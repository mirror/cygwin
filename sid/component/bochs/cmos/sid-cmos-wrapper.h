// sid-cmos-wrapper.h - SID import of the bochs cmos component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_CMOS_WRAPPER_DEF_H
#define SID_CMOS_WRAPPER_DEF_H	1

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
using sid::host_int_4;
using sid::little_int_1;
using sidutil::callback_word_bus;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::input_pin;
using sidutil::callback_control_register;
using sidutil::control_register_bus;
using sidutil::fixed_control_register;

class cmos : public sidutil::fixed_pin_map_component,
             public sidutil::no_accessor_component,
             public sidutil::fixed_attribute_map_component,
             public sidutil::no_relation_component,
             public sidutil::fixed_bus_map_component
{
public:
  cmos();
  ~cmos() throw() {};

  void init(host_int_4);
  void reset(host_int_4);
  void image_load(host_int_4);
  void periodic_timer(host_int_4);
  void one_second_timer(host_int_4);

  void drive_trigger_irq_pin(void);
  void drive_periodic_timer_control_pin(host_int_4 value, bool regular);
  void drive_one_second_timer_control_pin(host_int_4 value, bool regular);
  host_int_4 get_time(void);

protected:

  callback_pin<cmos> init_pin;
  callback_pin<cmos> reset_pin;
  callback_pin<cmos> image_load_pin;
  callback_pin<cmos> periodic_timer_pin;
  callback_pin<cmos> one_second_timer_pin;
  input_pin host_time_pin;

  output_pin trigger_irq_pin;
  output_pin periodic_timer_control_pin;
  output_pin one_second_timer_control_pin;
  output_pin time_query_pin;

  bus::status read_port_0x70_0x71 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x70_0x71 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<cmos, little_int_1> ports_0x70_0x71_bus;

  // register_bus must be declared before the control_registers
  // because member constructors are called in the order in which
  // they're declared
  control_register_bus<little_int_1> register_bus;

  void set_register_0x10 (little_int_1 data, little_int_1 mask);
  little_int_1 get_register_0x10 (void);

  void set_register_0x14 (little_int_1 data, little_int_1 mask);
  little_int_1 get_register_0x14 (void);

  callback_control_register<little_int_1, cmos> register_0x10;
  callback_control_register<little_int_1, cmos> register_0x14;

  bool use_image_file;
  std::string image_file_path;
  host_int_4 cmos_irq_number;
  bool use_host_time;
  host_int_4 start_time;
  bx_cmos_c bx_cmos;
};
#endif // SID_CMOS_WRAPPER_DEF_H
