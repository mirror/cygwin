/* Simulator model support for mepcop1_48.

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

mepcop1_48_mep_model::mepcop1_48_mep_model (mep_ext1_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
mepcop1_48_mep_model::model_cmov_crn_rm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cmov_crn_rm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cmov_rn_crm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cmov_rn_crm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cmovc_ccrn_rm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cmovc_ccrn_rm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cmovc_rn_ccrm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cmovc_rn_ccrm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cmovh_crn_rm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cmovh_crn_rm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cmovh_rn_crm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cmovh_rn_crm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm_p0.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_c0nop_P0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_c0nop_P0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpfsftbi_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpfsftbi_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpeq_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpeq_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpeq_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpeq_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpeq_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpeq_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpne_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpne_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpne_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpne_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpne_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpne_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgtu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgtu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgt_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgt_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgt_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgt_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgtu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgtu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgt_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgt_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgeu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgeu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpge_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpge_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpge_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpge_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpgeu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpgeu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpacmpge_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpacmpge_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpeq_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpeq_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpeq_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpeq_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpeq_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpeq_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpne_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpne_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpne_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpne_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpne_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpne_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgtu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgtu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgt_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgt_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgt_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgt_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgtu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgtu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgt_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgt_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgeu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgeu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpge_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpge_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpge_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpge_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpgeu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpgeu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpocmpge_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpocmpge_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdadd3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdadd3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsub3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsub3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsub3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsub3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdsub3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdsub3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsadd3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsadd3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsadd3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsadd3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssub3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssub3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssub3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssub3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextuaddu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextuaddu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextuadd3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextuadd3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextladdu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextladdu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextladd3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextladd3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextusubu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextusubu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextusub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextusub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextlsubu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextlsubu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpextlsub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpextlsub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpaveu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpaveu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpave3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpave3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpave3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpave3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpave3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpave3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpaddsru3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpaddsru3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpaddsr3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpaddsr3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpaddsr3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpaddsr3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpaddsr3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpaddsr3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpabsu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpabsu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpabs3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpabs3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpabs3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpabs3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpand3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpand3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpnor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpnor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpxor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpxor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cppacku_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cppacku_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cppack_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cppack_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cppack_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cppack_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmaxu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmaxu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmax3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmax3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmax3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmax3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmaxu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmaxu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmax3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmax3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpminu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpminu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmin3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmin3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmin3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmin3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpminu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpminu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmin3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmin3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrl3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrl3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssrl3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssrl3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrl3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrl3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssrl3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssrl3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrl3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrl3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssrl3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssrl3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdsrl3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdsrl3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsra3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsra3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssra3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssra3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsra3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsra3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssra3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssra3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsra3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsra3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssra3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssra3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdsra3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdsra3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsll3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsll3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssll3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssll3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsll3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsll3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssll3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssll3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsll3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsll3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpssll3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpssll3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdsll3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdsll3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsla3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsla3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsla3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsla3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrli3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrli3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrli3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrli3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrli3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrli3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdsrli3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdsrli3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrai3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrai3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrai3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrai3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpsrai3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpsrai3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdsrai3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdsrai3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpslli3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpslli3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpslli3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpslli3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpslli3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpslli3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdslli3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdslli3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpslai3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpslai3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpslai3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpslai3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpclipiu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpclipiu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpclipi3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpclipi3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdclipiu3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdclipiu3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdclipi3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdclipi3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmovi_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmovi_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmoviu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmoviu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cpmovi_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cpmovi_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdmoviu_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdmoviu_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_w_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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
mepcop1_48_mep_model::model_cdmovi_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_48_mep_model::model_cdmovi_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_h_P0_P1.f
  const mepcop1_48_scache* abuf = sem;
  const mepcop1_48_idesc* idesc = abuf->idesc;
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

const mepcop1_48_mep_model::insn_timing mepcop1_48_mep_model::timing[] = {
  { MEPCOP1_48_INSN_X_INVALID, 0, 0, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CMOV_CRN_RM_P0, & mepcop1_48_mep_model::model_cmov_crn_rm_p0_before, & mepcop1_48_mep_model::model_cmov_crn_rm_p0_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CMOV_RN_CRM_P0, & mepcop1_48_mep_model::model_cmov_rn_crm_p0_before, & mepcop1_48_mep_model::model_cmov_rn_crm_p0_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CMOVC_CCRN_RM_P0, & mepcop1_48_mep_model::model_cmovc_ccrn_rm_p0_before, & mepcop1_48_mep_model::model_cmovc_ccrn_rm_p0_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CMOVC_RN_CCRM_P0, & mepcop1_48_mep_model::model_cmovc_rn_ccrm_p0_before, & mepcop1_48_mep_model::model_cmovc_rn_ccrm_p0_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CMOVH_CRN_RM_P0, & mepcop1_48_mep_model::model_cmovh_crn_rm_p0_before, & mepcop1_48_mep_model::model_cmovh_crn_rm_p0_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CMOVH_RN_CRM_P0, & mepcop1_48_mep_model::model_cmovh_rn_crm_p0_before, & mepcop1_48_mep_model::model_cmovh_rn_crm_p0_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_C0NOP_P0_P0S, & mepcop1_48_mep_model::model_c0nop_P0_P0S_before, & mepcop1_48_mep_model::model_c0nop_P0_P0S_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPFSFTBI_P0_P1, & mepcop1_48_mep_model::model_cpfsftbi_P0_P1_before, & mepcop1_48_mep_model::model_cpfsftbi_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPEQ_B_P0_P1, & mepcop1_48_mep_model::model_cpacmpeq_b_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpeq_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPEQ_H_P0_P1, & mepcop1_48_mep_model::model_cpacmpeq_h_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpeq_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPEQ_W_P0_P1, & mepcop1_48_mep_model::model_cpacmpeq_w_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpeq_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPNE_B_P0_P1, & mepcop1_48_mep_model::model_cpacmpne_b_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpne_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPNE_H_P0_P1, & mepcop1_48_mep_model::model_cpacmpne_h_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpne_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPNE_W_P0_P1, & mepcop1_48_mep_model::model_cpacmpne_w_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpne_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGTU_B_P0_P1, & mepcop1_48_mep_model::model_cpacmpgtu_b_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgtu_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGT_B_P0_P1, & mepcop1_48_mep_model::model_cpacmpgt_b_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgt_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGT_H_P0_P1, & mepcop1_48_mep_model::model_cpacmpgt_h_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgt_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGTU_W_P0_P1, & mepcop1_48_mep_model::model_cpacmpgtu_w_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgtu_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGT_W_P0_P1, & mepcop1_48_mep_model::model_cpacmpgt_w_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgt_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGEU_B_P0_P1, & mepcop1_48_mep_model::model_cpacmpgeu_b_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgeu_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGE_B_P0_P1, & mepcop1_48_mep_model::model_cpacmpge_b_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpge_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGE_H_P0_P1, & mepcop1_48_mep_model::model_cpacmpge_h_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpge_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGEU_W_P0_P1, & mepcop1_48_mep_model::model_cpacmpgeu_w_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpgeu_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPACMPGE_W_P0_P1, & mepcop1_48_mep_model::model_cpacmpge_w_P0_P1_before, & mepcop1_48_mep_model::model_cpacmpge_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPEQ_B_P0_P1, & mepcop1_48_mep_model::model_cpocmpeq_b_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpeq_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPEQ_H_P0_P1, & mepcop1_48_mep_model::model_cpocmpeq_h_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpeq_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPEQ_W_P0_P1, & mepcop1_48_mep_model::model_cpocmpeq_w_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpeq_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPNE_B_P0_P1, & mepcop1_48_mep_model::model_cpocmpne_b_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpne_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPNE_H_P0_P1, & mepcop1_48_mep_model::model_cpocmpne_h_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpne_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPNE_W_P0_P1, & mepcop1_48_mep_model::model_cpocmpne_w_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpne_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGTU_B_P0_P1, & mepcop1_48_mep_model::model_cpocmpgtu_b_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgtu_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGT_B_P0_P1, & mepcop1_48_mep_model::model_cpocmpgt_b_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgt_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGT_H_P0_P1, & mepcop1_48_mep_model::model_cpocmpgt_h_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgt_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGTU_W_P0_P1, & mepcop1_48_mep_model::model_cpocmpgtu_w_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgtu_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGT_W_P0_P1, & mepcop1_48_mep_model::model_cpocmpgt_w_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgt_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGEU_B_P0_P1, & mepcop1_48_mep_model::model_cpocmpgeu_b_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgeu_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGE_B_P0_P1, & mepcop1_48_mep_model::model_cpocmpge_b_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpge_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGE_H_P0_P1, & mepcop1_48_mep_model::model_cpocmpge_h_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpge_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGEU_W_P0_P1, & mepcop1_48_mep_model::model_cpocmpgeu_w_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpgeu_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOCMPGE_W_P0_P1, & mepcop1_48_mep_model::model_cpocmpge_w_P0_P1_before, & mepcop1_48_mep_model::model_cpocmpge_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDADD3_P0_P1, & mepcop1_48_mep_model::model_cdadd3_P0_P1_before, & mepcop1_48_mep_model::model_cdadd3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSUB3_B_P0_P1, & mepcop1_48_mep_model::model_cpsub3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpsub3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSUB3_H_P0_P1, & mepcop1_48_mep_model::model_cpsub3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsub3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSUB3_W_P0_P1, & mepcop1_48_mep_model::model_cpsub3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsub3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSUB3_P0_P1, & mepcop1_48_mep_model::model_cdsub3_P0_P1_before, & mepcop1_48_mep_model::model_cdsub3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSADD3_H_P0_P1, & mepcop1_48_mep_model::model_cpsadd3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsadd3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSADD3_W_P0_P1, & mepcop1_48_mep_model::model_cpsadd3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsadd3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSUB3_H_P0_P1, & mepcop1_48_mep_model::model_cpssub3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpssub3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSUB3_W_P0_P1, & mepcop1_48_mep_model::model_cpssub3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpssub3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTUADDU3_B_P0_P1, & mepcop1_48_mep_model::model_cpextuaddu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextuaddu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTUADD3_B_P0_P1, & mepcop1_48_mep_model::model_cpextuadd3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextuadd3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTLADDU3_B_P0_P1, & mepcop1_48_mep_model::model_cpextladdu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextladdu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTLADD3_B_P0_P1, & mepcop1_48_mep_model::model_cpextladd3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextladd3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTUSUBU3_B_P0_P1, & mepcop1_48_mep_model::model_cpextusubu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextusubu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTUSUB3_B_P0_P1, & mepcop1_48_mep_model::model_cpextusub3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextusub3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTLSUBU3_B_P0_P1, & mepcop1_48_mep_model::model_cpextlsubu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextlsubu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPEXTLSUB3_B_P0_P1, & mepcop1_48_mep_model::model_cpextlsub3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpextlsub3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPAVEU3_B_P0_P1, & mepcop1_48_mep_model::model_cpaveu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpaveu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPAVE3_B_P0_P1, & mepcop1_48_mep_model::model_cpave3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpave3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPAVE3_H_P0_P1, & mepcop1_48_mep_model::model_cpave3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpave3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPAVE3_W_P0_P1, & mepcop1_48_mep_model::model_cpave3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpave3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPADDSRU3_B_P0_P1, & mepcop1_48_mep_model::model_cpaddsru3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpaddsru3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPADDSR3_B_P0_P1, & mepcop1_48_mep_model::model_cpaddsr3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpaddsr3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPADDSR3_H_P0_P1, & mepcop1_48_mep_model::model_cpaddsr3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpaddsr3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPADDSR3_W_P0_P1, & mepcop1_48_mep_model::model_cpaddsr3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpaddsr3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPABSU3_B_P0_P1, & mepcop1_48_mep_model::model_cpabsu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpabsu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPABS3_B_P0_P1, & mepcop1_48_mep_model::model_cpabs3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpabs3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPABS3_H_P0_P1, & mepcop1_48_mep_model::model_cpabs3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpabs3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPAND3_P0_P1, & mepcop1_48_mep_model::model_cpand3_P0_P1_before, & mepcop1_48_mep_model::model_cpand3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPOR3_P0_P1, & mepcop1_48_mep_model::model_cpor3_P0_P1_before, & mepcop1_48_mep_model::model_cpor3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPNOR3_P0_P1, & mepcop1_48_mep_model::model_cpnor3_P0_P1_before, & mepcop1_48_mep_model::model_cpnor3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPXOR3_P0_P1, & mepcop1_48_mep_model::model_cpxor3_P0_P1_before, & mepcop1_48_mep_model::model_cpxor3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPPACKU_B_P0_P1, & mepcop1_48_mep_model::model_cppacku_b_P0_P1_before, & mepcop1_48_mep_model::model_cppacku_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPPACK_B_P0_P1, & mepcop1_48_mep_model::model_cppack_b_P0_P1_before, & mepcop1_48_mep_model::model_cppack_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPPACK_H_P0_P1, & mepcop1_48_mep_model::model_cppack_h_P0_P1_before, & mepcop1_48_mep_model::model_cppack_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMAXU3_B_P0_P1, & mepcop1_48_mep_model::model_cpmaxu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpmaxu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMAX3_B_P0_P1, & mepcop1_48_mep_model::model_cpmax3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpmax3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMAX3_H_P0_P1, & mepcop1_48_mep_model::model_cpmax3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpmax3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMAXU3_W_P0_P1, & mepcop1_48_mep_model::model_cpmaxu3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpmaxu3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMAX3_W_P0_P1, & mepcop1_48_mep_model::model_cpmax3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpmax3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMINU3_B_P0_P1, & mepcop1_48_mep_model::model_cpminu3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpminu3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMIN3_B_P0_P1, & mepcop1_48_mep_model::model_cpmin3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpmin3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMIN3_H_P0_P1, & mepcop1_48_mep_model::model_cpmin3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpmin3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMINU3_W_P0_P1, & mepcop1_48_mep_model::model_cpminu3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpminu3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMIN3_W_P0_P1, & mepcop1_48_mep_model::model_cpmin3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpmin3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRL3_B_P0_P1, & mepcop1_48_mep_model::model_cpsrl3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpsrl3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSRL3_B_P0_P1, & mepcop1_48_mep_model::model_cpssrl3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpssrl3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRL3_H_P0_P1, & mepcop1_48_mep_model::model_cpsrl3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsrl3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSRL3_H_P0_P1, & mepcop1_48_mep_model::model_cpssrl3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpssrl3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRL3_W_P0_P1, & mepcop1_48_mep_model::model_cpsrl3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsrl3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSRL3_W_P0_P1, & mepcop1_48_mep_model::model_cpssrl3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpssrl3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSRL3_P0_P1, & mepcop1_48_mep_model::model_cdsrl3_P0_P1_before, & mepcop1_48_mep_model::model_cdsrl3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRA3_B_P0_P1, & mepcop1_48_mep_model::model_cpsra3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpsra3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSRA3_B_P0_P1, & mepcop1_48_mep_model::model_cpssra3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpssra3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRA3_H_P0_P1, & mepcop1_48_mep_model::model_cpsra3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsra3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSRA3_H_P0_P1, & mepcop1_48_mep_model::model_cpssra3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpssra3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRA3_W_P0_P1, & mepcop1_48_mep_model::model_cpsra3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsra3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSRA3_W_P0_P1, & mepcop1_48_mep_model::model_cpssra3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpssra3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSRA3_P0_P1, & mepcop1_48_mep_model::model_cdsra3_P0_P1_before, & mepcop1_48_mep_model::model_cdsra3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLL3_B_P0_P1, & mepcop1_48_mep_model::model_cpsll3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpsll3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSLL3_B_P0_P1, & mepcop1_48_mep_model::model_cpssll3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpssll3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLL3_H_P0_P1, & mepcop1_48_mep_model::model_cpsll3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsll3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSLL3_H_P0_P1, & mepcop1_48_mep_model::model_cpssll3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpssll3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLL3_W_P0_P1, & mepcop1_48_mep_model::model_cpsll3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsll3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSSLL3_W_P0_P1, & mepcop1_48_mep_model::model_cpssll3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpssll3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSLL3_P0_P1, & mepcop1_48_mep_model::model_cdsll3_P0_P1_before, & mepcop1_48_mep_model::model_cdsll3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLA3_H_P0_P1, & mepcop1_48_mep_model::model_cpsla3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsla3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLA3_W_P0_P1, & mepcop1_48_mep_model::model_cpsla3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsla3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRLI3_B_P0_P1, & mepcop1_48_mep_model::model_cpsrli3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpsrli3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRLI3_H_P0_P1, & mepcop1_48_mep_model::model_cpsrli3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsrli3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRLI3_W_P0_P1, & mepcop1_48_mep_model::model_cpsrli3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsrli3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSRLI3_P0_P1, & mepcop1_48_mep_model::model_cdsrli3_P0_P1_before, & mepcop1_48_mep_model::model_cdsrli3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRAI3_B_P0_P1, & mepcop1_48_mep_model::model_cpsrai3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpsrai3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRAI3_H_P0_P1, & mepcop1_48_mep_model::model_cpsrai3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpsrai3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSRAI3_W_P0_P1, & mepcop1_48_mep_model::model_cpsrai3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpsrai3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSRAI3_P0_P1, & mepcop1_48_mep_model::model_cdsrai3_P0_P1_before, & mepcop1_48_mep_model::model_cdsrai3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLLI3_B_P0_P1, & mepcop1_48_mep_model::model_cpslli3_b_P0_P1_before, & mepcop1_48_mep_model::model_cpslli3_b_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLLI3_H_P0_P1, & mepcop1_48_mep_model::model_cpslli3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpslli3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLLI3_W_P0_P1, & mepcop1_48_mep_model::model_cpslli3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpslli3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDSLLI3_P0_P1, & mepcop1_48_mep_model::model_cdslli3_P0_P1_before, & mepcop1_48_mep_model::model_cdslli3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLAI3_H_P0_P1, & mepcop1_48_mep_model::model_cpslai3_h_P0_P1_before, & mepcop1_48_mep_model::model_cpslai3_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPSLAI3_W_P0_P1, & mepcop1_48_mep_model::model_cpslai3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpslai3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPCLIPIU3_W_P0_P1, & mepcop1_48_mep_model::model_cpclipiu3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpclipiu3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPCLIPI3_W_P0_P1, & mepcop1_48_mep_model::model_cpclipi3_w_P0_P1_before, & mepcop1_48_mep_model::model_cpclipi3_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDCLIPIU3_P0_P1, & mepcop1_48_mep_model::model_cdclipiu3_P0_P1_before, & mepcop1_48_mep_model::model_cdclipiu3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDCLIPI3_P0_P1, & mepcop1_48_mep_model::model_cdclipi3_P0_P1_before, & mepcop1_48_mep_model::model_cdclipi3_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMOVI_H_P0_P1, & mepcop1_48_mep_model::model_cpmovi_h_P0_P1_before, & mepcop1_48_mep_model::model_cpmovi_h_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMOVIU_W_P0_P1, & mepcop1_48_mep_model::model_cpmoviu_w_P0_P1_before, & mepcop1_48_mep_model::model_cpmoviu_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CPMOVI_W_P0_P1, & mepcop1_48_mep_model::model_cpmovi_w_P0_P1_before, & mepcop1_48_mep_model::model_cpmovi_w_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDMOVIU_P0_P1, & mepcop1_48_mep_model::model_cdmoviu_P0_P1_before, & mepcop1_48_mep_model::model_cdmoviu_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_48_INSN_CDMOVI_P0_P1, & mepcop1_48_mep_model::model_cdmovi_P0_P1_before, & mepcop1_48_mep_model::model_cdmovi_P0_P1_after, { { mepcop1_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
};

