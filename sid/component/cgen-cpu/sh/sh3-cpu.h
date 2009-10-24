/* CPU class elements for sh3.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

// This file is included in the middle of the cpu class struct.

public:

// CPU state information.

  // Hardware elements.
  struct {
  /* Program counter */
  UDI h_pc;
  /* General purpose integer registers */
  DI h_gr[64];
  /* Status register */
  SI h_sr;
  /* Floating point status and control register */
  SI h_fpscr;
  /* Single precision floating point registers */
  SF h_fr[64];
  /* Current instruction set mode */
  BI h_ism;
  } hardware;

  void stream_cgen_hardware (std::ostream &ost) const 
  {
    ost << hardware.h_pc << ' ';
    for (int i = 0; i < 64; i++)
      ost << hardware.h_gr[i] << ' ';
    ost << hardware.h_sr << ' ';
    ost << hardware.h_fpscr << ' ';
    for (int i = 0; i < 64; i++)
      ost << hardware.h_fr[i] << ' ';
    ost << hardware.h_ism << ' ';
  }
  void destream_cgen_hardware (std::istream &ist) 
  {
    ist >> hardware.h_pc;
    for (int i = 0; i < 64; i++)
      ist >> hardware.h_gr[i];
    ist >> hardware.h_sr;
    ist >> hardware.h_fpscr;
    for (int i = 0; i < 64; i++)
      ist >> hardware.h_fr[i];
    ist >> hardware.h_ism;
  }
  template <typename ST> 
  void stream_stacks (const ST &st, std::ostream &ost) const
  {
    for (int i = 0; i < sh3::pipe_sz; i++)
    {
      ost << st[i].t << ' ';
      for (int j = 0; j <= st[i].t; j++)
      {
        ost << st[i].buf[j].pc << ' ';
        ost << st[i].buf[j].val << ' ';
        ost << st[i].buf[j].idx0 << ' ';
      }
    }
  }
  
  template <typename ST> 
  void destream_stacks (ST &st, std::istream &ist)
  {
    for (int i = 0; i < sh3::pipe_sz; i++)
    {
      ist >> st[i].t;
      for (int j = 0; j <= st[i].t; j++)
      {
        ist >> st[i].buf[j].pc;
        ist >> st[i].buf[j].val;
        ist >> st[i].buf[j].idx0;
      }
    }
  }
  
  void stream_cgen_write_stacks (std::ostream &ost, const sh3::write_stacks &stacks) const 
  {
    stream_stacks ( stacks.h_pc_writes, ost);
    stream_stacks ( stacks.h_pr_writes, ost);
  }
  void destream_cgen_write_stacks (std::istream &ist, sh3::write_stacks &stacks) 
  {
    destream_stacks ( stacks.h_pc_writes, ist);
    destream_stacks ( stacks.h_pr_writes, ist);
  }
  // C++ register access function templates
#define current_cpu this

  inline UDI h_pc_get () const { return current_cpu->hardware.h_pc; }
  inline void h_pc_set (UDI newval) { {
current_cpu->hardware.h_ism = ANDDI (newval, 1);
current_cpu->hardware.h_pc = ANDDI (newval, INVDI (1));
}
 }

  inline DI h_gr_get (UINT regno) const { return ((((regno) == (63))) ? (MAKEDI (0, 0)) : (current_cpu->hardware.h_gr[regno])); }
  inline void h_gr_set (UINT regno, DI newval) { if (((regno) != (63))) {
current_cpu->hardware.h_gr[regno] = newval;
} else {
((void) 0); /*nop*/
}
 }

  inline SI h_grc_get (UINT regno) const { return ANDDI (current_cpu->hardware.h_gr[regno], ZEXTSIDI (0xffffffff)); }
  inline void h_grc_set (UINT regno, SI newval) { current_cpu->hardware.h_gr[regno] = EXTSIDI (newval);
 }

  inline SI h_sr_get () const { return this->hardware.h_sr; }
  inline void h_sr_set (SI newval) { this->hardware.h_sr = newval; }

  inline SI h_fpscr_get () const { return this->hardware.h_fpscr; }
  inline void h_fpscr_set (SI newval) { this->hardware.h_fpscr = newval; }

  inline BI h_frbit_get () const { return ANDSI (SRLSI (current_cpu->hardware.h_fpscr, 21), 1); }
  inline void h_frbit_set (BI newval) { current_cpu->hardware.h_fpscr = ORSI (ANDSI (current_cpu->hardware.h_fpscr, (~ (((1) << (21))))), SLLSI (newval, 21));
 }

  inline BI h_szbit_get () const { return ANDSI (SRLSI (current_cpu->hardware.h_fpscr, 20), 1); }
  inline void h_szbit_set (BI newval) { current_cpu->hardware.h_fpscr = ORSI (ANDSI (current_cpu->hardware.h_fpscr, (~ (((1) << (20))))), SLLSI (newval, 20));
 }

  inline BI h_prbit_get () const { return ANDSI (SRLSI (current_cpu->hardware.h_fpscr, 19), 1); }
  inline void h_prbit_set (BI newval) { current_cpu->hardware.h_fpscr = ORSI (ANDSI (current_cpu->hardware.h_fpscr, (~ (((1) << (19))))), SLLSI (newval, 19));
 }

  inline BI h_sbit_get () const { return ANDSI (SRLSI (current_cpu->hardware.h_sr, 1), 1); }
  inline void h_sbit_set (BI newval) { current_cpu->hardware.h_sr = ORSI (ANDSI (current_cpu->hardware.h_sr, (~ (2))), SLLSI (newval, 1));
 }

  inline BI h_mbit_get () const { return ANDSI (SRLSI (current_cpu->hardware.h_sr, 9), 1); }
  inline void h_mbit_set (BI newval) { current_cpu->hardware.h_sr = ORSI (ANDSI (current_cpu->hardware.h_sr, (~ (((1) << (9))))), SLLSI (newval, 9));
 }

  inline BI h_qbit_get () const { return ANDSI (SRLSI (current_cpu->hardware.h_sr, 8), 1); }
  inline void h_qbit_set (BI newval) { current_cpu->hardware.h_sr = ORSI (ANDSI (current_cpu->hardware.h_sr, (~ (((1) << (8))))), SLLSI (newval, 8));
 }

  inline SF h_fr_get (UINT regno) const { return this->hardware.h_fr[regno]; }
  inline void h_fr_set (UINT regno, SF newval) { this->hardware.h_fr[regno] = newval; }

  inline SF h_fp_get (UINT regno) const { return current_cpu->hardware.h_fr[regno]; }
  inline void h_fp_set (UINT regno, SF newval) { current_cpu->hardware.h_fr[regno] = newval;
 }

  inline SF h_fv_get (UINT regno) const { return current_cpu->hardware.h_fr[regno]; }
  inline void h_fv_set (UINT regno, SF newval) { current_cpu->hardware.h_fr[regno] = newval;
 }

  inline DF h_dr_get (UINT regno) const { return SUBWORDDIDF (ORDI (SLLDI (ZEXTSIDI (SUBWORDSFSI (current_cpu->hardware.h_fr[regno])), 32), ZEXTSIDI (SUBWORDSFSI (current_cpu->hardware.h_fr[((regno) + (1))])))); }
  inline void h_dr_set (UINT regno, DF newval) { {
current_cpu->hardware.h_fr[regno] = SUBWORDSISF (SUBWORDDFSI (newval, 0));
current_cpu->hardware.h_fr[((regno) + (1))] = SUBWORDSISF (SUBWORDDFSI (newval, 1));
}
 }

  inline BI h_endian_get () const { return current_cpu->sh64_endian (); }
  inline void h_endian_set (BI newval) { current_cpu->cgen_rtx_error ("cannot alter target byte order mid-program");
 }

  inline BI h_ism_get () const { return current_cpu->hardware.h_ism; }
  inline void h_ism_set (BI newval) { current_cpu->cgen_rtx_error ("cannot set ism directly");
 }

  inline SF h_frc_get (UINT regno) const { return current_cpu->hardware.h_fr[((((16) * (current_cpu->h_frbit_get ()))) + (regno))]; }
  inline void h_frc_set (UINT regno, SF newval) { current_cpu->hardware.h_fr[((((16) * (current_cpu->h_frbit_get ()))) + (regno))] = newval;
 }

  inline DF h_drc_get (UINT regno) const { return current_cpu->h_dr_get (((((16) * (current_cpu->h_frbit_get ()))) + (regno))); }
  inline void h_drc_set (UINT regno, DF newval) { current_cpu->h_dr_set (((((16) * (current_cpu->h_frbit_get ()))) + (regno)), newval);
 }

  inline SF h_xf_get (UINT regno) const { return current_cpu->hardware.h_fr[((((16) * (NOTBI (current_cpu->h_frbit_get ())))) + (regno))]; }
  inline void h_xf_set (UINT regno, SF newval) { current_cpu->hardware.h_fr[((((16) * (NOTBI (current_cpu->h_frbit_get ())))) + (regno))] = newval;
 }

  inline DF h_xd_get (UINT regno) const { return current_cpu->h_dr_get (((((16) * (NOTBI (current_cpu->h_frbit_get ())))) + (regno))); }
  inline void h_xd_set (UINT regno, DF newval) { current_cpu->h_dr_set (((((16) * (NOTBI (current_cpu->h_frbit_get ())))) + (regno)), newval);
 }

  inline SF h_fvc_get (UINT regno) const { return current_cpu->hardware.h_fr[((((16) * (current_cpu->h_frbit_get ()))) + (regno))]; }
  inline void h_fvc_set (UINT regno, SF newval) { current_cpu->hardware.h_fr[((((16) * (current_cpu->h_frbit_get ()))) + (regno))] = newval;
 }

  inline SI h_gbr_get () const { return SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 16)], 1); }
  inline void h_gbr_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 16)] = EXTSIDI (newval);
 }

  inline SI h_vbr_get () const { return SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 20)], 1); }
  inline void h_vbr_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 20)] = EXTSIDI (newval);
 }

  inline SI h_pr_get () const { return SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 18)], 1); }
  inline void h_pr_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 18)] = EXTSIDI (newval);
 }

  inline SI h_macl_get () const { return SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 17)], 1); }
  inline void h_macl_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 17)] = ORDI (SLLDI (ZEXTSIDI (SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 17)], 0)), 32), ZEXTSIDI (newval));
 }

  inline SI h_mach_get () const { return SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 17)], 0); }
  inline void h_mach_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 17)] = ORDI (SLLDI (ZEXTSIDI (newval), 32), ZEXTSIDI (SUBWORDDISI (current_cpu->hardware.h_gr[((UINT) 17)], 1)));
 }

  inline BI h_tbit_get () const { return ANDBI (current_cpu->hardware.h_gr[((UINT) 19)], 1); }
  inline void h_tbit_set (BI newval) { current_cpu->hardware.h_gr[((UINT) 19)] = ORDI (ANDDI (current_cpu->hardware.h_gr[((UINT) 19)], INVDI (1)), ZEXTBIDI (newval));
 }

#undef current_cpu

