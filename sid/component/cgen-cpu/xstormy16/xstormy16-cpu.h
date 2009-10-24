/* CPU class elements for xstormy16.

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
  /* registers */
  SI h_gr[16];
  } hardware;

  void stream_cgen_hardware (std::ostream &ost) const 
  {
    ost << hardware.h_pc << ' ';
    for (int i = 0; i < 16; i++)
      ost << hardware.h_gr[i] << ' ';
  }
  void destream_cgen_hardware (std::istream &ist) 
  {
    ist >> hardware.h_pc;
    for (int i = 0; i < 16; i++)
      ist >> hardware.h_gr[i];
  }
  // C++ register access function templates
#define current_cpu this

  inline USI h_pc_get () const { return this->hardware.h_pc; }
  inline void h_pc_set (USI newval) { current_cpu->h_pc_set_handler (newval);
 }

  inline SI h_gr_get (UINT regno) const { return ((65535) & (current_cpu->hardware.h_gr[regno])); }
  inline void h_gr_set (UINT regno, SI newval) { current_cpu->h_gr_set_handler (regno, newval);
 }

  inline SI h_Rb_get (UINT regno) const { return current_cpu->h_gr_get (((regno) + (8))); }
  inline void h_Rb_set (UINT regno, SI newval) { current_cpu->h_gr_set (((regno) + (8)), newval);
 }

  inline SI h_Rbj_get (UINT regno) const { return current_cpu->h_gr_get (((regno) + (8))); }
  inline void h_Rbj_set (UINT regno, SI newval) { current_cpu->h_gr_set (((regno) + (8)), newval);
 }

  inline SI h_Rpsw_get () const { return ((15) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 12))); }
  inline void h_Rpsw_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), 4095), SLLHI (newval, 12)));
 }

  inline SI h_z8_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 0))); }
  inline void h_z8_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 0))), SLLHI (newval, 0)));
 }

  inline SI h_z16_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 1))); }
  inline void h_z16_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 1))), SLLHI (newval, 1)));
 }

  inline SI h_cy_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 2))); }
  inline void h_cy_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 2))), SLLHI (newval, 2)));
 }

  inline SI h_hc_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 3))); }
  inline void h_hc_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 3))), SLLHI (newval, 3)));
 }

  inline SI h_ov_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 4))); }
  inline void h_ov_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 4))), SLLHI (newval, 4)));
 }

  inline SI h_pt_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 5))); }
  inline void h_pt_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 5))), SLLHI (newval, 5)));
 }

  inline SI h_s_get () const { return ((1) & (SRLSI (current_cpu->h_gr_get (((UINT) 14)), 6))); }
  inline void h_s_set (SI newval) { current_cpu->h_gr_set (((UINT) 14), ORSI (ANDSI (current_cpu->h_gr_get (((UINT) 14)), INVHI (SLLHI (1, 6))), SLLHI (newval, 6)));
 }

#undef current_cpu

