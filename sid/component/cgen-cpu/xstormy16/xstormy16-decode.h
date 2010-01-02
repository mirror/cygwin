/* Decode header for xstormy16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef XSTORMY16_DECODE_H
#define XSTORMY16_DECODE_H

namespace xstormy16 {

using namespace cgen;
using namespace xstormy16;

typedef UINT xstormy16_insn_word;

/* Enum declaration for instructions in cpu family xstormy16.  */
typedef enum xstormy16_insn_type {
  XSTORMY16_INSN_X_INVALID, XSTORMY16_INSN_MOVLMEMIMM, XSTORMY16_INSN_MOVHMEMIMM, XSTORMY16_INSN_MOVLGRMEM
 , XSTORMY16_INSN_MOVHGRMEM, XSTORMY16_INSN_MOVLMEMGR, XSTORMY16_INSN_MOVHMEMGR, XSTORMY16_INSN_MOVGRGRI
 , XSTORMY16_INSN_MOVGRGRIPOSTINC, XSTORMY16_INSN_MOVGRGRIPREDEC, XSTORMY16_INSN_MOVGRIGR, XSTORMY16_INSN_MOVGRIPOSTINCGR
 , XSTORMY16_INSN_MOVGRIPREDECGR, XSTORMY16_INSN_MOVGRGRII, XSTORMY16_INSN_MOVGRGRIIPOSTINC, XSTORMY16_INSN_MOVGRGRIIPREDEC
 , XSTORMY16_INSN_MOVGRIIGR, XSTORMY16_INSN_MOVGRIIPOSTINCGR, XSTORMY16_INSN_MOVGRIIPREDECGR, XSTORMY16_INSN_MOVGRGR
 , XSTORMY16_INSN_MOVWIMM8, XSTORMY16_INSN_MOVWGRIMM8, XSTORMY16_INSN_MOVWGRIMM16, XSTORMY16_INSN_MOVLOWGR
 , XSTORMY16_INSN_MOVHIGHGR, XSTORMY16_INSN_MOVFGRGRI, XSTORMY16_INSN_MOVFGRGRIPOSTINC, XSTORMY16_INSN_MOVFGRGRIPREDEC
 , XSTORMY16_INSN_MOVFGRIGR, XSTORMY16_INSN_MOVFGRIPOSTINCGR, XSTORMY16_INSN_MOVFGRIPREDECGR, XSTORMY16_INSN_MOVFGRGRII
 , XSTORMY16_INSN_MOVFGRGRIIPOSTINC, XSTORMY16_INSN_MOVFGRGRIIPREDEC, XSTORMY16_INSN_MOVFGRIIGR, XSTORMY16_INSN_MOVFGRIIPOSTINCGR
 , XSTORMY16_INSN_MOVFGRIIPREDECGR, XSTORMY16_INSN_MASKGRGR, XSTORMY16_INSN_MASKGRIMM16, XSTORMY16_INSN_PUSHGR
 , XSTORMY16_INSN_POPGR, XSTORMY16_INSN_SWPN, XSTORMY16_INSN_SWPB, XSTORMY16_INSN_SWPW
 , XSTORMY16_INSN_ANDGRGR, XSTORMY16_INSN_ANDIMM8, XSTORMY16_INSN_ANDGRIMM16, XSTORMY16_INSN_ORGRGR
 , XSTORMY16_INSN_ORIMM8, XSTORMY16_INSN_ORGRIMM16, XSTORMY16_INSN_XORGRGR, XSTORMY16_INSN_XORIMM8
 , XSTORMY16_INSN_XORGRIMM16, XSTORMY16_INSN_NOTGR, XSTORMY16_INSN_ADDGRGR, XSTORMY16_INSN_ADDGRIMM4
 , XSTORMY16_INSN_ADDIMM8, XSTORMY16_INSN_ADDGRIMM16, XSTORMY16_INSN_ADCGRGR, XSTORMY16_INSN_ADCGRIMM4
 , XSTORMY16_INSN_ADCIMM8, XSTORMY16_INSN_ADCGRIMM16, XSTORMY16_INSN_SUBGRGR, XSTORMY16_INSN_SUBGRIMM4
 , XSTORMY16_INSN_SUBIMM8, XSTORMY16_INSN_SUBGRIMM16, XSTORMY16_INSN_SBCGRGR, XSTORMY16_INSN_SBCGRIMM4
 , XSTORMY16_INSN_SBCGRIMM8, XSTORMY16_INSN_SBCGRIMM16, XSTORMY16_INSN_INCGRIMM2, XSTORMY16_INSN_DECGRIMM2
 , XSTORMY16_INSN_RRCGRGR, XSTORMY16_INSN_RRCGRIMM4, XSTORMY16_INSN_RLCGRGR, XSTORMY16_INSN_RLCGRIMM4
 , XSTORMY16_INSN_SHRGRGR, XSTORMY16_INSN_SHRGRIMM, XSTORMY16_INSN_SHLGRGR, XSTORMY16_INSN_SHLGRIMM
 , XSTORMY16_INSN_ASRGRGR, XSTORMY16_INSN_ASRGRIMM, XSTORMY16_INSN_SET1GRIMM, XSTORMY16_INSN_SET1GRGR
 , XSTORMY16_INSN_SET1LMEMIMM, XSTORMY16_INSN_SET1HMEMIMM, XSTORMY16_INSN_CLR1GRIMM, XSTORMY16_INSN_CLR1GRGR
 , XSTORMY16_INSN_CLR1LMEMIMM, XSTORMY16_INSN_CLR1HMEMIMM, XSTORMY16_INSN_CBWGR, XSTORMY16_INSN_REVGR
 , XSTORMY16_INSN_BCCGRGR, XSTORMY16_INSN_BCCGRIMM8, XSTORMY16_INSN_BCCIMM16, XSTORMY16_INSN_BNGRIMM4
 , XSTORMY16_INSN_BNGRGR, XSTORMY16_INSN_BNLMEMIMM, XSTORMY16_INSN_BNHMEMIMM, XSTORMY16_INSN_BPGRIMM4
 , XSTORMY16_INSN_BPGRGR, XSTORMY16_INSN_BPLMEMIMM, XSTORMY16_INSN_BPHMEMIMM, XSTORMY16_INSN_BCC
 , XSTORMY16_INSN_BGR, XSTORMY16_INSN_BR, XSTORMY16_INSN_JMP, XSTORMY16_INSN_JMPF
 , XSTORMY16_INSN_CALLRGR, XSTORMY16_INSN_CALLRIMM, XSTORMY16_INSN_CALLGR, XSTORMY16_INSN_CALLFIMM
 , XSTORMY16_INSN_ICALLRGR, XSTORMY16_INSN_ICALLGR, XSTORMY16_INSN_ICALLFIMM, XSTORMY16_INSN_IRET
 , XSTORMY16_INSN_RET, XSTORMY16_INSN_MUL, XSTORMY16_INSN_DIV, XSTORMY16_INSN_SDIV
 , XSTORMY16_INSN_SDIVLH, XSTORMY16_INSN_DIVLH, XSTORMY16_INSN_RESET, XSTORMY16_INSN_NOP
 , XSTORMY16_INSN_HALT, XSTORMY16_INSN_HOLD, XSTORMY16_INSN_HOLDX, XSTORMY16_INSN_BRK
 , XSTORMY16_INSN_SYSCALL
} XSTORMY16_INSN_TYPE;


// Forward decls.
struct xstormy16_cpu;
struct xstormy16_scache;
typedef sem_status (xstormy16_sem_fn) (xstormy16_cpu* cpu, xstormy16_scache* sem);


// Instruction descriptor.

struct xstormy16_idesc {

  // scache engine executor for this insn
  xstormy16_sem_fn* execute;

  const char* insn_name;
  enum xstormy16_insn_type sem_index;
  xstormy16_insn_attr attrs;

  // idesc table: indexed by sem_index
  static xstormy16_idesc idesc_table[];

  static xstormy16_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union xstormy16_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_abs24;
  } sfmt_jmpf;
  struct { /*  */
    SI f_rel12a;
  } sfmt_br;
  struct { /*  */
    UINT f_Rbj;
    UINT f_Rd;
  } sfmt_jmp;
  struct { /*  */
    SI f_rel8_2;
    UINT f_op2;
  } sfmt_bcc;
  struct { /*  */
    UINT f_imm3;
    HI f_hmem8;
  } sfmt_set1hmemimm;
  struct { /*  */
    UINT f_imm3;
    UINT f_lmem8;
  } sfmt_set1lmemimm;
  struct { /*  */
    UINT f_Rd;
    UINT f_imm2;
  } sfmt_incgrimm2;
  struct { /*  */
    UINT f_Rd;
    UINT f_imm16;
  } sfmt_movwgrimm16;
  struct { /*  */
    SI f_rel12;
    UINT f_imm3b;
    HI f_hmem8;
  } sfmt_bnhmemimm;
  struct { /*  */
    SI f_rel12;
    UINT f_imm3b;
    UINT f_lmem8;
  } sfmt_bnlmemimm;
  struct { /*  */
    SI f_rel12;
    UINT f_Rd;
    UINT f_imm4;
  } sfmt_bngrimm4;
  struct { /*  */
    SI f_rel8_4;
    UINT f_imm16;
    UINT f_op2;
  } sfmt_bccimm16;
  struct { /*  */
    UINT f_Rm;
    UINT f_op2m;
    HI f_hmem8;
  } sfmt_movhgrmem;
  struct { /*  */
    UINT f_Rm;
    UINT f_lmem8;
    UINT f_op2m;
  } sfmt_movlgrmem;
  struct { /*  */
    UINT f_imm16;
    UINT f_op2m;
    HI f_hmem8;
  } sfmt_movhmemimm;
  struct { /*  */
    UINT f_imm16;
    UINT f_lmem8;
    UINT f_op2m;
  } sfmt_movlmemimm;
  struct { /*  */
    SI f_rel12;
    UINT f_Rm;
    UINT f_imm8;
    UINT f_op5;
  } sfmt_bccgrimm8;
  struct { /*  */
    SI f_rel12;
    UINT f_Rd;
    UINT f_Rs;
    UINT f_op5;
  } sfmt_bccgrgr;
  struct { /*  */
    INT f_imm12;
    UINT f_Rb;
    UINT f_Rdm;
    UINT f_Rs;
    UINT f_op2m;
  } sfmt_movfgrgrii;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    xstormy16_scache* next;
    xstormy16_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    xstormy16_scache* insn;
  } before;
};

// Simulator instruction cache.

struct xstormy16_scache {
  // executor
  union {
    cgoto_label cgoto;
    xstormy16_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  xstormy16_idesc* idesc;

  // argument buffer
  xstormy16_sem_fields fields;



  // decode given instruction
  void decode (xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
};

} // end xstormy16 namespace

// Decls of each semantic fn.

using xstormy16::xstormy16_sem_fn;
extern xstormy16_sem_fn xstormy16_sem_x_invalid;
extern xstormy16_sem_fn xstormy16_sem_movlmemimm;
extern xstormy16_sem_fn xstormy16_sem_movhmemimm;
extern xstormy16_sem_fn xstormy16_sem_movlgrmem;
extern xstormy16_sem_fn xstormy16_sem_movhgrmem;
extern xstormy16_sem_fn xstormy16_sem_movlmemgr;
extern xstormy16_sem_fn xstormy16_sem_movhmemgr;
extern xstormy16_sem_fn xstormy16_sem_movgrgri;
extern xstormy16_sem_fn xstormy16_sem_movgrgripostinc;
extern xstormy16_sem_fn xstormy16_sem_movgrgripredec;
extern xstormy16_sem_fn xstormy16_sem_movgrigr;
extern xstormy16_sem_fn xstormy16_sem_movgripostincgr;
extern xstormy16_sem_fn xstormy16_sem_movgripredecgr;
extern xstormy16_sem_fn xstormy16_sem_movgrgrii;
extern xstormy16_sem_fn xstormy16_sem_movgrgriipostinc;
extern xstormy16_sem_fn xstormy16_sem_movgrgriipredec;
extern xstormy16_sem_fn xstormy16_sem_movgriigr;
extern xstormy16_sem_fn xstormy16_sem_movgriipostincgr;
extern xstormy16_sem_fn xstormy16_sem_movgriipredecgr;
extern xstormy16_sem_fn xstormy16_sem_movgrgr;
extern xstormy16_sem_fn xstormy16_sem_movwimm8;
extern xstormy16_sem_fn xstormy16_sem_movwgrimm8;
extern xstormy16_sem_fn xstormy16_sem_movwgrimm16;
extern xstormy16_sem_fn xstormy16_sem_movlowgr;
extern xstormy16_sem_fn xstormy16_sem_movhighgr;
extern xstormy16_sem_fn xstormy16_sem_movfgrgri;
extern xstormy16_sem_fn xstormy16_sem_movfgrgripostinc;
extern xstormy16_sem_fn xstormy16_sem_movfgrgripredec;
extern xstormy16_sem_fn xstormy16_sem_movfgrigr;
extern xstormy16_sem_fn xstormy16_sem_movfgripostincgr;
extern xstormy16_sem_fn xstormy16_sem_movfgripredecgr;
extern xstormy16_sem_fn xstormy16_sem_movfgrgrii;
extern xstormy16_sem_fn xstormy16_sem_movfgrgriipostinc;
extern xstormy16_sem_fn xstormy16_sem_movfgrgriipredec;
extern xstormy16_sem_fn xstormy16_sem_movfgriigr;
extern xstormy16_sem_fn xstormy16_sem_movfgriipostincgr;
extern xstormy16_sem_fn xstormy16_sem_movfgriipredecgr;
extern xstormy16_sem_fn xstormy16_sem_maskgrgr;
extern xstormy16_sem_fn xstormy16_sem_maskgrimm16;
extern xstormy16_sem_fn xstormy16_sem_pushgr;
extern xstormy16_sem_fn xstormy16_sem_popgr;
extern xstormy16_sem_fn xstormy16_sem_swpn;
extern xstormy16_sem_fn xstormy16_sem_swpb;
extern xstormy16_sem_fn xstormy16_sem_swpw;
extern xstormy16_sem_fn xstormy16_sem_andgrgr;
extern xstormy16_sem_fn xstormy16_sem_andimm8;
extern xstormy16_sem_fn xstormy16_sem_andgrimm16;
extern xstormy16_sem_fn xstormy16_sem_orgrgr;
extern xstormy16_sem_fn xstormy16_sem_orimm8;
extern xstormy16_sem_fn xstormy16_sem_orgrimm16;
extern xstormy16_sem_fn xstormy16_sem_xorgrgr;
extern xstormy16_sem_fn xstormy16_sem_xorimm8;
extern xstormy16_sem_fn xstormy16_sem_xorgrimm16;
extern xstormy16_sem_fn xstormy16_sem_notgr;
extern xstormy16_sem_fn xstormy16_sem_addgrgr;
extern xstormy16_sem_fn xstormy16_sem_addgrimm4;
extern xstormy16_sem_fn xstormy16_sem_addimm8;
extern xstormy16_sem_fn xstormy16_sem_addgrimm16;
extern xstormy16_sem_fn xstormy16_sem_adcgrgr;
extern xstormy16_sem_fn xstormy16_sem_adcgrimm4;
extern xstormy16_sem_fn xstormy16_sem_adcimm8;
extern xstormy16_sem_fn xstormy16_sem_adcgrimm16;
extern xstormy16_sem_fn xstormy16_sem_subgrgr;
extern xstormy16_sem_fn xstormy16_sem_subgrimm4;
extern xstormy16_sem_fn xstormy16_sem_subimm8;
extern xstormy16_sem_fn xstormy16_sem_subgrimm16;
extern xstormy16_sem_fn xstormy16_sem_sbcgrgr;
extern xstormy16_sem_fn xstormy16_sem_sbcgrimm4;
extern xstormy16_sem_fn xstormy16_sem_sbcgrimm8;
extern xstormy16_sem_fn xstormy16_sem_sbcgrimm16;
extern xstormy16_sem_fn xstormy16_sem_incgrimm2;
extern xstormy16_sem_fn xstormy16_sem_decgrimm2;
extern xstormy16_sem_fn xstormy16_sem_rrcgrgr;
extern xstormy16_sem_fn xstormy16_sem_rrcgrimm4;
extern xstormy16_sem_fn xstormy16_sem_rlcgrgr;
extern xstormy16_sem_fn xstormy16_sem_rlcgrimm4;
extern xstormy16_sem_fn xstormy16_sem_shrgrgr;
extern xstormy16_sem_fn xstormy16_sem_shrgrimm;
extern xstormy16_sem_fn xstormy16_sem_shlgrgr;
extern xstormy16_sem_fn xstormy16_sem_shlgrimm;
extern xstormy16_sem_fn xstormy16_sem_asrgrgr;
extern xstormy16_sem_fn xstormy16_sem_asrgrimm;
extern xstormy16_sem_fn xstormy16_sem_set1grimm;
extern xstormy16_sem_fn xstormy16_sem_set1grgr;
extern xstormy16_sem_fn xstormy16_sem_set1lmemimm;
extern xstormy16_sem_fn xstormy16_sem_set1hmemimm;
extern xstormy16_sem_fn xstormy16_sem_clr1grimm;
extern xstormy16_sem_fn xstormy16_sem_clr1grgr;
extern xstormy16_sem_fn xstormy16_sem_clr1lmemimm;
extern xstormy16_sem_fn xstormy16_sem_clr1hmemimm;
extern xstormy16_sem_fn xstormy16_sem_cbwgr;
extern xstormy16_sem_fn xstormy16_sem_revgr;
extern xstormy16_sem_fn xstormy16_sem_bccgrgr;
extern xstormy16_sem_fn xstormy16_sem_bccgrimm8;
extern xstormy16_sem_fn xstormy16_sem_bccimm16;
extern xstormy16_sem_fn xstormy16_sem_bngrimm4;
extern xstormy16_sem_fn xstormy16_sem_bngrgr;
extern xstormy16_sem_fn xstormy16_sem_bnlmemimm;
extern xstormy16_sem_fn xstormy16_sem_bnhmemimm;
extern xstormy16_sem_fn xstormy16_sem_bpgrimm4;
extern xstormy16_sem_fn xstormy16_sem_bpgrgr;
extern xstormy16_sem_fn xstormy16_sem_bplmemimm;
extern xstormy16_sem_fn xstormy16_sem_bphmemimm;
extern xstormy16_sem_fn xstormy16_sem_bcc;
extern xstormy16_sem_fn xstormy16_sem_bgr;
extern xstormy16_sem_fn xstormy16_sem_br;
extern xstormy16_sem_fn xstormy16_sem_jmp;
extern xstormy16_sem_fn xstormy16_sem_jmpf;
extern xstormy16_sem_fn xstormy16_sem_callrgr;
extern xstormy16_sem_fn xstormy16_sem_callrimm;
extern xstormy16_sem_fn xstormy16_sem_callgr;
extern xstormy16_sem_fn xstormy16_sem_callfimm;
extern xstormy16_sem_fn xstormy16_sem_icallrgr;
extern xstormy16_sem_fn xstormy16_sem_icallgr;
extern xstormy16_sem_fn xstormy16_sem_icallfimm;
extern xstormy16_sem_fn xstormy16_sem_iret;
extern xstormy16_sem_fn xstormy16_sem_ret;
extern xstormy16_sem_fn xstormy16_sem_mul;
extern xstormy16_sem_fn xstormy16_sem_div;
extern xstormy16_sem_fn xstormy16_sem_sdiv;
extern xstormy16_sem_fn xstormy16_sem_sdivlh;
extern xstormy16_sem_fn xstormy16_sem_divlh;
extern xstormy16_sem_fn xstormy16_sem_reset;
extern xstormy16_sem_fn xstormy16_sem_nop;
extern xstormy16_sem_fn xstormy16_sem_halt;
extern xstormy16_sem_fn xstormy16_sem_hold;
extern xstormy16_sem_fn xstormy16_sem_holdx;
extern xstormy16_sem_fn xstormy16_sem_brk;
extern xstormy16_sem_fn xstormy16_sem_syscall;

#endif /* XSTORMY16_DECODE_H */
