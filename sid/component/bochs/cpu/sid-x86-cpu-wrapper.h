//  sid-x86-cpu-wrapper.h - class declaration for the sid x86 cpu component. -*- C++ -*-
//
//  Copyright (C) 2001 Red Hat.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

#ifndef __X86_H__
#define __X86_H__ 1
#include <sidcomp.h>
#include <sidcpuutil.h>

#include "bochs.h"
#include "sid-bochs-memory.h"
#include "cpu.h"

#define X86_CPU_DEBUG 0

using sid::component;
using sid::host_int_8;
using sid::host_int_4;
using sid::host_int_1;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::bus;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::input_pin;

class x86_cpu : public sidutil::basic_bi_endian_cpu
{
  friend void BX_CPU_C::INSB_YbDX(BxInstruction_t *i);
  friend void BX_CPU_C::INSW_YvDX(BxInstruction_t *i);
  friend void BX_CPU_C::OUTSB_DXXb(BxInstruction_t *i);
  friend void BX_CPU_C::OUTSW_DXXv(BxInstruction_t *i);
  friend Bit32u BX_CPU_C::inp32(Bit16u addr);
  friend Bit16u BX_CPU_C::inp16(Bit16u addr);
  friend Bit8u BX_CPU_C::inp8(Bit16u addr);
  friend void BX_CPU_C::outp32(Bit16u addr, Bit32u value);
  friend void BX_CPU_C::outp16(Bit16u addr, Bit16u value);
  friend void BX_CPU_C::outp8(Bit16u addr, Bit8u value);

  friend void sid_bx_mem_c::read_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);
  friend void sid_bx_mem_c::write_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);

public:
  x86_cpu ();
  ~x86_cpu () throw () {}

  void do_syscall();
  void do_breakpoint();
  
  void step_insns ();
  void reset ();
  void flush_icache ();
  void set_pc (sid::host_int_4 value);
  string dbg_get_reg(unsigned int);
  component::status dbg_set_reg(unsigned int, const string &);

  void interrupt(host_int_4 val);
  void hold_request(host_int_4 val);
  void enable_a20(host_int_4 val);
  host_int_4 a20_enabled(void);

  bool hardware_mode(void);

  void drive_hold_acknowledge_pin(void);

  void drive_interrupt_acknowledge_pin(void);
  host_int_1 interrupt_acknowledged(void);

  host_int_8 now(void);

  host_int_4 a20_mask;
protected:
  bx_cpu_c bx_cpu;
  sid_bx_mem_c bx_mem;
  
  host_int_4 syscall_error;
  
  bool warnings_enabled;
  bool blocking_on_syscall;
  bool verbose_p;

  callback_pin<x86_cpu> interrupt_pin;
  output_pin interrupt_acknowledge_pin;
  input_pin interrupt_acknowledge_response_pin;

  output_pin hold_acknowledge_pin;

  callback_pin<x86_cpu> hold_request_pin;

  callback_pin<x86_cpu> enable_a20_pin;
  output_pin a20_enabled_pin;

  little_int_1 read_io_memory_1 (host_int_4 addr);
  void write_io_memory_1 (host_int_4 addr, little_int_1 value);

  little_int_2 read_io_memory_2 (host_int_4 addr);
  void write_io_memory_2 (host_int_4 addr, little_int_2 value);

  little_int_4 read_io_memory_4 (host_int_4 addr);
  void write_io_memory_4 (host_int_4 addr, little_int_4 value);

  bus *io_memory_bus;

  bool in_hardware_mode;
  bool _a20_enabled;

  string memory_mode;

  void enter_protected_mode();
};
#endif // __X86_H__
