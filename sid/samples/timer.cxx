// timer.cxx - an example of a SID component implementation.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// Noteworthy remarks about the code in this source file:
// * For clarity, the C++ "using" keyword is used sparingly and all members
//   of the "sid::" namespace appear fully qualified.
// * Documentation for the Standard Template Library, plus any obscure
//   C++ syntax you may encounter can be discovered in the 3rd edition of
//   ``The C++ Programming Language'', by Stroustup. ISBN 0-201-88954-4.

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>

#include <set>
#include <string>
#include <vector>


// Wrap everything in a unique namespace 
namespace timer_example
{


// Import standard types into this namespace.
using namespace std;


class Timer: public virtual sid::component
{
public:
  Timer()
    :scheduler_pin(0), clock_pin(this), bus(this), enabled(false) { }
  ~Timer() throw () { }
  
  // Provide implementations for abstract methods in sid::component.
  // See include/sidcomp.h.
  
  vector<string> pin_names() throw();
  sid::pin* find_pin(const string& name) throw();
  sid::component::status connect_pin(const string& name, sid::pin* pin) throw();
  sid::component::status disconnect_pin(const string& name, sid::pin* pin) throw();
  vector<sid::pin*> connected_pins(const string& name) throw();
  
  vector<string> accessor_names() throw();
  sid::component::status connect_accessor(const string& name, sid::bus* bus) throw();
  sid::component::status disconnect_accessor(const string& name, sid::bus* bus) throw();
  
  vector<string> bus_names() throw();
  sid::bus* find_bus(const string& name) throw();
  sid::bus* connected_bus(const string& name) throw();
  
  vector<string> attribute_names() throw();
  vector<string> attribute_names(const string& category) throw();
  string attribute_value(const string& name) throw();
  sid::component::status set_attribute_value(const string& name, const string& value) throw();
  
  vector<string> relationship_names() throw();
  sid::component::status relate(const string& rel, sid::component* c) throw();
  sid::component::status unrelate(const string& rel, sid::component* c) throw();
  vector<sid::component*> related_components(const string& rel) throw();
  
private:
  // A netlist, which tracks pins connected to the interrupt pin.
  typedef set<sid::pin*> netlist_t;
  netlist_t intpin_netlist;

  // A handle to the scheduler's "control" pin.
  // The scheduler is a preexisting SID component which can schedule
  // and deliver events to a component via an "event" pin.
  // See schedule() for more details.
  sid::pin* scheduler_pin;

  // Schedule an event for some time in the future.
  void schedule(sid::host_int_4 time);

  // Cancel any pending events.
  void cancel();

  // Reschedule an event.
  void reset_schedule();

  // This method is called whenever the scheduler delivers an event,
  // because the "divided-clock-event" pin will be connected to the
  // scheduler.  It is a specialised pin with these fixed semantics.
  // Refer to class clock_pin_t below.
  void tick();

  // Drive a value on the interrupt pin (which propogates to all
  // connected pins).
  void drive_interrupt(sid::host_int_4 value);

  class clock_pin_t: public sid::pin
  {
    // clock_pin_t is a specialised pin.
    // It calls timer->tick() whenever a value is driven. 
  public:
    clock_pin_t(Timer* t): timer(t) { }
    void driven(sid::host_int_4 value) throw() { timer->tick(); }
  private:
    Timer* timer;
  };
  friend class clock_pin_t;
  clock_pin_t clock_pin;


  // register_bus is a specialised bus.
  // It handles the majority of the component's functionality, since
  // that is mostly controlled by the timer's register set.

  class register_bus: public sid::bus
  {
  public:
    register_bus(Timer* t): timer(t) { }

    // Prototypes for bus read/write methods of all kinds.
    sid::bus::status read(sid::host_int_4 addr,sid::little_int_1& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::big_int_1& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::little_int_2& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::big_int_2& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::little_int_4& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::big_int_4& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::little_int_8& data) throw();
    sid::bus::status read(sid::host_int_4 addr,sid::big_int_8& data) throw();

    sid::bus::status write(sid::host_int_4 addr,sid::little_int_1 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::big_int_1 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::little_int_2 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::big_int_2 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::little_int_4 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::big_int_4 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::little_int_8 data) throw();
    sid::bus::status write(sid::host_int_4 addr,sid::big_int_8 data) throw();

  private:
    Timer* timer;
  };
  friend class register_bus;
  register_bus bus;

  // Data members that represent the timer's internal state.

  bool enabled;
  sid::host_int_2 load_value, prescale, counter;
  enum timer_mode { PERIODIC, FREERUNNING } mode;
};


// Return a list of pin names which are visible to other components.

vector<string>
Timer::pin_names() throw()
{
  vector<string> pins;
  pins.push_back("divided-clock-event");
  return pins;
}


// Return a list of pins that are connected to a named pin.
// We recognize "interrupt" and "divided-clock-control".

vector<sid::pin*>
Timer::connected_pins(const string& name) throw()
{
  vector<sid::pin*> pins;
  netlist_t::const_iterator it;

  if (name == "interrupt")
    {
      for (it = intpin_netlist.begin(); it != intpin_netlist.end();
	   it++)
	{
	  pins.push_back(*it);
	}
      return pins;
    }
  else if (name == "divided-clock-control")
    {
      pins.push_back(scheduler_pin);
      return pins;
    }
  return vector<sid::pin*>();
}


// Connect a pin to a named pin.
// We recognize "interrupt" and "divided-clock-control".

// We allow multiple pins to be connected to the interrupt pin (with
// infinite fan-out!), so these are kept in a netlist.  For
// efficiency, the STL container chosen for the netlist ensures that
// no duplicate pin handles are stored.

sid::component::status
Timer::connect_pin(const string& name, sid::pin* pin) throw()
{
  if (name == "interrupt")
    {
      // Add this pin to the netlist.
      intpin_netlist.insert(intpin_netlist.end(), pin);
      return sid::component::ok;
    }
  else if (name == "divided-clock-control")
    {
      // Reassign the scheduler pin.
      scheduler_pin = pin;
      return sid::component::ok;
    }
  return sid::component::not_found;
}

// Disconnect a pin from a named pin.

sid::component::status
Timer::disconnect_pin(const string& name, sid::pin* pin) throw()
{
  if (name == "interrupt")
    {
      // Remove this pin from the netlist.
      if (intpin_netlist.erase(pin) > 0)
	return sid::component::ok;
    }
  else if (name == "divided-clock-control" && scheduler_pin == pin)
    {
      // Elsewhere, we make sure to not use this pin if it's null.
      scheduler_pin = 0;
      return sid::component::ok;
    }
  return sid::component::not_found;
}


// Find a pin of a given name.
// We only recognize "divided-clock-event".

sid::pin*
Timer::find_pin(const string& name) throw()
{
  if (name == "divided-clock-event")
    return &clock_pin;

  return 0;
}


vector<string>
Timer::accessor_names() throw()
{
  // No accessors.
  return vector<string>();
}


sid::component::status
Timer::connect_accessor(const string& name, sid::bus* bus) throw()
{
  // No acccessors; any name is unknown.
  return sid::component::not_found;
}


sid::component::status
Timer::disconnect_accessor(const string& name, sid::bus* bus) throw()
{
  // No accessors; any name is unknown.
  return sid::component::not_found;
}


// Return a list of bus names. We have just one--"registers".

vector<string>
Timer::bus_names() throw()
{
  vector<string> buses;
  buses.push_back("registers");
  return buses;
}

sid::bus*
Timer::find_bus(const string& name) throw()
{
  if (name == "registers")
    return &bus;
  return 0;
}


sid::bus*
Timer::connected_bus(const string& name) throw()
{
  // No connected buses; return a null pointer.
  return 0;
}


vector<string>
Timer::attribute_names() throw()
{
  // No attributes; return an empty vector.
  return vector<string>();
}

vector<string>
Timer::attribute_names(const string& category) throw()
{
  // No attributes, regardless of category. Return an empty vector.
  return vector<string>();
}

string
Timer::attribute_value(const string& name) throw()
{
  // No attributes--return the empty string for any attribute value.
  return string();
}

sid::component::status
Timer::set_attribute_value(const string& name, const string& value) throw()
{
  // No attributes--return not_found regardless of attribute name.
  return sid::component::not_found;
}


vector<sid::component*>
Timer::related_components(const string& rel) throw()
{
  // No related components.
  return vector<sid::component*>();
}

sid::component::status
Timer::unrelate(const string& rel, sid::component* c) throw()
{
  // No related components; always unfound.
  return sid::component::not_found;
}

sid::component::status
Timer::relate(const string& rel, sid::component* c) throw()
{
  // No related components; always unfound.
  return sid::component::not_found;
}

vector<string>
Timer::relationship_names() throw()
{
  // No relations.
  return vector<string>();
}



void
Timer::drive_interrupt(sid::host_int_4 value)
{
  // Iterate the netlist, driving the value to all pins connected to
  // the interrupt pin.

  for (netlist_t::const_iterator it = intpin_netlist.begin();
       it != intpin_netlist.end();
       it++)
    {
      (*it)->driven(value);
    }
}


// Schedule an event to be delivered at a later time.

void
Timer::schedule(sid::host_int_4 time)
{
  // The scheduler component tests bit 31 of a value carried on its
  // "control" pin.  If this bit is set, the event will be delivered
  // routinely at the specified interval.  Otherwise, the event will
  // only occur once.

  assert ((time & 0x80000000) == 0);
  assert ((time & 0x7FFFFFFF) != 0);
  
  if (scheduler_pin)
    scheduler_pin->driven(0x80000000 | time);
}


// Cancel any pending event.

void
Timer::cancel()
{
  // Cancel the event by driving a zero value to the scheduler.

  if (scheduler_pin)
    scheduler_pin->driven(0);
}


// Reset the schedule, in case the timer's enable or divisor registers
// have been altered.

void
Timer::reset_schedule()
{
  cancel();
  
  if (!enabled)
    return;
  
  assert (prescale <= 2);
  unsigned divisor = 1 << (prescale * 4);
  
  schedule(divisor);
}


// Handle 32-bit (little endian) reads.
// If the address is not 32-bit aligned or does not match any register
// address, return an error.

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::little_int_4& data) throw()
{
  if (addr % 4 != 0)
    return sid::bus::misaligned;
  
  switch (addr)
    { 
    case 0x0:
      data = timer->load_value;
      break;
      
    case 0x4:
      data = timer->counter;
      break;
      
    case 0x8:
      data =
	(timer->enabled << 7) | 
	(timer->mode << 6) | 
	(timer->prescale << 2);
      break;
      
    case 0xC:
      break;
      
    default:
      return sid::bus::unmapped;
    }

  return sid::bus::ok;
}


// Handle 32-bit (big endian) reads.
// Just do a little endian read and rearrange the result.

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::big_int_4& data) throw()
{
  sid::little_int_4 le_data;
  sid::bus::status st = read(addr, le_data);
  data.set_target_memory_value (le_data.target_memory_value ());
  return st;
}


// Handle 32-bit (little endian) writes.
// If the address is not 32-bit aligned or does not match any register
// address, return an error.

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::little_int_4 data) throw()
{
  if (addr % 4 != 0)
    return sid::bus::misaligned;
  
  switch (addr)
    {
    case 0x0:
      // A write to LOAD_REG.
      // Clear top 16 bits when loading a new value.
      timer->load_value = data & 0xFFFF;
      // Reset the counter value.
      timer->counter = timer->load_value;
      break;

    case 0x4:
      break;

    case 0x8:
      // A write to CTL_REG.
      timer->prescale = (data & 0x0C) >> 2;
      timer->enabled = ((data & 0x80) == 0x80);
      timer->mode = (data & 0x40) ? PERIODIC : FREERUNNING;
      timer->reset_schedule();
      break;

    case 0xC:
      timer->drive_interrupt(0);
      break;

    default:
      return sid::bus::unmapped;
    }

  return sid::bus::ok;
}


// Handle 32-bit (big endian) writes.
// Just rearrange the data and do a little endian write.

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::big_int_4 data) throw()
{
  sid::little_int_4 le_data;
  le_data.set_target_memory_value (data.target_memory_value ());
  return write(addr, le_data);
}

// For simplicity, bus accesses that are not 32-bits wide are not
// handled.  Ideally, different widths should be handled sensibly.
// For example, a one-byte write to location n+1, where n is 32-bit
// aligned, should behave as you might expect.

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::little_int_1& data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::big_int_1& data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::little_int_2& data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::big_int_2& data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::little_int_8& data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::read(sid::host_int_4 addr, sid::big_int_8& data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::little_int_1 data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::big_int_1 data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::little_int_2 data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::big_int_2 data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::little_int_8 data) throw()
{
  return sid::bus::unpermitted;
}

sid::bus::status
Timer::register_bus::write(sid::host_int_4 addr, sid::big_int_8 data) throw()
{
  return sid::bus::unpermitted;
}

// Called when the scheduled event arrives.
// Decrement the counter register and check for an interrupt
// condition--and if so, drive the interrupt pin.

void
Timer::tick()
{
  if (!enabled) return;
  
  counter--;
  if (counter == 0)
    {
      if (mode == PERIODIC)
	{
	  counter = load_value;
	  drive_interrupt(1);
	}
      else
	{
	  // Rolls over from maximum value; no interrupts.
	  counter = 0xFFFF;
	}
    }
}


// Return a list of component types supported by this library.

static vector<string>
TimerListTypes()
{
  vector<string> types;
  types.push_back("hw-timer-example");
  return types;
}

// Instantiate a component, given a specified component type.

static sid::component*
TimerCreate(const string& typeName)
{
  if (typeName == "hw-timer-example")
    return new Timer();

  return 0;
}

// Destruct a component instance.

static void
TimerDelete(sid::component* c)
{
  delete dynamic_cast<Timer*>(c);
}


} // end namespace


// This symbol is used by the library loader to validate the library
// and instantiate components of the types supported by this library.

DLLEXPORT extern const sid::component_library example_component_library;

const sid::component_library example_component_library =
{
  sid::COMPONENT_LIBRARY_MAGIC,
  &timer_example::TimerListTypes,
  &timer_example::TimerCreate,
  &timer_example::TimerDelete
};
