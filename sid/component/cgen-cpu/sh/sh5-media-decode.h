/* Decode header for sh5_media.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef SH5_MEDIA_DECODE_H
#define SH5_MEDIA_DECODE_H

namespace sh5_media {
// forward declaration of struct in -defs.h
struct write_stacks;
}

namespace sh5 {

using namespace cgen;
using namespace sh;

typedef UINT sh5_media_insn_word;

/* Enum declaration for instructions in cpu family sh5_media.  */
typedef enum sh5_media_insn_type {
  SH5_MEDIA_INSN_X_INVALID, SH5_MEDIA_INSN_ADD, SH5_MEDIA_INSN_ADDL, SH5_MEDIA_INSN_ADDI
 , SH5_MEDIA_INSN_ADDIL, SH5_MEDIA_INSN_ADDZL, SH5_MEDIA_INSN_ALLOCO, SH5_MEDIA_INSN_AND
 , SH5_MEDIA_INSN_ANDC, SH5_MEDIA_INSN_ANDI, SH5_MEDIA_INSN_BEQ, SH5_MEDIA_INSN_BEQI
 , SH5_MEDIA_INSN_BGE, SH5_MEDIA_INSN_BGEU, SH5_MEDIA_INSN_BGT, SH5_MEDIA_INSN_BGTU
 , SH5_MEDIA_INSN_BLINK, SH5_MEDIA_INSN_BNE, SH5_MEDIA_INSN_BNEI, SH5_MEDIA_INSN_BRK
 , SH5_MEDIA_INSN_BYTEREV, SH5_MEDIA_INSN_CMPEQ, SH5_MEDIA_INSN_CMPGT, SH5_MEDIA_INSN_CMPGTU
 , SH5_MEDIA_INSN_CMVEQ, SH5_MEDIA_INSN_CMVNE, SH5_MEDIA_INSN_FABSD, SH5_MEDIA_INSN_FABSS
 , SH5_MEDIA_INSN_FADDD, SH5_MEDIA_INSN_FADDS, SH5_MEDIA_INSN_FCMPEQD, SH5_MEDIA_INSN_FCMPEQS
 , SH5_MEDIA_INSN_FCMPGED, SH5_MEDIA_INSN_FCMPGES, SH5_MEDIA_INSN_FCMPGTD, SH5_MEDIA_INSN_FCMPGTS
 , SH5_MEDIA_INSN_FCMPUND, SH5_MEDIA_INSN_FCMPUNS, SH5_MEDIA_INSN_FCNVDS, SH5_MEDIA_INSN_FCNVSD
 , SH5_MEDIA_INSN_FDIVD, SH5_MEDIA_INSN_FDIVS, SH5_MEDIA_INSN_FGETSCR, SH5_MEDIA_INSN_FIPRS
 , SH5_MEDIA_INSN_FLDD, SH5_MEDIA_INSN_FLDP, SH5_MEDIA_INSN_FLDS, SH5_MEDIA_INSN_FLDXD
 , SH5_MEDIA_INSN_FLDXP, SH5_MEDIA_INSN_FLDXS, SH5_MEDIA_INSN_FLOATLD, SH5_MEDIA_INSN_FLOATLS
 , SH5_MEDIA_INSN_FLOATQD, SH5_MEDIA_INSN_FLOATQS, SH5_MEDIA_INSN_FMACS, SH5_MEDIA_INSN_FMOVD
 , SH5_MEDIA_INSN_FMOVDQ, SH5_MEDIA_INSN_FMOVLS, SH5_MEDIA_INSN_FMOVQD, SH5_MEDIA_INSN_FMOVS
 , SH5_MEDIA_INSN_FMOVSL, SH5_MEDIA_INSN_FMULD, SH5_MEDIA_INSN_FMULS, SH5_MEDIA_INSN_FNEGD
 , SH5_MEDIA_INSN_FNEGS, SH5_MEDIA_INSN_FPUTSCR, SH5_MEDIA_INSN_FSQRTD, SH5_MEDIA_INSN_FSQRTS
 , SH5_MEDIA_INSN_FSTD, SH5_MEDIA_INSN_FSTP, SH5_MEDIA_INSN_FSTS, SH5_MEDIA_INSN_FSTXD
 , SH5_MEDIA_INSN_FSTXP, SH5_MEDIA_INSN_FSTXS, SH5_MEDIA_INSN_FSUBD, SH5_MEDIA_INSN_FSUBS
 , SH5_MEDIA_INSN_FTRCDL, SH5_MEDIA_INSN_FTRCSL, SH5_MEDIA_INSN_FTRCDQ, SH5_MEDIA_INSN_FTRCSQ
 , SH5_MEDIA_INSN_FTRVS, SH5_MEDIA_INSN_GETCFG, SH5_MEDIA_INSN_GETCON, SH5_MEDIA_INSN_GETTR
 , SH5_MEDIA_INSN_ICBI, SH5_MEDIA_INSN_LDB, SH5_MEDIA_INSN_LDL, SH5_MEDIA_INSN_LDQ
 , SH5_MEDIA_INSN_LDUB, SH5_MEDIA_INSN_LDUW, SH5_MEDIA_INSN_LDW, SH5_MEDIA_INSN_LDHIL
 , SH5_MEDIA_INSN_LDHIQ, SH5_MEDIA_INSN_LDLOL, SH5_MEDIA_INSN_LDLOQ, SH5_MEDIA_INSN_LDXB
 , SH5_MEDIA_INSN_LDXL, SH5_MEDIA_INSN_LDXQ, SH5_MEDIA_INSN_LDXUB, SH5_MEDIA_INSN_LDXUW
 , SH5_MEDIA_INSN_LDXW, SH5_MEDIA_INSN_MABSL, SH5_MEDIA_INSN_MABSW, SH5_MEDIA_INSN_MADDL
 , SH5_MEDIA_INSN_MADDW, SH5_MEDIA_INSN_MADDSL, SH5_MEDIA_INSN_MADDSUB, SH5_MEDIA_INSN_MADDSW
 , SH5_MEDIA_INSN_MCMPEQB, SH5_MEDIA_INSN_MCMPEQL, SH5_MEDIA_INSN_MCMPEQW, SH5_MEDIA_INSN_MCMPGTL
 , SH5_MEDIA_INSN_MCMPGTUB, SH5_MEDIA_INSN_MCMPGTW, SH5_MEDIA_INSN_MCMV, SH5_MEDIA_INSN_MCNVSLW
 , SH5_MEDIA_INSN_MCNVSWB, SH5_MEDIA_INSN_MCNVSWUB, SH5_MEDIA_INSN_MEXTR1, SH5_MEDIA_INSN_MEXTR2
 , SH5_MEDIA_INSN_MEXTR3, SH5_MEDIA_INSN_MEXTR4, SH5_MEDIA_INSN_MEXTR5, SH5_MEDIA_INSN_MEXTR6
 , SH5_MEDIA_INSN_MEXTR7, SH5_MEDIA_INSN_MMACFXWL, SH5_MEDIA_INSN_MMACNFX_WL, SH5_MEDIA_INSN_MMULL
 , SH5_MEDIA_INSN_MMULW, SH5_MEDIA_INSN_MMULFXL, SH5_MEDIA_INSN_MMULFXW, SH5_MEDIA_INSN_MMULFXRPW
 , SH5_MEDIA_INSN_MMULHIWL, SH5_MEDIA_INSN_MMULLOWL, SH5_MEDIA_INSN_MMULSUMWQ, SH5_MEDIA_INSN_MOVI
 , SH5_MEDIA_INSN_MPERMW, SH5_MEDIA_INSN_MSADUBQ, SH5_MEDIA_INSN_MSHALDSL, SH5_MEDIA_INSN_MSHALDSW
 , SH5_MEDIA_INSN_MSHARDL, SH5_MEDIA_INSN_MSHARDW, SH5_MEDIA_INSN_MSHARDSQ, SH5_MEDIA_INSN_MSHFHIB
 , SH5_MEDIA_INSN_MSHFHIL, SH5_MEDIA_INSN_MSHFHIW, SH5_MEDIA_INSN_MSHFLOB, SH5_MEDIA_INSN_MSHFLOL
 , SH5_MEDIA_INSN_MSHFLOW, SH5_MEDIA_INSN_MSHLLDL, SH5_MEDIA_INSN_MSHLLDW, SH5_MEDIA_INSN_MSHLRDL
 , SH5_MEDIA_INSN_MSHLRDW, SH5_MEDIA_INSN_MSUBL, SH5_MEDIA_INSN_MSUBW, SH5_MEDIA_INSN_MSUBSL
 , SH5_MEDIA_INSN_MSUBSUB, SH5_MEDIA_INSN_MSUBSW, SH5_MEDIA_INSN_MULSL, SH5_MEDIA_INSN_MULUL
 , SH5_MEDIA_INSN_NOP, SH5_MEDIA_INSN_NSB, SH5_MEDIA_INSN_OCBI, SH5_MEDIA_INSN_OCBP
 , SH5_MEDIA_INSN_OCBWB, SH5_MEDIA_INSN_OR, SH5_MEDIA_INSN_ORI, SH5_MEDIA_INSN_PREFI
 , SH5_MEDIA_INSN_PTA, SH5_MEDIA_INSN_PTABS, SH5_MEDIA_INSN_PTB, SH5_MEDIA_INSN_PTREL
 , SH5_MEDIA_INSN_PUTCFG, SH5_MEDIA_INSN_PUTCON, SH5_MEDIA_INSN_RTE, SH5_MEDIA_INSN_SHARD
 , SH5_MEDIA_INSN_SHARDL, SH5_MEDIA_INSN_SHARI, SH5_MEDIA_INSN_SHARIL, SH5_MEDIA_INSN_SHLLD
 , SH5_MEDIA_INSN_SHLLDL, SH5_MEDIA_INSN_SHLLI, SH5_MEDIA_INSN_SHLLIL, SH5_MEDIA_INSN_SHLRD
 , SH5_MEDIA_INSN_SHLRDL, SH5_MEDIA_INSN_SHLRI, SH5_MEDIA_INSN_SHLRIL, SH5_MEDIA_INSN_SHORI
 , SH5_MEDIA_INSN_SLEEP, SH5_MEDIA_INSN_STB, SH5_MEDIA_INSN_STL, SH5_MEDIA_INSN_STQ
 , SH5_MEDIA_INSN_STW, SH5_MEDIA_INSN_STHIL, SH5_MEDIA_INSN_STHIQ, SH5_MEDIA_INSN_STLOL
 , SH5_MEDIA_INSN_STLOQ, SH5_MEDIA_INSN_STXB, SH5_MEDIA_INSN_STXL, SH5_MEDIA_INSN_STXQ
 , SH5_MEDIA_INSN_STXW, SH5_MEDIA_INSN_SUB, SH5_MEDIA_INSN_SUBL, SH5_MEDIA_INSN_SWAPQ
 , SH5_MEDIA_INSN_SYNCI, SH5_MEDIA_INSN_SYNCO, SH5_MEDIA_INSN_TRAPA, SH5_MEDIA_INSN_XOR
 , SH5_MEDIA_INSN_XORI
} SH5_MEDIA_INSN_TYPE;


// Forward decls.
struct sh5_cpu;
struct sh5_media_scache;
typedef void (sh5_media_sem_fn) (sh5_cpu* cpu, sh5_media_scache* sem, int tick, sh5_media::write_stacks &buf);


// Instruction descriptor.

struct sh5_media_idesc {

  // scache engine executor for this insn
  sh5_media_sem_fn* execute;

  const char* insn_name;
  enum sh5_media_insn_type sem_index;
  sh_insn_attr attrs;

  // idesc table: indexed by sem_index
  static sh5_media_idesc idesc_table[];

  static sh5_media_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union sh5_media_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    INT f_imm16;
    UINT f_dest;
    unsigned char out_rd;
  } sfmt_movi;
  struct { /*  */
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rm;
  } sfmt_alloco;
  struct { /*  */
    UINT f_dest;
    UINT f_uimm16;
    unsigned char in_rd;
    unsigned char out_rd;
  } sfmt_shori;
  struct { /*  */
    DI f_disp16;
    UINT f_likely;
    UINT f_tra;
    unsigned char out_tra;
  } sfmt_pta;
  struct { /*  */
    UINT f_dest;
    UINT f_left_right;
    unsigned char in_frgh;
    unsigned char out_rd;
  } sfmt_fmovsl;
  struct { /*  */
    UINT f_dest;
    UINT f_left_right;
    unsigned char in_drgh;
    unsigned char out_rd;
  } sfmt_fmovdq;
  struct { /*  */
    UINT f_dest;
    UINT f_left_right;
    unsigned char in_frgh;
    unsigned char out_drf;
  } sfmt_fcnvsd;
  struct { /*  */
    UINT f_dest;
    UINT f_left_right;
    unsigned char in_drgh;
    unsigned char out_frf;
  } sfmt_fcnvds;
  struct { /*  */
    UINT f_dest;
    UINT f_left_right;
    unsigned char in_frgh;
    unsigned char out_frf;
  } sfmt_fabss;
  struct { /*  */
    UINT f_dest;
    UINT f_left_right;
    unsigned char in_drgh;
    unsigned char out_drf;
  } sfmt_fabsd;
  struct { /*  */
    UINT f_dest;
    UINT f_trb;
    unsigned char in_trb;
    unsigned char out_rd;
  } sfmt_blink;
  struct { /*  */
    INT f_imm6;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_xori;
  struct { /*  */
    SI f_disp10x2;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rd;
    unsigned char in_rm;
  } sfmt_stw;
  struct { /*  */
    SI f_disp10x8;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rd;
    unsigned char in_rm;
  } sfmt_stq;
  struct { /*  */
    SI f_disp10x4;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rd;
    unsigned char in_rm;
  } sfmt_stl;
  struct { /*  */
    INT f_disp10;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rd;
    unsigned char in_rm;
  } sfmt_stb;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_uimm6;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_shari;
  struct { /*  */
    INT f_disp6;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rd;
    unsigned char in_rm;
  } sfmt_putcfg;
  struct { /*  */
    UINT f_likely;
    UINT f_right;
    UINT f_tra;
    unsigned char in_rn;
    unsigned char out_tra;
  } sfmt_ptabs;
  struct { /*  */
    INT f_imm10;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_ori;
  struct { /*  */
    SI f_disp10x2;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_lduw;
  struct { /*  */
    SI f_disp10x8;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_ldq;
  struct { /*  */
    SI f_disp10x4;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_ldl;
  struct { /*  */
    INT f_disp6;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_getcfg;
  struct { /*  */
    SI f_disp10x4;
    UINT f_dest;
    UINT f_left;
    unsigned char in_frf;
    unsigned char in_rm;
  } sfmt_fsts;
  struct { /*  */
    SI f_disp10x8;
    UINT f_dest;
    UINT f_left;
    unsigned char in_drf;
    unsigned char in_rm;
  } sfmt_fstd;
  struct { /*  */
    SI f_disp10x4;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_frf;
  } sfmt_flds;
  struct { /*  */
    SI f_disp10x8;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_drf;
  } sfmt_fldd;
  struct { /*  */
    INT f_disp10;
    UINT f_dest;
    UINT f_left;
    unsigned char in_rm;
    unsigned char out_rd;
  } sfmt_addi;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_frf;
    unsigned char in_rm;
    unsigned char in_rn;
  } sfmt_fstxs;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_drf;
    unsigned char in_rm;
    unsigned char in_rn;
  } sfmt_fstxd;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_frf;
  } sfmt_fldxs;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_drf;
  } sfmt_fldxd;
  struct { /*  */
    SI f_disp10x8;
    UINT f_dest;
    UINT f_left;
    unsigned char in_fpf;
    unsigned char in_rm;
    unsigned char out_fpf;
  } sfmt_fldp;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_frg;
    unsigned char in_frh;
    unsigned char out_rd;
  } sfmt_fcmpeqs;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_drg;
    unsigned char in_drh;
    unsigned char out_rd;
  } sfmt_fcmpeqd;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_drg;
    unsigned char in_drh;
    unsigned char out_drf;
  } sfmt_faddd;
  struct { /*  */
    INT f_imm6;
    UINT f_left;
    UINT f_likely;
    UINT f_tra;
    unsigned char in_rm;
    unsigned char in_tra;
  } sfmt_beqi;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_rd;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_rd;
  } sfmt_mcmv;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_frf;
    unsigned char in_frg;
    unsigned char in_frh;
    unsigned char out_frf;
  } sfmt_fmacs;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_fpf;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char out_fpf;
  } sfmt_fldxp;
  struct { /*  */
    UINT f_left;
    UINT f_likely;
    UINT f_right;
    UINT f_tra;
    unsigned char in_rm;
    unsigned char in_rn;
    unsigned char in_tra;
  } sfmt_beq;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_fvg;
    unsigned char in_fvh;
    unsigned char out_frf;
    unsigned char out_fvg;
    unsigned char out_fvh;
  } sfmt_fiprs;
  struct { /*  */
    UINT f_dest;
    UINT f_left;
    UINT f_right;
    unsigned char in_fvf;
    unsigned char in_fvh;
    unsigned char in_mtrxg;
    unsigned char out_fvf;
    unsigned char out_fvh;
    unsigned char out_mtrxg;
  } sfmt_ftrvs;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    sh5_media_scache* next;
    sh5_media_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    sh5_media_scache* insn;
  } before;
};

// Simulator instruction cache.

struct sh5_media_scache {
  // executor
  union {
    cgoto_label cgoto;
    sh5_media_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  sh5_media_idesc* idesc;

  // argument buffer
  sh5_media_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (sh5_cpu* current_cpu, PCADDR pc, sh5_media_insn_word base_insn, sh5_media_insn_word entire_insn);
};

} // end sh5 namespace

// Decls of each semantic fn.

using sh5::sh5_media_sem_fn;
extern sh5_media_sem_fn sh5_media_sem_x_invalid;
extern sh5_media_sem_fn sh5_media_sem_add;
extern sh5_media_sem_fn sh5_media_sem_addl;
extern sh5_media_sem_fn sh5_media_sem_addi;
extern sh5_media_sem_fn sh5_media_sem_addil;
extern sh5_media_sem_fn sh5_media_sem_addzl;
extern sh5_media_sem_fn sh5_media_sem_alloco;
extern sh5_media_sem_fn sh5_media_sem_and;
extern sh5_media_sem_fn sh5_media_sem_andc;
extern sh5_media_sem_fn sh5_media_sem_andi;
extern sh5_media_sem_fn sh5_media_sem_beq;
extern sh5_media_sem_fn sh5_media_sem_beqi;
extern sh5_media_sem_fn sh5_media_sem_bge;
extern sh5_media_sem_fn sh5_media_sem_bgeu;
extern sh5_media_sem_fn sh5_media_sem_bgt;
extern sh5_media_sem_fn sh5_media_sem_bgtu;
extern sh5_media_sem_fn sh5_media_sem_blink;
extern sh5_media_sem_fn sh5_media_sem_bne;
extern sh5_media_sem_fn sh5_media_sem_bnei;
extern sh5_media_sem_fn sh5_media_sem_brk;
extern sh5_media_sem_fn sh5_media_sem_byterev;
extern sh5_media_sem_fn sh5_media_sem_cmpeq;
extern sh5_media_sem_fn sh5_media_sem_cmpgt;
extern sh5_media_sem_fn sh5_media_sem_cmpgtu;
extern sh5_media_sem_fn sh5_media_sem_cmveq;
extern sh5_media_sem_fn sh5_media_sem_cmvne;
extern sh5_media_sem_fn sh5_media_sem_fabsd;
extern sh5_media_sem_fn sh5_media_sem_fabss;
extern sh5_media_sem_fn sh5_media_sem_faddd;
extern sh5_media_sem_fn sh5_media_sem_fadds;
extern sh5_media_sem_fn sh5_media_sem_fcmpeqd;
extern sh5_media_sem_fn sh5_media_sem_fcmpeqs;
extern sh5_media_sem_fn sh5_media_sem_fcmpged;
extern sh5_media_sem_fn sh5_media_sem_fcmpges;
extern sh5_media_sem_fn sh5_media_sem_fcmpgtd;
extern sh5_media_sem_fn sh5_media_sem_fcmpgts;
extern sh5_media_sem_fn sh5_media_sem_fcmpund;
extern sh5_media_sem_fn sh5_media_sem_fcmpuns;
extern sh5_media_sem_fn sh5_media_sem_fcnvds;
extern sh5_media_sem_fn sh5_media_sem_fcnvsd;
extern sh5_media_sem_fn sh5_media_sem_fdivd;
extern sh5_media_sem_fn sh5_media_sem_fdivs;
extern sh5_media_sem_fn sh5_media_sem_fgetscr;
extern sh5_media_sem_fn sh5_media_sem_fiprs;
extern sh5_media_sem_fn sh5_media_sem_fldd;
extern sh5_media_sem_fn sh5_media_sem_fldp;
extern sh5_media_sem_fn sh5_media_sem_flds;
extern sh5_media_sem_fn sh5_media_sem_fldxd;
extern sh5_media_sem_fn sh5_media_sem_fldxp;
extern sh5_media_sem_fn sh5_media_sem_fldxs;
extern sh5_media_sem_fn sh5_media_sem_floatld;
extern sh5_media_sem_fn sh5_media_sem_floatls;
extern sh5_media_sem_fn sh5_media_sem_floatqd;
extern sh5_media_sem_fn sh5_media_sem_floatqs;
extern sh5_media_sem_fn sh5_media_sem_fmacs;
extern sh5_media_sem_fn sh5_media_sem_fmovd;
extern sh5_media_sem_fn sh5_media_sem_fmovdq;
extern sh5_media_sem_fn sh5_media_sem_fmovls;
extern sh5_media_sem_fn sh5_media_sem_fmovqd;
extern sh5_media_sem_fn sh5_media_sem_fmovs;
extern sh5_media_sem_fn sh5_media_sem_fmovsl;
extern sh5_media_sem_fn sh5_media_sem_fmuld;
extern sh5_media_sem_fn sh5_media_sem_fmuls;
extern sh5_media_sem_fn sh5_media_sem_fnegd;
extern sh5_media_sem_fn sh5_media_sem_fnegs;
extern sh5_media_sem_fn sh5_media_sem_fputscr;
extern sh5_media_sem_fn sh5_media_sem_fsqrtd;
extern sh5_media_sem_fn sh5_media_sem_fsqrts;
extern sh5_media_sem_fn sh5_media_sem_fstd;
extern sh5_media_sem_fn sh5_media_sem_fstp;
extern sh5_media_sem_fn sh5_media_sem_fsts;
extern sh5_media_sem_fn sh5_media_sem_fstxd;
extern sh5_media_sem_fn sh5_media_sem_fstxp;
extern sh5_media_sem_fn sh5_media_sem_fstxs;
extern sh5_media_sem_fn sh5_media_sem_fsubd;
extern sh5_media_sem_fn sh5_media_sem_fsubs;
extern sh5_media_sem_fn sh5_media_sem_ftrcdl;
extern sh5_media_sem_fn sh5_media_sem_ftrcsl;
extern sh5_media_sem_fn sh5_media_sem_ftrcdq;
extern sh5_media_sem_fn sh5_media_sem_ftrcsq;
extern sh5_media_sem_fn sh5_media_sem_ftrvs;
extern sh5_media_sem_fn sh5_media_sem_getcfg;
extern sh5_media_sem_fn sh5_media_sem_getcon;
extern sh5_media_sem_fn sh5_media_sem_gettr;
extern sh5_media_sem_fn sh5_media_sem_icbi;
extern sh5_media_sem_fn sh5_media_sem_ldb;
extern sh5_media_sem_fn sh5_media_sem_ldl;
extern sh5_media_sem_fn sh5_media_sem_ldq;
extern sh5_media_sem_fn sh5_media_sem_ldub;
extern sh5_media_sem_fn sh5_media_sem_lduw;
extern sh5_media_sem_fn sh5_media_sem_ldw;
extern sh5_media_sem_fn sh5_media_sem_ldhil;
extern sh5_media_sem_fn sh5_media_sem_ldhiq;
extern sh5_media_sem_fn sh5_media_sem_ldlol;
extern sh5_media_sem_fn sh5_media_sem_ldloq;
extern sh5_media_sem_fn sh5_media_sem_ldxb;
extern sh5_media_sem_fn sh5_media_sem_ldxl;
extern sh5_media_sem_fn sh5_media_sem_ldxq;
extern sh5_media_sem_fn sh5_media_sem_ldxub;
extern sh5_media_sem_fn sh5_media_sem_ldxuw;
extern sh5_media_sem_fn sh5_media_sem_ldxw;
extern sh5_media_sem_fn sh5_media_sem_mabsl;
extern sh5_media_sem_fn sh5_media_sem_mabsw;
extern sh5_media_sem_fn sh5_media_sem_maddl;
extern sh5_media_sem_fn sh5_media_sem_maddw;
extern sh5_media_sem_fn sh5_media_sem_maddsl;
extern sh5_media_sem_fn sh5_media_sem_maddsub;
extern sh5_media_sem_fn sh5_media_sem_maddsw;
extern sh5_media_sem_fn sh5_media_sem_mcmpeqb;
extern sh5_media_sem_fn sh5_media_sem_mcmpeql;
extern sh5_media_sem_fn sh5_media_sem_mcmpeqw;
extern sh5_media_sem_fn sh5_media_sem_mcmpgtl;
extern sh5_media_sem_fn sh5_media_sem_mcmpgtub;
extern sh5_media_sem_fn sh5_media_sem_mcmpgtw;
extern sh5_media_sem_fn sh5_media_sem_mcmv;
extern sh5_media_sem_fn sh5_media_sem_mcnvslw;
extern sh5_media_sem_fn sh5_media_sem_mcnvswb;
extern sh5_media_sem_fn sh5_media_sem_mcnvswub;
extern sh5_media_sem_fn sh5_media_sem_mextr1;
extern sh5_media_sem_fn sh5_media_sem_mextr2;
extern sh5_media_sem_fn sh5_media_sem_mextr3;
extern sh5_media_sem_fn sh5_media_sem_mextr4;
extern sh5_media_sem_fn sh5_media_sem_mextr5;
extern sh5_media_sem_fn sh5_media_sem_mextr6;
extern sh5_media_sem_fn sh5_media_sem_mextr7;
extern sh5_media_sem_fn sh5_media_sem_mmacfxwl;
extern sh5_media_sem_fn sh5_media_sem_mmacnfx_wl;
extern sh5_media_sem_fn sh5_media_sem_mmull;
extern sh5_media_sem_fn sh5_media_sem_mmulw;
extern sh5_media_sem_fn sh5_media_sem_mmulfxl;
extern sh5_media_sem_fn sh5_media_sem_mmulfxw;
extern sh5_media_sem_fn sh5_media_sem_mmulfxrpw;
extern sh5_media_sem_fn sh5_media_sem_mmulhiwl;
extern sh5_media_sem_fn sh5_media_sem_mmullowl;
extern sh5_media_sem_fn sh5_media_sem_mmulsumwq;
extern sh5_media_sem_fn sh5_media_sem_movi;
extern sh5_media_sem_fn sh5_media_sem_mpermw;
extern sh5_media_sem_fn sh5_media_sem_msadubq;
extern sh5_media_sem_fn sh5_media_sem_mshaldsl;
extern sh5_media_sem_fn sh5_media_sem_mshaldsw;
extern sh5_media_sem_fn sh5_media_sem_mshardl;
extern sh5_media_sem_fn sh5_media_sem_mshardw;
extern sh5_media_sem_fn sh5_media_sem_mshardsq;
extern sh5_media_sem_fn sh5_media_sem_mshfhib;
extern sh5_media_sem_fn sh5_media_sem_mshfhil;
extern sh5_media_sem_fn sh5_media_sem_mshfhiw;
extern sh5_media_sem_fn sh5_media_sem_mshflob;
extern sh5_media_sem_fn sh5_media_sem_mshflol;
extern sh5_media_sem_fn sh5_media_sem_mshflow;
extern sh5_media_sem_fn sh5_media_sem_mshlldl;
extern sh5_media_sem_fn sh5_media_sem_mshlldw;
extern sh5_media_sem_fn sh5_media_sem_mshlrdl;
extern sh5_media_sem_fn sh5_media_sem_mshlrdw;
extern sh5_media_sem_fn sh5_media_sem_msubl;
extern sh5_media_sem_fn sh5_media_sem_msubw;
extern sh5_media_sem_fn sh5_media_sem_msubsl;
extern sh5_media_sem_fn sh5_media_sem_msubsub;
extern sh5_media_sem_fn sh5_media_sem_msubsw;
extern sh5_media_sem_fn sh5_media_sem_mulsl;
extern sh5_media_sem_fn sh5_media_sem_mulul;
extern sh5_media_sem_fn sh5_media_sem_nop;
extern sh5_media_sem_fn sh5_media_sem_nsb;
extern sh5_media_sem_fn sh5_media_sem_ocbi;
extern sh5_media_sem_fn sh5_media_sem_ocbp;
extern sh5_media_sem_fn sh5_media_sem_ocbwb;
extern sh5_media_sem_fn sh5_media_sem_or;
extern sh5_media_sem_fn sh5_media_sem_ori;
extern sh5_media_sem_fn sh5_media_sem_prefi;
extern sh5_media_sem_fn sh5_media_sem_pta;
extern sh5_media_sem_fn sh5_media_sem_ptabs;
extern sh5_media_sem_fn sh5_media_sem_ptb;
extern sh5_media_sem_fn sh5_media_sem_ptrel;
extern sh5_media_sem_fn sh5_media_sem_putcfg;
extern sh5_media_sem_fn sh5_media_sem_putcon;
extern sh5_media_sem_fn sh5_media_sem_rte;
extern sh5_media_sem_fn sh5_media_sem_shard;
extern sh5_media_sem_fn sh5_media_sem_shardl;
extern sh5_media_sem_fn sh5_media_sem_shari;
extern sh5_media_sem_fn sh5_media_sem_sharil;
extern sh5_media_sem_fn sh5_media_sem_shlld;
extern sh5_media_sem_fn sh5_media_sem_shlldl;
extern sh5_media_sem_fn sh5_media_sem_shlli;
extern sh5_media_sem_fn sh5_media_sem_shllil;
extern sh5_media_sem_fn sh5_media_sem_shlrd;
extern sh5_media_sem_fn sh5_media_sem_shlrdl;
extern sh5_media_sem_fn sh5_media_sem_shlri;
extern sh5_media_sem_fn sh5_media_sem_shlril;
extern sh5_media_sem_fn sh5_media_sem_shori;
extern sh5_media_sem_fn sh5_media_sem_sleep;
extern sh5_media_sem_fn sh5_media_sem_stb;
extern sh5_media_sem_fn sh5_media_sem_stl;
extern sh5_media_sem_fn sh5_media_sem_stq;
extern sh5_media_sem_fn sh5_media_sem_stw;
extern sh5_media_sem_fn sh5_media_sem_sthil;
extern sh5_media_sem_fn sh5_media_sem_sthiq;
extern sh5_media_sem_fn sh5_media_sem_stlol;
extern sh5_media_sem_fn sh5_media_sem_stloq;
extern sh5_media_sem_fn sh5_media_sem_stxb;
extern sh5_media_sem_fn sh5_media_sem_stxl;
extern sh5_media_sem_fn sh5_media_sem_stxq;
extern sh5_media_sem_fn sh5_media_sem_stxw;
extern sh5_media_sem_fn sh5_media_sem_sub;
extern sh5_media_sem_fn sh5_media_sem_subl;
extern sh5_media_sem_fn sh5_media_sem_swapq;
extern sh5_media_sem_fn sh5_media_sem_synci;
extern sh5_media_sem_fn sh5_media_sem_synco;
extern sh5_media_sem_fn sh5_media_sem_trapa;
extern sh5_media_sem_fn sh5_media_sem_xor;
extern sh5_media_sem_fn sh5_media_sem_xori;

#endif /* SH5_MEDIA_DECODE_H */
