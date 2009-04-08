// cache.cxx -- A universal memory cache. -*- C++ -*-

// Copyright (C) 2001, 2002, 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidtypes.h>

#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

#include "cache.h"
#include "mep-cache.h"

static string buffer_sizes[] =
  { "4", "8" };

static string line_sizes[] =
  { "16", "32", "64", "128" };

static string cache_sizes[] =
  { "1", "2", "4", "8", "16", "32", "64", "128", "256", "512" };

static string assocs[] =
  { "direct", "full", "2way", "4way" };

static string replacement_algorithms[] =
  { "lru", "fifo", "random" }; 

// One per replacement policy
static cache_replacement_null null_replacement;
static cache_replacement_lru lru_replacement;
static cache_replacement_fifo fifo_replacement;
static cache_replacement_random random_replacement;
static cache_line_factory internal_line_factory;
static mep_assoc_replacement_algorithm mep_assoc_replacement;

cache_component::cache_component (unsigned assocy,
				  unsigned cache_sz, 
				  unsigned line_sz,
				  cache_replacement_algorithm& replacer,
				  cache_line_factory& factory)
  :acache (cache_sz, line_sz, assocy, replacer, factory),
   upstream (*this),
   downstream (0),
   report_pin (this, &cache_component::emit_report),
   flush_all_pin (this, &cache_component::flush_all_lines),
   flush_pin (this, &cache_component::flush_line),
   flush_set_pin (this, &cache_component::flush_set),
   flush_and_invalidate_set_pin (this, &cache_component::flush_and_invalidate_set),
   invalidate_all_pin (this, &cache_component::invalidate_all_lines),
   invalidate_pin (this, &cache_component::invalidate_line),
   invalidate_set_pin (this, &cache_component::invalidate_set),
   flush_and_invalidate_pin (this, &cache_component::flush_and_invalidate_line),
   prefetch_pin (this, &cache_component::prefetch_line),
   write_hint_pin (this, &cache_component::write_hint),
   lock_pin (this, &cache_component::lock_line),
   unlock_pin (this, &cache_component::unlock_line),
   write_allocate_p (false),
   write_through_p (false),
   collect_p (true),
   report_heading ("cache profile report"),
   line_factory (factory),
   line_size (line_sz),
   cache_size (cache_sz),
   assoc (assocy),
   data_width (4),
   hit_latency (0),
   miss_latency (0),
   refill_latency (0),
   refill_latency_specified (false),
   total_latency_p (false)
{
  acache.init ();
  memset (&stats, 0, sizeof (stats));

  add_bus ("upstream", &upstream);
  add_accessor ("downstream", &downstream);
  
  add_pin ("report!", &report_pin);
  add_pin ("flush-all", &flush_all_pin);
  add_pin ("flush-set", &flush_set_pin);
  add_pin ("flush", &flush_pin);
  add_pin ("invalidate-all", &invalidate_all_pin);
  add_pin ("invalidate-set", &invalidate_set_pin);
  add_pin ("flush-and-invalidate-set", &flush_and_invalidate_set_pin);
  add_pin ("invalidate", &invalidate_pin);
  add_pin ("flush-and-invalidate", &flush_and_invalidate_pin);
  add_pin ("prefetch", &prefetch_pin);
  add_pin ("write-hint", &write_hint_pin);
  add_pin ("lock", &lock_pin);  
  add_pin ("unlock", &unlock_pin);
  add_pin ("operation-status", &operation_status_pin);
  
  add_attribute_ro ("cache-size", &cache_size, "setting");
  add_attribute_ro ("line-size", &line_size, "setting");
  add_attribute_virtual ("associativity", this,
			 &cache_component::associativity,
			 &cache_component::set_nothing,
			 "setting");
  add_attribute ("data-width", &data_width, "setting");

  add_attribute ("write-through?", &write_through_p, "setting");
  add_attribute ("write-allocate?", &write_allocate_p, "setting");

  add_attribute_virtual ("hash-bit-mask", this,
			 &cache_component::get_hash_mask,
			 &cache_component::set_hash_mask,
			 "setting");

  add_attribute_virtual ("hash-shift-amount", this,
			 &cache_component::get_hash_shift,
			 &cache_component::set_hash_shift,
			 "setting");

  add_attribute ("collect-statistics?", &collect_p, "setting");
  add_attribute ("report-heading", &report_heading, "setting");
  
  add_attribute_virtual ("dump!", this,
			 &cache_component::get_nothing,
			 &cache_component::dump,
			 "setting");

  add_attribute_ro ("read-accesses", &stats.reads, "register");
  add_attribute_ro ("write-accesses", &stats.writes, "register");
  add_attribute_ro ("misaligned-reads", &stats.misaligned_reads, "register");
  add_attribute_ro ("misaligned-writes", &stats.misaligned_writes, "register");
  add_attribute_ro ("flushes", &stats.flushes, "register");
  add_attribute_ro ("replacements", &stats.replacements, "register");

  add_attribute_virtual ("read-hit-rate", this,
			 &cache_component::read_hit_rate,
			 &cache_component::set_nothing,
			 "register");
  
  add_attribute_virtual ("write-hit-rate", this,
			 &cache_component::write_hit_rate,
			 &cache_component::set_nothing,
			 "register");

  add_attribute ("hit-latency", &hit_latency, "setting");
  add_attribute ("miss-latency", &miss_latency, "setting");
  add_attribute ("total-latency?", &total_latency_p, "setting");

  add_attribute_virtual ("refill-latency", this,
			 &cache_component::get_refill_latency,
			 &cache_component::set_refill_latency,
			 "setting");

  // FIXME: state save/restore
}




// dummy dtor
cache_component::~cache_component () throw ()
{
}


unsigned
cache_component::line_offset (const cache_line& line, const host_int_4& addr)
{
  return addr - acache.tag_to_addr (line.tag ());
}

template <typename DataType>
bus::status
cache_component::write_any (host_int_4 addr, DataType data)
{
  bus::status st, read_status;

  if (UNLIKELY (downstream == 0))
    return bus::unmapped;

  if (LIKELY (collect_p))
    stats.writes++;

  if (UNLIKELY (addr % sizeof (data) != 0))
    {
      if (LIKELY (collect_p))
	stats.misaligned_writes++;
    }

  // Punt on access across lines
  if (UNLIKELY (addr % line_size + sizeof (data) > line_size))
    return bus::misaligned;

  cache_tag tag = acache.addr_to_tag (addr);
  cache_line* line = acache.find (tag);
  if (LIKELY (line))
    {
      if (LIKELY (collect_p))
	stats.write_hits++;
      line->insert (line_offset (*line, addr), data);
      if (write_through_p)
	{
	  do
	    {
	      st = downstream->write (addr, data);
	      if (st == bus::ok)
		break;
	    }
	  while (handle_write_error (st, addr));
	  if (st != bus::ok)
	    return st;
	}
    }
  else
    {
      if (write_allocate_p && acache.vacancy_p (addr))
	{
	  if (collect_p)
	    stats.replacements++;

	  cache_line *expelled_line = acache.expell_line (tag);
	  assert (expelled_line);

	  if (! write_through_p)
	    {
	      if (expelled_line->valid_p () && expelled_line->dirty_p ())
		{
		  // flush a dirty line being replaced
		  if ((st = write_line (*expelled_line)) != bus::ok)
		    return st;
		}
	    }
	  else
	    {
	      do
		{
		  st = downstream->write (addr, data);
		  if (st == bus::ok)
		    break;
		}
	      while (handle_write_error (st, addr));
	      if (st != bus::ok)
		return st;
	    }

	  expelled_line->set_tag (tag);
	  if ((read_status = read_line (*expelled_line)) != bus::ok)
	    return read_status;
	      
	  expelled_line->insert (line_offset (*expelled_line, addr), data);
	}
      else
	{
	  // write through to memory to preserve the write
	  do
	    {
	      st = downstream->write (addr, data);
	      if (st == bus::ok)
		break;
	    }
	  while (handle_write_error (st, addr));
	  if (st != bus::ok)
	    return st;
	}
    }

  st = bus::ok;
  if (line)
    st.latency = hit_latency;
  else
    st.latency = read_status.latency + miss_latency;
  return st;
}

template <typename DataType>
bus::status
cache_component::read_any (host_int_4 addr, DataType& data)
{
  bus::status st, read_status;

  if (UNLIKELY (downstream == 0))
    return bus::unmapped;

  if (LIKELY (collect_p))
    stats.reads++;

  // Punt on misaligned accesses
  if (UNLIKELY (addr % sizeof (data) != 0))
    {
      if (LIKELY (collect_p))
	stats.misaligned_reads++;
    }

  // Punt on accesses across lines
  if (UNLIKELY (addr % line_size + sizeof (data) > line_size))
    return bus::misaligned;

  cache_tag tag = acache.addr_to_tag (addr);
  cache_line* line = acache.find (tag);
  if (LIKELY (line))
    {
      if (LIKELY (collect_p))
	stats.read_hits++;
      line->extract (line_offset (*line, addr), data);
    }
  else
    {
      // miss!
      if (acache.vacancy_p (addr))
	{
	  if (LIKELY (collect_p))
	    stats.replacements++;
	  
	  cache_line *expelled_line = acache.expell_line (tag);
	  assert (expelled_line);
	  if (expelled_line->valid_p () && expelled_line->dirty_p ())
	    {
	      // flush a dirty line being replaced
	      if ((st = write_line (*expelled_line)) != bus::ok)
		  return st;
	    }
	  expelled_line->set_tag (tag);
	  if ((read_status = read_line (*expelled_line)) != bus::ok)
	    return read_status;
	  expelled_line->extract (line_offset (*expelled_line, addr), data);
	}
      else
	{
	  do
	    {
	      st = downstream->read (addr, data);
	      if (st == bus::ok)
		break;
	    }
	  while (handle_read_error (st, addr));
	  st.latency += miss_latency;
	  return st;
	}
    }

  st = bus::ok;
  if (line)
    st.latency += hit_latency;
  else
    st.latency = read_status.latency + miss_latency;
  return st;
}

// Prepare a line for writing.  This means we are expecting to write
// to all the bytes in the line, so we set it up to *not* read the
// line from the cache on the first write to it, by making the line
// valid if needed.  As a side effect, if you don't write to all the
// bytes in the line, unwritten bytes are undefined when written to
// memory.
void
cache_component::write_hint (host_int_4 addr)
{
  bus::status st, read_status;

  if (UNLIKELY (downstream == 0))
    return;

  if (LIKELY (collect_p))
    stats.reads++;

  cache_tag tag = acache.addr_to_tag (addr);
  cache_line* line = acache.find (tag);
  if (LIKELY (line))
    {
      // Line already exists in cache, nothing to do.
    }
  else
    {
      // miss!
      if (acache.vacancy_p (addr))
	{
	  if (LIKELY (collect_p))
	    stats.replacements++;
	  
	  cache_line *expelled_line = acache.expell_line (tag);
	  assert (expelled_line);
	  if (expelled_line->valid_p () && expelled_line->dirty_p ())
	    {
	      // flush a dirty line being replaced
	      if ((st = write_line (*expelled_line)) != bus::ok)
		  return;
	    }
	  expelled_line->set_tag (tag);
	  // We don't actually read the line, though.
	  expelled_line->validate ();
	}
      else
	{
	  // No room in the cache, so our hint must go uneeded.
	}
    }

  st = bus::ok;
  if (line)
    st.latency += hit_latency;
  else
    st.latency = miss_latency;
  report_status (st);
  return;
}

bus::status
cache_component::read_line (cache_line& line)
{
  bus::status st;
  host_int_4 base = acache.tag_to_addr (line.tag ());
  lock_downstream ();
  host_int_2 actual_fill_latency = 0;
  for (host_int_4 offset = 0; offset < line_size; offset += data_width)
    {
      // Unlock the downstream interface for the last read
      if (offset + data_width >= line_size)
	unlock_downstream ();

      sid::big_int_8 data8;
      sid::big_int_4 data4;
      host_int_4 address = base + offset;
      if (data_width == 8)
	st = read_downstream (address, data8);
      else
	st = read_downstream (address, data4);

      if (st != bus::ok)
	{
	  unlock_downstream ();
	  return st;
	}

      if (total_latency_p)
	actual_fill_latency += st.latency;
      else if (st.latency > actual_fill_latency)
	actual_fill_latency = st.latency;

      if (data_width == 8)
	line.insert (offset, data8);
      else
	line.insert (offset, data4);
    }
  line.unlock ();
  line.clean ();
  line.validate ();

  if (refill_latency_specified && ! total_latency_p)
    st.latency = refill_latency;
  else
    st.latency = actual_fill_latency;

  return st;
}

bus::status
cache_component::write_line (cache_line& line)
{
  bus::status st;
  host_int_4 base = acache.tag_to_addr (line.tag ());
  lock_downstream ();
  host_int_2 actual_latency = 0;
  for (host_int_4 offset = 0; offset < line_size; offset += data_width)
    {
      // Unlock the downstream interface for the last write
      if (offset + data_width >= line_size)
	unlock_downstream ();

      sid::big_int_4 data4;
      sid::big_int_8 data8;
      host_int_4 address = base + offset;
      if (data_width == 8)
	{
	  line.extract (offset, data8);
	  st = write_downstream (address, data8);
	}
      else
	{
	  line.extract (offset, data4);
	  st = write_downstream (address, data4);
	}

      if (st != bus::ok)
	{
	  unlock_downstream ();
	  return st;
	}

      if (total_latency_p)
	actual_latency += st.latency;
      else if (st.latency > actual_latency)
	actual_latency = st.latency;
    }
  line.clean ();
  if (LIKELY (collect_p))
    stats.flushes++;
  st.latency = actual_latency;
  return st;
}

template<typename DataType>
bus::status
cache_component::read_downstream (host_int_4 address, DataType &data)
{
  bus::status st;
  do
    {
      st = downstream->read (address, data);
      if (st == bus::ok)
	break;
    }
  while (handle_read_error (st, address));
  return st;
}

template<typename DataType>
bus::status
cache_component::write_downstream (host_int_4 address, DataType data)
{
  bus::status st;
  do
    {
      st = downstream->write (address, data);
      if (st == bus::ok)
	break;
    }
  while (handle_write_error (st, address));
  return st;
}

void
cache_component::flush_all_lines (host_int_4)
{
  host_int_2 total_latency = 0;
  bus::status st;
  while (true)
    {
      cache_line* line = acache.find_any_dirty ();
      if (line == 0) break;
      st = write_line (*line);
      if (st != bus::ok)
	break;
      total_latency += st.latency;
    }
  st.latency = total_latency;
  report_status (st);
}

void
cache_component::flush_line (host_int_4 addr)
{
  bus::status st;
  cache_line* line = acache.find (acache.addr_to_tag (addr));
  if (line && line->dirty_p ())
    st = write_line (*line);
  report_status (st);
}

void
cache_component::flush_set (host_int_4 addr)
{
  host_int_4 index = acache.addr_to_index (addr);
  assert (index < acache.num_sets ());

  host_int_2 total_latency = 0;
  bus::status st;
  cache_set& set = acache [index];
  for (unsigned i = 0; i < set.num_lines(); i++)
    {
      cache_line& line = set [i];
      if (line.valid_p () && line.dirty_p ())
	{
	  st = write_line (line);
	  if (st != bus::ok)
	    break;
	  total_latency += st.latency;
	}
    }
  st.latency = total_latency;
  report_status (st);
}

void
cache_component::flush_and_invalidate_set (host_int_4 addr)
{
  host_int_4 index = acache.addr_to_index (addr);
  assert (index < acache.num_sets ());

  host_int_2 total_latency = 0;
  bus::status st;
  cache_set& set = acache [index];
  for (unsigned i = 0; i < set.num_lines(); i++)
    {
      cache_line& line = set [i];
      if (line.valid_p () && line.dirty_p ())
	{
	  st = write_line (line);
	  if (st != bus::ok)
	    break;
	  total_latency += st.latency;
	  line.invalidate ();
	}
    }
  st.latency = total_latency;
  report_status (st);
}

void
cache_component::invalidate_all_lines (host_int_4 ignore)
{
  acache.invalidate ();
  report_status (bus::ok);
}

void
cache_component::invalidate_line (host_int_4 addr)
{
  cache_line* line = acache.find (acache.addr_to_tag (addr));
  if (line)
    line->invalidate ();
  report_status (bus::ok);
}

void
cache_component::flush_and_invalidate_line (host_int_4 addr)
{
  cache_line* line = acache.find (acache.addr_to_tag (addr));
  if (line && line->dirty_p ())
    {
      bus::status st = write_line (*line);
      line->invalidate ();
      report_status (st);
      return;
    }
  report_status (bus::ok);
}

void
cache_component::invalidate_set (host_int_4 addr)
{
  host_int_4 set = acache.addr_to_index (addr);
  acache.invalidate (set);
  report_status (bus::ok);
}

void
cache_component::prefetch_line (host_int_4 addr)
{
  sid::big_int_1 dummy;
  bus::status st = read_any (addr, dummy);
  report_status (st);
}

void
cache_component::lock_line (host_int_4 addr)
{
  cache_line* line = acache.find (acache.addr_to_tag (addr));
  if (line)
    line->lock ();
  report_status (bus::ok);
}

void
cache_component::unlock_line (host_int_4 addr)
{
  cache_line* line = acache.find (acache.addr_to_tag (addr));
  if (line)
    line->unlock ();
  report_status (bus::ok);
}

void
cache_component::emit_report (host_int_4 ignore)
{
  cout << report_heading << endl
       << "reads:        " << make_attribute (stats.reads) << endl
       << "read hits:    " << read_hit_rate () << endl
       << "writes:       " << make_attribute (stats.writes) << endl
       << "write hits:   " << write_hit_rate () << endl
       << "replacements: " << make_attribute (stats.replacements) << endl
       << "flushes:      " << make_attribute (stats.flushes) << endl;
}

string
cache_component::get_hash_mask ()
{
  return make_attribute (acache.hash_params.mask);
}

string
cache_component::get_hash_shift ()
{
  return make_attribute (acache.hash_params.shift);
}

sid::component::status
cache_component::set_hash_shift (const string& value)
{
  unsigned shift;

  if (parse_attribute (value, shift) != sid::component::ok)
    return sid::component::bad_value;

  if ((acache.hash_params.mask >> shift) >= acache.num_sets ())
    return sid::component::bad_value;

  acache.hash_params.shift = shift;
  return sid::component::ok;
}

sid::component::status
cache_component::set_hash_mask (const string& value)
{
  sid::host_int_4 mask;

  if (parse_attribute (value, mask) != sid::component::ok)
    return sid::component::bad_value;

  if ((mask >> acache.hash_params.shift) >= acache.num_sets ())
    return sid::component::bad_value;

  acache.hash_params.mask = mask;
  return sid::component::ok;
}

string
cache_component::get_refill_latency ()
{
  return make_attribute (refill_latency);
}

sid::component::status
cache_component::set_refill_latency (const string& value)
{
  if (parse_attribute (value, refill_latency) != sid::component::ok)
    return sid::component::bad_value;
  refill_latency_specified = true;
  return sid::component::ok;
}

sid::component::status
cache_component::dump (const string& ignore)
{
  acache.dump ();
  return sid::component::ok;
}

string
cache_component::associativity ()
{
  switch (assoc)
    {
    case 0:
      return "fully-associative";
    case 1:
      return "direct-mapped";
    default:
      return make_attribute (assoc) + "-way";
    }
}

string
cache_component::read_hit_rate ()
{
  if (stats.reads == 0)
    return "0%";
  else
    {
      float rate = (static_cast<float> (stats.read_hits) / stats.reads) * 100;
      return make_attribute (static_cast<int> (rate)) + "%";
    }
}

string
cache_component::write_hit_rate ()
{
  if (stats.writes == 0)
    return "0%";
  else
    {
      float rate = (static_cast<float> (stats.write_hits) / stats.writes) * 100;
      return make_attribute (static_cast<int> (rate)) + "%";
    }
}

// ------------------------------------------------------------------------
// The blocking cache component.

// This function is the root of the blockable child thread. It gets passed
// to pthread_create.
//
extern "C" void *
blocking_cache_child_thread_root (void *comp)
{
  // Set up this thread to receive and handle signals from the parent thread.
  // this need only be done once.
  //
  blocking_cache_component *cache = static_cast<blocking_cache_component *>(comp);
  cache->child_init ();

  for (;;)
    {
      // Signal completion and wait for the signal to resume
      cache->child_completed ();

      // Now perform the transaction
      cache->perform_transaction ();
    }

  // We should never reach here.
  return NULL;
}

blocking_cache_component::blocking_cache_component (unsigned assocy,
						    unsigned cache_sz, 
						    unsigned line_sz,
						    cache_replacement_algorithm& replacer,
						    cache_line_factory& factory)
  :cache_component (assocy, cache_sz, line_sz, replacer, factory),
   blocking_component (this, blocking_cache_child_thread_root)
{
  add_pin ("downstream-lock", & downstream_lock_pin);
  downstream_lock_pin.set_active_high ();
}

blocking_cache_component::blocking_cache_component (void *child_self,
						    unsigned assocy,
						    unsigned cache_sz, 
						    unsigned line_sz,
						    cache_replacement_algorithm& replacer,
						    cache_line_factory& factory)
  :cache_component (assocy, cache_sz, line_sz, replacer, factory),
   blocking_component (child_self, blocking_cache_child_thread_root)
{
  add_pin ("downstream-lock", & downstream_lock_pin);
  downstream_lock_pin.set_active_high ();
}

// Handles bus errors from reads and writes from/to insn and data memory.
// Specifically, bus::busy is handled in blockable mode.
//
bool
blocking_cache_component::handle_bus_error (bus::status s)
{
  if (s != bus::busy)
    return false; // not handled

  // Signal that we're blocked and wait for the signal to try again
  transaction_status = s;
  child_blocked ();
  return true;
}

#define DEFN_METHOD(DataType) \
bus::status \
blocking_cache_component::write(host_int_4 addr, DataType data) \
{ \
  if (blockable) \
    { \
      /* Signal the child thread to resume */ \
      need_child_thread (); \
      setup_write_transaction (addr, data); \
      continue_child_thread_and_wait (); \
 \
      return transaction_status; \
    } \
  return this->write_any(addr, data); \
} \
bus::status \
blocking_cache_component::read(host_int_4 addr, DataType& data) \
{ \
  if (blockable) \
    { \
      /* Signal the child thread to resume */ \
      need_child_thread (); \
      setup_read_transaction (addr, data); \
      continue_child_thread_and_wait (); \
 \
      get_transaction_data (data); \
      return transaction_status; \
    } \
  return this->read_any(addr, data); \
}
DEFN_METHOD (big_int_1)
DEFN_METHOD (big_int_2)
DEFN_METHOD (big_int_4)
DEFN_METHOD (big_int_8)
DEFN_METHOD (little_int_1)
DEFN_METHOD (little_int_2)
DEFN_METHOD (little_int_4)
DEFN_METHOD (little_int_8)
#undef DEFN_METHOD

void
blocking_cache_component::flush_all_lines (host_int_4 v)
{
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      setup_flush_all_transaction ();
      int signal = continue_child_thread_and_wait ();
      if (signal == ctl_child_blocked)
	report_status (transaction_status);
      return;
    }
  cache_component::flush_all_lines (v);
}

void
blocking_cache_component::flush_line (host_int_4 addr)
{
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      setup_flush_line_transaction (addr);
      int signal = continue_child_thread_and_wait ();
      if (signal == ctl_child_blocked)
	report_status (transaction_status);
      return;
    }
  cache_component::flush_line (addr);
}

void
blocking_cache_component::flush_set (host_int_4 addr)
{
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      setup_flush_set_transaction (addr);
      int signal = continue_child_thread_and_wait ();
      if (signal == ctl_child_blocked)
	report_status (transaction_status);
      return;
    }
  cache_component::flush_set (addr);
}

void
blocking_cache_component::flush_and_invalidate_set (host_int_4 addr)
{
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      setup_flush_and_invalidate_set_transaction (addr);
      int signal = continue_child_thread_and_wait ();
      if (signal == ctl_child_blocked)
	report_status (transaction_status);
      return;
    }
  cache_component::flush_and_invalidate_set (addr);
}

void
blocking_cache_component::flush_and_invalidate_line (host_int_4 addr)
{
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      setup_flush_and_invalidate_line_transaction (addr);
      int signal = continue_child_thread_and_wait ();
      if (signal == ctl_child_blocked)
	report_status (transaction_status);
      return;
    }
  cache_component::flush_and_invalidate_line (addr);
}

void
blocking_cache_component::prefetch_line (host_int_4 addr)
{
  sid::big_int_1 dummy;
  bus::status st = read (addr, dummy);
  report_status (st);
}


cache_line *
cache_replacement_fifo::expell (cache_set& cset)
{
  // If this is the first time through, expand fifo accordingly.
  if (fifo.size () != cset.num_lines ())
    fifo.resize (cset.num_lines ());

  for (unsigned i = 0; i < fifo.size (); i++)
    fifo[i]++;

  unsigned i;
  vector<int> candidates(fifo);

  int n = fifo.size ();
  while (n > 0)
    {
      vector<int>::iterator it;
      it = max_element (candidates.begin (), candidates.end ());
      i = distance (candidates.begin (), it);
      cache_line& line = cset.get_line (i);
      if (line.locked_p ())
	{
	  *it = -1;
	}
      else 
	{
	  // update state
	  fifo[i] = 0;
	  return &line;
	}
      n--;
    }

  return 0;
}

cache_line *
cache_replacement_lru::expell (cache_set& cset)
{
  unsigned oldest = 0;
  int index = -1;
  lru.resize (cset.num_lines ());

  for (unsigned i = 0; i < cset.num_lines (); i++)
    {
      cache_line& line = cset.get_line (i);
      if (!line.valid_p ())
	{
	  index = i;
	  break;
	}
      else if (!line.locked_p () && lru[i] > oldest)
	{
	  index = i;
	  oldest = lru[i];
	}
    }

  if (index < 0)
    return 0;

  lru[index] = 0;
  return &cset.get_line (index);
}

void
cache_replacement_lru::update (cache_set& cset, cache_line& selected_line)
{
  cache_tag t = selected_line.tag ();
  for (unsigned i = 0; i < lru.size (); i++)
    {
      if (cset.get_line (i) == t)
	lru[i] = 0;
      else
	lru[i]++;
    }
}

cache_line *
cache_replacement_null::expell (cache_set& cset)
{
  cache_line& line = cset.get_line (0);
  if (!line.locked_p ())
    return &line;

  return 0;
}

cache_line *
cache_replacement_random::expell (cache_set& cset)
{
  for (unsigned i = 0; i < cset.num_lines (); i++)
    {
      cache_line& line = cset.get_line (i);
      if (!line.valid_p ())
	return &line;
    }

  unsigned n = cset.num_lines ();
  vector<bool> candidates(n, true);

  while (n > 0)
    {
      unsigned i = rand () % cset.num_lines ();
      
      // Try, try again.
      if (!candidates[i]) continue;

      cache_line& line = cset.get_line (i);
      if (!line.locked_p ())
	return &line;

      candidates[i] = false;
      n--;
    }

  return 0;
}


static vector<string>
CacheListTypes ()
{
  string type;
  vector<string> types;

  types.push_back ("hw-cache-basic");
  types.push_back ("hw-blocking-cache-basic");

  for (unsigned i = 0; i < (sizeof (buffer_sizes) / sizeof (string)); i++)
    {
      types.push_back ("hw-cache-buffer-" + buffer_sizes[i]);
      types.push_back ("hw-blocking-cache-buffer-" + buffer_sizes[i]);
    }

  for (unsigned i = 0; i < (sizeof (assocs) / sizeof (string)); i++)
    for (unsigned j = 0; j < (sizeof (cache_sizes) / sizeof (string)); j++)
      for (unsigned k = 0; k < (sizeof (line_sizes) / sizeof (string)); k++)
	{
	  if (assocs[i] == "direct")
	    {
	      type = cache_sizes[j] + "kb/";
	      type += line_sizes[k];
	      types.push_back ("hw-cache-direct/" + type);
	      types.push_back ("hw-blocking-cache-direct/" + type);
	    }
	  else
	    for (unsigned m = 0;
		 m < (sizeof (replacement_algorithms) / sizeof (string)); m++)
	      {
		type = assocs[i] + "/";
		type += cache_sizes[j] + "kb/";
		type += line_sizes[k] + "/";
		type += replacement_algorithms[m];
		types.push_back ("hw-cache-" + type);
		types.push_back ("hw-blocking-cache-" + type);
	      }
	}

  for (unsigned i = 0; i < (sizeof (assocs) / sizeof (string)); i++)
    for (unsigned j = 0; j < (sizeof (cache_sizes) / sizeof (string)); j++)
      for (unsigned k = 0; k < (sizeof (line_sizes) / sizeof (string)); k++)
	{
	  type = "hw-mep-cache-";
	  type += assocs[i] + "/";
	  type += cache_sizes[j] + "kb/";
	  type += line_sizes[k];
	  types.push_back (type);
	}

  return types;
}

static component *
create_mep_cache (vector<string>& parts)
{
  // decode cache types: hw-mep-cache-<assoc>/<s>kb/<ls>
  //
  string assoc_string = parts[3];

  bool match;
  int i;
  for (match = false, i = 0; i < sizeof (assocs) / sizeof (string); i++)
    if (assoc_string == assocs[i])
      match = true;

  if (!match)
    return 0;
  
  // Parse "<x>kb", where <x> is a positive integer. 
  int cache_sz;
  string cache_size_string = parts[4].substr (0, parts[4].length() - 2);
  for (match = false, i = 0; i < sizeof (cache_sizes) / sizeof (string); i++)
    if (cache_size_string == cache_sizes[i])
      {
	cache_sz = atoi (cache_size_string.c_str ()) * 1024;
	match = true;
      }

  if (!match)
    return 0;
  
  int line_sz;
  string line_size_string = parts[5];
  for (match = false, i = 0; i < sizeof (line_sizes) / sizeof (string); i++)
    if (line_size_string == line_sizes[i])
      {
	line_sz = atoi (line_size_string.c_str ());
	match = true;
      }

  if (!match)
    return 0;

  int assoc;
  if (assoc_string == "direct")
    assoc = 1;
  else
    {
      int pos;
      if ((pos = assoc_string.find ("way", 0)) == string::npos)
	return 0;

      assoc_string.erase (pos, assoc_string.length () - pos);
      if ((assoc = atoi (assoc_string.c_str ())) == 0)
	return 0;
    }

  if (assoc == 1)
    return new mep_cache (assoc, cache_sz, line_sz, null_replacement);
  
  return new mep_cache (assoc, cache_sz, line_sz, mep_assoc_replacement);
}

static component*
CacheCreate (const string& typeName)
{
  unsigned i;
  bool match;

  if (typeName == "hw-cache-basic")
    return new cache_component (1, 16384, 32, null_replacement, internal_line_factory);

  if (typeName == "hw-blocking-cache-basic")
    return new blocking_cache_component (1, 16384, 32, null_replacement, internal_line_factory);

  if (typeName.substr (0, 16) == "hw-cache-buffer-")
    {
      unsigned size;
      if (parse_attribute (typeName.substr (16), size) != sid::component::ok)
	return 0;
      return new cache_component (0, size, size, null_replacement, internal_line_factory);
    }
  
  if (typeName.substr (0, 25) == "hw-blocking-cache-buffer-")
    {
      unsigned size;
      if (parse_attribute (typeName.substr (25), size) != sid::component::ok)
	return 0;
      return new blocking_cache_component (0, size, size, null_replacement, internal_line_factory);
    }
  
  vector<string> parts = sidutil::tokenize (typeName, "-/");

  if (parts.size () >= 6 && parts[0] == "hw" && parts[1] == "mep" && parts[1] != "cache")
    return create_mep_cache (parts);

  unsigned extra_ix;
  if (parts.size () >= 5 && parts[0] == "hw" && parts[1] == "cache")
    extra_ix = 0;
  else if (parts.size () >= 6 && parts[0] == "hw" && parts[1] == "blocking" && parts[2] == "cache")
    extra_ix = 1;
  else
    return 0;
  
  string assoc_string = parts[2 + extra_ix];
  for (match = false, i = 0; i < sizeof (assocs) / sizeof (string); i++)
    if (assoc_string == assocs[i])
      match = true;

  if (!match)
    return 0;
  
  // Parse "<x>kb", where <x> is a positive integer. 
  int cache_sz;
  string cache_size_string = parts[3 + extra_ix].substr (0, parts[3 + extra_ix].length() - 2);
  for (match = false, i = 0; i < sizeof (cache_sizes) / sizeof (string); i++)
    if (cache_size_string == cache_sizes[i])
      {
	cache_sz = atoi (cache_size_string.c_str ()) * 1024;
	match = true;
      }

  if (!match)
    return 0;
  
  int line_sz;
  string line_size_string = parts[4 + extra_ix];
  for (match = false, i = 0; i < sizeof (line_sizes) / sizeof (string); i++)
    if (line_size_string == line_sizes[i])
      {
	line_sz = atoi (line_size_string.c_str ());
	match = true;
      }

  if (!match)
    return 0;
  
  string replace_alg_string;
  if (assoc_string != "direct")
    if (parts.size () + extra_ix < 6)
      return 0;
    else
      {
	replace_alg_string = parts[5 + extra_ix];
	for (match = false, i = 0; i < sizeof (replacement_algorithms) / sizeof (string); i++)
	  if (replace_alg_string == replacement_algorithms[i])
	    match = true;
	
	if (!match)
	  return 0;
      }
  
  int assoc;
  if (assoc_string == "full")
    assoc = 0;
  else if (assoc_string == "direct")
    assoc = 1;
  else
    {
      int pos;
      if ((pos = assoc_string.find ("way", 0)) == string::npos)
        return 0;
      assoc_string.erase (pos, assoc_string.length () - pos);
      if ((assoc = atoi (assoc_string.c_str ())) == 0)
        return 0;
    }

  if (extra_ix == 0)
    {
      if (assoc == 1)
	return new cache_component (assoc, cache_sz, line_sz, null_replacement, internal_line_factory);
  
      if (replace_alg_string == "lru")
	return new cache_component (assoc, cache_sz, line_sz, lru_replacement, internal_line_factory);
      else if (replace_alg_string == "fifo")
	return new cache_component (assoc, cache_sz, line_sz, fifo_replacement, internal_line_factory);
      else if (replace_alg_string == "random")
	return new cache_component (assoc, cache_sz, line_sz, random_replacement, internal_line_factory);
    }
  else
    {
      if (assoc == 1)
	return new blocking_cache_component (assoc, cache_sz, line_sz, null_replacement, internal_line_factory);
  
      if (replace_alg_string == "lru")
	return new blocking_cache_component (assoc, cache_sz, line_sz, lru_replacement, internal_line_factory);
      else if (replace_alg_string == "fifo")
	return new blocking_cache_component (assoc, cache_sz, line_sz, fifo_replacement, internal_line_factory);
      else if (replace_alg_string == "random")
	return new blocking_cache_component (assoc, cache_sz, line_sz, random_replacement, internal_line_factory);
    }

  return 0;
}

static void
CacheDelete (component* c)
{
  delete dynamic_cast<cache_component*>(c);
}

DLLEXPORT extern const sid::component_library cache_component_library;

const sid::component_library cache_component_library =
{
  sid::COMPONENT_LIBRARY_MAGIC,
  &CacheListTypes,
  &CacheCreate,
  &CacheDelete
};
