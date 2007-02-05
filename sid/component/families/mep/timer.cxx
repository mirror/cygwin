// timer.cxx - An implementation of the Timer for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2002, 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "timer.h"

using namespace std;

mep_timer_channel::mep_timer_channel (mep_timer &o,
				      control_register_bus<big_int_4> &b,
				      sidutil::output_pin &p,
				      unsigned c)
  :
  owner (o),
  control_bus (b),
  interrupt_pin (p),
  channel_num (c),
  // Ctrl regs and fields. Fields with undefined initial values
  // are not initialized.
  cnt_cnt (0x1),
  cnt (& control_bus, 0x0, 0xffffffff, true, true, this,
       & mep_timer_channel::set_cnt, & mep_timer_channel::get_cnt),
  cmp_cmp (0),
  cmp (& control_bus, 0x1, 0xffffffff, true, true, this,
       & mep_timer_channel::set_cmp, & mep_timer_channel::get_cmp),
  ten_ten (0),
  ten (& control_bus, 0x2, 0xffffffff, true, true, this,
       & mep_timer_channel::set_ten, & mep_timer_channel::get_ten),
  tcr_tai (0),
  tcr_tmd (0),
  tcr_tie (0),
  tcr (& control_bus, 0x3, 0xffffffff, true, true, this,
       & mep_timer_channel::set_tcr, & mep_timer_channel::get_tcr),
  tis_tis (0),
  tis (& control_bus, 0x4, 0xffffffff, true, true, this,
       & mep_timer_channel::set_tis, & mep_timer_channel::get_tis),
  tcd_tcd (0),
  tcd (& control_bus, 0x5, 0xffffffff, true, true, this,
       & mep_timer_channel::set_tcd, & mep_timer_channel::get_tcd),
  ticks (0)
{
}

void
mep_timer_channel::set_ten_ten (unsigned ten)
{
  if (ten)
    {
      // Setting this bit when it is already set has no effect.
      if (ten_ten)
	return;

      ten_ten = 1;

      // If cmp_cmp and cnt_cnt are both 0, then indicate a timeout
      // immediately, otherwise activate the timer.
      if (get_cmp_cmp () == 0 && get_cnt_cnt () == 0)
	{
	  timeout ();
	  if (! ten_ten)
	    return;
	}
	 
      // Activate the timer.
      if (owner.activate ())
	{
	  // Perform one tick right away
	  ticks = 0;
	  tick ();
	  return;
	}
    }

  // Bit being cleared, or init failed.
  ten_ten = 0;
}

void
mep_timer_channel::set_tis_tis (unsigned tis)
{
  // We are clearing tis_tis in interval mode
  if (tis_tis && ! tis && get_tcr_tmd () == 0)
    {
      // If counter matches the compare register, then there is no effect
      // since the timer immediately times out again. See MeP Media Engine
      // User's Manual, section 6.4.1, item (3).
      if (get_cnt_cnt () == get_cmp_cmp ())
	return;

      // Clear any pending interrupt
      if (owner.debug_burst)
	cout << "  clearing interrupt pin while clearing tis_tis" << endl;
      interrupt_pin.drive (0);
    }
  // If we setting tis_tis to 1, generate an interrupt if tcr_tie
  // is also set.
  else if (tis && get_tcr_tie ())
    {
      if (get_tcr_tmd ())
	{
	  if (owner.debug_burst)
	    cout << "  driving nmi pin while setting tis_tis" << endl;
	  owner.signal_nmi ();
	}
      else
	{
	  if (owner.debug_burst)
	    cout << "  driving interrupt pin while setting tis_tis" << endl;
	  interrupt_pin.drive (1);
	}
    }

  tis_tis = tis;
}

void
mep_timer_channel::set_tcr_tie (unsigned tie)
{
  // If we are changing tie_tie from 0 to 1 in interval mode and tis_tis is
  // set, generate an interrupt.
  if (! tcr_tie && tie && get_tcr_tmd () == 0 && get_tis_tis ())
    {
      if (owner.debug_burst)
	cout << "  driving interrupt pin while setting tcr_tie" << endl;
      interrupt_pin.drive (1);
    }

  tcr_tie = tie;
}

int
mep_timer_channel::tick ()
{
  // If not active, then nothing to do
  if (! get_ten_ten ())
    return 0; // not active

  if (owner.debug_burst)
    cout << "channel " << channel_num << " is active" << endl;

  // Only increment the counter if the divisor has been exceeded
  ++ticks;
  if (ticks < tick_limit ())
    {
      if (owner.debug_burst)
	cout << "  ticks== 0x" << hex << ticks
	     << " limit== 0x" << tick_limit () << dec << endl;
      return 1; // still active
    }
  ticks = 0;

  // Increment the counter
  sid::big_int_4 cnt = get_cnt_cnt () + 1;
  set_cnt_cnt (cnt);

  if (owner.debug_burst)
    cout << "  cnt is " << hex << cnt << dec << endl;

  // See if we have timed out
  if (cnt != get_cmp_cmp ())
    return 1; // still active

  // we have timed out
  timeout ();

  return get_ten_ten (); // still active?
}

void
mep_timer_channel::timeout ()
{
  if (owner.debug_burst)
    cout << "  timeout" << endl;

  // Signal the interrupt, if requested
  set_tis_tis (1);

  // Check for auto counter reset.
  if (! get_tcr_tai ())
    {
      if (owner.debug_burst)
	cout << "  no auto reset. Channel now inactive. cnt is "
	     << hex << get_cnt_cnt () << dec << endl;
      // No auto reset. Timer becomes inactive.
      set_ten_ten (0);
      return;
    }

  // Reset the counter.
  set_cnt_cnt (1);
  if (owner.debug_burst)
    cout << "  auto reset" << endl;

  if (owner.debug_burst)
    cout << "  channel remains active" << endl;
}

mep_timer::mep_timer ()
  :
  active (false),
  num_channels (1),
  sched ("burst", this, & mep_timer::do_one_burst),
  nmi_pin ()
{
  // Allocate and assign  a control bus and an interrupt pin for
  // each channel.
  for (int i = 0; i < max_channels; ++i)
    {
      channels[i] = NULL;
      channel_ctrl_bus[i] = new control_register_bus<big_int_4> ();
      add_bus ("control-regs-" + make_numeric_attribute (i),
	       channel_ctrl_bus[i]);
      interrupt_pin[i] = new sidutil::output_pin ();
      add_pin ("interrupt-" + make_numeric_attribute (i), interrupt_pin[i]);
    }
  add_pin ("nmi", & nmi_pin);

  // Set up the default configuration.
  add_attribute_notify ("num-channels", & num_channels, this,
			& mep_timer::num_channels_set, "setting");
  set_attribute_value ("num-channels", "1");
}

// Called after the dcr attribute is set to alter the configuration
// accordingly.
void
mep_timer::num_channels_set ()
{
  // Allocate the requested number of channels
  for (int i = 0; i < num_channels; ++i)
    {
      if (channels[i] != NULL)
	continue; // already allocated
      assert (channel_ctrl_bus[i]);
      assert (interrupt_pin[i]);
      channels[i] = new mep_timer_channel (*this, *channel_ctrl_bus[i],
					   *interrupt_pin[i], i);
    }
}

bool
mep_timer::activate () throw ()
{
  if (active)
    return true; // all is ok

  // Schedule the transfer with the scheduler.
  active = true;
  sched.schedule_regular (begin_wait);  
  return true; // all is ok
}

void
mep_timer::do_one_burst () throw ()
{
  if (debug_burst)
    cout << "------------------------" << endl;

  bool active_channels = false;
  for (int i = 0; i < num_channels; ++i)
    {
      assert (channels[i]);
      bool still_active = channels[i]->tick ();

      if (still_active)
	active_channels = true;
    }

  if (! active_channels)
    {
      sched.cancel ();
      active = false;
    }
}

void
mep_timer::signal_nmi ()
{
  nmi_pin.drive (1);
}
