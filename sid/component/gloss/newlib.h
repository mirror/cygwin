// newlib.h - Interface details for the C library; used by ROM
// monitors and the like.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// Error numbers must be synchronised with:
//   newlib/libc/include/sys/errno.h
//
// Signal numbers must be synchronised with:
//   newlib/libc/include/sys/signal.h

#ifndef NEWLIB_H
#define NEWLIB_H

class newlib
{
 public:

  // It would be nice to give these enumerations their familiar
  // names (e.g. EPERM), but then these will collide with macros
  // of the same name on the host.

  enum errors
  {
    ePerm = 1,
    eNoEnt = 2,
    eBadF = 9,
    eAgain = 11,
    eFault = 14,
    eInval = 22,
    ePipe = 32,
    eNoSys = 88
  };

  enum signals
  {
    sigNone = 0,
    sigHup = 1,
    sigInt = 2,
    sigQuit = 3,
    sigIll = 4,
    sigTrap = 5,
    sigAbrt = 6,
    sigBus = 7,
    sigFpe = 8,
    sigKill = 9,
    sigSegv = 11,
    sigTerm = 15
  };

  static int host_to_target_errno (int errcode);
};

#endif // NEWLIB_H
