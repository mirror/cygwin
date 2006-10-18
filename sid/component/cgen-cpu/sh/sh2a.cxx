// sh2a.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh2a.h"
#include "sh2a_model.h"

using namespace sh;

using sid::host_int_4;
using sid::host_int_8;

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
sh2a_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::sh2a_cpu_base (CPU *cpu) :
  sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL> (cpu)
{
  for (int i = 0; i < 64; ++i)
    {
      this->h_fr_set (i, 0);
      this->h_gr_set (i, 0);
    }
  for (int i = 0; i < 32; ++i)
    {
      this->h_fp_set (i, 0);
    }
  this->h_sr_set (0);
  this->hardware.h_ism = 0; // Must be set directly
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
inline bool
sh2a_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::is_32_bit_insn (USI base_insn)
{
  USI opcode = base_insn & 0xf00f0000;
  return (opcode == 0x30010000 || opcode == 0x00000000);
}

// --------------------------------------------------------------------------------
// Remaining methods.
//
template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh2a_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::fetch_insn (PCADDR pc, USI &base_insn, USI &entire_insn)
{
  // 16 or 32 bit insns. Beware unaligned reads.
  base_insn = this->GETIMEMHI (pc, pc) << 16;
  if (is_32_bit_insn (base_insn))
    base_insn |= this->GETIMEMHI (pc, pc + 2) & 0xffff;
  entire_insn = base_insn;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
bool
sh2a_cpu_base<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles)
{
  // Not if the first insn is 32 bits
  if (insn1->is_32_bit_insn ())
    return false;

  // Not if they don't have the same post-fetch latency.
  if (insn1->get_post_fetch_latency () != insn2->get_post_fetch_latency ())
    return false;

  // Not if the first insn uses more than one cycle.
  if (cycles != 1)
    return false;

  // Ask the model as well.
  if (! this->model.parallel_possible (insn1->get_insn ()->idesc, insn2->get_insn ()->idesc))
    return false;

  return true;
}

// Explicit instantiations
template class sh2a_cpu_base<sh2a_fpu_cpu,sh2a_fpu_cpu_cgen,sh2a_fpu_idesc,sh2a_fpu_scache,
			     sh2a_fpu_model<
                               sh_common_model_with_vliw<
                                 sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
                                 sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
                               sh2a_fpu_cpu,sh2a_fpu_idesc>
                              >;
template class sh2a_cpu_base<sh2a_nofpu_cpu,sh2a_nofpu_cpu_cgen,sh2a_nofpu_idesc,sh2a_nofpu_scache,
			     sh2a_model<
                               sh_common_model_with_vliw<
                                 sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
                                 sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
                               sh2a_nofpu_cpu,sh2a_nofpu_idesc>
                              >;
