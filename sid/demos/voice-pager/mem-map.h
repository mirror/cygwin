// mem-map.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEM_MAP_H
#define MEM_MAP_H

// base addresses of the various components.

typedef volatile unsigned char* PhysAddr_char;
typedef volatile unsigned long int* PhysAddr_lint;

PhysAddr_char const RTC_BASE		= (PhysAddr_char const) 0xa007F8;
PhysAddr_char const PARPORT_BASE	= (PhysAddr_char const) 0xa01100;
PhysAddr_char const LCD_BASE		= (PhysAddr_char const) 0xa01200;
PhysAddr_lint const CODEC_BASE	        = (PhysAddr_lint const) 0xa01300;
PhysAddr_char const PAGE_BASE		= (PhysAddr_char const) 0xa01400;


#endif // MEM_MAP_H
