// sidattrutil.h - Classes to manage lists of component attributes and
// mappings between application objects and their string
// representations.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2003, 2005, 2006, 2007 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDATTRUTIL_H
#define SIDATTRUTIL_H

#include <sidconfig.h>
#include <sidcomputil.h>
#include <sidpinutil.h>
#include "sidtypes.h"

#include <string>
#include <typeinfo>
#include <map>

#include <cctype>
// XXX: kludge for compatibility both with old & new libstdc++
#if STD_CCTYPE
#define STDCTYPE(func) std::func
#else
#define STDCTYPE(func) func
#endif


#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

// <ext/hash_map>? <hash_map>?  std::?  __gnu_cxx::?  Too much hassle.
#undef HAVE_HASHING

#include <iostream>
#if HAVE_SSTREAM
#include <sstream>
#elif HAVE_STRSTREAM_H
#include <strstream.h>
#else
#error "need <sstream> or <strstream.h>!"
#endif

#include <cassert>
#include <sidmiscutil.h>


namespace sidutil
{

  // Make a string from an object by the default output-streaming operator.
  template <typename Type>
  static std::string
  make_attribute (const Type& value)
  {
#if HAVE_SSTREAM
    std::ostringstream stream;
    stream << value;
    return stream.str ();
#elif HAVE_STRSTREAM_H
    ostrstream stream;
    stream << value;
    std::string result (stream.str (), stream.pcount ());
    stream.freeze (0);
    return result;
#else
#error "need <sstream> or <strstream.h>!"
#endif
  }


  // Attempt to make object from a string using the default input-streaming operator.
  template <typename Type>
  static sid::component::status
  parse_attribute (const std::string& str, Type& value)
  {
#if HAVE_SSTREAM
    std::istringstream stream (str);
    stream >> value;
#elif HAVE_STRSTREAM_H
    istrstream stream (str.data (), str.length ());
    stream >> value;
#else
#error "need <sstream> or <strstream.h>!"
#endif

    // Ensure stream is still good, and that operator>> has consumed entire string.
    if (! stream.bad () && (stream.rdbuf ()->in_avail () == 0))
      return sid::component::ok;
    else
      return sid::component::bad_value;
  }



// ---------------------------------------------------------------------------

  // Specific attribute make/parse routines for common types

  // Specialization for strings
static std::string
make_attribute (const std::string& value)
{
  return value;
}

static sid::component::status
parse_attribute (const std::string& str, std::string& value)
{
  value = str;
  return sid::component::ok;
}


  // Specialization for bools
static std::string
make_attribute (const bool& value)
{
  if (value)
    return "yes";
  else
    return "no";
}

static sid::component::status
parse_attribute (const std::string& str, bool& value)
{
  if (str == "yes" || str == "y" ||
      str == "true" || str == "t" ||
      str == "on" || 
      str == "1")
    {
      value = true;
      return sid::component::ok;
    }
  else if (str == "no" || str == "n" ||
	   str == "false" || str == "f" ||
	   str == "off" ||
	   str == "0")
    {
      value = false;
      return sid::component::ok;
    }

  return sid::component::bad_value;
}


  // Specialization for host_int_X

template <typename Value>
static std::string
make_numeric_attribute (const Value& value, std::ios::fmtflags ios_flags = std::ios::dec)
{
#if HAVE_SSTREAM
    std::ostringstream stream;
    stream.flags (ios_flags);
    stream << value;
    return stream.str ();
#elif HAVE_STRSTREAM_H
    ostrstream stream;
    stream.flags (ios_flags);
    stream << value;
    std::string result (stream.str (), stream.pcount ());
    stream.freeze (0);
    return result;
#else
#error "need <sstream> or <strstream.h>!"
#endif
}


static std::string
make_attribute (const sid::host_int_8& value)
{
  return sidutil::make_numeric_attribute (value);
}

static std::string
make_attribute (const sid::host_int_4& value)
{
  return sidutil::make_numeric_attribute (value);
}

static std::string
make_attribute (const sid::host_int_2& value)
{
  return sidutil::make_numeric_attribute (value);
}

static std::string
make_attribute (const sid::host_int_1& value)
{
  // widen to avoid representation as char
  return sidutil::make_numeric_attribute (sid::host_int_2(value));
}

static std::string
make_attribute (const sid::signed_host_int_8& value)
{
  return sidutil::make_numeric_attribute (value);
}

static std::string
make_attribute (const sid::signed_host_int_4& value)
{
  return sidutil::make_numeric_attribute (value);
}

static std::string
make_attribute (const sid::signed_host_int_2& value)
{
  return sidutil::make_numeric_attribute (value);
}

static std::string
make_attribute (const sid::signed_host_int_1& value)
{
  // widen to avoid representation as char
  return sidutil::make_numeric_attribute (sid::signed_host_int_2(value));
}


template <typename unsignedValue>
static sid::component::status
parse_unsigned_numeric_attribute (const std::string& str, unsignedValue& value)
{
  // Algorithm based on newlib's strtoul, from BSD.

  unsignedValue base = 10;
  unsigned parseoffset = 0;
  bool negative = false;

  if (str.length () == 0)
    return sid::component::bad_value;

  if (str.length () > parseoffset+1 && str.substr (parseoffset,1) == "-")
    {
      negative = true;
      parseoffset ++;
    }

  // NB: check longest prefixes first!
  if (str.length () > parseoffset+2 && (str.substr (parseoffset,2) == "0x" || 
					str.substr (parseoffset,2) == "0X"))
    {
      base = 16;
      parseoffset += 2;
    }
  else if (str.length () > parseoffset+2 && (str.substr (parseoffset,2) == "0b" ||
					     str.substr (parseoffset,2) == "0B"))
    {
      base = 2;
      parseoffset += 2;
    }
  else if (str.length () > parseoffset+1 && str.substr (parseoffset,1) == "0")
    {
      base = 8;
      parseoffset += 1;
    }

  //cout << "str=" << str << " base=" << base << " negative=" << negative;

  unsignedValue acc = 0;
  unsignedValue max = (unsignedValue) -1;
  unsignedValue cutoff = max / base;
  unsignedValue cutlim = max % base;
  for (unsigned i = parseoffset; i < str.length (); i++)
    {
      unsigned char c = str[i];
      // cout << "c=" << (int)c << " acc=" << acc << endl;
      if (STDCTYPE(isdigit) (c))
	c -= '0';
      else if (STDCTYPE(isalpha) (c))
	c -= STDCTYPE(isupper) (c) ? 'A' - 10 : 'a' - 10;
      else
	return sid::component::bad_value;

      // limit accumulation
      if (c >= base)
	return sid::component::bad_value;
      else if (acc > cutoff || (acc == cutoff && c > cutlim))
	return sid::component::bad_value;	

      acc *= base;
      acc += c;
    }

  value = negative ? -acc : acc;
  // cout << " value=" << value << endl;

  return sid::component::ok;
}


static sid::component::status
parse_attribute (const std::string& str, sid::host_int_8& value)
{
  return sidutil::parse_unsigned_numeric_attribute (str, value);
}

static sid::component::status
parse_attribute (const std::string& str, sid::host_int_4& value)
{
  return sidutil::parse_unsigned_numeric_attribute (str, value);
}

static sid::component::status
parse_attribute (const std::string& str, sid::host_int_2& value)
{
  return sidutil::parse_unsigned_numeric_attribute (str, value);
}

static sid::component::status
parse_attribute (const std::string& str, sid::host_int_1& value)
{
  return sidutil::parse_unsigned_numeric_attribute (str, value);
}

// Signed versions.
// ??? The unsigned versions don't mark negative values as bad so
// for now the signed versions don't mark big unsigned values as bad.

static sid::component::status
parse_attribute (const std::string& str, sid::signed_host_int_8& value)
{
  sid::host_int_8 uvalue;
  sid::component::status s = sidutil::parse_unsigned_numeric_attribute (str, uvalue);
  if (s == sid::component::ok)
    value = uvalue;
  return s;
}

static sid::component::status
parse_attribute (const std::string& str, sid::signed_host_int_4& value)
{
  sid::host_int_4 uvalue;
  sid::component::status s = sidutil::parse_unsigned_numeric_attribute (str, uvalue);
  if (s == sid::component::ok)
    value = uvalue;
  return s;
}

static sid::component::status
parse_attribute (const std::string& str, sid::signed_host_int_2& value)
{
  sid::host_int_2 uvalue;
  sid::component::status s = sidutil::parse_unsigned_numeric_attribute (str, uvalue);
  if (s == sid::component::ok)
    value = uvalue;
  return s;
}

static sid::component::status
parse_attribute (const std::string& str, sid::signed_host_int_1& value)
{
  sid::host_int_1 uvalue;
  sid::component::status s = sidutil::parse_unsigned_numeric_attribute (str, uvalue);
  if (s == sid::component::ok)
    value = uvalue;
  return s;
}



// Specialization for {big,little}_int types

template <typename IntType, bool IsBig>
static sid::component::status
parse_attribute (const std::string& str, sid::any_int<IntType,IsBig>& value)
{
  typename sid::any_int<IntType,IsBig>::value_type v;
  sid::component::status s = parse_attribute (str, v);
  if (s == sid::component::ok)
    value = v;
  return s;
}

template <typename IntType, bool IsBig>
static std::string
make_attribute (const sid::any_int<IntType,IsBig>& value)
{
  typename sid::any_int<IntType,IsBig>::value_type v = value.integer_value ();
  return make_attribute (v);
}




// ---------------------------------------------------------------------------


  // Abstract attribute-coder class provides interface to a pair of
  // string->object and object->string conversion functions.
  class attribute_coder_base
  {
  public:
    virtual std::string make_attribute() const = 0;
    virtual sid::component::status parse_attribute(const std::string& str) = 0;
    virtual ~attribute_coder_base() {}
  };


  // This kind of attribute coder calls a pair of unparameterized
  // member functions for making/parsing attribute strings.
  template <class Class>
  class attribute_coder_virtual: public attribute_coder_base
  {
  public:
    typedef std::string (Class::*getter_f) ();
    typedef sid::component::status (Class::*setter_f) (const std::string&);    

  private:
    Class* receiver;
    getter_f getter;
    setter_f setter;

  public:
    attribute_coder_virtual (Class* r, getter_f g, setter_f s):
      receiver (r), getter (g), setter (s) {}

    attribute_coder_virtual (Class* r, setter_f s, getter_f g):
      receiver (r), getter (g), setter (s) {}

    std::string make_attribute () const
      { return (receiver->*getter) (); }

    sid::component::status
    parse_attribute (const std::string& str)
      { return (receiver->*setter) (str); }

    ~attribute_coder_virtual() { }
  };


  // This kind of attribute coder redirects the calls to another
  // object's named attribute.  This may be used to create
  // aliased attributes.
  class attribute_coder_alias: public attribute_coder_base
  {
  private:
    sid::component* receiver;
    std::string name;

  public:
    attribute_coder_alias (sid::component* r, const std::string& n):
      receiver (r), name(n) {}

    std::string make_attribute () const
      { return receiver->attribute_value (name); }

    sid::component::status
    parse_attribute (const std::string& str)
      { return receiver->set_attribute_value (name, str); }

    ~attribute_coder_alias() { }
  };



  // This kind of attribute coder calls a pair of member functions for 
  // making/parsing attribute strings.  They are parameterized with a
  // value of some type.
  template <class Class, typename Parameter>
  class attribute_coder_virtual_parameterized: public attribute_coder_base
  {
  public:
    typedef std::string (Class::*getter_f) (Parameter);
    typedef sid::component::status (Class::*setter_f)
      (Parameter, const std::string&);    

  private:
    Class* receiver;
    Parameter parameter;
    getter_f getter;
    setter_f setter;

  public:
    attribute_coder_virtual_parameterized (Class* r, getter_f g, setter_f s,
					 Parameter p)
      :receiver (r), getter (g), setter (s), parameter (p) { }
      
    attribute_coder_virtual_parameterized (Class* r, setter_f s, getter_f g,
					 Parameter p)
      :receiver (r), getter (g), setter (s), parameter (p) { }
      
    std::string
    make_attribute () const
      {
	return (receiver->*getter) (parameter);
      }

    sid::component::status
    parse_attribute (const std::string& str)
      {
	return (receiver->*setter) (parameter, str);
      }

   ~attribute_coder_virtual_parameterized() { }

  };


  // This attribute coder stores a pointer to a value.  It forwards
  // make_attribute and parse_attribute to the pointed-to value for
  // mapping to/from strings.
  template <typename Value>
  class attribute_coder: public attribute_coder_base
  {
    Value* ptr;
  public:
    attribute_coder (Value* p): ptr (p) {}

    std::string make_attribute () const
      {
	return sidutil::make_attribute (*ptr);
      }

    sid::component::status parse_attribute (const std::string& str)
      {
	return sidutil::parse_attribute (str, *ptr);
      }

    ~attribute_coder() { }
  };


  // This attribute coder stores a pointer to a value.  It forwards
  // make_attribute to the pointed-to value for mapping from
  // strings. It intercepts parse_attribute to prevent a value change.
  template <typename Value>
  class attribute_coder_ro: public attribute_coder<Value>
  {
  public:
    attribute_coder_ro (Value* p): attribute_coder<Value> (p) {}

    // Override to disable writing.
    sid::component::status
    parse_attribute (const std::string& str)
      {
	return sid::component::bad_value;
      }
    
    ~attribute_coder_ro() { }
  };


  // This attribute coder stores a literal const value.  It forwards
  // make_attribute to the value for mapping from strings.  It
  // intercepts parse_attribute to prevent a value change.
  template <typename Value>
  class attribute_coder_ro_value: public attribute_coder_base
  {
    const Value value;

  public:
    attribute_coder_ro_value (const Value& v): value (v) {}

    std::string make_attribute () const
      {
	return sidutil::make_attribute (value);
      }

    sid::component::status parse_attribute (const std::string& str)
      {
	return sid::component::bad_value; 
      }
    
    ~attribute_coder_ro_value() { }
 
  };


  // This attribute coder is like basic attribute_coder<>, but it
  // calls a notification function after any parse_attribute attempt.
  template <typename Value, class Class>
  class attribute_coder_notify: public attribute_coder<Value>
  {
    typedef void (Class::*Callback) ();
    Class* receiver;
    Callback pmf;

  public:
    attribute_coder_notify (Value* p, Class* rec, Callback f):
      attribute_coder<Value> (p), receiver (rec), pmf (f) {}

    sid::component::status
    parse_attribute (const std::string& str)
      {
	sid::component::status stat = 
	  attribute_coder<Value>::parse_attribute (str);
	// XXX: make sense to call pmf if stat != ok?
	// XXX: could even endavour to restore previous value if != ok
	 (receiver->*pmf) ();
	return stat;
      }
  };


  // This attribute coder class performs its work by reading/writing
  // a fixed address via a bus.
  template <class DataType>
  class attribute_coder_bus_rw: public attribute_coder_base
  {
    mutable sid::bus* target;
    sid::host_int_4 address;

  public:
    attribute_coder_bus_rw (sid::bus* t, sid::host_int_4 a)
			  : target (t), address (a) 
      {
	assert (t != 0);
      }

    std::string make_attribute () const
      { 
	DataType value;
	sid::bus::status s2 = this->target->read (address, value);
	if (s2 == sid::bus::ok) return sidutil::make_attribute (value);
	else return "";
      }

    sid::component::status parse_attribute (const std::string& str)
      {
	DataType value;
	sid::component::status s1 = sidutil::parse_attribute (str, value);
	if (s1 != sid::component::ok) return s1;
	sid::bus::status s2 = this->target->write (address, value);
	if (s2 == sid::bus::ok) return sid::component::ok;
	else return sid::component::bad_value;
      }
    
    ~attribute_coder_bus_rw() { }
  };


  // This is a read-only variety of the same thing.
  template <class DataType>
  class attribute_coder_bus_ro: public attribute_coder_bus_rw<DataType>
  {
  public:
    attribute_coder_bus_ro (sid::bus* t, sid::host_int_4 a): 
      attribute_coder_bus_rw<DataType> (t, a) {}

    sid::component::status parse_attribute (const std::string& str)
      {
	return sid::component::bad_value;
      }
  };


  // This is a write-only variety of the same thing.  It returns the
  // last successfully written value on reads.
  template <class DataType>
  class attribute_coder_bus_wo: public attribute_coder_bus_rw<DataType>
  {
  public:
    attribute_coder_bus_wo (sid::bus* t, sid::host_int_4 a): 
      attribute_coder_bus_rw<DataType> (t, a),
      last_written_attribute ("no value")
      {}

    std::string make_attribute () const
      { 
	return this->last_written_attribute;
      }

    sid::component::status parse_attribute (const std::string& str)
      {
	sid::component::status s = attribute_coder_bus_rw<DataType>::parse_attribute (str);
	if (s == sid::component::ok)
	  this->last_written_attribute = str;
	return s;
      }

   ~attribute_coder_bus_wo() { }

  private:
    std::string last_written_attribute;
  };


#ifdef HAVE_HASHING
  struct hash_string
  {
    size_t
    operator () (const std::string& s) const
      {
	// XXX: improve? 
	return std::hash<const char*> () (s.c_str ()); 
      }
  };
#endif


  // A mix-in for classes with largely static attribute lists.
  class fixed_attribute_map_component: public virtual sid::component
  {
  private:
    // use hash table for this, if available
#ifdef HAVE_HASHING
    typedef std::hash_map<std::string,attribute_coder_base*,hash_string> attribute_map_t;
#else
    typedef std::map<std::string,attribute_coder_base*> attribute_map_t;
#endif
    mutable attribute_map_t attribute_map;

  private:
    // map attribute name <-> category name

    // Each matching entry in these parallel lists represents one
    // attribute name <-> category name relationship.
    std::vector<std::string> category_pair_attribute;
    std::vector<std::string> category_pair_category;

    // XXX: This used to be a pair of string->set<string> maps, but
    // the compiler working set blew up.
    
  protected:
    ~fixed_attribute_map_component () { /* XXX: delete coder objects */ }

    // Add or remove an attribute <-> category association.  The named
    // attribute must already exist.
    void
    categorize (const std::string& attr, const std::string& category)
      {
	assert (this->attribute_map.find (attr) != this->attribute_map.end ());

	// Add a matching pair into the category_pair vectors.
	this->category_pair_attribute.push_back (attr);
	this->category_pair_category.push_back (category);

	// size of both vectors should be same 
	assert (this->category_pair_attribute.size () == 
					this->category_pair_category.size ());
      }


    // Remove all entry pairs from the category_pair vectors where the
    // attribute name matches the argument attr.
    void
    uncategorize (const std::string& attr)
      {
	assert (this->attribute_map.find (attr) != this->attribute_map.end ());

	// Remove all entry pairs from the category_pair vectors where
	// the attribute name matches.
	unsigned i = 0;

	while (i < this->category_pair_attribute.size ())
	  {
	    if (this->category_pair_attribute[i] == attr)
	      {
		this->category_pair_attribute.erase (
				this->category_pair_attribute.begin () + i);

		this->category_pair_category.erase (
				this->category_pair_category.begin () + i );
	      }
	    else
	      i++;
	  }
	
	assert (this->category_pair_attribute.size () == 
		this->category_pair_category.size ());
      }


    // Low level add-attribute: supply associated coder instance
    // XXX: candidates for moving out-of-line
    void
    add_attribute_coder (const std::string& name,
			attribute_coder_base* coder_ptr)
      {
	assert (this->attribute_map.find (name) == this->attribute_map.end ());
	this->attribute_map[name] = coder_ptr;
      }
    
    
    void
    add_attribute_coder (const std::string& name,
			attribute_coder_base* coder_ptr, 
			const std::string& category)
      {
	this->add_attribute_coder (name, coder_ptr);
	this->categorize (name, category);
      }

    // Add basic attribute; use streaming conversions
    template <typename Value>
    void
    add_attribute (const std::string& name, Value* ptr)
      { 
	this->add_attribute_coder (name, new attribute_coder<Value> (ptr)); 
      }

    
    template <typename Value>
    void
    add_attribute (const std::string& name, Value* ptr, 
		  const std::string& category)
      { 
	this->add_attribute (name, ptr);
	this->categorize (name, category);
      }
    
    // Add read-only attribute
    template <typename Value>
    void
    add_attribute_ro (const std::string& name, Value* str_ptr)
      {
	this->add_attribute_coder (name,
				  new attribute_coder_ro<Value> (str_ptr));
      }
    
    template <typename Value>
    void
    add_attribute_ro (const std::string& name, Value* str_ptr, 
		     const std::string& category)
      {
	this->add_attribute_ro (name, str_ptr);
	this->categorize (name, category);
      }
    
    
    // Add read-only value attribute
    template <typename Value>
    void
    add_attribute_ro_value (const std::string& name, const Value& v)
      {
	this->add_attribute_coder (name,
				  new attribute_coder_ro_value<Value> (v));
      }
    
    
    template <typename Value>
    void
    add_attribute_ro_value (const std::string& name, const Value& v,
			   const std::string& category)
      {
	this->add_attribute_ro_value (name, v);
	this->categorize (name, category);
      }

    // Add an attribute alias
    void
    add_attribute_alias (const std::string& aka, const std::string& name)
      {
	this->add_attribute_coder (aka,
				   new attribute_coder_alias (this, name));
      }

    void
    add_attribute_alias (const std::string& aka, const std::string& name, 
			 const std::string& category)
      {
	this->add_attribute_alias (aka, name);
	this->categorize (name, category);
      }

    
    // Add a r/w attribute.  After a write, call given function.
    template <typename Value, class Class>
    void
    add_attribute_notify (const std::string& name, Value* str_ptr, 
			 Class* receiver,
			 void (Class::*pmf) ())
      {
	this->add_attribute_coder (name, 
				  new attribute_coder_notify<Value,Class>
				  (str_ptr, receiver, pmf));
      }
    
    template <typename Value, class Class>
    void
    add_attribute_notify (const std::string& name, Value* str_ptr, 
			 Class* receiver,
			 void (Class::*pmf) (),
			 const std::string& category)
      {
	this->add_attribute_notify (name, str_ptr, receiver, pmf);
	this->categorize (name, category);
      }
    
    
    // Add a r/w attribute.  Use given functions for getting/setting values.
    template <class Class, typename Getter, typename Setter>
    void
    add_attribute_virtual (const std::string& name,
			  Class* receiver,
			  Getter getter,
			  Setter setter)
      {
	this->add_attribute_coder (name,
				  new attribute_coder_virtual<Class> (receiver,
								      getter, 
								      setter));
      }
    
    template <class Class, typename Getter, typename Setter>
    void
    add_attribute_virtual (const std::string& name,
			  Class* receiver,
			  Getter getter,
			  Setter setter,
			  const std::string& category)
      {
	this->add_attribute_virtual (name, receiver, getter, setter);
	this->categorize (name, category);
      }

    // Add a parameterized r/w attribute.  Use given functions for getting/setting values.
    template <class Class, typename Getter, typename Setter, typename Parameter>
    void
    add_attribute_virtual_parameterized (const std::string& name,
					 Parameter param,
					 Class* receiver,
					 Getter getter,
					 Setter setter)
      {
	this->add_attribute_coder (name,
				   new attribute_coder_virtual_parameterized<Class,Parameter>
				   (receiver,
				    getter, 
				    setter,
				    param));
      }


    template <class Class, typename Getter, typename Setter, typename Parameter>
    void
    add_attribute_virtual_parameterized (const std::string& name,
					 Parameter param,
					 Class* receiver,
					 Getter getter,
					 Setter setter,
					 const std::string& category)
      {
	this->add_attribute_virtual_parameterized (name,
						   param,
						   receiver,
						   getter, 
						   setter);
	this->categorize (name, category);
      }



    // Removes attribute name from component.
    void
    remove_attribute (const std::string& name)
      {
	assert (this->attribute_map.find (name) != this->attribute_map.end ());
	this->uncategorize (name);
	this->attribute_map.erase (name);
	// XXX: delete coder?
      }
    
    
  public:
    // Returns vector containing names of all component's attributes.  
    std::vector<std::string>
    attribute_names () throw()
      {
	std::vector<std::string> names;
	for (attribute_map_t::const_iterator it = 
		               this->attribute_map.begin();
	     it != this->attribute_map.end();
	     it++)
	   {
	     names.push_back ((*it).first);
	   }
	return names;
      }
    
    // Method returns the names of a component's attribute in a given
    // category.
    std::vector<std::string>
    attribute_names (const std::string& category) throw()
      {
	 std::vector<std::string> attrs;
	 for (unsigned i= 0; i< this->category_pair_category.size(); i++)
	    {
	      if (this->category_pair_category[i] == category)
	        attrs.push_back (this->category_pair_attribute[i]);
	    }
	 return attrs;
      }
    
    // Method returns attribute value corresponding to attribute name
    // passed as argument. Method returns value in std::string form
    // using make_atribute method.
    std::string
    attribute_value (const std::string& name) throw()
      {
	attribute_map_t::iterator it = this->attribute_map.find(name);
	if (it == this->attribute_map.end())
	  return "";
	else
	  return ((*it).second)->make_attribute ();
      }
    
    
    // Method sets attribute value corresponding to attribute name (arg. 1).
    // The value of attribute is set by parsing argument value using
    // parse_attribute method. Method returns ok if value is set.
    component::status
    set_attribute_value (const std::string& name,
			const std::string& value) throw()
      {
	    attribute_map_t::iterator it = this->attribute_map.find (name);
	    if (it == this->attribute_map.end ())
	      return component::not_found;
	    else
	      return ((*it).second)->parse_attribute (value);
      }
  };

  // A configurable_component maintains a relationship with a
  // sid-control-dynamic-configurator component and reconfigures itself
  // when its configure! attribute is set.
  class configurable_component:
    public virtual fixed_attribute_map_component
  {
  public:
    configurable_component ()
      {
	add_attribute_virtual ("configure!", this,
			       & configurable_component::dynamic_config,
			       & configurable_component::nothing);
      }
    ~configurable_component() {}

    // Dynamic reconfiguration support
  private:
    std::string nothing() { return ""; }
  protected:
    virtual component::status
    dynamic_config(const std::string& spec)
      {
	// Call the configure method to handle each configuration item.
	std::vector<std::string> parts = sidutil::tokenize (spec, ":");
	unsigned size = parts.size ();
	for (unsigned i = 0; i < size; ++i)
	  configure (parts[i]);
	return component::ok;
      }

    virtual void configure (const std::string &config) {}
  };

  // A mix-in for classes with user logging.
  class fixed_attribute_map_with_logging_component
  : public virtual fixed_attribute_map_component,
    public virtual fixed_pin_map_component,
    public virtual configurable_component
  {
  protected:
    fixed_attribute_map_with_logging_component () :
      ulog_level (0),
      ulog_mode ("less"),
      ulog_out_pin (),
      buffer_output (false)
      {
	add_attribute ("buffer-output", &buffer_output, "setting");
	add_attribute ("ulog-level", &ulog_level, "setting");
	add_attribute ("ulog-mode",  &ulog_mode,  "setting");
	add_pin ("ulog-out", & ulog_out_pin);
	ulog_logger =  new logger (& ulog_out_pin, buffer_output, ulog_level, ulog_mode);
      }
    ~fixed_attribute_map_with_logging_component ()
      {
	// Output any saved messages.
	ulog_logger->output_saved_messages ();
      }

    void log (sid::host_int_4 level, const char *fmt, ...)
      {
	va_list ap;
	va_start (ap, fmt);
	// In case values changed
	ulog_logger->set_attributes (buffer_output, ulog_level, ulog_mode);
	ulog_logger->log (level, fmt, ap);
	va_end (ap);
      }

  protected:
    bool check_level (sid::host_int_4 level) const
      {
	return ulog_logger->check_level (level);
      }
    sid::host_int_4 ulog_level;
    std::string ulog_mode;
    sidutil::output_pin ulog_out_pin;
    bool buffer_output;
    sidutil::logger *ulog_logger;

protected:
    // Dynamic configuration support
    virtual void configure (const string &config)
      {
	// Call up to the base class
	configurable_component::configure (config);

	// Handle items specific to this component
	if (config.size () < 11)
	  return;
	if (config.substr (0, 10) == "ulog-mode=")
	  {
	    ulog_mode = config.substr (10);
	    ulog_logger->set_attributes (buffer_output, ulog_level, ulog_mode);
	    return;
	  }
	if (config.size () < 12)
	  return;
	if (config.substr (0, 11) == "ulog-level=")
	  {
	    sid::host_int_4 level;
	    sid::component::status s = sidutil::parse_attribute (config.substr (11), level);
	    if (s == sid::component::ok)
	      ulog_level = level;
	    ulog_logger->set_attributes (buffer_output, ulog_level, ulog_mode);
	    return;
	  }
      }
  };


  // A mix-in for components which need to save and restore state
  // at given time indices.
  class reversible_component :
    public virtual fixed_pin_map_component,
    public virtual fixed_attribute_map_component
  {
  public:
    reversible_component () :
      reversible_p (false),
      restore_to_time_pin (this, & reversible_component::restore_state_to_time)
      {
	add_pin ("restore-to-time!", & this->restore_to_time_pin);
	add_attribute ("reversible?", & reversible_p, "setting");
      }

    ~reversible_component () {}

  protected:
    bool reversible_p;

    virtual void restore_state_to_time (sid::host_int_4) {}
    callback_pin<reversible_component> restore_to_time_pin;
  };
}

#endif // SIDATTRUTIL_H
