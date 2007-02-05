/* Simulator instruction decoder for mepcore2.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext2.h"

using namespace mep_ext2; // FIXME: namespace organization still wip


// The instruction descriptor array. 

mepcore2_idesc mepcore2_idesc::idesc_table[MEPCORE2_INSN_CMOVC_RM_CCRN + 1] =
{
  { mepcore2_sem_x_invalid, "X_INVALID", MEPCORE2_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sb, "SB", MEPCORE2_INSN_SB, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sh, "SH", MEPCORE2_INSN_SH, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sw, "SW", MEPCORE2_INSN_SW, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lb, "LB", MEPCORE2_INSN_LB, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lh, "LH", MEPCORE2_INSN_LH, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lw, "LW", MEPCORE2_INSN_LW, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lbu, "LBU", MEPCORE2_INSN_LBU, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lhu, "LHU", MEPCORE2_INSN_LHU, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_sw_sp, "SW_SP", MEPCORE2_INSN_SW_SP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lw_sp, "LW_SP", MEPCORE2_INSN_LW_SP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_sb_tp, "SB_TP", MEPCORE2_INSN_SB_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sh_tp, "SH_TP", MEPCORE2_INSN_SH_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sw_tp, "SW_TP", MEPCORE2_INSN_SW_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lb_tp, "LB_TP", MEPCORE2_INSN_LB_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lh_tp, "LH_TP", MEPCORE2_INSN_LH_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lw_tp, "LW_TP", MEPCORE2_INSN_LW_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lbu_tp, "LBU_TP", MEPCORE2_INSN_LBU_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lhu_tp, "LHU_TP", MEPCORE2_INSN_LHU_TP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_sb16, "SB16", MEPCORE2_INSN_SB16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sh16, "SH16", MEPCORE2_INSN_SH16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sw16, "SW16", MEPCORE2_INSN_SW16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lb16, "LB16", MEPCORE2_INSN_LB16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lh16, "LH16", MEPCORE2_INSN_LH16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lw16, "LW16", MEPCORE2_INSN_LW16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lbu16, "LBU16", MEPCORE2_INSN_LBU16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_lhu16, "LHU16", MEPCORE2_INSN_LHU16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_sw24, "SW24", MEPCORE2_INSN_SW24, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lw24, "LW24", MEPCORE2_INSN_LW24, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_extb, "EXTB", MEPCORE2_INSN_EXTB, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_exth, "EXTH", MEPCORE2_INSN_EXTH, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_extub, "EXTUB", MEPCORE2_INSN_EXTUB, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_extuh, "EXTUH", MEPCORE2_INSN_EXTUH, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ssarb, "SSARB", MEPCORE2_INSN_SSARB, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_mov, "MOV", MEPCORE2_INSN_MOV, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_movi8, "MOVI8", MEPCORE2_INSN_MOVI8, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_movi16, "MOVI16", MEPCORE2_INSN_MOVI16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_movu24, "MOVU24", MEPCORE2_INSN_MOVU24, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_movu16, "MOVU16", MEPCORE2_INSN_MOVU16, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_movh, "MOVH", MEPCORE2_INSN_MOVH, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_add3, "ADD3", MEPCORE2_INSN_ADD3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_add, "ADD", MEPCORE2_INSN_ADD, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_add3i, "ADD3I", MEPCORE2_INSN_ADD3I, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_advck3, "ADVCK3", MEPCORE2_INSN_ADVCK3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sub, "SUB", MEPCORE2_INSN_SUB, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sbvck3, "SBVCK3", MEPCORE2_INSN_SBVCK3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_neg, "NEG", MEPCORE2_INSN_NEG, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_slt3, "SLT3", MEPCORE2_INSN_SLT3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sltu3, "SLTU3", MEPCORE2_INSN_SLTU3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_slt3i, "SLT3I", MEPCORE2_INSN_SLT3I, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sltu3i, "SLTU3I", MEPCORE2_INSN_SLTU3I, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sl1ad3, "SL1AD3", MEPCORE2_INSN_SL1AD3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sl2ad3, "SL2AD3", MEPCORE2_INSN_SL2AD3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_add3x, "ADD3X", MEPCORE2_INSN_ADD3X, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_slt3x, "SLT3X", MEPCORE2_INSN_SLT3X, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sltu3x, "SLTU3X", MEPCORE2_INSN_SLTU3X, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_or, "OR", MEPCORE2_INSN_OR, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_and, "AND", MEPCORE2_INSN_AND, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_xor, "XOR", MEPCORE2_INSN_XOR, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_nor, "NOR", MEPCORE2_INSN_NOR, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_or3, "OR3", MEPCORE2_INSN_OR3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_and3, "AND3", MEPCORE2_INSN_AND3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_xor3, "XOR3", MEPCORE2_INSN_XOR3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sra, "SRA", MEPCORE2_INSN_SRA, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_srl, "SRL", MEPCORE2_INSN_SRL, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sll, "SLL", MEPCORE2_INSN_SLL, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_srai, "SRAI", MEPCORE2_INSN_SRAI, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_srli, "SRLI", MEPCORE2_INSN_SRLI, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_slli, "SLLI", MEPCORE2_INSN_SLLI, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sll3, "SLL3", MEPCORE2_INSN_SLL3, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fsft, "FSFT", MEPCORE2_INSN_FSFT, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bra, "BRA", MEPCORE2_INSN_BRA, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_beqz, "BEQZ", MEPCORE2_INSN_BEQZ, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bnez, "BNEZ", MEPCORE2_INSN_BNEZ, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_beqi, "BEQI", MEPCORE2_INSN_BEQI, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bnei, "BNEI", MEPCORE2_INSN_BNEI, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_blti, "BLTI", MEPCORE2_INSN_BLTI, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bgei, "BGEI", MEPCORE2_INSN_BGEI, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_beq, "BEQ", MEPCORE2_INSN_BEQ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bne, "BNE", MEPCORE2_INSN_BNE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bsr12, "BSR12", MEPCORE2_INSN_BSR12, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bsr24, "BSR24", MEPCORE2_INSN_BSR24, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_jmp, "JMP", MEPCORE2_INSN_JMP, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_jmp24, "JMP24", MEPCORE2_INSN_JMP24, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_jsr, "JSR", MEPCORE2_INSN_JSR, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ret, "RET", MEPCORE2_INSN_RET, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_repeat, "REPEAT", MEPCORE2_INSN_REPEAT, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_erepeat, "EREPEAT", MEPCORE2_INSN_EREPEAT, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_stc_lp, "STC_LP", MEPCORE2_INSN_STC_LP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_stc_hi, "STC_HI", MEPCORE2_INSN_STC_HI, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_stc_lo, "STC_LO", MEPCORE2_INSN_STC_LO, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_stc, "STC", MEPCORE2_INSN_STC, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ldc_lp, "LDC_LP", MEPCORE2_INSN_LDC_LP, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ldc_hi, "LDC_HI", MEPCORE2_INSN_LDC_HI, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ldc_lo, "LDC_LO", MEPCORE2_INSN_LDC_LO, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ldc, "LDC", MEPCORE2_INSN_LDC, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 2, CONFIG_NONE } },
  { mepcore2_sem_di, "DI", MEPCORE2_INSN_DI, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ei, "EI", MEPCORE2_INSN_EI, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_reti, "RETI", MEPCORE2_INSN_RETI, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_halt, "HALT", MEPCORE2_INSN_HALT, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sleep, "SLEEP", MEPCORE2_INSN_SLEEP, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swi, "SWI", MEPCORE2_INSN_SWI, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_break, "BREAK", MEPCORE2_INSN_BREAK, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_MAY_TRAP)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_syncm, "SYNCM", MEPCORE2_INSN_SYNCM, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_stcb, "STCB", MEPCORE2_INSN_STCB, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ldcb, "LDCB", MEPCORE2_INSN_LDCB, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 3, CONFIG_NONE } },
  { mepcore2_sem_bsetm, "BSETM", MEPCORE2_INSN_BSETM, { 0|(1<<CGEN_INSN_OPTIONAL_BIT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bclrm, "BCLRM", MEPCORE2_INSN_BCLRM, { 0|(1<<CGEN_INSN_OPTIONAL_BIT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bnotm, "BNOTM", MEPCORE2_INSN_BNOTM, { 0|(1<<CGEN_INSN_OPTIONAL_BIT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_btstm, "BTSTM", MEPCORE2_INSN_BTSTM, { 0|(1<<CGEN_INSN_OPTIONAL_BIT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_tas, "TAS", MEPCORE2_INSN_TAS, { 0|(1<<CGEN_INSN_OPTIONAL_BIT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_cache, "CACHE", MEPCORE2_INSN_CACHE, { 0|(1<<CGEN_INSN_VOLATILE), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_mul, "MUL", MEPCORE2_INSN_MUL, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_mulu, "MULU", MEPCORE2_INSN_MULU, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_mulr, "MULR", MEPCORE2_INSN_MULR, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 3, CONFIG_NONE } },
  { mepcore2_sem_mulru, "MULRU", MEPCORE2_INSN_MULRU, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 3, CONFIG_NONE } },
  { mepcore2_sem_madd, "MADD", MEPCORE2_INSN_MADD, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_maddu, "MADDU", MEPCORE2_INSN_MADDU, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_maddr, "MADDR", MEPCORE2_INSN_MADDR, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 3, CONFIG_NONE } },
  { mepcore2_sem_maddru, "MADDRU", MEPCORE2_INSN_MADDRU, { 0|(1<<CGEN_INSN_OPTIONAL_MUL_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 3, CONFIG_NONE } },
  { mepcore2_sem_div, "DIV", MEPCORE2_INSN_DIV, { 0|(1<<CGEN_INSN_MAY_TRAP)|(1<<CGEN_INSN_OPTIONAL_DIV_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 34, CONFIG_NONE } },
  { mepcore2_sem_divu, "DIVU", MEPCORE2_INSN_DIVU, { 0|(1<<CGEN_INSN_MAY_TRAP)|(1<<CGEN_INSN_OPTIONAL_DIV_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 34, CONFIG_NONE } },
  { mepcore2_sem_dret, "DRET", MEPCORE2_INSN_DRET, { 0|(1<<CGEN_INSN_OPTIONAL_DEBUG_INSN)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_dbreak, "DBREAK", MEPCORE2_INSN_DBREAK, { 0|(1<<CGEN_INSN_VOLATILE)|(1<<CGEN_INSN_MAY_TRAP)|(1<<CGEN_INSN_OPTIONAL_DEBUG_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ldz, "LDZ", MEPCORE2_INSN_LDZ, { 0|(1<<CGEN_INSN_OPTIONAL_LDZ_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_abs, "ABS", MEPCORE2_INSN_ABS, { 0|(1<<CGEN_INSN_OPTIONAL_ABS_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ave, "AVE", MEPCORE2_INSN_AVE, { 0|(1<<CGEN_INSN_OPTIONAL_AVE_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_min, "MIN", MEPCORE2_INSN_MIN, { 0|(1<<CGEN_INSN_OPTIONAL_MINMAX_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_max, "MAX", MEPCORE2_INSN_MAX, { 0|(1<<CGEN_INSN_OPTIONAL_MINMAX_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_minu, "MINU", MEPCORE2_INSN_MINU, { 0|(1<<CGEN_INSN_OPTIONAL_MINMAX_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_maxu, "MAXU", MEPCORE2_INSN_MAXU, { 0|(1<<CGEN_INSN_OPTIONAL_MINMAX_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_clip, "CLIP", MEPCORE2_INSN_CLIP, { 0|(1<<CGEN_INSN_OPTIONAL_CLIP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_clipu, "CLIPU", MEPCORE2_INSN_CLIPU, { 0|(1<<CGEN_INSN_OPTIONAL_CLIP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sadd, "SADD", MEPCORE2_INSN_SADD, { 0|(1<<CGEN_INSN_OPTIONAL_SAT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ssub, "SSUB", MEPCORE2_INSN_SSUB, { 0|(1<<CGEN_INSN_OPTIONAL_SAT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_saddu, "SADDU", MEPCORE2_INSN_SADDU, { 0|(1<<CGEN_INSN_OPTIONAL_SAT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ssubu, "SSUBU", MEPCORE2_INSN_SSUBU, { 0|(1<<CGEN_INSN_OPTIONAL_SAT_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swcp, "SWCP", MEPCORE2_INSN_SWCP, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lwcp, "LWCP", MEPCORE2_INSN_LWCP, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_smcp, "SMCP", MEPCORE2_INSN_SMCP, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lmcp, "LMCP", MEPCORE2_INSN_LMCP, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swcpi, "SWCPI", MEPCORE2_INSN_SWCPI, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lwcpi, "LWCPI", MEPCORE2_INSN_LWCPI, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_smcpi, "SMCPI", MEPCORE2_INSN_SMCPI, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lmcpi, "LMCPI", MEPCORE2_INSN_LMCPI, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swcp16, "SWCP16", MEPCORE2_INSN_SWCP16, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lwcp16, "LWCP16", MEPCORE2_INSN_LWCP16, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_smcp16, "SMCP16", MEPCORE2_INSN_SMCP16, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lmcp16, "LMCP16", MEPCORE2_INSN_LMCP16, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sbcpa, "SBCPA", MEPCORE2_INSN_SBCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lbcpa, "LBCPA", MEPCORE2_INSN_LBCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_shcpa, "SHCPA", MEPCORE2_INSN_SHCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lhcpa, "LHCPA", MEPCORE2_INSN_LHCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swcpa, "SWCPA", MEPCORE2_INSN_SWCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lwcpa, "LWCPA", MEPCORE2_INSN_LWCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_smcpa, "SMCPA", MEPCORE2_INSN_SMCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lmcpa, "LMCPA", MEPCORE2_INSN_LMCPA, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sbcpm0, "SBCPM0", MEPCORE2_INSN_SBCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lbcpm0, "LBCPM0", MEPCORE2_INSN_LBCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_shcpm0, "SHCPM0", MEPCORE2_INSN_SHCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lhcpm0, "LHCPM0", MEPCORE2_INSN_LHCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swcpm0, "SWCPM0", MEPCORE2_INSN_SWCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lwcpm0, "LWCPM0", MEPCORE2_INSN_LWCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_smcpm0, "SMCPM0", MEPCORE2_INSN_SMCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lmcpm0, "LMCPM0", MEPCORE2_INSN_LMCPM0, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sbcpm1, "SBCPM1", MEPCORE2_INSN_SBCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lbcpm1, "LBCPM1", MEPCORE2_INSN_LBCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_shcpm1, "SHCPM1", MEPCORE2_INSN_SHCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lhcpm1, "LHCPM1", MEPCORE2_INSN_LHCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_swcpm1, "SWCPM1", MEPCORE2_INSN_SWCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lwcpm1, "LWCPM1", MEPCORE2_INSN_LWCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_smcpm1, "SMCPM1", MEPCORE2_INSN_SMCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_lmcpm1, "LMCPM1", MEPCORE2_INSN_LMCPM1, { 0|(1<<CGEN_INSN_OPTIONAL_CP64_INSN)|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bcpeq, "BCPEQ", MEPCORE2_INSN_BCPEQ, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bcpne, "BCPNE", MEPCORE2_INSN_BCPNE, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bcpat, "BCPAT", MEPCORE2_INSN_BCPAT, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bcpaf, "BCPAF", MEPCORE2_INSN_BCPAF, { 0|(1<<CGEN_INSN_RELAXABLE)|(1<<CGEN_INSN_OPTIONAL_CP_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_synccp, "SYNCCP", MEPCORE2_INSN_SYNCCP, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_jsrv, "JSRV", MEPCORE2_INSN_JSRV, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_bsrv, "BSRV", MEPCORE2_INSN_BSRV, { 0|(1<<CGEN_INSN_OPTIONAL_CP_INSN)|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_sim_syscall, "SIM_SYSCALL", MEPCORE2_INSN_SIM_SYSCALL, { 0, (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_0, "RI_0", MEPCORE2_INSN_RI_0, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_1, "RI_1", MEPCORE2_INSN_RI_1, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_2, "RI_2", MEPCORE2_INSN_RI_2, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_3, "RI_3", MEPCORE2_INSN_RI_3, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_4, "RI_4", MEPCORE2_INSN_RI_4, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_5, "RI_5", MEPCORE2_INSN_RI_5, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_6, "RI_6", MEPCORE2_INSN_RI_6, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_7, "RI_7", MEPCORE2_INSN_RI_7, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_8, "RI_8", MEPCORE2_INSN_RI_8, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_9, "RI_9", MEPCORE2_INSN_RI_9, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_10, "RI_10", MEPCORE2_INSN_RI_10, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_11, "RI_11", MEPCORE2_INSN_RI_11, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_12, "RI_12", MEPCORE2_INSN_RI_12, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_13, "RI_13", MEPCORE2_INSN_RI_13, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_14, "RI_14", MEPCORE2_INSN_RI_14, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_15, "RI_15", MEPCORE2_INSN_RI_15, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_17, "RI_17", MEPCORE2_INSN_RI_17, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_20, "RI_20", MEPCORE2_INSN_RI_20, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_21, "RI_21", MEPCORE2_INSN_RI_21, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_22, "RI_22", MEPCORE2_INSN_RI_22, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_23, "RI_23", MEPCORE2_INSN_RI_23, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_24, "RI_24", MEPCORE2_INSN_RI_24, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_25, "RI_25", MEPCORE2_INSN_RI_25, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_26, "RI_26", MEPCORE2_INSN_RI_26, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_16, "RI_16", MEPCORE2_INSN_RI_16, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_18, "RI_18", MEPCORE2_INSN_RI_18, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ri_19, "RI_19", MEPCORE2_INSN_RI_19, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\xe0" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fadds, "FADDS", MEPCORE2_INSN_FADDS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fsubs, "FSUBS", MEPCORE2_INSN_FSUBS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fmuls, "FMULS", MEPCORE2_INSN_FMULS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fdivs, "FDIVS", MEPCORE2_INSN_FDIVS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fsqrts, "FSQRTS", MEPCORE2_INSN_FSQRTS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fabss, "FABSS", MEPCORE2_INSN_FABSS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fnegs, "FNEGS", MEPCORE2_INSN_FNEGS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fmovs, "FMOVS", MEPCORE2_INSN_FMOVS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_froundws, "FROUNDWS", MEPCORE2_INSN_FROUNDWS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ftruncws, "FTRUNCWS", MEPCORE2_INSN_FTRUNCWS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fceilws, "FCEILWS", MEPCORE2_INSN_FCEILWS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_ffloorws, "FFLOORWS", MEPCORE2_INSN_FFLOORWS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcvtws, "FCVTWS", MEPCORE2_INSN_FCVTWS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcvtsw, "FCVTSW", MEPCORE2_INSN_FCVTSW, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpfs, "FCMPFS", MEPCORE2_INSN_FCMPFS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpus, "FCMPUS", MEPCORE2_INSN_FCMPUS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpes, "FCMPES", MEPCORE2_INSN_FCMPES, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpues, "FCMPUES", MEPCORE2_INSN_FCMPUES, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpls, "FCMPLS", MEPCORE2_INSN_FCMPLS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpuls, "FCMPULS", MEPCORE2_INSN_FCMPULS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmples, "FCMPLES", MEPCORE2_INSN_FCMPLES, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpules, "FCMPULES", MEPCORE2_INSN_FCMPULES, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpfis, "FCMPFIS", MEPCORE2_INSN_FCMPFIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpuis, "FCMPUIS", MEPCORE2_INSN_FCMPUIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpeis, "FCMPEIS", MEPCORE2_INSN_FCMPEIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpueis, "FCMPUEIS", MEPCORE2_INSN_FCMPUEIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmplis, "FCMPLIS", MEPCORE2_INSN_FCMPLIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpulis, "FCMPULIS", MEPCORE2_INSN_FCMPULIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpleis, "FCMPLEIS", MEPCORE2_INSN_FCMPLEIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_fcmpuleis, "FCMPULEIS", MEPCORE2_INSN_FCMPULEIS, { 0|(1<<CGEN_INSN_MAY_TRAP), (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_cmov_frn_rm, "CMOV_FRN_RM", MEPCORE2_INSN_CMOV_FRN_RM, { 0, (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_cmov_rm_frn, "CMOV_RM_FRN", MEPCORE2_INSN_CMOV_RM_FRN, { 0, (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_cmovc_ccrn_rm, "CMOVC_CCRN_RM", MEPCORE2_INSN_CMOVC_CCRN_RM, { 0, (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },
  { mepcore2_sem_cmovc_rm_ccrn, "CMOVC_RM_CCRN", MEPCORE2_INSN_CMOVC_RM_CCRN, { 0, (1<<MACH_BASE), { 1, "\x20" }, 0, CONFIG_NONE } },

};

// Given a canonical virtual insn id, return the target specific one.

mepcore2_insn_type
mepcore2_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return MEPCORE2_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return MEPCORE2_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
mepcore2_extract_sfmt_empty (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sh (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sw (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lh (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lw (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lbu (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lhu (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sw_sp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lw_sp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sb_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sh_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sw_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lb_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lh_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lw_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lbu_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lhu_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sb16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sh16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sw16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lb16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lh16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lw16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lbu16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lhu16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sw24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lw24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_extb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_exth (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_extub (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ssarb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_mov (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_movi8 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_movi16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_movu24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_movu16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_add3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_add (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_add3i (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_advck3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sub (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_slt3i (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sl1ad3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_add3x (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_slt3x (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sltu3x (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_or3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_srai (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sll3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_fsft (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_bra (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_beqz (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_beqi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_beq (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_bsr12 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_bsr24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_jmp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_jmp24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_jsr (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ret (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_repeat (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_erepeat (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_stc_lp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_stc_hi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_stc_lo (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_stc (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ldc_lp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ldc_hi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ldc_lo (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ldc (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_di (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_reti (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_halt (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sleep (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_break (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_stcb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_bsetm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_btstm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_tas (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_cache (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_mul (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_mulr (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_madd (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_maddr (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_div (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_dret (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_dbreak (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_ldz (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_abs (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_min (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_clip (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_clipu (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lwcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_smcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lmcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lwcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_smcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lmcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lwcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_smcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lmcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sbcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lbcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_shcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lhcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lwcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_smcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lmcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sbcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lbcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_shcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lhcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lwcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_smcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lmcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sbcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lbcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_shcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lhcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_swcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lwcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_smcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_lmcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_bcpeq (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_synccp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_sim_syscall (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_fadds (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_fsqrts (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_froundws (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_fcvtsw (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_fcmpfs (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_cmov_frn_rm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_cmov_rm_frn (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_cmovc_ccrn_rm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
static void
mepcore2_extract_sfmt_cmovc_rm_ccrn (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);

// Fetch & decode instruction
void
mepcore2_scache::decode (mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn)
{
  /* Result of decoder.  */
  MEPCORE2_INSN_TYPE itype;

  {
    mepcore2_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 21) & (15 << 7)) | ((insn >> 17) & (1 << 6)) | ((insn >> 14) & (15 << 2)) | ((insn >> 12) & (3 << 0)));
      switch (val)
      {
      case 0 : /* fall through */
      case 64 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x0)
          { itype = MEPCORE2_INSN_MOV; mepcore2_extract_sfmt_mov (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 : /* fall through */
      case 68 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1)
          { itype = MEPCORE2_INSN_NEG; mepcore2_extract_sfmt_mov (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 : /* fall through */
      case 72 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2)
          { itype = MEPCORE2_INSN_SLT3; mepcore2_extract_sfmt_advck3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 12 : /* fall through */
      case 76 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3)
          { itype = MEPCORE2_INSN_SLTU3; mepcore2_extract_sfmt_advck3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 : /* fall through */
      case 80 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x4)
          { itype = MEPCORE2_INSN_SUB; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 20 : /* fall through */
      case 84 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x5)
          { itype = MEPCORE2_INSN_SBVCK3; mepcore2_extract_sfmt_advck3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 : /* fall through */
      case 88 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x6)
          { itype = MEPCORE2_INSN_RI_0; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 28 : /* fall through */
      case 92 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x7)
          { itype = MEPCORE2_INSN_ADVCK3; mepcore2_extract_sfmt_advck3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 32 : /* fall through */
      case 96 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x8)
          { itype = MEPCORE2_INSN_SB; mepcore2_extract_sfmt_sb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 36 : /* fall through */
      case 100 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x9)
          { itype = MEPCORE2_INSN_SH; mepcore2_extract_sfmt_sh (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 40 : /* fall through */
      case 104 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xa)
          { itype = MEPCORE2_INSN_SW; mepcore2_extract_sfmt_sw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 44 : /* fall through */
      case 108 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xb)
          { itype = MEPCORE2_INSN_LBU; mepcore2_extract_sfmt_lbu (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 48 : /* fall through */
      case 112 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xc)
          { itype = MEPCORE2_INSN_LB; mepcore2_extract_sfmt_lb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 52 : /* fall through */
      case 116 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xd)
          { itype = MEPCORE2_INSN_LH; mepcore2_extract_sfmt_lh (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 56 : /* fall through */
      case 120 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xe)
          { itype = MEPCORE2_INSN_LW; mepcore2_extract_sfmt_lw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 60 : /* fall through */
      case 124 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xf)
          { itype = MEPCORE2_INSN_LHU; mepcore2_extract_sfmt_lhu (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 128 : /* fall through */
      case 192 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1000)
          { itype = MEPCORE2_INSN_OR; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 132 : /* fall through */
      case 196 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1001)
          { itype = MEPCORE2_INSN_AND; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 136 : /* fall through */
      case 200 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1002)
          { itype = MEPCORE2_INSN_XOR; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 140 : /* fall through */
      case 204 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1003)
          { itype = MEPCORE2_INSN_NOR; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 144 : /* fall through */
      case 208 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1004)
          { itype = MEPCORE2_INSN_MUL; mepcore2_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 148 : /* fall through */
      case 212 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1005)
          { itype = MEPCORE2_INSN_MULU; mepcore2_extract_sfmt_mul (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 152 : /* fall through */
      case 216 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1006)
          { itype = MEPCORE2_INSN_MULR; mepcore2_extract_sfmt_mulr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 156 : /* fall through */
      case 220 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1007)
          { itype = MEPCORE2_INSN_MULRU; mepcore2_extract_sfmt_mulr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 160 : /* fall through */
      case 224 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1008)
          { itype = MEPCORE2_INSN_DIV; mepcore2_extract_sfmt_div (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 164 : /* fall through */
      case 228 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x1009)
          { itype = MEPCORE2_INSN_DIVU; mepcore2_extract_sfmt_div (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 168 : /* fall through */
      case 232 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x100a)
          { itype = MEPCORE2_INSN_RI_1; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 172 : /* fall through */
      case 236 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x100b)
          { itype = MEPCORE2_INSN_RI_2; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 176 : /* fall through */
      case 240 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xfc0f) == 0x100c)
          { itype = MEPCORE2_INSN_SSARB; mepcore2_extract_sfmt_ssarb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 180 :
        {
          unsigned int val = (((insn >> 21) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x100d)
              { itype = MEPCORE2_INSN_EXTB; mepcore2_extract_sfmt_extb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x102d)
              { itype = MEPCORE2_INSN_EXTH; mepcore2_extract_sfmt_exth (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 184 : /* fall through */
      case 248 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xff0f) == 0x100e)
          { itype = MEPCORE2_INSN_JMP; mepcore2_extract_sfmt_jmp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 188 : /* fall through */
      case 252 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xff0f) == 0x100f)
              { itype = MEPCORE2_INSN_JSR; mepcore2_extract_sfmt_jsr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xff0f) == 0x180f)
              { itype = MEPCORE2_INSN_JSRV; mepcore2_extract_sfmt_jsr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 244 :
        {
          unsigned int val = (((insn >> 21) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x108d)
              { itype = MEPCORE2_INSN_EXTUB; mepcore2_extract_sfmt_extub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x10ad)
              { itype = MEPCORE2_INSN_EXTUH; mepcore2_extract_sfmt_extub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 256 : /* fall through */
      case 320 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2000)
          { itype = MEPCORE2_INSN_BSETM; mepcore2_extract_sfmt_bsetm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 260 : /* fall through */
      case 324 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2001)
          { itype = MEPCORE2_INSN_BCLRM; mepcore2_extract_sfmt_bsetm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 264 : /* fall through */
      case 328 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2002)
          { itype = MEPCORE2_INSN_BNOTM; mepcore2_extract_sfmt_bsetm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 268 : /* fall through */
      case 332 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2003)
          { itype = MEPCORE2_INSN_BTSTM; mepcore2_extract_sfmt_btstm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 272 : /* fall through */
      case 336 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2004)
          { itype = MEPCORE2_INSN_TAS; mepcore2_extract_sfmt_tas (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 276 : /* fall through */
      case 340 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2005)
          { itype = MEPCORE2_INSN_RI_3; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 280 : /* fall through */
      case 344 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2006)
          { itype = MEPCORE2_INSN_SL1AD3; mepcore2_extract_sfmt_sl1ad3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 284 : /* fall through */
      case 348 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2007)
          { itype = MEPCORE2_INSN_SL2AD3; mepcore2_extract_sfmt_sl1ad3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 288 : /* fall through */
      case 352 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2008)
          { itype = MEPCORE2_INSN_RI_4; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 292 : /* fall through */
      case 356 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x2009)
          { itype = MEPCORE2_INSN_RI_5; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 296 : /* fall through */
      case 360 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x200a)
          { itype = MEPCORE2_INSN_RI_6; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 300 : /* fall through */
      case 364 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x200b)
          { itype = MEPCORE2_INSN_RI_7; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 304 : /* fall through */
      case 368 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x200c)
          { itype = MEPCORE2_INSN_SRL; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 308 : /* fall through */
      case 372 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x200d)
          { itype = MEPCORE2_INSN_SRA; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 312 : /* fall through */
      case 376 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x200e)
          { itype = MEPCORE2_INSN_SLL; mepcore2_extract_sfmt_sub (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 316 : /* fall through */
      case 380 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x200f)
          { itype = MEPCORE2_INSN_FSFT; mepcore2_extract_sfmt_fsft (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 384 : /* fall through */
      case 448 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3000)
          { itype = MEPCORE2_INSN_SWCPI; mepcore2_extract_sfmt_swcpi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 388 : /* fall through */
      case 452 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3001)
          { itype = MEPCORE2_INSN_LWCPI; mepcore2_extract_sfmt_lwcpi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 392 : /* fall through */
      case 456 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3002)
          { itype = MEPCORE2_INSN_SMCPI; mepcore2_extract_sfmt_smcpi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 396 : /* fall through */
      case 460 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3003)
          { itype = MEPCORE2_INSN_LMCPI; mepcore2_extract_sfmt_lmcpi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 400 : /* fall through */
      case 464 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3004)
          { itype = MEPCORE2_INSN_RI_8; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 404 : /* fall through */
      case 468 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3005)
          { itype = MEPCORE2_INSN_RI_9; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 408 : /* fall through */
      case 472 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3006)
          { itype = MEPCORE2_INSN_RI_10; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 412 : /* fall through */
      case 476 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3007)
          { itype = MEPCORE2_INSN_RI_11; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 416 : /* fall through */
      case 480 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3008)
          { itype = MEPCORE2_INSN_SWCP; mepcore2_extract_sfmt_swcp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 420 : /* fall through */
      case 484 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x3009)
          { itype = MEPCORE2_INSN_LWCP; mepcore2_extract_sfmt_lwcp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 424 : /* fall through */
      case 488 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x300a)
          { itype = MEPCORE2_INSN_SMCP; mepcore2_extract_sfmt_smcp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 428 : /* fall through */
      case 492 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x300b)
          { itype = MEPCORE2_INSN_LMCP; mepcore2_extract_sfmt_lmcp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 432 : /* fall through */
      case 496 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x300c)
          { itype = MEPCORE2_INSN_RI_12; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 436 : /* fall through */
      case 500 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x300d)
          { itype = MEPCORE2_INSN_RI_13; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 440 : /* fall through */
      case 504 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x300e)
          { itype = MEPCORE2_INSN_RI_14; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 444 : /* fall through */
      case 508 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x300f)
          { itype = MEPCORE2_INSN_RI_15; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 512 : /* fall through */
      case 528 : /* fall through */
      case 544 : /* fall through */
      case 560 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf083) == 0x4000)
          { itype = MEPCORE2_INSN_ADD3I; mepcore2_extract_sfmt_add3i (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 520 : /* fall through */
      case 536 : /* fall through */
      case 552 : /* fall through */
      case 568 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf083) == 0x4002)
          { itype = MEPCORE2_INSN_SW_SP; mepcore2_extract_sfmt_sw_sp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 524 : /* fall through */
      case 540 : /* fall through */
      case 556 : /* fall through */
      case 572 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf083) == 0x4003)
          { itype = MEPCORE2_INSN_LW_SP; mepcore2_extract_sfmt_lw_sp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 576 : /* fall through */
      case 580 : /* fall through */
      case 592 : /* fall through */
      case 596 : /* fall through */
      case 608 : /* fall through */
      case 612 : /* fall through */
      case 624 : /* fall through */
      case 628 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf880) == 0x4880)
          { itype = MEPCORE2_INSN_LBU_TP; mepcore2_extract_sfmt_lbu_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 584 : /* fall through */
      case 600 : /* fall through */
      case 616 : /* fall through */
      case 632 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf883) == 0x4082)
              { itype = MEPCORE2_INSN_SW_TP; mepcore2_extract_sfmt_sw_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf880) == 0x4880)
              { itype = MEPCORE2_INSN_LBU_TP; mepcore2_extract_sfmt_lbu_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 588 : /* fall through */
      case 604 : /* fall through */
      case 620 : /* fall through */
      case 636 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf883) == 0x4083)
              { itype = MEPCORE2_INSN_LW_TP; mepcore2_extract_sfmt_lw_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf880) == 0x4880)
              { itype = MEPCORE2_INSN_LBU_TP; mepcore2_extract_sfmt_lbu_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 640 : /* fall through */
      case 644 : /* fall through */
      case 648 : /* fall through */
      case 652 : /* fall through */
      case 656 : /* fall through */
      case 660 : /* fall through */
      case 664 : /* fall through */
      case 668 : /* fall through */
      case 672 : /* fall through */
      case 676 : /* fall through */
      case 680 : /* fall through */
      case 684 : /* fall through */
      case 688 : /* fall through */
      case 692 : /* fall through */
      case 696 : /* fall through */
      case 700 : /* fall through */
      case 704 : /* fall through */
      case 708 : /* fall through */
      case 712 : /* fall through */
      case 716 : /* fall through */
      case 720 : /* fall through */
      case 724 : /* fall through */
      case 728 : /* fall through */
      case 732 : /* fall through */
      case 736 : /* fall through */
      case 740 : /* fall through */
      case 744 : /* fall through */
      case 748 : /* fall through */
      case 752 : /* fall through */
      case 756 : /* fall through */
      case 760 : /* fall through */
      case 764 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf000) == 0x5000)
          { itype = MEPCORE2_INSN_MOVI8; mepcore2_extract_sfmt_movi8 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 768 : /* fall through */
      case 784 : /* fall through */
      case 800 : /* fall through */
      case 816 : /* fall through */
      case 832 : /* fall through */
      case 848 : /* fall through */
      case 864 : /* fall through */
      case 880 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf003) == 0x6000)
          { itype = MEPCORE2_INSN_ADD; mepcore2_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 772 : /* fall through */
      case 804 : /* fall through */
      case 836 : /* fall through */
      case 868 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf007) == 0x6001)
          { itype = MEPCORE2_INSN_SLT3I; mepcore2_extract_sfmt_slt3i (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 776 : /* fall through */
      case 808 : /* fall through */
      case 840 : /* fall through */
      case 872 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf007) == 0x6002)
          { itype = MEPCORE2_INSN_SRLI; mepcore2_extract_sfmt_srai (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 780 : /* fall through */
      case 812 : /* fall through */
      case 844 : /* fall through */
      case 876 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf007) == 0x6003)
          { itype = MEPCORE2_INSN_SRAI; mepcore2_extract_sfmt_srai (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 788 : /* fall through */
      case 820 : /* fall through */
      case 852 : /* fall through */
      case 884 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf007) == 0x6005)
          { itype = MEPCORE2_INSN_SLTU3I; mepcore2_extract_sfmt_slt3i (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 792 : /* fall through */
      case 824 : /* fall through */
      case 856 : /* fall through */
      case 888 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf007) == 0x6006)
          { itype = MEPCORE2_INSN_SLLI; mepcore2_extract_sfmt_srai (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 796 : /* fall through */
      case 828 : /* fall through */
      case 860 : /* fall through */
      case 892 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf007) == 0x6007)
          { itype = MEPCORE2_INSN_SLL3; mepcore2_extract_sfmt_sll3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 896 :
        {
          unsigned int val = (((insn >> 26) & (1 << 1)) | ((insn >> 20) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7000)
              { itype = MEPCORE2_INSN_DI; mepcore2_extract_sfmt_di (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7010)
              { itype = MEPCORE2_INSN_EI; mepcore2_extract_sfmt_di (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : /* fall through */
          case 3 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf8ef) == 0x7800)
              { itype = MEPCORE2_INSN_SIM_SYSCALL; mepcore2_extract_sfmt_sim_syscall (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 900 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7011)
              { itype = MEPCORE2_INSN_SYNCM; mepcore2_extract_sfmt_sleep (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7021)
              { itype = MEPCORE2_INSN_SYNCCP; mepcore2_extract_sfmt_synccp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 904 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7002)
              { itype = MEPCORE2_INSN_RET; mepcore2_extract_sfmt_ret (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7012)
              { itype = MEPCORE2_INSN_RETI; mepcore2_extract_sfmt_reti (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7022)
              { itype = MEPCORE2_INSN_HALT; mepcore2_extract_sfmt_halt (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7032)
              { itype = MEPCORE2_INSN_BREAK; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7062)
              { itype = MEPCORE2_INSN_SLEEP; mepcore2_extract_sfmt_sleep (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 908 :
        {
          unsigned int val = (((insn >> 21) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7013)
              { itype = MEPCORE2_INSN_DRET; mepcore2_extract_sfmt_dret (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7033)
              { itype = MEPCORE2_INSN_DBREAK; mepcore2_extract_sfmt_dbreak (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 912 : /* fall through */
      case 976 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x7004)
          { itype = MEPCORE2_INSN_CACHE; mepcore2_extract_sfmt_cache (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 916 : /* fall through */
      case 980 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x7005)
          { itype = MEPCORE2_INSN_RI_16; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 920 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffcf) == 0x7006)
          { itype = MEPCORE2_INSN_SWI; mepcore2_extract_sfmt_swi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 924 : /* fall through */
      case 988 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x7007)
          { itype = MEPCORE2_INSN_RI_17; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 928 :
        {
          unsigned int val = (((insn >> 21) & (3 << 0)));
          switch (val)
          {
          case 0 :
            {
              unsigned int val = (((insn >> 20) & (1 << 0)));
              switch (val)
              {
              case 0 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf00e) == 0x7008)
                  { itype = MEPCORE2_INSN_STC; mepcore2_extract_sfmt_stc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 1 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf0ff) == 0x7018)
                  { itype = MEPCORE2_INSN_STC_LP; mepcore2_extract_sfmt_stc_lp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              }
            }
          case 1 : /* fall through */
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf00e) == 0x7008)
              { itype = MEPCORE2_INSN_STC; mepcore2_extract_sfmt_stc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            {
              unsigned int val = (((insn >> 20) & (1 << 0)));
              switch (val)
              {
              case 0 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf00e) == 0x7008)
                  { itype = MEPCORE2_INSN_STC; mepcore2_extract_sfmt_stc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 1 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf0ff) == 0x7078)
                  { itype = MEPCORE2_INSN_STC_HI; mepcore2_extract_sfmt_stc_hi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              }
            }
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 932 : /* fall through */
      case 996 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00e) == 0x7008)
          { itype = MEPCORE2_INSN_STC; mepcore2_extract_sfmt_stc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 936 :
        {
          unsigned int val = (((insn >> 21) & (3 << 0)));
          switch (val)
          {
          case 0 :
            {
              unsigned int val = (((insn >> 20) & (1 << 0)));
              switch (val)
              {
              case 0 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf00e) == 0x700a)
                  { itype = MEPCORE2_INSN_LDC; mepcore2_extract_sfmt_ldc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 1 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf0ff) == 0x701a)
                  { itype = MEPCORE2_INSN_LDC_LP; mepcore2_extract_sfmt_ldc_lp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              }
            }
          case 1 : /* fall through */
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf00e) == 0x700a)
              { itype = MEPCORE2_INSN_LDC; mepcore2_extract_sfmt_ldc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            {
              unsigned int val = (((insn >> 20) & (1 << 0)));
              switch (val)
              {
              case 0 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf00e) == 0x700a)
                  { itype = MEPCORE2_INSN_LDC; mepcore2_extract_sfmt_ldc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              case 1 :
                entire_insn = entire_insn >> 16;
                if ((entire_insn & 0xf0ff) == 0x707a)
                  { itype = MEPCORE2_INSN_LDC_HI; mepcore2_extract_sfmt_ldc_hi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
                itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
              }
            }
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 940 : /* fall through */
      case 1004 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00e) == 0x700a)
          { itype = MEPCORE2_INSN_LDC; mepcore2_extract_sfmt_ldc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 944 : /* fall through */
      case 1008 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x700c)
          { itype = MEPCORE2_INSN_RI_18; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 948 : /* fall through */
      case 1012 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x700d)
          { itype = MEPCORE2_INSN_RI_19; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 952 : /* fall through */
      case 1016 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x700e)
          { itype = MEPCORE2_INSN_RI_20; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 956 : /* fall through */
      case 1020 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0x700f)
          { itype = MEPCORE2_INSN_RI_21; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 992 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x7088)
              { itype = MEPCORE2_INSN_STC_LO; mepcore2_extract_sfmt_stc_lo (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : /* fall through */
          case 2 : /* fall through */
          case 3 : /* fall through */
          case 4 : /* fall through */
          case 5 : /* fall through */
          case 6 : /* fall through */
          case 7 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf00e) == 0x7008)
              { itype = MEPCORE2_INSN_STC; mepcore2_extract_sfmt_stc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1000 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x708a)
              { itype = MEPCORE2_INSN_LDC_LO; mepcore2_extract_sfmt_ldc_lo (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : /* fall through */
          case 2 : /* fall through */
          case 3 : /* fall through */
          case 4 : /* fall through */
          case 5 : /* fall through */
          case 6 : /* fall through */
          case 7 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf00e) == 0x700a)
              { itype = MEPCORE2_INSN_LDC; mepcore2_extract_sfmt_ldc (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1024 : /* fall through */
      case 1028 : /* fall through */
      case 1032 : /* fall through */
      case 1036 : /* fall through */
      case 1040 : /* fall through */
      case 1044 : /* fall through */
      case 1048 : /* fall through */
      case 1052 : /* fall through */
      case 1056 : /* fall through */
      case 1060 : /* fall through */
      case 1064 : /* fall through */
      case 1068 : /* fall through */
      case 1072 : /* fall through */
      case 1076 : /* fall through */
      case 1080 : /* fall through */
      case 1084 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf880) == 0x8000)
              { itype = MEPCORE2_INSN_SB_TP; mepcore2_extract_sfmt_sb_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf880) == 0x8800)
              { itype = MEPCORE2_INSN_LB_TP; mepcore2_extract_sfmt_lb_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1088 : /* fall through */
      case 1096 : /* fall through */
      case 1104 : /* fall through */
      case 1112 : /* fall through */
      case 1120 : /* fall through */
      case 1128 : /* fall through */
      case 1136 : /* fall through */
      case 1144 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf881) == 0x8080)
              { itype = MEPCORE2_INSN_SH_TP; mepcore2_extract_sfmt_sh_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf881) == 0x8880)
              { itype = MEPCORE2_INSN_LH_TP; mepcore2_extract_sfmt_lh_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1092 : /* fall through */
      case 1100 : /* fall through */
      case 1108 : /* fall through */
      case 1116 : /* fall through */
      case 1124 : /* fall through */
      case 1132 : /* fall through */
      case 1140 : /* fall through */
      case 1148 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf881) == 0x8881)
          { itype = MEPCORE2_INSN_LHU_TP; mepcore2_extract_sfmt_lhu_tp (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1152 : /* fall through */
      case 1156 : /* fall through */
      case 1160 : /* fall through */
      case 1164 : /* fall through */
      case 1168 : /* fall through */
      case 1172 : /* fall through */
      case 1176 : /* fall through */
      case 1180 : /* fall through */
      case 1184 : /* fall through */
      case 1188 : /* fall through */
      case 1192 : /* fall through */
      case 1196 : /* fall through */
      case 1200 : /* fall through */
      case 1204 : /* fall through */
      case 1208 : /* fall through */
      case 1212 : /* fall through */
      case 1216 : /* fall through */
      case 1220 : /* fall through */
      case 1224 : /* fall through */
      case 1228 : /* fall through */
      case 1232 : /* fall through */
      case 1236 : /* fall through */
      case 1240 : /* fall through */
      case 1244 : /* fall through */
      case 1248 : /* fall through */
      case 1252 : /* fall through */
      case 1256 : /* fall through */
      case 1260 : /* fall through */
      case 1264 : /* fall through */
      case 1268 : /* fall through */
      case 1272 : /* fall through */
      case 1276 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf000) == 0x9000)
          { itype = MEPCORE2_INSN_ADD3; mepcore2_extract_sfmt_add3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1280 : /* fall through */
      case 1288 : /* fall through */
      case 1296 : /* fall through */
      case 1304 : /* fall through */
      case 1312 : /* fall through */
      case 1320 : /* fall through */
      case 1328 : /* fall through */
      case 1336 : /* fall through */
      case 1344 : /* fall through */
      case 1352 : /* fall through */
      case 1360 : /* fall through */
      case 1368 : /* fall through */
      case 1376 : /* fall through */
      case 1384 : /* fall through */
      case 1392 : /* fall through */
      case 1400 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf001) == 0xa000)
          { itype = MEPCORE2_INSN_BEQZ; mepcore2_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1284 : /* fall through */
      case 1292 : /* fall through */
      case 1300 : /* fall through */
      case 1308 : /* fall through */
      case 1316 : /* fall through */
      case 1324 : /* fall through */
      case 1332 : /* fall through */
      case 1340 : /* fall through */
      case 1348 : /* fall through */
      case 1356 : /* fall through */
      case 1364 : /* fall through */
      case 1372 : /* fall through */
      case 1380 : /* fall through */
      case 1388 : /* fall through */
      case 1396 : /* fall through */
      case 1404 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf001) == 0xa001)
          { itype = MEPCORE2_INSN_BNEZ; mepcore2_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1408 : /* fall through */
      case 1416 : /* fall through */
      case 1424 : /* fall through */
      case 1432 : /* fall through */
      case 1440 : /* fall through */
      case 1448 : /* fall through */
      case 1456 : /* fall through */
      case 1464 : /* fall through */
      case 1472 : /* fall through */
      case 1480 : /* fall through */
      case 1488 : /* fall through */
      case 1496 : /* fall through */
      case 1504 : /* fall through */
      case 1512 : /* fall through */
      case 1520 : /* fall through */
      case 1528 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf001) == 0xb000)
          { itype = MEPCORE2_INSN_BRA; mepcore2_extract_sfmt_bra (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1412 : /* fall through */
      case 1420 : /* fall through */
      case 1428 : /* fall through */
      case 1436 : /* fall through */
      case 1444 : /* fall through */
      case 1452 : /* fall through */
      case 1460 : /* fall through */
      case 1468 : /* fall through */
      case 1476 : /* fall through */
      case 1484 : /* fall through */
      case 1492 : /* fall through */
      case 1500 : /* fall through */
      case 1508 : /* fall through */
      case 1516 : /* fall through */
      case 1524 : /* fall through */
      case 1532 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf001) == 0xb001)
          { itype = MEPCORE2_INSN_BSR12; mepcore2_extract_sfmt_bsr12 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1536 : /* fall through */
      case 1537 : /* fall through */
      case 1538 : /* fall through */
      case 1539 : /* fall through */
      case 1600 : /* fall through */
      case 1601 : /* fall through */
      case 1602 : /* fall through */
      case 1603 :
        if ((entire_insn & 0xf00f0000) == 0xc0000000)
          { itype = MEPCORE2_INSN_ADD3X; mepcore2_extract_sfmt_add3x (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1540 : /* fall through */
      case 1541 : /* fall through */
      case 1542 : /* fall through */
      case 1543 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ff0000) == 0xc0010000)
              { itype = MEPCORE2_INSN_MOVI16; mepcore2_extract_sfmt_movi16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf0ff0000) == 0xc0110000)
              { itype = MEPCORE2_INSN_MOVU16; mepcore2_extract_sfmt_movu16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf0ff0000) == 0xc0210000)
              { itype = MEPCORE2_INSN_MOVH; mepcore2_extract_sfmt_movu16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1544 : /* fall through */
      case 1545 : /* fall through */
      case 1546 : /* fall through */
      case 1547 : /* fall through */
      case 1608 : /* fall through */
      case 1609 : /* fall through */
      case 1610 : /* fall through */
      case 1611 :
        if ((entire_insn & 0xf00f0000) == 0xc0020000)
          { itype = MEPCORE2_INSN_SLT3X; mepcore2_extract_sfmt_slt3x (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1548 : /* fall through */
      case 1549 : /* fall through */
      case 1550 : /* fall through */
      case 1551 : /* fall through */
      case 1612 : /* fall through */
      case 1613 : /* fall through */
      case 1614 : /* fall through */
      case 1615 :
        if ((entire_insn & 0xf00f0000) == 0xc0030000)
          { itype = MEPCORE2_INSN_SLTU3X; mepcore2_extract_sfmt_sltu3x (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1552 : /* fall through */
      case 1553 : /* fall through */
      case 1554 : /* fall through */
      case 1555 : /* fall through */
      case 1616 : /* fall through */
      case 1617 : /* fall through */
      case 1618 : /* fall through */
      case 1619 :
        if ((entire_insn & 0xf00f0000) == 0xc0040000)
          { itype = MEPCORE2_INSN_OR3; mepcore2_extract_sfmt_or3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1556 : /* fall through */
      case 1557 : /* fall through */
      case 1558 : /* fall through */
      case 1559 : /* fall through */
      case 1620 : /* fall through */
      case 1621 : /* fall through */
      case 1622 : /* fall through */
      case 1623 :
        if ((entire_insn & 0xf00f0000) == 0xc0050000)
          { itype = MEPCORE2_INSN_AND3; mepcore2_extract_sfmt_or3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1560 : /* fall through */
      case 1561 : /* fall through */
      case 1562 : /* fall through */
      case 1563 : /* fall through */
      case 1624 : /* fall through */
      case 1625 : /* fall through */
      case 1626 : /* fall through */
      case 1627 :
        if ((entire_insn & 0xf00f0000) == 0xc0060000)
          { itype = MEPCORE2_INSN_XOR3; mepcore2_extract_sfmt_or3 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1564 : /* fall through */
      case 1628 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xc007)
          { itype = MEPCORE2_INSN_RI_22; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1568 : /* fall through */
      case 1569 : /* fall through */
      case 1570 : /* fall through */
      case 1571 : /* fall through */
      case 1632 : /* fall through */
      case 1633 : /* fall through */
      case 1634 : /* fall through */
      case 1635 :
        if ((entire_insn & 0xf00f0000) == 0xc0080000)
          { itype = MEPCORE2_INSN_SB16; mepcore2_extract_sfmt_sb16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1572 : /* fall through */
      case 1573 : /* fall through */
      case 1574 : /* fall through */
      case 1575 : /* fall through */
      case 1636 : /* fall through */
      case 1637 : /* fall through */
      case 1638 : /* fall through */
      case 1639 :
        if ((entire_insn & 0xf00f0000) == 0xc0090000)
          { itype = MEPCORE2_INSN_SH16; mepcore2_extract_sfmt_sh16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1576 : /* fall through */
      case 1577 : /* fall through */
      case 1578 : /* fall through */
      case 1579 : /* fall through */
      case 1640 : /* fall through */
      case 1641 : /* fall through */
      case 1642 : /* fall through */
      case 1643 :
        if ((entire_insn & 0xf00f0000) == 0xc00a0000)
          { itype = MEPCORE2_INSN_SW16; mepcore2_extract_sfmt_sw16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1580 : /* fall through */
      case 1581 : /* fall through */
      case 1582 : /* fall through */
      case 1583 : /* fall through */
      case 1644 : /* fall through */
      case 1645 : /* fall through */
      case 1646 : /* fall through */
      case 1647 :
        if ((entire_insn & 0xf00f0000) == 0xc00b0000)
          { itype = MEPCORE2_INSN_LBU16; mepcore2_extract_sfmt_lbu16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1584 : /* fall through */
      case 1585 : /* fall through */
      case 1586 : /* fall through */
      case 1587 : /* fall through */
      case 1648 : /* fall through */
      case 1649 : /* fall through */
      case 1650 : /* fall through */
      case 1651 :
        if ((entire_insn & 0xf00f0000) == 0xc00c0000)
          { itype = MEPCORE2_INSN_LB16; mepcore2_extract_sfmt_lb16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1588 : /* fall through */
      case 1589 : /* fall through */
      case 1590 : /* fall through */
      case 1591 : /* fall through */
      case 1652 : /* fall through */
      case 1653 : /* fall through */
      case 1654 : /* fall through */
      case 1655 :
        if ((entire_insn & 0xf00f0000) == 0xc00d0000)
          { itype = MEPCORE2_INSN_LH16; mepcore2_extract_sfmt_lh16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1592 : /* fall through */
      case 1593 : /* fall through */
      case 1594 : /* fall through */
      case 1595 : /* fall through */
      case 1656 : /* fall through */
      case 1657 : /* fall through */
      case 1658 : /* fall through */
      case 1659 :
        if ((entire_insn & 0xf00f0000) == 0xc00e0000)
          { itype = MEPCORE2_INSN_LW16; mepcore2_extract_sfmt_lw16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1596 : /* fall through */
      case 1597 : /* fall through */
      case 1598 : /* fall through */
      case 1599 : /* fall through */
      case 1660 : /* fall through */
      case 1661 : /* fall through */
      case 1662 : /* fall through */
      case 1663 :
        if ((entire_insn & 0xf00f0000) == 0xc00f0000)
          { itype = MEPCORE2_INSN_LHU16; mepcore2_extract_sfmt_lhu16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
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
      case 1704 : /* fall through */
      case 1705 : /* fall through */
      case 1706 : /* fall through */
      case 1707 : /* fall through */
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
      case 1768 : /* fall through */
      case 1769 : /* fall through */
      case 1770 : /* fall through */
      case 1771 : /* fall through */
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
        if ((entire_insn & 0xf8000000) == 0xd0000000)
          { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1680 : /* fall through */
      case 1681 : /* fall through */
      case 1682 : /* fall through */
      case 1683 : /* fall through */
      case 1744 : /* fall through */
      case 1745 : /* fall through */
      case 1746 : /* fall through */
      case 1747 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8040000)
              { itype = MEPCORE2_INSN_BCPEQ; mepcore2_extract_sfmt_bcpeq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1684 : /* fall through */
      case 1685 : /* fall through */
      case 1686 : /* fall through */
      case 1687 : /* fall through */
      case 1748 : /* fall through */
      case 1749 : /* fall through */
      case 1750 : /* fall through */
      case 1751 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8050000)
              { itype = MEPCORE2_INSN_BCPNE; mepcore2_extract_sfmt_bcpeq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1688 : /* fall through */
      case 1689 : /* fall through */
      case 1690 : /* fall through */
      case 1691 : /* fall through */
      case 1752 : /* fall through */
      case 1753 : /* fall through */
      case 1754 : /* fall through */
      case 1755 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8060000)
              { itype = MEPCORE2_INSN_BCPAT; mepcore2_extract_sfmt_bcpeq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1692 : /* fall through */
      case 1693 : /* fall through */
      case 1694 : /* fall through */
      case 1695 : /* fall through */
      case 1756 : /* fall through */
      case 1757 : /* fall through */
      case 1758 : /* fall through */
      case 1759 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8070000)
              { itype = MEPCORE2_INSN_BCPAF; mepcore2_extract_sfmt_bcpeq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1696 : /* fall through */
      case 1697 : /* fall through */
      case 1698 : /* fall through */
      case 1699 : /* fall through */
      case 1760 : /* fall through */
      case 1761 : /* fall through */
      case 1762 : /* fall through */
      case 1763 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf80f0000) == 0xd8080000)
              { itype = MEPCORE2_INSN_JMP24; mepcore2_extract_sfmt_jmp24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1700 : /* fall through */
      case 1701 : /* fall through */
      case 1702 : /* fall through */
      case 1703 : /* fall through */
      case 1764 : /* fall through */
      case 1765 : /* fall through */
      case 1766 : /* fall through */
      case 1767 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf80f0000) == 0xd8090000)
              { itype = MEPCORE2_INSN_BSR24; mepcore2_extract_sfmt_bsr24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1708 : /* fall through */
      case 1709 : /* fall through */
      case 1710 : /* fall through */
      case 1711 : /* fall through */
      case 1772 : /* fall through */
      case 1773 : /* fall through */
      case 1774 : /* fall through */
      case 1775 :
        {
          unsigned int val = (((insn >> 27) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf8000000) == 0xd0000000)
              { itype = MEPCORE2_INSN_MOVU24; mepcore2_extract_sfmt_movu24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf80f0000) == 0xd80b0000)
              { itype = MEPCORE2_INSN_BSRV; mepcore2_extract_sfmt_bsr24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1792 : /* fall through */
      case 1793 : /* fall through */
      case 1794 : /* fall through */
      case 1795 : /* fall through */
      case 1856 : /* fall through */
      case 1857 : /* fall through */
      case 1858 : /* fall through */
      case 1859 :
        if ((entire_insn & 0xf00f0000) == 0xe0000000)
          { itype = MEPCORE2_INSN_BEQI; mepcore2_extract_sfmt_beqi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1796 : /* fall through */
      case 1797 : /* fall through */
      case 1798 : /* fall through */
      case 1799 : /* fall through */
      case 1860 : /* fall through */
      case 1861 : /* fall through */
      case 1862 : /* fall through */
      case 1863 :
        if ((entire_insn & 0xf00f0000) == 0xe0010000)
          { itype = MEPCORE2_INSN_BEQ; mepcore2_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1800 : /* fall through */
      case 1801 : /* fall through */
      case 1802 : /* fall through */
      case 1803 : /* fall through */
      case 1816 : /* fall through */
      case 1817 : /* fall through */
      case 1818 : /* fall through */
      case 1819 : /* fall through */
      case 1832 : /* fall through */
      case 1833 : /* fall through */
      case 1834 : /* fall through */
      case 1835 : /* fall through */
      case 1848 : /* fall through */
      case 1849 : /* fall through */
      case 1850 : /* fall through */
      case 1851 : /* fall through */
      case 1864 : /* fall through */
      case 1865 : /* fall through */
      case 1866 : /* fall through */
      case 1867 : /* fall through */
      case 1880 : /* fall through */
      case 1881 : /* fall through */
      case 1882 : /* fall through */
      case 1883 : /* fall through */
      case 1896 : /* fall through */
      case 1897 : /* fall through */
      case 1898 : /* fall through */
      case 1899 : /* fall through */
      case 1912 : /* fall through */
      case 1913 : /* fall through */
      case 1914 : /* fall through */
      case 1915 :
        if ((entire_insn & 0xf0030000) == 0xe0020000)
          { itype = MEPCORE2_INSN_SW24; mepcore2_extract_sfmt_sw24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1804 : /* fall through */
      case 1805 : /* fall through */
      case 1806 : /* fall through */
      case 1807 : /* fall through */
      case 1820 : /* fall through */
      case 1821 : /* fall through */
      case 1822 : /* fall through */
      case 1823 : /* fall through */
      case 1836 : /* fall through */
      case 1837 : /* fall through */
      case 1838 : /* fall through */
      case 1839 : /* fall through */
      case 1852 : /* fall through */
      case 1853 : /* fall through */
      case 1854 : /* fall through */
      case 1855 : /* fall through */
      case 1868 : /* fall through */
      case 1869 : /* fall through */
      case 1870 : /* fall through */
      case 1871 : /* fall through */
      case 1884 : /* fall through */
      case 1885 : /* fall through */
      case 1886 : /* fall through */
      case 1887 : /* fall through */
      case 1900 : /* fall through */
      case 1901 : /* fall through */
      case 1902 : /* fall through */
      case 1903 : /* fall through */
      case 1916 : /* fall through */
      case 1917 : /* fall through */
      case 1918 : /* fall through */
      case 1919 :
        if ((entire_insn & 0xf0030000) == 0xe0030000)
          { itype = MEPCORE2_INSN_LW24; mepcore2_extract_sfmt_lw24 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1808 : /* fall through */
      case 1809 : /* fall through */
      case 1810 : /* fall through */
      case 1811 : /* fall through */
      case 1872 : /* fall through */
      case 1873 : /* fall through */
      case 1874 : /* fall through */
      case 1875 :
        if ((entire_insn & 0xf00f0000) == 0xe0040000)
          { itype = MEPCORE2_INSN_BNEI; mepcore2_extract_sfmt_beqi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1812 : /* fall through */
      case 1813 : /* fall through */
      case 1814 : /* fall through */
      case 1815 : /* fall through */
      case 1876 : /* fall through */
      case 1877 : /* fall through */
      case 1878 : /* fall through */
      case 1879 :
        if ((entire_insn & 0xf00f0000) == 0xe0050000)
          { itype = MEPCORE2_INSN_BNE; mepcore2_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1824 : /* fall through */
      case 1825 : /* fall through */
      case 1826 : /* fall through */
      case 1827 : /* fall through */
      case 1888 : /* fall through */
      case 1889 : /* fall through */
      case 1890 : /* fall through */
      case 1891 :
        if ((entire_insn & 0xf00f0000) == 0xe0080000)
          { itype = MEPCORE2_INSN_BGEI; mepcore2_extract_sfmt_beqi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1828 : /* fall through */
      case 1829 : /* fall through */
      case 1830 : /* fall through */
      case 1831 :
        {
          unsigned int val = (((insn >> 20) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ff0000) == 0xe0090000)
              { itype = MEPCORE2_INSN_REPEAT; mepcore2_extract_sfmt_repeat (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xffff0000) == 0xe0190000)
              { itype = MEPCORE2_INSN_EREPEAT; mepcore2_extract_sfmt_erepeat (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1840 : /* fall through */
      case 1841 : /* fall through */
      case 1842 : /* fall through */
      case 1843 : /* fall through */
      case 1904 : /* fall through */
      case 1905 : /* fall through */
      case 1906 : /* fall through */
      case 1907 :
        if ((entire_insn & 0xf00f0000) == 0xe00c0000)
          { itype = MEPCORE2_INSN_BLTI; mepcore2_extract_sfmt_beqi (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1844 : /* fall through */
      case 1908 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xe00d)
          { itype = MEPCORE2_INSN_RI_23; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1924 : /* fall through */
      case 1988 :
        {
          unsigned int val = (((insn >> 0) & (15 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fffff) == 0xf0010000)
              { itype = MEPCORE2_INSN_LDZ; mepcore2_extract_sfmt_ldz (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fffff) == 0xf0010002)
              { itype = MEPCORE2_INSN_AVE; mepcore2_extract_sfmt_abs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fffff) == 0xf0010003)
              { itype = MEPCORE2_INSN_ABS; mepcore2_extract_sfmt_abs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf00fffff) == 0xf0010004)
              { itype = MEPCORE2_INSN_MIN; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xf00fffff) == 0xf0010005)
              { itype = MEPCORE2_INSN_MAX; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf00fffff) == 0xf0010006)
              { itype = MEPCORE2_INSN_MINU; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf00fffff) == 0xf0010007)
              { itype = MEPCORE2_INSN_MAXU; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 8 :
            if ((entire_insn & 0xf00fffff) == 0xf0010008)
              { itype = MEPCORE2_INSN_SADD; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 9 :
            if ((entire_insn & 0xf00fffff) == 0xf0010009)
              { itype = MEPCORE2_INSN_SADDU; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 10 :
            if ((entire_insn & 0xf00fffff) == 0xf001000a)
              { itype = MEPCORE2_INSN_SSUB; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 11 :
            if ((entire_insn & 0xf00fffff) == 0xf001000b)
              { itype = MEPCORE2_INSN_SSUBU; mepcore2_extract_sfmt_min (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1925 :
        {
          unsigned int val = (((insn >> 0) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ffff07) == 0xf0011000)
              { itype = MEPCORE2_INSN_CLIP; mepcore2_extract_sfmt_clip (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf0ffff07) == 0xf0011001)
              { itype = MEPCORE2_INSN_CLIPU; mepcore2_extract_sfmt_clipu (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1927 : /* fall through */
      case 1991 :
        {
          unsigned int val = (((insn >> 0) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fffff) == 0xf0013004)
              { itype = MEPCORE2_INSN_MADD; mepcore2_extract_sfmt_madd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf00fffff) == 0xf0013005)
              { itype = MEPCORE2_INSN_MADDU; mepcore2_extract_sfmt_madd (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fffff) == 0xf0013006)
              { itype = MEPCORE2_INSN_MADDR; mepcore2_extract_sfmt_maddr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fffff) == 0xf0013007)
              { itype = MEPCORE2_INSN_MADDRU; mepcore2_extract_sfmt_maddr (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1932 : /* fall through */
      case 1996 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xf003)
          { itype = MEPCORE2_INSN_RI_24; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1936 : /* fall through */
      case 1937 : /* fall through */
      case 1938 : /* fall through */
      case 1939 :
        {
          unsigned int val = (((insn >> 20) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ff0000) == 0xf0040000)
              { itype = MEPCORE2_INSN_STCB; mepcore2_extract_sfmt_stcb (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf0ff0000) == 0xf0140000)
              { itype = MEPCORE2_INSN_LDCB; mepcore2_extract_sfmt_movu16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1940 : /* fall through */
      case 2004 :
        {
          unsigned int val = (((insn >> 12) & (1 << 2)) | ((insn >> 10) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fff00) == 0xf0050000)
              { itype = MEPCORE2_INSN_SBCPA; mepcore2_extract_sfmt_sbcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fff00) == 0xf0050800)
              { itype = MEPCORE2_INSN_SBCPM0; mepcore2_extract_sfmt_sbcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fff00) == 0xf0050c00)
              { itype = MEPCORE2_INSN_SBCPM1; mepcore2_extract_sfmt_sbcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf00fff00) == 0xf0054000)
              { itype = MEPCORE2_INSN_LBCPA; mepcore2_extract_sfmt_lbcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf00fff00) == 0xf0054800)
              { itype = MEPCORE2_INSN_LBCPM0; mepcore2_extract_sfmt_lbcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf00fff00) == 0xf0054c00)
              { itype = MEPCORE2_INSN_LBCPM1; mepcore2_extract_sfmt_lbcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1941 : /* fall through */
      case 2005 :
        {
          unsigned int val = (((insn >> 12) & (1 << 2)) | ((insn >> 10) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fff01) == 0xf0051000)
              { itype = MEPCORE2_INSN_SHCPA; mepcore2_extract_sfmt_shcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fff01) == 0xf0051800)
              { itype = MEPCORE2_INSN_SHCPM0; mepcore2_extract_sfmt_shcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fff01) == 0xf0051c00)
              { itype = MEPCORE2_INSN_SHCPM1; mepcore2_extract_sfmt_shcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf00fff01) == 0xf0055000)
              { itype = MEPCORE2_INSN_LHCPA; mepcore2_extract_sfmt_lhcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf00fff01) == 0xf0055800)
              { itype = MEPCORE2_INSN_LHCPM0; mepcore2_extract_sfmt_lhcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf00fff01) == 0xf0055c00)
              { itype = MEPCORE2_INSN_LHCPM1; mepcore2_extract_sfmt_lhcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1942 : /* fall through */
      case 2006 :
        {
          unsigned int val = (((insn >> 12) & (1 << 2)) | ((insn >> 10) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fff03) == 0xf0052000)
              { itype = MEPCORE2_INSN_SWCPA; mepcore2_extract_sfmt_swcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fff03) == 0xf0052800)
              { itype = MEPCORE2_INSN_SWCPM0; mepcore2_extract_sfmt_swcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fff03) == 0xf0052c00)
              { itype = MEPCORE2_INSN_SWCPM1; mepcore2_extract_sfmt_swcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf00fff03) == 0xf0056000)
              { itype = MEPCORE2_INSN_LWCPA; mepcore2_extract_sfmt_lwcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf00fff03) == 0xf0056800)
              { itype = MEPCORE2_INSN_LWCPM0; mepcore2_extract_sfmt_lwcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf00fff03) == 0xf0056c00)
              { itype = MEPCORE2_INSN_LWCPM1; mepcore2_extract_sfmt_lwcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1943 : /* fall through */
      case 2007 :
        {
          unsigned int val = (((insn >> 12) & (1 << 2)) | ((insn >> 10) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fff07) == 0xf0053000)
              { itype = MEPCORE2_INSN_SMCPA; mepcore2_extract_sfmt_smcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fff07) == 0xf0053800)
              { itype = MEPCORE2_INSN_SMCPM0; mepcore2_extract_sfmt_smcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fff07) == 0xf0053c00)
              { itype = MEPCORE2_INSN_SMCPM1; mepcore2_extract_sfmt_smcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf00fff07) == 0xf0057000)
              { itype = MEPCORE2_INSN_LMCPA; mepcore2_extract_sfmt_lmcpa (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf00fff07) == 0xf0057800)
              { itype = MEPCORE2_INSN_LMCPM0; mepcore2_extract_sfmt_lmcpm0 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf00fff07) == 0xf0057c00)
              { itype = MEPCORE2_INSN_LMCPM1; mepcore2_extract_sfmt_lmcpm1 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1944 : /* fall through */
      case 2008 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xf006)
          { itype = MEPCORE2_INSN_RI_25; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1948 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0fff001) == 0xf0070000)
              { itype = MEPCORE2_INSN_FADDS; mepcore2_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf0fff001) == 0xf0170000)
              { itype = MEPCORE2_INSN_FSUBS; mepcore2_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf0fff001) == 0xf0270000)
              { itype = MEPCORE2_INSN_FMULS; mepcore2_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf0fff001) == 0xf0370000)
              { itype = MEPCORE2_INSN_FDIVS; mepcore2_extract_sfmt_fadds (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0470000)
              { itype = MEPCORE2_INSN_FSQRTS; mepcore2_extract_sfmt_fsqrts (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0570000)
              { itype = MEPCORE2_INSN_FABSS; mepcore2_extract_sfmt_fsqrts (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0670000)
              { itype = MEPCORE2_INSN_FMOVS; mepcore2_extract_sfmt_fsqrts (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0770000)
              { itype = MEPCORE2_INSN_FNEGS; mepcore2_extract_sfmt_fsqrts (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1949 :
        {
          unsigned int val = (((insn >> 21) & (1 << 1)) | ((insn >> 15) & (1 << 0)));
          switch (val)
          {
          case 1 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0079000)
              { itype = MEPCORE2_INSN_FCVTSW; mepcore2_extract_sfmt_fcvtsw (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0471000)
              { itype = MEPCORE2_INSN_FCVTWS; mepcore2_extract_sfmt_froundws (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1950 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffff009) == 0xf0072000)
              { itype = MEPCORE2_INSN_FCMPFS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfffff009) == 0xf0172000)
              { itype = MEPCORE2_INSN_FCMPUS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfffff009) == 0xf0272000)
              { itype = MEPCORE2_INSN_FCMPES; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfffff009) == 0xf0372000)
              { itype = MEPCORE2_INSN_FCMPUES; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfffff009) == 0xf0472000)
              { itype = MEPCORE2_INSN_FCMPLS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfffff009) == 0xf0572000)
              { itype = MEPCORE2_INSN_FCMPULS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfffff009) == 0xf0672000)
              { itype = MEPCORE2_INSN_FCMPLES; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfffff009) == 0xf0772000)
              { itype = MEPCORE2_INSN_FCMPULES; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1951 : /* fall through */
      case 2015 :
        {
          unsigned int val = (((insn >> 0) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00ffff7) == 0xf007f000)
              { itype = MEPCORE2_INSN_CMOV_FRN_RM; mepcore2_extract_sfmt_cmov_frn_rm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf00ffff7) == 0xf007f001)
              { itype = MEPCORE2_INSN_CMOV_RM_FRN; mepcore2_extract_sfmt_cmov_rm_frn (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf00fffff) == 0xf007f002)
              { itype = MEPCORE2_INSN_CMOVC_CCRN_RM; mepcore2_extract_sfmt_cmovc_ccrn_rm (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf00fffff) == 0xf007f003)
              { itype = MEPCORE2_INSN_CMOVC_RM_CCRN; mepcore2_extract_sfmt_cmovc_rm_ccrn (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 1952 : /* fall through */
      case 2016 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf00f) == 0xf008)
          { itype = MEPCORE2_INSN_RI_26; mepcore2_extract_sfmt_break (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1968 : /* fall through */
      case 1969 : /* fall through */
      case 1970 : /* fall through */
      case 1971 : /* fall through */
      case 2032 : /* fall through */
      case 2033 : /* fall through */
      case 2034 : /* fall through */
      case 2035 :
        if ((entire_insn & 0xf00f0000) == 0xf00c0000)
          { itype = MEPCORE2_INSN_SWCP16; mepcore2_extract_sfmt_swcp16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1972 : /* fall through */
      case 1973 : /* fall through */
      case 1974 : /* fall through */
      case 1975 : /* fall through */
      case 2036 : /* fall through */
      case 2037 : /* fall through */
      case 2038 : /* fall through */
      case 2039 :
        if ((entire_insn & 0xf00f0000) == 0xf00d0000)
          { itype = MEPCORE2_INSN_LWCP16; mepcore2_extract_sfmt_lwcp16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1976 : /* fall through */
      case 1977 : /* fall through */
      case 1978 : /* fall through */
      case 1979 : /* fall through */
      case 2040 : /* fall through */
      case 2041 : /* fall through */
      case 2042 : /* fall through */
      case 2043 :
        if ((entire_insn & 0xf00f0000) == 0xf00e0000)
          { itype = MEPCORE2_INSN_SMCP16; mepcore2_extract_sfmt_smcp16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1980 : /* fall through */
      case 1981 : /* fall through */
      case 1982 : /* fall through */
      case 1983 : /* fall through */
      case 2044 : /* fall through */
      case 2045 : /* fall through */
      case 2046 : /* fall through */
      case 2047 :
        if ((entire_insn & 0xf00f0000) == 0xf00f0000)
          { itype = MEPCORE2_INSN_LMCP16; mepcore2_extract_sfmt_lmcp16 (this, current_cpu, pc, base_insn, entire_insn); goto done; }
        itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 2012 :
        {
          unsigned int val = (((insn >> 20) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0c70000)
              { itype = MEPCORE2_INSN_FROUNDWS; mepcore2_extract_sfmt_froundws (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0d70000)
              { itype = MEPCORE2_INSN_FTRUNCWS; mepcore2_extract_sfmt_froundws (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0e70000)
              { itype = MEPCORE2_INSN_FCEILWS; mepcore2_extract_sfmt_froundws (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xf0fff0f3) == 0xf0f70000)
              { itype = MEPCORE2_INSN_FFLOORWS; mepcore2_extract_sfmt_froundws (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 2014 :
        {
          unsigned int val = (((insn >> 20) & (7 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xfffff009) == 0xf0872000)
              { itype = MEPCORE2_INSN_FCMPFIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            if ((entire_insn & 0xfffff009) == 0xf0972000)
              { itype = MEPCORE2_INSN_FCMPUIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            if ((entire_insn & 0xfffff009) == 0xf0a72000)
              { itype = MEPCORE2_INSN_FCMPEIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            if ((entire_insn & 0xfffff009) == 0xf0b72000)
              { itype = MEPCORE2_INSN_FCMPUEIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 4 :
            if ((entire_insn & 0xfffff009) == 0xf0c72000)
              { itype = MEPCORE2_INSN_FCMPLIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 5 :
            if ((entire_insn & 0xfffff009) == 0xf0d72000)
              { itype = MEPCORE2_INSN_FCMPULIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 6 :
            if ((entire_insn & 0xfffff009) == 0xf0e72000)
              { itype = MEPCORE2_INSN_FCMPLEIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 7 :
            if ((entire_insn & 0xfffff009) == 0xf0f72000)
              { itype = MEPCORE2_INSN_FCMPULEIS; mepcore2_extract_sfmt_fcmpfs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      default : itype = MEPCORE2_INSN_X_INVALID; mepcore2_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & mepcore2_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
mepcore2_extract_sfmt_empty (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
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
mepcore2_extract_sfmt_sb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sb16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnc) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sb)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (in_rnc) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sh (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sh16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rns) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sh)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (in_rns) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sw (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sw16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sw)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (in_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lb16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnc) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lb)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnc) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lh (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lh16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rns) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lh)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rns) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lw (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lw16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lw)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lbu (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lbu16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnuc) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lbu)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnuc) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lhu (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lhu16.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnus) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lhu)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnus) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sw_sp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sw_sp.f
    UINT f_rn;
    SI f_7u9a4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_7u9a4) = f_7u9a4;
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sw_sp)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_7u9a4:0x" << hex << f_7u9a4 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rnl) = f_rn;
      FLD (in_sp) = 15;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lw_sp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lw_sp.f
    UINT f_rn;
    SI f_7u9a4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9a4) = f_7u9a4;
  FLD (f_rn) = f_rn;
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lw_sp)\t"
        << " f_7u9a4:0x" << hex << f_7u9a4 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_sp) = 15;
      FLD (out_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sb_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sb_tp.f
    UINT f_rn3;
    UINT f_7u9;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9 = EXTRACT_MSB0_UINT (insn, 16, 9, 7);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn3) = f_rn3;
  FLD (f_7u9) = f_7u9;
  FLD (i_rn3c) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sb_tp)\t"
        << " f_rn3:0x" << hex << f_rn3 << dec
        << " f_7u9:0x" << hex << f_7u9 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn3c) = f_rn3;
      FLD (in_tp) = 13;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sh_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sh_tp.f
    UINT f_rn3;
    SI f_7u9a2;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a2 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 6)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_rn3) = f_rn3;
  FLD (f_7u9a2) = f_7u9a2;
  FLD (i_rn3s) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sh_tp)\t"
        << " f_rn3:0x" << hex << f_rn3 << dec
        << " f_7u9a2:0x" << hex << f_7u9a2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn3s) = f_rn3;
      FLD (in_tp) = 13;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sw_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sw_tp.f
    UINT f_rn3;
    SI f_7u9a4;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_rn3) = f_rn3;
  FLD (f_7u9a4) = f_7u9a4;
  FLD (i_rn3l) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sw_tp)\t"
        << " f_rn3:0x" << hex << f_rn3 << dec
        << " f_7u9a4:0x" << hex << f_7u9a4 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn3l) = f_rn3;
      FLD (in_tp) = 13;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lb_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lb_tp.f
    UINT f_rn3;
    UINT f_7u9;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9 = EXTRACT_MSB0_UINT (insn, 16, 9, 7);

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9) = f_7u9;
  FLD (f_rn3) = f_rn3;
  FLD (i_rn3c) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lb_tp)\t"
        << " f_7u9:0x" << hex << f_7u9 << dec
        << " f_rn3:0x" << hex << f_rn3 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_tp) = 13;
      FLD (out_rn3c) = f_rn3;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lh_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lh_tp.f
    UINT f_rn3;
    SI f_7u9a2;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a2 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 6)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9a2) = f_7u9a2;
  FLD (f_rn3) = f_rn3;
  FLD (i_rn3s) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lh_tp)\t"
        << " f_7u9a2:0x" << hex << f_7u9a2 << dec
        << " f_rn3:0x" << hex << f_rn3 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_tp) = 13;
      FLD (out_rn3s) = f_rn3;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lw_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lw_tp.f
    UINT f_rn3;
    SI f_7u9a4;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9a4) = f_7u9a4;
  FLD (f_rn3) = f_rn3;
  FLD (i_rn3l) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lw_tp)\t"
        << " f_7u9a4:0x" << hex << f_7u9a4 << dec
        << " f_rn3:0x" << hex << f_rn3 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_tp) = 13;
      FLD (out_rn3l) = f_rn3;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lbu_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lbu_tp.f
    UINT f_rn3;
    UINT f_7u9;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9 = EXTRACT_MSB0_UINT (insn, 16, 9, 7);

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9) = f_7u9;
  FLD (f_rn3) = f_rn3;
  FLD (i_rn3uc) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lbu_tp)\t"
        << " f_7u9:0x" << hex << f_7u9 << dec
        << " f_rn3:0x" << hex << f_rn3 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_tp) = 13;
      FLD (out_rn3uc) = f_rn3;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lhu_tp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lhu_tp.f
    UINT f_rn3;
    SI f_7u9a2;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a2 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 6)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9a2) = f_7u9a2;
  FLD (f_rn3) = f_rn3;
  FLD (i_rn3us) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lhu_tp)\t"
        << " f_7u9a2:0x" << hex << f_7u9a2 << dec
        << " f_rn3:0x" << hex << f_rn3 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_tp) = 13;
      FLD (out_rn3us) = f_rn3;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sb16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sb16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (f_16s16) = f_16s16;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnc) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sb16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (in_rnc) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sh16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sh16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (f_16s16) = f_16s16;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rns) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sh16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (in_rns) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sw16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sw16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (f_16s16) = f_16s16;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sw16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (in_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lb16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lb16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnc) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lb16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnc) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lh16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lh16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rns) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lh16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rns) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lw16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lw16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lw16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lbu16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lbu16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnuc) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lbu16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnuc) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lhu16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lhu16.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rnus) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lhu16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rnus) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sw24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sw24.f
    UINT f_rn;
    UINT f_24u8a4n_lo;
    UINT f_24u8a4n_hi;
    UINT f_24u8a4n;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_24u8a4n_lo = EXTRACT_MSB0_UINT (insn, 32, 8, 6);
    f_24u8a4n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u8a4n = ((((f_24u8a4n_hi) << (8))) | (((f_24u8a4n_lo) << (2))));

  /* Record the fields for the semantic handler.  */
  FLD (f_24u8a4n) = f_24u8a4n;
  FLD (f_rn) = f_rn;
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sw24)\t"
        << " f_24u8a4n:0x" << hex << f_24u8a4n << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lw24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lw24.f
    UINT f_rn;
    UINT f_24u8a4n_lo;
    UINT f_24u8a4n_hi;
    UINT f_24u8a4n;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_24u8a4n_lo = EXTRACT_MSB0_UINT (insn, 32, 8, 6);
    f_24u8a4n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u8a4n = ((((f_24u8a4n_hi) << (8))) | (((f_24u8a4n_lo) << (2))));

  /* Record the fields for the semantic handler.  */
  FLD (f_24u8a4n) = f_24u8a4n;
  FLD (f_rn) = f_rn;
  FLD (i_rnl) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lw24)\t"
        << " f_24u8a4n:0x" << hex << f_24u8a4n << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rnl) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_extb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_clip.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_extb)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_exth (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_clip.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_exth)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_extub (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_clip.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_extub)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ssarb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ssarb.f
    UINT f_2u6;
    UINT f_rm;

    f_2u6 = EXTRACT_MSB0_UINT (insn, 16, 6, 2);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_2u6) = f_2u6;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ssarb)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_2u6:0x" << hex << f_2u6 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_sar) = 2;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_mov (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sltu3x.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mov)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_movi8 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movi8.f
    UINT f_rn;
    INT f_8s8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_8s8 = EXTRACT_MSB0_INT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s8) = f_8s8;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movi8)\t"
        << " f_8s8:0x" << hex << f_8s8 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_movi16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3x.f
    UINT f_rn;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movi16)\t"
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_movu24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_movu24.f
    UINT f_rn3;
    UINT f_24u8n_lo;
    UINT f_24u8n_hi;
    UINT f_24u8n;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 32, 5, 3);
    f_24u8n_lo = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_24u8n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u8n = ((((f_24u8n_hi) << (8))) | (f_24u8n_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_24u8n) = f_24u8n;
  FLD (f_rn3) = f_rn3;
  FLD (i_rn3) = & current_cpu->hardware.h_gpr[f_rn3];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movu24)\t"
        << " f_24u8n:0x" << hex << f_24u8n << dec
        << " f_rn3:0x" << hex << f_rn3 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn3) = f_rn3;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_movu16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sltu3x.f
    UINT f_rn;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_16u16) = f_16u16;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_movu16)\t"
        << " f_16u16:0x" << hex << f_16u16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_add3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_rn;
    UINT f_rm;
    UINT f_rl;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_rl = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (f_rl) = f_rl;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  FLD (i_rl) = & current_cpu->hardware.h_gpr[f_rl];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add3)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << " f_rl:0x" << hex << f_rl << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rl) = f_rl;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_add (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_rn;
    INT f_6s8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_6s8 = EXTRACT_MSB0_INT (insn, 16, 8, 6);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_6s8) = f_6s8;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_6s8:0x" << hex << f_6s8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_add3i (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3i.f
    UINT f_rn;
    SI f_7u9a4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_7u9a4) = f_7u9a4;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add3i)\t"
        << " f_7u9a4:0x" << hex << f_7u9a4 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_sp) = 15;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_advck3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_advck3.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_advck3)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sub (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fsft.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sub)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_slt3i (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_slt3i.f
    UINT f_rn;
    UINT f_5u8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_5u8 = EXTRACT_MSB0_UINT (insn, 16, 8, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_5u8) = f_5u8;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_slt3i)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_5u8:0x" << hex << f_5u8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sl1ad3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_advck3.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sl1ad3)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_add3x (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3x.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add3x)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_slt3x (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3x.f
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_slt3x)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sltu3x (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sltu3x.f
    UINT f_rn;
    UINT f_rm;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16u16) = f_16u16;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sltu3x)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16u16:0x" << hex << f_16u16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_or3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sltu3x.f
    UINT f_rn;
    UINT f_rm;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16u16) = f_16u16;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_or3)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16u16:0x" << hex << f_16u16 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_srai (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_srai.f
    UINT f_rn;
    UINT f_5u8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_5u8 = EXTRACT_MSB0_UINT (insn, 16, 8, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_5u8) = f_5u8;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_srai)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_5u8:0x" << hex << f_5u8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sll3 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_slt3i.f
    UINT f_rn;
    UINT f_5u8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_5u8 = EXTRACT_MSB0_UINT (insn, 16, 8, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_5u8) = f_5u8;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sll3)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_5u8:0x" << hex << f_5u8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_fsft (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fsft.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fsft)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (in_sar) = 2;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_bra (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bsr12.f
    SI f_12s4a2;

    f_12s4a2 = ((((EXTRACT_MSB0_INT (insn, 16, 4, 11)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_12s4a2) = f_12s4a2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bra)\t"
        << " f_12s4a2:0x" << hex << f_12s4a2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_beqz (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beqz.f
    UINT f_rn;
    SI f_8s8a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_8s8a2 = ((((EXTRACT_MSB0_INT (insn, 16, 8, 7)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s8a2) = f_8s8a2;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beqz)\t"
        << " f_8s8a2:0x" << hex << f_8s8a2 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_beqi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beqi.f
    UINT f_rn;
    UINT f_4u8;
    SI f_17s16a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_4u8 = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_17s16a2) = f_17s16a2;
  FLD (f_rn) = f_rn;
  FLD (f_4u8) = f_4u8;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beqi)\t"
        << " f_17s16a2:0x" << hex << f_17s16a2 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << " f_4u8:0x" << hex << f_4u8 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_beq (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    UINT f_rn;
    UINT f_rm;
    SI f_17s16a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_17s16a2) = f_17s16a2;
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beq)\t"
        << " f_17s16a2:0x" << hex << f_17s16a2 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_bsr12 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bsr12.f
    SI f_12s4a2;

    f_12s4a2 = ((((EXTRACT_MSB0_INT (insn, 16, 4, 11)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_12s4a2) = f_12s4a2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bsr12)\t"
        << " f_12s4a2:0x" << hex << f_12s4a2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (out_lp) = 1;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_bsr24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bsr24.f
    UINT f_24s5a2n_lo;
    INT f_24s5a2n_hi;
    INT f_24s5a2n;

    f_24s5a2n_lo = EXTRACT_MSB0_UINT (insn, 32, 5, 7);
    f_24s5a2n_hi = EXTRACT_MSB0_INT (insn, 32, 16, 16);
  f_24s5a2n = ((((((f_24s5a2n_hi) << (8))) | (((f_24s5a2n_lo) << (1))))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_24s5a2n) = f_24s5a2n;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bsr24)\t"
        << " f_24s5a2n:0x" << hex << f_24s5a2n << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (out_lp) = 1;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_jmp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jsr.f
    UINT f_rm;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jmp)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (in_rm) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_jmp24 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jmp24.f
    UINT f_24u5a2n_lo;
    UINT f_24u5a2n_hi;
    UINT f_24u5a2n;

    f_24u5a2n_lo = EXTRACT_MSB0_UINT (insn, 32, 5, 7);
    f_24u5a2n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u5a2n = ((((f_24u5a2n_hi) << (8))) | (((f_24u5a2n_lo) << (1))));

  /* Record the fields for the semantic handler.  */
  FLD (f_24u5a2n) = f_24u5a2n;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jmp24)\t"
        << " f_24u5a2n:0x" << hex << f_24u5a2n << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_jsr (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_jsr.f
    UINT f_rm;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jsr)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (in_rm) = f_rm;
      FLD (out_lp) = 1;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ret (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ret.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ret)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_lp) = 1;
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_repeat (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_repeat.f
    UINT f_rn;
    SI f_17s16a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_17s16a2) = f_17s16a2;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_repeat)\t"
        << " f_17s16a2:0x" << hex << f_17s16a2 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (in_rn) = f_rn;
      FLD (out_h_csr_SI_4) = 4;
      FLD (out_h_csr_SI_5) = 5;
      FLD (out_h_csr_SI_6) = 6;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_erepeat (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_repeat.f
    SI f_17s16a2;

    f_17s16a2 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_17s16a2) = f_17s16a2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_erepeat)\t"
        << " f_17s16a2:0x" << hex << f_17s16a2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (out_h_csr_SI_4) = 4;
      FLD (out_h_csr_SI_5) = 5;
      FLD (out_h_csr_SI_6) = 6;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_stc_lp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stc_lp.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stc_lp)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_lp) = 1;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_stc_hi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stc_hi)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_hi) = 7;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_stc_lo (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stc_lo)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_lo) = 8;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_stc (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stc.f
    UINT f_rn;
    UINT f_csrn_lo;
    UINT f_csrn_hi;
    UINT f_csrn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_csrn_lo = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_csrn_hi = EXTRACT_MSB0_UINT (insn, 16, 15, 1);
  f_csrn = ((((f_csrn_hi) << (4))) | (f_csrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_csrn) = f_csrn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stc)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_csrn:0x" << hex << f_csrn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_csrn) = f_csrn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ldc_lp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldc_lp.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc_lp)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_lp) = 1;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ldc_hi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc_hi)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_hi) = 7;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ldc_lo (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc_lo)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_lo) = 8;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ldc (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldc.f
    UINT f_rn;
    UINT f_csrn_lo;
    UINT f_csrn_hi;
    UINT f_csrn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_csrn_lo = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_csrn_hi = EXTRACT_MSB0_UINT (insn, 16, 15, 1);
  f_csrn = ((((f_csrn_hi) << (4))) | (f_csrn_lo));

  /* Record the fields for the semantic handler.  */
  FLD (f_csrn) = f_csrn;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldc)\t"
        << " f_csrn:0x" << hex << f_csrn << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_csrn) = f_csrn;
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_di (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_di.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_di)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_psw) = 16;
      FLD (out_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_reti (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_reti.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_reti)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_epc) = 19;
      FLD (in_npc) = 23;
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_halt (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_di.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_halt)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sleep (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sleep)\t"
        << endl;
    }

#undef FLD
}

void
mepcore2_extract_sfmt_swi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swi.f
    UINT f_2u10;

    f_2u10 = EXTRACT_MSB0_UINT (insn, 16, 10, 2);

  /* Record the fields for the semantic handler.  */
  FLD (f_2u10) = f_2u10;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swi)\t"
        << " f_2u10:0x" << hex << f_2u10 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_exc) = 20;
      FLD (out_exc) = 20;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_break (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
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

void
mepcore2_extract_sfmt_stcb (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stcb.f
    UINT f_rn;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_16u16) = f_16u16;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stcb)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_16u16:0x" << hex << f_16u16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_bsetm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_btstm.f
    UINT f_3u5;
    UINT f_rm;

    f_3u5 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_3u5) = f_3u5;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bsetm)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_3u5:0x" << hex << f_3u5 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_btstm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_btstm.f
    UINT f_3u5;
    UINT f_rm;

    f_3u5 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_3u5) = f_3u5;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_btstm)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_3u5:0x" << hex << f_3u5 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_r0) = 0;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_tas (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_tas.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_tas)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_cache (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_tas.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cache)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_mul (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mul)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_hi) = 7;
      FLD (out_lo) = 8;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_mulr (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mulr)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_hi) = 7;
      FLD (out_lo) = 8;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_madd (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_madd)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_hi) = 7;
      FLD (in_lo) = 8;
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_hi) = 7;
      FLD (out_lo) = 8;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_maddr (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_maddr)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_hi) = 7;
      FLD (in_lo) = 8;
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_hi) = 7;
      FLD (out_lo) = 8;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_div (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_maddr.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_div)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_hi) = 7;
      FLD (out_lo) = 8;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_dret (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_dret.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_dret)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_dbg) = 24;
      FLD (in_depc) = 25;
      FLD (out_dbg) = 24;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_dbreak (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_dret.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_dbreak)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_dbg) = 24;
      FLD (out_dbg) = 24;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_ldz (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sltu3x.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldz)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_abs (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fsft.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_abs)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_min (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fsft.f
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_rn) = f_rn;
  FLD (i_rm) = & current_cpu->hardware.h_gpr[f_rm];
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_min)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rm) = f_rm;
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_clip (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_clip.f
    UINT f_rn;
    UINT f_5u24;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_5u24 = EXTRACT_MSB0_UINT (insn, 32, 24, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_5u24) = f_5u24;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_clip)\t"
        << " f_5u24:0x" << hex << f_5u24 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_clipu (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_clip.f
    UINT f_rn;
    UINT f_5u24;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_5u24 = EXTRACT_MSB0_UINT (insn, 32, 24, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_5u24) = f_5u24;
  FLD (f_rn) = f_rn;
  FLD (i_rn) = & current_cpu->hardware.h_gpr[f_rn];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_clipu)\t"
        << " f_5u24:0x" << hex << f_5u24 << dec
        << " f_rn:0x" << hex << f_rn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rn) = f_rn;
      FLD (out_rn) = f_rn;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_swcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swcp)\t"
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lwcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lwcp)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_smcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_smcp)\t"
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lmcp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lmcp)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_swcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swcpi)\t"
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lwcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lwcpi)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_smcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_smcpi)\t"
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lmcpi (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lmcpi)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_swcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swcp16)\t"
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lwcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lwcp16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_smcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_smcp16)\t"
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lmcp16 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcp16.f
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_16s16) = f_16s16;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lmcp16)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_16s16:0x" << hex << f_16s16 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sbcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
    UINT f_crn;
    UINT f_rm;
    INT f_8s24;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24 = EXTRACT_MSB0_INT (insn, 32, 24, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24) = f_8s24;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sbcpa)\t"
        << " f_8s24:0x" << hex << f_8s24 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lbcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
    UINT f_crn;
    UINT f_rm;
    INT f_8s24;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24 = EXTRACT_MSB0_INT (insn, 32, 24, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24) = f_8s24;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lbcpa)\t"
        << " f_8s24:0x" << hex << f_8s24 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_shcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a2;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a2 = ((EXTRACT_MSB0_INT (insn, 32, 24, 7)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a2) = f_8s24a2;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shcpa)\t"
        << " f_8s24a2:0x" << hex << f_8s24a2 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lhcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a2;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a2 = ((EXTRACT_MSB0_INT (insn, 32, 24, 7)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a2) = f_8s24a2;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lhcpa)\t"
        << " f_8s24a2:0x" << hex << f_8s24a2 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_swcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a4;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a4 = ((EXTRACT_MSB0_INT (insn, 32, 24, 6)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a4) = f_8s24a4;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swcpa)\t"
        << " f_8s24a4:0x" << hex << f_8s24a4 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lwcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a4;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a4 = ((EXTRACT_MSB0_INT (insn, 32, 24, 6)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a4) = f_8s24a4;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lwcpa)\t"
        << " f_8s24a4:0x" << hex << f_8s24a4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_smcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a8;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a8 = ((EXTRACT_MSB0_INT (insn, 32, 24, 5)) << (3));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a8) = f_8s24a8;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_smcpa)\t"
        << " f_8s24a8:0x" << hex << f_8s24a8 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lmcpa (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a8;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a8 = ((EXTRACT_MSB0_INT (insn, 32, 24, 5)) << (3));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a8) = f_8s24a8;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lmcpa)\t"
        << " f_8s24a8:0x" << hex << f_8s24a8 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sbcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sbcpm0.f
    UINT f_crn;
    UINT f_rm;
    INT f_8s24;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24 = EXTRACT_MSB0_INT (insn, 32, 24, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24) = f_8s24;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sbcpm0)\t"
        << " f_8s24:0x" << hex << f_8s24 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lbcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sbcpm0.f
    UINT f_crn;
    UINT f_rm;
    INT f_8s24;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24 = EXTRACT_MSB0_INT (insn, 32, 24, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24) = f_8s24;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lbcpm0)\t"
        << " f_8s24:0x" << hex << f_8s24 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_shcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shcpm0.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a2;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a2 = ((EXTRACT_MSB0_INT (insn, 32, 24, 7)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a2) = f_8s24a2;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shcpm0)\t"
        << " f_8s24a2:0x" << hex << f_8s24a2 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lhcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shcpm0.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a2;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a2 = ((EXTRACT_MSB0_INT (insn, 32, 24, 7)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a2) = f_8s24a2;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lhcpm0)\t"
        << " f_8s24a2:0x" << hex << f_8s24a2 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_swcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcpm0.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a4;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a4 = ((EXTRACT_MSB0_INT (insn, 32, 24, 6)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a4) = f_8s24a4;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swcpm0)\t"
        << " f_8s24a4:0x" << hex << f_8s24a4 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lwcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcpm0.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a4;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a4 = ((EXTRACT_MSB0_INT (insn, 32, 24, 6)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a4) = f_8s24a4;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lwcpm0)\t"
        << " f_8s24a4:0x" << hex << f_8s24a4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_smcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm0.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a8;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a8 = ((EXTRACT_MSB0_INT (insn, 32, 24, 5)) << (3));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a8) = f_8s24a8;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_smcpm0)\t"
        << " f_8s24a8:0x" << hex << f_8s24a8 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lmcpm0 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm0.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a8;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a8 = ((EXTRACT_MSB0_INT (insn, 32, 24, 5)) << (3));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a8) = f_8s24a8;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lmcpm0)\t"
        << " f_8s24a8:0x" << hex << f_8s24a8 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb0) = 12;
      FLD (in_me0) = 13;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sbcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
    UINT f_crn;
    UINT f_rm;
    INT f_8s24;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24 = EXTRACT_MSB0_INT (insn, 32, 24, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24) = f_8s24;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sbcpm1)\t"
        << " f_8s24:0x" << hex << f_8s24 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lbcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sbcpm1.f
    UINT f_crn;
    UINT f_rm;
    INT f_8s24;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24 = EXTRACT_MSB0_INT (insn, 32, 24, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24) = f_8s24;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lbcpm1)\t"
        << " f_8s24:0x" << hex << f_8s24 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_shcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a2;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a2 = ((EXTRACT_MSB0_INT (insn, 32, 24, 7)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a2) = f_8s24a2;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_shcpm1)\t"
        << " f_8s24a2:0x" << hex << f_8s24a2 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lhcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_shcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a2;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a2 = ((EXTRACT_MSB0_INT (insn, 32, 24, 7)) << (1));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a2) = f_8s24a2;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lhcpm1)\t"
        << " f_8s24a2:0x" << hex << f_8s24a2 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_swcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a4;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a4 = ((EXTRACT_MSB0_INT (insn, 32, 24, 6)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a4) = f_8s24a4;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swcpm1)\t"
        << " f_8s24a4:0x" << hex << f_8s24a4 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lwcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a4;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a4 = ((EXTRACT_MSB0_INT (insn, 32, 24, 6)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a4) = f_8s24a4;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lwcpm1)\t"
        << " f_8s24a4:0x" << hex << f_8s24a4 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_smcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a8;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a8 = ((EXTRACT_MSB0_INT (insn, 32, 24, 5)) << (3));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a8) = f_8s24a8;
  FLD (f_crn) = f_crn;
  FLD (f_rm) = f_rm;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_smcpm1)\t"
        << " f_8s24a8:0x" << hex << f_8s24a8 << dec
        << " f_crn:0x" << hex << f_crn << dec
        << " f_rm:0x" << hex << f_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_lmcpm1 (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_smcpm1.f
    UINT f_crn;
    UINT f_rm;
    SI f_8s24a8;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_8s24a8 = ((EXTRACT_MSB0_INT (insn, 32, 24, 5)) << (3));

  /* Record the fields for the semantic handler.  */
  FLD (f_8s24a8) = f_8s24a8;
  FLD (f_rm) = f_rm;
  FLD (f_crn) = f_crn;
  FLD (i_rma) = & current_cpu->hardware.h_gpr[f_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lmcpm1)\t"
        << " f_8s24a8:0x" << hex << f_8s24a8 << dec
        << " f_rm:0x" << hex << f_rm << dec
        << " f_crn:0x" << hex << f_crn << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_mb1) = 14;
      FLD (in_me1) = 15;
      FLD (in_rma) = f_rm;
      FLD (out_rma) = f_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_bcpeq (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    UINT f_rm;
    SI f_17s16a2;

    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (1))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_rm) = f_rm;
  FLD (f_17s16a2) = f_17s16a2;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bcpeq)\t"
        << " f_rm:0x" << hex << f_rm << dec
        << " f_17s16a2:0x" << hex << f_17s16a2 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_opt) = 26;
      FLD (in_psw) = 16;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_synccp (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_synccp)\t"
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcore2_extract_sfmt_sim_syscall (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_sim_syscall.f
    UINT f_5;
    UINT f_6;
    UINT f_7;
    UINT f_11;
    UINT f_callnum;

    f_5 = EXTRACT_MSB0_UINT (insn, 16, 5, 1);
    f_6 = EXTRACT_MSB0_UINT (insn, 16, 6, 1);
    f_7 = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_11 = EXTRACT_MSB0_UINT (insn, 16, 11, 1);
  f_callnum = ((((f_5) << (3))) | (((((f_6) << (2))) | (((((f_7) << (1))) | (f_11))))));

  /* Record the fields for the semantic handler.  */
  FLD (f_callnum) = f_callnum;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sim_syscall)\t"
        << " f_callnum:0x" << hex << f_callnum << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
    }
#undef FLD
}

void
mepcore2_extract_sfmt_fadds (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fadds.f
    UINT f_fmax_4_4;
    UINT f_fmax_20_4;
    UINT f_fmax_24_4;
    UINT f_fmax_28_1;
    UINT f_fmax_29_1;
    UINT f_fmax_30_1;
    UINT f_fmax_frd;
    UINT f_fmax_frn;
    UINT f_fmax_frm;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_20_4 = EXTRACT_MSB0_UINT (insn, 32, 20, 4);
    f_fmax_24_4 = EXTRACT_MSB0_UINT (insn, 32, 24, 4);
    f_fmax_28_1 = EXTRACT_MSB0_UINT (insn, 32, 28, 1);
    f_fmax_29_1 = EXTRACT_MSB0_UINT (insn, 32, 29, 1);
    f_fmax_30_1 = EXTRACT_MSB0_UINT (insn, 32, 30, 1);
  f_fmax_frd = ((((f_fmax_28_1) << (4))) | (f_fmax_4_4));
  f_fmax_frn = ((((f_fmax_29_1) << (4))) | (f_fmax_20_4));
  f_fmax_frm = ((((f_fmax_30_1) << (4))) | (f_fmax_24_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_frm) = f_fmax_frm;
  FLD (f_fmax_frn) = f_fmax_frn;
  FLD (f_fmax_frd) = f_fmax_frd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fadds)\t"
        << " f_fmax_frm:0x" << hex << f_fmax_frm << dec
        << " f_fmax_frn:0x" << hex << f_fmax_frn << dec
        << " f_fmax_frd:0x" << hex << f_fmax_frd << dec
        << endl;
    }

#undef FLD
}

void
mepcore2_extract_sfmt_fsqrts (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fadds.f
    UINT f_fmax_4_4;
    UINT f_fmax_20_4;
    UINT f_fmax_28_1;
    UINT f_fmax_29_1;
    UINT f_fmax_frd;
    UINT f_fmax_frn;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_20_4 = EXTRACT_MSB0_UINT (insn, 32, 20, 4);
    f_fmax_28_1 = EXTRACT_MSB0_UINT (insn, 32, 28, 1);
    f_fmax_29_1 = EXTRACT_MSB0_UINT (insn, 32, 29, 1);
  f_fmax_frd = ((((f_fmax_28_1) << (4))) | (f_fmax_4_4));
  f_fmax_frn = ((((f_fmax_29_1) << (4))) | (f_fmax_20_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_frn) = f_fmax_frn;
  FLD (f_fmax_frd) = f_fmax_frd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fsqrts)\t"
        << " f_fmax_frn:0x" << hex << f_fmax_frn << dec
        << " f_fmax_frd:0x" << hex << f_fmax_frd << dec
        << endl;
    }

#undef FLD
}

void
mepcore2_extract_sfmt_froundws (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fadds.f
    UINT f_fmax_4_4;
    UINT f_fmax_20_4;
    UINT f_fmax_28_1;
    UINT f_fmax_29_1;
    UINT f_fmax_frd;
    UINT f_fmax_frn;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_20_4 = EXTRACT_MSB0_UINT (insn, 32, 20, 4);
    f_fmax_28_1 = EXTRACT_MSB0_UINT (insn, 32, 28, 1);
    f_fmax_29_1 = EXTRACT_MSB0_UINT (insn, 32, 29, 1);
  f_fmax_frd = ((((f_fmax_28_1) << (4))) | (f_fmax_4_4));
  f_fmax_frn = ((((f_fmax_29_1) << (4))) | (f_fmax_20_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_frn) = f_fmax_frn;
  FLD (f_fmax_frd) = f_fmax_frd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_froundws)\t"
        << " f_fmax_frn:0x" << hex << f_fmax_frn << dec
        << " f_fmax_frd:0x" << hex << f_fmax_frd << dec
        << endl;
    }

#undef FLD
}

void
mepcore2_extract_sfmt_fcvtsw (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fadds.f
    UINT f_fmax_4_4;
    UINT f_fmax_20_4;
    UINT f_fmax_28_1;
    UINT f_fmax_29_1;
    UINT f_fmax_frd;
    UINT f_fmax_frn;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_20_4 = EXTRACT_MSB0_UINT (insn, 32, 20, 4);
    f_fmax_28_1 = EXTRACT_MSB0_UINT (insn, 32, 28, 1);
    f_fmax_29_1 = EXTRACT_MSB0_UINT (insn, 32, 29, 1);
  f_fmax_frd = ((((f_fmax_28_1) << (4))) | (f_fmax_4_4));
  f_fmax_frn = ((((f_fmax_29_1) << (4))) | (f_fmax_20_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_frn) = f_fmax_frn;
  FLD (f_fmax_frd) = f_fmax_frd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fcvtsw)\t"
        << " f_fmax_frn:0x" << hex << f_fmax_frn << dec
        << " f_fmax_frd:0x" << hex << f_fmax_frd << dec
        << endl;
    }

#undef FLD
}

void
mepcore2_extract_sfmt_fcmpfs (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_fadds.f
    UINT f_fmax_20_4;
    UINT f_fmax_24_4;
    UINT f_fmax_29_1;
    UINT f_fmax_30_1;
    UINT f_fmax_frn;
    UINT f_fmax_frm;

    f_fmax_20_4 = EXTRACT_MSB0_UINT (insn, 32, 20, 4);
    f_fmax_24_4 = EXTRACT_MSB0_UINT (insn, 32, 24, 4);
    f_fmax_29_1 = EXTRACT_MSB0_UINT (insn, 32, 29, 1);
    f_fmax_30_1 = EXTRACT_MSB0_UINT (insn, 32, 30, 1);
  f_fmax_frn = ((((f_fmax_29_1) << (4))) | (f_fmax_20_4));
  f_fmax_frm = ((((f_fmax_30_1) << (4))) | (f_fmax_24_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_frm) = f_fmax_frm;
  FLD (f_fmax_frn) = f_fmax_frn;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_fcmpfs)\t"
        << " f_fmax_frm:0x" << hex << f_fmax_frm << dec
        << " f_fmax_frn:0x" << hex << f_fmax_frn << dec
        << endl;
    }

#undef FLD
}

void
mepcore2_extract_sfmt_cmov_frn_rm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmov_frn_rm.f
    UINT f_fmax_4_4;
    UINT f_fmax_rm;
    UINT f_fmax_28_1;
    UINT f_fmax_frd;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_fmax_28_1 = EXTRACT_MSB0_UINT (insn, 32, 28, 1);
  f_fmax_frd = ((((f_fmax_28_1) << (4))) | (f_fmax_4_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_rm) = f_fmax_rm;
  FLD (f_fmax_frd) = f_fmax_frd;
  FLD (i_fmax_Rm) = & current_cpu->hardware.h_gpr[f_fmax_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmov_frn_rm)\t"
        << " f_fmax_rm:0x" << hex << f_fmax_rm << dec
        << " f_fmax_frd:0x" << hex << f_fmax_frd << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_fmax_Rm) = f_fmax_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_cmov_rm_frn (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmov_rm_frn.f
    UINT f_fmax_4_4;
    UINT f_fmax_rm;
    UINT f_fmax_28_1;
    UINT f_fmax_frd;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_fmax_28_1 = EXTRACT_MSB0_UINT (insn, 32, 28, 1);
  f_fmax_frd = ((((f_fmax_28_1) << (4))) | (f_fmax_4_4));

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_frd) = f_fmax_frd;
  FLD (f_fmax_rm) = f_fmax_rm;
  FLD (i_fmax_Rm) = & current_cpu->hardware.h_gpr[f_fmax_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmov_rm_frn)\t"
        << " f_fmax_frd:0x" << hex << f_fmax_frd << dec
        << " f_fmax_rm:0x" << hex << f_fmax_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_fmax_Rm) = f_fmax_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_cmovc_ccrn_rm (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmovc_ccrn_rm.f
    UINT f_fmax_4_4;
    UINT f_fmax_rm;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_rm) = f_fmax_rm;
  FLD (f_fmax_4_4) = f_fmax_4_4;
  FLD (i_fmax_Rm) = & current_cpu->hardware.h_gpr[f_fmax_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmovc_ccrn_rm)\t"
        << " f_fmax_rm:0x" << hex << f_fmax_rm << dec
        << " f_fmax_4_4:0x" << hex << f_fmax_4_4 << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (in_fmax_Rm) = f_fmax_rm;
    }
#undef FLD
}

void
mepcore2_extract_sfmt_cmovc_rm_ccrn (mepcore2_scache* abuf, mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn){
    mepcore2_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_cmovc_rm_ccrn.f
    UINT f_fmax_4_4;
    UINT f_fmax_rm;

    f_fmax_4_4 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_fmax_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_fmax_4_4) = f_fmax_4_4;
  FLD (f_fmax_rm) = f_fmax_rm;
  FLD (i_fmax_Rm) = & current_cpu->hardware.h_gpr[f_fmax_rm];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmovc_rm_ccrn)\t"
        << " f_fmax_4_4:0x" << hex << f_fmax_4_4 << dec
        << " f_fmax_rm:0x" << hex << f_fmax_rm << dec
        << endl;
    }

  /* Record the fields for profiling.  */
  if (UNLIKELY (current_cpu->trace_counter_p || current_cpu->final_insn_count_p))
    {
      FLD (out_fmax_Rm) = f_fmax_rm;
    }
#undef FLD
}

