// mep-gbif.h - The Toshiba MeP Global Bus Interface Unit
// -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_GBIF_H
#define MEP_GBIF_H

#include <sidcomp.h>
#include <sidbusutil.h>
#include <list>

namespace toshapi {

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;
using ::std::list;

class GlobalBusInterface: public bus_arbitrator
{
public:
  GlobalBusInterface ();
  ~GlobalBusInterface () throw () { }

protected:
  // enumerate the interfaces. Upstream interfaces are listed in order of
  // priority
  enum upstream_if {global_bus_slave, biu, dmac, num_upstream_ifs};
  enum downstream_if {global_bus_master, local_memory, num_downstream_ifs};

  static const char *upstr[];
  static const char *downstr[];

  const char *up2str (int upstream) { return upstr[upstream]; }

private:
  unsigned hold_duration;

protected:
  // Virtual overrides for arbitration
  //
  virtual bool prioritize_request (bus_request &r);

  virtual int prioritize (const bus_request& r1, const bus_request &r2);
  virtual bool access_granted (bus_request &r);
  virtual bool check_passthrough (int = 0);

protected:
  // Virtual overrides for handling dowstream accessors and pins
  //
  void lock_downstream (int upstream, int downstream)
    {
      assert (downstream < num_downstream_ifs);
      bool state = check_locked (upstream);
      log (7, "%s: downstream pin %d now %d\n", name.c_str (), downstream, (int)state);
      downstream_lock_pin[downstream].set (state);
    }

  bool check_locked (int upstream)
    {
      assert (upstream < num_upstream_ifs);
      log (7, "%s: upstream pin %d: %d \n", name.c_str (), upstream,
	   upstream_lock_pin[upstream].state () == binary_pin_active);
      return upstream_lock_pin[upstream].state () == binary_pin_active;
    }

  sid::bus::status set_route_busy (bus_request &r, bus::status s);
  void update_busy_routes ();
  bool check_route_busy (int upstream, int downstream);
  sid::bus::status busy_status ();

  bus *downstream_bus (int downstream);

protected:
  // Virtual overrides for timing
  //
  virtual sid::host_int_2 access_latency (bus_request &r);

protected:
  // Utility methods
  //
  //
  virtual int downstream_for_address (host_int_4 address);

private:
  // Input busses
  input_interface biu_bus; 
  input_interface dmac_bus; 
  input_interface global_bus_slave_bus; 

  // Output accessors
  bus *global_bus_master_bus;
  bus *local_bus;

  // Input pins
  binary_input_pin passthrough_pin;
  binary_input_pin upstream_lock_pin[num_upstream_ifs];

  // Output pins
  binary_output_pin downstream_lock_pin[num_downstream_ifs];

  // State
  host_int_2 upstream_busy[num_upstream_ifs];
  host_int_2 downstream_busy[num_downstream_ifs];
  int lock_owner;
  int prev_latency;
  host_int_2 total_latency;
  bus_request held_request;

protected:
  list<bus_request> request_queue;
  bool internal_request;
};

} // namespace toshapi

#endif // GBIF_H
