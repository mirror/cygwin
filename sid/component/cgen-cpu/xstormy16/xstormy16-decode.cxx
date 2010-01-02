/* Simulator instruction decoder for xstormy16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "xstormy16.h"

using namespace xstormy16; // FIXME: namespace organization still wip


// The instruction descriptor array. 

xstormy16_idesc xstormy16_idesc::idesc_table[XSTORMY16_INSN_SYSCALL + 1] =
{
  { xstormy16_sem_x_invalid, "X_INVALID", XSTORMY16_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE) } },
  { xstormy16_sem_movlmemimm, "MOVLMEMIMM", XSTORMY16_INSN_MOVLMEMIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movhmemimm, "MOVHMEMIMM", XSTORMY16_INSN_MOVHMEMIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movlgrmem, "MOVLGRMEM", XSTORMY16_INSN_MOVLGRMEM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movhgrmem, "MOVHGRMEM", XSTORMY16_INSN_MOVHGRMEM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movlmemgr, "MOVLMEMGR", XSTORMY16_INSN_MOVLMEMGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movhmemgr, "MOVHMEMGR", XSTORMY16_INSN_MOVHMEMGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgri, "MOVGRGRI", XSTORMY16_INSN_MOVGRGRI, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgripostinc, "MOVGRGRIPOSTINC", XSTORMY16_INSN_MOVGRGRIPOSTINC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgripredec, "MOVGRGRIPREDEC", XSTORMY16_INSN_MOVGRGRIPREDEC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrigr, "MOVGRIGR", XSTORMY16_INSN_MOVGRIGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgripostincgr, "MOVGRIPOSTINCGR", XSTORMY16_INSN_MOVGRIPOSTINCGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgripredecgr, "MOVGRIPREDECGR", XSTORMY16_INSN_MOVGRIPREDECGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgrii, "MOVGRGRII", XSTORMY16_INSN_MOVGRGRII, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgriipostinc, "MOVGRGRIIPOSTINC", XSTORMY16_INSN_MOVGRGRIIPOSTINC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgriipredec, "MOVGRGRIIPREDEC", XSTORMY16_INSN_MOVGRGRIIPREDEC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgriigr, "MOVGRIIGR", XSTORMY16_INSN_MOVGRIIGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgriipostincgr, "MOVGRIIPOSTINCGR", XSTORMY16_INSN_MOVGRIIPOSTINCGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgriipredecgr, "MOVGRIIPREDECGR", XSTORMY16_INSN_MOVGRIIPREDECGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movgrgr, "MOVGRGR", XSTORMY16_INSN_MOVGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movwimm8, "MOVWIMM8", XSTORMY16_INSN_MOVWIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movwgrimm8, "MOVWGRIMM8", XSTORMY16_INSN_MOVWGRIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movwgrimm16, "MOVWGRIMM16", XSTORMY16_INSN_MOVWGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movlowgr, "MOVLOWGR", XSTORMY16_INSN_MOVLOWGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movhighgr, "MOVHIGHGR", XSTORMY16_INSN_MOVHIGHGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrgri, "MOVFGRGRI", XSTORMY16_INSN_MOVFGRGRI, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrgripostinc, "MOVFGRGRIPOSTINC", XSTORMY16_INSN_MOVFGRGRIPOSTINC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrgripredec, "MOVFGRGRIPREDEC", XSTORMY16_INSN_MOVFGRGRIPREDEC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrigr, "MOVFGRIGR", XSTORMY16_INSN_MOVFGRIGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgripostincgr, "MOVFGRIPOSTINCGR", XSTORMY16_INSN_MOVFGRIPOSTINCGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgripredecgr, "MOVFGRIPREDECGR", XSTORMY16_INSN_MOVFGRIPREDECGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrgrii, "MOVFGRGRII", XSTORMY16_INSN_MOVFGRGRII, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrgriipostinc, "MOVFGRGRIIPOSTINC", XSTORMY16_INSN_MOVFGRGRIIPOSTINC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgrgriipredec, "MOVFGRGRIIPREDEC", XSTORMY16_INSN_MOVFGRGRIIPREDEC, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgriigr, "MOVFGRIIGR", XSTORMY16_INSN_MOVFGRIIGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgriipostincgr, "MOVFGRIIPOSTINCGR", XSTORMY16_INSN_MOVFGRIIPOSTINCGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_movfgriipredecgr, "MOVFGRIIPREDECGR", XSTORMY16_INSN_MOVFGRIIPREDECGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_maskgrgr, "MASKGRGR", XSTORMY16_INSN_MASKGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_maskgrimm16, "MASKGRIMM16", XSTORMY16_INSN_MASKGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_pushgr, "PUSHGR", XSTORMY16_INSN_PUSHGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_popgr, "POPGR", XSTORMY16_INSN_POPGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_swpn, "SWPN", XSTORMY16_INSN_SWPN, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_swpb, "SWPB", XSTORMY16_INSN_SWPB, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_swpw, "SWPW", XSTORMY16_INSN_SWPW, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_andgrgr, "ANDGRGR", XSTORMY16_INSN_ANDGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_andimm8, "ANDIMM8", XSTORMY16_INSN_ANDIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_andgrimm16, "ANDGRIMM16", XSTORMY16_INSN_ANDGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_orgrgr, "ORGRGR", XSTORMY16_INSN_ORGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_orimm8, "ORIMM8", XSTORMY16_INSN_ORIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_orgrimm16, "ORGRIMM16", XSTORMY16_INSN_ORGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_xorgrgr, "XORGRGR", XSTORMY16_INSN_XORGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_xorimm8, "XORIMM8", XSTORMY16_INSN_XORIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_xorgrimm16, "XORGRIMM16", XSTORMY16_INSN_XORGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_notgr, "NOTGR", XSTORMY16_INSN_NOTGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_addgrgr, "ADDGRGR", XSTORMY16_INSN_ADDGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_addgrimm4, "ADDGRIMM4", XSTORMY16_INSN_ADDGRIMM4, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_addimm8, "ADDIMM8", XSTORMY16_INSN_ADDIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_addgrimm16, "ADDGRIMM16", XSTORMY16_INSN_ADDGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_adcgrgr, "ADCGRGR", XSTORMY16_INSN_ADCGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_adcgrimm4, "ADCGRIMM4", XSTORMY16_INSN_ADCGRIMM4, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_adcimm8, "ADCIMM8", XSTORMY16_INSN_ADCIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_adcgrimm16, "ADCGRIMM16", XSTORMY16_INSN_ADCGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_subgrgr, "SUBGRGR", XSTORMY16_INSN_SUBGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_subgrimm4, "SUBGRIMM4", XSTORMY16_INSN_SUBGRIMM4, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_subimm8, "SUBIMM8", XSTORMY16_INSN_SUBIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_subgrimm16, "SUBGRIMM16", XSTORMY16_INSN_SUBGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_sbcgrgr, "SBCGRGR", XSTORMY16_INSN_SBCGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_sbcgrimm4, "SBCGRIMM4", XSTORMY16_INSN_SBCGRIMM4, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_sbcgrimm8, "SBCGRIMM8", XSTORMY16_INSN_SBCGRIMM8, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_sbcgrimm16, "SBCGRIMM16", XSTORMY16_INSN_SBCGRIMM16, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_incgrimm2, "INCGRIMM2", XSTORMY16_INSN_INCGRIMM2, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_decgrimm2, "DECGRIMM2", XSTORMY16_INSN_DECGRIMM2, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_rrcgrgr, "RRCGRGR", XSTORMY16_INSN_RRCGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_rrcgrimm4, "RRCGRIMM4", XSTORMY16_INSN_RRCGRIMM4, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_rlcgrgr, "RLCGRGR", XSTORMY16_INSN_RLCGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_rlcgrimm4, "RLCGRIMM4", XSTORMY16_INSN_RLCGRIMM4, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_shrgrgr, "SHRGRGR", XSTORMY16_INSN_SHRGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_shrgrimm, "SHRGRIMM", XSTORMY16_INSN_SHRGRIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_shlgrgr, "SHLGRGR", XSTORMY16_INSN_SHLGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_shlgrimm, "SHLGRIMM", XSTORMY16_INSN_SHLGRIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_asrgrgr, "ASRGRGR", XSTORMY16_INSN_ASRGRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_asrgrimm, "ASRGRIMM", XSTORMY16_INSN_ASRGRIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_set1grimm, "SET1GRIMM", XSTORMY16_INSN_SET1GRIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_set1grgr, "SET1GRGR", XSTORMY16_INSN_SET1GRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_set1lmemimm, "SET1LMEMIMM", XSTORMY16_INSN_SET1LMEMIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_set1hmemimm, "SET1HMEMIMM", XSTORMY16_INSN_SET1HMEMIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_clr1grimm, "CLR1GRIMM", XSTORMY16_INSN_CLR1GRIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_clr1grgr, "CLR1GRGR", XSTORMY16_INSN_CLR1GRGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_clr1lmemimm, "CLR1LMEMIMM", XSTORMY16_INSN_CLR1LMEMIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_clr1hmemimm, "CLR1HMEMIMM", XSTORMY16_INSN_CLR1HMEMIMM, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_cbwgr, "CBWGR", XSTORMY16_INSN_CBWGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_revgr, "REVGR", XSTORMY16_INSN_REVGR, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_bccgrgr, "BCCGRGR", XSTORMY16_INSN_BCCGRGR, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bccgrimm8, "BCCGRIMM8", XSTORMY16_INSN_BCCGRIMM8, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bccimm16, "BCCIMM16", XSTORMY16_INSN_BCCIMM16, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bngrimm4, "BNGRIMM4", XSTORMY16_INSN_BNGRIMM4, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bngrgr, "BNGRGR", XSTORMY16_INSN_BNGRGR, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bnlmemimm, "BNLMEMIMM", XSTORMY16_INSN_BNLMEMIMM, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bnhmemimm, "BNHMEMIMM", XSTORMY16_INSN_BNHMEMIMM, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bpgrimm4, "BPGRIMM4", XSTORMY16_INSN_BPGRIMM4, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bpgrgr, "BPGRGR", XSTORMY16_INSN_BPGRGR, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bplmemimm, "BPLMEMIMM", XSTORMY16_INSN_BPLMEMIMM, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bphmemimm, "BPHMEMIMM", XSTORMY16_INSN_BPHMEMIMM, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bcc, "BCC", XSTORMY16_INSN_BCC, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_bgr, "BGR", XSTORMY16_INSN_BGR, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_br, "BR", XSTORMY16_INSN_BR, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_jmp, "JMP", XSTORMY16_INSN_JMP, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_jmpf, "JMPF", XSTORMY16_INSN_JMPF, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_callrgr, "CALLRGR", XSTORMY16_INSN_CALLRGR, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_callrimm, "CALLRIMM", XSTORMY16_INSN_CALLRIMM, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_callgr, "CALLGR", XSTORMY16_INSN_CALLGR, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_callfimm, "CALLFIMM", XSTORMY16_INSN_CALLFIMM, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_icallrgr, "ICALLRGR", XSTORMY16_INSN_ICALLRGR, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_icallgr, "ICALLGR", XSTORMY16_INSN_ICALLGR, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_icallfimm, "ICALLFIMM", XSTORMY16_INSN_ICALLFIMM, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_iret, "IRET", XSTORMY16_INSN_IRET, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_ret, "RET", XSTORMY16_INSN_RET, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE) } },
  { xstormy16_sem_mul, "MUL", XSTORMY16_INSN_MUL, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_div, "DIV", XSTORMY16_INSN_DIV, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_sdiv, "SDIV", XSTORMY16_INSN_SDIV, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_sdivlh, "SDIVLH", XSTORMY16_INSN_SDIVLH, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_divlh, "DIVLH", XSTORMY16_INSN_DIVLH, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_reset, "RESET", XSTORMY16_INSN_RESET, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_nop, "NOP", XSTORMY16_INSN_NOP, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_halt, "HALT", XSTORMY16_INSN_HALT, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_hold, "HOLD", XSTORMY16_INSN_HOLD, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_holdx, "HOLDX", XSTORMY16_INSN_HOLDX, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_brk, "BRK", XSTORMY16_INSN_BRK, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_syscall, "SYSCALL", XSTORMY16_INSN_SYSCALL, { 0, (1<<MACH_BASE) } },

};

// Given a canonical virtual insn id, return the target specific one.

xstormy16_insn_type
xstormy16_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return XSTORMY16_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return XSTORMY16_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
xstormy16_extract_sfmt_empty (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movlmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movhmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movlgrmem (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movhgrmem (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movlmemgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movhmemgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgri (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgripostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgripredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgripostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgripredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgrii (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgriipostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgriipredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgriigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgriipostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgriipredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movwimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movwgrimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movwgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movlowgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrgri (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrgripostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrgripredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgripostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgripredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrgrii (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrgriipostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgrgriipredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgriigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgriipostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_movfgriipredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_maskgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_maskgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_pushgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_popgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_swpn (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_swpw (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_andgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_andimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_andgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_addgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_adcgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_adcgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_adcimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_adcgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_incgrimm2 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_shrgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_shrgrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_set1lmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_set1hmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bccgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bccgrimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bccimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bngrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bngrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bnlmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bnhmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bcc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_bgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_br (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_jmp (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_jmpf (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_callrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_callrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_callgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_callfimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_icallrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_icallgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_icallfimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_iret (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_ret (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_mul (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_sdivlh (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_reset (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);

// Fetch & decode instruction
void
xstormy16_scache::decode (xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn)
{
  /* Result of decoder.  */
  XSTORMY16_INSN_TYPE itype;

  {
    xstormy16_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 21) & (1023 << 1)) | ((insn >> 19) & (1 << 0)));
      switch (val)
      {
      case 0 :
        {
          unsigned int val = (((insn >> 17) & (3 << 3)) | ((insn >> 16) & (7 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_NOP; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_SYSCALL; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_IRET; xstormy16_extract_sfmt_iret (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_RET; xstormy16_extract_sfmt_ret (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_BRK; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 : /* fall through */
          case 9 : /* fall through */
          case 10 : /* fall through */
          case 11 : /* fall through */
          case 12 : /* fall through */
          case 13 : /* fall through */
          case 14 : /* fall through */
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_CALLRGR; xstormy16_extract_sfmt_callrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 16 : /* fall through */
          case 17 : /* fall through */
          case 18 : /* fall through */
          case 19 : /* fall through */
          case 20 : /* fall through */
          case 21 : /* fall through */
          case 22 : /* fall through */
          case 23 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_BGR; xstormy16_extract_sfmt_bgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 24 : /* fall through */
          case 25 : /* fall through */
          case 26 : /* fall through */
          case 27 : /* fall through */
          case 28 : /* fall through */
          case 29 : /* fall through */
          case 30 : /* fall through */
          case 31 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_ICALLRGR; xstormy16_extract_sfmt_icallrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1 :
        {
          unsigned int val = (((insn >> 17) & (3 << 3)) | ((insn >> 16) & (7 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_HALT; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_HOLD; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_HOLDX; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_RESET; xstormy16_extract_sfmt_reset (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 : /* fall through */
          case 9 : /* fall through */
          case 10 : /* fall through */
          case 11 : /* fall through */
          case 12 : /* fall through */
          case 13 : /* fall through */
          case 14 : /* fall through */
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_CALLRGR; xstormy16_extract_sfmt_callrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 16 : /* fall through */
          case 17 : /* fall through */
          case 18 : /* fall through */
          case 19 : /* fall through */
          case 20 : /* fall through */
          case 21 : /* fall through */
          case 22 : /* fall through */
          case 23 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_BGR; xstormy16_extract_sfmt_bgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 24 : /* fall through */
          case 25 : /* fall through */
          case 26 : /* fall through */
          case 27 : /* fall through */
          case 28 : /* fall through */
          case 29 : /* fall through */
          case 30 : /* fall through */
          case 31 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_ICALLRGR; xstormy16_extract_sfmt_icallrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 2 : /* fall through */
      case 3 :
        {
          unsigned int val = (((insn >> 21) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_JMP; xstormy16_extract_sfmt_jmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_ICALLGR; xstormy16_extract_sfmt_icallgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 4 : /* fall through */
      case 5 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_PUSHGR; xstormy16_extract_sfmt_pushgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_POPGR; xstormy16_extract_sfmt_popgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : /* fall through */
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_CALLGR; xstormy16_extract_sfmt_callgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 6 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xc0)
              { itype = XSTORMY16_INSN_DIV; xstormy16_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xd0)
              { itype = XSTORMY16_INSN_MUL; xstormy16_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xe0)
              { itype = XSTORMY16_INSN_DIVLH; xstormy16_extract_sfmt_sdivlh (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 7 :
        {
          unsigned int val = (((insn >> 21) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xc8)
              { itype = XSTORMY16_INSN_SDIV; xstormy16_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0xe8)
              { itype = XSTORMY16_INSN_SDIVLH; xstormy16_extract_sfmt_sdivlh (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 8 : /* fall through */
      case 9 : /* fall through */
      case 10 : /* fall through */
      case 11 : /* fall through */
      case 12 : /* fall through */
      case 13 : /* fall through */
      case 14 : /* fall through */
      case 15 : itype = XSTORMY16_INSN_CALLFIMM; xstormy16_extract_sfmt_callfimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 : /* fall through */
      case 17 : /* fall through */
      case 18 : /* fall through */
      case 19 : /* fall through */
      case 20 : /* fall through */
      case 21 : /* fall through */
      case 22 : /* fall through */
      case 23 : itype = XSTORMY16_INSN_JMPF; xstormy16_extract_sfmt_jmpf (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 : /* fall through */
      case 25 : /* fall through */
      case 26 : /* fall through */
      case 27 : /* fall through */
      case 28 : /* fall through */
      case 29 : /* fall through */
      case 30 : /* fall through */
      case 31 : itype = XSTORMY16_INSN_ICALLFIMM; xstormy16_extract_sfmt_icallfimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 32 : /* fall through */
      case 33 : /* fall through */
      case 34 : /* fall through */
      case 35 : /* fall through */
      case 36 : /* fall through */
      case 37 : /* fall through */
      case 38 : /* fall through */
      case 39 :
        if ((entire_insn & 0xff00f000) == 0x4000000)
          { itype = XSTORMY16_INSN_BNGRIMM4; xstormy16_extract_sfmt_bngrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 40 : /* fall through */
      case 41 : /* fall through */
      case 42 : /* fall through */
      case 43 : /* fall through */
      case 44 : /* fall through */
      case 45 : /* fall through */
      case 46 : /* fall through */
      case 47 :
        if ((entire_insn & 0xff00f000) == 0x5000000)
          { itype = XSTORMY16_INSN_BPGRIMM4; xstormy16_extract_sfmt_bngrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 48 : /* fall through */
      case 49 : /* fall through */
      case 50 : /* fall through */
      case 51 : /* fall through */
      case 52 : /* fall through */
      case 53 : /* fall through */
      case 54 : /* fall through */
      case 55 :
        if ((entire_insn & 0xff00f000) == 0x6000000)
          { itype = XSTORMY16_INSN_BNGRGR; xstormy16_extract_sfmt_bngrgr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 56 : /* fall through */
      case 57 : /* fall through */
      case 58 : /* fall through */
      case 59 : /* fall through */
      case 60 : /* fall through */
      case 61 : /* fall through */
      case 62 : /* fall through */
      case 63 :
        if ((entire_insn & 0xff00f000) == 0x7000000)
          { itype = XSTORMY16_INSN_BPGRGR; xstormy16_extract_sfmt_bngrgr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 64 : /* fall through */
      case 65 : /* fall through */
      case 66 : /* fall through */
      case 67 : /* fall through */
      case 68 : /* fall through */
      case 69 : /* fall through */
      case 70 : /* fall through */
      case 71 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_CLR1GRIMM; xstormy16_extract_sfmt_addgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 72 : /* fall through */
      case 73 : /* fall through */
      case 74 : /* fall through */
      case 75 : /* fall through */
      case 76 : /* fall through */
      case 77 : /* fall through */
      case 78 : /* fall through */
      case 79 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SET1GRIMM; xstormy16_extract_sfmt_addgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 80 : /* fall through */
      case 81 : /* fall through */
      case 82 : /* fall through */
      case 83 : /* fall through */
      case 84 : /* fall through */
      case 85 : /* fall through */
      case 86 : /* fall through */
      case 87 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_CLR1GRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 88 : /* fall through */
      case 89 : /* fall through */
      case 90 : /* fall through */
      case 91 : /* fall through */
      case 92 : /* fall through */
      case 93 : /* fall through */
      case 94 : /* fall through */
      case 95 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SET1GRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 104 : /* fall through */
      case 105 : /* fall through */
      case 106 : /* fall through */
      case 107 : /* fall through */
      case 108 : /* fall through */
      case 109 : /* fall through */
      case 110 : /* fall through */
      case 111 : itype = XSTORMY16_INSN_BCCGRGR; xstormy16_extract_sfmt_bccgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 128 : /* fall through */
      case 129 : /* fall through */
      case 130 : /* fall through */
      case 131 : /* fall through */
      case 132 : /* fall through */
      case 133 : /* fall through */
      case 134 : /* fall through */
      case 135 : /* fall through */
      case 136 : /* fall through */
      case 137 : /* fall through */
      case 138 : /* fall through */
      case 139 : /* fall through */
      case 140 : /* fall through */
      case 141 : /* fall through */
      case 142 : /* fall through */
      case 143 : /* fall through */
      case 144 : /* fall through */
      case 145 : /* fall through */
      case 146 : /* fall through */
      case 147 : /* fall through */
      case 148 : /* fall through */
      case 149 : /* fall through */
      case 150 : /* fall through */
      case 151 : /* fall through */
      case 152 : /* fall through */
      case 153 : /* fall through */
      case 154 : /* fall through */
      case 155 : /* fall through */
      case 156 : /* fall through */
      case 157 : /* fall through */
      case 158 : /* fall through */
      case 159 : /* fall through */
      case 160 : /* fall through */
      case 161 : /* fall through */
      case 162 : /* fall through */
      case 163 : /* fall through */
      case 164 : /* fall through */
      case 165 : /* fall through */
      case 166 : /* fall through */
      case 167 : /* fall through */
      case 168 : /* fall through */
      case 169 : /* fall through */
      case 170 : /* fall through */
      case 171 : /* fall through */
      case 172 : /* fall through */
      case 173 : /* fall through */
      case 174 : /* fall through */
      case 175 : /* fall through */
      case 176 : /* fall through */
      case 177 : /* fall through */
      case 178 : /* fall through */
      case 179 : /* fall through */
      case 180 : /* fall through */
      case 181 : /* fall through */
      case 182 : /* fall through */
      case 183 : /* fall through */
      case 184 : /* fall through */
      case 185 : /* fall through */
      case 186 : /* fall through */
      case 187 : /* fall through */
      case 188 : /* fall through */
      case 189 : /* fall through */
      case 190 : /* fall through */
      case 191 : /* fall through */
      case 192 : /* fall through */
      case 193 : /* fall through */
      case 194 : /* fall through */
      case 195 : /* fall through */
      case 196 : /* fall through */
      case 197 : /* fall through */
      case 198 : /* fall through */
      case 199 : /* fall through */
      case 200 : /* fall through */
      case 201 : /* fall through */
      case 202 : /* fall through */
      case 203 : /* fall through */
      case 204 : /* fall through */
      case 205 : /* fall through */
      case 206 : /* fall through */
      case 207 : /* fall through */
      case 208 : /* fall through */
      case 209 : /* fall through */
      case 210 : /* fall through */
      case 211 : /* fall through */
      case 212 : /* fall through */
      case 213 : /* fall through */
      case 214 : /* fall through */
      case 215 : /* fall through */
      case 216 : /* fall through */
      case 217 : /* fall through */
      case 218 : /* fall through */
      case 219 : /* fall through */
      case 220 : /* fall through */
      case 221 : /* fall through */
      case 222 : /* fall through */
      case 223 : /* fall through */
      case 224 : /* fall through */
      case 225 : /* fall through */
      case 226 : /* fall through */
      case 227 : /* fall through */
      case 228 : /* fall through */
      case 229 : /* fall through */
      case 230 : /* fall through */
      case 231 : /* fall through */
      case 232 : /* fall through */
      case 233 : /* fall through */
      case 234 : /* fall through */
      case 235 : /* fall through */
      case 236 : /* fall through */
      case 237 : /* fall through */
      case 238 : /* fall through */
      case 239 : /* fall through */
      case 240 : /* fall through */
      case 241 : /* fall through */
      case 242 : /* fall through */
      case 243 : /* fall through */
      case 244 : /* fall through */
      case 245 : /* fall through */
      case 246 : /* fall through */
      case 247 : /* fall through */
      case 248 : /* fall through */
      case 249 : /* fall through */
      case 250 : /* fall through */
      case 251 : /* fall through */
      case 252 : /* fall through */
      case 253 : /* fall through */
      case 254 : /* fall through */
      case 255 :
        {
          unsigned int val = (((insn >> 16) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_BR; xstormy16_extract_sfmt_br (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_CALLRIMM; xstormy16_extract_sfmt_callrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 256 : /* fall through */
      case 257 : /* fall through */
      case 258 : /* fall through */
      case 259 : /* fall through */
      case 260 : /* fall through */
      case 261 : /* fall through */
      case 262 : /* fall through */
      case 263 : /* fall through */
      case 272 : /* fall through */
      case 273 : /* fall through */
      case 274 : /* fall through */
      case 275 : /* fall through */
      case 276 : /* fall through */
      case 277 : /* fall through */
      case 278 : /* fall through */
      case 279 : /* fall through */
      case 288 : /* fall through */
      case 289 : /* fall through */
      case 290 : /* fall through */
      case 291 : /* fall through */
      case 292 : /* fall through */
      case 293 : /* fall through */
      case 294 : /* fall through */
      case 295 : /* fall through */
      case 304 : /* fall through */
      case 305 : /* fall through */
      case 306 : /* fall through */
      case 307 : /* fall through */
      case 308 : /* fall through */
      case 309 : /* fall through */
      case 310 : /* fall through */
      case 311 : /* fall through */
      case 320 : /* fall through */
      case 321 : /* fall through */
      case 322 : /* fall through */
      case 323 : /* fall through */
      case 324 : /* fall through */
      case 325 : /* fall through */
      case 326 : /* fall through */
      case 327 : /* fall through */
      case 336 : /* fall through */
      case 337 : /* fall through */
      case 338 : /* fall through */
      case 339 : /* fall through */
      case 340 : /* fall through */
      case 341 : /* fall through */
      case 342 : /* fall through */
      case 343 : /* fall through */
      case 352 : /* fall through */
      case 353 : /* fall through */
      case 354 : /* fall through */
      case 355 : /* fall through */
      case 356 : /* fall through */
      case 357 : /* fall through */
      case 358 : /* fall through */
      case 359 : /* fall through */
      case 368 : /* fall through */
      case 369 : /* fall through */
      case 370 : /* fall through */
      case 371 : /* fall through */
      case 372 : /* fall through */
      case 373 : /* fall through */
      case 374 : /* fall through */
      case 375 : itype = XSTORMY16_INSN_BCCGRIMM8; xstormy16_extract_sfmt_bccgrimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 264 : /* fall through */
      case 265 : /* fall through */
      case 266 : /* fall through */
      case 267 : /* fall through */
      case 268 : /* fall through */
      case 269 : /* fall through */
      case 270 : /* fall through */
      case 271 : /* fall through */
      case 280 : /* fall through */
      case 281 : /* fall through */
      case 282 : /* fall through */
      case 283 : /* fall through */
      case 284 : /* fall through */
      case 285 : /* fall through */
      case 286 : /* fall through */
      case 287 : /* fall through */
      case 296 : /* fall through */
      case 297 : /* fall through */
      case 298 : /* fall through */
      case 299 : /* fall through */
      case 300 : /* fall through */
      case 301 : /* fall through */
      case 302 : /* fall through */
      case 303 : /* fall through */
      case 312 : /* fall through */
      case 313 : /* fall through */
      case 314 : /* fall through */
      case 315 : /* fall through */
      case 316 : /* fall through */
      case 317 : /* fall through */
      case 318 : /* fall through */
      case 319 : /* fall through */
      case 328 : /* fall through */
      case 329 : /* fall through */
      case 330 : /* fall through */
      case 331 : /* fall through */
      case 332 : /* fall through */
      case 333 : /* fall through */
      case 334 : /* fall through */
      case 335 : /* fall through */
      case 344 : /* fall through */
      case 345 : /* fall through */
      case 346 : /* fall through */
      case 347 : /* fall through */
      case 348 : /* fall through */
      case 349 : /* fall through */
      case 350 : /* fall through */
      case 351 : /* fall through */
      case 360 : /* fall through */
      case 361 : /* fall through */
      case 362 : /* fall through */
      case 363 : /* fall through */
      case 364 : /* fall through */
      case 365 : /* fall through */
      case 366 : /* fall through */
      case 367 : /* fall through */
      case 376 : /* fall through */
      case 377 : /* fall through */
      case 378 : /* fall through */
      case 379 : /* fall through */
      case 380 : /* fall through */
      case 381 : /* fall through */
      case 382 : /* fall through */
      case 383 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVWGRIMM8; xstormy16_extract_sfmt_movwgrimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 384 : /* fall through */
      case 385 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_INCGRIMM2; xstormy16_extract_sfmt_incgrimm2 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 386 : /* fall through */
      case 387 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_DECGRIMM2; xstormy16_extract_sfmt_incgrimm2 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 388 : /* fall through */
      case 389 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_SWPB; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_SWPN; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_CBWGR; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_NOTGR; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 390 : /* fall through */
      case 391 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_MOVLOWGR; xstormy16_extract_sfmt_movlowgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_MOVHIGHGR; xstormy16_extract_sfmt_movlowgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = XSTORMY16_INSN_MASKGRIMM16; xstormy16_extract_sfmt_maskgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = XSTORMY16_INSN_REVGR; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 392 : /* fall through */
      case 393 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_ANDGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_ORGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = XSTORMY16_INSN_XORGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 : itype = XSTORMY16_INSN_MOVWGRIMM16; xstormy16_extract_sfmt_movwgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 394 : /* fall through */
      case 395 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_ADDGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_ADCGRIMM16; xstormy16_extract_sfmt_adcgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = XSTORMY16_INSN_SUBGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 : itype = XSTORMY16_INSN_SBCGRIMM16; xstormy16_extract_sfmt_adcgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 400 : /* fall through */
      case 401 : /* fall through */
      case 402 : /* fall through */
      case 403 : /* fall through */
      case 404 : /* fall through */
      case 405 : /* fall through */
      case 406 : /* fall through */
      case 407 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SWPW; xstormy16_extract_sfmt_swpw (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 408 : /* fall through */
      case 409 : /* fall through */
      case 410 : /* fall through */
      case 411 : /* fall through */
      case 412 : /* fall through */
      case 413 : /* fall through */
      case 414 : /* fall through */
      case 415 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MASKGRGR; xstormy16_extract_sfmt_maskgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 432 : /* fall through */
      case 433 : /* fall through */
      case 434 : /* fall through */
      case 435 : /* fall through */
      case 436 : /* fall through */
      case 437 : /* fall through */
      case 438 : /* fall through */
      case 439 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ASRGRGR; xstormy16_extract_sfmt_shrgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 440 : /* fall through */
      case 441 : /* fall through */
      case 442 : /* fall through */
      case 443 : /* fall through */
      case 444 : /* fall through */
      case 445 : /* fall through */
      case 446 : /* fall through */
      case 447 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ASRGRIMM; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 448 : /* fall through */
      case 449 : /* fall through */
      case 450 : /* fall through */
      case 451 : /* fall through */
      case 452 : /* fall through */
      case 453 : /* fall through */
      case 454 : /* fall through */
      case 455 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_RRCGRGR; xstormy16_extract_sfmt_adcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 456 : /* fall through */
      case 457 : /* fall through */
      case 458 : /* fall through */
      case 459 : /* fall through */
      case 460 : /* fall through */
      case 461 : /* fall through */
      case 462 : /* fall through */
      case 463 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_RRCGRIMM4; xstormy16_extract_sfmt_adcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 464 : /* fall through */
      case 465 : /* fall through */
      case 466 : /* fall through */
      case 467 : /* fall through */
      case 468 : /* fall through */
      case 469 : /* fall through */
      case 470 : /* fall through */
      case 471 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_RLCGRGR; xstormy16_extract_sfmt_adcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 472 : /* fall through */
      case 473 : /* fall through */
      case 474 : /* fall through */
      case 475 : /* fall through */
      case 476 : /* fall through */
      case 477 : /* fall through */
      case 478 : /* fall through */
      case 479 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_RLCGRIMM4; xstormy16_extract_sfmt_adcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 480 : /* fall through */
      case 481 : /* fall through */
      case 482 : /* fall through */
      case 483 : /* fall through */
      case 484 : /* fall through */
      case 485 : /* fall through */
      case 486 : /* fall through */
      case 487 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SHRGRGR; xstormy16_extract_sfmt_shrgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 488 : /* fall through */
      case 489 : /* fall through */
      case 490 : /* fall through */
      case 491 : /* fall through */
      case 492 : /* fall through */
      case 493 : /* fall through */
      case 494 : /* fall through */
      case 495 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SHRGRIMM; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 496 : /* fall through */
      case 497 : /* fall through */
      case 498 : /* fall through */
      case 499 : /* fall through */
      case 500 : /* fall through */
      case 501 : /* fall through */
      case 502 : /* fall through */
      case 503 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SHLGRGR; xstormy16_extract_sfmt_shrgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 504 : /* fall through */
      case 505 : /* fall through */
      case 506 : /* fall through */
      case 507 : /* fall through */
      case 508 : /* fall through */
      case 509 : /* fall through */
      case 510 : /* fall through */
      case 511 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SHLGRIMM; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 512 : /* fall through */
      case 513 : /* fall through */
      case 514 : /* fall through */
      case 515 : /* fall through */
      case 516 : /* fall through */
      case 517 : /* fall through */
      case 518 : /* fall through */
      case 519 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ANDGRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 520 : /* fall through */
      case 521 : /* fall through */
      case 522 : /* fall through */
      case 523 : /* fall through */
      case 524 : /* fall through */
      case 525 : /* fall through */
      case 526 : /* fall through */
      case 527 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ANDIMM8; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 528 : /* fall through */
      case 529 : /* fall through */
      case 530 : /* fall through */
      case 531 : /* fall through */
      case 532 : /* fall through */
      case 533 : /* fall through */
      case 534 : /* fall through */
      case 535 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ORGRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 536 : /* fall through */
      case 537 : /* fall through */
      case 538 : /* fall through */
      case 539 : /* fall through */
      case 540 : /* fall through */
      case 541 : /* fall through */
      case 542 : /* fall through */
      case 543 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ORIMM8; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 544 : /* fall through */
      case 545 : /* fall through */
      case 546 : /* fall through */
      case 547 : /* fall through */
      case 548 : /* fall through */
      case 549 : /* fall through */
      case 550 : /* fall through */
      case 551 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_XORGRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 552 : /* fall through */
      case 553 : /* fall through */
      case 554 : /* fall through */
      case 555 : /* fall through */
      case 556 : /* fall through */
      case 557 : /* fall through */
      case 558 : /* fall through */
      case 559 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_XORIMM8; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 560 : /* fall through */
      case 561 : /* fall through */
      case 562 : /* fall through */
      case 563 : /* fall through */
      case 564 : /* fall through */
      case 565 : /* fall through */
      case 566 : /* fall through */
      case 567 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRGR; xstormy16_extract_sfmt_movgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 568 : /* fall through */
      case 569 : /* fall through */
      case 570 : /* fall through */
      case 571 : /* fall through */
      case 572 : /* fall through */
      case 573 : /* fall through */
      case 574 : /* fall through */
      case 575 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVWIMM8; xstormy16_extract_sfmt_movwimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 584 : /* fall through */
      case 585 : /* fall through */
      case 586 : /* fall through */
      case 587 : /* fall through */
      case 588 : /* fall through */
      case 589 : /* fall through */
      case 590 : /* fall through */
      case 591 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ADDGRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 600 : /* fall through */
      case 601 : /* fall through */
      case 602 : /* fall through */
      case 603 : /* fall through */
      case 604 : /* fall through */
      case 605 : /* fall through */
      case 606 : /* fall through */
      case 607 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ADCGRGR; xstormy16_extract_sfmt_adcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 616 : /* fall through */
      case 617 : /* fall through */
      case 618 : /* fall through */
      case 619 : /* fall through */
      case 620 : /* fall through */
      case 621 : /* fall through */
      case 622 : /* fall through */
      case 623 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SUBGRGR; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 632 : /* fall through */
      case 633 : /* fall through */
      case 634 : /* fall through */
      case 635 : /* fall through */
      case 636 : /* fall through */
      case 637 : /* fall through */
      case 638 : /* fall through */
      case 639 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SBCGRGR; xstormy16_extract_sfmt_adcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 648 : /* fall through */
      case 649 : /* fall through */
      case 650 : /* fall through */
      case 651 : /* fall through */
      case 652 : /* fall through */
      case 653 : /* fall through */
      case 654 : /* fall through */
      case 655 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ADDGRIMM4; xstormy16_extract_sfmt_addgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 664 : /* fall through */
      case 665 : /* fall through */
      case 666 : /* fall through */
      case 667 : /* fall through */
      case 668 : /* fall through */
      case 669 : /* fall through */
      case 670 : /* fall through */
      case 671 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ADCGRIMM4; xstormy16_extract_sfmt_adcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 680 : /* fall through */
      case 681 : /* fall through */
      case 682 : /* fall through */
      case 683 : /* fall through */
      case 684 : /* fall through */
      case 685 : /* fall through */
      case 686 : /* fall through */
      case 687 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SUBGRIMM4; xstormy16_extract_sfmt_addgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 696 : /* fall through */
      case 697 : /* fall through */
      case 698 : /* fall through */
      case 699 : /* fall through */
      case 700 : /* fall through */
      case 701 : /* fall through */
      case 702 : /* fall through */
      case 703 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SBCGRIMM4; xstormy16_extract_sfmt_adcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 712 : /* fall through */
      case 713 : /* fall through */
      case 714 : /* fall through */
      case 715 : /* fall through */
      case 716 : /* fall through */
      case 717 : /* fall through */
      case 718 : /* fall through */
      case 719 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ADDIMM8; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 728 : /* fall through */
      case 729 : /* fall through */
      case 730 : /* fall through */
      case 731 : /* fall through */
      case 732 : /* fall through */
      case 733 : /* fall through */
      case 734 : /* fall through */
      case 735 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_ADCIMM8; xstormy16_extract_sfmt_adcimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 744 : /* fall through */
      case 745 : /* fall through */
      case 746 : /* fall through */
      case 747 : /* fall through */
      case 748 : /* fall through */
      case 749 : /* fall through */
      case 750 : /* fall through */
      case 751 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SUBIMM8; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 760 : /* fall through */
      case 761 : /* fall through */
      case 762 : /* fall through */
      case 763 : /* fall through */
      case 764 : /* fall through */
      case 765 : /* fall through */
      case 766 : /* fall through */
      case 767 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SBCGRIMM8; xstormy16_extract_sfmt_adcimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 768 : /* fall through */
      case 770 : /* fall through */
      case 772 : /* fall through */
      case 774 : /* fall through */
      case 776 : /* fall through */
      case 778 : /* fall through */
      case 780 : /* fall through */
      case 782 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRGRIPOSTINC; xstormy16_extract_sfmt_movgrgripostinc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 769 : /* fall through */
      case 771 : /* fall through */
      case 773 : /* fall through */
      case 775 : /* fall through */
      case 777 : /* fall through */
      case 779 : /* fall through */
      case 781 : /* fall through */
      case 783 :
        if ((entire_insn & 0xfe08f000) == 0x60080000)
          { itype = XSTORMY16_INSN_MOVGRGRIIPOSTINC; xstormy16_extract_sfmt_movgrgriipostinc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 784 : /* fall through */
      case 786 : /* fall through */
      case 788 : /* fall through */
      case 790 : /* fall through */
      case 792 : /* fall through */
      case 794 : /* fall through */
      case 796 : /* fall through */
      case 798 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRIPOSTINCGR; xstormy16_extract_sfmt_movgripostincgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 785 : /* fall through */
      case 787 : /* fall through */
      case 789 : /* fall through */
      case 791 : /* fall through */
      case 793 : /* fall through */
      case 795 : /* fall through */
      case 797 : /* fall through */
      case 799 :
        if ((entire_insn & 0xfe08f000) == 0x62080000)
          { itype = XSTORMY16_INSN_MOVGRIIPOSTINCGR; xstormy16_extract_sfmt_movgriipostincgr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 800 : /* fall through */
      case 802 : /* fall through */
      case 804 : /* fall through */
      case 806 : /* fall through */
      case 808 : /* fall through */
      case 810 : /* fall through */
      case 812 : /* fall through */
      case 814 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVFGRGRIPOSTINC; xstormy16_extract_sfmt_movfgrgripostinc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 801 : /* fall through */
      case 803 : /* fall through */
      case 805 : /* fall through */
      case 807 : /* fall through */
      case 809 : /* fall through */
      case 811 : /* fall through */
      case 813 : /* fall through */
      case 815 :
        if ((entire_insn & 0xfe088000) == 0x64080000)
          { itype = XSTORMY16_INSN_MOVFGRGRIIPOSTINC; xstormy16_extract_sfmt_movfgrgriipostinc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 816 : /* fall through */
      case 818 : /* fall through */
      case 820 : /* fall through */
      case 822 : /* fall through */
      case 824 : /* fall through */
      case 826 : /* fall through */
      case 828 : /* fall through */
      case 830 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVFGRIPOSTINCGR; xstormy16_extract_sfmt_movfgripostincgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 817 : /* fall through */
      case 819 : /* fall through */
      case 821 : /* fall through */
      case 823 : /* fall through */
      case 825 : /* fall through */
      case 827 : /* fall through */
      case 829 : /* fall through */
      case 831 :
        if ((entire_insn & 0xfe088000) == 0x66080000)
          { itype = XSTORMY16_INSN_MOVFGRIIPOSTINCGR; xstormy16_extract_sfmt_movfgriipostincgr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 832 : /* fall through */
      case 834 : /* fall through */
      case 836 : /* fall through */
      case 838 : /* fall through */
      case 840 : /* fall through */
      case 842 : /* fall through */
      case 844 : /* fall through */
      case 846 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRGRIPREDEC; xstormy16_extract_sfmt_movgrgripredec (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 833 : /* fall through */
      case 835 : /* fall through */
      case 837 : /* fall through */
      case 839 : /* fall through */
      case 841 : /* fall through */
      case 843 : /* fall through */
      case 845 : /* fall through */
      case 847 :
        if ((entire_insn & 0xfe08f000) == 0x68080000)
          { itype = XSTORMY16_INSN_MOVGRGRIIPREDEC; xstormy16_extract_sfmt_movgrgriipredec (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 848 : /* fall through */
      case 850 : /* fall through */
      case 852 : /* fall through */
      case 854 : /* fall through */
      case 856 : /* fall through */
      case 858 : /* fall through */
      case 860 : /* fall through */
      case 862 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRIPREDECGR; xstormy16_extract_sfmt_movgripredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 849 : /* fall through */
      case 851 : /* fall through */
      case 853 : /* fall through */
      case 855 : /* fall through */
      case 857 : /* fall through */
      case 859 : /* fall through */
      case 861 : /* fall through */
      case 863 :
        if ((entire_insn & 0xfe08f000) == 0x6a080000)
          { itype = XSTORMY16_INSN_MOVGRIIPREDECGR; xstormy16_extract_sfmt_movgriipredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 864 : /* fall through */
      case 866 : /* fall through */
      case 868 : /* fall through */
      case 870 : /* fall through */
      case 872 : /* fall through */
      case 874 : /* fall through */
      case 876 : /* fall through */
      case 878 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVFGRGRIPREDEC; xstormy16_extract_sfmt_movfgrgripredec (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 865 : /* fall through */
      case 867 : /* fall through */
      case 869 : /* fall through */
      case 871 : /* fall through */
      case 873 : /* fall through */
      case 875 : /* fall through */
      case 877 : /* fall through */
      case 879 :
        if ((entire_insn & 0xfe088000) == 0x6c080000)
          { itype = XSTORMY16_INSN_MOVFGRGRIIPREDEC; xstormy16_extract_sfmt_movfgrgriipredec (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 880 : /* fall through */
      case 882 : /* fall through */
      case 884 : /* fall through */
      case 886 : /* fall through */
      case 888 : /* fall through */
      case 890 : /* fall through */
      case 892 : /* fall through */
      case 894 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVFGRIPREDECGR; xstormy16_extract_sfmt_movfgripredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 881 : /* fall through */
      case 883 : /* fall through */
      case 885 : /* fall through */
      case 887 : /* fall through */
      case 889 : /* fall through */
      case 891 : /* fall through */
      case 893 : /* fall through */
      case 895 :
        if ((entire_insn & 0xfe088000) == 0x6e080000)
          { itype = XSTORMY16_INSN_MOVFGRIIPREDECGR; xstormy16_extract_sfmt_movfgriipredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 896 : /* fall through */
      case 898 : /* fall through */
      case 900 : /* fall through */
      case 902 : /* fall through */
      case 904 : /* fall through */
      case 906 : /* fall through */
      case 908 : /* fall through */
      case 910 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRGRI; xstormy16_extract_sfmt_movgrgri (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 897 : /* fall through */
      case 899 : /* fall through */
      case 901 : /* fall through */
      case 903 : /* fall through */
      case 905 : /* fall through */
      case 907 : /* fall through */
      case 909 : /* fall through */
      case 911 :
        if ((entire_insn & 0xfe08f000) == 0x70080000)
          { itype = XSTORMY16_INSN_MOVGRGRII; xstormy16_extract_sfmt_movgrgrii (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 912 : /* fall through */
      case 914 : /* fall through */
      case 916 : /* fall through */
      case 918 : /* fall through */
      case 920 : /* fall through */
      case 922 : /* fall through */
      case 924 : /* fall through */
      case 926 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVGRIGR; xstormy16_extract_sfmt_movgrigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 913 : /* fall through */
      case 915 : /* fall through */
      case 917 : /* fall through */
      case 919 : /* fall through */
      case 921 : /* fall through */
      case 923 : /* fall through */
      case 925 : /* fall through */
      case 927 :
        if ((entire_insn & 0xfe08f000) == 0x72080000)
          { itype = XSTORMY16_INSN_MOVGRIIGR; xstormy16_extract_sfmt_movgriigr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 928 : /* fall through */
      case 930 : /* fall through */
      case 932 : /* fall through */
      case 934 : /* fall through */
      case 936 : /* fall through */
      case 938 : /* fall through */
      case 940 : /* fall through */
      case 942 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVFGRGRI; xstormy16_extract_sfmt_movfgrgri (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 929 : /* fall through */
      case 931 : /* fall through */
      case 933 : /* fall through */
      case 935 : /* fall through */
      case 937 : /* fall through */
      case 939 : /* fall through */
      case 941 : /* fall through */
      case 943 :
        if ((entire_insn & 0xfe088000) == 0x74080000)
          { itype = XSTORMY16_INSN_MOVFGRGRII; xstormy16_extract_sfmt_movfgrgrii (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 944 : /* fall through */
      case 946 : /* fall through */
      case 948 : /* fall through */
      case 950 : /* fall through */
      case 952 : /* fall through */
      case 954 : /* fall through */
      case 956 : /* fall through */
      case 958 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVFGRIGR; xstormy16_extract_sfmt_movfgrigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 945 : /* fall through */
      case 947 : /* fall through */
      case 949 : /* fall through */
      case 951 : /* fall through */
      case 953 : /* fall through */
      case 955 : /* fall through */
      case 957 : /* fall through */
      case 959 :
        if ((entire_insn & 0xfe088000) == 0x76080000)
          { itype = XSTORMY16_INSN_MOVFGRIIGR; xstormy16_extract_sfmt_movfgriigr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 960 : /* fall through */
      case 961 : /* fall through */
      case 962 : /* fall through */
      case 963 : /* fall through */
      case 964 : /* fall through */
      case 965 : /* fall through */
      case 966 : /* fall through */
      case 967 : /* fall through */
      case 968 : /* fall through */
      case 969 : /* fall through */
      case 970 : /* fall through */
      case 971 : /* fall through */
      case 972 : /* fall through */
      case 973 : /* fall through */
      case 974 : /* fall through */
      case 975 : itype = XSTORMY16_INSN_MOVLMEMIMM; xstormy16_extract_sfmt_movlmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 976 : /* fall through */
      case 977 : /* fall through */
      case 978 : /* fall through */
      case 979 : /* fall through */
      case 980 : /* fall through */
      case 981 : /* fall through */
      case 982 : /* fall through */
      case 983 : /* fall through */
      case 984 : /* fall through */
      case 985 : /* fall through */
      case 986 : /* fall through */
      case 987 : /* fall through */
      case 988 : /* fall through */
      case 989 : /* fall through */
      case 990 : /* fall through */
      case 991 : itype = XSTORMY16_INSN_MOVHMEMIMM; xstormy16_extract_sfmt_movhmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 992 : /* fall through */
      case 993 : /* fall through */
      case 994 : /* fall through */
      case 995 : /* fall through */
      case 996 : /* fall through */
      case 997 : /* fall through */
      case 998 : /* fall through */
      case 999 :
        if ((entire_insn & 0xff008000) == 0x7c000000)
          { itype = XSTORMY16_INSN_BNLMEMIMM; xstormy16_extract_sfmt_bnlmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1000 : /* fall through */
      case 1001 : /* fall through */
      case 1002 : /* fall through */
      case 1003 : /* fall through */
      case 1004 : /* fall through */
      case 1005 : /* fall through */
      case 1006 : /* fall through */
      case 1007 :
        if ((entire_insn & 0xff008000) == 0x7d000000)
          { itype = XSTORMY16_INSN_BPLMEMIMM; xstormy16_extract_sfmt_bnlmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1008 : /* fall through */
      case 1009 : /* fall through */
      case 1010 : /* fall through */
      case 1011 : /* fall through */
      case 1012 : /* fall through */
      case 1013 : /* fall through */
      case 1014 : /* fall through */
      case 1015 :
        if ((entire_insn & 0xff008000) == 0x7e000000)
          { itype = XSTORMY16_INSN_BNHMEMIMM; xstormy16_extract_sfmt_bnhmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1016 : /* fall through */
      case 1017 : /* fall through */
      case 1018 : /* fall through */
      case 1019 : /* fall through */
      case 1020 : /* fall through */
      case 1021 : /* fall through */
      case 1022 : /* fall through */
      case 1023 :
        if ((entire_insn & 0xff008000) == 0x7f000000)
          { itype = XSTORMY16_INSN_BPHMEMIMM; xstormy16_extract_sfmt_bnhmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1024 : /* fall through */
      case 1025 : /* fall through */
      case 1026 : /* fall through */
      case 1027 : /* fall through */
      case 1028 : /* fall through */
      case 1029 : /* fall through */
      case 1030 : /* fall through */
      case 1031 : /* fall through */
      case 1032 : /* fall through */
      case 1033 : /* fall through */
      case 1034 : /* fall through */
      case 1035 : /* fall through */
      case 1036 : /* fall through */
      case 1037 : /* fall through */
      case 1038 : /* fall through */
      case 1039 : /* fall through */
      case 1040 : /* fall through */
      case 1041 : /* fall through */
      case 1042 : /* fall through */
      case 1043 : /* fall through */
      case 1044 : /* fall through */
      case 1045 : /* fall through */
      case 1046 : /* fall through */
      case 1047 : /* fall through */
      case 1048 : /* fall through */
      case 1049 : /* fall through */
      case 1050 : /* fall through */
      case 1051 : /* fall through */
      case 1052 : /* fall through */
      case 1053 : /* fall through */
      case 1054 : /* fall through */
      case 1055 : /* fall through */
      case 1056 : /* fall through */
      case 1057 : /* fall through */
      case 1058 : /* fall through */
      case 1059 : /* fall through */
      case 1060 : /* fall through */
      case 1061 : /* fall through */
      case 1062 : /* fall through */
      case 1063 : /* fall through */
      case 1064 : /* fall through */
      case 1065 : /* fall through */
      case 1066 : /* fall through */
      case 1067 : /* fall through */
      case 1068 : /* fall through */
      case 1069 : /* fall through */
      case 1070 : /* fall through */
      case 1071 : /* fall through */
      case 1072 : /* fall through */
      case 1073 : /* fall through */
      case 1074 : /* fall through */
      case 1075 : /* fall through */
      case 1076 : /* fall through */
      case 1077 : /* fall through */
      case 1078 : /* fall through */
      case 1079 : /* fall through */
      case 1080 : /* fall through */
      case 1081 : /* fall through */
      case 1082 : /* fall through */
      case 1083 : /* fall through */
      case 1084 : /* fall through */
      case 1085 : /* fall through */
      case 1086 : /* fall through */
      case 1087 : /* fall through */
      case 1088 : /* fall through */
      case 1089 : /* fall through */
      case 1090 : /* fall through */
      case 1091 : /* fall through */
      case 1092 : /* fall through */
      case 1093 : /* fall through */
      case 1094 : /* fall through */
      case 1095 : /* fall through */
      case 1096 : /* fall through */
      case 1097 : /* fall through */
      case 1098 : /* fall through */
      case 1099 : /* fall through */
      case 1100 : /* fall through */
      case 1101 : /* fall through */
      case 1102 : /* fall through */
      case 1103 : /* fall through */
      case 1104 : /* fall through */
      case 1105 : /* fall through */
      case 1106 : /* fall through */
      case 1107 : /* fall through */
      case 1108 : /* fall through */
      case 1109 : /* fall through */
      case 1110 : /* fall through */
      case 1111 : /* fall through */
      case 1112 : /* fall through */
      case 1113 : /* fall through */
      case 1114 : /* fall through */
      case 1115 : /* fall through */
      case 1116 : /* fall through */
      case 1117 : /* fall through */
      case 1118 : /* fall through */
      case 1119 : /* fall through */
      case 1120 : /* fall through */
      case 1121 : /* fall through */
      case 1122 : /* fall through */
      case 1123 : /* fall through */
      case 1124 : /* fall through */
      case 1125 : /* fall through */
      case 1126 : /* fall through */
      case 1127 : /* fall through */
      case 1128 : /* fall through */
      case 1129 : /* fall through */
      case 1130 : /* fall through */
      case 1131 : /* fall through */
      case 1132 : /* fall through */
      case 1133 : /* fall through */
      case 1134 : /* fall through */
      case 1135 : /* fall through */
      case 1136 : /* fall through */
      case 1137 : /* fall through */
      case 1138 : /* fall through */
      case 1139 : /* fall through */
      case 1140 : /* fall through */
      case 1141 : /* fall through */
      case 1142 : /* fall through */
      case 1143 : /* fall through */
      case 1144 : /* fall through */
      case 1145 : /* fall through */
      case 1146 : /* fall through */
      case 1147 : /* fall through */
      case 1148 : /* fall through */
      case 1149 : /* fall through */
      case 1150 : /* fall through */
      case 1151 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVLGRMEM; xstormy16_extract_sfmt_movlgrmem (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1152 : /* fall through */
      case 1153 : /* fall through */
      case 1154 : /* fall through */
      case 1155 : /* fall through */
      case 1156 : /* fall through */
      case 1157 : /* fall through */
      case 1158 : /* fall through */
      case 1159 : /* fall through */
      case 1160 : /* fall through */
      case 1161 : /* fall through */
      case 1162 : /* fall through */
      case 1163 : /* fall through */
      case 1164 : /* fall through */
      case 1165 : /* fall through */
      case 1166 : /* fall through */
      case 1167 : /* fall through */
      case 1168 : /* fall through */
      case 1169 : /* fall through */
      case 1170 : /* fall through */
      case 1171 : /* fall through */
      case 1172 : /* fall through */
      case 1173 : /* fall through */
      case 1174 : /* fall through */
      case 1175 : /* fall through */
      case 1176 : /* fall through */
      case 1177 : /* fall through */
      case 1178 : /* fall through */
      case 1179 : /* fall through */
      case 1180 : /* fall through */
      case 1181 : /* fall through */
      case 1182 : /* fall through */
      case 1183 : /* fall through */
      case 1184 : /* fall through */
      case 1185 : /* fall through */
      case 1186 : /* fall through */
      case 1187 : /* fall through */
      case 1188 : /* fall through */
      case 1189 : /* fall through */
      case 1190 : /* fall through */
      case 1191 : /* fall through */
      case 1192 : /* fall through */
      case 1193 : /* fall through */
      case 1194 : /* fall through */
      case 1195 : /* fall through */
      case 1196 : /* fall through */
      case 1197 : /* fall through */
      case 1198 : /* fall through */
      case 1199 : /* fall through */
      case 1200 : /* fall through */
      case 1201 : /* fall through */
      case 1202 : /* fall through */
      case 1203 : /* fall through */
      case 1204 : /* fall through */
      case 1205 : /* fall through */
      case 1206 : /* fall through */
      case 1207 : /* fall through */
      case 1208 : /* fall through */
      case 1209 : /* fall through */
      case 1210 : /* fall through */
      case 1211 : /* fall through */
      case 1212 : /* fall through */
      case 1213 : /* fall through */
      case 1214 : /* fall through */
      case 1215 : /* fall through */
      case 1216 : /* fall through */
      case 1217 : /* fall through */
      case 1218 : /* fall through */
      case 1219 : /* fall through */
      case 1220 : /* fall through */
      case 1221 : /* fall through */
      case 1222 : /* fall through */
      case 1223 : /* fall through */
      case 1224 : /* fall through */
      case 1225 : /* fall through */
      case 1226 : /* fall through */
      case 1227 : /* fall through */
      case 1228 : /* fall through */
      case 1229 : /* fall through */
      case 1230 : /* fall through */
      case 1231 : /* fall through */
      case 1232 : /* fall through */
      case 1233 : /* fall through */
      case 1234 : /* fall through */
      case 1235 : /* fall through */
      case 1236 : /* fall through */
      case 1237 : /* fall through */
      case 1238 : /* fall through */
      case 1239 : /* fall through */
      case 1240 : /* fall through */
      case 1241 : /* fall through */
      case 1242 : /* fall through */
      case 1243 : /* fall through */
      case 1244 : /* fall through */
      case 1245 : /* fall through */
      case 1246 : /* fall through */
      case 1247 : /* fall through */
      case 1248 : /* fall through */
      case 1249 : /* fall through */
      case 1250 : /* fall through */
      case 1251 : /* fall through */
      case 1252 : /* fall through */
      case 1253 : /* fall through */
      case 1254 : /* fall through */
      case 1255 : /* fall through */
      case 1256 : /* fall through */
      case 1257 : /* fall through */
      case 1258 : /* fall through */
      case 1259 : /* fall through */
      case 1260 : /* fall through */
      case 1261 : /* fall through */
      case 1262 : /* fall through */
      case 1263 : /* fall through */
      case 1264 : /* fall through */
      case 1265 : /* fall through */
      case 1266 : /* fall through */
      case 1267 : /* fall through */
      case 1268 : /* fall through */
      case 1269 : /* fall through */
      case 1270 : /* fall through */
      case 1271 : /* fall through */
      case 1272 : /* fall through */
      case 1273 : /* fall through */
      case 1274 : /* fall through */
      case 1275 : /* fall through */
      case 1276 : /* fall through */
      case 1277 : /* fall through */
      case 1278 : /* fall through */
      case 1279 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVLMEMGR; xstormy16_extract_sfmt_movlmemgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1280 : /* fall through */
      case 1281 : /* fall through */
      case 1282 : /* fall through */
      case 1283 : /* fall through */
      case 1284 : /* fall through */
      case 1285 : /* fall through */
      case 1286 : /* fall through */
      case 1287 : /* fall through */
      case 1288 : /* fall through */
      case 1289 : /* fall through */
      case 1290 : /* fall through */
      case 1291 : /* fall through */
      case 1292 : /* fall through */
      case 1293 : /* fall through */
      case 1294 : /* fall through */
      case 1295 : /* fall through */
      case 1296 : /* fall through */
      case 1297 : /* fall through */
      case 1298 : /* fall through */
      case 1299 : /* fall through */
      case 1300 : /* fall through */
      case 1301 : /* fall through */
      case 1302 : /* fall through */
      case 1303 : /* fall through */
      case 1304 : /* fall through */
      case 1305 : /* fall through */
      case 1306 : /* fall through */
      case 1307 : /* fall through */
      case 1308 : /* fall through */
      case 1309 : /* fall through */
      case 1310 : /* fall through */
      case 1311 : /* fall through */
      case 1312 : /* fall through */
      case 1313 : /* fall through */
      case 1314 : /* fall through */
      case 1315 : /* fall through */
      case 1316 : /* fall through */
      case 1317 : /* fall through */
      case 1318 : /* fall through */
      case 1319 : /* fall through */
      case 1320 : /* fall through */
      case 1321 : /* fall through */
      case 1322 : /* fall through */
      case 1323 : /* fall through */
      case 1324 : /* fall through */
      case 1325 : /* fall through */
      case 1326 : /* fall through */
      case 1327 : /* fall through */
      case 1328 : /* fall through */
      case 1329 : /* fall through */
      case 1330 : /* fall through */
      case 1331 : /* fall through */
      case 1332 : /* fall through */
      case 1333 : /* fall through */
      case 1334 : /* fall through */
      case 1335 : /* fall through */
      case 1336 : /* fall through */
      case 1337 : /* fall through */
      case 1338 : /* fall through */
      case 1339 : /* fall through */
      case 1340 : /* fall through */
      case 1341 : /* fall through */
      case 1342 : /* fall through */
      case 1343 : /* fall through */
      case 1344 : /* fall through */
      case 1345 : /* fall through */
      case 1346 : /* fall through */
      case 1347 : /* fall through */
      case 1348 : /* fall through */
      case 1349 : /* fall through */
      case 1350 : /* fall through */
      case 1351 : /* fall through */
      case 1352 : /* fall through */
      case 1353 : /* fall through */
      case 1354 : /* fall through */
      case 1355 : /* fall through */
      case 1356 : /* fall through */
      case 1357 : /* fall through */
      case 1358 : /* fall through */
      case 1359 : /* fall through */
      case 1360 : /* fall through */
      case 1361 : /* fall through */
      case 1362 : /* fall through */
      case 1363 : /* fall through */
      case 1364 : /* fall through */
      case 1365 : /* fall through */
      case 1366 : /* fall through */
      case 1367 : /* fall through */
      case 1368 : /* fall through */
      case 1369 : /* fall through */
      case 1370 : /* fall through */
      case 1371 : /* fall through */
      case 1372 : /* fall through */
      case 1373 : /* fall through */
      case 1374 : /* fall through */
      case 1375 : /* fall through */
      case 1376 : /* fall through */
      case 1377 : /* fall through */
      case 1378 : /* fall through */
      case 1379 : /* fall through */
      case 1380 : /* fall through */
      case 1381 : /* fall through */
      case 1382 : /* fall through */
      case 1383 : /* fall through */
      case 1384 : /* fall through */
      case 1385 : /* fall through */
      case 1386 : /* fall through */
      case 1387 : /* fall through */
      case 1388 : /* fall through */
      case 1389 : /* fall through */
      case 1390 : /* fall through */
      case 1391 : /* fall through */
      case 1392 : /* fall through */
      case 1393 : /* fall through */
      case 1394 : /* fall through */
      case 1395 : /* fall through */
      case 1396 : /* fall through */
      case 1397 : /* fall through */
      case 1398 : /* fall through */
      case 1399 : /* fall through */
      case 1400 : /* fall through */
      case 1401 : /* fall through */
      case 1402 : /* fall through */
      case 1403 : /* fall through */
      case 1404 : /* fall through */
      case 1405 : /* fall through */
      case 1406 : /* fall through */
      case 1407 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVHGRMEM; xstormy16_extract_sfmt_movhgrmem (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1408 : /* fall through */
      case 1409 : /* fall through */
      case 1410 : /* fall through */
      case 1411 : /* fall through */
      case 1412 : /* fall through */
      case 1413 : /* fall through */
      case 1414 : /* fall through */
      case 1415 : /* fall through */
      case 1416 : /* fall through */
      case 1417 : /* fall through */
      case 1418 : /* fall through */
      case 1419 : /* fall through */
      case 1420 : /* fall through */
      case 1421 : /* fall through */
      case 1422 : /* fall through */
      case 1423 : /* fall through */
      case 1424 : /* fall through */
      case 1425 : /* fall through */
      case 1426 : /* fall through */
      case 1427 : /* fall through */
      case 1428 : /* fall through */
      case 1429 : /* fall through */
      case 1430 : /* fall through */
      case 1431 : /* fall through */
      case 1432 : /* fall through */
      case 1433 : /* fall through */
      case 1434 : /* fall through */
      case 1435 : /* fall through */
      case 1436 : /* fall through */
      case 1437 : /* fall through */
      case 1438 : /* fall through */
      case 1439 : /* fall through */
      case 1440 : /* fall through */
      case 1441 : /* fall through */
      case 1442 : /* fall through */
      case 1443 : /* fall through */
      case 1444 : /* fall through */
      case 1445 : /* fall through */
      case 1446 : /* fall through */
      case 1447 : /* fall through */
      case 1448 : /* fall through */
      case 1449 : /* fall through */
      case 1450 : /* fall through */
      case 1451 : /* fall through */
      case 1452 : /* fall through */
      case 1453 : /* fall through */
      case 1454 : /* fall through */
      case 1455 : /* fall through */
      case 1456 : /* fall through */
      case 1457 : /* fall through */
      case 1458 : /* fall through */
      case 1459 : /* fall through */
      case 1460 : /* fall through */
      case 1461 : /* fall through */
      case 1462 : /* fall through */
      case 1463 : /* fall through */
      case 1464 : /* fall through */
      case 1465 : /* fall through */
      case 1466 : /* fall through */
      case 1467 : /* fall through */
      case 1468 : /* fall through */
      case 1469 : /* fall through */
      case 1470 : /* fall through */
      case 1471 : /* fall through */
      case 1472 : /* fall through */
      case 1473 : /* fall through */
      case 1474 : /* fall through */
      case 1475 : /* fall through */
      case 1476 : /* fall through */
      case 1477 : /* fall through */
      case 1478 : /* fall through */
      case 1479 : /* fall through */
      case 1480 : /* fall through */
      case 1481 : /* fall through */
      case 1482 : /* fall through */
      case 1483 : /* fall through */
      case 1484 : /* fall through */
      case 1485 : /* fall through */
      case 1486 : /* fall through */
      case 1487 : /* fall through */
      case 1488 : /* fall through */
      case 1489 : /* fall through */
      case 1490 : /* fall through */
      case 1491 : /* fall through */
      case 1492 : /* fall through */
      case 1493 : /* fall through */
      case 1494 : /* fall through */
      case 1495 : /* fall through */
      case 1496 : /* fall through */
      case 1497 : /* fall through */
      case 1498 : /* fall through */
      case 1499 : /* fall through */
      case 1500 : /* fall through */
      case 1501 : /* fall through */
      case 1502 : /* fall through */
      case 1503 : /* fall through */
      case 1504 : /* fall through */
      case 1505 : /* fall through */
      case 1506 : /* fall through */
      case 1507 : /* fall through */
      case 1508 : /* fall through */
      case 1509 : /* fall through */
      case 1510 : /* fall through */
      case 1511 : /* fall through */
      case 1512 : /* fall through */
      case 1513 : /* fall through */
      case 1514 : /* fall through */
      case 1515 : /* fall through */
      case 1516 : /* fall through */
      case 1517 : /* fall through */
      case 1518 : /* fall through */
      case 1519 : /* fall through */
      case 1520 : /* fall through */
      case 1521 : /* fall through */
      case 1522 : /* fall through */
      case 1523 : /* fall through */
      case 1524 : /* fall through */
      case 1525 : /* fall through */
      case 1526 : /* fall through */
      case 1527 : /* fall through */
      case 1528 : /* fall through */
      case 1529 : /* fall through */
      case 1530 : /* fall through */
      case 1531 : /* fall through */
      case 1532 : /* fall through */
      case 1533 : /* fall through */
      case 1534 : /* fall through */
      case 1535 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_MOVHMEMGR; xstormy16_extract_sfmt_movhmemgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1536 : /* fall through */
      case 1537 : /* fall through */
      case 1538 : /* fall through */
      case 1539 : /* fall through */
      case 1540 : /* fall through */
      case 1541 : /* fall through */
      case 1542 : /* fall through */
      case 1543 : /* fall through */
      case 1544 : /* fall through */
      case 1545 : /* fall through */
      case 1546 : /* fall through */
      case 1547 : /* fall through */
      case 1548 : /* fall through */
      case 1549 : /* fall through */
      case 1550 : /* fall through */
      case 1551 : /* fall through */
      case 1552 : /* fall through */
      case 1553 : /* fall through */
      case 1554 : /* fall through */
      case 1555 : /* fall through */
      case 1556 : /* fall through */
      case 1557 : /* fall through */
      case 1558 : /* fall through */
      case 1559 : /* fall through */
      case 1560 : /* fall through */
      case 1561 : /* fall through */
      case 1562 : /* fall through */
      case 1563 : /* fall through */
      case 1564 : /* fall through */
      case 1565 : /* fall through */
      case 1566 : /* fall through */
      case 1567 : /* fall through */
      case 1568 : /* fall through */
      case 1569 : /* fall through */
      case 1570 : /* fall through */
      case 1571 : /* fall through */
      case 1572 : /* fall through */
      case 1573 : /* fall through */
      case 1574 : /* fall through */
      case 1575 : /* fall through */
      case 1576 : /* fall through */
      case 1577 : /* fall through */
      case 1578 : /* fall through */
      case 1579 : /* fall through */
      case 1580 : /* fall through */
      case 1581 : /* fall through */
      case 1582 : /* fall through */
      case 1583 : /* fall through */
      case 1584 : /* fall through */
      case 1585 : /* fall through */
      case 1586 : /* fall through */
      case 1587 : /* fall through */
      case 1588 : /* fall through */
      case 1589 : /* fall through */
      case 1590 : /* fall through */
      case 1591 : /* fall through */
      case 1592 : /* fall through */
      case 1593 : /* fall through */
      case 1594 : /* fall through */
      case 1595 : /* fall through */
      case 1596 : /* fall through */
      case 1597 : /* fall through */
      case 1598 : /* fall through */
      case 1599 : /* fall through */
      case 1600 : /* fall through */
      case 1601 : /* fall through */
      case 1602 : /* fall through */
      case 1603 : /* fall through */
      case 1604 : /* fall through */
      case 1605 : /* fall through */
      case 1606 : /* fall through */
      case 1607 : /* fall through */
      case 1608 : /* fall through */
      case 1609 : /* fall through */
      case 1610 : /* fall through */
      case 1611 : /* fall through */
      case 1612 : /* fall through */
      case 1613 : /* fall through */
      case 1614 : /* fall through */
      case 1615 : /* fall through */
      case 1616 : /* fall through */
      case 1617 : /* fall through */
      case 1618 : /* fall through */
      case 1619 : /* fall through */
      case 1620 : /* fall through */
      case 1621 : /* fall through */
      case 1622 : /* fall through */
      case 1623 : /* fall through */
      case 1624 : /* fall through */
      case 1625 : /* fall through */
      case 1626 : /* fall through */
      case 1627 : /* fall through */
      case 1628 : /* fall through */
      case 1629 : /* fall through */
      case 1630 : /* fall through */
      case 1631 : /* fall through */
      case 1632 : /* fall through */
      case 1633 : /* fall through */
      case 1634 : /* fall through */
      case 1635 : /* fall through */
      case 1636 : /* fall through */
      case 1637 : /* fall through */
      case 1638 : /* fall through */
      case 1639 : /* fall through */
      case 1640 : /* fall through */
      case 1641 : /* fall through */
      case 1642 : /* fall through */
      case 1643 : /* fall through */
      case 1644 : /* fall through */
      case 1645 : /* fall through */
      case 1646 : /* fall through */
      case 1647 : /* fall through */
      case 1648 : /* fall through */
      case 1649 : /* fall through */
      case 1650 : /* fall through */
      case 1651 : /* fall through */
      case 1652 : /* fall through */
      case 1653 : /* fall through */
      case 1654 : /* fall through */
      case 1655 : /* fall through */
      case 1656 : /* fall through */
      case 1657 : /* fall through */
      case 1658 : /* fall through */
      case 1659 : /* fall through */
      case 1660 : /* fall through */
      case 1661 : /* fall through */
      case 1662 : /* fall through */
      case 1663 : itype = XSTORMY16_INSN_BCCIMM16; xstormy16_extract_sfmt_bccimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1664 : /* fall through */
      case 1665 : /* fall through */
      case 1666 : /* fall through */
      case 1667 : /* fall through */
      case 1668 : /* fall through */
      case 1669 : /* fall through */
      case 1670 : /* fall through */
      case 1671 : /* fall through */
      case 1672 : /* fall through */
      case 1673 : /* fall through */
      case 1674 : /* fall through */
      case 1675 : /* fall through */
      case 1676 : /* fall through */
      case 1677 : /* fall through */
      case 1678 : /* fall through */
      case 1679 : /* fall through */
      case 1680 : /* fall through */
      case 1681 : /* fall through */
      case 1682 : /* fall through */
      case 1683 : /* fall through */
      case 1684 : /* fall through */
      case 1685 : /* fall through */
      case 1686 : /* fall through */
      case 1687 : /* fall through */
      case 1688 : /* fall through */
      case 1689 : /* fall through */
      case 1690 : /* fall through */
      case 1691 : /* fall through */
      case 1692 : /* fall through */
      case 1693 : /* fall through */
      case 1694 : /* fall through */
      case 1695 : /* fall through */
      case 1696 : /* fall through */
      case 1697 : /* fall through */
      case 1698 : /* fall through */
      case 1699 : /* fall through */
      case 1700 : /* fall through */
      case 1701 : /* fall through */
      case 1702 : /* fall through */
      case 1703 : /* fall through */
      case 1704 : /* fall through */
      case 1705 : /* fall through */
      case 1706 : /* fall through */
      case 1707 : /* fall through */
      case 1708 : /* fall through */
      case 1709 : /* fall through */
      case 1710 : /* fall through */
      case 1711 : /* fall through */
      case 1712 : /* fall through */
      case 1713 : /* fall through */
      case 1714 : /* fall through */
      case 1715 : /* fall through */
      case 1716 : /* fall through */
      case 1717 : /* fall through */
      case 1718 : /* fall through */
      case 1719 : /* fall through */
      case 1720 : /* fall through */
      case 1721 : /* fall through */
      case 1722 : /* fall through */
      case 1723 : /* fall through */
      case 1724 : /* fall through */
      case 1725 : /* fall through */
      case 1726 : /* fall through */
      case 1727 : /* fall through */
      case 1728 : /* fall through */
      case 1729 : /* fall through */
      case 1730 : /* fall through */
      case 1731 : /* fall through */
      case 1732 : /* fall through */
      case 1733 : /* fall through */
      case 1734 : /* fall through */
      case 1735 : /* fall through */
      case 1736 : /* fall through */
      case 1737 : /* fall through */
      case 1738 : /* fall through */
      case 1739 : /* fall through */
      case 1740 : /* fall through */
      case 1741 : /* fall through */
      case 1742 : /* fall through */
      case 1743 : /* fall through */
      case 1744 : /* fall through */
      case 1745 : /* fall through */
      case 1746 : /* fall through */
      case 1747 : /* fall through */
      case 1748 : /* fall through */
      case 1749 : /* fall through */
      case 1750 : /* fall through */
      case 1751 : /* fall through */
      case 1752 : /* fall through */
      case 1753 : /* fall through */
      case 1754 : /* fall through */
      case 1755 : /* fall through */
      case 1756 : /* fall through */
      case 1757 : /* fall through */
      case 1758 : /* fall through */
      case 1759 : /* fall through */
      case 1760 : /* fall through */
      case 1761 : /* fall through */
      case 1762 : /* fall through */
      case 1763 : /* fall through */
      case 1764 : /* fall through */
      case 1765 : /* fall through */
      case 1766 : /* fall through */
      case 1767 : /* fall through */
      case 1768 : /* fall through */
      case 1769 : /* fall through */
      case 1770 : /* fall through */
      case 1771 : /* fall through */
      case 1772 : /* fall through */
      case 1773 : /* fall through */
      case 1774 : /* fall through */
      case 1775 : /* fall through */
      case 1776 : /* fall through */
      case 1777 : /* fall through */
      case 1778 : /* fall through */
      case 1779 : /* fall through */
      case 1780 : /* fall through */
      case 1781 : /* fall through */
      case 1782 : /* fall through */
      case 1783 : /* fall through */
      case 1784 : /* fall through */
      case 1785 : /* fall through */
      case 1786 : /* fall through */
      case 1787 : /* fall through */
      case 1788 : /* fall through */
      case 1789 : /* fall through */
      case 1790 : /* fall through */
      case 1791 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_BCC; xstormy16_extract_sfmt_bcc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1792 : /* fall through */
      case 1793 : /* fall through */
      case 1794 : /* fall through */
      case 1795 : /* fall through */
      case 1796 : /* fall through */
      case 1797 : /* fall through */
      case 1798 : /* fall through */
      case 1799 : /* fall through */
      case 1808 : /* fall through */
      case 1809 : /* fall through */
      case 1810 : /* fall through */
      case 1811 : /* fall through */
      case 1812 : /* fall through */
      case 1813 : /* fall through */
      case 1814 : /* fall through */
      case 1815 : /* fall through */
      case 1824 : /* fall through */
      case 1825 : /* fall through */
      case 1826 : /* fall through */
      case 1827 : /* fall through */
      case 1828 : /* fall through */
      case 1829 : /* fall through */
      case 1830 : /* fall through */
      case 1831 : /* fall through */
      case 1840 : /* fall through */
      case 1841 : /* fall through */
      case 1842 : /* fall through */
      case 1843 : /* fall through */
      case 1844 : /* fall through */
      case 1845 : /* fall through */
      case 1846 : /* fall through */
      case 1847 : /* fall through */
      case 1856 : /* fall through */
      case 1857 : /* fall through */
      case 1858 : /* fall through */
      case 1859 : /* fall through */
      case 1860 : /* fall through */
      case 1861 : /* fall through */
      case 1862 : /* fall through */
      case 1863 : /* fall through */
      case 1872 : /* fall through */
      case 1873 : /* fall through */
      case 1874 : /* fall through */
      case 1875 : /* fall through */
      case 1876 : /* fall through */
      case 1877 : /* fall through */
      case 1878 : /* fall through */
      case 1879 : /* fall through */
      case 1888 : /* fall through */
      case 1889 : /* fall through */
      case 1890 : /* fall through */
      case 1891 : /* fall through */
      case 1892 : /* fall through */
      case 1893 : /* fall through */
      case 1894 : /* fall through */
      case 1895 : /* fall through */
      case 1904 : /* fall through */
      case 1905 : /* fall through */
      case 1906 : /* fall through */
      case 1907 : /* fall through */
      case 1908 : /* fall through */
      case 1909 : /* fall through */
      case 1910 : /* fall through */
      case 1911 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_CLR1LMEMIMM; xstormy16_extract_sfmt_set1lmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1800 : /* fall through */
      case 1801 : /* fall through */
      case 1802 : /* fall through */
      case 1803 : /* fall through */
      case 1804 : /* fall through */
      case 1805 : /* fall through */
      case 1806 : /* fall through */
      case 1807 : /* fall through */
      case 1816 : /* fall through */
      case 1817 : /* fall through */
      case 1818 : /* fall through */
      case 1819 : /* fall through */
      case 1820 : /* fall through */
      case 1821 : /* fall through */
      case 1822 : /* fall through */
      case 1823 : /* fall through */
      case 1832 : /* fall through */
      case 1833 : /* fall through */
      case 1834 : /* fall through */
      case 1835 : /* fall through */
      case 1836 : /* fall through */
      case 1837 : /* fall through */
      case 1838 : /* fall through */
      case 1839 : /* fall through */
      case 1848 : /* fall through */
      case 1849 : /* fall through */
      case 1850 : /* fall through */
      case 1851 : /* fall through */
      case 1852 : /* fall through */
      case 1853 : /* fall through */
      case 1854 : /* fall through */
      case 1855 : /* fall through */
      case 1864 : /* fall through */
      case 1865 : /* fall through */
      case 1866 : /* fall through */
      case 1867 : /* fall through */
      case 1868 : /* fall through */
      case 1869 : /* fall through */
      case 1870 : /* fall through */
      case 1871 : /* fall through */
      case 1880 : /* fall through */
      case 1881 : /* fall through */
      case 1882 : /* fall through */
      case 1883 : /* fall through */
      case 1884 : /* fall through */
      case 1885 : /* fall through */
      case 1886 : /* fall through */
      case 1887 : /* fall through */
      case 1896 : /* fall through */
      case 1897 : /* fall through */
      case 1898 : /* fall through */
      case 1899 : /* fall through */
      case 1900 : /* fall through */
      case 1901 : /* fall through */
      case 1902 : /* fall through */
      case 1903 : /* fall through */
      case 1912 : /* fall through */
      case 1913 : /* fall through */
      case 1914 : /* fall through */
      case 1915 : /* fall through */
      case 1916 : /* fall through */
      case 1917 : /* fall through */
      case 1918 : /* fall through */
      case 1919 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SET1LMEMIMM; xstormy16_extract_sfmt_set1lmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1920 : /* fall through */
      case 1921 : /* fall through */
      case 1922 : /* fall through */
      case 1923 : /* fall through */
      case 1924 : /* fall through */
      case 1925 : /* fall through */
      case 1926 : /* fall through */
      case 1927 : /* fall through */
      case 1936 : /* fall through */
      case 1937 : /* fall through */
      case 1938 : /* fall through */
      case 1939 : /* fall through */
      case 1940 : /* fall through */
      case 1941 : /* fall through */
      case 1942 : /* fall through */
      case 1943 : /* fall through */
      case 1952 : /* fall through */
      case 1953 : /* fall through */
      case 1954 : /* fall through */
      case 1955 : /* fall through */
      case 1956 : /* fall through */
      case 1957 : /* fall through */
      case 1958 : /* fall through */
      case 1959 : /* fall through */
      case 1968 : /* fall through */
      case 1969 : /* fall through */
      case 1970 : /* fall through */
      case 1971 : /* fall through */
      case 1972 : /* fall through */
      case 1973 : /* fall through */
      case 1974 : /* fall through */
      case 1975 : /* fall through */
      case 1984 : /* fall through */
      case 1985 : /* fall through */
      case 1986 : /* fall through */
      case 1987 : /* fall through */
      case 1988 : /* fall through */
      case 1989 : /* fall through */
      case 1990 : /* fall through */
      case 1991 : /* fall through */
      case 2000 : /* fall through */
      case 2001 : /* fall through */
      case 2002 : /* fall through */
      case 2003 : /* fall through */
      case 2004 : /* fall through */
      case 2005 : /* fall through */
      case 2006 : /* fall through */
      case 2007 : /* fall through */
      case 2016 : /* fall through */
      case 2017 : /* fall through */
      case 2018 : /* fall through */
      case 2019 : /* fall through */
      case 2020 : /* fall through */
      case 2021 : /* fall through */
      case 2022 : /* fall through */
      case 2023 : /* fall through */
      case 2032 : /* fall through */
      case 2033 : /* fall through */
      case 2034 : /* fall through */
      case 2035 : /* fall through */
      case 2036 : /* fall through */
      case 2037 : /* fall through */
      case 2038 : /* fall through */
      case 2039 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_CLR1HMEMIMM; xstormy16_extract_sfmt_set1hmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1928 : /* fall through */
      case 1929 : /* fall through */
      case 1930 : /* fall through */
      case 1931 : /* fall through */
      case 1932 : /* fall through */
      case 1933 : /* fall through */
      case 1934 : /* fall through */
      case 1935 : /* fall through */
      case 1944 : /* fall through */
      case 1945 : /* fall through */
      case 1946 : /* fall through */
      case 1947 : /* fall through */
      case 1948 : /* fall through */
      case 1949 : /* fall through */
      case 1950 : /* fall through */
      case 1951 : /* fall through */
      case 1960 : /* fall through */
      case 1961 : /* fall through */
      case 1962 : /* fall through */
      case 1963 : /* fall through */
      case 1964 : /* fall through */
      case 1965 : /* fall through */
      case 1966 : /* fall through */
      case 1967 : /* fall through */
      case 1976 : /* fall through */
      case 1977 : /* fall through */
      case 1978 : /* fall through */
      case 1979 : /* fall through */
      case 1980 : /* fall through */
      case 1981 : /* fall through */
      case 1982 : /* fall through */
      case 1983 : /* fall through */
      case 1992 : /* fall through */
      case 1993 : /* fall through */
      case 1994 : /* fall through */
      case 1995 : /* fall through */
      case 1996 : /* fall through */
      case 1997 : /* fall through */
      case 1998 : /* fall through */
      case 1999 : /* fall through */
      case 2008 : /* fall through */
      case 2009 : /* fall through */
      case 2010 : /* fall through */
      case 2011 : /* fall through */
      case 2012 : /* fall through */
      case 2013 : /* fall through */
      case 2014 : /* fall through */
      case 2015 : /* fall through */
      case 2024 : /* fall through */
      case 2025 : /* fall through */
      case 2026 : /* fall through */
      case 2027 : /* fall through */
      case 2028 : /* fall through */
      case 2029 : /* fall through */
      case 2030 : /* fall through */
      case 2031 : /* fall through */
      case 2040 : /* fall through */
      case 2041 : /* fall through */
      case 2042 : /* fall through */
      case 2043 : /* fall through */
      case 2044 : /* fall through */
      case 2045 : /* fall through */
      case 2046 : /* fall through */
      case 2047 :
        entire_insn = entire_insn >> 16;
        itype = XSTORMY16_INSN_SET1HMEMIMM; xstormy16_extract_sfmt_set1hmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & xstormy16_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
xstormy16_extract_sfmt_empty (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
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
xstormy16_extract_sfmt_movlmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movlmemimm.f
    UINT f_op2m;
    UINT f_lmem8;
    UINT f_imm16;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_lmem8 = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm16) = f_imm16;
  FLD (f_lmem8) = f_lmem8;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movlmemimm)\t"
        << " f_imm16:0x" << hex << f_imm16 << dec
        << " f_lmem8:0x" << hex << f_lmem8 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movhmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movhmemimm.f
    UINT f_op2m;
    HI f_hmem8;
    UINT f_imm16;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_hmem8 = ((EXTRACT_MSB0_UINT (insn, 32, 8, 8)) + (32512));
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_hmem8) = f_hmem8;
  FLD (f_imm16) = f_imm16;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movhmemimm)\t"
        << " f_hmem8:0x" << hex << f_hmem8 << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movlgrmem (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movlgrmem.f
    UINT f_Rm;
    UINT f_op2m;
    UINT f_lmem8;

    f_Rm = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_lmem8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rm) = f_Rm;
  FLD (f_lmem8) = f_lmem8;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movlgrmem)\t"
        << " f_Rm:0x" << hex << f_Rm << dec
        << " f_lmem8:0x" << hex << f_lmem8 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movhgrmem (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movhgrmem.f
    UINT f_Rm;
    UINT f_op2m;
    HI f_hmem8;

    f_Rm = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_hmem8 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) + (32512));

  /* Record the fields for the semantic handler.  */
  FLD (f_Rm) = f_Rm;
  FLD (f_hmem8) = f_hmem8;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movhgrmem)\t"
        << " f_Rm:0x" << hex << f_Rm << dec
        << " f_hmem8:0x" << hex << f_hmem8 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movlmemgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movlgrmem.f
    UINT f_Rm;
    UINT f_op2m;
    UINT f_lmem8;

    f_Rm = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_lmem8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rm) = f_Rm;
  FLD (f_lmem8) = f_lmem8;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movlmemgr)\t"
        << " f_Rm:0x" << hex << f_Rm << dec
        << " f_lmem8:0x" << hex << f_lmem8 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movhmemgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movhgrmem.f
    UINT f_Rm;
    UINT f_op2m;
    HI f_hmem8;

    f_Rm = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_hmem8 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) + (32512));

  /* Record the fields for the semantic handler.  */
  FLD (f_Rm) = f_Rm;
  FLD (f_hmem8) = f_hmem8;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movhmemgr)\t"
        << " f_Rm:0x" << hex << f_Rm << dec
        << " f_hmem8:0x" << hex << f_hmem8 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgri (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgri)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgripostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgripostinc)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgripredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgripredec)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrigr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgripostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgripostincgr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgripredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgripredecgr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgrii (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgrii)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgriipostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgriipostinc)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgriipredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgriipredec)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgriigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgriigr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgriipostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgriipostincgr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgriipredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgriipredecgr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;

    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movgrgr)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movwimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movwimm8)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movwgrimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
    UINT f_Rm;
    UINT f_imm8;

    f_Rm = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rm) = f_Rm;
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movwgrimm8)\t"
        << " f_Rm:0x" << hex << f_Rm << dec
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movwgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
    UINT f_Rd;
    UINT f_imm16;

    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm16) = f_imm16;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movwgrimm16)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movlowgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movlowgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrgri (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrgri)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrgripostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrgripostinc)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrgripredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrgripredec)\t"
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrigr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgripostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgripostincgr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgripredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;

    f_op2m = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 16, 13, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgripredecgr)\t"
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrgrii (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    UINT f_Rb;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_Rb = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rb) = f_Rb;
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrgrii)\t"
        << " f_Rb:0x" << hex << f_Rb << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrgriipostinc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    UINT f_Rb;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_Rb = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rb) = f_Rb;
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrgriipostinc)\t"
        << " f_Rb:0x" << hex << f_Rb << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgrgriipredec (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    UINT f_Rb;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_Rb = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rb) = f_Rb;
  FLD (f_Rs) = f_Rs;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgrgriipredec)\t"
        << " f_Rb:0x" << hex << f_Rb << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgriigr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    UINT f_Rb;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_Rb = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rb) = f_Rb;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgriigr)\t"
        << " f_Rb:0x" << hex << f_Rb << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgriipostincgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    UINT f_Rb;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_Rb = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rb) = f_Rb;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgriipostincgr)\t"
        << " f_Rb:0x" << hex << f_Rb << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_movfgriipredecgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movfgrgrii.f
    UINT f_op2m;
    UINT f_Rs;
    UINT f_Rdm;
    UINT f_Rb;
    INT f_imm12;

    f_op2m = EXTRACT_MSB0_UINT (insn, 32, 7, 1);
    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rdm = EXTRACT_MSB0_UINT (insn, 32, 13, 3);
    f_Rb = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_imm12 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rb) = f_Rb;
  FLD (f_Rdm) = f_Rdm;
  FLD (f_Rs) = f_Rs;
  FLD (f_imm12) = f_imm12;
  FLD (f_op2m) = f_op2m;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movfgriipredecgr)\t"
        << " f_Rb:0x" << hex << f_Rb << dec
        << " f_Rdm:0x" << hex << f_Rdm << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_imm12:0x" << hex << f_imm12 << dec
        << " f_op2m:0x" << hex << f_op2m << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_maskgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;

    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_maskgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_maskgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
    UINT f_Rd;
    UINT f_imm16;

    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm16) = f_imm16;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_maskgrimm16)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_pushgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_pushgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_popgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_popgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_swpn (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swpn)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_swpw (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;

    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swpw)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_andgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;

    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_andgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_andimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_andimm8)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_andgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
    UINT f_Rd;
    UINT f_imm16;

    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm16) = f_imm16;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_andgrimm16)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_addgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
    UINT f_imm4;
    UINT f_Rd;

    f_imm4 = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm4) = f_imm4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addgrimm4)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm4:0x" << hex << f_imm4 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_adcgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;

    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_adcgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_adcgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
    UINT f_imm4;
    UINT f_Rd;

    f_imm4 = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm4) = f_imm4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_adcgrimm4)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm4:0x" << hex << f_imm4 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_adcimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_adcimm8)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_adcgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movwgrimm16.f
    UINT f_Rd;
    UINT f_imm16;

    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm16) = f_imm16;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_adcgrimm16)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_incgrimm2 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_incgrimm2.f
    UINT f_imm2;
    UINT f_Rd;

    f_imm2 = EXTRACT_MSB0_UINT (insn, 16, 10, 2);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm2) = f_imm2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_incgrimm2)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm2:0x" << hex << f_imm2 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_shrgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;

    f_Rs = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shrgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_shrgrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
    UINT f_imm4;
    UINT f_Rd;

    f_imm4 = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm4) = f_imm4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shrgrimm)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm4:0x" << hex << f_imm4 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_set1lmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_set1lmemimm.f
    UINT f_imm3;
    UINT f_lmem8;

    f_imm3 = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_lmem8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm3) = f_imm3;
  FLD (f_lmem8) = f_lmem8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_set1lmemimm)\t"
        << " f_imm3:0x" << hex << f_imm3 << dec
        << " f_lmem8:0x" << hex << f_lmem8 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_set1hmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_set1hmemimm.f
    UINT f_imm3;
    HI f_hmem8;

    f_imm3 = EXTRACT_MSB0_UINT (insn, 16, 4, 3);
    f_hmem8 = ((EXTRACT_MSB0_UINT (insn, 16, 8, 8)) + (32512));

  /* Record the fields for the semantic handler.  */
  FLD (f_hmem8) = f_hmem8;
  FLD (f_imm3) = f_imm3;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_set1hmemimm)\t"
        << " f_hmem8:0x" << hex << f_hmem8 << dec
        << " f_imm3:0x" << hex << f_imm3 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bccgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;
    UINT f_op5;
    SI f_rel12;

    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_op5 = EXTRACT_MSB0_UINT (insn, 32, 16, 4);
    f_rel12 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  FLD (f_op5) = f_op5;
  FLD (f_rel12) = f_rel12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bccgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_op5:0x" << hex << f_op5 << dec
        << " f_rel12:0x" << hex << f_rel12 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bccgrimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
    UINT f_Rm;
    UINT f_imm8;
    UINT f_op5;
    SI f_rel12;

    f_Rm = EXTRACT_MSB0_UINT (insn, 32, 4, 3);
    f_imm8 = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_op5 = EXTRACT_MSB0_UINT (insn, 32, 16, 4);
    f_rel12 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (f_Rm) = f_Rm;
  FLD (f_op5) = f_op5;
  FLD (f_imm8) = f_imm8;
  FLD (f_rel12) = f_rel12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bccgrimm8)\t"
        << " f_Rm:0x" << hex << f_Rm << dec
        << " f_op5:0x" << hex << f_op5 << dec
        << " f_imm8:0x" << hex << f_imm8 << dec
        << " f_rel12:0x" << hex << f_rel12 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bccimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccimm16.f
    UINT f_op2;
    SI f_rel8_4;
    UINT f_imm16;

    f_op2 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rel8_4 = ((EXTRACT_MSB0_SINT (insn, 32, 8, 8)) + (((pc) + (4))));
    f_imm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_op2) = f_op2;
  FLD (f_imm16) = f_imm16;
  FLD (f_rel8_4) = f_rel8_4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bccimm16)\t"
        << " f_op2:0x" << hex << f_op2 << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
        << " f_rel8_4:0x" << hex << f_rel8_4 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bngrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bngrimm4.f
    UINT f_imm4;
    UINT f_Rd;
    SI f_rel12;

    f_imm4 = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_rel12 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_imm4) = f_imm4;
  FLD (f_rel12) = f_rel12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bngrimm4)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm4:0x" << hex << f_imm4 << dec
        << " f_rel12:0x" << hex << f_rel12 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bngrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrgr.f
    UINT f_Rs;
    UINT f_Rd;
    SI f_rel12;

    f_Rs = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_Rd = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_rel12 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  FLD (f_Rs) = f_Rs;
  FLD (f_rel12) = f_rel12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bngrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << " f_rel12:0x" << hex << f_rel12 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bnlmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bnlmemimm.f
    UINT f_lmem8;
    UINT f_imm3b;
    SI f_rel12;

    f_lmem8 = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_imm3b = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_rel12 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (f_imm3b) = f_imm3b;
  FLD (f_lmem8) = f_lmem8;
  FLD (f_rel12) = f_rel12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bnlmemimm)\t"
        << " f_imm3b:0x" << hex << f_imm3b << dec
        << " f_lmem8:0x" << hex << f_lmem8 << dec
        << " f_rel12:0x" << hex << f_rel12 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bnhmemimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bnhmemimm.f
    HI f_hmem8;
    UINT f_imm3b;
    SI f_rel12;

    f_hmem8 = ((EXTRACT_MSB0_UINT (insn, 32, 8, 8)) + (32512));
    f_imm3b = EXTRACT_MSB0_UINT (insn, 32, 17, 3);
    f_rel12 = ((EXTRACT_MSB0_SINT (insn, 32, 20, 12)) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (f_hmem8) = f_hmem8;
  FLD (f_imm3b) = f_imm3b;
  FLD (f_rel12) = f_rel12;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bnhmemimm)\t"
        << " f_hmem8:0x" << hex << f_hmem8 << dec
        << " f_imm3b:0x" << hex << f_imm3b << dec
        << " f_rel12:0x" << hex << f_rel12 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bcc (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bcc.f
    UINT f_op2;
    SI f_rel8_2;

    f_op2 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rel8_2 = ((EXTRACT_MSB0_SINT (insn, 16, 8, 8)) + (((pc) + (2))));

  /* Record the fields for the semantic handler.  */
  FLD (f_op2) = f_op2;
  FLD (f_rel8_2) = f_rel8_2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bcc)\t"
        << " f_op2:0x" << hex << f_op2 << dec
        << " f_rel8_2:0x" << hex << f_rel8_2 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_bgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_br (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_br.f
    SI f_rel12a;

    f_rel12a = ((((EXTRACT_MSB0_SINT (insn, 16, 4, 11)) << (1))) + (((pc) + (2))));

  /* Record the fields for the semantic handler.  */
  FLD (f_rel12a) = f_rel12a;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_br)\t"
        << " f_rel12a:0x" << hex << f_rel12a << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_jmp (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rbj;
    UINT f_Rd;

    f_Rbj = EXTRACT_MSB0_UINT (insn, 16, 11, 1);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rbj) = f_Rbj;
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jmp)\t"
        << " f_Rbj:0x" << hex << f_Rbj << dec
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_jmpf (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmpf.f
    UINT f_abs24_1;
    UINT f_abs24_2;
    UINT f_abs24;

    f_abs24_1 = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_abs24_2 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_abs24 = ((((f_abs24_2) << (8))) | (f_abs24_1));

  /* Record the fields for the semantic handler.  */
  FLD (f_abs24) = f_abs24;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jmpf)\t"
        << " f_abs24:0x" << hex << f_abs24 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_callrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_callrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_callrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_br.f
    SI f_rel12a;

    f_rel12a = ((((EXTRACT_MSB0_SINT (insn, 16, 4, 11)) << (1))) + (((pc) + (2))));

  /* Record the fields for the semantic handler.  */
  FLD (f_rel12a) = f_rel12a;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_callrimm)\t"
        << " f_rel12a:0x" << hex << f_rel12a << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_callgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rbj;
    UINT f_Rd;

    f_Rbj = EXTRACT_MSB0_UINT (insn, 16, 11, 1);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rbj) = f_Rbj;
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_callgr)\t"
        << " f_Rbj:0x" << hex << f_Rbj << dec
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_callfimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmpf.f
    UINT f_abs24_1;
    UINT f_abs24_2;
    UINT f_abs24;

    f_abs24_1 = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_abs24_2 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_abs24 = ((((f_abs24_2) << (8))) | (f_abs24_1));

  /* Record the fields for the semantic handler.  */
  FLD (f_abs24) = f_abs24;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_callfimm)\t"
        << " f_abs24:0x" << hex << f_abs24 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_icallrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rd;

    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_icallrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_icallgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp.f
    UINT f_Rbj;
    UINT f_Rd;

    f_Rbj = EXTRACT_MSB0_UINT (insn, 16, 11, 1);
    f_Rd = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_Rbj) = f_Rbj;
  FLD (f_Rd) = f_Rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_icallgr)\t"
        << " f_Rbj:0x" << hex << f_Rbj << dec
        << " f_Rd:0x" << hex << f_Rd << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_icallfimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmpf.f
    UINT f_abs24_1;
    UINT f_abs24_2;
    UINT f_abs24;

    f_abs24_1 = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_abs24_2 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_abs24 = ((((f_abs24_2) << (8))) | (f_abs24_1));

  /* Record the fields for the semantic handler.  */
  FLD (f_abs24) = f_abs24;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_icallfimm)\t"
        << " f_abs24:0x" << hex << f_abs24 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_iret (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_iret)\t"
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_ret (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ret)\t"
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_mul (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mul)\t"
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_sdivlh (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sdivlh)\t"
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_reset (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_reset)\t"
        << endl;
    }

#undef FLD
}

