// parport-driver.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#include <stdio.h>
#include "parport-driver.h"
#include "mem-map.h"

parport_driver::parport_driver() :
  PR_REG (PARPORT_BASE + 0),    SR_REG (PARPORT_BASE + 1),
  IOSEL_REG (PARPORT_BASE + 1), CTL_REG (PARPORT_BASE + 2),
  CMD_REG (PARPORT_BASE + 2)
{ }
   
unsigned char
parport_driver::get_prreg() 
 {
   static unsigned char last_val = 0;

   unsigned char status = *SR_REG;

   if( status & 0x4 ) 
     return last_val;

   unsigned char val = *PR_REG;

   last_val = val;

   return val;
 }




