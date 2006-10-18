// sh2a_nofpu.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH2A_NOFPU_H
#define SH2A_NOFPU_H

#include "sh2a.h"
#include "sh2a_model.h"

namespace sh2a_nofpu
{
  using namespace sh;
  using namespace sh_compact;

#define SH2A_NOFPU_BASE sh2a_cpu_base<sh2a_nofpu_cpu,sh2a_nofpu_cpu_cgen,sh2a_nofpu_idesc,sh2a_nofpu_scache, \
                                      sh2a_model<sh_common_model_with_vliw< \
                                        sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>, \
                                        sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>, \
                                      sh2a_nofpu_cpu,sh2a_nofpu_idesc> >

  class sh2a_nofpu_cpu: public SH2A_NOFPU_BASE
    {
    public:
      sh2a_nofpu_cpu () :
	SH2A_NOFPU_BASE (this),
	tick (0)
        {}
      ~sh2a_nofpu_cpu () throw() {}

    protected:
      virtual void reset();
      virtual void execute_insn (sh2a_nofpu_scache *sc);

      // pipeline modelling
      virtual void write_stacks_reset () { write_stacks.reset (); tick = 0; }
      virtual void write_stacks_writeback () { write_stacks.writeback (tick, this); }
      virtual void update_tick () { tick = (tick + 1) % sh2a_nofpu::pipe_sz; } // move ahead thru circular pipeline

      sh2a_nofpu::write_stacks write_stacks;
      int tick;
    };
}

#endif // SH2A_NOFPU_H
