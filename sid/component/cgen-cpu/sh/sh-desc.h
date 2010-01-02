/* Misc. entries in the sh description file.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DESC_SH_H
#define DESC_SH_H

#include "cgen/bitset.h"

namespace sh {

// Enums.

/* Enum declaration for .  */
typedef enum frc_names {
  H_FRC_FR0, H_FRC_FR1, H_FRC_FR2, H_FRC_FR3
 , H_FRC_FR4, H_FRC_FR5, H_FRC_FR6, H_FRC_FR7
 , H_FRC_FR8, H_FRC_FR9, H_FRC_FR10, H_FRC_FR11
 , H_FRC_FR12, H_FRC_FR13, H_FRC_FR14, H_FRC_FR15
} FRC_NAMES;

/* Enum declaration for .  */
typedef enum drc_names {
  H_DRC_DR0 = 0, H_DRC_DR2 = 2, H_DRC_DR4 = 4, H_DRC_DR6 = 6
 , H_DRC_DR8 = 8, H_DRC_DR10 = 10, H_DRC_DR12 = 12, H_DRC_DR14 = 14
} DRC_NAMES;

/* Enum declaration for .  */
typedef enum xf_names {
  H_XF_XF0, H_XF_XF1, H_XF_XF2, H_XF_XF3
 , H_XF_XF4, H_XF_XF5, H_XF_XF6, H_XF_XF7
 , H_XF_XF8, H_XF_XF9, H_XF_XF10, H_XF_XF11
 , H_XF_XF12, H_XF_XF13, H_XF_XF14, H_XF_XF15
} XF_NAMES;

// Insn attribute indices.

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_ILLSLOT, CGEN_INSN_FP_INSN
 , CGEN_INSN_32_BIT_INSN, CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31, CGEN_INSN_MACH
 , CGEN_INSN_ISA, CGEN_INSN_SH4_GROUP, CGEN_INSN_SH4A_GROUP, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

// Attributes.

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_SH2, MACH_SH2E, MACH_SH2A_FPU
 , MACH_SH2A_NOFPU, MACH_SH3, MACH_SH3E, MACH_SH4_NOFPU
 , MACH_SH4, MACH_SH4A_NOFPU, MACH_SH4A, MACH_SH4AL
 , MACH_SH5, MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_COMPACT, ISA_MEDIA, ISA_MAX
} ISA_ATTR;

/* Enum declaration for sh4 insn groups.  */
typedef enum sh4_group_attr {
  SH4_GROUP_NONE, SH4_GROUP_MT, SH4_GROUP_EX, SH4_GROUP_BR
 , SH4_GROUP_LS, SH4_GROUP_FE, SH4_GROUP_CO, SH4_GROUP_MAX
} SH4_GROUP_ATTR;

/* Enum declaration for sh4a insn groups.  */
typedef enum sh4a_group_attr {
  SH4A_GROUP_NONE, SH4A_GROUP_MT, SH4A_GROUP_EX, SH4A_GROUP_BR
 , SH4A_GROUP_LS, SH4A_GROUP_FE, SH4A_GROUP_CO, SH4A_GROUP_MAX
} SH4A_GROUP_ATTR;

// Insn attributes.

struct sh_insn_attr {
  unsigned int bools;
  unsigned int mach;
  CGEN_BITSET isa;
  enum sh4_group_attr sh4_group;
  enum sh4a_group_attr sh4a_group;
  inline unsigned int get_mach_attr () { return mach; }
  inline CGEN_BITSET get_isa_attr () { return isa; }
  inline enum sh4_group_attr get_sh4_group_attr () { return sh4_group; }
  inline enum sh4a_group_attr get_sh4a_group_attr () { return sh4a_group; }
  inline int get_alias_attr () { return (bools & (1<<CGEN_INSN_ALIAS)) != 0; }
  inline int get_virtual_attr () { return (bools & (1<<CGEN_INSN_VIRTUAL)) != 0; }
  inline int get_uncond_cti_attr () { return (bools & (1<<CGEN_INSN_UNCOND_CTI)) != 0; }
  inline int get_cond_cti_attr () { return (bools & (1<<CGEN_INSN_COND_CTI)) != 0; }
  inline int get_skip_cti_attr () { return (bools & (1<<CGEN_INSN_SKIP_CTI)) != 0; }
  inline int get_delay_slot_attr () { return (bools & (1<<CGEN_INSN_DELAY_SLOT)) != 0; }
  inline int get_relaxable_attr () { return (bools & (1<<CGEN_INSN_RELAXABLE)) != 0; }
  inline int get_relaxed_attr () { return (bools & (1<<CGEN_INSN_RELAXED)) != 0; }
  inline int get_no_dis_attr () { return (bools & (1<<CGEN_INSN_NO_DIS)) != 0; }
  inline int get_pbb_attr () { return (bools & (1<<CGEN_INSN_PBB)) != 0; }
  inline int get_illslot_attr () { return (bools & (1<<CGEN_INSN_ILLSLOT)) != 0; }
  inline int get_fp_insn_attr () { return (bools & (1<<CGEN_INSN_FP_INSN)) != 0; }
  inline int get_32_bit_insn_attr () { return (bools & (1<<CGEN_INSN_32_BIT_INSN)) != 0; }
};

#define MACH_SH2_INSN_CHUNK_BITSIZE 0
#define MACH_SH2E_INSN_CHUNK_BITSIZE 0
#define MACH_SH2A_FPU_INSN_CHUNK_BITSIZE 0
#define MACH_SH2A_NOFPU_INSN_CHUNK_BITSIZE 0
#define MACH_SH3_INSN_CHUNK_BITSIZE 0
#define MACH_SH3E_INSN_CHUNK_BITSIZE 0
#define MACH_SH4_NOFPU_INSN_CHUNK_BITSIZE 0
#define MACH_SH4_INSN_CHUNK_BITSIZE 0
#define MACH_SH4A_NOFPU_INSN_CHUNK_BITSIZE 0
#define MACH_SH4A_INSN_CHUNK_BITSIZE 0
#define MACH_SH4AL_INSN_CHUNK_BITSIZE 0
#define MACH_SH5_INSN_CHUNK_BITSIZE 0

} // end sh namespace

#endif /* DESC_SH_H */
