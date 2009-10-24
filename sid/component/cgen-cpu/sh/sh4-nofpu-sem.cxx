/* Simulator instruction semantics for sh4_nofpu.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh4_nofpu.h"

using namespace sh4_nofpu; // FIXME: namespace organization still wip
using namespace sh4_nofpu; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

void
sh4_nofpu_sem_x_invalid (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
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

// ********** add-compact: add $rm, $rn

void
sh4_nofpu_sem_add_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addi-compact: add #$imm8, $rn

void
sh4_nofpu_sem_addi_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), EXTQISI (ANDQI (FLD (f_imm8), 255)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addc-compact: addc $rm, $rn

void
sh4_nofpu_sem_addc_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_flag;
  tmp_flag = ADDCFSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_tbit_get ());
  {
    SI opval = ADDCSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_tbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = tmp_flag;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** addv-compact: addv $rm, $rn

void
sh4_nofpu_sem_addv_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  tmp_t = ADDOFSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)), 0);
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = tmp_t;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** and-compact: and $rm64, $rn64

void
sh4_nofpu_sem_and_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = ANDDI (current_cpu->h_gr_get (FLD (f_rm)), current_cpu->h_gr_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** andi-compact: and #$uimm8, r0

void
sh4_nofpu_sem_andi_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ANDSI (current_cpu->h_grc_get (((UINT) 0)), ZEXTSIDI (FLD (f_imm8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** andb-compact: and.b #$imm8, @(r0, gbr)

void
sh4_nofpu_sem_andb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  UQI tmp_data;
  tmp_addr = ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_gbr_get ());
  tmp_data = ANDQI (current_cpu->GETMEMUQI (pc, tmp_addr), FLD (f_imm8));
  {
    UQI opval = tmp_data;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** bf-compact: bf $disp8

void
sh4_nofpu_sem_bf_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->h_tbit_get ())) {
  {
    UDI opval = FLD (i_disp8);
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bfs-compact: bf/s $disp8

void
sh4_nofpu_sem_bfs_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (NOTBI (current_cpu->h_tbit_get ())) {
{
  {
    UDI opval = ADDDI (pc, 2);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (FLD (i_disp8));
  {
    UDI opval = FLD (i_disp8);
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bra-compact: bra $disp12

void
sh4_nofpu_sem_bra_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (FLD (i_disp12));
  {
    UDI opval = FLD (i_disp12);
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** braf-compact: braf $rn

void
sh4_nofpu_sem_braf_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (ADDDI (EXTSIDI (current_cpu->h_grc_get (FLD (f_rn))), ADDDI (pc, 4)));
  {
    UDI opval = ADDDI (EXTSIDI (current_cpu->h_grc_get (FLD (f_rn))), ADDDI (pc, 4));
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bsr-compact: bsr $disp12

void
sh4_nofpu_sem_bsr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_bra_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDDI (pc, 4);
    buf.h_pr_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<SI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pr" << ":=0x" << hex << opval << dec << "  ";
  }
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (FLD (i_disp12));
  {
    UDI opval = FLD (i_disp12);
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bsrf-compact: bsrf $rn

void
sh4_nofpu_sem_bsrf_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDDI (pc, 4);
    buf.h_pr_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<SI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pr" << ":=0x" << hex << opval << dec << "  ";
  }
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (ADDDI (EXTSIDI (current_cpu->h_grc_get (FLD (f_rn))), ADDDI (pc, 4)));
  {
    UDI opval = ADDDI (EXTSIDI (current_cpu->h_grc_get (FLD (f_rn))), ADDDI (pc, 4));
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bt-compact: bt $disp8

void
sh4_nofpu_sem_bt_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->h_tbit_get ()) {
  {
    UDI opval = FLD (i_disp8);
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** bts-compact: bt/s $disp8

void
sh4_nofpu_sem_bts_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_bf_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

if (current_cpu->h_tbit_get ()) {
{
  {
    UDI opval = ADDDI (pc, 2);
    written |= (1ULL << 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (FLD (i_disp8));
  {
    UDI opval = FLD (i_disp8);
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
}
}

  abuf->written = written;
  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** clrmac-compact: clrmac

void
sh4_nofpu_sem_clrmac_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
  {
    SI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** clrs-compact: clrs

void
sh4_nofpu_sem_clrs_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_sbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** clrt-compact: clrt

void
sh4_nofpu_sem_clrt_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpeq-compact: cmp/eq $rm, $rn

void
sh4_nofpu_sem_cmpeq_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = EQSI (current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpeqi-compact: cmp/eq #$imm8, r0

void
sh4_nofpu_sem_cmpeqi_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = EQSI (current_cpu->h_grc_get (((UINT) 0)), EXTQISI (ANDQI (FLD (f_imm8), 255)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpge-compact: cmp/ge $rm, $rn

void
sh4_nofpu_sem_cmpge_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = GESI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpgt-compact: cmp/gt $rm, $rn

void
sh4_nofpu_sem_cmpgt_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = GTSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmphi-compact: cmp/hi $rm, $rn

void
sh4_nofpu_sem_cmphi_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = GTUSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmphs-compact: cmp/hs $rm, $rn

void
sh4_nofpu_sem_cmphs_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = GEUSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmppl-compact: cmp/pl $rn

void
sh4_nofpu_sem_cmppl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = GTSI (current_cpu->h_grc_get (FLD (f_rn)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmppz-compact: cmp/pz $rn

void
sh4_nofpu_sem_cmppz_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = GESI (current_cpu->h_grc_get (FLD (f_rn)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** cmpstr-compact: cmp/str $rm, $rn

void
sh4_nofpu_sem_cmpstr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  SI tmp_temp;
  tmp_temp = XORSI (current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_grc_get (FLD (f_rn)));
  tmp_t = EQSI (ANDSI (tmp_temp, 0xff000000), 0);
  tmp_t = ORBI (EQSI (ANDSI (tmp_temp, 16711680), 0), tmp_t);
  tmp_t = ORBI (EQSI (ANDSI (tmp_temp, 65280), 0), tmp_t);
  tmp_t = ORBI (EQSI (ANDSI (tmp_temp, 255), 0), tmp_t);
  {
    BI opval = ((GTUBI (tmp_t, 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** div0s-compact: div0s $rm, $rn

void
sh4_nofpu_sem_div0s_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    BI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
  {
    BI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rm)), 31);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mbit_set (opval);
  }
  {
    BI opval = ((EQSI (SRLSI (current_cpu->h_grc_get (FLD (f_rm)), 31), SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31))) ? (0) : (1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** div0u-compact: div0u

void
sh4_nofpu_sem_div0u_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    BI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
  {
    BI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
  {
    BI opval = 0;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** div1-compact: div1 $rm, $rn

void
sh4_nofpu_sem_div1_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_oldq;
  SI tmp_tmp0;
  UQI tmp_tmp1;
  tmp_oldq = current_cpu->h_qbit_get ();
  {
    BI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
  {
    SI opval = ORSI (SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 1), ZEXTBISI (current_cpu->h_tbit_get ()));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
if (NOTBI (tmp_oldq)) {
if (NOTBI (current_cpu->h_mbit_get ())) {
{
  tmp_tmp0 = current_cpu->h_grc_get (FLD (f_rn));
  {
    SI opval = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  tmp_tmp1 = GTUSI (current_cpu->h_grc_get (FLD (f_rn)), tmp_tmp0);
if (NOTBI (current_cpu->h_qbit_get ())) {
  {
    BI opval = ((tmp_tmp1) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
} else {
  {
    BI opval = ((EQQI (tmp_tmp1, 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
}
}
} else {
{
  tmp_tmp0 = current_cpu->h_grc_get (FLD (f_rn));
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  tmp_tmp1 = LTUSI (current_cpu->h_grc_get (FLD (f_rn)), tmp_tmp0);
if (NOTBI (current_cpu->h_qbit_get ())) {
  {
    BI opval = ((EQQI (tmp_tmp1, 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
} else {
  {
    BI opval = ((tmp_tmp1) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
}
}
}
} else {
if (NOTBI (current_cpu->h_mbit_get ())) {
{
  tmp_tmp0 = current_cpu->h_grc_get (FLD (f_rn));
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  tmp_tmp1 = LTUSI (current_cpu->h_grc_get (FLD (f_rn)), tmp_tmp0);
if (NOTBI (current_cpu->h_qbit_get ())) {
  {
    BI opval = ((tmp_tmp1) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
} else {
  {
    BI opval = ((EQQI (tmp_tmp1, 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
}
}
} else {
{
  tmp_tmp0 = current_cpu->h_grc_get (FLD (f_rn));
  {
    SI opval = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  tmp_tmp1 = GTUSI (current_cpu->h_grc_get (FLD (f_rn)), tmp_tmp0);
if (NOTBI (current_cpu->h_qbit_get ())) {
  {
    BI opval = ((EQQI (tmp_tmp1, 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
} else {
  {
    BI opval = ((tmp_tmp1) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "qbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_qbit_set (opval);
  }
}
}
}
}
  {
    BI opval = ((EQBI (current_cpu->h_qbit_get (), current_cpu->h_mbit_get ())) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** divu-compact: divu r0, $rn

void
sh4_nofpu_sem_divu_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = UDIVSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (((UINT) 0)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mulr-compact: mulr r0, $rn

void
sh4_nofpu_sem_mulr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = MULSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (((UINT) 0)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** dmulsl-compact: dmuls.l $rm, $rn

void
sh4_nofpu_sem_dmulsl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (current_cpu->h_grc_get (FLD (f_rm))), EXTSIDI (current_cpu->h_grc_get (FLD (f_rn))));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** dmulul-compact: dmulu.l $rm, $rn

void
sh4_nofpu_sem_dmulul_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI (current_cpu->h_grc_get (FLD (f_rm))), ZEXTSIDI (current_cpu->h_grc_get (FLD (f_rn))));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** dt-compact: dt $rn

void
sh4_nofpu_sem_dt_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = EQSI (current_cpu->h_grc_get (FLD (f_rn)), 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** extsb-compact: exts.b $rm, $rn

void
sh4_nofpu_sem_extsb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (SUBWORDSIQI (current_cpu->h_grc_get (FLD (f_rm)), 3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** extsw-compact: exts.w $rm, $rn

void
sh4_nofpu_sem_extsw_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** extub-compact: extu.b $rm, $rn

void
sh4_nofpu_sem_extub_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTQISI (SUBWORDSIQI (current_cpu->h_grc_get (FLD (f_rm)), 3));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** extuw-compact: extu.w $rm, $rn

void
sh4_nofpu_sem_extuw_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTHISI (SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** frchg-compact: frchg

void
sh4_nofpu_sem_frchg_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = NOTBI (current_cpu->h_frbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "frbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_frbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** fschg-compact: fschg

void
sh4_nofpu_sem_fschg_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = NOTBI (current_cpu->h_szbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "szbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_szbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** jmp-compact: jmp @$rn

void
sh4_nofpu_sem_jmp_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (current_cpu->h_grc_get (FLD (f_rn)));
  {
    UDI opval = current_cpu->h_grc_get (FLD (f_rn));
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
current_cpu->cg_profile (pc, current_cpu->h_grc_get (FLD (f_rn)));
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** jsr-compact: jsr @$rn

void
sh4_nofpu_sem_jsr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = ADDDI (pc, 4);
    buf.h_pr_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<SI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pr" << ":=0x" << hex << opval << dec << "  ";
  }
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (current_cpu->h_grc_get (FLD (f_rn)));
  {
    UDI opval = current_cpu->h_grc_get (FLD (f_rn));
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
current_cpu->cg_profile (pc, current_cpu->h_grc_get (FLD (f_rn)));
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** ldc-gbr-compact: ldc $rn, gbr

void
sh4_nofpu_sem_ldc_gbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gbr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gbr_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldc-vbr-compact: ldc $rn, vbr

void
sh4_nofpu_sem_ldc_vbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_vbr_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldc-sr-compact: ldc $rn, sr

void
sh4_nofpu_sem_ldc_sr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->hardware.h_sr = opval;
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldcl-gbr-compact: ldc.l @${rn}+, gbr

void
sh4_nofpu_sem_ldcl_gbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gbr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gbr_set (opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldcl-vbr-compact: ldc.l @${rn}+, vbr

void
sh4_nofpu_sem_ldcl_vbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "vbr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_vbr_set (opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lds-mach-compact: lds $rn, mach

void
sh4_nofpu_sem_lds_mach_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldsl-mach-compact: lds.l @${rn}+, mach

void
sh4_nofpu_sem_ldsl_mach_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lds-macl-compact: lds $rn, macl

void
sh4_nofpu_sem_lds_macl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldsl-macl-compact: lds.l @${rn}+, macl

void
sh4_nofpu_sem_ldsl_macl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** lds-pr-compact: lds $rn, pr

void
sh4_nofpu_sem_lds_pr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_pr_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ldsl-pr-compact: lds.l @${rn}+, pr

void
sh4_nofpu_sem_ldsl_pr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pr" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_pr_set (opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** macl-compact: mac.l @${rm}+, @${rn}+

void
sh4_nofpu_sem_macl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_tmpry;
  DI tmp_mac;
  DI tmp_result;
  SI tmp_x;
  SI tmp_y;
  tmp_x = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)));
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
if (EQSI (FLD (f_rn), FLD (f_rm))) {
{
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 4);
    written |= (1ULL << 11);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
}
}
  tmp_y = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rm)));
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 4);
    written |= (1ULL << 11);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
  tmp_tmpry = MULDI (ZEXTSIDI (tmp_x), ZEXTSIDI (tmp_y));
  tmp_mac = ORDI (SLLDI (ZEXTSIDI (current_cpu->h_mach_get ()), 32), ZEXTSIDI (current_cpu->h_macl_get ()));
  tmp_result = ADDDI (tmp_mac, tmp_tmpry);
{
if (current_cpu->h_sbit_get ()) {
{
  SI tmp_min;
  SI tmp_max;
  tmp_max = SRLDI (INVDI (0), 16);
  tmp_min = SRLDI (INVDI (0), 15);
if (GTDI (tmp_result, tmp_max)) {
  tmp_result = tmp_max;
} else {
if (LTDI (tmp_result, tmp_min)) {
  tmp_result = tmp_min;
}
}
}
}
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** macw-compact: mac.w @${rm}+, @${rn}+

void
sh4_nofpu_sem_macw_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_tmpry;
  DI tmp_mac;
  DI tmp_result;
  HI tmp_x;
  HI tmp_y;
  tmp_x = current_cpu->GETMEMHI (pc, current_cpu->h_grc_get (FLD (f_rn)));
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
if (EQSI (FLD (f_rn), FLD (f_rm))) {
{
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rn)), 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 2);
    written |= (1ULL << 11);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
}
}
  tmp_y = current_cpu->GETMEMHI (pc, current_cpu->h_grc_get (FLD (f_rm)));
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 2);
    written |= (1ULL << 11);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
  tmp_tmpry = MULSI (ZEXTHISI (tmp_x), ZEXTHISI (tmp_y));
if (current_cpu->h_sbit_get ()) {
{
if (ADDOFSI (tmp_tmpry, current_cpu->h_macl_get (), 0)) {
  {
    SI opval = 1;
    written |= (1ULL << 9);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
}
  {
    SI opval = ADDSI (tmp_tmpry, current_cpu->h_macl_get ());
    written |= (1ULL << 10);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
}
} else {
{
  tmp_mac = ORDI (SLLDI (ZEXTSIDI (current_cpu->h_mach_get ()), 32), ZEXTSIDI (current_cpu->h_macl_get ()));
  tmp_result = ADDDI (tmp_mac, EXTSIDI (tmp_tmpry));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    written |= (1ULL << 9);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "mach" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_mach_set (opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    written |= (1ULL << 10);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mov-compact: mov $rm64, $rn64

void
sh4_nofpu_sem_mov_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = current_cpu->h_gr_get (FLD (f_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movi-compact: mov #$imm8, $rn

void
sh4_nofpu_sem_movi_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_addi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQIDI (ANDQI (FLD (f_imm8), 255));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movi20-compact: movi20 #$imm20, $rn

void
sh4_nofpu_sem_movi20_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movi20_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = FLD (f_imm20);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb1-compact: mov.b $rm, @$rn

void
sh4_nofpu_sem_movb1_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    UQI opval = SUBWORDSIUQI (current_cpu->h_grc_get (FLD (f_rm)), 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_grc_get (FLD (f_rn)) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, current_cpu->h_grc_get (FLD (f_rn)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb2-compact: mov.b $rm, @-$rn

void
sh4_nofpu_sem_movb2_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
  {
    UQI opval = SUBWORDSIUQI (current_cpu->h_grc_get (FLD (f_rm)), 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb3-compact: mov.b $rm, @(r0,$rn)

void
sh4_nofpu_sem_movb3_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    UQI opval = SUBWORDSIUQI (current_cpu->h_grc_get (FLD (f_rm)), 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rn))) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rn))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb4-compact: mov.b r0, @($imm8, gbr)

void
sh4_nofpu_sem_movb4_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8));
  {
    UQI opval = SUBWORDSIUQI (current_cpu->h_grc_get (((UINT) 0)), 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb5-compact: mov.b r0, @($imm4, $rm)

void
sh4_nofpu_sem_movb5_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb5_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm4));
  {
    UQI opval = SUBWORDSIUQI (current_cpu->h_grc_get (((UINT) 0)), 3);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb6-compact: mov.b @$rm, $rn

void
sh4_nofpu_sem_movb6_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, current_cpu->h_grc_get (FLD (f_rm))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb7-compact: mov.b @${rm}+, $rn

void
sh4_nofpu_sem_movb7_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  QI tmp_data;
  tmp_data = current_cpu->GETMEMQI (pc, current_cpu->h_grc_get (FLD (f_rm)));
if (EQSI (FLD (f_rm), FLD (f_rn))) {
  {
    SI opval = EXTQISI (tmp_data);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
} else {
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 1);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
}
  {
    SI opval = EXTQISI (tmp_data);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb8-compact: mov.b @(r0, $rm), $rn

void
sh4_nofpu_sem_movb8_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rm)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb9-compact: mov.b @($imm8, gbr), r0

void
sh4_nofpu_sem_movb9_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movb10-compact: mov.b @($imm4, $rm), r0

void
sh4_nofpu_sem_movb10_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm4))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl1-compact: mov.l $rm, @$rn

void
sh4_nofpu_sem_movl1_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_grc_get (FLD (f_rn)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl2-compact: mov.l $rm, @-$rn

void
sh4_nofpu_sem_movl2_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
  {
    SI opval = current_cpu->h_grc_get (FLD (f_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl3-compact: mov.l $rm, @(r0, $rn)

void
sh4_nofpu_sem_movl3_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rn))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rn))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl4-compact: mov.l r0, @($imm8x4, gbr)

void
sh4_nofpu_sem_movl4_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl4_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (((UINT) 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8x4)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8x4)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl5-compact: mov.l $rm, @($imm4x4, $rn)

void
sh4_nofpu_sem_movl5_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl5_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_grc_get (FLD (f_rn)), FLD (f_imm4x4)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rn)), FLD (f_imm4x4)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl6-compact: mov.l @$rm, $rn

void
sh4_nofpu_sem_movl6_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl7-compact: mov.l @${rm}+, $rn

void
sh4_nofpu_sem_movl7_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->GETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
if (EQSI (FLD (f_rm), FLD (f_rn))) {
  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
} else {
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 4);
    written |= (1ULL << 5);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl8-compact: mov.l @(r0, $rm), $rn

void
sh4_nofpu_sem_movl8_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rm))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl9-compact: mov.l @($imm8x4, gbr), r0

void
sh4_nofpu_sem_movl9_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8x4)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl10-compact: mov.l @($imm8x4, pc), $rn

void
sh4_nofpu_sem_movl10_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (FLD (f_imm8x4), ANDDI (ADDDI (pc, 4), INVSI (3))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl11-compact: mov.l @($imm4x4, $rm), $rn

void
sh4_nofpu_sem_movl11_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl11_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm4x4)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl12-compact: mov.l @($imm12x4, $rm), $rn

void
sh4_nofpu_sem_movl12_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->GETMEMSI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm12x4)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movl13-compact: mov.l $rm, @($imm12x4, $rn)

void
sh4_nofpu_sem_movl13_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 4;

  {
    SI opval = current_cpu->h_grc_get (FLD (f_rm));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_grc_get (FLD (f_rn)), FLD (f_imm12x4)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rn)), FLD (f_imm12x4)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw1-compact: mov.w $rm, @$rn

void
sh4_nofpu_sem_movw1_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_grc_get (FLD (f_rn)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, current_cpu->h_grc_get (FLD (f_rn)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw2-compact: mov.w $rm, @-$rn

void
sh4_nofpu_sem_movw2_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 2);
  {
    HI opval = SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw3-compact: mov.w $rm, @(r0, $rn)

void
sh4_nofpu_sem_movw3_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb3_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rn))) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rn))), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw4-compact: mov.w r0, @($imm8x2, gbr)

void
sh4_nofpu_sem_movw4_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw4_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = SUBWORDSIHI (current_cpu->h_grc_get (((UINT) 0)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8x2)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8x2)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw5-compact: mov.w r0, @($imm4x2, $rm)

void
sh4_nofpu_sem_movw5_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw5_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    HI opval = SUBWORDSIHI (current_cpu->h_grc_get (((UINT) 0)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm4x2)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMHI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm4x2)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw6-compact: mov.w @$rm, $rn

void
sh4_nofpu_sem_movw6_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, current_cpu->h_grc_get (FLD (f_rm))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw7-compact: mov.w @${rm}+, $rn

void
sh4_nofpu_sem_movw7_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  HI tmp_data;
  tmp_data = current_cpu->GETMEMHI (pc, current_cpu->h_grc_get (FLD (f_rm)));
if (EQSI (FLD (f_rm), FLD (f_rn))) {
  {
    SI opval = EXTHISI (tmp_data);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
} else {
  {
    SI opval = ADDSI (current_cpu->h_grc_get (FLD (f_rm)), 2);
    written |= (1ULL << 4);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rm) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rm), opval);
  }
}
  {
    SI opval = EXTHISI (tmp_data);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw8-compact: mov.w @(r0, $rm), $rn

void
sh4_nofpu_sem_movw8_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movb8_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_grc_get (FLD (f_rm)))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw9-compact: mov.w @($imm8x2, gbr), r0

void
sh4_nofpu_sem_movw9_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw9_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->h_gbr_get (), FLD (f_imm8x2))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw10-compact: mov.w @($imm8x2, pc), $rn

void
sh4_nofpu_sem_movw10_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDDI (ADDDI (pc, 4), FLD (f_imm8x2))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movw11-compact: mov.w @($imm4x2, $rm), r0

void
sh4_nofpu_sem_movw11_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw11_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->h_grc_get (FLD (f_rm)), FLD (f_imm4x2))));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mova-compact: mova @($imm8x4, pc), r0

void
sh4_nofpu_sem_mova_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl9_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ADDDI (ANDDI (ADDDI (pc, 4), INVSI (3)), FLD (f_imm8x4));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movcal-compact: movca.l r0, @$rn

void
sh4_nofpu_sem_movcal_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_grc_get (((UINT) 0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_grc_get (FLD (f_rn)) << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, current_cpu->h_grc_get (FLD (f_rn)), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** movt-compact: movt $rn

void
sh4_nofpu_sem_movt_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ZEXTBISI (current_cpu->h_tbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mull-compact: mul.l $rm, $rn

void
sh4_nofpu_sem_mull_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = MULSI (current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_grc_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** mulsw-compact: muls.w $rm, $rn

void
sh4_nofpu_sem_mulsw_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = MULSI (EXTHISI (SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1)), EXTHISI (SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rn)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** muluw-compact: mulu.w $rm, $rn

void
sh4_nofpu_sem_muluw_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = MULSI (ZEXTHISI (SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 1)), ZEXTHISI (SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rn)), 1)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "macl" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_macl_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** neg-compact: neg $rm, $rn

void
sh4_nofpu_sem_neg_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = NEGSI (current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** negc-compact: negc $rm, $rn

void
sh4_nofpu_sem_negc_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_flag;
  tmp_flag = SUBCFSI (0, current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_tbit_get ());
  {
    SI opval = SUBCSI (0, current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_tbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = tmp_flag;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** nop-compact: nop

void
sh4_nofpu_sem_nop_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

((void) 0); /*nop*/

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** not-compact: not $rm64, $rn64

void
sh4_nofpu_sem_not_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = INVDI (current_cpu->h_gr_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ocbi-compact: ocbi @$rn

void
sh4_nofpu_sem_ocbi_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ocbp-compact: ocbp @$rn

void
sh4_nofpu_sem_ocbp_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ocbwb-compact: ocbwb @$rn

void
sh4_nofpu_sem_ocbwb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    SI opval = current_cpu->h_grc_get (FLD (f_rn));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
((void) 0); /*nop*/
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** or-compact: or $rm64, $rn64

void
sh4_nofpu_sem_or_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = ORDI (current_cpu->h_gr_get (FLD (f_rm)), current_cpu->h_gr_get (FLD (f_rn)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** ori-compact: or #$uimm8, r0

void
sh4_nofpu_sem_ori_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ORSI (current_cpu->h_grc_get (((UINT) 0)), ZEXTSIDI (FLD (f_imm8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** orb-compact: or.b #$imm8, @(r0, gbr)

void
sh4_nofpu_sem_orb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  UQI tmp_data;
  tmp_addr = ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_gbr_get ());
  tmp_data = ORQI (current_cpu->GETMEMUQI (pc, tmp_addr), FLD (f_imm8));
  {
    UQI opval = tmp_data;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** pref-compact: pref @$rn

void
sh4_nofpu_sem_pref_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->sh64_pref (current_cpu->h_grc_get (FLD (f_rn)));

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rotcl-compact: rotcl $rn

void
sh4_nofpu_sem_rotcl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_temp;
  tmp_temp = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31);
  {
    SI opval = ORSI (SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 1), current_cpu->h_tbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_temp) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rotcr-compact: rotcr $rn

void
sh4_nofpu_sem_rotcr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_lsbit;
  SI tmp_temp;
  tmp_lsbit = ((EQSI (ANDSI (current_cpu->h_grc_get (FLD (f_rn)), 1), 0)) ? (0) : (1));
  tmp_temp = current_cpu->h_tbit_get ();
  {
    SI opval = ORSI (SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 1), SLLSI (tmp_temp, 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_lsbit) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rotl-compact: rotl $rn

void
sh4_nofpu_sem_rotl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_temp;
  tmp_temp = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31);
  {
    SI opval = ORSI (SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 1), tmp_temp);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_temp) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rotr-compact: rotr $rn

void
sh4_nofpu_sem_rotr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_lsbit;
  SI tmp_temp;
  tmp_lsbit = ((EQSI (ANDSI (current_cpu->h_grc_get (FLD (f_rn)), 1), 0)) ? (0) : (1));
  tmp_temp = tmp_lsbit;
  {
    SI opval = ORSI (SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 1), SLLSI (tmp_temp, 31));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_lsbit) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** rts-compact: rts

void
sh4_nofpu_sem_rts_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  {
    UDI opval = ADDDI (pc, 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->branch (opval, npc, status);
  }
current_cpu->save_delayed_pc (current_cpu->h_pr_get ());
  {
    UDI opval = current_cpu->h_pr_get ();
    buf.h_pc_writes [(tick + 1) % sh4_nofpu::pipe_sz].push (sh4_nofpu::write<UDI>(pc, opval));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "pc" << ":=0x" << hex << opval << dec << "  ";
  }
current_cpu->notify_ret (current_cpu->h_pr_get ());
}

  current_cpu->done_cti_insn (npc, status);
#undef FLD
}

// ********** sets-compact: sets

void
sh4_nofpu_sem_sets_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = 1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "sbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_sbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sett-compact: sett

void
sh4_nofpu_sem_sett_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.fmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = 1;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shad-compact: shad $rm, $rn

void
sh4_nofpu_sem_shad_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_shamt;
  tmp_shamt = ANDSI (current_cpu->h_grc_get (FLD (f_rm)), 31);
if (GESI (current_cpu->h_grc_get (FLD (f_rm)), 0)) {
  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), tmp_shamt);
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
} else {
if (NESI (tmp_shamt, 0)) {
  {
    SI opval = SRASI (current_cpu->h_grc_get (FLD (f_rn)), SUBSI (32, tmp_shamt));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
} else {
if (LTSI (current_cpu->h_grc_get (FLD (f_rn)), 0)) {
  {
    SI opval = NEGSI (1);
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shal-compact: shal $rn

void
sh4_nofpu_sem_shal_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  tmp_t = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31);
  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_t) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shar-compact: shar $rn

void
sh4_nofpu_sem_shar_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  tmp_t = ANDSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
  {
    SI opval = SRASI (current_cpu->h_grc_get (FLD (f_rn)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_t) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shld-compact: shld $rm, $rn

void
sh4_nofpu_sem_shld_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  SI tmp_shamt;
  tmp_shamt = ANDSI (current_cpu->h_grc_get (FLD (f_rm)), 31);
if (GESI (current_cpu->h_grc_get (FLD (f_rm)), 0)) {
  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), tmp_shamt);
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
} else {
if (NESI (tmp_shamt, 0)) {
  {
    SI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), SUBSI (32, tmp_shamt));
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
} else {
  {
    SI opval = 0;
    written |= (1ULL << 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}
}
}

  abuf->written = written;
  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shll-compact: shll $rn

void
sh4_nofpu_sem_shll_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  tmp_t = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 31);
  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_t) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shll2-compact: shll2 $rn

void
sh4_nofpu_sem_shll2_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shll8-compact: shll8 $rn

void
sh4_nofpu_sem_shll8_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shll16-compact: shll16 $rn

void
sh4_nofpu_sem_shll16_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SLLSI (current_cpu->h_grc_get (FLD (f_rn)), 16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlr-compact: shlr $rn

void
sh4_nofpu_sem_shlr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  tmp_t = ANDSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
  {
    SI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 1);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_t) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlr2-compact: shlr2 $rn

void
sh4_nofpu_sem_shlr2_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 2);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlr8-compact: shlr8 $rn

void
sh4_nofpu_sem_shlr8_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 8);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** shlr16-compact: shlr16 $rn

void
sh4_nofpu_sem_shlr16_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 16);
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stc-gbr-compact: stc gbr, $rn

void
sh4_nofpu_sem_stc_gbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_gbr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stc-vbr-compact: stc vbr, $rn

void
sh4_nofpu_sem_stc_vbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_vbr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stcl-gbr-compact: stc.l gbr, @-$rn

void
sh4_nofpu_sem_stcl_gbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
  {
    SI opval = current_cpu->h_gbr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stcl-vbr-compact: stc.l vbr, @-$rn

void
sh4_nofpu_sem_stcl_vbr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
  {
    SI opval = current_cpu->h_vbr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sts-mach-compact: sts mach, $rn

void
sh4_nofpu_sem_sts_mach_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_mach_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stsl-mach-compact: sts.l mach, @-$rn

void
sh4_nofpu_sem_stsl_mach_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
  {
    SI opval = current_cpu->h_mach_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sts-macl-compact: sts macl, $rn

void
sh4_nofpu_sem_sts_macl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_macl_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stsl-macl-compact: sts.l macl, @-$rn

void
sh4_nofpu_sem_stsl_macl_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
  {
    SI opval = current_cpu->h_macl_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sts-pr-compact: sts pr, $rn

void
sh4_nofpu_sem_sts_pr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movw10_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = current_cpu->h_pr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** stsl-pr-compact: sts.l pr, @-$rn

void
sh4_nofpu_sem_stsl_pr_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), 4);
  {
    SI opval = current_cpu->h_pr_get ();
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->SETMEMSI (pc, tmp_addr, opval);
  }
  {
    SI opval = tmp_addr;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** sub-compact: sub $rm, $rn

void
sh4_nofpu_sem_sub_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** subc-compact: subc $rm, $rn

void
sh4_nofpu_sem_subc_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_flag;
  tmp_flag = SUBCFSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_tbit_get ());
  {
    SI opval = SUBCSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_tbit_get ());
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = tmp_flag;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** subv-compact: subv $rm, $rn

void
sh4_nofpu_sem_subv_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  BI tmp_t;
  tmp_t = SUBOFSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)), 0);
  {
    SI opval = SUBSI (current_cpu->h_grc_get (FLD (f_rn)), current_cpu->h_grc_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
  {
    BI opval = ((tmp_t) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** swapb-compact: swap.b $rm, $rn

void
sh4_nofpu_sem_swapb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  UHI tmp_top_half;
  UQI tmp_byte1;
  UQI tmp_byte0;
  tmp_top_half = SUBWORDSIHI (current_cpu->h_grc_get (FLD (f_rm)), 0);
  tmp_byte1 = SUBWORDSIQI (current_cpu->h_grc_get (FLD (f_rm)), 2);
  tmp_byte0 = SUBWORDSIQI (current_cpu->h_grc_get (FLD (f_rm)), 3);
  {
    SI opval = ORSI (SLLSI (tmp_top_half, 16), ORSI (SLLSI (tmp_byte0, 8), tmp_byte1));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** swapw-compact: swap.w $rm, $rn

void
sh4_nofpu_sem_swapw_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl12_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ORSI (SRLSI (current_cpu->h_grc_get (FLD (f_rm)), 16), SLLSI (current_cpu->h_grc_get (FLD (f_rm)), 16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** tasb-compact: tas.b @$rn

void
sh4_nofpu_sem_tasb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_divu_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  UQI tmp_byte;
  tmp_byte = current_cpu->GETMEMUQI (pc, current_cpu->h_grc_get (FLD (f_rn)));
  {
    BI opval = ((EQQI (tmp_byte, 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
  tmp_byte = ORQI (tmp_byte, 128);
  {
    UQI opval = tmp_byte;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) current_cpu->h_grc_get (FLD (f_rn)) << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, current_cpu->h_grc_get (FLD (f_rn)), opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** trapa-compact: trapa #$uimm8

void
sh4_nofpu_sem_trapa_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

current_cpu->sh64_compact_trapa (FLD (f_imm8), pc);

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** tst-compact: tst $rm, $rn

void
sh4_nofpu_sem_tst_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_movl13_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = ((EQSI (ANDSI (current_cpu->h_grc_get (FLD (f_rm)), current_cpu->h_grc_get (FLD (f_rn))), 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** tsti-compact: tst #$uimm8, r0

void
sh4_nofpu_sem_tsti_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    BI opval = ((EQSI (ANDSI (current_cpu->h_grc_get (((UINT) 0)), ZEXTSISI (FLD (f_imm8))), 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** tstb-compact: tst.b #$imm8, @(r0, gbr)

void
sh4_nofpu_sem_tstb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  tmp_addr = ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_gbr_get ());
  {
    BI opval = ((EQQI (ANDQI (current_cpu->GETMEMUQI (pc, tmp_addr), FLD (f_imm8)), 0)) ? (1) : (0));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "tbit" << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_tbit_set (opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xor-compact: xor $rm64, $rn64

void
sh4_nofpu_sem_xor_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_and_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    DI opval = XORDI (current_cpu->h_gr_get (FLD (f_rn)), current_cpu->h_gr_get (FLD (f_rm)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "gr" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_gr_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xori-compact: xor #$uimm8, r0

void
sh4_nofpu_sem_xori_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = XORSI (current_cpu->h_grc_get (((UINT) 0)), ZEXTSIDI (FLD (f_imm8)));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << ((UINT) 0) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (((UINT) 0), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xorb-compact: xor.b #$imm8, @(r0, gbr)

void
sh4_nofpu_sem_xorb_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_andi_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

{
  DI tmp_addr;
  UQI tmp_data;
  tmp_addr = ADDSI (current_cpu->h_grc_get (((UINT) 0)), current_cpu->h_gbr_get ());
  tmp_data = XORQI (current_cpu->GETMEMUQI (pc, tmp_addr), FLD (f_imm8));
  {
    UQI opval = tmp_data;
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "memory" << '[' <<  "0x" << hex << (UDI) tmp_addr << dec << ']' << ":=0x" << hex << (USI) opval << dec << "  ";
    current_cpu->SETMEMUQI (pc, tmp_addr, opval);
  }
}

  current_cpu->done_insn (npc, status);
#undef FLD
}

// ********** xtrct-compact: xtrct $rm, $rn

void
sh4_nofpu_sem_xtrct_compact (sh4_nofpu_cpu* current_cpu, sh4_nofpu_scache* sem, const int tick, 
	sh4_nofpu::write_stacks &buf)
{
#define FLD(f) abuf->fields.sfmt_macl_compact.f
  sem_status status = SEM_STATUS_NORMAL;
  sh4_nofpu_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 2;

  {
    SI opval = ORSI (SLLSI (current_cpu->h_grc_get (FLD (f_rm)), 16), SRLSI (current_cpu->h_grc_get (FLD (f_rn)), 16));
    if (UNLIKELY(current_cpu->trace_result_p))
      current_cpu->trace_stream << "grc" << '[' << FLD (f_rn) << ']' << ":=0x" << hex << opval << dec << "  ";
    current_cpu->h_grc_set (FLD (f_rn), opval);
  }

  current_cpu->done_insn (npc, status);
#undef FLD
}

