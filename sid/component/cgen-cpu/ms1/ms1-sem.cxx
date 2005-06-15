/* Simulator instruction semantics for ms1.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "ms1.h"

using namespace ms1; // FIXME: namespace organization still wip
using namespace ms1; // FIXME: namespace organization still wip

#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

void
ms1_sem_x_invalid (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 0;

  {
    current_cpu->invalid_insn (pc);
    assert (0);
    /* NOTREACHED */
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** add: add $frdrrr,$frsr1,$frsr2

void
ms1_sem_add (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ADDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addu: addu $frdrrr,$frsr1,$frsr2

void
ms1_sem_addu (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ADDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addi: addi $frdr,$frsr1,#$imm16

void
ms1_sem_addi (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_tmp;
  tmp_tmp = ANDSI (FLD (f_imm16s), 65535);
  {
    SI opval = ADDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTHISI (tmp_tmp));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addui: addui $frdr,$frsr1,#$imm16z

void
ms1_sem_addui (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ADDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sub: sub $frdrrr,$frsr1,$frsr2

void
ms1_sem_sub (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SUBSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** subu: subu $frdrrr,$frsr1,$frsr2

void
ms1_sem_subu (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SUBSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** subi: subi $frdr,$frsr1,#$imm16

void
ms1_sem_subi (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_tmp;
  tmp_tmp = ANDSI (FLD (f_imm16s), 65535);
  {
    SI opval = SUBSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTHISI (tmp_tmp));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** subui: subui $frdr,$frsr1,#$imm16z

void
ms1_sem_subui (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SUBSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mul: mul $frdrrr,$frsr1,$frsr2

void
ms1_sem_mul (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_op1;
  HI tmp_op2;
  tmp_op1 = ANDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], 65535);
if (ORBI (LTHI (tmp_op1, -32768), GTHI (tmp_op1, 32767))) {
current_cpu->cgen_rtx_error ("operand out of range");
}
  tmp_op2 = ANDSI (current_cpu->hardware.h_spr[FLD (f_sr2)], 65535);
if (ORBI (LTHI (tmp_op2, -32768), GTHI (tmp_op2, 32767))) {
current_cpu->cgen_rtx_error ("operand out of range");
}
  {
    SI opval = MULSI (EXTHISI (tmp_op1), EXTHISI (tmp_op2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** muli: muli $frdr,$frsr1,#$imm16

void
ms1_sem_muli (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_op1;
  HI tmp_op2;
  tmp_op1 = ANDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], 65535);
if (ORBI (LTHI (tmp_op1, -32768), GTHI (tmp_op1, 32767))) {
current_cpu->cgen_rtx_error ("operand out of range");
}
  tmp_op2 = ANDSI (FLD (f_imm16s), 65535);
if (EQHI (tmp_op1, 0)) {
current_cpu->cgen_rtx_error ("op1 is 0");
}
if (EQHI (tmp_op2, 0)) {
current_cpu->cgen_rtx_error ("op2 is 0");
}
  {
    SI opval = MULSI (EXTHISI (tmp_op1), EXTHISI (tmp_op2));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** and: and $frdrrr,$frsr1,$frsr2

void
ms1_sem_and (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ANDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** andi: andi $frdr,$frsr1,#$imm16z

void
ms1_sem_andi (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ANDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** or: or $frdrrr,$frsr1,$frsr2

void
ms1_sem_or (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nop: nop

void
ms1_sem_nop (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ori: ori $frdr,$frsr1,#$imm16z

void
ms1_sem_ori (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xor: xor $frdrrr,$frsr1,$frsr2

void
ms1_sem_xor (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = XORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xori: xori $frdr,$frsr1,#$imm16z

void
ms1_sem_xori (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = XORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nand: nand $frdrrr,$frsr1,$frsr2

void
ms1_sem_nand (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = INVSI (ANDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nandi: nandi $frdr,$frsr1,#$imm16z

void
ms1_sem_nandi (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = INVSI (ANDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nor: nor $frdrrr,$frsr1,$frsr2

void
ms1_sem_nor (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = INVSI (ORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nori: nori $frdr,$frsr1,#$imm16z

void
ms1_sem_nori (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = INVSI (ORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xnor: xnor $frdrrr,$frsr1,$frsr2

void
ms1_sem_xnor (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = INVSI (XORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xnori: xnori $frdr,$frsr1,#$imm16z

void
ms1_sem_xnori (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = INVSI (XORSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTSISI (FLD (f_imm16u))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldui: ldui $frdr,#$imm16z

void
ms1_sem_ldui (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addui.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ANDSI (SLLSI (FLD (f_imm16u), 16), 0xffff0000);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lsl: lsl $frdrrr,$frsr1,$frsr2

void
ms1_sem_lsl (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SLLSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lsli: lsli $frdr,$frsr1,#$imm16

void
ms1_sem_lsli (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SLLSI (current_cpu->hardware.h_spr[FLD (f_sr1)], FLD (f_imm16s));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lsr: lsr $frdrrr,$frsr1,$frsr2

void
ms1_sem_lsr (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRLSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lsri: lsri $frdr,$frsr1,#$imm16

void
ms1_sem_lsri (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRLSI (current_cpu->hardware.h_spr[FLD (f_sr1)], FLD (f_imm16s));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** asr: asr $frdrrr,$frsr1,$frsr2

void
ms1_sem_asr (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRASI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** asri: asri $frdr,$frsr1,#$imm16

void
ms1_sem_asri (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SRASI (current_cpu->hardware.h_spr[FLD (f_sr1)], FLD (f_imm16s));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** brlt: brlt $frsr1,$frsr2,$imm16o

void
ms1_sem_brlt (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (LTSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)])) {
  {
    USI opval = ADDSI (pc, EXTSISI (FLD (f_imm16s)));
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** brle: brle $frsr1,$frsr2,$imm16o

void
ms1_sem_brle (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (LESI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)])) {
  {
    USI opval = ADDSI (pc, EXTSISI (FLD (f_imm16s)));
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** breq: breq $frsr1,$frsr2,$imm16o

void
ms1_sem_breq (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (EQSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)])) {
  {
    USI opval = ADDSI (pc, EXTSISI (FLD (f_imm16s)));
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** brne: brne $frsr1,$frsr2,$imm16o

void
ms1_sem_brne (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (NOTBI (EQSI (current_cpu->hardware.h_spr[FLD (f_sr1)], current_cpu->hardware.h_spr[FLD (f_sr2)]))) {
  {
    USI opval = ADDSI (pc, EXTSISI (FLD (f_imm16s)));
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** jmp: jmp $imm16o

void
ms1_sem_jmp (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    USI opval = ADDSI (pc, EXTSISI (FLD (f_imm16s)));
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** jal: jal $frdrrr,$frsr1

void
ms1_sem_jal (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (EQSI (current_cpu->hardware.h_spr[FLD (f_sr1)], 0)) {
current_cpu->do_syscall (pc);
} else {
{
  {
    SI opval = ADDSI (pc, 8);
    buf.h_spr_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<SI>(pc, opval, FLD (f_drrr)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
  }
  {
    USI opval = current_cpu->hardware.h_spr[FLD (f_sr1)];
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** dbnz: dbnz $frsr1,$imm16o

void
ms1_sem_dbnz (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
if (NOTBI (EQSI (current_cpu->hardware.h_spr[FLD (f_sr1)], 0))) {
  {
    USI opval = ADDSI (pc, EXTSISI (FLD (f_imm16s)));
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ei: ei

void
ms1_sem_ei (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

current_cpu->enable_interrupts ();

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** di: di

void
ms1_sem_di (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

current_cpu->disable_interrupts ();

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** si: si $frdrrr

void
ms1_sem_si (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_add.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SI opval = ADDSI (pc, 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_drrr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_drrr)] = opval;
  }
current_cpu->do_syscall (pc);
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** reti: reti $frsr1

void
ms1_sem_reti (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->enable_interrupts ();
  {
    USI opval = current_cpu->hardware.h_spr[FLD (f_sr1)];
    buf.h_pc_writes [(tick + 1) % ms1::pipe_sz].push (ms1::write<USI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldw: ldw $frdr,$frsr1,#$imm16

void
ms1_sem_ldw (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  USI tmp_ea;
  HI tmp_tmp;
  tmp_tmp = ANDSI (FLD (f_imm16s), 65535);
  tmp_ea = ANDSI (ADDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTHISI (tmp_tmp)), 0xfffffffc);
  {
    SI opval = current_cpu->GETMEMSI (pc, tmp_ea);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "spr" << '[' << FLD (f_dr) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_spr[FLD (f_dr)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stw: stw $frsr2,$frsr1,#$imm16

void
ms1_sem_stw (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_brlt.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  USI tmp_ea;
  HI tmp_tmp;
  tmp_tmp = ANDSI (FLD (f_imm16s), 65535);
  tmp_ea = ANDSI (ADDSI (current_cpu->hardware.h_spr[FLD (f_sr1)], EXTHISI (tmp_tmp)), 0xfffffffc);
  {
    SI opval = current_cpu->hardware.h_spr[FLD (f_sr2)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_ea << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_ea, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** break: break

void
ms1_sem_break (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

current_cpu->do_break (pc);

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** iflush: iflush

void
ms1_sem_iflush (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldctxt: ldctxt $frsr1,$frsr2,#$rc,#$rcnum,#$contnum

void
ms1_sem_ldctxt (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldfb: ldfb $frsr1,$frsr2,#$imm16z

void
ms1_sem_ldfb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stfb: stfb $frsr1,$frsr2,#$imm16z

void
ms1_sem_stfb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcb: fbcb $frsr1,#$rbbc,#$ball,#$brc,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbcb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbcb: mfbcb $frsr1,#$rbbc,$frsr2,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_mfbcb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcci: fbcci $frsr1,#$rbbc,#$ball,#$brc,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbcci (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbrci: fbrci $frsr1,#$rbbc,#$ball,#$brc,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbrci (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcri: fbcri $frsr1,#$rbbc,#$ball,#$brc,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbcri (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbrri: fbrri $frsr1,#$rbbc,#$ball,#$brc,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbrri (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbcci: mfbcci $frsr1,#$rbbc,$frsr2,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_mfbcci (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbrci: mfbrci $frsr1,#$rbbc,$frsr2,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_mfbrci (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbcri: mfbcri $frsr1,#$rbbc,$frsr2,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_mfbcri (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbrri: mfbrri $frsr1,#$rbbc,$frsr2,#$fbdisp,#$cell,#$dup,#$ctxdisp

void
ms1_sem_mfbrri (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcbdr: fbcbdr $frsr1,#$rbbc,$frsr2,#$ball2,#$brc2,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbcbdr (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rcfbcb: rcfbcb #$rbbc,#$type,#$ball,#$brc,#$rownum,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_rcfbcb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mrcfbcb: mrcfbcb $frsr2,#$rbbc,#$type,#$rownum,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_mrcfbcb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cbcast: cbcast #$mask,#$rc2,#$ctxdisp

void
ms1_sem_cbcast (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** dupcbcast: dupcbcast #$mask,#$cell,#$rc2,#$ctxdisp

void
ms1_sem_dupcbcast (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** wfbi: wfbi #$bankaddr,#$rownum1,#$cell,#$dup,#$ctxdisp

void
ms1_sem_wfbi (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** wfb: wfb $frsr1,$frsr2,#$fbdisp,#$rownum2,#$ctxdisp

void
ms1_sem_wfb (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rcrisc: rcrisc $frdrrr,#$rbbc,$frsr1,#$colnum,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_rcrisc (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcbinc: fbcbinc $frsr1,#$rbbc,#$incamt,#$rc1,#$cbrb,#$cell,#$dup,#$ctxdisp

void
ms1_sem_fbcbinc (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rcxmode: rcxmode $frsr2,#$rda,#$wr,#$xmode,#$mask1,#$fbdisp,#$rownum2,#$rc2,#$ctxdisp

void
ms1_sem_rcxmode (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** interleaver: intlvr $frsr1,#$mode,$frsr2,#$id,#$size

void
ms1_sem_interleaver (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** wfbinc: wfbinc #$rda,#$wr,#$fbincr,#$ball,#$colnum,#$length,#$rownum1,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_wfbinc (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mwfbinc: mwfbinc $frsr2,#$rda,#$wr,#$fbincr,#$length,#$rownum1,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_mwfbinc (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** wfbincr: wfbincr $frsr1,#$rda,#$wr,#$ball,#$colnum,#$length,#$rownum1,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_wfbincr (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mwfbincr: mwfbincr $frsr1,$frsr2,#$rda,#$wr,#$length,#$rownum1,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_mwfbincr (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcbincs: fbcbincs #$perm,#$a23,#$cr,#$cbs,#$incr,#$ccb,#$cdb,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_fbcbincs (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbcbincs: mfbcbincs $frsr1,#$perm,#$cbs,#$incr,#$ccb,#$cdb,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_mfbcbincs (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fbcbincrs: fbcbincrs $frsr1,#$perm,#$ball,#$colnum,#$cbx,#$ccb,#$cdb,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_fbcbincrs (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mfbcbincrs: mfbcbincrs $frsr1,$frsr2,#$perm,#$cbx,#$ccb,#$cdb,#$rownum2,#$dup,#$ctxdisp

void
ms1_sem_mfbcbincrs (ms1_cpu* current_cpu, ms1_scache* sem, const int tick, 
	ms1::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  ms1_scache* abuf = sem;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

