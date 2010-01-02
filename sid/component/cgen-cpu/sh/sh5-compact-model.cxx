/* Simulator model support for sh5_compact.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh5.h"

using namespace sh5; // FIXME: namespace organization still wip

/* The profiling data is recorded here, but is accessed via the profiling
   mechanism.  After all, this is information for profiling.  */

/* Model handlers for each insn.  */

sh5_compact_sh5_model::sh5_compact_sh5_model (sh5_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
sh5_compact_sh5_model::model_add_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_add_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_compact_sh5_model::model_addi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_addi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_addc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_addc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_addv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_addv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_and_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_and_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_compact_sh5_model::model_andi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_andi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_andb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_logic_b_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_andb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_logic_b_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bf_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bf_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 2)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bfs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bfs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 3)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bra_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_branch_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bra_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_braf_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_jmp_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_braf_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_jmp_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_brk_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_brk_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bsr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_branch_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bsr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bsrf_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_jsr_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bsrf_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_jsr_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 2)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bts_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_branch_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_bts_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    if (insn_referenced & (1 << 3)) referenced |= 1 << 0;
    cycles += model_u_branch_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_clrmac_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_set_mac_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_clrmac_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_mac_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_clrs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_clrs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_clrt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_clrt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpeq_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpeq_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpeqi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpeqi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpge_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpge_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpgt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpgt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmphi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmphi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmphs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmphs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmppl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmppl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmppz_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmppz_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpstr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_cmpstr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_div0s_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_div0s_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_div0u_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_div0u_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_div1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_div1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_divu_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_divu_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_compact_sh5_model::model_mulr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_mulr_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_mulr_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mulr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_mulr_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_mulr_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_dmulsl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_dmul_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_dmulsl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_dmul_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_dmulul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_dmul_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_dmulul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_dmul_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_dt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_dt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extsb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extsb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extsw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extsw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extub_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extub_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extuw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_extuw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fabs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_0_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fabs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_0_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fadd_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fadd_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcmpeq_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fcmp_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcmpeq_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fcmp_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcmpgt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fcmp_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcmpgt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fcmp_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcnvds_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drn);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fcnv_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_fpul_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcnvds_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drn);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fcnv_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_fpul_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcnvsd_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_fpul_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fcnv_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drn);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fcnvsd_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpul_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fcnv_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drn);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fdiv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_fdiv_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fdiv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_fdiv_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fipr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    INT in_fvm = -1;
    INT in_fvn = -1;
    cycles += model_u_fipr_before (current_cpu, idesc, 1, in_fvm, in_fvn);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fipr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_fvm = -1;
    INT in_fvn = -1;
    cycles += model_u_fipr_after (current_cpu, idesc, 1, referenced, in_fvm, in_fvn);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_flds_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_flds_fpul_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_flds_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_flds_fpul_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fldi0_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_0_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fldi0_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_0_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fldi1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_0_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fldi1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_0_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_float_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_float_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_fpul_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_float_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_float_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpul_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmac_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmac_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fr0);
    cycles += model_u_use_fr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 4);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_before (current_cpu, idesc, 5, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmac_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmac_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fr0);
    cycles += model_u_use_fr_after (current_cpu, idesc, 2, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 4, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov1_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_set_fr_0_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov1_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_set_fr_0_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_load_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_load_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_load_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_load_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 4);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_load_fr_before (current_cpu, idesc, 5, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fmovn);
    cycles += model_u_load_fr_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov6_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov6_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 4);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 5);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fmovm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 2, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 4, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 5, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drn);
    cycles += model_u_load_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drn);
    cycles += model_u_load_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmov9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fmul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fneg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_0_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fneg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_0_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_frchg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_frchg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fschg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fschg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fsqrt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_fsqrt_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fsqrt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_fsqrt_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fsts_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_fpul_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_0_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fsts_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpul_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frn);
    cycles += model_u_set_fr_0_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fsub_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_fsub_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdm);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fsdn);
    cycles += model_u_set_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ftrc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrc_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_fpul_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ftrc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrc_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fsdn);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_fpul_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ftrv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    INT in_fvn = -1;
    cycles += model_u_ftrv_before (current_cpu, idesc, 1, in_fvn);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ftrv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_fvn = -1;
    cycles += model_u_ftrv_after (current_cpu, idesc, 1, referenced, in_fvn);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_jmp_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_jmp_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_jmp_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_jmp_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_jsr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_jsr_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_jsr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_jsr_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldc_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldc_gbr_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldc_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldc_gbr_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldc_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldc_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_ldc_sr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldc_sr_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldc_sr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldc_sr_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldcl_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldcl_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_load_gbr_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldcl_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldcl_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_gbr_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldcl_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldcl_vbr_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_load_vbr_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldcl_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldcl_vbr_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_vbr_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_lds_fpscr_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_lds_fpscr_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_lds_fpscr_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_ldsl_fpscr_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_lds_fpscr_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldsl_fpscr_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_load_fpul_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_fpul_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_load_fpul_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_fpul_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_mac_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_mac_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_load_mac_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_mac_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_mac_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_mac_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_load_mac_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_mac_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_lds_pr_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_lds_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_lds_pr_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_lds_pr_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_load_pr_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ldsl_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_lds_pr_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_load_pr_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_macl_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_macl_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_macw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_macw_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_macw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_macw_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mov_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mov_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_movi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movi20_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movi20_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 2, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_sx_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_sx_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb10_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movb10_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 2, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_sx_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_sx_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl10_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl10_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl11_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl11_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl12_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl12_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl13_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movl13_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 2, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_sx_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_sx_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw10_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw10_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_load_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw11_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movw11_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mova_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mova_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movcal_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ocb_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movcal_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ocb_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movcol_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movcol_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_movt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 0, referenced);
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
sh5_compact_sh5_model::model_movual_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movual_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movual2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_movual2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_r0);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mull_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_mull_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mull_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_mull_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mulsw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_mulsw_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_mulsw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_mulsw_after (current_cpu, idesc, 2, referenced);
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
sh5_compact_sh5_model::model_muluw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_mulsw_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_multiply_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_muluw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_mulsw_after (current_cpu, idesc, 2, referenced);
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
sh5_compact_sh5_model::model_neg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_neg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_negc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_negc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_nop_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_nop_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_not_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_not_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_ocbi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ocb_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ocbi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ocb_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ocbp_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ocb_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ocbp_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ocb_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ocbwb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ocb_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ocbwb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ocb_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_or_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_or_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_compact_sh5_model::model_ori_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_ori_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_orb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_logic_b_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_orb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_logic_b_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_pref_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_pref_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotcl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotcl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotcr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotcr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rotr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rts_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_jmp_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_rts_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    referenced |= 1 << 0;
    cycles += model_u_jmp_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sets_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sets_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sett_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sett_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shad_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shad_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shal_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shal_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shar_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shar_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shld_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shld_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll16_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shll16_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr16_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_shlr16_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stc_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stc_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stc_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_stc_vbr_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stc_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_stc_vbr_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stcl_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldcl_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stcl_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldcl_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stcl_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_ldcl_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stcl_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_ldcl_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_fpscr_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_fpu_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpscr_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_fpu_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_fpscr_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpscr_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_fpul_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_fpu_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpul_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rn);
    cycles += model_u_fpu_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_fpul_before (current_cpu, idesc, 0);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_maybe_fpu_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_fpu_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_fpul_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_maybe_fpu_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_write_back_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_write_back_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_write_back_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_write_back_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_write_back_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_write_back_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_multiply_result_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_write_back_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_multiply_result_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_write_back_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_use_pr_before (current_cpu, idesc, 0);
  }
  {
    cycles += model_u_sts_pr_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sts_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_pr_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_sts_pr_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_pr_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_sts_pr_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_stsl_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_pr_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_sts_pr_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sub_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_sub_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_compact_sh5_model::model_subc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_subc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_subv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_subv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_swapb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_swapb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_swapw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_swapw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tasb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_tas_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tasb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_tas_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_trapa_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_trap_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_trapa_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_trap_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tst_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tst_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tsti_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tsti_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tstb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_use_tbit_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_sx_before (current_cpu, idesc, 3);
  }
  {
    cycles += model_u_set_sr_bit_before (current_cpu, idesc, 4);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 5);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_tstb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_use_tbit_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_sx_after (current_cpu, idesc, 3, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_set_sr_bit_after (current_cpu, idesc, 4, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 5, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_xor_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_xor_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm64);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_compact_sh5_model::model_xori_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_xori_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_compact_sh5_model::model_xorb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_logic_b_before (current_cpu, idesc, 1);
  }
  {
    cycles += model_u_memory_access_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_xorb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_r0);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_logic_b_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_memory_access_after (current_cpu, idesc, 2, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_xtrct_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  {
    cycles += model_u_shift_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_model::model_xtrct_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rn);
    cycles += model_u_use_gr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 2, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_shift_after (current_cpu, idesc, 3, referenced);
  }
  return cycles;
#undef FLD
}

sh5_compact_sh5_media_model::sh5_compact_sh5_media_model (sh5_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
sh5_compact_sh5_media_model::model_add_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_add_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_addi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_addi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_addc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_addc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_addv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_addv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_and_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_and_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_andi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_andi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_andb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_andb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bf_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bf_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bfs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bfs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bra_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bra_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_braf_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_braf_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_brk_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_brk_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bsr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bsr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bsrf_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bsrf_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bts_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_bts_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_clrmac_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_clrmac_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_clrs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_clrs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_clrt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_clrt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpeq_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpeq_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpeqi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpeqi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpge_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpge_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpgt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpgt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmphi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmphi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmphs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmphs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmppl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmppl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmppz_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmppz_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpstr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_cmpstr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_div0s_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_div0s_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_div0u_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_div0u_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_div1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_div1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_divu_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_divu_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mulr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mulr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_dmulsl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_dmulsl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_dmulul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_dmulul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_dt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_dt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extsb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extsb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extsw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extsw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extub_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extub_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extuw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_extuw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fabs_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fabs_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fadd_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fadd_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcmpeq_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcmpeq_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcmpgt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcmpgt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcnvds_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcnvds_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcnvsd_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fcnvsd_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fdiv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fdiv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fipr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fipr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_flds_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_flds_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fldi0_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fldi0_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fldi1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fldi1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_float_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_float_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_float_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_float_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmac_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmac_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmac_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmac_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov1_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov1_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov6_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov6_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov7_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmov9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmov9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fmul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fneg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fneg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_frchg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_frchg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fschg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fschg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fsqrt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fsqrt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fsts_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fsts_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fsub_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_fsub_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fadd_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ftrc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrc_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ftrc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrc_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ftrv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ftrv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fipr_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_jmp_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_jmp_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_jsr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_jsr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldc_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldc_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldc_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldc_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldc_sr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldc_sr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldcl_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldcl_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldcl_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldcl_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_lds_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ldsl_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_macw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_macw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mov_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mov_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movi20_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movi20_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb10_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movb10_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl10_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl10_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl11_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl11_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl12_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl12_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl13_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movl13_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw1_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw1_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw3_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw3_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw4_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw4_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw5_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw5_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw6_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw6_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw7_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw7_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw9_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw9_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw10_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw10_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw11_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movw11_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mova_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mova_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movcal_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movcal_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movcol_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movcol_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movt_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movt_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movual_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movual_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movual2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_movual2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movual2_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mull_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mull_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mulsw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_mulsw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_muluw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_muluw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_neg_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_neg_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_negc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_negc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_nop_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_nop_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_not_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_not_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ocbi_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ocbi_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ocbp_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ocbp_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ocbwb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ocbwb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_or_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_or_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ori_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_ori_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_orb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_orb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_pref_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_pref_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotcl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotcl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotcr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotcr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rotr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rts_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_rts_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sets_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sets_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sett_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sett_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shad_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shad_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shal_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shal_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shar_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shar_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shld_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shld_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll16_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shll16_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr2_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr2_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr8_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr8_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr16_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_shlr16_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stc_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stc_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stc_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stc_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stcl_gbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stcl_gbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stcl_vbr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stcl_vbr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_fpscr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_fpscr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_fpul_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_fpul_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_mach_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_mach_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_macl_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_macl_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sts_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_pr_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_stsl_pr_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sub_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_sub_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_subc_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_subc_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_subv_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_subv_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_swapb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_swapb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_swapw_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_swapw_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tasb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tasb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stsl_fpul_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_trapa_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_trapa_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tst_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tst_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tsti_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tsti_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tstb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_tstb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xor_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xor_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xori_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xori_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xorb_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xorb_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xtrct_compact_before (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_compact_sh5_media_model::model_xtrct_compact_after (sh5_cpu *current_cpu, sh5_compact_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh5_compact_scache* abuf = sem;
  const sh5_compact_idesc* idesc = abuf->idesc;
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

/* Model timing data for `sh5'.  */

const sh5_compact_sh5_model::insn_timing sh5_compact_sh5_model::timing[] = {
  { SH5_COMPACT_INSN_X_INVALID, 0, 0, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADD_COMPACT, & sh5_compact_sh5_model::model_add_compact_before, & sh5_compact_sh5_model::model_add_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADDI_COMPACT, & sh5_compact_sh5_model::model_addi_compact_before, & sh5_compact_sh5_model::model_addi_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADDC_COMPACT, & sh5_compact_sh5_model::model_addc_compact_before, & sh5_compact_sh5_model::model_addc_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_ADDV_COMPACT, & sh5_compact_sh5_model::model_addv_compact_before, & sh5_compact_sh5_model::model_addv_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_AND_COMPACT, & sh5_compact_sh5_model::model_and_compact_before, & sh5_compact_sh5_model::model_and_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ANDI_COMPACT, & sh5_compact_sh5_model::model_andi_compact_before, & sh5_compact_sh5_model::model_andi_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ANDB_COMPACT, & sh5_compact_sh5_model::model_andb_compact_before, & sh5_compact_sh5_model::model_andb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOGIC_B, 0, 3 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_BF_COMPACT, & sh5_compact_sh5_model::model_bf_compact_before, & sh5_compact_sh5_model::model_bf_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_BRANCH, 0, 3 } } },
  { SH5_COMPACT_INSN_BFS_COMPACT, & sh5_compact_sh5_model::model_bfs_compact_before, & sh5_compact_sh5_model::model_bfs_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH5_COMPACT_INSN_BRA_COMPACT, & sh5_compact_sh5_model::model_bra_compact_before, & sh5_compact_sh5_model::model_bra_compact_after, { { sh5_compact_sh5_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH5_COMPACT_INSN_BRAF_COMPACT, & sh5_compact_sh5_model::model_braf_compact_before, & sh5_compact_sh5_model::model_braf_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_JMP, 0, 2 } } },
  { SH5_COMPACT_INSN_BRK_COMPACT, & sh5_compact_sh5_model::model_brk_compact_before, & sh5_compact_sh5_model::model_brk_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BSR_COMPACT, & sh5_compact_sh5_model::model_bsr_compact_before, & sh5_compact_sh5_model::model_bsr_compact_after, { { sh5_compact_sh5_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH5_COMPACT_INSN_BSRF_COMPACT, & sh5_compact_sh5_model::model_bsrf_compact_before, & sh5_compact_sh5_model::model_bsrf_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_JSR, 0, 2 } } },
  { SH5_COMPACT_INSN_BT_COMPACT, & sh5_compact_sh5_model::model_bt_compact_before, & sh5_compact_sh5_model::model_bt_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_BRANCH, 0, 3 } } },
  { SH5_COMPACT_INSN_BTS_COMPACT, & sh5_compact_sh5_model::model_bts_compact_before, & sh5_compact_sh5_model::model_bts_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH5_COMPACT_INSN_CLRMAC_COMPACT, & sh5_compact_sh5_model::model_clrmac_compact_before, & sh5_compact_sh5_model::model_clrmac_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_MAC, 0, 0 } } },
  { SH5_COMPACT_INSN_CLRS_COMPACT, & sh5_compact_sh5_model::model_clrs_compact_before, & sh5_compact_sh5_model::model_clrs_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CLRT_COMPACT, & sh5_compact_sh5_model::model_clrt_compact_before, & sh5_compact_sh5_model::model_clrt_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPEQ_COMPACT, & sh5_compact_sh5_model::model_cmpeq_compact_before, & sh5_compact_sh5_model::model_cmpeq_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPEQI_COMPACT, & sh5_compact_sh5_model::model_cmpeqi_compact_before, & sh5_compact_sh5_model::model_cmpeqi_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPGE_COMPACT, & sh5_compact_sh5_model::model_cmpge_compact_before, & sh5_compact_sh5_model::model_cmpge_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPGT_COMPACT, & sh5_compact_sh5_model::model_cmpgt_compact_before, & sh5_compact_sh5_model::model_cmpgt_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPHI_COMPACT, & sh5_compact_sh5_model::model_cmphi_compact_before, & sh5_compact_sh5_model::model_cmphi_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPHS_COMPACT, & sh5_compact_sh5_model::model_cmphs_compact_before, & sh5_compact_sh5_model::model_cmphs_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPPL_COMPACT, & sh5_compact_sh5_model::model_cmppl_compact_before, & sh5_compact_sh5_model::model_cmppl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPPZ_COMPACT, & sh5_compact_sh5_model::model_cmppz_compact_before, & sh5_compact_sh5_model::model_cmppz_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_CMPSTR_COMPACT, & sh5_compact_sh5_model::model_cmpstr_compact_before, & sh5_compact_sh5_model::model_cmpstr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_DIV0S_COMPACT, & sh5_compact_sh5_model::model_div0s_compact_before, & sh5_compact_sh5_model::model_div0s_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_DIV0U_COMPACT, & sh5_compact_sh5_model::model_div0u_compact_before, & sh5_compact_sh5_model::model_div0u_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_DIV1_COMPACT, & sh5_compact_sh5_model::model_div1_compact_before, & sh5_compact_sh5_model::model_div1_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_DIVU_COMPACT, & sh5_compact_sh5_model::model_divu_compact_before, & sh5_compact_sh5_model::model_divu_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 34 } } },
  { SH5_COMPACT_INSN_MULR_COMPACT, & sh5_compact_sh5_model::model_mulr_compact_before, & sh5_compact_sh5_model::model_mulr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MULR, 1, 2 }, { sh5_compact_sh5_model::UNIT_U_MULR_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_DMULSL_COMPACT, & sh5_compact_sh5_model::model_dmulsl_compact_before, & sh5_compact_sh5_model::model_dmulsl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_DMUL, 1, 2 } } },
  { SH5_COMPACT_INSN_DMULUL_COMPACT, & sh5_compact_sh5_model::model_dmulul_compact_before, & sh5_compact_sh5_model::model_dmulul_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_DMUL, 1, 2 } } },
  { SH5_COMPACT_INSN_DT_COMPACT, & sh5_compact_sh5_model::model_dt_compact_before, & sh5_compact_sh5_model::model_dt_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_EXTSB_COMPACT, & sh5_compact_sh5_model::model_extsb_compact_before, & sh5_compact_sh5_model::model_extsb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_EXTSW_COMPACT, & sh5_compact_sh5_model::model_extsw_compact_before, & sh5_compact_sh5_model::model_extsw_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_EXTUB_COMPACT, & sh5_compact_sh5_model::model_extub_compact_before, & sh5_compact_sh5_model::model_extub_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_EXTUW_COMPACT, & sh5_compact_sh5_model::model_extuw_compact_before, & sh5_compact_sh5_model::model_extuw_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_FABS_COMPACT, & sh5_compact_sh5_model::model_fabs_compact_before, & sh5_compact_sh5_model::model_fabs_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR_0, 0, 0 } } },
  { SH5_COMPACT_INSN_FADD_COMPACT, & sh5_compact_sh5_model::model_fadd_compact_before, & sh5_compact_sh5_model::model_fadd_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FCMPEQ_COMPACT, & sh5_compact_sh5_model::model_fcmpeq_compact_before, & sh5_compact_sh5_model::model_fcmpeq_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FCMP, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 } } },
  { SH5_COMPACT_INSN_FCMPGT_COMPACT, & sh5_compact_sh5_model::model_fcmpgt_compact_before, & sh5_compact_sh5_model::model_fcmpgt_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FCMP, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 } } },
  { SH5_COMPACT_INSN_FCNVDS_COMPACT, & sh5_compact_sh5_model::model_fcnvds_compact_before, & sh5_compact_sh5_model::model_fcnvds_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_DR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FCNV, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FPUL, 0, 0 } } },
  { SH5_COMPACT_INSN_FCNVSD_COMPACT, & sh5_compact_sh5_model::model_fcnvsd_compact_before, & sh5_compact_sh5_model::model_fcnvsd_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FPUL, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FCNV, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_DR, 0, 0 } } },
  { SH5_COMPACT_INSN_FDIV_COMPACT, & sh5_compact_sh5_model::model_fdiv_compact_before, & sh5_compact_sh5_model::model_fdiv_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FDIV, 0, 0 } } },
  { SH5_COMPACT_INSN_FIPR_COMPACT, & sh5_compact_sh5_model::model_fipr_compact_before, & sh5_compact_sh5_model::model_fipr_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FIPR, 0, 0 } } },
  { SH5_COMPACT_INSN_FLDS_COMPACT, & sh5_compact_sh5_model::model_flds_compact_before, & sh5_compact_sh5_model::model_flds_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FLDS_FPUL, 0, 0 } } },
  { SH5_COMPACT_INSN_FLDI0_COMPACT, & sh5_compact_sh5_model::model_fldi0_compact_before, & sh5_compact_sh5_model::model_fldi0_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR_0, 0, 0 } } },
  { SH5_COMPACT_INSN_FLDI1_COMPACT, & sh5_compact_sh5_model::model_fldi1_compact_before, & sh5_compact_sh5_model::model_fldi1_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR_0, 0, 0 } } },
  { SH5_COMPACT_INSN_FLOAT_COMPACT, & sh5_compact_sh5_model::model_float_compact_before, & sh5_compact_sh5_model::model_float_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FPUL, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FMAC_COMPACT, & sh5_compact_sh5_model::model_fmac_compact_before, & sh5_compact_sh5_model::model_fmac_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV1_COMPACT, & sh5_compact_sh5_model::model_fmov1_compact_before, & sh5_compact_sh5_model::model_fmov1_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR_0, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV2_COMPACT, & sh5_compact_sh5_model::model_fmov2_compact_before, & sh5_compact_sh5_model::model_fmov2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV3_COMPACT, & sh5_compact_sh5_model::model_fmov3_compact_before, & sh5_compact_sh5_model::model_fmov3_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV4_COMPACT, & sh5_compact_sh5_model::model_fmov4_compact_before, & sh5_compact_sh5_model::model_fmov4_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV5_COMPACT, & sh5_compact_sh5_model::model_fmov5_compact_before, & sh5_compact_sh5_model::model_fmov5_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV6_COMPACT, & sh5_compact_sh5_model::model_fmov6_compact_before, & sh5_compact_sh5_model::model_fmov6_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV7_COMPACT, & sh5_compact_sh5_model::model_fmov7_compact_before, & sh5_compact_sh5_model::model_fmov7_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV8_COMPACT, & sh5_compact_sh5_model::model_fmov8_compact_before, & sh5_compact_sh5_model::model_fmov8_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 1 }, { sh5_compact_sh5_model::UNIT_U_LOAD_DR, 0, 0 } } },
  { SH5_COMPACT_INSN_FMOV9_COMPACT, & sh5_compact_sh5_model::model_fmov9_compact_before, & sh5_compact_sh5_model::model_fmov9_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 1 } } },
  { SH5_COMPACT_INSN_FMUL_COMPACT, & sh5_compact_sh5_model::model_fmul_compact_before, & sh5_compact_sh5_model::model_fmul_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FNEG_COMPACT, & sh5_compact_sh5_model::model_fneg_compact_before, & sh5_compact_sh5_model::model_fneg_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR_0, 0, 0 } } },
  { SH5_COMPACT_INSN_FRCHG_COMPACT, & sh5_compact_sh5_model::model_frchg_compact_before, & sh5_compact_sh5_model::model_frchg_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FSCHG_COMPACT, & sh5_compact_sh5_model::model_fschg_compact_before, & sh5_compact_sh5_model::model_fschg_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FSQRT_COMPACT, & sh5_compact_sh5_model::model_fsqrt_compact_before, & sh5_compact_sh5_model::model_fsqrt_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FSQRT, 0, 0 } } },
  { SH5_COMPACT_INSN_FSTS_COMPACT, & sh5_compact_sh5_model::model_fsts_compact_before, & sh5_compact_sh5_model::model_fsts_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FPUL, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR_0, 0, 0 } } },
  { SH5_COMPACT_INSN_FSUB_COMPACT, & sh5_compact_sh5_model::model_fsub_compact_before, & sh5_compact_sh5_model::model_fsub_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FR, 0, 0 } } },
  { SH5_COMPACT_INSN_FTRC_COMPACT, & sh5_compact_sh5_model::model_ftrc_compact_before, & sh5_compact_sh5_model::model_ftrc_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_FPUL, 0, 0 } } },
  { SH5_COMPACT_INSN_FTRV_COMPACT, & sh5_compact_sh5_model::model_ftrv_compact_before, & sh5_compact_sh5_model::model_ftrv_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_FTRV, 0, 0 } } },
  { SH5_COMPACT_INSN_JMP_COMPACT, & sh5_compact_sh5_model::model_jmp_compact_before, & sh5_compact_sh5_model::model_jmp_compact_after, { { sh5_compact_sh5_model::UNIT_U_JMP, 0, 2 } } },
  { SH5_COMPACT_INSN_JSR_COMPACT, & sh5_compact_sh5_model::model_jsr_compact_before, & sh5_compact_sh5_model::model_jsr_compact_after, { { sh5_compact_sh5_model::UNIT_U_JSR, 0, 2 } } },
  { SH5_COMPACT_INSN_LDC_GBR_COMPACT, & sh5_compact_sh5_model::model_ldc_gbr_compact_before, & sh5_compact_sh5_model::model_ldc_gbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDC_GBR, 0, 1 } } },
  { SH5_COMPACT_INSN_LDC_VBR_COMPACT, & sh5_compact_sh5_model::model_ldc_vbr_compact_before, & sh5_compact_sh5_model::model_ldc_vbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDC_SR_COMPACT, & sh5_compact_sh5_model::model_ldc_sr_compact_before, & sh5_compact_sh5_model::model_ldc_sr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDC_SR, 0, 1 } } },
  { SH5_COMPACT_INSN_LDCL_GBR_COMPACT, & sh5_compact_sh5_model::model_ldcl_gbr_compact_before, & sh5_compact_sh5_model::model_ldcl_gbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDCL, 0, 3 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GBR, 0, 0 } } },
  { SH5_COMPACT_INSN_LDCL_VBR_COMPACT, & sh5_compact_sh5_model::model_ldcl_vbr_compact_before, & sh5_compact_sh5_model::model_ldcl_vbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDCL_VBR, 0, 3 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_VBR, 0, 0 } } },
  { SH5_COMPACT_INSN_LDS_FPSCR_COMPACT, & sh5_compact_sh5_model::model_lds_fpscr_compact_before, & sh5_compact_sh5_model::model_lds_fpscr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDS_FPSCR, 0, 3 } } },
  { SH5_COMPACT_INSN_LDSL_FPSCR_COMPACT, & sh5_compact_sh5_model::model_ldsl_fpscr_compact_before, & sh5_compact_sh5_model::model_ldsl_fpscr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDS_FPSCR, 0, 3 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDSL_FPSCR, 0, 0 } } },
  { SH5_COMPACT_INSN_LDS_FPUL_COMPACT, & sh5_compact_sh5_model::model_lds_fpul_compact_before, & sh5_compact_sh5_model::model_lds_fpul_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_FPUL, 0, 0 } } },
  { SH5_COMPACT_INSN_LDSL_FPUL_COMPACT, & sh5_compact_sh5_model::model_ldsl_fpul_compact_before, & sh5_compact_sh5_model::model_ldsl_fpul_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_FPUL, 0, 0 } } },
  { SH5_COMPACT_INSN_LDS_MACH_COMPACT, & sh5_compact_sh5_model::model_lds_mach_compact_before, & sh5_compact_sh5_model::model_lds_mach_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_MAC, 0, 0 } } },
  { SH5_COMPACT_INSN_LDSL_MACH_COMPACT, & sh5_compact_sh5_model::model_ldsl_mach_compact_before, & sh5_compact_sh5_model::model_ldsl_mach_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_MAC, 0, 0 } } },
  { SH5_COMPACT_INSN_LDS_MACL_COMPACT, & sh5_compact_sh5_model::model_lds_macl_compact_before, & sh5_compact_sh5_model::model_lds_macl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_MAC, 0, 0 } } },
  { SH5_COMPACT_INSN_LDSL_MACL_COMPACT, & sh5_compact_sh5_model::model_ldsl_macl_compact_before, & sh5_compact_sh5_model::model_ldsl_macl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_MAC, 0, 0 } } },
  { SH5_COMPACT_INSN_LDS_PR_COMPACT, & sh5_compact_sh5_model::model_lds_pr_compact_before, & sh5_compact_sh5_model::model_lds_pr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDS_PR, 0, 1 } } },
  { SH5_COMPACT_INSN_LDSL_PR_COMPACT, & sh5_compact_sh5_model::model_ldsl_pr_compact_before, & sh5_compact_sh5_model::model_ldsl_pr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDS_PR, 0, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_PR, 0, 0 } } },
  { SH5_COMPACT_INSN_MACL_COMPACT, & sh5_compact_sh5_model::model_macl_compact_before, & sh5_compact_sh5_model::model_macl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MACL, 1, 2 } } },
  { SH5_COMPACT_INSN_MACW_COMPACT, & sh5_compact_sh5_model::model_macw_compact_before, & sh5_compact_sh5_model::model_macw_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MACW, 1, 2 } } },
  { SH5_COMPACT_INSN_MOV_COMPACT, & sh5_compact_sh5_model::model_mov_compact_before, & sh5_compact_sh5_model::model_mov_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVI_COMPACT, & sh5_compact_sh5_model::model_movi_compact_before, & sh5_compact_sh5_model::model_movi_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVI20_COMPACT, & sh5_compact_sh5_model::model_movi20_compact_before, & sh5_compact_sh5_model::model_movi20_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB1_COMPACT, & sh5_compact_sh5_model::model_movb1_compact_before, & sh5_compact_sh5_model::model_movb1_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB2_COMPACT, & sh5_compact_sh5_model::model_movb2_compact_before, & sh5_compact_sh5_model::model_movb2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB3_COMPACT, & sh5_compact_sh5_model::model_movb3_compact_before, & sh5_compact_sh5_model::model_movb3_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB4_COMPACT, & sh5_compact_sh5_model::model_movb4_compact_before, & sh5_compact_sh5_model::model_movb4_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SX, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB5_COMPACT, & sh5_compact_sh5_model::model_movb5_compact_before, & sh5_compact_sh5_model::model_movb5_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB6_COMPACT, & sh5_compact_sh5_model::model_movb6_compact_before, & sh5_compact_sh5_model::model_movb6_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB7_COMPACT, & sh5_compact_sh5_model::model_movb7_compact_before, & sh5_compact_sh5_model::model_movb7_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB8_COMPACT, & sh5_compact_sh5_model::model_movb8_compact_before, & sh5_compact_sh5_model::model_movb8_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB9_COMPACT, & sh5_compact_sh5_model::model_movb9_compact_before, & sh5_compact_sh5_model::model_movb9_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVB10_COMPACT, & sh5_compact_sh5_model::model_movb10_compact_before, & sh5_compact_sh5_model::model_movb10_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL1_COMPACT, & sh5_compact_sh5_model::model_movl1_compact_before, & sh5_compact_sh5_model::model_movl1_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL2_COMPACT, & sh5_compact_sh5_model::model_movl2_compact_before, & sh5_compact_sh5_model::model_movl2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL3_COMPACT, & sh5_compact_sh5_model::model_movl3_compact_before, & sh5_compact_sh5_model::model_movl3_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL4_COMPACT, & sh5_compact_sh5_model::model_movl4_compact_before, & sh5_compact_sh5_model::model_movl4_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SX, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL5_COMPACT, & sh5_compact_sh5_model::model_movl5_compact_before, & sh5_compact_sh5_model::model_movl5_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL6_COMPACT, & sh5_compact_sh5_model::model_movl6_compact_before, & sh5_compact_sh5_model::model_movl6_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL7_COMPACT, & sh5_compact_sh5_model::model_movl7_compact_before, & sh5_compact_sh5_model::model_movl7_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL8_COMPACT, & sh5_compact_sh5_model::model_movl8_compact_before, & sh5_compact_sh5_model::model_movl8_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL9_COMPACT, & sh5_compact_sh5_model::model_movl9_compact_before, & sh5_compact_sh5_model::model_movl9_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL10_COMPACT, & sh5_compact_sh5_model::model_movl10_compact_before, & sh5_compact_sh5_model::model_movl10_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL11_COMPACT, & sh5_compact_sh5_model::model_movl11_compact_before, & sh5_compact_sh5_model::model_movl11_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL12_COMPACT, & sh5_compact_sh5_model::model_movl12_compact_before, & sh5_compact_sh5_model::model_movl12_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVL13_COMPACT, & sh5_compact_sh5_model::model_movl13_compact_before, & sh5_compact_sh5_model::model_movl13_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW1_COMPACT, & sh5_compact_sh5_model::model_movw1_compact_before, & sh5_compact_sh5_model::model_movw1_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW2_COMPACT, & sh5_compact_sh5_model::model_movw2_compact_before, & sh5_compact_sh5_model::model_movw2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW3_COMPACT, & sh5_compact_sh5_model::model_movw3_compact_before, & sh5_compact_sh5_model::model_movw3_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW4_COMPACT, & sh5_compact_sh5_model::model_movw4_compact_before, & sh5_compact_sh5_model::model_movw4_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SX, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW5_COMPACT, & sh5_compact_sh5_model::model_movw5_compact_before, & sh5_compact_sh5_model::model_movw5_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW6_COMPACT, & sh5_compact_sh5_model::model_movw6_compact_before, & sh5_compact_sh5_model::model_movw6_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW7_COMPACT, & sh5_compact_sh5_model::model_movw7_compact_before, & sh5_compact_sh5_model::model_movw7_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW8_COMPACT, & sh5_compact_sh5_model::model_movw8_compact_before, & sh5_compact_sh5_model::model_movw8_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW9_COMPACT, & sh5_compact_sh5_model::model_movw9_compact_before, & sh5_compact_sh5_model::model_movw9_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW10_COMPACT, & sh5_compact_sh5_model::model_movw10_compact_before, & sh5_compact_sh5_model::model_movw10_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVW11_COMPACT, & sh5_compact_sh5_model::model_movw11_compact_before, & sh5_compact_sh5_model::model_movw11_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVA_COMPACT, & sh5_compact_sh5_model::model_mova_compact_before, & sh5_compact_sh5_model::model_mova_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVCAL_COMPACT, & sh5_compact_sh5_model::model_movcal_compact_before, & sh5_compact_sh5_model::model_movcal_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_OCB, 0, 6 } } },
  { SH5_COMPACT_INSN_MOVCOL_COMPACT, & sh5_compact_sh5_model::model_movcol_compact_before, & sh5_compact_sh5_model::model_movcol_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVT_COMPACT, & sh5_compact_sh5_model::model_movt_compact_before, & sh5_compact_sh5_model::model_movt_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVUAL_COMPACT, & sh5_compact_sh5_model::model_movual_compact_before, & sh5_compact_sh5_model::model_movual_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 1 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MOVUAL2_COMPACT, & sh5_compact_sh5_model::model_movual2_compact_before, & sh5_compact_sh5_model::model_movual2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 1 }, { sh5_compact_sh5_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_MULL_COMPACT, & sh5_compact_sh5_model::model_mull_compact_before, & sh5_compact_sh5_model::model_mull_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MULL, 1, 2 } } },
  { SH5_COMPACT_INSN_MULSW_COMPACT, & sh5_compact_sh5_model::model_mulsw_compact_before, & sh5_compact_sh5_model::model_mulsw_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MULSW, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MULTIPLY, 1, 2 } } },
  { SH5_COMPACT_INSN_MULUW_COMPACT, & sh5_compact_sh5_model::model_muluw_compact_before, & sh5_compact_sh5_model::model_muluw_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MULSW, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MULTIPLY, 1, 2 } } },
  { SH5_COMPACT_INSN_NEG_COMPACT, & sh5_compact_sh5_model::model_neg_compact_before, & sh5_compact_sh5_model::model_neg_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_NEGC_COMPACT, & sh5_compact_sh5_model::model_negc_compact_before, & sh5_compact_sh5_model::model_negc_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_NOP_COMPACT, & sh5_compact_sh5_model::model_nop_compact_before, & sh5_compact_sh5_model::model_nop_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_NOT_COMPACT, & sh5_compact_sh5_model::model_not_compact_before, & sh5_compact_sh5_model::model_not_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_OCBI_COMPACT, & sh5_compact_sh5_model::model_ocbi_compact_before, & sh5_compact_sh5_model::model_ocbi_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_OCB, 0, 1 } } },
  { SH5_COMPACT_INSN_OCBP_COMPACT, & sh5_compact_sh5_model::model_ocbp_compact_before, & sh5_compact_sh5_model::model_ocbp_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_OCB, 0, 4 } } },
  { SH5_COMPACT_INSN_OCBWB_COMPACT, & sh5_compact_sh5_model::model_ocbwb_compact_before, & sh5_compact_sh5_model::model_ocbwb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_OCB, 0, 4 } } },
  { SH5_COMPACT_INSN_OR_COMPACT, & sh5_compact_sh5_model::model_or_compact_before, & sh5_compact_sh5_model::model_or_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ORI_COMPACT, & sh5_compact_sh5_model::model_ori_compact_before, & sh5_compact_sh5_model::model_ori_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ORB_COMPACT, & sh5_compact_sh5_model::model_orb_compact_before, & sh5_compact_sh5_model::model_orb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOGIC_B, 0, 3 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_PREF_COMPACT, & sh5_compact_sh5_model::model_pref_compact_before, & sh5_compact_sh5_model::model_pref_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_ROTCL_COMPACT, & sh5_compact_sh5_model::model_rotcl_compact_before, & sh5_compact_sh5_model::model_rotcl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_ROTCR_COMPACT, & sh5_compact_sh5_model::model_rotcr_compact_before, & sh5_compact_sh5_model::model_rotcr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_ROTL_COMPACT, & sh5_compact_sh5_model::model_rotl_compact_before, & sh5_compact_sh5_model::model_rotl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_ROTR_COMPACT, & sh5_compact_sh5_model::model_rotr_compact_before, & sh5_compact_sh5_model::model_rotr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_RTS_COMPACT, & sh5_compact_sh5_model::model_rts_compact_before, & sh5_compact_sh5_model::model_rts_compact_after, { { sh5_compact_sh5_model::UNIT_U_JMP, 0, 2 } } },
  { SH5_COMPACT_INSN_SETS_COMPACT, & sh5_compact_sh5_model::model_sets_compact_before, & sh5_compact_sh5_model::model_sets_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SETT_COMPACT, & sh5_compact_sh5_model::model_sett_compact_before, & sh5_compact_sh5_model::model_sett_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHAD_COMPACT, & sh5_compact_sh5_model::model_shad_compact_before, & sh5_compact_sh5_model::model_shad_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHAL_COMPACT, & sh5_compact_sh5_model::model_shal_compact_before, & sh5_compact_sh5_model::model_shal_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHAR_COMPACT, & sh5_compact_sh5_model::model_shar_compact_before, & sh5_compact_sh5_model::model_shar_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLD_COMPACT, & sh5_compact_sh5_model::model_shld_compact_before, & sh5_compact_sh5_model::model_shld_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLL_COMPACT, & sh5_compact_sh5_model::model_shll_compact_before, & sh5_compact_sh5_model::model_shll_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLL2_COMPACT, & sh5_compact_sh5_model::model_shll2_compact_before, & sh5_compact_sh5_model::model_shll2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLL8_COMPACT, & sh5_compact_sh5_model::model_shll8_compact_before, & sh5_compact_sh5_model::model_shll8_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLL16_COMPACT, & sh5_compact_sh5_model::model_shll16_compact_before, & sh5_compact_sh5_model::model_shll16_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLR_COMPACT, & sh5_compact_sh5_model::model_shlr_compact_before, & sh5_compact_sh5_model::model_shlr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLR2_COMPACT, & sh5_compact_sh5_model::model_shlr2_compact_before, & sh5_compact_sh5_model::model_shlr2_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLR8_COMPACT, & sh5_compact_sh5_model::model_shlr8_compact_before, & sh5_compact_sh5_model::model_shlr8_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SHLR16_COMPACT, & sh5_compact_sh5_model::model_shlr16_compact_before, & sh5_compact_sh5_model::model_shlr16_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_STC_GBR_COMPACT, & sh5_compact_sh5_model::model_stc_gbr_compact_before, & sh5_compact_sh5_model::model_stc_gbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STC_VBR_COMPACT, & sh5_compact_sh5_model::model_stc_vbr_compact_before, & sh5_compact_sh5_model::model_stc_vbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_STC_VBR, 0, 1 } } },
  { SH5_COMPACT_INSN_STCL_GBR_COMPACT, & sh5_compact_sh5_model::model_stcl_gbr_compact_before, & sh5_compact_sh5_model::model_stcl_gbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDCL, 0, 2 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STCL_VBR_COMPACT, & sh5_compact_sh5_model::model_stcl_vbr_compact_before, & sh5_compact_sh5_model::model_stcl_vbr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LDCL, 0, 2 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STS_FPSCR_COMPACT, & sh5_compact_sh5_model::model_sts_fpscr_compact_before, & sh5_compact_sh5_model::model_sts_fpscr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FPSCR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_STSL_FPSCR_COMPACT, & sh5_compact_sh5_model::model_stsl_fpscr_compact_before, & sh5_compact_sh5_model::model_stsl_fpscr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_FPSCR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STS_FPUL_COMPACT, & sh5_compact_sh5_model::model_sts_fpul_compact_before, & sh5_compact_sh5_model::model_sts_fpul_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FPUL, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_LOAD_GR, 0, 0 } } },
  { SH5_COMPACT_INSN_STSL_FPUL_COMPACT, & sh5_compact_sh5_model::model_stsl_fpul_compact_before, & sh5_compact_sh5_model::model_stsl_fpul_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_FPUL, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MAYBE_FPU, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_FPU_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STS_MACH_COMPACT, & sh5_compact_sh5_model::model_sts_mach_compact_before, & sh5_compact_sh5_model::model_sts_mach_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STSL_MACH_COMPACT, & sh5_compact_sh5_model::model_stsl_mach_compact_before, & sh5_compact_sh5_model::model_stsl_mach_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STS_MACL_COMPACT, & sh5_compact_sh5_model::model_sts_macl_compact_before, & sh5_compact_sh5_model::model_sts_macl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STSL_MACL_COMPACT, & sh5_compact_sh5_model::model_stsl_macl_compact_before, & sh5_compact_sh5_model::model_stsl_macl_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_STS_PR_COMPACT, & sh5_compact_sh5_model::model_sts_pr_compact_before, & sh5_compact_sh5_model::model_sts_pr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_PR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_STS_PR, 0, 1 } } },
  { SH5_COMPACT_INSN_STSL_PR_COMPACT, & sh5_compact_sh5_model::model_stsl_pr_compact_before, & sh5_compact_sh5_model::model_stsl_pr_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_PR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_STS_PR, 0, 1 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_SUB_COMPACT, & sh5_compact_sh5_model::model_sub_compact_before, & sh5_compact_sh5_model::model_sub_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SUBC_COMPACT, & sh5_compact_sh5_model::model_subc_compact_before, & sh5_compact_sh5_model::model_subc_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SUBV_COMPACT, & sh5_compact_sh5_model::model_subv_compact_before, & sh5_compact_sh5_model::model_subv_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_SWAPB_COMPACT, & sh5_compact_sh5_model::model_swapb_compact_before, & sh5_compact_sh5_model::model_swapb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_SWAPW_COMPACT, & sh5_compact_sh5_model::model_swapw_compact_before, & sh5_compact_sh5_model::model_swapw_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH5_COMPACT_INSN_TASB_COMPACT, & sh5_compact_sh5_model::model_tasb_compact_before, & sh5_compact_sh5_model::model_tasb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_TAS, 1, 4 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_TRAPA_COMPACT, & sh5_compact_sh5_model::model_trapa_compact_before, & sh5_compact_sh5_model::model_trapa_compact_after, { { sh5_compact_sh5_model::UNIT_U_TRAP, 0, 8 } } },
  { SH5_COMPACT_INSN_TST_COMPACT, & sh5_compact_sh5_model::model_tst_compact_before, & sh5_compact_sh5_model::model_tst_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_TSTI_COMPACT, & sh5_compact_sh5_model::model_tsti_compact_before, & sh5_compact_sh5_model::model_tsti_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH5_COMPACT_INSN_TSTB_COMPACT, & sh5_compact_sh5_model::model_tstb_compact_before, & sh5_compact_sh5_model::model_tstb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_TBIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 3 }, { sh5_compact_sh5_model::UNIT_U_SX, 1, 3 }, { sh5_compact_sh5_model::UNIT_U_SET_SR_BIT, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_XOR_COMPACT, & sh5_compact_sh5_model::model_xor_compact_before, & sh5_compact_sh5_model::model_xor_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_XORI_COMPACT, & sh5_compact_sh5_model::model_xori_compact_before, & sh5_compact_sh5_model::model_xori_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_XORB_COMPACT, & sh5_compact_sh5_model::model_xorb_compact_before, & sh5_compact_sh5_model::model_xorb_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_LOGIC_B, 0, 3 }, { sh5_compact_sh5_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH5_COMPACT_INSN_XTRCT_COMPACT, & sh5_compact_sh5_model::model_xtrct_compact_before, & sh5_compact_sh5_model::model_xtrct_compact_after, { { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_USE_GR, 0, 0 }, { sh5_compact_sh5_model::UNIT_U_EXEC, 1, 1 }, { sh5_compact_sh5_model::UNIT_U_SHIFT, 0, 0 } } },
};

/* Model timing data for `sh5-media'.  */

const sh5_compact_sh5_media_model::insn_timing sh5_compact_sh5_media_model::timing[] = {
  { SH5_COMPACT_INSN_X_INVALID, 0, 0, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADD_COMPACT, & sh5_compact_sh5_media_model::model_add_compact_before, & sh5_compact_sh5_media_model::model_add_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADDI_COMPACT, & sh5_compact_sh5_media_model::model_addi_compact_before, & sh5_compact_sh5_media_model::model_addi_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADDC_COMPACT, & sh5_compact_sh5_media_model::model_addc_compact_before, & sh5_compact_sh5_media_model::model_addc_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ADDV_COMPACT, & sh5_compact_sh5_media_model::model_addv_compact_before, & sh5_compact_sh5_media_model::model_addv_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_AND_COMPACT, & sh5_compact_sh5_media_model::model_and_compact_before, & sh5_compact_sh5_media_model::model_and_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ANDI_COMPACT, & sh5_compact_sh5_media_model::model_andi_compact_before, & sh5_compact_sh5_media_model::model_andi_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ANDB_COMPACT, & sh5_compact_sh5_media_model::model_andb_compact_before, & sh5_compact_sh5_media_model::model_andb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BF_COMPACT, & sh5_compact_sh5_media_model::model_bf_compact_before, & sh5_compact_sh5_media_model::model_bf_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BFS_COMPACT, & sh5_compact_sh5_media_model::model_bfs_compact_before, & sh5_compact_sh5_media_model::model_bfs_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BRA_COMPACT, & sh5_compact_sh5_media_model::model_bra_compact_before, & sh5_compact_sh5_media_model::model_bra_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BRAF_COMPACT, & sh5_compact_sh5_media_model::model_braf_compact_before, & sh5_compact_sh5_media_model::model_braf_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BRK_COMPACT, & sh5_compact_sh5_media_model::model_brk_compact_before, & sh5_compact_sh5_media_model::model_brk_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BSR_COMPACT, & sh5_compact_sh5_media_model::model_bsr_compact_before, & sh5_compact_sh5_media_model::model_bsr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BSRF_COMPACT, & sh5_compact_sh5_media_model::model_bsrf_compact_before, & sh5_compact_sh5_media_model::model_bsrf_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BT_COMPACT, & sh5_compact_sh5_media_model::model_bt_compact_before, & sh5_compact_sh5_media_model::model_bt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_BTS_COMPACT, & sh5_compact_sh5_media_model::model_bts_compact_before, & sh5_compact_sh5_media_model::model_bts_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CLRMAC_COMPACT, & sh5_compact_sh5_media_model::model_clrmac_compact_before, & sh5_compact_sh5_media_model::model_clrmac_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CLRS_COMPACT, & sh5_compact_sh5_media_model::model_clrs_compact_before, & sh5_compact_sh5_media_model::model_clrs_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CLRT_COMPACT, & sh5_compact_sh5_media_model::model_clrt_compact_before, & sh5_compact_sh5_media_model::model_clrt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPEQ_COMPACT, & sh5_compact_sh5_media_model::model_cmpeq_compact_before, & sh5_compact_sh5_media_model::model_cmpeq_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPEQI_COMPACT, & sh5_compact_sh5_media_model::model_cmpeqi_compact_before, & sh5_compact_sh5_media_model::model_cmpeqi_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPGE_COMPACT, & sh5_compact_sh5_media_model::model_cmpge_compact_before, & sh5_compact_sh5_media_model::model_cmpge_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPGT_COMPACT, & sh5_compact_sh5_media_model::model_cmpgt_compact_before, & sh5_compact_sh5_media_model::model_cmpgt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPHI_COMPACT, & sh5_compact_sh5_media_model::model_cmphi_compact_before, & sh5_compact_sh5_media_model::model_cmphi_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPHS_COMPACT, & sh5_compact_sh5_media_model::model_cmphs_compact_before, & sh5_compact_sh5_media_model::model_cmphs_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPPL_COMPACT, & sh5_compact_sh5_media_model::model_cmppl_compact_before, & sh5_compact_sh5_media_model::model_cmppl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPPZ_COMPACT, & sh5_compact_sh5_media_model::model_cmppz_compact_before, & sh5_compact_sh5_media_model::model_cmppz_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_CMPSTR_COMPACT, & sh5_compact_sh5_media_model::model_cmpstr_compact_before, & sh5_compact_sh5_media_model::model_cmpstr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DIV0S_COMPACT, & sh5_compact_sh5_media_model::model_div0s_compact_before, & sh5_compact_sh5_media_model::model_div0s_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DIV0U_COMPACT, & sh5_compact_sh5_media_model::model_div0u_compact_before, & sh5_compact_sh5_media_model::model_div0u_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DIV1_COMPACT, & sh5_compact_sh5_media_model::model_div1_compact_before, & sh5_compact_sh5_media_model::model_div1_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DIVU_COMPACT, & sh5_compact_sh5_media_model::model_divu_compact_before, & sh5_compact_sh5_media_model::model_divu_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MULR_COMPACT, & sh5_compact_sh5_media_model::model_mulr_compact_before, & sh5_compact_sh5_media_model::model_mulr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DMULSL_COMPACT, & sh5_compact_sh5_media_model::model_dmulsl_compact_before, & sh5_compact_sh5_media_model::model_dmulsl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DMULUL_COMPACT, & sh5_compact_sh5_media_model::model_dmulul_compact_before, & sh5_compact_sh5_media_model::model_dmulul_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_DT_COMPACT, & sh5_compact_sh5_media_model::model_dt_compact_before, & sh5_compact_sh5_media_model::model_dt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_EXTSB_COMPACT, & sh5_compact_sh5_media_model::model_extsb_compact_before, & sh5_compact_sh5_media_model::model_extsb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_EXTSW_COMPACT, & sh5_compact_sh5_media_model::model_extsw_compact_before, & sh5_compact_sh5_media_model::model_extsw_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_EXTUB_COMPACT, & sh5_compact_sh5_media_model::model_extub_compact_before, & sh5_compact_sh5_media_model::model_extub_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_EXTUW_COMPACT, & sh5_compact_sh5_media_model::model_extuw_compact_before, & sh5_compact_sh5_media_model::model_extuw_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FABS_COMPACT, & sh5_compact_sh5_media_model::model_fabs_compact_before, & sh5_compact_sh5_media_model::model_fabs_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FADD_COMPACT, & sh5_compact_sh5_media_model::model_fadd_compact_before, & sh5_compact_sh5_media_model::model_fadd_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FCMPEQ_COMPACT, & sh5_compact_sh5_media_model::model_fcmpeq_compact_before, & sh5_compact_sh5_media_model::model_fcmpeq_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FCMPGT_COMPACT, & sh5_compact_sh5_media_model::model_fcmpgt_compact_before, & sh5_compact_sh5_media_model::model_fcmpgt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FCNVDS_COMPACT, & sh5_compact_sh5_media_model::model_fcnvds_compact_before, & sh5_compact_sh5_media_model::model_fcnvds_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FCNVSD_COMPACT, & sh5_compact_sh5_media_model::model_fcnvsd_compact_before, & sh5_compact_sh5_media_model::model_fcnvsd_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FDIV_COMPACT, & sh5_compact_sh5_media_model::model_fdiv_compact_before, & sh5_compact_sh5_media_model::model_fdiv_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FIPR_COMPACT, & sh5_compact_sh5_media_model::model_fipr_compact_before, & sh5_compact_sh5_media_model::model_fipr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FLDS_COMPACT, & sh5_compact_sh5_media_model::model_flds_compact_before, & sh5_compact_sh5_media_model::model_flds_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FLDI0_COMPACT, & sh5_compact_sh5_media_model::model_fldi0_compact_before, & sh5_compact_sh5_media_model::model_fldi0_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FLDI1_COMPACT, & sh5_compact_sh5_media_model::model_fldi1_compact_before, & sh5_compact_sh5_media_model::model_fldi1_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FLOAT_COMPACT, & sh5_compact_sh5_media_model::model_float_compact_before, & sh5_compact_sh5_media_model::model_float_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMAC_COMPACT, & sh5_compact_sh5_media_model::model_fmac_compact_before, & sh5_compact_sh5_media_model::model_fmac_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV1_COMPACT, & sh5_compact_sh5_media_model::model_fmov1_compact_before, & sh5_compact_sh5_media_model::model_fmov1_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV2_COMPACT, & sh5_compact_sh5_media_model::model_fmov2_compact_before, & sh5_compact_sh5_media_model::model_fmov2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV3_COMPACT, & sh5_compact_sh5_media_model::model_fmov3_compact_before, & sh5_compact_sh5_media_model::model_fmov3_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV4_COMPACT, & sh5_compact_sh5_media_model::model_fmov4_compact_before, & sh5_compact_sh5_media_model::model_fmov4_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV5_COMPACT, & sh5_compact_sh5_media_model::model_fmov5_compact_before, & sh5_compact_sh5_media_model::model_fmov5_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV6_COMPACT, & sh5_compact_sh5_media_model::model_fmov6_compact_before, & sh5_compact_sh5_media_model::model_fmov6_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV7_COMPACT, & sh5_compact_sh5_media_model::model_fmov7_compact_before, & sh5_compact_sh5_media_model::model_fmov7_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV8_COMPACT, & sh5_compact_sh5_media_model::model_fmov8_compact_before, & sh5_compact_sh5_media_model::model_fmov8_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMOV9_COMPACT, & sh5_compact_sh5_media_model::model_fmov9_compact_before, & sh5_compact_sh5_media_model::model_fmov9_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FMUL_COMPACT, & sh5_compact_sh5_media_model::model_fmul_compact_before, & sh5_compact_sh5_media_model::model_fmul_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FNEG_COMPACT, & sh5_compact_sh5_media_model::model_fneg_compact_before, & sh5_compact_sh5_media_model::model_fneg_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FRCHG_COMPACT, & sh5_compact_sh5_media_model::model_frchg_compact_before, & sh5_compact_sh5_media_model::model_frchg_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FSCHG_COMPACT, & sh5_compact_sh5_media_model::model_fschg_compact_before, & sh5_compact_sh5_media_model::model_fschg_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FSQRT_COMPACT, & sh5_compact_sh5_media_model::model_fsqrt_compact_before, & sh5_compact_sh5_media_model::model_fsqrt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FSTS_COMPACT, & sh5_compact_sh5_media_model::model_fsts_compact_before, & sh5_compact_sh5_media_model::model_fsts_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FSUB_COMPACT, & sh5_compact_sh5_media_model::model_fsub_compact_before, & sh5_compact_sh5_media_model::model_fsub_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FTRC_COMPACT, & sh5_compact_sh5_media_model::model_ftrc_compact_before, & sh5_compact_sh5_media_model::model_ftrc_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_FTRV_COMPACT, & sh5_compact_sh5_media_model::model_ftrv_compact_before, & sh5_compact_sh5_media_model::model_ftrv_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_JMP_COMPACT, & sh5_compact_sh5_media_model::model_jmp_compact_before, & sh5_compact_sh5_media_model::model_jmp_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_JSR_COMPACT, & sh5_compact_sh5_media_model::model_jsr_compact_before, & sh5_compact_sh5_media_model::model_jsr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDC_GBR_COMPACT, & sh5_compact_sh5_media_model::model_ldc_gbr_compact_before, & sh5_compact_sh5_media_model::model_ldc_gbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDC_VBR_COMPACT, & sh5_compact_sh5_media_model::model_ldc_vbr_compact_before, & sh5_compact_sh5_media_model::model_ldc_vbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDC_SR_COMPACT, & sh5_compact_sh5_media_model::model_ldc_sr_compact_before, & sh5_compact_sh5_media_model::model_ldc_sr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDCL_GBR_COMPACT, & sh5_compact_sh5_media_model::model_ldcl_gbr_compact_before, & sh5_compact_sh5_media_model::model_ldcl_gbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDCL_VBR_COMPACT, & sh5_compact_sh5_media_model::model_ldcl_vbr_compact_before, & sh5_compact_sh5_media_model::model_ldcl_vbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDS_FPSCR_COMPACT, & sh5_compact_sh5_media_model::model_lds_fpscr_compact_before, & sh5_compact_sh5_media_model::model_lds_fpscr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDSL_FPSCR_COMPACT, & sh5_compact_sh5_media_model::model_ldsl_fpscr_compact_before, & sh5_compact_sh5_media_model::model_ldsl_fpscr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDS_FPUL_COMPACT, & sh5_compact_sh5_media_model::model_lds_fpul_compact_before, & sh5_compact_sh5_media_model::model_lds_fpul_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDSL_FPUL_COMPACT, & sh5_compact_sh5_media_model::model_ldsl_fpul_compact_before, & sh5_compact_sh5_media_model::model_ldsl_fpul_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDS_MACH_COMPACT, & sh5_compact_sh5_media_model::model_lds_mach_compact_before, & sh5_compact_sh5_media_model::model_lds_mach_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDSL_MACH_COMPACT, & sh5_compact_sh5_media_model::model_ldsl_mach_compact_before, & sh5_compact_sh5_media_model::model_ldsl_mach_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDS_MACL_COMPACT, & sh5_compact_sh5_media_model::model_lds_macl_compact_before, & sh5_compact_sh5_media_model::model_lds_macl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDSL_MACL_COMPACT, & sh5_compact_sh5_media_model::model_ldsl_macl_compact_before, & sh5_compact_sh5_media_model::model_ldsl_macl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDS_PR_COMPACT, & sh5_compact_sh5_media_model::model_lds_pr_compact_before, & sh5_compact_sh5_media_model::model_lds_pr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_LDSL_PR_COMPACT, & sh5_compact_sh5_media_model::model_ldsl_pr_compact_before, & sh5_compact_sh5_media_model::model_ldsl_pr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MACL_COMPACT, & sh5_compact_sh5_media_model::model_macl_compact_before, & sh5_compact_sh5_media_model::model_macl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MACW_COMPACT, & sh5_compact_sh5_media_model::model_macw_compact_before, & sh5_compact_sh5_media_model::model_macw_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOV_COMPACT, & sh5_compact_sh5_media_model::model_mov_compact_before, & sh5_compact_sh5_media_model::model_mov_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVI_COMPACT, & sh5_compact_sh5_media_model::model_movi_compact_before, & sh5_compact_sh5_media_model::model_movi_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVI20_COMPACT, & sh5_compact_sh5_media_model::model_movi20_compact_before, & sh5_compact_sh5_media_model::model_movi20_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB1_COMPACT, & sh5_compact_sh5_media_model::model_movb1_compact_before, & sh5_compact_sh5_media_model::model_movb1_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB2_COMPACT, & sh5_compact_sh5_media_model::model_movb2_compact_before, & sh5_compact_sh5_media_model::model_movb2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB3_COMPACT, & sh5_compact_sh5_media_model::model_movb3_compact_before, & sh5_compact_sh5_media_model::model_movb3_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB4_COMPACT, & sh5_compact_sh5_media_model::model_movb4_compact_before, & sh5_compact_sh5_media_model::model_movb4_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB5_COMPACT, & sh5_compact_sh5_media_model::model_movb5_compact_before, & sh5_compact_sh5_media_model::model_movb5_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB6_COMPACT, & sh5_compact_sh5_media_model::model_movb6_compact_before, & sh5_compact_sh5_media_model::model_movb6_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB7_COMPACT, & sh5_compact_sh5_media_model::model_movb7_compact_before, & sh5_compact_sh5_media_model::model_movb7_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB8_COMPACT, & sh5_compact_sh5_media_model::model_movb8_compact_before, & sh5_compact_sh5_media_model::model_movb8_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB9_COMPACT, & sh5_compact_sh5_media_model::model_movb9_compact_before, & sh5_compact_sh5_media_model::model_movb9_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVB10_COMPACT, & sh5_compact_sh5_media_model::model_movb10_compact_before, & sh5_compact_sh5_media_model::model_movb10_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL1_COMPACT, & sh5_compact_sh5_media_model::model_movl1_compact_before, & sh5_compact_sh5_media_model::model_movl1_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL2_COMPACT, & sh5_compact_sh5_media_model::model_movl2_compact_before, & sh5_compact_sh5_media_model::model_movl2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL3_COMPACT, & sh5_compact_sh5_media_model::model_movl3_compact_before, & sh5_compact_sh5_media_model::model_movl3_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL4_COMPACT, & sh5_compact_sh5_media_model::model_movl4_compact_before, & sh5_compact_sh5_media_model::model_movl4_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL5_COMPACT, & sh5_compact_sh5_media_model::model_movl5_compact_before, & sh5_compact_sh5_media_model::model_movl5_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL6_COMPACT, & sh5_compact_sh5_media_model::model_movl6_compact_before, & sh5_compact_sh5_media_model::model_movl6_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL7_COMPACT, & sh5_compact_sh5_media_model::model_movl7_compact_before, & sh5_compact_sh5_media_model::model_movl7_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL8_COMPACT, & sh5_compact_sh5_media_model::model_movl8_compact_before, & sh5_compact_sh5_media_model::model_movl8_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL9_COMPACT, & sh5_compact_sh5_media_model::model_movl9_compact_before, & sh5_compact_sh5_media_model::model_movl9_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL10_COMPACT, & sh5_compact_sh5_media_model::model_movl10_compact_before, & sh5_compact_sh5_media_model::model_movl10_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL11_COMPACT, & sh5_compact_sh5_media_model::model_movl11_compact_before, & sh5_compact_sh5_media_model::model_movl11_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL12_COMPACT, & sh5_compact_sh5_media_model::model_movl12_compact_before, & sh5_compact_sh5_media_model::model_movl12_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVL13_COMPACT, & sh5_compact_sh5_media_model::model_movl13_compact_before, & sh5_compact_sh5_media_model::model_movl13_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW1_COMPACT, & sh5_compact_sh5_media_model::model_movw1_compact_before, & sh5_compact_sh5_media_model::model_movw1_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW2_COMPACT, & sh5_compact_sh5_media_model::model_movw2_compact_before, & sh5_compact_sh5_media_model::model_movw2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW3_COMPACT, & sh5_compact_sh5_media_model::model_movw3_compact_before, & sh5_compact_sh5_media_model::model_movw3_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW4_COMPACT, & sh5_compact_sh5_media_model::model_movw4_compact_before, & sh5_compact_sh5_media_model::model_movw4_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW5_COMPACT, & sh5_compact_sh5_media_model::model_movw5_compact_before, & sh5_compact_sh5_media_model::model_movw5_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW6_COMPACT, & sh5_compact_sh5_media_model::model_movw6_compact_before, & sh5_compact_sh5_media_model::model_movw6_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW7_COMPACT, & sh5_compact_sh5_media_model::model_movw7_compact_before, & sh5_compact_sh5_media_model::model_movw7_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW8_COMPACT, & sh5_compact_sh5_media_model::model_movw8_compact_before, & sh5_compact_sh5_media_model::model_movw8_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW9_COMPACT, & sh5_compact_sh5_media_model::model_movw9_compact_before, & sh5_compact_sh5_media_model::model_movw9_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW10_COMPACT, & sh5_compact_sh5_media_model::model_movw10_compact_before, & sh5_compact_sh5_media_model::model_movw10_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVW11_COMPACT, & sh5_compact_sh5_media_model::model_movw11_compact_before, & sh5_compact_sh5_media_model::model_movw11_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVA_COMPACT, & sh5_compact_sh5_media_model::model_mova_compact_before, & sh5_compact_sh5_media_model::model_mova_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVCAL_COMPACT, & sh5_compact_sh5_media_model::model_movcal_compact_before, & sh5_compact_sh5_media_model::model_movcal_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVCOL_COMPACT, & sh5_compact_sh5_media_model::model_movcol_compact_before, & sh5_compact_sh5_media_model::model_movcol_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVT_COMPACT, & sh5_compact_sh5_media_model::model_movt_compact_before, & sh5_compact_sh5_media_model::model_movt_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVUAL_COMPACT, & sh5_compact_sh5_media_model::model_movual_compact_before, & sh5_compact_sh5_media_model::model_movual_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MOVUAL2_COMPACT, & sh5_compact_sh5_media_model::model_movual2_compact_before, & sh5_compact_sh5_media_model::model_movual2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MULL_COMPACT, & sh5_compact_sh5_media_model::model_mull_compact_before, & sh5_compact_sh5_media_model::model_mull_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MULSW_COMPACT, & sh5_compact_sh5_media_model::model_mulsw_compact_before, & sh5_compact_sh5_media_model::model_mulsw_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_MULUW_COMPACT, & sh5_compact_sh5_media_model::model_muluw_compact_before, & sh5_compact_sh5_media_model::model_muluw_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_NEG_COMPACT, & sh5_compact_sh5_media_model::model_neg_compact_before, & sh5_compact_sh5_media_model::model_neg_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_NEGC_COMPACT, & sh5_compact_sh5_media_model::model_negc_compact_before, & sh5_compact_sh5_media_model::model_negc_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_NOP_COMPACT, & sh5_compact_sh5_media_model::model_nop_compact_before, & sh5_compact_sh5_media_model::model_nop_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_NOT_COMPACT, & sh5_compact_sh5_media_model::model_not_compact_before, & sh5_compact_sh5_media_model::model_not_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_OCBI_COMPACT, & sh5_compact_sh5_media_model::model_ocbi_compact_before, & sh5_compact_sh5_media_model::model_ocbi_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_OCBP_COMPACT, & sh5_compact_sh5_media_model::model_ocbp_compact_before, & sh5_compact_sh5_media_model::model_ocbp_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_OCBWB_COMPACT, & sh5_compact_sh5_media_model::model_ocbwb_compact_before, & sh5_compact_sh5_media_model::model_ocbwb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_OR_COMPACT, & sh5_compact_sh5_media_model::model_or_compact_before, & sh5_compact_sh5_media_model::model_or_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ORI_COMPACT, & sh5_compact_sh5_media_model::model_ori_compact_before, & sh5_compact_sh5_media_model::model_ori_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ORB_COMPACT, & sh5_compact_sh5_media_model::model_orb_compact_before, & sh5_compact_sh5_media_model::model_orb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_PREF_COMPACT, & sh5_compact_sh5_media_model::model_pref_compact_before, & sh5_compact_sh5_media_model::model_pref_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ROTCL_COMPACT, & sh5_compact_sh5_media_model::model_rotcl_compact_before, & sh5_compact_sh5_media_model::model_rotcl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ROTCR_COMPACT, & sh5_compact_sh5_media_model::model_rotcr_compact_before, & sh5_compact_sh5_media_model::model_rotcr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ROTL_COMPACT, & sh5_compact_sh5_media_model::model_rotl_compact_before, & sh5_compact_sh5_media_model::model_rotl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_ROTR_COMPACT, & sh5_compact_sh5_media_model::model_rotr_compact_before, & sh5_compact_sh5_media_model::model_rotr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_RTS_COMPACT, & sh5_compact_sh5_media_model::model_rts_compact_before, & sh5_compact_sh5_media_model::model_rts_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SETS_COMPACT, & sh5_compact_sh5_media_model::model_sets_compact_before, & sh5_compact_sh5_media_model::model_sets_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SETT_COMPACT, & sh5_compact_sh5_media_model::model_sett_compact_before, & sh5_compact_sh5_media_model::model_sett_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHAD_COMPACT, & sh5_compact_sh5_media_model::model_shad_compact_before, & sh5_compact_sh5_media_model::model_shad_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHAL_COMPACT, & sh5_compact_sh5_media_model::model_shal_compact_before, & sh5_compact_sh5_media_model::model_shal_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHAR_COMPACT, & sh5_compact_sh5_media_model::model_shar_compact_before, & sh5_compact_sh5_media_model::model_shar_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLD_COMPACT, & sh5_compact_sh5_media_model::model_shld_compact_before, & sh5_compact_sh5_media_model::model_shld_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLL_COMPACT, & sh5_compact_sh5_media_model::model_shll_compact_before, & sh5_compact_sh5_media_model::model_shll_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLL2_COMPACT, & sh5_compact_sh5_media_model::model_shll2_compact_before, & sh5_compact_sh5_media_model::model_shll2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLL8_COMPACT, & sh5_compact_sh5_media_model::model_shll8_compact_before, & sh5_compact_sh5_media_model::model_shll8_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLL16_COMPACT, & sh5_compact_sh5_media_model::model_shll16_compact_before, & sh5_compact_sh5_media_model::model_shll16_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLR_COMPACT, & sh5_compact_sh5_media_model::model_shlr_compact_before, & sh5_compact_sh5_media_model::model_shlr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLR2_COMPACT, & sh5_compact_sh5_media_model::model_shlr2_compact_before, & sh5_compact_sh5_media_model::model_shlr2_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLR8_COMPACT, & sh5_compact_sh5_media_model::model_shlr8_compact_before, & sh5_compact_sh5_media_model::model_shlr8_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SHLR16_COMPACT, & sh5_compact_sh5_media_model::model_shlr16_compact_before, & sh5_compact_sh5_media_model::model_shlr16_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STC_GBR_COMPACT, & sh5_compact_sh5_media_model::model_stc_gbr_compact_before, & sh5_compact_sh5_media_model::model_stc_gbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STC_VBR_COMPACT, & sh5_compact_sh5_media_model::model_stc_vbr_compact_before, & sh5_compact_sh5_media_model::model_stc_vbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STCL_GBR_COMPACT, & sh5_compact_sh5_media_model::model_stcl_gbr_compact_before, & sh5_compact_sh5_media_model::model_stcl_gbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STCL_VBR_COMPACT, & sh5_compact_sh5_media_model::model_stcl_vbr_compact_before, & sh5_compact_sh5_media_model::model_stcl_vbr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STS_FPSCR_COMPACT, & sh5_compact_sh5_media_model::model_sts_fpscr_compact_before, & sh5_compact_sh5_media_model::model_sts_fpscr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STSL_FPSCR_COMPACT, & sh5_compact_sh5_media_model::model_stsl_fpscr_compact_before, & sh5_compact_sh5_media_model::model_stsl_fpscr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STS_FPUL_COMPACT, & sh5_compact_sh5_media_model::model_sts_fpul_compact_before, & sh5_compact_sh5_media_model::model_sts_fpul_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STSL_FPUL_COMPACT, & sh5_compact_sh5_media_model::model_stsl_fpul_compact_before, & sh5_compact_sh5_media_model::model_stsl_fpul_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STS_MACH_COMPACT, & sh5_compact_sh5_media_model::model_sts_mach_compact_before, & sh5_compact_sh5_media_model::model_sts_mach_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STSL_MACH_COMPACT, & sh5_compact_sh5_media_model::model_stsl_mach_compact_before, & sh5_compact_sh5_media_model::model_stsl_mach_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STS_MACL_COMPACT, & sh5_compact_sh5_media_model::model_sts_macl_compact_before, & sh5_compact_sh5_media_model::model_sts_macl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STSL_MACL_COMPACT, & sh5_compact_sh5_media_model::model_stsl_macl_compact_before, & sh5_compact_sh5_media_model::model_stsl_macl_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STS_PR_COMPACT, & sh5_compact_sh5_media_model::model_sts_pr_compact_before, & sh5_compact_sh5_media_model::model_sts_pr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_STSL_PR_COMPACT, & sh5_compact_sh5_media_model::model_stsl_pr_compact_before, & sh5_compact_sh5_media_model::model_stsl_pr_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SUB_COMPACT, & sh5_compact_sh5_media_model::model_sub_compact_before, & sh5_compact_sh5_media_model::model_sub_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SUBC_COMPACT, & sh5_compact_sh5_media_model::model_subc_compact_before, & sh5_compact_sh5_media_model::model_subc_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SUBV_COMPACT, & sh5_compact_sh5_media_model::model_subv_compact_before, & sh5_compact_sh5_media_model::model_subv_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SWAPB_COMPACT, & sh5_compact_sh5_media_model::model_swapb_compact_before, & sh5_compact_sh5_media_model::model_swapb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_SWAPW_COMPACT, & sh5_compact_sh5_media_model::model_swapw_compact_before, & sh5_compact_sh5_media_model::model_swapw_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_TASB_COMPACT, & sh5_compact_sh5_media_model::model_tasb_compact_before, & sh5_compact_sh5_media_model::model_tasb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_TRAPA_COMPACT, & sh5_compact_sh5_media_model::model_trapa_compact_before, & sh5_compact_sh5_media_model::model_trapa_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_TST_COMPACT, & sh5_compact_sh5_media_model::model_tst_compact_before, & sh5_compact_sh5_media_model::model_tst_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_TSTI_COMPACT, & sh5_compact_sh5_media_model::model_tsti_compact_before, & sh5_compact_sh5_media_model::model_tsti_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_TSTB_COMPACT, & sh5_compact_sh5_media_model::model_tstb_compact_before, & sh5_compact_sh5_media_model::model_tstb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_XOR_COMPACT, & sh5_compact_sh5_media_model::model_xor_compact_before, & sh5_compact_sh5_media_model::model_xor_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_XORI_COMPACT, & sh5_compact_sh5_media_model::model_xori_compact_before, & sh5_compact_sh5_media_model::model_xori_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_XORB_COMPACT, & sh5_compact_sh5_media_model::model_xorb_compact_before, & sh5_compact_sh5_media_model::model_xorb_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_COMPACT_INSN_XTRCT_COMPACT, & sh5_compact_sh5_media_model::model_xtrct_compact_before, & sh5_compact_sh5_media_model::model_xtrct_compact_after, { { sh5_compact_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
};

