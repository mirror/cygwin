// mips.cxx - MIPS monitors (IDT, PMON, ...).  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// ??? At present this is very minimal.  Enough to get the simulator going.
// Cadillac version left for later.

#include "config.h"
#include "mips.h"
#include "newlib.h"

using namespace std;
using namespace sid;
using namespace sidutil;

mips32_idt::mips32_idt()
{
  // so we can query how big it is
  add_uni_relation("ram", &this->ram);
  // so we can stuff in our monitor implementation
  add_uni_relation("rom", &this->rom);

  this->register_attribute_names[-1] = "r0"; // result
  this->register_attribute_names[-2] = "r0"; // error
  this->register_attribute_names[0] = "r3";  // function code
  this->register_attribute_names[1] = "r4";  // arg 1
  this->register_attribute_names[2] = "r5";  // arg 2
  this->register_attribute_names[3] = "r6";  // arg 3
}

// For the idt monitor we need to fill the rom with suitable contents.

void
mips32_idt::reset()
{
  gloss32::reset ();

  // Fill the ROM with suitable code.
  update_endian();
  int32 syscall_insn = 0x0000000c;
  int32 return_insn = 0x03e00008;
  sid::bus* memory = this->rom->find_bus ("read-write-port");
  assert (memory != 0);

  int32 addr = 0;
  for (int i = 0; i < SYSCALL_MAX; ++i, addr += 8)
    {
      int32 insn = syscall_insn | ((i + SYSCALL_MIN) << 6);

      if (this->endian == sidutil::endian_little)
	{
	  little_int_4 little_insn = insn;
	  little_int_4 little_return_insn = return_insn;
	  bus::status s = memory->write(addr, little_return_insn);
	  assert (s == bus::ok);
	  // Execute the syscall in the delay slot.
	  s = memory->write(addr + 4, little_insn);
	  assert (s == bus::ok);
	}
      else
	{
	  big_int_4 big_insn = insn;
	  big_int_4 big_return_insn = return_insn;
	  bus::status s = memory->write(addr, big_return_insn);
	  assert (s == bus::ok);
	  // Execute the syscall in the delay slot.
	  s = memory->write(addr + 4, big_insn);
	  assert (s == bus::ok);
	}
    }
}

bool
mips32_idt::get_int_argument(unsigned index, int32& value)
{
  assert (cpu);
  string attr_name = register_attribute_names[index];
  assert (attr_name != "");

  string attr_value = cpu->attribute_value (attr_name);
  if (attr_value == "")
    {
      cerr << "Could not read attribute " << attr_name
	   << " for ABI argument #" << index << endl;
      return false;
    }

  host_int_4 value_number;
  parse_attribute(attr_value, value_number);
  value = value_number;
  return true;
}

bool
mips32_idt::set_int_result(int32 value) 
{
  assert (cpu);
  string attr_name = register_attribute_names[-1];
  assert (attr_name != "");

  host_int_4 value_number = value;
  string attr_value = make_attribute(value_number);

  cpu->set_attribute_value (attr_name, attr_value);
  return true; // XXX: check?
}

bool
mips32_idt::set_error_result(int32 target_errno) 
{
  assert (cpu);
  string attr_name = register_attribute_names[-2];
  assert (attr_name != "");

  host_int_4 value_number = target_errno;
  string attr_value = make_attribute(value_number);

  cpu->set_attribute_value (attr_name, attr_value);
  return true; // XXX: safe to assume success?
}

bool
mips32_idt::syscall_trap_p()
{
  host_int_4 trap_type = trap_type_ipin.sense ();
  host_int_4 trap_code = trap_code_pin.sense ();

  // MIPS system calls work by branching to specific entry points in the
  // ROM monitor.  What we do is fill the ROM with `syscall' insns which we
  // then intercept.
  if ((trap_type == sidutil::cpu_trap_syscall)
      && (trap_code >= SYSCALL_MIN)
      && (trap_code < (SYSCALL_MIN + SYSCALL_MAX)))
    return true;

  // _exit however uses the `break' insn.  Lovely.
  if (trap_type == sidutil::cpu_trap_breakpoint
      && trap_code == BREAK_EXIT)
    return true;

  return false;
}

void
mips32_idt::syscall_trap()
{
  int syscall;

  // Turn a break exit into a syscall exit.
  if (trap_type_ipin.sense() == sidutil::cpu_trap_breakpoint
      && trap_code_pin.sense() == BREAK_EXIT)
    syscall = SYSCALL_EXIT;
  else
    syscall = trap_code_pin.sense() - SYSCALL_MIN;

  if (verbose_p)
    {
      cerr << "MIPS/idt call number " << syscall << endl;
    }

  switch (syscall)
    {
    case SYSCALL_EXIT:
      {
	int32 value;
	get_int_argument(1, value);
	if (verbose_p)
	  cerr << "*** exit(" << value << ")" << endl;

	if (value == 0)
	  process_signal_pin.drive((value << 8) | newlib::sigNone);
	else
	  process_signal_pin.drive(newlib::sigAbrt);
      }
      break;

    case SYSCALL_GET_MEM_INFO:
      {
	int32 bufptr;
	get_int_argument(1, bufptr);
	// memory size
	int32 mem_size;
	string mem_size_attr = "size";
	string attr_value = this->ram->attribute_value (mem_size_attr);
	if (attr_value == "")
	  {
	    cerr << "Could not read ram size attribute." << endl;
	    mem_size = 0;
	  }
	parse_attribute(attr_value, mem_size);
	set_word(bufptr, mem_size);
	// instruction cache size
	set_word(bufptr + 4, 0);
	// data cache size
	set_word(bufptr + 8, 0);
      }
      break;

    case SYSCALL_WRITE:
      {
	int32 fd;
	int32 address;
	int32 length;
	string str;

	get_int_argument(1, fd);
	get_int_argument(2, address);
	get_int_argument(3, length);

	size32 len_written;
	int errcode;
	if (! this->write (fd, address, length, len_written, errcode))
	  {
	    set_error_result(host_to_target_errno(errcode));
	    set_int_result(-1);
	  }
	else
	  set_int_result(len_written);
      }
      break;

    default:
      if (verbose_p)
	{
	  cerr << "Unimplemented syscall " << syscall << endl;
	}
      set_int_result(-1);
      set_error_result(newlib::eNoSys);
    }
}

// Convert host errno value to target.

int
mips32_idt::host_to_target_errno (int host_errno)
{
  return newlib::host_to_target_errno (host_errno);
}
