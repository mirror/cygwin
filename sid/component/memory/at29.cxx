// at29.cxx - Implementation of ATMEL's 29xxx flash memory.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "at29.h"
#include <new>

enum {
  SEQ_ADDR1 = 0x5555,
  SEQ_ADDR2 = 0xAAAA,
  START_CMD1 = 0xAA,
  START_CMD2 = 0x55,
  ID_CMD = 0x90,
  PROG_CMD = 0xA0,
  STOP_CMD = 0xF0
};


at29_flash_memory::at29_flash_memory (size_t ms, size_t ss, host_int_1 id) throw (bad_alloc)
  :my_bus(this),
   state(LOCKED),
   noSectorNum(0xFFFFFFFF),
   sectorNum(noSectorNum),
   manufacturerCode(0x1F)
{
  // set incoming parameters
  deviceIdCode = id;
  sector_size = ss;
  bool ok = attempt_resize (ms);
  if (! ok)
    throw bad_alloc (); // abort constructor

  add_bus("read-write-port", &this->my_bus);
  add_attribute("device-code", &deviceIdCode, "setting");
  add_attribute_ro("manufacturer-code", &manufacturerCode, "setting");
}

void
at29_flash_memory::stream_state (ostream& out) const
{
  flash_uniform_sector_memory::stream_state(out);
  if (!out.good())
    return;

  out << ':' << "device-code " << deviceIdCode;
}

void
at29_flash_memory::destream_state (istream& in)
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

bool
at29_flash_memory::write_ok(host_int_4 address)
{
  if (sectorNum == noSectorNum)
    {
      sectorNum = address / sector_size;
    }
  else
    {
      if (sectorNum != address / sector_size)
	{
	  return false;
	}
    }
  return (state == PROG);
}


bus::status
at29_bus::read(host_int_4 address,
	       little_int_1& data) throw ()
{
  if (target->state == at29_flash_memory::IDENT)
    {
      switch (address) {
      case 0:
	data = target->manufacturerCode;
	return bus::ok;
      case 1:
	data = target->deviceIdCode;
	return bus::ok;
      default:
	return bus::unpermitted;
      }
    }
  
  // Bounds check the memory read.
  if (address > target->buffer_length)
    {
      return bus::unmapped;
    }
  data = target->buffer[address];
  return bus::ok;
}


bus::status
at29_bus::read(host_int_4 address,
	       big_int_1& data) throw ()
{
  little_int_1 littleData(data);
  
  bus::status result = read(address, littleData);
  data = littleData;
  
  return result;
}	


bus::status
at29_bus::write(host_int_4 address, 
		little_int_1 le_data) throw()
{
  host_int_1 data = le_data;

  if (target->state == at29_flash_memory::PROG &&
      address == SEQ_ADDR1 && data == START_CMD1)
    {
      target->state = at29_flash_memory::LOCKED;
    }
  
  if (target->state == at29_flash_memory::IDENT &&
      address == SEQ_ADDR1 && data == START_CMD1)
    {
      target->state = at29_flash_memory::START1;
      return bus::ok;
    }
  
  if (target->state == at29_flash_memory::LOCKED &&
      address == SEQ_ADDR1 && data == START_CMD1)
    {
      target->state = at29_flash_memory::START1;
      return bus::ok;
    }
  
  if (target->state == at29_flash_memory::START1 &&
      address == SEQ_ADDR2 && data == START_CMD2)
    {
      target->state = at29_flash_memory::START2;
      return bus::ok;
    }
  
  if (target->state == at29_flash_memory::START2 &&
      address == SEQ_ADDR1 && data == ID_CMD)
    {
      target->state = at29_flash_memory::IDENT;
      return bus::ok;
    }
  
  if (target->state == at29_flash_memory::START2 &&
      address == SEQ_ADDR1 && data == STOP_CMD)
    {
      target->state = at29_flash_memory::LOCKED;
      return bus::ok;
    }
  
  if (target->state == at29_flash_memory::START2 &&
      address == SEQ_ADDR1 && data == PROG_CMD)
    {
      target->state = at29_flash_memory::PROG;
      target->sectorNum = target->noSectorNum;
      return bus::ok;
    }
  
  // Bounds check the memory write.
  if (address > target->buffer_length)
    {
      return bus::unmapped;
    }
  
  if (target->write_ok(address))
    {
      target->buffer[address] = data;
    }

  return bus::ok;
}


bus::status
at29_bus::write(host_int_4 address,
		big_int_1 data) throw ()
{
  return write(address, little_int_1(data));
}


// static const description table for flash family
// Details taken from Atmel Flash Application Note AN-3, Rev. 0518B-10/98.

const at29_flash_memory_type at29_flash_memory::types[] = 
{
  { "c256",   32*1024,  64,  0xDC },
  { "lv256",  32*1024,  64,  0xBC },
  { "c257",   32*1024,  64,  0xDC },
  { "c512",   64*1024,  128, 0x5D },
  { "lv512",  64*1024,  128, 0x3D },
  { "c010a",  128*1024, 128, 0xD5 },
  { "lv010a", 128*1024, 128, 0x35 },
  { "bv010a", 128*1024, 128, 0x35 },
  // at29c1024 and at29lv1024 are 16-bit-wide devices, not supported by this code
  { "c020",   256*1024, 256, 0xDA },
  { "lv020",  256*1024, 256, 0xBA },
  { "bv020",  256*1024, 256, 0xBA },
  { "c040",   512*1024, 512, 0x5B },
  { "lv040",  512*1024, 512, 0x3B },
  { "bv040",  512*1024, 512, 0x3B },
  { "c040a",  512*1024, 256, 0xA4 },
  { "lv040a", 512*1024, 256, 0xC4 },
  { "bv040a", 512*1024, 256, 0xC4 },
  // termination
  { 0, 0, 0, 0 }
};
