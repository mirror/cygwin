// cacheutil.h -- Helper classes for a generic memory cache. -*- C++ -*-

// Copyright (C) 2001, 2002, 2004, 2005 Red Hat.
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

// The cache_line class represents a line in a cache. It is a virtual base
// class which requires an implementation.

class cache_line
{
public:
  virtual ~cache_line () {}

  // Get the line's tag.
  virtual void set_tag (cache_tag tag) = 0;
  virtual cache_tag tag () const = 0;

  // Mark the line dirty or clean.
  virtual void dirty () = 0;
  virtual void clean () = 0;

  // Mark the line valid or invalid.
  virtual void validate () = 0;
  virtual void invalidate () = 0;

  // Lock or unlock the line.
  virtual void lock () = 0;
  virtual void unlock () = 0;

  // Is the line dirty?
  virtual bool dirty_p () const = 0;

  // Is the line valid?
  virtual bool valid_p () const = 0;

  // Is the line locked?
  virtual bool locked_p () const = 0;

  // Insert or extract a datum from the line, starting at byte offset.
#define DEFN_METHOD(DataType) \
  virtual void insert (unsigned offset, DataType new_data) = 0; \
  virtual void extract (unsigned offset, DataType& new_data) const = 0;

  DEFN_METHOD (sid::big_int_1)
  DEFN_METHOD (sid::big_int_2)
  DEFN_METHOD (sid::big_int_4)
  DEFN_METHOD (sid::big_int_8)
  DEFN_METHOD (sid::little_int_1)
  DEFN_METHOD (sid::little_int_2)
  DEFN_METHOD (sid::little_int_4)
  DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

  // Dump a line in human readable form to cout.
  virtual void dump () const;
  virtual void dump_data () const = 0;
};

// The internal_cache_line class keeps its data internally and is the default
// cache_line implementation.

// +-------+-----+----------------+ M = modified (dirty) bit
// | M V L | tag |     data       | V = valid bit
// +-------+-----+----------------+ L = lock bit
//           byte 0              N

class internal_cache_line : public cache_line
{
public:
  internal_cache_line (unsigned line_size);
  ~internal_cache_line ();

  // Get the line's tag.
  void set_tag (cache_tag tag);
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

#define DEFN_METHOD(DataType) \
  /* Insert a datum into the line, starting at byte offset.  */ \
  virtual void insert (unsigned offset, DataType new_data) \
  { \
    assert (offset + sizeof (new_data) <= size); \
    DataType::value_type mem_image = new_data.target_memory_value (); \
    memcpy (& data[offset], & mem_image, sizeof (new_data)); \
    dirty_bit = true; \
  } \
  /* Extract a datum from the line, starting at byte offset.  */ \
  virtual void extract (unsigned offset, DataType& new_data) const \
  { \
    assert (offset + sizeof (new_data) <= size); \
    DataType::value_type mem_image; \
    memcpy (& mem_image, & data[offset], sizeof (new_data)); \
    new_data.set_target_memory_value (mem_image); \
  }

  DEFN_METHOD (sid::big_int_1)
  DEFN_METHOD (sid::big_int_2)
  DEFN_METHOD (sid::big_int_4)
  DEFN_METHOD (sid::big_int_8)
  DEFN_METHOD (sid::little_int_1)
  DEFN_METHOD (sid::little_int_2)
  DEFN_METHOD (sid::little_int_4)
  DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

  // Dump a line in human readable form to cout.
  void dump_data () const;

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

  // Choose a line to replace in a cache set. Return it, if successful
  virtual cache_line *expell (cache_set &set) = 0;

  // Update state (for example, treating LRU bits), if required.
  virtual void update (cache_set& cset, cache_line &accessed_line) {}
};

// The cache_line_factory creates and destroys cache lines. This default
// implementation creates lines of type internal_cache_line.

class cache_line_factory
{
public:
  virtual ~cache_line_factory () {}

  virtual cache_line *make_line (unsigned line_size, unsigned index, unsigned way)
  {
    return new internal_cache_line (line_size);
  }
  virtual void destroy_line (cache_line *line)
  {
    delete line;
  }
};

// The cache_set class represents a set of cache_lines.  For a 2-way
// associative cache, there will be just two lines in the set.

class cache_set
{
public:
  cache_set (unsigned line_size, unsigned nlines,
	     cache_replacement_algorithm& alg, cache_line_factory &f);
  virtual ~cache_set ();

  void allocate_lines (unsigned index);

  // Try to find a line in the cache with a matching tag. 
  // If found, return it.
  virtual cache_line* find (const cache_tag& tag);

  // Find any dirty cache line.  If found, return the line
  virtual cache_line* find_any_dirty ();

  // Invalidate the entire set.
  void invalidate (); 

  // Is there any vacancy for a new line?
  bool vacancy_p () const;

  // Remove a line from the set.
  void expunge_line (cache_line& line);

  // Flush the entire set.
  void expunge (unsigned index);

  // Choose a line to be replaced. Return it, if successful.
  cache_line *expell_line ();

  // Return the number of lines in the set.
  unsigned num_lines () const;

  // Get a cache line from slot `i' of the set.
  cache_line& get_line (unsigned i) const;

  // Place a cache line into slot `i' of the set.
  void set_line (unsigned i, cache_line &line);

  // Dump diagnostics to cerr.
  virtual void dump () const;

  cache_line& operator[] (unsigned index)
  {
    assert (index < num_lines ());
    return *(lines[index]);
  }

private:
  cache_replacement_algorithm& replacer;
  cache_line_factory& line_factory;
  std::vector <cache_line*> lines;
  unsigned line_size;
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
	 unsigned assoc, cache_replacement_algorithm& replacer,
	 cache_line_factory &line_factory);
  virtual ~cache ();

  void init ();

  // Calculate a tag.
  cache_tag addr_to_tag (const sid::host_int_4& addr) const;

  // Calculate a set index.
  unsigned addr_to_index (const sid::host_int_4& addr) const;

  // Perform the inverse operation.
  sid::host_int_4 tag_to_addr (const cache_tag& tag) const;
  
  // Find a line, given a tag.  If found, return it.
  cache_line* find (cache_tag tag);

  // Find any dirty cache line.  If found, set hit to true and return it.
  // Otherwise, set hit to false.
  cache_line* find_any_dirty ();

  // Remove a line from the cache.
  void expunge (cache_line& line);

  // Vacancy in the cache?
  bool vacancy_p (const sid::host_int_4& addr) const;

  // Choose a line in the cache to expell in place of one
  // representing 'tag'. Return it, if successful.
  cache_line *expell_line (cache_tag tag);

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
