// sid-vga-wrapper.h - SID import of the bochs vga component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_VGA_WRAPPER_DEF_H
#define SID_VGA_WRAPPER_DEF_H	1

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

#include "bochs.h"

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_4;
using sid::little_int_1;

using sidutil::callback_word_bus;
using sidutil::callback_pin;
using sidutil::output_pin;

class vga : public sidutil::fixed_pin_map_component,
            public sidutil::fixed_accessor_map_component,
            public sidutil::fixed_attribute_map_component,
            public sidutil::no_relation_component,
            public sidutil::fixed_bus_map_component
{
public:
  vga();
  ~vga() throw() {};
  
  void init(host_int_4);
  
  void drive_text_start_address_pin(host_int_4 addr);
  void drive_text_cursor_x_pin(host_int_4 x);
  void drive_text_cursor_y_pin(host_int_4 y);
  void drive_text_memory_updated_pin(void);
  
  void drive_dimension_width_pin(host_int_4 width);
  void drive_dimension_height_pin(host_int_4 height);
  void drive_dimensions_updated_pin(void);

  void drive_palette_change_index_pin(host_int_4 index);

protected:
  callback_pin<vga> init_pin;

  output_pin text_start_address_pin;
  output_pin text_cursor_x_pin;
  output_pin text_cursor_y_pin;
  output_pin text_memory_updated_pin;

  output_pin dimension_width_pin;
  output_pin dimension_height_pin;
  output_pin dimensions_updated_pin;

  output_pin palette_change_index_pin;

  bus::status read_port_0x3b4_0x3b5 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3b4_0x3b5 (host_int_4 addr, little_int_1 mask, little_int_1 data);
  bus::status read_port_0x3ba (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3ba (host_int_4 addr, little_int_1 mask, little_int_1 data);
  bus::status read_port_0x3c0_0x3cf (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3c0_0x3cf (host_int_4 addr, little_int_1 mask, little_int_1 data);
  bus::status read_port_0x3d4_0x3d5 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3d4_0x3d5 (host_int_4 addr, little_int_1 mask, little_int_1 data);
  bus::status read_port_0x3da (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3da (host_int_4 addr, little_int_1 mask, little_int_1 data);
  
  callback_word_bus<vga, little_int_1> ports_0x3b4_0x3b5_bus;
  callback_word_bus<vga, little_int_1> port_0x3ba_bus;
  callback_word_bus<vga, little_int_1> ports_0x3c0_0x3cf_bus;
  callback_word_bus<vga, little_int_1> ports_0x3d4_0x3d5_bus;
  callback_word_bus<vga, little_int_1> port_0x3da_bus;

  bus::status read_mem (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_mem (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<vga, little_int_1> framebuffer_bus;

  bus *cmos_registers_bus;

  bx_vga_c bx_vga;

  // copied from sid/component/memory/generic.h

  host_int_1* buffer;
  host_int_4 buffer_length;
  bool mmapping_p;

  host_int_4 max_buffer_length;
  bool attempt_resize (host_int_4 new_length) throw();

  string get_size_attr ();
  component::status set_size_attr (const string& s);

  string image_file_name;
  callback_pin<vga> imageload_pin;
  void imageload_handler (host_int_4);
  callback_pin<vga> imagestore_pin;
  void imagestore_handler (host_int_4);
  output_pin error_pin;
  callback_pin<vga> imagemmap_pin;
  void imagemmap_handler (host_int_4);
  callback_pin<vga> imagemsync_pin;
  void imagemsync_handler (host_int_4);

};
#endif // SID_VGA_WRAPPER_DEF_H
