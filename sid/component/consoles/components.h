// file.cxx - Joint header file for nearby component classes.
// -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidtypes.h>
#include <sidmiscutil.h>
#include <sidschedutil.h>
#include <sidpinattrutil.h>

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <cassert>
extern "C" {
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#define BSD_COMP
#include <sys/ioctl.h>
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#include <netinet/tcp.h>
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
}


namespace console_stuff 
{

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::flush;
using std::cerr;
using std::endl;
  
using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_2;
using sid::little_int_1;
using sid::host_int_4;
using sid::host_int_8;
using sid::component_library;
  
using sidutil::no_bus_component;
using sidutil::fixed_attribute_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::no_accessor_component;
using sidutil::no_relation_component;
using sidutil::output_pin;
using sidutil::callback_pin;
using sidutil::string2stream;
using sidutil::stream2string;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::scheduler_event_subscription;
using sidutil::std_error_string;
using sidutil::tokenize;
using sidutil::recursion_limited;
using sidutil::recursion_record;
using sidutil::make_numeric_attribute;


// -------------------------------------------------------------------------

class stdioConsole: public virtual component, 
		    protected fixed_attribute_map_component,
		    protected no_bus_component,
		    protected fixed_pin_map_component,
		    protected no_accessor_component,
		    protected no_relation_component
{
public:
  stdioConsole();

private:
  void write(host_int_4 value);
  void read(host_int_4);

  callback_pin<stdioConsole> activity_pin;
  callback_pin<stdioConsole> stdout_pin;
  output_pin stdin_pin;

  // save & restore state
  string save_state ( );
  component::status restore_state (const string& state);

};


// -------------------------------------------------------------------------

  class socketio: public virtual component,
		  protected no_bus_component,
		  protected fixed_attribute_map_component,
		  protected fixed_pin_map_component,
		  protected no_accessor_component,
		  protected no_relation_component,
		  protected recursion_limited
  {
  private:
    callback_pin<socketio> init_pin, fini_pin;
    void init_handler (host_int_4);
    void fini_handler (host_int_4);

    // mode settings
    bool server_p; // server or client mode?
    bool verbose_p; // verbosity?
    bool trace_traffic_p; // trace all socket traffic?
    bool buffer_disconnected_p; // keep outbound data while disconnected?

    // this and other side 
    sockaddr_in sock_name;
    sockaddr_in peer_name;

    // outbound data
    callback_pin<socketio> out_pin;
    void tx_eof_handler();
    void tx_handler(host_int_4 value);
    // inbound data
    output_pin in_pin;

    // low level state
    int fd;
    int serv_fd;
    bool connected_p;
    string out_buffer;
    float avg_out_buffer_size;
    enum _bs { in_buffer_size = 2048 };
    char in_buffer [in_buffer_size];
    host_int_8 in_count;
    host_int_8 out_count;
    host_int_8 poll_count;

    // polling info
    friend class scheduler_event_subscription<socketio>;
    scheduler_event_subscription<socketio> poll_control;

    // Make these types small enough to avoid having to request long
    // delays from the scheduler.
    host_int_2 poll_interval;
    host_int_2 max_poll_interval;

    void asyncificate (int fd);
    void update_poll_interval();
    void poll ();
    void poll_connect ();
    void poll_receive ();
    void poll_transmit ();
    void wait_more();
    void wait_less();

    // state control
    friend ostream& operator << (ostream& o, const socketio& it);
    friend istream& operator >> (istream& i, socketio& it);
    string save_state () { return make_attribute(*this); }
    sid::component::status restore_state (const string& state)
      { return parse_attribute (state, *this); }


  public:
    socketio(bool server_p);
  };


} // end of namespace console_stuff

