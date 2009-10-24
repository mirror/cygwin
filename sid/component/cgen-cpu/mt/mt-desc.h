/* Misc. entries in the mt description file.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DESC_MT_H
#define DESC_MT_H

#include "cgen/bitset.h"

namespace mt {

// Enums.

/* Enum declaration for msys enums.  */
typedef enum insn_msys {
  MSYS_NO, MSYS_YES
} INSN_MSYS;

/* Enum declaration for opc enums.  */
typedef enum insn_opc {
  OPC_ADD = 0, OPC_ADDU = 1, OPC_SUB = 2, OPC_SUBU = 3
 , OPC_MUL = 4, OPC_AND = 8, OPC_OR = 9, OPC_XOR = 10
 , OPC_NAND = 11, OPC_NOR = 12, OPC_XNOR = 13, OPC_LDUI = 14
 , OPC_LSL = 16, OPC_LSR = 17, OPC_ASR = 18, OPC_BRLT = 24
 , OPC_BRLE = 25, OPC_BREQ = 26, OPC_JMP = 27, OPC_JAL = 28
 , OPC_BRNEQ = 29, OPC_DBNZ = 30, OPC_LOOP = 31, OPC_LDW = 32
 , OPC_STW = 33, OPC_EI = 48, OPC_DI = 49, OPC_SI = 50
 , OPC_RETI = 51, OPC_BREAK = 52, OPC_IFLUSH = 53
} INSN_OPC;

/* Enum declaration for msopc enums.  */
typedef enum insn_msopc {
  MSOPC_LDCTXT, MSOPC_LDFB, MSOPC_STFB, MSOPC_FBCB
 , MSOPC_MFBCB, MSOPC_FBCCI, MSOPC_FBRCI, MSOPC_FBCRI
 , MSOPC_FBRRI, MSOPC_MFBCCI, MSOPC_MFBRCI, MSOPC_MFBCRI
 , MSOPC_MFBRRI, MSOPC_FBCBDR, MSOPC_RCFBCB, MSOPC_MRCFBCB
 , MSOPC_CBCAST, MSOPC_DUPCBCAST, MSOPC_WFBI, MSOPC_WFB
 , MSOPC_RCRISC, MSOPC_FBCBINC, MSOPC_RCXMODE, MSOPC_INTLVR
 , MSOPC_WFBINC, MSOPC_MWFBINC, MSOPC_WFBINCR, MSOPC_MWFBINCR
 , MSOPC_FBCBINCS, MSOPC_MFBCBINCS, MSOPC_FBCBINCRS, MSOPC_MFBCBINCRS
} INSN_MSOPC;

/* Enum declaration for imm enums.  */
typedef enum insn_imm {
  IMM_NO, IMM_YES
} INSN_IMM;

/* Enum declaration for .  */
typedef enum msys_syms {
  H_NIL_DUP = 1, H_NIL_XX = 0
} MSYS_SYMS;

// Insn attribute indices.

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_LOAD_DELAY, CGEN_INSN_MEMORY_ACCESS
 , CGEN_INSN_AL_INSN, CGEN_INSN_IO_INSN, CGEN_INSN_BR_INSN, CGEN_INSN_JAL_HAZARD
 , CGEN_INSN_USES_FRDR, CGEN_INSN_USES_FRDRRR, CGEN_INSN_USES_FRSR1, CGEN_INSN_USES_FRSR2
 , CGEN_INSN_SKIPA, CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31, CGEN_INSN_MACH
 , CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

// Attributes.

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_MS1, MACH_MS1_003, MACH_MS2
 , MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_MT, ISA_MAX
} ISA_ATTR;

// Insn attributes.

struct mt_insn_attr {
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
  inline int get_load_delay_attr () { return (bools & (1<<CGEN_INSN_LOAD_DELAY)) != 0; }
  inline int get_memory_access_attr () { return (bools & (1<<CGEN_INSN_MEMORY_ACCESS)) != 0; }
  inline int get_al_insn_attr () { return (bools & (1<<CGEN_INSN_AL_INSN)) != 0; }
  inline int get_io_insn_attr () { return (bools & (1<<CGEN_INSN_IO_INSN)) != 0; }
  inline int get_br_insn_attr () { return (bools & (1<<CGEN_INSN_BR_INSN)) != 0; }
  inline int get_jal_hazard_attr () { return (bools & (1<<CGEN_INSN_JAL_HAZARD)) != 0; }
  inline int get_uses_frdr_attr () { return (bools & (1<<CGEN_INSN_USES_FRDR)) != 0; }
  inline int get_uses_frdrrr_attr () { return (bools & (1<<CGEN_INSN_USES_FRDRRR)) != 0; }
  inline int get_uses_frsr1_attr () { return (bools & (1<<CGEN_INSN_USES_FRSR1)) != 0; }
  inline int get_uses_frsr2_attr () { return (bools & (1<<CGEN_INSN_USES_FRSR2)) != 0; }
  inline int get_skipa_attr () { return (bools & (1<<CGEN_INSN_SKIPA)) != 0; }
};

#define MACH_MS1_003_INSN_CHUNK_BITSIZE 0

} // end mt namespace

#endif /* DESC_MT_H */
