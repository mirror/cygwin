/* Simulator model support for sh5_media.

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

sh5_media_sh5_model::sh5_media_sh5_model (sh5_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
sh5_media_sh5_model::model_add_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_add_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addzl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_addzl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_alloco_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_alloco_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_and_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_and_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_andc_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_andc_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_andi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_andi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_beq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_beq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_beqi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_beqi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bge_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bge_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bgeu_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bgeu_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_blink_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_blink_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bne_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bne_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bnei_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_bnei_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_brk_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_brk_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_byterev_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_byterev_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmpeq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmpeq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmpgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmpgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmpgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmpgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmveq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmveq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmvne_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_cmvne_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fabsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fabsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fabss_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fabss_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_faddd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_faddd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fadds_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fadds_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpeqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpeqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpeqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpeqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpged_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpged_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpges_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpges_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpgtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpgtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpgts_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpgts_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpund_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpund_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpuns_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcmpuns_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcnvds_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcnvds_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcnvsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fcnvsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fdivd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fdivd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fdivs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fdivs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fgetscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fgetscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fiprs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fiprs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fiprs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fiprs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_flds_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_flds_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fldxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatld_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatld_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatls_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatls_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_floatqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmacs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmacs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovdq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovdq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovls_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovls_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmovsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmuld_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmuld_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmuls_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fmuls_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fnegd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fnegd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fnegs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fnegs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fputscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fputscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsqrtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsqrtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsqrts_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsqrts_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsts_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsts_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fstxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsubd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsubd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsubs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_fsubs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrcsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrvs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrvs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ftrvs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrvs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_getcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_getcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_getcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_getcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_gettr_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_gettr_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_icbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_icbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_lduw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_lduw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldhiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldhiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxuw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxuw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ldxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mabsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mabsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mabsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mabsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_maddsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpeqb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpeqb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpeql_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpeql_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpeqw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpeqw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpgtl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpgtl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpgtub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpgtub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpgtw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmpgtw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmv_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcmv_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcnvslw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcnvslw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcnvswb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcnvswb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcnvswub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mcnvswub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr1_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr1_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr2_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr2_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr3_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr3_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr4_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr4_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr5_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr5_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr6_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr6_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr7_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mextr7_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmacfxwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmacfxwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmacnfx_wl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmacnfx_wl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmull_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmull_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulfxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulfxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulfxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulfxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulfxrpw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulfxrpw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulhiwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulhiwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmullowl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmullowl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulsumwq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mmulsumwq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_movi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_movi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mpermw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mpermw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msadubq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msadubq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshaldsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshaldsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshaldsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshaldsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshardw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshardw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshardsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshardsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshfhib_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshfhib_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshfhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshfhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshfhiw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshfhiw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshflob_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshflob_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshflol_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshflol_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshflow_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshflow_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlrdw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mshlrdw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_msubsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mulsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mulsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mulul_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_mulul_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_nop_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_nop_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_nsb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_nsb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ocbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ocbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ocbp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ocbp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ocbwb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ocbwb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_or_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_or_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ori_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ori_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_prefi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_prefi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_pta_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_pta_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ptabs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ptabs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ptb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ptb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ptrel_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_ptrel_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_putcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_putcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_putcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_putcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_rte_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_rte_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shard_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shard_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shari_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shari_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sharil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sharil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlld_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlld_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlli_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlli_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shllil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shllil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlrd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlrd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlri_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlri_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlril_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shlril_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shori_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_shori_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sleep_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sleep_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stb.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stb.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sthil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sthil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sthiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sthiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_stxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_sub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_subl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_subl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_swapq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_swapq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_synci_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_synci_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_synco_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_synco_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_trapa_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_trapa_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_xor_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_xor_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_xori_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_model::model_xori_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

sh5_media_sh5_media_model::sh5_media_sh5_media_model (sh5_cpu *cpu)
  : cgen_model (cpu)
{
}

UINT
sh5_media_sh5_media_model::model_add_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_add_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_addl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_addl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_addi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_addi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_addil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_addil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_addzl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_addzl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_alloco_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_alloco_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_and_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_and_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_andc_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_andc_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_andi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_andi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_beq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 3, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_beq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 3, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_beqi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 2, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_beqi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 2, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bge_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 3, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bge_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 3, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bgeu_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 3, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bgeu_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 3, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 3, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 3, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 3, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 3, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_blink_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_targetreg = -1;
    in_targetreg = FLD (in_trb);
    cycles += model_u_blink_before (current_cpu, idesc, 0, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_blink_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_targetreg = -1;
    in_targetreg = FLD (in_trb);
    referenced |= 1 << 1;
    cycles += model_u_blink_after (current_cpu, idesc, 0, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bne_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 3, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bne_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 3, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bnei_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    cycles += model_u_cond_branch_before (current_cpu, idesc, 2, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_bnei_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT in_targetreg = -1;
    in_targetreg = FLD (in_tra);
    if (insn_referenced & (1 << 4)) referenced |= 1 << 1;
    cycles += model_u_cond_branch_after (current_cpu, idesc, 2, referenced, in_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_brk_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_brk_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_byterev_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_byterev_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_cmpeq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmpeq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmpgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmpgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmpgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmpgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmveq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmveq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmvne_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_cmvne_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fabsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fabsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fabss_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fabss_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_faddd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_faddd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fadds_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fadds_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpeqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpeqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpeqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpeqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpged_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpged_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpges_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpges_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpgtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpgtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpgts_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpgts_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpund_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpund_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpuns_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcmpuns_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcnvds_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcnvds_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcnvsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fcnvsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fdivd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_fdivd_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fdivd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_fdivd_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fdivs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_fdiv_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fdivs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_fdiv_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fgetscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 1, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 5, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fgetscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fiprs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fiprs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fvg);
    cycles += model_u_use_fv_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fvh);
    cycles += model_u_use_fv_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fiprs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fiprs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fvg);
    cycles += model_u_use_fv_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fvh);
    cycles += model_u_use_fv_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_flds_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_flds_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_dr_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fp_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fv_before (current_cpu, idesc, 7, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_mtrx_before (current_cpu, idesc, 8, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_dr_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fp_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_fv_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_load_mtrx_after (current_cpu, idesc, 8, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_dr_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fp_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fv_before (current_cpu, idesc, 7, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_mtrx_before (current_cpu, idesc, 8, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_dr_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fp_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_fv_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fpf);
    cycles += model_u_load_mtrx_after (current_cpu, idesc, 8, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_dr_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fp_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fv_before (current_cpu, idesc, 7, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_mtrx_before (current_cpu, idesc, 8, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fldxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_dr_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fp_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_fv_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_load_mtrx_after (current_cpu, idesc, 8, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatld_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatld_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatls_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatls_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_floatqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmacs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frf);
    cycles += model_u_use_fr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 3);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 7, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 8, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmacs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frf);
    cycles += model_u_use_fr_after (current_cpu, idesc, 2, referenced, in_usereg);
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 8, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovdq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovdq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovls_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovls_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmovsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmuld_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmuld_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmuls_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fmuls_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fnegd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fnegd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fnegs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fnegs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fputscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fputscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsqrtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_fsqrtd_before (current_cpu, idesc, 1, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsqrtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_fsqrtd_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsqrts_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_fsqrt_before (current_cpu, idesc, 1, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsqrts_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_fsqrt_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fstd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drf);
    cycles += model_u_use_dr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fstd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_drf);
    cycles += model_u_use_dr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_fstp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fpf);
    cycles += model_u_use_fp_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fstp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_fpf);
    cycles += model_u_use_fp_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_fsts_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frf);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 2);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsts_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fsts.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_frf);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_fstxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_drf);
    cycles += model_u_use_dr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fstxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_drf);
    cycles += model_u_use_dr_after (current_cpu, idesc, 2, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_fstxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_fpf);
    cycles += model_u_use_fp_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fstxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_fpf);
    cycles += model_u_use_fp_after (current_cpu, idesc, 2, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_fstxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_frf);
    cycles += model_u_use_fr_before (current_cpu, idesc, 2, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 3);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fstxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fstxs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    in_usereg = FLD (in_frf);
    cycles += model_u_use_fr_after (current_cpu, idesc, 2, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_fsubd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsubd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drg);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsubs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 6, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 7, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_fsubs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frg);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 7, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_frf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_drgh);
    cycles += model_u_use_dr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 1);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_before (current_cpu, idesc, 2, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_before (current_cpu, idesc, 3, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_before (current_cpu, idesc, 4, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_before (current_cpu, idesc, 5, out_loadreg);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_before (current_cpu, idesc, 6, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrcsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_frgh);
    cycles += model_u_use_fr_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_fpu_after (current_cpu, idesc, 1, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_dr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fp_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_fv_after (current_cpu, idesc, 5, referenced, out_loadreg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_drf);
    cycles += model_u_set_mtrx_after (current_cpu, idesc, 6, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrvs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrvs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_mtrxg);
    cycles += model_u_use_mtrx_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_fvh);
    cycles += model_u_use_fv_before (current_cpu, idesc, 1, in_usereg);
  }
  {
    cycles += model_u_fpu_before (current_cpu, idesc, 2);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_fvf);
    cycles += model_u_ftrvs_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ftrvs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ftrvs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_mtrxg);
    cycles += model_u_use_mtrx_after (current_cpu, idesc, 0, referenced, in_usereg);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_fvh);
    cycles += model_u_use_fv_after (current_cpu, idesc, 1, referenced, in_usereg);
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
    out_loadreg = FLD (out_fvf);
    cycles += model_u_ftrvs_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_getcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_getcfg_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_getcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    cycles += model_u_getcfg_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_getcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 1, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_getcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 1, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_gettr_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_trb);
    cycles += model_u_use_tr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_gettr_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_trb);
    cycles += model_u_use_tr_after (current_cpu, idesc, 0, referenced, in_usereg);
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
sh5_media_sh5_media_model::model_icbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_icbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ldb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ldq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_lduw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_lduw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldhiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldhiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxuw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxuw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_before (current_cpu, idesc, 4, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ldxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_load_gr_after (current_cpu, idesc, 4, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mabsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mabsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mabsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 2, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mabsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 2, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_maddsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpeqb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpeqb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpeql_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpeql_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpeqw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpeqw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpgtl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpgtl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpgtub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpgtub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpgtw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmpgtw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmv_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcmv_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcnvslw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcnvslw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcnvswb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcnvswb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcnvswub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mcnvswub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr1_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr1_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr2_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr2_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr3_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr3_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr4_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr4_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr5_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr5_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr6_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr6_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr7_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mextr7_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmacfxwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmacfxwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmacnfx_wl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmacnfx_wl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmull_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmull_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulfxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulfxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulfxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulfxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulfxrpw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulfxrpw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulhiwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulhiwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmullowl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmullowl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulsumwq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mmulsumwq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_movi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_movi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_movi.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mpermw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mpermw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msadubq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msadubq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshaldsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshaldsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshaldsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshaldsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshardw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshardw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshardsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshardsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshfhib_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshfhib_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshfhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshfhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshfhiw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshfhiw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshflob_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshflob_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshflol_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshflol_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshflow_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshflow_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlrdw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mshlrdw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_msubsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mulsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mulsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mulul_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_before (current_cpu, idesc, 3, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_mulul_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_loadreg = -1;
    out_loadreg = FLD (out_rd);
    cycles += model_u_set_gr_after (current_cpu, idesc, 3, referenced, out_loadreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_nop_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_nop_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_nsb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_nsb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ocbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ocbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ocbp_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ocbp_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ocbwb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ocbwb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_or_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_or_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ori_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_ori_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_prefi_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_prefi_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_pta_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_before (current_cpu, idesc, 1, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_pta_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_after (current_cpu, idesc, 1, referenced, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ptabs_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_before (current_cpu, idesc, 2, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ptabs_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_after (current_cpu, idesc, 2, referenced, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ptb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  {
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_before (current_cpu, idesc, 1, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ptb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_after (current_cpu, idesc, 1, referenced, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ptrel_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_before (current_cpu, idesc, 2, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_ptrel_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    INT out_targetreg = -1;
    out_targetreg = FLD (out_tra);
    cycles += model_u_pt_after (current_cpu, idesc, 2, referenced, out_targetreg);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_putcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rm);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_putcfg_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_putcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
    cycles += model_u_putcfg_after (current_cpu, idesc, 1, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_putcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_putcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_rte_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_rte_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shard_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shard_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shari_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shari_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_sharil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_sharil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shlld_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlld_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlli_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shlli_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shllil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shllil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shlrd_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlrd_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shlri_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shlri_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shlril_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shlril_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_shori_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    INT in_usereg = -1;
    in_usereg = FLD (in_rd);
    cycles += model_u_use_gr_before (current_cpu, idesc, 0, in_usereg);
  }
  {
    cycles += model_u_exec_before (current_cpu, idesc, 1);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_shori_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_shori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    INT in_usereg = -1;
    in_usereg = FLD (in_rd);
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
sh5_media_sh5_media_model::model_sleep_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_sleep_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stb.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stb.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stl.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stq.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_stw.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_sthil_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_sthil_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_sthiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_sthiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_stxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_stxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_sub_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_sub_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_subl_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_subl_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_swapq_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_swapq_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_synci_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_synci_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_synco_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    cycles += model_u_exec_before (current_cpu, idesc, 0);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_synco_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
  int cycles = 0;
  {
    int referenced = 0;
    unsigned long long insn_referenced = abuf->written;
    cycles += model_u_exec_after (current_cpu, idesc, 0, referenced);
  }
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_trapa_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_trapa_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_xor_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_xor_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
  return cycles;
#undef FLD
}

UINT
sh5_media_sh5_media_model::model_xori_before (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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
sh5_media_sh5_media_model::model_xori_after (sh5_cpu *current_cpu, sh5_media_scache *sem)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  const sh5_media_scache* abuf = sem;
  const sh5_media_idesc* idesc = abuf->idesc;
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

/* We assume UNIT_NONE == 0 because the tables don't always terminate
   entries with it.  */

/* Model timing data for `sh5'.  */

const sh5_media_sh5_model::insn_timing sh5_media_sh5_model::timing[] = {
  { SH5_MEDIA_INSN_X_INVALID, 0, 0, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADD, & sh5_media_sh5_model::model_add_before, & sh5_media_sh5_model::model_add_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDL, & sh5_media_sh5_model::model_addl_before, & sh5_media_sh5_model::model_addl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDI, & sh5_media_sh5_model::model_addi_before, & sh5_media_sh5_model::model_addi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDIL, & sh5_media_sh5_model::model_addil_before, & sh5_media_sh5_model::model_addil_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDZL, & sh5_media_sh5_model::model_addzl_before, & sh5_media_sh5_model::model_addzl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ALLOCO, & sh5_media_sh5_model::model_alloco_before, & sh5_media_sh5_model::model_alloco_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_AND, & sh5_media_sh5_model::model_and_before, & sh5_media_sh5_model::model_and_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ANDC, & sh5_media_sh5_model::model_andc_before, & sh5_media_sh5_model::model_andc_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ANDI, & sh5_media_sh5_model::model_andi_before, & sh5_media_sh5_model::model_andi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BEQ, & sh5_media_sh5_model::model_beq_before, & sh5_media_sh5_model::model_beq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BEQI, & sh5_media_sh5_model::model_beqi_before, & sh5_media_sh5_model::model_beqi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BGE, & sh5_media_sh5_model::model_bge_before, & sh5_media_sh5_model::model_bge_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BGEU, & sh5_media_sh5_model::model_bgeu_before, & sh5_media_sh5_model::model_bgeu_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BGT, & sh5_media_sh5_model::model_bgt_before, & sh5_media_sh5_model::model_bgt_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BGTU, & sh5_media_sh5_model::model_bgtu_before, & sh5_media_sh5_model::model_bgtu_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BLINK, & sh5_media_sh5_model::model_blink_before, & sh5_media_sh5_model::model_blink_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BNE, & sh5_media_sh5_model::model_bne_before, & sh5_media_sh5_model::model_bne_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BNEI, & sh5_media_sh5_model::model_bnei_before, & sh5_media_sh5_model::model_bnei_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BRK, & sh5_media_sh5_model::model_brk_before, & sh5_media_sh5_model::model_brk_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BYTEREV, & sh5_media_sh5_model::model_byterev_before, & sh5_media_sh5_model::model_byterev_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMPEQ, & sh5_media_sh5_model::model_cmpeq_before, & sh5_media_sh5_model::model_cmpeq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMPGT, & sh5_media_sh5_model::model_cmpgt_before, & sh5_media_sh5_model::model_cmpgt_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMPGTU, & sh5_media_sh5_model::model_cmpgtu_before, & sh5_media_sh5_model::model_cmpgtu_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMVEQ, & sh5_media_sh5_model::model_cmveq_before, & sh5_media_sh5_model::model_cmveq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMVNE, & sh5_media_sh5_model::model_cmvne_before, & sh5_media_sh5_model::model_cmvne_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FABSD, & sh5_media_sh5_model::model_fabsd_before, & sh5_media_sh5_model::model_fabsd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FABSS, & sh5_media_sh5_model::model_fabss_before, & sh5_media_sh5_model::model_fabss_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FADDD, & sh5_media_sh5_model::model_faddd_before, & sh5_media_sh5_model::model_faddd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FADDS, & sh5_media_sh5_model::model_fadds_before, & sh5_media_sh5_model::model_fadds_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPEQD, & sh5_media_sh5_model::model_fcmpeqd_before, & sh5_media_sh5_model::model_fcmpeqd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPEQS, & sh5_media_sh5_model::model_fcmpeqs_before, & sh5_media_sh5_model::model_fcmpeqs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPGED, & sh5_media_sh5_model::model_fcmpged_before, & sh5_media_sh5_model::model_fcmpged_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPGES, & sh5_media_sh5_model::model_fcmpges_before, & sh5_media_sh5_model::model_fcmpges_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPGTD, & sh5_media_sh5_model::model_fcmpgtd_before, & sh5_media_sh5_model::model_fcmpgtd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPGTS, & sh5_media_sh5_model::model_fcmpgts_before, & sh5_media_sh5_model::model_fcmpgts_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPUND, & sh5_media_sh5_model::model_fcmpund_before, & sh5_media_sh5_model::model_fcmpund_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCMPUNS, & sh5_media_sh5_model::model_fcmpuns_before, & sh5_media_sh5_model::model_fcmpuns_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCNVDS, & sh5_media_sh5_model::model_fcnvds_before, & sh5_media_sh5_model::model_fcnvds_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FCNVSD, & sh5_media_sh5_model::model_fcnvsd_before, & sh5_media_sh5_model::model_fcnvsd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FDIVD, & sh5_media_sh5_model::model_fdivd_before, & sh5_media_sh5_model::model_fdivd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FDIVS, & sh5_media_sh5_model::model_fdivs_before, & sh5_media_sh5_model::model_fdivs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FGETSCR, & sh5_media_sh5_model::model_fgetscr_before, & sh5_media_sh5_model::model_fgetscr_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FIPRS, & sh5_media_sh5_model::model_fiprs_before, & sh5_media_sh5_model::model_fiprs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLDD, & sh5_media_sh5_model::model_fldd_before, & sh5_media_sh5_model::model_fldd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLDP, & sh5_media_sh5_model::model_fldp_before, & sh5_media_sh5_model::model_fldp_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLDS, & sh5_media_sh5_model::model_flds_before, & sh5_media_sh5_model::model_flds_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLDXD, & sh5_media_sh5_model::model_fldxd_before, & sh5_media_sh5_model::model_fldxd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLDXP, & sh5_media_sh5_model::model_fldxp_before, & sh5_media_sh5_model::model_fldxp_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLDXS, & sh5_media_sh5_model::model_fldxs_before, & sh5_media_sh5_model::model_fldxs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLOATLD, & sh5_media_sh5_model::model_floatld_before, & sh5_media_sh5_model::model_floatld_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLOATLS, & sh5_media_sh5_model::model_floatls_before, & sh5_media_sh5_model::model_floatls_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLOATQD, & sh5_media_sh5_model::model_floatqd_before, & sh5_media_sh5_model::model_floatqd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FLOATQS, & sh5_media_sh5_model::model_floatqs_before, & sh5_media_sh5_model::model_floatqs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMACS, & sh5_media_sh5_model::model_fmacs_before, & sh5_media_sh5_model::model_fmacs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMOVD, & sh5_media_sh5_model::model_fmovd_before, & sh5_media_sh5_model::model_fmovd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMOVDQ, & sh5_media_sh5_model::model_fmovdq_before, & sh5_media_sh5_model::model_fmovdq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMOVLS, & sh5_media_sh5_model::model_fmovls_before, & sh5_media_sh5_model::model_fmovls_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMOVQD, & sh5_media_sh5_model::model_fmovqd_before, & sh5_media_sh5_model::model_fmovqd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMOVS, & sh5_media_sh5_model::model_fmovs_before, & sh5_media_sh5_model::model_fmovs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMOVSL, & sh5_media_sh5_model::model_fmovsl_before, & sh5_media_sh5_model::model_fmovsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMULD, & sh5_media_sh5_model::model_fmuld_before, & sh5_media_sh5_model::model_fmuld_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FMULS, & sh5_media_sh5_model::model_fmuls_before, & sh5_media_sh5_model::model_fmuls_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FNEGD, & sh5_media_sh5_model::model_fnegd_before, & sh5_media_sh5_model::model_fnegd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FNEGS, & sh5_media_sh5_model::model_fnegs_before, & sh5_media_sh5_model::model_fnegs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FPUTSCR, & sh5_media_sh5_model::model_fputscr_before, & sh5_media_sh5_model::model_fputscr_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSQRTD, & sh5_media_sh5_model::model_fsqrtd_before, & sh5_media_sh5_model::model_fsqrtd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSQRTS, & sh5_media_sh5_model::model_fsqrts_before, & sh5_media_sh5_model::model_fsqrts_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTD, & sh5_media_sh5_model::model_fstd_before, & sh5_media_sh5_model::model_fstd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTP, & sh5_media_sh5_model::model_fstp_before, & sh5_media_sh5_model::model_fstp_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTS, & sh5_media_sh5_model::model_fsts_before, & sh5_media_sh5_model::model_fsts_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTXD, & sh5_media_sh5_model::model_fstxd_before, & sh5_media_sh5_model::model_fstxd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTXP, & sh5_media_sh5_model::model_fstxp_before, & sh5_media_sh5_model::model_fstxp_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTXS, & sh5_media_sh5_model::model_fstxs_before, & sh5_media_sh5_model::model_fstxs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSUBD, & sh5_media_sh5_model::model_fsubd_before, & sh5_media_sh5_model::model_fsubd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSUBS, & sh5_media_sh5_model::model_fsubs_before, & sh5_media_sh5_model::model_fsubs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FTRCDL, & sh5_media_sh5_model::model_ftrcdl_before, & sh5_media_sh5_model::model_ftrcdl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FTRCSL, & sh5_media_sh5_model::model_ftrcsl_before, & sh5_media_sh5_model::model_ftrcsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FTRCDQ, & sh5_media_sh5_model::model_ftrcdq_before, & sh5_media_sh5_model::model_ftrcdq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FTRCSQ, & sh5_media_sh5_model::model_ftrcsq_before, & sh5_media_sh5_model::model_ftrcsq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FTRVS, & sh5_media_sh5_model::model_ftrvs_before, & sh5_media_sh5_model::model_ftrvs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_GETCFG, & sh5_media_sh5_model::model_getcfg_before, & sh5_media_sh5_model::model_getcfg_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_GETCON, & sh5_media_sh5_model::model_getcon_before, & sh5_media_sh5_model::model_getcon_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_GETTR, & sh5_media_sh5_model::model_gettr_before, & sh5_media_sh5_model::model_gettr_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ICBI, & sh5_media_sh5_model::model_icbi_before, & sh5_media_sh5_model::model_icbi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDB, & sh5_media_sh5_model::model_ldb_before, & sh5_media_sh5_model::model_ldb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDL, & sh5_media_sh5_model::model_ldl_before, & sh5_media_sh5_model::model_ldl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDQ, & sh5_media_sh5_model::model_ldq_before, & sh5_media_sh5_model::model_ldq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDUB, & sh5_media_sh5_model::model_ldub_before, & sh5_media_sh5_model::model_ldub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDUW, & sh5_media_sh5_model::model_lduw_before, & sh5_media_sh5_model::model_lduw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDW, & sh5_media_sh5_model::model_ldw_before, & sh5_media_sh5_model::model_ldw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDHIL, & sh5_media_sh5_model::model_ldhil_before, & sh5_media_sh5_model::model_ldhil_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDHIQ, & sh5_media_sh5_model::model_ldhiq_before, & sh5_media_sh5_model::model_ldhiq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDLOL, & sh5_media_sh5_model::model_ldlol_before, & sh5_media_sh5_model::model_ldlol_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDLOQ, & sh5_media_sh5_model::model_ldloq_before, & sh5_media_sh5_model::model_ldloq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDXB, & sh5_media_sh5_model::model_ldxb_before, & sh5_media_sh5_model::model_ldxb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDXL, & sh5_media_sh5_model::model_ldxl_before, & sh5_media_sh5_model::model_ldxl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDXQ, & sh5_media_sh5_model::model_ldxq_before, & sh5_media_sh5_model::model_ldxq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDXUB, & sh5_media_sh5_model::model_ldxub_before, & sh5_media_sh5_model::model_ldxub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDXUW, & sh5_media_sh5_model::model_ldxuw_before, & sh5_media_sh5_model::model_ldxuw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDXW, & sh5_media_sh5_model::model_ldxw_before, & sh5_media_sh5_model::model_ldxw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MABSL, & sh5_media_sh5_model::model_mabsl_before, & sh5_media_sh5_model::model_mabsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MABSW, & sh5_media_sh5_model::model_mabsw_before, & sh5_media_sh5_model::model_mabsw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDL, & sh5_media_sh5_model::model_maddl_before, & sh5_media_sh5_model::model_maddl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDW, & sh5_media_sh5_model::model_maddw_before, & sh5_media_sh5_model::model_maddw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDSL, & sh5_media_sh5_model::model_maddsl_before, & sh5_media_sh5_model::model_maddsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDSUB, & sh5_media_sh5_model::model_maddsub_before, & sh5_media_sh5_model::model_maddsub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDSW, & sh5_media_sh5_model::model_maddsw_before, & sh5_media_sh5_model::model_maddsw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMPEQB, & sh5_media_sh5_model::model_mcmpeqb_before, & sh5_media_sh5_model::model_mcmpeqb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMPEQL, & sh5_media_sh5_model::model_mcmpeql_before, & sh5_media_sh5_model::model_mcmpeql_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMPEQW, & sh5_media_sh5_model::model_mcmpeqw_before, & sh5_media_sh5_model::model_mcmpeqw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMPGTL, & sh5_media_sh5_model::model_mcmpgtl_before, & sh5_media_sh5_model::model_mcmpgtl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMPGTUB, & sh5_media_sh5_model::model_mcmpgtub_before, & sh5_media_sh5_model::model_mcmpgtub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMPGTW, & sh5_media_sh5_model::model_mcmpgtw_before, & sh5_media_sh5_model::model_mcmpgtw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCMV, & sh5_media_sh5_model::model_mcmv_before, & sh5_media_sh5_model::model_mcmv_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCNVSLW, & sh5_media_sh5_model::model_mcnvslw_before, & sh5_media_sh5_model::model_mcnvslw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCNVSWB, & sh5_media_sh5_model::model_mcnvswb_before, & sh5_media_sh5_model::model_mcnvswb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCNVSWUB, & sh5_media_sh5_model::model_mcnvswub_before, & sh5_media_sh5_model::model_mcnvswub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR1, & sh5_media_sh5_model::model_mextr1_before, & sh5_media_sh5_model::model_mextr1_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR2, & sh5_media_sh5_model::model_mextr2_before, & sh5_media_sh5_model::model_mextr2_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR3, & sh5_media_sh5_model::model_mextr3_before, & sh5_media_sh5_model::model_mextr3_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR4, & sh5_media_sh5_model::model_mextr4_before, & sh5_media_sh5_model::model_mextr4_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR5, & sh5_media_sh5_model::model_mextr5_before, & sh5_media_sh5_model::model_mextr5_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR6, & sh5_media_sh5_model::model_mextr6_before, & sh5_media_sh5_model::model_mextr6_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR7, & sh5_media_sh5_model::model_mextr7_before, & sh5_media_sh5_model::model_mextr7_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMACFXWL, & sh5_media_sh5_model::model_mmacfxwl_before, & sh5_media_sh5_model::model_mmacfxwl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMACNFX_WL, & sh5_media_sh5_model::model_mmacnfx_wl_before, & sh5_media_sh5_model::model_mmacnfx_wl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULL, & sh5_media_sh5_model::model_mmull_before, & sh5_media_sh5_model::model_mmull_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULW, & sh5_media_sh5_model::model_mmulw_before, & sh5_media_sh5_model::model_mmulw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULFXL, & sh5_media_sh5_model::model_mmulfxl_before, & sh5_media_sh5_model::model_mmulfxl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULFXW, & sh5_media_sh5_model::model_mmulfxw_before, & sh5_media_sh5_model::model_mmulfxw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULFXRPW, & sh5_media_sh5_model::model_mmulfxrpw_before, & sh5_media_sh5_model::model_mmulfxrpw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULHIWL, & sh5_media_sh5_model::model_mmulhiwl_before, & sh5_media_sh5_model::model_mmulhiwl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULLOWL, & sh5_media_sh5_model::model_mmullowl_before, & sh5_media_sh5_model::model_mmullowl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULSUMWQ, & sh5_media_sh5_model::model_mmulsumwq_before, & sh5_media_sh5_model::model_mmulsumwq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MOVI, & sh5_media_sh5_model::model_movi_before, & sh5_media_sh5_model::model_movi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MPERMW, & sh5_media_sh5_model::model_mpermw_before, & sh5_media_sh5_model::model_mpermw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSADUBQ, & sh5_media_sh5_model::model_msadubq_before, & sh5_media_sh5_model::model_msadubq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHALDSL, & sh5_media_sh5_model::model_mshaldsl_before, & sh5_media_sh5_model::model_mshaldsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHALDSW, & sh5_media_sh5_model::model_mshaldsw_before, & sh5_media_sh5_model::model_mshaldsw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHARDL, & sh5_media_sh5_model::model_mshardl_before, & sh5_media_sh5_model::model_mshardl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHARDW, & sh5_media_sh5_model::model_mshardw_before, & sh5_media_sh5_model::model_mshardw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHARDSQ, & sh5_media_sh5_model::model_mshardsq_before, & sh5_media_sh5_model::model_mshardsq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFHIB, & sh5_media_sh5_model::model_mshfhib_before, & sh5_media_sh5_model::model_mshfhib_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFHIL, & sh5_media_sh5_model::model_mshfhil_before, & sh5_media_sh5_model::model_mshfhil_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFHIW, & sh5_media_sh5_model::model_mshfhiw_before, & sh5_media_sh5_model::model_mshfhiw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFLOB, & sh5_media_sh5_model::model_mshflob_before, & sh5_media_sh5_model::model_mshflob_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFLOL, & sh5_media_sh5_model::model_mshflol_before, & sh5_media_sh5_model::model_mshflol_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFLOW, & sh5_media_sh5_model::model_mshflow_before, & sh5_media_sh5_model::model_mshflow_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLLDL, & sh5_media_sh5_model::model_mshlldl_before, & sh5_media_sh5_model::model_mshlldl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLLDW, & sh5_media_sh5_model::model_mshlldw_before, & sh5_media_sh5_model::model_mshlldw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLRDL, & sh5_media_sh5_model::model_mshlrdl_before, & sh5_media_sh5_model::model_mshlrdl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLRDW, & sh5_media_sh5_model::model_mshlrdw_before, & sh5_media_sh5_model::model_mshlrdw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBL, & sh5_media_sh5_model::model_msubl_before, & sh5_media_sh5_model::model_msubl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBW, & sh5_media_sh5_model::model_msubw_before, & sh5_media_sh5_model::model_msubw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBSL, & sh5_media_sh5_model::model_msubsl_before, & sh5_media_sh5_model::model_msubsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBSUB, & sh5_media_sh5_model::model_msubsub_before, & sh5_media_sh5_model::model_msubsub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBSW, & sh5_media_sh5_model::model_msubsw_before, & sh5_media_sh5_model::model_msubsw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MULSL, & sh5_media_sh5_model::model_mulsl_before, & sh5_media_sh5_model::model_mulsl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MULUL, & sh5_media_sh5_model::model_mulul_before, & sh5_media_sh5_model::model_mulul_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_NOP, & sh5_media_sh5_model::model_nop_before, & sh5_media_sh5_model::model_nop_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_NSB, & sh5_media_sh5_model::model_nsb_before, & sh5_media_sh5_model::model_nsb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OCBI, & sh5_media_sh5_model::model_ocbi_before, & sh5_media_sh5_model::model_ocbi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OCBP, & sh5_media_sh5_model::model_ocbp_before, & sh5_media_sh5_model::model_ocbp_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OCBWB, & sh5_media_sh5_model::model_ocbwb_before, & sh5_media_sh5_model::model_ocbwb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OR, & sh5_media_sh5_model::model_or_before, & sh5_media_sh5_model::model_or_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ORI, & sh5_media_sh5_model::model_ori_before, & sh5_media_sh5_model::model_ori_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PREFI, & sh5_media_sh5_model::model_prefi_before, & sh5_media_sh5_model::model_prefi_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PTA, & sh5_media_sh5_model::model_pta_before, & sh5_media_sh5_model::model_pta_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PTABS, & sh5_media_sh5_model::model_ptabs_before, & sh5_media_sh5_model::model_ptabs_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PTB, & sh5_media_sh5_model::model_ptb_before, & sh5_media_sh5_model::model_ptb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PTREL, & sh5_media_sh5_model::model_ptrel_before, & sh5_media_sh5_model::model_ptrel_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PUTCFG, & sh5_media_sh5_model::model_putcfg_before, & sh5_media_sh5_model::model_putcfg_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PUTCON, & sh5_media_sh5_model::model_putcon_before, & sh5_media_sh5_model::model_putcon_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_RTE, & sh5_media_sh5_model::model_rte_before, & sh5_media_sh5_model::model_rte_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARD, & sh5_media_sh5_model::model_shard_before, & sh5_media_sh5_model::model_shard_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARDL, & sh5_media_sh5_model::model_shardl_before, & sh5_media_sh5_model::model_shardl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARI, & sh5_media_sh5_model::model_shari_before, & sh5_media_sh5_model::model_shari_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARIL, & sh5_media_sh5_model::model_sharil_before, & sh5_media_sh5_model::model_sharil_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLD, & sh5_media_sh5_model::model_shlld_before, & sh5_media_sh5_model::model_shlld_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLDL, & sh5_media_sh5_model::model_shlldl_before, & sh5_media_sh5_model::model_shlldl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLI, & sh5_media_sh5_model::model_shlli_before, & sh5_media_sh5_model::model_shlli_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLIL, & sh5_media_sh5_model::model_shllil_before, & sh5_media_sh5_model::model_shllil_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRD, & sh5_media_sh5_model::model_shlrd_before, & sh5_media_sh5_model::model_shlrd_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRDL, & sh5_media_sh5_model::model_shlrdl_before, & sh5_media_sh5_model::model_shlrdl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRI, & sh5_media_sh5_model::model_shlri_before, & sh5_media_sh5_model::model_shlri_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRIL, & sh5_media_sh5_model::model_shlril_before, & sh5_media_sh5_model::model_shlril_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHORI, & sh5_media_sh5_model::model_shori_before, & sh5_media_sh5_model::model_shori_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SLEEP, & sh5_media_sh5_model::model_sleep_before, & sh5_media_sh5_model::model_sleep_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STB, & sh5_media_sh5_model::model_stb_before, & sh5_media_sh5_model::model_stb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STL, & sh5_media_sh5_model::model_stl_before, & sh5_media_sh5_model::model_stl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STQ, & sh5_media_sh5_model::model_stq_before, & sh5_media_sh5_model::model_stq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STW, & sh5_media_sh5_model::model_stw_before, & sh5_media_sh5_model::model_stw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STHIL, & sh5_media_sh5_model::model_sthil_before, & sh5_media_sh5_model::model_sthil_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STHIQ, & sh5_media_sh5_model::model_sthiq_before, & sh5_media_sh5_model::model_sthiq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STLOL, & sh5_media_sh5_model::model_stlol_before, & sh5_media_sh5_model::model_stlol_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STLOQ, & sh5_media_sh5_model::model_stloq_before, & sh5_media_sh5_model::model_stloq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXB, & sh5_media_sh5_model::model_stxb_before, & sh5_media_sh5_model::model_stxb_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXL, & sh5_media_sh5_model::model_stxl_before, & sh5_media_sh5_model::model_stxl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXQ, & sh5_media_sh5_model::model_stxq_before, & sh5_media_sh5_model::model_stxq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXW, & sh5_media_sh5_model::model_stxw_before, & sh5_media_sh5_model::model_stxw_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SUB, & sh5_media_sh5_model::model_sub_before, & sh5_media_sh5_model::model_sub_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SUBL, & sh5_media_sh5_model::model_subl_before, & sh5_media_sh5_model::model_subl_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SWAPQ, & sh5_media_sh5_model::model_swapq_before, & sh5_media_sh5_model::model_swapq_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SYNCI, & sh5_media_sh5_model::model_synci_before, & sh5_media_sh5_model::model_synci_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SYNCO, & sh5_media_sh5_model::model_synco_before, & sh5_media_sh5_model::model_synco_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_TRAPA, & sh5_media_sh5_model::model_trapa_before, & sh5_media_sh5_model::model_trapa_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_XOR, & sh5_media_sh5_model::model_xor_before, & sh5_media_sh5_model::model_xor_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_XORI, & sh5_media_sh5_model::model_xori_before, & sh5_media_sh5_model::model_xori_after, { { sh5_media_sh5_model::UNIT_U_EXEC, 1, 1 } } },
};

/* Model timing data for `sh5-media'.  */

const sh5_media_sh5_media_model::insn_timing sh5_media_sh5_media_model::timing[] = {
  { SH5_MEDIA_INSN_X_INVALID, 0, 0, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADD, & sh5_media_sh5_media_model::model_add_before, & sh5_media_sh5_media_model::model_add_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDL, & sh5_media_sh5_media_model::model_addl_before, & sh5_media_sh5_media_model::model_addl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDI, & sh5_media_sh5_media_model::model_addi_before, & sh5_media_sh5_media_model::model_addi_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDIL, & sh5_media_sh5_media_model::model_addil_before, & sh5_media_sh5_media_model::model_addil_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ADDZL, & sh5_media_sh5_media_model::model_addzl_before, & sh5_media_sh5_media_model::model_addzl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ALLOCO, & sh5_media_sh5_media_model::model_alloco_before, & sh5_media_sh5_media_model::model_alloco_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_AND, & sh5_media_sh5_media_model::model_and_before, & sh5_media_sh5_media_model::model_and_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ANDC, & sh5_media_sh5_media_model::model_andc_before, & sh5_media_sh5_media_model::model_andc_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ANDI, & sh5_media_sh5_media_model::model_andi_before, & sh5_media_sh5_media_model::model_andi_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_BEQ, & sh5_media_sh5_media_model::model_beq_before, & sh5_media_sh5_media_model::model_beq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BEQI, & sh5_media_sh5_media_model::model_beqi_before, & sh5_media_sh5_media_model::model_beqi_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BGE, & sh5_media_sh5_media_model::model_bge_before, & sh5_media_sh5_media_model::model_bge_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BGEU, & sh5_media_sh5_media_model::model_bgeu_before, & sh5_media_sh5_media_model::model_bgeu_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BGT, & sh5_media_sh5_media_model::model_bgt_before, & sh5_media_sh5_media_model::model_bgt_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BGTU, & sh5_media_sh5_media_model::model_bgtu_before, & sh5_media_sh5_media_model::model_bgtu_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BLINK, & sh5_media_sh5_media_model::model_blink_before, & sh5_media_sh5_media_model::model_blink_after, { { sh5_media_sh5_media_model::UNIT_U_BLINK, 0, 0 } } },
  { SH5_MEDIA_INSN_BNE, & sh5_media_sh5_media_model::model_bne_before, & sh5_media_sh5_media_model::model_bne_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BNEI, & sh5_media_sh5_media_model::model_bnei_before, & sh5_media_sh5_media_model::model_bnei_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_COND_BRANCH, 0, 0 } } },
  { SH5_MEDIA_INSN_BRK, & sh5_media_sh5_media_model::model_brk_before, & sh5_media_sh5_media_model::model_brk_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 10 } } },
  { SH5_MEDIA_INSN_BYTEREV, & sh5_media_sh5_media_model::model_byterev_before, & sh5_media_sh5_media_model::model_byterev_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMPEQ, & sh5_media_sh5_media_model::model_cmpeq_before, & sh5_media_sh5_media_model::model_cmpeq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMPGT, & sh5_media_sh5_media_model::model_cmpgt_before, & sh5_media_sh5_media_model::model_cmpgt_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMPGTU, & sh5_media_sh5_media_model::model_cmpgtu_before, & sh5_media_sh5_media_model::model_cmpgtu_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMVEQ, & sh5_media_sh5_media_model::model_cmveq_before, & sh5_media_sh5_media_model::model_cmveq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_CMVNE, & sh5_media_sh5_media_model::model_cmvne_before, & sh5_media_sh5_media_model::model_cmvne_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FABSD, & sh5_media_sh5_media_model::model_fabsd_before, & sh5_media_sh5_media_model::model_fabsd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FABSS, & sh5_media_sh5_media_model::model_fabss_before, & sh5_media_sh5_media_model::model_fabss_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FADDD, & sh5_media_sh5_media_model::model_faddd_before, & sh5_media_sh5_media_model::model_faddd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FADDS, & sh5_media_sh5_media_model::model_fadds_before, & sh5_media_sh5_media_model::model_fadds_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FCMPEQD, & sh5_media_sh5_media_model::model_fcmpeqd_before, & sh5_media_sh5_media_model::model_fcmpeqd_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPEQS, & sh5_media_sh5_media_model::model_fcmpeqs_before, & sh5_media_sh5_media_model::model_fcmpeqs_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPGED, & sh5_media_sh5_media_model::model_fcmpged_before, & sh5_media_sh5_media_model::model_fcmpged_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPGES, & sh5_media_sh5_media_model::model_fcmpges_before, & sh5_media_sh5_media_model::model_fcmpges_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPGTD, & sh5_media_sh5_media_model::model_fcmpgtd_before, & sh5_media_sh5_media_model::model_fcmpgtd_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPGTS, & sh5_media_sh5_media_model::model_fcmpgts_before, & sh5_media_sh5_media_model::model_fcmpgts_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPUND, & sh5_media_sh5_media_model::model_fcmpund_before, & sh5_media_sh5_media_model::model_fcmpund_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCMPUNS, & sh5_media_sh5_media_model::model_fcmpuns_before, & sh5_media_sh5_media_model::model_fcmpuns_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FCNVDS, & sh5_media_sh5_media_model::model_fcnvds_before, & sh5_media_sh5_media_model::model_fcnvds_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FCNVSD, & sh5_media_sh5_media_model::model_fcnvsd_before, & sh5_media_sh5_media_model::model_fcnvsd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FDIVD, & sh5_media_sh5_media_model::model_fdivd_before, & sh5_media_sh5_media_model::model_fdivd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FDIVD, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 36 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 35 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 35 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 36 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 36 } } },
  { SH5_MEDIA_INSN_FDIVS, & sh5_media_sh5_media_model::model_fdivs_before, & sh5_media_sh5_media_model::model_fdivs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FDIV, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 19 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 20 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 20 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 20 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 20 } } },
  { SH5_MEDIA_INSN_FGETSCR, & sh5_media_sh5_media_model::model_fgetscr_before, & sh5_media_sh5_media_model::model_fgetscr_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FIPRS, & sh5_media_sh5_media_model::model_fiprs_before, & sh5_media_sh5_media_model::model_fiprs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FV, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FV, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FLDD, & sh5_media_sh5_media_model::model_fldd_before, & sh5_media_sh5_media_model::model_fldd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_DR, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FP, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FV, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_MTRX, 0, 6 } } },
  { SH5_MEDIA_INSN_FLDP, & sh5_media_sh5_media_model::model_fldp_before, & sh5_media_sh5_media_model::model_fldp_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_DR, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FP, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FV, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_MTRX, 0, 6 } } },
  { SH5_MEDIA_INSN_FLDS, & sh5_media_sh5_media_model::model_flds_before, & sh5_media_sh5_media_model::model_flds_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FR, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FV, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_MTRX, 0, 6 } } },
  { SH5_MEDIA_INSN_FLDXD, & sh5_media_sh5_media_model::model_fldxd_before, & sh5_media_sh5_media_model::model_fldxd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_DR, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FP, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FV, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_MTRX, 0, 6 } } },
  { SH5_MEDIA_INSN_FLDXP, & sh5_media_sh5_media_model::model_fldxp_before, & sh5_media_sh5_media_model::model_fldxp_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_DR, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FP, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FV, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_MTRX, 0, 6 } } },
  { SH5_MEDIA_INSN_FLDXS, & sh5_media_sh5_media_model::model_fldxs_before, & sh5_media_sh5_media_model::model_fldxs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FR, 0, 3 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_FV, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_MTRX, 0, 6 } } },
  { SH5_MEDIA_INSN_FLOATLD, & sh5_media_sh5_media_model::model_floatld_before, & sh5_media_sh5_media_model::model_floatld_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FLOATLS, & sh5_media_sh5_media_model::model_floatls_before, & sh5_media_sh5_media_model::model_floatls_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FLOATQD, & sh5_media_sh5_media_model::model_floatqd_before, & sh5_media_sh5_media_model::model_floatqd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FLOATQS, & sh5_media_sh5_media_model::model_floatqs_before, & sh5_media_sh5_media_model::model_floatqs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FMACS, & sh5_media_sh5_media_model::model_fmacs_before, & sh5_media_sh5_media_model::model_fmacs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FMOVD, & sh5_media_sh5_media_model::model_fmovd_before, & sh5_media_sh5_media_model::model_fmovd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FMOVDQ, & sh5_media_sh5_media_model::model_fmovdq_before, & sh5_media_sh5_media_model::model_fmovdq_after, { { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FMOVLS, & sh5_media_sh5_media_model::model_fmovls_before, & sh5_media_sh5_media_model::model_fmovls_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FMOVQD, & sh5_media_sh5_media_model::model_fmovqd_before, & sh5_media_sh5_media_model::model_fmovqd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FMOVS, & sh5_media_sh5_media_model::model_fmovs_before, & sh5_media_sh5_media_model::model_fmovs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FMOVSL, & sh5_media_sh5_media_model::model_fmovsl_before, & sh5_media_sh5_media_model::model_fmovsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_FMULD, & sh5_media_sh5_media_model::model_fmuld_before, & sh5_media_sh5_media_model::model_fmuld_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 10 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 9 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 9 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 10 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 10 } } },
  { SH5_MEDIA_INSN_FMULS, & sh5_media_sh5_media_model::model_fmuls_before, & sh5_media_sh5_media_model::model_fmuls_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FNEGD, & sh5_media_sh5_media_model::model_fnegd_before, & sh5_media_sh5_media_model::model_fnegd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FNEGS, & sh5_media_sh5_media_model::model_fnegs_before, & sh5_media_sh5_media_model::model_fnegs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FPUTSCR, & sh5_media_sh5_media_model::model_fputscr_before, & sh5_media_sh5_media_model::model_fputscr_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 8 } } },
  { SH5_MEDIA_INSN_FSQRTD, & sh5_media_sh5_media_model::model_fsqrtd_before, & sh5_media_sh5_media_model::model_fsqrtd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FSQRTD, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 36 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 35 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 35 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 36 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 36 } } },
  { SH5_MEDIA_INSN_FSQRTS, & sh5_media_sh5_media_model::model_fsqrts_before, & sh5_media_sh5_media_model::model_fsqrts_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FSQRT, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 19 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 20 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 20 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 20 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 20 } } },
  { SH5_MEDIA_INSN_FSTD, & sh5_media_sh5_media_model::model_fstd_before, & sh5_media_sh5_media_model::model_fstd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTP, & sh5_media_sh5_media_model::model_fstp_before, & sh5_media_sh5_media_model::model_fstp_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FP, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTS, & sh5_media_sh5_media_model::model_fsts_before, & sh5_media_sh5_media_model::model_fsts_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTXD, & sh5_media_sh5_media_model::model_fstxd_before, & sh5_media_sh5_media_model::model_fstxd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTXP, & sh5_media_sh5_media_model::model_fstxp_before, & sh5_media_sh5_media_model::model_fstxp_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FP, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSTXS, & sh5_media_sh5_media_model::model_fstxs_before, & sh5_media_sh5_media_model::model_fstxs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_FSUBD, & sh5_media_sh5_media_model::model_fsubd_before, & sh5_media_sh5_media_model::model_fsubd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FSUBS, & sh5_media_sh5_media_model::model_fsubs_before, & sh5_media_sh5_media_model::model_fsubs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FTRCDL, & sh5_media_sh5_media_model::model_ftrcdl_before, & sh5_media_sh5_media_model::model_ftrcdl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FTRCSL, & sh5_media_sh5_media_model::model_ftrcsl_before, & sh5_media_sh5_media_model::model_ftrcsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FTRCDQ, & sh5_media_sh5_media_model::model_ftrcdq_before, & sh5_media_sh5_media_model::model_ftrcdq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_DR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FTRCSQ, & sh5_media_sh5_media_model::model_ftrcsq_before, & sh5_media_sh5_media_model::model_ftrcsq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_FR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_FR, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_DR, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FP, 0, 6 }, { sh5_media_sh5_media_model::UNIT_U_SET_FV, 0, 7 }, { sh5_media_sh5_media_model::UNIT_U_SET_MTRX, 0, 7 } } },
  { SH5_MEDIA_INSN_FTRVS, & sh5_media_sh5_media_model::model_ftrvs_before, & sh5_media_sh5_media_model::model_ftrvs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_MTRX, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_FV, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_FPU, 0, 4 }, { sh5_media_sh5_media_model::UNIT_U_FTRVS, 0, 0 } } },
  { SH5_MEDIA_INSN_GETCFG, & sh5_media_sh5_media_model::model_getcfg_before, & sh5_media_sh5_media_model::model_getcfg_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_GETCFG, 0, 0 } } },
  { SH5_MEDIA_INSN_GETCON, & sh5_media_sh5_media_model::model_getcon_before, & sh5_media_sh5_media_model::model_getcon_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_GETTR, & sh5_media_sh5_media_model::model_gettr_before, & sh5_media_sh5_media_model::model_gettr_after, { { sh5_media_sh5_media_model::UNIT_U_USE_TR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ICBI, & sh5_media_sh5_media_model::model_icbi_before, & sh5_media_sh5_media_model::model_icbi_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_LDB, & sh5_media_sh5_media_model::model_ldb_before, & sh5_media_sh5_media_model::model_ldb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDL, & sh5_media_sh5_media_model::model_ldl_before, & sh5_media_sh5_media_model::model_ldl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDQ, & sh5_media_sh5_media_model::model_ldq_before, & sh5_media_sh5_media_model::model_ldq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDUB, & sh5_media_sh5_media_model::model_ldub_before, & sh5_media_sh5_media_model::model_ldub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDUW, & sh5_media_sh5_media_model::model_lduw_before, & sh5_media_sh5_media_model::model_lduw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDW, & sh5_media_sh5_media_model::model_ldw_before, & sh5_media_sh5_media_model::model_ldw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDHIL, & sh5_media_sh5_media_model::model_ldhil_before, & sh5_media_sh5_media_model::model_ldhil_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDHIQ, & sh5_media_sh5_media_model::model_ldhiq_before, & sh5_media_sh5_media_model::model_ldhiq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDLOL, & sh5_media_sh5_media_model::model_ldlol_before, & sh5_media_sh5_media_model::model_ldlol_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDLOQ, & sh5_media_sh5_media_model::model_ldloq_before, & sh5_media_sh5_media_model::model_ldloq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDXB, & sh5_media_sh5_media_model::model_ldxb_before, & sh5_media_sh5_media_model::model_ldxb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDXL, & sh5_media_sh5_media_model::model_ldxl_before, & sh5_media_sh5_media_model::model_ldxl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDXQ, & sh5_media_sh5_media_model::model_ldxq_before, & sh5_media_sh5_media_model::model_ldxq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDXUB, & sh5_media_sh5_media_model::model_ldxub_before, & sh5_media_sh5_media_model::model_ldxub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDXUW, & sh5_media_sh5_media_model::model_ldxuw_before, & sh5_media_sh5_media_model::model_ldxuw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_LDXW, & sh5_media_sh5_media_model::model_ldxw_before, & sh5_media_sh5_media_model::model_ldxw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_MEMORY_ACCESS, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_LOAD_GR, 0, 0 } } },
  { SH5_MEDIA_INSN_MABSL, & sh5_media_sh5_media_model::model_mabsl_before, & sh5_media_sh5_media_model::model_mabsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MABSW, & sh5_media_sh5_media_model::model_mabsw_before, & sh5_media_sh5_media_model::model_mabsw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MADDL, & sh5_media_sh5_media_model::model_maddl_before, & sh5_media_sh5_media_model::model_maddl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDW, & sh5_media_sh5_media_model::model_maddw_before, & sh5_media_sh5_media_model::model_maddw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MADDSL, & sh5_media_sh5_media_model::model_maddsl_before, & sh5_media_sh5_media_model::model_maddsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MADDSUB, & sh5_media_sh5_media_model::model_maddsub_before, & sh5_media_sh5_media_model::model_maddsub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MADDSW, & sh5_media_sh5_media_model::model_maddsw_before, & sh5_media_sh5_media_model::model_maddsw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMPEQB, & sh5_media_sh5_media_model::model_mcmpeqb_before, & sh5_media_sh5_media_model::model_mcmpeqb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMPEQL, & sh5_media_sh5_media_model::model_mcmpeql_before, & sh5_media_sh5_media_model::model_mcmpeql_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMPEQW, & sh5_media_sh5_media_model::model_mcmpeqw_before, & sh5_media_sh5_media_model::model_mcmpeqw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMPGTL, & sh5_media_sh5_media_model::model_mcmpgtl_before, & sh5_media_sh5_media_model::model_mcmpgtl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMPGTUB, & sh5_media_sh5_media_model::model_mcmpgtub_before, & sh5_media_sh5_media_model::model_mcmpgtub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMPGTW, & sh5_media_sh5_media_model::model_mcmpgtw_before, & sh5_media_sh5_media_model::model_mcmpgtw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCMV, & sh5_media_sh5_media_model::model_mcmv_before, & sh5_media_sh5_media_model::model_mcmv_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MCNVSLW, & sh5_media_sh5_media_model::model_mcnvslw_before, & sh5_media_sh5_media_model::model_mcnvslw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCNVSWB, & sh5_media_sh5_media_model::model_mcnvswb_before, & sh5_media_sh5_media_model::model_mcnvswb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MCNVSWUB, & sh5_media_sh5_media_model::model_mcnvswub_before, & sh5_media_sh5_media_model::model_mcnvswub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MEXTR1, & sh5_media_sh5_media_model::model_mextr1_before, & sh5_media_sh5_media_model::model_mextr1_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR2, & sh5_media_sh5_media_model::model_mextr2_before, & sh5_media_sh5_media_model::model_mextr2_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR3, & sh5_media_sh5_media_model::model_mextr3_before, & sh5_media_sh5_media_model::model_mextr3_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR4, & sh5_media_sh5_media_model::model_mextr4_before, & sh5_media_sh5_media_model::model_mextr4_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR5, & sh5_media_sh5_media_model::model_mextr5_before, & sh5_media_sh5_media_model::model_mextr5_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR6, & sh5_media_sh5_media_model::model_mextr6_before, & sh5_media_sh5_media_model::model_mextr6_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MEXTR7, & sh5_media_sh5_media_model::model_mextr7_before, & sh5_media_sh5_media_model::model_mextr7_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMACFXWL, & sh5_media_sh5_media_model::model_mmacfxwl_before, & sh5_media_sh5_media_model::model_mmacfxwl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMACNFX_WL, & sh5_media_sh5_media_model::model_mmacnfx_wl_before, & sh5_media_sh5_media_model::model_mmacnfx_wl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MMULL, & sh5_media_sh5_media_model::model_mmull_before, & sh5_media_sh5_media_model::model_mmull_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 2 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 4 } } },
  { SH5_MEDIA_INSN_MMULW, & sh5_media_sh5_media_model::model_mmulw_before, & sh5_media_sh5_media_model::model_mmulw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_MMULFXL, & sh5_media_sh5_media_model::model_mmulfxl_before, & sh5_media_sh5_media_model::model_mmulfxl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 2 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 4 } } },
  { SH5_MEDIA_INSN_MMULFXW, & sh5_media_sh5_media_model::model_mmulfxw_before, & sh5_media_sh5_media_model::model_mmulfxw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_MMULFXRPW, & sh5_media_sh5_media_model::model_mmulfxrpw_before, & sh5_media_sh5_media_model::model_mmulfxrpw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_MMULHIWL, & sh5_media_sh5_media_model::model_mmulhiwl_before, & sh5_media_sh5_media_model::model_mmulhiwl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_MMULLOWL, & sh5_media_sh5_media_model::model_mmullowl_before, & sh5_media_sh5_media_model::model_mmullowl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_MMULSUMWQ, & sh5_media_sh5_media_model::model_mmulsumwq_before, & sh5_media_sh5_media_model::model_mmulsumwq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MOVI, & sh5_media_sh5_media_model::model_movi_before, & sh5_media_sh5_media_model::model_movi_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MPERMW, & sh5_media_sh5_media_model::model_mpermw_before, & sh5_media_sh5_media_model::model_mpermw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSADUBQ, & sh5_media_sh5_media_model::model_msadubq_before, & sh5_media_sh5_media_model::model_msadubq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHALDSL, & sh5_media_sh5_media_model::model_mshaldsl_before, & sh5_media_sh5_media_model::model_mshaldsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MSHALDSW, & sh5_media_sh5_media_model::model_mshaldsw_before, & sh5_media_sh5_media_model::model_mshaldsw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MSHARDL, & sh5_media_sh5_media_model::model_mshardl_before, & sh5_media_sh5_media_model::model_mshardl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHARDW, & sh5_media_sh5_media_model::model_mshardw_before, & sh5_media_sh5_media_model::model_mshardw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHARDSQ, & sh5_media_sh5_media_model::model_mshardsq_before, & sh5_media_sh5_media_model::model_mshardsq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MSHFHIB, & sh5_media_sh5_media_model::model_mshfhib_before, & sh5_media_sh5_media_model::model_mshfhib_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFHIL, & sh5_media_sh5_media_model::model_mshfhil_before, & sh5_media_sh5_media_model::model_mshfhil_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFHIW, & sh5_media_sh5_media_model::model_mshfhiw_before, & sh5_media_sh5_media_model::model_mshfhiw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFLOB, & sh5_media_sh5_media_model::model_mshflob_before, & sh5_media_sh5_media_model::model_mshflob_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFLOL, & sh5_media_sh5_media_model::model_mshflol_before, & sh5_media_sh5_media_model::model_mshflol_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHFLOW, & sh5_media_sh5_media_model::model_mshflow_before, & sh5_media_sh5_media_model::model_mshflow_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLLDL, & sh5_media_sh5_media_model::model_mshlldl_before, & sh5_media_sh5_media_model::model_mshlldl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLLDW, & sh5_media_sh5_media_model::model_mshlldw_before, & sh5_media_sh5_media_model::model_mshlldw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLRDL, & sh5_media_sh5_media_model::model_mshlrdl_before, & sh5_media_sh5_media_model::model_mshlrdl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSHLRDW, & sh5_media_sh5_media_model::model_mshlrdw_before, & sh5_media_sh5_media_model::model_mshlrdw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBL, & sh5_media_sh5_media_model::model_msubl_before, & sh5_media_sh5_media_model::model_msubl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBW, & sh5_media_sh5_media_model::model_msubw_before, & sh5_media_sh5_media_model::model_msubw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_MSUBSL, & sh5_media_sh5_media_model::model_msubsl_before, & sh5_media_sh5_media_model::model_msubsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MSUBSUB, & sh5_media_sh5_media_model::model_msubsub_before, & sh5_media_sh5_media_model::model_msubsub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MSUBSW, & sh5_media_sh5_media_model::model_msubsw_before, & sh5_media_sh5_media_model::model_msubsw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 2 } } },
  { SH5_MEDIA_INSN_MULSL, & sh5_media_sh5_media_model::model_mulsl_before, & sh5_media_sh5_media_model::model_mulsl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_MULUL, & sh5_media_sh5_media_model::model_mulul_before, & sh5_media_sh5_media_model::model_mulul_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_SET_GR, 0, 3 } } },
  { SH5_MEDIA_INSN_NOP, & sh5_media_sh5_media_model::model_nop_before, & sh5_media_sh5_media_model::model_nop_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_NSB, & sh5_media_sh5_media_model::model_nsb_before, & sh5_media_sh5_media_model::model_nsb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OCBI, & sh5_media_sh5_media_model::model_ocbi_before, & sh5_media_sh5_media_model::model_ocbi_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OCBP, & sh5_media_sh5_media_model::model_ocbp_before, & sh5_media_sh5_media_model::model_ocbp_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OCBWB, & sh5_media_sh5_media_model::model_ocbwb_before, & sh5_media_sh5_media_model::model_ocbwb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_OR, & sh5_media_sh5_media_model::model_or_before, & sh5_media_sh5_media_model::model_or_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_ORI, & sh5_media_sh5_media_model::model_ori_before, & sh5_media_sh5_media_model::model_ori_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PREFI, & sh5_media_sh5_media_model::model_prefi_before, & sh5_media_sh5_media_model::model_prefi_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_PTA, & sh5_media_sh5_media_model::model_pta_before, & sh5_media_sh5_media_model::model_pta_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_PT, 0, 0 } } },
  { SH5_MEDIA_INSN_PTABS, & sh5_media_sh5_media_model::model_ptabs_before, & sh5_media_sh5_media_model::model_ptabs_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_PT, 0, 0 } } },
  { SH5_MEDIA_INSN_PTB, & sh5_media_sh5_media_model::model_ptb_before, & sh5_media_sh5_media_model::model_ptb_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_PT, 0, 0 } } },
  { SH5_MEDIA_INSN_PTREL, & sh5_media_sh5_media_model::model_ptrel_before, & sh5_media_sh5_media_model::model_ptrel_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 }, { sh5_media_sh5_media_model::UNIT_U_PT, 0, 0 } } },
  { SH5_MEDIA_INSN_PUTCFG, & sh5_media_sh5_media_model::model_putcfg_before, & sh5_media_sh5_media_model::model_putcfg_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_PUTCFG, 0, 0 } } },
  { SH5_MEDIA_INSN_PUTCON, & sh5_media_sh5_media_model::model_putcon_before, & sh5_media_sh5_media_model::model_putcon_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 5 } } },
  { SH5_MEDIA_INSN_RTE, & sh5_media_sh5_media_model::model_rte_before, & sh5_media_sh5_media_model::model_rte_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 8 } } },
  { SH5_MEDIA_INSN_SHARD, & sh5_media_sh5_media_model::model_shard_before, & sh5_media_sh5_media_model::model_shard_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARDL, & sh5_media_sh5_media_model::model_shardl_before, & sh5_media_sh5_media_model::model_shardl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARI, & sh5_media_sh5_media_model::model_shari_before, & sh5_media_sh5_media_model::model_shari_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHARIL, & sh5_media_sh5_media_model::model_sharil_before, & sh5_media_sh5_media_model::model_sharil_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLD, & sh5_media_sh5_media_model::model_shlld_before, & sh5_media_sh5_media_model::model_shlld_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLDL, & sh5_media_sh5_media_model::model_shlldl_before, & sh5_media_sh5_media_model::model_shlldl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLI, & sh5_media_sh5_media_model::model_shlli_before, & sh5_media_sh5_media_model::model_shlli_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLLIL, & sh5_media_sh5_media_model::model_shllil_before, & sh5_media_sh5_media_model::model_shllil_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRD, & sh5_media_sh5_media_model::model_shlrd_before, & sh5_media_sh5_media_model::model_shlrd_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRDL, & sh5_media_sh5_media_model::model_shlrdl_before, & sh5_media_sh5_media_model::model_shlrdl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRI, & sh5_media_sh5_media_model::model_shlri_before, & sh5_media_sh5_media_model::model_shlri_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHLRIL, & sh5_media_sh5_media_model::model_shlril_before, & sh5_media_sh5_media_model::model_shlril_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SHORI, & sh5_media_sh5_media_model::model_shori_before, & sh5_media_sh5_media_model::model_shori_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SLEEP, & sh5_media_sh5_media_model::model_sleep_before, & sh5_media_sh5_media_model::model_sleep_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STB, & sh5_media_sh5_media_model::model_stb_before, & sh5_media_sh5_media_model::model_stb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STL, & sh5_media_sh5_media_model::model_stl_before, & sh5_media_sh5_media_model::model_stl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STQ, & sh5_media_sh5_media_model::model_stq_before, & sh5_media_sh5_media_model::model_stq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STW, & sh5_media_sh5_media_model::model_stw_before, & sh5_media_sh5_media_model::model_stw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STHIL, & sh5_media_sh5_media_model::model_sthil_before, & sh5_media_sh5_media_model::model_sthil_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STHIQ, & sh5_media_sh5_media_model::model_sthiq_before, & sh5_media_sh5_media_model::model_sthiq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STLOL, & sh5_media_sh5_media_model::model_stlol_before, & sh5_media_sh5_media_model::model_stlol_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STLOQ, & sh5_media_sh5_media_model::model_stloq_before, & sh5_media_sh5_media_model::model_stloq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXB, & sh5_media_sh5_media_model::model_stxb_before, & sh5_media_sh5_media_model::model_stxb_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXL, & sh5_media_sh5_media_model::model_stxl_before, & sh5_media_sh5_media_model::model_stxl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXQ, & sh5_media_sh5_media_model::model_stxq_before, & sh5_media_sh5_media_model::model_stxq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_STXW, & sh5_media_sh5_media_model::model_stxw_before, & sh5_media_sh5_media_model::model_stxw_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SUB, & sh5_media_sh5_media_model::model_sub_before, & sh5_media_sh5_media_model::model_sub_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SUBL, & sh5_media_sh5_media_model::model_subl_before, & sh5_media_sh5_media_model::model_subl_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SWAPQ, & sh5_media_sh5_media_model::model_swapq_before, & sh5_media_sh5_media_model::model_swapq_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SYNCI, & sh5_media_sh5_media_model::model_synci_before, & sh5_media_sh5_media_model::model_synci_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_SYNCO, & sh5_media_sh5_media_model::model_synco_before, & sh5_media_sh5_media_model::model_synco_after, { { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_TRAPA, & sh5_media_sh5_media_model::model_trapa_before, & sh5_media_sh5_media_model::model_trapa_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 10 } } },
  { SH5_MEDIA_INSN_XOR, & sh5_media_sh5_media_model::model_xor_before, & sh5_media_sh5_media_model::model_xor_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
  { SH5_MEDIA_INSN_XORI, & sh5_media_sh5_media_model::model_xori_before, & sh5_media_sh5_media_model::model_xori_after, { { sh5_media_sh5_media_model::UNIT_U_USE_GR, 0, 0 }, { sh5_media_sh5_media_model::UNIT_U_EXEC, 1, 1 } } },
};

