// t6963c-japan.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "t6963c-japan.h"

#include <sidso.h>
#include <stdio.h>
#include <unistd.h>

#define NROWS	8
#define NCOLS	8

enum {
  SET_CURSOR	= 0x21,
  SET_OFFSET	= 0x22,
  SET_ADP	= 0x24,
  SET_TXT_HOME	= 0x40,
  SET_TXT_AREA	= 0x41,
  SET_GRX_HOME	= 0x42,
  SET_GRX_AREA	= 0x43,
  SET_AWRITE	= 0xb0,
  SET_AREAD	= 0xb1,
  CLR_AUTO_RW	= 0xb2,
  DWRITE_INC	= 0xc0,
  DREAD_INC	= 0xc1,
  DWRITE_DEC	= 0xc2,
  DREAD_DEC	= 0xc3,
  DWRITE	= 0xc4,
  DREAD		= 0xc5
};

enum {		// status byte
  STA0	= 0x1,	// set if ready to take next command
  STA1	= 0x2,	// set if memory ready
  STA2	= 0x4,	// set if auto read
  STA3	= 0x8,	// set if auto write
  STA6	= 0x40,	// set if peek/poke error
  STA7	= 0x80,	// set if display on
};

enum {
  DATA_REG	= 0xa0000,
  CMD_REG	= 0xa0004,
  STATUS_REG	= 0xa0004
};

T6963C_tester :: T6963C_tester() : run_ipin( this, &T6963C_tester::run ) {
  add_pin( "run", &run_ipin, &run_opin );
  add_accessor( "bus", &bus );

  lcd = 0;
  add_uni_relation( "lcd", &lcd );

  lcd = 0;
  add_uni_relation( "ddram", &dram );

  state = INIT;
  fail_count = 0;
}

bool 
T6963C_tester :: check_status( uchar what ) {
  big_int_1 val;
  uchar byte;

  if( bus->read( STATUS_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "check_status: read failed\n" );
    return false;
  }

  byte = val;
  if( (byte & what) != what ) {
    ++fail_count;
    printf( "check_status: bad status - got %02x != %02x\n", byte, what );
    return false;
  }

  return true;
}

bool 
T6963C_tester :: send_cmd( uchar cmd ) {
  big_int_1 val = cmd;

  if( !check_status( STA1 | STA0 ) )
    return false;

  if( bus->write( CMD_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "send_cmd: bad write\n" );
    return false;
  }
  
  return true;
}
  
bool 
T6963C_tester :: reset_auto( uchar mode ) {
  big_int_1 val = CLR_AUTO_RW;

  if( !check_status( mode ) )
    return false;

  if( bus->write( CMD_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "reset_auto: bad write\n" );
    return false;
  }
  
  return true;
}
  
bool 
T6963C_tester :: send_data( uchar data ) {
  big_int_1 val = data;

  if( !check_status( STA1 | STA0 ) )
    return false;

  if( bus->write( DATA_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "send_data: bad write\n" );
    return false;
  }
  
  return true;
}
  
bool 
T6963C_tester :: get_data( uchar& data ) {
  big_int_1 val;

  if( !check_status( STA1 | STA0 ) )
    return false;

  if( bus->read( DATA_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "get_data: read failed\n" );
    return false;
  }

  data = val;
  return true;
}

bool 
T6963C_tester :: write_mem( uchar cmd, uchar val ) {
  if( !send_data( val ) )
    return false;

  if( !send_cmd( cmd ) )
    return false;

  return true;
}

bool 
T6963C_tester :: read_mem( uchar cmd, uchar& val ) {
  if( !send_cmd( cmd ) )
    return false;

  return get_data( val );
}

bool 
T6963C_tester :: auto_write( uchar data ) {
  big_int_1 val = data;

  if( !check_status( STA3 ) )
    return false;

  if( bus->write( DATA_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "auto_write failed\n" );
    return false;
  }
  
  return true;
}

bool 
T6963C_tester :: auto_read( uchar& data ) {
  big_int_1 val;

  if( !check_status( STA2 ) )
    return false;

  if( bus->read( DATA_REG, val ) != sid::bus::ok ) {
    ++fail_count;
    printf( "auto_read failed\n" );
    return false;
  }

  data = val;
  return true;
}

bool 
T6963C_tester :: set_word_reg( uchar cmd, uchar lo, uchar hi ) {
  if( !send_data( lo ) )
    return false;

  if( !send_data( hi ) )
    return false;

  if( !send_cmd( cmd ) )
    return false;

  return true;
}

void
T6963C_tester :: mem_set( uchar val, unsigned addr, int len ) {
  set_word_reg( SET_ADP, addr & 0xff, addr >> 8 );
  send_cmd( SET_AWRITE );
 
 for( int i=0; i<len; i++ )
    auto_write( val );

  reset_auto( 8 );
}

void
T6963C_tester :: init() {
  int i;
  uchar val;

  cout << "starting T6963C LCD tests" << endl;

  //intialize the display
  set_word_reg( SET_TXT_HOME, 0x00, 0x00 );
  set_word_reg( SET_TXT_AREA, NCOLS, 0 );
  set_word_reg( SET_GRX_HOME, 0x00, 0x02 );
  set_word_reg( SET_GRX_AREA, NCOLS, 0 );
 
  // mode set: OR mode, internal cgen
  send_cmd( 0x80 );			

  mem_set( 0, 0, NCOLS*NROWS );			// clear display

  // write a text string
  set_word_reg( SET_ADP, 2*NCOLS+1, 0x00 );	// row 2, col 1
  send_cmd( SET_AWRITE );

  char *test_str = "CYGNUS";
  int len = strlen( test_str );

  for( i=0; i<len; i++ ) 
    auto_write( test_str[i] - ' ' );
  reset_auto( 8 );

  set_word_reg( SET_ADP, 4*NCOLS+1, 0x00 );	// row 4, col 1
  send_cmd( SET_AWRITE );

  test_str = "REDHAT";
  len = strlen( test_str );

  for( i=0; i<len; i++ ) 
    auto_write( test_str[i] - ' ' );
  reset_auto( 8 );

  set_word_reg( SET_ADP, 3*NCOLS+4, 0x00 );	// row 3, col 4
  write_mem( DWRITE, '+' - ' ' );
  set_word_reg( SET_ADP, 5*NCOLS+4, 0x00 );	// row 5, col 4
  write_mem( DWRITE, '=' - ' ' );
  set_word_reg( SET_ADP, 6*NCOLS+3, 0x00 );	// row 6, col 3
  write_mem( DWRITE_INC, '$' - ' ' );
  write_mem( DWRITE_INC, 0 );
  write_mem( DWRITE_INC, '?' - ' ' );

  set_word_reg( SET_CURSOR, 3, 6 );		// cursor at [x,y] = 5,6
  send_cmd( 0xa8 );				// 8-line cursor

  // display: text on, graphics off, blinking cursor
  send_cmd( 0x97 );

  cout << "should see 'CYGNUS + REDHAT = $?'" << endl;
}

void
T6963C_tester :: dump_rom() {
  int i;

  mem_set( 0, 0, NROWS*NCOLS );			// clear text mem

  set_word_reg( SET_ADP, 0, 0 );
  send_cmd( SET_AWRITE );
  for( i=0x40; i<0x80; i++ )
    auto_write( i );
  reset_auto( 8 );

  set_word_reg( SET_CURSOR, NCOLS/2, NROWS/2 );
  send_cmd( 0xa0 );				// 1-line cursor

  send_cmd( 0x94 );				// text only, no cursor

  cout << "should Japanese character set" << endl;
}

void
T6963C_tester :: yield( int to_state, unsigned long count ) {
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

void
T6963C_tester :: run( host_int_4 ) {
  switch( state ) {
  case INIT:
    init();
    yield( DISABLE_DISPLAY, 1000000 );
    return;

  case DISABLE_DISPLAY:
    if( !lcd || !dram ) {
      cout << "missing relation to lcd and/or dram" << endl;
      ++fail_count;
    }
    else {
      snap_shot = lcd->attribute_value( "state-snapshot" );
      dram_state = dram->attribute_value( "state-snapshot" );
      cout << "Took a state snapshot" << endl;
    }

    send_cmd( 0x90 );	// disable display
    cout << "Display should now be disabled" << endl;
    yield( ENABLE_DISPLAY, 100000 );
    return;

  case ENABLE_DISPLAY:
    send_cmd( 0x94 );
    cout << "Re-enabled display" << endl;
    yield( DUMP_ROM, 0 );
    return;

  case DUMP_ROM:
    dump_rom();
    yield( RESTORE, 1000000 );
    return;

  case RESTORE:
    {
      component::status rc;

      rc = lcd->set_attribute_value( "state-snapshot", snap_shot );
      if( rc != component::ok ) {
	cout << "lcd restore state failed" << endl;
	++fail_count;
      }
      rc = dram->set_attribute_value( "state-snapshot", dram_state );
      if( rc != component::ok ) {
	cout << "dram restore state failed" << endl;
	++fail_count;
      }

      cout << "state should be restored to snap-shot" << endl;
      yield( DONE, 200000 );
    }
    return;

  case WAITING:
    yield( next_state, 0 );
    return;

  default:
    break;
  }

  cout << "all tests complete: fail count " << fail_count << endl;

  run_opin.drive( 0 );
}

static vector<string>
T6963CTesterListTypes() {
  vector<string> types;
  types.push_back(string("t6963c-tester"));
  return types;
}

static component*
T6963CTesterCreate( const string& typeName ) {
  if(typeName == "t6963c-tester")
    return new T6963C_tester();
  else
    return 0;
}

static void
T6963CTesterDelete( component* c ) {
  delete dynamic_cast<T6963C_tester*>(c);
}


// static object
extern const component_library t6963c_tester_component_library;

const component_library t6963c_tester_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & T6963CTesterListTypes, 
  & T6963CTesterCreate,
  & T6963CTesterDelete
};

