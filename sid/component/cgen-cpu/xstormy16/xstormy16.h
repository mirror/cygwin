// xstormy16.h - Hand-written code for the Sanyo Xstormy16 CPU. -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cgen-cpu.h"
#include "xstormy16-desc.h"
#include "xstormy16-defs.h"
#include "xstormy16-decode.h"

namespace xstormy16
{
  class xstormy16_cpu_cgen
    {
      // Include cgen generated elements.
#include "xstormy16-cpu.h"

    public:
      inline void cgen_rtx_error(const char* msg) const
	{
	  cerr << "xstormy16-cpu rtx error: " << msg << endl;
	}
    protected:
      USI syscall_trap_num;

    };

  class xstormy16_cpu: public xstormy16_cpu_cgen, public cgen_bi_endian_cpu
    {
    private:
      scache_engine<xstormy16_scache> engine;

      void step_insns ();
      void flush_icache ();
      void reset ();
      
      // debug support routines
      string dbg_get_reg (host_int_4 n);
      component::status dbg_set_reg (host_int_4 n, const string& s);

    public:
      xstormy16_cpu ();
      ~xstormy16_cpu () throw() { };

      void set_pc (host_int_4 v) 
	{ 
	  this->hardware.h_pc = (PCADDR) v; 
	}

      host_int_4 get_pc ()
        {
	  return this->hardware.h_pc;
	}

      // syscall temporary registers
      USI syscall_arg0;
      USI syscall_arg1;
      USI syscall_arg2;
      USI syscall_arg3;
      USI syscall_error;
      USI syscall_result;

      int parity (int);
      void syscall ();
      void do_brk ();
      void do_halt ();
      void do_hold ();
      void do_holdx ();
      
      // Called by semantic code to perform branches.
      inline void
      branch (PCADDR new_pc, PCADDR& npc, sem_status& status)
	{
	  npc = new_pc;
	}

      // Called by the semantic code at the end of a non-cti insn.
      inline void
      done_insn (PCADDR npc, sem_status& status)
	{
	  this->h_pc_set (npc);
	}

      // Called by the semantic code at the end of a cti insn.
      inline void
      done_cti_insn (PCADDR npc, sem_status& status)
	{
	  this->h_pc_set (npc);
	}

      void invalid_insn (PCADDR pc);
      void memory_trap (const cpu_memory_fault& t);

    };

} // namespace xstormy16
