// sh4a.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH4A_H
#define SH4A_H

#include "sh4.h"
#include "sh4a_model.h"

namespace sh4a
{
  using namespace sh;
  using namespace sh4;

  template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
  class sh4a_cpu_base: public sh4_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>
    {
    public:
      sh4a_cpu_base (CPU *cpu) : sh4_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL> (cpu) {}
      ~sh4a_cpu_base () throw() {}

    protected:
      virtual bool parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles);
    };

  class sh4a_cpu: public sh4a_cpu_base<sh4a_cpu,sh4a_cpu_cgen,sh4a_idesc,sh4a_scache,sh4a_fpu_model<sh4a_cpu,sh4a_idesc> >
    {
    public:
      sh4a_cpu (bool single_only = false) :
	sh4a_cpu_base<sh4a_cpu,sh4a_cpu_cgen,sh4a_idesc,sh4a_scache,sh4a_fpu_model<sh4a_cpu,sh4a_idesc> > (this),
	tick (0),
	single_only_p (single_only)
        {}
      ~sh4a_cpu () throw() {}

    protected:
      virtual void execute_insn (sh4a_scache *sc);

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh4a::pipe_sz; } // move ahead thru circular pipeline

      sh4a::write_stacks write_stacks;
      int tick;
      bool single_only_p;
    };

  class sh4a_single_cpu: public sh4a_cpu
    {
    public:
      sh4a_single_cpu () :
	sh4a_cpu (true)
      {}
      ~sh4a_single_cpu () throw() {}
    };
}
#endif // SH4A_H
