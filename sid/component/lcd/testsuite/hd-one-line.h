// hd-one-line.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HD_ONE_LINE_DEF_H
#define HD_ONE_LINE_DEF_H	1

#include "hd-tester.h"

class hd_one_line : public HD44780U_tester {
private:
  output_pin refresh;

  enum {
    SCROLL = LAST_BASE_STATE
  };

  void init();
  void draw_char( uchar val );

  uchar curr_char;

  virtual void run( host_int_4 );

public:

  hd_one_line() { add_pin( "force-refresh", &refresh ); }

  ~hd_one_line() {}
};

#endif // HD_ONE_LINE_DEF_H
