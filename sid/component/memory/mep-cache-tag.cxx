// mep-cache-tag.cxx - An implementation of the Cache tag memory for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidtypes.h>

#include "mep-cache-tag.h"

// Zap a possible math.h macro by this name
#undef log2

template <typename V>
static unsigned
log2 (const V& v1)
{
  V v2(1);
  for (unsigned i = 0; i < 8 * sizeof (V); i++)
    if (v1 & (v2 << i))
      return i;
}

// ----------------------------------------

mep_cache_tag_bus::mep_cache_tag_bus (mep_cache_tag_memory* targ) :
  generic_read_write_bus(targ),
  target (targ)
{
}

template <typename DataType>
bus::status
mep_cache_tag_bus::write_any_filtered (host_int_4 address, DataType data)
{
  // Range check address
  if (UNLIKELY((address < 0)))
    return bus::unmapped;
	       
  // Only the first word representing each line may be written.
  const unsigned width = sizeof(typename DataType::value_type); 
  if ((address+width) % target->line_size > 4/*bytes*/)
    return bus::unmapped;

  // Some bits may not be written
  assert (width <= 4);
  int shift = log2 (target->buffer_length) - log2 (target->assoc);
  host_int_4 mask = ~((1 << shift) - 1); // tag
  mask = mask | 0x1; // V bit
  if (! target->icache_p)
    mask = mask | 0x2; // D bit
  if (target->assoc > 1 && address < target->buffer_length / 2)
    mask = mask | 0x4; // R bit

  // Now shift the mask to match the alignment and size of the data.
  mask = mask >> ((4 - (address % 4 + width)) * 8);
  data = data & mask;
  typename DataType::value_type mem_image = data.target_memory_value();
  memcpy (& target->buffer[address], & mem_image, width);
  bus::status st (bus::ok);
  st.latency = target->write_latency;
  return st;
}

mep_cache_tag_memory::mep_cache_tag_memory()
  : read_write_bus(this),
    line_size (32),
    assoc (1),
    icache_p (false)
{
  add_bus ("read-write-port", & this->read_write_bus);
  add_attribute ("line-size", & line_size);
  add_attribute ("assoc",     & assoc);
  add_attribute ("icache?",   & icache_p);
}
