// am29.cxx - Implementation of AMD's 29xxx flash memory.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <sidcomp.h>
#include <sidbusutil.h>

#include "am29.h"

enum {
  STATE_READ,
  STATE_UNLOCK1,
  STATE_UNLOCK2,
  STATE_AUTOSELECT,
  STATE_PROGRAM,
  STATE_ERASE0,
  STATE_ERASE1,
  STATE_ERASE2,
  STATE_BYPASS,
  STATE_BYPASS_RESET
};

enum {
  UNLOCK = 0x555,
  UNLOCK2 = 0x2AA
};

enum {
  AUTOSELECT_CMD = 0x90,
  ERASE_CMD = 0x80,
  ERASE_CHIP_CMD = 0x10,
  ERASE_SECTOR_CMD = 0x30,
  PROGRAM_CMD = 0xA0,
  UNLOCK1_CMD = 0xAA,
  UNLOCK2_CMD = 0x55,
  BYPASS_CMD = 0x20,
  BYPASS_PROG_CMD = 0xA0,
  BYPASS_RESET_CMD = 0x90
};
 
am29_flash_memory::am29_flash_memory (size_t ms, size_t ss, host_int_1 id)
  :my_bus(this),
   manufacturerCode(0x01)
{
  // set incoming parameters
  deviceIdCode = id;
  sector_size = ss;
  if (!attempt_resize(ms))
    {
      throw bad_alloc();
    }
  
  mode = STATE_READ;
  erase();

  add_bus("read-write-port", &this->my_bus);
  add_attribute_ro("mode", &mode);
  add_attribute("device-code", &deviceIdCode, "setting");
  add_attribute_ro_value("manufacturer-code", manufacturerCode, "setting");
}

void
am29_flash_memory::stream_state (ostream& out) const
{
  flash_uniform_sector_memory::stream_state(out);
  if (!out.good())
    return;

  out << ':' << "device-code " << deviceIdCode;
}

void
am29_flash_memory::destream_state (istream& in)
{
  flash_uniform_sector_memory::destream_state(in);
  if (!in.good())
    return;

  char ch;
  string key;

  in.get(ch);
  if (ch != ':')
    {
      in.setstate(ios::badbit);
      return;
    }
  in >> key;
  if (key != "device-code")
    {
      in.setstate(ios::badbit);
      return;
    }
  in >> deviceIdCode;
}


// Erase the entire chip.
void
am29_flash_memory::erase()
{
  for (unsigned i = 0; i < buffer_length; i++)
    {
     buffer[i] = 0xFF;
    }
}

// Erase a sector.
void
am29_flash_memory::erase(unsigned sector)
{
  host_int_4 start_addr = sector_size * sector;

  if (start_addr >= buffer_length)
    return;

  host_int_4 end_addr = sector_size * (sector + 1);

  if (end_addr > buffer_length)
    end_addr = buffer_length;
  
  assert(start_addr < end_addr);
  assert(start_addr < buffer_length);
  assert(end_addr < buffer_length);
  
  for (unsigned i = start_addr; i < end_addr; i++)
    {
      buffer[i] = 0xFF;
    }
}


bool
am29_flash_memory::write_ok(host_int_4 address)
{
  return (mode == STATE_PROGRAM);
}


bus::status
am29_flash_memory::am29_bus::read(host_int_4 address,
				  little_int_1& data) throw ()
{
  try
    {
      if (target->mode == STATE_AUTOSELECT)
	{
	  if ((address & 0xF) == 0)
	    data = target->manufacturerCode;
	  else if ((address & 0xF) == 1)
	    data = target->deviceIdCode;
	  else if ((address & 0xF) == 2)
	    {
	      // FIXME: All sectors are unprotected.
	      data = 0;
	    }
	  return bus::ok;
	}

      // Bounds check the memory reference.
      if (address > target->buffer_length)
	{
	  return bus::unmapped;
	}
      data = target->buffer[address];
      return sid::bus::ok;
    }
  catch (...)
    {
      return sid::bus::delayed;
    }
}
 

bus::status
am29_flash_memory::am29_bus::read(host_int_4 address,
				  big_int_1& data) throw ()
{
  try
    {
      little_int_1 littleData(data);
      bus::status result = read(address, littleData);
      data = littleData;
      return result;
    }
  catch (...)
    {
      return sid::bus::delayed;
    }
}	


bus::status
am29_flash_memory::am29_bus::write(host_int_4 address, 
				   little_int_1 le_data) throw()
{
  try
    {
      host_int_1 data = le_data;
      
      switch (target->mode)
	{
	case STATE_READ:
	  if (address == UNLOCK && data == UNLOCK1_CMD)
	    {
	      target->mode = STATE_UNLOCK1;
	      return bus::ok;
	    }
          return bus::unpermitted;

	case STATE_AUTOSELECT:
	  // Don't care about the address bits for the reset command.
	  if (data == 0xF0)
	    {
	      target->mode = STATE_READ;
	      return bus::ok;
	    }
          return bus::ok;

	case STATE_BYPASS:
	  // Don't care about address bits for the bypass program cmd.
	  if (data == BYPASS_PROG_CMD)
	    target->mode = STATE_PROGRAM;
	  else if (data == BYPASS_RESET_CMD)
	    target->mode = STATE_BYPASS_RESET;
	  else
	    target->mode = STATE_READ;
	  return bus::ok;

	case STATE_BYPASS_RESET:
	  // Go back to read mode unconditionally -- this is the
	  // expected behaviour even if the magic codes are wrong.
	  target->mode = STATE_READ;
	  return bus::ok;

	case STATE_ERASE0:
	  if (address == UNLOCK && data == UNLOCK1_CMD)
	    target->mode = STATE_ERASE1;
	  else
	    target->mode = STATE_READ;
	  return bus::ok;

	case STATE_ERASE1:
	  if (address == UNLOCK2 && data == UNLOCK2_CMD)
	    target->mode = STATE_ERASE2;
	  else
	    target->mode = STATE_READ;
	  return bus::ok;

	case STATE_ERASE2:
	  if (address == UNLOCK && data == ERASE_CHIP_CMD)
	    {
	      target->erase();
	    }
	  else if (UNLOCK && data == ERASE_SECTOR_CMD)
	    {
	      target->erase((address >> 16));
	    }
	  target->mode = STATE_READ;
	  return bus::ok;
	  
	case STATE_UNLOCK1:
	  if (address == UNLOCK2 && data == UNLOCK2_CMD)
	    target->mode = STATE_UNLOCK2;
	  else
	    target->mode = STATE_READ;
	  return bus::ok;
	  
	case STATE_UNLOCK2:
	  if (address == UNLOCK && data == AUTOSELECT_CMD)
	    target->mode = STATE_AUTOSELECT;
	  else if (address == UNLOCK && data == PROGRAM_CMD)
	    target->mode = STATE_PROGRAM;
	  else if (address == UNLOCK && data == ERASE_CMD)
	    target->mode = STATE_ERASE0;
	  else if (address == UNLOCK && data == BYPASS_CMD)
	    target->mode = STATE_BYPASS;
	  else
	    target->mode = STATE_READ;
	  return bus::ok;
	}

      if (address > target->buffer_length)
	{
	  return bus::unmapped;
	}

      if (target->write_ok(address))
        {
	  little_int_1 old_data = target->buffer[address];
	  for (int i = 0; i < 8; i++)
	    {
	      int mask = 1 << i;
	      if (((old_data & mask) == 0) && ((data & mask) != 0))
		{
		  // Cannot change a 0 back to a 1, so clear this bit.
		  data &= ~mask;
		}
	    }
		  
          target->buffer[address] = data;
	  target->mode = STATE_READ;
          return bus::ok;
        }
      else
        return bus::delayed;
    }
  catch (...)
    {
      return bus::delayed;
    }
}


bus::status
am29_flash_memory::am29_bus::write(host_int_4 address,
				   big_int_1 data) throw ()
{
  return write(address, little_int_1(data));
}

// static const description table for flash family
// Details taken from AMD data sheet, publication no. 21354, 1999-05-18.

const am29_flash_memory_type am29_flash_memory::types[] = 
{
  { "f010a", 128*1024, 16*1024, 0x20 },
  { "lv010b", 128*1024, 16*1024, 0x6E },
  { "lv040b", 512*1024, 64*1024, 0x4F },
  { "lv081b", 1024*1024, 64*1024, 0x38 },
  { "lv017b", 2*1024*1024, 64*1024, 0xC8 },
  { "lv033c", 4*1024*1024, 64*1024, 0xA3 },
  // termination
  { 0, 0, 0, 0 }
};
