// ramrom.h - Declarations for the ramrom_memory class.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "generic.h"

#include <sidcomp.h>
#include <sidattrutil.h>

#include <iostream>
#include <stdexcept>
#include <new>


using std::ostream;
using std::istream;

using sid::component;

using sidutil::make_attribute;
using sidutil::parse_attribute;


// ----------------------------------------------------------------------------

class ramrom_memory: public generic_memory
{
public:
  ramrom_memory();

protected:
  // buses
  friend class ramrom_read_only_bus;
  friend class ramrom_read_write_bus;
  generic_read_only_bus read_only_bus;
  generic_read_write_bus read_write_bus;
};
