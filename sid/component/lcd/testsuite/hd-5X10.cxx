// hd-5X10.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "hd-5X10.h"
#include <sidso.h>

void
hd_5X10 :: init() {
  put( LCD_IR, 0x34 );		// 1-lines, 5x10 font
  put( LCD_IR, 1 );		// clear display
  put( LCD_IR, 0x3 );		// return home
  put( LCD_IR, 0xe );		// enable display and cursor
  put( LCD_IR, 0x6 );		// incr on write

  put( LCD_IR, 0x80 );		// select DDRAM address 0

  put( LCD_DR, 0xe7 );		// g
  put( LCD_DR, 0xef );		// o
  put( LCD_DR, ' ' );
  put( LCD_DR, 0xf4 );		// ohm
  put( LCD_DR, ' ' );
  put( LCD_DR, 0xe2 );		// beta
  put( LCD_DR, 0xf9 );		// y
  put( LCD_DR, 0xe3 );		// epsilon

  refresh.drive( 1 );
  cout << "Should see \"Go home bye\" (sort of :-)" << endl;
}

void
hd_5X10 :: init_2() {
  put( LCD_IR, 4 );		// decr on write
  curr_char = 5;
}

void
hd_5X10 :: init_3() {
  put( LCD_IR, 6 );		// incr on write

  curr_char = 3;
  str[3] = 0xea;		// j
  str[2] = 0xe4;		// mu
  str[1] = 'm';
  str[0] = 0xf0;		// p
}

void
hd_5X10 :: draw_char( uchar val ) {
  put( LCD_DR, val );
}

void
hd_5X10 :: run( host_int_4 ) {
  switch( curr_state() ) {
  case INIT:
    init();
    yield( INIT_2, 1000000 );
    return;

  case INIT_2:
    init_2();
    yield( SCROLL_LEFT, 0 );
    return;

  case SCROLL_LEFT:
    draw_char( ' ' );
    refresh.drive( 1 );
    --curr_char;

    if( curr_char == 0 ) {
      cout << "should see \"go ohm\" " << endl;
      yield( INIT_3, 200000 );
    }
    else
      yield( SCROLL_LEFT, 50000 );
    return;

  case INIT_3:
    init_3();
    yield( SCROLL_RIGHT, 0 );
    return;

  case SCROLL_RIGHT:
    draw_char( str[curr_char] );
    refresh.drive( 1 );
    --curr_char;

    if( curr_char < 0 ) {
      cout << "should see \"go jump\" " << endl;
      yield( DONE, 500000 );
    }
    else
      yield( SCROLL_RIGHT, 50000 );
    return;

  case WAITING:
    yield();
    return;

  default:
    break;
  }

  cout << "all tests complete: fail count " << fail_count << endl;

  run_opin.drive( 0 );
}

static vector<string>
HD44780UTesterListTypes() {
  vector<string> types;
  types.push_back(string("hd44780u-tester"));
  return types;
}

static component*
HD44780UTesterCreate( const string& typeName ) {
  if(typeName == "hd44780u-tester")
    return new hd_5X10();
  else
    return 0;
}

static void
HD44780UTesterDelete( component* c ) {
  delete dynamic_cast<hd_5X10*>(c);
}


// static object
extern const component_library hd5X10_tester_component_library;

const component_library hd5X10_tester_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & HD44780UTesterListTypes, 
  & HD44780UTesterCreate,
  & HD44780UTesterDelete
};

