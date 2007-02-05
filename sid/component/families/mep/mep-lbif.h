// mep-lbif.h - The Toshiba MeP Local Bus Interface Unit
// -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_LBIF_H
#define MEP_LBIF_H

#include <sidcomp.h>
#include <sidbusutil.h>
#include <list>

namespace toshapi {

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;
using std::list;

class LocalBus: public bus_arbitrator
{
public:
  LocalBus ();
  ~LocalBus () throw () { }

protected:
  // enumerate the interfaces
  enum upstream_if {gbif, dmac, num_upstream_ifs};
  enum downstream_if {local_memory, num_downstream_ifs};

  static const char *upstr[];
  static const char *downstr[];

  virtual const char *up2str (int upstream) { return upstr[upstream]; }

protected:
  // Virtual overrides for arbitration
  //
  virtual bool prioritize_request (bus_request &r);

  virtual int prioritize (const bus_request& r1, const bus_request &r2);
  virtual bool access_granted (bus_request &r);
  virtual bool check_passthrough (int = 0);

protected:
  // Virtual overrides for timing
  //
  virtual sid::host_int_2 access_latency (bus_request &r);

protected:
  virtual void lock_downstream (int upstream, int downstream)
    {
      assert (downstream < num_downstream_ifs);
      bool state = check_locked (upstream);
      log (7, "%s: downstream pin now %d\n", name.c_str (), (int)state);
      downstream_lock_pin.set (state);
    }

  virtual bool check_locked (int upstream)
    {
      assert (upstream < num_upstream_ifs);
      log (7, "%s: upstream pin %d: %d \n", name.c_str (), upstream,
	   upstream_lock_pin[upstream].state () == binary_pin_active);
      return upstream_lock_pin[upstream].state () == binary_pin_active;
    }

  virtual bool check_route_busy (int upstream, int downstream);
  virtual sid::bus::status set_route_busy (bus_request &r, bus::status s);
  virtual void update_busy_routes ();
  virtual sid::bus::status busy_status ()
    {
      // Busy for at least this many cycles
      sid::bus::status s (sid::bus::busy, busy ? busy : 1);
      return s;
    }

protected:
  // Utility methods
  //
  //
  virtual bus *downstream_bus (int downstream) { return local_bus; }
  virtual int downstream_for_address (host_int_4 address) { return local_memory; }

protected:
  // Input busses
  input_interface gbif_bus; 
  input_interface dmac_bus; 

  // Output accessors
  bus *local_bus;

  // Input pins
  binary_input_pin passthrough_pin;
  binary_input_pin upstream_lock_pin[num_upstream_ifs];

  // Output pins
  binary_output_pin downstream_lock_pin;

  // State
  list<bus_request> request_queue;
  host_int_2 busy;
  int lock_owner;
  int prev_latency;
  host_int_2 total_latency;
};

} // namespace toshapi

#endif // MEP_LBIF_H
