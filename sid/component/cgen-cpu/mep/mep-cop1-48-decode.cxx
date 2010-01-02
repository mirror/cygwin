/* Simulator instruction decoder for mepcop1_48.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext1.h"

using namespace mep_ext1; // FIXME: namespace organization still wip


// The instruction descriptor array. 

mepcop1_48_idesc mepcop1_48_idesc::idesc_table[MEPCOP1_48_INSN_CDMOVI_P0_P1 + 1] =
{
  { mepcop1_48_sem_x_invalid, "X_INVALID", MEPCOP1_48_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_CORE) } },
  { mepcop1_48_sem_cmov_crn_rm_p0, "CMOV_CRN_RM_P0", MEPCOP1_48_INSN_CMOV_CRN_RM_P0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0) } },
  { mepcop1_48_sem_cmov_rn_crm_p0, "CMOV_RN_CRM_P0", MEPCOP1_48_INSN_CMOV_RN_CRM_P0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0) } },
  { mepcop1_48_sem_cmovc_ccrn_rm_p0, "CMOVC_CCRN_RM_P0", MEPCOP1_48_INSN_CMOVC_CCRN_RM_P0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0) } },
  { mepcop1_48_sem_cmovc_rn_ccrm_p0, "CMOVC_RN_CCRM_P0", MEPCOP1_48_INSN_CMOVC_RN_CCRM_P0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0) } },
  { mepcop1_48_sem_cmovh_crn_rm_p0, "CMOVH_CRN_RM_P0", MEPCOP1_48_INSN_CMOVH_CRN_RM_P0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0) } },
  { mepcop1_48_sem_cmovh_rn_crm_p0, "CMOVH_RN_CRM_P0", MEPCOP1_48_INSN_CMOVH_RN_CRM_P0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x8" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0) } },
  { mepcop1_48_sem_c0nop_P0_P0S, "C0NOP_P0_P0S", MEPCOP1_48_INSN_C0NOP_P0_P0S, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x28" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P0S) } },
  { mepcop1_48_sem_cpfsftbi_P0_P1, "CPFSFTBI_P0_P1", MEPCOP1_48_INSN_CPFSFTBI_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpeq_b_P0_P1, "CPACMPEQ_B_P0_P1", MEPCOP1_48_INSN_CPACMPEQ_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpeq_h_P0_P1, "CPACMPEQ_H_P0_P1", MEPCOP1_48_INSN_CPACMPEQ_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpeq_w_P0_P1, "CPACMPEQ_W_P0_P1", MEPCOP1_48_INSN_CPACMPEQ_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpne_b_P0_P1, "CPACMPNE_B_P0_P1", MEPCOP1_48_INSN_CPACMPNE_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpne_h_P0_P1, "CPACMPNE_H_P0_P1", MEPCOP1_48_INSN_CPACMPNE_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpne_w_P0_P1, "CPACMPNE_W_P0_P1", MEPCOP1_48_INSN_CPACMPNE_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgtu_b_P0_P1, "CPACMPGTU_B_P0_P1", MEPCOP1_48_INSN_CPACMPGTU_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgt_b_P0_P1, "CPACMPGT_B_P0_P1", MEPCOP1_48_INSN_CPACMPGT_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgt_h_P0_P1, "CPACMPGT_H_P0_P1", MEPCOP1_48_INSN_CPACMPGT_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgtu_w_P0_P1, "CPACMPGTU_W_P0_P1", MEPCOP1_48_INSN_CPACMPGTU_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2USI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgt_w_P0_P1, "CPACMPGT_W_P0_P1", MEPCOP1_48_INSN_CPACMPGT_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgeu_b_P0_P1, "CPACMPGEU_B_P0_P1", MEPCOP1_48_INSN_CPACMPGEU_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpge_b_P0_P1, "CPACMPGE_B_P0_P1", MEPCOP1_48_INSN_CPACMPGE_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpge_h_P0_P1, "CPACMPGE_H_P0_P1", MEPCOP1_48_INSN_CPACMPGE_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpgeu_w_P0_P1, "CPACMPGEU_W_P0_P1", MEPCOP1_48_INSN_CPACMPGEU_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2USI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpacmpge_w_P0_P1, "CPACMPGE_W_P0_P1", MEPCOP1_48_INSN_CPACMPGE_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpeq_b_P0_P1, "CPOCMPEQ_B_P0_P1", MEPCOP1_48_INSN_CPOCMPEQ_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpeq_h_P0_P1, "CPOCMPEQ_H_P0_P1", MEPCOP1_48_INSN_CPOCMPEQ_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpeq_w_P0_P1, "CPOCMPEQ_W_P0_P1", MEPCOP1_48_INSN_CPOCMPEQ_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpne_b_P0_P1, "CPOCMPNE_B_P0_P1", MEPCOP1_48_INSN_CPOCMPNE_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpne_h_P0_P1, "CPOCMPNE_H_P0_P1", MEPCOP1_48_INSN_CPOCMPNE_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpne_w_P0_P1, "CPOCMPNE_W_P0_P1", MEPCOP1_48_INSN_CPOCMPNE_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgtu_b_P0_P1, "CPOCMPGTU_B_P0_P1", MEPCOP1_48_INSN_CPOCMPGTU_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgt_b_P0_P1, "CPOCMPGT_B_P0_P1", MEPCOP1_48_INSN_CPOCMPGT_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgt_h_P0_P1, "CPOCMPGT_H_P0_P1", MEPCOP1_48_INSN_CPOCMPGT_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgtu_w_P0_P1, "CPOCMPGTU_W_P0_P1", MEPCOP1_48_INSN_CPOCMPGTU_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2USI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgt_w_P0_P1, "CPOCMPGT_W_P0_P1", MEPCOP1_48_INSN_CPOCMPGT_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgeu_b_P0_P1, "CPOCMPGEU_B_P0_P1", MEPCOP1_48_INSN_CPOCMPGEU_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpge_b_P0_P1, "CPOCMPGE_B_P0_P1", MEPCOP1_48_INSN_CPOCMPGE_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpge_h_P0_P1, "CPOCMPGE_H_P0_P1", MEPCOP1_48_INSN_CPOCMPGE_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpgeu_w_P0_P1, "CPOCMPGEU_W_P0_P1", MEPCOP1_48_INSN_CPOCMPGEU_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2USI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpocmpge_w_P0_P1, "CPOCMPGE_W_P0_P1", MEPCOP1_48_INSN_CPOCMPGE_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdadd3_P0_P1, "CDADD3_P0_P1", MEPCOP1_48_INSN_CDADD3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsub3_b_P0_P1, "CPSUB3_B_P0_P1", MEPCOP1_48_INSN_CPSUB3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsub3_h_P0_P1, "CPSUB3_H_P0_P1", MEPCOP1_48_INSN_CPSUB3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsub3_w_P0_P1, "CPSUB3_W_P0_P1", MEPCOP1_48_INSN_CPSUB3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdsub3_P0_P1, "CDSUB3_P0_P1", MEPCOP1_48_INSN_CDSUB3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsadd3_h_P0_P1, "CPSADD3_H_P0_P1", MEPCOP1_48_INSN_CPSADD3_H_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsadd3_w_P0_P1, "CPSADD3_W_P0_P1", MEPCOP1_48_INSN_CPSADD3_W_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssub3_h_P0_P1, "CPSSUB3_H_P0_P1", MEPCOP1_48_INSN_CPSSUB3_H_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssub3_w_P0_P1, "CPSSUB3_W_P0_P1", MEPCOP1_48_INSN_CPSSUB3_W_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextuaddu3_b_P0_P1, "CPEXTUADDU3_B_P0_P1", MEPCOP1_48_INSN_CPEXTUADDU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextuadd3_b_P0_P1, "CPEXTUADD3_B_P0_P1", MEPCOP1_48_INSN_CPEXTUADD3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextladdu3_b_P0_P1, "CPEXTLADDU3_B_P0_P1", MEPCOP1_48_INSN_CPEXTLADDU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextladd3_b_P0_P1, "CPEXTLADD3_B_P0_P1", MEPCOP1_48_INSN_CPEXTLADD3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextusubu3_b_P0_P1, "CPEXTUSUBU3_B_P0_P1", MEPCOP1_48_INSN_CPEXTUSUBU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextusub3_b_P0_P1, "CPEXTUSUB3_B_P0_P1", MEPCOP1_48_INSN_CPEXTUSUB3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextlsubu3_b_P0_P1, "CPEXTLSUBU3_B_P0_P1", MEPCOP1_48_INSN_CPEXTLSUBU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpextlsub3_b_P0_P1, "CPEXTLSUB3_B_P0_P1", MEPCOP1_48_INSN_CPEXTLSUB3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpaveu3_b_P0_P1, "CPAVEU3_B_P0_P1", MEPCOP1_48_INSN_CPAVEU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpave3_b_P0_P1, "CPAVE3_B_P0_P1", MEPCOP1_48_INSN_CPAVE3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpave3_h_P0_P1, "CPAVE3_H_P0_P1", MEPCOP1_48_INSN_CPAVE3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpave3_w_P0_P1, "CPAVE3_W_P0_P1", MEPCOP1_48_INSN_CPAVE3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpaddsru3_b_P0_P1, "CPADDSRU3_B_P0_P1", MEPCOP1_48_INSN_CPADDSRU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpaddsr3_b_P0_P1, "CPADDSR3_B_P0_P1", MEPCOP1_48_INSN_CPADDSR3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpaddsr3_h_P0_P1, "CPADDSR3_H_P0_P1", MEPCOP1_48_INSN_CPADDSR3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpaddsr3_w_P0_P1, "CPADDSR3_W_P0_P1", MEPCOP1_48_INSN_CPADDSR3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpabsu3_b_P0_P1, "CPABSU3_B_P0_P1", MEPCOP1_48_INSN_CPABSU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpabs3_b_P0_P1, "CPABS3_B_P0_P1", MEPCOP1_48_INSN_CPABS3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpabs3_h_P0_P1, "CPABS3_H_P0_P1", MEPCOP1_48_INSN_CPABS3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpand3_P0_P1, "CPAND3_P0_P1", MEPCOP1_48_INSN_CPAND3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_VECT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpor3_P0_P1, "CPOR3_P0_P1", MEPCOP1_48_INSN_CPOR3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_VECT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpnor3_P0_P1, "CPNOR3_P0_P1", MEPCOP1_48_INSN_CPNOR3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_VECT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpxor3_P0_P1, "CPXOR3_P0_P1", MEPCOP1_48_INSN_CPXOR3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_VECT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cppacku_b_P0_P1, "CPPACKU_B_P0_P1", MEPCOP1_48_INSN_CPPACKU_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cppack_b_P0_P1, "CPPACK_B_P0_P1", MEPCOP1_48_INSN_CPPACK_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cppack_h_P0_P1, "CPPACK_H_P0_P1", MEPCOP1_48_INSN_CPPACK_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmaxu3_b_P0_P1, "CPMAXU3_B_P0_P1", MEPCOP1_48_INSN_CPMAXU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmax3_b_P0_P1, "CPMAX3_B_P0_P1", MEPCOP1_48_INSN_CPMAX3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmax3_h_P0_P1, "CPMAX3_H_P0_P1", MEPCOP1_48_INSN_CPMAX3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmaxu3_w_P0_P1, "CPMAXU3_W_P0_P1", MEPCOP1_48_INSN_CPMAXU3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmax3_w_P0_P1, "CPMAX3_W_P0_P1", MEPCOP1_48_INSN_CPMAX3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpminu3_b_P0_P1, "CPMINU3_B_P0_P1", MEPCOP1_48_INSN_CPMINU3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmin3_b_P0_P1, "CPMIN3_B_P0_P1", MEPCOP1_48_INSN_CPMIN3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmin3_h_P0_P1, "CPMIN3_H_P0_P1", MEPCOP1_48_INSN_CPMIN3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpminu3_w_P0_P1, "CPMINU3_W_P0_P1", MEPCOP1_48_INSN_CPMINU3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmin3_w_P0_P1, "CPMIN3_W_P0_P1", MEPCOP1_48_INSN_CPMIN3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrl3_b_P0_P1, "CPSRL3_B_P0_P1", MEPCOP1_48_INSN_CPSRL3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssrl3_b_P0_P1, "CPSSRL3_B_P0_P1", MEPCOP1_48_INSN_CPSSRL3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrl3_h_P0_P1, "CPSRL3_H_P0_P1", MEPCOP1_48_INSN_CPSRL3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssrl3_h_P0_P1, "CPSSRL3_H_P0_P1", MEPCOP1_48_INSN_CPSSRL3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrl3_w_P0_P1, "CPSRL3_W_P0_P1", MEPCOP1_48_INSN_CPSRL3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssrl3_w_P0_P1, "CPSSRL3_W_P0_P1", MEPCOP1_48_INSN_CPSSRL3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdsrl3_P0_P1, "CDSRL3_P0_P1", MEPCOP1_48_INSN_CDSRL3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsra3_b_P0_P1, "CPSRA3_B_P0_P1", MEPCOP1_48_INSN_CPSRA3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssra3_b_P0_P1, "CPSSRA3_B_P0_P1", MEPCOP1_48_INSN_CPSSRA3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsra3_h_P0_P1, "CPSRA3_H_P0_P1", MEPCOP1_48_INSN_CPSRA3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssra3_h_P0_P1, "CPSSRA3_H_P0_P1", MEPCOP1_48_INSN_CPSSRA3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsra3_w_P0_P1, "CPSRA3_W_P0_P1", MEPCOP1_48_INSN_CPSRA3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssra3_w_P0_P1, "CPSSRA3_W_P0_P1", MEPCOP1_48_INSN_CPSSRA3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdsra3_P0_P1, "CDSRA3_P0_P1", MEPCOP1_48_INSN_CDSRA3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsll3_b_P0_P1, "CPSLL3_B_P0_P1", MEPCOP1_48_INSN_CPSLL3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssll3_b_P0_P1, "CPSSLL3_B_P0_P1", MEPCOP1_48_INSN_CPSSLL3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsll3_h_P0_P1, "CPSLL3_H_P0_P1", MEPCOP1_48_INSN_CPSLL3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssll3_h_P0_P1, "CPSSLL3_H_P0_P1", MEPCOP1_48_INSN_CPSSLL3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsll3_w_P0_P1, "CPSLL3_W_P0_P1", MEPCOP1_48_INSN_CPSLL3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpssll3_w_P0_P1, "CPSSLL3_W_P0_P1", MEPCOP1_48_INSN_CPSSLL3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdsll3_P0_P1, "CDSLL3_P0_P1", MEPCOP1_48_INSN_CDSLL3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsla3_h_P0_P1, "CPSLA3_H_P0_P1", MEPCOP1_48_INSN_CPSLA3_H_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsla3_w_P0_P1, "CPSLA3_W_P0_P1", MEPCOP1_48_INSN_CPSLA3_W_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrli3_b_P0_P1, "CPSRLI3_B_P0_P1", MEPCOP1_48_INSN_CPSRLI3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrli3_h_P0_P1, "CPSRLI3_H_P0_P1", MEPCOP1_48_INSN_CPSRLI3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrli3_w_P0_P1, "CPSRLI3_W_P0_P1", MEPCOP1_48_INSN_CPSRLI3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdsrli3_P0_P1, "CDSRLI3_P0_P1", MEPCOP1_48_INSN_CDSRLI3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrai3_b_P0_P1, "CPSRAI3_B_P0_P1", MEPCOP1_48_INSN_CPSRAI3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrai3_h_P0_P1, "CPSRAI3_H_P0_P1", MEPCOP1_48_INSN_CPSRAI3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpsrai3_w_P0_P1, "CPSRAI3_W_P0_P1", MEPCOP1_48_INSN_CPSRAI3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdsrai3_P0_P1, "CDSRAI3_P0_P1", MEPCOP1_48_INSN_CDSRAI3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpslli3_b_P0_P1, "CPSLLI3_B_P0_P1", MEPCOP1_48_INSN_CPSLLI3_B_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpslli3_h_P0_P1, "CPSLLI3_H_P0_P1", MEPCOP1_48_INSN_CPSLLI3_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpslli3_w_P0_P1, "CPSLLI3_W_P0_P1", MEPCOP1_48_INSN_CPSLLI3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdslli3_P0_P1, "CDSLLI3_P0_P1", MEPCOP1_48_INSN_CDSLLI3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpslai3_h_P0_P1, "CPSLAI3_H_P0_P1", MEPCOP1_48_INSN_CPSLAI3_H_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpslai3_w_P0_P1, "CPSLAI3_W_P0_P1", MEPCOP1_48_INSN_CPSLAI3_W_P0_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpclipiu3_w_P0_P1, "CPCLIPIU3_W_P0_P1", MEPCOP1_48_INSN_CPCLIPIU3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpclipi3_w_P0_P1, "CPCLIPI3_W_P0_P1", MEPCOP1_48_INSN_CPCLIPI3_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdclipiu3_P0_P1, "CDCLIPIU3_P0_P1", MEPCOP1_48_INSN_CDCLIPIU3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdclipi3_P0_P1, "CDCLIPI3_P0_P1", MEPCOP1_48_INSN_CDCLIPI3_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmovi_h_P0_P1, "CPMOVI_H_P0_P1", MEPCOP1_48_INSN_CPMOVI_H_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmoviu_w_P0_P1, "CPMOVIU_W_P0_P1", MEPCOP1_48_INSN_CPMOVIU_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2USI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cpmovi_w_P0_P1, "CPMOVI_W_P0_P1", MEPCOP1_48_INSN_CPMOVI_W_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdmoviu_P0_P1, "CDMOVIU_P0_P1", MEPCOP1_48_INSN_CDMOVIU_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },
  { mepcop1_48_sem_cdmovi_P0_P1, "CDMOVI_P0_P1", MEPCOP1_48_INSN_CDMOVI_P0_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xc" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P1) } },

};

// Given a canonical virtual insn id, return the target specific one.

mepcop1_48_insn_type
mepcop1_48_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return MEPCOP1_48_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return MEPCOP1_48_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
mepcop1_48_extract_sfmt_empty (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cmov_crn_rm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cmov_rn_crm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cmovc_ccrn_rm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cmovc_rn_ccrm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cmovh_crn_rm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_c0nop_P0_P0S (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpfsftbi_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cdadd3_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpssub3_h_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpsrli3_b_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpsrli3_h_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpmovi_h_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
static void
mepcop1_48_extract_sfmt_cpmoviu_w_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);

// Fetch & decode instruction
void
mepcop1_48_scache::decode (mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn)
{
  /* Result of decoder.  */
  MEPCOP1_48_INSN_TYPE itype;

  {
    mepcop1_48_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 20) & (127 << 4)) | ((insn >> 19) & (15 << 0)));
      switch (val)
      {
      case 0 :
        if ((entire_insn & 0xffffffff) == 0x0)
          { itype = MEPCOP1_48_INSN_C0NOP_P0_P0S; mepcop1_48_extract_sfmt_c0nop_P0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 :
        {
          unsigned int val = (((insn >> 4) & (31 << 0)));
          switch (val)
          {
          case 1 :
            if ((entire_insn & 0xfff801ff) == 0x980010)
              { itype = MEPCOP1_48_INSN_CPACMPEQ_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff801ff) == 0x980030)
              { itype = MEPCOP1_48_INSN_CPACMPEQ_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfff801ff) == 0x980050)
              { itype = MEPCOP1_48_INSN_CPACMPEQ_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xfff801ff) == 0x980090)
              { itype = MEPCOP1_48_INSN_CPACMPNE_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xfff801ff) == 0x9800b0)
              { itype = MEPCOP1_48_INSN_CPACMPNE_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfff801ff) == 0x9800d0)
              { itype = MEPCOP1_48_INSN_CPACMPNE_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 16 :
            if ((entire_insn & 0xfff801ff) == 0x980100)
              { itype = MEPCOP1_48_INSN_CPACMPGTU_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 17 :
            if ((entire_insn & 0xfff801ff) == 0x980110)
              { itype = MEPCOP1_48_INSN_CPACMPGT_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 19 :
            if ((entire_insn & 0xfff801ff) == 0x980130)
              { itype = MEPCOP1_48_INSN_CPACMPGT_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 20 :
            if ((entire_insn & 0xfff801ff) == 0x980140)
              { itype = MEPCOP1_48_INSN_CPACMPGTU_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 21 :
            if ((entire_insn & 0xfff801ff) == 0x980150)
              { itype = MEPCOP1_48_INSN_CPACMPGT_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 24 :
            if ((entire_insn & 0xfff801ff) == 0x980180)
              { itype = MEPCOP1_48_INSN_CPACMPGEU_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 25 :
            if ((entire_insn & 0xfff801ff) == 0x980190)
              { itype = MEPCOP1_48_INSN_CPACMPGE_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 27 :
            if ((entire_insn & 0xfff801ff) == 0x9801b0)
              { itype = MEPCOP1_48_INSN_CPACMPGE_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 28 :
            if ((entire_insn & 0xfff801ff) == 0x9801c0)
              { itype = MEPCOP1_48_INSN_CPACMPGEU_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 29 :
            if ((entire_insn & 0xfff801ff) == 0x9801d0)
              { itype = MEPCOP1_48_INSN_CPACMPGE_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 5 : /* fall through */
      case 21 : /* fall through */
      case 37 : /* fall through */
      case 53 : /* fall through */
      case 69 : /* fall through */
      case 85 : /* fall through */
      case 101 : /* fall through */
      case 117 : /* fall through */
      case 133 : /* fall through */
      case 149 : /* fall through */
      case 165 : /* fall through */
      case 181 : /* fall through */
      case 197 : /* fall through */
      case 213 : /* fall through */
      case 229 : /* fall through */
      case 245 : /* fall through */
      case 261 : /* fall through */
      case 277 : /* fall through */
      case 293 : /* fall through */
      case 309 : /* fall through */
      case 325 : /* fall through */
      case 341 : /* fall through */
      case 357 : /* fall through */
      case 373 : /* fall through */
      case 389 : /* fall through */
      case 405 : /* fall through */
      case 421 : /* fall through */
      case 437 : /* fall through */
      case 453 : /* fall through */
      case 469 : /* fall through */
      case 485 : /* fall through */
      case 501 : /* fall through */
      case 517 : /* fall through */
      case 533 : /* fall through */
      case 549 : /* fall through */
      case 565 : /* fall through */
      case 581 : /* fall through */
      case 597 : /* fall through */
      case 613 : /* fall through */
      case 629 : /* fall through */
      case 645 : /* fall through */
      case 661 : /* fall through */
      case 677 : /* fall through */
      case 693 : /* fall through */
      case 709 : /* fall through */
      case 725 : /* fall through */
      case 741 : /* fall through */
      case 757 : /* fall through */
      case 773 : /* fall through */
      case 789 : /* fall through */
      case 805 : /* fall through */
      case 821 : /* fall through */
      case 837 : /* fall through */
      case 853 : /* fall through */
      case 869 : /* fall through */
      case 885 : /* fall through */
      case 901 : /* fall through */
      case 917 : /* fall through */
      case 933 : /* fall through */
      case 949 : /* fall through */
      case 965 : /* fall through */
      case 981 : /* fall through */
      case 997 : /* fall through */
      case 1013 : /* fall through */
      case 1029 : /* fall through */
      case 1045 : /* fall through */
      case 1061 : /* fall through */
      case 1077 : /* fall through */
      case 1093 : /* fall through */
      case 1109 : /* fall through */
      case 1125 : /* fall through */
      case 1141 : /* fall through */
      case 1157 : /* fall through */
      case 1173 : /* fall through */
      case 1189 : /* fall through */
      case 1205 : /* fall through */
      case 1221 : /* fall through */
      case 1237 : /* fall through */
      case 1253 : /* fall through */
      case 1269 : /* fall through */
      case 1285 : /* fall through */
      case 1301 : /* fall through */
      case 1317 : /* fall through */
      case 1333 : /* fall through */
      case 1349 : /* fall through */
      case 1365 : /* fall through */
      case 1381 : /* fall through */
      case 1397 : /* fall through */
      case 1413 : /* fall through */
      case 1429 : /* fall through */
      case 1445 : /* fall through */
      case 1461 : /* fall through */
      case 1477 : /* fall through */
      case 1493 : /* fall through */
      case 1509 : /* fall through */
      case 1525 : /* fall through */
      case 1541 : /* fall through */
      case 1557 : /* fall through */
      case 1573 : /* fall through */
      case 1589 : /* fall through */
      case 1605 : /* fall through */
      case 1621 : /* fall through */
      case 1637 : /* fall through */
      case 1653 : /* fall through */
      case 1669 : /* fall through */
      case 1685 : /* fall through */
      case 1701 : /* fall through */
      case 1717 : /* fall through */
      case 1733 : /* fall through */
      case 1749 : /* fall through */
      case 1765 : /* fall through */
      case 1781 : /* fall through */
      case 1797 : /* fall through */
      case 1813 : /* fall through */
      case 1829 : /* fall through */
      case 1845 : /* fall through */
      case 1861 : /* fall through */
      case 1877 : /* fall through */
      case 1893 : /* fall through */
      case 1909 : /* fall through */
      case 1925 : /* fall through */
      case 1941 : /* fall through */
      case 1957 : /* fall through */
      case 1973 : /* fall through */
      case 1989 : /* fall through */
      case 2005 : /* fall through */
      case 2021 : /* fall through */
      case 2037 :
        {
          unsigned int val = (((insn >> 9) & (31 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf83e0f) == 0xa80000)
              { itype = MEPCOP1_48_INSN_CPSRLI3_B_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf83e0f) == 0xa80200)
              { itype = MEPCOP1_48_INSN_CPSRLI3_H_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf83e0f) == 0xa80400)
              { itype = MEPCOP1_48_INSN_CPSRLI3_W_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf83e0f) == 0xa80600)
              { itype = MEPCOP1_48_INSN_CDSRLI3_P0_P1; mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf83e0f) == 0xa80800)
              { itype = MEPCOP1_48_INSN_CPSRAI3_B_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xf83e0f) == 0xa80a00)
              { itype = MEPCOP1_48_INSN_CPSRAI3_H_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf83e0f) == 0xa80c00)
              { itype = MEPCOP1_48_INSN_CPSRAI3_W_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf83e0f) == 0xa80e00)
              { itype = MEPCOP1_48_INSN_CDSRAI3_P0_P1; mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xf83e0f) == 0xa81000)
              { itype = MEPCOP1_48_INSN_CPSLLI3_B_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xf83e0f) == 0xa81200)
              { itype = MEPCOP1_48_INSN_CPSLLI3_H_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            if ((entire_insn & 0xf83e0f) == 0xa81400)
              { itype = MEPCOP1_48_INSN_CPSLLI3_W_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xf83e0f) == 0xa81600)
              { itype = MEPCOP1_48_INSN_CDSLLI3_P0_P1; mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xf83e0f) == 0xa81a00)
              { itype = MEPCOP1_48_INSN_CPSLAI3_H_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            if ((entire_insn & 0xf83e0f) == 0xa81c00)
              { itype = MEPCOP1_48_INSN_CPSLAI3_W_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 16 :
            if ((entire_insn & 0xf83e0f) == 0xa82000)
              { itype = MEPCOP1_48_INSN_CPCLIPIU3_W_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 17 :
            if ((entire_insn & 0xf83e0f) == 0xa82200)
              { itype = MEPCOP1_48_INSN_CPCLIPI3_W_P0_P1; mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 18 :
            if ((entire_insn & 0xf83e0f) == 0xa82400)
              { itype = MEPCOP1_48_INSN_CDCLIPIU3_P0_P1; mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 19 :
            if ((entire_insn & 0xf83e0f) == 0xa82600)
              { itype = MEPCOP1_48_INSN_CDCLIPI3_P0_P1; mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 6 : /* fall through */
      case 22 : /* fall through */
      case 38 : /* fall through */
      case 54 : /* fall through */
      case 70 : /* fall through */
      case 86 : /* fall through */
      case 102 : /* fall through */
      case 118 : /* fall through */
      case 134 : /* fall through */
      case 150 : /* fall through */
      case 166 : /* fall through */
      case 182 : /* fall through */
      case 198 : /* fall through */
      case 214 : /* fall through */
      case 230 : /* fall through */
      case 246 : /* fall through */
      case 262 : /* fall through */
      case 278 : /* fall through */
      case 294 : /* fall through */
      case 310 : /* fall through */
      case 326 : /* fall through */
      case 342 : /* fall through */
      case 358 : /* fall through */
      case 374 : /* fall through */
      case 390 : /* fall through */
      case 406 : /* fall through */
      case 422 : /* fall through */
      case 438 : /* fall through */
      case 454 : /* fall through */
      case 470 : /* fall through */
      case 486 : /* fall through */
      case 502 : /* fall through */
      case 518 : /* fall through */
      case 534 : /* fall through */
      case 550 : /* fall through */
      case 566 : /* fall through */
      case 582 : /* fall through */
      case 598 : /* fall through */
      case 614 : /* fall through */
      case 630 : /* fall through */
      case 646 : /* fall through */
      case 662 : /* fall through */
      case 678 : /* fall through */
      case 694 : /* fall through */
      case 710 : /* fall through */
      case 726 : /* fall through */
      case 742 : /* fall through */
      case 758 : /* fall through */
      case 774 : /* fall through */
      case 790 : /* fall through */
      case 806 : /* fall through */
      case 822 : /* fall through */
      case 838 : /* fall through */
      case 854 : /* fall through */
      case 870 : /* fall through */
      case 886 : /* fall through */
      case 902 : /* fall through */
      case 918 : /* fall through */
      case 934 : /* fall through */
      case 950 : /* fall through */
      case 966 : /* fall through */
      case 982 : /* fall through */
      case 998 : /* fall through */
      case 1014 : /* fall through */
      case 1030 : /* fall through */
      case 1046 : /* fall through */
      case 1062 : /* fall through */
      case 1078 : /* fall through */
      case 1094 : /* fall through */
      case 1110 : /* fall through */
      case 1126 : /* fall through */
      case 1142 : /* fall through */
      case 1158 : /* fall through */
      case 1174 : /* fall through */
      case 1190 : /* fall through */
      case 1206 : /* fall through */
      case 1222 : /* fall through */
      case 1238 : /* fall through */
      case 1254 : /* fall through */
      case 1270 : /* fall through */
      case 1286 : /* fall through */
      case 1302 : /* fall through */
      case 1318 : /* fall through */
      case 1334 : /* fall through */
      case 1350 : /* fall through */
      case 1366 : /* fall through */
      case 1382 : /* fall through */
      case 1398 : /* fall through */
      case 1414 : /* fall through */
      case 1430 : /* fall through */
      case 1446 : /* fall through */
      case 1462 : /* fall through */
      case 1478 : /* fall through */
      case 1494 : /* fall through */
      case 1510 : /* fall through */
      case 1526 : /* fall through */
      case 1542 : /* fall through */
      case 1558 : /* fall through */
      case 1574 : /* fall through */
      case 1590 : /* fall through */
      case 1606 : /* fall through */
      case 1622 : /* fall through */
      case 1638 : /* fall through */
      case 1654 : /* fall through */
      case 1670 : /* fall through */
      case 1686 : /* fall through */
      case 1702 : /* fall through */
      case 1718 : /* fall through */
      case 1734 : /* fall through */
      case 1750 : /* fall through */
      case 1766 : /* fall through */
      case 1782 : /* fall through */
      case 1798 : /* fall through */
      case 1814 : /* fall through */
      case 1830 : /* fall through */
      case 1846 : /* fall through */
      case 1862 : /* fall through */
      case 1878 : /* fall through */
      case 1894 : /* fall through */
      case 1910 : /* fall through */
      case 1926 : /* fall through */
      case 1942 : /* fall through */
      case 1958 : /* fall through */
      case 1974 : /* fall through */
      case 1990 : /* fall through */
      case 2006 : /* fall through */
      case 2022 : /* fall through */
      case 2038 :
        if ((entire_insn & 0xf8300f) == 0xb01000)
          { itype = MEPCOP1_48_INSN_CPMOVI_H_P0_P1; mepcop1_48_extract_sfmt_cpmovi_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 : /* fall through */
      case 23 : /* fall through */
      case 39 : /* fall through */
      case 55 : /* fall through */
      case 71 : /* fall through */
      case 87 : /* fall through */
      case 103 : /* fall through */
      case 119 : /* fall through */
      case 135 : /* fall through */
      case 151 : /* fall through */
      case 167 : /* fall through */
      case 183 : /* fall through */
      case 199 : /* fall through */
      case 215 : /* fall through */
      case 231 : /* fall through */
      case 247 : /* fall through */
      case 263 : /* fall through */
      case 279 : /* fall through */
      case 295 : /* fall through */
      case 311 : /* fall through */
      case 327 : /* fall through */
      case 343 : /* fall through */
      case 359 : /* fall through */
      case 375 : /* fall through */
      case 391 : /* fall through */
      case 407 : /* fall through */
      case 423 : /* fall through */
      case 439 : /* fall through */
      case 455 : /* fall through */
      case 471 : /* fall through */
      case 487 : /* fall through */
      case 503 : /* fall through */
      case 519 : /* fall through */
      case 535 : /* fall through */
      case 551 : /* fall through */
      case 567 : /* fall through */
      case 583 : /* fall through */
      case 599 : /* fall through */
      case 615 : /* fall through */
      case 631 : /* fall through */
      case 647 : /* fall through */
      case 663 : /* fall through */
      case 679 : /* fall through */
      case 695 : /* fall through */
      case 711 : /* fall through */
      case 727 : /* fall through */
      case 743 : /* fall through */
      case 759 : /* fall through */
      case 775 : /* fall through */
      case 791 : /* fall through */
      case 807 : /* fall through */
      case 823 : /* fall through */
      case 839 : /* fall through */
      case 855 : /* fall through */
      case 871 : /* fall through */
      case 887 : /* fall through */
      case 903 : /* fall through */
      case 919 : /* fall through */
      case 935 : /* fall through */
      case 951 : /* fall through */
      case 967 : /* fall through */
      case 983 : /* fall through */
      case 999 : /* fall through */
      case 1015 : /* fall through */
      case 1031 : /* fall through */
      case 1047 : /* fall through */
      case 1063 : /* fall through */
      case 1079 : /* fall through */
      case 1095 : /* fall through */
      case 1111 : /* fall through */
      case 1127 : /* fall through */
      case 1143 : /* fall through */
      case 1159 : /* fall through */
      case 1175 : /* fall through */
      case 1191 : /* fall through */
      case 1207 : /* fall through */
      case 1223 : /* fall through */
      case 1239 : /* fall through */
      case 1255 : /* fall through */
      case 1271 : /* fall through */
      case 1287 : /* fall through */
      case 1303 : /* fall through */
      case 1319 : /* fall through */
      case 1335 : /* fall through */
      case 1351 : /* fall through */
      case 1367 : /* fall through */
      case 1383 : /* fall through */
      case 1399 : /* fall through */
      case 1415 : /* fall through */
      case 1431 : /* fall through */
      case 1447 : /* fall through */
      case 1463 : /* fall through */
      case 1479 : /* fall through */
      case 1495 : /* fall through */
      case 1511 : /* fall through */
      case 1527 : /* fall through */
      case 1543 : /* fall through */
      case 1559 : /* fall through */
      case 1575 : /* fall through */
      case 1591 : /* fall through */
      case 1607 : /* fall through */
      case 1623 : /* fall through */
      case 1639 : /* fall through */
      case 1655 : /* fall through */
      case 1671 : /* fall through */
      case 1687 : /* fall through */
      case 1703 : /* fall through */
      case 1719 : /* fall through */
      case 1735 : /* fall through */
      case 1751 : /* fall through */
      case 1767 : /* fall through */
      case 1783 : /* fall through */
      case 1799 : /* fall through */
      case 1815 : /* fall through */
      case 1831 : /* fall through */
      case 1847 : /* fall through */
      case 1863 : /* fall through */
      case 1879 : /* fall through */
      case 1895 : /* fall through */
      case 1911 : /* fall through */
      case 1927 : /* fall through */
      case 1943 : /* fall through */
      case 1959 : /* fall through */
      case 1975 : /* fall through */
      case 1991 : /* fall through */
      case 2007 : /* fall through */
      case 2023 : /* fall through */
      case 2039 :
        {
          unsigned int val = (((insn >> 12) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8300f) == 0xb80000)
              { itype = MEPCOP1_48_INSN_CPMOVIU_W_P0_P1; mepcop1_48_extract_sfmt_cpmoviu_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf8300f) == 0xb81000)
              { itype = MEPCOP1_48_INSN_CPMOVI_W_P0_P1; mepcop1_48_extract_sfmt_cpmovi_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf8300f) == 0xb82000)
              { itype = MEPCOP1_48_INSN_CDMOVIU_P0_P1; mepcop1_48_extract_sfmt_cpmoviu_w_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf8300f) == 0xb83000)
              { itype = MEPCOP1_48_INSN_CDMOVI_P0_P1; mepcop1_48_extract_sfmt_cpmovi_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 8 : /* fall through */
      case 24 : /* fall through */
      case 40 : /* fall through */
      case 56 : /* fall through */
      case 72 : /* fall through */
      case 88 : /* fall through */
      case 104 : /* fall through */
      case 120 : /* fall through */
      case 136 : /* fall through */
      case 152 : /* fall through */
      case 168 : /* fall through */
      case 184 : /* fall through */
      case 200 : /* fall through */
      case 216 : /* fall through */
      case 232 : /* fall through */
      case 248 : /* fall through */
      case 264 : /* fall through */
      case 280 : /* fall through */
      case 296 : /* fall through */
      case 312 : /* fall through */
      case 328 : /* fall through */
      case 344 : /* fall through */
      case 360 : /* fall through */
      case 376 : /* fall through */
      case 392 : /* fall through */
      case 408 : /* fall through */
      case 424 : /* fall through */
      case 440 : /* fall through */
      case 456 : /* fall through */
      case 472 : /* fall through */
      case 488 : /* fall through */
      case 504 : /* fall through */
      case 520 : /* fall through */
      case 536 : /* fall through */
      case 552 : /* fall through */
      case 568 : /* fall through */
      case 584 : /* fall through */
      case 600 : /* fall through */
      case 616 : /* fall through */
      case 632 : /* fall through */
      case 648 : /* fall through */
      case 664 : /* fall through */
      case 680 : /* fall through */
      case 696 : /* fall through */
      case 712 : /* fall through */
      case 728 : /* fall through */
      case 744 : /* fall through */
      case 760 : /* fall through */
      case 776 : /* fall through */
      case 792 : /* fall through */
      case 808 : /* fall through */
      case 824 : /* fall through */
      case 840 : /* fall through */
      case 856 : /* fall through */
      case 872 : /* fall through */
      case 888 : /* fall through */
      case 904 : /* fall through */
      case 920 : /* fall through */
      case 936 : /* fall through */
      case 952 : /* fall through */
      case 968 : /* fall through */
      case 984 : /* fall through */
      case 1000 : /* fall through */
      case 1016 : /* fall through */
      case 1032 : /* fall through */
      case 1048 : /* fall through */
      case 1064 : /* fall through */
      case 1080 : /* fall through */
      case 1096 : /* fall through */
      case 1112 : /* fall through */
      case 1128 : /* fall through */
      case 1144 : /* fall through */
      case 1160 : /* fall through */
      case 1176 : /* fall through */
      case 1192 : /* fall through */
      case 1208 : /* fall through */
      case 1224 : /* fall through */
      case 1240 : /* fall through */
      case 1256 : /* fall through */
      case 1272 : /* fall through */
      case 1288 : /* fall through */
      case 1304 : /* fall through */
      case 1320 : /* fall through */
      case 1336 : /* fall through */
      case 1352 : /* fall through */
      case 1368 : /* fall through */
      case 1384 : /* fall through */
      case 1400 : /* fall through */
      case 1416 : /* fall through */
      case 1432 : /* fall through */
      case 1448 : /* fall through */
      case 1464 : /* fall through */
      case 1480 : /* fall through */
      case 1496 : /* fall through */
      case 1512 : /* fall through */
      case 1528 : /* fall through */
      case 1544 : /* fall through */
      case 1560 : /* fall through */
      case 1576 : /* fall through */
      case 1592 : /* fall through */
      case 1608 : /* fall through */
      case 1624 : /* fall through */
      case 1640 : /* fall through */
      case 1656 : /* fall through */
      case 1672 : /* fall through */
      case 1688 : /* fall through */
      case 1704 : /* fall through */
      case 1720 : /* fall through */
      case 1736 : /* fall through */
      case 1752 : /* fall through */
      case 1768 : /* fall through */
      case 1784 : /* fall through */
      case 1800 : /* fall through */
      case 1816 : /* fall through */
      case 1832 : /* fall through */
      case 1848 : /* fall through */
      case 1864 : /* fall through */
      case 1880 : /* fall through */
      case 1896 : /* fall through */
      case 1912 : /* fall through */
      case 1928 : /* fall through */
      case 1944 : /* fall through */
      case 1960 : /* fall through */
      case 1976 : /* fall through */
      case 1992 : /* fall through */
      case 2008 : /* fall through */
      case 2024 : /* fall through */
      case 2040 :
        if ((entire_insn & 0xf8000f) == 0x400000)
          { itype = MEPCOP1_48_INSN_CPFSFTBI_P0_P1; mepcop1_48_extract_sfmt_cpfsftbi_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 14 : /* fall through */
      case 30 : /* fall through */
      case 46 : /* fall through */
      case 62 : /* fall through */
      case 78 : /* fall through */
      case 94 : /* fall through */
      case 110 : /* fall through */
      case 126 : /* fall through */
      case 142 : /* fall through */
      case 158 : /* fall through */
      case 174 : /* fall through */
      case 190 : /* fall through */
      case 206 : /* fall through */
      case 222 : /* fall through */
      case 238 : /* fall through */
      case 254 : /* fall through */
      case 270 : /* fall through */
      case 286 : /* fall through */
      case 302 : /* fall through */
      case 318 : /* fall through */
      case 334 : /* fall through */
      case 350 : /* fall through */
      case 366 : /* fall through */
      case 382 : /* fall through */
      case 398 : /* fall through */
      case 414 : /* fall through */
      case 430 : /* fall through */
      case 446 : /* fall through */
      case 462 : /* fall through */
      case 478 : /* fall through */
      case 494 : /* fall through */
      case 510 : /* fall through */
      case 526 : /* fall through */
      case 542 : /* fall through */
      case 558 : /* fall through */
      case 574 : /* fall through */
      case 590 : /* fall through */
      case 606 : /* fall through */
      case 622 : /* fall through */
      case 638 : /* fall through */
      case 654 : /* fall through */
      case 670 : /* fall through */
      case 686 : /* fall through */
      case 702 : /* fall through */
      case 718 : /* fall through */
      case 734 : /* fall through */
      case 750 : /* fall through */
      case 766 : /* fall through */
      case 782 : /* fall through */
      case 798 : /* fall through */
      case 814 : /* fall through */
      case 830 : /* fall through */
      case 846 : /* fall through */
      case 862 : /* fall through */
      case 878 : /* fall through */
      case 894 : /* fall through */
      case 910 : /* fall through */
      case 926 : /* fall through */
      case 942 : /* fall through */
      case 958 : /* fall through */
      case 974 : /* fall through */
      case 990 : /* fall through */
      case 1006 : /* fall through */
      case 1022 : /* fall through */
      case 1038 : /* fall through */
      case 1054 : /* fall through */
      case 1070 : /* fall through */
      case 1086 : /* fall through */
      case 1102 : /* fall through */
      case 1118 : /* fall through */
      case 1134 : /* fall through */
      case 1150 : /* fall through */
      case 1166 : /* fall through */
      case 1182 : /* fall through */
      case 1198 : /* fall through */
      case 1214 : /* fall through */
      case 1230 : /* fall through */
      case 1246 : /* fall through */
      case 1262 : /* fall through */
      case 1278 : /* fall through */
      case 1294 : /* fall through */
      case 1310 : /* fall through */
      case 1326 : /* fall through */
      case 1342 : /* fall through */
      case 1358 : /* fall through */
      case 1374 : /* fall through */
      case 1390 : /* fall through */
      case 1406 : /* fall through */
      case 1422 : /* fall through */
      case 1438 : /* fall through */
      case 1454 : /* fall through */
      case 1470 : /* fall through */
      case 1486 : /* fall through */
      case 1502 : /* fall through */
      case 1518 : /* fall through */
      case 1534 : /* fall through */
      case 1550 : /* fall through */
      case 1566 : /* fall through */
      case 1582 : /* fall through */
      case 1598 : /* fall through */
      case 1614 : /* fall through */
      case 1630 : /* fall through */
      case 1646 : /* fall through */
      case 1662 : /* fall through */
      case 1678 : /* fall through */
      case 1694 : /* fall through */
      case 1710 : /* fall through */
      case 1726 : /* fall through */
      case 1742 : /* fall through */
      case 1758 : /* fall through */
      case 1774 : /* fall through */
      case 1790 : /* fall through */
      case 1806 : /* fall through */
      case 1822 : /* fall through */
      case 1838 : /* fall through */
      case 1854 : /* fall through */
      case 1870 : /* fall through */
      case 1886 : /* fall through */
      case 1902 : /* fall through */
      case 1918 : /* fall through */
      case 1934 : /* fall through */
      case 1950 : /* fall through */
      case 1966 : /* fall through */
      case 1982 : /* fall through */
      case 1998 : /* fall through */
      case 2014 : /* fall through */
      case 2030 : /* fall through */
      case 2046 :
        {
          unsigned int val = (((insn >> 14) & (1 << 2)) | ((insn >> 8) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfff7ff) == 0xf00000)
              { itype = MEPCOP1_48_INSN_CMOV_CRN_RM_P0; mepcop1_48_extract_sfmt_cmov_crn_rm_p0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfff7ff) == 0xf00100)
              { itype = MEPCOP1_48_INSN_CMOV_RN_CRM_P0; mepcop1_48_extract_sfmt_cmov_rn_crm_p0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfff3ff) == 0xf00200)
              { itype = MEPCOP1_48_INSN_CMOVC_CCRN_RM_P0; mepcop1_48_extract_sfmt_cmovc_ccrn_rm_p0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff3ff) == 0xf00300)
              { itype = MEPCOP1_48_INSN_CMOVC_RN_CCRM_P0; mepcop1_48_extract_sfmt_cmovc_rn_ccrm_p0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfff7ff) == 0xf10000)
              { itype = MEPCOP1_48_INSN_CMOVH_CRN_RM_P0; mepcop1_48_extract_sfmt_cmovh_crn_rm_p0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfff7ff) == 0xf10100)
              { itype = MEPCOP1_48_INSN_CMOVH_RN_CRM_P0; mepcop1_48_extract_sfmt_cmov_rn_crm_p0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 19 :
        {
          unsigned int val = (((insn >> 4) & (31 << 0)));
          switch (val)
          {
          case 1 :
            if ((entire_insn & 0xfff801ff) == 0x1980010)
              { itype = MEPCOP1_48_INSN_CPOCMPEQ_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff801ff) == 0x1980030)
              { itype = MEPCOP1_48_INSN_CPOCMPEQ_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfff801ff) == 0x1980050)
              { itype = MEPCOP1_48_INSN_CPOCMPEQ_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xfff801ff) == 0x1980090)
              { itype = MEPCOP1_48_INSN_CPOCMPNE_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xfff801ff) == 0x19800b0)
              { itype = MEPCOP1_48_INSN_CPOCMPNE_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfff801ff) == 0x19800d0)
              { itype = MEPCOP1_48_INSN_CPOCMPNE_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 16 :
            if ((entire_insn & 0xfff801ff) == 0x1980100)
              { itype = MEPCOP1_48_INSN_CPOCMPGTU_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 17 :
            if ((entire_insn & 0xfff801ff) == 0x1980110)
              { itype = MEPCOP1_48_INSN_CPOCMPGT_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 19 :
            if ((entire_insn & 0xfff801ff) == 0x1980130)
              { itype = MEPCOP1_48_INSN_CPOCMPGT_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 20 :
            if ((entire_insn & 0xfff801ff) == 0x1980140)
              { itype = MEPCOP1_48_INSN_CPOCMPGTU_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 21 :
            if ((entire_insn & 0xfff801ff) == 0x1980150)
              { itype = MEPCOP1_48_INSN_CPOCMPGT_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 24 :
            if ((entire_insn & 0xfff801ff) == 0x1980180)
              { itype = MEPCOP1_48_INSN_CPOCMPGEU_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 25 :
            if ((entire_insn & 0xfff801ff) == 0x1980190)
              { itype = MEPCOP1_48_INSN_CPOCMPGE_B_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 27 :
            if ((entire_insn & 0xfff801ff) == 0x19801b0)
              { itype = MEPCOP1_48_INSN_CPOCMPGE_H_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 28 :
            if ((entire_insn & 0xfff801ff) == 0x19801c0)
              { itype = MEPCOP1_48_INSN_CPOCMPGEU_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 29 :
            if ((entire_insn & 0xfff801ff) == 0x19801d0)
              { itype = MEPCOP1_48_INSN_CPOCMPGE_W_P0_P1; mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 52 :
        if ((entire_insn & 0xfff8000f) == 0x3a00000)
          { itype = MEPCOP1_48_INSN_CDADD3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 68 :
        if ((entire_insn & 0xfff8000f) == 0x4a00000)
          { itype = MEPCOP1_48_INSN_CPSUB3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 84 :
        if ((entire_insn & 0xfff8000f) == 0x5a00000)
          { itype = MEPCOP1_48_INSN_CPSUB3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 100 :
        if ((entire_insn & 0xfff8000f) == 0x6a00000)
          { itype = MEPCOP1_48_INSN_CPSUB3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 116 :
        if ((entire_insn & 0xfff8000f) == 0x7a00000)
          { itype = MEPCOP1_48_INSN_CDSUB3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 164 :
        if ((entire_insn & 0xfff8000f) == 0xaa00000)
          { itype = MEPCOP1_48_INSN_CPSADD3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 180 :
        if ((entire_insn & 0xfff8000f) == 0xba00000)
          { itype = MEPCOP1_48_INSN_CPSADD3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 228 :
        if ((entire_insn & 0xfff8000f) == 0xea00000)
          { itype = MEPCOP1_48_INSN_CPSSUB3_H_P0_P1; mepcop1_48_extract_sfmt_cpssub3_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 244 :
        if ((entire_insn & 0xfff8000f) == 0xfa00000)
          { itype = MEPCOP1_48_INSN_CPSSUB3_W_P0_P1; mepcop1_48_extract_sfmt_cpssub3_h_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 260 :
        if ((entire_insn & 0xfff8000f) == 0x10a00000)
          { itype = MEPCOP1_48_INSN_CPEXTUADDU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 276 :
        if ((entire_insn & 0xfff8000f) == 0x11a00000)
          { itype = MEPCOP1_48_INSN_CPEXTUADD3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 292 :
        if ((entire_insn & 0xfff8000f) == 0x12a00000)
          { itype = MEPCOP1_48_INSN_CPEXTLADDU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 308 :
        if ((entire_insn & 0xfff8000f) == 0x13a00000)
          { itype = MEPCOP1_48_INSN_CPEXTLADD3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 324 :
        if ((entire_insn & 0xfff8000f) == 0x14a00000)
          { itype = MEPCOP1_48_INSN_CPEXTUSUBU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 340 :
        if ((entire_insn & 0xfff8000f) == 0x15a00000)
          { itype = MEPCOP1_48_INSN_CPEXTUSUB3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 356 :
        if ((entire_insn & 0xfff8000f) == 0x16a00000)
          { itype = MEPCOP1_48_INSN_CPEXTLSUBU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 372 :
        if ((entire_insn & 0xfff8000f) == 0x17a00000)
          { itype = MEPCOP1_48_INSN_CPEXTLSUB3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 388 :
        if ((entire_insn & 0xfff8000f) == 0x18a00000)
          { itype = MEPCOP1_48_INSN_CPAVEU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 404 :
        if ((entire_insn & 0xfff8000f) == 0x19a00000)
          { itype = MEPCOP1_48_INSN_CPAVE3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 420 :
        if ((entire_insn & 0xfff8000f) == 0x1aa00000)
          { itype = MEPCOP1_48_INSN_CPAVE3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 436 :
        if ((entire_insn & 0xfff8000f) == 0x1ba00000)
          { itype = MEPCOP1_48_INSN_CPAVE3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 452 :
        if ((entire_insn & 0xfff8000f) == 0x1ca00000)
          { itype = MEPCOP1_48_INSN_CPADDSRU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 468 :
        if ((entire_insn & 0xfff8000f) == 0x1da00000)
          { itype = MEPCOP1_48_INSN_CPADDSR3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 484 :
        if ((entire_insn & 0xfff8000f) == 0x1ea00000)
          { itype = MEPCOP1_48_INSN_CPADDSR3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 500 :
        if ((entire_insn & 0xfff8000f) == 0x1fa00000)
          { itype = MEPCOP1_48_INSN_CPADDSR3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 516 :
        if ((entire_insn & 0xfff8000f) == 0x20a00000)
          { itype = MEPCOP1_48_INSN_CPABSU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 532 :
        if ((entire_insn & 0xfff8000f) == 0x21a00000)
          { itype = MEPCOP1_48_INSN_CPABS3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 548 :
        if ((entire_insn & 0xfff8000f) == 0x22a00000)
          { itype = MEPCOP1_48_INSN_CPABS3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 580 :
        if ((entire_insn & 0xfff8000f) == 0x24a00000)
          { itype = MEPCOP1_48_INSN_CPAND3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 596 :
        if ((entire_insn & 0xfff8000f) == 0x25a00000)
          { itype = MEPCOP1_48_INSN_CPOR3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 612 :
        if ((entire_insn & 0xfff8000f) == 0x26a00000)
          { itype = MEPCOP1_48_INSN_CPNOR3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 628 :
        if ((entire_insn & 0xfff8000f) == 0x27a00000)
          { itype = MEPCOP1_48_INSN_CPXOR3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 708 :
        if ((entire_insn & 0xfff8000f) == 0x2ca00000)
          { itype = MEPCOP1_48_INSN_CPPACKU_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 724 :
        if ((entire_insn & 0xfff8000f) == 0x2da00000)
          { itype = MEPCOP1_48_INSN_CPPACK_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 756 :
        if ((entire_insn & 0xfff8000f) == 0x2fa00000)
          { itype = MEPCOP1_48_INSN_CPPACK_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 772 :
        if ((entire_insn & 0xfff8000f) == 0x30a00000)
          { itype = MEPCOP1_48_INSN_CPMAXU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 788 :
        if ((entire_insn & 0xfff8000f) == 0x31a00000)
          { itype = MEPCOP1_48_INSN_CPMAX3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 820 :
        if ((entire_insn & 0xfff8000f) == 0x33a00000)
          { itype = MEPCOP1_48_INSN_CPMAX3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 836 :
        if ((entire_insn & 0xfff8000f) == 0x34a00000)
          { itype = MEPCOP1_48_INSN_CPMAXU3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 852 :
        if ((entire_insn & 0xfff8000f) == 0x35a00000)
          { itype = MEPCOP1_48_INSN_CPMAX3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 900 :
        if ((entire_insn & 0xfff8000f) == 0x38a00000)
          { itype = MEPCOP1_48_INSN_CPMINU3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 916 :
        if ((entire_insn & 0xfff8000f) == 0x39a00000)
          { itype = MEPCOP1_48_INSN_CPMIN3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 948 :
        if ((entire_insn & 0xfff8000f) == 0x3ba00000)
          { itype = MEPCOP1_48_INSN_CPMIN3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 964 :
        if ((entire_insn & 0xfff8000f) == 0x3ca00000)
          { itype = MEPCOP1_48_INSN_CPMINU3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 980 :
        if ((entire_insn & 0xfff8000f) == 0x3da00000)
          { itype = MEPCOP1_48_INSN_CPMIN3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1028 :
        if ((entire_insn & 0xfff8000f) == 0x40a00000)
          { itype = MEPCOP1_48_INSN_CPSRL3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1044 :
        if ((entire_insn & 0xfff8000f) == 0x41a00000)
          { itype = MEPCOP1_48_INSN_CPSSRL3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1060 :
        if ((entire_insn & 0xfff8000f) == 0x42a00000)
          { itype = MEPCOP1_48_INSN_CPSRL3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1076 :
        if ((entire_insn & 0xfff8000f) == 0x43a00000)
          { itype = MEPCOP1_48_INSN_CPSSRL3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1092 :
        if ((entire_insn & 0xfff8000f) == 0x44a00000)
          { itype = MEPCOP1_48_INSN_CPSRL3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1108 :
        if ((entire_insn & 0xfff8000f) == 0x45a00000)
          { itype = MEPCOP1_48_INSN_CPSSRL3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1124 :
        if ((entire_insn & 0xfff8000f) == 0x46a00000)
          { itype = MEPCOP1_48_INSN_CDSRL3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1156 :
        if ((entire_insn & 0xfff8000f) == 0x48a00000)
          { itype = MEPCOP1_48_INSN_CPSRA3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1172 :
        if ((entire_insn & 0xfff8000f) == 0x49a00000)
          { itype = MEPCOP1_48_INSN_CPSSRA3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1188 :
        if ((entire_insn & 0xfff8000f) == 0x4aa00000)
          { itype = MEPCOP1_48_INSN_CPSRA3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1204 :
        if ((entire_insn & 0xfff8000f) == 0x4ba00000)
          { itype = MEPCOP1_48_INSN_CPSSRA3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1220 :
        if ((entire_insn & 0xfff8000f) == 0x4ca00000)
          { itype = MEPCOP1_48_INSN_CPSRA3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1236 :
        if ((entire_insn & 0xfff8000f) == 0x4da00000)
          { itype = MEPCOP1_48_INSN_CPSSRA3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1252 :
        if ((entire_insn & 0xfff8000f) == 0x4ea00000)
          { itype = MEPCOP1_48_INSN_CDSRA3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1284 :
        if ((entire_insn & 0xfff8000f) == 0x50a00000)
          { itype = MEPCOP1_48_INSN_CPSLL3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1300 :
        if ((entire_insn & 0xfff8000f) == 0x51a00000)
          { itype = MEPCOP1_48_INSN_CPSSLL3_B_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1316 :
        if ((entire_insn & 0xfff8000f) == 0x52a00000)
          { itype = MEPCOP1_48_INSN_CPSLL3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1332 :
        if ((entire_insn & 0xfff8000f) == 0x53a00000)
          { itype = MEPCOP1_48_INSN_CPSSLL3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1348 :
        if ((entire_insn & 0xfff8000f) == 0x54a00000)
          { itype = MEPCOP1_48_INSN_CPSLL3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1364 :
        if ((entire_insn & 0xfff8000f) == 0x55a00000)
          { itype = MEPCOP1_48_INSN_CPSSLL3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1380 :
        if ((entire_insn & 0xfff8000f) == 0x56a00000)
          { itype = MEPCOP1_48_INSN_CDSLL3_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1444 :
        if ((entire_insn & 0xfff8000f) == 0x5aa00000)
          { itype = MEPCOP1_48_INSN_CPSLA3_H_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1476 :
        if ((entire_insn & 0xfff8000f) == 0x5ca00000)
          { itype = MEPCOP1_48_INSN_CPSLA3_W_P0_P1; mepcop1_48_extract_sfmt_cdadd3_P0_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = MEPCOP1_48_INSN_X_INVALID; mepcop1_48_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & mepcop1_48_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
mepcop1_48_extract_sfmt_empty (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
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
mepcop1_48_extract_sfmt_cmov_crn_rm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
    UINT f_ivc2_ccrn_lo;
    UINT f_ivc2_crm;
    UINT f_ivc2_ccrn_h1;
    UINT f_ivc2_crnx;

    f_ivc2_ccrn_lo = EXTRACT_MSB0_UINT (insn, 32, 0, 4);
    f_ivc2_crm = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_ivc2_ccrn_h1 = EXTRACT_MSB0_UINT (insn, 32, 20, 1);
  f_ivc2_crnx = ((((f_ivc2_ccrn_h1) << (4))) | (f_ivc2_ccrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_crm) = f_ivc2_crm;
  FLD (f_ivc2_crnx) = f_ivc2_crnx;
  FLD (i_ivc2rm) = & current_cpu->hardware.h_gpr[f_ivc2_crm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmov_crn_rm_p0)\t"
        << " f_ivc2_crm:0x" << hex << f_ivc2_crm << dec
        << " f_ivc2_crnx:0x" << hex << f_ivc2_crnx << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_ivc2rm) = f_ivc2_crm;
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cmov_rn_crm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
    UINT f_ivc2_ccrn_lo;
    UINT f_ivc2_crm;
    UINT f_ivc2_ccrn_h1;
    UINT f_ivc2_crnx;

    f_ivc2_ccrn_lo = EXTRACT_MSB0_UINT (insn, 32, 0, 4);
    f_ivc2_crm = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_ivc2_ccrn_h1 = EXTRACT_MSB0_UINT (insn, 32, 20, 1);
  f_ivc2_crnx = ((((f_ivc2_ccrn_h1) << (4))) | (f_ivc2_ccrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_crnx) = f_ivc2_crnx;
  FLD (f_ivc2_crm) = f_ivc2_crm;
  FLD (i_ivc2rm) = & current_cpu->hardware.h_gpr[f_ivc2_crm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmov_rn_crm_p0)\t"
        << " f_ivc2_crnx:0x" << hex << f_ivc2_crnx << dec
        << " f_ivc2_crm:0x" << hex << f_ivc2_crm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_ivc2rm) = f_ivc2_crm;
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cmovc_ccrn_rm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm_p0.f
    UINT f_ivc2_ccrn_lo;
    UINT f_ivc2_crm;
    UINT f_ivc2_ccrn_h2;
    UINT f_ivc2_ccrn;

    f_ivc2_ccrn_lo = EXTRACT_MSB0_UINT (insn, 32, 0, 4);
    f_ivc2_crm = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_ivc2_ccrn_h2 = EXTRACT_MSB0_UINT (insn, 32, 20, 2);
  f_ivc2_ccrn = ((((f_ivc2_ccrn_h2) << (4))) | (f_ivc2_ccrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_crm) = f_ivc2_crm;
  FLD (f_ivc2_ccrn) = f_ivc2_ccrn;
  FLD (i_ivc2rm) = & current_cpu->hardware.h_gpr[f_ivc2_crm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmovc_ccrn_rm_p0)\t"
        << " f_ivc2_crm:0x" << hex << f_ivc2_crm << dec
        << " f_ivc2_ccrn:0x" << hex << f_ivc2_ccrn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_ivc2rm) = f_ivc2_crm;
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cmovc_rn_ccrm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm_p0.f
    UINT f_ivc2_ccrn_lo;
    UINT f_ivc2_crm;
    UINT f_ivc2_ccrn_h2;
    UINT f_ivc2_ccrn;

    f_ivc2_ccrn_lo = EXTRACT_MSB0_UINT (insn, 32, 0, 4);
    f_ivc2_crm = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_ivc2_ccrn_h2 = EXTRACT_MSB0_UINT (insn, 32, 20, 2);
  f_ivc2_ccrn = ((((f_ivc2_ccrn_h2) << (4))) | (f_ivc2_ccrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_ccrn) = f_ivc2_ccrn;
  FLD (f_ivc2_crm) = f_ivc2_crm;
  FLD (i_ivc2rm) = & current_cpu->hardware.h_gpr[f_ivc2_crm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmovc_rn_ccrm_p0)\t"
        << " f_ivc2_ccrn:0x" << hex << f_ivc2_ccrn << dec
        << " f_ivc2_crm:0x" << hex << f_ivc2_crm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_ivc2rm) = f_ivc2_crm;
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cmovh_crn_rm_p0 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
    UINT f_ivc2_ccrn_lo;
    UINT f_ivc2_crm;
    UINT f_ivc2_ccrn_h1;
    UINT f_ivc2_crnx;

    f_ivc2_ccrn_lo = EXTRACT_MSB0_UINT (insn, 32, 0, 4);
    f_ivc2_crm = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_ivc2_ccrn_h1 = EXTRACT_MSB0_UINT (insn, 32, 20, 1);
  f_ivc2_crnx = ((((f_ivc2_ccrn_h1) << (4))) | (f_ivc2_ccrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_crnx) = f_ivc2_crnx;
  FLD (f_ivc2_crm) = f_ivc2_crm;
  FLD (i_ivc2rm) = & current_cpu->hardware.h_gpr[f_ivc2_crm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmovh_crn_rm_p0)\t"
        << " f_ivc2_crnx:0x" << hex << f_ivc2_crnx << dec
        << " f_ivc2_crm:0x" << hex << f_ivc2_crm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_ivc2rm) = f_ivc2_crm;
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_c0nop_P0_P0S (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_c0nop_P0_P0S)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpfsftbi_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
    UINT f_ivc2_3u5;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u18;
    UINT f_ivc2_5u23;

    f_ivc2_3u5 = EXTRACT_MSB0_UINT (insn, 32, 5, 3);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u18 = EXTRACT_MSB0_UINT (insn, 32, 18, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u18) = f_ivc2_5u18;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_3u5) = f_ivc2_3u5;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpfsftbi_P0_P1)\t"
        << " f_ivc2_5u18:0x" << hex << f_ivc2_5u18 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_3u5:0x" << hex << f_ivc2_3u5 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpacmpeq_b_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u18;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u18 = EXTRACT_MSB0_UINT (insn, 32, 18, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u18) = f_ivc2_5u18;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpacmpeq_b_P0_P1)\t"
        << " f_ivc2_5u18:0x" << hex << f_ivc2_5u18 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cdadd3_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u18;
    UINT f_ivc2_5u23;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u18 = EXTRACT_MSB0_UINT (insn, 32, 18, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u18) = f_ivc2_5u18;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cdadd3_P0_P1)\t"
        << " f_ivc2_5u18:0x" << hex << f_ivc2_5u18 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpssub3_h_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u18;
    UINT f_ivc2_5u23;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u18 = EXTRACT_MSB0_UINT (insn, 32, 18, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u18) = f_ivc2_5u18;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpssub3_h_P0_P1)\t"
        << " f_ivc2_5u18:0x" << hex << f_ivc2_5u18 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpsrli3_b_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
    UINT f_ivc2_3u5;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;

    f_ivc2_3u5 = EXTRACT_MSB0_UINT (insn, 32, 5, 3);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_3u5) = f_ivc2_3u5;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpsrli3_b_P0_P1)\t"
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_3u5:0x" << hex << f_ivc2_3u5 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpsrli3_h_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
    UINT f_ivc2_4u4;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;

    f_ivc2_4u4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_4u4) = f_ivc2_4u4;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpsrli3_h_P0_P1)\t"
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_4u4:0x" << hex << f_ivc2_4u4 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpsrli3_w_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
    UINT f_ivc2_5u3;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;

    f_ivc2_5u3 = EXTRACT_MSB0_UINT (insn, 32, 3, 5);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_5u3) = f_ivc2_5u3;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpsrli3_w_P0_P1)\t"
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_5u3:0x" << hex << f_ivc2_5u3 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cdsrli3_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
    UINT f_ivc2_6u2;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;

    f_ivc2_6u2 = EXTRACT_MSB0_UINT (insn, 32, 2, 6);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_6u2) = f_ivc2_6u2;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cdsrli3_P0_P1)\t"
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << " f_ivc2_6u2:0x" << hex << f_ivc2_6u2 << dec
        << " f_ivc2_5u23:0x" << hex << f_ivc2_5u23 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpmovi_h_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
    UINT f_ivc2_8u0;
    UINT f_ivc2_5u13;
    UINT f_ivc2_8u20;
    INT f_ivc2_simm16p0;

    f_ivc2_8u0 = EXTRACT_MSB0_UINT (insn, 32, 0, 8);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_8u20 = EXTRACT_MSB0_UINT (insn, 32, 20, 8);
{
  f_ivc2_simm16p0 = ((f_ivc2_8u20) | (((f_ivc2_8u0) << (8))));
}

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_simm16p0) = f_ivc2_simm16p0;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmovi_h_P0_P1)\t"
        << " f_ivc2_simm16p0:0x" << hex << f_ivc2_simm16p0 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_48_extract_sfmt_cpmoviu_w_P0_P1 (mepcop1_48_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn){
    mepcop1_48_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
    UINT f_ivc2_8u0;
    UINT f_ivc2_5u13;
    UINT f_ivc2_8u20;
    UINT f_ivc2_imm16p0;

    f_ivc2_8u0 = EXTRACT_MSB0_UINT (insn, 32, 0, 8);
    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_8u20 = EXTRACT_MSB0_UINT (insn, 32, 20, 8);
{
  f_ivc2_imm16p0 = ((f_ivc2_8u20) | (((f_ivc2_8u0) << (8))));
}

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_imm16p0) = f_ivc2_imm16p0;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmoviu_w_P0_P1)\t"
        << " f_ivc2_imm16p0:0x" << hex << f_ivc2_imm16p0 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

