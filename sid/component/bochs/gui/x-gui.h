// x-gui.h - SID gui front-end to the bochs vga, keyboard and mouse components.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef X_GUI_DEF_H
#define X_GUI_DEF_H	1

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidattrutil.h>
#include <sidcpuutil.h>
#include <sidpinattrutil.h>
#include <sidmiscutil.h>
#include <sidwatchutil.h>
#include <sidso.h>
#include "generic.h"

extern "C" {
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
}

#include "bochs.h"

#define MAX_TEXT_LINES 50
// 640 / 16
#define NUM_X_TILES 40
// 480 / 16
#define NUM_Y_TILES 30

#define MAX_MAPPED_STRING_LENGTH 10

using sid::host_int_4;
using sid::little_int_1;
using sidutil::input_pin;
using sidutil::callback_pin;

class x_gui : public generic_memory,
              public logfunctions
{
public:
  x_gui();
  ~x_gui() throw() {};

  void init(host_int_4);
  void handle_events(host_int_4);
  void update_display(host_int_4);
  void palette_change_index(host_int_4 index);

  struct rgb_data
  {
    host_int_1 red;
    host_int_1 green;
    host_int_1 blue;
  };

protected:

  output_pin generate_scancode_pin;

  callback_pin<x_gui> init_pin;
  callback_pin<x_gui> handle_events_pin;
  callback_pin<x_gui> update_display_pin;
  callback_pin<x_gui> palette_change_index_pin;
  
  input_pin text_memory_updated_pin;
  input_pin text_start_address_pin;
  input_pin text_cursor_x_pin;
  input_pin text_cursor_y_pin;

  input_pin dimension_width_pin;
  input_pin dimension_height_pin;
  input_pin dimensions_updated_pin;

  host_int_4 x_tilesize;
  host_int_4 y_tilesize;

  host_int_1 text_snapshot[2 * 80 * MAX_TEXT_LINES];
  host_int_1 *vga_memory;
  rgb_data *palette_memory;
private:
  void redraw_area(unsigned x0, unsigned y0, unsigned width, unsigned height);
  void xkeypress(KeySym keysym, int press_release);

  void load_font(void);
  std::string font_name;

  bool private_colormap;
};
#endif X_GUI_DEF_H
