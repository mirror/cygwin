/* Simulator instruction semantics for mepcop1_32.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

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
mepcop1_32_sem_x_invalid (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
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

// ********** cmov-crn-rm: cmov $crnx64,$rm

sem_status
mepcop1_32_sem_cmov_crn_rm (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (ZEXTSIDI (* FLD (i_rm)), ANDDI (current_cpu->hardware.h_cr64[FLD (f_crnx)], MAKEDI (0xffffffff, 0)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crnx) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crnx), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmov-rn-crm: cmov $rm,$crnx64

sem_status
mepcop1_32_sem_cmov_rn_crm (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->hardware.h_cr64[FLD (f_crnx)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rm) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovc-ccrn-rm: cmovc $ivc2c3ccrn,$rm

sem_status
mepcop1_32_sem_cmovc_ccrn_rm (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = * FLD (i_rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << FLD (f_ivc2_ccrn_c3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (FLD (f_ivc2_ccrn_c3), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovc-rn-ccrm: cmovc $rm,$ivc2c3ccrn

sem_status
mepcop1_32_sem_cmovc_rn_ccrm (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->h_ccr_ivc2_get (FLD (f_ivc2_ccrn_c3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rm) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovh-crn-rm: cmovh $crnx64,$rm

sem_status
mepcop1_32_sem_cmovh_crn_rm (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (* FLD (i_rm)), 32), ANDDI (current_cpu->hardware.h_cr64[FLD (f_crnx)], 0xffffffff));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crnx) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crnx), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmovh-rn-crm: cmovh $rm,$crnx64

sem_status
mepcop1_32_sem_cmovh_rn_crm (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRLDI (current_cpu->hardware.h_cr64[FLD (f_crnx)], 32);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rm) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadd3_b_C3: cpadd3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpadd3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpadd3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadd3_h_C3: cpadd3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpadd3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpadd3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadd3_w_C3: cpadd3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpadd3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpadd3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdadd3_C3: cdadd3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cdadd3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdadd3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsub3_b_C3: cpsub3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsub3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsub3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsub3_h_C3: cpsub3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsub3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsub3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsub3_w_C3: cpsub3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsub3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsub3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsub3_C3: cdsub3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cdsub3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsub3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpand3_C3: cpand3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpand3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpand3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpor3_C3: cpor3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpor3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpor3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpnor3_C3: cpnor3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpnor3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpnor3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpxor3_C3: cpxor3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpxor3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpxor3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsel_C3: cpsel $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsel_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsel (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbi_C3: cpfsftbi $croc,$crqc,$crpc,$imm3p4

sem_status
mepcop1_32_sem_cpfsftbi_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpfsftbi (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_3u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbs0_C3: cpfsftbs0 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpfsftbs0_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpfsftbs0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbs1_C3: cpfsftbs1 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpfsftbs1_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpfsftbs1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpacku_b_C3: cpunpacku.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpunpacku_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpacku_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpacku_h_C3: cpunpacku.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpunpacku_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpacku_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpacku_w_C3: cpunpacku.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpunpacku_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpacku_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpackl_b_C3: cpunpackl.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpunpackl_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpackl_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpackl_h_C3: cpunpackl.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpunpackl_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpackl_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpackl_w_C3: cpunpackl.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpunpackl_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpackl_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacku_b_C3: cppacku.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cppacku_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacku_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppack_b_C3: cppack.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cppack_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppack_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppack_h_C3: cppack.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cppack_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppack_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrl3_b_C3: cpsrl3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsrl3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrl3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssrl3_b_C3: cpssrl3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssrl3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssrl3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrl3_h_C3: cpsrl3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsrl3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrl3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssrl3_h_C3: cpssrl3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssrl3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssrl3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrl3_w_C3: cpsrl3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsrl3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrl3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssrl3_w_C3: cpssrl3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssrl3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssrl3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsrl3_C3: cdsrl3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cdsrl3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsrl3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsra3_b_C3: cpsra3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsra3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsra3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssra3_b_C3: cpssra3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssra3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssra3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsra3_h_C3: cpsra3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsra3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsra3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssra3_h_C3: cpssra3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssra3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssra3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsra3_w_C3: cpsra3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsra3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsra3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssra3_w_C3: cpssra3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssra3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssra3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsra3_C3: cdsra3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cdsra3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsra3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsll3_b_C3: cpsll3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsll3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsll3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssll3_b_C3: cpssll3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssll3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssll3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsll3_h_C3: cpsll3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsll3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsll3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssll3_h_C3: cpssll3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssll3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssll3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsll3_w_C3: cpsll3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsll3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsll3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssll3_w_C3: cpssll3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssll3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpssll3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsll3_C3: cdsll3 $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cdsll3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsll3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsla3_h_C3: cpsla3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsla3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsla3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsla3_w_C3: cpsla3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsla3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsla3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadd3_h_C3: cpsadd3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsadd3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsadd3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadd3_w_C3: cpsadd3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpsadd3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsadd3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssub3_h_C3: cpssub3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssub3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
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
    DI opval = current_cpu->ivc2_cpssub3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssub3_w_C3: cpssub3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpssub3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
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
    DI opval = current_cpu->ivc2_cpssub3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuaddu3_b_C3: cpextuaddu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextuaddu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuaddu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuadd3_b_C3: cpextuadd3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextuadd3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuadd3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextladdu3_b_C3: cpextladdu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextladdu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextladdu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextladd3_b_C3: cpextladd3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextladd3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextladd3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextusubu3_b_C3: cpextusubu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextusubu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextusubu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextusub3_b_C3: cpextusub3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextusub3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextusub3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlsubu3_b_C3: cpextlsubu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextlsubu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlsubu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlsub3_b_C3: cpextlsub3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpextlsub3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlsub3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaveu3_b_C3: cpaveu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpaveu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaveu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpave3_b_C3: cpave3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpave3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpave3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpave3_h_C3: cpave3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpave3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpave3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpave3_w_C3: cpave3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpave3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpave3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsru3_b_C3: cpaddsru3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpaddsru3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsru3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsr3_b_C3: cpaddsr3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpaddsr3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsr3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsr3_h_C3: cpaddsr3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpaddsr3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsr3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddsr3_w_C3: cpaddsr3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpaddsr3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpaddsr3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsu3_b_C3: cpabsu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpabsu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabs3_b_C3: cpabs3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpabs3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabs3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabs3_h_C3: cpabs3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpabs3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabs3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmaxu3_b_C3: cpmaxu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmaxu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmaxu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmax3_b_C3: cpmax3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmax3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmax3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmax3_h_C3: cpmax3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmax3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmax3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmaxu3_w_C3: cpmaxu3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmaxu3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmaxu3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmax3_w_C3: cpmax3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmax3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmax3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpminu3_b_C3: cpminu3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpminu3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpminu3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmin3_b_C3: cpmin3.b $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmin3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmin3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmin3_h_C3: cpmin3.h $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmin3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmin3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpminu3_w_C3: cpminu3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpminu3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpminu3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmin3_w_C3: cpmin3.w $croc,$crqc,$crpc

sem_status
mepcop1_32_sem_cpmin3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmin3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovfrcsar0_C3: cpmovfrcsar0 $croc

sem_status
mepcop1_32_sem_cpmovfrcsar0_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovfrcsar0 (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovfrcsar1_C3: cpmovfrcsar1 $croc

sem_status
mepcop1_32_sem_cpmovfrcsar1_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovfrcsar1 (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovfrcc_C3: cpmovfrcc $croc

sem_status
mepcop1_32_sem_cpmovfrcc_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovfrcc (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovtocsar0_C3: cpmovtocsar0 $crqc

sem_status
mepcop1_32_sem_cpmovtocsar0_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 0), opval);
  }
current_cpu->ivc2_cpmovtocsar0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovtocsar1_C3: cpmovtocsar1 $crqc

sem_status
mepcop1_32_sem_cpmovtocsar1_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 15), opval);
  }
current_cpu->ivc2_cpmovtocsar1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovtocc_C3: cpmovtocc $crqc

sem_status
mepcop1_32_sem_cpmovtocc_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpmovtocc (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmov_C3: cpmov $croc,$crqc

sem_status
mepcop1_32_sem_cpmov_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmov (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsz_b_C3: cpabsz.b $croc,$crqc

sem_status
mepcop1_32_sem_cpabsz_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsz_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsz_h_C3: cpabsz.h $croc,$crqc

sem_status
mepcop1_32_sem_cpabsz_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsz_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsz_w_C3: cpabsz.w $croc,$crqc

sem_status
mepcop1_32_sem_cpabsz_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsz_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpldz_h_C3: cpldz.h $croc,$crqc

sem_status
mepcop1_32_sem_cpldz_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpldz_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpldz_w_C3: cpldz.w $croc,$crqc

sem_status
mepcop1_32_sem_cpldz_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpldz_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpnorm_h_C3: cpnorm.h $croc,$crqc

sem_status
mepcop1_32_sem_cpnorm_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpnorm_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpnorm_w_C3: cpnorm.w $croc,$crqc

sem_status
mepcop1_32_sem_cpnorm_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpnorm_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphaddu_b_C3: cphaddu.b $croc,$crqc

sem_status
mepcop1_32_sem_cphaddu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphaddu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphadd_b_C3: cphadd.b $croc,$crqc

sem_status
mepcop1_32_sem_cphadd_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphadd_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphadd_h_C3: cphadd.h $croc,$crqc

sem_status
mepcop1_32_sem_cphadd_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphadd_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphadd_w_C3: cphadd.w $croc,$crqc

sem_status
mepcop1_32_sem_cphadd_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphadd_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpccadd_b_C3: cpccadd.b $crqc

sem_status
mepcop1_32_sem_cpccadd_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpccadd_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpbcast_b_C3: cpbcast.b $croc,$crqc

sem_status
mepcop1_32_sem_cpbcast_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpbcast_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpbcast_h_C3: cpbcast.h $croc,$crqc

sem_status
mepcop1_32_sem_cpbcast_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpbcast_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpbcast_w_C3: cpbcast.w $croc,$crqc

sem_status
mepcop1_32_sem_cpbcast_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpbcast_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuu_b_C3: cpextuu.b $croc,$crqc

sem_status
mepcop1_32_sem_cpextuu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextu_b_C3: cpextu.b $croc,$crqc

sem_status
mepcop1_32_sem_cpextu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuu_h_C3: cpextuu.h $croc,$crqc

sem_status
mepcop1_32_sem_cpextuu_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuu_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextu_h_C3: cpextu.h $croc,$crqc

sem_status
mepcop1_32_sem_cpextu_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextu_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlu_b_C3: cpextlu.b $croc,$crqc

sem_status
mepcop1_32_sem_cpextlu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextl_b_C3: cpextl.b $croc,$crqc

sem_status
mepcop1_32_sem_cpextl_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextl_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlu_h_C3: cpextlu.h $croc,$crqc

sem_status
mepcop1_32_sem_cpextlu_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlu_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextl_h_C3: cpextl.h $croc,$crqc

sem_status
mepcop1_32_sem_cpextl_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextl_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastub_h_C3: cpcastub.h $croc,$crqc

sem_status
mepcop1_32_sem_cpcastub_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastub_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastb_h_C3: cpcastb.h $croc,$crqc

sem_status
mepcop1_32_sem_cpcastb_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastb_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastub_w_C3: cpcastub.w $croc,$crqc

sem_status
mepcop1_32_sem_cpcastub_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastub_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastb_w_C3: cpcastb.w $croc,$crqc

sem_status
mepcop1_32_sem_cpcastb_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastb_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastuh_w_C3: cpcastuh.w $croc,$crqc

sem_status
mepcop1_32_sem_cpcastuh_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastuh_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcasth_w_C3: cpcasth.w $croc,$crqc

sem_status
mepcop1_32_sem_cpcasth_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcasth_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdcastuw_C3: cdcastuw $croc,$crqc

sem_status
mepcop1_32_sem_cdcastuw_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdcastuw (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdcastw_C3: cdcastw $croc,$crqc

sem_status
mepcop1_32_sem_cdcastw_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdcastw (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeqz_b_C3: cpcmpeqz.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpeqz_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpeqz_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeq_b_C3: cpcmpeq.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpeq_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpeq_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeq_h_C3: cpcmpeq.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpeq_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpeq_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeq_w_C3: cpcmpeq.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpeq_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpeq_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpne_b_C3: cpcmpne.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpne_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpne_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpne_h_C3: cpcmpne.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpne_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpne_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpne_w_C3: cpcmpne.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpne_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpne_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgtu_b_C3: cpcmpgtu.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgtu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgtu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgt_b_C3: cpcmpgt.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgt_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgt_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgt_h_C3: cpcmpgt.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgt_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgt_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgtu_w_C3: cpcmpgtu.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgtu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgtu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgt_w_C3: cpcmpgt.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgt_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgt_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgeu_b_C3: cpcmpgeu.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgeu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgeu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpge_b_C3: cpcmpge.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpge_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpge_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpge_h_C3: cpcmpge.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpge_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpge_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgeu_w_C3: cpcmpgeu.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpgeu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpgeu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpge_w_C3: cpcmpge.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpcmpge_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpcmpge_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpeq_b_C3: cpacmpeq.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpeq_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpeq_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpeq_h_C3: cpacmpeq.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpeq_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpeq_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpeq_w_C3: cpacmpeq.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpeq_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpeq_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpne_b_C3: cpacmpne.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpne_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpne_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpne_h_C3: cpacmpne.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpne_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpne_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpne_w_C3: cpacmpne.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpne_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpne_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgtu_b_C3: cpacmpgtu.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgtu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgtu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgt_b_C3: cpacmpgt.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgt_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgt_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgt_h_C3: cpacmpgt.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgt_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgt_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgtu_w_C3: cpacmpgtu.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgtu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgtu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgt_w_C3: cpacmpgt.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgt_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgt_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgeu_b_C3: cpacmpgeu.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgeu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgeu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpge_b_C3: cpacmpge.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpge_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpge_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpge_h_C3: cpacmpge.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpge_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpge_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpgeu_w_C3: cpacmpgeu.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpgeu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpgeu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacmpge_w_C3: cpacmpge.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpacmpge_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpacmpge_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpeq_b_C3: cpocmpeq.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpeq_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpeq_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpeq_h_C3: cpocmpeq.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpeq_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpeq_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpeq_w_C3: cpocmpeq.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpeq_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpeq_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpne_b_C3: cpocmpne.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpne_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpne_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpne_h_C3: cpocmpne.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpne_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpne_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpne_w_C3: cpocmpne.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpne_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpne_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgtu_b_C3: cpocmpgtu.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgtu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgtu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgt_b_C3: cpocmpgt.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgt_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgt_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgt_h_C3: cpocmpgt.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgt_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgt_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgtu_w_C3: cpocmpgtu.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgtu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgtu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgt_w_C3: cpocmpgt.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgt_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgt_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgeu_b_C3: cpocmpgeu.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgeu_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgeu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpge_b_C3: cpocmpge.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpge_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpge_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpge_h_C3: cpocmpge.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpge_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpge_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpgeu_w_C3: cpocmpgeu.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpgeu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpgeu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpocmpge_w_C3: cpocmpge.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpocmpge_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 1), opval);
  }
current_cpu->ivc2_cpocmpge_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrli3_b_C3: cpsrli3.b $crqc,$crpc,$imm3p9

sem_status
mepcop1_32_sem_cpsrli3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrli3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_3u9));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrli3_h_C3: cpsrli3.h $crqc,$crpc,$imm4p8

sem_status
mepcop1_32_sem_cpsrli3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrli3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_4u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrli3_w_C3: cpsrli3.w $crqc,$crpc,$imm5p7

sem_status
mepcop1_32_sem_cpsrli3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrli3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_5u7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsrli3_C3: cdsrli3 $crqc,$crpc,$imm6p6

sem_status
mepcop1_32_sem_cdsrli3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsrli3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_6u6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrai3_b_C3: cpsrai3.b $crqc,$crpc,$imm3p9

sem_status
mepcop1_32_sem_cpsrai3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrai3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_3u9));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrai3_h_C3: cpsrai3.h $crqc,$crpc,$imm4p8

sem_status
mepcop1_32_sem_cpsrai3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrai3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_4u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrai3_w_C3: cpsrai3.w $crqc,$crpc,$imm5p7

sem_status
mepcop1_32_sem_cpsrai3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsrai3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_5u7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdsrai3_C3: cdsrai3 $crqc,$crpc,$imm6p6

sem_status
mepcop1_32_sem_cdsrai3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdsrai3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_6u6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslli3_b_C3: cpslli3.b $crqc,$crpc,$imm3p9

sem_status
mepcop1_32_sem_cpslli3_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslli3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_3u9));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslli3_h_C3: cpslli3.h $crqc,$crpc,$imm4p8

sem_status
mepcop1_32_sem_cpslli3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslli3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_4u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslli3_w_C3: cpslli3.w $crqc,$crpc,$imm5p7

sem_status
mepcop1_32_sem_cpslli3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslli3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_5u7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdslli3_C3: cdslli3 $crqc,$crpc,$imm6p6

sem_status
mepcop1_32_sem_cdslli3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdslli3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_6u6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslai3_h_C3: cpslai3.h $crqc,$crpc,$imm4p8

sem_status
mepcop1_32_sem_cpslai3_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslai3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_4u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslai3_w_C3: cpslai3.w $crqc,$crpc,$imm5p7

sem_status
mepcop1_32_sem_cpslai3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpslai3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_5u7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpclipiu3_w_C3: cpclipiu3.w $crqc,$crpc,$imm5p7

sem_status
mepcop1_32_sem_cpclipiu3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpclipiu3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_5u7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpclipi3_w_C3: cpclipi3.w $crqc,$crpc,$imm5p7

sem_status
mepcop1_32_sem_cpclipi3_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpclipi3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_5u7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdclipiu3_C3: cdclipiu3 $crqc,$crpc,$imm6p6

sem_status
mepcop1_32_sem_cdclipiu3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdclipiu3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_6u6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdclipi3_C3: cdclipi3 $crqc,$crpc,$imm6p6

sem_status
mepcop1_32_sem_cdclipi3_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdclipi3 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)], FLD (f_ivc2_6u6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_b_C3: cpmovi.b $crqc,$simm8p4

sem_status
mepcop1_32_sem_cpmovi_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovi_b (pc, FLD (f_ivc2_8s4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmoviu_h_C3: cpmoviu.h $crqc,$imm8p4

sem_status
mepcop1_32_sem_cpmoviu_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmoviu_h (pc, FLD (f_ivc2_8u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_h_C3: cpmovi.h $crqc,$simm8p4

sem_status
mepcop1_32_sem_cpmovi_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovi_h (pc, FLD (f_ivc2_8s4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmoviu_w_C3: cpmoviu.w $crqc,$imm8p4

sem_status
mepcop1_32_sem_cpmoviu_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmoviu_w (pc, FLD (f_ivc2_8u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_w_C3: cpmovi.w $crqc,$simm8p4

sem_status
mepcop1_32_sem_cpmovi_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovi_w (pc, FLD (f_ivc2_8s4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdmoviu_C3: cdmoviu $crqc,$imm8p4

sem_status
mepcop1_32_sem_cdmoviu_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdmoviu (pc, FLD (f_ivc2_8u4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdmovi_C3: cdmovi $crqc,$simm8p4

sem_status
mepcop1_32_sem_cdmovi_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdmovi (pc, FLD (f_ivc2_8s4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u21), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadda1u_b_C3: cpadda1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpadda1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpadda1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadda1_b_C3: cpadda1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpadda1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpadda1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddua1_h_C3: cpaddua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpaddua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpaddua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddla1_h_C3: cpaddla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpaddla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpaddla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddaca1u_b_C3: cpaddaca1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpaddaca1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpaddaca1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddaca1_b_C3: cpaddaca1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpaddaca1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpaddaca1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddacua1_h_C3: cpaddacua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpaddacua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpaddacua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddacla1_h_C3: cpaddacla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpaddacla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpaddacla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsuba1u_b_C3: cpsuba1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpsuba1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsuba1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsuba1_b_C3: cpsuba1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpsuba1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsuba1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubua1_h_C3: cpsubua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsubua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsubua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubla1_h_C3: cpsubla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsubla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpsubla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubaca1u_b_C3: cpsubaca1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpsubaca1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsubaca1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubaca1_b_C3: cpsubaca1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpsubaca1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsubaca1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubacua1_h_C3: cpsubacua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsubacua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsubacua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubacla1_h_C3: cpsubacla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsubacla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsubacla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsa1u_b_C3: cpabsa1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpabsa1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpabsa1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsa1_b_C3: cpabsa1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpabsa1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpabsa1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsua1_h_C3: cpabsua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpabsua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpabsua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsla1_h_C3: cpabsla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpabsla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpabsla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsada1u_b_C3: cpsada1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpsada1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsada1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsada1_b_C3: cpsada1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpsada1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsada1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadua1_h_C3: cpsadua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsadua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsadua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadla1_h_C3: cpsadla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsadla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsadla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpseta1_h_C3: cpseta1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpseta1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpseta1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsetua1_w_C3: cpsetua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsetua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsetua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsetla1_w_C3: cpsetla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsetla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpsetla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmova1_b_C3: cpmova1.b $croc

sem_status
mepcop1_32_sem_cpmova1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmova1_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovua1_h_C3: cpmovua1.h $croc

sem_status
mepcop1_32_sem_cpmovua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovua1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovla1_h_C3: cpmovla1.h $croc

sem_status
mepcop1_32_sem_cpmovla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovla1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovuua1_w_C3: cpmovuua1.w $croc

sem_status
mepcop1_32_sem_cpmovuua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovuua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovula1_w_C3: cpmovula1.w $croc

sem_status
mepcop1_32_sem_cpmovula1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovula1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovlua1_w_C3: cpmovlua1.w $croc

sem_status
mepcop1_32_sem_cpmovlua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovlua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovlla1_w_C3: cpmovlla1.w $croc

sem_status
mepcop1_32_sem_cpmovlla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovlla1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacka1u_b_C3: cppacka1u.b $croc

sem_status
mepcop1_32_sem_cppacka1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacka1u_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacka1_b_C3: cppacka1.b $croc

sem_status
mepcop1_32_sem_cppacka1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacka1_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackua1_h_C3: cppackua1.h $croc

sem_status
mepcop1_32_sem_cppackua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackua1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackla1_h_C3: cppackla1.h $croc

sem_status
mepcop1_32_sem_cppackla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackla1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackua1_w_C3: cppackua1.w $croc

sem_status
mepcop1_32_sem_cppackua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackla1_w_C3: cppackla1.w $croc

sem_status
mepcop1_32_sem_cppackla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackla1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovhua1_w_C3: cpmovhua1.w $croc

sem_status
mepcop1_32_sem_cpmovhua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovhua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovhla1_w_C3: cpmovhla1.w $croc

sem_status
mepcop1_32_sem_cpmovhla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovhla1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u7), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrla1_C3: cpsrla1 $crqc

sem_status
mepcop1_32_sem_cpsrla1_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsrla1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsraa1_C3: cpsraa1 $crqc

sem_status
mepcop1_32_sem_cpsraa1_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsraa1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslla1_C3: cpslla1 $crqc

sem_status
mepcop1_32_sem_cpslla1_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpslla1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrlia1_P1: cpsrlia1 $imm5p7

sem_status
mepcop1_32_sem_cpsrlia1_P1 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsrlia1 (pc, FLD (f_ivc2_5u7));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsraia1_P1: cpsraia1 $imm5p7

sem_status
mepcop1_32_sem_cpsraia1_P1 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsraia1 (pc, FLD (f_ivc2_5u7));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsllia1_P1: cpsllia1 $imm5p7

sem_status
mepcop1_32_sem_cpsllia1_P1 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpsllia1 (pc, FLD (f_ivc2_5u7));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssqa1u_b_C3: cpssqa1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpssqa1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpssqa1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssqa1_b_C3: cpssqa1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpssqa1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpssqa1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssda1u_b_C3: cpssda1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpssda1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpssda1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssda1_b_C3: cpssda1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpssda1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpssda1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmula1u_b_C3: cpmula1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpmula1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpmula1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmula1_b_C3: cpmula1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpmula1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpmula1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulua1_h_C3: cpmulua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpmulua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulla1_h_C3: cpmulla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpmulla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulua1u_w_C3: cpmulua1u.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulua1u_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpmulua1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulla1u_w_C3: cpmulla1u.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulla1u_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpmulla1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulua1_w_C3: cpmulua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
current_cpu->ivc2_cpmulua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulla1_w_C3: cpmulla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
current_cpu->ivc2_cpmulla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmada1u_b_C3: cpmada1u.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpmada1u_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmada1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmada1_b_C3: cpmada1.b $crqc,$crpc

sem_status
mepcop1_32_sem_cpmada1_b_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmada1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadua1_h_C3: cpmadua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmadua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmadua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadla1_h_C3: cpmadla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmadla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmadla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadua1u_w_C3: cpmadua1u.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmadua1u_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmadua1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadla1u_w_C3: cpmadla1u.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmadla1u_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmadla1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadua1_w_C3: cpmadua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmadua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmadua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadla1_w_C3: cpmadla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmadla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmadla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbua1_h_C3: cpmsbua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmsbua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmsbua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbla1_h_C3: cpmsbla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmsbla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmsbla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbua1u_w_C3: cpmsbua1u.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmsbua1u_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmsbua1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbla1u_w_C3: cpmsbla1u.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmsbla1u_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmsbla1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbua1_w_C3: cpmsbua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmsbua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmsbua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbla1_w_C3: cpmsbla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmsbla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmsbla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadua1_h_C3: cpsmadua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadla1_h_C3: cpsmadla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadua1_w_C3: cpsmadua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadla1_w_C3: cpsmadla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbua1_h_C3: cpsmsbua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbla1_h_C3: cpsmsbla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbua1_w_C3: cpsmsbua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbla1_w_C3: cpsmsbla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslua1_h_C3: cpmulslua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulslua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmulslua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslla1_h_C3: cpmulslla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulslla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmulslla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslua1_w_C3: cpmulslua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulslua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmulslua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslla1_w_C3: cpmulslla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpmulslla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpmulslla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslua1_h_C3: cpsmadslua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadslua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadslua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslla1_h_C3: cpsmadslla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadslla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadslla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslua1_w_C3: cpsmadslua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadslua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadslua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslla1_w_C3: cpsmadslla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmadslla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmadslla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslua1_h_C3: cpsmsbslua1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbslua1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbslua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslla1_h_C3: cpsmsbslla1.h $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbslla1_h_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbslla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslua1_w_C3: cpsmsbslua1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbslua1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 28) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 28), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 29) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 29), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 30) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 30), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 31) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 31), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbslua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslla1_w_C3: cpsmsbslla1.w $crqc,$crpc

sem_status
mepcop1_32_sem_cpsmsbslla1_w_C3 (mep_ext1_cpu* current_cpu, mepcop1_32_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_32_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 24), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 25) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 25), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 26) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 26), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 27) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 27), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 7), opval);
  }
current_cpu->ivc2_cpsmsbslla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u21)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u26)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

