// cache.cxx -- A universal memory cache. -*- C++ -*-

// Copyright (C) 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidtypes.h>

#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include "cache.h"

string line_sizes[] =
  { "16", "32", "64", "128" };

string cache_sizes[] =
  { "8", "16", "32", "64", "128", "256", "512" };

string assocs[] =
  { "direct", "full", "2way", "4way" };

string replacement_algorithms[] =
  { "lru", "fifo", "random" }; 

// One per replacement policy
static cache_replacement_null null_replacement;
static cache_replacement_lru lru_replacement;
static cache_replacement_fifo fifo_replacement;
static cache_replacement_random random_replacement;

cache_component::cache_component (unsigned assocy,
				  unsigned cache_sz, 
				  unsigned line_sz,
				  cache_replacement_algorithm& replacer)
  :report_pin (this, &cache_component::emit_report),
   flush_pin (this, &cache_component::flush_line),
   invalidate_all_pin (this, &cache_component::invalidate_all_lines),
   invalidate_pin (this, &cache_component::invalidate_line),
   prefetch_pin (this, &cache_component::prefetch_line),
   lock_pin (this, &cache_component::lock_line),
   unlock_pin (this, &cache_component::unlock_line),
   write_allocate_p (false),
   write_through_p (false),
   downstream (0),
   upstream (*this),
   collect_p (true),
   line_size (line_sz),
   cache_size (cache_sz),
   assoc (assocy),
   report_heading ("cache profile report"),
   acache (cache_sz, line_sz, assocy, replacer)
{
  memset (&stats, 0, sizeof (stats));

  add_bus ("upstream", &upstream);
  add_accessor ("downstream", &downstream);
  
  add_pin ("report!", &report_pin);
  add_pin ("flush", &flush_pin);
  add_pin ("invalidate-all", &invalidate_all_pin);
  add_pin ("invalidate", &invalidate_pin);
  add_pin ("prefetch", &prefetch_pin);
  add_pin ("lock", &lock_pin);  
  add_pin ("unlock", &unlock_pin);
  
  add_attribute_ro ("cache-size", &cache_size, "setting");
  add_attribute_ro ("line-size", &line_size, "setting");
  add_attribute_virtual ("associativity", this,
			 &cache_component::associativity,
			 &cache_component::set_nothing,
			 "setting");

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

  // FIXME: state save/restore
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
  bool hit;
  bus::status st;

  if (UNLIKELY (downstream == 0))
    return bus::unmapped;

  if (LIKELY (collect_p))
    stats.writes++;

  if (UNLIKELY (addr % sizeof (data) != 0))
    {
      // Punt on misaligned accesses
      if (LIKELY (collect_p))
	stats.misaligned_writes++;

      cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
      if (hit)
      {
	if (line.dirty_p ())
        {	
	  // flush a dirty line being replaced
	  if ((st = write_line (line)) != bus::ok)
	    return st;
	}
	acache.expunge (line);
      }
      return downstream->read (addr, data);
    }

  cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
  if (LIKELY (hit))
    {
      if (LIKELY (collect_p))
	stats.write_hits++;
      line.insert (line_offset (line, addr), data);
      if (write_through_p)
	{
	  if ((st = downstream->write (addr, data)) != bus::ok)
	    return st;
	}
    }
  else
    {
      if (write_allocate_p)
	{
	  if (acache.vacancy_p (addr))
	    {
	      cache_line expelled_line (line_size);
	      cache_line new_line (line_size, acache.addr_to_tag (addr));
	      if ((st = read_line (new_line)) != bus::ok)
		return st;
	      
	      new_line.insert (line_offset (new_line, addr), data);
	      acache.replace (expelled_line, new_line);
	      
	      if (collect_p)
		stats.replacements++;
	      
	      if (expelled_line.dirty_p () && !write_through_p)
		{
		  // flush a dirty line being replaced
		  if ((st = write_line (expelled_line)) != bus::ok)
		    return st;
		}
	      
	      if (write_through_p)
		{
		  if ((st = downstream->write (addr, data)) != bus::ok)
		    return st;
		}
	    }
	}
      else
	{
	  // write through to memory to preserve the write
	  if ((st = downstream->write (addr, data)) != bus::ok)
	    return st;
	}
    }
  return bus::ok;
}

template <typename DataType>
bus::status
cache_component::read_any (host_int_4 addr, DataType& data)
{
  if (UNLIKELY (downstream == 0))
    return bus::unmapped;

  if (LIKELY (collect_p))
    stats.reads++;

  // Punt on misaligned accesses
  if (UNLIKELY (addr % sizeof (data) != 0))
    {
      if (LIKELY (collect_p))
	stats.misaligned_reads++;
      return downstream->read (addr, data);
    }

  bool hit;
  bus::status st;

  cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
  if (LIKELY (hit))
    {
      if (LIKELY (collect_p))
	stats.read_hits++;
      line.extract (line_offset (line, addr), data);
    }
  else
    {
      // miss!
      if (acache.vacancy_p (addr))
	{
	  cache_line expelled_line (line_size);
	  cache_line new_line (line_size, acache.addr_to_tag (addr));
	  
	  if ((st = read_line (new_line)) != bus::ok)
	    return st;
	  new_line.extract (line_offset (new_line, addr), data);

	  acache.replace (expelled_line, new_line);

	  if (collect_p)
	    stats.replacements++;
	  
	  if (expelled_line.dirty_p ())
	    {
	      // flush a dirty line being replaced
	      if ((st = write_line (expelled_line)) != bus::ok)
		return st;
	    }
	}
      else
	return downstream->read (addr, data);
    }
  return bus::ok;
}

bus::status
cache_component::read_line (cache_line& line)
{
  host_int_4 base = acache.tag_to_addr (line.tag ());
  for (host_int_4 offset = 0; offset < line_size; offset += 4)
    {
      sid::big_int_4 data;
      bus::status st = downstream->read (base + offset, data);
      if (st != bus::ok)
	return st;
      line.insert (offset, data);
    }
  line.unlock ();
  line.clean ();
  line.validate ();
  return bus::ok;
}

bus::status
cache_component::write_line (cache_line& line)
{
  host_int_4 base = acache.tag_to_addr (line.tag ());
  for (host_int_4 offset = 0; offset < line_size; offset += 4)
    {
      sid::big_int_4 data;
      line.extract (offset, data);
      bus::status st = downstream->write (base + offset, data);
      if (st != bus::ok)
	return st;
    }
  line.clean ();
  if (LIKELY (collect_p))
    stats.flushes++;
  return bus::ok;
}

void
cache_component::flush_line (host_int_4 addr)
{
  bool hit;
  cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
  if (hit && line.dirty_p ())
    bus::status st = write_line (line);
}

void
cache_component::invalidate_all_lines (host_int_4 ignore)
{
  acache.invalidate ();
}

void
cache_component::invalidate_line (host_int_4 addr)
{
  bool hit;
  cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
  if (hit)
    line.invalidate ();
}

void
cache_component::prefetch_line (host_int_4 addr)
{
  sid::big_int_1 dummy;
  bus::status st = read_any (addr, dummy);
}

void
cache_component::lock_line (host_int_4 addr)
{
  bool hit;
  cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
  if (hit)
    line.lock ();
}

void
cache_component::unlock_line (host_int_4 addr)
{
  bool hit;
  cache_line& line = acache.find (acache.addr_to_tag (addr), hit);
  if (hit)
    line.unlock ();
}

void
cache_component::emit_report (host_int_4 ignore)
{
  cout << report_heading << endl << endl
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
cache_component::set_hash_mask (const string& value)
{
  unsigned shift;
  parse_attribute (value, shift);

  if ((acache.hash_params.mask >> shift) >= acache.num_sets ())
    return sid::component::bad_value;

  acache.hash_params.shift = shift;
  return sid::component::ok;
}

sid::component::status
cache_component::set_hash_shift (const string& value)
{
  sid::host_int_4 mask;
  parse_attribute (value, mask);

  if ((mask >> acache.hash_params.shift) >= acache.num_sets ())
    return sid::component::bad_value;

  acache.hash_params.mask = mask;
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

void
cache_replacement_fifo::replace (cache_set& cset, cache_line& old_line, cache_line new_line)
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
	  old_line = line;
	  old_line.invalidate ();
	  cset.set_line (i, new_line);

	  // update state
	  fifo[i] = 0;
	  return;
	}
      n--;
    }
}

void
cache_replacement_lru::replace (cache_set& cset, cache_line& old_line, cache_line new_line)
{
  int oldest;
  int index = -1;
  lru.resize (cset.num_lines ());

  for (unsigned i = 0, oldest = 0; i < cset.num_lines (); i++)
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
    return;
  
  old_line = cset.get_line (index);
  old_line.invalidate ();
  cset.set_line (index, new_line);
  lru[index] = 0;
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

void
cache_replacement_null::replace (cache_set& cset, cache_line& old_line, cache_line new_line)
{
  cache_line& line = cset.get_line (0);
  if (!line.locked_p ())
    {
      old_line = line;
      old_line.invalidate ();
      cset.set_line (0, new_line);
    }
}

void
cache_replacement_random::replace (cache_set& cset, cache_line& old_line, cache_line new_line)
{
  for (unsigned i = 0; i < cset.num_lines (); i++)
    {
      cache_line& line = cset.get_line (i);
      if (!line.valid_p ())
	{
	  old_line = line;
	  old_line.invalidate ();
	  cset.set_line (i, new_line);
	  return;
	}
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
	{
	  old_line = line;
	  old_line.invalidate ();
	  cset.set_line (i, new_line);
	  return;
	}
      else
	{
	  candidates[i] = false;
	  n--;
	}
    }
}


extern const sid::component_library cache_component_library;

static vector<string>
CacheListTypes ()
{
  string type;
  vector<string> types;

  types.push_back ("hw-cache-basic");

  for (int i = 0; i < (sizeof (assocs) / sizeof (string)); i++)
    for (int j = 0; j < (sizeof (cache_sizes) / sizeof (string)); j++)
      for (int k = 0; k < (sizeof (line_sizes) / sizeof (string)); k++)
	{
	  if (assocs[i] == "direct")
	    {
	      type = string ("hw-cache-direct/");
	      type += cache_sizes[j] + "kb/";
	      type += line_sizes[k];
	      types.push_back (type);
	    }
	  else
	    for (int m = 0;
		 m < (sizeof (replacement_algorithms) / sizeof (string)); m++)
	      {
		type = string ("hw-cache-");
		type += assocs[i] + "/";
		type += cache_sizes[j] + "kb/";
		type += line_sizes[k] + "/";
		type += replacement_algorithms[m];
		types.push_back (type);
	      }
	}
  return types;
}

static component*
CacheCreate (const string& typeName)
{
  bool match;
  int i, index = 0, pos;
  int assoc, linesz, cachesz;

  if (typeName == "hw-cache-basic")
    return new cache_component (1, 16384, 32, null_replacement);

  if (typeName.find ("hw-cache-", index) != 0)
    return 0;
  index += strlen ("hw-cache-");
  
  // parse assoc + "/"
  if ((pos = typeName.find_first_of ("/", index)) == string::npos)
    return 0;
  string assoc_string = typeName.substr (index, (pos - index));
  index = pos + 1;

  string cache_size_string;

  // Parse "<x>kb", where <x> is a positive integer. 
  if ((pos = typeName.find_first_of ("/", index)) == string::npos)
    return 0;
  cache_size_string = typeName.substr (index, (pos - index));
  index = pos + 1;

  if ((pos = cache_size_string.find ("kb", 0)) == string::npos)
    return 0;
  cache_size_string.erase (pos, cache_size_string.length () - pos);

  string line_size_string;
  string replace_alg_string;

  if (assoc_string == "direct")
    line_size_string = typeName.substr (index, (typeName.length () - index));
  else
    {
      if ((pos = typeName.find_first_of ("/", index)) == string::npos)
	return 0;
      line_size_string = typeName.substr (index, (pos - index));
      index = pos + 1;
      replace_alg_string = typeName.substr (index, (typeName.length () - index));
    }

  for (match = false, i = 0; i < sizeof (assocs) / sizeof (string); i++)
    if (assoc_string == assocs[i]) 
      match = true;
  if (!match)
    return 0;

  for (match = false, i = 0; i < sizeof (cache_sizes) / sizeof (string); i++)
    if (cache_size_string == cache_sizes[i])
      {
	cachesz = atoi (cache_size_string.c_str ()) * 1024;
	match = true;
      }
  if (!match)
    return 0;
  
  for (match = false, i = 0; i < sizeof (line_sizes) / sizeof (string); i++)
    if (line_size_string == line_sizes[i])
      {
	linesz = atoi (line_size_string.c_str ());
	match = true;
      }
  if (!match)
    return 0;
  
  if (assoc_string != "direct")
    {
      for (match = false, i = 0;
	   i < sizeof (replacement_algorithms) / sizeof (string); i++)
	{
	  if (replace_alg_string == replacement_algorithms[i])
	    match = true;
	}
      if (!match)
	return 0;
    }

  if (assoc_string == "full")
    assoc = 0;
  else if (assoc_string == "direct")
    assoc = 1;
  else
    {
      if ((pos = assoc_string.find ("way", 0)) == string::npos)
        return 0;
      assoc_string.erase (pos, assoc_string.length () - pos);
      if ((assoc = atoi (assoc_string.c_str ())) == 0)
        return 0;
    }

  if (assoc == 1)
    return new cache_component (assoc, cachesz, linesz, null_replacement);

  if (replace_alg_string == "lru")
    return new cache_component (assoc, cachesz, linesz, lru_replacement);
  else if (replace_alg_string == "fifo")
    return new cache_component (assoc, cachesz, linesz, fifo_replacement);
  else if (replace_alg_string == "random")
    return new cache_component (assoc, cachesz, linesz, random_replacement);

  return 0;
}

static void
CacheDelete (component* c)
{
  delete dynamic_cast<cache_component*>(c);
}

const sid::component_library cache_component_library DLLEXPORT =
{
  sid::COMPONENT_LIBRARY_MAGIC,
  &CacheListTypes,
  &CacheCreate,
  &CacheDelete
};
