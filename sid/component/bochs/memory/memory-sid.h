//  memory-sid.h - declaration of the sid_mem_c class. -*- C++ -*-
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

#ifndef __MEMORY_SID_H__
#define __MEMORY_SID_H__

#include "memory.h"

class x86_cpu;

class sid_mem_c : public BX_MEM_C {

public:
    x86_cpu *sid_cpu;
    
    void read_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);
    void write_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);
};

extern sid_mem_c bx_mem;

#endif // __MEMORY_SID_H__
