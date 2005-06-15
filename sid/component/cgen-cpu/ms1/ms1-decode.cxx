/* Simulator instruction decoder for ms1.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "ms1.h"

using namespace ms1; // FIXME: namespace organization still wip


// The instruction descriptor array. 

ms1_idesc ms1_idesc::idesc_table[MS1_INSN_MFBCBINCRS + 1] =
{
  { ms1_sem_x_invalid, "X_INVALID", MS1_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE) } },
  { ms1_sem_add, "ADD", MS1_INSN_ADD, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_addu, "ADDU", MS1_INSN_ADDU, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_addi, "ADDI", MS1_INSN_ADDI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_addui, "ADDUI", MS1_INSN_ADDUI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_sub, "SUB", MS1_INSN_SUB, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_subu, "SUBU", MS1_INSN_SUBU, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_subi, "SUBI", MS1_INSN_SUBI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_subui, "SUBUI", MS1_INSN_SUBUI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_mul, "MUL", MS1_INSN_MUL, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_MS1_003) } },
  { ms1_sem_muli, "MULI", MS1_INSN_MULI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_MS1_003) } },
  { ms1_sem_and, "AND", MS1_INSN_AND, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_andi, "ANDI", MS1_INSN_ANDI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_or, "OR", MS1_INSN_OR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_nop, "NOP", MS1_INSN_NOP, { 0, (1<<MACH_BASE) } },
  { ms1_sem_ori, "ORI", MS1_INSN_ORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_xor, "XOR", MS1_INSN_XOR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_xori, "XORI", MS1_INSN_XORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_nand, "NAND", MS1_INSN_NAND, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_nandi, "NANDI", MS1_INSN_NANDI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_nor, "NOR", MS1_INSN_NOR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_nori, "NORI", MS1_INSN_NORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_xnor, "XNOR", MS1_INSN_XNOR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_xnori, "XNORI", MS1_INSN_XNORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_ldui, "LDUI", MS1_INSN_LDUI, { 0|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { ms1_sem_lsl, "LSL", MS1_INSN_LSL, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR), (1<<MACH_BASE) } },
  { ms1_sem_lsli, "LSLI", MS1_INSN_LSLI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR), (1<<MACH_BASE) } },
  { ms1_sem_lsr, "LSR", MS1_INSN_LSR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR), (1<<MACH_BASE) } },
  { ms1_sem_lsri, "LSRI", MS1_INSN_LSRI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR), (1<<MACH_BASE) } },
  { ms1_sem_asr, "ASR", MS1_INSN_ASR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR), (1<<MACH_BASE) } },
  { ms1_sem_asri, "ASRI", MS1_INSN_ASRI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR), (1<<MACH_BASE) } },
  { ms1_sem_brlt, "BRLT", MS1_INSN_BRLT, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { ms1_sem_brle, "BRLE", MS1_INSN_BRLE, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { ms1_sem_breq, "BREQ", MS1_INSN_BREQ, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { ms1_sem_brne, "BRNE", MS1_INSN_BRNE, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { ms1_sem_jmp, "JMP", MS1_INSN_JMP, { 0|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { ms1_sem_jal, "JAL", MS1_INSN_JAL, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { ms1_sem_dbnz, "DBNZ", MS1_INSN_DBNZ, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_MS1_003) } },
  { ms1_sem_ei, "EI", MS1_INSN_EI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_di, "DI", MS1_INSN_DI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_si, "SI", MS1_INSN_SI, { 0|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { ms1_sem_reti, "RETI", MS1_INSN_RETI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { ms1_sem_ldw, "LDW", MS1_INSN_LDW, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_MEMORY_ACCESS)|(1<<CGEN_INSN_LOAD_DELAY), (1<<MACH_BASE) } },
  { ms1_sem_stw, "STW", MS1_INSN_STW, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_MEMORY_ACCESS), (1<<MACH_BASE) } },
  { ms1_sem_break, "BREAK", MS1_INSN_BREAK, { 0, (1<<MACH_BASE) } },
  { ms1_sem_iflush, "IFLUSH", MS1_INSN_IFLUSH, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_ldctxt, "LDCTXT", MS1_INSN_LDCTXT, { 0, (1<<MACH_BASE) } },
  { ms1_sem_ldfb, "LDFB", MS1_INSN_LDFB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_stfb, "STFB", MS1_INSN_STFB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbcb, "FBCB", MS1_INSN_FBCB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_mfbcb, "MFBCB", MS1_INSN_MFBCB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbcci, "FBCCI", MS1_INSN_FBCCI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbrci, "FBRCI", MS1_INSN_FBRCI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbcri, "FBCRI", MS1_INSN_FBCRI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbrri, "FBRRI", MS1_INSN_FBRRI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_mfbcci, "MFBCCI", MS1_INSN_MFBCCI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_mfbrci, "MFBRCI", MS1_INSN_MFBRCI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_mfbcri, "MFBCRI", MS1_INSN_MFBCRI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_mfbrri, "MFBRRI", MS1_INSN_MFBRRI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbcbdr, "FBCBDR", MS1_INSN_FBCBDR, { 0, (1<<MACH_BASE) } },
  { ms1_sem_rcfbcb, "RCFBCB", MS1_INSN_RCFBCB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_mrcfbcb, "MRCFBCB", MS1_INSN_MRCFBCB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_cbcast, "CBCAST", MS1_INSN_CBCAST, { 0, (1<<MACH_BASE) } },
  { ms1_sem_dupcbcast, "DUPCBCAST", MS1_INSN_DUPCBCAST, { 0, (1<<MACH_BASE) } },
  { ms1_sem_wfbi, "WFBI", MS1_INSN_WFBI, { 0, (1<<MACH_BASE) } },
  { ms1_sem_wfb, "WFB", MS1_INSN_WFB, { 0, (1<<MACH_BASE) } },
  { ms1_sem_rcrisc, "RCRISC", MS1_INSN_RCRISC, { 0, (1<<MACH_BASE) } },
  { ms1_sem_fbcbinc, "FBCBINC", MS1_INSN_FBCBINC, { 0, (1<<MACH_BASE) } },
  { ms1_sem_rcxmode, "RCXMODE", MS1_INSN_RCXMODE, { 0, (1<<MACH_BASE) } },
  { ms1_sem_interleaver, "INTERLEAVER", MS1_INSN_INTERLEAVER, { 0, (1<<MACH_BASE) } },
  { ms1_sem_wfbinc, "WFBINC", MS1_INSN_WFBINC, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_mwfbinc, "MWFBINC", MS1_INSN_MWFBINC, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_wfbincr, "WFBINCR", MS1_INSN_WFBINCR, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_mwfbincr, "MWFBINCR", MS1_INSN_MWFBINCR, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_fbcbincs, "FBCBINCS", MS1_INSN_FBCBINCS, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_mfbcbincs, "MFBCBINCS", MS1_INSN_MFBCBINCS, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_fbcbincrs, "FBCBINCRS", MS1_INSN_FBCBINCRS, { 0, (1<<MACH_MS1_003) } },
  { ms1_sem_mfbcbincrs, "MFBCBINCRS", MS1_INSN_MFBCBINCRS, { 0, (1<<MACH_MS1_003) } },

};

// Given a canonical virtual insn id, return the target specific one.

ms1_insn_type
ms1_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return MS1_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return MS1_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
ms1_extract_sfmt_empty (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_add (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_addu (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_addi (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_addui (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_andi (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_nop (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_ldui (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_lsl (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_brlt (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_jmp (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_jal (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_dbnz (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_si (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_reti (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_ldw (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_stw (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);
static void
ms1_extract_sfmt_break (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn);

// Fetch & decode instruction
void
ms1_scache::decode (ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn)
{
  /* Result of decoder.  */
  MS1_INSN_TYPE itype;

  {
    ms1_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 24) & (255 << 0)));
      switch (val)
      {
      case 0 :
        if ((entire_insn & 0xff000fff) == 0x0)
          { itype = MS1_INSN_ADD; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1 :
        if ((entire_insn & 0xff000000) == 0x1000000)
          { itype = MS1_INSN_ADDI; ms1_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 2 :
        if ((entire_insn & 0xff000fff) == 0x2000000)
          { itype = MS1_INSN_ADDU; ms1_extract_sfmt_addu (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 :
        if ((entire_insn & 0xff000000) == 0x3000000)
          { itype = MS1_INSN_ADDUI; ms1_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 :
        if ((entire_insn & 0xff000fff) == 0x4000000)
          { itype = MS1_INSN_SUB; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 5 :
        if ((entire_insn & 0xff000000) == 0x5000000)
          { itype = MS1_INSN_SUBI; ms1_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 6 :
        if ((entire_insn & 0xff000fff) == 0x6000000)
          { itype = MS1_INSN_SUBU; ms1_extract_sfmt_addu (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 :
        if ((entire_insn & 0xff000000) == 0x7000000)
          { itype = MS1_INSN_SUBUI; ms1_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 :
        if ((entire_insn & 0xff000fff) == 0x8000000)
          { itype = MS1_INSN_MUL; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 9 :
        if ((entire_insn & 0xff000000) == 0x9000000)
          { itype = MS1_INSN_MULI; ms1_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 :
        if ((entire_insn & 0xff000fff) == 0x10000000)
          { itype = MS1_INSN_AND; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 17 :
        if ((entire_insn & 0xff000000) == 0x11000000)
          { itype = MS1_INSN_ANDI; ms1_extract_sfmt_andi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 18 :
        {
          unsigned int val = (((insn >> 12) & (127 << 0)));
          switch (val)
          {
          case 0 :
            {
              unsigned int val = (((insn >> 19) & (31 << 0)));
              switch (val)
              {
              case 0 :
                if ((entire_insn & 0xffffffff) == 0x12000000)
                  { itype = MS1_INSN_NOP; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 1 : /* fall through */
              case 2 : /* fall through */
              case 3 : /* fall through */
              case 4 : /* fall through */
              case 5 : /* fall through */
              case 6 : /* fall through */
              case 7 : /* fall through */
              case 8 : /* fall through */
              case 9 : /* fall through */
              case 10 : /* fall through */
              case 11 : /* fall through */
              case 12 : /* fall through */
              case 13 : /* fall through */
              case 14 : /* fall through */
              case 15 : /* fall through */
              case 16 : /* fall through */
              case 17 : /* fall through */
              case 18 : /* fall through */
              case 19 : /* fall through */
              case 20 : /* fall through */
              case 21 : /* fall through */
              case 22 : /* fall through */
              case 23 : /* fall through */
              case 24 : /* fall through */
              case 25 : /* fall through */
              case 26 : /* fall through */
              case 27 : /* fall through */
              case 28 : /* fall through */
              case 29 : /* fall through */
              case 30 : /* fall through */
              case 31 :
                if ((entire_insn & 0xff000fff) == 0x12000000)
                  { itype = MS1_INSN_OR; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              }
            }
          case 1 : /* fall through */
          case 2 : /* fall through */
          case 3 : /* fall through */
          case 4 : /* fall through */
          case 5 : /* fall through */
          case 6 : /* fall through */
          case 7 : /* fall through */
          case 8 : /* fall through */
          case 9 : /* fall through */
          case 10 : /* fall through */
          case 11 : /* fall through */
          case 12 : /* fall through */
          case 13 : /* fall through */
          case 14 : /* fall through */
          case 15 : /* fall through */
          case 16 : /* fall through */
          case 17 : /* fall through */
          case 18 : /* fall through */
          case 19 : /* fall through */
          case 20 : /* fall through */
          case 21 : /* fall through */
          case 22 : /* fall through */
          case 23 : /* fall through */
          case 24 : /* fall through */
          case 25 : /* fall through */
          case 26 : /* fall through */
          case 27 : /* fall through */
          case 28 : /* fall through */
          case 29 : /* fall through */
          case 30 : /* fall through */
          case 31 : /* fall through */
          case 32 : /* fall through */
          case 33 : /* fall through */
          case 34 : /* fall through */
          case 35 : /* fall through */
          case 36 : /* fall through */
          case 37 : /* fall through */
          case 38 : /* fall through */
          case 39 : /* fall through */
          case 40 : /* fall through */
          case 41 : /* fall through */
          case 42 : /* fall through */
          case 43 : /* fall through */
          case 44 : /* fall through */
          case 45 : /* fall through */
          case 46 : /* fall through */
          case 47 : /* fall through */
          case 48 : /* fall through */
          case 49 : /* fall through */
          case 50 : /* fall through */
          case 51 : /* fall through */
          case 52 : /* fall through */
          case 53 : /* fall through */
          case 54 : /* fall through */
          case 55 : /* fall through */
          case 56 : /* fall through */
          case 57 : /* fall through */
          case 58 : /* fall through */
          case 59 : /* fall through */
          case 60 : /* fall through */
          case 61 : /* fall through */
          case 62 : /* fall through */
          case 63 : /* fall through */
          case 64 : /* fall through */
          case 65 : /* fall through */
          case 66 : /* fall through */
          case 67 : /* fall through */
          case 68 : /* fall through */
          case 69 : /* fall through */
          case 70 : /* fall through */
          case 71 : /* fall through */
          case 72 : /* fall through */
          case 73 : /* fall through */
          case 74 : /* fall through */
          case 75 : /* fall through */
          case 76 : /* fall through */
          case 77 : /* fall through */
          case 78 : /* fall through */
          case 79 : /* fall through */
          case 80 : /* fall through */
          case 81 : /* fall through */
          case 82 : /* fall through */
          case 83 : /* fall through */
          case 84 : /* fall through */
          case 85 : /* fall through */
          case 86 : /* fall through */
          case 87 : /* fall through */
          case 88 : /* fall through */
          case 89 : /* fall through */
          case 90 : /* fall through */
          case 91 : /* fall through */
          case 92 : /* fall through */
          case 93 : /* fall through */
          case 94 : /* fall through */
          case 95 : /* fall through */
          case 96 : /* fall through */
          case 97 : /* fall through */
          case 98 : /* fall through */
          case 99 : /* fall through */
          case 100 : /* fall through */
          case 101 : /* fall through */
          case 102 : /* fall through */
          case 103 : /* fall through */
          case 104 : /* fall through */
          case 105 : /* fall through */
          case 106 : /* fall through */
          case 107 : /* fall through */
          case 108 : /* fall through */
          case 109 : /* fall through */
          case 110 : /* fall through */
          case 111 : /* fall through */
          case 112 : /* fall through */
          case 113 : /* fall through */
          case 114 : /* fall through */
          case 115 : /* fall through */
          case 116 : /* fall through */
          case 117 : /* fall through */
          case 118 : /* fall through */
          case 119 : /* fall through */
          case 120 : /* fall through */
          case 121 : /* fall through */
          case 122 : /* fall through */
          case 123 : /* fall through */
          case 124 : /* fall through */
          case 125 : /* fall through */
          case 126 : /* fall through */
          case 127 :
            if ((entire_insn & 0xff000fff) == 0x12000000)
              { itype = MS1_INSN_OR; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 19 :
        if ((entire_insn & 0xff000000) == 0x13000000)
          { itype = MS1_INSN_ORI; ms1_extract_sfmt_andi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 20 :
        if ((entire_insn & 0xff000fff) == 0x14000000)
          { itype = MS1_INSN_XOR; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 21 :
        if ((entire_insn & 0xff000000) == 0x15000000)
          { itype = MS1_INSN_XORI; ms1_extract_sfmt_andi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 22 :
        if ((entire_insn & 0xff000fff) == 0x16000000)
          { itype = MS1_INSN_NAND; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 23 :
        if ((entire_insn & 0xff000000) == 0x17000000)
          { itype = MS1_INSN_NANDI; ms1_extract_sfmt_andi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 :
        if ((entire_insn & 0xff000fff) == 0x18000000)
          { itype = MS1_INSN_NOR; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 25 :
        if ((entire_insn & 0xff000000) == 0x19000000)
          { itype = MS1_INSN_NORI; ms1_extract_sfmt_andi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 26 :
        if ((entire_insn & 0xff000fff) == 0x1a000000)
          { itype = MS1_INSN_XNOR; ms1_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 27 :
        if ((entire_insn & 0xff000000) == 0x1b000000)
          { itype = MS1_INSN_XNORI; ms1_extract_sfmt_andi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 29 :
        if ((entire_insn & 0xfff00000) == 0x1d000000)
          { itype = MS1_INSN_LDUI; ms1_extract_sfmt_ldui (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 32 :
        if ((entire_insn & 0xff000fff) == 0x20000000)
          { itype = MS1_INSN_LSL; ms1_extract_sfmt_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 33 :
        if ((entire_insn & 0xff000000) == 0x21000000)
          { itype = MS1_INSN_LSLI; ms1_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 34 :
        if ((entire_insn & 0xff000fff) == 0x22000000)
          { itype = MS1_INSN_LSR; ms1_extract_sfmt_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 35 :
        if ((entire_insn & 0xff000000) == 0x23000000)
          { itype = MS1_INSN_LSRI; ms1_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 36 :
        if ((entire_insn & 0xff000fff) == 0x24000000)
          { itype = MS1_INSN_ASR; ms1_extract_sfmt_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 37 :
        if ((entire_insn & 0xff000000) == 0x25000000)
          { itype = MS1_INSN_ASRI; ms1_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 49 :
        if ((entire_insn & 0xff000000) == 0x31000000)
          { itype = MS1_INSN_BRLT; ms1_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 51 :
        if ((entire_insn & 0xff000000) == 0x33000000)
          { itype = MS1_INSN_BRLE; ms1_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 53 :
        if ((entire_insn & 0xff000000) == 0x35000000)
          { itype = MS1_INSN_BREQ; ms1_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 55 :
        if ((entire_insn & 0xffff0000) == 0x37000000)
          { itype = MS1_INSN_JMP; ms1_extract_sfmt_jmp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 56 :
        if ((entire_insn & 0xff0f0fff) == 0x38000000)
          { itype = MS1_INSN_JAL; ms1_extract_sfmt_jal (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 59 :
        if ((entire_insn & 0xff000000) == 0x3b000000)
          { itype = MS1_INSN_BRNE; ms1_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 61 :
        if ((entire_insn & 0xff0f0000) == 0x3d000000)
          { itype = MS1_INSN_DBNZ; ms1_extract_sfmt_dbnz (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 65 :
        if ((entire_insn & 0xff000000) == 0x41000000)
          { itype = MS1_INSN_LDW; ms1_extract_sfmt_ldw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 67 :
        if ((entire_insn & 0xff000000) == 0x43000000)
          { itype = MS1_INSN_STW; ms1_extract_sfmt_stw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 96 :
        if ((entire_insn & 0xffffffff) == 0x60000000)
          { itype = MS1_INSN_EI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 98 :
        if ((entire_insn & 0xffffffff) == 0x62000000)
          { itype = MS1_INSN_DI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 100 :
        if ((entire_insn & 0xffff0fff) == 0x64000000)
          { itype = MS1_INSN_SI; ms1_extract_sfmt_si (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 102 :
        if ((entire_insn & 0xff0fffff) == 0x66000000)
          { itype = MS1_INSN_RETI; ms1_extract_sfmt_reti (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 104 :
        if ((entire_insn & 0xffffffff) == 0x68000000)
          { itype = MS1_INSN_BREAK; ms1_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 106 :
        if ((entire_insn & 0xffffffff) == 0x6a000000)
          { itype = MS1_INSN_IFLUSH; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 128 :
        if ((entire_insn & 0xff000e00) == 0x80000000)
          { itype = MS1_INSN_LDCTXT; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 132 :
        if ((entire_insn & 0xff000000) == 0x84000000)
          { itype = MS1_INSN_LDFB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 136 :
        if ((entire_insn & 0xff000000) == 0x88000000)
          { itype = MS1_INSN_STFB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 140 : /* fall through */
      case 141 : /* fall through */
      case 142 : /* fall through */
      case 143 :
        if ((entire_insn & 0xfc00f000) == 0x8c000000)
          { itype = MS1_INSN_FBCB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 144 : /* fall through */
      case 145 : /* fall through */
      case 146 : /* fall through */
      case 147 :
        if ((entire_insn & 0xfc00f000) == 0x90000000)
          { itype = MS1_INSN_MFBCB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 148 : /* fall through */
      case 149 : /* fall through */
      case 150 : /* fall through */
      case 151 :
        if ((entire_insn & 0xfc000000) == 0x94000000)
          { itype = MS1_INSN_FBCCI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 152 : /* fall through */
      case 153 : /* fall through */
      case 154 : /* fall through */
      case 155 :
        if ((entire_insn & 0xfc000000) == 0x98000000)
          { itype = MS1_INSN_FBRCI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 156 : /* fall through */
      case 157 : /* fall through */
      case 158 : /* fall through */
      case 159 :
        if ((entire_insn & 0xfc000000) == 0x9c000000)
          { itype = MS1_INSN_FBCRI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 160 : /* fall through */
      case 161 : /* fall through */
      case 162 : /* fall through */
      case 163 :
        if ((entire_insn & 0xfc000000) == 0xa0000000)
          { itype = MS1_INSN_FBRRI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 164 : /* fall through */
      case 165 : /* fall through */
      case 166 : /* fall through */
      case 167 :
        if ((entire_insn & 0xfc000000) == 0xa4000000)
          { itype = MS1_INSN_MFBCCI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 168 : /* fall through */
      case 169 : /* fall through */
      case 170 : /* fall through */
      case 171 :
        if ((entire_insn & 0xfc000000) == 0xa8000000)
          { itype = MS1_INSN_MFBRCI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 172 : /* fall through */
      case 173 : /* fall through */
      case 174 : /* fall through */
      case 175 :
        if ((entire_insn & 0xfc000000) == 0xac000000)
          { itype = MS1_INSN_MFBCRI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 176 : /* fall through */
      case 177 : /* fall through */
      case 178 : /* fall through */
      case 179 :
        if ((entire_insn & 0xfc000000) == 0xb0000000)
          { itype = MS1_INSN_MFBRRI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 180 : /* fall through */
      case 181 : /* fall through */
      case 182 : /* fall through */
      case 183 :
        if ((entire_insn & 0xfc000000) == 0xb4000000)
          { itype = MS1_INSN_FBCBDR; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 184 : /* fall through */
      case 185 : /* fall through */
      case 186 : /* fall through */
      case 187 :
        if ((entire_insn & 0xfcc08000) == 0xb8000000)
          { itype = MS1_INSN_RCFBCB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 188 : /* fall through */
      case 189 : /* fall through */
      case 190 : /* fall through */
      case 191 :
        if ((entire_insn & 0xfcc08000) == 0xbc000000)
          { itype = MS1_INSN_MRCFBCB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 192 : /* fall through */
      case 193 : /* fall through */
      case 194 : /* fall through */
      case 195 :
        if ((entire_insn & 0xfc000380) == 0xc0000000)
          { itype = MS1_INSN_CBCAST; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 196 : /* fall through */
      case 197 : /* fall through */
      case 198 : /* fall through */
      case 199 :
        if ((entire_insn & 0xfc000000) == 0xc4000000)
          { itype = MS1_INSN_DUPCBCAST; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 200 : /* fall through */
      case 201 : /* fall through */
      case 202 : /* fall through */
      case 203 :
        if ((entire_insn & 0xfc000000) == 0xc8000000)
          { itype = MS1_INSN_WFBI; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 204 :
        if ((entire_insn & 0xff000040) == 0xcc000000)
          { itype = MS1_INSN_WFB; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 208 : /* fall through */
      case 209 : /* fall through */
      case 210 : /* fall through */
      case 211 :
        if ((entire_insn & 0xfc080000) == 0xd0000000)
          { itype = MS1_INSN_RCRISC; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 212 : /* fall through */
      case 213 : /* fall through */
      case 214 : /* fall through */
      case 215 :
        if ((entire_insn & 0xfc000000) == 0xd4000000)
          { itype = MS1_INSN_FBCBINC; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 216 : /* fall through */
      case 217 : /* fall through */
      case 218 : /* fall through */
      case 219 :
        if ((entire_insn & 0xfc000000) == 0xd8000000)
          { itype = MS1_INSN_RCXMODE; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 220 : /* fall through */
      case 221 : /* fall through */
      case 222 : /* fall through */
      case 223 :
        if ((entire_insn & 0xfc008000) == 0xdc000000)
          { itype = MS1_INSN_INTERLEAVER; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 224 : /* fall through */
      case 225 : /* fall through */
      case 226 : /* fall through */
      case 227 :
        if ((entire_insn & 0xfc000000) == 0xe0000000)
          { itype = MS1_INSN_WFBINC; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 228 : /* fall through */
      case 229 : /* fall through */
      case 230 : /* fall through */
      case 231 :
        if ((entire_insn & 0xfc000000) == 0xe4000000)
          { itype = MS1_INSN_MWFBINC; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 232 : /* fall through */
      case 233 : /* fall through */
      case 234 : /* fall through */
      case 235 :
        if ((entire_insn & 0xfc000000) == 0xe8000000)
          { itype = MS1_INSN_WFBINCR; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 236 : /* fall through */
      case 237 : /* fall through */
      case 238 : /* fall through */
      case 239 :
        if ((entire_insn & 0xfc000000) == 0xec000000)
          { itype = MS1_INSN_MWFBINCR; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 240 : /* fall through */
      case 241 : /* fall through */
      case 242 : /* fall through */
      case 243 :
        if ((entire_insn & 0xfc000000) == 0xf0000000)
          { itype = MS1_INSN_FBCBINCS; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 244 : /* fall through */
      case 245 : /* fall through */
      case 246 : /* fall through */
      case 247 :
        if ((entire_insn & 0xfc000000) == 0xf4000000)
          { itype = MS1_INSN_MFBCBINCS; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 248 : /* fall through */
      case 249 : /* fall through */
      case 250 : /* fall through */
      case 251 :
        if ((entire_insn & 0xfc008000) == 0xf8000000)
          { itype = MS1_INSN_FBCBINCRS; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 252 : /* fall through */
      case 253 : /* fall through */
      case 254 : /* fall through */
      case 255 :
        if ((entire_insn & 0xfc008000) == 0xfc000000)
          { itype = MS1_INSN_MFBCBINCRS; ms1_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = MS1_INSN_X_INVALID; ms1_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & ms1_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
ms1_extract_sfmt_empty (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_empty)\t"
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_add (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_sr1;
    UINT f_sr2;
    UINT f_drrr;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_sr2 = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_drrr = EXTRACT_LSB0_UINT (insn, 32, 15, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_sr2) = f_sr2;
  FLD (f_drrr) = f_drrr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_sr2:0x" << hex << f_sr2 << dec
        << " f_drrr:0x" << hex << f_drrr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_addu (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_sr1;
    UINT f_sr2;
    UINT f_drrr;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_sr2 = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_drrr = EXTRACT_LSB0_UINT (insn, 32, 15, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_sr2) = f_sr2;
  FLD (f_drrr) = f_drrr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addu)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_sr2:0x" << hex << f_sr2 << dec
        << " f_drrr:0x" << hex << f_drrr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_addi (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_sr1;
    UINT f_dr;
    HI f_imm16s;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_dr = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16s = ((EXTRACT_LSB0_INT (insn, 32, 15, 16)) + (0));

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_imm16s) = f_imm16s;
  FLD (f_dr) = f_dr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addi)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_imm16s:0x" << hex << f_imm16s << dec
        << " f_dr:0x" << hex << f_dr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_addui (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addui.f
    UINT f_sr1;
    UINT f_dr;
    UINT f_imm16u;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_dr = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16u = EXTRACT_LSB0_UINT (insn, 32, 15, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_imm16u) = f_imm16u;
  FLD (f_dr) = f_dr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addui)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_imm16u:0x" << hex << f_imm16u << dec
        << " f_dr:0x" << hex << f_dr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_andi (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addui.f
    UINT f_sr1;
    UINT f_dr;
    UINT f_imm16u;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_dr = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16u = EXTRACT_LSB0_UINT (insn, 32, 15, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_imm16u) = f_imm16u;
  FLD (f_dr) = f_dr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_andi)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_imm16u:0x" << hex << f_imm16u << dec
        << " f_dr:0x" << hex << f_dr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_nop (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_nop)\t"
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_ldui (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addui.f
    UINT f_dr;
    UINT f_imm16u;

    f_dr = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16u = EXTRACT_LSB0_UINT (insn, 32, 15, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm16u) = f_imm16u;
  FLD (f_dr) = f_dr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldui)\t"
        << " f_imm16u:0x" << hex << f_imm16u << dec
        << " f_dr:0x" << hex << f_dr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_lsl (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_sr1;
    UINT f_sr2;
    UINT f_drrr;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_sr2 = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_drrr = EXTRACT_LSB0_UINT (insn, 32, 15, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_sr2) = f_sr2;
  FLD (f_drrr) = f_drrr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lsl)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_sr2:0x" << hex << f_sr2 << dec
        << " f_drrr:0x" << hex << f_drrr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_brlt (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_brlt.f
    UINT f_sr1;
    UINT f_sr2;
    HI f_imm16s;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_sr2 = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16s = ((EXTRACT_LSB0_INT (insn, 32, 15, 16)) + (0));

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_sr2) = f_sr2;
  FLD (f_imm16s) = f_imm16s;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_brlt)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_sr2:0x" << hex << f_sr2 << dec
        << " f_imm16s:0x" << hex << f_imm16s << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
ms1_extract_sfmt_jmp (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_brlt.f
    HI f_imm16s;

    f_imm16s = ((EXTRACT_LSB0_INT (insn, 32, 15, 16)) + (0));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm16s) = f_imm16s;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jmp)\t"
        << " f_imm16s:0x" << hex << f_imm16s << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
ms1_extract_sfmt_jal (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_sr1;
    UINT f_drrr;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_drrr = EXTRACT_LSB0_UINT (insn, 32, 15, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_drrr) = f_drrr;
  FLD (f_sr1) = f_sr1;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jal)\t"
        << " f_drrr:0x" << hex << f_drrr << dec
        << " f_sr1:0x" << hex << f_sr1 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
ms1_extract_sfmt_dbnz (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_brlt.f
    UINT f_sr1;
    HI f_imm16s;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_imm16s = ((EXTRACT_LSB0_INT (insn, 32, 15, 16)) + (0));

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_imm16s) = f_imm16s;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_dbnz)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_imm16s:0x" << hex << f_imm16s << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
ms1_extract_sfmt_si (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_drrr;

    f_drrr = EXTRACT_LSB0_UINT (insn, 32, 15, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_drrr) = f_drrr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_si)\t"
        << " f_drrr:0x" << hex << f_drrr << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
ms1_extract_sfmt_reti (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_brlt.f
    UINT f_sr1;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_reti)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
ms1_extract_sfmt_ldw (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_sr1;
    UINT f_dr;
    HI f_imm16s;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_dr = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16s = ((EXTRACT_LSB0_INT (insn, 32, 15, 16)) + (0));

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_imm16s) = f_imm16s;
  FLD (f_dr) = f_dr;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldw)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_imm16s:0x" << hex << f_imm16s << dec
        << " f_dr:0x" << hex << f_dr << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_stw (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_brlt.f
    UINT f_sr1;
    UINT f_sr2;
    HI f_imm16s;

    f_sr1 = EXTRACT_LSB0_UINT (insn, 32, 23, 4);
    f_sr2 = EXTRACT_LSB0_UINT (insn, 32, 19, 4);
    f_imm16s = ((EXTRACT_LSB0_INT (insn, 32, 15, 16)) + (0));

  /* Record the fields for the semantic handler.  */
  FLD (f_sr1) = f_sr1;
  FLD (f_sr2) = f_sr2;
  FLD (f_imm16s) = f_imm16s;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stw)\t"
        << " f_sr1:0x" << hex << f_sr1 << dec
        << " f_sr2:0x" << hex << f_sr2 << dec
        << " f_imm16s:0x" << hex << f_imm16s << dec
        << endl;
    }

#undef FLD
}

void
ms1_extract_sfmt_break (ms1_scache* abuf, ms1_cpu* current_cpu, PCADDR pc, ms1_insn_word base_insn, ms1_insn_word entire_insn){
    ms1_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_break)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

