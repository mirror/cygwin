// compCodec.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"



basic_codec::basic_codec():
  registers (this, & basic_codec::reg_read, & basic_codec::reg_write),
  rx_sample_pin (this, & basic_codec::rx_sample_pin_handler)
{
  this->tx_count = 0;
  this->rx_count = 0;
  this->rx_buffer = "";
  this->rx_offset = 0;

  add_pin ("rx-sample", & this->rx_sample_pin);
  add_attribute ("rx-sample", & this->rx_sample_pin, "pin");
  add_pin ("tx-sample", & this->tx_sample_pin);
  add_attribute ("tx-sample", & this->tx_sample_pin, "pin");

  add_pin ("rx-mode", & this->rx_mode_pin);
  add_attribute ("rx-mode", & this->rx_mode_pin, "pin");
  add_pin ("rx-pending", & this->rx_pending_pin);
  add_attribute ("rx-pending", & this->rx_pending_pin, "pin");
  add_pin ("tx-mode", & this->tx_mode_pin);
  add_attribute ("tx-mode", & this->tx_mode_pin, "pin");
  add_pin ("tx-pending", & this->tx_pending_pin);
  add_attribute ("tx-pending", & this->tx_pending_pin, "pin");

  add_pin ("config-set", & this->config_set_pin);
  add_attribute ("config-set", & this->config_set_pin, "pin");

  add_bus ("registers", & this->registers);

  add_attribute ("tx-count", & this->tx_count, "register");
  add_attribute ("rx-count", & this->rx_count, "register");
  add_attribute_ro ("rx-buffer", & this->rx_buffer, "register");
  add_attribute_ro ("rx-offset", & this->rx_offset, "register");
}



void
basic_codec::update_txrx_mode_pins ()
{
  if (this->tx_count > 0 && this->tx_mode_pin.recall() == 0)
    this->tx_mode_pin.drive (1);
  if (this->tx_count == 0 && tx_mode_pin.recall() != 0)
    this->tx_mode_pin.drive (0);
  
  if (this->rx_count > 0 && this->rx_mode_pin.recall() == 0)
    {
      this->rx_buffer = "";
      this->rx_offset = 0;
      this->rx_mode_pin.drive (1);
    }
  if (this->rx_count == 0 && rx_mode_pin.recall() != 0)
    {
      this->rx_mode_pin.drive (0);
      this->rx_buffer = "";
      this->rx_offset = 0;
    }

  // XXX: flush processed section of rx_buffer more aggressively
}


bus::status
basic_codec::reg_write (host_int_4 idx, big_int_4 mask, big_int_4 data)
{
  bus::status s = bus::ok;

  switch (idx)
    {
    case 0: // tx-count register
      this->tx_count = (this->tx_count & ~mask) | (data & mask);
      break;

    case 1: // rx-count register
      this->rx_count = (this->rx_count & ~mask) | (data & mask);
      break;

    case 2: // audio-config register
      this->config = (this->config & ~mask) | (data & mask);
      this->config_set_pin.drive (this->config);
      break;

    case 3: // status register
      break;

    case 4: // tx register
      if (this->tx_count > 0)
	{
	  this->tx_sample_pin.drive (data.read_byte (0));
	  this->tx_count --;
	}
      break;

    default:
      s = bus::unmapped;
    }

  this->update_txrx_mode_pins ();

  return s;
}


bus::status
basic_codec::reg_read (host_int_4 idx, big_int_4 mask, big_int_4& data)
{
  bus::status s = bus::ok;

  switch (idx)
    {
    case 0: // tx-count register
      data = this->tx_count;
      break;

    case 1: // rx-count register
      data = this->rx_count;
      break;

    case 2: // audio-config register
      data = this->config;
      break;

    case 3: // status register
      data.write_byte (0, (this->tx_count > 0) ? 1 : 0);
      data.write_byte (1, ((this->rx_count > 0) && 
			   (this->rx_buffer.size() > this->rx_offset)) ? 1 : 0);
      data.write_byte (2, (this->tx_pending_pin.sense() ? 1 : 0));
      data.write_byte (3, (this->rx_pending_pin.sense() ? 1 : 0));
      break;

    case 4: // rx register
      if (this->rx_count > 0)
	{
	  // The buffer accumulates characters at its end.  When
	  // consuming, we don't want to copy string contents downward
	  // for each byte.  Thus this arithmetic trickery.
	  data = 0;
	  if (this->rx_offset >= this->rx_buffer.size())
	    {
	      // UNDERFLOW!
	      cerr << "hw-audio-sid: rx underflow!" << endl;
	    }
	  else
	    {
	      data.write_byte (0, this->rx_buffer[this->rx_offset]);
	      this->rx_offset ++;
	    }
	  this->rx_count --;
	}
      break;

    default:
      s = bus::unmapped;
    }

  this->update_txrx_mode_pins ();

  return s;
}



void
basic_codec::rx_sample_pin_handler (host_int_4 value)
{
  if (this->rx_count > 0)
    this->rx_buffer += (value & 0xFF);
  else
    {
      cerr << "hw-audio-sid: spurious rx!" << endl;;
    }
}
