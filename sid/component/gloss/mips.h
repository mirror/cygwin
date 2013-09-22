// mips.h - Class declaration for the MIPS monitor support.
// Currently supported monitors: idt.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MIPS_H
#define MIPS_H

#include "gloss.h"

// ??? mips_idt, and have 64_p attribute?
// [with associated changes to gloss32/gloss64]

class mips32_idt: public gloss32
{
public:

  mips32_idt();
  ~mips32_idt() throw() { }

private:

  // Begin idt syscalls here to distinguish them from others.
  // blah blah ... no suitable value ... blah blah
  enum { SYSCALL_MIN = 0x42000 };

  enum syscalls
  {
    SYSCALL_WRITE = 8,
    SYSCALL_EXIT = 17,
    SYSCALL_GET_MEM_INFO = 55,
    SYSCALL_MAX = 64
  };

  // _exit() stuff's this in the `code' field of `break' insns.
  enum { BREAK_EXIT = 0xffc00 };

  // The main RAM memory of the cpu we support.
  // ??? multi-cpu support, blah blah blah
  component* ram;

  // The ROM memory of the monitor we emulate.
  component* rom;

  // We need to do some extra processing at reset time.
  void reset();

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

#endif /* MIPS_H */
