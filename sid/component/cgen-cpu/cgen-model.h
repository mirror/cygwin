// cgen-model.h  -*- C++ -*-

// Copyright (C) 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_MODEL_H
#define CGEN_MODEL_H

#include "cgen-cpu.h"

namespace cgen
{

class cgen_model
{
public:
  cgen_model (cgen_bi_endian_cpu *c) : cpu (c) {}

  // To be overridden as needed. Call before each insn is executed. first_p is
  // true when the insn is the first of a group of parallel insns.
  virtual void model_insn_before (bool first_p = true) {}

  // To be overridden as needed. Call after each insn is executed. last_p is
  // true when the insn is the first of a group of parallel insns. cycles is the
  // number of cycles used by each particular insn.
  virtual void model_insn_after (bool last_p = true, sid::host_int_4 cycles = 1)
    {
      if (last_p && cycles > 0)
	cpu->update_total_latency (cycles - 1);
    }

protected:
  cgen_bi_endian_cpu *cpu;
};

} // namespace cgen

#endif /* CGEN_MODEL_H */
