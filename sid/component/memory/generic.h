// generic.h - Header for the generic_memory class.  -*- C++ -*-

// Copyright (C) 1999-2001, 2006, 2007 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef GENERIC_H
#define GENERIC_H


#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidtypes.h>
#include <sidmiscutil.h>

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <new>

using std::vector;
using std::string;
using std::bad_alloc;
using std::istream;
using std::ostream;
using std::ios;
using std::cerr;
using std::endl;
using std::ifstream;

using sid::component;
using sid::bus;
using sid::host_int_1;
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

using sidutil::fixed_pin_map_component;
using sidutil::no_accessor_component;
using sidutil::fixed_attribute_map_component;
using sidutil::fixed_relation_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::reversible_component;
using sidutil::std_error_string;
using sidutil::callback_pin;
using sidutil::output_pin;


// ----------------------------------------------------------------------------


class generic_memory: public virtual component,
		      protected virtual fixed_pin_map_component,
		      protected no_accessor_component,
		      protected virtual fixed_attribute_map_component,
		      protected fixed_relation_map_component,
		      protected fixed_bus_map_component,
		      protected reversible_component
{
public:
  generic_memory() throw (bad_alloc);
  ~generic_memory();

protected:
  // memory buffers
  friend class generic_read_only_bus;
  friend class generic_read_write_bus;
  host_int_1* buffer;
  host_int_4 buffer_length;
  bool mmapping_p;

  // state control
  virtual string save_state() { return make_attribute(*this); }
  virtual component::status restore_state(const string& state)
  {
    return parse_attribute(state, *this);
  }
  virtual void stream_state (ostream&) const;
  virtual void destream_state (istream&);

  friend ostream& operator << (ostream& o, const generic_memory& it);
  friend istream& operator >> (istream& i, generic_memory& it);

  host_int_4 max_buffer_length;
  bool attempt_resize (host_int_4 new_length) throw();

  host_int_4 base_address;
  bool warn_rom_write;
  bool allow_rom_write;
  
  host_int_2 read_latency;
  host_int_2 write_latency;

protected:
  // Change logging for the purpose of reverse simulation.
  component *sched;
  sidutil::change_log change_log;
  void record_update (host_int_4 address, const void *bytes, unsigned width);
  virtual void restore_state_to_time (sid::host_int_4 tick);

private:
  string get_size_attr ();
  component::status set_size_attr (const string& s);

  string image_file_name;
  callback_pin<generic_memory> imageload_pin;
  void imageload_handler (host_int_4);
  callback_pin<generic_memory> imagestore_pin;
  void imagestore_handler (host_int_4);
  output_pin error_pin;
  callback_pin<generic_memory> imagemmap_pin;
  void imagemmap_handler (host_int_4);
  callback_pin<generic_memory> imagemsync_pin;
  void imagemsync_handler (host_int_4);
};




class generic_read_only_bus: public bus
{
public:
  generic_read_only_bus(generic_memory* target): 
    target(target) {}

  // some macros to make manufacturing of the cartesian-product calls simpler
#define SID_GB_WRITE(type2) \
      bus::status write(host_int_4 address, type2 data) throw () \
	  { if (! target->warn_rom_write && ! target->allow_rom_write) \
	       return bus::unpermitted;			\
	    cerr << "Warning: invalid write to ROM address 0x" << std::hex << target->base_address + address << endl; \
	    if (target->allow_rom_write)		\
	        return this->write_any(address,data);	\
	    else					\
		return bus::ok; }
 
#define SID_GB_READ(type2) \
      bus::status read(host_int_4 address, type2& data) throw () \
	  { return this->read_any(address,data); }
  
  // ----------------------------------------------------------------
  
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

protected:
  generic_memory* target;

  template <typename DataType>
  inline bus::status
  read_any(host_int_4 address, DataType& data);

  template <typename DataType>
  inline bus::status
  write_any(host_int_4 address, DataType data);
};




class generic_read_write_bus: public generic_read_only_bus
{
public:
  generic_read_write_bus(generic_memory* target): 
    generic_read_only_bus(target) {}


  // some macros to make manufacturing of the cartesian-product calls simpler
#define SID_GB_WRITE(type2) \
      bus::status write(host_int_4 address, type2 data) throw () \
	      { return this->write_any(address,data); } \
  
  // ----------------------------------------------------------------
  
    SID_GB_WRITE(little_int_1);
    SID_GB_WRITE(little_int_2);
    SID_GB_WRITE(little_int_4);
    SID_GB_WRITE(little_int_8);

    SID_GB_WRITE(big_int_1);
    SID_GB_WRITE(big_int_2);
    SID_GB_WRITE(big_int_4);
    SID_GB_WRITE(big_int_8);
      
#undef SID_GB_WRITE
};



// ----------------------------------------------------------------------------

template <typename DataType>
inline bus::status
generic_read_only_bus::write_any(host_int_4 address, DataType data)
{
  const unsigned width = sizeof(typename DataType::value_type); 

  // Range check address
  if (LIKELY((address >= 0) && ((address+width) <= target->buffer_length)))
    {
      typename DataType::value_type mem_image = data.target_memory_value();
      if (UNLIKELY (target->reversible_p))
	target->record_update (address, & mem_image, width);
      memcpy (& target->buffer[address], & mem_image, width);
      bus::status st (bus::ok);
      st.latency = target->write_latency;
      return st;
    }

  return bus::unmapped;
}


template <typename DataType>
inline sid::bus::status
generic_read_only_bus::read_any(host_int_4 address, DataType& data)
{
  const unsigned width = sizeof(typename DataType::value_type);

  // Range check address
  if (LIKELY((address >= 0) && ((address+width) <= target->buffer_length)))
    {
      typename DataType::value_type mem_image;
      memcpy (& mem_image, & target->buffer[address], width);
      data.set_target_memory_value (mem_image);
      bus::status st (bus::ok);
      st.latency = target->read_latency;
      return st;
    }

  return bus::unmapped;
}



// ----------------------------------------------------------------------------



#endif // GENERIC_H

