// T6963C.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef T6963C_DEF_H
#define T6963C_DEF_H

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidbusutil.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>

using namespace sid;
using namespace sidutil;

static const int ROM_SIZE = 128 + 32;

class T6963C: public virtual component,
	      public fixed_accessor_map_component,
	      public fixed_attribute_map_component,
	      public fixed_bus_map_component,
	      public fixed_pin_map_component,
	      public no_relation_component
{
private:
  // registers
  host_int_1 status;
  host_int_1 cursor_x, cursor_y;
  host_int_1 offset;
  host_int_2 adp;

  host_int_2 graphic_home;
  host_int_2 text_home;
  host_int_1 g_cols, t_cols;

  void set_reg_attr();

 /* Commands with arguments are sent as follows:
  *	check STA0,1 status
  *	send D1
  *	check status
  *	send D2 (optional)
  *	check status (if D2 sent)
  *	send command
  *
  * dbuf1 and dbuf2 are data buffers to hold D1 and D2, respectively
  */
  bool use_first_dbuf;
  unsigned char dbuf1, dbuf2;

  int mode;			// mode set
  bool external_cgen;

  bool cursor_on;		// display mode
  bool cursor_blink_on;
  bool text_on;
  bool graphics_on;

  int num_cursor_lines;

  bool blinking_chars_are_visible;

  // Set if in text attribute mode and at least one char has blink on
  bool need_continuous_refresh;

  // pins

 /* The real chip uses a bunch of strobes to cycle through the pixels.
  * Specifically, these are the LP, HSCP, and LSCP pins. I chose to abstract 
  * these pins into row/col so that we only have to output a pixel if it is on.
  * Specifically, the row and col are multiplexed into a single word, and the
  * row_col pin is only driven if that pixel is on.
  */
  output_pin row_col;		// row/column selector

 /* The frame pin is set on at the beginning of a refresh and turned off at
  * the end.
  */
  output_pin fr;

  // bus
  sid::bus *ex_ram;

  friend class callback_byte_bus<T6963C>;
  callback_byte_bus<T6963C> busif;

 /* The Toshiba specs give the following table for accessing the registers:
  *
  * WR! = L, C/D = H: Command Write, C/D = L: Data Write
  * RD! = L, C/D = H: Status Read,   C/D = L: Data Read
  *
  * So there really isn't an address range in a direct sense. To access the
  * registers, I have assumed that C/D is tied to logical address line A0,
  * so that the latch buffers are accessed as:
  *
  * Logical Address 0: Data buffer
  * Logical Address 1: Command/Status register
  */
  sid::bus::status busRead( host_int_4 laddr, host_int_1& data );
  sid::bus::status busWrite( host_int_4 laddr, host_int_1 data );

  host_int_1 rom[ROM_SIZE][8];

  void executeCommand( unsigned char cmd );

  void refresh();

  // display geometry

 /* hw_rows and hw_cols are hardwired chip inputs derived from the MDS and
  * MD0-3 pins. Note that the text area and graphic area commands can over-
  * ride and refine these settings.
  */
  int hw_rows;
  int hw_cols;

  std::string getDisplayWidth()	{ return make_attribute( hw_cols ); }
  component::status setDisplayWidth( const std::string& s );

  std::string getDisplayHeight()	{ return make_attribute( hw_rows ); }
  component::status setDisplayHeight( const std::string& s );

  // The font-size attribute replaces the FS0 and FS1 pins
  int font_width;

  std::string getFontSize()		{ return make_attribute( font_width ); }
  component::status setFontSize( const std::string& s );

 /* Scheduler stuff. To save on simulation cycles, the screen is only refreshed
  * if necessary. The two conditions used to determine that a refresh is 
  * required are: a) there was a write to the chip (data or control), b) either
  * the cursor or some text is blinking. For (a) we use a one-time refresh,
  * for (b) we use a continuous periodic refresh. The one-time refresh can
  * turn into a periodic refresh if it turns out that we wrote something that
  * enabled blinking.
  */
  friend class sidutil::scheduler_event_subscription<T6963C>;
  sidutil::scheduler_event_subscription<T6963C> refresh_sync;

public:
  enum {
    NO_SCHED,
    ONE_TIME_SCHED,
    REGULAR_SCHED
  };

private:
  int current_schedule;		// one of the above
  host_int_4 refresh_period;	// in milliseconds

  // Triggerpoint manager
  friend class sidutil::self_watcher<T6963C>;
  sidutil::self_watcher<T6963C> trigger_mgr;

  // Virtual pin interfaces between self_watcher and fixed_pin_map_component
  sid::component::status
  pin_factory( const std::string& n ) { return trigger_mgr.create_virtual_pin(n); }

  void
  pin_junkyard( const std::string& n ) { trigger_mgr.destroy_virtual_pin( n ); }

  // State save/restore.
  std::string save_state ();
  component::status restore_state ( const std::string& state );
  friend std::ostream& operator << ( std::ostream& op, const T6963C& copy_obj );
  friend std::istream& operator >> ( std::istream& ip, T6963C& ovwrite_obj );

public:

  T6963C( bool use_japan_rom );

  void reset();

  ~T6963C() {}
};

#endif // T6963C_DEF_H
