// sidpinattrutil.h - Classes for generating attributes which reflect
// the sense of pins.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDPINATTRUTIL_H
#define SIDPINATTRUTIL_H

#include <sidconfig.h>

#include <sidattrutil.h>
#include <sidpinutil.h>

namespace sidutil 
{
  // Attribute coders for various pin types.
  // Usage:
  //   type pin;
  //   add_attribute( "pin-name", &pin );

  // Attribute coder for type input_pin. Default is base 10 in and
  // out.

  inline std::string
  make_attribute( const input_pin& pin )
    {
      return sidutil::make_attribute( pin.sense() );
    }

  inline sid::component::status
  parse_attribute( const std::string& str, input_pin& pin )
    {
      sid::host_int_4 v;
      sid::component::status s = sidutil::parse_attribute( str, v );
      if( s != sid::component::ok )
	return s;
      pin.driven( v );
      return sid::component::ok;
    }


  // Commonly used input_pin relatives

  template <class Callee>
  inline std::string
  make_attribute( const callback_pin<Callee>& pin )
    {
      return make_attribute( * (input_pin*) &pin);

    }
  template <class Callee>  
  inline sid::component::status
  parse_attribute( const std::string& str, callback_pin<Callee>& pin )
    {
      return parse_attribute( str, * (input_pin*) &pin);
    }

    
  // Attribute coder for type output_pin. Default is base 10 in and
  // out.
 
  inline std::string
  make_attribute( const output_pin& pin )
    {
      return sidutil::make_attribute( pin.recall() );
    }

  inline sid::component::status
  parse_attribute( const std::string& str, output_pin& pin )
    {
      sid::host_int_4 v;
      sid::component::status s = sidutil::parse_attribute( str, v );
      if( s != sid::component::ok )
	return s;
      pin.drive( v );
      return sid::component::ok;
    }


  // Attribute coder for type inputoutput_pin. Default is base 10 in
  // and out.   Uses input_mode_p() to pick input-side or output-side
  // conversion.

  inline std::string
  make_attribute( const inputoutput_pin& pin )
    {
      if (pin.input_mode_p())
	return sidutil::make_attribute( * pin.input() );
      else
	return sidutil::make_attribute( * pin.output() );
    }

  inline sid::component::status
  parse_attribute( const std::string& str, inputoutput_pin& pin )
    {
      if (pin.input_mode_p())
	return sidutil::parse_attribute( str, * pin.input() );
      else
	return sidutil::parse_attribute( str, * pin.output() );
    }


  // Attribute coder for a binary_input_pin. `attribute_value(
  // "pin-name" )' returns "on" or "off" and is sensitive to whether
  // the pin is active high or active low. For `set_attribute_value(
  // "pin-name", val )', val can be "on" or "off", which is again
  // sensitive to whether the pin is active high or low. The method
  // also accepts "1" and "0", which are absolute, ie. they override
  // the active high/low sense of the pin.
  
  inline std::string
  make_attribute( const binary_input_pin& pin )
    {
      switch( pin.state())
	{
	case sidutil::binary_pin_active:
	  return "on";
	case sidutil::binary_pin_inactive:
	  return "off";
	default:
	  return "tri-stated";
	}
    }
  
  inline sid::component::status
  parse_attribute( const std::string& str, binary_input_pin& pin )
    {
      if (str == "on")
	{
	  if (pin.active_high())
	    pin.driven( 1 ); // binary_pin_state::active
	  else
	    pin.driven( 0 );
	  
	  return sid::component::ok;
	}
      
      if (str == "off" ) {
	if( pin.active_high() )
	  pin.driven( 0 ); // binary_pin_state::inactive
	else
	  pin.driven( 1 );
	
	return sid::component::ok;
    }
      
      if( str == "1" ) {
	pin.driven( 1 );
	return sid::component::ok;
      }
      
      if( str == "0" ) {
	pin.driven( 0 );
	return sid::component::ok;
      }
      
      return sid::component::bad_value;
    }


  // Attribute coder for a binary_output_pin. `attribute_value(
  // "pin-name" )'  returns "on" or "off" and is sensitive to whether
  // the pin is active high or active low. For `set_attribute_value(
  // "pin-name", val )', val can be "on" or "off", which is again
  // sensitive to whether the pin is active high or low. The method
  // also accepts "1" and "0", which are absolute, ie. they over-ride
  // the active high/low sense of the pin.
 
  inline std::string
  make_attribute( const binary_output_pin& pin )
    { 
      if (pin.active_high())
	{
	  switch(pin.recall())
	    {
	    case 1:
	      return "on";
	    case 0:
	      return "off";
	    default:
	      return "tri-stated";
	    }
	}
      else
	{
	  switch(pin.recall())
	    {
	    case 0:
	      return "on";
	    case 1:
	      return "off";
	    default:
	      return "tri-stated";
	    }
	}
    }
  
  inline sid::component::status
  parse_attribute( const std::string& str, binary_output_pin& pin )
    {
      if (str == "on")
	{
	  pin.on();
	  return sid::component::ok;
	}
      if (str == "off")
	{
	  pin.off();
	  return sid::component::ok;
	}
      if (str == "1")
	{
	  pin.drive(1);
	  return sid::component::ok;
	}
      if (str == "0")
	{
	  pin.drive(0);
	  return sid::component::ok;
	}
      return sid::component::bad_value;
    }

} // end namespace

#endif // SIDPINATTRUTIL_H
