// hd-europe.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HD_EUROPE_DEF_H
#define HD_EUROPE_DEF_H	1

#include "hd-tester.h"

class hd_europe : public HD44780U_tester {
private:

  enum {
    SHOW = LAST_BASE_STATE,
    RESTORE
  };

  void init();
  void show();

  uchar curr_char;
  int shift_count;

  string snap_shot;
  
  virtual void run( host_int_4 );

public:

  hd_europe() {}

  ~hd_europe() {}
};

#endif // HD_EUROPE_DEF_H
