// cache.h -- A universal memory cache. -*- C++ -*-

// Copyright (C) 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CACHE_H
#define CACHE_H

#include "cacheutil.h"

using std::string;
using std::vector;

using sid::bus;
using sid::component;
using sid::host_int_2;
using sid::host_int_4;

using sidutil::fixed_attribute_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_accessor_map_component;
using sidutil::no_relation_component;
using sidutil::callback_pin;
using sidutil::make_attribute;
using sidutil::parse_attribute;

class cache_component;
class cache_bus: public bus
{
public:
  cache_bus (cache_component& c)
    :cache(c) {}

private:
  cache_component& cache;

  template <typename DataType>
  bus::status write_any (host_int_4 addr, DataType data);
  
  template <typename DataType>
  bus::status read_any (host_int_4 addr, DataType& data);

#define DEFN_METHOD(DataType) \
  bus::status write(host_int_4 addr, DataType data) throw (); \
  bus::status read(host_int_4 addr, DataType& data) throw ();
  
  DEFN_METHOD (sid::big_int_1)
  DEFN_METHOD (sid::big_int_2)
  DEFN_METHOD (sid::big_int_4)
  DEFN_METHOD (sid::big_int_8)
  DEFN_METHOD (sid::little_int_1)
  DEFN_METHOD (sid::little_int_2)
  DEFN_METHOD (sid::little_int_4)
  DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD
};

// FIFO cache replacement algorithm

class cache_replacement_fifo: public cache_replacement_algorithm
{
public:
  void replace (cache_set& cset, cache_line& old_line, cache_line new_line);

private:
  vector <int> fifo;
};

// Least recently used (LRU) replacement algorithm

class cache_replacement_lru: public cache_replacement_algorithm
{
public:
  void replace (cache_set& cset, cache_line& old_line, cache_line new_line);
  void update (cache_set& cset, cache_line& selected);

private:
  vector <unsigned> lru;
};

// Random replacement algorithm

class cache_replacement_random: public cache_replacement_algorithm
{
public:
  void replace (cache_set& cset, cache_line& old_line, cache_line new_line);
};

// Null replacement algorithm; used by direct mapped caches

class cache_replacement_null: public cache_replacement_algorithm
{
public:
  void replace (cache_set& cset, cache_line& old_line, cache_line new_line);
};


class cache_component: public virtual component,
		       protected fixed_attribute_map_component,
		       protected fixed_bus_map_component,
		       protected fixed_pin_map_component,
		       protected fixed_accessor_map_component,
		       protected no_relation_component
{
public:
  cache_component (unsigned asoctvty, unsigned cache_sz,
		   unsigned line_sz, cache_replacement_algorithm& replacer);

  ~cache_component () throw();

  template <typename DataType> bus::status 
  write_any (host_int_4 addr, DataType data);
  
  template <typename DataType> bus::status
  read_any (host_int_4 addr, DataType& data);

private:
  cache acache;

  cache_bus upstream;
  bus* downstream;

  callback_pin<cache_component> report_pin;
  void emit_report (host_int_4 ignore);

  callback_pin<cache_component> flush_all_pin;
  void flush_all_lines (host_int_4 ignore);

  callback_pin<cache_component> flush_pin;
  void flush_line (host_int_4 addr);

  callback_pin<cache_component> invalidate_all_pin;
  void invalidate_all_lines (host_int_4 ignore);

  callback_pin<cache_component> invalidate_pin;
  void invalidate_line (host_int_4 addr);

  callback_pin<cache_component> prefetch_pin;
  void prefetch_line (host_int_4 addr);

  callback_pin<cache_component> lock_pin;
  void lock_line (host_int_4 addr);

  callback_pin<cache_component> unlock_pin;
  void unlock_line (host_int_4 addr);

  string read_hit_rate ();
  string write_hit_rate ();
  string get_nothing () { return ""; }
  status set_nothing (const string& ignore) { return sid::component::ok; }
  string associativity ();
  status dump (const string& ignore);
  string get_hash_mask ();
  status set_hash_mask (const string& ignore);
  string get_hash_shift ();
  status set_hash_shift (const string& ignore);

  unsigned line_offset (const cache_line& line, const host_int_4& addr); 

  bus::status read_line (cache_line& line);
  bus::status write_line (cache_line& line);

  bool write_allocate_p;
  bool write_through_p;
  bool collect_p;
  string report_heading;

  struct
  {
    unsigned long reads;
    unsigned long writes;
    unsigned long read_hits;
    unsigned long write_hits;
    unsigned long misaligned_reads;
    unsigned long misaligned_writes;
    unsigned long flushes;
    unsigned long replacements;
  } stats;

  unsigned line_size;
  unsigned cache_size;
  unsigned assoc;

  host_int_2 hit_latency;
  host_int_2 miss_latency;
  host_int_2 refill_latency;
};

template <typename DataType>
bus::status
cache_bus::write_any (host_int_4 addr, DataType data)
{
  return cache.write_any (addr, data);
}
  
template <typename DataType>
bus::status
cache_bus::read_any (host_int_4 addr, DataType& data)
{
  return cache.read_any (addr, data);
}

#define DEFN_METHOD(DataType) \
  inline bus::status cache_bus::write(host_int_4 addr, DataType data) throw () { return this->write_any(addr, data); } \
  inline bus::status cache_bus::read(host_int_4 addr, DataType& data) throw () { return this->read_any(addr, data); }
  
DEFN_METHOD (sid::big_int_1)
DEFN_METHOD (sid::big_int_2)
DEFN_METHOD (sid::big_int_4)
DEFN_METHOD (sid::big_int_8)
DEFN_METHOD (sid::little_int_1)
DEFN_METHOD (sid::little_int_2)
DEFN_METHOD (sid::little_int_4)
DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

#endif // CACHE_H
