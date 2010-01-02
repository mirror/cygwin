/* Decode header for mepcop1_16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP1_16_DECODE_H
#define MEPCOP1_16_DECODE_H

namespace mep_ext1 {

using namespace cgen;
using namespace mep;

typedef UINT mepcop1_16_insn_word;

/* Enum declaration for instructions in cpu family mepcop1_16.  */
typedef enum mepcop1_16_insn_type {
  MEPCOP1_16_INSN_X_INVALID, MEPCOP1_16_INSN_C0NOP_P0_P0S, MEPCOP1_16_INSN_CPADD3_B_P0S_P1, MEPCOP1_16_INSN_CPADD3_H_P0S_P1
 , MEPCOP1_16_INSN_CPADD3_W_P0S_P1, MEPCOP1_16_INSN_CPUNPACKU_B_P0S_P1, MEPCOP1_16_INSN_CPUNPACKU_H_P0S_P1, MEPCOP1_16_INSN_CPUNPACKU_W_P0S_P1
 , MEPCOP1_16_INSN_CPUNPACKL_B_P0S_P1, MEPCOP1_16_INSN_CPUNPACKL_H_P0S_P1, MEPCOP1_16_INSN_CPUNPACKL_W_P0S_P1, MEPCOP1_16_INSN_CPSEL_P0S_P1
 , MEPCOP1_16_INSN_CPFSFTBS0_P0S_P1, MEPCOP1_16_INSN_CPFSFTBS1_P0S_P1, MEPCOP1_16_INSN_CPMOV_P0S_P1, MEPCOP1_16_INSN_CPABSZ_B_P0S_P1
 , MEPCOP1_16_INSN_CPABSZ_H_P0S_P1, MEPCOP1_16_INSN_CPABSZ_W_P0S_P1, MEPCOP1_16_INSN_CPLDZ_H_P0S_P1, MEPCOP1_16_INSN_CPLDZ_W_P0S_P1
 , MEPCOP1_16_INSN_CPNORM_H_P0S_P1, MEPCOP1_16_INSN_CPNORM_W_P0S_P1, MEPCOP1_16_INSN_CPHADDU_B_P0S_P1, MEPCOP1_16_INSN_CPHADD_B_P0S_P1
 , MEPCOP1_16_INSN_CPHADD_H_P0S_P1, MEPCOP1_16_INSN_CPHADD_W_P0S_P1, MEPCOP1_16_INSN_CPCCADD_B_P0S_P1, MEPCOP1_16_INSN_CPBCAST_B_P0S_P1
 , MEPCOP1_16_INSN_CPBCAST_H_P0S_P1, MEPCOP1_16_INSN_CPBCAST_W_P0S_P1, MEPCOP1_16_INSN_CPEXTUU_B_P0S_P1, MEPCOP1_16_INSN_CPEXTU_B_P0S_P1
 , MEPCOP1_16_INSN_CPEXTUU_H_P0S_P1, MEPCOP1_16_INSN_CPEXTU_H_P0S_P1, MEPCOP1_16_INSN_CPEXTLU_B_P0S_P1, MEPCOP1_16_INSN_CPEXTL_B_P0S_P1
 , MEPCOP1_16_INSN_CPEXTLU_H_P0S_P1, MEPCOP1_16_INSN_CPEXTL_H_P0S_P1, MEPCOP1_16_INSN_CPCASTUB_H_P0S_P1, MEPCOP1_16_INSN_CPCASTB_H_P0S_P1
 , MEPCOP1_16_INSN_CPCASTUB_W_P0S_P1, MEPCOP1_16_INSN_CPCASTB_W_P0S_P1, MEPCOP1_16_INSN_CPCASTUH_W_P0S_P1, MEPCOP1_16_INSN_CPCASTH_W_P0S_P1
 , MEPCOP1_16_INSN_CDCASTUW_P0S_P1, MEPCOP1_16_INSN_CDCASTW_P0S_P1, MEPCOP1_16_INSN_CPMOVFRCSAR0_P0S_P1, MEPCOP1_16_INSN_CPMOVFRCSAR1_P0S_P1
 , MEPCOP1_16_INSN_CPMOVFRCC_P0S_P1, MEPCOP1_16_INSN_CPMOVTOCSAR0_P0S_P1, MEPCOP1_16_INSN_CPMOVTOCSAR1_P0S_P1, MEPCOP1_16_INSN_CPMOVTOCC_P0S_P1
 , MEPCOP1_16_INSN_CPCMPEQZ_B_P0S_P1, MEPCOP1_16_INSN_CPCMPEQ_B_P0S_P1, MEPCOP1_16_INSN_CPCMPEQ_H_P0S_P1, MEPCOP1_16_INSN_CPCMPEQ_W_P0S_P1
 , MEPCOP1_16_INSN_CPCMPNE_B_P0S_P1, MEPCOP1_16_INSN_CPCMPNE_H_P0S_P1, MEPCOP1_16_INSN_CPCMPNE_W_P0S_P1, MEPCOP1_16_INSN_CPCMPGTU_B_P0S_P1
 , MEPCOP1_16_INSN_CPCMPGT_B_P0S_P1, MEPCOP1_16_INSN_CPCMPGT_H_P0S_P1, MEPCOP1_16_INSN_CPCMPGTU_W_P0S_P1, MEPCOP1_16_INSN_CPCMPGT_W_P0S_P1
 , MEPCOP1_16_INSN_CPCMPGEU_B_P0S_P1, MEPCOP1_16_INSN_CPCMPGE_B_P0S_P1, MEPCOP1_16_INSN_CPCMPGE_H_P0S_P1, MEPCOP1_16_INSN_CPCMPGEU_W_P0S_P1
 , MEPCOP1_16_INSN_CPCMPGE_W_P0S_P1, MEPCOP1_16_INSN_CPADDA0U_B_P0S, MEPCOP1_16_INSN_CPADDA0_B_P0S, MEPCOP1_16_INSN_CPADDUA0_H_P0S
 , MEPCOP1_16_INSN_CPADDLA0_H_P0S, MEPCOP1_16_INSN_CPADDACA0U_B_P0S, MEPCOP1_16_INSN_CPADDACA0_B_P0S, MEPCOP1_16_INSN_CPADDACUA0_H_P0S
 , MEPCOP1_16_INSN_CPADDACLA0_H_P0S, MEPCOP1_16_INSN_CPSUBA0U_B_P0S, MEPCOP1_16_INSN_CPSUBA0_B_P0S, MEPCOP1_16_INSN_CPSUBUA0_H_P0S
 , MEPCOP1_16_INSN_CPSUBLA0_H_P0S, MEPCOP1_16_INSN_CPSUBACA0U_B_P0S, MEPCOP1_16_INSN_CPSUBACA0_B_P0S, MEPCOP1_16_INSN_CPSUBACUA0_H_P0S
 , MEPCOP1_16_INSN_CPSUBACLA0_H_P0S, MEPCOP1_16_INSN_CPABSA0U_B_P0S, MEPCOP1_16_INSN_CPABSA0_B_P0S, MEPCOP1_16_INSN_CPABSUA0_H_P0S
 , MEPCOP1_16_INSN_CPABSLA0_H_P0S, MEPCOP1_16_INSN_CPSADA0U_B_P0S, MEPCOP1_16_INSN_CPSADA0_B_P0S, MEPCOP1_16_INSN_CPSADUA0_H_P0S
 , MEPCOP1_16_INSN_CPSADLA0_H_P0S, MEPCOP1_16_INSN_CPSETA0_H_P0S, MEPCOP1_16_INSN_CPSETUA0_W_P0S, MEPCOP1_16_INSN_CPSETLA0_W_P0S
 , MEPCOP1_16_INSN_CPMOVA0_B_P0S, MEPCOP1_16_INSN_CPMOVUA0_H_P0S, MEPCOP1_16_INSN_CPMOVLA0_H_P0S, MEPCOP1_16_INSN_CPMOVUUA0_W_P0S
 , MEPCOP1_16_INSN_CPMOVULA0_W_P0S, MEPCOP1_16_INSN_CPMOVLUA0_W_P0S, MEPCOP1_16_INSN_CPMOVLLA0_W_P0S, MEPCOP1_16_INSN_CPPACKA0U_B_P0S
 , MEPCOP1_16_INSN_CPPACKA0_B_P0S, MEPCOP1_16_INSN_CPPACKUA0_H_P0S, MEPCOP1_16_INSN_CPPACKLA0_H_P0S, MEPCOP1_16_INSN_CPPACKUA0_W_P0S
 , MEPCOP1_16_INSN_CPPACKLA0_W_P0S, MEPCOP1_16_INSN_CPMOVHUA0_W_P0S, MEPCOP1_16_INSN_CPMOVHLA0_W_P0S, MEPCOP1_16_INSN_CPACSUMA0_P0S
 , MEPCOP1_16_INSN_CPACCPA0_P0S, MEPCOP1_16_INSN_CPSRLA0_P0S, MEPCOP1_16_INSN_CPSRAA0_P0S, MEPCOP1_16_INSN_CPSLLA0_P0S
 , MEPCOP1_16_INSN_CPSRLIA0_P0S, MEPCOP1_16_INSN_CPSRAIA0_P0S, MEPCOP1_16_INSN_CPSLLIA0_P0S, MEPCOP1_16_INSN_CPFSFTBA0S0U_B_P0S
 , MEPCOP1_16_INSN_CPFSFTBA0S0_B_P0S, MEPCOP1_16_INSN_CPFSFTBUA0S0_H_P0S, MEPCOP1_16_INSN_CPFSFTBLA0S0_H_P0S, MEPCOP1_16_INSN_CPFACA0S0U_B_P0S
 , MEPCOP1_16_INSN_CPFACA0S0_B_P0S, MEPCOP1_16_INSN_CPFACUA0S0_H_P0S, MEPCOP1_16_INSN_CPFACLA0S0_H_P0S, MEPCOP1_16_INSN_CPFSFTBA0S1U_B_P0S
 , MEPCOP1_16_INSN_CPFSFTBA0S1_B_P0S, MEPCOP1_16_INSN_CPFSFTBUA0S1_H_P0S, MEPCOP1_16_INSN_CPFSFTBLA0S1_H_P0S, MEPCOP1_16_INSN_CPFACA0S1U_B_P0S
 , MEPCOP1_16_INSN_CPFACA0S1_B_P0S, MEPCOP1_16_INSN_CPFACUA0S1_H_P0S, MEPCOP1_16_INSN_CPFACLA0S1_H_P0S, MEPCOP1_16_INSN_CPMOVI_B_P0S_P1
} MEPCOP1_16_INSN_TYPE;


// Forward decls.
struct mep_ext1_cpu;
struct mepcop1_16_scache;
typedef sem_status (mepcop1_16_sem_fn) (mep_ext1_cpu* cpu, mepcop1_16_scache* sem);


// Instruction descriptor.

struct mepcop1_16_idesc {

  // scache engine executor for this insn
  mepcop1_16_sem_fn* execute;

  const char* insn_name;
  enum mepcop1_16_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mepcop1_16_idesc idesc_table[];

  static mepcop1_16_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mepcop1_16_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    INT f_ivc2_8s20;
    UINT f_ivc2_5u13;
  } sfmt_cpmovi_b_P0S_P1;
  struct { /*  */
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u18;
    UINT f_ivc2_5u23;
  } sfmt_cpadd3_b_P0S_P1;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    mepcop1_16_scache* next;
    mepcop1_16_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mepcop1_16_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mepcop1_16_scache {
  // executor
  union {
    cgoto_label cgoto;
    mepcop1_16_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mepcop1_16_idesc* idesc;

  // argument buffer
  mepcop1_16_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_16_insn_word base_insn, mepcop1_16_insn_word entire_insn);
};

} // end mep_ext1 namespace

// Decls of each semantic fn.

using mep_ext1::mepcop1_16_sem_fn;
extern mepcop1_16_sem_fn mepcop1_16_sem_x_invalid;
extern mepcop1_16_sem_fn mepcop1_16_sem_c0nop_P0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpadd3_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpadd3_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpadd3_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpunpacku_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpunpacku_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpunpacku_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpunpackl_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpunpackl_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpunpackl_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsel_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftbs0_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftbs1_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmov_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsz_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsz_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsz_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpldz_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpldz_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpnorm_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpnorm_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cphaddu_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cphadd_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cphadd_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cphadd_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpccadd_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpbcast_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpbcast_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpbcast_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextuu_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextu_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextuu_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextu_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextlu_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextl_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextlu_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpextl_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcastub_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcastb_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcastub_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcastb_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcastuh_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcasth_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cdcastuw_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cdcastw_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovfrcsar0_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovfrcsar1_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovfrcc_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovtocsar0_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovtocsar1_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovtocc_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpeqz_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpeq_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpeq_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpeq_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpne_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpne_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpne_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgtu_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgt_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgt_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgtu_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgt_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgeu_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpge_b_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpge_h_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpgeu_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpcmpge_w_P0S_P1;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpadda0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpadda0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaddua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaddla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaddaca0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaddaca0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaddacua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaddacla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsuba0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsuba0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsubua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsubla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsubaca0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsubaca0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsubacua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsubacla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsa0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsa0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpabsla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsada0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsada0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsadua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsadla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpseta0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsetua0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsetla0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmova0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovuua0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovula0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovlua0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovlla0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cppacka0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cppacka0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cppackua0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cppackla0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cppackua0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cppackla0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovhua0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovhla0_w_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpacsuma0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpaccpa0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsrla0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsraa0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpslla0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsrlia0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsraia0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpsllia0_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftba0s0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftba0s0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftbua0s0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftbla0s0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfaca0s0u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfaca0s0_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfacua0s0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfacla0s0_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftba0s1u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftba0s1_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftbua0s1_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfsftbla0s1_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfaca0s1u_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfaca0s1_b_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfacua0s1_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpfacla0s1_h_P0S;
extern mepcop1_16_sem_fn mepcop1_16_sem_cpmovi_b_P0S_P1;

#endif /* MEPCOP1_16_DECODE_H */
