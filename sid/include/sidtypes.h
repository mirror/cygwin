// sidtypes.h - Different data types and automatic conversions between
// them (for example, big and little endian integrals).  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDTYPES_H
#define SIDTYPES_H

#include <iostream>
#include <iomanip>
#include <cassert>

// In order to make the sid core header files host-independent,
// host-specific (autoconf-generated) headers are not #included here.
// Instead, we use a handful of compiler-provided macros to determine
// some key platform parameters.

#if defined(__NetBSD__)
# include <machine/endian.h>
# if BYTE_ORDER == LITTLE_ENDIAN
#  define HOST_BIG_ENDIAN false
# else
#  define HOST_BIG_ENDIAN true
# endif
#else
# if defined(__i386__) || defined(__x86_64__) || defined(__alpha__) || (defined(__mips__) && defined(_MIPSEL))
#  define HOST_BIG_ENDIAN false
# elif defined(__sparc__) || defined(__powerpc__) || (defined(__mips__) && defined(_MIPSEB))
#  define HOST_BIG_ENDIAN true
# else
#  error "Unknown host platform"
# endif
#endif


namespace sid {
  // XXX: Define these conditionally.
  typedef unsigned char host_int_1;
  typedef unsigned short host_int_2;
  typedef unsigned int host_int_4;
  typedef unsigned long long host_int_8;
  typedef signed char signed_host_int_1;
  typedef signed short signed_host_int_2;
  typedef signed int signed_host_int_4;
  typedef signed long long signed_host_int_8;



  
  // The following bytereverse functions are used to convert between
  // big-endian and little-endian integers.

  inline host_int_1
  bytereverse(host_int_1 value)
  {
    return value;
  }

  inline host_int_2
  bytereverse(host_int_2 value)
  {
    // This is a 386 instruction.
#if defined(__GNUC__) && (defined(__i386__) || defined (__x86_64__))
    __asm__("xchgb %b0,%h0" : "=q" (value) :  "0" (value));
#else
      value = ( ((value & 0xff00U) >> 8) 
	      | ((value & 0x00ffU) << 8));
#endif
    return value;
  }

  inline host_int_4
  bytereverse(host_int_4 value)
  {
#if defined(__GNUC__) && (defined(__i486__) || defined(__i586__) || defined(__i686__) || defined (__x86_64__))
    // This is a 486+ instruction
      __asm__ ("bswap %0" : "=r" (value) : "0" (value));
#else
      value = ( ((value & 0xff000000UL) >> 24)
	      | ((value & 0x00ff0000UL) >> 8)
	      | ((value & 0x0000ff00UL) << 8)
	      | ((value & 0x000000ffUL) << 24));
#endif
    return value;
  }

  inline host_int_8
  bytereverse(host_int_8 value)
  {
#if defined (__GNUC__) && defined (__x86_64__)
    // This is an x86_64 instruction.
    __asm__ ("bswap %0" : "=r" (value) : "0" (value));
#else
    host_int_4 upper = (value & 0xffffffff00000000ULL) >> 32;
    host_int_4 lower = (value & 0x00000000ffffffffULL);
    upper = bytereverse(upper);
    lower = bytereverse(lower);
    value = ((host_int_8)lower) << 32 | (host_int_8)upper;
#endif
    return value;
  }


  // A bi-endian integer class.
  // 
  // Each instance represents an integer quanitity, with an additional
  // tag that describes how that value should be stored in simulated
  // memory.
  //
  // The template class any_int<> should not be used directly.
  // Rather, use one of the typedef'd classes:
  // big_int_1, big_int_2, big_int_4, big_int_8
  // little_int_1, little_int_2, little_int_4, or little_int_8

  template <typename IntType, bool IsBig>
  class any_int
  {
  public:
    // Utility related types
    typedef IntType value_type;
    typedef any_int<IntType,HOST_BIG_ENDIAN> host_int_type;
    typedef any_int<host_int_1,IsBig> size_1_type;
    typedef any_int<host_int_2,IsBig> size_2_type;
    typedef any_int<host_int_4,IsBig> size_4_type;
    typedef any_int<host_int_8,IsBig> size_8_type;


    // Return the natural integer value represented by this object.
    // This value is the same, whether this class represents a big or
    // little endian value.
    IntType integer_value() const { return _integer_value; }
    operator IntType () const { return _integer_value; }
    
    // Return the simulated memory image of this value.  This may be
    // a byte-reversed copy of integer_value().
    IntType target_memory_value() const
      {
	if (IsBig == HOST_BIG_ENDIAN)
	  return this->_integer_value;
	else
	  return bytereverse (_integer_value);
      }

    // Set the simulated memory image of this value.  It may be
    // byte-reversed.
    void set_target_memory_value(IntType v)
      {
	if (IsBig == HOST_BIG_ENDIAN)
	  this->_integer_value = v;
	else
	  this->_integer_value = bytereverse(v);
      }



    // The default constructor constructs an object with value 0. 
    any_int(): _integer_value (0) {}

    // Construct from a big_int type.
    // Copies the integer_value.  Regardless of types, the value is
    // NOT byte-reversed by this call.
    // v is the big_int value to construct the new object from. 
    any_int(const any_int<IntType,true>& v): _integer_value (v.integer_value()) {}
 
    // Construct from a little_int type.
    // Copies the integer_value.  Regardless of types, the value is
    // NOT byte-reversed by this call.
    // v is the little_int value to construct the new object from.
    any_int(const any_int<IntType,false>& v): _integer_value (v.integer_value()) {}

    // Construct from a integer type.
    // The new object's integer_value() method will return `v'.
    // v is the integer value to construct the new object from. 
    any_int(IntType v): _integer_value(v) {}


    // Assign from a little_int type.
    // Copies the integer_value.  Regardless of types, the value is
    // NOT byte-reversed by this call.
    // v is the little_int value to be assigned from.
    any_int<IntType,IsBig>& operator = (const any_int<IntType,false>& v)
      {
	_integer_value = v.integer_value();
	return *this;
      }

    // Assign from a big_int type.
    // Copies the integer_value.  Regardless of types, the value is 
    // NOT byte-reversed by this call.
    // v is the little_int value to be assigned from.
    any_int<IntType,IsBig>& operator = (const any_int<IntType,true>& v)
      {
	_integer_value = v.integer_value();
	return *this;
      }
    
    // Assign from a integer type.
    // The new object's integer_value() method will return `v'.
    // v is the integer value to construct the new object from. 
    any_int<IntType,IsBig>& operator = (IntType v) {
      _integer_value = v;
      return *this;
    }

    // These functions access the stored value as if it was a byte array.

    // Write byte at offset ix in target memory image.
    // ix is the index of the byte in the in-memory image.
    // byte is the value to write.
    void write_byte(unsigned ix, host_int_1 byte)
      {
	assert (0 <= ix && ix < sizeof(IntType));
	char* value_ptr = reinterpret_cast<char*>(&this->_integer_value);
	if (IsBig != HOST_BIG_ENDIAN) {
	  value_ptr[(sizeof(IntType)-1)-ix] = byte;
	} else {
	  value_ptr[ix] = byte;
	}
      }

    // Read byte at offset ix from the target memory image.
    // ix is the index of the byte in the in-memory image.
    // Returns the value of the byte.
    host_int_1 read_byte(unsigned ix) const
      {
	assert (0 <= ix && ix < sizeof(IntType));
	const char* value_ptr = reinterpret_cast<const char*>(&this->_integer_value);
	if (IsBig != HOST_BIG_ENDIAN) {
	  return value_ptr[(sizeof(IntType)-1)-ix];
	} else {
	  return value_ptr[ix];
	}
      }

  private:
    IntType _integer_value;
  };


// ----------------------------------------------------------------------------


  // Stream any_int using current stream flags
  template <typename IntType, bool IsBig>
  inline std::ostream&
  operator << (std::ostream& o, const any_int<IntType,IsBig>& v)
  {
    host_int_8 value;
    value = v; 
    o << value;
    return o;
  }


  // Destream any_int using current stream flags
  template <typename IntType, bool IsBig>
  inline std::istream&
  operator >> (std::istream& i, any_int<IntType,IsBig>& v)
  {
    host_int_8 value;
    i >> value;
    v = (IntType) value;
    // XXX: range check?
    return i;
  }



// ----------------------------------------------------------------------------


  // A series of big-endian quantities: 1-8 bytes.
  typedef any_int<host_int_1,true> big_int_1;
  typedef any_int<host_int_2,true> big_int_2;
  typedef any_int<host_int_4,true> big_int_4;
  typedef any_int<host_int_8,true> big_int_8;
  

  // A series of little-endian quantities: 1-8 bytes.
  typedef any_int<host_int_1,false> little_int_1;
  typedef any_int<host_int_2,false> little_int_2;
  typedef any_int<host_int_4,false> little_int_4;
  typedef any_int<host_int_8,false> little_int_8;
}

#endif // SIDTYPES_H
