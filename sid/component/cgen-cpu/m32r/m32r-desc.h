/* Misc. entries in the m32r description file.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DESC_M32R_H
#define DESC_M32R_H

#include "cgen/bitset.h"

namespace m32r {

// Enums.

/* Enum declaration for insn format enums.  */
typedef enum insn_op1 {
  OP1_0, OP1_1, OP1_2, OP1_3
 , OP1_4, OP1_5, OP1_6, OP1_7
 , OP1_8, OP1_9, OP1_10, OP1_11
 , OP1_12, OP1_13, OP1_14, OP1_15
} INSN_OP1;

/* Enum declaration for op2 enums.  */
typedef enum insn_op2 {
  OP2_0, OP2_1, OP2_2, OP2_3
 , OP2_4, OP2_5, OP2_6, OP2_7
 , OP2_8, OP2_9, OP2_10, OP2_11
 , OP2_12, OP2_13, OP2_14, OP2_15
} INSN_OP2;

/* Enum declaration for .  */
typedef enum gr_names {
  H_GR_FP = 13, H_GR_LR = 14, H_GR_SP = 15, H_GR_R0 = 0
 , H_GR_R1 = 1, H_GR_R2 = 2, H_GR_R3 = 3, H_GR_R4 = 4
 , H_GR_R5 = 5, H_GR_R6 = 6, H_GR_R7 = 7, H_GR_R8 = 8
 , H_GR_R9 = 9, H_GR_R10 = 10, H_GR_R11 = 11, H_GR_R12 = 12
 , H_GR_R13 = 13, H_GR_R14 = 14, H_GR_R15 = 15
} GR_NAMES;

/* Enum declaration for .  */
typedef enum cr_names {
  H_CR_PSW = 0, H_CR_CBR = 1, H_CR_SPI = 2, H_CR_SPU = 3
 , H_CR_BPC = 6, H_CR_BBPSW = 8, H_CR_BBPC = 14, H_CR_EVB = 5
 , H_CR_CR0 = 0, H_CR_CR1 = 1, H_CR_CR2 = 2, H_CR_CR3 = 3
 , H_CR_CR4 = 4, H_CR_CR5 = 5, H_CR_CR6 = 6, H_CR_CR7 = 7
 , H_CR_CR8 = 8, H_CR_CR9 = 9, H_CR_CR10 = 10, H_CR_CR11 = 11
 , H_CR_CR12 = 12, H_CR_CR13 = 13, H_CR_CR14 = 14, H_CR_CR15 = 15
} CR_NAMES;

// Insn attribute indices.

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_FILL_SLOT, CGEN_INSN_SPECIAL
 , CGEN_INSN_SPECIAL_M32R, CGEN_INSN_SPECIAL_FLOAT, CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31
 , CGEN_INSN_MACH, CGEN_INSN_PIPE, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

// Attributes.

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_M32R, MACH_M32RX, MACH_M32R2
 , MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_M32R, ISA_MAX
} ISA_ATTR;

/* Enum declaration for parallel execution pipeline selection.  */
typedef enum pipe_attr {
  PIPE_NONE, PIPE_O, PIPE_S, PIPE_OS
 , PIPE_O_OS
} PIPE_ATTR;

// Insn attributes.

struct m32r_insn_attr {
  unsigned int bools;
  unsigned int mach;
  enum pipe_attr pipe;
  inline unsigned int get_mach_attr () { return mach; }
  inline enum pipe_attr get_pipe_attr () { return pipe; }
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
  inline int get_fill_slot_attr () { return (bools & (1<<CGEN_INSN_FILL_SLOT)) != 0; }
  inline int get_special_attr () { return (bools & (1<<CGEN_INSN_SPECIAL)) != 0; }
  inline int get_special_m32r_attr () { return (bools & (1<<CGEN_INSN_SPECIAL_M32R)) != 0; }
  inline int get_special_float_attr () { return (bools & (1<<CGEN_INSN_SPECIAL_FLOAT)) != 0; }
};

#define MACH_M32R_INSN_CHUNK_BITSIZE 0

} // end m32r namespace

#endif /* DESC_M32R_H */
