// hd-two-line.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HD_TWO_LINE_DEF_H
#define HD_TWO_LINE_DEF_H	1

#include "hd-tester.h"

class hd_two_line : public HD44780U_tester {
private:

  enum {
    DRAW_LOGO = LAST_BASE_STATE,
    NO_DISPLAY,
    SET_CURSOR,
    MOVE_CURSOR,
    SHIFT_CURSOR_LEFT,
    SHIFT_CURSOR_RIGHT,
    SHIFT_DISPLAY_LEFT,
    SHIFT_DISPLAY_RIGHT,
  };

  void init();
  void draw_logo();
  void disable_display();
  void enable_display();
  void enable_cursor();
  void move_cursor();
  void shift_cursor_left();
  void shift_cursor_right();
  void shift_display_right();
  void shift_display_left();

  char curr_char;
  int shift_count;

  virtual void run( host_int_4 );

public:

  hd_two_line() {}

  ~hd_two_line() {}
};

#endif // HD_TWO_LINE_DEF_H
