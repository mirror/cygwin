// am29.h - A specialisation of the generic uniform sector flash memory
// class which models the AMD 29xxx series of flash memory.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// More details on this component can be found on AMD's web site
// <http://www.amd.com/> in various data sheets.

#ifndef AM29_H
#define AM29_H

#include <assert.h>
#include <iostream>
#include "flash.h"

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

struct am29_flash_memory_type
{
  const char* name;
  size_t memory_size;
  size_t sector_size;
  unsigned device_id;
};


class am29_flash_memory: public flash_uniform_sector_memory
{
public:
  am29_flash_memory(size_t memory_size, size_t sector_size, 
			 host_int_1 device_id);

  static const am29_flash_memory_type types[];

protected:
  void stream_state (ostream&) const;
  void destream_state (istream&);  

private:
  class am29_bus: public bus
  {
  public:
    am29_bus(am29_flash_memory* target):
      target(target) {}

    bus::status write(host_int_4 address, big_int_1 data) 
								    throw ( );

    bus::status write(host_int_4 address, little_int_1 data)
								    throw ( );

    bus::status read(host_int_4 address, big_int_1& data) throw ( );
    bus::status read(host_int_4 address, little_int_1& data) throw ( );

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
  
#undef NOPERM_WRITE  
#undef NOPERM_READ

  private:
    am29_flash_memory* target;
  };

  friend class am29_bus;
  am29_bus my_bus;

  bool write_ok(host_int_4 address);

  // Erase the entire chip.
  void erase();

  // Erase a given sector.
  void erase(unsigned sector);

  host_int_1 manufacturerCode;
  host_int_1 deviceIdCode;

  int mode;
};

#endif // AM29_H






