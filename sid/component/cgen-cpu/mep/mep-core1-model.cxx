/* Simulator model support for mepcore1.

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

mepcore1_mep_model::mepcore1_mep_model (mep_ext1_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
mepcore1_mep_model::model_stcb_r_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stcb_r_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldcb_r_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldcb_r_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_pref_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_pref_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_prefd_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_prefd_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_casb3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_casb3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_cash3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_cash3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_casw3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_casw3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbucpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhucpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_uci_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_uci_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_dsp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_dsp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sb_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sb_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sh_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sh_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lb_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lb_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lh_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lh_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw_sp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw_sp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw_sp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw_sp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sb_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sb_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sh_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sh_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lb_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lb_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lh_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lh_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbu_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbu_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhu_tp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhu_tp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sb16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sb16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sh16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sh16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lb16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lb16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lh16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lh16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbu16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbu16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhu16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhu16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw24_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sw24_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw24_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lw24_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_extb_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_extb_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_exth_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_exth_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_extub_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_extub_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_extuh_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_extuh_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ssarb_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ssarb_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mov_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mov_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_movi8_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movi8_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movi16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movi16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movu24_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movu24_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movu16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movu16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movh_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_movh_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_add3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add3i_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add3i_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_advck3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_advck3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sub_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sub_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbvck3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbvck3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_neg_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_neg_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slt3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slt3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sltu3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sltu3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slt3i_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slt3i_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sltu3i_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_sltu3i_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_sl1ad3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sl1ad3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sl2ad3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sl2ad3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add3x_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_add3x_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slt3x_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slt3x_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sltu3x_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sltu3x_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_or_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_or_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_and_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_and_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_xor_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_xor_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_nor_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_nor_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_or3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_or3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_and3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_and3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_xor3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_xor3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sra_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sra_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_srl_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_srl_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sll_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sll_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_srai_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_srai_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_srli_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_srli_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slli_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_slli_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sll3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sll3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_fsft_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_fsft_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bra_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bra_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_beqz_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_beqz_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bnez_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bnez_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_beqi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_beqi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bnei_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bnei_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_blti_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_blti_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bgei_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bgei_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_beq_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_beq_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bne_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bne_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsr12_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsr12_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsr24_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsr24_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jmp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jmp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jmp24_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jmp24_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jsr_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jsr_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ret_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ret_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_repeat_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_repeat_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_erepeat_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_erepeat_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_stc_lp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_lp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_hi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_hi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_lo_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_lo_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stc_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_lp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_lp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_hi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_hi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_lo_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_lo_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldc_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_di_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_di_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_ei_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_ei_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_reti_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_reti_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_halt_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_halt_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_sleep_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_sleep_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_swi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_swi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_break_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_break_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_syncm_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_syncm_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_stcb_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_stcb_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldcb_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldcb_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsetm_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsetm_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bclrm_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bclrm_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bnotm_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bnotm_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_btstm_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_btstm_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_tas_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_tas_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_cache_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_cache_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mul_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mul_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mulu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mulu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mulr_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mulr_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mulru_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_mulru_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_madd_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_madd_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maddu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maddu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maddr_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maddr_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maddru_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maddru_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_div_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_div_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_divu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_divu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_dret_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_dret_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_dbreak_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_dbreak_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_ldz_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ldz_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_abs_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_abs_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ave_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ave_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_min_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_min_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_max_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_max_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_minu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_minu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maxu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_maxu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_clip_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_clip_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_clipu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_clipu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sadd_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sadd_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ssub_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ssub_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_saddu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_saddu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ssubu_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ssubu_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpi_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpi_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcp16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcp16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcp16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcp16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcp16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcp16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcp16_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcp16_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpa_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpa_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpm0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpm0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sbcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lbcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_shcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lhcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_swcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lwcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_smcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpm1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_lmcpm1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bcpeq_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpeq_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpne_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpne_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpat_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpat_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpaf_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_bcpaf_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_synccp_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_synccp_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_jsrv_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_jsrv_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsrv_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_bsrv_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_sim_syscall_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_sim_syscall_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore1_mep_model::model_ri_0_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_0_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_1_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_1_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_2_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_2_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_3_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_3_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_4_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_4_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_5_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_5_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_6_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_6_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_7_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_7_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_8_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_8_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_9_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_9_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_10_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_10_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_11_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_11_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_12_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_12_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_13_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_13_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_14_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_14_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_15_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_15_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_17_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_17_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_20_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_20_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_21_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_21_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_22_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_22_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_23_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_23_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_26_before (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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
mepcore1_mep_model::model_ri_26_after (mep_ext1_cpu *current_cpu, mepcore1_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore1_scache* abuf = sem;
  const mepcore1_idesc* idesc = abuf->idesc;
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

const mepcore1_mep_model::insn_timing mepcore1_mep_model::timing[] = {
  { MEPCORE1_INSN_X_INVALID, 0, 0, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_STCB_R, & mepcore1_mep_model::model_stcb_r_before, & mepcore1_mep_model::model_stcb_r_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_STCB, 0, 0 } } },
  { MEPCORE1_INSN_LDCB_R, & mepcore1_mep_model::model_ldcb_r_before, & mepcore1_mep_model::model_ldcb_r_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_LDCB, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LDCB_GPR, 0, 0 } } },
  { MEPCORE1_INSN_PREF, & mepcore1_mep_model::model_pref_before, & mepcore1_mep_model::model_pref_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_PREFD, & mepcore1_mep_model::model_prefd_before, & mepcore1_mep_model::model_prefd_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_CASB3, & mepcore1_mep_model::model_casb3_before, & mepcore1_mep_model::model_casb3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_CASH3, & mepcore1_mep_model::model_cash3_before, & mepcore1_mep_model::model_cash3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_CASW3, & mepcore1_mep_model::model_casw3_before, & mepcore1_mep_model::model_casw3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SBCP, & mepcore1_mep_model::model_sbcp_before, & mepcore1_mep_model::model_sbcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBCP, & mepcore1_mep_model::model_lbcp_before, & mepcore1_mep_model::model_lbcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBUCP, & mepcore1_mep_model::model_lbucp_before, & mepcore1_mep_model::model_lbucp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SHCP, & mepcore1_mep_model::model_shcp_before, & mepcore1_mep_model::model_shcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHCP, & mepcore1_mep_model::model_lhcp_before, & mepcore1_mep_model::model_lhcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHUCP, & mepcore1_mep_model::model_lhucp_before, & mepcore1_mep_model::model_lhucp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBUCPA, & mepcore1_mep_model::model_lbucpa_before, & mepcore1_mep_model::model_lbucpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHUCPA, & mepcore1_mep_model::model_lhucpa_before, & mepcore1_mep_model::model_lhucpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBUCPM0, & mepcore1_mep_model::model_lbucpm0_before, & mepcore1_mep_model::model_lbucpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHUCPM0, & mepcore1_mep_model::model_lhucpm0_before, & mepcore1_mep_model::model_lhucpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBUCPM1, & mepcore1_mep_model::model_lbucpm1_before, & mepcore1_mep_model::model_lbucpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHUCPM1, & mepcore1_mep_model::model_lhucpm1_before, & mepcore1_mep_model::model_lhucpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_UCI, & mepcore1_mep_model::model_uci_before, & mepcore1_mep_model::model_uci_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_DSP, & mepcore1_mep_model::model_dsp_before, & mepcore1_mep_model::model_dsp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SB, & mepcore1_mep_model::model_sb_before, & mepcore1_mep_model::model_sb_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SH, & mepcore1_mep_model::model_sh_before, & mepcore1_mep_model::model_sh_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SW, & mepcore1_mep_model::model_sw_before, & mepcore1_mep_model::model_sw_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LB, & mepcore1_mep_model::model_lb_before, & mepcore1_mep_model::model_lb_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LH, & mepcore1_mep_model::model_lh_before, & mepcore1_mep_model::model_lh_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LW, & mepcore1_mep_model::model_lw_before, & mepcore1_mep_model::model_lw_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LBU, & mepcore1_mep_model::model_lbu_before, & mepcore1_mep_model::model_lbu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LHU, & mepcore1_mep_model::model_lhu_before, & mepcore1_mep_model::model_lhu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_SW_SP, & mepcore1_mep_model::model_sw_sp_before, & mepcore1_mep_model::model_sw_sp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LW_SP, & mepcore1_mep_model::model_lw_sp_before, & mepcore1_mep_model::model_lw_sp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_SB_TP, & mepcore1_mep_model::model_sb_tp_before, & mepcore1_mep_model::model_sb_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SH_TP, & mepcore1_mep_model::model_sh_tp_before, & mepcore1_mep_model::model_sh_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SW_TP, & mepcore1_mep_model::model_sw_tp_before, & mepcore1_mep_model::model_sw_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LB_TP, & mepcore1_mep_model::model_lb_tp_before, & mepcore1_mep_model::model_lb_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LH_TP, & mepcore1_mep_model::model_lh_tp_before, & mepcore1_mep_model::model_lh_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LW_TP, & mepcore1_mep_model::model_lw_tp_before, & mepcore1_mep_model::model_lw_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LBU_TP, & mepcore1_mep_model::model_lbu_tp_before, & mepcore1_mep_model::model_lbu_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LHU_TP, & mepcore1_mep_model::model_lhu_tp_before, & mepcore1_mep_model::model_lhu_tp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_SB16, & mepcore1_mep_model::model_sb16_before, & mepcore1_mep_model::model_sb16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SH16, & mepcore1_mep_model::model_sh16_before, & mepcore1_mep_model::model_sh16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SW16, & mepcore1_mep_model::model_sw16_before, & mepcore1_mep_model::model_sw16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LB16, & mepcore1_mep_model::model_lb16_before, & mepcore1_mep_model::model_lb16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LH16, & mepcore1_mep_model::model_lh16_before, & mepcore1_mep_model::model_lh16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LW16, & mepcore1_mep_model::model_lw16_before, & mepcore1_mep_model::model_lw16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LBU16, & mepcore1_mep_model::model_lbu16_before, & mepcore1_mep_model::model_lbu16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LHU16, & mepcore1_mep_model::model_lhu16_before, & mepcore1_mep_model::model_lhu16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_SW24, & mepcore1_mep_model::model_sw24_before, & mepcore1_mep_model::model_sw24_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LW24, & mepcore1_mep_model::model_lw24_before, & mepcore1_mep_model::model_lw24_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_EXTB, & mepcore1_mep_model::model_extb_before, & mepcore1_mep_model::model_extb_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_EXTH, & mepcore1_mep_model::model_exth_before, & mepcore1_mep_model::model_exth_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_EXTUB, & mepcore1_mep_model::model_extub_before, & mepcore1_mep_model::model_extub_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_EXTUH, & mepcore1_mep_model::model_extuh_before, & mepcore1_mep_model::model_extuh_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SSARB, & mepcore1_mep_model::model_ssarb_before, & mepcore1_mep_model::model_ssarb_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MOV, & mepcore1_mep_model::model_mov_before, & mepcore1_mep_model::model_mov_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MOVI8, & mepcore1_mep_model::model_movi8_before, & mepcore1_mep_model::model_movi8_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MOVI16, & mepcore1_mep_model::model_movi16_before, & mepcore1_mep_model::model_movi16_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MOVU24, & mepcore1_mep_model::model_movu24_before, & mepcore1_mep_model::model_movu24_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MOVU16, & mepcore1_mep_model::model_movu16_before, & mepcore1_mep_model::model_movu16_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MOVH, & mepcore1_mep_model::model_movh_before, & mepcore1_mep_model::model_movh_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_ADD3, & mepcore1_mep_model::model_add3_before, & mepcore1_mep_model::model_add3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_ADD, & mepcore1_mep_model::model_add_before, & mepcore1_mep_model::model_add_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_ADD3I, & mepcore1_mep_model::model_add3i_before, & mepcore1_mep_model::model_add3i_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_ADVCK3, & mepcore1_mep_model::model_advck3_before, & mepcore1_mep_model::model_advck3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SUB, & mepcore1_mep_model::model_sub_before, & mepcore1_mep_model::model_sub_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 } } },
  { MEPCORE1_INSN_SBVCK3, & mepcore1_mep_model::model_sbvck3_before, & mepcore1_mep_model::model_sbvck3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_NEG, & mepcore1_mep_model::model_neg_before, & mepcore1_mep_model::model_neg_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLT3, & mepcore1_mep_model::model_slt3_before, & mepcore1_mep_model::model_slt3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLTU3, & mepcore1_mep_model::model_sltu3_before, & mepcore1_mep_model::model_sltu3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLT3I, & mepcore1_mep_model::model_slt3i_before, & mepcore1_mep_model::model_slt3i_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLTU3I, & mepcore1_mep_model::model_sltu3i_before, & mepcore1_mep_model::model_sltu3i_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SL1AD3, & mepcore1_mep_model::model_sl1ad3_before, & mepcore1_mep_model::model_sl1ad3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SL2AD3, & mepcore1_mep_model::model_sl2ad3_before, & mepcore1_mep_model::model_sl2ad3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_ADD3X, & mepcore1_mep_model::model_add3x_before, & mepcore1_mep_model::model_add3x_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLT3X, & mepcore1_mep_model::model_slt3x_before, & mepcore1_mep_model::model_slt3x_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLTU3X, & mepcore1_mep_model::model_sltu3x_before, & mepcore1_mep_model::model_sltu3x_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_OR, & mepcore1_mep_model::model_or_before, & mepcore1_mep_model::model_or_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_AND, & mepcore1_mep_model::model_and_before, & mepcore1_mep_model::model_and_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_XOR, & mepcore1_mep_model::model_xor_before, & mepcore1_mep_model::model_xor_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_NOR, & mepcore1_mep_model::model_nor_before, & mepcore1_mep_model::model_nor_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_OR3, & mepcore1_mep_model::model_or3_before, & mepcore1_mep_model::model_or3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_AND3, & mepcore1_mep_model::model_and3_before, & mepcore1_mep_model::model_and3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_XOR3, & mepcore1_mep_model::model_xor3_before, & mepcore1_mep_model::model_xor3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SRA, & mepcore1_mep_model::model_sra_before, & mepcore1_mep_model::model_sra_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SRL, & mepcore1_mep_model::model_srl_before, & mepcore1_mep_model::model_srl_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLL, & mepcore1_mep_model::model_sll_before, & mepcore1_mep_model::model_sll_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SRAI, & mepcore1_mep_model::model_srai_before, & mepcore1_mep_model::model_srai_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SRLI, & mepcore1_mep_model::model_srli_before, & mepcore1_mep_model::model_srli_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLLI, & mepcore1_mep_model::model_slli_before, & mepcore1_mep_model::model_slli_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLL3, & mepcore1_mep_model::model_sll3_before, & mepcore1_mep_model::model_sll3_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_FSFT, & mepcore1_mep_model::model_fsft_before, & mepcore1_mep_model::model_fsft_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BRA, & mepcore1_mep_model::model_bra_before, & mepcore1_mep_model::model_bra_after, { { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BEQZ, & mepcore1_mep_model::model_beqz_before, & mepcore1_mep_model::model_beqz_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BNEZ, & mepcore1_mep_model::model_bnez_before, & mepcore1_mep_model::model_bnez_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BEQI, & mepcore1_mep_model::model_beqi_before, & mepcore1_mep_model::model_beqi_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BNEI, & mepcore1_mep_model::model_bnei_before, & mepcore1_mep_model::model_bnei_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BLTI, & mepcore1_mep_model::model_blti_before, & mepcore1_mep_model::model_blti_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BGEI, & mepcore1_mep_model::model_bgei_before, & mepcore1_mep_model::model_bgei_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BEQ, & mepcore1_mep_model::model_beq_before, & mepcore1_mep_model::model_beq_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BNE, & mepcore1_mep_model::model_bne_before, & mepcore1_mep_model::model_bne_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BSR12, & mepcore1_mep_model::model_bsr12_before, & mepcore1_mep_model::model_bsr12_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BSR24, & mepcore1_mep_model::model_bsr24_before, & mepcore1_mep_model::model_bsr24_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_JMP, & mepcore1_mep_model::model_jmp_before, & mepcore1_mep_model::model_jmp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_JMP24, & mepcore1_mep_model::model_jmp24_before, & mepcore1_mep_model::model_jmp24_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_JSR, & mepcore1_mep_model::model_jsr_before, & mepcore1_mep_model::model_jsr_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RET, & mepcore1_mep_model::model_ret_before, & mepcore1_mep_model::model_ret_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_REPEAT, & mepcore1_mep_model::model_repeat_before, & mepcore1_mep_model::model_repeat_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_EREPEAT, & mepcore1_mep_model::model_erepeat_before, & mepcore1_mep_model::model_erepeat_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_STC_LP, & mepcore1_mep_model::model_stc_lp_before, & mepcore1_mep_model::model_stc_lp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_STC_HI, & mepcore1_mep_model::model_stc_hi_before, & mepcore1_mep_model::model_stc_hi_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_STC_LO, & mepcore1_mep_model::model_stc_lo_before, & mepcore1_mep_model::model_stc_lo_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_STC, & mepcore1_mep_model::model_stc_before, & mepcore1_mep_model::model_stc_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LDC_LP, & mepcore1_mep_model::model_ldc_lp_before, & mepcore1_mep_model::model_ldc_lp_after, { { mepcore1_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LDC_HI, & mepcore1_mep_model::model_ldc_hi_before, & mepcore1_mep_model::model_ldc_hi_after, { { mepcore1_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LDC_LO, & mepcore1_mep_model::model_ldc_lo_before, & mepcore1_mep_model::model_ldc_lo_after, { { mepcore1_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_LDC, & mepcore1_mep_model::model_ldc_before, & mepcore1_mep_model::model_ldc_after, { { mepcore1_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE1_INSN_DI, & mepcore1_mep_model::model_di_before, & mepcore1_mep_model::model_di_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_EI, & mepcore1_mep_model::model_ei_before, & mepcore1_mep_model::model_ei_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_RETI, & mepcore1_mep_model::model_reti_before, & mepcore1_mep_model::model_reti_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_HALT, & mepcore1_mep_model::model_halt_before, & mepcore1_mep_model::model_halt_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SLEEP, & mepcore1_mep_model::model_sleep_before, & mepcore1_mep_model::model_sleep_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWI, & mepcore1_mep_model::model_swi_before, & mepcore1_mep_model::model_swi_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BREAK, & mepcore1_mep_model::model_break_before, & mepcore1_mep_model::model_break_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_SYNCM, & mepcore1_mep_model::model_syncm_before, & mepcore1_mep_model::model_syncm_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_STCB, & mepcore1_mep_model::model_stcb_before, & mepcore1_mep_model::model_stcb_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_STCB, 0, 0 } } },
  { MEPCORE1_INSN_LDCB, & mepcore1_mep_model::model_ldcb_before, & mepcore1_mep_model::model_ldcb_after, { { mepcore1_mep_model::UNIT_U_LDCB, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_LDCB_GPR, 0, 0 } } },
  { MEPCORE1_INSN_BSETM, & mepcore1_mep_model::model_bsetm_before, & mepcore1_mep_model::model_bsetm_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BCLRM, & mepcore1_mep_model::model_bclrm_before, & mepcore1_mep_model::model_bclrm_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BNOTM, & mepcore1_mep_model::model_bnotm_before, & mepcore1_mep_model::model_bnotm_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BTSTM, & mepcore1_mep_model::model_btstm_before, & mepcore1_mep_model::model_btstm_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_TAS, & mepcore1_mep_model::model_tas_before, & mepcore1_mep_model::model_tas_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_CACHE, & mepcore1_mep_model::model_cache_before, & mepcore1_mep_model::model_cache_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MUL, & mepcore1_mep_model::model_mul_before, & mepcore1_mep_model::model_mul_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE1_INSN_MULU, & mepcore1_mep_model::model_mulu_before, & mepcore1_mep_model::model_mulu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE1_INSN_MULR, & mepcore1_mep_model::model_mulr_before, & mepcore1_mep_model::model_mulr_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore1_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE1_INSN_MULRU, & mepcore1_mep_model::model_mulru_before, & mepcore1_mep_model::model_mulru_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore1_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE1_INSN_MADD, & mepcore1_mep_model::model_madd_before, & mepcore1_mep_model::model_madd_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE1_INSN_MADDU, & mepcore1_mep_model::model_maddu_before, & mepcore1_mep_model::model_maddu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE1_INSN_MADDR, & mepcore1_mep_model::model_maddr_before, & mepcore1_mep_model::model_maddr_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore1_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE1_INSN_MADDRU, & mepcore1_mep_model::model_maddru_before, & mepcore1_mep_model::model_maddru_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore1_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE1_INSN_DIV, & mepcore1_mep_model::model_div_before, & mepcore1_mep_model::model_div_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_DIVIDE, 0, 0 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_DIVU, & mepcore1_mep_model::model_divu_before, & mepcore1_mep_model::model_divu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_DIVIDE, 0, 0 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_DRET, & mepcore1_mep_model::model_dret_before, & mepcore1_mep_model::model_dret_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_DBREAK, & mepcore1_mep_model::model_dbreak_before, & mepcore1_mep_model::model_dbreak_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LDZ, & mepcore1_mep_model::model_ldz_before, & mepcore1_mep_model::model_ldz_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_ABS, & mepcore1_mep_model::model_abs_before, & mepcore1_mep_model::model_abs_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_AVE, & mepcore1_mep_model::model_ave_before, & mepcore1_mep_model::model_ave_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MIN, & mepcore1_mep_model::model_min_before, & mepcore1_mep_model::model_min_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MAX, & mepcore1_mep_model::model_max_before, & mepcore1_mep_model::model_max_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MINU, & mepcore1_mep_model::model_minu_before, & mepcore1_mep_model::model_minu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_MAXU, & mepcore1_mep_model::model_maxu_before, & mepcore1_mep_model::model_maxu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_CLIP, & mepcore1_mep_model::model_clip_before, & mepcore1_mep_model::model_clip_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_CLIPU, & mepcore1_mep_model::model_clipu_before, & mepcore1_mep_model::model_clipu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SADD, & mepcore1_mep_model::model_sadd_before, & mepcore1_mep_model::model_sadd_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SSUB, & mepcore1_mep_model::model_ssub_before, & mepcore1_mep_model::model_ssub_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SADDU, & mepcore1_mep_model::model_saddu_before, & mepcore1_mep_model::model_saddu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SSUBU, & mepcore1_mep_model::model_ssubu_before, & mepcore1_mep_model::model_ssubu_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWCP, & mepcore1_mep_model::model_swcp_before, & mepcore1_mep_model::model_swcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LWCP, & mepcore1_mep_model::model_lwcp_before, & mepcore1_mep_model::model_lwcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SMCP, & mepcore1_mep_model::model_smcp_before, & mepcore1_mep_model::model_smcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LMCP, & mepcore1_mep_model::model_lmcp_before, & mepcore1_mep_model::model_lmcp_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWCPI, & mepcore1_mep_model::model_swcpi_before, & mepcore1_mep_model::model_swcpi_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LWCPI, & mepcore1_mep_model::model_lwcpi_before, & mepcore1_mep_model::model_lwcpi_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SMCPI, & mepcore1_mep_model::model_smcpi_before, & mepcore1_mep_model::model_smcpi_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LMCPI, & mepcore1_mep_model::model_lmcpi_before, & mepcore1_mep_model::model_lmcpi_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWCP16, & mepcore1_mep_model::model_swcp16_before, & mepcore1_mep_model::model_swcp16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LWCP16, & mepcore1_mep_model::model_lwcp16_before, & mepcore1_mep_model::model_lwcp16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SMCP16, & mepcore1_mep_model::model_smcp16_before, & mepcore1_mep_model::model_smcp16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LMCP16, & mepcore1_mep_model::model_lmcp16_before, & mepcore1_mep_model::model_lmcp16_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SBCPA, & mepcore1_mep_model::model_sbcpa_before, & mepcore1_mep_model::model_sbcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBCPA, & mepcore1_mep_model::model_lbcpa_before, & mepcore1_mep_model::model_lbcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SHCPA, & mepcore1_mep_model::model_shcpa_before, & mepcore1_mep_model::model_shcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHCPA, & mepcore1_mep_model::model_lhcpa_before, & mepcore1_mep_model::model_lhcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWCPA, & mepcore1_mep_model::model_swcpa_before, & mepcore1_mep_model::model_swcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LWCPA, & mepcore1_mep_model::model_lwcpa_before, & mepcore1_mep_model::model_lwcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SMCPA, & mepcore1_mep_model::model_smcpa_before, & mepcore1_mep_model::model_smcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LMCPA, & mepcore1_mep_model::model_lmcpa_before, & mepcore1_mep_model::model_lmcpa_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SBCPM0, & mepcore1_mep_model::model_sbcpm0_before, & mepcore1_mep_model::model_sbcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBCPM0, & mepcore1_mep_model::model_lbcpm0_before, & mepcore1_mep_model::model_lbcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SHCPM0, & mepcore1_mep_model::model_shcpm0_before, & mepcore1_mep_model::model_shcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHCPM0, & mepcore1_mep_model::model_lhcpm0_before, & mepcore1_mep_model::model_lhcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWCPM0, & mepcore1_mep_model::model_swcpm0_before, & mepcore1_mep_model::model_swcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LWCPM0, & mepcore1_mep_model::model_lwcpm0_before, & mepcore1_mep_model::model_lwcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SMCPM0, & mepcore1_mep_model::model_smcpm0_before, & mepcore1_mep_model::model_smcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LMCPM0, & mepcore1_mep_model::model_lmcpm0_before, & mepcore1_mep_model::model_lmcpm0_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SBCPM1, & mepcore1_mep_model::model_sbcpm1_before, & mepcore1_mep_model::model_sbcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LBCPM1, & mepcore1_mep_model::model_lbcpm1_before, & mepcore1_mep_model::model_lbcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SHCPM1, & mepcore1_mep_model::model_shcpm1_before, & mepcore1_mep_model::model_shcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LHCPM1, & mepcore1_mep_model::model_lhcpm1_before, & mepcore1_mep_model::model_lhcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SWCPM1, & mepcore1_mep_model::model_swcpm1_before, & mepcore1_mep_model::model_swcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LWCPM1, & mepcore1_mep_model::model_lwcpm1_before, & mepcore1_mep_model::model_lwcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SMCPM1, & mepcore1_mep_model::model_smcpm1_before, & mepcore1_mep_model::model_smcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_LMCPM1, & mepcore1_mep_model::model_lmcpm1_before, & mepcore1_mep_model::model_lmcpm1_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BCPEQ, & mepcore1_mep_model::model_bcpeq_before, & mepcore1_mep_model::model_bcpeq_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BCPNE, & mepcore1_mep_model::model_bcpne_before, & mepcore1_mep_model::model_bcpne_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BCPAT, & mepcore1_mep_model::model_bcpat_before, & mepcore1_mep_model::model_bcpat_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_BCPAF, & mepcore1_mep_model::model_bcpaf_before, & mepcore1_mep_model::model_bcpaf_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_SYNCCP, & mepcore1_mep_model::model_synccp_before, & mepcore1_mep_model::model_synccp_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_JSRV, & mepcore1_mep_model::model_jsrv_before, & mepcore1_mep_model::model_jsrv_after, { { mepcore1_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_BSRV, & mepcore1_mep_model::model_bsrv_before, & mepcore1_mep_model::model_bsrv_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_SIM_SYSCALL, & mepcore1_mep_model::model_sim_syscall_before, & mepcore1_mep_model::model_sim_syscall_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE1_INSN_RI_0, & mepcore1_mep_model::model_ri_0_before, & mepcore1_mep_model::model_ri_0_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_1, & mepcore1_mep_model::model_ri_1_before, & mepcore1_mep_model::model_ri_1_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_2, & mepcore1_mep_model::model_ri_2_before, & mepcore1_mep_model::model_ri_2_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_3, & mepcore1_mep_model::model_ri_3_before, & mepcore1_mep_model::model_ri_3_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_4, & mepcore1_mep_model::model_ri_4_before, & mepcore1_mep_model::model_ri_4_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_5, & mepcore1_mep_model::model_ri_5_before, & mepcore1_mep_model::model_ri_5_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_6, & mepcore1_mep_model::model_ri_6_before, & mepcore1_mep_model::model_ri_6_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_7, & mepcore1_mep_model::model_ri_7_before, & mepcore1_mep_model::model_ri_7_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_8, & mepcore1_mep_model::model_ri_8_before, & mepcore1_mep_model::model_ri_8_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_9, & mepcore1_mep_model::model_ri_9_before, & mepcore1_mep_model::model_ri_9_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_10, & mepcore1_mep_model::model_ri_10_before, & mepcore1_mep_model::model_ri_10_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_11, & mepcore1_mep_model::model_ri_11_before, & mepcore1_mep_model::model_ri_11_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_12, & mepcore1_mep_model::model_ri_12_before, & mepcore1_mep_model::model_ri_12_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_13, & mepcore1_mep_model::model_ri_13_before, & mepcore1_mep_model::model_ri_13_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_14, & mepcore1_mep_model::model_ri_14_before, & mepcore1_mep_model::model_ri_14_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_15, & mepcore1_mep_model::model_ri_15_before, & mepcore1_mep_model::model_ri_15_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_17, & mepcore1_mep_model::model_ri_17_before, & mepcore1_mep_model::model_ri_17_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_20, & mepcore1_mep_model::model_ri_20_before, & mepcore1_mep_model::model_ri_20_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_21, & mepcore1_mep_model::model_ri_21_before, & mepcore1_mep_model::model_ri_21_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_22, & mepcore1_mep_model::model_ri_22_before, & mepcore1_mep_model::model_ri_22_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_23, & mepcore1_mep_model::model_ri_23_before, & mepcore1_mep_model::model_ri_23_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE1_INSN_RI_26, & mepcore1_mep_model::model_ri_26_before, & mepcore1_mep_model::model_ri_26_after, { { mepcore1_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore1_mep_model::UNIT_U_BRANCH, 0, 0 } } },
};

