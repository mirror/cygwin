// m32r.cxx - Implementation of the M32R libgloss specifics.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "m32r.h"
#include "libgloss.h"
#include "newlib.h"

using namespace std;
using namespace sid;
using namespace sidutil;

m32r_libgloss::m32r_libgloss()
{
  register_attribute_names[-1] = "r0"; // result
  register_attribute_names[-2] = "r0"; // error
  register_attribute_names[0] = "r0";  // function code
  register_attribute_names[1] = "r1";  // arg 1
  register_attribute_names[2] = "r2";  // arg 2
  register_attribute_names[3] = "r3";  // arg 3
}

bool
m32r_libgloss::get_int_argument(unsigned index, int32& value)
{
  assert (cpu);
  string attrName = register_attribute_names[index];
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

bool
m32r_libgloss::set_int_result(int32 value) 
{
  assert (cpu);
  string attrName = register_attribute_names[-1];
  assert (attrName != "");

  host_int_4 value_number = value;
  string attrValue = make_attribute(value_number);

  cpu->set_attribute_value (attrName, attrValue);
  return true; // XXX: check?
}

bool
m32r_libgloss::set_error_result(int32 value) 
{
  assert (cpu);
  string attrName = register_attribute_names[-2];
  assert (attrName != "");

  host_int_4 value_number = value;
  string attrValue = make_attribute(value_number);

  cpu->set_attribute_value (attrName, attrValue);
  return true; // XXX: safe to assume success?
}

bool
m32r_libgloss::syscall_trap_p()
{
  // M32R system calls use TRAP 0.
  return ((trap_type_ipin.sense() == sidutil::cpu_trap_software)
	  && (trap_code_pin.sense() == 0)); /* trap 0 */
}

void
m32r_libgloss::syscall_trap()
{
  int32 syscall;

  get_int_argument(0, syscall);
  if (verbose_p)
    {
      cerr << "M32R/libgloss system call number " << syscall << endl;
    }

  switch (syscall)
    {
    case libgloss::SYS_exit:
      {
	int32 value;
	get_int_argument(1, value);
	if (verbose_p)
	  cerr << "*** exit(" << value << ")" << endl;

	if (value == 0)
	  process_signal_pin.drive(newlib::sigQuit);
	else
	  process_signal_pin.drive(newlib::sigAbrt);
      }
      break;

    case libgloss::SYS_write:
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
	    return;
	  }

	set_int_result(len_written);
      }
      break;

    case libgloss::SYS_read:
      {
	int32 fd;
	int32 address;
	int32 length;
	string str;

	get_int_argument(1, fd);
	get_int_argument(2, address);
	get_int_argument(3, length);

	size32 len_read;
	int errcode;
	if (! this->read (fd, address, length, len_read, errcode))
	  {
	    set_error_result(host_to_target_errno(errcode));
	    set_int_result(-1);
	    return;
	  }

	set_int_result(len_read);
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
m32r_libgloss::host_to_target_errno (int host_errno)
{
  return newlib::host_to_target_errno (host_errno);
}
