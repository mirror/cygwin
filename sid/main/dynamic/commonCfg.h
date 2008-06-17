#ifndef __commonCfg_h__
#define __commonCfg_h__

#include "baseCfg.h"
#include <vector>

class MemCfg :
  virtual public AtomicCfg
{
public:
  MemCfg (const string name);
  MemCfg (const string name, 
	  sid::host_int_4 sz);
  MemCfg (const string name, 
	  sid::host_int_4 read_lat,
	  sid::host_int_4 write_lat);
  MemCfg (const string name, 
	  sid::host_int_4 sz,
	  sid::host_int_4 read_lat,
	  sid::host_int_4 write_lat);
  virtual ~MemCfg();
  void set_read_latency (sid::host_int_4 lat);
  void set_write_latency (sid::host_int_4 lat);
  void set_size (sid::host_int_4 sz);
  sid::host_int_4 size();
  sid::host_int_4 read_latency();
  sid::host_int_4 write_latency();  
  static MemCfg *get_by_name (const string name);

 protected:
  sid::host_int_4 my_size;
  sid::host_int_4 my_read_latency;
  sid::host_int_4 my_write_latency;    
};

class CacheCfg :
  virtual public AtomicCfg
{
public:
  // n-byte buffers
  CacheCfg (const string name, sid::host_int_4 size = 8);
  // direct caches
  CacheCfg (const string name, 
	    const sid::host_int_4 size, 
	    const sid::host_int_4 linesize);
  // complex associative caches
  CacheCfg (const string name, 
	    const string assoc, 
	    const sid::host_int_4 size, 
	    const sid::host_int_4 linesize, 
	    const string replace);
  virtual ~CacheCfg();
  void set_upstream (ComponentCfg *c, const string accessorname);
  void set_downstream (ComponentCfg *c, const string busname);
  void set_hit_latency (sid::host_int_4 i);
  void set_miss_latency (sid::host_int_4 i);
  void set_refill_latency (sid::host_int_4 i);
  sid::host_int_4 size ();
  sid::host_int_4 line_size ();
  void set_size (sid::host_int_4 sz);
  void set_line_size (sid::host_int_4 sz);
  void set_way (sid::host_int_4 sz);
  sid::host_int_4 get_size () const { return my_size; }
  sid::host_int_4 get_line_size () const {return my_line_size; }
 protected:
  virtual void compute_comptype ();
  string my_assoc;
  sid::host_int_4 my_size;
  sid::host_int_4 my_line_size;
  string my_replace;
};

class BlockingCacheCfg :
  public CacheCfg
{
public:
  // 8-byte buffers
  BlockingCacheCfg (const string name);
  // direct caches
  BlockingCacheCfg (const string name, 
		    const sid::host_int_4 size, 
		    const sid::host_int_4 linesize);
  // complex associative caches
  BlockingCacheCfg (const string name, 
		    const string assoc, 
		    const sid::host_int_4 size, 
		    const sid::host_int_4 linesize, 
		    const string replace);
  virtual ~BlockingCacheCfg();
};


class SchedCfg :
  virtual public AtomicCfg
{
public:
  SchedCfg (const string name, const string variant);
  virtual ~SchedCfg ();
  int add_subscription (ComponentCfg *c, 
			string event);
  int add_subscription (ComponentCfg *c, 
			string event, 
			string control);
  int add_subscription (ComponentCfg *c, 
			string event, 
			string control,
			string time_query,
			string time_high,
			string time_low);
  void set_regular (int n, bool v);
  void set_time (int n, int tv);
  void set_priority (int n, int pv);
  virtual void write_config (Writer &w);

  static const int config_priority  = 2;
  static const int gprof_priority   = 1;
  static const int default_priority = 0;

protected:
  int n;
};

// small helper for optional values
template <typename T>
struct Maybe
{
  Maybe () : val (), specified (false) {}
  Maybe (const T &x) : val (x), specified (true) {}
  T val;
  bool specified;
};

// helper for unambiguously constructing mappings 
struct Mapping
{
  Maybe <ComponentCfg *>  _slave;
  Maybe <string>          _bus;
  Maybe <string>          _banks;
  Maybe <sid::host_int_4> _low;
  Maybe <sid::host_int_4> _high;
  Maybe <sid::host_int_4> _wordsz;
  Maybe <sid::host_int_4> _stride;
  Maybe <sid::host_int_4> _width;
  Maybe <sid::host_int_4> _base;
  
  public:
  
  Mapping () {}
  
  Mapping & slave  (ComponentCfg *i)   { _slave = Maybe <ComponentCfg *> (i);   return *this; }
  Mapping & bus    (const string &i)   { _bus = Maybe <string> (i);             return *this; }
  Mapping & banks  (const string &i)   { _banks = Maybe <string> (i);           return *this; }
  Mapping & low    (sid::host_int_4 i) { _low = Maybe <sid::host_int_4> (i);    return *this; }
  Mapping & high   (sid::host_int_4 i) { _high = Maybe <sid::host_int_4> (i);   return *this; }
  Mapping & wordsz (sid::host_int_4 i) { _wordsz = Maybe <sid::host_int_4> (i); return *this; }
  Mapping & stride (sid::host_int_4 i) { _stride = Maybe <sid::host_int_4> (i); return *this; }
  Mapping & width  (sid::host_int_4 i) { _width = Maybe <sid::host_int_4> (i);  return *this; }
  Mapping & base   (sid::host_int_4 i) { _base = Maybe <sid::host_int_4> (i);   return *this; }  
  
  Mapping & slave  () { _slave = Maybe <ComponentCfg *> ();   return *this; }
  Mapping & bus    () { _bus = Maybe <string> ();             return *this; }
  Mapping & banks  () { _banks = Maybe <string> ();           return *this; }
  Mapping & low    () { _low = Maybe <sid::host_int_4> ();    return *this; }
  Mapping & high   () { _high = Maybe <sid::host_int_4> ();   return *this; }
  Mapping & wordsz () { _wordsz = Maybe <sid::host_int_4> (); return *this; }
  Mapping & stride () { _stride = Maybe <sid::host_int_4> (); return *this; }
  Mapping & width  () { _width = Maybe <sid::host_int_4> ();  return *this; }
  Mapping & base   () { _base = Maybe <sid::host_int_4> ();   return *this; }  
  
};

class MapperCfg :
  virtual public AtomicCfg
{
public:
  MapperCfg (const string name, bool transparent = false);
  virtual ~MapperCfg ();
  virtual void map (const Mapping &m);
  void set_transparent (bool t);
  virtual void add_prefix (const string prefix);
  static MapperCfg *get_by_name (const string name);
};


class GlueSeqCfg : 
  virtual public AtomicCfg
{
 public:
  GlueSeqCfg (const string name);
  void add_output (int seqnum, ComponentCfg *c, string pin_name);
  virtual void write_config (Writer &w);
 protected:
  int n;
};

// Configs which support logging should inherit this
struct UlogCfg
{
  UlogCfg (sid::host_int_4 l = 0, const string m = "less", const string f = "-")
    : ulog_level (l), ulog_mode (m), ulog_file (f)
  {}
  virtual void set_ulog_level (sid::host_int_4 l) { ulog_level = l; }
  virtual void set_ulog_mode (const string m) { ulog_mode = m; }
  virtual void set_ulog_file (const string f) { ulog_file = f; }
  sid::host_int_4 ulog_level;
  string ulog_mode;
  string ulog_file;
};

// you should really only make one of these, with an empty name,
// unless you want some crazy multi-session support.
class BoardCfg;
class LoaderCfg;

struct SessionCfg :
  virtual public AggregateCfg, public UlogCfg
{
  SessionCfg (const string name);
  virtual ~SessionCfg ();  
  SchedCfg *host_sched;
  SchedCfg *sim_sched;
  GlueSeqCfg *init_seq;
  GlueSeqCfg *reset_net;
  GlueSeqCfg *shutdown_seq;
  GlueSeqCfg *yield_net;
  AtomicCfg *stdio_obj;
  AtomicCfg *main_obj;
  LoaderCfg *loader;
  // optional bits
  virtual void write_load (Writer &w);
  void use_audio();
  void use_tksched();
  void use_tksm();
  void use_tcl_bridge();
  void use_no_stdio ();
  void set_reversible () { reversible_p = true; }
  virtual void set_loader (LoaderCfg *l);
  LoaderCfg *get_loader () const { return loader; }
  AtomicCfg *audio;
  AtomicCfg *tksched;
  AtomicCfg *tksm;
  AtomicCfg *tcl_bridge;
  bool verbose;
  bool use_stdio;
  bool reversible_p;
  bool need_gprof;
  bool need_core_probe;
  bool maybe_model_busses;
  void add_ulog_file (const string filename);

  map<const string, AtomicCfg *> ulog_map;
  void add_gdb () { ++gdb_count; }
  void add_board (ComponentCfg *b) { ++board_count; add_child (b); }
  void add_memory (MemCfg *mem) { memory.push_back (mem); }
  vector<MemCfg *> memory;
  virtual void write_config (Writer &w);
  // Support for dynamic configuration profiles
  vector<AtomicCfg *> wrapped_components;
  void add_wrapped_component (AtomicCfg *comp) { wrapped_components.push_back (comp); }
  string wrap_config ();
  void profile_config (const string &spec);
protected:
  void add_profile_config (const string &name, const string &options);
  void profile_config_error (const string &spec);
  string profile_opt_value (const string& opt, const vector<string>& opt_parts, unsigned max_parts);
  string profile_opt_int_value (const string& opt, const vector<string>& opt_parts);
  string profile_opt_gprof_value (const string& opt, const vector<string>& opt_parts);
  bool match_profile_opt (const string &opt, const string& want, unsigned min_size);
private:
  sid::host_int_4 board_count;
  sid::host_int_4 gdb_count;
};

class CpuCfg :
  virtual public AtomicCfg
{
public:
  CpuCfg (const string name, 
	  const string variant,
	  SessionCfg *sess);
  virtual ~CpuCfg ();
  void set_imem (ComponentCfg *m, string busname);
  void set_dmem (ComponentCfg *m, string busname);
  void set_disasm_mem (ComponentCfg *m, string busname);
  void set_variant (const string var);
  int get_subscription_number();
  virtual void add_prefix (const string prefix);
  static CpuCfg *get_by_name (const string name);
  static void get_all (vector <CpuCfg *> &targ);
 protected:
  int event_subscription;
};

class LoaderCfg :
  virtual public AtomicCfg
{
public:
  LoaderCfg (const string name, 
	     SessionCfg *sess);
  virtual ~LoaderCfg ();
  void set_target (ComponentCfg *mem, const string mem_bus_name);
  void add_cpu (CpuCfg *cpu);
  void set_file (const string filename);
};


class GlossCfg :
  virtual public AtomicCfg
{
public:
  GlossCfg (const string name, 
	    CpuCfg *cpu, 
	    ComponentCfg *mem,
	    const string mem_bus_name,
	    SessionCfg *sess);
  GlossCfg (const string name, 
	    CpuCfg *cpu, 
	    SessionCfg *sess);
  virtual ~GlossCfg ();
};

class GprofCfg :
  virtual public AtomicCfg
{
public:
  GprofCfg (const string name, 
	    const string filename,
	    CpuCfg *cpu, 
	    SessionCfg *sess,
	    gprof_type type,
            int interval);
  GprofCfg (const string name, 
	    CpuCfg *cpu, 
	    SessionCfg *sess);
  virtual ~GprofCfg ();
};

class GdbCfg :
  virtual public AggregateCfg
{
 public:
  GdbCfg (const string name, 
	  const string port, 
	  CpuCfg *c, 
	  BoardCfg *b,
	  SessionCfg *s);
  virtual ~GdbCfg ();
  virtual void write_config (Writer &w);
 protected:
  CpuCfg *cpu;
  BoardCfg *board;
  SessionCfg *sess;
  AtomicCfg *stub;
  AtomicCfg *sock;
};

class LoaderCfg;
class BoardCfg :
virtual public AggregateCfg, public UlogCfg
{
public:
  BoardCfg (const string name,
	    const string default_cpu_variant,
	    SessionCfg *s,
	    bool with_default_gloss = true,
	    bool with_z_packet = true,
	    bool with_cpu_main_mem_connect = false);    
  virtual void use_gloss ();
  virtual void set_cpu (const string variant);
  virtual void set_loader (LoaderCfg *l);
  virtual void set_gdb (const string port);
  virtual void set_gprof (const string filename, gprof_type type, int interval);
  virtual void set_engine (const string engine);
  virtual void set_step_insn_count (const string count);
  virtual void set_endian (const string endian);
  virtual void add_sidrtc (sid::host_int_4 addr);
  virtual void add_sidcodec (sid::host_int_4 addr);
  virtual void add_dcache (const string type);
  virtual void add_icache (const string type);
  virtual void add_memory (const Mapping &m);
  virtual void enable_warnings ();
  virtual void final_insn_count ();
  virtual void trace_counter ();
  virtual void trace_extract ();
  virtual void trace_semantics ();
  virtual void trace_disassemble ();
  virtual void trace_core ();
  virtual void set_warmup (bool w = true);
  virtual void add_profile_func (const string &spec);
  virtual void add_warmup_func (const string &funcs);
  virtual void set_start_config (const string &config);
  virtual void write_load (Writer &w);
  virtual void write_config (Writer &w);

  // Mep-specific options
  virtual void set_config_index (unsigned i = 0) {}
  virtual void set_warn_write_to_code (bool b = true) {}
  virtual void set_warn_write_to_rom (bool b = true) {}
  virtual void set_allow_write_to_rom (bool b = true) {}
  virtual void set_model_busses (bool b = true) {}
  virtual void set_dsp_user_out (bool b = true) {}
  virtual void set_corrupt_caches (bool b = true) {}
  virtual void set_opt_insn (string s = "") {}
  virtual void set_opt_no_insn (string s = "") {}
  virtual void set_opt_local_mem (string s = "") {}
  virtual void set_opt_global_mem (string s = "") {}
  virtual void set_opt_shadow_mem (string s = "") {}
  virtual void set_opt_dmac_channel_bitw (string s = "") {}
  virtual void set_opt_biu_width (string s = "") {}
  virtual void set_opt_dmac_rectangle (bool b = false) {}
  virtual void set_opt_imem_size (string s = "") {}
  virtual void set_opt_dmem_size (string s = "") {}
  virtual void set_opt_dmem_bank_num (string s = "") {}
  virtual void set_opt_dmem_fixed_start_address (bool b = false) {}
  virtual void set_opt_icache_size (string s = "") {}
  virtual void set_opt_icache_line_size (string s = "") {}
  virtual void set_opt_icache_way (string s = "") {}
  virtual void set_opt_icache_cwf (string s = "") {}
  virtual void set_opt_dcache_size (string s = "") {}
  virtual void set_opt_dcache_line_size (string s = "") {}
  virtual void set_opt_dcache_way (string s = "") {}
  virtual void set_opt_dcache_cwf (string s = "") {}
  virtual void set_opt_intc_channel_bitw (string s = "") {}
  virtual void set_opt_intc_level (string s = "") {}
  virtual void set_opt_timer_channel_bitw (string s = "") {}

  virtual ~BoardCfg ();

  GlueSeqCfg *cache_flush_net;
  bool z_packet;
  CpuCfg *cpu;
  SessionCfg *sess;
  MapperCfg *main_mapper;
  AtomicCfg *dynamic_configurator;

 protected:
  GdbCfg *gdb;
  GlossCfg *gloss;
  GprofCfg *gprof;
  AtomicCfg *core_probe;
  AtomicCfg *icache;
  AtomicCfg *dcache;  
  LoaderCfg *loader;

  string start_config;
  string warmup_funcs;
  string profile_funcs;
  string step_insn_count;
  bool step_insn_count_1_required_p;
};

#endif // __commonCfg_h__
