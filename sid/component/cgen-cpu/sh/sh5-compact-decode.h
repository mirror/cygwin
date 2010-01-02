/* Decode header for sh5_compact.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef SH5_COMPACT_DECODE_H
#define SH5_COMPACT_DECODE_H

namespace sh5_compact {
// forward declaration of struct in -defs.h
struct write_stacks;
}

namespace sh5 {

using namespace cgen;
using namespace sh;

typedef UINT sh5_compact_insn_word;

/* Enum declaration for instructions in cpu family sh5_compact.  */
typedef enum sh5_compact_insn_type {
  SH5_COMPACT_INSN_X_INVALID, SH5_COMPACT_INSN_ADD_COMPACT, SH5_COMPACT_INSN_ADDI_COMPACT, SH5_COMPACT_INSN_ADDC_COMPACT
 , SH5_COMPACT_INSN_ADDV_COMPACT, SH5_COMPACT_INSN_AND_COMPACT, SH5_COMPACT_INSN_ANDI_COMPACT, SH5_COMPACT_INSN_ANDB_COMPACT
 , SH5_COMPACT_INSN_BF_COMPACT, SH5_COMPACT_INSN_BFS_COMPACT, SH5_COMPACT_INSN_BRA_COMPACT, SH5_COMPACT_INSN_BRAF_COMPACT
 , SH5_COMPACT_INSN_BRK_COMPACT, SH5_COMPACT_INSN_BSR_COMPACT, SH5_COMPACT_INSN_BSRF_COMPACT, SH5_COMPACT_INSN_BT_COMPACT
 , SH5_COMPACT_INSN_BTS_COMPACT, SH5_COMPACT_INSN_CLRMAC_COMPACT, SH5_COMPACT_INSN_CLRS_COMPACT, SH5_COMPACT_INSN_CLRT_COMPACT
 , SH5_COMPACT_INSN_CMPEQ_COMPACT, SH5_COMPACT_INSN_CMPEQI_COMPACT, SH5_COMPACT_INSN_CMPGE_COMPACT, SH5_COMPACT_INSN_CMPGT_COMPACT
 , SH5_COMPACT_INSN_CMPHI_COMPACT, SH5_COMPACT_INSN_CMPHS_COMPACT, SH5_COMPACT_INSN_CMPPL_COMPACT, SH5_COMPACT_INSN_CMPPZ_COMPACT
 , SH5_COMPACT_INSN_CMPSTR_COMPACT, SH5_COMPACT_INSN_DIV0S_COMPACT, SH5_COMPACT_INSN_DIV0U_COMPACT, SH5_COMPACT_INSN_DIV1_COMPACT
 , SH5_COMPACT_INSN_DIVU_COMPACT, SH5_COMPACT_INSN_MULR_COMPACT, SH5_COMPACT_INSN_DMULSL_COMPACT, SH5_COMPACT_INSN_DMULUL_COMPACT
 , SH5_COMPACT_INSN_DT_COMPACT, SH5_COMPACT_INSN_EXTSB_COMPACT, SH5_COMPACT_INSN_EXTSW_COMPACT, SH5_COMPACT_INSN_EXTUB_COMPACT
 , SH5_COMPACT_INSN_EXTUW_COMPACT, SH5_COMPACT_INSN_FABS_COMPACT, SH5_COMPACT_INSN_FADD_COMPACT, SH5_COMPACT_INSN_FCMPEQ_COMPACT
 , SH5_COMPACT_INSN_FCMPGT_COMPACT, SH5_COMPACT_INSN_FCNVDS_COMPACT, SH5_COMPACT_INSN_FCNVSD_COMPACT, SH5_COMPACT_INSN_FDIV_COMPACT
 , SH5_COMPACT_INSN_FIPR_COMPACT, SH5_COMPACT_INSN_FLDS_COMPACT, SH5_COMPACT_INSN_FLDI0_COMPACT, SH5_COMPACT_INSN_FLDI1_COMPACT
 , SH5_COMPACT_INSN_FLOAT_COMPACT, SH5_COMPACT_INSN_FMAC_COMPACT, SH5_COMPACT_INSN_FMOV1_COMPACT, SH5_COMPACT_INSN_FMOV2_COMPACT
 , SH5_COMPACT_INSN_FMOV3_COMPACT, SH5_COMPACT_INSN_FMOV4_COMPACT, SH5_COMPACT_INSN_FMOV5_COMPACT, SH5_COMPACT_INSN_FMOV6_COMPACT
 , SH5_COMPACT_INSN_FMOV7_COMPACT, SH5_COMPACT_INSN_FMOV8_COMPACT, SH5_COMPACT_INSN_FMOV9_COMPACT, SH5_COMPACT_INSN_FMUL_COMPACT
 , SH5_COMPACT_INSN_FNEG_COMPACT, SH5_COMPACT_INSN_FRCHG_COMPACT, SH5_COMPACT_INSN_FSCHG_COMPACT, SH5_COMPACT_INSN_FSQRT_COMPACT
 , SH5_COMPACT_INSN_FSTS_COMPACT, SH5_COMPACT_INSN_FSUB_COMPACT, SH5_COMPACT_INSN_FTRC_COMPACT, SH5_COMPACT_INSN_FTRV_COMPACT
 , SH5_COMPACT_INSN_JMP_COMPACT, SH5_COMPACT_INSN_JSR_COMPACT, SH5_COMPACT_INSN_LDC_GBR_COMPACT, SH5_COMPACT_INSN_LDC_VBR_COMPACT
 , SH5_COMPACT_INSN_LDC_SR_COMPACT, SH5_COMPACT_INSN_LDCL_GBR_COMPACT, SH5_COMPACT_INSN_LDCL_VBR_COMPACT, SH5_COMPACT_INSN_LDS_FPSCR_COMPACT
 , SH5_COMPACT_INSN_LDSL_FPSCR_COMPACT, SH5_COMPACT_INSN_LDS_FPUL_COMPACT, SH5_COMPACT_INSN_LDSL_FPUL_COMPACT, SH5_COMPACT_INSN_LDS_MACH_COMPACT
 , SH5_COMPACT_INSN_LDSL_MACH_COMPACT, SH5_COMPACT_INSN_LDS_MACL_COMPACT, SH5_COMPACT_INSN_LDSL_MACL_COMPACT, SH5_COMPACT_INSN_LDS_PR_COMPACT
 , SH5_COMPACT_INSN_LDSL_PR_COMPACT, SH5_COMPACT_INSN_MACL_COMPACT, SH5_COMPACT_INSN_MACW_COMPACT, SH5_COMPACT_INSN_MOV_COMPACT
 , SH5_COMPACT_INSN_MOVI_COMPACT, SH5_COMPACT_INSN_MOVI20_COMPACT, SH5_COMPACT_INSN_MOVB1_COMPACT, SH5_COMPACT_INSN_MOVB2_COMPACT
 , SH5_COMPACT_INSN_MOVB3_COMPACT, SH5_COMPACT_INSN_MOVB4_COMPACT, SH5_COMPACT_INSN_MOVB5_COMPACT, SH5_COMPACT_INSN_MOVB6_COMPACT
 , SH5_COMPACT_INSN_MOVB7_COMPACT, SH5_COMPACT_INSN_MOVB8_COMPACT, SH5_COMPACT_INSN_MOVB9_COMPACT, SH5_COMPACT_INSN_MOVB10_COMPACT
 , SH5_COMPACT_INSN_MOVL1_COMPACT, SH5_COMPACT_INSN_MOVL2_COMPACT, SH5_COMPACT_INSN_MOVL3_COMPACT, SH5_COMPACT_INSN_MOVL4_COMPACT
 , SH5_COMPACT_INSN_MOVL5_COMPACT, SH5_COMPACT_INSN_MOVL6_COMPACT, SH5_COMPACT_INSN_MOVL7_COMPACT, SH5_COMPACT_INSN_MOVL8_COMPACT
 , SH5_COMPACT_INSN_MOVL9_COMPACT, SH5_COMPACT_INSN_MOVL10_COMPACT, SH5_COMPACT_INSN_MOVL11_COMPACT, SH5_COMPACT_INSN_MOVL12_COMPACT
 , SH5_COMPACT_INSN_MOVL13_COMPACT, SH5_COMPACT_INSN_MOVW1_COMPACT, SH5_COMPACT_INSN_MOVW2_COMPACT, SH5_COMPACT_INSN_MOVW3_COMPACT
 , SH5_COMPACT_INSN_MOVW4_COMPACT, SH5_COMPACT_INSN_MOVW5_COMPACT, SH5_COMPACT_INSN_MOVW6_COMPACT, SH5_COMPACT_INSN_MOVW7_COMPACT
 , SH5_COMPACT_INSN_MOVW8_COMPACT, SH5_COMPACT_INSN_MOVW9_COMPACT, SH5_COMPACT_INSN_MOVW10_COMPACT, SH5_COMPACT_INSN_MOVW11_COMPACT
 , SH5_COMPACT_INSN_MOVA_COMPACT, SH5_COMPACT_INSN_MOVCAL_COMPACT, SH5_COMPACT_INSN_MOVCOL_COMPACT, SH5_COMPACT_INSN_MOVT_COMPACT
 , SH5_COMPACT_INSN_MOVUAL_COMPACT, SH5_COMPACT_INSN_MOVUAL2_COMPACT, SH5_COMPACT_INSN_MULL_COMPACT, SH5_COMPACT_INSN_MULSW_COMPACT
 , SH5_COMPACT_INSN_MULUW_COMPACT, SH5_COMPACT_INSN_NEG_COMPACT, SH5_COMPACT_INSN_NEGC_COMPACT, SH5_COMPACT_INSN_NOP_COMPACT
 , SH5_COMPACT_INSN_NOT_COMPACT, SH5_COMPACT_INSN_OCBI_COMPACT, SH5_COMPACT_INSN_OCBP_COMPACT, SH5_COMPACT_INSN_OCBWB_COMPACT
 , SH5_COMPACT_INSN_OR_COMPACT, SH5_COMPACT_INSN_ORI_COMPACT, SH5_COMPACT_INSN_ORB_COMPACT, SH5_COMPACT_INSN_PREF_COMPACT
 , SH5_COMPACT_INSN_ROTCL_COMPACT, SH5_COMPACT_INSN_ROTCR_COMPACT, SH5_COMPACT_INSN_ROTL_COMPACT, SH5_COMPACT_INSN_ROTR_COMPACT
 , SH5_COMPACT_INSN_RTS_COMPACT, SH5_COMPACT_INSN_SETS_COMPACT, SH5_COMPACT_INSN_SETT_COMPACT, SH5_COMPACT_INSN_SHAD_COMPACT
 , SH5_COMPACT_INSN_SHAL_COMPACT, SH5_COMPACT_INSN_SHAR_COMPACT, SH5_COMPACT_INSN_SHLD_COMPACT, SH5_COMPACT_INSN_SHLL_COMPACT
 , SH5_COMPACT_INSN_SHLL2_COMPACT, SH5_COMPACT_INSN_SHLL8_COMPACT, SH5_COMPACT_INSN_SHLL16_COMPACT, SH5_COMPACT_INSN_SHLR_COMPACT
 , SH5_COMPACT_INSN_SHLR2_COMPACT, SH5_COMPACT_INSN_SHLR8_COMPACT, SH5_COMPACT_INSN_SHLR16_COMPACT, SH5_COMPACT_INSN_STC_GBR_COMPACT
 , SH5_COMPACT_INSN_STC_VBR_COMPACT, SH5_COMPACT_INSN_STCL_GBR_COMPACT, SH5_COMPACT_INSN_STCL_VBR_COMPACT, SH5_COMPACT_INSN_STS_FPSCR_COMPACT
 , SH5_COMPACT_INSN_STSL_FPSCR_COMPACT, SH5_COMPACT_INSN_STS_FPUL_COMPACT, SH5_COMPACT_INSN_STSL_FPUL_COMPACT, SH5_COMPACT_INSN_STS_MACH_COMPACT
 , SH5_COMPACT_INSN_STSL_MACH_COMPACT, SH5_COMPACT_INSN_STS_MACL_COMPACT, SH5_COMPACT_INSN_STSL_MACL_COMPACT, SH5_COMPACT_INSN_STS_PR_COMPACT
 , SH5_COMPACT_INSN_STSL_PR_COMPACT, SH5_COMPACT_INSN_SUB_COMPACT, SH5_COMPACT_INSN_SUBC_COMPACT, SH5_COMPACT_INSN_SUBV_COMPACT
 , SH5_COMPACT_INSN_SWAPB_COMPACT, SH5_COMPACT_INSN_SWAPW_COMPACT, SH5_COMPACT_INSN_TASB_COMPACT, SH5_COMPACT_INSN_TRAPA_COMPACT
 , SH5_COMPACT_INSN_TST_COMPACT, SH5_COMPACT_INSN_TSTI_COMPACT, SH5_COMPACT_INSN_TSTB_COMPACT, SH5_COMPACT_INSN_XOR_COMPACT
 , SH5_COMPACT_INSN_XORI_COMPACT, SH5_COMPACT_INSN_XORB_COMPACT, SH5_COMPACT_INSN_XTRCT_COMPACT
} SH5_COMPACT_INSN_TYPE;


// Forward decls.
struct sh5_cpu;
struct sh5_compact_scache;
typedef void (sh5_compact_sem_fn) (sh5_cpu* cpu, sh5_compact_scache* sem, int tick, sh5_compact::write_stacks &buf);


// Instruction descriptor.

struct sh5_compact_idesc {

  // scache engine executor for this insn
  sh5_compact_sem_fn* execute;

  const char* insn_name;
  enum sh5_compact_insn_type sem_index;
  sh_insn_attr attrs;

  // idesc table: indexed by sem_index
  static sh5_compact_idesc idesc_table[];

  static sh5_compact_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union sh5_compact_sem_fields {
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
    SI f_vm;
    SI f_vn;
  } sfmt_fipr_compact;
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
    UINT f_rn;
    unsigned char in_fsdn;
    unsigned char out_fpul;
  } sfmt_ftrc_compact;
  struct { /*  */
    UINT f_rn;
    unsigned char in_fpul;
    unsigned char out_frn;
  } sfmt_fsts_compact;
  struct { /*  */
    UINT f_rn;
    unsigned char in_fpul;
    unsigned char out_fsdn;
  } sfmt_float_compact;
  struct { /*  */
    UINT f_rn;
    unsigned char in_frn;
    unsigned char out_fpul;
  } sfmt_flds_compact;
  struct { /*  */
    SI f_dn;
    unsigned char in_fpul;
    unsigned char out_drn;
  } sfmt_fcnvsd_compact;
  struct { /*  */
    SI f_dn;
    unsigned char in_drn;
    unsigned char out_fpul;
  } sfmt_fcnvds_compact;
  struct { /*  */
    UINT f_imm8;
    unsigned char in_r0;
    unsigned char out_r0;
  } sfmt_andi_compact;
  struct { /*  */
    UINT f_rn;
    unsigned char in_fpul;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_stsl_fpul_compact;
  struct { /*  */
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_r0;
    unsigned char out_rn;
  } sfmt_movual2_compact;
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
    unsigned char in_rn;
    unsigned char out_fpul;
    unsigned char out_rn;
  } sfmt_ldsl_fpul_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_fmovm;
    unsigned char out_fmovn;
  } sfmt_fmov1_compact;
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
    SI f_dm;
    SI f_imm12x8;
    UINT f_rn;
    unsigned char in_drm;
    unsigned char in_rn;
  } sfmt_fmov9_compact;
  struct { /*  */
    SI f_dn;
    SI f_imm12x8;
    UINT f_rm;
    unsigned char in_rm;
    unsigned char out_drn;
  } sfmt_fmov8_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_fmovm;
    unsigned char in_r0;
    unsigned char in_rn;
  } sfmt_fmov7_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_fmovm;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_fmov6_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_r0;
    unsigned char in_rm;
    unsigned char out_fmovn;
  } sfmt_fmov4_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char out_fmovn;
    unsigned char out_rm;
  } sfmt_fmov3_compact;
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_fsdm;
    unsigned char in_fsdn;
    unsigned char out_fsdn;
  } sfmt_fadd_compact;
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
  struct { /*  */
    UINT f_rm;
    UINT f_rn;
    unsigned char in_fr0;
    unsigned char in_frm;
    unsigned char in_frn;
    unsigned char out_frn;
  } sfmt_fmac_compact;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    sh5_compact_scache* next;
    sh5_compact_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    sh5_compact_scache* insn;
  } before;
};

// Simulator instruction cache.

struct sh5_compact_scache {
  // executor
  union {
    cgoto_label cgoto;
    sh5_compact_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  sh5_compact_idesc* idesc;

  // argument buffer
  sh5_compact_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (sh5_cpu* current_cpu, PCADDR pc, sh5_compact_insn_word base_insn, sh5_compact_insn_word entire_insn);
};

} // end sh5 namespace

// Decls of each semantic fn.

using sh5::sh5_compact_sem_fn;
extern sh5_compact_sem_fn sh5_compact_sem_x_invalid;
extern sh5_compact_sem_fn sh5_compact_sem_add_compact;
extern sh5_compact_sem_fn sh5_compact_sem_addi_compact;
extern sh5_compact_sem_fn sh5_compact_sem_addc_compact;
extern sh5_compact_sem_fn sh5_compact_sem_addv_compact;
extern sh5_compact_sem_fn sh5_compact_sem_and_compact;
extern sh5_compact_sem_fn sh5_compact_sem_andi_compact;
extern sh5_compact_sem_fn sh5_compact_sem_andb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bf_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bfs_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bra_compact;
extern sh5_compact_sem_fn sh5_compact_sem_braf_compact;
extern sh5_compact_sem_fn sh5_compact_sem_brk_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bsr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bsrf_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_bts_compact;
extern sh5_compact_sem_fn sh5_compact_sem_clrmac_compact;
extern sh5_compact_sem_fn sh5_compact_sem_clrs_compact;
extern sh5_compact_sem_fn sh5_compact_sem_clrt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmpeq_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmpeqi_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmpge_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmpgt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmphi_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmphs_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmppl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmppz_compact;
extern sh5_compact_sem_fn sh5_compact_sem_cmpstr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_div0s_compact;
extern sh5_compact_sem_fn sh5_compact_sem_div0u_compact;
extern sh5_compact_sem_fn sh5_compact_sem_div1_compact;
extern sh5_compact_sem_fn sh5_compact_sem_divu_compact;
extern sh5_compact_sem_fn sh5_compact_sem_mulr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_dmulsl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_dmulul_compact;
extern sh5_compact_sem_fn sh5_compact_sem_dt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_extsb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_extsw_compact;
extern sh5_compact_sem_fn sh5_compact_sem_extub_compact;
extern sh5_compact_sem_fn sh5_compact_sem_extuw_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fabs_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fadd_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fcmpeq_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fcmpgt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fcnvds_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fcnvsd_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fdiv_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fipr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_flds_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fldi0_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fldi1_compact;
extern sh5_compact_sem_fn sh5_compact_sem_float_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmac_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov1_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov3_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov4_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov5_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov6_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov7_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov8_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmov9_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fmul_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fneg_compact;
extern sh5_compact_sem_fn sh5_compact_sem_frchg_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fschg_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fsqrt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fsts_compact;
extern sh5_compact_sem_fn sh5_compact_sem_fsub_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ftrc_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ftrv_compact;
extern sh5_compact_sem_fn sh5_compact_sem_jmp_compact;
extern sh5_compact_sem_fn sh5_compact_sem_jsr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldc_gbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldc_vbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldc_sr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldcl_gbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldcl_vbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_lds_fpscr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldsl_fpscr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_lds_fpul_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldsl_fpul_compact;
extern sh5_compact_sem_fn sh5_compact_sem_lds_mach_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldsl_mach_compact;
extern sh5_compact_sem_fn sh5_compact_sem_lds_macl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldsl_macl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_lds_pr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ldsl_pr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_macl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_macw_compact;
extern sh5_compact_sem_fn sh5_compact_sem_mov_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movi_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movi20_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb1_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb3_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb4_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb5_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb6_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb7_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb8_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb9_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movb10_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl1_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl3_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl4_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl5_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl6_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl7_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl8_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl9_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl10_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl11_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl12_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movl13_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw1_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw3_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw4_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw5_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw6_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw7_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw8_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw9_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw10_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movw11_compact;
extern sh5_compact_sem_fn sh5_compact_sem_mova_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movcal_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movcol_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movt_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movual_compact;
extern sh5_compact_sem_fn sh5_compact_sem_movual2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_mull_compact;
extern sh5_compact_sem_fn sh5_compact_sem_mulsw_compact;
extern sh5_compact_sem_fn sh5_compact_sem_muluw_compact;
extern sh5_compact_sem_fn sh5_compact_sem_neg_compact;
extern sh5_compact_sem_fn sh5_compact_sem_negc_compact;
extern sh5_compact_sem_fn sh5_compact_sem_nop_compact;
extern sh5_compact_sem_fn sh5_compact_sem_not_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ocbi_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ocbp_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ocbwb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_or_compact;
extern sh5_compact_sem_fn sh5_compact_sem_ori_compact;
extern sh5_compact_sem_fn sh5_compact_sem_orb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_pref_compact;
extern sh5_compact_sem_fn sh5_compact_sem_rotcl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_rotcr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_rotl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_rotr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_rts_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sets_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sett_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shad_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shal_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shar_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shld_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shll_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shll2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shll8_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shll16_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shlr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shlr2_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shlr8_compact;
extern sh5_compact_sem_fn sh5_compact_sem_shlr16_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stc_gbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stc_vbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stcl_gbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stcl_vbr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sts_fpscr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stsl_fpscr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sts_fpul_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stsl_fpul_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sts_mach_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stsl_mach_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sts_macl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stsl_macl_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sts_pr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_stsl_pr_compact;
extern sh5_compact_sem_fn sh5_compact_sem_sub_compact;
extern sh5_compact_sem_fn sh5_compact_sem_subc_compact;
extern sh5_compact_sem_fn sh5_compact_sem_subv_compact;
extern sh5_compact_sem_fn sh5_compact_sem_swapb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_swapw_compact;
extern sh5_compact_sem_fn sh5_compact_sem_tasb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_trapa_compact;
extern sh5_compact_sem_fn sh5_compact_sem_tst_compact;
extern sh5_compact_sem_fn sh5_compact_sem_tsti_compact;
extern sh5_compact_sem_fn sh5_compact_sem_tstb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_xor_compact;
extern sh5_compact_sem_fn sh5_compact_sem_xori_compact;
extern sh5_compact_sem_fn sh5_compact_sem_xorb_compact;
extern sh5_compact_sem_fn sh5_compact_sem_xtrct_compact;

#endif /* SH5_COMPACT_DECODE_H */
