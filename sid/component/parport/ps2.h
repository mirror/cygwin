// ps2.h - Simulation of PS/2 parallel controller.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef PARPORT_H
#define PARPORT_H

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidbusutil.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidpinattrutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::cerr;
using std::cout;

using sid::component;
using sid::host_int_1;
using sid::host_int_2;
using sid::host_int_4;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_pin_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_attribute_map_component;
using sidutil::no_accessor_component;
using sidutil::no_relation_component;
using sidutil::binary_input_pin;
using sidutil::callback_pin;
using sidutil::binary_output_pin;
using sidutil::output_pin;
using sidutil::inputoutput_pin;
using sidutil::input_pin;
using sidutil::callback_byte_bus;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::self_watcher;


class ParPort: public virtual component,
	       public no_accessor_component,
	       public fixed_attribute_map_component,
	       public no_relation_component,
	       public fixed_bus_map_component,
	       public fixed_pin_map_component
{
 public: 
  ParPort();
  void reset(host_int_4);
  
 private:

  // Triggerpoint manager
  friend class self_watcher<ParPort>;
  self_watcher<ParPort> triggerpoint_manager;

  // Virtual pin interfaces between self_watcher and fixed_pin_map_component
 sid::component::status
  pin_factory(const std::string& name)
    {
      return this->triggerpoint_manager.create_virtual_pin (name);
    }

  void
  pin_junkyard(const std::string& name)
    {
      this->triggerpoint_manager.destroy_virtual_pin (name);
    }

  enum { NUM_REGS = 5, MAX_DATA_PINS = 8 };

  // 4 regs required for parallel port.
  host_int_1 regs [NUM_REGS];
  
  // STROBE* pin internally active high 
  binary_output_pin  AL_strobe;
  
  // AUTOFDXT* pin internally active high
  binary_output_pin  AL_autofdxt; 
  
  // SLCTIN* pin internally active high
  binary_output_pin  AL_slctin;  

  // INIT pin internally active low
  binary_output_pin  init; 
 
  // INTP* pin internally active high.
  binary_output_pin  AL_irq_mask; 

public:
  class parport_iopin : public inputoutput_pin
  {
  private:
    ParPort *port_ptr;
    host_int_2 datapin_num;

  public:
    parport_iopin(): port_ptr(0) {}

    // Need non-constructor since an array of these beasts is being
    // allocated.
    void init (ParPort *pport, host_int_2 pin_num)
      {
	assert (port_ptr == 0);
	port_ptr = pport;
	datapin_num = pin_num;
      } 

    bool input_mode_p () const
      {
	assert (port_ptr != 0);
	return port_ptr->iopins_readmode (); 
      }

    void driven (host_int_4 value) throw ();
  };
  friend class parport_iopin;

private:
  // Bidirectional Printer Data bus PD0 (LSB) - PD7 (MSB)
  parport_iopin data_bus[8];

  // Class to handle 'driven' method properly
  class parport_inputpin: public binary_input_pin 
  {
   private:
    ParPort *parport;
    void (ParPort::*handle_driven)(host_int_4);
    
   public:
    parport_inputpin ()
      :parport(0), handle_driven(0) {}
    
    parport_inputpin(ParPort* owner_obj, 
		    void (ParPort::*fun_ptr)(host_int_4),  
		    bool pin_type = false);
    
    void driven(host_int_4 input_val) throw ();
  };
  
  friend class parport_inputpin; 
	
  // ERROR* to indicate an error 
  parport_inputpin AL_error;

  // SLCT pin refers Printer is selected. 
  parport_inputpin slct;	
  
  // PE pin indicating out of paper
  parport_inputpin page_empty; 

  // ACK* to indicate data accepted by printer 
  parport_inputpin AL_ack;
  
  // BUSY pin Internally active low. Printer busy 
  parport_inputpin busy; 
  
  // Select interrupt type
  parport_inputpin AL_intsel; 
  
  // Bi-directional pin
  parport_inputpin biden; 
  
  callback_pin <ParPort> reset_pin;
  
  host_int_4 biden_val;
  host_int_4 AL_intsel_val;

  // Methods to handle input signals from device.
  void error_handler(host_int_4 err_val);
  void slct_handler(host_int_4 sclt_val);
  void page_empty_handler(host_int_4 pe_val);
  void ack_handler(host_int_4 ack_val);
  void busy_handler(host_int_4 busy_val);
  void intsel_handler(host_int_4 int_val);
  void biden_handler (host_int_4 bid_val );  
  
  // Transmit data to device
  void printer_data(host_int_1 val);
  
  callback_byte_bus <ParPort> bus_size; 
  
  // Read Registers.
  sid::bus::status read_parport(host_int_4 reg_index, 
			        host_int_1& reg_val);
  
  // Write to Registers.
  sid::bus::status write_parport (host_int_4 reg_index, 
				  host_int_1 reg_val);  
  
  void add_bus_pins();
  void store_registerAttr();
  void store_outputpinAttr();
  void store_inputpinAttr();
  void initialize_bioutpins();
  void reset_internalregs();
  void reset_outputpins();
  void sense_inputpins();
  void clear_intp();
  void set_datapins(host_int_1 new_prval);
  void store_contval(host_int_1 cnt_val);
  void change_strobe(int val);
  void change_autofdxt(int val);
  void change_init(int val);
  void change_slctin(int val);
  void change_intp(int val);
  void change_ioselect(int val);
  bool test_change(int val1, int val2);
  void store_newdata(host_int_1 val);
  void set_intppin();
  void set_intp_acklow();
  void set_intp_ackhigh();
  void initialize_iodatapins();
  void update_ipprreg (host_int_2 pin_num, host_int_4 pin_val);
  int iopins_readmode () const;
  bool output_mode ();
  void intsel_attrhandler ();

  std::string save_state () {return make_attribute(*this);}
  sid::component::status restore_state (const string& state)
    { return parse_attribute (state, *this); }
  friend ostream& operator << (ostream& op, const ParPort& copy_obj);
  friend istream& operator >> (istream& ip, ParPort& ovwrite_obj);
};


namespace sidutil
{

  inline std::string
  make_attribute( const ParPort::parport_iopin& pin)
    {
      return make_attribute( * (inputoutput_pin*) &pin);
    }

  inline sid::component::status
  parse_attribute( const std::string& str, ParPort::parport_iopin& pin )
    {
      return parse_attribute( str, * (inputoutput_pin*) &pin);
    }
}


#endif // PARPORT_H	
