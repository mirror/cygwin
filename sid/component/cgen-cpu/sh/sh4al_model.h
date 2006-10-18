// sh4al_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Common insn modelling functions for all sh models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH4AL_MODEL_IMPL_H
#define SH4AL_MODEL_IMPL_H

#include "sh4a_model.h"

// Model for sh4al 
//
using namespace sh4al;

#define SH4AL_MODEL_BASE sh4a_model<sh2a_model<sh_common_model<sh4al_sh4al_model,sh4al_cpu,sh4al_idesc,sh4al_scache>,sh4al_cpu,sh4al_idesc>, \
                                    sh4al_cpu,sh4al_idesc>

class sh4al_model : public SH4AL_MODEL_BASE
{
public:
  sh4al_model (sh4al_cpu* cpu) : SH4AL_MODEL_BASE (cpu) {}
};

#endif // SH4AL_MODEL_IMPL_H
