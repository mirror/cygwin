// compMapper.cxx - a bus mapper component.  -*- C++ -*-

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

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include <cstdlib>

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::cerr;
using std::endl;
using std::max;
using std::min;

using sid::component;
using sid::bus;
using sid::host_int_2;
using sid::host_int_4;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::little_int_8;
using sid::big_int_1;
using sid::big_int_2;
using sid::big_int_4;
using sid::big_int_8;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_attribute_map_component;
using sidutil::no_relation_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::make_numeric_attribute;
using sidutil::parse_attribute;
using sidutil::tokenize;
using sidutil::attribute_coder_virtual_parameterized;


// ----------------------------------------------------------------------------


struct mapping_record
{
  host_int_4 low, high;         // inclusive address range
  host_int_4 hit_count;         // number of accesses via this record
  bus* accessor;                // target bus

  bool use_strideoffset_p;      // following fields valid?
  host_int_2 stride;	        // stride
  host_int_2 stride_shift;	// log2(stride)
  host_int_2 stride_mask;	// stride - 1
  host_int_2 offset;	        // offset
  host_int_2 width;	        // device access width
  host_int_2 width_shift;       // log2(width)

  string spec;                  // user-given specification string
};


bool 
overlaps_p (const mapping_record& a, const mapping_record& b)
{
  // I always rederive this little formula from first principles. 
  host_int_4 max_first = max(a.low, b.low);
  host_int_4 min_last = min(a.high, b.high);
  return (max_first <= min_last);
}


class mr_cmp: public std::binary_function<mapping_record, mapping_record, bool>
{
public:
  bool operator () (const mapping_record& a, const mapping_record& b) const
    {
      return (a.low < b.low); 
    }
  
  bool operator () (const mapping_record& a, host_int_4 addr) const
    {
      return (a.high < addr); 
    }
  
  bool operator () (host_int_4 addr, const mapping_record& b) const
    {
      return (addr < b.low);
    }
};



// ------------------------------------------------------------------------


class generic_mapper;
class generic_mapper_bus: public bus
{
public:
  generic_mapper_bus (generic_mapper* target): target (target)
    {
      this->tlb = 0;
    }


  // The address lookup function - body below
  inline mapping_record* locate (host_int_4 address) const;


  // Specialized write() for stride/offset slaves
  template <class DataMaster, class DataSlave>
  inline bus::status
  write_strideoffset_any (host_int_4 address, const mapping_record* r,
			  DataMaster data, DataSlave) throw ()
    {
      const host_int_4 master_offset = address & r->stride_mask;
      const host_int_4 master_size = sizeof (typename DataMaster::value_type);
      const host_int_4 slave_size = sizeof (typename DataSlave::value_type);
      const host_int_4 slave_offset = r->offset;

      // Signal error if master access does not include all of slave bus
      if (UNLIKELY((master_offset > slave_offset) || 
	 	   (master_offset+master_size < slave_offset+slave_size)))
	return bus::misaligned;

      // Signal error if master access spans stride boundary.
      if (UNLIKELY(master_size+master_offset > r->stride))
	return bus::misaligned;

      // Copy data bytes for slave
      DataSlave ds;
      for (unsigned i=0; i<slave_size; i++)
	ds.write_byte (i, data.read_byte (i + slave_offset - master_offset));

      host_int_4 mapped_address = (address - r->low) >> (r->stride_shift - r->width_shift);
      return r->accessor->write (mapped_address, ds);
    }


  // Specialized read() for stride/offset slaves
  template <class DataMaster, class DataSlave>
  inline bus::status
  read_strideoffset_any (host_int_4 address, const mapping_record* r,
			  DataMaster& data, DataSlave) throw ()
    {
      const host_int_4 master_offset = address & r->stride_mask;
      const host_int_4 master_size = sizeof (typename DataMaster::value_type);
      const host_int_4 slave_size = sizeof (typename DataSlave::value_type);
      const host_int_4 slave_offset = r->offset;

      // Signal error if master access does not include all of slave bus
      if (UNLIKELY((master_offset > slave_offset) || 
		   (master_offset+master_size < slave_offset+slave_size)))
	return bus::misaligned;

      // Signal error if master access spans stride boundary.
      if (UNLIKELY(master_size+master_offset > r->stride))
	return bus::misaligned;

      DataSlave ds;
      host_int_4 mapped_address = (address - r->low) >> (r->stride_shift - r->width_shift);
      bus::status s = r->accessor->read (mapped_address, ds);

      // Copy data bytes for master
      for (unsigned i=0; i<slave_size; i++)
	data.write_byte (i, ds.read_byte (i + slave_offset - master_offset));

      return s;
    }



  // Generic write()
  template <class Data>
  inline bus::status
  write_any (host_int_4 address, Data data) throw ()
    {
      const mapping_record* r = this->locate (address);
      if (LIKELY (r))
	{
	  // bypass stride/offset calculations?
	  if (LIKELY(! r->use_strideoffset_p))
	    {
	      host_int_4 mapped_address = address - r->low;
	      return r->accessor->write (mapped_address, data);
	    }

	  // Order these alternatives by guess of frequency of use
	  if (r->width == 1)
	    {
	      typename Data::size_1_type s1data;
	      return write_strideoffset_any (address, r, data, s1data);
	    }
	  else if (r->width == 4)
	    {
	      typename Data::size_4_type s4data;
	      return write_strideoffset_any (address, r, data, s4data);
	    }
	  else if (r->width == 2)
	    {
	      typename Data::size_2_type s2data;
	      return write_strideoffset_any (address, r, data, s2data);
	    }
	  else if (r->width == 8)
	    {
	      typename Data::size_8_type s8data;
	      return write_strideoffset_any (address, r, data, s8data);
	    }
	  else
	    assert (0);
	}
      else
	return bus::unmapped;
    }


  // Generic read()
  template <class Data>
  inline bus::status
  read_any (host_int_4 address, Data& data) throw ()
    {
      const mapping_record* r = this->locate (address);
      if (LIKELY (r))
	{
	  // bypass stride/offset calculations?
	  if (LIKELY(! r->use_strideoffset_p))
	    {
	      host_int_4 mapped_address = address - r->low;
	      return r->accessor->read (mapped_address, data);
	    }

	  // Order these alternatives by guess of frequency of use
	  if (r->width == 1)
	    {
	      typename Data::size_1_type s1data;
	      return read_strideoffset_any (address, r, data, s1data);
	    }
	  else if (r->width == 4)
	    {
	      typename Data::size_4_type s4data;
	      return read_strideoffset_any (address, r, data, s4data);
	    }
	  else if (r->width == 2)
	    {
	      typename Data::size_2_type s2data;
	      return read_strideoffset_any (address, r, data, s2data);
	    }
	  else if (r->width == 8)
	    {
	      typename Data::size_8_type s8data;
	      return read_strideoffset_any (address, r, data, s8data);
	    }
	  else
	    assert (0);
	}
      else
	return bus::unmapped;
    }


  // some macros to make manufacturing of the cartesian-product calls simpler
#define SID_GB_WRITE(Type) \
  bus::status write (host_int_4 address, Type data) throw () { return write_any (address,data); }
#define SID_GB_READ(Type) \
  bus::status read (host_int_4 address, Type& data) throw () { return read_any (address,data); }
  
  // -------------------------------------------------------------------

    SID_GB_WRITE(little_int_1);
    SID_GB_WRITE(little_int_2);
    SID_GB_WRITE(little_int_4);
    SID_GB_WRITE(little_int_8);
    SID_GB_READ(little_int_1);
    SID_GB_READ(little_int_2);
    SID_GB_READ(little_int_4);
    SID_GB_READ(little_int_8);

    SID_GB_WRITE(big_int_1);
    SID_GB_WRITE(big_int_2);
    SID_GB_WRITE(big_int_4);
    SID_GB_WRITE(big_int_8);
    SID_GB_READ(big_int_1);
    SID_GB_READ(big_int_2);
    SID_GB_READ(big_int_4);
    SID_GB_READ(big_int_8);
      
#undef SID_GB_WRITE
#undef SID_GB_READ

  ~generic_mapper_bus ();

private:
  generic_mapper* target;
  mutable struct mapping_record* tlb;
};

generic_mapper_bus::~generic_mapper_bus () {
}



// ----------------------------------------------------------------------------

class generic_mapper: public virtual component,
		      protected fixed_attribute_map_component,
		      protected no_relation_component,
		      protected fixed_pin_map_component,
		      // NB: implements accessor sub-api directly
		      protected fixed_bus_map_component
{
public:
  generic_mapper ();
  ~generic_mapper () {}

  std::vector<string> accessor_names () throw();
  component::status connect_accessor (const string& name, bus* bus) throw();
  component::status disconnect_accessor (const string& name, bus* bus) throw();
  bus* connected_bus (const string& name) throw();

  mapping_record* make_name_mapping (const string& str, bus* bus) const;

protected:
  friend class generic_mapper_bus;

  vector<mapping_record> accessors;
  generic_mapper_bus my_bus;

  // stats
  host_int_4 access_count;
  host_int_4 cache_hit_count;

private:
  string save_state ();
  component::status restore_state (const string& state);

  string get_hits (std::string entry);
  component::status set_hits (std::string entry, const std::string& value);
};


generic_mapper::generic_mapper ()
  :my_bus (this)
{
  add_bus ("access-port", &this->my_bus);
  add_attribute_virtual ("state-snapshot", this,
			 & generic_mapper::save_state,
			 & generic_mapper::restore_state);

  this->access_count = 0;
  add_attribute ("access-count", & this->access_count, "register");
  this->cache_hit_count = 0;
  add_attribute ("cache-hit-count", & this->cache_hit_count, "register");
}


vector<string>
generic_mapper::accessor_names () throw()
{
  vector<string> names;  
  for (vector<mapping_record>::const_iterator it = this->accessors.begin();
       it != this->accessors.end();
       it++)
     {
       names.push_back (it->spec);
     }  
  return names;
}

component::status
generic_mapper::connect_accessor (const string& name, bus* bus) throw()
  {
    // new entry
    mapping_record *r = make_name_mapping (name, bus);
    if (r == NULL)
      {
	return component::bad_value;
      }

    // Reject overlaps
    for (unsigned i=0; i<this->accessors.size(); i++)
      if (overlaps_p (this->accessors[i], *r))
	{
	  cerr << "mapper error: overlap between " << r->spec
	       << " and " << this->accessors[i].spec
	       << endl;
	  delete r;
	  return component::bad_value;
	}

    this->accessors.push_back (*r);
    sort(this->accessors.begin(),this->accessors.end(),mr_cmp());

    add_attribute_virtual_parameterized (name + "-hits", 
					 name,
					 this,
					 & generic_mapper::get_hits,
					 & generic_mapper::set_hits,
					 "register");

    delete r;
    return component::ok;
  }


component::status
generic_mapper::disconnect_accessor (const string& name, bus* bus) throw()
  {
    for (vector<mapping_record>::iterator it = this->accessors.begin();
         it != this->accessors.end();
         it++)
       {
         // found existing entry
         if (it->spec == name)
	   {
	     remove_attribute (name + "-hits");
	     this->accessors.erase (it);
	     sort(this->accessors.begin(),this->accessors.end(),mr_cmp());
	     return component::ok;
	   }
       }
    return component::not_found;
  }


bus* 
generic_mapper::connected_bus (const string& name) throw() 
  {
    for (vector<mapping_record>::const_iterator it = this->accessors.begin();
         it != this->accessors.end ();
         it++)
       {
	 // found existing entry
         if (it->spec == name)
	   return (*it).accessor;
       }
     return 0;
  }



// Parse a mapping specification and produce a mapping_record from it.
// Return 0 on parse or validity-checking error.
//
// Accept the following forms:
// [LOW-HIGH]
// [LOW-HIGH,STRIDE,WIDTH]
//
// Each number may be specified in any format that parse_attribute()
// understands.
//
mapping_record* 
generic_mapper::make_name_mapping (const string& str, bus* acc) const 
{
  // Fill in this struct in stack; may return copy if all goes well
  mapping_record record;

  vector<string> fields = tokenize (str, "[-,]");

  // Must have either four or six tokens (including empties
  // before/after "[" and "]")
  if (fields.size() != 4 && fields.size() != 6)
    {
      cerr << "mapper error: parse error (bad number of fields) in " << str << endl;
      return 0;
    }

  record.use_strideoffset_p = (fields.size() == 6);
  record.spec = str;
  record.hit_count = 0;

  // parse two or four fields
  component::status s1 = parse_attribute(fields[1], record.low);
  component::status s2 = parse_attribute(fields[2], record.high);
  if (s1 != component::ok || s2 != component::ok)
    {
      cerr << "mapper error: parse error (low-high) in " << str << endl;
      return 0;
    }
  if (record.use_strideoffset_p)
    {
      component::status s3 = parse_attribute(fields[3], record.stride);
      component::status s4 = parse_attribute(fields[4], record.width);
      if (s3 != component::ok || s4 != component::ok)
	{
	  cerr << "mapper error: parse error (stride,width) in " << str << endl;
	  return 0;
	}
    }

  // check fields for validity
  if (record.low > record.high)
    {
      cerr << "mapper error: illegal low-high in " << str << endl;
      return 0;
    }

  // check further
  if (record.use_strideoffset_p)
    {
      if (record.width > record.stride)
	{
	  cerr << "mapper error: illegal stride<width in " << str << endl;
	  return 0;
	}

      // compute stride_shift & stride_mask
      record.stride_shift = 1;
      for (unsigned i = 0; i<32; i++)
	{
	  if (record.stride == (1 << record.stride_shift))
	    break;
	  if (i == 31)
	    {
	      cerr << "mapper error: illegal stride in " << str << endl;
	      return 0;
	    }
	  record.stride_shift ++;
	}
      record.stride_mask = record.stride - 1;

      // compute width_shift
      switch (record.width)
	{
	case 1:
	  record.width_shift = 0;
	  break;
	case 2:
	  record.width_shift = 1;
	  break;
	case 4:
	  record.width_shift = 2;
	  break;
	case 8:
	  record.width_shift = 3;
	  break;
	default:
	  cerr << "mapper error: illegal width in " << str << endl;
	  return 0;
	}

      // compute offset; adjust high/low to contain entire stride regions
      record.offset = record.low & record.stride_mask;
      record.low &= ~ record.stride_mask;
      record.high |= record.stride_mask;
    }
  else
    {
      // no stride/offset
      record.stride = 0;
      record.stride_shift = 0;
      record.stride_mask = 0; 
      record.offset = 0;
      record.width = 0;
      record.width_shift = 0;
    }


  // fill in slot
  record.accessor = acc;

  /*
  cout << "new mapping_record: "
       << record.low << " " << record.high << " " << record.hit_count << " "
       << record.use_strideoffset_p << " " << record.stride << " " << record.stride_shift << " "
       << record.stride_mask << " " << record.offset << " " << record.width << " "
       << record.width_shift << " " << record.spec << endl;
  */

  // Return a copy of our hand-made record
  return new mapping_record (record);
}


inline mapping_record*
generic_mapper_bus::locate (host_int_4 address) const
{
  this->target->access_count ++;

  // check last-used entry first 
  mapping_record* cache = this->tlb; // one-entry tlb
  if (LIKELY(cache && address <= cache->high && address >= cache->low))
    {
      this->target->cache_hit_count ++;
      cache->hit_count ++;
      return cache;
    }

  // binary search in one statement!
  vector<mapping_record>::iterator where = 
    lower_bound (this->target->accessors.begin (),
		this->target->accessors.end (),
		address,
		mr_cmp ());

  // XXX: other optimizations

  while (where != this->target->accessors.end ())
    {
      mapping_record* found = & * where;
      // cout << " [found: " << found.first << "-" << found.last << "]" << endl;

      // Incoming address is smaller than the first map entry?
      if (UNLIKELY(address < found->low))
	break;

      // Incoming address is within this map entry?
      if (LIKELY(address <= found->high))
	{
	  found->hit_count ++;
	  this->tlb = found;
	  return found;
	}

      where ++;
    }

  return 0;
}



string
generic_mapper::get_hits (string entry)
{
  for (unsigned i=0; i<this->accessors.size(); i++)
    {
      if (this->accessors[i].spec == entry)
	return make_numeric_attribute (this->accessors[i].hit_count);
    }
  return "?";
}


component::status
generic_mapper::set_hits (string entry, const string& value)
{
  for (unsigned i=0; i<this->accessors.size(); i++)
    {
      if (this->accessors[i].spec == entry)
	return parse_attribute (value, this->accessors[i].hit_count);
    }
  return component::not_found;
}


string
generic_mapper::save_state ()
{
  // XXX: redo
  return string ();
} 


component::status
generic_mapper::restore_state (const string& state)
{
  // XXX: redo
  if (state == "")
    return component::ok;
  else 
    return component::bad_value;
} 



// ----------------------------------------------------------------------------

static
vector<string>
compMapperListTypes ()
{
  vector<string> types;
  types.push_back ("hw-mapper-basic");
  return types;
}


static
component*
compMapperCreate (const string& typeName)
{
  if (typeName == "hw-mapper-basic")
    return new generic_mapper ();
  else
    return 0;
}


static
void
compMapperDelete (component* c)
{
  delete dynamic_cast<generic_mapper*>(c);
}


// static object
extern const component_library mapper_component_library;

const component_library mapper_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compMapperListTypes, 
  & compMapperCreate,
  & compMapperDelete
};
