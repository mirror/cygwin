// lbif.cxx - An implementation of the Local Bus Interface Unit for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found in the
// External Specification of the MPI Integrator.

#include "components.h"
#include "mep-lbif.h"

namespace toshapi {

const char *LocalBus::upstr[] = {"GBIF", "DMAC"};
const char *LocalBus::downstr[] = {"Local Memory"};

// Methods for LocalBus
//
LocalBus::LocalBus () :
  bus_arbitrator (),
  gbif_bus (this, gbif),
  dmac_bus (this, dmac),
  local_bus (0),
  busy (0),
  prev_latency (-1),
  total_latency (0),
  lock_owner (-1)
{
  // The GBIF interface bus
  add_bus ("gbif-interface", &gbif_bus);
  
  // The DMAC interface bus
  add_bus ("dmac-interface", &dmac_bus);
  
  // The local bus
  add_accessor ("local-bus", & this->local_bus);

  // Input pins
  add_pin ("passthrough", & passthrough_pin);
  passthrough_pin.set_active_high ();

  add_pin ("gbif-lock", & this->upstream_lock_pin[gbif]);
  this->upstream_lock_pin[gbif].set_active_high ();
  add_pin ("dmac-lock", & this->upstream_lock_pin[dmac]);
  this->upstream_lock_pin[dmac].set_active_high ();

  // Output pins
  add_pin ("local-memory-lock", & this->downstream_lock_pin);
  this->downstream_lock_pin.set_active_high ();
}

// Methods for arbitation
//
bool
LocalBus::prioritize_request (bus_request &r)
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
LocalBus::prioritize (const bus_request &r1, const bus_request& r2)
{
  return -1; // FIFO
}

bool
LocalBus::access_granted (bus_request &r)
{
  // Grant access automatically if the upstream interface has a lock, otherwise
  // access is granted if the request is at the head of the queue.
  if (lock_owner == r.upstream || r == request_queue.front ())
    {
      // Need to adjust for the base address of local memory
      if (r.upstream == gbif)
	r.addr -= 0x200000;
      return true;
    }
  log (5, "%s: access denied: not highest priority\n", name.c_str ());
  return false;
}

sid::host_int_2
LocalBus::access_latency (bus_request &r)
{
  // The penalty depends on the origin and type of the request.
  if (! r.is_read)
    return 1; // All writes have a 1 cycle penalty

  if (r.upstream == dmac)
    return 3; // read from DMAC has a 3 cycle penalty

  return 1; // read from GBIF has a 1 cycle penalty
}

bus::status
LocalBus::set_route_busy (bus_request &r, bus::status s)
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
      
      // Local bus is busy for the duration of the burst, but can accept
      // new requests immediatately afterward.
      busy = total_latency;
      sid::host_int_2 penalty = access_latency (r);
      if (penalty > 1)
	busy -= (penalty - 1);
      reschedule (busy);

      // Reset latency for burst pipeline
      prev_latency = -1;
      total_latency = 0;
      lock_owner = -1;
    }
  else
    {
      log (7, "%s: access is locked\n", name.c_str ());
      lock_owner = r.upstream;
    }

  // Request is complete
  // Need to remove adjustment for the base address of local memory
  if (r.upstream == gbif)
    r.addr += 0x200000;
  request_queue.remove (r);
  s.latency = this_latency;
  return s;
}

bool
LocalBus::check_route_busy (int upstream, int downstream)
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
LocalBus::update_busy_routes ()
{
  log (7, "%s: busy status: %d cycles\n", name.c_str (), busy);
  if (busy > 0)
    if (--busy)
      reschedule (1);
}

bool
LocalBus::check_passthrough (int upstream)
{
  if (passthrough_pin.state () == binary_pin_active)
    {
      log (8, "%s: passthrough enabled\n", name.c_str ());
      return true;
    }
  return bus_arbitrator::check_passthrough (upstream);
}
} // namespace toshapi
