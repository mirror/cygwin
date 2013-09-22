// angel.h - A limited emulation component for the Angel ROM monitor
// that features onthe ARM PID7T development board.  -*- C++ -*-

// Copyright (C) 1999-2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// Details of the Angel ROM monitor and, specifically, the system call
// interface, can be found in Chapter 8 of the ARM Software
// Development Toolkit Reference Guide (ARM part no. DUI 0041B).

#ifndef ANGEL_H
#define ANGEL_H

// FIXME: Move to common area.
extern "C" {
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef HAVE_TIME_H
#include <time.h>
#endif
}

#include "gloss.h"

using sidutil::make_attribute;
using sidutil::parse_attribute;

class arm_angel: public gloss32
{
public:

  arm_angel();
  ~arm_angel() throw() { }

private:

  enum syscalls /* See also: newlib/libc/sys/arm/swi.h AngelSWI_Reason_* */
  {
    syscall_open = 0x1,
    syscall_close = 0x2,
    syscall_writec = 0x3,
    syscall_write0 = 0x4,
    syscall_write = 0x5,
    syscall_read = 0x6,
    syscall_readc = 0x7,
    syscall_iserror,
    syscall_istty = 0x9,
    syscall_seek = 0xA,
    syscall_flen = 0xC,
    syscall_tmpnam = 0xD,
    syscall_remove = 0xE,
    syscall_rename = 0xF,
    syscall_clock = 0x10,
    syscall_time = 0x11,
    syscall_system = 0x12,
    syscall_errno = 0x13,
    syscall_get_cmdline = 0x15,
    syscall_heapinfo = 0x16,
    syscall_report_exception = 0x18
  };

  enum exceptions {
    exception_rte = 0x20022,  // Runtime error.
    exception_exit = 0x20026
  };

  int32 errnum;
  uint32 heapBase, heapLimit;
  uint32 stackBase, stackLimit;

  clock_t startupTime;

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
  // Cover fn for set_error_result (host_to_target_errno (errcode)).
  bool set_host_error_result (int32 errcode);

  // Methods to handle the individual system calls.
  void do_clock();
  void do_close();
  void do_flen();
  void do_get_cmdline();
  void do_heapinfo();
  void do_iserror();
  void do_istty();
  void do_open();
  void do_read();
  void do_readc();
  void do_remove();
  void do_rename();
  void do_report_exception();
  void do_seek();
  void do_system();
  void do_tmpnam();
  void do_write();
  void do_write0();
  void do_writec();
};

#endif // ANGEL_H
