#include "mep.h"

#include "mep-defs.h"
#include "mep-decode.h"
#include "mep-model.h"

#include "common_model.h"

using namespace mep;

namespace mep_basic {

  class mep_basic_cpu: public mep_cpu_vliw<mep_basic_cpu,
    mep_scache,dummy_scache,dummy_scache,dummy_scache,dummy_scache>
  {
  public:
    mep_basic_cpu (): mep_cpu_vliw<mep_basic_cpu,mep_scache,
    dummy_scache,dummy_scache,dummy_scache,dummy_scache>
      (this,ISA_MEP,ISA_MAX,ISA_MAX,ISA_MAX,ISA_MAX),
    my_core_model (this)
      {
	// the mep-basic cpu has no uci/dsp/coprocessor
	this->insn_options[VL64] = false;
	this->insn_options[VL32] = false;
	this->insn_options[CP] = false;
	this->insn_options[DSP] = false;
	this->insn_options[UCI] = false;
      }
    ~mep_basic_cpu () throw () { }
    void core_model_insn_before (bool first_p = true) { my_core_model.model_insn_before (first_p); }
    void core_model_step_latency (sid::host_int_4 cycles = 0) { my_core_model.step_latency (cycles); }

    UINT model_before (mep_scache* sem)
      {
	UINT stall = my_core_model.model_before (this, sem);
	if (stall) update_total_latency (stall);
	return stall;
      }

    UINT model_after (mep_scache* sem) { return my_core_model.model_after (this, sem); }
    UINT model_after (dummy_scache* sem) { return 1; }

    void core_model_insn_after (bool last_p = true, UINT cycles = 1) { my_core_model.model_insn_after (last_p, cycles); }

  private:
    mep_common_model<mep_mep_model, mep_basic_cpu, mep_idesc, mep_scache> my_core_model;
  };

}
