// libgloss.h - Interface details for libgloss.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// System call numbers must be synchronised with:
//   libgloss/syscall.h
//
// Some ports don't use the standard syscall.h numbers.  Sigh.
// Those ports should not use this file.

#ifndef LIBGLOSS_H
#define LIBGLOSS_H

class libgloss
{
public:

  enum libgloss_syscall
  {
    SYS_exit = 1,
    SYS_open = 2, 
    SYS_close = 3, 
    SYS_read = 4,
    SYS_write = 5, 
    SYS_lseek = 6, 
    SYS_unlink = 7,
    SYS_getpid = 8,
    SYS_kill = 9,
    SYS_fstat = 10, 
    SYS_argvlen = 12, 
    SYS_argv = 13,
    SYS_chdir = 14, 
    SYS_stat = 15, 
    SYS_chmod = 16, 
    SYS_utime = 17,
    SYS_time = 18,
    SYS_gettimeofday = 19,
    SYS_times = 20,
    SYS_reconfig = 25,
    SYS_argc = 172,
    SYS_argnlen = 173,
    SYS_argn = 174,
    SYS_unsupported = 255 // arbitrary syscall number, unsupported by default gloss component
  };
};

#endif // LIBGLOSS_H
