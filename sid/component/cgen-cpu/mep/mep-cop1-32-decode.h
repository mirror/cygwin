/* Decode header for mepcop1_32.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP1_32_DECODE_H
#define MEPCOP1_32_DECODE_H

namespace mep_ext1 {

using namespace cgen;
using namespace mep;

typedef UINT mepcop1_32_insn_word;

/* Enum declaration for instructions in cpu family mepcop1_32.  */
typedef enum mepcop1_32_insn_type {
  MEPCOP1_32_INSN_X_INVALID, MEPCOP1_32_INSN_CMOV_CRN_RM, MEPCOP1_32_INSN_CMOV_RN_CRM, MEPCOP1_32_INSN_CMOVC_CCRN_RM
 , MEPCOP1_32_INSN_CMOVC_RN_CCRM, MEPCOP1_32_INSN_CMOVH_CRN_RM, MEPCOP1_32_INSN_CMOVH_RN_CRM, MEPCOP1_32_INSN_CPADD3_B_C3
 , MEPCOP1_32_INSN_CPADD3_H_C3, MEPCOP1_32_INSN_CPADD3_W_C3, MEPCOP1_32_INSN_CDADD3_C3, MEPCOP1_32_INSN_CPSUB3_B_C3
 , MEPCOP1_32_INSN_CPSUB3_H_C3, MEPCOP1_32_INSN_CPSUB3_W_C3, MEPCOP1_32_INSN_CDSUB3_C3, MEPCOP1_32_INSN_CPAND3_C3
 , MEPCOP1_32_INSN_CPOR3_C3, MEPCOP1_32_INSN_CPNOR3_C3, MEPCOP1_32_INSN_CPXOR3_C3, MEPCOP1_32_INSN_CPSEL_C3
 , MEPCOP1_32_INSN_CPFSFTBI_C3, MEPCOP1_32_INSN_CPFSFTBS0_C3, MEPCOP1_32_INSN_CPFSFTBS1_C3, MEPCOP1_32_INSN_CPUNPACKU_B_C3
 , MEPCOP1_32_INSN_CPUNPACKU_H_C3, MEPCOP1_32_INSN_CPUNPACKU_W_C3, MEPCOP1_32_INSN_CPUNPACKL_B_C3, MEPCOP1_32_INSN_CPUNPACKL_H_C3
 , MEPCOP1_32_INSN_CPUNPACKL_W_C3, MEPCOP1_32_INSN_CPPACKU_B_C3, MEPCOP1_32_INSN_CPPACK_B_C3, MEPCOP1_32_INSN_CPPACK_H_C3
 , MEPCOP1_32_INSN_CPSRL3_B_C3, MEPCOP1_32_INSN_CPSSRL3_B_C3, MEPCOP1_32_INSN_CPSRL3_H_C3, MEPCOP1_32_INSN_CPSSRL3_H_C3
 , MEPCOP1_32_INSN_CPSRL3_W_C3, MEPCOP1_32_INSN_CPSSRL3_W_C3, MEPCOP1_32_INSN_CDSRL3_C3, MEPCOP1_32_INSN_CPSRA3_B_C3
 , MEPCOP1_32_INSN_CPSSRA3_B_C3, MEPCOP1_32_INSN_CPSRA3_H_C3, MEPCOP1_32_INSN_CPSSRA3_H_C3, MEPCOP1_32_INSN_CPSRA3_W_C3
 , MEPCOP1_32_INSN_CPSSRA3_W_C3, MEPCOP1_32_INSN_CDSRA3_C3, MEPCOP1_32_INSN_CPSLL3_B_C3, MEPCOP1_32_INSN_CPSSLL3_B_C3
 , MEPCOP1_32_INSN_CPSLL3_H_C3, MEPCOP1_32_INSN_CPSSLL3_H_C3, MEPCOP1_32_INSN_CPSLL3_W_C3, MEPCOP1_32_INSN_CPSSLL3_W_C3
 , MEPCOP1_32_INSN_CDSLL3_C3, MEPCOP1_32_INSN_CPSLA3_H_C3, MEPCOP1_32_INSN_CPSLA3_W_C3, MEPCOP1_32_INSN_CPSADD3_H_C3
 , MEPCOP1_32_INSN_CPSADD3_W_C3, MEPCOP1_32_INSN_CPSSUB3_H_C3, MEPCOP1_32_INSN_CPSSUB3_W_C3, MEPCOP1_32_INSN_CPEXTUADDU3_B_C3
 , MEPCOP1_32_INSN_CPEXTUADD3_B_C3, MEPCOP1_32_INSN_CPEXTLADDU3_B_C3, MEPCOP1_32_INSN_CPEXTLADD3_B_C3, MEPCOP1_32_INSN_CPEXTUSUBU3_B_C3
 , MEPCOP1_32_INSN_CPEXTUSUB3_B_C3, MEPCOP1_32_INSN_CPEXTLSUBU3_B_C3, MEPCOP1_32_INSN_CPEXTLSUB3_B_C3, MEPCOP1_32_INSN_CPAVEU3_B_C3
 , MEPCOP1_32_INSN_CPAVE3_B_C3, MEPCOP1_32_INSN_CPAVE3_H_C3, MEPCOP1_32_INSN_CPAVE3_W_C3, MEPCOP1_32_INSN_CPADDSRU3_B_C3
 , MEPCOP1_32_INSN_CPADDSR3_B_C3, MEPCOP1_32_INSN_CPADDSR3_H_C3, MEPCOP1_32_INSN_CPADDSR3_W_C3, MEPCOP1_32_INSN_CPABSU3_B_C3
 , MEPCOP1_32_INSN_CPABS3_B_C3, MEPCOP1_32_INSN_CPABS3_H_C3, MEPCOP1_32_INSN_CPMAXU3_B_C3, MEPCOP1_32_INSN_CPMAX3_B_C3
 , MEPCOP1_32_INSN_CPMAX3_H_C3, MEPCOP1_32_INSN_CPMAXU3_W_C3, MEPCOP1_32_INSN_CPMAX3_W_C3, MEPCOP1_32_INSN_CPMINU3_B_C3
 , MEPCOP1_32_INSN_CPMIN3_B_C3, MEPCOP1_32_INSN_CPMIN3_H_C3, MEPCOP1_32_INSN_CPMINU3_W_C3, MEPCOP1_32_INSN_CPMIN3_W_C3
 , MEPCOP1_32_INSN_CPMOVFRCSAR0_C3, MEPCOP1_32_INSN_CPMOVFRCSAR1_C3, MEPCOP1_32_INSN_CPMOVFRCC_C3, MEPCOP1_32_INSN_CPMOVTOCSAR0_C3
 , MEPCOP1_32_INSN_CPMOVTOCSAR1_C3, MEPCOP1_32_INSN_CPMOVTOCC_C3, MEPCOP1_32_INSN_CPMOV_C3, MEPCOP1_32_INSN_CPABSZ_B_C3
 , MEPCOP1_32_INSN_CPABSZ_H_C3, MEPCOP1_32_INSN_CPABSZ_W_C3, MEPCOP1_32_INSN_CPLDZ_H_C3, MEPCOP1_32_INSN_CPLDZ_W_C3
 , MEPCOP1_32_INSN_CPNORM_H_C3, MEPCOP1_32_INSN_CPNORM_W_C3, MEPCOP1_32_INSN_CPHADDU_B_C3, MEPCOP1_32_INSN_CPHADD_B_C3
 , MEPCOP1_32_INSN_CPHADD_H_C3, MEPCOP1_32_INSN_CPHADD_W_C3, MEPCOP1_32_INSN_CPCCADD_B_C3, MEPCOP1_32_INSN_CPBCAST_B_C3
 , MEPCOP1_32_INSN_CPBCAST_H_C3, MEPCOP1_32_INSN_CPBCAST_W_C3, MEPCOP1_32_INSN_CPEXTUU_B_C3, MEPCOP1_32_INSN_CPEXTU_B_C3
 , MEPCOP1_32_INSN_CPEXTUU_H_C3, MEPCOP1_32_INSN_CPEXTU_H_C3, MEPCOP1_32_INSN_CPEXTLU_B_C3, MEPCOP1_32_INSN_CPEXTL_B_C3
 , MEPCOP1_32_INSN_CPEXTLU_H_C3, MEPCOP1_32_INSN_CPEXTL_H_C3, MEPCOP1_32_INSN_CPCASTUB_H_C3, MEPCOP1_32_INSN_CPCASTB_H_C3
 , MEPCOP1_32_INSN_CPCASTUB_W_C3, MEPCOP1_32_INSN_CPCASTB_W_C3, MEPCOP1_32_INSN_CPCASTUH_W_C3, MEPCOP1_32_INSN_CPCASTH_W_C3
 , MEPCOP1_32_INSN_CDCASTUW_C3, MEPCOP1_32_INSN_CDCASTW_C3, MEPCOP1_32_INSN_CPCMPEQZ_B_C3, MEPCOP1_32_INSN_CPCMPEQ_B_C3
 , MEPCOP1_32_INSN_CPCMPEQ_H_C3, MEPCOP1_32_INSN_CPCMPEQ_W_C3, MEPCOP1_32_INSN_CPCMPNE_B_C3, MEPCOP1_32_INSN_CPCMPNE_H_C3
 , MEPCOP1_32_INSN_CPCMPNE_W_C3, MEPCOP1_32_INSN_CPCMPGTU_B_C3, MEPCOP1_32_INSN_CPCMPGT_B_C3, MEPCOP1_32_INSN_CPCMPGT_H_C3
 , MEPCOP1_32_INSN_CPCMPGTU_W_C3, MEPCOP1_32_INSN_CPCMPGT_W_C3, MEPCOP1_32_INSN_CPCMPGEU_B_C3, MEPCOP1_32_INSN_CPCMPGE_B_C3
 , MEPCOP1_32_INSN_CPCMPGE_H_C3, MEPCOP1_32_INSN_CPCMPGEU_W_C3, MEPCOP1_32_INSN_CPCMPGE_W_C3, MEPCOP1_32_INSN_CPACMPEQ_B_C3
 , MEPCOP1_32_INSN_CPACMPEQ_H_C3, MEPCOP1_32_INSN_CPACMPEQ_W_C3, MEPCOP1_32_INSN_CPACMPNE_B_C3, MEPCOP1_32_INSN_CPACMPNE_H_C3
 , MEPCOP1_32_INSN_CPACMPNE_W_C3, MEPCOP1_32_INSN_CPACMPGTU_B_C3, MEPCOP1_32_INSN_CPACMPGT_B_C3, MEPCOP1_32_INSN_CPACMPGT_H_C3
 , MEPCOP1_32_INSN_CPACMPGTU_W_C3, MEPCOP1_32_INSN_CPACMPGT_W_C3, MEPCOP1_32_INSN_CPACMPGEU_B_C3, MEPCOP1_32_INSN_CPACMPGE_B_C3
 , MEPCOP1_32_INSN_CPACMPGE_H_C3, MEPCOP1_32_INSN_CPACMPGEU_W_C3, MEPCOP1_32_INSN_CPACMPGE_W_C3, MEPCOP1_32_INSN_CPOCMPEQ_B_C3
 , MEPCOP1_32_INSN_CPOCMPEQ_H_C3, MEPCOP1_32_INSN_CPOCMPEQ_W_C3, MEPCOP1_32_INSN_CPOCMPNE_B_C3, MEPCOP1_32_INSN_CPOCMPNE_H_C3
 , MEPCOP1_32_INSN_CPOCMPNE_W_C3, MEPCOP1_32_INSN_CPOCMPGTU_B_C3, MEPCOP1_32_INSN_CPOCMPGT_B_C3, MEPCOP1_32_INSN_CPOCMPGT_H_C3
 , MEPCOP1_32_INSN_CPOCMPGTU_W_C3, MEPCOP1_32_INSN_CPOCMPGT_W_C3, MEPCOP1_32_INSN_CPOCMPGEU_B_C3, MEPCOP1_32_INSN_CPOCMPGE_B_C3
 , MEPCOP1_32_INSN_CPOCMPGE_H_C3, MEPCOP1_32_INSN_CPOCMPGEU_W_C3, MEPCOP1_32_INSN_CPOCMPGE_W_C3, MEPCOP1_32_INSN_CPSRLI3_B_C3
 , MEPCOP1_32_INSN_CPSRLI3_H_C3, MEPCOP1_32_INSN_CPSRLI3_W_C3, MEPCOP1_32_INSN_CDSRLI3_C3, MEPCOP1_32_INSN_CPSRAI3_B_C3
 , MEPCOP1_32_INSN_CPSRAI3_H_C3, MEPCOP1_32_INSN_CPSRAI3_W_C3, MEPCOP1_32_INSN_CDSRAI3_C3, MEPCOP1_32_INSN_CPSLLI3_B_C3
 , MEPCOP1_32_INSN_CPSLLI3_H_C3, MEPCOP1_32_INSN_CPSLLI3_W_C3, MEPCOP1_32_INSN_CDSLLI3_C3, MEPCOP1_32_INSN_CPSLAI3_H_C3
 , MEPCOP1_32_INSN_CPSLAI3_W_C3, MEPCOP1_32_INSN_CPCLIPIU3_W_C3, MEPCOP1_32_INSN_CPCLIPI3_W_C3, MEPCOP1_32_INSN_CDCLIPIU3_C3
 , MEPCOP1_32_INSN_CDCLIPI3_C3, MEPCOP1_32_INSN_CPMOVI_B_C3, MEPCOP1_32_INSN_CPMOVIU_H_C3, MEPCOP1_32_INSN_CPMOVI_H_C3
 , MEPCOP1_32_INSN_CPMOVIU_W_C3, MEPCOP1_32_INSN_CPMOVI_W_C3, MEPCOP1_32_INSN_CDMOVIU_C3, MEPCOP1_32_INSN_CDMOVI_C3
 , MEPCOP1_32_INSN_CPADDA1U_B_C3, MEPCOP1_32_INSN_CPADDA1_B_C3, MEPCOP1_32_INSN_CPADDUA1_H_C3, MEPCOP1_32_INSN_CPADDLA1_H_C3
 , MEPCOP1_32_INSN_CPADDACA1U_B_C3, MEPCOP1_32_INSN_CPADDACA1_B_C3, MEPCOP1_32_INSN_CPADDACUA1_H_C3, MEPCOP1_32_INSN_CPADDACLA1_H_C3
 , MEPCOP1_32_INSN_CPSUBA1U_B_C3, MEPCOP1_32_INSN_CPSUBA1_B_C3, MEPCOP1_32_INSN_CPSUBUA1_H_C3, MEPCOP1_32_INSN_CPSUBLA1_H_C3
 , MEPCOP1_32_INSN_CPSUBACA1U_B_C3, MEPCOP1_32_INSN_CPSUBACA1_B_C3, MEPCOP1_32_INSN_CPSUBACUA1_H_C3, MEPCOP1_32_INSN_CPSUBACLA1_H_C3
 , MEPCOP1_32_INSN_CPABSA1U_B_C3, MEPCOP1_32_INSN_CPABSA1_B_C3, MEPCOP1_32_INSN_CPABSUA1_H_C3, MEPCOP1_32_INSN_CPABSLA1_H_C3
 , MEPCOP1_32_INSN_CPSADA1U_B_C3, MEPCOP1_32_INSN_CPSADA1_B_C3, MEPCOP1_32_INSN_CPSADUA1_H_C3, MEPCOP1_32_INSN_CPSADLA1_H_C3
 , MEPCOP1_32_INSN_CPSETA1_H_C3, MEPCOP1_32_INSN_CPSETUA1_W_C3, MEPCOP1_32_INSN_CPSETLA1_W_C3, MEPCOP1_32_INSN_CPMOVA1_B_C3
 , MEPCOP1_32_INSN_CPMOVUA1_H_C3, MEPCOP1_32_INSN_CPMOVLA1_H_C3, MEPCOP1_32_INSN_CPMOVUUA1_W_C3, MEPCOP1_32_INSN_CPMOVULA1_W_C3
 , MEPCOP1_32_INSN_CPMOVLUA1_W_C3, MEPCOP1_32_INSN_CPMOVLLA1_W_C3, MEPCOP1_32_INSN_CPPACKA1U_B_C3, MEPCOP1_32_INSN_CPPACKA1_B_C3
 , MEPCOP1_32_INSN_CPPACKUA1_H_C3, MEPCOP1_32_INSN_CPPACKLA1_H_C3, MEPCOP1_32_INSN_CPPACKUA1_W_C3, MEPCOP1_32_INSN_CPPACKLA1_W_C3
 , MEPCOP1_32_INSN_CPMOVHUA1_W_C3, MEPCOP1_32_INSN_CPMOVHLA1_W_C3, MEPCOP1_32_INSN_CPSRLA1_C3, MEPCOP1_32_INSN_CPSRAA1_C3
 , MEPCOP1_32_INSN_CPSLLA1_C3, MEPCOP1_32_INSN_CPSRLIA1_P1, MEPCOP1_32_INSN_CPSRAIA1_P1, MEPCOP1_32_INSN_CPSLLIA1_P1
 , MEPCOP1_32_INSN_CPSSQA1U_B_C3, MEPCOP1_32_INSN_CPSSQA1_B_C3, MEPCOP1_32_INSN_CPSSDA1U_B_C3, MEPCOP1_32_INSN_CPSSDA1_B_C3
 , MEPCOP1_32_INSN_CPMULA1U_B_C3, MEPCOP1_32_INSN_CPMULA1_B_C3, MEPCOP1_32_INSN_CPMULUA1_H_C3, MEPCOP1_32_INSN_CPMULLA1_H_C3
 , MEPCOP1_32_INSN_CPMULUA1U_W_C3, MEPCOP1_32_INSN_CPMULLA1U_W_C3, MEPCOP1_32_INSN_CPMULUA1_W_C3, MEPCOP1_32_INSN_CPMULLA1_W_C3
 , MEPCOP1_32_INSN_CPMADA1U_B_C3, MEPCOP1_32_INSN_CPMADA1_B_C3, MEPCOP1_32_INSN_CPMADUA1_H_C3, MEPCOP1_32_INSN_CPMADLA1_H_C3
 , MEPCOP1_32_INSN_CPMADUA1U_W_C3, MEPCOP1_32_INSN_CPMADLA1U_W_C3, MEPCOP1_32_INSN_CPMADUA1_W_C3, MEPCOP1_32_INSN_CPMADLA1_W_C3
 , MEPCOP1_32_INSN_CPMSBUA1_H_C3, MEPCOP1_32_INSN_CPMSBLA1_H_C3, MEPCOP1_32_INSN_CPMSBUA1U_W_C3, MEPCOP1_32_INSN_CPMSBLA1U_W_C3
 , MEPCOP1_32_INSN_CPMSBUA1_W_C3, MEPCOP1_32_INSN_CPMSBLA1_W_C3, MEPCOP1_32_INSN_CPSMADUA1_H_C3, MEPCOP1_32_INSN_CPSMADLA1_H_C3
 , MEPCOP1_32_INSN_CPSMADUA1_W_C3, MEPCOP1_32_INSN_CPSMADLA1_W_C3, MEPCOP1_32_INSN_CPSMSBUA1_H_C3, MEPCOP1_32_INSN_CPSMSBLA1_H_C3
 , MEPCOP1_32_INSN_CPSMSBUA1_W_C3, MEPCOP1_32_INSN_CPSMSBLA1_W_C3, MEPCOP1_32_INSN_CPMULSLUA1_H_C3, MEPCOP1_32_INSN_CPMULSLLA1_H_C3
 , MEPCOP1_32_INSN_CPMULSLUA1_W_C3, MEPCOP1_32_INSN_CPMULSLLA1_W_C3, MEPCOP1_32_INSN_CPSMADSLUA1_H_C3, MEPCOP1_32_INSN_CPSMADSLLA1_H_C3
 , MEPCOP1_32_INSN_CPSMADSLUA1_W_C3, MEPCOP1_32_INSN_CPSMADSLLA1_W_C3, MEPCOP1_32_INSN_CPSMSBSLUA1_H_C3, MEPCOP1_32_INSN_CPSMSBSLLA1_H_C3
 , MEPCOP1_32_INSN_CPSMSBSLUA1_W_C3, MEPCOP1_32_INSN_CPSMSBSLLA1_W_C3
} MEPCOP1_32_INSN_TYPE;


// Forward decls.
struct mep_ext1_cpu;
struct mepcop1_32_scache;
typedef sem_status (mepcop1_32_sem_fn) (mep_ext1_cpu* cpu, mepcop1_32_scache* sem);


// Instruction descriptor.

struct mepcop1_32_idesc {

  // scache engine executor for this insn
  mepcop1_32_sem_fn* execute;

  const char* insn_name;
  enum mepcop1_32_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mepcop1_32_idesc idesc_table[];

  static mepcop1_32_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mepcop1_32_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    UINT f_ivc2_5u21;
    UINT f_ivc2_8u4;
  } sfmt_cpmoviu_h_C3;
  struct { /*  */
    INT f_ivc2_8s4;
    UINT f_ivc2_5u21;
  } sfmt_cpmovi_b_C3;
  struct { /*  */
    UINT f_ivc2_5u21;
    UINT f_ivc2_5u26;
    UINT f_ivc2_6u6;
  } sfmt_cdsrli3_C3;
  struct { /*  */
    UINT f_ivc2_4u8;
    UINT f_ivc2_5u21;
    UINT f_ivc2_5u26;
  } sfmt_cpsrli3_h_C3;
  struct { /*  */
    UINT f_ivc2_3u9;
    UINT f_ivc2_5u21;
    UINT f_ivc2_5u26;
  } sfmt_cpsrli3_b_C3;
  struct { /*  */
    UINT f_ivc2_3u4;
    UINT f_ivc2_5u21;
    UINT f_ivc2_5u26;
    UINT f_ivc2_5u7;
  } sfmt_cpfsftbi_C3;
  struct { /*  */
    SI* i_rm;
    UINT f_ivc2_ccrn_c3;
    UINT f_rm;
    unsigned char out_rm;
  } sfmt_cmovc_rn_ccrm;
  struct { /*  */
    SI* i_rm;
    UINT f_ivc2_ccrn_c3;
    UINT f_rm;
    unsigned char in_rm;
  } sfmt_cmovc_ccrn_rm;
  struct { /*  */
    SI* i_rm;
    UINT f_crnx;
    UINT f_rm;
    unsigned char out_rm;
  } sfmt_cmov_rn_crm;
  struct { /*  */
    SI* i_rm;
    UINT f_crnx;
    UINT f_rm;
    unsigned char in_rm;
  } sfmt_cmov_crn_rm;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    mepcop1_32_scache* next;
    mepcop1_32_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mepcop1_32_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mepcop1_32_scache {
  // executor
  union {
    cgoto_label cgoto;
    mepcop1_32_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mepcop1_32_idesc* idesc;

  // argument buffer
  mepcop1_32_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_ext1_cpu* current_cpu, PCADDR pc, mepcop1_32_insn_word base_insn, mepcop1_32_insn_word entire_insn);
};

} // end mep_ext1 namespace

// Decls of each semantic fn.

using mep_ext1::mepcop1_32_sem_fn;
extern mepcop1_32_sem_fn mepcop1_32_sem_x_invalid;
extern mepcop1_32_sem_fn mepcop1_32_sem_cmov_crn_rm;
extern mepcop1_32_sem_fn mepcop1_32_sem_cmov_rn_crm;
extern mepcop1_32_sem_fn mepcop1_32_sem_cmovc_ccrn_rm;
extern mepcop1_32_sem_fn mepcop1_32_sem_cmovc_rn_ccrm;
extern mepcop1_32_sem_fn mepcop1_32_sem_cmovh_crn_rm;
extern mepcop1_32_sem_fn mepcop1_32_sem_cmovh_rn_crm;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpadd3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpadd3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpadd3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdadd3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsub3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsub3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsub3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdsub3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpand3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpor3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpnor3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpxor3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsel_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpfsftbi_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpfsftbs0_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpfsftbs1_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpunpacku_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpunpacku_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpunpacku_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpunpackl_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpunpackl_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpunpackl_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppacku_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppack_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppack_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrl3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssrl3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrl3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssrl3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrl3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssrl3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdsrl3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsra3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssra3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsra3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssra3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsra3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssra3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdsra3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsll3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssll3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsll3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssll3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsll3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssll3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdsll3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsla3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsla3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsadd3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsadd3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssub3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssub3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextuaddu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextuadd3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextladdu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextladd3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextusubu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextusub3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextlsubu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextlsub3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaveu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpave3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpave3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpave3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddsru3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddsr3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddsr3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddsr3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabs3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabs3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmaxu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmax3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmax3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmaxu3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmax3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpminu3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmin3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmin3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpminu3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmin3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovfrcsar0_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovfrcsar1_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovfrcc_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovtocsar0_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovtocsar1_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovtocc_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmov_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsz_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsz_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsz_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpldz_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpldz_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpnorm_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpnorm_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cphaddu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cphadd_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cphadd_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cphadd_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpccadd_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpbcast_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpbcast_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpbcast_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextuu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextuu_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextu_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextlu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextl_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextlu_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpextl_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcastub_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcastb_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcastub_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcastb_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcastuh_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcasth_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdcastuw_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdcastw_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpeqz_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpeq_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpeq_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpeq_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpne_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpne_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpne_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgtu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgt_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgt_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgtu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgt_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgeu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpge_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpge_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpgeu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpcmpge_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpeq_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpeq_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpeq_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpne_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpne_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpne_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgtu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgt_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgt_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgtu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgt_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgeu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpge_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpge_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpgeu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpacmpge_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpeq_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpeq_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpeq_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpne_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpne_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpne_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgtu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgt_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgt_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgtu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgt_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgeu_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpge_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpge_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpgeu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpocmpge_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrli3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrli3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrli3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdsrli3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrai3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrai3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrai3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdsrai3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpslli3_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpslli3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpslli3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdslli3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpslai3_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpslai3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpclipiu3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpclipi3_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdclipiu3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdclipi3_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovi_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmoviu_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovi_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmoviu_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovi_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdmoviu_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cdmovi_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpadda1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpadda1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddaca1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddaca1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddacua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpaddacla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsuba1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsuba1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsubua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsubla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsubaca1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsubaca1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsubacua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsubacla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsa1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsa1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpabsla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsada1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsada1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsadua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsadla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpseta1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsetua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsetla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmova1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovuua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovula1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovlua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovlla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppacka1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppacka1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppackua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppackla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppackua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cppackla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovhua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmovhla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrla1_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsraa1_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpslla1_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsrlia1_P1;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsraia1_P1;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsllia1_P1;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssqa1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssqa1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssda1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpssda1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmula1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmula1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulua1u_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulla1u_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmada1u_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmada1_b_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmadua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmadla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmadua1u_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmadla1u_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmadua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmadla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmsbua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmsbla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmsbua1u_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmsbla1u_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmsbua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmsbla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulslua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulslla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulslua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpmulslla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadslua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadslla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadslua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmadslla1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbslua1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbslla1_h_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbslua1_w_C3;
extern mepcop1_32_sem_fn mepcop1_32_sem_cpsmsbslla1_w_C3;

#endif /* MEPCOP1_32_DECODE_H */
