// flash.h - Class declaration for a generic flash memory component.
// The generic part is modelled on the assumption that a flash memory
// is like a conventional memory, only it has restrictions on how you
// can write to it.  The memory is divided into "sectors" or "zones".
// -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef FLASH_H
#define FLASH_H

#include "generic.h"

class flash_memory: public generic_memory
{
protected:
  // Returns true if a write is allowed to proceed. Some flash
  // memories have a data protection mechanism to prevent garbage
  // being written to the memory when the memory is in a transient
  // state.
  virtual bool write_ok(host_int_4 address) = 0;
};


class flash_uniform_sector_memory: public flash_memory
{
public:
  flash_uniform_sector_memory();

protected:
  host_int_4 sector_size;
  string get_sector_size_attr();
  component::status set_sector_size_attr(const string& s);

  void stream_state (ostream&) const;
  void destream_state (istream&);
};

#endif // FLASH_H
