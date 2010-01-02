/* CPU class elements for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

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
  /* 64-bit coprocessor registers, pending writes */
  DI h_cr64_w[32];
  /* Coprocessor control registers */
  SI h_ccr[64];
  /* Coprocessor control registers, pending writes */
  SI h_ccr_w[64];
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
    for (int i = 0; i < 32; i++)
      ost << hardware.h_cr64_w[i] << ' ';
    for (int i = 0; i < 64; i++)
      ost << hardware.h_ccr[i] << ' ';
    for (int i = 0; i < 64; i++)
      ost << hardware.h_ccr_w[i] << ' ';
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
    for (int i = 0; i < 32; i++)
      ist >> hardware.h_cr64_w[i];
    for (int i = 0; i < 64; i++)
      ist >> hardware.h_ccr[i];
    for (int i = 0; i < 64; i++)
      ist >> hardware.h_ccr_w[i];
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
  inline void h_cr64_set (UINT regno, DI newval) { current_cpu->h_cr64_queue_set (regno, newval);
 }

  inline DI h_cr64_w_get (UINT regno) const { return this->hardware.h_cr64_w[regno]; }
  inline void h_cr64_w_set (UINT regno, DI newval) { this->hardware.h_cr64_w[regno] = newval; }

  inline SI h_cr_get (UINT regno) const { return TRUNCDISI (current_cpu->h_cr64_get (regno)); }
  inline void h_cr_set (UINT regno, SI newval) { current_cpu->h_cr64_set (regno, EXTSIDI (newval));
 }

  inline SI h_ccr_get (UINT regno) const { return this->hardware.h_ccr[regno]; }
  inline void h_ccr_set (UINT regno, SI newval) { current_cpu->h_ccr_queue_set (regno, newval);
 }

  inline SI h_ccr_w_get (UINT regno) const { return this->hardware.h_ccr_w[regno]; }
  inline void h_ccr_w_set (UINT regno, SI newval) { this->hardware.h_ccr_w[regno] = newval; }

  inline DI h_cr_ivc2_get (UINT regno) const { return current_cpu->h_cr64_get (regno); }
  inline void h_cr_ivc2_set (UINT regno, DI newval) { current_cpu->h_cr64_set (regno, newval);
 }

  inline SI h_ccr_ivc2_get (UINT regno) const { return current_cpu->h_ccr_get (regno); }
  inline void h_ccr_ivc2_set (UINT regno, SI newval) { current_cpu->h_ccr_set (regno, newval);
 }

#undef current_cpu

