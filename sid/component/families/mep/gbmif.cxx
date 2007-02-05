// gbmif.cxx - An implementation of the Global Bus Master Interface Unit for
// the Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found in the
// External Specification of the MPI Integrator.

#include "components.h"
#include "mep-gbmif.h"

namespace toshapi {

// Methods for GlobalBus
//
GlobalBus::GlobalBus () :
  bus_arbitrator (),
  gbif_busses (0),
  global_bus (0),
  passthrough_pin (0),
  upstream_lock_pin (0),
  num_ports (0),
  busy (0),
  prev_latency (-1),
  total_latency (0),
  lock_owner (-1)
{
  // Attributes
  add_attribute_notify ("ports", & num_ports, this,
			& GlobalBus::ports_attribute_set,
			"configuration");

  // The global bus
  add_accessor ("global-bus", & this->global_bus);

  // Output pins
  add_pin ("global-bus-lock", & this->downstream_lock_pin);
  this->downstream_lock_pin.set_active_high ();
}

void
GlobalBus::ports_attribute_set ()
{
  // Allocate the given number of ports from the GBIFs of the cores and add the
  // busses and pins for them.
  assert (num_ports);
  gbif_busses = new input_interface*[num_ports];
  passthrough_pin = new binary_input_pin*[num_ports];
  upstream_lock_pin = new binary_input_pin*[num_ports];

  for (unsigned i = 0; i < num_ports; ++i)
    {
      gbif_busses[i] = new input_interface (this, i);
      add_bus ("gbif-interface-" + sidutil::make_attribute (i),
	       gbif_busses[i]);

      // Input pins
      passthrough_pin[i] = new binary_input_pin ();
      add_pin ("passthrough-" + sidutil::make_attribute (i), 
	       passthrough_pin[i]);
      passthrough_pin[i]->set_active_high ();

      upstream_lock_pin[i] = new binary_input_pin ();
      add_pin ("gbif-lock-" + sidutil::make_attribute (i), 
	       upstream_lock_pin[i]);
      upstream_lock_pin[i]->set_active_high ();
    }
}

// Methods for arbitation
//
bool
GlobalBus::prioritize_request (bus_request &r)
{
  // Find the proper place in the queue
  bool add_to_queue = true;
  list <bus_request>::iterator i;
  for (i = request_queue.begin (); i != request_queue.end (); ++i)
    {
      if (r == *i)
	{
	  log (7, "%s: already queued\n", name.c_str ());
	  add_to_queue = false;
	  break;
	}
      if (prioritize (r, *i) > 0)
	break;
    }
  if (add_to_queue)
    {
      log (6, "%s: added to queue\n", name.c_str ());
      request_queue.insert (i, r);
    }
  return access_granted (r);
}

// Returns -1, 0 or 1 if r1 has lower, equal or higher priority respectively
int
GlobalBus::prioritize (const bus_request &r1, const bus_request& r2)
{
  // Keep requests from the same upstream together, but maintain the
  // order of the blocks to correspond to the order in which each
  // upstream interface made a request.
  if (r1.upstream != r2.upstream)
    return -1;
  return 1;
}

bool
GlobalBus::access_granted (bus_request &r)
{
  // Grant access automatically if the upstream interface has a lock.
  if (lock_owner == r.upstream)
    return true;

  // Otherwise access is granted if no requests for other upstream
  // interfaces are ahead of this one in the queue. This implements
  // a FIFO-like priority where requests from the same upstream
  // interface at the head of the queue are equal. This resolves deadlock
  // in the situation where an upstream interface blocks the request which
  // is at the head of our queue because it has lower priority than a
  // subsequent request.
  list <bus_request>::iterator i = request_queue.begin();
  if (i != request_queue.end ())
    {
      if (r.upstream == i->upstream)
	return true;
    }

  log (5, "%s: access denied: not highest priority\n", name.c_str ());
  return false;
}

bus::status
GlobalBus::set_route_busy (bus_request &r, bus::status s)
{
  log (7, "%s: set_route_busy\n", name.c_str ());
  sid::host_int_2 this_latency = 1; // minimum latency

  // If this is the first or only read/write, then apply the penalty here.
  if (prev_latency < 0)
    {
      this_latency = access_latency (r);
      log (7, "%s:   read/write penalty is %d\n", name.c_str (), this_latency);
      prev_latency = 0;
    }
  else
    log (7, "%s:   previous latency was %d\n", name.c_str (), prev_latency);
  log (7, "%s:   downstream latency is %d\n", name.c_str (), s.latency);

  // If this access took longer than the previous one, then either this
  // is the first (or only) read/write in a burst or there will be a gap in the
  // burst. Account for it here.
  if (prev_latency < s.latency)
    this_latency += s.latency - prev_latency;

  log (7, "%s:   additional latency is %d\n", name.c_str (), this_latency);
  total_latency += this_latency;

  if (! check_locked (r.upstream) && s == sid::bus::ok)
    {
      log (7, "%s:   total latency of access/burst is %d\n", name.c_str (), total_latency);
      
      busy = total_latency;
      reschedule (busy);

      // Reset latency for burst pipeline
      prev_latency = -1;
      total_latency = 0;
      lock_owner = -1;
    }
  else
    {
      log (7, "%s:   access is locked\n", name.c_str ());
      prev_latency = s.latency;
      lock_owner = r.upstream;
    }

  // Request is complete
  request_queue.remove (r);
  s.latency = this_latency;
  return s;
}

bool
GlobalBus::check_route_busy (int upstream, int downstream)
{
  if (busy)
    {
      // The bus is busy. Block the request
      log (5, "%s: access denied: interface is busy\n", name.c_str ());
      return true; // busy
    }

  log (5, "%s: access granted\n", name.c_str ());
  return false; // route ok
}

void
GlobalBus::update_busy_routes ()
{
  log (7, "%s: busy status: %d cycles\n", name.c_str (), busy);
  if (busy > 0)
    if (--busy)
      reschedule (1);
}

bool
GlobalBus::check_passthrough (int upstream)
{
  assert (upstream < num_ports);
  assert (passthrough_pin[upstream]);
  if (passthrough_pin[upstream]->state () == binary_pin_active)
    {
      log (8, "%s: passthrough enabled\n", name.c_str ());
      return true;
    }
  return bus_arbitrator::check_passthrough (upstream);
}
} // namespace toshapi
