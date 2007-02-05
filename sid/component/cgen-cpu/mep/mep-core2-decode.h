/* Decode header for mepcore2.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCORE2_DECODE_H
#define MEPCORE2_DECODE_H

namespace mep_ext2 {

using namespace cgen;
using namespace mep;

typedef UINT mepcore2_insn_word;

/* Enum declaration for instructions in cpu family mepcore2.  */
typedef enum mepcore2_insn_type {
  MEPCORE2_INSN_X_INVALID, MEPCORE2_INSN_SB, MEPCORE2_INSN_SH, MEPCORE2_INSN_SW
 , MEPCORE2_INSN_LB, MEPCORE2_INSN_LH, MEPCORE2_INSN_LW, MEPCORE2_INSN_LBU
 , MEPCORE2_INSN_LHU, MEPCORE2_INSN_SW_SP, MEPCORE2_INSN_LW_SP, MEPCORE2_INSN_SB_TP
 , MEPCORE2_INSN_SH_TP, MEPCORE2_INSN_SW_TP, MEPCORE2_INSN_LB_TP, MEPCORE2_INSN_LH_TP
 , MEPCORE2_INSN_LW_TP, MEPCORE2_INSN_LBU_TP, MEPCORE2_INSN_LHU_TP, MEPCORE2_INSN_SB16
 , MEPCORE2_INSN_SH16, MEPCORE2_INSN_SW16, MEPCORE2_INSN_LB16, MEPCORE2_INSN_LH16
 , MEPCORE2_INSN_LW16, MEPCORE2_INSN_LBU16, MEPCORE2_INSN_LHU16, MEPCORE2_INSN_SW24
 , MEPCORE2_INSN_LW24, MEPCORE2_INSN_EXTB, MEPCORE2_INSN_EXTH, MEPCORE2_INSN_EXTUB
 , MEPCORE2_INSN_EXTUH, MEPCORE2_INSN_SSARB, MEPCORE2_INSN_MOV, MEPCORE2_INSN_MOVI8
 , MEPCORE2_INSN_MOVI16, MEPCORE2_INSN_MOVU24, MEPCORE2_INSN_MOVU16, MEPCORE2_INSN_MOVH
 , MEPCORE2_INSN_ADD3, MEPCORE2_INSN_ADD, MEPCORE2_INSN_ADD3I, MEPCORE2_INSN_ADVCK3
 , MEPCORE2_INSN_SUB, MEPCORE2_INSN_SBVCK3, MEPCORE2_INSN_NEG, MEPCORE2_INSN_SLT3
 , MEPCORE2_INSN_SLTU3, MEPCORE2_INSN_SLT3I, MEPCORE2_INSN_SLTU3I, MEPCORE2_INSN_SL1AD3
 , MEPCORE2_INSN_SL2AD3, MEPCORE2_INSN_ADD3X, MEPCORE2_INSN_SLT3X, MEPCORE2_INSN_SLTU3X
 , MEPCORE2_INSN_OR, MEPCORE2_INSN_AND, MEPCORE2_INSN_XOR, MEPCORE2_INSN_NOR
 , MEPCORE2_INSN_OR3, MEPCORE2_INSN_AND3, MEPCORE2_INSN_XOR3, MEPCORE2_INSN_SRA
 , MEPCORE2_INSN_SRL, MEPCORE2_INSN_SLL, MEPCORE2_INSN_SRAI, MEPCORE2_INSN_SRLI
 , MEPCORE2_INSN_SLLI, MEPCORE2_INSN_SLL3, MEPCORE2_INSN_FSFT, MEPCORE2_INSN_BRA
 , MEPCORE2_INSN_BEQZ, MEPCORE2_INSN_BNEZ, MEPCORE2_INSN_BEQI, MEPCORE2_INSN_BNEI
 , MEPCORE2_INSN_BLTI, MEPCORE2_INSN_BGEI, MEPCORE2_INSN_BEQ, MEPCORE2_INSN_BNE
 , MEPCORE2_INSN_BSR12, MEPCORE2_INSN_BSR24, MEPCORE2_INSN_JMP, MEPCORE2_INSN_JMP24
 , MEPCORE2_INSN_JSR, MEPCORE2_INSN_RET, MEPCORE2_INSN_REPEAT, MEPCORE2_INSN_EREPEAT
 , MEPCORE2_INSN_STC_LP, MEPCORE2_INSN_STC_HI, MEPCORE2_INSN_STC_LO, MEPCORE2_INSN_STC
 , MEPCORE2_INSN_LDC_LP, MEPCORE2_INSN_LDC_HI, MEPCORE2_INSN_LDC_LO, MEPCORE2_INSN_LDC
 , MEPCORE2_INSN_DI, MEPCORE2_INSN_EI, MEPCORE2_INSN_RETI, MEPCORE2_INSN_HALT
 , MEPCORE2_INSN_SLEEP, MEPCORE2_INSN_SWI, MEPCORE2_INSN_BREAK, MEPCORE2_INSN_SYNCM
 , MEPCORE2_INSN_STCB, MEPCORE2_INSN_LDCB, MEPCORE2_INSN_BSETM, MEPCORE2_INSN_BCLRM
 , MEPCORE2_INSN_BNOTM, MEPCORE2_INSN_BTSTM, MEPCORE2_INSN_TAS, MEPCORE2_INSN_CACHE
 , MEPCORE2_INSN_MUL, MEPCORE2_INSN_MULU, MEPCORE2_INSN_MULR, MEPCORE2_INSN_MULRU
 , MEPCORE2_INSN_MADD, MEPCORE2_INSN_MADDU, MEPCORE2_INSN_MADDR, MEPCORE2_INSN_MADDRU
 , MEPCORE2_INSN_DIV, MEPCORE2_INSN_DIVU, MEPCORE2_INSN_DRET, MEPCORE2_INSN_DBREAK
 , MEPCORE2_INSN_LDZ, MEPCORE2_INSN_ABS, MEPCORE2_INSN_AVE, MEPCORE2_INSN_MIN
 , MEPCORE2_INSN_MAX, MEPCORE2_INSN_MINU, MEPCORE2_INSN_MAXU, MEPCORE2_INSN_CLIP
 , MEPCORE2_INSN_CLIPU, MEPCORE2_INSN_SADD, MEPCORE2_INSN_SSUB, MEPCORE2_INSN_SADDU
 , MEPCORE2_INSN_SSUBU, MEPCORE2_INSN_SWCP, MEPCORE2_INSN_LWCP, MEPCORE2_INSN_SMCP
 , MEPCORE2_INSN_LMCP, MEPCORE2_INSN_SWCPI, MEPCORE2_INSN_LWCPI, MEPCORE2_INSN_SMCPI
 , MEPCORE2_INSN_LMCPI, MEPCORE2_INSN_SWCP16, MEPCORE2_INSN_LWCP16, MEPCORE2_INSN_SMCP16
 , MEPCORE2_INSN_LMCP16, MEPCORE2_INSN_SBCPA, MEPCORE2_INSN_LBCPA, MEPCORE2_INSN_SHCPA
 , MEPCORE2_INSN_LHCPA, MEPCORE2_INSN_SWCPA, MEPCORE2_INSN_LWCPA, MEPCORE2_INSN_SMCPA
 , MEPCORE2_INSN_LMCPA, MEPCORE2_INSN_SBCPM0, MEPCORE2_INSN_LBCPM0, MEPCORE2_INSN_SHCPM0
 , MEPCORE2_INSN_LHCPM0, MEPCORE2_INSN_SWCPM0, MEPCORE2_INSN_LWCPM0, MEPCORE2_INSN_SMCPM0
 , MEPCORE2_INSN_LMCPM0, MEPCORE2_INSN_SBCPM1, MEPCORE2_INSN_LBCPM1, MEPCORE2_INSN_SHCPM1
 , MEPCORE2_INSN_LHCPM1, MEPCORE2_INSN_SWCPM1, MEPCORE2_INSN_LWCPM1, MEPCORE2_INSN_SMCPM1
 , MEPCORE2_INSN_LMCPM1, MEPCORE2_INSN_BCPEQ, MEPCORE2_INSN_BCPNE, MEPCORE2_INSN_BCPAT
 , MEPCORE2_INSN_BCPAF, MEPCORE2_INSN_SYNCCP, MEPCORE2_INSN_JSRV, MEPCORE2_INSN_BSRV
 , MEPCORE2_INSN_SIM_SYSCALL, MEPCORE2_INSN_RI_0, MEPCORE2_INSN_RI_1, MEPCORE2_INSN_RI_2
 , MEPCORE2_INSN_RI_3, MEPCORE2_INSN_RI_4, MEPCORE2_INSN_RI_5, MEPCORE2_INSN_RI_6
 , MEPCORE2_INSN_RI_7, MEPCORE2_INSN_RI_8, MEPCORE2_INSN_RI_9, MEPCORE2_INSN_RI_10
 , MEPCORE2_INSN_RI_11, MEPCORE2_INSN_RI_12, MEPCORE2_INSN_RI_13, MEPCORE2_INSN_RI_14
 , MEPCORE2_INSN_RI_15, MEPCORE2_INSN_RI_17, MEPCORE2_INSN_RI_20, MEPCORE2_INSN_RI_21
 , MEPCORE2_INSN_RI_22, MEPCORE2_INSN_RI_23, MEPCORE2_INSN_RI_24, MEPCORE2_INSN_RI_25
 , MEPCORE2_INSN_RI_26, MEPCORE2_INSN_RI_16, MEPCORE2_INSN_RI_18, MEPCORE2_INSN_RI_19
 , MEPCORE2_INSN_FADDS, MEPCORE2_INSN_FSUBS, MEPCORE2_INSN_FMULS, MEPCORE2_INSN_FDIVS
 , MEPCORE2_INSN_FSQRTS, MEPCORE2_INSN_FABSS, MEPCORE2_INSN_FNEGS, MEPCORE2_INSN_FMOVS
 , MEPCORE2_INSN_FROUNDWS, MEPCORE2_INSN_FTRUNCWS, MEPCORE2_INSN_FCEILWS, MEPCORE2_INSN_FFLOORWS
 , MEPCORE2_INSN_FCVTWS, MEPCORE2_INSN_FCVTSW, MEPCORE2_INSN_FCMPFS, MEPCORE2_INSN_FCMPUS
 , MEPCORE2_INSN_FCMPES, MEPCORE2_INSN_FCMPUES, MEPCORE2_INSN_FCMPLS, MEPCORE2_INSN_FCMPULS
 , MEPCORE2_INSN_FCMPLES, MEPCORE2_INSN_FCMPULES, MEPCORE2_INSN_FCMPFIS, MEPCORE2_INSN_FCMPUIS
 , MEPCORE2_INSN_FCMPEIS, MEPCORE2_INSN_FCMPUEIS, MEPCORE2_INSN_FCMPLIS, MEPCORE2_INSN_FCMPULIS
 , MEPCORE2_INSN_FCMPLEIS, MEPCORE2_INSN_FCMPULEIS, MEPCORE2_INSN_CMOV_FRN_RM, MEPCORE2_INSN_CMOV_RM_FRN
 , MEPCORE2_INSN_CMOVC_CCRN_RM, MEPCORE2_INSN_CMOVC_RM_CCRN
} MEPCORE2_INSN_TYPE;


// Forward decls.
struct mep_ext2_cpu;
struct mepcore2_scache;
typedef sem_status (mepcore2_sem_fn) (mep_ext2_cpu* cpu, mepcore2_scache* sem);


// Instruction descriptor.

struct mepcore2_idesc {

  // scache engine executor for this insn
  mepcore2_sem_fn* execute;

  const char* insn_name;
  enum mepcore2_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mepcore2_idesc idesc_table[];

  static mepcore2_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mepcore2_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_callnum;
  } sfmt_sim_syscall;
  struct { /*  */
    unsigned char in_psw;
    unsigned char out_psw;
  } sfmt_di;
  struct { /*  */
    UINT f_fmax_frd;
    UINT f_fmax_frm;
    UINT f_fmax_frn;
  } sfmt_fadds;
  struct { /*  */
    unsigned char in_dbg;
    unsigned char in_depc;
    unsigned char out_dbg;
  } sfmt_dret;
  struct { /*  */
    UINT f_2u10;
    unsigned char in_exc;
    unsigned char out_exc;
  } sfmt_swi;
  struct { /*  */
    unsigned char in_lp;
    unsigned char in_opt;
    unsigned char in_psw;
  } sfmt_ret;
  struct { /*  */
    UINT f_24u5a2n;
    unsigned char in_opt;
    unsigned char in_psw;
  } sfmt_jmp24;
  struct { /*  */
    SI* i_fmax_Rm;
    UINT f_fmax_4_4;
    UINT f_fmax_rm;
    unsigned char out_fmax_Rm;
  } sfmt_cmovc_rm_ccrn;
  struct { /*  */
    SI* i_fmax_Rm;
    UINT f_fmax_4_4;
    UINT f_fmax_rm;
    unsigned char in_fmax_Rm;
  } sfmt_cmovc_ccrn_rm;
  struct { /*  */
    SI* i_fmax_Rm;
    UINT f_fmax_frd;
    UINT f_fmax_rm;
    unsigned char out_fmax_Rm;
  } sfmt_cmov_rm_frn;
  struct { /*  */
    SI* i_fmax_Rm;
    UINT f_fmax_frd;
    UINT f_fmax_rm;
    unsigned char in_fmax_Rm;
  } sfmt_cmov_frn_rm;
  struct { /*  */
    SI* i_rn;
    UINT f_16u16;
    UINT f_rn;
    unsigned char in_rn;
  } sfmt_stcb;
  struct { /*  */
    unsigned char in_epc;
    unsigned char in_npc;
    unsigned char in_opt;
    unsigned char in_psw;
  } sfmt_reti;
  struct { /*  */
    SI* i_rn;
    UINT f_rn;
    unsigned char in_lp;
    unsigned char out_rn;
  } sfmt_ldc_lp;
  struct { /*  */
    SI* i_rn;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_lp;
  } sfmt_stc_lp;
  struct { /*  */
    INT f_24s5a2n;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char out_lp;
  } sfmt_bsr24;
  struct { /*  */
    SI f_12s4a2;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char out_lp;
  } sfmt_bsr12;
  struct { /*  */
    SI* i_rn3;
    UINT f_24u8n;
    UINT f_rn3;
    unsigned char out_rn3;
  } sfmt_movu24;
  struct { /*  */
    SI* i_rn;
    INT f_8s8;
    UINT f_rn;
    unsigned char out_rn;
  } sfmt_movi8;
  struct { /*  */
    SI* i_rnl;
    UINT f_24u8a4n;
    UINT f_rn;
    unsigned char out_rnl;
  } sfmt_lw24;
  struct { /*  */
    SI* i_rnl;
    UINT f_24u8a4n;
    UINT f_rn;
    unsigned char in_rnl;
  } sfmt_sw24;
  struct { /*  */
    SI* i_rma;
    INT f_16s16;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_rma;
  } sfmt_swcp16;
  struct { /*  */
    SI* i_rn;
    UINT f_5u24;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_clip;
  struct { /*  */
    SI* i_rma;
    UINT f_3u5;
    UINT f_rm;
    unsigned char in_rma;
    unsigned char out_r0;
  } sfmt_btstm;
  struct { /*  */
    SI* i_rn;
    UINT f_csrn;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_csrn;
  } sfmt_stc;
  struct { /*  */
    SI* i_rn;
    UINT f_5u8;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_srai;
  struct { /*  */
    SI* i_rn;
    UINT f_5u8;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_r0;
  } sfmt_slt3i;
  struct { /*  */
    SI* i_rn;
    SI f_7u9a4;
    UINT f_rn;
    unsigned char in_sp;
    unsigned char out_rn;
  } sfmt_add3i;
  struct { /*  */
    SI* i_rn;
    INT f_6s8;
    UINT f_rn;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_add;
  struct { /*  */
    SI* i_rm;
    UINT f_2u6;
    UINT f_rm;
    unsigned char in_rm;
    unsigned char out_sar;
  } sfmt_ssarb;
  struct { /*  */
    SI* i_rn3us;
    SI f_7u9a2;
    UINT f_rn3;
    unsigned char in_tp;
    unsigned char out_rn3us;
  } sfmt_lhu_tp;
  struct { /*  */
    SI* i_rn3uc;
    UINT f_7u9;
    UINT f_rn3;
    unsigned char in_tp;
    unsigned char out_rn3uc;
  } sfmt_lbu_tp;
  struct { /*  */
    SI* i_rn3l;
    SI f_7u9a4;
    UINT f_rn3;
    unsigned char in_tp;
    unsigned char out_rn3l;
  } sfmt_lw_tp;
  struct { /*  */
    SI* i_rn3s;
    SI f_7u9a2;
    UINT f_rn3;
    unsigned char in_tp;
    unsigned char out_rn3s;
  } sfmt_lh_tp;
  struct { /*  */
    SI* i_rn3c;
    UINT f_7u9;
    UINT f_rn3;
    unsigned char in_tp;
    unsigned char out_rn3c;
  } sfmt_lb_tp;
  struct { /*  */
    SI* i_rn3l;
    SI f_7u9a4;
    UINT f_rn3;
    unsigned char in_rn3l;
    unsigned char in_tp;
  } sfmt_sw_tp;
  struct { /*  */
    SI* i_rn3s;
    SI f_7u9a2;
    UINT f_rn3;
    unsigned char in_rn3s;
    unsigned char in_tp;
  } sfmt_sh_tp;
  struct { /*  */
    SI* i_rn3c;
    UINT f_7u9;
    UINT f_rn3;
    unsigned char in_rn3c;
    unsigned char in_tp;
  } sfmt_sb_tp;
  struct { /*  */
    SI* i_rnl;
    SI f_7u9a4;
    UINT f_rn;
    unsigned char in_sp;
    unsigned char out_rnl;
  } sfmt_lw_sp;
  struct { /*  */
    SI* i_rnl;
    SI f_7u9a4;
    UINT f_rn;
    unsigned char in_rnl;
    unsigned char in_sp;
  } sfmt_sw_sp;
  struct { /*  */
    SI* i_rma;
    SI* i_rn;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rn;
  } sfmt_tas;
  struct { /*  */
    SI* i_rm;
    UINT f_rm;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char in_rm;
    unsigned char out_lp;
  } sfmt_jsr;
  struct { /*  */
    SI* i_rn;
    SI f_8s8a2;
    UINT f_rn;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char in_rn;
  } sfmt_beqz;
  struct { /*  */
    SI* i_rn;
    UINT f_csrn;
    UINT f_rn;
    unsigned char in_csrn;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char out_rn;
  } sfmt_ldc;
  struct { /*  */
    SI* i_rn;
    SI f_17s16a2;
    UINT f_4u8;
    UINT f_rn;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char in_rn;
  } sfmt_beqi;
  struct { /*  */
    SI* i_rm;
    SI* i_rn;
    UINT f_16u16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char out_rn;
  } sfmt_sltu3x;
  struct { /*  */
    SI* i_rm;
    SI* i_rn;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char out_rn;
  } sfmt_add3x;
  struct { /*  */
    SI* i_rm;
    SI* i_rn;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_r0;
  } sfmt_advck3;
  struct { /*  */
    SI* i_rma;
    SI* i_rnus;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rnus;
  } sfmt_lhu16;
  struct { /*  */
    SI* i_rma;
    SI* i_rnuc;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rnuc;
  } sfmt_lbu16;
  struct { /*  */
    SI* i_rma;
    SI* i_rnl;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rnl;
  } sfmt_lw16;
  struct { /*  */
    SI* i_rma;
    SI* i_rns;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rns;
  } sfmt_lh16;
  struct { /*  */
    SI* i_rma;
    SI* i_rnc;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rnc;
  } sfmt_lb16;
  struct { /*  */
    SI* i_rma;
    SI* i_rnl;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char in_rnl;
  } sfmt_sw16;
  struct { /*  */
    SI* i_rma;
    SI* i_rns;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char in_rns;
  } sfmt_sh16;
  struct { /*  */
    SI* i_rma;
    SI* i_rnc;
    INT f_16s16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char in_rnc;
  } sfmt_sb16;
  struct { /*  */
    SI* i_rma;
    SI f_8s24a8;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb1;
    unsigned char in_me1;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_smcpm1;
  struct { /*  */
    SI* i_rma;
    SI f_8s24a4;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb1;
    unsigned char in_me1;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_swcpm1;
  struct { /*  */
    SI* i_rma;
    SI f_8s24a2;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb1;
    unsigned char in_me1;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_shcpm1;
  struct { /*  */
    SI* i_rma;
    INT f_8s24;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb1;
    unsigned char in_me1;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_sbcpm1;
  struct { /*  */
    SI* i_rma;
    SI f_8s24a8;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb0;
    unsigned char in_me0;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_smcpm0;
  struct { /*  */
    SI* i_rma;
    SI f_8s24a4;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb0;
    unsigned char in_me0;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_swcpm0;
  struct { /*  */
    SI* i_rma;
    SI f_8s24a2;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb0;
    unsigned char in_me0;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_shcpm0;
  struct { /*  */
    SI* i_rma;
    INT f_8s24;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb0;
    unsigned char in_me0;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_sbcpm0;
  struct { /*  */
    SI* i_rm;
    SI* i_rn;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char in_sar;
    unsigned char out_rn;
  } sfmt_fsft;
  struct { /*  */
    SI* i_rn;
    SI f_17s16a2;
    UINT f_rn;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char in_rn;
    unsigned char out_h_csr_SI_4;
    unsigned char out_h_csr_SI_5;
    unsigned char out_h_csr_SI_6;
  } sfmt_repeat;
  struct { /*  */
    SI* i_rm;
    SI* i_rn;
    SI f_17s16a2;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_opt;
    unsigned char in_psw;
    unsigned char in_rm;
    unsigned char in_rn;
  } sfmt_beq;
  struct { /*  */
    SI* i_rl;
    SI* i_rm;
    SI* i_rn;
    UINT f_rl;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_rl;
  } sfmt_add3;
  struct { /*  */
    SI* i_rm;
    SI* i_rn;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_hi;
    unsigned char in_lo;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_hi;
    unsigned char out_lo;
    unsigned char out_rn;
  } sfmt_maddr;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    mepcore2_scache* next;
    mepcore2_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mepcore2_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mepcore2_scache {
  // executor
  union {
    cgoto_label cgoto;
    mepcore2_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mepcore2_idesc* idesc;

  // argument buffer
  mepcore2_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_ext2_cpu* current_cpu, PCADDR pc, mepcore2_insn_word base_insn, mepcore2_insn_word entire_insn);
};

} // end mep_ext2 namespace

// Decls of each semantic fn.

using mep_ext2::mepcore2_sem_fn;
extern mepcore2_sem_fn mepcore2_sem_x_invalid;
extern mepcore2_sem_fn mepcore2_sem_sb;
extern mepcore2_sem_fn mepcore2_sem_sh;
extern mepcore2_sem_fn mepcore2_sem_sw;
extern mepcore2_sem_fn mepcore2_sem_lb;
extern mepcore2_sem_fn mepcore2_sem_lh;
extern mepcore2_sem_fn mepcore2_sem_lw;
extern mepcore2_sem_fn mepcore2_sem_lbu;
extern mepcore2_sem_fn mepcore2_sem_lhu;
extern mepcore2_sem_fn mepcore2_sem_sw_sp;
extern mepcore2_sem_fn mepcore2_sem_lw_sp;
extern mepcore2_sem_fn mepcore2_sem_sb_tp;
extern mepcore2_sem_fn mepcore2_sem_sh_tp;
extern mepcore2_sem_fn mepcore2_sem_sw_tp;
extern mepcore2_sem_fn mepcore2_sem_lb_tp;
extern mepcore2_sem_fn mepcore2_sem_lh_tp;
extern mepcore2_sem_fn mepcore2_sem_lw_tp;
extern mepcore2_sem_fn mepcore2_sem_lbu_tp;
extern mepcore2_sem_fn mepcore2_sem_lhu_tp;
extern mepcore2_sem_fn mepcore2_sem_sb16;
extern mepcore2_sem_fn mepcore2_sem_sh16;
extern mepcore2_sem_fn mepcore2_sem_sw16;
extern mepcore2_sem_fn mepcore2_sem_lb16;
extern mepcore2_sem_fn mepcore2_sem_lh16;
extern mepcore2_sem_fn mepcore2_sem_lw16;
extern mepcore2_sem_fn mepcore2_sem_lbu16;
extern mepcore2_sem_fn mepcore2_sem_lhu16;
extern mepcore2_sem_fn mepcore2_sem_sw24;
extern mepcore2_sem_fn mepcore2_sem_lw24;
extern mepcore2_sem_fn mepcore2_sem_extb;
extern mepcore2_sem_fn mepcore2_sem_exth;
extern mepcore2_sem_fn mepcore2_sem_extub;
extern mepcore2_sem_fn mepcore2_sem_extuh;
extern mepcore2_sem_fn mepcore2_sem_ssarb;
extern mepcore2_sem_fn mepcore2_sem_mov;
extern mepcore2_sem_fn mepcore2_sem_movi8;
extern mepcore2_sem_fn mepcore2_sem_movi16;
extern mepcore2_sem_fn mepcore2_sem_movu24;
extern mepcore2_sem_fn mepcore2_sem_movu16;
extern mepcore2_sem_fn mepcore2_sem_movh;
extern mepcore2_sem_fn mepcore2_sem_add3;
extern mepcore2_sem_fn mepcore2_sem_add;
extern mepcore2_sem_fn mepcore2_sem_add3i;
extern mepcore2_sem_fn mepcore2_sem_advck3;
extern mepcore2_sem_fn mepcore2_sem_sub;
extern mepcore2_sem_fn mepcore2_sem_sbvck3;
extern mepcore2_sem_fn mepcore2_sem_neg;
extern mepcore2_sem_fn mepcore2_sem_slt3;
extern mepcore2_sem_fn mepcore2_sem_sltu3;
extern mepcore2_sem_fn mepcore2_sem_slt3i;
extern mepcore2_sem_fn mepcore2_sem_sltu3i;
extern mepcore2_sem_fn mepcore2_sem_sl1ad3;
extern mepcore2_sem_fn mepcore2_sem_sl2ad3;
extern mepcore2_sem_fn mepcore2_sem_add3x;
extern mepcore2_sem_fn mepcore2_sem_slt3x;
extern mepcore2_sem_fn mepcore2_sem_sltu3x;
extern mepcore2_sem_fn mepcore2_sem_or;
extern mepcore2_sem_fn mepcore2_sem_and;
extern mepcore2_sem_fn mepcore2_sem_xor;
extern mepcore2_sem_fn mepcore2_sem_nor;
extern mepcore2_sem_fn mepcore2_sem_or3;
extern mepcore2_sem_fn mepcore2_sem_and3;
extern mepcore2_sem_fn mepcore2_sem_xor3;
extern mepcore2_sem_fn mepcore2_sem_sra;
extern mepcore2_sem_fn mepcore2_sem_srl;
extern mepcore2_sem_fn mepcore2_sem_sll;
extern mepcore2_sem_fn mepcore2_sem_srai;
extern mepcore2_sem_fn mepcore2_sem_srli;
extern mepcore2_sem_fn mepcore2_sem_slli;
extern mepcore2_sem_fn mepcore2_sem_sll3;
extern mepcore2_sem_fn mepcore2_sem_fsft;
extern mepcore2_sem_fn mepcore2_sem_bra;
extern mepcore2_sem_fn mepcore2_sem_beqz;
extern mepcore2_sem_fn mepcore2_sem_bnez;
extern mepcore2_sem_fn mepcore2_sem_beqi;
extern mepcore2_sem_fn mepcore2_sem_bnei;
extern mepcore2_sem_fn mepcore2_sem_blti;
extern mepcore2_sem_fn mepcore2_sem_bgei;
extern mepcore2_sem_fn mepcore2_sem_beq;
extern mepcore2_sem_fn mepcore2_sem_bne;
extern mepcore2_sem_fn mepcore2_sem_bsr12;
extern mepcore2_sem_fn mepcore2_sem_bsr24;
extern mepcore2_sem_fn mepcore2_sem_jmp;
extern mepcore2_sem_fn mepcore2_sem_jmp24;
extern mepcore2_sem_fn mepcore2_sem_jsr;
extern mepcore2_sem_fn mepcore2_sem_ret;
extern mepcore2_sem_fn mepcore2_sem_repeat;
extern mepcore2_sem_fn mepcore2_sem_erepeat;
extern mepcore2_sem_fn mepcore2_sem_stc_lp;
extern mepcore2_sem_fn mepcore2_sem_stc_hi;
extern mepcore2_sem_fn mepcore2_sem_stc_lo;
extern mepcore2_sem_fn mepcore2_sem_stc;
extern mepcore2_sem_fn mepcore2_sem_ldc_lp;
extern mepcore2_sem_fn mepcore2_sem_ldc_hi;
extern mepcore2_sem_fn mepcore2_sem_ldc_lo;
extern mepcore2_sem_fn mepcore2_sem_ldc;
extern mepcore2_sem_fn mepcore2_sem_di;
extern mepcore2_sem_fn mepcore2_sem_ei;
extern mepcore2_sem_fn mepcore2_sem_reti;
extern mepcore2_sem_fn mepcore2_sem_halt;
extern mepcore2_sem_fn mepcore2_sem_sleep;
extern mepcore2_sem_fn mepcore2_sem_swi;
extern mepcore2_sem_fn mepcore2_sem_break;
extern mepcore2_sem_fn mepcore2_sem_syncm;
extern mepcore2_sem_fn mepcore2_sem_stcb;
extern mepcore2_sem_fn mepcore2_sem_ldcb;
extern mepcore2_sem_fn mepcore2_sem_bsetm;
extern mepcore2_sem_fn mepcore2_sem_bclrm;
extern mepcore2_sem_fn mepcore2_sem_bnotm;
extern mepcore2_sem_fn mepcore2_sem_btstm;
extern mepcore2_sem_fn mepcore2_sem_tas;
extern mepcore2_sem_fn mepcore2_sem_cache;
extern mepcore2_sem_fn mepcore2_sem_mul;
extern mepcore2_sem_fn mepcore2_sem_mulu;
extern mepcore2_sem_fn mepcore2_sem_mulr;
extern mepcore2_sem_fn mepcore2_sem_mulru;
extern mepcore2_sem_fn mepcore2_sem_madd;
extern mepcore2_sem_fn mepcore2_sem_maddu;
extern mepcore2_sem_fn mepcore2_sem_maddr;
extern mepcore2_sem_fn mepcore2_sem_maddru;
extern mepcore2_sem_fn mepcore2_sem_div;
extern mepcore2_sem_fn mepcore2_sem_divu;
extern mepcore2_sem_fn mepcore2_sem_dret;
extern mepcore2_sem_fn mepcore2_sem_dbreak;
extern mepcore2_sem_fn mepcore2_sem_ldz;
extern mepcore2_sem_fn mepcore2_sem_abs;
extern mepcore2_sem_fn mepcore2_sem_ave;
extern mepcore2_sem_fn mepcore2_sem_min;
extern mepcore2_sem_fn mepcore2_sem_max;
extern mepcore2_sem_fn mepcore2_sem_minu;
extern mepcore2_sem_fn mepcore2_sem_maxu;
extern mepcore2_sem_fn mepcore2_sem_clip;
extern mepcore2_sem_fn mepcore2_sem_clipu;
extern mepcore2_sem_fn mepcore2_sem_sadd;
extern mepcore2_sem_fn mepcore2_sem_ssub;
extern mepcore2_sem_fn mepcore2_sem_saddu;
extern mepcore2_sem_fn mepcore2_sem_ssubu;
extern mepcore2_sem_fn mepcore2_sem_swcp;
extern mepcore2_sem_fn mepcore2_sem_lwcp;
extern mepcore2_sem_fn mepcore2_sem_smcp;
extern mepcore2_sem_fn mepcore2_sem_lmcp;
extern mepcore2_sem_fn mepcore2_sem_swcpi;
extern mepcore2_sem_fn mepcore2_sem_lwcpi;
extern mepcore2_sem_fn mepcore2_sem_smcpi;
extern mepcore2_sem_fn mepcore2_sem_lmcpi;
extern mepcore2_sem_fn mepcore2_sem_swcp16;
extern mepcore2_sem_fn mepcore2_sem_lwcp16;
extern mepcore2_sem_fn mepcore2_sem_smcp16;
extern mepcore2_sem_fn mepcore2_sem_lmcp16;
extern mepcore2_sem_fn mepcore2_sem_sbcpa;
extern mepcore2_sem_fn mepcore2_sem_lbcpa;
extern mepcore2_sem_fn mepcore2_sem_shcpa;
extern mepcore2_sem_fn mepcore2_sem_lhcpa;
extern mepcore2_sem_fn mepcore2_sem_swcpa;
extern mepcore2_sem_fn mepcore2_sem_lwcpa;
extern mepcore2_sem_fn mepcore2_sem_smcpa;
extern mepcore2_sem_fn mepcore2_sem_lmcpa;
extern mepcore2_sem_fn mepcore2_sem_sbcpm0;
extern mepcore2_sem_fn mepcore2_sem_lbcpm0;
extern mepcore2_sem_fn mepcore2_sem_shcpm0;
extern mepcore2_sem_fn mepcore2_sem_lhcpm0;
extern mepcore2_sem_fn mepcore2_sem_swcpm0;
extern mepcore2_sem_fn mepcore2_sem_lwcpm0;
extern mepcore2_sem_fn mepcore2_sem_smcpm0;
extern mepcore2_sem_fn mepcore2_sem_lmcpm0;
extern mepcore2_sem_fn mepcore2_sem_sbcpm1;
extern mepcore2_sem_fn mepcore2_sem_lbcpm1;
extern mepcore2_sem_fn mepcore2_sem_shcpm1;
extern mepcore2_sem_fn mepcore2_sem_lhcpm1;
extern mepcore2_sem_fn mepcore2_sem_swcpm1;
extern mepcore2_sem_fn mepcore2_sem_lwcpm1;
extern mepcore2_sem_fn mepcore2_sem_smcpm1;
extern mepcore2_sem_fn mepcore2_sem_lmcpm1;
extern mepcore2_sem_fn mepcore2_sem_bcpeq;
extern mepcore2_sem_fn mepcore2_sem_bcpne;
extern mepcore2_sem_fn mepcore2_sem_bcpat;
extern mepcore2_sem_fn mepcore2_sem_bcpaf;
extern mepcore2_sem_fn mepcore2_sem_synccp;
extern mepcore2_sem_fn mepcore2_sem_jsrv;
extern mepcore2_sem_fn mepcore2_sem_bsrv;
extern mepcore2_sem_fn mepcore2_sem_sim_syscall;
extern mepcore2_sem_fn mepcore2_sem_ri_0;
extern mepcore2_sem_fn mepcore2_sem_ri_1;
extern mepcore2_sem_fn mepcore2_sem_ri_2;
extern mepcore2_sem_fn mepcore2_sem_ri_3;
extern mepcore2_sem_fn mepcore2_sem_ri_4;
extern mepcore2_sem_fn mepcore2_sem_ri_5;
extern mepcore2_sem_fn mepcore2_sem_ri_6;
extern mepcore2_sem_fn mepcore2_sem_ri_7;
extern mepcore2_sem_fn mepcore2_sem_ri_8;
extern mepcore2_sem_fn mepcore2_sem_ri_9;
extern mepcore2_sem_fn mepcore2_sem_ri_10;
extern mepcore2_sem_fn mepcore2_sem_ri_11;
extern mepcore2_sem_fn mepcore2_sem_ri_12;
extern mepcore2_sem_fn mepcore2_sem_ri_13;
extern mepcore2_sem_fn mepcore2_sem_ri_14;
extern mepcore2_sem_fn mepcore2_sem_ri_15;
extern mepcore2_sem_fn mepcore2_sem_ri_17;
extern mepcore2_sem_fn mepcore2_sem_ri_20;
extern mepcore2_sem_fn mepcore2_sem_ri_21;
extern mepcore2_sem_fn mepcore2_sem_ri_22;
extern mepcore2_sem_fn mepcore2_sem_ri_23;
extern mepcore2_sem_fn mepcore2_sem_ri_24;
extern mepcore2_sem_fn mepcore2_sem_ri_25;
extern mepcore2_sem_fn mepcore2_sem_ri_26;
extern mepcore2_sem_fn mepcore2_sem_ri_16;
extern mepcore2_sem_fn mepcore2_sem_ri_18;
extern mepcore2_sem_fn mepcore2_sem_ri_19;
extern mepcore2_sem_fn mepcore2_sem_fadds;
extern mepcore2_sem_fn mepcore2_sem_fsubs;
extern mepcore2_sem_fn mepcore2_sem_fmuls;
extern mepcore2_sem_fn mepcore2_sem_fdivs;
extern mepcore2_sem_fn mepcore2_sem_fsqrts;
extern mepcore2_sem_fn mepcore2_sem_fabss;
extern mepcore2_sem_fn mepcore2_sem_fnegs;
extern mepcore2_sem_fn mepcore2_sem_fmovs;
extern mepcore2_sem_fn mepcore2_sem_froundws;
extern mepcore2_sem_fn mepcore2_sem_ftruncws;
extern mepcore2_sem_fn mepcore2_sem_fceilws;
extern mepcore2_sem_fn mepcore2_sem_ffloorws;
extern mepcore2_sem_fn mepcore2_sem_fcvtws;
extern mepcore2_sem_fn mepcore2_sem_fcvtsw;
extern mepcore2_sem_fn mepcore2_sem_fcmpfs;
extern mepcore2_sem_fn mepcore2_sem_fcmpus;
extern mepcore2_sem_fn mepcore2_sem_fcmpes;
extern mepcore2_sem_fn mepcore2_sem_fcmpues;
extern mepcore2_sem_fn mepcore2_sem_fcmpls;
extern mepcore2_sem_fn mepcore2_sem_fcmpuls;
extern mepcore2_sem_fn mepcore2_sem_fcmples;
extern mepcore2_sem_fn mepcore2_sem_fcmpules;
extern mepcore2_sem_fn mepcore2_sem_fcmpfis;
extern mepcore2_sem_fn mepcore2_sem_fcmpuis;
extern mepcore2_sem_fn mepcore2_sem_fcmpeis;
extern mepcore2_sem_fn mepcore2_sem_fcmpueis;
extern mepcore2_sem_fn mepcore2_sem_fcmplis;
extern mepcore2_sem_fn mepcore2_sem_fcmpulis;
extern mepcore2_sem_fn mepcore2_sem_fcmpleis;
extern mepcore2_sem_fn mepcore2_sem_fcmpuleis;
extern mepcore2_sem_fn mepcore2_sem_cmov_frn_rm;
extern mepcore2_sem_fn mepcore2_sem_cmov_rm_frn;
extern mepcore2_sem_fn mepcore2_sem_cmovc_ccrn_rm;
extern mepcore2_sem_fn mepcore2_sem_cmovc_rm_ccrn;

#endif /* MEPCORE2_DECODE_H */
