/* Misc. entries in the arm description file.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DESC_ARM_H
#define DESC_ARM_H

#include "cgen/bitset.h"

namespace arm {

// Enums.

/* Enum declaration for .  */
typedef enum gr_names {
  H_GR_PC = 15, H_GR_R0 = 0, H_GR_R1 = 1, H_GR_R2 = 2
 , H_GR_R3 = 3, H_GR_R4 = 4, H_GR_R5 = 5, H_GR_R6 = 6
 , H_GR_R7 = 7, H_GR_R8 = 8, H_GR_R9 = 9, H_GR_R10 = 10
 , H_GR_R11 = 11, H_GR_R12 = 12, H_GR_R13 = 13, H_GR_R14 = 14
 , H_GR_R15 = 15, H_GR_SP = 13, H_GR_LR = 14
} GR_NAMES;

/* Enum declaration for arm cpu states.  */
typedef enum arm_mode {
  ARM_MODE_USER = 16, ARM_MODE_FIQ = 17, ARM_MODE_IRQ = 18, ARM_MODE_SUPERVISOR = 19
 , ARM_MODE_ABORT = 23, ARM_MODE_UNDEFINED = 27, ARM_MODE_SYSTEM = 31
} ARM_MODE;

/* Enum declaration for operand 2 shift type.  */
typedef enum shift_type {
  SHIFT_TYPE_LSL = 0, SHIFT_TYPE_ASL = 0, SHIFT_TYPE_LSR = 1, SHIFT_TYPE_ASR = 2
 , SHIFT_TYPE_ROR = 3
} SHIFT_TYPE;

/* Enum declaration for condition codes.  */
typedef enum cond_codes {
  COND_EQ, COND_NE, COND_CS, COND_CC
 , COND_MI, COND_PL, COND_VS, COND_VC
 , COND_HI, COND_LS, COND_GE, COND_LT
 , COND_GT, COND_LE, COND_AL
} COND_CODES;

/* Enum declaration for Arith/logic opcode enums.  */
typedef enum al_opcode {
  OP_AND, OP_EOR, OP_SUB, OP_RSB
 , OP_ADD, OP_ADC, OP_SBC, OP_RSC
 , OP_TST, OP_TEQ, OP_CMP, OP_CMN
 , OP_ORR, OP_MOV, OP_BIC, OP_MVN
} AL_OPCODE;

/* Enum declaration for PSR transfer destinations.  */
typedef enum psr_dests {
  PSR_CURRENT, PSR_SAVED
} PSR_DESTS;

/* Enum declaration for condition code tests.  */
typedef enum cc_tests {
  CC_EQ, CC_NE, CC_CS, CC_CC
 , CC_MI, CC_PL, CC_VS, CC_VC
 , CC_HI, CC_LS, CC_GE, CC_LT
 , CC_GT, CC_LE
} CC_TESTS;

// Insn attribute indices.

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31
 , CGEN_INSN_MACH, CGEN_INSN_ISA, CGEN_INSN_R15_OFFSET, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

// Attributes.

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_ARM7TDMI, MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_ARM, ISA_THUMB, ISA_MAX
} ISA_ATTR;

// Insn attributes.

struct arm_insn_attr {
  unsigned int bools;
  unsigned int mach;
  CGEN_BITSET isa;
  int r15_offset;
  inline unsigned int get_mach_attr () { return mach; }
  inline CGEN_BITSET get_isa_attr () { return isa; }
  inline int get_r15_offset_attr () { return r15_offset; }
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

#define MACH_ARM7TDMI_INSN_CHUNK_BITSIZE 0

} // end arm namespace

#endif /* DESC_ARM_H */
