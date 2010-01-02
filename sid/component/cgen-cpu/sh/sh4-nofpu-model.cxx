/* Simulator model support for sh4_nofpu.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh4_nofpu.h"

using namespace sh4_nofpu; // FIXME: namespace organization still wip

/* The profiling data is recorded here, but is accessed via the profiling
   mechanism.  After all, this is information for profiling.  */

/* Model handlers for each insn.  */

sh4_nofpu_sh4_nofpu_model::sh4_nofpu_sh4_nofpu_model (sh4_nofpu_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
sh4_nofpu_sh4_nofpu_model::model_add_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_add_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_addi_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_addi_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_addc_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_addc_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_addv_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_addv_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_and_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_and_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_andi_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_andi_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_andb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_andb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bf_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bf_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bfs_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bfs_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bra_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_branch_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_bra_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_braf_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_braf_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bsr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_branch_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_bsr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bsrf_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bsrf_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bt_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bt_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bts_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_bts_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_clrmac_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_clrmac_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_clrs_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_clrs_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_clrt_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_clrt_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpeq_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpeq_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpeqi_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpeqi_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpge_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpge_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpgt_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpgt_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmphi_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmphi_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmphs_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmphs_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmppl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmppl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmppz_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmppz_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpstr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_cmpstr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_div0s_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_div0s_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_div0u_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_div0u_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_div1_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_div1_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_divu_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_divu_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mulr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mulr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_dmulsl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_dmulsl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_dmulul_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_dmulul_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_dt_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_dt_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extsb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extsb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extsw_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extsw_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extub_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extub_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extuw_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_extuw_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_frchg_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_frchg_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_fschg_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_fschg_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_jmp_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_jmp_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_jmp_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_jsr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_jsr_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_jsr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldc_gbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldc_gbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldc_vbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldc_vbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldc_sr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldc_sr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldcl_gbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldcl_gbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldcl_vbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldcl_vbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_lds_mach_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_lds_mach_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldsl_mach_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldsl_mach_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_lds_macl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_lds_macl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldsl_macl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldsl_macl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_lds_pr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_lds_pr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldsl_pr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ldsl_pr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_macl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_macl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_macw_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_macw_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mov_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mov_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movi_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_movi_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_movi20_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_movi20_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_movb1_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb1_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb2_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb2_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb3_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb3_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb4_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb4_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb5_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb5_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb6_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb6_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb7_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb7_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb8_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb8_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb9_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb9_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb10_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movb10_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl1_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl1_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl2_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl2_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl3_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl3_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl4_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl4_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl5_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl5_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl6_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl6_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl7_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl7_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl8_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl8_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl9_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl9_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl10_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl10_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl11_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl11_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl12_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl12_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl13_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movl13_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw1_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw1_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw2_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw2_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw3_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw3_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw4_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw4_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw5_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw5_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw6_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw6_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw7_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw7_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw8_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw8_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw9_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw9_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw10_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw10_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw11_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movw11_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mova_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_mova_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_movcal_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movcal_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movt_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_movt_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mull_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mull_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mulsw_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_mulsw_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_muluw_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_muluw_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_neg_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_neg_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_negc_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_negc_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_nop_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_nop_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_not_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_not_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ocbi_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ocbi_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ocbp_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ocbp_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ocbwb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ocbwb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_or_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_or_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ori_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_ori_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_orb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_orb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_pref_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_pref_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotcl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotcl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotcr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotcr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rotr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_rts_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_jmp_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_rts_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sets_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sets_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sett_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sett_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shad_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shad_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shal_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shal_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shar_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shar_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shld_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shld_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll2_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll2_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll8_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll8_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll16_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shll16_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr2_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr2_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr8_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr8_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr16_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_shlr16_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stc_gbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_stc_gbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_stc_vbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_stc_vbr_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_stc_vbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stcl_gbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stcl_gbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stcl_vbr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stcl_vbr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sts_mach_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sts_mach_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stsl_mach_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stsl_mach_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sts_macl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sts_macl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stsl_macl_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stsl_macl_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sts_pr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sts_pr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stsl_pr_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_stsl_pr_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sub_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_sub_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_subc_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_subc_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_subv_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_subv_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_swapb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_swapb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_swapw_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_swapw_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tasb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tasb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_trapa_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_trap_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh4_nofpu_sh4_nofpu_model::model_trapa_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tst_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tst_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tsti_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tsti_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tstb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_tstb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xor_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xor_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xori_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xori_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xorb_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xorb_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xtrct_compact_before (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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
sh4_nofpu_sh4_nofpu_model::model_xtrct_compact_after (sh4_nofpu_cpu *current_cpu, sh4_nofpu_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  const sh4_nofpu_scache* abuf = sem;
  const sh4_nofpu_idesc* idesc = abuf->idesc;
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

/* We assume UNIT_NONE == 0 because the tables don't always terminate
   entries with it.  */

/* Model timing data for `sh4-nofpu'.  */

const sh4_nofpu_sh4_nofpu_model::insn_timing sh4_nofpu_sh4_nofpu_model::timing[] = {
  { SH4_NOFPU_INSN_X_INVALID, 0, 0, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ADD_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_add_compact_before, & sh4_nofpu_sh4_nofpu_model::model_add_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ADDI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_addi_compact_before, & sh4_nofpu_sh4_nofpu_model::model_addi_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ADDC_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_addc_compact_before, & sh4_nofpu_sh4_nofpu_model::model_addc_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_ADDV_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_addv_compact_before, & sh4_nofpu_sh4_nofpu_model::model_addv_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_AND_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_and_compact_before, & sh4_nofpu_sh4_nofpu_model::model_and_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ANDI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_andi_compact_before, & sh4_nofpu_sh4_nofpu_model::model_andi_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ANDB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_andb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_andb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOGIC_B, 0, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_BF_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bf_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bf_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_BRANCH, 0, 3 } } },
  { SH4_NOFPU_INSN_BFS_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bfs_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bfs_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH4_NOFPU_INSN_BRA_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bra_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bra_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH4_NOFPU_INSN_BRAF_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_braf_compact_before, & sh4_nofpu_sh4_nofpu_model::model_braf_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_JMP, 0, 2 } } },
  { SH4_NOFPU_INSN_BSR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bsr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bsr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH4_NOFPU_INSN_BSRF_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bsrf_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bsrf_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_JSR, 0, 2 } } },
  { SH4_NOFPU_INSN_BT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bt_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bt_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_BRANCH, 0, 3 } } },
  { SH4_NOFPU_INSN_BTS_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_bts_compact_before, & sh4_nofpu_sh4_nofpu_model::model_bts_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_BRANCH, 0, 2 } } },
  { SH4_NOFPU_INSN_CLRMAC_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_clrmac_compact_before, & sh4_nofpu_sh4_nofpu_model::model_clrmac_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_MAC, 0, 0 } } },
  { SH4_NOFPU_INSN_CLRS_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_clrs_compact_before, & sh4_nofpu_sh4_nofpu_model::model_clrs_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CLRT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_clrt_compact_before, & sh4_nofpu_sh4_nofpu_model::model_clrt_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPEQ_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmpeq_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmpeq_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPEQI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmpeqi_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmpeqi_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPGE_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmpge_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmpge_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPGT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmpgt_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmpgt_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPHI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmphi_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmphi_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPHS_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmphs_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmphs_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPPL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmppl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmppl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPPZ_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmppz_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmppz_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_CMPSTR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_cmpstr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_cmpstr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_DIV0S_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_div0s_compact_before, & sh4_nofpu_sh4_nofpu_model::model_div0s_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_DIV0U_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_div0u_compact_before, & sh4_nofpu_sh4_nofpu_model::model_div0u_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_DIV1_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_div1_compact_before, & sh4_nofpu_sh4_nofpu_model::model_div1_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_DIVU_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_divu_compact_before, & sh4_nofpu_sh4_nofpu_model::model_divu_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 34 } } },
  { SH4_NOFPU_INSN_MULR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_mulr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_mulr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULR, 1, 2 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULR_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_DMULSL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_dmulsl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_dmulsl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_DMUL, 1, 2 } } },
  { SH4_NOFPU_INSN_DMULUL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_dmulul_compact_before, & sh4_nofpu_sh4_nofpu_model::model_dmulul_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_DMUL, 1, 2 } } },
  { SH4_NOFPU_INSN_DT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_dt_compact_before, & sh4_nofpu_sh4_nofpu_model::model_dt_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_EXTSB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_extsb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_extsb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_EXTSW_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_extsw_compact_before, & sh4_nofpu_sh4_nofpu_model::model_extsw_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_EXTUB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_extub_compact_before, & sh4_nofpu_sh4_nofpu_model::model_extub_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_EXTUW_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_extuw_compact_before, & sh4_nofpu_sh4_nofpu_model::model_extuw_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_FRCHG_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_frchg_compact_before, & sh4_nofpu_sh4_nofpu_model::model_frchg_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_FSCHG_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_fschg_compact_before, & sh4_nofpu_sh4_nofpu_model::model_fschg_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_JMP_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_jmp_compact_before, & sh4_nofpu_sh4_nofpu_model::model_jmp_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_JMP, 0, 2 } } },
  { SH4_NOFPU_INSN_JSR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_jsr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_jsr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_JSR, 0, 2 } } },
  { SH4_NOFPU_INSN_LDC_GBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldc_gbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldc_gbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDC_GBR, 0, 1 } } },
  { SH4_NOFPU_INSN_LDC_VBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldc_vbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldc_vbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_LDC_SR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldc_sr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldc_sr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDC_SR, 0, 1 } } },
  { SH4_NOFPU_INSN_LDCL_GBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldcl_gbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldcl_gbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDCL, 0, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GBR, 0, 0 } } },
  { SH4_NOFPU_INSN_LDCL_VBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldcl_vbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldcl_vbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDCL_VBR, 0, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_VBR, 0, 0 } } },
  { SH4_NOFPU_INSN_LDS_MACH_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_lds_mach_compact_before, & sh4_nofpu_sh4_nofpu_model::model_lds_mach_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_MAC, 0, 0 } } },
  { SH4_NOFPU_INSN_LDSL_MACH_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldsl_mach_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldsl_mach_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_MAC, 0, 0 } } },
  { SH4_NOFPU_INSN_LDS_MACL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_lds_macl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_lds_macl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_MAC, 0, 0 } } },
  { SH4_NOFPU_INSN_LDSL_MACL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldsl_macl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldsl_macl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_MAC, 0, 0 } } },
  { SH4_NOFPU_INSN_LDS_PR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_lds_pr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_lds_pr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDS_PR, 0, 1 } } },
  { SH4_NOFPU_INSN_LDSL_PR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ldsl_pr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ldsl_pr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDS_PR, 0, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_PR, 0, 0 } } },
  { SH4_NOFPU_INSN_MACL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_macl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_macl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MACL, 1, 2 } } },
  { SH4_NOFPU_INSN_MACW_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_macw_compact_before, & sh4_nofpu_sh4_nofpu_model::model_macw_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MACW, 1, 2 } } },
  { SH4_NOFPU_INSN_MOV_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_mov_compact_before, & sh4_nofpu_sh4_nofpu_model::model_mov_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_MOVI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movi_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movi_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_MOVI20_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movi20_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movi20_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_MOVB1_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb1_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb1_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB2_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb2_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb2_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB3_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb3_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb3_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB4_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb4_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb4_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SX, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB5_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb5_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb5_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB6_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb6_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb6_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB7_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb7_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb7_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB8_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb8_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb8_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB9_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb9_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb9_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVB10_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movb10_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movb10_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL1_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl1_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl1_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL2_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl2_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl2_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL3_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl3_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl3_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL4_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl4_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl4_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SX, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL5_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl5_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl5_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL6_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl6_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl6_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL7_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl7_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl7_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL8_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl8_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl8_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL9_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl9_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl9_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL10_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl10_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl10_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL11_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl11_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl11_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL12_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl12_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl12_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVL13_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movl13_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movl13_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW1_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw1_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw1_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW2_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw2_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw2_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW3_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw3_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw3_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW4_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw4_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw4_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SX, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW5_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw5_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw5_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW6_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw6_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw6_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW7_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw7_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw7_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW8_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw8_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw8_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW9_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw9_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw9_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW10_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw10_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw10_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVW11_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movw11_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movw11_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH4_NOFPU_INSN_MOVA_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_mova_compact_before, & sh4_nofpu_sh4_nofpu_model::model_mova_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_MOVCAL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movcal_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movcal_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_OCB, 0, 6 } } },
  { SH4_NOFPU_INSN_MOVT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_movt_compact_before, & sh4_nofpu_sh4_nofpu_model::model_movt_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_MULL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_mull_compact_before, & sh4_nofpu_sh4_nofpu_model::model_mull_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULL, 1, 2 } } },
  { SH4_NOFPU_INSN_MULSW_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_mulsw_compact_before, & sh4_nofpu_sh4_nofpu_model::model_mulsw_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULSW, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULTIPLY, 1, 2 } } },
  { SH4_NOFPU_INSN_MULUW_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_muluw_compact_before, & sh4_nofpu_sh4_nofpu_model::model_muluw_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULSW, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MULTIPLY, 1, 2 } } },
  { SH4_NOFPU_INSN_NEG_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_neg_compact_before, & sh4_nofpu_sh4_nofpu_model::model_neg_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_NEGC_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_negc_compact_before, & sh4_nofpu_sh4_nofpu_model::model_negc_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_NOP_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_nop_compact_before, & sh4_nofpu_sh4_nofpu_model::model_nop_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_NOT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_not_compact_before, & sh4_nofpu_sh4_nofpu_model::model_not_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_OCBI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ocbi_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ocbi_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_OCB, 0, 1 } } },
  { SH4_NOFPU_INSN_OCBP_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ocbp_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ocbp_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_OCB, 0, 4 } } },
  { SH4_NOFPU_INSN_OCBWB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ocbwb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ocbwb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_OCB, 0, 4 } } },
  { SH4_NOFPU_INSN_OR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_or_compact_before, & sh4_nofpu_sh4_nofpu_model::model_or_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ORI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_ori_compact_before, & sh4_nofpu_sh4_nofpu_model::model_ori_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_ORB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_orb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_orb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOGIC_B, 0, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_PREF_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_pref_compact_before, & sh4_nofpu_sh4_nofpu_model::model_pref_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_ROTCL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_rotcl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_rotcl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_ROTCR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_rotcr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_rotcr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_ROTL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_rotl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_rotl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_ROTR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_rotr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_rotr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_RTS_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_rts_compact_before, & sh4_nofpu_sh4_nofpu_model::model_rts_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_JMP, 0, 2 } } },
  { SH4_NOFPU_INSN_SETS_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_sets_compact_before, & sh4_nofpu_sh4_nofpu_model::model_sets_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SETT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_sett_compact_before, & sh4_nofpu_sh4_nofpu_model::model_sett_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHAD_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shad_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shad_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHAL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shal_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shal_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHAR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shar_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shar_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLD_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shld_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shld_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shll_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shll_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLL2_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shll2_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shll2_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLL8_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shll8_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shll8_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLL16_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shll16_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shll16_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shlr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shlr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLR2_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shlr2_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shlr2_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLR8_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shlr8_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shlr8_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SHLR16_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_shlr16_compact_before, & sh4_nofpu_sh4_nofpu_model::model_shlr16_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_STC_GBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stc_gbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stc_gbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_STC_VBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stc_vbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stc_vbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_STC_VBR, 0, 1 } } },
  { SH4_NOFPU_INSN_STCL_GBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stcl_gbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stcl_gbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDCL, 0, 2 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_STCL_VBR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stcl_vbr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stcl_vbr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LDCL, 0, 2 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_STS_MACH_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_sts_mach_compact_before, & sh4_nofpu_sh4_nofpu_model::model_sts_mach_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_STSL_MACH_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stsl_mach_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stsl_mach_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_STS_MACL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_sts_macl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_sts_macl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_STSL_MACL_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stsl_macl_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stsl_macl_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_MULTIPLY_RESULT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_WRITE_BACK, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_STS_PR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_sts_pr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_sts_pr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_PR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_STS_PR, 0, 1 } } },
  { SH4_NOFPU_INSN_STSL_PR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_stsl_pr_compact_before, & sh4_nofpu_sh4_nofpu_model::model_stsl_pr_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_PR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_STS_PR, 0, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_SUB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_sub_compact_before, & sh4_nofpu_sh4_nofpu_model::model_sub_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_SUBC_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_subc_compact_before, & sh4_nofpu_sh4_nofpu_model::model_subc_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_SUBV_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_subv_compact_before, & sh4_nofpu_sh4_nofpu_model::model_subv_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_SWAPB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_swapb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_swapb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_SWAPW_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_swapw_compact_before, & sh4_nofpu_sh4_nofpu_model::model_swapw_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
  { SH4_NOFPU_INSN_TASB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_tasb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_tasb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_TAS, 1, 4 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_TRAPA_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_trapa_compact_before, & sh4_nofpu_sh4_nofpu_model::model_trapa_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_TRAP, 0, 8 } } },
  { SH4_NOFPU_INSN_TST_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_tst_compact_before, & sh4_nofpu_sh4_nofpu_model::model_tst_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_TSTI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_tsti_compact_before, & sh4_nofpu_sh4_nofpu_model::model_tsti_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 } } },
  { SH4_NOFPU_INSN_TSTB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_tstb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_tstb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_TBIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SX, 1, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SET_SR_BIT, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_XOR_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_xor_compact_before, & sh4_nofpu_sh4_nofpu_model::model_xor_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_XORI_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_xori_compact_before, & sh4_nofpu_sh4_nofpu_model::model_xori_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 } } },
  { SH4_NOFPU_INSN_XORB_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_xorb_compact_before, & sh4_nofpu_sh4_nofpu_model::model_xorb_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_LOGIC_B, 0, 3 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_MEMORY_ACCESS, 0, 0 } } },
  { SH4_NOFPU_INSN_XTRCT_COMPACT, & sh4_nofpu_sh4_nofpu_model::model_xtrct_compact_before, & sh4_nofpu_sh4_nofpu_model::model_xtrct_compact_after, { { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_USE_GR, 0, 0 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_EXEC, 1, 1 }, { sh4_nofpu_sh4_nofpu_model::UNIT_U_SHIFT, 0, 0 } } },
};

