// sh4al.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH4AL_H
#define SH4AL_H

#include "sh4a.h"
#include "sh4al_model.h"

namespace sh4al
{
  using namespace sh;
  using namespace sh4;

  class sh4al_cpu: public sh4a_cpu_base<sh4al_cpu,sh4al_cpu_cgen,sh4al_idesc,sh4al_scache,sh4al_model>
    {
    public:
      sh4al_cpu () :
	sh4a_cpu_base<sh4al_cpu,sh4al_cpu_cgen,sh4al_idesc,sh4al_scache,sh4al_model> (this),
	tick (0)
      {}
      ~sh4al_cpu () throw() {}

    protected:
      virtual void execute_insn (sh4al_scache *sc);

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh4al::pipe_sz; } // move ahead thru circular pipeline

      //      virtual bool parallel_possible (insn_info<sh4al_scache> *insn1, insn_info<sh4al_scache> *insn2, UINT cycles);

      sh4al::write_stacks write_stacks;
      int tick;
    };
}
#endif // SH4AL_H
