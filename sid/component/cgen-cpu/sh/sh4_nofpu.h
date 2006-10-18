// sh4_nofpu.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH4_NOFPU_H
#define SH4_NOFPU_H

#include "sh4.h"

namespace sh4_nofpu
{
  using namespace sh;
  using namespace sh4;

  class sh4_nofpu_cpu: public sh4_cpu_base<sh4_nofpu_cpu,sh4_nofpu_cpu_cgen,sh4_nofpu_idesc,sh4_nofpu_scache,
		                           sh4_model<sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,
		                                                sh4_nofpu_cpu,sh4_nofpu_idesc>,
			                             sh4_nofpu_cpu,sh4_nofpu_idesc> >
    {
    public:
      sh4_nofpu_cpu () :
	sh4_cpu_base<sh4_nofpu_cpu,sh4_nofpu_cpu_cgen,sh4_nofpu_idesc,sh4_nofpu_scache,
		     sh4_model<sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,
					  sh4_nofpu_cpu,sh4_nofpu_idesc>,
			       sh4_nofpu_cpu,sh4_nofpu_idesc> > (this),
	tick (0)
        {}
      ~sh4_nofpu_cpu () throw() {}

    protected:
      virtual void execute_insn (sh4_nofpu_scache *sc);

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh4_nofpu::pipe_sz; } // move ahead thru circular pipeline

      sh4_nofpu::write_stacks write_stacks;
      int tick;
    };
}
#endif // SH4_NOFPU_H
