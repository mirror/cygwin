// sidcpuutil.h - Elements common to CPU models.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDCPUUTIL_H
#define SIDCPUUTIL_H

#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidcomputil.h>
#include <sidmiscutil.h>
#include <sidwatchutil.h>

namespace sidutil
{
  // kinds of endianness
  enum endian 
  {
    endian_unknown = 0,
    endian_big = 1,
    endian_little = 2
  };
  
  inline
    std::ostream& operator << (std::ostream& o, const endian& e)
      {
	switch (e) 
	  {
	  default: 
	  case endian_unknown: o << "unknown"; break;
	  case endian_big: o << "big"; break;
	  case endian_little: o << "little"; break;
	  }
	return o;
      }
  
  
  inline
    std::istream& operator >> (std::istream& i, endian& e)
      {
	std::string s;
	i >> s;
	if (s == "unknown" || s == "0") { e = endian_unknown; }
	else if (s == "big" || s == "1") { e = endian_big; }
	else if (s == "little" || s == "2") { e = endian_little; }
	else { i.setstate(std::ios::badbit); e = endian_unknown; }
	return i;
      }

  // ------------------------------------------------------------------------

  class cpu_exception {};

  class cpu_memory_fault: public cpu_exception
  {
  public:
    sid::host_int_4 pc;
    sid::host_int_4 address;
    sid::bus::status status;
    const char* operation;
    
    cpu_memory_fault (sid::host_int_4 p, sid::host_int_4 a, sid::bus::status s, const char* o):
      pc(p), address(a), status(s), operation(o) 
      {}
  };
  

  // ------------------------------------------------------------------------


  // Values travelling through the trap-type pin.
  // Additional "arguments" are sent through the trap-code pin.
  enum cpu_trap_type {
    cpu_trap_software = 1,      // trap instruction hit
    cpu_trap_breakpoint = 2,    // breakpoint instruction hit
    cpu_trap_syscall = 3,       // system call instruction hit
    cpu_trap_invalid_insn = 4,  // invalid instruction hit
    cpu_trap_memory_fault = 5,  // memory fault encountered
    cpu_trap_overflow = 6,      // arithmetic overflow
    cpu_trap_stepped = 7,       // single-step completed
  };


  // Possible trap disposition codes
  enum cpu_trap_disposition 
  {
    cpu_trap_unhandled = 0,     // dispatch to hardware fault handling
    cpu_trap_handled = 1,       // supervisor handled faulting instruction
    cpu_trap_reissue = 2,       // rerun faulting instruction
    cpu_trap_skip = 3,          // skip faulting instruction
  };


  // ------------------------------------------------------------------------


  class basic_cpu: public virtual sid::component,
		   protected fixed_pin_map_component,
		   protected fixed_accessor_map_component,
		   protected fixed_attribute_map_component,
		   protected fixed_relation_map_component,
		   protected fixed_bus_map_component
  {
    // custom memory allocators for poisioning freshly-allocated memory
  public:
    void* operator new (size_t sz)
    {
      void* p = std::operator new (sz);
      // Initialize the object with garbage, to ease detection of missing initialization.
      char* q = (char*) p;
      char deadbeef[] = { 0xde, 0xad, 0xbe, 0xef };
      for (unsigned i=0; i<sz; i++)
	*q++ = deadbeef[i % 4];
      return p;
    }
    void operator delete (void* p)
    {
      std::operator delete (p);
    }

    // recursion protection
  protected:
    recursion_limited step_limit;

    // triggerpoint support
  protected:
    friend class self_watcher<basic_cpu>;
    self_watcher<basic_cpu> triggerpoint_manager;
    // Virtual pin interfaces between self_watcher and fixed_pin_map_component
    sid::component::status pin_factory (const std::string& name)
      {
	return this->triggerpoint_manager.create_virtual_pin (name);
      }
    void pin_junkyard (const std::string& name)
      {
	return this->triggerpoint_manager.destroy_virtual_pin (name);
      }
  // Helper functions for target view support
  template <class PinType>
  void add_watchable_pin (const std::string& name, PinType* pin)
    {
      this->add_pin (name, pin);
      this->add_attribute (name, pin, "pin");
      this->triggerpoint_manager.add_watchable_attribute (name);
      this->categorize (name, "watchable");
    }

  template <class ValueType>
  void add_watchable_register (const std::string& name, ValueType* value)
    {
      this->add_attribute (name, value, "register");
      this->triggerpoint_manager.add_watchable_attribute (name);
      this->categorize (name, "watchable");
    }

  template <class Class, typename Getter, typename Setter>
  void add_watchable_register (const std::string& name,
                               Class* receiver,
                               Getter getter,
                               Setter setter)
    {
      this->add_attribute_virtual (name, receiver, getter, setter, "register");
      this->triggerpoint_manager.add_watchable_attribute (name);
      this->categorize (name, "watchable");
    }

  template <class Class, typename Getter, typename Setter, typename Parameter>
  void add_watchable_register (const std::string& name,
                               Parameter param,
                               Class* receiver,
                               Getter getter,
                               Setter setter)
    {
      this->add_attribute_virtual_parameterized (name, param, receiver, 
                                                 getter, setter, "register");
      this->triggerpoint_manager.add_watchable_attribute (name);
      this->categorize (name, "watchable");
    }

  template <class ValueType>
  void add_watchable_ro_register (const std::string& name, ValueType* value)
    {
      this->add_attribute_ro (name, value, "register");
      this->triggerpoint_manager.add_watchable_attribute (name);
      this->categorize (name, "watchable");
    }

    // step/yield control pins
  private:
    callback_pin<basic_cpu> step_pin;
    callback_pin<basic_cpu> yield_pin;
    bool yield_p;
    sid::host_int_4 step_insn_count;
    sid::host_int_8 total_insn_count;
    sid::host_int_4 current_step_insn_count;
    output_pin step_cycles_pin;
  public:
    bool trace_extract_p;
    bool trace_result_p;
    bool enable_step_trap_p;

    void step_pin_handler (sid::host_int_4)
      {
	recursion_record limit (& this->step_limit);
	if (UNLIKELY(! limit.ok())) return;

	this->current_step_insn_count = 0;
	this->yield_p = false;

	// Enter insn loop.  Poll continue_after_insn_p after each instruction
	sid::host_int_8 prev_insn_count = this->total_insn_count;
	this->step_insns ();
	sid::host_int_8 num_insns = this->total_insn_count - prev_insn_count;

	// Clamp
	const sid::host_int_4 min_num_cycles = 1;
	const sid::host_int_4 max_num_cycles = 0x7FFFFFFF;
	sid::host_int_4 num_cycles = 
	  num_insns <= min_num_cycles ? min_num_cycles :
	  num_insns >= max_num_cycles ? max_num_cycles :
	  num_insns;
	this->stepped (num_cycles);
      }
    void yield ()
      {
	this->yield_p = true;
	// A subsequent continue_after_insns_p should return false.
      }
    void yield_pin_handler (sid::host_int_4)
      {
	this->yield ();
      }

  protected:
    virtual void step_insns () = 0;
    void stepped (sid::host_int_4 n)
      {
	this->step_cycles_pin.drive (n);
      }
    bool stop_after_insns_p (sid::host_int_4 num)
      {
	this->current_step_insn_count += num;
	if (UNLIKELY(this->yield_p ||
		    (this->current_step_insn_count >= this->step_insn_count)))
          {
            // Batch updates to total_insn_count to avoid long-long
            // arithmetic overhead in the inner insn-stepping loops.
	    this->total_insn_count += this->current_step_insn_count;
	    this->current_step_insn_count = 0;
	    return true;
          }
        else
	  {
	    return false;
	  }
      }


    // Reset the processor model to power-up state.
  private:
    callback_pin<basic_cpu> reset_pin;
    virtual void reset () = 0;
    void reset_pin_handler(sid::host_int_4 v) { this->reset (); this->stepped(1); }

    // Flush internal abstract icache (if any)
  private:
    callback_pin<basic_cpu> flush_icache_pin;
    virtual void flush_icache () = 0;
    void flush_icache_pin_handler(sid::host_int_4 v) { this->flush_icache(); }

    // Set the initial PC after reset
  private:
    callback_pin<basic_cpu> pc_set_pin;
    virtual void set_pc(sid::host_int_4) = 0;
    void pc_set_pin_handler(sid::host_int_4 v) { this->set_pc (v); }

    // Set the initial endianness after reset
  private:
    callback_pin<basic_cpu> endian_set_pin;
    virtual void set_endian(sid::host_int_4) = 0;
    void endian_set_pin_handler(sid::host_int_4 v) { this->set_endian (v); }

    // Signal trap type code and argument
  private:
    output_pin trap_type_pin;
    output_pin trap_code_pin;
    input_pin trap_disposition_pin;
  protected:
    cpu_trap_disposition signal_trap (cpu_trap_type p, sid::host_int_4 param = 0)
      {
	// Prepare disposition pin in case we get no signal back
	this->trap_disposition_pin.driven (sid::host_int_4(cpu_trap_unhandled));
	this->trap_code_pin.drive (param);
	this->trap_type_pin.drive (sid::host_int_4(p));
	return static_cast<cpu_trap_disposition>(trap_disposition_pin.sense ());
      }

    
    // state save/restore: Override these in derived classes, but
    // include a call up to this base implementation.
  protected:
    virtual void stream_state(std::ostream& o) const 
      {
	o << "basic-cpu"
	  // attrs
	  << " " << this->step_insn_count
	  << " " << this->enable_step_trap_p
	  << " " << this->total_insn_count
	  << " " << this->trace_extract_p
	  << " " << this->trace_result_p
	  // pins
	  << " " << this->step_cycles_pin
	  << " " << this->trap_type_pin
	  << " " << this->trap_code_pin;
      }

    virtual void destream_state(std::istream& i) 
      {
	std::string key;
	i >> key;
	if (key != "basic-cpu")
	  {
	    i.setstate (std::ios::badbit);
	    return;
	  }
	i >> this->step_insn_count
	  >> this->enable_step_trap_p
	  >> this->total_insn_count
	  >> this->trace_extract_p
	  >> this->trace_result_p
	  // pins
	  >> this->step_cycles_pin
	  >> this->trap_type_pin
	  >> this->trap_code_pin;
      }

    // helper functions
  private:
    friend std::ostream& operator << (std::ostream& o, const basic_cpu& c);
    friend std::istream& operator >> (std::istream& i, basic_cpu& c);
    std::string save_state() { return make_attribute(*this); }
    sid::component::status restore_state(const std::string& s)
      { return parse_attribute(s, *this); }


    // ------------------------------------------------------------------------
    // debugger access functions
  private:
    passthrough_bus debugger_bus;
    virtual std::string dbg_get_reg (sid::host_int_4 n) = 0;
    virtual sid::component::status dbg_set_reg (sid::host_int_4 n, const std::string& s) = 0;

  protected:
    template <typename PC>
    void create_gdb_register_attrs (sid::host_int_4 count, 
				    const std::string& expedited_regno_list, 
				    PC* pc)
      {
	this->triggerpoint_manager.add_watchable_value ("gdb-register-pc", pc);
	this->add_attribute_ro_value ("gdb-num-registers", count, "debugger");
	this->add_attribute_ro_value ("gdb-exp-registers", expedited_regno_list, "debugger");
	for (sid::host_int_4 i=0; i<count; i++)
	  {
	    std::string name = std::string ("gdb-register-") + make_numeric_attribute (i);
	    attribute_coder_base* coder =
	      new attribute_coder_virtual_parameterized<basic_cpu,sid::host_int_4>
	      (this, & basic_cpu::dbg_get_reg, & basic_cpu::dbg_set_reg, i);
	    this->add_attribute_coder (name, coder, "debugger");
	  }
      }


    // ------------------------------------------------------------------------
    // memory access functions

  protected:
    sid::bus* data_bus;
    sid::bus* insn_bus;

  protected:
    template <typename BigOrLittleInt>
    BigOrLittleInt read_insn_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt) const;
    template <typename BigOrLittleInt>
    BigOrLittleInt write_insn_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt value) const;
    template <typename BigOrLittleInt>
    BigOrLittleInt read_data_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt) const;
    template <typename BigOrLittleInt>
    BigOrLittleInt write_data_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt value) const;

    // ------------------------------------------------------------------------
    
public:
    basic_cpu ():
      step_limit ("instruction stepping", 1),
      triggerpoint_manager (this),
      step_pin (this, & basic_cpu::step_pin_handler),
      yield_pin (this, & basic_cpu::yield_pin_handler),
      reset_pin (this, & basic_cpu::reset_pin_handler),
      flush_icache_pin (this, & basic_cpu::flush_icache_pin_handler),
      pc_set_pin (this, & basic_cpu::pc_set_pin_handler),
      endian_set_pin (this, & basic_cpu::endian_set_pin_handler),
      debugger_bus (& this->data_bus)
      {
	// buses
	this->data_bus = 0;
	add_accessor ("data-memory", & this->data_bus);
	this->insn_bus = 0;
	add_accessor ("insn-memory", & this->insn_bus);
	add_bus ("debugger-bus", & this->debugger_bus);

	// pins
	add_pin ("step!", & this->step_pin);
	add_watchable_pin ("step-cycles", & this->step_cycles_pin);
	add_pin ("flush-icache", & this->flush_icache_pin);
	add_pin ("reset!", & this->reset_pin);
	add_pin ("yield", & this->yield_pin);
	add_pin ("start-pc-set!", & this->pc_set_pin);
	add_pin ("endian-set!", & this->endian_set_pin);
	add_watchable_pin ("trap", & this->trap_type_pin); // output side
	add_watchable_pin ("trap-code", & this->trap_code_pin);
	add_pin ("trap", & this->trap_disposition_pin); // input side

	// attributes
	this->step_insn_count = 1;
	add_attribute ("step-insn-count", & this->step_insn_count, "setting");
	this->enable_step_trap_p = false;
	add_attribute ("enable-step-trap?", & this->enable_step_trap_p, "setting");
	this->total_insn_count = 0;
	add_watchable_register ("insn-count", & this->total_insn_count);
	add_attribute_virtual ("state-snapshot", this,
			       & basic_cpu::save_state,
			       & basic_cpu::restore_state);
	add_attribute ("trace-extract?", & trace_extract_p, "setting");
	add_attribute ("trace-result?", & trace_result_p, "setting");
      }

    ~basic_cpu() {}
  };


  inline std::ostream& operator << (std::ostream& o, const basic_cpu& c) {
    c.stream_state (o);
    return o;
  }
  inline std::istream& operator >> (std::istream& i, basic_cpu& c) {
    c.destream_state (i);
    return i;
  }

    template <typename BigOrLittleInt>
    BigOrLittleInt basic_cpu::read_insn_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt) const
      {
	BigOrLittleInt value;
	sid::bus::status s = 
	  (LIKELY(this->insn_bus)) ? this->insn_bus->read (address, value) : sid::bus::unmapped;
	if (LIKELY(s == sid::bus::ok))
	  return value;

	throw cpu_memory_fault (pc, address, s, "insn read");
      }

    template <typename BigOrLittleInt>
    BigOrLittleInt basic_cpu::write_insn_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt value) const
      {
	sid::bus::status s = 
	  (LIKELY(this->insn_bus)) ? this->insn_bus->write (address, value) : sid::bus::unmapped;
	if (LIKELY(s == sid::bus::ok))
	  return value;

	throw cpu_memory_fault (pc, address, s, "insn write");
      }

    template <typename BigOrLittleInt>
    BigOrLittleInt basic_cpu::read_data_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt) const
      {
	BigOrLittleInt value;
	sid::bus::status s = 
	  (LIKELY(this->data_bus)) ? this->data_bus->read (address, value) : sid::bus::unmapped;
	if (LIKELY(s == sid::bus::ok))
	  return value;

	throw cpu_memory_fault (pc, address, s, "data read");
      }

    template <typename BigOrLittleInt>
    BigOrLittleInt basic_cpu::write_data_memory (sid::host_int_4 pc, sid::host_int_4 address, BigOrLittleInt value) const
      {
	sid::bus::status s = 
	  (LIKELY(this->data_bus)) ? this->data_bus->write (address, value) : sid::bus::unmapped;
	if (LIKELY(s == sid::bus::ok))
	  return value;

	throw cpu_memory_fault (pc, address, s, "data write");
      }



  // ------------------------------------------------------------------------
  // Derived classes for memory access functions of various endianness

  class basic_big_endian_cpu: public basic_cpu
  {
    void set_endian(sid::host_int_4) {}

  protected:

    basic_big_endian_cpu ()
      {
	add_attribute_ro_value ("endian", endian_big, "register");
      }
    ~basic_big_endian_cpu () {}

    sid::host_int_1 read_insn_memory_1 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::big_int_1());
      }

    sid::host_int_2 read_insn_memory_2 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::big_int_2());
      }

    sid::host_int_4 read_insn_memory_4 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::big_int_4());
      }

    sid::host_int_8 read_insn_memory_8 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::big_int_8());
      }

    void write_insn_memory_1 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_1 value) const
      {
	this->write_insn_memory (pc, address, sid::big_int_1(value));
      }

    void write_insn_memory_2 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_2 value) const
      {
	this->write_insn_memory (pc, address, sid::big_int_2(value));
      }

    void write_insn_memory_4 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_4 value) const
      {
	this->write_insn_memory (pc, address, sid::big_int_4(value));
      }

    void write_insn_memory_8 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_8 value) const
      {
	this->write_insn_memory (pc, address, sid::big_int_8(value));
      }

    sid::host_int_1 read_data_memory_1 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::big_int_1());
      }

    sid::host_int_2 read_data_memory_2 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::big_int_2());
      }

    sid::host_int_4 read_data_memory_4 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::big_int_4());
      }

    sid::host_int_8 read_data_memory_8 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::big_int_8());
      }

    void write_data_memory_1 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_1 value) const
      {
	this->write_data_memory (pc, address, sid::big_int_1(value));
      }

    void write_data_memory_2 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_2 value) const
      {
	this->write_data_memory (pc, address, sid::big_int_2(value));
      }

    void write_data_memory_4 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_4 value) const
      {
	this->write_data_memory (pc, address, sid::big_int_4(value));
      }

    void write_data_memory_8 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_8 value) const
      {
	this->write_data_memory (pc, address, sid::big_int_8(value));
      }
  };


  // ----------------------------------------------------------------------------

  class basic_little_endian_cpu: public basic_cpu
  {
    void set_endian(sid::host_int_4) {}

  protected:
    basic_little_endian_cpu ()
      {
	add_attribute_ro_value ("endian", endian_little, "register");
      }
    ~basic_little_endian_cpu () {}

    sid::host_int_1 read_insn_memory_1 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::little_int_1());
      }

    sid::host_int_2 read_insn_memory_2 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::little_int_2());
      }

    sid::host_int_4 read_insn_memory_4 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::little_int_4());
      }

    sid::host_int_8 read_insn_memory_8 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_insn_memory (pc, address, sid::little_int_8());
      }

    void write_insn_memory_1 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_1 value) const
      {
	this->write_insn_memory (pc, address, sid::little_int_1(value));
      }

    void write_insn_memory_2 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_2 value) const
      {
	this->write_insn_memory (pc, address, sid::little_int_2(value));
      }

    void write_insn_memory_4 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_4 value) const
      {
	this->write_insn_memory (pc, address, sid::little_int_4(value));
      }

    void write_insn_memory_8 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_8 value) const
      {
	this->write_insn_memory (pc, address, sid::little_int_8(value));
      }

    sid::host_int_1 read_data_memory_1 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::little_int_1());
      }

    sid::host_int_2 read_data_memory_2 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::little_int_2());
      }

    sid::host_int_4 read_data_memory_4 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::little_int_4());
      }

    sid::host_int_8 read_data_memory_8 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	return this->read_data_memory (pc, address, sid::little_int_8());
      }

    void write_data_memory_1 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_1 value) const
      {
	this->write_data_memory (pc, address, sid::little_int_1(value));
      }

    void write_data_memory_2 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_2 value) const
      {
	this->write_data_memory (pc, address, sid::little_int_2(value));
      }

    void write_data_memory_4 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_4 value) const
      {
	this->write_data_memory (pc, address, sid::little_int_4(value));
      }

    void write_data_memory_8 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_8 value) const
      {
	this->write_data_memory (pc, address, sid::little_int_8(value));
      }
  };


  // ----------------------------------------------------------------------------


  class basic_bi_endian_cpu: public basic_cpu
  {
    endian _current_endianness;
  protected:
    endian current_endianness() const { return this->_current_endianness; }

  protected:
    basic_bi_endian_cpu ()
      {
	this->_current_endianness = endian_big;
	add_attribute ("endian", & this->_current_endianness, "register");
      }
    ~basic_bi_endian_cpu () {}

    void set_endian(sid::host_int_4 v)
      {
	switch (v)
	  {
	  case 1:
	    this->_current_endianness = endian_big;
	    break;
	  case 2:
	    this->_current_endianness = endian_little;
	    break;
	  default:
	    // XXX: warning message?
	    break;
	  }
      }

    void stream_state(std::ostream& o) const 
      {
	basic_cpu::stream_state(o);
	o << " " << this->_current_endianness;
      }

    void destream_state(std::istream& i) 
      {
	basic_cpu::destream_state(i);
	i >> this->_current_endianness;
      }


    sid::host_int_1 read_insn_memory_1 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_insn_memory (pc, address, sid::little_int_1());
	else // endian_big or endian_unknown
	  return this->read_insn_memory (pc, address, sid::big_int_1());
      }

    sid::host_int_2 read_insn_memory_2 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_insn_memory (pc, address, sid::little_int_2());
	else // endian_big or endian_unknown
	  return this->read_insn_memory (pc, address, sid::big_int_2());
      }

    sid::host_int_4 read_insn_memory_4 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_insn_memory (pc, address, sid::little_int_4());
	else // endian_big or endian_unknown
	  return this->read_insn_memory (pc, address, sid::big_int_4());
      }

    sid::host_int_8 read_insn_memory_8 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_insn_memory (pc, address, sid::little_int_8());
	else // endian_big or endian_unknown
	  return this->read_insn_memory (pc, address, sid::big_int_8());
      }

    void write_insn_memory_1 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_1 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_insn_memory (pc, address, sid::little_int_1(value));
	else // endian_big or endian_unknown
	  this->write_insn_memory (pc, address, sid::big_int_1(value));
      }

    void write_insn_memory_2 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_2 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_insn_memory (pc, address, sid::little_int_2(value));
	else // endian_big or endian_unknown
	  this->write_insn_memory (pc, address, sid::big_int_2(value));
      }

    void write_insn_memory_4 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_4 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_insn_memory (pc, address, sid::little_int_4(value));
	else // endian_big or endian_unknown
	  this->write_insn_memory (pc, address, sid::big_int_4(value));
      }

    void write_insn_memory_8 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_8 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_insn_memory (pc, address, sid::little_int_8(value));
	else // endian_big or endian_unknown
	  this->write_insn_memory (pc, address, sid::big_int_8(value));
      }

    sid::host_int_1 read_data_memory_1 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_data_memory (pc, address, sid::little_int_1());
	else // endian_big or endian_unknown
	  return this->read_data_memory (pc, address, sid::big_int_1());
      }

    sid::host_int_2 read_data_memory_2 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_data_memory (pc, address, sid::little_int_2());
	else // endian_big or endian_unknown
	  return this->read_data_memory (pc, address, sid::big_int_2());
      }

    sid::host_int_4 read_data_memory_4 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_data_memory (pc, address, sid::little_int_4());
	else // endian_big or endian_unknown
	  return this->read_data_memory (pc, address, sid::big_int_4());
      }

    sid::host_int_8 read_data_memory_8 (sid::host_int_4 pc, sid::host_int_4 address) const
      {
	if (this->_current_endianness == endian_little)
	  return this->read_data_memory (pc, address, sid::little_int_8());
	else // endian_big or endian_unknown
	  return this->read_data_memory (pc, address, sid::big_int_8());
      }

    void write_data_memory_1 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_1 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_data_memory (pc, address, sid::little_int_1(value));
	else // endian_big or endian_unknown
	  this->write_data_memory (pc, address, sid::big_int_1(value));
      }

    void write_data_memory_2 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_2 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_data_memory (pc, address, sid::little_int_2(value));
	else // endian_big or endian_unknown
	  this->write_data_memory (pc, address, sid::big_int_2(value));
      }

    void write_data_memory_4 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_4 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_data_memory (pc, address, sid::little_int_4(value));
	else // endian_big or endian_unknown
	  this->write_data_memory (pc, address, sid::big_int_4(value));
      }

    void write_data_memory_8 (sid::host_int_4 pc, sid::host_int_4 address, sid::host_int_8 value) const
      {
	if (this->_current_endianness == endian_little)
	  this->write_data_memory (pc, address, sid::little_int_8(value));
	else // endian_big or endian_unknown
	  this->write_data_memory (pc, address, sid::big_int_8(value));
      }
  };


} // end namespace sidutil


#endif // SIDCPUUTIL_H
