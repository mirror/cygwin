// mainDynamic.cxx - high-tech mainline.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include "../../version.h"

#include "baseCfg.h"
#include "commonCfg.h"
#include <sidmiscutil.h>
#include <getopt.h>


// Stub functions to set breakpoints on
static void sid_pre_configure () {}
static void sid_post_configure () {}
static void sid_pre_run () {}
static void sid_post_run () {}

extern sid::component_library /* *not* DLLIMPORT */ config_component_library;


typedef struct {
  const char *name;
  const char *blurb;
  BoardCfg * (*factory) (const string name, SessionCfg *sess);
} boardspec;


static BoardCfg * 
mk_basic (const string name, SessionCfg *sess)
{
  return new BoardCfg (name, "none", sess, false, true, true);
}


static boardspec boards [] = {
  {"basic", "basic cpu + memory board", & mk_basic},
  {0, 0, 0}
};
    
void
version ()
{
  cout << "sid " << SID_RELEASE << endl;
  cout << "Copyright 1999-2002 Red Hat, Inc." << endl;
  cout << "sid is free software, covered by the GNU General Public License," << endl;
  cout << "as interpreted by the COPYING.SID terms." << endl;
}

 
void
usage ()
{
  cout << "Usage: sid OPTIONS [FILE] ..." << endl;
  cout << "Options:" << endl;
  cout << "-h, --help            Print this help" << endl;
  cout << "-v, --version         Print version" << endl;
  cout << "-n, --no-run          Load/check configuration but do not run simulation" << endl;
  cout << "-f FILE               Also read configuration FILE" << endl;
  cout << "-e LINE               Also do configuration LINE" << endl;
  cout << endl;
  cout << "All -b options are performed first, in sequence. " << endl;
  cout << "All -f/-e options are performed after -b options, in sequence." << endl;
  cout << "FILE names supplied without -f are done last, in sequence." << endl;
  cout << endl;
  cout << "--persistent          Run top-level loop indefinitely" << endl;
  cout << "--rc                  Pass stop code as simulator exit rc" << endl;
  cout << "--save-temps=FILE     Write config to FILE, '-' for stdout." << endl;
  cout << "--wrap=COMPONENT      Turn on SID API tracing for COMPONENT" << endl;
  cout << "--verbose             Turn on run-time verbosity settings" << endl;
  cout << "--tksm                Add a an experimental Tk system monitor" << endl;
  cout << "--tksched             Add a simple Tk sim-scheduler controller" << endl;
  cout << "--board=BOARD         Instantiate builtin BOARD; remaining options" << endl
       << "                      apply to most recently instantiated BOARD." << endl
       << "                      BOARD may be any of:" << endl;
  for (boardspec *board = boards; board->name; ++board)
    cout << "                         " << board->name << "\t" << board->blurb << endl;
  cout << endl
       << "Board-specific options:" << endl;
  cout << "--cpu=CPU             Change board to use CPU" << endl;
  cout << "--load=FILE           Load FILE into board's memory" << endl
       << "                      Sub options (comma separated):" << endl
       << "                         bus=MAPPER   Load file into bus MAPPER" << endl
       << "                         cpu=CPU      Set pc of cpu CPU on load" << endl
       << "                         all-cpus     Shortcut for using all CPUs" << endl;
  cout << "--gloss               Give board a gloss (operating system)" << endl;
  cout << "--gdb=PORT            Give board a gdb stub on tcp port PORT" << endl;
  cout << "--engine=scache|pbb   Set board's engine type to scache or pbb" << endl;
  cout << "--sidrtc=ADDR         Add a real-time clock at address ADDR" << endl;
  cout << "--sidcodec=ADDR       Add an audio codec at address ADDR" << endl;
  cout << "--insn-count=COUNT    Set block of uninterrupted ticks for insns" << endl;
  cout << "--enable-warnings     Turn on CPU execution warnings" << endl;
  cout << "--final-insn-count    Turn on CPU instruction count summary" << endl;
  cout << "--trace-extract       Turn on CPU insn decode tracing" << endl;
  cout << "--trace-semantics     Turn on CPU execute tracing" << endl;
  cout << "--trace-disassemble   Turn on CPU execute disassembly" << endl;
  cout << "--trace-counter       Turn on CPU insn tracing" << endl;
  cout << "--trace-core          Turn on bus access tracing" << endl;
  cout << "--icache=TYPE         Put insn cache hw-cache-TYPE on board" << endl;
  cout << "--dcache=TYPE         Put data cache hw-cache-TYPE on board" << endl
       << "                      e.g., direct/64kb/32, 4way/256kb/64/lru" << endl;
  cout << "--EB | --EL           Set powerup CPU mode to big/little endian" << endl;
  cout << "--gprof=FILE          Turn on GPROF profiling, collect in FILE " << endl
       << "                      Sub option (comma separated):" << endl
       << "                         cycles[=N]   collect data every N simulated cycles, " << endl
       << "                                      default N=1." << endl
       << "                         (if cycles is not specified, default to " << endl
       << "                          collect data every Insn-count ticks.)" << endl;
  cout << "--memory-region=BASE,SIZE " << endl
       << "                      Add RAM region from BASE to BASE+SIZE-1." << endl
       << "                      Sub options (comma separated):" << endl
       << "                         bus=MAPPER   Attach memory to bus MAPPER" << endl
       << "                         read-only    Make memory read-only" << endl
       << "                         alias=BASE2  Add an alias at BASE2" << endl
       << "                         file=NAME    Load/save memory from file" << endl
       << "                         mmap         Memory map given file" << endl
       << "                         latency=r:w  Set read, write latencies [0:0]" << endl
       << "                         latency=rw   Set both latencies [0]" << endl;
  cout << "--ulog-level=LEVEL    Set the logging level for the current board" << endl;
  cout << "--ulog-mode=less|match|equal" << endl
       << "                      Set the logging mode for the current board" << endl;
  cout << "--ulog-file=-|FILE    Set the log file name" << endl;
  cout << endl
       << " note: most board-specific options can be used in board-neutral position " << endl
       << " where they are interpreted as session-specific or default settings. " << endl;
}

string optstring (const char *def=NULL)
{
  const char *in = optarg ? optarg : (def ? def : "");
  string str("");
  str.insert (0, in, strlen(in));
  return str;
}

sid::host_int_4 addr (const string optname, const string in)
{
  sid::host_int_4 val = 0;
  if (sidutil::parse_unsigned_numeric_attribute (in, val)
      != sid::component::ok)
    {
      cerr << "cannot parse address option " << optname << " = '" << in << "'" << endl;
      exit (10);
    }
  return val;
}

sid::host_int_4 optaddr (const string optname)
{
  return addr (optname, optstring());
}

void try_load_file (const string memspec,
		    BoardCfg *board,
		    SessionCfg *sess)
{

  vector <CpuCfg *> cpus;
  MapperCfg *map = NULL;

  static int i = 0;
  assert (sess);
  LoaderCfg *loader = new LoaderCfg ("loader-" + sidutil::make_numeric_attribute (i), sess); 
  assert (loader);

  vector<string> toks = sidutil::tokenize (memspec, ",");

  for (vector<string>::const_iterator i = toks.begin();
       i != toks.end(); ++i)
    {
      vector<string> subtoks = sidutil::tokenize (*i, "=");
      switch (subtoks.size ())
	{
	case 1:
	  if (subtoks[0] == "all-cpus")
	    {
	      CpuCfg::get_all (cpus);
	    }
	  else
	    {
	      loader->set_file (*i);
	    }
	  break;
	case 2:
	  if (subtoks[0] == "bus")
	    {
	      map = MapperCfg::get_by_name (subtoks[1]);
	      if (map == NULL)
		{
		  cerr << "error: --load bus=" 
		       << *i << " refers to unknown memory bus" << endl;
		  exit (12);
		}
	    }	  
	  else if (subtoks[0] == "cpu")
	    {
	      CpuCfg *cpu = CpuCfg::get_by_name (subtoks[1]);
	      if (cpu == NULL)
		{
		  cerr << "error: --load cpu=" 
		       << *i << " refers to unknown cpu" << endl;
		  exit (12);
		}
	      else
		cpus.push_back (cpu);
	    }
	  else
	    goto bad_sub_option;
	  break;
	default:
	  goto bad_sub_option;
	}
      continue;
    bad_sub_option:
      cerr << "error: unknown sub-option to --load: " << *i << endl;
      exit (19);      
    }
  

  // try using specified map, or try to default to using board map

  if (map)
    {
      loader->set_target (map, "access-port");
      sess->set_loader (loader);
    }
  else
    {
      if (board)
	{
	  assert (board->main_mapper);
	  loader->set_target (board->main_mapper, "access-port");
	  board->set_loader (loader);
	}
      else
	{
	  cerr << "no bus named and no default board map for --load" << endl;
	  exit (20);	  
	}
    }

  // try to default to using board cpu

  if (cpus.size () == 0)
    {
      if (board)
	cpus.push_back (board->cpu);
      else
	cerr << "warning: no cpus specified and no default board cpu for --load" << endl;	  
    }

  // construct loader

  for (vector<CpuCfg *>::const_iterator c = cpus.begin(); 
       c != cpus.end (); ++c)
    {      
      assert (*c);
      loader->add_cpu (*c);
    }
}

void try_add_memory (const string memspec, 
		     BoardCfg *board, 
		     SessionCfg *sess)
{
  MemCfg *mem = NULL;
  static int memcount = 0;
  vector<sid::host_int_4> bases;
  vector<string> toks = sidutil::tokenize (memspec, ",");
  bool mmap_p = false;
  bool read_only_p = false;
  string filename ("");

  MapperCfg *map = NULL;
  assert (sess);

  if (toks.size() < 2)
    {
      cerr << "error: --memory-region requires BASE,SIZE argument" << endl;
      exit (11);
    }
  bases.push_back (addr ("--memory-region BASE", toks[0]));
  sid::host_int_4 size = addr ("--memory-region SIZE", toks[1]);

  mem = new MemCfg ("extra-mem-" + 
		    sidutil::make_numeric_attribute (memcount++));

  assert (mem);
  mem->set_size (size);
  for (vector<string>::const_iterator i = (toks.begin() + 2);
       i != toks.end(); ++i)
    {
      vector<string> subtoks = sidutil::tokenize (*i, "=");
      switch (subtoks.size())
	{
	case 1:
	  assert (mem);
	  if (subtoks[0] == "read-only")
	    read_only_p = true;
	  else if (subtoks[0] == "mmap")
	    mmap_p = true;
	  else
	    goto bad_sub_option;
	  break;
	case 2:
	  if (subtoks[0] == "bus")
	    {
	      map = MapperCfg::get_by_name (subtoks[1]);
	      if (map == NULL)
		{
		  cerr << "error: --memory-region bus=" 
		       << *i << " refers to unknown memory bus" << endl;
		  exit (12);
		}
	    }
	  else if (subtoks[0] == "alias")
	    {
	      bases.push_back (addr ("--memory-region alias", subtoks[1]));
	    }
	  else if (subtoks[0] == "file")
	    {
	      assert (mem);
	      filename = subtoks[1];
	    }
	  else if (subtoks[0] == "latency")
	    {
	      vector<string> lat = sidutil::tokenize (subtoks[1], ":");
	      assert (mem);
	      switch (lat.size())
		{
		case 1:
		  mem->set_read_latency (addr ("--memory-region latency", lat[0]));
		  mem->set_write_latency (addr ("--memory-region latency", lat[0]));
		  break;
		case 2:
		  mem->set_read_latency (addr ("--memory-region read latency", lat[0]));
		  mem->set_write_latency (addr ("--memory-region write latency", lat[1]));
		  break;
		default:
		  cerr << "error: --memory-region latency must be RW or R:W" << endl;
		  exit (12);
		}
	    }
	  else
	    goto bad_sub_option;
	  break;
	default:
	  goto bad_sub_option;
	}
      continue;
    bad_sub_option:
      cerr << "error: unknown sub-option to --memory-region: " << *i << endl;
      exit (13);      
    }

  // try to default to using board map if no map has been specified.

  if (map)
    {
      sess->add_child (mem);
    }
  else
    {
      if (board && board->main_mapper)
	{
	  board->add_child (mem);
	} 
      else
	{
	  cerr << "no bus named and no default board map for --memory-region" << endl;
	  exit (18);
	}
    } 

  assert (mem);
  string port ( read_only_p ? "read-only-port" : "read-write-port");

  // map the memory into the mapper, at all specified locations.
  for (vector<sid::host_int_4>::const_iterator i = bases.begin();
       i != bases.end(); ++i)
    {
      Mapping m = Mapping()
	.slave(mem).bus(port)
	.low(*i).high((*i) + size - 1);
      if (map)
	map->map (m.base(0));
      else if (board)
	board->add_memory (m);
      else
	assert (false); // impossible. we already checked!
    }

  // handle image-file loading, mmaping and saving
  if (filename.size() > 0)
    {
      mem->set (mem, "image-file", filename);      
      string loadpin (mmap_p ? "image-mmap" : "image-load");
      sess->init_seq->add_output (1, mem, loadpin);      
      if (! (mmap_p || read_only_p))
	sess->shutdown_seq->add_output (6, mem, "image-store");
    }
}


void try_add_gprof(const string optstring, BoardCfg *board)
{
  gprof_type type;
  string interval_string;
  int interval;
  vector<string> toks = sidutil::tokenize (optstring, ",");

  type = instruction_count;	// default type value
  if (toks.size() > 1)		// if we have a type argument
    {
      vector<string> subtoks = sidutil::tokenize (toks[1], "=");
      
      if (subtoks[0] == "cycles")	// If it is cycles
        {
          type = simulated_cycles;
          interval = 1;		// default interval value
          if (subtoks.size() > 1)	// if we have a number of cycles argument
            {
              interval_string = subtoks[1];
              interval = atoi(interval_string.c_str());
              if (interval < 1) 
                {
                  interval = 1;
                }
            }
        }
      else
        {
          cerr << "error: unknown sub-option to --gprof: " << subtoks[0] << endl;
          exit (21);      
        }
    }

  board->set_gprof (toks[0], type, interval);

}



void option_requires_board (BoardCfg *curr_board, 
			    const string option_name)
{
  if (! curr_board)
    {
      cerr << "error: option --" << option_name << " must be preceeded by option --board" << endl;
      exit (7);
    }
}


struct Defs {
  Defs () : cpu(""), 
	    enable_warnings (false),
            final_insn_count (false),
	    trace_extract (false),
	    trace_semantics (false),
	    trace_disassemble (false),
	    trace_counter (false),
	    trace_core (false),
	    ulog_level (0),
	    ulog_mode ("less"),
	    ulog_file ("-"),
	    step_insn_count ("10000")
  {}
  string cpu;
  bool enable_warnings;
  bool final_insn_count;
  bool trace_extract;
  bool trace_semantics;
  bool trace_disassemble;
  bool trace_counter;
  bool trace_core;
  sid::host_int_4 ulog_level;
  string ulog_mode;
  string ulog_file;
  string step_insn_count;
};
  

void need_sess (SessionCfg *&sess)
{
  if (! sess)
    sess = new SessionCfg ("");
}


// main line
int
main(int argc, char* argv[])
{
  vector< pair<bool,string> > config_items;
  bool dry_run_p = false;
  bool verbose_p = false;
  bool persistent_p = false;
  bool rc_p = false;
  string output_file ("");
  SessionCfg *sess = NULL;
  BoardCfg *curr_board = NULL;
  int nboards = 0;

  if (argc == 1)
    {
      version ();
      cout << endl;
      usage ();
      return 1;
    }

  Defs defaults;

  enum option_num { opt_help, opt_version, opt_save_temps, opt_wrap, 
		    opt_verbose, opt_tksched, opt_enable_warnings,
		    opt_persistent, opt_rc, opt_no_run, opt_sidrtc, opt_sidcodec, 
		    opt_tksm, opt_board, opt_cpu, opt_gdb, opt_gloss, opt_engine, 
		    opt_insn_count, opt_load, opt_icache, opt_dcache, 
		    opt_memory_region, opt_trace_extract, opt_trace_semantics,
		    opt_trace_disassemble, opt_trace_counter, opt_trace_core,
		    opt_final_insn_count, opt_eb, opt_el, opt_gprof,
		    opt_ulog_level, opt_ulog_mode, opt_ulog_file };
		    
  int curr_opt;

  static struct option long_options [] = {
    // name, has-arg, *flag, val
    
    // short-option equivalents
    {"help",    no_argument, NULL, 'h' },
    {"version", no_argument, NULL, 'v' },
    {"no-run",  no_argument, NULL, 'n' },

    // per-session settings
    {"save-temps",      required_argument, & curr_opt, opt_save_temps },
    {"wrap",            required_argument, & curr_opt, opt_wrap },
    {"verbose",         no_argument, & curr_opt, opt_verbose },
    {"tksched",         no_argument, & curr_opt, opt_tksched },
    {"enable-warnings", no_argument, & curr_opt, opt_enable_warnings },
    {"persistent",      no_argument, & curr_opt, opt_persistent },
    {"rc",              no_argument, & curr_opt, opt_rc },
    {"tksm",            no_argument, & curr_opt, opt_tksm },


    // per-board settings
    {"board",             required_argument, & curr_opt, opt_board },
    {"cpu",               required_argument, & curr_opt, opt_cpu },    
    {"gdb",               required_argument, & curr_opt, opt_gdb },
    {"gprof",             required_argument, & curr_opt, opt_gprof },
    {"engine",            required_argument, & curr_opt, opt_engine },
    {"sidrtc",          required_argument, & curr_opt, opt_sidrtc },
    {"sidcodec",        required_argument, & curr_opt, opt_sidcodec },
    {"insn-count",        required_argument, & curr_opt, opt_insn_count },
    {"load",              required_argument, & curr_opt, opt_load },
    {"icache",            required_argument, & curr_opt, opt_icache },
    {"dcache",            required_argument, & curr_opt, opt_dcache },
    {"memory-region",     required_argument, & curr_opt, opt_memory_region },
    {"gloss",             no_argument, & curr_opt, opt_gloss },
    {"trace-extract",     no_argument, & curr_opt, opt_trace_extract },
    {"trace-semantics",   no_argument, & curr_opt, opt_trace_semantics },
    {"trace-disassemble", no_argument, & curr_opt, opt_trace_disassemble },
    {"trace-counter",     no_argument, & curr_opt, opt_trace_counter },
    {"trace-core",        no_argument, & curr_opt, opt_trace_core },
    {"final-insn-count",  no_argument, & curr_opt, opt_final_insn_count },
    {"EB",                no_argument, & curr_opt, opt_eb },
    {"EL",                no_argument, & curr_opt, opt_el },
    {"ulog-level",        required_argument, &curr_opt, opt_ulog_level },
    {"ulog-mode",         required_argument, &curr_opt, opt_ulog_mode },
    {"ulog-file",         required_argument, &curr_opt, opt_ulog_file },
    { 0, 0, NULL, 0 }
 };
  
  while (true)
    {
      int c = getopt_long (argc, argv, "+hvne:f:",
			   long_options, NULL);
      if (c == EOF)
	break;

      switch (c)
	{
	case 'h':
	  usage ();
	  return 0;

	case 'v':
	  version ();
	  return 0;
	  
	case 'n':
	  dry_run_p = true;
	  break;

	case 'e':
	  config_items.push_back (make_pair (false, optstring()));
	  break;

	case 'f':
	  config_items.push_back (make_pair (true, optstring()));
	  break;

	case 0:

	  switch ((enum option_num)curr_opt)
	    {
	    case opt_save_temps:
	      output_file = optstring();
	      break;
	      

	    case opt_board:
	      {
		need_sess (sess);
		if (curr_board)
		  sess->add_child (curr_board);
		curr_board = NULL;
		string new_board_type = optstring();
		string new_board_name (new_board_type + "-" + 
				       sidutil::make_attribute(nboards++));
		
		for (boardspec *i = boards; i->name; ++i)
		  {
		    if (new_board_type == i->name)
		      {
			curr_board = i->factory (new_board_name, sess);
			assert (curr_board);
			if (defaults.cpu != "")
			  curr_board->set_cpu (defaults.cpu);
			if (defaults.trace_extract)
			  curr_board->trace_extract();
			if (defaults.trace_semantics)
			  curr_board->trace_semantics();
			if (defaults.trace_disassemble)
			  curr_board->trace_disassemble();
			if (defaults.trace_counter)
			  curr_board->trace_counter();
			if (defaults.final_insn_count)
			  curr_board->final_insn_count();
			if (defaults.trace_core)
			  curr_board->trace_core();
			if (defaults.enable_warnings)
			  curr_board->enable_warnings();
			curr_board->set_ulog_level (defaults.ulog_level);
			curr_board->set_ulog_mode (defaults.ulog_mode);
			curr_board->set_ulog_file (defaults.ulog_file);
			if (defaults.step_insn_count != "10000")
			  curr_board->set_step_insn_count(defaults.step_insn_count);
			break;
		      }
		  }
		if (! curr_board)
		  {
		    cerr << "unknown board: " << new_board_type << endl;
		    exit (5);
		  }
	      }
	      break;


	    case opt_tksched:
	      if (sess)
		sess->use_tksched();
	      break;

	    case opt_tksm:
	      if (sess)
		sess->use_tksm();
	      break;
	      
	    case opt_verbose:
	      verbose_p = true;
	      if (sess)
		sess->verbose = true;
	      break;
	     
	    case opt_gprof:
	      option_requires_board (curr_board, "gprof");
	      try_add_gprof(optstring(), curr_board);
	      break;

	    case opt_gdb:
	      option_requires_board (curr_board, "gdb");
	      curr_board->set_gdb (optstring());
	      persistent_p = true;
	      break;

	    case opt_gloss:
	      option_requires_board (curr_board, "gloss");
	      curr_board->use_gloss ();
	      break;

	    case opt_load:
	      need_sess (sess);
	      try_load_file (optstring(), curr_board, sess);
	      break;
	      
	    case opt_cpu:
	      if (curr_board)
		curr_board->set_cpu (optstring());
	      else
		defaults.cpu = optstring();
	      break;	      
	      
	    case opt_trace_extract:
	      if (curr_board)
		curr_board->trace_extract();
	      else
		defaults.trace_extract = true;
	      break;

	    case opt_trace_semantics:
	      if (curr_board)
		curr_board->trace_semantics();
	      else
		defaults.trace_semantics = true;
	      break;

	    case opt_trace_disassemble:
	      if (curr_board)
		curr_board->trace_disassemble();
	      else
		defaults.trace_disassemble = true;
	      break;

	    case opt_trace_counter:
	      if (curr_board)
		curr_board->trace_counter();
	      else
		defaults.trace_counter = true;
	      break;

	    case opt_final_insn_count:
	      if (curr_board)
		curr_board->final_insn_count();
	      else
		defaults.final_insn_count = true;
	      break;

	    case opt_trace_core:
	      if (curr_board)
		curr_board->trace_core();
	      else
		defaults.trace_core = true;
	      break;

	    case opt_enable_warnings:
	      if (curr_board)
		curr_board->enable_warnings();
	      else
		defaults.enable_warnings = true;
	      break;

	    case opt_wrap:
	      {
		string c (optstring());
		if (sess)
		  sess->use_tcl_bridge ();
		if (! AtomicCfg::wrap_component (c))
		  {
		    cerr << "error: no component named '" << c << "' to wrap" << endl;
		    exit (9);
		  }
	      }
	      break;

	      
	    case opt_insn_count:
	      if (curr_board)
		curr_board->set_step_insn_count(optstring());
	      else
		defaults.step_insn_count = optstring();
	      break;

	    case opt_persistent:
	      persistent_p = true;
	      break;

	    case opt_rc:
	      rc_p = true;
	      break;

	    case opt_sidrtc:
	      option_requires_board (curr_board, "sidrtc");
	      curr_board->add_sidrtc (optaddr("sidrtc"));
	      break;

	    case opt_sidcodec:
	      option_requires_board (curr_board, "sidcodec");
	      curr_board->add_sidcodec (optaddr("sidcodec"));
	      break;
	      
	    case opt_eb:
	      option_requires_board (curr_board, "EB");
	      curr_board->set_endian ("big");
	      break;

	    case opt_el:
	      option_requires_board (curr_board, "EL");
	      curr_board->set_endian ("little");
	      break;

	    case opt_memory_region:
	      need_sess (sess);
	      try_add_memory (optstring(), curr_board, sess);
	      break;

	    case opt_dcache:
	      option_requires_board (curr_board, "dcache");
	      curr_board->add_dcache (optstring());
	      break;

	    case opt_icache:
	      option_requires_board (curr_board, "icache");
	      curr_board->add_icache (optstring());
	      break;

	    case opt_engine:
	      {
		option_requires_board (curr_board, "engine");
		string engine = optstring();
		if (engine == "pbb" || engine == "scache")
		  curr_board->set_engine (optstring());
		else
		  {
		    cerr << "error: --engine must be either pbb or scache" << endl;
		    exit (8);
		  }
	      }
	      break;

	    case opt_ulog_level:
	      if (curr_board)
		curr_board->set_ulog_level (optaddr ("ulog-level"));
	      else
		{
		  defaults.ulog_level = optaddr ("ulog-level");
		  need_sess (sess);
		  sess->set_ulog_level (optaddr ("ulog-level"));
		}
	      break;

	    case opt_ulog_mode:
	      if (curr_board)
		curr_board->set_ulog_mode (optstring ());
	      else
		{
		  defaults.ulog_mode = optstring ();
		  need_sess (sess);
		  sess->set_ulog_mode (optstring ());
		}
	      break;

	    case opt_ulog_file:
	      need_sess (sess);
	      sess->add_ulog_file (optstring ());
	      if (curr_board)
		curr_board->set_ulog_file (optstring ());
	      else
		{
		  defaults.ulog_file = optstring ();
		  sess->set_ulog_file (optstring ());
		}
	      break;
	    }
	  break;
	  

	case '?':
	default:
	  usage ();
	  return 1;
	}
    }

  if (sess && curr_board)
    sess->add_child (curr_board);

  if (persistent_p)
    config_items.push_back (make_pair (false, string("set main persistent? true")));

  if (verbose_p)
    config_items.push_back (make_pair (false, string("set main verbose? true")));

  sid::component* main_component = 
    config_component_library.create_component("sid-control-cfgroot");
  if(main_component == 0)
    {
      cerr << "Cannot instantiate configuration root component." << endl;
      return 2;
    }

  sid_pre_configure ();
  Writer config_writer (main_component, output_file);

  
  // Treat remaining arguments as file names
  for (unsigned j=optind; j<argc; j++)
    {
      config_items.push_back (make_pair (true, string(argv[j])));
    }

  // instantiate any built-in boards
  if (sess)
    sess->write_all (config_writer);
  
  // NB: There is no problem if config_items is empty.  cfgroot will
  // abort a run if there are no other configured components.

  for (vector <pair <bool, string> >::const_iterator i = config_items.begin();
       i != config_items.end(); ++i)
    {
      if (i->first == true)
	config_writer.write_file (i->second);
      else
	config_writer.write_line (i->second);
    }
  
  sid_post_configure ();

  if (! dry_run_p)
    {
      // drive the root's "run" pin.
      sid_pre_run ();
      sid::pin* run_pin = main_component->find_pin ("run!");
      if (! run_pin)
	{
	  cerr << "Cannot find root run pin." << endl;
	  return 4;
	}
      
      // run the simulation
      run_pin->driven (0);
      // the simulation has ended.
      sid_post_run ();
    }

  // fetch exit-code from cfgroot
  sid::host_int_4 code;
  sid::component::status s = 
    sidutil::parse_attribute (main_component->attribute_value ("stop-code"), code);
  if (s != sid::component::ok)
    code = 0;

  // delete cfgroot and the rest of the world
  config_component_library.delete_component (main_component);

  if (rc_p)
    return ((code >> 8) & 0xff); // extract just the rc portion of the wait struct
  else
    return 0;
}


#ifndef SID_STATIC
// Define a stub lt_preloaded_symbols[], as if libtool's
// "--dlpreopen libnull.la" linker option was given (for an empty libnull.la).
// This must agree with ltmain.sh & libltdl.
struct symbols {
  const char *name;
  void* address;
};
extern struct symbols lt_preloaded_symbols[];
struct symbols lt_preloaded_symbols[] = { 0, 0 };
#endif // !SID_STATIC

