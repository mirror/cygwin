// mainDynamic.cxx - high-tech mainline.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include "../../version.h"

#include "baseCfg.h"
#include "commonCfg.h"
#include <sidmiscutil.h>
#include <getopt.h>

#ifdef SIDTARGET_MEP
#include "mepCfg.h"
#endif /* SIDTARGET_MEP */

#if defined (SIDTARGET_SH) || defined (SIDTARGET_SH64)
#include "shCfg.h"
#endif /* SIDTARGET_SH */

#include <string>

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

#ifdef SIDTARGET_MEP
/* begin-mepcfgtool-factories */
static BoardCfg *
mk_simple (const string name, SessionCfg *sess)
{
  MepBoardCfg *b = new MepBoardCfg (name, "simple", sess);

  b->set_core_type (MEP_CORE_C2);
  b->set_cpu ("mep-ext1");
  b->add_irq_board ();
  b->set_core_id (1);
  b->set_intc_channel_bitw (8);
  b->set_intc_level (15);
  b->set_opt_biu (64);
  b->set_endian ("big");
  b->set_opt_abs (false);
  b->set_opt_ave (false);
  b->set_opt_bit (false);
  b->set_opt_clp (false);
  b->set_opt_div (false);
  b->set_opt_ldz (false);
  b->set_opt_min (false);
  b->set_opt_mul (false);
  b->set_opt_sat (false);
  b->set_opt_dsu (false);
  b->set_opt_uci (false);
  return b;
}

static BoardCfg *
mk_fmax (const string name, SessionCfg *sess)
{
  MepBoardCfg *b = new MepBoardCfg (name, "fmax", sess);

  b->set_core_type (MEP_CORE_C2);
  b->set_cpu ("mep-ext2");
  b->add_irq_board ();
  b->set_core_id (2);
  b->set_intc_channel_bitw (8);
  b->set_intc_level (15);
  b->add_cop ("fmax_cop", 0);
  b->set_cop_data_bus_width (32);
  b->set_cop_ccr ( 0, 0x00000101);
  b->set_cop_ccr ( 1, 0x00000000);
  b->set_cop_ccr (15, 0x00000000);
  b->set_opt_biu (64);
  b->set_endian ("big");
  b->set_opt_abs (true);
  b->set_opt_ave (true);
  b->set_opt_bit (true);
  b->set_opt_clp (true);
  b->set_opt_div (true);
  b->set_opt_ldz (true);
  b->set_opt_min (true);
  b->set_opt_mul (true);
  b->set_opt_sat (true);
  b->set_opt_dsu (false);
  b->set_opt_uci (false);
  return b;
}
/* end-mepcfgtool-factories */

#endif /* SIDTARGET_MEP */

static boardspec boards [] = {
  {"basic", "basic cpu + memory board", & mk_basic},
#ifdef SIDTARGET_MEP
/* begin-mepcfgtool-boards */
  { "simple", "MeP custom board 'simple'", & mk_simple },
  { "fmax", "MeP custom board 'fmax'", & mk_fmax },
/* end-mepcfgtool-boards */
#endif /* SIDTARGET_MEP */
#if defined (SIDTARGET_SH) || defined (SIDTARGET_SH64)
  { "sh", "sh default board", & mk_sh },
  { "sh2", "sh2 board", & mk_sh2 },
  { "sh2e", "sh2e board", & mk_sh2e },
  { "sh2a", "sh2a default board", & mk_sh2a },
  { "sh2a-nofpu", "sh2a board with no fpu", & mk_sh2a_nofpu },
  { "sh2a-single-only", "sh2a board with single precision fpu", & mk_sh2a_fpu_single },
  { "sh2a-single", "sh2a board with fpu: default precision is single", & mk_sh2a_fpu },
  { "sh2a-fpu", "sh2a board with fpu", & mk_sh2a_fpu }, // same as sh2a-single
  { "sh3", "sh3 board", & mk_sh3 },
  { "sh3e", "sh3e board", & mk_sh3e },
  { "sh4", "sh4 board with fpu", & mk_sh4 },
  { "sh4-nofpu", "sh4 board with no fpu", & mk_sh4_nofpu },
  { "sh4-single-only", "sh4 board with single precision fpu", & mk_sh4_single },
  { "sh4-single", "sh4 board with fpu: default precision is single", & mk_sh4 },
  { "sh4a", "sh4a board with fpu", & mk_sh4a },
  { "sh4a-nofpu", "sh4a board with no fpu", & mk_sh4a_nofpu },
  { "sh4a-single-only", "sh4a board with single precision fpu", & mk_sh4a_single },
  { "sh4a-single", "sh4a board with fpu: default precision is single", & mk_sh4a },
  { "sh4al", "sh4al board", & mk_sh4al },
#if defined (SIDTARGET_SH64)
  { "sh5", "sh5 default board", & mk_sh5_64media },
  { "sh5-compact", "sh5 compact board", & mk_sh5_compact },
  { "sh5-32media", "sh5 32 bit media board", & mk_sh5_32media },
  { "sh5-64media", "sh5 64 bit media board", & mk_sh5_64media },
#endif
#endif
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
  cout << "--profile-config=NAME,OPTIONS" << endl;
  cout << "                      Specify options for a named profiling configuration" << endl;
  cout << "--rc                  Pass stop code as simulator exit rc" << endl;
  cout << "--reversible          Configure for reversible simulation" << endl;
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
  cout << "--profile-func=FUNCTIONS:NAME" << endl;
  cout << "                      Specify functions which use a given profiling configuration" << endl;
  cout << "--ulog-level=LEVEL    Set the logging level for the current board" << endl;
  cout << "--ulog-mode=less|match|equal" << endl
       << "                      Set the logging mode for the current board" << endl;
  cout << "--ulog-file=-|FILE    Set the log file name" << endl;
  cout << "--warmup              Start the simulation in 'warm-up' mode" << endl;
  cout << "--warmup-func=FUNCTIONS" << endl;
  cout << "                      Specify functions to be simulated in 'warm-up' mode" << endl;
  cout << "--warn-write-to-code  Generate a warning when memory containing executable code is written to" << endl;
  cout << "--no-warn-write-to-code  Do not generate a warning when memory containing executable code is written to" << endl;
  cout << "--warn-write-to-rom   Generate a warning when read only memory is written to" << endl;
  cout << "--allow-write-to-rom  Allow read only memory to be written to" << endl;
  // MeP specific options
  cout << "--model-busses        Turn on bus arbitration modelling" << endl;
  cout << "--dsp-user-out        Display user written DSP trace output for --trace-disassemble" << endl;
  cout << "--no-dsp-user-out     Display normal insn disassembly of DSP insns for --trace-disassemble" << endl;
  cout << "--local-mem=START,SIZE,NAME[,api]" << endl;
  cout << "--global-mem=START,SIZE[,cached][,rom]" << endl;
  cout << "--shadow-mem=START,SIZE,BASE[,cached][,MODULE_NAME]" << endl;
  cout << "--biu-width=N" << endl;
  cout << "--dmac-channel-bitw=N" << endl;
  cout << "--dmac-rectangle" << endl;
  cout << "--dmac-no-rectangle" << endl;
  cout << "--insn=abs|ave|bit|clp|div|ldz|min|mul|sat" << endl;
  cout << "--no-insn=abs|ave|bit|clp|div|ldz|min|mul|sat" << endl;
  cout << "--imem-size=N" << endl;
  cout << "--dmem-size=N" << endl;
  cout << "--dmem-bank-num=N" << endl;
  cout << "--dmem-fixed-start-address" << endl;
  cout << "--dmem-no-fixed-start-address" << endl;
  cout << "--icache-size=N" << endl;
  cout << "--icache-line-size=N" << endl;
  cout << "--icache-way=N" << endl;
  cout << "--icache-cwf=on|off" << endl;
  cout << "--dcache-size=N" << endl;
  cout << "--dcache-line-size=N" << endl;
  cout << "--dcache-way=N" << endl;
  cout << "--dcache-cwf=on|off" << endl;
  cout << "--corrupt-caches" << endl;
  cout << "--intc-channel-bitw=N" << endl;
  cout << "--intc-level=N" << endl;
  cout << "--timer-channel-bitw=N" << endl;
  // End MeP specific options
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

  sess->add_memory (mem);
}


void try_add_gprof(const string optstring, BoardCfg *board)
{
  gprof_type type;
  string interval_string;
  int interval = 1;
  vector<string> toks = sidutil::tokenize (optstring, ",");

  type = instruction_count;	// default type value
  if (toks.size() > 1)		// if we have a type argument
    {
      if (toks[1].empty ())
	{
          cerr << "error: unknown sub-option to --gprof: " << optstring << endl;
          exit (21);      
	}
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
	    warmup (false),
	    profile_func (""),
	    warmup_func (""),
	    start_config (""),
	    warn_write_to_code (true),
	    warn_write_to_rom (false),
	    allow_write_to_rom (false),
	    // MeP specific options
	    model_busses (false),
	    dsp_user_out (false),
	    corrupt_caches (false),
	    // End MeP specific options
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
  bool warmup;
  string profile_func;
  string warmup_func;
  string start_config;
  string step_insn_count;
  bool warn_write_to_code;
  bool warn_write_to_rom;
  bool allow_write_to_rom;
  // MeP specific options
  bool model_busses;
  bool dsp_user_out;
  bool corrupt_caches;
  // End MeP specific options
};
  
struct BoardConfig
{
  BoardCfg *board;
  string config;
};

static void need_sess (SessionCfg *&sess, bool verbose)
{
  if (! sess)
    {
      sess = new SessionCfg ("");
      sess->profile_config ("sid-internal-warmup:");
      sess->verbose = verbose;
    }
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
  vector<BoardConfig> board_configs;
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
		    opt_persistent, opt_profile_config,
		    opt_rc, opt_reversible, opt_no_run, opt_sidrtc, opt_sidcodec, 
		    opt_tksm, opt_board, opt_cpu, opt_gdb, opt_gloss, opt_engine, 
		    opt_insn_count, opt_load, opt_icache, opt_dcache, 
		    opt_memory_region, opt_profile_func,
		    opt_trace_extract, opt_trace_semantics,
		    opt_trace_disassemble, opt_trace_counter, opt_trace_core,
		    opt_final_insn_count, opt_eb, opt_el, opt_gprof,
		    opt_ulog_level, opt_ulog_mode, opt_ulog_file,
		    opt_warmup, opt_warmup_func,
		    opt_warn_write_to_code, no_opt_warn_write_to_code,
  		    opt_warn_write_to_rom, opt_allow_write_to_rom,
		    // MeP specific options
		    opt_model_busses,
		    opt_dsp_user_out, opt_no_dsp_user_out,
		    opt_local_mem, opt_global_mem, opt_shadow_mem,
		    opt_biu_width, opt_insn, opt_no_insn,
		    opt_imem_size, opt_dmem_size, opt_dmem_bank_num,
		    opt_dmem_fixed_start_address, opt_dmem_no_fixed_start_address,
		    opt_icache_size, opt_icache_line_size, opt_icache_way, opt_icache_cwf,
		    opt_dcache_size, opt_dcache_line_size, opt_dcache_way, opt_dcache_cwf,
		    opt_dmac_channel_bitw, opt_dmac_rectangle, opt_dmac_no_rectangle,
		    opt_corrupt_caches,
		    opt_intc_channel_bitw, opt_intc_level,
		    opt_timer_channel_bitw
		    // End MeP specific options
  };
		    
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
    {"profile-config",  required_argument, &curr_opt, opt_profile_config },
    {"rc",              no_argument, & curr_opt, opt_rc },
    {"reversible",      no_argument, & curr_opt, opt_reversible },
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
    {"profile-func",      required_argument, &curr_opt, opt_profile_func },
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
    {"warmup",            no_argument, &curr_opt, opt_warmup },
    {"warmup-func",       required_argument, &curr_opt, opt_warmup_func },
    {"warn-write-to-code",no_argument, & curr_opt, opt_warn_write_to_code },
    {"no-warn-write-to-code",no_argument, & curr_opt, no_opt_warn_write_to_code },
    {"warn-write-to-rom",no_argument, & curr_opt, opt_warn_write_to_rom },
    {"allow-write-to-rom",no_argument, & curr_opt, opt_allow_write_to_rom },
    // MeP specific options
    {"model-busses",no_argument, & curr_opt, opt_model_busses },
    {"dsp-user-out",no_argument, & curr_opt, opt_dsp_user_out },
    {"no-dsp-user-out",no_argument, & curr_opt, opt_no_dsp_user_out },
    {"local-mem",required_argument, & curr_opt, opt_local_mem },
    {"global-mem",required_argument, & curr_opt, opt_global_mem },
    {"shadow-mem",required_argument, & curr_opt, opt_shadow_mem },
    {"dmac-channel-bitw",required_argument, & curr_opt, opt_dmac_channel_bitw },
    {"biu-width",required_argument, & curr_opt, opt_biu_width },
    {"dmac-rectangle",no_argument, & curr_opt, opt_dmac_rectangle },
    {"dmac-no-rectangle",no_argument, & curr_opt, opt_dmac_no_rectangle },
    {"insn",required_argument, & curr_opt, opt_insn },
    {"no-insn",required_argument, & curr_opt, opt_no_insn },
    {"imem-size",required_argument, & curr_opt, opt_imem_size },
    {"dmem-size",required_argument, & curr_opt, opt_dmem_size },
    {"dmem-bank-num",required_argument, & curr_opt, opt_dmem_bank_num },
    {"dmem-fixed-start-address",no_argument, & curr_opt, opt_dmem_fixed_start_address },
    {"dmem-no-fixed-start-address",no_argument, & curr_opt, opt_dmem_no_fixed_start_address },
    {"icache-size",required_argument, & curr_opt, opt_icache_size },
    {"icache-line-size",required_argument, & curr_opt, opt_icache_line_size },
    {"icache-way",required_argument, & curr_opt, opt_icache_way },
    {"icache-cwf",required_argument, & curr_opt, opt_icache_cwf },
    {"dcache-size",required_argument, & curr_opt, opt_dcache_size },
    {"dcache-line-size",required_argument, & curr_opt, opt_dcache_line_size },
    {"dcache-way",required_argument, & curr_opt, opt_dcache_way },
    {"dcache-cwf",required_argument, & curr_opt, opt_dcache_cwf },
    {"corrupt-caches",no_argument, & curr_opt, opt_corrupt_caches },
    {"intc-channel-bitw",required_argument, & curr_opt, opt_intc_channel_bitw },
    {"intc-level",required_argument, & curr_opt, opt_intc_level },
    {"timer-channel-bitw",required_argument, & curr_opt, opt_timer_channel_bitw },
    // End MeP specific options
    { 0, 0, NULL, 0 }
 };

  string board_start_config = "";
  string wrap_config = "";
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
		need_sess (sess, verbose_p);
		if (curr_board)
		  {
		    sess->add_board (curr_board);
		    if (! defaults.warmup)
		      {
			BoardConfig bc = { curr_board, defaults.start_config + board_start_config };
			board_configs.push_back (bc);
		      }
		    board_start_config = "";
		  }
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
			curr_board->set_warmup (defaults.warmup);
			curr_board->add_warmup_func (defaults.warmup_func);
			curr_board->add_profile_func (defaults.profile_func);
			if (defaults.step_insn_count != "10000")
			  curr_board->set_step_insn_count(defaults.step_insn_count);
			if (defaults.warn_write_to_code)
			  curr_board->set_warn_write_to_code(true);
			else
			  curr_board->set_warn_write_to_code(false);
			if (defaults.warn_write_to_rom)
			  curr_board->set_warn_write_to_rom(true);
			if (defaults.allow_write_to_rom)
			  curr_board->set_allow_write_to_rom(true);
			// MeP specific options
			curr_board->set_config_index (i - boards);
			if (defaults.model_busses)
			  curr_board->set_model_busses(true);
			if (defaults.dsp_user_out)
			  curr_board->set_dsp_user_out(true);
			if (defaults.corrupt_caches)
			  curr_board->set_corrupt_caches(true);
			// End MeP specific options
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
	      defaults.start_config += " --verbose";
	      break;
	     
	    case opt_gprof:
	      option_requires_board (curr_board, "gprof");
	      try_add_gprof(optstring(), curr_board);
	      board_start_config += " --gprof=" + optstring();
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
	      need_sess (sess, verbose_p);
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
		{
		  board_start_config += " --trace-extract";
		  curr_board->trace_extract();
		}
	      else
		{
		  defaults.trace_extract = true;
		  defaults.start_config += " --trace-extract";
		}
	      break;

	    case opt_trace_semantics:
	      if (curr_board)
		{
		  board_start_config += " --trace-semantics";
		  curr_board->trace_semantics();
		}
	      else
		{
		  defaults.trace_semantics = true;
		  defaults.start_config += " --trace-semantics";
		}
	      break;

	    case opt_trace_disassemble:
	      if (curr_board)
		{
		  curr_board->trace_disassemble();
		  board_start_config += " --trace-disassemble";
		}
	      else
		{
		  defaults.trace_disassemble = true;
		  defaults.start_config += " --trace-disassemble";
		}
	      break;

	    case opt_trace_counter:
	      if (curr_board)
		{
		  curr_board->trace_counter();
		  board_start_config += " --trace-counter";
		}
	      else
		{
		  defaults.trace_counter = true;
		  defaults.start_config += " --trace-counter";
		}
	      break;

	    case opt_final_insn_count:
	      if (curr_board)
		{
		  curr_board->final_insn_count();
		  board_start_config += " --final-insn-count";
		}
	      else
		{
		  defaults.final_insn_count = true;
		  defaults.start_config += " --final-insn-count";
		}
	      break;

	    case opt_trace_core:
	      if (curr_board)
		{
		  curr_board->trace_core();
		  board_start_config += " --trace-core";
		}
	      else
		{
		  defaults.trace_core = true;
		  defaults.start_config += " --trace-core";
		}
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
		AtomicCfg *comp = AtomicCfg::wrap_component (c);
		if (! comp)
		  {
		    cerr << "error: no component named '" << c << "' to wrap" << endl;
		    exit (9);
		  }
		sess->add_wrapped_component (comp);
	      }
	      break;

	      
	    case opt_insn_count:
	      if (curr_board)
		{
		  curr_board->set_step_insn_count(optstring());
		  board_start_config += " --insn-count=" + optstring();
		}
	      else
		{
		  defaults.step_insn_count = optstring();
		  defaults.start_config += " --insn-count=" + optstring();
		}
	      break;

	    case opt_persistent:
	      persistent_p = true;
	      break;

	    case opt_rc:
	      rc_p = true;
	      break;

	    case opt_reversible:
	      if (sess)
		{
		  sess->set_reversible ();
		  // --insn-count must be 1 for this to work correctly
		  if (curr_board)
		    {
		      curr_board->set_step_insn_count("1");
		      board_start_config += " --insn-count=1";
		    }
		  else
		    {
		      defaults.step_insn_count = "1";
		      defaults.start_config += " --insn-count=1";
		    }
		}
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
	      need_sess (sess, verbose_p);
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
		{
		  curr_board->set_ulog_level (optaddr ("ulog-level"));
		  board_start_config += " --ulog-level=" + optstring();
		}
	      else
		{
		  defaults.ulog_level = optaddr ("ulog-level");
		  defaults.start_config += " --ulog-level=" + optstring();
		  need_sess (sess, verbose_p);
		  sess->set_ulog_level (optaddr ("ulog-level"));
		}
	      break;

	    case opt_ulog_mode:
	      if (curr_board)
		{
		  curr_board->set_ulog_mode (optstring ());
		  board_start_config += " --ulog-mode=" + optstring();
		}
	      else
		{
		  defaults.ulog_mode = optstring ();
		  defaults.start_config += " --ulog-mode=" + optstring();
		  need_sess (sess, verbose_p);
		  sess->set_ulog_mode (optstring ());
		}
	      break;

	    case opt_ulog_file:
	      need_sess (sess, verbose_p);
	      sess->add_ulog_file (optstring ());
	      if (curr_board)
		curr_board->set_ulog_file (optstring ());
	      else
		{
		  defaults.ulog_file = optstring ();
		  sess->set_ulog_file (optstring ());
		}
	      break;

	    case opt_warmup:
	      if (curr_board)
		curr_board->set_warmup (true);
	      else
		defaults.warmup = true;
	      break;

	    case opt_warmup_func:
	      if (curr_board)
		curr_board->add_warmup_func (optstring ());
	      else
		{
		  if (! defaults.warmup_func.empty ())
		    defaults.warmup_func += ",";
		  defaults.warmup_func += optstring ();
		}
	      break;

	    case opt_profile_func:
	      if (curr_board)
		curr_board->add_profile_func (optstring ());
	      else
		{
		  if (! defaults.profile_func.empty ())
		    defaults.profile_func += "|";
		  defaults.profile_func += optstring ();
		}
	      break;

	    case opt_profile_config:
	      need_sess (sess, verbose_p);
	      sess->profile_config (optstring ());
	      break;

	    case opt_warn_write_to_code:
	      if (curr_board)
		curr_board->set_warn_write_to_code (true);
	      else
		defaults.warn_write_to_code = true;
	      break;

	    case no_opt_warn_write_to_code:
	      if (curr_board)
		curr_board->set_warn_write_to_code (false);
	      else
		defaults.warn_write_to_code = false;
	      break;

	    case opt_warn_write_to_rom:
	      if (curr_board)
		curr_board->set_warn_write_to_rom (true);
	      else
		defaults.warn_write_to_rom = true;
	      break;

	    case opt_allow_write_to_rom:
	      if (curr_board)
		curr_board->set_allow_write_to_rom (true);
	      else
		defaults.allow_write_to_rom = true;
	      break;

	    // MeP specific options.
	    case opt_model_busses:
	      if (curr_board)
		{
		  curr_board->set_model_busses (true);
		  board_start_config += " --model-busses";
		}
	      else
		{
		  defaults.model_busses = true;
		  defaults.start_config += " --model-busses";
		}
	      break;

	    case opt_dsp_user_out:
	      if (curr_board)
		curr_board->set_dsp_user_out (true);
	      else
		defaults.dsp_user_out = true;
	      break;

	    case opt_no_dsp_user_out:
	      if (curr_board)
		curr_board->set_dsp_user_out (false);
	      else
		defaults.dsp_user_out = false;
	      break;

	    case opt_local_mem:
	      if (curr_board)
		curr_board->set_opt_local_mem (optstring ());
	      break;
	      
	    case opt_global_mem:
	      if (curr_board)
		curr_board->set_opt_global_mem (optstring ());
	      break;
	      
	    case opt_shadow_mem:
	      if (curr_board)
		curr_board->set_opt_shadow_mem (optstring ());
	      break;
	      
	    case opt_dmac_channel_bitw:
	      if (curr_board)
		curr_board->set_opt_dmac_channel_bitw (optstring ());
	      break;

	    case opt_biu_width:
	      if (curr_board)
		curr_board->set_opt_biu_width (optstring ());
	      break;
	      
	    case opt_dmac_rectangle:
	      if (curr_board)
		curr_board->set_opt_dmac_rectangle (true);
	      break;
	      
	    case opt_dmac_no_rectangle:
	      if (curr_board)
		curr_board->set_opt_dmac_rectangle (false);
	      break;
	      
	    case opt_insn:
	      if (curr_board)
		curr_board->set_opt_insn (optstring ());
	      break;
	      
	    case opt_no_insn:
	      if (curr_board)
		curr_board->set_opt_no_insn (optstring ());
	      break;
	      
	    case opt_imem_size:
	      if (curr_board)
		curr_board->set_opt_imem_size (optstring ());
	      break;
	      
	    case opt_dmem_size:
	      if (curr_board)
		curr_board->set_opt_dmem_size (optstring ());
	      break;
	      
	    case opt_dmem_bank_num:
	      if (curr_board)
		curr_board->set_opt_dmem_bank_num (optstring ());
	      break;
	      
	    case opt_dmem_fixed_start_address:
	      if (curr_board)
		curr_board->set_opt_dmem_fixed_start_address (true);
	      break;
	      
	    case opt_dmem_no_fixed_start_address:
	      if (curr_board)
		curr_board->set_opt_dmem_fixed_start_address (false);
	      break;
	      
	    case opt_icache_size:
	      if (curr_board)
		curr_board->set_opt_icache_size (optstring ());
	      break;
	      
	    case opt_icache_line_size:
	      if (curr_board)
		curr_board->set_opt_icache_line_size (optstring ());
	      break;
	      
	    case opt_icache_way:
	      if (curr_board)
		curr_board->set_opt_icache_way (optstring ());
	      break;
	      
	    case opt_icache_cwf:
	      {
		string cwf = optstring();
		if (cwf == "on" || cwf == "off")
		  {
		    if (curr_board)
		      curr_board->set_opt_icache_cwf (cwf);
		  }
		else
		  {
		    cerr << "error: --icache-cwf must be either on or off" << endl;
		    exit (8);
		  }
	      }
	      break;

	    case opt_dcache_size:
	      if (curr_board)
		curr_board->set_opt_dcache_size (optstring ());
	      break;
	      
	    case opt_dcache_line_size:
	      if (curr_board)
		curr_board->set_opt_dcache_line_size (optstring ());
	      break;
	      
	    case opt_dcache_way:
	      if (curr_board)
		curr_board->set_opt_dcache_way (optstring ());
	      break;
	      
	    case opt_dcache_cwf:
	      {
		string cwf = optstring();
		if (cwf == "on" || cwf == "off")
		  {
		    if (curr_board)
		      curr_board->set_opt_dcache_cwf (cwf);
		  }
		else
		  {
		    cerr << "error: --dcache-cwf must be either on or off" << endl;
		    exit (8);
		  }
	      }
	      break;

	    case opt_corrupt_caches:
	      if (curr_board)
		curr_board->set_corrupt_caches (true);
	      else
		defaults.corrupt_caches = true;
	      break;

	    case opt_intc_channel_bitw:
	      if (curr_board)
		curr_board->set_opt_intc_channel_bitw (optstring ());
	      break;
	      
	    case opt_intc_level:
	      if (curr_board)
		curr_board->set_opt_intc_level (optstring ());
	      break;

	    case opt_timer_channel_bitw:
	      if (curr_board)
		curr_board->set_opt_timer_channel_bitw (optstring ());
	      break;
	    // End MeP specific options.
	    }
	  break;


	case '?':
	default:
	  usage ();
	  return 1;
	}
    }

  if (sess && curr_board)
    {
      sess->add_board (curr_board);
      if (! defaults.warmup)
	{
	  BoardConfig bc = { curr_board, defaults.start_config + board_start_config };
	  board_configs.push_back (bc);

	  string wrap_config = sess->wrap_config ();
	  for (vector<BoardConfig>::const_iterator it = board_configs.begin ();
	       it != board_configs.end ();
	       ++it)
	    it->board->set_start_config (it->config + wrap_config);
	}
    }

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

