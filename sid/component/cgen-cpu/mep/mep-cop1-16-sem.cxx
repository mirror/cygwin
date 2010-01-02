/* Simulator instruction semantics for mepcop1_16.

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
mepcop1_16_sem_x_invalid (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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

// ********** c0nop_P0_P0S: c0nop

sem_status
mepcop1_16_sem_c0nop_P0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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

// ********** cpadd3_b_P0S_P1: cpadd3.b $crop,$crqp,$crpp

sem_status
mepcop1_16_sem_cpadd3_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpadd3_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpadd3_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpunpacku_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpunpacku_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpunpacku_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpunpackl_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpunpackl_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpunpackl_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpsel_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpfsftbs0_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpfsftbs1_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmov_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpabsz_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpabsz_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpabsz_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpldz_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpldz_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpnorm_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpnorm_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cphaddu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cphadd_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cphadd_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cphadd_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpccadd_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpbcast_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpbcast_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpbcast_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextuu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextuu_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextu_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextlu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextl_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextlu_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpextl_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcastub_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcastb_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcastub_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcastb_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcastuh_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcasth_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cdcastuw_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cdcastw_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmovfrcsar0_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmovfrcsar1_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmovfrcc_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmovtocsar0_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmovtocsar1_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpmovtocc_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpeqz_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpeq_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpeq_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpeq_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpne_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpne_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpne_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgtu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgt_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgt_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgtu_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgt_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgeu_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpge_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpge_h_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpgeu_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
mepcop1_16_sem_cpcmpge_w_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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

// ********** cpadda0u_b_P0S: cpadda0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpadda0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpadda0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpadda0_b_P0S: cpadda0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpadda0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpadda0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddua0_h_P0S: cpaddua0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpaddua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
current_cpu->ivc2_cpaddua0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddla0_h_P0S: cpaddla0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpaddla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpaddla0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddaca0u_b_P0S: cpaddaca0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpaddaca0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpaddaca0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddaca0_b_P0S: cpaddaca0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpaddaca0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpaddaca0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddacua0_h_P0S: cpaddacua0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpaddacua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpaddacua0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaddacla0_h_P0S: cpaddacla0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpaddacla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpaddacla0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsuba0u_b_P0S: cpsuba0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpsuba0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsuba0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsuba0_b_P0S: cpsuba0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpsuba0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsuba0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubua0_h_P0S: cpsubua0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpsubua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
current_cpu->ivc2_cpsubua0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubla0_h_P0S: cpsubla0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpsubla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsubla0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubaca0u_b_P0S: cpsubaca0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpsubaca0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsubaca0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubaca0_b_P0S: cpsubaca0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpsubaca0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsubaca0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubacua0_h_P0S: cpsubacua0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpsubacua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsubacua0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsubacla0_h_P0S: cpsubacla0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpsubacla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsubacla0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsa0u_b_P0S: cpabsa0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpabsa0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpabsa0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsa0_b_P0S: cpabsa0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpabsa0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpabsa0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsua0_h_P0S: cpabsua0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpabsua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
current_cpu->ivc2_cpabsua0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpabsla0_h_P0S: cpabsla0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpabsla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpabsla0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsada0u_b_P0S: cpsada0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpsada0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsada0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsada0_b_P0S: cpsada0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpsada0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsada0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadua0_h_P0S: cpsadua0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpsadua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsadua0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsadla0_h_P0S: cpsadla0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpsadla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpsadla0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpseta0_h_P0S: cpseta0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpseta0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpseta0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsetua0_w_P0S: cpsetua0.w $crqp,$crpp

sem_status
mepcop1_16_sem_cpsetua0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
current_cpu->ivc2_cpsetua0_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsetla0_w_P0S: cpsetla0.w $crqp,$crpp

sem_status
mepcop1_16_sem_cpsetla0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsetla0_w (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmova0_b_P0S: cpmova0.b $crop

sem_status
mepcop1_16_sem_cpmova0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmova0_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovua0_h_P0S: cpmovua0.h $crop

sem_status
mepcop1_16_sem_cpmovua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovua0_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovla0_h_P0S: cpmovla0.h $crop

sem_status
mepcop1_16_sem_cpmovla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovla0_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovuua0_w_P0S: cpmovuua0.w $crop

sem_status
mepcop1_16_sem_cpmovuua0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovuua0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovula0_w_P0S: cpmovula0.w $crop

sem_status
mepcop1_16_sem_cpmovula0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovula0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovlua0_w_P0S: cpmovlua0.w $crop

sem_status
mepcop1_16_sem_cpmovlua0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovlua0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovlla0_w_P0S: cpmovlla0.w $crop

sem_status
mepcop1_16_sem_cpmovlla0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovlla0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacka0u_b_P0S: cppacka0u.b $crop

sem_status
mepcop1_16_sem_cppacka0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacka0u_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppacka0_b_P0S: cppacka0.b $crop

sem_status
mepcop1_16_sem_cppacka0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppacka0_b (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackua0_h_P0S: cppackua0.h $crop

sem_status
mepcop1_16_sem_cppackua0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackua0_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackla0_h_P0S: cppackla0.h $crop

sem_status
mepcop1_16_sem_cppackla0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackla0_h (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackua0_w_P0S: cppackua0.w $crop

sem_status
mepcop1_16_sem_cppackua0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackua0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cppackla0_w_P0S: cppackla0.w $crop

sem_status
mepcop1_16_sem_cppackla0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cppackla0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovhua0_w_P0S: cpmovhua0.w $crop

sem_status
mepcop1_16_sem_cpmovhua0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovhua0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovhla0_w_P0S: cpmovhla0.w $crop

sem_status
mepcop1_16_sem_cpmovhla0_w_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    DI opval = current_cpu->ivc2_cpmovhla0_w (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_ivc2_5u23) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_ivc2_5u23), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpacsuma0_P0S: cpacsuma0

sem_status
mepcop1_16_sem_cpacsuma0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpacsuma0 (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpaccpa0_P0S: cpaccpa0

sem_status
mepcop1_16_sem_cpaccpa0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpaccpa0 (pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrla0_P0S: cpsrla0 $crqp

sem_status
mepcop1_16_sem_cpsrla0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsrla0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsraa0_P0S: cpsraa0 $crqp

sem_status
mepcop1_16_sem_cpsraa0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsraa0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpslla0_P0S: cpslla0 $crqp

sem_status
mepcop1_16_sem_cpslla0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpslla0 (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsrlia0_P0S: cpsrlia0 $imm5p23

sem_status
mepcop1_16_sem_cpsrlia0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsrlia0 (pc, FLD (f_ivc2_5u23));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsraia0_P0S: cpsraia0 $imm5p23

sem_status
mepcop1_16_sem_cpsraia0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsraia0 (pc, FLD (f_ivc2_5u23));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpsllia0_P0S: cpsllia0 $imm5p23

sem_status
mepcop1_16_sem_cpsllia0_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpsllia0 (pc, FLD (f_ivc2_5u23));
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftba0s0u_b_P0S: cpfsftba0s0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftba0s0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpfsftba0s0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftba0s0_b_P0S: cpfsftba0s0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftba0s0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpfsftba0s0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbua0s0_h_P0S: cpfsftbua0s0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftbua0s0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
current_cpu->ivc2_cpfsftbua0s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbla0s0_h_P0S: cpfsftbla0s0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftbla0s0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpfsftbla0s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfaca0s0u_b_P0S: cpfaca0s0u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfaca0s0u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfaca0s0u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfaca0s0_b_P0S: cpfaca0s0.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfaca0s0_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfaca0s0_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfacua0s0_h_P0S: cpfacua0s0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfacua0s0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfacua0s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfacla0s0_h_P0S: cpfacla0s0.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfacla0s0_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfacla0s0_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftba0s1u_b_P0S: cpfsftba0s1u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftba0s1u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpfsftba0s1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftba0s1_b_P0S: cpfsftba0s1.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftba0s1_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpfsftba0s1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbua0s1_h_P0S: cpfsftbua0s1.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftbua0s1_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
current_cpu->ivc2_cpfsftbua0s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfsftbla0s1_h_P0S: cpfsftbla0s1.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfsftbla0s1_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
current_cpu->ivc2_cpfsftbla0s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfaca0s1u_b_P0S: cpfaca0s1u.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfaca0s1u_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfaca0s1u_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfaca0s1_b_P0S: cpfaca0s1.b $crqp,$crpp

sem_status
mepcop1_16_sem_cpfaca0s1_b_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfaca0s1_b (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfacua0s1_h_P0S: cpfacua0s1.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfacua0s1_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfacua0s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpfacla0s1_h_P0S: cpfacla0s1.h $crqp,$crpp

sem_status
mepcop1_16_sem_cpfacla0s1_h_P0S (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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
      current_cpu->trace_stream << "ccr-ivc2" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_ccr_ivc2_set (((UINT) 6), opval);
  }
current_cpu->ivc2_cpfacla0s1_h (pc, current_cpu->hardware.h_cr64[FLD (f_ivc2_5u13)], current_cpu->hardware.h_cr64[FLD (f_ivc2_5u18)]);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cpmovi_b_P0S_P1: cpmovi.b $crqp,$simm8p20

sem_status
mepcop1_16_sem_cpmovi_b_P0S_P1 (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop1_16_scache* abuf = sem;
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

