/* Simulator instruction decoder for mt.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mt.h"

using namespace mt; // FIXME: namespace organization still wip


// The instruction descriptor array. 

mt_idesc mt_idesc::idesc_table[MT_INSN_MFBCBINCRS + 1] =
{
  { mt_sem_x_invalid, "X_INVALID", MT_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE) } },
  { mt_sem_add, "ADD", MT_INSN_ADD, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_addu, "ADDU", MT_INSN_ADDU, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_addi, "ADDI", MT_INSN_ADDI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_addui, "ADDUI", MT_INSN_ADDUI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_sub, "SUB", MT_INSN_SUB, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_subu, "SUBU", MT_INSN_SUBU, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_subi, "SUBI", MT_INSN_SUBI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_subui, "SUBUI", MT_INSN_SUBUI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_mul, "MUL", MT_INSN_MUL, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_muli, "MULI", MT_INSN_MULI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_and, "AND", MT_INSN_AND, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_andi, "ANDI", MT_INSN_ANDI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_or, "OR", MT_INSN_OR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_nop, "NOP", MT_INSN_NOP, { 0, (1<<MACH_BASE) } },
  { mt_sem_ori, "ORI", MT_INSN_ORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_xor, "XOR", MT_INSN_XOR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_xori, "XORI", MT_INSN_XORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_nand, "NAND", MT_INSN_NAND, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_nandi, "NANDI", MT_INSN_NANDI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_nor, "NOR", MT_INSN_NOR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_nori, "NORI", MT_INSN_NORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_xnor, "XNOR", MT_INSN_XNOR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_xnori, "XNORI", MT_INSN_XNORI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_ldui, "LDUI", MT_INSN_LDUI, { 0|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_AL_INSN), (1<<MACH_BASE) } },
  { mt_sem_lsl, "LSL", MT_INSN_LSL, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR), (1<<MACH_BASE) } },
  { mt_sem_lsli, "LSLI", MT_INSN_LSLI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR), (1<<MACH_BASE) } },
  { mt_sem_lsr, "LSR", MT_INSN_LSR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR), (1<<MACH_BASE) } },
  { mt_sem_lsri, "LSRI", MT_INSN_LSRI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR), (1<<MACH_BASE) } },
  { mt_sem_asr, "ASR", MT_INSN_ASR, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR), (1<<MACH_BASE) } },
  { mt_sem_asri, "ASRI", MT_INSN_ASRI, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR), (1<<MACH_BASE) } },
  { mt_sem_brlt, "BRLT", MT_INSN_BRLT, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDRRR)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { mt_sem_brle, "BRLE", MT_INSN_BRLE, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { mt_sem_breq, "BREQ", MT_INSN_BREQ, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { mt_sem_brne, "BRNE", MT_INSN_BRNE, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_BASE) } },
  { mt_sem_jmp, "JMP", MT_INSN_JMP, { 0|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { mt_sem_jal, "JAL", MT_INSN_JAL, { 0|(1<<CGEN_INSN_JAL_HAZARD)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { mt_sem_dbnz, "DBNZ", MT_INSN_DBNZ, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_DELAY_SLOT)|(1<<CGEN_INSN_BR_INSN), (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_ei, "EI", MT_INSN_EI, { 0, (1<<MACH_BASE) } },
  { mt_sem_di, "DI", MT_INSN_DI, { 0, (1<<MACH_BASE) } },
  { mt_sem_si, "SI", MT_INSN_SI, { 0|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { mt_sem_reti, "RETI", MT_INSN_RETI, { 0|(1<<CGEN_INSN_JAL_HAZARD)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_BR_INSN)|(1<<CGEN_INSN_DELAY_SLOT), (1<<MACH_BASE) } },
  { mt_sem_ldw, "LDW", MT_INSN_LDW, { 0|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_USES_FRDR)|(1<<CGEN_INSN_MEMORY_ACCESS)|(1<<CGEN_INSN_LOAD_DELAY), (1<<MACH_BASE) } },
  { mt_sem_stw, "STW", MT_INSN_STW, { 0|(1<<CGEN_INSN_USES_FRSR2)|(1<<CGEN_INSN_USES_FRSR1)|(1<<CGEN_INSN_MEMORY_ACCESS), (1<<MACH_BASE) } },
  { mt_sem_break, "BREAK", MT_INSN_BREAK, { 0, (1<<MACH_BASE) } },
  { mt_sem_iflush, "IFLUSH", MT_INSN_IFLUSH, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_fbcb, "FBCB", MT_INSN_FBCB, { 0, (1<<MACH_MS1)|(1<<MACH_MS1_003) } },
  { mt_sem_mfbcb, "MFBCB", MT_INSN_MFBCB, { 0, (1<<MACH_BASE) } },
  { mt_sem_fbcci, "FBCCI", MT_INSN_FBCCI, { 0, (1<<MACH_BASE) } },
  { mt_sem_fbrci, "FBRCI", MT_INSN_FBRCI, { 0, (1<<MACH_BASE) } },
  { mt_sem_fbcri, "FBCRI", MT_INSN_FBCRI, { 0, (1<<MACH_BASE) } },
  { mt_sem_fbrri, "FBRRI", MT_INSN_FBRRI, { 0, (1<<MACH_BASE) } },
  { mt_sem_mfbcci, "MFBCCI", MT_INSN_MFBCCI, { 0, (1<<MACH_BASE) } },
  { mt_sem_mfbrci, "MFBRCI", MT_INSN_MFBRCI, { 0, (1<<MACH_BASE) } },
  { mt_sem_mfbcri, "MFBCRI", MT_INSN_MFBCRI, { 0, (1<<MACH_BASE) } },
  { mt_sem_mfbrri, "MFBRRI", MT_INSN_MFBRRI, { 0, (1<<MACH_BASE) } },
  { mt_sem_fbcbdr, "FBCBDR", MT_INSN_FBCBDR, { 0, (1<<MACH_BASE) } },
  { mt_sem_rcfbcb, "RCFBCB", MT_INSN_RCFBCB, { 0, (1<<MACH_BASE) } },
  { mt_sem_mrcfbcb, "MRCFBCB", MT_INSN_MRCFBCB, { 0, (1<<MACH_BASE) } },
  { mt_sem_cbcast, "CBCAST", MT_INSN_CBCAST, { 0, (1<<MACH_BASE) } },
  { mt_sem_dupcbcast, "DUPCBCAST", MT_INSN_DUPCBCAST, { 0, (1<<MACH_BASE) } },
  { mt_sem_wfbi, "WFBI", MT_INSN_WFBI, { 0, (1<<MACH_BASE) } },
  { mt_sem_wfb, "WFB", MT_INSN_WFB, { 0, (1<<MACH_BASE) } },
  { mt_sem_rcrisc, "RCRISC", MT_INSN_RCRISC, { 0, (1<<MACH_BASE) } },
  { mt_sem_fbcbinc, "FBCBINC", MT_INSN_FBCBINC, { 0, (1<<MACH_BASE) } },
  { mt_sem_rcxmode, "RCXMODE", MT_INSN_RCXMODE, { 0, (1<<MACH_BASE) } },
  { mt_sem_interleaver, "INTERLEAVER", MT_INSN_INTERLEAVER, { 0, (1<<MACH_BASE) } },
  { mt_sem_wfbinc, "WFBINC", MT_INSN_WFBINC, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_mwfbinc, "MWFBINC", MT_INSN_MWFBINC, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_wfbincr, "WFBINCR", MT_INSN_WFBINCR, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_mwfbincr, "MWFBINCR", MT_INSN_MWFBINCR, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_fbcbincs, "FBCBINCS", MT_INSN_FBCBINCS, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_mfbcbincs, "MFBCBINCS", MT_INSN_MFBCBINCS, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_fbcbincrs, "FBCBINCRS", MT_INSN_FBCBINCRS, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },
  { mt_sem_mfbcbincrs, "MFBCBINCRS", MT_INSN_MFBCBINCRS, { 0, (1<<MACH_MS1_003)|(1<<MACH_MS2) } },

};

// Given a canonical virtual insn id, return the target specific one.

mt_insn_type
mt_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return MT_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return MT_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
mt_extract_sfmt_empty (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_add (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_addi (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_addui (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_nop (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_ldui (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_brlt (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_jmp (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_jal (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_dbnz (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_si (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_reti (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_ldw (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_stw (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);
static void
mt_extract_sfmt_break (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn);

// Fetch & decode instruction
void
mt_scache::decode (mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn)
{
  /* Result of decoder.  */
  MT_INSN_TYPE itype;

  {
    mt_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 24) & (255 << 0)));
      switch (val)
      {
      case 0 :
        if ((entire_insn & 0xff000fff) == 0x0)
          { itype = MT_INSN_ADD; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1 : itype = MT_INSN_ADDI; mt_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 2 :
        if ((entire_insn & 0xff000fff) == 0x2000000)
          { itype = MT_INSN_ADDU; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 : itype = MT_INSN_ADDUI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 :
        if ((entire_insn & 0xff000fff) == 0x4000000)
          { itype = MT_INSN_SUB; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 5 : itype = MT_INSN_SUBI; mt_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 6 :
        if ((entire_insn & 0xff000fff) == 0x6000000)
          { itype = MT_INSN_SUBU; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 : itype = MT_INSN_SUBUI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 :
        if ((entire_insn & 0xff000fff) == 0x8000000)
          { itype = MT_INSN_MUL; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 9 : itype = MT_INSN_MULI; mt_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 :
        if ((entire_insn & 0xff000fff) == 0x10000000)
          { itype = MT_INSN_AND; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 17 : itype = MT_INSN_ANDI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
                  { itype = MT_INSN_NOP; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
                  { itype = MT_INSN_OR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
              { itype = MT_INSN_OR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 19 : itype = MT_INSN_ORI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 20 :
        if ((entire_insn & 0xff000fff) == 0x14000000)
          { itype = MT_INSN_XOR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 21 : itype = MT_INSN_XORI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 22 :
        if ((entire_insn & 0xff000fff) == 0x16000000)
          { itype = MT_INSN_NAND; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 23 : itype = MT_INSN_NANDI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 :
        if ((entire_insn & 0xff000fff) == 0x18000000)
          { itype = MT_INSN_NOR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 25 : itype = MT_INSN_NORI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 26 :
        if ((entire_insn & 0xff000fff) == 0x1a000000)
          { itype = MT_INSN_XNOR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 27 : itype = MT_INSN_XNORI; mt_extract_sfmt_addui (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 29 :
        if ((entire_insn & 0xfff00000) == 0x1d000000)
          { itype = MT_INSN_LDUI; mt_extract_sfmt_ldui (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 32 :
        if ((entire_insn & 0xff000fff) == 0x20000000)
          { itype = MT_INSN_LSL; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 33 : itype = MT_INSN_LSLI; mt_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 34 :
        if ((entire_insn & 0xff000fff) == 0x22000000)
          { itype = MT_INSN_LSR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 35 : itype = MT_INSN_LSRI; mt_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 36 :
        if ((entire_insn & 0xff000fff) == 0x24000000)
          { itype = MT_INSN_ASR; mt_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 37 : itype = MT_INSN_ASRI; mt_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 49 : itype = MT_INSN_BRLT; mt_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 51 : itype = MT_INSN_BRLE; mt_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 53 : itype = MT_INSN_BREQ; mt_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 55 :
        if ((entire_insn & 0xffff0000) == 0x37000000)
          { itype = MT_INSN_JMP; mt_extract_sfmt_jmp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 56 :
        if ((entire_insn & 0xff0f0fff) == 0x38000000)
          { itype = MT_INSN_JAL; mt_extract_sfmt_jal (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 59 : itype = MT_INSN_BRNE; mt_extract_sfmt_brlt (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 61 :
        if ((entire_insn & 0xff0f0000) == 0x3d000000)
          { itype = MT_INSN_DBNZ; mt_extract_sfmt_dbnz (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 65 : itype = MT_INSN_LDW; mt_extract_sfmt_ldw (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 67 : itype = MT_INSN_STW; mt_extract_sfmt_stw (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 96 :
        if ((entire_insn & 0xffffffff) == 0x60000000)
          { itype = MT_INSN_EI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 98 :
        if ((entire_insn & 0xffffffff) == 0x62000000)
          { itype = MT_INSN_DI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 100 :
        if ((entire_insn & 0xffff0fff) == 0x64000000)
          { itype = MT_INSN_SI; mt_extract_sfmt_si (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 102 :
        if ((entire_insn & 0xff0fffff) == 0x66000000)
          { itype = MT_INSN_RETI; mt_extract_sfmt_reti (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 104 :
        if ((entire_insn & 0xffffffff) == 0x68000000)
          { itype = MT_INSN_BREAK; mt_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 106 :
        if ((entire_insn & 0xffffffff) == 0x6a000000)
          { itype = MT_INSN_IFLUSH; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 140 : /* fall through */
      case 141 : /* fall through */
      case 142 : /* fall through */
      case 143 :
        if ((entire_insn & 0xfc00f000) == 0x8c000000)
          { itype = MT_INSN_FBCB; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 144 : /* fall through */
      case 145 : /* fall through */
      case 146 : /* fall through */
      case 147 :
        if ((entire_insn & 0xfc00f000) == 0x90000000)
          { itype = MT_INSN_MFBCB; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 148 : /* fall through */
      case 149 : /* fall through */
      case 150 : /* fall through */
      case 151 : itype = MT_INSN_FBCCI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 152 : /* fall through */
      case 153 : /* fall through */
      case 154 : /* fall through */
      case 155 : itype = MT_INSN_FBRCI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 156 : /* fall through */
      case 157 : /* fall through */
      case 158 : /* fall through */
      case 159 : itype = MT_INSN_FBCRI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 160 : /* fall through */
      case 161 : /* fall through */
      case 162 : /* fall through */
      case 163 : itype = MT_INSN_FBRRI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 164 : /* fall through */
      case 165 : /* fall through */
      case 166 : /* fall through */
      case 167 : itype = MT_INSN_MFBCCI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 168 : /* fall through */
      case 169 : /* fall through */
      case 170 : /* fall through */
      case 171 : itype = MT_INSN_MFBRCI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 172 : /* fall through */
      case 173 : /* fall through */
      case 174 : /* fall through */
      case 175 : itype = MT_INSN_MFBCRI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 176 : /* fall through */
      case 177 : /* fall through */
      case 178 : /* fall through */
      case 179 : itype = MT_INSN_MFBRRI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 180 : /* fall through */
      case 181 : /* fall through */
      case 182 : /* fall through */
      case 183 : itype = MT_INSN_FBCBDR; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 184 : /* fall through */
      case 185 : /* fall through */
      case 186 : /* fall through */
      case 187 :
        if ((entire_insn & 0xfcc08000) == 0xb8000000)
          { itype = MT_INSN_RCFBCB; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 188 : /* fall through */
      case 189 : /* fall through */
      case 190 : /* fall through */
      case 191 :
        if ((entire_insn & 0xfcc08000) == 0xbc000000)
          { itype = MT_INSN_MRCFBCB; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 192 : /* fall through */
      case 193 : /* fall through */
      case 194 : /* fall through */
      case 195 :
        if ((entire_insn & 0xfc000380) == 0xc0000000)
          { itype = MT_INSN_CBCAST; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 196 : /* fall through */
      case 197 : /* fall through */
      case 198 : /* fall through */
      case 199 : itype = MT_INSN_DUPCBCAST; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 200 : /* fall through */
      case 201 : /* fall through */
      case 202 : /* fall through */
      case 203 : itype = MT_INSN_WFBI; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 204 :
        if ((entire_insn & 0xff000040) == 0xcc000000)
          { itype = MT_INSN_WFB; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 208 : /* fall through */
      case 209 : /* fall through */
      case 210 : /* fall through */
      case 211 :
        if ((entire_insn & 0xfc080000) == 0xd0000000)
          { itype = MT_INSN_RCRISC; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 212 : /* fall through */
      case 213 : /* fall through */
      case 214 : /* fall through */
      case 215 : itype = MT_INSN_FBCBINC; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 216 : /* fall through */
      case 217 : /* fall through */
      case 218 : /* fall through */
      case 219 : itype = MT_INSN_RCXMODE; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 220 : /* fall through */
      case 221 : /* fall through */
      case 222 : /* fall through */
      case 223 :
        if ((entire_insn & 0xfc008000) == 0xdc000000)
          { itype = MT_INSN_INTERLEAVER; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 224 : /* fall through */
      case 225 : /* fall through */
      case 226 : /* fall through */
      case 227 : itype = MT_INSN_WFBINC; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 228 : /* fall through */
      case 229 : /* fall through */
      case 230 : /* fall through */
      case 231 : itype = MT_INSN_MWFBINC; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 232 : /* fall through */
      case 233 : /* fall through */
      case 234 : /* fall through */
      case 235 : itype = MT_INSN_WFBINCR; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 236 : /* fall through */
      case 237 : /* fall through */
      case 238 : /* fall through */
      case 239 : itype = MT_INSN_MWFBINCR; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 240 : /* fall through */
      case 241 : /* fall through */
      case 242 : /* fall through */
      case 243 : itype = MT_INSN_FBCBINCS; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 244 : /* fall through */
      case 245 : /* fall through */
      case 246 : /* fall through */
      case 247 : itype = MT_INSN_MFBCBINCS; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 248 : /* fall through */
      case 249 : /* fall through */
      case 250 : /* fall through */
      case 251 :
        if ((entire_insn & 0xfc008000) == 0xf8000000)
          { itype = MT_INSN_FBCBINCRS; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 252 : /* fall through */
      case 253 : /* fall through */
      case 254 : /* fall through */
      case 255 :
        if ((entire_insn & 0xfc008000) == 0xfc000000)
          { itype = MT_INSN_MFBCBINCRS; mt_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = MT_INSN_X_INVALID; mt_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & mt_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
mt_extract_sfmt_empty (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_add (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_addi (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_addui (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_nop (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_ldui (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_brlt (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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

#undef FLD
}

void
mt_extract_sfmt_jmp (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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

#undef FLD
}

void
mt_extract_sfmt_jal (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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

#undef FLD
}

void
mt_extract_sfmt_dbnz (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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

#undef FLD
}

void
mt_extract_sfmt_si (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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

#undef FLD
}

void
mt_extract_sfmt_reti (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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

#undef FLD
}

void
mt_extract_sfmt_ldw (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_stw (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
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
mt_extract_sfmt_break (mt_scache* abuf, mt_cpu* current_cpu, PCADDR pc, mt_insn_word base_insn, mt_insn_word entire_insn){
    mt_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_break)\t"
        << endl;
    }

#undef FLD
}

