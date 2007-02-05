/* Decode header for mepcop2_64.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP2_64_DECODE_H
#define MEPCOP2_64_DECODE_H

namespace mep_ext2 {

using namespace cgen;
using namespace mep;

typedef UINT mepcop2_64_insn_word;

/* Enum declaration for instructions in cpu family mepcop2_64.  */
typedef enum mepcop2_64_insn_type {
  MEPCOP2_64_INSN_X_INVALID
} MEPCOP2_64_INSN_TYPE;


// Forward decls.
struct mep_ext2_cpu;
struct mepcop2_64_scache;
typedef sem_status (mepcop2_64_sem_fn) (mep_ext2_cpu* cpu, mepcop2_64_scache* sem);


// Instruction descriptor.

struct mepcop2_64_idesc {

  // scache engine executor for this insn
  mepcop2_64_sem_fn* execute;

  const char* insn_name;
  enum mepcop2_64_insn_type sem_index;
  mep_insn_attr attrs;

  // idesc table: indexed by sem_index
  static mepcop2_64_idesc idesc_table[];

  static mepcop2_64_insn_type lookup_virtual (virtual_insn_type vit);
};

// Instruction argument buffer.

union mepcop2_64_sem_fields {
  struct { /* no operands */
    int empty;
  } fmt_empty;
  struct { /*  */
    int empty;
  } sfmt_empty;
  // This one is for chain/cti-chain virtual insns.
  struct {
    // Number of insns in pbb.
    unsigned insn_count;
    // This is used by chain insns and by untaken conditional branches.
    mepcop2_64_scache* next;
    mepcop2_64_scache* branch_target;
  } chain;
  // This one is for `before' virtual insns.
  struct {
    // The cache entry of the real insn.
    mepcop2_64_scache* insn;
  } before;
};

// Simulator instruction cache.

struct mepcop2_64_scache {
  // executor
  union {
    cgoto_label cgoto;
    mepcop2_64_sem_fn* fn;
  } execute;

  // PC of this instruction.
  PCADDR addr;

  // instruction class
  mepcop2_64_idesc* idesc;

  // argument buffer
  mepcop2_64_sem_fields fields;


  // writeback flags
  // Only used if profiling or parallel execution support enabled during
  // file generation.
  unsigned long long written;


  // decode given instruction
  void decode (mep_ext2_cpu* current_cpu, PCADDR pc, mepcop2_64_insn_word base_insn, mepcop2_64_insn_word entire_insn);
};

} // end mep_ext2 namespace

// Decls of each semantic fn.

using mep_ext2::mepcop2_64_sem_fn;
extern mepcop2_64_sem_fn mepcop2_64_sem_x_invalid;

#endif /* MEPCOP2_64_DECODE_H */
