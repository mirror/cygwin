/* Simulator instruction semantics for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_basic.h"

using namespace mep_basic; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

sem_status
mep_sem_x_invalid (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
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

// ********** stcb_r: stcb $rn,($rma)

sem_status
mep_sem_stcb_r (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stcb_r.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_stcb (* FLD (i_rn), ANDSI (* FLD (i_rma), 65535));

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldcb_r: ldcb $rn,($rma)

sem_status
mep_sem_ldcb_r (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->do_ldcb (ANDSI (* FLD (i_rma), 65535));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** pref: pref $cimm4,($rma)

sem_status
mep_sem_pref (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_dcache (pc);
current_cpu->do_cache_prefetch (FLD (f_rn), * FLD (i_rma), pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** prefd: pref $cimm4,$sdisp16($rma)

sem_status
mep_sem_prefd (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_dcache (pc);
current_cpu->do_cache_prefetch (FLD (f_rn), ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** casb3: casb3 $rl5,$rn,($rm)

sem_status
mep_sem_casb3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->do_casb3 (FLD (f_rl5), * FLD (i_rn), * FLD (i_rm), pc);
  {
    SI opval = * FLD (i_rl5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rl5) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rl5) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cash3: cash3 $rl5,$rn,($rm)

sem_status
mep_sem_cash3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->do_cash3 (FLD (f_rl5), * FLD (i_rn), * FLD (i_rm), pc);
  {
    SI opval = * FLD (i_rl5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rl5) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rl5) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** casw3: casw3 $rl5,$rn,($rm)

sem_status
mep_sem_casw3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_casb3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->do_casw3 (FLD (f_rl5), * FLD (i_rn), * FLD (i_rm), pc);
  {
    SI opval = * FLD (i_rl5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rl5) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rl5) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcp: sbcp $crn,$cdisp12($rma)

sem_status
mep_sem_sbcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20))));
  {
    QI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20))) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20))), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbcp: lbcp $crn,$cdisp12($rma)

sem_status
mep_sem_lbcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbucp: lbucp $crn,$cdisp12($rma)

sem_status
mep_sem_lbucp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shcp: shcp $crn,$cdisp12($rma)

sem_status
mep_sem_shcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20))));
  {
    HI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20))), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhcp: lhcp $crn,$cdisp12($rma)

sem_status
mep_sem_lhcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhucp: lhucp $crn,$cdisp12($rma)

sem_status
mep_sem_lhucp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sbcp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_12s20)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbucpa: lbucpa $crn,($rma+),$cdisp10

sem_status
mep_sem_lbucpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), FLD (f_cdisp10));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhucpa: lhucpa $crn,($rma+),$cdisp10a2

sem_status
mep_sem_lhucpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbucpm0: lbucpm0 $crn,($rma+),$cdisp10

sem_status
mep_sem_lbucpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhucpm0: lhucpm0 $crn,($rma+),$cdisp10a2

sem_status
mep_sem_lhucpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbucpm1: lbucpm1 $crn,($rma+),$cdisp10

sem_status
mep_sem_lbucpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhucpm1: lhucpm1 $crn,($rma+),$cdisp10a2

sem_status
mep_sem_lhucpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** uci: uci $rn,$rm,$uimm16

sem_status
mep_sem_uci (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->do_UCI (* FLD (i_rn), * FLD (i_rm), ZEXTSISI (FLD (f_16u16)), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** dsp: dsp $rn,$rm,$uimm16

sem_status
mep_sem_dsp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->do_DSP (* FLD (i_rn), * FLD (i_rm), ZEXTSISI (FLD (f_16u16)), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sb: sb $rnc,($rma)

sem_status
mep_sem_sb (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (* FLD (i_rma));
  {
    UQI opval = ANDSI (* FLD (i_rnc), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, * FLD (i_rma), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sh: sh $rns,($rma)

sem_status
mep_sem_sh (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (1)));
  {
    UHI opval = ANDSI (* FLD (i_rns), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (1)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUHI (pc, ANDSI (* FLD (i_rma), INVSI (1)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sw: sw $rnl,($rma)

sem_status
mep_sem_sw (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (3)));
  {
    USI opval = * FLD (i_rnl);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUSI (pc, ANDSI (* FLD (i_rma), INVSI (3)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lb: lb $rnc,($rma)

sem_status
mep_sem_lb (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnc) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lh: lh $rns,($rma)

sem_status
mep_sem_lh (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rns) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lw: lw $rnl,($rma)

sem_status
mep_sem_lw (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnl) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbu: lbu $rnuc,($rma)

sem_status
mep_sem_lbu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMUQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnuc) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhu: lhu $rnus,($rma)

sem_status
mep_sem_lhu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMUHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnus) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sw-sp: sw $rnl,$udisp7a4($spr)

sem_status
mep_sem_sw_sp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sw_sp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (ANDSI (ADDSI (FLD (f_7u9a4), current_cpu->hardware.h_gpr[((UINT) 15)]), INVSI (3)));
  {
    SI opval = * FLD (i_rnl);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (FLD (f_7u9a4), current_cpu->hardware.h_gpr[((UINT) 15)]), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (ADDSI (FLD (f_7u9a4), current_cpu->hardware.h_gpr[((UINT) 15)]), INVSI (3)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lw-sp: lw $rnl,$udisp7a4($spr)

sem_status
mep_sem_lw_sp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lw_sp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (ADDSI (FLD (f_7u9a4), current_cpu->hardware.h_gpr[((UINT) 15)]), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnl) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sb-tp: sb $rn3c,$udisp7($tpr)

sem_status
mep_sem_sb_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sb_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (ADDSI (ZEXTSISI (FLD (f_7u9)), current_cpu->hardware.h_gpr[((UINT) 13)]));
  {
    QI opval = ANDSI (* FLD (i_rn3c), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (ZEXTSISI (FLD (f_7u9)), current_cpu->hardware.h_gpr[((UINT) 13)]) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (ZEXTSISI (FLD (f_7u9)), current_cpu->hardware.h_gpr[((UINT) 13)]), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sh-tp: sh $rn3s,$udisp7a2($tpr)

sem_status
mep_sem_sh_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sh_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a2)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (1)));
  {
    HI opval = ANDSI (* FLD (i_rn3s), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a2)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (1)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a2)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (1)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sw-tp: sw $rn3l,$udisp7a4($tpr)

sem_status
mep_sem_sw_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sw_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_write_to_text (ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a4)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (3)));
  {
    SI opval = * FLD (i_rn3l);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a4)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a4)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (3)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lb-tp: lb $rn3c,$udisp7($tpr)

sem_status
mep_sem_lb_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lb_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (ZEXTSISI (FLD (f_7u9)), current_cpu->hardware.h_gpr[((UINT) 13)])));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn3) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn3c) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lh-tp: lh $rn3s,$udisp7a2($tpr)

sem_status
mep_sem_lh_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lh_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a2)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn3) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn3s) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lw-tp: lw $rn3l,$udisp7a4($tpr)

sem_status
mep_sem_lw_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lw_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a4)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn3) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn3l) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbu-tp: lbu $rn3uc,$udisp7($tpr)

sem_status
mep_sem_lbu_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (ZEXTSISI (FLD (f_7u9)), current_cpu->hardware.h_gpr[((UINT) 13)])));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn3) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn3uc) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhu-tp: lhu $rn3us,$udisp7a2($tpr)

sem_status
mep_sem_lhu_tp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ANDSI (ADDSI (ZEXTSISI (FLD (f_7u9a2)), current_cpu->hardware.h_gpr[((UINT) 13)]), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn3) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn3us) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sb16: sb $rnc,$sdisp16($rma)

sem_status
mep_sem_sb16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sb16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_write_to_text (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))));
  {
    QI opval = ANDSI (* FLD (i_rnc), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sh16: sh $rns,$sdisp16($rma)

sem_status
mep_sem_sh16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sh16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_write_to_text (ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (1)));
  {
    HI opval = ANDSI (* FLD (i_rns), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (1)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (1)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sw16: sw $rnl,$sdisp16($rma)

sem_status
mep_sem_sw16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sw16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_write_to_text (ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (3)));
  {
    SI opval = * FLD (i_rnl);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (3)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lb16: lb $rnc,$sdisp16($rma)

sem_status
mep_sem_lb16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lb16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnc) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lh16: lh $rns,$sdisp16($rma)

sem_status
mep_sem_lh16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lh16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rns) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lw16: lw $rnl,$sdisp16($rma)

sem_status
mep_sem_lw16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lw16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnl) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbu16: lbu $rnuc,$sdisp16($rma)

sem_status
mep_sem_lbu16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbu16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnuc) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhu16: lhu $rnus,$sdisp16($rma)

sem_status
mep_sem_lhu16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lhu16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ANDSI (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_16s16))), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnus) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sw24: sw $rnl,($addr24a4)

sem_status
mep_sem_sw24 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sw24.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_write_to_text (ZEXTSISI (FLD (f_24u8a4n)));
  {
    SI opval = * FLD (i_rnl);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ZEXTSISI (FLD (f_24u8a4n)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ZEXTSISI (FLD (f_24u8a4n)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lw24: lw $rnl,($addr24a4)

sem_status
mep_sem_lw24 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lw24.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->GETMEMSI (pc, ZEXTSISI (FLD (f_24u8a4n)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rnl) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** extb: extb $rn

sem_status
mep_sem_extb (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (ANDQI (* FLD (i_rn), 255));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** exth: exth $rn

sem_status
mep_sem_exth (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (ANDHI (* FLD (i_rn), 65535));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** extub: extub $rn

sem_status
mep_sem_extub (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTSISI (ANDSI (* FLD (i_rn), 255));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** extuh: extuh $rn

sem_status
mep_sem_extuh (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTSISI (ANDSI (* FLD (i_rn), 65535));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ssarb: ssarb $udisp2($rm)

sem_status
mep_sem_ssarb (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ssarb.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->big_endian_p ()) {
  {
    SI opval = ZEXTSISI (MULSI (ANDSI (ADDSI (FLD (f_2u6), * FLD (i_rm)), 3), 8));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 2), opval);
  }
} else {
  {
    SI opval = SUBSI (32, ZEXTSISI (MULSI (ANDSI (ADDSI (FLD (f_2u6), * FLD (i_rm)), 3), 8)));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 2), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov: mov $rn,$rm

sem_status
mep_sem_mov (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movi8: mov $rn,$simm8

sem_status
mep_sem_movi8 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movi8.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTSISI (FLD (f_8s8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movi16: mov $rn,$simm16

sem_status
mep_sem_movi16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = EXTSISI (FLD (f_16s16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movu24: movu $rn3,$uimm24

sem_status
mep_sem_movu24 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_movu24.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ZEXTSISI (FLD (f_24u8n));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn3) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn3) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movu16: movu $rn,$uimm16

sem_status
mep_sem_movu16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ZEXTSISI (FLD (f_16u16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** movh: movh $rn,$uimm16

sem_status
mep_sem_movh (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SLLSI (FLD (f_16u16), 16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add3: add3 $rl,$rn,$rm

sem_status
mep_sem_add3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (* FLD (i_rn), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rl) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rl) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add: add $rn,$simm6

sem_status
mep_sem_add (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (* FLD (i_rn), EXTSISI (FLD (f_6s8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add3i: add3 $rn,$spr,$uimm7a4

sem_status
mep_sem_add3i (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3i.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (current_cpu->hardware.h_gpr[((UINT) 15)], ZEXTSISI (FLD (f_7u9a4)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** advck3: advck3 \$0,$rn,$rm

sem_status
mep_sem_advck3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (ADDOFSI (* FLD (i_rn), * FLD (i_rm), 0)) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub: sub $rn,$rm

sem_status
mep_sem_sub (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SUBSI (* FLD (i_rn), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbvck3: sbvck3 \$0,$rn,$rm

sem_status
mep_sem_sbvck3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (SUBOFSI (* FLD (i_rn), * FLD (i_rm), 0)) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** neg: neg $rn,$rm

sem_status
mep_sem_neg (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = NEGSI (* FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** slt3: slt3 \$0,$rn,$rm

sem_status
mep_sem_slt3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (LTSI (* FLD (i_rn), * FLD (i_rm))) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sltu3: sltu3 \$0,$rn,$rm

sem_status
mep_sem_sltu3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (LTUSI (* FLD (i_rn), * FLD (i_rm))) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** slt3i: slt3 \$0,$rn,$uimm5

sem_status
mep_sem_slt3i (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (LTSI (* FLD (i_rn), ZEXTSISI (FLD (f_5u8)))) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sltu3i: sltu3 \$0,$rn,$uimm5

sem_status
mep_sem_sltu3i (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (LTUSI (* FLD (i_rn), ZEXTSISI (FLD (f_5u8)))) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sl1ad3: sl1ad3 \$0,$rn,$rm

sem_status
mep_sem_sl1ad3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (SLLSI (* FLD (i_rn), 1), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sl2ad3: sl2ad3 \$0,$rn,$rm

sem_status
mep_sem_sl2ad3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_advck3.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (SLLSI (* FLD (i_rn), 2), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add3x: add3 $rn,$rm,$simm16

sem_status
mep_sem_add3x (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ADDSI (* FLD (i_rm), EXTSISI (FLD (f_16s16)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** slt3x: slt3 $rn,$rm,$simm16

sem_status
mep_sem_slt3x (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (LTSI (* FLD (i_rm), EXTSISI (FLD (f_16s16)))) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sltu3x: sltu3 $rn,$rm,$uimm16

sem_status
mep_sem_sltu3x (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (LTUSI (* FLD (i_rm), ZEXTSISI (FLD (f_16u16)))) {
  {
    SI opval = 1;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** or: or $rn,$rm

sem_status
mep_sem_or (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ORSI (* FLD (i_rn), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** and: and $rn,$rm

sem_status
mep_sem_and (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ANDSI (* FLD (i_rn), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xor: xor $rn,$rm

sem_status
mep_sem_xor (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = XORSI (* FLD (i_rn), * FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** nor: nor $rn,$rm

sem_status
mep_sem_nor (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = INVSI (ORSI (* FLD (i_rn), * FLD (i_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** or3: or3 $rn,$rm,$uimm16

sem_status
mep_sem_or3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ORSI (* FLD (i_rm), ZEXTSISI (FLD (f_16u16)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** and3: and3 $rn,$rm,$uimm16

sem_status
mep_sem_and3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ANDSI (* FLD (i_rm), ZEXTSISI (FLD (f_16u16)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xor3: xor3 $rn,$rm,$uimm16

sem_status
mep_sem_xor3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = XORSI (* FLD (i_rm), ZEXTSISI (FLD (f_16u16)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sra: sra $rn,$rm

sem_status
mep_sem_sra (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRASI (* FLD (i_rn), ANDSI (* FLD (i_rm), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srl: srl $rn,$rm

sem_status
mep_sem_srl (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (* FLD (i_rn), ANDSI (* FLD (i_rm), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sll: sll $rn,$rm

sem_status
mep_sem_sll (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (* FLD (i_rn), ANDSI (* FLD (i_rm), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srai: sra $rn,$uimm5

sem_status
mep_sem_srai (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRASI (* FLD (i_rn), FLD (f_5u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srli: srl $rn,$uimm5

sem_status
mep_sem_srli (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (* FLD (i_rn), FLD (f_5u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** slli: sll $rn,$uimm5

sem_status
mep_sem_slli (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_srai.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (* FLD (i_rn), FLD (f_5u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sll3: sll3 \$0,$rn,$uimm5

sem_status
mep_sem_sll3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slt3i.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (* FLD (i_rn), FLD (f_5u8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** fsft: fsft $rn,$rm

sem_status
mep_sem_fsft (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_temp;
  QI tmp_shamt;
  tmp_shamt = ANDSI (current_cpu->h_csr_get (((UINT) 2)), 63);
  tmp_temp = SLLDI (ORDI (SLLDI (ZEXTSIDI (* FLD (i_rn)), 32), ZEXTSIDI (* FLD (i_rm))), tmp_shamt);
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_temp, 32), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bra: bra $pcrel12a2

sem_status
mep_sem_bra (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_12s4a2), INVSI (7));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_12s4a2), INVSI (3));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_12s4a2), INVSI (1));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** beqz: beqz $rn,$pcrel8a2

sem_status
mep_sem_beqz (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (* FLD (i_rn), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_8s8a2), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_8s8a2), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_8s8a2), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnez: bnez $rn,$pcrel8a2

sem_status
mep_sem_bnez (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beqz.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NESI (* FLD (i_rn), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_8s8a2), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_8s8a2), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_8s8a2), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** beqi: beqi $rn,$uimm4,$pcrel17a2

sem_status
mep_sem_beqi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQSI (* FLD (i_rn), ZEXTSISI (FLD (f_4u8)))) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnei: bnei $rn,$uimm4,$pcrel17a2

sem_status
mep_sem_bnei (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_rn), ZEXTSISI (FLD (f_4u8)))) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** blti: blti $rn,$uimm4,$pcrel17a2

sem_status
mep_sem_blti (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (LTSI (* FLD (i_rn), ZEXTSISI (FLD (f_4u8)))) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bgei: bgei $rn,$uimm4,$pcrel17a2

sem_status
mep_sem_bgei (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (GESI (* FLD (i_rn), ZEXTSISI (FLD (f_4u8)))) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** beq: beq $rn,$rm,$pcrel17a2

sem_status
mep_sem_beq (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQSI (* FLD (i_rn), * FLD (i_rm))) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bne: bne $rn,$rm,$pcrel17a2

sem_status
mep_sem_bne (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_rn), * FLD (i_rm))) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bsr12: bsr $pcrel12a2

sem_status
mep_sem_bsr12 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bsr12.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->cg_profile (pc, FLD (f_12s4a2));
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ADDSI (pc, 8);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
 else {
  {
    SI opval = ADDSI (pc, 2);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_12s4a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_12s4a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_12s4a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bsr24: bsr $pcrel24a2

sem_status
mep_sem_bsr24 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->cg_profile (pc, FLD (f_24s5a2n));
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ADDSI (pc, 8);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
 else {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** jmp: jmp $rm

sem_status
mep_sem_jmp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (EQSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), 0)) {
if (ANDSI (* FLD (i_rm), 1)) {
{
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (1, 12)));
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
} else {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
if (ANDSI (* FLD (i_rm), 1)) {
{
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (0, 12)));
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}
current_cpu->cg_profile_jump (pc, * FLD (i_rm));
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** jmp24: jmp $pcabs24a2

sem_status
mep_sem_jmp24 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jmp24.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (ORSI (ANDSI (pc, 0xf0000000), FLD (f_24u5a2n)), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (ORSI (ANDSI (pc, 0xf0000000), FLD (f_24u5a2n)), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (ORSI (ANDSI (pc, 0xf0000000), FLD (f_24u5a2n)), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
current_cpu->cg_profile_jump (pc, FLD (f_24u5a2n));
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** jsr: jsr $rm

sem_status
mep_sem_jsr (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->cg_profile (pc, * FLD (i_rm));
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ADDSI (pc, 8);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
 else {
  {
    SI opval = ADDSI (pc, 2);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
}
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ret: ret

sem_status
mep_sem_ret (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ret.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (EQSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), 0)) {
if (ANDSI (current_cpu->h_csr_get (((UINT) 1)), 1)) {
{
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (1, 12)));
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 1)), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 1)), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
} else {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 1)), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
if (ANDSI (current_cpu->h_csr_get (((UINT) 1)), 1)) {
{
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (0, 12)));
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 1)), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 1)), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 1)), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}
current_cpu->notify_ret (pc);
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** repeat: repeat $rn,$pcrel17a2

sem_status
mep_sem_repeat (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ADDSI (pc, 8);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 4), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 4), opval);
  }
}
 else {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 4), opval);
  }
}
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 5), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 5), opval);
  }
}
 else {
  {
    SI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 5), opval);
  }
}
  {
    SI opval = * FLD (i_rn);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 6), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** erepeat: erepeat $pcrel17a2

sem_status
mep_sem_erepeat (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_repeat.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ADDSI (pc, 8);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 4), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 4), opval);
  }
}
 else {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 4), opval);
  }
}
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 5), opval);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 5), opval);
  }
}
 else {
  {
    SI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 5), opval);
  }
}
current_cpu->hardware.h_csr[((UINT) 5)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 5)], INVSI (SLLSI (1, 0))), ANDSI (SLLSI (1, 0), SLLSI (1, 0)));
  {
    SI opval = 1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 6), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stc_lp: stc $rn,\$lp

sem_status
mep_sem_stc_lp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stc_lp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_rn);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stc_hi: stc $rn,\$hi

sem_status
mep_sem_stc_hi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_rn);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stc_lo: stc $rn,\$lo

sem_status
mep_sem_stc_lo (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_rn);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stc: stc $rn,$csrn

sem_status
mep_sem_stc (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stc.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_rn);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << FLD (f_csrn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (FLD (f_csrn), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldc_lp: ldc $rn,\$lp

sem_status
mep_sem_ldc_lp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_csr_get (((UINT) 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldc_hi: ldc $rn,\$hi

sem_status
mep_sem_ldc_hi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_csr_get (((UINT) 7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldc_lo: ldc $rn,\$lo

sem_status
mep_sem_ldc_lo (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_csr_get (((UINT) 8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldc: ldc $rn,$csrn

sem_status
mep_sem_ldc (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldc.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (FLD (f_csrn), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    SI opval = ADDSI (pc, 8);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    SI opval = ADDSI (pc, 4);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
 else {
  {
    SI opval = ADDSI (pc, 2);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
} else {
  {
    SI opval = current_cpu->h_csr_get (FLD (f_csrn));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** di: di

sem_status
mep_sem_di (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 1), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 16) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 16), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ei: ei

sem_status
mep_sem_ei (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ORSI (current_cpu->h_csr_get (((UINT) 16)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 16) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 16), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** reti: reti

sem_status
mep_sem_reti (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_reti.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), 0)) {
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 9), 1)) {
if (ANDSI (current_cpu->h_csr_get (((UINT) 23)), 1)) {
{
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (1, 12)));
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 23)), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 23)), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 9))), ANDSI (SLLSI (1, 9), SLLSI (0, 9)));
}
} else {
{
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 23)), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 9))), ANDSI (SLLSI (1, 9), SLLSI (0, 9)));
}
}
} else {
if (ANDSI (current_cpu->h_csr_get (((UINT) 19)), 1)) {
{
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (1, 12)));
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 19)), INVSI (3));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 19)), INVSI (7));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 2))), ANDSI (SLLSI (1, 2), SLLSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 3), 1), 2)));
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 0))), ANDSI (SLLSI (1, 0), SLLSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 1), 1), 0)));
}
} else {
{
  {
    USI opval = ANDSI (current_cpu->h_csr_get (((UINT) 19)), INVSI (1));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 2))), ANDSI (SLLSI (1, 2), SLLSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 3), 1), 2)));
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 0))), ANDSI (SLLSI (1, 0), SLLSI (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 1), 1), 0)));
}
}
}
} else {
((void) 0); /*nop*/
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** halt: halt

sem_status
mep_sem_halt (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_di.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (current_cpu->h_csr_get (((UINT) 16)), SLLSI (1, 11));

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sleep: sleep

sem_status
mep_sem_sleep (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_sleep ();

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swi: swi $uimm2

sem_status
mep_sem_swi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (FLD (f_2u10), 0)) {
  {
    SI opval = ORSI (current_cpu->h_csr_get (((UINT) 20)), SLLSI (1, 4));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 20) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 20), opval);
  }
}
 else if (EQSI (FLD (f_2u10), 1)) {
  {
    SI opval = ORSI (current_cpu->h_csr_get (((UINT) 20)), SLLSI (1, 5));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 20) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 20), opval);
  }
}
 else if (EQSI (FLD (f_2u10), 2)) {
  {
    SI opval = ORSI (current_cpu->h_csr_get (((UINT) 20)), SLLSI (1, 6));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 20) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 20), opval);
  }
}
 else if (EQSI (FLD (f_2u10), 3)) {
  {
    SI opval = ORSI (current_cpu->h_csr_get (((UINT) 20)), SLLSI (1, 7));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 20) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 20), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** break: break

sem_status
mep_sem_break (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->break_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** syncm: syncm

sem_status
mep_sem_syncm (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stcb: stcb $rn,$uimm16

sem_status
mep_sem_stcb (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

current_cpu->do_stcb (* FLD (i_rn), FLD (f_16u16));

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldcb: ldcb $rn,$uimm16

sem_status
mep_sem_ldcb (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_uci.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->do_ldcb (FLD (f_16u16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bsetm: bsetm ($rma),$uimm3

sem_status
mep_sem_bsetm (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_bit (pc);
  {
    UQI opval = ORQI (current_cpu->GETMEMUQI (pc, * FLD (i_rma)), SLLSI (1, FLD (f_3u5)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, * FLD (i_rma), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bclrm: bclrm ($rma),$uimm3

sem_status
mep_sem_bclrm (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_bit (pc);
  {
    UQI opval = ANDQI (current_cpu->GETMEMUQI (pc, * FLD (i_rma)), INVSI (SLLSI (1, FLD (f_3u5))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, * FLD (i_rma), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnotm: bnotm ($rma),$uimm3

sem_status
mep_sem_bnotm (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_bit (pc);
  {
    UQI opval = XORQI (current_cpu->GETMEMUQI (pc, * FLD (i_rma)), SLLSI (1, FLD (f_3u5)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, * FLD (i_rma), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** btstm: btstm \$0,($rma),$uimm3

sem_status
mep_sem_btstm (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_btstm.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_bit (pc);
  {
    SI opval = ZEXTQISI (ANDQI (current_cpu->GETMEMUQI (pc, * FLD (i_rma)), SLLSI (1, FLD (f_3u5))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gpr[((UINT) 0)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** tas: tas $rn,($rma)

sem_status
mep_sem_tas (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
current_cpu->check_option_bit (pc);
  tmp_result = ZEXTQISI (current_cpu->GETMEMUQI (pc, * FLD (i_rma)));
  {
    UQI opval = 1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, * FLD (i_rma), opval);
  }
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cache: cache $cimm4,($rma)

sem_status
mep_sem_cache (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldcb_r.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_cache (FLD (f_rn), * FLD (i_rma), pc);

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mul: mul $rn,$rm

sem_status
mep_sem_mul (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = MULDI (EXTSIDI (* FLD (i_rn)), EXTSIDI (* FLD (i_rm)));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mulu: mulu $rn,$rm

sem_status
mep_sem_mulu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = MULDI (ZEXTSIDI (* FLD (i_rn)), ZEXTSIDI (* FLD (i_rm)));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mulr: mulr $rn,$rm

sem_status
mep_sem_mulr (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = MULDI (EXTSIDI (* FLD (i_rn)), EXTSIDI (* FLD (i_rm)));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mulru: mulru $rn,$rm

sem_status
mep_sem_mulru (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = MULDI (ZEXTSIDI (* FLD (i_rn)), ZEXTSIDI (* FLD (i_rm)));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** madd: madd $rn,$rm

sem_status
mep_sem_madd (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = ORDI (SLLDI (ZEXTSIDI (current_cpu->h_csr_get (((UINT) 7))), 32), ZEXTSIDI (current_cpu->h_csr_get (((UINT) 8))));
  tmp_result = ADDDI (tmp_result, MULDI (EXTSIDI (* FLD (i_rn)), EXTSIDI (* FLD (i_rm))));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maddu: maddu $rn,$rm

sem_status
mep_sem_maddu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = ORDI (SLLDI (ZEXTSIDI (current_cpu->h_csr_get (((UINT) 7))), 32), ZEXTSIDI (current_cpu->h_csr_get (((UINT) 8))));
  tmp_result = ADDDI (tmp_result, MULDI (ZEXTSIDI (* FLD (i_rn)), ZEXTSIDI (* FLD (i_rm))));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maddr: maddr $rn,$rm

sem_status
mep_sem_maddr (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = ORDI (SLLDI (ZEXTSIDI (current_cpu->h_csr_get (((UINT) 7))), 32), ZEXTSIDI (current_cpu->h_csr_get (((UINT) 8))));
  tmp_result = ADDDI (tmp_result, MULDI (EXTSIDI (* FLD (i_rn)), EXTSIDI (* FLD (i_rm))));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maddru: maddru $rn,$rm

sem_status
mep_sem_maddru (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_result;
current_cpu->check_option_mul (pc);
  tmp_result = ORDI (SLLDI (ZEXTSIDI (current_cpu->h_csr_get (((UINT) 7))), 32), ZEXTSIDI (current_cpu->h_csr_get (((UINT) 8))));
  tmp_result = ADDDI (tmp_result, MULDI (ZEXTSIDI (* FLD (i_rn)), ZEXTSIDI (* FLD (i_rm))));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** div: div $rn,$rm

sem_status
mep_sem_div (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_div (pc);
if (EQSI (* FLD (i_rm), 0)) {
  {
    USI opval = current_cpu->zdiv_exception (pc);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
if (ANDBI (EQSI (* FLD (i_rn), 0x80000000), EQSI (* FLD (i_rm), 0xffffffff))) {
{
  {
    SI opval = 0x80000000;
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = 0;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
}
} else {
{
  {
    SI opval = DIVSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = MODSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
}
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** divu: divu $rn,$rm

sem_status
mep_sem_divu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_maddr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_div (pc);
if (EQSI (* FLD (i_rm), 0)) {
  {
    USI opval = current_cpu->zdiv_exception (pc);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
{
  {
    SI opval = UDIVSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 8), opval);
  }
  {
    SI opval = UMODSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 7), opval);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** dret: dret

sem_status
mep_sem_dret (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_debug (pc);
  {
    SI opval = ANDSI (current_cpu->h_csr_get (((UINT) 24)), INVSI (SLLSI (1, 15)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 24), opval);
  }
  {
    USI opval = current_cpu->h_csr_get (((UINT) 25));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** dbreak: dbreak

sem_status
mep_sem_dbreak (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_dret.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_debug (pc);
  {
    SI opval = ORSI (current_cpu->h_csr_get (((UINT) 24)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 24) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 24), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldz: ldz $rn,$rm

sem_status
mep_sem_ldz (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3x.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_ldz (pc);
  {
    SI opval = current_cpu->do_ldz (* FLD (i_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** abs: abs $rn,$rm

sem_status
mep_sem_abs (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_abs (pc);
  {
    SI opval = ABSSI (SUBSI (* FLD (i_rn), * FLD (i_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ave: ave $rn,$rm

sem_status
mep_sem_ave (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_ave (pc);
  {
    SI opval = SRASI (ADDSI (ADDSI (* FLD (i_rn), * FLD (i_rm)), 1), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** min: min $rn,$rm

sem_status
mep_sem_min (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_minmax (pc);
if (GTSI (* FLD (i_rn), * FLD (i_rm))) {
  {
    SI opval = * FLD (i_rm);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** max: max $rn,$rm

sem_status
mep_sem_max (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_minmax (pc);
if (LTSI (* FLD (i_rn), * FLD (i_rm))) {
  {
    SI opval = * FLD (i_rm);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** minu: minu $rn,$rm

sem_status
mep_sem_minu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_minmax (pc);
if (GTUSI (* FLD (i_rn), * FLD (i_rm))) {
  {
    SI opval = * FLD (i_rm);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maxu: maxu $rn,$rm

sem_status
mep_sem_maxu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_minmax (pc);
if (LTUSI (* FLD (i_rn), * FLD (i_rm))) {
  {
    SI opval = * FLD (i_rm);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clip: clip $rn,$cimm5

sem_status
mep_sem_clip (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_min;
  SI tmp_max;
current_cpu->check_option_clip (pc);
  tmp_max = SUBSI (SLLSI (1, SUBSI (FLD (f_5u24), 1)), 1);
  tmp_min = NEGSI (SLLSI (1, SUBSI (FLD (f_5u24), 1)));
if (EQSI (FLD (f_5u24), 0)) {
  {
    SI opval = 0;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
 else if (GTSI (* FLD (i_rn), tmp_max)) {
  {
    SI opval = tmp_max;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
 else if (LTSI (* FLD (i_rn), tmp_min)) {
  {
    SI opval = tmp_min;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clipu: clipu $rn,$cimm5

sem_status
mep_sem_clipu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clip.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_max;
current_cpu->check_option_clip (pc);
  tmp_max = SUBSI (SLLSI (1, FLD (f_5u24)), 1);
if (EQSI (FLD (f_5u24), 0)) {
  {
    SI opval = 0;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
 else if (GTSI (* FLD (i_rn), tmp_max)) {
  {
    SI opval = tmp_max;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
 else if (LTSI (* FLD (i_rn), 0)) {
  {
    SI opval = 0;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sadd: sadd $rn,$rm

sem_status
mep_sem_sadd (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_sat (pc);
if (ADDOFSI (* FLD (i_rn), * FLD (i_rm), 0)) {
if (LTSI (* FLD (i_rn), 0)) {
  {
    SI opval = NEGSI (SLLSI (1, 31));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
} else {
  {
    SI opval = SUBSI (SLLSI (1, 31), 1);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
} else {
  {
    SI opval = ADDSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ssub: ssub $rn,$rm

sem_status
mep_sem_ssub (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_sat (pc);
if (SUBOFSI (* FLD (i_rn), * FLD (i_rm), 0)) {
if (LTSI (* FLD (i_rn), 0)) {
  {
    SI opval = NEGSI (SLLSI (1, 31));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
} else {
  {
    SI opval = SUBSI (SLLSI (1, 31), 1);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
} else {
  {
    SI opval = SUBSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** saddu: saddu $rn,$rm

sem_status
mep_sem_saddu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_sat (pc);
if (ADDCFSI (* FLD (i_rn), * FLD (i_rm), 0)) {
  {
    SI opval = INVSI (0);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
} else {
  {
    SI opval = ADDSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ssubu: ssubu $rn,$rm

sem_status
mep_sem_ssubu (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_fsft.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_sat (pc);
if (SUBCFSI (* FLD (i_rn), * FLD (i_rm), 0)) {
  {
    SI opval = 0;
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
} else {
  {
    SI opval = SUBSI (* FLD (i_rn), * FLD (i_rm));
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swcp: swcp $crn,($rma)

sem_status
mep_sem_swcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (3)));
  {
    SI opval = current_cpu->h_cr_get (FLD (f_crn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lwcp: lwcp $crn,($rma)

sem_status
mep_sem_lwcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smcp: smcp $crn64,($rma)

sem_status
mep_sem_smcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
current_cpu->do_smcp (* FLD (i_rma), current_cpu->hardware.h_cr64[FLD (f_crn)], pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lmcp: lmcp $crn64,($rma)

sem_status
mep_sem_lmcp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
  {
    DI opval = current_cpu->do_lmcp (* FLD (i_rma), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swcpi: swcpi $crn,($rma+)

sem_status
mep_sem_swcpi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (3)));
  {
    SI opval = current_cpu->h_cr_get (FLD (f_crn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lwcpi: lwcpi $crn,($rma+)

sem_status
mep_sem_lwcpi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smcpi: smcpi $crn64,($rma+)

sem_status
mep_sem_smcpi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
current_cpu->do_smcpi (FLD (f_rm), current_cpu->hardware.h_cr64[FLD (f_crn)], pc);
  {
    SI opval = * FLD (i_rma);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lmcpi: lmcpi $crn64,($rma+)

sem_status
mep_sem_lmcpi (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
  {
    DI opval = current_cpu->do_lmcpi (FLD (f_rm), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crn), opval);
  }
  {
    SI opval = * FLD (i_rma);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swcp16: swcp $crn,$sdisp16($rma)

sem_status
mep_sem_swcp16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = current_cpu->h_cr_get (FLD (f_crn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (ADDSI (* FLD (i_rma), FLD (f_16s16)), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (ADDSI (* FLD (i_rma), FLD (f_16s16)), INVSI (3)), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lwcp16: lwcp $crn,$sdisp16($rma)

sem_status
mep_sem_lwcp16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (ADDSI (* FLD (i_rma), FLD (f_16s16)), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smcp16: smcp $crn64,$sdisp16($rma)

sem_status
mep_sem_smcp16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
current_cpu->do_smcp16 (* FLD (i_rma), FLD (f_16s16), current_cpu->hardware.h_cr64[FLD (f_crn)], pc);
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lmcp16: lmcp $crn64,$sdisp16($rma)

sem_status
mep_sem_lmcp16 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swcp16.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
  {
    DI opval = current_cpu->do_lmcp16 (* FLD (i_rma), FLD (f_16s16), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crn), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcpa: sbcpa $crn,($rma+),$cdisp10

sem_status
mep_sem_sbcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
  {
    QI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, * FLD (i_rma), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbcpa: lbcpa $crn,($rma+),$cdisp10

sem_status
mep_sem_lbcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shcpa: shcpa $crn,($rma+),$cdisp10a2

sem_status
mep_sem_shcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (1)));
  {
    HI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (1)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1)), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhcpa: lhcpa $crn,($rma+),$cdisp10a2

sem_status
mep_sem_lhcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swcpa: swcpa $crn,($rma+),$cdisp10a4

sem_status
mep_sem_swcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (3)));
  {
    SI opval = current_cpu->h_cr_get (FLD (f_crn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lwcpa: lwcpa $crn,($rma+),$cdisp10a4

sem_status
mep_sem_lwcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smcpa: smcpa $crn64,($rma+),$cdisp10a8

sem_status
mep_sem_smcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
current_cpu->do_smcpa (FLD (f_rm), FLD (f_cdisp10), current_cpu->hardware.h_cr64[FLD (f_crn)], pc);
  {
    SI opval = * FLD (i_rma);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lmcpa: lmcpa $crn64,($rma+),$cdisp10a8

sem_status
mep_sem_lmcpa (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
  {
    DI opval = current_cpu->do_lmcpa (FLD (f_rm), FLD (f_cdisp10), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crn), opval);
  }
  {
    SI opval = * FLD (i_rma);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcpm0: sbcpm0 $crn,($rma+),$cdisp10

sem_status
mep_sem_sbcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
  {
    QI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, * FLD (i_rma), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbcpm0: lbcpm0 $crn,($rma+),$cdisp10

sem_status
mep_sem_lbcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shcpm0: shcpm0 $crn,($rma+),$cdisp10a2

sem_status
mep_sem_shcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (1)));
  {
    HI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (1)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1)), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhcpm0: lhcpm0 $crn,($rma+),$cdisp10a2

sem_status
mep_sem_lhcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swcpm0: swcpm0 $crn,($rma+),$cdisp10a4

sem_status
mep_sem_swcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (3)));
  {
    SI opval = current_cpu->h_cr_get (FLD (f_crn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lwcpm0: lwcpm0 $crn,($rma+),$cdisp10a4

sem_status
mep_sem_lwcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = current_cpu->GETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smcpm0: smcpm0 $crn64,($rma+),$cdisp10a8

sem_status
mep_sem_smcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
current_cpu->do_smcp (* FLD (i_rma), current_cpu->hardware.h_cr64[FLD (f_crn)], pc);
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lmcpm0: lmcpm0 $crn64,($rma+),$cdisp10a8

sem_status
mep_sem_lmcpm0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm0.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
  {
    DI opval = current_cpu->do_lmcp (* FLD (i_rma), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 12)), current_cpu->h_csr_get (((UINT) 13)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 13)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 12)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbcpm1: sbcpm1 $crn,($rma+),$cdisp10

sem_status
mep_sem_sbcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (* FLD (i_rma));
  {
    QI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rma) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, * FLD (i_rma), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lbcpm1: lbcpm1 $crn,($rma+),$cdisp10

sem_status
mep_sem_lbcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_rma)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** shcpm1: shcpm1 $crn,($rma+),$cdisp10a2

sem_status
mep_sem_shcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (1)));
  {
    HI opval = ANDSI (current_cpu->h_cr_get (FLD (f_crn)), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (1)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1)), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lhcpm1: lhcpm1 $crn,($rma+),$cdisp10a2

sem_status
mep_sem_lhcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ANDSI (* FLD (i_rma), INVSI (1))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swcpm1: swcpm1 $crn,($rma+),$cdisp10a4

sem_status
mep_sem_swcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_write_to_text (ANDSI (* FLD (i_rma), INVSI (3)));
  {
    SI opval = current_cpu->h_cr_get (FLD (f_crn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDSI (* FLD (i_rma), INVSI (3)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3)), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lwcpm1: lwcpm1 $crn,($rma+),$cdisp10a4

sem_status
mep_sem_lwcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
  {
    SI opval = EXTSISI (current_cpu->GETMEMSI (pc, ANDSI (* FLD (i_rma), INVSI (3))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smcpm1: smcpm1 $crn64,($rma+),$cdisp10a8

sem_status
mep_sem_smcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
current_cpu->do_smcp (* FLD (i_rma), current_cpu->hardware.h_cr64[FLD (f_crn)], pc);
current_cpu->check_write_to_text (* FLD (i_rma));
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lmcpm1: lmcpm1 $crn64,($rma+),$cdisp10a8

sem_status
mep_sem_lmcpm1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lbucpm1.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
current_cpu->check_option_cp64 (pc);
  {
    DI opval = current_cpu->do_lmcp (* FLD (i_rma), pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr64" << '[' << FLD (f_crn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr64_set (FLD (f_crn), opval);
  }
  {
    SI opval = ({   SI tmp_modulo_mask;
  tmp_modulo_mask = ({   SI tmp_temp;
  tmp_temp = ORSI (current_cpu->h_csr_get (((UINT) 14)), current_cpu->h_csr_get (((UINT) 15)));
; SRLSI (-1, current_cpu->do_ldz (tmp_temp)); });
; ((EQSI (ANDSI (* FLD (i_rma), tmp_modulo_mask), current_cpu->h_csr_get (((UINT) 15)))) ? (ORSI (ANDSI (* FLD (i_rma), INVSI (tmp_modulo_mask)), current_cpu->h_csr_get (((UINT) 14)))) : (ADDSI (* FLD (i_rma), EXTSISI (FLD (f_cdisp10))))); });
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gpr" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rma) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcpeq: bcpeq $cccc,$pcrel17a2

sem_status
mep_sem_bcpeq (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
if (EQSI (XORSI (FLD (f_rm), current_cpu->hardware.h_ccr[((UINT) 1)]), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcpne: bcpne $cccc,$pcrel17a2

sem_status
mep_sem_bcpne (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
if (NESI (XORSI (FLD (f_rm), current_cpu->hardware.h_ccr[((UINT) 1)]), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcpat: bcpat $cccc,$pcrel17a2

sem_status
mep_sem_bcpat (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
if (NESI (ANDSI (FLD (f_rm), current_cpu->hardware.h_ccr[((UINT) 1)]), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcpaf: bcpaf $cccc,$pcrel17a2

sem_status
mep_sem_bcpaf (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->check_option_cp (pc);
if (EQSI (ANDSI (FLD (f_rm), current_cpu->hardware.h_ccr[((UINT) 1)]), 0)) {
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (7));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (3));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
 else {
  {
    USI opval = ANDSI (FLD (f_17s16a2), INVSI (1));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** synccp: synccp

sem_status
mep_sem_synccp (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->check_option_cp (pc);
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** jsrv: jsrv $rm

sem_status
mep_sem_jsrv (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_jsr.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
current_cpu->cg_profile (pc, * FLD (i_rm));
current_cpu->check_option_cp (pc);
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
{
  {
    SI opval = ORSI (ADDSI (pc, 8), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (0, 12)));
}
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
{
  {
    SI opval = ORSI (ADDSI (pc, 4), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (0, 12)));
}
}
 else {
{
  {
    SI opval = ORSI (ADDSI (pc, 2), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (* FLD (i_rm), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (1, 12)));
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bsrv: bsrv $pcrel24a2

sem_status
mep_sem_bsrv (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bsr24.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->cg_profile (pc, FLD (f_24s5a2n));
current_cpu->check_option_cp (pc);
if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 6), 1))) {
{
  {
    SI opval = ORSI (ADDSI (pc, 8), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (0, 12)));
}
}
 else if (ANDIF (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 16)), 12), 1), ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1))) {
{
  {
    SI opval = ORSI (ADDSI (pc, 4), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (1));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (0, 12)));
}
}
 else {
{
  {
    SI opval = ORSI (ADDSI (pc, 4), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "csr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_csr_set (((UINT) 1), opval);
  }
if (ANDSI (SRLSI (current_cpu->h_csr_get (((UINT) 26)), 5), 1)) {
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (3));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    USI opval = ANDSI (FLD (f_24s5a2n), INVSI (7));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
current_cpu->hardware.h_csr[((UINT) 16)] = ORSI (ANDSI (current_cpu->hardware.h_csr[((UINT) 16)], INVSI (SLLSI (1, 12))), ANDSI (SLLSI (1, 12), SLLSI (1, 12)));
}
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sim-syscall: --syscall--

sem_status
mep_sem_sim_syscall (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->do_syscall (pc, FLD (f_callnum));

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-0: --reserved--

sem_status
mep_sem_ri_0 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-1: --reserved--

sem_status
mep_sem_ri_1 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-2: --reserved--

sem_status
mep_sem_ri_2 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-3: --reserved--

sem_status
mep_sem_ri_3 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-4: --reserved--

sem_status
mep_sem_ri_4 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-5: --reserved--

sem_status
mep_sem_ri_5 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-6: --reserved--

sem_status
mep_sem_ri_6 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-7: --reserved--

sem_status
mep_sem_ri_7 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-8: --reserved--

sem_status
mep_sem_ri_8 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-9: --reserved--

sem_status
mep_sem_ri_9 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-10: --reserved--

sem_status
mep_sem_ri_10 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-11: --reserved--

sem_status
mep_sem_ri_11 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-12: --reserved--

sem_status
mep_sem_ri_12 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-13: --reserved--

sem_status
mep_sem_ri_13 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-14: --reserved--

sem_status
mep_sem_ri_14 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-15: --reserved--

sem_status
mep_sem_ri_15 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-17: --reserved--

sem_status
mep_sem_ri_17 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-20: --reserved--

sem_status
mep_sem_ri_20 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-21: --reserved--

sem_status
mep_sem_ri_21 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-22: --reserved--

sem_status
mep_sem_ri_22 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-23: --reserved--

sem_status
mep_sem_ri_23 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ri-26: --reserved--

sem_status
mep_sem_ri_26 (mep_basic_cpu* current_cpu, mep_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mep_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->ri_exception (pc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

