// sh2.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH2_H
#define SH2_H

#include "sh_compact.h"

namespace sh2
{
  using namespace sh;
  using namespace sh_compact;

  class sh2_cpu: public sh_compact_cpu<sh2_cpu,sh2_cpu_cgen,sh2_idesc,sh2_scache,sh_common_model<sh2_sh2_model,sh2_cpu,sh2_idesc,sh2_scache> >
    {
    public:
      sh2_cpu () :
	sh_compact_cpu<sh2_cpu,sh2_cpu_cgen,sh2_idesc,sh2_scache,sh_common_model<sh2_sh2_model,sh2_cpu,sh2_idesc,sh2_scache> > (this),
	tick (0)
        {}
      ~sh2_cpu () throw() {}

    protected:
      virtual void execute_insn ();

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh2::pipe_sz; } // move ahead thru circular pipeline

      sh2::write_stacks write_stacks;
      int tick;
    };
}
#endif // SH2_H
