// gprof.cxx - A component for generating gprof profile data.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidpinattrutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>
#include <sidcpuutil.h>

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif


namespace profiling_components
{
  using sid::host_int_8;
  using sid::host_int_4;
  using sid::host_int_2;
  using sid::host_int_1;
  using sid::big_int_8;
  using sid::big_int_4;
  using sid::big_int_2;
  using sid::big_int_1;
  using sid::little_int_8;
  using sid::little_int_4;
  using sid::little_int_2;
  using sid::little_int_1;
  using sid::component;
  using sid::bus;

  using sidutil::fixed_pin_map_component;
  using sidutil::fixed_attribute_map_component;
  using sidutil::no_bus_component;
  using sidutil::no_accessor_component;
  using sidutil::fixed_relation_map_component;
  using sidutil::callback_pin;
  using sidutil::make_attribute;
  using sidutil::parse_attribute;
  using sidutil::std_error_string;
  using sidutil::endian;
  using sidutil::endian_unknown;
  using sidutil::endian_big;
  using sidutil::endian_little;

  using std::map;
  using std::hash_map;
  using std::vector;
  using std::string;
  using std::ofstream;
  using std::cerr;
  using std::endl;
  using std::ostream;

// ----------------------------------------------------------------------------

  class gprof_component: public virtual component,
			 protected fixed_pin_map_component,
			 protected no_accessor_component,
			 protected fixed_attribute_map_component,
			 protected fixed_relation_map_component,
			 protected no_bus_component
  {
#ifdef HAVE_HASHING
    typedef hash_map<host_int_4,host_int_4> hitcount_map_t;
#else
    typedef map<host_int_4,host_int_4> hitcount_map_t;
#endif
    
    // statistics
    hitcount_map_t value_hitcount_map;
    host_int_4 value_count;
    host_int_4 value_min, value_max;
    host_int_4 limit_min, limit_max;
    host_int_4 bucket_size;

    string target_attribute;
    component* target_component;

    string output_file;
    endian output_file_format;

    callback_pin<gprof_component> accumulate_pin;
    callback_pin<gprof_component> reset_pin;
    callback_pin<gprof_component> store_pin;


    string bucket_size_get()
      {
	return make_attribute (this->bucket_size);
      }

    component::status bucket_size_set(const string& str)
      {
	host_int_4 new_bucket_size;
	component::status s = parse_attribute (str, new_bucket_size);

	// Reject malformed input
	if (s != component::ok) return s;

	// Reject change if we already have samples 
	if ((this->value_count != 0) &&
	    (this->bucket_size != new_bucket_size))
	  {
	    cerr << "sw-profile-gprof: invalid time to change bucket size" << endl;
	    return component::bad_value;
	  }

	// Reject invalid size
	if (new_bucket_size == 0)
	  {
	    cerr << "sw-profile-gprof: invalid null bucket size." << endl;
	    return component::bad_value;
	  }

	this->bucket_size = new_bucket_size;
	return component::ok;
      }


    void accumulate (host_int_4)
      {
	if (! this->target_component) return;

	string value_str = this->target_component->attribute_value (this->target_attribute);
	host_int_4 value;
	component::status s = parse_attribute (value_str, value);
	if (s != component::ok) return;

	// Reject out-of-bounds samples
	if (value < this->limit_min || value > this->limit_max) return;

	value_count ++;

	assert (this->bucket_size != 0);
	host_int_4 quantized = (value / this->bucket_size) * this->bucket_size;

	if (quantized < this->value_min) this->value_min = quantized;
	if (quantized > this->value_max) this->value_max = quantized;
	this->value_hitcount_map [quantized] ++;
      }

    void reset (host_int_4)
      {
	this->value_hitcount_map.clear ();
	this->value_min = ~0;
	this->value_max = 0;
	value_count = 0;
      }


    // Write given host_int_X in target byte order
    template <typename IntType>
    void put_bytes (ostream& o, IntType v, unsigned count)
      {

	switch (this->output_file_format)
	  {
	  case endian_little:
	    {
	      sid::any_int<IntType, false> lv = v;
	      for (unsigned i=0; i<count; i++)
		o.put (lv.read_byte (i));
	    }
	    break;

	  case endian_big:
	    {
	      sid::any_int<IntType, true> bv = v;
	      for (unsigned i=0; i<count; i++)
		o.put (bv.read_byte (i));
	    }
	    break;

	  default:
	    assert (0);
	  }
      }

    void put_bytes (ostream& o, const char* v, unsigned count)
      {
	for (unsigned i=0; i<count; i++)
	  {
	    o.put (*v);
	    if (*v) v++;  // advance unless we've hit NULL terminator
	  }
      }


    void store (host_int_4)
      {
	// Fetch endianness from target CPU
	if (this->output_file_format == endian_unknown)
	  {
	    string value = this->target_component->attribute_value ("endian");
	    component::status s = parse_attribute (value, this->output_file_format);
	    if (s != component::ok)
	      this->output_file_format = endian_unknown;
	  }
	if (this->output_file_format == endian_unknown)
	  {
	    cerr << "sw-profile-gprof: Unknown endianness for output file." << endl;
	    return;
	  }

	ofstream of (this->output_file.c_str ());
	if (! of.good())
	  {
	    cerr << "sw-profile-gprof: Error opening "
		 << this->output_file << ":" << std_error_string();
	    return;
	  }

	// write gmon header
	put_bytes (of, "gmon", 4);             // gmon_hdr.cookie
	// version number (1) in target-endian
	put_bytes (of, host_int_4(1), 4);      // gmon_hdr.version = GMON_VERSION
	// 12 bytes of padding
	put_bytes (of, host_int_4(0), 4);      // gmon_hdr.spare
	put_bytes (of, host_int_4(0), 4);      // gmon_hdr.spare
	put_bytes (of, host_int_4(0), 4);      // gmon_hdr.spare

	// We may have to loop and dump out several adjacent histogram
	// tables, because histogram bucket count overflow.  The
	// bucket counts are limited to 16 bits, but a 32-bit counter
	// in gprof may be accumulated my multiple overlapping
	// histogram tables.  We copy the histogram table here, since
	// its counters will be decremented by up to 2**16-1 per
	// iteration.
	hitcount_map_t value_hitcount_map_copy = this->value_hitcount_map;
	while (true)
	  {
	    // write a new histogram record
	    // GMON_Record_Tag
	    put_bytes (of, host_int_1(0), 1);      // GMON_TAG_TIME_HIST
	    // gmon_hist_hdr
	    put_bytes (of, this->value_min, 4);    // gmon_hist_hdr.low_pc
	    put_bytes (of, this->value_max, 4);    // gmon_hist_hdr.high_pc
	    assert (this->bucket_size != 0);
	    host_int_4 num_buckets = 1 + (this->value_max - this->value_min) / this->bucket_size;
	    put_bytes (of, num_buckets, 4);        // gmon_hist_hdr.hist_size
	    // XXX: actual prof_rate not available here ...
	    put_bytes (of, host_int_4(1), 4);      // gmon_hist_hdr.prof_rate
	    put_bytes (of, "tick", 15);            // gmon_hist_hdr.dimen
	    put_bytes (of, "t", 1);                // gmon_hist_hdr.dimen_abbrev

	    // Dump out histogram counts
	    bool overflow = false;
	    for (host_int_4 bucket = this->value_min;
		 bucket <= this->value_max;
		 bucket += this->bucket_size)
	      {
		const host_int_4 max_count = 65535;
		host_int_4 count = 0;

		// Check if this bucket exists by find() instead of a
		// blind []-lookup, because the latter would allocate
		// fresh & useless 0-count buckets for all non-touched
		// values.
		hitcount_map_t::iterator b = value_hitcount_map_copy.find (bucket);
		if (b != value_hitcount_map_copy.end())
		  count = b->second;

		if (count > max_count) // overflow!
		  {
		    put_bytes (of, host_int_2(max_count), 2);
		    b->second -= max_count;
		    overflow = true;
		  }
		else
		  {
		    put_bytes (of, host_int_2(count), 2);
		  }
	      }

	    if (!overflow)
	      break;
	  }

	of.close ();
      }


  public:
    gprof_component ():
      value_count (0),
      value_min (~0),
      value_max (0),
      limit_min (0),
      limit_max (~0),
      bucket_size (1), // != 0
      target_attribute ("pc"),
      target_component (0),
      output_file ("gmon.out"),
      output_file_format (endian_unknown),
      accumulate_pin (this, & gprof_component::accumulate),
      reset_pin (this, & gprof_component::reset),
      store_pin (this, & gprof_component::store)
      {
	add_pin ("sample", & this->accumulate_pin);
	add_attribute ("sample", & this->accumulate_pin, "pin");
	add_pin ("reset", & this->reset_pin);
	add_attribute ("reset", & this->reset_pin, "pin");
	add_pin ("store", & this->store_pin);
	add_attribute ("store", & this->store_pin, "pin");
	add_attribute_virtual ("bucket-size", this,
			       & gprof_component::bucket_size_get,
			       & gprof_component::bucket_size_set,
			       "setting");
	add_attribute_ro ("value-min", & this->value_min, "register");
	add_attribute_ro ("value-max", & this->value_max, "register");
	add_attribute_ro ("value-count", & this->value_count, "register");
	add_attribute ("limit-min", & this->limit_min, "setting");
	add_attribute ("limit-max", & this->limit_max, "setting");
	add_attribute ("value-attribute", & this->target_attribute, "setting");
	add_attribute ("output-file", & this->output_file, "setting");
	add_attribute ("output-file-endianness", & this->output_file_format, "setting");
	add_uni_relation ("target-component", & this->target_component);
      }
  };



// ----------------------------------------------------------------------------

  static
  vector<string>
  list_types()
{
  vector<string> types;
  types.push_back("sw-profile-gprof");
  return types;
}
  
  
  static
  component*
  create(const string& typeName)
{
  if (typeName == "sw-profile-gprof")
    return new gprof_component ();

  return 0;
}


  static
  void
  do_delete(component* c)
{
  delete dynamic_cast<gprof_component*>(c);
}

  
} // end namespace



// static object in root namespace
extern const sid::component_library prof_component_library;

const sid::component_library prof_component_library DLLEXPORT = 
{
  sid::COMPONENT_LIBRARY_MAGIC,
  & profiling_components::list_types, 
  & profiling_components::create,
  & profiling_components::do_delete
};

