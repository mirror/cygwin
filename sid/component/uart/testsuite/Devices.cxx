// Devices.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "Devices.h"
#include <stdio.h>
#include "uart-def.h"

void
DeviceDriver :: intrHandler( int val ) {
  little_int_1 chr, status;
  int iid;
  char st;
  host_int_4 addr;

  if( !val ) // interrupt deasserted
    return;

  ++irq_cnt;

  assert( bus );

  bus->read( addr = UART_IIR, status );
  iid = status & 0xf;

  if( iid == 0x6 ) {			// Rx Error
    bus->read( addr = UART_LSR, status );
    st = status;
    printf( "intrHandler - Rx Status Error %02x\n", st );
  }

  if( iid==0x4 || iid==0xc ) {		// Rx ready && Rx TimeOut
    // This should work for FIFO oriented input too.
    bus->read( addr = UART_LSR, status );
    while( status & 0x1 ) {
      if( (status & 0x8e) ) {
	st = status;
	printf( "DeviceDriver::intrHandler - Rx error %02x\n", st );
      }

      bus->read( addr = UART_RXB, chr );
      rstr[rc++] = chr;

      if( rc == 128 ) {
	printf( "DeviceDriver::intrHandler - Rx infinite loop\n" );
	return;
      }

      bus->read( addr = UART_LSR, status );
    }
  }

  if( iid == 0x2 ) {			// Tx ready
    if( !wstr ) {
      printf( "DeviceDriver::intrHandler - spurious interrupt %x\n", val );
      return;
    }

    little_int_1 l;
    if( wstr[wc] ) {
      l = wstr[wc++];
      bus->write( addr = UART_THR, l );
    } else {
      wc = -1;
    }
  }
}

int
DeviceDriver :: read( char *buf ) {
  int len = rc;

  strncpy( buf, rstr, len );

  rc = 0;	// reset counter for next string
  return len;
}

void
DeviceDriver :: write( char *s ) {
  int len = strlen( s );
  little_int_1 id, val;
  host_int_4 addr;

  wstr = s;
  wc = 0;

  if( len == 0 )				// Nothing to write :-(
    return;

  // Assume line discipline has already been set up

  bus->read( addr = UART_LSR, id );
  if( (id & 0x60) != 0x60 )
    printf( "DeviceDriver::write - UART not ready?\n" );

  bus->write( addr = UART_IER, val = 0x2 ); // Enable Tx interrupts

 /* I don't know if Tx IRQs are always pending but masked. If they are,
  * that would mean that unmasking them does automatically generates an
  * interrupt when the current char is transmitted. This makes sense because
  * otherwise you have to have to wait for that current char to finish.
  * On the other hand, I don't remember it working this way.
  * I'll assume you don't have to kickstart the transfer, but we'll have to 
  * test it with real hardware/software.
  */
#if 0
  wc = 1;
  bus->write( addr = UART_THR, *s ); // Write the first char
#endif

  ++len;	// need an extra one to move to the NULL
  while( len-- )
    scheduler_advance_pin.drive(0);	// advance the world

  if( wc != -1 )
    printf( "DeviceDriver::write - failed at character %d (len %d)\n", wc, 
	    strlen( s ) );

  bus->write( addr = UART_IER, val = 0 ); // Disable Tx interrupts

  wstr = 0;
}
    

/* checkParity checks that the parity bit in position NBITS+1 of VAL 
 * matches the parity type specified by P. The function returns zero
 * if the parity bit is incorrect.
 */
int 
SerialSink :: checkParity( unsigned val, int nbits, enum parity p ) const {
  int i, ones_count = 0;

  for( i=0; i<(nbits+1); i++ ) {
    if( val & 1 )
      ++ones_count;

    val >>= 1;
  }

  if( p==EVEN_PARITY && (ones_count & 1) )
    return 0;
  
  if( p==ODD_PARITY && !(ones_count & 1) )
    return 0;

  return 1;
}

// Number of data bits - indexed by bottom 2 bits of LCR
static int num_bits[4] = { 5, 6, 7, 8 };

void
SerialSink :: echo( host_int_4 v ) {
  unsigned val = v;

  if( ldisc ) {
    int nbits = num_bits[ldisc & 0x3];
    int i, data_mask = 0;

    if( !checkParity( val, nbits, (enum parity) (ldisc & 0x10) ) )
      printf( "\nSerialSink::echo - parity check failed on %x\n", val );

    for( i=0; i<nbits; i++ )		// build a mask for the data
      data_mask |= (1 << i);

    val &= data_mask;
  }

  putchar( val );
}

void
Main :: run() {
  char *str = "Hello World\n";
  little_int_1 val;
  host_int_4 addr;
  unsigned int i;

  ios::sync_with_stdio();

  assert( bus );

  /* Write "hello world" with no interrupts. */
  bus->write( addr = UART_LCR, val = 0x02 ); // 7-bits, no parity

  for( i=0; i<strlen( str ); i++ ) {
    little_int_1 chr = str[i];

    bus->write( addr = UART_THR, chr );
  }

  str = "Try interrupt driven output\n" ;

  // XXX oh me god
  host_int_4 straddr = (host_int_4) str;
  wtrigger.drive( straddr );

  /* now try the FIFO. */
  str = "polled input - with FIFOs";
  puts( str );

  bus->write( addr = UART_LCR, val = 0x2a );// 7-bits, stick-parity = 1

  bus->write( addr = UART_FCR, val = 0x03 );// Enable FIFOs

  for( i=0; i<strlen( str ); i+=8 ) {		// do 8 chars at a time
    unsigned int j;

    for( j=i; (j<i+8) && (j<strlen( str )); j++ )
      source.drive( str[j] | 0x080 );

    for( j=i; (j<i+8) && (j<strlen( str )); j++ ) {
      char ch;

      bus->read( addr = UART_LSR, val );
      if( val != 0x61 ) {
	ch = val;
	printf( "LSR read got %02x (expected 0x61)\n", ch );
      }

      bus->read( addr = UART_RXB, val );
      if( val != str[j] ) {
	ch = val;
	printf( "RXB read got %02x (expected %02x)\n", ch, str[j] );
      }
    }
  }

  printf( "Th-th-th-that's all for now folks!\n" );
}

static vector<string>
DevicesListTypes()
{
  vector<string> types;
  types.push_back(string("DeviceDriver"));
  types.push_back(string("SerialSink"));
  types.push_back(string("Main"));
  return types;
}

static component*
DevicesCreate(const string& typeName)
{
  if(typeName == "DeviceDriver")
    return new DeviceDriver();
  else if(typeName == "SerialSink")
    return new SerialSink();
  else if(typeName == "Main")
    return new Main();
  else
    return 0;
}


static void
DevicesDelete(component* c)
{
  // Two of these casts will return 0.  It is safe to delete 0.
  DeviceDriver* d1 = dynamic_cast<DeviceDriver*>(c);
  if (d1) { delete d1; return; }
  SerialSink* d2 = dynamic_cast<SerialSink*>(c);
  if (d2) { delete d2; return; }
  Main* d3 = dynamic_cast<Main*>(c);
  if (d3) { delete d3; return; }
}


// static object
extern const component_library devices_component_library;

const component_library devices_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & DevicesListTypes, 
  & DevicesCreate,
  & DevicesDelete
};
