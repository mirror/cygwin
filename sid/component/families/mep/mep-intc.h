// mep-intc.h - The Toshiba MeP configurable interrupt controller.
// -*- C++ -*-

// Copyright (C) 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_INTC_H
#define MEP_INTC_H

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::endl;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_4;
using sid::big_int_1;
using sid::big_int_4;
// using sid::component_library;
// using sid::COMPONENT_LIBRARY_MAGIC;

using namespace sid;
using namespace sidutil;

// Forward declarations.
template <typename DataType> class isr_control_register;
class mep_intc;

template <typename DataType>
class updating_control_register_bus: 
public control_register_bus <DataType>
{
public:
  updating_control_register_bus (mep_intc *whom)
    : host (whom)
    {}
  virtual void post_access_hook();
 private:
  mep_intc *host;
};

class interrupt_pin;

class mep_intc: public virtual component,
		protected fixed_attribute_map_component,
		protected fixed_bus_map_component,
		protected fixed_pin_map_component,
		protected no_accessor_component,
		protected no_relation_component
{
  friend class interrupt_pin;

public:
  mep_intc (unsigned num_channels);
  ~mep_intc () throw ();
  void update_state ();
  
private:
  enum { max_channels = 32 };
  unsigned num_channels;
  unsigned cfg_interrupt_level;
  bool have_irq;

  void interrupt_source_driven (host_int_4 value, host_int_4 channel);
  void reset (host_int_4 ignored = 0);
  
  output_pin interrupt_out_pin;
  callback_pin<mep_intc> reset_pin;
  interrupt_pin* interrupt_sources[max_channels];

  string interrupt_names[max_channels];

  component::status nop (const string& unused) {}
  string make_bit_register_attr (value_control_register<big_int_4>** ptr);
  string make_nybble_register_attr (value_control_register<big_int_4>** ptr);
  
  string get_isr ();
  string get_ier ()  { return make_bit_register_attr (ier); }
  string get_iet ()  { return make_bit_register_attr (iet); }
  string get_ilr0 () { return make_nybble_register_attr (&ilr[0]); }
  string get_ilr1 () { return make_nybble_register_attr (&ilr[8]); }
  string get_ilr2 () { return make_nybble_register_attr (&ilr[16]); }
  string get_ilr3 () { return make_nybble_register_attr (&ilr[24]); }

  updating_control_register_bus<big_int_4> registers;

  ro_value_control_register<big_int_4> interrupt_level;
  value_control_register<big_int_4>    interrupt_mask_level;
  ro_value_control_register<big_int_4> interrupt_channel_num;
  ro_value_control_register<big_int_4> ivr_reserved;
  isr_control_register<big_int_4>*     isr[max_channels];
  value_control_register<big_int_4>*   ier[max_channels];
  value_control_register<big_int_4>*   iet[max_channels];
  value_control_register<big_int_4>*   ilr[max_channels];
};

template <typename DataType>
void
updating_control_register_bus<DataType>::post_access_hook() 
{
  assert (host);
  host->update_state ();
}

template <typename DataType>
class isr_control_register: public value_control_register<DataType>
{
 public:
  isr_control_register (control_register_bank<DataType>* b,
			sid::host_int_4 o,
			DataType m,
			DataType v,
			value_control_register<big_int_4>* iet_reg):
    value_control_register<DataType> (b,o,m,true,true,v),
    iet (iet_reg)
    {}
  
  isr_control_register (control_register_bank<DataType>* b,
			sid::host_int_4 o,
			DataType m,
			value_control_register<big_int_4>* iet_reg):
    value_control_register<DataType> (b,o,m,true,true,0),
    iet (iet_reg)
    {}
  
  void operator = (const DataType& v)
    {
      DataType shifted_v = v << this->shift_amount ();
      value_control_register<DataType>::set (shifted_v, this->get_mask ()); 
    }
  
 protected:
  void set (DataType set_value, DataType set_mask)
    {
      // Allow setting edge-triggered channels only.
      if (*iet)
	// Allow setting this register to 0, but no other value.
	if (set_value == 0)
	  value_control_register<DataType>::set (set_value, set_mask);
    }
  
 private:
  value_control_register<big_int_4>* iet;
};

class interrupt_pin: public input_pin
{
public:
  interrupt_pin (host_int_4 pos, mep_intc* whom, void (mep_intc::*fp) (host_int_4, host_int_4))
    :bit_num (pos), host (whom), driveit (fp) { }
  
  void driven (host_int_4 value) throw ()
  {
    // Expose last value to attribute code.
    input_pin::driven (value);
    return (host->*driveit) (bit_num, value);
  }
  
private:
  mep_intc* host;
  host_int_4 bit_num;
  void (mep_intc::*driveit) (host_int_4 pos, host_int_4 val);
};

#endif // MEP_INTC_H
