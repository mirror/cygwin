// Uart.cxx - NS16550 UART component.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "Uart.h"

#include <sidpinattrutil.h>
#include <sidso.h>

using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

enum reg_mnemonics {
  RBR		= 0,	// Rx Buff, Addr=0 && DLAB=0, read-only
  IER		= 1,	// Interrupt Enable, Addr=1 && DLAB=0
  IIR		= 2,	// Interrupt ID, read-only
  LCR		= 3,	// Line Control Reg
  MCR		= 4,	// Modem Control Reg
  LSR		= 5,	// Line Status Reg
  MSR		= 6,	// Modem Status Reg
  SCR		= 7,	// Scratch Reg
  DLL		= 8,	// Divisor LSB, Addr=0 && DLAB=1
  DLM		= 9,	// Divisor MSB, Addr=1 && DLAB=1
  THR		= 10,	// Tx Hold, Addr=0 && DLAB=0, write-only
  FCR		= 11,	// FIFO Control, write-only
};

enum intr_enable_bitpos {
  IER_ERBFI	= 0,	// Enable Rx buffer full
  IER_ETBEI	= 1,	// Enable Tx buffer empty
  IER_ELSI	= 2,	// Enable line status
  IER_EDSSI	= 3	// Enable data set status
};

enum intr_id_bitpos {
  IIR_NPEND	= 0,	// Interrupt pending - active low
  IIR_ID	= 1,	// Interrupt ID (3 bits)
  IIR_FTL	= 6	// FIFO Trigger Level (2 bits)
};

#define IIR_ID_MASK	0xf1

enum intr_id {
  IIR_RLS_ID	= 0x6,	// Rx Line Status
  IIR_RDA_ID	= 0x4,  // Rx Data Available
  IIR_CTI_ID	= 0x0c,	// Character Timeout Indicator
  IIR_TBE_ID	= 0x2,	// Tx Buffer Empty
  IIR_DSS_ID	= 0x0	// Data Set Status
};

enum intr_pend_mask {	// The bits for the INTR pending mask
  PEND_RX_ERR	= 0x1,
  PEND_RX_RDY	= 0x2,
  PEND_RX_TO	= 0x4,
  PEND_TX_RDY	= 0x8,
  PEND_MODEM	= 0x10
};

enum line_ctl_bitpos {
  LCR_BITS	= 0,	// # of data bits (bits 0 and 1)
  LCR_STOP	= 2,	// # of stop bits
  LCR_PE	= 3,	// Parity Enable
  LCR_PSEL	= 4,	// Parity Select
  LCR_STICK	= 5,	// Stick parity
  LCR_BRK	= 6,	// Break control
  LCR_DLAB	= 7	// Divisor Latch Access Bit
};

enum line_status_bitpos {
  LSR_DR	= 0,	// Data ready
  LSR_OE	= 1,	// Overrun error
  LSR_PE	= 2,	// Parity error
  LSR_FE	= 3,	// Framing error
  LSR_BI	= 4,	// Break indicator
  LSR_THRE	= 5,	// Tx Holding Reg empty
  LSR_TEMT	= 6,	// Tx empty
  LSR_ERF	= 7	// Error in Rx FIFO
};

enum fcn_ctl_bitpos {
  FCR_FE	= 0,	// FIFO enable
  FCR_RFR	= 1,	// Rx FIFO reset
  FCR_TFR	= 2,	// Tx FIFO reset
  FCR_DMA	= 3,	// DMA mode select
  FCR_RT	= 6	// Rx Trigger (2 bits)
};

enum modem_ctl_bitpos {
  MCR_DTR	= 0,	// Data Tx ready
  MCR_RTS	= 1,	// Request to send
  MCR_OUT1	= 2,
  MCR_OUT2	= 3,
  MCR_LOOPBACK	= 4	// loopback mode
};

enum modem_status_bitpos {
  MSR_DCTS	= 0,	// The first four are "delta" flags
  MSR_DDSR	= 1,
  MSR_TERI	= 2,
  MSR_DDCD	= 3,
  MSR_CCTS	= 4,	// The next four are "complement" flags
  MSR_CDSR	= 5,
  MSR_CRI	= 6,
  MSR_CDCD	= 7
};

const int FIFO_TOP = 0;

inline void
bit_set( unsigned char& val, int pos ) {
  val |= (1 << pos);		// set bit at position pos
}

inline void
bit_clear( unsigned char& val, int pos ) {
  val &= ~(1 << pos);		// clear bit at position pos
}

inline int
bit_test( unsigned char val, int pos ) {
  return (val & (1 << pos));	// return non-zero if bit at pos is 1
}

inline int
bit_value( unsigned char val, int pos ) {
  return ((val >> pos) & 1);	// return bit at pos as its own int
}


// streaming operators for Uart::regs type

class attribute_coder_uart_reg: public attribute_coder_base
{
  typedef host_int_1 Value;
  Value* ptr;

public:
  attribute_coder_uart_reg(Value* p): ptr(p) {}

  std::string
  make_attribute() const
    { 
      int r = *ptr;
      
#if HAVE_SSTREAM
      // I haven't actually tested this
      std::ostringstream stream;
      stream << std::hex << std::setw(2) << std::setfill('0') << r;
      return stream.str();
#else
#if HAVE_STRSTREAM_H
      ostrstream stream;
      stream << std::hex << std::setw(2) << std::setfill('0') << r;
      std::string result(stream.str(), stream.pcount());
      stream.freeze();
      return result;
#else
#error "need <sstream> or <strstream.h>!"
#endif
#endif
    }
  

  sid::component::status
  parse_attribute(const std::string& str)
    {
      int r;
#if HAVE_SSTREAM
      std::istringstream stream (str);
      stream >> std::hex >> r;
#else
#if HAVE_STRSTREAM_H
      istrstream stream (str.data(), str.length());
      stream >> std::hex >> r;
#else
#error "need <sstream> or <strstream.h>!"
#endif
#endif
      if( stream.good() ) {
	*ptr = r;
	return component::ok;
      }
      else {
	cerr << "UART register set failed :-(" << endl;
	return component::bad_value;
      }
    }
};


Uart :: Uart()
   :triggerpoint_manager(this), 
    busif( this, &(Uart::busReadHandler), &(Uart::busWriteHandler) ),
    sin( this, &Uart::sinHandler ), 
    reset_pin( this, &(Uart::reset) ),
    rx_timeout( "rx-timeout", this, &Uart::rxWatchdog ),
    tx_timeout( "tx-timeout", this, &Uart::txWatchdog )
{
  in_cnt = 0;
  out_cnt = 0;
  pending = 0;
  sio_framing_p = true;

  in_fifo_length = out_fifo_length = 16; // Defaults for 16550
  update_fifo_lengths ();

  add_attribute( "sio-framing?", &sio_framing_p, "setting" );
  add_attribute_notify( "in-fifo-length", &in_fifo_length, 
			this, &Uart::update_fifo_lengths,
			"setting" );
  add_attribute_notify( "out-fifo-length", &out_fifo_length, 
			this, &Uart::update_fifo_lengths,
			"setting" );

  add_bus( "Bus", &busif );

  add_pin( "Sin", &sin );
  add_pin( "Sout", &sout );
  add_attribute_ro_value( "tk tty", string("hw-visual-tty"), "gui");

  add_pin( "INTR", &intr );
  intr.set_active_high();
  intr.off ();

  add_pin( "TxRdy", &txrdy );
  add_pin( "RxRdy", &rxrdy );
  add_pin( "RTS", &rts );
  add_pin( "DTR", &dtr );
  add_pin( "OUT1", &out1 );
  add_pin( "OUT2", &out2 );

  add_pin( "CTS", &cts );
  cts.init( this, &Uart::ctsHandler );

  add_pin( "DSR", &dsr );
  dsr.init( this, &Uart::dsrHandler );

  add_pin( "DCD", &dcd );
  dcd.init( this, &Uart::dcdHandler );

  add_pin( "RI", &ri );
  ri.init( this, &Uart::riHandler );

  add_pin( "Reset", &reset_pin );

 /* Pick the timeout as 10 msec. Its supposed to be proportional to the
  * baud rate, but since our baud rate is infinitely fast, we just pick
  * something to make sure we get control back eventually.
  */
  timeout_incr = 10;
  add_attribute( "timeout", &timeout_incr );

  Uart_ctor_0();
  Uart_ctor_1();
  Uart_ctor_2();
  Uart_ctor_3();
  Uart_ctor_4();
  add_attribute_virtual ("state-snapshot", this,
			 &Uart::save_state,
			 &Uart::restore_state );

}

// The following functions contain what used to be within Uart::Uart().

void
Uart :: Uart_ctor_0()
{

  add_attribute_coder("RBR", new attribute_coder_uart_reg(& this->regs[RBR]),
								   "register");
  triggerpoint_manager.add_watchable_value ("RBR", & this->regs[RBR]);
  categorize ("RBR", "watchable");

  add_attribute_coder("IER", new attribute_coder_uart_reg(& this->regs[IER]),
								   "register");
  triggerpoint_manager.add_watchable_value ("IER", & this->regs[IER]);
  categorize ("IER", "watchable");

  add_attribute_coder("IIR", new attribute_coder_uart_reg(& this->regs[IIR]),
								   "register");
  triggerpoint_manager.add_watchable_value ("IIR", & this->regs[IIR]);
  categorize ("IIR", "watchable");

  add_attribute_coder("LCR", new attribute_coder_uart_reg(& this->regs[LCR]), 
								   "register");
  triggerpoint_manager.add_watchable_value ("LCR", & this->regs[LCR]);
  categorize ("LCR", "watchable");

  add_attribute_coder("MCR", new attribute_coder_uart_reg(& this->regs[MCR]),
								   "register");
  triggerpoint_manager.add_watchable_value ("MCR", & this->regs[MCR]);
  categorize ("MCR", "watchable");

}


void
Uart :: Uart_ctor_1()
{
  add_attribute_coder("LSR", new attribute_coder_uart_reg(& this->regs[LSR]),
								   "register");
  triggerpoint_manager.add_watchable_value ("LSR", & this->regs[LSR]);
  categorize ("LSR", "watchable");

  add_attribute_coder("MSR", new attribute_coder_uart_reg(& this->regs[MSR]),
								   "register");
  triggerpoint_manager.add_watchable_value ("MSR", & this->regs[MSR]);
  categorize ("MSR", "watchable");

  add_attribute_coder("SCR", new attribute_coder_uart_reg(& this->regs[SCR]), 
								   "register");
  triggerpoint_manager.add_watchable_value ("SCR", & this->regs[SCR]);
  categorize ("SCR", "watchable");

  add_attribute_coder("DLL", new attribute_coder_uart_reg(& this->regs[DLL]), 
								   "register");
  triggerpoint_manager.add_watchable_value ("DLL", & this->regs[DLL]);
  categorize ("DLL", "watchable");

  add_attribute_coder("DLM", new attribute_coder_uart_reg(& this->regs[DLM]), 
								   "register");
  triggerpoint_manager.add_watchable_value ("DLM", & this->regs[DLM]);
  categorize ("DLM", "watchable");
}


void
Uart :: Uart_ctor_2()
{
  add_attribute_coder("THR", new attribute_coder_uart_reg(& this->regs[THR]), 
								   "register");
  triggerpoint_manager.add_watchable_value ("THR", & this->regs[THR]);
  categorize ("THR", "watchable");

  add_attribute_coder("FCR", new attribute_coder_uart_reg(& this->regs[FCR]), 
								   "register");
  triggerpoint_manager.add_watchable_value ("FCR", & this->regs[FCR]);
  categorize ("FCR", "watchable");

  add_attribute( "Sin", &sin, "pin" );
  triggerpoint_manager.add_watchable_attribute ("Sin");
  categorize ("Sin", "watchable");

  add_attribute( "Sout", &sout, "pin" );
  triggerpoint_manager.add_watchable_attribute ("Sout");
  categorize ("Sout", "watchable");

  add_attribute( "Reset", &reset_pin, "pin" );
  triggerpoint_manager.add_watchable_attribute ("Reset");
  categorize ("Reset", "watchable");

  add_attribute( "INTR", &intr, "pin" );
  triggerpoint_manager.add_watchable_attribute ("INTR");
  categorize ("INTR", "watchable");
}


void
Uart :: Uart_ctor_3()
{
  add_attribute( "TxRDY", &txrdy, "pin" );
  triggerpoint_manager.add_watchable_attribute ("TxRDY");
  categorize ("TxRDY", "watchable");

  add_attribute( "RxRDY", &rxrdy, "pin" );
  triggerpoint_manager.add_watchable_attribute ("RxRDY");
  categorize ("RxRDY", "watchable");

  add_attribute( "RTS", &rts, "pin" );
  triggerpoint_manager.add_watchable_attribute ("RTS");
  categorize ("RTS", "watchable");

  add_attribute( "DTR", &dtr, "pin" );
  triggerpoint_manager.add_watchable_attribute ("DTR");
  categorize ("DTR", "watchable");

  add_attribute( "OUT1", &out1, "pin" );
  triggerpoint_manager.add_watchable_attribute ("OUT1");
  categorize ("OUT1", "watchable");
}


void
Uart :: Uart_ctor_4()
{

  add_attribute( "OUT2", &out2, "pin" );
  triggerpoint_manager.add_watchable_attribute ("OUT2");
  categorize ("OUT2", "watchable");

  add_attribute( "CTS", (binary_input_pin *) &cts, "pin" );
  triggerpoint_manager.add_watchable_attribute ("CTS");
  categorize ("CTS", "watchable");

  add_attribute( "DSR", (binary_input_pin *) &dsr, "pin" );
  triggerpoint_manager.add_watchable_attribute ("DSR");
  categorize ("DSR", "watchable");

  add_attribute( "RI", (binary_input_pin *) &ri, "pin" );
  triggerpoint_manager.add_watchable_attribute ("RI");
  categorize ("RI", "watchable");

  add_attribute( "DCD", (binary_input_pin *) &dcd, "pin" );
  triggerpoint_manager.add_watchable_attribute ("DCD");
  categorize ("DCD", "watchable");
}


// The in_fifo_length and/or out_fifo_length members have been changed.
// Resize the fifo vectors to match.
void
Uart :: update_fifo_lengths() {
  // Clamp values 
  if (in_fifo_length < 1)
    in_fifo_length = 1;
  if (out_fifo_length < 1)
    out_fifo_length = 1;

  // Resize the vectors.  Leftover values will be lost.
  in_fifo.resize( in_fifo_length );
  in_errs.resize( in_fifo_length );
  out_fifo.resize( out_fifo_length );

  // There were some pending bytes in there ...
  if (in_cnt > in_fifo_length)
    {
      // Treat as overrun error
      in_cnt = in_fifo_length - 1;
      in_errs[in_cnt-1] = LSR_OE;
      bit_set( regs[LSR], LSR_ERF );
    }
}


void
Uart :: reset( host_int_4 ) {
  // RBR and THR are not affected by reset
  regs[IER] = 0;
  regs[IIR] = 1;	// no pending interrupt yet
  regs[FCR] = 0;
  regs[LCR] = 0;
  regs[LSR] = 0x60;	// Tx side is empty
  regs[MCR] = 0;
  setModemStatusReg();	// set MSR
  regs[SCR] = 0;
  // DLL and DLM are not affected by reset

  intr.off();
  out1.off();
  out2.off();
  rts.off();
  dtr.off();

  pending |= PEND_TX_RDY;
  txrdy.on();		// ready to get a char
  rxrdy.off();

  rx_timeout.cancel();
  tx_timeout.cancel();
}

sid::bus::status
Uart::busReadHandler( host_int_4 index, host_int_1& p ) {
  unsigned char val;

  switch( index ) {
  case 0:
    if( bit_test( regs[LCR], LCR_DLAB ) )
      val = regs[DLL];
    else
      val = receive();
    break;

  case 1:
    if( bit_test( regs[LCR], LCR_DLAB ) )
      val = regs[DLM];
    else
      val = regs[IER];
    break;

  case 2:
    val = regs[IIR];
    break;

  case LCR:
  case MCR:
  case SCR:
    val = regs[index];
    break;

  case LSR:
    val = regs[LSR];

    regs[LSR] &= 0xe1;			// Clear per char status bits
    pending &= ~(PEND_RX_ERR);		// Clear pending status if error

    // Deassert interrupt line if the LSR raised the interupt.
    if( !(bit_test( regs[IIR], IIR_NPEND )) ) {
      if( (regs[IIR] & ~(IIR_ID_MASK)) == IIR_RLS_ID ) {
	// This one is done, but there could be more pending conditions
	if( !setInterruptId() )	{	// deassert IRQ
	  bit_set( regs[IIR], IIR_NPEND );
	  intr.off();
	}
      }
    }
    break;

  case MSR:
    val = setModemStatusReg();

    regs[MSR] &= 0xf0;			// Clear delta bits
    pending &= ~(PEND_MODEM);		// Modem has no pending IRQ

    // Deassert interrupt line if the modem raised the interupt.
    if( !(bit_test( regs[IIR], IIR_NPEND )) ) {
      if( (regs[IIR] & ~(IIR_ID_MASK)) == IIR_DSS_ID ) {
	bit_set( regs[IIR], IIR_NPEND );
	intr.off();
      }
    }
    break;

  default:
    return sid::bus::unmapped;			// illegal index
  }

  p = val;

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();

  return sid::bus::ok;
}

sid::bus::status
Uart :: busWriteHandler( host_int_4 index, host_int_1 val ) {
  switch( index ) {
  case 0:
    if( bit_test( regs[LCR], LCR_DLAB ) )
      regs[DLL] = val;
    else
      xmit( val );
    break;

  case 1:
    if( bit_test( regs[LCR], LCR_DLAB ) )
      regs[DLM] = val;
    else {
      regs[IER] = val & 0x0f;

      if( setInterruptId() ) {	// did we enable something that was pending?
	if( bit_test( regs[IIR], IIR_NPEND) ) {
	  bit_clear( regs[IIR], IIR_NPEND );
	  intr.on();
	}
      }
      else {			// nothing enabled - turn off IRQ if on
       /* This behavior is pointed out in the application notes, and is
	* required because the INTR line is level oriented, but many chips
	* are edge-sensitive to interrupt lines.
	*/
	if( !(bit_test( regs[IIR], IIR_NPEND)) ) {
	  bit_set( regs[IIR], IIR_NPEND );
	  intr.off();
	}
      }
    }
    break;

  case 2: // FCR (write-only)
    setFunctionReg( val );
    break;

  case LCR:
  case SCR:
    regs[index] = val;
    break;

  case MCR:
    setModemControlReg( val );
    break;

  case MSR:
  case LSR:
    // What does it mean to write these registers?
    break;

  default:
    return sid::bus::unmapped; // illegal index
  }

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();

  return sid::bus::ok;
}

void
Uart :: setFunctionReg( unsigned char val ) {
  int i;

  if( bit_test( regs[FCR], FCR_FE ) && !(bit_test( val, FCR_FE )) ) {
    // clearing FCR_FE disables and resets the FIFOs
    in_cnt = 0;
    out_cnt = 0;

    for( i=0; i<in_fifo_length; i++ ) {
      in_fifo[i] = 0;
      in_errs[i] = 0;
    }

    for( i=0; i<out_fifo_length; i++ )
      out_fifo[i] = 0;

    regs[IIR] &= 0x3f;			// Clear FIFO enable bits in IIR
  }

  if( !(bit_test( val, FCR_FE )) ) {
    regs[FCR] = 0;
    return;
  }

  if( bit_test( val, FCR_RFR ) ) {	// reset input FIFO
    in_cnt = 0;

    for( i=0; i<in_fifo_length; i++ ) {
      in_fifo[i] = 0;
      in_errs[i] = 0;
    }
  }

  if( bit_test( val, FCR_TFR ) ) {	// reset output FIFO
    out_cnt = 0;

    for( i=0; i<out_fifo_length ; i++ )
      out_fifo[i] = 0;
  }

  regs[FCR] = val;
  regs[IIR] |= 0xc0;			// Set FIFO enable bits in IIR
}

/* Check the interrupt sources in order to determine if an interrupt is
 * warranted. Returns TRUE if an interrupt is required.
 */
int
Uart :: setInterruptId() {
  if( pending ) {
    regs[IIR] &= IIR_ID_MASK;		// Clear current id

    if( pending & PEND_RX_ERR ) {	// Rx Error
      if( bit_test( regs[IER], IER_ELSI ) ) {
	regs[IIR] |= IIR_RLS_ID;
	return 1;
      }
    }

    if( pending & PEND_RX_RDY ) {	// Rx ready
      if( bit_test( regs[IER], IER_ERBFI ) ) {
	regs[IIR] |= IIR_RDA_ID;
	return 1;
      }
    }

    if( pending & PEND_RX_TO ) {	// Input timeout
      regs[IIR] |= IIR_CTI_ID;		// Not enabled via IER
      return 1;
    }

    if( pending & PEND_TX_RDY ) {	// Tx ready
      if( bit_test( regs[IER], IER_ETBEI ) ) {
	regs[IIR] |= IIR_TBE_ID;
	return 1;
      }
    }

    if( pending & PEND_MODEM ) {	// Modem status
      if( bit_test( regs[IER], IER_EDSSI ) ) {
	regs[IIR] |= IIR_DSS_ID;
	return 1;
      }
    }
  }

  return 0;
}

/* genParity determines the parity bit for the low NBITS bits of VAL,
 * according to the parity type specified by P. The routine returns
 * VAL with the parity bit set in bit NBITS+1.
 */
unsigned
Uart :: genParity( unsigned val, int nbits, enum parity p ) const {
  int i, ones_count = 0;
  unsigned copy = val;

  for( i=0; i<nbits; i++ ) {
    if( copy & 1 )
      ++ones_count;

    copy >>= 1;
  }

  if( p==EVEN_PARITY && (ones_count & 1) )
    return val | (1 << nbits);
  
  if( p==ODD_PARITY && !(ones_count & 1) )
    return val | (1 << nbits);

  return val;
}

/* checkParity checks that the parity bit in position NBITS+1 of VAL 
 * matches the parity type specified by P. The function returns zero
 * if the parity bit is incorrect.
 */
int 
Uart :: checkParity( unsigned val, int nbits, enum parity p ) const {
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
Uart :: xmit( unsigned val ) {
  int i, data_mask = 0;
  int nbits = num_bits[regs[LCR] & 0x3];
  unsigned oval = val;

  if( bit_test( regs[FCR], FCR_FE ) && !bit_test( regs[FCR], FCR_DMA ) ) {
   /* Single char DMA mode - turn off TxRDY. Note that in multi-char DMA
    * TxRDY is always on because the Tx FIFO is never full.
    */
    txrdy.off();
  }

  tx_timeout.cancel();

  for( i=0; i<nbits; i++ )		// build a mask for the data
    data_mask |= (1 << i);

  val &= data_mask;

  if( bit_test( regs[LCR], LCR_PE ) ) {	// parity is enabled
    if( bit_test( regs[LCR], LCR_STICK ) ) {
      // Stick parity = 0 if EVEN, = 1 if ODD
      if( !(bit_test( regs[LCR], LCR_PSEL )) )
	val |= (1 << nbits);
    }
    else				// no stick parity
      val = genParity( val,nbits, (enum parity) bit_test(regs[LCR], LCR_PSEL) );
  }

  // XXX: Hey, what about out_fifo[] ?
  regs[THR] = val;
  if (sio_framing_p)
    sout.drive( val );			// send it
  else
    sout.drive( oval );                 // send it without framing

  regs[THR] = 0;			// always empty because always sent
  bit_set( regs[LSR], LSR_THRE );
  bit_set( regs[LSR], LSR_TEMT );

  if( bit_test( regs[FCR], FCR_FE ) && !bit_test( regs[FCR], FCR_DMA ) ) {
    // Single char DMA mode - turn on TxRDY
    txrdy.on();
  }

 /* The specs imply that the delay from write to TxRDY interrupt is just for 
  * FIFO mode, but I think it makes sense all the time. (We'll have to see
  * what the chip does, of course :-)
  */
  tx_timeout.schedule_irregular( timeout_incr );

  pending &= ~(PEND_TX_RDY);		// the watchdog will set this
}

static int trigger_vals[4] = { 1, 4, 8, 14 };	// from FCR bits 6-7

void
Uart :: sinHandler( host_int_4 v ) {
  int i, data_mask = 0;
  int nbits = num_bits[regs[LCR] & 0x3];
  unsigned val = v;

  if( in_cnt == in_fifo_length ) {	// FIFO full
    in_errs[in_cnt-1] = LSR_OE;
    bit_set( regs[LSR], LSR_ERF );

    // check for triggerpoints
    triggerpoint_manager.check_and_dispatch ();

    return;				// drop the char
  }
  else if( !bit_test( regs[FCR], FCR_FE ) ) { // not in FIFO mode
    if( in_cnt == 1 )			// already had a char
      bit_set( in_errs[FIFO_TOP], LSR_OE ); // so it will be lost

    in_cnt = 0;				// always at the top of the FIFO
  }

  if( sio_framing_p ) // framing?
    {
      if( bit_test( regs[LCR], LCR_PE ) ) {	// parity is enabled
	if( bit_test( regs[LCR], LCR_STICK ) ) {
	  
	  // Stick parity is on: 0 if EVEN parity selected; 1 otherwise
	  if( (bit_test( regs[LCR], LCR_PSEL )) ) {
	    if( bit_test( val, nbits ) )
	      bit_set( in_errs[in_cnt], LSR_PE );
	  }
	}
	else				// regular parity
	  if( !checkParity( val, nbits, (enum parity)bit_test(regs[LCR],LCR_PSEL)) )
	    bit_set( in_errs[in_cnt], LSR_PE );
      }

      for( i=0; i<nbits; i++ )		// build a mask for the data
	data_mask |= (1 << i);
      
      val &= data_mask;
    }
  else
    {
      // treat val as raw data value
    }

  in_fifo[in_cnt] = val;

  if( in_cnt == 0 ) {
   /* The spec says that the errors are revealed when the char is at the
    * top of the FIFO. If in_cnt == 0 then this char is at the top.
    */
    regs[LSR] &= 0x61;			// set error bits
    regs[LSR] |= in_errs[FIFO_TOP];

    if( in_errs[FIFO_TOP] )
      pending |= PEND_RX_ERR;

    in_errs[FIFO_TOP] = 0;		// done with them now
  }

  ++in_cnt;

  bit_set( regs[LSR], LSR_DR );	// Data now available

  if( !bit_test( regs[FCR], FCR_FE ) ) {	// Not in FIFO mode
    pending |= PEND_RX_RDY;

    rxrdy.on();				// Set the DMA line (mode 0)
  }
  else {				// FIFO mode
    int trigger = trigger_vals[(regs[FCR] & 0xc0) >> 6];

    rx_timeout.cancel();

    if( in_cnt>1 && in_errs[in_cnt-1] )	// did we just get an error?
      bit_set( regs[LSR], LSR_ERF );

    if( in_cnt >= trigger ) {
      if( bit_test( regs[FCR], FCR_DMA ) )
	rxrdy.on();			// Set the DMA line (mode 1)

      pending |= PEND_RX_RDY;
    }
    else {				// not at trigger point yet
      if( !bit_test( regs[FCR], FCR_DMA ) )
	rxrdy.on();			// Set the DMA line (mode 0)

      // set up a callback in case no more chars come.
      rx_timeout.schedule_irregular( timeout_incr );
    }
  }

  if( setInterruptId() ) {		// IRQ if enabled
    bit_clear( regs[IIR], IIR_NPEND );
    intr.on();
  }

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}

host_int_1
Uart :: receive() {
  int i;

  regs[RBR] = in_fifo[FIFO_TOP];	// get the char at the top of the FIFO

  --in_cnt;				// one less in FIFO

  if( in_cnt <= 0 ) {			// emptied the FIFO
    bit_clear( regs[LSR], LSR_DR );

    pending &= ~(PEND_RX_RDY);		// clear pending IRQ source

    rxrdy.off();

    in_cnt = 0;				// guard against multiple reads
  }
  else {				// data still in FIFO
   /* This looks inefficient, because we physically move all the characters 
    * one position up the FIFO. I originally did this with in/out pointers,
    * but that fails for the following case: get 4 in, read 2, then get 14 in.
    * The hardware should allow this, but its tough to get right with pointers.
    */
    for( i=0; i<in_cnt; i++ ) {
      in_fifo[i] = in_fifo[i+1];
      in_errs[i] = in_errs[i+1];
    }

    bit_set( regs[LSR], LSR_DR );	

    /* "Reveal" the next char's status in the LSR */
    regs[LSR] &= 0x61;			// mask out the per char errors
    regs[LSR] |= in_errs[FIFO_TOP];	// and get the error for this char

    if( in_errs[FIFO_TOP] )
      pending |= PEND_RX_ERR;

    in_errs[FIFO_TOP] = 0;		// done with these errors

    for( i=1; i<in_cnt; i++ ) {
      if( in_errs[i] )
	bit_set( regs[LSR], LSR_ERF );	// error still to come
    }

    int trigger = trigger_vals[(regs[FCR] & 0xc0) >> 6];

    if( in_cnt < trigger )		// dropped below trigger point
      pending &= ~PEND_RX_RDY;
  }

  rx_timeout.cancel();

  if( setInterruptId() ) {		// possibly new Rx errors
    bit_clear( regs[IIR], IIR_NPEND );	// assert interrupt
    intr.on();
  }
  else {				// possibly out of data
    bit_set( regs[IIR], IIR_NPEND );	// deassert interrupt
    intr.off();
  }

  return regs[RBR];
}

/* rxWatchdog is a scheduler callback function. It is triggered from FIFO
 * mode when no input characters have arrived during the specified timeout.
 *
 * This functionality is important to make sure no characters are stranded 
 * in the FIFO with interrupts enabled. For example, if the interrupt trigger 
 * point is set at 8 and the last packet only contains 6 characters, they
 * would remain in the FIFO indefinitely unless a timeout is set.
 */
void 
Uart :: rxWatchdog() {
  pending |= PEND_RX_TO;		// timed out on receive

  if( setInterruptId() ) {
    bit_clear( regs[IIR], IIR_NPEND );	// assert interrupt
    intr.on();

    // check for triggerpoints
    triggerpoint_manager.check_and_dispatch ();
  }
}

/* txWatchdog is a scheduler callback function. It is triggered in FIFO mode
 * when Tx interrupts are enabled, and a character is output but no subsequent
 * character is output within a given timeout period.
 *
 * This functionality prevents back-to-back interrupts when the Transmit
 * Holding Register is empty and there is room in the Transmit FIFO. When
 * the Holding Register is written the character is immediately transferred
 * to the FIFO, which would generate another Tx Ready interrupt, possibly
 * while the CPU is still handling the current Tx Ready interrupt. The timeout
 * is set to delay the subsequent Tx Ready interrupt.
 */
void 
Uart :: txWatchdog() {
  pending |= PEND_TX_RDY;		// timed out on xmit

  if( setInterruptId() ) {
    bit_clear( regs[IIR], IIR_NPEND );	// assert interrupt
    intr.on();

    // check for triggerpoints
    triggerpoint_manager.check_and_dispatch ();
  }
}

/* Set the delta/complement bit for the corresponding modem input line.
 * BIT is the position of the complement bit; VAL is treated as the boolean
 * _ACTIVE_LOW_ chip input.
 *
 * This routine relies on the fact that the delta bit group is in the first
 * 4 bits, and that the complement bit group is in the second four bits.
 */
inline void
Uart :: modemLineChange( int bit, int val ) {
  assert( (bit >= 4) && (bit <= 7) );

  bit_set( regs[MSR], bit - 4 );

  if( val )
    bit_clear( regs[MSR], bit );
  else
    bit_set( regs[MSR], bit );
}

void
Uart :: setModemControlReg( unsigned char val ) {
  unsigned char changed = regs[MCR] ^ val;

  regs[MCR] = val & 0x1f;			// Top 3 bits are always 0

  if( bit_test( changed, MCR_LOOPBACK ) ) {
    if( bit_test( val, MCR_LOOPBACK ) ) {	// switch to Loopback
      bit_set( regs[MCR], MCR_LOOPBACK );
    
      dtr.off();	// The external lines are de-asserted
      rts.off();
      out1.off();
      out2.off();

      // Note: The MSR reg flags are updated when that register is read.
    }
    else {
      bit_clear( regs[MCR], MCR_LOOPBACK );

      dtr.set( bit_value( val, MCR_DTR ) );
      rts.set( bit_value( val, MCR_RTS ) );
      out1.set( bit_value( val, MCR_OUT1 ) );
      out2.set( bit_value( val, MCR_OUT2 ) );
    }

   /* It is unclear to me what's supposed to happen to the MSR delta bits
    * when we switch to/from loopback. 
    */
    return;
  }

  if( bit_test( val, MCR_LOOPBACK ) ) {		// in loopback mode
   /* Have to complement the logical bit values to get external active-low
    * signal values expected by modemLineChange
    */
    if( bit_test( changed, MCR_DTR ) )
      modemLineChange( MSR_CDSR, ~(bit_value( val, MCR_DTR )) );

    if( bit_test( changed, MCR_RTS ) )
      modemLineChange( MSR_CCTS, ~(bit_value( val, MCR_RTS )) );

    if( bit_test( changed, MCR_OUT1 ) )
      modemLineChange( MSR_CRI, ~(bit_value( val, MCR_OUT1 )) );

    if( bit_test( changed, MCR_OUT2 ) )
      modemLineChange( MSR_CDCD, ~(bit_value( val, MCR_OUT2 )) );

    if( changed & 0x0f )
      checkModemIRQ();
  }
  else {					// not in loopback mode
    dtr.set( bit_value( val, MCR_DTR ) );
    rts.set( bit_value( val, MCR_RTS ) );
    out1.set( bit_value( val, MCR_OUT1 ) );
    out2.set( bit_value( val, MCR_OUT2 ) );
  }
}

host_int_1
Uart :: setModemStatusReg() {
  bit_clear( regs[MSR], MSR_CCTS );
  bit_clear( regs[MSR], MSR_CDSR );
  bit_clear( regs[MSR], MSR_CRI );
  bit_clear( regs[MSR], MSR_CDCD );

  if( bit_test( regs[MCR], MCR_LOOPBACK ) ) {	// in loop-back mode
    if( bit_test( regs[MCR], MCR_RTS ) )
      bit_set( regs[MSR], MSR_CCTS );

    if( bit_test( regs[MCR], MCR_DTR ) )
      bit_set( regs[MSR], MSR_CDSR );

    if( bit_test( regs[MCR], MCR_OUT1 ) )
      bit_set( regs[MSR], MSR_CRI );

    if( bit_test( regs[MCR], MCR_OUT2 ) )
      bit_set( regs[MSR], MSR_CDCD );
  }
  else {					// not in loopback mode
    if( cts.state() == binary_pin_active )
      bit_set( regs[MSR], MSR_CCTS );

    if( dsr.state() == binary_pin_active )
      bit_set( regs[MSR], MSR_CDSR );

    if( ri.state() == binary_pin_active )
      bit_set( regs[MSR], MSR_CRI );

    if( dcd.state() == binary_pin_active )
      bit_set( regs[MSR], MSR_CDCD );
  }

  return regs[MSR];
}

void
Uart :: checkModemIRQ() {
  pending |= PEND_MODEM;

  if( bit_test( regs[IER], IER_EDSSI ) ) {
    // Modem interrupts are enabled

    if( (bit_test( regs[IIR], IIR_NPEND )) ) {
      // There is no IRQ currently pending - raise the interrupt

      regs[IIR] = (regs[IIR] & IIR_ID_MASK);	// Set the ID as the modem
      bit_clear( regs[IIR], IIR_NPEND );	// Set pending bit (low)
      intr.on();
    }
  }
}

// Callback for CTS pin
void
Uart :: ctsHandler( int val ) {
  if( !(bit_test( regs[MCR], MCR_LOOPBACK )) )	// ignore if loop-back
    modemLineChange( MSR_CCTS, val );

  checkModemIRQ();

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}

// Callback for DSR pin
void
Uart :: dsrHandler( int val ) {
  if( !(bit_test( regs[MCR], MCR_LOOPBACK )) )	// ignore if loop-back
    modemLineChange( MSR_CDSR, val );

  checkModemIRQ();

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}

// Callback for RI pin
void
Uart :: riHandler( int val ) {
  if( !(bit_test( regs[MCR], MCR_LOOPBACK )) ) {
    if( bit_test( regs[MSR], MSR_CRI ) && val )
      bit_set( regs[MSR], MSR_TERI );	    // Set on 0 to 1 transition

    if( val )
      bit_clear( regs[MSR], MSR_CRI );
    else
      bit_set( regs[MSR], MSR_CRI );
  }

  checkModemIRQ();

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}

// Callback for DCD pin
void
Uart :: dcdHandler( int val ) {
  if( !(bit_test( regs[MCR], MCR_LOOPBACK )) )	// ignore if loop-back
    modemLineChange( MSR_CDCD, val );

  checkModemIRQ();

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}



ostream&
operator << (ostream& op, const Uart& copy_obj)
{
  // Store Internal Registers First
  op << "InterRegs ";
  for (int reg_num = 0; reg_num < (UART_NUM_REGS - 1); ++reg_num)
      op << (host_int_4) copy_obj.regs[reg_num] << " ";
  op << (host_int_4) copy_obj.regs[UART_NUM_REGS - 1] << ":";

  op << "FifoLengths " << copy_obj.in_fifo_length << " " << copy_obj.out_fifo_length << ":";

  op << "InFCh " << copy_obj.in_cnt;
  if (copy_obj.in_cnt > 0)
    {
      op << "InFifo ";
      for (int in_chars = 0; in_chars < (copy_obj.in_cnt - 1); ++in_chars)
         op << copy_obj.in_fifo[in_chars] << " ";
      op << copy_obj.in_fifo[copy_obj.in_cnt - 1];

      op << "InErr ";
      for (int in_error = 0; in_error < (copy_obj.in_cnt - 1); ++in_error)
          op << (host_int_4) copy_obj.in_errs[in_error] << " ";
      op << (host_int_4) copy_obj.in_errs[copy_obj.in_cnt -1];
    }
  op << ":"; // Seperator.

  op << "OutFCh " << copy_obj.out_cnt;
  if (copy_obj.out_cnt > 0)
    {
      op << "OutFifo ";
      for ( int out_chars = 0; out_chars < (copy_obj.out_cnt - 1 ); ++out_chars)
         op << copy_obj.out_fifo[out_chars] << " ";
      op << copy_obj.out_fifo[copy_obj.out_cnt - 1];
    }
  op << ":";  // Seperator
  op << "Pend " << copy_obj.pending << ":" ;
  op << "Frame " << copy_obj.sio_framing_p << ":";
  op << "rxpin " << copy_obj.rxrdy.recall() << ":";
  op << "txpin " << copy_obj.txrdy.recall() << ":";
  op << "TOCount " << copy_obj.timeout_incr;

  return op;
}

istream&
operator >> (istream& ip, Uart& ovwrite_obj)
{
  string coding;

  ip >> coding;
  if ( coding != "InterRegs")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
   host_int_4 reg_value;
   for (int reg_num = 0; reg_num < UART_NUM_REGS; ++reg_num)
      {
	ip >> reg_value;
	if (reg_num != MCR)
	   ovwrite_obj.regs[reg_num] = reg_value;
        else
	  ovwrite_obj.busWriteHandler(MCR, (host_int_1)reg_value); // Will drive o/p pins too
      }

    if ( bit_test(ovwrite_obj.regs[IIR], IIR_NPEND) )
      ovwrite_obj.intr.off();
    else // Raise interrupt
      ovwrite_obj.intr.on();

   char sep;
   ip.get(sep);
   if ( sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }


   ip >> coding;
   if (coding != "FifoLengths")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> ovwrite_obj.in_fifo_length;
   ip >> ovwrite_obj.out_fifo_length;
   ip.get(sep);
   if ( sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ovwrite_obj.update_fifo_lengths ();
      
   ip >> coding;
   if (coding != "InFCh")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> ovwrite_obj.in_cnt;
   if (  ovwrite_obj.in_cnt > 0 ) 
     {
       ip >> coding;
       if (coding != "InFifo")
	 {
	   ip.setstate(ios::badbit);
	   return ip;
	 }
       for (unsigned int  i = 0; i <  ovwrite_obj.in_cnt; ++i) 
	  ip >> ovwrite_obj.in_fifo[i];

       ip >> coding;
       if (coding != "InErr")
	 {
	   ip.setstate(ios::badbit);
	   return ip;
	 }

       host_int_4 err_val;
       for (unsigned int j= 0; j <  ovwrite_obj.in_cnt; ++j)
	  {
	    ip >> err_val;
	    ovwrite_obj.in_errs[j] = err_val;
	  }
     }
   ip.get(sep);
   if (sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }

   ip >> coding;
   if ( coding != "OutFCh")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> ovwrite_obj.out_cnt;
   if ( ovwrite_obj.out_cnt > 0 ) 
     {
       ip >> coding;
       if (coding != "OutFifo")
	 {
	    ip.setstate(ios::badbit);
	    return ip;
	 }
       for (unsigned int k = 0; k < ovwrite_obj.out_cnt; ++k )
	   ip >> ovwrite_obj.out_fifo[k];
     }
   ip.get(sep);
   if (sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }

   ip >> coding;
   if ( coding != "Pend")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> ovwrite_obj.pending;
   ip.get(sep);
   if (sep != ':') 
     {
       ip.setstate(ios::badbit);
       return ip;
     }
 
   ip >> coding;
   if (coding != "Frame")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> ovwrite_obj.sio_framing_p;
   ip.get(sep);
   if (sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }

   host_int_4 temppin_val =0;
   ip >> coding;
   if (coding != "rxpin")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> temppin_val;
   ovwrite_obj.rxrdy.drive(temppin_val);
   ip.get(sep);
   if (sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }

   ip >> coding;
   if (coding != "txpin")
     {
       ip.setstate(ios::badbit);
       return ip;
     }
   ip >> temppin_val;
   ovwrite_obj.txrdy.drive(temppin_val);
   ip.get(sep);
   if (sep != ':')
     {
       ip.setstate(ios::badbit);
       return ip;
     }

   ip >> coding;
   if (coding != "TOCount")
     {
       ip.setstate(ios::badbit);
       return ip;
     } 
   ip >> ovwrite_obj.timeout_incr;

   return ip;
}


// Standard DLL wrapper-stuff

static vector<string>
UartListTypes()
{
  vector<string> types;
  types.push_back(string("hw-uart-ns16550"));
  return types;
}

static component*
UartCreate(const string& typeName)
{
  if(typeName == "hw-uart-ns16550")
    return new Uart();
  else
    return 0;
}


static void
UartDelete(component* c)
{
  delete dynamic_cast<Uart*>(c);
}


// static object
extern const component_library uart_component_library;

const component_library uart_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & UartListTypes, 
  & UartCreate,
  & UartDelete
};

