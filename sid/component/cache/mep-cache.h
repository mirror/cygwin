// mep-cache.h - Class declaration for the Toshiba Media Engine (MeP) Cache
// -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_CACHE_H
#define MEP_CACHE_H

#include "sidcpuutil.h"
#include "cache.h"

class mep_cache;

using namespace sidutil;

// The mep_cache_line class keeps its data and tags in global memory.

class mep_cache_line : public cache_line
{
public:
  mep_cache_line (unsigned line_size, unsigned index, unsigned way, mep_cache &c);
 ~mep_cache_line () {}

  // Get the line's tag.
  void set_tag (cache_tag tag);
  void clear_tag ();
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

  // Maintain the R bit.
  int get_R () const;
  void set_R (int);

  // Is the line dirty?
  bool dirty_p () const;

  // Is the line valid?
  bool valid_p () const;

  // Is the line locked?
  bool locked_p () const;

#define DEFN_METHOD(DataType) \
  /* Insert a datum into the line, starting at byte offset.  */ \
  virtual void insert (unsigned offset, DataType new_data); \
  /* Extract a datum from the line, starting at byte offset.  */ \
  virtual void extract (unsigned offset, DataType& new_data) const;

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
  void set_raw_tag (cache_tag tag);
  cache_tag raw_tag () const;

  unsigned my_size;
  unsigned my_way;
  int my_index;
  int index_shift;
  cache_tag index_mask;
  cache_tag address_mask;
  mep_cache &my_cache;
};

// The cache_line_factory creates and destroys cache lines. This
// implementation maps the tags and data to global memory via
// the cache's test_area_bus.
//
class mep_cache_line_factory : public cache_line_factory
{
public:
  mep_cache_line_factory (mep_cache &c) :
    cache (c)
    {}
 ~mep_cache_line_factory () {}

  cache_line *make_line (unsigned line_size, unsigned index, unsigned way)
  {
    return new mep_cache_line (line_size, index, way, cache);
  }
private:
  mep_cache &cache;
};

// Replacement alorithm for MeP associative caches
//
class mep_assoc_replacement_algorithm : public cache_replacement_algorithm
{
public:
  virtual ~mep_assoc_replacement_algorithm () {}

  // Choose a line to replace in a cache set. Return it, if successful
  virtual cache_line *expell (cache_set &set);
};

// The actual MEP_CACHE component.
// Inherit from the generic cache component.
//
class mep_cache: public blocking_cache_component
{
public:
  mep_cache (unsigned assoc, unsigned cache_sz, unsigned line_sz,
	     cache_replacement_algorithm& replacer);
 ~mep_cache () throw() {}

 unsigned size () const { return cache_size; }
 unsigned assoc () const { return blocking_cache_component::assoc; }

 void write_tag (unsigned way, int index, cache_tag atag);
 cache_tag read_tag (unsigned way, int index);

#define DEFN_METHOD(DataType) \
  /* Insert a datum into the line at the given index, starting at byte offset.  */ \
  void write_data (unsigned way, int index, unsigned offset, DataType new_data); \
  /* Extract a datum from the line at the given index, starting at byte offset.  */ \
  void read_data (unsigned way, int index, unsigned offset, DataType& new_data) const;

DEFN_METHOD (sid::big_int_1)
DEFN_METHOD (sid::big_int_2)
DEFN_METHOD (sid::big_int_4)
DEFN_METHOD (sid::big_int_8)
DEFN_METHOD (sid::little_int_1)
DEFN_METHOD (sid::little_int_2)
DEFN_METHOD (sid::little_int_4)
DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

  void dump_data (unsigned way, int index) const;

private:
  bus* tag_test_mem;
  bus* data_test_mem;
  callback_pin<mep_cache> clear_tag_pin;
  void clear_tag (host_int_4 addr);
  callback_pin<mep_cache> endian_set_pin;
  void endian_set_pin_handler(sid::host_int_4 v);
  endian endianness;

  virtual void configure (const string &config);
};
#endif // CACHE_H
