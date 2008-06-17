// gdb.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2005, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef GDB_DEF_H
#define GDB_DEF_H	1

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidcpuutil.h>
#include <sidpinattrutil.h>
#include <sidmiscutil.h>
#include <sidwatchutil.h>
#include <sidso.h>

#include <vector>
#include <cstdio>
#include <map>

using std::vector;
using std::string;
using std::map;
using std::cerr;
using std::endl;
using std::ios;
using std::cout;

using sid::component;
using sid::bus;
using sid::host_int_8;
using sid::host_int_4;
using sid::host_int_2;
using sid::host_int_1;
using sid::big_int_1;
using sid::big_int_2;
using sid::big_int_4;
using sid::big_int_8;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::little_int_8;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::make_attribute;
using sidutil::make_numeric_attribute;
using sidutil::fixed_attribute_map_component;
using sidutil::no_bus_component;
using sidutil::no_accessor_component;
using sidutil::fixed_relation_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::configurable_component;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::input_pin;
using sidutil::cpu_trap_handled;
using sidutil::parse_attribute;
using sidutil::endian;
using sidutil::endian_unknown;
using sidutil::endian_big;
using sidutil::endian_little;
using sidutil::map_watchable_name;
using sidutil::tokenize;

class gdb: public virtual component,
	   public virtual fixed_attribute_map_component,
	   public virtual fixed_pin_map_component,
	   public no_bus_component,
	   public no_accessor_component,
	   public virtual fixed_relation_map_component,
	   public virtual configurable_component
{
public:
  gdb();
  ~gdb() throw();

private:
  friend class callback_pin<gdb>;

  // match cpu for attribute conversion convenience
  typedef host_int_2 dbg_register_number_t;
  
  // initialization connections
  callback_pin<gdb> init_pin;
  void init_handler (host_int_4);
  callback_pin<gdb> deinit_pin;
  void deinit_handler (host_int_4);

  // socket<->gdb connections
  bool connected_p;
  callback_pin<gdb> remote_rx_pin;
  void remote_rx_eof_handler();
  void remote_rx_handler(host_int_4 value);
  output_pin remote_tx_pin;

  // cpu/gloss<->gdb connections
  component* cfgroot;
  component* cpu;
  component* gloss;
  input_pin cpu_trap_code_pin;
  callback_pin<gdb> cpu_trap_ipin;
  output_pin cpu_trap_opin;
  unsigned long last_signal; 
  void cpu_trap_handler (host_int_4 value);
  callback_pin<gdb> gloss_process_signal_pin;  // signal from gloss
  void gloss_signal_handler (host_int_4 value);
  callback_pin<gdb> target_tx_pin; // signal from pin
  void target_tx_handler (host_int_4 value);
  output_pin icache_flush_pin; // signal to cpu

  // cpu<->target system connections
  output_pin yield_pin; // signal to target subsystem
  vector<component*> target_schedulers;
  vector<component*> host_schedulers;
  vector<bool> target_schedulers_enabled;
  vector<bool> host_schedulers_host_time_yielded;
  // turn target subsystem on/off
  output_pin process_signal_pin;  // signal to cfgroot
  output_pin restart_pin; // signal to hw-reset
  void target_power (bool on);

  // This setting allows us to compensate for some Harvardized
  // addressing schemes, where a PC value is annotated with
  // address space identification bits.
  host_int_8 gdb_pc_mask; // 0=disabled

  // hw breakpoint tracking
  typedef map<host_int_8,int> hw_breakpoints_t;
  hw_breakpoints_t hw_breakpoints; // address -> insertion-count
  bool add_hw_breakpoint (host_int_8, host_int_4);
  bool remove_hw_breakpoint (host_int_8, host_int_4);
  bool remove_all_hw_breakpoints ();

  // sw breakpoint tracking
  typedef map<host_int_8,string> sw_breakpoints_t;
  sw_breakpoints_t sw_breakpoints; // address -> memory-image
  bool add_sw_breakpoint (host_int_8, host_int_4);
  bool remove_sw_breakpoint (host_int_8, host_int_4);
  bool remove_all_sw_breakpoints ();

  // hw watchpoint tracking
  typedef map<string,int> hw_watchpoints_t;
  hw_watchpoints_t hw_watchpoints; // watcher name -> insertion-count
  bool add_hw_watchpoint (host_int_8, host_int_4);
  bool remove_hw_watchpoint (host_int_8, host_int_4);
  bool remove_hw_watchpoint (const string &);
  bool remove_all_hw_watchpoints ();

  // pending signal tracking
  typedef map<int,int> pending_signal_counts_t;
  pending_signal_counts_t pending_signal_counts;

  // pending step control tracking
  host_int_8 step_range_start, step_range_end;

  // sid<->gdb target control
  callback_pin<gdb> stop_pin; // special-purpose "interrupt target" pin
  void stop_handler (host_int_4);
  callback_pin<gdb> trapstop_pin; // special-purpose "breakpoint target" pin
  void trapstop_handler (host_int_4);
  callback_pin<gdb> start_pin; // special-purpose "resume target" pin
  void start_handler (host_int_4);

  // settings
  bool exit_on_detach;
  bool trace_gdbserv;
  bool trace_gdbsid;
  void update_trace_flags();
  bool enable_Z_packet; // support z* at all
  bool force_Z_sw_to_hw; // map z0 -> z1
  bool force_Z_hw_to_sw; // map z1 -> z0
  bool fallback_Z_sw_to_hw; // hw, if error during sw breakpoint add attempt
  bool enable_E_packet;
  bool operating_mode_p;

  // gdbserv state
  struct gdbserv* gdbserv;
  struct gdbserv_client* gdbserv_client;

  virtual void configure (const string &config);

public:
  // gdbserv_client<->gdb callback hooks
  void gdbsid_client_write (const unsigned char* ch, unsigned len);
  // gdbserv<->gdb callback hooks
  struct gdbserv_target* gdbsid_target_attach (struct gdbserv *gdbserv);
  void process_rcmd (const char *cmd, int sizeof_cmd);
  void process_get_gen ();
  void process_set_gen ();
  void process_set_args ();
  int process_set_reg (int reg);
  int process_set_regs ();
  void process_get_reg (int reg);
  void process_get_regs ();
  void process_get_exp_regs ();
  void process_get_mem (struct gdbserv_reg *reg_addr, struct gdbserv_reg *reg_len);
  void process_set_mem (struct gdbserv_reg *reg_addr, struct gdbserv_reg *reg_len, int binary);
  void process_set_pc (struct gdbserv_reg *val);
  int process_signal (int sigval);
  void flush_i_cache();
  unsigned long compute_signal (unsigned long sig);
  unsigned long get_trap_number ();
  void supply_expedited_regs ();
  int exit_program (); 
  int break_program ();
  void restart_program ();
  int singlestep_program ();
  int rangestep_program (struct gdbserv_reg *range_start, struct gdbserv_reg *range_end);
  void sigkill_program ();
  int continue_program ();
  int Z_breakpoint_ok_p (unsigned long type, struct gdbserv_reg *addr, struct gdbserv_reg *len);
  int remove_breakpoint (unsigned long type, struct gdbserv_reg *addr, struct gdbserv_reg *len);
  int set_breakpoint (unsigned long type, struct gdbserv_reg *addr, struct gdbserv_reg *len);
  int set_exec_direction (const char* direction);
  void process_detach ();
};



extern "C" struct gdbserv_target* gdbsid_target_attach_hook (struct gdbserv *gdbserv, 
							     void *globalstate);
extern "C" void process_get_gen_hook (struct gdbserv *gdbserv);
extern "C" void process_set_gen_hook (struct gdbserv *gdbserv);
extern "C" void process_set_args_hook (struct gdbserv *gdbserv);
extern "C" int process_set_reg_hook (struct gdbserv *gdbserv, int reg);
extern "C" int process_set_regs_hook (struct gdbserv *gdbserv);
extern "C" void process_get_reg_hook (struct gdbserv *gdbserv, int reg);
extern "C" void process_get_regs_hook (struct gdbserv *gdbserv);
extern "C" void process_get_exp_regs_hook (struct gdbserv *gdbserv);
extern "C" unsigned long get_trap_number_hook (struct gdbserv *gdbserv);
extern "C" void process_get_mem_hook (struct gdbserv *gdbserv,
				      struct gdbserv_reg *reg_addr,
				      struct gdbserv_reg *reg_len);
extern "C" void process_set_mem_hook (struct gdbserv *gdbserv,
				      struct gdbserv_reg *reg_addr,
				      struct gdbserv_reg *reg_len,
				      int binary);
extern "C" void process_set_pc_hook (struct gdbserv *gdbserv, struct gdbserv_reg *val);
extern "C" int process_signal_hook (struct gdbserv *gdbserv, int sig);
extern "C" void flush_i_cache_hook (struct gdbserv *gdbserv );
extern "C" unsigned long compute_signal_hook (struct gdbserv *gdbserv, unsigned long sig);
extern "C" int exit_program_hook (struct gdbserv *gdbserv); 
extern "C" int break_program_hook (struct gdbserv *gdbserv);
extern "C" void restart_program_hook (struct gdbserv *gdbserv);
extern "C" int singlestep_program_hook (struct gdbserv *gdbserv);
extern "C" int rangestep_program_hook (struct gdbserv *gdbserv, 
				       struct gdbserv_reg *val1, 
				       struct gdbserv_reg *val2);
extern "C" void sigkill_program_hook (struct gdbserv *gdbserv);
extern "C" int continue_program_hook (struct gdbserv *gdbserv );
extern "C" int remove_breakpoint_hook (struct gdbserv *gdbserv, unsigned long type,
				       struct gdbserv_reg *addr, struct gdbserv_reg *len);
extern "C" int set_breakpoint_hook (struct gdbserv *gdbserv, unsigned long type,
				    struct gdbserv_reg *addr, struct gdbserv_reg *len);
extern "C" void process_detach_hook (struct gdbserv *gdbserv);

#endif // GDB_DEF_H
