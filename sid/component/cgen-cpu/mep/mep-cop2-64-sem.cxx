/* Simulator instruction semantics for mepcop2_64.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext2.h"

using namespace mep_ext2; // FIXME: namespace organization still wip
#define GET_ATTR(name) GET_ATTR_##name ()


// ********** x-invalid: --invalid--

sem_status
mepcop2_64_sem_x_invalid (mep_ext2_cpu* current_cpu, mepcop2_64_scache* sem)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  sem_status status = SEM_STATUS_NORMAL;
  mepcop2_64_scache* abuf = sem;
  unsigned long long written = 0;
  PCADDR pc = abuf->addr;
  PCADDR npc = pc + 0;

  {
    current_cpu->invalid_insn (pc);
    assert (0);
    /* NOTREACHED */
  }

  current_cpu->done_insn (npc, status);
  return status;
#undef FLD
}

