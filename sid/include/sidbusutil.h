// sidbusutil.h -*- C++ -*- Different types and sizes of buses.

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDBUSUTIL_H
#define SIDBUSUTIL_H

#include <sidconfig.h>
#include <sidtypes.h>

#include <string>
#include <map>
#include <vector>
#include <iostream>

namespace sidutil
{
  // The word_bus converts incoming bus access calls to a particular
  // preferred size & type.  The bus object is addressable as if it
  // was memory, with no alignment/size restrictions.

  template <typename DataType>
  class word_bus: public sid::bus
  {
  protected:
    word_bus() {}
    ~word_bus() {}

    virtual sid::bus::status word_write(sid::host_int_4 addr,
					DataType mask,
					DataType data) = 0;

    virtual sid::bus::status word_read(sid::host_int_4 addr,
				       DataType mask,
				       DataType& data) = 0;

    virtual void post_access_hook() { }

    // Method writes data at address. AccDataType can be different than
    // DataType. Method itself takes care to represent data to component
    // in its required data size.
    template <typename AccDataType>
    bus::status
    writeAny(sid::host_int_4 address, AccDataType data)
      {
	unsigned busWidth = sizeof(typename DataType::value_type);
	unsigned accWidth = sizeof(typename AccDataType::value_type);

	// Make local modifiable copy.
	sid::host_int_4 a = address;

	unsigned bytesWritten = 0;
	DataType d = 0;
        DataType mask = 0;
	while(bytesWritten < accWidth)
	  {
	    sid::host_int_1 byte = data.read_byte(bytesWritten);
	    d.write_byte((bytesWritten + a) % busWidth, byte);
	    mask.write_byte((bytesWritten + a) % busWidth, 0xff);

	    if(((bytesWritten + a) % busWidth == (busWidth - 1)) || // last byte in target
	       (bytesWritten == (accWidth - 1))) // last byte in source
	      {
		sid::bus::status s;

		s = this->word_write(sid::host_int_4(a / busWidth), mask, d);
		if (s != sid::bus::ok)
		  {
		    this->post_access_hook();
		    return s;
		  }

		a = a + busWidth; // advance address
		// Clear data.
		d = 0;
		// Clear mask.
		mask = 0;
	      }
	    bytesWritten ++;
	  }

	this->post_access_hook();
	return sid::bus::ok;
      }
    

    // This method is used to read data from address. Like the above
    // case AccDataType can be different than DataType. Method returns
    // ok if sucessful.
    template <typename AccDataType>
    sid::bus::status
    readAny(sid::host_int_4 address, AccDataType& data)
      {
	unsigned busWidth = sizeof(typename DataType::value_type);
	unsigned accWidth = sizeof(typename AccDataType::value_type);
	
	// Make local modifiable copy.
	sid::host_int_4 a = address;
	
	unsigned bytesRead = 0;
	unsigned bytesAddressed = 0;
        DataType mask = 0;
	while(bytesAddressed < accWidth)
	  {
	    mask.write_byte((bytesAddressed + a) % busWidth, 0xff);

	    if(((bytesAddressed + a) % busWidth == (busWidth - 1)) || // last byte in target
	       (bytesAddressed == (accWidth - 1))) // last byte in source
	      {
		sid::bus::status s;

		DataType d = 0;
		s = this->word_read(sid::host_int_4(a / busWidth), mask, d);
		if (s != sid::bus::ok)
		  {
		    this->post_access_hook();
		    return s;
		  }

		// Copy over newly read bytes
		while (bytesRead <= bytesAddressed)
		  {
		    assert (mask.read_byte((bytesRead + a) % busWidth) == 0xff);
		    sid::host_int_1 byte = d.read_byte((bytesRead + a) % busWidth);
		    data.write_byte(bytesRead, byte);
		    bytesRead ++;
		  }

		a = a + busWidth; // advance address
		// Clear mask.
		mask = 0;
	      }
	    
	    bytesAddressed ++;
	  }
	assert (bytesAddressed == bytesRead);

	this->post_access_hook();
	return sid::bus::ok;
      }
    
    
    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define SID_GB_WRITE(type1,type2) \
      sid::bus::status write(type1 addr, type2 data) throw () \
	  { return writeAny(addr, data); }
    
#define SID_GB_READ(type1,type2) \
      sid::bus::status read(type1 addr, type2& data) throw () \
	  { return readAny(addr, data); }
    
    SID_GB_WRITE(sid::host_int_4, sid::little_int_1)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_1)
    SID_GB_WRITE(sid::host_int_4, sid::little_int_2)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_2)
    SID_GB_WRITE(sid::host_int_4, sid::little_int_4)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_4)
    SID_GB_WRITE(sid::host_int_4, sid::little_int_8)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_8)

    SID_GB_READ(sid::host_int_4, sid::little_int_1)
    SID_GB_READ(sid::host_int_4, sid::big_int_1)
    SID_GB_READ(sid::host_int_4, sid::little_int_2)
    SID_GB_READ(sid::host_int_4, sid::big_int_2)
    SID_GB_READ(sid::host_int_4, sid::little_int_4)
    SID_GB_READ(sid::host_int_4, sid::big_int_4)
    SID_GB_READ(sid::host_int_4, sid::little_int_8)
    SID_GB_READ(sid::host_int_4, sid::big_int_8)

#undef SID_GB_WRITE
#undef SID_GB_READ
  };



  template <class Master, class DataType>
  class callback_word_bus: public word_bus<DataType>
  {
  public:
    typedef sid::bus::status (Master::*ReadFunction) (sid::host_int_4, DataType, DataType&);
    typedef sid::bus::status (Master::*WriteFunction) (sid::host_int_4, DataType, DataType);

  private:
    Master* receiver;
    ReadFunction read_callback;
    WriteFunction write_callback;

    sid::bus::status word_write(sid::host_int_4 addr,
				DataType mask,
				DataType data)
      {
	return (receiver->*write_callback) (addr, mask, data);
      }

    sid::bus::status word_read(sid::host_int_4 addr,
			       DataType mask,
			       DataType& data)
      {
	return (receiver->*read_callback) (addr, mask, data);
      }

  public:
    callback_word_bus (Master* m, ReadFunction rf, WriteFunction wf):
      receiver (m), read_callback (rf), write_callback (wf) {}
  };



  // This sort of bus passes accesses through to another, specified
  // by a meta-pointer.
  class passthrough_bus: public sid::bus
  {
  public:
    passthrough_bus(sid::bus** t): target(t) 
      {
	assert (target != 0);
      }
    ~passthrough_bus() {}
    
    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define SID_GB_WRITE(dtype) \
      sid::bus::status write(sid::host_int_4 addr, dtype data) throw ()\
	  { if (LIKELY(*target)) return (*target)->write(addr, data); else return sid::bus::unpermitted; }

#define SID_GB_READ(dtype) \
      sid::bus::status read(sid::host_int_4 addr, dtype& data) throw ()\
	  { if (LIKELY(*target)) return (*target)->read(addr, data); else return sid::bus::unpermitted; }

    SID_GB_WRITE(sid::little_int_1)
    SID_GB_WRITE(sid::big_int_1)
    SID_GB_WRITE(sid::little_int_2)
    SID_GB_WRITE(sid::big_int_2)
    SID_GB_WRITE(sid::little_int_4)
    SID_GB_WRITE(sid::big_int_4)
    SID_GB_WRITE(sid::little_int_8)
    SID_GB_WRITE(sid::big_int_8)

    SID_GB_READ(sid::little_int_1)
    SID_GB_READ(sid::big_int_1)
    SID_GB_READ(sid::little_int_2)
    SID_GB_READ(sid::big_int_2)
    SID_GB_READ(sid::little_int_4)
    SID_GB_READ(sid::big_int_4)
    SID_GB_READ(sid::little_int_8)
    SID_GB_READ(sid::big_int_8)

#undef SID_GB_WRITE
#undef SID_GB_READ

  private:
    sid::bus** target;
  };
  
  // This sort of bus passes accesses through to one of two buses which
  // are specified by meta-pointers.  Access can be switched dynamically.
  class mux_passthrough_bus: public sid::bus
  {
  public:
    mux_passthrough_bus(sid::bus** t1, sid::bus** t2): index(0), target(t1) 
      {
	assert (t1 != 0);
        assert (t2 != 0);
        t[0] = t1;
        t[1] = t2;
      }
    ~mux_passthrough_bus() {}
    void switch_bus() { index ^= 1; target = t[index]; }
    
    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define SID_GB_WRITE(dtype) \
      sid::bus::status write(sid::host_int_4 addr, dtype data) throw ()\
	  { if (LIKELY(*target)) return (*target)->write(addr, data); else return sid::bus::unpermitted; }

#define SID_GB_READ(dtype) \
      sid::bus::status read(sid::host_int_4 addr, dtype& data) throw ()\
	  { if (LIKELY(*target)) return (*target)->read(addr, data); else return sid::bus::unpermitted; }

    SID_GB_WRITE(sid::little_int_1)
    SID_GB_WRITE(sid::big_int_1)
    SID_GB_WRITE(sid::little_int_2)
    SID_GB_WRITE(sid::big_int_2)
    SID_GB_WRITE(sid::little_int_4)
    SID_GB_WRITE(sid::big_int_4)
    SID_GB_WRITE(sid::little_int_8)
    SID_GB_WRITE(sid::big_int_8)

    SID_GB_READ(sid::little_int_1)
    SID_GB_READ(sid::big_int_1)
    SID_GB_READ(sid::little_int_2)
    SID_GB_READ(sid::big_int_2)
    SID_GB_READ(sid::little_int_4)
    SID_GB_READ(sid::big_int_4)
    SID_GB_READ(sid::little_int_8)
    SID_GB_READ(sid::big_int_8)

#undef SID_GB_WRITE
#undef SID_GB_READ

  private:
    int index;
    sid::bus** target;
    sid::bus** t[2];
  };

  // The passthrough_word_bus maps memory and either directly passes through to the underlying
  // bus or else converts the incoming bus access call to a particular
  // preferred size & type.  The bus object is addressable as if it
  // was memory, with no alignment/size restrictions.

  template <class DataType>
  class passthrough_word_bus: public word_bus<DataType>
  {

  protected:

    sid::bus **target;

    passthrough_word_bus(sid::bus **t): target(t) 
      { 
	assert (target != 0);
      }
    ~passthrough_word_bus() {}

    virtual sid::bus::status word_write(sid::host_int_4 addr,
					DataType mask,
					DataType data) = 0;

    virtual sid::bus::status word_read(sid::host_int_4 addr,
				       DataType mask,
				       DataType& data) = 0;

    virtual int do_direct_passthrough (sid::host_int_4 addr) { return 0; } 

    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define SID_GB_WRITE(type1,type2) \
      sid::bus::status write(type1 addr, type2 data) throw () \
	  { if (do_direct_passthrough (addr)) \
               return (*target)->write(addr, data); \
               return word_bus<DataType>::write(addr, data); }
    
#define SID_GB_READ(type1,type2) \
      sid::bus::status read(type1 addr, type2& data) throw () \
	  { if (do_direct_passthrough (addr)) \
               return (*target)->read(addr, data); \
            return word_bus<DataType>::read(addr, data); }
    
    SID_GB_WRITE(sid::host_int_4, sid::little_int_1)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_1)
    SID_GB_WRITE(sid::host_int_4, sid::little_int_2)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_2)
    SID_GB_WRITE(sid::host_int_4, sid::little_int_4)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_4)
    SID_GB_WRITE(sid::host_int_4, sid::little_int_8)
    SID_GB_WRITE(sid::host_int_4, sid::big_int_8)

    SID_GB_READ(sid::host_int_4, sid::little_int_1)
    SID_GB_READ(sid::host_int_4, sid::big_int_1)
    SID_GB_READ(sid::host_int_4, sid::little_int_2)
    SID_GB_READ(sid::host_int_4, sid::big_int_2)
    SID_GB_READ(sid::host_int_4, sid::little_int_4)
    SID_GB_READ(sid::host_int_4, sid::big_int_4)
    SID_GB_READ(sid::host_int_4, sid::little_int_8)
    SID_GB_READ(sid::host_int_4, sid::big_int_8)

#undef SID_GB_WRITE
#undef SID_GB_READ
  };

  // The harvard bus allows a single virtual memory model to be broken
  // down into data and insn memory via section numbers (top byte of address).
  // The sections for data and insn are given in the form of first section number
  // and last section number.  The bus object is addressable as if it was memory, 
  // with no alignment/size restrictions.

  class harvard_bus: public sid::bus
  {
  protected:
    sid::bus   **insn_bus;
    sid::bus   **data_bus;
    sid::host_int_4 first_data_section;
    sid::host_int_4 last_data_section;
    sid::host_int_4 first_insn_section;
    sid::host_int_4 last_insn_section;

  public:
    harvard_bus (sid::bus **d_bus, sid::bus **i_bus, 
		 sid::host_int_4 first_data, sid::host_int_4 last_data,
                 sid::host_int_4 first_insn, sid::host_int_4 last_insn):
      insn_bus (i_bus),
      data_bus (d_bus),
      first_data_section (first_data),
      last_data_section (last_data),
      first_insn_section (first_insn),
      last_insn_section (last_insn)
      { 
	assert (insn_bus != 0);
	assert (data_bus != 0);
      }
    ~harvard_bus() {}

    sid::bus *map_addr_to_bus (sid::host_int_4 *addr)
      {
	sid::host_int_4 section = *addr >> 24;

	if (section >= first_data_section && section <= last_data_section)
          {
            *addr -= first_data_section << 24;
	    return *data_bus;
          }
	if (section >= first_insn_section && section <= last_insn_section)
          {
            *addr -= first_insn_section << 24;
	    return *insn_bus;
          }
	return NULL;
      }


    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define SID_GB_WRITE(type1) \
      sid::bus::status write(sid::host_int_4 addr, type1 data) throw () \
	  { sid::bus *bus = this->map_addr_to_bus (&addr); \
            if (UNLIKELY(bus == NULL)) \
              return sid::bus::unmapped; \
            else \
              return bus->write(addr, data); }
    
#define SID_GB_READ(type1) \
      sid::bus::status read(sid::host_int_4 addr, type1& data) throw () \
	  { sid::bus *bus = this->map_addr_to_bus (&addr); \
            if (UNLIKELY(bus == NULL)) \
              return sid::bus::unmapped; \
            else \
              return bus->read(addr, data); }
    
    SID_GB_WRITE(sid::little_int_1)
    SID_GB_WRITE(sid::big_int_1)
    SID_GB_WRITE(sid::little_int_2)
    SID_GB_WRITE(sid::big_int_2)
    SID_GB_WRITE(sid::little_int_4)
    SID_GB_WRITE(sid::big_int_4)
    SID_GB_WRITE(sid::little_int_8)
    SID_GB_WRITE(sid::big_int_8)

    SID_GB_READ(sid::little_int_1)
    SID_GB_READ(sid::big_int_1)
    SID_GB_READ(sid::little_int_2)
    SID_GB_READ(sid::big_int_2)
    SID_GB_READ(sid::little_int_4)
    SID_GB_READ(sid::big_int_4)
    SID_GB_READ(sid::little_int_8)
    SID_GB_READ(sid::big_int_8)

#undef SID_GB_WRITE
#undef SID_GB_READ
  };




  // For byte-wide peripherals - similar to word_bus<host_int_1>.
  // It accepts only byte-wide accesses.
  class byte_bus : public sid::bus
  {
  protected:
    byte_bus() {}
    ~byte_bus() {}
    
    virtual sid::bus::status 
    write_data(sid::host_int_4 addr, sid::host_int_1 data) throw () = 0;
    
    virtual sid::bus::status 
    read_data(sid::host_int_4 addr, sid::host_int_1& data) throw () = 0;
    
    // Byte accesses to a byte-wide component are easy.
    sid::bus::status 
    write(sid::host_int_4 addr, sid::little_int_1 data) throw () 
      {
	return write_data(addr, data.integer_value() );
      }

    sid::bus::status 
    write(sid::host_int_4 addr, sid::big_int_1 data) throw () 
      {
	return write_data( addr, data.integer_value() );
      }
    
    sid::bus::status 
    read( sid::host_int_4 addr, sid::little_int_1& data ) throw ()
      {
	sid::host_int_1 d;
	sid::bus::status s = read_data( addr, d );
	data = d;
	return s;
      }
        
    sid::bus::status 
    read( sid::host_int_4 addr, sid::big_int_1& data ) throw ()
      {
	sid::host_int_1 d;
	sid::bus::status s = read_data( addr, d );
	data = d;
	return s;
      }

    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define BYTE_BUS_WRITE_A4(dtype) \
    sid::bus::status write(sid::host_int_4 addr, dtype data ) throw () {\
          return sid::bus::unmapped; }

#define BYTE_BUS_READ_A4(dtype)\
    sid::bus::status read(sid::host_int_4 addr, dtype& data ) throw () { \
          return sid::bus::unmapped; }

    BYTE_BUS_WRITE_A4( sid::little_int_2 )
    BYTE_BUS_WRITE_A4( sid::big_int_2 )
    BYTE_BUS_WRITE_A4( sid::little_int_4 )
    BYTE_BUS_WRITE_A4( sid::big_int_4 )
    BYTE_BUS_WRITE_A4( sid::little_int_8 )
    BYTE_BUS_WRITE_A4( sid::big_int_8 )
    BYTE_BUS_READ_A4 ( sid::little_int_2 )
    BYTE_BUS_READ_A4 ( sid::big_int_2 )
    BYTE_BUS_READ_A4 ( sid::little_int_4 )
    BYTE_BUS_READ_A4 ( sid::big_int_4 )
    BYTE_BUS_READ_A4 ( sid::little_int_8 )
    BYTE_BUS_READ_A4 ( sid::big_int_8 )

#undef BYTE_BUS_WRITE_A4
#undef BYTE_BUS_READ_A4
  };


  // Callback_byte_bus class allows user to have different read/write
  // methods for each object of this class. User can have one read
  // and write method on class level for all objects of class
  // call_back_byte_bus or user can have seperate read and write
  // methods in class Reciever for each object of class
  // callback_byte_bus.
  template <class Receiver>
  class callback_byte_bus : public byte_bus {
  public:
    callback_byte_bus( Receiver* h,
		       sid::bus::status (Receiver::*r) ( 
			 sid::host_int_4, sid::host_int_1& ),
		       sid::bus::status (Receiver::*w) ( 
			 sid::host_int_4, sid::host_int_1 )
		      ) : receiver(h), reader(r), writer(w) {}

    ~callback_byte_bus() {}

  protected:
    Receiver* receiver;
    sid::bus::status (Receiver::*reader) ( sid::host_int_4 addr, 
					   sid::host_int_1& data );
    sid::bus::status (Receiver::*writer) ( sid::host_int_4 addr, 
					   sid::host_int_1 data );

    virtual sid::bus::status 
    read_data( sid::host_int_4 addr, sid::host_int_1& data ) throw() {
      return (receiver->*reader) ( addr, data );
    }

    virtual sid::bus::status 
    write_data( sid::host_int_4 addr, sid::host_int_1 data ) throw() {
      return (receiver->*writer) ( addr, data );
    }
    
  };


  template <typename DataType>
  class control_register;

  // This class is used to store different types of component
  // registers. Types of register storage supported by this class are
  // read-only, write-only, and read/write only registers.
  template <typename DataType>
  class control_register_bank
  {
  public:
    void add_writeonly_register(control_register<DataType>* reg,
				sid::host_int_4 address);
    void add_readonly_register(control_register<DataType>* reg,
			       sid::host_int_4 address);
    void add_readwrite_register(control_register<DataType>* reg,
				sid::host_int_4 address);
    
  private:
    typedef std::vector<control_register<DataType>*> reg_vector;
    typedef std::map<sid::host_int_4, reg_vector> reg_map;

  protected:
    // read- and write- mappings for control registers
    reg_map read_map, write_map;
  };

  template <typename DataType>
  void 
  control_register_bank<DataType>::add_writeonly_register(control_register<DataType>* reg,
							  sid::host_int_4 address)
  {
    write_map[address].push_back(reg);
  }


  template <typename DataType>
  void 
  control_register_bank<DataType>::add_readonly_register(control_register<DataType>* reg, 
							  sid::host_int_4 address)
  {
    read_map[address].push_back(reg);
  }


  template <typename DataType>
  void 
  control_register_bank<DataType>::add_readwrite_register(control_register<DataType>* reg, 
							  sid::host_int_4 address)
  {
    this->add_writeonly_register(reg, address);
    this->add_readonly_register(reg, address);
  }


  // This is a general type of control register whose value is get/set
  // by a virtual function.
  template <typename DataType>
  class control_register
  {
  public:
    virtual void set (DataType set_value, DataType set_mask) = 0;
    virtual DataType get () = 0;
    DataType get_mask() const { return this->field_mask; }
    
    control_register(control_register_bank<DataType>* bank,
		     sid::host_int_4 offset,
		     DataType m,
		     bool read,
		     bool write): field_mask(m)
      {
	if (read)
	  bank->add_readonly_register(this, offset);
	if (write)
	  bank->add_writeonly_register(this, offset);
      }
  private:
    DataType field_mask;
  };

  // streaming ops for following class
  template <typename DataType> class value_control_register;
  
  template <typename DataType>
  std::ostream& 
  operator << (std::ostream& o, const value_control_register<DataType>& it)
  {  
    sid::host_int_8 v = (sid::host_int_8) it.field_value;
    o << v;
    return o;
  }


  template <typename DataType>
  std::istream& 
  operator >> (std::istream& i, value_control_register<DataType>& it)
  {
    sid::host_int_8 v;
    i >> v;
    it.field_value = v;
    return i;
  }


  // This is a type of control register whose value is stored directly.  It
  // provides an assignment and conversion operator for use like a variable.
  template <typename DataType>
  class value_control_register: public control_register<DataType>
  {
  private:
    typedef typename DataType::value_type ValueType;

  public:
    void set (DataType set_value, DataType set_mask)
      {
	this->field_value = (this->field_value & ~set_mask) | (set_value & set_mask);
      }


    DataType get ()
      {
	return this->field_value; 
      }

    DataType get () const
      {
	return this->field_value; 
      }

    value_control_register(control_register_bank<DataType>* b,
			   sid::host_int_4 o,
			   DataType m,
			   bool r,
			   bool w,
			   DataType v): 
      control_register<DataType>(b,o,m,r,w),
      field_value(v) {}

    value_control_register(control_register_bank<DataType>* b,
			   sid::host_int_4 o,
			   DataType m,
			   bool r,
			   bool w):
      control_register<DataType>(b,o,m,r,w),
      field_value(0) {}

    // Some convenience operators for accessing register fields
    void operator = (const DataType& v)
      {
	DataType shifted_v = v << this->shift_amount();
	this->set (shifted_v, this->get_mask()); 
      }


    void operator = (const ValueType& v)
      {
	ValueType shifted_v = v << this->shift_amount();
	this->set (shifted_v, this->get_mask()); 
      }

    // conversion operators
    operator DataType () const
      {
	DataType shifted_v = this->get() >> this->shift_amount(); 
	return shifted_v;
      }

    operator ValueType () const
      {
	ValueType shifted_v = this->get() >> this->shift_amount(); 
	return shifted_v;
      }

    friend std::ostream& operator << <> (std::ostream& o, 
					 const value_control_register<DataType>& it);
    friend std::istream& operator >> <> (std::istream& i, 
					 value_control_register<DataType>& it);
  
private:
    DataType field_value;
    
    // return index of mask LSB
    unsigned shift_amount() const
      {
	DataType mask = this->get_mask ();
	for (unsigned i=0; i<sizeof(DataType)*8; i++)
	  if (mask & (1 << i))
	    return i;
	assert(0);
      }
  };

  // This is a type of control register whose value never changes.
  // One may also use it for reserved fields.
  // Read only register.
  template <typename DataType>
  class fixed_control_register: public value_control_register<DataType>
  {
  public:
    fixed_control_register(control_register_bank<DataType>* b,
			   sid::host_int_4 o,
			   DataType m,
			   bool r,
			   bool w,
			   DataType v): 
      value_control_register<DataType>(b,o,m,r,w,v)
      {}

  protected:
    void set (DataType set_value, DataType set_mask)
      {
	// do nothing
	// XXX: check for match with field_value?
      }
  };


  // This is a type of control register whose value is set/get via
  // a pair of class member functions.
  template <typename DataType, class Class>
  class callback_control_register: public control_register<DataType>
  {
  public:
    callback_control_register(control_register_bank<DataType>* b,
			      sid::host_int_4 o,
			      DataType m,
			      bool r,
			      bool w,
			      Class* rec, 
			      void (Class::*s)(DataType, DataType), 
			      DataType (Class::*g)()): 
      control_register<DataType>(b,o,m,r,w),
      receiver(rec),
      set_callback(s),
      get_callback(g)
      {}

    // Read only register
    callback_control_register(control_register_bank<DataType>* b,
			      sid::host_int_4 o,
			      DataType m,
			      bool r,
			      bool w,
			      Class* rec, 
			      DataType (Class::*g)()): 
      control_register<DataType>(b,o,m,r,w),
      receiver(rec),
      set_callback(0),
      get_callback(g)
      {}

    // Write only register
    callback_control_register(control_register_bank<DataType>* b,
			      sid::host_int_4 o,
			      DataType m,
			      bool r,
			      bool w,
			      Class* rec, 
			      void (Class::*s)(DataType, DataType)):
      control_register<DataType>(b,o,m,r,w),
      receiver(rec),
      set_callback(s),
      get_callback(0)
      {}

  private:
    Class* receiver;
    void (Class::*set_callback) (DataType, DataType);
    DataType (Class::*get_callback) ();

    void set (DataType set_value, DataType set_mask)
      {
	assert(this->set_callback);
	(receiver->*set_callback)(set_value, set_mask); 
      }

    DataType get ()
      {
	assert(this->get_callback);
	return (receiver->*get_callback)(); 
      }
  };
  
  // This is a bus that acts like a look-up table for control
  // registers.  Each register may take up a bitfield of a word.
  // Read/Write accesses are dispatched to all the registers whose
  // bitfields overlap the accessed word.

  template <typename DataType>
  class control_register_bus: public control_register_bank<DataType>,
			      public word_bus <DataType>
  {
  protected:
    sid::bus::status word_write(sid::host_int_4 addr,
				DataType mask,
				DataType data)
      {
	reg_map::iterator i = write_map.find(addr);
	if (i == write_map.end())
	  return sid::bus::unmapped; // XXX: or unpermitted?
	
	DataType unmatched_mask = mask;

	// scan through all registers at this address
	for(reg_vector::iterator it = i->second.begin();
	    it != i->second.end();
	    it++)
	  {
	    control_register<DataType>* reg = (*it);
	    DataType reg_mask = reg->get_mask();
	    if (reg_mask & mask) // overlap?
	      {
		// Assert that no other register took these bits already.
		assert ((unmatched_mask & reg_mask) == (mask & reg_mask)); 
		// Take the bits.
		unmatched_mask = unmatched_mask & ~reg_mask;
		// Hand over the masked data value.  Use both the
		// incoming write mask and the control register mask
		reg->set (data & mask & reg_mask, reg_mask & mask);
	      }
	  }

	// Assert that all bits in this word have been taken by control registers.
	assert (unmatched_mask == 0); 
	return sid::bus::ok;
      }


    sid::bus::status word_read(sid::host_int_4 addr,
			       DataType mask,
			       DataType& data_out)
      {
	reg_map::iterator i = read_map.find(addr);
	if (i == read_map.end())
	  return sid::bus::unmapped; // XXX: or unpermitted?

	DataType data = 0;
	DataType unmatched_mask = mask;

	// scan through all registers at this address
	for(reg_vector::iterator it = i->second.begin();
	    it != i->second.end();
	    it++)
	  {
	    control_register<DataType>* reg = (*it);
	    DataType reg_mask = reg->get_mask();
	    if (reg_mask & mask) // overlap?
	      {
		// Assert that no other register took these bits already.
		assert ((unmatched_mask & reg_mask) == (mask & reg_mask)); 
		// Take the bits.
		unmatched_mask = unmatched_mask & ~reg_mask;
		// Hand over the masked data value.  Use both the
		// incoming read mask and the control register mask
		DataType d = reg->get ();
		data = data | (d & reg_mask & mask);
	      }
	  }

	// Assert that all bits in this word have been taken by control registers.
	assert (unmatched_mask == 0); 
	// Return the data.  (Caller will use the read mask.)
	data_out = data;
	return sid::bus::ok;
      }
  };


  // Following class is used to overwrite access supervisory
  // interface methods declared in class sid::component.
  
  class fixed_accessor_map_component: public virtual sid::component
  {
  public:

    // Returns vector of accessor names to components.
    std::vector<std::string>
    accessor_names() throw ()
      {
	std::vector<std::string> names;
	for(accessor_map_t::const_iterator it = this->accessor_map.begin();
	    it != this->accessor_map.end();
	    it++)
	  {
	    names.push_back(it->first);
	  }
	return names;
      }


    // Returns pointer to accessor bus corresponding to string name.
    sid::bus*
    connected_bus(const std::string& name) throw ()
      {
	accessor_map_t::iterator it = this->accessor_map.find(name);
	if (it == this->accessor_map.end())
	  return 0;
	else
	  return * it->second;
      }


    // Sets accessor represented by string name to bus pointed by argument.
    sid::component::status
    connect_accessor(const std::string& name, sid::bus* bus) throw ()
      {
	accessor_map_t::iterator it = this->accessor_map.find(name);
	if (it != this->accessor_map.end()) 
	  {
	    // Only allow setting if unset
	    if (*it->second == 0)
	      {
		*it->second = bus;
		return sid::component::ok;
	      }
	    else
	      return sid::component::bad_value;
	  }

	return sid::component::not_found;
      }

    // Disassociate a named accessor from a bus.
    sid::component::status
    disconnect_accessor(const std::string& name, sid::bus* bus) throw ()
      {
	accessor_map_t::iterator it = this->accessor_map.find(name);
	if (it != this->accessor_map.end()) 
	  {
	    // Only allow setting if set to given prior value
	    if (*it->second == bus)
	      {
		*it->second = 0;
		return sid::component::ok;
	      }
	    else
	      return sid::component::bad_value;
	  }

	return sid::component::not_found;
      }

  protected:
    // add accessor to component
    void
    add_accessor(const std::string& name, sid::bus** accessor_address)
      {
	assert(accessor_address);
	accessor_map[name] = accessor_address;
      }

  private:
    typedef std::map<std::string,sid::bus**> accessor_map_t;
    mutable accessor_map_t accessor_map;
    
  };

  
  // Class fixed_bus_map_component overwrites bus supervisory
  // interface declared in class sid::component.
  class fixed_bus_map_component: public virtual sid::component
  {
  public:
    std::vector<std::string>
    bus_names() throw ()
      {
	std::vector<std::string> names;
	for(bus_map_t::const_iterator it = this->bus_map.begin();
	    it != this->bus_map.end();
	    it++)
	  {
	    names.push_back(it->first);
	  }
	return names;
      }
    
    // Returns pointer to bus that corresponds to string name.
    sid::bus*
    find_bus(const std::string& name) throw ()
      {
	bus_map_t::iterator it = this->bus_map.find(name);
	if (it == this->bus_map.end())
	  return 0;
	else
	  return it->second;
      }

  protected:
    void
    add_bus(const std::string& name, sid::bus* bus)
      {
	assert(bus);
	bus_map[name] = bus;
      }

    // Disassociate a named bus
    sid::component::status
    disconnect_bus(const std::string& name, sid::bus* bus) throw ()
      {
	bus_map_t::iterator it = this->bus_map.find(name);
	if (it != this->bus_map.end()) 
	  {
	    // Only allow setting if set to given prior value
	    if (it->second == bus)
	      {
		it->second = 0;
		return sid::component::ok;
	      }
	    else
	      return sid::component::bad_value;
	  }

	return sid::component::not_found;
      }

  private:
    typedef std::map<std::string,sid::bus*> bus_map_t;
    mutable bus_map_t bus_map;
  };
}



#endif // H_SIDBUSUTIL_H
