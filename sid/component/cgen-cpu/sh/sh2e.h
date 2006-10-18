// sh2e.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH2E_H
#define SH2E_H

#include "sh_compact.h"

namespace sh2e
{
  using namespace sh;
  using namespace sh_compact;

  class sh2e_cpu: public sh_compact_cpu<sh2e_cpu,sh2e_cpu_cgen,sh2e_idesc,sh2e_scache,sh_common_model_with_fp<sh2e_sh2e_model,sh2e_cpu,sh2e_idesc,sh2e_scache> >
    {
    public:
      sh2e_cpu () :
	sh_compact_cpu<sh2e_cpu,sh2e_cpu_cgen,sh2e_idesc,sh2e_scache,sh_common_model_with_fp<sh2e_sh2e_model,sh2e_cpu,sh2e_idesc,sh2e_scache> > (this),
	tick (0)
        {}
      ~sh2e_cpu () throw() {}

    protected:
      virtual void reset();
      virtual void execute_insn ();

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh2e::pipe_sz; } // move ahead thru circular pipeline

      sh2e::write_stacks write_stacks;
      int tick;
    };
}
#endif // SH2E_H
