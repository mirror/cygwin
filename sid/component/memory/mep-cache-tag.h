// mep-cache-tag.h - Class declaration for the Toshiba Media Engine (MeP) Cache
// -*- C++ -*-

// Copyright (C) 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_CACHE_TAG_H
#define MEP_CACHE_TAG_H

#include "sidcpuutil.h"
#include "generic.h"

using namespace sidutil;

// Memory components for mep cache tag memory.
class mep_cache_tag_memory;

class mep_cache_tag_bus: public generic_read_write_bus
{
public:
  mep_cache_tag_bus(mep_cache_tag_memory* targ);

  // some macros to make manufacturing of the cartesian-product calls simpler
#define SID_GB_WRITE(type2) \
      bus::status write(host_int_4 address, type2 data) throw () \
	{ return this->write_any_filtered (address,data); } \
  
    SID_GB_WRITE(little_int_1);
    SID_GB_WRITE(little_int_2);
    SID_GB_WRITE(little_int_4);
    SID_GB_WRITE(little_int_8);

    SID_GB_WRITE(big_int_1);
    SID_GB_WRITE(big_int_2);
    SID_GB_WRITE(big_int_4);
    SID_GB_WRITE(big_int_8);
      
#undef SID_GB_WRITE
#undef SID_GB_READ


protected:
  template <typename DataType>
  bus::status
  write_any_filtered (host_int_4 address, DataType data);

  mep_cache_tag_memory *target;
};

// Memory components for mep cache tag memory.
class mep_cache_tag_memory : public generic_memory
{
public:
  mep_cache_tag_memory ();
protected:
  // buses
  friend class mep_cache_tag_bus;
  mep_cache_tag_bus read_write_bus;

  unsigned line_size;
  unsigned assoc;
  bool icache_p;
};

#endif // MEP_CACHE_TAG_H
