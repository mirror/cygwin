/* Misc. entries in the xstormy16 description file.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DESC_XSTORMY16_H
#define DESC_XSTORMY16_H

#include "cgen/bitset.h"

namespace xstormy16 {

// Enums.

/* Enum declaration for .  */
typedef enum gr_names {
  H_GR_R0 = 0, H_GR_R1 = 1, H_GR_R2 = 2, H_GR_R3 = 3
 , H_GR_R4 = 4, H_GR_R5 = 5, H_GR_R6 = 6, H_GR_R7 = 7
 , H_GR_R8 = 8, H_GR_R9 = 9, H_GR_R10 = 10, H_GR_R11 = 11
 , H_GR_R12 = 12, H_GR_R13 = 13, H_GR_R14 = 14, H_GR_R15 = 15
 , H_GR_PSW = 14, H_GR_SP = 15
} GR_NAMES;

/* Enum declaration for .  */
typedef enum gr_rb_names {
  H_RBJ_R8 = 0, H_RBJ_R9 = 1, H_RBJ_R10 = 2, H_RBJ_R11 = 3
 , H_RBJ_R12 = 4, H_RBJ_R13 = 5, H_RBJ_R14 = 6, H_RBJ_R15 = 7
 , H_RBJ_PSW = 6, H_RBJ_SP = 7
} GR_RB_NAMES;

/* Enum declaration for insn op enums.  */
typedef enum insn_op1 {
  OP1_0, OP1_1, OP1_2, OP1_3
 , OP1_4, OP1_5, OP1_6, OP1_7
 , OP1_8, OP1_9, OP1_A, OP1_B
 , OP1_C, OP1_D, OP1_E, OP1_F
} INSN_OP1;

/* Enum declaration for insn op enums.  */
typedef enum insn_op2 {
  OP2_0, OP2_1, OP2_2, OP2_3
 , OP2_4, OP2_5, OP2_6, OP2_7
 , OP2_8, OP2_9, OP2_A, OP2_B
 , OP2_C, OP2_D, OP2_E, OP2_F
} INSN_OP2;

/* Enum declaration for insn op enums.  */
typedef enum insn_op2a {
  OP2A_0, OP2A_2, OP2A_4, OP2A_6
 , OP2A_8, OP2A_A, OP2A_C, OP2A_E
} INSN_OP2A;

/* Enum declaration for insn op enums.  */
typedef enum insn_op2m {
  OP2M_0, OP2M_1
} INSN_OP2M;

/* Enum declaration for insn op enums.  */
typedef enum insn_op3 {
  OP3_0, OP3_1, OP3_2, OP3_3
 , OP3_4, OP3_5, OP3_6, OP3_7
 , OP3_8, OP3_9, OP3_A, OP3_B
 , OP3_C, OP3_D, OP3_E, OP3_F
} INSN_OP3;

/* Enum declaration for insn op enums.  */
typedef enum insn_op3a {
  OP3A_0, OP3A_1, OP3A_2, OP3A_3
} INSN_OP3A;

/* Enum declaration for insn op enums.  */
typedef enum insn_op3b {
  OP3B_0, OP3B_2, OP3B_4, OP3B_6
 , OP3B_8, OP3B_A, OP3B_C, OP3B_E
} INSN_OP3B;

/* Enum declaration for insn op enums.  */
typedef enum insn_op4 {
  OP4_0, OP4_1, OP4_2, OP4_3
 , OP4_4, OP4_5, OP4_6, OP4_7
 , OP4_8, OP4_9, OP4_A, OP4_B
 , OP4_C, OP4_D, OP4_E, OP4_F
} INSN_OP4;

/* Enum declaration for insn op enums.  */
typedef enum insn_op4m {
  OP4M_0, OP4M_1
} INSN_OP4M;

/* Enum declaration for insn op enums.  */
typedef enum insn_op4b {
  OP4B_0, OP4B_1
} INSN_OP4B;

/* Enum declaration for insn op enums.  */
typedef enum insn_op5 {
  OP5_0, OP5_1, OP5_2, OP5_3
 , OP5_4, OP5_5, OP5_6, OP5_7
 , OP5_8, OP5_9, OP5_A, OP5_B
 , OP5_C, OP5_D, OP5_E, OP5_F
} INSN_OP5;

/* Enum declaration for insn op enums.  */
typedef enum insn_op5a {
  OP5A_0, OP5A_1
} INSN_OP5A;

// Insn attribute indices.

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31
 , CGEN_INSN_MACH, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

// Attributes.

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_XSTORMY16, MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_XSTORMY16, ISA_MAX
} ISA_ATTR;

// Insn attributes.

struct xstormy16_insn_attr {
  unsigned int bools;
  unsigned int mach;
  inline unsigned int get_mach_attr () { return mach; }
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
};

#define MACH_XSTORMY16_INSN_CHUNK_BITSIZE 16

} // end xstormy16 namespace

#endif /* DESC_XSTORMY16_H */
