/* Decode header for m32rbf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef M32RBF_DECODE_H
#define M32RBF_DECODE_H

namespace m32rbf {

using namespace cgen;
using namespace m32r;

typedef UINT m32rbf_insn_word;

/* Enum declaration for instructions in cpu family m32rbf.  */
typedef enum m32rbf_insn_type {
  M32RBF_INSN_X_INVALID, M32RBF_INSN_ADD, M32RBF_INSN_ADD3, M32RBF_INSN_AND
 , M32RBF_INSN_AND3, M32RBF_INSN_OR, M32RBF_INSN_OR3, M32RBF_INSN_XOR
 , M32RBF_INSN_XOR3, M32RBF_INSN_ADDI, M32RBF_INSN_ADDV, M32RBF_INSN_ADDV3
 , M32RBF_INSN_ADDX, M32RBF_INSN_BC8, M32RBF_INSN_BC24, M32RBF_INSN_BEQ
 , M32RBF_INSN_BEQZ, M32RBF_INSN_BGEZ, M32RBF_INSN_BGTZ, M32RBF_INSN_BLEZ
 , M32RBF_INSN_BLTZ, M32RBF_INSN_BNEZ, M32RBF_INSN_BL8, M32RBF_INSN_BL24
 , M32RBF_INSN_BNC8, M32RBF_INSN_BNC24, M32RBF_INSN_BNE, M32RBF_INSN_BRA8
 , M32RBF_INSN_BRA24, M32RBF_INSN_CMP, M32RBF_INSN_CMPI, M32RBF_INSN_CMPU
 , M32RBF_INSN_CMPUI, M32RBF_INSN_DIV, M32RBF_INSN_DIVU, M32RBF_INSN_REM
 , M32RBF_INSN_REMU, M32RBF_INSN_JL, M32RBF_INSN_JMP, M32RBF_INSN_LD
 , M32RBF_INSN_LD_D, M32RBF_INSN_LDB, M32RBF_INSN_LDB_D, M32RBF_INSN_LDH
 , M32RBF_INSN_LDH_D, M32RBF_INSN_LDUB, M32RBF_INSN_LDUB_D, M32RBF_INSN_LDUH
 , M32RBF_INSN_LDUH_D, M32RBF_INSN_LD_PLUS, M32RBF_INSN_LD24, M32RBF_INSN_LDI8
 , M32RBF_INSN_LDI16, M32RBF_INSN_LOCK, M32RBF_INSN_MACHI, M32RBF_INSN_MACLO
 , M32RBF_INSN_MACWHI, M32RBF_INSN_MACWLO, M32RBF_INSN_MUL, M32RBF_INSN_MULHI
 , M32RBF_INSN_MULLO, M32RBF_INSN_MULWHI, M32RBF_INSN_MULWLO, M32RBF_INSN_MV
 , M32RBF_INSN_MVFACHI, M32RBF_INSN_MVFACLO, M32RBF_INSN_MVFACMI, M32RBF_INSN_MVFC
 , M32RBF_INSN_MVTACHI, M32RBF_INSN_MVTACLO, M32RBF_INSN_MVTC, M32RBF_INSN_NEG
 , M32RBF_INSN_NOP, M32RBF_INSN_NOT, M32RBF_INSN_RAC, M32RBF_INSN_RACH
 , M32RBF_INSN_RTE, M32RBF_INSN_SETH, M32RBF_INSN_SLL, M32RBF_INSN_SLL3
 , M32RBF_INSN_SLLI, M32RBF_INSN_SRA, M32RBF_INSN_SRA3, M32RBF_INSN_SRAI
 , M32RBF_INSN_SRL, M32RBF_INSN_SRL3, M32RBF_INSN_SRLI, M32RBF_INSN_ST
 , M32RBF_INSN_ST_D, M32RBF_INSN_STB, M32RBF_INSN_STB_D, M32RBF_INSN_STH
 , M32RBF_INSN_STH_D, M32RBF_INSN_ST_PLUS, M32RBF_INSN_ST_MINUS, M32RBF_INSN_SUB
 , M32RBF_INSN_SUBV, M32RBF_INSN_SUBX, M32RBF_INSN_TRAP, M32RBF_INSN_UNLOCK
 , M32RBF_INSN_CLRPSW, M32RBF_INSN_SETPSW, M32RBF_INSN_BSET, M32RBF_INSN_BCLR
 , M32RBF_INSN_BTST
} M32RBF_INSN_TYPE;


// Forward decls.
struct m32rbf_cpu;
struct m32rbf_scache;
typedef sem_status (m32rbf_sem_fn) (m32rbf_cpu* cpu, m32rbf_scache* sem);


// Instruction descriptor.

struct m32rbf_idesc {

  // scache engine executor for this insn
  m32rbf_sem_fn* execute;

  const char* insn_name;
  enum m32rbf_insn_type sem_index;
  m32r_insn_attr attrs;

  // idesc table: indexed by sem_index
  static m32rbf_idesc idesc_table[];

  static m32rbf_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union m32rbf_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_uimm8;
  } sfmt_clrpsw;
  struct { /*  */
    UINT f_uimm4;
  } sfmt_trap;
  struct { /*  */
    IADDR i_disp24;
  } sfmt_bc24;
  struct { /*  */
    IADDR i_disp8;
  } sfmt_bc8;
  struct { /*  */
    SI* i_dr;
    UINT f_r1;
    UINT f_uimm5;
  } sfmt_slli;
  struct { /*  */
    SI* i_dr;
    UINT f_hi16;
    UINT f_r1;
  } sfmt_seth;
  struct { /*  */
    ADDR i_uimm24;
    SI* i_dr;
    UINT f_r1;
  } sfmt_ld24;
  struct { /*  */
    SI* i_dr;
    INT f_simm8;
    UINT f_r1;
  } sfmt_addi;
  struct { /*  */
    SI* i_sr;
    INT f_simm16;
    UINT f_r2;
    UINT f_uimm3;
  } sfmt_bset;
  struct { /*  */
    SI* i_src1;
    SI* i_src2;
    INT f_simm16;
    UINT f_r1;
    UINT f_r2;
  } sfmt_st_d;
  struct { /*  */
    IADDR i_disp16;
    SI* i_src1;
    SI* i_src2;
    UINT f_r1;
    UINT f_r2;
  } sfmt_beq;
  struct { /*  */
    SI* i_dr;
    SI* i_sr;
    UINT f_r1;
    UINT f_r2;
    UINT f_uimm16;
  } sfmt_and3;
  struct { /*  */
    SI* i_dr;
    SI* i_sr;
    INT f_simm16;
    UINT f_r1;
    UINT f_r2;
  } sfmt_add3;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    m32rbf_scache* next;
    m32rbf_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    m32rbf_scache* insn;
  } before;
};

// Simulator instruction cache.

struct m32rbf_scache {
  // executor
  union {
    cgoto_label cgoto;
    m32rbf_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  m32rbf_idesc* idesc;

  // argument buffer
  m32rbf_sem_fields fields;



  // decode given instruction
  void decode (m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
};

} // end m32rbf namespace

// Decls of each semantic fn.

using m32rbf::m32rbf_sem_fn;
extern m32rbf_sem_fn m32rbf_sem_x_invalid;
extern m32rbf_sem_fn m32rbf_sem_add;
extern m32rbf_sem_fn m32rbf_sem_add3;
extern m32rbf_sem_fn m32rbf_sem_and;
extern m32rbf_sem_fn m32rbf_sem_and3;
extern m32rbf_sem_fn m32rbf_sem_or;
extern m32rbf_sem_fn m32rbf_sem_or3;
extern m32rbf_sem_fn m32rbf_sem_xor;
extern m32rbf_sem_fn m32rbf_sem_xor3;
extern m32rbf_sem_fn m32rbf_sem_addi;
extern m32rbf_sem_fn m32rbf_sem_addv;
extern m32rbf_sem_fn m32rbf_sem_addv3;
extern m32rbf_sem_fn m32rbf_sem_addx;
extern m32rbf_sem_fn m32rbf_sem_bc8;
extern m32rbf_sem_fn m32rbf_sem_bc24;
extern m32rbf_sem_fn m32rbf_sem_beq;
extern m32rbf_sem_fn m32rbf_sem_beqz;
extern m32rbf_sem_fn m32rbf_sem_bgez;
extern m32rbf_sem_fn m32rbf_sem_bgtz;
extern m32rbf_sem_fn m32rbf_sem_blez;
extern m32rbf_sem_fn m32rbf_sem_bltz;
extern m32rbf_sem_fn m32rbf_sem_bnez;
extern m32rbf_sem_fn m32rbf_sem_bl8;
extern m32rbf_sem_fn m32rbf_sem_bl24;
extern m32rbf_sem_fn m32rbf_sem_bnc8;
extern m32rbf_sem_fn m32rbf_sem_bnc24;
extern m32rbf_sem_fn m32rbf_sem_bne;
extern m32rbf_sem_fn m32rbf_sem_bra8;
extern m32rbf_sem_fn m32rbf_sem_bra24;
extern m32rbf_sem_fn m32rbf_sem_cmp;
extern m32rbf_sem_fn m32rbf_sem_cmpi;
extern m32rbf_sem_fn m32rbf_sem_cmpu;
extern m32rbf_sem_fn m32rbf_sem_cmpui;
extern m32rbf_sem_fn m32rbf_sem_div;
extern m32rbf_sem_fn m32rbf_sem_divu;
extern m32rbf_sem_fn m32rbf_sem_rem;
extern m32rbf_sem_fn m32rbf_sem_remu;
extern m32rbf_sem_fn m32rbf_sem_jl;
extern m32rbf_sem_fn m32rbf_sem_jmp;
extern m32rbf_sem_fn m32rbf_sem_ld;
extern m32rbf_sem_fn m32rbf_sem_ld_d;
extern m32rbf_sem_fn m32rbf_sem_ldb;
extern m32rbf_sem_fn m32rbf_sem_ldb_d;
extern m32rbf_sem_fn m32rbf_sem_ldh;
extern m32rbf_sem_fn m32rbf_sem_ldh_d;
extern m32rbf_sem_fn m32rbf_sem_ldub;
extern m32rbf_sem_fn m32rbf_sem_ldub_d;
extern m32rbf_sem_fn m32rbf_sem_lduh;
extern m32rbf_sem_fn m32rbf_sem_lduh_d;
extern m32rbf_sem_fn m32rbf_sem_ld_plus;
extern m32rbf_sem_fn m32rbf_sem_ld24;
extern m32rbf_sem_fn m32rbf_sem_ldi8;
extern m32rbf_sem_fn m32rbf_sem_ldi16;
extern m32rbf_sem_fn m32rbf_sem_lock;
extern m32rbf_sem_fn m32rbf_sem_machi;
extern m32rbf_sem_fn m32rbf_sem_maclo;
extern m32rbf_sem_fn m32rbf_sem_macwhi;
extern m32rbf_sem_fn m32rbf_sem_macwlo;
extern m32rbf_sem_fn m32rbf_sem_mul;
extern m32rbf_sem_fn m32rbf_sem_mulhi;
extern m32rbf_sem_fn m32rbf_sem_mullo;
extern m32rbf_sem_fn m32rbf_sem_mulwhi;
extern m32rbf_sem_fn m32rbf_sem_mulwlo;
extern m32rbf_sem_fn m32rbf_sem_mv;
extern m32rbf_sem_fn m32rbf_sem_mvfachi;
extern m32rbf_sem_fn m32rbf_sem_mvfaclo;
extern m32rbf_sem_fn m32rbf_sem_mvfacmi;
extern m32rbf_sem_fn m32rbf_sem_mvfc;
extern m32rbf_sem_fn m32rbf_sem_mvtachi;
extern m32rbf_sem_fn m32rbf_sem_mvtaclo;
extern m32rbf_sem_fn m32rbf_sem_mvtc;
extern m32rbf_sem_fn m32rbf_sem_neg;
extern m32rbf_sem_fn m32rbf_sem_nop;
extern m32rbf_sem_fn m32rbf_sem_not;
extern m32rbf_sem_fn m32rbf_sem_rac;
extern m32rbf_sem_fn m32rbf_sem_rach;
extern m32rbf_sem_fn m32rbf_sem_rte;
extern m32rbf_sem_fn m32rbf_sem_seth;
extern m32rbf_sem_fn m32rbf_sem_sll;
extern m32rbf_sem_fn m32rbf_sem_sll3;
extern m32rbf_sem_fn m32rbf_sem_slli;
extern m32rbf_sem_fn m32rbf_sem_sra;
extern m32rbf_sem_fn m32rbf_sem_sra3;
extern m32rbf_sem_fn m32rbf_sem_srai;
extern m32rbf_sem_fn m32rbf_sem_srl;
extern m32rbf_sem_fn m32rbf_sem_srl3;
extern m32rbf_sem_fn m32rbf_sem_srli;
extern m32rbf_sem_fn m32rbf_sem_st;
extern m32rbf_sem_fn m32rbf_sem_st_d;
extern m32rbf_sem_fn m32rbf_sem_stb;
extern m32rbf_sem_fn m32rbf_sem_stb_d;
extern m32rbf_sem_fn m32rbf_sem_sth;
extern m32rbf_sem_fn m32rbf_sem_sth_d;
extern m32rbf_sem_fn m32rbf_sem_st_plus;
extern m32rbf_sem_fn m32rbf_sem_st_minus;
extern m32rbf_sem_fn m32rbf_sem_sub;
extern m32rbf_sem_fn m32rbf_sem_subv;
extern m32rbf_sem_fn m32rbf_sem_subx;
extern m32rbf_sem_fn m32rbf_sem_trap;
extern m32rbf_sem_fn m32rbf_sem_unlock;
extern m32rbf_sem_fn m32rbf_sem_clrpsw;
extern m32rbf_sem_fn m32rbf_sem_setpsw;
extern m32rbf_sem_fn m32rbf_sem_bset;
extern m32rbf_sem_fn m32rbf_sem_bclr;
extern m32rbf_sem_fn m32rbf_sem_btst;

#endif /* M32RBF_DECODE_H */
