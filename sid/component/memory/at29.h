// at29.h - A specialisation of the generic flash memory class to
// model the ATMEL 29xxx series of flash memory.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// The ATMEL flash has a data security mechanism that prevents
// unexpected data modification due to transient address/data lines in
// the physical realm.  To write to a given sector, a special sequence
// of address writes must first take place.

// More details on this component can be found on ATMEL's web site
// (http://www.atmel.com/) in various data sheets.

#ifndef AT29_H
#define AT29_H

#include "flash.h"

#include <sidcomp.h>
#include <sidtypes.h>
#include <sidattrutil.h>

#include <stdexcept>
#include <cassert>
#include <iostream>

using std::ostream;
using std::istream;
using std::string;

using sid::bus;
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



struct at29_flash_memory_type
{
  const char* name;
  host_int_4 memory_size;
  host_int_4 sector_size;
  host_int_1 device_id;
};



class at29_flash_memory;

class at29_bus: public bus
{
public:
  at29_bus(at29_flash_memory* target): target(target) {}
  
  bus::status write(host_int_4 address, big_int_1 data) throw ();
  bus::status write(host_int_4 address, little_int_1 data) throw ();
  bus::status read(host_int_4 address, big_int_1& data) throw ();
  bus::status read(host_int_4 address, little_int_1& data) throw ();
  
#define NOPERM_WRITE(type) \
    bus::status write(host_int_4 address, type data) throw () \
              { return bus::unpermitted; }
  
#define NOPERM_READ(type) \
    bus::status read(host_int_4 address, type& data) throw () \
	      { return bus::unpermitted; }
  
  NOPERM_WRITE(big_int_2);
  NOPERM_WRITE(little_int_2);
  NOPERM_WRITE(big_int_4);
  NOPERM_WRITE(little_int_4);
  NOPERM_WRITE(big_int_8);
  NOPERM_WRITE(little_int_8);
  
  NOPERM_READ(big_int_2);
  NOPERM_READ(little_int_2);
  NOPERM_READ(big_int_4);
  NOPERM_READ(little_int_4);
  NOPERM_READ(big_int_8);
  NOPERM_READ(little_int_8);
  
#undef NOPERM_READ
#undef NOPERM_WRITE

  private:
    at29_flash_memory* target;
};



class at29_flash_memory: public flash_uniform_sector_memory
{
public:

  at29_flash_memory(size_t memory_size, size_t sector_size, 
		    host_int_1 device_id) throw (bad_alloc);
  static const at29_flash_memory_type types[];

protected:
  void stream_state (ostream&) const;
  void destream_state (istream&);  
  
private:
  friend class at29_bus;
  at29_bus my_bus;

  bool write_ok(host_int_4 address);

  enum states {
    LOCKED,
    START1,
    START2,
    PROG,
    IDENT
  } state;

  const host_int_4 noSectorNum;
  host_int_4 sectorNum;
  host_int_1 manufacturerCode;
  host_int_1 deviceIdCode;
};


#endif // AT29_H
