// components.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidschedutil.h>

#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include <cstdlib>

#include <unistd.h>
#include <fcntl.h>
#define BSD_COMP
#include <sys/ioctl.h>

#ifdef HAVE_SYS_AUDIOIO_H
#include <sys/audioio.h>
#endif
#ifdef HAVE_SYS_SOUNDCARD_H
#include <sys/soundcard.h>
#endif

#ifdef SOUND_CYGWIN
#include <windows.h>
#ifdef HAVE_MMSYSTEM_H
#include <mmsystem.h>
#endif
#ifdef HAVE_MMREG_H
#include <mmreg.h>
#endif
#endif


using std::deque;
using std::string;
using std::ostream;
using std::istream;
using std::vector;
using std::string;
using std::cerr;
using std::endl;
using std::ios;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_2;
using sid::host_int_4;
using sid::big_int_1;
using sid::big_int_4;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_attribute_map_component;
using sidutil::no_relation_component;
using sidutil::no_accessor_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::no_bus_component;
using sidutil::make_attribute;
using sidutil::make_numeric_attribute;
using sidutil::parse_attribute;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::input_pin;
using sidutil::std_error_string;
using sidutil::callback_word_bus;


// ----------------------------------------------------------------------------



class basic_codec: public virtual component,
		   protected fixed_attribute_map_component,
		   protected no_relation_component,
		   protected fixed_pin_map_component,
		   protected no_accessor_component,
		   protected fixed_bus_map_component
{
public:
  basic_codec ();
  ~basic_codec () {}

private:
  friend class callback_word_bus<basic_codec,big_int_4>;
  callback_word_bus<basic_codec,big_int_4> registers;

  friend class callback_pin<basic_codec>;
  callback_pin<basic_codec> rx_sample_pin;
  output_pin tx_sample_pin;
  output_pin tx_mode_pin, rx_mode_pin;
  input_pin tx_pending_pin, rx_pending_pin;
  output_pin config_set_pin;

  host_int_4 tx_count;

  host_int_4 rx_count;
  string rx_buffer;
  host_int_4 rx_offset;

  host_int_4 config;

private:
  bus::status reg_write (host_int_4 idx, big_int_4 mask, big_int_4 data);
  bus::status reg_read (host_int_4 idx, big_int_4 mask, big_int_4& data);
  void rx_sample_pin_handler (host_int_4);
  
  void update_txrx_mode_pins ();
};



// ----------------------------------------------------------------------------


struct audio_config
{
  host_int_2 num_bits_per_sample;
  enum encoding_t { ulaw, alaw, pcm } encoding;
  host_int_2 num_channels;
  host_int_2 sampling_frequency;

  // Initialize to default
  audio_config ();

  // Encode/decode config state for sid::pin transmission
  audio_config (host_int_4);
  host_int_4 encode () const;
};


// ----------------------------------------------------------------------------


class generic_audio: public virtual component,
		     protected fixed_attribute_map_component,
		     protected no_relation_component,
		     protected fixed_pin_map_component,
		     protected no_accessor_component,
		     protected no_bus_component
{
public:
  generic_audio ();
  ~generic_audio () {}

protected:
  virtual bool begin_tx (const audio_config&) = 0;
  virtual bool pending_tx_p ();
  virtual void end_tx () = 0;
  virtual bool begin_rx (const audio_config&) = 0;
  virtual void end_rx () = 0;
  virtual string poll_tx (const string&) = 0;
  virtual string poll_rx () = 0;

private:
  friend class callback_pin<generic_audio>;

  callback_pin<generic_audio> tx_mode_pin;
  callback_pin<generic_audio> tx_sample_pin;
  bool tx_active_p;
  string tx_buffer;
  output_pin tx_pending_pin;

  callback_pin<generic_audio> rx_mode_pin;
  output_pin rx_sample_pin;
  bool rx_active_p;
  string rx_buffer;
  output_pin rx_pending_pin;

  audio_config config;
  callback_pin<generic_audio> config_set_pin;

  callback_pin<generic_audio> reset_pin;
  callback_pin<generic_audio> poll_pin;

  host_int_4 poll_count;
  host_int_4 tx_samples_count;
  host_int_4 tx_blocks_count;
  host_int_4 rx_samples_count;
  host_int_4 rx_blocks_count;

  void tx_mode_pin_handler (host_int_4);
  void tx_sample_pin_handler (host_int_4);
  void rx_mode_pin_handler (host_int_4);
  void config_set_pin_handler (host_int_4);
  void reset_pin_handler (host_int_4);
  void poll_pin_handler (host_int_4);

  void update_txrx_pending_pins ();
};


// ----------------------------------------------------------------------------


class nop_audio: public generic_audio
{
public:
  nop_audio () {}
  ~nop_audio () {}

private:
  // The inherited virtual functions 
  bool begin_tx (const audio_config&) { return false; }
  void end_tx () {}
  bool begin_rx (const audio_config&) { return false; }
  void end_rx () {}
  string poll_tx (const string&) { return string(); }
  string poll_rx () { return string(); }
};


// ----------------------------------------------------------------------------


class fd_audio: public generic_audio
{
public:
  fd_audio ();
  ~fd_audio ();

protected:
  virtual bool set_audio_config (int, const audio_config&) = 0;

private:
  string devaudio;
  int tx_fd;
  int rx_fd;

  // The inherited virtual functions 
  bool begin_tx (const audio_config&);
  void end_tx ();
  bool begin_rx (const audio_config&);
  void end_rx ();
  string poll_tx (const string&);
  string poll_rx ();
};


class linux_audio: public fd_audio 
{ 
  // XXX
public:
  linux_audio () {}
  ~linux_audio () {}

protected:
  bool set_audio_config (int, const audio_config&) { return true; }
};

class solaris_audio: public fd_audio 
{
public:
  solaris_audio () {}
  ~solaris_audio () {}

  // XXX
  bool set_audio_config (int, const audio_config&) { return true; }
};


// ----------------------------------------------------------------------------


#if defined(SOUND_CYGWIN)

struct win32_audio_buf
{
  WAVEHDR header;
  HANDLE block_handle;
  HPSTR block_addr;

  win32_audio_buf (host_int_4 size);
  virtual ~win32_audio_buf ();

  bool done_p ();
  string buffer ();
};


// Disposable, variable-size transmit buffer
struct win32_audio_tx_buf: public win32_audio_buf
{
  HWAVEOUT device;

  win32_audio_tx_buf (HWAVEOUT dev, const string& buf);
  ~win32_audio_tx_buf ();
};


// Reusable, fixed-size receive buffer
struct win32_audio_rx_buf: public win32_audio_buf
{
  HWAVEIN device;

  win32_audio_rx_buf (HWAVEIN dev, host_int_4 size);
  ~win32_audio_rx_buf ();

};




class cygwin_audio: public generic_audio
{
public:
  cygwin_audio ();
  ~cygwin_audio ();

private:
  host_int_2 rx_buffer_size;
  host_int_1 rx_buffer_count;

  HWAVEOUT waveOut;
  typedef deque<win32_audio_tx_buf*> tx_bufs_t;
  tx_bufs_t tx_bufs;

  HWAVEIN waveIn;
  typedef deque<win32_audio_rx_buf*> rx_bufs_t;
  rx_bufs_t rx_bufs;

  // The inherited virtual functions 
  bool begin_tx (const audio_config&);
  bool pending_tx_p ();
  void end_tx ();
  bool begin_rx (const audio_config&);
  void end_rx ();
  string poll_tx (const string&);
  string poll_rx ();
};

#endif // CYGWIN


// ----------------------------------------------------------------------------


#endif // COMPONENTS_H
