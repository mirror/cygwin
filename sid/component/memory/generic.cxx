// generic.cxx - a class of generic memories.  -*- C++ -*-

// Copyright (C) 1999-2001, 2003, 2006, 2007 Red Hat.
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
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

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
using sidutil::find_sid_data_file;

// ----------------------------------------------------------------------------

generic_memory::generic_memory() throw (bad_alloc):
  imageload_pin (this, & generic_memory::imageload_handler),
  imagestore_pin (this, & generic_memory::imagestore_handler),
  imagemmap_pin (this, & generic_memory::imagemmap_handler),
  imagemsync_pin (this, & generic_memory::imagemsync_handler),
  sched (0),
  change_log (0x60000),
  read_latency (0),
  write_latency (0),
  base_address (0),
  warn_rom_write (false),
  allow_rom_write (false)
{
  this->max_buffer_length = 32UL * 1024UL * 1024UL;
  this->buffer = 0;
  this->buffer_length = 0;
  this->mmapping_p = false;

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
  add_pin ("image-mmap", & this->imagemmap_pin);
  add_attribute ("image-mmap", & this->imagemmap_pin, "pin");
  add_pin ("image-msync", & this->imagemsync_pin);
  add_attribute ("image-msync", & this->imagemsync_pin, "pin");

  add_attribute ("read-latency", & this->read_latency, "setting");
  add_attribute ("write-latency", & this->write_latency, "setting");
  add_attribute ("base-address", & this->base_address, "setting");

  add_attribute ("warn-rom-write-option?", & this->warn_rom_write, "setting");
  add_attribute ("allow-rom-write-option?", & this->allow_rom_write, "setting");

  // Undocumented, dangerous, do not use ...
  add_attribute_ro ("buffer-base-UNSAFE", (host_int_4*) & this->buffer);
  add_attribute_ro ("buffer-length-UNSAFE", & this->buffer_length);

  add_attribute_virtual ("state-snapshot", this,
			 & generic_memory::save_state,
			 & generic_memory::restore_state);

  add_uni_relation ("sim-sched", & sched);
}


generic_memory::~generic_memory ()
{
  assert (this->buffer);
  if (this->mmapping_p)
    munmap (reinterpret_cast<char*>(this->buffer), this->buffer_length);
  else
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
      this->error_pin.drive (0);
      return false;
    }

  if (this->mmapping_p)
    {
      munmap (reinterpret_cast<char*>(this->buffer), this->buffer_length);
      this->mmapping_p = false;
    }
  else
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
      this->error_pin.drive (0);
      return;
    }

  ifstream f (find_sid_data_file(this->image_file_name).c_str(), ios::binary | ios::in);
  if (! f.good())
    {
      cerr << "memory: error opening " << this->image_file_name << ": "
	   << std_error_string() << endl;
      this->error_pin.drive (0);
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
      this->error_pin.drive (0);
      return;
    }

  ofstream f (find_sid_data_file(this->image_file_name).c_str(),
	      ios::binary | ios::out | ios::trunc);
  if (! f.good())
    {
      cerr << "memory: error opening " << this->image_file_name << ": "
	<< std_error_string() << endl;
      this->error_pin.drive (0);
      return;
    }

  // Save whole darned file
  f.write (reinterpret_cast<const char*>(& this->buffer[0]), this->buffer_length);
  // if (! f.good())
  //  cerr << "memory: short write to " << this->image_file_name << endl;
}




void
generic_memory::imagemsync_handler (host_int_4)
{
  assert (this->buffer);
  if (this->mmapping_p)
    {
      int rc = msync (reinterpret_cast<char*>(this->buffer),
		      this->buffer_length, MS_SYNC|MS_INVALIDATE);
      if (rc < 0) 
	cerr << "memory: failed in mmap:" << std_error_string() << endl;
    }
}



void
generic_memory::imagemmap_handler (host_int_4)
{
  assert (this->buffer);

  // Do nothing if file name was empty.
  if (this->image_file_name == "")
    {
      cerr << "memory: no image-file set for image-mmap" << endl;
      this->error_pin.drive (0);
      return;
    }

  int fd = open (find_sid_data_file(this->image_file_name).c_str(), O_RDWR);
  if (fd < 0)
    {
      cerr << "memory: cannot open image-file during image-mmap:" << std_error_string() << endl;
      this->error_pin.drive (0);
      return;
    }

  /* Some kernels will SIGBUS the application if mmap'd file is not large enough.  */ 
  struct stat desc;
  int rc = fstat (fd, & desc);
  if (rc < 0 || desc.st_size < this->buffer_length)
    {
      cerr << "memory: cannot confirm that mmap file is large enough (>= " 
	   << this->buffer_length << " bytes)." << endl;
      this->error_pin.drive (0);
      return;
    }

  char* new_buffer = reinterpret_cast<char*>(mmap (0, this->buffer_length, 
						   PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0));
#ifndef MAP_FAILED
#define MAP_FAILED ((char*)-1)
#endif
  if (new_buffer == 0 || new_buffer == MAP_FAILED)
    {
      cerr << "memory: failed in mmap:" << std_error_string() << endl;
      close (fd);
      this->error_pin.drive (0);
      return;
    }

  if (this->mmapping_p)
    {
      // Unmap previous block first
      munmap (reinterpret_cast<char*>(this->buffer), this->buffer_length);
      this->mmapping_p = false;
    }

  this->buffer = reinterpret_cast<host_int_1*>(new_buffer);
  close (fd);
  this->mmapping_p = true;
}


// Record a change in this memory region, so that it may be restored later.
void
generic_memory::record_update (host_int_4 address, const void *bytes, unsigned width)
{
  // This function is only used during reverse debugging at the moment.
  assert (reversible_p);

  // Make sure we can get the current time
  if (! sched)
    return;
  string tick_attr = sched->attribute_value ("time");
  host_int_4 tick;
  component::status s = parse_attribute (tick_attr, tick);
  if (s != component::ok)
    return;

  // Make sure that the time is not 0.
  if (tick == 0)
    return;

  // Assemble the change log entry
  char change[4 + 8]; // max buffer size
  *(sid::host_int_4 *)change = address;
  memcpy (change + 4, this->buffer + address, width);

  // The change log record contains the current tick, the address and the
  // original data.
  change_log.push (& tick, sizeof (tick));
  change_log.add (change, 4 + width);
  change_log.finish ();
}


// Restore this mrmory region to the state it was at the given time (tick).
void
generic_memory::restore_state_to_time (sid::host_int_4 tick)
{
  // Call up to the base class.
  reversible_component::restore_state_to_time (tick);

  // Undo all updates back to the given time.
  while (! change_log.empty ())
    {
      sid::host_int_4 length;
      const unsigned char *record = (const unsigned char *)change_log.top (length);

      // The time (tick) of the change is the first item in the record.
      // If this record occurred previous to our target time, then we are done.
      sid::host_int_4 new_tick = *(sid::host_int_4*)record;
      if (new_tick < tick)
	break;

      record += sizeof (new_tick);
      length -= sizeof (new_tick);

      // The next item in the record is the address which was changed.
      sid::host_int_4 address = *(sid::host_int_4*)record;
      record += sizeof (address);
      length -= sizeof (address);

      // The remainder of the record contains the original data.
      // Restore the change.
      memcpy (this->buffer + address, record, length);

      // Done with this record.
      change_log.pop ();
    }
}
	
// ----------------------------------------------------------------------------


void
generic_memory::stream_state (ostream& out) const
{
  out << "memory-state" << endl;
  out << string2stream(this->image_file_name) << " "
      << this->imageload_pin << " "
      << this->imagestore_pin << endl;

  out << "read-latency " << read_latency;
  out << "write-latency " << write_latency;

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

  in >> key;
  if (key != "read-latency")
    {
      in.setstate (ios::badbit);
      return;
    }
  in >> read_latency;

  in >> key;
  if (key != "write-latency")
    {
      in.setstate (ios::badbit);
      return;
    }
  in >> write_latency;

  string coding;
  in >> coding;
  if (coding == "uncompressed")
    {
      host_int_4 new_length;
      in >> new_length;
      // Do the attempt_resize() bit even if new_length == size, 
      // since we want to clear/reset the memory.
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

