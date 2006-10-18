// sh5.h - Hand-written code for the Renesas Sh5 CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH5_H
#define SH5_H

#include "sh4.h"
#include "sh5_model.h"

namespace sh5
{
  using namespace sh;
  using namespace sh_compact;
  using namespace sh4;

#define SH5_CPU_BASE sh4_cpu_base<sh5_cpu,sh5_cpu_cgen,sh5_compact_idesc,sh5_compact_scache, \
                                  sh_common_model_with_fp<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache> >

#define SH5_CPU_NON_VLIW_BASE sh_compact_cpu<sh5_cpu,sh5_cpu_cgen,sh5_compact_idesc,sh5_compact_scache, \
                                             sh_common_model_with_fp<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache> >

  class sh5_cpu: public SH5_CPU_BASE
    {
    public:
      sh5_cpu ();
      ~sh5_cpu () throw() { };

      /* virtual */ void flush_icache ()
        {
	  SH5_CPU_BASE::flush_icache ();
	  this->engine.flush ();
	}
      /* virtual */ void flush_icache (host_int_4 pc)
        {
	  SH5_CPU_BASE::flush_icache (pc);
	  this->engine.zap (pc);
	}

      virtual void cg_profile_jump (sid::host_int_4 caller, sid::host_int_4 callee);

      virtual host_int_4 insn_size (PCADDR pc)
        {
	  return fetched_insn_is_compact ? SH5_CPU_BASE::insn_size (pc) : 4;
	}

    public:
      SF sh64_fiprs (unsigned g, unsigned h);
      void sh64_fldp (PCADDR pc, DI rm, DI rn, unsigned fpf);
      void sh64_fstp (PCADDR pc, DI rm, DI rn, unsigned fpf);

      void sh64_save_cfg_address (UINT address) { cfg_address = address; }
      UINT sh64_get_cfg_address () const { return cfg_address; }

      void save_branch_prediction (INT reg, UINT likely) { branch_prediction[reg] = likely; }
      UINT get_branch_prediction (INT reg) const { return branch_prediction[reg]; }

      void save_branch_optimization (UINT likely) { branch_optimization = likely; }
      UINT get_branch_optimization () const { return branch_optimization; }

      void prefetch (PCADDR target);

    protected:
      bool compact_p () { return h_ism_get () == 0; }
      bool compact_insn_pending () { return this->vliw_insns.size () != 0; }

      virtual void fetch_insn (PCADDR pc, USI &base_insn, USI &entire_insn);
      virtual void decode_insn (PCADDR pc);
      virtual void execute_insn ();
      virtual void execute_insn (sh5_compact_scache *sc);
      virtual void disassemble (PCADDR pc);
      virtual void trace_counter (PCADDR pc);

      virtual void write_stacks_reset ()
        {
	  this->compact_write_stacks.reset ();
	  this->media_write_stacks.reset ();
	  this->compact_tick = 0;
	  this->media_tick = 0;
	}
      virtual void write_stacks_writeback ()
        {
	  this->compact_write_stacks.writeback (this->compact_tick, this);
	  this->media_write_stacks.writeback (this->media_tick, this);
	}
      virtual void update_tick ()
        {
	  this->compact_tick = (this->compact_tick + 1) % sh5_compact::pipe_sz;
	  this->media_tick = (this->media_tick + 1) % sh5_media::pipe_sz;
	} // move ahead thru circular pipeline

    protected:
      // Insn modelling
      virtual void model_insn_before ();
      virtual void model_step_latency (sid::host_int_4 cycles = 0);
      virtual UINT model_before (sh5_compact_scache *sc);
      virtual UINT model_after (sh5_compact_scache *sc);
      virtual model_status model_insn_after (UINT cycles, PCADDR &pc);

    public:
      DI sh64_nsb (DI rm);
      void sh64_trapa (DI rm, PCADDR pc);

    private:
      // pipeline modelling
      sh5_compact::write_stacks compact_write_stacks;
      sh5_media::write_stacks media_write_stacks;
      int compact_tick;
      int media_tick;

      string get_pc_attribute () { return make_attribute (this->h_pc_get () & 0xffffffff); }
      string get_pc_hi_attribute () { return make_attribute ((this->h_pc_get () >> 32) & 0xffffffff); }
      virtual sid::host_int_4 get_pc_hi() { return (this->h_pc_get () >> 32) & 0xffffffff; }

      component::status set_pc_attribute (const string &attr)
        {
	  UDI pc;
	  component::status stat = parse_attribute(attr, pc);
	  if (stat != component::ok)
	    return stat;
	  this->h_pc_set ((this->h_pc_get () & ~(UDI)0xffffffff) | (pc & 0xffffffff));
	  return component::ok;
	}

      component::status set_pc_hi_attribute (const string &attr)
        {
	  UDI pc;
	  component::status stat = parse_attribute(attr, pc);
	  if (stat != component::ok)
	    return stat;
	  this->h_pc_set ((this->h_pc_get () & (UDI)0xffffffff) | ((pc & 0xffffffff) << 32));
	  return component::ok;
	}

      sh5_media_scache *fetched_insn;
      bool fetched_insn_is_compact;
      scache_engine<sh5_media_scache> engine;
      sh5_media_model model;
      UINT cfg_address;
      UINT branch_prediction[8];
      UINT branch_optimization;
    };

  class sh5_compact_cpu: public sh5_cpu
    {
    public:
      sh5_compact_cpu () : sh5_cpu () {}
      ~sh5_compact_cpu () throw() {}
    };

  class sh5_32media_cpu: public sh5_cpu
    {
    public:
      sh5_32media_cpu () : sh5_cpu () {}
      ~sh5_32media_cpu () throw() {}
    };

  class sh5_64media_cpu: public sh5_cpu
    {
    public:
      sh5_64media_cpu () : sh5_cpu () {}
      ~sh5_64media_cpu () throw() {}
    };
}
#endif // SH5_H
