/* Simulator instruction decoder for sh2a_nofpu.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh2a_nofpu.h"

using namespace sh2a_nofpu; // FIXME: namespace organization still wip


// The instruction descriptor array. 

sh2a_nofpu_idesc sh2a_nofpu_idesc::idesc_table[SH2A_NOFPU_INSN_XTRCT_COMPACT + 1] =
{
  { sh2a_nofpu_sem_x_invalid, "X_INVALID", SH2A_NOFPU_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_add_compact, "ADD_COMPACT", SH2A_NOFPU_INSN_ADD_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_addi_compact, "ADDI_COMPACT", SH2A_NOFPU_INSN_ADDI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_addc_compact, "ADDC_COMPACT", SH2A_NOFPU_INSN_ADDC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_addv_compact, "ADDV_COMPACT", SH2A_NOFPU_INSN_ADDV_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_and_compact, "AND_COMPACT", SH2A_NOFPU_INSN_AND_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_andi_compact, "ANDI_COMPACT", SH2A_NOFPU_INSN_ANDI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_andb_compact, "ANDB_COMPACT", SH2A_NOFPU_INSN_ANDB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_bf_compact, "BF_COMPACT", SH2A_NOFPU_INSN_BF_COMPACT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_bfs_compact, "BFS_COMPACT", SH2A_NOFPU_INSN_BFS_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_bra_compact, "BRA_COMPACT", SH2A_NOFPU_INSN_BRA_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_braf_compact, "BRAF_COMPACT", SH2A_NOFPU_INSN_BRAF_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_bsr_compact, "BSR_COMPACT", SH2A_NOFPU_INSN_BSR_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_bsrf_compact, "BSRF_COMPACT", SH2A_NOFPU_INSN_BSRF_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_bt_compact, "BT_COMPACT", SH2A_NOFPU_INSN_BT_COMPACT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_bts_compact, "BTS_COMPACT", SH2A_NOFPU_INSN_BTS_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_BR, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_clrmac_compact, "CLRMAC_COMPACT", SH2A_NOFPU_INSN_CLRMAC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_clrt_compact, "CLRT_COMPACT", SH2A_NOFPU_INSN_CLRT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmpeq_compact, "CMPEQ_COMPACT", SH2A_NOFPU_INSN_CMPEQ_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmpeqi_compact, "CMPEQI_COMPACT", SH2A_NOFPU_INSN_CMPEQI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmpge_compact, "CMPGE_COMPACT", SH2A_NOFPU_INSN_CMPGE_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmpgt_compact, "CMPGT_COMPACT", SH2A_NOFPU_INSN_CMPGT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmphi_compact, "CMPHI_COMPACT", SH2A_NOFPU_INSN_CMPHI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmphs_compact, "CMPHS_COMPACT", SH2A_NOFPU_INSN_CMPHS_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmppl_compact, "CMPPL_COMPACT", SH2A_NOFPU_INSN_CMPPL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmppz_compact, "CMPPZ_COMPACT", SH2A_NOFPU_INSN_CMPPZ_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_cmpstr_compact, "CMPSTR_COMPACT", SH2A_NOFPU_INSN_CMPSTR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_div0s_compact, "DIV0S_COMPACT", SH2A_NOFPU_INSN_DIV0S_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_div0u_compact, "DIV0U_COMPACT", SH2A_NOFPU_INSN_DIV0U_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_div1_compact, "DIV1_COMPACT", SH2A_NOFPU_INSN_DIV1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_divu_compact, "DIVU_COMPACT", SH2A_NOFPU_INSN_DIVU_COMPACT, { 0, (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_mulr_compact, "MULR_COMPACT", SH2A_NOFPU_INSN_MULR_COMPACT, { 0, (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_dmulsl_compact, "DMULSL_COMPACT", SH2A_NOFPU_INSN_DMULSL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_dmulul_compact, "DMULUL_COMPACT", SH2A_NOFPU_INSN_DMULUL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_dt_compact, "DT_COMPACT", SH2A_NOFPU_INSN_DT_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_extsb_compact, "EXTSB_COMPACT", SH2A_NOFPU_INSN_EXTSB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_extsw_compact, "EXTSW_COMPACT", SH2A_NOFPU_INSN_EXTSW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_extub_compact, "EXTUB_COMPACT", SH2A_NOFPU_INSN_EXTUB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_extuw_compact, "EXTUW_COMPACT", SH2A_NOFPU_INSN_EXTUW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_frchg_compact, "FRCHG_COMPACT", SH2A_NOFPU_INSN_FRCHG_COMPACT, { 0|(1<<CGEN_INSN_FP_INSN), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_FE, SH4A_GROUP_FE } },
  { sh2a_nofpu_sem_fschg_compact, "FSCHG_COMPACT", SH2A_NOFPU_INSN_FSCHG_COMPACT, { 0|(1<<CGEN_INSN_FP_INSN), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_FE, SH4A_GROUP_FE } },
  { sh2a_nofpu_sem_jmp_compact, "JMP_COMPACT", SH2A_NOFPU_INSN_JMP_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_jsr_compact, "JSR_COMPACT", SH2A_NOFPU_INSN_JSR_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_ldc_gbr_compact, "LDC_GBR_COMPACT", SH2A_NOFPU_INSN_LDC_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_ldc_vbr_compact, "LDC_VBR_COMPACT", SH2A_NOFPU_INSN_LDC_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_ldc_sr_compact, "LDC_SR_COMPACT", SH2A_NOFPU_INSN_LDC_SR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_ldcl_gbr_compact, "LDCL_GBR_COMPACT", SH2A_NOFPU_INSN_LDCL_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_ldcl_vbr_compact, "LDCL_VBR_COMPACT", SH2A_NOFPU_INSN_LDCL_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_lds_mach_compact, "LDS_MACH_COMPACT", SH2A_NOFPU_INSN_LDS_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_ldsl_mach_compact, "LDSL_MACH_COMPACT", SH2A_NOFPU_INSN_LDSL_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_lds_macl_compact, "LDS_MACL_COMPACT", SH2A_NOFPU_INSN_LDS_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_ldsl_macl_compact, "LDSL_MACL_COMPACT", SH2A_NOFPU_INSN_LDSL_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_lds_pr_compact, "LDS_PR_COMPACT", SH2A_NOFPU_INSN_LDS_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_ldsl_pr_compact, "LDSL_PR_COMPACT", SH2A_NOFPU_INSN_LDSL_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_macl_compact, "MACL_COMPACT", SH2A_NOFPU_INSN_MACL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_macw_compact, "MACW_COMPACT", SH2A_NOFPU_INSN_MACW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_mov_compact, "MOV_COMPACT", SH2A_NOFPU_INSN_MOV_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_MT } },
  { sh2a_nofpu_sem_movi_compact, "MOVI_COMPACT", SH2A_NOFPU_INSN_MOVI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_MT } },
  { sh2a_nofpu_sem_movi20_compact, "MOVI20_COMPACT", SH2A_NOFPU_INSN_MOVI20_COMPACT, { 0|(1<<CGEN_INSN_32_BIT_INSN), (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_movb1_compact, "MOVB1_COMPACT", SH2A_NOFPU_INSN_MOVB1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb2_compact, "MOVB2_COMPACT", SH2A_NOFPU_INSN_MOVB2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb3_compact, "MOVB3_COMPACT", SH2A_NOFPU_INSN_MOVB3_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb4_compact, "MOVB4_COMPACT", SH2A_NOFPU_INSN_MOVB4_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb5_compact, "MOVB5_COMPACT", SH2A_NOFPU_INSN_MOVB5_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb6_compact, "MOVB6_COMPACT", SH2A_NOFPU_INSN_MOVB6_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb7_compact, "MOVB7_COMPACT", SH2A_NOFPU_INSN_MOVB7_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb8_compact, "MOVB8_COMPACT", SH2A_NOFPU_INSN_MOVB8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb9_compact, "MOVB9_COMPACT", SH2A_NOFPU_INSN_MOVB9_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movb10_compact, "MOVB10_COMPACT", SH2A_NOFPU_INSN_MOVB10_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl1_compact, "MOVL1_COMPACT", SH2A_NOFPU_INSN_MOVL1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl2_compact, "MOVL2_COMPACT", SH2A_NOFPU_INSN_MOVL2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl3_compact, "MOVL3_COMPACT", SH2A_NOFPU_INSN_MOVL3_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl4_compact, "MOVL4_COMPACT", SH2A_NOFPU_INSN_MOVL4_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl5_compact, "MOVL5_COMPACT", SH2A_NOFPU_INSN_MOVL5_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl6_compact, "MOVL6_COMPACT", SH2A_NOFPU_INSN_MOVL6_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl7_compact, "MOVL7_COMPACT", SH2A_NOFPU_INSN_MOVL7_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl8_compact, "MOVL8_COMPACT", SH2A_NOFPU_INSN_MOVL8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl9_compact, "MOVL9_COMPACT", SH2A_NOFPU_INSN_MOVL9_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl10_compact, "MOVL10_COMPACT", SH2A_NOFPU_INSN_MOVL10_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl11_compact, "MOVL11_COMPACT", SH2A_NOFPU_INSN_MOVL11_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movl12_compact, "MOVL12_COMPACT", SH2A_NOFPU_INSN_MOVL12_COMPACT, { 0|(1<<CGEN_INSN_32_BIT_INSN), (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_movl13_compact, "MOVL13_COMPACT", SH2A_NOFPU_INSN_MOVL13_COMPACT, { 0|(1<<CGEN_INSN_32_BIT_INSN), (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH4)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_NONE, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_movw1_compact, "MOVW1_COMPACT", SH2A_NOFPU_INSN_MOVW1_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw2_compact, "MOVW2_COMPACT", SH2A_NOFPU_INSN_MOVW2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw3_compact, "MOVW3_COMPACT", SH2A_NOFPU_INSN_MOVW3_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw4_compact, "MOVW4_COMPACT", SH2A_NOFPU_INSN_MOVW4_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw5_compact, "MOVW5_COMPACT", SH2A_NOFPU_INSN_MOVW5_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw6_compact, "MOVW6_COMPACT", SH2A_NOFPU_INSN_MOVW6_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw7_compact, "MOVW7_COMPACT", SH2A_NOFPU_INSN_MOVW7_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw8_compact, "MOVW8_COMPACT", SH2A_NOFPU_INSN_MOVW8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw9_compact, "MOVW9_COMPACT", SH2A_NOFPU_INSN_MOVW9_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw10_compact, "MOVW10_COMPACT", SH2A_NOFPU_INSN_MOVW10_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movw11_compact, "MOVW11_COMPACT", SH2A_NOFPU_INSN_MOVW11_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_LS, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_mova_compact, "MOVA_COMPACT", SH2A_NOFPU_INSN_MOVA_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_movt_compact, "MOVT_COMPACT", SH2A_NOFPU_INSN_MOVT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_mull_compact, "MULL_COMPACT", SH2A_NOFPU_INSN_MULL_COMPACT, { 0, (1<<MACH_SH2)|(1<<MACH_SH2E)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH2A_NOFPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_mulsw_compact, "MULSW_COMPACT", SH2A_NOFPU_INSN_MULSW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_muluw_compact, "MULUW_COMPACT", SH2A_NOFPU_INSN_MULUW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_neg_compact, "NEG_COMPACT", SH2A_NOFPU_INSN_NEG_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_negc_compact, "NEGC_COMPACT", SH2A_NOFPU_INSN_NEGC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_nop_compact, "NOP_COMPACT", SH2A_NOFPU_INSN_NOP_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_MT } },
  { sh2a_nofpu_sem_not_compact, "NOT_COMPACT", SH2A_NOFPU_INSN_NOT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_or_compact, "OR_COMPACT", SH2A_NOFPU_INSN_OR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_ori_compact, "ORI_COMPACT", SH2A_NOFPU_INSN_ORI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_orb_compact, "ORB_COMPACT", SH2A_NOFPU_INSN_ORB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_rotcl_compact, "ROTCL_COMPACT", SH2A_NOFPU_INSN_ROTCL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_rotcr_compact, "ROTCR_COMPACT", SH2A_NOFPU_INSN_ROTCR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_rotl_compact, "ROTL_COMPACT", SH2A_NOFPU_INSN_ROTL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_rotr_compact, "ROTR_COMPACT", SH2A_NOFPU_INSN_ROTR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_rts_compact, "RTS_COMPACT", SH2A_NOFPU_INSN_RTS_COMPACT, { 0|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_BR } },
  { sh2a_nofpu_sem_sett_compact, "SETT_COMPACT", SH2A_NOFPU_INSN_SETT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shad_compact, "SHAD_COMPACT", SH2A_NOFPU_INSN_SHAD_COMPACT, { 0, (1<<MACH_SH2A_NOFPU)|(1<<MACH_SH2A_FPU)|(1<<MACH_SH3)|(1<<MACH_SH3E)|(1<<MACH_SH4_NOFPU)|(1<<MACH_SH4)|(1<<MACH_SH4A_NOFPU)|(1<<MACH_SH4A)|(1<<MACH_SH4AL)|(1<<MACH_SH5), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shal_compact, "SHAL_COMPACT", SH2A_NOFPU_INSN_SHAL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shar_compact, "SHAR_COMPACT", SH2A_NOFPU_INSN_SHAR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shll_compact, "SHLL_COMPACT", SH2A_NOFPU_INSN_SHLL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shll2_compact, "SHLL2_COMPACT", SH2A_NOFPU_INSN_SHLL2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shll8_compact, "SHLL8_COMPACT", SH2A_NOFPU_INSN_SHLL8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shll16_compact, "SHLL16_COMPACT", SH2A_NOFPU_INSN_SHLL16_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shlr_compact, "SHLR_COMPACT", SH2A_NOFPU_INSN_SHLR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shlr2_compact, "SHLR2_COMPACT", SH2A_NOFPU_INSN_SHLR2_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shlr8_compact, "SHLR8_COMPACT", SH2A_NOFPU_INSN_SHLR8_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_shlr16_compact, "SHLR16_COMPACT", SH2A_NOFPU_INSN_SHLR16_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_stc_gbr_compact, "STC_GBR_COMPACT", SH2A_NOFPU_INSN_STC_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_stc_vbr_compact, "STC_VBR_COMPACT", SH2A_NOFPU_INSN_STC_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_stcl_gbr_compact, "STCL_GBR_COMPACT", SH2A_NOFPU_INSN_STCL_GBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_stcl_vbr_compact, "STCL_VBR_COMPACT", SH2A_NOFPU_INSN_STCL_VBR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_NONE } },
  { sh2a_nofpu_sem_sts_mach_compact, "STS_MACH_COMPACT", SH2A_NOFPU_INSN_STS_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_stsl_mach_compact, "STSL_MACH_COMPACT", SH2A_NOFPU_INSN_STSL_MACH_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_sts_macl_compact, "STS_MACL_COMPACT", SH2A_NOFPU_INSN_STS_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_stsl_macl_compact, "STSL_MACL_COMPACT", SH2A_NOFPU_INSN_STSL_MACL_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_sts_pr_compact, "STS_PR_COMPACT", SH2A_NOFPU_INSN_STS_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_stsl_pr_compact, "STSL_PR_COMPACT", SH2A_NOFPU_INSN_STSL_PR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_LS } },
  { sh2a_nofpu_sem_sub_compact, "SUB_COMPACT", SH2A_NOFPU_INSN_SUB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_subc_compact, "SUBC_COMPACT", SH2A_NOFPU_INSN_SUBC_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_subv_compact, "SUBV_COMPACT", SH2A_NOFPU_INSN_SUBV_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_swapb_compact, "SWAPB_COMPACT", SH2A_NOFPU_INSN_SWAPB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_swapw_compact, "SWAPW_COMPACT", SH2A_NOFPU_INSN_SWAPW_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_tasb_compact, "TASB_COMPACT", SH2A_NOFPU_INSN_TASB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_trapa_compact, "TRAPA_COMPACT", SH2A_NOFPU_INSN_TRAPA_COMPACT, { 0|(1<<CGEN_INSN_ILLSLOT), (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_tst_compact, "TST_COMPACT", SH2A_NOFPU_INSN_TST_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_tsti_compact, "TSTI_COMPACT", SH2A_NOFPU_INSN_TSTI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_MT, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_tstb_compact, "TSTB_COMPACT", SH2A_NOFPU_INSN_TSTB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_xor_compact, "XOR_COMPACT", SH2A_NOFPU_INSN_XOR_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_xori_compact, "XORI_COMPACT", SH2A_NOFPU_INSN_XORI_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },
  { sh2a_nofpu_sem_xorb_compact, "XORB_COMPACT", SH2A_NOFPU_INSN_XORB_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_CO, SH4A_GROUP_CO } },
  { sh2a_nofpu_sem_xtrct_compact, "XTRCT_COMPACT", SH2A_NOFPU_INSN_XTRCT_COMPACT, { 0, (1<<MACH_BASE), { 1, "\x80" }, SH4_GROUP_EX, SH4A_GROUP_EX } },

};

// Given a canonical virtual insn id, return the target specific one.

sh2a_nofpu_insn_type
sh2a_nofpu_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return SH2A_NOFPU_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return SH2A_NOFPU_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
sh2a_nofpu_extract_sfmt_empty (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_add_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_addi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_addc_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_addv_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_and_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_andi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_andb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_bf_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_bfs_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_bra_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_braf_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_bsr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_bsrf_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_clrmac_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_clrt_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_cmpeq_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_cmpeqi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_cmppl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_div0s_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_div0u_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_div1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_divu_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_dmulsl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_dt_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_extsb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_frchg_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_fschg_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldc_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldc_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldc_sr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldcl_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldcl_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_lds_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldsl_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_lds_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldsl_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_lds_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_ldsl_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_macw_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_mov_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movi20_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb3_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb4_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb5_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb6_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb7_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb8_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb9_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movb10_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl3_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl4_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl5_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl6_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl7_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl8_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl9_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl10_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl11_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl12_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movl13_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw3_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw4_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw5_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw6_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw7_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw8_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw9_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw10_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movw11_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_mova_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_movt_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_mull_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_negc_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_nop_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_rotcl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_rts_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_shad_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_shll2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stc_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stc_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stcl_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stcl_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_sts_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stsl_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_sts_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stsl_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_sts_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_stsl_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_tasb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_trapa_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_tsti_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);
static void
sh2a_nofpu_extract_sfmt_tstb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn);

// Fetch & decode instruction
void
sh2a_nofpu_scache::decode (sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn)
{
  /* Result of decoder.  */
  SH2A_NOFPU_INSN_TYPE itype;

  {
    sh2a_nofpu_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 22) & (15 << 6)) | ((insn >> 16) & (63 << 0)));
      switch (val)
      {
      case 0 : /* fall through */
      case 16 : /* fall through */
      case 32 : /* fall through */
      case 48 : itype = SH2A_NOFPU_INSN_MOVI20_COMPACT; sh2a_nofpu_extract_sfmt_movi20_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x3)
          { itype = SH2A_NOFPU_INSN_BSRF_COMPACT; sh2a_nofpu_extract_sfmt_bsrf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 : /* fall through */
      case 20 : /* fall through */
      case 36 : /* fall through */
      case 52 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVB3_COMPACT; sh2a_nofpu_extract_sfmt_movb3_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 5 : /* fall through */
      case 21 : /* fall through */
      case 37 : /* fall through */
      case 53 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW3_COMPACT; sh2a_nofpu_extract_sfmt_movw3_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 6 : /* fall through */
      case 22 : /* fall through */
      case 38 : /* fall through */
      case 54 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL3_COMPACT; sh2a_nofpu_extract_sfmt_movl3_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 : /* fall through */
      case 23 : /* fall through */
      case 39 : /* fall through */
      case 55 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MULL_COMPACT; sh2a_nofpu_extract_sfmt_mull_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x8)
          { itype = SH2A_NOFPU_INSN_CLRT_COMPACT; sh2a_nofpu_extract_sfmt_clrt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 9 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x9)
          { itype = SH2A_NOFPU_INSN_NOP_COMPACT; sh2a_nofpu_extract_sfmt_nop_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 10 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0xa)
          { itype = SH2A_NOFPU_INSN_STS_MACH_COMPACT; sh2a_nofpu_extract_sfmt_sts_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 11 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0xb)
          { itype = SH2A_NOFPU_INSN_RTS_COMPACT; sh2a_nofpu_extract_sfmt_rts_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 12 : /* fall through */
      case 28 : /* fall through */
      case 44 : /* fall through */
      case 60 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVB8_COMPACT; sh2a_nofpu_extract_sfmt_movb8_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 13 : /* fall through */
      case 29 : /* fall through */
      case 45 : /* fall through */
      case 61 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW8_COMPACT; sh2a_nofpu_extract_sfmt_movw8_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 14 : /* fall through */
      case 30 : /* fall through */
      case 46 : /* fall through */
      case 62 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL8_COMPACT; sh2a_nofpu_extract_sfmt_movl8_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 15 : /* fall through */
      case 31 : /* fall through */
      case 47 : /* fall through */
      case 63 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MACL_COMPACT; sh2a_nofpu_extract_sfmt_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 18 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x12)
          { itype = SH2A_NOFPU_INSN_STC_GBR_COMPACT; sh2a_nofpu_extract_sfmt_stc_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x18)
          { itype = SH2A_NOFPU_INSN_SETT_COMPACT; sh2a_nofpu_extract_sfmt_clrt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 25 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x19)
          { itype = SH2A_NOFPU_INSN_DIV0U_COMPACT; sh2a_nofpu_extract_sfmt_div0u_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 26 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x1a)
          { itype = SH2A_NOFPU_INSN_STS_MACL_COMPACT; sh2a_nofpu_extract_sfmt_sts_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 34 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x22)
          { itype = SH2A_NOFPU_INSN_STC_VBR_COMPACT; sh2a_nofpu_extract_sfmt_stc_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 35 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x23)
          { itype = SH2A_NOFPU_INSN_BRAF_COMPACT; sh2a_nofpu_extract_sfmt_braf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 40 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffff) == 0x28)
          { itype = SH2A_NOFPU_INSN_CLRMAC_COMPACT; sh2a_nofpu_extract_sfmt_clrmac_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 41 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x29)
          { itype = SH2A_NOFPU_INSN_MOVT_COMPACT; sh2a_nofpu_extract_sfmt_movt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 42 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x2a)
          { itype = SH2A_NOFPU_INSN_STS_PR_COMPACT; sh2a_nofpu_extract_sfmt_sts_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 64 : /* fall through */
      case 65 : /* fall through */
      case 66 : /* fall through */
      case 67 : /* fall through */
      case 68 : /* fall through */
      case 69 : /* fall through */
      case 70 : /* fall through */
      case 71 : /* fall through */
      case 72 : /* fall through */
      case 73 : /* fall through */
      case 74 : /* fall through */
      case 75 : /* fall through */
      case 76 : /* fall through */
      case 77 : /* fall through */
      case 78 : /* fall through */
      case 79 : /* fall through */
      case 80 : /* fall through */
      case 81 : /* fall through */
      case 82 : /* fall through */
      case 83 : /* fall through */
      case 84 : /* fall through */
      case 85 : /* fall through */
      case 86 : /* fall through */
      case 87 : /* fall through */
      case 88 : /* fall through */
      case 89 : /* fall through */
      case 90 : /* fall through */
      case 91 : /* fall through */
      case 92 : /* fall through */
      case 93 : /* fall through */
      case 94 : /* fall through */
      case 95 : /* fall through */
      case 96 : /* fall through */
      case 97 : /* fall through */
      case 98 : /* fall through */
      case 99 : /* fall through */
      case 100 : /* fall through */
      case 101 : /* fall through */
      case 102 : /* fall through */
      case 103 : /* fall through */
      case 104 : /* fall through */
      case 105 : /* fall through */
      case 106 : /* fall through */
      case 107 : /* fall through */
      case 108 : /* fall through */
      case 109 : /* fall through */
      case 110 : /* fall through */
      case 111 : /* fall through */
      case 112 : /* fall through */
      case 113 : /* fall through */
      case 114 : /* fall through */
      case 115 : /* fall through */
      case 116 : /* fall through */
      case 117 : /* fall through */
      case 118 : /* fall through */
      case 119 : /* fall through */
      case 120 : /* fall through */
      case 121 : /* fall through */
      case 122 : /* fall through */
      case 123 : /* fall through */
      case 124 : /* fall through */
      case 125 : /* fall through */
      case 126 : /* fall through */
      case 127 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL5_COMPACT; sh2a_nofpu_extract_sfmt_movl5_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 128 : /* fall through */
      case 144 : /* fall through */
      case 160 : /* fall through */
      case 176 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVB1_COMPACT; sh2a_nofpu_extract_sfmt_movb1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 129 : /* fall through */
      case 145 : /* fall through */
      case 161 : /* fall through */
      case 177 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW1_COMPACT; sh2a_nofpu_extract_sfmt_movw1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 130 : /* fall through */
      case 146 : /* fall through */
      case 162 : /* fall through */
      case 178 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL1_COMPACT; sh2a_nofpu_extract_sfmt_movl1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 132 : /* fall through */
      case 148 : /* fall through */
      case 164 : /* fall through */
      case 180 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVB2_COMPACT; sh2a_nofpu_extract_sfmt_movb2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 133 : /* fall through */
      case 149 : /* fall through */
      case 165 : /* fall through */
      case 181 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW2_COMPACT; sh2a_nofpu_extract_sfmt_movw2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 134 : /* fall through */
      case 150 : /* fall through */
      case 166 : /* fall through */
      case 182 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL2_COMPACT; sh2a_nofpu_extract_sfmt_movl2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 135 : /* fall through */
      case 151 : /* fall through */
      case 167 : /* fall through */
      case 183 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_DIV0S_COMPACT; sh2a_nofpu_extract_sfmt_div0s_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 136 : /* fall through */
      case 152 : /* fall through */
      case 168 : /* fall through */
      case 184 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_TST_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 137 : /* fall through */
      case 153 : /* fall through */
      case 169 : /* fall through */
      case 185 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_AND_COMPACT; sh2a_nofpu_extract_sfmt_and_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 138 : /* fall through */
      case 154 : /* fall through */
      case 170 : /* fall through */
      case 186 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_XOR_COMPACT; sh2a_nofpu_extract_sfmt_and_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 139 : /* fall through */
      case 155 : /* fall through */
      case 171 : /* fall through */
      case 187 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_OR_COMPACT; sh2a_nofpu_extract_sfmt_and_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 140 : /* fall through */
      case 156 : /* fall through */
      case 172 : /* fall through */
      case 188 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_CMPSTR_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 141 : /* fall through */
      case 157 : /* fall through */
      case 173 : /* fall through */
      case 189 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_XTRCT_COMPACT; sh2a_nofpu_extract_sfmt_add_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 142 : /* fall through */
      case 158 : /* fall through */
      case 174 : /* fall through */
      case 190 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MULUW_COMPACT; sh2a_nofpu_extract_sfmt_mull_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 143 : /* fall through */
      case 159 : /* fall through */
      case 175 : /* fall through */
      case 191 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MULSW_COMPACT; sh2a_nofpu_extract_sfmt_mull_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 192 : /* fall through */
      case 208 : /* fall through */
      case 224 : /* fall through */
      case 240 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_CMPEQ_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 193 : /* fall through */
      case 209 : /* fall through */
      case 225 : /* fall through */
      case 241 :
        {
          unsigned int val = (((insn >> 14) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00ff000) == 0x30012000)
              { itype = SH2A_NOFPU_INSN_MOVL13_COMPACT; sh2a_nofpu_extract_sfmt_movl13_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf00ff000) == 0x30016000)
              { itype = SH2A_NOFPU_INSN_MOVL12_COMPACT; sh2a_nofpu_extract_sfmt_movl12_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 194 : /* fall through */
      case 210 : /* fall through */
      case 226 : /* fall through */
      case 242 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_CMPHS_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 195 : /* fall through */
      case 211 : /* fall through */
      case 227 : /* fall through */
      case 243 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_CMPGE_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 196 : /* fall through */
      case 212 : /* fall through */
      case 228 : /* fall through */
      case 244 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_DIV1_COMPACT; sh2a_nofpu_extract_sfmt_div1_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 197 : /* fall through */
      case 213 : /* fall through */
      case 229 : /* fall through */
      case 245 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_DMULUL_COMPACT; sh2a_nofpu_extract_sfmt_dmulsl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 198 : /* fall through */
      case 214 : /* fall through */
      case 230 : /* fall through */
      case 246 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_CMPHI_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 199 : /* fall through */
      case 215 : /* fall through */
      case 231 : /* fall through */
      case 247 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_CMPGT_COMPACT; sh2a_nofpu_extract_sfmt_cmpeq_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 200 : /* fall through */
      case 216 : /* fall through */
      case 232 : /* fall through */
      case 248 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_SUB_COMPACT; sh2a_nofpu_extract_sfmt_add_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 202 : /* fall through */
      case 218 : /* fall through */
      case 234 : /* fall through */
      case 250 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_SUBC_COMPACT; sh2a_nofpu_extract_sfmt_addc_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 203 : /* fall through */
      case 219 : /* fall through */
      case 235 : /* fall through */
      case 251 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_SUBV_COMPACT; sh2a_nofpu_extract_sfmt_addv_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 204 : /* fall through */
      case 220 : /* fall through */
      case 236 : /* fall through */
      case 252 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_ADD_COMPACT; sh2a_nofpu_extract_sfmt_add_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 205 : /* fall through */
      case 221 : /* fall through */
      case 237 : /* fall through */
      case 253 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_DMULSL_COMPACT; sh2a_nofpu_extract_sfmt_dmulsl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 206 : /* fall through */
      case 222 : /* fall through */
      case 238 : /* fall through */
      case 254 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_ADDC_COMPACT; sh2a_nofpu_extract_sfmt_addc_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 207 : /* fall through */
      case 223 : /* fall through */
      case 239 : /* fall through */
      case 255 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_ADDV_COMPACT; sh2a_nofpu_extract_sfmt_addv_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 256 :
        {
          unsigned int val = (((insn >> 23) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x4000)
              { itype = SH2A_NOFPU_INSN_SHLL_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x4080)
              { itype = SH2A_NOFPU_INSN_MULR_COMPACT; sh2a_nofpu_extract_sfmt_divu_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 257 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4001)
          { itype = SH2A_NOFPU_INSN_SHLR_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 258 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4002)
          { itype = SH2A_NOFPU_INSN_STSL_MACH_COMPACT; sh2a_nofpu_extract_sfmt_stsl_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 260 :
        {
          unsigned int val = (((insn >> 23) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x4004)
              { itype = SH2A_NOFPU_INSN_ROTL_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x4084)
              { itype = SH2A_NOFPU_INSN_DIVU_COMPACT; sh2a_nofpu_extract_sfmt_divu_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 261 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4005)
          { itype = SH2A_NOFPU_INSN_ROTR_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 262 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4006)
          { itype = SH2A_NOFPU_INSN_LDSL_MACH_COMPACT; sh2a_nofpu_extract_sfmt_ldsl_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 264 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4008)
          { itype = SH2A_NOFPU_INSN_SHLL2_COMPACT; sh2a_nofpu_extract_sfmt_shll2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 265 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4009)
          { itype = SH2A_NOFPU_INSN_SHLR2_COMPACT; sh2a_nofpu_extract_sfmt_shll2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 266 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x400a)
          { itype = SH2A_NOFPU_INSN_LDS_MACH_COMPACT; sh2a_nofpu_extract_sfmt_lds_mach_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 267 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x400b)
          { itype = SH2A_NOFPU_INSN_JSR_COMPACT; sh2a_nofpu_extract_sfmt_bsrf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 268 : /* fall through */
      case 284 : /* fall through */
      case 300 : /* fall through */
      case 316 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_SHAD_COMPACT; sh2a_nofpu_extract_sfmt_shad_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 270 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x400e)
          { itype = SH2A_NOFPU_INSN_LDC_SR_COMPACT; sh2a_nofpu_extract_sfmt_ldc_sr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 271 : /* fall through */
      case 287 : /* fall through */
      case 303 : /* fall through */
      case 319 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MACW_COMPACT; sh2a_nofpu_extract_sfmt_macw_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 272 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4010)
          { itype = SH2A_NOFPU_INSN_DT_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 273 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4011)
          { itype = SH2A_NOFPU_INSN_CMPPZ_COMPACT; sh2a_nofpu_extract_sfmt_cmppl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 274 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4012)
          { itype = SH2A_NOFPU_INSN_STSL_MACL_COMPACT; sh2a_nofpu_extract_sfmt_stsl_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 275 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4013)
          { itype = SH2A_NOFPU_INSN_STCL_GBR_COMPACT; sh2a_nofpu_extract_sfmt_stcl_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 277 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4015)
          { itype = SH2A_NOFPU_INSN_CMPPL_COMPACT; sh2a_nofpu_extract_sfmt_cmppl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 278 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4016)
          { itype = SH2A_NOFPU_INSN_LDSL_MACL_COMPACT; sh2a_nofpu_extract_sfmt_ldsl_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 279 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4017)
          { itype = SH2A_NOFPU_INSN_LDCL_GBR_COMPACT; sh2a_nofpu_extract_sfmt_ldcl_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 280 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4018)
          { itype = SH2A_NOFPU_INSN_SHLL8_COMPACT; sh2a_nofpu_extract_sfmt_shll2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 281 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4019)
          { itype = SH2A_NOFPU_INSN_SHLR8_COMPACT; sh2a_nofpu_extract_sfmt_shll2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 282 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x401a)
          { itype = SH2A_NOFPU_INSN_LDS_MACL_COMPACT; sh2a_nofpu_extract_sfmt_lds_macl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 283 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x401b)
          { itype = SH2A_NOFPU_INSN_TASB_COMPACT; sh2a_nofpu_extract_sfmt_tasb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 286 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x401e)
          { itype = SH2A_NOFPU_INSN_LDC_GBR_COMPACT; sh2a_nofpu_extract_sfmt_ldc_gbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 288 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4020)
          { itype = SH2A_NOFPU_INSN_SHAL_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 289 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4021)
          { itype = SH2A_NOFPU_INSN_SHAR_COMPACT; sh2a_nofpu_extract_sfmt_dt_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 290 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4022)
          { itype = SH2A_NOFPU_INSN_STSL_PR_COMPACT; sh2a_nofpu_extract_sfmt_stsl_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 291 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4023)
          { itype = SH2A_NOFPU_INSN_STCL_VBR_COMPACT; sh2a_nofpu_extract_sfmt_stcl_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 292 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4024)
          { itype = SH2A_NOFPU_INSN_ROTCL_COMPACT; sh2a_nofpu_extract_sfmt_rotcl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 293 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4025)
          { itype = SH2A_NOFPU_INSN_ROTCR_COMPACT; sh2a_nofpu_extract_sfmt_rotcl_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 294 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4026)
          { itype = SH2A_NOFPU_INSN_LDSL_PR_COMPACT; sh2a_nofpu_extract_sfmt_ldsl_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 295 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4027)
          { itype = SH2A_NOFPU_INSN_LDCL_VBR_COMPACT; sh2a_nofpu_extract_sfmt_ldcl_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 296 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4028)
          { itype = SH2A_NOFPU_INSN_SHLL16_COMPACT; sh2a_nofpu_extract_sfmt_shll2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 297 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x4029)
          { itype = SH2A_NOFPU_INSN_SHLR16_COMPACT; sh2a_nofpu_extract_sfmt_shll2_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 298 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x402a)
          { itype = SH2A_NOFPU_INSN_LDS_PR_COMPACT; sh2a_nofpu_extract_sfmt_lds_pr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 299 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x402b)
          { itype = SH2A_NOFPU_INSN_JMP_COMPACT; sh2a_nofpu_extract_sfmt_braf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 302 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf0ff) == 0x402e)
          { itype = SH2A_NOFPU_INSN_LDC_VBR_COMPACT; sh2a_nofpu_extract_sfmt_ldc_vbr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 320 : /* fall through */
      case 321 : /* fall through */
      case 322 : /* fall through */
      case 323 : /* fall through */
      case 324 : /* fall through */
      case 325 : /* fall through */
      case 326 : /* fall through */
      case 327 : /* fall through */
      case 328 : /* fall through */
      case 329 : /* fall through */
      case 330 : /* fall through */
      case 331 : /* fall through */
      case 332 : /* fall through */
      case 333 : /* fall through */
      case 334 : /* fall through */
      case 335 : /* fall through */
      case 336 : /* fall through */
      case 337 : /* fall through */
      case 338 : /* fall through */
      case 339 : /* fall through */
      case 340 : /* fall through */
      case 341 : /* fall through */
      case 342 : /* fall through */
      case 343 : /* fall through */
      case 344 : /* fall through */
      case 345 : /* fall through */
      case 346 : /* fall through */
      case 347 : /* fall through */
      case 348 : /* fall through */
      case 349 : /* fall through */
      case 350 : /* fall through */
      case 351 : /* fall through */
      case 352 : /* fall through */
      case 353 : /* fall through */
      case 354 : /* fall through */
      case 355 : /* fall through */
      case 356 : /* fall through */
      case 357 : /* fall through */
      case 358 : /* fall through */
      case 359 : /* fall through */
      case 360 : /* fall through */
      case 361 : /* fall through */
      case 362 : /* fall through */
      case 363 : /* fall through */
      case 364 : /* fall through */
      case 365 : /* fall through */
      case 366 : /* fall through */
      case 367 : /* fall through */
      case 368 : /* fall through */
      case 369 : /* fall through */
      case 370 : /* fall through */
      case 371 : /* fall through */
      case 372 : /* fall through */
      case 373 : /* fall through */
      case 374 : /* fall through */
      case 375 : /* fall through */
      case 376 : /* fall through */
      case 377 : /* fall through */
      case 378 : /* fall through */
      case 379 : /* fall through */
      case 380 : /* fall through */
      case 381 : /* fall through */
      case 382 : /* fall through */
      case 383 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL11_COMPACT; sh2a_nofpu_extract_sfmt_movl11_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 384 : /* fall through */
      case 400 : /* fall through */
      case 416 : /* fall through */
      case 432 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVB6_COMPACT; sh2a_nofpu_extract_sfmt_movb6_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 385 : /* fall through */
      case 401 : /* fall through */
      case 417 : /* fall through */
      case 433 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW6_COMPACT; sh2a_nofpu_extract_sfmt_movw6_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 386 : /* fall through */
      case 402 : /* fall through */
      case 418 : /* fall through */
      case 434 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL6_COMPACT; sh2a_nofpu_extract_sfmt_movl6_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 387 : /* fall through */
      case 403 : /* fall through */
      case 419 : /* fall through */
      case 435 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOV_COMPACT; sh2a_nofpu_extract_sfmt_mov_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 388 : /* fall through */
      case 404 : /* fall through */
      case 420 : /* fall through */
      case 436 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVB7_COMPACT; sh2a_nofpu_extract_sfmt_movb7_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 389 : /* fall through */
      case 405 : /* fall through */
      case 421 : /* fall through */
      case 437 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW7_COMPACT; sh2a_nofpu_extract_sfmt_movw7_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 390 : /* fall through */
      case 406 : /* fall through */
      case 422 : /* fall through */
      case 438 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL7_COMPACT; sh2a_nofpu_extract_sfmt_movl7_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 391 : /* fall through */
      case 407 : /* fall through */
      case 423 : /* fall through */
      case 439 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_NOT_COMPACT; sh2a_nofpu_extract_sfmt_mov_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 392 : /* fall through */
      case 408 : /* fall through */
      case 424 : /* fall through */
      case 440 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_SWAPB_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 393 : /* fall through */
      case 409 : /* fall through */
      case 425 : /* fall through */
      case 441 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_SWAPW_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 394 : /* fall through */
      case 410 : /* fall through */
      case 426 : /* fall through */
      case 442 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_NEGC_COMPACT; sh2a_nofpu_extract_sfmt_negc_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 395 : /* fall through */
      case 411 : /* fall through */
      case 427 : /* fall through */
      case 443 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_NEG_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 396 : /* fall through */
      case 412 : /* fall through */
      case 428 : /* fall through */
      case 444 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_EXTUB_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 397 : /* fall through */
      case 413 : /* fall through */
      case 429 : /* fall through */
      case 445 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_EXTUW_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 398 : /* fall through */
      case 414 : /* fall through */
      case 430 : /* fall through */
      case 446 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_EXTSB_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 399 : /* fall through */
      case 415 : /* fall through */
      case 431 : /* fall through */
      case 447 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_EXTSW_COMPACT; sh2a_nofpu_extract_sfmt_extsb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 448 : /* fall through */
      case 449 : /* fall through */
      case 450 : /* fall through */
      case 451 : /* fall through */
      case 452 : /* fall through */
      case 453 : /* fall through */
      case 454 : /* fall through */
      case 455 : /* fall through */
      case 456 : /* fall through */
      case 457 : /* fall through */
      case 458 : /* fall through */
      case 459 : /* fall through */
      case 460 : /* fall through */
      case 461 : /* fall through */
      case 462 : /* fall through */
      case 463 : /* fall through */
      case 464 : /* fall through */
      case 465 : /* fall through */
      case 466 : /* fall through */
      case 467 : /* fall through */
      case 468 : /* fall through */
      case 469 : /* fall through */
      case 470 : /* fall through */
      case 471 : /* fall through */
      case 472 : /* fall through */
      case 473 : /* fall through */
      case 474 : /* fall through */
      case 475 : /* fall through */
      case 476 : /* fall through */
      case 477 : /* fall through */
      case 478 : /* fall through */
      case 479 : /* fall through */
      case 480 : /* fall through */
      case 481 : /* fall through */
      case 482 : /* fall through */
      case 483 : /* fall through */
      case 484 : /* fall through */
      case 485 : /* fall through */
      case 486 : /* fall through */
      case 487 : /* fall through */
      case 488 : /* fall through */
      case 489 : /* fall through */
      case 490 : /* fall through */
      case 491 : /* fall through */
      case 492 : /* fall through */
      case 493 : /* fall through */
      case 494 : /* fall through */
      case 495 : /* fall through */
      case 496 : /* fall through */
      case 497 : /* fall through */
      case 498 : /* fall through */
      case 499 : /* fall through */
      case 500 : /* fall through */
      case 501 : /* fall through */
      case 502 : /* fall through */
      case 503 : /* fall through */
      case 504 : /* fall through */
      case 505 : /* fall through */
      case 506 : /* fall through */
      case 507 : /* fall through */
      case 508 : /* fall through */
      case 509 : /* fall through */
      case 510 : /* fall through */
      case 511 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_ADDI_COMPACT; sh2a_nofpu_extract_sfmt_addi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 512 : /* fall through */
      case 513 : /* fall through */
      case 514 : /* fall through */
      case 515 : /* fall through */
      case 516 : /* fall through */
      case 517 : /* fall through */
      case 518 : /* fall through */
      case 519 : /* fall through */
      case 520 : /* fall through */
      case 521 : /* fall through */
      case 522 : /* fall through */
      case 523 : /* fall through */
      case 524 : /* fall through */
      case 525 : /* fall through */
      case 526 : /* fall through */
      case 527 : /* fall through */
      case 528 : /* fall through */
      case 529 : /* fall through */
      case 530 : /* fall through */
      case 531 : /* fall through */
      case 532 : /* fall through */
      case 533 : /* fall through */
      case 534 : /* fall through */
      case 535 : /* fall through */
      case 536 : /* fall through */
      case 537 : /* fall through */
      case 538 : /* fall through */
      case 539 : /* fall through */
      case 540 : /* fall through */
      case 541 : /* fall through */
      case 542 : /* fall through */
      case 543 : /* fall through */
      case 544 : /* fall through */
      case 545 : /* fall through */
      case 546 : /* fall through */
      case 547 : /* fall through */
      case 548 : /* fall through */
      case 549 : /* fall through */
      case 550 : /* fall through */
      case 551 : /* fall through */
      case 552 : /* fall through */
      case 553 : /* fall through */
      case 554 : /* fall through */
      case 555 : /* fall through */
      case 556 : /* fall through */
      case 557 : /* fall through */
      case 558 : /* fall through */
      case 559 : /* fall through */
      case 560 : /* fall through */
      case 561 : /* fall through */
      case 562 : /* fall through */
      case 563 : /* fall through */
      case 564 : /* fall through */
      case 565 : /* fall through */
      case 566 : /* fall through */
      case 567 : /* fall through */
      case 568 : /* fall through */
      case 569 : /* fall through */
      case 570 : /* fall through */
      case 571 : /* fall through */
      case 572 : /* fall through */
      case 573 : /* fall through */
      case 574 : /* fall through */
      case 575 :
        {
          unsigned int val = (((insn >> 24) & (15 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVB5_COMPACT; sh2a_nofpu_extract_sfmt_movb5_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVW5_COMPACT; sh2a_nofpu_extract_sfmt_movw5_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVB10_COMPACT; sh2a_nofpu_extract_sfmt_movb10_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVW11_COMPACT; sh2a_nofpu_extract_sfmt_movw11_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_CMPEQI_COMPACT; sh2a_nofpu_extract_sfmt_cmpeqi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_BT_COMPACT; sh2a_nofpu_extract_sfmt_bf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_BF_COMPACT; sh2a_nofpu_extract_sfmt_bf_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_BTS_COMPACT; sh2a_nofpu_extract_sfmt_bfs_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_BFS_COMPACT; sh2a_nofpu_extract_sfmt_bfs_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 576 : /* fall through */
      case 577 : /* fall through */
      case 578 : /* fall through */
      case 579 : /* fall through */
      case 580 : /* fall through */
      case 581 : /* fall through */
      case 582 : /* fall through */
      case 583 : /* fall through */
      case 584 : /* fall through */
      case 585 : /* fall through */
      case 586 : /* fall through */
      case 587 : /* fall through */
      case 588 : /* fall through */
      case 589 : /* fall through */
      case 590 : /* fall through */
      case 591 : /* fall through */
      case 592 : /* fall through */
      case 593 : /* fall through */
      case 594 : /* fall through */
      case 595 : /* fall through */
      case 596 : /* fall through */
      case 597 : /* fall through */
      case 598 : /* fall through */
      case 599 : /* fall through */
      case 600 : /* fall through */
      case 601 : /* fall through */
      case 602 : /* fall through */
      case 603 : /* fall through */
      case 604 : /* fall through */
      case 605 : /* fall through */
      case 606 : /* fall through */
      case 607 : /* fall through */
      case 608 : /* fall through */
      case 609 : /* fall through */
      case 610 : /* fall through */
      case 611 : /* fall through */
      case 612 : /* fall through */
      case 613 : /* fall through */
      case 614 : /* fall through */
      case 615 : /* fall through */
      case 616 : /* fall through */
      case 617 : /* fall through */
      case 618 : /* fall through */
      case 619 : /* fall through */
      case 620 : /* fall through */
      case 621 : /* fall through */
      case 622 : /* fall through */
      case 623 : /* fall through */
      case 624 : /* fall through */
      case 625 : /* fall through */
      case 626 : /* fall through */
      case 627 : /* fall through */
      case 628 : /* fall through */
      case 629 : /* fall through */
      case 630 : /* fall through */
      case 631 : /* fall through */
      case 632 : /* fall through */
      case 633 : /* fall through */
      case 634 : /* fall through */
      case 635 : /* fall through */
      case 636 : /* fall through */
      case 637 : /* fall through */
      case 638 : /* fall through */
      case 639 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVW10_COMPACT; sh2a_nofpu_extract_sfmt_movw10_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 703 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_BRA_COMPACT; sh2a_nofpu_extract_sfmt_bra_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        itype = SH2A_NOFPU_INSN_BSR_COMPACT; sh2a_nofpu_extract_sfmt_bsr_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 768 : /* fall through */
      case 769 : /* fall through */
      case 770 : /* fall through */
      case 771 : /* fall through */
      case 772 : /* fall through */
      case 773 : /* fall through */
      case 774 : /* fall through */
      case 775 : /* fall through */
      case 776 : /* fall through */
      case 777 : /* fall through */
      case 778 : /* fall through */
      case 779 : /* fall through */
      case 780 : /* fall through */
      case 781 : /* fall through */
      case 782 : /* fall through */
      case 783 : /* fall through */
      case 784 : /* fall through */
      case 785 : /* fall through */
      case 786 : /* fall through */
      case 787 : /* fall through */
      case 788 : /* fall through */
      case 789 : /* fall through */
      case 790 : /* fall through */
      case 791 : /* fall through */
      case 792 : /* fall through */
      case 793 : /* fall through */
      case 794 : /* fall through */
      case 795 : /* fall through */
      case 796 : /* fall through */
      case 797 : /* fall through */
      case 798 : /* fall through */
      case 799 : /* fall through */
      case 800 : /* fall through */
      case 801 : /* fall through */
      case 802 : /* fall through */
      case 803 : /* fall through */
      case 804 : /* fall through */
      case 805 : /* fall through */
      case 806 : /* fall through */
      case 807 : /* fall through */
      case 808 : /* fall through */
      case 809 : /* fall through */
      case 810 : /* fall through */
      case 811 : /* fall through */
      case 812 : /* fall through */
      case 813 : /* fall through */
      case 814 : /* fall through */
      case 815 : /* fall through */
      case 816 : /* fall through */
      case 817 : /* fall through */
      case 818 : /* fall through */
      case 819 : /* fall through */
      case 820 : /* fall through */
      case 821 : /* fall through */
      case 822 : /* fall through */
      case 823 : /* fall through */
      case 824 : /* fall through */
      case 825 : /* fall through */
      case 826 : /* fall through */
      case 827 : /* fall through */
      case 828 : /* fall through */
      case 829 : /* fall through */
      case 830 : /* fall through */
      case 831 :
        {
          unsigned int val = (((insn >> 24) & (15 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVB4_COMPACT; sh2a_nofpu_extract_sfmt_movb4_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVW4_COMPACT; sh2a_nofpu_extract_sfmt_movw4_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVL4_COMPACT; sh2a_nofpu_extract_sfmt_movl4_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_TRAPA_COMPACT; sh2a_nofpu_extract_sfmt_trapa_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVB9_COMPACT; sh2a_nofpu_extract_sfmt_movb9_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVW9_COMPACT; sh2a_nofpu_extract_sfmt_movw9_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVL9_COMPACT; sh2a_nofpu_extract_sfmt_movl9_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_MOVA_COMPACT; sh2a_nofpu_extract_sfmt_mova_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_TSTI_COMPACT; sh2a_nofpu_extract_sfmt_tsti_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_ANDI_COMPACT; sh2a_nofpu_extract_sfmt_andi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_XORI_COMPACT; sh2a_nofpu_extract_sfmt_andi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_ORI_COMPACT; sh2a_nofpu_extract_sfmt_andi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_TSTB_COMPACT; sh2a_nofpu_extract_sfmt_tstb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_ANDB_COMPACT; sh2a_nofpu_extract_sfmt_andb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_XORB_COMPACT; sh2a_nofpu_extract_sfmt_andb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = SH2A_NOFPU_INSN_ORB_COMPACT; sh2a_nofpu_extract_sfmt_andb_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 832 : /* fall through */
      case 833 : /* fall through */
      case 834 : /* fall through */
      case 835 : /* fall through */
      case 836 : /* fall through */
      case 837 : /* fall through */
      case 838 : /* fall through */
      case 839 : /* fall through */
      case 840 : /* fall through */
      case 841 : /* fall through */
      case 842 : /* fall through */
      case 843 : /* fall through */
      case 844 : /* fall through */
      case 845 : /* fall through */
      case 846 : /* fall through */
      case 847 : /* fall through */
      case 848 : /* fall through */
      case 849 : /* fall through */
      case 850 : /* fall through */
      case 851 : /* fall through */
      case 852 : /* fall through */
      case 853 : /* fall through */
      case 854 : /* fall through */
      case 855 : /* fall through */
      case 856 : /* fall through */
      case 857 : /* fall through */
      case 858 : /* fall through */
      case 859 : /* fall through */
      case 860 : /* fall through */
      case 861 : /* fall through */
      case 862 : /* fall through */
      case 863 : /* fall through */
      case 864 : /* fall through */
      case 865 : /* fall through */
      case 866 : /* fall through */
      case 867 : /* fall through */
      case 868 : /* fall through */
      case 869 : /* fall through */
      case 870 : /* fall through */
      case 871 : /* fall through */
      case 872 : /* fall through */
      case 873 : /* fall through */
      case 874 : /* fall through */
      case 875 : /* fall through */
      case 876 : /* fall through */
      case 877 : /* fall through */
      case 878 : /* fall through */
      case 879 : /* fall through */
      case 880 : /* fall through */
      case 881 : /* fall through */
      case 882 : /* fall through */
      case 883 : /* fall through */
      case 884 : /* fall through */
      case 885 : /* fall through */
      case 886 : /* fall through */
      case 887 : /* fall through */
      case 888 : /* fall through */
      case 889 : /* fall through */
      case 890 : /* fall through */
      case 891 : /* fall through */
      case 892 : /* fall through */
      case 893 : /* fall through */
      case 894 : /* fall through */
      case 895 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVL10_COMPACT; sh2a_nofpu_extract_sfmt_movl10_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 959 :
        entire_insn = entire_insn >> 16;
        itype = SH2A_NOFPU_INSN_MOVI_COMPACT; sh2a_nofpu_extract_sfmt_movi_compact (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1021 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xf3fd)
              { itype = SH2A_NOFPU_INSN_FSCHG_COMPACT; sh2a_nofpu_extract_sfmt_fschg_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xfbfd)
              { itype = SH2A_NOFPU_INSN_FRCHG_COMPACT; sh2a_nofpu_extract_sfmt_frchg_compact (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      default : itype = SH2A_NOFPU_INSN_X_INVALID; sh2a_nofpu_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & sh2a_nofpu_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
sh2a_nofpu_extract_sfmt_empty (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_add_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_addi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_addc_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_addv_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_and_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_andi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_andb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_bf_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bf_compact.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_SINT (insn, 16, 8, 8)) << (1))) + (((pc) + (4))));

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
sh2a_nofpu_extract_sfmt_bfs_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bf_compact.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_SINT (insn, 16, 8, 8)) << (1))) + (((pc) + (4))));

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
sh2a_nofpu_extract_sfmt_bra_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bra_compact.f
    SI f_disp12;

    f_disp12 = ((((EXTRACT_MSB0_SINT (insn, 16, 4, 12)) << (1))) + (((pc) + (4))));

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
sh2a_nofpu_extract_sfmt_braf_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_bsr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bra_compact.f
    SI f_disp12;

    f_disp12 = ((((EXTRACT_MSB0_SINT (insn, 16, 4, 12)) << (1))) + (((pc) + (4))));

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
sh2a_nofpu_extract_sfmt_bsrf_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_clrmac_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_clrt_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_cmpeq_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_cmpeqi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_cmppl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_div0s_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_div0u_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_div1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_divu_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_dmulsl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_dt_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_extsb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_frchg_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_fschg_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldc_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldc_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldc_sr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldcl_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldcl_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_lds_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldsl_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_lds_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldsl_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_lds_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_ldsl_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_macw_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_mov_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movi_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movi20_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
    UINT f_rn;
    INT f_imm20_hi;
    UINT f_imm20_lo;
    INT f_imm20;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_imm20_hi = EXTRACT_MSB0_SINT (insn, 32, 8, 4);
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
sh2a_nofpu_extract_sfmt_movb1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb3_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb4_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb5_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb6_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb7_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb8_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb9_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movb10_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl3_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl4_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl5_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl6_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl7_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl8_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl9_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl10_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl11_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movl12_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
    UINT f_rn;
    UINT f_rm;
    SI f_imm12x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_imm12x4 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) << (2));

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
sh2a_nofpu_extract_sfmt_movl13_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
    UINT f_rn;
    UINT f_rm;
    SI f_imm12x4;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_imm12x4 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) << (2));

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
sh2a_nofpu_extract_sfmt_movw1_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw3_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw4_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw5_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw6_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw7_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw8_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw9_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw10_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movw11_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_mova_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_movt_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_mull_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_negc_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_nop_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_rotcl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_rts_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_shad_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_shll2_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_divu_compact.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shll2_compact)\t"
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
sh2a_nofpu_extract_sfmt_stc_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_stc_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_stcl_gbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_stcl_vbr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_sts_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_stsl_mach_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_sts_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_stsl_macl_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_sts_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_stsl_pr_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_tasb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_trapa_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_tsti_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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
sh2a_nofpu_extract_sfmt_tstb_compact (sh2a_nofpu_scache* abuf, sh2a_nofpu_cpu* current_cpu, PCADDR pc, sh2a_nofpu_insn_word base_insn, sh2a_nofpu_insn_word entire_insn){
    sh2a_nofpu_insn_word insn = entire_insn;
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

