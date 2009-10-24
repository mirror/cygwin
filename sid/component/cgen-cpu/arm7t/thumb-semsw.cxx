/* Simulator instruction semantics for thumb.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "arm7f.h"

using namespace arm7f; // FIXME: namespace organization still wip

#define GET_ATTR(name) GET_ATTR_##name ()


void
arm7f_cpu::thumb_pbb_run ()
{
  arm7f_cpu* current_cpu = this;
  thumb_scache* vpc;
  // These two are used to pass data from cti insns to the cti-chain insn.
  PCADDR pbb_br_npc;
  branch_status pbb_br_status;

#ifdef __GNUC__
{
  static const struct sem_labels
    {
      enum thumb_insn_type insn;
      void *label;
    }
  labels[] = 
    {
      { THUMB_INSN_X_AFTER, && case_INSN_X_AFTER },
      { THUMB_INSN_X_BEFORE, && case_INSN_X_BEFORE },
      { THUMB_INSN_X_CTI_CHAIN, && case_INSN_X_CTI_CHAIN },
      { THUMB_INSN_X_CHAIN, && case_INSN_X_CHAIN },
      { THUMB_INSN_X_BEGIN, && case_INSN_X_BEGIN },
      { THUMB_INSN_X_INVALID, && case_INSN_X_INVALID },
      { THUMB_INSN_LSL, && case_INSN_LSL },
      { THUMB_INSN_LSR, && case_INSN_LSR },
      { THUMB_INSN_ASR, && case_INSN_ASR },
      { THUMB_INSN_ADD, && case_INSN_ADD },
      { THUMB_INSN_ADDI, && case_INSN_ADDI },
      { THUMB_INSN_SUB, && case_INSN_SUB },
      { THUMB_INSN_SUBI, && case_INSN_SUBI },
      { THUMB_INSN_MOV, && case_INSN_MOV },
      { THUMB_INSN_CMP, && case_INSN_CMP },
      { THUMB_INSN_ADDI8, && case_INSN_ADDI8 },
      { THUMB_INSN_SUBI8, && case_INSN_SUBI8 },
      { THUMB_INSN_ALU_AND, && case_INSN_ALU_AND },
      { THUMB_INSN_ALU_EOR, && case_INSN_ALU_EOR },
      { THUMB_INSN_ALU_LSL, && case_INSN_ALU_LSL },
      { THUMB_INSN_ALU_LSR, && case_INSN_ALU_LSR },
      { THUMB_INSN_ALU_ASR, && case_INSN_ALU_ASR },
      { THUMB_INSN_ALU_ROR, && case_INSN_ALU_ROR },
      { THUMB_INSN_ALU_ADC, && case_INSN_ALU_ADC },
      { THUMB_INSN_ALU_SBC, && case_INSN_ALU_SBC },
      { THUMB_INSN_ALU_TST, && case_INSN_ALU_TST },
      { THUMB_INSN_ALU_NEG, && case_INSN_ALU_NEG },
      { THUMB_INSN_ALU_CMP, && case_INSN_ALU_CMP },
      { THUMB_INSN_ALU_CMN, && case_INSN_ALU_CMN },
      { THUMB_INSN_ALU_ORR, && case_INSN_ALU_ORR },
      { THUMB_INSN_ALU_MUL, && case_INSN_ALU_MUL },
      { THUMB_INSN_ALU_BIC, && case_INSN_ALU_BIC },
      { THUMB_INSN_ALU_MVN, && case_INSN_ALU_MVN },
      { THUMB_INSN_ADD_RD_HS, && case_INSN_ADD_RD_HS },
      { THUMB_INSN_ADD_HD_RS, && case_INSN_ADD_HD_RS },
      { THUMB_INSN_ADD_HD_HS, && case_INSN_ADD_HD_HS },
      { THUMB_INSN_CMP_RD_HS, && case_INSN_CMP_RD_HS },
      { THUMB_INSN_CMP_HD_RS, && case_INSN_CMP_HD_RS },
      { THUMB_INSN_CMP_HD_HS, && case_INSN_CMP_HD_HS },
      { THUMB_INSN_MOV_RD_HS, && case_INSN_MOV_RD_HS },
      { THUMB_INSN_MOV_HD_RS, && case_INSN_MOV_HD_RS },
      { THUMB_INSN_MOV_HD_HS, && case_INSN_MOV_HD_HS },
      { THUMB_INSN_BX_RS, && case_INSN_BX_RS },
      { THUMB_INSN_BX_HS, && case_INSN_BX_HS },
      { THUMB_INSN_LDR_PC, && case_INSN_LDR_PC },
      { THUMB_INSN_STR, && case_INSN_STR },
      { THUMB_INSN_STRB, && case_INSN_STRB },
      { THUMB_INSN_LDR, && case_INSN_LDR },
      { THUMB_INSN_LDRB, && case_INSN_LDRB },
      { THUMB_INSN_STRH, && case_INSN_STRH },
      { THUMB_INSN_LDRH, && case_INSN_LDRH },
      { THUMB_INSN_LDSB, && case_INSN_LDSB },
      { THUMB_INSN_LDSH, && case_INSN_LDSH },
      { THUMB_INSN_STR_IMM, && case_INSN_STR_IMM },
      { THUMB_INSN_LDR_IMM, && case_INSN_LDR_IMM },
      { THUMB_INSN_STRB_IMM, && case_INSN_STRB_IMM },
      { THUMB_INSN_LDRB_IMM, && case_INSN_LDRB_IMM },
      { THUMB_INSN_STRH_IMM, && case_INSN_STRH_IMM },
      { THUMB_INSN_LDRH_IMM, && case_INSN_LDRH_IMM },
      { THUMB_INSN_STR_SPREL, && case_INSN_STR_SPREL },
      { THUMB_INSN_LDR_SPREL, && case_INSN_LDR_SPREL },
      { THUMB_INSN_LDA_PC, && case_INSN_LDA_PC },
      { THUMB_INSN_LDA_SP, && case_INSN_LDA_SP },
      { THUMB_INSN_ADD_SP, && case_INSN_ADD_SP },
      { THUMB_INSN_SUB_SP, && case_INSN_SUB_SP },
      { THUMB_INSN_PUSH, && case_INSN_PUSH },
      { THUMB_INSN_PUSH_LR, && case_INSN_PUSH_LR },
      { THUMB_INSN_POP, && case_INSN_POP },
      { THUMB_INSN_POP_PC, && case_INSN_POP_PC },
      { THUMB_INSN_STMIA, && case_INSN_STMIA },
      { THUMB_INSN_LDMIA, && case_INSN_LDMIA },
      { THUMB_INSN_BEQ, && case_INSN_BEQ },
      { THUMB_INSN_BNE, && case_INSN_BNE },
      { THUMB_INSN_BCS, && case_INSN_BCS },
      { THUMB_INSN_BCC, && case_INSN_BCC },
      { THUMB_INSN_BMI, && case_INSN_BMI },
      { THUMB_INSN_BPL, && case_INSN_BPL },
      { THUMB_INSN_BVS, && case_INSN_BVS },
      { THUMB_INSN_BVC, && case_INSN_BVC },
      { THUMB_INSN_BHI, && case_INSN_BHI },
      { THUMB_INSN_BLS, && case_INSN_BLS },
      { THUMB_INSN_BGE, && case_INSN_BGE },
      { THUMB_INSN_BLT, && case_INSN_BLT },
      { THUMB_INSN_BGT, && case_INSN_BGT },
      { THUMB_INSN_BLE, && case_INSN_BLE },
      { THUMB_INSN_SWI, && case_INSN_SWI },
      { THUMB_INSN_B, && case_INSN_B },
      { THUMB_INSN_BL_HI, && case_INSN_BL_HI },
      { THUMB_INSN_BL_LO, && case_INSN_BL_LO },
    { (thumb_insn_type) 0, 0 }
  };

  if (! thumb_idesc::idesc_table_initialized_p)
    {
      for (int i=0; labels[i].label != 0; i++)
	thumb_idesc::idesc_table[labels[i].insn].cgoto.label = labels[i].label; 

      // confirm that table is all filled up
      for (int i = 0; i <= THUMB_INSN_BL_LO; i++)
        assert (thumb_idesc::idesc_table[i].cgoto.label != 0);

      // Initialize the compiler virtual insn.
      current_cpu->thumb_engine.compile_begin_insn (current_cpu);

      thumb_idesc::idesc_table_initialized_p = true;
    }
}
#endif

#ifdef __GNUC__
#define CASE(X) case_##X
// Branch to next handler without going around main loop.
#define NEXT(vpc) goto * vpc->execute.cgoto.label;
// Break out of threaded interpreter and return to "main loop".
#define BREAK(vpc) goto end_switch
#else
#define CASE(X) case THUMB_##X
#define NEXT(vpc) goto restart
#define BREAK(vpc) break
#endif

  // Get next insn to execute.
  vpc = current_cpu->thumb_engine.get_next_vpc (current_cpu->h_pc_get ());

restart:
#ifdef __GNUC__
  goto * vpc->execute.cgoto.label;
#else
  switch (vpc->idesc->sem_index)
#endif

  {
// ********** --after--

  CASE (INSN_X_AFTER):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.fmt_empty.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;

  {
    current_cpu->thumb_engine.pbb_after (current_cpu, abuf);
  }

#undef FLD
    }
    NEXT (vpc);

// ********** --before--

  CASE (INSN_X_BEFORE):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.fmt_empty.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;

  {
    current_cpu->thumb_engine.pbb_before (current_cpu, abuf);
  }

#undef FLD
    }
    NEXT (vpc);

// ********** --cti-chain--

  CASE (INSN_X_CTI_CHAIN):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.fmt_empty.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;

  {
    vpc = current_cpu->thumb_engine.pbb_cti_chain (current_cpu, abuf, pbb_br_status, pbb_br_npc);
    // If we don't have to give up control, don't.
    // Note that we may overrun step_insn_count since we do the test at the
    // end of the block.  This is defined to be ok.
    if (UNLIKELY(current_cpu->stop_after_insns_p (abuf->fields.chain.insn_count)))
      BREAK (vpc);
  }

#undef FLD
    }
    NEXT (vpc);

// ********** --chain--

  CASE (INSN_X_CHAIN):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.fmt_empty.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;

  {
    vpc = current_cpu->thumb_engine.pbb_chain (current_cpu, abuf);
    // If we don't have to give up control, don't.
    // Note that we may overrun step_insn_count since we do the test at the
    // end of the block.  This is defined to be ok.
    if (UNLIKELY(current_cpu->stop_after_insns_p (abuf->fields.chain.insn_count)))
      BREAK (vpc);
  }

#undef FLD
    }
    NEXT (vpc);

// ********** --begin--

  CASE (INSN_X_BEGIN):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.fmt_empty.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;

  {
    vpc = current_cpu->thumb_pbb_begin (current_cpu->h_pc_get ());
  }

#undef FLD
    }
    NEXT (vpc);

// ********** --invalid--

  CASE (INSN_X_INVALID):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.fmt_empty.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;

  {
    current_cpu->invalid_insn (pc);
    assert (0);
    /* NOTREACHED */
  }

#undef FLD
    }
    NEXT (vpc);

// ********** lsl $rd,$rs,#$offset5

  CASE (INSN_LSL):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_lsl.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  tmp_carry_out = current_cpu->compute_carry_out_immshift (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), SHIFT_TYPE_LSL, FLD (f_offset5), current_cpu->hardware.h_cbit);
current_cpu->thumb_h_gr_t_set (FLD (f_rd), SLLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset5)));
{
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** lsr $rd,$rs,#$offset5

  CASE (INSN_LSR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_lsl.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  tmp_carry_out = current_cpu->compute_carry_out_immshift (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), SHIFT_TYPE_LSR, FLD (f_offset5), current_cpu->hardware.h_cbit);
current_cpu->thumb_h_gr_t_set (FLD (f_rd), SRLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset5)));
{
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** asr $rd,$rs,#$offset5

  CASE (INSN_ASR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_lsl.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  tmp_carry_out = current_cpu->compute_carry_out_immshift (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), SHIFT_TYPE_ASR, FLD (f_offset5), current_cpu->hardware.h_cbit);
current_cpu->thumb_h_gr_t_set (FLD (f_rd), SRASI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset5)));
{
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** add $rd,$rs,$rn

  CASE (INSN_ADD):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_add.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
current_cpu->hardware.h_vbit = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn))));
}

#undef FLD
    }
    NEXT (vpc);

// ********** add $rd,$rs,#$offset3

  CASE (INSN_ADDI):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
current_cpu->hardware.h_vbit = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3)));
}

#undef FLD
    }
    NEXT (vpc);

// ********** sub $rd,$rs,$rn

  CASE (INSN_SUB):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_add.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn)), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), SUBSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->thumb_h_gr_t_get (FLD (f_rn))));
}

#undef FLD
    }
    NEXT (vpc);

// ********** sub $rd,$rs,#$offset3

  CASE (INSN_SUBI):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), SUBSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), FLD (f_offset3)));
}

#undef FLD
    }
    NEXT (vpc);

// ********** mov ${bit10-rd},#$offset8

  CASE (INSN_MOV):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_mov.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), FLD (f_offset8));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** cmp ${bit10-rd},#$offset8

  CASE (INSN_CMP):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_mov.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
}

#undef FLD
    }
    NEXT (vpc);

// ********** add ${bit10-rd},#$offset8

  CASE (INSN_ADDI8):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_mov.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
current_cpu->hardware.h_vbit = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8)));
}

#undef FLD
    }
    NEXT (vpc);

// ********** sub ${bit10-rd},#$offset8

  CASE (INSN_SUBI8):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_mov.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), SUBSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)), FLD (f_offset8)));
}

#undef FLD
    }
    NEXT (vpc);

// ********** and $rd,$rs

  CASE (INSN_ALU_AND):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_rd), ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** eor $rd,$rs

  CASE (INSN_ALU_EOR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_rd), XORSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** lsl $rd,$rs

  CASE (INSN_ALU_LSL):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_LSL, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = SLLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
{
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** lsr $rd,$rs

  CASE (INSN_ALU_LSR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_LSR, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = SRLSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
{
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** asr $rd,$rs

  CASE (INSN_ALU_ASR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_ASR, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = SRASI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
{
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** ror $rd,$rs

  CASE (INSN_ALU_ROR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  BI tmp_carry_out;
  SI tmp_result;
  tmp_carry_out = current_cpu->compute_carry_out_regshift (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), SHIFT_TYPE_ROR, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
  tmp_result = RORSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
{
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = tmp_carry_out;
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** adc $rd,$rs

  CASE (INSN_ALU_ADC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
current_cpu->hardware.h_vbit = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), current_cpu->hardware.h_cbit);
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
}

#undef FLD
    }
    NEXT (vpc);

// ********** sbc $rd,$rs

  CASE (INSN_ALU_SBC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit));
{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit));
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit)));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), NOTBI (current_cpu->hardware.h_cbit));
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
}

#undef FLD
    }
    NEXT (vpc);

// ********** tst $rd,$rs

  CASE (INSN_ALU_TST):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_x;
  tmp_x = ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
{
current_cpu->hardware.h_zbit = EQSI (tmp_x, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_x, 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** neg $rd,$rs

  CASE (INSN_ALU_NEG):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = NEGSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
{
  SI tmp_result;
  tmp_result = SUBCSI (0, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (0, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0));
current_cpu->hardware.h_vbit = SUBOFSI (0, current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
}
current_cpu->thumb_h_gr_t_set (FLD (f_rd), tmp_result);
}

#undef FLD
    }
    NEXT (vpc);

// ********** cmp $rd,$rs

  CASE (INSN_ALU_CMP):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
}

#undef FLD
    }
    NEXT (vpc);

// ********** cmn $rd,$rs

  CASE (INSN_ALU_CMN):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = ADDCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = ADDCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
current_cpu->hardware.h_vbit = ADDOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
}

#undef FLD
    }
    NEXT (vpc);

// ********** orr $rd,$rs

  CASE (INSN_ALU_ORR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_rd), ORSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** mul $rd,$rs

  CASE (INSN_ALU_MUL):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_rd), MULSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** bic $rd,$rs

  CASE (INSN_ALU_BIC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_rd), ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), INVSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)))));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** mvn $rd,$rs

  CASE (INSN_ALU_MVN):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_gr_t_set (FLD (f_rd), INVSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
{
current_cpu->hardware.h_zbit = EQSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
current_cpu->hardware.h_nbit = LTSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), 0);
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** add $rd,$hs

  CASE (INSN_ADD_RD_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs))));

#undef FLD
    }
    NEXT (vpc);

// ********** add $hd,$rs

  CASE (INSN_ADD_HD_RS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (EQSI (FLD (f_rd), 7)) {
npc = ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs))); br_status = BRANCH_UNCACHEABLE;
} else {
current_cpu->thumb_h_hiregs_set (FLD (f_rd), ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs))));
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** add $hd,$hs

  CASE (INSN_ADD_HD_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (EQSI (FLD (f_rd), 7)) {
npc = ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs))); br_status = BRANCH_UNCACHEABLE;
} else {
current_cpu->thumb_h_hiregs_set (FLD (f_rd), ADDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs))));
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** cmp $rd,$hs

  CASE (INSN_CMP_RD_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_gr_t_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
}

#undef FLD
    }
    NEXT (vpc);

// ********** cmp $hd,$rs

  CASE (INSN_CMP_HD_RS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 0);
}

#undef FLD
    }
    NEXT (vpc);

// ********** cmp $hd,$hs

  CASE (INSN_CMP_HD_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_result;
  tmp_result = SUBCSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
{
current_cpu->hardware.h_zbit = EQSI (tmp_result, 0);
current_cpu->hardware.h_nbit = LTSI (tmp_result, 0);
}
current_cpu->hardware.h_cbit = NOTBI (SUBCFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0));
current_cpu->hardware.h_vbit = SUBOFSI (current_cpu->thumb_h_hiregs_get (FLD (f_rd)), current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 0);
}

#undef FLD
    }
    NEXT (vpc);

// ********** mov $rd,$hs

  CASE (INSN_MOV_RD_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), current_cpu->thumb_h_hiregs_get (FLD (f_rs)));

#undef FLD
    }
    NEXT (vpc);

// ********** mov $hd,$rs

  CASE (INSN_MOV_HD_RS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (EQSI (FLD (f_rd), 7)) {
npc = current_cpu->thumb_h_gr_t_get (FLD (f_rs)); br_status = BRANCH_UNCACHEABLE;
} else {
current_cpu->thumb_h_hiregs_set (FLD (f_rd), current_cpu->thumb_h_gr_t_get (FLD (f_rs)));
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** mov $hd,$hs

  CASE (INSN_MOV_HD_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (EQSI (FLD (f_rd), 7)) {
npc = current_cpu->thumb_h_hiregs_get (FLD (f_rs)); br_status = BRANCH_UNCACHEABLE;
} else {
current_cpu->thumb_h_hiregs_set (FLD (f_rd), current_cpu->thumb_h_hiregs_get (FLD (f_rs)));
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bx $rs

  CASE (INSN_BX_RS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
npc = current_cpu->thumb_h_gr_t_get (FLD (f_rs)); br_status = BRANCH_UNCACHEABLE;
if (NOTSI (ANDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rs)), 1))) {
current_cpu->h_tbit_set (0);
}
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bx $hs

  CASE (INSN_BX_HS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_addi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
npc = current_cpu->thumb_h_hiregs_get (FLD (f_rs)); br_status = BRANCH_UNCACHEABLE;
if (NOTSI (ANDSI (current_cpu->thumb_h_hiregs_get (FLD (f_rs)), 1))) {
current_cpu->h_tbit_set (0);
}
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** ldr ${bit10-rd},[pc,#$word8]

  CASE (INSN_LDR_PC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), current_cpu->GETMEMSI (pc, ADDSI (ANDSI (ADDSI (pc, 4), -4), FLD (f_word8))));

#undef FLD
    }
    NEXT (vpc);

// ********** str $rd,[$rb,$ro]

  CASE (INSN_STR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))), current_cpu->thumb_h_gr_t_get (FLD (f_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** strb $rd,[$rb,$ro]

  CASE (INSN_STRB):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))), current_cpu->thumb_h_gr_t_get (FLD (f_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** ldr $rd,[$rb,$ro]

  CASE (INSN_LDR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), current_cpu->GETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro)))));

#undef FLD
    }
    NEXT (vpc);

// ********** ldrb $rd,[$rb,$ro]

  CASE (INSN_LDRB):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))))));

#undef FLD
    }
    NEXT (vpc);

// ********** strh $rd,[$rb,$ro]

  CASE (INSN_STRH):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))), current_cpu->thumb_h_gr_t_get (FLD (f_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** ldrh $rd,[$rb,$ro]

  CASE (INSN_LDRH):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), ZEXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))))));

#undef FLD
    }
    NEXT (vpc);

// ********** ldsb $rd,[$rb,$ro]

  CASE (INSN_LDSB):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), EXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))))));

#undef FLD
    }
    NEXT (vpc);

// ********** ldsh $rd,[$rb,$ro]

  CASE (INSN_LDSH):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), EXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), current_cpu->thumb_h_gr_t_get (FLD (f_ro))))));

#undef FLD
    }
    NEXT (vpc);

// ********** str $rd,[$rb,#${offset5-7}]

  CASE (INSN_STR_IMM):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str_imm.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_7)), current_cpu->thumb_h_gr_t_get (FLD (f_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** ldr $rd,[$rb,#${offset5-7}]

  CASE (INSN_LDR_IMM):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_str_imm.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), current_cpu->GETMEMSI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_7))));

#undef FLD
    }
    NEXT (vpc);

// ********** strb $rd,[$rb,#$offset5]

  CASE (INSN_STRB_IMM):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_strb_imm.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5)), current_cpu->thumb_h_gr_t_get (FLD (f_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** ldrb $rd,[$rb,#$offset5]

  CASE (INSN_LDRB_IMM):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_strb_imm.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), ZEXTQISI (current_cpu->GETMEMQI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5)))));

#undef FLD
    }
    NEXT (vpc);

// ********** strh $rd,[$rb,#${offset5-6}]

  CASE (INSN_STRH_IMM):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_strh_imm.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_6)), current_cpu->thumb_h_gr_t_get (FLD (f_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** ldrh $rd,[$rb,#${offset5-6}]

  CASE (INSN_LDRH_IMM):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_strh_imm.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_rd), ZEXTHISI (current_cpu->GETMEMHI (pc, ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_rb)), FLD (f_offset5_6)))));

#undef FLD
    }
    NEXT (vpc);

// ********** str ${bit10-rd},[sp,#$word8]

  CASE (INSN_STR_SPREL):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->SETMEMSI (pc, ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8)), current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rd)));

#undef FLD
    }
    NEXT (vpc);

// ********** ldr ${bit10-rd},[sp,#$word8]

  CASE (INSN_LDR_SPREL):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), current_cpu->GETMEMSI (pc, ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8))));

#undef FLD
    }
    NEXT (vpc);

// ********** add ${bit10-rd},pc,$word8

  CASE (INSN_LDA_PC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), ADDSI (ANDSI (ADDSI (pc, 4), -4), FLD (f_word8)));

#undef FLD
    }
    NEXT (vpc);

// ********** add ${bit10-rd},sp,$word8

  CASE (INSN_LDA_SP):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_ldr_pc.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rd), ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_word8)));

#undef FLD
    }
    NEXT (vpc);

// ********** add sp,#$sword7

  CASE (INSN_ADD_SP):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_add_sp.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), FLD (f_sword7)));

#undef FLD
    }
    NEXT (vpc);

// ********** add sp,#-$sword7

  CASE (INSN_SUB_SP):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_add_sp.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), FLD (f_sword7)));

#undef FLD
    }
    NEXT (vpc);

// ********** push {$rlist}

  CASE (INSN_PUSH):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_stmia.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 7)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 6)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 5)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 4)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 3)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 2)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 1)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 0)));
}
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** push {${rlist-lr}}

  CASE (INSN_PUSH_LR):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_stmia.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_lr_t_get ());
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 7)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 6)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 5)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 4)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 3)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 2)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 1)));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
current_cpu->thumb_h_sp_t_set (SUBSI (current_cpu->thumb_h_sp_t_get (), 4));
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_sp_t_get (), current_cpu->thumb_h_gr_t_get (((UINT) 0)));
}
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** pop {$rlist}

  CASE (INSN_POP):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_stmia.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 0), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 1), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 2), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 3), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 4), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 5), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 6), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 7), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** pop {${rlist-pc}}

  CASE (INSN_POP_PC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_stmia.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 0), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 1), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 2), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 3), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 4), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 5), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 6), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 7), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()));
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}
}
npc = current_cpu->GETMEMSI (pc, current_cpu->thumb_h_sp_t_get ()); br_status = BRANCH_UNCACHEABLE;
current_cpu->thumb_h_sp_t_set (ADDSI (current_cpu->thumb_h_sp_t_get (), 4));
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** stmia $rb!,{$rlist}

  CASE (INSN_STMIA):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_stmia.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 0)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 1)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 2)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 3)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 4)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 5)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 6)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
current_cpu->SETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), current_cpu->thumb_h_gr_t_get (((UINT) 7)));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** ldmia $rb!,{$rlist}

  CASE (INSN_LDMIA):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_stmia.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
if (ANDSI (FLD (f_rlist), SLLSI (1, 0))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 0), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 1))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 1), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 2))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 2), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 3))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 3), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 4))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 4), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 5))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 5), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 6))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 6), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
if (ANDSI (FLD (f_rlist), SLLSI (1, 7))) {
{
current_cpu->thumb_h_gr_t_set (((UINT) 7), current_cpu->GETMEMSI (pc, current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb))));
current_cpu->thumb_h_gr_t_set (FLD (f_bit10_rb), ADDSI (current_cpu->thumb_h_gr_t_get (FLD (f_bit10_rb)), 4));
}
}
}

#undef FLD
    }
    NEXT (vpc);

// ********** beq $soffset8

  CASE (INSN_BEQ):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (current_cpu->hardware.h_zbit) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bne $soffset8

  CASE (INSN_BNE):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (NOTBI (current_cpu->hardware.h_zbit)) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bcs $soffset8

  CASE (INSN_BCS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (current_cpu->hardware.h_cbit) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bcc $soffset8

  CASE (INSN_BCC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (NOTBI (current_cpu->hardware.h_cbit)) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bmi $soffset8

  CASE (INSN_BMI):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (current_cpu->hardware.h_nbit) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bpl $soffset8

  CASE (INSN_BPL):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (NOTBI (current_cpu->hardware.h_nbit)) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bvs $soffset8

  CASE (INSN_BVS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (current_cpu->hardware.h_vbit) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bvc $soffset8

  CASE (INSN_BVC):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (NOTBI (current_cpu->hardware.h_vbit)) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bhi $soffset8

  CASE (INSN_BHI):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (ANDBI (current_cpu->hardware.h_cbit, NOTBI (current_cpu->hardware.h_zbit))) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bls $soffset8

  CASE (INSN_BLS):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (ORBI (NOTBI (current_cpu->hardware.h_cbit), current_cpu->hardware.h_zbit)) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bge $soffset8

  CASE (INSN_BGE):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (NOTBI (XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit))) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** blt $soffset8

  CASE (INSN_BLT):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit)) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bgt $soffset8

  CASE (INSN_BGT):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (NOTBI (ORBI (current_cpu->hardware.h_zbit, XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit)))) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** ble $soffset8

  CASE (INSN_BLE):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_beq.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

if (ORBI (current_cpu->hardware.h_zbit, XORBI (current_cpu->hardware.h_nbit, current_cpu->hardware.h_vbit))) {
npc = FLD (i_soffset8); br_status = BRANCH_CACHEABLE;
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** swi $value8

  CASE (INSN_SWI):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_swi.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

npc = current_cpu->thumb_swi (pc, FLD (f_value8)); br_status = BRANCH_UNCACHEABLE;

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** b $offset11

  CASE (INSN_B):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_b.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

npc = FLD (i_offset11); br_status = BRANCH_CACHEABLE;

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);

// ********** bl-hi ${lbwl-hi}

  CASE (INSN_BL_HI):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_bl_hi.f
      PCADDR pc = abuf->addr;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

current_cpu->thumb_h_lr_t_set (ADDSI (ADDSI (pc, 4), SLLSI (FLD (f_lbwl_hi), 12)));

#undef FLD
    }
    NEXT (vpc);

// ********** bl-lo ${lbwl-lo}

  CASE (INSN_BL_LO):
    {
      thumb_scache* abuf = vpc;
#define FLD(f) abuf->fields.sfmt_bl_lo.f
      PCADDR pc = abuf->addr;
      PCADDR npc;
      branch_status br_status = BRANCH_UNTAKEN;
      vpc = vpc + 1;
      current_cpu->hardware.h_gr[((UINT) 15)] = ADDSI (pc, 4);

{
  SI tmp_cur_pc;
  tmp_cur_pc = pc;
npc = ADDSI (current_cpu->thumb_h_lr_t_get (), SLLSI (FLD (f_lbwl_lo), 1)); br_status = BRANCH_UNCACHEABLE;
current_cpu->thumb_h_lr_t_set (ORSI (ADDSI (tmp_cur_pc, 2), 1));
}

      pbb_br_npc = npc;
      pbb_br_status = br_status;
#undef FLD
    }
    NEXT (vpc);


#ifdef __GNUC__
    end_switch: ;
#else
    default: abort();
#endif
  }

  // Save vpc for next time.
  current_cpu->thumb_engine.set_next_vpc (vpc);
}

