// gprof.cxx - A component for generating gprof profile data.  -*- C++ -*-

// Copyright (C) 1999-2002, 2005, 2006 Red Hat.
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
  using sid::pin;

  using sidutil::fixed_pin_map_component;
  using sidutil::fixed_attribute_map_component;
  using sidutil::no_bus_component;
  using sidutil::no_accessor_component;
  using sidutil::fixed_relation_map_component;
  using sidutil::configurable_component;
  using sidutil::input_pin;
  using sidutil::output_pin;
  using sidutil::callback_pin;
  using sidutil::make_attribute;
  using sidutil::parse_attribute;
  using sidutil::tokenize;
  using sidutil::std_error_string;
  using sidutil::endian;
  using sidutil::endian_unknown;
  using sidutil::endian_big;
  using sidutil::endian_little;

  using std::map;
  using std::vector;
  using std::string;
  using std::ofstream;
  using std::cerr;
  using std::endl;
  using std::pair;
  using std::make_pair;
  using std::ostream;
  using std::ios;
  using std::ofstream;


// ----------------------------------------------------------------------------

  class gprof_component: public virtual component,
			 protected virtual fixed_pin_map_component,
			 protected no_accessor_component,
			 protected virtual fixed_attribute_map_component,
			 protected virtual fixed_relation_map_component,
			 protected no_bus_component,
			 protected configurable_component
  {
    typedef map<host_int_8,host_int_4> hitcount_map_t;
    typedef map<pair<host_int_8,host_int_8>,host_int_4> cg_count_map_t;
    
    // statistics
    struct statistics
    {
      hitcount_map_t value_hitcount_map;
      cg_count_map_t cg_count_map;
      host_int_4 value_count;
      host_int_8 value_min, value_max;
      host_int_8 limit_min, limit_max;
      host_int_4 bucket_size;
      host_int_4 pc_size;
      string output_file;
      statistics () :
	value_count (0),
	value_min (~(host_int_8)0),
	value_max (0),
	limit_min (0),
	limit_max (~(host_int_8)0),
	bucket_size (1), // != 0
	pc_size (4), // default
	output_file ("")
        { }
      const statistics &operator= (const statistics &other)
        {
	  this->value_count = other.value_count;
	  this->value_min   = other.value_min;
	  this->value_max   = other.value_max;
	  this->limit_min   = other.limit_min;
	  this->limit_max   = other.limit_max;
	  this->bucket_size = other.bucket_size;
	  this->pc_size     = other.pc_size;
	  this->output_file = other.output_file;
	}
    };

    vector<statistics> stats;
    unsigned current_stats;

    component* target_component;

    endian output_file_format;

    callback_pin<gprof_component> accumulate_pin;

    input_pin pc_hi_pin;
    input_pin pc_pin;
    input_pin cg_caller_hi_pin;
    input_pin cg_caller_pin;
    input_pin cg_callee_hi_pin;
    callback_pin<gprof_component> cg_callee_pin;

    callback_pin<gprof_component> reset_pin;
    callback_pin<gprof_component> store_pin;

    component::status set_nothing (const string& str)
      {
	return component::bad_value;
      }

    string value_min_get()
      {
	return make_attribute (this->stats[current_stats].value_min);
      }

    string value_max_get()
      {
	return make_attribute (this->stats[current_stats].value_max);
      }

    string value_count_get()
      {
	return make_attribute (this->stats[current_stats].value_count);
      }

    string limit_min_get()
      {
	return make_attribute (this->stats[current_stats].limit_min);
      }

    component::status limit_min_set(const string& str)
      {
	host_int_8 new_limit_min;
	component::status s = parse_attribute (str, new_limit_min);
	// Reject malformed input
	if (s == component::ok)
	  this->stats[current_stats].limit_min = new_limit_min;
	return s;
      }

    string limit_max_get()
      {
	return make_attribute (this->stats[current_stats].limit_max);
      }

    component::status limit_max_set(const string& str)
      {
	host_int_8 new_limit_max;
	component::status s = parse_attribute (str, new_limit_max);
	// Reject malformed input
	if (s == component::ok)
	  this->stats[current_stats].limit_max = new_limit_max;
	return s;
      }

    string bucket_size_get()
      {
	return make_attribute (this->stats[current_stats].bucket_size);
      }

    component::status bucket_size_set(const string& str)
      {
	host_int_4 new_bucket_size;
	component::status s = parse_attribute (str, new_bucket_size);

	// Reject malformed input
	if (s != component::ok) return s;

	// Reject change if we already have samples 
	statistics &st = this->stats[current_stats];
	if ((st.value_count != 0) &&
	    (st.bucket_size != new_bucket_size))
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

	st.bucket_size = new_bucket_size;
	return component::ok;
      }


    string pc_size_get()
      {
	return make_attribute (this->stats[current_stats].pc_size);
      }

    component::status pc_size_set(const string& str)
      {
	host_int_4 new_pc_size;
	component::status s = parse_attribute (str, new_pc_size);

	// Reject malformed input
	if (s != component::ok) return s;

	// Reject invalid sizes
	if (new_pc_size != 4 && new_pc_size != 8)
	  {
	    cerr << "sw-profile-gprof: invalid pc size." << endl;
	    return component::bad_value;
	  }

	this->stats[current_stats].pc_size = new_pc_size;
	return component::ok;
      }


    string output_file_get()
      {
	return this->stats[current_stats].output_file;
      }

    component::status output_file_set(const string& str)
      {
	this->stats[current_stats].output_file = str;
	return component::ok;
      }

    void accumulate (host_int_4 ticks)
      {
	if (! this->target_component) return;

	host_int_8 value = (((host_int_8)this->pc_hi_pin.sense ()) << 32) | (this->pc_pin.sense () & 0xffffffff);

	// std::cout << "sampled " << ticks << " ticks at 0x" << std::hex << value << std::dec << " for " << stats[current_stats].output_file << endl;
	// Reject out-of-bounds samples
	statistics &st = this->stats[current_stats];
	if (value < st.limit_min || value > st.limit_max) return;

	st.value_count ++;

	assert (st.bucket_size != 0);
	host_int_8 quantized = (value / st.bucket_size) * st.bucket_size;

	if (quantized < st.value_min) st.value_min = quantized;
	if (quantized > st.value_max) st.value_max = quantized;
	st.value_hitcount_map [quantized] += ticks;
      }

    void accumulate_call (host_int_4 selfpc_low)
      {
	host_int_8 selfpc = (((host_int_8)this->cg_callee_hi_pin.sense ()) << 32) | (selfpc_low & 0xffffffff);
	host_int_8 callerpc = (((host_int_8)this->cg_caller_hi_pin.sense ()) << 32) | (this->cg_caller_pin.sense () & 0xffffffff);

	// Reject out-of-bounds samples
	statistics &st = this->stats[current_stats];
	if (selfpc < st.limit_min || selfpc > st.limit_max) return;
	if (callerpc < st.limit_min || callerpc > st.limit_max) return;

	st.value_count ++;

	assert (st.bucket_size != 0);
	host_int_8 c_quantized = (callerpc / st.bucket_size) * st.bucket_size;
	host_int_8 s_quantized = (selfpc / st.bucket_size) * st.bucket_size;

	if (c_quantized < st.value_min) st.value_min = c_quantized;
	if (s_quantized < st.value_min) st.value_min = s_quantized;
	if (c_quantized > st.value_max) st.value_max = c_quantized;
	if (s_quantized > st.value_max) st.value_max = s_quantized;

	st.cg_count_map [make_pair(c_quantized,s_quantized)] ++;
      }


    void reset (host_int_4)
      {
	statistics new_stats;
	if (! stats.empty ())
	  {
	    new_stats.bucket_size = stats[0].bucket_size;
	    new_stats.output_file = stats[0].output_file;
	  }
	stats.clear ();
	stats.push_back (new_stats);
	current_stats = 0;
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

	for (vector<statistics>::iterator it = stats.begin ();
	     it != stats.end ();
	     ++it)
	  store_stats (*it);
      }

    void store_stats (statistics &stats)
      {
	if (stats.output_file.empty ())
	  stats.output_file = "gmon.out";

	ofstream of (stats.output_file.c_str (),
                     ios::out | ios::trunc | ios::binary);
	if (! of.good())
	  {
	    cerr << "sw-profile-gprof: Error opening "
		 << stats.output_file << ":" << std_error_string();
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

	if (! stats.value_hitcount_map.empty())
	  {
	    // We may have to loop and dump out several adjacent histogram
	    // tables, because histogram bucket count overflow.  The
	    // bucket counts are limited to 16 bits, but a 32-bit counter
	    // in gprof may be accumulated my multiple overlapping
	    // histogram tables.  We copy the histogram table here, since
	    // its counters will be decremented by up to 2**16-1 per
	    // iteration.
	    hitcount_map_t value_hitcount_map_copy = stats.value_hitcount_map;
	    while (true)
	      {
		// write a new histogram record
		// GMON_Record_Tag
		put_bytes (of, host_int_1(0), 1);      // GMON_TAG_TIME_HIST
		// gmon_hist_hdr
		if (stats.pc_size == 4) // 4 byte pc
		  {
		    put_bytes (of, (host_int_4)stats.value_min, stats.pc_size);    // gmon_hist_hdr.low_pc
		    host_int_4 uprounded_value_max = stats.value_max + stats.bucket_size;
		    put_bytes (of, uprounded_value_max, stats.pc_size); // gmon_hist_hdr.high_pc
		  }
		else // 8 byte pc
		  {
		    put_bytes (of, stats.value_min, stats.pc_size);    // gmon_hist_hdr.low_pc
		    host_int_8 uprounded_value_max = stats.value_max + stats.bucket_size;
		    put_bytes (of, uprounded_value_max, stats.pc_size); // gmon_hist_hdr.high_pc
		  }
		assert (stats.bucket_size != 0);
		host_int_4 num_buckets = 1 + (stats.value_max - stats.value_min) / stats.bucket_size;
		put_bytes (of, num_buckets, 4);        // gmon_hist_hdr.hist_size
		put_bytes (of, host_int_4(1), 4);      // gmon_hist_hdr.prof_rate
		put_bytes (of, "tick", 15);            // gmon_hist_hdr.dimen
		put_bytes (of, "t", 1);                // gmon_hist_hdr.dimen_abbrev
		
		// Dump out histogram counts
		bool overflow = false;
		for (host_int_8 bucket = stats.value_min;
		     bucket <= stats.value_max;
		     bucket += stats.bucket_size)
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
			b->second = 0; // in case we iterate due to overflow
		      }
		  }
		
		if (!overflow)
		  break;
	      }
	  } // (emitting hash table?)

	// Now spit out the call graph stastics.
	cg_count_map_t::const_iterator ci = stats.cg_count_map.begin();
	while (ci != stats.cg_count_map.end())
	  {
	    // write a new histogram record
	    // GMON_Record_Tag
	    put_bytes (of, host_int_1(1), 1);      // GMON_TAG_CG_ARC

	    // gmon_hist_hdr
	    if (stats.pc_size == 4) // 4 byte pc
	      {
		put_bytes (of, (host_int_4)(ci->first.first), 4);    // cg caller
		put_bytes (of, (host_int_4)(ci->first.second), 4);    // cg self
	      }
	    else // 8 byte pc
	      {
		put_bytes (of, ci->first.first, 8);    // cg caller
		put_bytes (of, ci->first.second, 8);    // cg self
	      }
	    put_bytes (of, ci->second, 4);    // cg count
	    
	    ci ++;
	  }

	of.close ();
      }

    void configure (const string &config)
      {
	// Call up to the base classes first
	configurable_component::configure (config);

	// Now handle relevent configuration for us.
	if (config.size () < 6)
	  return;
	if (config.substr (0, 6) == "gprof=")
	  {
	    // If a filename has been specified, then see if we need to switch files.
	    if (config.size () > 6)
	      {
		vector<string> parts = tokenize (config.substr (6), ",");

		// Special case: Default stats have not yet been assigned an
		// output file and no data has been collected yet. Simply
		// assign this file name.
		if (current_stats == 0 && stats[0].value_count == 0
		    && stats[0].output_file.empty ())
		  stats[0].output_file = parts[0];
		else
		  {
		    unsigned size = stats.size ();
		    unsigned i;
		    for (i = 0; i < size; ++i)
		      if (stats[i].output_file == parts[0])
			break;
		    // This is a new output file, so create new stats for it.
		    if (i >= size)
		      {
			statistics new_stats;
			new_stats.bucket_size = stats[0].bucket_size;
			new_stats.output_file = parts[0];
			stats.push_back (new_stats);
		      }
		    current_stats = i;
		  }
	      }
	    return;
	  }
      }

  public:
    gprof_component ():
      target_component (0),
      output_file_format (endian_unknown),
      accumulate_pin (this, & gprof_component::accumulate),
      cg_callee_pin (this, & gprof_component::accumulate_call),
      reset_pin (this, & gprof_component::reset),
      store_pin (this, & gprof_component::store),
      current_stats (0)
      {
	// Reset before adding attributes etc.
	reset (1);

	add_pin ("sample", & this->accumulate_pin);
	add_attribute ("sample", & this->accumulate_pin, "pin");
	add_pin ("pc", & this->pc_pin);
	add_attribute ("pc", & this->pc_pin, "pin");
	add_pin ("pc-hi", & this->pc_hi_pin);
	add_attribute ("pc-hi", & this->pc_hi_pin, "pin");
	add_pin ("cg-caller", & this->cg_caller_pin);
	add_attribute ("cg-caller", & this->cg_caller_pin, "pin");
	add_pin ("cg-caller-hi", & this->cg_caller_hi_pin);
	add_attribute ("cg-caller-hi", & this->cg_caller_hi_pin, "pin");
	add_pin ("cg-callee", & this->cg_callee_pin);
	add_attribute ("cg-callee", & this->cg_callee_pin, "pin");
	add_pin ("cg-callee-hi", & this->cg_callee_hi_pin);
	add_attribute ("cg-callee-hi", & this->cg_callee_hi_pin, "pin");
	add_pin ("reset", & this->reset_pin);
	add_attribute ("reset", & this->reset_pin, "pin");
	add_pin ("store", & this->store_pin);
	add_attribute ("store", & this->store_pin, "pin");
	add_attribute_virtual ("pc-size", this,
			       & gprof_component::pc_size_get,
			       & gprof_component::pc_size_set,
			       "setting");
	add_attribute_virtual ("bucket-size", this,
			       & gprof_component::bucket_size_get,
			       & gprof_component::bucket_size_set,
			       "setting");
	add_attribute_virtual ("value-min", this,
			       & gprof_component::value_min_get,
			       & gprof_component::set_nothing, // ro
			       "setting");
	add_attribute_virtual ("value-max", this,
			       & gprof_component::value_max_get,
			       & gprof_component::set_nothing, // ro
			       "setting");
	add_attribute_virtual ("value-count", this,
			       & gprof_component::value_count_get,
			       & gprof_component::set_nothing, // ro
			       "setting");
	add_attribute_virtual ("limit-min", this,
			       & gprof_component::limit_min_get,
			       & gprof_component::limit_min_set,
			       "setting");
	add_attribute_virtual ("limit-max", this,
			       & gprof_component::limit_max_get,
			       & gprof_component::limit_max_set,
			       "setting");
	add_attribute_virtual ("output-file", this,
			       & gprof_component::output_file_get,
			       & gprof_component::output_file_set,
			       "setting");
	add_attribute ("output-file-endianness", & this->output_file_format, "setting");
	add_uni_relation ("target-component", & this->target_component);

	pc_hi_pin.driven (0);
	cg_caller_hi_pin.driven (0);
	cg_callee_hi_pin.driven (0);
      }
    ~gprof_component () throw () { }
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
DLLEXPORT extern const sid::component_library prof_component_library;

const sid::component_library prof_component_library =
{
  sid::COMPONENT_LIBRARY_MAGIC,
  & profiling_components::list_types, 
  & profiling_components::create,
  & profiling_components::do_delete
};

