/* Decode header for ms1.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MS1_DECODE_H
#define MS1_DECODE_H

namespace ms1 {
// forward declaration of struct in -defs.h
struct write_stacks;
}

namespace ms1 {

using namespace cgen;
using namespace ms1;

typedef UINT ms1_insn_word;

/* Enum declaration for instructions in cpu family ms1.  */
typedef enum ms1_insn_type {
  MS1_INSN_X_INVALID, MS1_INSN_ADD, MS1_INSN_ADDU, MS1_INSN_ADDI
 , MS1_INSN_ADDUI, MS1_INSN_SUB, MS1_INSN_SUBU, MS1_INSN_SUBI
 , MS1_INSN_SUBUI, MS1_INSN_MUL, MS1_INSN_MULI, MS1_INSN_AND
 , MS1_INSN_ANDI, MS1_INSN_OR, MS1_INSN_NOP, MS1_INSN_ORI
 , MS1_INSN_XOR, MS1_INSN_XORI, MS1_INSN_NAND, MS1_INSN_NANDI
 , MS1_INSN_NOR, MS1_INSN_NORI, MS1_INSN_XNOR, MS1_INSN_XNORI
 , MS1_INSN_LDUI, MS1_INSN_LSL, MS1_INSN_LSLI, MS1_INSN_LSR
 , MS1_INSN_LSRI, MS1_INSN_ASR, MS1_INSN_ASRI, MS1_INSN_BRLT
 , MS1_INSN_BRLE, MS1_INSN_BREQ, MS1_INSN_BRNE, MS1_INSN_JMP
 , MS1_INSN_JAL, MS1_INSN_DBNZ, MS1_INSN_EI, MS1_INSN_DI
 , MS1_INSN_SI, MS1_INSN_RETI, MS1_INSN_LDW, MS1_INSN_STW
 , MS1_INSN_BREAK, MS1_INSN_IFLUSH, MS1_INSN_LDCTXT, MS1_INSN_LDFB
 , MS1_INSN_STFB, MS1_INSN_FBCB, MS1_INSN_MFBCB, MS1_INSN_FBCCI
 , MS1_INSN_FBRCI, MS1_INSN_FBCRI, MS1_INSN_FBRRI, MS1_INSN_MFBCCI
 , MS1_INSN_MFBRCI, MS1_INSN_MFBCRI, MS1_INSN_MFBRRI, MS1_INSN_FBCBDR
 , MS1_INSN_RCFBCB, MS1_INSN_MRCFBCB, MS1_INSN_CBCAST, MS1_INSN_DUPCBCAST
 , MS1_INSN_WFBI, MS1_INSN_WFB, MS1_INSN_RCRISC, MS1_INSN_FBCBINC
 , MS1_INSN_RCXMODE, MS1_INSN_INTERLEAVER, MS1_INSN_WFBINC, MS1_INSN_MWFBINC
 , MS1_INSN_WFBINCR, MS1_INSN_MWFBINCR, MS1_INSN_FBCBINCS, MS1_INSN_MFBCBINCS
 , MS1_INSN_FBCBINCRS, MS1_INSN_MFBCBINCRS
} MS1_INSN_TYPE;


// Forward decls.
struct ms1_cpu;
struct ms1_scache;
typedef void (ms1_sem_fn) (ms1_cpu* cpu, ms1_scache* sem, int tick, ms1::write_stacks &buf);


// Instruction descriptor.

struct ms1_idesc {

  // scache engine executor for this insn
  ms1_sem_fn* execute;

  const char* insn_name;
  enum ms1_insn_type sem_index;
  ms1_insn_attr attrs;

  // idesc table: indexed by sem_index
  static ms1_idesc idesc_table[];

  static ms1_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union ms1_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_sr1;
    UINT f_sr2;
    HI f_imm16s;
  } sfmt_brlt;
  struct { /*  */
    UINT f_dr;
    UINT f_imm16u;
    UINT f_sr1;
  } sfmt_addui;
  struct { /*  */
    UINT f_dr;
    UINT f_sr1;
    HI f_imm16s;
  } sfmt_addi;
  struct { /*  */
    UINT f_drrr;
    UINT f_sr1;
    UINT f_sr2;
  } sfmt_add;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    ms1_scache* next;
    ms1_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    ms1_scache* insn;
  } before;
};

// Simulator instruction cache.

struct ms1_scache {
  // executor
  union {
    cgoto_label cgoto;
    ms1_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  ms1_idesc* idesc;

  // argument buffer
  ms1_sem_fields fields;



  // decode given instruction
  void decode (ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
};

} // end ms1 namespace

// Decls of each semantic fn.

using ms1::ms1_sem_fn;
extern ms1_sem_fn ms1_sem_x_invalid;
extern ms1_sem_fn ms1_sem_add;
extern ms1_sem_fn ms1_sem_addu;
extern ms1_sem_fn ms1_sem_addi;
extern ms1_sem_fn ms1_sem_addui;
extern ms1_sem_fn ms1_sem_sub;
extern ms1_sem_fn ms1_sem_subu;
extern ms1_sem_fn ms1_sem_subi;
extern ms1_sem_fn ms1_sem_subui;
extern ms1_sem_fn ms1_sem_mul;
extern ms1_sem_fn ms1_sem_muli;
extern ms1_sem_fn ms1_sem_and;
extern ms1_sem_fn ms1_sem_andi;
extern ms1_sem_fn ms1_sem_or;
extern ms1_sem_fn ms1_sem_nop;
extern ms1_sem_fn ms1_sem_ori;
extern ms1_sem_fn ms1_sem_xor;
extern ms1_sem_fn ms1_sem_xori;
extern ms1_sem_fn ms1_sem_nand;
extern ms1_sem_fn ms1_sem_nandi;
extern ms1_sem_fn ms1_sem_nor;
extern ms1_sem_fn ms1_sem_nori;
extern ms1_sem_fn ms1_sem_xnor;
extern ms1_sem_fn ms1_sem_xnori;
extern ms1_sem_fn ms1_sem_ldui;
extern ms1_sem_fn ms1_sem_lsl;
extern ms1_sem_fn ms1_sem_lsli;
extern ms1_sem_fn ms1_sem_lsr;
extern ms1_sem_fn ms1_sem_lsri;
extern ms1_sem_fn ms1_sem_asr;
extern ms1_sem_fn ms1_sem_asri;
extern ms1_sem_fn ms1_sem_brlt;
extern ms1_sem_fn ms1_sem_brle;
extern ms1_sem_fn ms1_sem_breq;
extern ms1_sem_fn ms1_sem_brne;
extern ms1_sem_fn ms1_sem_jmp;
extern ms1_sem_fn ms1_sem_jal;
extern ms1_sem_fn ms1_sem_dbnz;
extern ms1_sem_fn ms1_sem_ei;
extern ms1_sem_fn ms1_sem_di;
extern ms1_sem_fn ms1_sem_si;
extern ms1_sem_fn ms1_sem_reti;
extern ms1_sem_fn ms1_sem_ldw;
extern ms1_sem_fn ms1_sem_stw;
extern ms1_sem_fn ms1_sem_break;
extern ms1_sem_fn ms1_sem_iflush;
extern ms1_sem_fn ms1_sem_ldctxt;
extern ms1_sem_fn ms1_sem_ldfb;
extern ms1_sem_fn ms1_sem_stfb;
extern ms1_sem_fn ms1_sem_fbcb;
extern ms1_sem_fn ms1_sem_mfbcb;
extern ms1_sem_fn ms1_sem_fbcci;
extern ms1_sem_fn ms1_sem_fbrci;
extern ms1_sem_fn ms1_sem_fbcri;
extern ms1_sem_fn ms1_sem_fbrri;
extern ms1_sem_fn ms1_sem_mfbcci;
extern ms1_sem_fn ms1_sem_mfbrci;
extern ms1_sem_fn ms1_sem_mfbcri;
extern ms1_sem_fn ms1_sem_mfbrri;
extern ms1_sem_fn ms1_sem_fbcbdr;
extern ms1_sem_fn ms1_sem_rcfbcb;
extern ms1_sem_fn ms1_sem_mrcfbcb;
extern ms1_sem_fn ms1_sem_cbcast;
extern ms1_sem_fn ms1_sem_dupcbcast;
extern ms1_sem_fn ms1_sem_wfbi;
extern ms1_sem_fn ms1_sem_wfb;
extern ms1_sem_fn ms1_sem_rcrisc;
extern ms1_sem_fn ms1_sem_fbcbinc;
extern ms1_sem_fn ms1_sem_rcxmode;
extern ms1_sem_fn ms1_sem_interleaver;
extern ms1_sem_fn ms1_sem_wfbinc;
extern ms1_sem_fn ms1_sem_mwfbinc;
extern ms1_sem_fn ms1_sem_wfbincr;
extern ms1_sem_fn ms1_sem_mwfbincr;
extern ms1_sem_fn ms1_sem_fbcbincs;
extern ms1_sem_fn ms1_sem_mfbcbincs;
extern ms1_sem_fn ms1_sem_fbcbincrs;
extern ms1_sem_fn ms1_sem_mfbcbincrs;

#endif /* MS1_DECODE_H */
