// sh2a.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH2A_H
#define SH2A_H

#include "sh_vliw.h"

namespace sh_compact
{
  using namespace sh;
  using sid::host_int_8;
  using sid::host_int_4;

  template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
  class sh2a_cpu_base: public sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>
    {
    public:
      sh2a_cpu_base (CPU *cpu);
      ~sh2a_cpu_base () throw() {}

    private:
      bool is_32_bit_insn (USI base_insn);

    protected:
      virtual void fetch_insn (PCADDR pc, USI &base_insn, USI &entire_insn);
      virtual bool parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles);

    };
};

#endif // SH2A_H
