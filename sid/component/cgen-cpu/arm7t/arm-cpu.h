/* CPU class elements for arm.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

// This file is included in the middle of the cpu class struct.

public:

// CPU state information.

  // Hardware elements.
  struct {
  /* ARM program counter (h-gr reg 15) */
  USI h_pc;
  /* General purpose registers */
  SI h_gr[16];
  /* user/system mode r8-r14 holding buffer */
  SI h_gr_usr[7];
  /* fiq mode r8-r14 regs */
  SI h_gr_fiq[7];
  /* supervisor mode r13-r14 regs */
  SI h_gr_svc[2];
  /* abort mode r13-r14 regs */
  SI h_gr_abt[2];
  /* irq mode r13-r14 regs */
  SI h_gr_irq[2];
  /* undefined mode r13-r14 regs */
  SI h_gr_und[2];
  /* carry bit */
  BI h_cbit;
  /* negative bit */
  BI h_nbit;
  /* overflow bit */
  BI h_vbit;
  /* zerobit */
  BI h_zbit;
  /* irq disable bit */
  BI h_ibit;
  /* fiq disable bit */
  BI h_fbit;
  /* thumb bit */
  BI h_tbit;
  /* m4,m3,m2,m1,m0 */
  UINT h_mbits;
  /* Saved Process Status Register during FIQ */
  SI h_spsr_fiq;
  /* Saved Process Status Register during SVC */
  SI h_spsr_svc;
  /* Saved Process Status Register during Abort */
  SI h_spsr_abt;
  /* Saved Process Status Register during IRQ */
  SI h_spsr_irq;
  /* Saved Process Status Register during Undefined */
  SI h_spsr_und;
  } hardware;

  void stream_cgen_hardware (std::ostream &ost) const 
  {
    ost << hardware.h_pc << ' ';
    for (int i = 0; i < 16; i++)
      ost << hardware.h_gr[i] << ' ';
    for (int i = 0; i < 7; i++)
      ost << hardware.h_gr_usr[i] << ' ';
    for (int i = 0; i < 7; i++)
      ost << hardware.h_gr_fiq[i] << ' ';
    for (int i = 0; i < 2; i++)
      ost << hardware.h_gr_svc[i] << ' ';
    for (int i = 0; i < 2; i++)
      ost << hardware.h_gr_abt[i] << ' ';
    for (int i = 0; i < 2; i++)
      ost << hardware.h_gr_irq[i] << ' ';
    for (int i = 0; i < 2; i++)
      ost << hardware.h_gr_und[i] << ' ';
    ost << hardware.h_cbit << ' ';
    ost << hardware.h_nbit << ' ';
    ost << hardware.h_vbit << ' ';
    ost << hardware.h_zbit << ' ';
    ost << hardware.h_ibit << ' ';
    ost << hardware.h_fbit << ' ';
    ost << hardware.h_tbit << ' ';
    ost << hardware.h_mbits << ' ';
    ost << hardware.h_spsr_fiq << ' ';
    ost << hardware.h_spsr_svc << ' ';
    ost << hardware.h_spsr_abt << ' ';
    ost << hardware.h_spsr_irq << ' ';
    ost << hardware.h_spsr_und << ' ';
  }
  void destream_cgen_hardware (std::istream &ist) 
  {
    ist >> hardware.h_pc;
    for (int i = 0; i < 16; i++)
      ist >> hardware.h_gr[i];
    for (int i = 0; i < 7; i++)
      ist >> hardware.h_gr_usr[i];
    for (int i = 0; i < 7; i++)
      ist >> hardware.h_gr_fiq[i];
    for (int i = 0; i < 2; i++)
      ist >> hardware.h_gr_svc[i];
    for (int i = 0; i < 2; i++)
      ist >> hardware.h_gr_abt[i];
    for (int i = 0; i < 2; i++)
      ist >> hardware.h_gr_irq[i];
    for (int i = 0; i < 2; i++)
      ist >> hardware.h_gr_und[i];
    ist >> hardware.h_cbit;
    ist >> hardware.h_nbit;
    ist >> hardware.h_vbit;
    ist >> hardware.h_zbit;
    ist >> hardware.h_ibit;
    ist >> hardware.h_fbit;
    ist >> hardware.h_tbit;
    ist >> hardware.h_mbits;
    ist >> hardware.h_spsr_fiq;
    ist >> hardware.h_spsr_svc;
    ist >> hardware.h_spsr_abt;
    ist >> hardware.h_spsr_irq;
    ist >> hardware.h_spsr_und;
  }
  // C++ register access function templates
#define current_cpu this

  inline USI h_pc_get () const { return this->hardware.h_pc; }
  inline void h_pc_set (USI newval) { if (current_cpu->hardware.h_tbit) {
current_cpu->hardware.h_pc = ANDSI (newval, -2);
} else {
current_cpu->hardware.h_pc = ANDSI (newval, -4);
}
 }

  inline SI h_gr_get (UINT regno) const { return this->hardware.h_gr[regno]; }
  inline void h_gr_set (UINT regno, SI newval) { this->hardware.h_gr[regno] = newval; }

  inline SI h_gr_usr_get (UINT regno) const { return this->hardware.h_gr_usr[regno]; }
  inline void h_gr_usr_set (UINT regno, SI newval) { this->hardware.h_gr_usr[regno] = newval; }

  inline SI h_gr_fiq_get (UINT regno) const { return this->hardware.h_gr_fiq[regno]; }
  inline void h_gr_fiq_set (UINT regno, SI newval) { this->hardware.h_gr_fiq[regno] = newval; }

  inline SI h_gr_svc_get (UINT regno) const { return this->hardware.h_gr_svc[regno]; }
  inline void h_gr_svc_set (UINT regno, SI newval) { this->hardware.h_gr_svc[regno] = newval; }

  inline SI h_gr_abt_get (UINT regno) const { return this->hardware.h_gr_abt[regno]; }
  inline void h_gr_abt_set (UINT regno, SI newval) { this->hardware.h_gr_abt[regno] = newval; }

  inline SI h_gr_irq_get (UINT regno) const { return this->hardware.h_gr_irq[regno]; }
  inline void h_gr_irq_set (UINT regno, SI newval) { this->hardware.h_gr_irq[regno] = newval; }

  inline SI h_gr_und_get (UINT regno) const { return this->hardware.h_gr_und[regno]; }
  inline void h_gr_und_set (UINT regno, SI newval) { this->hardware.h_gr_und[regno] = newval; }

  inline BI h_cbit_get () const { return this->hardware.h_cbit; }
  inline void h_cbit_set (BI newval) { this->hardware.h_cbit = newval; }

  inline BI h_nbit_get () const { return this->hardware.h_nbit; }
  inline void h_nbit_set (BI newval) { this->hardware.h_nbit = newval; }

  inline BI h_vbit_get () const { return this->hardware.h_vbit; }
  inline void h_vbit_set (BI newval) { this->hardware.h_vbit = newval; }

  inline BI h_zbit_get () const { return this->hardware.h_zbit; }
  inline void h_zbit_set (BI newval) { this->hardware.h_zbit = newval; }

  inline BI h_ibit_get () const { return this->hardware.h_ibit; }
  inline void h_ibit_set (BI newval) { this->hardware.h_ibit = newval; }

  inline BI h_fbit_get () const { return this->hardware.h_fbit; }
  inline void h_fbit_set (BI newval) { this->hardware.h_fbit = newval; }

  inline BI h_tbit_get () const { return this->hardware.h_tbit; }
  inline void h_tbit_set (BI newval) { {
current_cpu->arm_tbit_set (newval);
}
 }

  inline UINT h_mbits_get () const { return this->hardware.h_mbits; }
  inline void h_mbits_set (UINT newval) { {
  switch (newval)
  {
  case ARM_MODE_USER :   case ARM_MODE_FIQ :   case ARM_MODE_IRQ :   case ARM_MODE_SUPERVISOR :   case ARM_MODE_ABORT :   case ARM_MODE_UNDEFINED :   case ARM_MODE_SYSTEM : {
((void) 0); /*nop*/
}
    break;
  default : {
current_cpu->cgen_rtx_error ("bad value for M4-M0");
}
    break;
  }
current_cpu->arm_mbits_set (newval);
}
 }

  inline SI h_cpsr_get () const { return ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_nbit), 31), ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_zbit), 30), ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_cbit), 29), ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_vbit), 28), ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_ibit), 7), ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_fbit), 6), ORSI (SLLSI (ZEXTBISI (current_cpu->hardware.h_tbit), 5), current_cpu->hardware.h_mbits))))))); }
  inline void h_cpsr_set (SI newval) { {
current_cpu->hardware.h_nbit = NESI (ANDSI (newval, 0x80000000), 0);
current_cpu->hardware.h_zbit = NESI (ANDSI (newval, 1073741824), 0);
current_cpu->hardware.h_cbit = NESI (ANDSI (newval, 536870912), 0);
current_cpu->hardware.h_vbit = NESI (ANDSI (newval, 268435456), 0);
current_cpu->hardware.h_ibit = NESI (ANDSI (newval, 128), 0);
current_cpu->hardware.h_fbit = NESI (ANDSI (newval, 64), 0);
current_cpu->h_tbit_set (NESI (ANDSI (newval, 32), 0));
current_cpu->h_mbits_set (ANDSI (newval, 31));
}
 }

  inline SI h_spsr_fiq_get () const { return this->hardware.h_spsr_fiq; }
  inline void h_spsr_fiq_set (SI newval) { this->hardware.h_spsr_fiq = newval; }

  inline SI h_spsr_svc_get () const { return this->hardware.h_spsr_svc; }
  inline void h_spsr_svc_set (SI newval) { this->hardware.h_spsr_svc = newval; }

  inline SI h_spsr_abt_get () const { return this->hardware.h_spsr_abt; }
  inline void h_spsr_abt_set (SI newval) { this->hardware.h_spsr_abt = newval; }

  inline SI h_spsr_irq_get () const { return this->hardware.h_spsr_irq; }
  inline void h_spsr_irq_set (SI newval) { this->hardware.h_spsr_irq = newval; }

  inline SI h_spsr_und_get () const { return this->hardware.h_spsr_und; }
  inline void h_spsr_und_set (SI newval) { this->hardware.h_spsr_und = newval; }

  inline SI h_spsr_get () const { return (current_cpu->hardware.h_mbits == ARM_MODE_USER) ? ((current_cpu->cgen_rtx_error ("can't read spsr in user mode"), 0)) : (current_cpu->hardware.h_mbits == ARM_MODE_FIQ) ? (current_cpu->hardware.h_spsr_fiq) : (current_cpu->hardware.h_mbits == ARM_MODE_IRQ) ? (current_cpu->hardware.h_spsr_irq) : (current_cpu->hardware.h_mbits == ARM_MODE_SUPERVISOR) ? (current_cpu->hardware.h_spsr_svc) : (current_cpu->hardware.h_mbits == ARM_MODE_ABORT) ? (current_cpu->hardware.h_spsr_abt) : (current_cpu->hardware.h_mbits == ARM_MODE_UNDEFINED) ? (current_cpu->hardware.h_spsr_und) : (current_cpu->hardware.h_mbits == ARM_MODE_SYSTEM) ? ((current_cpu->cgen_rtx_error ("can't read spsr in system mode"), 0)) : ((current_cpu->cgen_rtx_error ("can't read spsr, invalid mode"), 0)); }
  inline void h_spsr_set (SI newval) {   switch (current_cpu->hardware.h_mbits)
  {
  case ARM_MODE_USER : {
current_cpu->cgen_rtx_error ("can't set spsr in user mode");
}
    break;
  case ARM_MODE_FIQ : {
current_cpu->hardware.h_spsr_fiq = newval;
}
    break;
  case ARM_MODE_IRQ : {
current_cpu->hardware.h_spsr_irq = newval;
}
    break;
  case ARM_MODE_SUPERVISOR : {
current_cpu->hardware.h_spsr_svc = newval;
}
    break;
  case ARM_MODE_ABORT : {
current_cpu->hardware.h_spsr_abt = newval;
}
    break;
  case ARM_MODE_UNDEFINED : {
current_cpu->hardware.h_spsr_und = newval;
}
    break;
  case ARM_MODE_SYSTEM : {
current_cpu->cgen_rtx_error ("can't set spsr in system mode");
}
    break;
  default : {
current_cpu->cgen_rtx_error ("can't set spsr, invalid mode");
}
    break;
  }
 }

  inline SI thumb_h_gr_t_get (UINT regno) const { return current_cpu->hardware.h_gr[regno]; }
  inline void thumb_h_gr_t_set (UINT regno, SI newval) { current_cpu->hardware.h_gr[regno] = newval;
 }

  inline SI thumb_h_lr_t_get () const { return current_cpu->hardware.h_gr[((UINT) 14)]; }
  inline void thumb_h_lr_t_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 14)] = newval;
 }

  inline SI thumb_h_sp_t_get () const { return current_cpu->hardware.h_gr[((UINT) 13)]; }
  inline void thumb_h_sp_t_set (SI newval) { current_cpu->hardware.h_gr[((UINT) 13)] = newval;
 }

  inline SI thumb_h_hiregs_get (UINT regno) const { return current_cpu->hardware.h_gr[((regno) + (8))]; }
  inline void thumb_h_hiregs_set (UINT regno, SI newval) { current_cpu->hardware.h_gr[((regno) + (8))] = newval;
 }

#undef current_cpu

