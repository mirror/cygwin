// adac-driver.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "adac-driver.h"
#include "mem-map.h"
#include <iostream>

inline void
adac_driver::write_codec (enum codec_regs regno, unsigned value)
{
  unsigned be_value;
  unsigned char* be_value_bytes = (unsigned char *) & be_value;

  be_value_bytes[0] = (value >> 24) & 0xFF;
  be_value_bytes[1] = (value >> 16) & 0xFF;
  be_value_bytes[2] = (value >> 8)  & 0xFF;
  be_value_bytes[3] = (value >> 0)  & 0xFF;

  codec_base [regno] = be_value;
}


inline unsigned
adac_driver::read_codec (enum codec_regs regno)
{
  unsigned be_value;
  unsigned char* be_value_bytes = (unsigned char *) & be_value;
  unsigned value;

  be_value = codec_base [regno];

  value = ((be_value_bytes[0] << 24) | (be_value_bytes[1] << 16) 
	   | (be_value_bytes[2] << 8) | (be_value_bytes[3]));
  return value;
}


adac_driver::adac_driver() 
{
  tx_buf_ptr = 0;
  tx_buf = "";
  rx_buf = "";

  codec_base = (unsigned*) CODEC_BASE;

  write_codec (config, 134291264); // 8-bit uLaw mono 8000Hz
}


adac_driver::~adac_driver()
{
  write_codec (tx_count, 0);
  write_codec (rx_count, 0);
}


void
adac_driver::begin_read ()
{
  write_codec (rx_count, static_cast<unsigned> (-1));
}


void
adac_driver::poll_read ()
{
  unsigned iterations = 1000;
  while (--iterations && read_codec (status) & (0xFF << 16))
    rx_buf += (unsigned char)(read_codec (data) >> 24);
}


string
adac_driver::finish_read ()
{
  write_codec (rx_count, 0);
  string b = rx_buf;
  rx_buf = "";
  return b;
}


void
adac_driver::begin_write (const string& sample)
{
  tx_buf = sample;
  tx_buf_ptr = 0;

  write_codec (tx_count, static_cast<unsigned> (-1));
}


void
adac_driver::poll_write ()
{
  unsigned iterations = 1000;
  if (tx_buf_ptr < tx_buf.size())
    while (--iterations && read_codec (status) & (0xFF << 24))
      {
	write_codec (data, tx_buf[tx_buf_ptr] << 24);
	tx_buf_ptr ++;
      }
}


void
adac_driver::finish_write ()
{
  /* wait for codec to flush previous bytes */
  int pending = 0;
  do
    {
      unsigned s = read_codec (status);
      pending = (s & (0xFF << 8));
    } while (pending);

  write_codec (tx_count, 0);
  tx_buf = "";
  tx_buf_ptr = 0;
}
