/* Decode header for mepcop1_48.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP1_48_DECODE_H
#define MEPCOP1_48_DECODE_H

namespace mep_ext1 {

using namespace cgen;
using namespace mep;

typedef UINT mepcop1_48_insn_word;

/* Enum declaration for instructions in cpu family mepcop1_48.  */
typedef enum mepcop1_48_insn_type {
  MEPCOP1_48_INSN_X_INVALID, MEPCOP1_48_INSN_CMOV_CRN_RM_P0, MEPCOP1_48_INSN_CMOV_RN_CRM_P0, MEPCOP1_48_INSN_CMOVC_CCRN_RM_P0
 , MEPCOP1_48_INSN_CMOVC_RN_CCRM_P0, MEPCOP1_48_INSN_CMOVH_CRN_RM_P0, MEPCOP1_48_INSN_CMOVH_RN_CRM_P0, MEPCOP1_48_INSN_C0NOP_P0_P0S
 , MEPCOP1_48_INSN_CPFSFTBI_P0_P1, MEPCOP1_48_INSN_CPACMPEQ_B_P0_P1, MEPCOP1_48_INSN_CPACMPEQ_H_P0_P1, MEPCOP1_48_INSN_CPACMPEQ_W_P0_P1
 , MEPCOP1_48_INSN_CPACMPNE_B_P0_P1, MEPCOP1_48_INSN_CPACMPNE_H_P0_P1, MEPCOP1_48_INSN_CPACMPNE_W_P0_P1, MEPCOP1_48_INSN_CPACMPGTU_B_P0_P1
 , MEPCOP1_48_INSN_CPACMPGT_B_P0_P1, MEPCOP1_48_INSN_CPACMPGT_H_P0_P1, MEPCOP1_48_INSN_CPACMPGTU_W_P0_P1, MEPCOP1_48_INSN_CPACMPGT_W_P0_P1
 , MEPCOP1_48_INSN_CPACMPGEU_B_P0_P1, MEPCOP1_48_INSN_CPACMPGE_B_P0_P1, MEPCOP1_48_INSN_CPACMPGE_H_P0_P1, MEPCOP1_48_INSN_CPACMPGEU_W_P0_P1
 , MEPCOP1_48_INSN_CPACMPGE_W_P0_P1, MEPCOP1_48_INSN_CPOCMPEQ_B_P0_P1, MEPCOP1_48_INSN_CPOCMPEQ_H_P0_P1, MEPCOP1_48_INSN_CPOCMPEQ_W_P0_P1
 , MEPCOP1_48_INSN_CPOCMPNE_B_P0_P1, MEPCOP1_48_INSN_CPOCMPNE_H_P0_P1, MEPCOP1_48_INSN_CPOCMPNE_W_P0_P1, MEPCOP1_48_INSN_CPOCMPGTU_B_P0_P1
 , MEPCOP1_48_INSN_CPOCMPGT_B_P0_P1, MEPCOP1_48_INSN_CPOCMPGT_H_P0_P1, MEPCOP1_48_INSN_CPOCMPGTU_W_P0_P1, MEPCOP1_48_INSN_CPOCMPGT_W_P0_P1
 , MEPCOP1_48_INSN_CPOCMPGEU_B_P0_P1, MEPCOP1_48_INSN_CPOCMPGE_B_P0_P1, MEPCOP1_48_INSN_CPOCMPGE_H_P0_P1, MEPCOP1_48_INSN_CPOCMPGEU_W_P0_P1
 , MEPCOP1_48_INSN_CPOCMPGE_W_P0_P1, MEPCOP1_48_INSN_CDADD3_P0_P1, MEPCOP1_48_INSN_CPSUB3_B_P0_P1, MEPCOP1_48_INSN_CPSUB3_H_P0_P1
 , MEPCOP1_48_INSN_CPSUB3_W_P0_P1, MEPCOP1_48_INSN_CDSUB3_P0_P1, MEPCOP1_48_INSN_CPSADD3_H_P0_P1, MEPCOP1_48_INSN_CPSADD3_W_P0_P1
 , MEPCOP1_48_INSN_CPSSUB3_H_P0_P1, MEPCOP1_48_INSN_CPSSUB3_W_P0_P1, MEPCOP1_48_INSN_CPEXTUADDU3_B_P0_P1, MEPCOP1_48_INSN_CPEXTUADD3_B_P0_P1
 , MEPCOP1_48_INSN_CPEXTLADDU3_B_P0_P1, MEPCOP1_48_INSN_CPEXTLADD3_B_P0_P1, MEPCOP1_48_INSN_CPEXTUSUBU3_B_P0_P1, MEPCOP1_48_INSN_CPEXTUSUB3_B_P0_P1
 , MEPCOP1_48_INSN_CPEXTLSUBU3_B_P0_P1, MEPCOP1_48_INSN_CPEXTLSUB3_B_P0_P1, MEPCOP1_48_INSN_CPAVEU3_B_P0_P1, MEPCOP1_48_INSN_CPAVE3_B_P0_P1
 , MEPCOP1_48_INSN_CPAVE3_H_P0_P1, MEPCOP1_48_INSN_CPAVE3_W_P0_P1, MEPCOP1_48_INSN_CPADDSRU3_B_P0_P1, MEPCOP1_48_INSN_CPADDSR3_B_P0_P1
 , MEPCOP1_48_INSN_CPADDSR3_H_P0_P1, MEPCOP1_48_INSN_CPADDSR3_W_P0_P1, MEPCOP1_48_INSN_CPABSU3_B_P0_P1, MEPCOP1_48_INSN_CPABS3_B_P0_P1
 , MEPCOP1_48_INSN_CPABS3_H_P0_P1, MEPCOP1_48_INSN_CPAND3_P0_P1, MEPCOP1_48_INSN_CPOR3_P0_P1, MEPCOP1_48_INSN_CPNOR3_P0_P1
 , MEPCOP1_48_INSN_CPXOR3_P0_P1, MEPCOP1_48_INSN_CPPACKU_B_P0_P1, MEPCOP1_48_INSN_CPPACK_B_P0_P1, MEPCOP1_48_INSN_CPPACK_H_P0_P1
 , MEPCOP1_48_INSN_CPMAXU3_B_P0_P1, MEPCOP1_48_INSN_CPMAX3_B_P0_P1, MEPCOP1_48_INSN_CPMAX3_H_P0_P1, MEPCOP1_48_INSN_CPMAXU3_W_P0_P1
 , MEPCOP1_48_INSN_CPMAX3_W_P0_P1, MEPCOP1_48_INSN_CPMINU3_B_P0_P1, MEPCOP1_48_INSN_CPMIN3_B_P0_P1, MEPCOP1_48_INSN_CPMIN3_H_P0_P1
 , MEPCOP1_48_INSN_CPMINU3_W_P0_P1, MEPCOP1_48_INSN_CPMIN3_W_P0_P1, MEPCOP1_48_INSN_CPSRL3_B_P0_P1, MEPCOP1_48_INSN_CPSSRL3_B_P0_P1
 , MEPCOP1_48_INSN_CPSRL3_H_P0_P1, MEPCOP1_48_INSN_CPSSRL3_H_P0_P1, MEPCOP1_48_INSN_CPSRL3_W_P0_P1, MEPCOP1_48_INSN_CPSSRL3_W_P0_P1
 , MEPCOP1_48_INSN_CDSRL3_P0_P1, MEPCOP1_48_INSN_CPSRA3_B_P0_P1, MEPCOP1_48_INSN_CPSSRA3_B_P0_P1, MEPCOP1_48_INSN_CPSRA3_H_P0_P1
 , MEPCOP1_48_INSN_CPSSRA3_H_P0_P1, MEPCOP1_48_INSN_CPSRA3_W_P0_P1, MEPCOP1_48_INSN_CPSSRA3_W_P0_P1, MEPCOP1_48_INSN_CDSRA3_P0_P1
 , MEPCOP1_48_INSN_CPSLL3_B_P0_P1, MEPCOP1_48_INSN_CPSSLL3_B_P0_P1, MEPCOP1_48_INSN_CPSLL3_H_P0_P1, MEPCOP1_48_INSN_CPSSLL3_H_P0_P1
 , MEPCOP1_48_INSN_CPSLL3_W_P0_P1, MEPCOP1_48_INSN_CPSSLL3_W_P0_P1, MEPCOP1_48_INSN_CDSLL3_P0_P1, MEPCOP1_48_INSN_CPSLA3_H_P0_P1
 , MEPCOP1_48_INSN_CPSLA3_W_P0_P1, MEPCOP1_48_INSN_CPSRLI3_B_P0_P1, MEPCOP1_48_INSN_CPSRLI3_H_P0_P1, MEPCOP1_48_INSN_CPSRLI3_W_P0_P1
 , MEPCOP1_48_INSN_CDSRLI3_P0_P1, MEPCOP1_48_INSN_CPSRAI3_B_P0_P1, MEPCOP1_48_INSN_CPSRAI3_H_P0_P1, MEPCOP1_48_INSN_CPSRAI3_W_P0_P1
 , MEPCOP1_48_INSN_CDSRAI3_P0_P1, MEPCOP1_48_INSN_CPSLLI3_B_P0_P1, MEPCOP1_48_INSN_CPSLLI3_H_P0_P1, MEPCOP1_48_INSN_CPSLLI3_W_P0_P1
 , MEPCOP1_48_INSN_CDSLLI3_P0_P1, MEPCOP1_48_INSN_CPSLAI3_H_P0_P1, MEPCOP1_48_INSN_CPSLAI3_W_P0_P1, MEPCOP1_48_INSN_CPCLIPIU3_W_P0_P1
 , MEPCOP1_48_INSN_CPCLIPI3_W_P0_P1, MEPCOP1_48_INSN_CDCLIPIU3_P0_P1, MEPCOP1_48_INSN_CDCLIPI3_P0_P1, MEPCOP1_48_INSN_CPMOVI_H_P0_P1
 , MEPCOP1_48_INSN_CPMOVIU_W_P0_P1, MEPCOP1_48_INSN_CPMOVI_W_P0_P1, MEPCOP1_48_INSN_CDMOVIU_P0_P1, MEPCOP1_48_INSN_CDMOVI_P0_P1
} MEPCOP1_48_INSN_TYPE;


// Forward decls.
struct mep_ext1_cpu;
struct mepcop1_48_scache;
typedef sem_status (mepcop1_48_sem_fn) (mep_ext1_cpu* cpu, mepcop1_48_scache* sem);


// Instruction descriptor.

struct mepcop1_48_idesc {

  // scache engine executor for this insn
  mepcop1_48_sem_fn* execute;

  const char* insn_name;
  enum mepcop1_48_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mepcop1_48_idesc idesc_table[];

  static mepcop1_48_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mepcop1_48_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_ivc2_5u13;
    UINT f_ivc2_imm16p0;
  } sfmt_cpmoviu_w_P0_P1;
  struct { /*  */
    INT f_ivc2_simm16p0;
    UINT f_ivc2_5u13;
  } sfmt_cpmovi_h_P0_P1;
  struct { /*  */
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;
    UINT f_ivc2_6u2;
  } sfmt_cdsrli3_P0_P1;
  struct { /*  */
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;
    UINT f_ivc2_5u3;
  } sfmt_cpsrli3_w_P0_P1;
  struct { /*  */
    UINT f_ivc2_4u4;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u23;
  } sfmt_cpsrli3_h_P0_P1;
  struct { /*  */
    UINT f_ivc2_3u5;
    UINT f_ivc2_5u13;
    UINT f_ivc2_5u18;
    UINT f_ivc2_5u23;
  } sfmt_cpfsftbi_P0_P1;
  struct { /*  */
    SI* i_ivc2rm;
    UINT f_ivc2_ccrn;
    UINT f_ivc2_crm;
    unsigned char out_ivc2rm;
  } sfmt_cmovc_rn_ccrm_p0;
  struct { /*  */
    SI* i_ivc2rm;
    UINT f_ivc2_ccrn;
    UINT f_ivc2_crm;
    unsigned char in_ivc2rm;
  } sfmt_cmovc_ccrn_rm_p0;
  struct { /*  */
    SI* i_ivc2rm;
    UINT f_ivc2_crm;
    UINT f_ivc2_crnx;
    unsigned char out_ivc2rm;
  } sfmt_cmov_rn_crm_p0;
  struct { /*  */
    SI* i_ivc2rm;
    UINT f_ivc2_crm;
    UINT f_ivc2_crnx;
    unsigned char in_ivc2rm;
  } sfmt_cmov_crn_rm_p0;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    mepcop1_48_scache* next;
    mepcop1_48_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mepcop1_48_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mepcop1_48_scache {
  // executor
  union {
    cgoto_label cgoto;
    mepcop1_48_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mepcop1_48_idesc* idesc;

  // argument buffer
  mepcop1_48_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_48_insn_word base_insn, mepcop1_48_insn_word entire_insn);
};

} // end mep_ext1 namespace

// Decls of each semantic fn.

using mep_ext1::mepcop1_48_sem_fn;
extern mepcop1_48_sem_fn mepcop1_48_sem_x_invalid;
extern mepcop1_48_sem_fn mepcop1_48_sem_cmov_crn_rm_p0;
extern mepcop1_48_sem_fn mepcop1_48_sem_cmov_rn_crm_p0;
extern mepcop1_48_sem_fn mepcop1_48_sem_cmovc_ccrn_rm_p0;
extern mepcop1_48_sem_fn mepcop1_48_sem_cmovc_rn_ccrm_p0;
extern mepcop1_48_sem_fn mepcop1_48_sem_cmovh_crn_rm_p0;
extern mepcop1_48_sem_fn mepcop1_48_sem_cmovh_rn_crm_p0;
extern mepcop1_48_sem_fn mepcop1_48_sem_c0nop_P0_P0S;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpfsftbi_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpeq_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpeq_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpeq_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpne_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpne_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpne_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgtu_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgt_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgt_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgtu_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgt_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgeu_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpge_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpge_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpgeu_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpacmpge_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpeq_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpeq_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpeq_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpne_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpne_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpne_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgtu_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgt_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgt_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgtu_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgt_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgeu_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpge_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpge_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpgeu_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpocmpge_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdadd3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsub3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsub3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsub3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdsub3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsadd3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsadd3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssub3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssub3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextuaddu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextuadd3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextladdu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextladd3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextusubu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextusub3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextlsubu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpextlsub3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpaveu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpave3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpave3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpave3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpaddsru3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpaddsr3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpaddsr3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpaddsr3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpabsu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpabs3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpabs3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpand3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpor3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpnor3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpxor3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cppacku_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cppack_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cppack_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmaxu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmax3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmax3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmaxu3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmax3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpminu3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmin3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmin3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpminu3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmin3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrl3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssrl3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrl3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssrl3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrl3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssrl3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdsrl3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsra3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssra3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsra3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssra3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsra3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssra3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdsra3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsll3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssll3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsll3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssll3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsll3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpssll3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdsll3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsla3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsla3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrli3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrli3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrli3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdsrli3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrai3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrai3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpsrai3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdsrai3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpslli3_b_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpslli3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpslli3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdslli3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpslai3_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpslai3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpclipiu3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpclipi3_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdclipiu3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdclipi3_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmovi_h_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmoviu_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cpmovi_w_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdmoviu_P0_P1;
extern mepcop1_48_sem_fn mepcop1_48_sem_cdmovi_P0_P1;

#endif /* MEPCOP1_48_DECODE_H */
