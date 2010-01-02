/* Decode header for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEP_DECODE_H
#define MEP_DECODE_H

namespace mep_basic {

using namespace cgen;
using namespace mep;

typedef UINT mep_insn_word;

/* Enum declaration for instructions in cpu family mep.  */
typedef enum mep_insn_type {
  MEP_INSN_X_INVALID, MEP_INSN_STCB_R, MEP_INSN_LDCB_R, MEP_INSN_PREF
 , MEP_INSN_PREFD, MEP_INSN_CASB3, MEP_INSN_CASH3, MEP_INSN_CASW3
 , MEP_INSN_SBCP, MEP_INSN_LBCP, MEP_INSN_LBUCP, MEP_INSN_SHCP
 , MEP_INSN_LHCP, MEP_INSN_LHUCP, MEP_INSN_LBUCPA, MEP_INSN_LHUCPA
 , MEP_INSN_LBUCPM0, MEP_INSN_LHUCPM0, MEP_INSN_LBUCPM1, MEP_INSN_LHUCPM1
 , MEP_INSN_UCI, MEP_INSN_DSP, MEP_INSN_SB, MEP_INSN_SH
 , MEP_INSN_SW, MEP_INSN_LB, MEP_INSN_LH, MEP_INSN_LW
 , MEP_INSN_LBU, MEP_INSN_LHU, MEP_INSN_SW_SP, MEP_INSN_LW_SP
 , MEP_INSN_SB_TP, MEP_INSN_SH_TP, MEP_INSN_SW_TP, MEP_INSN_LB_TP
 , MEP_INSN_LH_TP, MEP_INSN_LW_TP, MEP_INSN_LBU_TP, MEP_INSN_LHU_TP
 , MEP_INSN_SB16, MEP_INSN_SH16, MEP_INSN_SW16, MEP_INSN_LB16
 , MEP_INSN_LH16, MEP_INSN_LW16, MEP_INSN_LBU16, MEP_INSN_LHU16
 , MEP_INSN_SW24, MEP_INSN_LW24, MEP_INSN_EXTB, MEP_INSN_EXTH
 , MEP_INSN_EXTUB, MEP_INSN_EXTUH, MEP_INSN_SSARB, MEP_INSN_MOV
 , MEP_INSN_MOVI8, MEP_INSN_MOVI16, MEP_INSN_MOVU24, MEP_INSN_MOVU16
 , MEP_INSN_MOVH, MEP_INSN_ADD3, MEP_INSN_ADD, MEP_INSN_ADD3I
 , MEP_INSN_ADVCK3, MEP_INSN_SUB, MEP_INSN_SBVCK3, MEP_INSN_NEG
 , MEP_INSN_SLT3, MEP_INSN_SLTU3, MEP_INSN_SLT3I, MEP_INSN_SLTU3I
 , MEP_INSN_SL1AD3, MEP_INSN_SL2AD3, MEP_INSN_ADD3X, MEP_INSN_SLT3X
 , MEP_INSN_SLTU3X, MEP_INSN_OR, MEP_INSN_AND, MEP_INSN_XOR
 , MEP_INSN_NOR, MEP_INSN_OR3, MEP_INSN_AND3, MEP_INSN_XOR3
 , MEP_INSN_SRA, MEP_INSN_SRL, MEP_INSN_SLL, MEP_INSN_SRAI
 , MEP_INSN_SRLI, MEP_INSN_SLLI, MEP_INSN_SLL3, MEP_INSN_FSFT
 , MEP_INSN_BRA, MEP_INSN_BEQZ, MEP_INSN_BNEZ, MEP_INSN_BEQI
 , MEP_INSN_BNEI, MEP_INSN_BLTI, MEP_INSN_BGEI, MEP_INSN_BEQ
 , MEP_INSN_BNE, MEP_INSN_BSR12, MEP_INSN_BSR24, MEP_INSN_JMP
 , MEP_INSN_JMP24, MEP_INSN_JSR, MEP_INSN_RET, MEP_INSN_REPEAT
 , MEP_INSN_EREPEAT, MEP_INSN_STC_LP, MEP_INSN_STC_HI, MEP_INSN_STC_LO
 , MEP_INSN_STC, MEP_INSN_LDC_LP, MEP_INSN_LDC_HI, MEP_INSN_LDC_LO
 , MEP_INSN_LDC, MEP_INSN_DI, MEP_INSN_EI, MEP_INSN_RETI
 , MEP_INSN_HALT, MEP_INSN_SLEEP, MEP_INSN_SWI, MEP_INSN_BREAK
 , MEP_INSN_SYNCM, MEP_INSN_STCB, MEP_INSN_LDCB, MEP_INSN_BSETM
 , MEP_INSN_BCLRM, MEP_INSN_BNOTM, MEP_INSN_BTSTM, MEP_INSN_TAS
 , MEP_INSN_CACHE, MEP_INSN_MUL, MEP_INSN_MULU, MEP_INSN_MULR
 , MEP_INSN_MULRU, MEP_INSN_MADD, MEP_INSN_MADDU, MEP_INSN_MADDR
 , MEP_INSN_MADDRU, MEP_INSN_DIV, MEP_INSN_DIVU, MEP_INSN_DRET
 , MEP_INSN_DBREAK, MEP_INSN_LDZ, MEP_INSN_ABS, MEP_INSN_AVE
 , MEP_INSN_MIN, MEP_INSN_MAX, MEP_INSN_MINU, MEP_INSN_MAXU
 , MEP_INSN_CLIP, MEP_INSN_CLIPU, MEP_INSN_SADD, MEP_INSN_SSUB
 , MEP_INSN_SADDU, MEP_INSN_SSUBU, MEP_INSN_SWCP, MEP_INSN_LWCP
 , MEP_INSN_SMCP, MEP_INSN_LMCP, MEP_INSN_SWCPI, MEP_INSN_LWCPI
 , MEP_INSN_SMCPI, MEP_INSN_LMCPI, MEP_INSN_SWCP16, MEP_INSN_LWCP16
 , MEP_INSN_SMCP16, MEP_INSN_LMCP16, MEP_INSN_SBCPA, MEP_INSN_LBCPA
 , MEP_INSN_SHCPA, MEP_INSN_LHCPA, MEP_INSN_SWCPA, MEP_INSN_LWCPA
 , MEP_INSN_SMCPA, MEP_INSN_LMCPA, MEP_INSN_SBCPM0, MEP_INSN_LBCPM0
 , MEP_INSN_SHCPM0, MEP_INSN_LHCPM0, MEP_INSN_SWCPM0, MEP_INSN_LWCPM0
 , MEP_INSN_SMCPM0, MEP_INSN_LMCPM0, MEP_INSN_SBCPM1, MEP_INSN_LBCPM1
 , MEP_INSN_SHCPM1, MEP_INSN_LHCPM1, MEP_INSN_SWCPM1, MEP_INSN_LWCPM1
 , MEP_INSN_SMCPM1, MEP_INSN_LMCPM1, MEP_INSN_BCPEQ, MEP_INSN_BCPNE
 , MEP_INSN_BCPAT, MEP_INSN_BCPAF, MEP_INSN_SYNCCP, MEP_INSN_JSRV
 , MEP_INSN_BSRV, MEP_INSN_SIM_SYSCALL, MEP_INSN_RI_0, MEP_INSN_RI_1
 , MEP_INSN_RI_2, MEP_INSN_RI_3, MEP_INSN_RI_4, MEP_INSN_RI_5
 , MEP_INSN_RI_6, MEP_INSN_RI_7, MEP_INSN_RI_8, MEP_INSN_RI_9
 , MEP_INSN_RI_10, MEP_INSN_RI_11, MEP_INSN_RI_12, MEP_INSN_RI_13
 , MEP_INSN_RI_14, MEP_INSN_RI_15, MEP_INSN_RI_17, MEP_INSN_RI_20
 , MEP_INSN_RI_21, MEP_INSN_RI_22, MEP_INSN_RI_23, MEP_INSN_RI_26
} MEP_INSN_TYPE;


// Forward decls.
struct mep_basic_cpu;
struct mep_scache;
typedef sem_status (mep_sem_fn) (mep_basic_cpu* cpu, mep_scache* sem);


// Instruction descriptor.

struct mep_idesc {

  // scache engine executor for this insn
  mep_sem_fn* execute;

  const char* insn_name;
  enum mep_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mep_idesc idesc_table[];

  static mep_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mep_sem_fields {
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
    mep_scache* next;
    mep_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mep_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mep_scache {
  // executor
  union {
    cgoto_label cgoto;
    mep_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mep_idesc* idesc;

  // argument buffer
  mep_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_basic_cpu* current_cpu, PCADDR pc, mep_insn_word base_insn, mep_insn_word entire_insn);
};

} // end mep_basic namespace

// Decls of each semantic fn.

using mep_basic::mep_sem_fn;
extern mep_sem_fn mep_sem_x_invalid;
extern mep_sem_fn mep_sem_stcb_r;
extern mep_sem_fn mep_sem_ldcb_r;
extern mep_sem_fn mep_sem_pref;
extern mep_sem_fn mep_sem_prefd;
extern mep_sem_fn mep_sem_casb3;
extern mep_sem_fn mep_sem_cash3;
extern mep_sem_fn mep_sem_casw3;
extern mep_sem_fn mep_sem_sbcp;
extern mep_sem_fn mep_sem_lbcp;
extern mep_sem_fn mep_sem_lbucp;
extern mep_sem_fn mep_sem_shcp;
extern mep_sem_fn mep_sem_lhcp;
extern mep_sem_fn mep_sem_lhucp;
extern mep_sem_fn mep_sem_lbucpa;
extern mep_sem_fn mep_sem_lhucpa;
extern mep_sem_fn mep_sem_lbucpm0;
extern mep_sem_fn mep_sem_lhucpm0;
extern mep_sem_fn mep_sem_lbucpm1;
extern mep_sem_fn mep_sem_lhucpm1;
extern mep_sem_fn mep_sem_uci;
extern mep_sem_fn mep_sem_dsp;
extern mep_sem_fn mep_sem_sb;
extern mep_sem_fn mep_sem_sh;
extern mep_sem_fn mep_sem_sw;
extern mep_sem_fn mep_sem_lb;
extern mep_sem_fn mep_sem_lh;
extern mep_sem_fn mep_sem_lw;
extern mep_sem_fn mep_sem_lbu;
extern mep_sem_fn mep_sem_lhu;
extern mep_sem_fn mep_sem_sw_sp;
extern mep_sem_fn mep_sem_lw_sp;
extern mep_sem_fn mep_sem_sb_tp;
extern mep_sem_fn mep_sem_sh_tp;
extern mep_sem_fn mep_sem_sw_tp;
extern mep_sem_fn mep_sem_lb_tp;
extern mep_sem_fn mep_sem_lh_tp;
extern mep_sem_fn mep_sem_lw_tp;
extern mep_sem_fn mep_sem_lbu_tp;
extern mep_sem_fn mep_sem_lhu_tp;
extern mep_sem_fn mep_sem_sb16;
extern mep_sem_fn mep_sem_sh16;
extern mep_sem_fn mep_sem_sw16;
extern mep_sem_fn mep_sem_lb16;
extern mep_sem_fn mep_sem_lh16;
extern mep_sem_fn mep_sem_lw16;
extern mep_sem_fn mep_sem_lbu16;
extern mep_sem_fn mep_sem_lhu16;
extern mep_sem_fn mep_sem_sw24;
extern mep_sem_fn mep_sem_lw24;
extern mep_sem_fn mep_sem_extb;
extern mep_sem_fn mep_sem_exth;
extern mep_sem_fn mep_sem_extub;
extern mep_sem_fn mep_sem_extuh;
extern mep_sem_fn mep_sem_ssarb;
extern mep_sem_fn mep_sem_mov;
extern mep_sem_fn mep_sem_movi8;
extern mep_sem_fn mep_sem_movi16;
extern mep_sem_fn mep_sem_movu24;
extern mep_sem_fn mep_sem_movu16;
extern mep_sem_fn mep_sem_movh;
extern mep_sem_fn mep_sem_add3;
extern mep_sem_fn mep_sem_add;
extern mep_sem_fn mep_sem_add3i;
extern mep_sem_fn mep_sem_advck3;
extern mep_sem_fn mep_sem_sub;
extern mep_sem_fn mep_sem_sbvck3;
extern mep_sem_fn mep_sem_neg;
extern mep_sem_fn mep_sem_slt3;
extern mep_sem_fn mep_sem_sltu3;
extern mep_sem_fn mep_sem_slt3i;
extern mep_sem_fn mep_sem_sltu3i;
extern mep_sem_fn mep_sem_sl1ad3;
extern mep_sem_fn mep_sem_sl2ad3;
extern mep_sem_fn mep_sem_add3x;
extern mep_sem_fn mep_sem_slt3x;
extern mep_sem_fn mep_sem_sltu3x;
extern mep_sem_fn mep_sem_or;
extern mep_sem_fn mep_sem_and;
extern mep_sem_fn mep_sem_xor;
extern mep_sem_fn mep_sem_nor;
extern mep_sem_fn mep_sem_or3;
extern mep_sem_fn mep_sem_and3;
extern mep_sem_fn mep_sem_xor3;
extern mep_sem_fn mep_sem_sra;
extern mep_sem_fn mep_sem_srl;
extern mep_sem_fn mep_sem_sll;
extern mep_sem_fn mep_sem_srai;
extern mep_sem_fn mep_sem_srli;
extern mep_sem_fn mep_sem_slli;
extern mep_sem_fn mep_sem_sll3;
extern mep_sem_fn mep_sem_fsft;
extern mep_sem_fn mep_sem_bra;
extern mep_sem_fn mep_sem_beqz;
extern mep_sem_fn mep_sem_bnez;
extern mep_sem_fn mep_sem_beqi;
extern mep_sem_fn mep_sem_bnei;
extern mep_sem_fn mep_sem_blti;
extern mep_sem_fn mep_sem_bgei;
extern mep_sem_fn mep_sem_beq;
extern mep_sem_fn mep_sem_bne;
extern mep_sem_fn mep_sem_bsr12;
extern mep_sem_fn mep_sem_bsr24;
extern mep_sem_fn mep_sem_jmp;
extern mep_sem_fn mep_sem_jmp24;
extern mep_sem_fn mep_sem_jsr;
extern mep_sem_fn mep_sem_ret;
extern mep_sem_fn mep_sem_repeat;
extern mep_sem_fn mep_sem_erepeat;
extern mep_sem_fn mep_sem_stc_lp;
extern mep_sem_fn mep_sem_stc_hi;
extern mep_sem_fn mep_sem_stc_lo;
extern mep_sem_fn mep_sem_stc;
extern mep_sem_fn mep_sem_ldc_lp;
extern mep_sem_fn mep_sem_ldc_hi;
extern mep_sem_fn mep_sem_ldc_lo;
extern mep_sem_fn mep_sem_ldc;
extern mep_sem_fn mep_sem_di;
extern mep_sem_fn mep_sem_ei;
extern mep_sem_fn mep_sem_reti;
extern mep_sem_fn mep_sem_halt;
extern mep_sem_fn mep_sem_sleep;
extern mep_sem_fn mep_sem_swi;
extern mep_sem_fn mep_sem_break;
extern mep_sem_fn mep_sem_syncm;
extern mep_sem_fn mep_sem_stcb;
extern mep_sem_fn mep_sem_ldcb;
extern mep_sem_fn mep_sem_bsetm;
extern mep_sem_fn mep_sem_bclrm;
extern mep_sem_fn mep_sem_bnotm;
extern mep_sem_fn mep_sem_btstm;
extern mep_sem_fn mep_sem_tas;
extern mep_sem_fn mep_sem_cache;
extern mep_sem_fn mep_sem_mul;
extern mep_sem_fn mep_sem_mulu;
extern mep_sem_fn mep_sem_mulr;
extern mep_sem_fn mep_sem_mulru;
extern mep_sem_fn mep_sem_madd;
extern mep_sem_fn mep_sem_maddu;
extern mep_sem_fn mep_sem_maddr;
extern mep_sem_fn mep_sem_maddru;
extern mep_sem_fn mep_sem_div;
extern mep_sem_fn mep_sem_divu;
extern mep_sem_fn mep_sem_dret;
extern mep_sem_fn mep_sem_dbreak;
extern mep_sem_fn mep_sem_ldz;
extern mep_sem_fn mep_sem_abs;
extern mep_sem_fn mep_sem_ave;
extern mep_sem_fn mep_sem_min;
extern mep_sem_fn mep_sem_max;
extern mep_sem_fn mep_sem_minu;
extern mep_sem_fn mep_sem_maxu;
extern mep_sem_fn mep_sem_clip;
extern mep_sem_fn mep_sem_clipu;
extern mep_sem_fn mep_sem_sadd;
extern mep_sem_fn mep_sem_ssub;
extern mep_sem_fn mep_sem_saddu;
extern mep_sem_fn mep_sem_ssubu;
extern mep_sem_fn mep_sem_swcp;
extern mep_sem_fn mep_sem_lwcp;
extern mep_sem_fn mep_sem_smcp;
extern mep_sem_fn mep_sem_lmcp;
extern mep_sem_fn mep_sem_swcpi;
extern mep_sem_fn mep_sem_lwcpi;
extern mep_sem_fn mep_sem_smcpi;
extern mep_sem_fn mep_sem_lmcpi;
extern mep_sem_fn mep_sem_swcp16;
extern mep_sem_fn mep_sem_lwcp16;
extern mep_sem_fn mep_sem_smcp16;
extern mep_sem_fn mep_sem_lmcp16;
extern mep_sem_fn mep_sem_sbcpa;
extern mep_sem_fn mep_sem_lbcpa;
extern mep_sem_fn mep_sem_shcpa;
extern mep_sem_fn mep_sem_lhcpa;
extern mep_sem_fn mep_sem_swcpa;
extern mep_sem_fn mep_sem_lwcpa;
extern mep_sem_fn mep_sem_smcpa;
extern mep_sem_fn mep_sem_lmcpa;
extern mep_sem_fn mep_sem_sbcpm0;
extern mep_sem_fn mep_sem_lbcpm0;
extern mep_sem_fn mep_sem_shcpm0;
extern mep_sem_fn mep_sem_lhcpm0;
extern mep_sem_fn mep_sem_swcpm0;
extern mep_sem_fn mep_sem_lwcpm0;
extern mep_sem_fn mep_sem_smcpm0;
extern mep_sem_fn mep_sem_lmcpm0;
extern mep_sem_fn mep_sem_sbcpm1;
extern mep_sem_fn mep_sem_lbcpm1;
extern mep_sem_fn mep_sem_shcpm1;
extern mep_sem_fn mep_sem_lhcpm1;
extern mep_sem_fn mep_sem_swcpm1;
extern mep_sem_fn mep_sem_lwcpm1;
extern mep_sem_fn mep_sem_smcpm1;
extern mep_sem_fn mep_sem_lmcpm1;
extern mep_sem_fn mep_sem_bcpeq;
extern mep_sem_fn mep_sem_bcpne;
extern mep_sem_fn mep_sem_bcpat;
extern mep_sem_fn mep_sem_bcpaf;
extern mep_sem_fn mep_sem_synccp;
extern mep_sem_fn mep_sem_jsrv;
extern mep_sem_fn mep_sem_bsrv;
extern mep_sem_fn mep_sem_sim_syscall;
extern mep_sem_fn mep_sem_ri_0;
extern mep_sem_fn mep_sem_ri_1;
extern mep_sem_fn mep_sem_ri_2;
extern mep_sem_fn mep_sem_ri_3;
extern mep_sem_fn mep_sem_ri_4;
extern mep_sem_fn mep_sem_ri_5;
extern mep_sem_fn mep_sem_ri_6;
extern mep_sem_fn mep_sem_ri_7;
extern mep_sem_fn mep_sem_ri_8;
extern mep_sem_fn mep_sem_ri_9;
extern mep_sem_fn mep_sem_ri_10;
extern mep_sem_fn mep_sem_ri_11;
extern mep_sem_fn mep_sem_ri_12;
extern mep_sem_fn mep_sem_ri_13;
extern mep_sem_fn mep_sem_ri_14;
extern mep_sem_fn mep_sem_ri_15;
extern mep_sem_fn mep_sem_ri_17;
extern mep_sem_fn mep_sem_ri_20;
extern mep_sem_fn mep_sem_ri_21;
extern mep_sem_fn mep_sem_ri_22;
extern mep_sem_fn mep_sem_ri_23;
extern mep_sem_fn mep_sem_ri_26;

#endif /* MEP_DECODE_H */
