// sh_media.h - Interface details for sh_media.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// System call numbers must be synchronised with:
//   sin/sh/syscall.h
//
// Some ports don't use the standard syscall.h numbers.  Sigh.

#ifndef SH_MEDIA_H
#define SH_MEDIA_H

class sh_media
{
public:

  enum sh_media_syscall
  {
    // !!! DANGER !!!
    // This was copied from sim/sh64/sh64.c.
    SYS_exit    = 1,
    SYS_read	= 3,
    SYS_write   = 4,
    SYS_open	= 5,
    SYS_close	= 6,
    SYS_lseek	= 19,
    SYS_time	= 23,
    SYS_argc	= 172,
    SYS_argnlen	= 173,
    SYS_argn	= 174
  };
};

#endif // SH_MEDIA_H
