// cma222.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef INTERRUPT_CMA222_H
#define INTERRUPT_CMA222_H

#if SIDTARGET_ARM

class cma222IntController: public IntController<little_int_1>
{
public:
  cma222IntController():
    IntController<little_int_1>(8, 0, 0) { }
  cma222IntController::~cma222IntController() throw () { }

private:

  // required virtual methods
  sid::bus::status irq_read_word(host_int_4 addr, little_int_1 mask,
				 little_int_1& data);
  sid::bus::status irq_write_word(host_int_4 addr, little_int_1 mask,
				  little_int_1 data);
  void irq_src_driven(host_int_4 val, host_int_4 bit_num);

  // use generic drive_irq_interrupts();
  // want to override this default
  void drive_fiq_interrupts() { }

  enum { NMI, SIRQ1, SIRQ0, TIRQ, NIRQ, IREQ1, IREQ2, IREQ3, PIRQ = NIRQ };
  host_int_1 irqAckSlot[3];
};

#endif // SIGTARGET_ARM 

#endif // INTERRUPT_CMA222_H
