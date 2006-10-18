// sh4.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH4_H
#define SH4_H

#include "sh_vliw.h"
#include "sh4_model.h"

namespace sh4
{
  using namespace sh;

  template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
  class sh4_cpu_base: public sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>
    {
    public:
      sh4_cpu_base (CPU *cpu) : sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL> (cpu) {}
      ~sh4_cpu_base () throw() {}

    public:
      void sh64_fipr (unsigned m, unsigned n);
      void sh64_ftrv (unsigned n);

    protected:
      virtual bool parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles);

    protected:
      static bool parallel_allowed [SH4_GROUP_MAX][SH4_GROUP_MAX];
    };

  class sh4_cpu: public sh4_cpu_base<sh4_cpu,sh4_cpu_cgen,sh4_idesc,sh4_scache,sh4_fpu_model<sh4_cpu,sh4_idesc> >
    {
    public:
      sh4_cpu (bool single_only = false) :
	sh4_cpu_base<sh4_cpu,sh4_cpu_cgen,sh4_idesc,sh4_scache,sh4_fpu_model<sh4_cpu,sh4_idesc> > (this),
	tick (0),
	single_only_p (single_only)
        {}
      ~sh4_cpu () throw() {}

    protected:
      virtual void execute_insn (sh4_scache *sc);

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh4::pipe_sz; } // move ahead thru circular pipeline

      sh4::write_stacks write_stacks;
      int tick;
      bool single_only_p;
    };

  class sh4_single_cpu: public sh4_cpu
    {
    public:
      sh4_single_cpu () :
	sh4_cpu (true)
      {}
      ~sh4_single_cpu () throw() {}
    };
}
#endif // SH4_H
