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

#include "bochs.h"
#define LOG_THIS BX_CPU_THIS_PTR

     // sid_cpu_c constructor
void sid_cpu_c::init(sid_mem_c *addrspace)
{
    // To deal with initialization order problems inherent in C++, use
  // the macros SAFE_GET_IOFUNC and SAFE_GET_GENLOG to retrieve "io" and "genlog"
  // in all constructors or functions called by constructors.  The macros
  // test for NULL and create the object if necessary, then return it.
  // Ensure that io and genlog get created, by making one reference to
  // each macro right here.  All other code can call them directly.
  SAFE_GET_IOFUNC();
  SAFE_GET_GENLOG();

  BX_CPU_THIS_PTR set_INTR (0);
#if BX_SUPPORT_APIC
  local_apic.init ();
#endif
  setprefix("[CPU ]");
  // in SMP mode, the prefix of the CPU will be changed to [CPUn] in 
  // bx_local_apic_c::set_id as soon as the apic ID is assigned.

  /* hack for the following fields.  Its easier to decode mod-rm bytes if
     you can assume there's always a base & index register used.  For
     modes which don't really use them, point to an empty (zeroed) register.
   */
  empty_register = 0;

  // 16bit address mode base register, used for mod-rm decoding

  _16bit_base_reg[0] = &gen_reg[BX_16BIT_REG_BX].word.rx;
  _16bit_base_reg[1] = &gen_reg[BX_16BIT_REG_BX].word.rx;
  _16bit_base_reg[2] = &gen_reg[BX_16BIT_REG_BP].word.rx;
  _16bit_base_reg[3] = &gen_reg[BX_16BIT_REG_BP].word.rx;
  _16bit_base_reg[4] = (Bit16u*) &empty_register;
  _16bit_base_reg[5] = (Bit16u*) &empty_register;
  _16bit_base_reg[6] = &gen_reg[BX_16BIT_REG_BP].word.rx;
  _16bit_base_reg[7] = &gen_reg[BX_16BIT_REG_BX].word.rx;

  // 16bit address mode index register, used for mod-rm decoding
  _16bit_index_reg[0] = &gen_reg[BX_16BIT_REG_SI].word.rx;
  _16bit_index_reg[1] = &gen_reg[BX_16BIT_REG_DI].word.rx;
  _16bit_index_reg[2] = &gen_reg[BX_16BIT_REG_SI].word.rx;
  _16bit_index_reg[3] = &gen_reg[BX_16BIT_REG_DI].word.rx;
  _16bit_index_reg[4] = &gen_reg[BX_16BIT_REG_SI].word.rx;
  _16bit_index_reg[5] = &gen_reg[BX_16BIT_REG_DI].word.rx;
  _16bit_index_reg[6] = (Bit16u*) &empty_register;
  _16bit_index_reg[7] = (Bit16u*) &empty_register;

  // for decoding instructions: access to seg reg's via index number
  sreg_mod00_rm16[0] = BX_SEG_REG_DS;
  sreg_mod00_rm16[1] = BX_SEG_REG_DS;
  sreg_mod00_rm16[2] = BX_SEG_REG_SS;
  sreg_mod00_rm16[3] = BX_SEG_REG_SS;
  sreg_mod00_rm16[4] = BX_SEG_REG_DS;
  sreg_mod00_rm16[5] = BX_SEG_REG_DS;
  sreg_mod00_rm16[6] = BX_SEG_REG_DS;
  sreg_mod00_rm16[7] = BX_SEG_REG_DS;

  sreg_mod01_rm16[0] = BX_SEG_REG_DS;
  sreg_mod01_rm16[1] = BX_SEG_REG_DS;
  sreg_mod01_rm16[2] = BX_SEG_REG_SS;
  sreg_mod01_rm16[3] = BX_SEG_REG_SS;
  sreg_mod01_rm16[4] = BX_SEG_REG_DS;
  sreg_mod01_rm16[5] = BX_SEG_REG_DS;
  sreg_mod01_rm16[6] = BX_SEG_REG_SS;
  sreg_mod01_rm16[7] = BX_SEG_REG_DS;

  sreg_mod10_rm16[0] = BX_SEG_REG_DS;
  sreg_mod10_rm16[1] = BX_SEG_REG_DS;
  sreg_mod10_rm16[2] = BX_SEG_REG_SS;
  sreg_mod10_rm16[3] = BX_SEG_REG_SS;
  sreg_mod10_rm16[4] = BX_SEG_REG_DS;
  sreg_mod10_rm16[5] = BX_SEG_REG_DS;
  sreg_mod10_rm16[6] = BX_SEG_REG_SS;
  sreg_mod10_rm16[7] = BX_SEG_REG_DS;

  // the default segment to use for a one-byte modrm with mod==01b
  // and rm==i
  //
  sreg_mod01_rm32[0] = BX_SEG_REG_DS;
  sreg_mod01_rm32[1] = BX_SEG_REG_DS;
  sreg_mod01_rm32[2] = BX_SEG_REG_DS;
  sreg_mod01_rm32[3] = BX_SEG_REG_DS;
  sreg_mod01_rm32[4] = BX_SEG_REG_NULL;
    // this entry should never be accessed
    // (escape to 2-byte)
  sreg_mod01_rm32[5] = BX_SEG_REG_SS;
  sreg_mod01_rm32[6] = BX_SEG_REG_DS;
  sreg_mod01_rm32[7] = BX_SEG_REG_DS;

  // the default segment to use for a one-byte modrm with mod==10b
  // and rm==i
  //
  sreg_mod10_rm32[0] = BX_SEG_REG_DS;
  sreg_mod10_rm32[1] = BX_SEG_REG_DS;
  sreg_mod10_rm32[2] = BX_SEG_REG_DS;
  sreg_mod10_rm32[3] = BX_SEG_REG_DS;
  sreg_mod10_rm32[4] = BX_SEG_REG_NULL;
    // this entry should never be accessed
    // (escape to 2-byte)
  sreg_mod10_rm32[5] = BX_SEG_REG_SS;
  sreg_mod10_rm32[6] = BX_SEG_REG_DS;
  sreg_mod10_rm32[7] = BX_SEG_REG_DS;


  // the default segment to use for a two-byte modrm with mod==00b
  // and base==i
  //
  sreg_mod0_base32[0] = BX_SEG_REG_DS;
  sreg_mod0_base32[1] = BX_SEG_REG_DS;
  sreg_mod0_base32[2] = BX_SEG_REG_DS;
  sreg_mod0_base32[3] = BX_SEG_REG_DS;
  sreg_mod0_base32[4] = BX_SEG_REG_SS;
  sreg_mod0_base32[5] = BX_SEG_REG_DS;
  sreg_mod0_base32[6] = BX_SEG_REG_DS;
  sreg_mod0_base32[7] = BX_SEG_REG_DS;

  // the default segment to use for a two-byte modrm with
  // mod==01b or mod==10b and base==i
  sreg_mod1or2_base32[0] = BX_SEG_REG_DS;
  sreg_mod1or2_base32[1] = BX_SEG_REG_DS;
  sreg_mod1or2_base32[2] = BX_SEG_REG_DS;
  sreg_mod1or2_base32[3] = BX_SEG_REG_DS;
  sreg_mod1or2_base32[4] = BX_SEG_REG_SS;
  sreg_mod1or2_base32[5] = BX_SEG_REG_SS;
  sreg_mod1or2_base32[6] = BX_SEG_REG_DS;
  sreg_mod1or2_base32[7] = BX_SEG_REG_DS;

#if BX_DYNAMIC_TRANSLATION
  DTWrite8vShim = NULL;
  DTWrite16vShim = NULL;
  DTWrite32vShim = NULL;
  DTRead8vShim = NULL;
  DTRead16vShim = NULL;
  DTRead32vShim = NULL;
  DTReadRMW8vShim = (BxDTShim_t) DTASReadRMW8vShim;
  BX_DEBUG(( "DTReadRMW8vShim is %x\n", (unsigned) DTReadRMW8vShim ));
  BX_DEBUG(( "&DTReadRMW8vShim is %x\n", (unsigned) &DTReadRMW8vShim ));
  DTReadRMW16vShim = NULL;
  DTReadRMW32vShim = NULL;
  DTWriteRMW8vShim = (BxDTShim_t) DTASWriteRMW8vShim;
  DTWriteRMW16vShim = NULL;
  DTWriteRMW32vShim = NULL;
  DTSetFlagsOSZAPCPtr = (BxDTShim_t) DTASSetFlagsOSZAPC;
  DTIndBrHandler = (BxDTShim_t) DTASIndBrHandler;
  DTDirBrHandler = (BxDTShim_t) DTASDirBrHandler;
#endif

  mem = addrspace;
  sprintf (name, "CPU %p", this);

  BX_INSTR_INIT();
  BX_DEBUG(( "Init.\n"));
}

  void
sid_cpu_c::set_INTR(Boolean value)
{
  BX_CPU_THIS_PTR INTR = value;
  BX_CPU_THIS_PTR async_event = 0;
}
