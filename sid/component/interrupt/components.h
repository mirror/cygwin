// components.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>

#include <vector>
#include <string>

#if HAVE_SSTREAM
  #include <sstream>
#elif HAVE_STRSTREAM_H
  #include <strstream.h>
#else
  #error "need <sstream> or <strstream.h>!"
#endif

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::endl;

using sid::component;
using sid::bus;
using sid::host_int_4;
using sid::little_int_4;
using sid::host_int_1;
using sid::little_int_1;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_attribute_map_component;
using sidutil::no_relation_component;
using sidutil::no_accessor_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::no_bus_component;
using sidutil::make_attribute;
using sidutil::make_numeric_attribute;
using sidutil::parse_attribute;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::input_pin;
using sidutil::std_error_string;
using sidutil::callback_word_bus;
using sidutil::word_bus;
using sidutil::self_watcher;

//
// The IntController class defines the high level interface to an
// interrupt controller and should be generic enough to work for
// any interrupt controller (if not, extend it).
//
template <class foo> class IntController;
template <class foo> istream& operator>> (istream& ip, IntController<foo>& ovwrite_obj);
template <class foo> ostream& operator<< (ostream& op, const IntController<foo>& copy_obj);
 
template<class bus_size> class IntController:
	public virtual component, 
	protected fixed_attribute_map_component,
	protected fixed_bus_map_component,
	protected fixed_pin_map_component,
	protected no_accessor_component,
	protected no_relation_component
{
public:

  IntController<bus_size>(host_int_4 num_irq = 0,
			  host_int_4 num_fiq = 0,
			  host_int_4 ctrlr_features = 0);
  virtual ~IntController<bus_size>() throw () { }
  
private:
  class interrupt_bus: public word_bus<bus_size>
  {
  public:
    interrupt_bus (IntController<bus_size> *who,
      sid::bus::status (IntController<bus_size>::*rd)
        (host_int_4, bus_size, bus_size&),
      sid::bus::status (IntController<bus_size>::*wr)
        (host_int_4, bus_size, bus_size)):
	  host(who), read(rd), write(wr) { }
  
    ~interrupt_bus() throw () { }
  
    sid::bus::status word_write
      (host_int_4 addr, bus_size mask, bus_size data)
	{ return ((host->*write)(addr, mask, data)); }
  
    sid::bus::status word_read
      (host_int_4 addr, bus_size mask, bus_size& data)
	{ return (host->*read)(addr, mask, data); }
  
  private:
    IntController<bus_size> *host;
  
    sid::bus::status (IntController<bus_size>::*read)
      (host_int_4 addr, bus_size mask, bus_size& data);
    sid::bus::status (IntController<bus_size>::*write)
      (host_int_4 addr, bus_size mask, bus_size data);
  };
  friend class interrupt_bus;

  class interrupt_lines: public input_pin
  {
  public:
  
    interrupt_lines(host_int_4 pos, IntController<bus_size>* who,
      void (IntController<bus_size>::*fp) (host_int_4, host_int_4)):
  		     bit_num(pos), host(who), driveit(fp) { }
  
    ~interrupt_lines() throw ()
      { host = NULL; driveit = NULL; }
  
    void driven(host_int_4 value) throw ()
      {
        // expose last value to attribute code
        input_pin::driven(value);

	return (host->*driveit)(value, bit_num);
      }
  
  private:
    IntController<bus_size> *host;
    host_int_4 bit_num;
  
    void (IntController<bus_size>::*driveit)
      (host_int_4 pin_val, host_int_4 pos);
  };
  friend class interrupt_lines;
 
protected:

  // internals

  host_int_4 irq_pending;
  host_int_4 irq_enabled;

  host_int_4 fiq_pending;
  host_int_4 fiq_enabled;

  interrupt_bus irq_bus;
  interrupt_bus fiq_bus;

  vector<interrupt_lines*> irq_lines;
  vector<interrupt_lines*> fiq_lines;

  output_pin irq_pin;
  output_pin fiq_pin;

  // note that the reset_pin may not exist
  callback_pin<IntController<bus_size> > reset_pin;

  friend class self_watcher<IntController<bus_size> >;
  self_watcher<IntController<bus_size> > triggerpoint_manager;

  // virtual methods for reading/writing/driving the IRQ's
  virtual sid::bus::status irq_read_word
    (host_int_4 addr, bus_size mask, bus_size& data) = 0;
  virtual sid::bus::status irq_write_word
    (host_int_4 addr, bus_size mask, bus_size data) = 0;

  virtual sid::bus::status fiq_read_word
    (host_int_4 addr, bus_size mask, bus_size& data) 
      { return sid::bus::unmapped; }
  virtual sid::bus::status fiq_write_word
    (host_int_4 addr, bus_size mask, bus_size data)
      { return sid::bus::unmapped; }

  virtual void irq_src_driven (host_int_4 driven_val, host_int_4 bit_num) = 0;
  virtual void fiq_src_driven (host_int_4 driven_val, host_int_4 bit_num) {}

  enum { INTR_INACTIVE = 1, INTR_ACTIVE = 0 };

  virtual void drive_irq_interrupts();
  virtual void drive_fiq_interrupts();
  virtual void drive_interrupts();
  virtual void reset(host_int_4 reset_val);

  sid::component::status
  pin_factory(const string& name)
    { return this->triggerpoint_manager.create_virtual_pin(name); }

  void
  pin_junkyard(const string& name)
    { this->triggerpoint_manager.destroy_virtual_pin(name); }

  enum {
    RSTPIN =  0x01,
    FIQREGS = 0x02,
    FIQBUS =  0x04
  };
  host_int_4 features;

private:
  string save_state()
    { return make_attribute (*this); }

  sid::component::status restore_state(const string& state)
    { return parse_attribute(state, *this); }

  friend ostream& operator<< <> (ostream& op, const IntController<bus_size>& copy_obj);
  friend istream& operator>> <> (istream& ip, IntController<bus_size>& ovwrite_obj);
};


// functions in template class

template<class bus_size>
IntController<bus_size>::IntController<bus_size>
  (host_int_4 num_irq,
   host_int_4 num_fiq,
   host_int_4 ctrlr_features):
	irq_bus(this, &IntController<bus_size>::irq_read_word,
		&IntController<bus_size>::irq_write_word),
	fiq_bus(this, &IntController<bus_size>::fiq_read_word,
		&IntController<bus_size>::fiq_write_word),
	irq_enabled(0), irq_pending(0),
	fiq_enabled(0), fiq_pending(0),
	reset_pin(this, &IntController<bus_size>::reset),
	features(ctrlr_features),
	triggerpoint_manager(this)
{
  if (features & RSTPIN)
    {
      add_pin("reset", &reset_pin);
      add_attribute("reset", &reset_pin, "pin");
      triggerpoint_manager.add_watchable_attribute("reset");
      categorize("reset", "watchable");
    }
  
  add_bus("irq-registers", &irq_bus);
  if (features & FIQBUS)
    add_bus("fiq-registers", &fiq_bus);
  
  add_pin("interrupt", &irq_pin);
  add_attribute("interrupt", &irq_pin, "pin");
  triggerpoint_manager.add_watchable_attribute("interrupt");
  categorize("interrupt", "watchable");
  
  if (features & FIQREGS)
    {
      add_pin("fast-interrupt", &fiq_pin);
      add_attribute("fast-interrupt", &fiq_pin, "pin");
      triggerpoint_manager.add_watchable_attribute("fast-interrupt");
      categorize("fast-interrupt", "watchable");
    }
  
  interrupt_lines* tmpline = NULL;
  string tmpstr = "";
  
  for (unsigned i = 0; i < num_irq; ++i)
    {
      tmpline = new interrupt_lines (i, this,
	&IntController<bus_size>::irq_src_driven);
      irq_lines.push_back(tmpline);
      if (num_irq == 1)
        tmpstr = "interrupt-source";
      else
        tmpstr = "interrupt-source-" + make_numeric_attribute(i);
      add_pin(tmpstr, irq_lines[i]);
      add_attribute(tmpstr, static_cast<input_pin*>(irq_lines[i]), "pin");
      triggerpoint_manager.add_watchable_attribute(tmpstr);
      categorize(tmpstr, "watchable");

      tmpline = NULL;
      tmpstr = "";
    }

  for (unsigned i = 0; i < num_fiq; ++i)
    {
      tmpline = new interrupt_lines (i, this,
	&IntController<bus_size>::fiq_src_driven);
      fiq_lines.push_back(tmpline);
      if (num_fiq == 1)
        tmpstr = "fast-interrupt-source";
      else
        tmpstr = "fast-interrupt-source-" + make_numeric_attribute(i);
      add_pin(tmpstr, fiq_lines[i]);
      add_attribute(tmpstr, static_cast<input_pin*>(fiq_lines[i]), "pin");
      triggerpoint_manager.add_watchable_attribute(tmpstr);
      categorize(tmpstr, "watchable");

      tmpline = NULL;
      tmpstr = "";
    }

  add_attribute("irq-raw-status", &irq_pending, "register");
  triggerpoint_manager.add_watchable_value("irq-raw-status", &irq_pending);
  categorize("irq-raw-status", "watchable");

  add_attribute("irq-enable-register", &irq_enabled, "register");
  triggerpoint_manager.add_watchable_value("irq-enable-register", &irq_enabled);
  categorize("irq-enable-register", "watchable");

  if (features & FIQREGS)
    {
      add_attribute("fiq-raw-status", &fiq_pending, "register");
      triggerpoint_manager.add_watchable_value("fiq-raw-status", &fiq_pending);
      categorize("fiq-raw-status", "watchable");

      add_attribute("fiq-enable-register", &fiq_enabled, "register");
      triggerpoint_manager.add_watchable_value("fiq-enable-register", &fiq_enabled);
      categorize("fiq-enable-register", "watchable");
    }

  add_attribute_virtual("state-snapshot", this,
			&IntController::save_state,
			&IntController::restore_state);
  
}


template<class bus_size> void
IntController<bus_size>::drive_irq_interrupts()
{
  // irq_pending and irq_enabled are bit masks
  host_int_4 val = (irq_pending & irq_enabled) ? INTR_ACTIVE : INTR_INACTIVE;

  if (val != irq_pin.recall())
    irq_pin.drive(val);

  // Trigger checkpoint.
  triggerpoint_manager.check_and_dispatch();
}


template<class bus_size> void
IntController<bus_size>::drive_fiq_interrupts()
{
  // fiq_pending and fiq_enabled are bit masks
  host_int_4 val = (fiq_pending & fiq_enabled) ? INTR_ACTIVE : INTR_INACTIVE;

  if (val != fiq_pin.recall())
    fiq_pin.drive(val);

  // Trigger checkpoint.
  triggerpoint_manager.check_and_dispatch();
}


template<class bus_size> void
IntController<bus_size>::drive_interrupts()
{ 
  drive_fiq_interrupts();
  drive_irq_interrupts();
}


template<class bus_size> void
IntController<bus_size>::reset(host_int_4 reset_val)
{
  irq_enabled = fiq_enabled = 0;
  drive_interrupts();
}


template<class bus_size>
ostream& operator<< (ostream& op, const IntController<bus_size>& copy_obj)
{
  op << "IRQEnable " << copy_obj.irq_enabled << " ";
  op << "IRQPend "   << copy_obj.irq_pending;
  op << " FIQEnable " << copy_obj.fiq_enabled;
  op << " FIQPend "   << copy_obj.fiq_pending;
  op << endl;
  
  op << "Pins ";
  op << copy_obj.reset_pin << " ";
  op << copy_obj.irq_pin;
  op << " " << copy_obj.fiq_pin;
  
  for (unsigned i = 0; i < copy_obj.irq_lines.size(); i++)
    op << " " << *static_cast<input_pin*>(copy_obj.irq_lines[i]);
  for (unsigned i = 0; i < copy_obj.fiq_lines.size(); i++)
    op << " " << *static_cast<input_pin*>(copy_obj.fiq_lines[i]);
  
  // NB: no whitespace at end!
  
  return op;
}

template <class bus_size>
istream& operator>> (istream& ip, IntController<bus_size>& ovwrite_obj)
{
  string coding;
  
  ip >> coding;
  if (coding != "IRQEnable")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.irq_enabled;
  
  ip >> coding;
  if (coding != "IRQPend")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.irq_pending;	    
  
  ip >> coding;
  if ( coding != "FIQEnable")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.fiq_enabled;
  
  ip >> coding;
  if ( coding != "FIQPend")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.fiq_pending;
  
  ip >> coding;
  if (coding != "Pins" )
    {
      ip.setstate (ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.reset_pin;
  ip >> ovwrite_obj.irq_pin;
  ip >> ovwrite_obj.fiq_pin;
  
  for (unsigned i = 0; i < ovwrite_obj.irq_lines.size(); i++)
    ip >> *static_cast<input_pin*>(ovwrite_obj.irq_lines[i]);
  for (unsigned i = 0; i < ovwrite_obj.fiq_lines.size(); i++)
    ip >> *static_cast<input_pin*>(ovwrite_obj.fiq_lines[i]);
  
  return ip;
}

#endif // COMPONENTS_H
