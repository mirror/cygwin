// ps2.cxx - Simulation of the PS/2 parallel controller.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "ps2.h"

#include <cassert>
#include <sidpinattrutil.h>


// Register Names
enum reg_abbrev
{
  PR    = 0,  // Port Register.(R/W)
  SR    = 1,  //  Status Register(R)
  COM   = 2,  //  Command Register(R)
  CON   = 3,  //  Control Register(R/W)
  IOSEL = 4,  //  IOSelect Register(W)
 
  //  R/W  refers to read & write register.
  //  R    refers to read only register
  //  W    refers to write only register  
};

// Status Register is used to read Interrupt status & other input pin status
enum status_register_bits
{
  // Pins 0-1 are hard coded to 1
  SR_IRQ         = 2, // Interrupt Pending pin
  SR_ERROR       = 3, // Error State pin
  SR_SLCT        = 4, // Printer Selected pin
  SR_PE          = 5, // Page Empty pin 
  SR_ACK         = 6, // ACk from printer pin
  SR_BUSY        = 7, // Busy signal From Printer pin
};


// Command Register is used to read pin state
enum command_register_bits
{
  COM_STROBE     = 0,  // STROBE output pin
  COM_AUTOFDXT   = 1, // line feedback output pin
  COM_INIT       = 2, // Initialize Printer O/P pin
  COM_SLCTIN     = 3, // Select Printer Pin
  COM_IRQ_MASK   = 4, // Enable Interrupt.
  // Pins 5-7 are hard coded to 1
};

// Control Register is used to set pins state
enum control_register_bits
{
  CON_STROBE     = 0,  // Strobe pin state
  CON_AUTOFDXT   = 1, // Line feedback pin state
  CON_INIT       = 2, // Initialize printer pin state
  CON_SLCTIN     = 3, // Select Printer pin state
  CON_IRQ_MASK   = 4, // Enabling/Disbling Interrupt
  CON_IO_SELECT  = 5, // PD7-PD0 in input or Output mode
  // Pins 6-7 are hard coded to 1.
};



/* Following method sets the bit at position pos in character referenced
   by argument val. This method returns no value.
*/ 
inline void
bit_set(unsigned char& val, int pos)
{
  val |= (1 << pos);		
}


/* This method clear the bit at position pos in character referenced by 
   argument val. This method returns no value.
*/
inline void
bit_clear(unsigned char& val, int pos)
{
  val &= ~(1 << pos);		
}


/* Following method tests the bit indicated by argument pos in 
character val. Method returns non-zero value if bit at position pos
is non-zero else it returns 0.
*/
inline int
bit_test(unsigned char val, int pos)
{
  return (val &(1 << pos));	
}


/* This method returns the bit value at position pos in chararcter
val. Return value is 1 if bit value is non-zero otherwise it returns 0.
*/
inline int
bit_value(unsigned char val, int pos)
{
  return ((val >> pos) & 1);	
}


// Constructor
ParPort::ParPort()
  // Initializes internal pins so as to call appropriate driven method.
  :triggerpoint_manager(this),
   AL_error(this, &ParPort::error_handler, false),
   slct(this, &ParPort::slct_handler, true),
   page_empty(this, &ParPort::page_empty_handler, true),
   AL_ack(this, &ParPort::ack_handler,false),
   busy(this, &ParPort::busy_handler, true),
   AL_intsel(this, &ParPort::intsel_handler, false),
   biden (this, &ParPort:: biden_handler, true),
   reset_pin(this, &ParPort::reset),
   bus_size(this, &ParPort::read_parport, &ParPort::write_parport)
{
  for (unsigned i=0; i<8; i++)
    this->data_bus[i].init (this, i);

  add_bus_pins();
  store_registerAttr();
  store_outputpinAttr();
  store_inputpinAttr();
  initialize_bioutpins();
  // For saving restoring state
  add_attribute_virtual ("state-snapshot", this,
			 & ParPort::save_state,
			 & ParPort::restore_state);
  // Reseting internal registers and O/P pins.
  reset(0);
}


// dummy dtor
ParPort::~ParPort() throw ()
{
}


/* Following helper function adds bus, and pins to target
   view. Method returns no value.
*/
void
ParPort::add_bus_pins() 
{
   add_bus("Bus",	&bus_size);
   add_pin("STROBE",	&AL_strobe);
   add_pin("AUTOFDXT",	&AL_autofdxt);
   add_pin("SLCTIN",	&AL_slctin);
   add_pin("INIT",	&init);
   add_pin("INTP",	&AL_irq_mask);
   add_pin("PD0",	&data_bus[0]);
   add_pin("PD1",	&data_bus[1]);
   add_pin("PD2",	&data_bus[2]);
   add_pin("PD3",	&data_bus[3]);
   add_pin("PD4",	&data_bus[4]);
   add_pin("PD5",	&data_bus[5]);
   add_pin("PD6",	&data_bus[6]);
   add_pin("PD7",	&data_bus[7]);
   add_pin("ERROR",	&AL_error);
   add_pin("SLCT",	&slct);
   add_pin("PE",	&page_empty);
   add_pin("ACK",	&AL_ack);
   add_pin("BUSY",	&busy);
   add_pin("RESET",	&reset_pin);
   add_pin("INTSEL",	&AL_intsel);
   add_pin("BIDEN",	&biden);
}


/* This method adds register to target view. Method
   takes no argument and returns no value.
*/
void
ParPort::store_registerAttr()
{
  add_attribute ("PR",    &regs[PR],	"register");
  triggerpoint_manager.add_watchable_value ("PR", &regs[PR]);
  categorize ("PR", "watchable");

  add_attribute ("SR",    &regs[SR],	"register");
  triggerpoint_manager.add_watchable_value ("SR", &regs[SR]);
  categorize ("SR", "watchable");

  add_attribute ("COM",   &regs[COM],	"register");
  triggerpoint_manager.add_watchable_value ("COM", &regs[COM]);
  categorize ("COM", "watchable");

  add_attribute ("CON",   &regs[CON],	"register");
  triggerpoint_manager.add_watchable_value ("CON", &regs[CON]);
  categorize ("CON", "watchable");

  add_attribute ("IOSEL", &regs[IOSEL],	"register");
  triggerpoint_manager.add_watchable_value ("IOSEL", &regs[IOSEL]);
  categorize ("IOSEL", "watchable");
}


/* 
  Following helper function adds output pins of printer port
  to target view. Method takes no arguments and returns no value.
*/
void
ParPort::store_outputpinAttr()
{
  add_attribute("STROBE", &AL_strobe, "pin");
  triggerpoint_manager.add_watchable_attribute ("STROBE");
  categorize ("STROBE", "watchable");

  add_attribute("AUTOFDXT", &AL_autofdxt, "pin");
  triggerpoint_manager.add_watchable_attribute ("AUTOFDXT");
  categorize ("AUTOFDXT", "watchable");

  add_attribute("SLCTIN", &AL_slctin, "pin");
  triggerpoint_manager.add_watchable_attribute ("SLCTIN");
  categorize ("SLCTIN", "watchable");

  add_attribute("INIT", &init, "pin");
  triggerpoint_manager.add_watchable_attribute ("INIT");
  categorize ("INIT", "watchable");

  add_attribute("INTP", &AL_irq_mask, "pin");
  triggerpoint_manager.add_watchable_attribute ("INTP");
  categorize ("INTP", "watchable");

  add_attribute("PD0", & data_bus[0], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD0");
  categorize ("PD0", "watchable");

  add_attribute("PD1", & data_bus[1], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD1");
  categorize ("PD1", "watchable");

  add_attribute("PD2", & data_bus[2], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD2");
  categorize ("PD2", "watchable");

  add_attribute("PD3", & data_bus[3], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD3");
  categorize ("PD3", "watchable");

  add_attribute("PD4", & data_bus[4], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD4");
  categorize ("PD4", "watchable");

  add_attribute("PD5", & data_bus[5], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD5");
  categorize ("PD5", "watchable");

  add_attribute("PD6", & data_bus[6], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD6");
  categorize ("PD6", "watchable");

  add_attribute("PD7", & data_bus[7], "pin");
  triggerpoint_manager.add_watchable_attribute ("PD7"); 
  categorize ("PD7", "watchable");
}


// This method adds input pins of printer port to target view.
void
ParPort::store_inputpinAttr()
{
  add_attribute("ERROR",   (binary_input_pin*) &AL_error,	"pin");
  triggerpoint_manager.add_watchable_attribute ("ERROR");
  categorize ("ERROR", "watchable");

  add_attribute("SLCT",    (binary_input_pin*) &slct,		"pin");
  triggerpoint_manager.add_watchable_attribute ("SLCT");
  categorize ("SLCT", "watchable");

  add_attribute("PE",	   (binary_input_pin*) &page_empty,	"pin");
  triggerpoint_manager.add_watchable_attribute ("PE");
  categorize ("PE", "watchable");

  add_attribute("ACK",     (binary_input_pin*) &AL_ack,		"pin");
  triggerpoint_manager.add_watchable_attribute ("ACK");
  categorize ("ACK", "watchable");

  add_attribute("BUSY",    (binary_input_pin*) &busy,		"pin");
  triggerpoint_manager.add_watchable_attribute ("BUSY");
  categorize ("BUSY", "watchable");

  add_attribute("RESET",   &reset_pin,				"pin");
  triggerpoint_manager.add_watchable_attribute ("RESET");
  categorize ("RESET", "watchable");

  add_attribute("BIDEN",   (binary_input_pin*) &biden,		"pin");
  triggerpoint_manager.add_watchable_attribute ("BIDEN");
  categorize ("BIDEN", "watchable");

  add_attribute("INTSEL",  (binary_input_pin*) &AL_intsel,	"pin");
  triggerpoint_manager.add_watchable_attribute ("INTSEL");
  categorize ("INTSEL", "watchable");

  add_attribute("BIDEN_VAL", &biden_val);
  triggerpoint_manager.add_watchable_attribute ("BIDEN_VAL");
  categorize ("BIDEN_VAL", "watchable");

  add_attribute_notify ("INTSEL_VAL", &AL_intsel_val, 
			 this, &ParPort::intsel_attrhandler);
  triggerpoint_manager.add_watchable_attribute ("INTSEL_VAL");
  categorize ("INTSEL_VAL", "watchable");
}


// Initializing output pins 
void
ParPort::initialize_bioutpins()
{
  // strobe, autofdxt, slctin, and INTP pins are active low, so don't
  // need to initialize them explicity.
  init.set_active_high();
}


/* This method is used to reset the internal registers &
   output pins. This method is called when reset pin is driven.
   Method retuns no value and takes no argument.
*/
void
ParPort::reset(host_int_4)
{
  reset_internalregs();
}


// Reset state for internal registers
void
ParPort::reset_internalregs()
{
  regs[IOSEL] = 0x00;

  regs[PR] = 0x00; // Need to talk about it
  
  biden_val = 1; // To set PD0-PD7 in output mode by default

  // CONTR REGISTER  11000000(11000000  = 0xC0) 
  regs[CON] = 0xC0;
  reset_outputpins();   
 
  // Command Register 11100000 = 0xE0 
  regs[COM] = 0xE0; 

  // STATUS REGISTER 00000111 = 0x0F Sense input Pins
  regs[SR]  = 0x07;
  sense_inputpins();

}	

void
ParPort::sense_inputpins()
{
  host_int_4 pin_val = 0;

  pin_val = AL_error.sense();
  error_handler (pin_val);

  pin_val = slct.sense();
  slct_handler (pin_val);

  pin_val = page_empty.sense();
  page_empty_handler(pin_val);

  pin_val = AL_ack.sense();
  ack_handler(pin_val);

  pin_val = busy.sense();
  busy_handler (pin_val);

}


// Reseting output pins as mentioned in manual
void
ParPort::reset_outputpins()
{
  // Based on values in control register at reset time. 
  // CON bit 4= 0 which is an inactive signal
   AL_irq_mask.on();
   AL_slctin.off();
   AL_autofdxt.off();
   AL_strobe.off();
   // Initializes when O/P sig is act LOW
   init.off();
}


/* This method is used to read internal register of parallel port.
Method takes two arguments. First argument represents the address
value of the desired register and the second argument is an object
of class host_int_1 in which the current value of desired register 
will be stored. Method returns status = ok if operation is successful
otherwise it returns status =unmapped i.e. the address is not valid.
Please note that trying to read only writeable register won't store
the value of writeable register in argument reg_val
*/ 
sid::bus::status
ParPort::read_parport(host_int_4 reg_index, host_int_1& reg_val)
{
  if( reg_index > 8 )
    return sid::bus::unmapped;

  switch (reg_index & 0x03) { // only A0 and A1 are used
  case 0:
    reg_val = regs[PR];
    break;

  case 1:
    reg_val = regs[SR];
    clear_intp(); // clear interrupt if latch mode
    break;

  case 2:
    reg_val = regs[COM];
    break;

  default:  // hmmm, 3 is not unmapped, but it doesn't do anything either 
    return sid::bus::unmapped; // Fixed above comment
  }

  return sid::bus::ok;
}   


// Clears interrupt if latched mode
void
ParPort::clear_intp()
{
  if ((AL_intsel_val) &&(bit_test(regs[COM],COM_IRQ_MASK)))
    {   // in latched mode 
       const unsigned char CLEAR_INTP_MASK = 0x04;
       regs[SR] |=  CLEAR_INTP_MASK; // set bit2 IRQ = 1
       AL_irq_mask.on(); // put signal low
      // INTP disable don't touch the INTP bit as it is in tristate
    }
}   


/* This method is used to write on internal register.
Method takes two arguments. First argument represents the address of the 
desired register on which application program wants to write the value 
represented by the second argument. Method retuns the status =ok if 
write operation is successful else status =unmapped if address represented 
by first argument is invalid. Please note that writing value on read only 
register won't have any affect on the register value.
*/
sid::bus::status
ParPort::write_parport(host_int_4 reg_index,
		      host_int_1 reg_val)
{
  host_int_1 store_val = reg_val;

  if( reg_index > 8 )
    return sid::bus::unmapped;

  switch (reg_index & 0x03) { // only A0 and A1 are used
  case 0:
    printer_data(reg_val);	    
    // any action in case cannot write
    break;

  case 1:
    regs[IOSEL] = reg_val;
    break;

  case 2:
    // Last two bits are always one
    store_val = store_val | 0xc0; 
    store_contval(store_val);
    break;

  default: // hmmm, 3 is not unmapped, but it doesn't do anything either
    return sid::bus::unmapped; // Fixed above comment
  }

  // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();

  return sid::bus::ok;
}


/* Following method writes data represented by argument val
on  PR register provided port is in output mode.
If port is in input mode, no change is made in current PR register
value. Method returns no value.
*/
void
ParPort::printer_data(host_int_1 val) 
{
  if (biden_val) { 
    // BIDEN = 1
    if (!(bit_test(regs[CON],CON_IO_SELECT))) 
      {
	// O/P mode 
	store_newdata(val);
      }
    // else input mode cannot write
  }
  else 
    { // biden is 0 so 
      // if 0x55 is in IOselect reg, then O/P mode else I/P mode
      host_int_4 curr_IOselreg = regs[IOSEL];
      if (curr_IOselreg == 0x55)
	{
	  // Output mode
	  store_newdata(val);
	}
      // else 0xAA or any hex number other than 55 refers input mode 
  }
}


/* This helper function writes value represented by argument val
on PR register and calls another helper function to update output 
data pins according to the new value stored in register. 
Method returns no value.
*/
void
ParPort::store_newdata(host_int_1 val)
{
  regs[PR]= val;
  set_datapins(val); // updating output data pins

}


/* This method updates the output data pins (PD0-PD7) according to  
current value of PR register inorder to have register value & pins sync.
Method takes one argument of type host_int_1 representing the current 
value of PR register. Method returns no value.
*/ 
void
ParPort::set_datapins(host_int_1 new_prval)
{
  for (int i = 0; i < MAX_DATA_PINS; i++) {
    data_bus[i].drive (bit_test(new_prval, i) ? 1 : 0);
  }
}


/* This Handler is executed when error pin is driven.
Method updates bit #3 of SR register to represent 
current value of error pin. Argument to this method represents 
the currrent value of error pin. Method returns no value
*/
void
ParPort::error_handler(host_int_4 err_val)
{
  if (err_val) {
    // No error 
    if (!(bit_test(regs[SR], SR_ERROR))) 
      {
	bit_set(regs[SR], SR_ERROR);
      }
  }
  else {
    if (bit_test(regs[SR], SR_ERROR))
      {
	bit_clear(regs[SR], SR_ERROR);
      }
  }

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}


/* This Handler is executed when slct pin is driven.
Method updates bit #4 of SR register to represent 
current value of slct pin. Argument to this method represents 
the currrent value of slct pin. Method returns no value
*/
void
ParPort::slct_handler(host_int_4 slct_val)
{
  if (slct_val) {
    if (!(bit_test(regs[SR], SR_SLCT)))
      {
	bit_set(regs[SR], SR_SLCT); 
      }
  }
  else {
    if (bit_test(regs[SR], SR_SLCT)) 
      {
	bit_clear(regs[SR], SR_SLCT);
      }
  }

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}


/* This Handler is executed when page empty pin is driven.
Method updates bit #5 of SR register to represent 
current value of PE pin. Argument to this method represents 
the currrent value of PE pin. Method returns no value
*/
void
ParPort::page_empty_handler(host_int_4 pe_val)
{
  if (pe_val) {
    // logic 1 val
    if (!(bit_test(regs[SR], SR_PE))) 
      {
	bit_set(regs[SR], SR_PE); 
      }
  }
  else {
    // low signal
    if (bit_test(regs[SR], SR_PE))
      {
	bit_clear(regs[SR], SR_PE);
      }
  }   

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}


/* This Handler is executed when ack pin is driven.
Method updates bit #6 of SR register to represent 
current value of ack pin. Argument to this method represents 
the currrent value of ack pin. Method returns no value
In addition to updating its corresponding bit in SR register,
method also checks for the interrupt which is driven at the 
falling edge of the ack signal. 
*/
void
ParPort::ack_handler(host_int_4 ack_val)
{
 if (!ack_val) { 
   // ACK* signal from printer(Falling Edge)	
    bit_clear(regs[SR], SR_ACK);
    set_intp_acklow(); // falling edge check other pins 
 } 	
 else { 
   // if ack is high
   bit_set(regs[SR], SR_ACK);
   set_intp_ackhigh(); // rising edge 
 }

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}


/* This method is called upon receiving the falling edge of ack signal.
Latched interrupt is set iff INTSEL pin =1 & INTP is enabled.
In case when INTSEL=0, bit 2 of SR just follows ACK, whereas if 
INTSEL =1, and INTP is 0, bit 2 of SR is set high as interrupts are 
requested to be disbled by the application program.
*/
void
ParPort::set_intp_acklow()
{
  if ((AL_intsel_val) &&(bit_test(regs[COM], COM_IRQ_MASK))) 
    {
      // set Interupt INTP =0 & set ACK bit
      // I should check if it is already in interript mode or not.
      // If in interrupt mode then I should update 
      bit_clear(regs[SR],SR_IRQ);
      AL_irq_mask.off();
    }

  else if ((!AL_intsel_val) &&(bit_test(regs[COM], COM_IRQ_MASK))) 
    {
      bit_clear(regs[SR], SR_IRQ);
      AL_irq_mask.on();
    }

  else if ((!AL_intsel_val) &&(!bit_test(regs[COM],
					     COM_IRQ_MASK))) 
    {
      bit_clear(regs[SR], SR_IRQ);
      // INTP Pin is in Tristate mode.
      AL_irq_mask.on();
    }

  else
    { 
      // intsel = 1, INTP pin = 0; 
      //  bit_clear(regs[SR], SR_IRQ); // Interrupt pending latch 
      bit_set(regs[SR],SR_IRQ); // not taking interrupt. Late decision
      AL_irq_mask.on();
      // Pin is in tristate mode.
    }
}


/*  This method is called when rising edge of ack signal is received. 
If INTSEL pin = 0, IRQ bit in SR reg. follows ack pin (in this case it 
will be one). Else if INTSEL = 1 , IRQ bit is set to one (latched mode).
INTP output pin displays same value as IRQ bit provided INTP bit ( bit #4 
Control register) is not disabled. Method takes no argument and returns 
no value.
*/ 
void
ParPort::set_intp_ackhigh()
{
  if ((AL_intsel_val) &&(bit_test(regs[COM], COM_IRQ_MASK))) {
    if (bit_test(regs[SR],SR_IRQ)) { // currently I am in not pending
      bit_set(regs[SR],SR_IRQ); // No interrupt not falling edge
      AL_irq_mask.on();  // no interrupt. same reason
    }
    else { 
      // I am in pending so keep this bit low until SR read
    }
  }
  else if ((!AL_intsel_val) &&(bit_test(regs[COM], COM_IRQ_MASK))) 
    {
      bit_set(regs[SR], SR_IRQ);
      AL_irq_mask.off();
    }
  else if ((!AL_intsel_val) &&(!bit_test(regs[COM], COM_IRQ_MASK))) 
    {
      bit_set(regs[SR], SR_IRQ);
      AL_irq_mask.on();
      // INTP Pin is in Tristate mode.
    }
  else 
    { // intsel = 1, INTP pin = 0;
      bit_set(regs[SR], SR_IRQ); // Interrupt pending latch 
      AL_irq_mask.on();
      // Pin is in tristate mode. ??  check for error
    }
}


/* This Handler is executed when busy pin is driven.
Method updates bit #7 of SR register to represent 
current value of busy pin. Argument to this method represents 
the currrent value of busy pin. Method returns no value
*/
void
ParPort::busy_handler(host_int_4 busy_val)
{
  if (busy_val) 
    {
      // Got a busy signal 
      if (!bit_test(regs[SR], SR_BUSY))
	{
	  // bit set, clear the bit
	  //	  bit_clear(regs[SR], SR_BUSY);
	  bit_set(regs[SR], SR_BUSY);
	}
    }
  else 
    {
      // Not busy
      if ((bit_test(regs[SR], SR_BUSY)))  
	{
	  // bit clear, set the bit
	  //bit_set(regs[SR], SR_BUSY);
	   bit_clear(regs[SR], SR_BUSY);
	}
    }

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();

}


/* This method is called when INTSEL pin is driven.
Method takes one argument which represents the 
newly value driven on INTSEL pin. Upon driven,
method checks whether new value of INTSEL is 0 or 1.
If value is zero, IRQ  (bit #2 SR register) follows ACK.
else if value is non-zero, IRQ bit is set to one. (latch mode)
Similarly if INTP (bit 4 CON Register) is set then INTP pin
follows ACK when INTSEL =0. WHile INTSEL =1, INTP pin is 
set 0 (low signal)
*/
void
ParPort::intsel_handler(host_int_4 val)
{
  AL_intsel_val = val;
  if (!val) 
    {
      // JUST FOLLOW
      if (!bit_test(regs[SR],SR_ACK)) 
	{
	  bit_clear(regs[SR], SR_IRQ);
	  AL_irq_mask.on ();
      }
      else {
	// when ack* is high
	bit_set(regs[SR], SR_IRQ);
	if (bit_test(regs[COM], COM_IRQ_MASK))
	  {
	    AL_irq_mask.off();
	  }
        else 
	  AL_irq_mask.on (); // Tristate mode
      }
    }
  else 
    {
      // assuming it is 1 and not tristated, Latch mode
      bit_set(regs[SR], SR_IRQ); 
      // AcK low or high int missed. so it is set
      AL_irq_mask.on(); 
    }

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}


/* This method is called when biden pin is driven.
Method simply copies the current biden value into one 
of its simulation variables. Method takes one argument of 
type host_int_4 representing current biden value.
Method returns no value 
*/   
void
ParPort:: biden_handler ( host_int_4 bid_val)
{
  biden_val = ( (bid_val > 0) ? 1 : 0 ); 

 // check for triggerpoints
  triggerpoint_manager.check_and_dispatch ();
}


/* This method stores value in control register.
Method takes the new value user wants to store in
control register as argument. This method also calls 
other helper methods to drive the output pins to have pins 
& regs values sync. Method returns no value.
*/ 
void
ParPort::store_contval(host_int_1 cnt_val)
{
// Get changes in Control register
  host_int_1 changes = regs[CON] ^ cnt_val;

  for(int i= 0; i < 6; ++i) {
    if (bit_test(changes, i)) 
      {
	// Change has made 
	int chbit_val = bit_test(cnt_val, i); // new bit value.(For debug)  
	
	switch (i) {
	case 0: 
	  change_strobe(chbit_val);
	  break;

	case 1:
	  change_autofdxt(chbit_val);
	  break;

	case 2:
	  change_init(chbit_val);
	  break;

	case 3:
	  change_slctin(chbit_val);
	  break;

	case 4:
	  change_intp(chbit_val);
	  break;

	case 5:
	  change_ioselect(chbit_val);
	  break;

	default:
	  cerr << " Error in StoreContl \n";
	  break;
	}
      }
  }
  // Finally change the value.
  regs[CON] = cnt_val;  // not needed 
}


/*  Following method is called when strobe bit changes its value.
This method drives the strobe pin to update the output
strobe pin and to inform printer that data is available.
Method takes one argument representing new value of 
strobe bit. Method returns no value.
*/
void
ParPort::change_strobe(int val)
{
  int old_regpinval = bit_test(regs[COM],COM_STROBE);

  if (test_change(old_regpinval, val)) 
    {
      if (!old_regpinval) { // New reg pin val= 1 or true
	// means strobe is asserted(thue pin will signal low)
	AL_strobe.on(); // output signal low.
	bit_set(regs[COM],COM_STROBE);
	bit_set(regs[CON],CON_STROBE); // useless
      }
      else {
	// new reg value for this pin is 0(Strobe de-asserted)
	AL_strobe.off(); // high signal
	bit_clear(regs[COM], COM_STROBE);
	bit_clear(regs[CON], CON_STROBE); // useless
      }
    }
  else
    cerr <<" error in change_strobe  \n";
}


/* This method is called when autofdxt bit (bit #1 Con reg)
is changed. Method takes one argument representing new 
bit value. Method updates the output pin according to the 
new bit value. By updating output pin, pin & reg values
are sync. also printer is informed for automatic line feed backup
after printing each line. Method returns no value.
*/   
void
ParPort::change_autofdxt(int val)
{
  int curr_regpinval = bit_test(regs[COM], COM_AUTOFDXT);
 
 if (test_change(curr_regpinval, val)) 
   {
     if (! curr_regpinval) 
       {
	 // New reg value =1 or true
	 // Output mode AUTOFDXT signals low.
	 AL_autofdxt.on();
	 bit_set(regs[COM], COM_AUTOFDXT);
	 bit_set(regs[CON], CON_AUTOFDXT);
       }
     else {
       // new value is 0 or FALSE
       AL_autofdxt.off();
       bit_clear(regs[COM], COM_AUTOFDXT);
       bit_clear(regs[CON], CON_AUTOFDXT);
     }
   }
 else
   cerr << " ERROR IN change_autofdxt \n";
}


/* This method is called when init bit (bit #2 Control register)
is changed. Method updates the init output pin to inform
printer to be initialized. Method takes one argument representing
the new init bit value. Method returns no value.
*/ 
void
ParPort::change_init(int val)
{
 int curr_regpinval = bit_test(regs[COM], COM_INIT);
 
 if (test_change(curr_regpinval, val))
   {
     if (!curr_regpinval) 
       { // current val is 1(true)
	 init.on();
	 bit_set(regs[COM], COM_INIT);
	 bit_set(regs[CON], CON_INIT);	 
       }
     else { // new init reg val is 0
       init.off(); // sending initialization signal.
       bit_clear(regs[COM], COM_INIT);
       bit_clear(regs[CON], CON_INIT);
     }
   }
 else 
   cerr <<" ERROR IN change_init \n";
}


/* Method is called when slctin bit (bit# 3 Con reg.) value is changed.
Method updates the output slctin pin & selects the printer.
Method takes one argument representing new slctin bit value
& returns no value.
*/  
void
ParPort::change_slctin(int val)
{
 int curr_regpinval = bit_test(regs[CON], CON_SLCTIN);

 if (test_change(curr_regpinval, val))
   {
     if (! curr_regpinval) 
       { 
	 // new value 1
	 AL_slctin.on(); // need to select printer LOW signal
	 bit_set(regs[COM], COM_SLCTIN);
	 bit_set(regs[CON], CON_SLCTIN);
       }
     else 
       {	
	 // new value 0
	 AL_slctin.off();
	 bit_clear(regs[COM], COM_SLCTIN);
	 bit_clear(regs[CON], CON_SLCTIN);
       }
   }
 else
   {
     cout << " error found in change_slctin \n";
     assert(0);
   }
}


/* This method is called when INTP bit (bit# 4 Con reg.) is
changed. New INTP is passed to method as argument.
If new bit value is 0, the interrupt is disabled, and INTP pin 
is in tristate mode. Otherwise, INTP pin value is set depending
upon the value of INTSEL, and ACK. (see documentation of SetINTPpin 
function) Method returns no value.
*/    
void
ParPort::change_intp(int val)
{  
 int curr_regpinval = bit_test(regs[COM], COM_IRQ_MASK);
  if (test_change(curr_regpinval, val)) 
    {
      if (! curr_regpinval)
	{
	  // new value 1
	  bit_set(regs[CON], CON_IRQ_MASK);
	  bit_set(regs[COM], COM_IRQ_MASK);
	  set_intppin();  // Is called when INTP is not tristated.
	}
      else 
	{
	  // new value 0
	  AL_irq_mask.on(); // Tristate mode.
	  bit_clear(regs[COM], COM_IRQ_MASK);
	  bit_clear(regs[CON], CON_IRQ_MASK);
	  if ((AL_intsel_val) &&(!bit_test(regs[SR],SR_IRQ)))
	    {
	      // no more interrupt even standing interrupt.
	      bit_set (regs[SR], SR_IRQ); 
	    }
	}
    }
  else 
    cout << " error found in chang_intp \n";
}


/* This method is called when bit# 5 of Control register is changed.
Method sets the value of bit# 5 as per requested by application.
This bit is used to select between software controlled IO versus
software/hardware controlled IO. Method takes one argument 
representing the new value for bit 5. Method returns no value.
*/ 
void
ParPort::change_ioselect(int val)
{
 int curr_regpinval = bit_test(regs[CON], CON_IO_SELECT);
 
 if (test_change(curr_regpinval, val))
   {
     if (! curr_regpinval)
       {
	 // new value 1
	 bit_set(regs[CON], CON_IO_SELECT);
       }
     else
       {
	 // new value 0
	 bit_clear(regs[CON], CON_IO_SELECT);
       }
   }
 else 
   {
     cout << " error found in change_ioselect \n";
     assert(0);
   }
}


/* This method is used for debugging purposes.
It compares two values passed argument and returns
true if they are not equal otherwise returns false.
*/ 
bool
ParPort::test_change(int val1 , int val2)
{
   return (val1 != val2);
} 


/* This method sets the INTP output pin when INTP bit (bit#4 control reg.)
is enabled.  If INTSEL = 0, INTP output pin will just follow the ACK 
otherwise when INTSEL  = 1, INTP output pin will set to low (0).
Method takes no argument and returns no value.
*/ 
void
ParPort::set_intppin()
{
  if (! bit_test(regs[SR],SR_ACK)) { // ACK signal = low
    if (AL_intsel_val) { // latched mode 
      AL_irq_mask.on() ;  // I have missed inter(no falling edge)
      bit_set(regs[SR],SR_IRQ); // no interrupt
    }
    else {  // intsel = 0 follow mode. 
      AL_irq_mask.on(); // Following AL_ack
      bit_clear(regs[SR],SR_IRQ);
    }
  }

  else { // ack* state =1
    if (AL_intsel_val) { 
      AL_irq_mask.on(); // no interrupt ACK* is high
      bit_set(regs[SR],SR_IRQ);
    }
    else {
     AL_irq_mask.off(); // Follow
     bit_set(regs[SR],SR_IRQ);
    }
  }
}

void
ParPort::intsel_attrhandler() 
{
  // assuming Al_intsel_val is already updated
  intsel_handler (AL_intsel_val);
}


// Constructor of nested class parport_inputpin 
ParPort::parport_inputpin::parport_inputpin(ParPort* owner_obj,
					  void(ParPort::*fun_ptr)(host_int_4),
					  bool pin_type)
  :parport(owner_obj),
   handle_driven(fun_ptr)
{
  if (pin_type)
    {
      // If it is set high.
      this->set_active_high();
    }
}


// Overwriting driven method.
void
ParPort::parport_inputpin::driven(host_int_4 input_val) throw ()
{
  value = input_val;
  (parport->*handle_driven)(input_val);
}


/* Friend function to print details of object referenced by
second argument to stream referenced by first argument.
Method returns a reference to an object of type ostream
*/
ostream& 
operator <<  (ostream& op, const ParPort& copy_obj) 
{

  /* Copying input Pins that have no corresponding register bits 
     in parallel port */
  op << "Biden "  << copy_obj.biden_val << ":";
  op << "Intsel " << copy_obj.AL_intsel_val << ":";

  // First copying all 5 internal registers.
  op << "InterRegs ";
  op << (host_int_4) copy_obj.regs[IOSEL] << " ";
  op << (host_int_4) copy_obj.regs[CON]   << " ";
  op << (host_int_4) copy_obj.regs[PR]    << " ";
  op << (host_int_4) copy_obj.regs[SR]    << " "; 
  op << (host_int_4) copy_obj.regs[COM];

  // Copy all pins
  op << " Pins ";
  op << copy_obj.AL_strobe << " "
     << copy_obj.AL_autofdxt << " "
     << copy_obj.AL_slctin << " "
     << copy_obj.init << " "
     << copy_obj.AL_irq_mask << " "
     << copy_obj.data_bus[0] << " "
     << copy_obj.data_bus[1] << " "
     << copy_obj.data_bus[2] << " "
     << copy_obj.data_bus[3] << " "
     << copy_obj.data_bus[4] << " "
     << copy_obj.data_bus[5] << " "
     << copy_obj.data_bus[6] << " "
     << copy_obj.data_bus[7] << " "
     << copy_obj.AL_error << " "
     << copy_obj.slct << " "
     << copy_obj.page_empty << " "
     << copy_obj.AL_ack << " "
     << copy_obj.busy << " "
     << copy_obj.reset_pin << " "
     << copy_obj.biden << " "
     << copy_obj.AL_intsel;

  // NB: no whitespace at end!

  return op;
}

/* This friend function is used to read info. from stream 
refernced by first argument and store in object 
of type ParPort referenced by second argument.
Method returns a reference to an object of type istream.
*/
istream&
operator >> (istream& ip, ParPort& ovwrite_obj)
{
  string coding;
  char sep;

  ip >> coding; // biden pin
  if (coding != "Biden") 
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.biden_val ;
  ip.get(sep); // :

  ip >> coding; // Intsel Pin
  if (coding != "Intsel") 
    {
       ip.setstate(ios::badbit);
       return ip;
    }
  ip >> ovwrite_obj.AL_intsel_val;
  ip.get(sep); // :
  
  ip >> coding;
  if  (coding != "InterRegs")
    {
       ip.setstate(ios::badbit);
       return ip;
    }

  host_int_4 reg_val;

  ip >> reg_val; // IOSEL register
  ovwrite_obj.regs[IOSEL] = reg_val;

  ip >> reg_val; // CON val
  ovwrite_obj.write_parport(2, reg_val); // Pins will be updated

  ip >> reg_val; //PR reg
  if ( ! ovwrite_obj.output_mode() )
    ovwrite_obj.regs[PR] = reg_val;
  else // output mode Pins will be updated accordingly
    ovwrite_obj.store_newdata(reg_val);  
    
  ip >> reg_val;// SR regs
  ovwrite_obj.regs[SR] = reg_val;
 
  ip >> reg_val; // COM value
  ovwrite_obj.regs[COM] = reg_val;

  // Copy all pins
  ip >> coding;
  if (coding != "Pins")
    {
       ip.setstate(ios::badbit);
       return ip;
    }

  ip >> ovwrite_obj.AL_strobe 
     >> ovwrite_obj.AL_autofdxt 
     >> ovwrite_obj.AL_slctin 
     >> ovwrite_obj.init 
     >> ovwrite_obj.AL_irq_mask 
     >> ovwrite_obj.data_bus[0] 
     >> ovwrite_obj.data_bus[1] 
     >> ovwrite_obj.data_bus[2] 
     >> ovwrite_obj.data_bus[3] 
     >> ovwrite_obj.data_bus[4] 
     >> ovwrite_obj.data_bus[5] 
     >> ovwrite_obj.data_bus[6] 
     >> ovwrite_obj.data_bus[7] 
     >> ovwrite_obj.AL_error 
     >> ovwrite_obj.slct 
     >> ovwrite_obj.page_empty 
     >> ovwrite_obj.AL_ack 
     >> ovwrite_obj.busy 
     >> ovwrite_obj.reset_pin 
     >> ovwrite_obj.biden
     >> ovwrite_obj.AL_intsel;
    
  return ip;
}


bool
ParPort::output_mode ()
{
  if ( (biden_val) && (! (bit_test(regs[CON], CON_IO_SELECT)) )  
    || ( (!biden_val) && ( regs[IOSEL] == 0x55)) )
     {
      return true;
    }

  return false;
}


void 
ParPort::parport_iopin::driven (host_int_4 value) throw ()
{
  // only if I am in input mode.
  if ( port_ptr->iopins_readmode() ) 
    {  
      port_ptr->update_ipprreg(datapin_num, value);
    }
  // check for triggerpoints
  port_ptr->triggerpoint_manager.check_and_dispatch ();
}


int ParPort:: iopins_readmode() const
{
   host_int_4 val_ioselreg = regs[IOSEL];

   // biden = 1&& bit 5 == 1   OR    biden ==0 && io select reg != 55 
   if ( ((biden_val) && (bit_test(regs[CON], CON_IO_SELECT))) || 
        ((!biden_val) && (val_ioselreg != 0x55)) ) 
     {
	    return 1;
     }
   else
     {
	  return 0;
     }
}
    

void 
ParPort::update_ipprreg( host_int_2 pin_num, host_int_4 pin_val)
{
   if (pin_val == 0) 
     {
	bit_clear (regs[PR], pin_num);
     }
   else if (pin_val == 1)
     {
        bit_set  (regs[PR], pin_num);
     }
   else 
     {
       cerr << " Some wrong value on input data pin is driven \n";
     }
} 



/* Following methods are used to create library,
   and store information about parallel port in library. 
*/
static vector<string>
ParPortListTypes()
{
  vector<string> types;
  types.push_back(string("hw-parport-ps/2"));
  return types;
}


static component*
ParPortCreate(const string& typeName)
{
  if (typeName == "hw-parport-ps/2")
    return new ParPort();
  else
    return 0;
}


static void
ParPortDelete(component* c)
{
  delete dynamic_cast<ParPort*>(c);
}


// static object
extern const component_library parport_component_library;

const component_library parport_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & ParPortListTypes, 
  & ParPortCreate,
  & ParPortDelete
};
