// timer.h - Class declaration for the Toshiba Media Engine (MeP) Timer
// -*- C++ -*-

// Copyright (C) 2002, 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef TIMER_H
#define TIMER_H

#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidschedutil.h>
#include <sidbusutil.h>
#include <sidcpuutil.h>


// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;

class mep_timer_channel;

// The actual TIMER component.
// Inherit mix-in classes.
class mep_timer: public virtual component,
		protected fixed_attribute_map_component,
		protected fixed_bus_map_component,
		protected fixed_pin_map_component,
		protected fixed_accessor_map_component,
		protected no_relation_component
{
public:
  mep_timer ();

  // Debugging
  static const bool debug_burst = false;

  bool activate () throw ();
  void signal_nmi ();

private:
  static const int max_channels = 4;
  static const int begin_wait = 1;

  void do_one_burst () throw ();

  // Called when num-channels attribute is set.
  void num_channels_set ();

  // Activation state
  bool active;

  unsigned num_channels;

  // One control bus for each of the channels.
  control_register_bus<big_int_4> *channel_ctrl_bus[max_channels];
  
  // The TIMER Channels
  mep_timer_channel *channels[max_channels];

  // Timer state machine.
  scheduler_event_subscription<mep_timer> sched;

  // Output pins.
  sidutil::output_pin *interrupt_pin[max_channels];
  sidutil::output_pin nmi_pin;

  // This class must be a friend of scheduler_event_subscription<T>.
  friend class scheduler_event_subscription<mep_timer>;
};

// This class represents one control channel of the timer.
//
class mep_timer_channel
{
 public:
  mep_timer_channel (mep_timer &o,
		     control_register_bus<big_int_4> &b,
		     sidutil::output_pin &p,
		     unsigned c);

  // Respond to one clock tick
  int tick ();

  // Access to control registers fields.
  unsigned  get_cnt_cnt  () { return cnt_cnt; }
  unsigned  get_cmp_cmp  () { return cmp_cmp; }
  unsigned  get_ten_ten  () { return ten_ten; }
  unsigned  get_tcr_tai  () { return tcr_tai; }
  unsigned  get_tcr_tmd  () { return tcr_tmd; }
  unsigned  get_tcr_tie  () { return tcr_tie; }
  unsigned  get_tis_tis  () { return tis_tis; }
  unsigned  get_tcd_tcd  () { return tcd_tcd; }

  void set_cnt_cnt (unsigned cnt) { cnt_cnt = cnt; }
  void set_cmp_cmp (unsigned cmp) { cmp_cmp = cmp; }
  void set_ten_ten (unsigned ten);
  void set_tcr_tai (unsigned tai) { tcr_tai = tai; }
  void set_tcr_tmd (unsigned tmd) { tcr_tmd = (channel_num == 0 ? tmd : 0); }
  void set_tcr_tie (unsigned tie);
  void set_tis_tis (unsigned tis);
  void set_tcd_tcd (unsigned tcd) { tcd_tcd = tcd; }

  // Access to control registers as a whole.
  big_int_4 get_cnt () { return cnt_cnt; }
  big_int_4 get_cmp () { return cmp_cmp; }
  big_int_4 get_ten () { return ten_ten; }
  big_int_4 get_tcr () { return ((tcr_tai & 1) << 5)
			      | ((tcr_tmd & 1) << 4)
			      | ((tcr_tie & 1)     ); }
  big_int_4 get_tis () { return tis_tis; }
  big_int_4 get_tcd () { return tcd_tcd; }

  void set_cnt  (big_int_4 val, big_int_4 unused) { set_cnt_cnt  (val); }
  void set_cmp  (big_int_4 val, big_int_4 unused) { set_cmp_cmp  (val); }
  void set_ten  (big_int_4 val, big_int_4 unused) { set_ten_ten  (val       & 0x1); }
  void set_tcr  (big_int_4 val, big_int_4 unused) { set_tcr_tai ((val >> 5) & 0x1);
                                                    set_tcr_tmd ((val >> 4) & 0x1);
                                                    set_tcr_tie ((val     ) & 0x1); }
  void set_tis  (big_int_4 val, big_int_4 unused) { set_tis_tis  (val       & 0x1); }
  void set_tcd  (big_int_4 val, big_int_4 unused) { set_tcd_tcd  (val       & 0x7); }

 private:
  // Respond to timeout
  void timeout ();

  unsigned tick_limit () { return 1 << get_tcd_tcd (); }

  // The owning TIMER
  mep_timer &owner;

  // Control registers for this channel.
  control_register_bus<big_int_4> &control_bus;

  // Interrupt pin
  sidutil::output_pin &interrupt_pin;

  // Channel number
  unsigned channel_num;

  // CNT (Count Register)
  unsigned cnt_cnt;
  callback_control_register<big_int_4,mep_timer_channel> cnt;
  // CMP (Compare Register)
  unsigned cmp_cmp;
  callback_control_register<big_int_4,mep_timer_channel> cmp;
  // TEN (Timer Enable Register)
  unsigned ten_ten;
  callback_control_register<big_int_4,mep_timer_channel> ten;
  // TCR (Timer Control Register)
  unsigned tcr_tai;
  unsigned tcr_tmd;
  unsigned tcr_tie;
  callback_control_register<big_int_4,mep_timer_channel> tcr;
  // TIS (Timer Interrupt Status Register)
  unsigned tis_tis;
  callback_control_register<big_int_4,mep_timer_channel> tis;
  // TCD (Timer Clock Divide Register)
  unsigned tcd_tcd;
  callback_control_register<big_int_4,mep_timer_channel> tcd;

  // Number of ticks since the last counter increment
  unsigned ticks;
};

#endif // TIMER_H
