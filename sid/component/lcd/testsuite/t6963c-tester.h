// t6963-tester.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef T6963C_TESTER_DEF_H
#define T6963C_TESTER_DEF_H	1

#include <sidcomp.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidattrutil.h>
#include <sidcomputil.h>

using namespace sid;
using namespace sidutil;
using namespace std;

typedef unsigned char uchar;

class T6963C_tester : public virtual component,
		      public fixed_attribute_map_component,
		      public fixed_accessor_map_component,
		      public fixed_pin_map_component,
		      public no_bus_component,
		      public fixed_relation_map_component
{
private:
  sid::bus* bus;

  callback_pin<T6963C_tester> run_ipin;
  output_pin run_opin;

  int fail_count;

  bool check_status( uchar what );
  bool send_cmd( uchar cmd );

  bool send_data( uchar data );
  bool get_data( uchar& data );

  bool auto_write( uchar data );
  bool auto_read( uchar& data );
  bool reset_auto( uchar mode );

  bool write_mem( uchar cmd, uchar data );
  bool read_mem( uchar cmd, uchar& data );

  bool set_word_reg( uchar cmd, uchar lo, uchar hi );

  void mem_set( uchar val, unsigned addr, int len );

  enum {
    DONE,
    WAITING,
    BASE_TESTS,
    DRAW_LOGO,
    ENABLE_GX,
    TST_OR_MODE,
    TST_XOR_MODE,
    DUMP_ROM,
    TST_ATTR_MODE
  };

  int state, next_state;
  unsigned long curr_count, wait_count;

  char* test_str;

  void yield( int to_state, unsigned long count );

  void base_tests();
  void draw_string();
  void draw_logo();
  void enable_gx();
  void test_or_mode();
  void test_xor_mode();
  void dump_rom();
  void test_attr_mode();

public:

  T6963C_tester();

  void run( host_int_4 );

  ~T6963C_tester() {}
};

#endif // T6963C_TESTER_DEF_H


