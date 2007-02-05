// gbif.cxx - An implementation of the Global Bus Interface Unit for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found in the
// External Specification of the MPI Integrator.

#include "components.h"
#include "mep-gbif.h"

namespace toshapi {

const char *GlobalBusInterface::upstr[] = {"Global Bus Slave", "BIU", "DMAC"};
const char *GlobalBusInterface::downstr[] = {"Global Bus Master", "Local Memory"};

// Methods for GlobalBusInterface
//
GlobalBusInterface::GlobalBusInterface () :
  bus_arbitrator (),
  biu_bus (this, biu),
  dmac_bus (this, dmac),
  global_bus_slave_bus (this, global_bus_slave),
  global_bus_master_bus (0),
  local_bus (0),
  hold_duration (0),
  prev_latency (-1),
  total_latency (0),
  lock_owner (-1),
  internal_request (false)
{
  // Clear the busy array.
  memset (upstream_busy, 0, sizeof upstream_busy);
  memset (downstream_busy, 0, sizeof upstream_busy);

  // The BIU interface bus
  add_bus ("biu-interface", &biu_bus);

  // The DMAC interface bus
  add_bus ("dmac-interface", &dmac_bus);

  // The Global Bus Slave interface bus
  add_bus ("global-bus-slave-interface", &global_bus_slave_bus);
  
  // The global and local bus interfaces
  add_accessor ("global-bus-master", & this->global_bus_master_bus);
  add_accessor ("local-bus", & this->local_bus);

  // Input pins
  add_pin ("passthrough", & passthrough_pin);
  passthrough_pin.set_active_high ();

  add_pin ("biu-lock", & this->upstream_lock_pin[biu]);
  this->upstream_lock_pin[biu].set_active_high ();
  add_pin ("dmac-lock", & this->upstream_lock_pin[dmac]);
  this->upstream_lock_pin[dmac].set_active_high ();
  add_pin ("global-bus-slave-lock", & this->upstream_lock_pin[global_bus_slave]);
  this->upstream_lock_pin[global_bus_slave].set_active_high ();

  // Output pins
  add_pin ("local-memory-lock", & this->downstream_lock_pin[local_memory]);
  this->downstream_lock_pin[local_memory].set_active_high ();
  add_pin ("gbmif-lock", & this->downstream_lock_pin[global_bus_master]);
  this->downstream_lock_pin[global_bus_master].set_active_high ();
}

// Methods for arbitation
//
bool
GlobalBusInterface::prioritize_request (bus_request &r)
{
  // Otherwise find the proper place in the queue
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
      // If the request is from the Global Bus Slave Interface, then hold it
      // for one cycle.
      if (r.upstream == global_bus_slave && ! internal_request)
	{
	  log (6, "%s: Holding request from %s\n", name.c_str (), upstr[r.upstream]);
	  held_request = r;
	  hold_duration = 1;
	  reschedule (1);
	  return false; // not ready
	}
      log (6, "%s: added to queue\n", name.c_str ());
      request_queue.insert (i, r);
    }
  return access_granted (r);
}

// Returns -1, 0 or 1 if r1 has lower, equal or higher priority respectively
int
GlobalBusInterface::prioritize (const bus_request &r1, const bus_request& r2)
{
  // Keep the requests for each downstream interface together
  if (r1.downstream != r2.downstream)
    return r2.downstream - r1.downstream;

  // Within downstream blocks, prioritize by upstream interface. Simply compare
  // the upstream interfaces which are defined in order of priority.
  return r2.upstream - r1.upstream;
}

bool
GlobalBusInterface::access_granted (bus_request &r)
{
  // Grant access automatically if the upstream interface has a lock
  if (lock_owner == r.upstream)
    return true;

  // The GBIF can handle requests to both downstream interfaces
  // simultaneously. See if the given request is the first queued for
  // its downstream interface.
  for (list <bus_request>::iterator i = request_queue.begin();
       i != request_queue.end (); ++i)
    {
      if (r.downstream == i->downstream)
	{
	  if (r == *i)
	    return true;
	  break;
	}
    }
  log (5, "%s: access denied: not highest priority\n", name.c_str ());
  return false;
}

// Utility methods
//
// Returns the target bus corresponding to the given address. The address may
// also be adjusted to match the base address of the chosen bus.
//
bus *
GlobalBusInterface::downstream_bus (int downstream)
{
  if (downstream == global_bus_master)
    return global_bus_master_bus;

  return local_bus;
}

int
GlobalBusInterface::downstream_for_address (host_int_4 address)
{
  // Addresses in the ranges:
  //   0x200000-0x2fffff
  //   0x600000-0x6fffff
  // are on the local bus. Other addresses are on the global bus.
  if (address >= 0x200000)
    {
      if (address <= 0x2fffff
	  || address >= 0x600000 && address <= 0x6fffff)
	{
	  if (ulog_level >= 8 || ! check_passthrough())
	    log (6, "%s: target is local bus interface\n", name.c_str ());
	  return local_memory;
	}
    }

  if (ulog_level >= 8 || ! check_passthrough())
    log (6, "%s: target is global bus master interface\n", name.c_str ());
  return global_bus_master;
}

sid::host_int_2
GlobalBusInterface::access_latency (bus_request &r)
{
  // No latency for accessing local memory from the BIU
  if (r.upstream == biu && r.downstream == local_memory)
    return 0;

  // Latency of 1 cycle for other accesses
  return 1;
}

bus::status
GlobalBusInterface::set_route_busy (bus_request &r, bus::status s)
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
      
      // Must reschedule before setting busy state!!
      reschedule (total_latency);
      assert (! upstream_busy[r.upstream]);
      assert (! downstream_busy[r.downstream]);
      upstream_busy[r.upstream] = total_latency;
      downstream_busy[r.downstream] = total_latency;

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
GlobalBusInterface::check_route_busy (int upstream, int downstream)
{
  if (upstream_busy[upstream])
    {
      // The bus is busy. Block the request
      log (5, "%s: access denied: upstream %s busy\n", name.c_str (),
	   upstr [upstream]);
      return true; // busy
    }
  if (downstream_busy[downstream])
    {
      // The bus is busy. Block the request
      log (5, "%s: access_denied: downstream %s busy\n", name.c_str (),
	   downstr [downstream]);
      return true; // busy
    }

  log (5, "%s: access granted\n", name.c_str ());
  return false; // route ok
}

sid::bus::status
GlobalBusInterface::busy_status ()
{
  // Return the max of the busy status of the interfaces
  sid::host_int_2 busy = 1; // busy for at least 1 cycle
  for (int i = 0; i < num_upstream_ifs; ++i)
    if (upstream_busy[i] > busy)
      busy = upstream_busy[i];
  for (int i = 0; i < num_downstream_ifs; ++i)
    if (downstream_busy[i] > busy)
      busy = downstream_busy[i];

  log (7, "%s: busy_status == %d\n", name.c_str (), busy);
  return sid::bus::status (sid::bus::busy, busy);
}

void
GlobalBusInterface::update_busy_routes ()
{
  bool still_busy = false;

  log (7, "%s: status:\n", name.c_str());

  // See if there's a request being held which should be released
  log (7, "%s:   holding gbsi request for %d cycles\n", name.c_str (), hold_duration);
  if (hold_duration > 0)
    {
      if (--hold_duration)
	still_busy = true;
      else
	{
	  log (7, "%s:     releasing held %s request from %s to %s at 0x%x\n",
	       name.c_str (), held_request.is_read ? "read" : "write",
	       upstr[held_request.upstream], downstr[held_request.downstream],
	       held_request.addr);
	  internal_request = true;
	  prioritize_request (held_request);
	  internal_request = false;
	}
    }

  // Now update the status of each interface
  log (7, "%s:   interface status:\n", name.c_str());
  log (7, "%s:     upstream:", name.c_str());
  for (int i = 0; i < num_upstream_ifs; ++i)
    {
      log (7, " %s:%d", upstr [i], upstream_busy[i]);
      if (upstream_busy[i] > 0)
	if (--(upstream_busy[i]))
	  still_busy = true;
    }
  log (7, "\n%s:     downstream:", name.c_str());
  for (int i = 0; i < num_downstream_ifs; ++i)
    {
      log (7, " %s:%d", downstr [i], downstream_busy[i]);
      if (downstream_busy[i] > 0)
	if (--(downstream_busy[i]))
	  still_busy = true;
    }
  log (7, "\n");

  if (still_busy)
    reschedule (1);
}

bool
GlobalBusInterface::check_passthrough (int upstream)
{
  if (passthrough_pin.state () == binary_pin_active)
    {
      log (8, "%s: passthrough enabled\n", name.c_str ());
      return true;
    }
  return bus_arbitrator::check_passthrough (upstream);
}

} // namespace toshapi
