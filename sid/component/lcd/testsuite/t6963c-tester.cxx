// t-6963-tester.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "t6963c-tester.h"

#include <sidso.h>
#include <stdio.h>
#include <unistd.h>

#define NROWS	6
#define NCOLS	20

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

  state = BASE_TESTS;
  test_str = "Hi Alex!";

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

  reset_auto( STA3 );
}

void
T6963C_tester :: base_tests() {
  int i;
  uchar val;

  cout << "starting T6963C LCD tests" << endl;

  cout << "test 1: write/read external ram" << endl;
  cout << "test 1a) write then read with no increment" << endl;
  set_word_reg( SET_ADP, 0x00, 0x01 );	// adp = 0x100
  write_mem( DWRITE, 0xaa );
  read_mem( DREAD, val );

  if( val != 0xaa ) {
    printf( "read mem, no inc - got %02x != 0xaa\n", val );
    ++fail_count;
  }

  write_mem( DWRITE, 0x55 );
  read_mem( DREAD, val );

  if( val != 0x55 ) {
    printf( "read mem, no inc - got %02x != 0x55\n", val );
    ++fail_count;
  }

  cout << "test 1b) write then read with increment" << endl;
  set_word_reg( SET_ADP, 0x20, 0x0 );
  for( i=0; i<10; i++ )
    write_mem( DWRITE_INC, i+1 );

  set_word_reg( SET_ADP, 0x20, 0x0 );
  for( i=0; i<10; i++ ) {
    read_mem( DREAD_INC, val );

    if( val != i+1 ) {
      printf( "read mem 0x%02x - got %02x != %02x\n", 0x20+i, val, i+1 );
      ++fail_count;
    }
  }

  cout << "test 1c) read with decrement" << endl;
  read_mem( DREAD_DEC, val );	// back-up ADP by one

  for( i=10; i>=0; i-- ) {
    read_mem( DREAD_DEC, val );

    if( val != i ) {
      printf( "read mem 0x%02x - got %02x != %02x\n", 0x20+i-1, val, i );
      ++fail_count;
    }
  }

  cout << "test 1d) auto write/read" << endl;
  set_word_reg( SET_ADP, 0x00, 0x2 );	// adp = 0x200
  send_cmd( SET_AWRITE );
  send_data( 'a' );
  for( i=1; i<10; i++ )
    auto_write( 'a' + i );

  reset_auto( 8 );

  set_word_reg( SET_ADP, 0x00, 0x2 );	// adp = 0x200
  send_cmd( SET_AREAD );
  get_data( val );
  if( val != 'a' ) {
    printf( "auto read - got %02x != 'a'\n", val );
    ++fail_count;
  }

  for( i=1; i<10; i++ ) {
    auto_read( val );

    if( val != ('a' + i) ) {
      printf( "auto_read %d - got %02x != '%c'\n", i, val, 'a'+i );
      ++fail_count;
    }
  }

  reset_auto( 4 );

  cout << "test 1e) bit set/reset" << endl;
  set_word_reg( SET_ADP, 0x01, 0x2 );	// adp = 0x201
  write_mem( DWRITE, 0xff );
  send_cmd( 0xf2 );			// clear bit 2
  read_mem( DREAD, val );

  if( val != 0xfb ) {
    printf( "bit clear - got %02x != 0xfb\n", val );
    ++fail_count;
  }

  set_word_reg( SET_ADP, 0x02, 0x2 );	// adp = 0x201
  write_mem( DWRITE, 0 );
  send_cmd( 0xff );			// set bit 7
  read_mem( DREAD, val );

  if( val != 0x80 ) {
    printf( "bit set - got %02x != 0x80\n", val );
    ++fail_count;
  }
}

void
T6963C_tester :: draw_string() {
  int i;
  uchar val;

  cout << "drawing tests" << endl;

  //intialize the display
  set_word_reg( SET_TXT_HOME, 0x00, 0x00 );
  set_word_reg( SET_TXT_AREA, NCOLS, 0 );
  set_word_reg( SET_GRX_HOME, 0x00, 0x02 );
  set_word_reg( SET_GRX_AREA, NCOLS, 0 );
 
  // mode set: OR mode, internal cgen
  send_cmd( 0x80 );			

  set_word_reg( SET_CURSOR, 0, 0 );		// cursor at [0,0]
  send_cmd( 0xa0 );				// one-line cursor

  // display: text on, graphics off, solid cursor
  send_cmd( 0x96 );

  mem_set( 0, 0, NCOLS*NROWS );			// clear display

  // write a text string
  set_word_reg( SET_ADP, NCOLS+7, 0x00 );	// row 2, col 7
  send_cmd( SET_AWRITE );

  int len = strlen( test_str );
  
  for( i=0; i<len; i++ ) 
    auto_write( test_str[i] - ' ' );
  reset_auto( 8 );

  for( i=len; i>=0; i-- ) {
    read_mem( DREAD_DEC, val );			// back-up ADP by one

    if( val != (test_str[i] - ' ') )
      printf( "test_str[%d] is %02x != %02x\n", i, test_str[i] - ' ', val );
  }

  cout << "should see 'Hi Alex!'" << endl;
}

static char logo[4][8] = { 0, 3, 0x0e, 0x18, 0x33, 0x26, 0x6c, 0x48,	// ul
		     0, 0xc0, 0x70, 0x18, 0xcc, 0x66, 0x36, 0, // ur
		     0x48, 0x6c, 0x26, 0x33, 0x18, 0x0e, 3, 0, // ll
		     0, 0x35, 0x66, 0xcc, 0x18, 0x70, 0xc0, 0 };

void
T6963C_tester :: draw_logo() {
  int i, j;

  // write Cygnus logo to chars 0x80-0x83
  set_word_reg( SET_OFFSET, 2, 0 );
  set_word_reg( SET_ADP, 0, 0x14 );	// cgen area is 0x1400
  send_cmd( SET_AWRITE );
  for( i=0; i<4; i++ )
    for( j=0; j<8; j++ )
      auto_write( logo[i][j] );
  reset_auto( 8 );

  // display logo at row 3, col 10
  set_word_reg( SET_ADP, 2*NCOLS+10, 0 );
  write_mem( DWRITE_INC, 0x80 );	// ul
  write_mem( DWRITE, 0x81 );		// ur

  set_word_reg( SET_ADP, 3*NCOLS+10, 0 );
  write_mem( DWRITE_INC, 0x82 );	// ll
  write_mem( DWRITE, 0x83 );		// lr

  set_word_reg( SET_CURSOR, 1, 0 );		// cursor at [1,0]
  send_cmd( 0xa1 );				// two-line cursor

  cout << "should see cygnus logo" << endl;
}

void
T6963C_tester :: enable_gx() {
  mem_set( 0, 0x200, NROWS*NCOLS*8 );	// clear graphics mem

  send_cmd( 0x9f );			// enable text and graphics
  
  set_word_reg( SET_CURSOR, 0, 1 );	// cursor at [0,1]
  send_cmd( 0xa7 );			// two-line cursor

  cout << "should see no change - but graphics are on, and cursor should be blinking" << endl;
}

static char box[8] = { 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff };

void 
T6963C_tester :: test_or_mode() {
  int i;

  // draw boxes around string
  for( i=0; i<8; i++ ) {
    // to get to the correct position, add (x*NCOLS*bytes/line + y) to base
    unsigned addr = 0x200 + (8+i)*NCOLS + 7;

    set_word_reg( SET_ADP, addr & 0xff, (addr >> 8) );
    send_cmd( SET_AWRITE );
    for( unsigned j=0; j<strlen( test_str ); j++ )
      auto_write( box[i] );
    reset_auto( 8 );
  }
  
  set_word_reg( SET_CURSOR, NCOLS-1, NROWS-1 );	// cursor at lower right
  send_cmd( 0xa2 );				// three-line cursor

  cout << "should see boxes around chars" << endl;
}

void
T6963C_tester :: test_xor_mode() {
  int i;

  // use exor mode to reverse chars
  for( i=0; i<8; i++ ) {
    // to get to the correct position, add (x*NCOLS*bytes/line + y) to base
    unsigned addr = 0x200 + (8+i)*NCOLS + 7;

    mem_set( 0xff, addr, strlen( test_str ) );
  }
  
  send_cmd( 0x81 );	// switch to XOR mode

  set_word_reg( SET_CURSOR, NCOLS, NROWS-1 );	// cursor off screen
  send_cmd( 0xa3 );				// four-line cursor
  send_cmd( 0x9e );				// turn off blinking

  cout << "should see chars in reverse video" << endl;
}

void
T6963C_tester :: test_attr_mode() {
  int i;

  set_word_reg( SET_ADP, 0, 2 );		// graphics home

  for( i=0; i<NROWS*NCOLS; i+=6 ) {
    write_mem( DWRITE_INC, 0 );			// normal	
    write_mem( DWRITE_INC, 5 );			// reverse
    write_mem( DWRITE_INC, 3 );			// inhibit
    write_mem( DWRITE_INC, 8 );			// blinking normal
    write_mem( DWRITE_INC, 0xd );		// blinking reverse
    write_mem( DWRITE_INC, 0xb );		// blinking inhibit
  }

  send_cmd( 0x9c );	// turn on text and graphics
  send_cmd( 0x84 );	// switch to text attribute mode

  cout << "test of text attribute mode" << endl;
}

void
T6963C_tester :: dump_rom() {
  int i;

  mem_set( 0, 0, NROWS*NCOLS );			// clear text mem

  set_word_reg( SET_ADP, 0, 0 );
  send_cmd( SET_AWRITE );
  for( i=0x28; i<0xa0; i++ )
    auto_write( i - 0x20 );
  reset_auto( 8 );

  set_word_reg( SET_CURSOR, NCOLS/2, NROWS/2 );
  send_cmd( 0xa4 );				// four-line cursor

  send_cmd( 0x94 );				// text only, no cursor

  cout << "should see upper and lower case alphabet" << endl;
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
  case BASE_TESTS:
    base_tests();
    draw_string();

    yield( DRAW_LOGO, 100000 );
    return;

  case DRAW_LOGO:
    draw_logo();
    yield( ENABLE_GX, 100000 );
    return;

  case ENABLE_GX:
    enable_gx();
    yield( TST_OR_MODE, 100000 );
    return;

  case TST_OR_MODE:
    test_or_mode();
    yield( TST_XOR_MODE, 100000 );
    return;

  case TST_XOR_MODE:
    test_xor_mode();
    yield( DUMP_ROM, 100000 );
    return;

  case DUMP_ROM:
    dump_rom();
    yield( TST_ATTR_MODE, 1000000 );
    return;

  case TST_ATTR_MODE:
    test_attr_mode();
    yield( DONE, 50000 );
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

