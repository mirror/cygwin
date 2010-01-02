/* Simulator instruction semantics for arm.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "arm7f.h"

using namespace arm7f; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

sem_status
arm_sem_x_invalid (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
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

// ********** b: b$cond $offset24

sem_status
arm_sem_b (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_b.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    USI opval = FLD (i_offset24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bl: bl$cond $offset24

sem_status
arm_sem_bl (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_b.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = ANDSI (ADDSI (pc, 4), -4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  {
    USI opval = FLD (i_offset24);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bx: bx$cond ${bx-rn}

sem_status
arm_sem_bx (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bx.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    USI opval = ANDSI (* FLD (i_bx_rn), 0xfffffffe);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (ANDSI (* FLD (i_bx_rn), 1)) {
  {
    BI opval = 1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-dec-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-dec-reg-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-inc-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-inc-reg-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-dec-nonpriv-imm-offset: ldr${cond}t $rd,???

sem_status
arm_sem_ldr_post_dec_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-dec-nonpriv-reg-offset: ldr${cond}t $rd,???

sem_status
arm_sem_ldr_post_dec_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-inc-nonpriv-imm-offset: ldr${cond}t $rd,???

sem_status
arm_sem_ldr_post_inc_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-post-inc-nonpriv-reg-offset: ldr${cond}t $rd,???

sem_status
arm_sem_ldr_post_inc_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-dec-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-dec-reg-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-inc-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-inc-reg-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-dec-wb-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-dec-wb-reg-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-inc-wb-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-pre-inc-wb-reg-offset: ldr${cond} $rd,???

sem_status
arm_sem_ldr_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-dec-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-dec-reg-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-inc-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-inc-reg-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-dec-nonpriv-imm-offset: ldr${cond}bt $rd,???

sem_status
arm_sem_ldrb_post_dec_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-dec-nonpriv-reg-offset: ldr${cond}bt $rd,???

sem_status
arm_sem_ldrb_post_dec_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-inc-nonpriv-imm-offset: ldr${cond}bt $rd,???

sem_status
arm_sem_ldrb_post_inc_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-post-inc-nonpriv-reg-offset: ldr${cond}bt $rd,???

sem_status
arm_sem_ldrb_post_inc_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-dec-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-dec-reg-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-inc-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-inc-reg-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-dec-wb-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-dec-wb-reg-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-inc-wb-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-pre-inc-wb-reg-offset: ldr${cond}b $rd,???

sem_status
arm_sem_ldrb_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-dec-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_str_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-dec-reg-offset: str${cond} $rd,???

sem_status
arm_sem_str_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-inc-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_str_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-inc-reg-offset: str${cond} $rd,???

sem_status
arm_sem_str_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-dec-nonpriv-imm-offset: ldr${cond}t $rd,???

sem_status
arm_sem_str_post_dec_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-dec-nonpriv-reg-offset: str${cond}t $rd,???

sem_status
arm_sem_str_post_dec_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-inc-nonpriv-imm-offset: ldr${cond}t $rd,???

sem_status
arm_sem_str_post_inc_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-post-inc-nonpriv-reg-offset: str${cond}t $rd,???

sem_status
arm_sem_str_post_inc_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-dec-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_str_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-dec-reg-offset: str${cond} $rd,???

sem_status
arm_sem_str_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-inc-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_str_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-inc-reg-offset: str${cond} $rd,???

sem_status
arm_sem_str_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-dec-wb-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_str_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-dec-wb-reg-offset: str${cond} $rd,???

sem_status
arm_sem_str_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-inc-wb-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_str_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-pre-inc-wb-reg-offset: str${cond} $rd,???

sem_status
arm_sem_str_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = * FLD (i_rd);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-dec-imm-offset: ldr${cond}b $rd,???

sem_status
arm_sem_strb_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-dec-reg-offset: str${cond}b $rd,???

sem_status
arm_sem_strb_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-inc-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_strb_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-inc-reg-offset: str${cond} $rd,???

sem_status
arm_sem_strb_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-dec-nonpriv-imm-offset: ldr${cond}t $rd,???

sem_status
arm_sem_strb_post_dec_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-dec-nonpriv-reg-offset: str${cond}t $rd,???

sem_status
arm_sem_strb_post_dec_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-inc-nonpriv-imm-offset: ldr${cond}t $rd,???

sem_status
arm_sem_strb_post_inc_nonpriv_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-post-inc-nonpriv-reg-offset: str${cond}t $rd,???

sem_status
arm_sem_strb_post_inc_nonpriv_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = * FLD (i_rn);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-dec-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_strb_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-dec-reg-offset: str${cond} $rd,???

sem_status
arm_sem_strb_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-inc-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_strb_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-inc-reg-offset: str${cond} $rd,???

sem_status
arm_sem_strb_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-dec-wb-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_strb_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-dec-wb-reg-offset: str${cond} $rd,???

sem_status
arm_sem_strb_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-inc-wb-imm-offset: ldr${cond} $rd,???

sem_status
arm_sem_strb_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_post_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (f_uimm12);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-pre-inc-wb-reg-offset: str${cond} $rd,???

sem_status
arm_sem_strb_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    QI opval = TRUNCSIQI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-dec-imm-offset: FIXME

sem_status
arm_sem_strh_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-dec-reg-offset: FIXME

sem_status
arm_sem_strh_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-inc-imm-offset: FIXME

sem_status
arm_sem_strh_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-inc-reg-offset: FIXME

sem_status
arm_sem_strh_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-dec-wb-imm-offset: FIXME

sem_status
arm_sem_strh_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-dec-wb-reg-offset: FIXME

sem_status
arm_sem_strh_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-inc-wb-imm-offset: FIXME

sem_status
arm_sem_strh_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-pre-inc-wb-reg-offset: FIXME

sem_status
arm_sem_strh_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-post-dec-imm-offset: FIXME

sem_status
arm_sem_strh_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-post-dec-reg-offset: FIXME

sem_status
arm_sem_strh_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-post-inc-imm-offset: FIXME

sem_status
arm_sem_strh_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-post-inc-reg-offset: FIXME

sem_status
arm_sem_strh_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
  {
    HI opval = TRUNCSIHI (* FLD (i_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-dec-imm-offset: FIXME

sem_status
arm_sem_ldrsb_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-dec-reg-offset: FIXME

sem_status
arm_sem_ldrsb_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-inc-imm-offset: FIXME

sem_status
arm_sem_ldrsb_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-inc-reg-offset: FIXME

sem_status
arm_sem_ldrsb_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-dec-wb-imm-offset: FIXME

sem_status
arm_sem_ldrsb_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-dec-wb-reg-offset: FIXME

sem_status
arm_sem_ldrsb_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-inc-wb-imm-offset: FIXME

sem_status
arm_sem_ldrsb_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-pre-inc-wb-reg-offset: FIXME

sem_status
arm_sem_ldrsb_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-post-dec-imm-offset: FIXME

sem_status
arm_sem_ldrsb_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-post-dec-reg-offset: FIXME

sem_status
arm_sem_ldrsb_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-post-inc-imm-offset: FIXME

sem_status
arm_sem_ldrsb_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsb-post-inc-reg-offset: FIXME

sem_status
arm_sem_ldrsb_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-dec-imm-offset: FIXME

sem_status
arm_sem_ldrh_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-dec-reg-offset: FIXME

sem_status
arm_sem_ldrh_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-inc-imm-offset: FIXME

sem_status
arm_sem_ldrh_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-inc-reg-offset: FIXME

sem_status
arm_sem_ldrh_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-dec-wb-imm-offset: FIXME

sem_status
arm_sem_ldrh_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-dec-wb-reg-offset: FIXME

sem_status
arm_sem_ldrh_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-inc-wb-imm-offset: FIXME

sem_status
arm_sem_ldrh_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-pre-inc-wb-reg-offset: FIXME

sem_status
arm_sem_ldrh_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-post-dec-imm-offset: FIXME

sem_status
arm_sem_ldrh_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-post-dec-reg-offset: FIXME

sem_status
arm_sem_ldrh_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-post-inc-imm-offset: FIXME

sem_status
arm_sem_ldrh_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-post-inc-reg-offset: FIXME

sem_status
arm_sem_ldrh_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-dec-imm-offset: FIXME

sem_status
arm_sem_ldrsh_pre_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-dec-reg-offset: FIXME

sem_status
arm_sem_ldrsh_pre_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-inc-imm-offset: FIXME

sem_status
arm_sem_ldrsh_pre_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-inc-reg-offset: FIXME

sem_status
arm_sem_ldrsh_pre_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
((void) 0); /*nop*/
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-dec-wb-imm-offset: FIXME

sem_status
arm_sem_ldrsh_pre_dec_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-dec-wb-reg-offset: FIXME

sem_status
arm_sem_ldrsh_pre_dec_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-inc-wb-imm-offset: FIXME

sem_status
arm_sem_ldrsh_pre_inc_wb_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-pre-inc-wb-reg-offset: FIXME

sem_status
arm_sem_ldrsh_pre_inc_wb_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
((void) 0); /*nop*/
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-post-dec-imm-offset: FIXME

sem_status
arm_sem_ldrsh_post_dec_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-post-dec-reg-offset: FIXME

sem_status
arm_sem_ldrsh_post_dec_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = SUBSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-post-inc-imm-offset: FIXME

sem_status
arm_sem_ldrsh_post_inc_imm_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = FLD (i_hdt_offset8);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrsh-post-inc-reg-offset: FIXME

sem_status
arm_sem_ldrsh_post_inc_reg_offset (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  SI tmp_offset;
  tmp_offset = * FLD (i_rm);
  tmp_addr = * FLD (i_rn);
if (EQSI (FLD (f_rd), 15)) {
  {
    USI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, tmp_addr));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
  tmp_addr = ADDSI (* FLD (i_rn), tmp_offset);
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mul: mul$cond${set-cc?} ${mul-rd},$rm,$rs

sem_status
arm_sem_mul (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_mla.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = MULSI (* FLD (i_rm), * FLD (i_rs));
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_mul_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_mul_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mla: mla$cond${set-cc?} ${mul-rd},$rm,$rs,${mul-rn}

sem_status
arm_sem_mla (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_mla.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  {
    SI opval = ADDSI (MULSI (* FLD (i_rm), * FLD (i_rs)), * FLD (i_mul_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_mul_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_mul_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** umull: umull$cond${set-cc?} $rdlo,$rdhi,$rm,$rs

sem_status
arm_sem_umull (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_umull.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_mul_result;
  SI tmp_hi;
  SI tmp_lo;
  tmp_mul_result = MULDI (ZEXTSIDI (* FLD (i_rs)), ZEXTSIDI (* FLD (i_rm)));
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdhi) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdhi) = opval;
  }
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdlo) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdlo) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** umlal: umlal$cond${set-cc?} $rdlo,$rdhi,$rm,$rs

sem_status
arm_sem_umlal (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_umull.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_mul_result;
  SI tmp_hi;
  SI tmp_lo;
  tmp_mul_result = JOINSIDI (* FLD (i_rdhi), * FLD (i_rdlo));
  tmp_mul_result = ADDDI (MULDI (ZEXTSIDI (* FLD (i_rs)), ZEXTSIDI (* FLD (i_rm))), tmp_mul_result);
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdhi) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdhi) = opval;
  }
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdlo) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdlo) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smull: smull$cond${set-cc?} $rdlo,$rdhi,$rm,$rs

sem_status
arm_sem_smull (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_umull.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_mul_result;
  SI tmp_hi;
  SI tmp_lo;
  tmp_mul_result = MULDI (EXTSIDI (* FLD (i_rs)), EXTSIDI (* FLD (i_rm)));
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdhi) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdhi) = opval;
  }
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdlo) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdlo) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** smlal: smlal$cond${set-cc?} $rdlo,$rdhi,$rm,$rs

sem_status
arm_sem_smlal (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_umull.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_mul_result;
  SI tmp_hi;
  SI tmp_lo;
  tmp_mul_result = JOINSIDI (* FLD (i_rdhi), * FLD (i_rdlo));
  tmp_mul_result = ADDDI (MULDI (EXTSIDI (* FLD (i_rs)), EXTSIDI (* FLD (i_rm))), tmp_mul_result);
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdhi) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdhi) = opval;
  }
  {
    SI opval = SUBWORDDISI (tmp_mul_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rdlo) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rdlo) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTDI (tmp_mul_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swp: swp$cond $rd,$rm,[$rn]

sem_status
arm_sem_swp (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_temp;
  tmp_temp = current_cpu->GETMEMSI (pc, * FLD (i_rn));
  {
    SI opval = * FLD (i_rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rn) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, * FLD (i_rn), opval);
  }
  {
    SI opval = tmp_temp;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swpb: swpb${cond}b $rd,$rm,[$rn]

sem_status
arm_sem_swpb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_temp;
  tmp_temp = current_cpu->GETMEMQI (pc, * FLD (i_rn));
  {
    QI opval = * FLD (i_rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) * FLD (i_rn) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, * FLD (i_rn), opval);
  }
  {
    SI opval = tmp_temp;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** swi: swi$cond ${swi-comment}

sem_status
arm_sem_swi (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    USI opval = current_cpu->arm_swi (pc, FLD (f_swi_comment));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** and-reg/imm-shift: and$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_and_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = ANDSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** and-reg/reg-shift: and$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_and_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = ANDSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** and-imm: and$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_and_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = ANDSI (* FLD (i_rn), FLD (f_imm12));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** orr-reg/imm-shift: orr$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_orr_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = ORSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** orr-reg/reg-shift: orr$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_orr_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = ORSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** orr-imm: orr$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_orr_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = ORSI (* FLD (i_rn), FLD (f_imm12));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** eor-reg/imm-shift: eor$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_eor_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = XORSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** eor-reg/reg-shift: eor$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_eor_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = XORSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** eor-imm: eor$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_eor_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = XORSI (* FLD (i_rn), FLD (f_imm12));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov-reg/imm-shift: mov$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_mov_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = tmp_operand2;
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov-reg/reg-shift: mov$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_mov_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = tmp_operand2;
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov-imm: mov$cond${set-cc?} $rd,$imm12

sem_status
arm_sem_mov_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = FLD (f_imm12);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bic-reg/imm-shift: bic$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_bic_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = ANDSI (* FLD (i_rn), INVSI (tmp_operand2));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bic-reg/reg-shift: bic$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_bic_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = ANDSI (* FLD (i_rn), INVSI (tmp_operand2));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bic-imm: bic$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_bic_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = ANDSI (* FLD (i_rn), INVSI (FLD (f_imm12)));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvn-reg/imm-shift: mvn$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_mvn_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = INVSI (tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvn-reg/reg-shift: mvn$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_mvn_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = INVSI (tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mvn-imm: mvn$cond${set-cc?} $rd,$imm12

sem_status
arm_sem_mvn_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = INVSI (FLD (f_imm12));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-reg/imm-shift: add$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_add_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = ADDSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = ADDCSI (tmp_temp_op1, tmp_temp_op2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (tmp_temp_op1, tmp_temp_op2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (tmp_temp_op1, tmp_temp_op2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-reg/reg-shift: add$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_add_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = ADDSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = ADDCSI (tmp_temp_op1, tmp_temp_op2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (tmp_temp_op1, tmp_temp_op2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (tmp_temp_op1, tmp_temp_op2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-imm: add$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_add_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = ADDSI (* FLD (i_rn), FLD (f_imm12));
if (EQSI (FLD (f_rd), 15)) {
{
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
{
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = ADDCSI (* FLD (i_rn), FLD (f_imm12), 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (* FLD (i_rn), FLD (f_imm12), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (* FLD (i_rn), FLD (f_imm12), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** adc-reg/imm-shift: adc$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_adc_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = ADDCSI (* FLD (i_rn), tmp_operand2, current_cpu->hardware.h_cbit);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = ADDCSI (tmp_temp_op1, tmp_temp_op2, current_cpu->hardware.h_cbit);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (tmp_temp_op1, tmp_temp_op2, current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (tmp_temp_op1, tmp_temp_op2, current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** adc-reg/reg-shift: adc$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_adc_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = ADDCSI (* FLD (i_rn), tmp_operand2, current_cpu->hardware.h_cbit);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = ADDCSI (tmp_temp_op1, tmp_temp_op2, current_cpu->hardware.h_cbit);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (tmp_temp_op1, tmp_temp_op2, current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (tmp_temp_op1, tmp_temp_op2, current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** adc-imm: adc$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_adc_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = ADDCSI (* FLD (i_rn), FLD (f_imm12), current_cpu->hardware.h_cbit);
if (EQSI (FLD (f_rd), 15)) {
{
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
{
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = ADDCSI (* FLD (i_rn), FLD (f_imm12), current_cpu->hardware.h_cbit);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (* FLD (i_rn), FLD (f_imm12), current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (* FLD (i_rn), FLD (f_imm12), current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub-reg/imm-shift: sub$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_sub_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op1, tmp_temp_op2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op1, tmp_temp_op2, 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op1, tmp_temp_op2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub-reg/reg-shift: sub$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_sub_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op1, tmp_temp_op2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op1, tmp_temp_op2, 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op1, tmp_temp_op2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub-imm: sub$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_sub_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = SUBSI (* FLD (i_rn), FLD (f_imm12));
if (EQSI (FLD (f_rd), 15)) {
{
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
{
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (* FLD (i_rn), FLD (f_imm12), 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (* FLD (i_rn), FLD (f_imm12), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (* FLD (i_rn), FLD (f_imm12), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbc-reg/imm-shift: sbc$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_sbc_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBCSI (* FLD (i_rn), tmp_operand2, NOTBI (current_cpu->hardware.h_cbit));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op1, tmp_temp_op2, NOTBI (current_cpu->hardware.h_cbit));
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op1, tmp_temp_op2, NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op1, tmp_temp_op2, NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbc-reg/reg-shift: sbc$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_sbc_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBCSI (* FLD (i_rn), tmp_operand2, NOTBI (current_cpu->hardware.h_cbit));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op1, tmp_temp_op2, NOTBI (current_cpu->hardware.h_cbit));
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op1, tmp_temp_op2, NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op1, tmp_temp_op2, NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** sbc-imm: sbc$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_sbc_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = SUBCSI (* FLD (i_rn), FLD (f_imm12), NOTBI (current_cpu->hardware.h_cbit));
if (EQSI (FLD (f_rd), 15)) {
{
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
{
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (* FLD (i_rn), FLD (f_imm12), NOTBI (current_cpu->hardware.h_cbit));
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (* FLD (i_rn), FLD (f_imm12), NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (* FLD (i_rn), FLD (f_imm12), NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** rsb-reg/imm-shift: rsb$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_rsb_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBSI (tmp_operand2, * FLD (i_rn));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op2, tmp_temp_op1, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op2, tmp_temp_op1, 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op2, tmp_temp_op1, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** rsb-reg/reg-shift: rsb$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_rsb_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBSI (tmp_operand2, * FLD (i_rn));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op2, tmp_temp_op1, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op2, tmp_temp_op1, 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op2, tmp_temp_op1, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** rsb-imm: rsb$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_rsb_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = SUBSI (FLD (f_imm12), * FLD (i_rn));
if (EQSI (FLD (f_rd), 15)) {
{
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
{
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (FLD (f_imm12), * FLD (i_rn), 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (FLD (f_imm12), * FLD (i_rn), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (FLD (f_imm12), * FLD (i_rn), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** rsc-reg/imm-shift: rsc$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_rsc_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBCSI (tmp_operand2, * FLD (i_rn), NOTBI (current_cpu->hardware.h_cbit));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op2, tmp_temp_op1, NOTBI (current_cpu->hardware.h_cbit));
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op2, tmp_temp_op1, NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op2, tmp_temp_op1, NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** rsc-reg/reg-shift: rsc$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_rsc_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  SI tmp_result;
  SI tmp_temp_op1;
  SI tmp_temp_op2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_temp_op1 = * FLD (i_rn);
  tmp_temp_op2 = tmp_operand2;
  tmp_result = SUBCSI (tmp_operand2, * FLD (i_rn), NOTBI (current_cpu->hardware.h_cbit));
if (EQSI (FLD (f_rd), 15)) {
{
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
} else {
{
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (tmp_temp_op2, tmp_temp_op1, NOTBI (current_cpu->hardware.h_cbit));
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (tmp_temp_op2, tmp_temp_op1, NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (tmp_temp_op2, tmp_temp_op1, NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** rsc-imm: rsc$cond${set-cc?} $rd,$rn,$imm12

sem_status
arm_sem_rsc_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = SUBCSI (FLD (f_imm12), * FLD (i_rn), NOTBI (current_cpu->hardware.h_cbit));
if (EQSI (FLD (f_rd), 15)) {
{
if (FLD (f_set_cc_)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
  {
    USI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
} else {
{
if (FLD (f_set_cc_)) {
{
  SI tmp_result;
  tmp_result = SUBCSI (FLD (f_imm12), * FLD (i_rn), NOTBI (current_cpu->hardware.h_cbit));
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (FLD (f_imm12), * FLD (i_rn), NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (FLD (f_imm12), * FLD (i_rn), NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** tst-reg/imm-shift: tst$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_tst_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = ANDSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** tst-reg/reg-shift: tst$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_tst_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = ANDSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** tst-imm: tst${cond}${set-cc?} $rn,$imm12

sem_status
arm_sem_tst_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_tst_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  BI tmp_carry_out;
if (EQSI (FLD (f_ror_imm8_rotate), 0)) {
  tmp_carry_out = current_cpu->hardware.h_cbit;
} else {
  tmp_carry_out = LTBI (FLD (f_ror_imm8), 0);
}
{
{
  {
    BI opval = EQSI (ANDSI (* FLD (i_rn), FLD (f_ror_imm8)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (ANDSI (* FLD (i_rn), FLD (f_ror_imm8)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** teq-reg/imm-shift: teq$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_teq_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
  tmp_carry_out = current_cpu->compute_carry_out_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm), current_cpu->hardware.h_cbit);
  tmp_result = XORSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** teq-reg/reg-shift: teq$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_teq_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  BI tmp_carry_out;
  SI tmp_result;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
  tmp_carry_out = current_cpu->compute_carry_out_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg), current_cpu->hardware.h_cbit);
  tmp_result = XORSI (* FLD (i_rn), tmp_operand2);
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** teq-imm: teq${cond}${set-cc?} $rn,$imm12

sem_status
arm_sem_teq_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_tst_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  BI tmp_carry_out;
if (EQSI (FLD (f_ror_imm8_rotate), 0)) {
  tmp_carry_out = current_cpu->hardware.h_cbit;
} else {
  tmp_carry_out = LTBI (FLD (f_ror_imm8), 0);
}
{
{
  {
    BI opval = EQSI (XORSI (* FLD (i_rn), FLD (f_ror_imm8)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (XORSI (* FLD (i_rn), FLD (f_ror_imm8)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = tmp_carry_out;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp-reg/imm-shift: cmp$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_cmp_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
  SI tmp_result;
  tmp_result = SUBCSI (* FLD (i_rn), tmp_operand2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (* FLD (i_rn), tmp_operand2, 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (* FLD (i_rn), tmp_operand2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp-reg/reg-shift: cmp$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_cmp_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
  SI tmp_result;
  tmp_result = SUBCSI (* FLD (i_rn), tmp_operand2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (* FLD (i_rn), tmp_operand2, 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (* FLD (i_rn), tmp_operand2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp-imm: cmp${cond}${set-cc?} $rn,$imm12

sem_status
arm_sem_cmp_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = SUBCSI (* FLD (i_rn), FLD (f_imm12), 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = NOTBI (SUBCFSI (* FLD (i_rn), FLD (f_imm12), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (* FLD (i_rn), FLD (f_imm12), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmn-reg/imm-shift: cmn$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftimm}

sem_status
arm_sem_cmn_reg_imm_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  tmp_operand2 = current_cpu->compute_operand2_immshift (* FLD (i_rm), FLD (f_operand2_shifttype), FLD (f_operand2_shiftimm));
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
  SI tmp_result;
  tmp_result = ADDCSI (* FLD (i_rn), tmp_operand2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (* FLD (i_rn), tmp_operand2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (* FLD (i_rn), tmp_operand2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmn-reg/reg-shift: cmn$cond${set-cc?} $rd,$rn,$rm,${operand2-shifttype} ${operand2-shiftreg}

sem_status
arm_sem_cmn_reg_reg_shift (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_reg_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_operand2;
  tmp_operand2 = current_cpu->compute_operand2_regshift (* FLD (i_rm), FLD (f_operand2_shifttype), * FLD (i_operand2_shiftreg));
if (EQSI (FLD (f_rd), 15)) {
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
} else {
{
  SI tmp_result;
  tmp_result = ADDCSI (* FLD (i_rn), tmp_operand2, 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (* FLD (i_rn), tmp_operand2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (* FLD (i_rn), tmp_operand2, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmn-imm: cmn${cond}${set-cc?} $rn,$imm12

sem_status
arm_sem_cmn_imm (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result;
  tmp_result = ADDCSI (* FLD (i_rn), FLD (f_imm12), 0);
{
  {
    BI opval = EQSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
  {
    BI opval = ADDCFSI (* FLD (i_rn), FLD (f_imm12), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (* FLD (i_rn), FLD (f_imm12), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmda: FIXME

sem_status
arm_sem_ldmda (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmda-sw: FIXME

sem_status
arm_sem_ldmda_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmda-wb: FIXME

sem_status
arm_sem_ldmda_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmda-sw-wb: FIXME

sem_status
arm_sem_ldmda_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmib: FIXME

sem_status
arm_sem_ldmib (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
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

// ********** ldmib-sw: FIXME

sem_status
arm_sem_ldmib_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmib-wb: FIXME

sem_status
arm_sem_ldmib_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmib-sw-wb: FIXME

sem_status
arm_sem_ldmib_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmia: FIXME

sem_status
arm_sem_ldmia (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmia-sw: FIXME

sem_status
arm_sem_ldmia_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmia-wb: FIXME

sem_status
arm_sem_ldmia_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmia-sw-wb: FIXME

sem_status
arm_sem_ldmia_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmdb: ldm$cond ..

sem_status
arm_sem_ldmdb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmdb-sw: ldm$cond ..

sem_status
arm_sem_ldmdb_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmdb-wb: FIXME

sem_status
arm_sem_ldmdb_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmdb-sw-wb: FIXME

sem_status
arm_sem_ldmdb_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    USI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 14) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 14)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (14, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (14, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 13) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 13)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (13, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (13, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 12) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 12)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (12, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (12, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 11) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 11)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (11, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (11, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 10) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 10)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (10, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (10, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 9) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 9)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (9, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (9, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 8)] = opval;
  }
} else {
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-usr" << '[' << SUBSI (8, 8) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr_usr[SUBSI (8, 8)] = opval;
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 7)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 6)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 5)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 4)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 3)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 2)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 1)] = opval;
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_addr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_gr[((UINT) 0)] = opval;
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmdb: FIXME

sem_status
arm_sem_stmdb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmdb-sw: FIXME

sem_status
arm_sem_stmdb_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmdb-wb: FIXME

sem_status
arm_sem_stmdb_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmdb-sw-wb: FIXME

sem_status
arm_sem_stmdb_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = SUBSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmib: FIXME

sem_status
arm_sem_stmib (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmib-sw: FIXME

sem_status
arm_sem_stmib_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmib-wb: FIXME

sem_status
arm_sem_stmib_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmib-sw-wb: FIXME

sem_status
arm_sem_stmib_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  tmp_addr = ADDSI (tmp_addr, 4);
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmia: FIXME

sem_status
arm_sem_stmia (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmia-sw: FIXME

sem_status
arm_sem_stmia_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmia-wb: FIXME

sem_status
arm_sem_stmia_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmia-sw-wb: FIXME

sem_status
arm_sem_stmia_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = ADDSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmda: FIXME

sem_status
arm_sem_stmda (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmda-sw: FIXME

sem_status
arm_sem_stmda_sw (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmda-wb: FIXME

sem_status
arm_sem_stmda_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmda-sw-wb: FIXME

sem_status
arm_sem_stmda_sw_wb (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldmda.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_addr;
  tmp_addr = * FLD (i_rn);
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
{
  {
    SI opval = ADDSI (current_cpu->hardware.h_gr[((UINT) 15)], 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 14))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 14)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (14, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 13))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 13)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (13, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 12))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 12)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (12, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 11))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 11)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (11, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 10))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 10)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (10, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 9))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 9)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (9, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 8))) {
{
if (ANDSI (FLD (f_reg_list), SLLSI (1, 15))) {
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
} else {
  {
    SI opval = current_cpu->hardware.h_gr_usr[SUBSI (8, 8)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
}
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 7)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 6)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 5)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 4)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 3)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 1)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
if (ANDSI (FLD (f_reg_list), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->hardware.h_gr[((UINT) 0)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  tmp_addr = SUBSI (tmp_addr, 4);
}
}
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rn) = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mrs-c: mrs$cond $rd,cpsr

sem_status
arm_sem_mrs_c (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->h_cpsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mrs-s: mrs$cond $rd,spsr

sem_status
arm_sem_mrs_s (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_pre_dec_imm_offset.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->h_spsr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    * FLD (i_rd) = opval;
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** msr-c: msr$cond cpsr,$rm

sem_status
arm_sem_msr_c (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = * FLD (i_rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cpsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cpsr_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** msr-s: msr$cond spsr,$rm

sem_status
arm_sem_msr_s (arm7f_cpu* current_cpu, arm_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_and_reg_imm_shift.f
  sem_status status = SEM_STATUS_NORMAL;
  arm_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = * FLD (i_rm);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spsr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_spsr_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

