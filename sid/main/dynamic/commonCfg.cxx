
#include "commonCfg.h"

// MemCfg
struct MemCfg_impl
{
  static map <string, MemCfg *> name_map;
};

map <string, MemCfg *> MemCfg_impl::name_map;

MemCfg *MemCfg::get_by_name (const string name)
{
  if (MemCfg_impl::name_map.find (name) ==
      MemCfg_impl::name_map.end())
    return NULL;
  return MemCfg_impl::name_map [name];
}

MemCfg::~MemCfg () {}
MemCfg::MemCfg (const string name) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libmemory.la", 
	     "mem_component_library",
	     "hw-memory-ram/rom-basic")
{
  MemCfg_impl::name_map [my_name] = this;
}

MemCfg::MemCfg (const string name, 
	sid::host_int_4 sz) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libmemory.la", 
	     "mem_component_library", 
	     "hw-memory-ram/rom-basic")
{
  set_size (sz);
  MemCfg_impl::name_map [my_name] = this;
}

MemCfg::MemCfg (const string name, 
	sid::host_int_4 read_lat,
	sid::host_int_4 write_lat) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libmemory.la", 
	     "mem_component_library",
	     "hw-memory-ram/rom-basic")
{
  set_read_latency (read_lat);
  set_write_latency (write_lat);
  MemCfg_impl::name_map [my_name] = this;
}

MemCfg::MemCfg (const string name, 
	sid::host_int_4 sz,
	sid::host_int_4 read_lat,
	sid::host_int_4 write_lat) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libmemory.la", 
	     "mem_component_library",
	     "hw-memory-ram/rom-basic")
{
  set_size (sz);
  set_read_latency (read_lat);
  set_write_latency (write_lat);
  MemCfg_impl::name_map [my_name] = this;
}


void MemCfg::set_read_latency (sid::host_int_4 lat)
{
  my_read_latency = lat;
  set (this, "read-latency", sidutil::make_attribute(lat));
}

void MemCfg::set_write_latency (sid::host_int_4 lat)
{
  my_write_latency = lat;
  set (this, "write-latency", sidutil::make_attribute(lat));
}

void MemCfg::set_size (sid::host_int_4 sz)
{
  my_size = sz;
  set (this, "size", sidutil::make_attribute(sz));
}

sid::host_int_4 MemCfg::size()
{
  return my_size;
}

sid::host_int_4 MemCfg::read_latency()
{
  return my_read_latency;
}

sid::host_int_4 MemCfg::write_latency()
{
  return my_write_latency;
}



// CacheCfg
CacheCfg::~CacheCfg () {}
CacheCfg::CacheCfg (const string name) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-cache-buffer-8"),
  my_assoc (""),
  my_size (8),
  my_line_size (0),
  my_replace ("")
{}

// direct caches
CacheCfg::CacheCfg (const string name, 
		    const sid::host_int_4 size, 
		    const sid::host_int_4 linesize) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-cache-direct/" + 
	     sidutil::make_attribute(size) + "kb/" +
	     sidutil::make_attribute(linesize)),
  my_assoc ("direct"),
  my_size (size),
  my_line_size (linesize),
  my_replace ("")
{}

// complex associative caches
CacheCfg::CacheCfg (const string name, 
	  const string assoc, 
	  const sid::host_int_4 size, 
	  const sid::host_int_4 linesize, 
	  const string replace) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-cache-" + assoc + "/" + 
	     sidutil::make_attribute(size) + "kb/" +
	     sidutil::make_attribute(linesize) + "/" +
	     replace),
  my_assoc (assoc),
  my_size (size),
  my_line_size (linesize),
  my_replace (replace)
{}

void CacheCfg::compute_comptype ()
{
  if (my_assoc == "")
    {
      my_comptype = "hw-cache-buffer-8";
    }
  else
    {
      string replace = my_replace;

      if (my_assoc != "direct" && replace == "")
	replace = "lru";

      if (replace == "")
	{
	  my_comptype = "hw-cache-" + my_assoc + "/"
	    + sidutil::make_attribute(my_size) + "kb/"
	    + sidutil::make_attribute(my_line_size);
	} 
      else 
	{
	  my_comptype = "hw-cache-" + my_assoc + "/"
	    + sidutil::make_attribute(my_size) + "kb/"
	    + sidutil::make_attribute(my_line_size) + "/"
	    + replace;
	}
    }
}

sid::host_int_4 CacheCfg::size ()
{
  return my_size;
}

sid::host_int_4 CacheCfg::line_size ()
{
  return my_line_size;
}

void CacheCfg::set_size (sid::host_int_4 sz)
{
  my_size = sz;
  compute_comptype ();
}

void CacheCfg::set_line_size (sid::host_int_4 sz)
{
  my_line_size = sz;
  compute_comptype ();
}

void CacheCfg::set_way (sid::host_int_4 w)
{
  switch (w)
    {
    case 1:
      my_assoc = "direct";
      break;
    case 2:
      my_assoc = "2way";
      break;
    case 4:
      my_assoc = "4way";
      break;
    default:
      assert (false);
    }
  compute_comptype ();
}

void CacheCfg::set_upstream (ComponentCfg *c, const string accessorname)
{
  assert (c);
  conn_bus (c, accessorname, this, "upstream");
}

void CacheCfg::set_downstream (ComponentCfg *c, const string busname)
{
  assert (c);
  conn_bus (this, "downstream", c, busname);
}

void CacheCfg::set_hit_latency (sid::host_int_4 i)
{
  set (this, "hit-latency", sidutil::make_attribute (i));
}

void CacheCfg::set_miss_latency (sid::host_int_4 i)
{
  set (this, "miss-latency", sidutil::make_attribute (i));
}

void CacheCfg::set_refill_latency (sid::host_int_4 i)
{
  set (this, "refill-latency", sidutil::make_attribute (i));
}

// CpuCfg


struct CpuCfg_impl
{
  static map <string, CpuCfg *> name_map;
};

map <string, CpuCfg *> CpuCfg_impl::name_map;

CpuCfg *CpuCfg::get_by_name (const string name)
{
  if (CpuCfg_impl::name_map.find (name) ==
      CpuCfg_impl::name_map.end())
    return NULL;
  return CpuCfg_impl::name_map [name];
}

void CpuCfg::get_all (vector <CpuCfg *> &targ)
{
  for (map <string, CpuCfg *>::const_iterator i = CpuCfg_impl::name_map.begin();
       i != CpuCfg_impl::name_map.end(); ++i)
    targ.push_back (i->second);
}


CpuCfg::~CpuCfg () {}
CpuCfg::CpuCfg (const string name, 
		const string variant, 
		SessionCfg *sess) : 
    ComponentCfg (name),
    AtomicCfg (name, 
	       "libcgencpu.la", 
	       "cgen_component_library",
	       "hw-cpu-" + variant),
    event_subscription (0)
{
  assert (sess);
  assert (sess->reset_net);
  assert (sess->yield_net);
  assert (sess->sim_sched);
  CpuCfg_impl::name_map [my_name] = this;
  sess->reset_net->add_output (0, this, "reset!");
  sess->yield_net->add_output (0, this, "yield");
  event_subscription = 
    sess->sim_sched->add_subscription 
    (this, "step!", "step-cycles", 
     "time-query", "time-high", "time-low");
}


void CpuCfg::set_imem (ComponentCfg *m, string busname)
{
  conn_bus (this, "insn-memory", m, busname);
}

void CpuCfg::set_dmem (ComponentCfg *m, string busname)
{
  conn_bus (this, "data-memory", m, busname);
}

void CpuCfg::set_disasm_mem (ComponentCfg *m, string busname)
{
  conn_bus (this, "disassembler-memory", m, busname);
}

void CpuCfg::set_variant (const string var)
{
  my_comptype = string ("hw-cpu-" + var);
}

int CpuCfg::get_subscription_number ()
{
  return event_subscription;
}

void CpuCfg::add_prefix (const string prefix)
{
  CpuCfg_impl::name_map.erase (my_name);
  AtomicCfg::add_prefix (prefix);
  CpuCfg_impl::name_map [my_name] = this;
}


// SchedCfg
SchedCfg::~SchedCfg () {}
SchedCfg::SchedCfg (const string name, const string variant) :
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libsched.la",
	     "sched_component_library",
	     "sid-sched-" + variant),     //variant is "host-accurate" or "sim"
  n(0)
{}


int SchedCfg::add_subscription (ComponentCfg *c, 
		      string event)
{
  string s = sidutil::make_attribute (n);
  conn_pin (this, s + "-event", c, event);
  return n++;
}

int SchedCfg::add_subscription (ComponentCfg *c, 
		      string event, 
		      string control)
{
  string s = sidutil::make_attribute (n);
  conn_pin (this, s + "-event", c, event);
  conn_pin (this, s + "-control", c, control, dst_to_src);
  return n++;
}

int SchedCfg::add_subscription (ComponentCfg *c, 
		      string event, 
		      string control,
		      string time_query,
		      string time_high,
		      string time_low)
{
  string s = sidutil::make_attribute (n);
  conn_pin (this, s + "-event", c, event);
  conn_pin (this, s + "-control", c, control, dst_to_src);
  conn_pin (this, "time-query", c, time_query, dst_to_src);
  conn_pin (this, "time-high", c, time_high);
  conn_pin (this, "time-low", c, time_low);
  return n++;
}

void SchedCfg::set_regular (int n, bool v)
{
  string s = sidutil::make_attribute (n);
  set (this, s + "-regular?", v ? "true" : "false");
}

void SchedCfg::set_time (int n, int tv)
{
  string s = sidutil::make_attribute (n);
  string ts = sidutil::make_attribute (tv);
  set (this, s + "-time", ts);
}

void SchedCfg::write_config (Writer &w)
{
  Setting (this, "num-clients", sidutil::make_attribute (n)).write_to (w);
  AtomicCfg::write_config (w);
}

// MapperCfg
struct MapperCfg_impl
{
  static map <string, MapperCfg *> name_map;
};

map <string, MapperCfg *> MapperCfg_impl::name_map;

MapperCfg *MapperCfg::get_by_name (const string name)
{
  if (MapperCfg_impl::name_map.find (name) ==
      MapperCfg_impl::name_map.end())
    return NULL;
  return MapperCfg_impl::name_map [name];
}

MapperCfg::~MapperCfg () {}
MapperCfg::MapperCfg (const string name, bool transparent) :
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libmapper.la", 
	     "mapper_component_library", 
	     string("hw-mapper-") + (transparent ? "transparent" : "basic"))
{
  MapperCfg_impl::name_map [my_name] = this;
}



void MapperCfg::set_transparent (bool t)
{
  if (t)
    my_comptype = "hw-mapper-transparent";
  else
    my_comptype = "hw-mapper-basic";
}

void MapperCfg::add_prefix (const string prefix)
{
  MapperCfg_impl::name_map.erase (my_name);
  AtomicCfg::add_prefix (prefix);
  MapperCfg_impl::name_map [my_name] = this;
}

void MapperCfg::map (const Mapping &m) 
{
  // FIXME: report an error here?
  if (! (m._slave.specified && m._bus.specified))
    return;
  
  string map_accessor = "[";
  if (m._wordsz.specified)
    map_accessor += sidutil::make_attribute(m._wordsz.val) + "*";

  if (m._base.specified)
    map_accessor += sidutil::make_attribute(m._base.val) + "=";

  // always include a low and a high. default to 0 if not specified.
  // FIXME: perhaps issuing a warning here would be better?
  map_accessor += 
    sidutil::make_attribute(m._low.specified ? 
			    m._low.val : 0) 
    + "-"
    + sidutil::make_attribute(m._high.specified ? 
			      m._high.val : 0);

  // Both stride and width must be specified for either to make sense.
  if (m._stride.specified && m._width.specified)
    map_accessor += "," 
      + sidutil::make_attribute(m._stride.val) 
      + ","
      + sidutil::make_attribute(m._width.val);
  
  map_accessor += "]";

  if (m._banks.specified)
    map_accessor += m._banks.val;

  conn_bus (this, map_accessor, m._slave.val, m._bus.val);
}

// GlusSeqCfg 

GlueSeqCfg::GlueSeqCfg (const string name)
  : ComponentCfg (name),
    AtomicCfg (name,
	       "libglue.la", 
	       "glue_component_library", 
	       "hw-glue-sequence"),
    n(-1)
{}

void GlueSeqCfg::add_output (int seqnum, ComponentCfg *c, string pin_name)
{
  n = seqnum > n ? seqnum : n;
  string s = sidutil::make_attribute (seqnum);
  conn_pin (this, "output-" + s, c, pin_name);
}

void GlueSeqCfg::write_config (Writer &w)
{
  Setting (this, "num-outputs", sidutil::make_attribute (n+1)).write_to (w);
  AtomicCfg::write_config (w);
}


// SessionCfg
SessionCfg::~SessionCfg () {}
SessionCfg::SessionCfg (const string name)
  : ComponentCfg (name),
    AggregateCfg (name),
    host_sched (new SchedCfg ("host-sched", "host-accurate")),
    sim_sched (new SchedCfg ("sim-sched", "sim")),
    init_seq (new GlueSeqCfg ("init-seq")),
    reset_net (new GlueSeqCfg ("reset-net")),
    shutdown_seq (new GlueSeqCfg ("shutdown-seq")),
    yield_net (new GlueSeqCfg ("yield-net")),
    stdio_obj (NULL),
    // built-in (currently global)
    main_obj ( new AtomicCfg ("main", "", "", "") ),
    // optional bits
    audio (NULL),
    tksched (NULL),
    tksm (NULL),
    tcl_bridge (NULL),
    loader (NULL),
    verbose (false),
    use_stdio (true),
    board_count (0),
    gdb_count (0)
{
  add_child (host_sched);
  add_child (sim_sched);
  add_child (init_seq);
  add_child (reset_net);
  add_child (shutdown_seq);
  add_child (yield_net);
  add_child (main_obj);
  
  conn_pin (main_obj, "perform-activity", host_sched, "advance");
  conn_pin (main_obj, "perform-activity", sim_sched, "advance");
  conn_pin (main_obj, "starting", init_seq, "input");
  conn_pin (main_obj, "stopping", shutdown_seq, "input");
  yield_net->add_output (0, host_sched, "yield");
  init_seq->add_output (0, reset_net, "input");

  AtomicCfg *ulog = new AtomicCfg ("ulog-cout",
				   "libconsoles.la", 
				   "console_component_library", 
				   "sid-io-fileio");
  ulog_map["-"] = ulog;
  add_child (ulog);
}

void
SessionCfg::add_ulog_file (const string name)
{
  if (ulog_map.find (name) != ulog_map.end ())
    return; // already there

  // There is no existing logger for this file, so add a new one.
  AtomicCfg *ulog = new AtomicCfg ("ulog-" + name, 
				   "libconsoles.la", 
				   "console_component_library", 
				   "sid-io-fileio");
  set (ulog, "filename", name);
  ulog_map[name] = ulog;
  add_child (ulog);
}

void SessionCfg::set_loader (LoaderCfg *l)
{
  if (loader)
    return;
  loader = l;
  add_child (l);
}

void SessionCfg::use_no_stdio ()
{
  use_stdio = false;
}

void SessionCfg::write_load (Writer &w)
{
  if (use_stdio)
    {
      stdio_obj = new AtomicCfg ("stdio", 
				 "libconsoles.la", 
				 "console_component_library", 
				 "sid-io-stdio");
      add_child (stdio_obj);
      int n = host_sched->add_subscription (stdio_obj, "poll");
      host_sched->set_regular (n, true);
      host_sched->set_time (n, 150);
      use_stdio = false;
    }
  AggregateCfg::write_load (w);
}

void SessionCfg::use_audio () 
{
  if (audio)
    return;
  audio = new AtomicCfg ("audio", "libaudio.la", 
			 "audio_component_library",
			 "sid-io-audio");
  add_child (audio);
  int n = host_sched->add_subscription (audio, "poll");
  host_sched->set_regular (n, true);
  host_sched->set_time (n, 100);
}

void SessionCfg::use_tksched ()
{
  if (tksched)
    return;
  use_tcl_bridge();
  tksched = new AtomicCfg ("tksched", "libtclapi.la", 
			   "tcl_bridge_library",
			   "sid-visual-sched");
  add_child (tksched);
  relate (tksched, "scheduler", sim_sched);
}

void SessionCfg::use_tksm ()
{
  if (tksm)
    return;
  use_tcl_bridge();
  tksm = new AtomicCfg ("tksm", "libtclapi.la", 
			"tcl_bridge_library",
			   "sid-control-tksm");
  add_child (tksm);
  assert (main_obj);
  assert (host_sched);
  relate (main_obj, "component-catalog-informees", tksm);
  int n = host_sched->add_subscription (tksm, "refresh");
  host_sched->set_regular (n, true);
  host_sched->set_time (n, 1000);
}

void SessionCfg::use_tcl_bridge ()
{
  if (tcl_bridge)
    return;
  tcl_bridge = new AtomicCfg ("tcl-event-consumer", "libtclapi.la", 
			      "tcl_bridge_library",
			      "bridge-tcl");
  add_child (tcl_bridge);
  assert (host_sched);
  assert (init_seq);
  host_sched->add_subscription (tcl_bridge, "!event", "!event-control");
  init_seq->add_output (7, tcl_bridge, "!event");
}

void SessionCfg::write_config (Writer &w)
{
  AggregateCfg::write_config (w);

  // Stop the host scheduler if all of the GDB stubs are stopped
  if (gdb_count)
    {
      assert (host_sched);
      Setting (host_sched, "yield-host-time-threshold",
	       sidutil::make_attribute (gdb_count)).write_to (w);
      Setting (host_sched, "yield-host-time?", "0").write_to (w);
    }

  // Stop the sim scheduler if any of the GDB stubs are stopped
  assert (sim_sched);
  Setting (sim_sched, "enable-threshold",
	   sidutil::make_attribute (board_count)).write_to (w);
  Setting (sim_sched, "enabled?",
	   sidutil::make_attribute (board_count)).write_to (w);
}

// LoaderCfg 
LoaderCfg::~LoaderCfg () {}
LoaderCfg::LoaderCfg (const string name, 
		      SessionCfg *sess) :
  ComponentCfg (name),
  AtomicCfg ( name, "libloader.la", 
	      "loader_component_library",
	      "sw-load-elf")
{
  assert (sess);
  set (this, "file", "a.out");
  set (this, "verbose?", sess->verbose ? "true" : "false");
  conn_pin (this, "error", sess->main_obj, "stop!");
  sess->init_seq->add_output (1, this, "load!");
}

void LoaderCfg::set_target (ComponentCfg *mem, const string mem_bus_name)
{
  assert (mem);
  conn_bus (this, "load-accessor-data", mem, mem_bus_name);
  conn_bus (this, "load-accessor-insn", mem, mem_bus_name);
}

void LoaderCfg::add_cpu (CpuCfg *cpu) 
{
  assert (cpu);
  conn_pin (this, "start-pc-set", cpu, "start-pc-set!");
  conn_pin (this, "endian-set", cpu, "endian-set!");
}

void LoaderCfg::set_file (const string filename)
{
  set (this, "file", filename);
}


// GlossCfg
GlossCfg::~GlossCfg () {}
GlossCfg::GlossCfg (const string name, 
		    CpuCfg *cpu, 
		    ComponentCfg *mem,
		    const string mem_bus_name,
		    SessionCfg *sess) :
  ComponentCfg (name),
  AtomicCfg ( name, "libgloss.la", 
	      "gloss_component_library",
	      "sw-gloss-generic/libgloss")    
{
  assert (cpu);
  assert (mem);
  assert (sess);
  relate (this, "cpu", cpu);
  conn_pin (this, "trap", cpu, "trap", both);
  conn_pin (this, "trap-code", cpu, "trap-code", dst_to_src);
  conn_bus (this, "target-memory", mem, mem_bus_name);
  set (this, "verbose?", sess->verbose ? "true" : "false");
  assert (sess->init_seq);
  sess->init_seq->add_output (2, this, "reset");
}

GlossCfg::GlossCfg (const string name, 
		    CpuCfg *cpu, 
		    SessionCfg *sess) :
  ComponentCfg (name),
  AtomicCfg ( name, "libgloss.la", 
	      "gloss_component_library",
	      "sw-gloss-generic/libgloss")    
{
  assert (cpu);
  assert (sess);
  relate (this, "cpu", cpu);
  conn_pin (this, "trap", cpu, "trap", both);
  conn_pin (this, "trap-code", cpu, "trap-code", dst_to_src);
  set (this, "verbose?", sess->verbose ? "true" : "false");
  assert (sess->init_seq);
  sess->init_seq->add_output (2, this, "reset");
}


// GprofCfg
GprofCfg::~GprofCfg() {}
GprofCfg::GprofCfg (const string name, 
		    const string filename,
		    CpuCfg *cpu, 
		    SessionCfg *sess,
		    gprof_type type,
                    int interval) :
  ComponentCfg (name),
  AtomicCfg ( name, "libprof.la", 
	      "prof_component_library",
	      "sw-profile-gprof")
{
  assert (cpu);
  assert (sess);
  if (type == simulated_cycles)
    {
      assert (sess->sim_sched);
      int slot = sess->sim_sched->add_subscription (this, "sample");
      sess->sim_sched->set_regular (slot, true);
      sess->sim_sched->set_time (slot, interval);
    }
  else		// default to instruction_count
    {
      string ev = sidutil::make_attribute (cpu->get_subscription_number());
      ev += "-event";
      conn_pin (sess->sim_sched, ev, this, "sample");
    }
  sess->shutdown_seq->add_output (7, this, "store");
  relate (this, "target-component", cpu);
  conn_pin (cpu, "cg-caller", this, "cg-caller");
  conn_pin (cpu, "cg-callee", this, "cg-callee");
  set (this, "value-attribute", "pc");
  set (this, "bucket-size", "4"); // bytes-per-bucket
  set (this, "output-file", filename);
}



// GdbCfg
GdbCfg::~GdbCfg () {}
GdbCfg::GdbCfg (const string name, 
		const string port,
		CpuCfg *c, 
		BoardCfg *b,
		SessionCfg *s) :
  ComponentCfg (name),
  AggregateCfg (name),
  cpu (c),
  board (b),
  sess (s),
  sock (NULL),
  stub (NULL)  
{
  assert (cpu);
  assert (board);
  assert (sess);

  sock = new AtomicCfg ("socket", 
			"libconsoles.la", 
			"console_component_library", 
			"sid-io-socket-server");
  stub  = new AtomicCfg ( "stub", "libgdb.la", 
			  "gdb_component_library",
			  "sw-debug-gdb");
  add_child (sock);
  add_child (stub);

  // hook up our stub to the session and board
  relate (stub, "cpu", cpu);
  relate (stub, "cfgroot", sess->main_obj);
  relate (stub, "target-schedulers", sess->sim_sched);
  relate (stub, "host-schedulers", sess->host_sched);
  sess->init_seq->add_output (3, stub, "init");
  sess->shutdown_seq->add_output (5, stub, "deinit");
  conn_pin (stub, "flush-icache", board->cache_flush_net, "input");
  conn_pin (stub, "restart", sess->reset_net, "input");
  set (stub, "exit-on-detach?", "true");
  
  // hook up our socket to the outside world
  sess->init_seq->add_output (2, sock, "init");
  sess->shutdown_seq->add_output (6, sock, "fini");
  conn_pin (sock, "rx", stub, "remote-rx");
  conn_pin (sock, "tx", stub, "remote-tx", dst_to_src);
  sess->host_sched->add_subscription (sock, "poll-event", "poll-control");
  set (sock, "sockaddr-local", "0.0.0.0:" + port);

  // expose stub's names to the outside as our names
  map_name (stub, out_pin, "yield",                "yield");
  map_name (stub, in_pin,  "trap",                 "trap");
  map_name (stub, out_pin, "trap",                 "trap");
  map_name (stub, in_pin,  "trap-code",            "trap-code");
  map_name (stub, in_pin,  "gloss-process-signal", "gloss-process-signal");
  map_name (stub, out_pin, "process-signal",       "process-signal");
  map_name (stub, in_pin,  "target-tx",            "target-tx");
  map_name (stub, relater, "gloss",                "gloss");
  map_name (stub, attr,    "enable-Z-packet?",     "enable-Z-packet?");
  map_name (stub, attr,    "operating-mode?",      "operating-mode?");
}


void GdbCfg::write_config (Writer &w)
{
  AggregateCfg::write_config (w);
  assert (sock);
  assert (stub);
  if (sess->verbose)
    {      
      Setting (stub, "trace-gdbsid?", "true").write_to (w); 
      Setting (stub, "trace-gdbserv?", "true").write_to (w); 
      Setting (sock, "verbose?", "true").write_to (w); 
    }
}


// BoardCfg
BoardCfg::~BoardCfg () {}
BoardCfg::BoardCfg (const string name, 
		    const string default_cpu_variant,		    
		    SessionCfg *s,
		    bool with_default_gloss,
		    bool with_z_packet,
		    bool with_cpu_main_mem_connect) :
  ComponentCfg (name),
  AggregateCfg (name),
  UlogCfg (),
  cache_flush_net (NULL),
  z_packet (with_z_packet),
  sess (s),
  cpu (NULL),
  gdb (NULL),
  gloss (NULL),
  gprof (NULL),
  main_mapper (NULL),
  icache (NULL),
  dcache (NULL),
  loader (NULL)
{
  assert (sess);
  cpu = new CpuCfg ("cpu", default_cpu_variant, sess);
  set_step_insn_count ("10000");
  set_engine ("pbb");
  main_mapper = new MapperCfg ("main-map");
  assert (main_mapper);

  cache_flush_net = new GlueSeqCfg ("cache-flush-net");
  cache_flush_net->add_output (1, cpu, "flush-icache");

  if (with_default_gloss)
    use_gloss ();

  if (with_cpu_main_mem_connect)
    {
      cpu->set_imem (main_mapper, "access-port");
      cpu->set_dmem (main_mapper, "access-port");
    }
  add_child (cpu);
  add_child (main_mapper);
  add_child (cache_flush_net);
}


void BoardCfg::use_gloss () 
{
  if (gloss)
    return;
  gloss = new GlossCfg ("gloss", cpu, main_mapper, "access-port", sess);
  add_child (gloss);
}

void BoardCfg::set_cpu (const string variant)
{
  assert (cpu);
  cpu->set_variant(variant);
}

void BoardCfg::set_gdb (const string port)
{
  if (gdb)
    return;
  gdb = new GdbCfg ("gdb", port, cpu, this, sess);
  add_child (gdb);
  sess->use_no_stdio ();
  sess->add_gdb ();
}


void BoardCfg::set_loader (LoaderCfg *l)
{
  if (loader)
    return;
  loader = l;
  add_child (l);
}

void BoardCfg::write_config (Writer &w)
{
  AggregateCfg::write_config (w);
  if (gloss)
    {      
      if (gdb)
	{ 
	  // gdb chained off gloss	  
	  PinConnection  (gloss, "trap-chain", gdb, "trap", both).write_to (w); 
	  PinConnection (gloss, "trap-code-chain", gdb, "trap-code").write_to (w);
	  PinConnection (gloss, "process-signal", gdb, "gloss-process-signal").write_to (w);
	  PinConnection (gdb, "process-signal", sess->main_obj, "stop!").write_to (w);
	  PinConnection (gdb, "yield", sess->yield_net, "input").write_to (w);
	  PinConnection (gloss, "debug-tx", gdb, "target-tx").write_to (w);
	  Relation (gdb, "gloss", gloss).write_to (w);
	  Setting (gdb, "enable-Z-packet?", z_packet ? "true" : "false").write_to (w);
	  Setting (gdb, "operating-mode?", "false").write_to (w);
	} 
      else 
	{
	  // gloss alone	  
	  assert (sess->stdio_obj);
	  PinConnection (gloss, "debug-tx", sess->stdio_obj, "stdout").write_to(w);
	  PinConnection (gloss, "debug-rx", sess->stdio_obj, "stdin", dst_to_src).write_to(w);
	  PinConnection (gloss, "process-signal", sess->main_obj, "stop!").write_to(w);
	  PinConnection (gloss, "process-signal", sess->yield_net, "input").write_to(w);
	}
    }
  else
    {
      if (gdb)
	{
	  // gdb alone
	  PinConnection (cpu, "trap", gdb, "trap", both).write_to(w);
	  PinConnection (cpu, "trap-code", gdb, "trap-code").write_to(w);
	}
    }  
}

void BoardCfg::set_gprof (const string filename, gprof_type type, int interval)
{
  if (gprof)
    return;
  gprof = new GprofCfg ("gprof", filename, cpu, sess, type, interval);
  add_child (gprof);
}

void BoardCfg::set_engine (const string engine)
{
  assert (cpu);
  cpu->set (cpu, "engine-type", engine);
}

void BoardCfg::set_step_insn_count (const string count)
{
  assert (cpu);
  cpu->set (cpu, "step-insn-count", count);
}

void BoardCfg::set_endian (const string endian)
{
  assert (cpu);
  cpu->set (cpu, "endian", endian);
}

void BoardCfg::add_sidrtc (sid::host_int_4 addr)
{
  AtomicCfg *rtc = new AtomicCfg ("rtc", "librtc.la", 
				  "rtc_component_library",
				  "hw-rtc-sid");
  add_child (rtc);
  assert (main_mapper);
  main_mapper->map (Mapping()
		    .slave(rtc).bus("registers")
		    .low(addr).high(addr+7));
}

void BoardCfg::add_sidcodec (sid::host_int_4 addr)
{
  AtomicCfg *codec = new AtomicCfg ("codec", "libaudio.la", 
				    "audio_component_library",
				    "hw-audio-sid");
  assert (sess);
  sess->use_audio ();
  assert (sess->audio);

  add_child (codec);
  main_mapper->map (Mapping()
		    .slave(codec).bus("registers")
		    .low(addr).high(addr+19));
  codec->conn_pin (codec, "tx-sample", sess->audio, "tx-sample");
  codec->conn_pin (codec, "rx-sample", sess->audio, "rx-sample", dst_to_src);
  codec->conn_pin (codec, "tx-mode", sess->audio, "tx-mode");
  codec->conn_pin (codec, "tx-pending", sess->audio, "tx-pending", dst_to_src);
  codec->conn_pin (codec, "rx-mode", sess->audio, "rx-mode");
  codec->conn_pin (codec, "rx-pending", sess->audio, "rx-pending", dst_to_src);
  codec->conn_pin (codec, "config-set", sess->audio, "config-set");
}


void BoardCfg::trace_extract ()
{
  assert (cpu);
  cpu->set (cpu, "trace-extract?", "true");
}

void BoardCfg::trace_semantics ()
{
  assert (cpu);
  cpu->set (cpu, "trace-semantics?", "true");
}

void BoardCfg::final_insn_count ()
{
  assert (cpu);
  assert (sess->shutdown_seq);
  sess->shutdown_seq->add_output (0, cpu, "print-insn-summary!");
  cpu->set (cpu, "final-insn-count?", "true");
}

void BoardCfg::trace_counter ()
{
  assert (cpu);
  cpu->set (cpu, "trace-counter?", "true");
}

void BoardCfg::trace_disassemble ()
{
  assert (cpu);
  cpu->set (cpu, "trace-disassemble?", "true");
}

void BoardCfg::enable_warnings ()
{
  assert (cpu);
  cpu->set (cpu, "enable-warnings?", "true");
}

void BoardCfg::add_dcache (const string type)
{
  static int num = 0;
  AtomicCfg *new_dcache = new AtomicCfg ("dcache-" + sidutil::make_attribute (num++), 
					 "libcache.la", 
					 "cache_component_library",
					 "hw-cache-" + type);
  add_child (new_dcache);
  if (dcache)
    {
      // we are extending the existing dcache chain
      dcache->map_name (new_dcache, accessor, "downstream", "downstream");
      dcache->conn_bus (dcache, "downstream", new_dcache, "upstream", false);
    }
  else
    {
      // we are chaining off the CPU
      assert (cpu);
      cpu->map_name (new_dcache, accessor, "data-memory", "downstream");
      cpu->conn_bus (cpu, "data-memory", new_dcache, "upstream", false);
    }
  dcache = new_dcache;
}

void BoardCfg::add_icache (const string type)
{
  static int num = 0;
  AtomicCfg *new_icache = new AtomicCfg ("icache-" + sidutil::make_attribute (num++), 
					 "libcache.la", 
					 "cache_component_library",
					 "hw-cache-" + type);
  add_child (new_icache);
  assert (cache_flush_net);
  cache_flush_net->add_output (1, new_icache, "flush-all");
  if (icache)
    {
      // we are extending the existing icache chain
      icache->map_name (new_icache, accessor, "downstream", "downstream");
      icache->conn_bus (icache, "downstream", new_icache, "upstream", false);
    }
  else
    {
      // we are chaining off the CPU
      assert (cpu);
      cpu->map_name (new_icache, accessor, "insn-memory", "downstream");
      cpu->conn_bus (cpu, "insn-memory", new_icache, "upstream", false);
    }
  icache = new_icache;
}

void BoardCfg::add_memory (const Mapping &m)
{
  if (main_mapper)
    {
      Mapping map(m);
      main_mapper->map (map.base(0));
    }
}


void BoardCfg::trace_core ()
{
  if (core_probe)
    return;
  core_probe = new AtomicCfg ("probe", "libglue.la", 
			      "glue_component_library", "hw-glue-probe-bus");
  add_child (core_probe);
  assert (main_mapper);
  main_mapper->map_name (core_probe, bus, "access-port", "upstream");
  // this connection needs to be non-virtual, to avoid a feedback loop
  core_probe->conn_bus (core_probe, "downstream", main_mapper, "access-port", false);
  core_probe->set (core_probe, "trace?", "true");
}
