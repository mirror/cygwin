/* Simulator model support for mepcop1_16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext1.h"

using namespace mep_ext1; // FIXME: namespace organization still wip

/* The profiling data is recorded here, but is accessed via the profiling
   mechanism.  After all, this is information for profiling.  */

/* Model handlers for each insn.  */

mepcop1_16_mep_model::mepcop1_16_mep_model (mep_ext1_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
mepcop1_16_mep_model::model_c0nop_P0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_c0nop_P0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadd3_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadd3_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadd3_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadd3_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadd3_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadd3_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpacku_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpacku_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpacku_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpacku_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpacku_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpacku_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpackl_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpackl_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpackl_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpackl_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpackl_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpunpackl_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsel_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsel_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbs0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbs0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbs1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbs1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmov_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmov_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsz_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsz_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsz_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsz_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsz_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsz_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpldz_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpldz_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpldz_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpldz_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpnorm_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpnorm_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpnorm_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpnorm_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphaddu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphaddu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphadd_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphadd_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphadd_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphadd_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphadd_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cphadd_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpccadd_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpccadd_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpbcast_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpbcast_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpbcast_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpbcast_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpbcast_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpbcast_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextuu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextuu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextuu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextuu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextlu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextlu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextl_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextl_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextlu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextlu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextl_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpextl_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastub_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastub_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastb_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastb_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastub_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastub_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastb_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastb_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastuh_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcastuh_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcasth_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcasth_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cdcastuw_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cdcastuw_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cdcastw_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cdcastw_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovfrcsar0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovfrcsar0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovfrcsar1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovfrcsar1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovfrcc_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovfrcc_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovtocsar0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovtocsar0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovtocsar1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovtocsar1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovtocc_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovtocc_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeqz_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeqz_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeq_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeq_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeq_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeq_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeq_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpeq_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpne_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpne_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpne_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpne_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpne_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpne_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgtu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgtu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgt_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgt_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgt_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgt_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgtu_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgtu_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgt_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgt_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgeu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgeu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpge_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpge_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpge_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpge_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgeu_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpgeu_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpge_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpcmpge_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadda0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadda0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadda0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpadda0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddaca0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddaca0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddaca0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddaca0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddacua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddacua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddacla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaddacla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsuba0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsuba0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsuba0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsuba0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubaca0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubaca0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubaca0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubaca0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubacua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubacua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubacla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsubacla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsa0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsa0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsa0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsa0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpabsla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsada0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsada0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsada0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsada0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsadua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsadua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsadla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsadla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpseta0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpseta0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsetua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsetua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsetla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsetla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmova0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmova0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovuua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovuua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovula0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovula0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovlua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovlua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovlla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovlla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppacka0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppacka0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppacka0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppacka0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cppackla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovhua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovhua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovhla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovhla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpacsuma0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpacsuma0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaccpa0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpaccpa0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsrla0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsrla0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsraa0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsraa0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpslla0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpslla0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsrlia0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsrlia0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsraia0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsraia0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsllia0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpsllia0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbua0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbua0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbla0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbla0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacua0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacua0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacla0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacla0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s1u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s1u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s1_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftba0s1_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbua0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbua0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbla0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfsftbla0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s1u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s1u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s1_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfaca0s1_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacua0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacua0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacla0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpfacla0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpadd3_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovi_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_16_mep_model::model_cpmovi_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_P0S_P1.f
  const mepcop1_16_scache* abuf = sem;
  const mepcop1_16_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

/* We assume UNIT_NONE == 0 because the tables don't always terminate
   entries with it.  */

/* Model timing data for `mep'.  */

const mepcop1_16_mep_model::insn_timing mepcop1_16_mep_model::timing[] = {
  { MEPCOP1_16_INSN_X_INVALID, 0, 0, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_C0NOP_P0_P0S, & mepcop1_16_mep_model::model_c0nop_P0_P0S_before, & mepcop1_16_mep_model::model_c0nop_P0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADD3_B_P0S_P1, & mepcop1_16_mep_model::model_cpadd3_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpadd3_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADD3_H_P0S_P1, & mepcop1_16_mep_model::model_cpadd3_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpadd3_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADD3_W_P0S_P1, & mepcop1_16_mep_model::model_cpadd3_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpadd3_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPUNPACKU_B_P0S_P1, & mepcop1_16_mep_model::model_cpunpacku_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpunpacku_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPUNPACKU_H_P0S_P1, & mepcop1_16_mep_model::model_cpunpacku_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpunpacku_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPUNPACKU_W_P0S_P1, & mepcop1_16_mep_model::model_cpunpacku_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpunpacku_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPUNPACKL_B_P0S_P1, & mepcop1_16_mep_model::model_cpunpackl_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpunpackl_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPUNPACKL_H_P0S_P1, & mepcop1_16_mep_model::model_cpunpackl_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpunpackl_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPUNPACKL_W_P0S_P1, & mepcop1_16_mep_model::model_cpunpackl_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpunpackl_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSEL_P0S_P1, & mepcop1_16_mep_model::model_cpsel_P0S_P1_before, & mepcop1_16_mep_model::model_cpsel_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBS0_P0S_P1, & mepcop1_16_mep_model::model_cpfsftbs0_P0S_P1_before, & mepcop1_16_mep_model::model_cpfsftbs0_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBS1_P0S_P1, & mepcop1_16_mep_model::model_cpfsftbs1_P0S_P1_before, & mepcop1_16_mep_model::model_cpfsftbs1_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOV_P0S_P1, & mepcop1_16_mep_model::model_cpmov_P0S_P1_before, & mepcop1_16_mep_model::model_cpmov_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSZ_B_P0S_P1, & mepcop1_16_mep_model::model_cpabsz_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpabsz_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSZ_H_P0S_P1, & mepcop1_16_mep_model::model_cpabsz_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpabsz_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSZ_W_P0S_P1, & mepcop1_16_mep_model::model_cpabsz_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpabsz_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPLDZ_H_P0S_P1, & mepcop1_16_mep_model::model_cpldz_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpldz_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPLDZ_W_P0S_P1, & mepcop1_16_mep_model::model_cpldz_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpldz_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPNORM_H_P0S_P1, & mepcop1_16_mep_model::model_cpnorm_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpnorm_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPNORM_W_P0S_P1, & mepcop1_16_mep_model::model_cpnorm_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpnorm_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPHADDU_B_P0S_P1, & mepcop1_16_mep_model::model_cphaddu_b_P0S_P1_before, & mepcop1_16_mep_model::model_cphaddu_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPHADD_B_P0S_P1, & mepcop1_16_mep_model::model_cphadd_b_P0S_P1_before, & mepcop1_16_mep_model::model_cphadd_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPHADD_H_P0S_P1, & mepcop1_16_mep_model::model_cphadd_h_P0S_P1_before, & mepcop1_16_mep_model::model_cphadd_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPHADD_W_P0S_P1, & mepcop1_16_mep_model::model_cphadd_w_P0S_P1_before, & mepcop1_16_mep_model::model_cphadd_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCCADD_B_P0S_P1, & mepcop1_16_mep_model::model_cpccadd_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpccadd_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPBCAST_B_P0S_P1, & mepcop1_16_mep_model::model_cpbcast_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpbcast_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPBCAST_H_P0S_P1, & mepcop1_16_mep_model::model_cpbcast_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpbcast_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPBCAST_W_P0S_P1, & mepcop1_16_mep_model::model_cpbcast_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpbcast_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTUU_B_P0S_P1, & mepcop1_16_mep_model::model_cpextuu_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpextuu_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTU_B_P0S_P1, & mepcop1_16_mep_model::model_cpextu_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpextu_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTUU_H_P0S_P1, & mepcop1_16_mep_model::model_cpextuu_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpextuu_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTU_H_P0S_P1, & mepcop1_16_mep_model::model_cpextu_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpextu_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTLU_B_P0S_P1, & mepcop1_16_mep_model::model_cpextlu_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpextlu_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTL_B_P0S_P1, & mepcop1_16_mep_model::model_cpextl_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpextl_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTLU_H_P0S_P1, & mepcop1_16_mep_model::model_cpextlu_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpextlu_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPEXTL_H_P0S_P1, & mepcop1_16_mep_model::model_cpextl_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpextl_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCASTUB_H_P0S_P1, & mepcop1_16_mep_model::model_cpcastub_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpcastub_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCASTB_H_P0S_P1, & mepcop1_16_mep_model::model_cpcastb_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpcastb_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCASTUB_W_P0S_P1, & mepcop1_16_mep_model::model_cpcastub_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcastub_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCASTB_W_P0S_P1, & mepcop1_16_mep_model::model_cpcastb_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcastb_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCASTUH_W_P0S_P1, & mepcop1_16_mep_model::model_cpcastuh_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcastuh_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCASTH_W_P0S_P1, & mepcop1_16_mep_model::model_cpcasth_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcasth_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CDCASTUW_P0S_P1, & mepcop1_16_mep_model::model_cdcastuw_P0S_P1_before, & mepcop1_16_mep_model::model_cdcastuw_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CDCASTW_P0S_P1, & mepcop1_16_mep_model::model_cdcastw_P0S_P1_before, & mepcop1_16_mep_model::model_cdcastw_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVFRCSAR0_P0S_P1, & mepcop1_16_mep_model::model_cpmovfrcsar0_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovfrcsar0_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVFRCSAR1_P0S_P1, & mepcop1_16_mep_model::model_cpmovfrcsar1_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovfrcsar1_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVFRCC_P0S_P1, & mepcop1_16_mep_model::model_cpmovfrcc_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovfrcc_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVTOCSAR0_P0S_P1, & mepcop1_16_mep_model::model_cpmovtocsar0_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovtocsar0_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVTOCSAR1_P0S_P1, & mepcop1_16_mep_model::model_cpmovtocsar1_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovtocsar1_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVTOCC_P0S_P1, & mepcop1_16_mep_model::model_cpmovtocc_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovtocc_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPEQZ_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpeqz_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpeqz_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPEQ_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpeq_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpeq_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPEQ_H_P0S_P1, & mepcop1_16_mep_model::model_cpcmpeq_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpeq_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPEQ_W_P0S_P1, & mepcop1_16_mep_model::model_cpcmpeq_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpeq_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPNE_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpne_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpne_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPNE_H_P0S_P1, & mepcop1_16_mep_model::model_cpcmpne_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpne_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPNE_W_P0S_P1, & mepcop1_16_mep_model::model_cpcmpne_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpne_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGTU_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgtu_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgtu_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGT_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgt_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgt_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGT_H_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgt_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgt_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGTU_W_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgtu_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgtu_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGT_W_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgt_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgt_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGEU_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgeu_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgeu_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGE_B_P0S_P1, & mepcop1_16_mep_model::model_cpcmpge_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpge_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGE_H_P0S_P1, & mepcop1_16_mep_model::model_cpcmpge_h_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpge_h_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGEU_W_P0S_P1, & mepcop1_16_mep_model::model_cpcmpgeu_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpgeu_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPCMPGE_W_P0S_P1, & mepcop1_16_mep_model::model_cpcmpge_w_P0S_P1_before, & mepcop1_16_mep_model::model_cpcmpge_w_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDA0U_B_P0S, & mepcop1_16_mep_model::model_cpadda0u_b_P0S_before, & mepcop1_16_mep_model::model_cpadda0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDA0_B_P0S, & mepcop1_16_mep_model::model_cpadda0_b_P0S_before, & mepcop1_16_mep_model::model_cpadda0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDUA0_H_P0S, & mepcop1_16_mep_model::model_cpaddua0_h_P0S_before, & mepcop1_16_mep_model::model_cpaddua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDLA0_H_P0S, & mepcop1_16_mep_model::model_cpaddla0_h_P0S_before, & mepcop1_16_mep_model::model_cpaddla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDACA0U_B_P0S, & mepcop1_16_mep_model::model_cpaddaca0u_b_P0S_before, & mepcop1_16_mep_model::model_cpaddaca0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDACA0_B_P0S, & mepcop1_16_mep_model::model_cpaddaca0_b_P0S_before, & mepcop1_16_mep_model::model_cpaddaca0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDACUA0_H_P0S, & mepcop1_16_mep_model::model_cpaddacua0_h_P0S_before, & mepcop1_16_mep_model::model_cpaddacua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPADDACLA0_H_P0S, & mepcop1_16_mep_model::model_cpaddacla0_h_P0S_before, & mepcop1_16_mep_model::model_cpaddacla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBA0U_B_P0S, & mepcop1_16_mep_model::model_cpsuba0u_b_P0S_before, & mepcop1_16_mep_model::model_cpsuba0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBA0_B_P0S, & mepcop1_16_mep_model::model_cpsuba0_b_P0S_before, & mepcop1_16_mep_model::model_cpsuba0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBUA0_H_P0S, & mepcop1_16_mep_model::model_cpsubua0_h_P0S_before, & mepcop1_16_mep_model::model_cpsubua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBLA0_H_P0S, & mepcop1_16_mep_model::model_cpsubla0_h_P0S_before, & mepcop1_16_mep_model::model_cpsubla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBACA0U_B_P0S, & mepcop1_16_mep_model::model_cpsubaca0u_b_P0S_before, & mepcop1_16_mep_model::model_cpsubaca0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBACA0_B_P0S, & mepcop1_16_mep_model::model_cpsubaca0_b_P0S_before, & mepcop1_16_mep_model::model_cpsubaca0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBACUA0_H_P0S, & mepcop1_16_mep_model::model_cpsubacua0_h_P0S_before, & mepcop1_16_mep_model::model_cpsubacua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSUBACLA0_H_P0S, & mepcop1_16_mep_model::model_cpsubacla0_h_P0S_before, & mepcop1_16_mep_model::model_cpsubacla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSA0U_B_P0S, & mepcop1_16_mep_model::model_cpabsa0u_b_P0S_before, & mepcop1_16_mep_model::model_cpabsa0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSA0_B_P0S, & mepcop1_16_mep_model::model_cpabsa0_b_P0S_before, & mepcop1_16_mep_model::model_cpabsa0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSUA0_H_P0S, & mepcop1_16_mep_model::model_cpabsua0_h_P0S_before, & mepcop1_16_mep_model::model_cpabsua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPABSLA0_H_P0S, & mepcop1_16_mep_model::model_cpabsla0_h_P0S_before, & mepcop1_16_mep_model::model_cpabsla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSADA0U_B_P0S, & mepcop1_16_mep_model::model_cpsada0u_b_P0S_before, & mepcop1_16_mep_model::model_cpsada0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSADA0_B_P0S, & mepcop1_16_mep_model::model_cpsada0_b_P0S_before, & mepcop1_16_mep_model::model_cpsada0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSADUA0_H_P0S, & mepcop1_16_mep_model::model_cpsadua0_h_P0S_before, & mepcop1_16_mep_model::model_cpsadua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSADLA0_H_P0S, & mepcop1_16_mep_model::model_cpsadla0_h_P0S_before, & mepcop1_16_mep_model::model_cpsadla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSETA0_H_P0S, & mepcop1_16_mep_model::model_cpseta0_h_P0S_before, & mepcop1_16_mep_model::model_cpseta0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSETUA0_W_P0S, & mepcop1_16_mep_model::model_cpsetua0_w_P0S_before, & mepcop1_16_mep_model::model_cpsetua0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSETLA0_W_P0S, & mepcop1_16_mep_model::model_cpsetla0_w_P0S_before, & mepcop1_16_mep_model::model_cpsetla0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVA0_B_P0S, & mepcop1_16_mep_model::model_cpmova0_b_P0S_before, & mepcop1_16_mep_model::model_cpmova0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVUA0_H_P0S, & mepcop1_16_mep_model::model_cpmovua0_h_P0S_before, & mepcop1_16_mep_model::model_cpmovua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVLA0_H_P0S, & mepcop1_16_mep_model::model_cpmovla0_h_P0S_before, & mepcop1_16_mep_model::model_cpmovla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVUUA0_W_P0S, & mepcop1_16_mep_model::model_cpmovuua0_w_P0S_before, & mepcop1_16_mep_model::model_cpmovuua0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVULA0_W_P0S, & mepcop1_16_mep_model::model_cpmovula0_w_P0S_before, & mepcop1_16_mep_model::model_cpmovula0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVLUA0_W_P0S, & mepcop1_16_mep_model::model_cpmovlua0_w_P0S_before, & mepcop1_16_mep_model::model_cpmovlua0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVLLA0_W_P0S, & mepcop1_16_mep_model::model_cpmovlla0_w_P0S_before, & mepcop1_16_mep_model::model_cpmovlla0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPPACKA0U_B_P0S, & mepcop1_16_mep_model::model_cppacka0u_b_P0S_before, & mepcop1_16_mep_model::model_cppacka0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPPACKA0_B_P0S, & mepcop1_16_mep_model::model_cppacka0_b_P0S_before, & mepcop1_16_mep_model::model_cppacka0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPPACKUA0_H_P0S, & mepcop1_16_mep_model::model_cppackua0_h_P0S_before, & mepcop1_16_mep_model::model_cppackua0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPPACKLA0_H_P0S, & mepcop1_16_mep_model::model_cppackla0_h_P0S_before, & mepcop1_16_mep_model::model_cppackla0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPPACKUA0_W_P0S, & mepcop1_16_mep_model::model_cppackua0_w_P0S_before, & mepcop1_16_mep_model::model_cppackua0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPPACKLA0_W_P0S, & mepcop1_16_mep_model::model_cppackla0_w_P0S_before, & mepcop1_16_mep_model::model_cppackla0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVHUA0_W_P0S, & mepcop1_16_mep_model::model_cpmovhua0_w_P0S_before, & mepcop1_16_mep_model::model_cpmovhua0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVHLA0_W_P0S, & mepcop1_16_mep_model::model_cpmovhla0_w_P0S_before, & mepcop1_16_mep_model::model_cpmovhla0_w_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPACSUMA0_P0S, & mepcop1_16_mep_model::model_cpacsuma0_P0S_before, & mepcop1_16_mep_model::model_cpacsuma0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPACCPA0_P0S, & mepcop1_16_mep_model::model_cpaccpa0_P0S_before, & mepcop1_16_mep_model::model_cpaccpa0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSRLA0_P0S, & mepcop1_16_mep_model::model_cpsrla0_P0S_before, & mepcop1_16_mep_model::model_cpsrla0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSRAA0_P0S, & mepcop1_16_mep_model::model_cpsraa0_P0S_before, & mepcop1_16_mep_model::model_cpsraa0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSLLA0_P0S, & mepcop1_16_mep_model::model_cpslla0_P0S_before, & mepcop1_16_mep_model::model_cpslla0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSRLIA0_P0S, & mepcop1_16_mep_model::model_cpsrlia0_P0S_before, & mepcop1_16_mep_model::model_cpsrlia0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSRAIA0_P0S, & mepcop1_16_mep_model::model_cpsraia0_P0S_before, & mepcop1_16_mep_model::model_cpsraia0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPSLLIA0_P0S, & mepcop1_16_mep_model::model_cpsllia0_P0S_before, & mepcop1_16_mep_model::model_cpsllia0_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBA0S0U_B_P0S, & mepcop1_16_mep_model::model_cpfsftba0s0u_b_P0S_before, & mepcop1_16_mep_model::model_cpfsftba0s0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBA0S0_B_P0S, & mepcop1_16_mep_model::model_cpfsftba0s0_b_P0S_before, & mepcop1_16_mep_model::model_cpfsftba0s0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBUA0S0_H_P0S, & mepcop1_16_mep_model::model_cpfsftbua0s0_h_P0S_before, & mepcop1_16_mep_model::model_cpfsftbua0s0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBLA0S0_H_P0S, & mepcop1_16_mep_model::model_cpfsftbla0s0_h_P0S_before, & mepcop1_16_mep_model::model_cpfsftbla0s0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACA0S0U_B_P0S, & mepcop1_16_mep_model::model_cpfaca0s0u_b_P0S_before, & mepcop1_16_mep_model::model_cpfaca0s0u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACA0S0_B_P0S, & mepcop1_16_mep_model::model_cpfaca0s0_b_P0S_before, & mepcop1_16_mep_model::model_cpfaca0s0_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACUA0S0_H_P0S, & mepcop1_16_mep_model::model_cpfacua0s0_h_P0S_before, & mepcop1_16_mep_model::model_cpfacua0s0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACLA0S0_H_P0S, & mepcop1_16_mep_model::model_cpfacla0s0_h_P0S_before, & mepcop1_16_mep_model::model_cpfacla0s0_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBA0S1U_B_P0S, & mepcop1_16_mep_model::model_cpfsftba0s1u_b_P0S_before, & mepcop1_16_mep_model::model_cpfsftba0s1u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBA0S1_B_P0S, & mepcop1_16_mep_model::model_cpfsftba0s1_b_P0S_before, & mepcop1_16_mep_model::model_cpfsftba0s1_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBUA0S1_H_P0S, & mepcop1_16_mep_model::model_cpfsftbua0s1_h_P0S_before, & mepcop1_16_mep_model::model_cpfsftbua0s1_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFSFTBLA0S1_H_P0S, & mepcop1_16_mep_model::model_cpfsftbla0s1_h_P0S_before, & mepcop1_16_mep_model::model_cpfsftbla0s1_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACA0S1U_B_P0S, & mepcop1_16_mep_model::model_cpfaca0s1u_b_P0S_before, & mepcop1_16_mep_model::model_cpfaca0s1u_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACA0S1_B_P0S, & mepcop1_16_mep_model::model_cpfaca0s1_b_P0S_before, & mepcop1_16_mep_model::model_cpfaca0s1_b_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACUA0S1_H_P0S, & mepcop1_16_mep_model::model_cpfacua0s1_h_P0S_before, & mepcop1_16_mep_model::model_cpfacua0s1_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPFACLA0S1_H_P0S, & mepcop1_16_mep_model::model_cpfacla0s1_h_P0S_before, & mepcop1_16_mep_model::model_cpfacla0s1_h_P0S_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_16_INSN_CPMOVI_B_P0S_P1, & mepcop1_16_mep_model::model_cpmovi_b_P0S_P1_before, & mepcop1_16_mep_model::model_cpmovi_b_P0S_P1_after, { { mepcop1_16_mep_model::UNIT_U_EXEC, 1, 1 } } },
};

