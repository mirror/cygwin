// sid-floppy-wrapper.h - SID import of the bochs floppy component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_FLOPPY_WRAPPER_DEF_H
#define SID_FLOPPY_WRAPPER_DEF_H	1

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
using sidutil::input_pin;

class floppy : public sidutil::fixed_pin_map_component,
               public sidutil::fixed_accessor_map_component,
               public sidutil::fixed_attribute_map_component,
               public sidutil::no_relation_component,
               public sidutil::fixed_bus_map_component
{
public:
  floppy();
  ~floppy() throw() {};

  void init(host_int_4);
  void reset(host_int_4);
  void drive_trigger_irq_pin(void);
  void drive_command_delay_control_pin(host_int_4 value, bool regular);
  void channel_request(host_int_4 channel, little_int_1 val);
  bool terminal_count(void);
  host_int_4 dma_channel_number(void);
  void dma_channel(host_int_4 phy_addr);
  void dma_write(host_int_4 addr, little_int_1 data);
  void dma_read(host_int_4 addr, unsigned char *data);
  void command_delay(host_int_4);
protected:

  // read == 1, write == 0
  input_pin read_write_pin;
  callback_pin<floppy> dma_channel_pin;

  input_pin terminal_count_pin;

  callback_pin<floppy> command_delay_pin;
  output_pin command_delay_control_pin;

  output_pin trigger_irq_pin;

  callback_pin<floppy> init_pin;
  callback_pin<floppy> reset_pin;

  bus::status read_port_0x3f2_0x3f7 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3f2_0x3f7 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<floppy, little_int_1> ports_0x3f2_0x3f7_bus;

  bus *cmos_registers_bus;
  bus *dma_channels_bus;
  bus *dma_bus;

  std::string floppy_a_type;
  std::string floppy_b_type;

  std::string floppy_a_path;
  std::string floppy_b_path;

  bool floppy_a_is_inserted;
  bool floppy_b_is_inserted;

  host_int_4 floppy_dma_channel;
  host_int_4 floppy_irq_number;
  bx_floppy_ctrl_c bx_floppy;
};
#endif // SID_FLOPPY_WRAPPER_DEF_H
