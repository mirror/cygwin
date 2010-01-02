/* Simulator model support for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_basic.h"

using namespace mep_basic; // FIXME: namespace organization still wip

/* The profiling data is recorded here, but is accessed via the profiling
   mechanism.  After all, this is information for profiling.  */

/* Model handlers for each insn.  */

mep_mep_model::mep_mep_model (mep_basic_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
mep_mep_model::model_stcb_r_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_stcb_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stcb_r_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_stcb_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldcb_r_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldcb_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_ldcb_gpr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldcb_r_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldcb_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_ldcb_gpr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_pref_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_pref_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_prefd_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_prefd_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_casb3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rl5);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rl5);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 1, out_loadreg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_casb3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rl5);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rl5);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_cash3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rl5);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rl5);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 1, out_loadreg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_cash3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rl5);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rl5);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_casw3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rl5);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rl5);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 1, out_loadreg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_casw3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rl5);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rl5);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbucpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhucpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_uci_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_uci_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_dsp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_dsp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sb_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rnc);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sb_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rnc);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sh_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rns);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sh_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rns);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lb_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnc);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lb_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnc);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lh_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rns);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lh_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rns);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnuc);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnuc);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnus);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnus);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw_sp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_sp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw_sp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_sp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw_sp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_sp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw_sp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_sp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sb_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn3c);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sb_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn3c);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sh_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn3s);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sh_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn3s);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn3l);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn3l);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lb_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3c);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lb_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3c);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lh_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3s);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lh_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3s);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3l);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3l);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbu_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3uc);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbu_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3uc);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhu_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3us);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhu_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_tp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn3us);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sb16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rnc);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sb16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rnc);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sh16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rns);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sh16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rns);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lb16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnc);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lb16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnc);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lh16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rns);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lh16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rns);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbu16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnuc);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbu16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnuc);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhu16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnus);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhu16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnus);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw24_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sw24_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rnl);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw24_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lw24_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rnl);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_extb_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_extb_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_exth_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_exth_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_extub_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_extub_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_extuh_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_extuh_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ssarb_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ssarb_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mov_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mov_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movi8_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movi8_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movi16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movi16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movu24_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movu24_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movu16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movu16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movh_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_movh_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add3i_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_sp);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add3i_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_sp);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_advck3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_advck3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sub_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sub_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbvck3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbvck3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_neg_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_neg_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slt3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slt3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sltu3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sltu3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slt3i_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slt3i_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sltu3i_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sltu3i_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sl1ad3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sl1ad3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sl2ad3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sl2ad3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add3x_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_add3x_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slt3x_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slt3x_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sltu3x_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sltu3x_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_or_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_or_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_and_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_and_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_xor_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_xor_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_nor_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_nor_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_or3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_or3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_and3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_and3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_xor3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_xor3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sra_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sra_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_srl_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_srl_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sll_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sll_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_srai_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_srai_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_srli_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_srli_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slli_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_slli_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sll3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sll3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_fsft_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_fsft_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bra_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_branch_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bra_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 3)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_beqz_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_beqz_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 4)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bnez_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bnez_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 4)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_beqi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_beqi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bnei_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bnei_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_blti_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_blti_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bgei_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bgei_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_beq_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_beq_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bne_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bne_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsr12_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsr12_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsr24_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsr24_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jmp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jmp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 4)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jmp24_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jmp24_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 4)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jsr_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jsr_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ret_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ret_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 4)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_repeat_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_repeat_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_erepeat_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_erepeat_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_lp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_storereg = -1;
    out_storereg = FLD (out_lp);
    cycles += model_u_store_ctrl_reg_before (current_cpu, idesc, 1, out_storereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_lp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_storereg = -1;
    out_storereg = FLD (out_lp);
    cycles += model_u_store_ctrl_reg_after (current_cpu, idesc, 1, referenced, out_storereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_hi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_storereg = -1;
    out_storereg = FLD (out_hi);
    cycles += model_u_store_ctrl_reg_before (current_cpu, idesc, 1, out_storereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_hi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_storereg = -1;
    out_storereg = FLD (out_hi);
    cycles += model_u_store_ctrl_reg_after (current_cpu, idesc, 1, referenced, out_storereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_lo_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_storereg = -1;
    out_storereg = FLD (out_lo);
    cycles += model_u_store_ctrl_reg_before (current_cpu, idesc, 1, out_storereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_lo_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_storereg = -1;
    out_storereg = FLD (out_lo);
    cycles += model_u_store_ctrl_reg_after (current_cpu, idesc, 1, referenced, out_storereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_storereg = -1;
    out_storereg = FLD (out_csrn);
    cycles += model_u_store_ctrl_reg_before (current_cpu, idesc, 1, out_storereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stc_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_storereg = -1;
    out_storereg = FLD (out_csrn);
    cycles += model_u_store_ctrl_reg_after (current_cpu, idesc, 1, referenced, out_storereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_lp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_lp);
    cycles += model_u_use_ctrl_reg_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_lp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_lp);
    cycles += model_u_use_ctrl_reg_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_hi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_hi);
    cycles += model_u_use_ctrl_reg_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_hi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_hi);
    cycles += model_u_use_ctrl_reg_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_lo_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_lo);
    cycles += model_u_use_ctrl_reg_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_lo_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_lo);
    cycles += model_u_use_ctrl_reg_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_csrn);
    cycles += model_u_use_ctrl_reg_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldc_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_csrn);
    cycles += model_u_use_ctrl_reg_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_di_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_di_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ei_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ei_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_reti_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_reti_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 4)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_halt_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_halt_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sleep_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sleep_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_break_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_break_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_syncm_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_syncm_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stcb_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_stcb_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_stcb_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_stcb_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldcb_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_ldcb_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_ldcb_gpr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldcb_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldcb_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_ldcb_gpr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsetm_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsetm_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bclrm_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bclrm_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bnotm_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bnotm_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_btstm_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_btstm_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_tas_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_tas_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_cache_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_cache_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mul_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mul_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mulu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mulu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mulr_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  {
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_before (current_cpu, idesc, 4, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mulr_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_after (current_cpu, idesc, 4, referenced, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mulru_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  {
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_before (current_cpu, idesc, 4, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_mulru_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_after (current_cpu, idesc, 4, referenced, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_madd_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_madd_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maddu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maddu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maddr_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  {
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_before (current_cpu, idesc, 4, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maddr_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_after (current_cpu, idesc, 4, referenced, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maddru_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  {
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_before (current_cpu, idesc, 4, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maddru_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_multiply_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_resultreg = -1;
    out_resultreg = FLD (out_rn);
    cycles += model_u_mul_gpr_after (current_cpu, idesc, 4, referenced, out_resultreg);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_div_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_divide_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_div_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_divide_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_divu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_divide_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_divu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_divide_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_dret_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_dret_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_dbreak_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_dbreak_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldz_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ldz_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_abs_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_abs_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ave_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ave_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_min_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_min_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_max_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_max_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_minu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_minu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maxu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_maxu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_clip_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_clip_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_clipu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_clipu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sadd_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sadd_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ssub_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ssub_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_saddu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_saddu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ssubu_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ssubu_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sbcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lbcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_shcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lhcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_swcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lwcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_smcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_lmcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rma);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpeq_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpeq_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpne_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpne_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpat_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpat_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpaf_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bcpaf_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_synccp_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_synccp_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jsrv_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_jsrv_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gpr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsrv_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_bsrv_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 5)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sim_syscall_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_sim_syscall_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_0_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_0_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_1_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_1_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_2_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_2_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_3_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_3_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_4_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_4_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_5_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_5_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_6_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_6_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_7_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_7_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_8_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_8_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_9_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_9_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_10_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_10_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_11_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_11_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_12_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_12_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_13_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_13_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_14_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_14_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_15_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_15_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_17_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_17_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_20_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_20_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_21_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_21_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_22_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_22_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_23_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_23_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_26_before (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
mep_mep_model::model_ri_26_after (mep_basic_cpu *current_cpu, mep_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mep_scache* abuf = sem;
  const mep_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

/* We assume UNIT_NONE == 0 because the tables don't always terminate
   entries with it.  */

/* Model timing data for `mep'.  */

const mep_mep_model::insn_timing mep_mep_model::timing[] = {
  { MEP_INSN_X_INVALID, 0, 0, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_STCB_R, & mep_mep_model::model_stcb_r_before, & mep_mep_model::model_stcb_r_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_STCB, 0, 0 } } },
  { MEP_INSN_LDCB_R, & mep_mep_model::model_ldcb_r_before, & mep_mep_model::model_ldcb_r_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_LDCB, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LDCB_GPR, 0, 0 } } },
  { MEP_INSN_PREF, & mep_mep_model::model_pref_before, & mep_mep_model::model_pref_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_PREFD, & mep_mep_model::model_prefd_before, & mep_mep_model::model_prefd_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_CASB3, & mep_mep_model::model_casb3_before, & mep_mep_model::model_casb3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_CASH3, & mep_mep_model::model_cash3_before, & mep_mep_model::model_cash3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_CASW3, & mep_mep_model::model_casw3_before, & mep_mep_model::model_casw3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SBCP, & mep_mep_model::model_sbcp_before, & mep_mep_model::model_sbcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBCP, & mep_mep_model::model_lbcp_before, & mep_mep_model::model_lbcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBUCP, & mep_mep_model::model_lbucp_before, & mep_mep_model::model_lbucp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SHCP, & mep_mep_model::model_shcp_before, & mep_mep_model::model_shcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHCP, & mep_mep_model::model_lhcp_before, & mep_mep_model::model_lhcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHUCP, & mep_mep_model::model_lhucp_before, & mep_mep_model::model_lhucp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBUCPA, & mep_mep_model::model_lbucpa_before, & mep_mep_model::model_lbucpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHUCPA, & mep_mep_model::model_lhucpa_before, & mep_mep_model::model_lhucpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBUCPM0, & mep_mep_model::model_lbucpm0_before, & mep_mep_model::model_lbucpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHUCPM0, & mep_mep_model::model_lhucpm0_before, & mep_mep_model::model_lhucpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBUCPM1, & mep_mep_model::model_lbucpm1_before, & mep_mep_model::model_lbucpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHUCPM1, & mep_mep_model::model_lhucpm1_before, & mep_mep_model::model_lhucpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_UCI, & mep_mep_model::model_uci_before, & mep_mep_model::model_uci_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_DSP, & mep_mep_model::model_dsp_before, & mep_mep_model::model_dsp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SB, & mep_mep_model::model_sb_before, & mep_mep_model::model_sb_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SH, & mep_mep_model::model_sh_before, & mep_mep_model::model_sh_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SW, & mep_mep_model::model_sw_before, & mep_mep_model::model_sw_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LB, & mep_mep_model::model_lb_before, & mep_mep_model::model_lb_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LH, & mep_mep_model::model_lh_before, & mep_mep_model::model_lh_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LW, & mep_mep_model::model_lw_before, & mep_mep_model::model_lw_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LBU, & mep_mep_model::model_lbu_before, & mep_mep_model::model_lbu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LHU, & mep_mep_model::model_lhu_before, & mep_mep_model::model_lhu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_SW_SP, & mep_mep_model::model_sw_sp_before, & mep_mep_model::model_sw_sp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LW_SP, & mep_mep_model::model_lw_sp_before, & mep_mep_model::model_lw_sp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_SB_TP, & mep_mep_model::model_sb_tp_before, & mep_mep_model::model_sb_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SH_TP, & mep_mep_model::model_sh_tp_before, & mep_mep_model::model_sh_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SW_TP, & mep_mep_model::model_sw_tp_before, & mep_mep_model::model_sw_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LB_TP, & mep_mep_model::model_lb_tp_before, & mep_mep_model::model_lb_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LH_TP, & mep_mep_model::model_lh_tp_before, & mep_mep_model::model_lh_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LW_TP, & mep_mep_model::model_lw_tp_before, & mep_mep_model::model_lw_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LBU_TP, & mep_mep_model::model_lbu_tp_before, & mep_mep_model::model_lbu_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LHU_TP, & mep_mep_model::model_lhu_tp_before, & mep_mep_model::model_lhu_tp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_SB16, & mep_mep_model::model_sb16_before, & mep_mep_model::model_sb16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SH16, & mep_mep_model::model_sh16_before, & mep_mep_model::model_sh16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SW16, & mep_mep_model::model_sw16_before, & mep_mep_model::model_sw16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LB16, & mep_mep_model::model_lb16_before, & mep_mep_model::model_lb16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LH16, & mep_mep_model::model_lh16_before, & mep_mep_model::model_lh16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LW16, & mep_mep_model::model_lw16_before, & mep_mep_model::model_lw16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LBU16, & mep_mep_model::model_lbu16_before, & mep_mep_model::model_lbu16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LHU16, & mep_mep_model::model_lhu16_before, & mep_mep_model::model_lhu16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_SW24, & mep_mep_model::model_sw24_before, & mep_mep_model::model_sw24_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LW24, & mep_mep_model::model_lw24_before, & mep_mep_model::model_lw24_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_EXTB, & mep_mep_model::model_extb_before, & mep_mep_model::model_extb_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_EXTH, & mep_mep_model::model_exth_before, & mep_mep_model::model_exth_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_EXTUB, & mep_mep_model::model_extub_before, & mep_mep_model::model_extub_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_EXTUH, & mep_mep_model::model_extuh_before, & mep_mep_model::model_extuh_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SSARB, & mep_mep_model::model_ssarb_before, & mep_mep_model::model_ssarb_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MOV, & mep_mep_model::model_mov_before, & mep_mep_model::model_mov_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MOVI8, & mep_mep_model::model_movi8_before, & mep_mep_model::model_movi8_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MOVI16, & mep_mep_model::model_movi16_before, & mep_mep_model::model_movi16_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MOVU24, & mep_mep_model::model_movu24_before, & mep_mep_model::model_movu24_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MOVU16, & mep_mep_model::model_movu16_before, & mep_mep_model::model_movu16_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MOVH, & mep_mep_model::model_movh_before, & mep_mep_model::model_movh_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_ADD3, & mep_mep_model::model_add3_before, & mep_mep_model::model_add3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_ADD, & mep_mep_model::model_add_before, & mep_mep_model::model_add_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_ADD3I, & mep_mep_model::model_add3i_before, & mep_mep_model::model_add3i_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_ADVCK3, & mep_mep_model::model_advck3_before, & mep_mep_model::model_advck3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SUB, & mep_mep_model::model_sub_before, & mep_mep_model::model_sub_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 } } },
  { MEP_INSN_SBVCK3, & mep_mep_model::model_sbvck3_before, & mep_mep_model::model_sbvck3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_NEG, & mep_mep_model::model_neg_before, & mep_mep_model::model_neg_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLT3, & mep_mep_model::model_slt3_before, & mep_mep_model::model_slt3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLTU3, & mep_mep_model::model_sltu3_before, & mep_mep_model::model_sltu3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLT3I, & mep_mep_model::model_slt3i_before, & mep_mep_model::model_slt3i_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLTU3I, & mep_mep_model::model_sltu3i_before, & mep_mep_model::model_sltu3i_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SL1AD3, & mep_mep_model::model_sl1ad3_before, & mep_mep_model::model_sl1ad3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SL2AD3, & mep_mep_model::model_sl2ad3_before, & mep_mep_model::model_sl2ad3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_ADD3X, & mep_mep_model::model_add3x_before, & mep_mep_model::model_add3x_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLT3X, & mep_mep_model::model_slt3x_before, & mep_mep_model::model_slt3x_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLTU3X, & mep_mep_model::model_sltu3x_before, & mep_mep_model::model_sltu3x_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_OR, & mep_mep_model::model_or_before, & mep_mep_model::model_or_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_AND, & mep_mep_model::model_and_before, & mep_mep_model::model_and_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_XOR, & mep_mep_model::model_xor_before, & mep_mep_model::model_xor_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_NOR, & mep_mep_model::model_nor_before, & mep_mep_model::model_nor_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_OR3, & mep_mep_model::model_or3_before, & mep_mep_model::model_or3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_AND3, & mep_mep_model::model_and3_before, & mep_mep_model::model_and3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_XOR3, & mep_mep_model::model_xor3_before, & mep_mep_model::model_xor3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SRA, & mep_mep_model::model_sra_before, & mep_mep_model::model_sra_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SRL, & mep_mep_model::model_srl_before, & mep_mep_model::model_srl_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLL, & mep_mep_model::model_sll_before, & mep_mep_model::model_sll_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SRAI, & mep_mep_model::model_srai_before, & mep_mep_model::model_srai_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SRLI, & mep_mep_model::model_srli_before, & mep_mep_model::model_srli_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLLI, & mep_mep_model::model_slli_before, & mep_mep_model::model_slli_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLL3, & mep_mep_model::model_sll3_before, & mep_mep_model::model_sll3_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_FSFT, & mep_mep_model::model_fsft_before, & mep_mep_model::model_fsft_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BRA, & mep_mep_model::model_bra_before, & mep_mep_model::model_bra_after, { { mep_mep_model::UNIT_U_BRANCH, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BEQZ, & mep_mep_model::model_beqz_before, & mep_mep_model::model_beqz_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BNEZ, & mep_mep_model::model_bnez_before, & mep_mep_model::model_bnez_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BEQI, & mep_mep_model::model_beqi_before, & mep_mep_model::model_beqi_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BNEI, & mep_mep_model::model_bnei_before, & mep_mep_model::model_bnei_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BLTI, & mep_mep_model::model_blti_before, & mep_mep_model::model_blti_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BGEI, & mep_mep_model::model_bgei_before, & mep_mep_model::model_bgei_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BEQ, & mep_mep_model::model_beq_before, & mep_mep_model::model_beq_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BNE, & mep_mep_model::model_bne_before, & mep_mep_model::model_bne_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BSR12, & mep_mep_model::model_bsr12_before, & mep_mep_model::model_bsr12_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BSR24, & mep_mep_model::model_bsr24_before, & mep_mep_model::model_bsr24_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_JMP, & mep_mep_model::model_jmp_before, & mep_mep_model::model_jmp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_JMP24, & mep_mep_model::model_jmp24_before, & mep_mep_model::model_jmp24_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_JSR, & mep_mep_model::model_jsr_before, & mep_mep_model::model_jsr_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RET, & mep_mep_model::model_ret_before, & mep_mep_model::model_ret_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_REPEAT, & mep_mep_model::model_repeat_before, & mep_mep_model::model_repeat_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_EREPEAT, & mep_mep_model::model_erepeat_before, & mep_mep_model::model_erepeat_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_STC_LP, & mep_mep_model::model_stc_lp_before, & mep_mep_model::model_stc_lp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_STC_HI, & mep_mep_model::model_stc_hi_before, & mep_mep_model::model_stc_hi_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_STC_LO, & mep_mep_model::model_stc_lo_before, & mep_mep_model::model_stc_lo_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_STC, & mep_mep_model::model_stc_before, & mep_mep_model::model_stc_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LDC_LP, & mep_mep_model::model_ldc_lp_before, & mep_mep_model::model_ldc_lp_after, { { mep_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LDC_HI, & mep_mep_model::model_ldc_hi_before, & mep_mep_model::model_ldc_hi_after, { { mep_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LDC_LO, & mep_mep_model::model_ldc_lo_before, & mep_mep_model::model_ldc_lo_after, { { mep_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_LDC, & mep_mep_model::model_ldc_before, & mep_mep_model::model_ldc_after, { { mep_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEP_INSN_DI, & mep_mep_model::model_di_before, & mep_mep_model::model_di_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_EI, & mep_mep_model::model_ei_before, & mep_mep_model::model_ei_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_RETI, & mep_mep_model::model_reti_before, & mep_mep_model::model_reti_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_HALT, & mep_mep_model::model_halt_before, & mep_mep_model::model_halt_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SLEEP, & mep_mep_model::model_sleep_before, & mep_mep_model::model_sleep_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWI, & mep_mep_model::model_swi_before, & mep_mep_model::model_swi_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BREAK, & mep_mep_model::model_break_before, & mep_mep_model::model_break_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_SYNCM, & mep_mep_model::model_syncm_before, & mep_mep_model::model_syncm_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_STCB, & mep_mep_model::model_stcb_before, & mep_mep_model::model_stcb_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_STCB, 0, 0 } } },
  { MEP_INSN_LDCB, & mep_mep_model::model_ldcb_before, & mep_mep_model::model_ldcb_after, { { mep_mep_model::UNIT_U_LDCB, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_LDCB_GPR, 0, 0 } } },
  { MEP_INSN_BSETM, & mep_mep_model::model_bsetm_before, & mep_mep_model::model_bsetm_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BCLRM, & mep_mep_model::model_bclrm_before, & mep_mep_model::model_bclrm_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BNOTM, & mep_mep_model::model_bnotm_before, & mep_mep_model::model_bnotm_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BTSTM, & mep_mep_model::model_btstm_before, & mep_mep_model::model_btstm_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_TAS, & mep_mep_model::model_tas_before, & mep_mep_model::model_tas_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_CACHE, & mep_mep_model::model_cache_before, & mep_mep_model::model_cache_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MUL, & mep_mep_model::model_mul_before, & mep_mep_model::model_mul_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEP_INSN_MULU, & mep_mep_model::model_mulu_before, & mep_mep_model::model_mulu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEP_INSN_MULR, & mep_mep_model::model_mulr_before, & mep_mep_model::model_mulr_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mep_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEP_INSN_MULRU, & mep_mep_model::model_mulru_before, & mep_mep_model::model_mulru_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mep_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEP_INSN_MADD, & mep_mep_model::model_madd_before, & mep_mep_model::model_madd_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEP_INSN_MADDU, & mep_mep_model::model_maddu_before, & mep_mep_model::model_maddu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEP_INSN_MADDR, & mep_mep_model::model_maddr_before, & mep_mep_model::model_maddr_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mep_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEP_INSN_MADDRU, & mep_mep_model::model_maddru_before, & mep_mep_model::model_maddru_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mep_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEP_INSN_DIV, & mep_mep_model::model_div_before, & mep_mep_model::model_div_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_DIVIDE, 0, 0 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_DIVU, & mep_mep_model::model_divu_before, & mep_mep_model::model_divu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_DIVIDE, 0, 0 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_DRET, & mep_mep_model::model_dret_before, & mep_mep_model::model_dret_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_DBREAK, & mep_mep_model::model_dbreak_before, & mep_mep_model::model_dbreak_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LDZ, & mep_mep_model::model_ldz_before, & mep_mep_model::model_ldz_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_ABS, & mep_mep_model::model_abs_before, & mep_mep_model::model_abs_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_AVE, & mep_mep_model::model_ave_before, & mep_mep_model::model_ave_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MIN, & mep_mep_model::model_min_before, & mep_mep_model::model_min_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MAX, & mep_mep_model::model_max_before, & mep_mep_model::model_max_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MINU, & mep_mep_model::model_minu_before, & mep_mep_model::model_minu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_MAXU, & mep_mep_model::model_maxu_before, & mep_mep_model::model_maxu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_CLIP, & mep_mep_model::model_clip_before, & mep_mep_model::model_clip_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_CLIPU, & mep_mep_model::model_clipu_before, & mep_mep_model::model_clipu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SADD, & mep_mep_model::model_sadd_before, & mep_mep_model::model_sadd_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SSUB, & mep_mep_model::model_ssub_before, & mep_mep_model::model_ssub_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SADDU, & mep_mep_model::model_saddu_before, & mep_mep_model::model_saddu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SSUBU, & mep_mep_model::model_ssubu_before, & mep_mep_model::model_ssubu_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWCP, & mep_mep_model::model_swcp_before, & mep_mep_model::model_swcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LWCP, & mep_mep_model::model_lwcp_before, & mep_mep_model::model_lwcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SMCP, & mep_mep_model::model_smcp_before, & mep_mep_model::model_smcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LMCP, & mep_mep_model::model_lmcp_before, & mep_mep_model::model_lmcp_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWCPI, & mep_mep_model::model_swcpi_before, & mep_mep_model::model_swcpi_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LWCPI, & mep_mep_model::model_lwcpi_before, & mep_mep_model::model_lwcpi_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SMCPI, & mep_mep_model::model_smcpi_before, & mep_mep_model::model_smcpi_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LMCPI, & mep_mep_model::model_lmcpi_before, & mep_mep_model::model_lmcpi_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWCP16, & mep_mep_model::model_swcp16_before, & mep_mep_model::model_swcp16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LWCP16, & mep_mep_model::model_lwcp16_before, & mep_mep_model::model_lwcp16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SMCP16, & mep_mep_model::model_smcp16_before, & mep_mep_model::model_smcp16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LMCP16, & mep_mep_model::model_lmcp16_before, & mep_mep_model::model_lmcp16_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SBCPA, & mep_mep_model::model_sbcpa_before, & mep_mep_model::model_sbcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBCPA, & mep_mep_model::model_lbcpa_before, & mep_mep_model::model_lbcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SHCPA, & mep_mep_model::model_shcpa_before, & mep_mep_model::model_shcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHCPA, & mep_mep_model::model_lhcpa_before, & mep_mep_model::model_lhcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWCPA, & mep_mep_model::model_swcpa_before, & mep_mep_model::model_swcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LWCPA, & mep_mep_model::model_lwcpa_before, & mep_mep_model::model_lwcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SMCPA, & mep_mep_model::model_smcpa_before, & mep_mep_model::model_smcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LMCPA, & mep_mep_model::model_lmcpa_before, & mep_mep_model::model_lmcpa_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SBCPM0, & mep_mep_model::model_sbcpm0_before, & mep_mep_model::model_sbcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBCPM0, & mep_mep_model::model_lbcpm0_before, & mep_mep_model::model_lbcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SHCPM0, & mep_mep_model::model_shcpm0_before, & mep_mep_model::model_shcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHCPM0, & mep_mep_model::model_lhcpm0_before, & mep_mep_model::model_lhcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWCPM0, & mep_mep_model::model_swcpm0_before, & mep_mep_model::model_swcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LWCPM0, & mep_mep_model::model_lwcpm0_before, & mep_mep_model::model_lwcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SMCPM0, & mep_mep_model::model_smcpm0_before, & mep_mep_model::model_smcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LMCPM0, & mep_mep_model::model_lmcpm0_before, & mep_mep_model::model_lmcpm0_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SBCPM1, & mep_mep_model::model_sbcpm1_before, & mep_mep_model::model_sbcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LBCPM1, & mep_mep_model::model_lbcpm1_before, & mep_mep_model::model_lbcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SHCPM1, & mep_mep_model::model_shcpm1_before, & mep_mep_model::model_shcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LHCPM1, & mep_mep_model::model_lhcpm1_before, & mep_mep_model::model_lhcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SWCPM1, & mep_mep_model::model_swcpm1_before, & mep_mep_model::model_swcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LWCPM1, & mep_mep_model::model_lwcpm1_before, & mep_mep_model::model_lwcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SMCPM1, & mep_mep_model::model_smcpm1_before, & mep_mep_model::model_smcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_LMCPM1, & mep_mep_model::model_lmcpm1_before, & mep_mep_model::model_lmcpm1_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BCPEQ, & mep_mep_model::model_bcpeq_before, & mep_mep_model::model_bcpeq_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BCPNE, & mep_mep_model::model_bcpne_before, & mep_mep_model::model_bcpne_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BCPAT, & mep_mep_model::model_bcpat_before, & mep_mep_model::model_bcpat_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_BCPAF, & mep_mep_model::model_bcpaf_before, & mep_mep_model::model_bcpaf_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_SYNCCP, & mep_mep_model::model_synccp_before, & mep_mep_model::model_synccp_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_JSRV, & mep_mep_model::model_jsrv_before, & mep_mep_model::model_jsrv_after, { { mep_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_BSRV, & mep_mep_model::model_bsrv_before, & mep_mep_model::model_bsrv_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_SIM_SYSCALL, & mep_mep_model::model_sim_syscall_before, & mep_mep_model::model_sim_syscall_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEP_INSN_RI_0, & mep_mep_model::model_ri_0_before, & mep_mep_model::model_ri_0_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_1, & mep_mep_model::model_ri_1_before, & mep_mep_model::model_ri_1_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_2, & mep_mep_model::model_ri_2_before, & mep_mep_model::model_ri_2_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_3, & mep_mep_model::model_ri_3_before, & mep_mep_model::model_ri_3_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_4, & mep_mep_model::model_ri_4_before, & mep_mep_model::model_ri_4_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_5, & mep_mep_model::model_ri_5_before, & mep_mep_model::model_ri_5_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_6, & mep_mep_model::model_ri_6_before, & mep_mep_model::model_ri_6_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_7, & mep_mep_model::model_ri_7_before, & mep_mep_model::model_ri_7_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_8, & mep_mep_model::model_ri_8_before, & mep_mep_model::model_ri_8_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_9, & mep_mep_model::model_ri_9_before, & mep_mep_model::model_ri_9_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_10, & mep_mep_model::model_ri_10_before, & mep_mep_model::model_ri_10_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_11, & mep_mep_model::model_ri_11_before, & mep_mep_model::model_ri_11_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_12, & mep_mep_model::model_ri_12_before, & mep_mep_model::model_ri_12_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_13, & mep_mep_model::model_ri_13_before, & mep_mep_model::model_ri_13_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_14, & mep_mep_model::model_ri_14_before, & mep_mep_model::model_ri_14_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_15, & mep_mep_model::model_ri_15_before, & mep_mep_model::model_ri_15_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_17, & mep_mep_model::model_ri_17_before, & mep_mep_model::model_ri_17_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_20, & mep_mep_model::model_ri_20_before, & mep_mep_model::model_ri_20_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_21, & mep_mep_model::model_ri_21_before, & mep_mep_model::model_ri_21_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_22, & mep_mep_model::model_ri_22_before, & mep_mep_model::model_ri_22_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_23, & mep_mep_model::model_ri_23_before, & mep_mep_model::model_ri_23_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEP_INSN_RI_26, & mep_mep_model::model_ri_26_before, & mep_mep_model::model_ri_26_after, { { mep_mep_model::UNIT_U_EXEC, 1, 1 }, { mep_mep_model::UNIT_U_BRANCH, 0, 0 } } },
};

