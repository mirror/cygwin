// mep-gbmif.h - The Toshiba MeP Global Bus Master Interface Unit
// -*- C++ -*-

// Copyright (C) 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_GBMIF_H
#define MEP_GBMIF_H

#include <sidcomp.h>
#include <sidbusutil.h>
#include <list>
#include <string>

namespace toshapi {

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;
using std::list;

class GlobalBus: public bus_arbitrator
{
public:
  GlobalBus ();
  ~GlobalBus () throw () { }

protected:
  // enumerate the interfaces
  enum downstream_if {global_memory, num_downstream_ifs};

  virtual const char *up2str (int upstream)
    {
      string str = "GBIF interface " + sidutil::make_attribute (upstream);
      return str.c_str ();
    }

protected:
  // Virtual overrides for arbitration
  //
  virtual bool prioritize_request (bus_request &r);

  virtual int prioritize (const bus_request& r1, const bus_request &r2);
  virtual bool access_granted (bus_request &r);
  virtual bool check_passthrough (int = 0);

protected:
  virtual void lock_downstream (int upstream, int downstream)
    {
      bool state = check_locked (upstream);
      log (7, "%s: downstream pin now: %d \n", name.c_str (), (int)state);
      downstream_lock_pin.set (state);
    }

  virtual bool check_locked (int upstream)
    {
      assert (upstream < num_ports);
      log (7, "%s: upstream pin %d: %d \n", name.c_str (), upstream,
	   upstream_lock_pin[upstream]->state () == binary_pin_active);
      return upstream_lock_pin[upstream]->state () == binary_pin_active;
    }

protected:
  // Virtual overrides for timing
  //
  // Read and write both have a latency of 1 cycle
  virtual sid::host_int_2 access_latency (bus_request &r) { return 1; }

  // Utility methods
  //
  //
  virtual int downstream_for_address (host_int_4 address) { return global_memory; }
  virtual bool check_route_busy (int upstream, int downstream);
  virtual sid::bus::status set_route_busy (bus_request &r, bus::status s);
  virtual void update_busy_routes ();
  virtual sid::bus::status busy_status ()
    {
      // Busy for at least this many cycles
      sid::bus::status s (sid::bus::busy, busy ? busy : 1);
      return s;
    }

  virtual bus *downstream_bus (int downstream) { return global_bus; }

protected:
  // Input busses
  input_interface** gbif_busses; 

  // Output accessors
  bus *global_bus;

  // Input pins
  binary_input_pin **passthrough_pin;
  binary_input_pin **upstream_lock_pin;

  // Output pins
  binary_output_pin downstream_lock_pin;

  // State
  void ports_attribute_set ();
  unsigned num_ports;
  list<bus_request> request_queue;
  host_int_2 busy;
  int lock_owner;
  int prev_latency;
  host_int_2 total_latency;
};

} // namespace toshapi

#endif // MEP_GBMIF_H
