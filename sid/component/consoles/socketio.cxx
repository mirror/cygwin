// socketio.cxx - A console that uses a socket to do its I/O.
// -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"

#ifndef INADDR_NONE
#define INADDR_NONE ((unsigned long int) 0xffffffff)
#endif


std::ostream& 
operator << (std::ostream& o, const sockaddr_in& it)
{
  const char* ipaddr = inet_ntoa (it.sin_addr);
  // XXX: use gethostbyaddr ?
  unsigned short port = ntohs (it.sin_port);
  std::string portstr = sidutil::make_numeric_attribute (port);
  o << ipaddr << ":" << portstr;
  return o;
}


std::istream&
operator >> (std::istream& i, sockaddr_in& it)
{
  std::string s;
  i >> s;
  std::vector<std::string> tokens = sidutil::tokenize(s, ":");

  if (tokens.size() != 2)
    i.setstate (std::ios::badbit);
  else
    {
      struct in_addr addr;

#ifdef HAVE_INET_ATON
      int rc = inet_aton (tokens[0].c_str(), & addr);
      if (rc == 0) // NB: rc is of reverse polarity
	i.setstate (std::ios::badbit);	
#elif HAVE_INET_ADDR
      addr.s_addr = inet_addr (tokens[0].c_str());
      if (addr.s_addr == htonl(INADDR_NONE))
	i.setstate (std::ios::badbit);
#else
#error "Need inet_aton or inet_addr!"
#endif
      // XXX: use gethostbyname ?

      unsigned short port;
      sid::component::status s = sidutil::parse_attribute(tokens[1], port);
      if (s != sid::component::ok)
	i.setstate (std::ios::badbit);
      else
	{
	  it.sin_family = AF_INET;
	  it.sin_addr = addr;
	  it.sin_port = htons (port);
	}
    }

  return i;
}


namespace console_stuff
{


socketio::socketio(bool s):
  recursion_limited ("socket polling", 1),
  init_pin (this, & socketio::init_handler),
  fini_pin (this, & socketio::fini_handler),
  out_pin (this, & socketio::tx_handler),
  poll_control ("poll", this, & socketio::poll)
{
  // defaults
  this->server_p = s;
  this->verbose_p = false;
  this->trace_traffic_p = false;
  this->sock_name.sin_family = AF_INET;
  this->sock_name.sin_port = htons (0);
  this->sock_name.sin_addr.s_addr = htonl (INADDR_ANY);
  this->peer_name.sin_family = AF_INET;
  this->peer_name.sin_port = htons (0);
  this->peer_name.sin_addr.s_addr = htonl (INADDR_ANY);
  this->fd = -1;
  this->serv_fd = -1;
  this->connected_p = false;
  this->buffer_disconnected_p = true;
  this->poll_interval = 100; // default: 100 ms
  this->max_poll_interval = 250; // default: 250 ms
  this->in_count = this->out_count = 0;
  this->poll_count = 0;
  this->avg_out_buffer_size = 0.0;
  
  add_pin ("init", & this->init_pin);
  add_attribute ("init", & this->init_pin, "pin");
  add_pin ("fini", & this->fini_pin);
  add_attribute ("fini", & this->fini_pin, "pin");
  add_pin ("tx", & this->out_pin);
  add_attribute ("tx", & this->out_pin, "pin");
  add_attribute_ro ("tx-count", & this->out_count, "register");
  add_attribute_ro ("tx-buffer", & this->out_buffer, "register");
  add_pin ("rx", & this->in_pin);
  add_attribute ("rx", & this->in_pin, "pin");
  add_attribute_ro ("rx-count", & this->in_count, "register");
  add_attribute_ro ("poll-count", & this->poll_count, "register");
  add_attribute_ro ("avg-tx-buffer-size", & this->avg_out_buffer_size, "register");

  add_attribute_ro ("server?", & this->server_p, "setting");
  if (this->server_p)
    {
      add_attribute ("sockaddr-local", & this->sock_name, "setting");
      add_attribute_ro ("sockaddr-peer", & this->peer_name, "register");
    }
  else
    {
      add_attribute_ro ("sockaddr-local", & this->sock_name, "register");
      add_attribute ("sockaddr-peer", & this->peer_name, "setting");
    }
  
  // add_attribute_ro ("server?", & this->server_p, "setting");
  add_attribute ("verbose?", & this->verbose_p, "setting");
  add_attribute ("trace-traffic?", & this->trace_traffic_p, "setting");
  add_attribute ("buffer-while-disconnected?", & this->buffer_disconnected_p, "setting");
  add_attribute_ro ("connected?", & this->connected_p, "register");
  add_attribute_notify ("max-poll-interval", & this->max_poll_interval,
			this, & socketio::update_poll_interval, "setting");
  add_attribute_notify ("poll-interval", & this->poll_interval,
			this, & socketio::update_poll_interval, "register");
  
  add_attribute_virtual ("state-snapshot", this,
			 & socketio::save_state,
			 & socketio::restore_state);
}
  
  
  // ----------------------------------------------------------------------------


  void
  socketio::update_poll_interval ()
{
  this->poll_control.cancel();

  // clamp it between upper & lower limits
  if (this->poll_interval < 1) 
    this->poll_interval = 1;
  if (this->max_poll_interval < 1)
    this->max_poll_interval = 1;
  if (this->poll_interval > this->max_poll_interval) 
    this->poll_interval = this->max_poll_interval;

  this->poll_control.schedule_irregular (this->poll_interval);
}

  
  void 
  socketio::init_handler (host_int_4)
{
  // This used to be just an assert, but a misguided user could tickle
  // the init pin directly...
  if (this->fd >= 0 || this->serv_fd >= 0)
    {
      cerr << "socketio: illegal init after initialization" << endl;
      return;
    }

  assert (this->fd < 0);
  assert (this->serv_fd < 0);

  this->fd = socket (PF_INET, SOCK_STREAM, 0);
  if (this->fd < 0)
    {
      cerr << "socket error: " << std_error_string() << endl;
      return;
    }

  if (this->verbose_p)
    cout << "socketio: using fd " << this->fd << endl;

  // set options
  int on = 1;
  on = 1;
  setsockopt (this->fd, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof (on));

  // bind; even if INADDR_ANY & port 0
  this->sock_name.sin_family = AF_INET;
  int rc = bind (this->fd, 
		 reinterpret_cast<sockaddr*>(& this->sock_name),
		 sizeof (this->sock_name));
  if (rc != 0)
    cerr << "bind error: " << std_error_string() << endl;

  // prepare for service
  if (this->server_p)
    {
      // save server-socket fd
      this->serv_fd = this->fd;
      this->fd = -1;

      int rc = listen (this->serv_fd, 1);
      if (rc != 0)
	cerr << "listen error: " << std_error_string() << endl;

      this->asyncificate (this->serv_fd);

      // get local binding
#ifdef HAVE_SOCKLEN_T
      socklen_t addrlen;
#else
      int addrlen;
#endif
      addrlen = sizeof (struct sockaddr_in);
      rc = getsockname (this->serv_fd, 
			reinterpret_cast<sockaddr*>(& this->sock_name),
			& addrlen);
      if (rc != 0)
	cerr << "getsockname error: " << std_error_string() << endl;

      if (this->verbose_p)
	cout << "socketio: server at " << this->sock_name << endl;
    }
  else
    {
      this->asyncificate (this->fd);

      // get local binding
#ifdef HAVE_SOCKLEN_T
      socklen_t addrlen;
#else
      int addrlen;
#endif
      addrlen = sizeof (struct sockaddr_in);
      int rc = getsockname (this->fd, 
			    reinterpret_cast<sockaddr*>(& this->sock_name),
			    & addrlen);
      if (rc != 0)
	cerr << "getsockname error: " << std_error_string() << endl;

      if (this->verbose_p)
	cout << "socketio: client at " << this->sock_name << endl;
    }

  // start polling
  this->poll_control.schedule_irregular (this->poll_interval);
}



  void 
  socketio::asyncificate (int fd)
{
  // Disable transmit coalescing
  int on = 1;
  int rc = setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, (char*)&on, sizeof (on));
  if (rc)
    cerr << "setsockopt TCP_NODELAY error: " << std_error_string() << endl;

  on = 1;
  rc = setsockopt (fd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof (on));
  if (rc)
    cerr << "setsockopt SO_KEEPALIVE error: " << std_error_string() << endl;

  // Make this file descriptor nonblocking.
  // Don't make it O_ASYNC though - we don't care about SIGIO.

  // POSIX way
  int flags = fcntl (fd, F_GETFL, 0);
  flags |= O_NONBLOCK;
  rc = fcntl (fd, F_SETFL, flags);

  if (rc == -1)
    cerr << "fcntl error: " << std_error_string() << endl;

  // CYGWIN way
  int yes = 1;
  rc = ioctl (fd, FIONBIO, (void*) & yes);

  if (rc == -1)
    cerr << "ioctl error: " << std_error_string() << endl;
}


void 
socketio::fini_handler (host_int_4)
{
  this->poll_control.cancel ();

  if (this->connected_p)
    {
      assert (this->fd >= 0);
      int rc = shutdown (this->fd, 2); // shut down sending & receiving
      if (rc != 0)
	cerr << "shutdown error: " << std_error_string() << endl;
      this->connected_p = false;
    }
  if (this->fd >= 0)
    {
      int rc = close (this->fd);
      if (rc != 0)
	cerr << "close error: " << std_error_string() << endl;
      this->fd = -1;
    }
  if (this->serv_fd >= 0)
    {
      int rc = close (this->serv_fd);
      if (rc != 0)
	cerr << "close error: " << std_error_string() << endl;
      this->serv_fd = -1;
    }
}
  

void 
socketio::tx_handler (host_int_4 value)
{
  // extract byte or EOF command
  char byte = (value & 0x00FF);
  if (value & ~0x00FF)
    return this->tx_eof_handler ();

  if (! this->connected_p && ! this->buffer_disconnected_p)
    return;

  // append bottom byte to tx buffer
  this->out_buffer += byte;

  // calculate a moving average
  this->avg_out_buffer_size = 
    ((0.99 * this->avg_out_buffer_size) +
     (0.01 * this->out_buffer.length()));
}


void 
socketio::tx_eof_handler ()
{
  if (! this->connected_p)
    return;

  // eof
  if (this->server_p)
    {
      int rc = shutdown (this->fd, 2); // shut down sending & receiving
      if (rc != 0)
	cerr << "shutdown error: " << std_error_string() << endl;
      rc = close (this->fd);
      if (rc < 0)
	cerr << "close error: " << std_error_string() << endl;
      this->fd = -1;
    }
  this->connected_p = false;
  if (this->verbose_p)
    cout << "socketio: oeof" << endl;
}


bool
innocent_errno_p (int err)
{
  return ((err == EWOULDBLOCK) 
	  || (err == EINPROGRESS)
	  || (err == EINTR)
	  || (err == EAGAIN));
}


void
socketio::wait_more ()
{
  // raise number slowly
  this->poll_interval += 1 + (this->poll_interval / 100);
  if (this->poll_interval > this->max_poll_interval)
    this->poll_interval = this->max_poll_interval;
}


void
socketio::wait_less ()
{
  // shrink number but keep it strictly positive
  this->poll_interval = this->poll_interval / 2 + 1;
}


void 
socketio::poll_connect ()
{
  // attempt to connect
  assert (! this->connected_p);

  if (this->server_p)
    {
      // server
      assert (this->serv_fd >= 0);
      assert (this->fd < 0);
      
#ifdef HAVE_SOCKLEN_T
      socklen_t addrlen;
#else
      int addrlen;
#endif
      addrlen = sizeof (struct sockaddr_in);
      this->fd = accept (this->serv_fd, 
			 reinterpret_cast<sockaddr*>(& this->peer_name),
			 & addrlen);
      if (this->fd >= 0)
	{
	  // XXX: add security checks on peer_name here
	  this->asyncificate (this->fd);
	  this->connected_p = true;
	  if (this->verbose_p)
	    cout << "socketio: accepted connection from " << this->peer_name
		 << ", fd " << this->fd << endl;
	}
      else if (! innocent_errno_p (errno))
	{
	  cerr << "accept error: " << std_error_string () << endl; 
	}
      else
	this->wait_more();
    }
  else 
    {
      // client
      assert (this->serv_fd < 0);
      assert (this->fd >= 0);
      
      this->peer_name.sin_family = AF_INET;
      int rc = connect (this->fd, reinterpret_cast<sockaddr*>(& this->peer_name),
			sizeof (this->peer_name));
      if (rc == 0)
	{
	  this->connected_p = true;
	  if (this->verbose_p)
	    cout << "socketio: connected to " << this->peer_name << endl;
	}
      else if (! innocent_errno_p (errno))
	cerr << "connect error: " << std_error_string() << ", retrying" << endl;
      else
	this->wait_more ();
    }
}



void 
socketio::poll_receive ()
{
  // attempt to pump some data in
  assert (this->fd >= 0);
  int count = read (this->fd, this->in_buffer, in_buffer_size);
  if (count > 0)
    {
      if (this->trace_traffic_p)
	cout << ">>" << std::string(this->in_buffer, count) << ">>" << flush;

      // yey
      for (int j=0; j<count; j++)
	{
	  unsigned char c = this->in_buffer[j];
	  this->in_pin.drive (c);
	  this->in_count ++;
	}
      this->wait_less ();
    }
  else if ((count == 0) ||
	   ((count < 0) && (! innocent_errno_p (errno))))
    {
      // eof
      if (this->server_p)
	{
	  int rc = shutdown (this->fd, 2); // shut down sending & receiving
	  if (rc != 0)
	    cerr << "shutdown error: " << std_error_string() << endl;
	  rc = close (this->fd);
	  if (rc < 0)
	    cerr << "close error: " << std_error_string() << endl;
	  this->fd = -1;
	}
      this->connected_p = false;
      if (this->verbose_p)
	cout << "socketio: ieof1" << endl;
      this->in_pin.drive (~0);
    }
  else // if ((count < 0) && (innocent_errno_p (errno)))
    this->wait_more ();
}



void 
socketio::poll_transmit ()
{
  // attempt to pump some data out
  assert (this->fd >= 0);
  if (this->out_buffer.length() != 0)
    {
      int count = write (this->fd, this->out_buffer.data(), this->out_buffer.length());
      if (count > 0)
	{
	  // yey
	  this->out_count += count;

	  if (this->trace_traffic_p)
	    cout << "<<" << this->out_buffer.substr(0, count) << "<<" << flush;

	  // zap from buffer
	  this->out_buffer = this->out_buffer.substr(count, std::string::npos);
	  this->wait_less();
	}
      else if ((count < 0) && (! innocent_errno_p (errno)))
	{
	  // eof
	  if (this->server_p)
	    {
	      int rc = shutdown (this->fd, 2); // shut down sending & receiving
	      if (rc != 0)
		cerr << "shutdown error: " << std_error_string() << endl;
	      rc = close (this->fd);
	      if (rc < 0)
		cerr << "close error: " << std_error_string() << endl;
	      this->fd = -1;
	    }
	  this->connected_p = false;
	  if (this->verbose_p)
	    cout << "socketio: ieof2" << endl;
	  this->in_pin.drive (~0);
	}
      else // if ((count == 0) || ((count < 0) && (innocent_errno_p (errno))))
	this->wait_more ();
    }
}



void 
socketio::poll ()
{
  // do nothing if init has not been performed yet
  if ((this->server_p == false && this->fd < 0) ||
      (this->server_p == true && this->serv_fd < 0))
    {
      cerr << "socketio: illegal poll while uninitialized" << endl;
      return;
    }

  this->poll_count ++;

  // prevent reentrant use
  recursion_record polling(this);
  if (! polling.ok())
    return;

  // poll again later
  this->poll_control.schedule_irregular (this->poll_interval);
  
  // XXX: very verbose
  // if (this->verbose_p)
  //  cout << "socketio: next poll in " << this->poll_interval << " ms" << endl;

  // attempt to connect
  if (! this->connected_p)
    this->poll_connect();

  // still not connected?
  if (! this->connected_p)
    return;

  this->poll_receive();

  // got disconnected?
  if (! this->connected_p)
    return;

  this->poll_transmit();
}


ostream& 
operator << (ostream& out, const socketio& it)
{
  // XXX: finish this?
  return out;
}


istream& 
operator >> (istream& in, socketio& it)
{
  // XXX: finish this?
  return in;
}


} // end namespace console_stuff
