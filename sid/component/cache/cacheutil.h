// cacheutil.h -- Helper classes for a generic memory cache. -*- C++ -*-

// Copyright (C) 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CACHEUTIL_H
#define CACHEUTIL_H

#include <vector>
#include <iostream>
#include <sidcomp.h>
#include <sidattrutil.h>

#include "log2.h"

typedef sid::host_int_4 cache_tag;
typedef sid::host_int_1 byte;

// The cache_line class represents a line in a cache:

// +-------+-----+----------------+ M = modified (dirty) bit
// | M V L | tag |     data       | V = valid bit
// +-------+-----+----------------+ L = lock bit
//           byte 0              N

class cache_line
{
public:
  cache_line (unsigned line_size);
  cache_line (unsigned line_size, cache_tag tag);
  cache_line (unsigned line_size, cache_tag tag, std::vector <byte> intial_data);
  cache_line (const cache_line&);
  cache_line& operator= (const cache_line&);
  virtual ~cache_line ();

  // Get the line's tag.
  cache_tag tag () const;

  // Mark the line dirty or clean.
  void dirty ();
  void clean ();

  // Mark the line valid or invalid.
  void validate ();
  void invalidate ();

  // Lock or unlock the line.
  void lock ();
  void unlock ();

  // Is the line dirty?
  bool dirty_p () const;

  // Is the line valid?
  bool valid_p () const;

  // Is the line locked?
  bool locked_p () const;

  // Insert a datum into the line, starting at byte offset.
  template <typename DataType>
  void insert (unsigned offset, DataType new_data)
  {
    assert (offset + sizeof (new_data) <= size);
    typename DataType::value_type mem_image = new_data.target_memory_value ();
    memcpy (& data[offset], & mem_image, sizeof (new_data));
    dirty_bit = true;
  }

  // Extract a datum from the line, starting at byte offset.
  template <typename DataType>
  void extract (unsigned offset, DataType& new_data) const
  {
    assert (offset + sizeof (new_data) <= size);
    typename DataType::value_type mem_image;
    memcpy (& mem_image, & data[offset], sizeof (new_data));
    new_data.set_target_memory_value (mem_image);
  }

  // Dump a line in human readable form to cout.
  void dump () const;

private:
  unsigned size;
  bool valid_bit;
  bool dirty_bit;
  bool lock_bit;
  byte *data;
  cache_tag atag;
};

// Allow cache tags and a line's cache tag to be compared directly.
bool operator== (const cache_tag&, const cache_line&);
bool operator== (const cache_line&, const cache_tag&);

// A class from which all replacement algorithms should be derived.

class cache_set;
class cache_replacement_algorithm
{
public:
  virtual ~cache_replacement_algorithm () {}

  // Place new_line in a cache slot. Point old_line to the existing line.
  // Return true if successful, false otherwise.
  virtual void replace (cache_set& cset, cache_line& old_line, cache_line new_line) = 0;

  // Update state (for example, treating LRU bits), if required.
  virtual void update (cache_set& cset, cache_line& accessed_line) {}
};


// The cache_set class represents a set of cache_lines.  For a 2-way
// associative cache, there will be just two lines in the set.

class cache_set
{
public:
  cache_set (unsigned line_size, unsigned nlines,
	     cache_replacement_algorithm& alg);
  virtual ~cache_set ();
 
  // Try to find a line in the cache with a matching tag. 
  // If found, set "hit" to true and return a ref to the line.
  // Otherwise, set "hit" to false.
  virtual cache_line& find (const cache_tag& tag, bool& hit);

  // Find any dirty cache line.  If found, set hit to true and return it.
  // Otherwise, set hit to false.
  virtual cache_line* find_any_dirty ();

  // Invalidate the entire set.
  void invalidate (); 

  // Is there any vacancy for a new line?
  bool vacancy_p () const;

  // Remove a line from the set.
  void expunge_line (cache_line& line);

  // Flush the entire set.
  void expunge (unsigned index);

  // Replace a line in the set with new_line.
  // Return false if the line cannot be placed, true otherwise.
  void replace_line (cache_line& old_line, cache_line new_line);

  // Return the number of lines in the set.
  unsigned num_lines () const;

  // Get a cache line from slot `i' of the set.
  cache_line& get_line (unsigned i) const;

  // Place a cache line into slot `i' of the set.
  void set_line (unsigned i, const cache_line line);

  // Dump diagnostics to cerr.
  virtual void dump () const;

  cache_line& operator[] (unsigned index)
  {
    assert (index < num_lines ());
    return *(lines[index]);
  }

private:
  cache_replacement_algorithm& replacer;
  std::vector <cache_line*> lines;
  typedef std::vector <cache_line*>::iterator iterator_t;
  typedef std::vector <cache_line*>::const_iterator const_iterator_t;
};


// The cache class represents the complete cache as a series of
// cache_sets.  For a fully-associative cache, there will be one set
// with many lines.  For a direct mapped cache, there will be many
// sets of single lines.  Provide high-level methods for the user.

// The constructor builds a cache cache_size bytes in size and of the
// specified associativity.  0=fully assoc., 1=direct mapped, 2=2-way,
// etc.  The replacement algorithm is user-provided.

class cache
{
public:
  cache (unsigned cache_size, unsigned line_size,
	 unsigned assoc, cache_replacement_algorithm& replacer);
  virtual ~cache ();

  // Calculate a tag.
  cache_tag addr_to_tag (const sid::host_int_4& addr) const;

  // Perform the inverse operation.
  sid::host_int_4 tag_to_addr (const cache_tag& tag) const;
  
  // Find a line, given a tag.  If found, set hit to true and return it.
  // Otherwise, set hit to false.
  cache_line& find (cache_tag tag, bool& hit);

  // Find any dirty cache line.  If found, set hit to true and return it.
  // Otherwise, set hit to false.
  cache_line* find_any_dirty ();

  // Remove a line from the cache.
  void expunge (cache_line& line);

  // Vacancy in the cache?
  bool vacancy_p (const sid::host_int_4& addr) const;

  // Replace a line in the cache with 'new_line'.  If the expelled
  // line is dirty, set 'old_line' to it and return true, otherwise
  // false.
  void replace (cache_line& old_line, cache_line new_line);

  // Invalidate the entire cache.
  void invalidate ();

  // Invalidate a specific set (indexed).
  void invalidate (unsigned index);

  // The number of sets in the cache.
  unsigned num_sets ();

  // Dump the entire cache's state.
  void dump () const;

  // index = (addr & mask) >> shift
  struct
  {
    sid::host_int_4 mask;
    unsigned shift;
  } hash_params;

  cache_set& operator[] (unsigned index)
  {
    assert (index < num_sets ());
    return *(sets[index]);
  }
    
private:
  // Compute the index into the cache.
  unsigned hash_fn (const cache_tag& tag) const;

  // The number of non-tag bits in an address.
  unsigned num_non_tag_bits;

  std::vector <cache_set*> sets;
  typedef std::vector <cache_set*>::iterator iterator_t;
  typedef std::vector <cache_set*>::const_iterator const_iterator_t;
};

#endif // CACHEUTIL_H
