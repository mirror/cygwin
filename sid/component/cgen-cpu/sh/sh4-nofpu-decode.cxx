/* Simulator instruction decoder for sh4_nofpu.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh4_nofpu.h"

using namespace sh4_nofpu; // FIXME: namespace organization still wip


// The instruction descriptor array. 

sh4_nofpu_idesc sh4_nofpu_idesc::idesc_table[SH4_NOFPU_INSN_XTRCT_COMPACT + 1] =
{
  { sh4_nofpu_sem_x_invalid, "X_INVALID", SH4_NOFPU_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_add_compact, "ADD_COMPACT", SH4_NOFPU_INSN_ADD_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_addi_compact, "ADDI_COMPACT", SH4_NOFPU_INSN_ADDI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_addc_compact, "ADDC_COMPACT", SH4_NOFPU_INSN_ADDC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_addv_compact, "ADDV_COMPACT", SH4_NOFPU_INSN_ADDV_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_and_compact, "AND_COMPACT", SH4_NOFPU_INSN_AND_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_andi_compact, "ANDI_COMPACT", SH4_NOFPU_INSN_ANDI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_andb_compact, "ANDB_COMPACT", SH4_NOFPU_INSN_ANDB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_bf_compact, "BF_COMPACT", SH4_NOFPU_INSN_BF_COMPACT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_bfs_compact, "BFS_COMPACT", SH4_NOFPU_INSN_BFS_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_bra_compact, "BRA_COMPACT", SH4_NOFPU_INSN_BRA_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_braf_compact, "BRAF_COMPACT", SH4_NOFPU_INSN_BRAF_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_bsr_compact, "BSR_COMPACT", SH4_NOFPU_INSN_BSR_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_bsrf_compact, "BSRF_COMPACT", SH4_NOFPU_INSN_BSRF_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_bt_compact, "BT_COMPACT", SH4_NOFPU_INSN_BT_COMPACT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_bts_compact, "BTS_COMPACT", SH4_NOFPU_INSN_BTS_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_clrmac_compact, "CLRMAC_COMPACT", SH4_NOFPU_INSN_CLRMAC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_clrs_compact, "CLRS_COMPACT", SH4_NOFPU_INSN_CLRS_COMPACT, { 0, (1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_clrt_compact, "CLRT_COMPACT", SH4_NOFPU_INSN_CLRT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmpeq_compact, "CMPEQ_COMPACT", SH4_NOFPU_INSN_CMPEQ_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmpeqi_compact, "CMPEQI_COMPACT", SH4_NOFPU_INSN_CMPEQI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmpge_compact, "CMPGE_COMPACT", SH4_NOFPU_INSN_CMPGE_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmpgt_compact, "CMPGT_COMPACT", SH4_NOFPU_INSN_CMPGT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmphi_compact, "CMPHI_COMPACT", SH4_NOFPU_INSN_CMPHI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmphs_compact, "CMPHS_COMPACT", SH4_NOFPU_INSN_CMPHS_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmppl_compact, "CMPPL_COMPACT", SH4_NOFPU_INSN_CMPPL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmppz_compact, "CMPPZ_COMPACT", SH4_NOFPU_INSN_CMPPZ_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_cmpstr_compact, "CMPSTR_COMPACT", SH4_NOFPU_INSN_CMPSTR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_div0s_compact, "DIV0S_COMPACT", SH4_NOFPU_INSN_DIV0S_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_div0u_compact, "DIV0U_COMPACT", SH4_NOFPU_INSN_DIV0U_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_div1_compact, "DIV1_COMPACT", SH4_NOFPU_INSN_DIV1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_divu_compact, "DIVU_COMPACT", SH4_NOFPU_INSN_DIVU_COMPACT, { 0, (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_mulr_compact, "MULR_COMPACT", SH4_NOFPU_INSN_MULR_COMPACT, { 0, (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_dmulsl_compact, "DMULSL_COMPACT", SH4_NOFPU_INSN_DMULSL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_dmulul_compact, "DMULUL_COMPACT", SH4_NOFPU_INSN_DMULUL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_dt_compact, "DT_COMPACT", SH4_NOFPU_INSN_DT_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_extsb_compact, "EXTSB_COMPACT", SH4_NOFPU_INSN_EXTSB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_extsw_compact, "EXTSW_COMPACT", SH4_NOFPU_INSN_EXTSW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_extub_compact, "EXTUB_COMPACT", SH4_NOFPU_INSN_EXTUB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_extuw_compact, "EXTUW_COMPACT", SH4_NOFPU_INSN_EXTUW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_frchg_compact, "FRCHG_COMPACT", SH4_NOFPU_INSN_FRCHG_COMPACT, { 0|(1<<CGEN_INSN_FP_INSN), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_FE, SH4A_GROUP_FE } },
  { sh4_nofpu_sem_fschg_compact, "FSCHG_COMPACT", SH4_NOFPU_INSN_FSCHG_COMPACT, { 0|(1<<CGEN_INSN_FP_INSN), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_FE, SH4A_GROUP_FE } },
  { sh4_nofpu_sem_jmp_compact, "JMP_COMPACT", SH4_NOFPU_INSN_JMP_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_jsr_compact, "JSR_COMPACT", SH4_NOFPU_INSN_JSR_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_ldc_gbr_compact, "LDC_GBR_COMPACT", SH4_NOFPU_INSN_LDC_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ldc_vbr_compact, "LDC_VBR_COMPACT", SH4_NOFPU_INSN_LDC_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ldc_sr_compact, "LDC_SR_COMPACT", SH4_NOFPU_INSN_LDC_SR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_ldcl_gbr_compact, "LDCL_GBR_COMPACT", SH4_NOFPU_INSN_LDCL_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ldcl_vbr_compact, "LDCL_VBR_COMPACT", SH4_NOFPU_INSN_LDCL_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_lds_mach_compact, "LDS_MACH_COMPACT", SH4_NOFPU_INSN_LDS_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ldsl_mach_compact, "LDSL_MACH_COMPACT", SH4_NOFPU_INSN_LDSL_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_lds_macl_compact, "LDS_MACL_COMPACT", SH4_NOFPU_INSN_LDS_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ldsl_macl_compact, "LDSL_MACL_COMPACT", SH4_NOFPU_INSN_LDSL_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_lds_pr_compact, "LDS_PR_COMPACT", SH4_NOFPU_INSN_LDS_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ldsl_pr_compact, "LDSL_PR_COMPACT", SH4_NOFPU_INSN_LDSL_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_macl_compact, "MACL_COMPACT", SH4_NOFPU_INSN_MACL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_macw_compact, "MACW_COMPACT", SH4_NOFPU_INSN_MACW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_mov_compact, "MOV_COMPACT", SH4_NOFPU_INSN_MOV_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_MT } },
  { sh4_nofpu_sem_movi_compact, "MOVI_COMPACT", SH4_NOFPU_INSN_MOVI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_MT } },
  { sh4_nofpu_sem_movi20_compact, "MOVI20_COMPACT", SH4_NOFPU_INSN_MOVI20_COMPACT, { 0|(1<<CGEN_INSN_32_BIT_INSN), (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_movb1_compact, "MOVB1_COMPACT", SH4_NOFPU_INSN_MOVB1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb2_compact, "MOVB2_COMPACT", SH4_NOFPU_INSN_MOVB2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb3_compact, "MOVB3_COMPACT", SH4_NOFPU_INSN_MOVB3_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb4_compact, "MOVB4_COMPACT", SH4_NOFPU_INSN_MOVB4_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb5_compact, "MOVB5_COMPACT", SH4_NOFPU_INSN_MOVB5_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb6_compact, "MOVB6_COMPACT", SH4_NOFPU_INSN_MOVB6_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb7_compact, "MOVB7_COMPACT", SH4_NOFPU_INSN_MOVB7_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb8_compact, "MOVB8_COMPACT", SH4_NOFPU_INSN_MOVB8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb9_compact, "MOVB9_COMPACT", SH4_NOFPU_INSN_MOVB9_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movb10_compact, "MOVB10_COMPACT", SH4_NOFPU_INSN_MOVB10_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl1_compact, "MOVL1_COMPACT", SH4_NOFPU_INSN_MOVL1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl2_compact, "MOVL2_COMPACT", SH4_NOFPU_INSN_MOVL2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl3_compact, "MOVL3_COMPACT", SH4_NOFPU_INSN_MOVL3_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl4_compact, "MOVL4_COMPACT", SH4_NOFPU_INSN_MOVL4_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl5_compact, "MOVL5_COMPACT", SH4_NOFPU_INSN_MOVL5_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl6_compact, "MOVL6_COMPACT", SH4_NOFPU_INSN_MOVL6_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl7_compact, "MOVL7_COMPACT", SH4_NOFPU_INSN_MOVL7_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl8_compact, "MOVL8_COMPACT", SH4_NOFPU_INSN_MOVL8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl9_compact, "MOVL9_COMPACT", SH4_NOFPU_INSN_MOVL9_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl10_compact, "MOVL10_COMPACT", SH4_NOFPU_INSN_MOVL10_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl11_compact, "MOVL11_COMPACT", SH4_NOFPU_INSN_MOVL11_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movl12_compact, "MOVL12_COMPACT", SH4_NOFPU_INSN_MOVL12_COMPACT, { 0|(1<<CGEN_INSN_32_BIT_INSN), (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_movl13_compact, "MOVL13_COMPACT", SH4_NOFPU_INSN_MOVL13_COMPACT, { 0|(1<<CGEN_INSN_32_BIT_INSN), (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_movw1_compact, "MOVW1_COMPACT", SH4_NOFPU_INSN_MOVW1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw2_compact, "MOVW2_COMPACT", SH4_NOFPU_INSN_MOVW2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw3_compact, "MOVW3_COMPACT", SH4_NOFPU_INSN_MOVW3_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw4_compact, "MOVW4_COMPACT", SH4_NOFPU_INSN_MOVW4_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw5_compact, "MOVW5_COMPACT", SH4_NOFPU_INSN_MOVW5_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw6_compact, "MOVW6_COMPACT", SH4_NOFPU_INSN_MOVW6_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw7_compact, "MOVW7_COMPACT", SH4_NOFPU_INSN_MOVW7_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw8_compact, "MOVW8_COMPACT", SH4_NOFPU_INSN_MOVW8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw9_compact, "MOVW9_COMPACT", SH4_NOFPU_INSN_MOVW9_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw10_compact, "MOVW10_COMPACT", SH4_NOFPU_INSN_MOVW10_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movw11_compact, "MOVW11_COMPACT", SH4_NOFPU_INSN_MOVW11_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_mova_compact, "MOVA_COMPACT", SH4_NOFPU_INSN_MOVA_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movcal_compact, "MOVCAL_COMPACT", SH4_NOFPU_INSN_MOVCAL_COMPACT, { 0, (1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_movt_compact, "MOVT_COMPACT", SH4_NOFPU_INSN_MOVT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_mull_compact, "MULL_COMPACT", SH4_NOFPU_INSN_MULL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_mulsw_compact, "MULSW_COMPACT", SH4_NOFPU_INSN_MULSW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_muluw_compact, "MULUW_COMPACT", SH4_NOFPU_INSN_MULUW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_neg_compact, "NEG_COMPACT", SH4_NOFPU_INSN_NEG_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_negc_compact, "NEGC_COMPACT", SH4_NOFPU_INSN_NEGC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_nop_compact, "NOP_COMPACT", SH4_NOFPU_INSN_NOP_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_MT } },
  { sh4_nofpu_sem_not_compact, "NOT_COMPACT", SH4_NOFPU_INSN_NOT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_ocbi_compact, "OCBI_COMPACT", SH4_NOFPU_INSN_OCBI_COMPACT, { 0, (1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ocbp_compact, "OCBP_COMPACT", SH4_NOFPU_INSN_OCBP_COMPACT, { 0, (1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_ocbwb_compact, "OCBWB_COMPACT", SH4_NOFPU_INSN_OCBWB_COMPACT, { 0, (1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_or_compact, "OR_COMPACT", SH4_NOFPU_INSN_OR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_ori_compact, "ORI_COMPACT", SH4_NOFPU_INSN_ORI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_orb_compact, "ORB_COMPACT", SH4_NOFPU_INSN_ORB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_pref_compact, "PREF_COMPACT", SH4_NOFPU_INSN_PREF_COMPACT, { 0, (1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_rotcl_compact, "ROTCL_COMPACT", SH4_NOFPU_INSN_ROTCL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_rotcr_compact, "ROTCR_COMPACT", SH4_NOFPU_INSN_ROTCR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_rotl_compact, "ROTL_COMPACT", SH4_NOFPU_INSN_ROTL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_rotr_compact, "ROTR_COMPACT", SH4_NOFPU_INSN_ROTR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_rts_compact, "RTS_COMPACT", SH4_NOFPU_INSN_RTS_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh4_nofpu_sem_sets_compact, "SETS_COMPACT", SH4_NOFPU_INSN_SETS_COMPACT, { 0, (1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_sett_compact, "SETT_COMPACT", SH4_NOFPU_INSN_SETT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shad_compact, "SHAD_COMPACT", SH4_NOFPU_INSN_SHAD_COMPACT, { 0, (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shal_compact, "SHAL_COMPACT", SH4_NOFPU_INSN_SHAL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shar_compact, "SHAR_COMPACT", SH4_NOFPU_INSN_SHAR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shld_compact, "SHLD_COMPACT", SH4_NOFPU_INSN_SHLD_COMPACT, { 0, (1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shll_compact, "SHLL_COMPACT", SH4_NOFPU_INSN_SHLL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shll2_compact, "SHLL2_COMPACT", SH4_NOFPU_INSN_SHLL2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shll8_compact, "SHLL8_COMPACT", SH4_NOFPU_INSN_SHLL8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shll16_compact, "SHLL16_COMPACT", SH4_NOFPU_INSN_SHLL16_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shlr_compact, "SHLR_COMPACT", SH4_NOFPU_INSN_SHLR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shlr2_compact, "SHLR2_COMPACT", SH4_NOFPU_INSN_SHLR2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shlr8_compact, "SHLR8_COMPACT", SH4_NOFPU_INSN_SHLR8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_shlr16_compact, "SHLR16_COMPACT", SH4_NOFPU_INSN_SHLR16_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_stc_gbr_compact, "STC_GBR_COMPACT", SH4_NOFPU_INSN_STC_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_stc_vbr_compact, "STC_VBR_COMPACT", SH4_NOFPU_INSN_STC_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_stcl_gbr_compact, "STCL_GBR_COMPACT", SH4_NOFPU_INSN_STCL_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_stcl_vbr_compact, "STCL_VBR_COMPACT", SH4_NOFPU_INSN_STCL_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh4_nofpu_sem_sts_mach_compact, "STS_MACH_COMPACT", SH4_NOFPU_INSN_STS_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_stsl_mach_compact, "STSL_MACH_COMPACT", SH4_NOFPU_INSN_STSL_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_sts_macl_compact, "STS_MACL_COMPACT", SH4_NOFPU_INSN_STS_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_stsl_macl_compact, "STSL_MACL_COMPACT", SH4_NOFPU_INSN_STSL_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_sts_pr_compact, "STS_PR_COMPACT", SH4_NOFPU_INSN_STS_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_stsl_pr_compact, "STSL_PR_COMPACT", SH4_NOFPU_INSN_STSL_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh4_nofpu_sem_sub_compact, "SUB_COMPACT", SH4_NOFPU_INSN_SUB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_subc_compact, "SUBC_COMPACT", SH4_NOFPU_INSN_SUBC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_subv_compact, "SUBV_COMPACT", SH4_NOFPU_INSN_SUBV_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_swapb_compact, "SWAPB_COMPACT", SH4_NOFPU_INSN_SWAPB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_swapw_compact, "SWAPW_COMPACT", SH4_NOFPU_INSN_SWAPW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_tasb_compact, "TASB_COMPACT", SH4_NOFPU_INSN_TASB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_trapa_compact, "TRAPA_COMPACT", SH4_NOFPU_INSN_TRAPA_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_tst_compact, "TST_COMPACT", SH4_NOFPU_INSN_TST_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_tsti_compact, "TSTI_COMPACT", SH4_NOFPU_INSN_TSTI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_tstb_compact, "TSTB_COMPACT", SH4_NOFPU_INSN_TSTB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_xor_compact, "XOR_COMPACT", SH4_NOFPU_INSN_XOR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_xori_compact, "XORI_COMPACT", SH4_NOFPU_INSN_XORI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh4_nofpu_sem_xorb_compact, "XORB_COMPACT", SH4_NOFPU_INSN_XORB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh4_nofpu_sem_xtrct_compact, "XTRCT_COMPACT", SH4_NOFPU_INSN_XTRCT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },

};

// Given a canonical virtual insn id, return the target specific one.

sh4_nofpu_insn_type
sh4_nofpu_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return SH4_NOFPU_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return SH4_NOFPU_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
sh4_nofpu_extract_sfmt_empty (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_add_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_addi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_addc_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_addv_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_and_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_andi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_andb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_bf_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_bfs_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_bra_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_braf_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_bsr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_bsrf_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_clrmac_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_clrs_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_clrt_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_cmpeq_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_cmpeqi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_cmppl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_div0s_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_div0u_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_div1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_divu_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_dmulsl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_dt_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_extsb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_frchg_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_fschg_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldc_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldc_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldc_sr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldcl_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldcl_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_lds_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldsl_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_lds_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldsl_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_lds_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ldsl_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_macw_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_mov_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movi20_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb2_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb3_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb4_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb5_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb6_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb7_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb8_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb9_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movb10_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl2_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl3_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl4_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl5_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl6_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl7_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl8_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl9_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl10_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl11_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl12_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movl13_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw2_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw3_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw4_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw5_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw6_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw7_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw8_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw9_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw10_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movw11_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_mova_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movcal_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_movt_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_mull_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_negc_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_nop_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_ocbi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_pref_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_rotcl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_rts_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_shad_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stc_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stc_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stcl_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stcl_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_sts_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stsl_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_sts_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stsl_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_sts_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_stsl_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_tasb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_trapa_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_tsti_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);
static void
sh4_nofpu_extract_sfmt_tstb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn);

// Fetch & decode instruction
void
sh4_nofpu_scache::decode (sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn)
{
  /* Result of decoder.  */
  SH4_NOFPU_INSN_TYPE itype;

  {
    sh4_nofpu_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 21) & (15 << 7)) | ((insn >> 17) & (1 << 6)) | ((insn >> 16) & (63 << 0)));
      switch (val)
      {
      case 0 : /* fall through */
      case 16 : /* fall through */
      case 32 : /* fall through */
      case 48 : /* fall through */
      case 64 : /* fall through */
      case 80 : /* fall through */
      case 96 : /* fall through */
      case 112 : itype = SH4_NOFPU_INSN_MOVI20_COMPACT; sh4_nofpu_extract_sfmt_movi20_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x3)
          { itype = SH4_NOFPU_INSN_BSRF_COMPACT; sh4_nofpu_extract_sfmt_bsrf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 : /* fall through */
      case 20 : /* fall through */
      case 36 : /* fall through */
      case 52 : /* fall through */
      case 68 : /* fall through */
      case 84 : /* fall through */
      case 100 : /* fall through */
      case 116 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVB3_COMPACT; sh4_nofpu_extract_sfmt_movb3_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 5 : /* fall through */
      case 21 : /* fall through */
      case 37 : /* fall through */
      case 53 : /* fall through */
      case 69 : /* fall through */
      case 85 : /* fall through */
      case 101 : /* fall through */
      case 117 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW3_COMPACT; sh4_nofpu_extract_sfmt_movw3_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 6 : /* fall through */
      case 22 : /* fall through */
      case 38 : /* fall through */
      case 54 : /* fall through */
      case 70 : /* fall through */
      case 86 : /* fall through */
      case 102 : /* fall through */
      case 118 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL3_COMPACT; sh4_nofpu_extract_sfmt_movl3_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 : /* fall through */
      case 23 : /* fall through */
      case 39 : /* fall through */
      case 55 : /* fall through */
      case 71 : /* fall through */
      case 87 : /* fall through */
      case 103 : /* fall through */
      case 119 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MULL_COMPACT; sh4_nofpu_extract_sfmt_mull_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 :
        {
          unsigned int val = (((insn >> 22) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x8)
              { itype = SH4_NOFPU_INSN_CLRT_COMPACT; sh4_nofpu_extract_sfmt_clrt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x48)
              { itype = SH4_NOFPU_INSN_CLRS_COMPACT; sh4_nofpu_extract_sfmt_clrs_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 9 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x9)
          { itype = SH4_NOFPU_INSN_NOP_COMPACT; sh4_nofpu_extract_sfmt_nop_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 10 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0xa)
          { itype = SH4_NOFPU_INSN_STS_MACH_COMPACT; sh4_nofpu_extract_sfmt_sts_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 11 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0xb)
          { itype = SH4_NOFPU_INSN_RTS_COMPACT; sh4_nofpu_extract_sfmt_rts_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 12 : /* fall through */
      case 28 : /* fall through */
      case 44 : /* fall through */
      case 60 : /* fall through */
      case 76 : /* fall through */
      case 92 : /* fall through */
      case 108 : /* fall through */
      case 124 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVB8_COMPACT; sh4_nofpu_extract_sfmt_movb8_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 13 : /* fall through */
      case 29 : /* fall through */
      case 45 : /* fall through */
      case 61 : /* fall through */
      case 77 : /* fall through */
      case 93 : /* fall through */
      case 109 : /* fall through */
      case 125 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW8_COMPACT; sh4_nofpu_extract_sfmt_movw8_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 14 : /* fall through */
      case 30 : /* fall through */
      case 46 : /* fall through */
      case 62 : /* fall through */
      case 78 : /* fall through */
      case 94 : /* fall through */
      case 110 : /* fall through */
      case 126 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL8_COMPACT; sh4_nofpu_extract_sfmt_movl8_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 15 : /* fall through */
      case 31 : /* fall through */
      case 47 : /* fall through */
      case 63 : /* fall through */
      case 79 : /* fall through */
      case 95 : /* fall through */
      case 111 : /* fall through */
      case 127 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MACL_COMPACT; sh4_nofpu_extract_sfmt_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 18 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x12)
          { itype = SH4_NOFPU_INSN_STC_GBR_COMPACT; sh4_nofpu_extract_sfmt_stc_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 :
        {
          unsigned int val = (((insn >> 22) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x18)
              { itype = SH4_NOFPU_INSN_SETT_COMPACT; sh4_nofpu_extract_sfmt_clrt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x58)
              { itype = SH4_NOFPU_INSN_SETS_COMPACT; sh4_nofpu_extract_sfmt_clrs_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 25 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x19)
          { itype = SH4_NOFPU_INSN_DIV0U_COMPACT; sh4_nofpu_extract_sfmt_div0u_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 26 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x1a)
          { itype = SH4_NOFPU_INSN_STS_MACL_COMPACT; sh4_nofpu_extract_sfmt_sts_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 34 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x22)
          { itype = SH4_NOFPU_INSN_STC_VBR_COMPACT; sh4_nofpu_extract_sfmt_stc_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 35 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x23)
          { itype = SH4_NOFPU_INSN_BRAF_COMPACT; sh4_nofpu_extract_sfmt_braf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 40 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x28)
          { itype = SH4_NOFPU_INSN_CLRMAC_COMPACT; sh4_nofpu_extract_sfmt_clrmac_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 41 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x29)
          { itype = SH4_NOFPU_INSN_MOVT_COMPACT; sh4_nofpu_extract_sfmt_movt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 42 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x2a)
          { itype = SH4_NOFPU_INSN_STS_PR_COMPACT; sh4_nofpu_extract_sfmt_sts_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 67 :
        {
          unsigned int val = (((insn >> 22) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_PREF_COMPACT; sh4_nofpu_extract_sfmt_pref_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVCAL_COMPACT; sh4_nofpu_extract_sfmt_movcal_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 83 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x93)
          { itype = SH4_NOFPU_INSN_OCBI_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 99 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0xa3)
          { itype = SH4_NOFPU_INSN_OCBP_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 115 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0xb3)
          { itype = SH4_NOFPU_INSN_OCBWB_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 128 : /* fall through */
      case 129 : /* fall through */
      case 130 : /* fall through */
      case 131 : /* fall through */
      case 132 : /* fall through */
      case 133 : /* fall through */
      case 134 : /* fall through */
      case 135 : /* fall through */
      case 136 : /* fall through */
      case 137 : /* fall through */
      case 138 : /* fall through */
      case 139 : /* fall through */
      case 140 : /* fall through */
      case 141 : /* fall through */
      case 142 : /* fall through */
      case 143 : /* fall through */
      case 144 : /* fall through */
      case 145 : /* fall through */
      case 146 : /* fall through */
      case 147 : /* fall through */
      case 148 : /* fall through */
      case 149 : /* fall through */
      case 150 : /* fall through */
      case 151 : /* fall through */
      case 152 : /* fall through */
      case 153 : /* fall through */
      case 154 : /* fall through */
      case 155 : /* fall through */
      case 156 : /* fall through */
      case 157 : /* fall through */
      case 158 : /* fall through */
      case 159 : /* fall through */
      case 160 : /* fall through */
      case 161 : /* fall through */
      case 162 : /* fall through */
      case 163 : /* fall through */
      case 164 : /* fall through */
      case 165 : /* fall through */
      case 166 : /* fall through */
      case 167 : /* fall through */
      case 168 : /* fall through */
      case 169 : /* fall through */
      case 170 : /* fall through */
      case 171 : /* fall through */
      case 172 : /* fall through */
      case 173 : /* fall through */
      case 174 : /* fall through */
      case 175 : /* fall through */
      case 176 : /* fall through */
      case 177 : /* fall through */
      case 178 : /* fall through */
      case 179 : /* fall through */
      case 180 : /* fall through */
      case 181 : /* fall through */
      case 182 : /* fall through */
      case 183 : /* fall through */
      case 184 : /* fall through */
      case 185 : /* fall through */
      case 186 : /* fall through */
      case 187 : /* fall through */
      case 188 : /* fall through */
      case 189 : /* fall through */
      case 190 : /* fall through */
      case 191 : /* fall through */
      case 192 : /* fall through */
      case 193 : /* fall through */
      case 194 : /* fall through */
      case 195 : /* fall through */
      case 196 : /* fall through */
      case 197 : /* fall through */
      case 198 : /* fall through */
      case 199 : /* fall through */
      case 200 : /* fall through */
      case 201 : /* fall through */
      case 202 : /* fall through */
      case 203 : /* fall through */
      case 204 : /* fall through */
      case 205 : /* fall through */
      case 206 : /* fall through */
      case 207 : /* fall through */
      case 208 : /* fall through */
      case 209 : /* fall through */
      case 210 : /* fall through */
      case 211 : /* fall through */
      case 212 : /* fall through */
      case 213 : /* fall through */
      case 214 : /* fall through */
      case 215 : /* fall through */
      case 216 : /* fall through */
      case 217 : /* fall through */
      case 218 : /* fall through */
      case 219 : /* fall through */
      case 220 : /* fall through */
      case 221 : /* fall through */
      case 222 : /* fall through */
      case 223 : /* fall through */
      case 224 : /* fall through */
      case 225 : /* fall through */
      case 226 : /* fall through */
      case 227 : /* fall through */
      case 228 : /* fall through */
      case 229 : /* fall through */
      case 230 : /* fall through */
      case 231 : /* fall through */
      case 232 : /* fall through */
      case 233 : /* fall through */
      case 234 : /* fall through */
      case 235 : /* fall through */
      case 236 : /* fall through */
      case 237 : /* fall through */
      case 238 : /* fall through */
      case 239 : /* fall through */
      case 240 : /* fall through */
      case 241 : /* fall through */
      case 242 : /* fall through */
      case 243 : /* fall through */
      case 244 : /* fall through */
      case 245 : /* fall through */
      case 246 : /* fall through */
      case 247 : /* fall through */
      case 248 : /* fall through */
      case 249 : /* fall through */
      case 250 : /* fall through */
      case 251 : /* fall through */
      case 252 : /* fall through */
      case 253 : /* fall through */
      case 254 : /* fall through */
      case 255 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL5_COMPACT; sh4_nofpu_extract_sfmt_movl5_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 256 : /* fall through */
      case 272 : /* fall through */
      case 288 : /* fall through */
      case 304 : /* fall through */
      case 320 : /* fall through */
      case 336 : /* fall through */
      case 352 : /* fall through */
      case 368 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVB1_COMPACT; sh4_nofpu_extract_sfmt_movb1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 257 : /* fall through */
      case 273 : /* fall through */
      case 289 : /* fall through */
      case 305 : /* fall through */
      case 321 : /* fall through */
      case 337 : /* fall through */
      case 353 : /* fall through */
      case 369 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW1_COMPACT; sh4_nofpu_extract_sfmt_movw1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 258 : /* fall through */
      case 274 : /* fall through */
      case 290 : /* fall through */
      case 306 : /* fall through */
      case 322 : /* fall through */
      case 338 : /* fall through */
      case 354 : /* fall through */
      case 370 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL1_COMPACT; sh4_nofpu_extract_sfmt_movl1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 260 : /* fall through */
      case 276 : /* fall through */
      case 292 : /* fall through */
      case 308 : /* fall through */
      case 324 : /* fall through */
      case 340 : /* fall through */
      case 356 : /* fall through */
      case 372 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVB2_COMPACT; sh4_nofpu_extract_sfmt_movb2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 261 : /* fall through */
      case 277 : /* fall through */
      case 293 : /* fall through */
      case 309 : /* fall through */
      case 325 : /* fall through */
      case 341 : /* fall through */
      case 357 : /* fall through */
      case 373 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW2_COMPACT; sh4_nofpu_extract_sfmt_movw2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 262 : /* fall through */
      case 278 : /* fall through */
      case 294 : /* fall through */
      case 310 : /* fall through */
      case 326 : /* fall through */
      case 342 : /* fall through */
      case 358 : /* fall through */
      case 374 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL2_COMPACT; sh4_nofpu_extract_sfmt_movl2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 263 : /* fall through */
      case 279 : /* fall through */
      case 295 : /* fall through */
      case 311 : /* fall through */
      case 327 : /* fall through */
      case 343 : /* fall through */
      case 359 : /* fall through */
      case 375 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_DIV0S_COMPACT; sh4_nofpu_extract_sfmt_div0s_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 264 : /* fall through */
      case 280 : /* fall through */
      case 296 : /* fall through */
      case 312 : /* fall through */
      case 328 : /* fall through */
      case 344 : /* fall through */
      case 360 : /* fall through */
      case 376 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_TST_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 265 : /* fall through */
      case 281 : /* fall through */
      case 297 : /* fall through */
      case 313 : /* fall through */
      case 329 : /* fall through */
      case 345 : /* fall through */
      case 361 : /* fall through */
      case 377 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_AND_COMPACT; sh4_nofpu_extract_sfmt_and_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 266 : /* fall through */
      case 282 : /* fall through */
      case 298 : /* fall through */
      case 314 : /* fall through */
      case 330 : /* fall through */
      case 346 : /* fall through */
      case 362 : /* fall through */
      case 378 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_XOR_COMPACT; sh4_nofpu_extract_sfmt_and_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 267 : /* fall through */
      case 283 : /* fall through */
      case 299 : /* fall through */
      case 315 : /* fall through */
      case 331 : /* fall through */
      case 347 : /* fall through */
      case 363 : /* fall through */
      case 379 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_OR_COMPACT; sh4_nofpu_extract_sfmt_and_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 268 : /* fall through */
      case 284 : /* fall through */
      case 300 : /* fall through */
      case 316 : /* fall through */
      case 332 : /* fall through */
      case 348 : /* fall through */
      case 364 : /* fall through */
      case 380 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_CMPSTR_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 269 : /* fall through */
      case 285 : /* fall through */
      case 301 : /* fall through */
      case 317 : /* fall through */
      case 333 : /* fall through */
      case 349 : /* fall through */
      case 365 : /* fall through */
      case 381 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_XTRCT_COMPACT; sh4_nofpu_extract_sfmt_add_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 270 : /* fall through */
      case 286 : /* fall through */
      case 302 : /* fall through */
      case 318 : /* fall through */
      case 334 : /* fall through */
      case 350 : /* fall through */
      case 366 : /* fall through */
      case 382 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MULUW_COMPACT; sh4_nofpu_extract_sfmt_mull_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 271 : /* fall through */
      case 287 : /* fall through */
      case 303 : /* fall through */
      case 319 : /* fall through */
      case 335 : /* fall through */
      case 351 : /* fall through */
      case 367 : /* fall through */
      case 383 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MULSW_COMPACT; sh4_nofpu_extract_sfmt_mull_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 384 : /* fall through */
      case 400 : /* fall through */
      case 416 : /* fall through */
      case 432 : /* fall through */
      case 448 : /* fall through */
      case 464 : /* fall through */
      case 480 : /* fall through */
      case 496 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_CMPEQ_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 385 : /* fall through */
      case 401 : /* fall through */
      case 417 : /* fall through */
      case 433 : /* fall through */
      case 449 : /* fall through */
      case 465 : /* fall through */
      case 481 : /* fall through */
      case 497 :
        {
          unsigned int val = (((insn >> 14) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00ff000) == 0x30012000)
              { itype = SH4_NOFPU_INSN_MOVL13_COMPACT; sh4_nofpu_extract_sfmt_movl13_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf00ff000) == 0x30016000)
              { itype = SH4_NOFPU_INSN_MOVL12_COMPACT; sh4_nofpu_extract_sfmt_movl12_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 386 : /* fall through */
      case 402 : /* fall through */
      case 418 : /* fall through */
      case 434 : /* fall through */
      case 450 : /* fall through */
      case 466 : /* fall through */
      case 482 : /* fall through */
      case 498 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_CMPHS_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 387 : /* fall through */
      case 403 : /* fall through */
      case 419 : /* fall through */
      case 435 : /* fall through */
      case 451 : /* fall through */
      case 467 : /* fall through */
      case 483 : /* fall through */
      case 499 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_CMPGE_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 388 : /* fall through */
      case 404 : /* fall through */
      case 420 : /* fall through */
      case 436 : /* fall through */
      case 452 : /* fall through */
      case 468 : /* fall through */
      case 484 : /* fall through */
      case 500 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_DIV1_COMPACT; sh4_nofpu_extract_sfmt_div1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 389 : /* fall through */
      case 405 : /* fall through */
      case 421 : /* fall through */
      case 437 : /* fall through */
      case 453 : /* fall through */
      case 469 : /* fall through */
      case 485 : /* fall through */
      case 501 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_DMULUL_COMPACT; sh4_nofpu_extract_sfmt_dmulsl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 390 : /* fall through */
      case 406 : /* fall through */
      case 422 : /* fall through */
      case 438 : /* fall through */
      case 454 : /* fall through */
      case 470 : /* fall through */
      case 486 : /* fall through */
      case 502 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_CMPHI_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 391 : /* fall through */
      case 407 : /* fall through */
      case 423 : /* fall through */
      case 439 : /* fall through */
      case 455 : /* fall through */
      case 471 : /* fall through */
      case 487 : /* fall through */
      case 503 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_CMPGT_COMPACT; sh4_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 392 : /* fall through */
      case 408 : /* fall through */
      case 424 : /* fall through */
      case 440 : /* fall through */
      case 456 : /* fall through */
      case 472 : /* fall through */
      case 488 : /* fall through */
      case 504 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SUB_COMPACT; sh4_nofpu_extract_sfmt_add_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 394 : /* fall through */
      case 410 : /* fall through */
      case 426 : /* fall through */
      case 442 : /* fall through */
      case 458 : /* fall through */
      case 474 : /* fall through */
      case 490 : /* fall through */
      case 506 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SUBC_COMPACT; sh4_nofpu_extract_sfmt_addc_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 395 : /* fall through */
      case 411 : /* fall through */
      case 427 : /* fall through */
      case 443 : /* fall through */
      case 459 : /* fall through */
      case 475 : /* fall through */
      case 491 : /* fall through */
      case 507 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SUBV_COMPACT; sh4_nofpu_extract_sfmt_addv_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 396 : /* fall through */
      case 412 : /* fall through */
      case 428 : /* fall through */
      case 444 : /* fall through */
      case 460 : /* fall through */
      case 476 : /* fall through */
      case 492 : /* fall through */
      case 508 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_ADD_COMPACT; sh4_nofpu_extract_sfmt_add_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 397 : /* fall through */
      case 413 : /* fall through */
      case 429 : /* fall through */
      case 445 : /* fall through */
      case 461 : /* fall through */
      case 477 : /* fall through */
      case 493 : /* fall through */
      case 509 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_DMULSL_COMPACT; sh4_nofpu_extract_sfmt_dmulsl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 398 : /* fall through */
      case 414 : /* fall through */
      case 430 : /* fall through */
      case 446 : /* fall through */
      case 462 : /* fall through */
      case 478 : /* fall through */
      case 494 : /* fall through */
      case 510 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_ADDC_COMPACT; sh4_nofpu_extract_sfmt_addc_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 399 : /* fall through */
      case 415 : /* fall through */
      case 431 : /* fall through */
      case 447 : /* fall through */
      case 463 : /* fall through */
      case 479 : /* fall through */
      case 495 : /* fall through */
      case 511 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_ADDV_COMPACT; sh4_nofpu_extract_sfmt_addv_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 512 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4000)
          { itype = SH4_NOFPU_INSN_SHLL_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 513 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4001)
          { itype = SH4_NOFPU_INSN_SHLR_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 514 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4002)
          { itype = SH4_NOFPU_INSN_STSL_MACH_COMPACT; sh4_nofpu_extract_sfmt_stsl_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 516 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4004)
          { itype = SH4_NOFPU_INSN_ROTL_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 517 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4005)
          { itype = SH4_NOFPU_INSN_ROTR_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 518 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4006)
          { itype = SH4_NOFPU_INSN_LDSL_MACH_COMPACT; sh4_nofpu_extract_sfmt_ldsl_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 520 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4008)
          { itype = SH4_NOFPU_INSN_SHLL2_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 521 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4009)
          { itype = SH4_NOFPU_INSN_SHLR2_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 522 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x400a)
          { itype = SH4_NOFPU_INSN_LDS_MACH_COMPACT; sh4_nofpu_extract_sfmt_lds_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 523 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x400b)
          { itype = SH4_NOFPU_INSN_JSR_COMPACT; sh4_nofpu_extract_sfmt_bsrf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 524 : /* fall through */
      case 540 : /* fall through */
      case 556 : /* fall through */
      case 572 : /* fall through */
      case 588 : /* fall through */
      case 604 : /* fall through */
      case 620 : /* fall through */
      case 636 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SHAD_COMPACT; sh4_nofpu_extract_sfmt_shad_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 525 : /* fall through */
      case 541 : /* fall through */
      case 557 : /* fall through */
      case 573 : /* fall through */
      case 589 : /* fall through */
      case 605 : /* fall through */
      case 621 : /* fall through */
      case 637 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SHLD_COMPACT; sh4_nofpu_extract_sfmt_shad_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 526 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x400e)
          { itype = SH4_NOFPU_INSN_LDC_SR_COMPACT; sh4_nofpu_extract_sfmt_ldc_sr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 527 : /* fall through */
      case 543 : /* fall through */
      case 559 : /* fall through */
      case 575 : /* fall through */
      case 591 : /* fall through */
      case 607 : /* fall through */
      case 623 : /* fall through */
      case 639 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MACW_COMPACT; sh4_nofpu_extract_sfmt_macw_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 528 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4010)
          { itype = SH4_NOFPU_INSN_DT_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 529 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4011)
          { itype = SH4_NOFPU_INSN_CMPPZ_COMPACT; sh4_nofpu_extract_sfmt_cmppl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 530 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4012)
          { itype = SH4_NOFPU_INSN_STSL_MACL_COMPACT; sh4_nofpu_extract_sfmt_stsl_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 531 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4013)
          { itype = SH4_NOFPU_INSN_STCL_GBR_COMPACT; sh4_nofpu_extract_sfmt_stcl_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 533 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4015)
          { itype = SH4_NOFPU_INSN_CMPPL_COMPACT; sh4_nofpu_extract_sfmt_cmppl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 534 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4016)
          { itype = SH4_NOFPU_INSN_LDSL_MACL_COMPACT; sh4_nofpu_extract_sfmt_ldsl_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 535 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4017)
          { itype = SH4_NOFPU_INSN_LDCL_GBR_COMPACT; sh4_nofpu_extract_sfmt_ldcl_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 536 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4018)
          { itype = SH4_NOFPU_INSN_SHLL8_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 537 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4019)
          { itype = SH4_NOFPU_INSN_SHLR8_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 538 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x401a)
          { itype = SH4_NOFPU_INSN_LDS_MACL_COMPACT; sh4_nofpu_extract_sfmt_lds_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 539 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x401b)
          { itype = SH4_NOFPU_INSN_TASB_COMPACT; sh4_nofpu_extract_sfmt_tasb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 542 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x401e)
          { itype = SH4_NOFPU_INSN_LDC_GBR_COMPACT; sh4_nofpu_extract_sfmt_ldc_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 544 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4020)
          { itype = SH4_NOFPU_INSN_SHAL_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 545 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4021)
          { itype = SH4_NOFPU_INSN_SHAR_COMPACT; sh4_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 546 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4022)
          { itype = SH4_NOFPU_INSN_STSL_PR_COMPACT; sh4_nofpu_extract_sfmt_stsl_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 547 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4023)
          { itype = SH4_NOFPU_INSN_STCL_VBR_COMPACT; sh4_nofpu_extract_sfmt_stcl_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 548 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4024)
          { itype = SH4_NOFPU_INSN_ROTCL_COMPACT; sh4_nofpu_extract_sfmt_rotcl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 549 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4025)
          { itype = SH4_NOFPU_INSN_ROTCR_COMPACT; sh4_nofpu_extract_sfmt_rotcl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 550 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4026)
          { itype = SH4_NOFPU_INSN_LDSL_PR_COMPACT; sh4_nofpu_extract_sfmt_ldsl_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 551 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4027)
          { itype = SH4_NOFPU_INSN_LDCL_VBR_COMPACT; sh4_nofpu_extract_sfmt_ldcl_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 552 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4028)
          { itype = SH4_NOFPU_INSN_SHLL16_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 553 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4029)
          { itype = SH4_NOFPU_INSN_SHLR16_COMPACT; sh4_nofpu_extract_sfmt_ocbi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 554 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x402a)
          { itype = SH4_NOFPU_INSN_LDS_PR_COMPACT; sh4_nofpu_extract_sfmt_lds_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 555 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x402b)
          { itype = SH4_NOFPU_INSN_JMP_COMPACT; sh4_nofpu_extract_sfmt_braf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 558 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x402e)
          { itype = SH4_NOFPU_INSN_LDC_VBR_COMPACT; sh4_nofpu_extract_sfmt_ldc_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 576 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4080)
          { itype = SH4_NOFPU_INSN_MULR_COMPACT; sh4_nofpu_extract_sfmt_divu_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 580 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4084)
          { itype = SH4_NOFPU_INSN_DIVU_COMPACT; sh4_nofpu_extract_sfmt_divu_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 640 : /* fall through */
      case 641 : /* fall through */
      case 642 : /* fall through */
      case 643 : /* fall through */
      case 644 : /* fall through */
      case 645 : /* fall through */
      case 646 : /* fall through */
      case 647 : /* fall through */
      case 648 : /* fall through */
      case 649 : /* fall through */
      case 650 : /* fall through */
      case 651 : /* fall through */
      case 652 : /* fall through */
      case 653 : /* fall through */
      case 654 : /* fall through */
      case 655 : /* fall through */
      case 656 : /* fall through */
      case 657 : /* fall through */
      case 658 : /* fall through */
      case 659 : /* fall through */
      case 660 : /* fall through */
      case 661 : /* fall through */
      case 662 : /* fall through */
      case 663 : /* fall through */
      case 664 : /* fall through */
      case 665 : /* fall through */
      case 666 : /* fall through */
      case 667 : /* fall through */
      case 668 : /* fall through */
      case 669 : /* fall through */
      case 670 : /* fall through */
      case 671 : /* fall through */
      case 672 : /* fall through */
      case 673 : /* fall through */
      case 674 : /* fall through */
      case 675 : /* fall through */
      case 676 : /* fall through */
      case 677 : /* fall through */
      case 678 : /* fall through */
      case 679 : /* fall through */
      case 680 : /* fall through */
      case 681 : /* fall through */
      case 682 : /* fall through */
      case 683 : /* fall through */
      case 684 : /* fall through */
      case 685 : /* fall through */
      case 686 : /* fall through */
      case 687 : /* fall through */
      case 688 : /* fall through */
      case 689 : /* fall through */
      case 690 : /* fall through */
      case 691 : /* fall through */
      case 692 : /* fall through */
      case 693 : /* fall through */
      case 694 : /* fall through */
      case 695 : /* fall through */
      case 696 : /* fall through */
      case 697 : /* fall through */
      case 698 : /* fall through */
      case 699 : /* fall through */
      case 700 : /* fall through */
      case 701 : /* fall through */
      case 702 : /* fall through */
      case 703 : /* fall through */
      case 704 : /* fall through */
      case 705 : /* fall through */
      case 706 : /* fall through */
      case 707 : /* fall through */
      case 708 : /* fall through */
      case 709 : /* fall through */
      case 710 : /* fall through */
      case 711 : /* fall through */
      case 712 : /* fall through */
      case 713 : /* fall through */
      case 714 : /* fall through */
      case 715 : /* fall through */
      case 716 : /* fall through */
      case 717 : /* fall through */
      case 718 : /* fall through */
      case 719 : /* fall through */
      case 720 : /* fall through */
      case 721 : /* fall through */
      case 722 : /* fall through */
      case 723 : /* fall through */
      case 724 : /* fall through */
      case 725 : /* fall through */
      case 726 : /* fall through */
      case 727 : /* fall through */
      case 728 : /* fall through */
      case 729 : /* fall through */
      case 730 : /* fall through */
      case 731 : /* fall through */
      case 732 : /* fall through */
      case 733 : /* fall through */
      case 734 : /* fall through */
      case 735 : /* fall through */
      case 736 : /* fall through */
      case 737 : /* fall through */
      case 738 : /* fall through */
      case 739 : /* fall through */
      case 740 : /* fall through */
      case 741 : /* fall through */
      case 742 : /* fall through */
      case 743 : /* fall through */
      case 744 : /* fall through */
      case 745 : /* fall through */
      case 746 : /* fall through */
      case 747 : /* fall through */
      case 748 : /* fall through */
      case 749 : /* fall through */
      case 750 : /* fall through */
      case 751 : /* fall through */
      case 752 : /* fall through */
      case 753 : /* fall through */
      case 754 : /* fall through */
      case 755 : /* fall through */
      case 756 : /* fall through */
      case 757 : /* fall through */
      case 758 : /* fall through */
      case 759 : /* fall through */
      case 760 : /* fall through */
      case 761 : /* fall through */
      case 762 : /* fall through */
      case 763 : /* fall through */
      case 764 : /* fall through */
      case 765 : /* fall through */
      case 766 : /* fall through */
      case 767 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL11_COMPACT; sh4_nofpu_extract_sfmt_movl11_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 768 : /* fall through */
      case 784 : /* fall through */
      case 800 : /* fall through */
      case 816 : /* fall through */
      case 832 : /* fall through */
      case 848 : /* fall through */
      case 864 : /* fall through */
      case 880 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVB6_COMPACT; sh4_nofpu_extract_sfmt_movb6_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 769 : /* fall through */
      case 785 : /* fall through */
      case 801 : /* fall through */
      case 817 : /* fall through */
      case 833 : /* fall through */
      case 849 : /* fall through */
      case 865 : /* fall through */
      case 881 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW6_COMPACT; sh4_nofpu_extract_sfmt_movw6_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 770 : /* fall through */
      case 786 : /* fall through */
      case 802 : /* fall through */
      case 818 : /* fall through */
      case 834 : /* fall through */
      case 850 : /* fall through */
      case 866 : /* fall through */
      case 882 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL6_COMPACT; sh4_nofpu_extract_sfmt_movl6_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 771 : /* fall through */
      case 787 : /* fall through */
      case 803 : /* fall through */
      case 819 : /* fall through */
      case 835 : /* fall through */
      case 851 : /* fall through */
      case 867 : /* fall through */
      case 883 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOV_COMPACT; sh4_nofpu_extract_sfmt_mov_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 772 : /* fall through */
      case 788 : /* fall through */
      case 804 : /* fall through */
      case 820 : /* fall through */
      case 836 : /* fall through */
      case 852 : /* fall through */
      case 868 : /* fall through */
      case 884 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVB7_COMPACT; sh4_nofpu_extract_sfmt_movb7_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 773 : /* fall through */
      case 789 : /* fall through */
      case 805 : /* fall through */
      case 821 : /* fall through */
      case 837 : /* fall through */
      case 853 : /* fall through */
      case 869 : /* fall through */
      case 885 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW7_COMPACT; sh4_nofpu_extract_sfmt_movw7_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 774 : /* fall through */
      case 790 : /* fall through */
      case 806 : /* fall through */
      case 822 : /* fall through */
      case 838 : /* fall through */
      case 854 : /* fall through */
      case 870 : /* fall through */
      case 886 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL7_COMPACT; sh4_nofpu_extract_sfmt_movl7_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 775 : /* fall through */
      case 791 : /* fall through */
      case 807 : /* fall through */
      case 823 : /* fall through */
      case 839 : /* fall through */
      case 855 : /* fall through */
      case 871 : /* fall through */
      case 887 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_NOT_COMPACT; sh4_nofpu_extract_sfmt_mov_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 776 : /* fall through */
      case 792 : /* fall through */
      case 808 : /* fall through */
      case 824 : /* fall through */
      case 840 : /* fall through */
      case 856 : /* fall through */
      case 872 : /* fall through */
      case 888 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SWAPB_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 777 : /* fall through */
      case 793 : /* fall through */
      case 809 : /* fall through */
      case 825 : /* fall through */
      case 841 : /* fall through */
      case 857 : /* fall through */
      case 873 : /* fall through */
      case 889 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_SWAPW_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 778 : /* fall through */
      case 794 : /* fall through */
      case 810 : /* fall through */
      case 826 : /* fall through */
      case 842 : /* fall through */
      case 858 : /* fall through */
      case 874 : /* fall through */
      case 890 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_NEGC_COMPACT; sh4_nofpu_extract_sfmt_negc_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 779 : /* fall through */
      case 795 : /* fall through */
      case 811 : /* fall through */
      case 827 : /* fall through */
      case 843 : /* fall through */
      case 859 : /* fall through */
      case 875 : /* fall through */
      case 891 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_NEG_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 780 : /* fall through */
      case 796 : /* fall through */
      case 812 : /* fall through */
      case 828 : /* fall through */
      case 844 : /* fall through */
      case 860 : /* fall through */
      case 876 : /* fall through */
      case 892 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_EXTUB_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 781 : /* fall through */
      case 797 : /* fall through */
      case 813 : /* fall through */
      case 829 : /* fall through */
      case 845 : /* fall through */
      case 861 : /* fall through */
      case 877 : /* fall through */
      case 893 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_EXTUW_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 782 : /* fall through */
      case 798 : /* fall through */
      case 814 : /* fall through */
      case 830 : /* fall through */
      case 846 : /* fall through */
      case 862 : /* fall through */
      case 878 : /* fall through */
      case 894 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_EXTSB_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 783 : /* fall through */
      case 799 : /* fall through */
      case 815 : /* fall through */
      case 831 : /* fall through */
      case 847 : /* fall through */
      case 863 : /* fall through */
      case 879 : /* fall through */
      case 895 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_EXTSW_COMPACT; sh4_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 896 : /* fall through */
      case 897 : /* fall through */
      case 898 : /* fall through */
      case 899 : /* fall through */
      case 900 : /* fall through */
      case 901 : /* fall through */
      case 902 : /* fall through */
      case 903 : /* fall through */
      case 904 : /* fall through */
      case 905 : /* fall through */
      case 906 : /* fall through */
      case 907 : /* fall through */
      case 908 : /* fall through */
      case 909 : /* fall through */
      case 910 : /* fall through */
      case 911 : /* fall through */
      case 912 : /* fall through */
      case 913 : /* fall through */
      case 914 : /* fall through */
      case 915 : /* fall through */
      case 916 : /* fall through */
      case 917 : /* fall through */
      case 918 : /* fall through */
      case 919 : /* fall through */
      case 920 : /* fall through */
      case 921 : /* fall through */
      case 922 : /* fall through */
      case 923 : /* fall through */
      case 924 : /* fall through */
      case 925 : /* fall through */
      case 926 : /* fall through */
      case 927 : /* fall through */
      case 928 : /* fall through */
      case 929 : /* fall through */
      case 930 : /* fall through */
      case 931 : /* fall through */
      case 932 : /* fall through */
      case 933 : /* fall through */
      case 934 : /* fall through */
      case 935 : /* fall through */
      case 936 : /* fall through */
      case 937 : /* fall through */
      case 938 : /* fall through */
      case 939 : /* fall through */
      case 940 : /* fall through */
      case 941 : /* fall through */
      case 942 : /* fall through */
      case 943 : /* fall through */
      case 944 : /* fall through */
      case 945 : /* fall through */
      case 946 : /* fall through */
      case 947 : /* fall through */
      case 948 : /* fall through */
      case 949 : /* fall through */
      case 950 : /* fall through */
      case 951 : /* fall through */
      case 952 : /* fall through */
      case 953 : /* fall through */
      case 954 : /* fall through */
      case 955 : /* fall through */
      case 956 : /* fall through */
      case 957 : /* fall through */
      case 958 : /* fall through */
      case 959 : /* fall through */
      case 960 : /* fall through */
      case 961 : /* fall through */
      case 962 : /* fall through */
      case 963 : /* fall through */
      case 964 : /* fall through */
      case 965 : /* fall through */
      case 966 : /* fall through */
      case 967 : /* fall through */
      case 968 : /* fall through */
      case 969 : /* fall through */
      case 970 : /* fall through */
      case 971 : /* fall through */
      case 972 : /* fall through */
      case 973 : /* fall through */
      case 974 : /* fall through */
      case 975 : /* fall through */
      case 976 : /* fall through */
      case 977 : /* fall through */
      case 978 : /* fall through */
      case 979 : /* fall through */
      case 980 : /* fall through */
      case 981 : /* fall through */
      case 982 : /* fall through */
      case 983 : /* fall through */
      case 984 : /* fall through */
      case 985 : /* fall through */
      case 986 : /* fall through */
      case 987 : /* fall through */
      case 988 : /* fall through */
      case 989 : /* fall through */
      case 990 : /* fall through */
      case 991 : /* fall through */
      case 992 : /* fall through */
      case 993 : /* fall through */
      case 994 : /* fall through */
      case 995 : /* fall through */
      case 996 : /* fall through */
      case 997 : /* fall through */
      case 998 : /* fall through */
      case 999 : /* fall through */
      case 1000 : /* fall through */
      case 1001 : /* fall through */
      case 1002 : /* fall through */
      case 1003 : /* fall through */
      case 1004 : /* fall through */
      case 1005 : /* fall through */
      case 1006 : /* fall through */
      case 1007 : /* fall through */
      case 1008 : /* fall through */
      case 1009 : /* fall through */
      case 1010 : /* fall through */
      case 1011 : /* fall through */
      case 1012 : /* fall through */
      case 1013 : /* fall through */
      case 1014 : /* fall through */
      case 1015 : /* fall through */
      case 1016 : /* fall through */
      case 1017 : /* fall through */
      case 1018 : /* fall through */
      case 1019 : /* fall through */
      case 1020 : /* fall through */
      case 1021 : /* fall through */
      case 1022 : /* fall through */
      case 1023 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_ADDI_COMPACT; sh4_nofpu_extract_sfmt_addi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1024 : /* fall through */
      case 1025 : /* fall through */
      case 1026 : /* fall through */
      case 1027 : /* fall through */
      case 1028 : /* fall through */
      case 1029 : /* fall through */
      case 1030 : /* fall through */
      case 1031 : /* fall through */
      case 1032 : /* fall through */
      case 1033 : /* fall through */
      case 1034 : /* fall through */
      case 1035 : /* fall through */
      case 1036 : /* fall through */
      case 1037 : /* fall through */
      case 1038 : /* fall through */
      case 1039 : /* fall through */
      case 1040 : /* fall through */
      case 1041 : /* fall through */
      case 1042 : /* fall through */
      case 1043 : /* fall through */
      case 1044 : /* fall through */
      case 1045 : /* fall through */
      case 1046 : /* fall through */
      case 1047 : /* fall through */
      case 1048 : /* fall through */
      case 1049 : /* fall through */
      case 1050 : /* fall through */
      case 1051 : /* fall through */
      case 1052 : /* fall through */
      case 1053 : /* fall through */
      case 1054 : /* fall through */
      case 1055 : /* fall through */
      case 1056 : /* fall through */
      case 1057 : /* fall through */
      case 1058 : /* fall through */
      case 1059 : /* fall through */
      case 1060 : /* fall through */
      case 1061 : /* fall through */
      case 1062 : /* fall through */
      case 1063 : /* fall through */
      case 1064 : /* fall through */
      case 1065 : /* fall through */
      case 1066 : /* fall through */
      case 1067 : /* fall through */
      case 1068 : /* fall through */
      case 1069 : /* fall through */
      case 1070 : /* fall through */
      case 1071 : /* fall through */
      case 1072 : /* fall through */
      case 1073 : /* fall through */
      case 1074 : /* fall through */
      case 1075 : /* fall through */
      case 1076 : /* fall through */
      case 1077 : /* fall through */
      case 1078 : /* fall through */
      case 1079 : /* fall through */
      case 1080 : /* fall through */
      case 1081 : /* fall through */
      case 1082 : /* fall through */
      case 1083 : /* fall through */
      case 1084 : /* fall through */
      case 1085 : /* fall through */
      case 1086 : /* fall through */
      case 1087 : /* fall through */
      case 1088 : /* fall through */
      case 1089 : /* fall through */
      case 1090 : /* fall through */
      case 1091 : /* fall through */
      case 1092 : /* fall through */
      case 1093 : /* fall through */
      case 1094 : /* fall through */
      case 1095 : /* fall through */
      case 1096 : /* fall through */
      case 1097 : /* fall through */
      case 1098 : /* fall through */
      case 1099 : /* fall through */
      case 1100 : /* fall through */
      case 1101 : /* fall through */
      case 1102 : /* fall through */
      case 1103 : /* fall through */
      case 1104 : /* fall through */
      case 1105 : /* fall through */
      case 1106 : /* fall through */
      case 1107 : /* fall through */
      case 1108 : /* fall through */
      case 1109 : /* fall through */
      case 1110 : /* fall through */
      case 1111 : /* fall through */
      case 1112 : /* fall through */
      case 1113 : /* fall through */
      case 1114 : /* fall through */
      case 1115 : /* fall through */
      case 1116 : /* fall through */
      case 1117 : /* fall through */
      case 1118 : /* fall through */
      case 1119 : /* fall through */
      case 1120 : /* fall through */
      case 1121 : /* fall through */
      case 1122 : /* fall through */
      case 1123 : /* fall through */
      case 1124 : /* fall through */
      case 1125 : /* fall through */
      case 1126 : /* fall through */
      case 1127 : /* fall through */
      case 1128 : /* fall through */
      case 1129 : /* fall through */
      case 1130 : /* fall through */
      case 1131 : /* fall through */
      case 1132 : /* fall through */
      case 1133 : /* fall through */
      case 1134 : /* fall through */
      case 1135 : /* fall through */
      case 1136 : /* fall through */
      case 1137 : /* fall through */
      case 1138 : /* fall through */
      case 1139 : /* fall through */
      case 1140 : /* fall through */
      case 1141 : /* fall through */
      case 1142 : /* fall through */
      case 1143 : /* fall through */
      case 1144 : /* fall through */
      case 1145 : /* fall through */
      case 1146 : /* fall through */
      case 1147 : /* fall through */
      case 1148 : /* fall through */
      case 1149 : /* fall through */
      case 1150 : /* fall through */
      case 1151 :
        {
          unsigned int val = (((insn >> 24) & (15 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVB5_COMPACT; sh4_nofpu_extract_sfmt_movb5_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVW5_COMPACT; sh4_nofpu_extract_sfmt_movw5_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVB10_COMPACT; sh4_nofpu_extract_sfmt_movb10_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVW11_COMPACT; sh4_nofpu_extract_sfmt_movw11_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_CMPEQI_COMPACT; sh4_nofpu_extract_sfmt_cmpeqi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_BT_COMPACT; sh4_nofpu_extract_sfmt_bf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_BF_COMPACT; sh4_nofpu_extract_sfmt_bf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_BTS_COMPACT; sh4_nofpu_extract_sfmt_bfs_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_BFS_COMPACT; sh4_nofpu_extract_sfmt_bfs_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1152 : /* fall through */
      case 1153 : /* fall through */
      case 1154 : /* fall through */
      case 1155 : /* fall through */
      case 1156 : /* fall through */
      case 1157 : /* fall through */
      case 1158 : /* fall through */
      case 1159 : /* fall through */
      case 1160 : /* fall through */
      case 1161 : /* fall through */
      case 1162 : /* fall through */
      case 1163 : /* fall through */
      case 1164 : /* fall through */
      case 1165 : /* fall through */
      case 1166 : /* fall through */
      case 1167 : /* fall through */
      case 1168 : /* fall through */
      case 1169 : /* fall through */
      case 1170 : /* fall through */
      case 1171 : /* fall through */
      case 1172 : /* fall through */
      case 1173 : /* fall through */
      case 1174 : /* fall through */
      case 1175 : /* fall through */
      case 1176 : /* fall through */
      case 1177 : /* fall through */
      case 1178 : /* fall through */
      case 1179 : /* fall through */
      case 1180 : /* fall through */
      case 1181 : /* fall through */
      case 1182 : /* fall through */
      case 1183 : /* fall through */
      case 1184 : /* fall through */
      case 1185 : /* fall through */
      case 1186 : /* fall through */
      case 1187 : /* fall through */
      case 1188 : /* fall through */
      case 1189 : /* fall through */
      case 1190 : /* fall through */
      case 1191 : /* fall through */
      case 1192 : /* fall through */
      case 1193 : /* fall through */
      case 1194 : /* fall through */
      case 1195 : /* fall through */
      case 1196 : /* fall through */
      case 1197 : /* fall through */
      case 1198 : /* fall through */
      case 1199 : /* fall through */
      case 1200 : /* fall through */
      case 1201 : /* fall through */
      case 1202 : /* fall through */
      case 1203 : /* fall through */
      case 1204 : /* fall through */
      case 1205 : /* fall through */
      case 1206 : /* fall through */
      case 1207 : /* fall through */
      case 1208 : /* fall through */
      case 1209 : /* fall through */
      case 1210 : /* fall through */
      case 1211 : /* fall through */
      case 1212 : /* fall through */
      case 1213 : /* fall through */
      case 1214 : /* fall through */
      case 1215 : /* fall through */
      case 1216 : /* fall through */
      case 1217 : /* fall through */
      case 1218 : /* fall through */
      case 1219 : /* fall through */
      case 1220 : /* fall through */
      case 1221 : /* fall through */
      case 1222 : /* fall through */
      case 1223 : /* fall through */
      case 1224 : /* fall through */
      case 1225 : /* fall through */
      case 1226 : /* fall through */
      case 1227 : /* fall through */
      case 1228 : /* fall through */
      case 1229 : /* fall through */
      case 1230 : /* fall through */
      case 1231 : /* fall through */
      case 1232 : /* fall through */
      case 1233 : /* fall through */
      case 1234 : /* fall through */
      case 1235 : /* fall through */
      case 1236 : /* fall through */
      case 1237 : /* fall through */
      case 1238 : /* fall through */
      case 1239 : /* fall through */
      case 1240 : /* fall through */
      case 1241 : /* fall through */
      case 1242 : /* fall through */
      case 1243 : /* fall through */
      case 1244 : /* fall through */
      case 1245 : /* fall through */
      case 1246 : /* fall through */
      case 1247 : /* fall through */
      case 1248 : /* fall through */
      case 1249 : /* fall through */
      case 1250 : /* fall through */
      case 1251 : /* fall through */
      case 1252 : /* fall through */
      case 1253 : /* fall through */
      case 1254 : /* fall through */
      case 1255 : /* fall through */
      case 1256 : /* fall through */
      case 1257 : /* fall through */
      case 1258 : /* fall through */
      case 1259 : /* fall through */
      case 1260 : /* fall through */
      case 1261 : /* fall through */
      case 1262 : /* fall through */
      case 1263 : /* fall through */
      case 1264 : /* fall through */
      case 1265 : /* fall through */
      case 1266 : /* fall through */
      case 1267 : /* fall through */
      case 1268 : /* fall through */
      case 1269 : /* fall through */
      case 1270 : /* fall through */
      case 1271 : /* fall through */
      case 1272 : /* fall through */
      case 1273 : /* fall through */
      case 1274 : /* fall through */
      case 1275 : /* fall through */
      case 1276 : /* fall through */
      case 1277 : /* fall through */
      case 1278 : /* fall through */
      case 1279 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVW10_COMPACT; sh4_nofpu_extract_sfmt_movw10_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1280 : /* fall through */
      case 1281 : /* fall through */
      case 1282 : /* fall through */
      case 1283 : /* fall through */
      case 1284 : /* fall through */
      case 1285 : /* fall through */
      case 1286 : /* fall through */
      case 1287 : /* fall through */
      case 1288 : /* fall through */
      case 1289 : /* fall through */
      case 1290 : /* fall through */
      case 1291 : /* fall through */
      case 1292 : /* fall through */
      case 1293 : /* fall through */
      case 1294 : /* fall through */
      case 1295 : /* fall through */
      case 1296 : /* fall through */
      case 1297 : /* fall through */
      case 1298 : /* fall through */
      case 1299 : /* fall through */
      case 1300 : /* fall through */
      case 1301 : /* fall through */
      case 1302 : /* fall through */
      case 1303 : /* fall through */
      case 1304 : /* fall through */
      case 1305 : /* fall through */
      case 1306 : /* fall through */
      case 1307 : /* fall through */
      case 1308 : /* fall through */
      case 1309 : /* fall through */
      case 1310 : /* fall through */
      case 1311 : /* fall through */
      case 1312 : /* fall through */
      case 1313 : /* fall through */
      case 1314 : /* fall through */
      case 1315 : /* fall through */
      case 1316 : /* fall through */
      case 1317 : /* fall through */
      case 1318 : /* fall through */
      case 1319 : /* fall through */
      case 1320 : /* fall through */
      case 1321 : /* fall through */
      case 1322 : /* fall through */
      case 1323 : /* fall through */
      case 1324 : /* fall through */
      case 1325 : /* fall through */
      case 1326 : /* fall through */
      case 1327 : /* fall through */
      case 1328 : /* fall through */
      case 1329 : /* fall through */
      case 1330 : /* fall through */
      case 1331 : /* fall through */
      case 1332 : /* fall through */
      case 1333 : /* fall through */
      case 1334 : /* fall through */
      case 1335 : /* fall through */
      case 1336 : /* fall through */
      case 1337 : /* fall through */
      case 1338 : /* fall through */
      case 1339 : /* fall through */
      case 1340 : /* fall through */
      case 1341 : /* fall through */
      case 1342 : /* fall through */
      case 1343 : /* fall through */
      case 1344 : /* fall through */
      case 1345 : /* fall through */
      case 1346 : /* fall through */
      case 1347 : /* fall through */
      case 1348 : /* fall through */
      case 1349 : /* fall through */
      case 1350 : /* fall through */
      case 1351 : /* fall through */
      case 1352 : /* fall through */
      case 1353 : /* fall through */
      case 1354 : /* fall through */
      case 1355 : /* fall through */
      case 1356 : /* fall through */
      case 1357 : /* fall through */
      case 1358 : /* fall through */
      case 1359 : /* fall through */
      case 1360 : /* fall through */
      case 1361 : /* fall through */
      case 1362 : /* fall through */
      case 1363 : /* fall through */
      case 1364 : /* fall through */
      case 1365 : /* fall through */
      case 1366 : /* fall through */
      case 1367 : /* fall through */
      case 1368 : /* fall through */
      case 1369 : /* fall through */
      case 1370 : /* fall through */
      case 1371 : /* fall through */
      case 1372 : /* fall through */
      case 1373 : /* fall through */
      case 1374 : /* fall through */
      case 1375 : /* fall through */
      case 1376 : /* fall through */
      case 1377 : /* fall through */
      case 1378 : /* fall through */
      case 1379 : /* fall through */
      case 1380 : /* fall through */
      case 1381 : /* fall through */
      case 1382 : /* fall through */
      case 1383 : /* fall through */
      case 1384 : /* fall through */
      case 1385 : /* fall through */
      case 1386 : /* fall through */
      case 1387 : /* fall through */
      case 1388 : /* fall through */
      case 1389 : /* fall through */
      case 1390 : /* fall through */
      case 1391 : /* fall through */
      case 1392 : /* fall through */
      case 1393 : /* fall through */
      case 1394 : /* fall through */
      case 1395 : /* fall through */
      case 1396 : /* fall through */
      case 1397 : /* fall through */
      case 1398 : /* fall through */
      case 1399 : /* fall through */
      case 1400 : /* fall through */
      case 1401 : /* fall through */
      case 1402 : /* fall through */
      case 1403 : /* fall through */
      case 1404 : /* fall through */
      case 1405 : /* fall through */
      case 1406 : /* fall through */
      case 1407 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_BRA_COMPACT; sh4_nofpu_extract_sfmt_bra_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1408 : /* fall through */
      case 1409 : /* fall through */
      case 1410 : /* fall through */
      case 1411 : /* fall through */
      case 1412 : /* fall through */
      case 1413 : /* fall through */
      case 1414 : /* fall through */
      case 1415 : /* fall through */
      case 1416 : /* fall through */
      case 1417 : /* fall through */
      case 1418 : /* fall through */
      case 1419 : /* fall through */
      case 1420 : /* fall through */
      case 1421 : /* fall through */
      case 1422 : /* fall through */
      case 1423 : /* fall through */
      case 1424 : /* fall through */
      case 1425 : /* fall through */
      case 1426 : /* fall through */
      case 1427 : /* fall through */
      case 1428 : /* fall through */
      case 1429 : /* fall through */
      case 1430 : /* fall through */
      case 1431 : /* fall through */
      case 1432 : /* fall through */
      case 1433 : /* fall through */
      case 1434 : /* fall through */
      case 1435 : /* fall through */
      case 1436 : /* fall through */
      case 1437 : /* fall through */
      case 1438 : /* fall through */
      case 1439 : /* fall through */
      case 1440 : /* fall through */
      case 1441 : /* fall through */
      case 1442 : /* fall through */
      case 1443 : /* fall through */
      case 1444 : /* fall through */
      case 1445 : /* fall through */
      case 1446 : /* fall through */
      case 1447 : /* fall through */
      case 1448 : /* fall through */
      case 1449 : /* fall through */
      case 1450 : /* fall through */
      case 1451 : /* fall through */
      case 1452 : /* fall through */
      case 1453 : /* fall through */
      case 1454 : /* fall through */
      case 1455 : /* fall through */
      case 1456 : /* fall through */
      case 1457 : /* fall through */
      case 1458 : /* fall through */
      case 1459 : /* fall through */
      case 1460 : /* fall through */
      case 1461 : /* fall through */
      case 1462 : /* fall through */
      case 1463 : /* fall through */
      case 1464 : /* fall through */
      case 1465 : /* fall through */
      case 1466 : /* fall through */
      case 1467 : /* fall through */
      case 1468 : /* fall through */
      case 1469 : /* fall through */
      case 1470 : /* fall through */
      case 1471 : /* fall through */
      case 1472 : /* fall through */
      case 1473 : /* fall through */
      case 1474 : /* fall through */
      case 1475 : /* fall through */
      case 1476 : /* fall through */
      case 1477 : /* fall through */
      case 1478 : /* fall through */
      case 1479 : /* fall through */
      case 1480 : /* fall through */
      case 1481 : /* fall through */
      case 1482 : /* fall through */
      case 1483 : /* fall through */
      case 1484 : /* fall through */
      case 1485 : /* fall through */
      case 1486 : /* fall through */
      case 1487 : /* fall through */
      case 1488 : /* fall through */
      case 1489 : /* fall through */
      case 1490 : /* fall through */
      case 1491 : /* fall through */
      case 1492 : /* fall through */
      case 1493 : /* fall through */
      case 1494 : /* fall through */
      case 1495 : /* fall through */
      case 1496 : /* fall through */
      case 1497 : /* fall through */
      case 1498 : /* fall through */
      case 1499 : /* fall through */
      case 1500 : /* fall through */
      case 1501 : /* fall through */
      case 1502 : /* fall through */
      case 1503 : /* fall through */
      case 1504 : /* fall through */
      case 1505 : /* fall through */
      case 1506 : /* fall through */
      case 1507 : /* fall through */
      case 1508 : /* fall through */
      case 1509 : /* fall through */
      case 1510 : /* fall through */
      case 1511 : /* fall through */
      case 1512 : /* fall through */
      case 1513 : /* fall through */
      case 1514 : /* fall through */
      case 1515 : /* fall through */
      case 1516 : /* fall through */
      case 1517 : /* fall through */
      case 1518 : /* fall through */
      case 1519 : /* fall through */
      case 1520 : /* fall through */
      case 1521 : /* fall through */
      case 1522 : /* fall through */
      case 1523 : /* fall through */
      case 1524 : /* fall through */
      case 1525 : /* fall through */
      case 1526 : /* fall through */
      case 1527 : /* fall through */
      case 1528 : /* fall through */
      case 1529 : /* fall through */
      case 1530 : /* fall through */
      case 1531 : /* fall through */
      case 1532 : /* fall through */
      case 1533 : /* fall through */
      case 1534 : /* fall through */
      case 1535 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_BSR_COMPACT; sh4_nofpu_extract_sfmt_bsr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1536 : /* fall through */
      case 1537 : /* fall through */
      case 1538 : /* fall through */
      case 1539 : /* fall through */
      case 1540 : /* fall through */
      case 1541 : /* fall through */
      case 1542 : /* fall through */
      case 1543 : /* fall through */
      case 1544 : /* fall through */
      case 1545 : /* fall through */
      case 1546 : /* fall through */
      case 1547 : /* fall through */
      case 1548 : /* fall through */
      case 1549 : /* fall through */
      case 1550 : /* fall through */
      case 1551 : /* fall through */
      case 1552 : /* fall through */
      case 1553 : /* fall through */
      case 1554 : /* fall through */
      case 1555 : /* fall through */
      case 1556 : /* fall through */
      case 1557 : /* fall through */
      case 1558 : /* fall through */
      case 1559 : /* fall through */
      case 1560 : /* fall through */
      case 1561 : /* fall through */
      case 1562 : /* fall through */
      case 1563 : /* fall through */
      case 1564 : /* fall through */
      case 1565 : /* fall through */
      case 1566 : /* fall through */
      case 1567 : /* fall through */
      case 1568 : /* fall through */
      case 1569 : /* fall through */
      case 1570 : /* fall through */
      case 1571 : /* fall through */
      case 1572 : /* fall through */
      case 1573 : /* fall through */
      case 1574 : /* fall through */
      case 1575 : /* fall through */
      case 1576 : /* fall through */
      case 1577 : /* fall through */
      case 1578 : /* fall through */
      case 1579 : /* fall through */
      case 1580 : /* fall through */
      case 1581 : /* fall through */
      case 1582 : /* fall through */
      case 1583 : /* fall through */
      case 1584 : /* fall through */
      case 1585 : /* fall through */
      case 1586 : /* fall through */
      case 1587 : /* fall through */
      case 1588 : /* fall through */
      case 1589 : /* fall through */
      case 1590 : /* fall through */
      case 1591 : /* fall through */
      case 1592 : /* fall through */
      case 1593 : /* fall through */
      case 1594 : /* fall through */
      case 1595 : /* fall through */
      case 1596 : /* fall through */
      case 1597 : /* fall through */
      case 1598 : /* fall through */
      case 1599 : /* fall through */
      case 1600 : /* fall through */
      case 1601 : /* fall through */
      case 1602 : /* fall through */
      case 1603 : /* fall through */
      case 1604 : /* fall through */
      case 1605 : /* fall through */
      case 1606 : /* fall through */
      case 1607 : /* fall through */
      case 1608 : /* fall through */
      case 1609 : /* fall through */
      case 1610 : /* fall through */
      case 1611 : /* fall through */
      case 1612 : /* fall through */
      case 1613 : /* fall through */
      case 1614 : /* fall through */
      case 1615 : /* fall through */
      case 1616 : /* fall through */
      case 1617 : /* fall through */
      case 1618 : /* fall through */
      case 1619 : /* fall through */
      case 1620 : /* fall through */
      case 1621 : /* fall through */
      case 1622 : /* fall through */
      case 1623 : /* fall through */
      case 1624 : /* fall through */
      case 1625 : /* fall through */
      case 1626 : /* fall through */
      case 1627 : /* fall through */
      case 1628 : /* fall through */
      case 1629 : /* fall through */
      case 1630 : /* fall through */
      case 1631 : /* fall through */
      case 1632 : /* fall through */
      case 1633 : /* fall through */
      case 1634 : /* fall through */
      case 1635 : /* fall through */
      case 1636 : /* fall through */
      case 1637 : /* fall through */
      case 1638 : /* fall through */
      case 1639 : /* fall through */
      case 1640 : /* fall through */
      case 1641 : /* fall through */
      case 1642 : /* fall through */
      case 1643 : /* fall through */
      case 1644 : /* fall through */
      case 1645 : /* fall through */
      case 1646 : /* fall through */
      case 1647 : /* fall through */
      case 1648 : /* fall through */
      case 1649 : /* fall through */
      case 1650 : /* fall through */
      case 1651 : /* fall through */
      case 1652 : /* fall through */
      case 1653 : /* fall through */
      case 1654 : /* fall through */
      case 1655 : /* fall through */
      case 1656 : /* fall through */
      case 1657 : /* fall through */
      case 1658 : /* fall through */
      case 1659 : /* fall through */
      case 1660 : /* fall through */
      case 1661 : /* fall through */
      case 1662 : /* fall through */
      case 1663 :
        {
          unsigned int val = (((insn >> 24) & (15 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVB4_COMPACT; sh4_nofpu_extract_sfmt_movb4_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVW4_COMPACT; sh4_nofpu_extract_sfmt_movw4_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVL4_COMPACT; sh4_nofpu_extract_sfmt_movl4_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_TRAPA_COMPACT; sh4_nofpu_extract_sfmt_trapa_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVB9_COMPACT; sh4_nofpu_extract_sfmt_movb9_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVW9_COMPACT; sh4_nofpu_extract_sfmt_movw9_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVL9_COMPACT; sh4_nofpu_extract_sfmt_movl9_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_MOVA_COMPACT; sh4_nofpu_extract_sfmt_mova_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_TSTI_COMPACT; sh4_nofpu_extract_sfmt_tsti_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_ANDI_COMPACT; sh4_nofpu_extract_sfmt_andi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_XORI_COMPACT; sh4_nofpu_extract_sfmt_andi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_ORI_COMPACT; sh4_nofpu_extract_sfmt_andi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_TSTB_COMPACT; sh4_nofpu_extract_sfmt_tstb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_ANDB_COMPACT; sh4_nofpu_extract_sfmt_andb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_XORB_COMPACT; sh4_nofpu_extract_sfmt_andb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = SH4_NOFPU_INSN_ORB_COMPACT; sh4_nofpu_extract_sfmt_andb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1664 : /* fall through */
      case 1665 : /* fall through */
      case 1666 : /* fall through */
      case 1667 : /* fall through */
      case 1668 : /* fall through */
      case 1669 : /* fall through */
      case 1670 : /* fall through */
      case 1671 : /* fall through */
      case 1672 : /* fall through */
      case 1673 : /* fall through */
      case 1674 : /* fall through */
      case 1675 : /* fall through */
      case 1676 : /* fall through */
      case 1677 : /* fall through */
      case 1678 : /* fall through */
      case 1679 : /* fall through */
      case 1680 : /* fall through */
      case 1681 : /* fall through */
      case 1682 : /* fall through */
      case 1683 : /* fall through */
      case 1684 : /* fall through */
      case 1685 : /* fall through */
      case 1686 : /* fall through */
      case 1687 : /* fall through */
      case 1688 : /* fall through */
      case 1689 : /* fall through */
      case 1690 : /* fall through */
      case 1691 : /* fall through */
      case 1692 : /* fall through */
      case 1693 : /* fall through */
      case 1694 : /* fall through */
      case 1695 : /* fall through */
      case 1696 : /* fall through */
      case 1697 : /* fall through */
      case 1698 : /* fall through */
      case 1699 : /* fall through */
      case 1700 : /* fall through */
      case 1701 : /* fall through */
      case 1702 : /* fall through */
      case 1703 : /* fall through */
      case 1704 : /* fall through */
      case 1705 : /* fall through */
      case 1706 : /* fall through */
      case 1707 : /* fall through */
      case 1708 : /* fall through */
      case 1709 : /* fall through */
      case 1710 : /* fall through */
      case 1711 : /* fall through */
      case 1712 : /* fall through */
      case 1713 : /* fall through */
      case 1714 : /* fall through */
      case 1715 : /* fall through */
      case 1716 : /* fall through */
      case 1717 : /* fall through */
      case 1718 : /* fall through */
      case 1719 : /* fall through */
      case 1720 : /* fall through */
      case 1721 : /* fall through */
      case 1722 : /* fall through */
      case 1723 : /* fall through */
      case 1724 : /* fall through */
      case 1725 : /* fall through */
      case 1726 : /* fall through */
      case 1727 : /* fall through */
      case 1728 : /* fall through */
      case 1729 : /* fall through */
      case 1730 : /* fall through */
      case 1731 : /* fall through */
      case 1732 : /* fall through */
      case 1733 : /* fall through */
      case 1734 : /* fall through */
      case 1735 : /* fall through */
      case 1736 : /* fall through */
      case 1737 : /* fall through */
      case 1738 : /* fall through */
      case 1739 : /* fall through */
      case 1740 : /* fall through */
      case 1741 : /* fall through */
      case 1742 : /* fall through */
      case 1743 : /* fall through */
      case 1744 : /* fall through */
      case 1745 : /* fall through */
      case 1746 : /* fall through */
      case 1747 : /* fall through */
      case 1748 : /* fall through */
      case 1749 : /* fall through */
      case 1750 : /* fall through */
      case 1751 : /* fall through */
      case 1752 : /* fall through */
      case 1753 : /* fall through */
      case 1754 : /* fall through */
      case 1755 : /* fall through */
      case 1756 : /* fall through */
      case 1757 : /* fall through */
      case 1758 : /* fall through */
      case 1759 : /* fall through */
      case 1760 : /* fall through */
      case 1761 : /* fall through */
      case 1762 : /* fall through */
      case 1763 : /* fall through */
      case 1764 : /* fall through */
      case 1765 : /* fall through */
      case 1766 : /* fall through */
      case 1767 : /* fall through */
      case 1768 : /* fall through */
      case 1769 : /* fall through */
      case 1770 : /* fall through */
      case 1771 : /* fall through */
      case 1772 : /* fall through */
      case 1773 : /* fall through */
      case 1774 : /* fall through */
      case 1775 : /* fall through */
      case 1776 : /* fall through */
      case 1777 : /* fall through */
      case 1778 : /* fall through */
      case 1779 : /* fall through */
      case 1780 : /* fall through */
      case 1781 : /* fall through */
      case 1782 : /* fall through */
      case 1783 : /* fall through */
      case 1784 : /* fall through */
      case 1785 : /* fall through */
      case 1786 : /* fall through */
      case 1787 : /* fall through */
      case 1788 : /* fall through */
      case 1789 : /* fall through */
      case 1790 : /* fall through */
      case 1791 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVL10_COMPACT; sh4_nofpu_extract_sfmt_movl10_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1792 : /* fall through */
      case 1793 : /* fall through */
      case 1794 : /* fall through */
      case 1795 : /* fall through */
      case 1796 : /* fall through */
      case 1797 : /* fall through */
      case 1798 : /* fall through */
      case 1799 : /* fall through */
      case 1800 : /* fall through */
      case 1801 : /* fall through */
      case 1802 : /* fall through */
      case 1803 : /* fall through */
      case 1804 : /* fall through */
      case 1805 : /* fall through */
      case 1806 : /* fall through */
      case 1807 : /* fall through */
      case 1808 : /* fall through */
      case 1809 : /* fall through */
      case 1810 : /* fall through */
      case 1811 : /* fall through */
      case 1812 : /* fall through */
      case 1813 : /* fall through */
      case 1814 : /* fall through */
      case 1815 : /* fall through */
      case 1816 : /* fall through */
      case 1817 : /* fall through */
      case 1818 : /* fall through */
      case 1819 : /* fall through */
      case 1820 : /* fall through */
      case 1821 : /* fall through */
      case 1822 : /* fall through */
      case 1823 : /* fall through */
      case 1824 : /* fall through */
      case 1825 : /* fall through */
      case 1826 : /* fall through */
      case 1827 : /* fall through */
      case 1828 : /* fall through */
      case 1829 : /* fall through */
      case 1830 : /* fall through */
      case 1831 : /* fall through */
      case 1832 : /* fall through */
      case 1833 : /* fall through */
      case 1834 : /* fall through */
      case 1835 : /* fall through */
      case 1836 : /* fall through */
      case 1837 : /* fall through */
      case 1838 : /* fall through */
      case 1839 : /* fall through */
      case 1840 : /* fall through */
      case 1841 : /* fall through */
      case 1842 : /* fall through */
      case 1843 : /* fall through */
      case 1844 : /* fall through */
      case 1845 : /* fall through */
      case 1846 : /* fall through */
      case 1847 : /* fall through */
      case 1848 : /* fall through */
      case 1849 : /* fall through */
      case 1850 : /* fall through */
      case 1851 : /* fall through */
      case 1852 : /* fall through */
      case 1853 : /* fall through */
      case 1854 : /* fall through */
      case 1855 : /* fall through */
      case 1856 : /* fall through */
      case 1857 : /* fall through */
      case 1858 : /* fall through */
      case 1859 : /* fall through */
      case 1860 : /* fall through */
      case 1861 : /* fall through */
      case 1862 : /* fall through */
      case 1863 : /* fall through */
      case 1864 : /* fall through */
      case 1865 : /* fall through */
      case 1866 : /* fall through */
      case 1867 : /* fall through */
      case 1868 : /* fall through */
      case 1869 : /* fall through */
      case 1870 : /* fall through */
      case 1871 : /* fall through */
      case 1872 : /* fall through */
      case 1873 : /* fall through */
      case 1874 : /* fall through */
      case 1875 : /* fall through */
      case 1876 : /* fall through */
      case 1877 : /* fall through */
      case 1878 : /* fall through */
      case 1879 : /* fall through */
      case 1880 : /* fall through */
      case 1881 : /* fall through */
      case 1882 : /* fall through */
      case 1883 : /* fall through */
      case 1884 : /* fall through */
      case 1885 : /* fall through */
      case 1886 : /* fall through */
      case 1887 : /* fall through */
      case 1888 : /* fall through */
      case 1889 : /* fall through */
      case 1890 : /* fall through */
      case 1891 : /* fall through */
      case 1892 : /* fall through */
      case 1893 : /* fall through */
      case 1894 : /* fall through */
      case 1895 : /* fall through */
      case 1896 : /* fall through */
      case 1897 : /* fall through */
      case 1898 : /* fall through */
      case 1899 : /* fall through */
      case 1900 : /* fall through */
      case 1901 : /* fall through */
      case 1902 : /* fall through */
      case 1903 : /* fall through */
      case 1904 : /* fall through */
      case 1905 : /* fall through */
      case 1906 : /* fall through */
      case 1907 : /* fall through */
      case 1908 : /* fall through */
      case 1909 : /* fall through */
      case 1910 : /* fall through */
      case 1911 : /* fall through */
      case 1912 : /* fall through */
      case 1913 : /* fall through */
      case 1914 : /* fall through */
      case 1915 : /* fall through */
      case 1916 : /* fall through */
      case 1917 : /* fall through */
      case 1918 : /* fall through */
      case 1919 :
        entire_insn = entire_insn >> 16;
        itype = SH4_NOFPU_INSN_MOVI_COMPACT; sh4_nofpu_extract_sfmt_movi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 2045 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xf3fd)
              { itype = SH4_NOFPU_INSN_FSCHG_COMPACT; sh4_nofpu_extract_sfmt_fschg_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xfbfd)
              { itype = SH4_NOFPU_INSN_FRCHG_COMPACT; sh4_nofpu_extract_sfmt_frchg_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      default : itype = SH4_NOFPU_INSN_X_INVALID; sh4_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & sh4_nofpu_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
sh4_nofpu_extract_sfmt_empty (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_empty)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_add_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_addi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi_compact.f
    UINT f_rn;
    UINT f_imm8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addi_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_addc_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addc_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_addv_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addv_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_and_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_and_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm64) = f_rm;
      FLD (in_rn64) = f_rn;
      FLD (out_rn64) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_andi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_andi_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_andb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_andb_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_bf_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bf_compact.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_INT (insn, 16, 8, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp8) = f_disp8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bf_compact)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_bfs_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bf_compact.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_INT (insn, 16, 8, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp8) = f_disp8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bfs_compact)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_bra_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bra_compact.f
    SI f_disp12;

    f_disp12 = ((((EXTRACT_MSB0_INT (insn, 16, 4, 12)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp12) = f_disp12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bra_compact)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_braf_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_braf_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_bsr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bra_compact.f
    SI f_disp12;

    f_disp12 = ((((EXTRACT_MSB0_INT (insn, 16, 4, 12)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp12) = f_disp12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bsr_compact)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_bsrf_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bsrf_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_clrmac_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_clrmac_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_clrs_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_clrs_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_clrt_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_clrt_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_cmpeq_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmpeq_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_cmpeqi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmpeqi_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_cmppl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmppl_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_div0s_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_div0s_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_div0u_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_div0u_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_div1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_div1_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_divu_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_divu_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_dmulsl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_dmulsl_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_dt_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_dt_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_extsb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_extsb_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_frchg_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_frchg_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_fschg_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fschg_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldc_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc_gbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldc_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc_vbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldc_sr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc_sr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldcl_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldcl_gbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldcl_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldcl_vbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_lds_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lds_mach_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldsl_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldsl_mach_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_lds_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lds_macl_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldsl_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldsl_macl_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_lds_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lds_pr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_ldsl_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldsl_pr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_macl_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_macw_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_macw_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_mov_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mov_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm64) = f_rm;
      FLD (out_rn64) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi_compact.f
    UINT f_rn;
    UINT f_imm8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movi_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movi20_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
    UINT f_rn;
    INT f_imm20_hi;
    UINT f_imm20_lo;
    INT f_imm20;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_imm20_hi = EXTRACT_MSB0_INT (insn, 32, 8, 4);
    f_imm20_lo = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_imm20 = ((((f_imm20_hi) << (16))) | (f_imm20_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm20) = f_imm20;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movi20_compact)\t"
        << " f_imm20:0x" << hex << f_imm20 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb1_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb2_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb2_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb3_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb3_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb4_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb4_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb5_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
    UINT f_rm;
    UINT f_imm4;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_imm4 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm4) = f_imm4;
  FLD (f_rm) = f_rm;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb5_compact)\t"
        << " f_imm4:0x" << hex << f_imm4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb6_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb6_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb7_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb7_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb8_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb8_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb9_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb9_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movb10_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
    UINT f_rm;
    UINT f_imm4;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_imm4 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm4) = f_imm4;
  FLD (f_rm) = f_rm;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movb10_compact)\t"
        << " f_imm4:0x" << hex << f_imm4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl1_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl2_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl2_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl3_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl3_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl4_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
    SI f_imm8x4;

    f_imm8x4 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x4) = f_imm8x4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl4_compact)\t"
        << " f_imm8x4:0x" << hex << f_imm8x4 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl5_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
    UINT f_rn;
    UINT f_rm;
    SI f_imm4x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_imm4x4 = ((EXTRACT_MSB0_UINT (insn, 16, 12, 4)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm4x4) = f_imm4x4;
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl5_compact)\t"
        << " f_imm4x4:0x" << hex << f_imm4x4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl6_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl6_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl7_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl7_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl8_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl8_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl9_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
    SI f_imm8x4;

    f_imm8x4 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x4) = f_imm8x4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl9_compact)\t"
        << " f_imm8x4:0x" << hex << f_imm8x4 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl10_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
    UINT f_rn;
    SI f_imm8x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_imm8x4 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x4) = f_imm8x4;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl10_compact)\t"
        << " f_imm8x4:0x" << hex << f_imm8x4 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl11_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
    UINT f_rn;
    UINT f_rm;
    SI f_imm4x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_imm4x4 = ((EXTRACT_MSB0_UINT (insn, 16, 12, 4)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm4x4) = f_imm4x4;
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl11_compact)\t"
        << " f_imm4x4:0x" << hex << f_imm4x4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl12_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;
    SI f_imm12x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_imm12x4 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm12x4) = f_imm12x4;
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl12_compact)\t"
        << " f_imm12x4:0x" << hex << f_imm12x4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movl13_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;
    SI f_imm12x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_imm12x4 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm12x4) = f_imm12x4;
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movl13_compact)\t"
        << " f_imm12x4:0x" << hex << f_imm12x4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw1_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw1_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw2_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw2_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw3_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw3_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw4_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
    SI f_imm8x2;

    f_imm8x2 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x2) = f_imm8x2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw4_compact)\t"
        << " f_imm8x2:0x" << hex << f_imm8x2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw5_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
    UINT f_rm;
    SI f_imm4x2;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_imm4x2 = ((EXTRACT_MSB0_UINT (insn, 16, 12, 4)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm4x2) = f_imm4x2;
  FLD (f_rm) = f_rm;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw5_compact)\t"
        << " f_imm4x2:0x" << hex << f_imm4x2 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw6_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw6_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw7_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw7_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw8_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw8_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw9_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
    SI f_imm8x2;

    f_imm8x2 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x2) = f_imm8x2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw9_compact)\t"
        << " f_imm8x2:0x" << hex << f_imm8x2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw10_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;
    SI f_imm8x2;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_imm8x2 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x2) = f_imm8x2;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw10_compact)\t"
        << " f_imm8x2:0x" << hex << f_imm8x2 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movw11_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
    UINT f_rm;
    SI f_imm4x2;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_imm4x2 = ((EXTRACT_MSB0_UINT (insn, 16, 12, 4)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm4x2) = f_imm4x2;
  FLD (f_rm) = f_rm;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movw11_compact)\t"
        << " f_imm4x2:0x" << hex << f_imm4x2 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_mova_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
    SI f_imm8x4;

    f_imm8x4 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8x4) = f_imm8x4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mova_compact)\t"
        << " f_imm8x4:0x" << hex << f_imm8x4 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movcal_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movcal_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_movt_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movt_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_mull_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mull_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_negc_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_negc_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_nop_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_nop_compact)\t"
        << endl;
    }

#undef FLD
}

void
sh4_nofpu_extract_sfmt_ocbi_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ocbi_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_pref_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_pref_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_rotcl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_rotcl_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_rts_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_rts_compact)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_shad_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_macl_compact.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shad_compact)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stc_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stc_gbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stc_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stc_vbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stcl_gbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stcl_gbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stcl_vbr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stcl_vbr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_sts_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sts_mach_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stsl_mach_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stsl_mach_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_sts_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sts_macl_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stsl_macl_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stsl_macl_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_sts_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sts_pr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_stsl_pr_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stsl_pr_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_tasb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_tasb_compact)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_trapa_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_trapa_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_tsti_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_tsti_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

void
sh4_nofpu_extract_sfmt_tstb_compact (sh4_nofpu_scache* abuf, sh4_nofpu_cpu* current_cpu, PCADDR pc, sh4_nofpu_insn_word base_insn, sh4_nofpu_insn_word entire_insn){
    sh4_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_andi_compact.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_tstb_compact)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_r0) = 0;
    }
#undef FLD
}

