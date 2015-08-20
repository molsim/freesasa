/*
  Copyright Simon Mitternacht 2013-2015.

  This file is part of FreeSASA.

  FreeSASA is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FreeSASA is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FreeSASA.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#if HAVE_CONFIG_H
# include <config.h>
#endif
#if HAVE_PTHREAD_H
# include <pthread.h>
#endif

#include "freesasa.h"
#include "sasa.h"
#include "srp.h"
#include "verlet.h"

#ifdef __GNUC__
#define __attrib_pure__ __attribute__((pure))
#else
#define __attrib_pure__
#endif

extern const char *freesasa_name;
extern int freesasa_fail(const char *format, ...);
extern int freesasa_warn(const char *format, ...);

// calculation parameters (results stored in *sasa)
typedef struct {
    int i1,i2;
    int n_atoms;
    int n_points;
    double probe_radius;
    const freesasa_coord *xyz;
    const freesasa_coord *srp;
    double *r;
    freesasa_verlet *adj;
    double *sasa;
    char *spcount_0;
} sasa_sr;

#if HAVE_LIBPTHREAD
static void sasa_sr_do_threads(int n_threads, sasa_sr sr);
static void *sasa_sr_thread(void *arg);
#endif

static double sasa_sr_calc_atom(int i,const sasa_sr) __attrib_pure__;

int freesasa_shrake_rupley(double *sasa,
                           const freesasa_coord *xyz,
                           const double *r,
                           double probe_radius,
                           int n_points,
                           int n_threads)
{
    assert(sasa);
    assert(xyz);
    assert(r);

    int n_atoms = freesasa_coord_n(xyz);
    int return_value = FREESASA_SUCCESS;
    const double *srp_p;
    freesasa_coord *srp;
    char spcount_0[n_points];

    if (n_atoms == 0) {
        return freesasa_warn("%s: empty coordinates", __func__);
    }

    // Initialize test-points
    srp_p = freesasa_srp_get_points(n_points);
    if (srp_p == NULL) return FREESASA_FAIL;
    srp = freesasa_coord_new_linked(srp_p,n_points);
    
    /* a reference zero array is prepared so that it won't need to be
       initialized for each atom */
    memset(spcount_0,0,n_points);

    //store parameters and reference arrays
    sasa_sr sr = {.n_atoms = n_atoms, .n_points = n_points,
                  .probe_radius = probe_radius,
                  .xyz = xyz, .srp = srp,
                  .spcount_0 = spcount_0,
                  .sasa = sasa};

    sr.r = malloc(sizeof(double)*n_atoms);
    assert(sr.r);
    for (int i = 0; i < n_atoms; ++i) sr.r[i] = r[i] + probe_radius;

    //calculate distances
    sr.adj = freesasa_verlet_new(xyz,sr.r);


    //calculate SASA
    if (n_threads > 1) {
#if HAVE_LIBPTHREAD
        sasa_sr_do_threads(n_threads, sr);
#else
        return_value = freesasa_warn("%s: program compiled for single-threaded use, "
                                     "but multiple threads were requested. Will "
                                     "proceed in single-threaded mode.\n",
                                     __func__);
        n_threads = 1;
#endif
    }
    if (n_threads == 1) {
        // don't want the overhead of generating threads if only one is used
        for (int i = 0; i < n_atoms; ++i) {
            sasa[i] = sasa_sr_calc_atom(i,sr);
        }
    }
    freesasa_coord_free(srp);
    freesasa_verlet_free(sr.adj);
    free(sr.r);
    return return_value;
}

#if HAVE_LIBPTHREAD
static void sasa_sr_do_threads(int n_threads, sasa_sr sr)
{
    pthread_t thread[n_threads];
    sasa_sr srt[n_threads];
    int n_atoms = sr.n_atoms;
    int thread_block_size = n_atoms/n_threads;
    int res;
    void *thread_result;

    for (int t = 0; t < n_threads; ++t) {
        srt[t] = sr;
        srt[t].i1 = t*thread_block_size;
        if (t == n_threads-1) srt[t].i2 = n_atoms;
        else srt[t].i2 = (t+1)*thread_block_size;
        errno = 0;
        res = pthread_create(&thread[t], NULL, sasa_sr_thread, (void *) &srt[t]);
        if (res) {
            perror(freesasa_name);
            abort();
        }
    }
    for (int t = 0; t < n_threads; ++t) {
        errno = 0;
        int res = pthread_join(thread[t],&thread_result);
        if (res) {
            perror(freesasa_name);
            abort();
        }
    }
}

static void *sasa_sr_thread(void* arg)
{
    sasa_sr sr = *((sasa_sr*) arg);
    int n = sr.i2-sr.i1;
    double *sasa = malloc(sizeof(double)*n);
    assert(sasa);
    for (int i = 0; i < n; ++i) {
        sasa[i] = sasa_sr_calc_atom(i+sr.i1,sr);
    }
    // mutex should not be necessary, but might be safer to have one here?
    memcpy(&sr.sasa[sr.i1],sasa,sizeof(double)*n);
    free(sasa);
    pthread_exit(NULL);
}
#endif

static double sasa_sr_calc_atom(int i, const sasa_sr sr) {
    const int n_points = sr.n_points;
    const freesasa_coord *xyz = sr.xyz;
    /* this array keeps track of which testpoints belonging to
       a certain atom overlap with other atoms */
    char spcount[n_points];
    const double ri = sr.r[i];
    const double *restrict vi = freesasa_coord_i(xyz,i);
    double xi = vi[0], yi = vi[1], zi = vi[2];
    const double *restrict v = freesasa_coord_all(xyz);
    const double *restrict r = sr.r;
    const double *restrict tp;
    int n_surface = 0;
    
    /* testpoints for this atom */
    freesasa_coord* tp_coord_ri = freesasa_coord_copy(sr.srp);
    freesasa_coord_scale(tp_coord_ri, ri);
    freesasa_coord_translate(tp_coord_ri, vi);
    tp = freesasa_coord_all(tp_coord_ri);

    memcpy(spcount,sr.spcount_0,sizeof(char)*n_points);

    for (int j = 0; j < sr.adj->nn[i]; ++j) {
        const int ja = sr.adj->nb[i][j];
        const double rj = sr.r[ja];
        const double xj = v[3*ja+0], yj = v[3*ja+1], zj = v[3*ja+2];
        for (int k = 0; k < n_points; ++k) {
            if (spcount[k]) continue;
            double dx = tp[3*k]-xj, dy = tp[3*k+1]-yj, dz = tp[3*k+2]-zj;
            if (dx*dx + dy*dy + dz*dz < rj*rj) {
                spcount[k] = 1;
            }
            /* i.e. if |xyz[i]+ri*srp[k] - xyz[j]| <= rj we have an
               overlap. */
        }
    }
    freesasa_coord_free(tp_coord_ri);
    for (int k = 0; k < n_points; ++k) {
        if (!spcount[k]) ++n_surface;
    }
    return (4.0*M_PI*ri*ri*n_surface)/n_points;
}
