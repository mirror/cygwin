/* Simulator instruction operand writer for xstormy16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000, 2001, 2002 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "xstormy16.h"
using namespace xstormy16;


sem_status
xstormy16_write_sfmt_empty (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_empty.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto


  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movlmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movlmemimm.f
#define OPRND(f) par_exec->operands.sfmt_movlmemimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 5))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_lmem8_idx), OPRND (h_memory_HI_lmem8));
    }
  if (written & (1ULL << 6))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_lmem8_idx), OPRND (h_memory_QI_lmem8));
    }
  if (written & (1ULL << 7))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movhmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movhmemimm.f
#define OPRND(f) par_exec->operands.sfmt_movhmemimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 5))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_hmem8_idx), OPRND (h_memory_HI_hmem8));
    }
  if (written & (1ULL << 6))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_hmem8_idx), OPRND (h_memory_QI_hmem8));
    }
  if (written & (1ULL << 7))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movlgrmem (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movlgrmem.f
#define OPRND(f) par_exec->operands.sfmt_movlgrmem.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 7))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rm_idx), OPRND (h_gr_HI_index_of__DFLT_Rm));
    }
  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movhgrmem (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movhgrmem.f
#define OPRND(f) par_exec->operands.sfmt_movhgrmem.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 7))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rm_idx), OPRND (h_gr_HI_index_of__DFLT_Rm));
    }
  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movlmemgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movlgrmem.f
#define OPRND(f) par_exec->operands.sfmt_movlmemgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 5))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_lmem8_idx), OPRND (h_memory_HI_lmem8));
    }
  if (written & (1ULL << 6))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_lmem8_idx), OPRND (h_memory_QI_lmem8));
    }
  if (written & (1ULL << 7))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgri (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrgri.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 7))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgripostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrgripostinc.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgripredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrgripredec.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrigr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 5))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_nwhere_idx), OPRND (h_memory_HI_nwhere));
    }
  if (written & (1ULL << 6))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_Rs_idx), OPRND (h_memory_QI_Rs));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgripostincgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgripostincgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  if (written & (1ULL << 6))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_nwhere_idx), OPRND (h_memory_HI_nwhere));
    }
  if (written & (1ULL << 7))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_Rs_idx), OPRND (h_memory_QI_Rs));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgripredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgripredecgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  if (written & (1ULL << 6))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_nwhere_idx), OPRND (h_memory_HI_nwhere));
    }
  if (written & (1ULL << 7))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_Rs_idx), OPRND (h_memory_QI_Rs));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgrii (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrgrii.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgriipostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrgriipostinc.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgriipredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgrgriipredec.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgriigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgriigr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  if (written & (1ULL << 7))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_nwhere_idx), OPRND (h_memory_HI_nwhere));
    }
  if (written & (1ULL << 8))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_add__DFLT_Rs_imm12_idx), OPRND (h_memory_QI_add__DFLT_Rs_imm12));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgriipredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movgriipredecgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  if (written & (1ULL << 7))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_nwhere_idx), OPRND (h_memory_HI_nwhere));
    }
  if (written & (1ULL << 8))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_add__DFLT_Rs_imm12_idx), OPRND (h_memory_QI_add__DFLT_Rs_imm12));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_movgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movwimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
#define OPRND(f) par_exec->operands.sfmt_movwimm8.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_Rpsw_idx), OPRND (h_gr_HI_Rpsw));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movwgrimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
#define OPRND(f) par_exec->operands.sfmt_movwgrimm8.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rm_idx), OPRND (h_gr_HI_index_of__DFLT_Rm));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movwgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
#define OPRND(f) par_exec->operands.sfmt_movwgrimm16.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movlowgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_movlowgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrgri (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrgri.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 8))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrgripostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrgripostinc.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrgripredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrgripredec.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrigr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
    }
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgripredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgripredecgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrgrii (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrgrii.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 9))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrgriipostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrgriipostinc.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 11))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgrgriipredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgrgriipredec.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  if (written & (1ULL << 10))
    {
      current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rdm_idx), OPRND (h_gr_HI_index_of__DFLT_Rdm));
    }
  if (written & (1ULL << 11))
    {
      current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgriigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgriigr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  if (written & (1ULL << 8))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_and__DFLT_add__DFLT_join__SI_HI_Rb_Rs_imm12_4294967294_idx), OPRND (h_memory_HI_and__DFLT_add__DFLT_join__SI_HI_Rb_Rs_imm12_4294967294));
    }
  if (written & (1ULL << 9))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_add__DFLT_join__SI_HI_Rb_Rs_imm12_idx), OPRND (h_memory_QI_add__DFLT_join__SI_HI_Rb_Rs_imm12));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_movfgriipredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
#define OPRND(f) par_exec->operands.sfmt_movfgriipredecgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rs_idx), OPRND (h_gr_HI_index_of__DFLT_Rs));
  if (written & (1ULL << 8))
    {
      current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_and__DFLT_add__DFLT_join__SI_HI_Rb_Rs_imm12_4294967294_idx), OPRND (h_memory_HI_and__DFLT_add__DFLT_join__SI_HI_Rb_Rs_imm12_4294967294));
    }
  if (written & (1ULL << 9))
    {
      current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_add__DFLT_join__SI_HI_Rb_Rs_imm12_idx), OPRND (h_memory_QI_add__DFLT_join__SI_HI_Rb_Rs_imm12));
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_maskgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_maskgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_maskgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
#define OPRND(f) par_exec->operands.sfmt_maskgrimm16.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_pushgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_pushgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_sp_idx), OPRND (h_memory_HI_sp));
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_popgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_popgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rd), OPRND (Rd));
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_swpn (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_swpn.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_swpw (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_swpw.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (FLD (f_Rs), OPRND (Rs));
  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_andgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_andgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_andimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
#define OPRND(f) par_exec->operands.sfmt_andimm8.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_Rpsw_idx), OPRND (h_gr_HI_Rpsw));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_andgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
#define OPRND(f) par_exec->operands.sfmt_andgrimm16.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_addgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_addgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_addgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
#define OPRND(f) par_exec->operands.sfmt_addgrimm4.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_addimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
#define OPRND(f) par_exec->operands.sfmt_addimm8.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_Rpsw_idx), OPRND (h_gr_HI_Rpsw));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_addgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
#define OPRND(f) par_exec->operands.sfmt_addgrimm16.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_adcgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_adcgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_adcgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
#define OPRND(f) par_exec->operands.sfmt_adcgrimm4.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_adcimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
#define OPRND(f) par_exec->operands.sfmt_adcimm8.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_Rpsw_idx), OPRND (h_gr_HI_Rpsw));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_adcgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
#define OPRND(f) par_exec->operands.sfmt_adcgrimm16.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_incgrimm2 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_incgrimm2.f
#define OPRND(f) par_exec->operands.sfmt_incgrimm2.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_rrcgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_rrcgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_rrcgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
#define OPRND(f) par_exec->operands.sfmt_rrcgrimm4.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_shrgrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
#define OPRND(f) par_exec->operands.sfmt_shrgrimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_asrgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_asrgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_asrgrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
#define OPRND(f) par_exec->operands.sfmt_asrgrimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (OPRND (h_gr_HI_index_of__DFLT_Rd_idx), OPRND (h_gr_HI_index_of__DFLT_Rd));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_set1lmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_set1lmemimm.f
#define OPRND(f) par_exec->operands.sfmt_set1lmemimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_lmem8_idx), OPRND (h_memory_QI_lmem8));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_set1hmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_set1hmemimm.f
#define OPRND(f) par_exec->operands.sfmt_set1hmemimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMQI (pc, OPRND (h_memory_QI_hmem8_idx), OPRND (h_memory_QI_hmem8));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bccgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_bccgrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 13))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bccgrimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
#define OPRND(f) par_exec->operands.sfmt_bccgrimm8.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 13))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bccimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccimm16.f
#define OPRND(f) par_exec->operands.sfmt_bccimm16.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 12))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bngrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
#define OPRND(f) par_exec->operands.sfmt_bngrimm4.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_Rpsw_set (OPRND (Rpsw));
  if (written & (1ULL << 5))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bngrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
#define OPRND(f) par_exec->operands.sfmt_bngrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_Rpsw_set (OPRND (Rpsw));
  if (written & (1ULL << 5))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bnlmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bnlmemimm.f
#define OPRND(f) par_exec->operands.sfmt_bnlmemimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 4))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bnhmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bnhmemimm.f
#define OPRND(f) par_exec->operands.sfmt_bnhmemimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 4))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bcc (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_bcc.f
#define OPRND(f) par_exec->operands.sfmt_bcc.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  if (written & (1ULL << 7))
    {
      current_cpu->branch (OPRND (pc), npc, status);
    }

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_bgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_bgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->branch (OPRND (pc), npc, status);

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_br (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_br.f
#define OPRND(f) par_exec->operands.sfmt_br.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->branch (OPRND (pc), npc, status);

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_jmp (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_jmp.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->branch (OPRND (pc), npc, status);

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_jmpf (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmpf.f
#define OPRND(f) par_exec->operands.sfmt_jmpf.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->branch (OPRND (pc), npc, status);

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_callrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_callrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_callrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_br.f
#define OPRND(f) par_exec->operands.sfmt_callrimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_callgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_callgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_callfimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmpf.f
#define OPRND(f) par_exec->operands.sfmt_callfimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_icallrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_icallrgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_add__DFLT_sp_4_idx), OPRND (h_memory_HI_add__DFLT_sp_4));
  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_icallgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
#define OPRND(f) par_exec->operands.sfmt_icallgr.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_add__DFLT_sp_4_idx), OPRND (h_memory_HI_add__DFLT_sp_4));
  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_icallfimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.sfmt_jmpf.f
#define OPRND(f) par_exec->operands.sfmt_icallfimm.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->SETMEMHI (pc, OPRND (h_memory_HI_add__DFLT_sp_4_idx), OPRND (h_memory_HI_add__DFLT_sp_4));
  current_cpu->SETMEMSI (pc, OPRND (h_memory_SI_sp_idx), OPRND (h_memory_SI_sp));
  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_iret (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_iret.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_ret (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_ret.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->branch (OPRND (pc), npc, status);
  current_cpu->h_gr_set (((UINT) 15), OPRND (sp));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_mul (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_mul.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (((UINT) 0), OPRND (R0));
  current_cpu->h_gr_set (((UINT) 1), OPRND (R1));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_sdiv (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_sdiv.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (((UINT) 0), OPRND (R0));
  current_cpu->h_gr_set (((UINT) 1), OPRND (R1));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_sdivlh (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_sdivlh.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto

  current_cpu->h_gr_set (((UINT) 0), OPRND (R0));
  current_cpu->h_gr_set (((UINT) 1), OPRND (R1));
  current_cpu->h_gr_set (((UINT) 14), OPRND (psw));

  return status;
#undef OPRND
#undef FLD
}


sem_status
xstormy16_write_sfmt_nop (xstormy16_cpu* current_cpu, xstormy16_scache* sem, xstormy16_parexec* par_exec)
{
#define FLD(f) abuf->fields.fmt_empty.f
#define OPRND(f) par_exec->operands.sfmt_nop.f
  xstormy16_scache* abuf = sem;
  unsigned long long written = abuf->written;
  PCADDR pc = abuf->addr;
  PCADDR npc = 0; // dummy value for branches
  sem_status status = SEM_STATUS_NORMAL; // ditto


  return status;
#undef OPRND
#undef FLD
}

