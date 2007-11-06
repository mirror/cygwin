// gloss.cxx - Gloss routines.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2005, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include <errno.h>
#include "gloss.h"
#include "libgloss.h"
#include "libcygmon.h"
#include "sh_compact.h"
#include "sh_media.h"
// ??? For now.  grep for newlib below.
#include "newlib.h"
#ifdef HAVE_TIMES
#include <sys/times.h>
#endif
#ifdef HAVE_GETTIMEOFDAY
#include <sys/time.h>
#endif

#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctime>


// Some usings not mentioned in gloss.h.
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::big_int_2;
using sid::big_int_4;

using sidutil::parse_attribute;
using sidutil::make_numeric_attribute;
using sidutil::make_attribute;

gloss32::gloss32() :
  reset_pin(this, &gloss32::reset_pin_handler),
  trap_type_ipin(this, &gloss32::trap_pin_handler),
  rx_pin(this, &gloss32::rx_handler),
  cpu (0),
  main (0),
  cpu_memory_bus (0),
  dynamic_configurator (0),
  syscall_numbering_scheme("libgloss"),
  max_fds(32),
  verbose_p(false)
{
  command_line.push_back ("<unknown>");

  // ??? There's a naming disconnect between "cpu" and "target_memory".
  add_accessor("target-memory", &this->cpu_memory_bus);

  add_pin("reset", &this->reset_pin);
  add_pin("trap", &this->trap_type_ipin, &this->trap_type_opin);
  add_pin("trap-code", &this->trap_code_pin);
  add_pin("trap-chain",
	  &this->trap_type_chain_ipin, &this->trap_type_chain_opin);
  add_pin("trap-code-chain", &this->trap_code_chain_pin);
  add_pin("process-signal", &this->process_signal_pin);

  add_pin("debug-tx", &this->tx_pin);
  add_pin("debug-rx", &this->rx_pin);
  add_pin("debug-rx-eof", &this->rx_eof_pin);
  add_attribute_ro_value ("tk tty", string("hw-visual-tty"), "gui");

  add_uni_relation("cpu", &this->cpu);
  add_uni_relation("main", &this->main);
  add_uni_relation("dynamic-configurator", &this->dynamic_configurator);
  add_pin ("configure", &this->sys_configure_pin);

  add_attribute_virtual("command-line", this,
			&gloss32::get_command_line,
			&gloss32::set_command_line,
			"setting");

  add_attribute("syscall-numbering-scheme", &this->syscall_numbering_scheme, "setting");
  add_pin ("config-result", &config_result_pin);
  add_pin ("config-error", &config_error_pin);

  add_attribute("verbose?", &this->verbose_p, "setting");
  
  add_attribute("max-fds", &this->max_fds, "setting");
  add_attribute("exit-code", &this->exit_code, "register");
  add_attribute_virtual ("state-snapshot", this,
                         & gloss32::save_state,
                         & gloss32::restore_state);
  host_ops = 0;
  fd_table = 0;
  exit_code = 0;
}

gloss32::~gloss32() throw()
{
  if (host_ops)
    delete host_ops;
  delete [] fd_table;
}

string
gloss32::get_command_line ()
{
  string cline;
  for (std::vector<string>::const_iterator it = command_line.begin();
       it != command_line.end ();
       it++)
    {
      cline += *it;
      if (it + 1 != command_line.end ())
	cline += " ";
    }
  return cline;
}

component::status
gloss32::set_command_line (const string& cline)
{
  vector<string> argv = sidutil::tokenize (cline, " ");
  command_line.clear();

  if (argv.empty())
    {
      command_line.push_back ("<unknown>");
      return component::bad_value;
    }

  // Insert all non-empty strings into command_line.
  for (std::vector<string>::iterator it = argv.begin();
       it != argv.end ();
       it++)
    {
      if (*it != "")
	command_line.push_back (*it);
    }

  return command_line.empty() ? component::bad_value : component::ok;
}

void
gloss32::reset_pin_handler(host_int_4 ignore)
{
  // Call a virtual method to do the work so derived classes can override.
  reset();
}

void
gloss32::setup_fds (int new_max_fds)
{
  if (new_max_fds < 0 || new_max_fds > 256)
    {
      cerr << "*** Bad value " << new_max_fds << " for max_fds." << endl;
      new_max_fds = 32;
    }
  if (fd_table)
    {
      // Close any open files.
      // FIXME: Undoubtedly incomplete.
      for (int i = 0; i < max_fds; ++i)
	{
	  int errcode;
	  if (! host_ops->close (fd_table[i], errcode))
	    cerr << "*** While resetting, close("
		   << fd_table[i]
		   << ") unexpectedly failed." << endl;
	}
      delete [] fd_table;
    }
  max_fds = new_max_fds;
  fd_table = new int[max_fds];
  for (int i = 0; i < max_fds; ++i)
    fd_table[i] = -1;
  fd_table[0] = 0;
  fd_table[1] = 1;
  fd_table[2] = 2;
}

void
gloss32::reset()
{
  this->setup_fds (max_fds);
  this->exit_code = 0;
}

// streaming/destreaming of gloss32
void
gloss32::stream_state (std::ostream& o) const
{
  o << " gloss32";
  /* FIXME: the fds eventually should be saved and restored in some manner. */
  o << " " << max_fds;
  o << " " << syscall_numbering_scheme; 
}

void
gloss32::destream_state (std::istream& i)
{
  string key;
  int new_max_fds;

  i >> key;

  if (key != "gloss32")
    {
      i.setstate (ios::badbit);
      return;
    }

  /* FIXME: the fds eventually should be saved and restored in some manner. */
  i >> new_max_fds;

  i >> syscall_numbering_scheme;

  this->setup_fds (new_max_fds);
}

// Called when rx pin is driven.  Record byte in buffer.

void
gloss32::rx_handler(host_int_4 byte)
{
  rx_buffer.push_back(byte);
}

// Update our knowledge of what the cpu's endianness is.

void
gloss32::update_endian()
{
  if (! this->cpu)
    {
      cerr << "*** CPU not specified!" << endl;
      return;
    }

  string attr_name = "endian";
  string attr_value = this->cpu->attribute_value(attr_name);
  component::status s = parse_attribute(attr_value, this->endian);
  if ((s != component::ok) || (this->endian == sidutil::endian_unknown))
    {
      cerr << "Unknown endianness (" << attr_value << "), assuming big" << endl;
      this->endian = sidutil::endian_big;
    }
}

// Memory access methods.

// Calling get_string with length = 0 indicates that there is no
// imposed length limit; read from memory until a NUL is encountered.

bool
gloss32::get_string (address32 address, string& value, unsigned length)
{
  if (! cpu_memory_bus)
    {
      cerr << "*** CPU memory bus not configured!" << endl;
      return false;
    }
  
  if (verbose_p)
    {
      cerr << "Reading " << length << " byte(s) from target memory at "
	   << make_numeric_attribute (address, ios::hex | ios::showbase) << ": ";
    }

  for (unsigned i = 0; (i < length || length == 0); i++)
    {
      char c;
      little_int_1 byte;

      bus::status s = cpu_memory_bus->read (address, byte);
      if (s != bus::ok) 
	{
	  if (verbose_p)
	    cerr << "failed" << endl;
	  return false;
	}

      c = byte;
      if (length == 0 && c == '\0')
	break;

      value += c;
      address++;
      
      if (verbose_p)
	cerr << "[" << c << "]";
    }

  if (verbose_p)
    cerr << endl;
  return true;
}

bool
gloss32::set_string (address32 address, const char* value, unsigned length)
{
  if (! this->cpu_memory_bus)
    {
      cerr << "*** CPU memory bus not configured!" << endl;
      return false;
    }
  
  if (verbose_p)
    {
      cerr << "Writing " << length << " byte(s) to target memory at "
	   << make_numeric_attribute (address, ios::hex | ios::showbase)
           << ": ";
    }
  
  for (unsigned i = 0; i < length; i++)
    {
      char c = value[i];
      little_int_1 byte = c;

      while (true)
	{
	  bus::status s = this->cpu_memory_bus->write(address, byte);
	  if (s == bus::ok) 
	    break;
	  else 
	    {
	      if (verbose_p)
		cerr << "failed" << endl;
	      return false;
	    }
	}
      address++;
      
      if (verbose_p)
	cerr << "[" << c << "]";
    }

  if (verbose_p)
    cerr << endl;

  return true;
}

bool
gloss32::set_string(address32 address, const string& value)
{
  return set_string (address, value.c_str(), value.length () + 1);
}

bool
gloss32::get_halfword (address32 addr, sid::host_int_2& value)
{
  if (! cpu_memory_bus)
    {
      if (verbose_p)
	cerr << "*** CPU memory bus not configured!" << endl;
      return false;
    }

  if (verbose_p)
    {
      cerr << "Reading word from target memory at "
	   << make_numeric_attribute (addr, ios::hex | ios::showbase)
	   << ":";
    }

  while (true)
    {
      bus::status s;

      if (endian == sidutil::endian_big)
	{
	  big_int_2 word;
	  s = cpu_memory_bus->read (addr, word);
	  value = word;
	}
      else
	{
	  little_int_2 word;
	  s = cpu_memory_bus->read (addr, word);
	  value = word;
	}

      if (s == bus::ok)
	break;
      else
	{
	  if (verbose_p)
	    cerr << "failed" << endl;
	  return false;
	}
    }
  if (verbose_p)
    cerr << make_numeric_attribute (value, ios::hex | ios::showbase) << endl;

  return true;
}

bool
gloss32::set_halfword(address32 addr, sid::host_int_2 value)
{
  if (! cpu_memory_bus)
    {
      if (verbose_p)
	cerr << "*** Target memory bus not configured!" << endl;
      return false;
    }

  if (verbose_p)
    {
      cerr << "Write word " << make_numeric_attribute (value, ios::hex | ios::showbase)
	   << " to target memory at "
	   << make_numeric_attribute (addr, ios::hex | ios::showbase);
    }

  while (true)
    {
      bus::status s;

      if (this->endian == sidutil::endian_big)
	{
	  big_int_2 word = value;
	  s = this->cpu_memory_bus->write(addr, word);
	}
      else
	{
	  little_int_2 word = value;
	  s = this->cpu_memory_bus->write(addr, word);
	}

      if (s == bus::ok)
	break;
      else
	{
	  if (verbose_p)
	    cerr << ": failed" << endl;
	  return false;
	}
    }

  if (verbose_p)
    cerr << endl;

  return true;
}


bool
gloss32::get_word(address32 address, int32& value)
{
  if (! cpu_memory_bus)
    {
      cerr << "*** CPU memory bus not configured!" << endl;
      return false;
    }

  if (verbose_p)
    {
      cerr << "Reading word from target memory at "
	   << make_numeric_attribute (address, ios::hex | ios::showbase)
	   << ": ";
    }

  while (true)
    {
      bus::status s;

      if (this->endian == sidutil::endian_big)
	{
	  big_int_4 word;
	  s = this->cpu_memory_bus->read(address, word);
	  value = word;
	}
      else
	{
	  little_int_4 word;
	  s = this->cpu_memory_bus->read(address, word);
	  value = word;
	}

      if (s == bus::ok)
	break;
      else
	{
	  if (verbose_p)
	    cerr << "failed" << endl;
	  return false;
	}
    }

  if (verbose_p)
    cerr << make_numeric_attribute (value, ios::hex | ios::showbase) << endl;

  return true;
}

bool
gloss32::set_word(address32 address, int32 value)
{
  if (! cpu_memory_bus)
    {
      cerr << "*** Target memory bus not configured!" << endl;
      return false;
    }

  if (verbose_p)
    {
      cerr << "Write word " << make_numeric_attribute (value, ios::hex | ios::showbase)
	   << " to target memory at "
	   << make_numeric_attribute (address, ios::hex | ios::showbase);
    }

  while (true)
    {
      bus::status s;

      if (this->endian == sidutil::endian_big)
	{
	  big_int_4 word = value;
	  s = this->cpu_memory_bus->write(address, word);
	}
      else
	{
	  little_int_4 word = value;
	  s = this->cpu_memory_bus->write(address, word);
	}

      if (s == bus::ok)
	break;
      else
	{
	  if (verbose_p)
	    cerr << ": failed" << endl;
	  return false;
	}
    }

  if (verbose_p)
    cerr << endl;

  return true;
}

// Return the value of the cpu's program counter.
// This is (currently) for informational purposes.  Thus we needn't care if
// the value returned is the address of the trap or faulting instruction, or
// some offset past it.
// ??? Might want to require the accuracy though (future concerns).

bool
gloss32::get_pc(address32& value)
{
  if (! this->cpu)
    {
      cerr << "*** CPU not specified!" << endl;
      return false;
    }

  // ??? If target needs to override this method, probably the only reason
  // will be to use a different string here.  Make member?
  string attr_name = "pc";

  string attr_value = this->cpu->attribute_value(attr_name);
  if (attr_value == "")
    {
      cerr << "*** Could not read pc!" << endl;
      return false;
    }

  host_int_4 value_number;
  parse_attribute(attr_value, value_number);
  value = value_number;
  return true;
}

// Handle an incoming trap request.
// This is split into 32 and 64 bit versions.
// 64 bit versions may need to pass 64 bit values through (1 or more) pins
// (??? maybe not though).

void
gloss32::trap_pin_handler(host_int_4 traptype)
{
  if (verbose_p)
    cerr << "gloss trap " << traptype << " code " << trap_code_pin.sense() << endl;

  host_int_4 trapcode = this->trap_code_pin.sense ();

  // Emulatable system call?
  if (syscall_trap_p())
    {
      update_endian();
      this->blocked_p = false;
      syscall_trap(); // may set blocked_p
      if (this->blocked_p)
	trap_type_opin.drive(sidutil::cpu_trap_reissue);
      else
	trap_type_opin.drive(sidutil::cpu_trap_skip);
      return;
    }

  // Dispatch it up the handler chain.
  this->trap_type_chain_ipin.driven (sidutil::cpu_trap_unhandled);
  this->trap_code_chain_pin.drive (trapcode);
  this->trap_type_chain_opin.drive (traptype);
  host_int_4 chain_response = this->trap_type_chain_ipin.sense();
  if (chain_response != sidutil::cpu_trap_unhandled)
    {
      this->trap_type_opin.drive (chain_response);
      return;
    }
  // No response from handler chain.

  // Dispatch to general fault handler here.
  update_endian ();
  fault_trap (traptype, trapcode);
}


void
gloss32::fault_trap(host_int_4 trap_type, host_int_4 trap_code)
{
  string trapname =
    trap_type == sidutil::cpu_trap_software ? "software" :
    trap_type == sidutil::cpu_trap_breakpoint ? "breakpoint" :
    trap_type == sidutil::cpu_trap_syscall ? "syscall" :
    trap_type == sidutil::cpu_trap_invalid_insn ? "invalid insn" :
    trap_type == sidutil::cpu_trap_memory_fault ? "memory" :
    trap_type == sidutil::cpu_trap_overflow ? "overflow" :
    trap_type == sidutil::cpu_trap_stepped ? "stepped" :
    "unknown";

  host_int_4 trapsig =
    trap_type == sidutil::cpu_trap_software ? newlib::sigTrap :
    trap_type == sidutil::cpu_trap_breakpoint ? newlib::sigTrap :
    trap_type == sidutil::cpu_trap_syscall ? newlib::sigTrap :
    trap_type == sidutil::cpu_trap_invalid_insn ? newlib::sigIll :
    trap_type == sidutil::cpu_trap_memory_fault ? newlib::sigSegv :
    trap_type == sidutil::cpu_trap_overflow ? newlib::sigFpe :
    trap_type == sidutil::cpu_trap_stepped ? newlib::sigTrap :
    newlib::sigAbrt;

  bool printcode =
    trap_type == sidutil::cpu_trap_software ? true :
    trap_type == sidutil::cpu_trap_breakpoint ? true :
    trap_type == sidutil::cpu_trap_syscall ? true :
    trap_type == sidutil::cpu_trap_invalid_insn ? false :
    trap_type == sidutil::cpu_trap_memory_fault ? true :
    trap_type == sidutil::cpu_trap_overflow ? false :
    trap_type == sidutil::cpu_trap_stepped ? false :
    true;

  cerr << "Fault (" << trapname;
  if (printcode) 
    cerr << ", " << make_numeric_attribute (trap_code, ios::hex | ios::showbase);
  cerr << ")";

  address32 pc;
  if (get_pc(pc))
    cerr << " pc=" << make_numeric_attribute (pc, ios::hex | ios::showbase) << endl;

  // ??? Probably the only reason a subclass would want to override us is to
  // use a different value here.  Make member?  Canonicalize the value?

  process_signal_pin.drive(trapsig);
  
  // Acknowlege trap.
  trap_type_opin.drive(sidutil::cpu_trap_skip);
}

bool
gloss32::set_host_error_result (int32 host_errno)
{
  return set_error_result (host_to_target_errno (host_errno));
}

// Convert host errno value to target.

int
gloss32::host_to_target_errno (int host_errno)
{
  return newlib::host_to_target_errno (host_errno);
}

bool
gloss32::get_int_argument(unsigned index, int32& value)
{
  assert (cpu);
  string attrName = "syscall-arg";
  attrName.append(1,'0' + index);
  assert (attrName != "");

  string attrValue = cpu->attribute_value (attrName);
  if (attrValue == "")
    {
      cerr << "Could not read attribute " << attrName
	   << " for ABI argument #" << index << endl;
      return false;
    }

  host_int_4 value_number;
  parse_attribute(attrValue, value_number);
  value = value_number;
  return true;
}

// default argument handling routines
bool
gloss32::set_int_result(int32 value) 
{
  assert (cpu);

  host_int_4 value_number = value;
  string attrValue = make_attribute(value_number);

  cpu->set_attribute_value ("syscall-result", attrValue);
  return true; // XXX: check?
}

bool
gloss32::set_error_result(int32 value) 
{
  assert (cpu);

  host_int_4 value_number = value;
  string attrValue = make_attribute(value_number);

  cpu->set_attribute_value ("syscall-error", attrValue);
  return true; // XXX: safe to assume success?
}



// syscall conversion routine
int32 
gloss32::target_to_host_syscall (int32 target_syscall)
{
  if(syscall_numbering_scheme == "cygmon")
    {
      switch(target_syscall)
        {
        case cygmon::SYS_exit:
          return libgloss::SYS_exit;
          break;
        case cygmon::SYS_open:
          return libgloss::SYS_open;
          break;
        case cygmon::SYS_close:
          return libgloss::SYS_close;
          break;
        case cygmon::SYS_read:
          return libgloss::SYS_read;
          break;
        case cygmon::SYS_write:
          return libgloss::SYS_write;
          break;
        case cygmon::SYS_kill:
          return libgloss::SYS_kill;
          break;
        case cygmon::SYS_time:
          return libgloss::SYS_time;
          break;
        case cygmon::SYS_gettimeofday:
          return libgloss::SYS_gettimeofday;
          break;
        default:
          return libgloss::SYS_unsupported;
          break;
        };
    }
  else if (syscall_numbering_scheme == "libgloss")
    {
      return target_syscall;
    }
  else if (syscall_numbering_scheme == "mep")
    {
      // syscall 0 is an alternate for SYS_reconfig on MeP
      if (target_syscall == 0)
	return libgloss::SYS_reconfig;
      return target_syscall;
    }
  else if (syscall_numbering_scheme == "sh-compact")
    {
      switch(target_syscall)
        {
        case sh_compact::SYS_exit:
          return libgloss::SYS_exit;
          break;
        case sh_compact::SYS_open:
          return libgloss::SYS_open;
          break;
        case sh_compact::SYS_close:
          return libgloss::SYS_close;
          break;
        case sh_compact::SYS_read:
          return libgloss::SYS_read;
          break;
        case sh_compact::SYS_write:
          return libgloss::SYS_write;
          break;
        case sh_compact::SYS_lseek:
          return libgloss::SYS_lseek;
          break;
        case sh_compact::SYS_unlink:
          return libgloss::SYS_unlink;
          break;
        case sh_compact::SYS_getpid:
          return libgloss::SYS_getpid;
          break;
        case sh_compact::SYS_fstat:
          return libgloss::SYS_fstat;
          break;
        case sh_compact::SYS_chdir:
          return libgloss::SYS_chdir;
          break;
        case sh_compact::SYS_stat:
          return libgloss::SYS_stat;
          break;
        case sh_compact::SYS_chmod:
          return libgloss::SYS_chmod;
          break;
        case sh_compact::SYS_utime:
          return libgloss::SYS_utime;
          break;
        case sh_compact::SYS_time:
          return libgloss::SYS_time;
          break;
        case sh_compact::SYS_argc:
          return libgloss::SYS_argc;
          break;
        case sh_compact::SYS_argnlen:
          return libgloss::SYS_argnlen;
          break;
        case sh_compact::SYS_argn:
          return libgloss::SYS_argn;
          break;
        default:
          return libgloss::SYS_unsupported;
          break;
        };
    }
  else if (syscall_numbering_scheme == "sh-media")
    {
      switch(target_syscall)
        {
        case sh_compact::SYS_exit:
          return libgloss::SYS_exit;
          break;
        case sh_compact::SYS_open:
          return libgloss::SYS_open;
          break;
        case sh_compact::SYS_close:
          return libgloss::SYS_close;
          break;
        case sh_compact::SYS_read:
          return libgloss::SYS_read;
          break;
        case sh_compact::SYS_write:
          return libgloss::SYS_write;
          break;
        case sh_compact::SYS_lseek:
          return libgloss::SYS_lseek;
          break;
        case sh_compact::SYS_time:
          return libgloss::SYS_time;
          break;
        case sh_compact::SYS_argc:
          return libgloss::SYS_argc;
          break;
        case sh_compact::SYS_argnlen:
          return libgloss::SYS_argnlen;
          break;
        case sh_compact::SYS_argn:
          return libgloss::SYS_argn;
          break;
        default:
          return libgloss::SYS_unsupported;
          break;
        };
    }
  else
    {
      cerr << "gloss: unsupported syscall numbering scheme. Assuming default (libgloss)" << endl;
      syscall_numbering_scheme = "libgloss";
      return target_syscall;
    };
}

// System call support.
bool
gloss32::syscall_trap_p()
{
  string attrValue = cpu->attribute_value ("syscall-trap");
  host_int_4 syscall_trap;
  parse_attribute(attrValue, syscall_trap);
  return ((trap_type_ipin.sense() == sidutil::cpu_trap_software)
	  && (trap_code_pin.sense() == syscall_trap));
}

void
gloss32::syscall_trap()
{
  int32 syscall;

  this->get_int_argument(0, syscall);
  if (verbose_p)
    cerr << "System call number " << syscall << endl;

  switch (target_to_host_syscall(syscall))
    {
    case libgloss::SYS_reconfig:
      do_sys_reconfig();
      break;
    case libgloss::SYS_read:
      do_sys_read();
      break;
    case libgloss::SYS_write:
      do_sys_write();
      break;
    case libgloss::SYS_exit:
      do_sys_exit();
      break;
    case libgloss::SYS_lseek:
      do_sys_lseek();
      break;
    case libgloss::SYS_fstat:
      do_sys_fstat();
      break;
    case libgloss::SYS_close:
      do_sys_close();
      break;
    case libgloss::SYS_open:
      do_sys_open();
      break;
    case libgloss::SYS_time:
      do_sys_time();
      break;
    case libgloss::SYS_gettimeofday:
      do_sys_gettimeofday();
      break;
    case libgloss::SYS_times:
      do_sys_times();
      break;
    case libgloss::SYS_unlink:
      do_sys_unlink();
      break;
    case libgloss::SYS_argc:
      do_sys_argc();
      break;
    case libgloss::SYS_argnlen:
      do_sys_argnlen();
      break;
    case libgloss::SYS_argn:
      do_sys_argn();
      break;
    default:
      do_nonstandard_target_syscalls (syscall);
      break;
    }
}

void
gloss32::do_nonstandard_target_syscalls (int32 target_syscall)
{
  if (verbose_p)
    cerr << "Unimplemented syscall " << target_syscall << endl;
  set_int_result(-1);
  set_error_result(newlib::eNoSys);
}

void
gloss32::configure (const string &config)
{
  // Call up to the base class first
  configurable_component::configure (config);

  // Now handle relevent configuration for us.
  if (config.size () <= 8)
    return;
  if (config.substr (0, 8) == "verbose=")
    {
      verbose_p = (config.substr (8) == "true");
      return;
    }
}

void
gloss32::sys_reconfig_set (const string &profile_name)
{
  // Make sure that the main component and the dynamic configurator component
  // have been related to us.
  if (! main)
    {
      set_error_result (1);
      return;
    }
  if (! dynamic_configurator)
    {
      set_error_result (2);
      return;
    }

  // Set main's lookup-dynamic-config attribute with the name we're looking
  // for. main will then write the configuration string into its
  // found-config-profile attribute if it is found.
  component::status s = main->set_attribute_value ("lookup-dynamic-config!",
						   profile_name);
  if (s != component::ok)
    {
      set_error_result (3);
      return;
    }

  // Pass the configuration string to the dynamic configurator for this board.
  string config = main->attribute_value ("found-dynamic-config");
  dynamic_configurator->set_attribute_value ("configure!", config);
  if (s != component::ok)
    {
      set_error_result (4);
      return;
    }

  host_int_4 result = config_result_pin.sense ();
  set_int_result (result);
  host_int_4 error = config_error_pin.sense ();
  set_error_result (error);
}

void
gloss32::sys_reconfig_reset (int32 handle)
{
  // Drive the configure! pin of the dynamic configurator
  sys_configure_pin.drive (handle);

  // If there is an error, then the config result will be zero, otherwise
  // it will be a config handle.
  host_int_4 result = config_result_pin.sense ();
  set_int_result (result);
  host_int_4 error = config_error_pin.sense ();
  set_error_result (error);
}

void
gloss32::do_sys_reconfig ()
{
  if (verbose_p)
    cerr << "sys_reconfig: ";

  int32 n, str_ptr, handle;
  string profile_name;

  get_int_argument(1, n);
  switch (n)
    {
    case 0: // warmup ()
      profile_name = "sid-internal-warmup";
      if (verbose_p)
	cerr << profile_name << endl;
      sys_reconfig_set (profile_name);
      break;
    case 1: // set (name)
      get_int_argument(2, str_ptr);
      get_string(str_ptr, profile_name);
      if (verbose_p)
	cerr << "set " << profile_name << endl;
      sys_reconfig_set (profile_name);
      break;
    case 2: // reset (handle)
      get_int_argument(2, handle);
      if (verbose_p)
	cerr << "reset 0x" << ios::hex << handle << ios::dec << endl;
      sys_reconfig_reset (handle);
      break;
    }
}

void
gloss32::do_sys_argc ()
{
  set_int_result (command_line.size ());
  set_error_result (0);
}

void
gloss32::do_sys_argnlen ()
{
  int32 n;
  get_int_argument(1, n);

  if (n < command_line.size ())
    {
      set_int_result (command_line[n].length ());
      set_error_result (0);
    }
  else
    {
      set_int_result (-1);
      set_error_result (newlib::eInval);
    }
}

void
gloss32::do_sys_argn ()
{
  int32 n, str_ptr;
  get_int_argument (1, n);
  get_int_argument(2, str_ptr);

  if (n < command_line.size ())
    {
      // Include the NULL byte.
      int i = command_line[n].length () + 1;
      if (set_string (str_ptr, command_line[n]))
	{
	  set_int_result (i);
	  set_error_result (0);
	}
      else
	{
	  set_int_result (-1);
	  set_error_result (newlib::eFault);
	}
    }
  else
    {
      set_int_result (-1);
      set_error_result (newlib::eInval);
    }
}

void
gloss32::do_sys_time()
{
  int32 timetp, rv;

  get_int_argument(1, timetp);
  rv = time(NULL);
  if (timetp)
    set_word(timetp, rv);

  set_int_result(rv);
}

void
gloss32::do_sys_gettimeofday()
{
#ifdef HAVE_GETTIMEOFDAY
  int32 timevalp, rv, value;
  struct timeval tv;

  /* Ignore 2nd parameter to gettimeofday().  */
  get_int_argument(1, timevalp);
  rv = gettimeofday(&tv, NULL);
  if (rv != -1)
    {
      value = tv.tv_sec;
      set_word(timevalp, value);
      value = tv.tv_usec;
      set_word(timevalp + 4, value);
    }
  set_int_result(rv);
#else
  set_int_result(-1);
  set_error_result(newlib::eNoSys);
#endif
}

void
gloss32::do_sys_times()
{
#ifdef HAVE_TIMES
  int32 value, rv, tmsp;
  struct tms tms;

  get_int_argument(1, tmsp);
  if (!tmsp)
    {
      set_int_result(EFAULT);
      return;
    }
  rv = times(&tms);
  if (rv != -1) 
    {
      value = tms.tms_utime;
      set_word(tmsp, value);
      value = tms.tms_stime;
      set_word(tmsp + 4, value);
      value = tms.tms_cutime;
      set_word(tmsp + 8, value);
      value = tms.tms_cstime;
      set_word(tmsp + 12, value);
    }
  set_int_result(rv);
#else
  set_int_result(-1);
  set_error_result(newlib::eNoSys);
#endif
}

void
gloss32::do_sys_unlink()
{
  string filename;
  int32 str_ptr;
  int errcode;

  get_int_argument(1, str_ptr);
  get_string(str_ptr, filename, 100);

  if (! this->remove (filename, errcode))
    {
      set_host_error_result (errcode);
      set_int_result (-1);
    }
  else
    set_int_result (0);
}

void
gloss32::do_sys_exit()
{
  int32 value;
  get_int_argument(1, value);
  if (verbose_p)
    cerr << "*** exit(" << value << ")" << endl;

  this->exit_code = value;
  
  if (value == 0)
    process_signal_pin.drive((value << 8) | newlib::sigQuit);
  else
    process_signal_pin.drive((value << 8) | newlib::sigAbrt);
}

void
gloss32::do_sys_lseek()
{
  int32 handle, offset, seek_type;
  hostops::seek_type whence;

  get_int_argument(1, handle);
  get_int_argument(2, offset);
  get_int_argument(3, seek_type);

  switch (seek_type)
    {
    case 1:
      whence = hostops::seek_cur;
      break;
    case 2:
      whence = hostops::seek_end;
      break;
    default:
    case 0:
      whence = hostops::seek_set;
      break;
    }

  size32 new_pos;
  int errcode;
  
  if (! this->lseek(handle, offset, whence, new_pos, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(-1);
      return;
    }
  set_int_result(new_pos);
}

void
gloss32::do_sys_fstat()
{
  struct stat st;
  int32 handle, ptr;

  get_int_argument (1, handle);
  get_int_argument (2, ptr);

  if (verbose_p)
    cerr << "*** fstat (" << handle << "," << ptr << ")" << endl;

  int fd = lookup_fd (handle);
  if (fd < 0)
    {
      set_host_error_result (EBADF);
      set_int_result (-1);
    }

  int rc = ::fstat (fd, &st);
  if (rc < 0)
    {
      set_host_error_result (errno);
      set_int_result (-1);
    }
  else
    {
      set_error_result (0);
      set_int_result (rc);
    }

  // Populate struct stat in target memory.
  set_halfword (ptr, st.st_dev);
  ptr += 2;
  set_halfword (ptr, st.st_ino);
  ptr += 2;
  set_word (ptr, st.st_mode);
  ptr += 4;
  set_halfword (ptr, st.st_nlink);
  ptr += 2;
  set_halfword (ptr, st.st_uid);
  ptr += 2;
  set_halfword (ptr, st.st_gid);
  ptr += 2;
  set_halfword (ptr, st.st_rdev);
  ptr += 2;
  set_word (ptr, st.st_size);
}

void
gloss32::do_sys_read()
{
  int32 handle, str_ptr, str_length;

  get_int_argument(1, handle);
  get_int_argument(2, str_ptr);
  get_int_argument(3, str_length);

  size32 len_read;
  int errcode;
  if (! this->read (handle, str_ptr, str_length, len_read, errcode))
    {
      set_host_error_result(errcode);
      // FIXME: what is proper result here?
      set_int_result(-1);
      return;
    }

  // return number of bytes read.
  set_int_result(len_read);
}

void
gloss32::do_sys_write()
{
  string str;
  int32 handle, str_ptr, str_length;

  get_int_argument(1, handle);
  get_int_argument(2, str_ptr);
  get_int_argument(3, str_length);

  size32 len_written;
  int errcode;
  if (! this->write (handle, str_ptr, str_length, len_written, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(-1);
      return;
    }

  // return number of bytes written
  set_int_result(len_written);
}

void
gloss32::do_sys_close()
{
  int32 handle;

  get_int_argument(1, handle);

  int errcode;
  if (! this->close(handle, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(1);
      return;
    }
  set_int_result(0);
}

void
gloss32::do_sys_open()
{
  string filename;
  int32 str_ptr, str_length, open_flags, mode, flags;

  get_int_argument(1, str_ptr);
  get_int_argument(2, open_flags);
  get_int_argument(3, mode);

  if (!get_string (str_ptr, filename))
    {
      set_error_result (newlib::eFault);
      set_int_result (-1);
      return;
    }

  if (!target_to_host_open_flags (open_flags, flags))
    {
      set_error_result(newlib::eInval);
      set_int_result(-1);
      return;
    }

  // Check for standard I/O. ":tt" is a magic filename for stdin/stdout.
  if (filename == ":tt")
    {
      switch (flags) {
      case (hostops::open_read_only | hostops::open_text):
	set_int_result(0);
	break;
      case (hostops::open_write_only | hostops::open_create | hostops::open_trunc | hostops::open_text):
	set_int_result(1);
	break;
      default:
	set_error_result(newlib::eInval);
	set_int_result(-1);
	break;
      }
      return;
    }
 
  int result_fd,errcode;

  if ((flags & hostops::open_create) != 0)
    {
      if (! this->open (filename, flags, mode, result_fd, errcode))
	{
	  set_host_error_result (errcode);
	  set_int_result (-1);
	}
      else
	set_int_result (result_fd);
    }
  else
    {
      if (! this->open (filename, flags, result_fd, errcode))
	{
	  set_host_error_result (errcode);
	  set_int_result (-1);
	}
      else
	set_int_result (result_fd);
    }
}

// This only handles O_RDONLY, O_WRONLY, O_RDWR, O_APPEND, O_CREAT & O_TRUNC.
#define NEWLIB_O_RDONLY		0x0000
#define NEWLIB_O_WRONLY		0x0001
#define NEWLIB_O_RDWR		0x0002
#define NEWLIB_O_APPEND		0x0008
#define NEWLIB_O_CREAT		0x0200
#define NEWLIB_O_TRUNC		0x0400
bool
gloss32::target_to_host_open_flags (int open_flags, int& flags)
{
  switch (open_flags & 3)
    {
    case NEWLIB_O_RDONLY:
      flags = hostops::open_read_only;
      break;
    case NEWLIB_O_WRONLY:
      flags = hostops::open_write_only;
      break;
    case NEWLIB_O_RDWR:
      flags = hostops::open_read_write;
      break;
    default:
      return false;
    }

  if ((open_flags & ~(3|NEWLIB_O_APPEND|NEWLIB_O_CREAT|NEWLIB_O_TRUNC)) != 0)
    return false;

  if (open_flags & NEWLIB_O_APPEND)
    flags |= hostops::open_append;

  if (open_flags & NEWLIB_O_CREAT)
    flags |= hostops::open_create;

  if (open_flags & NEWLIB_O_TRUNC)
    flags |= hostops::open_trunc;

  return true;
}

int
gloss32::lookup_fd (int target_fd)
{
  if (target_fd < 0 || target_fd >= max_fds)
    return -1;
  return fd_table[target_fd];
}

// Return unused fd or -1 if table is full.
// Allocating the fd is left to the caller.

int
gloss32::unused_fd ()
{
  for (int i = 0; i < max_fds; ++i)
    {
      if (fd_table[i] == -1)
	return i;
    }
  return -1;
}

// Record target_fd/host_fd mapping.

void
gloss32::alloc_fd (int target_fd, int host_fd)
{
  fd_table[target_fd] = host_fd;
}

void
gloss32::free_fd (int target_fd)
{
  assert (target_fd >= 0 && target_fd < max_fds);
  fd_table[target_fd] = -1;
}

bool
gloss32::open (string filename, int flags, int& result_fd, int& errcode)
{
  int host_fd,target_fd;

  if (verbose_p)
    cerr << "*** open(" << filename << ", " << flags << ")";

  target_fd = unused_fd ();
  if (target_fd == -1)
    {
      if (verbose_p)
	cerr << " -> failed, EMFILE" << endl;
      errcode = EMFILE;
      return false;
    }

  if (! host_ops->open (filename.c_str (), flags, host_fd, errcode))
    {
      if (verbose_p)
	cerr << " -> failed, " << errcode << endl;
      return false;
    }
  alloc_fd (target_fd, host_fd);
  result_fd = target_fd;

  if (verbose_p)
    cerr << " -> " << result_fd << endl;

  return true;
}

bool
gloss32::open (string filename, int flags, int mode, int& result_fd, int& errcode)
{
  int host_fd,target_fd;
  
  if (verbose_p)
    cerr << "*** open(" << filename << ", " << flags << ", " << mode << ")";

  target_fd = unused_fd ();
  if (target_fd == -1)
    {
      if (verbose_p)
	cerr << " -> failed, EMFILE" << endl;
      errcode = EMFILE;
      return false;
    }

  if (! host_ops->open (filename.c_str (), flags, mode, host_fd, errcode))
    {
      if (verbose_p)
	cerr << " -> failed, " << errcode << endl;
      return false;
    }
  alloc_fd (target_fd, host_fd);
  result_fd = target_fd;

  if (verbose_p)
    cerr << " -> " << result_fd << endl;

  return true;
}

bool
gloss32::close (int fd, int& errcode)
{
  int host_fd;

  // FIXME: 0,1,2?

  host_fd = lookup_fd (fd);
  if (host_fd == -1)
    {
      errcode = EBADF;
      return false;
    }

  if (! host_ops->close (host_fd, errcode))
    return false;
  free_fd (fd);
  return true;
}

// ??? 64 bit host edge conditions

bool
gloss32::read (int fd, address32 addr, size32 len,
	       size32& len_read, int& errcode)
{
  int host_fd = lookup_fd (fd);

  // Special handling for stdin.
  // If it hasn't been closed/reopened, use rx-pin.
  int use_rx_p = (fd == 0
		  && host_fd == 0);

  if (verbose_p)
    cerr << "*** read(" << fd << "," << addr << "," << len << ")" << endl;

  if (host_fd == -1)
    {
      errcode = EBADF;
      return false;
    }

  // Read a chunk at a time to reduce number of host syscalls.
  const unsigned int xfr_size = 4096; // ???
  char buf[xfr_size];
  string strbuf; // ???

  size32 total_read = 0;
  while (len > 0)
    {
      size32 count_read;

      if (use_rx_p)
	{
	  char c;

	  if (rx_buffer.size() > 0)
	    {
	      count_read = std::min (size_t(len), rx_buffer.size());
	      for (int i = 0; i < count_read; ++i)
		{
		  c = rx_buffer.front();
		  rx_buffer.erase (rx_buffer.begin());
		  strbuf += c;
		}
	    }
	  else if (rx_eof_pin.sense () != 0)
	    {
	      len_read = 0;
	      return true;
	    }
	  else
	    {
	      this->blocked_p = true;
	      errcode = EAGAIN;
	      return false;
	    }
	}
      else
	{
	  size32 count = len > xfr_size ? xfr_size : len;

	  // Read the next chunk from the file.

	  if (! host_ops->read32 (host_fd, buf, count, count_read, errcode))
	    {
	      // If we've already read something, return with that.
	      if (total_read > 0)
		{
		  len_read = total_read;
		  return true;
		}
	      return false;
	    }
	  if (count_read == 0)
	    {
	      len_read = total_read;
	      return true;
	    }
	  strbuf.assign (buf, count_read); // ???
	}

      // Write chunk to memory.

      if (! set_string (addr, strbuf))
	{
	  // FIXME: Signal error or return amount read (through to
	  // memory) thus far?
	  // FIXME: Should reset file position.
#if 0
	  if (total_read > 0)
	    {
	      len_read = total_read;
	      return true;
	    }
#endif
	  errcode = EINVAL; // ???
	  return false;
	}

      addr = addr + count_read;
      total_read += count_read;
      len -= count_read;

      // if we have read from the rx_buffer, then we have either emptied it
      // or read the required number of characters so we should exit the loop
      if (use_rx_p && count_read > 0)
	break;
    }

  len_read = total_read;
  return true;
}

// ??? 64 bit host edge conditions

bool
gloss32::write (int fd, address32 addr, size32 len,
		size32& len_written, int& errcode)
{
  int host_fd = lookup_fd (fd);

  // Special handling for stdout/stderr.
  // If it hasn't been closed/reopened, use tx-pin.
  // ??? Allow separating stdout,stderr.
  int use_tx_p = ((fd == 1 || fd == 2)
		  && host_fd == fd);

  if (verbose_p)
    cerr << "*** write(" << fd << ", 0x" << ios::hex << addr << ", " << ios::dec << len << ")" << endl;

  if (host_fd == -1)
    {
      errcode = EBADF;
      return false;
    }

  // Write a chunk at a time to reduce number of host system calls.
  const unsigned int xfr_size = 4096; // ???

  size32 total_written = 0;
  while (len > 0)
    {
      string buf; // ??? Previously allocated char array?

      size32 count = len > xfr_size ? xfr_size : len;

      // Read next chunk from memory.

      if (! get_string (addr, buf, count))
	{
	  // FIXME: Signal error or return amount written thus far?
	  // FIXME: Should reset file position.
#if 0
	  if (total_written > 0)
	    {
	      len_written = total_written;
	      return true;
	    }
#endif
	  errcode = EINVAL; // ???
	  return false;
	}

      addr = addr + count;

      // Write chunk to file.

      unsigned int count_written;

      if (use_tx_p)
	{
	  unsigned i;
	  for (i = 0; i < count; ++i)
	    {
	      host_int_4 value = buf[i];
	      tx_pin.drive(value);
	    }
	  count_written = i;
	}
      else
	{
	  if (! host_ops->write32 (host_fd, buf.c_str(), count, count_written, errcode))
	    {
	      // If we've already written something, return with that.
	      if (total_written > 0)
		{
		  len_written = total_written;
		  return true;
		}
	      return false;
	    }
	}
      if (count_written == 0)
	{
	  len_written = total_written;
	  return true;
	}

      total_written += count_written;
      len -= count_written;
    }

  len_written = total_written;
  return true;
}

bool
gloss32::remove (string filename, int& errcode)
{
  return host_ops->remove (filename.c_str (), errcode);
}

bool
gloss32::rename (string oldname, string newname, int& errcode)
{
  return host_ops->rename (oldname.c_str (), newname.c_str (), errcode);
}

bool
gloss32::lseek (int fd, offset32 offset, hostops::seek_type how,
		size32& result, int& errcode)
{
  if (verbose_p)
    cerr << "*** lseek(" << fd << ", " << offset << ", " << (int) how << ")";

  int host_fd = lookup_fd (fd);
  if (host_fd == -1)
    {
      if (verbose_p)
	cerr << " -> failed, EBADF" << endl;
      errcode = EBADF;
      return false;
    }

  size32 new_pos;
  if (! host_ops->lseek32 (host_fd, offset, how, new_pos, errcode))
    {
      if (verbose_p)
	cerr << " -> failed, " << errcode << endl;
      return false;
    }

  if (verbose_p)
    cerr << " -> " << new_pos << endl;
  result = new_pos;
  return true;
}

bool
gloss32::getsize (int fd, size32& size, int& errcode)
{
  int host_fd = lookup_fd (fd);
  if (host_fd == -1)
    {
      errcode = EBADF;
      return false;
    }
  return host_ops->getsize32 (host_fd, size, errcode);
}

bool
gloss32::tmpnam (string& filename, int& errcode)
{
  char filename_buf[1024]; // FIXME

  if (! host_ops->tmpnam (filename_buf, errcode))
    return false;
  filename = filename_buf;
  return true;
}

bool
gloss32::isatty (int fd, bool& result, int& errcode)
{
  int host_fd = lookup_fd (fd);
  if (host_fd == -1)
    {
      errcode = EBADF;
      return false;
    }

  // FIXME: Quick hack.
  if (host_fd == 0 || host_fd == 1 || host_fd == 2)
    result = true;
  else
    result = false;
  return true;
}

std::ostream& 
operator << (std::ostream& out, const gloss32& it)
{
  it.stream_state(out);
  return out;
}

std::istream& 
operator >> (std::istream& in, gloss32& it)
{
  it.destream_state(in);
  return in;
}

