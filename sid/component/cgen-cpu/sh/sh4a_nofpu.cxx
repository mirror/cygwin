// sh4a_nofpu.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh4a_nofpu.h"

using namespace sh4a_nofpu;

void
sh4a_nofpu_cpu::execute_insn (sh4a_nofpu_scache *sc)
{
  sc->idesc->execute (this, sc, tick, write_stacks);
}
