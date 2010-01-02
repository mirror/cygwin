/* Decode header for mt.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MT_DECODE_H
#define MT_DECODE_H

namespace mt {
// forward declaration of struct in -defs.h
struct write_stacks;
}

namespace mt {

using namespace cgen;
using namespace mt;

typedef UINT mt_insn_word;

/* Enum declaration for instructions in cpu family mt.  */
typedef enum mt_insn_type {
  MT_INSN_X_INVALID, MT_INSN_ADD, MT_INSN_ADDU, MT_INSN_ADDI
 , MT_INSN_ADDUI, MT_INSN_SUB, MT_INSN_SUBU, MT_INSN_SUBI
 , MT_INSN_SUBUI, MT_INSN_MUL, MT_INSN_MULI, MT_INSN_AND
 , MT_INSN_ANDI, MT_INSN_OR, MT_INSN_NOP, MT_INSN_ORI
 , MT_INSN_XOR, MT_INSN_XORI, MT_INSN_NAND, MT_INSN_NANDI
 , MT_INSN_NOR, MT_INSN_NORI, MT_INSN_XNOR, MT_INSN_XNORI
 , MT_INSN_LDUI, MT_INSN_LSL, MT_INSN_LSLI, MT_INSN_LSR
 , MT_INSN_LSRI, MT_INSN_ASR, MT_INSN_ASRI, MT_INSN_BRLT
 , MT_INSN_BRLE, MT_INSN_BREQ, MT_INSN_BRNE, MT_INSN_JMP
 , MT_INSN_JAL, MT_INSN_DBNZ, MT_INSN_EI, MT_INSN_DI
 , MT_INSN_SI, MT_INSN_RETI, MT_INSN_LDW, MT_INSN_STW
 , MT_INSN_BREAK, MT_INSN_IFLUSH, MT_INSN_FBCB, MT_INSN_MFBCB
 , MT_INSN_FBCCI, MT_INSN_FBRCI, MT_INSN_FBCRI, MT_INSN_FBRRI
 , MT_INSN_MFBCCI, MT_INSN_MFBRCI, MT_INSN_MFBCRI, MT_INSN_MFBRRI
 , MT_INSN_FBCBDR, MT_INSN_RCFBCB, MT_INSN_MRCFBCB, MT_INSN_CBCAST
 , MT_INSN_DUPCBCAST, MT_INSN_WFBI, MT_INSN_WFB, MT_INSN_RCRISC
 , MT_INSN_FBCBINC, MT_INSN_RCXMODE, MT_INSN_INTERLEAVER, MT_INSN_WFBINC
 , MT_INSN_MWFBINC, MT_INSN_WFBINCR, MT_INSN_MWFBINCR, MT_INSN_FBCBINCS
 , MT_INSN_MFBCBINCS, MT_INSN_FBCBINCRS, MT_INSN_MFBCBINCRS
} MT_INSN_TYPE;


// Forward decls.
struct mt_cpu;
struct mt_scache;
typedef void (mt_sem_fn) (mt_cpu* cpu, mt_scache* sem, int tick, mt::write_stacks &buf);


// Instruction descriptor.

struct mt_idesc {

  // scache engine executor for this insn
  mt_sem_fn* execute;

  const char* insn_name;
  enum mt_insn_type sem_index;
  mt_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mt_idesc idesc_table[];

  static mt_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mt_sem_fields {
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
    mt_scache* next;
    mt_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mt_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mt_scache {
  // executor
  union {
    cgoto_label cgoto;
    mt_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mt_idesc* idesc;

  // argument buffer
  mt_sem_fields fields;



  // decode given instruction
  void decode (mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
};

} // end mt namespace

// Decls of each semantic fn.

using mt::mt_sem_fn;
extern mt_sem_fn mt_sem_x_invalid;
extern mt_sem_fn mt_sem_add;
extern mt_sem_fn mt_sem_addu;
extern mt_sem_fn mt_sem_addi;
extern mt_sem_fn mt_sem_addui;
extern mt_sem_fn mt_sem_sub;
extern mt_sem_fn mt_sem_subu;
extern mt_sem_fn mt_sem_subi;
extern mt_sem_fn mt_sem_subui;
extern mt_sem_fn mt_sem_mul;
extern mt_sem_fn mt_sem_muli;
extern mt_sem_fn mt_sem_and;
extern mt_sem_fn mt_sem_andi;
extern mt_sem_fn mt_sem_or;
extern mt_sem_fn mt_sem_nop;
extern mt_sem_fn mt_sem_ori;
extern mt_sem_fn mt_sem_xor;
extern mt_sem_fn mt_sem_xori;
extern mt_sem_fn mt_sem_nand;
extern mt_sem_fn mt_sem_nandi;
extern mt_sem_fn mt_sem_nor;
extern mt_sem_fn mt_sem_nori;
extern mt_sem_fn mt_sem_xnor;
extern mt_sem_fn mt_sem_xnori;
extern mt_sem_fn mt_sem_ldui;
extern mt_sem_fn mt_sem_lsl;
extern mt_sem_fn mt_sem_lsli;
extern mt_sem_fn mt_sem_lsr;
extern mt_sem_fn mt_sem_lsri;
extern mt_sem_fn mt_sem_asr;
extern mt_sem_fn mt_sem_asri;
extern mt_sem_fn mt_sem_brlt;
extern mt_sem_fn mt_sem_brle;
extern mt_sem_fn mt_sem_breq;
extern mt_sem_fn mt_sem_brne;
extern mt_sem_fn mt_sem_jmp;
extern mt_sem_fn mt_sem_jal;
extern mt_sem_fn mt_sem_dbnz;
extern mt_sem_fn mt_sem_ei;
extern mt_sem_fn mt_sem_di;
extern mt_sem_fn mt_sem_si;
extern mt_sem_fn mt_sem_reti;
extern mt_sem_fn mt_sem_ldw;
extern mt_sem_fn mt_sem_stw;
extern mt_sem_fn mt_sem_break;
extern mt_sem_fn mt_sem_iflush;
extern mt_sem_fn mt_sem_fbcb;
extern mt_sem_fn mt_sem_mfbcb;
extern mt_sem_fn mt_sem_fbcci;
extern mt_sem_fn mt_sem_fbrci;
extern mt_sem_fn mt_sem_fbcri;
extern mt_sem_fn mt_sem_fbrri;
extern mt_sem_fn mt_sem_mfbcci;
extern mt_sem_fn mt_sem_mfbrci;
extern mt_sem_fn mt_sem_mfbcri;
extern mt_sem_fn mt_sem_mfbrri;
extern mt_sem_fn mt_sem_fbcbdr;
extern mt_sem_fn mt_sem_rcfbcb;
extern mt_sem_fn mt_sem_mrcfbcb;
extern mt_sem_fn mt_sem_cbcast;
extern mt_sem_fn mt_sem_dupcbcast;
extern mt_sem_fn mt_sem_wfbi;
extern mt_sem_fn mt_sem_wfb;
extern mt_sem_fn mt_sem_rcrisc;
extern mt_sem_fn mt_sem_fbcbinc;
extern mt_sem_fn mt_sem_rcxmode;
extern mt_sem_fn mt_sem_interleaver;
extern mt_sem_fn mt_sem_wfbinc;
extern mt_sem_fn mt_sem_mwfbinc;
extern mt_sem_fn mt_sem_wfbincr;
extern mt_sem_fn mt_sem_mwfbincr;
extern mt_sem_fn mt_sem_fbcbincs;
extern mt_sem_fn mt_sem_mfbcbincs;
extern mt_sem_fn mt_sem_fbcbincrs;
extern mt_sem_fn mt_sem_mfbcbincrs;

#endif /* MT_DECODE_H */
