// arm.cxx - An implementation of the timer from the ARM PID7T
// development board.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
// arm.cxx

// A more thorough description of this component may be found at
// <http://www.arm.com/Documentation/UserMans/rps/#timer>

#include "arm7t-timer.h"

ostream& operator << (ostream& o, const armTimer::timer_mode& m)
{
  switch (m)
    {
    case armTimer::free_running: 
      o << "free-running";
      break;
    case armTimer::periodic:
      o << "periodic";
      break;
    default:
      o << "?";
    }
  return o;
}

istream& operator >> (istream& i, armTimer::timer_mode& m)
{
  string mode;
  i >> mode;
  if (mode == "free-running")
    m = armTimer::free_running;
  else if (mode == "periodic")
    m = armTimer::periodic;
  else 
    i.setstate (ios::badbit);
  return i;
}



armTimer::armTimer()
  :counter(0), enabled(false), loadValue(0),
   mode(free_running), prescale(0), bus(this),
   reset_pin(this, & armTimer::reset_pin_handler), 
   triggerpoint_manager(this)
{
  add_bus("registers", &this->bus);

  add_pin("interrupt", &this->interrupt_pin);
  add_attribute("interrupt", & this->interrupt_pin, "pin");
  triggerpoint_manager.add_watchable_attribute("interrupt");
  categorize("interrupt", "watchable");
  
  add_attribute("counter", &this->counter, "register"); 
  triggerpoint_manager.add_watchable_attribute("counter");
  categorize("counter", "watchable");

  add_attribute("load-value", &this->loadValue, "register");
  triggerpoint_manager.add_watchable_attribute("load-value");
  categorize("load-value", "watchable");

  add_attribute("enabled", &this->enabled, "register");
  triggerpoint_manager.add_watchable_attribute("enabled");
  categorize("enabled", "watchable");

  add_attribute("mode", &this->mode, "register");
  triggerpoint_manager.add_watchable_attribute("mode");
  categorize("mode", "watchable");

  add_attribute("prescale", &this->prescale, "register");
  triggerpoint_manager.add_watchable_attribute("prescale");
  categorize("prescale", "watchable");

  add_pin ("reset", & this->reset_pin);
  add_attribute ("reset", & this->reset_pin, "pin");
  triggerpoint_manager.add_watchable_attribute("reset");
  categorize("reset", "watchable");

  add_attribute_virtual ("state-snapshot", this, 
			 & armTimer:: save_state,
			 & armTimer:: restore_state);
}



void
armTimer::reset ()
{
  this->counter = 0;
  this->enabled = false;
  this->loadValue = 0;
  this->mode = free_running;
  this->prescale = 0;
  if (this->interrupt_pin.recall() != 0)
    this->interrupt_pin.drive (0);
  this->reset_schedule ();
}


armTimerNoSched::armTimerNoSched()
  :armTimer(), clockpin(this, & armTimerNoSched::tick), ticks(0)
{
  add_pin("clock", &clockpin);

  add_attribute_ro("ticks", &ticks, "register");
  triggerpoint_manager.add_watchable_attribute("ticks");
  categorize("ticks", "watchable");
}


void
armTimerNoSched::reset ()
{
  armTimer::reset ();
  this->ticks = 0;
}


armTimerSched::armTimerSched()
  :armTimer(), ticker("divided-clock", this, & armTimer::tick)
{
}



void
armTimer::tick()
{
  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch();

  if (!enabled)
    return;

  counter--;
  // cerr << "divisor=" << divisor << " counter=" << counter << endl;
  if (counter == 0)
    {
      if (mode == periodic) {
	counter = loadValue;
	if (interrupt_pin.recall() != 1)
	  interrupt_pin.drive(1);
      } else {
	counter = 65535; // rolls over from maximum value; no interrupts
      }
    }
}


void
armTimerNoSched::tick()
{
  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch();

  if (!enabled)
    return;

  if (prescale > 3) 
    {
      cerr << "hw-timer-arm/ref error: invalid prescale value" << prescale << endl;
      prescale = 3;
    }
  assert (prescale <= 3);
  unsigned divisor = 1 << (prescale * 4);

  ticks ++;
  assert (divisor != 0);
  if ((ticks % divisor) == 0) {
    ticks = 0;

    armTimer::tick();
  }
}


void
armTimerSched::reset_schedule()
{
  // cerr << "reset_schedule" << endl;
  this->ticker.cancel();

  if (!enabled)
    return;

  // XXX: prescale == 3 has undefined behavior.
  assert (prescale <= 3);
  unsigned divisor = 1 << (prescale * 4);

  // cerr << "divisor = " << divisor << endl;
  this->ticker.schedule_regular (divisor);
}




bus::status
armTimer::bus_interface::word_write(host_int_4 addr,
				    little_int_4 mask,
				    little_int_4 le_data)
{
  host_int_4 data = le_data;
  switch (addr)
    {
    case 0:
      // Clear top 16 bits when loading a new value.
      host->loadValue = data & 0xFFFF;
      // Reset the counter value.
      host->counter = host->loadValue;
      break;
    case 1:
      // Reserved.
      break;
    case 2:
      host->prescale = (data & 0x0C) >> 2;
      host->enabled = ((data & 0x80) == 0x80);
      host->mode = ((data & 0x40) >> 6) ? periodic : free_running;
      host->reset_schedule();
      break;
    case 3:
      if (host->interrupt_pin.recall() != 0)
	host->interrupt_pin.drive(0);
      break;
    case 4:
      // Reserved.
      break;
    default:
      return bus::unmapped;
    }

  // check for triggerpoints
  host->triggerpoint_manager.check_and_dispatch();
  return bus::ok;
}

bus::status
armTimer::bus_interface::word_read(host_int_4 addr,
				   little_int_4 mask,
				   little_int_4& data)
{
  switch (addr)
    { 
    case 0:
      // Timer load
      data = host->loadValue;
      return bus::ok;

    case 1:
      // Timer value
      data = host->counter;
      return bus::ok;

    case 2:
      // Timer control
      data = (host->enabled << 7) | (host->mode << 6) | (host->prescale << 2);
      return bus::ok;

    case 3:
      // Reserved.
      return bus::ok;

    case 4:
      // Reserved.
      return bus::ok;

    default:
      return bus::unmapped;
    }

  // NOTREACHED
}

std::string
armTimer::save_state()
{
  return make_attribute(*this);
}


sid::component::status
armTimer::restore_state(const string& state)
{
  return parse_attribute(state, *this);
}

ostream&
operator << (ostream& op, const armTimer& obj)
{
  obj.stream(op);
  return op;
}

istream& operator >> (istream& ip, armTimer& obj)
{
  obj.destream(ip);
  return ip;
}

void
armTimer::stream(ostream& op) const
{
  op << "Interrupt " << interrupt_pin << ' ';
  op << "Counter " << counter << ' ';
  op << "Enable " << enabled << ' ';
  op << "LoadValue " << loadValue << ' ';
  op << mode << ' ' ;
  op << "Prescale " << prescale << ' ';
  op << "Reset " << reset_pin;
}

void
armTimerNoSched::stream(ostream& op) const
{
  armTimer::stream(op);
  if (!op.good())
    return;

  op << ' ' << "Ticks " << ticks;
}

void
armTimerNoSched::destream(istream& ip)
{
  armTimer::destream(ip);
  if (!ip.good())
    return;

  string key;

  ip >> key;
  if (key != "Ticks")
    {
      ip.setstate(ios::badbit);
      return;
    }

  ip >> ticks;
}

void
armTimer::destream(istream& ip)
{
  string key;
  
  ip >> key;
  if (key == "Interrupt")
    {
      ip >> interrupt_pin;
    }
  else
    {
      ip.setstate(ios::badbit);
      return;
    }

  ip >> key;
  if (key == "Counter")
    ip >> counter;
  else
    {
      ip.setstate(ios::badbit);
      return;
    }       
  
  ip >> key;
  if (key != "Enable")
    {
      ip.setstate(ios::badbit);
      return;
    }
  else 
    ip >> enabled;
  
  ip >> key;
  if (key != "LoadValue")
    {
      ip.setstate(ios::badbit);
      return;
    }
  else 
    ip >> loadValue;
  
  // following >> is taken care by timer_mode operator
  ip >> mode;
  
  ip >> key;
  if (key != "Prescale")
    {
      ip.setstate(ios::badbit);
      return;
    }
  else 
    ip >> prescale;

  ip >> key;
  if (key != "Reset")
    {
      ip.setstate(ios::badbit);
      return;
    }
  else 
    ip >> reset_pin;
}

