/* Decode header for mepcore1.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCORE1_DECODE_H
#define MEPCORE1_DECODE_H

namespace mep_ext1 {

using namespace cgen;
using namespace mep;

typedef UINT mepcore1_insn_word;

/* Enum declaration for instructions in cpu family mepcore1.  */
typedef enum mepcore1_insn_type {
  MEPCORE1_INSN_X_INVALID, MEPCORE1_INSN_STCB_R, MEPCORE1_INSN_LDCB_R, MEPCORE1_INSN_PREF
 , MEPCORE1_INSN_PREFD, MEPCORE1_INSN_CASB3, MEPCORE1_INSN_CASH3, MEPCORE1_INSN_CASW3
 , MEPCORE1_INSN_SBCP, MEPCORE1_INSN_LBCP, MEPCORE1_INSN_LBUCP, MEPCORE1_INSN_SHCP
 , MEPCORE1_INSN_LHCP, MEPCORE1_INSN_LHUCP, MEPCORE1_INSN_LBUCPA, MEPCORE1_INSN_LHUCPA
 , MEPCORE1_INSN_LBUCPM0, MEPCORE1_INSN_LHUCPM0, MEPCORE1_INSN_LBUCPM1, MEPCORE1_INSN_LHUCPM1
 , MEPCORE1_INSN_UCI, MEPCORE1_INSN_DSP, MEPCORE1_INSN_SB, MEPCORE1_INSN_SH
 , MEPCORE1_INSN_SW, MEPCORE1_INSN_LB, MEPCORE1_INSN_LH, MEPCORE1_INSN_LW
 , MEPCORE1_INSN_LBU, MEPCORE1_INSN_LHU, MEPCORE1_INSN_SW_SP, MEPCORE1_INSN_LW_SP
 , MEPCORE1_INSN_SB_TP, MEPCORE1_INSN_SH_TP, MEPCORE1_INSN_SW_TP, MEPCORE1_INSN_LB_TP
 , MEPCORE1_INSN_LH_TP, MEPCORE1_INSN_LW_TP, MEPCORE1_INSN_LBU_TP, MEPCORE1_INSN_LHU_TP
 , MEPCORE1_INSN_SB16, MEPCORE1_INSN_SH16, MEPCORE1_INSN_SW16, MEPCORE1_INSN_LB16
 , MEPCORE1_INSN_LH16, MEPCORE1_INSN_LW16, MEPCORE1_INSN_LBU16, MEPCORE1_INSN_LHU16
 , MEPCORE1_INSN_SW24, MEPCORE1_INSN_LW24, MEPCORE1_INSN_EXTB, MEPCORE1_INSN_EXTH
 , MEPCORE1_INSN_EXTUB, MEPCORE1_INSN_EXTUH, MEPCORE1_INSN_SSARB, MEPCORE1_INSN_MOV
 , MEPCORE1_INSN_MOVI8, MEPCORE1_INSN_MOVI16, MEPCORE1_INSN_MOVU24, MEPCORE1_INSN_MOVU16
 , MEPCORE1_INSN_MOVH, MEPCORE1_INSN_ADD3, MEPCORE1_INSN_ADD, MEPCORE1_INSN_ADD3I
 , MEPCORE1_INSN_ADVCK3, MEPCORE1_INSN_SUB, MEPCORE1_INSN_SBVCK3, MEPCORE1_INSN_NEG
 , MEPCORE1_INSN_SLT3, MEPCORE1_INSN_SLTU3, MEPCORE1_INSN_SLT3I, MEPCORE1_INSN_SLTU3I
 , MEPCORE1_INSN_SL1AD3, MEPCORE1_INSN_SL2AD3, MEPCORE1_INSN_ADD3X, MEPCORE1_INSN_SLT3X
 , MEPCORE1_INSN_SLTU3X, MEPCORE1_INSN_OR, MEPCORE1_INSN_AND, MEPCORE1_INSN_XOR
 , MEPCORE1_INSN_NOR, MEPCORE1_INSN_OR3, MEPCORE1_INSN_AND3, MEPCORE1_INSN_XOR3
 , MEPCORE1_INSN_SRA, MEPCORE1_INSN_SRL, MEPCORE1_INSN_SLL, MEPCORE1_INSN_SRAI
 , MEPCORE1_INSN_SRLI, MEPCORE1_INSN_SLLI, MEPCORE1_INSN_SLL3, MEPCORE1_INSN_FSFT
 , MEPCORE1_INSN_BRA, MEPCORE1_INSN_BEQZ, MEPCORE1_INSN_BNEZ, MEPCORE1_INSN_BEQI
 , MEPCORE1_INSN_BNEI, MEPCORE1_INSN_BLTI, MEPCORE1_INSN_BGEI, MEPCORE1_INSN_BEQ
 , MEPCORE1_INSN_BNE, MEPCORE1_INSN_BSR12, MEPCORE1_INSN_BSR24, MEPCORE1_INSN_JMP
 , MEPCORE1_INSN_JMP24, MEPCORE1_INSN_JSR, MEPCORE1_INSN_RET, MEPCORE1_INSN_REPEAT
 , MEPCORE1_INSN_EREPEAT, MEPCORE1_INSN_STC_LP, MEPCORE1_INSN_STC_HI, MEPCORE1_INSN_STC_LO
 , MEPCORE1_INSN_STC, MEPCORE1_INSN_LDC_LP, MEPCORE1_INSN_LDC_HI, MEPCORE1_INSN_LDC_LO
 , MEPCORE1_INSN_LDC, MEPCORE1_INSN_DI, MEPCORE1_INSN_EI, MEPCORE1_INSN_RETI
 , MEPCORE1_INSN_HALT, MEPCORE1_INSN_SLEEP, MEPCORE1_INSN_SWI, MEPCORE1_INSN_BREAK
 , MEPCORE1_INSN_SYNCM, MEPCORE1_INSN_STCB, MEPCORE1_INSN_LDCB, MEPCORE1_INSN_BSETM
 , MEPCORE1_INSN_BCLRM, MEPCORE1_INSN_BNOTM, MEPCORE1_INSN_BTSTM, MEPCORE1_INSN_TAS
 , MEPCORE1_INSN_CACHE, MEPCORE1_INSN_MUL, MEPCORE1_INSN_MULU, MEPCORE1_INSN_MULR
 , MEPCORE1_INSN_MULRU, MEPCORE1_INSN_MADD, MEPCORE1_INSN_MADDU, MEPCORE1_INSN_MADDR
 , MEPCORE1_INSN_MADDRU, MEPCORE1_INSN_DIV, MEPCORE1_INSN_DIVU, MEPCORE1_INSN_DRET
 , MEPCORE1_INSN_DBREAK, MEPCORE1_INSN_LDZ, MEPCORE1_INSN_ABS, MEPCORE1_INSN_AVE
 , MEPCORE1_INSN_MIN, MEPCORE1_INSN_MAX, MEPCORE1_INSN_MINU, MEPCORE1_INSN_MAXU
 , MEPCORE1_INSN_CLIP, MEPCORE1_INSN_CLIPU, MEPCORE1_INSN_SADD, MEPCORE1_INSN_SSUB
 , MEPCORE1_INSN_SADDU, MEPCORE1_INSN_SSUBU, MEPCORE1_INSN_SWCP, MEPCORE1_INSN_LWCP
 , MEPCORE1_INSN_SMCP, MEPCORE1_INSN_LMCP, MEPCORE1_INSN_SWCPI, MEPCORE1_INSN_LWCPI
 , MEPCORE1_INSN_SMCPI, MEPCORE1_INSN_LMCPI, MEPCORE1_INSN_SWCP16, MEPCORE1_INSN_LWCP16
 , MEPCORE1_INSN_SMCP16, MEPCORE1_INSN_LMCP16, MEPCORE1_INSN_SBCPA, MEPCORE1_INSN_LBCPA
 , MEPCORE1_INSN_SHCPA, MEPCORE1_INSN_LHCPA, MEPCORE1_INSN_SWCPA, MEPCORE1_INSN_LWCPA
 , MEPCORE1_INSN_SMCPA, MEPCORE1_INSN_LMCPA, MEPCORE1_INSN_SBCPM0, MEPCORE1_INSN_LBCPM0
 , MEPCORE1_INSN_SHCPM0, MEPCORE1_INSN_LHCPM0, MEPCORE1_INSN_SWCPM0, MEPCORE1_INSN_LWCPM0
 , MEPCORE1_INSN_SMCPM0, MEPCORE1_INSN_LMCPM0, MEPCORE1_INSN_SBCPM1, MEPCORE1_INSN_LBCPM1
 , MEPCORE1_INSN_SHCPM1, MEPCORE1_INSN_LHCPM1, MEPCORE1_INSN_SWCPM1, MEPCORE1_INSN_LWCPM1
 , MEPCORE1_INSN_SMCPM1, MEPCORE1_INSN_LMCPM1, MEPCORE1_INSN_BCPEQ, MEPCORE1_INSN_BCPNE
 , MEPCORE1_INSN_BCPAT, MEPCORE1_INSN_BCPAF, MEPCORE1_INSN_SYNCCP, MEPCORE1_INSN_JSRV
 , MEPCORE1_INSN_BSRV, MEPCORE1_INSN_SIM_SYSCALL, MEPCORE1_INSN_RI_0, MEPCORE1_INSN_RI_1
 , MEPCORE1_INSN_RI_2, MEPCORE1_INSN_RI_3, MEPCORE1_INSN_RI_4, MEPCORE1_INSN_RI_5
 , MEPCORE1_INSN_RI_6, MEPCORE1_INSN_RI_7, MEPCORE1_INSN_RI_8, MEPCORE1_INSN_RI_9
 , MEPCORE1_INSN_RI_10, MEPCORE1_INSN_RI_11, MEPCORE1_INSN_RI_12, MEPCORE1_INSN_RI_13
 , MEPCORE1_INSN_RI_14, MEPCORE1_INSN_RI_15, MEPCORE1_INSN_RI_17, MEPCORE1_INSN_RI_20
 , MEPCORE1_INSN_RI_21, MEPCORE1_INSN_RI_22, MEPCORE1_INSN_RI_23, MEPCORE1_INSN_RI_26
} MEPCORE1_INSN_TYPE;


// Forward decls.
struct mep_ext1_cpu;
struct mepcore1_scache;
typedef sem_status (mepcore1_sem_fn) (mep_ext1_cpu* cpu, mepcore1_scache* sem);


// Instruction descriptor.

struct mepcore1_idesc {

  // scache engine executor for this insn
  mepcore1_sem_fn* execute;

  const char* insn_name;
  enum mepcore1_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mepcore1_idesc idesc_table[];

  static mepcore1_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mepcore1_sem_fields {
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
    INT f_12s20;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_rma;
  } sfmt_sbcp;
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
    SI* i_rma;
    SI* i_rn;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char out_rn;
  } sfmt_ldcb_r;
  struct { /*  */
    SI* i_rma;
    SI* i_rn;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rma;
    unsigned char in_rn;
  } sfmt_stcb_r;
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
    SI* i_rm;
    SI* i_rn;
    UINT f_16u16;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_rn;
  } sfmt_uci;
  struct { /*  */
    SI* i_rma;
    SI f_cdisp10;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb1;
    unsigned char in_me1;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_lbucpm1;
  struct { /*  */
    SI* i_rma;
    SI f_cdisp10;
    UINT f_crn;
    UINT f_rm;
    unsigned char in_mb0;
    unsigned char in_me0;
    unsigned char in_rma;
    unsigned char out_rma;
  } sfmt_lbucpm0;
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
    SI* i_rl5;
    SI* i_rm;
    SI* i_rn;
    UINT f_rl5;
    UINT f_rm;
    UINT f_rn;
    unsigned char in_rl5;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_rl5;
  } sfmt_casb3;
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
    mepcore1_scache* next;
    mepcore1_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mepcore1_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mepcore1_scache {
  // executor
  union {
    cgoto_label cgoto;
    mepcore1_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mepcore1_idesc* idesc;

  // argument buffer
  mepcore1_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_ext1_cpu* current_cpu, PCADDR pc, mepcore1_insn_word base_insn, mepcore1_insn_word entire_insn);
};

} // end mep_ext1 namespace

// Decls of each semantic fn.

using mep_ext1::mepcore1_sem_fn;
extern mepcore1_sem_fn mepcore1_sem_x_invalid;
extern mepcore1_sem_fn mepcore1_sem_stcb_r;
extern mepcore1_sem_fn mepcore1_sem_ldcb_r;
extern mepcore1_sem_fn mepcore1_sem_pref;
extern mepcore1_sem_fn mepcore1_sem_prefd;
extern mepcore1_sem_fn mepcore1_sem_casb3;
extern mepcore1_sem_fn mepcore1_sem_cash3;
extern mepcore1_sem_fn mepcore1_sem_casw3;
extern mepcore1_sem_fn mepcore1_sem_sbcp;
extern mepcore1_sem_fn mepcore1_sem_lbcp;
extern mepcore1_sem_fn mepcore1_sem_lbucp;
extern mepcore1_sem_fn mepcore1_sem_shcp;
extern mepcore1_sem_fn mepcore1_sem_lhcp;
extern mepcore1_sem_fn mepcore1_sem_lhucp;
extern mepcore1_sem_fn mepcore1_sem_lbucpa;
extern mepcore1_sem_fn mepcore1_sem_lhucpa;
extern mepcore1_sem_fn mepcore1_sem_lbucpm0;
extern mepcore1_sem_fn mepcore1_sem_lhucpm0;
extern mepcore1_sem_fn mepcore1_sem_lbucpm1;
extern mepcore1_sem_fn mepcore1_sem_lhucpm1;
extern mepcore1_sem_fn mepcore1_sem_uci;
extern mepcore1_sem_fn mepcore1_sem_dsp;
extern mepcore1_sem_fn mepcore1_sem_sb;
extern mepcore1_sem_fn mepcore1_sem_sh;
extern mepcore1_sem_fn mepcore1_sem_sw;
extern mepcore1_sem_fn mepcore1_sem_lb;
extern mepcore1_sem_fn mepcore1_sem_lh;
extern mepcore1_sem_fn mepcore1_sem_lw;
extern mepcore1_sem_fn mepcore1_sem_lbu;
extern mepcore1_sem_fn mepcore1_sem_lhu;
extern mepcore1_sem_fn mepcore1_sem_sw_sp;
extern mepcore1_sem_fn mepcore1_sem_lw_sp;
extern mepcore1_sem_fn mepcore1_sem_sb_tp;
extern mepcore1_sem_fn mepcore1_sem_sh_tp;
extern mepcore1_sem_fn mepcore1_sem_sw_tp;
extern mepcore1_sem_fn mepcore1_sem_lb_tp;
extern mepcore1_sem_fn mepcore1_sem_lh_tp;
extern mepcore1_sem_fn mepcore1_sem_lw_tp;
extern mepcore1_sem_fn mepcore1_sem_lbu_tp;
extern mepcore1_sem_fn mepcore1_sem_lhu_tp;
extern mepcore1_sem_fn mepcore1_sem_sb16;
extern mepcore1_sem_fn mepcore1_sem_sh16;
extern mepcore1_sem_fn mepcore1_sem_sw16;
extern mepcore1_sem_fn mepcore1_sem_lb16;
extern mepcore1_sem_fn mepcore1_sem_lh16;
extern mepcore1_sem_fn mepcore1_sem_lw16;
extern mepcore1_sem_fn mepcore1_sem_lbu16;
extern mepcore1_sem_fn mepcore1_sem_lhu16;
extern mepcore1_sem_fn mepcore1_sem_sw24;
extern mepcore1_sem_fn mepcore1_sem_lw24;
extern mepcore1_sem_fn mepcore1_sem_extb;
extern mepcore1_sem_fn mepcore1_sem_exth;
extern mepcore1_sem_fn mepcore1_sem_extub;
extern mepcore1_sem_fn mepcore1_sem_extuh;
extern mepcore1_sem_fn mepcore1_sem_ssarb;
extern mepcore1_sem_fn mepcore1_sem_mov;
extern mepcore1_sem_fn mepcore1_sem_movi8;
extern mepcore1_sem_fn mepcore1_sem_movi16;
extern mepcore1_sem_fn mepcore1_sem_movu24;
extern mepcore1_sem_fn mepcore1_sem_movu16;
extern mepcore1_sem_fn mepcore1_sem_movh;
extern mepcore1_sem_fn mepcore1_sem_add3;
extern mepcore1_sem_fn mepcore1_sem_add;
extern mepcore1_sem_fn mepcore1_sem_add3i;
extern mepcore1_sem_fn mepcore1_sem_advck3;
extern mepcore1_sem_fn mepcore1_sem_sub;
extern mepcore1_sem_fn mepcore1_sem_sbvck3;
extern mepcore1_sem_fn mepcore1_sem_neg;
extern mepcore1_sem_fn mepcore1_sem_slt3;
extern mepcore1_sem_fn mepcore1_sem_sltu3;
extern mepcore1_sem_fn mepcore1_sem_slt3i;
extern mepcore1_sem_fn mepcore1_sem_sltu3i;
extern mepcore1_sem_fn mepcore1_sem_sl1ad3;
extern mepcore1_sem_fn mepcore1_sem_sl2ad3;
extern mepcore1_sem_fn mepcore1_sem_add3x;
extern mepcore1_sem_fn mepcore1_sem_slt3x;
extern mepcore1_sem_fn mepcore1_sem_sltu3x;
extern mepcore1_sem_fn mepcore1_sem_or;
extern mepcore1_sem_fn mepcore1_sem_and;
extern mepcore1_sem_fn mepcore1_sem_xor;
extern mepcore1_sem_fn mepcore1_sem_nor;
extern mepcore1_sem_fn mepcore1_sem_or3;
extern mepcore1_sem_fn mepcore1_sem_and3;
extern mepcore1_sem_fn mepcore1_sem_xor3;
extern mepcore1_sem_fn mepcore1_sem_sra;
extern mepcore1_sem_fn mepcore1_sem_srl;
extern mepcore1_sem_fn mepcore1_sem_sll;
extern mepcore1_sem_fn mepcore1_sem_srai;
extern mepcore1_sem_fn mepcore1_sem_srli;
extern mepcore1_sem_fn mepcore1_sem_slli;
extern mepcore1_sem_fn mepcore1_sem_sll3;
extern mepcore1_sem_fn mepcore1_sem_fsft;
extern mepcore1_sem_fn mepcore1_sem_bra;
extern mepcore1_sem_fn mepcore1_sem_beqz;
extern mepcore1_sem_fn mepcore1_sem_bnez;
extern mepcore1_sem_fn mepcore1_sem_beqi;
extern mepcore1_sem_fn mepcore1_sem_bnei;
extern mepcore1_sem_fn mepcore1_sem_blti;
extern mepcore1_sem_fn mepcore1_sem_bgei;
extern mepcore1_sem_fn mepcore1_sem_beq;
extern mepcore1_sem_fn mepcore1_sem_bne;
extern mepcore1_sem_fn mepcore1_sem_bsr12;
extern mepcore1_sem_fn mepcore1_sem_bsr24;
extern mepcore1_sem_fn mepcore1_sem_jmp;
extern mepcore1_sem_fn mepcore1_sem_jmp24;
extern mepcore1_sem_fn mepcore1_sem_jsr;
extern mepcore1_sem_fn mepcore1_sem_ret;
extern mepcore1_sem_fn mepcore1_sem_repeat;
extern mepcore1_sem_fn mepcore1_sem_erepeat;
extern mepcore1_sem_fn mepcore1_sem_stc_lp;
extern mepcore1_sem_fn mepcore1_sem_stc_hi;
extern mepcore1_sem_fn mepcore1_sem_stc_lo;
extern mepcore1_sem_fn mepcore1_sem_stc;
extern mepcore1_sem_fn mepcore1_sem_ldc_lp;
extern mepcore1_sem_fn mepcore1_sem_ldc_hi;
extern mepcore1_sem_fn mepcore1_sem_ldc_lo;
extern mepcore1_sem_fn mepcore1_sem_ldc;
extern mepcore1_sem_fn mepcore1_sem_di;
extern mepcore1_sem_fn mepcore1_sem_ei;
extern mepcore1_sem_fn mepcore1_sem_reti;
extern mepcore1_sem_fn mepcore1_sem_halt;
extern mepcore1_sem_fn mepcore1_sem_sleep;
extern mepcore1_sem_fn mepcore1_sem_swi;
extern mepcore1_sem_fn mepcore1_sem_break;
extern mepcore1_sem_fn mepcore1_sem_syncm;
extern mepcore1_sem_fn mepcore1_sem_stcb;
extern mepcore1_sem_fn mepcore1_sem_ldcb;
extern mepcore1_sem_fn mepcore1_sem_bsetm;
extern mepcore1_sem_fn mepcore1_sem_bclrm;
extern mepcore1_sem_fn mepcore1_sem_bnotm;
extern mepcore1_sem_fn mepcore1_sem_btstm;
extern mepcore1_sem_fn mepcore1_sem_tas;
extern mepcore1_sem_fn mepcore1_sem_cache;
extern mepcore1_sem_fn mepcore1_sem_mul;
extern mepcore1_sem_fn mepcore1_sem_mulu;
extern mepcore1_sem_fn mepcore1_sem_mulr;
extern mepcore1_sem_fn mepcore1_sem_mulru;
extern mepcore1_sem_fn mepcore1_sem_madd;
extern mepcore1_sem_fn mepcore1_sem_maddu;
extern mepcore1_sem_fn mepcore1_sem_maddr;
extern mepcore1_sem_fn mepcore1_sem_maddru;
extern mepcore1_sem_fn mepcore1_sem_div;
extern mepcore1_sem_fn mepcore1_sem_divu;
extern mepcore1_sem_fn mepcore1_sem_dret;
extern mepcore1_sem_fn mepcore1_sem_dbreak;
extern mepcore1_sem_fn mepcore1_sem_ldz;
extern mepcore1_sem_fn mepcore1_sem_abs;
extern mepcore1_sem_fn mepcore1_sem_ave;
extern mepcore1_sem_fn mepcore1_sem_min;
extern mepcore1_sem_fn mepcore1_sem_max;
extern mepcore1_sem_fn mepcore1_sem_minu;
extern mepcore1_sem_fn mepcore1_sem_maxu;
extern mepcore1_sem_fn mepcore1_sem_clip;
extern mepcore1_sem_fn mepcore1_sem_clipu;
extern mepcore1_sem_fn mepcore1_sem_sadd;
extern mepcore1_sem_fn mepcore1_sem_ssub;
extern mepcore1_sem_fn mepcore1_sem_saddu;
extern mepcore1_sem_fn mepcore1_sem_ssubu;
extern mepcore1_sem_fn mepcore1_sem_swcp;
extern mepcore1_sem_fn mepcore1_sem_lwcp;
extern mepcore1_sem_fn mepcore1_sem_smcp;
extern mepcore1_sem_fn mepcore1_sem_lmcp;
extern mepcore1_sem_fn mepcore1_sem_swcpi;
extern mepcore1_sem_fn mepcore1_sem_lwcpi;
extern mepcore1_sem_fn mepcore1_sem_smcpi;
extern mepcore1_sem_fn mepcore1_sem_lmcpi;
extern mepcore1_sem_fn mepcore1_sem_swcp16;
extern mepcore1_sem_fn mepcore1_sem_lwcp16;
extern mepcore1_sem_fn mepcore1_sem_smcp16;
extern mepcore1_sem_fn mepcore1_sem_lmcp16;
extern mepcore1_sem_fn mepcore1_sem_sbcpa;
extern mepcore1_sem_fn mepcore1_sem_lbcpa;
extern mepcore1_sem_fn mepcore1_sem_shcpa;
extern mepcore1_sem_fn mepcore1_sem_lhcpa;
extern mepcore1_sem_fn mepcore1_sem_swcpa;
extern mepcore1_sem_fn mepcore1_sem_lwcpa;
extern mepcore1_sem_fn mepcore1_sem_smcpa;
extern mepcore1_sem_fn mepcore1_sem_lmcpa;
extern mepcore1_sem_fn mepcore1_sem_sbcpm0;
extern mepcore1_sem_fn mepcore1_sem_lbcpm0;
extern mepcore1_sem_fn mepcore1_sem_shcpm0;
extern mepcore1_sem_fn mepcore1_sem_lhcpm0;
extern mepcore1_sem_fn mepcore1_sem_swcpm0;
extern mepcore1_sem_fn mepcore1_sem_lwcpm0;
extern mepcore1_sem_fn mepcore1_sem_smcpm0;
extern mepcore1_sem_fn mepcore1_sem_lmcpm0;
extern mepcore1_sem_fn mepcore1_sem_sbcpm1;
extern mepcore1_sem_fn mepcore1_sem_lbcpm1;
extern mepcore1_sem_fn mepcore1_sem_shcpm1;
extern mepcore1_sem_fn mepcore1_sem_lhcpm1;
extern mepcore1_sem_fn mepcore1_sem_swcpm1;
extern mepcore1_sem_fn mepcore1_sem_lwcpm1;
extern mepcore1_sem_fn mepcore1_sem_smcpm1;
extern mepcore1_sem_fn mepcore1_sem_lmcpm1;
extern mepcore1_sem_fn mepcore1_sem_bcpeq;
extern mepcore1_sem_fn mepcore1_sem_bcpne;
extern mepcore1_sem_fn mepcore1_sem_bcpat;
extern mepcore1_sem_fn mepcore1_sem_bcpaf;
extern mepcore1_sem_fn mepcore1_sem_synccp;
extern mepcore1_sem_fn mepcore1_sem_jsrv;
extern mepcore1_sem_fn mepcore1_sem_bsrv;
extern mepcore1_sem_fn mepcore1_sem_sim_syscall;
extern mepcore1_sem_fn mepcore1_sem_ri_0;
extern mepcore1_sem_fn mepcore1_sem_ri_1;
extern mepcore1_sem_fn mepcore1_sem_ri_2;
extern mepcore1_sem_fn mepcore1_sem_ri_3;
extern mepcore1_sem_fn mepcore1_sem_ri_4;
extern mepcore1_sem_fn mepcore1_sem_ri_5;
extern mepcore1_sem_fn mepcore1_sem_ri_6;
extern mepcore1_sem_fn mepcore1_sem_ri_7;
extern mepcore1_sem_fn mepcore1_sem_ri_8;
extern mepcore1_sem_fn mepcore1_sem_ri_9;
extern mepcore1_sem_fn mepcore1_sem_ri_10;
extern mepcore1_sem_fn mepcore1_sem_ri_11;
extern mepcore1_sem_fn mepcore1_sem_ri_12;
extern mepcore1_sem_fn mepcore1_sem_ri_13;
extern mepcore1_sem_fn mepcore1_sem_ri_14;
extern mepcore1_sem_fn mepcore1_sem_ri_15;
extern mepcore1_sem_fn mepcore1_sem_ri_17;
extern mepcore1_sem_fn mepcore1_sem_ri_20;
extern mepcore1_sem_fn mepcore1_sem_ri_21;
extern mepcore1_sem_fn mepcore1_sem_ri_22;
extern mepcore1_sem_fn mepcore1_sem_ri_23;
extern mepcore1_sem_fn mepcore1_sem_ri_26;

#endif /* MEPCORE1_DECODE_H */
