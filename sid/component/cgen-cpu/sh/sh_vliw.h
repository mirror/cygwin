// sh_vliw.h - Hand-written code for the Renesas Sh CPU. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#ifndef SH_VLIW_H
#define SH_VLIW_H

#include "sh_compact.h"
#include <vector>

namespace sh
{
  using sid::host_int_8;
  using sid::host_int_4;
  using namespace sh_compact;

  template <class SCACHE>
  class insn_info
    {
    public:
      void set_insn (SCACHE *sc) { insn = sc; }
      void set_post_fetch_latency (host_int_8 l) { post_fetch_latency = l; }
      void update_post_fetch_latency (host_int_8 l) { if (l > post_fetch_latency) post_fetch_latency = l; }
      void reduce_post_fetch_latency (host_int_4 l) { post_fetch_latency -= l; }
      void set_pc (PCADDR pcaddr) { pc = pcaddr; }
      void set_delay_slot (bool b = true) { delay_slot_p = b; }
      void set_sh5_media (bool b = true) { sh5_media_p = b; }

      host_int_8 get_post_fetch_latency () const { return post_fetch_latency; }
      SCACHE *get_insn () const { return insn; }
      PCADDR get_pc () const { return pc; }
      bool in_delay_slot () const { return delay_slot_p; }
      bool is_sh5_media () const { return sh5_media_p; }

      bool is_32_bit_insn () const { return is_sh5_media () || insn->idesc->attrs.get_32_bit_insn_attr (); }
      unsigned byte_size () const { return is_32_bit_insn () ? 4 : 2; }

      sh4_group_attr sh4_group () const { return insn->idesc->attrs.get_sh4_group_attr (); }
      sh4a_group_attr sh4a_group () const { return insn->idesc->attrs.get_sh4a_group_attr (); }
      // NOTE same as sh4a
      sh4a_group_attr sh4al_group () const { return sh4a_group (); }

    private:
      SCACHE *insn;
      host_int_8 post_fetch_latency;
      PCADDR pc;
      bool delay_slot_p;
      bool sh5_media_p;
    };

  template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
  class sh_vliw_cpu: public sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>
    {
    public:
      sh_vliw_cpu (CPU *cpu);
      ~sh_vliw_cpu () throw() {}

    private:
      virtual void step_insns ();
      sem_status step_one_insn (PCADDR pc);

    protected:
      virtual void reset();
      void reset_vliw ();

      // Insn modelling
      virtual void model_insn_before ();
      virtual UINT model_before (SCACHE *sc);
      virtual UINT model_before (sh5_media_scache *sc);
      virtual UINT model_after (SCACHE *sc);
      virtual UINT model_after (sh5_media_scache *sc);
      virtual model_status model_insn_after (UINT cycles, PCADDR &pc);
      virtual void model_step_latency (sid::host_int_4 cycles = 0);

    protected:
      bool branch_taken;
    public:
      virtual void model_branch_taken (bool taken) { branch_taken = taken; }
      bool model_branch_taken_p () { return branch_taken; }

    protected:
      void model_reduce_latency (host_int_4 l = 1) { this->model.reduce_saved_latency (l); }
      void model_branch_stall () { this->model.branch_stall (); }

      virtual void trace_counter (PCADDR pc);
      virtual void execute_insn ();
      virtual void execute_insn (SCACHE *sc) = 0;
      virtual void disassemble (PCADDR pc);

      virtual bool parallel_possible (insn_info<SCACHE> *insn1, insn_info<SCACHE> *insn2, UINT cycles) = 0;
      virtual PCADDR next_pc (insn_info<SCACHE> *insn, PCADDR pc);
      virtual PCADDR next_pc (SCACHE *sc, sid::host_int_4 cycles, insn_info<SCACHE> *insn2);
      bool is_cti_insn (SCACHE *sc);

    protected:
      bool next_insn_in_delay_slot_p;
      // TODO, use a simple array and a circular index.
      vector<insn_info<SCACHE> *> vliw_insns;
    };
};

#endif // SH_VLIW_H
