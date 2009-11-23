/* Simulator instruction decoder for sh5_media.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sh5.h"

using namespace sh5; // FIXME: namespace organization still wip


// The instruction descriptor array. 

sh5_media_idesc sh5_media_idesc::idesc_table[SH5_MEDIA_INSN_XORI + 1] =
{
  { sh5_media_sem_x_invalid, "X_INVALID", SH5_MEDIA_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_add, "ADD", SH5_MEDIA_INSN_ADD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_addl, "ADDL", SH5_MEDIA_INSN_ADDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_addi, "ADDI", SH5_MEDIA_INSN_ADDI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_addil, "ADDIL", SH5_MEDIA_INSN_ADDIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_addzl, "ADDZL", SH5_MEDIA_INSN_ADDZL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_alloco, "ALLOCO", SH5_MEDIA_INSN_ALLOCO, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_and, "AND", SH5_MEDIA_INSN_AND, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_andc, "ANDC", SH5_MEDIA_INSN_ANDC, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_andi, "ANDI", SH5_MEDIA_INSN_ANDI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_beq, "BEQ", SH5_MEDIA_INSN_BEQ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_beqi, "BEQI", SH5_MEDIA_INSN_BEQI, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_bge, "BGE", SH5_MEDIA_INSN_BGE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_bgeu, "BGEU", SH5_MEDIA_INSN_BGEU, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_bgt, "BGT", SH5_MEDIA_INSN_BGT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_bgtu, "BGTU", SH5_MEDIA_INSN_BGTU, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_blink, "BLINK", SH5_MEDIA_INSN_BLINK, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_bne, "BNE", SH5_MEDIA_INSN_BNE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_bnei, "BNEI", SH5_MEDIA_INSN_BNEI, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_brk, "BRK", SH5_MEDIA_INSN_BRK, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_byterev, "BYTEREV", SH5_MEDIA_INSN_BYTEREV, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_cmpeq, "CMPEQ", SH5_MEDIA_INSN_CMPEQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_cmpgt, "CMPGT", SH5_MEDIA_INSN_CMPGT, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_cmpgtu, "CMPGTU", SH5_MEDIA_INSN_CMPGTU, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_cmveq, "CMVEQ", SH5_MEDIA_INSN_CMVEQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_cmvne, "CMVNE", SH5_MEDIA_INSN_CMVNE, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fabsd, "FABSD", SH5_MEDIA_INSN_FABSD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fabss, "FABSS", SH5_MEDIA_INSN_FABSS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_faddd, "FADDD", SH5_MEDIA_INSN_FADDD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fadds, "FADDS", SH5_MEDIA_INSN_FADDS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpeqd, "FCMPEQD", SH5_MEDIA_INSN_FCMPEQD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpeqs, "FCMPEQS", SH5_MEDIA_INSN_FCMPEQS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpged, "FCMPGED", SH5_MEDIA_INSN_FCMPGED, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpges, "FCMPGES", SH5_MEDIA_INSN_FCMPGES, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpgtd, "FCMPGTD", SH5_MEDIA_INSN_FCMPGTD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpgts, "FCMPGTS", SH5_MEDIA_INSN_FCMPGTS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpund, "FCMPUND", SH5_MEDIA_INSN_FCMPUND, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcmpuns, "FCMPUNS", SH5_MEDIA_INSN_FCMPUNS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcnvds, "FCNVDS", SH5_MEDIA_INSN_FCNVDS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fcnvsd, "FCNVSD", SH5_MEDIA_INSN_FCNVSD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fdivd, "FDIVD", SH5_MEDIA_INSN_FDIVD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fdivs, "FDIVS", SH5_MEDIA_INSN_FDIVS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fgetscr, "FGETSCR", SH5_MEDIA_INSN_FGETSCR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fiprs, "FIPRS", SH5_MEDIA_INSN_FIPRS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fldd, "FLDD", SH5_MEDIA_INSN_FLDD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fldp, "FLDP", SH5_MEDIA_INSN_FLDP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_flds, "FLDS", SH5_MEDIA_INSN_FLDS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fldxd, "FLDXD", SH5_MEDIA_INSN_FLDXD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fldxp, "FLDXP", SH5_MEDIA_INSN_FLDXP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fldxs, "FLDXS", SH5_MEDIA_INSN_FLDXS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_floatld, "FLOATLD", SH5_MEDIA_INSN_FLOATLD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_floatls, "FLOATLS", SH5_MEDIA_INSN_FLOATLS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_floatqd, "FLOATQD", SH5_MEDIA_INSN_FLOATQD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_floatqs, "FLOATQS", SH5_MEDIA_INSN_FLOATQS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmacs, "FMACS", SH5_MEDIA_INSN_FMACS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmovd, "FMOVD", SH5_MEDIA_INSN_FMOVD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmovdq, "FMOVDQ", SH5_MEDIA_INSN_FMOVDQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmovls, "FMOVLS", SH5_MEDIA_INSN_FMOVLS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmovqd, "FMOVQD", SH5_MEDIA_INSN_FMOVQD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmovs, "FMOVS", SH5_MEDIA_INSN_FMOVS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmovsl, "FMOVSL", SH5_MEDIA_INSN_FMOVSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmuld, "FMULD", SH5_MEDIA_INSN_FMULD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fmuls, "FMULS", SH5_MEDIA_INSN_FMULS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fnegd, "FNEGD", SH5_MEDIA_INSN_FNEGD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fnegs, "FNEGS", SH5_MEDIA_INSN_FNEGS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fputscr, "FPUTSCR", SH5_MEDIA_INSN_FPUTSCR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fsqrtd, "FSQRTD", SH5_MEDIA_INSN_FSQRTD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fsqrts, "FSQRTS", SH5_MEDIA_INSN_FSQRTS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fstd, "FSTD", SH5_MEDIA_INSN_FSTD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fstp, "FSTP", SH5_MEDIA_INSN_FSTP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fsts, "FSTS", SH5_MEDIA_INSN_FSTS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fstxd, "FSTXD", SH5_MEDIA_INSN_FSTXD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fstxp, "FSTXP", SH5_MEDIA_INSN_FSTXP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fstxs, "FSTXS", SH5_MEDIA_INSN_FSTXS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fsubd, "FSUBD", SH5_MEDIA_INSN_FSUBD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_fsubs, "FSUBS", SH5_MEDIA_INSN_FSUBS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ftrcdl, "FTRCDL", SH5_MEDIA_INSN_FTRCDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ftrcsl, "FTRCSL", SH5_MEDIA_INSN_FTRCSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ftrcdq, "FTRCDQ", SH5_MEDIA_INSN_FTRCDQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ftrcsq, "FTRCSQ", SH5_MEDIA_INSN_FTRCSQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ftrvs, "FTRVS", SH5_MEDIA_INSN_FTRVS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_getcfg, "GETCFG", SH5_MEDIA_INSN_GETCFG, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_getcon, "GETCON", SH5_MEDIA_INSN_GETCON, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_gettr, "GETTR", SH5_MEDIA_INSN_GETTR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_icbi, "ICBI", SH5_MEDIA_INSN_ICBI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldb, "LDB", SH5_MEDIA_INSN_LDB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldl, "LDL", SH5_MEDIA_INSN_LDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldq, "LDQ", SH5_MEDIA_INSN_LDQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldub, "LDUB", SH5_MEDIA_INSN_LDUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_lduw, "LDUW", SH5_MEDIA_INSN_LDUW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldw, "LDW", SH5_MEDIA_INSN_LDW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldhil, "LDHIL", SH5_MEDIA_INSN_LDHIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldhiq, "LDHIQ", SH5_MEDIA_INSN_LDHIQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldlol, "LDLOL", SH5_MEDIA_INSN_LDLOL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldloq, "LDLOQ", SH5_MEDIA_INSN_LDLOQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldxb, "LDXB", SH5_MEDIA_INSN_LDXB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldxl, "LDXL", SH5_MEDIA_INSN_LDXL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldxq, "LDXQ", SH5_MEDIA_INSN_LDXQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldxub, "LDXUB", SH5_MEDIA_INSN_LDXUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldxuw, "LDXUW", SH5_MEDIA_INSN_LDXUW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ldxw, "LDXW", SH5_MEDIA_INSN_LDXW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mabsl, "MABSL", SH5_MEDIA_INSN_MABSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mabsw, "MABSW", SH5_MEDIA_INSN_MABSW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_maddl, "MADDL", SH5_MEDIA_INSN_MADDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_maddw, "MADDW", SH5_MEDIA_INSN_MADDW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_maddsl, "MADDSL", SH5_MEDIA_INSN_MADDSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_maddsub, "MADDSUB", SH5_MEDIA_INSN_MADDSUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_maddsw, "MADDSW", SH5_MEDIA_INSN_MADDSW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmpeqb, "MCMPEQB", SH5_MEDIA_INSN_MCMPEQB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmpeql, "MCMPEQL", SH5_MEDIA_INSN_MCMPEQL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmpeqw, "MCMPEQW", SH5_MEDIA_INSN_MCMPEQW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmpgtl, "MCMPGTL", SH5_MEDIA_INSN_MCMPGTL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmpgtub, "MCMPGTUB", SH5_MEDIA_INSN_MCMPGTUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmpgtw, "MCMPGTW", SH5_MEDIA_INSN_MCMPGTW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcmv, "MCMV", SH5_MEDIA_INSN_MCMV, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcnvslw, "MCNVSLW", SH5_MEDIA_INSN_MCNVSLW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcnvswb, "MCNVSWB", SH5_MEDIA_INSN_MCNVSWB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mcnvswub, "MCNVSWUB", SH5_MEDIA_INSN_MCNVSWUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr1, "MEXTR1", SH5_MEDIA_INSN_MEXTR1, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr2, "MEXTR2", SH5_MEDIA_INSN_MEXTR2, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr3, "MEXTR3", SH5_MEDIA_INSN_MEXTR3, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr4, "MEXTR4", SH5_MEDIA_INSN_MEXTR4, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr5, "MEXTR5", SH5_MEDIA_INSN_MEXTR5, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr6, "MEXTR6", SH5_MEDIA_INSN_MEXTR6, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mextr7, "MEXTR7", SH5_MEDIA_INSN_MEXTR7, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmacfxwl, "MMACFXWL", SH5_MEDIA_INSN_MMACFXWL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmacnfx_wl, "MMACNFX_WL", SH5_MEDIA_INSN_MMACNFX_WL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmull, "MMULL", SH5_MEDIA_INSN_MMULL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmulw, "MMULW", SH5_MEDIA_INSN_MMULW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmulfxl, "MMULFXL", SH5_MEDIA_INSN_MMULFXL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmulfxw, "MMULFXW", SH5_MEDIA_INSN_MMULFXW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmulfxrpw, "MMULFXRPW", SH5_MEDIA_INSN_MMULFXRPW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmulhiwl, "MMULHIWL", SH5_MEDIA_INSN_MMULHIWL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmullowl, "MMULLOWL", SH5_MEDIA_INSN_MMULLOWL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mmulsumwq, "MMULSUMWQ", SH5_MEDIA_INSN_MMULSUMWQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_movi, "MOVI", SH5_MEDIA_INSN_MOVI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mpermw, "MPERMW", SH5_MEDIA_INSN_MPERMW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_msadubq, "MSADUBQ", SH5_MEDIA_INSN_MSADUBQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshaldsl, "MSHALDSL", SH5_MEDIA_INSN_MSHALDSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshaldsw, "MSHALDSW", SH5_MEDIA_INSN_MSHALDSW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshardl, "MSHARDL", SH5_MEDIA_INSN_MSHARDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshardw, "MSHARDW", SH5_MEDIA_INSN_MSHARDW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshardsq, "MSHARDSQ", SH5_MEDIA_INSN_MSHARDSQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshfhib, "MSHFHIB", SH5_MEDIA_INSN_MSHFHIB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshfhil, "MSHFHIL", SH5_MEDIA_INSN_MSHFHIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshfhiw, "MSHFHIW", SH5_MEDIA_INSN_MSHFHIW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshflob, "MSHFLOB", SH5_MEDIA_INSN_MSHFLOB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshflol, "MSHFLOL", SH5_MEDIA_INSN_MSHFLOL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshflow, "MSHFLOW", SH5_MEDIA_INSN_MSHFLOW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshlldl, "MSHLLDL", SH5_MEDIA_INSN_MSHLLDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshlldw, "MSHLLDW", SH5_MEDIA_INSN_MSHLLDW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshlrdl, "MSHLRDL", SH5_MEDIA_INSN_MSHLRDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mshlrdw, "MSHLRDW", SH5_MEDIA_INSN_MSHLRDW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_msubl, "MSUBL", SH5_MEDIA_INSN_MSUBL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_msubw, "MSUBW", SH5_MEDIA_INSN_MSUBW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_msubsl, "MSUBSL", SH5_MEDIA_INSN_MSUBSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_msubsub, "MSUBSUB", SH5_MEDIA_INSN_MSUBSUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_msubsw, "MSUBSW", SH5_MEDIA_INSN_MSUBSW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mulsl, "MULSL", SH5_MEDIA_INSN_MULSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_mulul, "MULUL", SH5_MEDIA_INSN_MULUL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_nop, "NOP", SH5_MEDIA_INSN_NOP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_nsb, "NSB", SH5_MEDIA_INSN_NSB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ocbi, "OCBI", SH5_MEDIA_INSN_OCBI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ocbp, "OCBP", SH5_MEDIA_INSN_OCBP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ocbwb, "OCBWB", SH5_MEDIA_INSN_OCBWB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_or, "OR", SH5_MEDIA_INSN_OR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ori, "ORI", SH5_MEDIA_INSN_ORI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_prefi, "PREFI", SH5_MEDIA_INSN_PREFI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_pta, "PTA", SH5_MEDIA_INSN_PTA, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ptabs, "PTABS", SH5_MEDIA_INSN_PTABS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ptb, "PTB", SH5_MEDIA_INSN_PTB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_ptrel, "PTREL", SH5_MEDIA_INSN_PTREL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_putcfg, "PUTCFG", SH5_MEDIA_INSN_PUTCFG, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_putcon, "PUTCON", SH5_MEDIA_INSN_PUTCON, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_rte, "RTE", SH5_MEDIA_INSN_RTE, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shard, "SHARD", SH5_MEDIA_INSN_SHARD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shardl, "SHARDL", SH5_MEDIA_INSN_SHARDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shari, "SHARI", SH5_MEDIA_INSN_SHARI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_sharil, "SHARIL", SH5_MEDIA_INSN_SHARIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlld, "SHLLD", SH5_MEDIA_INSN_SHLLD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlldl, "SHLLDL", SH5_MEDIA_INSN_SHLLDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlli, "SHLLI", SH5_MEDIA_INSN_SHLLI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shllil, "SHLLIL", SH5_MEDIA_INSN_SHLLIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlrd, "SHLRD", SH5_MEDIA_INSN_SHLRD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlrdl, "SHLRDL", SH5_MEDIA_INSN_SHLRDL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlri, "SHLRI", SH5_MEDIA_INSN_SHLRI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shlril, "SHLRIL", SH5_MEDIA_INSN_SHLRIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_shori, "SHORI", SH5_MEDIA_INSN_SHORI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_sleep, "SLEEP", SH5_MEDIA_INSN_SLEEP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stb, "STB", SH5_MEDIA_INSN_STB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stl, "STL", SH5_MEDIA_INSN_STL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stq, "STQ", SH5_MEDIA_INSN_STQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stw, "STW", SH5_MEDIA_INSN_STW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_sthil, "STHIL", SH5_MEDIA_INSN_STHIL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_sthiq, "STHIQ", SH5_MEDIA_INSN_STHIQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stlol, "STLOL", SH5_MEDIA_INSN_STLOL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stloq, "STLOQ", SH5_MEDIA_INSN_STLOQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stxb, "STXB", SH5_MEDIA_INSN_STXB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stxl, "STXL", SH5_MEDIA_INSN_STXL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stxq, "STXQ", SH5_MEDIA_INSN_STXQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_stxw, "STXW", SH5_MEDIA_INSN_STXW, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_sub, "SUB", SH5_MEDIA_INSN_SUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_subl, "SUBL", SH5_MEDIA_INSN_SUBL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_swapq, "SWAPQ", SH5_MEDIA_INSN_SWAPQ, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_synci, "SYNCI", SH5_MEDIA_INSN_SYNCI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_synco, "SYNCO", SH5_MEDIA_INSN_SYNCO, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_trapa, "TRAPA", SH5_MEDIA_INSN_TRAPA, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_xor, "XOR", SH5_MEDIA_INSN_XOR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { sh5_media_sem_xori, "XORI", SH5_MEDIA_INSN_XORI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },

};

// Given a canonical virtual insn id, return the target specific one.

sh5_media_insn_type
sh5_media_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return SH5_MEDIA_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return SH5_MEDIA_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
sh5_media_extract_sfmt_empty (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_add (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_addi (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_alloco (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_beq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_beqi (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_blink (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_brk (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_byterev (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_cmveq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fabsd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fabss (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_faddd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fadds (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fcmpeqd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fcmpeqs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fcnvds (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fcnvsd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fgetscr (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fiprs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fldd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fldp (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_flds (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fldxd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fldxp (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fldxs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fmacs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fmovdq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fmovls (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fmovqd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fmovsl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fputscr (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fstd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fsts (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fstxd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_fstxs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ftrvs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_getcfg (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_getcon (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_gettr (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_lduw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldhil (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldhiq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldlol (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldloq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldxb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldxl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldxq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldxub (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldxuw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ldxw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_mcmv (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_movi (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_nop (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ori (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_pta (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ptabs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_ptrel (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_putcfg (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_putcon (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_shari (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_shori (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_sthil (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_sthiq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stlol (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stloq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stxb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stxl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stxq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_stxw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_swapq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_trapa (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
static void
sh5_media_extract_sfmt_xori (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);

// Fetch & decode instruction
void
sh5_media_scache::decode (sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn)
{
  /* Result of decoder.  */
  SH5_MEDIA_INSN_TYPE itype;

  {
    sh5_media_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 22) & (63 << 4)) | ((insn >> 16) & (15 << 0)));
      switch (val)
      {
      case 1 :
        if ((entire_insn & 0xfc0f000f) == 0x10000)
          { itype = SH5_MEDIA_INSN_CMPEQ; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 :
        if ((entire_insn & 0xfc0f000f) == 0x30000)
          { itype = SH5_MEDIA_INSN_CMPGT; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 7 :
        if ((entire_insn & 0xfc0f000f) == 0x70000)
          { itype = SH5_MEDIA_INSN_CMPGTU; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 :
        if ((entire_insn & 0xfc0f000f) == 0x80000)
          { itype = SH5_MEDIA_INSN_ADDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 9 :
        if ((entire_insn & 0xfc0f000f) == 0x90000)
          { itype = SH5_MEDIA_INSN_ADD; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 10 :
        if ((entire_insn & 0xfc0f000f) == 0xa0000)
          { itype = SH5_MEDIA_INSN_SUBL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 11 :
        if ((entire_insn & 0xfc0f000f) == 0xb0000)
          { itype = SH5_MEDIA_INSN_SUB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 12 :
        if ((entire_insn & 0xfc0f000f) == 0xc0000)
          { itype = SH5_MEDIA_INSN_ADDZL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 13 :
        if ((entire_insn & 0xfc0ffc0f) == 0xdfc00)
          { itype = SH5_MEDIA_INSN_NSB; sh5_media_extract_sfmt_byterev (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 14 :
        if ((entire_insn & 0xfc0f000f) == 0xe0000)
          { itype = SH5_MEDIA_INSN_MULUL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 15 :
        if ((entire_insn & 0xfc0ffc0f) == 0xffc00)
          { itype = SH5_MEDIA_INSN_BYTEREV; sh5_media_extract_sfmt_byterev (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 :
        if ((entire_insn & 0xfc0f000f) == 0x4000000)
          { itype = SH5_MEDIA_INSN_SHLLDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 17 :
        if ((entire_insn & 0xfc0f000f) == 0x4010000)
          { itype = SH5_MEDIA_INSN_SHLLD; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 18 :
        if ((entire_insn & 0xfc0f000f) == 0x4020000)
          { itype = SH5_MEDIA_INSN_SHLRDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 19 :
        if ((entire_insn & 0xfc0f000f) == 0x4030000)
          { itype = SH5_MEDIA_INSN_SHLRD; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 22 :
        if ((entire_insn & 0xfc0f000f) == 0x4060000)
          { itype = SH5_MEDIA_INSN_SHARDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 23 :
        if ((entire_insn & 0xfc0f000f) == 0x4070000)
          { itype = SH5_MEDIA_INSN_SHARD; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 25 :
        if ((entire_insn & 0xfc0f000f) == 0x4090000)
          { itype = SH5_MEDIA_INSN_OR; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 27 :
        if ((entire_insn & 0xfc0f000f) == 0x40b0000)
          { itype = SH5_MEDIA_INSN_AND; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 29 :
        if ((entire_insn & 0xfc0f000f) == 0x40d0000)
          { itype = SH5_MEDIA_INSN_XOR; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 30 :
        if ((entire_insn & 0xfc0f000f) == 0x40e0000)
          { itype = SH5_MEDIA_INSN_MULSL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 31 :
        if ((entire_insn & 0xfc0f000f) == 0x40f0000)
          { itype = SH5_MEDIA_INSN_ANDC; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 33 :
        if ((entire_insn & 0xfc0f000f) == 0x8010000)
          { itype = SH5_MEDIA_INSN_MADDW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 34 :
        if ((entire_insn & 0xfc0f000f) == 0x8020000)
          { itype = SH5_MEDIA_INSN_MADDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 36 :
        if ((entire_insn & 0xfc0f000f) == 0x8040000)
          { itype = SH5_MEDIA_INSN_MADDSUB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 37 :
        if ((entire_insn & 0xfc0f000f) == 0x8050000)
          { itype = SH5_MEDIA_INSN_MADDSW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 38 :
        if ((entire_insn & 0xfc0f000f) == 0x8060000)
          { itype = SH5_MEDIA_INSN_MADDSL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 41 :
        if ((entire_insn & 0xfc0f000f) == 0x8090000)
          { itype = SH5_MEDIA_INSN_MSUBW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 42 :
        if ((entire_insn & 0xfc0f000f) == 0x80a0000)
          { itype = SH5_MEDIA_INSN_MSUBL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 44 :
        if ((entire_insn & 0xfc0f000f) == 0x80c0000)
          { itype = SH5_MEDIA_INSN_MSUBSUB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 45 :
        if ((entire_insn & 0xfc0f000f) == 0x80d0000)
          { itype = SH5_MEDIA_INSN_MSUBSW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 46 :
        if ((entire_insn & 0xfc0f000f) == 0x80e0000)
          { itype = SH5_MEDIA_INSN_MSUBSL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 49 :
        if ((entire_insn & 0xfc0f000f) == 0xc010000)
          { itype = SH5_MEDIA_INSN_MSHLLDW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 50 :
        if ((entire_insn & 0xfc0f000f) == 0xc020000)
          { itype = SH5_MEDIA_INSN_MSHLLDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 53 :
        if ((entire_insn & 0xfc0f000f) == 0xc050000)
          { itype = SH5_MEDIA_INSN_MSHALDSW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 54 :
        if ((entire_insn & 0xfc0f000f) == 0xc060000)
          { itype = SH5_MEDIA_INSN_MSHALDSL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 57 :
        if ((entire_insn & 0xfc0f000f) == 0xc090000)
          { itype = SH5_MEDIA_INSN_MSHARDW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 58 :
        if ((entire_insn & 0xfc0f000f) == 0xc0a0000)
          { itype = SH5_MEDIA_INSN_MSHARDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 59 :
        if ((entire_insn & 0xfc0f000f) == 0xc0b0000)
          { itype = SH5_MEDIA_INSN_MSHARDSQ; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 61 :
        if ((entire_insn & 0xfc0f000f) == 0xc0d0000)
          { itype = SH5_MEDIA_INSN_MSHLRDW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 62 :
        if ((entire_insn & 0xfc0f000f) == 0xc0e0000)
          { itype = SH5_MEDIA_INSN_MSHLRDL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 86 :
        if ((entire_insn & 0xfc0f000f) == 0x14060000)
          { itype = SH5_MEDIA_INSN_FIPRS; sh5_media_extract_sfmt_fiprs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 94 :
        if ((entire_insn & 0xfc0f000f) == 0x140e0000)
          { itype = SH5_MEDIA_INSN_FTRVS; sh5_media_extract_sfmt_ftrvs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 96 :
        if ((entire_insn & 0xfc0f000f) == 0x18000000)
          { itype = SH5_MEDIA_INSN_FABSS; sh5_media_extract_sfmt_fabss (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 97 :
        if ((entire_insn & 0xfc0f000f) == 0x18010000)
          { itype = SH5_MEDIA_INSN_FABSD; sh5_media_extract_sfmt_fabsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 98 :
        if ((entire_insn & 0xfc0f000f) == 0x18020000)
          { itype = SH5_MEDIA_INSN_FNEGS; sh5_media_extract_sfmt_fabss (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 99 :
        if ((entire_insn & 0xfc0f000f) == 0x18030000)
          { itype = SH5_MEDIA_INSN_FNEGD; sh5_media_extract_sfmt_fabsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 112 :
        if ((entire_insn & 0xfc0ffc0f) == 0x1c00fc00)
          { itype = SH5_MEDIA_INSN_FMOVLS; sh5_media_extract_sfmt_fmovls (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 113 :
        if ((entire_insn & 0xfc0ffc0f) == 0x1c01fc00)
          { itype = SH5_MEDIA_INSN_FMOVQD; sh5_media_extract_sfmt_fmovqd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 114 :
        if ((entire_insn & 0xfffffc0f) == 0x1ff2fc00)
          { itype = SH5_MEDIA_INSN_FGETSCR; sh5_media_extract_sfmt_fgetscr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 120 :
        if ((entire_insn & 0xfc0f000f) == 0x1c080000)
          { itype = SH5_MEDIA_INSN_FLDXS; sh5_media_extract_sfmt_fldxs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 121 :
        if ((entire_insn & 0xfc0f000f) == 0x1c090000)
          { itype = SH5_MEDIA_INSN_FLDXD; sh5_media_extract_sfmt_fldxd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 125 :
        if ((entire_insn & 0xfc0f000f) == 0x1c0d0000)
          { itype = SH5_MEDIA_INSN_FLDXP; sh5_media_extract_sfmt_fldxp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 129 :
        if ((entire_insn & 0xfc0f000f) == 0x20010000)
          { itype = SH5_MEDIA_INSN_CMVEQ; sh5_media_extract_sfmt_cmveq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 131 :
        if ((entire_insn & 0xfc0f000f) == 0x20030000)
          { itype = SH5_MEDIA_INSN_SWAPQ; sh5_media_extract_sfmt_swapq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 133 :
        if ((entire_insn & 0xfc0f000f) == 0x20050000)
          { itype = SH5_MEDIA_INSN_CMVNE; sh5_media_extract_sfmt_cmveq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 159 :
        if ((entire_insn & 0xfc0ffc0f) == 0x240ffc00)
          { itype = SH5_MEDIA_INSN_GETCON; sh5_media_extract_sfmt_getcon (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 160 :
        if ((entire_insn & 0xfc0f000f) == 0x28000000)
          { itype = SH5_MEDIA_INSN_MCMPEQB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 161 :
        if ((entire_insn & 0xfc0f000f) == 0x28010000)
          { itype = SH5_MEDIA_INSN_MCMPEQW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 162 :
        if ((entire_insn & 0xfc0f000f) == 0x28020000)
          { itype = SH5_MEDIA_INSN_MCMPEQL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 164 :
        if ((entire_insn & 0xfc0f000f) == 0x28040000)
          { itype = SH5_MEDIA_INSN_MCMPGTUB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 165 :
        if ((entire_insn & 0xfc0f000f) == 0x28050000)
          { itype = SH5_MEDIA_INSN_MCMPGTW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 166 :
        if ((entire_insn & 0xfc0f000f) == 0x28060000)
          { itype = SH5_MEDIA_INSN_MCMPGTL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 167 :
        if ((entire_insn & 0xfc0f000f) == 0x28070000)
          { itype = SH5_MEDIA_INSN_MEXTR1; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 169 :
        if ((entire_insn & 0xfc0ffc0f) == 0x2809fc00)
          { itype = SH5_MEDIA_INSN_MABSW; sh5_media_extract_sfmt_byterev (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 170 :
        if ((entire_insn & 0xfc0ffc0f) == 0x280afc00)
          { itype = SH5_MEDIA_INSN_MABSL; sh5_media_extract_sfmt_byterev (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 171 :
        if ((entire_insn & 0xfc0f000f) == 0x280b0000)
          { itype = SH5_MEDIA_INSN_MEXTR2; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 173 :
        if ((entire_insn & 0xfc0f000f) == 0x280d0000)
          { itype = SH5_MEDIA_INSN_MPERMW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 175 :
        if ((entire_insn & 0xfc0f000f) == 0x280f0000)
          { itype = SH5_MEDIA_INSN_MEXTR3; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 176 :
        if ((entire_insn & 0xfc0f000f) == 0x2c000000)
          { itype = SH5_MEDIA_INSN_MSHFLOB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 177 :
        if ((entire_insn & 0xfc0f000f) == 0x2c010000)
          { itype = SH5_MEDIA_INSN_MSHFLOW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 178 :
        if ((entire_insn & 0xfc0f000f) == 0x2c020000)
          { itype = SH5_MEDIA_INSN_MSHFLOL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 179 :
        if ((entire_insn & 0xfc0f000f) == 0x2c030000)
          { itype = SH5_MEDIA_INSN_MEXTR4; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 180 :
        if ((entire_insn & 0xfc0f000f) == 0x2c040000)
          { itype = SH5_MEDIA_INSN_MSHFHIB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 181 :
        if ((entire_insn & 0xfc0f000f) == 0x2c050000)
          { itype = SH5_MEDIA_INSN_MSHFHIW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 182 :
        if ((entire_insn & 0xfc0f000f) == 0x2c060000)
          { itype = SH5_MEDIA_INSN_MSHFHIL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 183 :
        if ((entire_insn & 0xfc0f000f) == 0x2c070000)
          { itype = SH5_MEDIA_INSN_MEXTR5; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 187 :
        if ((entire_insn & 0xfc0f000f) == 0x2c0b0000)
          { itype = SH5_MEDIA_INSN_MEXTR6; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 191 :
        if ((entire_insn & 0xfc0f000f) == 0x2c0f0000)
          { itype = SH5_MEDIA_INSN_MEXTR7; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 192 :
        if ((entire_insn & 0xfc0f000f) == 0x30000000)
          { itype = SH5_MEDIA_INSN_FMOVSL; sh5_media_extract_sfmt_fmovsl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 193 :
        if ((entire_insn & 0xfc0f000f) == 0x30010000)
          { itype = SH5_MEDIA_INSN_FMOVDQ; sh5_media_extract_sfmt_fmovdq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 194 :
        if ((entire_insn & 0xfc0f03ff) == 0x300203f0)
          { itype = SH5_MEDIA_INSN_FPUTSCR; sh5_media_extract_sfmt_fputscr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 200 :
        if ((entire_insn & 0xfc0f000f) == 0x30080000)
          { itype = SH5_MEDIA_INSN_FCMPEQS; sh5_media_extract_sfmt_fcmpeqs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 201 :
        if ((entire_insn & 0xfc0f000f) == 0x30090000)
          { itype = SH5_MEDIA_INSN_FCMPEQD; sh5_media_extract_sfmt_fcmpeqd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 202 :
        if ((entire_insn & 0xfc0f000f) == 0x300a0000)
          { itype = SH5_MEDIA_INSN_FCMPUNS; sh5_media_extract_sfmt_fcmpeqs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 203 :
        if ((entire_insn & 0xfc0f000f) == 0x300b0000)
          { itype = SH5_MEDIA_INSN_FCMPUND; sh5_media_extract_sfmt_fcmpeqd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 204 :
        if ((entire_insn & 0xfc0f000f) == 0x300c0000)
          { itype = SH5_MEDIA_INSN_FCMPGTS; sh5_media_extract_sfmt_fcmpeqs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 205 :
        if ((entire_insn & 0xfc0f000f) == 0x300d0000)
          { itype = SH5_MEDIA_INSN_FCMPGTD; sh5_media_extract_sfmt_fcmpeqd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 206 :
        if ((entire_insn & 0xfc0f000f) == 0x300e0000)
          { itype = SH5_MEDIA_INSN_FCMPGES; sh5_media_extract_sfmt_fcmpeqs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 207 :
        if ((entire_insn & 0xfc0f000f) == 0x300f0000)
          { itype = SH5_MEDIA_INSN_FCMPGED; sh5_media_extract_sfmt_fcmpeqd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 208 :
        if ((entire_insn & 0xfc0f000f) == 0x34000000)
          { itype = SH5_MEDIA_INSN_FADDS; sh5_media_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 209 :
        if ((entire_insn & 0xfc0f000f) == 0x34010000)
          { itype = SH5_MEDIA_INSN_FADDD; sh5_media_extract_sfmt_faddd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 210 :
        if ((entire_insn & 0xfc0f000f) == 0x34020000)
          { itype = SH5_MEDIA_INSN_FSUBS; sh5_media_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 211 :
        if ((entire_insn & 0xfc0f000f) == 0x34030000)
          { itype = SH5_MEDIA_INSN_FSUBD; sh5_media_extract_sfmt_faddd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 212 :
        if ((entire_insn & 0xfc0f000f) == 0x34040000)
          { itype = SH5_MEDIA_INSN_FDIVS; sh5_media_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 213 :
        if ((entire_insn & 0xfc0f000f) == 0x34050000)
          { itype = SH5_MEDIA_INSN_FDIVD; sh5_media_extract_sfmt_faddd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 214 :
        if ((entire_insn & 0xfc0f000f) == 0x34060000)
          { itype = SH5_MEDIA_INSN_FMULS; sh5_media_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 215 :
        if ((entire_insn & 0xfc0f000f) == 0x34070000)
          { itype = SH5_MEDIA_INSN_FMULD; sh5_media_extract_sfmt_faddd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 222 :
        if ((entire_insn & 0xfc0f000f) == 0x340e0000)
          { itype = SH5_MEDIA_INSN_FMACS; sh5_media_extract_sfmt_fmacs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 224 :
        if ((entire_insn & 0xfc0f000f) == 0x38000000)
          { itype = SH5_MEDIA_INSN_FMOVS; sh5_media_extract_sfmt_fabss (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 225 :
        if ((entire_insn & 0xfc0f000f) == 0x38010000)
          { itype = SH5_MEDIA_INSN_FMOVD; sh5_media_extract_sfmt_fabsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 228 :
        if ((entire_insn & 0xfc0f000f) == 0x38040000)
          { itype = SH5_MEDIA_INSN_FSQRTS; sh5_media_extract_sfmt_fabss (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 229 :
        if ((entire_insn & 0xfc0f000f) == 0x38050000)
          { itype = SH5_MEDIA_INSN_FSQRTD; sh5_media_extract_sfmt_fabsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 230 :
        if ((entire_insn & 0xfc0f000f) == 0x38060000)
          { itype = SH5_MEDIA_INSN_FCNVSD; sh5_media_extract_sfmt_fcnvsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 231 :
        if ((entire_insn & 0xfc0f000f) == 0x38070000)
          { itype = SH5_MEDIA_INSN_FCNVDS; sh5_media_extract_sfmt_fcnvds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 232 :
        if ((entire_insn & 0xfc0f000f) == 0x38080000)
          { itype = SH5_MEDIA_INSN_FTRCSL; sh5_media_extract_sfmt_fabss (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 233 :
        if ((entire_insn & 0xfc0f000f) == 0x38090000)
          { itype = SH5_MEDIA_INSN_FTRCDQ; sh5_media_extract_sfmt_fabsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 234 :
        if ((entire_insn & 0xfc0f000f) == 0x380a0000)
          { itype = SH5_MEDIA_INSN_FTRCSQ; sh5_media_extract_sfmt_fcnvsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 235 :
        if ((entire_insn & 0xfc0f000f) == 0x380b0000)
          { itype = SH5_MEDIA_INSN_FTRCDL; sh5_media_extract_sfmt_fcnvds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 236 :
        if ((entire_insn & 0xfc0f000f) == 0x380c0000)
          { itype = SH5_MEDIA_INSN_FLOATLS; sh5_media_extract_sfmt_fabss (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 237 :
        if ((entire_insn & 0xfc0f000f) == 0x380d0000)
          { itype = SH5_MEDIA_INSN_FLOATQD; sh5_media_extract_sfmt_fabsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 238 :
        if ((entire_insn & 0xfc0f000f) == 0x380e0000)
          { itype = SH5_MEDIA_INSN_FLOATLD; sh5_media_extract_sfmt_fcnvsd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 239 :
        if ((entire_insn & 0xfc0f000f) == 0x380f0000)
          { itype = SH5_MEDIA_INSN_FLOATQS; sh5_media_extract_sfmt_fcnvds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 248 :
        if ((entire_insn & 0xfc0f000f) == 0x3c080000)
          { itype = SH5_MEDIA_INSN_FSTXS; sh5_media_extract_sfmt_fstxs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 249 :
        if ((entire_insn & 0xfc0f000f) == 0x3c090000)
          { itype = SH5_MEDIA_INSN_FSTXD; sh5_media_extract_sfmt_fstxd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 253 :
        if ((entire_insn & 0xfc0f000f) == 0x3c0d0000)
          { itype = SH5_MEDIA_INSN_FSTXP; sh5_media_extract_sfmt_fldxp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 256 :
        if ((entire_insn & 0xfc0f000f) == 0x40000000)
          { itype = SH5_MEDIA_INSN_LDXB; sh5_media_extract_sfmt_ldxb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 257 :
        if ((entire_insn & 0xfc0f000f) == 0x40010000)
          { itype = SH5_MEDIA_INSN_LDXW; sh5_media_extract_sfmt_ldxw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 258 :
        if ((entire_insn & 0xfc0f000f) == 0x40020000)
          { itype = SH5_MEDIA_INSN_LDXL; sh5_media_extract_sfmt_ldxl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 259 :
        if ((entire_insn & 0xfc0f000f) == 0x40030000)
          { itype = SH5_MEDIA_INSN_LDXQ; sh5_media_extract_sfmt_ldxq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 260 :
        if ((entire_insn & 0xfc0f000f) == 0x40040000)
          { itype = SH5_MEDIA_INSN_LDXUB; sh5_media_extract_sfmt_ldxub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 261 :
        if ((entire_insn & 0xfc0f000f) == 0x40050000)
          { itype = SH5_MEDIA_INSN_LDXUW; sh5_media_extract_sfmt_ldxuw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 273 :
        if ((entire_insn & 0xff8ffc0f) == 0x4401fc00)
          { itype = SH5_MEDIA_INSN_BLINK; sh5_media_extract_sfmt_blink (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 277 :
        if ((entire_insn & 0xff8ffc0f) == 0x4405fc00)
          { itype = SH5_MEDIA_INSN_GETTR; sh5_media_extract_sfmt_gettr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 288 :
        if ((entire_insn & 0xfc0f000f) == 0x48000000)
          { itype = SH5_MEDIA_INSN_MSADUBQ; sh5_media_extract_sfmt_mcmv (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 289 :
        if ((entire_insn & 0xfc0f000f) == 0x48010000)
          { itype = SH5_MEDIA_INSN_MMACFXWL; sh5_media_extract_sfmt_mcmv (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 291 :
        if ((entire_insn & 0xfc0f000f) == 0x48030000)
          { itype = SH5_MEDIA_INSN_MCMV; sh5_media_extract_sfmt_mcmv (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 293 :
        if ((entire_insn & 0xfc0f000f) == 0x48050000)
          { itype = SH5_MEDIA_INSN_MMACNFX_WL; sh5_media_extract_sfmt_mcmv (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 297 :
        if ((entire_insn & 0xfc0f000f) == 0x48090000)
          { itype = SH5_MEDIA_INSN_MMULSUMWQ; sh5_media_extract_sfmt_mcmv (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 305 :
        if ((entire_insn & 0xfc0f000f) == 0x4c010000)
          { itype = SH5_MEDIA_INSN_MMULW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 306 :
        if ((entire_insn & 0xfc0f000f) == 0x4c020000)
          { itype = SH5_MEDIA_INSN_MMULL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 309 :
        if ((entire_insn & 0xfc0f000f) == 0x4c050000)
          { itype = SH5_MEDIA_INSN_MMULFXW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 310 :
        if ((entire_insn & 0xfc0f000f) == 0x4c060000)
          { itype = SH5_MEDIA_INSN_MMULFXL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 312 :
        if ((entire_insn & 0xfc0f000f) == 0x4c080000)
          { itype = SH5_MEDIA_INSN_MCNVSWB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 313 :
        if ((entire_insn & 0xfc0f000f) == 0x4c090000)
          { itype = SH5_MEDIA_INSN_MMULFXRPW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 314 :
        if ((entire_insn & 0xfc0f000f) == 0x4c0a0000)
          { itype = SH5_MEDIA_INSN_MMULLOWL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 316 :
        if ((entire_insn & 0xfc0f000f) == 0x4c0c0000)
          { itype = SH5_MEDIA_INSN_MCNVSWUB; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 317 :
        if ((entire_insn & 0xfc0f000f) == 0x4c0d0000)
          { itype = SH5_MEDIA_INSN_MCNVSLW; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 318 :
        if ((entire_insn & 0xfc0f000f) == 0x4c0e0000)
          { itype = SH5_MEDIA_INSN_MMULHIWL; sh5_media_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 384 :
        if ((entire_insn & 0xfc0f000f) == 0x60000000)
          { itype = SH5_MEDIA_INSN_STXB; sh5_media_extract_sfmt_stxb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 385 :
        if ((entire_insn & 0xfc0f000f) == 0x60010000)
          { itype = SH5_MEDIA_INSN_STXW; sh5_media_extract_sfmt_stxw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 386 :
        if ((entire_insn & 0xfc0f000f) == 0x60020000)
          { itype = SH5_MEDIA_INSN_STXL; sh5_media_extract_sfmt_stxl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 387 :
        if ((entire_insn & 0xfc0f000f) == 0x60030000)
          { itype = SH5_MEDIA_INSN_STXQ; sh5_media_extract_sfmt_stxq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 401 :
        if ((entire_insn & 0xfc0f018f) == 0x64010000)
          { itype = SH5_MEDIA_INSN_BEQ; sh5_media_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 403 :
        if ((entire_insn & 0xfc0f018f) == 0x64030000)
          { itype = SH5_MEDIA_INSN_BGE; sh5_media_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 405 :
        if ((entire_insn & 0xfc0f018f) == 0x64050000)
          { itype = SH5_MEDIA_INSN_BNE; sh5_media_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 407 :
        if ((entire_insn & 0xfc0f018f) == 0x64070000)
          { itype = SH5_MEDIA_INSN_BGT; sh5_media_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 411 :
        if ((entire_insn & 0xfc0f018f) == 0x640b0000)
          { itype = SH5_MEDIA_INSN_BGEU; sh5_media_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 415 :
        if ((entire_insn & 0xfc0f018f) == 0x640f0000)
          { itype = SH5_MEDIA_INSN_BGTU; sh5_media_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 417 :
        if ((entire_insn & 0xffff018f) == 0x6bf10000)
          { itype = SH5_MEDIA_INSN_PTABS; sh5_media_extract_sfmt_ptabs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 421 :
        if ((entire_insn & 0xffff018f) == 0x6bf50000)
          { itype = SH5_MEDIA_INSN_PTREL; sh5_media_extract_sfmt_ptrel (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 432 :
        if ((entire_insn & 0xffffffff) == 0x6ff0fff0)
          { itype = SH5_MEDIA_INSN_NOP; sh5_media_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 433 :
        if ((entire_insn & 0xfc0fffff) == 0x6c01fff0)
          { itype = SH5_MEDIA_INSN_TRAPA; sh5_media_extract_sfmt_trapa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 434 :
        if ((entire_insn & 0xffffffff) == 0x6ff2fff0)
          { itype = SH5_MEDIA_INSN_SYNCI; sh5_media_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 435 :
        if ((entire_insn & 0xffffffff) == 0x6ff3fff0)
          { itype = SH5_MEDIA_INSN_RTE; sh5_media_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 437 :
        if ((entire_insn & 0xffffffff) == 0x6ff5fff0)
          { itype = SH5_MEDIA_INSN_BRK; sh5_media_extract_sfmt_brk (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 438 :
        if ((entire_insn & 0xffffffff) == 0x6ff6fff0)
          { itype = SH5_MEDIA_INSN_SYNCO; sh5_media_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 439 :
        if ((entire_insn & 0xffffffff) == 0x6ff7fff0)
          { itype = SH5_MEDIA_INSN_SLEEP; sh5_media_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 447 :
        if ((entire_insn & 0xfc0ffc0f) == 0x6c0ffc00)
          { itype = SH5_MEDIA_INSN_PUTCON; sh5_media_extract_sfmt_putcon (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 512 : /* fall through */
      case 513 : /* fall through */
      case 514 : /* fall through */
      case 515 : /* fall through */
      case 516 : /* fall through */
      case 517 : /* fall through */
      case 518 : /* fall through */
      case 519 : /* fall through */
      case 520 : /* fall through */
      case 521 : /* fall through */
      case 522 : /* fall through */
      case 523 : /* fall through */
      case 524 : /* fall through */
      case 525 : /* fall through */
      case 526 : /* fall through */
      case 527 :
        if ((entire_insn & 0xfc00000f) == 0x80000000)
          { itype = SH5_MEDIA_INSN_LDB; sh5_media_extract_sfmt_ldb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 528 : /* fall through */
      case 529 : /* fall through */
      case 530 : /* fall through */
      case 531 : /* fall through */
      case 532 : /* fall through */
      case 533 : /* fall through */
      case 534 : /* fall through */
      case 535 : /* fall through */
      case 536 : /* fall through */
      case 537 : /* fall through */
      case 538 : /* fall through */
      case 539 : /* fall through */
      case 540 : /* fall through */
      case 541 : /* fall through */
      case 542 : /* fall through */
      case 543 :
        if ((entire_insn & 0xfc00000f) == 0x84000000)
          { itype = SH5_MEDIA_INSN_LDW; sh5_media_extract_sfmt_lduw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 544 : /* fall through */
      case 545 : /* fall through */
      case 546 : /* fall through */
      case 547 : /* fall through */
      case 548 : /* fall through */
      case 549 : /* fall through */
      case 550 : /* fall through */
      case 551 : /* fall through */
      case 552 : /* fall through */
      case 553 : /* fall through */
      case 554 : /* fall through */
      case 555 : /* fall through */
      case 556 : /* fall through */
      case 557 : /* fall through */
      case 558 : /* fall through */
      case 559 :
        if ((entire_insn & 0xfc00000f) == 0x88000000)
          { itype = SH5_MEDIA_INSN_LDL; sh5_media_extract_sfmt_ldl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 560 : /* fall through */
      case 561 : /* fall through */
      case 562 : /* fall through */
      case 563 : /* fall through */
      case 564 : /* fall through */
      case 565 : /* fall through */
      case 566 : /* fall through */
      case 567 : /* fall through */
      case 568 : /* fall through */
      case 569 : /* fall through */
      case 570 : /* fall through */
      case 571 : /* fall through */
      case 572 : /* fall through */
      case 573 : /* fall through */
      case 574 : /* fall through */
      case 575 :
        if ((entire_insn & 0xfc00000f) == 0x8c000000)
          { itype = SH5_MEDIA_INSN_LDQ; sh5_media_extract_sfmt_ldq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 576 : /* fall through */
      case 577 : /* fall through */
      case 578 : /* fall through */
      case 579 : /* fall through */
      case 580 : /* fall through */
      case 581 : /* fall through */
      case 582 : /* fall through */
      case 583 : /* fall through */
      case 584 : /* fall through */
      case 585 : /* fall through */
      case 586 : /* fall through */
      case 587 : /* fall through */
      case 588 : /* fall through */
      case 589 : /* fall through */
      case 590 : /* fall through */
      case 591 :
        if ((entire_insn & 0xfc00000f) == 0x90000000)
          { itype = SH5_MEDIA_INSN_LDUB; sh5_media_extract_sfmt_ldb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 592 : /* fall through */
      case 593 : /* fall through */
      case 594 : /* fall through */
      case 595 : /* fall through */
      case 596 : /* fall through */
      case 597 : /* fall through */
      case 598 : /* fall through */
      case 599 : /* fall through */
      case 600 : /* fall through */
      case 601 : /* fall through */
      case 602 : /* fall through */
      case 603 : /* fall through */
      case 604 : /* fall through */
      case 605 : /* fall through */
      case 606 : /* fall through */
      case 607 :
        if ((entire_insn & 0xfc00000f) == 0x94000000)
          { itype = SH5_MEDIA_INSN_FLDS; sh5_media_extract_sfmt_flds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 608 : /* fall through */
      case 609 : /* fall through */
      case 610 : /* fall through */
      case 611 : /* fall through */
      case 612 : /* fall through */
      case 613 : /* fall through */
      case 614 : /* fall through */
      case 615 : /* fall through */
      case 616 : /* fall through */
      case 617 : /* fall through */
      case 618 : /* fall through */
      case 619 : /* fall through */
      case 620 : /* fall through */
      case 621 : /* fall through */
      case 622 : /* fall through */
      case 623 :
        if ((entire_insn & 0xfc00000f) == 0x98000000)
          { itype = SH5_MEDIA_INSN_FLDP; sh5_media_extract_sfmt_fldp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 624 : /* fall through */
      case 625 : /* fall through */
      case 626 : /* fall through */
      case 627 : /* fall through */
      case 628 : /* fall through */
      case 629 : /* fall through */
      case 630 : /* fall through */
      case 631 : /* fall through */
      case 632 : /* fall through */
      case 633 : /* fall through */
      case 634 : /* fall through */
      case 635 : /* fall through */
      case 636 : /* fall through */
      case 637 : /* fall through */
      case 638 : /* fall through */
      case 639 :
        if ((entire_insn & 0xfc00000f) == 0x9c000000)
          { itype = SH5_MEDIA_INSN_FLDD; sh5_media_extract_sfmt_fldd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 640 : /* fall through */
      case 641 : /* fall through */
      case 642 : /* fall through */
      case 643 : /* fall through */
      case 644 : /* fall through */
      case 645 : /* fall through */
      case 646 : /* fall through */
      case 647 : /* fall through */
      case 648 : /* fall through */
      case 649 : /* fall through */
      case 650 : /* fall through */
      case 651 : /* fall through */
      case 652 : /* fall through */
      case 653 : /* fall through */
      case 654 : /* fall through */
      case 655 :
        if ((entire_insn & 0xfc00000f) == 0xa0000000)
          { itype = SH5_MEDIA_INSN_STB; sh5_media_extract_sfmt_stb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 656 : /* fall through */
      case 657 : /* fall through */
      case 658 : /* fall through */
      case 659 : /* fall through */
      case 660 : /* fall through */
      case 661 : /* fall through */
      case 662 : /* fall through */
      case 663 : /* fall through */
      case 664 : /* fall through */
      case 665 : /* fall through */
      case 666 : /* fall through */
      case 667 : /* fall through */
      case 668 : /* fall through */
      case 669 : /* fall through */
      case 670 : /* fall through */
      case 671 :
        if ((entire_insn & 0xfc00000f) == 0xa4000000)
          { itype = SH5_MEDIA_INSN_STW; sh5_media_extract_sfmt_stw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 672 : /* fall through */
      case 673 : /* fall through */
      case 674 : /* fall through */
      case 675 : /* fall through */
      case 676 : /* fall through */
      case 677 : /* fall through */
      case 678 : /* fall through */
      case 679 : /* fall through */
      case 680 : /* fall through */
      case 681 : /* fall through */
      case 682 : /* fall through */
      case 683 : /* fall through */
      case 684 : /* fall through */
      case 685 : /* fall through */
      case 686 : /* fall through */
      case 687 :
        if ((entire_insn & 0xfc00000f) == 0xa8000000)
          { itype = SH5_MEDIA_INSN_STL; sh5_media_extract_sfmt_stl (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 688 : /* fall through */
      case 689 : /* fall through */
      case 690 : /* fall through */
      case 691 : /* fall through */
      case 692 : /* fall through */
      case 693 : /* fall through */
      case 694 : /* fall through */
      case 695 : /* fall through */
      case 696 : /* fall through */
      case 697 : /* fall through */
      case 698 : /* fall through */
      case 699 : /* fall through */
      case 700 : /* fall through */
      case 701 : /* fall through */
      case 702 : /* fall through */
      case 703 :
        if ((entire_insn & 0xfc00000f) == 0xac000000)
          { itype = SH5_MEDIA_INSN_STQ; sh5_media_extract_sfmt_stq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 704 : /* fall through */
      case 705 : /* fall through */
      case 706 : /* fall through */
      case 707 : /* fall through */
      case 708 : /* fall through */
      case 709 : /* fall through */
      case 710 : /* fall through */
      case 711 : /* fall through */
      case 712 : /* fall through */
      case 713 : /* fall through */
      case 714 : /* fall through */
      case 715 : /* fall through */
      case 716 : /* fall through */
      case 717 : /* fall through */
      case 718 : /* fall through */
      case 719 :
        if ((entire_insn & 0xfc00000f) == 0xb0000000)
          { itype = SH5_MEDIA_INSN_LDUW; sh5_media_extract_sfmt_lduw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 720 : /* fall through */
      case 721 : /* fall through */
      case 722 : /* fall through */
      case 723 : /* fall through */
      case 724 : /* fall through */
      case 725 : /* fall through */
      case 726 : /* fall through */
      case 727 : /* fall through */
      case 728 : /* fall through */
      case 729 : /* fall through */
      case 730 : /* fall through */
      case 731 : /* fall through */
      case 732 : /* fall through */
      case 733 : /* fall through */
      case 734 : /* fall through */
      case 735 :
        if ((entire_insn & 0xfc00000f) == 0xb4000000)
          { itype = SH5_MEDIA_INSN_FSTS; sh5_media_extract_sfmt_fsts (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 736 : /* fall through */
      case 737 : /* fall through */
      case 738 : /* fall through */
      case 739 : /* fall through */
      case 740 : /* fall through */
      case 741 : /* fall through */
      case 742 : /* fall through */
      case 743 : /* fall through */
      case 744 : /* fall through */
      case 745 : /* fall through */
      case 746 : /* fall through */
      case 747 : /* fall through */
      case 748 : /* fall through */
      case 749 : /* fall through */
      case 750 : /* fall through */
      case 751 :
        if ((entire_insn & 0xfc00000f) == 0xb8000000)
          { itype = SH5_MEDIA_INSN_FSTP; sh5_media_extract_sfmt_fldp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 752 : /* fall through */
      case 753 : /* fall through */
      case 754 : /* fall through */
      case 755 : /* fall through */
      case 756 : /* fall through */
      case 757 : /* fall through */
      case 758 : /* fall through */
      case 759 : /* fall through */
      case 760 : /* fall through */
      case 761 : /* fall through */
      case 762 : /* fall through */
      case 763 : /* fall through */
      case 764 : /* fall through */
      case 765 : /* fall through */
      case 766 : /* fall through */
      case 767 :
        if ((entire_insn & 0xfc00000f) == 0xbc000000)
          { itype = SH5_MEDIA_INSN_FSTD; sh5_media_extract_sfmt_fstd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 770 :
        if ((entire_insn & 0xfc0f000f) == 0xc0020000)
          { itype = SH5_MEDIA_INSN_LDLOL; sh5_media_extract_sfmt_ldlol (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 771 :
        if ((entire_insn & 0xfc0f000f) == 0xc0030000)
          { itype = SH5_MEDIA_INSN_LDLOQ; sh5_media_extract_sfmt_ldloq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 774 :
        if ((entire_insn & 0xfc0f000f) == 0xc0060000)
          { itype = SH5_MEDIA_INSN_LDHIL; sh5_media_extract_sfmt_ldhil (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 775 :
        if ((entire_insn & 0xfc0f000f) == 0xc0070000)
          { itype = SH5_MEDIA_INSN_LDHIQ; sh5_media_extract_sfmt_ldhiq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 783 :
        if ((entire_insn & 0xfc0f000f) == 0xc00f0000)
          { itype = SH5_MEDIA_INSN_GETCFG; sh5_media_extract_sfmt_getcfg (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 784 :
        if ((entire_insn & 0xfc0f000f) == 0xc4000000)
          { itype = SH5_MEDIA_INSN_SHLLIL; sh5_media_extract_sfmt_shari (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 785 :
        if ((entire_insn & 0xfc0f000f) == 0xc4010000)
          { itype = SH5_MEDIA_INSN_SHLLI; sh5_media_extract_sfmt_shari (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 786 :
        if ((entire_insn & 0xfc0f000f) == 0xc4020000)
          { itype = SH5_MEDIA_INSN_SHLRIL; sh5_media_extract_sfmt_shari (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 787 :
        if ((entire_insn & 0xfc0f000f) == 0xc4030000)
          { itype = SH5_MEDIA_INSN_SHLRI; sh5_media_extract_sfmt_shari (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 790 :
        if ((entire_insn & 0xfc0f000f) == 0xc4060000)
          { itype = SH5_MEDIA_INSN_SHARIL; sh5_media_extract_sfmt_shari (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 791 :
        if ((entire_insn & 0xfc0f000f) == 0xc4070000)
          { itype = SH5_MEDIA_INSN_SHARI; sh5_media_extract_sfmt_shari (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 797 :
        if ((entire_insn & 0xfc0f000f) == 0xc40d0000)
          { itype = SH5_MEDIA_INSN_XORI; sh5_media_extract_sfmt_xori (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 800 : /* fall through */
      case 801 : /* fall through */
      case 802 : /* fall through */
      case 803 : /* fall through */
      case 804 : /* fall through */
      case 805 : /* fall through */
      case 806 : /* fall through */
      case 807 : /* fall through */
      case 808 : /* fall through */
      case 809 : /* fall through */
      case 810 : /* fall through */
      case 811 : /* fall through */
      case 812 : /* fall through */
      case 813 : /* fall through */
      case 814 : /* fall through */
      case 815 :
        if ((entire_insn & 0xfc00000f) == 0xc8000000)
          { itype = SH5_MEDIA_INSN_SHORI; sh5_media_extract_sfmt_shori (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 816 : /* fall through */
      case 817 : /* fall through */
      case 818 : /* fall through */
      case 819 : /* fall through */
      case 820 : /* fall through */
      case 821 : /* fall through */
      case 822 : /* fall through */
      case 823 : /* fall through */
      case 824 : /* fall through */
      case 825 : /* fall through */
      case 826 : /* fall through */
      case 827 : /* fall through */
      case 828 : /* fall through */
      case 829 : /* fall through */
      case 830 : /* fall through */
      case 831 :
        if ((entire_insn & 0xfc00000f) == 0xcc000000)
          { itype = SH5_MEDIA_INSN_MOVI; sh5_media_extract_sfmt_movi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 832 : /* fall through */
      case 833 : /* fall through */
      case 834 : /* fall through */
      case 835 : /* fall through */
      case 836 : /* fall through */
      case 837 : /* fall through */
      case 838 : /* fall through */
      case 839 : /* fall through */
      case 840 : /* fall through */
      case 841 : /* fall through */
      case 842 : /* fall through */
      case 843 : /* fall through */
      case 844 : /* fall through */
      case 845 : /* fall through */
      case 846 : /* fall through */
      case 847 :
        if ((entire_insn & 0xfc00000f) == 0xd0000000)
          { itype = SH5_MEDIA_INSN_ADDI; sh5_media_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 848 : /* fall through */
      case 849 : /* fall through */
      case 850 : /* fall through */
      case 851 : /* fall through */
      case 852 : /* fall through */
      case 853 : /* fall through */
      case 854 : /* fall through */
      case 855 : /* fall through */
      case 856 : /* fall through */
      case 857 : /* fall through */
      case 858 : /* fall through */
      case 859 : /* fall through */
      case 860 : /* fall through */
      case 861 : /* fall through */
      case 862 : /* fall through */
      case 863 :
        if ((entire_insn & 0xfc00000f) == 0xd4000000)
          { itype = SH5_MEDIA_INSN_ADDIL; sh5_media_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 864 : /* fall through */
      case 865 : /* fall through */
      case 866 : /* fall through */
      case 867 : /* fall through */
      case 868 : /* fall through */
      case 869 : /* fall through */
      case 870 : /* fall through */
      case 871 : /* fall through */
      case 872 : /* fall through */
      case 873 : /* fall through */
      case 874 : /* fall through */
      case 875 : /* fall through */
      case 876 : /* fall through */
      case 877 : /* fall through */
      case 878 : /* fall through */
      case 879 :
        if ((entire_insn & 0xfc00000f) == 0xd8000000)
          { itype = SH5_MEDIA_INSN_ANDI; sh5_media_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 880 : /* fall through */
      case 881 : /* fall through */
      case 882 : /* fall through */
      case 883 : /* fall through */
      case 884 : /* fall through */
      case 885 : /* fall through */
      case 886 : /* fall through */
      case 887 : /* fall through */
      case 888 : /* fall through */
      case 889 : /* fall through */
      case 890 : /* fall through */
      case 891 : /* fall through */
      case 892 : /* fall through */
      case 893 : /* fall through */
      case 894 : /* fall through */
      case 895 :
        if ((entire_insn & 0xfc00000f) == 0xdc000000)
          { itype = SH5_MEDIA_INSN_ORI; sh5_media_extract_sfmt_ori (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 897 :
        if ((entire_insn & 0xfc0ffc0f) == 0xe001fc00)
          { itype = SH5_MEDIA_INSN_PREFI; sh5_media_extract_sfmt_alloco (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 898 :
        if ((entire_insn & 0xfc0f000f) == 0xe0020000)
          { itype = SH5_MEDIA_INSN_STLOL; sh5_media_extract_sfmt_stlol (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 899 :
        if ((entire_insn & 0xfc0f000f) == 0xe0030000)
          { itype = SH5_MEDIA_INSN_STLOQ; sh5_media_extract_sfmt_stloq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 900 :
        if ((entire_insn & 0xfc0f03ff) == 0xe00403f0)
          { itype = SH5_MEDIA_INSN_ALLOCO; sh5_media_extract_sfmt_alloco (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 901 :
        if ((entire_insn & 0xfc0f03ff) == 0xe00503f0)
          { itype = SH5_MEDIA_INSN_ICBI; sh5_media_extract_sfmt_alloco (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 902 :
        if ((entire_insn & 0xfc0f000f) == 0xe0060000)
          { itype = SH5_MEDIA_INSN_STHIL; sh5_media_extract_sfmt_sthil (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 903 :
        if ((entire_insn & 0xfc0f000f) == 0xe0070000)
          { itype = SH5_MEDIA_INSN_STHIQ; sh5_media_extract_sfmt_sthiq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 904 :
        if ((entire_insn & 0xfc0f03ff) == 0xe00803f0)
          { itype = SH5_MEDIA_INSN_OCBP; sh5_media_extract_sfmt_alloco (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 905 :
        if ((entire_insn & 0xfc0f03ff) == 0xe00903f0)
          { itype = SH5_MEDIA_INSN_OCBI; sh5_media_extract_sfmt_alloco (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 908 :
        if ((entire_insn & 0xfc0f03ff) == 0xe00c03f0)
          { itype = SH5_MEDIA_INSN_OCBWB; sh5_media_extract_sfmt_alloco (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 911 :
        if ((entire_insn & 0xfc0f000f) == 0xe00f0000)
          { itype = SH5_MEDIA_INSN_PUTCFG; sh5_media_extract_sfmt_putcfg (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 913 :
        if ((entire_insn & 0xfc0f018f) == 0xe4010000)
          { itype = SH5_MEDIA_INSN_BEQI; sh5_media_extract_sfmt_beqi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 917 :
        if ((entire_insn & 0xfc0f018f) == 0xe4050000)
          { itype = SH5_MEDIA_INSN_BNEI; sh5_media_extract_sfmt_beqi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 928 : /* fall through */
      case 929 : /* fall through */
      case 930 : /* fall through */
      case 931 : /* fall through */
      case 932 : /* fall through */
      case 933 : /* fall through */
      case 934 : /* fall through */
      case 935 : /* fall through */
      case 936 : /* fall through */
      case 937 : /* fall through */
      case 938 : /* fall through */
      case 939 : /* fall through */
      case 940 : /* fall through */
      case 941 : /* fall through */
      case 942 : /* fall through */
      case 943 :
        if ((entire_insn & 0xfc00018f) == 0xe8000000)
          { itype = SH5_MEDIA_INSN_PTA; sh5_media_extract_sfmt_pta (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 944 : /* fall through */
      case 945 : /* fall through */
      case 946 : /* fall through */
      case 947 : /* fall through */
      case 948 : /* fall through */
      case 949 : /* fall through */
      case 950 : /* fall through */
      case 951 : /* fall through */
      case 952 : /* fall through */
      case 953 : /* fall through */
      case 954 : /* fall through */
      case 955 : /* fall through */
      case 956 : /* fall through */
      case 957 : /* fall through */
      case 958 : /* fall through */
      case 959 :
        if ((entire_insn & 0xfc00018f) == 0xec000000)
          { itype = SH5_MEDIA_INSN_PTB; sh5_media_extract_sfmt_pta (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = SH5_MEDIA_INSN_X_INVALID; sh5_media_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & sh5_media_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
sh5_media_extract_sfmt_empty (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
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
sh5_media_extract_sfmt_add (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_addi (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_left;
    INT f_disp10;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10 = EXTRACT_MSB0_SINT (insn, 32, 12, 10);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10) = f_disp10;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addi)\t"
        << " f_disp10:0x" << hex << f_disp10 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_alloco (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_alloco.f
    UINT f_left;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alloco)\t"
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_beq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    UINT f_left;
    UINT f_right;
    UINT f_likely;
    UINT f_tra;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_likely = EXTRACT_MSB0_UINT (insn, 32, 22, 1);
    f_tra = EXTRACT_MSB0_UINT (insn, 32, 25, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_likely) = f_likely;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_tra) = f_tra;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beq)\t"
        << " f_likely:0x" << hex << f_likely << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_tra:0x" << hex << f_tra << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (in_tra) = f_tra;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_beqi (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beqi.f
    UINT f_left;
    INT f_imm6;
    UINT f_likely;
    UINT f_tra;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_imm6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_likely = EXTRACT_MSB0_UINT (insn, 32, 22, 1);
    f_tra = EXTRACT_MSB0_UINT (insn, 32, 25, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm6) = f_imm6;
  FLD (f_likely) = f_likely;
  FLD (f_left) = f_left;
  FLD (f_tra) = f_tra;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beqi)\t"
        << " f_imm6:0x" << hex << f_imm6 << dec
        << " f_likely:0x" << hex << f_likely << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_tra:0x" << hex << f_tra << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_tra) = f_tra;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_blink (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_blink.f
    UINT f_trb;
    UINT f_dest;

    f_trb = EXTRACT_MSB0_UINT (insn, 32, 9, 3);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_trb) = f_trb;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_blink)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_trb:0x" << hex << f_trb << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_trb) = f_trb;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_brk (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_brk)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
sh5_media_extract_sfmt_byterev (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_xori.f
    UINT f_left;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_byterev)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_cmveq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmveq)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fabsd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fabsd.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fabsd)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drgh) = f_left_right;
      FLD (out_drf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fabss (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fabss.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fabss)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frgh) = f_left_right;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_faddd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_faddd.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_faddd)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drg) = f_left;
      FLD (in_drh) = f_right;
      FLD (out_drf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fadds (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fmacs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fadds)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frg) = f_left;
      FLD (in_frh) = f_right;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fcmpeqd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fcmpeqd.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fcmpeqd)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drg) = f_left;
      FLD (in_drh) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fcmpeqs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fcmpeqs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fcmpeqs)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frg) = f_left;
      FLD (in_frh) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fcnvds (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fcnvds.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fcnvds)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drgh) = f_left_right;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fcnvsd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fcnvsd.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fcnvsd)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frgh) = f_left_right;
      FLD (out_drf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fgetscr (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fcnvds.f
    UINT f_dest;

    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fgetscr)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fiprs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fiprs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fiprs)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_fvg) = f_left;
      FLD (in_fvh) = f_right;
      FLD (out_frf) = f_dest;
      FLD (out_fvg) = f_left;
      FLD (out_fvh) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fldd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fldd.f
    UINT f_left;
    SI f_disp10x8;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x8 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (3));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x8) = f_disp10x8;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fldd)\t"
        << " f_disp10x8:0x" << hex << f_disp10x8 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_drf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fldp (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fldp.f
    UINT f_left;
    SI f_disp10x8;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x8 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (3));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x8) = f_disp10x8;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fldp)\t"
        << " f_disp10x8:0x" << hex << f_disp10x8 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_fpf) = f_dest;
      FLD (in_rm) = f_left;
      FLD (out_fpf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_flds (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_flds.f
    UINT f_left;
    SI f_disp10x4;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x4 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (2));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x4) = f_disp10x4;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_flds)\t"
        << " f_disp10x4:0x" << hex << f_disp10x4 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fldxd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fldxd.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fldxd)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_drf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fldxp (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fldxp.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fldxp)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_fpf) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_fpf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fldxs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fldxs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fldxs)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fmacs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fmacs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fmacs)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frf) = f_dest;
      FLD (in_frg) = f_left;
      FLD (in_frh) = f_right;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fmovdq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fmovdq.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fmovdq)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drgh) = f_left_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fmovls (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_flds.f
    UINT f_left;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fmovls)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_frf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fmovqd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fldd.f
    UINT f_left;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fmovqd)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_drf) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fmovsl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fmovsl.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fmovsl)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frgh) = f_left_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fputscr (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fmovsl.f
    UINT f_left;
    UINT f_right;
    UINT f_left_right;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
  f_left_right = f_left;

  /* Record the fields for the semantic handler.  */
  FLD (f_left_right) = f_left_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fputscr)\t"
        << " f_left_right:0x" << hex << f_left_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frgh) = f_left_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fstd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fstd.f
    UINT f_left;
    SI f_disp10x8;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x8 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (3));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x8) = f_disp10x8;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fstd)\t"
        << " f_disp10x8:0x" << hex << f_disp10x8 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drf) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fsts (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fsts.f
    UINT f_left;
    SI f_disp10x4;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x4 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (2));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x4) = f_disp10x4;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fsts)\t"
        << " f_disp10x4:0x" << hex << f_disp10x4 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frf) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fstxd (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fstxd.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fstxd)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_drf) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_fstxs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fstxs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fstxs)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_frf) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ftrvs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ftrvs.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ftrvs)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_fvf) = f_dest;
      FLD (in_fvh) = f_right;
      FLD (in_mtrxg) = f_left;
      FLD (out_fvf) = f_dest;
      FLD (out_fvh) = f_right;
      FLD (out_mtrxg) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_getcfg (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_getcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_getcfg)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_getcon (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_xori.f
    UINT f_left;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_getcon)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_gettr (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_blink.f
    UINT f_trb;
    UINT f_dest;

    f_trb = EXTRACT_MSB0_UINT (insn, 32, 9, 3);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_trb) = f_trb;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_gettr)\t"
        << " f_trb:0x" << hex << f_trb << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_trb) = f_trb;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_left;
    INT f_disp10;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10 = EXTRACT_MSB0_SINT (insn, 32, 12, 10);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10) = f_disp10;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldb)\t"
        << " f_disp10:0x" << hex << f_disp10 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldl.f
    UINT f_left;
    SI f_disp10x4;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x4 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (2));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x4) = f_disp10x4;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldl)\t"
        << " f_disp10x4:0x" << hex << f_disp10x4 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldq.f
    UINT f_left;
    SI f_disp10x8;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x8 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (3));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x8) = f_disp10x8;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldq)\t"
        << " f_disp10x8:0x" << hex << f_disp10x8 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_lduw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lduw.f
    UINT f_left;
    SI f_disp10x2;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x2 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (1));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x2) = f_disp10x2;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lduw)\t"
        << " f_disp10x2:0x" << hex << f_disp10x2 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldhil (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_getcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldhil)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldhiq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_getcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldhiq)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldlol (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_getcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldlol)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldloq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_getcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldloq)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldxb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldxb)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldxl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldxl)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldxq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldxq)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldxub (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldxub)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldxuw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldxuw)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ldxw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldxw)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_mcmv (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mcmv)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_movi (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movi.f
    INT f_imm16;
    UINT f_dest;

    f_imm16 = EXTRACT_MSB0_SINT (insn, 32, 6, 16);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm16) = f_imm16;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movi)\t"
        << " f_imm16:0x" << hex << f_imm16 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_nop (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
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
sh5_media_extract_sfmt_ori (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ori.f
    UINT f_left;
    INT f_imm10;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_imm10 = EXTRACT_MSB0_SINT (insn, 32, 12, 10);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm10) = f_imm10;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ori)\t"
        << " f_imm10:0x" << hex << f_imm10 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_pta (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_pta.f
    DI f_disp16;
    UINT f_likely;
    UINT f_tra;

    f_disp16 = ((((EXTRACT_MSB0_SINT (insn, 32, 6, 16)) << (2))) + (pc));
    f_likely = EXTRACT_MSB0_UINT (insn, 32, 22, 1);
    f_tra = EXTRACT_MSB0_UINT (insn, 32, 25, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp16) = f_disp16;
  FLD (f_tra) = f_tra;
  FLD (f_likely) = f_likely;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_pta)\t"
        << " f_disp16:0x" << hex << f_disp16 << dec
        << " f_tra:0x" << hex << f_tra << dec
        << " f_likely:0x" << hex << f_likely << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_tra) = f_tra;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ptabs (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ptabs.f
    UINT f_right;
    UINT f_likely;
    UINT f_tra;

    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_likely = EXTRACT_MSB0_UINT (insn, 32, 22, 1);
    f_tra = EXTRACT_MSB0_UINT (insn, 32, 25, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_tra) = f_tra;
  FLD (f_likely) = f_likely;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ptabs)\t"
        << " f_tra:0x" << hex << f_tra << dec
        << " f_likely:0x" << hex << f_likely << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_right;
      FLD (out_tra) = f_tra;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_ptrel (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ptabs.f
    UINT f_right;
    UINT f_likely;
    UINT f_tra;

    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_likely = EXTRACT_MSB0_UINT (insn, 32, 22, 1);
    f_tra = EXTRACT_MSB0_UINT (insn, 32, 25, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_tra) = f_tra;
  FLD (f_likely) = f_likely;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ptrel)\t"
        << " f_tra:0x" << hex << f_tra << dec
        << " f_likely:0x" << hex << f_likely << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_right;
      FLD (out_tra) = f_tra;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_putcfg (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_putcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_putcfg)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_putcon (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_xori.f
    UINT f_left;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_putcon)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_shari (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shari.f
    UINT f_left;
    UINT f_uimm6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_uimm6 = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  FLD (f_uimm6) = f_uimm6;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shari)\t"
        << " f_left:0x" << hex << f_left << dec
        << " f_uimm6:0x" << hex << f_uimm6 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_shori (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shori.f
    UINT f_uimm16;
    UINT f_dest;

    f_uimm16 = EXTRACT_MSB0_UINT (insn, 32, 6, 16);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_uimm16) = f_uimm16;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shori)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_uimm16:0x" << hex << f_uimm16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stb.f
    UINT f_left;
    INT f_disp10;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10 = EXTRACT_MSB0_SINT (insn, 32, 12, 10);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10) = f_disp10;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stb)\t"
        << " f_disp10:0x" << hex << f_disp10 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stl.f
    UINT f_left;
    SI f_disp10x4;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x4 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (2));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x4) = f_disp10x4;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stl)\t"
        << " f_disp10x4:0x" << hex << f_disp10x4 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stq.f
    UINT f_left;
    SI f_disp10x8;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x8 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (3));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x8) = f_disp10x8;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stq)\t"
        << " f_disp10x8:0x" << hex << f_disp10x8 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stw.f
    UINT f_left;
    SI f_disp10x2;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp10x2 = ((EXTRACT_MSB0_SINT (insn, 32, 12, 10)) << (1));
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp10x2) = f_disp10x2;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stw)\t"
        << " f_disp10x2:0x" << hex << f_disp10x2 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_sthil (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_putcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sthil)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_sthiq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_putcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sthiq)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stlol (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_putcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stlol)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stloq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_putcfg.f
    UINT f_left;
    INT f_disp6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_disp6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_disp6) = f_disp6;
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stloq)\t"
        << " f_disp6:0x" << hex << f_disp6 << dec
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stxb (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stxb)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stxl (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stxl)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stxq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stxq)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_stxw (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stxw)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_swapq (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mcmv.f
    UINT f_left;
    UINT f_right;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_right = EXTRACT_MSB0_UINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_dest) = f_dest;
  FLD (f_left) = f_left;
  FLD (f_right) = f_right;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swapq)\t"
        << " f_dest:0x" << hex << f_dest << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_right:0x" << hex << f_right << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rd) = f_dest;
      FLD (in_rm) = f_left;
      FLD (in_rn) = f_right;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_trapa (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_alloco.f
    UINT f_left;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_left) = f_left;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_trapa)\t"
        << " f_left:0x" << hex << f_left << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
    }
#undef FLD
}

void
sh5_media_extract_sfmt_xori (sh5_media_scache* abuf, sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn){
    sh5_media_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_xori.f
    UINT f_left;
    INT f_imm6;
    UINT f_dest;

    f_left = EXTRACT_MSB0_UINT (insn, 32, 6, 6);
    f_imm6 = EXTRACT_MSB0_SINT (insn, 32, 16, 6);
    f_dest = EXTRACT_MSB0_UINT (insn, 32, 22, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_imm6) = f_imm6;
  FLD (f_left) = f_left;
  FLD (f_dest) = f_dest;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_xori)\t"
        << " f_imm6:0x" << hex << f_imm6 << dec
        << " f_left:0x" << hex << f_left << dec
        << " f_dest:0x" << hex << f_dest << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_left;
      FLD (out_rd) = f_dest;
    }
#undef FLD
}

