// sh4a.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh4a.h"
#include "sh4al.h"

using namespace sh4a;

void
sh4a_cpu::execute_insn (sh4a_scache *sc)
{
  sc->idesc->execute (this, sc, tick, write_stacks);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
bool
sh4a_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles)
{
  // Not if they don't have the same post-fetch latency.
  if (insn1->get_post_fetch_latency () != insn2->get_post_fetch_latency ())
    return false;

  // Not if insn1 is a delay slot insn
  if (insn1->in_delay_slot ())
    return false;

  // Check the table here. It's the same as for sh4.
  return this->parallel_allowed [insn1->sh4a_group ()][insn2->sh4a_group ()];
}

// Explicit instantiations
template class sh4a_cpu_base<sh4a_cpu,sh4a_cpu_cgen,sh4a_idesc,sh4a_scache,sh4a_fpu_model<sh4a_cpu,sh4a_idesc> >;
template class sh4a_cpu_base<sh4a_nofpu_cpu,sh4a_nofpu_cpu_cgen,sh4a_nofpu_idesc,sh4a_nofpu_scache,
			     sh4a_model<sh2a_model<sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>,
						   sh4a_nofpu_cpu,sh4a_nofpu_idesc>,
					sh4a_nofpu_cpu,sh4a_nofpu_idesc> >;
template class sh4a_cpu_base<sh4al_cpu,sh4al_cpu_cgen,sh4al_idesc,sh4al_scache,sh4al_model>;
