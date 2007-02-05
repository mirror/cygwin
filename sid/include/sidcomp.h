// sidcomp.h - Define the external interface of a SID component, that
// is, the SID component API expressed in -*- C++ -*-.

// Copyright (C) 1999, 2000, 2001, 2004, 2007 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDCOMP_H
#define SIDCOMP_H

#include <sidtypes.h>

#include <string>
#include <vector>

namespace sid
{
  // PART 0: Basic declarations
  // Together, these numbers describe the API as defined in the
  // abstract sid:: classes.  Every time the API changes, a new number
  // pair needs to be assigned.  These numbers figure in the
  // COMPONENT_LIBRARY_MAGIC mechanism in sidso.h, and prevents
  // interopration attempts with obsolete component objects.

  const unsigned API_MAJOR_VERSION = 3;
  const unsigned API_MINOR_VERSION = 3;

  // PART 1: Buses
  //
  // The abstract class sid::bus defines a function-call oriented
  // model of a hardware data/address/control bus.  It supports a
  // 32-bit address space, and allows reads and writes with data of
  // varying lengths.  The sid::bus class is the slave that provides
  // the data.  A bus accessor is the bus master which requests the
  // data.  One component's bus accessor is connected to another's bus
  // with the connect_accessor() method.

  class bus
  {
  public:
    // status values from read/write calls.
    enum status_t
    {
      ok           = 0x00, // done, no problems
      misaligned   = 0x01, // address misaligned
      unmapped     = 0x02, // address not in mapped range
      unpermitted  = 0x04, // may not read or may not write at address
      busy         = 0x05  // target component is busy
    };

    struct status
    {
      status ()
	:code (ok), latency (0) {}
      status (enum status_t c)
	:code (static_cast<host_int_1>(c)), latency (0) {}
      status (enum status_t c, host_int_2 lat)
	   :code (static_cast<host_int_1>(c)), latency (lat) {}
      operator int() const { return static_cast<int>(code); }

      host_int_1 code;
      host_int_2 latency;
    };


    // These member functions enumerate the Cartesian product of all
    // possible access requests to a bus:
    // {data-endianness} X {addr-width} X {data-width}
    //  little,big         4		   1,2,4,8

    // Write data at given address.

    virtual status write(host_int_4 addr, big_int_1 data) 
      throw () = 0;

    virtual status write(host_int_4 addr, little_int_1 data) 
      throw () = 0;

    virtual status write(host_int_4 addr, big_int_2 data) 
      throw () = 0;

    virtual status write(host_int_4 addr, little_int_2 data) 
      throw () = 0;

    virtual status write(host_int_4 addr, big_int_4 data)
      throw () = 0;

    virtual status write(host_int_4 addr, little_int_4 data)
      throw () = 0;

    virtual status write(host_int_4 addr, big_int_8 data) 
      throw () = 0;

    virtual status write(host_int_4 addr, little_int_8 data)
      throw () = 0;

    // Write data from given address.
    virtual status
    read(host_int_4 addr, big_int_1& data)
      throw () = 0;

    virtual status
    read(host_int_4 addr, little_int_1& data)
      throw()= 0;

    virtual status
    read(host_int_4 addr, big_int_2& data)
      throw () = 0;

    virtual status
    read(host_int_4 addr, little_int_2& data)
      throw()= 0;

    virtual status
    read(host_int_4 addr, big_int_4& data)
      throw () = 0;

    virtual status
    read(host_int_4 addr, little_int_4& data)
      throw()= 0;

    virtual status
    read(host_int_4 addr, big_int_8& data)
      throw () = 0;

    virtual status
    read(host_int_4 addr, little_int_8& data)
      throw()= 0;

  protected:
    bus() {}
    virtual ~bus() {}  
  };

  
  // PART 2: Pins
  //
  // The abstract pin class is one of the methods by which components
  // communicate.  The sid::pin class represents the input side of a
  // pin->pin connection.  Incoming signals are represented by calls
  // on the driven() method.  Outgoing signals may be sent to other
  // components' pins after they are given to a component using the
  // connect_pin() method.

  class pin
  {
  public:
    // A notification that the pin has been driven with some value.
    virtual void driven(host_int_4 value) throw () = 0;

  protected:
    pin() {}
    virtual ~pin() {}
  };
  

  // PART 3: Components
  //
  // The abstract component class is the basic building block of a
  // simulator.  Components are connected together to create complete
  // simulations.  There are several types of connections: pins, buses
  // and relations.

  class component
  {
  public:
    // Status indications for various calls.
    enum status
    {
      ok	= 0,	// successful
      not_found = -1,   // lookup key invalid
      bad_value	= -2	// illegal parameter 
    };

    // PART 3.1: instantiation
  protected:
    component() {}
    virtual ~component() {}  

  public:
    // PART 3.2: attributes (SUPERVISORY)

    // List the names of all your attributes.
    virtual std::vector<std::string>
    attribute_names()
      throw() = 0;

    // List the names of your attributes in a given category.
    virtual std::vector<std::string>
    attribute_names(const std::string& category)
      throw() = 0;
      
    // Get the value of your named attribute. 
    // Return an empty string on failure.
    virtual std::string
    attribute_value(const std::string& name) 
      throw() = 0;

    // Set your named attribute to a given value.
    // Returns component::ok only if sucessful.
    virtual status
    set_attribute_value(const std::string& name, const std::string& value)
      throw() = 0;


    // PART 3.3: pins (SUPERVISORY)
  public:
    // List all your pin names.  Include all input pins (for use with
    // find_pin) and output pins (for use with connect_pin etc.).
    virtual std::vector<std::string>
    pin_names()
      throw() = 0;

    // Find input pin with given name.  
    // Return a pointer to your pin or 0 if the pin is not found.
    virtual pin*
    find_pin(const std::string& name) 
      throw() = 0;

    // Add new connection between your named output pin to given input pin.
    virtual status
    connect_pin(const std::string& name, pin* pin)
      throw() = 0;

    // Remove connection between your named output pin from given input pin.
    virtual status
    disconnect_pin(const std::string& name, pin* pin)
      throw()= 0;

    // List all pins connected to your named output pin.  
    virtual std::vector<pin*>
    connected_pins(const std::string& name)
      throw() = 0;


    // PART 3.4: buses & accessors (SUPERVISORY)
  public:
    // List the names of your buses.
    virtual std::vector<std::string>
    bus_names()
      throw() = 0;

    // Find a bus of the given name.  
    // Return a pointer to your bus, or 0 if the bus is not found.
    virtual bus*
    find_bus(const std::string& name)
      throw() = 0;

    // List the names of your bus accessors.
    virtual std::vector<std::string> 
    accessor_names()
      throw() = 0;
    
    // Connect your named accessor to a given bus.  
    virtual status
    connect_accessor(const std::string& name, bus* bus)
      throw() = 0;

    // Disconnect your named accessor from a given bus.
    virtual status
    disconnect_accessor(const std::string& name, bus* bus)
      throw() = 0;

    // Return the bus connected to your named accessor.
    virtual bus*
    connected_bus(const std::string& name)
      throw() = 0;


    // PART 3.5: component enumeration (SUPERVISORY)
  public:
    // List the names of your component relationship lists.
    virtual std::vector<std::string> 
    relationship_names()
      throw() = 0;

    // Add given component to your named relationship list.
    virtual status
    relate (const std::string& name, component* comp) 
      throw () = 0;

    // Remove given component from your named relationship list.
    virtual status
    unrelate (const std::string& name, component* comp) 
      throw () = 0;

    // List components in your named relationship list.  Return
    // empty list if relationship is not found.
    virtual std::vector<component*>
    related_components (const std::string& name)
      throw () = 0;
  };
}

#endif // SIDCOMP_H
