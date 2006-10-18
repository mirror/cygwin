// sh2a_fpu.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh2a_fpu.h"

using namespace sh2a_fpu;
void
sh2a_fpu_cpu::reset()
{
  SH2A_FPU_BASE::reset ();
  this->h_fpscr_set (0x00040001);
}

void
sh2a_fpu_cpu::execute_insn (sh2a_fpu_scache *sc)
{
  sc->idesc->execute (this, sc, tick, write_stacks);
}
