// angel.h - A limited emulation component for the Angel ROM monitor
// that features onthe ARM PID7T development board.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
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

private:

  enum syscalls
  {
    syscall_open = 1,
    syscall_close,
    syscall_writec,
    syscall_write0,
    syscall_write,
    syscall_readc,
    syscall_read,
    syscall_iserror,
    syscall_istty,
    syscall_seek = 0xA,
    syscall_flen = 0xC,
    syscall_tmpnam,
    syscall_remove,
    syscall_rename,
    syscall_clock,
    syscall_time,
    syscall_system,
    syscall_errno,
    syscall_get_cmdline = 0x15,
    syscall_heapinfo,
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
