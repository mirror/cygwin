/* Simulator instruction semantics for thumb.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

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
thumb_sem_x_invalid (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
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

// ********** lsl: lsl $rd,$rs,#$offset5

sem_status
thumb_sem_lsl (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lsl.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  tmp_carry_out = current_cpu->compute_carry_out_immshift (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), SHIFT_TYPE_LSL, FLD (f_offset5), current_cpu->hardware.h_cbit);
  {
    SI opval = SLLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
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

// ********** lsr: lsr $rd,$rs,#$offset5

sem_status
thumb_sem_lsr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lsl.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  tmp_carry_out = current_cpu->compute_carry_out_immshift (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), SHIFT_TYPE_LSR, FLD (f_offset5), current_cpu->hardware.h_cbit);
  {
    SI opval = SRLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
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

// ********** asr: asr $rd,$rs,#$offset5

sem_status
thumb_sem_asr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_lsl.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  tmp_carry_out = current_cpu->compute_carry_out_immshift (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), SHIFT_TYPE_ASR, FLD (f_offset5), current_cpu->hardware.h_cbit);
  {
    SI opval = SRASI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
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

// ********** add: add $rd,$rs,$rn

sem_status
thumb_sem_add (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
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
    BI opval = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addi: add $rd,$rs,#$offset3

sem_status
thumb_sem_addi (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
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
    BI opval = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub: sub $rd,$rs,$rn

sem_status
thumb_sem_sub (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = SUBSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subi: sub $rd,$rs,#$offset3

sem_status
thumb_sem_subi (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = SUBSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov: mov ${bit10-rd},#$offset8

sem_status
thumb_sem_mov (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_mov.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = FLD (f_offset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp: cmp ${bit10-rd},#$offset8

sem_status
thumb_sem_cmp (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_mov.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** addi8: add ${bit10-rd},#$offset8

sem_status
thumb_sem_addi8 (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_mov.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
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
    BI opval = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** subi8: sub ${bit10-rd},#$offset8

sem_status
thumb_sem_subi8 (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_mov.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = SUBSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-and: and $rd,$rs

sem_status
thumb_sem_alu_and (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-eor: eor $rd,$rs

sem_status
thumb_sem_alu_eor (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = XORSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-lsl: lsl $rd,$rs

sem_status
thumb_sem_alu_lsl (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_LSL, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = SLLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
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

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-lsr: lsr $rd,$rs

sem_status
thumb_sem_alu_lsr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_LSR, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = SRLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
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

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-asr: asr $rd,$rs

sem_status
thumb_sem_alu_asr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_ASR, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = SRASI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
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

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-ror: ror $rd,$rs

sem_status
thumb_sem_alu_ror (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_ROR, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = RORSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
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

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-adc: adc $rd,$rs

sem_status
thumb_sem_alu_adc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
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
    BI opval = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-sbc: sbc $rd,$rs

sem_status
thumb_sem_alu_sbc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit));
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit));
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-tst: tst $rd,$rs

sem_status
thumb_sem_alu_tst (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_x;
  tmp_x = ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
{
  {
    BI opval = EQSI (tmp_x, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (tmp_x, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-neg: neg $rd,$rs

sem_status
thumb_sem_alu_neg (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = NEGSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
{
  SI tmp_result;
  tmp_result = SUBCSI (0, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
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
    BI opval = NOTBI (SUBCFSI (0, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (0, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}
  {
    SI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-cmp: cmp $rd,$rs

sem_status
thumb_sem_alu_cmp (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-cmn: cmn $rd,$rs

sem_status
thumb_sem_alu_cmn (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
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
    BI opval = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-orr: orr $rd,$rs

sem_status
thumb_sem_alu_orr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ORSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-mul: mul $rd,$rs

sem_status
thumb_sem_alu_mul (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = MULSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-bic: bic $rd,$rs

sem_status
thumb_sem_alu_bic (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), INVSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** alu-mvn: mvn $rd,$rs

sem_status
thumb_sem_alu_mvn (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = INVSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }
{
  {
    BI opval = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "zbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_zbit = opval;
  }
  {
    BI opval = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "nbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_nbit = opval;
  }
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-rd-hs: add $rd,$hs

sem_status
thumb_sem_add_rd_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-hd-rs: add $hd,$rs

sem_status
thumb_sem_add_hd_rs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (FLD (f_rd), 7)) {
  {
    USI opval = ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "hiregs" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_hiregs_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-hd-hs: add $hd,$hs

sem_status
thumb_sem_add_hd_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (FLD (f_rd), 7)) {
  {
    USI opval = ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "hiregs" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_hiregs_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp-rd-hs: cmp $rd,$hs

sem_status
thumb_sem_cmp_rd_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp-hd-rs: cmp $hd,$rs

sem_status
thumb_sem_cmp_hd_rs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** cmp-hd-hs: cmp $hd,$hs

sem_status
thumb_sem_cmp_hd_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
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
    BI opval = NOTBI (SUBCFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_cbit = opval;
  }
  {
    BI opval = SUBOFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_vbit = opval;
  }
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov-rd-hs: mov $rd,$hs

sem_status
thumb_sem_mov_rd_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->thumb_h_hiregs_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov-hd-rs: mov $hd,$rs

sem_status
thumb_sem_mov_hd_rs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (FLD (f_rd), 7)) {
  {
    USI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "hiregs" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_hiregs_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** mov-hd-hs: mov $hd,$hs

sem_status
thumb_sem_mov_hd_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (EQSI (FLD (f_rd), 7)) {
  {
    USI opval = current_cpu->thumb_h_hiregs_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
} else {
  {
    SI opval = current_cpu->thumb_h_hiregs_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "hiregs" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_hiregs_set (FLD (f_rd), opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bx-rs: bx $rs

sem_status
thumb_sem_bx_rs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    USI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (NOTSI (ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 1))) {
  {
    BI opval = 0;
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

// ********** bx-hs: bx $hs

sem_status
thumb_sem_bx_hs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    USI opval = current_cpu->thumb_h_hiregs_get (FLD (f_rs));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (NOTSI (ANDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 1))) {
  {
    BI opval = 0;
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

// ********** ldr-pc: ldr ${bit10-rd},[pc,#$word8]

sem_status
thumb_sem_ldr_pc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (ANDSI (ADDSI (pc, 4), -4), FLD (f_word8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str: str $rd,[$rb,$ro]

sem_status
thumb_sem_str (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb: strb $rd,[$rb,$ro]

sem_status
thumb_sem_strb (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    QI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr: ldr $rd,[$rb,$ro]

sem_status
thumb_sem_ldr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb: ldrb $rd,[$rb,$ro]

sem_status
thumb_sem_ldrb (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh: strh $rd,[$rb,$ro]

sem_status
thumb_sem_strh (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh: ldrh $rd,[$rb,$ro]

sem_status
thumb_sem_ldrh (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldsb: ldsb $rd,[$rb,$ro]

sem_status
thumb_sem_ldsb (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldsh: ldsh $rd,[$rb,$ro]

sem_status
thumb_sem_ldsh (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-imm: str $rd,[$rb,#${offset5-7}]

sem_status
thumb_sem_str_imm (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_7)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_7)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-imm: ldr $rd,[$rb,#${offset5-7}]

sem_status
thumb_sem_ldr_imm (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_str_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_7)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strb-imm: strb $rd,[$rb,#$offset5]

sem_status
thumb_sem_strb_imm (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strb_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    QI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5)) << dec << ']' << ":=0x" << hex << (SI) opval << dec << "  ";
    current_cpu->SETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrb-imm: ldrb $rd,[$rb,#$offset5]

sem_status
thumb_sem_ldrb_imm (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strb_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** strh-imm: strh $rd,[$rb,#${offset5-6}]

sem_status
thumb_sem_strh_imm (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = current_cpu->thumb_h_gr_t_get (FLD (f_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_6)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_6)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldrh-imm: ldrh $rd,[$rb,#${offset5-6}]

sem_status
thumb_sem_ldrh_imm (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_strh_imm.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_6))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** str-sprel: str ${bit10-rd},[sp,#$word8]

sem_status
thumb_sem_str_sprel (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8)), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldr-sprel: ldr ${bit10-rd},[sp,#$word8]

sem_status
thumb_sem_ldr_sprel (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lda-pc: add ${bit10-rd},pc,$word8

sem_status
thumb_sem_lda_pc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (ANDSI (ADDSI (pc, 4), -4), FLD (f_word8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** lda-sp: add ${bit10-rd},sp,$word8

sem_status
thumb_sem_lda_sp (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rd) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** add-sp: add sp,#$sword7

sem_status
thumb_sem_add_sp (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add_sp.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_sword7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** sub-sp: add sp,#-$sword7

sem_status
thumb_sem_sub_sp (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_add_sp.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), FLD (f_sword7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** push: push {$rlist}

sem_status
thumb_sem_push (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stmia.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** push-lr: push {${rlist-lr}}

sem_status
thumb_sem_push_lr (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stmia.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_lr_t_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
  {
    SI opval = SUBSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_sp_t_get () << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** pop: pop {$rlist}

sem_status
thumb_sem_pop (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stmia.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 0), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 1), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 2), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 3), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 4), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 5), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 6), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 7), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** pop-pc: pop {${rlist-pc}}

sem_status
thumb_sem_pop_pc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stmia.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 0), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 1), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 2), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 3), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 4), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 5), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 6), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 7), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}
}
  {
    USI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_sp_t_get (), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sp-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_sp_t_set (opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** stmia: stmia $rb!,{$rlist}

sem_status
thumb_sem_stmia (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stmia.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 5));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->thumb_h_gr_t_get (((UINT) 7));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** ldmia: ldmia $rb!,{$rlist}

sem_status
thumb_sem_ldmia (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_stmia.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 0), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 1) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 1), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 2) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 2), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 3) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 3), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 4) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 4), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 5) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 5), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 6) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 6), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << ((UINT) 7) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (((UINT) 7), opval);
  }
  {
    SI opval = ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr-t" << '[' << FLD (f_bit10_rb) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), opval);
  }
}
}
}

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** beq: beq $soffset8

sem_status
thumb_sem_beq (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->hardware.h_zbit) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bne: bne $soffset8

sem_status
thumb_sem_bne (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->hardware.h_zbit)) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcs: bcs $soffset8

sem_status
thumb_sem_bcs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->hardware.h_cbit) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bcc: bcc $soffset8

sem_status
thumb_sem_bcc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->hardware.h_cbit)) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bmi: bmi $soffset8

sem_status
thumb_sem_bmi (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->hardware.h_nbit) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bpl: bpl $soffset8

sem_status
thumb_sem_bpl (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->hardware.h_nbit)) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bvs: bvs $soffset8

sem_status
thumb_sem_bvs (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->hardware.h_vbit) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bvc: bvc $soffset8

sem_status
thumb_sem_bvc (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->hardware.h_vbit)) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bhi: bhi $soffset8

sem_status
thumb_sem_bhi (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (ANDBI (current_cpu->hardware.h_cbit, NOTBI (current_cpu->hardware.h_zbit))) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bls: bls $soffset8

sem_status
thumb_sem_bls (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (ORBI (NOTBI (current_cpu->hardware.h_cbit), current_cpu->hardware.h_zbit)) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bge: bge $soffset8

sem_status
thumb_sem_bge (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit))) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** blt: blt $soffset8

sem_status
thumb_sem_blt (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit)) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bgt: bgt $soffset8

sem_status
thumb_sem_bgt (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (ORBI (current_cpu->hardware.h_zbit, XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit)))) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** ble: ble $soffset8

sem_status
thumb_sem_ble (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (ORBI (current_cpu->hardware.h_zbit, XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit))) {
  {
    USI opval = FLD (i_soffset8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** swi: swi $value8

sem_status
thumb_sem_swi (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_swi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = current_cpu->thumb_swi (pc, FLD (f_value8));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** b: b $offset11

sem_status
thumb_sem_b (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_b.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    USI opval = FLD (i_offset11);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

// ********** bl-hi: bl-hi ${lbwl-hi}

sem_status
thumb_sem_bl_hi (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bl_hi.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (ADDSI (pc, 4), SLLSI (FLD (f_lbwl_hi), 12));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "lr-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_lr_t_set (opval);
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

// ********** bl-lo: bl-lo ${lbwl-lo}

sem_status
thumb_sem_bl_lo (arm7f_cpu* current_cpu, thumb_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_bl_lo.f
  sem_status status = SEM_STATUS_NORMAL;
  thumb_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_cur_pc;
  tmp_cur_pc = pc;
  {
    USI opval = ADDSI (current_cpu->thumb_h_lr_t_get (), SLLSI (FLD (f_lbwl_lo), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
  {
    SI opval = ORSI (ADDSI (tmp_cur_pc, 2), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "lr-t" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->thumb_h_lr_t_set (opval);
  }
}

  current_cpu->done_cti_insn (npc, status);
  return status;
#undef FLD
}

