// cma222.cxx - An implementation of the interrupt controller from the
// Cogent Computer CMA222 development board.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found at
// <http://www.cogcomp.com/data_sheets/cma222ds.htm

#include "config.h"
#include "tconfig.h"
#include "components.h"

#include "cma222.h"

#if SIDTARGET_ARM

/*
 * ``NMI, PIRQ and TIRQ are "Sticky Bits". When they go true, the source bit will
 * remain true until a one is written to the corresponding bit in the Clear
 * Interrupt Source Register.''  -- deal with it.
 */
void
cma222IntController::irq_src_driven(host_int_4 val, host_int_4 bit_num)
{

  if (val)
    irq_pending |= 1 << bit_num;
  else
    {
      switch (bit_num) {
        case NMI:
        case PIRQ:
        case TIRQ:
          return;
      }
      irq_pending &= ~(1 << bit_num);
    }
  drive_irq_interrupts();
}

sid::bus::status
cma222IntController::irq_write_word(host_int_4 addr,
				    little_int_1 mask,
				    little_int_1 le_data)
{
  host_int_1 data = le_data;

  switch (addr) {
  case 0x8:
    // Clear Interrupt Source Register
    irq_pending &= ~data;
    break;
  case 0x18:
    // Interrupt Mask Register
    irq_enabled = data;
    break;
  default:
    if (addr >= 0 && addr < 0x38)
      return bus::unpermitted;
    else
      return bus::unmapped;
  }
  // Some pending interrupts may now be enabled.
  // Some may also now be disabled.  Re-check.
  drive_irq_interrupts ();

  return bus::ok;
}

sid::bus::status
cma222IntController::irq_read_word(host_int_4 addr,
				   little_int_1 mask,
				   little_int_1& le_data)
{
  host_int_1 data;

  switch (addr) {
  case 0x0:
    // Interrupt Source Register
    data = irq_pending & irq_enabled;
    break;
  case 0x10:
    // Interrupt Mask Register
    data = irq_enabled;
    break;
  // XXX: note that there is currently no way to *set* these values!
  // XXX: need to see how the IO modules on the real hardware do it
  // XXX: and provide a that works like that.
  case 0x20:
    // Interrupt Acknowledge Slot 1
    data = irqAckSlot[0];
    break;
  case 0x28:
    // Interrupt Acknowledge Slot 2
    data = irqAckSlot[1];
    break;
  case 0x30:
    // Interrupt Acknowledge Slot 3
    data = irqAckSlot[2];
    break;
  default:
    if (addr >= 0 && addr < 0x38)
      return bus::unpermitted;
    else
      return bus::unmapped;
  } 
  le_data = data;
  return bus::ok;
}

#endif // SIDTARGET_ARM
