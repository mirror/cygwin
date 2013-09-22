// m32r.h - Class declaration for the M32R gloss component, using
// libgloss.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef M32R_H
#define M32R_H

#include "gloss.h"

class m32r_libgloss: public gloss32
{
public:

  m32r_libgloss();
  ~m32r_libgloss() throw() { }

private:

  // ABI-specifics, for getting syscall arguments and setting results.
  // ??? Class by itself.
  // ??? Perhaps this shouldn't be here at all as it's really an
  // implementation detail (but lots of implementations will probably use it).
  bool get_int_argument(unsigned index, int32& value);
  bool set_int_result(int32 value);
  bool set_error_result(int32 value);

  // Return boolean indicating if cpu is requesting something we're to handle.
  bool syscall_trap_p();
  // Perform a system call trap.
  void syscall_trap();

  // Convert host errno to target errno.
  int host_to_target_errno (int errno_);
};

#endif /* M32R_H */
