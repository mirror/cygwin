// sid-vga-wrapper.cc - SID import of the bochs vga component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-vga-wrapper.h"

#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <new>
#include <new>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>

using std::cerr;
using std::nothrow;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
#include <sys/stat.h>

using std::cerr;
using std::nothrow;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::find_sid_data_file;
using sidutil::std_error_string;

vga::vga ()
    : init_pin(this, & vga::init),
      ports_0x3b4_0x3b5_bus(this, & vga::read_port_0x3b4_0x3b5, &vga::write_port_0x3b4_0x3b5),
      port_0x3ba_bus(this, & vga::read_port_0x3ba, &vga::write_port_0x3ba),
      ports_0x3c0_0x3cf_bus(this, & vga::read_port_0x3c0_0x3cf, &vga::write_port_0x3c0_0x3cf),
      ports_0x3d4_0x3d5_bus(this, & vga::read_port_0x3d4_0x3d5, &vga::write_port_0x3d4_0x3d5),
      port_0x3da_bus(this, & vga::read_port_0x3da, &vga::write_port_0x3da),
      cmos_registers_bus(0),
      framebuffer_bus(this, & vga::read_mem, &vga::write_mem),
      imageload_pin (this, & vga::imageload_handler),
      imagestore_pin (this, & vga::imagestore_handler),
      imagemmap_pin (this, & vga::imagemmap_handler),
      imagemsync_pin (this, & vga::imagemsync_handler)
{
  add_pin("init", & this->init_pin);

  add_pin("text-start-address", & this->text_start_address_pin);
  add_pin("text-cursor-x", & this->text_cursor_x_pin);
  add_pin("text-cursor-y", & this->text_cursor_y_pin);
  add_pin("text-memory-updated", & this->text_memory_updated_pin);

  add_pin("dimension-width", & this->dimension_width_pin);
  add_pin("dimension-height", & this->dimension_height_pin);
  add_pin("dimensions-updated", & this->dimensions_updated_pin);

  add_pin("palette-change-index", & this->palette_change_index_pin);

  add_bus("ports-0x3b4-0x3b5", & this->ports_0x3b4_0x3b5_bus);
  add_bus("port-0x3ba", & this->port_0x3ba_bus);
  add_bus("ports-0x3c0-0x3cf", & this->ports_0x3c0_0x3cf_bus);
  add_bus("ports-0x3d4-0x3d5", & this->ports_0x3d4_0x3d5_bus);
  add_bus("port-0x3da", & this->port_0x3da_bus);

  add_bus("framebuffer", & this->framebuffer_bus);

  add_accessor("cmos-registers", & this->cmos_registers_bus);

  // copied from sid/component/memory/generic.cxx

  add_attribute_virtual ("size", this,
			 & vga::get_size_attr,
			 & vga::set_size_attr, "setting");

  this->max_buffer_length = 32UL * 1024UL * 1024UL;
  this->buffer = 0;
  this->buffer_length = 0;
  this->mmapping_p = false;

  add_attribute ("image-file", & this->image_file_name, "setting");
  add_pin ("image-load", & this->imageload_pin);
  add_attribute ("image-load", & this->imageload_pin, "pin");
  add_pin ("image-store", & this->imagestore_pin);
  add_attribute ("image-store", & this->imagestore_pin, "pin");
  add_pin ("image-mmap", & this->imagemmap_pin);
  add_attribute ("image-mmap", & this->imagemmap_pin, "pin");
  add_pin ("image-msync", & this->imagemsync_pin);
  add_attribute ("image-msync", & this->imagemsync_pin, "pin");
}

void
vga::init (host_int_4)
{
  bx_vga.init(this, this->buffer);
  if (cmos_registers_bus)
    {
      little_int_1 old_register_value;
      little_int_1 new_register_value;

      cmos_registers_bus->read(host_int_4(0x14), old_register_value);
      new_register_value = (old_register_value & 0xcf) | 0x00;
      cmos_registers_bus->write(host_int_4(0x14), new_register_value); /* video card with BIOS ROM */
    }
}

bus::status
vga::read_port_0x3b4_0x3b5 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3b4;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_0x3b4_0x3b5 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3b4;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_0x3ba (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3ba;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_0x3ba (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3ba;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_0x3c0_0x3cf (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3c0;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_0x3c0_0x3cf (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3c0;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_0x3d4_0x3d5 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3d4;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_0x3d4_0x3d5 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3d4;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_0x3da (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3da;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_0x3da (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3da;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_mem (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0xa0000;
  data = bx_vga.mem_read(addr);
  return bus::ok;
}

bus::status
vga::write_mem (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0xa0000;
  bx_vga.mem_write(addr, data);
  return bus::ok;
}

void
vga::drive_text_start_address_pin (host_int_4 addr)
{
  this->text_start_address_pin.drive(addr);
}

void
vga::drive_text_cursor_x_pin (host_int_4 x)
{
  this->text_cursor_x_pin.drive(x);
}

void
vga::drive_text_cursor_y_pin (host_int_4 y)
{
  this->text_cursor_y_pin.drive(y);
}

void
vga::drive_text_memory_updated_pin (void)
{
  this->text_memory_updated_pin.drive(1);
}

void
vga::drive_dimension_width_pin (host_int_4 width)
{
  this->dimension_width_pin.drive(width);
}

void
vga::drive_dimension_height_pin (host_int_4 height)
{
  this->dimension_height_pin.drive(height);
}

void
vga::drive_dimensions_updated_pin (void)
{
  this->dimensions_updated_pin.drive(1);
}

void
vga::drive_palette_change_index_pin (host_int_4 index)
{
  this->palette_change_index_pin.drive(index);
}

bool
vga::attempt_resize (host_int_4 new_length) throw()
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

string
vga::get_size_attr ()
{
  return make_attribute (this->buffer_length);
}


component::status
vga::set_size_attr (const string& s)
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

void
vga::imageload_handler (host_int_4)
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
vga::imagestore_handler (host_int_4)
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
vga::imagemsync_handler (host_int_4)
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
vga::imagemmap_handler (host_int_4)
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
