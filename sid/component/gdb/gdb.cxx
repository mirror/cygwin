// gdb.cxx - GDB stub implementation.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "gdb.h"
#include <cassert>

extern "C" {
#include <stdio.h>
#include "gdbserv.h"
#include "gdbserv-client.h"
#include "gdbserv-target.h"
#include "gdbserv-utils.h"
#include "gdbserv-output.h"
}

// ----------------------------------------------------------------------------
// Interface functions to gdbserv code: client side

extern "C" void
gdbsid_client_write_hook (struct gdbserv *gdbserv, const unsigned char* ch, unsigned len)
{
  assert (gdbserv != 0);
  assert (ch != 0);
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  g->gdbsid_client_write (ch, len);
}



// ----------------------------------------------------------------------------
// Interface functions to gdbserv code: target side

extern "C" struct gdbserv_target*
gdbsid_target_attach_hook (struct gdbserv *gdbserv, void *globalstate)
{
  gdb* g = static_cast<gdb*> (globalstate);
  return g->gdbsid_target_attach (gdbserv);
}

extern "C" void
process_get_gen_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_get_gen ();
}

extern "C" void
process_set_gen_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_set_gen ();
}

extern "C" void
process_set_args_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_set_args ();
}

extern "C" int
process_set_reg_hook (struct gdbserv *gdbserv, int reg)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_set_reg (reg);
}

extern "C" int
process_set_regs_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_set_regs ();
}

extern "C" void
process_get_reg_hook (struct gdbserv *gdbserv, int reg)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_get_reg (reg);
}

extern "C" void
process_get_regs_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_get_regs ();
}

extern "C" void
process_get_exp_regs_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_get_exp_regs ();
}

extern "C" void
process_get_mem_hook (struct gdbserv *gdbserv,
		      struct gdbserv_reg *reg_addr,
		      struct gdbserv_reg *reg_len)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_get_mem (reg_addr, reg_len);
}

extern "C" void
process_set_mem_hook (struct gdbserv *gdbserv,
		      struct gdbserv_reg *reg_addr,
		      struct gdbserv_reg *reg_len,
                      int binary)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_set_mem (reg_addr, reg_len, binary);
}

extern "C" void
process_set_pc_hook (struct gdbserv *gdbserv, struct gdbserv_reg *val) 
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_set_pc (val);
}

extern "C" int
process_signal_hook (struct gdbserv *gdbserv, int sig) 
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_signal (sig);
}

extern "C" void
flush_i_cache_hook (struct gdbserv *gdbserv) 
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->flush_i_cache ();
}

extern "C" unsigned long
compute_signal_hook (struct gdbserv *gdbserv, unsigned long sig)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->compute_signal (sig);
}

extern "C" unsigned long
get_trap_number_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->get_trap_number ();
}

extern "C" int
exit_program_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->exit_program ();
}

extern "C" int
break_program_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->break_program ();
}

extern "C" void
restart_program_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->restart_program ();
}

extern "C" int
singlestep_program_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->singlestep_program ();
}

extern "C" void
sigkill_program_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  g->sigkill_program ();
}

extern "C" int
continue_program_hook (struct gdbserv *gdbserv) 
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->continue_program ();
}

extern "C" int
remove_breakpoint_hook (struct gdbserv *gdbserv, unsigned long type,
			struct gdbserv_reg *addr, struct gdbserv_reg* len)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->remove_breakpoint (type, addr, len);
}

extern "C" int
set_breakpoint_hook (struct gdbserv *gdbserv, unsigned long type,
		     struct gdbserv_reg *addr, struct gdbserv_reg* len)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->set_breakpoint (type, addr, len);
}

extern "C" void
process_detach_hook (struct gdbserv *gdbserv)
{
  gdb* g = static_cast<gdb*> (gdbserv_target_data (gdbserv));
  return g->process_detach ();
}


// ----------------------------------------------------------------------------
// Implementations for base class.


struct gdbserv_target*
gdb::gdbsid_target_attach (struct gdbserv *gdbserv)
{
  // Do nothing if we're not configured properly.
  if (this->cpu == 0)
    {
      cerr << "Error: Cannot attach to gdb: cpu relationship is not configured." << endl;
      return 0;
    }

  if (this->gdbserv == 0)
    {
      struct gdbserv_target* gdbtarget = new ::gdbserv_target();
      assert (gdbtarget != 0);
      memset (gdbtarget, 0, sizeof (*gdbtarget)); // XXX: needed?

      gdbtarget->process_get_gen = process_get_gen_hook;
      gdbtarget->process_set_gen = process_set_gen_hook;
      gdbtarget->process_set_args = process_set_args_hook;
      gdbtarget->process_set_reg = process_set_reg_hook;
      gdbtarget->process_get_reg = process_get_reg_hook;
      gdbtarget->process_set_regs = process_set_regs_hook;
      gdbtarget->process_get_regs = process_get_regs_hook;
      gdbtarget->process_get_exp_regs = process_get_exp_regs_hook;
      gdbtarget->process_get_mem = process_get_mem_hook;
      gdbtarget->process_set_mem = process_set_mem_hook;
      gdbtarget->process_set_pc = process_set_pc_hook;
      gdbtarget->process_signal = process_signal_hook;
      gdbtarget->flush_i_cache = flush_i_cache_hook;
      gdbtarget->compute_signal = compute_signal_hook;
      gdbtarget->get_trap_number = get_trap_number_hook;
      gdbtarget->exit_program = exit_program_hook;
      gdbtarget->break_program = break_program_hook;
      gdbtarget->restart_program = restart_program_hook;
      gdbtarget->singlestep_program = singlestep_program_hook;
      gdbtarget->sigkill_program = sigkill_program_hook;
      gdbtarget->continue_program = continue_program_hook;
      gdbtarget->remove_breakpoint = remove_breakpoint_hook;
      gdbtarget->set_breakpoint = set_breakpoint_hook;
      gdbtarget->detach = process_detach_hook;

      // install mutual pointers
      gdbtarget->data = static_cast<void*>(this);
      this->gdbserv = gdbserv;

      if (trace_gdbsid)
	cerr << "gdb open" << endl;

      // shut down target
      target_power (false);
      
      // signal gdb
      last_signal = GDBSERV_SIGTRAP;
      gdbserv_fromtarget_break (gdbserv, last_signal);

      return gdbtarget;
    }
  else
    {
      cerr << "Error: Cannot attach again to gdb." << endl;
      return 0;
    }
}


void
gdb::process_get_gen ()
{
}


void
gdb::process_set_gen ()
{

  if (trace_gdbsid)
    cerr << "process_set_gen" << endl;

#if 0
  char *lhs;
  char *rhs;
  size_t sizeof_buf;

  sizeof_buf = gdbserv_input_size (gdbserv);
  if (sizeof_buf <= 0)
    {
      gdbserv_output_string (gdbserv, "E01");
      return;
    }
  lhs = (char*) alloca (sizeof_buf + 1);
  gdbserv_input_string (gdbserv, lhs, sizeof_buf + 1);
  rhs = strchr (lhs, '=');
  if (rhs == NULL)
    {
      gdbserv_output_string (gdbserv, "E02");
      return;
    }
  *rhs++ = '\0';
  //  if (this->general_set_func)
  //    gdbsid->general_set_func (gdbsid->general_set_data, lhs, rhs);
#endif
}


void
gdb::process_set_args ()
{
  if (trace_gdbsid)
    cerr << "process_set_args" << endl;

  if (gloss)
    {
      ; // XXX: collect arguments etc.
    }
  else
    {
      cerr << "Warning: gloss component not configured!" << endl;
    }
}


int
gdb::process_set_reg (int reg)
{
  string reg_image;

  if (trace_gdbsid)
    cerr << "process_set_reg " << reg << endl;
  
  dbg_register_number_t regno = reg;
  string reg_name = string("gdb-register-") + make_numeric_attribute(regno);

  int byte = gdbserv_input_byte (gdbserv);
  while (byte >= 0) 
    {
      // if (trace_gdbsid)
      // cerr << "[" << hex << byte << "]" << dec << endl;
      
      reg_image += (char) byte;
      byte = gdbserv_input_byte (gdbserv);
    }

  component::status s = cpu->set_attribute_value (reg_name, reg_image);
  if (s != component::ok)
    return -1;
    
  return 0;
}


void
gdb::process_get_reg (int reg)
{
  if (trace_gdbsid)
    cerr << "process_get_reg " << reg << endl;

  // Not implemented
  gdbserv_output_string (gdbserv, "E01");
}


int
gdb::process_set_regs ()
{
  if (trace_gdbsid)
    cerr << "process_set_regs" << endl;

  // Not implemented
  gdbserv_output_string (gdbserv, "E01");

  return 0;
}


void
gdb::process_get_regs ()
{
  if (trace_gdbsid)
    cerr << "process_get_regs " << endl;

  dbg_register_number_t num_regs;
  string num_regs_str = cpu->attribute_value ("gdb-num-registers");
  component::status s = parse_attribute (num_regs_str, num_regs);
  if (s != component::ok)
    num_regs = 0;

  if (trace_gdbsid)
    cerr << "num_regs=" << num_regs;
  unsigned num_bytes = 0;

  for (dbg_register_number_t regno=0; regno<num_regs; regno++) 
    {
      string reg_name = string("gdb-register-") 
	+ make_numeric_attribute(regno);
      string value = cpu->attribute_value (reg_name);

      for (unsigned i=0; i < value.length(); i++)
	{
	  gdbserv_output_byte (gdbserv, value[i]);
	  num_bytes ++;
	}
    }

  if (trace_gdbsid)
    cerr << " bytes=" << num_bytes << endl;
}


void
gdb::process_get_exp_regs ()
{
  if (trace_gdbsid)
    cerr << "process_get_exp_regs";

  string exp_regs_str = cpu->attribute_value ("gdb-exp-registers");
  // None supplied
  if (exp_regs_str == "")
    return;

  vector<string> exp_regs_list = tokenize (exp_regs_str, ";");
  unsigned num_bytes = 0;

  for (unsigned i=0; i<exp_regs_list.size(); i++)
    {
      dbg_register_number_t regno;
      component::status s = parse_attribute (exp_regs_list[i], regno);
      if (s != component::ok)
	continue;

      if (trace_gdbsid)
	cerr << " " << regno;

      string reg_name = string("gdb-register-") + make_numeric_attribute (regno);
      string value = cpu->attribute_value (reg_name);

      // encode register number
      string regno_hex = make_numeric_attribute (regno, ios::hex); // no ios::showbase
      gdbserv_output_string (gdbserv, regno_hex.c_str());
      gdbserv_output_char (gdbserv, ':');

      // and value
      for (unsigned i=0; i < value.length(); i++)
	{
	  gdbserv_output_byte (gdbserv, value[i]);
	  num_bytes ++;
	}
      gdbserv_output_char (gdbserv, ';');
    }

  if (trace_gdbsid)
    cerr << " bytes=" << num_bytes << endl;
}



// Helper functions

template <class Type>
void 
read_bus_word(gdbserv* gdbserv, 
	      sid::bus* bus,
	      host_int_4 address,
	      const Type& _dummy)
{
  Type value;
  bus::status s = bus->read (address, value);
  if (s == bus::ok) 
    {
      for (unsigned i=0; i < sizeof(typename Type::value_type); i++)
	gdbserv_output_byte (gdbserv, value.read_byte(i));
    }
  else
    gdbserv_output_string (gdbserv, "E05");
}


template <class Type>
void 
write_bus_word(gdbserv* gdbserv, 
	       int binary,
	       sid::bus* bus,
	       host_int_4 address,
	       const Type& _dummy)
{
  Type value;

  for (unsigned i=0; i < sizeof(typename Type::value_type); i++)
    {
      char b;
      if (binary)
	gdbserv_input_escaped_binary (gdbserv, & b, 1);
      else
	gdbserv_input_bytes (gdbserv, & b, 1);

      value.write_byte (i, b);
    }

  bus::status s = bus->write (address, value);
  if (s == bus::ok)
    ; // No response means "OK"
  else
    gdbserv_output_string (gdbserv, "E05");
}



void
gdb::process_get_mem (struct gdbserv_reg *reg_addr,
		      struct gdbserv_reg *reg_len)
{
  unsigned long long addr8;
  gdbserv_reg_to_ulonglong (gdbserv, reg_addr, &addr8);
  unsigned long len;
  gdbserv_reg_to_ulong (gdbserv, reg_len, &len);

  if (trace_gdbsid)
    cerr << "process_get_mem addr=" << addr8 << " len=" << len << endl;

  if (! cpu)
    {
      cerr << "No cpu!" << endl;
      gdbserv_output_string (gdbserv, "E01");
      return;
    }
  sid::bus* memory = cpu->find_bus ("debugger-bus");
  if (! memory)
    {
      cerr << "No debugger-bus!" << endl;
      gdbserv_output_string (gdbserv, "E02");
      return;
    }
 
  endian e;
  component::status s = 
    parse_attribute (cpu->attribute_value ("endian"), e);
  if (s != component::ok) assert (e == endian_unknown);

  // XXX: 64-bit addresses unsupported
  if (0 && addr8 >= (1ULL << 32))
    {
      cerr << "Bad address" << endl;
      gdbserv_output_string (gdbserv, "E03");
      return;
    }
  host_int_4 addr = addr8; // truncate

  if (len==1 && e==endian_big) 
    read_bus_word (gdbserv, memory, addr, big_int_1());
  else if (len==1 && e==endian_little)
    read_bus_word (gdbserv, memory, addr, little_int_1());
  else if (len==2 && e==endian_big) 
    read_bus_word (gdbserv, memory, addr, big_int_2());
  else if (len==2 && e==endian_little)
    read_bus_word (gdbserv, memory, addr, little_int_2());
  else if (len==4 && e==endian_big) 
    read_bus_word (gdbserv, memory, addr, big_int_4());
  else if (len==4 && e==endian_little)
    read_bus_word (gdbserv, memory, addr, little_int_4());
  else if (len==8 && e==endian_big) 
    read_bus_word (gdbserv, memory, addr, big_int_8());
  else if (len==8 && e==endian_little)
    read_bus_word (gdbserv, memory, addr, little_int_8());
  else if (e==endian_little)
    {
      for (unsigned long i=0; i<len; i++)
	read_bus_word (gdbserv, memory, addr + i, little_int_1());
    }
  else if (e==endian_big)
    {
      for (unsigned long i=0; i<len; i++)
	read_bus_word (gdbserv, memory, addr + i, big_int_1());
    }
  else
    {
      cerr << "Unknown endianness/size combination!" << endl;
      gdbserv_output_string (gdbserv, "E04");
    }
}


void
gdb::process_set_mem (struct gdbserv_reg *reg_addr,
		      struct gdbserv_reg *reg_len,
		      int binary)
{
  unsigned long long addr8;
  gdbserv_reg_to_ulonglong (gdbserv, reg_addr, &addr8);

  unsigned long len;
  gdbserv_reg_to_ulong (gdbserv, reg_len, &len);

  if (trace_gdbsid)
    cerr << "process_set_mem"
	<< " addr=" << addr8 
	<< " len=" << len 
	<< " binary=" << binary 
        << endl;

  if (! cpu)
    {
      cerr << "No cpu!" << endl;
      gdbserv_output_string (gdbserv, "E01");
      return;
    }
  sid::bus* memory = cpu->find_bus ("debugger-bus");
  if (! memory)
    {
      cerr << "No debugger-bus!" << endl;
      gdbserv_output_string (gdbserv, "E02");
      return;
    }
 
  endian e;
  component::status s = 
    parse_attribute (cpu->attribute_value ("endian"), e);
  if (s != component::ok) assert (e == endian_unknown);

  // XXX: 64-bit addresses unsupported
  if (0 && addr8 >= (1ULL << 32))
    {
      cerr << "Bad address" << endl;
      gdbserv_output_string (gdbserv, "E03");
      return;
    }
  host_int_4 addr = addr8; // truncate

  if (len==1 && e==endian_big) 
    write_bus_word (gdbserv, binary, memory, addr, big_int_1());
  else if (len==1 && e==endian_little)
    write_bus_word (gdbserv, binary, memory, addr, little_int_1());
  else if (len==2 && e==endian_big) 
    write_bus_word (gdbserv, binary, memory, addr, big_int_2());
  else if (len==2 && e==endian_little)
    write_bus_word (gdbserv, binary, memory, addr, little_int_2());
  else if (len==4 && e==endian_big) 
    write_bus_word (gdbserv, binary, memory, addr, big_int_4());
  else if (len==4 && e==endian_little)
    write_bus_word (gdbserv, binary, memory, addr, little_int_4());
  else if (len==8 && e==endian_big) 
    write_bus_word (gdbserv, binary, memory, addr, big_int_8());
  else if (len==8 && e==endian_little)
    write_bus_word (gdbserv, binary, memory, addr, little_int_8());
  else if (e==endian_little)
    {
      for (unsigned long i=0; i<len; i++)
	write_bus_word (gdbserv, binary, memory, addr + i, little_int_1());
    }
  else if (e==endian_big)
    {
      for (unsigned long i=0; i<len; i++)
	write_bus_word (gdbserv, binary, memory, addr + i, big_int_1());
    }
  else
    {
      cerr << "Unknown endianness/size combination!" << endl;
      gdbserv_output_string (gdbserv, "E04");
    }
}


void
gdb::process_set_pc (struct gdbserv_reg* val) 
{
  if (trace_gdbsid)
    cerr << "process_set_pc" << endl;

  // XXX: why is this a stub?
}


int
gdb::process_signal (int sig)
{
  if (trace_gdbsid)
    cerr << "process_signal " << sig << endl;

  // Mark next occurrence of this signal as to be ignored
  this->pending_signal_counts [sig] ++;

  return 0;
}


void
gdb::flush_i_cache () 
{
  if (trace_gdbsid)
    cerr << "flush_i_cache" << endl;

  this->icache_flush_pin.drive (0);
}


unsigned long
gdb::compute_signal (unsigned long sig)
{
  if (trace_gdbsid)
    cerr << "compute_signal " << sig << endl;

  return sig;
}


unsigned long
gdb::get_trap_number ()
{
  if (trace_gdbsid)
    cerr << "get_trap_number " << endl;

  return last_signal;
}


int
gdb::exit_program ()
{
  if (trace_gdbsid)
    cerr << "exit_program " << endl;

  // shut down target
  target_power (false);

  // signal gdb
  last_signal = GDBSERV_SIGINT;
  gdbserv_fromtarget_break (gdbserv, last_signal);

  // [don't] signal cfgroot to shut down
  // this->process_signal_pin.drive (1);

  return 0;
}


int
gdb::break_program ()
{
  if (trace_gdbsid)
    cerr << "break_program " << endl;

  // shut down target
  target_power (false);

  // signal gdb
  last_signal = GDBSERV_SIGINT;
  gdbserv_fromtarget_break (gdbserv, last_signal);
  return 0;
}


void
gdb::restart_program ()
{
  if (trace_gdbsid)
    cerr << "restart_program " << endl;

  // Drive restart pin so reset can be performed
  this->restart_pin.drive (1);
}


int
gdb::singlestep_program ()
{
  if (trace_gdbsid)
    cerr << "singlestep_program " << endl;

  assert (cpu != 0);
  component::status s = cpu->set_attribute_value ("enable-step-trap?", "1");
  if (s != component::ok)
    {
      cerr << "Cannot set enable-step-trap? attribute in cpu: status " << (int)s << endl;
    }

  // turn on target subsystem
  target_power (true);

  return 0;
}

void
gdb::sigkill_program ()
{
  if (trace_gdbsid)
    cerr << "sigkill_program " << endl;

  // signal gdb
  last_signal = GDBSERV_SIGKILL;
  gdbserv_fromtarget_exit (gdbserv, last_signal);
}


int
gdb::continue_program () 
{
  if (trace_gdbsid)
    cerr << "continue_program " << endl;

  // turn off single-stepping
  assert (cpu != 0);
  component::status s = cpu->set_attribute_value ("enable-step-trap?", "0");
  if (s != component::ok)
    {
      cerr << "Cannot clear enable-step-trap? attribute in cpu: status " << (int) s << endl;
    }

  // turn on target subsystem
  target_power (true);
  return 0;
}


int
gdb::remove_breakpoint (unsigned long type, struct gdbserv_reg *addr, struct gdbserv_reg *len)
{
  if (trace_gdbsid)
    cerr << "remove_breakpoint type " << type << endl;
  if (! enable_Z_packet) return 1;

  if (this->cpu == 0) return -1;

  host_int_8 watch_pc;
  gdbserv_reg_to_ulonglong (gdbserv, addr, &watch_pc);

  bool ok = this->remove_hw_breakpoint (watch_pc);
  return ok ? 0 : -1;
}


bool
gdb::remove_all_hw_breakpoints ()
{
  while (true)
    {
      hw_breakpoints_t::iterator it = this->hw_breakpoints.begin();
      if (it == this->hw_breakpoints.end()) break;

      // clean up carcass with refcount=0
      if (it->second == 0)
	{
	  this->hw_breakpoints.erase(it);
	  continue;
	}

      // decrement refcount
      host_int_8 address = it->first;
      bool ok = this->remove_hw_breakpoint (address);
      if (!ok) return ok;
    }
  return true;
}


bool
gdb::remove_hw_breakpoint (host_int_8 address)
{  
  if (this->hw_breakpoints[address] <= 0)
    {
      cerr << "sw-debug-gdb: duplicate breakpoint count underflow!" << endl;
      return false;
    }

  string watcher_name = 
    string("watch:") + 
    map_watchable_name ("gdb-register-pc") +
    string(":value:") + 
    make_numeric_attribute (address);
  
  this->hw_breakpoints[address] --;
  if (this->hw_breakpoints[address] == 0)
    {
      component::status s = this->cpu->disconnect_pin (watcher_name, & this->trapstop_pin);
      return (s == component::ok);
    }
  else
    return true;
}


int
gdb::set_breakpoint (unsigned long type, struct gdbserv_reg *addr, struct gdbserv_reg *len)
{
  if (trace_gdbsid)
    cerr << "set_breakpoint type " << type << endl;
  if (! enable_Z_packet) return 1;

  if (this->cpu == 0) return -1;

  host_int_8 watch_pc;
  gdbserv_reg_to_ulonglong (gdbserv, addr, &watch_pc);

  bool ok = this->add_hw_breakpoint (watch_pc);
  return ok ? 0 : -1;
}


bool
gdb::add_hw_breakpoint (host_int_8 address)
{  
  string watcher_name = 
    string("watch:") + 
    map_watchable_name ("gdb-register-pc") +
    string(":value:") + 
    make_numeric_attribute (address);
  
  this->hw_breakpoints[address] ++;
  if (this->hw_breakpoints[address] == 1)
    {
      component::status s = this->cpu->connect_pin (watcher_name, & this->trapstop_pin);
      return (s == component::ok);
    }
  else
    return true;
}



void
gdb::process_detach ()
{
  if (trace_gdbsid)
    cerr << "process_detach " << endl;

  bool ok = this->remove_all_hw_breakpoints ();
  if (!ok)
    {
      cerr << "sw-debug-gdb: cannot clean up hardware breakpoints" << endl;
    }

  // Decouple from gdbserv; caller will free it.
  this->gdbserv = 0;

  // Conditionally stop sim.
  if (this->exit_on_detach)
    {
      // shut down target
      target_power (false);
      // signal cfgroot to shut down
      this->process_signal_pin.drive (1);
    }
  else
    {
      // Don't resume target subsystem.  It may be halted on purpose,
      // such as after having executed an exit().  A gdb re-attach may
      // bring the target back to life.
    }
}


void
gdb::target_power (bool on)
{
  if (trace_gdbsid)
    cerr << "target_power " << on << endl;

  // clear signal cause
  last_signal = GDBSERV_SIGNONE;

  // signal target system to yield
  this->yield_pin.drive (0);

  // Set/clear enabled? attribute of target schedulers
  for (unsigned i=0; i<target_schedulers.size(); i++)
    {
      assert(target_schedulers[i]);
      component::status s = target_schedulers[i]->set_attribute_value ("enabled?", (on ? "1" : "0"));
      if (s != component::ok)
	{
	  cerr << "Cannot set enabled? attribute in scheduler: status " << (int) s << endl;
	}
    }

  // Set/clear yield-host-time? attribute of host schedulers
  for (unsigned j=0; j<host_schedulers.size(); j++)
    {
      assert(host_schedulers[j]);
      component::status s = host_schedulers[j]->set_attribute_value ("yield-host-time?",
							      (on ? "0" : "1"));
      if (s != component::ok)
	{
	  cerr << "Cannot set yield? attribute in scheduler: status " << (int) s << endl;
	}
    }
}


// ----------------------------------------------------------------------------
// Interface functions to gdbserv / client code


void
gdb::gdbsid_client_write (const unsigned char* ch, unsigned len)
{
  if (! this->connected_p)
    {
      cerr << "gdb: warning: writing but not yet connected" << endl;
    }

  for (unsigned i = 0; i < len; i++)
    {
      this->remote_tx_pin.drive (ch[i]);
    }
}


void
gdb::remote_rx_eof_handler ()
{
  if (this->trace_gdbserv)
    cout << "gdb: disconnect" << endl;

  if (! this->connected_p)
    {
      cerr << "gdb: unexpected disconnection." << endl;
      return;
    }

  this->connected_p = false;

  gdbserv_fromclient_detach (this->gdbserv);

  assert (this->gdbserv_client != 0);
  delete this->gdbserv_client;
  this->gdbserv_client = 0;
}


void
gdb::remote_rx_handler (host_int_4 value)
{
  // dispatch to EOF handler
  if (value & ~0x00FF)
    return this->remote_rx_eof_handler ();

  // first byte coming from a connection?
  if (! this->connected_p)
    {
      if (this->trace_gdbserv)
	cout << "gdb: connect" << endl;

      this->connected_p = true;

      assert (this->gdbserv_client == 0);
      this->gdbserv_client = new ::gdbserv_client();
      this->gdbserv_client->write = & gdbsid_client_write_hook;
      this->gdbserv_client->data = static_cast<void*>(this);

      // Attach to gdbserv engine.  NB: This calls back into this
      // object through the attach_hook.
      struct gdbserv* serv = gdbserv_fromclient_attach (this->gdbserv_client,
							& gdbsid_target_attach_hook,
							static_cast<void*>(this));
      if (serv == 0)
	{
	  // This shouldn't happen, since 
	  cerr << "gdb: refusing connection" << endl;
	  this->connected_p = false;
	  delete this->gdbserv_client;
	  this->gdbserv_client = 0;
	  this->remote_tx_pin.drive (~0); // send EOF
	  return;
	}
    }

  // forward the byte to gdbserv-input.
  assert (this->gdbserv != 0);

  char data = (value & 0x00FF);
  gdbserv_fromclient_data (this->gdbserv, & data, 1);
}


// ----------------------------------------------------------------------------
// Interface functions to sid code

gdb::gdb ():
  init_pin (this, & gdb::init_handler), 
  deinit_pin (this, & gdb::deinit_handler),
  connected_p (false),
  remote_rx_pin (this, & gdb::remote_rx_handler),
  cpu (0),
  gloss (0),
  cpu_trap_ipin (this, & gdb::cpu_trap_handler),
  gloss_process_signal_pin (this, & gdb::gloss_signal_handler),
  target_tx_pin (this, & gdb::target_tx_handler),
  stop_pin (this, & gdb::stop_handler),
  trapstop_pin (this, & gdb::trapstop_handler),
  start_pin (this, & gdb::start_handler),
  gdbserv (0),
  gdbserv_client (0)
{
  add_pin ("init", & init_pin);
  add_attribute ("init", & init_pin, "pin");
  add_pin ("deinit", & deinit_pin);
  add_attribute ("deinit", & deinit_pin, "pin");
  add_pin ("trap-code", & cpu_trap_code_pin);
  add_pin ("process-signal", & process_signal_pin);
  add_pin ("restart", & restart_pin);
  add_pin ("gloss-process-signal", & gloss_process_signal_pin);
  add_pin ("remote-rx", & remote_rx_pin);
  add_attribute ("remote-rx", & remote_rx_pin, "pin");
  add_pin ("remote-tx", & remote_tx_pin);
  add_attribute ("remote-tx", & remote_tx_pin, "pin");
  add_pin ("target-tx", & target_tx_pin);
  add_attribute ("target-tx", & target_tx_pin, "pin");
  add_pin ("trap", & cpu_trap_ipin, & cpu_trap_opin);
  add_pin ("yield", & yield_pin);
  add_attribute ("yield", & yield_pin, "pin");
  add_pin ("flush-icache", & icache_flush_pin);
  add_attribute ("flush-icache", & icache_flush_pin, "pin");
  add_pin ("stop-target", & stop_pin);
  add_attribute ("stop-target", & stop_pin, "pin");
  add_pin ("start-target", & start_pin);
  add_attribute ("start-target", & start_pin, "pin");

  // NB: We don't have to register the stoptrap_pin as an externally
  // visible input pin.
  // add_pin ("stop-target-trap", & stoptrap_pin);

  this->connected_p = false;
  add_attribute_ro ("connected?", & this->connected_p, "register");

  cpu = 0;
  gloss = 0;
  add_uni_relation ("cpu", & cpu);
  add_uni_relation ("gloss", & gloss);
  add_multi_relation ("target-schedulers", & target_schedulers);
  add_multi_relation ("host-schedulers", & host_schedulers);

  // trace flags
  trace_gdbserv = false;
  trace_gdbsid = false;
  exit_on_detach = false;
  enable_Z_packet = true;
  operating_mode_p = true;

  add_attribute_notify ("trace-gdbserv?", & trace_gdbserv, 
			this, & gdb::update_trace_flags, "setting");
  add_attribute_notify ("trace-gdbsid?", & trace_gdbsid,
			this, & gdb::update_trace_flags, "setting");
  add_attribute ("exit-on-detach?", & exit_on_detach, "setting");
  add_attribute ("enable-Z-packet?", & enable_Z_packet, "setting");
  add_attribute ("operating-mode?", & operating_mode_p, "setting");
}



void
gdb::init_handler (host_int_4) 
{
  if (!cpu) 
    {
      cerr << "sid-gdb: no debug cpu specified." << endl;
      return;
    }
  
  // suspend down target system
  target_power (false);
}


void
gdb::deinit_handler (host_int_4) 
{
  // disconnect if needed
  if (this->connected_p)
    this->remote_rx_eof_handler ();
}



void
gdb::update_trace_flags()
{
  gdbserv_state_trace = trace_gdbserv ? stderr : NULL;
} 


// Some sid-side component would like the target CPU to stop and hand
// control to the debugger.
void
gdb::stop_handler (host_int_4)
{
  if (trace_gdbsid)
    cerr << "stop_handler" << endl;

  // ignore if signal is pending
  if (this->pending_signal_counts [GDBSERV_SIGINT] > 0)
    {
      this->pending_signal_counts [GDBSERV_SIGINT] --;
      return;
    }

  // shut down target
  target_power (false);

  // attached?
  if (this->gdbserv == 0)
    {
      // XXX: Is this warning useful?
      cerr << "gdb: warning: stopping without attached debugger!" << endl;
    }
  else
    {
      // signal gdb
      last_signal = GDBSERV_SIGINT;
      gdbserv_fromtarget_break (gdbserv, last_signal);
    }
}


// The "target-stop-trap" pin was tickled, presumably because the CPU has
// hit an hardware breakpoint, emulated by a PC triggerpoint.
void
gdb::trapstop_handler (host_int_4)
{
  if (trace_gdbsid)
    cerr << "trapstop_handler" << endl;

  // ignore if signal is pending
  if (this->pending_signal_counts [GDBSERV_SIGTRAP] > 0)
    {
      this->pending_signal_counts [GDBSERV_SIGTRAP] --;
      return;
    }

  // shut down target
  target_power (false);

  // attached?
  if (this->gdbserv == 0)
    {
      // XXX: Is this warning useful?
      cerr << "gdb: warning: stopping without attached debugger!" << endl;
    }
  else
    {
      // signal gdb
      last_signal = GDBSERV_SIGTRAP;
      gdbserv_fromtarget_break (gdbserv, last_signal);
    }
}


// Some sid-side component would like the target CPU to start again.
// NB: This could upset an attached external debugger.
void
gdb::start_handler (host_int_4)
{
  if (trace_gdbsid)
    cerr << "start_handler" << endl;

  // resume target
  target_power (true);

  // attached?
  if (this->gdbserv != 0)
    {
      // We may already be halted, or running.  But there is no way to
      // inform gdb that we are about to resume running.
      cerr << "gdb: warning: starting without informing attached debugger!" << endl;
    }
}



// The GLOSS emulator is signalling that a process exit signal 
// is in process.
void
gdb::gloss_signal_handler (host_int_4 value)
{
  if (trace_gdbsid)
    cerr << "gloss_signal " << value << endl;

  // shut down target
  target_power (false);

  // detached?
  if (this->gdbserv == 0)
    {
      // forward signal
      this->process_signal_pin.drive (value);
    }
  else
    {
      // signal gdb
      last_signal = value & 0xff;
      gdbserv_fromtarget_exit (gdbserv, value >> 8);
    }
}


// The CPU is signalling that a trap of some sort is in progress.
void
gdb::cpu_trap_handler (host_int_4 trap_type) 
{
  if (trace_gdbsid)
    cerr << "cpu_trap_handler t=" << trap_type << endl;

  // Don't handle CPU traps in operating mode, except for:
  // - single-stepping
  if (this->operating_mode_p &&
      (trap_type != sidutil::cpu_trap_stepped))
    return;

  host_int_4 trapsig =
    trap_type == sidutil::cpu_trap_software ? GDBSERV_SIGTRAP :
    trap_type == sidutil::cpu_trap_breakpoint ? GDBSERV_SIGTRAP :
    trap_type == sidutil::cpu_trap_syscall ? GDBSERV_SIGTRAP :
    trap_type == sidutil::cpu_trap_invalid_insn ? GDBSERV_SIGILL :
    trap_type == sidutil::cpu_trap_memory_fault ? GDBSERV_SIGSEGV:
    trap_type == sidutil::cpu_trap_overflow ? GDBSERV_SIGFPE :
    trap_type == sidutil::cpu_trap_stepped ? GDBSERV_SIGTRAP :
    GDBSERV_SIGQUIT;

  // detached?
  if (this->gdbserv == 0)
    {
      // shut down target
      target_power (false);
      // forward signal
      this->process_signal_pin.drive (trap_type);
    }
  else 
    {
      // ignore if signal is pending
      if (this->pending_signal_counts [trapsig] > 0)
	{
	  this->pending_signal_counts [trapsig] --;
	  return;
	}

      // ack signal
      this->cpu_trap_opin.drive (cpu_trap_handled);
      // shut down target
      target_power (false);
      // signal gdb
      if (last_signal == GDBSERV_SIGNONE) 
	last_signal = trapsig;
      gdbserv_fromtarget_break (gdbserv, last_signal);
    }
}



// A 'standard output' character came in from the target.  Send it on
// to gdb via a "O" packet.  Each will pile up a pending '+' ACK in
// return ... gah.
void
gdb::target_tx_handler (host_int_4 value)
{
  // detached?
  if (this->gdbserv == 0)
    {
      ; // do nothing
    }
  else
    {
      gdbserv_output_discard (gdbserv);
      gdbserv_output_char (gdbserv, 'O');
      gdbserv_output_byte (gdbserv, ((int) value) & 0xFF);  
      gdbserv_output_packet (gdbserv);
      gdbserv_output_discard (gdbserv);
    }
}



gdb::~gdb()
{
  // Do nothing here; disconnection and gdbserv memory cleanup ought
  // to have occurred during deinit / detach earlier.
}



// ----------------------------------------------------------------------------

// Standard DLL wrapper-stuff

static vector<string>
gdb_list_types () 
{
  vector<string> types;
  types.push_back ("sw-debug-gdb");
  return types;
}

static component*
gdb_create (const string& name) 
{
  if (name == "sw-debug-gdb")
    return new gdb ();
  else
    return 0;
}

static void
gdb_delete (component* c) 
{
  delete dynamic_cast<gdb*>(c);
}

// static object
extern const component_library gdb_component_library;

const component_library gdb_component_library DLLEXPORT = {
  COMPONENT_LIBRARY_MAGIC,
  & gdb_list_types, 
  & gdb_create,
  & gdb_delete
};
