/* Simulator instruction decoder for mepcop1_16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext1.h"

using namespace mep_ext1; // FIXME: namespace organization still wip


// The instruction descriptor array. 

mepcop1_16_idesc mepcop1_16_idesc::idesc_table[MEPCOP1_16_INSN_CPMOVI_B_P0S_P1 + 1] =
{
  { mepcop1_16_sem_x_invalid, "X_INVALID", MEPCOP1_16_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_CORE) } },
  { mepcop1_16_sem_c0nop_P0_P0S, "C0NOP_P0_P0S", MEPCOP1_16_INSN_C0NOP_P0_P0S, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x28" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0)|(1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpadd3_b_P0S_P1, "CPADD3_B_P0S_P1", MEPCOP1_16_INSN_CPADD3_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpadd3_h_P0S_P1, "CPADD3_H_P0S_P1", MEPCOP1_16_INSN_CPADD3_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpadd3_w_P0S_P1, "CPADD3_W_P0S_P1", MEPCOP1_16_INSN_CPADD3_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpunpacku_b_P0S_P1, "CPUNPACKU_B_P0S_P1", MEPCOP1_16_INSN_CPUNPACKU_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpunpacku_h_P0S_P1, "CPUNPACKU_H_P0S_P1", MEPCOP1_16_INSN_CPUNPACKU_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4UHI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpunpacku_w_P0S_P1, "CPUNPACKU_W_P0S_P1", MEPCOP1_16_INSN_CPUNPACKU_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2USI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpunpackl_b_P0S_P1, "CPUNPACKL_B_P0S_P1", MEPCOP1_16_INSN_CPUNPACKL_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpunpackl_h_P0S_P1, "CPUNPACKL_H_P0S_P1", MEPCOP1_16_INSN_CPUNPACKL_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpunpackl_w_P0S_P1, "CPUNPACKL_W_P0S_P1", MEPCOP1_16_INSN_CPUNPACKL_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpsel_P0S_P1, "CPSEL_P0S_P1", MEPCOP1_16_INSN_CPSEL_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpfsftbs0_P0S_P1, "CPFSFTBS0_P0S_P1", MEPCOP1_16_INSN_CPFSFTBS0_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpfsftbs1_P0S_P1, "CPFSFTBS1_P0S_P1", MEPCOP1_16_INSN_CPFSFTBS1_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmov_P0S_P1, "CPMOV_P0S_P1", MEPCOP1_16_INSN_CPMOV_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpabsz_b_P0S_P1, "CPABSZ_B_P0S_P1", MEPCOP1_16_INSN_CPABSZ_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpabsz_h_P0S_P1, "CPABSZ_H_P0S_P1", MEPCOP1_16_INSN_CPABSZ_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpabsz_w_P0S_P1, "CPABSZ_W_P0S_P1", MEPCOP1_16_INSN_CPABSZ_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpldz_h_P0S_P1, "CPLDZ_H_P0S_P1", MEPCOP1_16_INSN_CPLDZ_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpldz_w_P0S_P1, "CPLDZ_W_P0S_P1", MEPCOP1_16_INSN_CPLDZ_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpnorm_h_P0S_P1, "CPNORM_H_P0S_P1", MEPCOP1_16_INSN_CPNORM_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpnorm_w_P0S_P1, "CPNORM_W_P0S_P1", MEPCOP1_16_INSN_CPNORM_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cphaddu_b_P0S_P1, "CPHADDU_B_P0S_P1", MEPCOP1_16_INSN_CPHADDU_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cphadd_b_P0S_P1, "CPHADD_B_P0S_P1", MEPCOP1_16_INSN_CPHADD_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cphadd_h_P0S_P1, "CPHADD_H_P0S_P1", MEPCOP1_16_INSN_CPHADD_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cphadd_w_P0S_P1, "CPHADD_W_P0S_P1", MEPCOP1_16_INSN_CPHADD_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpccadd_b_P0S_P1, "CPCCADD_B_P0S_P1", MEPCOP1_16_INSN_CPCCADD_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRSTCOPY, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpbcast_b_P0S_P1, "CPBCAST_B_P0S_P1", MEPCOP1_16_INSN_CPBCAST_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpbcast_h_P0S_P1, "CPBCAST_H_P0S_P1", MEPCOP1_16_INSN_CPBCAST_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpbcast_w_P0S_P1, "CPBCAST_W_P0S_P1", MEPCOP1_16_INSN_CPBCAST_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextuu_b_P0S_P1, "CPEXTUU_B_P0S_P1", MEPCOP1_16_INSN_CPEXTUU_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextu_b_P0S_P1, "CPEXTU_B_P0S_P1", MEPCOP1_16_INSN_CPEXTU_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextuu_h_P0S_P1, "CPEXTUU_H_P0S_P1", MEPCOP1_16_INSN_CPEXTUU_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4UHI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextu_h_P0S_P1, "CPEXTU_H_P0S_P1", MEPCOP1_16_INSN_CPEXTU_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4UHI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextlu_b_P0S_P1, "CPEXTLU_B_P0S_P1", MEPCOP1_16_INSN_CPEXTLU_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextl_b_P0S_P1, "CPEXTL_B_P0S_P1", MEPCOP1_16_INSN_CPEXTL_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextlu_h_P0S_P1, "CPEXTLU_H_P0S_P1", MEPCOP1_16_INSN_CPEXTLU_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4UHI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpextl_h_P0S_P1, "CPEXTL_H_P0S_P1", MEPCOP1_16_INSN_CPEXTL_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcastub_h_P0S_P1, "CPCASTUB_H_P0S_P1", MEPCOP1_16_INSN_CPCASTUB_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcastb_h_P0S_P1, "CPCASTB_H_P0S_P1", MEPCOP1_16_INSN_CPCASTB_H_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcastub_w_P0S_P1, "CPCASTUB_W_P0S_P1", MEPCOP1_16_INSN_CPCASTUB_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcastb_w_P0S_P1, "CPCASTB_W_P0S_P1", MEPCOP1_16_INSN_CPCASTB_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcastuh_w_P0S_P1, "CPCASTUH_W_P0S_P1", MEPCOP1_16_INSN_CPCASTUH_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcasth_w_P0S_P1, "CPCASTH_W_P0S_P1", MEPCOP1_16_INSN_CPCASTH_W_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cdcastuw_P0S_P1, "CDCASTUW_P0S_P1", MEPCOP1_16_INSN_CDCASTUW_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cdcastw_P0S_P1, "CDCASTW_P0S_P1", MEPCOP1_16_INSN_CDCASTW_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmovfrcsar0_P0S_P1, "CPMOVFRCSAR0_P0S_P1", MEPCOP1_16_INSN_CPMOVFRCSAR0_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmovfrcsar1_P0S_P1, "CPMOVFRCSAR1_P0S_P1", MEPCOP1_16_INSN_CPMOVFRCSAR1_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmovfrcc_P0S_P1, "CPMOVFRCC_P0S_P1", MEPCOP1_16_INSN_CPMOVFRCC_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmovtocsar0_P0S_P1, "CPMOVTOCSAR0_P0S_P1", MEPCOP1_16_INSN_CPMOVTOCSAR0_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmovtocsar1_P0S_P1, "CPMOVTOCSAR1_P0S_P1", MEPCOP1_16_INSN_CPMOVTOCSAR1_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpmovtocc_P0S_P1, "CPMOVTOCC_P0S_P1", MEPCOP1_16_INSN_CPMOVTOCC_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpeqz_b_P0S_P1, "CPCMPEQZ_B_P0S_P1", MEPCOP1_16_INSN_CPCMPEQZ_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpeq_b_P0S_P1, "CPCMPEQ_B_P0S_P1", MEPCOP1_16_INSN_CPCMPEQ_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpeq_h_P0S_P1, "CPCMPEQ_H_P0S_P1", MEPCOP1_16_INSN_CPCMPEQ_H_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpeq_w_P0S_P1, "CPCMPEQ_W_P0S_P1", MEPCOP1_16_INSN_CPCMPEQ_W_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpne_b_P0S_P1, "CPCMPNE_B_P0S_P1", MEPCOP1_16_INSN_CPCMPNE_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpne_h_P0S_P1, "CPCMPNE_H_P0S_P1", MEPCOP1_16_INSN_CPCMPNE_H_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpne_w_P0S_P1, "CPCMPNE_W_P0S_P1", MEPCOP1_16_INSN_CPCMPNE_W_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgtu_b_P0S_P1, "CPCMPGTU_B_P0S_P1", MEPCOP1_16_INSN_CPCMPGTU_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgt_b_P0S_P1, "CPCMPGT_B_P0S_P1", MEPCOP1_16_INSN_CPCMPGT_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgt_h_P0S_P1, "CPCMPGT_H_P0S_P1", MEPCOP1_16_INSN_CPCMPGT_H_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgtu_w_P0S_P1, "CPCMPGTU_W_P0S_P1", MEPCOP1_16_INSN_CPCMPGTU_W_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2USI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgt_w_P0S_P1, "CPCMPGT_W_P0S_P1", MEPCOP1_16_INSN_CPCMPGT_W_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgeu_b_P0S_P1, "CPCMPGEU_B_P0S_P1", MEPCOP1_16_INSN_CPCMPGEU_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpge_b_P0S_P1, "CPCMPGE_B_P0S_P1", MEPCOP1_16_INSN_CPCMPGE_B_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpge_h_P0S_P1, "CPCMPGE_H_P0S_P1", MEPCOP1_16_INSN_CPCMPGE_H_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpgeu_w_P0S_P1, "CPCMPGEU_W_P0S_P1", MEPCOP1_16_INSN_CPCMPGEU_W_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2USI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpcmpge_w_P0S_P1, "CPCMPGE_W_P0S_P1", MEPCOP1_16_INSN_CPCMPGE_W_P0S_P1, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },
  { mepcop1_16_sem_cpadda0u_b_P0S, "CPADDA0U_B_P0S", MEPCOP1_16_INSN_CPADDA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpadda0_b_P0S, "CPADDA0_B_P0S", MEPCOP1_16_INSN_CPADDA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaddua0_h_P0S, "CPADDUA0_H_P0S", MEPCOP1_16_INSN_CPADDUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaddla0_h_P0S, "CPADDLA0_H_P0S", MEPCOP1_16_INSN_CPADDLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaddaca0u_b_P0S, "CPADDACA0U_B_P0S", MEPCOP1_16_INSN_CPADDACA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaddaca0_b_P0S, "CPADDACA0_B_P0S", MEPCOP1_16_INSN_CPADDACA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaddacua0_h_P0S, "CPADDACUA0_H_P0S", MEPCOP1_16_INSN_CPADDACUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaddacla0_h_P0S, "CPADDACLA0_H_P0S", MEPCOP1_16_INSN_CPADDACLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsuba0u_b_P0S, "CPSUBA0U_B_P0S", MEPCOP1_16_INSN_CPSUBA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsuba0_b_P0S, "CPSUBA0_B_P0S", MEPCOP1_16_INSN_CPSUBA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsubua0_h_P0S, "CPSUBUA0_H_P0S", MEPCOP1_16_INSN_CPSUBUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsubla0_h_P0S, "CPSUBLA0_H_P0S", MEPCOP1_16_INSN_CPSUBLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsubaca0u_b_P0S, "CPSUBACA0U_B_P0S", MEPCOP1_16_INSN_CPSUBACA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsubaca0_b_P0S, "CPSUBACA0_B_P0S", MEPCOP1_16_INSN_CPSUBACA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsubacua0_h_P0S, "CPSUBACUA0_H_P0S", MEPCOP1_16_INSN_CPSUBACUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsubacla0_h_P0S, "CPSUBACLA0_H_P0S", MEPCOP1_16_INSN_CPSUBACLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpabsa0u_b_P0S, "CPABSA0U_B_P0S", MEPCOP1_16_INSN_CPABSA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpabsa0_b_P0S, "CPABSA0_B_P0S", MEPCOP1_16_INSN_CPABSA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpabsua0_h_P0S, "CPABSUA0_H_P0S", MEPCOP1_16_INSN_CPABSUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpabsla0_h_P0S, "CPABSLA0_H_P0S", MEPCOP1_16_INSN_CPABSLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsada0u_b_P0S, "CPSADA0U_B_P0S", MEPCOP1_16_INSN_CPSADA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsada0_b_P0S, "CPSADA0_B_P0S", MEPCOP1_16_INSN_CPSADA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsadua0_h_P0S, "CPSADUA0_H_P0S", MEPCOP1_16_INSN_CPSADUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsadla0_h_P0S, "CPSADLA0_H_P0S", MEPCOP1_16_INSN_CPSADLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpseta0_h_P0S, "CPSETA0_H_P0S", MEPCOP1_16_INSN_CPSETA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsetua0_w_P0S, "CPSETUA0_W_P0S", MEPCOP1_16_INSN_CPSETUA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsetla0_w_P0S, "CPSETLA0_W_P0S", MEPCOP1_16_INSN_CPSETLA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmova0_b_P0S, "CPMOVA0_B_P0S", MEPCOP1_16_INSN_CPMOVA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovua0_h_P0S, "CPMOVUA0_H_P0S", MEPCOP1_16_INSN_CPMOVUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovla0_h_P0S, "CPMOVLA0_H_P0S", MEPCOP1_16_INSN_CPMOVLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovuua0_w_P0S, "CPMOVUUA0_W_P0S", MEPCOP1_16_INSN_CPMOVUUA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovula0_w_P0S, "CPMOVULA0_W_P0S", MEPCOP1_16_INSN_CPMOVULA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovlua0_w_P0S, "CPMOVLUA0_W_P0S", MEPCOP1_16_INSN_CPMOVLUA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovlla0_w_P0S, "CPMOVLLA0_W_P0S", MEPCOP1_16_INSN_CPMOVLLA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cppacka0u_b_P0S, "CPPACKA0U_B_P0S", MEPCOP1_16_INSN_CPPACKA0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cppacka0_b_P0S, "CPPACKA0_B_P0S", MEPCOP1_16_INSN_CPPACKA0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cppackua0_h_P0S, "CPPACKUA0_H_P0S", MEPCOP1_16_INSN_CPPACKUA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cppackla0_h_P0S, "CPPACKLA0_H_P0S", MEPCOP1_16_INSN_CPPACKLA0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cppackua0_w_P0S, "CPPACKUA0_W_P0S", MEPCOP1_16_INSN_CPPACKUA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cppackla0_w_P0S, "CPPACKLA0_W_P0S", MEPCOP1_16_INSN_CPPACKLA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovhua0_w_P0S, "CPMOVHUA0_W_P0S", MEPCOP1_16_INSN_CPMOVHUA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovhla0_w_P0S, "CPMOVHLA0_W_P0S", MEPCOP1_16_INSN_CPMOVHLA0_W_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V2SI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpacsuma0_P0S, "CPACSUMA0_P0S", MEPCOP1_16_INSN_CPACSUMA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpaccpa0_P0S, "CPACCPA0_P0S", MEPCOP1_16_INSN_CPACCPA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsrla0_P0S, "CPSRLA0_P0S", MEPCOP1_16_INSN_CPSRLA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsraa0_P0S, "CPSRAA0_P0S", MEPCOP1_16_INSN_CPSRAA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpslla0_P0S, "CPSLLA0_P0S", MEPCOP1_16_INSN_CPSLLA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsrlia0_P0S, "CPSRLIA0_P0S", MEPCOP1_16_INSN_CPSRLIA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsraia0_P0S, "CPSRAIA0_P0S", MEPCOP1_16_INSN_CPSRAIA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpsllia0_P0S, "CPSLLIA0_P0S", MEPCOP1_16_INSN_CPSLLIA0_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_CP_DATA_BUS_INT, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftba0s0u_b_P0S, "CPFSFTBA0S0U_B_P0S", MEPCOP1_16_INSN_CPFSFTBA0S0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftba0s0_b_P0S, "CPFSFTBA0S0_B_P0S", MEPCOP1_16_INSN_CPFSFTBA0S0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftbua0s0_h_P0S, "CPFSFTBUA0S0_H_P0S", MEPCOP1_16_INSN_CPFSFTBUA0S0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftbla0s0_h_P0S, "CPFSFTBLA0S0_H_P0S", MEPCOP1_16_INSN_CPFSFTBLA0S0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfaca0s0u_b_P0S, "CPFACA0S0U_B_P0S", MEPCOP1_16_INSN_CPFACA0S0U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfaca0s0_b_P0S, "CPFACA0S0_B_P0S", MEPCOP1_16_INSN_CPFACA0S0_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfacua0s0_h_P0S, "CPFACUA0S0_H_P0S", MEPCOP1_16_INSN_CPFACUA0S0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfacla0s0_h_P0S, "CPFACLA0S0_H_P0S", MEPCOP1_16_INSN_CPFACLA0S0_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftba0s1u_b_P0S, "CPFSFTBA0S1U_B_P0S", MEPCOP1_16_INSN_CPFSFTBA0S1U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftba0s1_b_P0S, "CPFSFTBA0S1_B_P0S", MEPCOP1_16_INSN_CPFSFTBA0S1_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftbua0s1_h_P0S, "CPFSFTBUA0S1_H_P0S", MEPCOP1_16_INSN_CPFSFTBUA0S1_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfsftbla0s1_h_P0S, "CPFSFTBLA0S1_H_P0S", MEPCOP1_16_INSN_CPFSFTBLA0S1_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfaca0s1u_b_P0S, "CPFACA0S1U_B_P0S", MEPCOP1_16_INSN_CPFACA0S1U_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8UQI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfaca0s1_b_P0S, "CPFACA0S1_B_P0S", MEPCOP1_16_INSN_CPFACA0S1_B_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V8QI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfacua0s1_h_P0S, "CPFACUA0S1_H_P0S", MEPCOP1_16_INSN_CPFACUA0S1_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpfacla0s1_h_P0S, "CPFACLA0S1_H_P0S", MEPCOP1_16_INSN_CPFACLA0S1_H_P0S, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x20" }, CPTYPE_V4HI, CRET_VOID, 0, CONFIG_NONE, (1<<SLOTS_P0S) } },
  { mepcop1_16_sem_cpmovi_b_P0S_P1, "CPMOVI_B_P0S_P1", MEPCOP1_16_INSN_CPMOVI_B_P0S_P1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\x24" }, CPTYPE_V8QI, CRET_FIRST, 0, CONFIG_NONE, (1<<SLOTS_P0S)|(1<<SLOTS_P1) } },

};

// Given a canonical virtual insn id, return the target specific one.

mepcop1_16_insn_type
mepcop1_16_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return MEPCOP1_16_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return MEPCOP1_16_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
mepcop1_16_extract_sfmt_empty (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_c0nop_P0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpmov_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpccadd_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpmovtocsar0_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpmovtocsar1_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpmovtocc_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpadda0u_b_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpaddua0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpaddla0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpacsuma0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpaccpa0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpsrla0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpsrlia0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
static void
mepcop1_16_extract_sfmt_cpmovi_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);

// Fetch & decode instruction
void
mepcop1_16_scache::decode (mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn)
{
  /* Result of decoder.  */
  MEPCOP1_16_INSN_TYPE itype;

  {
    mepcop1_16_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 13) & (31 << 6)) | ((insn >> 7) & (1 << 5)) | ((insn >> 4) & (31 << 0)));
      switch (val)
      {
      case 0 :
        if ((entire_insn & 0xffffffff) == 0x0)
          { itype = MEPCOP1_16_INSN_C0NOP_P0_P0S; mepcop1_16_extract_sfmt_c0nop_P0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x80000)
          { itype = MEPCOP1_16_INSN_CPADD3_B_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 191 :
        if ((entire_insn & 0xfff8000f) == 0x100000)
          { itype = MEPCOP1_16_INSN_CPADD3_H_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x180000)
          { itype = MEPCOP1_16_INSN_CPADD3_W_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 256 : /* fall through */
      case 257 : /* fall through */
      case 258 : /* fall through */
      case 259 : /* fall through */
      case 260 : /* fall through */
      case 261 : /* fall through */
      case 262 : /* fall through */
      case 263 : /* fall through */
      case 264 : /* fall through */
      case 265 : /* fall through */
      case 266 : /* fall through */
      case 267 : /* fall through */
      case 268 : /* fall through */
      case 269 : /* fall through */
      case 270 : /* fall through */
      case 271 : /* fall through */
      case 272 : /* fall through */
      case 273 : /* fall through */
      case 274 : /* fall through */
      case 275 : /* fall through */
      case 276 : /* fall through */
      case 277 : /* fall through */
      case 278 : /* fall through */
      case 279 : /* fall through */
      case 280 : /* fall through */
      case 281 : /* fall through */
      case 282 : /* fall through */
      case 283 : /* fall through */
      case 284 : /* fall through */
      case 285 : /* fall through */
      case 286 : /* fall through */
      case 287 : /* fall through */
      case 288 : /* fall through */
      case 289 : /* fall through */
      case 290 : /* fall through */
      case 291 : /* fall through */
      case 292 : /* fall through */
      case 293 : /* fall through */
      case 294 : /* fall through */
      case 295 : /* fall through */
      case 296 : /* fall through */
      case 297 : /* fall through */
      case 298 : /* fall through */
      case 299 : /* fall through */
      case 300 : /* fall through */
      case 301 : /* fall through */
      case 302 : /* fall through */
      case 303 : /* fall through */
      case 304 : /* fall through */
      case 305 : /* fall through */
      case 306 : /* fall through */
      case 307 : /* fall through */
      case 308 : /* fall through */
      case 309 : /* fall through */
      case 310 : /* fall through */
      case 311 : /* fall through */
      case 312 : /* fall through */
      case 313 : /* fall through */
      case 314 : /* fall through */
      case 315 : /* fall through */
      case 316 : /* fall through */
      case 317 : /* fall through */
      case 318 : /* fall through */
      case 319 :
        if ((entire_insn & 0xfff8000f) == 0x200000)
          { itype = MEPCOP1_16_INSN_CPSEL_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x280000)
          { itype = MEPCOP1_16_INSN_CPUNPACKU_B_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 384 : /* fall through */
      case 385 : /* fall through */
      case 386 : /* fall through */
      case 387 : /* fall through */
      case 388 : /* fall through */
      case 389 : /* fall through */
      case 390 : /* fall through */
      case 391 : /* fall through */
      case 392 : /* fall through */
      case 393 : /* fall through */
      case 394 : /* fall through */
      case 395 : /* fall through */
      case 396 : /* fall through */
      case 397 : /* fall through */
      case 398 : /* fall through */
      case 399 : /* fall through */
      case 400 : /* fall through */
      case 401 : /* fall through */
      case 402 : /* fall through */
      case 403 : /* fall through */
      case 404 : /* fall through */
      case 405 : /* fall through */
      case 406 : /* fall through */
      case 407 : /* fall through */
      case 408 : /* fall through */
      case 409 : /* fall through */
      case 410 : /* fall through */
      case 411 : /* fall through */
      case 412 : /* fall through */
      case 413 : /* fall through */
      case 414 : /* fall through */
      case 415 : /* fall through */
      case 416 : /* fall through */
      case 417 : /* fall through */
      case 418 : /* fall through */
      case 419 : /* fall through */
      case 420 : /* fall through */
      case 421 : /* fall through */
      case 422 : /* fall through */
      case 423 : /* fall through */
      case 424 : /* fall through */
      case 425 : /* fall through */
      case 426 : /* fall through */
      case 427 : /* fall through */
      case 428 : /* fall through */
      case 429 : /* fall through */
      case 430 : /* fall through */
      case 431 : /* fall through */
      case 432 : /* fall through */
      case 433 : /* fall through */
      case 434 : /* fall through */
      case 435 : /* fall through */
      case 436 : /* fall through */
      case 437 : /* fall through */
      case 438 : /* fall through */
      case 439 : /* fall through */
      case 440 : /* fall through */
      case 441 : /* fall through */
      case 442 : /* fall through */
      case 443 : /* fall through */
      case 444 : /* fall through */
      case 445 : /* fall through */
      case 446 : /* fall through */
      case 447 :
        if ((entire_insn & 0xfff8000f) == 0x300000)
          { itype = MEPCOP1_16_INSN_CPUNPACKU_H_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x380000)
          { itype = MEPCOP1_16_INSN_CPUNPACKU_W_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x480000)
          { itype = MEPCOP1_16_INSN_CPUNPACKL_B_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x500000)
          { itype = MEPCOP1_16_INSN_CPUNPACKL_H_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x580000)
          { itype = MEPCOP1_16_INSN_CPUNPACKL_W_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x600000)
          { itype = MEPCOP1_16_INSN_CPFSFTBS0_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        if ((entire_insn & 0xfff8000f) == 0x680000)
          { itype = MEPCOP1_16_INSN_CPFSFTBS1_P0S_P1; mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 1055 :
        {
          unsigned int val = (((insn >> 10) & (1 << 3)) | ((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfff83e0f) == 0x800000)
              { itype = MEPCOP1_16_INSN_CPMOV_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfff83e0f) == 0x800200)
              { itype = MEPCOP1_16_INSN_CPABSZ_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfff83e0f) == 0x800400)
              { itype = MEPCOP1_16_INSN_CPABSZ_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff83e0f) == 0x800600)
              { itype = MEPCOP1_16_INSN_CPABSZ_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfff83e0f) == 0x800800)
              { itype = MEPCOP1_16_INSN_CPLDZ_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfff83e0f) == 0x800a00)
              { itype = MEPCOP1_16_INSN_CPLDZ_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfff83e0f) == 0x800c00)
              { itype = MEPCOP1_16_INSN_CPNORM_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfff83e0f) == 0x800e00)
              { itype = MEPCOP1_16_INSN_CPNORM_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xfff83e0f) == 0x802000)
              { itype = MEPCOP1_16_INSN_CPEXTUU_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xfff83e0f) == 0x802200)
              { itype = MEPCOP1_16_INSN_CPEXTU_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            if ((entire_insn & 0xfff83e0f) == 0x802400)
              { itype = MEPCOP1_16_INSN_CPEXTUU_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xfff83e0f) == 0x802600)
              { itype = MEPCOP1_16_INSN_CPEXTU_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            if ((entire_insn & 0xfff83e0f) == 0x802800)
              { itype = MEPCOP1_16_INSN_CPEXTLU_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfff83e0f) == 0x802a00)
              { itype = MEPCOP1_16_INSN_CPEXTL_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            if ((entire_insn & 0xfff83e0f) == 0x802c00)
              { itype = MEPCOP1_16_INSN_CPEXTLU_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            if ((entire_insn & 0xfff83e0f) == 0x802e00)
              { itype = MEPCOP1_16_INSN_CPEXTL_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1056 :
        {
          unsigned int val = (((insn >> 10) & (1 << 3)) | ((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfff83e0f) == 0x801000)
              { itype = MEPCOP1_16_INSN_CPHADDU_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfff83e0f) == 0x801200)
              { itype = MEPCOP1_16_INSN_CPHADD_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfff83e0f) == 0x801400)
              { itype = MEPCOP1_16_INSN_CPHADD_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff83e0f) == 0x801600)
              { itype = MEPCOP1_16_INSN_CPHADD_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfff83fff) == 0x801800)
              { itype = MEPCOP1_16_INSN_CPCCADD_B_P0S_P1; mepcop1_16_extract_sfmt_cpccadd_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfff83e0f) == 0x801a00)
              { itype = MEPCOP1_16_INSN_CPBCAST_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfff83e0f) == 0x801c00)
              { itype = MEPCOP1_16_INSN_CPBCAST_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfff83e0f) == 0x801e00)
              { itype = MEPCOP1_16_INSN_CPBCAST_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xfff83e0f) == 0x803000)
              { itype = MEPCOP1_16_INSN_CPCASTUB_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xfff83e0f) == 0x803200)
              { itype = MEPCOP1_16_INSN_CPCASTB_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            if ((entire_insn & 0xfff83e0f) == 0x803400)
              { itype = MEPCOP1_16_INSN_CDCASTUW_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xfff83e0f) == 0x803600)
              { itype = MEPCOP1_16_INSN_CDCASTW_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            if ((entire_insn & 0xfff83e0f) == 0x803800)
              { itype = MEPCOP1_16_INSN_CPCASTUB_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfff83e0f) == 0x803a00)
              { itype = MEPCOP1_16_INSN_CPCASTB_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            if ((entire_insn & 0xfff83e0f) == 0x803c00)
              { itype = MEPCOP1_16_INSN_CPCASTUH_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            if ((entire_insn & 0xfff83e0f) == 0x803e00)
              { itype = MEPCOP1_16_INSN_CPCASTH_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
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
      case 1087 :
        {
          unsigned int val = (((insn >> 10) & (1 << 3)) | ((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfff83e0f) == 0x801000)
              { itype = MEPCOP1_16_INSN_CPHADDU_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfff83e0f) == 0x801200)
              { itype = MEPCOP1_16_INSN_CPHADD_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfff83e0f) == 0x801400)
              { itype = MEPCOP1_16_INSN_CPHADD_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff83e0f) == 0x801600)
              { itype = MEPCOP1_16_INSN_CPHADD_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfff83e0f) == 0x801a00)
              { itype = MEPCOP1_16_INSN_CPBCAST_B_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfff83e0f) == 0x801c00)
              { itype = MEPCOP1_16_INSN_CPBCAST_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfff83e0f) == 0x801e00)
              { itype = MEPCOP1_16_INSN_CPBCAST_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xfff83e0f) == 0x803000)
              { itype = MEPCOP1_16_INSN_CPCASTUB_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xfff83e0f) == 0x803200)
              { itype = MEPCOP1_16_INSN_CPCASTB_H_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            if ((entire_insn & 0xfff83e0f) == 0x803400)
              { itype = MEPCOP1_16_INSN_CDCASTUW_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xfff83e0f) == 0x803600)
              { itype = MEPCOP1_16_INSN_CDCASTW_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            if ((entire_insn & 0xfff83e0f) == 0x803800)
              { itype = MEPCOP1_16_INSN_CPCASTUB_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfff83e0f) == 0x803a00)
              { itype = MEPCOP1_16_INSN_CPCASTB_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            if ((entire_insn & 0xfff83e0f) == 0x803c00)
              { itype = MEPCOP1_16_INSN_CPCASTUH_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 :
            if ((entire_insn & 0xfff83e0f) == 0x803e00)
              { itype = MEPCOP1_16_INSN_CPCASTH_W_P0S_P1; mepcop1_16_extract_sfmt_cpmov_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1088 :
        {
          unsigned int val = (((insn >> 12) & (1 << 1)) | ((insn >> 9) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffffe0f) == 0x880000)
              { itype = MEPCOP1_16_INSN_CPMOVFRCSAR0_P0S_P1; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfffffe0f) == 0x880200)
              { itype = MEPCOP1_16_INSN_CPMOVFRCC_P0S_P1; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfff83fff) == 0x882000)
              { itype = MEPCOP1_16_INSN_CPMOVTOCSAR0_P0S_P1; mepcop1_16_extract_sfmt_cpmovtocsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfff83fff) == 0x882200)
              { itype = MEPCOP1_16_INSN_CPMOVTOCC_P0S_P1; mepcop1_16_extract_sfmt_cpmovtocc_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
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
      case 1119 :
        {
          unsigned int val = (((insn >> 9) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffffe0f) == 0x880000)
              { itype = MEPCOP1_16_INSN_CPMOVFRCSAR0_P0S_P1; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfffffe0f) == 0x880200)
              { itype = MEPCOP1_16_INSN_CPMOVFRCC_P0S_P1; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1120 :
        {
          unsigned int val = (((insn >> 13) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffffe0f) == 0x881e00)
              { itype = MEPCOP1_16_INSN_CPMOVFRCSAR1_P0S_P1; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfff83fff) == 0x883e00)
              { itype = MEPCOP1_16_INSN_CPMOVTOCSAR1_P0S_P1; mepcop1_16_extract_sfmt_cpmovtocsar1_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
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
        if ((entire_insn & 0xfffffe0f) == 0x881e00)
          { itype = MEPCOP1_16_INSN_CPMOVFRCSAR1_P0S_P1; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1152 : /* fall through */
      case 1184 :
        if ((entire_insn & 0xfff801ff) == 0x900000)
          { itype = MEPCOP1_16_INSN_CPCMPEQZ_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1153 : /* fall through */
      case 1185 :
        if ((entire_insn & 0xfff801ff) == 0x900010)
          { itype = MEPCOP1_16_INSN_CPCMPEQ_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1155 : /* fall through */
      case 1187 :
        if ((entire_insn & 0xfff801ff) == 0x900030)
          { itype = MEPCOP1_16_INSN_CPCMPEQ_H_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1157 : /* fall through */
      case 1189 :
        if ((entire_insn & 0xfff801ff) == 0x900050)
          { itype = MEPCOP1_16_INSN_CPCMPEQ_W_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1161 : /* fall through */
      case 1193 :
        if ((entire_insn & 0xfff801ff) == 0x900090)
          { itype = MEPCOP1_16_INSN_CPCMPNE_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1163 : /* fall through */
      case 1195 :
        if ((entire_insn & 0xfff801ff) == 0x9000b0)
          { itype = MEPCOP1_16_INSN_CPCMPNE_H_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1165 : /* fall through */
      case 1197 :
        if ((entire_insn & 0xfff801ff) == 0x9000d0)
          { itype = MEPCOP1_16_INSN_CPCMPNE_W_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1168 : /* fall through */
      case 1200 :
        if ((entire_insn & 0xfff801ff) == 0x900100)
          { itype = MEPCOP1_16_INSN_CPCMPGTU_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1169 : /* fall through */
      case 1201 :
        if ((entire_insn & 0xfff801ff) == 0x900110)
          { itype = MEPCOP1_16_INSN_CPCMPGT_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1171 : /* fall through */
      case 1203 :
        if ((entire_insn & 0xfff801ff) == 0x900130)
          { itype = MEPCOP1_16_INSN_CPCMPGT_H_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1172 : /* fall through */
      case 1204 :
        if ((entire_insn & 0xfff801ff) == 0x900140)
          { itype = MEPCOP1_16_INSN_CPCMPGTU_W_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1173 : /* fall through */
      case 1205 :
        if ((entire_insn & 0xfff801ff) == 0x900150)
          { itype = MEPCOP1_16_INSN_CPCMPGT_W_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1176 : /* fall through */
      case 1208 :
        if ((entire_insn & 0xfff801ff) == 0x900180)
          { itype = MEPCOP1_16_INSN_CPCMPGEU_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1177 : /* fall through */
      case 1209 :
        if ((entire_insn & 0xfff801ff) == 0x900190)
          { itype = MEPCOP1_16_INSN_CPCMPGE_B_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1179 : /* fall through */
      case 1211 :
        if ((entire_insn & 0xfff801ff) == 0x9001b0)
          { itype = MEPCOP1_16_INSN_CPCMPGE_H_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1180 : /* fall through */
      case 1212 :
        if ((entire_insn & 0xfff801ff) == 0x9001c0)
          { itype = MEPCOP1_16_INSN_CPCMPGEU_W_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1181 : /* fall through */
      case 1213 :
        if ((entire_insn & 0xfff801ff) == 0x9001d0)
          { itype = MEPCOP1_16_INSN_CPCMPGE_W_P0S_P1; mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 1439 :
        if ((entire_insn & 0xfff8300f) == 0xb00000)
          { itype = MEPCOP1_16_INSN_CPMOVI_B_P0S_P1; mepcop1_16_extract_sfmt_cpmovi_b_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1536 : /* fall through */
      case 1568 :
        if ((entire_insn & 0xfff801ff) == 0xc00000)
          { itype = MEPCOP1_16_INSN_CPADDA0U_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1537 : /* fall through */
      case 1569 :
        if ((entire_insn & 0xfff801ff) == 0xc00010)
          { itype = MEPCOP1_16_INSN_CPADDA0_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1538 : /* fall through */
      case 1570 :
        if ((entire_insn & 0xfff801ff) == 0xc00020)
          { itype = MEPCOP1_16_INSN_CPADDUA0_H_P0S; mepcop1_16_extract_sfmt_cpaddua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1539 : /* fall through */
      case 1571 :
        if ((entire_insn & 0xfff801ff) == 0xc00030)
          { itype = MEPCOP1_16_INSN_CPADDLA0_H_P0S; mepcop1_16_extract_sfmt_cpaddla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1540 : /* fall through */
      case 1572 :
        if ((entire_insn & 0xfff801ff) == 0xc00040)
          { itype = MEPCOP1_16_INSN_CPADDACA0U_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1541 : /* fall through */
      case 1573 :
        if ((entire_insn & 0xfff801ff) == 0xc00050)
          { itype = MEPCOP1_16_INSN_CPADDACA0_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1542 : /* fall through */
      case 1574 :
        if ((entire_insn & 0xfff801ff) == 0xc00060)
          { itype = MEPCOP1_16_INSN_CPADDACUA0_H_P0S; mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1543 : /* fall through */
      case 1575 :
        if ((entire_insn & 0xfff801ff) == 0xc00070)
          { itype = MEPCOP1_16_INSN_CPADDACLA0_H_P0S; mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1544 : /* fall through */
      case 1576 :
        if ((entire_insn & 0xfff801ff) == 0xc00080)
          { itype = MEPCOP1_16_INSN_CPSUBA0U_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1545 : /* fall through */
      case 1577 :
        if ((entire_insn & 0xfff801ff) == 0xc00090)
          { itype = MEPCOP1_16_INSN_CPSUBA0_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1546 : /* fall through */
      case 1578 :
        if ((entire_insn & 0xfff801ff) == 0xc000a0)
          { itype = MEPCOP1_16_INSN_CPSUBUA0_H_P0S; mepcop1_16_extract_sfmt_cpaddua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1547 : /* fall through */
      case 1579 :
        if ((entire_insn & 0xfff801ff) == 0xc000b0)
          { itype = MEPCOP1_16_INSN_CPSUBLA0_H_P0S; mepcop1_16_extract_sfmt_cpaddla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1548 : /* fall through */
      case 1580 :
        if ((entire_insn & 0xfff801ff) == 0xc000c0)
          { itype = MEPCOP1_16_INSN_CPSUBACA0U_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1549 : /* fall through */
      case 1581 :
        if ((entire_insn & 0xfff801ff) == 0xc000d0)
          { itype = MEPCOP1_16_INSN_CPSUBACA0_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1550 : /* fall through */
      case 1582 :
        if ((entire_insn & 0xfff801ff) == 0xc000e0)
          { itype = MEPCOP1_16_INSN_CPSUBACUA0_H_P0S; mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1551 : /* fall through */
      case 1583 :
        if ((entire_insn & 0xfff801ff) == 0xc000f0)
          { itype = MEPCOP1_16_INSN_CPSUBACLA0_H_P0S; mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1552 : /* fall through */
      case 1584 :
        if ((entire_insn & 0xfff801ff) == 0xc00100)
          { itype = MEPCOP1_16_INSN_CPABSA0U_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1553 : /* fall through */
      case 1585 :
        if ((entire_insn & 0xfff801ff) == 0xc00110)
          { itype = MEPCOP1_16_INSN_CPABSA0_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1554 : /* fall through */
      case 1586 :
        if ((entire_insn & 0xfff801ff) == 0xc00120)
          { itype = MEPCOP1_16_INSN_CPABSUA0_H_P0S; mepcop1_16_extract_sfmt_cpaddua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1555 : /* fall through */
      case 1587 :
        if ((entire_insn & 0xfff801ff) == 0xc00130)
          { itype = MEPCOP1_16_INSN_CPABSLA0_H_P0S; mepcop1_16_extract_sfmt_cpaddla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1556 : /* fall through */
      case 1588 :
        if ((entire_insn & 0xfff801ff) == 0xc00140)
          { itype = MEPCOP1_16_INSN_CPSADA0U_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1557 : /* fall through */
      case 1589 :
        if ((entire_insn & 0xfff801ff) == 0xc00150)
          { itype = MEPCOP1_16_INSN_CPSADA0_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1558 : /* fall through */
      case 1590 :
        if ((entire_insn & 0xfff801ff) == 0xc00160)
          { itype = MEPCOP1_16_INSN_CPSADUA0_H_P0S; mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1559 : /* fall through */
      case 1591 :
        if ((entire_insn & 0xfff801ff) == 0xc00170)
          { itype = MEPCOP1_16_INSN_CPSADLA0_H_P0S; mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1563 : /* fall through */
      case 1595 :
        if ((entire_insn & 0xfff801ff) == 0xc001b0)
          { itype = MEPCOP1_16_INSN_CPSETA0_H_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1564 : /* fall through */
      case 1596 :
        if ((entire_insn & 0xfff801ff) == 0xc001c0)
          { itype = MEPCOP1_16_INSN_CPSETUA0_W_P0S; mepcop1_16_extract_sfmt_cpaddua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1565 : /* fall through */
      case 1597 :
        if ((entire_insn & 0xfff801ff) == 0xc001d0)
          { itype = MEPCOP1_16_INSN_CPSETLA0_W_P0S; mepcop1_16_extract_sfmt_cpaddla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1600 :
        {
          unsigned int val = (((insn >> 10) & (1 << 3)) | ((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 1 :
            if ((entire_insn & 0xfffffe0f) == 0xc80200)
              { itype = MEPCOP1_16_INSN_CPMOVA0_B_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfffffe0f) == 0xc80400)
              { itype = MEPCOP1_16_INSN_CPMOVUA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfffffe0f) == 0xc80600)
              { itype = MEPCOP1_16_INSN_CPMOVLA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfffffe0f) == 0xc80800)
              { itype = MEPCOP1_16_INSN_CPMOVUUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfffffe0f) == 0xc80a00)
              { itype = MEPCOP1_16_INSN_CPMOVULA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfffffe0f) == 0xc80c00)
              { itype = MEPCOP1_16_INSN_CPMOVLUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfffffe0f) == 0xc80e00)
              { itype = MEPCOP1_16_INSN_CPMOVLLA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xffffffff) == 0xc82000)
              { itype = MEPCOP1_16_INSN_CPACSUMA0_P0S; mepcop1_16_extract_sfmt_cpacsuma0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xffffffff) == 0xc82200)
              { itype = MEPCOP1_16_INSN_CPACCPA0_P0S; mepcop1_16_extract_sfmt_cpaccpa0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
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
      case 1631 :
        {
          unsigned int val = (((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 1 :
            if ((entire_insn & 0xfffffe0f) == 0xc80200)
              { itype = MEPCOP1_16_INSN_CPMOVA0_B_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfffffe0f) == 0xc80400)
              { itype = MEPCOP1_16_INSN_CPMOVUA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfffffe0f) == 0xc80600)
              { itype = MEPCOP1_16_INSN_CPMOVLA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfffffe0f) == 0xc80800)
              { itype = MEPCOP1_16_INSN_CPMOVUUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfffffe0f) == 0xc80a00)
              { itype = MEPCOP1_16_INSN_CPMOVULA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfffffe0f) == 0xc80c00)
              { itype = MEPCOP1_16_INSN_CPMOVLUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfffffe0f) == 0xc80e00)
              { itype = MEPCOP1_16_INSN_CPMOVLLA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1632 :
        {
          unsigned int val = (((insn >> 10) & (1 << 3)) | ((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffffe0f) == 0xc81000)
              { itype = MEPCOP1_16_INSN_CPPACKA0U_B_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfffffe0f) == 0xc81200)
              { itype = MEPCOP1_16_INSN_CPPACKA0_B_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfffffe0f) == 0xc81400)
              { itype = MEPCOP1_16_INSN_CPPACKUA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfffffe0f) == 0xc81600)
              { itype = MEPCOP1_16_INSN_CPPACKLA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfffffe0f) == 0xc81800)
              { itype = MEPCOP1_16_INSN_CPPACKUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfffffe0f) == 0xc81a00)
              { itype = MEPCOP1_16_INSN_CPPACKLA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfffffe0f) == 0xc81c00)
              { itype = MEPCOP1_16_INSN_CPMOVHUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfffffe0f) == 0xc81e00)
              { itype = MEPCOP1_16_INSN_CPMOVHLA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xfff83fff) == 0xc83000)
              { itype = MEPCOP1_16_INSN_CPSRLA0_P0S; mepcop1_16_extract_sfmt_cpsrla0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xfff83fff) == 0xc83200)
              { itype = MEPCOP1_16_INSN_CPSRAA0_P0S; mepcop1_16_extract_sfmt_cpsrla0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            if ((entire_insn & 0xfff83fff) == 0xc83400)
              { itype = MEPCOP1_16_INSN_CPSLLA0_P0S; mepcop1_16_extract_sfmt_cpsrla0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            if ((entire_insn & 0xfffffe0f) == 0xc83800)
              { itype = MEPCOP1_16_INSN_CPSRLIA0_P0S; mepcop1_16_extract_sfmt_cpsrlia0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfffffe0f) == 0xc83a00)
              { itype = MEPCOP1_16_INSN_CPSRAIA0_P0S; mepcop1_16_extract_sfmt_cpsrlia0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            if ((entire_insn & 0xfffffe0f) == 0xc83c00)
              { itype = MEPCOP1_16_INSN_CPSLLIA0_P0S; mepcop1_16_extract_sfmt_cpsrlia0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
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
          unsigned int val = (((insn >> 10) & (1 << 3)) | ((insn >> 9) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffffe0f) == 0xc81000)
              { itype = MEPCOP1_16_INSN_CPPACKA0U_B_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfffffe0f) == 0xc81200)
              { itype = MEPCOP1_16_INSN_CPPACKA0_B_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfffffe0f) == 0xc81400)
              { itype = MEPCOP1_16_INSN_CPPACKUA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfffffe0f) == 0xc81600)
              { itype = MEPCOP1_16_INSN_CPPACKLA0_H_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfffffe0f) == 0xc81800)
              { itype = MEPCOP1_16_INSN_CPPACKUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfffffe0f) == 0xc81a00)
              { itype = MEPCOP1_16_INSN_CPPACKLA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfffffe0f) == 0xc81c00)
              { itype = MEPCOP1_16_INSN_CPMOVHUA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfffffe0f) == 0xc81e00)
              { itype = MEPCOP1_16_INSN_CPMOVHLA0_W_P0S; mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 :
            if ((entire_insn & 0xfffffe0f) == 0xc83800)
              { itype = MEPCOP1_16_INSN_CPSRLIA0_P0S; mepcop1_16_extract_sfmt_cpsrlia0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 :
            if ((entire_insn & 0xfffffe0f) == 0xc83a00)
              { itype = MEPCOP1_16_INSN_CPSRAIA0_P0S; mepcop1_16_extract_sfmt_cpsrlia0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 :
            if ((entire_insn & 0xfffffe0f) == 0xc83c00)
              { itype = MEPCOP1_16_INSN_CPSLLIA0_P0S; mepcop1_16_extract_sfmt_cpsrlia0_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1984 : /* fall through */
      case 2016 :
        if ((entire_insn & 0xfff801ff) == 0xf80000)
          { itype = MEPCOP1_16_INSN_CPFSFTBA0S0U_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1985 : /* fall through */
      case 2017 :
        if ((entire_insn & 0xfff801ff) == 0xf80010)
          { itype = MEPCOP1_16_INSN_CPFSFTBA0S0_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1986 : /* fall through */
      case 2018 :
        if ((entire_insn & 0xfff801ff) == 0xf80020)
          { itype = MEPCOP1_16_INSN_CPFSFTBUA0S0_H_P0S; mepcop1_16_extract_sfmt_cpaddua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1987 : /* fall through */
      case 2019 :
        if ((entire_insn & 0xfff801ff) == 0xf80030)
          { itype = MEPCOP1_16_INSN_CPFSFTBLA0S0_H_P0S; mepcop1_16_extract_sfmt_cpaddla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1988 : /* fall through */
      case 2020 :
        if ((entire_insn & 0xfff801ff) == 0xf80040)
          { itype = MEPCOP1_16_INSN_CPFACA0S0U_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1989 : /* fall through */
      case 2021 :
        if ((entire_insn & 0xfff801ff) == 0xf80050)
          { itype = MEPCOP1_16_INSN_CPFACA0S0_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1990 : /* fall through */
      case 2022 :
        if ((entire_insn & 0xfff801ff) == 0xf80060)
          { itype = MEPCOP1_16_INSN_CPFACUA0S0_H_P0S; mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1991 : /* fall through */
      case 2023 :
        if ((entire_insn & 0xfff801ff) == 0xf80070)
          { itype = MEPCOP1_16_INSN_CPFACLA0S0_H_P0S; mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1992 : /* fall through */
      case 2024 :
        if ((entire_insn & 0xfff801ff) == 0xf80080)
          { itype = MEPCOP1_16_INSN_CPFSFTBA0S1U_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1993 : /* fall through */
      case 2025 :
        if ((entire_insn & 0xfff801ff) == 0xf80090)
          { itype = MEPCOP1_16_INSN_CPFSFTBA0S1_B_P0S; mepcop1_16_extract_sfmt_cpadda0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1994 : /* fall through */
      case 2026 :
        if ((entire_insn & 0xfff801ff) == 0xf800a0)
          { itype = MEPCOP1_16_INSN_CPFSFTBUA0S1_H_P0S; mepcop1_16_extract_sfmt_cpaddua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1995 : /* fall through */
      case 2027 :
        if ((entire_insn & 0xfff801ff) == 0xf800b0)
          { itype = MEPCOP1_16_INSN_CPFSFTBLA0S1_H_P0S; mepcop1_16_extract_sfmt_cpaddla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1996 : /* fall through */
      case 2028 :
        if ((entire_insn & 0xfff801ff) == 0xf800c0)
          { itype = MEPCOP1_16_INSN_CPFACA0S1U_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1997 : /* fall through */
      case 2029 :
        if ((entire_insn & 0xfff801ff) == 0xf800d0)
          { itype = MEPCOP1_16_INSN_CPFACA0S1_B_P0S; mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1998 : /* fall through */
      case 2030 :
        if ((entire_insn & 0xfff801ff) == 0xf800e0)
          { itype = MEPCOP1_16_INSN_CPFACUA0S1_H_P0S; mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1999 : /* fall through */
      case 2031 :
        if ((entire_insn & 0xfff801ff) == 0xf800f0)
          { itype = MEPCOP1_16_INSN_CPFACLA0S1_H_P0S; mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = MEPCOP1_16_INSN_X_INVALID; mepcop1_16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & mepcop1_16_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
mepcop1_16_extract_sfmt_empty (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
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
mepcop1_16_extract_sfmt_c0nop_P0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
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
mepcop1_16_extract_sfmt_cpadd3_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpadd3_b_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpmov_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmov_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpccadd_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
    UINT f_ivc2_5u13;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpccadd_b_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpmovfrcsar0_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
    UINT f_ivc2_5u23;

    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmovfrcsar0_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpmovtocsar0_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
    UINT f_ivc2_5u13;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmovtocsar0_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpmovtocsar1_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
    UINT f_ivc2_5u13;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmovtocsar1_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpmovtocc_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
    UINT f_ivc2_5u13;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmovtocc_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpcmpeqz_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpcmpeqz_b_P0S_P1)\t"
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
mepcop1_16_extract_sfmt_cpadda0u_b_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpadda0u_b_P0S)\t"
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
mepcop1_16_extract_sfmt_cpaddua0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpaddua0_h_P0S)\t"
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
mepcop1_16_extract_sfmt_cpaddla0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpaddla0_h_P0S)\t"
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
mepcop1_16_extract_sfmt_cpaddaca0u_b_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpaddaca0u_b_P0S)\t"
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
mepcop1_16_extract_sfmt_cpaddacua0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpaddacua0_h_P0S)\t"
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
mepcop1_16_extract_sfmt_cpaddacla0_h_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
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
        << "0x" << hex << pc << dec << " (sfmt_cpaddacla0_h_P0S)\t"
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
mepcop1_16_extract_sfmt_cpacsuma0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpacsuma0_P0S)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_16_extract_sfmt_cpaccpa0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpaccpa0_P0S)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcop1_16_extract_sfmt_cpsrla0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
    UINT f_ivc2_5u13;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpsrla0_P0S)\t"
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
mepcop1_16_extract_sfmt_cpsrlia0_P0S (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
    UINT f_ivc2_5u23;

    f_ivc2_5u23 = EXTRACT_MSB0_UINT (insn, 32, 23, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_5u23) = f_ivc2_5u23;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpsrlia0_P0S)\t"
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
mepcop1_16_extract_sfmt_cpmovi_b_P0S_P1 (mepcop1_16_scache* abuf, mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn){
    mepcop1_16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
    UINT f_ivc2_5u13;
    INT f_ivc2_8s20;

    f_ivc2_5u13 = EXTRACT_MSB0_UINT (insn, 32, 13, 5);
    f_ivc2_8s20 = EXTRACT_MSB0_SINT (insn, 32, 20, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_ivc2_8s20) = f_ivc2_8s20;
  FLD (f_ivc2_5u13) = f_ivc2_5u13;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cpmovi_b_P0S_P1)\t"
        << " f_ivc2_8s20:0x" << hex << f_ivc2_8s20 << dec
        << " f_ivc2_5u13:0x" << hex << f_ivc2_5u13 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

