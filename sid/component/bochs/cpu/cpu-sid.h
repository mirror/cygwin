//  cpu-sid.h - declaration of the sid_cpu_c class. -*- C++ -*-
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

#ifndef __CPU_SID_H__
#define __CPU_SID_H__

// The CHECK_MAX_INSTRUCTIONS macro allows cpu_loop to execute a few
// instructions and then return so that the other processors have a chance to
// run.  This is used only when simulating multiple processors.
// 
// If maximum instructions have been executed, return.  A count less
// than zero means run forever.
#define CHECK_MAX_INSTRUCTIONS(count) \
  if (count >= 0) {                   \
    count--; if (count == 0) return;  \
  }

#define NEED_CPU_REG_SHORTCUTS 1

#include "cpu.h"

class x86_cpu;

class sid_cpu_c : public BX_CPU_C {
  public:
    x86_cpu *sid_cpu;
    
    void init (sid_mem_c *addrspace);
    void interrupt(Bit8u vector, Boolean is_INT, Boolean is_error_code,
                   Bit16u error_code);
    void set_INTR(Boolean value);
    void cpu_loop(Bit32s max_instr_count);
    void prefetch(void);
    void revalidate_prefetch_q(void);

    Bit32u dbg_get_eflags(void);
    Bit32u dbg_get_reg(unsigned reg);
    Boolean dbg_set_reg(unsigned reg, Bit32u val);
    void JCC_Jd(BxInstruction_t *i);
    void INT3(BxInstruction_t *i);
    void INT_Ib(BxInstruction_t *i);
    unsigned FetchDecode(Bit8u *iptr, BxInstruction_t *instruction,
                         unsigned remain, Boolean is_32);
};

typedef void (sid_cpu_c::*SidExecutePtr_t)(BxInstruction_t *);

#  define BX_CPU_CALL_METHOD_FROM_SID(func, args) \
    (this->*((SidExecutePtr_t) (func))) args

extern sid_cpu_c bx_cpu;

#endif // __CPU_SID_H__
