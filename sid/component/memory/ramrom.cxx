// ramrom.cxx - RAM and ROM memory components.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include "ramrom.h"

using std::vector;
using std::string;
using std::ostream;
using std::istream;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_4;
using sid::host_int_4;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::little_int_8;
using sid::big_int_1;
using sid::big_int_2;
using sid::big_int_4;
using sid::big_int_8;


ramrom_memory::ramrom_memory()
  :read_only_bus(this), read_write_bus(this)
{
  add_bus ("read-only-port", & this->read_only_bus);
  add_bus ("read-write-port", & this->read_write_bus);
}
