//  exception-sid.cc - override the bochs cpu interrupt member function. -*- C++ -*-
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



#define NEED_CPU_REG_SHORTCUTS 1
#include "bochs.h"
#define LOG_THIS BX_CPU_THIS_PTR

#include "x86.h"

  void
sid_cpu_c::interrupt(Bit8u vector, Boolean is_INT, Boolean is_error_code,
                    Bit16u error_code)
{
    if (vector == 0x80)
    {
        int temp = this->gen_reg[0].erx;
        this->sid_cpu->do_syscall();
#if X86_CPU_DEBUG
        printf("Syscall number: %d was executed with the following return value: %d\n", temp, this->gen_reg[0].erx);
#endif
    }
    else if (vector == 0x03)
    {
        // INT3 was encountered -- trap to debugger
        this->sid_cpu->do_breakpoint();
    }
    else
    {
        BX_CPU_C::interrupt(vector, is_INT, is_error_code, error_code);
    }
}
