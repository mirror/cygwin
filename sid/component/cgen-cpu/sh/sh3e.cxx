// sh3e.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh3e.h"

using namespace sh3e;

void
sh3e_cpu::execute_insn ()
{
  fetched_insn->idesc->execute (this, fetched_insn, tick, write_stacks);
}
