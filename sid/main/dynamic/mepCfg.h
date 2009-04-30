// mepCfg.h - configuration for MeP.  -*- C++ -*-

// Copyright (C) 2002-2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef __mepCfg_h__
#define __mepCfg_h__

#include "commonCfg.h"

class MepMemCfg;
class MepCacheCfg;
class MepDMACCfg;
class MepDSUCfg;
class MepINTCCfg;
class MepMM_INTCfg;
class MepTimerCfg;
class MepHWengineCfg;
class MepToshapiHWengineCfg;
class MepMemRegionCfg;
class MepBusArbitratorCfg;

// The values are significant. They represent the value of the ID field of the
// ID register.
#define MEP_CORE_MEP     0x00
#define MEP_CORE_C2      0x02
#define MEP_CORE_C3      0x03
#define MEP_CORE_C4      0x04
#define MEP_CORE_C5      0x08
#define MEP_CORE_H1      0x10

class MepBoardCfg :
  virtual public BoardCfg
{
 public:
  MepBoardCfg (const string name, 
	       const string type,
	       SessionCfg *sess);    
  virtual ~MepBoardCfg ();
  static MepMemCfg *shared_main_mem;  
  static MepMM_INTCfg *shared_mm_int;  
  static const sid::host_int_4 localmem_base = 0x200000;
  static const sid::host_int_4 imem_dmem_base = 0x200000;
  static const sid::host_int_4 imem_dmem_size = 0x100000;
  static const sid::host_int_4 dmem_max_banks = 4;
  static const sid::host_int_4 icache_lines_address = 0x300000;
  static const sid::host_int_4 icache_tags_address  = 0x310000;
  static const sid::host_int_4 dcache_lines_address = 0x320000;
  static const sid::host_int_4 dcache_tags_address  = 0x330000;

  void set_module_type (const string ty);
  string get_module_type ();
  void set_endian (const string endian);

  AtomicCfg *get_local_shadow_bit_insn_probe () { return local_shadow_bit_insn_probe; }

  // this could all be handled more dynamically, say using a single setter
  // function and a table of options, but assuming that we're aiming for
  // static detection of errors in config files, we may as well push it
  // back to compile time.

  MepMemRegionCfg * allocate_local_mem (sid::host_int_4 start, 
				       sid::host_int_4 size,
				       const char *name = 0);
  void add_local_mem (sid::host_int_4 start, 
		      sid::host_int_4 size,
		      const char *name = 0,
		      bool is_toshapi = false);
  void add_toshapi_local_mem (const string name, MepMemRegionCfg *lmem);

  void map_local_mem (MepMemRegionCfg *mem);
  MepMemRegionCfg *map_local_mem (sid::host_int_4 start, sid::host_int_4 size);

  MepMemRegionCfg *find_local_mem (const string name);

  virtual void add_memory (const Mapping &m);
  void add_hw_engine (const string type, 
		      sid::host_int_4 cbus_addr, 
		      int lbus_if,
		      sid::host_int_4 lbus_addr,
		      sid::host_int_4 lbus_size,
		      const char *local_mem_list);
  map<string, MepHWengineCfg*> hwe;
  MepToshapiHWengineCfg *add_toshapi_hw_engine (const string type,
						const string instance,
						sid::host_int_4 cbus_addr, 
						int lbus_if,
						sid::host_int_4 lbus_addr,
						sid::host_int_4 lbus_size,
						const char *local_mem_list);

  void add_dsp (const string type, 
		int cbus_if,
		int lbus_if,
		sid::host_int_4 lbus_addr,
		sid::host_int_4 lbus_size,
		int dmem_if_width,
		const char *local_mem_list);

  MepToshapiHWengineCfg *add_toshapi_dsp (const string type, 
					  const string instance,
					  int cbus_if,
					  int lbus_if,
					  sid::host_int_4 lbus_addr,
					  sid::host_int_4 lbus_size,
					  int dmem_if_width,
					  const char *local_mem_list);

  void add_toshapi_uci (const string type, const string instance);
  void add_toshapi_global_bus_if_model (const string type, const string instance);
  void add_toshapi_local_bus_model (const string type, const string instance);

  void add_cop (const string name, int cbus_if);
  void set_ivc2_decode (bool enabled);
  void allocate_dmac ();
  void add_dmac (int channel_bitw, int data_width, bool rectangle);
  void configure_dmac ();
  void add_timer (int channel_bitw);
  void allocate_timer (int channel_bitw);
  void configure_timer ();

  struct MepIrq {
    int irq_type;
    string src_mod;
    string dest_mod;
    string instance;
    string signal;
    int channel;
  };
  static vector<MepIrq> irq_specs;

  void add_irq_board ();
  void add_irq (int irq_type, const string src_mod, const string dest_mod, const string instance, const string signal,
		int engine_idx, int channel);
  void configure_irqs (Writer &w);
  void configure_irq (const MepIrq &irq, Writer &w);

  void add_exit_location ();

  bool shadow_covers_local_region (sid::host_int_4 s_base, sid::host_int_4 s_base_end,
				   sid::host_int_4 &offset, sid::host_int_4 &size, bool &is_dmem);

  virtual void set_loader (LoaderCfg *l);

  void set_core_type (int t);
  void set_core_id (sid::host_int_4 i);
  void set_imem_size (sid::host_int_4 v);
  void set_dmem_bank_num (sid::host_int_4 v);
  void set_dmem_size (sid::host_int_4 v);
  void set_dmem_fixed_start_address (bool b);
  void set_icache_size (sid::host_int_4 v);
  void set_icache_line_size (sid::host_int_4 v);
  void set_icache_way (sid::host_int_4 v);
  void set_icache_cwf (bool b);
  void set_dcache_size (sid::host_int_4 v);
  void set_dcache_line_size (sid::host_int_4 v);
  void set_dcache_way (sid::host_int_4 v);
  void set_dcache_cwf (bool b);
  void set_intc_channel_bitw (sid::host_int_4 v);
  void set_intc_level (sid::host_int_4 v);
  void intc_set (const string& name, const string& value);

  void map_imem_dmem ();
  void map_mm_int ();

  void set_opt_cp (bool b);
  void set_opt_dsu (bool b);
  void set_opt_dsp (bool b);
  void set_opt_uci (bool b);
  void set_opt_biu (unsigned data_width);
  void set_cop_vliw_bitw (sid::host_int_4 v);
  void set_cop_data_bus_width (sid::host_int_4 v);
  void set_cop_ccr (unsigned regno, sid::host_int_4 v);

  void set_opt_abs (bool b);
  void set_opt_ave (bool b);
  void set_opt_bit (bool b);
  void set_opt_clp (bool b);
  void set_opt_div (bool b);
  void set_opt_ldz (bool b);
  void set_opt_min (bool b);
  void set_opt_mul (bool b);
  void set_opt_sat (bool b);

  virtual void set_config_index (unsigned i = 0) { config_index = i; }
  virtual void set_warn_write_to_code (bool b = true);
  virtual void set_warn_write_to_rom (bool b = true) { warn_write_to_rom = b; };
  virtual void set_allow_write_to_rom (bool b = true) { allow_write_to_rom = b; };
  virtual void set_model_busses (bool b = true);
  virtual void set_dsp_user_out (bool b = true) { dsp_user_out = b; };
  virtual void set_corrupt_caches (bool b = true) { corrupt_caches = b; }
  virtual void set_opt_insn (string s = "" );
  virtual void set_opt_no_insn (string s = "" );
  virtual void set_opt_local_mem (string s = "");
  virtual void set_opt_global_mem (string s = "");
  virtual void set_opt_shadow_mem (string s = "");
  virtual void set_opt_dmac_channel_bitw (string s = "");
  virtual void set_opt_dmac_rectangle (bool b = false);
  virtual void set_opt_timer_channel_bitw (string s = "");
  virtual void set_opt_biu_width (string s = "");
  virtual void set_opt_imem_size (string s = "");
  virtual void set_opt_dmem_size (string s = "");
  virtual void set_opt_dmem_bank_num (string s = "");
  virtual void set_opt_dmem_fixed_start_address (bool b = false);
  virtual void set_opt_icache_size (string s = "");
  virtual void set_opt_icache_line_size (string s = "");
  virtual void set_opt_icache_way (string s = "");
  virtual void set_opt_icache_cwf (string s = "");
  virtual void set_opt_dcache_size (string s = "");
  virtual void set_opt_dcache_line_size (string s = "");
  virtual void set_opt_dcache_way (string s = "");
  virtual void set_opt_dcache_cwf (string s = "");
  virtual void set_opt_intc_channel_bitw (string s = "");
  virtual void set_opt_intc_level (string s = "");
  virtual void write_load (Writer &w);
  virtual void write_config (Writer &w);

 protected:
  int core_type;
  sid::host_int_4 core_rev;
  sid::host_int_4 core_id;
  sid::host_int_4 config_index;
  static sid::host_int_4 curr_core_id;

  void need_icache ();
  void configure_icache ();
  void need_dcache ();
  void configure_dcache ();
  void need_mm_int (sid::big_int_4 mapped_addr, unsigned reg_num, unsigned corecount);
  void allocate_mm_int ();
  
  CacheCfg *insn_buffer;

  sid::host_int_4 biu_width;

  MemCfg *imem0;
  MemCfg *imem1;
  sid::host_int_4 imem_size;
  MemCfg *dmem[dmem_max_banks];  
  sid::host_int_4 dmem_bank_num;
  sid::host_int_4 dmem_size;
  bool dmem_fixed_start_address;

  // The starting address of each dmem bank.
  sid::host_int_4 dmem_base[dmem_max_banks];

  sid::host_int_4 dmac_channel_bitw;
  sid::host_int_4 dmac_data_width;
  sid::host_int_4 dmac_rectangle;

  MepCacheCfg *dcache;
  MepCacheCfg *icache;
  MepCacheCfg *removed_dcache;
  MepCacheCfg *removed_icache;
  MapperCfg *local_mapper;
  vector<AtomicCfg *> dmem_probes;

  void need_intc ();
  void need_dsu ();

  MapperCfg *ctrlmap;
  AtomicCfg *dmac;
  MepDSUCfg *dsu;
  MepINTCCfg *intc;
  MepTimerCfg *timer;
  MepBusArbitratorCfg *gbif;
  MepBusArbitratorCfg *lbif;
  ComponentCfg *main_mem_top;
  const char *main_mem_bus;
  AtomicCfg *local_shadow_bit_insn_probe;

  string gbif_type;
  string lbif_type;

  unsigned hw_engines;

  bool warn_write_to_code;
  bool warn_write_to_rom;
  bool allow_write_to_rom;
  bool dsp_user_out;
  bool corrupt_caches;
  bool opt_bit_p;
  vector <string> insns;
  vector <MepMemRegionCfg *> local_mems;
  vector <MepToshapiHWengineCfg *> toshapi_dsps;
  string module_type;
  string endianness;

  bool insn_count_1_required () const;

  friend class MepMemCfg;

};

class MepHWengineCfg : public AtomicCfg
{
public:
  MepHWengineCfg (const string name, const string type, MepBoardCfg *b,
		  const char *lml) :
    ComponentCfg (name),
    AtomicCfg (name, "libmepfamily.la", 
	       "mepfamily_component_library", 
	       type),
    board (b),
    local_mem_list (lml)
  {}

  virtual void configure_lmem ();

  MepBoardCfg *board;
  const char *local_mem_list;
  MapperCfg* lbus_if_mapper;
};

class MepToshapiHWengineCfg : public MepHWengineCfg
{
public:
  MepToshapiHWengineCfg (const string name, const string type, MepBoardCfg *b,
			 const char *lml) :
    ComponentCfg (name),
    MepHWengineCfg (name, type, b, lml)
  {}

  void add_dmac_hw_req (const string spec, unsigned ch);
  virtual void configure_lmem ();
  virtual void write_config (Writer &w);
};

class MepToshapiMemCfg : virtual public AtomicCfg
{
public:
  MepToshapiMemCfg (const string name, BoardCfg *b) :
    ComponentCfg (name + "-toshapi"),
    AtomicCfg (name + "-toshapi", 
	       "libmepfamily.la", 
	       "mepfamily_component_library",
	       "hw-toshapi-" + name),
    board (b)
  {}

  virtual void write_config (Writer &w);

  BoardCfg *board;
};

#endif // __mepCfg_h__
