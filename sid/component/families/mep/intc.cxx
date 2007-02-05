// intc.cxx - An implementation of the interrupt controller for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2001-2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found in the
// Toshiba Media Engine User's Guide (revision 2.2), chapter 5.

#include "components.h"
#include "mep-intc.h"

mep_intc::mep_intc (unsigned num_channels)
  :num_channels (num_channels),
   cfg_interrupt_level (15),
   registers (this),
   interrupt_level       (&registers, 0, 0x0000f000),
   interrupt_mask_level  (&registers, 0, 0x00000f00, true, true, 0),
   interrupt_channel_num (&registers, 0, 0x000000F8),
   ivr_reserved          (&registers, 0, 0xffff0007),
   reset_pin (this, &mep_intc::reset)
{
  assert (num_channels <= max_channels && num_channels > 0);

  for (unsigned i = 0; i < num_channels; i++)
    {
      interrupt_sources[i] = new interrupt_pin (i, this, &mep_intc::interrupt_source_driven);
      ier[i] = new value_control_register<big_int_4> (&registers, 2, 1 << i, true, true);
      iet[i] = new value_control_register<big_int_4> (&registers, 3, 1 << i, true, true);
      ilr[i] = new value_control_register<big_int_4> (&registers, 4 + (i / 8), 0xf << (4 * (i % 8)), true, true);
    }
  
  for (unsigned i = num_channels; i < max_channels; i++)
    {
      interrupt_sources[i] = 0;
      ier[i] = new fixed_control_register<big_int_4> (&registers, 2, 1 << i);
      iet[i] = new fixed_control_register<big_int_4> (&registers, 3, 1 << i);
      ilr[i] = new fixed_control_register<big_int_4> (&registers, 4 + (i / 8), 0xf << (4 * (i % 8)));
    }

  for (unsigned i = 0; i < max_channels; i++)
    {
      isr[i] = new isr_control_register<big_int_4> (&registers, 1, 1 << i, iet[i]);
    }

  add_bus ("registers", &registers);
  add_pin ("interrupt", &interrupt_out_pin);
  add_pin ("reset", &reset_pin);
  add_attribute ("reset", &reset_pin, "add");
  add_attribute ("interrupt", &interrupt_out_pin, "pin");
  add_attribute ("cfg-interrupt-level", &cfg_interrupt_level, "setting");
  add_attribute ("have_irq", &have_irq, "setting");
  add_attribute_ro_value ("interrupt-level", interrupt_level, "register");
  add_attribute_ro_value ("interrupt-mask-level", interrupt_mask_level, "register");
  add_attribute_ro_value ("interrupt-channel-number", interrupt_channel_num, "register");

  add_attribute_virtual ("interrupt-status-register",  this, &mep_intc::get_isr,  &mep_intc::nop, "register");
  add_attribute_virtual ("interrupt-enable-register",  this, &mep_intc::get_ier,  &mep_intc::nop, "register");
  add_attribute_virtual ("interrupt-level-register-0", this, &mep_intc::get_ilr0, &mep_intc::nop, "register");
  add_attribute_virtual ("interrupt-level-register-1", this, &mep_intc::get_ilr1, &mep_intc::nop, "register");
  add_attribute_virtual ("interrupt-level-register-2", this, &mep_intc::get_ilr2, &mep_intc::nop, "register");
  add_attribute_virtual ("interrupt-level-register-3", this, &mep_intc::get_ilr3, &mep_intc::nop, "register");
  add_attribute_virtual ("interrupt-edge-trigger-register", this, &mep_intc::get_iet, &mep_intc::nop, "register");

  for (unsigned i = 0; i < num_channels; i++)
    {
      string name = "interrupt-source-" + make_numeric_attribute (i);
      add_pin (name, interrupt_sources[i]);
      string name2 = "interrupt-name-" + make_numeric_attribute (i);
      add_attribute (name2, & this->interrupt_names[i], "setting");
    }
  reset ();
}

mep_intc::~mep_intc () throw ()
{
  for (unsigned i = 0; i < max_channels; i++)
    {
      delete interrupt_sources[i];
      delete isr[i];
      delete ier[i];
      delete iet[i];
      delete ilr[i];
    }
}

string
mep_intc::get_isr ()
{
  host_int_4 value = 0;
  for (unsigned i = 0; i < 32; i++)
    value |= *isr[i] << i;
  return make_attribute (value);
}

string
mep_intc::make_bit_register_attr (value_control_register<big_int_4>** ptr)
{
  host_int_4 value = 0;
  for (unsigned i = 0; i < 32; i++)
    value |= *ptr[i] << i;
  return make_attribute (value);
}

string
mep_intc::make_nybble_register_attr (value_control_register<big_int_4>** ptr)
{
  host_int_4 value = 0;
  for (unsigned i = 0; i < 8; i++)
    value |= *ptr[i] << (4 * i);
  return make_attribute (value);
}

void
mep_intc::reset (host_int_4 ignored)
{
  interrupt_channel_num = 0;
  interrupt_mask_level = 0;
  interrupt_level = 0;
  
  for (unsigned i = 0; i < max_channels; i++)
    {
      *isr[i] = 0;
      *ier[i] = 0;
      *iet[i] = 0;
      *ilr[i] = 0;
    }

  update_state ();
}

void
mep_intc::update_state ()
{
  unsigned i;
  unsigned selected = (unsigned) -1;
  unsigned selected_level;

  // cap all ILRn values if necessary
  for (i = 0; i < num_channels; i++)
    {
      if (*ilr[i] > cfg_interrupt_level)
	*ilr[i] = cfg_interrupt_level;
    }
  
  for (selected_level = 0, i = 0; i < num_channels; i++)
    {
      if (*isr[i] &&
	  *ier[i] &&
	  *ilr[i] > interrupt_mask_level &&
	  *ilr[i] >= selected_level)
	{
	  selected = i;
	  selected_level = *ilr[selected];
	}
    }

  if (interrupt_out_pin.recall () != selected)
    {
      if (selected != -1)
	{
	  interrupt_channel_num = selected;
	  interrupt_level = selected_level;	  
	}  
      interrupt_out_pin.drive (selected);
    }
}

void
mep_intc::interrupt_source_driven (host_int_4 channel, host_int_4 value)
{
  if (*iet[channel])
    {
      // Triggered on rising edge.
      if (value)
	*isr[channel] = 1;
    }
  else
    {
      // Level triggered.
      *isr[channel] = (value > 0);
    }

  update_state ();
}
