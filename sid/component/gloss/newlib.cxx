// newlib.cxx - newlib support.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include <errno.h>
#include "newlib.h"

int
newlib::host_to_target_errno (int host_errno)
{
  switch (host_errno)
    {
#ifdef EPERM
    case EPERM : return ePerm;
#endif
#ifdef ENOENT
    case ENOENT : return eNoEnt;
#endif
#ifdef EBADF
    case EBADF : return eBadF;
#endif
#ifdef EAGAIN
    case EAGAIN : return eAgain;
#endif
#ifdef EFAULT
    case EFAULT : return eFault;
#endif
#ifdef EINVAL
    case EINVAL : return eInval;
#endif
#ifdef EPIPE
    case EPIPE : return ePipe;
#endif
#ifdef ENOSYS
    case ENOSYS : return eNoSys;
#endif
    default : return EINVAL;
    }
  /*NOTREACHED*/
}
