// sh3.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH3_H
#define SH3_H

#include "sh_compact.h"
#include "sh3_model.h"

namespace sh3
{
  using namespace sh;
  using namespace sh_compact;

  class sh3_cpu: public sh_compact_cpu<sh3_cpu,sh3_cpu_cgen,sh3_idesc,sh3_scache,
		                       sh3_model<sh_common_model<sh3_sh3_model,sh3_cpu,sh3_idesc,sh3_scache>,sh3_cpu,sh3_idesc> >
    {
    public:
      sh3_cpu () :
	sh_compact_cpu<sh3_cpu,sh3_cpu_cgen,sh3_idesc,sh3_scache,
                       sh3_model<sh_common_model<sh3_sh3_model,sh3_cpu,sh3_idesc,sh3_scache>,sh3_cpu,sh3_idesc> > (this),
	tick (0)
        {}
      ~sh3_cpu () throw() {}

    protected:
      virtual void execute_insn ();

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh3::pipe_sz; } // move ahead thru circular pipeline

      sh3::write_stacks write_stacks;
      int tick;
    };
}
#endif // SH3_H
