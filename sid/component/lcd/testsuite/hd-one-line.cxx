// hd-one-line.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "hd-one-line.h"
#include <sidso.h>

void
hd_one_line :: init() {
  put( LCD_IR, 0x30 );		// 1-lines, 5x8 font
  put( LCD_IR, 1 );		// clear display
  put( LCD_IR, 0x3 );		// return home
  put( LCD_IR, 0xc );		// enable display

  put( LCD_IR, 0x80 );		// select DDRAM address 0

  for( int i=0; i<8; i++ )
    put( LCD_DR, 0xa1 + i );

  put( LCD_IR, 0x7 );		// shift left on input
  curr_char = 0xaa;

  refresh.drive( 1 );
  cout << "should see Japanese chars 0xa1-0xa9" << endl;
}

void
hd_one_line :: draw_char( uchar val ) {
  put( LCD_DR, val );
}

void
hd_one_line :: run( host_int_4 ) {
  switch( curr_state() ) {
  case INIT:
    init();
    yield( SCROLL, 50000 );
    return;

  case SCROLL:
    if( (curr_char & 0x0f) == 0 )
      cout << "drawing japanese char " << hex << (int)curr_char << dec << endl;

    draw_char( curr_char );
    ++curr_char;
    if( curr_char >= 0xe0 )
      yield( DONE, 80000 );
    else {
      refresh.drive( 1 );
      yield( SCROLL, 80000 );
    }
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
    return new hd_one_line();
  else
    return 0;
}

static void
HD44780UTesterDelete( component* c ) {
  delete dynamic_cast<hd_one_line*>(c);
}


// static object
extern const component_library hd1l_tester_component_library;

const component_library hd1l_tester_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & HD44780UTesterListTypes, 
  & HD44780UTesterCreate,
  & HD44780UTesterDelete
};

