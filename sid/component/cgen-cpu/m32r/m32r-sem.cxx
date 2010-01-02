/* Simulator instruction semantics for m32rbf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "m32rbf.h"

using namespace m32rbf; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

sem_status
m32rbf_sem_x_invalid (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
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

// ********** add: add $dr,$sr

sem_status
m32rbf_sem_add (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add3: add3 $dr,$sr,$hash$slo16

sem_status
m32rbf_sem_add3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ADDSI (* FLD (i_sr), FLD (f_simm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** and: and $dr,$sr

sem_status
m32rbf_sem_and (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ANDSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** and3: and3 $dr,$sr,$uimm16

sem_status
m32rbf_sem_and3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ANDSI (* FLD (i_sr), FLD (f_uimm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** or: or $dr,$sr

sem_status
m32rbf_sem_or (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ORSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** or3: or3 $dr,$sr,$hash$ulo16

sem_status
m32rbf_sem_or3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ORSI (* FLD (i_sr), FLD (f_uimm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xor: xor $dr,$sr

sem_status
m32rbf_sem_xor (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = XORSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** xor3: xor3 $dr,$sr,$uimm16

sem_status
m32rbf_sem_xor3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = XORSI (* FLD (i_sr), FLD (f_uimm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addi: addi $dr,$simm8

sem_status
m32rbf_sem_addi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (* FLD (i_dr), FLD (f_simm8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addv: addv $dr,$sr

sem_status
m32rbf_sem_addv (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI temp0;BI temp1;
  temp0 = ADDSI (* FLD (i_dr), * FLD (i_sr));
  temp1 = ADDOFSI (* FLD (i_dr), * FLD (i_sr), 0);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
  {
    BI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addv3: addv3 $dr,$sr,$simm16

sem_status
m32rbf_sem_addv3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI temp0;BI temp1;
  temp0 = ADDSI (* FLD (i_sr), FLD (f_simm16));
  temp1 = ADDOFSI (* FLD (i_sr), FLD (f_simm16), 0);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
  {
    BI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addx: addx $dr,$sr

sem_status
m32rbf_sem_addx (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI temp0;BI temp1;
  temp0 = ADDCSI (* FLD (i_dr), * FLD (i_sr), current_cpu->hardware.h_cond);
  temp1 = ADDCFSI (* FLD (i_dr), * FLD (i_sr), current_cpu->hardware.h_cond);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
  {
    BI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bc8: bc.s $disp8

sem_status
m32rbf_sem_bc8 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc8.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->hardware.h_cond) {
  {
    USI opval = FLD (i_disp8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bc24: bc.l $disp24

sem_status
m32rbf_sem_bc24 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc24.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (current_cpu->hardware.h_cond) {
  {
    USI opval = FLD (i_disp24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** beq: beq $src1,$src2,$disp16

sem_status
m32rbf_sem_beq (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQSI (* FLD (i_src1), * FLD (i_src2))) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** beqz: beqz $src2,$disp16

sem_status
m32rbf_sem_beqz (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQSI (* FLD (i_src2), 0)) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bgez: bgez $src2,$disp16

sem_status
m32rbf_sem_bgez (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (GESI (* FLD (i_src2), 0)) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bgtz: bgtz $src2,$disp16

sem_status
m32rbf_sem_bgtz (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (GTSI (* FLD (i_src2), 0)) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** blez: blez $src2,$disp16

sem_status
m32rbf_sem_blez (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (LESI (* FLD (i_src2), 0)) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bltz: bltz $src2,$disp16

sem_status
m32rbf_sem_bltz (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (LTSI (* FLD (i_src2), 0)) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnez: bnez $src2,$disp16

sem_status
m32rbf_sem_bnez (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_src2), 0)) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bl8: bl.s $disp8

sem_status
m32rbf_sem_bl8 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc8.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDSI (ANDSI (pc, -4), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  {
    USI opval = FLD (i_disp8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bl24: bl.l $disp24

sem_status
m32rbf_sem_bl24 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc24.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = ADDSI (pc, 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  {
    USI opval = FLD (i_disp24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnc8: bnc.s $disp8

sem_status
m32rbf_sem_bnc8 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc8.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->hardware.h_cond)) {
  {
    USI opval = FLD (i_disp8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bnc24: bnc.l $disp24

sem_status
m32rbf_sem_bnc24 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc24.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NOTBI (current_cpu->hardware.h_cond)) {
  {
    USI opval = FLD (i_disp24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bne: bne $src1,$src2,$disp16

sem_status
m32rbf_sem_bne (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_src1), * FLD (i_src2))) {
  {
    USI opval = FLD (i_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bra8: bra.s $disp8

sem_status
m32rbf_sem_bra8 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc8.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = FLD (i_disp8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bra24: bra.l $disp24

sem_status
m32rbf_sem_bra24 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bc24.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    USI opval = FLD (i_disp24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp: cmp $src1,$src2

sem_status
m32rbf_sem_cmp (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = LTSI (* FLD (i_src1), * FLD (i_src2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmpi: cmpi $src2,$simm16

sem_status
m32rbf_sem_cmpi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    BI opval = LTSI (* FLD (i_src2), FLD (f_simm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmpu: cmpu $src1,$src2

sem_status
m32rbf_sem_cmpu (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = LTUSI (* FLD (i_src1), * FLD (i_src2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmpui: cmpui $src2,$simm16

sem_status
m32rbf_sem_cmpui (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    BI opval = LTUSI (* FLD (i_src2), FLD (f_simm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** div: div $dr,$sr

sem_status
m32rbf_sem_div (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_sr), 0)) {
  {
    SI opval = DIVSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** divu: divu $dr,$sr

sem_status
m32rbf_sem_divu (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_sr), 0)) {
  {
    SI opval = UDIVSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rem: rem $dr,$sr

sem_status
m32rbf_sem_rem (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_sr), 0)) {
  {
    SI opval = MODSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** remu: remu $dr,$sr

sem_status
m32rbf_sem_remu (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NESI (* FLD (i_sr), 0)) {
  {
    SI opval = UMODSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** jl: jl $sr

sem_status
m32rbf_sem_jl (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bset.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI temp0;USI temp1;
  temp0 = ADDSI (ANDSI (pc, -4), 4);
  temp1 = ANDSI (* FLD (i_sr), -4);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  {
    USI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** jmp: jmp $sr

sem_status
m32rbf_sem_jmp (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bset.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = ANDSI (* FLD (i_sr), -4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ld: ld $dr,@$sr

sem_status
m32rbf_sem_ld (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ld-d: ld $dr,@($slo16,$sr)

sem_status
m32rbf_sem_ld_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldb: ldb $dr,@$sr

sem_status
m32rbf_sem_ldb (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_sr)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldb-d: ldb $dr,@($slo16,$sr)

sem_status
m32rbf_sem_ldb_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldh: ldh $dr,@$sr

sem_status
m32rbf_sem_ldh (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, * FLD (i_sr)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldh-d: ldh $dr,@($slo16,$sr)

sem_status
m32rbf_sem_ldh_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldub: ldub $dr,@$sr

sem_status
m32rbf_sem_ldub (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, * FLD (i_sr)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldub-d: ldub $dr,@($slo16,$sr)

sem_status
m32rbf_sem_ldub_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lduh: lduh $dr,@$sr

sem_status
m32rbf_sem_lduh (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, * FLD (i_sr)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lduh-d: lduh $dr,@($slo16,$sr)

sem_status
m32rbf_sem_lduh_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ld-plus: ld $dr,@$sr+

sem_status
m32rbf_sem_ld_plus (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI temp0;SI temp1;
  temp0 = current_cpu->GETMEMSI (pc, * FLD (i_sr));
  temp1 = ADDSI (* FLD (i_sr), 4);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
  {
    SI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r2) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_sr) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ld24: ld24 $dr,$uimm24

sem_status
m32rbf_sem_ld24 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ld24.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = FLD (i_uimm24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldi8: ldi8 $dr,$simm8

sem_status
m32rbf_sem_ldi8 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = FLD (f_simm8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldi16: ldi16 $dr,$hash$slo16

sem_status
m32rbf_sem_ldi16 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = FLD (f_simm16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lock: lock $dr,@$sr

sem_status
m32rbf_sem_lock (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    BI opval = 1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "lock" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_lock = opval;
  }
  {
    SI opval = current_cpu->GETMEMSI (pc, * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** machi: machi $src1,$src2

sem_status
m32rbf_sem_machi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (ADDDI (current_cpu->h_accum_get (), MULDI (EXTSIDI (ANDSI (* FLD (i_src1), 0xffff0000)), EXTHIDI (TRUNCSIHI (SRASI (* FLD (i_src2), 16))))), 8), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** maclo: maclo $src1,$src2

sem_status
m32rbf_sem_maclo (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (ADDDI (current_cpu->h_accum_get (), MULDI (EXTSIDI (SLLSI (* FLD (i_src1), 16)), EXTHIDI (TRUNCSIHI (* FLD (i_src2))))), 8), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** macwhi: macwhi $src1,$src2

sem_status
m32rbf_sem_macwhi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (ADDDI (current_cpu->h_accum_get (), MULDI (EXTSIDI (* FLD (i_src1)), EXTHIDI (TRUNCSIHI (SRASI (* FLD (i_src2), 16))))), 8), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** macwlo: macwlo $src1,$src2

sem_status
m32rbf_sem_macwlo (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (ADDDI (current_cpu->h_accum_get (), MULDI (EXTSIDI (* FLD (i_src1)), EXTHIDI (TRUNCSIHI (* FLD (i_src2))))), 8), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mul: mul $dr,$sr

sem_status
m32rbf_sem_mul (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = MULSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mulhi: mulhi $src1,$src2

sem_status
m32rbf_sem_mulhi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (MULDI (EXTSIDI (ANDSI (* FLD (i_src1), 0xffff0000)), EXTHIDI (TRUNCSIHI (SRASI (* FLD (i_src2), 16)))), 16), 16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mullo: mullo $src1,$src2

sem_status
m32rbf_sem_mullo (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (MULDI (EXTSIDI (SLLSI (* FLD (i_src1), 16)), EXTHIDI (TRUNCSIHI (* FLD (i_src2)))), 16), 16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mulwhi: mulwhi $src1,$src2

sem_status
m32rbf_sem_mulwhi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (MULDI (EXTSIDI (* FLD (i_src1)), EXTHIDI (TRUNCSIHI (SRASI (* FLD (i_src2), 16)))), 8), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mulwlo: mulwlo $src1,$src2

sem_status
m32rbf_sem_mulwlo (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = SRADI (SLLDI (MULDI (EXTSIDI (* FLD (i_src1)), EXTHIDI (TRUNCSIHI (* FLD (i_src2)))), 8), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mv: mv $dr,$sr

sem_status
m32rbf_sem_mv (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_sr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvfachi: mvfachi $dr

sem_status
m32rbf_sem_mvfachi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slli.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = TRUNCDISI (SRADI (current_cpu->h_accum_get (), 32));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvfaclo: mvfaclo $dr

sem_status
m32rbf_sem_mvfaclo (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slli.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = TRUNCDISI (current_cpu->h_accum_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvfacmi: mvfacmi $dr

sem_status
m32rbf_sem_mvfacmi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slli.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = TRUNCDISI (SRADI (current_cpu->h_accum_get (), 16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvfc: mvfc $dr,$scr

sem_status
m32rbf_sem_mvfc (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_cr_get (FLD (f_r2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvtachi: mvtachi $src1

sem_status
m32rbf_sem_mvtachi (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = ORDI (ANDDI (current_cpu->h_accum_get (), MAKEDI (0, 0xffffffff)), SLLDI (EXTSIDI (* FLD (i_src1)), 32));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvtaclo: mvtaclo $src1

sem_status
m32rbf_sem_mvtaclo (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = ORDI (ANDDI (current_cpu->h_accum_get (), MAKEDI (0xffffffff, 0)), ZEXTSIDI (* FLD (i_src1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvtc: mvtc $sr,$dcr

sem_status
m32rbf_sem_mvtc (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = * FLD (i_sr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_r1), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** neg: neg $dr,$sr

sem_status
m32rbf_sem_neg (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = NEGSI (* FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** nop: nop

sem_status
m32rbf_sem_nop (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

PROFILE_COUNT_FILLNOPS (current_cpu, abuf->addr);

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** not: not $dr,$sr

sem_status
m32rbf_sem_not (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = INVSI (* FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rac: rac

sem_status
m32rbf_sem_rac (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_tmp1;
  tmp_tmp1 = SLLDI (current_cpu->h_accum_get (), 1);
  tmp_tmp1 = ADDDI (tmp_tmp1, MAKEDI (0, 32768));
  {
    DI opval = (GTDI (tmp_tmp1, MAKEDI (32767, 0xffff0000))) ? (MAKEDI (32767, 0xffff0000)) : (LTDI (tmp_tmp1, MAKEDI (0xffff8000, 0))) ? (MAKEDI (0xffff8000, 0)) : (ANDDI (tmp_tmp1, MAKEDI (0xffffffff, 0xffff0000)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rach: rach

sem_status
m32rbf_sem_rach (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_tmp1;
  tmp_tmp1 = ANDDI (current_cpu->h_accum_get (), MAKEDI (16777215, 0xffffffff));
if (ANDIF (GEDI (tmp_tmp1, MAKEDI (16383, 0x80000000)), LEDI (tmp_tmp1, MAKEDI (8388607, 0xffffffff)))) {
  tmp_tmp1 = MAKEDI (16383, 0x80000000);
} else {
if (ANDIF (GEDI (tmp_tmp1, MAKEDI (8388608, 0)), LEDI (tmp_tmp1, MAKEDI (16760832, 0)))) {
  tmp_tmp1 = MAKEDI (16760832, 0);
} else {
  tmp_tmp1 = ANDDI (ADDDI (current_cpu->h_accum_get (), MAKEDI (0, 1073741824)), MAKEDI (0xffffffff, 0x80000000));
}
}
  tmp_tmp1 = SLLDI (tmp_tmp1, 1);
  {
    DI opval = SRADI (SLLDI (tmp_tmp1, 7), 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "accum" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_accum_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** rte: rte

sem_status
m32rbf_sem_rte (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    USI opval = ANDSI (current_cpu->h_cr_get (((UINT) 6)), -4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    USI opval = current_cpu->h_cr_get (((UINT) 14));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (((UINT) 6), opval);
  }
  {
    UQI opval = current_cpu->hardware.h_bpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "psw" << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->h_psw_set (opval);
  }
  {
    UQI opval = current_cpu->hardware.h_bbpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "bpsw" << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->hardware.h_bpsw = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** seth: seth $dr,$hash$hi16

sem_status
m32rbf_sem_seth (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_seth.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SLLSI (FLD (f_hi16), 16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sll: sll $dr,$sr

sem_status
m32rbf_sem_sll (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (* FLD (i_dr), ANDSI (* FLD (i_sr), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sll3: sll3 $dr,$sr,$simm16

sem_status
m32rbf_sem_sll3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SLLSI (* FLD (i_sr), ANDSI (FLD (f_simm16), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** slli: slli $dr,$uimm5

sem_status
m32rbf_sem_slli (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slli.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (* FLD (i_dr), FLD (f_uimm5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sra: sra $dr,$sr

sem_status
m32rbf_sem_sra (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRASI (* FLD (i_dr), ANDSI (* FLD (i_sr), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sra3: sra3 $dr,$sr,$simm16

sem_status
m32rbf_sem_sra3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRASI (* FLD (i_sr), ANDSI (FLD (f_simm16), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srai: srai $dr,$uimm5

sem_status
m32rbf_sem_srai (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slli.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRASI (* FLD (i_dr), FLD (f_uimm5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srl: srl $dr,$sr

sem_status
m32rbf_sem_srl (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (* FLD (i_dr), ANDSI (* FLD (i_sr), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srl3: srl3 $dr,$sr,$simm16

sem_status
m32rbf_sem_srl3 (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRLSI (* FLD (i_sr), ANDSI (FLD (f_simm16), 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** srli: srli $dr,$uimm5

sem_status
m32rbf_sem_srli (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_slli.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (* FLD (i_dr), FLD (f_uimm5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** st: st $src1,@$src2

sem_status
m32rbf_sem_st (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_src2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, * FLD (i_src2), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** st-d: st $src1,@($slo16,$src2)

sem_status
m32rbf_sem_st_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_src2), FLD (f_simm16)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (* FLD (i_src2), FLD (f_simm16)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stb: stb $src1,@$src2

sem_status
m32rbf_sem_stb (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    QI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_src2) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, * FLD (i_src2), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stb-d: stb $src1,@($slo16,$src2)

sem_status
m32rbf_sem_stb_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    QI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_src2), FLD (f_simm16)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (* FLD (i_src2), FLD (f_simm16)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sth: sth $src1,@$src2

sem_status
m32rbf_sem_sth (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_src2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, * FLD (i_src2), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sth-d: sth $src1,@($slo16,$src2)

sem_status
m32rbf_sem_sth_d (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    HI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_src2), FLD (f_simm16)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (* FLD (i_src2), FLD (f_simm16)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** st-plus: st $src1,@+$src2

sem_status
m32rbf_sem_st_plus (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_new_src2;
  tmp_new_src2 = ADDSI (* FLD (i_src2), 4);
  {
    SI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_new_src2 << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_new_src2, opval);
  }
  {
    SI opval = tmp_new_src2;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r2) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_src2) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** st-minus: st $src1,@-$src2

sem_status
m32rbf_sem_st_minus (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_new_src2;
  tmp_new_src2 = SUBSI (* FLD (i_src2), 4);
  {
    SI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_new_src2 << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_new_src2, opval);
  }
  {
    SI opval = tmp_new_src2;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r2) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_src2) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub: sub $dr,$sr

sem_status
m32rbf_sem_sub (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SUBSI (* FLD (i_dr), * FLD (i_sr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subv: subv $dr,$sr

sem_status
m32rbf_sem_subv (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI temp0;BI temp1;
  temp0 = SUBSI (* FLD (i_dr), * FLD (i_sr));
  temp1 = SUBOFSI (* FLD (i_dr), * FLD (i_sr), 0);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
  {
    BI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subx: subx $dr,$sr

sem_status
m32rbf_sem_subx (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and3.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI temp0;BI temp1;
  temp0 = SUBCSI (* FLD (i_dr), * FLD (i_sr), current_cpu->hardware.h_cond);
  temp1 = SUBCFSI (* FLD (i_dr), * FLD (i_sr), current_cpu->hardware.h_cond);
  {
    SI opval = temp0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_r1) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_dr) = opval;
  }
  {
    BI opval = temp1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** trap: trap $uimm4

sem_status
m32rbf_sem_trap (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_trap.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    USI opval = current_cpu->h_cr_get (((UINT) 6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (((UINT) 14), opval);
  }
  {
    USI opval = ADDSI (pc, 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (((UINT) 6), opval);
  }
  {
    UQI opval = current_cpu->hardware.h_bpsw;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "bbpsw" << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->hardware.h_bbpsw = opval;
  }
  {
    UQI opval = current_cpu->h_psw_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "bpsw" << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->hardware.h_bpsw = opval;
  }
  {
    UQI opval = ANDQI (current_cpu->h_psw_get (), 128);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "psw" << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->h_psw_set (opval);
  }
  {
    SI opval = current_cpu->m32r_trap (pc, FLD (f_uimm4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** unlock: unlock $src1,@$src2

sem_status
m32rbf_sem_unlock (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_st_d.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (current_cpu->hardware.h_lock) {
  {
    SI opval = * FLD (i_src1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_src2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, * FLD (i_src2), opval);
  }
}
  {
    BI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "lock" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_lock = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** clrpsw: clrpsw $uimm8

sem_status
m32rbf_sem_clrpsw (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clrpsw.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = ANDSI (current_cpu->h_cr_get (((UINT) 0)), ORSI (ZEXTQISI (INVQI (FLD (f_uimm8))), 65280));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** setpsw: setpsw $uimm8

sem_status
m32rbf_sem_setpsw (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_clrpsw.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = FLD (f_uimm8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bset: bset $uimm3,@($slo16,$sr)

sem_status
m32rbf_sem_bset (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bset.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    QI opval = ORQI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16))), SLLQI (1, SUBSI (7, FLD (f_uimm3))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_sr), FLD (f_simm16)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bclr: bclr $uimm3,@($slo16,$sr)

sem_status
m32rbf_sem_bclr (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bset.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    QI opval = ANDQI (current_cpu->GETMEMQI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16))), INVQI (SLLQI (1, SUBSI (7, FLD (f_uimm3)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (* FLD (i_sr), FLD (f_simm16)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (* FLD (i_sr), FLD (f_simm16)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** btst: btst $uimm3,$sr

sem_status
m32rbf_sem_btst (m32rbf_cpu* current_cpu, m32rbf_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bset.f
  sem_status status = SEM_STATUS_NORMAL;
  m32rbf_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = ANDQI (SRLQI (* FLD (i_sr), SUBSI (7, FLD (f_uimm3))), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cond" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cond = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

