/* Simulator instruction decoder for thumb.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "arm7f.h"

using namespace arm7f; // FIXME: namespace organization still wip


// The instruction descriptor array. 

// Have label pointers been initialized?
// XXX: Note that this is also needed by when semantics are implemented as
// functions to handle machine variants.
bool thumb_idesc::idesc_table_initialized_p = false;

thumb_idesc thumb_idesc::idesc_table[THUMB_INSN_BL_LO + 1] =
{
  { 0, 0, "X_AFTER", THUMB_INSN_X_AFTER, { 0|(1<<CGEN_INSN_PBB)|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, 0, "X_BEFORE", THUMB_INSN_X_BEFORE, { 0|(1<<CGEN_INSN_PBB)|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, 0, "X_CTI_CHAIN", THUMB_INSN_X_CTI_CHAIN, { 0|(1<<CGEN_INSN_PBB)|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, 0, "X_CHAIN", THUMB_INSN_X_CHAIN, { 0|(1<<CGEN_INSN_PBB)|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, 0, "X_BEGIN", THUMB_INSN_X_BEGIN, { 0|(1<<CGEN_INSN_PBB)|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_x_invalid, "X_INVALID", THUMB_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_lsl, "LSL", THUMB_INSN_LSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_lsr, "LSR", THUMB_INSN_LSR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_asr, "ASR", THUMB_INSN_ASR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_add, "ADD", THUMB_INSN_ADD, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_addi, "ADDI", THUMB_INSN_ADDI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_sub, "SUB", THUMB_INSN_SUB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_subi, "SUBI", THUMB_INSN_SUBI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_mov, "MOV", THUMB_INSN_MOV, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_cmp, "CMP", THUMB_INSN_CMP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_addi8, "ADDI8", THUMB_INSN_ADDI8, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_subi8, "SUBI8", THUMB_INSN_SUBI8, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_and, "ALU_AND", THUMB_INSN_ALU_AND, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_eor, "ALU_EOR", THUMB_INSN_ALU_EOR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_lsl, "ALU_LSL", THUMB_INSN_ALU_LSL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_lsr, "ALU_LSR", THUMB_INSN_ALU_LSR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_asr, "ALU_ASR", THUMB_INSN_ALU_ASR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_ror, "ALU_ROR", THUMB_INSN_ALU_ROR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_adc, "ALU_ADC", THUMB_INSN_ALU_ADC, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_sbc, "ALU_SBC", THUMB_INSN_ALU_SBC, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_tst, "ALU_TST", THUMB_INSN_ALU_TST, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_neg, "ALU_NEG", THUMB_INSN_ALU_NEG, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_cmp, "ALU_CMP", THUMB_INSN_ALU_CMP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_cmn, "ALU_CMN", THUMB_INSN_ALU_CMN, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_orr, "ALU_ORR", THUMB_INSN_ALU_ORR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_mul, "ALU_MUL", THUMB_INSN_ALU_MUL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_bic, "ALU_BIC", THUMB_INSN_ALU_BIC, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_alu_mvn, "ALU_MVN", THUMB_INSN_ALU_MVN, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_add_rd_hs, "ADD_RD_HS", THUMB_INSN_ADD_RD_HS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_add_hd_rs, "ADD_HD_RS", THUMB_INSN_ADD_HD_RS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_add_hd_hs, "ADD_HD_HS", THUMB_INSN_ADD_HD_HS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_cmp_rd_hs, "CMP_RD_HS", THUMB_INSN_CMP_RD_HS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_cmp_hd_rs, "CMP_HD_RS", THUMB_INSN_CMP_HD_RS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_cmp_hd_hs, "CMP_HD_HS", THUMB_INSN_CMP_HD_HS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_mov_rd_hs, "MOV_RD_HS", THUMB_INSN_MOV_RD_HS, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_mov_hd_rs, "MOV_HD_RS", THUMB_INSN_MOV_HD_RS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_mov_hd_hs, "MOV_HD_HS", THUMB_INSN_MOV_HD_HS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bx_rs, "BX_RS", THUMB_INSN_BX_RS, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bx_hs, "BX_HS", THUMB_INSN_BX_HS, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldr_pc, "LDR_PC", THUMB_INSN_LDR_PC, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_str, "STR", THUMB_INSN_STR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_strb, "STRB", THUMB_INSN_STRB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldr, "LDR", THUMB_INSN_LDR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldrb, "LDRB", THUMB_INSN_LDRB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_strh, "STRH", THUMB_INSN_STRH, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldrh, "LDRH", THUMB_INSN_LDRH, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldsb, "LDSB", THUMB_INSN_LDSB, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldsh, "LDSH", THUMB_INSN_LDSH, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_str_imm, "STR_IMM", THUMB_INSN_STR_IMM, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldr_imm, "LDR_IMM", THUMB_INSN_LDR_IMM, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_strb_imm, "STRB_IMM", THUMB_INSN_STRB_IMM, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldrb_imm, "LDRB_IMM", THUMB_INSN_LDRB_IMM, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_strh_imm, "STRH_IMM", THUMB_INSN_STRH_IMM, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldrh_imm, "LDRH_IMM", THUMB_INSN_LDRH_IMM, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_str_sprel, "STR_SPREL", THUMB_INSN_STR_SPREL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldr_sprel, "LDR_SPREL", THUMB_INSN_LDR_SPREL, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_lda_pc, "LDA_PC", THUMB_INSN_LDA_PC, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_lda_sp, "LDA_SP", THUMB_INSN_LDA_SP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_add_sp, "ADD_SP", THUMB_INSN_ADD_SP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_sub_sp, "SUB_SP", THUMB_INSN_SUB_SP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_push, "PUSH", THUMB_INSN_PUSH, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_push_lr, "PUSH_LR", THUMB_INSN_PUSH_LR, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_pop, "POP", THUMB_INSN_POP, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_pop_pc, "POP_PC", THUMB_INSN_POP_PC, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_stmia, "STMIA", THUMB_INSN_STMIA, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ldmia, "LDMIA", THUMB_INSN_LDMIA, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_beq, "BEQ", THUMB_INSN_BEQ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bne, "BNE", THUMB_INSN_BNE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bcs, "BCS", THUMB_INSN_BCS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bcc, "BCC", THUMB_INSN_BCC, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bmi, "BMI", THUMB_INSN_BMI, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bpl, "BPL", THUMB_INSN_BPL, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bvs, "BVS", THUMB_INSN_BVS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bvc, "BVC", THUMB_INSN_BVC, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bhi, "BHI", THUMB_INSN_BHI, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bls, "BLS", THUMB_INSN_BLS, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bge, "BGE", THUMB_INSN_BGE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_blt, "BLT", THUMB_INSN_BLT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bgt, "BGT", THUMB_INSN_BGT, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_ble, "BLE", THUMB_INSN_BLE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_swi, "SWI", THUMB_INSN_SWI, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_b, "B", THUMB_INSN_B, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bl_hi, "BL_HI", THUMB_INSN_BL_HI, { 0, (1<<MACH_BASE), { 1, "\x40" } } },
  { 0, thumb_sem_bl_lo, "BL_LO", THUMB_INSN_BL_LO, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), { 1, "\x40" } } },

};

// Given a canonical virtual insn id, return the target specific one.

thumb_insn_type
thumb_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return THUMB_INSN_X_INVALID;
      case VIRTUAL_INSN_BEGIN: return THUMB_INSN_X_BEGIN;
      case VIRTUAL_INSN_CHAIN: return THUMB_INSN_X_CHAIN;
      case VIRTUAL_INSN_CTI_CHAIN: return THUMB_INSN_X_CTI_CHAIN;
      case VIRTUAL_INSN_BEFORE: return THUMB_INSN_X_BEFORE;
      case VIRTUAL_INSN_AFTER: return THUMB_INSN_X_AFTER;
      case VIRTUAL_INSN_COND: return THUMB_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
thumb_extract_sfmt_empty (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_lsl (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_add (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_addi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_mov (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_cmp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_addi8 (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_alu_and (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_alu_lsl (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_alu_adc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_alu_tst (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_alu_neg (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_alu_cmp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_add_rd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_add_hd_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_add_hd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_cmp_rd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_cmp_hd_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_cmp_hd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_mov_rd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_mov_hd_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_mov_hd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bx_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bx_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldr_pc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_str (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_strb (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldr (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldrb (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_strh (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldrh (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_str_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldr_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_strb_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldrb_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_strh_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldrh_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_str_sprel (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldr_sprel (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_lda_pc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_lda_sp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_add_sp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_push (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_push_lr (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_pop (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_pop_pc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_stmia (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_ldmia (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_beq (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bcs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bmi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bvs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bhi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bge (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bgt (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_swi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_b (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bl_hi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);
static void
thumb_extract_sfmt_bl_lo (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn);

// Fetch & decode instruction
void
thumb_scache::decode (arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn)
{
  /* Result of decoder.  */
  THUMB_INSN_TYPE itype;

  {
    thumb_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 8) & (255 << 0)));
      switch (val)
      {
      case 0 : /* fall through */
      case 1 : /* fall through */
      case 2 : /* fall through */
      case 3 : /* fall through */
      case 4 : /* fall through */
      case 5 : /* fall through */
      case 6 : /* fall through */
      case 7 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LSL; thumb_extract_sfmt_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 : /* fall through */
      case 9 : /* fall through */
      case 10 : /* fall through */
      case 11 : /* fall through */
      case 12 : /* fall through */
      case 13 : /* fall through */
      case 14 : /* fall through */
      case 15 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LSR; thumb_extract_sfmt_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 : /* fall through */
      case 17 : /* fall through */
      case 18 : /* fall through */
      case 19 : /* fall through */
      case 20 : /* fall through */
      case 21 : /* fall through */
      case 22 : /* fall through */
      case 23 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_ASR; thumb_extract_sfmt_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 : /* fall through */
      case 25 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_ADD; thumb_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 26 : /* fall through */
      case 27 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_SUB; thumb_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 28 : /* fall through */
      case 29 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_ADDI; thumb_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 30 : /* fall through */
      case 31 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_SUBI; thumb_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 32 : /* fall through */
      case 33 : /* fall through */
      case 34 : /* fall through */
      case 35 : /* fall through */
      case 36 : /* fall through */
      case 37 : /* fall through */
      case 38 : /* fall through */
      case 39 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_MOV; thumb_extract_sfmt_mov (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 40 : /* fall through */
      case 41 : /* fall through */
      case 42 : /* fall through */
      case 43 : /* fall through */
      case 44 : /* fall through */
      case 45 : /* fall through */
      case 46 : /* fall through */
      case 47 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_CMP; thumb_extract_sfmt_cmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 48 : /* fall through */
      case 49 : /* fall through */
      case 50 : /* fall through */
      case 51 : /* fall through */
      case 52 : /* fall through */
      case 53 : /* fall through */
      case 54 : /* fall through */
      case 55 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_ADDI8; thumb_extract_sfmt_addi8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 56 : /* fall through */
      case 57 : /* fall through */
      case 58 : /* fall through */
      case 59 : /* fall through */
      case 60 : /* fall through */
      case 61 : /* fall through */
      case 62 : /* fall through */
      case 63 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_SUBI8; thumb_extract_sfmt_addi8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 64 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_AND; thumb_extract_sfmt_alu_and (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_EOR; thumb_extract_sfmt_alu_and (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_LSL; thumb_extract_sfmt_alu_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_LSR; thumb_extract_sfmt_alu_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 65 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_ASR; thumb_extract_sfmt_alu_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_ADC; thumb_extract_sfmt_alu_adc (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_SBC; thumb_extract_sfmt_alu_adc (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_ROR; thumb_extract_sfmt_alu_lsl (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 66 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_TST; thumb_extract_sfmt_alu_tst (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_NEG; thumb_extract_sfmt_alu_neg (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_CMP; thumb_extract_sfmt_alu_cmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_CMN; thumb_extract_sfmt_alu_cmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 67 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_ORR; thumb_extract_sfmt_alu_and (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_MUL; thumb_extract_sfmt_alu_and (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_BIC; thumb_extract_sfmt_alu_and (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ALU_MVN; thumb_extract_sfmt_alu_and (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 68 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ADD_RD_HS; thumb_extract_sfmt_add_rd_hs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ADD_HD_RS; thumb_extract_sfmt_add_hd_rs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ADD_HD_HS; thumb_extract_sfmt_add_hd_hs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 69 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_CMP_RD_HS; thumb_extract_sfmt_cmp_rd_hs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_CMP_HD_RS; thumb_extract_sfmt_cmp_hd_rs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_CMP_HD_HS; thumb_extract_sfmt_cmp_hd_hs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 70 :
        {
          unsigned int val = (((insn >> 6) & (3 << 0)));
          switch (val)
          {
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_MOV_RD_HS; thumb_extract_sfmt_mov_rd_hs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_MOV_HD_RS; thumb_extract_sfmt_mov_hd_rs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_MOV_HD_HS; thumb_extract_sfmt_mov_hd_hs (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 71 :
        {
          unsigned int val = (((insn >> 6) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffc7) == 0x4700)
              { itype = THUMB_INSN_BX_RS; thumb_extract_sfmt_bx_rs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffc7) == 0x4740)
              { itype = THUMB_INSN_BX_HS; thumb_extract_sfmt_bx_hs (this, current_cpu, pc, base_insn, entire_insn); goto done; }
            itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 72 : /* fall through */
      case 73 : /* fall through */
      case 74 : /* fall through */
      case 75 : /* fall through */
      case 76 : /* fall through */
      case 77 : /* fall through */
      case 78 : /* fall through */
      case 79 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDR_PC; thumb_extract_sfmt_ldr_pc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 80 : /* fall through */
      case 81 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STR; thumb_extract_sfmt_str (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 82 : /* fall through */
      case 83 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STRH; thumb_extract_sfmt_strh (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 84 : /* fall through */
      case 85 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STRB; thumb_extract_sfmt_strb (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 86 : /* fall through */
      case 87 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDSB; thumb_extract_sfmt_ldrb (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 88 : /* fall through */
      case 89 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDR; thumb_extract_sfmt_ldr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 90 : /* fall through */
      case 91 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDRH; thumb_extract_sfmt_ldrh (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 92 : /* fall through */
      case 93 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDRB; thumb_extract_sfmt_ldrb (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 94 : /* fall through */
      case 95 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDSH; thumb_extract_sfmt_ldrh (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 96 : /* fall through */
      case 97 : /* fall through */
      case 98 : /* fall through */
      case 99 : /* fall through */
      case 100 : /* fall through */
      case 101 : /* fall through */
      case 102 : /* fall through */
      case 103 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STR_IMM; thumb_extract_sfmt_str_imm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 104 : /* fall through */
      case 105 : /* fall through */
      case 106 : /* fall through */
      case 107 : /* fall through */
      case 108 : /* fall through */
      case 109 : /* fall through */
      case 110 : /* fall through */
      case 111 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDR_IMM; thumb_extract_sfmt_ldr_imm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 112 : /* fall through */
      case 113 : /* fall through */
      case 114 : /* fall through */
      case 115 : /* fall through */
      case 116 : /* fall through */
      case 117 : /* fall through */
      case 118 : /* fall through */
      case 119 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STRB_IMM; thumb_extract_sfmt_strb_imm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 120 : /* fall through */
      case 121 : /* fall through */
      case 122 : /* fall through */
      case 123 : /* fall through */
      case 124 : /* fall through */
      case 125 : /* fall through */
      case 126 : /* fall through */
      case 127 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDRB_IMM; thumb_extract_sfmt_ldrb_imm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 128 : /* fall through */
      case 129 : /* fall through */
      case 130 : /* fall through */
      case 131 : /* fall through */
      case 132 : /* fall through */
      case 133 : /* fall through */
      case 134 : /* fall through */
      case 135 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STRH_IMM; thumb_extract_sfmt_strh_imm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 136 : /* fall through */
      case 137 : /* fall through */
      case 138 : /* fall through */
      case 139 : /* fall through */
      case 140 : /* fall through */
      case 141 : /* fall through */
      case 142 : /* fall through */
      case 143 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDRH_IMM; thumb_extract_sfmt_ldrh_imm (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 144 : /* fall through */
      case 145 : /* fall through */
      case 146 : /* fall through */
      case 147 : /* fall through */
      case 148 : /* fall through */
      case 149 : /* fall through */
      case 150 : /* fall through */
      case 151 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STR_SPREL; thumb_extract_sfmt_str_sprel (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 152 : /* fall through */
      case 153 : /* fall through */
      case 154 : /* fall through */
      case 155 : /* fall through */
      case 156 : /* fall through */
      case 157 : /* fall through */
      case 158 : /* fall through */
      case 159 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDR_SPREL; thumb_extract_sfmt_ldr_sprel (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 160 : /* fall through */
      case 161 : /* fall through */
      case 162 : /* fall through */
      case 163 : /* fall through */
      case 164 : /* fall through */
      case 165 : /* fall through */
      case 166 : /* fall through */
      case 167 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDA_PC; thumb_extract_sfmt_lda_pc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 168 : /* fall through */
      case 169 : /* fall through */
      case 170 : /* fall through */
      case 171 : /* fall through */
      case 172 : /* fall through */
      case 173 : /* fall through */
      case 174 : /* fall through */
      case 175 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDA_SP; thumb_extract_sfmt_lda_sp (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 176 :
        {
          unsigned int val = (((insn >> 7) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_ADD_SP; thumb_extract_sfmt_add_sp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = THUMB_INSN_SUB_SP; thumb_extract_sfmt_add_sp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
          }
        }
      case 180 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_PUSH; thumb_extract_sfmt_push (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 181 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_PUSH_LR; thumb_extract_sfmt_push_lr (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 188 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_POP; thumb_extract_sfmt_pop (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 189 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_POP_PC; thumb_extract_sfmt_pop_pc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 192 : /* fall through */
      case 193 : /* fall through */
      case 194 : /* fall through */
      case 195 : /* fall through */
      case 196 : /* fall through */
      case 197 : /* fall through */
      case 198 : /* fall through */
      case 199 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_STMIA; thumb_extract_sfmt_stmia (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 200 : /* fall through */
      case 201 : /* fall through */
      case 202 : /* fall through */
      case 203 : /* fall through */
      case 204 : /* fall through */
      case 205 : /* fall through */
      case 206 : /* fall through */
      case 207 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_LDMIA; thumb_extract_sfmt_ldmia (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 208 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BEQ; thumb_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 209 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BNE; thumb_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 210 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BCS; thumb_extract_sfmt_bcs (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 211 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BCC; thumb_extract_sfmt_bcs (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 212 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BMI; thumb_extract_sfmt_bmi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 213 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BPL; thumb_extract_sfmt_bmi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 214 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BVS; thumb_extract_sfmt_bvs (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 215 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BVC; thumb_extract_sfmt_bvs (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 216 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BHI; thumb_extract_sfmt_bhi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 217 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BLS; thumb_extract_sfmt_bhi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 218 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BGE; thumb_extract_sfmt_bge (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 219 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BLT; thumb_extract_sfmt_bge (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 220 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BGT; thumb_extract_sfmt_bgt (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 221 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BLE; thumb_extract_sfmt_bgt (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 223 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_SWI; thumb_extract_sfmt_swi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 224 : /* fall through */
      case 225 : /* fall through */
      case 226 : /* fall through */
      case 227 : /* fall through */
      case 228 : /* fall through */
      case 229 : /* fall through */
      case 230 : /* fall through */
      case 231 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_B; thumb_extract_sfmt_b (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 240 : /* fall through */
      case 241 : /* fall through */
      case 242 : /* fall through */
      case 243 : /* fall through */
      case 244 : /* fall through */
      case 245 : /* fall through */
      case 246 : /* fall through */
      case 247 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BL_HI; thumb_extract_sfmt_bl_hi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 248 : /* fall through */
      case 249 : /* fall through */
      case 250 : /* fall through */
      case 251 : /* fall through */
      case 252 : /* fall through */
      case 253 : /* fall through */
      case 254 : /* fall through */
      case 255 :
        entire_insn = entire_insn >> 16;
        itype = THUMB_INSN_BL_LO; thumb_extract_sfmt_bl_lo (this, current_cpu, pc, base_insn, entire_insn); goto done;
      default : itype = THUMB_INSN_X_INVALID; thumb_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn); goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & thumb_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
thumb_extract_sfmt_empty (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
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
thumb_extract_sfmt_lsl (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_lsl.f
    UINT f_offset5;
    UINT f_rs;
    UINT f_rd;

    f_offset5 = EXTRACT_LSB0_UINT (insn, 16, 10, 5);
    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5) = f_offset5;
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lsl)\t"
        << " f_offset5:0x" << hex << f_offset5 << dec
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_add (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add.f
    UINT f_rn;
    UINT f_rs;
    UINT f_rd;

    f_rn = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rn) = f_rn;
  FLD (f_rs) = f_rs;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add)\t"
        << " f_rn:0x" << hex << f_rn << dec
        << " f_rs:0x" << hex << f_rs << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_addi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_offset3;
    UINT f_rs;
    UINT f_rd;

    f_offset3 = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset3) = f_offset3;
  FLD (f_rs) = f_rs;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addi)\t"
        << " f_offset3:0x" << hex << f_offset3 << dec
        << " f_rs:0x" << hex << f_rs << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_mov (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mov.f
    UINT f_bit10_rd;
    UINT f_offset8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_offset8 = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_bit10_rd) = f_bit10_rd;
  FLD (f_offset8) = f_offset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mov)\t"
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << " f_offset8:0x" << hex << f_offset8 << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_cmp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mov.f
    UINT f_bit10_rd;
    UINT f_offset8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_offset8 = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_bit10_rd) = f_bit10_rd;
  FLD (f_offset8) = f_offset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmp)\t"
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << " f_offset8:0x" << hex << f_offset8 << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_addi8 (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_mov.f
    UINT f_bit10_rd;
    UINT f_offset8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_offset8 = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_bit10_rd) = f_bit10_rd;
  FLD (f_offset8) = f_offset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addi8)\t"
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << " f_offset8:0x" << hex << f_offset8 << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_alu_and (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alu_and)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_alu_lsl (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alu_lsl)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_alu_adc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alu_adc)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_alu_tst (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alu_tst)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_alu_neg (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rs) = f_rs;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alu_neg)\t"
        << " f_rs:0x" << hex << f_rs << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_alu_cmp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_alu_cmp)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_add_rd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rs) = f_rs;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add_rd_hs)\t"
        << " f_rs:0x" << hex << f_rs << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_add_hd_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add_hd_rs)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_add_hd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add_hd_hs)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_cmp_rd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rs) = f_rs;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmp_rd_hs)\t"
        << " f_rs:0x" << hex << f_rs << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_cmp_hd_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmp_hd_rs)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_cmp_hd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmp_hd_hs)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_mov_rd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rs) = f_rs;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mov_rd_hs)\t"
        << " f_rs:0x" << hex << f_rs << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_mov_hd_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mov_hd_rs)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_mov_hd_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;
    UINT f_rd;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rd) = f_rd;
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mov_hd_hs)\t"
        << " f_rd:0x" << hex << f_rd << dec
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bx_rs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bx_rs)\t"
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bx_hs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_rs;

    f_rs = EXTRACT_LSB0_UINT (insn, 16, 5, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rs) = f_rs;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bx_hs)\t"
        << " f_rs:0x" << hex << f_rs << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldr_pc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
    UINT f_bit10_rd;
    SI f_word8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_word8 = ((EXTRACT_LSB0_UINT (insn, 16, 7, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_word8) = f_word8;
  FLD (f_bit10_rd) = f_bit10_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldr_pc)\t"
        << " f_word8:0x" << hex << f_word8 << dec
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_str (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str.f
    UINT f_ro;
    UINT f_rb;
    UINT f_rd;

    f_ro = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  FLD (f_ro) = f_ro;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_str)\t"
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << " f_ro:0x" << hex << f_ro << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_strb (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str.f
    UINT f_ro;
    UINT f_rb;
    UINT f_rd;

    f_ro = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  FLD (f_ro) = f_ro;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_strb)\t"
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << " f_ro:0x" << hex << f_ro << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldr (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str.f
    UINT f_ro;
    UINT f_rb;
    UINT f_rd;

    f_ro = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rb) = f_rb;
  FLD (f_ro) = f_ro;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldr)\t"
        << " f_rb:0x" << hex << f_rb << dec
        << " f_ro:0x" << hex << f_ro << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldrb (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str.f
    UINT f_ro;
    UINT f_rb;
    UINT f_rd;

    f_ro = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rb) = f_rb;
  FLD (f_ro) = f_ro;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldrb)\t"
        << " f_rb:0x" << hex << f_rb << dec
        << " f_ro:0x" << hex << f_ro << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_strh (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str.f
    UINT f_ro;
    UINT f_rb;
    UINT f_rd;

    f_ro = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  FLD (f_ro) = f_ro;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_strh)\t"
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << " f_ro:0x" << hex << f_ro << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldrh (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str.f
    UINT f_ro;
    UINT f_rb;
    UINT f_rd;

    f_ro = EXTRACT_LSB0_UINT (insn, 16, 8, 3);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_rb) = f_rb;
  FLD (f_ro) = f_ro;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldrh)\t"
        << " f_rb:0x" << hex << f_rb << dec
        << " f_ro:0x" << hex << f_ro << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_str_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str_imm.f
    SI f_offset5_7;
    UINT f_rb;
    UINT f_rd;

    f_offset5_7 = ((EXTRACT_LSB0_UINT (insn, 16, 10, 5)) << (2));
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5_7) = f_offset5_7;
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_str_imm)\t"
        << " f_offset5_7:0x" << hex << f_offset5_7 << dec
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldr_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_str_imm.f
    SI f_offset5_7;
    UINT f_rb;
    UINT f_rd;

    f_offset5_7 = ((EXTRACT_LSB0_UINT (insn, 16, 10, 5)) << (2));
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5_7) = f_offset5_7;
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldr_imm)\t"
        << " f_offset5_7:0x" << hex << f_offset5_7 << dec
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_strb_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_strb_imm.f
    UINT f_offset5;
    UINT f_rb;
    UINT f_rd;

    f_offset5 = EXTRACT_LSB0_UINT (insn, 16, 10, 5);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5) = f_offset5;
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_strb_imm)\t"
        << " f_offset5:0x" << hex << f_offset5 << dec
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldrb_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_strb_imm.f
    UINT f_offset5;
    UINT f_rb;
    UINT f_rd;

    f_offset5 = EXTRACT_LSB0_UINT (insn, 16, 10, 5);
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5) = f_offset5;
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldrb_imm)\t"
        << " f_offset5:0x" << hex << f_offset5 << dec
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_strh_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_strh_imm.f
    SI f_offset5_6;
    UINT f_rb;
    UINT f_rd;

    f_offset5_6 = ((EXTRACT_LSB0_UINT (insn, 16, 10, 5)) << (1));
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5_6) = f_offset5_6;
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_strh_imm)\t"
        << " f_offset5_6:0x" << hex << f_offset5_6 << dec
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldrh_imm (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_strh_imm.f
    SI f_offset5_6;
    UINT f_rb;
    UINT f_rd;

    f_offset5_6 = ((EXTRACT_LSB0_UINT (insn, 16, 10, 5)) << (1));
    f_rb = EXTRACT_LSB0_UINT (insn, 16, 5, 3);
    f_rd = EXTRACT_LSB0_UINT (insn, 16, 2, 3);

  /* Record the fields for the semantic handler.  */
  FLD (f_offset5_6) = f_offset5_6;
  FLD (f_rb) = f_rb;
  FLD (f_rd) = f_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldrh_imm)\t"
        << " f_offset5_6:0x" << hex << f_offset5_6 << dec
        << " f_rb:0x" << hex << f_rb << dec
        << " f_rd:0x" << hex << f_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_str_sprel (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
    UINT f_bit10_rd;
    SI f_word8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_word8 = ((EXTRACT_LSB0_UINT (insn, 16, 7, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_bit10_rd) = f_bit10_rd;
  FLD (f_word8) = f_word8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_str_sprel)\t"
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << " f_word8:0x" << hex << f_word8 << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldr_sprel (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
    UINT f_bit10_rd;
    SI f_word8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_word8 = ((EXTRACT_LSB0_UINT (insn, 16, 7, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_word8) = f_word8;
  FLD (f_bit10_rd) = f_bit10_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldr_sprel)\t"
        << " f_word8:0x" << hex << f_word8 << dec
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_lda_pc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
    UINT f_bit10_rd;
    SI f_word8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_word8 = ((EXTRACT_LSB0_UINT (insn, 16, 7, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_word8) = f_word8;
  FLD (f_bit10_rd) = f_bit10_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lda_pc)\t"
        << " f_word8:0x" << hex << f_word8 << dec
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_lda_sp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
    UINT f_bit10_rd;
    SI f_word8;

    f_bit10_rd = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_word8 = ((EXTRACT_LSB0_UINT (insn, 16, 7, 8)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_word8) = f_word8;
  FLD (f_bit10_rd) = f_bit10_rd;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lda_sp)\t"
        << " f_word8:0x" << hex << f_word8 << dec
        << " f_bit10_rd:0x" << hex << f_bit10_rd << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_add_sp (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add_sp.f
    SI f_sword7;

    f_sword7 = ((EXTRACT_LSB0_UINT (insn, 16, 6, 7)) << (2));

  /* Record the fields for the semantic handler.  */
  FLD (f_sword7) = f_sword7;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add_sp)\t"
        << " f_sword7:0x" << hex << f_sword7 << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_push (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stmia.f
    UINT f_rlist;

    f_rlist = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_rlist) = f_rlist;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_push)\t"
        << " f_rlist:0x" << hex << f_rlist << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_push_lr (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stmia.f
    UINT f_rlist;

    f_rlist = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_rlist) = f_rlist;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_push_lr)\t"
        << " f_rlist:0x" << hex << f_rlist << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_pop (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stmia.f
    UINT f_rlist;

    f_rlist = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_rlist) = f_rlist;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_pop)\t"
        << " f_rlist:0x" << hex << f_rlist << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_pop_pc (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stmia.f
    UINT f_rlist;

    f_rlist = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_rlist) = f_rlist;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_pop_pc)\t"
        << " f_rlist:0x" << hex << f_rlist << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_stmia (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stmia.f
    UINT f_bit10_rb;
    UINT f_rlist;

    f_bit10_rb = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_rlist = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_bit10_rb) = f_bit10_rb;
  FLD (f_rlist) = f_rlist;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stmia)\t"
        << " f_bit10_rb:0x" << hex << f_bit10_rb << dec
        << " f_rlist:0x" << hex << f_rlist << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_ldmia (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_stmia.f
    UINT f_bit10_rb;
    UINT f_rlist;

    f_bit10_rb = EXTRACT_LSB0_UINT (insn, 16, 10, 3);
    f_rlist = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_bit10_rb) = f_bit10_rb;
  FLD (f_rlist) = f_rlist;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldmia)\t"
        << " f_bit10_rb:0x" << hex << f_bit10_rb << dec
        << " f_rlist:0x" << hex << f_rlist << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_beq (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beq)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bcs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bcs)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bmi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bmi)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bvs (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bvs)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bhi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bhi)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bge (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bge)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bgt (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    SI f_soffset8;

    f_soffset8 = ((((EXTRACT_LSB0_INT (insn, 16, 7, 8)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_soffset8) = f_soffset8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bgt)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_swi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_swi.f
    UINT f_value8;

    f_value8 = EXTRACT_LSB0_UINT (insn, 16, 7, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_value8) = f_value8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_swi)\t"
        << " f_value8:0x" << hex << f_value8 << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_b (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_b.f
    SI f_offset11;

    f_offset11 = ((((EXTRACT_LSB0_INT (insn, 16, 10, 11)) << (1))) + (((pc) + (4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_offset11) = f_offset11;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_b)\t"
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bl_hi (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bl_hi.f
    INT f_lbwl_hi;

    f_lbwl_hi = EXTRACT_LSB0_INT (insn, 16, 10, 11);

  /* Record the fields for the semantic handler.  */
  FLD (f_lbwl_hi) = f_lbwl_hi;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bl_hi)\t"
        << " f_lbwl_hi:0x" << hex << f_lbwl_hi << dec
        << endl;
    }

#undef FLD
}

void
thumb_extract_sfmt_bl_lo (thumb_scache* abuf, arm7f_cpu* current_cpu, PCADDR pc, thumb_insn_word base_insn, thumb_insn_word entire_insn){
    thumb_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bl_lo.f
    UINT f_lbwl_lo;

    f_lbwl_lo = EXTRACT_LSB0_UINT (insn, 16, 10, 11);

  /* Record the fields for the semantic handler.  */
  FLD (f_lbwl_lo) = f_lbwl_lo;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bl_lo)\t"
        << " f_lbwl_lo:0x" << hex << f_lbwl_lo << dec
        << endl;
    }

#undef FLD
}

