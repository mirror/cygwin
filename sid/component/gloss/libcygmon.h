// libcygmon.h - Interface details for Cygmon.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// System call numbers must be synchronised with:
//   libgloss/i386/cygmon-syscall.h

#ifndef CYGMON_H
#define CYGMON_H

class cygmon
{
public:
    
  enum cygmon_syscall
  {
    SYS_exit = 1,
    SYS_open = 5, 
    SYS_close = 6, 
    SYS_read = 3,
    SYS_write = 4, 
    SYS_kill = 37,
    SYS_time = 13,
    SYS_gettimeofday = 156
  };
};

#endif // CYGMON_H
