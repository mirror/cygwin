// Devices.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef DEVICES_DEF_H
#define DEVICES_DEF_H	1

#include <sidcomp.h>
#include <sidso.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidattrutil.h>
#include <sidcomputil.h>

using namespace std;
using namespace sid;
using namespace sidutil;

class DeviceDriver : public virtual component,
		     public fixed_attribute_map_component,
		     public fixed_bus_map_component,
		     public fixed_accessor_map_component,
		     public no_relation_component,
		     public fixed_pin_map_component
{
private:

  int irq_cnt;

  int wc;		// for writing strings
  char *wstr;

  int rc;		// for reading strings
  char rstr[128];

  sid::bus *bus;
  output_pin scheduler_advance_pin;

  class intr_pin : public binary_input_pin {
    DeviceDriver *driver;

  public:
    intr_pin()				{ driver = 0; }

    void init( DeviceDriver *me )	{ driver = me; set_active_high(); }

    void driven( host_int_4 val )  throw ( ) { 
       try
	 {
	     driver->intrHandler( val ); 
	 }
	catch (...)
	  { }
    }


    ~intr_pin()			{}
  };

  friend class intr_pin;
  intr_pin intr;

  void intrHandler( int val );

  class WriteTrigger : public input_pin {
    DeviceDriver *driver;

  public:
    WriteTrigger()		{ driver = 0; }

    void init(DeviceDriver *owner) { driver = owner; }

    void driven( host_int_4 val ) throw ( ) {
	try 
	  {
            // XXX oh me god
            long str_addr = val;
            driver->write( (char *) str_addr ); 
	  }
	catch (...)
	  { }
    }

  };

  friend class WriteTrigger;
  WriteTrigger wtrigger;
  
public: 

  DeviceDriver() {
    add_pin( "sched-advance", &scheduler_advance_pin );

    add_pin( "INTR", &intr );
    intr.init( this );

    add_pin( "write-trigger", &wtrigger );
    wtrigger.init( this );

    add_accessor( "Bus", &bus );

    irq_cnt = 0; 
    add_attribute( "interrupt-count", &irq_cnt );

    wstr = 0; 
    rc = 0;
    bus = 0;
  }
  
  void write( char *s );
  int read( char *buf );

  ~DeviceDriver()	{}
};

class SerialSink : public virtual component,
		   public fixed_attribute_map_component,
		   public no_bus_component,
		   public no_accessor_component,
		   public no_relation_component,
		   public fixed_pin_map_component
{
private:

  callback_pin<SerialSink> sin;
  friend class callback_pin<SerialSink>;

  unsigned ldisc;			// Line Control Reg

  enum parity {
    ODD_PARITY = 0,
    EVEN_PARITY = 0x10		// Matches bit in LCR
  };

  int checkParity( unsigned val, int nbits, enum parity p ) const;

  void echo( host_int_4 val );

public:

  SerialSink() : sin( this, &SerialSink::echo ) {
    add_pin( "Sin", &sin );

    ldisc = 0;
    add_attribute( "line-discipline", &ldisc );
  }

  ~SerialSink() {}
};

class Main : public virtual component,
	     public no_attribute_component,
	     public fixed_bus_map_component,
	     public fixed_accessor_map_component,
	     public no_relation_component,
	     public fixed_pin_map_component
{
private:
  output_pin shutdown;
  output_pin source;
  output_pin wtrigger;

  sid::bus *bus;

  class activity_pin_t: public input_pin {
    Main* host;

  public:
    activity_pin_t(Main* h): host(h) {}

    void driven() throw ( ){
      try 
	{
          host->run();
          host->shutdown.drive( 1 );
	}
      catch (...)
	{ }
    }

  };

  friend class activity_pin_t;
  activity_pin_t activity_pin;

  void run();

public:

  Main() : activity_pin(this) {
    add_pin( "perform-activity", &activity_pin );
    add_pin( "shutdown-status", &shutdown );
    add_pin( "source", &source );
    add_pin( "driver-trigger", &wtrigger );

    add_accessor( "Bus", &bus );
  }

  ~Main() {}
};

#endif // DEVICES_DEF_H
