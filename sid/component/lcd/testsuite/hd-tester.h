// hd-tester.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HD44780U_TESTER_DEF_H
#define HD44780U_TESTER_DEF_H	1

#include <sidcomp.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidcomputil.h>

using namespace sid;
using namespace sidutil;
using namespace std;

typedef unsigned char uchar;

class HD44780U_tester : public virtual component,
			public no_bus_component,
			public no_attribute_component,
			public fixed_accessor_map_component,
			public fixed_pin_map_component,
			public fixed_relation_map_component
{
private:
  sid::bus* bus;

  callback_pin<HD44780U_tester> run_ipin;

  int state, next_state;
  unsigned long curr_count, wait_count;

protected:

  output_pin run_opin;

  int fail_count;

  void put( unsigned reg, uchar val );
  uchar get( unsigned reg );

  int curr_state()	{ return state; }

  void yield( int to_state, unsigned long count );
  void yield()		{ this->yield( this->next_state, 0 ); }

  virtual void run( host_int_4 ) {}

  component *lcd;

  enum {
    DONE,
    WAITING,
    INIT,
    LAST_BASE_STATE
  };

  enum {
    LCD_IR = 0,
    LCD_AC = 0,
    LCD_DR = 4
  };

public:

  HD44780U_tester();

  ~HD44780U_tester() {}
};

#endif // HD44780U_TESTER_DEF_H
