// compIDE.cxx - An IDE disk drive component.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidpinattrutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidwatchutil.h>

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
#include <cerrno>

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;
using std::cerr;
using std::endl;
using std::ios;
using std::filebuf;

using sid::component;
using sid::COMPONENT_LIBRARY_MAGIC ;
using sid::component_library;
using sid::host_int_1;
using sid::host_int_2;
using sid::host_int_4;
using sid::host_int_1;
using sid::big_int_1;
using sid::big_int_2;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;

using sidutil::fixed_attribute_map_component;
using sidutil::no_accessor_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::no_relation_component;
using sidutil::output_pin;
using sidutil::control_register_bus;
using sidutil::callback_control_register;
using sidutil::value_control_register;
using sidutil::fixed_control_register;
using sidutil::attribute_coder_base;
using sidutil::attribute_coder_bus_ro;
using sidutil::attribute_coder_bus_wo;
using sidutil::attribute_coder_bus_rw;
using sidutil::self_watcher;
using sidutil::string2stream;
using sidutil::stream2string;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::std_error_string;


// ---------------------------------------------------------------


// This class overrides the word_bus<>' post_access_hook to call the
// triggerpoint check function in ide_controller.
class ide_controller;
class ide_hooking_register_bus: public control_register_bus<little_int_1>
{
private:
  ide_controller* foe;
  void post_access_hook();

public:
  ide_hooking_register_bus(ide_controller* f): foe(f) {}
  ~ide_hooking_register_bus () throw() {}
};


// This is a proxy bus for the IDE controller/drive command bus only.
// It is necessary since the default word_bus<> cannot tell apart a
// single 16-bit access to the data port from two 8-bit accesses to
// the data and adjacent error/precomp ports.
class ide_command_bank_bus: public ide_hooking_register_bus
{
public:
  ide_command_bank_bus(ide_controller* c): ide_hooking_register_bus(c) {}

  // Override only 16-bit read/write operations from address 0.
  // Decompose 16-bit data into low & high parts.  Prefer
  // little-endian interpretation.
  bus::status
  write (host_int_4 addr, little_int_2 data) throw ()
    {
       if (addr == 0)
	 {
	    little_int_1 low = data.read_byte (0);
	    little_int_1 high = data.read_byte(1);
	    bus::status s1 = this->sidutil::word_bus<little_int_1>::write(addr, low);
	    bus::status s2 = this->sidutil::word_bus<little_int_1>::write (addr, high);
	    return (s1 == bus::ok ? s2 : s1);
	 }
       else
	 {
	      // pass to base class
	   return control_register_bus<little_int_1>::write (addr, data);
	 }
    }

  bus::status
  write (host_int_4 addr, big_int_2 data) throw ()
    {
      little_int_2 ledata;
      ledata.write_byte (0, data.read_byte(0));
      ledata.write_byte (1, data.read_byte(1));
      return this->write(addr, ledata);
    }

  bus::status
  read (host_int_4 addr, little_int_2& data) throw ()
    {
      if (addr == 0)
	{
	   little_int_1 low, high;
	   bus::status s1 = this->sidutil::word_bus<little_int_1>::read (addr, low);
	   data.write_byte (0, low);
	   bus::status s2 = this->sidutil::word_bus<little_int_1>::read (addr, high);
	   data.write_byte (1, high);
	   return (s1 == bus::ok ? s2 : s1);
	}
        else
	  {
	      // pass to base class
	    return control_register_bus<little_int_1>::read (addr, data);
	  }
    }

  bus::status
  read (host_int_4 addr, big_int_2& data) throw ()
    {
       little_int_2 ledata;
       bus::status s = this->read(addr, ledata);
       data.write_byte (0, ledata.read_byte(0));
       data.write_byte (1, ledata.read_byte(1));
       return s;
    }
};

// This is an IDE controller/drive model.  It is a small subset of the
// old ATA-1 standard using polled-I/O.  The primary reference used
// was the Quantum Bigfoot AT hard drive reference manual.

class ide_controller: public virtual component,
		      protected fixed_attribute_map_component,
		      protected no_accessor_component,
		      protected fixed_pin_map_component,
		      protected fixed_bus_map_component,
		      protected no_relation_component
{
protected:
  // "Command block" register bank
  ide_hooking_register_bus controlbus;

  // "Control block" register bank
  ide_command_bank_bus commandbus;

  // ALTERNATE STATUS register.  Represent most bits individually.
  value_control_register<little_int_1> altstatus_reg_drdy;
  value_control_register<little_int_1> altstatus_reg_drq;
  value_control_register<little_int_1> altstatus_reg_error;
  fixed_control_register<little_int_1> altstatus_reg_rest;
  // CONTROL register.
  callback_control_register<little_int_1, ide_controller> device_control_reg_srst;
  value_control_register<little_int_1> device_control_reg_nien;  // negated interrupt enable
  fixed_control_register<little_int_1> device_control_reg_rest;
  // DRIVE ADDRESS register.  Acts like drives always idle.
  fixed_control_register<little_int_1> drive_address_reg;

  // DATA PORT register.
  callback_control_register<little_int_1, ide_controller> data_port_reg;
  // ERROR register.  Implements ABRT and AMNF bits only.
  value_control_register<little_int_1> error_reg_abrt;
  value_control_register<little_int_1> error_reg_amnf;
  fixed_control_register<little_int_1> error_reg_rest;
  // PRECOMP register.  Ignored.
  fixed_control_register<little_int_1> precomp_reg;
  // SECTOR/CYLINDER registers.
  value_control_register<little_int_1> sector_count_reg;
  value_control_register<little_int_1> sector_number_reg;
  value_control_register<little_int_1> cylinder_low_reg;
  value_control_register<little_int_1> cylinder_high_reg;
  // DRIVE/HEAD register.
  value_control_register<little_int_1> drive_head_reg_l;
  value_control_register<little_int_1> drive_head_reg_drive;
  value_control_register<little_int_1> drive_head_reg_head;
  fixed_control_register<little_int_1> drive_head_reg_rest;
  // STATUS register.  Equivalent to ALTSTATUS read, plus interrupt reset.
  callback_control_register<little_int_1, ide_controller> status_reg;
  // COMMAND register.
  callback_control_register<little_int_1, ide_controller> command_reg;

  // Triggerpoint manager
  friend class self_watcher<ide_controller>;
  self_watcher<ide_controller> triggerpoint_manager;

  // Virtual pin interfaces between self_watcher and fixed_pin_map_component
  sid::component::status 
  pin_factory(const std::string& name)
    {
      // cerr << "ide_controller::pin_factory" << endl;
      return this->triggerpoint_manager.create_virtual_pin (name);
    }
  void
  pin_junkyard(const std::string& name)
    {
      // cerr << "ide_controller::pin_junkyard" << endl;
      this->triggerpoint_manager.destroy_virtual_pin (name);
    }

  // Hook interfaces between self_watcher and control_register_buses
  friend class ide_hooking_register_bus;
  void
  post_access_hook()
    {
      // cerr << "ide_controller::post_access_hook" << endl;
      this->triggerpoint_manager.check_and_dispatch();
    }


  // back-ends
public:
  struct drive
  { 
    bool present;
    string filename;
    fstream* file;
    host_int_2 num_cylinders;
    host_int_1 num_heads;
    host_int_1 num_sectors;

  private:
    enum { fifo_length = 512 }; // XXX: == sector size -- fixed?
    host_int_1 fifo[fifo_length];
    unsigned fifo_index;

  public:
    drive():
      present (false), filename ("/dev/null"), file(0),
      num_cylinders (0), 
      num_heads (0),
      num_sectors (0)
      { for (unsigned i=0 ; i < fifo_length; i++) this->fifo[i] = 0;
	fifo_index = 0;
	this->filename_changed();
      }

    ~drive()
      {
	if (this->file)
	  delete this->file;
      }

    // open new read/write fstream for this file name
    void
    filename_changed ()
      {
	if (this->file) delete this->file;
	this->file = new fstream (this->filename.c_str(), ios::in | ios::out | ios::binary);
	this->check_file_good ("opening");
      }

    void
    check_file_good(const string& message)
      {
	if (! this->file->good())
	  {
	    cerr << "Error while " << message << " " 
		 << this->filename << ": " << std_error_string() << endl;
	  }
      }

    void fifo_push (host_int_1 v) 
      {
	assert(this->fifo_index < fifo_length);
	this->fifo[this->fifo_index++] = v; 
      }
    host_int_1 fifo_pop () 
      { 
	assert(this->fifo_index < fifo_length);
	return this->fifo[this->fifo_index++]; 
      }

    // internal functions for identify_drive use only
    void fifo_push_short (host_int_2 value)
      {
	// defined as little endian
	little_int_2 little_value = value;
	this->fifo_push (little_value.read_byte(0));
	this->fifo_push (little_value.read_byte(1));
      }
    void fifo_push_long (host_int_4 value)
      {
	// defined as little endian
	little_int_4 little_value = value;
	this->fifo_push (little_value.read_byte(0));
	this->fifo_push (little_value.read_byte(1));
	this->fifo_push (little_value.read_byte(2));
	this->fifo_push (little_value.read_byte(3));
      }
    void fifo_push_string (const string& str, unsigned length)
      {
	const char* c = str.c_str();
	for (unsigned i=0; i<length; i++)
	  {
	    this->fifo_push (*c);
	    if (*c) c++; // increment, except if we are at end of string
	  }
      }

    void fifo_clear_rest ()
      {
	while(this->fifo_index < fifo_length)
	  this->fifo[this->fifo_index++] = 0;
      }

    bool sector_complete () 
      {
	return this->fifo_index == this->fifo_length; 
      }
    void reset () 
      {
	this->fifo_index = 0; 
      }
    void write_sector (unsigned block)
      {
	assert (this->file);

	filebuf* buf = this->file->rdbuf();
	unsigned long position = block * this->fifo_length; // XXX: should be something::pos_type
	// cerr << "seeking to position=" << position << " in file=" << this->filename << endl;
	buf->pubseekpos(position);

	if (this->file->good())
	  buf->sputn((const char*) & this->fifo[0], (std::streamsize) this->fifo_length);

	this->check_file_good ("writing");
	this->fifo_index = 0;
      }

    void read_sector (unsigned block)
      {
	assert (this->file);

	filebuf* buf = this->file->rdbuf();
	unsigned long position = block * this->fifo_length; // XXX: should be something::pos_type
	// cerr << "seeking to position=" << position << " in file=" << this->filename << endl;
	buf->pubseekpos(position);

	if (this->file->good())
	  buf->sgetn((char*) & this->fifo[0], (std::streamsize) this->fifo_length);

	this->check_file_good ("reading");
	this->fifo_index = 0;
      }

    friend ostream& operator << (ostream& o, const drive& it);
    friend istream& operator >> (istream& i, drive& it);
  };

protected:
  drive drive_data[2];

  // pins
  output_pin interrupt_pin;

  // controller state
  enum controller_state { idle, reading, reading_nowb, writing, writing_nowb } state;
  	 
  // register access callbacks
  void device_control_srst(little_int_1 value, little_int_1 mask);
  void data_port_set(little_int_1 value, little_int_1 mask);
  little_int_1 data_port_get();
  little_int_1 status_get();
  void command_set(little_int_1 value, little_int_1 mask);

  // work functions
  void interrupt(host_int_4 v)
    {
      if (this->device_control_reg_nien == 0 || v == 0)
	this->interrupt_pin.drive(v);
    }
  void reset();
  unsigned get_current_block() const;
  bool current_block_valid () const;
  void read_current_block ();
  void goto_next_block ();
  bool identify_drive ();

  // state control
  friend ostream& operator << (ostream& o, const ide_controller& it);
  friend istream& operator >> (istream& i, ide_controller& it);
  string save_state() { return make_attribute(*this); }
  sid::component::status restore_state(const string& state)
    { return parse_attribute(state, *this); }

  // constructor helpers
  void ide_controller_ctor_0 ();
  void add_watchable_register (const string& name, attribute_coder_base* coder);


public:
  ide_controller():
    controlbus(this),
    commandbus(this),
    // ctrl registers            bank         offset mask  read?  write?  (extra)
    altstatus_reg_drdy          (&controlbus, 0x00, 0x40, true,  false),
    altstatus_reg_drq           (&controlbus, 0x00, 0x08, true,  false),
    altstatus_reg_error         (&controlbus, 0x00, 0x01, true,  false),
    altstatus_reg_rest          (&controlbus, 0x00, 0xb6, true,  false, 0x12), // DSC | INDEX
    device_control_reg_srst     (&controlbus, 0x00, 0x04, false, true, this, & ide_controller::device_control_srst),
    device_control_reg_nien     (&controlbus, 0x00, 0x02, false, true),
    device_control_reg_rest     (&controlbus, 0x00, 0xf9, false, true,  0x08), // bit 3 always set
    drive_address_reg           (&controlbus, 0x01, 0xff, true,  false, 0xff), // fake disks as idle
    // cmd registers
    data_port_reg               (&commandbus, 0x00, 0xff, true,  true, this, & ide_controller::data_port_set, & ide_controller::data_port_get),
    error_reg_abrt              (&commandbus, 0x01, 0x04, true,  false),
    error_reg_amnf              (&commandbus, 0x01, 0x01, true,  false),
    error_reg_rest              (&commandbus, 0x01, 0xfa, true,  false, 0x00), // no errors
    precomp_reg                 (&commandbus, 0x01, 0xff, false, true,  0x00),
    sector_count_reg            (&commandbus, 0x02, 0xff, true,  true),
    sector_number_reg           (&commandbus, 0x03, 0xff, true,  true),
    cylinder_low_reg            (&commandbus, 0x04, 0xff, true,  true),
    cylinder_high_reg           (&commandbus, 0x05, 0xff, true,  true),
    drive_head_reg_l            (&commandbus, 0x06, 0x40, true,  true),
    drive_head_reg_drive        (&commandbus, 0x06, 0x10, true,  true),
    drive_head_reg_head         (&commandbus, 0x06, 0x0f, true,  true),
    drive_head_reg_rest         (&commandbus, 0x06, 0xa0, true,  true,  0xa0),
    status_reg                  (&commandbus, 0x07, 0xff, true,  false, this, & ide_controller::status_get),
    command_reg                 (&commandbus, 0x07, 0xff, false, true, this, & ide_controller::command_set),
    triggerpoint_manager        (this)
    {
      ide_controller_ctor_0();
    }

  ~ide_controller() throw() {}
};



void
ide_controller::add_watchable_register (const string& name, attribute_coder_base* coder)
{
  // add as register attribute
  add_attribute_coder (name,
		       coder,
		       "register");
  // add watchable
  this->triggerpoint_manager.add_watchable_attribute (name);
  // add as watchable
  categorize (name, "watchable");
}


void
ide_controller::ide_controller_ctor_0()
{
  // Use base of 0x3F0 for ISA primary IDE; 0x370 for ISA secondary IDE
  add_bus("control-block-bus", & this->controlbus);
  // Use base of 0x1F0 for ISA primary IDE; 0x170 for ISA secondary IDE
  add_bus("command-block-bus", & this->commandbus);
  
  // Attributes
  add_attribute("drive0-present?", & this->drive_data[0].present, "setting");
  add_attribute("drive1-present?", & this->drive_data[1].present, "setting");      
  add_attribute_notify("drive0-file", & this->drive_data[0].filename,
		       & this->drive_data[0], & ide_controller::drive::filename_changed, "setting");
  add_attribute_notify("drive1-file", & this->drive_data[1].filename,
		       & this->drive_data[1], & ide_controller::drive::filename_changed, "setting");
  add_attribute("drive0-num-cylinders", & this->drive_data[0].num_cylinders, "setting");
  add_attribute("drive1-num-cylinders", & this->drive_data[1].num_cylinders, "setting");      
  add_attribute("drive0-num-heads", & this->drive_data[0].num_heads, "setting");
  add_attribute("drive1-num-heads", & this->drive_data[1].num_heads, "setting");      
  add_attribute("drive0-num-sectors-per-track", & this->drive_data[0].num_sectors, "setting");
  add_attribute("drive1-num-sectors-per-track", & this->drive_data[1].num_sectors, "setting");      
  
  add_attribute_virtual ("state-snapshot", this,
			 & ide_controller::save_state,
			 & ide_controller::restore_state);
  
  // Pins
  add_pin("interrupt", & this->interrupt_pin);
  
  // Categorized attributes for target view
  add_watchable_register ("altstatus", 
			  new attribute_coder_bus_ro<little_int_1>(& this->controlbus, 0x6));
  add_watchable_register ("control", 
			  new attribute_coder_bus_wo<little_int_1>(& this->controlbus, 0x6));
  add_watchable_register ("drive-address", 
			  new attribute_coder_bus_ro<little_int_1>(& this->controlbus, 0x7));
  add_watchable_register ("data", 
			  new attribute_coder_bus_rw<little_int_1>(& this->commandbus, 0x0));
  add_watchable_register ("error", 
			  new attribute_coder_bus_ro<little_int_1>(& this->commandbus, 0x1));
  add_watchable_register ("precomp", 
			  new attribute_coder_bus_wo<little_int_1>(& this->commandbus, 0x1));
  add_watchable_register ("sector-count", 
			  new attribute_coder_bus_rw<little_int_1>(& this->commandbus, 0x2));
  add_watchable_register ("sector-number", 
			  new attribute_coder_bus_rw<little_int_1>(& this->commandbus, 0x3));
  add_watchable_register ("cylinder-low", 
			  new attribute_coder_bus_rw<little_int_1>(& this->commandbus, 0x4));
  add_watchable_register ("cylinder-high", 
			  new attribute_coder_bus_rw<little_int_1>(& this->commandbus, 0x5));
  add_watchable_register ("drive/head", 
			  new attribute_coder_bus_rw<little_int_1>(& this->commandbus, 0x6));
  add_watchable_register ("command", 
			  new attribute_coder_bus_wo<little_int_1>(& this->commandbus, 0x7));

  add_attribute ("interrupt", & this->interrupt_pin, "pin");
  
  // Initialize!
  // XXX: do this in response to a reset pin
  this->reset();
}


void
ide_controller::reset()
{
  this->error_reg_amnf = 1;
  this->sector_count_reg = 1;
  this->sector_number_reg = 1;
  this->cylinder_low_reg = 0;
  this->cylinder_high_reg = 0;
  this->drive_head_reg_l = 0;
  this->drive_head_reg_drive = 0;
  this->drive_head_reg_head = 0;

  this->altstatus_reg_drq = 0;
  this->altstatus_reg_drdy = 1;
  this->altstatus_reg_error = 0;
  this->device_control_reg_nien = 1; // XXX: verify initial value!

  this->drive_data[0].reset ();
  this->drive_data[1].reset ();

  this->state = idle;
}


void 
ide_controller::device_control_srst(little_int_1 value, little_int_1 mask)
{
  if (value & mask)
    reset();
}

void
ide_controller::data_port_set(little_int_1 value, little_int_1 mask)
{
  switch (this->state)
    {
    case writing:
    case writing_nowb:
      {
	unsigned drive_num = this->drive_head_reg_drive;
	drive* d = & this->drive_data[drive_num];
	d->fifo_push(value);
	if (d->sector_complete ())
	  {
	    if (this->current_block_valid ())
	      {
		unsigned drive_num = this->drive_head_reg_drive;
		drive* d = & this->drive_data[drive_num];
		unsigned block = this->get_current_block ();
		if (this->state != writing_nowb) d->write_sector (block);
		
		this->goto_next_block ();
		if (((int) this->sector_count_reg > 0)
		    && (this->state == writing)) // more sectors to transfer?
		  {
		    this->altstatus_reg_drq = 1;
		    this->interrupt (1); // send next sector, please!
		  }
		else // done!
		  {
		    this->state = idle;
		    this->altstatus_reg_drdy = 1;
		    this->altstatus_reg_drq = 0;
		    this->interrupt (1); // command complete
		  }
	      }
	    else // error - overflow
	      {
		this->state = idle;
		this->altstatus_reg_error = 1;
		this->altstatus_reg_drdy = 1;
		this->altstatus_reg_drq = 0;
		this->interrupt (1); // command aborted
	      }
	  }
      }
      break;
      
    default:
      // Undefined behavior
      cerr << "Warning: inappropriate time to write to IDE data port." << endl;
    }
}

little_int_1
ide_controller::data_port_get()
{
  switch (this->state)
    {
    case reading:
    case reading_nowb:
      {
	unsigned drive_num = this->drive_head_reg_drive;
	drive* d = & this->drive_data[drive_num];
        little_int_1 value = d->fifo_pop();
	if (d->sector_complete ())
	  {
	    this->goto_next_block ();

	    if (((int) this->sector_count_reg > 0)
		&& (this->state == reading)) // more sectors to transfer?
	      this->read_current_block ();
	    else // done!
	      {
		this->state = idle;
		this->altstatus_reg_drdy = 1;
		this->altstatus_reg_drq = 0;
		this->interrupt (1); // command complete
	      }
	  }
	return value;
      }
      break;
      
    default:
      // Undefined behavior
      cerr << "Warning: inappropriate time to read from IDE data port." << endl;
      return 0;
    }
}


little_int_1
ide_controller::status_get()
{
  // clear interrupts and return the alternate status register
  this->interrupt (0); // clear interrupt
  return
    this->altstatus_reg_drdy.get()  |
    this->altstatus_reg_drq.get()   |
    this->altstatus_reg_error.get() |
    this->altstatus_reg_rest.get();
}


void
ide_controller::command_set(little_int_1 value, little_int_1 mask)
{
  if ((this->state != idle)
      || !(this->altstatus_reg_drdy))
    {
      // The IDE spec defines this act as causing undefined behavior.
      cerr << "Inappropriate time to issue IDE command." << endl;
      this->altstatus_reg_error = 1;
      this->interrupt (1);
      return;
    }

  // XXX: Clear meaningless powerup state
  this->error_reg_amnf = 0;

  // Trap access to non-present drives
  unsigned drive_num = this->drive_head_reg_drive;
  drive* d = & this->drive_data[drive_num];
  if (! d->present)
    {
      this->altstatus_reg_error = 1;
      this->interrupt (1);
    }

  // Dispatch IDE command
  switch(value)
    {
      // RECALIBRATE (0x10 -- 0x1F)
    case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:    
    case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f:
      // SEEK (0x70 - 0x7F)
    case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:    
    case 0x78: case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
      // XXX: other no-ops?

      this->altstatus_reg_error = 0;
      this->interrupt (1); // command complete
      break;

    case 0x20: // READ SECTORS w/ retry
    case 0x21: // READ SECTORS w/o retry
      this->state = reading;
      this->altstatus_reg_drdy = 0;
      read_current_block();
      break;

    case 0x30: // WRITE SECTORS w/ retry
    case 0x31: // WRITE SECTORS w/o retry
      if (this->current_block_valid ())
	{
	  this->state = writing;
	  this->altstatus_reg_error = 0;
	  this->altstatus_reg_drdy = 0;
	  this->altstatus_reg_drq = 1; // immediately ready

	  // reset FIFO pointer
	  unsigned drive_num = this->drive_head_reg_drive;
	  drive* d = & this->drive_data[drive_num];
	  d->reset ();
	}
      else
	{
	  this->altstatus_reg_error = 1;
	  this->altstatus_reg_drdy = 1;
	  this->altstatus_reg_drq = 0;
	  this->interrupt (1); // command aborted
	}

      break;

    case 0x91: // initialize drive parameters
      this->altstatus_reg_drdy = 1;
      this->altstatus_reg_drq = 0;
      this->altstatus_reg_error = 0;
      this->interrupt (1);
      break;

    case 0xe4: // READ BUFFER
      this->state = reading_nowb;
      this->altstatus_reg_error = 0;
      this->altstatus_reg_drdy = 0;
      this->altstatus_reg_drq = 1; // immediately ready
      break;

    case 0xe8: // WRITE BUFFER
      this->state = reading_nowb;
      this->altstatus_reg_error = 0;
      this->altstatus_reg_drdy = 0;
      this->altstatus_reg_drq = 1; // immediately ready
      break;

    case 0xec: // IDENTIFY DRIVE
      {
	bool ok;
	ok = this->identify_drive();
	if (ok)
	  {
	    this->altstatus_reg_error = 0;
	    this->altstatus_reg_drdy = 0;
	    this->state = reading_nowb;
	    this->altstatus_reg_drq = 1; // immediately ready
	  }
	else
	  this->altstatus_reg_error = 1;
	this->interrupt (1); // command complete
      }
      break;

    default:
      {
	cerr << "Unimplemented IDE command " << value << endl;

	// set command error indication
	this->altstatus_reg_error = 1;
	this->interrupt(1); // command aborted
      }
    }
}



void
ide_controller::read_current_block ()
{
  if (this->current_block_valid ())
    {
      unsigned drive_num = this->drive_head_reg_drive;
      drive* d = & this->drive_data[drive_num];
      unsigned block = this->get_current_block ();
      if (this->state != reading_nowb) d->read_sector (block);
      this->altstatus_reg_drq = 1;
      this->interrupt(1); // receive next sector, please!
    }
  else
    {
      this->state = idle;
      this->altstatus_reg_error = 1;
      this->altstatus_reg_drdy = 1;
      this->altstatus_reg_drq = 0;
      interrupt(1); // command aborted
    }
}


// Check that the current contents of the CHS registers refer to a
// valid sector on the selected drive.
bool
ide_controller::current_block_valid () const
{
  unsigned drive_num = this->drive_head_reg_drive;
  const drive* d = & this->drive_data[drive_num];

  // If any required parameters are missing, abort read/write attempt.
  if(d->present == false
     || d->file == 0
     || d->num_cylinders == 0 
     || d->num_heads == 0
     || d->num_sectors == 0)
    return false;

  if (this->drive_head_reg_l) // LBA mode
    {
      unsigned num_blocks = d->num_cylinders * d->num_heads * d->num_sectors;
      unsigned block_num = this->get_current_block();

      if (block_num >= num_blocks)
	return false;
    }
  else // CHS mode
    {
      if (((unsigned) this->drive_head_reg_head >= d->num_heads) 
	  || ((unsigned)(this->cylinder_high_reg << 8 | this->cylinder_low_reg)
	      >= d->num_cylinders)
	  || ((unsigned)this->sector_number_reg >= d->num_sectors))
	return false;
    }

  return true;
}


// Return the logical sector number being accessed.  The mapping from
// LBA mode is simpler.
unsigned
ide_controller::get_current_block() const
{
  if (this->drive_head_reg_l) // LBA mode
    {
      return
	this->drive_head_reg_head << 24 |
	this->cylinder_high_reg << 16 |
	this->cylinder_low_reg << 8 |
	this->sector_number_reg;
    }
  else // CHS mode
    {
      unsigned drive_num = this->drive_head_reg_drive;
      const drive* d = & this->drive_data[drive_num];

      // NB: C most significant, S least significant!
      return
	((this->cylinder_high_reg << 8 | this->cylinder_low_reg)
	 * d->num_sectors * d->num_cylinders)
	+ (this->drive_head_reg_head * d->num_sectors)
	+ this->sector_number_reg;
    }
}


// A sector transfer has finished.  Increment the block address
// pointers.  Decrement the sector count, but roll this counter over
// from 0 to 255.
void
ide_controller::goto_next_block()
{
  // first decrement that counter
  unsigned cnt = this->sector_count_reg;
  assert(cnt >= 0 && cnt <= 255);
  this->sector_count_reg = (cnt == 0) ? 255 : cnt - 1;

  // now on to the CHS registers ..

  unsigned drive_num = this->drive_head_reg_drive;
  const drive* d = & this->drive_data[drive_num];
  bool lba_p = (this->drive_head_reg_l == 1); // LBA mode?

  // from most significant ... to least significant
  unsigned cyl = this->cylinder_high_reg << 8 | this->cylinder_low_reg;
  unsigned hd = this->drive_head_reg_head;
  unsigned sec = this->sector_number_reg;

  // limits for same
  unsigned sec_max = lba_p ? 256 : (unsigned)d->num_sectors;
  unsigned hd_max = lba_p ? 16 : (unsigned)d->num_heads;
  unsigned cyl_max = lba_p ? 65536 : (unsigned)d->num_cylinders;

  // do long addition by "nested ripple carry" method
  sec ++;
  if (sec == sec_max)
    {
      sec = 0;
      hd ++;
      if (hd == hd_max)
	{
	  hd = 0;
	  cyl ++;
	  if(cyl == cyl_max)
	    {
	      cyl = 0;
	      // XXX: overflowed on cylinder number ... how to handle?
	    }
	}
    }

  // write back modified values
  this->cylinder_high_reg = ((cyl >> 8) & 0xff);
  this->cylinder_low_reg = (cyl & 0xff);
  this->drive_head_reg_head = hd;
  this->sector_number_reg = sec;
}

    
bool
ide_controller::identify_drive ()
{
  unsigned drive_num = this->drive_head_reg_drive;
  drive* d = & this->drive_data[drive_num];

  if(! d->present)
    return false;

  d->reset ();

  // Fill in standard drive identification struct in the sector buffer.
  // Struct definition and comments from include/linux/hdreg.h.

  d->fifo_push_short (0);                // lots of obsolete bit flags
  d->fifo_push_short (d->num_cylinders); // "physical" cyls
  d->fifo_push_short (0);                // reserved (word 2)
  d->fifo_push_short ((unsigned)d->num_heads);     // "physical" heads
  d->fifo_push_short ((unsigned)d->num_sectors * 512); // unformatted bytes per track
  d->fifo_push_short (512);              // unformatted bytes per sector
  d->fifo_push_short ((unsigned)d->num_sectors);   // "physical" sectors per track
  d->fifo_push_short (0);                // vendor unique
  d->fifo_push_short (0);                // vendor unique
  d->fifo_push_short (0);                // vendor unique
  d->fifo_push_string("#000", 20);       // serial number
  d->fifo_push_short (0);                // buffer type
  d->fifo_push_short (1);                // buffer size; 512 byte increments
  d->fifo_push_short (0);                // ecc bytes
  d->fifo_push_string(VERSION, 8);       // firmware version
  d->fifo_push_string("SID virtual IDE: `" + d->filename + "'", 40); // model
  d->fifo_push (0);                      // max multisector: 0 sectors
  d->fifo_push (0);                      // vendor unique
  d->fifo_push_short (0);                // dword I/O: not implemented
  d->fifo_push (0);                      // vendor unique
  d->fifo_push (0x02);                   // capability: LBA
  d->fifo_push_short (0);                // reserved
  d->fifo_push (0);                      // vendor unique
  d->fifo_push (2);                      // tPIO : fast
  d->fifo_push (0);                      // vendor unique
  d->fifo_push (0);                      // tDMA : slow 
  d->fifo_push_short (0x01);             // field_valid: cur_ok
  d->fifo_push_short ((unsigned)d->num_cylinders); // logical cylinders
  d->fifo_push_short ((unsigned)d->num_heads);     // logical heads
  d->fifo_push_short ((unsigned)d->num_sectors);   // logical sectors per track
  d->fifo_push_long  (d->num_sectors * d->num_heads * d->num_cylinders); // capacity
  d->fifo_push (0);                      // current multisector
  d->fifo_push (0);                      // multisect not ok
  d->fifo_push_long  (d->num_sectors * d->num_heads * d->num_cylinders); // LBA capacity
  d->fifo_push_short (0);                // dma 1-word
  d->fifo_push_short (0);                // dma multiple-word
  d->fifo_push_short (0);                // EIDE pia mode: mode 3
  d->fifo_push_short (0);                // min multi-word dma cycle time
  d->fifo_push_short (0);                // recomm multi-word dma cycle time
  d->fifo_push_short (0);                // min pio cycle time
  d->fifo_push_short (0);                // min pio cycle time, w/ IORDY
  d->fifo_clear_rest ();

  d->reset ();                           // put pointer back to beginning

  return true;
}




ostream& 
operator << (ostream& out, const ide_controller& it)
{
  out << "ide-controller "
    // only value_control_registers need to be saved
      << it.altstatus_reg_drdy << " "
      << it.altstatus_reg_drq << " "
      << it.altstatus_reg_error << " "
      << it.device_control_reg_nien << " "
      << it.error_reg_abrt << " "
      << it.error_reg_amnf << " "
      << it.sector_count_reg << " "
      << it.sector_number_reg << " "
      << it.cylinder_low_reg << " "
      << it.cylinder_high_reg << " "
      << it.drive_head_reg_l << " "
      << it.drive_head_reg_drive << " "
      << it.drive_head_reg_head << " "
      << (int) it.state << endl;

  out << it.drive_data[0] << endl
      << it.drive_data[1];

  // NB: don't leave whitespace at end of string, so
  // state reader will not leave it unparsed.

  return out;
}



ostream&
operator << (ostream& out, const ide_controller::drive& it)
{
  out << "ide-drive "
      << it.present << " "
      << string2stream(it.filename) << " "
      << it.num_cylinders << " "
      << host_int_2(it.num_heads) << " "
      << host_int_2(it.num_sectors) << " "
      << it.fifo_index;
  
  for(unsigned i=0; i<it.fifo_index; i++)
    out << " " << little_int_1(it.fifo[i]); // dump as hex

  return out;
}


istream& 
operator >> (istream& in, ide_controller& it)
{
  string coding;
  in >> coding;
  if (coding == "ide-controller")
    {
      in >> it.altstatus_reg_drdy
	 >> it.altstatus_reg_drq
	 >> it.altstatus_reg_error
	 >> it.device_control_reg_nien
	 >> it.error_reg_abrt
	 >> it.error_reg_amnf
	 >> it.sector_count_reg
	 >> it.sector_number_reg
	 >> it.cylinder_low_reg
	 >> it.cylinder_high_reg
	 >> it.drive_head_reg_l
	 >> it.drive_head_reg_drive
	 >> it.drive_head_reg_head;
      
      int s;
      in >> s;
      it.state = (ide_controller::controller_state) s;

      in >> it.drive_data[0]
	 >> it.drive_data[1];
    }
  else
    {
      in.setstate(ios::badbit);
    }

  return in;
}


istream& 
operator >> (istream& in, ide_controller::drive& it)
{
  string key;
  in >> key;
  if (key != "ide-drive")
    {
      in.setstate (ios::badbit);
      return in;
    }

  host_int_2 num_heads2, num_sectors2;
  
  in >> it.present
     >> stream2string(it.filename)
     >> it.num_cylinders
     >> num_heads2
     >> num_sectors2
     >> it.fifo_index;
  it.num_heads = num_heads2;
  it.num_sectors = num_sectors2;

  it.filename_changed();
      
  for(unsigned i=0; i<it.fifo_index; i++)
    {
      little_int_1 byte;
      in >> byte;  // read as hex
      it.fifo[i] = byte;
    }
  
  return in;
}



// Finally, the register bus hook itself - must come after
// ide_controller class declaration.

void ide_hooking_register_bus::post_access_hook()
{
  // cerr << "ide_hooking_register_bus post_access_hook" << endl;
  this->foe->post_access_hook();
}


// ----------------------------------------------------------------------------


static
vector<string>
compIdeListTypes()
{
  vector<string> types;
  types.push_back("hw-disk-ide");
  return types;
}


static
component*
compIdeCreate(const string& typeName)
{
  if(typeName == "hw-disk-ide")
    return new ide_controller();
  else
    return 0;
}


static
void
compIdeDelete(component* c)
{
  delete dynamic_cast<ide_controller*>(c);
}



// static object
extern const component_library ide_component_library;

const component_library ide_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compIdeListTypes, 
  & compIdeCreate,
  & compIdeDelete
};

