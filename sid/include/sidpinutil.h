// sidpinutil.h - various implementations of pins.  They include input
// pins and outputs (== lists of others' input pins), and mixtures of
// these.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDPINUTIL_H
#define SIDPINUTIL_H

#include <sidconfig.h>
#include <sidcomp.h>
#include <sidtypes.h>
#include <iostream>

#include <vector>
#include <algorithm>
#include <map>
#include <cassert>


namespace sidutil
{

  // An input_pin just tracks the last driven value.
  class input_pin : public sid::pin
  {
  public:
    input_pin (): value (0) {}
    
    sid::host_int_4
    sense () const
      {
	return this->value; 
      }
    
    void
    driven (sid::host_int_4 v) 
      throw ()
      {
	this->value = v;
      }
    
  protected:
    friend std::ostream& operator << (std::ostream& o, const input_pin& p);
    friend std::istream& operator >> (std::istream& i, input_pin& p);
    sid::host_int_4 value;
  };

  inline std::ostream& 
  operator << (std::ostream& o, const input_pin& p)
{
  o << p.value;
  return o;
}

  inline std::istream& 
  operator >> (std::istream& i, input_pin& p)
{
  i >> p.value;
  return i;
}
  


  // The output_pin maintains a list of connected pins.  It provides a
  // network connection and drive() API.  It trades off complicated
  // setup/configuration logic for fast run-time drive logic. 
  class output_pin
  {
    // a helper: use when number-of-outputs = 0
    class empty_output: public sid::pin
    {
      void driven (sid::host_int_4) throw () {}
    };


    // another helper: use when number-of-outputs > 1
    class list_output: public sid::pin
    {
    typedef std::vector<sid::pin*> pin_list_t;
    pin_list_t neighbours;
    
    public:
      // Propagate value to list of outputs.
      void
      driven (sid::host_int_4 v) throw()
	{
	  for (pin_list_t::iterator it = this->neighbours.begin ();
	      it != this->neighbours.end ();
	      it++)
	    {
	      (*it)->driven (v);
	    }
	}
      
      // Add given pin to output list.  Return not ::ok if duplicate.
      sid::component::status
      connect (sid::pin* p)
	{
	  assert (p != 0);

	  pin_list_t::iterator where = find (this->neighbours.begin (), 
					     this->neighbours.end (), p);
	  if (where == this->neighbours.end ())
	    {
	      this->neighbours.push_back (p);
	      return sid::component::ok;
	    }

	  return sid::component::bad_value;
	}
      

      // Disconnects pin p from output pin. Returns ok if successful.
      sid::component::status
      disconnect (sid::pin* p)
	{
	  assert (p != 0);

	  pin_list_t::iterator where = find (this->neighbours.begin (), 
					     this->neighbours.end (), p);
	  
	  if (where != this->neighbours.end ()) 
	    {
	      this->neighbours.erase (where);
	      return sid::component::ok;
	    }
	  else
	    {
	      return sid::component::bad_value;
	    }
	}
      
      // Return a copy of the output pins list
      std::vector<sid::pin*> 
      connections () const
	{
	  return /* copy of */ this->neighbours;
	}

      sid::pin*
      lone_connection () const
	{
	  assert (this->neighbours.size() == 1);
	  return this->neighbours[0];
	}
    };

  protected:
    // Clever polymorphic pointer is optimized for single output case
    unsigned num_outputs;     // 0/1/many
    sid::pin* output;         // always valid!
    empty_output output_nop;
    list_output output_list;
    sid::host_int_4 value;    // last value sent out via drive()

    friend std::ostream& operator << (std::ostream& o, const output_pin& p);
    friend std::istream& operator >> (std::istream& i, output_pin& p);

  public:
    output_pin ()
      {
	this->num_outputs = 0;
	this->output = & this->output_nop;
	this->value = 0;
      }
      
    ~output_pin ()
      {
	if (this->num_outputs == 0)
	  {
	    assert (this->output == & this->output_nop);
	  }
	else if (this->num_outputs == 1)
	  {
	    ; // do nothing - this is someone else's input pin
	  }
	else // if (this->num_outputs > 1)
	  {
	    assert (this->output == & this->output_list);
	  }
      }


    sid::host_int_4
    recall () const 
      {
	return this->value; 
      }

    void
    drive (sid::host_int_4 v)
      {
	// `output' is always valid, no need to check it
	this->value = v;
	this->output->driven (v);
      }
      

    // Connects new given pin to output pin.  Ignore if duplicate.
    sid::component::status
    connect (sid::pin* p)
      {
	assert (p != 0);

	// add and check for duplicates
	assert (this->num_outputs == this->output_list.connections ().size ());
	sid::component::status s = this->output_list.connect (p);
	if (s != sid::component::ok)
	  return s;

	// maintain shortcut pointer
	this->num_outputs ++;
	if (this->num_outputs == 1)
	  this->output = p;
	else // if (this->num_outputs > 1)
	  this->output = & this->output_list;

	return sid::component::ok;
      }
    
      
    // Disconnects given pin from output list. Returns ok if successful.
    sid::component::status
    disconnect (sid::pin* p)
      {
	assert (p != 0);

	// remove and check for duplicates
	assert (this->num_outputs == this->output_list.connections ().size ());
	sid::component::status s = this->output_list.disconnect (p);
	if (s != sid::component::ok)
	  return s;

	this->num_outputs --;
	if (this->num_outputs == 0)
	  this->output = & this->output_nop;
	else if (this->num_outputs == 1)
	  this->output = this->output_list.lone_connection ();
	else // if (this->num_outputs > 1)
	  this->output = & this->output_list;

	return sid::component::ok;
      }

      
      // Returns vector of all connected pins to output pin
      std::vector<sid::pin*> 
      connections () const
	{
	  assert (this->num_outputs == this->output_list.connections().size());
	  return /* copy of */ this->output_list.connections ();
	}
    };

  inline std::ostream& 
  operator << (std::ostream& o, const output_pin& p)
{
  o << p.value;
  return o;
}

  inline std::istream& 
  operator >> (std::istream& i, output_pin& p)
{
  i >> p.value;
  return i;
}



  // An inputoutput_pin is both.  A virtual member function specifies
  // the directionality at any given time, for purposes of attribute
  // generation.
  class inputoutput_pin: public input_pin, public output_pin
  {
  public:
    virtual bool input_mode_p () const = 0;
    virtual input_pin* input () { return this; }
    virtual const input_pin* input () const { return this; }
    virtual output_pin* output () { return this; }
    virtual const output_pin* output () const { return this; }

  protected:
    friend std::ostream& operator << (std::ostream& o, const input_pin& p);
    friend std::istream& operator >> (std::istream& i, input_pin& p);
  };

  inline std::ostream& 
  operator << (std::ostream& o, const inputoutput_pin& p)
{
  o << *p.output() << " " << *p.input();
  return o;
}

  inline std::istream& 
  operator >> (std::istream& i, inputoutput_pin& p)
{
  i >> *p.output() >> *p.input();
  return i;
}



  // Following class overwrites pin interface methods defined in
  // abstract class component.
  class fixed_pin_map_component: public virtual sid::component
    {
    private:
      typedef std::map<std::string,input_pin*> in_pin_map_t;
      typedef std::map<std::string,output_pin*> out_pin_map_t;
      mutable in_pin_map_t input_pins;
      mutable out_pin_map_t output_pins;
      
    protected:
      // Override this function so virtual output pins may be
      // manufactured on demand.
      virtual sid::component::status 
      pin_factory (const std::string& name)
	{
	  // Fail by default.
	  return sid::component::not_found;
	}
      
      // Override this function so virtual output pins may be
      // cleaned up on demand.
      virtual void
      pin_junkyard (const std::string& name) {}
      
      // Adds input pin to component
      void add_pin (const std::string& name, input_pin* pin)
      {
	assert (pin != 0);
	assert (this->input_pins.find(name) == this->input_pins.end());
	this->input_pins[name] = pin;
      }
      
      // Adds output pin to component.
      void add_pin (const std::string& name, output_pin* pin)
      {
	assert (pin != 0);
	assert (this->output_pins.find(name) == this->output_pins.end());
	this->output_pins[name] = pin;
      }

      // Add input-output pair in one gulp
      void
      add_pin (const std::string& name, inputoutput_pin* iopin)
      {
	add_pin (name, iopin->input());
	add_pin (name, iopin->output());
      }
      void
      add_pin (const std::string& name, input_pin* ipin, output_pin* opin)
      {
	add_pin (name, ipin);
	add_pin (name, opin);
      }
      void
      add_pin (const std::string& name, output_pin* opin, input_pin* ipin)
      {
	add_pin (name, ipin);
	add_pin (name, opin);
      }
      
      // Removes pin specified by arg. name from component.
      void remove_pin (const std::string& name)
	{
	  this->input_pins.erase (name);
	  this->output_pins.erase (name);
	}
      
    public:
      // Return the names of all known pins (input & output)
      std::vector<std::string>
      pin_names () throw ()
	{
	  std::vector<std::string> names;

	  for (out_pin_map_t::const_iterator out_it= this->output_pins.begin ();
	      out_it != this->output_pins.end (); 
	      out_it++) 
	    {
	      names.push_back (out_it->first);
	    }
	  
	  for (in_pin_map_t::const_iterator in_it = this->input_pins.begin (); 
	      in_it != this->input_pins.end (); 
	      in_it++) 
	    {
	      // XXX: test for duplicates!
	      names.push_back (in_it->first);
	    }
	  
	  return names;
	}

      
      // Returns pointer to pin name provided pin is connected to
      // component otherwise method returns 0 (null pointer).
      sid::pin*
      find_pin (const std::string& name) throw ()
	{
	  in_pin_map_t::iterator in_it = this->input_pins.find (name);
	  if (in_it != this->input_pins.end ())
	    return in_it->second;

	  return 0;
	}

      
      // Connect given pin from my named output.
      sid::component::status
      connect_pin (const std::string& name, sid::pin* pin) throw ()
	{
	  // kick out null pointers
	  if (pin == 0)
	    return sid::component::bad_value;

	  out_pin_map_t::iterator it = this->output_pins.find (name);
	  if (it == this->output_pins.end ())
	    {
	      // try the factory function
	      sid::component::status whither = this->pin_factory (name);
	      if (whither != sid::component::ok)
		return whither;
	    }
	  
	  // try looking again
	  it = this->output_pins.find (name);
	  if (it != this->output_pins.end ())
	    {
	      return it->second->connect (pin);
	    }
	  
	  return sid::component::not_found;
	}

      
      // Disconnect given pin from my named output.
      sid::component::status
      disconnect_pin (const std::string& name, sid::pin* pin) throw ()
	{
	  // kick out null pointers
	  if (pin == 0)
	    return sid::component::bad_value;

	  out_pin_map_t::iterator it = this->output_pins.find (name);
	  if (it != this->output_pins.end ()) 
	    {
	      sid::component::status stat_val = it->second->disconnect (pin);
	      
	      // If this output_pin is now an orphan, inform the pin_junkyard.
	      // It may want to remove it.
	      if (it->second->connections ().size () == 0)
		this->pin_junkyard (name);
	      
	      return stat_val;
	    }
	  return sid::component::not_found;
	}
      
      // Returns a vector of all connected pins to output pin name.
      std::vector<sid::pin*>
      connected_pins (const std::string& name) throw ()
	{
	  out_pin_map_t::const_iterator it = this->output_pins.find (name);
	  if (it != this->output_pins.end ())
	    return it->second->connections ();
	  
	  return std::vector<sid::pin*> ();
	}
    };
  
  
  // The callback_pin calls a member function of a template class for
  // each pin event.  There are separate callback functions for
  // value-carrying and non-value-carrying events.  If only one is set,
  // then it will be called for events of the other type.
  template <class Receiver>
  class callback_pin: public input_pin
  {
  protected:
    Receiver* receiver;
    void (Receiver::*pmf) (sid::host_int_4);
    
  public:
    callback_pin (Receiver* r, void (Receiver::*m) (sid::host_int_4)):
      receiver (r), pmf (m) 
      {
	assert (this->receiver != 0);
	assert (this->pmf != 0);
      }
    
    // Call configured pointer-to-member-function.
    void
    driven (sid::host_int_4 v) 
      throw ()
      { 
	input_pin::driven (v);
	(receiver->*pmf) (v); 
      }
    
    // Change the callback routine.
    void set_callback (void (Receiver::*m1) (sid::host_int_4))
      {
	this->pmf = m1;
	assert (this->pmf != 0);
      }
  };
  
  // Binary Pins
  // binary_input_pin, and binary_output_pin classes provide
  // extra interface to represent binary pins (input or output)
  // for sending signals from and to device.
  
  enum binary_pin_state {
    binary_pin_tristated = -1,
    binary_pin_inactive	= 0,
    binary_pin_active = 1
    };
  
  
  class binary_input_pin : public input_pin {
  public:
    // default is active low
    binary_input_pin ()		{ is_active_high = false; }
    
    // constructor to set active_high or low
    void set_active_high ()	{ is_active_high = true; }
    
    bool active_high () const	{ return is_active_high; }
    
    // Returns whether pin is active, inactive, or tristated depending
    // upon value on pin as well as wether pin is logically active
    // high or active low. 
    binary_pin_state state () const
      {
	if (this->active_high ()) {
	  switch (this->value) {
	  case 0: return binary_pin_inactive;
	  case 1: return binary_pin_active;
	  default: break;
	  }
	}
	else {
	  switch (this->value) {
	  case 0: return binary_pin_active;
	  case 1: return binary_pin_inactive;
	  default: break;
	  }
	}
	return binary_pin_tristated;
      }
    
  protected:
    bool is_active_high;
  };
  
  
  // Binary output pin class 
  class binary_output_pin : public output_pin {
  public:
    // default is active low
    binary_output_pin () { is_active_high = false; }

    // constructor to set active_high or low
    void set_active_high ()	{ is_active_high = true; }

    bool active_high () const	{ return is_active_high; }

    // Makes output pin in "active" state and drives all connected pins to it.
    void on ()
      {
	if (this->active_high ())
	  // binary_pin_state::active
	  this->value = 1; 
	else
	  this->value = 0;

	this->drive (this->value);
      }
    
    // Brings o/p pin in "inactive" state and drives all pins connected to it
    void off () {
      if (this->active_high ())
	this->value = 0;
      else
	this->value = 1;

      this->drive (this->value);
    }


    // Set output pin to active state if argument is true (!= 0).
    void set (int true_false)
      {
	if (this->active_high ())
	  this->value = (true_false) ? 1 : 0;
	else
	  this->value = (true_false) ? 0 : 1;
	this->drive (this->value);
      }

  protected:
    bool is_active_high;
  };
}

#endif // SIDPINUTIL_H
