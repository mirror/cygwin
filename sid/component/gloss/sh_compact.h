// sh_compact.h - Interface details for sh_compact.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// System call numbers must be synchronised with:
//   sin/sh/syscall.h
//
// Some ports don't use the standard syscall.h numbers.  Sigh.

#ifndef SH_COMPACT_H
#define SH_COMPACT_H

class sh_compact
{
public:

  enum sh_compact_syscall
  {
    // !!! DANGER !!!
    // This was copied from sim/sh/syscall.h which was copied from newlib.
    SYS_exit	  = 1,
    SYS_fork	  = 2,
    SYS_read	  = 3,
    SYS_write	  = 4,
    SYS_open	  = 5,
    SYS_close	  = 6,
    SYS_wait4	  = 7,
    SYS_creat	  = 8,
    SYS_link	  = 9,
    SYS_unlink	  = 10,
    SYS_execv	  = 11,
    SYS_chdir	  = 12,
    SYS_mknod	  = 14,
    SYS_chmod	  = 15,
    SYS_chown	  = 16,
    SYS_lseek	  = 19,
    SYS_getpid	  = 20,
    SYS_isatty    = 21,
    SYS_fstat     = 22,
    SYS_time 	  = 23,
    SYS_ARG	  = 24,
    SYS_stat	  = 38,
    SYS_pipe	  = 42,
    SYS_execve	  = 59,
    SYS_truncate  = 129,
    SYS_ftruncate = 130,
    SYS_argc	  = 172,
    SYS_argnlen	  = 173,
    SYS_argn	  = 174,
    SYS_utime     = 201, // not really a system call
    SYS_wait      = 202  // nor is this
  };
};

#endif // SH_COMPACT_H
