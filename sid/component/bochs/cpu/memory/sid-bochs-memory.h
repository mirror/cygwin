//  sid-bochs-memory.h - declaration of the sid_bx_mem_c class. -*- C++ -*-
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

#ifndef __SID_BX_MEMORY_H__
#define __SID_BX_MEMORY_H__

class x86_cpu;

// This class takes bochs calls to read_physical and write_physical,
// and calls the corresponding sid cpu read_data_memory and
// write_data_memory functions.
class sid_bx_mem_c : public logfunctions
{
public:
  void init(x86_cpu *x86_cpu_comp);
  void read_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);
  void write_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data);

protected:
  x86_cpu *x86_cpu_component;
};
#endif // __SID_BX_MEMORY_H__
