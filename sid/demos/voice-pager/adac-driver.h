// adac-driver.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef ADAC_DRIVER_H
#define ADAC_DRIVER_H

#include <string>

using std::string;

class adac_driver
{
  enum codec_regs { tx_count=0, rx_count=1, config=2, status=3, data=4 };
  volatile unsigned int* codec_base;
  inline void write_codec (enum codec_regs regno, unsigned value);
  inline unsigned read_codec (enum codec_regs regno);

  string tx_buf;
  unsigned tx_buf_ptr;
  string rx_buf;

 public:
   adac_driver();
   ~adac_driver();

   void begin_read ();
   void poll_read ();
   unsigned count_available_read () { return rx_buf.size (); }
   string finish_read ();

   void begin_write (const string& sample);
   void poll_write ();
   unsigned count_pending_write () { return tx_buf.size () - tx_buf_ptr; }
   void finish_write ();
};

#endif // ADAC_DRIVER_H

