// cgen-model.h  -*- C++ -*-

// Copyright (C) 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_MODEL_H
#define CGEN_MODEL_H

#include <sidtypes.h>
#include "cgen-cpu.h"

namespace cgen
{

class cgen_model
{
public:
  cgen_model (cgen_bi_endian_cpu *c) : cpu (c) {}

  // To be overridden as needed. Call before each insn is executed. first_p is
  // true when the insn is the first of a group of parallel insns.
  virtual void model_insn_before (bool first_p = true)
  {
    if (first_p)
      {
	// There may be latency from insn fetch.
	step_latency ();
	this->vliw_cycles = 1;
      }
  }

  // To be overridden as needed. Call after each insn is executed. last_p is
  // true when the insn is the first of a group of parallel insns. cycles is the
  // number of cycles used by each particular insn.
  virtual void model_insn_after (bool last_p = true, sid::host_int_4 cycles = 1)
    {
      // Accumulate the max cycles used by any one vliw insn.
      if (cycles > this->vliw_cycles)
	this->vliw_cycles = cycles;

      // Account for the latency of this group of insns.
      if (last_p)
	step_cycles (vliw_cycles);
    }

  // To be overridden as needed. Update any state associated with an
  // insn using the given number of cycles.
  virtual void step_cycles (sid::host_int_4 cycles)
  {
    if (cycles > 0)
      {
	// The cpu counts cycles as number of insns + total latency.
	cpu->update_total_latency (cycles - 1);
	step_latency (1);
    }
  }

  // To be overridden as needed. Update any state associated with an
  // insn having latency. Insn latency is tracked using the cpu's
  // get_total_latency () method.
  virtual void step_latency (sid::host_int_4 = 0) {}

protected:
  cgen_bi_endian_cpu *cpu;
  sid::host_int_4 vliw_cycles;
};

} // namespace cgen

#endif /* CGEN_MODEL_H */
