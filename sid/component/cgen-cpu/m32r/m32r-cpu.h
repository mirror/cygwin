/* CPU class elements for m32rbf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

// This file is included in the middle of the cpu class struct.

public:

// CPU state information.

  // Hardware elements.
  struct {
  /* program counter */
  USI h_pc;
  /* general registers */
  SI h_gr[16];
  /* control registers */
  USI h_cr[16];
  /* accumulator */
  DI h_accum;
  /* condition bit */
  BI h_cond;
  /* psw part of psw */
  UQI h_psw;
  /* backup psw */
  UQI h_bpsw;
  /* backup bpsw */
  UQI h_bbpsw;
  /* lock */
  BI h_lock;
  } hardware;

  void stream_cgen_hardware (std::ostream &ost) const 
  {
    ost << hardware.h_pc << ' ';
    for (int i = 0; i < 16; i++)
      ost << hardware.h_gr[i] << ' ';
    for (int i = 0; i < 16; i++)
      ost << hardware.h_cr[i] << ' ';
    ost << hardware.h_accum << ' ';
    ost << hardware.h_cond << ' ';
    ost << hardware.h_psw << ' ';
    ost << hardware.h_bpsw << ' ';
    ost << hardware.h_bbpsw << ' ';
    ost << hardware.h_lock << ' ';
  }
  void destream_cgen_hardware (std::istream &ist) 
  {
    ist >> hardware.h_pc;
    for (int i = 0; i < 16; i++)
      ist >> hardware.h_gr[i];
    for (int i = 0; i < 16; i++)
      ist >> hardware.h_cr[i];
    ist >> hardware.h_accum;
    ist >> hardware.h_cond;
    ist >> hardware.h_psw;
    ist >> hardware.h_bpsw;
    ist >> hardware.h_bbpsw;
    ist >> hardware.h_lock;
  }
  // C++ register access function templates
#define current_cpu this

  inline USI h_pc_get () const { return this->hardware.h_pc; }
  inline void h_pc_set (USI newval) { this->hardware.h_pc = newval; }

  inline SI h_gr_get (UINT regno) const { return this->hardware.h_gr[regno]; }
  inline void h_gr_set (UINT regno, SI newval) { this->hardware.h_gr[regno] = newval; }

  inline USI h_cr_get (UINT regno) const { return current_cpu->m32rbf_h_cr_get_handler (regno); }
  inline void h_cr_set (UINT regno, USI newval) { current_cpu->m32rbf_h_cr_set_handler (regno, newval);
 }

  inline DI h_accum_get () const { return current_cpu->m32rbf_h_accum_get_handler (); }
  inline void h_accum_set (DI newval) { current_cpu->m32rbf_h_accum_set_handler (newval);
 }

  inline BI h_cond_get () const { return this->hardware.h_cond; }
  inline void h_cond_set (BI newval) { this->hardware.h_cond = newval; }

  inline UQI h_psw_get () const { return current_cpu->m32rbf_h_psw_get_handler (); }
  inline void h_psw_set (UQI newval) { current_cpu->m32rbf_h_psw_set_handler (newval);
 }

  inline UQI h_bpsw_get () const { return this->hardware.h_bpsw; }
  inline void h_bpsw_set (UQI newval) { this->hardware.h_bpsw = newval; }

  inline UQI h_bbpsw_get () const { return this->hardware.h_bbpsw; }
  inline void h_bbpsw_set (UQI newval) { this->hardware.h_bbpsw = newval; }

  inline BI h_lock_get () const { return this->hardware.h_lock; }
  inline void h_lock_set (BI newval) { this->hardware.h_lock = newval; }

#undef current_cpu

