// hd-two-line.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "hd-two-line.h"
#include <sidso.h>

void
hd_two_line :: init() {
  put( LCD_IR, 0x38 );		// 2-lines, 5x8 font
  put( LCD_IR, 1 );		// clear display
  put( LCD_IR, 0x3 );		// return home
  put( LCD_IR, 0xc );		// enable display
}

static char logo[] = { 0x3, 0x4, 0x9, 0xa, 0xa, 
		0xa, 0xa, 0x9, 0x4, 0x3, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x18, 0x4, 0x13, 0x0b, 0x0, 
		0x0, 0xa, 0x13, 0x4, 0x18 };

void
hd_two_line :: draw_logo() {
  int i;

  put( LCD_IR, 0x43 );		// set AC to CGRAM char 0 line 3

  for( i=0; i<26; i++ )		// create logo	       
    put( LCD_DR, logo[i] );

  put( LCD_IR, 0x80 );		// select DDRAM address 0

  put( LCD_DR, 0 );		// write first line
  put( LCD_DR, 2 );

  char *str = "cygnus";
  char *p = str;

  while( *p )
    put( LCD_DR, *p++ );

  put( LCD_IR, 0xc0 );		// select start of second line

  put( LCD_DR, 1 );		// write second line
  put( LCD_DR, 3 );

  str = "rules!";
  p = str;

  while( *p )
    put( LCD_DR, *p++ );

  cout << "should see \"Cygnus rules!\" " << endl; 

  // This is for later, when the display is shifted
  put( LCD_IR, 0x88 );		// select DDRAM address 8

  put( LCD_DR, 0xf3 );		// infinity
  put( LCD_DR, 0xfc );		// house?

  put( LCD_IR, 0xa6 );		// select DDRAM address 0x26

  put( LCD_DR, 0xec );		// cent
  put( LCD_DR, 0xed );		// pound

  put( LCD_IR, 0xc8 );		// select DDRAM address 0x48

  put( LCD_DR, 0x5c );		// yen
  put( LCD_DR, 0xf2 );		// theta

  put( LCD_IR, 0xe6 );		// select DDRAM address 0x66

  put( LCD_DR, 0xe8 );		// sqrt
  put( LCD_DR, 0xf7 );		// pi
}

void 
hd_two_line :: enable_cursor() {
  put( LCD_IR, 0x82 );		// set DDRAM address to pos 2
  put( LCD_IR, 0x0e );		// enable cursor display

  cout << "cursor should be visible in line 1 pos 2" << endl;
}

void 
hd_two_line :: move_cursor() {
  put( LCD_IR, 0xc7 );		// set DDRAM address to pos 1
  put( LCD_IR, 0x0f );		// enable cursor display

  cout << "cursor and char should be blinking in line 2 pos 7" << endl;
}

void 
hd_two_line :: shift_cursor_left() {
  put( LCD_IR, 0x10 );		// shift cursor left

  cout << "cursor and char should be blinking in line 2 pos 6" << endl;
}

void 
hd_two_line :: shift_cursor_right() {
  put( LCD_IR, 0x0d );		// disable cursor (leave blinking on)
  put( LCD_IR, 0x14 );		// shift cursor right

  cout << "char should be blinking in line 2 pos 7" << endl;
}


void 
hd_two_line :: shift_display_left() {
  put( LCD_IR, 0x18 );		// shift display left

  cout << "display should be shifted left by one" << endl;
}

void 
hd_two_line :: shift_display_right() {
  put( LCD_IR, 0x1c );		// shift display right

  cout << "display should be shifted right by one" << endl;
}

void
hd_two_line :: disable_display() {
  put( LCD_IR, 0x08 );

  cout << "display should be disabled " << endl;
}

void
hd_two_line :: enable_display() {
  put( LCD_IR, 0x0c );		// leaves blink and cursor off

  cout << "display is now enabled " << endl;
}

void
hd_two_line :: run( host_int_4 ) {
  switch( curr_state() ) {
  case INIT:
    init();
    yield( DRAW_LOGO, 0 );
    return;

  case DRAW_LOGO:
    draw_logo();
    yield( NO_DISPLAY, 200000 );
    return;

  case NO_DISPLAY:
    disable_display();
    yield( SET_CURSOR, 100000 );
    return;

  case SET_CURSOR:
    enable_display();
    enable_cursor();
    yield( MOVE_CURSOR, 200000 );
    return;

  case MOVE_CURSOR:
    move_cursor();
    yield( SHIFT_CURSOR_LEFT, 500000 );
    return;

  case SHIFT_CURSOR_LEFT:
    shift_cursor_left();
    yield( SHIFT_CURSOR_RIGHT, 500000 );
    return;

  case SHIFT_CURSOR_RIGHT:
    shift_cursor_right();
    yield( SHIFT_DISPLAY_LEFT, 500000 );
    shift_count = 0;
    return;

  case SHIFT_DISPLAY_LEFT:
    shift_display_left();
    ++shift_count;
    if( shift_count == 2 ) {
      yield( SHIFT_DISPLAY_RIGHT, 200000 );
      shift_count = 0;
    }
    else
      yield( SHIFT_DISPLAY_LEFT, 200000 );
    return;

  case SHIFT_DISPLAY_RIGHT:
    shift_display_right();
    ++shift_count;
    if( shift_count == 4 )
      yield( DONE, 200000 );
    else
      yield( SHIFT_DISPLAY_RIGHT, 200000 );
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
    return new hd_two_line();
  else
    return 0;
}

static void
HD44780UTesterDelete( component* c ) {
  delete dynamic_cast<hd_two_line*>(c);
}


// static object
extern const component_library hd2l_tester_component_library;

const component_library hd2l_tester_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & HD44780UTesterListTypes, 
  & HD44780UTesterCreate,
  & HD44780UTesterDelete
};

