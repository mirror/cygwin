// T6963.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "T6963C.h"

#include <sidso.h>
#include <stdio.h>
#include <string>

using namespace std;

enum {		// status byte
  STA0	= 0x1,	// set if ready to take next command
  STA1	= 0x2,	// set if memory ready
  STA2	= 0x4,	// set if auto read
  STA3	= 0x8,	// set if auto write
  STA5  = 0x20, // set if controller enabled
  STA6	= 0x40,	// set if peek/poke error
  STA7	= 0x80,	// set if blink display on
};

enum {
  OR_MODE	= 0,
  XOR_MODE	= 1,
  AND_MODE	= 2,
  TXT_ATTR_MODE = 4
};

extern void init_rom_t6963c( bool japanese, unsigned char rom[][8] );

T6963C :: T6963C( bool use_japan_rom ) : 
  busif( this, &(T6963C::busRead), &(T6963C::busWrite) ),
  refresh_sync( "refresh-sync", this, &(T6963C::refresh) ),
  trigger_mgr( this )
{
  add_pin( "row-col", &row_col );
  add_attribute( "row-col", &row_col, "pin" );
  trigger_mgr.add_watchable_attribute( "row-col" );
  categorize( "row-col", "watchable" );

  add_pin( "FR", &fr );
  add_attribute( "FR", &fr, "pin" );
  trigger_mgr.add_watchable_attribute( "FR" );
  categorize( "FR", "watchable" );

  add_bus( "bus", &busif );

  ex_ram = 0;
  add_accessor( "external-ram", &ex_ram );

  hw_rows = 16;
  hw_cols = 80;
  add_attribute_virtual( "display-width", this,
			 & T6963C::getDisplayWidth, & T6963C::setDisplayWidth,
			 "setting" );
  add_attribute_virtual( "display-height", this,
			 &T6963C::getDisplayHeight, &T6963C::setDisplayHeight,
			 "setting" );

  font_width = 8;
  add_attribute_virtual( "font-width", this,
			 & T6963C::getFontSize, & T6963C::setFontSize,
			 "setting" );

  refresh_period = 1000; // default is 1000 msec
  add_attribute( "refresh-period-msec", &refresh_period, "setting" );

  set_reg_attr();

  cursor_on = false;
  cursor_blink_on = false;
  num_cursor_lines = 1;

  text_on = false;
  graphics_on = false;

  mode = OR_MODE;
  external_cgen = false;

  blinking_chars_are_visible = true;
  need_continuous_refresh = false;

  t_cols = 0;
  g_cols = 0;

  init_rom_t6963c( use_japan_rom, rom );

  reset();

  current_schedule = NO_SCHED;

  // For state saving/restoring
  add_attribute_virtual( "state-snapshot", this,
			 & T6963C::save_state,
			 & T6963C::restore_state );
}

void
T6963C :: set_reg_attr() {
  add_attribute( "SR", &status, "register" );
  trigger_mgr.add_watchable_value( "SR", &status );
  categorize( "SR", "watchable" );

  add_attribute( "X-ADRS", &cursor_x, "register" );
  trigger_mgr.add_watchable_value( "X-ADRS", &cursor_x );
  categorize( "X-ADRS", "watchable" );

  add_attribute( "Y-ADRS", &cursor_y, "register" );
  trigger_mgr.add_watchable_value( "Y-ADRS", &cursor_y );
  categorize( "Y-ADRS", "watchable" );

  add_attribute( "Offset", &offset, "register" );
  trigger_mgr.add_watchable_value( "Offset", &offset );
  categorize( "Offset", "watchable" );

  add_attribute( "ADP", &adp, "register" );
  trigger_mgr.add_watchable_value( "ADP", &adp );
  categorize( "ADP", "watchable" );

  add_attribute( "TH", &text_home, "register" );
  trigger_mgr.add_watchable_value( "TH", &text_home );
  categorize( "TH", "watchable" );

  add_attribute( "GH", &graphic_home, "register" );
  trigger_mgr.add_watchable_value( "GH", &graphic_home );
  categorize( "GH", "watchable" );

  add_attribute( "TA", &t_cols, "register" );
  trigger_mgr.add_watchable_value( "TA", &t_cols );
  categorize( "TA", "watchable" );

  add_attribute( "GA", &g_cols, "register" );
  trigger_mgr.add_watchable_value( "GA", &g_cols );
  categorize( "GA", "watchable" );
}

void
T6963C :: reset() {
  // If I read the spec correctly, reset doesn't change any register values.

  status = STA0 | STA1 | STA5;	// ready to take commands
  if( blinking_chars_are_visible )
    status |= STA7;

  use_first_dbuf = true;
}

sid::bus::status
T6963C :: busRead( host_int_4 laddr, host_int_1& data ) {
  if( laddr == 0 ) {		// read data
    if( status & STA2 ) {	// auto read mode
      if( !ex_ram ) {		// no external ram?
	status &= ~(STA2 | STA1);
	return sid::bus::ok;	// its the ex-ram, not the lcd, thats unmapped
      }

      ex_ram->read( adp, (big_int_1&) data );
      ++adp;
    }
    else
      data = dbuf1;
  }
  else if( laddr == 1 )		// read status
    data = status;
  else
    return sid::bus::unmapped;

  return sid::bus::ok;
}

sid::bus::status
T6963C :: busWrite( host_int_4 laddr, host_int_1 data ) {
  if( laddr == 0 ) {
    if( status & STA3 ) {	// auto write mode
      if( !ex_ram ) {		// no external ram?
	status &= ~(STA3 | STA1);
	return sid::bus::ok;	// its the ex-ram, not the lcd, thats unmapped
      }

      ex_ram->write( adp, big_int_1(data) );
      ++adp;
    }
    else {			// transfer data arg
      if( use_first_dbuf )
	dbuf1 = data;
      else
	dbuf2 = data;

      use_first_dbuf = !use_first_dbuf;
    }
  }
  else if( laddr == 1 ) {
    executeCommand( data );

    use_first_dbuf = true;
  }
  else
    return sid::bus::unmapped;

  if( (cursor_on && cursor_blink_on) || need_continuous_refresh ) {
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
  trigger_mgr.check_and_dispatch();

  return sid::bus::ok;
}

void
T6963C :: executeCommand( unsigned char cmd ) {
  big_int_1 val;

  switch( cmd & 0xf0 ) {
  case 0x20:			// set registers
    switch( cmd & 0x0f ) {
    case 1:			// set cursor pointer
      cursor_x = dbuf1 & 0x7f;
      cursor_y = dbuf2 & 0x1f;
      break;

    case 2:			// set offset reg
      offset = dbuf1;
      break;

    case 4:			// set address reg
      adp = (((unsigned) dbuf2) << 8) | dbuf1;
      break;

    default:
      break;
    }
    break;

  case 0x40:			// set control word
    switch( cmd & 0x0f ) {
    case 0:			// set text home
      text_home = (((unsigned) dbuf2) << 8) | dbuf1;
      break;

    case 1:			// set text area
      t_cols = dbuf1;
      break;

    case 2:			// set graphic home
      graphic_home = (((unsigned) dbuf2) << 8) | dbuf1;
      break;

    case 3:			// set graphic area
      g_cols = dbuf1;
      break;

    default:
      break;
    }
    break;

  case 0x80:	// mode set
    if( cmd & 0x8 ) 
      external_cgen = true;
    else
      external_cgen = false;

    mode = cmd & 0x7;
    break;

  case 0x90:	// display mode
    if( cmd == 0x90 )	// Display off
      status &= ~STA5;
    else
      status |= STA5;

    if( (cmd & 0x2) )
      cursor_on = true;
    else
      cursor_on = false;

    if( (cmd & 0x1) )
      cursor_blink_on = true;
    else
      cursor_blink_on = false;

    if( (cmd & 0x4) )
      text_on = true;
    else
      text_on = false;

    if( (cmd & 0x8) )
      graphics_on = true;
    else
      graphics_on = false;
    break;

  case 0xa0:	// cursor pattern select
    num_cursor_lines = (cmd & 7) + 1;
    break;

  case 0xb0:			// data auto read/write
    switch( cmd & 0x0f ) {
    case 0:			// enable auto write
      status |= STA3;
      break;

    case 1:			// enable auto read
      status |= STA2;
      break;

    case 2:			// clear auto mode
      status &= ~(STA2 | STA3);
      break;

    default:
      break;
    }
    break;

  case 0xc0:			// data read/write
    if( cmd>0xc5 )		// bad opcode
      break;

    if( !ex_ram ) {		// no external ram?
      status &= ~STA1;
      break;
    }

    if( (cmd & 1) ) {		// odd numbers are reads
      ex_ram->read( adp, val );
      dbuf1 = val;

      if( cmd == 0xc1 )
	++adp;
      else if( cmd == 0xc3 )
	--adp;
    }
    else {
      val = dbuf1;
      ex_ram->write( adp, val );
      
      if( cmd == 0xc0 )
	++adp;
      else if( cmd == 0xc2 )
	--adp;
    }
    break;

  case 0xe0:	// screen peek/copy
    cerr << "Screen peek/copy not supported!" << endl;
    break;

  case 0xf0:	// bit set/reset
    {
      unsigned char byte;

      if( ex_ram->read( adp, val ) != sid::bus::ok )
	break;

      byte = val;

      if( cmd & 0x8 )		
	byte |= 1 << (cmd & 7);		// set the bit
      else
	byte &= ~(1 << (cmd & 7));	// clear it

      val = byte;
      ex_ram->write( adp, val );
    }
    break;

  case 0x10:		
    // This is an escape hatch in case you don't want to or can't use the 
    // scheduler.
    refresh();
    break;

  default:
    break;
  }
}

#if 0
void
T6963C :: tick() {
  struct timeval curr;

  if( gettimeofday( &curr, NULL ) == -1 )
    printf( "gettimeofday failed?\n" );

  if( last.tv_sec )
    printf( "tick elapsed %.0lf msec\n", 
	    ((double) (curr.tv_sec - last.tv_sec)*1000.0) 
	    + ((double) (curr.tv_usec - last.tv_usec)/1000.0));

  last = curr;
}
#endif

void
T6963C :: refresh() {
  int i, j;
  int curr_row, curr_col;
  host_int_1 *cur, bits;
  unsigned taddr, gaddr, caddr;
  big_int_1 memval;
  host_int_1 val;
  host_int_1 text_char[8], graphics_char[8];

  fr.drive( 1 );			// start of new frame

  if( !(status & STA5) ) {			// display is off
    fr.drive( 0 );

    // No more refreshes til the display is re-enabled
    refresh_sync.cancel();
    current_schedule = NO_SCHED;

    return;
  }

  if( current_schedule == ONE_TIME_SCHED ) {
    // This is the callback for the scheduler, so our one-time is now.
    current_schedule = NO_SCHED;
  }

  taddr = text_home;
  gaddr = graphic_home;
  need_continuous_refresh = false;

  for( curr_row=0; curr_row<hw_rows; curr_row++ ) {
    if( graphics_on && mode!=TXT_ATTR_MODE )
      gaddr = graphic_home + curr_row*g_cols*8;
 
   /* Near as I can figure, the hardwired column setting is what we use,
    * but it can be over-ridden by the text/graphic area values.
    * I am guessing that the font width affects both equally.
    */
    for( curr_col=0; curr_col<hw_cols; curr_col++ ) {
      if( text_on && curr_col<t_cols ) {
	if( ex_ram->read( taddr, memval ) != bus::ok ) {
	  cerr << "T6963C::refresh - ex_ram read error" << endl;
	  return;
	}

	val = memval;			// read char from display ram

	if( !external_cgen && val<0x80 ) {
	  cur = &(rom[val + ' '][0]);	// char is in the ROM

	  for( j=0; j<8; j++ )
	    text_char[j] = cur[j];
	}
	else {
	  caddr = ((((unsigned) offset) << 8) | val) << 3;

	  for( j=0; j<8; j++ ) {
	    if( ex_ram->read( caddr + j, memval ) != bus::ok )
	      return;

	    text_char[j] = memval;
	  }
	}

       /* move to the next text char. The example in the spec shows that
	* adjacent lines are t_cols apart - not hw_cols apart.
	*/
	++taddr;
      }

      if( graphics_on && curr_col<g_cols ) {
       /* The spec says that in text attribute mode there is one graphics
	* area byte per text area byte. Otherwise, it shows that graphics
	* bytes for a single "character" are g_cols apart, ie. the line 
	* requires g_cols*8 bytes.
	*/
	if( mode == TXT_ATTR_MODE ) {
	  if( ex_ram->read( gaddr, memval ) != bus::ok )
	    return;

	  bits = memval;		// read attribute from graphics area
	}
	else {
	  for( j=0; j<8; j++ ) {
	    if( ex_ram->read( gaddr + j*g_cols, memval ) != bus::ok )
	      return;

	    graphics_char[j] = memval;
	  }
	}

	++gaddr;
      }

     /* We've now got the text block and the graphics block gathered into
      * cur and graphics_char, respectively. Presumably, the OR/XOR/AND
      * modes are only valid if both text and graphics are on. In this case
      * we perform the operation to get the thing we are going to display.
      * In text attribute mode, we examine the graphics char to see how to
      * modify the text char.
      *
      * At the end of this, the thing to display is pointed to by cur,
      * which means there is nothing to be done for text only mode.
      */
      if( !text_on && !graphics_on ) {
	if( !cursor_on )
	  return;

	memset( text_char, 0, 8 );
	cur = text_char;
      }
      if( text_on && !graphics_on )
	cur = text_char;
      if( graphics_on && !text_on )
	cur = graphics_char;
      else if( graphics_on && text_on ) {
	cur = text_char;
	for( j=0; j<8; j++ ) {
	  switch( mode ) {
	  case OR_MODE:
	    graphics_char[j] |= cur[j];
	    break;

	  case XOR_MODE:
	    graphics_char[j] ^= cur[j];
	    break;

	  case AND_MODE:
	    graphics_char[j] &= cur[j];
	    break;

	  case TXT_ATTR_MODE:
	    switch( bits & 0x0f ) {
	    case 3:				// inhibit display
	      graphics_char[j] = 0;
	      break;

	    case 5:				// reverse display
	      graphics_char[j] = ~cur[j];
	      break;

	    case 8:				// blinking normal
	      if( blinking_chars_are_visible )
		graphics_char[j] = cur[j];
	      else
		graphics_char[j] = 0;

	      need_continuous_refresh = true;
	      break;

	    case 0xb:				// blinking inhibit?
	      if( blinking_chars_are_visible )
		graphics_char[j] = 0;
	      else
		graphics_char[j] = 0xff;

	      need_continuous_refresh = true;
	      break;

	    case 0xd:				// blinking reverse
	      if( blinking_chars_are_visible )
		graphics_char[j] = ~cur[j];
	      else
		graphics_char[j] = cur[j];

	      need_continuous_refresh = true;
	      break;

	    default:
	      graphics_char[j] = cur[j];	// normal display
	      break;
	    }
	    break;

	  default:
	    break;
	  } // end switch( mode )
	} // end for( j=0; ... )

	cur = graphics_char;
      } // end if( graphics_on && text_on )

      if( cursor_on
	  && (!cursor_blink_on 
	      || (cursor_blink_on && blinking_chars_are_visible))
	  && (curr_row==cursor_y && curr_col==cursor_x) ) {

	// Cursor is on and visible at this position
	for( i=0; i<num_cursor_lines; i++ )
	  cur[7-i] |= 0xff;
      }

      // draw cur as a font_width by 8 block at [curr_row,curr_col]
      for( i=0; i<8; i++ ) {
	bits = cur[i];

	for( j=font_width-1; j>=0; j-- ) {
	  if( bits & 1 ) {
	    host_int_4 val = ((curr_row*8+i) << 16) | (curr_col*font_width+j);

	    // printf( "[%d %d]", curr_col*font_width + j, curr_row*8 + i );
	    row_col.drive( val );
	  }

	  bits >>= 1;
	}
      }
    } // end curr_col
  } // end curr_row

  fr.drive( 0 );	// end of frame

  blinking_chars_are_visible = !blinking_chars_are_visible;
  if( blinking_chars_are_visible )
    status |= STA7;
  else
    status &= ~STA7;

  if( need_continuous_refresh ) {
    if( current_schedule != REGULAR_SCHED ) {
      refresh_sync.schedule_regular( refresh_period );
      current_schedule = REGULAR_SCHED;
    }
  }
  else if( current_schedule==REGULAR_SCHED && !(cursor_on && cursor_blink_on) )
    refresh_sync.cancel();	// don't need continuous refresh anymore
}

component::status
T6963C :: setDisplayWidth( const string& arg ) {
  int val;
  component::status s = parse_attribute( arg, val );

  if( s == component::ok ) {
    switch( val ) {
    case 32:
    case 40:
    case 64:
    case 80:
      hw_cols = val;
      break;

    default:
      return component::bad_value;
    }
  }

  return s;
}
  
component::status
T6963C :: setDisplayHeight( const string& arg ) {
  int val;
  component::status s = parse_attribute( arg, val );

  if( s == component::ok ) {
    if( val>0 && val<=16 && (val % 2)==0 )
      hw_rows = val;
    else
      return component::bad_value;
  }

  return s;
}
  
component::status
T6963C :: setFontSize( const string& arg ) {
  int val;
  component::status s = parse_attribute( arg, val );

  if( s == component::ok ) {
    if( val>=5 && val<=8 )
      font_width = val;
    else
      return component::bad_value;
  }

  return s;
}

std::string 
T6963C::save_state() {
  return make_attribute( *this );
}

component::status
T6963C::restore_state( const string& state)
{
  return parse_attribute(state, *this);
}

ostream&
operator << ( ostream& op, const T6963C& copy_obj ) {
  op << "Status "  << host_int_4(copy_obj.status)   << ":" ;
  op << "CurX "    << host_int_4(copy_obj.cursor_x) << ":";
  op << "CurY "    << host_int_4(copy_obj.cursor_y) << ":";
  op << "Off "     << host_int_4(copy_obj.offset) << ":";
  op << "ADP "     << copy_obj.adp << ":";
  op << "Ghome "   << copy_obj.graphic_home << ":";
  op << "Thome "   << copy_obj.text_home << ":"; 
  op << "Gcols "   << host_int_1(copy_obj.g_cols) << ":";
  op << "Tcols "   << host_int_1(copy_obj.t_cols) << ":";
  op << "UseFdbuf " << copy_obj.use_first_dbuf << ":";
  op << "Dbuf1 "   << host_int_4 (copy_obj.dbuf1) << ":";
  op << "Dbuf2 "   << host_int_4 (copy_obj.dbuf2) << ":";
  op << "Mode "    << copy_obj.mode << ":";
  op << "ECgen "   << copy_obj.external_cgen << ":";
  op << "Con "     << copy_obj.cursor_on << ":";
  op << "CBl "     << copy_obj.cursor_blink_on <<":";
  op << "Ton "     << copy_obj.text_on << ":";
  op << "Gon "     << copy_obj.graphics_on << ":";
  op << "NCLs "    << copy_obj.num_cursor_lines << ":";
  op << "BChVis "  << copy_obj.blinking_chars_are_visible <<":";
  op << "NCRef "   << copy_obj.need_continuous_refresh << ":";
  op << "HR "     << copy_obj.hw_rows << ":";
  op << "HC "     << copy_obj.hw_cols << ":";
  op << "FWd "    << copy_obj.font_width << ":";
  op << "CSched " << copy_obj.current_schedule << ":";
  op << "RefPer " << copy_obj.refresh_period << ":";
  op << "FrPin "     << copy_obj.fr << ":";
  op << "RowColPin " << copy_obj.row_col;

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

istream&
operator >> ( istream& ip, T6963C& ovwrite_obj ) {
  host_int_4 temp_var = 0;
  string coding;
  char sep;

  GET_TOKEN("Status");
  ip >> temp_var;
  ovwrite_obj.status = temp_var;
  GET_SEPARATOR;

  temp_var = 0;
  GET_TOKEN("CurX");
  ip >> temp_var;
  ovwrite_obj.cursor_x = temp_var;
  GET_SEPARATOR;

  temp_var = 0;
  GET_TOKEN("CurY");
  ip >> temp_var;
  ovwrite_obj.cursor_y = temp_var;
  GET_SEPARATOR;

  GET_TOKEN("Off");
  ip >> temp_var;
  ovwrite_obj.offset = temp_var;
  GET_SEPARATOR;

  GET_TOKEN("ADP");
  ip >> ovwrite_obj.adp;
  GET_SEPARATOR;

  GET_TOKEN("Ghome");
  ip >> ovwrite_obj.graphic_home;
  GET_SEPARATOR;

  GET_TOKEN("Thome");
  ip >> ovwrite_obj.text_home;
  GET_SEPARATOR;

  GET_TOKEN("Gcols");
  ip >> ovwrite_obj.g_cols;
  GET_SEPARATOR;

  GET_TOKEN("Tcols");
  ip >> ovwrite_obj.t_cols;
  GET_SEPARATOR;

  GET_TOKEN("UseFdbuf");
  ip >> ovwrite_obj.use_first_dbuf;
  GET_SEPARATOR;

  temp_var = 0;
  GET_TOKEN("Dbuf1");
  ip >> temp_var;
  ovwrite_obj.dbuf1 = temp_var;
  GET_SEPARATOR;

  temp_var = 0;
  GET_TOKEN("Dbuf2");
  ip >> temp_var;
  ovwrite_obj.dbuf2 = temp_var;
  GET_SEPARATOR;

  GET_TOKEN("Mode");
  ip >> ovwrite_obj.mode;
  GET_SEPARATOR;

  GET_TOKEN("ECgen");
  ip >> ovwrite_obj.external_cgen;
  GET_SEPARATOR;

  GET_TOKEN("Con");
  ip >> ovwrite_obj.cursor_on;
  GET_SEPARATOR;

  GET_TOKEN("CBl");
  ip >> ovwrite_obj.cursor_blink_on;
  GET_SEPARATOR;

  GET_TOKEN("Ton");
  ip >> ovwrite_obj.text_on;
  GET_SEPARATOR;

  GET_TOKEN("Gon");
  ip >> ovwrite_obj.graphics_on;
  GET_SEPARATOR;
  
  GET_TOKEN("NCLs");
  ip >> ovwrite_obj.num_cursor_lines;
  GET_SEPARATOR;

  GET_TOKEN("BChVis");
  ip >> ovwrite_obj.blinking_chars_are_visible;
  GET_SEPARATOR;

  GET_TOKEN("NCRef");
  ip >> ovwrite_obj.need_continuous_refresh;
  GET_SEPARATOR;

  GET_TOKEN("HR");
  ip >> ovwrite_obj.hw_rows;
  GET_SEPARATOR;

  GET_TOKEN("HC");
  ip >> ovwrite_obj.hw_cols;
  GET_SEPARATOR;

  GET_TOKEN("FWd");
  ip >> ovwrite_obj.font_width;
  GET_SEPARATOR;

  GET_TOKEN("CSched");
  ip >> ovwrite_obj.current_schedule;
  GET_SEPARATOR;

  GET_TOKEN("RefPer");
  ip >> ovwrite_obj.refresh_period;
  GET_SEPARATOR;

  GET_TOKEN("FrPin");
  ip >> ovwrite_obj.fr;
  GET_SEPARATOR;

  GET_TOKEN("RowColPin");
  ip >> ovwrite_obj.row_col;

  return ip;
}

// Standard DLL wrapper-stuff

static vector<string>
T6963C_ListTypes() {
  vector<string> types;

  types.push_back( string( "hw-lcd-t6963c-0101" ) );
  types.push_back( string( "hw-lcd-t6963c-0201" ) );

  return types;
}

static component*
T6963C_Create( const string& typeName ) {
  if( typeName == "hw-lcd-t6963c-0101" )
    return new T6963C( false );
  else if( typeName == "hw-lcd-t6963c-0201" )
    return new T6963C( true );
  else
    return 0;
}

static void
T6963C_Delete( component* c ) {
  delete dynamic_cast<T6963C*>(c);
}


// static object
extern const component_library t6963c_component_library;

const component_library t6963c_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & T6963C_ListTypes, 
  & T6963C_Create,
  & T6963C_Delete
};
