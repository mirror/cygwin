// hd-europe.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "hd-europe.h"
#include <sidso.h>

void
hd_europe :: init() {
  put( LCD_IR, 0x38 );		// 2-lines, 5x8 font
  put( LCD_IR, 1 );		// clear display
  put( LCD_IR, 0x0d );		// enable display and blink
  put( LCD_IR, 0x6 );		// increment ac on writes

  curr_char = 0x10;
}

void
hd_europe :: show() {
  int i;

  put( LCD_IR, 0x80 );		// select DDRAM address 0
	
  for( i=0; i<8; i++ )
    put( LCD_DR, curr_char + i );

  put( LCD_IR, 0xc0 );		// select DDRAM address 0x40

  for( i=0; i<8; i++ )
    put( LCD_DR, curr_char + i + 8 );

  if( shift_count < 8 )
    put( LCD_IR, 0x80 + shift_count );	// blink character
  else
    put( LCD_IR, 0xc0 + (shift_count - 8) );

  if( curr_char>=0x20 && curr_char<0x80 )
    cout << "should see European chars '" 
	 << curr_char << "' to '" << (char) (curr_char + 15) << "'"; 
  else
    cout << "should see European chars 0x" << hex
	 << (unsigned) curr_char << " to 0x" << curr_char + 15 << dec;

  if( shift_count < 8 )
    cout << ", pos " << shift_count << " should be blinking";
  cout << endl;

  curr_char += 16;
}

void
hd_europe :: run( host_int_4 ) {
  switch( curr_state() ) {
  case INIT:
    init();
    shift_count = 0;
    yield( SHOW, 0 );
    return;

  case SHOW:
    show();
    ++shift_count;

    if( shift_count == 4 ) {
      snap_shot = lcd->attribute_value( "state-snapshot" );
      cout << "Took a state snapshot" << endl;
    }

    if( shift_count >= 15 )
      yield( RESTORE, 500000 );
    else {
      if( shift_count > 8 ) {
	put( LCD_IR, 0x0c );	// disable blink and cursor

	yield( SHOW, 1000000 );
      }
      else
	yield( SHOW, 500000 );
    }
    return;

  case RESTORE:
    lcd->set_attribute_value( "state-snapshot", snap_shot );
    cout << "state should be restored to snap-shot" << endl;
    yield( DONE, 500000 );
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
    return new hd_europe();
  else
    return 0;
}

static void
HD44780UTesterDelete( component* c ) {
  delete dynamic_cast<hd_europe*>(c);
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

