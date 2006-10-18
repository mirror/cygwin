// sh3e.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH3E_H
#define SH3E_H

#include "sh_compact.h"
#include "sh3_model.h"

namespace sh3e
{
  using namespace sh;
  using namespace sh_compact;

  class sh3e_cpu: public sh_compact_cpu<sh3e_cpu,sh3e_cpu_cgen,sh3e_idesc,sh3e_scache,
		                        sh3e_model<sh_common_model_with_fp<sh3e_sh3e_model,sh3e_cpu,sh3e_idesc,sh3e_scache>,
		                                   sh3e_cpu,sh3e_idesc> >
    {
    public:
      sh3e_cpu () :
	sh_compact_cpu<sh3e_cpu,sh3e_cpu_cgen,sh3e_idesc,sh3e_scache,
		       sh3e_model<sh_common_model_with_fp<sh3e_sh3e_model,sh3e_cpu,sh3e_idesc,sh3e_scache>,
				  sh3e_cpu,sh3e_idesc> > (this),
	tick (0)
        {}
      ~sh3e_cpu () throw() {}

    protected:
      virtual void execute_insn ();

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh3e::pipe_sz; } // move ahead thru circular pipeline

      sh3e::write_stacks write_stacks;
      int tick;
    };
}
#endif // SH3E_H
