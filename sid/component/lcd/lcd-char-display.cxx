// lcd-char-display.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidwatchutil.h>

#ifdef HAVE__USR_INCLUDE_CURSES_H
#include "/usr/include/curses.h"
#else
#ifdef HAVE_CURSES_H
#include <curses.h>
#endif
#endif

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using sid::component;
using sid::host_int_2;
using sid::host_int_4;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using namespace sidutil;

class lcd_char_display : public virtual component,
			 public fixed_pin_map_component,
			 public fixed_attribute_map_component,
			 public no_bus_component,
			 public no_accessor_component,
			 public no_relation_component
{
private:

  friend class callback_pin<lcd_char_display>;
  callback_pin<lcd_char_display> row_col_pin;
  callback_pin<lcd_char_display> frame_pin;
  callback_pin<lcd_char_display> init_pin;

  host_int_2 width, height;

  void set_pixel( host_int_4 row_col );

  void new_frame( host_int_4 val );
  void init( host_int_4 );

#if HAVE_CURSES_H && HAVE_CURSES_LIBRARY
  WINDOW *w;
#endif

  // Triggerpoint manager
  friend class self_watcher<lcd_char_display>;
  self_watcher<lcd_char_display> trigger_mgr;

  // Virtual pin interfaces between self_watcher and fixed_pin_map_component
  sid::component::status
  pin_factory( const string& n ) { return trigger_mgr.create_virtual_pin(n); }

  void
  pin_junkyard( const string& n ) { trigger_mgr.destroy_virtual_pin( n ); }

public:

  lcd_char_display();
  ~lcd_char_display() throw ();

  // Save & restore state
  string save_state ();
  component::status restore_state (const string& state);
};

lcd_char_display :: lcd_char_display() : 
  row_col_pin( this, &lcd_char_display::set_pixel ),
  frame_pin( this, &lcd_char_display::new_frame ),
  init_pin( this, &lcd_char_display::init ),
  trigger_mgr( this )
{
  add_pin( "row-col", &row_col_pin );
  add_attribute( "row-col", &row_col_pin, "pin" );
  trigger_mgr.add_watchable_attribute( "row-col" );
  categorize( "row-col", "watchable" );

  add_pin( "FR", &frame_pin );
  add_attribute( "FR", &frame_pin, "pin" );
  trigger_mgr.add_watchable_attribute( "FR" );
  categorize( "FR", "watchable" );

  add_pin( "init", &init_pin );
  add_attribute( "init", &init_pin, "pin" );
  trigger_mgr.add_watchable_attribute( "init" );
  categorize( "init", "watchable" );

  width = 80;
  height = 24;
  add_attribute( "width", &width, "setting" );
  add_attribute( "height", &height, "setting" );

  add_attribute_virtual ("state-snapshot", this,
			 & lcd_char_display::save_state,
			 & lcd_char_display::restore_state);
  
#if HAVE_CURSES_H && HAVE_CURSES_LIBRARY
  initscr();
  w = 0;
#endif
}

lcd_char_display :: ~lcd_char_display() throw () { 
#if HAVE_CURSES_H && HAVE_CURSES_LIBRARY
  endwin(); 
#endif
}

void 
lcd_char_display :: init( host_int_4 ) {
#if HAVE_CURSES_H && HAVE_CURSES_LIBRARY
  if( !w ) {
    w = newwin( height, width, 0, 0 );
    box( w, 0, 0 );
  }
#endif

  trigger_mgr.check_and_dispatch();
}

void
lcd_char_display::set_pixel (host_int_4 val)
{
  int i = val;

  int row = i >> 16;
  int col = i & 0x0ffff;

#if HAVE_CURSES_H && HAVE_CURSES_LIBRARY
  if (!w)
    return;
  mvwaddch( w, row, col, '*' );
#else
  cout << '[' << row << ',' << col << ']';
#endif // HAVE_CURSES_H

  trigger_mgr.check_and_dispatch();
}

void
lcd_char_display::new_frame (host_int_4 val)
{
#if HAVE_CURSES_H && HAVE_CURSES_LIBRARY
  if (!w)
    return;

  if (val == 1)
    werase (w);
  else
    wrefresh (w);
#else
  cout << endl;
#endif

  trigger_mgr.check_and_dispatch();
}

string
lcd_char_display::save_state ( )
{
    return string ("lcd-char");
}

component::status 
lcd_char_display::restore_state(const string& state)
{
   if (state == "lcd-char")
     return component::ok;
   return component::bad_value;
} 

static vector<string>
DevicesListTypes()
{
  vector<string> types;

  types.push_back( string( "hw-lcd-char-display" ) );

  return types;
}

static component*
DevicesCreate(const string& typeName)
{
  if( typeName == "hw-lcd-char-display" )
    return new lcd_char_display();
  else
    return 0;
}

static void
DevicesDelete(component* c)
{
  delete dynamic_cast<lcd_char_display*>(c);
}

// static object
extern const component_library lcd_char_display_component_library;

const component_library lcd_char_display_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & DevicesListTypes, 
  & DevicesCreate,
  & DevicesDelete
};
