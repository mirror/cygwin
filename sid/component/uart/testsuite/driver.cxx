// driver.cxx - test case driver for the UART.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <sidcomp.h>
#include <sidso.h>
#include <sidpinutil.h>
#include <sidcomputil.h>
#include <sidbusutil.h>

#include <iostream>
#include <map>
#include <vector>

#include <stdio.h>
#include "uart-def.h"

using namespace sidutil;
using namespace std;

#include "Devices.h"

#define BUS_READ(addr,value) \
{				\
little_int_1 xyzzy; 		\
bus->read((addr),xyzzy);	\
value = xyzzy;			\
}

#define BUS_WRITE(addr,value)   \
{				\
little_int_1 xyzzy = value;	\
bus->write((addr),xyzzy);	\
}

// refer to the component_library struct exported from compUart
// - requires static linking to work properly on some systems
extern component_library DLLIMPORT uart_component_library;
extern component_library DLLIMPORT sched_component_library;

static int err_cnt = 0;

inline void
check( unsigned char val, unsigned char expected, char* test ) {
  if( val != expected ) {
    printf( "%s: got 0x%02x (expected %02x)\n", test, val, expected );
    ++err_cnt;
  }
}



int
main( int argc, char* argv[] ) {
  output_pin source;
  SerialSink sink;
  DeviceDriver driver;
  unsigned int old_count;
  char *str = "Hello World\n";
  host_int_1 val;
  host_int_4 addr;
  char buf[128];
  int done_reptest = 0;
  ios::sync_with_stdio();
  unsigned int i;

  // check magic value
  assert (uart_component_library.magic == COMPONENT_LIBRARY_MAGIC);
  assert (sched_component_library.magic == COMPONENT_LIBRARY_MAGIC);
 
  // instantiate each type, once
  component* uart = (* uart_component_library.create_component)( "hw-uart-ns16550" );
  assert (uart != 0);
  component* sched =
    (* sched_component_library.create_component)( "sid-sched-sim" );
  assert (sched != 0);
  source.connect( uart->find_pin( "Sin" ) );
  uart->connect_pin( "Sout", sink.find_pin( "Sin" ) );

  sid::bus *bus = uart->find_bus( "Bus" );
  assert( bus );
  component::status s = driver.connect_accessor( "Bus", bus );
  assert( s == component::ok );

  // XXX: check sid::component::function() return values!!

  uart->connect_pin( "INTR", driver.find_pin( "INTR" ) );

  /* Configure the scheduler */ 
  sched->set_attribute_value( "num-clients", "2" );
  sched->connect_pin( "0-event", uart->find_pin( "rx-timeout-event" ));
  uart->connect_pin( "rx-timeout-control", sched->find_pin( "0-control" ));
  sched->connect_pin( "1-event", uart->find_pin( "tx-timeout-event" ));
  uart->connect_pin( "tx-timeout-control", sched->find_pin( "1-control" ));
  sid::pin* advancePin = sched->find_pin( "advance" );
  driver.connect_pin( "sched-advance", advancePin );

  /* Test writing of various registers */
  printf( "start with register read/write tests\n" );

  BUS_WRITE( addr = UART_SCRATCH, val = 4 );
  BUS_READ( addr = UART_SCRATCH, val );
  if( val != 4 ) {
    printf( "Didn't read the Scratch register properly: %d\n", (unsigned) val );
    ++err_cnt;
  }

  /* Write to the Divider */
  BUS_WRITE( addr = UART_LCR, val = 0x80 );	// set DLAB=1
  BUS_WRITE( addr = UART_DIVL, val = 0xaa );
  BUS_WRITE( addr = UART_DIVM, val = 0x55 );
  BUS_WRITE( addr = UART_LCR, val = 0x0 );	// clear DLAB


  BUS_READ( addr = UART_DIVL, val );
  if( val == 0xaa ) {
    printf( "Shouldn't have got DIVL register\n" );
    ++err_cnt;
  }

  BUS_READ( addr = UART_DIVM, val );
  if( val == 0x55 ) {
    printf( "Shouldn't have got DIVM register\n" );
    ++err_cnt;
  }

  BUS_WRITE( addr = UART_LCR, val = 0x80 );	// set DLAB=1
  
  BUS_READ( addr = UART_DIVL, val );
  if( val != 0xaa ) {
    printf( "Didn't get DIVL register: %02x\n", (unsigned) val );
    ++err_cnt;
  }

  BUS_READ( addr = UART_DIVM, val );
  if( val != 0x55 ) {
    printf( "Didn't get DIVM register: %02x\n", (unsigned) val );
    ++err_cnt;
  }

  BUS_WRITE( addr = UART_LCR, val = 0 );	// clear DLAB to access IER

  BUS_READ( addr = UART_LCR, val );		// check DLAB = 0
  check( val, 0, "LCR read" );

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), old_count );

  /* Put the UART in loopback mode */
  BUS_WRITE( addr = UART_MCR, val = 0x10 );
  BUS_WRITE( addr = UART_MCR, val = 0x12 );	// set RTS

  // Should see both DCTS and CCTS bits set
  BUS_READ( addr = UART_MSR, val );
  check( val, 0x11, "MSR read" );

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), i );
  if( i > old_count ) {
    printf( "Shouldn't have had an interrupt yet\n" );
    ++err_cnt;
  }

  BUS_READ( addr = UART_MSR, val );		// check DCTS cleared by read
  check( val, 0x10, "MSR read" );

  BUS_WRITE( addr = UART_IER, val = 0x08 );	// enable modem interrupts

  BUS_READ( addr = UART_IER, val );		// check EDSSI enabled
  check( val, 0x08, "IER read" );

  BUS_WRITE( addr = UART_MCR, val = 0x11 );	// set DTR, clear RTS

 /* Should see DCTS, DDSR, and CDSR bits set. The DCTS bit is set because
  * RTS changed back to deasserted.
  */
  BUS_READ( addr = UART_MSR, val );
  check( val, 0x23, "MSR read" );

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), i );
  if( i == old_count ) {
    printf( "Should have had an interrupt\n" );
    ++err_cnt;
  }
  
  string temp_storage_string = uart->attribute_value("state-snapshot");
 rep_test:
  
  /* Write "hello world" with no interrupts. */
  BUS_WRITE( addr = UART_LCR, val = 0x02 );	// 7-bits, no parity

  BUS_READ( addr = UART_LCR, val );
  check( val, 0x2, "LCR read" );

  for( i=0; i<strlen( str ); i++ ) {
    host_int_1 chr = str[i];

    BUS_WRITE( addr = UART_THR, chr );

    BUS_READ( addr = UART_LSR, val );		// Check that it was sent
    check( val, 0x60, "LSR read" );
  }

  /* Now with parity and stuff */
  BUS_WRITE( addr = UART_LCR, val = 0x1f );
  //string ldisc = "31";
  string ldisc = "0x1F";
  sink.set_attribute_value( "line-discipline", ldisc );// 8-bits, even parity, 2 stop

  str = "8-bits, even parity, 2 stop\n";

  for( i=0; i<strlen( str ); i++ ) {
    host_int_1 chr = str[i];

    BUS_WRITE( addr = UART_THR, chr );

    BUS_READ( addr = UART_LSR, val );		// Check that it was sent
    check( val, 0x60, "LSR read" );
  }

  advancePin->driven(0);			// callback from last write

  /* Try an interrupt driven output string. */
  BUS_WRITE( addr = UART_LCR, val = 0x0a );
  //ldisc = "10";
  ldisc = "0x0A";
  sink.set_attribute_value( "line-discipline", ldisc ); // 7-bits, odd parity, 1 stop

  driver.write( "interrupt-driven output\n" );

  /* now try some input. */
  BUS_WRITE( addr = UART_LCR, val = 0x3a );	// 7-bits, stick-parity = 0

  str = "polled input - no FIFOs";
  puts( str );

  for( i=0; i<strlen( str ); i++ ) {
    source.drive( str[i] );

    BUS_READ( addr = UART_LSR, val );
    check( val, 0x61, "LSR read" );

    BUS_READ( addr = UART_RXB, val );
    check( val, str[i], "RXB read" );
  }

  /* now try the FIFO. */
  str = "polled input - with FIFOs";
  puts( str );

  BUS_WRITE( addr = UART_LCR, val = 0x2a );	// 7-bits, stick-parity = 1
  BUS_WRITE( addr = UART_FCR, val = 0x03 );	// Enable FIFOs

  for( i=0; i<strlen( str ); i+=8 ) {		// do 8 chars at a time
   unsigned int j;

    for( j=i; (j<i+8) && (j<strlen( str )); j++ )
      source.drive( str[j] | 0x080 );

    for( j=i; (j<i+8) && (j<strlen( str )); j++ ) {
      BUS_READ( addr = UART_LSR, val );
      check( val, 0x61, "LSR read" );

      BUS_READ( addr = UART_RXB, val );
      check( val, str[j], "RXB read" );
    }
  }

  /* now for interrupt driven input */
  printf( "16450 style interrupt driven input\n" );

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), old_count );

  BUS_WRITE( addr = UART_LCR, val = 1 );	// 6-bits, no parity
  BUS_WRITE( addr = UART_FCR, val = 0 );	// Disable FIFOs
  BUS_WRITE( addr = UART_IER, val = 5 );	// Enable Rx interrupts

  str = "\t0123456789\n";			// These fit in 6 bits

  for( i=0; i<strlen( str ); i++ )		// Send the string
    source.drive( str[i] );

  val = driver.read( buf );
  if( val != strlen( str ) ) {
    printf( "str len mismatch: got %d but expected %d\n", (unsigned) val, strlen( str ) );
    ++err_cnt;
  }

  for( i=0; i<val; i++ ) {
    check( str[i], buf[i], "char mismatch" );
  }

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), i );
  if( i - old_count != strlen( str ) ) {
    printf( "Missing some interrupts\n" );
    ++err_cnt;
  }

  /* now for interrupt driven input using the FIFOs */
  printf( "check FIFO based interrupt driven input\n" );

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), old_count );

  BUS_WRITE( addr = UART_LCR, val = 0x2 );	// 7-bits, no parity
  BUS_WRITE( addr = UART_FCR, val = 0x43 );	// Enable FIFOs - trigger 4

  str = "My len must be divisible by four";
  for( i=0; i<strlen( str ); i++ )		// Send the string
    source.drive( str[i] );

  BUS_WRITE( addr = UART_IER, val = 0 );	// disable interrupts

  val = driver.read( buf );
  if( val != strlen( str ) ) {
    printf( "str len mismatch: got %d but expected %d\n", (unsigned) val, strlen( str ) );
    ++err_cnt;
  }

  for( i=0; i<val; i++ ) {
    check( str[i], buf[i], "char mismatch" );
  }

  parse_attribute<unsigned int>( driver.attribute_value( "interrupt-count" ), i );
  if( (i - old_count) != (unsigned)val/4 ) {
    printf( "missed some FIFO interrupts\n" );
    ++err_cnt;
  }

  // Test parity error 
  BUS_WRITE( addr = UART_FCR, val = 0 );	// no FIFOs
  BUS_WRITE( addr = UART_LCR, val = 0x0a );	// 7-bits, odd parity

  source.drive( 'c' );
  BUS_READ( addr = UART_LSR, val );
  check( val, 0x65, "parity check" );

  BUS_READ( addr = UART_RXB, val );
  check( val, 'c', "parity check" );

  // Test overrun error
  source.drive( 'a' );
  source.drive( 'b' );
  BUS_READ( addr = UART_LSR, val );
  check( val, 0x63, "overrun check" );

  // First char is overwritten by second
  BUS_READ( addr = UART_RXB, val );
  check( val, 'b', "overrun check" );

  // Check for latent errors in FIFO mode.
  printf( "check for errors deep in Rx FIFO\n" );

  BUS_WRITE( addr = UART_FCR, val = 0x0b );	// FIFOs on, DMA mode 1

  source.drive( 'a' );
  source.drive( 'b' );
  source.drive( 'c' );	// should cause a parity error.

  for( i=0; i<2; i++ ) {
    BUS_READ( addr = UART_LSR, val );
    if( val != 0xe1 ) {
      printf( "FIFO error check %d: got %02x but expected 0xe1\n", i+1, (unsigned) val );
      ++err_cnt;
    }

    BUS_READ( addr = UART_RXB, val );
    if( val != (unsigned) ('a' + i) ) {
      printf( "FIFO error check: got %02x but expected '%c'\n", (unsigned) val, 'a'+i );
      ++err_cnt;
    }
  }

  BUS_READ( addr = UART_LSR, val );
  check( val, 0x65, "FIFO error 3 check" );

  BUS_READ( addr = UART_RXB, val );
  check( val, 'c', "FIFO RXB error 3 check" );

  BUS_READ( addr = UART_LSR, val );
  check( val, 0x60, "FIFO error end check" );

  /* Finally, test stranded chars in the FIFO. */
  printf( "test stranded chars in Rx FIFO\n" );

  BUS_WRITE( addr = UART_LCR, val = 0x2 );	// 7-bits, no parity
  BUS_WRITE( addr = UART_FCR, val = 0xc3 );	// Enable FIFOs - trigger 14
  BUS_WRITE( addr = UART_IER, val = 0x5 );	// Enable receive interrupts

  str = "My len should not be a multiple of 14\n";
  for( i=0; i<strlen( str ); i++ )		// Send the string
    source.drive( str[i] );

  for( i=0; i<1000; i++ )
    advancePin->driven(0);		        // empty the event queue

  BUS_WRITE( addr = UART_IER, val = 0 );	// disable interrupts

  val = driver.read( buf );
  if( val != strlen( str ) ) {
    printf( "str len mismatch: got %d but expected %d\n", (unsigned) val, strlen( str ) );
    ++err_cnt;
  }

  cout << "Register names: ";
  vector<string> register_names = uart->attribute_names( "register" );
  for( unsigned k=0; k<register_names.size(); k++ )
    cout << register_names[k] << "(" << uart->attribute_value( register_names[k] ) << ") ";
  cout << endl;
  
  // NB: 40 = 0x28
  if( uart->set_attribute_value( "SCR", "40" ) != component::ok ) {
    printf( "couldn't set SCR reg\n" );
    ++err_cnt;
  }

  string reg_val = uart->attribute_value( "SCR" );
  if( reg_val != "40" ) {
    printf( "read SCR mismatch: expected 0x28=40, got %s\n", reg_val.c_str() );
    ++err_cnt;
  }

  // Note: 15 = 0x0f
  if( uart->set_attribute_value( "DLL", "15" ) != component::ok ) {
    printf( "couldn't set DLL reg\n" );
    ++err_cnt;
  }

  reg_val = uart->attribute_value( "DLL" );
  if( reg_val != "15" ) {
    printf( "read SCR mismatch: expected 0xf=15, got %s\n", reg_val.c_str() );
    ++err_cnt;
  }

  cout << "Pin names: ";
  vector<string> pin_names = uart->attribute_names( "pin" );
  for( unsigned k=0; k<pin_names.size(); k++ )
    cout << pin_names[k] << "(" << uart->attribute_value( pin_names[k] ) << ") ";
  cout << endl;
  
  if( uart->set_attribute_value( "OUT1", "on" ) != component::ok ) {
    printf( "couldn't set OUT1\n" );
    ++err_cnt;
  }

  string pin_val = uart->attribute_value( "OUT1" );
  if( pin_val != "on" ) {
    printf( "read OUT1 mismatch: expected 'on', got '%s'\n", pin_val.c_str() );
    ++err_cnt;
  }

  if( uart->set_attribute_value( "RI", "off" ) != component::ok ) {
    printf( "couldn't set RI\n" );
    ++err_cnt;
  }

  pin_val = uart->attribute_value( "RI" );
  if( pin_val != "off" ) {
    printf( "read RI: expected 'off', got '%s'\n", pin_val.c_str() );
    ++err_cnt;
  }

  if( uart->set_attribute_value( "RI", "0" ) != component::ok ) {
    printf( "couldn't set RI\n" );
    ++err_cnt;
  }

  pin_val = uart->attribute_value( "RI" );
  if( pin_val != "on" ) {
    printf( "set/get RI mismatch: expected 'on', got '%s'\n", pin_val.c_str() );
    ++err_cnt;
  }

  if( uart->set_attribute_value( "Reset", "1" ) != component::ok ) {
    printf( "couldn't reset Uart\n" );
    ++err_cnt;
  }

  pin_val = uart->attribute_value( "Reset" );
  if( pin_val != "1" ) {
    printf( "Reset: expected '1', got '%s'\n", pin_val.c_str() );
    ++err_cnt;
  }

  if (err_cnt) printf( "all tests complete - %d errors\n", err_cnt );

  if (! done_reptest ) 
    {
      uart->set_attribute_value ("state-snapshot", temp_storage_string);
      done_reptest++;  
         str = "Hello World\n";
	ldisc = "0";
	sink.set_attribute_value( "line-discipline", ldisc );
        goto rep_test;
    }
  return (err_cnt > 0);
}
