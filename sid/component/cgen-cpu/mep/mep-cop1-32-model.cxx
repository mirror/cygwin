/* Simulator model support for mepcop1_32.

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

mepcop1_32_mep_model::mepcop1_32_mep_model (mep_ext1_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
mepcop1_32_mep_model::model_cmov_crn_rm_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmov_crn_rm_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmov_rn_crm_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmov_rn_crm_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovc_ccrn_rm_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovc_ccrn_rm_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovc_rn_ccrm_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovc_rn_ccrm_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rn_ccrm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovh_crn_rm_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovh_crn_rm_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_crn_rm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovh_rn_crm_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cmovh_rn_crm_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rn_crm.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadd3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadd3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadd3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadd3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadd3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadd3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdadd3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdadd3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsub3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsub3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsub3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsub3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsub3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsub3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsub3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsub3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpand3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpand3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpor3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpor3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpnor3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpnor3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpxor3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpxor3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsel_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsel_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpfsftbi_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpfsftbi_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpfsftbs0_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpfsftbs0_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpfsftbs1_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpfsftbs1_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpacku_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpacku_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpacku_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpacku_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpacku_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpacku_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpackl_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpackl_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpackl_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpackl_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpackl_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpunpackl_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppacku_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppacku_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppack_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppack_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppack_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppack_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrl3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrl3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssrl3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssrl3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrl3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrl3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssrl3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssrl3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrl3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrl3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssrl3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssrl3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsrl3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsrl3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsra3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsra3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssra3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssra3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsra3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsra3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssra3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssra3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsra3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsra3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssra3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssra3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsra3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsra3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsll3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsll3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssll3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssll3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsll3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsll3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssll3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssll3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsll3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsll3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssll3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssll3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsll3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsll3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsla3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsla3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsla3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsla3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadd3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadd3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadd3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadd3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssub3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssub3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssub3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssub3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuaddu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuaddu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuadd3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuadd3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextladdu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextladdu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextladd3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextladd3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextusubu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextusubu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextusub3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextusub3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlsubu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlsubu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlsub3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlsub3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaveu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaveu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpave3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpave3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpave3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpave3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpave3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpave3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsru3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsru3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsr3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsr3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsr3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsr3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsr3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddsr3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabs3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabs3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabs3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabs3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmaxu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmaxu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmax3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmax3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmax3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmax3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmaxu3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmaxu3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmax3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmax3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpminu3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpminu3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmin3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmin3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmin3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmin3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpminu3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpminu3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmin3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmin3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovfrcsar0_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovfrcsar0_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovfrcsar1_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovfrcsar1_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovfrcc_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovfrcc_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovtocsar0_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovtocsar0_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovtocsar1_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovtocsar1_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovtocc_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovtocc_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmov_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmov_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsz_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsz_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsz_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsz_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsz_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsz_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpldz_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpldz_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpldz_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpldz_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpnorm_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpnorm_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpnorm_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpnorm_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphaddu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphaddu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphadd_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphadd_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphadd_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphadd_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphadd_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cphadd_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpccadd_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpccadd_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpbcast_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpbcast_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpbcast_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpbcast_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpbcast_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpbcast_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuu_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextuu_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextu_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextu_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextl_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextl_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlu_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextlu_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextl_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpextl_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastub_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastub_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastb_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastb_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastub_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastub_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastb_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastb_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastuh_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcastuh_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcasth_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcasth_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdcastuw_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdcastuw_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdcastw_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdcastw_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeqz_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeqz_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeq_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeq_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeq_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeq_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeq_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpeq_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpne_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpne_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpne_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpne_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpne_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpne_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgtu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgtu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgt_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgt_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgt_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgt_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgtu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgtu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgt_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgt_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgeu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgeu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpge_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpge_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpge_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpge_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgeu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpgeu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpge_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpcmpge_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpeq_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpeq_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpeq_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpeq_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpeq_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpeq_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpne_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpne_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpne_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpne_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpne_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpne_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgtu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgtu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgt_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgt_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgt_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgt_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgtu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgtu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgt_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgt_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgeu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgeu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpge_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpge_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpge_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpge_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgeu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpgeu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpge_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpacmpge_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpeq_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpeq_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpeq_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpeq_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpeq_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpeq_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpne_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpne_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpne_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpne_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpne_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpne_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgtu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgtu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgt_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgt_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgt_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgt_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgtu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgtu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgt_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgt_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgeu_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgeu_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpge_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpge_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpge_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpge_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgeu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpgeu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpge_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpocmpge_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrli3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrli3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrli3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrli3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrli3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrli3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsrli3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsrli3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrai3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrai3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrai3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrai3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrai3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrai3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsrai3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdsrai3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslli3_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslli3_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslli3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslli3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslli3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslli3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdslli3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdslli3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslai3_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslai3_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpsrli3_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslai3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslai3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpclipiu3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpclipiu3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpclipi3_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpclipi3_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdclipiu3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdclipiu3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdclipi3_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdclipi3_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovi_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovi_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmoviu_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmoviu_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovi_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovi_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmoviu_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmoviu_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovi_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovi_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdmoviu_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdmoviu_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdmovi_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cdmovi_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmovi_b_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadda1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadda1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadda1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpadda1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddaca1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddaca1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddaca1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddaca1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddacua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddacua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddacla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpaddacla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsuba1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsuba1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsuba1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsuba1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubaca1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubaca1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubaca1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubaca1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubacua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubacua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubacla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsubacla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsa1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsa1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsa1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsa1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpabsla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsada1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsada1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsada1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsada1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsadla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpseta1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpseta1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsetua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsetua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsetla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsetla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmova1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmova1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovuua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovuua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovula1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovula1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovlua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovlua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovlla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovlla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppacka1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppacka1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppacka1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppacka1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cppackla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovhua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovhua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovhla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmovhla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrla1_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrla1_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsraa1_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsraa1_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslla1_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpslla1_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpmoviu_h_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrlia1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsrlia1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsraia1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsraia1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsllia1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsllia1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cpfsftbi_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssqa1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssqa1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssqa1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssqa1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssda1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssda1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssda1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpssda1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmula1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmula1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmula1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmula1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulua1u_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulua1u_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulla1u_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulla1u_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmada1u_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmada1u_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmada1_b_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmada1_b_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadua1u_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadua1u_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadla1u_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadla1u_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmadla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbua1u_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbua1u_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbla1u_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbla1u_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmsbla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpmulslla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmadslla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslua1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslua1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslla1_h_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslla1_h_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslua1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslua1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslla1_w_C3_before (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcop1_32_mep_model::model_cpsmsbslla1_w_C3_after (mep_ext1_cpu *current_cpu, mepcop1_32_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cdsrli3_C3.f
  const mepcop1_32_scache* abuf = sem;
  const mepcop1_32_idesc* idesc = abuf->idesc;
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

const mepcop1_32_mep_model::insn_timing mepcop1_32_mep_model::timing[] = {
  { MEPCOP1_32_INSN_X_INVALID, 0, 0, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CMOV_CRN_RM, & mepcop1_32_mep_model::model_cmov_crn_rm_before, & mepcop1_32_mep_model::model_cmov_crn_rm_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CMOV_RN_CRM, & mepcop1_32_mep_model::model_cmov_rn_crm_before, & mepcop1_32_mep_model::model_cmov_rn_crm_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CMOVC_CCRN_RM, & mepcop1_32_mep_model::model_cmovc_ccrn_rm_before, & mepcop1_32_mep_model::model_cmovc_ccrn_rm_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CMOVC_RN_CCRM, & mepcop1_32_mep_model::model_cmovc_rn_ccrm_before, & mepcop1_32_mep_model::model_cmovc_rn_ccrm_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CMOVH_CRN_RM, & mepcop1_32_mep_model::model_cmovh_crn_rm_before, & mepcop1_32_mep_model::model_cmovh_crn_rm_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CMOVH_RN_CRM, & mepcop1_32_mep_model::model_cmovh_rn_crm_before, & mepcop1_32_mep_model::model_cmovh_rn_crm_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADD3_B_C3, & mepcop1_32_mep_model::model_cpadd3_b_C3_before, & mepcop1_32_mep_model::model_cpadd3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADD3_H_C3, & mepcop1_32_mep_model::model_cpadd3_h_C3_before, & mepcop1_32_mep_model::model_cpadd3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADD3_W_C3, & mepcop1_32_mep_model::model_cpadd3_w_C3_before, & mepcop1_32_mep_model::model_cpadd3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDADD3_C3, & mepcop1_32_mep_model::model_cdadd3_C3_before, & mepcop1_32_mep_model::model_cdadd3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUB3_B_C3, & mepcop1_32_mep_model::model_cpsub3_b_C3_before, & mepcop1_32_mep_model::model_cpsub3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUB3_H_C3, & mepcop1_32_mep_model::model_cpsub3_h_C3_before, & mepcop1_32_mep_model::model_cpsub3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUB3_W_C3, & mepcop1_32_mep_model::model_cpsub3_w_C3_before, & mepcop1_32_mep_model::model_cpsub3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSUB3_C3, & mepcop1_32_mep_model::model_cdsub3_C3_before, & mepcop1_32_mep_model::model_cdsub3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPAND3_C3, & mepcop1_32_mep_model::model_cpand3_C3_before, & mepcop1_32_mep_model::model_cpand3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOR3_C3, & mepcop1_32_mep_model::model_cpor3_C3_before, & mepcop1_32_mep_model::model_cpor3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPNOR3_C3, & mepcop1_32_mep_model::model_cpnor3_C3_before, & mepcop1_32_mep_model::model_cpnor3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPXOR3_C3, & mepcop1_32_mep_model::model_cpxor3_C3_before, & mepcop1_32_mep_model::model_cpxor3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSEL_C3, & mepcop1_32_mep_model::model_cpsel_C3_before, & mepcop1_32_mep_model::model_cpsel_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPFSFTBI_C3, & mepcop1_32_mep_model::model_cpfsftbi_C3_before, & mepcop1_32_mep_model::model_cpfsftbi_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPFSFTBS0_C3, & mepcop1_32_mep_model::model_cpfsftbs0_C3_before, & mepcop1_32_mep_model::model_cpfsftbs0_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPFSFTBS1_C3, & mepcop1_32_mep_model::model_cpfsftbs1_C3_before, & mepcop1_32_mep_model::model_cpfsftbs1_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPUNPACKU_B_C3, & mepcop1_32_mep_model::model_cpunpacku_b_C3_before, & mepcop1_32_mep_model::model_cpunpacku_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPUNPACKU_H_C3, & mepcop1_32_mep_model::model_cpunpacku_h_C3_before, & mepcop1_32_mep_model::model_cpunpacku_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPUNPACKU_W_C3, & mepcop1_32_mep_model::model_cpunpacku_w_C3_before, & mepcop1_32_mep_model::model_cpunpacku_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPUNPACKL_B_C3, & mepcop1_32_mep_model::model_cpunpackl_b_C3_before, & mepcop1_32_mep_model::model_cpunpackl_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPUNPACKL_H_C3, & mepcop1_32_mep_model::model_cpunpackl_h_C3_before, & mepcop1_32_mep_model::model_cpunpackl_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPUNPACKL_W_C3, & mepcop1_32_mep_model::model_cpunpackl_w_C3_before, & mepcop1_32_mep_model::model_cpunpackl_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKU_B_C3, & mepcop1_32_mep_model::model_cppacku_b_C3_before, & mepcop1_32_mep_model::model_cppacku_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACK_B_C3, & mepcop1_32_mep_model::model_cppack_b_C3_before, & mepcop1_32_mep_model::model_cppack_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACK_H_C3, & mepcop1_32_mep_model::model_cppack_h_C3_before, & mepcop1_32_mep_model::model_cppack_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRL3_B_C3, & mepcop1_32_mep_model::model_cpsrl3_b_C3_before, & mepcop1_32_mep_model::model_cpsrl3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSRL3_B_C3, & mepcop1_32_mep_model::model_cpssrl3_b_C3_before, & mepcop1_32_mep_model::model_cpssrl3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRL3_H_C3, & mepcop1_32_mep_model::model_cpsrl3_h_C3_before, & mepcop1_32_mep_model::model_cpsrl3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSRL3_H_C3, & mepcop1_32_mep_model::model_cpssrl3_h_C3_before, & mepcop1_32_mep_model::model_cpssrl3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRL3_W_C3, & mepcop1_32_mep_model::model_cpsrl3_w_C3_before, & mepcop1_32_mep_model::model_cpsrl3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSRL3_W_C3, & mepcop1_32_mep_model::model_cpssrl3_w_C3_before, & mepcop1_32_mep_model::model_cpssrl3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSRL3_C3, & mepcop1_32_mep_model::model_cdsrl3_C3_before, & mepcop1_32_mep_model::model_cdsrl3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRA3_B_C3, & mepcop1_32_mep_model::model_cpsra3_b_C3_before, & mepcop1_32_mep_model::model_cpsra3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSRA3_B_C3, & mepcop1_32_mep_model::model_cpssra3_b_C3_before, & mepcop1_32_mep_model::model_cpssra3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRA3_H_C3, & mepcop1_32_mep_model::model_cpsra3_h_C3_before, & mepcop1_32_mep_model::model_cpsra3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSRA3_H_C3, & mepcop1_32_mep_model::model_cpssra3_h_C3_before, & mepcop1_32_mep_model::model_cpssra3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRA3_W_C3, & mepcop1_32_mep_model::model_cpsra3_w_C3_before, & mepcop1_32_mep_model::model_cpsra3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSRA3_W_C3, & mepcop1_32_mep_model::model_cpssra3_w_C3_before, & mepcop1_32_mep_model::model_cpssra3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSRA3_C3, & mepcop1_32_mep_model::model_cdsra3_C3_before, & mepcop1_32_mep_model::model_cdsra3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLL3_B_C3, & mepcop1_32_mep_model::model_cpsll3_b_C3_before, & mepcop1_32_mep_model::model_cpsll3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSLL3_B_C3, & mepcop1_32_mep_model::model_cpssll3_b_C3_before, & mepcop1_32_mep_model::model_cpssll3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLL3_H_C3, & mepcop1_32_mep_model::model_cpsll3_h_C3_before, & mepcop1_32_mep_model::model_cpsll3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSLL3_H_C3, & mepcop1_32_mep_model::model_cpssll3_h_C3_before, & mepcop1_32_mep_model::model_cpssll3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLL3_W_C3, & mepcop1_32_mep_model::model_cpsll3_w_C3_before, & mepcop1_32_mep_model::model_cpsll3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSLL3_W_C3, & mepcop1_32_mep_model::model_cpssll3_w_C3_before, & mepcop1_32_mep_model::model_cpssll3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSLL3_C3, & mepcop1_32_mep_model::model_cdsll3_C3_before, & mepcop1_32_mep_model::model_cdsll3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLA3_H_C3, & mepcop1_32_mep_model::model_cpsla3_h_C3_before, & mepcop1_32_mep_model::model_cpsla3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLA3_W_C3, & mepcop1_32_mep_model::model_cpsla3_w_C3_before, & mepcop1_32_mep_model::model_cpsla3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSADD3_H_C3, & mepcop1_32_mep_model::model_cpsadd3_h_C3_before, & mepcop1_32_mep_model::model_cpsadd3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSADD3_W_C3, & mepcop1_32_mep_model::model_cpsadd3_w_C3_before, & mepcop1_32_mep_model::model_cpsadd3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSUB3_H_C3, & mepcop1_32_mep_model::model_cpssub3_h_C3_before, & mepcop1_32_mep_model::model_cpssub3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSUB3_W_C3, & mepcop1_32_mep_model::model_cpssub3_w_C3_before, & mepcop1_32_mep_model::model_cpssub3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTUADDU3_B_C3, & mepcop1_32_mep_model::model_cpextuaddu3_b_C3_before, & mepcop1_32_mep_model::model_cpextuaddu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTUADD3_B_C3, & mepcop1_32_mep_model::model_cpextuadd3_b_C3_before, & mepcop1_32_mep_model::model_cpextuadd3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTLADDU3_B_C3, & mepcop1_32_mep_model::model_cpextladdu3_b_C3_before, & mepcop1_32_mep_model::model_cpextladdu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTLADD3_B_C3, & mepcop1_32_mep_model::model_cpextladd3_b_C3_before, & mepcop1_32_mep_model::model_cpextladd3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTUSUBU3_B_C3, & mepcop1_32_mep_model::model_cpextusubu3_b_C3_before, & mepcop1_32_mep_model::model_cpextusubu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTUSUB3_B_C3, & mepcop1_32_mep_model::model_cpextusub3_b_C3_before, & mepcop1_32_mep_model::model_cpextusub3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTLSUBU3_B_C3, & mepcop1_32_mep_model::model_cpextlsubu3_b_C3_before, & mepcop1_32_mep_model::model_cpextlsubu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTLSUB3_B_C3, & mepcop1_32_mep_model::model_cpextlsub3_b_C3_before, & mepcop1_32_mep_model::model_cpextlsub3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPAVEU3_B_C3, & mepcop1_32_mep_model::model_cpaveu3_b_C3_before, & mepcop1_32_mep_model::model_cpaveu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPAVE3_B_C3, & mepcop1_32_mep_model::model_cpave3_b_C3_before, & mepcop1_32_mep_model::model_cpave3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPAVE3_H_C3, & mepcop1_32_mep_model::model_cpave3_h_C3_before, & mepcop1_32_mep_model::model_cpave3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPAVE3_W_C3, & mepcop1_32_mep_model::model_cpave3_w_C3_before, & mepcop1_32_mep_model::model_cpave3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDSRU3_B_C3, & mepcop1_32_mep_model::model_cpaddsru3_b_C3_before, & mepcop1_32_mep_model::model_cpaddsru3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDSR3_B_C3, & mepcop1_32_mep_model::model_cpaddsr3_b_C3_before, & mepcop1_32_mep_model::model_cpaddsr3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDSR3_H_C3, & mepcop1_32_mep_model::model_cpaddsr3_h_C3_before, & mepcop1_32_mep_model::model_cpaddsr3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDSR3_W_C3, & mepcop1_32_mep_model::model_cpaddsr3_w_C3_before, & mepcop1_32_mep_model::model_cpaddsr3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSU3_B_C3, & mepcop1_32_mep_model::model_cpabsu3_b_C3_before, & mepcop1_32_mep_model::model_cpabsu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABS3_B_C3, & mepcop1_32_mep_model::model_cpabs3_b_C3_before, & mepcop1_32_mep_model::model_cpabs3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABS3_H_C3, & mepcop1_32_mep_model::model_cpabs3_h_C3_before, & mepcop1_32_mep_model::model_cpabs3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMAXU3_B_C3, & mepcop1_32_mep_model::model_cpmaxu3_b_C3_before, & mepcop1_32_mep_model::model_cpmaxu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMAX3_B_C3, & mepcop1_32_mep_model::model_cpmax3_b_C3_before, & mepcop1_32_mep_model::model_cpmax3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMAX3_H_C3, & mepcop1_32_mep_model::model_cpmax3_h_C3_before, & mepcop1_32_mep_model::model_cpmax3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMAXU3_W_C3, & mepcop1_32_mep_model::model_cpmaxu3_w_C3_before, & mepcop1_32_mep_model::model_cpmaxu3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMAX3_W_C3, & mepcop1_32_mep_model::model_cpmax3_w_C3_before, & mepcop1_32_mep_model::model_cpmax3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMINU3_B_C3, & mepcop1_32_mep_model::model_cpminu3_b_C3_before, & mepcop1_32_mep_model::model_cpminu3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMIN3_B_C3, & mepcop1_32_mep_model::model_cpmin3_b_C3_before, & mepcop1_32_mep_model::model_cpmin3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMIN3_H_C3, & mepcop1_32_mep_model::model_cpmin3_h_C3_before, & mepcop1_32_mep_model::model_cpmin3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMINU3_W_C3, & mepcop1_32_mep_model::model_cpminu3_w_C3_before, & mepcop1_32_mep_model::model_cpminu3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMIN3_W_C3, & mepcop1_32_mep_model::model_cpmin3_w_C3_before, & mepcop1_32_mep_model::model_cpmin3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVFRCSAR0_C3, & mepcop1_32_mep_model::model_cpmovfrcsar0_C3_before, & mepcop1_32_mep_model::model_cpmovfrcsar0_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVFRCSAR1_C3, & mepcop1_32_mep_model::model_cpmovfrcsar1_C3_before, & mepcop1_32_mep_model::model_cpmovfrcsar1_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVFRCC_C3, & mepcop1_32_mep_model::model_cpmovfrcc_C3_before, & mepcop1_32_mep_model::model_cpmovfrcc_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVTOCSAR0_C3, & mepcop1_32_mep_model::model_cpmovtocsar0_C3_before, & mepcop1_32_mep_model::model_cpmovtocsar0_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVTOCSAR1_C3, & mepcop1_32_mep_model::model_cpmovtocsar1_C3_before, & mepcop1_32_mep_model::model_cpmovtocsar1_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVTOCC_C3, & mepcop1_32_mep_model::model_cpmovtocc_C3_before, & mepcop1_32_mep_model::model_cpmovtocc_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOV_C3, & mepcop1_32_mep_model::model_cpmov_C3_before, & mepcop1_32_mep_model::model_cpmov_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSZ_B_C3, & mepcop1_32_mep_model::model_cpabsz_b_C3_before, & mepcop1_32_mep_model::model_cpabsz_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSZ_H_C3, & mepcop1_32_mep_model::model_cpabsz_h_C3_before, & mepcop1_32_mep_model::model_cpabsz_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSZ_W_C3, & mepcop1_32_mep_model::model_cpabsz_w_C3_before, & mepcop1_32_mep_model::model_cpabsz_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPLDZ_H_C3, & mepcop1_32_mep_model::model_cpldz_h_C3_before, & mepcop1_32_mep_model::model_cpldz_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPLDZ_W_C3, & mepcop1_32_mep_model::model_cpldz_w_C3_before, & mepcop1_32_mep_model::model_cpldz_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPNORM_H_C3, & mepcop1_32_mep_model::model_cpnorm_h_C3_before, & mepcop1_32_mep_model::model_cpnorm_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPNORM_W_C3, & mepcop1_32_mep_model::model_cpnorm_w_C3_before, & mepcop1_32_mep_model::model_cpnorm_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPHADDU_B_C3, & mepcop1_32_mep_model::model_cphaddu_b_C3_before, & mepcop1_32_mep_model::model_cphaddu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPHADD_B_C3, & mepcop1_32_mep_model::model_cphadd_b_C3_before, & mepcop1_32_mep_model::model_cphadd_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPHADD_H_C3, & mepcop1_32_mep_model::model_cphadd_h_C3_before, & mepcop1_32_mep_model::model_cphadd_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPHADD_W_C3, & mepcop1_32_mep_model::model_cphadd_w_C3_before, & mepcop1_32_mep_model::model_cphadd_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCCADD_B_C3, & mepcop1_32_mep_model::model_cpccadd_b_C3_before, & mepcop1_32_mep_model::model_cpccadd_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPBCAST_B_C3, & mepcop1_32_mep_model::model_cpbcast_b_C3_before, & mepcop1_32_mep_model::model_cpbcast_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPBCAST_H_C3, & mepcop1_32_mep_model::model_cpbcast_h_C3_before, & mepcop1_32_mep_model::model_cpbcast_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPBCAST_W_C3, & mepcop1_32_mep_model::model_cpbcast_w_C3_before, & mepcop1_32_mep_model::model_cpbcast_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTUU_B_C3, & mepcop1_32_mep_model::model_cpextuu_b_C3_before, & mepcop1_32_mep_model::model_cpextuu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTU_B_C3, & mepcop1_32_mep_model::model_cpextu_b_C3_before, & mepcop1_32_mep_model::model_cpextu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTUU_H_C3, & mepcop1_32_mep_model::model_cpextuu_h_C3_before, & mepcop1_32_mep_model::model_cpextuu_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTU_H_C3, & mepcop1_32_mep_model::model_cpextu_h_C3_before, & mepcop1_32_mep_model::model_cpextu_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTLU_B_C3, & mepcop1_32_mep_model::model_cpextlu_b_C3_before, & mepcop1_32_mep_model::model_cpextlu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTL_B_C3, & mepcop1_32_mep_model::model_cpextl_b_C3_before, & mepcop1_32_mep_model::model_cpextl_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTLU_H_C3, & mepcop1_32_mep_model::model_cpextlu_h_C3_before, & mepcop1_32_mep_model::model_cpextlu_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPEXTL_H_C3, & mepcop1_32_mep_model::model_cpextl_h_C3_before, & mepcop1_32_mep_model::model_cpextl_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCASTUB_H_C3, & mepcop1_32_mep_model::model_cpcastub_h_C3_before, & mepcop1_32_mep_model::model_cpcastub_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCASTB_H_C3, & mepcop1_32_mep_model::model_cpcastb_h_C3_before, & mepcop1_32_mep_model::model_cpcastb_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCASTUB_W_C3, & mepcop1_32_mep_model::model_cpcastub_w_C3_before, & mepcop1_32_mep_model::model_cpcastub_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCASTB_W_C3, & mepcop1_32_mep_model::model_cpcastb_w_C3_before, & mepcop1_32_mep_model::model_cpcastb_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCASTUH_W_C3, & mepcop1_32_mep_model::model_cpcastuh_w_C3_before, & mepcop1_32_mep_model::model_cpcastuh_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCASTH_W_C3, & mepcop1_32_mep_model::model_cpcasth_w_C3_before, & mepcop1_32_mep_model::model_cpcasth_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDCASTUW_C3, & mepcop1_32_mep_model::model_cdcastuw_C3_before, & mepcop1_32_mep_model::model_cdcastuw_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDCASTW_C3, & mepcop1_32_mep_model::model_cdcastw_C3_before, & mepcop1_32_mep_model::model_cdcastw_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPEQZ_B_C3, & mepcop1_32_mep_model::model_cpcmpeqz_b_C3_before, & mepcop1_32_mep_model::model_cpcmpeqz_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPEQ_B_C3, & mepcop1_32_mep_model::model_cpcmpeq_b_C3_before, & mepcop1_32_mep_model::model_cpcmpeq_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPEQ_H_C3, & mepcop1_32_mep_model::model_cpcmpeq_h_C3_before, & mepcop1_32_mep_model::model_cpcmpeq_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPEQ_W_C3, & mepcop1_32_mep_model::model_cpcmpeq_w_C3_before, & mepcop1_32_mep_model::model_cpcmpeq_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPNE_B_C3, & mepcop1_32_mep_model::model_cpcmpne_b_C3_before, & mepcop1_32_mep_model::model_cpcmpne_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPNE_H_C3, & mepcop1_32_mep_model::model_cpcmpne_h_C3_before, & mepcop1_32_mep_model::model_cpcmpne_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPNE_W_C3, & mepcop1_32_mep_model::model_cpcmpne_w_C3_before, & mepcop1_32_mep_model::model_cpcmpne_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGTU_B_C3, & mepcop1_32_mep_model::model_cpcmpgtu_b_C3_before, & mepcop1_32_mep_model::model_cpcmpgtu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGT_B_C3, & mepcop1_32_mep_model::model_cpcmpgt_b_C3_before, & mepcop1_32_mep_model::model_cpcmpgt_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGT_H_C3, & mepcop1_32_mep_model::model_cpcmpgt_h_C3_before, & mepcop1_32_mep_model::model_cpcmpgt_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGTU_W_C3, & mepcop1_32_mep_model::model_cpcmpgtu_w_C3_before, & mepcop1_32_mep_model::model_cpcmpgtu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGT_W_C3, & mepcop1_32_mep_model::model_cpcmpgt_w_C3_before, & mepcop1_32_mep_model::model_cpcmpgt_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGEU_B_C3, & mepcop1_32_mep_model::model_cpcmpgeu_b_C3_before, & mepcop1_32_mep_model::model_cpcmpgeu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGE_B_C3, & mepcop1_32_mep_model::model_cpcmpge_b_C3_before, & mepcop1_32_mep_model::model_cpcmpge_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGE_H_C3, & mepcop1_32_mep_model::model_cpcmpge_h_C3_before, & mepcop1_32_mep_model::model_cpcmpge_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGEU_W_C3, & mepcop1_32_mep_model::model_cpcmpgeu_w_C3_before, & mepcop1_32_mep_model::model_cpcmpgeu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCMPGE_W_C3, & mepcop1_32_mep_model::model_cpcmpge_w_C3_before, & mepcop1_32_mep_model::model_cpcmpge_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPEQ_B_C3, & mepcop1_32_mep_model::model_cpacmpeq_b_C3_before, & mepcop1_32_mep_model::model_cpacmpeq_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPEQ_H_C3, & mepcop1_32_mep_model::model_cpacmpeq_h_C3_before, & mepcop1_32_mep_model::model_cpacmpeq_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPEQ_W_C3, & mepcop1_32_mep_model::model_cpacmpeq_w_C3_before, & mepcop1_32_mep_model::model_cpacmpeq_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPNE_B_C3, & mepcop1_32_mep_model::model_cpacmpne_b_C3_before, & mepcop1_32_mep_model::model_cpacmpne_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPNE_H_C3, & mepcop1_32_mep_model::model_cpacmpne_h_C3_before, & mepcop1_32_mep_model::model_cpacmpne_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPNE_W_C3, & mepcop1_32_mep_model::model_cpacmpne_w_C3_before, & mepcop1_32_mep_model::model_cpacmpne_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGTU_B_C3, & mepcop1_32_mep_model::model_cpacmpgtu_b_C3_before, & mepcop1_32_mep_model::model_cpacmpgtu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGT_B_C3, & mepcop1_32_mep_model::model_cpacmpgt_b_C3_before, & mepcop1_32_mep_model::model_cpacmpgt_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGT_H_C3, & mepcop1_32_mep_model::model_cpacmpgt_h_C3_before, & mepcop1_32_mep_model::model_cpacmpgt_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGTU_W_C3, & mepcop1_32_mep_model::model_cpacmpgtu_w_C3_before, & mepcop1_32_mep_model::model_cpacmpgtu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGT_W_C3, & mepcop1_32_mep_model::model_cpacmpgt_w_C3_before, & mepcop1_32_mep_model::model_cpacmpgt_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGEU_B_C3, & mepcop1_32_mep_model::model_cpacmpgeu_b_C3_before, & mepcop1_32_mep_model::model_cpacmpgeu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGE_B_C3, & mepcop1_32_mep_model::model_cpacmpge_b_C3_before, & mepcop1_32_mep_model::model_cpacmpge_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGE_H_C3, & mepcop1_32_mep_model::model_cpacmpge_h_C3_before, & mepcop1_32_mep_model::model_cpacmpge_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGEU_W_C3, & mepcop1_32_mep_model::model_cpacmpgeu_w_C3_before, & mepcop1_32_mep_model::model_cpacmpgeu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPACMPGE_W_C3, & mepcop1_32_mep_model::model_cpacmpge_w_C3_before, & mepcop1_32_mep_model::model_cpacmpge_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPEQ_B_C3, & mepcop1_32_mep_model::model_cpocmpeq_b_C3_before, & mepcop1_32_mep_model::model_cpocmpeq_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPEQ_H_C3, & mepcop1_32_mep_model::model_cpocmpeq_h_C3_before, & mepcop1_32_mep_model::model_cpocmpeq_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPEQ_W_C3, & mepcop1_32_mep_model::model_cpocmpeq_w_C3_before, & mepcop1_32_mep_model::model_cpocmpeq_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPNE_B_C3, & mepcop1_32_mep_model::model_cpocmpne_b_C3_before, & mepcop1_32_mep_model::model_cpocmpne_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPNE_H_C3, & mepcop1_32_mep_model::model_cpocmpne_h_C3_before, & mepcop1_32_mep_model::model_cpocmpne_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPNE_W_C3, & mepcop1_32_mep_model::model_cpocmpne_w_C3_before, & mepcop1_32_mep_model::model_cpocmpne_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGTU_B_C3, & mepcop1_32_mep_model::model_cpocmpgtu_b_C3_before, & mepcop1_32_mep_model::model_cpocmpgtu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGT_B_C3, & mepcop1_32_mep_model::model_cpocmpgt_b_C3_before, & mepcop1_32_mep_model::model_cpocmpgt_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGT_H_C3, & mepcop1_32_mep_model::model_cpocmpgt_h_C3_before, & mepcop1_32_mep_model::model_cpocmpgt_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGTU_W_C3, & mepcop1_32_mep_model::model_cpocmpgtu_w_C3_before, & mepcop1_32_mep_model::model_cpocmpgtu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGT_W_C3, & mepcop1_32_mep_model::model_cpocmpgt_w_C3_before, & mepcop1_32_mep_model::model_cpocmpgt_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGEU_B_C3, & mepcop1_32_mep_model::model_cpocmpgeu_b_C3_before, & mepcop1_32_mep_model::model_cpocmpgeu_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGE_B_C3, & mepcop1_32_mep_model::model_cpocmpge_b_C3_before, & mepcop1_32_mep_model::model_cpocmpge_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGE_H_C3, & mepcop1_32_mep_model::model_cpocmpge_h_C3_before, & mepcop1_32_mep_model::model_cpocmpge_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGEU_W_C3, & mepcop1_32_mep_model::model_cpocmpgeu_w_C3_before, & mepcop1_32_mep_model::model_cpocmpgeu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPOCMPGE_W_C3, & mepcop1_32_mep_model::model_cpocmpge_w_C3_before, & mepcop1_32_mep_model::model_cpocmpge_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRLI3_B_C3, & mepcop1_32_mep_model::model_cpsrli3_b_C3_before, & mepcop1_32_mep_model::model_cpsrli3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRLI3_H_C3, & mepcop1_32_mep_model::model_cpsrli3_h_C3_before, & mepcop1_32_mep_model::model_cpsrli3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRLI3_W_C3, & mepcop1_32_mep_model::model_cpsrli3_w_C3_before, & mepcop1_32_mep_model::model_cpsrli3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSRLI3_C3, & mepcop1_32_mep_model::model_cdsrli3_C3_before, & mepcop1_32_mep_model::model_cdsrli3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRAI3_B_C3, & mepcop1_32_mep_model::model_cpsrai3_b_C3_before, & mepcop1_32_mep_model::model_cpsrai3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRAI3_H_C3, & mepcop1_32_mep_model::model_cpsrai3_h_C3_before, & mepcop1_32_mep_model::model_cpsrai3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRAI3_W_C3, & mepcop1_32_mep_model::model_cpsrai3_w_C3_before, & mepcop1_32_mep_model::model_cpsrai3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSRAI3_C3, & mepcop1_32_mep_model::model_cdsrai3_C3_before, & mepcop1_32_mep_model::model_cdsrai3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLLI3_B_C3, & mepcop1_32_mep_model::model_cpslli3_b_C3_before, & mepcop1_32_mep_model::model_cpslli3_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLLI3_H_C3, & mepcop1_32_mep_model::model_cpslli3_h_C3_before, & mepcop1_32_mep_model::model_cpslli3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLLI3_W_C3, & mepcop1_32_mep_model::model_cpslli3_w_C3_before, & mepcop1_32_mep_model::model_cpslli3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDSLLI3_C3, & mepcop1_32_mep_model::model_cdslli3_C3_before, & mepcop1_32_mep_model::model_cdslli3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLAI3_H_C3, & mepcop1_32_mep_model::model_cpslai3_h_C3_before, & mepcop1_32_mep_model::model_cpslai3_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLAI3_W_C3, & mepcop1_32_mep_model::model_cpslai3_w_C3_before, & mepcop1_32_mep_model::model_cpslai3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCLIPIU3_W_C3, & mepcop1_32_mep_model::model_cpclipiu3_w_C3_before, & mepcop1_32_mep_model::model_cpclipiu3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPCLIPI3_W_C3, & mepcop1_32_mep_model::model_cpclipi3_w_C3_before, & mepcop1_32_mep_model::model_cpclipi3_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDCLIPIU3_C3, & mepcop1_32_mep_model::model_cdclipiu3_C3_before, & mepcop1_32_mep_model::model_cdclipiu3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDCLIPI3_C3, & mepcop1_32_mep_model::model_cdclipi3_C3_before, & mepcop1_32_mep_model::model_cdclipi3_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVI_B_C3, & mepcop1_32_mep_model::model_cpmovi_b_C3_before, & mepcop1_32_mep_model::model_cpmovi_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVIU_H_C3, & mepcop1_32_mep_model::model_cpmoviu_h_C3_before, & mepcop1_32_mep_model::model_cpmoviu_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVI_H_C3, & mepcop1_32_mep_model::model_cpmovi_h_C3_before, & mepcop1_32_mep_model::model_cpmovi_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVIU_W_C3, & mepcop1_32_mep_model::model_cpmoviu_w_C3_before, & mepcop1_32_mep_model::model_cpmoviu_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVI_W_C3, & mepcop1_32_mep_model::model_cpmovi_w_C3_before, & mepcop1_32_mep_model::model_cpmovi_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDMOVIU_C3, & mepcop1_32_mep_model::model_cdmoviu_C3_before, & mepcop1_32_mep_model::model_cdmoviu_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CDMOVI_C3, & mepcop1_32_mep_model::model_cdmovi_C3_before, & mepcop1_32_mep_model::model_cdmovi_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDA1U_B_C3, & mepcop1_32_mep_model::model_cpadda1u_b_C3_before, & mepcop1_32_mep_model::model_cpadda1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDA1_B_C3, & mepcop1_32_mep_model::model_cpadda1_b_C3_before, & mepcop1_32_mep_model::model_cpadda1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDUA1_H_C3, & mepcop1_32_mep_model::model_cpaddua1_h_C3_before, & mepcop1_32_mep_model::model_cpaddua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDLA1_H_C3, & mepcop1_32_mep_model::model_cpaddla1_h_C3_before, & mepcop1_32_mep_model::model_cpaddla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDACA1U_B_C3, & mepcop1_32_mep_model::model_cpaddaca1u_b_C3_before, & mepcop1_32_mep_model::model_cpaddaca1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDACA1_B_C3, & mepcop1_32_mep_model::model_cpaddaca1_b_C3_before, & mepcop1_32_mep_model::model_cpaddaca1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDACUA1_H_C3, & mepcop1_32_mep_model::model_cpaddacua1_h_C3_before, & mepcop1_32_mep_model::model_cpaddacua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPADDACLA1_H_C3, & mepcop1_32_mep_model::model_cpaddacla1_h_C3_before, & mepcop1_32_mep_model::model_cpaddacla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBA1U_B_C3, & mepcop1_32_mep_model::model_cpsuba1u_b_C3_before, & mepcop1_32_mep_model::model_cpsuba1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBA1_B_C3, & mepcop1_32_mep_model::model_cpsuba1_b_C3_before, & mepcop1_32_mep_model::model_cpsuba1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBUA1_H_C3, & mepcop1_32_mep_model::model_cpsubua1_h_C3_before, & mepcop1_32_mep_model::model_cpsubua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBLA1_H_C3, & mepcop1_32_mep_model::model_cpsubla1_h_C3_before, & mepcop1_32_mep_model::model_cpsubla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBACA1U_B_C3, & mepcop1_32_mep_model::model_cpsubaca1u_b_C3_before, & mepcop1_32_mep_model::model_cpsubaca1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBACA1_B_C3, & mepcop1_32_mep_model::model_cpsubaca1_b_C3_before, & mepcop1_32_mep_model::model_cpsubaca1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBACUA1_H_C3, & mepcop1_32_mep_model::model_cpsubacua1_h_C3_before, & mepcop1_32_mep_model::model_cpsubacua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSUBACLA1_H_C3, & mepcop1_32_mep_model::model_cpsubacla1_h_C3_before, & mepcop1_32_mep_model::model_cpsubacla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSA1U_B_C3, & mepcop1_32_mep_model::model_cpabsa1u_b_C3_before, & mepcop1_32_mep_model::model_cpabsa1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSA1_B_C3, & mepcop1_32_mep_model::model_cpabsa1_b_C3_before, & mepcop1_32_mep_model::model_cpabsa1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSUA1_H_C3, & mepcop1_32_mep_model::model_cpabsua1_h_C3_before, & mepcop1_32_mep_model::model_cpabsua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPABSLA1_H_C3, & mepcop1_32_mep_model::model_cpabsla1_h_C3_before, & mepcop1_32_mep_model::model_cpabsla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSADA1U_B_C3, & mepcop1_32_mep_model::model_cpsada1u_b_C3_before, & mepcop1_32_mep_model::model_cpsada1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSADA1_B_C3, & mepcop1_32_mep_model::model_cpsada1_b_C3_before, & mepcop1_32_mep_model::model_cpsada1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSADUA1_H_C3, & mepcop1_32_mep_model::model_cpsadua1_h_C3_before, & mepcop1_32_mep_model::model_cpsadua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSADLA1_H_C3, & mepcop1_32_mep_model::model_cpsadla1_h_C3_before, & mepcop1_32_mep_model::model_cpsadla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSETA1_H_C3, & mepcop1_32_mep_model::model_cpseta1_h_C3_before, & mepcop1_32_mep_model::model_cpseta1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSETUA1_W_C3, & mepcop1_32_mep_model::model_cpsetua1_w_C3_before, & mepcop1_32_mep_model::model_cpsetua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSETLA1_W_C3, & mepcop1_32_mep_model::model_cpsetla1_w_C3_before, & mepcop1_32_mep_model::model_cpsetla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVA1_B_C3, & mepcop1_32_mep_model::model_cpmova1_b_C3_before, & mepcop1_32_mep_model::model_cpmova1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVUA1_H_C3, & mepcop1_32_mep_model::model_cpmovua1_h_C3_before, & mepcop1_32_mep_model::model_cpmovua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVLA1_H_C3, & mepcop1_32_mep_model::model_cpmovla1_h_C3_before, & mepcop1_32_mep_model::model_cpmovla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVUUA1_W_C3, & mepcop1_32_mep_model::model_cpmovuua1_w_C3_before, & mepcop1_32_mep_model::model_cpmovuua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVULA1_W_C3, & mepcop1_32_mep_model::model_cpmovula1_w_C3_before, & mepcop1_32_mep_model::model_cpmovula1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVLUA1_W_C3, & mepcop1_32_mep_model::model_cpmovlua1_w_C3_before, & mepcop1_32_mep_model::model_cpmovlua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVLLA1_W_C3, & mepcop1_32_mep_model::model_cpmovlla1_w_C3_before, & mepcop1_32_mep_model::model_cpmovlla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKA1U_B_C3, & mepcop1_32_mep_model::model_cppacka1u_b_C3_before, & mepcop1_32_mep_model::model_cppacka1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKA1_B_C3, & mepcop1_32_mep_model::model_cppacka1_b_C3_before, & mepcop1_32_mep_model::model_cppacka1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKUA1_H_C3, & mepcop1_32_mep_model::model_cppackua1_h_C3_before, & mepcop1_32_mep_model::model_cppackua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKLA1_H_C3, & mepcop1_32_mep_model::model_cppackla1_h_C3_before, & mepcop1_32_mep_model::model_cppackla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKUA1_W_C3, & mepcop1_32_mep_model::model_cppackua1_w_C3_before, & mepcop1_32_mep_model::model_cppackua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPPACKLA1_W_C3, & mepcop1_32_mep_model::model_cppackla1_w_C3_before, & mepcop1_32_mep_model::model_cppackla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVHUA1_W_C3, & mepcop1_32_mep_model::model_cpmovhua1_w_C3_before, & mepcop1_32_mep_model::model_cpmovhua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMOVHLA1_W_C3, & mepcop1_32_mep_model::model_cpmovhla1_w_C3_before, & mepcop1_32_mep_model::model_cpmovhla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRLA1_C3, & mepcop1_32_mep_model::model_cpsrla1_C3_before, & mepcop1_32_mep_model::model_cpsrla1_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRAA1_C3, & mepcop1_32_mep_model::model_cpsraa1_C3_before, & mepcop1_32_mep_model::model_cpsraa1_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLLA1_C3, & mepcop1_32_mep_model::model_cpslla1_C3_before, & mepcop1_32_mep_model::model_cpslla1_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRLIA1_P1, & mepcop1_32_mep_model::model_cpsrlia1_P1_before, & mepcop1_32_mep_model::model_cpsrlia1_P1_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSRAIA1_P1, & mepcop1_32_mep_model::model_cpsraia1_P1_before, & mepcop1_32_mep_model::model_cpsraia1_P1_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSLLIA1_P1, & mepcop1_32_mep_model::model_cpsllia1_P1_before, & mepcop1_32_mep_model::model_cpsllia1_P1_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSQA1U_B_C3, & mepcop1_32_mep_model::model_cpssqa1u_b_C3_before, & mepcop1_32_mep_model::model_cpssqa1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSQA1_B_C3, & mepcop1_32_mep_model::model_cpssqa1_b_C3_before, & mepcop1_32_mep_model::model_cpssqa1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSDA1U_B_C3, & mepcop1_32_mep_model::model_cpssda1u_b_C3_before, & mepcop1_32_mep_model::model_cpssda1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSSDA1_B_C3, & mepcop1_32_mep_model::model_cpssda1_b_C3_before, & mepcop1_32_mep_model::model_cpssda1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULA1U_B_C3, & mepcop1_32_mep_model::model_cpmula1u_b_C3_before, & mepcop1_32_mep_model::model_cpmula1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULA1_B_C3, & mepcop1_32_mep_model::model_cpmula1_b_C3_before, & mepcop1_32_mep_model::model_cpmula1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULUA1_H_C3, & mepcop1_32_mep_model::model_cpmulua1_h_C3_before, & mepcop1_32_mep_model::model_cpmulua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULLA1_H_C3, & mepcop1_32_mep_model::model_cpmulla1_h_C3_before, & mepcop1_32_mep_model::model_cpmulla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULUA1U_W_C3, & mepcop1_32_mep_model::model_cpmulua1u_w_C3_before, & mepcop1_32_mep_model::model_cpmulua1u_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULLA1U_W_C3, & mepcop1_32_mep_model::model_cpmulla1u_w_C3_before, & mepcop1_32_mep_model::model_cpmulla1u_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULUA1_W_C3, & mepcop1_32_mep_model::model_cpmulua1_w_C3_before, & mepcop1_32_mep_model::model_cpmulua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULLA1_W_C3, & mepcop1_32_mep_model::model_cpmulla1_w_C3_before, & mepcop1_32_mep_model::model_cpmulla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADA1U_B_C3, & mepcop1_32_mep_model::model_cpmada1u_b_C3_before, & mepcop1_32_mep_model::model_cpmada1u_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADA1_B_C3, & mepcop1_32_mep_model::model_cpmada1_b_C3_before, & mepcop1_32_mep_model::model_cpmada1_b_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADUA1_H_C3, & mepcop1_32_mep_model::model_cpmadua1_h_C3_before, & mepcop1_32_mep_model::model_cpmadua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADLA1_H_C3, & mepcop1_32_mep_model::model_cpmadla1_h_C3_before, & mepcop1_32_mep_model::model_cpmadla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADUA1U_W_C3, & mepcop1_32_mep_model::model_cpmadua1u_w_C3_before, & mepcop1_32_mep_model::model_cpmadua1u_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADLA1U_W_C3, & mepcop1_32_mep_model::model_cpmadla1u_w_C3_before, & mepcop1_32_mep_model::model_cpmadla1u_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADUA1_W_C3, & mepcop1_32_mep_model::model_cpmadua1_w_C3_before, & mepcop1_32_mep_model::model_cpmadua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMADLA1_W_C3, & mepcop1_32_mep_model::model_cpmadla1_w_C3_before, & mepcop1_32_mep_model::model_cpmadla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMSBUA1_H_C3, & mepcop1_32_mep_model::model_cpmsbua1_h_C3_before, & mepcop1_32_mep_model::model_cpmsbua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMSBLA1_H_C3, & mepcop1_32_mep_model::model_cpmsbla1_h_C3_before, & mepcop1_32_mep_model::model_cpmsbla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMSBUA1U_W_C3, & mepcop1_32_mep_model::model_cpmsbua1u_w_C3_before, & mepcop1_32_mep_model::model_cpmsbua1u_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMSBLA1U_W_C3, & mepcop1_32_mep_model::model_cpmsbla1u_w_C3_before, & mepcop1_32_mep_model::model_cpmsbla1u_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMSBUA1_W_C3, & mepcop1_32_mep_model::model_cpmsbua1_w_C3_before, & mepcop1_32_mep_model::model_cpmsbua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMSBLA1_W_C3, & mepcop1_32_mep_model::model_cpmsbla1_w_C3_before, & mepcop1_32_mep_model::model_cpmsbla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADUA1_H_C3, & mepcop1_32_mep_model::model_cpsmadua1_h_C3_before, & mepcop1_32_mep_model::model_cpsmadua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADLA1_H_C3, & mepcop1_32_mep_model::model_cpsmadla1_h_C3_before, & mepcop1_32_mep_model::model_cpsmadla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADUA1_W_C3, & mepcop1_32_mep_model::model_cpsmadua1_w_C3_before, & mepcop1_32_mep_model::model_cpsmadua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADLA1_W_C3, & mepcop1_32_mep_model::model_cpsmadla1_w_C3_before, & mepcop1_32_mep_model::model_cpsmadla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBUA1_H_C3, & mepcop1_32_mep_model::model_cpsmsbua1_h_C3_before, & mepcop1_32_mep_model::model_cpsmsbua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBLA1_H_C3, & mepcop1_32_mep_model::model_cpsmsbla1_h_C3_before, & mepcop1_32_mep_model::model_cpsmsbla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBUA1_W_C3, & mepcop1_32_mep_model::model_cpsmsbua1_w_C3_before, & mepcop1_32_mep_model::model_cpsmsbua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBLA1_W_C3, & mepcop1_32_mep_model::model_cpsmsbla1_w_C3_before, & mepcop1_32_mep_model::model_cpsmsbla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULSLUA1_H_C3, & mepcop1_32_mep_model::model_cpmulslua1_h_C3_before, & mepcop1_32_mep_model::model_cpmulslua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULSLLA1_H_C3, & mepcop1_32_mep_model::model_cpmulslla1_h_C3_before, & mepcop1_32_mep_model::model_cpmulslla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULSLUA1_W_C3, & mepcop1_32_mep_model::model_cpmulslua1_w_C3_before, & mepcop1_32_mep_model::model_cpmulslua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPMULSLLA1_W_C3, & mepcop1_32_mep_model::model_cpmulslla1_w_C3_before, & mepcop1_32_mep_model::model_cpmulslla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADSLUA1_H_C3, & mepcop1_32_mep_model::model_cpsmadslua1_h_C3_before, & mepcop1_32_mep_model::model_cpsmadslua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADSLLA1_H_C3, & mepcop1_32_mep_model::model_cpsmadslla1_h_C3_before, & mepcop1_32_mep_model::model_cpsmadslla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADSLUA1_W_C3, & mepcop1_32_mep_model::model_cpsmadslua1_w_C3_before, & mepcop1_32_mep_model::model_cpsmadslua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMADSLLA1_W_C3, & mepcop1_32_mep_model::model_cpsmadslla1_w_C3_before, & mepcop1_32_mep_model::model_cpsmadslla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBSLUA1_H_C3, & mepcop1_32_mep_model::model_cpsmsbslua1_h_C3_before, & mepcop1_32_mep_model::model_cpsmsbslua1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBSLLA1_H_C3, & mepcop1_32_mep_model::model_cpsmsbslla1_h_C3_before, & mepcop1_32_mep_model::model_cpsmsbslla1_h_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBSLUA1_W_C3, & mepcop1_32_mep_model::model_cpsmsbslua1_w_C3_before, & mepcop1_32_mep_model::model_cpsmsbslua1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCOP1_32_INSN_CPSMSBSLLA1_W_C3, & mepcop1_32_mep_model::model_cpsmsbslla1_w_C3_before, & mepcop1_32_mep_model::model_cpsmsbslla1_w_C3_after, { { mepcop1_32_mep_model::UNIT_U_EXEC, 1, 1 } } },
};

