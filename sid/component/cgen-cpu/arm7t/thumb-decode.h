/* Decode header for thumb.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef THUMB_DECODE_H
#define THUMB_DECODE_H

namespace arm7f {

using namespace cgen;
using namespace arm;

typedef UINT thumb_insn_word;

/* Enum declaration for instructions in cpu family thumb.  */
typedef enum thumb_insn_type {
  THUMB_INSN_X_AFTER, THUMB_INSN_X_BEFORE, THUMB_INSN_X_CTI_CHAIN, THUMB_INSN_X_CHAIN
 , THUMB_INSN_X_BEGIN, THUMB_INSN_X_INVALID, THUMB_INSN_LSL, THUMB_INSN_LSR
 , THUMB_INSN_ASR, THUMB_INSN_ADD, THUMB_INSN_ADDI, THUMB_INSN_SUB
 , THUMB_INSN_SUBI, THUMB_INSN_MOV, THUMB_INSN_CMP, THUMB_INSN_ADDI8
 , THUMB_INSN_SUBI8, THUMB_INSN_ALU_AND, THUMB_INSN_ALU_EOR, THUMB_INSN_ALU_LSL
 , THUMB_INSN_ALU_LSR, THUMB_INSN_ALU_ASR, THUMB_INSN_ALU_ROR, THUMB_INSN_ALU_ADC
 , THUMB_INSN_ALU_SBC, THUMB_INSN_ALU_TST, THUMB_INSN_ALU_NEG, THUMB_INSN_ALU_CMP
 , THUMB_INSN_ALU_CMN, THUMB_INSN_ALU_ORR, THUMB_INSN_ALU_MUL, THUMB_INSN_ALU_BIC
 , THUMB_INSN_ALU_MVN, THUMB_INSN_ADD_RD_HS, THUMB_INSN_ADD_HD_RS, THUMB_INSN_ADD_HD_HS
 , THUMB_INSN_CMP_RD_HS, THUMB_INSN_CMP_HD_RS, THUMB_INSN_CMP_HD_HS, THUMB_INSN_MOV_RD_HS
 , THUMB_INSN_MOV_HD_RS, THUMB_INSN_MOV_HD_HS, THUMB_INSN_BX_RS, THUMB_INSN_BX_HS
 , THUMB_INSN_LDR_PC, THUMB_INSN_STR, THUMB_INSN_STRB, THUMB_INSN_LDR
 , THUMB_INSN_LDRB, THUMB_INSN_STRH, THUMB_INSN_LDRH, THUMB_INSN_LDSB
 , THUMB_INSN_LDSH, THUMB_INSN_STR_IMM, THUMB_INSN_LDR_IMM, THUMB_INSN_STRB_IMM
 , THUMB_INSN_LDRB_IMM, THUMB_INSN_STRH_IMM, THUMB_INSN_LDRH_IMM, THUMB_INSN_STR_SPREL
 , THUMB_INSN_LDR_SPREL, THUMB_INSN_LDA_PC, THUMB_INSN_LDA_SP, THUMB_INSN_ADD_SP
 , THUMB_INSN_SUB_SP, THUMB_INSN_PUSH, THUMB_INSN_PUSH_LR, THUMB_INSN_POP
 , THUMB_INSN_POP_PC, THUMB_INSN_STMIA, THUMB_INSN_LDMIA, THUMB_INSN_BEQ
 , THUMB_INSN_BNE, THUMB_INSN_BCS, THUMB_INSN_BCC, THUMB_INSN_BMI
 , THUMB_INSN_BPL, THUMB_INSN_BVS, THUMB_INSN_BVC, THUMB_INSN_BHI
 , THUMB_INSN_BLS, THUMB_INSN_BGE, THUMB_INSN_BLT, THUMB_INSN_BGT
 , THUMB_INSN_BLE, THUMB_INSN_SWI, THUMB_INSN_B, THUMB_INSN_BL_HI
 , THUMB_INSN_BL_LO
} THUMB_INSN_TYPE;


// Forward decls.
struct arm7f_cpu;
struct thumb_scache;
typedef sem_status (thumb_sem_fn) (arm7f_cpu* cpu, thumb_scache* sem);


// Instruction descriptor.

struct thumb_idesc {

  // computed-goto label pointer (pbb engine)
  // FIXME: frag case to be redone (should instead point to usage table).
  cgoto_label cgoto;

  // scache engine executor for this insn
  thumb_sem_fn* execute;

  const char* insn_name;
  enum thumb_insn_type sem_index;
  arm_insn_attr attrs;

  // idesc table: indexed by sem_index
  static thumb_idesc idesc_table[];

  // semantic label pointers filled_in?
  static bool idesc_table_initialized_p;

  static thumb_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union thumb_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_lbwl_lo;
  } sfmt_bl_lo;
  struct { /*  */
    INT f_lbwl_hi;
  } sfmt_bl_hi;
  struct { /*  */
    IADDR i_offset11;
  } sfmt_b;
  struct { /*  */
    UINT f_value8;
  } sfmt_swi;
  struct { /*  */
    IADDR i_soffset8;
  } sfmt_beq;
  struct { /*  */
    SI f_sword7;
  } sfmt_add_sp;
  struct { /*  */
    UINT f_bit10_rb;
    UINT f_rlist;
  } sfmt_stmia;
  struct { /*  */
    SI f_word8;
    UINT f_bit10_rd;
  } sfmt_ldr_pc;
  struct { /*  */
    UINT f_bit10_rd;
    UINT f_offset8;
  } sfmt_mov;
  struct { /*  */
    SI f_offset5_6;
    UINT f_rb;
    UINT f_rd;
  } sfmt_strh_imm;
  struct { /*  */
    UINT f_offset5;
    UINT f_rb;
    UINT f_rd;
  } sfmt_strb_imm;
  struct { /*  */
    SI f_offset5_7;
    UINT f_rb;
    UINT f_rd;
  } sfmt_str_imm;
  struct { /*  */
    UINT f_rb;
    UINT f_rd;
    UINT f_ro;
  } sfmt_str;
  struct { /*  */
    UINT f_offset3;
    UINT f_rd;
    UINT f_rs;
  } sfmt_addi;
  struct { /*  */
    UINT f_rd;
    UINT f_rn;
    UINT f_rs;
  } sfmt_add;
  struct { /*  */
    UINT f_offset5;
    UINT f_rd;
    UINT f_rs;
  } sfmt_lsl;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    thumb_scache* next;
    thumb_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    thumb_scache* insn;
  } before;
};

// Simulator instruction cache.

struct thumb_scache {
  // executor
  union {
    cgoto_label cgoto;
    thumb_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  thumb_idesc* idesc;

  // argument buffer
  thumb_sem_fields fields;



  // decode given instruction
  void decode (arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
};

} // end arm7f namespace

// Decls of each semantic fn.

using arm7f::thumb_sem_fn;
extern thumb_sem_fn thumb_sem_x_invalid;
extern thumb_sem_fn thumb_sem_lsl;
extern thumb_sem_fn thumb_sem_lsr;
extern thumb_sem_fn thumb_sem_asr;
extern thumb_sem_fn thumb_sem_add;
extern thumb_sem_fn thumb_sem_addi;
extern thumb_sem_fn thumb_sem_sub;
extern thumb_sem_fn thumb_sem_subi;
extern thumb_sem_fn thumb_sem_mov;
extern thumb_sem_fn thumb_sem_cmp;
extern thumb_sem_fn thumb_sem_addi8;
extern thumb_sem_fn thumb_sem_subi8;
extern thumb_sem_fn thumb_sem_alu_and;
extern thumb_sem_fn thumb_sem_alu_eor;
extern thumb_sem_fn thumb_sem_alu_lsl;
extern thumb_sem_fn thumb_sem_alu_lsr;
extern thumb_sem_fn thumb_sem_alu_asr;
extern thumb_sem_fn thumb_sem_alu_ror;
extern thumb_sem_fn thumb_sem_alu_adc;
extern thumb_sem_fn thumb_sem_alu_sbc;
extern thumb_sem_fn thumb_sem_alu_tst;
extern thumb_sem_fn thumb_sem_alu_neg;
extern thumb_sem_fn thumb_sem_alu_cmp;
extern thumb_sem_fn thumb_sem_alu_cmn;
extern thumb_sem_fn thumb_sem_alu_orr;
extern thumb_sem_fn thumb_sem_alu_mul;
extern thumb_sem_fn thumb_sem_alu_bic;
extern thumb_sem_fn thumb_sem_alu_mvn;
extern thumb_sem_fn thumb_sem_add_rd_hs;
extern thumb_sem_fn thumb_sem_add_hd_rs;
extern thumb_sem_fn thumb_sem_add_hd_hs;
extern thumb_sem_fn thumb_sem_cmp_rd_hs;
extern thumb_sem_fn thumb_sem_cmp_hd_rs;
extern thumb_sem_fn thumb_sem_cmp_hd_hs;
extern thumb_sem_fn thumb_sem_mov_rd_hs;
extern thumb_sem_fn thumb_sem_mov_hd_rs;
extern thumb_sem_fn thumb_sem_mov_hd_hs;
extern thumb_sem_fn thumb_sem_bx_rs;
extern thumb_sem_fn thumb_sem_bx_hs;
extern thumb_sem_fn thumb_sem_ldr_pc;
extern thumb_sem_fn thumb_sem_str;
extern thumb_sem_fn thumb_sem_strb;
extern thumb_sem_fn thumb_sem_ldr;
extern thumb_sem_fn thumb_sem_ldrb;
extern thumb_sem_fn thumb_sem_strh;
extern thumb_sem_fn thumb_sem_ldrh;
extern thumb_sem_fn thumb_sem_ldsb;
extern thumb_sem_fn thumb_sem_ldsh;
extern thumb_sem_fn thumb_sem_str_imm;
extern thumb_sem_fn thumb_sem_ldr_imm;
extern thumb_sem_fn thumb_sem_strb_imm;
extern thumb_sem_fn thumb_sem_ldrb_imm;
extern thumb_sem_fn thumb_sem_strh_imm;
extern thumb_sem_fn thumb_sem_ldrh_imm;
extern thumb_sem_fn thumb_sem_str_sprel;
extern thumb_sem_fn thumb_sem_ldr_sprel;
extern thumb_sem_fn thumb_sem_lda_pc;
extern thumb_sem_fn thumb_sem_lda_sp;
extern thumb_sem_fn thumb_sem_add_sp;
extern thumb_sem_fn thumb_sem_sub_sp;
extern thumb_sem_fn thumb_sem_push;
extern thumb_sem_fn thumb_sem_push_lr;
extern thumb_sem_fn thumb_sem_pop;
extern thumb_sem_fn thumb_sem_pop_pc;
extern thumb_sem_fn thumb_sem_stmia;
extern thumb_sem_fn thumb_sem_ldmia;
extern thumb_sem_fn thumb_sem_beq;
extern thumb_sem_fn thumb_sem_bne;
extern thumb_sem_fn thumb_sem_bcs;
extern thumb_sem_fn thumb_sem_bcc;
extern thumb_sem_fn thumb_sem_bmi;
extern thumb_sem_fn thumb_sem_bpl;
extern thumb_sem_fn thumb_sem_bvs;
extern thumb_sem_fn thumb_sem_bvc;
extern thumb_sem_fn thumb_sem_bhi;
extern thumb_sem_fn thumb_sem_bls;
extern thumb_sem_fn thumb_sem_bge;
extern thumb_sem_fn thumb_sem_blt;
extern thumb_sem_fn thumb_sem_bgt;
extern thumb_sem_fn thumb_sem_ble;
extern thumb_sem_fn thumb_sem_swi;
extern thumb_sem_fn thumb_sem_b;
extern thumb_sem_fn thumb_sem_bl_hi;
extern thumb_sem_fn thumb_sem_bl_lo;

#endif /* THUMB_DECODE_H */
