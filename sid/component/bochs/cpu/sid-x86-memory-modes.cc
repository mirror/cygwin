//  sid-x86-memory-modes.cc - set up protected mode. -*- C++ -*-
//
//  Copyright (C) 2001 Red Hat.
//
//  Copyright (C) 2001  MandrakeSoft S.A.
//
//    MandrakeSoft S.A.
//    43, rue d'Aboukir
//    75002 Paris - France
//    http://www.linux-mandrake.com/
//    http://www.mandrakesoft.com/
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

void x86_cpu::enter_protected_mode()
{
  if (memory_mode == "default")
  {
    // This mode sets all segment bases to 0x0, and sets all
    //   limits to 0xfffff
    // create a global descriptor table in memory:
    // null descriptor:
    for(int i = 0; i < 16; i += 4)
      write_data_memory_4(0x0, i, 0x0);
    
    // CS descriptor:
    write_data_memory_4(0x0, 0x0010, 0xffff0000);
    write_data_memory_4(0x0, 0x0014, 0x009b4f00);
    
    // DS descriptor:
    write_data_memory_4(0x0, 0x0018, 0xffff0000);
    write_data_memory_4(0x0, 0x001c, 0x00934f00);

        // CS (Code Segment) selector and descriptor in bochs representation:
    bx_cpu.sregs[BX_SEG_REG_CS].selector.value =     0x0010;
#if BX_CPU_LEVEL >= 2
    bx_cpu.sregs[BX_SEG_REG_CS].selector.index =     0x0002;
    bx_cpu.sregs[BX_SEG_REG_CS].selector.ti = 0;
    bx_cpu.sregs[BX_SEG_REG_CS].selector.rpl = 0;
    
    bx_cpu.sregs[BX_SEG_REG_CS].cache.valid =     1;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.p = 1;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.dpl = 0;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.segment = 1; /* data/code segment */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.type = 3; /* read/write access */
    
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.executable   = 1; /* data/stack segment */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.c_ed         = 0; /* normal expand up */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.r_w          = 1; /* writeable */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.a            = 1; /* accessed */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.base         = 0x00000000;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.limit        =     0xfffff;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.limit_scaled =     0xfffff;
#endif
#if BX_CPU_LEVEL >= 3
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.g   = 0; /* byte granular */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.d_b = 1; /* 32bit default size */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.avl = 0;
#endif

        // DS (Data Segment) selector and descriptor in bochs representation:
    bx_cpu.sregs[BX_SEG_REG_DS].selector.value =     0x0018;
#if BX_CPU_LEVEL >= 2
    bx_cpu.sregs[BX_SEG_REG_DS].selector.index =     0x0003;
    bx_cpu.sregs[BX_SEG_REG_DS].selector.ti = 0;
    bx_cpu.sregs[BX_SEG_REG_DS].selector.rpl = 0;
    
    bx_cpu.sregs[BX_SEG_REG_DS].cache.valid =     1;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.p = 1;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.dpl = 0;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.segment = 1; /* data/code segment */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.type = 3; /* read/write access */
    
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.executable   = 0; /* data/stack segment */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.c_ed         = 0; /* normal expand up */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.r_w          = 1; /* writeable */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.a            = 1; /* accessed */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.base         = 0x00000000;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.limit        =     0xfffff; // 2000
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.limit_scaled =     0xfffff;
#endif
#if BX_CPU_LEVEL >= 3
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.g   = 0; /* byte granular */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.d_b = 1; /* 32bit default size */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.avl = 0;
#endif

      /* ES (Extra Segment) and descriptor cache */
  bx_cpu.sregs[BX_SEG_REG_ES].selector.value =     0x0018;
#if BX_CPU_LEVEL >= 2
  bx_cpu.sregs[BX_SEG_REG_ES].selector.index =     0x0003;
  bx_cpu.sregs[BX_SEG_REG_ES].selector.ti = 0;
  bx_cpu.sregs[BX_SEG_REG_ES].selector.rpl = 0;

  bx_cpu.sregs[BX_SEG_REG_ES].cache.valid =     1;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.p = 1;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.dpl = 0;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.segment = 1; /* data/code segment */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.type = 3; /* read/write access */

  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.executable   = 0; /* data/stack segment */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.c_ed         = 0; /* normal expand up */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.r_w          = 1; /* writeable */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.a            = 1; /* accessed */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.base         = 0x00000000;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.limit        =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.limit_scaled =     0xfffff;
#endif
#if BX_CPU_LEVEL >= 3
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.g   = 0; /* byte granular */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.d_b = 1; /* 32bit default size */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.avl = 0;
#endif

    /* FS and descriptor cache */
#if BX_CPU_LEVEL >= 3
  bx_cpu.sregs[BX_SEG_REG_FS].selector.value =     0x0018;
  bx_cpu.sregs[BX_SEG_REG_FS].selector.index =     0x0003;
  bx_cpu.sregs[BX_SEG_REG_FS].selector.ti = 0;
  bx_cpu.sregs[BX_SEG_REG_FS].selector.rpl = 0;

  bx_cpu.sregs[BX_SEG_REG_FS].cache.valid =     1;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.p = 1;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.dpl = 0;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.segment = 1; /* data/code segment */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.type = 3; /* read/write access */

  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.executable   = 0; /* data/stack segment */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.c_ed         = 0; /* normal expand up */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.r_w          = 1; /* writeable */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.a            = 1; /* accessed */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.base         = 0x00000000;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.limit        =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.limit_scaled =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.g   = 0; /* byte granular */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.d_b = 1; /* 32bit default size */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.avl = 0;
#endif


  /* GS and descriptor cache */
#if BX_CPU_LEVEL >= 3
  bx_cpu.sregs[BX_SEG_REG_GS].selector.value =     0x0018;
  bx_cpu.sregs[BX_SEG_REG_GS].selector.index =     0x0003;
  bx_cpu.sregs[BX_SEG_REG_GS].selector.ti = 0;
  bx_cpu.sregs[BX_SEG_REG_GS].selector.rpl = 0;

  bx_cpu.sregs[BX_SEG_REG_GS].cache.valid =     1;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.p = 1;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.dpl = 0;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.segment = 1; /* data/code segment */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.type = 3; /* read/write access */

  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.executable   = 0; /* data/stack segment */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.c_ed         = 0; /* normal expand up */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.r_w          = 1; /* writeable */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.a            = 1; /* accessed */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.base         = 0x00000000;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.limit        =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.limit_scaled =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.g   = 0; /* byte granular */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.d_b = 1; /* 32bit default size */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.avl = 0;
#endif

      /* SS (Stack Segment) and descriptor cache */
    bx_cpu.sregs[BX_SEG_REG_SS].selector.value =     0x0018;
#if BX_CPU_LEVEL >= 2
    bx_cpu.sregs[BX_SEG_REG_SS].selector.index =     0x0003;
    bx_cpu.sregs[BX_SEG_REG_SS].selector.ti = 0;
    bx_cpu.sregs[BX_SEG_REG_SS].selector.rpl = 0;
    
    bx_cpu.sregs[BX_SEG_REG_SS].cache.valid =     1;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.p = 1;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.dpl = 0;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.segment = 1; /* data/code segment */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.type = 3; /* read/write access */
    
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.executable   = 0; /* data/stack segment */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.c_ed         = 0; /* normal expand up */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.r_w          = 1; /* writeable */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.a            = 1; /* accessed */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.base         = 0x00000000;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.limit        =     0xfffff;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.limit_scaled =     0xfffff;
#endif
#if BX_CPU_LEVEL >= 3
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.g   = 0; /* byte granular */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.d_b = 1; /* 32bit default size */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.avl = 0;
#endif

        /* GDTR (Global Descriptor Table Register) */
#if BX_CPU_LEVEL >= 2
    bx_cpu.gdtr.base         = 0x00000000;  
    bx_cpu.gdtr.limit        =     0x001f;  
#endif
        // set PE bit in CR0 so that protected mode is enabled
    bx_cpu.SetCR0(0x01);

  }
  else if (memory_mode == "cygmon")
  {
    // support for initial cygmon memory layout

    // this section simulates the Cygmon rom monitor startup code 
    
    // create a global descriptor table in memory:
    // null descriptor:
    for(int i = 0; i < 16; i += 4)
      write_data_memory_4(0x0, i, 0x0);

       // CS descriptor:
    write_data_memory_4(0x0, 0x10, 0xffff0000);
    write_data_memory_4(0x0, 0x14, 0x009bcf00);

        // DS descriptor:
    write_data_memory_4(0x0, 0x18, 0xffff0000);
    write_data_memory_4(0x0, 0x1c, 0x0093cf00);

    // CS (Code Segment) selector and descriptor in bochs representation:
    bx_cpu.sregs[BX_SEG_REG_CS].selector.value =     0x0010;
#if BX_CPU_LEVEL >= 2
    bx_cpu.sregs[BX_SEG_REG_CS].selector.index =     0x0002;
    bx_cpu.sregs[BX_SEG_REG_CS].selector.ti = 0;
    bx_cpu.sregs[BX_SEG_REG_CS].selector.rpl = 0;
    
    bx_cpu.sregs[BX_SEG_REG_CS].cache.valid =     1;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.p = 1;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.dpl = 0;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.segment = 1; /* data/code segment */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.type = 3; /* read/write access */
    
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.executable   = 1; /* data/stack segment */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.c_ed         = 0; /* normal expand up */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.r_w          = 1; /* writeable */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.a            = 1; /* accessed */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.base         = 0x00000000;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.limit        =     0xfffff;
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.limit_scaled =     0xffffffff;
#endif
#if BX_CPU_LEVEL >= 3
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.g   = 1; /* 4Kb granular */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.d_b = 1; /* 32bit default size */
    bx_cpu.sregs[BX_SEG_REG_CS].cache.u.segment.avl = 0;
#endif

        // DS (Data Segment) selector and descriptor in bochs representation:
    bx_cpu.sregs[BX_SEG_REG_DS].selector.value =     0x0018;
#if BX_CPU_LEVEL >= 2
    bx_cpu.sregs[BX_SEG_REG_DS].selector.index =     0x0003;
    bx_cpu.sregs[BX_SEG_REG_DS].selector.ti = 0;
    bx_cpu.sregs[BX_SEG_REG_DS].selector.rpl = 0;
    
    bx_cpu.sregs[BX_SEG_REG_DS].cache.valid =     1;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.p = 1;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.dpl = 0;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.segment = 1; /* data/code segment */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.type = 3; /* read/write access */
    
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.executable   = 0; /* data/stack segment */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.c_ed         = 0; /* normal expand up */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.r_w          = 1; /* writeable */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.a            = 1; /* accessed */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.base         = 0x00000000;
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.limit        =     0xfffff; // 2000
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.limit_scaled =     0xffffffff;
#endif
#if BX_CPU_LEVEL >= 3
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.g   = 1; /* 4Kb granular */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.d_b = 1; /* 32bit default size */
    bx_cpu.sregs[BX_SEG_REG_DS].cache.u.segment.avl = 0;
#endif

      /* ES (Extra Segment) and descriptor cache */
  bx_cpu.sregs[BX_SEG_REG_ES].selector.value =     0x0018;
#if BX_CPU_LEVEL >= 2
  bx_cpu.sregs[BX_SEG_REG_ES].selector.index =     0x0003;
  bx_cpu.sregs[BX_SEG_REG_ES].selector.ti = 0;
  bx_cpu.sregs[BX_SEG_REG_ES].selector.rpl = 0;

  bx_cpu.sregs[BX_SEG_REG_ES].cache.valid =     1;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.p = 1;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.dpl = 0;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.segment = 1; /* data/code segment */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.type = 3; /* read/write access */

  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.executable   = 0; /* data/stack segment */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.c_ed         = 0; /* normal expand up */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.r_w          = 1; /* writeable */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.a            = 1; /* accessed */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.base         = 0x00000000;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.limit        =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.limit_scaled =     0xffffffff;
#endif
#if BX_CPU_LEVEL >= 3
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.g   = 1; /* 4Kb granular */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.d_b = 1; /* 32bit default size */
  bx_cpu.sregs[BX_SEG_REG_ES].cache.u.segment.avl = 0;
#endif

    /* FS and descriptor cache */
#if BX_CPU_LEVEL >= 3
  bx_cpu.sregs[BX_SEG_REG_FS].selector.value =     0x0018;
  bx_cpu.sregs[BX_SEG_REG_FS].selector.index =     0x0003;
  bx_cpu.sregs[BX_SEG_REG_FS].selector.ti = 0;
  bx_cpu.sregs[BX_SEG_REG_FS].selector.rpl = 0;

  bx_cpu.sregs[BX_SEG_REG_FS].cache.valid =     1;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.p = 1;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.dpl = 0;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.segment = 1; /* data/code segment */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.type = 3; /* read/write access */

  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.executable   = 0; /* data/stack segment */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.c_ed         = 0; /* normal expand up */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.r_w          = 1; /* writeable */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.a            = 1; /* accessed */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.base         = 0x00000000;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.limit        =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.limit_scaled =     0xffffffff;
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.g   = 1; /* 4Kb granular */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.d_b = 1; /* 32bit default size */
  bx_cpu.sregs[BX_SEG_REG_FS].cache.u.segment.avl = 0;
#endif


  /* GS and descriptor cache */
#if BX_CPU_LEVEL >= 3
  bx_cpu.sregs[BX_SEG_REG_GS].selector.value =     0x0018;
  bx_cpu.sregs[BX_SEG_REG_GS].selector.index =     0x0003;
  bx_cpu.sregs[BX_SEG_REG_GS].selector.ti = 0;
  bx_cpu.sregs[BX_SEG_REG_GS].selector.rpl = 0;

  bx_cpu.sregs[BX_SEG_REG_GS].cache.valid =     1;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.p = 1;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.dpl = 0;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.segment = 1; /* data/code segment */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.type = 3; /* read/write access */

  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.executable   = 0; /* data/stack segment */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.c_ed         = 0; /* normal expand up */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.r_w          = 1; /* writeable */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.a            = 1; /* accessed */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.base         = 0x00000000;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.limit        =     0xfffff;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.limit_scaled =     0xffffffff;
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.g   = 1; /* 4Kb granular */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.d_b = 1; /* 32bit default size */
  bx_cpu.sregs[BX_SEG_REG_GS].cache.u.segment.avl = 0;
#endif

      /* SS (Stack Segment) and descriptor cache */
    bx_cpu.sregs[BX_SEG_REG_SS].selector.value =     0x0018;
#if BX_CPU_LEVEL >= 2
    bx_cpu.sregs[BX_SEG_REG_SS].selector.index =     0x0003;
    bx_cpu.sregs[BX_SEG_REG_SS].selector.ti = 0;
    bx_cpu.sregs[BX_SEG_REG_SS].selector.rpl = 0;
    
    bx_cpu.sregs[BX_SEG_REG_SS].cache.valid =     1;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.p = 1;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.dpl = 0;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.segment = 1; /* data/code segment */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.type = 3; /* read/write access */
    
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.executable   = 0; /* data/stack segment */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.c_ed         = 0; /* normal expand up */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.r_w          = 1; /* writeable */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.a            = 1; /* accessed */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.base         = 0x00000000;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.limit        =     0xfffff;
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.limit_scaled =     0xffffffff;
#endif
#if BX_CPU_LEVEL >= 3
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.g   = 1; /* 4Kb granular */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.d_b = 1; /* 32bit default size */
    bx_cpu.sregs[BX_SEG_REG_SS].cache.u.segment.avl = 0;
#endif

    // 
        /* GDTR (Global Descriptor Table Register) */
#if BX_CPU_LEVEL >= 2
    bx_cpu.gdtr.base         = 0x00000000;  
    bx_cpu.gdtr.limit        =     0x001f;  
#endif
        // set PE bit in CR0 so that protected mode is enabled
    bx_cpu.SetCR0(0x01);
  }
  else
  {
    cerr << "hw-cpu-x86: unsupported memory mode" << endl;
  }
}
