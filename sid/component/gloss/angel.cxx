// angel.cxx - An emulation of the Angel ROM monitor.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// Details of the Angel ROM monitor and, specifically, the system call
// interface, can be found in Chapter 8 of the ARM Software
// Development Toolkit Reference Guide (ARM part no. DUI 0041B).

#include "config.h"

// XXX: autoconf these?
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#include "angel.h"
#include "newlib.h"

arm_angel::arm_angel():
  errnum(0), heapBase(0x80000), heapLimit(1024), stackBase(0x200000),
  stackLimit(0x200000), startupTime(clock())
{
  add_attribute("heap-base", &this->heapBase, "setting");
  add_attribute("heap-limit", &this->heapLimit, "setting");
  add_attribute("stack-base", &this->stackBase, "setting");
  add_attribute("stack-limit", &this->stackLimit, "setting");

  register_attribute_names[0] = "r0";
  register_attribute_names[1] = "r1";

  // ??? The extra space is for compatibility with existing ARM tools, right?
  command_line.clear ();
  command_line.push_back ("sid ");
}

// Angel only has file descriptors 0 and 1 opened initially.

void
arm_angel::reset()
{
  gloss32::reset ();
  if (fd_table[2] > 2)
    {
      int errcode;
      if (! host_ops->close (fd_table[2], errcode))
	cerr << "*** While resetting, close("
	  << fd_table[2]
	     << ") unexpectedly failed." << endl;
    }
  fd_table[2] = -1;
}

bool
arm_angel::get_int_argument(unsigned index, int32& value)
{
  assert(this->cpu);
  string attr_name = this->register_attribute_names[index];
  assert(attr_name != "");

  string attr_value = this->cpu->attribute_value(attr_name);
  if (attr_name == "")
    {
      cerr << "Could not read attribute " << attr_name << " for ABI "
	   << "argument #" << index << endl;
      return false;
    }

  host_int_4 value_number;
  parse_attribute(attr_value, value_number);
  value = value_number;

  return true;
}

// Error codes in the Angel ROM monitor are always indicated in R0.

bool
arm_angel::set_int_result(int32 value)
{
  assert(this->cpu);
  string attr_name = this->register_attribute_names[0];
  assert(attr_name != "");

  host_int_4 value_number = value;
  string attr_value = make_attribute(value_number);

  this->cpu->set_attribute_value(attr_name, attr_value);
  return true;
}

bool
arm_angel::set_error_result(int32 target_errno)
{
  errnum = target_errno;
  return true;
}

bool
arm_angel::set_host_error_result (int32 host_errno)
{
  return set_error_result (host_to_target_errno (host_errno));
}

// System call support.

// Return a boolean indicating if the trap is a syscall request.

bool
arm_angel::syscall_trap_p()
{
  // ARM system calls use trap 0x123456.
  // Thumb system calls use trap 0xab.
  return ((this->trap_type_ipin.sense() == sidutil::cpu_trap_software)
	  && (this->trap_code_pin.sense() == 0x123456
	      /* ??? Ick, of course.  Need to know whether in thumb mode,
		 but that can't be done here.  */
	      /* ??? Yes it can now that there's the tbit pin.  */
	      || this->trap_code_pin.sense() == 0xab));
}

void
arm_angel::syscall_trap()
{
  int32 syscall;

  this->get_int_argument(0, syscall);
  if (verbose_p)
    cerr << "Angel system call number " << syscall << endl;

  switch (syscall)
    {
    case syscall_read:
      do_read();
      break;
    case syscall_write:
      do_write();
      break;
    case syscall_flen:
      do_flen();
      break;
    case syscall_seek:
      do_seek();
      break;
    case syscall_close:
      do_close();
      break;
    case syscall_open:
      do_open();
      break;
    case syscall_readc:
      do_readc();
      break;
    case syscall_write0:
      do_write0();
      break;
    case syscall_writec:
      do_writec();
      break;
    case syscall_rename:
      do_rename();
      break;
    case syscall_tmpnam:
      do_tmpnam();
      break;
    case syscall_remove:
      do_remove();
      break;
    case syscall_clock:
      do_clock();
      break;
    case syscall_istty:
      do_istty();
      break;
    case syscall_iserror:
      do_iserror();
      break;
    case syscall_time:
      set_int_result(time(NULL));
      break;
    case syscall_system:
      do_system();
      break;
    case syscall_errno:
      set_int_result(errnum);
      break;
    case syscall_get_cmdline:
      do_get_cmdline();
      break;
    case syscall_heapinfo:
      do_heapinfo();
      break;
    case syscall_report_exception:
      do_report_exception();
      break;
    default:
      if (verbose_p)
	cerr << "Unimplemented syscall " << syscall << endl;
      set_int_result(-1);
      set_error_result(newlib::eNoSys);
    }
}

// Convert host errno value to target.

int
arm_angel::host_to_target_errno (int host_errno)
{
  return newlib::host_to_target_errno (host_errno);
}

// Methods to handle the individual system calls.  No need for any
// argument passing, as the methods interrogate the CPU's registers
// directly.

void
arm_angel::do_report_exception()
{
  int32 reason;

  get_int_argument(1, reason);

  if (reason == exception_exit)
    {
      // Angel does not pass the _exit() code.
      host_int_4 rc = 0;
      set_int_result(0); // XXX: necessary?
      process_signal_pin.drive((rc << 8) | newlib::sigNone);
    }
  else
    {
      // Runtime error.
      set_int_result(1);
      process_signal_pin.drive(newlib::sigAbrt);
    }
}

void
arm_angel::do_readc()
{
  if (rx_buffer.size() > 0)
    {
      // cerr << endl;
      // cerr << "do_readc() => " << rx_buffer.front() << "0x" << hex << rx_buffer.front() << endl;
      // cerr << endl;
      set_int_result(rx_buffer.front());
      rx_buffer.erase(rx_buffer.begin());
    }
  else
    {
      this->blocked_p = true;
    }
}

void
arm_angel::do_get_cmdline()
{
  int32 ptr, str_ptr;

  get_int_argument(1, ptr);
  if (!get_word(ptr, str_ptr))
    {
      set_int_result(-1);
      set_error_result(newlib::eFault);
    }

  set_string(str_ptr, get_command_line() + '\0');
}

void
arm_angel::do_clock()
{
  int32 cs; // centiseconds
  clock_t now = clock();

  cs = (now - startupTime) / CLOCKS_PER_SEC / 100;
  set_int_result(cs);
}

void
arm_angel::do_iserror()
{
  int32 ptr, statusWord;

  get_int_argument(1, ptr);
  get_word(ptr, statusWord);

  if ((statusWord >> 31) != 0)
    set_int_result(1);
  else
    set_int_result(0);
}

void
arm_angel::do_remove()
{
  string filename;
  int32 ptr, str_ptr, str_length;
  
  get_int_argument(1, ptr);
  get_word(ptr, str_ptr);
  get_word(ptr + 4, str_length);

  get_string(str_ptr, filename, str_length);
  int errcode;
  if (! this->remove (filename, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(1);
    }
  else
    set_int_result(0);
}

void
arm_angel::do_istty()
{
  int32 ptr, handle;

  get_int_argument(1, ptr);
  get_word(ptr, handle);

  bool isatty_p;
  int errcode;
  if (! this->isatty(handle, isatty_p, errcode))
    {
      set_host_error_result(errcode);
      // Use 1 as an error code.
      set_int_result(1);
      return;
    }

  if (isatty_p)
    {
      // Interactive channel.
      set_int_result(-1);
    }
  else
    {
      // Non-interactive channel.
      set_int_result(0);
    }
}

void
arm_angel::do_tmpnam()
{
  string filename;
  int32 ptr, str_ptr, str_length;

  get_int_argument(1, ptr);
  get_word(ptr, str_ptr);
  get_word(ptr + 8, str_length);

  int errcode;
  if (! this->tmpnam(filename, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(1);
      return;
    }

  if (strlen(filename.c_str()) + 1 > str_length)
    {
      set_error_result(newlib::eFault);
      set_int_result(1);
      return;
    }

  set_string(str_ptr, filename + '\0');
  set_int_result(0);
}

void
arm_angel::do_seek()
{
  int32 ptr, handle, offset;

  get_int_argument(1, ptr);
  get_word(ptr, handle);
  get_word(ptr + 4, offset);

  size32 new_pos;
  int errcode;
  if (! this->lseek(handle, offset, hostops::seek_set, new_pos, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(1);
      return;
    }
  set_int_result(0);
}

void
arm_angel::do_write0()
{
  string byte;
  int32 ptr;
  host_int_4 value;

  get_int_argument(1, ptr);

  do {
    byte = ""; // ???
    if (! get_string (ptr, byte, 1))
      {
	// FIXME: not sure what to do in these circumstances.
	assert(("write0 memory read failed", 0));
	return;
      }
    if (byte[0] != '\0')
      {
	value = byte[0];
	tx_pin.drive(value);
	// ??? The next line was written very carefully so that it compiles.
	// host_int's aren't just plain int's.
	ptr = ptr + 1;
      }
  } while (byte[0] != '\0');
}

void
arm_angel::do_writec()
{
  string byte;
  int ptr;
  host_int_4 value;

  get_int_argument(1, ptr);

  if (! get_string (ptr, byte, 1))
    {
      // FIXME; not sure what to do in these circumstances.
      assert(("writec memory read failed", 0));
      return;
    }
  value = byte[0];
  tx_pin.drive(value);
}

void
arm_angel::do_rename()
{
  int32 ptr, old_name_ptr, old_name_length, new_name_ptr, new_name_length;
  string old_filename, new_filename;

  get_int_argument(1, ptr);
  get_word(ptr, old_name_ptr);
  get_word(ptr + 4, old_name_length);
  get_word(ptr + 8, new_name_ptr);
  get_word(ptr + 12, new_name_length);

  get_string(old_name_ptr, old_filename, old_name_length);
  get_string(new_name_ptr, new_filename, new_name_length);

  int errcode;
  if (! this->rename (old_filename, new_filename, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(1);
    }
  else
    set_int_result(0);
}

void
arm_angel::do_system()
{
  int32 ptr, str_ptr, strLen;

  get_int_argument(1, ptr);
  get_word(ptr, str_ptr);
  get_word(ptr + 4, strLen);

  string cmdline;
  get_string(str_ptr, cmdline, strLen);

  int32 result(system(cmdline.c_str()));
  set_int_result(result);
}

void
arm_angel::do_heapinfo()
{
  int32 ptr, blockPtr;
  int32 block[4] = { heapBase, heapLimit, stackBase, stackLimit };

  get_int_argument(1, ptr);
  get_word(ptr, blockPtr);

  if (verbose_p)
    cerr << "heapinfo into block @ " << blockPtr << endl;

  for (int i = 0; i < 4; i++)
    {
      if (set_word(blockPtr, block[i]) == false) // failed?
	{
	  set_int_result(-1);
	  set_error_result(newlib::eFault);
	  break;
	}
      blockPtr = blockPtr + 4;
    }
}

void
arm_angel::do_read()
{
  int32 ptr, handle, str_ptr, str_length;

  get_int_argument(1, ptr);
  get_word(ptr, handle);
  get_word(ptr + 4, str_ptr);
  get_word(ptr + 8, str_length);

  size32 len_read;
  int errcode;
  if (! this->read (handle, str_ptr, str_length, len_read, errcode))
    {
      set_host_error_result(errcode);
      // FIXME: what is proper result here?
      set_int_result(str_length);
      return;
    }

  // Angel returns the number of bytes not! read.
  set_int_result(str_length - len_read);
}

void
arm_angel::do_write()
{
  string str;
  int32 ptr, handle, str_ptr, str_length;

  get_int_argument(1, ptr);
  get_word(ptr, handle);
  get_word(ptr + 4, str_ptr);
  get_word(ptr + 8, str_length);

  size32 len_written;
  int errcode;
  if (! this->write (handle, str_ptr, str_length, len_written, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(-1);
      return;
    }

  // Angel returns the number of bytes not! written.
  set_int_result(str_length - len_written);
}

void
arm_angel::do_flen()
{
  int32 ptr, handle;

  get_int_argument(1, ptr);
  get_word(ptr, handle);

  unsigned int size;
  int errcode;
  if (! this->getsize(handle, size, errcode))
    {
      set_host_error_result(errcode);
      set_int_result(-1);
      return;
    }
  set_int_result(size);
}

void
arm_angel::do_close()
{
  int32 ptr, handle;

  get_int_argument(1, ptr);
  get_word(ptr, handle);

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
arm_angel::do_open()
{
  string filename;
  int32 ptr, str_ptr, str_length, open_flags;

  get_int_argument(1, ptr);
  get_word(ptr, str_ptr);
  get_word(ptr + 4, open_flags);
  get_word(ptr + 8, str_length);

  get_string(str_ptr, filename, str_length);

  if (open_flags < 0 || open_flags > 11) 
    {
      set_error_result(newlib::eInval);
      set_int_result(-1);
      return;
    }

  // Check for standard I/O. ":tt" is a magic filename for stdin/stdout.
  if (filename == ":tt")
    {
      switch (open_flags) {
      case 0:
	set_int_result(0);
	break;
      case 4:
	set_int_result(1);
	break;
      default:
	set_error_result(newlib::eInval);
	set_int_result(-1);
	break;
      }
      return;
    }

  int flags;
  switch (open_flags)
    {
    case 0:
      flags = hostops::open_read_only | hostops::open_text;
      break;
    case 1:
      flags = hostops::open_read_only;
      break;
    case 2:
      flags = hostops::open_read_write | hostops::open_text;
      break;
    case 3:
      flags = hostops::open_read_write;
      break;
    case 4:
      flags = hostops::open_write_only | hostops::open_create | hostops::open_trunc | hostops::open_text;
      break;
    case 5:
      flags = hostops::open_write_only | hostops::open_create | hostops::open_trunc;
      break;
    case 6:
      flags = hostops::open_read_write | hostops::open_create | hostops::open_trunc | hostops::open_text;
      break;
    case 7:
      flags = hostops::open_read_write | hostops::open_create | hostops::open_trunc;
      break;
    case 8:
      flags = hostops::open_write_only | hostops::open_create | hostops::open_append | hostops::open_text;
      break;
    case 9:
      flags = hostops::open_write_only | hostops::open_create | hostops::open_append;
      break;
    case 10:
      flags = hostops::open_read_write | hostops::open_create | hostops::open_append | hostops::open_text;
      break;
    case 11:
      flags = hostops::open_read_write | hostops::open_create | hostops::open_append;
      break;
    }

  int result_fd,errcode;

  if ((flags & hostops::open_create) != 0)
    {
      if (! this->open (filename, flags, 0600, result_fd, errcode))
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
