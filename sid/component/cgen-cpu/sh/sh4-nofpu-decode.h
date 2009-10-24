/* Decode header for sh4_nofpu.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef SH4_NOFPU_DECODE_H
#define SH4_NOFPU_DECODE_H

namespace sh4_nofpu {
// forward declaration of struct in -defs.h
struct write_stacks;
}

namespace sh4_nofpu {

using namespace cgen;
using namespace sh;

typedef UINT sh4_nofpu_insn_word;

/* Enum declaration for instructions in cpu family sh4_nofpu.  */
typedef enum sh4_nofpu_insn_type {
  SH4_NOFPU_INSN_X_INVALID, SH4_NOFPU_INSN_ADD_COMPACT, SH4_NOFPU_INSN_ADDI_COMPACT, SH4_NOFPU_INSN_ADDC_COMPACT
 , SH4_NOFPU_INSN_ADDV_COMPACT, SH4_NOFPU_INSN_AND_COMPACT, SH4_NOFPU_INSN_ANDI_COMPACT, SH4_NOFPU_INSN_ANDB_COMPACT
 , SH4_NOFPU_INSN_BF_COMPACT, SH4_NOFPU_INSN_BFS_COMPACT, SH4_NOFPU_INSN_BRA_COMPACT, SH4_NOFPU_INSN_BRAF_COMPACT
 , SH4_NOFPU_INSN_BSR_COMPACT, SH4_NOFPU_INSN_BSRF_COMPACT, SH4_NOFPU_INSN_BT_COMPACT, SH4_NOFPU_INSN_BTS_COMPACT
 , SH4_NOFPU_INSN_CLRMAC_COMPACT, SH4_NOFPU_INSN_CLRS_COMPACT, SH4_NOFPU_INSN_CLRT_COMPACT, SH4_NOFPU_INSN_CMPEQ_COMPACT
 , SH4_NOFPU_INSN_CMPEQI_COMPACT, SH4_NOFPU_INSN_CMPGE_COMPACT, SH4_NOFPU_INSN_CMPGT_COMPACT, SH4_NOFPU_INSN_CMPHI_COMPACT
 , SH4_NOFPU_INSN_CMPHS_COMPACT, SH4_NOFPU_INSN_CMPPL_COMPACT, SH4_NOFPU_INSN_CMPPZ_COMPACT, SH4_NOFPU_INSN_CMPSTR_COMPACT
 , SH4_NOFPU_INSN_DIV0S_COMPACT, SH4_NOFPU_INSN_DIV0U_COMPACT, SH4_NOFPU_INSN_DIV1_COMPACT, SH4_NOFPU_INSN_DIVU_COMPACT
 , SH4_NOFPU_INSN_MULR_COMPACT, SH4_NOFPU_INSN_DMULSL_COMPACT, SH4_NOFPU_INSN_DMULUL_COMPACT, SH4_NOFPU_INSN_DT_COMPACT
 , SH4_NOFPU_INSN_EXTSB_COMPACT, SH4_NOFPU_INSN_EXTSW_COMPACT, SH4_NOFPU_INSN_EXTUB_COMPACT, SH4_NOFPU_INSN_EXTUW_COMPACT
 , SH4_NOFPU_INSN_FRCHG_COMPACT, SH4_NOFPU_INSN_FSCHG_COMPACT, SH4_NOFPU_INSN_JMP_COMPACT, SH4_NOFPU_INSN_JSR_COMPACT
 , SH4_NOFPU_INSN_LDC_GBR_COMPACT, SH4_NOFPU_INSN_LDC_VBR_COMPACT, SH4_NOFPU_INSN_LDC_SR_COMPACT, SH4_NOFPU_INSN_LDCL_GBR_COMPACT
 , SH4_NOFPU_INSN_LDCL_VBR_COMPACT, SH4_NOFPU_INSN_LDS_MACH_COMPACT, SH4_NOFPU_INSN_LDSL_MACH_COMPACT, SH4_NOFPU_INSN_LDS_MACL_COMPACT
 , SH4_NOFPU_INSN_LDSL_MACL_COMPACT, SH4_NOFPU_INSN_LDS_PR_COMPACT, SH4_NOFPU_INSN_LDSL_PR_COMPACT, SH4_NOFPU_INSN_MACL_COMPACT
 , SH4_NOFPU_INSN_MACW_COMPACT, SH4_NOFPU_INSN_MOV_COMPACT, SH4_NOFPU_INSN_MOVI_COMPACT, SH4_NOFPU_INSN_MOVI20_COMPACT
 , SH4_NOFPU_INSN_MOVB1_COMPACT, SH4_NOFPU_INSN_MOVB2_COMPACT, SH4_NOFPU_INSN_MOVB3_COMPACT, SH4_NOFPU_INSN_MOVB4_COMPACT
 , SH4_NOFPU_INSN_MOVB5_COMPACT, SH4_NOFPU_INSN_MOVB6_COMPACT, SH4_NOFPU_INSN_MOVB7_COMPACT, SH4_NOFPU_INSN_MOVB8_COMPACT
 , SH4_NOFPU_INSN_MOVB9_COMPACT, SH4_NOFPU_INSN_MOVB10_COMPACT, SH4_NOFPU_INSN_MOVL1_COMPACT, SH4_NOFPU_INSN_MOVL2_COMPACT
 , SH4_NOFPU_INSN_MOVL3_COMPACT, SH4_NOFPU_INSN_MOVL4_COMPACT, SH4_NOFPU_INSN_MOVL5_COMPACT, SH4_NOFPU_INSN_MOVL6_COMPACT
 , SH4_NOFPU_INSN_MOVL7_COMPACT, SH4_NOFPU_INSN_MOVL8_COMPACT, SH4_NOFPU_INSN_MOVL9_COMPACT, SH4_NOFPU_INSN_MOVL10_COMPACT
 , SH4_NOFPU_INSN_MOVL11_COMPACT, SH4_NOFPU_INSN_MOVL12_COMPACT, SH4_NOFPU_INSN_MOVL13_COMPACT, SH4_NOFPU_INSN_MOVW1_COMPACT
 , SH4_NOFPU_INSN_MOVW2_COMPACT, SH4_NOFPU_INSN_MOVW3_COMPACT, SH4_NOFPU_INSN_MOVW4_COMPACT, SH4_NOFPU_INSN_MOVW5_COMPACT
 , SH4_NOFPU_INSN_MOVW6_COMPACT, SH4_NOFPU_INSN_MOVW7_COMPACT, SH4_NOFPU_INSN_MOVW8_COMPACT, SH4_NOFPU_INSN_MOVW9_COMPACT
 , SH4_NOFPU_INSN_MOVW10_COMPACT, SH4_NOFPU_INSN_MOVW11_COMPACT, SH4_NOFPU_INSN_MOVA_COMPACT, SH4_NOFPU_INSN_MOVCAL_COMPACT
 , SH4_NOFPU_INSN_MOVT_COMPACT, SH4_NOFPU_INSN_MULL_COMPACT, SH4_NOFPU_INSN_MULSW_COMPACT, SH4_NOFPU_INSN_MULUW_COMPACT
 , SH4_NOFPU_INSN_NEG_COMPACT, SH4_NOFPU_INSN_NEGC_COMPACT, SH4_NOFPU_INSN_NOP_COMPACT, SH4_NOFPU_INSN_NOT_COMPACT
 , SH4_NOFPU_INSN_OCBI_COMPACT, SH4_NOFPU_INSN_OCBP_COMPACT, SH4_NOFPU_INSN_OCBWB_COMPACT, SH4_NOFPU_INSN_OR_COMPACT
 , SH4_NOFPU_INSN_ORI_COMPACT, SH4_NOFPU_INSN_ORB_COMPACT, SH4_NOFPU_INSN_PREF_COMPACT, SH4_NOFPU_INSN_ROTCL_COMPACT
 , SH4_NOFPU_INSN_ROTCR_COMPACT, SH4_NOFPU_INSN_ROTL_COMPACT, SH4_NOFPU_INSN_ROTR_COMPACT, SH4_NOFPU_INSN_RTS_COMPACT
 , SH4_NOFPU_INSN_SETS_COMPACT, SH4_NOFPU_INSN_SETT_COMPACT, SH4_NOFPU_INSN_SHAD_COMPACT, SH4_NOFPU_INSN_SHAL_COMPACT
 , SH4_NOFPU_INSN_SHAR_COMPACT, SH4_NOFPU_INSN_SHLD_COMPACT, SH4_NOFPU_INSN_SHLL_COMPACT, SH4_NOFPU_INSN_SHLL2_COMPACT
 , SH4_NOFPU_INSN_SHLL8_COMPACT, SH4_NOFPU_INSN_SHLL16_COMPACT, SH4_NOFPU_INSN_SHLR_COMPACT, SH4_NOFPU_INSN_SHLR2_COMPACT
 , SH4_NOFPU_INSN_SHLR8_COMPACT, SH4_NOFPU_INSN_SHLR16_COMPACT, SH4_NOFPU_INSN_STC_GBR_COMPACT, SH4_NOFPU_INSN_STC_VBR_COMPACT
 , SH4_NOFPU_INSN_STCL_GBR_COMPACT, SH4_NOFPU_INSN_STCL_VBR_COMPACT, SH4_NOFPU_INSN_STS_MACH_COMPACT, SH4_NOFPU_INSN_STSL_MACH_COMPACT
 , SH4_NOFPU_INSN_STS_MACL_COMPACT, SH4_NOFPU_INSN_STSL_MACL_COMPACT, SH4_NOFPU_INSN_STS_PR_COMPACT, SH4_NOFPU_INSN_STSL_PR_COMPACT
 , SH4_NOFPU_INSN_SUB_COMPACT, SH4_NOFPU_INSN_SUBC_COMPACT, SH4_NOFPU_INSN_SUBV_COMPACT, SH4_NOFPU_INSN_SWAPB_COMPACT
 , SH4_NOFPU_INSN_SWAPW_COMPACT, SH4_NOFPU_INSN_TASB_COMPACT, SH4_NOFPU_INSN_TRAPA_COMPACT, SH4_NOFPU_INSN_TST_COMPACT
 , SH4_NOFPU_INSN_TSTI_COMPACT, SH4_NOFPU_INSN_TSTB_COMPACT, SH4_NOFPU_INSN_XOR_COMPACT, SH4_NOFPU_INSN_XORI_COMPACT
 , SH4_NOFPU_INSN_XORB_COMPACT, SH4_NOFPU_INSN_XTRCT_COMPACT
} SH4_NOFPU_INSN_TYPE;


// Forward decls.
struct sh4_nofpu_cpu;
struct sh4_nofpu_scache;
typedef void (sh4_nofpu_sem_fn) (sh4_nofpu_cpu* cpu, sh4_nofpu_scache* sem, int tick, sh4_nofpu::write_stacks &buf);


// Instruction descriptor.

struct sh4_nofpu_idesc {

  // scache engine executor for this insn
  sh4_nofpu_sem_fn* execute;

  const char* insn_name;
  enum sh4_nofpu_insn_type sem_index;
  sh_insn_attr attrs;

  // idesc table: indexed by sem_index
  static sh4_nofpu_idesc idesc_table[];

  static sh4_nofpu_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union sh4_nofpu_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    IADDR i_disp12;
  } sfmt_bra_compact;
  struct { /*  */
    IADDR i_disp8;
  } sfmt_bf_compact;
  struct { /*  */
    SI f_imm8x2;
    unsigned char out_r0;
  } sfmt_movw9_compact;
  struct { /*  */
    SI f_imm8x2;
    unsigned char in_r0;
  } sfmt_movw4_compact;
  struct { /*  */
    SI f_imm8x4;
    unsigned char out_r0;
  } sfmt_movl9_compact;
  struct { /*  */
    SI f_imm8x4;
    unsigned char in_r0;
  } sfmt_movl4_compact;
  struct { /*  */
    SI f_imm8x2;
    UINT f_rn;
    unsigned char out_rn;
  } sfmt_movw10_compact;
  struct { /*  */
    SI f_imm8x4;
    UINT f_rn;
    unsigned char out_rn;
  } sfmt_movl10_compact;
  struct { /*  */
    INT f_imm20;
    UINT f_rn;
    unsigned char out_rn;
  } sfmt_movi20_compact;
  struct { /*  */
    UINT f_imm8;
    unsigned char in_r0;
    unsigned char out_r0;
  } sfmt_andi_compact;
  struct { /*  */
    SI f_imm4x2;
    UINT f_rm;
    unsigned char in_rm;
    unsigned char out_r0;
  } sfmt_movw11_compact;
  struct { /*  */
    SI f_imm4x2;
    UINT f_rm;
    unsigned char in_r0;
    unsigned char in_rm;
  } sfmt_movw5_compact;
  struct { /*  */
    UINT f_imm4;
    UINT f_rm;
    unsigned char in_rm;
    unsigned char out_r0;
  } sfmt_movb10_compact;
  struct { /*  */
    UINT f_imm4;
    UINT f_rm;
    unsigned char in_r0;
    unsigned char in_rm;
  } sfmt_movb5_compact;
  struct { /*  */
    UINT f_rn;
    unsigned char in_r0;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_divu_compact;
  struct { /*  */
    UINT f_imm8;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_addi_compact;
  struct { /*  */
    SI f_imm12x4;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
  } sfmt_movl13_compact;
  struct { /*  */
    SI f_imm12x4;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char out_rn;
  } sfmt_movl12_compact;
  struct { /*  */
    SI f_imm4x4;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char out_rn;
  } sfmt_movl11_compact;
  struct { /*  */
    SI f_imm4x4;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
  } sfmt_movl5_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_r0;
    unsigned char in_rm;
    unsigned char out_rn;
  } sfmt_movb8_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_r0;
    unsigned char in_rm;
    unsigned char in_rn;
  } sfmt_movb3_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm64;
    unsigned char in_rn64;
    unsigned char out_rn64;
  } sfmt_and_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_rm;
    unsigned char out_rn;
  } sfmt_macl_compact;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    sh4_nofpu_scache* next;
    sh4_nofpu_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    sh4_nofpu_scache* insn;
  } before;
};

// Simulator instruction cache.

struct sh4_nofpu_scache {
  // executor
  union {
    cgoto_label cgoto;
    sh4_nofpu_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  sh4_nofpu_idesc* idesc;

  // argument buffer
  sh4_nofpu_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
};

} // end sh4_nofpu namespace

// Decls of each semantic fn.

using sh4_nofpu::sh4_nofpu_sem_fn;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_x_invalid;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_add_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_addi_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_addc_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_addv_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_and_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_andi_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_andb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bf_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bfs_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bra_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_braf_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bsr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bsrf_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bt_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_bts_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_clrmac_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_clrs_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_clrt_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmpeq_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmpeqi_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmpge_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmpgt_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmphi_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmphs_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmppl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmppz_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_cmpstr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_div0s_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_div0u_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_div1_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_divu_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_mulr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_dmulsl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_dmulul_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_dt_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_extsb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_extsw_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_extub_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_extuw_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_frchg_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_fschg_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_jmp_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_jsr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldc_gbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldc_vbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldc_sr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldcl_gbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldcl_vbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_lds_mach_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldsl_mach_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_lds_macl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldsl_macl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_lds_pr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ldsl_pr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_macl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_macw_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_mov_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movi_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movi20_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb1_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb2_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb3_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb4_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb5_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb6_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb7_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb8_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb9_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movb10_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl1_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl2_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl3_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl4_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl5_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl6_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl7_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl8_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl9_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl10_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl11_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl12_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movl13_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw1_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw2_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw3_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw4_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw5_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw6_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw7_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw8_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw9_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw10_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movw11_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_mova_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movcal_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_movt_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_mull_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_mulsw_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_muluw_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_neg_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_negc_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_nop_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_not_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ocbi_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ocbp_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ocbwb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_or_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_ori_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_orb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_pref_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_rotcl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_rotcr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_rotl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_rotr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_rts_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_sets_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_sett_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shad_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shal_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shar_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shld_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shll_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shll2_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shll8_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shll16_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shlr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shlr2_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shlr8_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_shlr16_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stc_gbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stc_vbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stcl_gbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stcl_vbr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_sts_mach_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stsl_mach_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_sts_macl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stsl_macl_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_sts_pr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_stsl_pr_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_sub_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_subc_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_subv_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_swapb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_swapw_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_tasb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_trapa_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_tst_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_tsti_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_tstb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_xor_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_xori_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_xorb_compact;
extern sh4_nofpu_sem_fn sh4_nofpu_sem_xtrct_compact;

#endif /* SH4_NOFPU_DECODE_H */
