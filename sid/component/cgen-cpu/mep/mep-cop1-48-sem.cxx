/* Simulator instruction semantics for mepcop1_48.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext1.h"

using namespace mep_ext1; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

sem_status
mepcop1_48_sem_x_invalid (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 0;

  {
    current_cpu->invalid_insn (pc);
    assert (0);
    /* NOTREACHED */
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmov-crn-rm-p0: cmov $ivc2crn,$ivc2rm

sem_status
mepcop1_48_sem_cmov_crn_rm_p0 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = * FLD (i_ivc2rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_crnx) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_crnx), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmov-rn-crm-p0: cmov $ivc2rm,$ivc2crn

sem_status
mepcop1_48_sem_cmov_rn_crm_p0 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->hardware.h_cr64[FLD (f_ivc2_crnx)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_ivc2_crm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_ivc2rm) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovc-ccrn-rm-p0: cmovc $ivc2ccrn,$ivc2rm

sem_status
mepcop1_48_sem_cmovc_ccrn_rm_p0 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm_p0.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = * FLD (i_ivc2rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << FLD (f_ivc2_ccrn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (FLD (f_ivc2_ccrn), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovc-rn-ccrm-p0: cmovc $ivc2rm,$ivc2ccrn

sem_status
mepcop1_48_sem_cmovc_rn_ccrm_p0 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm_p0.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->h_ccr_ivc2_get (FLD (f_ivc2_ccrn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_ivc2_crm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_ivc2rm) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovh-crn-rm-p0: cmovh $ivc2crn,$ivc2rm

sem_status
mepcop1_48_sem_cmovh_crn_rm_p0 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (* FLD (i_ivc2rm)), 32), ANDDI (current_cpu->hardware.h_cr64[FLD (f_ivc2_crnx)], 0xffffffff));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_crnx) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_crnx), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovh-rn-crm-p0: cmovh $ivc2rm,$ivc2crn

sem_status
mepcop1_48_sem_cmovh_rn_crm_p0 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRLDI (current_cpu->hardware.h_cr64[FLD (f_ivc2_crnx)], 32);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_ivc2_crm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_ivc2rm) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** c0nop_P0_P0S: c0nop

sem_status
mepcop1_48_sem_c0nop_P0_P0S (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_c0nop (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbi_P0_P1: cpfsftbi $crop,$crqp,$crpp,$imm3p5

sem_status
mepcop1_48_sem_cpfsftbi_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpfsftbi (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpeq_b_P0_P1: cpacmpeq.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpeq_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpeq_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpeq_h_P0_P1: cpacmpeq.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpeq_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpeq_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpeq_w_P0_P1: cpacmpeq.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpeq_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpeq_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpne_b_P0_P1: cpacmpne.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpne_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpne_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpne_h_P0_P1: cpacmpne.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpne_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpne_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpne_w_P0_P1: cpacmpne.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpne_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpne_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgtu_b_P0_P1: cpacmpgtu.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgtu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgtu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgt_b_P0_P1: cpacmpgt.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgt_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgt_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgt_h_P0_P1: cpacmpgt.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgt_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgt_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgtu_w_P0_P1: cpacmpgtu.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgtu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgtu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgt_w_P0_P1: cpacmpgt.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgt_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgt_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgeu_b_P0_P1: cpacmpgeu.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgeu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgeu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpge_b_P0_P1: cpacmpge.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpge_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpge_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpge_h_P0_P1: cpacmpge.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpge_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpge_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgeu_w_P0_P1: cpacmpgeu.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpgeu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpgeu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpge_w_P0_P1: cpacmpge.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpacmpge_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpacmpge_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpeq_b_P0_P1: cpocmpeq.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpeq_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpeq_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpeq_h_P0_P1: cpocmpeq.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpeq_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpeq_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpeq_w_P0_P1: cpocmpeq.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpeq_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpeq_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpne_b_P0_P1: cpocmpne.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpne_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpne_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpne_h_P0_P1: cpocmpne.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpne_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpne_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpne_w_P0_P1: cpocmpne.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpne_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpne_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgtu_b_P0_P1: cpocmpgtu.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgtu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgtu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgt_b_P0_P1: cpocmpgt.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgt_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgt_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgt_h_P0_P1: cpocmpgt.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgt_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgt_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgtu_w_P0_P1: cpocmpgtu.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgtu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgtu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgt_w_P0_P1: cpocmpgt.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgt_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgt_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgeu_b_P0_P1: cpocmpgeu.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgeu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgeu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpge_b_P0_P1: cpocmpge.b $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpge_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpge_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpge_h_P0_P1: cpocmpge.h $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpge_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpge_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgeu_w_P0_P1: cpocmpgeu.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpgeu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpgeu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpge_w_P0_P1: cpocmpge.w $crqp,$crpp

sem_status
mepcop1_48_sem_cpocmpge_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_cpocmpge_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdadd3_P0_P1: cdadd3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cdadd3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdadd3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsub3_b_P0_P1: cpsub3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsub3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsub3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsub3_h_P0_P1: cpsub3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsub3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsub3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsub3_w_P0_P1: cpsub3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsub3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsub3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsub3_P0_P1: cdsub3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cdsub3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsub3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadd3_h_P0_P1: cpsadd3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsadd3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsadd3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadd3_w_P0_P1: cpsadd3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsadd3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsadd3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssub3_h_P0_P1: cpssub3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssub3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 4), opval);
  }
  {
    DI opval = current_cpu->ivc2_cpssub3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssub3_w_P0_P1: cpssub3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssub3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 4), opval);
  }
  {
    DI opval = current_cpu->ivc2_cpssub3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuaddu3_b_P0_P1: cpextuaddu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextuaddu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuaddu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuadd3_b_P0_P1: cpextuadd3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextuadd3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuadd3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextladdu3_b_P0_P1: cpextladdu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextladdu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextladdu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextladd3_b_P0_P1: cpextladd3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextladd3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextladd3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextusubu3_b_P0_P1: cpextusubu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextusubu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextusubu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextusub3_b_P0_P1: cpextusub3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextusub3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextusub3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlsubu3_b_P0_P1: cpextlsubu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextlsubu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlsubu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlsub3_b_P0_P1: cpextlsub3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpextlsub3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlsub3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaveu3_b_P0_P1: cpaveu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpaveu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaveu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpave3_b_P0_P1: cpave3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpave3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpave3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpave3_h_P0_P1: cpave3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpave3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpave3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpave3_w_P0_P1: cpave3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpave3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpave3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsru3_b_P0_P1: cpaddsru3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpaddsru3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsru3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsr3_b_P0_P1: cpaddsr3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpaddsr3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsr3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsr3_h_P0_P1: cpaddsr3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpaddsr3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsr3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsr3_w_P0_P1: cpaddsr3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpaddsr3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsr3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsu3_b_P0_P1: cpabsu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpabsu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabs3_b_P0_P1: cpabs3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpabs3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabs3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabs3_h_P0_P1: cpabs3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpabs3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabs3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpand3_P0_P1: cpand3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpand3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpand3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpor3_P0_P1: cpor3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpor3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpor3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpnor3_P0_P1: cpnor3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpnor3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpnor3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpxor3_P0_P1: cpxor3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpxor3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpxor3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacku_b_P0_P1: cppacku.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cppacku_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacku_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppack_b_P0_P1: cppack.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cppack_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppack_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppack_h_P0_P1: cppack.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cppack_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppack_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmaxu3_b_P0_P1: cpmaxu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmaxu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmaxu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmax3_b_P0_P1: cpmax3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmax3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmax3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmax3_h_P0_P1: cpmax3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmax3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmax3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmaxu3_w_P0_P1: cpmaxu3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmaxu3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmaxu3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmax3_w_P0_P1: cpmax3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmax3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmax3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpminu3_b_P0_P1: cpminu3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpminu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpminu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmin3_b_P0_P1: cpmin3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmin3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmin3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmin3_h_P0_P1: cpmin3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmin3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmin3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpminu3_w_P0_P1: cpminu3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpminu3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpminu3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmin3_w_P0_P1: cpmin3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpmin3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmin3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrl3_b_P0_P1: cpsrl3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsrl3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrl3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssrl3_b_P0_P1: cpssrl3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssrl3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssrl3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrl3_h_P0_P1: cpsrl3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsrl3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrl3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssrl3_h_P0_P1: cpssrl3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssrl3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssrl3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrl3_w_P0_P1: cpsrl3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsrl3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrl3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssrl3_w_P0_P1: cpssrl3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssrl3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssrl3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsrl3_P0_P1: cdsrl3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cdsrl3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsrl3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsra3_b_P0_P1: cpsra3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsra3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsra3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssra3_b_P0_P1: cpssra3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssra3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssra3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsra3_h_P0_P1: cpsra3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsra3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsra3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssra3_h_P0_P1: cpssra3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssra3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssra3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsra3_w_P0_P1: cpsra3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsra3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsra3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssra3_w_P0_P1: cpssra3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssra3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssra3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsra3_P0_P1: cdsra3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cdsra3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsra3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsll3_b_P0_P1: cpsll3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsll3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsll3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssll3_b_P0_P1: cpssll3.b $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssll3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssll3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsll3_h_P0_P1: cpsll3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsll3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsll3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssll3_h_P0_P1: cpssll3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssll3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssll3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsll3_w_P0_P1: cpsll3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsll3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsll3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssll3_w_P0_P1: cpssll3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpssll3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssll3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsll3_P0_P1: cdsll3 $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cdsll3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsll3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsla3_h_P0_P1: cpsla3.h $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsla3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsla3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsla3_w_P0_P1: cpsla3.w $crop,$crqp,$crpp

sem_status
mepcop1_48_sem_cpsla3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsla3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrli3_b_P0_P1: cpsrli3.b $crop,$crqp,$imm3p5

sem_status
mepcop1_48_sem_cpsrli3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrli3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_3u5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrli3_h_P0_P1: cpsrli3.h $crop,$crqp,$imm4p4

sem_status
mepcop1_48_sem_cpsrli3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrli3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_4u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrli3_w_P0_P1: cpsrli3.w $crop,$crqp,$imm5p3

sem_status
mepcop1_48_sem_cpsrli3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrli3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_5u3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsrli3_P0_P1: cdsrli3 $crop,$crqp,$imm6p2

sem_status
mepcop1_48_sem_cdsrli3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsrli3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_6u2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrai3_b_P0_P1: cpsrai3.b $crop,$crqp,$imm3p5

sem_status
mepcop1_48_sem_cpsrai3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrai3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_3u5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrai3_h_P0_P1: cpsrai3.h $crop,$crqp,$imm4p4

sem_status
mepcop1_48_sem_cpsrai3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrai3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_4u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrai3_w_P0_P1: cpsrai3.w $crop,$crqp,$imm5p3

sem_status
mepcop1_48_sem_cpsrai3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrai3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_5u3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsrai3_P0_P1: cdsrai3 $crop,$crqp,$imm6p2

sem_status
mepcop1_48_sem_cdsrai3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsrai3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_6u2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslli3_b_P0_P1: cpslli3.b $crop,$crqp,$imm3p5

sem_status
mepcop1_48_sem_cpslli3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslli3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_3u5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslli3_h_P0_P1: cpslli3.h $crop,$crqp,$imm4p4

sem_status
mepcop1_48_sem_cpslli3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslli3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_4u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslli3_w_P0_P1: cpslli3.w $crop,$crqp,$imm5p3

sem_status
mepcop1_48_sem_cpslli3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslli3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_5u3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdslli3_P0_P1: cdslli3 $crop,$crqp,$imm6p2

sem_status
mepcop1_48_sem_cdslli3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdslli3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_6u2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslai3_h_P0_P1: cpslai3.h $crop,$crqp,$imm4p4

sem_status
mepcop1_48_sem_cpslai3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslai3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_4u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslai3_w_P0_P1: cpslai3.w $crop,$crqp,$imm5p3

sem_status
mepcop1_48_sem_cpslai3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslai3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_5u3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpclipiu3_w_P0_P1: cpclipiu3.w $crop,$crqp,$imm5p3

sem_status
mepcop1_48_sem_cpclipiu3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpclipiu3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_5u3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpclipi3_w_P0_P1: cpclipi3.w $crop,$crqp,$imm5p3

sem_status
mepcop1_48_sem_cpclipi3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpclipi3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_5u3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdclipiu3_P0_P1: cdclipiu3 $crop,$crqp,$imm6p2

sem_status
mepcop1_48_sem_cdclipiu3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdclipiu3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_6u2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdclipi3_P0_P1: cdclipi3 $crop,$crqp,$imm6p2

sem_status
mepcop1_48_sem_cdclipi3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdclipi3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], FLD (f_ivc2_6u2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_h_P0_P1: cpmovi.h $crqp,$simm16p0

sem_status
mepcop1_48_sem_cpmovi_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovi_h16 (pc, FLD (f_ivc2_simm16p0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmoviu_w_P0_P1: cpmoviu.w $crqp,$imm16p0

sem_status
mepcop1_48_sem_cpmoviu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmoviu_w16 (pc, FLD (f_ivc2_imm16p0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_w_P0_P1: cpmovi.w $crqp,$simm16p0

sem_status
mepcop1_48_sem_cpmovi_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovi_w16 (pc, FLD (f_ivc2_simm16p0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdmoviu_P0_P1: cdmoviu $crqp,$imm16p0

sem_status
mepcop1_48_sem_cdmoviu_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdmoviu16 (pc, FLD (f_ivc2_imm16p0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdmovi_P0_P1: cdmovi $crqp,$simm16p0

sem_status
mepcop1_48_sem_cdmovi_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_48_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdmovi16 (pc, FLD (f_ivc2_simm16p0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

