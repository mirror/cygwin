//  x86.h - x86_cpu class declaration for the x86 sid component. -*- C++ -*-
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
#include "sidcomp.h"
#include "sidcpuutil.h"
#include "bochs.h"
#include "memory-sid.h"
#include "cpu-sid.h"

#define X86_CPU_DEBUG 0

class x86_cpu : public sidutil::basic_bi_endian_cpu {
    friend void sid_mem_c::read_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);
    friend void sid_mem_c::write_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);
  public:
    sid_cpu_c bx_cpu;
    sid_mem_c bx_mem;

    sid::host_int_4 syscall_error;

    bool warnings_enabled;
    bool blocking_on_syscall;
    bool verbose_p;
    
    x86_cpu ();

    void do_syscall();
    void do_breakpoint();

    void step_insns ();
    void reset ();
    void flush_icache ();
    void set_pc (sid::host_int_4 value);
    string dbg_get_reg(unsigned int);
    sid::component::status dbg_set_reg(unsigned int, const string &);
  private:
    string memory_mode;
    
    void enter_protected_mode();
    
};

#endif // __X86_H__
