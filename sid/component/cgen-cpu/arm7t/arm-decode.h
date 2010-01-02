/* Decode header for arm.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef ARM_DECODE_H
#define ARM_DECODE_H

namespace arm7f {

using namespace cgen;
using namespace arm;

typedef UINT arm_insn_word;

/* Enum declaration for instructions in cpu family arm.  */
typedef enum arm_insn_type {
  ARM_INSN_X_COND, ARM_INSN_X_AFTER, ARM_INSN_X_BEFORE, ARM_INSN_X_CTI_CHAIN
 , ARM_INSN_X_CHAIN, ARM_INSN_X_BEGIN, ARM_INSN_X_INVALID, ARM_INSN_B
 , ARM_INSN_BL, ARM_INSN_BX, ARM_INSN_LDR_POST_DEC_IMM_OFFSET, ARM_INSN_LDR_POST_DEC_REG_OFFSET
 , ARM_INSN_LDR_POST_INC_IMM_OFFSET, ARM_INSN_LDR_POST_INC_REG_OFFSET, ARM_INSN_LDR_POST_DEC_NONPRIV_IMM_OFFSET, ARM_INSN_LDR_POST_DEC_NONPRIV_REG_OFFSET
 , ARM_INSN_LDR_POST_INC_NONPRIV_IMM_OFFSET, ARM_INSN_LDR_POST_INC_NONPRIV_REG_OFFSET, ARM_INSN_LDR_PRE_DEC_IMM_OFFSET, ARM_INSN_LDR_PRE_DEC_REG_OFFSET
 , ARM_INSN_LDR_PRE_INC_IMM_OFFSET, ARM_INSN_LDR_PRE_INC_REG_OFFSET, ARM_INSN_LDR_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_LDR_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_LDR_PRE_INC_WB_IMM_OFFSET, ARM_INSN_LDR_PRE_INC_WB_REG_OFFSET, ARM_INSN_LDRB_POST_DEC_IMM_OFFSET, ARM_INSN_LDRB_POST_DEC_REG_OFFSET
 , ARM_INSN_LDRB_POST_INC_IMM_OFFSET, ARM_INSN_LDRB_POST_INC_REG_OFFSET, ARM_INSN_LDRB_POST_DEC_NONPRIV_IMM_OFFSET, ARM_INSN_LDRB_POST_DEC_NONPRIV_REG_OFFSET
 , ARM_INSN_LDRB_POST_INC_NONPRIV_IMM_OFFSET, ARM_INSN_LDRB_POST_INC_NONPRIV_REG_OFFSET, ARM_INSN_LDRB_PRE_DEC_IMM_OFFSET, ARM_INSN_LDRB_PRE_DEC_REG_OFFSET
 , ARM_INSN_LDRB_PRE_INC_IMM_OFFSET, ARM_INSN_LDRB_PRE_INC_REG_OFFSET, ARM_INSN_LDRB_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_LDRB_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_LDRB_PRE_INC_WB_IMM_OFFSET, ARM_INSN_LDRB_PRE_INC_WB_REG_OFFSET, ARM_INSN_STR_POST_DEC_IMM_OFFSET, ARM_INSN_STR_POST_DEC_REG_OFFSET
 , ARM_INSN_STR_POST_INC_IMM_OFFSET, ARM_INSN_STR_POST_INC_REG_OFFSET, ARM_INSN_STR_POST_DEC_NONPRIV_IMM_OFFSET, ARM_INSN_STR_POST_DEC_NONPRIV_REG_OFFSET
 , ARM_INSN_STR_POST_INC_NONPRIV_IMM_OFFSET, ARM_INSN_STR_POST_INC_NONPRIV_REG_OFFSET, ARM_INSN_STR_PRE_DEC_IMM_OFFSET, ARM_INSN_STR_PRE_DEC_REG_OFFSET
 , ARM_INSN_STR_PRE_INC_IMM_OFFSET, ARM_INSN_STR_PRE_INC_REG_OFFSET, ARM_INSN_STR_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_STR_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_STR_PRE_INC_WB_IMM_OFFSET, ARM_INSN_STR_PRE_INC_WB_REG_OFFSET, ARM_INSN_STRB_POST_DEC_IMM_OFFSET, ARM_INSN_STRB_POST_DEC_REG_OFFSET
 , ARM_INSN_STRB_POST_INC_IMM_OFFSET, ARM_INSN_STRB_POST_INC_REG_OFFSET, ARM_INSN_STRB_POST_DEC_NONPRIV_IMM_OFFSET, ARM_INSN_STRB_POST_DEC_NONPRIV_REG_OFFSET
 , ARM_INSN_STRB_POST_INC_NONPRIV_IMM_OFFSET, ARM_INSN_STRB_POST_INC_NONPRIV_REG_OFFSET, ARM_INSN_STRB_PRE_DEC_IMM_OFFSET, ARM_INSN_STRB_PRE_DEC_REG_OFFSET
 , ARM_INSN_STRB_PRE_INC_IMM_OFFSET, ARM_INSN_STRB_PRE_INC_REG_OFFSET, ARM_INSN_STRB_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_STRB_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_STRB_PRE_INC_WB_IMM_OFFSET, ARM_INSN_STRB_PRE_INC_WB_REG_OFFSET, ARM_INSN_STRH_PRE_DEC_IMM_OFFSET, ARM_INSN_STRH_PRE_DEC_REG_OFFSET
 , ARM_INSN_STRH_PRE_INC_IMM_OFFSET, ARM_INSN_STRH_PRE_INC_REG_OFFSET, ARM_INSN_STRH_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_STRH_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_STRH_PRE_INC_WB_IMM_OFFSET, ARM_INSN_STRH_PRE_INC_WB_REG_OFFSET, ARM_INSN_STRH_POST_DEC_IMM_OFFSET, ARM_INSN_STRH_POST_DEC_REG_OFFSET
 , ARM_INSN_STRH_POST_INC_IMM_OFFSET, ARM_INSN_STRH_POST_INC_REG_OFFSET, ARM_INSN_LDRSB_PRE_DEC_IMM_OFFSET, ARM_INSN_LDRSB_PRE_DEC_REG_OFFSET
 , ARM_INSN_LDRSB_PRE_INC_IMM_OFFSET, ARM_INSN_LDRSB_PRE_INC_REG_OFFSET, ARM_INSN_LDRSB_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_LDRSB_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_LDRSB_PRE_INC_WB_IMM_OFFSET, ARM_INSN_LDRSB_PRE_INC_WB_REG_OFFSET, ARM_INSN_LDRSB_POST_DEC_IMM_OFFSET, ARM_INSN_LDRSB_POST_DEC_REG_OFFSET
 , ARM_INSN_LDRSB_POST_INC_IMM_OFFSET, ARM_INSN_LDRSB_POST_INC_REG_OFFSET, ARM_INSN_LDRH_PRE_DEC_IMM_OFFSET, ARM_INSN_LDRH_PRE_DEC_REG_OFFSET
 , ARM_INSN_LDRH_PRE_INC_IMM_OFFSET, ARM_INSN_LDRH_PRE_INC_REG_OFFSET, ARM_INSN_LDRH_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_LDRH_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_LDRH_PRE_INC_WB_IMM_OFFSET, ARM_INSN_LDRH_PRE_INC_WB_REG_OFFSET, ARM_INSN_LDRH_POST_DEC_IMM_OFFSET, ARM_INSN_LDRH_POST_DEC_REG_OFFSET
 , ARM_INSN_LDRH_POST_INC_IMM_OFFSET, ARM_INSN_LDRH_POST_INC_REG_OFFSET, ARM_INSN_LDRSH_PRE_DEC_IMM_OFFSET, ARM_INSN_LDRSH_PRE_DEC_REG_OFFSET
 , ARM_INSN_LDRSH_PRE_INC_IMM_OFFSET, ARM_INSN_LDRSH_PRE_INC_REG_OFFSET, ARM_INSN_LDRSH_PRE_DEC_WB_IMM_OFFSET, ARM_INSN_LDRSH_PRE_DEC_WB_REG_OFFSET
 , ARM_INSN_LDRSH_PRE_INC_WB_IMM_OFFSET, ARM_INSN_LDRSH_PRE_INC_WB_REG_OFFSET, ARM_INSN_LDRSH_POST_DEC_IMM_OFFSET, ARM_INSN_LDRSH_POST_DEC_REG_OFFSET
 , ARM_INSN_LDRSH_POST_INC_IMM_OFFSET, ARM_INSN_LDRSH_POST_INC_REG_OFFSET, ARM_INSN_MUL, ARM_INSN_MLA
 , ARM_INSN_UMULL, ARM_INSN_UMLAL, ARM_INSN_SMULL, ARM_INSN_SMLAL
 , ARM_INSN_SWP, ARM_INSN_SWPB, ARM_INSN_SWI, ARM_INSN_AND_REG_IMM_SHIFT
 , ARM_INSN_AND_REG_REG_SHIFT, ARM_INSN_AND_IMM, ARM_INSN_ORR_REG_IMM_SHIFT, ARM_INSN_ORR_REG_REG_SHIFT
 , ARM_INSN_ORR_IMM, ARM_INSN_EOR_REG_IMM_SHIFT, ARM_INSN_EOR_REG_REG_SHIFT, ARM_INSN_EOR_IMM
 , ARM_INSN_MOV_REG_IMM_SHIFT, ARM_INSN_MOV_REG_REG_SHIFT, ARM_INSN_MOV_IMM, ARM_INSN_BIC_REG_IMM_SHIFT
 , ARM_INSN_BIC_REG_REG_SHIFT, ARM_INSN_BIC_IMM, ARM_INSN_MVN_REG_IMM_SHIFT, ARM_INSN_MVN_REG_REG_SHIFT
 , ARM_INSN_MVN_IMM, ARM_INSN_ADD_REG_IMM_SHIFT, ARM_INSN_ADD_REG_REG_SHIFT, ARM_INSN_ADD_IMM
 , ARM_INSN_ADC_REG_IMM_SHIFT, ARM_INSN_ADC_REG_REG_SHIFT, ARM_INSN_ADC_IMM, ARM_INSN_SUB_REG_IMM_SHIFT
 , ARM_INSN_SUB_REG_REG_SHIFT, ARM_INSN_SUB_IMM, ARM_INSN_SBC_REG_IMM_SHIFT, ARM_INSN_SBC_REG_REG_SHIFT
 , ARM_INSN_SBC_IMM, ARM_INSN_RSB_REG_IMM_SHIFT, ARM_INSN_RSB_REG_REG_SHIFT, ARM_INSN_RSB_IMM
 , ARM_INSN_RSC_REG_IMM_SHIFT, ARM_INSN_RSC_REG_REG_SHIFT, ARM_INSN_RSC_IMM, ARM_INSN_TST_REG_IMM_SHIFT
 , ARM_INSN_TST_REG_REG_SHIFT, ARM_INSN_TST_IMM, ARM_INSN_TEQ_REG_IMM_SHIFT, ARM_INSN_TEQ_REG_REG_SHIFT
 , ARM_INSN_TEQ_IMM, ARM_INSN_CMP_REG_IMM_SHIFT, ARM_INSN_CMP_REG_REG_SHIFT, ARM_INSN_CMP_IMM
 , ARM_INSN_CMN_REG_IMM_SHIFT, ARM_INSN_CMN_REG_REG_SHIFT, ARM_INSN_CMN_IMM, ARM_INSN_LDMDA
 , ARM_INSN_LDMDA_SW, ARM_INSN_LDMDA_WB, ARM_INSN_LDMDA_SW_WB, ARM_INSN_LDMIB
 , ARM_INSN_LDMIB_SW, ARM_INSN_LDMIB_WB, ARM_INSN_LDMIB_SW_WB, ARM_INSN_LDMIA
 , ARM_INSN_LDMIA_SW, ARM_INSN_LDMIA_WB, ARM_INSN_LDMIA_SW_WB, ARM_INSN_LDMDB
 , ARM_INSN_LDMDB_SW, ARM_INSN_LDMDB_WB, ARM_INSN_LDMDB_SW_WB, ARM_INSN_STMDB
 , ARM_INSN_STMDB_SW, ARM_INSN_STMDB_WB, ARM_INSN_STMDB_SW_WB, ARM_INSN_STMIB
 , ARM_INSN_STMIB_SW, ARM_INSN_STMIB_WB, ARM_INSN_STMIB_SW_WB, ARM_INSN_STMIA
 , ARM_INSN_STMIA_SW, ARM_INSN_STMIA_WB, ARM_INSN_STMIA_SW_WB, ARM_INSN_STMDA
 , ARM_INSN_STMDA_SW, ARM_INSN_STMDA_WB, ARM_INSN_STMDA_SW_WB, ARM_INSN_MRS_C
 , ARM_INSN_MRS_S, ARM_INSN_MSR_C, ARM_INSN_MSR_S
} ARM_INSN_TYPE;


// Forward decls.
struct arm7f_cpu;
struct arm_scache;
typedef sem_status (arm_sem_fn) (arm7f_cpu* cpu, arm_scache* sem);


// Instruction descriptor.

struct arm_idesc {

  // computed-goto label pointer (pbb engine)
  // FIXME: frag case to be redone (should instead point to usage table).
  cgoto_label cgoto;

  // scache engine executor for this insn
  arm_sem_fn* execute;

  const char* insn_name;
  enum arm_insn_type sem_index;
  arm_insn_attr attrs;

  // idesc table: indexed by sem_index
  static arm_idesc idesc_table[];

  // semantic label pointers filled_in?
  static bool idesc_table_initialized_p;

  static arm_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union arm_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_swi_comment;
  } sfmt_swi;
  struct { /*  */
    IADDR i_offset24;
  } sfmt_b;
  struct { /*  */
    SI* i_bx_rn;
    UINT f_bx_rn;
  } sfmt_bx;
  struct { /*  */
    SI* i_rn;
    UINT f_reg_list;
    UINT f_rn;
  } sfmt_ldmda;
  struct { /*  */
    SI* i_rn;
    UINT f_rn;
    UINT f_ror_imm8;
    UINT f_ror_imm8_rotate;
  } sfmt_tst_imm;
  struct { /*  */
    ADDR i_hdt_offset8;
    SI* i_rd;
    SI* i_rn;
    UINT f_rd;
    UINT f_rn;
  } sfmt_strh_pre_dec_imm_offset;
  struct { /*  */
    SI* i_rd;
    SI* i_rn;
    UINT f_rd;
    UINT f_rn;
    UINT f_uimm12;
  } sfmt_ldr_post_dec_imm_offset;
  struct { /*  */
    SI* i_rd;
    SI* i_rn;
    SI f_imm12;
    UINT f_rd;
    UINT f_rn;
    UINT f_set_cc_;
  } sfmt_and_imm;
  struct { /*  */
    SI* i_rd;
    SI* i_rm;
    SI* i_rn;
    UINT f_operand2_shiftimm;
    UINT f_operand2_shifttype;
    UINT f_rd;
    UINT f_rm;
    UINT f_rn;
    UINT f_set_cc_;
  } sfmt_and_reg_imm_shift;
  struct { /*  */
    SI* i_rdhi;
    SI* i_rdlo;
    SI* i_rm;
    SI* i_rs;
    UINT f_rdhi;
    UINT f_rdlo;
    UINT f_rm;
    UINT f_rs;
    UINT f_set_cc_;
  } sfmt_umull;
  struct { /*  */
    SI* i_mul_rd;
    SI* i_mul_rn;
    SI* i_rm;
    SI* i_rs;
    UINT f_mul_rd;
    UINT f_mul_rn;
    UINT f_rm;
    UINT f_rs;
    UINT f_set_cc_;
  } sfmt_mla;
  struct { /*  */
    SI* i_operand2_shiftreg;
    SI* i_rd;
    SI* i_rm;
    SI* i_rn;
    UINT f_operand2_shiftreg;
    UINT f_operand2_shifttype;
    UINT f_rd;
    UINT f_rm;
    UINT f_rn;
    UINT f_set_cc_;
  } sfmt_and_reg_reg_shift;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    arm_scache* next;
    arm_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    arm_scache* insn;
  } before;
};

// Simulator instruction cache.

struct arm_scache {
  // executor
  union {
    cgoto_label cgoto;
    arm_sem_fn* fn;
  } execute;

  // condition
  UINT cond;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  arm_idesc* idesc;

  // argument buffer
  arm_sem_fields fields;



  // decode given instruction
  void decode (arm7f_cpu* current_cpu, PCADDR pc, arm_insn_word base_insn, arm_insn_word entire_insn);
};

} // end arm7f namespace

// Decls of each semantic fn.

using arm7f::arm_sem_fn;
extern arm_sem_fn arm_sem_x_invalid;
extern arm_sem_fn arm_sem_b;
extern arm_sem_fn arm_sem_bl;
extern arm_sem_fn arm_sem_bx;
extern arm_sem_fn arm_sem_ldr_post_dec_imm_offset;
extern arm_sem_fn arm_sem_ldr_post_dec_reg_offset;
extern arm_sem_fn arm_sem_ldr_post_inc_imm_offset;
extern arm_sem_fn arm_sem_ldr_post_inc_reg_offset;
extern arm_sem_fn arm_sem_ldr_post_dec_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_ldr_post_dec_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_ldr_post_inc_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_ldr_post_inc_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_ldr_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_ldr_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_ldr_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_ldr_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_ldr_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_ldr_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_ldr_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_ldr_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrb_post_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrb_post_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrb_post_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrb_post_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrb_post_dec_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_ldrb_post_dec_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_ldrb_post_inc_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_ldrb_post_inc_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_ldrb_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrb_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrb_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrb_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrb_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrb_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrb_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrb_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_str_post_dec_imm_offset;
extern arm_sem_fn arm_sem_str_post_dec_reg_offset;
extern arm_sem_fn arm_sem_str_post_inc_imm_offset;
extern arm_sem_fn arm_sem_str_post_inc_reg_offset;
extern arm_sem_fn arm_sem_str_post_dec_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_str_post_dec_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_str_post_inc_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_str_post_inc_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_str_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_str_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_str_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_str_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_str_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_str_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_str_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_str_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_strb_post_dec_imm_offset;
extern arm_sem_fn arm_sem_strb_post_dec_reg_offset;
extern arm_sem_fn arm_sem_strb_post_inc_imm_offset;
extern arm_sem_fn arm_sem_strb_post_inc_reg_offset;
extern arm_sem_fn arm_sem_strb_post_dec_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_strb_post_dec_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_strb_post_inc_nonpriv_imm_offset;
extern arm_sem_fn arm_sem_strb_post_inc_nonpriv_reg_offset;
extern arm_sem_fn arm_sem_strb_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_strb_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_strb_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_strb_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_strb_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_strb_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_strb_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_strb_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_strh_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_strh_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_strh_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_strh_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_strh_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_strh_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_strh_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_strh_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_strh_post_dec_imm_offset;
extern arm_sem_fn arm_sem_strh_post_dec_reg_offset;
extern arm_sem_fn arm_sem_strh_post_inc_imm_offset;
extern arm_sem_fn arm_sem_strh_post_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrsb_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrsb_post_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrsb_post_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrsb_post_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrsb_post_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrh_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrh_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrh_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrh_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrh_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrh_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrh_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrh_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrh_post_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrh_post_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrh_post_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrh_post_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_inc_reg_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_dec_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_dec_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_inc_wb_imm_offset;
extern arm_sem_fn arm_sem_ldrsh_pre_inc_wb_reg_offset;
extern arm_sem_fn arm_sem_ldrsh_post_dec_imm_offset;
extern arm_sem_fn arm_sem_ldrsh_post_dec_reg_offset;
extern arm_sem_fn arm_sem_ldrsh_post_inc_imm_offset;
extern arm_sem_fn arm_sem_ldrsh_post_inc_reg_offset;
extern arm_sem_fn arm_sem_mul;
extern arm_sem_fn arm_sem_mla;
extern arm_sem_fn arm_sem_umull;
extern arm_sem_fn arm_sem_umlal;
extern arm_sem_fn arm_sem_smull;
extern arm_sem_fn arm_sem_smlal;
extern arm_sem_fn arm_sem_swp;
extern arm_sem_fn arm_sem_swpb;
extern arm_sem_fn arm_sem_swi;
extern arm_sem_fn arm_sem_and_reg_imm_shift;
extern arm_sem_fn arm_sem_and_reg_reg_shift;
extern arm_sem_fn arm_sem_and_imm;
extern arm_sem_fn arm_sem_orr_reg_imm_shift;
extern arm_sem_fn arm_sem_orr_reg_reg_shift;
extern arm_sem_fn arm_sem_orr_imm;
extern arm_sem_fn arm_sem_eor_reg_imm_shift;
extern arm_sem_fn arm_sem_eor_reg_reg_shift;
extern arm_sem_fn arm_sem_eor_imm;
extern arm_sem_fn arm_sem_mov_reg_imm_shift;
extern arm_sem_fn arm_sem_mov_reg_reg_shift;
extern arm_sem_fn arm_sem_mov_imm;
extern arm_sem_fn arm_sem_bic_reg_imm_shift;
extern arm_sem_fn arm_sem_bic_reg_reg_shift;
extern arm_sem_fn arm_sem_bic_imm;
extern arm_sem_fn arm_sem_mvn_reg_imm_shift;
extern arm_sem_fn arm_sem_mvn_reg_reg_shift;
extern arm_sem_fn arm_sem_mvn_imm;
extern arm_sem_fn arm_sem_add_reg_imm_shift;
extern arm_sem_fn arm_sem_add_reg_reg_shift;
extern arm_sem_fn arm_sem_add_imm;
extern arm_sem_fn arm_sem_adc_reg_imm_shift;
extern arm_sem_fn arm_sem_adc_reg_reg_shift;
extern arm_sem_fn arm_sem_adc_imm;
extern arm_sem_fn arm_sem_sub_reg_imm_shift;
extern arm_sem_fn arm_sem_sub_reg_reg_shift;
extern arm_sem_fn arm_sem_sub_imm;
extern arm_sem_fn arm_sem_sbc_reg_imm_shift;
extern arm_sem_fn arm_sem_sbc_reg_reg_shift;
extern arm_sem_fn arm_sem_sbc_imm;
extern arm_sem_fn arm_sem_rsb_reg_imm_shift;
extern arm_sem_fn arm_sem_rsb_reg_reg_shift;
extern arm_sem_fn arm_sem_rsb_imm;
extern arm_sem_fn arm_sem_rsc_reg_imm_shift;
extern arm_sem_fn arm_sem_rsc_reg_reg_shift;
extern arm_sem_fn arm_sem_rsc_imm;
extern arm_sem_fn arm_sem_tst_reg_imm_shift;
extern arm_sem_fn arm_sem_tst_reg_reg_shift;
extern arm_sem_fn arm_sem_tst_imm;
extern arm_sem_fn arm_sem_teq_reg_imm_shift;
extern arm_sem_fn arm_sem_teq_reg_reg_shift;
extern arm_sem_fn arm_sem_teq_imm;
extern arm_sem_fn arm_sem_cmp_reg_imm_shift;
extern arm_sem_fn arm_sem_cmp_reg_reg_shift;
extern arm_sem_fn arm_sem_cmp_imm;
extern arm_sem_fn arm_sem_cmn_reg_imm_shift;
extern arm_sem_fn arm_sem_cmn_reg_reg_shift;
extern arm_sem_fn arm_sem_cmn_imm;
extern arm_sem_fn arm_sem_ldmda;
extern arm_sem_fn arm_sem_ldmda_sw;
extern arm_sem_fn arm_sem_ldmda_wb;
extern arm_sem_fn arm_sem_ldmda_sw_wb;
extern arm_sem_fn arm_sem_ldmib;
extern arm_sem_fn arm_sem_ldmib_sw;
extern arm_sem_fn arm_sem_ldmib_wb;
extern arm_sem_fn arm_sem_ldmib_sw_wb;
extern arm_sem_fn arm_sem_ldmia;
extern arm_sem_fn arm_sem_ldmia_sw;
extern arm_sem_fn arm_sem_ldmia_wb;
extern arm_sem_fn arm_sem_ldmia_sw_wb;
extern arm_sem_fn arm_sem_ldmdb;
extern arm_sem_fn arm_sem_ldmdb_sw;
extern arm_sem_fn arm_sem_ldmdb_wb;
extern arm_sem_fn arm_sem_ldmdb_sw_wb;
extern arm_sem_fn arm_sem_stmdb;
extern arm_sem_fn arm_sem_stmdb_sw;
extern arm_sem_fn arm_sem_stmdb_wb;
extern arm_sem_fn arm_sem_stmdb_sw_wb;
extern arm_sem_fn arm_sem_stmib;
extern arm_sem_fn arm_sem_stmib_sw;
extern arm_sem_fn arm_sem_stmib_wb;
extern arm_sem_fn arm_sem_stmib_sw_wb;
extern arm_sem_fn arm_sem_stmia;
extern arm_sem_fn arm_sem_stmia_sw;
extern arm_sem_fn arm_sem_stmia_wb;
extern arm_sem_fn arm_sem_stmia_sw_wb;
extern arm_sem_fn arm_sem_stmda;
extern arm_sem_fn arm_sem_stmda_sw;
extern arm_sem_fn arm_sem_stmda_wb;
extern arm_sem_fn arm_sem_stmda_sw_wb;
extern arm_sem_fn arm_sem_mrs_c;
extern arm_sem_fn arm_sem_mrs_s;
extern arm_sem_fn arm_sem_msr_c;
extern arm_sem_fn arm_sem_msr_s;

#endif /* ARM_DECODE_H */
