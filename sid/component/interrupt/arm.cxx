// arm.cxx - An implementation of the interrupt controller from the
// ARM PID7T development board.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found at
// <http://www.arm.com/Documentation/UserMans/rps/#int>.

#include "config.h"
#include "tconfig.h"
#include "components.h"

#include "arm.h"

#if SIDTARGET_ARM

void
armIntController::irq_src_driven(host_int_4 val, host_int_4 bit_num)
{
  if (val)
    irq_pending |= 1 << bit_num;
  else
    irq_pending &= ~(1 << bit_num);

  drive_irq_interrupts();
}

void
armIntController::fiq_src_driven(host_int_4 val, host_int_4 bit_num)
{
  fiq_pending = (val > 0) ? 1 : 0;

  drive_fiq_interrupts();
}

sid::bus::status
armIntController::irq_read_word(host_int_4 addr,
				little_int_4 mask,
				little_int_4& le_data)
{
  host_int_4 data;

  switch (addr) {
  case 0:
    // IRQStatus.
    data = irq_pending & irq_enabled;
    break;
  case 1:
    // IRQRawStatus.
    data = irq_pending;
    break;
  case 2:
    // IRQEnable.
    data = irq_enabled;
    break;
  case 3:	// Reserved.
  case 4:
    return bus::unpermitted;
  default:
    return bus::unmapped;
  } 
  le_data = data;
  return bus::ok;
}

sid::bus::status
armIntController::fiq_read_word(host_int_4 addr,
				little_int_4 mask,
				little_int_4& le_data)
{
  host_int_4 data;

  switch (addr) {
  case 0:
    // FIQStatus.
    data = fiq_pending && fiq_enabled;
    break;
  case 1:
    // FIQRawStatus.
    data = fiq_pending;
    break;
  case 2:
    // FIQEnable.
    data = fiq_enabled;
    break;
  case 3:	// Reserved.
    return bus::unpermitted;
  default:
    return bus::unmapped;
  } 
  le_data = data;
  return bus::ok;
}

sid::bus::status
armIntController::irq_write_word(host_int_4 addr,
				 little_int_4 mask,
				 little_int_4 le_data)
{
  host_int_4 data = le_data;

  switch (addr) {
  case 2:
    // IRQEnableSet.
    irq_enabled |= data;
    break;
  case 3:
    // IRQEnableClear.
    irq_enabled &= ~data;
    break;
  case 4:
    // IRQSoft.
    if (data & 2)
      {
        // Bit 1 set.
        irq_pending |= 2;
      }
    else
      {
	// Bit 1 clear.
	irq_pending &= ~2;
      }
      break;
  case 0:  // Reserved.
  case 1:
    return bus::unpermitted;
  default:
    return bus::unmapped;
  }
  // Some pending interrupts may now be enabled.
  // Some may also now be disabled.  Re-check.
  drive_interrupts();
  return bus::ok;
}

sid::bus::status
armIntController::fiq_write_word(host_int_4 addr,
				 little_int_4 mask,
				 little_int_4 le_data)
{
  host_int_4 data = le_data;

  switch (addr) {
  case 2:
   // FIQEnableSet.
    fiq_enabled |= data;
    break;
  case 3:
    fiq_enabled &= ~data;
    break;
  case 0:	// Reserved.
  case 1:
    return bus::unpermitted;
  default:
    return bus::unmapped;
  }
  // Some pending interrupts may now be enabled.
  // Some may also now be disabled.  Re-check.
  drive_interrupts();
  return bus::ok;
}

#endif // SIDTARGET_ARM
