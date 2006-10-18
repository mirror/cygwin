// sh_compact.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH_COMPACT_H
#define SH_COMPACT_H

#include "sh.h"
#include "common_model.h"

#include <vector>

namespace sh_compact
{
  using namespace sh;

  template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
  class sh_compact_cpu: public sh_cpu_impl<CGEN_CPU>
    {
    public:
      sh_compact_cpu (CPU *);
      ~sh_compact_cpu () throw() { }

      /* virtual */ void flush_icache ()
        {
	  this->engine.flush ();
	}
      /* virtual */ void flush_icache (host_int_4 pc)
        {
	  this->engine.zap (pc);
	}

    private:
      virtual void step_insns ();
      sem_status step_one_insn (PCADDR pc);

    protected:
      // Insn modelling
      //      virtual void model_insn_before () { model.step_latency (); }

      //      virtual void model_step_latency (sid::host_int_4 cycles = 0) { model.step_latency (cycles); }

      //      virtual UINT model_before (SCACHE *sc)
      //{
      //  UINT stall = model.model_before (thisp, sc);
      //  return stall;
      //}

      //      virtual UINT model_after (SCACHE *sc) {return model.model_after (thisp, sc); }

      //virtual model_status model_insn_after (UINT cycles, PCADDR &pc)
      //        {
      //	  model.step_cycles (cycles);
      //	  return model_ok;
      //	}

      vector<sid::host_int_4> return_addresses;
      bool find_return_address (sid::host_int_4 addr);
      sid::host_int_4 return_address (sid::host_int_4 caller) { return caller + this->insn_size (caller); }

    public:
      virtual void model_branch_taken (bool taken) { }

      virtual host_int_4 insn_size (PCADDR) { return 2; }

      virtual void cg_profile (sid::host_int_4 caller, sid::host_int_4 callee);
      virtual void notify_ret (sid::host_int_4 addr);

    protected:
      virtual void reset();
      virtual void write_stacks_writeback () = 0;
      virtual void update_tick () = 0;

      virtual void fetch_insn (PCADDR pc, USI &base_insn, USI &entire_insn);
      virtual void decode_insn (PCADDR pc);
      virtual void disassemble (PCADDR pc);
      virtual void execute_insn () = 0;

    public:
      void sh64_compact_trapa (UQI trapnum, PCADDR pc);
      void save_delayed_pc (PCADDR pc) { delayed_pc = pc; }

    protected:
      PCADDR delayed_pc;
      SCACHE *fetched_insn;
      MODEL model;
      CPU* thisp;   // pointer to subclass instance

    private:
      scache_engine<SCACHE> engine;
      unsigned dcix;
      unsigned drix;
    };
}

#endif // SH_COMPACT_H
