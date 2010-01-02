/* Simulator instruction semantics for xstormy16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "xstormy16.h"

using namespace xstormy16; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

sem_status
xstormy16_sem_x_invalid (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 0;

  {
    current_cpu->invalid_insn (pc);
    assert (0);
    /* NOTREACHED */
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movlmemimm: mov$ws2 $lmem8,#$imm16

sem_status
xstormy16_sem_movlmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movlmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = FLD (f_imm16);
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (FLD (f_lmem8), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (FLD (f_lmem8), 65534), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (FLD (f_imm16), 255);
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_lmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_lmem8), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movhmemimm: mov$ws2 $hmem8,#$imm16

sem_status
xstormy16_sem_movhmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movhmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = FLD (f_imm16);
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (FLD (f_hmem8), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (FLD (f_hmem8), 65534), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (FLD (f_imm16), 255);
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_hmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_hmem8), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movlgrmem: mov$ws2 $Rm,$lmem8

sem_status
xstormy16_sem_movlgrmem (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movlgrmem.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (FLD (f_lmem8), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMQI (pc, FLD (f_lmem8));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movhgrmem: mov$ws2 $Rm,$hmem8

sem_status
xstormy16_sem_movhgrmem (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movhgrmem.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (FLD (f_hmem8), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMQI (pc, FLD (f_hmem8));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movlmemgr: mov$ws2 $lmem8,$Rm

sem_status
xstormy16_sem_movlmemgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movlgrmem.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (FLD (f_lmem8), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (FLD (f_lmem8), 65534), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_lmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_lmem8), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movhmemgr: mov$ws2 $hmem8,$Rm

sem_status
xstormy16_sem_movhmemgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movhgrmem.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (FLD (f_hmem8), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (FLD (f_hmem8), 65534), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_hmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_hmem8), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgri: mov$ws2 $Rdm,($Rs)

sem_status
xstormy16_sem_movgrgri (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, current_cpu->h_gr_get (FLD (f_Rs))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgripostinc: mov$ws2 $Rdm,($Rs++)

sem_status
xstormy16_sem_movgrgripostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, current_cpu->h_gr_get (FLD (f_Rs))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (1, FLD (f_op2m)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgripredec: mov$ws2 $Rdm,(--$Rs)

sem_status
xstormy16_sem_movgrgripredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (1, FLD (f_op2m)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, current_cpu->h_gr_get (FLD (f_Rs))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrigr: mov$ws2 ($Rs),$Rdm

sem_status
xstormy16_sem_movgrigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (FLD (f_Rs)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, current_cpu->h_gr_get (FLD (f_Rs)), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgripostincgr: mov$ws2 ($Rs++),$Rdm

sem_status
xstormy16_sem_movgripostincgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (FLD (f_Rs)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, current_cpu->h_gr_get (FLD (f_Rs)), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgripredecgr: mov$ws2 (--$Rs),$Rdm

sem_status
xstormy16_sem_movgripredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (FLD (f_Rs)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, current_cpu->h_gr_get (FLD (f_Rs)), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgrii: mov$ws2 $Rdm,($Rs,$imm12)

sem_status
xstormy16_sem_movgrgrii (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgriipostinc: mov$ws2 $Rdm,($Rs++,$imm12)

sem_status
xstormy16_sem_movgrgriipostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgriipredec: mov$ws2 $Rdm,(--$Rs,$imm12)

sem_status
xstormy16_sem_movgrgriipredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgriigr: mov$ws2 ($Rs,$imm12),$Rdm

sem_status
xstormy16_sem_movgriigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgriipostincgr: mov$ws2 ($Rs++,$imm12),$Rdm

sem_status
xstormy16_sem_movgriipostincgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgriipredecgr: mov$ws2 (--$Rs,$imm12),$Rdm

sem_status
xstormy16_sem_movgriipredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), FLD (f_imm12)), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movgrgr: mov $Rd,$Rs

sem_status
xstormy16_sem_movgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rs));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movwimm8: mov.w Rx,#$imm8

sem_status
xstormy16_sem_movwimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = FLD (f_imm8);
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (current_cpu->h_Rpsw_get (), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movwgrimm8: mov.w $Rm,#$imm8small

sem_status
xstormy16_sem_movwgrimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = FLD (f_imm8);
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movwgrimm16: mov.w $Rd,#$imm16

sem_status
xstormy16_sem_movwgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_nvalue;
  tmp_nvalue = FLD (f_imm16);
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movlowgr: mov.b $Rd,RxL

sem_status
xstormy16_sem_movlowgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 65280), ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 255));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (0, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movhighgr: mov.b $Rd,RxH

sem_status
xstormy16_sem_movhighgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 255), ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 65280));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrgri: movf$ws2 $Rdm,($Rs)

sem_status
xstormy16_sem_movfgrgri (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ORSI (SLLSI (current_cpu->h_gr_get (((UINT) 8)), 16), current_cpu->h_gr_get (FLD (f_Rs))), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ORSI (SLLSI (current_cpu->h_gr_get (((UINT) 8)), 16), current_cpu->h_gr_get (FLD (f_Rs)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrgripostinc: movf$ws2 $Rdm,($Rs++)

sem_status
xstormy16_sem_movfgrgripostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrgripredec: movf$ws2 $Rdm,(--$Rs)

sem_status
xstormy16_sem_movfgrgripredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrigr: movf$ws2 ($Rs),$Rdm

sem_status
xstormy16_sem_movfgrigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgripostincgr: movf$ws2 ($Rs++),$Rdm

sem_status
xstormy16_sem_movfgripostincgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgripredecgr: movf$ws2 (--$Rs),$Rdm

sem_status
xstormy16_sem_movfgripredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), 65534), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, JOINHISI (current_cpu->h_gr_get (((UINT) 8)), current_cpu->h_gr_get (FLD (f_Rs))), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrgrii: movf$ws2 $Rdm,($Rb,$Rs,$imm12)

sem_status
xstormy16_sem_movfgrgrii (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrgriipostinc: movf$ws2 $Rdm,($Rb,$Rs++,$imm12)

sem_status
xstormy16_sem_movfgrgriipostinc (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgrgriipredec: movf$ws2 $Rdm,($Rb,--$Rs,$imm12)

sem_status
xstormy16_sem_movfgrgriipredec (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
if (FLD (f_op2m)) {
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->GETMEMHI (pc, ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 65534));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
} else {
{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (255, current_cpu->GETMEMQI (pc, ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rdm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rdm), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgriigr: movf$ws2 ($Rb,$Rs,$imm12),$Rdm

sem_status
xstormy16_sem_movfgriigr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 0xfffffffe) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 0xfffffffe), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgriipostincgr: movf$ws2 ($Rb,$Rs++,$imm12),$Rdm

sem_status
xstormy16_sem_movfgriipostincgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 0xfffffffe) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 0xfffffffe), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), opval);
  }
}
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
  {
    SI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rs)), ADDSI (FLD (f_op2m), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movfgriipredecgr: movf$ws2 ($Rb,--$Rs,$imm12),$Rdm

sem_status
xstormy16_sem_movfgriipredecgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (FLD (f_Rs)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = current_cpu->h_gr_get (FLD (f_Rdm));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rdm), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (FLD (f_op2m), 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
if (FLD (f_op2m)) {
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 0xfffffffe) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), 0xfffffffe), opval);
  }
} else {
  {
    QI opval = current_cpu->h_gr_get (FLD (f_Rdm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (JOINHISI (current_cpu->h_Rb_get (FLD (f_Rb)), current_cpu->h_gr_get (FLD (f_Rs))), FLD (f_imm12)), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maskgrgr: mask $Rd,$Rs

sem_status
xstormy16_sem_maskgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORHI (ANDHI (current_cpu->h_gr_get (FLD (f_Rd)), INVHI (current_cpu->h_gr_get (FLD (f_Rs)))), ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), current_cpu->h_gr_get (FLD (f_Rs))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maskgrimm16: mask $Rd,#$imm16

sem_status
xstormy16_sem_maskgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), INVSI (FLD (f_imm16))), ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm16)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** pushgr: push $Rd

sem_status
xstormy16_sem_pushgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    HI opval = current_cpu->h_gr_get (FLD (f_Rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** popgr: pop $Rd

sem_status
xstormy16_sem_popgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), -2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    SI opval = current_cpu->GETMEMHI (pc, current_cpu->h_gr_get (((UINT) 15)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swpn: swpn $Rd

sem_status
xstormy16_sem_swpn (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (ORSI (ANDSI (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), 4), 240), ANDSI (SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), 4), 15)), ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 65280));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (0, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swpb: swpb $Rd

sem_status
xstormy16_sem_swpb (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), 8), SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), 8));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swpw: swpw $Rd,$Rs

sem_status
xstormy16_sem_swpw (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_foo;
  tmp_foo = current_cpu->h_gr_get (FLD (f_Rs));
  {
    SI opval = current_cpu->h_gr_get (FLD (f_Rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rs) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rs), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = tmp_foo;
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** andgrgr: and $Rd,$Rs

sem_status
xstormy16_sem_andgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** andimm8: and Rx,#$imm8

sem_status
xstormy16_sem_andimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (current_cpu->h_Rpsw_get (), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** andgrimm16: and $Rd,#$imm16

sem_status
xstormy16_sem_andgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** orgrgr: or $Rd,$Rs

sem_status
xstormy16_sem_orgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** orimm8: or Rx,#$imm8

sem_status
xstormy16_sem_orimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (current_cpu->h_Rpsw_get (), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** orgrimm16: or $Rd,#$imm16

sem_status
xstormy16_sem_orgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xorgrgr: xor $Rd,$Rs

sem_status
xstormy16_sem_xorgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = XORSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xorimm8: xor Rx,#$imm8

sem_status
xstormy16_sem_xorimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = XORHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (current_cpu->h_Rpsw_get (), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xorgrimm16: xor $Rd,#$imm16

sem_status
xstormy16_sem_xorgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_nvalue;
  tmp_nvalue = XORSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** notgr: not $Rd

sem_status
xstormy16_sem_notgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = INVSI (current_cpu->h_gr_get (FLD (f_Rd)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addgrgr: add $Rd,$Rs

sem_status
xstormy16_sem_addgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 0), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addgrimm4: add $Rd,#$imm4

sem_status
xstormy16_sem_addgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), 0), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), 0), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm4), 15), 0), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addimm8: add Rx,#$imm8

sem_status
xstormy16_sem_addimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), 0), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), 0), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 15), ANDSI (FLD (f_imm8), 15), 0), 1), 8), SLLSI (current_cpu->h_Rpsw_get (), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addgrimm16: add $Rd,#$imm16

sem_status
xstormy16_sem_addgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), 0), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), 0), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm16), 15), 0), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** adcgrgr: adc $Rd,$Rs

sem_status
xstormy16_sem_adcgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), current_cpu->h_cy_get ()), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** adcgrimm4: adc $Rd,#$imm4

sem_status
xstormy16_sem_adcgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), current_cpu->h_cy_get ()), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm4), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** adcimm8: adc Rx,#$imm8

sem_status
xstormy16_sem_adcimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), current_cpu->h_cy_get ()), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 15), ANDSI (FLD (f_imm8), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (current_cpu->h_Rpsw_get (), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** adcgrimm16: adc $Rd,#$imm16

sem_status
xstormy16_sem_adcgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = ADDCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (ADDOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), current_cpu->h_cy_get ()), 4), SLLHI (ADDCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (ADDCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm16), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subgrgr: sub $Rd,$Rs

sem_status
xstormy16_sem_subgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 0), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subgrimm4: sub $Rd,#$imm4

sem_status
xstormy16_sem_subgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), 0), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm4), 15), 0), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subimm8: sub Rx,#$imm8

sem_status
xstormy16_sem_subimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), 0), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 15), ANDSI (FLD (f_imm8), 15), 0), 1), 8), SLLSI (current_cpu->h_Rpsw_get (), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subgrimm16: sub $Rd,#$imm16

sem_status
xstormy16_sem_subgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), 0);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), 0), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm16), 15), 0), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcgrgr: sbc $Rd,$Rs

sem_status
xstormy16_sem_sbcgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), current_cpu->h_cy_get ()), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcgrimm4: sbc $Rd,#$imm4

sem_status
xstormy16_sem_sbcgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), current_cpu->h_cy_get ()), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm4), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcgrimm8: sbc Rx,#$imm8

sem_status
xstormy16_sem_sbcgrimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), current_cpu->h_cy_get ()), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm8), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 15), ANDSI (FLD (f_imm8), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (current_cpu->h_Rpsw_get (), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << current_cpu->h_Rpsw_get () << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (current_cpu->h_Rpsw_get (), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcgrimm16: sbc $Rd,#$imm16

sem_status
xstormy16_sem_sbcgrimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_value;
  HI tmp_newpsw;
  tmp_value = SUBCSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), current_cpu->h_cy_get ());
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), current_cpu->h_cy_get ()), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm16), current_cpu->h_cy_get ()), 2)), ORHI (ANDHI (SRLHI (SUBCHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (FLD (f_imm16), 15), current_cpu->h_cy_get ()), 1), 8), SLLSI (FLD (f_Rd), 12))));
  {
    HI opval = tmp_value;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** incgrimm2: inc $Rd,#$imm2

sem_status
xstormy16_sem_incgrimm2 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_incgrimm2.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ADDSI (current_cpu->h_gr_get (FLD (f_Rd)), ADDSI (FLD (f_imm2), 1));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** decgrimm2: dec $Rd,#$imm2

sem_status
xstormy16_sem_decgrimm2 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_incgrimm2.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = SUBSI (current_cpu->h_gr_get (FLD (f_Rd)), ADDSI (FLD (f_imm2), 1));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rrcgrgr: rrc $Rd,$Rs

sem_status
xstormy16_sem_rrcgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_tmpfoo;
  tmp_tmpfoo = ORSI (ORSI (ANDSI (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), 17), 0xfffe0000), current_cpu->h_gr_get (FLD (f_Rd))), SLLSI (current_cpu->h_cy_get (), 16));
  tmp_tmpfoo = RORSI (tmp_tmpfoo, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15));
{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = TRUNCSIHI (tmp_tmpfoo);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (SRLSI (tmp_tmpfoo, 16), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rrcgrimm4: rrc $Rd,#$imm4

sem_status
xstormy16_sem_rrcgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_tmpfoo;
  tmp_tmpfoo = ORSI (ORSI (ANDSI (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), 17), 0xfffe0000), current_cpu->h_gr_get (FLD (f_Rd))), SLLSI (current_cpu->h_cy_get (), 16));
  tmp_tmpfoo = RORSI (tmp_tmpfoo, ANDSI (FLD (f_imm4), 15));
{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = TRUNCSIHI (tmp_tmpfoo);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (SRLSI (tmp_tmpfoo, 16), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rlcgrgr: rlc $Rd,$Rs

sem_status
xstormy16_sem_rlcgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_tmpfoo;
  tmp_tmpfoo = ORSI (ORSI (ANDSI (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), 2147352576), current_cpu->h_gr_get (FLD (f_Rd))), ORSI (SLLSI (current_cpu->h_cy_get (), 31), SLLSI (current_cpu->h_cy_get (), 16)));
  tmp_tmpfoo = ROLSI (tmp_tmpfoo, ANDSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 31));
{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = TRUNCSIHI (tmp_tmpfoo);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (SRLSI (tmp_tmpfoo, 16), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rlcgrimm4: rlc $Rd,#$imm4

sem_status
xstormy16_sem_rlcgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_tmpfoo;
  tmp_tmpfoo = ORSI (ORSI (ANDSI (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), 2147352576), current_cpu->h_gr_get (FLD (f_Rd))), ORSI (SLLSI (current_cpu->h_cy_get (), 31), SLLSI (current_cpu->h_cy_get (), 16)));
  tmp_tmpfoo = ROLSI (tmp_tmpfoo, ANDSI (FLD (f_imm4), 31));
{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = TRUNCSIHI (tmp_tmpfoo);
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (SRLSI (tmp_tmpfoo, 16), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shrgrgr: shr $Rd,$Rs

sem_status
xstormy16_sem_shrgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15));
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (((EQSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 0)) ? (current_cpu->h_cy_get ()) : (SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), SUBSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 1)))), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shrgrimm: shr $Rd,#$imm4

sem_status
xstormy16_sem_shrgrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4));
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (((EQSI (FLD (f_imm4), 0)) ? (current_cpu->h_cy_get ()) : (SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), SUBSI (FLD (f_imm4), 1)))), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shlgrgr: shl $Rd,$Rs

sem_status
xstormy16_sem_shlgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15));
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (SRLSI (((EQSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 0)) ? (SLLSI (current_cpu->h_cy_get (), 15)) : (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), SUBSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 1)))), 15), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shlgrimm: shl $Rd,#$imm4

sem_status
xstormy16_sem_shlgrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4));
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (SRLSI (((EQSI (FLD (f_imm4), 0)) ? (SLLSI (current_cpu->h_cy_get (), 15)) : (SLLSI (current_cpu->h_gr_get (FLD (f_Rd)), SUBSI (FLD (f_imm4), 1)))), 15), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** asrgrgr: asr $Rd,$Rs

sem_status
xstormy16_sem_asrgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = SRAHI (current_cpu->h_gr_get (FLD (f_Rd)), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15));
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (((EQSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 0)) ? (current_cpu->h_cy_get ()) : (SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), SUBSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15), 1)))), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** asrgrimm: asr $Rd,#$imm4

sem_status
xstormy16_sem_asrgrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  HI tmp_newpsw;
  tmp_nvalue = SRAHI (current_cpu->h_gr_get (FLD (f_Rd)), FLD (f_imm4));
  tmp_newpsw = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3992), SLLSI (ANDSI (ANDSI (((EQSI (FLD (f_imm4), 0)) ? (current_cpu->h_cy_get ()) : (SRLSI (current_cpu->h_gr_get (FLD (f_Rd)), SUBSI (FLD (f_imm4), 1)))), 1), 1), 2)), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = tmp_newpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** set1grimm: set1 $Rd,#$imm4

sem_status
xstormy16_sem_set1grimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (current_cpu->h_gr_get (FLD (f_Rd)), SLLSI (1, FLD (f_imm4)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** set1grgr: set1 $Rd,$Rs

sem_status
xstormy16_sem_set1grgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (current_cpu->h_gr_get (FLD (f_Rd)), SLLSI (1, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15)));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** set1lmemimm: set1 $lmem8,#$imm3

sem_status
xstormy16_sem_set1lmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_set1lmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORQI (current_cpu->GETMEMQI (pc, FLD (f_lmem8)), SLLSI (1, FLD (f_imm3)));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (0, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_lmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_lmem8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** set1hmemimm: set1 $hmem8,#$imm3

sem_status
xstormy16_sem_set1hmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_set1hmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORQI (current_cpu->GETMEMQI (pc, FLD (f_hmem8)), SLLSI (1, FLD (f_imm3)));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (0, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_hmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_hmem8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clr1grimm: clr1 $Rd,#$imm4

sem_status
xstormy16_sem_clr1grimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), INVSI (SLLSI (1, FLD (f_imm4))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clr1grgr: clr1 $Rd,$Rs

sem_status
xstormy16_sem_clr1grgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), INVSI (SLLSI (1, ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clr1lmemimm: clr1 $lmem8,#$imm3

sem_status
xstormy16_sem_clr1lmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_set1lmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDQI (current_cpu->GETMEMQI (pc, FLD (f_lmem8)), INVSI (SLLSI (1, FLD (f_imm3))));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (0, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_lmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_lmem8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clr1hmemimm: clr1 $hmem8,#$imm3

sem_status
xstormy16_sem_clr1hmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_set1hmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ANDQI (current_cpu->GETMEMQI (pc, FLD (f_hmem8)), INVSI (SLLSI (1, FLD (f_imm3))));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (0, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    QI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) FLD (f_hmem8) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, FLD (f_hmem8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cbwgr: cbw $Rd

sem_status
xstormy16_sem_cbwgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = EXTQIHI (TRUNCSIQI (current_cpu->h_gr_get (FLD (f_Rd))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** revgr: rev $Rd

sem_status
xstormy16_sem_revgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_nvalue;
  tmp_nvalue = ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 1), 15), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 2), 13), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 4), 11), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 8), 9), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 16), 7), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 32), 5), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 64), 3), ORSI (SLLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 128), 1), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 256), 1), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 512), 3), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 1024), 5), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 2048), 7), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 4096), 9), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 8192), 11), ORSI (SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 16384), 13), SRLSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 32768), 15))))))))))))))));
  {
    HI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_Rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_Rd), opval);
  }
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3996), ORSI (SLLSI (FLD (f_Rd), 12), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bccgrgr: b$bcond5 $Rd,$Rs,$rel12

sem_status
xstormy16_sem_bccgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
{
  HI tmp_value;
  tmp_value = SUBSI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)));
  {
    SI opval = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rd)), current_cpu->h_gr_get (FLD (f_Rs)), 0), 2)), ORHI (ANDHI (SRLHI (SUBHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), 15), ANDSI (current_cpu->h_gr_get (FLD (f_Rs)), 15)), 1), 8), SLLSI (FLD (f_Rd), 12))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
{
  BI tmp_tmp;
  switch (FLD (f_op5))
  {
  case 0 : {
  tmp_tmp = NOTSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()));
}
    break;
  case 1 : {
  tmp_tmp = NOTSI (current_cpu->h_cy_get ());
}
    break;
  case 2 : {
  tmp_tmp = XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ());
}
    break;
  case 3 : {
  tmp_tmp = current_cpu->h_cy_get ();
}
    break;
  case 4 : {
  tmp_tmp = NOTSI (ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ()));
}
    break;
  case 5 : {
  tmp_tmp = NOTSI (ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ()));
}
    break;
  case 6 : {
  tmp_tmp = ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ());
}
    break;
  case 7 : {
  tmp_tmp = ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ());
}
    break;
  case 8 : {
  tmp_tmp = NOTSI (current_cpu->h_s_get ());
}
    break;
  case 9 : {
  tmp_tmp = NOTSI (current_cpu->h_ov_get ());
}
    break;
  case 10 : {
  tmp_tmp = current_cpu->h_s_get ();
}
    break;
  case 11 : {
  tmp_tmp = current_cpu->h_ov_get ();
}
    break;
  case 12 : {
  tmp_tmp = NOTSI (current_cpu->h_z8_get ());
}
    break;
  case 13 : {
  tmp_tmp = NOTSI (current_cpu->h_z16_get ());
}
    break;
  case 14 : {
  tmp_tmp = current_cpu->h_z8_get ();
}
    break;
  case 15 : {
  tmp_tmp = current_cpu->h_z16_get ();
}
    break;
  }
if (tmp_tmp) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bccgrimm8: b$bcond5 $Rm,#$imm8,$rel12

sem_status
xstormy16_sem_bccgrimm8 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
{
  HI tmp_value;
  tmp_value = SUBSI (current_cpu->h_gr_get (FLD (f_Rm)), FLD (f_imm8));
  {
    SI opval = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (FLD (f_Rm)), FLD (f_imm8), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (FLD (f_Rm)), FLD (f_imm8), 0), 2)), ORHI (ANDHI (SRLHI (SUBHI (ANDSI (current_cpu->h_gr_get (FLD (f_Rm)), 15), ANDSI (FLD (f_imm8), 15)), 1), 8), SLLSI (FLD (f_Rm), 12))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
{
  BI tmp_tmp;
  switch (FLD (f_op5))
  {
  case 0 : {
  tmp_tmp = NOTSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()));
}
    break;
  case 1 : {
  tmp_tmp = NOTSI (current_cpu->h_cy_get ());
}
    break;
  case 2 : {
  tmp_tmp = XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ());
}
    break;
  case 3 : {
  tmp_tmp = current_cpu->h_cy_get ();
}
    break;
  case 4 : {
  tmp_tmp = NOTSI (ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ()));
}
    break;
  case 5 : {
  tmp_tmp = NOTSI (ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ()));
}
    break;
  case 6 : {
  tmp_tmp = ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ());
}
    break;
  case 7 : {
  tmp_tmp = ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ());
}
    break;
  case 8 : {
  tmp_tmp = NOTSI (current_cpu->h_s_get ());
}
    break;
  case 9 : {
  tmp_tmp = NOTSI (current_cpu->h_ov_get ());
}
    break;
  case 10 : {
  tmp_tmp = current_cpu->h_s_get ();
}
    break;
  case 11 : {
  tmp_tmp = current_cpu->h_ov_get ();
}
    break;
  case 12 : {
  tmp_tmp = NOTSI (current_cpu->h_z8_get ());
}
    break;
  case 13 : {
  tmp_tmp = NOTSI (current_cpu->h_z16_get ());
}
    break;
  case 14 : {
  tmp_tmp = current_cpu->h_z8_get ();
}
    break;
  case 15 : {
  tmp_tmp = current_cpu->h_z16_get ();
}
    break;
  }
if (tmp_tmp) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bccimm16: b$bcond2 Rx,#$imm16,${rel8-4}

sem_status
xstormy16_sem_bccimm16 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccimm16.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
{
  HI tmp_value;
  tmp_value = SUBHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm16));
  {
    SI opval = ORSI (ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 3968), ORBI (ORBI (EQHI (ANDHI (tmp_value, 255), 0), SLLHI (EQHI (tmp_value, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_value), 5), SLLHI (LTQI (SRLHI (tmp_value, MULSI (1, 8)), 0), 6)))), ORHI (ORHI (SLLHI (SUBOFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm16), 0), 4), SLLHI (SUBCFHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), FLD (f_imm16), 0), 2)), ORHI (ANDHI (SRLHI (SUBHI (ANDHI (current_cpu->h_gr_get (current_cpu->h_Rpsw_get ()), 15), ANDSI (FLD (f_imm16), 15)), 1), 8), SLLSI (current_cpu->h_Rpsw_get (), 12))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}
{
  BI tmp_tmp;
  switch (FLD (f_op2))
  {
  case 0 : {
  tmp_tmp = NOTSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()));
}
    break;
  case 1 : {
  tmp_tmp = NOTSI (current_cpu->h_cy_get ());
}
    break;
  case 2 : {
  tmp_tmp = XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ());
}
    break;
  case 3 : {
  tmp_tmp = current_cpu->h_cy_get ();
}
    break;
  case 4 : {
  tmp_tmp = NOTSI (ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ()));
}
    break;
  case 5 : {
  tmp_tmp = NOTSI (ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ()));
}
    break;
  case 6 : {
  tmp_tmp = ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ());
}
    break;
  case 7 : {
  tmp_tmp = ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ());
}
    break;
  case 8 : {
  tmp_tmp = NOTSI (current_cpu->h_s_get ());
}
    break;
  case 9 : {
  tmp_tmp = NOTSI (current_cpu->h_ov_get ());
}
    break;
  case 10 : {
  tmp_tmp = current_cpu->h_s_get ();
}
    break;
  case 11 : {
  tmp_tmp = current_cpu->h_ov_get ();
}
    break;
  case 12 : {
  tmp_tmp = NOTSI (current_cpu->h_z8_get ());
}
    break;
  case 13 : {
  tmp_tmp = NOTSI (current_cpu->h_z16_get ());
}
    break;
  case 14 : {
  tmp_tmp = current_cpu->h_z8_get ();
}
    break;
  case 15 : {
  tmp_tmp = current_cpu->h_z16_get ();
}
    break;
  }
if (tmp_tmp) {
  {
    USI opval = FLD (f_rel8_4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bngrimm4: bn $Rd,#$imm4,$rel12

sem_status
xstormy16_sem_bngrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = FLD (f_Rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "Rpsw" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_Rpsw_set (opval);
  }
if (EQSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), SLLSI (1, FLD (f_imm4))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bngrgr: bn $Rd,$Rs,$rel12

sem_status
xstormy16_sem_bngrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = FLD (f_Rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "Rpsw" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_Rpsw_set (opval);
  }
if (EQSI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), SLLSI (1, current_cpu->h_gr_get (FLD (f_Rs)))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnlmemimm: bn $lmem8,#$imm3b,$rel12

sem_status
xstormy16_sem_bnlmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bnlmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQQI (ANDQI (current_cpu->GETMEMQI (pc, FLD (f_lmem8)), SLLSI (1, FLD (f_imm3b))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnhmemimm: bn $hmem8,#$imm3b,$rel12

sem_status
xstormy16_sem_bnhmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bnhmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQQI (ANDQI (current_cpu->GETMEMQI (pc, FLD (f_hmem8)), SLLSI (1, FLD (f_imm3b))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bpgrimm4: bp $Rd,#$imm4,$rel12

sem_status
xstormy16_sem_bpgrimm4 (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = FLD (f_Rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "Rpsw" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_Rpsw_set (opval);
  }
if (NESI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), SLLSI (1, FLD (f_imm4))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bpgrgr: bp $Rd,$Rs,$rel12

sem_status
xstormy16_sem_bpgrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = FLD (f_Rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "Rpsw" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_Rpsw_set (opval);
  }
if (NESI (ANDSI (current_cpu->h_gr_get (FLD (f_Rd)), SLLSI (1, current_cpu->h_gr_get (FLD (f_Rs)))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bplmemimm: bp $lmem8,#$imm3b,$rel12

sem_status
xstormy16_sem_bplmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bnlmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NEQI (ANDQI (current_cpu->GETMEMQI (pc, FLD (f_lmem8)), SLLSI (1, FLD (f_imm3b))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bphmemimm: bp $hmem8,#$imm3b,$rel12

sem_status
xstormy16_sem_bphmemimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bnhmemimm.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NEQI (ANDQI (current_cpu->GETMEMQI (pc, FLD (f_hmem8)), SLLSI (1, FLD (f_imm3b))), 0)) {
  {
    USI opval = FLD (f_rel12);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcc: b$bcond2 ${rel8-2}

sem_status
xstormy16_sem_bcc (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bcc.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_tmp;
  switch (FLD (f_op2))
  {
  case 0 : {
  tmp_tmp = NOTSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()));
}
    break;
  case 1 : {
  tmp_tmp = NOTSI (current_cpu->h_cy_get ());
}
    break;
  case 2 : {
  tmp_tmp = XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ());
}
    break;
  case 3 : {
  tmp_tmp = current_cpu->h_cy_get ();
}
    break;
  case 4 : {
  tmp_tmp = NOTSI (ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ()));
}
    break;
  case 5 : {
  tmp_tmp = NOTSI (ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ()));
}
    break;
  case 6 : {
  tmp_tmp = ORSI (XORSI (current_cpu->h_s_get (), current_cpu->h_ov_get ()), current_cpu->h_z16_get ());
}
    break;
  case 7 : {
  tmp_tmp = ORSI (current_cpu->h_cy_get (), current_cpu->h_z16_get ());
}
    break;
  case 8 : {
  tmp_tmp = NOTSI (current_cpu->h_s_get ());
}
    break;
  case 9 : {
  tmp_tmp = NOTSI (current_cpu->h_ov_get ());
}
    break;
  case 10 : {
  tmp_tmp = current_cpu->h_s_get ();
}
    break;
  case 11 : {
  tmp_tmp = current_cpu->h_ov_get ();
}
    break;
  case 12 : {
  tmp_tmp = NOTSI (current_cpu->h_z8_get ());
}
    break;
  case 13 : {
  tmp_tmp = NOTSI (current_cpu->h_z16_get ());
}
    break;
  case 14 : {
  tmp_tmp = current_cpu->h_z8_get ();
}
    break;
  case 15 : {
  tmp_tmp = current_cpu->h_z16_get ();
}
    break;
  }
if (tmp_tmp) {
  {
    USI opval = FLD (f_rel8_2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bgr: br $Rd

sem_status
xstormy16_sem_bgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = ADDSI (ADDSI (pc, 2), current_cpu->h_gr_get (FLD (f_Rd)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** br: br $rel12a

sem_status
xstormy16_sem_br (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_br.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = FLD (f_rel12a);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** jmp: jmp $Rbj,$Rd

sem_status
xstormy16_sem_jmp (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = JOINHISI (current_cpu->h_Rbj_get (FLD (f_Rbj)), current_cpu->h_gr_get (FLD (f_Rd)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** jmpf: jmpf $abs24

sem_status
xstormy16_sem_jmpf (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmpf.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    USI opval = FLD (f_abs24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** callrgr: callr $Rd

sem_status
xstormy16_sem_callrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rd)), ADDSI (pc, 2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** callrimm: callr $rel12a

sem_status
xstormy16_sem_callrimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_br.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = FLD (f_rel12a);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** callgr: call $Rbj,$Rd

sem_status
xstormy16_sem_callgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = JOINHISI (current_cpu->h_Rbj_get (FLD (f_Rbj)), current_cpu->h_gr_get (FLD (f_Rd)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** callfimm: callf $abs24

sem_status
xstormy16_sem_callfimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmpf.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = ADDSI (pc, 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = FLD (f_abs24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** icallrgr: icallr $Rd

sem_status
xstormy16_sem_icallrgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    HI opval = current_cpu->h_gr_get (((UINT) 14));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = ADDSI (current_cpu->h_gr_get (FLD (f_Rd)), ADDSI (pc, 2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** icallgr: icall $Rbj,$Rd

sem_status
xstormy16_sem_icallgr (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    HI opval = current_cpu->h_gr_get (((UINT) 14));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = JOINHISI (current_cpu->h_Rbj_get (FLD (f_Rbj)), current_cpu->h_gr_get (FLD (f_Rd)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** icallfimm: icallf $abs24

sem_status
xstormy16_sem_icallfimm (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmpf.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = ADDSI (pc, 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_gr_get (((UINT) 15)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)), opval);
  }
  {
    HI opval = current_cpu->h_gr_get (((UINT) 14));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_gr_get (((UINT) 15)), 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = FLD (f_abs24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** iret: iret

sem_status
xstormy16_sem_iret (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (((UINT) 15)), 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = current_cpu->GETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = current_cpu->GETMEMHI (pc, ADDSI (current_cpu->h_gr_get (((UINT) 15)), 4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ret: ret

sem_status
xstormy16_sem_ret (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->h_gr_get (((UINT) 15)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 15) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 15), opval);
  }
  {
    USI opval = current_cpu->GETMEMSI (pc, current_cpu->h_gr_get (((UINT) 15)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mul: mul

sem_status
xstormy16_sem_mul (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_value;
  tmp_value = MULSI (ANDSI (current_cpu->h_gr_get (((UINT) 0)), 65535), ANDSI (current_cpu->h_gr_get (((UINT) 2)), 65535));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (TRUNCSIHI (tmp_value), 255), 0), SLLHI (EQHI (TRUNCSIHI (tmp_value), 0), 1)), ORHI (SLLHI (current_cpu->parity (TRUNCSIHI (tmp_value)), 5), SLLHI (LTQI (SRLHI (TRUNCSIHI (tmp_value), MULSI (1, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    SI opval = TRUNCSIHI (tmp_value);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 0), opval);
  }
  {
    SI opval = TRUNCSIHI (SRLSI (tmp_value, 16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 1), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** div: div

sem_status
xstormy16_sem_div (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = UMODSI (current_cpu->h_gr_get (((UINT) 0)), current_cpu->h_gr_get (((UINT) 2)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 1), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = UDIVSI (current_cpu->h_gr_get (((UINT) 0)), current_cpu->h_gr_get (((UINT) 2)));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    SI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 0), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sdiv: sdiv

sem_status
xstormy16_sem_sdiv (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = MODHI (current_cpu->h_gr_get (((UINT) 0)), current_cpu->h_gr_get (((UINT) 2)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 1), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = DIVHI (current_cpu->h_gr_get (((UINT) 0)), current_cpu->h_gr_get (((UINT) 2)));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    SI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 0), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sdivlh: sdivlh

sem_status
xstormy16_sem_sdivlh (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_value;
  tmp_value = ADDSI (SLLSI (ANDSI (current_cpu->h_gr_get (((UINT) 1)), 65535), 16), ANDSI (current_cpu->h_gr_get (((UINT) 0)), 65535));
  {
    SI opval = MODSI (tmp_value, EXTHISI (TRUNCSIHI (current_cpu->h_gr_get (((UINT) 2)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 1), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = DIVSI (tmp_value, EXTHISI (TRUNCSIHI (current_cpu->h_gr_get (((UINT) 2)))));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    SI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 0), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** divlh: divlh

sem_status
xstormy16_sem_divlh (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_value;
  tmp_value = ADDSI (SLLSI (ANDSI (current_cpu->h_gr_get (((UINT) 1)), 65535), 16), ANDSI (current_cpu->h_gr_get (((UINT) 0)), 65535));
  {
    SI opval = UMODSI (tmp_value, current_cpu->h_gr_get (((UINT) 2)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 1), opval);
  }
{
  HI tmp_nvalue;
  tmp_nvalue = UDIVSI (tmp_value, current_cpu->h_gr_get (((UINT) 2)));
  {
    SI opval = ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 65436), ORBI (ORBI (EQHI (ANDHI (tmp_nvalue, 255), 0), SLLHI (EQHI (tmp_nvalue, 0), 1)), ORHI (SLLHI (current_cpu->parity (tmp_nvalue), 5), SLLHI (LTQI (SRLHI (tmp_nvalue, MULSI (1, 8)), 0), 6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 14), opval);
  }
  {
    SI opval = tmp_nvalue;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (((UINT) 0), opval);
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** reset: reset

sem_status
xstormy16_sem_reset (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** nop: nop

sem_status
xstormy16_sem_nop (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** halt: halt

sem_status
xstormy16_sem_halt (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_halt ();

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** hold: hold

sem_status
xstormy16_sem_hold (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_hold ();

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** holdx: holdx

sem_status
xstormy16_sem_holdx (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_holdx ();

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** brk: brk

sem_status
xstormy16_sem_brk (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_brk ();

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** syscall: --unused--

sem_status
xstormy16_sem_syscall (xstormy16_cpu* current_cpu, xstormy16_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  xstormy16_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->syscall ();

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

