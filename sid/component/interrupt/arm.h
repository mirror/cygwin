// arm.h - Class declaration for the ARM reference interrupt
// controller.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef INTERRUPT_ARM_H
#define INTERRUPT_ARM_H

#if SIDTARGET_ARM

class armIntController: public IntController<little_int_4>
{
 public:
  armIntController():
    IntController<little_int_4>(32, 1, (RSTPIN|FIQREGS|FIQBUS)) { }
  ~armIntController() throw () { }
  
 private:
  // required virtual methods
  sid::bus::status irq_read_word(host_int_4 addr, little_int_4 mask,
				 little_int_4& data);
  sid::bus::status irq_write_word(host_int_4 addr, little_int_4 mask,
				  little_int_4 data);
  void irq_src_driven(host_int_4 driven_val, host_int_4 bit_num);

  // override (empty) virtual methods
  sid::bus::status fiq_read_word(host_int_4 addr, little_int_4 mask,
				 little_int_4& data);
  sid::bus::status fiq_write_word(host_int_4 addr, little_int_4 mask,
				  little_int_4 data);
  void fiq_src_driven(host_int_4 driven_val, host_int_4 bit_num);
};

#endif // SIGTARGET_ARM 

#endif // INTERRUPT_ARM_H
