//  sid-bochs-memory.cc - route bochs memory calls to sid cpu component. -*- C++ -*-
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

#include "bochs.h"
#include "sid-x86-cpu-wrapper.h"
#define LOG_THIS this->

void
sid_bx_mem_c::init(x86_cpu *x86_cpu_comp)
{
  x86_cpu_component = x86_cpu_comp;
}

void
sid_bx_mem_c::write_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data)
{
  Bit32u a20addr;

  a20addr = A20ADDR(addr);

  try
    {
      switch(len)
        {
        case 4:
          {
            Bit32u data32 = * ((Bit32u *) data);
            x86_cpu_component->write_data_memory_4 (cpu->eip, a20addr, data32);
            break;
          }
        case 2:
          {
            Bit16u data16 = * ((Bit16u *) data);
            x86_cpu_component->write_data_memory_2 (cpu->eip, a20addr, data16);
            break;
          }
        case 1:
          {
            Bit8u data8 =  * ((Bit8u *) data);
            x86_cpu_component->write_data_memory_1 (cpu->eip, a20addr, data8);
            break;
          }
        default:
          {
            Bit8u data8;
            Bit8u *data_ptr = (Bit8u *) data;
            
            for (unsigned i = 0; i < len; i++)
              {
                data8 = * data_ptr;
                x86_cpu_component->write_data_memory_1 (cpu->eip, a20addr, data8);
                data_ptr++;
                addr++;
                a20addr = A20ADDR(addr);
              }
            break;
          }
        }
    }
  catch (sidutil::cpu_memory_fault e)
    {
      cerr << "[MEM ] caught cpu_memory_fault exeception" << endl;
      cerr << "[MEM ] pc = " << setbase(16) << e.pc << endl;
      cerr << "[MEM ] addr = " << e.address << endl;
      cerr << "[MEM ] status: " << (e.status == sid::bus::ok ? "ok" :
                                    (e.status == sid::bus::misaligned ? "misaligned" :
                                     (e.status == sid::bus::unmapped ? "unmapped" : "unpermitted"))) << endl;
      
      cerr << "[MEM ] operation: " << e.operation << setbase(10) << endl;
      BX_PANIC(("sid_bx_mem_c::write_physical: error\n"));
    }
}

void
sid_bx_mem_c::read_physical(BX_CPU_C *cpu, Bit32u addr, unsigned len, void *data)
{

  Bit32u a20addr;

  a20addr = A20ADDR(addr);

  try
    {
      switch (len)
        {
        case 4:
          * ((Bit32u *) data) = x86_cpu_component->read_data_memory_4 (cpu->eip, a20addr);
          break;
        case 2:
          * ((Bit16u *) data) = x86_cpu_component->read_data_memory_2 (cpu->eip, a20addr);
          break;
        case 1:
          * ((Bit8u *) data) = x86_cpu_component->read_data_memory_1 (cpu->eip, a20addr);
          break;
        default:
          Bit8u data8;
          Bit8u * data_ptr = (Bit8u *) data;
          
          for (unsigned i = 0; i < len; i++)
            {
              * data_ptr = x86_cpu_component->read_data_memory_1 (cpu->eip, a20addr);
              data_ptr++;
              addr++;
              a20addr = A20ADDR(addr);
            }
          break;          
        }
    }
  catch (sidutil::cpu_memory_fault e)
    {
      cerr << "[MEM ] caught cpu_memory_fault exeception" << endl;
      cerr << "[MEM ] pc = " << setbase(16) << e.pc << endl;
      cerr << "[MEM ] addr = " << e.address << endl;
      cerr << "[MEM ] status: " << (e.status == sid::bus::ok ? "ok" :
                                    (e.status == sid::bus::misaligned ? "misaligned" :
                                     (e.status == sid::bus::unmapped ? "unmapped" : "unpermitted"))) << endl;
      
      cerr << "[MEM ] operation: " << e.operation << setbase(10) << endl;
      BX_PANIC(("sid_bx_mem_c::read_physical: error\n"));
    }
}
