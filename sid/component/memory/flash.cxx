// flash.cxx - Implementation of the generic flash memory class.
// -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "flash.h"

#include <sidattrutil.h>

using sidutil::make_attribute;
using sidutil::parse_attribute;

flash_uniform_sector_memory::flash_uniform_sector_memory()
{
  add_attribute_virtual("sector-size", this,
			& flash_uniform_sector_memory::get_sector_size_attr,
			& flash_uniform_sector_memory::set_sector_size_attr,
			"setting");
}


string
flash_uniform_sector_memory::get_sector_size_attr()
{
  return make_attribute(this->sector_size);
}


component::status
flash_uniform_sector_memory::set_sector_size_attr(const string& s)
{
  host_int_4 new_size;

  component::status st = parse_attribute(s, new_size);
  if (st == component::ok)
    {
      if ((new_size > 0) && (new_size <= buffer_length))
	{
	  sector_size = new_size;
	  return component::ok;
	}
      else
	return component::bad_value;
    }
  return st;
}

void
flash_uniform_sector_memory::stream_state (ostream& out) const
{
  flash_memory::stream_state(out);
  if (!out.good())
    return;

  out << ':' << "sector-size " << sector_size;
}

void
flash_uniform_sector_memory::destream_state (istream& in)
{
  flash_memory::destream_state(in);
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
  if (key != "sector-size")
    {
      in.setstate(ios::badbit);
      return;
    }
  in >> sector_size;
}
