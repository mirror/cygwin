/* Simulator model support for mepcore2.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext2.h"

using namespace mep_ext2; // FIXME: namespace organization still wip

/* The profiling data is recorded here, but is accessed via the profiling
   mechanism.  After all, this is information for profiling.  */

/* Model handlers for each insn.  */

mepcore2_mep_model::mepcore2_mep_model (mep_ext2_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
mepcore2_mep_model::model_sb_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sb_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sh_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sh_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lb_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lb_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lh_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lh_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw_sp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw_sp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw_sp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw_sp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sb_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sb_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sh_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sh_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lb_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lb_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lh_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lh_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbu_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbu_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhu_tp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhu_tp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sb16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sb16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sh16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sh16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lb16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lb16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lh16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lh16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbu16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbu16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhu16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhu16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw24_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sw24_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw24_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lw24_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_extb_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_extb_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_exth_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_exth_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_extub_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_extub_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_extuh_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_extuh_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ssarb_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ssarb_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mov_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mov_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_movi8_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movi8_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movi16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movi16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movu24_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movu24_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movu16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movu16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movh_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_movh_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_add3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add3i_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add3i_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_advck3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_advck3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sub_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sub_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbvck3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbvck3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_neg_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_neg_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slt3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slt3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sltu3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sltu3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slt3i_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slt3i_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sltu3i_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_sltu3i_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_sl1ad3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sl1ad3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sl2ad3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sl2ad3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add3x_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_add3x_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slt3x_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slt3x_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sltu3x_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sltu3x_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_or_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_or_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_and_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_and_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_xor_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_xor_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_nor_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_nor_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_or3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_or3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_and3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_and3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_xor3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_xor3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sra_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sra_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_srl_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_srl_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sll_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sll_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_srai_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_srai_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_srli_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_srli_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slli_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_slli_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sll3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sll3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_fsft_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_fsft_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bra_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bra_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_beqz_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_beqz_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bnez_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bnez_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_beqi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_beqi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bnei_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bnei_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_blti_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_blti_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bgei_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bgei_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_beq_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_beq_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bne_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bne_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsr12_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsr12_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsr24_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsr24_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jmp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jmp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jmp24_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jmp24_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jsr_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jsr_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ret_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ret_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_repeat_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_repeat_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_erepeat_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_erepeat_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_stc_lp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_lp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_hi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_hi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_lo_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_lo_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stc_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_lp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_lp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_hi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_hi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_lo_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_lo_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldc_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_di_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_di_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ei_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ei_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_reti_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_reti_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_halt_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_halt_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_sleep_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_sleep_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_swi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_swi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_break_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_break_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_syncm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_syncm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_stcb_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stcb.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_stcb_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stcb.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldcb_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldcb_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsetm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsetm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bclrm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bclrm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bnotm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bnotm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_btstm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_btstm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_tas_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_tas.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_tas_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_tas.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_cache_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_tas.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_cache_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_tas.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mul_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mul_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mulu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mulu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mulr_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mulr_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mulru_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_mulru_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_madd_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_madd_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maddu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maddu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maddr_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maddr_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maddru_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maddru_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_div_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_div_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_divu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_divu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_dret_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_dret_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_dbreak_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_dbreak_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ldz_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ldz_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sltu3x.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_abs_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_abs_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ave_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ave_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_min_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_min_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_max_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_max_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_minu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_minu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maxu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_maxu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_clip_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_clip_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_clipu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_clipu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sadd_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sadd_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ssub_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ssub_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_saddu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_saddu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ssubu_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ssubu_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpi_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpi_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcp16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcp16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcp16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcp16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcp16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcp16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcp16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcp16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_shcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_shcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpa_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpa_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_shcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_shcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpm0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpm0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm0.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sbcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lbcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_shcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_shcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lhcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_swcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lwcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_swcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_smcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpm1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_lmcpm1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_smcpm1.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bcpeq_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpeq_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpne_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpne_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpat_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpat_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpaf_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_bcpaf_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_synccp_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_synccp_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_jsrv_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_jsrv_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsrv_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_bsrv_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_sim_syscall_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_sim_syscall_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ri_0_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_0_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_1_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_1_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_2_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_2_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_3_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_3_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_4_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_4_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_5_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_5_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_6_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_6_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_7_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_7_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_8_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_8_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_9_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_9_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_10_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_10_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_11_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_11_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_12_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_12_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_13_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_13_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_14_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_14_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_15_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_15_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_17_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_17_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_20_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_20_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_21_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_21_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_22_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_22_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_23_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_23_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_24_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_24_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_25_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_25_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_26_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_26_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_16_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_16_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_18_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_18_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_19_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_ri_19_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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
mepcore2_mep_model::model_fadds_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fadds_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fsubs_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fsubs_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fmuls_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fmuls_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fdivs_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fdivs_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fsqrts_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fsqrts_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fabss_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fabss_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fnegs_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fnegs_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fmovs_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fmovs_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_froundws_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_froundws_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ftruncws_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ftruncws_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fceilws_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fceilws_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ffloorws_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_ffloorws_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcvtws_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcvtws_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcvtsw_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcvtsw_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpfs_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpfs_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpus_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpus_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpes_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpes_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpues_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpues_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpls_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpls_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpuls_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpuls_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmples_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmples_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpules_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpules_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpfis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpfis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpuis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpuis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpeis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpeis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpueis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpueis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmplis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmplis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpulis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpulis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpleis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpleis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpuleis_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_fcmpuleis_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadds.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmov_frn_rm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_frn_rm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmov_frn_rm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_frn_rm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmov_rm_frn_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rm_frn.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmov_rm_frn_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmov_rm_frn.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmovc_ccrn_rm_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmovc_ccrn_rm_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmovc_rm_ccrn_before (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rm_ccrn.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
mepcore2_mep_model::model_cmovc_rm_ccrn_after (mep_ext2_cpu *current_cpu, mepcore2_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_cmovc_rm_ccrn.f
  const mepcore2_scache* abuf = sem;
  const mepcore2_idesc* idesc = abuf->idesc;
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

const mepcore2_mep_model::insn_timing mepcore2_mep_model::timing[] = {
  { MEPCORE2_INSN_X_INVALID, 0, 0, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SB, & mepcore2_mep_model::model_sb_before, & mepcore2_mep_model::model_sb_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SH, & mepcore2_mep_model::model_sh_before, & mepcore2_mep_model::model_sh_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SW, & mepcore2_mep_model::model_sw_before, & mepcore2_mep_model::model_sw_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LB, & mepcore2_mep_model::model_lb_before, & mepcore2_mep_model::model_lb_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LH, & mepcore2_mep_model::model_lh_before, & mepcore2_mep_model::model_lh_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LW, & mepcore2_mep_model::model_lw_before, & mepcore2_mep_model::model_lw_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LBU, & mepcore2_mep_model::model_lbu_before, & mepcore2_mep_model::model_lbu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LHU, & mepcore2_mep_model::model_lhu_before, & mepcore2_mep_model::model_lhu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_SW_SP, & mepcore2_mep_model::model_sw_sp_before, & mepcore2_mep_model::model_sw_sp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LW_SP, & mepcore2_mep_model::model_lw_sp_before, & mepcore2_mep_model::model_lw_sp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_SB_TP, & mepcore2_mep_model::model_sb_tp_before, & mepcore2_mep_model::model_sb_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SH_TP, & mepcore2_mep_model::model_sh_tp_before, & mepcore2_mep_model::model_sh_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SW_TP, & mepcore2_mep_model::model_sw_tp_before, & mepcore2_mep_model::model_sw_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LB_TP, & mepcore2_mep_model::model_lb_tp_before, & mepcore2_mep_model::model_lb_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LH_TP, & mepcore2_mep_model::model_lh_tp_before, & mepcore2_mep_model::model_lh_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LW_TP, & mepcore2_mep_model::model_lw_tp_before, & mepcore2_mep_model::model_lw_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LBU_TP, & mepcore2_mep_model::model_lbu_tp_before, & mepcore2_mep_model::model_lbu_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LHU_TP, & mepcore2_mep_model::model_lhu_tp_before, & mepcore2_mep_model::model_lhu_tp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_SB16, & mepcore2_mep_model::model_sb16_before, & mepcore2_mep_model::model_sb16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SH16, & mepcore2_mep_model::model_sh16_before, & mepcore2_mep_model::model_sh16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SW16, & mepcore2_mep_model::model_sw16_before, & mepcore2_mep_model::model_sw16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LB16, & mepcore2_mep_model::model_lb16_before, & mepcore2_mep_model::model_lb16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LH16, & mepcore2_mep_model::model_lh16_before, & mepcore2_mep_model::model_lh16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LW16, & mepcore2_mep_model::model_lw16_before, & mepcore2_mep_model::model_lw16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LBU16, & mepcore2_mep_model::model_lbu16_before, & mepcore2_mep_model::model_lbu16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LHU16, & mepcore2_mep_model::model_lhu16_before, & mepcore2_mep_model::model_lhu16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_SW24, & mepcore2_mep_model::model_sw24_before, & mepcore2_mep_model::model_sw24_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LW24, & mepcore2_mep_model::model_lw24_before, & mepcore2_mep_model::model_lw24_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_EXTB, & mepcore2_mep_model::model_extb_before, & mepcore2_mep_model::model_extb_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_EXTH, & mepcore2_mep_model::model_exth_before, & mepcore2_mep_model::model_exth_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_EXTUB, & mepcore2_mep_model::model_extub_before, & mepcore2_mep_model::model_extub_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_EXTUH, & mepcore2_mep_model::model_extuh_before, & mepcore2_mep_model::model_extuh_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SSARB, & mepcore2_mep_model::model_ssarb_before, & mepcore2_mep_model::model_ssarb_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MOV, & mepcore2_mep_model::model_mov_before, & mepcore2_mep_model::model_mov_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MOVI8, & mepcore2_mep_model::model_movi8_before, & mepcore2_mep_model::model_movi8_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MOVI16, & mepcore2_mep_model::model_movi16_before, & mepcore2_mep_model::model_movi16_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MOVU24, & mepcore2_mep_model::model_movu24_before, & mepcore2_mep_model::model_movu24_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MOVU16, & mepcore2_mep_model::model_movu16_before, & mepcore2_mep_model::model_movu16_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MOVH, & mepcore2_mep_model::model_movh_before, & mepcore2_mep_model::model_movh_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_ADD3, & mepcore2_mep_model::model_add3_before, & mepcore2_mep_model::model_add3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_ADD, & mepcore2_mep_model::model_add_before, & mepcore2_mep_model::model_add_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_ADD3I, & mepcore2_mep_model::model_add3i_before, & mepcore2_mep_model::model_add3i_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_ADVCK3, & mepcore2_mep_model::model_advck3_before, & mepcore2_mep_model::model_advck3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SUB, & mepcore2_mep_model::model_sub_before, & mepcore2_mep_model::model_sub_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 } } },
  { MEPCORE2_INSN_SBVCK3, & mepcore2_mep_model::model_sbvck3_before, & mepcore2_mep_model::model_sbvck3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_NEG, & mepcore2_mep_model::model_neg_before, & mepcore2_mep_model::model_neg_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLT3, & mepcore2_mep_model::model_slt3_before, & mepcore2_mep_model::model_slt3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLTU3, & mepcore2_mep_model::model_sltu3_before, & mepcore2_mep_model::model_sltu3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLT3I, & mepcore2_mep_model::model_slt3i_before, & mepcore2_mep_model::model_slt3i_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLTU3I, & mepcore2_mep_model::model_sltu3i_before, & mepcore2_mep_model::model_sltu3i_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SL1AD3, & mepcore2_mep_model::model_sl1ad3_before, & mepcore2_mep_model::model_sl1ad3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SL2AD3, & mepcore2_mep_model::model_sl2ad3_before, & mepcore2_mep_model::model_sl2ad3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_ADD3X, & mepcore2_mep_model::model_add3x_before, & mepcore2_mep_model::model_add3x_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLT3X, & mepcore2_mep_model::model_slt3x_before, & mepcore2_mep_model::model_slt3x_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLTU3X, & mepcore2_mep_model::model_sltu3x_before, & mepcore2_mep_model::model_sltu3x_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_OR, & mepcore2_mep_model::model_or_before, & mepcore2_mep_model::model_or_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_AND, & mepcore2_mep_model::model_and_before, & mepcore2_mep_model::model_and_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_XOR, & mepcore2_mep_model::model_xor_before, & mepcore2_mep_model::model_xor_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_NOR, & mepcore2_mep_model::model_nor_before, & mepcore2_mep_model::model_nor_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_OR3, & mepcore2_mep_model::model_or3_before, & mepcore2_mep_model::model_or3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_AND3, & mepcore2_mep_model::model_and3_before, & mepcore2_mep_model::model_and3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_XOR3, & mepcore2_mep_model::model_xor3_before, & mepcore2_mep_model::model_xor3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SRA, & mepcore2_mep_model::model_sra_before, & mepcore2_mep_model::model_sra_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SRL, & mepcore2_mep_model::model_srl_before, & mepcore2_mep_model::model_srl_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLL, & mepcore2_mep_model::model_sll_before, & mepcore2_mep_model::model_sll_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SRAI, & mepcore2_mep_model::model_srai_before, & mepcore2_mep_model::model_srai_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SRLI, & mepcore2_mep_model::model_srli_before, & mepcore2_mep_model::model_srli_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLLI, & mepcore2_mep_model::model_slli_before, & mepcore2_mep_model::model_slli_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLL3, & mepcore2_mep_model::model_sll3_before, & mepcore2_mep_model::model_sll3_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FSFT, & mepcore2_mep_model::model_fsft_before, & mepcore2_mep_model::model_fsft_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BRA, & mepcore2_mep_model::model_bra_before, & mepcore2_mep_model::model_bra_after, { { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BEQZ, & mepcore2_mep_model::model_beqz_before, & mepcore2_mep_model::model_beqz_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BNEZ, & mepcore2_mep_model::model_bnez_before, & mepcore2_mep_model::model_bnez_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BEQI, & mepcore2_mep_model::model_beqi_before, & mepcore2_mep_model::model_beqi_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BNEI, & mepcore2_mep_model::model_bnei_before, & mepcore2_mep_model::model_bnei_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BLTI, & mepcore2_mep_model::model_blti_before, & mepcore2_mep_model::model_blti_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BGEI, & mepcore2_mep_model::model_bgei_before, & mepcore2_mep_model::model_bgei_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BEQ, & mepcore2_mep_model::model_beq_before, & mepcore2_mep_model::model_beq_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BNE, & mepcore2_mep_model::model_bne_before, & mepcore2_mep_model::model_bne_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BSR12, & mepcore2_mep_model::model_bsr12_before, & mepcore2_mep_model::model_bsr12_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BSR24, & mepcore2_mep_model::model_bsr24_before, & mepcore2_mep_model::model_bsr24_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_JMP, & mepcore2_mep_model::model_jmp_before, & mepcore2_mep_model::model_jmp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_JMP24, & mepcore2_mep_model::model_jmp24_before, & mepcore2_mep_model::model_jmp24_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_JSR, & mepcore2_mep_model::model_jsr_before, & mepcore2_mep_model::model_jsr_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RET, & mepcore2_mep_model::model_ret_before, & mepcore2_mep_model::model_ret_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_REPEAT, & mepcore2_mep_model::model_repeat_before, & mepcore2_mep_model::model_repeat_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_EREPEAT, & mepcore2_mep_model::model_erepeat_before, & mepcore2_mep_model::model_erepeat_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_STC_LP, & mepcore2_mep_model::model_stc_lp_before, & mepcore2_mep_model::model_stc_lp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_STC_HI, & mepcore2_mep_model::model_stc_hi_before, & mepcore2_mep_model::model_stc_hi_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_STC_LO, & mepcore2_mep_model::model_stc_lo_before, & mepcore2_mep_model::model_stc_lo_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_STC, & mepcore2_mep_model::model_stc_before, & mepcore2_mep_model::model_stc_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_STORE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LDC_LP, & mepcore2_mep_model::model_ldc_lp_before, & mepcore2_mep_model::model_ldc_lp_after, { { mepcore2_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LDC_HI, & mepcore2_mep_model::model_ldc_hi_before, & mepcore2_mep_model::model_ldc_hi_after, { { mepcore2_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LDC_LO, & mepcore2_mep_model::model_ldc_lo_before, & mepcore2_mep_model::model_ldc_lo_after, { { mepcore2_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_LDC, & mepcore2_mep_model::model_ldc_before, & mepcore2_mep_model::model_ldc_after, { { mepcore2_mep_model::UNIT_U_USE_CTRL_REG, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LOAD_GPR, 0, 0 } } },
  { MEPCORE2_INSN_DI, & mepcore2_mep_model::model_di_before, & mepcore2_mep_model::model_di_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_EI, & mepcore2_mep_model::model_ei_before, & mepcore2_mep_model::model_ei_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_RETI, & mepcore2_mep_model::model_reti_before, & mepcore2_mep_model::model_reti_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_HALT, & mepcore2_mep_model::model_halt_before, & mepcore2_mep_model::model_halt_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SLEEP, & mepcore2_mep_model::model_sleep_before, & mepcore2_mep_model::model_sleep_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWI, & mepcore2_mep_model::model_swi_before, & mepcore2_mep_model::model_swi_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BREAK, & mepcore2_mep_model::model_break_before, & mepcore2_mep_model::model_break_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_SYNCM, & mepcore2_mep_model::model_syncm_before, & mepcore2_mep_model::model_syncm_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_STCB, & mepcore2_mep_model::model_stcb_before, & mepcore2_mep_model::model_stcb_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_STCB, 0, 0 } } },
  { MEPCORE2_INSN_LDCB, & mepcore2_mep_model::model_ldcb_before, & mepcore2_mep_model::model_ldcb_after, { { mepcore2_mep_model::UNIT_U_LDCB, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_LDCB_GPR, 0, 0 } } },
  { MEPCORE2_INSN_BSETM, & mepcore2_mep_model::model_bsetm_before, & mepcore2_mep_model::model_bsetm_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BCLRM, & mepcore2_mep_model::model_bclrm_before, & mepcore2_mep_model::model_bclrm_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BNOTM, & mepcore2_mep_model::model_bnotm_before, & mepcore2_mep_model::model_bnotm_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BTSTM, & mepcore2_mep_model::model_btstm_before, & mepcore2_mep_model::model_btstm_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_TAS, & mepcore2_mep_model::model_tas_before, & mepcore2_mep_model::model_tas_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CACHE, & mepcore2_mep_model::model_cache_before, & mepcore2_mep_model::model_cache_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MUL, & mepcore2_mep_model::model_mul_before, & mepcore2_mep_model::model_mul_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE2_INSN_MULU, & mepcore2_mep_model::model_mulu_before, & mepcore2_mep_model::model_mulu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE2_INSN_MULR, & mepcore2_mep_model::model_mulr_before, & mepcore2_mep_model::model_mulr_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore2_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE2_INSN_MULRU, & mepcore2_mep_model::model_mulru_before, & mepcore2_mep_model::model_mulru_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore2_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE2_INSN_MADD, & mepcore2_mep_model::model_madd_before, & mepcore2_mep_model::model_madd_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE2_INSN_MADDU, & mepcore2_mep_model::model_maddu_before, & mepcore2_mep_model::model_maddu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 } } },
  { MEPCORE2_INSN_MADDR, & mepcore2_mep_model::model_maddr_before, & mepcore2_mep_model::model_maddr_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore2_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE2_INSN_MADDRU, & mepcore2_mep_model::model_maddru_before, & mepcore2_mep_model::model_maddru_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_MULTIPLY, 0, 0 }, { mepcore2_mep_model::UNIT_U_MUL_GPR, 0, 0 } } },
  { MEPCORE2_INSN_DIV, & mepcore2_mep_model::model_div_before, & mepcore2_mep_model::model_div_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_DIVIDE, 0, 0 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_DIVU, & mepcore2_mep_model::model_divu_before, & mepcore2_mep_model::model_divu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_DIVIDE, 0, 0 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_DRET, & mepcore2_mep_model::model_dret_before, & mepcore2_mep_model::model_dret_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_DBREAK, & mepcore2_mep_model::model_dbreak_before, & mepcore2_mep_model::model_dbreak_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LDZ, & mepcore2_mep_model::model_ldz_before, & mepcore2_mep_model::model_ldz_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_ABS, & mepcore2_mep_model::model_abs_before, & mepcore2_mep_model::model_abs_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_AVE, & mepcore2_mep_model::model_ave_before, & mepcore2_mep_model::model_ave_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MIN, & mepcore2_mep_model::model_min_before, & mepcore2_mep_model::model_min_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MAX, & mepcore2_mep_model::model_max_before, & mepcore2_mep_model::model_max_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MINU, & mepcore2_mep_model::model_minu_before, & mepcore2_mep_model::model_minu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_MAXU, & mepcore2_mep_model::model_maxu_before, & mepcore2_mep_model::model_maxu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CLIP, & mepcore2_mep_model::model_clip_before, & mepcore2_mep_model::model_clip_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CLIPU, & mepcore2_mep_model::model_clipu_before, & mepcore2_mep_model::model_clipu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SADD, & mepcore2_mep_model::model_sadd_before, & mepcore2_mep_model::model_sadd_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SSUB, & mepcore2_mep_model::model_ssub_before, & mepcore2_mep_model::model_ssub_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SADDU, & mepcore2_mep_model::model_saddu_before, & mepcore2_mep_model::model_saddu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SSUBU, & mepcore2_mep_model::model_ssubu_before, & mepcore2_mep_model::model_ssubu_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWCP, & mepcore2_mep_model::model_swcp_before, & mepcore2_mep_model::model_swcp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LWCP, & mepcore2_mep_model::model_lwcp_before, & mepcore2_mep_model::model_lwcp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SMCP, & mepcore2_mep_model::model_smcp_before, & mepcore2_mep_model::model_smcp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LMCP, & mepcore2_mep_model::model_lmcp_before, & mepcore2_mep_model::model_lmcp_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWCPI, & mepcore2_mep_model::model_swcpi_before, & mepcore2_mep_model::model_swcpi_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LWCPI, & mepcore2_mep_model::model_lwcpi_before, & mepcore2_mep_model::model_lwcpi_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SMCPI, & mepcore2_mep_model::model_smcpi_before, & mepcore2_mep_model::model_smcpi_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LMCPI, & mepcore2_mep_model::model_lmcpi_before, & mepcore2_mep_model::model_lmcpi_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWCP16, & mepcore2_mep_model::model_swcp16_before, & mepcore2_mep_model::model_swcp16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LWCP16, & mepcore2_mep_model::model_lwcp16_before, & mepcore2_mep_model::model_lwcp16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SMCP16, & mepcore2_mep_model::model_smcp16_before, & mepcore2_mep_model::model_smcp16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LMCP16, & mepcore2_mep_model::model_lmcp16_before, & mepcore2_mep_model::model_lmcp16_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SBCPA, & mepcore2_mep_model::model_sbcpa_before, & mepcore2_mep_model::model_sbcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LBCPA, & mepcore2_mep_model::model_lbcpa_before, & mepcore2_mep_model::model_lbcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SHCPA, & mepcore2_mep_model::model_shcpa_before, & mepcore2_mep_model::model_shcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LHCPA, & mepcore2_mep_model::model_lhcpa_before, & mepcore2_mep_model::model_lhcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWCPA, & mepcore2_mep_model::model_swcpa_before, & mepcore2_mep_model::model_swcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LWCPA, & mepcore2_mep_model::model_lwcpa_before, & mepcore2_mep_model::model_lwcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SMCPA, & mepcore2_mep_model::model_smcpa_before, & mepcore2_mep_model::model_smcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LMCPA, & mepcore2_mep_model::model_lmcpa_before, & mepcore2_mep_model::model_lmcpa_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SBCPM0, & mepcore2_mep_model::model_sbcpm0_before, & mepcore2_mep_model::model_sbcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LBCPM0, & mepcore2_mep_model::model_lbcpm0_before, & mepcore2_mep_model::model_lbcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SHCPM0, & mepcore2_mep_model::model_shcpm0_before, & mepcore2_mep_model::model_shcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LHCPM0, & mepcore2_mep_model::model_lhcpm0_before, & mepcore2_mep_model::model_lhcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWCPM0, & mepcore2_mep_model::model_swcpm0_before, & mepcore2_mep_model::model_swcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LWCPM0, & mepcore2_mep_model::model_lwcpm0_before, & mepcore2_mep_model::model_lwcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SMCPM0, & mepcore2_mep_model::model_smcpm0_before, & mepcore2_mep_model::model_smcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LMCPM0, & mepcore2_mep_model::model_lmcpm0_before, & mepcore2_mep_model::model_lmcpm0_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SBCPM1, & mepcore2_mep_model::model_sbcpm1_before, & mepcore2_mep_model::model_sbcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LBCPM1, & mepcore2_mep_model::model_lbcpm1_before, & mepcore2_mep_model::model_lbcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SHCPM1, & mepcore2_mep_model::model_shcpm1_before, & mepcore2_mep_model::model_shcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LHCPM1, & mepcore2_mep_model::model_lhcpm1_before, & mepcore2_mep_model::model_lhcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SWCPM1, & mepcore2_mep_model::model_swcpm1_before, & mepcore2_mep_model::model_swcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LWCPM1, & mepcore2_mep_model::model_lwcpm1_before, & mepcore2_mep_model::model_lwcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SMCPM1, & mepcore2_mep_model::model_smcpm1_before, & mepcore2_mep_model::model_smcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_LMCPM1, & mepcore2_mep_model::model_lmcpm1_before, & mepcore2_mep_model::model_lmcpm1_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BCPEQ, & mepcore2_mep_model::model_bcpeq_before, & mepcore2_mep_model::model_bcpeq_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BCPNE, & mepcore2_mep_model::model_bcpne_before, & mepcore2_mep_model::model_bcpne_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BCPAT, & mepcore2_mep_model::model_bcpat_before, & mepcore2_mep_model::model_bcpat_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_BCPAF, & mepcore2_mep_model::model_bcpaf_before, & mepcore2_mep_model::model_bcpaf_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_SYNCCP, & mepcore2_mep_model::model_synccp_before, & mepcore2_mep_model::model_synccp_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_JSRV, & mepcore2_mep_model::model_jsrv_before, & mepcore2_mep_model::model_jsrv_after, { { mepcore2_mep_model::UNIT_U_USE_GPR, 0, 0 }, { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_BSRV, & mepcore2_mep_model::model_bsrv_before, & mepcore2_mep_model::model_bsrv_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_SIM_SYSCALL, & mepcore2_mep_model::model_sim_syscall_before, & mepcore2_mep_model::model_sim_syscall_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_RI_0, & mepcore2_mep_model::model_ri_0_before, & mepcore2_mep_model::model_ri_0_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_1, & mepcore2_mep_model::model_ri_1_before, & mepcore2_mep_model::model_ri_1_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_2, & mepcore2_mep_model::model_ri_2_before, & mepcore2_mep_model::model_ri_2_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_3, & mepcore2_mep_model::model_ri_3_before, & mepcore2_mep_model::model_ri_3_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_4, & mepcore2_mep_model::model_ri_4_before, & mepcore2_mep_model::model_ri_4_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_5, & mepcore2_mep_model::model_ri_5_before, & mepcore2_mep_model::model_ri_5_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_6, & mepcore2_mep_model::model_ri_6_before, & mepcore2_mep_model::model_ri_6_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_7, & mepcore2_mep_model::model_ri_7_before, & mepcore2_mep_model::model_ri_7_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_8, & mepcore2_mep_model::model_ri_8_before, & mepcore2_mep_model::model_ri_8_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_9, & mepcore2_mep_model::model_ri_9_before, & mepcore2_mep_model::model_ri_9_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_10, & mepcore2_mep_model::model_ri_10_before, & mepcore2_mep_model::model_ri_10_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_11, & mepcore2_mep_model::model_ri_11_before, & mepcore2_mep_model::model_ri_11_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_12, & mepcore2_mep_model::model_ri_12_before, & mepcore2_mep_model::model_ri_12_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_13, & mepcore2_mep_model::model_ri_13_before, & mepcore2_mep_model::model_ri_13_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_14, & mepcore2_mep_model::model_ri_14_before, & mepcore2_mep_model::model_ri_14_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_15, & mepcore2_mep_model::model_ri_15_before, & mepcore2_mep_model::model_ri_15_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_17, & mepcore2_mep_model::model_ri_17_before, & mepcore2_mep_model::model_ri_17_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_20, & mepcore2_mep_model::model_ri_20_before, & mepcore2_mep_model::model_ri_20_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_21, & mepcore2_mep_model::model_ri_21_before, & mepcore2_mep_model::model_ri_21_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_22, & mepcore2_mep_model::model_ri_22_before, & mepcore2_mep_model::model_ri_22_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_23, & mepcore2_mep_model::model_ri_23_before, & mepcore2_mep_model::model_ri_23_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_24, & mepcore2_mep_model::model_ri_24_before, & mepcore2_mep_model::model_ri_24_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_25, & mepcore2_mep_model::model_ri_25_before, & mepcore2_mep_model::model_ri_25_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_26, & mepcore2_mep_model::model_ri_26_before, & mepcore2_mep_model::model_ri_26_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_16, & mepcore2_mep_model::model_ri_16_before, & mepcore2_mep_model::model_ri_16_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_18, & mepcore2_mep_model::model_ri_18_before, & mepcore2_mep_model::model_ri_18_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_RI_19, & mepcore2_mep_model::model_ri_19_before, & mepcore2_mep_model::model_ri_19_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 }, { mepcore2_mep_model::UNIT_U_BRANCH, 0, 0 } } },
  { MEPCORE2_INSN_FADDS, & mepcore2_mep_model::model_fadds_before, & mepcore2_mep_model::model_fadds_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FSUBS, & mepcore2_mep_model::model_fsubs_before, & mepcore2_mep_model::model_fsubs_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FMULS, & mepcore2_mep_model::model_fmuls_before, & mepcore2_mep_model::model_fmuls_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FDIVS, & mepcore2_mep_model::model_fdivs_before, & mepcore2_mep_model::model_fdivs_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FSQRTS, & mepcore2_mep_model::model_fsqrts_before, & mepcore2_mep_model::model_fsqrts_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FABSS, & mepcore2_mep_model::model_fabss_before, & mepcore2_mep_model::model_fabss_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FNEGS, & mepcore2_mep_model::model_fnegs_before, & mepcore2_mep_model::model_fnegs_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FMOVS, & mepcore2_mep_model::model_fmovs_before, & mepcore2_mep_model::model_fmovs_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FROUNDWS, & mepcore2_mep_model::model_froundws_before, & mepcore2_mep_model::model_froundws_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FTRUNCWS, & mepcore2_mep_model::model_ftruncws_before, & mepcore2_mep_model::model_ftruncws_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCEILWS, & mepcore2_mep_model::model_fceilws_before, & mepcore2_mep_model::model_fceilws_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FFLOORWS, & mepcore2_mep_model::model_ffloorws_before, & mepcore2_mep_model::model_ffloorws_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCVTWS, & mepcore2_mep_model::model_fcvtws_before, & mepcore2_mep_model::model_fcvtws_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCVTSW, & mepcore2_mep_model::model_fcvtsw_before, & mepcore2_mep_model::model_fcvtsw_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPFS, & mepcore2_mep_model::model_fcmpfs_before, & mepcore2_mep_model::model_fcmpfs_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPUS, & mepcore2_mep_model::model_fcmpus_before, & mepcore2_mep_model::model_fcmpus_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPES, & mepcore2_mep_model::model_fcmpes_before, & mepcore2_mep_model::model_fcmpes_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPUES, & mepcore2_mep_model::model_fcmpues_before, & mepcore2_mep_model::model_fcmpues_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPLS, & mepcore2_mep_model::model_fcmpls_before, & mepcore2_mep_model::model_fcmpls_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPULS, & mepcore2_mep_model::model_fcmpuls_before, & mepcore2_mep_model::model_fcmpuls_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPLES, & mepcore2_mep_model::model_fcmples_before, & mepcore2_mep_model::model_fcmples_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPULES, & mepcore2_mep_model::model_fcmpules_before, & mepcore2_mep_model::model_fcmpules_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPFIS, & mepcore2_mep_model::model_fcmpfis_before, & mepcore2_mep_model::model_fcmpfis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPUIS, & mepcore2_mep_model::model_fcmpuis_before, & mepcore2_mep_model::model_fcmpuis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPEIS, & mepcore2_mep_model::model_fcmpeis_before, & mepcore2_mep_model::model_fcmpeis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPUEIS, & mepcore2_mep_model::model_fcmpueis_before, & mepcore2_mep_model::model_fcmpueis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPLIS, & mepcore2_mep_model::model_fcmplis_before, & mepcore2_mep_model::model_fcmplis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPULIS, & mepcore2_mep_model::model_fcmpulis_before, & mepcore2_mep_model::model_fcmpulis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPLEIS, & mepcore2_mep_model::model_fcmpleis_before, & mepcore2_mep_model::model_fcmpleis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_FCMPULEIS, & mepcore2_mep_model::model_fcmpuleis_before, & mepcore2_mep_model::model_fcmpuleis_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CMOV_FRN_RM, & mepcore2_mep_model::model_cmov_frn_rm_before, & mepcore2_mep_model::model_cmov_frn_rm_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CMOV_RM_FRN, & mepcore2_mep_model::model_cmov_rm_frn_before, & mepcore2_mep_model::model_cmov_rm_frn_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CMOVC_CCRN_RM, & mepcore2_mep_model::model_cmovc_ccrn_rm_before, & mepcore2_mep_model::model_cmovc_ccrn_rm_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
  { MEPCORE2_INSN_CMOVC_RM_CCRN, & mepcore2_mep_model::model_cmovc_rm_ccrn_before, & mepcore2_mep_model::model_cmovc_rm_ccrn_after, { { mepcore2_mep_model::UNIT_U_EXEC, 1, 1 } } },
};

