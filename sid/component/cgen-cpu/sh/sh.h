// sh.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH_H
#define SH_H

#include "cgen-cpu.h"
#include "sh-desc.h"
#include "cgen-fpu.h"

#define WRITE_BUF_SZ 2
#include "sh2-defs.h"
#include "sh2-decode.h"
#include "sh2-model.h"
#include "sh2e-defs.h"
#include "sh2e-decode.h"
#include "sh2e-model.h"
#include "sh2a-fpu-defs.h"
#include "sh2a-fpu-decode.h"
#include "sh2a-fpu-model.h"
#include "sh2a-nofpu-defs.h"
#include "sh2a-nofpu-decode.h"
#include "sh2a-nofpu-model.h"
#include "sh3-defs.h"
#include "sh3-decode.h"
#include "sh3-model.h"
#include "sh3e-defs.h"
#include "sh3e-decode.h"
#include "sh3e-model.h"
#include "sh4-defs.h"
#include "sh4-decode.h"
#include "sh4-model.h"
#include "sh4-nofpu-defs.h"
#include "sh4-nofpu-decode.h"
#include "sh4-nofpu-model.h"
#include "sh4a-defs.h"
#include "sh4a-decode.h"
#include "sh4a-model.h"
#include "sh4a-nofpu-defs.h"
#include "sh4a-nofpu-decode.h"
#include "sh4a-nofpu-model.h"
#include "sh4al-defs.h"
#include "sh4al-decode.h"
#include "sh4al-model.h"
#include "sh5-compact-defs.h"
#include "sh5-compact-decode.h"
#include "sh5-compact-model.h"
#include "sh5-media-defs.h"
#include "sh5-media-decode.h"
#include "sh5-media-model.h"
#include "elf/sh.h"

#include <iostream>

// Map sh5::write_stacks onto sh5_media::write_stacks
// for sh5-cpu.h
namespace sh5
{
  const int pipe_sz = sh5_media::pipe_sz;
  typedef sh5_media::write_stacks write_stacks;
};

namespace sh
{
  using namespace cgen;
  using namespace sh;
  using namespace sh2;
  using namespace sh2e;
  using namespace sh2a_fpu;
  using namespace sh2a_nofpu;
  using namespace sh3;
  using namespace sh3e;
  using namespace sh4_nofpu;
  using namespace sh4;
  using namespace sh4a_nofpu;
  using namespace sh4a;
  using namespace sh4al;
  using namespace sh5;
  using namespace sh5_compact;
  using namespace sh5_media;

  class sh_cpu_cgen
    {
    public:
      sh_cpu_cgen () :
	fpu (dynamic_cast<cgen_bi_endian_cpu*>(this), new cgen_fp_ops)
      {}

      inline void cgen_rtx_error(const char* msg) const
	{
	  cerr << "sh-cpu rtx error: " << msg << endl;
	}

      // Floating point support
      cgen_fpu fpu;
#ifndef CGEN_CPU_FPU
#define CGEN_CPU_FPU(cpu) (&(cpu)->fpu)
#endif

    protected:
      virtual BI sh64_endian () const = 0;
    };

  class sh2_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh2-cpu.h"
    };

  class sh2e_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh2e-cpu.h"
    };

  class sh2a_fpu_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh2a-fpu-cpu.h"
    };

  class sh2a_nofpu_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh2a-nofpu-cpu.h"
    };

  class sh3_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh3-cpu.h"
    };

  class sh3e_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh3e-cpu.h"
    };

  class sh4_nofpu_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh4-nofpu-cpu.h"
    };

  class sh4_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh4-cpu.h"
    };

  class sh4a_nofpu_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh4a-nofpu-cpu.h"
    };

  class sh4a_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh4a-cpu.h"
    };

  class sh4al_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh4al-cpu.h"
    };

  class sh5_cpu_cgen : public sh_cpu_cgen
    {
      // Include cgen generated elements.
#include "sh5-cpu.h"
    };

  enum model_status { model_ok, model_get_insn, model_stalled };

  template<class CGEN_CPU>
  class sh_cpu: public CGEN_CPU, public cgen_bi_endian_cpu
    {
    private:
      //      void flush_icache (); -- not needed?
      
      // debug support routines
      string dbg_get_reg (host_int_4 n);
      component::status dbg_set_reg (host_int_4 n, const string& s);

      // ELF Header flag handling
      host_int_4 eflags;
      virtual void set_eflags(host_int_4);

    protected:
      host_int_4 elf_machine () const { return this->eflags & EF_SH_MACH_MASK; }
      int bfd_machine () const;
      bool mach_sh5_p () const { return elf_machine () == EF_SH5; }

    protected:
      virtual void reset ();

    protected:
      sid::signed_host_int_8 pending_latency;
      bool parallel_possible_p;

      virtual void write_stacks_reset () = 0;

    public:
      sh_cpu ();
      ~sh_cpu () throw() { };

      virtual host_int_4 insn_size (PCADDR pc) = 0;
      virtual void set_pc (host_int_4 v) { this->h_pc_set (v);	}
      virtual host_int_4 get_pc () { return this->h_pc_get ();}

      // syscall temporary registers
      USI syscall_trap_num;
      USI syscall_arg0;
      USI syscall_arg1;
      USI syscall_arg2;
      USI syscall_arg3;
      USI syscall_error;
      USI syscall_result;

      int parity (int);
      // void syscall (); -- not used?
      
      // Called by semantic code to perform branches.
      inline void
      branch (PCADDR new_pc, PCADDR& npc, sem_status& status)
	{
	  cgen_bi_endian_cpu::branch (new_pc, npc, status);
	  npc = new_pc;
	  status = SEM_STATUS_BRANCH_TAKEN;
	}

      // Called by the semantic code at the end of a non-cti insn.
      inline void
      done_insn (PCADDR npc, sem_status& status)
	{
	  this->h_pc_set (npc | this->h_ism_get ());
	}

      // Called by the semantic code at the end of a cti insn.
      inline void
      done_cti_insn (PCADDR npc, sem_status& status)
	{
	  cgen_bi_endian_cpu::done_cti_insn (npc, status);
	  if (status == SEM_STATUS_BRANCH_TAKEN)
	    this->h_pc_set (npc);
	  else
	    this->h_pc_set (npc | this->h_ism_get ());
	}

      void invalid_insn (PCADDR pc);
      void memory_trap (const cpu_memory_fault& t);
      virtual PCADDR fpu_exception (PCADDR pc, int &status) { status = 0; return pc; }

      BI
      sh64_endian () const
        {
	  return (current_endianness() == endian_big);
	}

      void sh64_break (PCADDR pc);

    public:
      // TODO: These should be placed at the proper level in the class heirarchy
      // Placed here now for convenience only.
      SF sh64_fldi0 ();
      SF sh64_fldi1 ();
      DF sh64_fabsd(DF drgh);
      SF sh64_fabss(SF frgh);
      DF sh64_faddd(DF drg, DF drh);
      SF sh64_fadds(SF frg, SF frh);
      BI sh64_fcmpeqd(DF drg, DF drh);
      BI sh64_fcmpeqs(SF frg, SF frh);
      BI sh64_fcmpged(DF drg, DF drh);
      BI sh64_fcmpges(SF frg, SF frh);
      BI sh64_fcmpgtd(DF drg, DF drh);
      BI sh64_fcmpgts(SF frg, SF frh);
      BI sh64_fcmpund(DF drg, DF drh);
      BI sh64_fcmpuns(SF frg, SF frh);
      SF sh64_fcnvds(DF drgh);
      DF sh64_fcnvsd(SF frgh);
      DF sh64_fdivd(DF drg, DF drh);
      SF sh64_fdivs(SF frg, SF frh);
      DF sh64_floatld(SF frgh);
      SF sh64_floatls(SF frgh);
      DF sh64_floatqd(DF drgh);
      SF sh64_floatqs(DF drgh);
      SF sh64_fmacs(SF fr0, SF frm, SF frn);
      DF sh64_fmuld(DF drg, DF drh);
      SF sh64_fmuls(SF frg, SF frh);
      DF sh64_fnegd(DF drgh);
      SF sh64_fnegs(SF frgh);
      DF sh64_fsqrtd(DF drgh);
      SF sh64_fsqrts(SF frgh);
      DF sh64_fsubd(DF drg, DF drh);
      SF sh64_fsubs(SF frg, SF frh);
      SF sh64_ftrcdl(DF drgh);
      SF sh64_ftrcsl(SF frgh);
      DF sh64_ftrcdq(DF drgh);
      DF sh64_ftrcsq(SF frgh);
      void sh64_ftrvs(unsigned g, unsigned h, unsigned f);
      SI sh64_movua (PCADDR pc, SI rn);

      // sh3 and up
      output_pin cache_prefetch_pin;
      void sh64_pref (DI addr);
    };

  // TODO: could be folded into sh_cpu
  template <class CGEN_CPU>
  class sh_cpu_impl: public sh_cpu<CGEN_CPU>
    {
    public:
      ~sh_cpu_impl() throw() { }
      PCADDR get_fetched_insn_pc () { return this->fetched_insn_pc; }

    protected:
      PCADDR fetched_insn_pc;
    };

} // namespace sh

#endif // SH_H
