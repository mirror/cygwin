// hd-5X10.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HD_5X10_DEF_H
#define HD_5X10_DEF_H	1

#include "hd-tester.h"

class hd_5X10 : public HD44780U_tester {
private:

  output_pin refresh;

  enum {
    INIT_2 = LAST_BASE_STATE,
    INIT_3,
    SCROLL_LEFT,
    SCROLL_RIGHT,
  };

  void init();
  void init_2();
  void init_3();

  void draw_char( uchar val );

  char str[4];
  int curr_char;

  virtual void run( host_int_4 );

public:

  hd_5X10() { add_pin( "force-refresh", &refresh ); }

  ~hd_5X10() {}
};

#endif // HD44780U_TESTER_DEF_H
