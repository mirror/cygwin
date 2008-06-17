
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
  set (this, "size", "0x" + sidutil::make_numeric_attribute(sz, std::ios::hex));
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
CacheCfg::CacheCfg (const string name, sid::host_int_4 size) : 
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-cache-buffer-" + sidutil::make_attribute (size)),
  my_assoc (""),
  my_size (size),
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
      my_comptype = "hw-cache-buffer-" + sidutil::make_attribute (my_size);
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

// BlockingCacheCfg
BlockingCacheCfg::~BlockingCacheCfg () {}
BlockingCacheCfg::BlockingCacheCfg (const string name) : 
  CacheCfg (name),
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-blocking-cache-buffer-8")
{}

// direct caches
BlockingCacheCfg::BlockingCacheCfg (const string name, 
		    const sid::host_int_4 size, 
		    const sid::host_int_4 linesize) : 
  CacheCfg (name, size, linesize),
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-blocking-cache-direct/" + 
	     sidutil::make_attribute(size) + "kb/" +
	     sidutil::make_attribute(linesize))
{}

// complex associative caches
BlockingCacheCfg::BlockingCacheCfg (const string name, 
	  const string assoc, 
	  const sid::host_int_4 size, 
	  const sid::host_int_4 linesize, 
	  const string replace) : 
  CacheCfg (name, assoc, size, linesize, replace),
  ComponentCfg (name),
  AtomicCfg (name, 
	     "libcache.la", 
	     "cache_component_library",
	     "hw-blocking-cache-" + assoc + "/" + 
	     sidutil::make_attribute(size) + "kb/" +
	     sidutil::make_attribute(linesize) + "/" +
	     replace)
{}

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
  relate (this, "sim-sched", sess->sim_sched);
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

void SchedCfg::set_priority (int n, int pv)
{
  string s = sidutil::make_attribute (n);
  string ps = sidutil::make_attribute (pv);
  set (this, s + "-priority", ps);
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
    map_accessor += "0x" + sidutil::make_numeric_attribute(m._wordsz.val, std::ios::hex) + "*";

  if (m._base.specified)
    map_accessor += "0x" + sidutil::make_numeric_attribute(m._base.val, std::ios::hex) + "=";

  // always include a low and a high. default to 0 if not specified.
  // FIXME: perhaps issuing a warning here would be better?
  map_accessor += "0x" + 
    sidutil::make_numeric_attribute(m._low.specified ? 
				    m._low.val : 0, std::ios::hex) 
    + "-0x"
    + sidutil::make_numeric_attribute(m._high.specified ? 
				      m._high.val : 0, std::ios::hex);

  // Both stride and width must be specified for either to make sense.
  if (m._stride.specified && m._width.specified)
    map_accessor += ",0x" 
      + sidutil::make_numeric_attribute(m._stride.val, std::ios::hex) 
      + ",0x"
      + sidutil::make_numeric_attribute(m._width.val, std::ios::hex);
  
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
    reversible_p (false),
    use_stdio (true),
    need_gprof (false),
    need_core_probe (false),
    maybe_model_busses (false),
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

void
SessionCfg::add_profile_config (const string &name, const string &options)
{
  set (main_obj, "dynamic-config!", name + "|" + options);
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

  // Setup all memory regions to be reversible, if specified.
  if (reversible_p)
    for (vector<MemCfg *>::iterator it = memory.begin ();
	 it != memory.end ();
	 ++it)
      {
	set (*it, "reversible?", "true");
	relate (*it, "sim-sched", sim_sched);
	conn_pin (sim_sched, "time-set", *it, "restore-to-time!");
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

string
SessionCfg::wrap_config ()
{
  string spec;
  for (vector<AtomicCfg *>::const_iterator it = wrapped_components.begin ();
       it != wrapped_components.end ();
       ++it)
    spec += " --wrap=" + (*it)->get_name ();
  return spec;
}

// Process the argument to --profile-config which will
// be a subset of the allowable SID command line options
// which can be dynamically changed.
//
void
SessionCfg::profile_config_error (const string &spec)
{
  cerr << "error: invalid argument to --profile-config: " << spec << endl;
  exit (8);
}

string
SessionCfg::profile_opt_value (const string& opt, const vector<string>& opt_parts, unsigned max_parts)
{
  unsigned size = opt_parts.size ();
  if (size > max_parts)
    profile_config_error (opt); // doesn't return

  if (max_parts == 1)
    return "true";

  return opt_parts[1];
}

string
SessionCfg::profile_opt_int_value (const string& opt, const vector<string>& opt_parts)
{
  unsigned size = opt_parts.size ();
  if (size != 2)
    profile_config_error (opt); // doesn't return

  unsigned n;
  sid::component::status s = sidutil::parse_attribute (opt_parts[1], n);
  if (s != sid::component::ok)
    profile_config_error (opt); // doesn't return

  return opt_parts[1];
}

string
SessionCfg::profile_opt_gprof_value (const string& opt, const vector<string>& opt_parts)
{
  unsigned size = opt_parts.size ();
  if (size < 2 || size > 3)
    profile_config_error (opt); // doesn't return

  vector<string> sub_parts = sidutil::tokenize (opt_parts[1], ",");
  if (sub_parts.size () > 2)
    profile_config_error (opt); // doesn't return

  string value = sub_parts[0];
  if (sub_parts.size () == 2)
    {
      if (sub_parts[1] != "cycles")
	profile_config_error (opt); // doesn't return

      if (size == 3)
	{
	  unsigned n;
	  sid::component::status s = sidutil::parse_attribute (opt_parts[2], n);
	  if (s != sid::component::ok)
	    profile_config_error (opt); // doesn't return
	  value += "," + opt_parts[2];
	}
      else
	value += ",1";
    }

  need_gprof = true;
  return value;
}

bool
SessionCfg::match_profile_opt (const string &opt, const string& want, unsigned min_size)
{
  unsigned opt_size = opt.size ();
  unsigned want_size = want.size ();
  if (opt_size < min_size || opt_size > want_size)
    return false;
  return opt == want.substr (0, opt_size);
}

void 
SessionCfg::profile_config (const string &spec)
{
  // Extract the name of the config profile
  vector<string> parts = sidutil::tokenize (spec, ":");
  if (parts.size () != 2)
    profile_config_error (spec);
  string name = parts[0];

  // Initialize the candidate options to their default values.
  string trace_extract = "false";
  string trace_semantics = "false";
  string trace_disassemble = "false";
  string trace_core = "false";
  string trace_counter = "false";
  string ulog_level = "0";
  string ulog_mode = "less";
  string wrap = "";
  string verbose = "false";
  string final_insn_count = "false";
  string gprof = "";
  string insn_count = "10000";
  // mep-specific options
  string model_busses = "false";

  // Now examine the spec and reset those which are specified.
  vector<string>opts = sidutil::tokenize (parts[1], " ");
  int size = opts.size ();
  for (int i = 0; i < size; ++i)
    {
      const string opt = opts[i];
      vector<string> opt_parts = sidutil::tokenize (opt, "=");
      const string opt_name = opt_parts[0];

      if (match_profile_opt (opt_name, "--trace-extract", 9))
	trace_extract = profile_opt_value (opt, opt_parts, 1);
      else if (match_profile_opt (opt_name, "--trace-semantics", 9))
	trace_semantics = profile_opt_value (opt, opt_parts, 1);
      else if (match_profile_opt (opt_name, "--trace-disassemble", 9))
	trace_disassemble = profile_opt_value (opt, opt_parts, 1);
      else if (match_profile_opt (opt_name, "--trace-core", 11))
	{
	  trace_core = profile_opt_value (opt, opt_parts, 1);
	  need_core_probe = true;
	}
      else if (match_profile_opt (opt_name, "--trace-counter", 11))
	trace_counter = profile_opt_value (opt, opt_parts, 1);
      else if (match_profile_opt (opt_name, "--ulog-level=", 8))
	ulog_level = profile_opt_int_value (opt, opt_parts);
      else if (match_profile_opt (opt_name, "--ulog-mode=", 8))
	ulog_mode = profile_opt_value (opt, opt_parts, 2);
      else if (match_profile_opt (opt_name, "--verbose", 3))
	verbose = profile_opt_value (opt, opt_parts, 1);
      else if (match_profile_opt (opt_name, "--wrap=", 3))
	{
	  string comp_name = profile_opt_value (opt, opt_parts, 2);
	  use_tcl_bridge ();
	  AtomicCfg *comp = AtomicCfg::possible_wrap_name (comp_name);
	  if (! wrap.empty ()) wrap += ",";
	  if (comp)
	    wrap += comp->get_name ();
	  else
	    wrap += comp_name;
	}
      else if (match_profile_opt (opt_name, "--final-insn-count", 3))
	final_insn_count = profile_opt_value (opt, opt_parts, 1);
      else if (match_profile_opt (opt_name, "--gprof=", 3))
	gprof = profile_opt_gprof_value (opt, opt_parts);
      else if (match_profile_opt (opt_name, "--insn-count=", 3))
	insn_count = profile_opt_int_value (opt, opt_parts);
      // mep-specific options
      else if (match_profile_opt (opt_name, "--model-busses", 3))
	model_busses = profile_opt_value (opt, opt_parts, 1);
    }

  if (model_busses != "false")
    maybe_model_busses = true;

  // Now contruct a string representing the complete configuration
  add_profile_config (name,
		      "trace-extract="     + trace_extract     + ":" +
		      "trace-semantics="   + trace_semantics   + ":" +
		      "trace-disassemble=" + trace_disassemble + ":" +
		      "trace-core="        + trace_core        + ":" +
		      "trace-counter="     + trace_counter     + ":" +
		      "ulog-level="        + ulog_level        + ":" +
		      "ulog-mode="         + ulog_mode         + ":" +
		      "wrap="              + wrap              + ":" +
		      "verbose="           + verbose           + ":" +
		      "final-insn-count="  + final_insn_count  + ":" +
		      "gprof="             + gprof             + ":" +
		      "insn-count="        + insn_count        + ":" +
		      // mep-specific options
		      "model-busses="      + model_busses);
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
  conn_pin (this, "eflags-set", cpu, "eflags-set!");
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

  conn_pin (cpu, "sample-gprof", this, "sample");

  sess->shutdown_seq->add_output (7, this, "store");
  relate (this, "target-component", cpu);
  conn_pin (cpu, "cg-caller", this, "cg-caller");
  conn_pin (cpu, "cg-callee", this, "cg-callee");
  conn_pin (cpu, "gprof-pc-hi", this, "pc-hi");
  conn_pin (cpu, "gprof-pc", this, "pc");
  if (cpu->comp_type().substr(0, 10) == "hw-cpu-mep")
    set (this, "bucket-size", "2"); // bytes-per-bucket
  else if (cpu->comp_type().substr(0, 9) == "hw-cpu-sh")
    set (this, "bucket-size", "2"); // bytes-per-bucket
  else
    set (this, "bucket-size", "4"); // bytes-per-bucket
  set (this, "output-file", filename);
}

// Create a gprof component but don't activate it
GprofCfg::GprofCfg (const string name,
		    CpuCfg *cpu, 
		    SessionCfg *sess) :
  ComponentCfg (name),
  AtomicCfg ( name, "libprof.la", 
	      "prof_component_library",
	      "sw-profile-gprof")
{
  assert (cpu);
  assert (sess);

  sess->shutdown_seq->add_output (7, this, "store");
  relate (this, "target-component", cpu);
  if (cpu->comp_type().substr(0, 10) == "hw-cpu-mep")
    set (this, "bucket-size", "2"); // bytes-per-bucket
  else if (cpu->comp_type().substr(0, 9) == "hw-cpu-sh")
    set (this, "bucket-size", "2"); // bytes-per-bucket
  else
    set (this, "bucket-size", "4"); // bytes-per-bucket
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

  // the stub and socket need to be connected to the dynamic_configurator.
  if (board->dynamic_configurator)
    {
      if (! stub->possibly_wrapped ())
	{
	  Relation (board->dynamic_configurator, "client", stub).write_to (w);
	}
      if (! sock->possibly_wrapped ())
	{
	  Relation (board->dynamic_configurator, "client", sock).write_to (w);
	}
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
  loader (NULL),
  core_probe (0),
  dynamic_configurator (NULL),
  start_config (""),
  warmup_funcs ("_Sid_config"),
  step_insn_count ("10000"),
  step_insn_count_1_required_p (false)
{
  assert (sess);
  cpu = new CpuCfg ("cpu", default_cpu_variant, sess);
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
 
  sess->shutdown_seq->add_output (0, cpu, "print-insn-summary!");

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

void BoardCfg::write_load (Writer &w)
{
  if (gloss)
    {
      // Create a dynamic reconfigurator to be used by this gloss
      dynamic_configurator = new AtomicCfg ("dynamic-config", "libconfig.la", 
					    "config_component_library",
					    "sid-control-dynamic-configurator");
      sess->reset_net->add_output (2, dynamic_configurator, "reset");
      int slot = sess->sim_sched->add_subscription (dynamic_configurator, "step!", "step-control");
      sess->sim_sched->set_priority (slot, SchedCfg::config_priority);
      add_child (dynamic_configurator);

      // If we may need a gprof for dynamic configuration but don't have
      // one yet, then create a disabled one.
      if (! gprof && sess->need_gprof)
	{
	  gprof = new GprofCfg ("gprof", cpu, sess);
	  add_child (gprof);
	}

      // If we may need a core_probe for dynamic configuration but don't have
      // one yet, then create a disabled one.
      if (! core_probe && sess->need_core_probe)
	{
	  trace_core ();
	  core_probe->set (core_probe, "trace?", "false");
	}

      if (sess->verbose)
	set (gloss, "verbose?", "true");
    }
  if (loader)
    if (sess->verbose)
      set (loader, "verbose?", "true");

  set (cpu, "step-insn-count", step_insn_count_1_required_p ? "1" : step_insn_count);

  AggregateCfg::write_load (w);
}

void BoardCfg::write_config (Writer &w)
{
  AggregateCfg::write_config (w);

  // Make the connection which allows the cpu to query the loader regarding
  // addresses.
  if (loader)
    {
      Relation (cpu, "loader", loader).write_to (w);
      PinConnection (cpu, "disassembly-symbol-address", loader, "function?").write_to (w);
    }

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
	  PinConnection (gloss, "debug-rx-eof", sess->stdio_obj, "eof", dst_to_src).write_to(w);
	  PinConnection (gloss, "process-signal", sess->main_obj, "stop!").write_to(w);
	  PinConnection (gloss, "process-signal", sess->yield_net, "input").write_to(w);
	}

      // Set up for dynamic configuration
      assert (dynamic_configurator);
      Relation (dynamic_configurator, "main", sess->main_obj).write_to (w);
      PinConnection (dynamic_configurator, "step-control", cpu, "yield").write_to (w);
      Relation (gloss, "main", sess->main_obj).write_to (w);
      Relation (gloss, "dynamic-configurator", dynamic_configurator).write_to (w);
      PinConnection (gloss, "configure", dynamic_configurator, "configure!").write_to (w);
      PinConnection (dynamic_configurator, "config-result", gloss, "config-result").write_to (w);
      PinConnection (dynamic_configurator, "config-error", gloss, "config-error").write_to (w);

      // Set the starting configuration
      if (start_config.empty ())
	start_config = "sid-internal-warmup";
      Setting (dynamic_configurator, "start-config", start_config).write_to (w);

      // Connect the new-config pin of the dynamic configurator to
      // the components of this board which need to know when the
      // configuration changes.
      assert (cpu);
      Relation (cpu, "main", sess->main_obj).write_to (w);
      if (! cpu->possibly_wrapped ())
	{
	  Relation (dynamic_configurator, "client", cpu).write_to (w);
	}
      if (gprof)
      	{
	  // gprof's configure! attribute will be set by the cpu.
	  Relation (cpu, "gprof", gprof).write_to (w);
      	}
      if (! gloss->possibly_wrapped ())
	{
	  Relation (dynamic_configurator, "client", gloss).write_to (w);
	}
      if (core_probe)
	Relation (cpu, "core-probe", core_probe).write_to (w);

      // Connect the new-config pin of the dynamic configurator to any wrapped child components
      dynamic_config_for_wrapped_children (dynamic_configurator, w);

      // Make the connections which enable the dynamic configurator to change configs on function
      // call and return.
      if (loader)
	{
	  if (! loader->possibly_wrapped ())
	    {
	      Relation (dynamic_configurator, "client", loader).write_to (w);
	    }
	  PinConnection (cpu, "cg-caller", dynamic_configurator, "function-caller!").write_to (w);
	  PinConnection (cpu, "cg-callee", dynamic_configurator, "function-callee!").write_to (w);
	  PinConnection (cpu, "cg-jump", dynamic_configurator, "function-jump!").write_to (w);
	  PinConnection (cpu, "cg-return", dynamic_configurator, "function-return!").write_to (w);
	  Relation (dynamic_configurator, "loader", loader).write_to (w);
	  PinConnection (dynamic_configurator, "function-address", loader, "function?").write_to (w);
	}

      // Initialize the warmup functions and profile functions.
      assert (! warmup_funcs.empty ());
      Setting (dynamic_configurator, "warmup-functions!", warmup_funcs).write_to (w);
      if (! profile_funcs.empty ())
	Setting (dynamic_configurator, "profile-functions!", profile_funcs.substr (1)).write_to (w); // Skip the initial delimeter.
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

  // Set up the cpu to be reversible, if requested.
  if (sess->reversible_p)
    {
      Setting (cpu, "reversible?", "true").write_to (w);
      PinConnection (sess->sim_sched, "time-set", cpu, "restore-to-time!").write_to(w);
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
  step_insn_count = count;
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
  cpu->set (cpu, "final-insn-count?", "true");
}

void BoardCfg::trace_counter ()
{
  assert (cpu);
  cpu->set (cpu, "trace-counter?", "true");
  step_insn_count_1_required_p = true;
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

void BoardCfg::add_profile_func (const string &spec)
{
  if (! spec.empty ())
    profile_funcs += "|" + spec;
}

void BoardCfg::add_warmup_func (const string &funcs)
{
  if (! funcs.empty ())
    warmup_funcs += "," + funcs;
}

void BoardCfg::set_warmup (bool w)
{
  if (w)
    start_config = "sid-internal-warmup";
}

void BoardCfg::set_start_config (const string &config)
{
  if (! start_config.empty ())
    return;

  if (! config.empty ())
    {
      start_config = "sid-internal-start-" + get_name ();
      sess->profile_config (start_config + ":" + config.substr (1));  // get past leading comma
    }
}
