/* CPU class elements for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

// This file is included in the middle of the cpu class struct.

public:

// CPU state information.

  // Hardware elements.
  struct {
  /* program counter */
  USI h_pc;
  /* General purpose registers */
  SI h_gpr[16];
  /* Control/special registers */
  SI h_csr[32];
  /* 64-bit coprocessor registers */
  DI h_cr64[32];
  /* Coprocessor control registers */
  SI h_ccr[64];
  /* flag */
  USI h_fmax_compare_i_p;
  } hardware;

  void stream_cgen_hardware (std::ostream &ost) const 
  {
    ost << hardware.h_pc << ' ';
    for (int i = 0; i < 16; i++)
      ost << hardware.h_gpr[i] << ' ';
    for (int i = 0; i < 32; i++)
      ost << hardware.h_csr[i] << ' ';
    for (int i = 0; i < 32; i++)
      ost << hardware.h_cr64[i] << ' ';
    for (int i = 0; i < 64; i++)
      ost << hardware.h_ccr[i] << ' ';
    ost << hardware.h_fmax_compare_i_p << ' ';
  }
  void destream_cgen_hardware (std::istream &ist) 
  {
    ist >> hardware.h_pc;
    for (int i = 0; i < 16; i++)
      ist >> hardware.h_gpr[i];
    for (int i = 0; i < 32; i++)
      ist >> hardware.h_csr[i];
    for (int i = 0; i < 32; i++)
      ist >> hardware.h_cr64[i];
    for (int i = 0; i < 64; i++)
      ist >> hardware.h_ccr[i];
    ist >> hardware.h_fmax_compare_i_p;
  }
  // C++ register access function templates
#define current_cpu this

  inline USI h_pc_get () const { return this->hardware.h_pc; }
  inline void h_pc_set (USI newval) { this->hardware.h_pc = newval; }

  inline SI h_gpr_get (UINT regno) const { return this->hardware.h_gpr[regno]; }
  inline void h_gpr_set (UINT regno, SI newval) { this->hardware.h_gpr[regno] = newval; }

  inline SI h_csr_get (UINT regno) const { return current_cpu->cgen_get_csr_value (regno); }
  inline void h_csr_set (UINT regno, SI newval) { current_cpu->cgen_set_csr_value (regno, newval);
 }

  inline DI h_cr64_get (UINT regno) const { return this->hardware.h_cr64[regno]; }
  inline void h_cr64_set (UINT regno, DI newval) { this->hardware.h_cr64[regno] = newval; }

  inline SI h_cr_get (UINT regno) const { return TRUNCDISI (current_cpu->h_cr64_get (regno)); }
  inline void h_cr_set (UINT regno, SI newval) { current_cpu->h_cr64_set (regno, EXTSIDI (newval));
 }

  inline SI h_ccr_get (UINT regno) const { return this->hardware.h_ccr[regno]; }
  inline void h_ccr_set (UINT regno, SI newval) { current_cpu->cgen_set_ccr_value (regno, newval);
 }

  inline SF ext_core2_h_cr_fmax_get (UINT regno) const { return current_cpu->fmax_fr_get_handler (regno); }
  inline void ext_core2_h_cr_fmax_set (UINT regno, SF newval) { current_cpu->fmax_fr_set_handler (regno, newval);
 }

  inline USI ext_core2_h_ccr_fmax_get (UINT regno) const { return current_cpu->h_ccr_get (regno); }
  inline void ext_core2_h_ccr_fmax_set (UINT regno, USI newval) { current_cpu->h_ccr_set (regno, newval);
 }

  inline USI ext_core2_h_fmax_compare_i_p_get () const { return this->hardware.h_fmax_compare_i_p; }
  inline void ext_core2_h_fmax_compare_i_p_set (USI newval) { this->hardware.h_fmax_compare_i_p = newval; }

#undef current_cpu

