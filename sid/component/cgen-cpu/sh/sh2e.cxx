// sh2e.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh2e.h"

using namespace sh2e;

void
sh2e_cpu::reset()
{
  sh_compact_cpu<sh2e_cpu,sh2e_cpu_cgen,sh2e_idesc,sh2e_scache,sh_common_model_with_fp<sh2e_sh2e_model,sh2e_cpu,sh2e_idesc,sh2e_scache> >::reset ();
  this->h_fpscr_set (0x00040001);
}

void
sh2e_cpu::execute_insn ()
{
  fetched_insn->idesc->execute (this, fetched_insn, tick, write_stacks);
}
