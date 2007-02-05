/* Simulator model support for mepcop2_48.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "mep_ext2.h"

using namespace mep_ext2; // FIXME: namespace organization still wip

/* The profiling data is recorded here, but is accessed via the profiling
   mechanism.  After all, this is information for profiling.  */

/* Model handlers for each insn.  */

mepcop2_48_mep_model::mepcop2_48_mep_model (mep_ext2_cpu *cpu)
  : cgen_model (cpu)
{
}

/* We assume UNIT_NONE == 0 because the tables don't always terminate
   entries with it.  */

/* Model timing data for `mep'.  */

const mepcop2_48_mep_model::insn_timing mepcop2_48_mep_model::timing[] = {
  { MEPCOP2_48_INSN_X_INVALID, 0, 0, { { mepcop2_48_mep_model::UNIT_U_EXEC, 1, 1 } } },
};

