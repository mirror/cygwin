// parport-driver.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef PARPORT_DRIVER_H
#define PARPORT_DRIVER_H

class parport_driver {
private:
  volatile unsigned char* const PR_REG;
  volatile unsigned char* const SR_REG;
  volatile unsigned char* const IOSEL_REG;
  volatile unsigned char* const CTL_REG;
  volatile unsigned char* const CMD_REG;

public: 
  parport_driver();

  // waits for ACK before returning new PR value
  unsigned char get_prreg();

  void set_ctl( unsigned char set_val ) { *CTL_REG = set_val; }
  void set_iosel( unsigned char set_val ) { *IOSEL_REG = set_val; }

  unsigned char get_pr()	{ return *PR_REG; }
  unsigned char get_sr()	{ return *SR_REG; }
  unsigned char get_cmd()	{ return *CMD_REG; }
};

#endif // PARPORT_DRIVER_H
