// HD44780U.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HD44780U_DEF_H
#define HD44780U_DEF_H	1

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidbusutil.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>

static const int DRAM_SIZE = 80;
static const int CGRAM_SIZE = 64;
static const int ROM_SIZE = 256;

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::cerr;
using std::endl;

using sid::component;
using sid::host_int_1;
using sid::host_int_4;

using namespace sidutil;

class HD44780U: public virtual component,
		public no_accessor_component,
		public fixed_attribute_map_component,
		public no_relation_component,
		public fixed_bus_map_component,
		public fixed_pin_map_component
{
private:

 /* The following pin replaces 58(!) pins on the real chip.
  * Instead of 16 row and 40 column selectors, I encode the row and column
  * on the row_col pin. The pin is only driven if the pixel is on.
  */
  output_pin row_col_pin;	// single pixel on/off at [row,col]

 /* The frame pin is a synthetic pin added to tell the display when a
  * refresh is starting/ending.
  */
  output_pin frame_pin;

  // registers
  host_int_1 ir;		// instruction register
  host_int_1 dr;		// data register
  host_int_1 ac;		// address counter

  // state
  char two_lines;		// two lines if non-zero
  char big_font;		// 5X10 font if non-zero
  char display;			// display on/off
  char cursor;			// cursor on/off
  char blink;			// blink on/off
  char incr;			// incr/decr

  // memory
  host_int_1 dram[DRAM_SIZE];	// data ram
  host_int_1 cgram[CGRAM_SIZE];	// character generator ram
  host_int_1 rom[ROM_SIZE][8];	// stored character rom
  host_int_1 rom10[32][11];	// 5X10 character rom

  bool access_cgram;		// access DDRAM vs CGRAM
  unsigned addr_bound;
  bool use_europe_rom;

  void incr_ac();		// inc/dec ac

  int display_offset;
  bool shift_on_write;

  // bus
  friend class callback_byte_bus<HD44780U>;
  callback_byte_bus<HD44780U> busif;

  sid::bus::status busRead( host_int_4 laddr, host_int_1& data );
  sid::bus::status busWrite( host_int_4 laddr, host_int_1 data );

  void execute( unsigned char );

  // send DDRAM contents to the display
  void refresh();

  friend class scheduler_event_subscription<HD44780U>;
  scheduler_event_subscription<HD44780U> refresh_sync;

  enum {
    NO_SCHED,
    ONE_TIME_SCHED,
    REGULAR_SCHED
  };

  int current_schedule;			// one of the above
  host_int_4 refresh_period;		// in milliseconds

  bool blinking_chars_are_visible;

  // Triggerpoint manager
  friend class self_watcher<HD44780U>;
  self_watcher<HD44780U> trigger_mgr;

  // Virtual pin interfaces between self_watcher and fixed_pin_map_component
  sid::component::status
  pin_factory( const string& n ) { return trigger_mgr.create_virtual_pin(n); }

  void
  pin_junkyard( const string& n ) { trigger_mgr.destroy_virtual_pin( n ); }

  bool verbose;

public:

  HD44780U( bool use_japan_rom );

  void reset();

  ~HD44780U() {}

  // save & restore

  string save_state();
  component::status restore_state( const string& state );

  friend ostream& operator << (ostream& op, const HD44780U& copy_obj);
  friend istream& operator >> (istream& ip, HD44780U& ovwrite_obj);
};

#endif // HD44780U_DEF_H
