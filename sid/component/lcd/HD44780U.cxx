// HD44780U.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "HD44780U.h"

#include <sidso.h>
#include <stdio.h>

using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;
using sidutil::make_attribute;
using sidutil::parse_attribute;

extern void init_rom( unsigned char rom[][8] );
extern void init_rom_japan( unsigned char rom[][8] );
extern void init_rom_europe( unsigned char rom[][8] );
extern void init_rom_5X10( unsigned char rom[][11] );

HD44780U :: HD44780U( bool use_japan_rom ) : 
  busif( this, &(HD44780U::busRead), &(HD44780U::busWrite) ),
  refresh_sync( "refresh-sync", this, &(HD44780U::refresh) ),
  trigger_mgr( this )
{
  int i, j;

  add_pin( "row-col", &row_col_pin );
  add_attribute( "row-col", &row_col_pin, "pin" );
  trigger_mgr.add_watchable_attribute( "row-col" );
  categorize( "row-col", "watchable" );

  add_pin( "FR", &frame_pin );
  add_attribute( "FR", &frame_pin, "pin" );
  trigger_mgr.add_watchable_attribute( "FR" );
  categorize( "FR", "watchable" );

  add_bus( "bus", &busif );

  add_attribute( "IR", &ir, "register" );
  trigger_mgr.add_watchable_value( "IR", &ir );
  categorize( "IR", "watchable" );

  add_attribute( "DR", &dr, "register" );
  trigger_mgr.add_watchable_value( "DR", &dr );
  categorize( "DR", "watchable" );

  add_attribute( "AC", &ac, "register" );
  trigger_mgr.add_watchable_value( "AC", &ac );
  categorize( "AC", "watchable" );

  refresh_period = 500;		// default is 500 msec
  add_attribute( "refresh-period-msec", &refresh_period, "setting" );

  add_attribute_virtual ("state-snapshot", this,
			 &HD44780U::save_state, &HD44780U::restore_state);

  verbose = false;
  add_attribute( "verbose?", &verbose, "setting" );

  current_schedule = NO_SCHED;

  for( i=0; i<ROM_SIZE; i++ )
    for( j=0; j<8; j++ ) rom[i][j] = 0;

  if( use_japan_rom ) {
    init_rom( rom );
    init_rom_japan( rom );
    init_rom_5X10( rom10 );
  }
  else
    init_rom_europe( rom );

  use_europe_rom = !use_japan_rom;

  reset();
}

void
HD44780U :: reset() {
  int i;

  two_lines = 0;
  big_font = 0;
  display = 0;
  cursor = 0;
  blink = 0;
  incr = 1;

  blinking_chars_are_visible = false;
  shift_on_write = false;

  access_cgram = false;
  addr_bound = DRAM_SIZE;

  ac = 0;
  display_offset = 0;

  for( i=0; i<DRAM_SIZE; i++ ) dram[i] = ' ';
  for( i=0; i<CGRAM_SIZE; i++ ) cgram[i] = 0;
}

inline void
HD44780U :: incr_ac() {
  // I don't actually know if ac is supposed to wrap
  ac = ac + incr;
  if( ac == ((host_int_1) -1) )
    ac = addr_bound;
  else if( ac == addr_bound )
    ac = 0;
}

sid::bus::status
HD44780U :: busRead( host_int_4 laddr, host_int_1& data ) {
  int val;

  if( laddr == 0 ) {
    // Read the address counter. Note that the busy flag is never set.
    if( two_lines && !access_cgram && (ac > 0x27) )
      val = ac + 0x18;
    else
      val = ac;

    data = val;
    return sid::bus::ok;
  }
  else if( laddr == 1 ) {
    // Read the data from the DR, adjust AC for next read, and reload DR.
    data = dr;

    incr_ac();

    if( access_cgram )
      dr = cgram[ac];
    else 
      dr = dram[ac];

    // check for triggerpoints
    trigger_mgr.check_and_dispatch();

    return sid::bus::ok;
  }

  return sid::bus::unmapped;
}

sid::bus::status
HD44780U :: busWrite( host_int_4 laddr, host_int_1 data ) {
  if( laddr == 0 ) {
    // write the IR (busy is not used, so don't need to worry about it)
    ir = data;
    execute( ir );
  }
  else if( laddr == 1 ) {
    // Write the data to the DR and from there to DRAM/CGRAM.
    // Then increment AC for next write.
    dr = data;

    if( access_cgram ) {
      // printf( "write CGRAM: 0x%02x\n", dr );

      cgram[ac] = dr;
    }
    else {
      // printf( "write DDRAM %d: 0x%02x (%c)\n", ac, dr, dr );

      dram[ac] = dr;

      if( shift_on_write )
	display_offset += incr;
    }

    incr_ac();
  }
  else
    return sid::bus::unmapped;

  if( blink ) {
    switch( current_schedule ) {
    case REGULAR_SCHED:
      break;			// already set up

    case ONE_TIME_SCHED:
      refresh_sync.cancel();	// cancel current schedule
      // fall-through

    case NO_SCHED:
      // printf( "setting up regular schedule\n" );
      refresh_sync.schedule_regular( refresh_period );
      current_schedule = REGULAR_SCHED;
      break;

    default:
      break;			// ??
    }
  }
  else if( current_schedule == REGULAR_SCHED ) {
    // The blinkin' lights have stopped - cancel the schedule
    refresh_sync.cancel();
    current_schedule = NO_SCHED;
  }

  if( current_schedule == NO_SCHED ) {
   /* We just wrote something, which could change the display.
    * Make sure we refresh it so we can see the change (if any).
    */
    refresh_sync.schedule_irregular( refresh_period );
    current_schedule = ONE_TIME_SCHED;
  }

  // check for triggerpoints
  trigger_mgr.check_and_dispatch ();

  if( verbose )
    cerr << "HD44780U::write - schedule " << current_schedule << endl;

  return sid::bus::ok;
}

void
HD44780U :: execute( unsigned char val ) {
  if( verbose )
    cerr << "HD44780U::execute "
         << make_numeric_attribute (val, ios::hex | ios::showbase)
         << endl;

  if( val == 1 ) {			// clear display
    for( int i=0; i<DRAM_SIZE; i++ )	// perform partial reset
      dram[i] = ' ';

    ac = 0;
    incr = 1;
    access_cgram = false;
    addr_bound = DRAM_SIZE;
    display_offset = 0;
  }
  else if( (val & ~1) == 0x2 ) {	// return home
    ac = 0;
    access_cgram = false;
    addr_bound = DRAM_SIZE;
    display_offset = 0;
  }
  else if( (val & ~3) == 0x4 ) {	// entry mode set
    if( val & 1 )			// shift display on DDRAM writes
      shift_on_write = true;
    else
      shift_on_write = false;

    if( val & 0x2 )
      incr = 1;
    else
      incr = -1;
  }
  else if( (val & ~7) == 0x08 ) {	// display on/off control
    display = val & 4;
    cursor  = val & 2;
    blink   = val & 1;
  }
  else if( (val & ~0x0f) == 0x10 ) {	// cursor/display shift
    switch( (val >> 2) & 0x3 ) {
    case 0:	// shift cursor left
      --ac;
      if( ac == ((host_int_1) -1) )
	ac = addr_bound;
      break;
    case 1:	// shift cursor right
      ++ac;
      if( ac == addr_bound )
	ac = 0;
      break;
    case 2:	// shift display left
      ++display_offset;
      if( two_lines ) {
	if( display_offset >= 40 )
	  display_offset = 0;
      }
      else {
	if( display_offset >= 80 )
	  display_offset = 0;
      }
      break;
    case 3:	// shift display right
      --display_offset;
      if( two_lines ) {
	if( display_offset <= -40 )
	  display_offset = 0;
      }
      else {
	if( display_offset <= -80 )
	  display_offset = 0;
      }
      break;
    }
  }
  else if( (val & ~0x1f) == 0x20 ) {	// function set
    two_lines = val & 0x08;
    big_font  = val & 4;
  }
  else if( (val & ~0x3f) == 0x40 ) {	// set CGRAM address
    ac = val & 0x3f;
    access_cgram = true;
    addr_bound = CGRAM_SIZE;

    dr = cgram[ac];
  }
  else if( (val & ~0x7f) == 0x80 ) {	// set DDRAM address
    val &= 0x7f;

    if( two_lines && (val >= 0x40) )
      ac = val - 0x18;
    else
      ac = val;

    access_cgram = false;
    addr_bound = DRAM_SIZE;

    dr = dram[ac];
  }
}

void
HD44780U :: refresh() {
  int i, j, k;
  unsigned char *cur, bits;
  unsigned addr;
  int last_row;
  bool using_big_font;
  const unsigned char first_5X10 = 0xe0;

  if( verbose )
    cerr << "HD44780U::refresh" << endl;

  frame_pin.drive( 1 );			// start of refresh

  if( !display ) {			// display is off
    frame_pin.drive( 0 );

    // No more refreshes til the display is re-enabled
    refresh_sync.cancel();
    current_schedule = NO_SCHED;

    if( verbose )
      cerr << "HD44780U::refresh - display is off" << endl;

    return;
  }

  if( current_schedule == ONE_TIME_SCHED ) {
    // This is the callback for the scheduler, so our one-time is now.
    current_schedule = NO_SCHED;
  }

  // write the first line
  if( big_font )
    last_row = 11;
  else
    last_row = 8;

  if( verbose )
    cerr << "HD44780U::refresh - first row: ";

  for( i=0; i<8; i++ ) {
    addr = display_offset + i;
    if( (display_offset + i) < 0 ) {
      if( two_lines )
	addr = 0x28 + (display_offset + i);
      else
	addr = 0x50 + (display_offset + i);
    }

    if( (ac == addr) && blink && !blinking_chars_are_visible )
      continue;

    if( dram[addr] < 0x10 ) {
      cur = &(cgram[dram[addr] << 3]);
      using_big_font = (last_row == 11);
    }
    else if( (dram[addr] >= first_5X10) && !use_europe_rom ) {
      cur = &(rom10[dram[addr] - first_5X10][0]);
      using_big_font = (last_row == 11);
    }
    else {
      cur = &(rom[dram[addr]][0]);
      using_big_font = false;
    }

    for( j=0; j<last_row; j++ ) {
      if( (j == last_row-1) && cursor && (ac == addr) )
	bits = 0x1f;
      else if( j>7 && !using_big_font )
	continue;
      else
	bits = cur[j];

      if( verbose && bits )
	cerr << "[" << i << "," << j << "=" 
	     << make_numeric_attribute (bits, ios::hex | ios::showbase)
	     << "]";

      for( k=4; k>=0; k-- ) {
	if( bits & 0x1 )
	  row_col_pin.drive( (j << 16) | (i*5 + k ) );

	bits >>= 1;
      }
    }
  }

  if( verbose )
    cerr << endl;

  if( two_lines ) {
    for( i=0; i<8; i++ ) {
      addr = 0x28 + display_offset + i;
      if( (display_offset + i) < 0 )
	addr = 0x50 + (display_offset + i);

      if( (ac == addr) && blink && !blinking_chars_are_visible )
	continue;

      if( (dram[addr] >= first_5X10) && !use_europe_rom )
	cur = &(rom10[dram[addr] - first_5X10][0]);
      else if( dram[addr] < 0x10 ) 
	cur = &(cgram[dram[addr] << 3]);
      else
	cur = &(rom[dram[addr]][0]);

      for( j=0; j<8; j++ ) {
	if( (j == 7) && cursor && (ac == addr) )
	  bits = 0x1f;
	else
	  bits = cur[j];

	for( k=4; k>=0; k-- ) {
	  if( bits & 0x1 )
	    row_col_pin.drive( ((8 + j) << 16) | (i*5 + k ) );

	  bits >>= 1;
	}
      }
    }
  }

  frame_pin.drive( 0 );

  blinking_chars_are_visible = !blinking_chars_are_visible;
}

string
HD44780U :: save_state() { 
  return make_attribute ( *this );
}

component::status
HD44780U :: restore_state( const string& state)
{
  return parse_attribute( state, *this );
}

ostream& 
operator << ( ostream& op, const HD44780U& copy_obj ) {	      
  op << "IR " << host_int_4 (copy_obj.ir) << ":";
  op << "DR " << host_int_4 (copy_obj.dr) << ":";
  op << "AC " << host_int_4 (copy_obj.ac) << ":";
  op << "Lines " << (host_int_4) copy_obj.two_lines << ":";
  op << "Font " << (host_int_4) copy_obj.big_font << ":";
  op << "Display " << (host_int_4) copy_obj.display << ":";
  op << "Cursor " << (host_int_4) copy_obj.cursor << ":";
  op << "Blink " << (host_int_4) copy_obj.blink << ":";
  op << "Incr " << (host_int_4) copy_obj.incr << ":";

  op << "DDRAM ";
  for (int j=0; j < (DRAM_SIZE - 1); j++ )
     op << (host_int_4) copy_obj.dram[j] << " ";
  op << (host_int_4) copy_obj.dram[DRAM_SIZE - 1] << ":";

  op << "CGRAM ";
  for (int j=0; j < (CGRAM_SIZE - 1); j++ )
     op << (host_int_4) copy_obj.cgram[j] << " ";
  op << (host_int_4) copy_obj.cgram[CGRAM_SIZE - 1] << ":";

  op << "AccessCgram " << copy_obj.access_cgram << ":";
  op << "AddrBound "   << copy_obj.addr_bound << ":";
  op << "DisOffset " << copy_obj.display_offset << ":";
  op << "ShiftOnWrite " << copy_obj.shift_on_write << ":";
  op << "EuropeRom " << copy_obj.use_europe_rom << ":";
  op << "BlinkVisible " << copy_obj.blinking_chars_are_visible << ":";
  op << "CurrSched " << copy_obj.current_schedule << ":";
  op << "RefreshPeriod " << copy_obj.refresh_period << ":";
  op << "RowColPin " << copy_obj.row_col_pin << ":";
  op << "FramePin " << copy_obj.frame_pin;

  return op;
}

#define GET_TOKEN(_str_) {		\
	string token;			\
	ip >> token;			\
	if( token != _str_ ) {		\
	  ip.setstate( ios::badbit );	\
	  return ip;			\
	}}	
	  

#define GET_SEPARATOR	{		\
	char sep;			\
	ip.get( sep );			\
	if( sep != ':' ) {		\
	  ip.setstate( ios::badbit );	\
	  return ip;			\
	}}

istream &
operator >> ( istream& ip, HD44780U& ovwrite_obj ) {
  host_int_4 temp_val;
  int j;

  GET_TOKEN( "IR" );	
  ip >> temp_val;
  ovwrite_obj.ir = temp_val;
  GET_SEPARATOR;	
  
  GET_TOKEN( "DR" );	
  ip >> temp_val;
  ovwrite_obj.dr = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "AC" );	
  ip >> temp_val;
  ovwrite_obj.ac = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "Lines" );	
  ip >> temp_val;
  ovwrite_obj.two_lines = temp_val;
  GET_SEPARATOR;

  GET_TOKEN( "Font" );	
  ip >> temp_val;
  ovwrite_obj.big_font = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "Display" );	
  ip >> temp_val;
  ovwrite_obj.display = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "Cursor" );	
  ip >> temp_val;
  ovwrite_obj.cursor = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "Blink" );	
  ip >> temp_val;
  ovwrite_obj.blink = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "Incr" );	
  ip >> temp_val;
  ovwrite_obj.incr = temp_val;
  GET_SEPARATOR;	

  GET_TOKEN( "DDRAM" );	
  for( j=0; j<DRAM_SIZE; j++) {
    ip >> temp_val;
    ovwrite_obj.dram[j] = temp_val;
  }
  GET_SEPARATOR;	

  GET_TOKEN( "CGRAM" );	
  for( j=0; j<CGRAM_SIZE; j++ ) {
    ip >> temp_val;
    ovwrite_obj.cgram[j] = temp_val;
  }
  GET_SEPARATOR;	

  GET_TOKEN( "AccessCgram" );	
  ip >> ovwrite_obj.access_cgram;
  GET_SEPARATOR;	

  GET_TOKEN( "AddrBound" );
  ip >> ovwrite_obj.addr_bound;
  GET_SEPARATOR;	

  GET_TOKEN( "DisOffset" );
  ip >> ovwrite_obj.display_offset;
  GET_SEPARATOR;	

  GET_TOKEN( "ShiftOnWrite" );
  ip >> ovwrite_obj.shift_on_write;
  GET_SEPARATOR;	

  GET_TOKEN( "EuropeRom" );
  ip >> ovwrite_obj.use_europe_rom;
  GET_SEPARATOR;	

  GET_TOKEN( "BlinkVisible" );
  ip >> ovwrite_obj.blinking_chars_are_visible;
  GET_SEPARATOR;	

  GET_TOKEN( "CurrSched" );
  ip >> ovwrite_obj.current_schedule;
  GET_SEPARATOR;	

  GET_TOKEN( "RefreshPeriod" );
  ip >> ovwrite_obj.refresh_period;
  GET_SEPARATOR;

  GET_TOKEN("RowColPin");
  ip >> ovwrite_obj.row_col_pin;
  GET_SEPARATOR;

  GET_TOKEN("FramePin");
  ip >> ovwrite_obj.frame_pin;

  return ip;
}

// Standard DLL wrapper-stuff

static vector<string>
HD44780U_ListTypes() {
  vector<string> types;

  types.push_back( string( "hw-lcd-hd44780u-a00" ) );
  types.push_back( string( "hw-lcd-hd44780u-a02" ) );

  return types;
}

static component*
HD44780U_Create( const string& typeName ) {
  if( typeName == "hw-lcd-hd44780u-a00" )
    return new HD44780U( true );
  else if( typeName == "hw-lcd-hd44780u-a02" )
    return new HD44780U( false );
  else
    return 0;
}

static void
HD44780U_Delete( component* c ) {
  delete dynamic_cast<HD44780U*>(c);
}

// static object
extern const component_library hd44780u_component_library;

const component_library hd44780u_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & HD44780U_ListTypes, 
  & HD44780U_Create,
  & HD44780U_Delete
};
