/* Simulator instruction decoder for xstormy16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000, 2001 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


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
  { xstormy16_sem_nop, "NOP", XSTORMY16_INSN_NOP, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_halt, "HALT", XSTORMY16_INSN_HALT, { 0, (1<<MACH_BASE) } },
  { xstormy16_sem_hold, "HOLD", XSTORMY16_INSN_HOLD, { 0, (1<<MACH_BASE) } },
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
xstormy16_extract_sfmt_addgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_addgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_addimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_addgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
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
xstormy16_extract_sfmt_rrcgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_rrcgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_shrgrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_asrgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
static void
xstormy16_extract_sfmt_asrgrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);
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
xstormy16_extract_sfmt_nop (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn);

// Fetch & decode instruction
void
xstormy16_scache::decode (xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn)
{
  /* Result of decoder.  */
  XSTORMY16_INSN_TYPE itype;

  {
    xstormy16_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 24) & (255 << 0)));
      switch (val)
      {
      case 0 :
        {
          unsigned int val = (((insn >> 20) & (15 << 0)));
          switch (val)
          {
          case 0 :
            {
              unsigned int val = (((insn >> 16) & (15 << 0)));
              switch (val)
              {
              case 0 : itype = XSTORMY16_INSN_NOP; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 1 : itype = XSTORMY16_INSN_SYSCALL; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 2 : itype = XSTORMY16_INSN_IRET; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_iret (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 3 : itype = XSTORMY16_INSN_RET; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_ret (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 5 : itype = XSTORMY16_INSN_BRK; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 8 : itype = XSTORMY16_INSN_HALT; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 10 : itype = XSTORMY16_INSN_HOLD; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
              }
            }
          case 1 : itype = XSTORMY16_INSN_CALLRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_callrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = XSTORMY16_INSN_BGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_bgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 : itype = XSTORMY16_INSN_ICALLRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_icallrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 : /* fall through */
          case 5 : itype = XSTORMY16_INSN_JMP; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_jmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 : /* fall through */
          case 7 : itype = XSTORMY16_INSN_ICALLGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_icallgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 : itype = XSTORMY16_INSN_PUSHGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_pushgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 : itype = XSTORMY16_INSN_POPGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_popgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 : /* fall through */
          case 11 : itype = XSTORMY16_INSN_CALLGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_callgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 : itype = XSTORMY16_INSN_DIV; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 : itype = XSTORMY16_INSN_MUL; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 1 : itype = XSTORMY16_INSN_CALLFIMM; xstormy16_extract_sfmt_callfimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 2 : itype = XSTORMY16_INSN_JMPF; xstormy16_extract_sfmt_jmpf (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 : itype = XSTORMY16_INSN_ICALLFIMM; xstormy16_extract_sfmt_icallfimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 : itype = XSTORMY16_INSN_BNGRIMM4; xstormy16_extract_sfmt_bngrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 5 : itype = XSTORMY16_INSN_BPGRIMM4; xstormy16_extract_sfmt_bngrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 6 : itype = XSTORMY16_INSN_BNGRGR; xstormy16_extract_sfmt_bngrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 : itype = XSTORMY16_INSN_BPGRGR; xstormy16_extract_sfmt_bngrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 : itype = XSTORMY16_INSN_CLR1GRIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 9 : itype = XSTORMY16_INSN_SET1GRIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 10 : itype = XSTORMY16_INSN_CLR1GRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 11 : itype = XSTORMY16_INSN_SET1GRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 13 : itype = XSTORMY16_INSN_BCCGRGR; xstormy16_extract_sfmt_bccgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
        {
          unsigned int val = (((insn >> 16) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_BR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_br (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_CALLRIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_callrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 32 : /* fall through */
      case 34 : /* fall through */
      case 36 : /* fall through */
      case 38 : /* fall through */
      case 40 : /* fall through */
      case 42 : /* fall through */
      case 44 : /* fall through */
      case 46 : itype = XSTORMY16_INSN_BCCGRIMM8; xstormy16_extract_sfmt_bccgrimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 33 : /* fall through */
      case 35 : /* fall through */
      case 37 : /* fall through */
      case 39 : /* fall through */
      case 41 : /* fall through */
      case 43 : /* fall through */
      case 45 : /* fall through */
      case 47 : itype = XSTORMY16_INSN_MOVWGRIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movwgrimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 48 :
        {
          unsigned int val = (((insn >> 20) & (15 << 0)));
          switch (val)
          {
          case 0 : /* fall through */
          case 1 : /* fall through */
          case 2 : /* fall through */
          case 3 : itype = XSTORMY16_INSN_INCGRIMM2; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_incgrimm2 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 : /* fall through */
          case 5 : /* fall through */
          case 6 : /* fall through */
          case 7 : itype = XSTORMY16_INSN_DECGRIMM2; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_incgrimm2 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 : itype = XSTORMY16_INSN_SWPB; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 : itype = XSTORMY16_INSN_SWPN; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 : itype = XSTORMY16_INSN_CBWGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 : itype = XSTORMY16_INSN_NOTGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 : itype = XSTORMY16_INSN_MOVLOWGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movlowgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 : itype = XSTORMY16_INSN_MOVHIGHGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movlowgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 : itype = XSTORMY16_INSN_MASKGRIMM16; xstormy16_extract_sfmt_maskgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 : itype = XSTORMY16_INSN_REVGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_swpn (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 49 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_ANDGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_ORGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = XSTORMY16_INSN_XORGRIMM16; xstormy16_extract_sfmt_andgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 : itype = XSTORMY16_INSN_MOVWGRIMM16; xstormy16_extract_sfmt_movwgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 : itype = XSTORMY16_INSN_ADDGRIMM16; xstormy16_extract_sfmt_addgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 : itype = XSTORMY16_INSN_ADCGRIMM16; xstormy16_extract_sfmt_adcgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 : itype = XSTORMY16_INSN_SUBGRIMM16; xstormy16_extract_sfmt_addgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 : itype = XSTORMY16_INSN_SBCGRIMM16; xstormy16_extract_sfmt_adcgrimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 50 : itype = XSTORMY16_INSN_SWPW; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_swpw (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 51 : itype = XSTORMY16_INSN_MASKGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_maskgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 54 : itype = XSTORMY16_INSN_ASRGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_asrgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 55 : itype = XSTORMY16_INSN_ASRGRIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_asrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 56 : itype = XSTORMY16_INSN_RRCGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_rrcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 57 : itype = XSTORMY16_INSN_RRCGRIMM4; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_rrcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 58 : itype = XSTORMY16_INSN_RLCGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_rrcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 59 : itype = XSTORMY16_INSN_RLCGRIMM4; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_rrcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 60 : itype = XSTORMY16_INSN_SHRGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 61 : itype = XSTORMY16_INSN_SHRGRIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 62 : itype = XSTORMY16_INSN_SHLGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 63 : itype = XSTORMY16_INSN_SHLGRIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_shrgrimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 64 : itype = XSTORMY16_INSN_ANDGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 65 : itype = XSTORMY16_INSN_ANDIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 66 : itype = XSTORMY16_INSN_ORGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 67 : itype = XSTORMY16_INSN_ORIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 68 : itype = XSTORMY16_INSN_XORGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 69 : itype = XSTORMY16_INSN_XORIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_andimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 70 : itype = XSTORMY16_INSN_MOVGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 71 : itype = XSTORMY16_INSN_MOVWIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movwimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 73 : itype = XSTORMY16_INSN_ADDGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_addgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 75 : itype = XSTORMY16_INSN_ADCGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_adcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 77 : itype = XSTORMY16_INSN_SUBGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_addgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 79 : itype = XSTORMY16_INSN_SBCGRGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_adcgrgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 81 : itype = XSTORMY16_INSN_ADDGRIMM4; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_addgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 83 : itype = XSTORMY16_INSN_ADCGRIMM4; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_adcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 85 : itype = XSTORMY16_INSN_SUBGRIMM4; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_addgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 87 : itype = XSTORMY16_INSN_SBCGRIMM4; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_adcgrimm4 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 89 : itype = XSTORMY16_INSN_ADDIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_addimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 91 : itype = XSTORMY16_INSN_ADCIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_adcimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 93 : itype = XSTORMY16_INSN_SUBIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_addimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 95 : itype = XSTORMY16_INSN_SBCGRIMM8; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_adcimm8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 96 : /* fall through */
      case 97 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVGRGRIPOSTINC; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgrgripostinc (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVGRGRIIPOSTINC; xstormy16_extract_sfmt_movgrgriipostinc (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 98 : /* fall through */
      case 99 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVGRIPOSTINCGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgripostincgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVGRIIPOSTINCGR; xstormy16_extract_sfmt_movgriigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 100 : /* fall through */
      case 101 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVFGRGRIPOSTINC; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movfgrgripostinc (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVFGRGRIIPOSTINC; xstormy16_extract_sfmt_movfgrgriipostinc (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 102 : /* fall through */
      case 103 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVFGRIPOSTINCGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movfgrigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVFGRIIPOSTINCGR; xstormy16_extract_sfmt_movfgriigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 104 : /* fall through */
      case 105 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVGRGRIPREDEC; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgrgripredec (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVGRGRIIPREDEC; xstormy16_extract_sfmt_movgrgriipredec (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 106 : /* fall through */
      case 107 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVGRIPREDECGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgripredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVGRIIPREDECGR; xstormy16_extract_sfmt_movgriipredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 108 : /* fall through */
      case 109 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVFGRGRIPREDEC; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movfgrgripredec (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVFGRGRIIPREDEC; xstormy16_extract_sfmt_movfgrgriipredec (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 110 : /* fall through */
      case 111 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVFGRIPREDECGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movfgripredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVFGRIIPREDECGR; xstormy16_extract_sfmt_movfgriipredecgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 112 : /* fall through */
      case 113 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVGRGRI; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgrgri (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVGRGRII; xstormy16_extract_sfmt_movgrgrii (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 114 : /* fall through */
      case 115 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVGRIGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movgrigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVGRIIGR; xstormy16_extract_sfmt_movgriigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 116 : /* fall through */
      case 117 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVFGRGRI; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movfgrgri (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVFGRGRII; xstormy16_extract_sfmt_movfgrgrii (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 118 : /* fall through */
      case 119 :
        {
          unsigned int val = (((insn >> 19) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = XSTORMY16_INSN_MOVFGRIGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movfgrigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = XSTORMY16_INSN_MOVFGRIIGR; xstormy16_extract_sfmt_movfgriigr (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 120 : /* fall through */
      case 121 : itype = XSTORMY16_INSN_MOVLMEMIMM; xstormy16_extract_sfmt_movlmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 122 : /* fall through */
      case 123 : itype = XSTORMY16_INSN_MOVHMEMIMM; xstormy16_extract_sfmt_movhmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 124 : itype = XSTORMY16_INSN_BNLMEMIMM; xstormy16_extract_sfmt_bnlmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 125 : itype = XSTORMY16_INSN_BPLMEMIMM; xstormy16_extract_sfmt_bnlmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 126 : itype = XSTORMY16_INSN_BNHMEMIMM; xstormy16_extract_sfmt_bnhmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 127 : itype = XSTORMY16_INSN_BPHMEMIMM; xstormy16_extract_sfmt_bnhmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 143 : itype = XSTORMY16_INSN_MOVLGRMEM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movlgrmem (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 159 : itype = XSTORMY16_INSN_MOVLMEMGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movlmemgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 175 : itype = XSTORMY16_INSN_MOVHGRMEM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movhgrmem (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 191 : itype = XSTORMY16_INSN_MOVHMEMGR; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_movlmemgr (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 207 : itype = XSTORMY16_INSN_BCCIMM16; xstormy16_extract_sfmt_bccimm16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 223 : itype = XSTORMY16_INSN_BCC; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_bcc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 224 : /* fall through */
      case 226 : /* fall through */
      case 228 : /* fall through */
      case 230 : /* fall through */
      case 232 : /* fall through */
      case 234 : /* fall through */
      case 236 : /* fall through */
      case 238 : itype = XSTORMY16_INSN_CLR1LMEMIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_set1lmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 225 : /* fall through */
      case 227 : /* fall through */
      case 229 : /* fall through */
      case 231 : /* fall through */
      case 233 : /* fall through */
      case 235 : /* fall through */
      case 237 : /* fall through */
      case 239 : itype = XSTORMY16_INSN_SET1LMEMIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_set1lmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 240 : /* fall through */
      case 242 : /* fall through */
      case 244 : /* fall through */
      case 246 : /* fall through */
      case 248 : /* fall through */
      case 250 : /* fall through */
      case 252 : /* fall through */
      case 254 : itype = XSTORMY16_INSN_CLR1HMEMIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_set1hmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 241 : /* fall through */
      case 243 : /* fall through */
      case 245 : /* fall through */
      case 247 : /* fall through */
      case 249 : /* fall through */
      case 251 : /* fall through */
      case 253 : /* fall through */
      case 255 : itype = XSTORMY16_INSN_SET1HMEMIMM; entire_insn = base_insn >> 16; xstormy16_extract_sfmt_set1hmemimm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = XSTORMY16_INSN_X_INVALID; xstormy16_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
    f_imm12 = EXTRACT_MSB0_INT (insn, 32, 20, 12);

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
xstormy16_extract_sfmt_addgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
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
        << "0x" << hex << pc << dec << " (sfmt_addgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
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
xstormy16_extract_sfmt_addimm8 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bccgrimm8.f
    UINT f_imm8;

    f_imm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm8) = f_imm8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addimm8)\t"
        << " f_imm8:0x" << hex << f_imm8 << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_addgrimm16 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
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
        << "0x" << hex << pc << dec << " (sfmt_addgrimm16)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm16:0x" << hex << f_imm16 << dec
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
xstormy16_extract_sfmt_rrcgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
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
        << "0x" << hex << pc << dec << " (sfmt_rrcgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_rrcgrimm4 (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
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
        << "0x" << hex << pc << dec << " (sfmt_rrcgrimm4)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_imm4:0x" << hex << f_imm4 << dec
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
xstormy16_extract_sfmt_asrgrgr (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
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
        << "0x" << hex << pc << dec << " (sfmt_asrgrgr)\t"
        << " f_Rd:0x" << hex << f_Rd << dec
        << " f_Rs:0x" << hex << f_Rs << dec
        << endl;
    }

#undef FLD
}

void
xstormy16_extract_sfmt_asrgrimm (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
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
        << "0x" << hex << pc << dec << " (sfmt_asrgrimm)\t"
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
    f_rel12 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) + (((pc) + (4))));

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
    f_rel12 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) + (((pc) + (4))));

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
    f_rel8_4 = ((EXTRACT_MSB0_INT (insn, 32, 8, 8)) + (((pc) + (4))));
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
    f_rel12 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) + (((pc) + (4))));

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
    f_rel12 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) + (((pc) + (4))));

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
    f_rel12 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) + (((pc) + (4))));

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
    f_rel12 = ((EXTRACT_MSB0_INT (insn, 32, 20, 12)) + (((pc) + (4))));

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
    f_rel8_2 = ((EXTRACT_MSB0_INT (insn, 16, 8, 8)) + (((pc) + (2))));

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

    f_rel12a = ((((EXTRACT_MSB0_INT (insn, 16, 4, 11)) << (1))) + (((pc) + (2))));

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

    f_rel12a = ((((EXTRACT_MSB0_INT (insn, 16, 4, 11)) << (1))) + (((pc) + (2))));

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
xstormy16_extract_sfmt_nop (xstormy16_scache* abuf, xstormy16_cpu* current_cpu, PCADDR pc, xstormy16_insn_word base_insn, xstormy16_insn_word entire_insn){
    xstormy16_insn_word insn = entire_insn;
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

