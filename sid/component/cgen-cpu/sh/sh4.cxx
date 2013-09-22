// sh4.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh4.h"
#include "sh4a.h"
#include "sh4al.h"

using namespace sh4a;

void
sh4_cpu::execute_insn (sh4_scache *sc)
{
  sc->idesc->execute (this, sc, tick, write_stacks);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh4_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::sh64_fipr (unsigned m, unsigned n)
{
  SF result = this->sh64_fmuls (this->h_fvc_get (m), this->h_fvc_get (n));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_frc_get (m + 1), this->h_frc_get (n + 1)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_frc_get (m + 2), this->h_frc_get (n + 2)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_frc_get (m + 3), this->h_frc_get (n + 3)));
  this->h_frc_set (n + 3, result);
}
 
template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh4_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::sh64_ftrv (unsigned n)
{
  SF result = this->sh64_fmuls (this->h_xf_get (0), this->h_frc_get (n));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (4),  this->h_frc_get (n + 1)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (8),  this->h_frc_get (n + 2)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (12), this->h_frc_get (n + 3)));
  this->h_frc_set (n, result);
  result = this->sh64_fmuls (this->h_xf_get (1), this->h_frc_get (n));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (5),  this->h_frc_get (n + 1)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (9),  this->h_frc_get (n + 2)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (13), this->h_frc_get (n + 3)));
  this->h_frc_set (n + 1, result);
  result = this->sh64_fmuls (this->h_xf_get (2), this->h_frc_get (n));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (6),  this->h_frc_get (n + 1)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (10), this->h_frc_get (n + 2)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (14), this->h_frc_get (n + 3)));
  this->h_frc_set (n + 2, result);
  result = this->sh64_fmuls (this->h_xf_get (3), this->h_frc_get (n));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (7),  this->h_frc_get (n + 1)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (11), this->h_frc_get (n + 2)));
  result = this->sh64_fadds (result, this->sh64_fmuls (this->h_xf_get (15), this->h_frc_get (n + 3)));
  this->h_frc_set (n + 3, result);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
bool
sh4_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::parallel_allowed [SH4_GROUP_MAX][SH4_GROUP_MAX] =
{           /* none   MT     EX     BR     LS     FE     CO */
  /* none */ { false, false, false, false, false, false, false },
  /* MT   */ { false, true,  true,  true,  true,  true,  false },
  /* EX   */ { false, true,  false, true,  true,  true,  false },
  /* BR   */ { false, true,  true,  false, true,  true,  false },
  /* LS   */ { false, true,  true,  true,  false, true,  false },
  /* FE   */ { false, true,  true,  true,  true,  false, false },
  /* CO   */ { false, false, false, false, false, false, false },
};

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
bool
sh4_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles)
{
  // Not if they don't have the same post-fetch latency.
  if (insn1->get_post_fetch_latency () != insn2->get_post_fetch_latency ())
    return false;

  // Check table here....
  return parallel_allowed [insn1->sh4_group ()][insn2->sh4_group ()];
}

// Explicit instantiations
template class sh4_cpu_base<sh4_cpu,sh4_cpu_cgen,sh4_idesc,sh4_scache,sh4_fpu_model<sh4_cpu,sh4_idesc> >;
template class sh4_cpu_base<sh4_nofpu_cpu,sh4_nofpu_cpu_cgen,sh4_nofpu_idesc,sh4_nofpu_scache,
			    sh4_model<sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,
						 sh4_nofpu_cpu,sh4_nofpu_idesc>,
				      sh4_nofpu_cpu,sh4_nofpu_idesc> >;
template class sh4_cpu_base<sh4a_cpu,sh4a_cpu_cgen,sh4a_idesc,sh4a_scache,sh4a_fpu_model<sh4a_cpu,sh4a_idesc> >;
template class sh4_cpu_base<sh4a_nofpu_cpu,sh4a_nofpu_cpu_cgen,sh4a_nofpu_idesc,sh4a_nofpu_scache,
			    sh4a_model<sh2a_model<sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>,
						  sh4a_nofpu_cpu,sh4a_nofpu_idesc>,
				       sh4a_nofpu_cpu,sh4a_nofpu_idesc> >;
template class sh4_cpu_base<sh4al_cpu,sh4al_cpu_cgen,sh4al_idesc,sh4al_scache,sh4al_model>;
template class sh4_cpu_base<sh5_cpu,sh5_cpu_cgen,sh5_compact_idesc,sh5_compact_scache,sh_common_model_with_fp<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache> >;
