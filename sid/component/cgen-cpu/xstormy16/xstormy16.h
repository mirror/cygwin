// xstormy16.h - Hand-written code for the Sanyo Xstormy16 CPU. -*- C++ -*-

// Copyright (C) 1999, 2000, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cgen-cpu.h"
#include "xstormy16-desc.h"
#include "xstormy16-defs.h"
#include "xstormy16-decode.h"

namespace xstormy16
{
  class xstormy16_cpu_cgen: public cgen_bi_endian_cpu
    {
      // Include cgen generated elements.
#include "xstormy16-cpu.h"

    public:
      xstormy16_cpu_cgen () {}
      ~xstormy16_cpu_cgen () throw() { };

    protected:
      // Log any changes to the pc, if we're reversible.
      void h_pc_set_handler (USI newval)
        {
	  if (UNLIKELY (this->reversible_p))
	    log_pc_change (newval);
	  this->hardware.h_pc = newval;
        }

      // Log any changes to the gr registers, if we're reversible.
      void h_gr_set_handler (UINT regno, SI newval)
        {
	  if (UNLIKELY (this->reversible_p))
	    log_gr_change (regno, newval);
	  this->hardware.h_gr[regno] = (0xffff & newval);
        }

      // Stateful (reversible) component implementation methods.
      virtual void init_change_logging ();
      virtual void finish_change_logging ();

      void log_pc_change (USI new_pc);
      void log_gr_change (UINT regno, SI newval);

      virtual void restore_change (const char *data, sid::host_int_4 length);

    protected:
      inline void cgen_rtx_error(const char* msg) const
	{
	  cerr << "xstormy16-cpu rtx error: " << msg << endl;
	}

    protected:
      USI syscall_trap_num;

      // The values of these constants are significant and must not be changed.
      static const sid::signed_host_int_1 PC_UNCHANGED = 0x00;
      static const sid::signed_host_int_1 PC_RESET = 0x01;

      // State for change logging.
      sid::host_int_2 gr_changed;
      sid::signed_host_int_1 pc_changed;
      SI old_h_gr[16];
      USI old_h_pc;
    };

  class xstormy16_cpu: public xstormy16_cpu_cgen
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
