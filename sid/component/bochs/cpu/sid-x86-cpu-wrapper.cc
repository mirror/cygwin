//  sid-x86-cpu-wrapper.cc - member function implementations for the sid x86 cpu component. -*- C++ -*-
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

#include "sid-x86-cpu-wrapper.h"

x86_cpu::x86_cpu ()
    : interrupt_pin(this, & x86_cpu::interrupt),
      hold_request_pin(this, & x86_cpu::hold_request),
      enable_a20_pin(this, & x86_cpu::enable_a20),
      in_hardware_mode(false),
      _a20_enabled(true),
      a20_mask(0xffffffff),
      memory_mode("default"),
      blocking_on_syscall(false),
      verbose_p(false),
      io_memory_bus(0)
{
  bx_cpu.init(this, &bx_mem);

  add_pin("interrupt", & this->interrupt_pin);
  add_pin("interrupt-acknowledge", & this->interrupt_acknowledge_pin);
  add_pin("interrupt-ack-response", & this->interrupt_acknowledge_response_pin);

  add_pin("hold-request", & this->hold_request_pin);
  add_pin("hold-acknowledge", & this->hold_acknowledge_pin);

  add_pin("enable-a20", & this->enable_a20_pin);
  add_pin("a20-enabled", & this->a20_enabled_pin);

  add_accessor("io-memory", & this->io_memory_bus);

  // set up registers for use by gloss component.
  // see libgloss/i386/* for calling conventions
  // and exception-sid.cc for handling of int 0x80
  add_watchable_register (string("syscall-arg0"), &bx_cpu.gen_reg[0].erx);
  add_watchable_register (string("syscall-arg1"), &bx_cpu.gen_reg[3].erx);
  add_watchable_register (string("syscall-arg2"), &bx_cpu.gen_reg[1].erx);
  add_watchable_register (string("syscall-arg3"), &bx_cpu.gen_reg[2].erx);
  add_watchable_register (string("syscall-result"), &bx_cpu.gen_reg[0].erx);

  add_watchable_register (string("syscall-trap"), &bx_cpu.gen_reg[0].erx);    
  add_watchable_register (string("syscall-error"), &syscall_error);

  // set up debugging interface
  // there are 16 integer registers
  create_gdb_register_attrs (16, "4;5;8;9", & this->bx_cpu.eip);
  
  add_attribute ("enable-warnings?", & this->warnings_enabled, "setting");
  add_attribute ("hardware-mode?", & this->in_hardware_mode, "setting");
  add_attribute ("memory-mode", & this->memory_mode, "setting");
  add_attribute ("verbose?", & this->verbose_p, "setting");
}

void
x86_cpu::do_syscall()
{
  sid::host_int_4 tempAX = bx_cpu.gen_reg[0].erx;
  sid::host_int_4 tempBX = bx_cpu.gen_reg[3].erx;
  sid::host_int_4 tempCX = bx_cpu.gen_reg[1].erx;
  sid::host_int_4 tempDX = bx_cpu.gen_reg[2].erx;
  
  sidutil::cpu_trap_disposition whatnext = signal_trap(sidutil::cpu_trap_software, bx_cpu.gen_reg[0].erx);
  
  switch (whatnext)
    {
    case sidutil::cpu_trap_unhandled:
      cerr << "hw-cpu-x86: cpu syscall trap unhandled" << endl;
      this->blocking_on_syscall = false;
      return;
    case sidutil::cpu_trap_reissue:
      bx_cpu.gen_reg[0].erx = tempAX;
      bx_cpu.gen_reg[3].erx = tempBX;
      bx_cpu.gen_reg[1].erx = tempCX;
      bx_cpu.gen_reg[2].erx = tempDX;
      this->blocking_on_syscall = true;
      return;
    case sidutil::cpu_trap_skip:
      /* fall-through */
    case sidutil::cpu_trap_handled:
      this->blocking_on_syscall = false;
      return;
    default:
      abort ();
    }
  this->yield();
  throw sidutil::cpu_exception();
}

void
x86_cpu::do_breakpoint()
{
  sidutil::cpu_trap_disposition whatnext = signal_trap(sidutil::cpu_trap_breakpoint, 0);
  
  switch (whatnext)
    {
    case sidutil::cpu_trap_unhandled:
      cerr << "hw-cpu-x86: cpu breakpoint trap unhandled" << endl;
      break;
      
    case sidutil::cpu_trap_skip:
    case sidutil::cpu_trap_handled:
    case sidutil::cpu_trap_reissue:
      break;
      
    default:
      abort();
    }
  this->yield();
  throw sidutil::cpu_exception();
}

void
x86_cpu::step_insns ()
{
  try
    {
      if (!this->blocking_on_syscall)
          bx_cpu.cpu_loop(1);
      else
        do_syscall();
    }
  catch (sidutil::cpu_exception& t)
    {
      this->yield();
    }
  
  if (this->enable_step_trap_p) 
    this->signal_trap (sidutil::cpu_trap_stepped);
}

void
x86_cpu::reset ()
{
  bx_cpu.reset(BX_RESET_HARDWARE);

  if (!in_hardware_mode)
    enter_protected_mode();

}

void
x86_cpu::flush_icache ()
{
  bx_cpu.invalidate_prefetch_q();
}

void
x86_cpu::set_pc (sid::host_int_4 value)
{
  // FIXME: this should check if we're using the extended (32-bit)
  // instruction pointer or the 16-bit one
  bx_cpu.eip = value - bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.base;
}

string
x86_cpu::dbg_get_reg(unsigned int reg)
{
  string attr;
  sid::host_int_4 val;
  val = bx_cpu.dbg_get_reg(reg + 10);
  
  // Change to "target endian".
  sid::little_int_4 v = val;
  for (unsigned i = 0; i < 4; i++)
    attr += v.read_byte (i);
  
  if (verbose_p)
    cerr << "dbg_get_reg: reg = " << reg << endl;
  
  return attr;
}

sid::component::status
x86_cpu::dbg_set_reg(unsigned int reg, const string &attr)
{
  // change from "target endian"
  sid::little_int_4 v;
  for (unsigned i = 0; i < 4; i++)
    v.write_byte (i, attr[i]);
  sid::host_int_4 val = v;
  
  if (verbose_p)
    {
      cerr << "dbg_set_reg: reg = " << reg;
      fprintf(stderr, " val = %p\n", val);
    }
  
  if(bx_cpu.dbg_set_reg(reg + 10, val))
    return sid::component::ok;
  else
    return sid::component::bad_value;
}

void
x86_cpu::interrupt(host_int_4 val)
{
  bx_cpu.set_INTR(val);
}

void
x86_cpu::hold_request(host_int_4 val)
{
  bx_cpu.set_HRQ(val);
}

host_int_8
x86_cpu::now(void)
{
  return sched_query.now();
}

void
x86_cpu::enable_a20(host_int_4 val)
{
  if (val)
    {
      _a20_enabled = true;
      a20_mask   = 0xffffffff;
    }
  else
    {
      _a20_enabled = false;
      a20_mask   = 0xffefffff;
    }
}

host_int_4
x86_cpu::a20_enabled(void)
{
  if(_a20_enabled)
    return 1;
  else
    return 0;
}

bool
x86_cpu::hardware_mode(void)
{
  return in_hardware_mode;
}

void
x86_cpu::drive_interrupt_acknowledge_pin(void)
{
  interrupt_acknowledge_pin.drive(1);
}

host_int_1
x86_cpu::interrupt_acknowledged(void)
{
  return interrupt_acknowledge_response_pin.sense();
}

void
x86_cpu::drive_hold_acknowledge_pin(void)
{
  hold_acknowledge_pin.drive(1);
}

little_int_1
x86_cpu::read_io_memory_1 (host_int_4 addr)
{
  little_int_1 val;
  bus::status status;

  status = io_memory_bus->read(addr, val);

  if (status != bus::ok)
    {
      cerr << "[IOMEM ] operation: read_1" << endl;
      cerr << "[IOMEM ] addr: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] val: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] status: " << (status == bus::misaligned ? "misaligned" :
                                     (status == bus::unmapped ? "unmapped" : "unpermitted")) << endl;
      // FIXME: range check needed?
      if (addr >= 0x02e0 && addr <= 0x02ef)
        return 0;
      else
        return 0xff;
    }
  else
    {
      return val;
    }
}

void
x86_cpu::write_io_memory_1 (host_int_4 addr, little_int_1 value)
{
  bus::status status;

  status = io_memory_bus->write(addr, value);

  if (status != bus::ok)
    {
      cerr << "[IOMEM ] operation: write_1" << endl;
      cerr << "[IOMEM ] addr: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] val: " << setbase(16) << value << setbase(10) << endl;
      cerr << "[IOMEM ] status: " << (status == bus::misaligned ? "misaligned" :
                                      (status == bus::unmapped ? "unmapped" : "unpermitted")) << endl;
    }
}

little_int_2
x86_cpu::read_io_memory_2 (host_int_4 addr)
{
  little_int_2 val;
  bus::status status;

  status = io_memory_bus->read(addr, val);

  if (status != bus::ok)
    {
      cerr << "[IOMEM ] operation: read_2" << endl;
      cerr << "[IOMEM ] addr: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] val: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] status: " << (status == bus::misaligned ? "misaligned" :
                                     (status == bus::unmapped ? "unmapped" : "unpermitted")) << endl;
      // FIXME: range check needed?
      if (addr >= 0x02e0 && addr <= 0x02ef)
        return 0;
      else
        return 0xffff;
    }
  else
    {
      return val;
    }
}

void
x86_cpu::write_io_memory_2 (host_int_4 addr, little_int_2 value)
{
  bus::status status;
  
  status = io_memory_bus->write(addr, value);
  
  if (status != bus::ok)
    {
      cerr << "[IOMEM ] operation: write_2" << endl;
      cerr << "[IOMEM ] addr: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] val: " << setbase(16) << value << setbase(10) << endl;
      cerr << "[IOMEM ] status: " << (status == bus::misaligned ? "misaligned" :
                                      (status == bus::unmapped ? "unmapped" : "unpermitted")) << endl;
    }
}

little_int_4
x86_cpu::read_io_memory_4 (host_int_4 addr)
{
  little_int_4 val;
  bus::status status;

  status = io_memory_bus->read(addr, val);

  if (status != bus::ok)
    {
      cerr << "[IOMEM ] operation: read_4" << endl;
      cerr << "[IOMEM ] addr: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] val: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] status: " << (status == bus::misaligned ? "misaligned" :
                                     (status == bus::unmapped ? "unmapped" : "unpermitted")) << endl;
      // FIXME: range check needed?
      if (addr >= 0x02e0 && addr <= 0x02ef)
        return 0;
      else
        return 0xffffffff;
    }
  else
    {
      return val;
    }
}

void
x86_cpu::write_io_memory_4 (host_int_4 addr, little_int_4 value)
{
  bus::status status;
  
  status = io_memory_bus->write(addr, value);
  
  if (status != bus::ok)
    {
      cerr << "[IOMEM ] operation: write_4" << endl;
      cerr << "[IOMEM ] addr: " << setbase(16) << addr << setbase(10) << endl;
      cerr << "[IOMEM ] val: " << setbase(16) << value << setbase(10) << endl;
      cerr << "[IOMEM ] status: " << (status == bus::misaligned ? "misaligned" :
                                      (status == bus::unmapped ? "unmapped" : "unpermitted")) << endl;
    }
}
