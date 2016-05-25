#include "classifier.h"

/* Autogenerated code from the script config2c.pl */

static const char *oons_residue_name[] = {"ACE", "ANY", "ARG", "ASN", "ASP", "ASX", "CSE", "CYS", "GLN", "GLU", "GLX", "HIS", "HOH", "ILE", "LEU", "LYS", "MET", "NH2", "PHE", "PRO", "PYL", "SEC", "SER", "THR", "TRP", "TYR", "VAL", };
static const char *oons_class_name[] = {"Apolar", "Polar", "Water", };

static const char *oons_ACE_atom_name[] = {"CH3", };
static double oons_ACE_atom_radius[] = {2.00, };
static int oons_ACE_atom_class[] = {0, };
static struct classifier_residue oons_ACE_cfg = {
    .name = "ACE", .n_atoms = 1,
    .atom_name = (char**) oons_ACE_atom_name,
    .atom_radius = (double*) oons_ACE_atom_radius,
    .atom_class = (int*) oons_ACE_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_ANY_atom_name[] = {"N6", "N9", "O", "N3", "O4'", "C5", "O5'", "C2'", "P", "N7", "C7", "CM2", "O6", "CB", "N", "OP3", "O3'", "OXT", "N1", "C3'", "O4", "O2", "O2'", "N2", "C", "OP1", "C4", "C5'", "CA", "OP2", "C6", "C8", "C2", "N4", "C1'", "C4'", };
static double oons_ANY_atom_radius[] = {1.55, 1.55, 1.40, 1.55, 1.40, 1.75, 1.40, 1.75, 1.80, 1.55, 1.75, 2.00, 1.40, 2.00, 1.55, 1.40, 1.40, 1.40, 1.55, 1.75, 1.40, 1.40, 1.40, 1.55, 1.55, 1.40, 1.75, 2.00, 2.00, 1.40, 1.75, 1.75, 1.75, 1.55, 1.75, 1.75, };
static int oons_ANY_atom_class[] = {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, };
static struct classifier_residue oons_ANY_cfg = {
    .name = "ANY", .n_atoms = 36,
    .atom_name = (char**) oons_ANY_atom_name,
    .atom_radius = (double*) oons_ANY_atom_radius,
    .atom_class = (int*) oons_ANY_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_ARG_atom_name[] = {"NE", "NH2", "CG", "NH1", "CD", "CZ", };
static double oons_ARG_atom_radius[] = {1.55, 1.55, 2.00, 1.55, 2.00, 2.00, };
static int oons_ARG_atom_class[] = {1, 1, 0, 1, 0, 0, };
static struct classifier_residue oons_ARG_cfg = {
    .name = "ARG", .n_atoms = 6,
    .atom_name = (char**) oons_ARG_atom_name,
    .atom_radius = (double*) oons_ARG_atom_radius,
    .atom_class = (int*) oons_ARG_atom_class,
    .max_area = {.name = "ARG", .total = 228.79, .main_chain = 41.90, .side_chain = 186.89, .polar = 115.26, .apolar = 113.52},
};

static const char *oons_ASN_atom_name[] = {"OD1", "ND2", "CG", };
static double oons_ASN_atom_radius[] = {1.40, 1.55, 1.55, };
static int oons_ASN_atom_class[] = {1, 1, 1, };
static struct classifier_residue oons_ASN_cfg = {
    .name = "ASN", .n_atoms = 3,
    .atom_name = (char**) oons_ASN_atom_name,
    .atom_radius = (double*) oons_ASN_atom_radius,
    .atom_class = (int*) oons_ASN_atom_class,
    .max_area = {.name = "ASN", .total = 136.22, .main_chain = 41.04, .side_chain = 95.18, .polar = 86.37, .apolar = 49.85},
};

static const char *oons_ASP_atom_name[] = {"OD2", "CG", "OD1", };
static double oons_ASP_atom_radius[] = {1.40, 1.55, 1.40, };
static int oons_ASP_atom_class[] = {1, 1, 1, };
static struct classifier_residue oons_ASP_cfg = {
    .name = "ASP", .n_atoms = 3,
    .atom_name = (char**) oons_ASP_atom_name,
    .atom_radius = (double*) oons_ASP_atom_radius,
    .atom_class = (int*) oons_ASP_atom_class,
    .max_area = {.name = "ASP", .total = 134.24, .main_chain = 41.82, .side_chain = 92.43, .polar = 84.12, .apolar = 50.13},
};

static const char *oons_ASX_atom_name[] = {"XD1", "XD2", "CG", "AD2", "AD1", };
static double oons_ASX_atom_radius[] = {1.5, 1.5, 1.55, 1.5, 1.5, };
static int oons_ASX_atom_class[] = {1, 1, 1, 1, 1, };
static struct classifier_residue oons_ASX_cfg = {
    .name = "ASX", .n_atoms = 5,
    .atom_name = (char**) oons_ASX_atom_name,
    .atom_radius = (double*) oons_ASX_atom_radius,
    .atom_class = (int*) oons_ASX_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_CSE_atom_name[] = {"SE", };
static double oons_CSE_atom_radius[] = {1.90, };
static int oons_CSE_atom_class[] = {1, };
static struct classifier_residue oons_CSE_cfg = {
    .name = "CSE", .n_atoms = 1,
    .atom_name = (char**) oons_CSE_atom_name,
    .atom_radius = (double*) oons_CSE_atom_radius,
    .atom_class = (int*) oons_CSE_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_CYS_atom_name[] = {"SG", };
static double oons_CYS_atom_radius[] = {2.00, };
static int oons_CYS_atom_class[] = {1, };
static struct classifier_residue oons_CYS_cfg = {
    .name = "CYS", .n_atoms = 1,
    .atom_name = (char**) oons_CYS_atom_name,
    .atom_radius = (double*) oons_CYS_atom_radius,
    .atom_class = (int*) oons_CYS_atom_class,
    .max_area = {.name = "CYS", .total = 132.58, .main_chain = 41.94, .side_chain = 90.64, .polar = 85.30, .apolar = 47.28},
};

static const char *oons_GLN_atom_name[] = {"CG", "CD", "OE1", "NE2", };
static double oons_GLN_atom_radius[] = {2.00, 1.55, 1.40, 1.55, };
static int oons_GLN_atom_class[] = {0, 1, 1, 1, };
static struct classifier_residue oons_GLN_cfg = {
    .name = "GLN", .n_atoms = 4,
    .atom_name = (char**) oons_GLN_atom_name,
    .atom_radius = (double*) oons_GLN_atom_radius,
    .atom_class = (int*) oons_GLN_atom_class,
    .max_area = {.name = "GLN", .total = 169.64, .main_chain = 41.90, .side_chain = 127.74, .polar = 115.00, .apolar = 54.64},
};

static const char *oons_GLU_atom_name[] = {"OE2", "OE1", "CG", "CD", };
static double oons_GLU_atom_radius[] = {1.40, 1.40, 2.00, 1.55, };
static int oons_GLU_atom_class[] = {1, 1, 0, 1, };
static struct classifier_residue oons_GLU_cfg = {
    .name = "GLU", .n_atoms = 4,
    .atom_name = (char**) oons_GLU_atom_name,
    .atom_radius = (double*) oons_GLU_atom_radius,
    .atom_class = (int*) oons_GLU_atom_class,
    .max_area = {.name = "GLU", .total = 166.01, .main_chain = 41.93, .side_chain = 124.09, .polar = 108.99, .apolar = 57.02},
};

static const char *oons_GLX_atom_name[] = {"XE2", "AE2", "CD", "XE1", "CG", "AE1", };
static double oons_GLX_atom_radius[] = {1.5, 1.5, 1.55, 1.5, 2.00, 1.5, };
static int oons_GLX_atom_class[] = {1, 1, 1, 1, 0, 1, };
static struct classifier_residue oons_GLX_cfg = {
    .name = "GLX", .n_atoms = 6,
    .atom_name = (char**) oons_GLX_atom_name,
    .atom_radius = (double*) oons_GLX_atom_radius,
    .atom_class = (int*) oons_GLX_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_HIS_atom_name[] = {"CE1", "CG", "CD2", "ND1", "NE2", };
static double oons_HIS_atom_radius[] = {1.75, 1.75, 1.75, 1.55, 1.55, };
static int oons_HIS_atom_class[] = {0, 0, 0, 1, 1, };
static struct classifier_residue oons_HIS_cfg = {
    .name = "HIS", .n_atoms = 5,
    .atom_name = (char**) oons_HIS_atom_name,
    .atom_radius = (double*) oons_HIS_atom_radius,
    .atom_class = (int*) oons_HIS_atom_class,
    .max_area = {.name = "HIS", .total = 170.73, .main_chain = 41.47, .side_chain = 129.27, .polar = 56.97, .apolar = 113.76},
};

static const char *oons_HOH_atom_name[] = {"O", };
static double oons_HOH_atom_radius[] = {1.40, };
static int oons_HOH_atom_class[] = {2, };
static struct classifier_residue oons_HOH_cfg = {
    .name = "HOH", .n_atoms = 1,
    .atom_name = (char**) oons_HOH_atom_name,
    .atom_radius = (double*) oons_HOH_atom_radius,
    .atom_class = (int*) oons_HOH_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_ILE_atom_name[] = {"CG2", "CD1", "CG1", };
static double oons_ILE_atom_radius[] = {2.00, 2.00, 2.00, };
static int oons_ILE_atom_class[] = {0, 0, 0, };
static struct classifier_residue oons_ILE_cfg = {
    .name = "ILE", .n_atoms = 3,
    .atom_name = (char**) oons_ILE_atom_name,
    .atom_radius = (double*) oons_ILE_atom_radius,
    .atom_class = (int*) oons_ILE_atom_class,
    .max_area = {.name = "ILE", .total = 173.24, .main_chain = 36.90, .side_chain = 136.34, .polar = 20.58, .apolar = 152.66},
};

static const char *oons_LEU_atom_name[] = {"CG", "CD2", "CD1", };
static double oons_LEU_atom_radius[] = {2.00, 2.00, 2.00, };
static int oons_LEU_atom_class[] = {0, 0, 0, };
static struct classifier_residue oons_LEU_cfg = {
    .name = "LEU", .n_atoms = 3,
    .atom_name = (char**) oons_LEU_atom_name,
    .atom_radius = (double*) oons_LEU_atom_radius,
    .atom_class = (int*) oons_LEU_atom_class,
    .max_area = {.name = "LEU", .total = 166.51, .main_chain = 41.95, .side_chain = 124.56, .polar = 25.02, .apolar = 141.50},
};

static const char *oons_LYS_atom_name[] = {"NZ", "CG", "CD", "CE", };
static double oons_LYS_atom_radius[] = {1.55, 2.00, 2.00, 2.00, };
static int oons_LYS_atom_class[] = {1, 0, 0, 0, };
static struct classifier_residue oons_LYS_cfg = {
    .name = "LYS", .n_atoms = 4,
    .atom_name = (char**) oons_LYS_atom_name,
    .atom_radius = (double*) oons_LYS_atom_radius,
    .atom_class = (int*) oons_LYS_atom_class,
    .max_area = {.name = "LYS", .total = 197.76, .main_chain = 41.90, .side_chain = 155.86, .polar = 72.37, .apolar = 125.39},
};

static const char *oons_MET_atom_name[] = {"SD", "CE", "CG", };
static double oons_MET_atom_radius[] = {2.00, 2.00, 2.00, };
static int oons_MET_atom_class[] = {1, 0, 0, };
static struct classifier_residue oons_MET_cfg = {
    .name = "MET", .n_atoms = 3,
    .atom_name = (char**) oons_MET_atom_name,
    .atom_radius = (double*) oons_MET_atom_radius,
    .atom_class = (int*) oons_MET_atom_class,
    .max_area = {.name = "MET", .total = 193.52, .main_chain = 41.88, .side_chain = 151.64, .polar = 71.52, .apolar = 122.00},
};

static const char *oons_NH2_atom_name[] = {"NH2", };
static double oons_NH2_atom_radius[] = {1.55, };
static int oons_NH2_atom_class[] = {1, };
static struct classifier_residue oons_NH2_cfg = {
    .name = "NH2", .n_atoms = 1,
    .atom_name = (char**) oons_NH2_atom_name,
    .atom_radius = (double*) oons_NH2_atom_radius,
    .atom_class = (int*) oons_NH2_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_PHE_atom_name[] = {"CD1", "CD2", "CE2", "CZ", "CE1", "CG", };
static double oons_PHE_atom_radius[] = {1.75, 1.75, 1.75, 1.75, 1.75, 1.75, };
static int oons_PHE_atom_class[] = {0, 0, 0, 0, 0, 0, };
static struct classifier_residue oons_PHE_cfg = {
    .name = "PHE", .n_atoms = 6,
    .atom_name = (char**) oons_PHE_atom_name,
    .atom_radius = (double*) oons_PHE_atom_radius,
    .atom_class = (int*) oons_PHE_atom_class,
    .max_area = {.name = "PHE", .total = 192.02, .main_chain = 40.38, .side_chain = 151.64, .polar = 25.21, .apolar = 166.81},
};

static const char *oons_PRO_atom_name[] = {"CD", "CG", "CB", };
static double oons_PRO_atom_radius[] = {1.75, 1.75, 1.75, };
static int oons_PRO_atom_class[] = {0, 0, 0, };
static struct classifier_residue oons_PRO_cfg = {
    .name = "PRO", .n_atoms = 3,
    .atom_name = (char**) oons_PRO_atom_name,
    .atom_radius = (double*) oons_PRO_atom_radius,
    .atom_class = (int*) oons_PRO_atom_class,
    .max_area = {.name = "PRO", .total = 123.92, .main_chain = 33.48, .side_chain = 90.44, .polar = 14.54, .apolar = 109.38},
};

static const char *oons_PYL_atom_name[] = {"CD2", "CA2", "CE2", "C2", "O2", "CE", "CD", "NZ", "CB2", "CG", "N2", "CG2", };
static double oons_PYL_atom_radius[] = {1.75, 1.75, 1.75, 1.55, 1.40, 2.00, 2.00, 1.55, 2.00, 2.00, 1.55, 1.75, };
static int oons_PYL_atom_class[] = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, };
static struct classifier_residue oons_PYL_cfg = {
    .name = "PYL", .n_atoms = 12,
    .atom_name = (char**) oons_PYL_atom_name,
    .atom_radius = (double*) oons_PYL_atom_radius,
    .atom_class = (int*) oons_PYL_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_SEC_atom_name[] = {"SE", };
static double oons_SEC_atom_radius[] = {1.90, };
static int oons_SEC_atom_class[] = {1, };
static struct classifier_residue oons_SEC_cfg = {
    .name = "SEC", .n_atoms = 1,
    .atom_name = (char**) oons_SEC_atom_name,
    .atom_radius = (double*) oons_SEC_atom_radius,
    .atom_class = (int*) oons_SEC_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *oons_SER_atom_name[] = {"OG", };
static double oons_SER_atom_radius[] = {1.40, };
static int oons_SER_atom_class[] = {1, };
static struct classifier_residue oons_SER_cfg = {
    .name = "SER", .n_atoms = 1,
    .atom_name = (char**) oons_SER_atom_name,
    .atom_radius = (double*) oons_SER_atom_radius,
    .atom_class = (int*) oons_SER_atom_class,
    .max_area = {.name = "SER", .total = 111.52, .main_chain = 43.53, .side_chain = 67.99, .polar = 48.36, .apolar = 63.16},
};

static const char *oons_THR_atom_name[] = {"OG1", "CG2", };
static double oons_THR_atom_radius[] = {1.40, 2.00, };
static int oons_THR_atom_class[] = {1, 0, };
static struct classifier_residue oons_THR_cfg = {
    .name = "THR", .n_atoms = 2,
    .atom_name = (char**) oons_THR_atom_name,
    .atom_radius = (double*) oons_THR_atom_radius,
    .atom_class = (int*) oons_THR_atom_class,
    .max_area = {.name = "THR", .total = 135.14, .main_chain = 38.84, .side_chain = 96.29, .polar = 41.22, .apolar = 93.91},
};

static const char *oons_TRP_atom_name[] = {"CZ3", "CG", "NE1", "CD1", "CH2", "CE3", "CZ2", "CE2", "CD2", };
static double oons_TRP_atom_radius[] = {1.75, 1.75, 1.55, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, };
static int oons_TRP_atom_class[] = {0, 0, 1, 0, 0, 0, 0, 0, 0, };
static struct classifier_residue oons_TRP_cfg = {
    .name = "TRP", .n_atoms = 9,
    .atom_name = (char**) oons_TRP_atom_name,
    .atom_radius = (double*) oons_TRP_atom_radius,
    .atom_class = (int*) oons_TRP_atom_class,
    .max_area = {.name = "TRP", .total = 222.80, .main_chain = 37.17, .side_chain = 185.63, .polar = 50.57, .apolar = 172.24},
};

static const char *oons_TYR_atom_name[] = {"OH", "CG", "CE1", "CE2", "CZ", "CD2", "CD1", };
static double oons_TYR_atom_radius[] = {1.40, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, };
static int oons_TYR_atom_class[] = {1, 0, 0, 0, 0, 0, 0, };
static struct classifier_residue oons_TYR_cfg = {
    .name = "TYR", .n_atoms = 7,
    .atom_name = (char**) oons_TYR_atom_name,
    .atom_radius = (double*) oons_TYR_atom_radius,
    .atom_class = (int*) oons_TYR_atom_class,
    .max_area = {.name = "TYR", .total = 205.21, .main_chain = 40.35, .side_chain = 164.86, .polar = 67.42, .apolar = 137.79},
};

static const char *oons_VAL_atom_name[] = {"CG2", "CG1", };
static double oons_VAL_atom_radius[] = {2.00, 2.00, };
static int oons_VAL_atom_class[] = {0, 0, };
static struct classifier_residue oons_VAL_cfg = {
    .name = "VAL", .n_atoms = 2,
    .atom_name = (char**) oons_VAL_atom_name,
    .atom_radius = (double*) oons_VAL_atom_radius,
    .atom_class = (int*) oons_VAL_atom_class,
    .max_area = {.name = "VAL", .total = 151.66, .main_chain = 40.79, .side_chain = 110.87, .polar = 25.21, .apolar = 126.45},
};

static struct classifier_residue *oons_residue_cfg[] = {
    &oons_ACE_cfg, &oons_ANY_cfg, &oons_ARG_cfg, &oons_ASN_cfg, &oons_ASP_cfg, &oons_ASX_cfg, &oons_CSE_cfg, &oons_CYS_cfg, &oons_GLN_cfg, &oons_GLU_cfg, &oons_GLX_cfg, &oons_HIS_cfg, &oons_HOH_cfg, &oons_ILE_cfg, &oons_LEU_cfg, &oons_LYS_cfg, &oons_MET_cfg, &oons_NH2_cfg, &oons_PHE_cfg, &oons_PRO_cfg, &oons_PYL_cfg, &oons_SEC_cfg, &oons_SER_cfg, &oons_THR_cfg, &oons_TRP_cfg, &oons_TYR_cfg, &oons_VAL_cfg, };

static struct classifier_config oons_auto_config = {
    .n_residues = 27, .n_classes = 3,
    .residue_name = (char**) oons_residue_name,
    .class_name = (char**) oons_class_name,
    .residue = (struct classifier_residue **) oons_residue_cfg,
};

static void oons_dummy_free(void *arg) {}

const freesasa_classifier freesasa_oons_classifier = {
    .name = "oons",
    .config = &oons_auto_config,
    .n_classes = 3,
    .radius = freesasa_classifier_radius,
    .sasa_class =freesasa_classifier_class,
    .class2str = freesasa_classifier_class2str,
    .residue_reference = freesasa_classifier_residue_reference,
    // Since this object is const, calling free should emit compiler warnings.
    .free_config = oons_dummy_free,
};
