// compAudio.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"


// Stuff usually defined in mmreg.h 
#ifndef WAVE_FORMAT_ALAW
#define WAVE_FORMAT_ALAW 0x0006
#endif

#ifndef WAVE_FORMAT_MULAW
#define WAVE_FORMAT_MULAW 0x0007
#endif

#ifndef WAVE_FORMAT_ADPCM
#define WAVE_FORMAT_ADPCM 0x0002
#endif



// ----------------------------------------------------------------------------


ostream& 
operator << (ostream& o, const audio_config& c)
{
  o << c.num_bits_per_sample << "-bit";

  o << " ";

  switch (c.encoding) 
    {
    case audio_config::ulaw:
      o << "uLaw"; break;
    case audio_config::alaw:
      o << "aLaw"; break;
    case audio_config::pcm:
      o << "PCM"; break;
    default:
      o << "?"; break;
    }

  o << " ";

  switch (c.num_channels)
    {
    case 1:
      o << "mono"; break;
    case 2:
      o << "stereo"; break;
    default:
      o << "?"; break;
    }

  o << " ";

  o << c.sampling_frequency << "Hz";
  return o;
}


istream& 
operator >> (istream& i, audio_config& c)
{
  // Don't support parsing above string.
  i.setstate (ios::badbit);
  return i;
}



audio_config::audio_config ()
{
  this->num_bits_per_sample = 8;
  this->encoding = audio_config::ulaw;
  this->num_channels = 1;
  this->sampling_frequency = 8000;
}


host_int_4
audio_config::encode () const
{
  return
    ((this->sampling_frequency << 0) & 0x0000FFFF) |
    ((this->num_channels << 16) & 0x00070000) |
    ((static_cast<int>(this->encoding) << 20) & 0x00300000) |
    ((this->num_bits_per_sample << 24) & 0x0F000000);
}


audio_config::audio_config (host_int_4 value)
{
  this->sampling_frequency = (value & 0x0000FFFF) >> 0;
  this->num_channels = (value & 0x00070000) >> 16;
  this->encoding = static_cast<encoding_t>((value & 0x00300000) >> 20);
  this->num_bits_per_sample = (value & 0x0F000000) >> 24;
}



// ----------------------------------------------------------------------------

generic_audio::generic_audio ():
  tx_mode_pin (this, & generic_audio::tx_mode_pin_handler),
  tx_sample_pin (this, & generic_audio::tx_sample_pin_handler),
  rx_mode_pin (this, & generic_audio::rx_mode_pin_handler),
  config_set_pin (this, & generic_audio::config_set_pin_handler),
  reset_pin (this, & generic_audio::reset_pin_handler),
  poll_pin (this, & generic_audio::poll_pin_handler)
{
  this->tx_active_p = false;
  this->rx_active_p = false;
  this->poll_count = 0;
  this->tx_samples_count = 0;
  this->tx_blocks_count = 0;
  this->rx_samples_count = 0;
  this->rx_blocks_count = 0;

  // Use default audio_config

  add_pin ("tx-mode", & this->tx_mode_pin);
  add_attribute ("tx-mode", & this->tx_mode_pin, "pin");
  add_pin ("tx-pending", & this->tx_pending_pin);
  add_attribute ("tx-pending", & this->tx_pending_pin, "pin");
  add_pin ("tx-sample", & this->tx_sample_pin);
  add_attribute ("tx-sample", & this->tx_sample_pin, "pin");
  add_attribute_ro ("tx-mode?", & this->tx_active_p, "register");
  add_attribute_ro ("tx-buffer", & this->tx_buffer, "register");

  add_pin ("rx-mode", & this->rx_mode_pin);
  add_attribute ("rx-mode", & this->rx_mode_pin, "pin");
  add_pin ("rx-pending", & this->rx_pending_pin);
  add_attribute ("rx-pending", & this->rx_pending_pin, "pin");
  add_pin ("rx-sample", & this->rx_sample_pin);
  add_attribute ("rx-sample", & this->rx_sample_pin, "pin");
  add_attribute_ro ("rx-mode?", & this->rx_active_p, "register");
  add_attribute_ro ("rx-buffer", & this->rx_buffer, "register");

  add_attribute_ro ("config", & this->config, "setting");
  add_pin ("config-set", & this->config_set_pin);
  add_attribute ("config-set", & this->config_set_pin, "pin");

  add_pin ("reset", & this->reset_pin);
  add_attribute ("reset", & this->reset_pin, "pin");

  add_pin ("poll", & this->poll_pin);
  add_attribute ("poll", & this->poll_pin, "pin");

  add_attribute ("poll-count", & this->poll_count, "register");
  add_attribute ("tx-blocks-count", & this->tx_blocks_count, "register");
  add_attribute ("tx-samples-count", & this->tx_samples_count, "register");
  add_attribute ("rx-blocks-count", & this->rx_blocks_count, "register");
  add_attribute ("rx-samples-count", & this->rx_samples_count, "register");
}


bool
generic_audio::pending_tx_p ()
{
  return (this->tx_buffer != "");
}


void
generic_audio::update_txrx_pending_pins ()
{
  // possible rising tx-pending edge
  if (this->pending_tx_p ())
    if (this->tx_pending_pin.recall() == 0)
      tx_pending_pin.drive (1);
  
  // possible falling tx-pending edge
  if (! this->pending_tx_p ())
    if (this->tx_pending_pin.recall() != 0)
      tx_pending_pin.drive (0);

  // possible rising rx-pending edge
  if (this->rx_active_p)
    if (this->rx_pending_pin.recall() == 0)
      this->rx_pending_pin.drive (1);

  // possible falling rx-pending edge
  if (! this->rx_active_p)
    if (this->rx_pending_pin.recall() != 0)
      this->rx_pending_pin.drive (0);
}


void
generic_audio::tx_mode_pin_handler (host_int_4 value)
{
  if (value != 0)
    {
      if (this->tx_active_p)
	{
	  cerr << "sid-io-audio: already in tx mode" << endl;
	  return;
	}
      
      bool ok = this->begin_tx (this->config);
      if (! ok)
	{
	  cerr << "sid-io-audio: cannot begin tx" << endl;
	  return;
	}
      
      this->tx_active_p = true;
      this->tx_blocks_count ++;
    }
  else
    {
      if (! this->tx_active_p)
	{
	  cerr << "sid-io-audio: already out of tx mode" << endl;
	  return;
	}

      // try flushing tx-buffer once, as a last gasp measure
      if (this->pending_tx_p ())
	{
	  this->poll_pin_handler (0);
	}

      if (this->pending_tx_p ())
	{
	  cerr << "sid-io-audio: flushing buffers on tx close" << endl;
	  this->tx_buffer = "";
	}

      this->end_tx ();
      this->tx_active_p = false;
    }

  this->update_txrx_pending_pins ();
}


void
generic_audio::rx_mode_pin_handler (host_int_4 value)
{
  if (value != 0)
    {
      if (this->rx_active_p)
	{
	  cerr << "sid-io-audio: already in rx mode" << endl;
	  return;
	}
      
      bool ok = this->begin_rx (this->config);
      if (! ok)
	{
	  cerr << "sid-io-audio: cannot begin rx" << endl;
	  return;
	}
      
      this->rx_active_p = true;
      this->rx_blocks_count ++;
    }
  else
    {
      if (! this->rx_active_p)
	{
	  cerr << "sid-io-audio: already out of rx mode" << endl;
	  return;
	}
      
      this->end_rx ();
      this->rx_active_p = false;
    }

  this->update_txrx_pending_pins ();
}


void
generic_audio::config_set_pin_handler (host_int_4 value)
{
  // Update settings only if we are idle
  if (! (this->rx_active_p || this->tx_active_p))
    this->config = audio_config (value);
}


void
generic_audio::reset_pin_handler (host_int_4)
{
  if (this->rx_active_p)
    {
      this->end_rx ();
      this->rx_active_p = false;
      this->rx_buffer = "";
    }

  if (this->tx_active_p)
    {
      this->end_tx ();
      this->tx_active_p = false;
      this->tx_buffer = "";
    }

  this->update_txrx_pending_pins ();
}



void
generic_audio::tx_sample_pin_handler (host_int_4 value)
{
  if (this->tx_active_p)
    this->tx_buffer += static_cast<unsigned char>((value & 0xFF));
  else
    {
      // cerr << "sid-io-audio: Ignoring unexpected tx sample." << endl;
    }
}



void
generic_audio::poll_pin_handler (host_int_4)
{
  this->poll_count ++;

  if (this->tx_active_p)
    {
      string remains = this->poll_tx (this->tx_buffer);
      this->tx_samples_count += this->tx_buffer.size() - remains.size();
      this->tx_buffer = remains;
    }

  if (this->rx_active_p)
    {
      string rxbuf = this->poll_rx ();
      for (unsigned i=0; i<rxbuf.size(); i++)
	{
	  this->rx_samples_count ++;
	  host_int_1 byte = rxbuf[i];
	  host_int_4 value = byte;
	  this->rx_sample_pin.drive (value);
	}
    }

  this->update_txrx_pending_pins ();
}


// ----------------------------------------------------------------------------


fd_audio::fd_audio()
{
  this->tx_fd = -1;
  this->rx_fd = -1;
  this->devaudio = "/dev/audio";

  add_attribute ("device", & this->devaudio, "setting");
}


fd_audio::~fd_audio()
{
  if (this->rx_fd >= 0)
    close (this->rx_fd);
  if (this->tx_fd >= 0)
    close (this->tx_fd);
}


static void
asyncificate (int fd)
{
  // Make this file descriptor nonblocking.
  // Don't make it O_ASYNC though - we don't care about SIGIO.

  // POSIX way
  int flags = fcntl (fd, F_GETFL, 0);
  flags |= O_NONBLOCK;
  int rc = fcntl (fd, F_SETFL, flags);

  if (rc == -1)
    cerr << "fcntl error: " << std_error_string() << endl;

  // This was necessary for cygwin sockets - see sid/component/consoles/socketio.cxx
#if 0
  // CYGWIN way
  int yes = 1;
  rc = ioctl (fd, FIONBIO, (void*) & yes);

  if (rc == -1)
    cerr << "ioctl error: " << std_error_string() << endl;
#endif
}


bool
fd_audio::begin_tx (const audio_config& c)
{
  assert (this->tx_fd < 0);

  this->tx_fd = open (this->devaudio.c_str(), O_WRONLY);
  if (this->tx_fd < 0)
    {
      cerr << "sid-io-audio: error opening " << devaudio << ": " << std_error_string() << endl;
      return false;
    }

  asyncificate (this->tx_fd);

  bool ok = this->set_audio_config (this->tx_fd, c);
  if (! ok)
    {
      cerr << "sid-io-audio: error setting mode " << c << endl;
      close (this->tx_fd);
      this->tx_fd = -1;
      return false;
    }

  return true;
}


void
fd_audio::end_tx ()
{
  assert (this->tx_fd >= 0);
  close (this->tx_fd);
  this->tx_fd = -1;
}



bool
fd_audio::begin_rx (const audio_config& c)
{
  assert (this->rx_fd < 0);

  this->rx_fd = open (this->devaudio.c_str(), O_RDONLY);
  if (this->rx_fd < 0)
    {
      cerr << "sid-io-audio: error opening " << devaudio << ": " << std_error_string() << endl;
      return false;
    }

  asyncificate (this->rx_fd);
  
  bool ok = this->set_audio_config (this->rx_fd, c);
  if (! ok)
    {
      cerr << "sid-io-audio: error setting mode " << c << endl;
      close (this->rx_fd);
      this->rx_fd = -1;
      return false;
    }

  return true;
}


void
fd_audio::end_rx ()
{
  assert (this->rx_fd >= 0);
  close (this->rx_fd);
  this->rx_fd = -1;
}


static bool
innocent_errno_p (int err)
{
  return ((err == EWOULDBLOCK) 
          || (err == EINPROGRESS)
          || (err == EINTR)
          || (err == EAGAIN));
}


string
fd_audio::poll_tx (const string& txbuf)
{
  if (txbuf.length() == 0)
    return txbuf;

  assert (this->tx_fd >= 0);

  int count = write (this->tx_fd, txbuf.data(), txbuf.length());
  if ((count < 0) && (! innocent_errno_p (errno)))
    {
      cerr << "sid-io-audio: write error: " << std_error_string() << endl;
      // Act as if sample was consumed
      return string();
    }
  else if (count <= 0 && innocent_errno_p (errno))
    {
      // Return entire string for future poll
      return txbuf;
    }
  else if (count == txbuf.length())
    {
      // Everything was sent!
      return string ();
    }
  else
    {
      // Return unsent portion
      return txbuf.substr (count);
    }
}


string
fd_audio::poll_rx ()
{
  assert (this->rx_fd >= 0);

  enum { rx_buffer_size = 65536 } ;
  static char rx_buffer [rx_buffer_size];

  int count = read (this->rx_fd, rx_buffer, rx_buffer_size);
  if ((count < 0) && (! innocent_errno_p (errno)))
    {
      cerr << "sid-io-audio: read error: " << std_error_string() << endl;
      // Act as if nothing was returned
      return string();
    }
  else if (count <= 0 && innocent_errno_p (errno))
    {
      // Try again later
      return string();
    }
  else
    {
      // Return received portion
      return string (rx_buffer, count);
    }
}


// ----------------------------------------------------------------------------


#if defined(SOUND_CYGWIN)

// XXX: CONTINUE HERE

cygwin_audio::cygwin_audio() 
{
  this->waveOut = 0;
  this->waveIn = 0;

  this->rx_buffer_size = 8000;
  add_attribute ("rx-buffer-size", & this->rx_buffer_size, "setting");
  this->rx_buffer_count = 8;
  add_attribute ("rx-buffer-count", & this->rx_buffer_count, "setting");
}


cygwin_audio::~cygwin_audio () 
{
}


bool
cygwin_audio::begin_tx (const audio_config& c) 
{ 
  assert (this->waveOut == 0);

  WAVEFORMATEX win_format;

  switch (c.encoding)
    {
    case audio_config::ulaw:
      win_format.wFormatTag = WAVE_FORMAT_MULAW;
      break;
      
    case audio_config::alaw:
      win_format.wFormatTag = WAVE_FORMAT_ALAW;
      break;

    case audio_config::pcm:
      win_format.wFormatTag = WAVE_FORMAT_PCM;
      break;

    default:
      return false;
    }

  win_format.wBitsPerSample = c.num_bits_per_sample;
  win_format.nChannels = c.num_channels;
  win_format.nSamplesPerSec = c.sampling_frequency;
  win_format.nAvgBytesPerSec = 
    c.sampling_frequency * (c.num_bits_per_sample / 8) * c.num_channels;
  win_format.nBlockAlign = (c.num_bits_per_sample / 8) * c.num_channels;
  win_format.cbSize = 0;

  unsigned res = waveOutOpen (& this->waveOut, WAVE_MAPPER,
			      & win_format, 0, 0L, CALLBACK_NULL);
  if (res || (this->waveOut == 0))
    {
      cerr << "sid-io-audio: waveOutOpen error " << res << endl;
      return false;
    }

  return true; 
}


bool
cygwin_audio::pending_tx_p ()
{
  return generic_audio::pending_tx_p () || (! this->tx_bufs.empty ());
}


void
cygwin_audio::end_tx () 
{
  assert (this->waveOut != 0);  

  unsigned res = waveOutReset (this->waveOut);
  if (res)
    cerr << "sid-io-audio: waveOutReset rc=" << res << endl;

  // Free up tx buffers
  while (! this->tx_bufs.empty())
    {
      win32_audio_tx_buf* b = this->tx_bufs.front();
      delete b;
      this->tx_bufs.pop_front ();
    }

  res = waveOutClose (this->waveOut);
  if (res != 0)
    cerr << "sid-io-audio: waveOutClose rc=" << res << endl;

  this->waveOut = 0;
}



bool
cygwin_audio::begin_rx (const audio_config& c)
{
  assert (this->waveIn == 0);

  WAVEFORMATEX win_format;

  switch (c.encoding)
    {
    case audio_config::ulaw:
      win_format.wFormatTag = WAVE_FORMAT_MULAW;
      break;
      
    case audio_config::alaw:
      win_format.wFormatTag = WAVE_FORMAT_ALAW;
      break;

    case audio_config::pcm:
      win_format.wFormatTag = WAVE_FORMAT_PCM;
      break;

    default:
      return false;
    }

  win_format.wBitsPerSample = c.num_bits_per_sample;
  win_format.nChannels = c.num_channels;
  win_format.nSamplesPerSec = c.sampling_frequency;
  win_format.nAvgBytesPerSec = 
    c.sampling_frequency * (c.num_bits_per_sample / 8) * c.num_channels;
  win_format.nBlockAlign = (c.num_bits_per_sample / 8) * c.num_channels;
  win_format.cbSize = 0;

  unsigned res = waveInOpen (& this->waveIn, WAVE_MAPPER,
			     & win_format, 0, 0L, CALLBACK_NULL);
  if (res || (this->waveIn == 0))
    {
      cerr << "sid-io-audio: waveInOpen error " << res << endl;
      return false;
    }

  // Create rx buffers
  for (unsigned i=0; i<this->rx_buffer_count; i++)
    {
      win32_audio_rx_buf* b = new win32_audio_rx_buf (this->waveIn, this->rx_buffer_size);
      this->rx_bufs.push_back (b);
    }

  // Start receiving into them
  res = waveInStart (this->waveIn);
  if (res)
    {
      cerr << "sid-io-audio: waveInStart error " << res << endl;
    }

  return true; 
}


void
cygwin_audio::end_rx ()
{
  assert (this->waveIn != 0);  

  unsigned res = waveInStop (this->waveIn);
  if (res)
    cerr << "sid-io-audio: waveInStop rc=" << res << endl;

  res = waveInReset (this->waveIn);
  if (res)
    cerr << "sid-io-audio: waveInReset rc=" << res << endl;

  // Free up pending rx buffers
  while (! this->rx_bufs.empty())
    {
      win32_audio_rx_buf* b = this->rx_bufs.front ();
      delete b;
      this->rx_bufs.pop_front ();
    }

  res = waveInClose (this->waveIn);
  if (res)
    cerr << "sid-io-audio: waveInClose rc=" << res << endl;

  this->waveIn = 0;
}


string
cygwin_audio::poll_tx (const string& buf)
{
  // Free up spent tx buffers
  while (! this->tx_bufs.empty())
    {
      win32_audio_tx_buf* b = this->tx_bufs.front();
      if (! b->done_p())
	break;

      delete b;
      this->tx_bufs.pop_front ();
    }

  if (buf.length() == 0)
    return buf;

  win32_audio_tx_buf* b = new win32_audio_tx_buf (this->waveOut, buf);
  this->tx_bufs.push_back (b);
  
  // We always consume entire supplied buffer
  return string ();
}


string
cygwin_audio::poll_rx ()
{
  string everything;

  // Free up pending rx buffers
  while (! this->rx_bufs.empty())
    {
      win32_audio_buf* b = this->rx_bufs.front ();
      if (! b->done_p())
	break;

      everything += b->buffer ();
      delete b;
      this->rx_bufs.pop_front ();

      win32_audio_rx_buf* b2 = new win32_audio_rx_buf (this->waveIn, this->rx_buffer_size);
      this->rx_bufs.push_back (b2);
    }

  return everything;
}


win32_audio_buf::win32_audio_buf (host_int_4 size)
{
  this->block_handle = GlobalAlloc (GMEM_MOVEABLE | GMEM_SHARE, size);
  if (! this->block_handle)
    {
      cerr << "sid-io-audio: GlobalAlloc " << size << " failed." << endl;
      // Act as if we're already done.
      this->header.dwFlags |= WHDR_DONE;
      return;
    }
  this->block_addr = static_cast<HPSTR>(GlobalLock (this->block_handle));

  this->header.lpData = this->block_addr;
  this->header.dwBufferLength = size;
  this->header.dwFlags = 0;
  this->header.dwLoops = 0;
  this->header.dwBytesRecorded = 0;
  this->header.dwUser = 0;
}


win32_audio_buf::~win32_audio_buf ()
{
  if (this->block_handle == 0)
    return;

  GlobalUnlock (this->block_addr);
  GlobalFree (this->block_handle);
}


bool
win32_audio_buf::done_p ()
{
  return (this->header.dwFlags & WHDR_DONE);
}


win32_audio_tx_buf::win32_audio_tx_buf (HWAVEOUT dev, const string& buf):
  win32_audio_buf (buf.length ())
{
  this->device = dev;
  
  // Copy data into this buffer
  memcpy (this->block_addr, buf.data(), buf.length());

  unsigned res = waveOutPrepareHeader (this->device, & this->header, sizeof (this->header));
  if (res)
    {
      cerr << "sid-io-audio: waveOutPrepareHeader error " << res << endl;
      return;
    }

  res = waveOutWrite (this->device, & this->header, sizeof (this->header));
  if (res)
    {
      cerr << "sid-io-audio: waveOutWrite error " << res << endl;
      return;
    }
}


win32_audio_rx_buf::win32_audio_rx_buf (HWAVEIN dev, host_int_4 size):
  win32_audio_buf (size)
{
  this->device = dev;

  unsigned res = waveInPrepareHeader (this->device, & this->header, sizeof (this->header));
  if (res)
    {
      cerr << "sid-io-audio: waveInPrepareHeader error " << res << endl;
      return;
    }

  res = waveInAddBuffer (this->device, & this->header, sizeof (this->header));
  if (res)
    {
      cerr << "sid-io-audio: waveInAddBuffer error " << res << endl;
      return;
    }
}


win32_audio_rx_buf::~win32_audio_rx_buf ()
{
  unsigned res = waveInUnprepareHeader (this->device, & this->header, sizeof (this->header));
  if (res)
    {
      cerr << "sid-io-audio: waveInUnprepareHeader error " << res << endl;
      return;
    }
}


win32_audio_tx_buf::~win32_audio_tx_buf ()
{
  unsigned res = waveOutUnprepareHeader (this->device, & this->header, sizeof (this->header));
  if (res)
    {
      cerr << "sid-io-audio: waveOutUnprepareHeader error " << res << endl;
      return;
    }
}


string
win32_audio_buf::buffer ()
{
  // fetch buffer contents
  string value = string (this->block_addr, this->header.dwBufferLength);
  return value;
}



#endif // CYGWIN
