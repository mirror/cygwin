// gloss.h - Basic process emulation plus ROM monitor support.
// -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// The name "gloss" is derived from the "libgloss" library.
// "gloss" is an acronym for: GNU Low-level Operating System Support.
// However, this header [and this directory] provides a base for all such
// components.
//
// Notes:
// - It defaults to the host cin/cout/cerr for target file handles 0/1/2.
//
// TODOs:
// - Add support for one component serving several cpus.
// - Currently uses blocking I/O.

#ifndef GLOSS_H
#define GLOSS_H

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidso.h>

#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidcpuutil.h>

#include "hostops.h"

using std::vector;
using std::string;
using std::map;
using std::cerr;
using std::ios;
using std::endl;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_4;
using sid::host_int_8;
using sid::signed_host_int_4;
using sid::signed_host_int_8;

using sidutil::fixed_attribute_map_component;
using sidutil::fixed_accessor_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::no_bus_component;
using sidutil::fixed_relation_map_component;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::input_pin;


class gloss32: public virtual component,
	       protected fixed_attribute_map_component,
	       protected fixed_accessor_map_component,
	       protected fixed_pin_map_component,
	       protected no_bus_component,
	       protected fixed_relation_map_component
{
public:

  gloss32();
  virtual ~gloss32() throw();

protected:

  // The cpu we're connected to.
  component* cpu;
  // Access to the cpu's memory.
  bus* cpu_memory_bus;
  // The endian of `cpu'.
  sidutil::endian endian;
  void update_endian();

  // Reset component.
  callback_pin<gloss32> reset_pin;
  void reset_pin_handler(host_int_4 ignore);
  // For derived classes to do additional things.
  virtual void reset();

  void setup_fds (int max_fds);

  // streaming/destreaming of state
  virtual string save_state() { return make_attribute(*this); }
  virtual component::status restore_state(const string& state)
  {
    return parse_attribute(state, *this);
  }
  void stream_state (std::ostream& o) const;
  void destream_state (std::istream& i);
  friend std::ostream& operator << (std::ostream& o, const gloss32& it);
  friend std::istream& operator >> (std::istream& i, gloss32& it);

  // Trap invocation and response.
  callback_pin<gloss32> trap_type_ipin;
  output_pin trap_type_opin;
  void trap_pin_handler(host_int_4 trapnum);
  input_pin trap_code_pin;
  // Allow trap handlers to be chained together.
  output_pin trap_type_chain_opin;
  input_pin trap_type_chain_ipin;
  output_pin trap_code_chain_pin;

  // Connected to "main" component to tell it to exit.
  output_pin process_signal_pin;

  // Debug channel communications.
  callback_pin<gloss32> rx_pin;
  void rx_handler(host_int_4 byte);
  vector<host_int_1> rx_buffer;
  output_pin tx_pin;

  // ABI-specifics, for getting syscall arguments and setting results.
  virtual bool get_int_argument(unsigned index, int32& value);
  virtual bool set_int_result(int32 value);
  virtual bool set_error_result(int32 target_errno);
  bool set_host_error_result (int32 host_errno);

  bool get_halfword(address32 address, sid::host_int_2& value);
  bool set_halfword(address32 address, sid::host_int_2 value);

  // Get/set a word in memory, taking into account the cpu's endianness.
  bool get_word(address32 address, int32& value);
  bool set_word(address32 address, int32 value);

  // Read/write a string in memory.
  // Calling get_string with length = 0 indicates that there is no
  // imposed length limit; read from memory until a NUL is encountered.
  bool set_string(address32 address, const string& value);
  bool set_string(address32 address, const char* value, unsigned length);
  bool get_string(address32 address, string& value, unsigned length = 0);

  // Get the value of the cpu's program counter.
  virtual bool get_pc(address32& value);

  // Names of cpu's general registers.
  // All need not be specified, just enough to get syscalls working.
  map<int,string> register_attribute_names;

  // Return boolean indicating if cpu is requesting something we're to handle.
  virtual bool syscall_trap_p();
  // Perform a system call trap.  Do not send trap disposition reply.
  virtual void syscall_trap();
  bool blocked_p; // signal that syscall blocked

  // syscall support
  int32 errnum;
  void do_sys_exit();
  void do_sys_read();
  void do_sys_write();
  void do_sys_open();
  void do_sys_close();
  void do_sys_lseek();
  void do_sys_fstat();
  void do_sys_time();
  void do_sys_gettimeofday();
  void do_sys_times();
  void do_sys_unlink();
  void do_sys_argc();
  void do_sys_argn();
  void do_sys_argnlen();
  virtual void do_nonstandard_target_syscalls(int32 syscall);
  virtual bool target_to_host_open_flags (int open_flags, int& flags);
  virtual int32 target_to_host_syscall (int32 syscall);

  // Handle all faults.  A reasonable default is provided.
  virtual void fault_trap(host_int_4 trap_type, host_int_4 trap_code);

  // For Unix process emulation.
  vector<string> command_line;
  string get_command_line ();
  component::status set_command_line (const string& cmd_line);

  // System calls.

  int exit_code;
  // Size of file descriptor table.
  int max_fds;
  // Open file handles; indexed by fd.
  // The result is the host's file descriptor.
  // Special provision is made to map 0,1,2 to cin,cout,cerr and track
  // when the original 0,1,2 are changed to something else.
  int* fd_table;
  // fd_table manipulation
  int lookup_fd (int target_fd);
  int unused_fd ();
  void alloc_fd (int target_fd, int host_fd);
  void free_fd (int target_fd);
  // Host O/S interface.
  hostops* host_ops;
  // Convert host errno to target errno.
  virtual int host_to_target_errno (int errno_);

  // Result is always boolean indicating success/failure.
  // If failure, `errcode' is set with the host's value for `errno'.
  bool open (string filename, int flags, int& result_fd, int& errcode);
  bool open (string filename, int flags, int mode, int& result_fd, int& errcode);
  bool close (int fd, int& errcode);
  bool read (int fd, address32 addr, size32 len,
	     size32& len_read, int& errcode);
  bool write (int fd, address32 addr, size32 len,
	      size32& len_written, int& errcode);
  bool remove (string filename, int& errcode);
  bool rename (string oldname, string newname, int& errcode);
  bool lseek (int fd, offset32 offset, hostops::seek_type how, size32& result, int& errcode);
  bool getsize (int fd, size32& size, int& errcode);
  bool tmpnam (string& filename, int& errcode);
  bool isatty (int fd, bool& result, int& errcode);

  string syscall_numbering_scheme;
  
  // true -> send various debugging messages to cerr.
  // ??? Would be nice to be able to specify a file.
  bool verbose_p;
};

class gloss64 : public gloss32
{
public:

  gloss64();
  virtual ~gloss64() throw();

protected:

  // ABI-specifics, for getting syscall arguments and setting results.
  virtual bool get_int_argument(unsigned index, int64& value);
  virtual bool set_int_result(int64 value);
  virtual bool set_error_result(int64 value);
  bool set_host_error_result (int32 host_errno);

  // Get/set a word in memory, taking into account the cpu's endianness.
  bool get_word(address64 address, int64& value);
  bool set_word(address64 address, int64 value);

  // Read/write a string in memory.
  // Note that this is a string of bytes, not a nul-terminated string.
  bool get_string(address64 address, string& value, unsigned length);
  bool set_string(address64 address, const string& value);

  // Get the value of the cpu's program counter.
  virtual bool get_pc(address64& value);

  // System calls.

  bool read (int fd, address64 addr, size64 len,
	     size64& len_read, int& errcode);
  bool write (int fd, address64 addr, size64 len,
	      size64& len_written, int& errcode);
  bool lseek (int fd, offset64 offset, hostops::seek_type how, size64& result, int& errcode);
  bool getsize (int fd, size64& size, int& errcode);
};

#endif // GLOSS_H
