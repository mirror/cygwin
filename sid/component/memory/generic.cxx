// generic.cxx - a class of generic memories.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "generic.h"

#include <sidpinattrutil.h>
#include <sidattrutil.h>
#include <sidmiscutil.h>

#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <unistd.h>
#include <fstream>

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::nothrow;
using std::ofstream;
using std::ifstream;

using sid::component;
using sid::host_int_1;
using sid::host_int_4;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::little_int_8;
using sid::big_int_1;
using sid::big_int_2;
using sid::big_int_4;
using sid::big_int_8;

using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::string2stream;
using sidutil::stream2string;

// ----------------------------------------------------------------------------

generic_memory::generic_memory() throw (bad_alloc):
  imageload_pin (this, & generic_memory::imageload_handler),
  imagestore_pin (this, & generic_memory::imagestore_handler)
{
  this->max_buffer_length = 32UL * 1024UL * 1024UL;
  this->buffer = 0;
  this->buffer_length = 0;
  bool ok = this->attempt_resize (1024);
  if (! ok) throw bad_alloc ();
  
  add_attribute_virtual ("size", this,
			 & generic_memory::get_size_attr,
			 & generic_memory::set_size_attr, "setting");
  add_attribute_ro ("size-max", & this->max_buffer_length, "setting");

  add_attribute ("image-file", & this->image_file_name, "setting");
  add_pin ("image-load", & this->imageload_pin);
  add_attribute ("image-load", & this->imageload_pin, "pin");
  add_pin ("image-store", & this->imagestore_pin);
  add_attribute ("image-store", & this->imagestore_pin, "pin");

  add_attribute_virtual ("state-snapshot", this,
			 & generic_memory::save_state,
			 & generic_memory::restore_state);
}


generic_memory::~generic_memory ()
{
  assert (this->buffer);
  delete [] this->buffer;
}


bool
generic_memory::attempt_resize (host_int_4 new_length) throw()
{
  if (new_length > max_buffer_length)
    return false;
  
  host_int_1* new_buffer = new (nothrow) host_int_1[new_length];
  if (new_buffer == 0)
    {
      cerr << "memory: error allocating memory buffer: " << std_error_string() << endl;
      return false;
    }

  if (this->buffer)
    delete [] this->buffer;
  this->buffer = new_buffer;
  this->buffer_length = new_length;
  memset(this->buffer, 0, this->buffer_length);

  return true;
}


void
generic_memory::imageload_handler (host_int_4)
{
  assert(this->buffer != 0);

  // Do nothing if file name was empty.
  if (this->image_file_name == "")
    {
      cerr << "memory: no image-file set for image-load" << endl;
      return;
    }

  ifstream f (this->image_file_name.c_str(), ios::binary | ios::in);
  if (! f.good())
    {
      cerr << "memory: error opening " << this->image_file_name << ": "
	   << std_error_string() << endl;
      return;
    }

  // Load whole darned file
  memset (& this->buffer[0], 0, this->buffer_length);
  f.read (reinterpret_cast<char*>(& this->buffer[0]), this->buffer_length);
}



void
generic_memory::imagestore_handler (host_int_4)
{
  assert(this->buffer != 0);

  // Do nothing if file name was empty.
  if (this->image_file_name == "")
    {
      cerr << "memory: no image-file set for image-store" << endl;
      return;
    }

  ofstream f (this->image_file_name.c_str(), ios::binary | ios::out | ios::trunc);
  if (! f.good())
    {
      cerr << "memory: error opening " << this->image_file_name << ": "
	<< std_error_string() << endl;
      return;
    }

  // Save whole darned file
  f.write (reinterpret_cast<const char*>(& this->buffer[0]), this->buffer_length);
  // if (! f.good())
  //  cerr << "memory: short write to " << this->image_file_name << endl;
}





// ----------------------------------------------------------------------------


void
generic_memory::stream_state (ostream& out) const
{
  out << "memory-state" << endl;
  out << string2stream(this->image_file_name) << " "
      << this->imageload_pin << " "
      << this->imagestore_pin << endl;
  
  if (this->buffer_length <= 4096) // encode small memories literally
    {
      out << "uncompressed "
	  << this->buffer_length;
      
      // formatted-to-nonformatted section separator
      out << ":";
      
      for(host_int_4 i = 0; i < this->buffer_length; i++)
	{
	  out.put(this->buffer[i]);
	}
    }
  else // encode large memories using puny RLE
    {
      out << "rle "
	  << this->buffer_length;

      // formatted-to-nonformatted section separator
      out << ":";
     
      // encoding: form 1: [repcount]  [byte]
      //           form 2: [norepcount][byte0]....[byteN]
      // decode as form 1 if [repcount] >= 128; form 2 if [norepcount] < 128.

      host_int_4 address = 0;
      while(address < this->buffer_length)
	{
	  host_int_1 b = this->buffer[address];

	  host_int_1 repcount = 0;
	  while ((repcount < 255) && (address+repcount < this->buffer_length))
	    {
	      if (this->buffer[address+repcount] != b)
		break;
	      repcount++;
	    }

	  if (repcount >= 128)
	    {
	      out.put (repcount);
	      out.put (b);
	      address += repcount;
	    }
	  else
	    {
	      // XXX: it would be nice to find the best size for uncompressed
	      // strings.  Instead, hard-code 64 here. (The decoder will work
	      // either way.)
	      unsigned char nonrepcount = 64;

	      // clip it to remaining buffer space!
	      host_int_4 max_nonrepcount = this->buffer_length - address;
	      if (nonrepcount > max_nonrepcount)
		{
		  nonrepcount = (host_int_1) max_nonrepcount;
		}

	      out.put (nonrepcount);
	      for (host_int_1 n = 0; n < nonrepcount; n++)
		out.put (this->buffer[address+n]);
	      address += nonrepcount;
	    }
	}
    }
}


void
generic_memory::destream_state (istream& in)
{
  string key;
  in >> key;
  if (key != "memory-state")
    {
      in.setstate (ios::badbit);
      return;
    }
  in >> stream2string(this->image_file_name) >> this->imageload_pin >> this->imagestore_pin;

  string coding;
  in >> coding;
  if (coding == "uncompressed")
    {
      host_int_4 new_length;
      in >> new_length;
      bool ok = this->attempt_resize(new_length);
      if (! ok)
	{
	  in.setstate(ios::badbit);
	  return;
	}

      char sep;
      in.get(sep);
      if (sep != ':')
	{
	  in.setstate(ios::badbit);
	  return;
	}

      assert (this->buffer != 0);
      for(unsigned i = 0; i < this->buffer_length; i++)
	{
	  char value;
	  in.get (value);
	  this->buffer[i] = value;
	}
    }
  else if (coding == "rle")
    {
      host_int_4 new_length;
      in >> new_length;
      bool ok = this->attempt_resize(new_length);
      if (! ok)
	{
	  in.setstate(ios::badbit);
	  return;
	}

      char sep;
      in.get(sep);
      if (sep != ':')
	{
	  in.setstate(ios::badbit);
	  return;
	}

      // encoding as above.

      host_int_4 address = 0;
      while (address < this->buffer_length)
	{
	  char c;
	  in.get (c);
	  unsigned count = (unsigned char) c;

	  //cout << "count=" << (int) count << " addr=" << (int) address << endl;

	  if (address + count > this->buffer_length) // detect overflow
	    {
	      in.setstate (ios::badbit);
	      return;
	    }

	  if (count >= 128)
	    {
	      // compressed	      
	      char b;
	      in.get (b);
	      for (unsigned i=0; i<count; i++)
		this->buffer[address+i] = b;
	    }
	  else 
	    {
	      // uncompressed
	      in.read (reinterpret_cast<char*>(& this->buffer[address]), count);
	    }

	  address += count;
	}
    }
  else
    {
      in.setstate(ios::badbit);
    }
}


// ----------------------------------------------------------------------------

string
generic_memory::get_size_attr ()
{
  return make_attribute (this->buffer_length);
}


component::status
generic_memory::set_size_attr (const string& s)
{
  host_int_4 new_size;
  component::status st = parse_attribute(s, new_size);
  if (st == component::ok)
    {
      bool ok = this->attempt_resize (new_size);
      if (! ok)
	return component::bad_value;
    }
  return st;
}

ostream& 
operator << (ostream& out, const generic_memory& it)
{
  it.stream_state(out);
  return out;
}

istream& 
operator >> (istream& in, generic_memory& it)
{
  it.destream_state(in);
  return in;
}

