/* Misc. entries in the mep description file.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DESC_MEP_H
#define DESC_MEP_H

#include "cgen/bitset.h"

namespace mep {

// Enums.

/* Enum declaration for major opcodes.  */
typedef enum major {
  MAJ_0, MAJ_1, MAJ_2, MAJ_3
 , MAJ_4, MAJ_5, MAJ_6, MAJ_7
 , MAJ_8, MAJ_9, MAJ_10, MAJ_11
 , MAJ_12, MAJ_13, MAJ_14, MAJ_15
} MAJOR;

// Insn attribute indices.

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_OPTIONAL_BIT_INSN, CGEN_INSN_OPTIONAL_MUL_INSN
 , CGEN_INSN_OPTIONAL_DIV_INSN, CGEN_INSN_OPTIONAL_DEBUG_INSN, CGEN_INSN_OPTIONAL_LDZ_INSN, CGEN_INSN_OPTIONAL_ABS_INSN
 , CGEN_INSN_OPTIONAL_AVE_INSN, CGEN_INSN_OPTIONAL_MINMAX_INSN, CGEN_INSN_OPTIONAL_CLIP_INSN, CGEN_INSN_OPTIONAL_SAT_INSN
 , CGEN_INSN_OPTIONAL_UCI_INSN, CGEN_INSN_OPTIONAL_DSP_INSN, CGEN_INSN_OPTIONAL_CP_INSN, CGEN_INSN_OPTIONAL_CP64_INSN
 , CGEN_INSN_OPTIONAL_VLIW64, CGEN_INSN_MAY_TRAP, CGEN_INSN_VLIW_ALONE, CGEN_INSN_VLIW_NO_CORE_NOP
 , CGEN_INSN_VLIW_NO_COP_NOP, CGEN_INSN_VLIW64_NO_MATCHING_NOP, CGEN_INSN_VLIW32_NO_MATCHING_NOP, CGEN_INSN_VOLATILE
 , CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31, CGEN_INSN_MACH, CGEN_INSN_ISA
 , CGEN_INSN_CPTYPE, CGEN_INSN_CRET, CGEN_INSN_LATENCY, CGEN_INSN_CONFIG
 , CGEN_INSN_SLOTS, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

// Attributes.

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_MEP, MACH_H1, MACH_C5
 , MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_MEP, ISA_EXT_CORE1, ISA_EXT_COP1_16, ISA_EXT_COP1_32
 , ISA_EXT_COP1_48, ISA_EXT_COP1_64, ISA_MAX
} ISA_ATTR;

/* Enum declaration for datatype to use for C intrinsics mapping.  */
typedef enum cdata_attr {
  CDATA_LABEL, CDATA_REGNUM, CDATA_FMAX_FLOAT, CDATA_FMAX_INT
 , CDATA_POINTER, CDATA_LONG, CDATA_ULONG, CDATA_SHORT
 , CDATA_USHORT, CDATA_CHAR, CDATA_UCHAR, CDATA_CP_DATA_BUS_INT
} CDATA_ATTR;

/* Enum declaration for datatype to use for coprocessor values.  */
typedef enum cptype_attr {
  CPTYPE_CP_DATA_BUS_INT, CPTYPE_VECT, CPTYPE_V2SI, CPTYPE_V4HI
 , CPTYPE_V8QI, CPTYPE_V2USI, CPTYPE_V4UHI, CPTYPE_V8UQI
} CPTYPE_ATTR;

/* Enum declaration for Insn's intrinsic returns void, or the first argument rather than (or in addition to) passing it..  */
typedef enum cret_attr {
  CRET_VOID, CRET_FIRST, CRET_FIRSTCOPY
} CRET_ATTR;

/* Enum declaration for .  */
typedef enum config_attr {
  CONFIG_NONE, CONFIG_DEFAULT
} CONFIG_ATTR;

/* Enum declaration for slots for which this opcode is valid - c3, p0s, p0, p1.  */
typedef enum slots_attr {
  SLOTS_CORE, SLOTS_C3, SLOTS_P0S, SLOTS_P0
 , SLOTS_P1
} SLOTS_ATTR;

// Insn attributes.

struct mep_insn_attr {
  unsigned int bools;
  unsigned int mach;
  CGEN_BITSET isa;
  enum cptype_attr cptype;
  enum cret_attr cret;
  int latency;
  enum config_attr config;
  unsigned int slots;
  inline unsigned int get_mach_attr () { return mach; }
  inline CGEN_BITSET get_isa_attr () { return isa; }
  inline enum cptype_attr get_cptype_attr () { return cptype; }
  inline enum cret_attr get_cret_attr () { return cret; }
  inline int get_latency_attr () { return latency; }
  inline enum config_attr get_config_attr () { return config; }
  inline unsigned int get_slots_attr () { return slots; }
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
  inline int get_optional_bit_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_BIT_INSN)) != 0; }
  inline int get_optional_mul_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_MUL_INSN)) != 0; }
  inline int get_optional_div_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_DIV_INSN)) != 0; }
  inline int get_optional_debug_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_DEBUG_INSN)) != 0; }
  inline int get_optional_ldz_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_LDZ_INSN)) != 0; }
  inline int get_optional_abs_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_ABS_INSN)) != 0; }
  inline int get_optional_ave_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_AVE_INSN)) != 0; }
  inline int get_optional_minmax_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_MINMAX_INSN)) != 0; }
  inline int get_optional_clip_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_CLIP_INSN)) != 0; }
  inline int get_optional_sat_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_SAT_INSN)) != 0; }
  inline int get_optional_uci_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_UCI_INSN)) != 0; }
  inline int get_optional_dsp_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_DSP_INSN)) != 0; }
  inline int get_optional_cp_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_CP_INSN)) != 0; }
  inline int get_optional_cp64_insn_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_CP64_INSN)) != 0; }
  inline int get_optional_vliw64_attr () { return (bools & (1<<CGEN_INSN_OPTIONAL_VLIW64)) != 0; }
  inline int get_may_trap_attr () { return (bools & (1<<CGEN_INSN_MAY_TRAP)) != 0; }
  inline int get_vliw_alone_attr () { return (bools & (1<<CGEN_INSN_VLIW_ALONE)) != 0; }
  inline int get_vliw_no_core_nop_attr () { return (bools & (1<<CGEN_INSN_VLIW_NO_CORE_NOP)) != 0; }
  inline int get_vliw_no_cop_nop_attr () { return (bools & (1<<CGEN_INSN_VLIW_NO_COP_NOP)) != 0; }
  inline int get_vliw64_no_matching_nop_attr () { return (bools & (1<<CGEN_INSN_VLIW64_NO_MATCHING_NOP)) != 0; }
  inline int get_vliw32_no_matching_nop_attr () { return (bools & (1<<CGEN_INSN_VLIW32_NO_MATCHING_NOP)) != 0; }
  inline int get_volatile_attr () { return (bools & (1<<CGEN_INSN_VOLATILE)) != 0; }
};

#define MACH_C5_INSN_CHUNK_BITSIZE 16

} // end mep namespace

#endif /* DESC_MEP_H */
