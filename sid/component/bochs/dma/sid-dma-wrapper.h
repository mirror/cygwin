// sid-dma-wrapper.h - SID import of the bochs dma component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_DMA_WRAPPER_DEF_H
#define SID_DMA_WRAPPER_DEF_H	1

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

using sid::bus;
using sid::component;
using sid::host_int_4;
using sid::little_int_1;
using sidutil::callback_pin;
using sidutil::callback_word_bus;
using sidutil::output_pin;

class dma : public sidutil::fixed_pin_map_component,
            public sidutil::fixed_accessor_map_component,
            public sidutil::fixed_attribute_map_component,
            public sidutil::no_relation_component,
            public sidutil::fixed_bus_map_component
{
public:
  dma();
  ~dma() throw() {};

  void init(host_int_4);

  void hold_acknowledge(host_int_4);

  void drive_hold_request_pin(host_int_4 value);
  void drive_terminal_count_pin(host_int_4 value);

  void drive_channel_pin(host_int_4 channel, host_int_4 value, bool read_mode);
protected:

  output_pin hold_request_pin;
  output_pin terminal_count_pin;

  callback_pin<dma> init_pin;
  callback_pin<dma> hold_acknowledge_pin;

  // Some ports in these ranges are not valid DMA ports.
  bus::status read_port_0x00_0x0f (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x00_0x0f (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0x81_0x8d (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x81_0x8d (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0x8f (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x8f (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0xc0_0xde (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0xc0_0xde (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<dma, little_int_1> ports_0x00_0x0f_bus;
  callback_word_bus<dma, little_int_1> ports_0x81_0x8d_bus;
  callback_word_bus<dma, little_int_1> port_0x8f_bus;
  callback_word_bus<dma, little_int_1> ports_0xc0_0xde_bus;

  bus::status channel_read_request(host_int_4 channel, little_int_1 mask, little_int_1 &val);
  bus::status channel_write_request(host_int_4 channel, little_int_1 mask, little_int_1 val);

  callback_word_bus<dma, little_int_1> channels_bus;

  // read == 1, write == 0
  output_pin read_write_pin;
  output_pin channel_pin[8];

  bx_dma_c bx_dma;
};
#endif // SID_DMA_WRAPPER_DEF_H
