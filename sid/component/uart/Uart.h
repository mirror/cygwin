// Uart.h - Declarations for the 16550 UART component.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef UART_DEF_H
#define UART_DEF_H	1

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidbusutil.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>

#define UART_NUM_REGS		12

#define UART_NUM_PINS		13

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::string;
using std::cerr;
using std::ios;
using std::endl;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_2;
using sid::host_int_4;

using sidutil::fixed_pin_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_attribute_map_component;
using sidutil::no_accessor_component;
using sidutil::no_relation_component;
using sidutil::scheduler_event_subscription;
using sidutil::binary_input_pin;
using sidutil::binary_output_pin;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::binary_pin_active;
using sidutil::callback_byte_bus;
using sidutil::attribute_coder_base;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::self_watcher;


class Uart: public virtual component,
	    public no_accessor_component,
	    public fixed_attribute_map_component,
	    public no_relation_component,
	    public fixed_bus_map_component,
	    public fixed_pin_map_component
{
private:

  // Triggerpoint Manager 
  friend class self_watcher<Uart>;
  self_watcher<Uart> triggerpoint_manager;

 /* Note: the FIFOs are shorts instead of chars because you can enable
  * parity even when 8 data bits are used.
  */
  host_int_2 in_fifo_length;
  vector<host_int_2> in_fifo;
  host_int_2 out_fifo_length;
  vector<host_int_2> out_fifo;

 /* Each received char in the FIFO may have an associated error.
  * in_errs parallels in_fifo.
  */
  vector<host_int_1> in_errs;

  int in_cnt;	// Number of chars in the input FIFO
  int out_cnt;  //   "         "          output FIFO

  host_int_1 regs[UART_NUM_REGS];

  int pending;		// Bit mask of pending interrupts

  bool sio_framing_p;   // Add framing bits to Sin/Sout pins?

  // The bus
  friend class callback_byte_bus<Uart>;
  callback_byte_bus<Uart> busif;

  bus::status busReadHandler( host_int_4 index, host_int_1& val );
  bus::status busWriteHandler( host_int_4 index, host_int_1 val);

  // Output pins

  binary_output_pin intr;	// Interrupt

  binary_output_pin txrdy;	// DMA control lines
  binary_output_pin rxrdy;

  binary_output_pin rts;	// Modem handshake lines
  binary_output_pin dtr;
  binary_output_pin out1;
  binary_output_pin out2;

  class UartInputPin : public binary_input_pin {
  private:
    Uart *uart;
    void (Uart::*handler) (int);

  public:
    UartInputPin()		{ uart = 0; }

    void init( Uart *owner, void (Uart::*h) (int), bool hi = false )	{ 
      uart = owner; 
      handler = h;

      if( hi )
	set_active_high();
    }

    void driven( host_int_4 v ) throw ( )
      {
        value = v;
        (uart->*handler) ( v ); 
      }
  }; // End of class UartInputPin

  friend class UartInputPin;

  UartInputPin cts;	// Clear to send
  UartInputPin dsr;	// Data set is ready from Modem side
  UartInputPin ri;	// Ring Indicator
  UartInputPin dcd;	// data carrier is detcted by Modem
  
  void ctsHandler( int );	// modem line callbacks
  void dsrHandler( int );	
  void riHandler( int );
  void dcdHandler( int );

  // Data I/O Pins

  callback_pin<Uart> sin;
  friend class callback_pin<Uart>;

  void sinHandler( host_int_4 value );
  
  output_pin sout;

  callback_pin<Uart> reset_pin;
  
  enum parity {
    ODD_PARITY = 0,
    EVEN_PARITY = 0x10		// Matches bit in LCR
  };

  unsigned genParity( unsigned val, int nbits, enum parity p ) const;
  int checkParity( unsigned val, int nbits, enum parity p ) const;

  void xmit( unsigned val );
  host_int_1 receive();

  void setFunctionReg( unsigned char val );
  int setInterruptId();

  inline void modemLineChange( int bit, int val );
  void setModemControlReg( unsigned char val );
  host_int_1 setModemStatusReg();
  void checkModemIRQ();

  int timeout_incr;		// FIFO timeouts
  friend class scheduler_event_subscription<Uart>; // allow it to add pins to us
  scheduler_event_subscription<Uart> rx_timeout;
  scheduler_event_subscription<Uart> tx_timeout;

  void rxWatchdog();	// FIFO timeout callbacks
  void txWatchdog();

  void update_fifo_lengths(); // *-fifo-length attribute callback

  // breaking ctor into small pieces for inline bloat prevention
  void Uart_ctor_0();
  void Uart_ctor_1();
  void Uart_ctor_2();
  void Uart_ctor_3();
  void Uart_ctor_4();

  // Save/Restore methods
  string save_state() { return make_attribute(*this); }
  sid::component::status  restore_state (const string& state) 
    { return parse_attribute ( state, *this);}
  friend ostream& operator << (ostream& op, const Uart& copy_obj);
  friend istream& operator >> (istream& ip, Uart& ovwrite_obj);

 // Virtual pin interfaces between self_watcher and fixed_pin_map_component
 sid::component::status
 pin_factory(const string& name)
    {
      return this->triggerpoint_manager.create_virtual_pin (name);
    }

 void
 pin_junkyard(const string& name)
    {
      this->triggerpoint_manager.destroy_virtual_pin (name);
    }

public:
  Uart();
  ~Uart() {}
  void reset( host_int_4 );
};

#endif // UART_DEF_H
