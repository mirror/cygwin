// hd-tester.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "hd-tester.h"

#define LCD_BASE	0xa0000		// base address for LCD

HD44780U_tester :: HD44780U_tester() : run_ipin( this, &HD44780U_tester::run )
{
  add_pin( "run", &run_ipin, &run_opin );

  add_accessor( "bus", &bus );
  add_uni_relation( "lcd", &lcd );

  fail_count = 0;

  state = INIT;
}

void
HD44780U_tester :: put( unsigned reg, uchar val ) {
  big_int_1 data = 0x80;

  while( data & 0x80 ) {
    if( bus->read( LCD_BASE + LCD_IR, data ) != sid::bus::ok ) {
      cerr << "send_cmd: status read failed" << endl;
      ++fail_count;
      return;
    }
  }

  data = val;
  if( bus->write( LCD_BASE + reg, data ) != sid::bus::ok ) {
    cerr << "send_cmd: write failed" << endl;
    ++fail_count;
  }
}

uchar
HD44780U_tester :: get( unsigned reg ) {
  big_int_1 data = 0x80;
  uchar val;

  while( data & 0x80 ) {
    if( bus->read( LCD_BASE + LCD_IR, data ) != sid::bus::ok ) {
      cerr << "get: status read failed" << endl;
      ++fail_count;
      return 0xff;
    }
  }

  if( bus->read( LCD_BASE + reg, data ) != sid::bus::ok ) {
    cerr << "get: read failed" << endl;
    ++fail_count;
  }

  val = data;
  return val;
}

void
HD44780U_tester :: yield( int to_state, unsigned long count ) {
  if( state == WAITING ) {
    if( curr_count < wait_count ) {
      ++curr_count;

#if 0
      if( (curr_count % 1000) == 0 )
	cerr << ".";
#endif
      return;
    }

    state = next_state;
  }
  else {
    next_state = to_state;
    state = WAITING;
    curr_count = 0;
    wait_count = count;
  }
}


