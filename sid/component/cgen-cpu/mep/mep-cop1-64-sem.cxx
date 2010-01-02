/* Simulator instruction semantics for mepcop1_64.

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
mepcop1_64_sem_x_invalid (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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

// ********** cpadd3_b_P0S_P1: cpadd3.b $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpadd3_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpadd3_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadd3_h_P0S_P1: cpadd3.h $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpadd3_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpadd3_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadd3_w_P0S_P1: cpadd3.w $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpadd3_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpadd3_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpacku_b_P0S_P1: cpunpacku.b $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpunpacku_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpacku_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpacku_h_P0S_P1: cpunpacku.h $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpunpacku_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpacku_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpacku_w_P0S_P1: cpunpacku.w $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpunpacku_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpacku_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpackl_b_P0S_P1: cpunpackl.b $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpunpackl_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpackl_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpackl_h_P0S_P1: cpunpackl.h $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpunpackl_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpackl_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpunpackl_w_P0S_P1: cpunpackl.w $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpunpackl_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpunpackl_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsel_P0S_P1: cpsel $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpsel_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpsel (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbs0_P0S_P1: cpfsftbs0 $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpfsftbs0_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpfsftbs0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbs1_P0S_P1: cpfsftbs1 $crop,$crqp,$crpp

sem_status
mepcop1_64_sem_cpfsftbs1_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpfsftbs1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmov_P0S_P1: cpmov $crop,$crqp

sem_status
mepcop1_64_sem_cpmov_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmov (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsz_b_P0S_P1: cpabsz.b $crop,$crqp

sem_status
mepcop1_64_sem_cpabsz_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsz_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsz_h_P0S_P1: cpabsz.h $crop,$crqp

sem_status
mepcop1_64_sem_cpabsz_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsz_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsz_w_P0S_P1: cpabsz.w $crop,$crqp

sem_status
mepcop1_64_sem_cpabsz_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpabsz_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpldz_h_P0S_P1: cpldz.h $crop,$crqp

sem_status
mepcop1_64_sem_cpldz_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpldz_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpldz_w_P0S_P1: cpldz.w $crop,$crqp

sem_status
mepcop1_64_sem_cpldz_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpldz_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpnorm_h_P0S_P1: cpnorm.h $crop,$crqp

sem_status
mepcop1_64_sem_cpnorm_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpnorm_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpnorm_w_P0S_P1: cpnorm.w $crop,$crqp

sem_status
mepcop1_64_sem_cpnorm_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpnorm_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphaddu_b_P0S_P1: cphaddu.b $crop,$crqp

sem_status
mepcop1_64_sem_cphaddu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphaddu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphadd_b_P0S_P1: cphadd.b $crop,$crqp

sem_status
mepcop1_64_sem_cphadd_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphadd_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphadd_h_P0S_P1: cphadd.h $crop,$crqp

sem_status
mepcop1_64_sem_cphadd_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphadd_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cphadd_w_P0S_P1: cphadd.w $crop,$crqp

sem_status
mepcop1_64_sem_cphadd_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cphadd_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpccadd_b_P0S_P1: cpccadd.b $crqp

sem_status
mepcop1_64_sem_cpccadd_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpccadd_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpbcast_b_P0S_P1: cpbcast.b $crop,$crqp

sem_status
mepcop1_64_sem_cpbcast_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpbcast_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpbcast_h_P0S_P1: cpbcast.h $crop,$crqp

sem_status
mepcop1_64_sem_cpbcast_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpbcast_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpbcast_w_P0S_P1: cpbcast.w $crop,$crqp

sem_status
mepcop1_64_sem_cpbcast_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpbcast_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuu_b_P0S_P1: cpextuu.b $crop,$crqp

sem_status
mepcop1_64_sem_cpextuu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextu_b_P0S_P1: cpextu.b $crop,$crqp

sem_status
mepcop1_64_sem_cpextu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextuu_h_P0S_P1: cpextuu.h $crop,$crqp

sem_status
mepcop1_64_sem_cpextuu_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextuu_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextu_h_P0S_P1: cpextu.h $crop,$crqp

sem_status
mepcop1_64_sem_cpextu_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextu_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlu_b_P0S_P1: cpextlu.b $crop,$crqp

sem_status
mepcop1_64_sem_cpextlu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextl_b_P0S_P1: cpextl.b $crop,$crqp

sem_status
mepcop1_64_sem_cpextl_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextl_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextlu_h_P0S_P1: cpextlu.h $crop,$crqp

sem_status
mepcop1_64_sem_cpextlu_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextlu_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpextl_h_P0S_P1: cpextl.h $crop,$crqp

sem_status
mepcop1_64_sem_cpextl_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpextl_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastub_h_P0S_P1: cpcastub.h $crop,$crqp

sem_status
mepcop1_64_sem_cpcastub_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastub_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastb_h_P0S_P1: cpcastb.h $crop,$crqp

sem_status
mepcop1_64_sem_cpcastb_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastb_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastub_w_P0S_P1: cpcastub.w $crop,$crqp

sem_status
mepcop1_64_sem_cpcastub_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastub_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastb_w_P0S_P1: cpcastb.w $crop,$crqp

sem_status
mepcop1_64_sem_cpcastb_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastb_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcastuh_w_P0S_P1: cpcastuh.w $crop,$crqp

sem_status
mepcop1_64_sem_cpcastuh_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcastuh_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcasth_w_P0S_P1: cpcasth.w $crop,$crqp

sem_status
mepcop1_64_sem_cpcasth_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpcasth_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdcastuw_P0S_P1: cdcastuw $crop,$crqp

sem_status
mepcop1_64_sem_cdcastuw_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdcastuw (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cdcastw_P0S_P1: cdcastw $crop,$crqp

sem_status
mepcop1_64_sem_cdcastw_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cdcastw (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovfrcsar0_P0S_P1: cpmovfrcsar0 $crop

sem_status
mepcop1_64_sem_cpmovfrcsar0_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovfrcsar0 (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovfrcsar1_P0S_P1: cpmovfrcsar1 $crop

sem_status
mepcop1_64_sem_cpmovfrcsar1_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovfrcsar1 (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovfrcc_P0S_P1: cpmovfrcc $crop

sem_status
mepcop1_64_sem_cpmovfrcc_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovfrcc (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovtocsar0_P0S_P1: cpmovtocsar0 $crqp

sem_status
mepcop1_64_sem_cpmovtocsar0_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmovtocsar0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovtocsar1_P0S_P1: cpmovtocsar1 $crqp

sem_status
mepcop1_64_sem_cpmovtocsar1_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmovtocsar1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovtocc_P0S_P1: cpmovtocc $crqp

sem_status
mepcop1_64_sem_cpmovtocc_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmovtocc (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeqz_b_P0S_P1: cpcmpeqz.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpeqz_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpeqz_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeq_b_P0S_P1: cpcmpeq.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpeq_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpeq_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeq_h_P0S_P1: cpcmpeq.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpeq_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpeq_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpeq_w_P0S_P1: cpcmpeq.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpeq_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpeq_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpne_b_P0S_P1: cpcmpne.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpne_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpne_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpne_h_P0S_P1: cpcmpne.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpne_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpne_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpne_w_P0S_P1: cpcmpne.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpne_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpne_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgtu_b_P0S_P1: cpcmpgtu.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgtu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgtu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgt_b_P0S_P1: cpcmpgt.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgt_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgt_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgt_h_P0S_P1: cpcmpgt.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgt_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgt_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgtu_w_P0S_P1: cpcmpgtu.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgtu_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgtu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgt_w_P0S_P1: cpcmpgt.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgt_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgt_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgeu_b_P0S_P1: cpcmpgeu.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgeu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgeu_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpge_b_P0S_P1: cpcmpge.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpge_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpge_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpge_h_P0S_P1: cpcmpge.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpge_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpge_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpgeu_w_P0S_P1: cpcmpgeu.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpgeu_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpgeu_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpcmpge_w_P0S_P1: cpcmpge.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpcmpge_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpcmpge_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbi_P0_P1: cpfsftbi $crop,$crqp,$crpp,$imm3p5

sem_status
mepcop1_64_sem_cpfsftbi_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpeq_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpeq_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpeq_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpne_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpne_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpne_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgtu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgt_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgt_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgtu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgt_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgeu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpge_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpge_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpgeu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpacmpge_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpeq_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpeq_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpeq_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpne_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpne_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpne_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgtu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgt_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgt_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgtu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgt_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgeu_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpge_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpge_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpgeu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpocmpge_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdadd3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsub3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsub3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsub3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdsub3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsadd3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsadd3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssub3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssub3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextuaddu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextuadd3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextladdu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextladd3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextusubu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextusub3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextlsubu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpextlsub3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpaveu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpave3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpave3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpave3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpaddsru3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpaddsr3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpaddsr3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpaddsr3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpabsu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpabs3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpabs3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpand3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpor3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpnor3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpxor3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cppacku_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cppack_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cppack_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmaxu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmax3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmax3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmaxu3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmax3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpminu3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmin3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmin3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpminu3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmin3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrl3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssrl3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrl3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssrl3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrl3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssrl3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdsrl3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsra3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssra3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsra3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssra3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsra3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssra3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdsra3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsll3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssll3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsll3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssll3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsll3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpssll3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdsll3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsla3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsla3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrli3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrli3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrli3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdsrli3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrai3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrai3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpsrai3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdsrai3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpslli3_b_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpslli3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpslli3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdslli3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpslai3_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpslai3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpclipiu3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpclipi3_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdclipiu3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdclipi3_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmovi_h_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmoviu_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cpmovi_w_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdmoviu_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
mepcop1_64_sem_cdmovi_P0_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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

// ********** c1nop_P1: c1nop

sem_status
mepcop1_64_sem_c1nop_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->ivc2_c1nop (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_b_P0S_P1: cpmovi.b $crqp,$simm8p20

sem_status
mepcop1_64_sem_cpmovi_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovi_b (pc, FLD (f_ivc2_8s20));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u13), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadda1u_b_P1: cpadda1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpadda1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpadda1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadda1_b_P1: cpadda1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpadda1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpadda1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddua1_h_P1: cpaddua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpaddua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaddua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddla1_h_P1: cpaddla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpaddla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaddla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddaca1u_b_P1: cpaddaca1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpaddaca1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaddaca1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddaca1_b_P1: cpaddaca1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpaddaca1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaddaca1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddacua1_h_P1: cpaddacua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpaddacua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaddacua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddacla1_h_P1: cpaddacla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpaddacla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaddacla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsuba1u_b_P1: cpsuba1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpsuba1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsuba1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsuba1_b_P1: cpsuba1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpsuba1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsuba1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubua1_h_P1: cpsubua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsubua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsubua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubla1_h_P1: cpsubla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsubla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsubla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubaca1u_b_P1: cpsubaca1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpsubaca1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsubaca1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubaca1_b_P1: cpsubaca1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpsubaca1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsubaca1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubacua1_h_P1: cpsubacua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsubacua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsubacua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubacla1_h_P1: cpsubacla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsubacla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsubacla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsa1u_b_P1: cpabsa1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpabsa1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpabsa1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsa1_b_P1: cpabsa1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpabsa1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpabsa1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsua1_h_P1: cpabsua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpabsua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpabsua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsla1_h_P1: cpabsla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpabsla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpabsla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsada1u_b_P1: cpsada1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpsada1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsada1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsada1_b_P1: cpsada1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpsada1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsada1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadua1_h_P1: cpsadua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsadua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsadua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadla1_h_P1: cpsadla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsadla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsadla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpseta1_h_P1: cpseta1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpseta1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpseta1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsetua1_w_P1: cpsetua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsetua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsetua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsetla1_w_P1: cpsetla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsetla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsetla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmova1_b_P1: cpmova1.b $crop

sem_status
mepcop1_64_sem_cpmova1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmova1_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovua1_h_P1: cpmovua1.h $crop

sem_status
mepcop1_64_sem_cpmovua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovua1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovla1_h_P1: cpmovla1.h $crop

sem_status
mepcop1_64_sem_cpmovla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovla1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovuua1_w_P1: cpmovuua1.w $crop

sem_status
mepcop1_64_sem_cpmovuua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovuua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovula1_w_P1: cpmovula1.w $crop

sem_status
mepcop1_64_sem_cpmovula1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovula1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovlua1_w_P1: cpmovlua1.w $crop

sem_status
mepcop1_64_sem_cpmovlua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovlua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovlla1_w_P1: cpmovlla1.w $crop

sem_status
mepcop1_64_sem_cpmovlla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovlla1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacka1u_b_P1: cppacka1u.b $crop

sem_status
mepcop1_64_sem_cppacka1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacka1u_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacka1_b_P1: cppacka1.b $crop

sem_status
mepcop1_64_sem_cppacka1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacka1_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackua1_h_P1: cppackua1.h $crop

sem_status
mepcop1_64_sem_cppackua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackua1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackla1_h_P1: cppackla1.h $crop

sem_status
mepcop1_64_sem_cppackla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackla1_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackua1_w_P1: cppackua1.w $crop

sem_status
mepcop1_64_sem_cppackua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackla1_w_P1: cppackla1.w $crop

sem_status
mepcop1_64_sem_cppackla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackla1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovhua1_w_P1: cpmovhua1.w $crop

sem_status
mepcop1_64_sem_cpmovhua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovhua1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovhla1_w_P1: cpmovhla1.w $crop

sem_status
mepcop1_64_sem_cpmovhla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovhla1_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacsuma1_P1: cpacsuma1

sem_status
mepcop1_64_sem_cpacsuma1_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpacsuma1 (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaccpa1_P1: cpaccpa1

sem_status
mepcop1_64_sem_cpaccpa1_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpaccpa1 (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacswp_P1: cpacswp

sem_status
mepcop1_64_sem_cpacswp_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 16) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 16), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 17) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 17), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 18) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 18), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 19) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 19), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 20) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 20), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 21) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 21), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 22) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 22), opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 23), opval);
  }
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
current_cpu->ivc2_cpacswp (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrla1_P1: cpsrla1 $crqp

sem_status
mepcop1_64_sem_cpsrla1_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsrla1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsraa1_P1: cpsraa1 $crqp

sem_status
mepcop1_64_sem_cpsraa1_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsraa1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslla1_P1: cpslla1 $crqp

sem_status
mepcop1_64_sem_cpslla1_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpslla1 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrlia1_1_p1: cpsrlia1 $imm5p23

sem_status
mepcop1_64_sem_cpsrlia1_1_p1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsrlia1 (pc, FLD (f_ivc2_5u23));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsraia1_1_p1: cpsraia1 $imm5p23

sem_status
mepcop1_64_sem_cpsraia1_1_p1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsraia1 (pc, FLD (f_ivc2_5u23));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsllia1_1_p1: cpsllia1 $imm5p23

sem_status
mepcop1_64_sem_cpsllia1_1_p1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsllia1 (pc, FLD (f_ivc2_5u23));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulia1s0u_b_P1: cpfmulia1s0u.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmulia1s0u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulia1s0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulia1s0_b_P1: cpfmulia1s0.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmulia1s0_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulia1s0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmuliua1s0_h_P1: cpfmuliua1s0.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmuliua1s0_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmuliua1s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulila1s0_h_P1: cpfmulila1s0.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmulila1s0_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulila1s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadia1s0u_b_P1: cpfmadia1s0u.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadia1s0u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadia1s0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadia1s0_b_P1: cpfmadia1s0.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadia1s0_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadia1s0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadiua1s0_h_P1: cpfmadiua1s0.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadiua1s0_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadiua1s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadila1s0_h_P1: cpfmadila1s0.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadila1s0_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadila1s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulia1s1u_b_P1: cpfmulia1s1u.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmulia1s1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulia1s1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulia1s1_b_P1: cpfmulia1s1.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmulia1s1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulia1s1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmuliua1s1_h_P1: cpfmuliua1s1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmuliua1s1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmuliua1s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulila1s1_h_P1: cpfmulila1s1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmulila1s1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulila1s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadia1s1u_b_P1: cpfmadia1s1u.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadia1s1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadia1s1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadia1s1_b_P1: cpfmadia1s1.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadia1s1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadia1s1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadiua1s1_h_P1: cpfmadiua1s1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadiua1s1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadiua1s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadila1s1_h_P1: cpfmadila1s1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpfmadila1s1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadila1s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamulia1u_b_P1: cpamulia1u.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamulia1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamulia1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamulia1_b_P1: cpamulia1.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamulia1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamulia1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamuliua1_h_P1: cpamuliua1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamuliua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamuliua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamulila1_h_P1: cpamulila1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamulila1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamulila1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamadia1u_b_P1: cpamadia1u.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamadia1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamadia1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamadia1_b_P1: cpamadia1.b $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamadia1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamadia1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamadiua1_h_P1: cpamadiua1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamadiua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamadiua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpamadila1_h_P1: cpamadila1.h $crqp,$crpp,$simm8p0

sem_status
mepcop1_64_sem_cpamadila1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpamadila1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulia1u_b_P1: cpfmulia1u.b $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmulia1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulia1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulia1_b_P1: cpfmulia1.b $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmulia1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulia1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmuliua1_h_P1: cpfmuliua1.h $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmuliua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmuliua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmulila1_h_P1: cpfmulila1.h $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmulila1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmulila1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadia1u_b_P1: cpfmadia1u.b $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmadia1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadia1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadia1_b_P1: cpfmadia1.b $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmadia1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadia1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadiua1_h_P1: cpfmadiua1.h $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmadiua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadiua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfmadila1_h_P1: cpfmadila1.h $crqp,$crpp,$imm3p25,$simm8p0

sem_status
mepcop1_64_sem_cpfmadila1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpfmadila1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)], FLD (f_ivc2_3u25), FLD (f_ivc2_8s0));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssqa1u_b_P1: cpssqa1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpssqa1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpssqa1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssqa1_b_P1: cpssqa1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpssqa1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpssqa1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssda1u_b_P1: cpssda1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpssda1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpssda1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpssda1_b_P1: cpssda1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpssda1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpssda1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmula1u_b_P1: cpmula1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpmula1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmula1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmula1_b_P1: cpmula1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpmula1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmula1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulua1_h_P1: cpmulua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulla1_h_P1: cpmulla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulua1u_w_P1: cpmulua1u.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulua1u_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulua1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulla1u_w_P1: cpmulla1u.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulla1u_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulla1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulua1_w_P1: cpmulua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulla1_w_P1: cpmulla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmada1u_b_P1: cpmada1u.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpmada1u_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmada1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmada1_b_P1: cpmada1.b $crqp,$crpp

sem_status
mepcop1_64_sem_cpmada1_b_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmada1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadua1_h_P1: cpmadua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmadua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmadua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadla1_h_P1: cpmadla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmadla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmadla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadua1u_w_P1: cpmadua1u.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmadua1u_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmadua1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadla1u_w_P1: cpmadla1u.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmadla1u_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmadla1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadua1_w_P1: cpmadua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmadua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmadua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmadla1_w_P1: cpmadla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmadla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmadla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbua1_h_P1: cpmsbua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmsbua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmsbua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbla1_h_P1: cpmsbla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmsbla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmsbla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbua1u_w_P1: cpmsbua1u.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmsbua1u_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmsbua1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbla1u_w_P1: cpmsbla1u.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmsbla1u_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmsbla1u_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbua1_w_P1: cpmsbua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmsbua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmsbua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmsbla1_w_P1: cpmsbla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmsbla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmsbla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadua1_h_P1: cpsmadua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadla1_h_P1: cpsmadla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadua1_w_P1: cpsmadua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadla1_w_P1: cpsmadla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbua1_h_P1: cpsmsbua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbla1_h_P1: cpsmsbla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbua1_w_P1: cpsmsbua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbla1_w_P1: cpsmsbla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslua1_h_P1: cpmulslua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulslua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulslua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslla1_h_P1: cpmulslla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulslla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulslla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslua1_w_P1: cpmulslua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulslua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulslua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmulslla1_w_P1: cpmulslla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpmulslla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpmulslla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslua1_h_P1: cpsmadslua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadslua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadslua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslla1_h_P1: cpsmadslla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadslla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadslla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslua1_w_P1: cpsmadslua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadslua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadslua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmadslla1_w_P1: cpsmadslla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmadslla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmadslla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslua1_h_P1: cpsmsbslua1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbslua1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbslua1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslla1_h_P1: cpsmsbslla1.h $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbslla1_h_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbslla1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslua1_w_P1: cpsmsbslua1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbslua1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbslua1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsmsbslla1_w_P1: cpsmsbslla1.w $crqp,$crpp

sem_status
mepcop1_64_sem_cpsmsbslla1_w_P1 (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpfmulia1u_b_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_64_scache* abuf = sem;
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
current_cpu->ivc2_cpsmsbslla1_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

