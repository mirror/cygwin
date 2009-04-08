// cache.h -- A universal memory cache. -*- C++ -*-

// Copyright (C) 2001, 2002, 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CACHE_H
#define CACHE_H

#include "sidblockingutil.h"
#include "cacheutil.h"

using std::string;
using std::vector;

using namespace sid;

using sidutil::fixed_attribute_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_accessor_map_component;
using sidutil::no_relation_component;
using sidutil::blocking_component;
using sidutil::callback_pin;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::binary_output_pin;
using sidutil::output_pin;

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
  
  DEFN_METHOD (big_int_1)
  DEFN_METHOD (big_int_2)
  DEFN_METHOD (big_int_4)
  DEFN_METHOD (big_int_8)
  DEFN_METHOD (little_int_1)
  DEFN_METHOD (little_int_2)
  DEFN_METHOD (little_int_4)
  DEFN_METHOD (little_int_8)
#undef DEFN_METHOD
};

// FIFO cache replacement algorithm

class cache_replacement_fifo: public cache_replacement_algorithm
{
public:
  cache_line *expell (cache_set& set);

private:
  vector <int> fifo;
};

// Least recently used (LRU) replacement algorithm

class cache_replacement_lru: public cache_replacement_algorithm
{
public:
  cache_line *expell (cache_set& set);
  void update (cache_set& cset, cache_line& selected);

private:
  vector <unsigned> lru;
};

// Random replacement algorithm

class cache_replacement_random: public cache_replacement_algorithm
{
public:
  cache_line *expell (cache_set& set);
};

// Null replacement algorithm; used by direct mapped caches

class cache_replacement_null: public cache_replacement_algorithm
{
public:
  cache_line *expell (cache_set& set);
};


class cache_component: public virtual component,
		       protected virtual fixed_attribute_map_component,
		       protected fixed_bus_map_component,
		       protected virtual fixed_pin_map_component,
		       protected fixed_accessor_map_component,
		       protected no_relation_component
{
public:
  cache_component (unsigned asoctvty, unsigned cache_sz,
		   unsigned line_sz, cache_replacement_algorithm& replacer,
		   cache_line_factory &line_factory);

  virtual ~cache_component () throw();

#define DEFN_METHOD(DataType) \
  virtual bus::status write(host_int_4 addr, DataType data) { return this->write_any(addr, data); } \
  virtual bus::status read(host_int_4 addr, DataType& data) { return this->read_any(addr, data); }
DEFN_METHOD (big_int_1)
DEFN_METHOD (big_int_2)
DEFN_METHOD (big_int_4)
DEFN_METHOD (big_int_8)
DEFN_METHOD (little_int_1)
DEFN_METHOD (little_int_2)
DEFN_METHOD (little_int_4)
DEFN_METHOD (little_int_8)
#undef DEFN_METHOD

protected:
  template <typename DataType> bus::status 
  write_any (host_int_4 addr, DataType data);
  
  template <typename DataType> bus::status
  read_any (host_int_4 addr, DataType& data);

protected:
  cache acache;

  cache_bus upstream;
  bus* downstream;

  callback_pin<cache_component> report_pin;
  void emit_report (host_int_4 ignore);

  callback_pin<cache_component> flush_all_pin;
  virtual void flush_all_lines (host_int_4 ignore);

  callback_pin<cache_component> flush_pin;
  virtual void flush_line (host_int_4 addr);

  callback_pin<cache_component> flush_set_pin;
  virtual void flush_set (host_int_4 set);

  callback_pin<cache_component> flush_and_invalidate_set_pin;
  virtual void flush_and_invalidate_set (host_int_4 set);

  callback_pin<cache_component> invalidate_all_pin;
  virtual void invalidate_all_lines (host_int_4 ignore);

  callback_pin<cache_component> invalidate_pin;
  virtual void invalidate_line (host_int_4 addr);

  callback_pin<cache_component> flush_and_invalidate_pin;
  virtual void flush_and_invalidate_line (host_int_4 addr);

  callback_pin<cache_component> invalidate_set_pin;
  virtual void invalidate_set (host_int_4 set);

  callback_pin<cache_component> prefetch_pin;
  virtual void prefetch_line (host_int_4 addr);

  callback_pin<cache_component> write_hint_pin;
  virtual void write_hint (host_int_4 addr);

  callback_pin<cache_component> lock_pin;
  virtual void lock_line (host_int_4 addr);

  callback_pin<cache_component> unlock_pin;
  virtual void unlock_line (host_int_4 addr);

  // Completion status for the above operations
  output_pin operation_status_pin;
  void report_status (bus::status st)
  {
    host_int_4 v = (st.latency << 16) | st.code;
    operation_status_pin.drive (v);
  }

  string read_hit_rate ();
  string write_hit_rate ();
  string get_nothing () { return ""; }
  status set_nothing (const string& ignore) { return component::ok; }
  string associativity ();
  status dump (const string& ignore);
  string get_hash_mask ();
  status set_hash_mask (const string& ignore);
  string get_hash_shift ();
  status set_hash_shift (const string& ignore);
  string get_refill_latency ();
  status set_refill_latency (const string& ignore);

  unsigned line_offset (const cache_line& line, const host_int_4& addr); 

  bus::status read_line (cache_line& line);
  bus::status write_line (cache_line& line);

  template<typename DataType> bus::status read_downstream (host_int_4 address, DataType &data);
  template<typename DataType> bus::status write_downstream (host_int_4 address, DataType data);

  // Handle read/write errors. The default is not to handle them.
  virtual bool handle_read_error (bus::status s, host_int_4 &addr) { return false; }
  virtual bool handle_write_error (bus::status s, host_int_4 &addr) { return false; }

  virtual void lock_downstream () { }
  virtual void unlock_downstream () { }

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

  cache_line_factory &line_factory;
  unsigned line_size;
  unsigned cache_size;
  unsigned assoc;
  unsigned data_width;

  host_int_2 hit_latency;
  host_int_2 miss_latency;
  host_int_2 refill_latency;
  bool refill_latency_specified;
  bool total_latency_p;
};

template <typename DataType>
bus::status
cache_bus::write_any (host_int_4 addr, DataType data)
{
  return cache.write (addr, data);
}
  
template <typename DataType>
bus::status
cache_bus::read_any (host_int_4 addr, DataType& data)
{
  return cache.read (addr, data);
}

#define DEFN_METHOD(DataType) \
  inline bus::status cache_bus::write(host_int_4 addr, DataType data) throw () { return this->write_any(addr, data); } \
  inline bus::status cache_bus::read(host_int_4 addr, DataType& data) throw () { return this->read_any(addr, data); }
  
DEFN_METHOD (big_int_1)
DEFN_METHOD (big_int_2)
DEFN_METHOD (big_int_4)
DEFN_METHOD (big_int_8)
DEFN_METHOD (little_int_1)
DEFN_METHOD (little_int_2)
DEFN_METHOD (little_int_4)
DEFN_METHOD (little_int_8)
#undef DEFN_METHOD

// This cache component handles bus::busy from downstream by blocking on
// and waiting to retry.
//
class blocking_cache_component :
  public cache_component, public blocking_component
{
public:
  // For use when constructing directly
  blocking_cache_component (unsigned asoctvty, unsigned cache_sz,
			    unsigned line_sz,
			    cache_replacement_algorithm& replacer,
			    cache_line_factory &line_factory);
  // For use by constructor of derived class
  blocking_cache_component (void *child_self,
			    unsigned asoctvty, unsigned cache_sz,
			    unsigned line_sz,
			    cache_replacement_algorithm& replacer,
			    cache_line_factory &line_factory);

  virtual ~blocking_cache_component () throw() {}

#define DEFN_METHOD(DataType) \
  virtual bus::status write(host_int_4 addr, DataType data); \
  virtual bus::status read(host_int_4 addr, DataType& data);
DEFN_METHOD (big_int_1)
DEFN_METHOD (big_int_2)
DEFN_METHOD (big_int_4)
DEFN_METHOD (big_int_8)
DEFN_METHOD (little_int_1)
DEFN_METHOD (little_int_2)
DEFN_METHOD (little_int_4)
DEFN_METHOD (little_int_8)
#undef DEFN_METHOD

protected:
  // Virtual overrides
  virtual void flush_all_lines (host_int_4 ignore);
  virtual void flush_line (host_int_4 addr);
  virtual void flush_set (host_int_4 set);
  virtual void flush_and_invalidate_set (host_int_4 set);
  virtual void flush_and_invalidate_line (host_int_4 addr);
  virtual void prefetch_line (host_int_4 addr);

protected:
  // Handle read/write errors.
  virtual bool handle_read_error (bus::status s, host_int_4 &addr)
    { return handle_bus_error (s); }
  virtual bool handle_write_error (bus::status s, host_int_4 &addr)
    { return handle_bus_error (s); }

  // Common function handles both read and write errors
  bool handle_bus_error (bus::status s);

  // Performing transactions on the child thread
public:
  void perform_transaction () { (this->*transaction_func) (); }
protected:
  host_int_4 transaction_addr;
  bus::status transaction_status;
  void (blocking_cache_component::*transaction_func)();

#define DEFN_METHOD(DataType) \
  DataType transaction_data##DataType; \
  void setup_read_transaction (host_int_4 addr, const DataType &data) \
    { transaction_addr = addr; \
      transaction_func = & blocking_cache_component::perform_read_transaction##DataType; \
    } \
  void setup_write_transaction (host_int_4 addr, const DataType &data) \
    { transaction_addr = addr; \
      transaction_data##DataType = data; \
      transaction_func = & blocking_cache_component::perform_write_transaction##DataType; \
    } \
  void perform_read_transaction##DataType () \
    { transaction_status = cache_component::read (transaction_addr, transaction_data##DataType); } \
  void perform_write_transaction##DataType () \
    { transaction_status = cache_component::write (transaction_addr, transaction_data##DataType); } \
  void get_transaction_data (DataType &data) { data = transaction_data##DataType; }

DEFN_METHOD (big_int_1)
DEFN_METHOD (big_int_2)
DEFN_METHOD (big_int_4)
DEFN_METHOD (big_int_8)
DEFN_METHOD (little_int_1)
DEFN_METHOD (little_int_2)
DEFN_METHOD (little_int_4)
DEFN_METHOD (little_int_8)
#undef DEFN_METHOD

protected:
  // Setup methods for blockable transactions
  //
  void setup_flush_all_transaction ()
    { 
      transaction_func = & blocking_cache_component::perform_flush_all_transaction;
    }
  void setup_flush_line_transaction (host_int_4 addr)
    {
      transaction_addr = addr;
      transaction_func = & blocking_cache_component::perform_flush_line_transaction;
    }
  void setup_flush_set_transaction (host_int_4 index)
    {
      transaction_addr = index;
      transaction_func = & blocking_cache_component::perform_flush_set_transaction;
    }
  void setup_flush_and_invalidate_set_transaction (host_int_4 index)
    {
      transaction_addr = index;
      transaction_func = & blocking_cache_component::perform_flush_and_invalidate_set_transaction;
    }
  void setup_flush_and_invalidate_line_transaction (host_int_4 addr)
    {
      transaction_addr = addr;
      transaction_func = & blocking_cache_component::perform_flush_and_invalidate_line_transaction;
    }

protected:
  // Work methods for blockable transactions
  //
  void perform_flush_all_transaction ()
    { cache_component::flush_all_lines (transaction_addr); }
  void perform_flush_line_transaction ()
    { cache_component::flush_line (transaction_addr); }
  void perform_flush_set_transaction ()
    { cache_component::flush_set (transaction_addr); }
  void perform_flush_and_invalidate_set_transaction ()
    { cache_component::flush_and_invalidate_set (transaction_addr); }
  void perform_flush_and_invalidate_line_transaction ()
    { cache_component::flush_and_invalidate_line (transaction_addr); }

protected:
  binary_output_pin downstream_lock_pin;
  virtual void lock_downstream () { downstream_lock_pin.on (); }
  virtual void unlock_downstream () { downstream_lock_pin.off (); }
};

#endif // CACHE_H
