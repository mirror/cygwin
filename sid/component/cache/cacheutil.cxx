// cacheutil.cxx -- Helper classes for a generic memory cache. -*- C++ -*-

// Copyright (C) 2001, 2002, 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cacheutil.h"

bool
operator== (const cache_tag& tag, const cache_line& line)
{
  return (line.valid_p () && tag == line.tag ());
}

bool
operator== (const cache_line& line, const cache_tag& tag)
{
  return (line.valid_p () && tag == line.tag ());
}

using std::cerr;
using std::hex;
using std::setw;
using std::setfill;
using std::endl;
using std::dec;

void
cache_line::dump () const
{
  cerr << "  ";

  if (dirty_p ())  cerr << 'M'; else cerr << '-';
  if (valid_p ())  cerr << 'V'; else cerr << '-';
  if (locked_p ()) cerr << 'L'; else cerr << '-';

  cerr << "  " << hex << setw (4) << setfill ('0') << tag () << "\t";
  dump_data ();
  cerr << dec << endl;
}

void
internal_cache_line::dump_data () const
{
  for (unsigned i = 0; i < size; i++)
    cerr << setw (2) << setfill ('0') << static_cast<unsigned> (data[i]);
}

internal_cache_line::internal_cache_line (unsigned line_size)
  :size (line_size), valid_bit (false), dirty_bit (false), lock_bit (false), atag (0)
{
  data = new byte [line_size];
  memset (data, 0, line_size);
}

internal_cache_line::~internal_cache_line ()
{
  delete [] data;
}

void
internal_cache_line::dirty ()
{
  dirty_bit = true;
}

void
internal_cache_line::clean ()
{
  dirty_bit = false;
}

void
internal_cache_line::validate ()
{
  valid_bit = true;
}

void
internal_cache_line::invalidate ()
{
  valid_bit = false;
}

void
internal_cache_line::lock ()
{
  lock_bit = true;
}

void
internal_cache_line::unlock ()
{
  lock_bit = false;
}

void
internal_cache_line::set_tag (cache_tag tag)
{
  atag = tag;
}

cache_tag
internal_cache_line::tag () const
{
  return atag;
}

bool
internal_cache_line::dirty_p () const
{
  return dirty_bit;
}

bool
internal_cache_line::valid_p () const
{
  return valid_bit;
}

bool
internal_cache_line::locked_p () const
{
  return lock_bit;
}

cache_set::cache_set (unsigned line_sz, unsigned nlines, cache_replacement_algorithm& alg, cache_line_factory &f)
  :replacer (alg),
   line_factory (f),
   line_size (line_sz)
{
  lines.resize (nlines);
  for (iterator_t it = lines.begin(); it != lines.end (); it++)
    *it = NULL;
}

cache_set::~cache_set ()
{
  for (iterator_t it = lines.begin (); it != lines.end (); it++)
    line_factory.destroy_line (*it);
}

void
cache_set::allocate_lines (unsigned index)
{
  unsigned way = 0;
  for (iterator_t it = lines.begin(); it != lines.end (); way++, it++)
    *it = line_factory.make_line (line_size, index, way);
}

unsigned
cache_set::num_lines () const
{
  return lines.size ();
}

cache_line&
cache_set::get_line (unsigned i) const
{
  return *lines[i];
}

void
cache_set::set_line (unsigned i, cache_line &line)
{
  lines[i] = &line;
}

cache_line*
cache_set::find (const cache_tag& tag)
{
  // Scan the lines in this set for tag. Might as well be linear; the
  // order of associativity will be small.

  for (const_iterator_t it = lines.begin (); it != lines.end (); it++)
    if (tag == *(*it) && (*it)->valid_p ())
      {
	replacer.update (*this, *(*it));
	return *it;
      }

  return NULL;
}


cache_line*
cache_set::find_any_dirty ()
{
  for (iterator_t it = lines.begin (); it != lines.end (); it++)
    {
      cache_line* i = * it;
      if (i->valid_p () && i->dirty_p ()) return i;
    }

  return 0;
}

void
cache_set::invalidate ()
{
  for (iterator_t it = lines.begin (); it != lines.end (); it++)
    (*it)->invalidate ();
}

bool
cache_set::vacancy_p () const
{
  for (const_iterator_t it = lines.begin (); it != lines.end (); it++)
    if (!(*it)->valid_p () || !(*it)->locked_p ())
      return true;

  return false;
}
    
void
cache_set::expunge_line (cache_line& line)
{
  line.unlock ();
  line.clean ();
  line.invalidate ();
}

cache_line *
cache_set::expell_line ()
{
  cache_line *line = replacer.expell (*this);
  return line;
}

void
cache_set::dump () const
{
  for (const_iterator_t it = lines.begin (); it != lines.end (); it++)
    (*it)->dump ();
}

cache::cache (unsigned cache_size, unsigned line_size, unsigned assoc,
	      cache_replacement_algorithm& replacer,
	      cache_line_factory& line_factory)
{
  assert (power_of_two_p (line_size));
  assert (cache_size >= line_size);

  // The cache size must be an even multiple of the line size.
  assert ((cache_size % line_size) == 0);

  int num_lines = cache_size / line_size;
  if (assoc > 0)
    assert (num_lines % assoc == 0 && assoc < num_lines);
  
  // The number of sets.  
  // If the cache is fully associative, there is only one set.
  int num_sets = (assoc == 0) ? 1 : (num_lines / assoc);
  sets.resize (num_sets);

  // The number of lines per set.
  // If the cache is fully associative, there is one set with as many
  // lines as there are in the cache.
  int lines_per_set = (assoc == 0) ? num_lines : assoc;
 
  for (iterator_t it = sets.begin (); it != sets.end (); it++)
    *it = new cache_set (line_size, lines_per_set, replacer, line_factory);
  
  num_non_tag_bits = log2 (line_size);

  // Pick a default hash function: the next few bits above the intra-line address bits
  unsigned cache_set_bits = log2 (sets.size());
  hash_params.mask = ((1U << cache_set_bits) - 1) << num_non_tag_bits;
  hash_params.shift = num_non_tag_bits;
}

cache::~cache ()
{
  for (unsigned i = 0; i < sets.size (); i++)
    delete sets[i];
}

void
cache::init ()
{
  unsigned index = 0;
  for (iterator_t it = sets.begin (); it != sets.end (); it++, index++)
    (*it)->allocate_lines (index);
}
  
cache_tag
cache::addr_to_tag (const sid::host_int_4& addr) const
{
  return addr >> num_non_tag_bits;
}

unsigned
cache::addr_to_index (const sid::host_int_4& addr) const
{
  return hash_fn (addr_to_tag (addr));
}

sid::host_int_4
cache::tag_to_addr (const cache_tag& tag) const
{
  return tag << num_non_tag_bits;
}

cache_line*
cache::find (cache_tag tag)
{
  unsigned index = hash_fn (tag);
  return sets[index]->find (tag);
}

cache_line*
cache::find_any_dirty ()
{
  for (unsigned i = 0; i < this->num_sets(); i++)
    {
      cache_line* foo = sets[i]->find_any_dirty ();
      if (foo) return foo;
    }
  return 0;
}


unsigned
cache::num_sets ()
{
  return sets.size ();
}

bool
cache::vacancy_p (const sid::host_int_4& addr) const
{
  unsigned index = hash_fn (addr_to_tag (addr));
  return sets[index]->vacancy_p ();
}

void
cache::invalidate ()
{
  for (iterator_t it = sets.begin (); it != sets.end(); it++)
    (*it)->invalidate ();
}

void
cache::invalidate (unsigned index)
{
  if (index >= sets.size ())
    return;
  sets[index]->invalidate ();
}

// Remove a line from the cache.
void
cache::expunge (cache_line& line)
{
  unsigned index = hash_fn (line.tag ());
  sets[index]->expunge_line (line);
}

// Replace a line in the cache with 'new_line'.  If the expelled
// line is dirty, set 'old_line' to it and return true, otherwise
// false.
cache_line *
cache::expell_line (cache_tag tag)
{
  unsigned index = hash_fn (tag);
  return sets[index]->expell_line ();
}

unsigned
cache::hash_fn (const cache_tag& tag) const
{
  sid::host_int_4 addr = tag_to_addr (tag);
  unsigned index = (addr & hash_params.mask) >> hash_params.shift;
  if (UNLIKELY(index >= this->sets.size()))
    {
      cerr << "cache: bad hash parameters (mask=" 
	   << sidutil::make_numeric_attribute (this->hash_params.mask, std::ios::hex|std::ios::showbase)
	   << " shift="
	   << sidutil::make_numeric_attribute (this->hash_params.shift)
	   << ") for address="
	   << sidutil::make_numeric_attribute (addr, std::ios::hex|std::ios::showbase)
	   << " #sets="
	   << sidutil::make_numeric_attribute (this->sets.size())
	   << endl;
      index = index % this->sets.size();
    }
  return index;
}

void
cache::dump () const
{
  unsigned i = 0;
  for (const_iterator_t it = sets.begin (); it != sets.end (); it++, i++)
    {
      cerr << "set " << i << endl;
      (*it)->dump ();
    }
}
