// sh.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006, 2010 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh.h"
#include "fp.h"

extern "C" {
#include "bfd.h"
#include "dis-asm.h"
}

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace sh;

template<class CGEN_CPU>
sh_cpu<CGEN_CPU>::sh_cpu () :
  pending_latency (0)
{
#if 0
  for (unsigned i = 0; i < 16; ++i)
    {
      string name = string ("GR") + make_numeric_attribute (i);
      SI* value = & this->hardware.h_gr[i];
      this->add_watchable_register (name, value);
    }
#endif
  // add syscall registers
  this->add_watchable_register (string("syscall-arg0"), &syscall_arg0);
  this->add_watchable_register (string("syscall-arg1"), &syscall_arg1);
  this->add_watchable_register (string("syscall-arg2"), &syscall_arg2);
  this->add_watchable_register (string("syscall-arg3"), &syscall_arg3);
  this->add_watchable_register (string("syscall-result"), &syscall_result);
  this->add_watchable_register (string("syscall-error"), &syscall_error);
  syscall_trap_num = 34;
  this->add_attribute (string("syscall-trap"), &syscall_trap_num, "setting");

  add_watchable_pin ("cache-prefetch", &cache_prefetch_pin);

#if 0 // customize this  
  this->create_gdb_register_attrs (17, "", & this->hardware.h_pc);
#endif
}

template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::reset()
{
  this->hardware.h_sr = 0xf0;
  write_stacks_reset ();
  if (UNLIKELY (this->trace_counter_p || this->final_insn_count_p))
    this->set_total_latency (2); // Initial IF + ID
  else
    this->set_total_latency (0);
}

template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::set_eflags(sid::host_int_4 flags)
{
  this->eflags = flags;
}

static int ef_to_bfd_mach_table [] = { EF_SH_BFD_TABLE };

template<class CGEN_CPU>
int
sh_cpu<CGEN_CPU>::bfd_machine () const
{
  return ef_to_bfd_mach_table[elf_machine ()];
}

template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::invalid_insn (PCADDR pc)
{
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_invalid_insn, pc);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "sh: unhandled invalid insn, pc=" << pc << endl;
      break;

    case cpu_trap_skip:
      {
	PCADDR npc = pc + insn_size (pc);
	this->h_pc_set (npc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
}

// Memory trap(/fault) handling.
template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::memory_trap (const cpu_memory_fault& t)
{
  this->h_pc_set (t.pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_memory_fault, t.address);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "sh: unhandled memory trap, pc=" << t.pc << endl;
      break;

    case cpu_trap_skip:
      {
	PCADDR pc = t.pc + insn_size (pc);
	this->h_pc_set (pc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
}

template<class CGEN_CPU>
string
sh_cpu<CGEN_CPU>::dbg_get_reg (host_int_4 reg)
{
  string attr;
  host_int_4 val;
  int size = reg < 16 ? 2 : 4;
#if 0 // customize this
  /* Bank zero regs */
  if (reg < 16)
    val = h_gr_get (reg);
  else if (reg == 16)
    val = h_pc_get ();
  else
#endif
    val = 0;

  // Change to "target endian".
  little_int_4 v = val;
  for (unsigned i = 0; i < size; i++)
    attr += v.read_byte (i);

  return attr;
}

template<class CGEN_CPU>
component::status
sh_cpu<CGEN_CPU>::dbg_set_reg (host_int_4 reg, const string& attr)
{
  // change from "target endian"
  little_int_4 v;
  int size = reg < 16 ? 2 : 4;
  for (unsigned i = 0; i < size; i++)
    v.write_byte (i, attr[i]);
  host_int_4 val = v;

#if 0 // customize this
  /* Bank zero regs */
  if (reg < 16)
    h_gr_set (reg, val);
  else if (reg == 16)
    h_pc_set (val);
  else
#endif
    return component::bad_value;

  return component::ok;
}

// C++ implementations of instructions follow here
template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::sh64_break (PCADDR pc)
{
  this->yield();
  throw cpu_exception ();
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fldi0 ()
{
  return this->fpu.ops->floatsisf (& this->fpu, fp::round_default, 0);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fldi1 ()
{
  return this->fpu.ops->floatsisf (& this->fpu, fp::round_default, 1);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fabsd(DF drgh)
{
  return this->fpu.ops->absdf (& this->fpu, drgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fabss(SF frgh)
{
  return this->fpu.ops->abssf (& this->fpu, frgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_faddd(DF drg, DF drh)
{
  return this->fpu.ops->adddf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fadds(SF frg, SF frh)
{
  return this->fpu.ops->addsf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpeqd(DF drg, DF drh)
{
  return this->fpu.ops->eqdf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpeqs(SF frg, SF frh)
{
  return this->fpu.ops->eqsf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpged(DF drg, DF drh)
{
  return this->fpu.ops->gedf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpges(SF frg, SF frh)
{
  return this->fpu.ops->gesf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpgtd(DF drg, DF drh)
{
  return this->fpu.ops->gtdf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpgts(SF frg, SF frh)
{
  return this->fpu.ops->gtsf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpund(DF drg, DF drh)
{
  return this->fpu.ops->unordereddf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
BI
sh_cpu<CGEN_CPU>::sh64_fcmpuns(SF frg, SF frh)
{
  return this->fpu.ops->unorderedsf (& this->fpu, frg, frh);
}  

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fcnvds(DF drgh)
{
  return this->fpu.ops->ftruncdfsf (& this->fpu, fp::round_default, drgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fcnvsd(SF frgh)
{
  return this->fpu.ops->fextsfdf (& this->fpu, fp::round_default, frgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fdivd(DF drg, DF drh)
{
  return this->fpu.ops->divdf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fdivs(SF frg, SF frh)
{
  return this->fpu.ops->divsf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_floatld(SF frgh)
{
  return this->fpu.ops->floatsidf (& this->fpu, fp::round_default, frgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_floatls(SF frgh)
{
  return this->fpu.ops->floatsisf (& this->fpu, fp::round_default, frgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_floatqd(DF drgh)
{
  return this->fpu.ops->floatdidf (& this->fpu, fp::round_default, drgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_floatqs(DF drgh)
{
  return this->fpu.ops->floatdisf (& this->fpu, fp::round_default, drgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fmacs(SF fr0, SF frm, SF frn)
{
  SF result = this->fpu.ops->mulsf (& this->fpu, fr0, frm);
  result = this->fpu.ops->addsf (& this->fpu, result, frn);
  return result;
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fmuld(DF drg, DF drh)
{
  return this->fpu.ops->muldf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fmuls(SF frg, SF frh)
{
  return this->fpu.ops->mulsf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fnegd(DF drgh)
{
  return this->fpu.ops->negdf (& this->fpu, drgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fnegs(SF frgh)
{
  return this->fpu.ops->negsf (& this->fpu, frgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fsqrtd(DF drgh)
{
  return this->fpu.ops->sqrtdf (& this->fpu, drgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fsqrts(SF frgh)
{
  return this->fpu.ops->sqrtsf (& this->fpu, frgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_fsubd(DF drg, DF drh)
{
  return this->fpu.ops->subdf (& this->fpu, drg, drh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_fsubs(SF frg, SF frh)
{
  return this->fpu.ops->subsf (& this->fpu, frg, frh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_ftrcdl(DF drgh)
{
  return this->fpu.ops->fixdfsi (& this->fpu, fp::round_default, drgh);
}

template<class CGEN_CPU>
SF
sh_cpu<CGEN_CPU>::sh64_ftrcsl(SF frgh)
{
  return this->fpu.ops->fixsfsi (& this->fpu, fp::round_default, frgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_ftrcdq(DF drgh)
{
  return this->fpu.ops->fixdfdi (& this->fpu, fp::round_default, drgh);
}

template<class CGEN_CPU>
DF
sh_cpu<CGEN_CPU>::sh64_ftrcsq(SF frgh)
{
  return this->fpu.ops->fixsfdi (& this->fpu, fp::round_default, frgh);
}

template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::sh64_ftrvs(unsigned g, unsigned h, unsigned f)
{
  int i, j;
  SF zero = this->fpu.ops->floatsisf (& this->fpu, fp::round_default, 0);
  for (i = 0; i < 4; i++)
    {
      SF result = zero;
      for (j = 0; j < 4; j++)
	{
	  SF f1, f2, temp;
	  f1 = this->h_fr_get ((g + i) + (j * 4));
	  f2 = this->h_fr_get (h + j);
	  temp = this->fpu.ops->mulsf (& this->fpu, f1, f2);
	  result = this->fpu.ops->addsf (& this->fpu, result, temp);
	}
      this->h_fr_set (f + i, result);
    }
}

template<class CGEN_CPU>
void
sh_cpu<CGEN_CPU>::sh64_pref (DI addr)
{
  cache_prefetch_pin.drive (addr);
}

template <class CGEN_CPU>
SI
sh_cpu<CGEN_CPU>::sh64_movua (PCADDR pc, SI rn)
{
  // Move the data one byte at a time to avoid alignment problems.
  // Be aware of endianness.
  if (this->current_endianness() == endian_big)
    {
      big_int_4 v;
      for (int i = 0; i < 4; ++i)
	v.write_byte (i, GETMEMQI (pc, rn + i));
      return v.integer_value ();
    }

  little_int_4 v;
  for (int i = 0; i < 4; ++i)
    v.write_byte (i, GETMEMQI (pc, rn + i));
  return v.integer_value ();
}

// Explicit instantiations
template class sh_cpu<sh2_cpu_cgen>;
template class sh_cpu<sh2e_cpu_cgen>;
template class sh_cpu<sh2a_fpu_cpu_cgen>;
template class sh_cpu<sh2a_nofpu_cpu_cgen>;
template class sh_cpu<sh3_cpu_cgen>;
template class sh_cpu<sh3e_cpu_cgen>;
template class sh_cpu<sh4_nofpu_cpu_cgen>;
template class sh_cpu<sh4_cpu_cgen>;
template class sh_cpu<sh4a_nofpu_cpu_cgen>;
template class sh_cpu<sh4a_cpu_cgen>;
template class sh_cpu<sh4al_cpu_cgen>;
template class sh_cpu<sh5_cpu_cgen>;

template class sh_cpu_impl<sh2_cpu_cgen>;
template class sh_cpu_impl<sh2e_cpu_cgen>;
template class sh_cpu_impl<sh2a_fpu_cpu_cgen>;
template class sh_cpu_impl<sh2a_nofpu_cpu_cgen>;
template class sh_cpu_impl<sh3_cpu_cgen>;
template class sh_cpu_impl<sh3e_cpu_cgen>;
template class sh_cpu_impl<sh4_nofpu_cpu_cgen>;
template class sh_cpu_impl<sh4_cpu_cgen>;
template class sh_cpu_impl<sh4a_nofpu_cpu_cgen>;
template class sh_cpu_impl<sh4a_cpu_cgen>;
template class sh_cpu_impl<sh4al_cpu_cgen>;
template class sh_cpu_impl<sh5_cpu_cgen>;

// Used by the disassembler. The real definitions are in opcodes/sh-opc.h
// which we don't pull in here.
#define MASK(LO,HI)  (  LO < 1   ? ((1 << (HI + 1)) - 1) \
		      : HI > 30  ? (-1 << LO) \
		      : LO == HI ? (1 << LO) \
		      :            (((1 << (HI + 1)) - 1) & (-1 << LO)))
#define arch_sh1_base	    (1 << 0)
#define arch_sh2_base	    (1 << 1)
#define arch_sh2a_sh3_base  (1 << 2)
#define arch_sh3_base	    (1 << 3)
#define arch_sh2a_sh4_base  (1 << 4)
#define arch_sh4_base	    (1 << 5)
#define arch_sh4a_base	    (1 << 6)
#define arch_sh2a_base      (1 << 7)
#define arch_sh_base_mask   MASK (0, 7)

/* Bits 8 ... 24 are currently free.  */

/* This is an annotation on instruction types, but we
   abuse the arch field in instructions to denote it.  */
#define arch_op32          (1 << 25)  /* This is a 32-bit opcode.  */
#define arch_opann_mask    MASK (25, 25)

#define arch_sh_no_mmu	   (1 << 26)
#define arch_sh_has_mmu    (1 << 27)
#define arch_sh_mmu_mask   MASK (26, 27)

#define arch_sh_no_co	   (1 << 28)  /* Neither FPU nor DSP co-processor.  */
#define arch_sh_sp_fpu	   (1 << 29)  /* Single precision FPU.  */
#define arch_sh_dp_fpu	   (1 << 30)  /* Double precision FPU.  */
#define arch_sh_has_dsp	   (1 << 31)
#define arch_sh_co_mask    MASK (28, 31)


#define arch_sh1	                   (arch_sh1_base     |arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh2	                   (arch_sh2_base     |arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh2a	                   (arch_sh2a_base    |arch_sh_no_mmu |arch_sh_dp_fpu)
#define arch_sh2a_nofpu	                   (arch_sh2a_base    |arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh2e	                   (arch_sh2_base     |arch_sh_no_mmu |arch_sh_sp_fpu)
#define arch_sh_dsp	                   (arch_sh2_base     |arch_sh_no_mmu |arch_sh_has_dsp)
#define arch_sh3_nommu	                   (arch_sh3_base     |arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh3	                   (arch_sh3_base     |arch_sh_has_mmu|arch_sh_no_co)
#define arch_sh3e	                   (arch_sh3_base     |arch_sh_has_mmu|arch_sh_sp_fpu)
#define arch_sh3_dsp	                   (arch_sh3_base     |arch_sh_has_mmu|arch_sh_has_dsp)
#define arch_sh4	                   (arch_sh4_base     |arch_sh_has_mmu|arch_sh_dp_fpu)
#define arch_sh4a	                   (arch_sh4a_base    |arch_sh_has_mmu|arch_sh_dp_fpu)
#define arch_sh4al_dsp	                   (arch_sh4a_base    |arch_sh_has_mmu|arch_sh_has_dsp)
#define arch_sh4_nofpu	                   (arch_sh4_base     |arch_sh_has_mmu|arch_sh_no_co)
#define arch_sh4a_nofpu	                   (arch_sh4a_base    |arch_sh_has_mmu|arch_sh_no_co)
#define arch_sh4_nommu_nofpu               (arch_sh4_base     |arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh2a_nofpu_or_sh4_nommu_nofpu (arch_sh2a_sh4_base|arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh2a_nofpu_or_sh3_nommu       (arch_sh2a_sh3_base|arch_sh_no_mmu |arch_sh_no_co)
#define arch_sh2a_or_sh3e                  (arch_sh2a_sh4_base|arch_sh_no_mmu |arch_sh_sp_fpu)
#define arch_sh2a_or_sh4                   (arch_sh2a_sh4_base|arch_sh_no_mmu |arch_sh_dp_fpu)

#define SH_ARCH_UNKNOWN_ARCH 0xffffffff

// Used by the disassembler. The real version is in bfd/cpu-sh.c
// which we don't pull in here.
static struct { unsigned long bfd_mach, arch; } bfd_to_arch_table[] =
{
  { bfd_mach_sh,              arch_sh1 },
  { bfd_mach_sh2,             arch_sh2 },
  { bfd_mach_sh2e,            arch_sh2e },
  { bfd_mach_sh_dsp,          arch_sh_dsp },
  { bfd_mach_sh2a,            arch_sh2a },
  { bfd_mach_sh2a_nofpu,      arch_sh2a_nofpu },

  { bfd_mach_sh2a_nofpu_or_sh4_nommu_nofpu,         arch_sh2a_nofpu_or_sh4_nommu_nofpu },
  { bfd_mach_sh2a_nofpu_or_sh3_nommu,               arch_sh2a_nofpu_or_sh3_nommu },
  { bfd_mach_sh2a_or_sh4,     arch_sh2a_or_sh4 },
  { bfd_mach_sh2a_or_sh3e,    arch_sh2a_or_sh3e },
  
  { bfd_mach_sh3,             arch_sh3 },
  { bfd_mach_sh3_nommu,       arch_sh3_nommu },
  { bfd_mach_sh3_dsp,         arch_sh3_dsp },
  { bfd_mach_sh3e,            arch_sh3e },
  { bfd_mach_sh4,             arch_sh4 },
  { bfd_mach_sh4a,            arch_sh4a },
  { bfd_mach_sh4al_dsp,       arch_sh4al_dsp },
  { bfd_mach_sh4_nofpu,       arch_sh4_nofpu },
  { bfd_mach_sh4_nommu_nofpu, arch_sh4_nommu_nofpu },
  { bfd_mach_sh4a_nofpu,      arch_sh4a_nofpu },
  { 0, 0 }   /* Terminator.  */
};

// Convert a BFD mach number into the right opcodes arch flags
// using the table above.
extern "C"
unsigned int
sh_get_arch_from_bfd_mach (unsigned long mach)
{
  int i = 0;

  while (bfd_to_arch_table[i].bfd_mach != 0)
    {
      if (bfd_to_arch_table[i].bfd_mach == mach)
	return bfd_to_arch_table[i].arch;
      i++;
    }

  return SH_ARCH_UNKNOWN_ARCH;
}
