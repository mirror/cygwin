/* Simulator instruction semantics for sh5_media.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh5.h"

using namespace sh5; // FIXME: namespace organization still wip
using namespace sh5_media; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

void
sh5_media_sem_x_invalid (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
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

// ********** add: add $rm, $rn, $rd

void
sh5_media_sem_add (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addl: add.l $rm, $rn, $rd

void
sh5_media_sem_addl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ADDSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addi: addi $rm, $disp10, $rd

void
sh5_media_sem_addi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addil: addi.l $rm, $disp10, $rd

void
sh5_media_sem_addil (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (ADDSI (EXTSISI (FLD (f_disp10)), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addzl: addz.l $rm, $rn, $rd

void
sh5_media_sem_addzl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTSIDI (ADDSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** alloco: alloco $rm, $disp6x32

void
sh5_media_sem_alloco (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_left), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** and: and $rm, $rn, $rd

void
sh5_media_sem_and (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ANDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** andc: andc $rm, $rn, $rd

void
sh5_media_sem_andc (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ANDDI (current_cpu->h_gr_get (FLD (f_left)), INVDI (current_cpu->h_gr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** andi: andi $rm, $disp10, $rd

void
sh5_media_sem_andi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ANDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** beq: beq$likely $rm, $rn, $tra

void
sh5_media_sem_beq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (EQDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** beqi: beqi$likely $rm, $imm6, $tra

void
sh5_media_sem_beqi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (EQDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_imm6)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bge: bge$likely $rm, $rn, $tra

void
sh5_media_sem_bge (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (GEDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bgeu: bgeu$likely $rm, $rn, $tra

void
sh5_media_sem_bgeu (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (GEUDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bgt: bgt$likely $rm, $rn, $tra

void
sh5_media_sem_bgt (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (GTDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bgtu: bgtu$likely $rm, $rn, $tra

void
sh5_media_sem_bgtu (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (GTUDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** blink: blink $trb, $rd

void
sh5_media_sem_blink (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = ORDI (ADDDI (pc, 4), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_trb)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
if (EQSI (FLD (f_dest), 63)) {
current_cpu->cg_profile_jump (pc, current_cpu->hardware.h_tr[FLD (f_trb)]);
} else {
current_cpu->cg_profile (pc, current_cpu->hardware.h_tr[FLD (f_trb)]);
}
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bne: bne$likely $rm, $rn, $tra

void
sh5_media_sem_bne (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (NEDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bnei: bnei$likely $rm, $imm6, $tra

void
sh5_media_sem_bnei (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_beqi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_optimization (FLD (f_likely));
if (NEDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_imm6)))) {
  {
    UDI opval = current_cpu->hardware.h_tr[FLD (f_tra)];
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** brk: brk

void
sh5_media_sem_brk (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

current_cpu->sh64_break (pc);

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** byterev: byterev $rm, $rd

void
sh5_media_sem_byterev (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_source;
  DI tmp_result;
  tmp_source = current_cpu->h_gr_get (FLD (f_left));
  tmp_result = 0;
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
{
  tmp_result = ORDI (SLLDI (tmp_result, 8), ANDDI (tmp_source, 255));
  tmp_source = SRLDI (tmp_source, 8);
}
  {
    DI opval = tmp_result;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpeq: cmpeq $rm, $rn, $rd

void
sh5_media_sem_cmpeq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ((EQDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpgt: cmpgt $rm, $rn, $rd

void
sh5_media_sem_cmpgt (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ((GTDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpgtu: cmpgtu $rm,$rn, $rd

void
sh5_media_sem_cmpgtu (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ((GTUDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmveq: cmveq $rm, $rn, $rd

void
sh5_media_sem_cmveq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (EQDI (current_cpu->h_gr_get (FLD (f_left)), 0)) {
  {
    DI opval = current_cpu->h_gr_get (FLD (f_right));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmvne: cmvne $rm, $rn, $rd

void
sh5_media_sem_cmvne (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

if (NEDI (current_cpu->h_gr_get (FLD (f_left)), 0)) {
  {
    DI opval = current_cpu->h_gr_get (FLD (f_right));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fabsd: fabs.d $drgh, $drf

void
sh5_media_sem_fabsd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fabsd (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fabss: fabs.s $frgh, $frf

void
sh5_media_sem_fabss (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fabss (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** faddd: fadd.d $drg, $drh, $drf

void
sh5_media_sem_faddd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_faddd (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fadds: fadd.s $frg, $frh, $frf

void
sh5_media_sem_fadds (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fadds (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpeqd: fcmpeq.d $drg, $drh, $rd

void
sh5_media_sem_fcmpeqd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpeqd (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpeqs: fcmpeq.s $frg, $frh, $rd

void
sh5_media_sem_fcmpeqs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpeqs (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpged: fcmpge.d $drg, $drh, $rd

void
sh5_media_sem_fcmpged (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpged (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpges: fcmpge.s $frg, $frh, $rd

void
sh5_media_sem_fcmpges (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpges (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpgtd: fcmpgt.d $drg, $drh, $rd

void
sh5_media_sem_fcmpgtd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpgtd (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpgts: fcmpgt.s $frg, $frh, $rd

void
sh5_media_sem_fcmpgts (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpgts (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpund: fcmpun.d $drg, $drh, $rd

void
sh5_media_sem_fcmpund (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpund (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcmpuns: fcmpun.s $frg, $frh, $rd

void
sh5_media_sem_fcmpuns (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTBIDI (current_cpu->sh64_fcmpuns (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcnvds: fcnv.ds $drgh, $frf

void
sh5_media_sem_fcnvds (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fcnvds (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fcnvsd: fcnv.sd $frgh, $drf

void
sh5_media_sem_fcnvsd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fcnvsd (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fdivd: fdiv.d $drg, $drh, $drf

void
sh5_media_sem_fdivd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fdivd (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fdivs: fdiv.s $frg, $frh, $frf

void
sh5_media_sem_fdivs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fdivs (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fgetscr: fgetscr $frf

void
sh5_media_sem_fgetscr (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = SUBWORDSISF (current_cpu->hardware.h_fpscr);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fiprs: fipr.s $fvg, $fvh, $frf

void
sh5_media_sem_fiprs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fiprs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SF opval = current_cpu->h_fv_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fv" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fv_set (FLD (f_left), opval);
  }
  {
    SF opval = current_cpu->h_fv_get (FLD (f_right));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fv" << '[' << FLD (f_right) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fv_set (FLD (f_right), opval);
  }
  {
    SF opval = current_cpu->sh64_fiprs (FLD (f_left), FLD (f_right));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fldd: fld.d $rm, $disp10x8, $drf

void
sh5_media_sem_fldd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->GETMEMDF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fldp: fld.p $rm, $disp10x8, $fpf

void
sh5_media_sem_fldp (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SF opval = current_cpu->h_fp_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fp" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fp_set (FLD (f_dest), opval);
  }
current_cpu->sh64_fldp (pc, current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x8), FLD (f_dest));
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** flds: fld.s $rm, $disp10x4, $frf

void
sh5_media_sem_flds (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->GETMEMSF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x4)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fldxd: fldx.d $rm, $rn, $drf

void
sh5_media_sem_fldxd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldxd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->GETMEMDF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fldxp: fldx.p $rm, $rn, $fpf

void
sh5_media_sem_fldxp (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SF opval = current_cpu->h_fp_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fp" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fp_set (FLD (f_dest), opval);
  }
current_cpu->sh64_fldp (pc, current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)), FLD (f_dest));
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fldxs: fldx.s $rm, $rn, $frf

void
sh5_media_sem_fldxs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldxs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->GETMEMSF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** floatld: float.ld $frgh, $drf

void
sh5_media_sem_floatld (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_floatld (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** floatls: float.ls $frgh, $frf

void
sh5_media_sem_floatls (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_floatls (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** floatqd: float.qd $drgh, $drf

void
sh5_media_sem_floatqd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_floatqd (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** floatqs: float.qs $drgh, $frf

void
sh5_media_sem_floatqs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_floatqs (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmacs: fmac.s $frg, $frh, $frf

void
sh5_media_sem_fmacs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fadds (current_cpu->hardware.h_fr[FLD (f_dest)], current_cpu->sh64_fmuls (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmovd: fmov.d $drgh, $drf

void
sh5_media_sem_fmovd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->h_dr_get (FLD (f_left_right));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmovdq: fmov.dq $drgh, $rd

void
sh5_media_sem_fmovdq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmovdq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SUBWORDDFDI (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmovls: fmov.ls $rm, $frf

void
sh5_media_sem_fmovls (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_flds.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = SUBWORDSISF (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmovqd: fmov.qd $rm, $drf

void
sh5_media_sem_fmovqd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = SUBWORDDIDF (current_cpu->h_gr_get (FLD (f_left)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmovs: fmov.s $frgh, $frf

void
sh5_media_sem_fmovs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->hardware.h_fr[FLD (f_left_right)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmovsl: fmov.sl $frgh, $rd

void
sh5_media_sem_fmovsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SUBWORDSFSI (current_cpu->hardware.h_fr[FLD (f_left_right)]));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmuld: fmul.d $drg, $drh, $drf

void
sh5_media_sem_fmuld (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fmuld (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fmuls: fmul.s $frg, $frh, $frf

void
sh5_media_sem_fmuls (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fmuls (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fnegd: fneg.d $drgh, $drf

void
sh5_media_sem_fnegd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fnegd (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fnegs: fneg.s $frgh, $frf

void
sh5_media_sem_fnegs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fnegs (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fputscr: fputscr $frgh

void
sh5_media_sem_fputscr (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmovsl.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SUBWORDSFSI (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fpscr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fpscr = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fsqrtd: fsqrt.d $drgh, $drf

void
sh5_media_sem_fsqrtd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fsqrtd (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fsqrts: fsqrt.s $frgh, $frf

void
sh5_media_sem_fsqrts (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fsqrts (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fstd: fst.d $rm, $disp10x8, $drf

void
sh5_media_sem_fstd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fstd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->h_dr_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x8)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMDF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x8)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fstp: fst.p $rm, $disp10x8, $fpf

void
sh5_media_sem_fstp (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldp.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SF opval = current_cpu->h_fp_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fp" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fp_set (FLD (f_dest), opval);
  }
current_cpu->sh64_fstp (pc, current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x8), FLD (f_dest));
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fsts: fst.s $rm, $disp10x4, $frf

void
sh5_media_sem_fsts (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fsts.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->hardware.h_fr[FLD (f_dest)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x4)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp10x4)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fstxd: fstx.d $rm, $rn, $drf

void
sh5_media_sem_fstxd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fstxd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->h_dr_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMDF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fstxp: fstx.p $rm, $rn, $fpf

void
sh5_media_sem_fstxp (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fldxp.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SF opval = current_cpu->h_fp_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fp" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fp_set (FLD (f_dest), opval);
  }
current_cpu->sh64_fstp (pc, current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)), FLD (f_dest));
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fstxs: fstx.s $rm, $rn, $frf

void
sh5_media_sem_fstxs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fstxs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->hardware.h_fr[FLD (f_dest)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSF (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fsubd: fsub.d $drg, $drh, $drf

void
sh5_media_sem_fsubd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_faddd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_fsubd (current_cpu->h_dr_get (FLD (f_left)), current_cpu->h_dr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fsubs: fsub.s $frg, $frh, $frf

void
sh5_media_sem_fsubs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fmacs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_fsubs (current_cpu->hardware.h_fr[FLD (f_left)], current_cpu->hardware.h_fr[FLD (f_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ftrcdl: ftrc.dl $drgh, $frf

void
sh5_media_sem_ftrcdl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvds.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_ftrcdl (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ftrcsl: ftrc.sl $frgh, $frf

void
sh5_media_sem_ftrcsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabss.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SF opval = current_cpu->sh64_ftrcsl (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_fr[FLD (f_dest)] = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ftrcdq: ftrc.dq $drgh, $drf

void
sh5_media_sem_ftrcdq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fabsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_ftrcdq (current_cpu->h_dr_get (FLD (f_left_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ftrcsq: ftrc.sq $frgh, $drf

void
sh5_media_sem_ftrcsq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DF opval = current_cpu->sh64_ftrcsq (current_cpu->hardware.h_fr[FLD (f_left_right)]);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "dr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_dr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ftrvs: ftrv.s $mtrxg, $fvh, $fvf

void
sh5_media_sem_ftrvs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_ftrvs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    SF opval = current_cpu->h_fmtx_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fmtx" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fmtx_set (FLD (f_left), opval);
  }
  {
    SF opval = current_cpu->h_fv_get (FLD (f_right));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fv" << '[' << FLD (f_right) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fv_set (FLD (f_right), opval);
  }
  {
    SF opval = current_cpu->h_fv_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "fv" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_fv_set (FLD (f_dest), opval);
  }
current_cpu->sh64_ftrvs (FLD (f_left), FLD (f_right), FLD (f_dest));
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** getcfg: getcfg $rm, $disp6, $rd

void
sh5_media_sem_getcfg (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_address;
  tmp_address = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
current_cpu->sh64_save_cfg_address (tmp_address);
  {
    DI opval = current_cpu->GETMEMSI (pc, tmp_address);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** getcon: getcon $crk, $rd

void
sh5_media_sem_getcon (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->h_cr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** gettr: gettr $trb, $rd

void
sh5_media_sem_gettr (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_blink.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->hardware.h_tr[FLD (f_trb)];
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** icbi: icbi $rm, $disp6x32

void
sh5_media_sem_icbi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_left), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldb: ld.b $rm, $disp10, $rd

void
sh5_media_sem_ldb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTQIDI (current_cpu->GETMEMQI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldl: ld.l $rm, $disp10x4, $rd

void
sh5_media_sem_ldl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_ldl.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (current_cpu->GETMEMSI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x4)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldq: ld.q $rm, $disp10x8, $rd

void
sh5_media_sem_ldq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_ldq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->GETMEMDI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x8))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldub: ld.ub $rm, $disp10, $rd

void
sh5_media_sem_ldub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTQIDI (current_cpu->GETMEMQI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lduw: ld.uw $rm, $disp10x2, $rd

void
sh5_media_sem_lduw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTHIDI (current_cpu->GETMEMHI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x2)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldw: ld.w $rm, $disp10x2, $rd

void
sh5_media_sem_ldw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_lduw.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTHIDI (current_cpu->GETMEMHI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x2)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldhil: ldhi.l $rm, $disp6, $rd

void
sh5_media_sem_ldhil (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  SI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = ADDDI (ANDDI (tmp_addr, 3), 1);
  tmp_val = 0;
if (ANDQI (tmp_bytecount, 4)) {
  {
    DI opval = EXTSIDI (current_cpu->GETMEMSI (pc, ANDDI (tmp_addr, -4)));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (tmp_addr, -4))));
}
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
  {
    DI opval = EXTSIDI (tmp_val);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
} else {
{
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (tmp_addr, -4))));
}
  {
    DI opval = EXTSIDI (SLLSI (tmp_val, SUBSI (32, MULSI (8, tmp_bytecount))));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldhiq: ldhi.q $rm, $disp6, $rd

void
sh5_media_sem_ldhiq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  DI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = ADDDI (ANDDI (tmp_addr, 7), 1);
  tmp_val = 0;
if (ANDQI (tmp_bytecount, 8)) {
  {
    DI opval = current_cpu->GETMEMDI (pc, ANDDI (tmp_addr, -8));
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
if (ANDQI (tmp_bytecount, 4)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 32), ZEXTSIDI (current_cpu->GETMEMSI (pc, ANDDI (tmp_addr, -8))));
}
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (tmp_addr, -4))));
}
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
  {
    DI opval = tmp_val;
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
} else {
{
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (tmp_addr, -4))));
}
if (ANDQI (tmp_bytecount, 4)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 32), ZEXTSIDI (current_cpu->GETMEMSI (pc, ANDDI (tmp_addr, -8))));
}
  {
    DI opval = SLLDI (tmp_val, SUBSI (64, MULSI (8, tmp_bytecount)));
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldlol: ldlo.l $rm, $disp6, $rd

void
sh5_media_sem_ldlol (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  SI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = SUBSI (4, ANDDI (tmp_addr, 3));
  tmp_val = 0;
if (ANDQI (tmp_bytecount, 4)) {
  {
    DI opval = EXTSIDI (current_cpu->GETMEMSI (pc, tmp_addr));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2))));
}
  {
    DI opval = EXTSIDI (SLLSI (tmp_val, SUBSI (32, MULSI (8, tmp_bytecount))));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
} else {
{
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2))));
}
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDSI (SLLSI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
  {
    DI opval = EXTSIDI (tmp_val);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldloq: ldlo.q $rm, $disp6, $rd

void
sh5_media_sem_ldloq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_getcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  DI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = SUBSI (8, ANDDI (tmp_addr, 7));
  tmp_val = 0;
if (ANDQI (tmp_bytecount, 8)) {
  {
    DI opval = current_cpu->GETMEMDI (pc, tmp_addr);
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2))));
}
if (ANDQI (tmp_bytecount, 4)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 32), ZEXTSIDI (current_cpu->GETMEMSI (pc, ANDDI (ADDDI (tmp_addr, 3), -4))));
}
  {
    DI opval = SLLDI (tmp_val, SUBSI (64, MULSI (8, tmp_bytecount)));
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
} else {
{
if (ANDQI (tmp_bytecount, 4)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 32), ZEXTSIDI (current_cpu->GETMEMSI (pc, ANDDI (ADDDI (tmp_addr, 3), -4))));
}
if (ANDQI (tmp_bytecount, 2)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 16), ZEXTHIDI (current_cpu->GETMEMHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2))));
}
if (ANDQI (tmp_bytecount, 1)) {
  tmp_val = ADDDI (SLLDI (tmp_val, 8), ZEXTQIDI (current_cpu->GETMEMQI (pc, tmp_addr)));
}
  {
    DI opval = tmp_val;
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldxb: ldx.b $rm, $rn, $rd

void
sh5_media_sem_ldxb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTQIDI (current_cpu->GETMEMQI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldxl: ldx.l $rm, $rn, $rd

void
sh5_media_sem_ldxl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (current_cpu->GETMEMSI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldxq: ldx.q $rm, $rn, $rd

void
sh5_media_sem_ldxq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->GETMEMDI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldxub: ldx.ub $rm, $rn, $rd

void
sh5_media_sem_ldxub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTQIDI (current_cpu->GETMEMUQI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldxuw: ldx.uw $rm, $rn, $rd

void
sh5_media_sem_ldxuw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ZEXTHIDI (current_cpu->GETMEMUHI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldxw: ldx.w $rm, $rn, $rd

void
sh5_media_sem_ldxw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTHIDI (current_cpu->GETMEMHI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mabsl: mabs.l $rm, $rd

void
sh5_media_sem_mabsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ABSSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1));
  tmp_result1 = ABSSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mabsw: mabs.w $rm, $rd

void
sh5_media_sem_mabsw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ABSHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3));
  tmp_result1 = ABSHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2));
  tmp_result2 = ABSHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1));
  tmp_result3 = ABSHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** maddl: madd.l $rm, $rn, $rd

void
sh5_media_sem_maddl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ADDSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1));
  tmp_result1 = ADDSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** maddw: madd.w $rm, $rn, $rd

void
sh5_media_sem_maddw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ADDHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3));
  tmp_result1 = ADDHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2));
  tmp_result2 = ADDHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1));
  tmp_result3 = ADDHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** maddsl: madds.l $rm, $rn, $rd

void
sh5_media_sem_maddsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ((LTDI (ADDDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1))), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (ADDDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1))), SLLDI (1, SUBSI (32, 1)))) ? (ADDDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result1 = ((LTDI (ADDDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0))), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (ADDDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0))), SLLDI (1, SUBSI (32, 1)))) ? (ADDDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0)))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** maddsub: madds.ub $rm, $rn, $rd

void
sh5_media_sem_maddsub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result1 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result2 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result3 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result4 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result5 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result6 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result7 = ((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))), MAKEDI (0, 0))) ? (0) : (((LTDI (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))), SLLDI (1, 8))) ? (ADDDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0)))) : (SUBQI (SLLQI (1, 8), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** maddsw: madds.w $rm, $rn, $rd

void
sh5_media_sem_maddsw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3))), SLLDI (1, SUBSI (16, 1)))) ? (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result1 = ((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2))), SLLDI (1, SUBSI (16, 1)))) ? (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result2 = ((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1))), SLLDI (1, SUBSI (16, 1)))) ? (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result3 = ((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0))), SLLDI (1, SUBSI (16, 1)))) ? (ADDDI (EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTHIDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmpeqb: mcmpeq.b $rm, $rn, $rd

void
sh5_media_sem_mcmpeqb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))) ? (INVQI (0)) : (0));
  tmp_result1 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))) ? (INVQI (0)) : (0));
  tmp_result2 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))) ? (INVQI (0)) : (0));
  tmp_result3 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))) ? (INVQI (0)) : (0));
  tmp_result4 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))) ? (INVQI (0)) : (0));
  tmp_result5 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))) ? (INVQI (0)) : (0));
  tmp_result6 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))) ? (INVQI (0)) : (0));
  tmp_result7 = ((EQQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))) ? (INVQI (0)) : (0));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmpeql: mcmpeq.l $rm, $rn, $rd

void
sh5_media_sem_mcmpeql (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ((EQSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1))) ? (INVSI (0)) : (0));
  tmp_result1 = ((EQSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0))) ? (INVSI (0)) : (0));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmpeqw: mcmpeq.w $rm, $rn, $rd

void
sh5_media_sem_mcmpeqw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ((EQHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3))) ? (INVHI (0)) : (0));
  tmp_result1 = ((EQHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2))) ? (INVHI (0)) : (0));
  tmp_result2 = ((EQHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1))) ? (INVHI (0)) : (0));
  tmp_result3 = ((EQHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0))) ? (INVHI (0)) : (0));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmpgtl: mcmpgt.l $rm, $rn, $rd

void
sh5_media_sem_mcmpgtl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ((GTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1))) ? (INVSI (0)) : (0));
  tmp_result1 = ((GTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0))) ? (INVSI (0)) : (0));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmpgtub: mcmpgt.ub $rm, $rn, $rd

void
sh5_media_sem_mcmpgtub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))) ? (INVQI (0)) : (0));
  tmp_result1 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))) ? (INVQI (0)) : (0));
  tmp_result2 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))) ? (INVQI (0)) : (0));
  tmp_result3 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))) ? (INVQI (0)) : (0));
  tmp_result4 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))) ? (INVQI (0)) : (0));
  tmp_result5 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))) ? (INVQI (0)) : (0));
  tmp_result6 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))) ? (INVQI (0)) : (0));
  tmp_result7 = ((GTUQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))) ? (INVQI (0)) : (0));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmpgtw: mcmpgt.w $rm, $rn, $rd

void
sh5_media_sem_mcmpgtw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ((GTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3))) ? (INVHI (0)) : (0));
  tmp_result1 = ((GTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2))) ? (INVHI (0)) : (0));
  tmp_result2 = ((GTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1))) ? (INVHI (0)) : (0));
  tmp_result3 = ((GTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0))) ? (INVHI (0)) : (0));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcmv: mcmv $rm, $rn, $rd

void
sh5_media_sem_mcmv (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), ANDDI (current_cpu->h_gr_get (FLD (f_dest)), INVDI (current_cpu->h_gr_get (FLD (f_right)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcnvslw: mcnvs.lw $rm, $rn, $rd

void
sh5_media_sem_mcnvslw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SLLDI (1, SUBSI (16, 1)))) ? (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result1 = ((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), SLLDI (1, SUBSI (16, 1)))) ? (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result2 = ((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1), SLLDI (1, SUBSI (16, 1)))) ? (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result3 = ((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0), SLLDI (1, SUBSI (16, 1)))) ? (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcnvswb: mcnvs.wb $rm, $rn, $rd

void
sh5_media_sem_mcnvswb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result1 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result2 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result3 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result4 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result5 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result6 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  tmp_result7 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0), NEGDI (SLLDI (1, SUBSI (8, 1))))) ? (NEGQI (SLLQI (1, SUBSI (8, 1)))) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0), SLLDI (1, SUBSI (8, 1)))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)) : (SUBQI (SLLQI (1, SUBSI (8, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mcnvswub: mcnvs.wub $rm, $rn, $rd

void
sh5_media_sem_mcnvswub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result1 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result2 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result3 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result4 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result5 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result6 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1)) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result7 = ((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0), MAKEDI (0, 0))) ? (0) : (((LTHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0), SLLDI (1, 8))) ? (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)) : (SUBQI (SLLQI (1, 8), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr1: mextr1 $rm, $rn, $rd

void
sh5_media_sem_mextr1 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 1);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 1));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr2: mextr2 $rm, $rn, $rd

void
sh5_media_sem_mextr2 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 2);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 2));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr3: mextr3 $rm, $rn, $rd

void
sh5_media_sem_mextr3 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 3);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 3));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr4: mextr4 $rm, $rn, $rd

void
sh5_media_sem_mextr4 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 4);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 4));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr5: mextr5 $rm, $rn, $rd

void
sh5_media_sem_mextr5 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 5);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 5));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr6: mextr6 $rm, $rn, $rd

void
sh5_media_sem_mextr6 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 6);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 6));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mextr7: mextr7 $rm, $rn, $rd

void
sh5_media_sem_mextr7 (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_count;
  DI tmp_mask;
  DI tmp_rhs;
  tmp_count = MULQI (8, 7);
  tmp_mask = SLLDI (INVSI (0), tmp_count);
  tmp_rhs = SRLDI (ANDDI (current_cpu->h_gr_get (FLD (f_left)), tmp_mask), tmp_count);
  tmp_count = MULQI (8, SUBQI (8, 7));
  tmp_mask = SRLDI (INVSI (0), tmp_count);
  {
    DI opval = ORDI (tmp_rhs, SLLDI (ANDDI (current_cpu->h_gr_get (FLD (f_right)), tmp_mask), tmp_count));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmacfxwl: mmacfx.wl $rm, $rn, $rd

void
sh5_media_sem_mmacfxwl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_temp;
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_dest)), 1);
  tmp_result1 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_dest)), 0);
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)));
  tmp_temp = ((LTDI (SLLDI (tmp_temp, 1), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SLLDI (tmp_temp, 1), SLLDI (1, SUBSI (32, 1)))) ? (SLLDI (tmp_temp, 1)) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result0 = ((LTDI (ADDDI (EXTSIDI (tmp_result0), EXTSIDI (tmp_temp)), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (ADDDI (EXTSIDI (tmp_result0), EXTSIDI (tmp_temp)), SLLDI (1, SUBSI (32, 1)))) ? (ADDDI (EXTSIDI (tmp_result0), EXTSIDI (tmp_temp))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)));
  tmp_temp = ((LTDI (SLLDI (tmp_temp, 1), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SLLDI (tmp_temp, 1), SLLDI (1, SUBSI (32, 1)))) ? (SLLDI (tmp_temp, 1)) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result1 = ((LTDI (ADDDI (EXTSIDI (tmp_result1), EXTSIDI (tmp_temp)), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (ADDDI (EXTSIDI (tmp_result1), EXTSIDI (tmp_temp)), SLLDI (1, SUBSI (32, 1)))) ? (ADDDI (EXTSIDI (tmp_result1), EXTSIDI (tmp_temp))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmacnfx.wl: mmacnfx.wl $rm, $rn, $rd

void
sh5_media_sem_mmacnfx_wl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_temp;
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_dest)), 1);
  tmp_result1 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_dest)), 0);
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)));
  tmp_temp = ((LTDI (SLLDI (tmp_temp, 1), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SLLDI (tmp_temp, 1), SLLDI (1, SUBSI (32, 1)))) ? (SLLDI (tmp_temp, 1)) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result0 = ((LTDI (SUBDI (EXTSIDI (tmp_result0), EXTSIDI (tmp_temp)), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SUBDI (EXTSIDI (tmp_result0), EXTSIDI (tmp_temp)), SLLDI (1, SUBSI (32, 1)))) ? (SUBDI (EXTSIDI (tmp_result0), EXTSIDI (tmp_temp))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)));
  tmp_temp = ((LTDI (SLLDI (tmp_temp, 1), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SLLDI (tmp_temp, 1), SLLDI (1, SUBSI (32, 1)))) ? (SLLDI (tmp_temp, 1)) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result1 = ((LTDI (SUBDI (EXTSIDI (tmp_result1), EXTSIDI (tmp_temp)), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SUBDI (EXTSIDI (tmp_result1), EXTSIDI (tmp_temp)), SLLDI (1, SUBSI (32, 1)))) ? (SUBDI (EXTSIDI (tmp_result1), EXTSIDI (tmp_temp))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmull: mmul.l $rm, $rn, $rd

void
sh5_media_sem_mmull (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = MULSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1));
  tmp_result1 = MULSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmulw: mmul.w $rm, $rn, $rd

void
sh5_media_sem_mmulw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = MULHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3));
  tmp_result1 = MULHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2));
  tmp_result2 = MULHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1));
  tmp_result3 = MULHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmulfxl: mmulfx.l $rm, $rn, $rd

void
sh5_media_sem_mmulfxl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_temp;
  SI tmp_result0;
  SI tmp_result1;
  tmp_temp = MULDI (ZEXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)));
  tmp_result0 = ((LTDI (SRADI (tmp_temp, 31), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SRADI (tmp_temp, 31), SLLDI (1, SUBSI (32, 1)))) ? (SRADI (tmp_temp, 31)) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_temp = MULDI (ZEXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0)));
  tmp_result1 = ((LTDI (SRADI (tmp_temp, 31), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SRADI (tmp_temp, 31), SLLDI (1, SUBSI (32, 1)))) ? (SRADI (tmp_temp, 31)) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmulfxw: mmulfx.w $rm, $rn, $rd

void
sh5_media_sem_mmulfxw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_temp;
  HI tmp_result0;
  HI tmp_result1;
  HI tmp_result2;
  HI tmp_result3;
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)));
  tmp_result0 = ((LTSI (SRASI (tmp_temp, 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (tmp_temp, 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (tmp_temp, 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)));
  tmp_result1 = ((LTSI (SRASI (tmp_temp, 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (tmp_temp, 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (tmp_temp, 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1)));
  tmp_result2 = ((LTSI (SRASI (tmp_temp, 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (tmp_temp, 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (tmp_temp, 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)));
  tmp_result3 = ((LTSI (SRASI (tmp_temp, 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (tmp_temp, 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (tmp_temp, 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmulfxrpw: mmulfxrp.w $rm, $rn, $rd

void
sh5_media_sem_mmulfxrpw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_temp;
  HI tmp_result0;
  HI tmp_result1;
  HI tmp_result2;
  HI tmp_result3;
  HI tmp_c;
  tmp_c = SLLSI (1, 14);
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)));
  tmp_result0 = ((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (ADDSI (tmp_temp, tmp_c), 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)));
  tmp_result1 = ((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (ADDSI (tmp_temp, tmp_c), 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1)));
  tmp_result2 = ((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (ADDSI (tmp_temp, tmp_c), 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_temp = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)));
  tmp_result3 = ((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTSI (SRASI (ADDSI (tmp_temp, tmp_c), 15), SLLDI (1, SUBSI (16, 1)))) ? (SRASI (ADDSI (tmp_temp, tmp_c), 15)) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmulhiwl: mmulhi.wl $rm, $rn, $rd

void
sh5_media_sem_mmulhiwl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1)));
  tmp_result1 = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmullowl: mmullo.wl $rm, $rn, $rd

void
sh5_media_sem_mmullowl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3)));
  tmp_result1 = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2)));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mmulsumwq: mmulsum.wq $rm, $rn, $rd

void
sh5_media_sem_mmulsumwq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_acc;
  tmp_acc = MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0)));
  tmp_acc = ADDDI (tmp_acc, MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1))));
  tmp_acc = ADDDI (tmp_acc, MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2))));
  tmp_acc = ADDDI (tmp_acc, MULSI (ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTHISI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3))));
  {
    DI opval = ADDDI (current_cpu->h_gr_get (FLD (f_dest)), tmp_acc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movi: movi $imm16, $rd

void
sh5_media_sem_movi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movi.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (FLD (f_imm16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mpermw: mperm.w $rm, $rn, $rd

void
sh5_media_sem_mpermw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_control;
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_control = ANDQI (current_cpu->h_gr_get (FLD (f_right)), 255);
  tmp_result0 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), SUBSI (3, ANDQI (tmp_control, 3)));
  tmp_result1 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), SUBSI (3, ANDQI (SRLQI (tmp_control, 2), 3)));
  tmp_result2 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), SUBSI (3, ANDQI (SRLQI (tmp_control, 4), 3)));
  tmp_result3 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), SUBSI (3, ANDQI (SRLQI (tmp_control, 6), 3)));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** msadubq: msad.ubq $rm, $rn, $rd

void
sh5_media_sem_msadubq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_acc;
  tmp_acc = ABSDI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0)));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))));
  tmp_acc = ADDDI (tmp_acc, ABSQI (SUBQI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7), SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))));
  {
    DI opval = ADDDI (current_cpu->h_gr_get (FLD (f_dest)), tmp_acc);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshaldsl: mshalds.l $rm, $rn, $rd

void
sh5_media_sem_mshaldsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ((LTDI (SLLDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31)), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SLLDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31)), SLLDI (1, SUBSI (32, 1)))) ? (SLLDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result1 = ((LTDI (SLLDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31)), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SLLDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31)), SLLDI (1, SUBSI (32, 1)))) ? (SLLDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshaldsw: mshalds.w $rm, $rn, $rd

void
sh5_media_sem_mshaldsw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = ((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), SLLDI (1, SUBSI (16, 1)))) ? (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result1 = ((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), SLLDI (1, SUBSI (16, 1)))) ? (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result2 = ((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), SLLDI (1, SUBSI (16, 1)))) ? (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result3 = ((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15)), SLLDI (1, SUBSI (16, 1)))) ? (SLLDI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshardl: mshard.l $rm, $rn, $rd

void
sh5_media_sem_mshardl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SRASI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31));
  tmp_result1 = SRASI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshardw: mshard.w $rm, $rn, $rd

void
sh5_media_sem_mshardw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = SRAHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result1 = SRAHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result2 = SRAHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result3 = SRAHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshardsq: mshards.q $rm, $rn, $rd

void
sh5_media_sem_mshardsq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ((LTDI (SRADI (current_cpu->h_gr_get (FLD (f_left)), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63)), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGDI (SLLDI (1, SUBSI (16, 1)))) : (((LTDI (SRADI (current_cpu->h_gr_get (FLD (f_left)), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63)), SLLDI (1, SUBSI (16, 1)))) ? (SRADI (current_cpu->h_gr_get (FLD (f_left)), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63))) : (SUBDI (SLLDI (1, SUBSI (16, 1)), 1)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshfhib: mshfhi.b $rm, $rn, $rd

void
sh5_media_sem_mshfhib (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3);
  tmp_result1 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3);
  tmp_result2 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2);
  tmp_result3 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2);
  tmp_result4 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1);
  tmp_result5 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1);
  tmp_result6 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0);
  tmp_result7 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0);
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshfhil: mshfhi.l $rm, $rn, $rd

void
sh5_media_sem_mshfhil (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0);
  tmp_result1 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0);
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshfhiw: mshfhi.w $rm, $rn, $rd

void
sh5_media_sem_mshfhiw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1);
  tmp_result1 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1);
  tmp_result2 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0);
  tmp_result3 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0);
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshflob: mshflo.b $rm, $rn, $rd

void
sh5_media_sem_mshflob (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7);
  tmp_result1 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7);
  tmp_result2 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6);
  tmp_result3 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6);
  tmp_result4 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5);
  tmp_result5 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5);
  tmp_result6 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4);
  tmp_result7 = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4);
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshflol: mshflo.l $rm, $rn, $rd

void
sh5_media_sem_mshflol (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1);
  tmp_result1 = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1);
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshflow: mshflo.w $rm, $rn, $rd

void
sh5_media_sem_mshflow (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3);
  tmp_result1 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3);
  tmp_result2 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2);
  tmp_result3 = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2);
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshlldl: mshlld.l $rm, $rn, $rd

void
sh5_media_sem_mshlldl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SLLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31));
  tmp_result1 = SLLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshlldw: mshlld.w $rm, $rn, $rd

void
sh5_media_sem_mshlldw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = SLLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result1 = SLLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result2 = SLLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result3 = SLLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshlrdl: mshlrd.l $rm, $rn, $rd

void
sh5_media_sem_mshlrdl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SRLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31));
  tmp_result1 = SRLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 31));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mshlrdw: mshlrd.w $rm, $rn, $rd

void
sh5_media_sem_mshlrdw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = SRLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result1 = SRLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result2 = SRLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  tmp_result3 = SRLHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 15));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** msubl: msub.l $rm, $rn, $rd

void
sh5_media_sem_msubl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = SUBSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1));
  tmp_result1 = SUBSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** msubw: msub.w $rm, $rn, $rd

void
sh5_media_sem_msubw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  HI tmp_result3;
  HI tmp_result2;
  HI tmp_result1;
  HI tmp_result0;
  tmp_result0 = SUBHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 3), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 3));
  tmp_result1 = SUBHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 2), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 2));
  tmp_result2 = SUBHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 1));
  tmp_result3 = SUBHI (SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_left)), 0), SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_right)), 0));
  {
    DI opval = ORDI (SLLDI (ZEXTHIDI (tmp_result3), 48), ORDI (SLLDI (ZEXTHIDI (tmp_result2), 32), ORDI (SLLDI (ZEXTHIDI (tmp_result1), 16), ZEXTHIDI (tmp_result0))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** msubsl: msubs.l $rm, $rn, $rd

void
sh5_media_sem_msubsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_result1;
  SI tmp_result0;
  tmp_result0 = ((LTDI (SUBDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1))), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SUBDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1))), SLLDI (1, SUBSI (32, 1)))) ? (SUBDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  tmp_result1 = ((LTDI (SUBDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0))), NEGDI (SLLDI (1, SUBSI (32, 1))))) ? (NEGSI (SLLSI (1, SUBSI (32, 1)))) : (((LTDI (SUBDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0))), SLLDI (1, SUBSI (32, 1)))) ? (SUBDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 0)))) : (SUBSI (SLLSI (1, SUBSI (32, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTSIDI (tmp_result1), 32), ZEXTSIDI (tmp_result0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** msubsub: msubs.ub $rm, $rn, $rd

void
sh5_media_sem_msubsub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result1 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result2 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result3 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result4 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result5 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result6 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1)))) : (SUBQI (SLLQI (1, 8), 1)))));
  tmp_result7 = ((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))), MAKEDI (0, 0))) ? (0) : (((LTDI (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))), SLLDI (1, 8))) ? (SUBDI (ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), ZEXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0)))) : (SUBQI (SLLQI (1, 8), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** msubsw: msubs.w $rm, $rn, $rd

void
sh5_media_sem_msubsw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  QI tmp_result7;
  QI tmp_result6;
  QI tmp_result5;
  QI tmp_result4;
  QI tmp_result3;
  QI tmp_result2;
  QI tmp_result1;
  QI tmp_result0;
  tmp_result0 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 7)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 7)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result1 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 6)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 6)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result2 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 5)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 5)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result3 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 4)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 4)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result4 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 3)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 3)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result5 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 2)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 2)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result6 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 1)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  tmp_result7 = ((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))), NEGDI (SLLDI (1, SUBSI (16, 1))))) ? (NEGHI (SLLHI (1, SUBSI (16, 1)))) : (((LTDI (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0))), SLLDI (1, SUBSI (16, 1)))) ? (SUBDI (EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_left)), 0)), EXTQIDI (SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_right)), 0)))) : (SUBHI (SLLHI (1, SUBSI (16, 1)), 1)))));
  {
    DI opval = ORDI (SLLDI (ZEXTQIDI (tmp_result7), 56), ORDI (SLLDI (ZEXTQIDI (tmp_result6), 48), ORDI (SLLDI (ZEXTQIDI (tmp_result5), 40), ORDI (SLLDI (ZEXTQIDI (tmp_result4), 32), ORDI (SLLDI (ZEXTQIDI (tmp_result3), 24), ORDI (SLLDI (ZEXTQIDI (tmp_result2), 16), ORDI (SLLDI (ZEXTQIDI (tmp_result1), 8), ZEXTQIDI (tmp_result0))))))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mulsl: muls.l $rm, $rn, $rd

void
sh5_media_sem_mulsl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = MULDI (EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), EXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mulul: mulu.l $rm, $rn, $rd

void
sh5_media_sem_mulul (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = MULDI (ZEXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1)), ZEXTSIDI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nop: nop

void
sh5_media_sem_nop (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nsb: nsb $rm, $rd

void
sh5_media_sem_nsb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->sh64_nsb (current_cpu->h_gr_get (FLD (f_left)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ocbi: ocbi $rm, $disp6x32

void
sh5_media_sem_ocbi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_left), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ocbp: ocbp $rm, $disp6x32

void
sh5_media_sem_ocbp (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_left), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ocbwb: ocbwb $rm, $disp6x32

void
sh5_media_sem_ocbwb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_left), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** or: or $rm, $rn, $rd

void
sh5_media_sem_or (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ori: ori $rm, $imm10, $rd

void
sh5_media_sem_ori (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_ori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_imm10)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** prefi: prefi $rm, $disp6x32

void
sh5_media_sem_prefi (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_left) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_left), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** pta: pta$likely $disp16, $tra

void
sh5_media_sem_pta (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_prediction (FLD (f_tra), FLD (f_likely));
  {
    DI opval = ADDSI (FLD (f_disp16), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tr" << '[' << FLD (f_tra) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_tr[FLD (f_tra)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ptabs: ptabs$likely $rn, $tra

void
sh5_media_sem_ptabs (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_prediction (FLD (f_tra), FLD (f_likely));
  {
    DI opval = current_cpu->h_gr_get (FLD (f_right));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tr" << '[' << FLD (f_tra) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_tr[FLD (f_tra)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ptb: ptb$likely $disp16, $tra

void
sh5_media_sem_ptb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_pta.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_prediction (FLD (f_tra), FLD (f_likely));
  {
    DI opval = FLD (f_disp16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tr" << '[' << FLD (f_tra) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_tr[FLD (f_tra)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ptrel: ptrel$likely $rn, $tra

void
sh5_media_sem_ptrel (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_ptabs.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
current_cpu->save_branch_prediction (FLD (f_tra), FLD (f_likely));
  {
    DI opval = ADDDI (pc, current_cpu->h_gr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tr" << '[' << FLD (f_tra) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_tr[FLD (f_tra)] = opval;
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** putcfg: putcfg $rm, $disp6, $rd

void
sh5_media_sem_putcfg (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  SI tmp_address;
  tmp_address = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
current_cpu->sh64_save_cfg_address (tmp_address);
  {
    SI opval = current_cpu->h_gr_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_address << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_address, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** putcon: putcon $rm, $crj

void
sh5_media_sem_putcon (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->h_gr_get (FLD (f_left));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "cr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_cr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rte: rte

void
sh5_media_sem_rte (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shard: shard $rm, $rn, $rd

void
sh5_media_sem_shard (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SRADI (current_cpu->h_gr_get (FLD (f_left)), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shardl: shard.l $rm, $rn, $rd

void
sh5_media_sem_shardl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SRASI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shari: shari $rm, $uimm6, $rd

void
sh5_media_sem_shari (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SRADI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_uimm6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sharil: shari.l $rm, $uimm6, $rd

void
sh5_media_sem_sharil (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SRASI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDSI (FLD (f_uimm6), 63)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlld: shlld $rm, $rn, $rd

void
sh5_media_sem_shlld (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SLLDI (current_cpu->h_gr_get (FLD (f_left)), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlldl: shlld.l $rm, $rn, $rd

void
sh5_media_sem_shlldl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SLLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlli: shlli $rm, $uimm6, $rd

void
sh5_media_sem_shlli (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SLLDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_uimm6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shllil: shlli.l $rm, $uimm6, $rd

void
sh5_media_sem_shllil (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SLLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDSI (FLD (f_uimm6), 63)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlrd: shlrd $rm, $rn, $rd

void
sh5_media_sem_shlrd (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SRLDI (current_cpu->h_gr_get (FLD (f_left)), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlrdl: shlrd.l $rm, $rn, $rd

void
sh5_media_sem_shlrdl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SRLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDDI (current_cpu->h_gr_get (FLD (f_right)), 63)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlri: shlri $rm, $uimm6, $rd

void
sh5_media_sem_shlri (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SRLDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_uimm6));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlril: shlri.l $rm, $uimm6, $rd

void
sh5_media_sem_shlril (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shari.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SRLSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), ANDSI (FLD (f_uimm6), 63)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shori: shori $uimm16, $rd

void
sh5_media_sem_shori (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_shori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = ORDI (SLLDI (current_cpu->h_gr_get (FLD (f_dest)), 16), ZEXTSIDI (FLD (f_uimm16)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sleep: sleep

void
sh5_media_sem_sleep (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stb: st.b $rm, $disp10, $rd

void
sh5_media_sem_stb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_stb.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    UQI opval = ANDQI (current_cpu->h_gr_get (FLD (f_dest)), 255);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10))) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stl: st.l $rm, $disp10x4, $rd

void
sh5_media_sem_stl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_stl.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = ANDSI (current_cpu->h_gr_get (FLD (f_dest)), 0xffffffff);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x4))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x4))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stq: st.q $rm, $disp10x8, $rd

void
sh5_media_sem_stq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_stq.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->h_gr_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x8))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMDI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x8))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stw: st.w $rm, $disp10x2, $rd

void
sh5_media_sem_stw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_stw.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    HI opval = ANDHI (current_cpu->h_gr_get (FLD (f_dest)), 65535);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x2))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_disp10x2))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sthil: sthi.l $rm, $disp6, $rd

void
sh5_media_sem_sthil (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  DI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = ADDDI (ANDDI (tmp_addr, 3), 1);
if (ANDQI (tmp_bytecount, 4)) {
  {
    SI opval = current_cpu->h_gr_get (FLD (f_dest));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDDI (tmp_addr, -4), opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
  tmp_val = current_cpu->h_gr_get (FLD (f_dest));
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    HI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDDI (tmp_addr, -4), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
}
} else {
{
  tmp_val = SRLDI (current_cpu->h_gr_get (FLD (f_dest)), SUBSI (32, MULSI (8, tmp_bytecount)));
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    HI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDDI (tmp_addr, -4), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sthiq: sthi.q $rm, $disp6, $rd

void
sh5_media_sem_sthiq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  DI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = ADDDI (ANDDI (tmp_addr, 7), 1);
if (ANDQI (tmp_bytecount, 8)) {
  {
    DI opval = current_cpu->h_gr_get (FLD (f_dest));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -8) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMDI (pc, ANDDI (tmp_addr, -8), opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
  tmp_val = current_cpu->h_gr_get (FLD (f_dest));
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    HI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDDI (tmp_addr, -4), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
if (ANDQI (tmp_bytecount, 4)) {
{
  {
    SI opval = ANDSI (tmp_val, 0xffffffff);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -8) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDDI (tmp_addr, -8), opval);
  }
  tmp_val = SRLDI (tmp_val, 32);
}
}
}
} else {
{
  tmp_val = SRLDI (current_cpu->h_gr_get (FLD (f_dest)), SUBSI (64, MULSI (8, tmp_bytecount)));
if (ANDQI (tmp_bytecount, 4)) {
{
  {
    SI opval = ANDSI (tmp_val, 0xffffffff);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -8) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ANDDI (tmp_addr, -8), opval);
  }
  tmp_val = SRLDI (tmp_val, 32);
}
}
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    HI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (tmp_addr, -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ANDDI (tmp_addr, -4), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stlol: stlo.l $rm, $disp6, $rd

void
sh5_media_sem_stlol (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  DI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = SUBSI (4, ANDDI (tmp_addr, 3));
if (ANDQI (tmp_bytecount, 4)) {
  {
    USI opval = current_cpu->h_gr_get (FLD (f_dest));
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUSI (pc, tmp_addr, opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
  tmp_val = SRLDI (current_cpu->h_gr_get (FLD (f_dest)), SUBSI (32, MULSI (8, tmp_bytecount)));
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    UHI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (ADDDI (tmp_addr, 1), -2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
}
} else {
{
  tmp_val = current_cpu->h_gr_get (FLD (f_dest));
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    UHI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (ADDDI (tmp_addr, 1), -2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stloq: stlo.q $rm, $disp6, $rd

void
sh5_media_sem_stloq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_putcfg.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  QI tmp_bytecount;
  DI tmp_val;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), FLD (f_disp6));
  tmp_bytecount = SUBSI (8, ANDDI (tmp_addr, 7));
if (ANDQI (tmp_bytecount, 8)) {
  {
    UDI opval = current_cpu->h_gr_get (FLD (f_dest));
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUDI (pc, tmp_addr, opval);
  }
} else {
if (current_cpu->h_endian_get ()) {
{
  tmp_val = SRLDI (current_cpu->h_gr_get (FLD (f_dest)), SUBSI (64, MULSI (8, tmp_bytecount)));
if (ANDQI (tmp_bytecount, 4)) {
{
  {
    USI opval = ANDSI (tmp_val, 0xffffffff);
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (ADDDI (tmp_addr, 3), -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUSI (pc, ANDDI (ADDDI (tmp_addr, 3), -4), opval);
  }
  tmp_val = SRLDI (tmp_val, 32);
}
}
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    UHI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (ADDDI (tmp_addr, 1), -2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
}
} else {
{
  tmp_val = current_cpu->h_gr_get (FLD (f_dest));
if (ANDQI (tmp_bytecount, 1)) {
{
  {
    UQI opval = ANDQI (tmp_val, 255);
    written |= (1ULL << 6);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  tmp_val = SRLDI (tmp_val, 8);
}
}
if (ANDQI (tmp_bytecount, 2)) {
{
  {
    UHI opval = ANDHI (tmp_val, 65535);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (ADDDI (tmp_addr, 1), -2) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUHI (pc, ANDDI (ADDDI (tmp_addr, 1), -2), opval);
  }
  tmp_val = SRLDI (tmp_val, 16);
}
}
if (ANDQI (tmp_bytecount, 4)) {
{
  {
    USI opval = ANDSI (tmp_val, 0xffffffff);
    written |= (1ULL << 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ANDDI (ADDDI (tmp_addr, 3), -4) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMUSI (pc, ANDDI (ADDDI (tmp_addr, 3), -4), opval);
  }
  tmp_val = SRLDI (tmp_val, 32);
}
}
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stxb: stx.b $rm, $rn, $rd

void
sh5_media_sem_stxb (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    UQI opval = SUBWORDDIQI (current_cpu->h_gr_get (FLD (f_dest)), 7);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stxl: stx.l $rm, $rn, $rd

void
sh5_media_sem_stxl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = SUBWORDDISI (current_cpu->h_gr_get (FLD (f_dest)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stxq: stx.q $rm, $rn, $rd

void
sh5_media_sem_stxq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = current_cpu->h_gr_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMDI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stxw: stx.w $rm, $rn, $rd

void
sh5_media_sem_stxw (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    HI opval = SUBWORDDIHI (current_cpu->h_gr_get (FLD (f_dest)), 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sub: sub $rm, $rn, $rd

void
sh5_media_sem_sub (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = SUBDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** subl: sub.l $rm, $rn, $rd

void
sh5_media_sem_subl (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = EXTSIDI (SUBSI (SUBWORDDISI (current_cpu->h_gr_get (FLD (f_left)), 1), SUBWORDDISI (current_cpu->h_gr_get (FLD (f_right)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** swapq: swap.q $rm, $rn, $rd

void
sh5_media_sem_swapq (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

{
  DI tmp_addr;
  DI tmp_temp;
  tmp_addr = ADDDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)));
  tmp_temp = current_cpu->GETMEMDI (pc, tmp_addr);
  {
    DI opval = current_cpu->h_gr_get (FLD (f_dest));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMDI (pc, tmp_addr, opval);
  }
  {
    DI opval = tmp_temp;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** synci: synci

void
sh5_media_sem_synci (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** synco: synco

void
sh5_media_sem_synco (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** trapa: trapa $rm

void
sh5_media_sem_trapa (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_alloco.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

current_cpu->sh64_trapa (current_cpu->h_gr_get (FLD (f_left)), pc);

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xor: xor $rm, $rn, $rd

void
sh5_media_sem_xor (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_mcmv.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = XORDI (current_cpu->h_gr_get (FLD (f_left)), current_cpu->h_gr_get (FLD (f_right)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xori: xori $rm, $imm6, $rd

void
sh5_media_sem_xori (sh5_cpu* current_cpu, sh5_media_scache* sem, const int tick, 
	sh5_media::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_xori.f
  sem_status status = SEM_STATUS_NORMAL;
  sh5_media_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    DI opval = XORDI (current_cpu->h_gr_get (FLD (f_left)), EXTSIDI (FLD (f_imm6)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_dest) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_dest), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

