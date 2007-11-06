// mepCfg.cxx - configuration for MeP.  -*- C++ -*-

// Copyright (C) 2002-2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.


#include "mepCfg.h"
#include "sidmiscutil.h"
#include <vector>

using sidutil::parse_attribute;
using sid::host_int_4;
using sid::component;

class MepGlobalMapperCfg : 
  virtual public MapperCfg
{
  // This is a special version of a MapperCfg which supports mapping a
  // memory block as read-write during startup, and then switching to
  // read-only once an image is loaded.

public:
  MepGlobalMapperCfg (const string name, bool transparent = false) :
    MapperCfg (name, transparent),
    ComponentCfg (name),
    AtomicCfg (name, 
	       "libmapper.la", 
	       "mapper_component_library", 
	       string("hw-mapper-") + (transparent ? "transparent" : "basic"))
  {}

  // bank 0 is the initial state, bank 1 is the "after loading" state.
  void map_ro_mem (const Mapping &m)
  {
    Mapping m1(m);
    MapperCfg::map (m1.banks("{0}").bus("read-write-port"));    
    MapperCfg::map (m1.banks("{1}").bus("read-only-port"));
  }

  // to support the illusion, we need to add command-line --memory-regions
  // to both banks, so we override the normal MapperCfg::map method.
  virtual void map (const Mapping &m)
  {
    Mapping m1(m);
    MapperCfg::map (m1.banks("{0,1}"));
  }
};


class MepMM_INTCfg :
  virtual public AtomicCfg
{
public:
  MepMM_INTCfg (sid::big_int_4 mapped_addr, unsigned reg_num, unsigned ccount) :
    ComponentCfg ("mm_int"),
    AtomicCfg ("mm_int", "libmepfamily.la", 
	       "mepfamily_component_library", 
	       "hw-mm_int-mep"),
    address (mapped_addr),
    // ignore reg_num for now. Allow for 0x100 bytes of register space per cpu.
    range (0x100 * ccount)
  {
  }

  sid::big_int_4 get_mapped_addr () const { return address; }

  // Range is 4 bytes per register per cpu
  unsigned get_range () const { return range; }

private:
  sid::big_int_4 address;
  unsigned range;
};


class MepMemRegionCfg :
  virtual public MemCfg
{
public:
  MepMemRegionCfg (const string name, sid::host_int_4 start, sid::host_int_4 size,
		   bool cached = false, bool readonly = false) :
    MemCfg (name, size),
    ComponentCfg (name),
    AtomicCfg (name,
             "libmemory.la",
             "mem_component_library",
             "hw-memory-ram/rom-basic"),
    my_start (start),
    my_cached (cached),
    my_toshapi (false),
    my_valid (true)
  {
    set (this, "base-address", "0x" + sidutil::make_numeric_attribute (start, std::ios::hex));
  }
  MepMemRegionCfg (const string name, sid::host_int_4 start, sid::host_int_4 size,
		   sid::host_int_4 read_latency, sid::host_int_4 write_latency,
		   bool cached = false, bool readonly = false) :
    MemCfg (name, size, read_latency, write_latency),
    ComponentCfg (name),
    AtomicCfg (name,
             "libmemory.la",
             "mem_component_library",
             "hw-memory-ram/rom-basic"),
    my_start (start),
    my_cached (cached),
    my_readonly (readonly),
    my_valid (true)
  {
    set (this, "base-address", "0x" + sidutil::make_numeric_attribute (start, std::ios::hex));
  }

  void set_start (sid::host_int_4 start) { my_start = start; }
  sid::host_int_4 start () const { return my_start; }

  void set_toshapi (bool toshapi = true) { my_toshapi = toshapi; }
  sid::host_int_4 is_toshapi () const { return my_toshapi; }

  void set_cached (bool cached = true) { my_cached = cached; }
  bool cached () const { return my_cached; }

  void set_readonly (bool readonly = true) { my_readonly = readonly; }
  bool readonly () const { return my_readonly; }

  bool valid () const { return my_valid; }
  void invalidate () { my_valid = false; }
  void validate () { my_valid = true; }

protected:
  sid::host_int_4 my_start;
  bool my_cached;
  bool my_readonly;
  bool my_toshapi;
  bool my_valid;
};

class MepShadowRegion
{
public:
  MepShadowRegion (sid::host_int_4 start, sid::host_int_4 size, sid::host_int_4 base,
		   bool cached = false, const char *mod_name = NULL) :
    my_start (start),
    my_size (size),
    my_base (base),
    my_cached (cached)
  {
    if (mod_name == NULL)
      my_mod_name = mod_name;
    else
      my_mod_name = strdup (mod_name);
  }

  bool is_local () const { return my_mod_name != NULL; }
  bool is_global () const { return ! is_local (); }
  bool is_cached () const { return my_cached; }

  sid::host_int_4 start () const { return my_start; }
  sid::host_int_4 size () const { return my_size; }
  sid::host_int_4 base () const {return my_base; }
  const char *mod_name () const { return my_mod_name; }

private:
  sid::host_int_4 my_start;
  sid::host_int_4 my_size;
  sid::host_int_4 my_base;
  const char *my_mod_name;
  bool my_cached;
};


class MepBusArbitratorCfg :
  virtual public AtomicCfg
{
public:
  MepBusArbitratorCfg (const string name, const string type) :
    ComponentCfg (name),
    AtomicCfg (name, "libmepfamily.la",
	       "mepfamily_component_library", 
	       type)
  {
  }
  void change_type (const string type) { my_comptype = type; }
};

class MepMemCfg :
  virtual public AggregateCfg
{
public:
    
  MepMemCfg (SessionCfg *s, MepBoardCfg *board) :
    ComponentCfg (""),
    AggregateCfg (""),
    global_mapper (new MepGlobalMapperCfg ("global")),
    sess (s),
    gbmif (0),
    gbmif_type ("hw-gbmif-mep"),
    insn_count_1 (false),
    model_busses (false)
  {

    // this is an object encapsulating the mep global memory config; it is
    // constructed _once_ and is a child of the session, not any particular
    // board. However, it contains both the global memory logic and the
    // logic needed to wire up any particular board's local & global memory
    // map. the memory system is a little complex, so here's a diagram.
    //
    //     +------------------------------------------------+
    //     |  +----------------------------+                |
    //     |  | main mapper (transparent)  |                |
    //     |  +----------------------------+                |
    //     |            |             |                     |
    //     |            |      +-----------------+          |
    //     |    media   |      | local mapper    |          |
    //     |   module   |      +-----------------+          |
    //     |            |          | | | |     | |          |
    //     |            |       +---------+   +---------+   |
    //     |            |       |  imem/  |+  |  local  |+  |
    //     |            |       |  dmem   ||  |  mems   ||  |
    //     |            |       +---------+|  +---------+|  |
    //     |            |        +---------+   +---------+  |
    //     +------------|-----------------------------------+
    //                  |
    //     +------------|------------------------+
    //     |            |                        | global memory
    //     | +-------------------------------+   | 
    //     | |         global mapper         |   | (shared among
    //     | +-------------------------------+   |  all media modules)
    //     |     |            |           |      |
    //     | +-------+    +-------+   +--------+ |
    //     | |global |    |global |   |global  | |
    //     | |memory |    |memory |   |memory  | |
    //     | |#1     |    |#2     |   |#3      | |
    //     | +-------+    +-------+   +--------+ |
    //     +-------------------------------------+
    //
    //
    // There are two local memory spaces, both accessed via the local data
    // bus.  Each media module has a main mapper which maps requests either
    // the local memory bus or to the global memory space.
    //
    // The board's main mapper is transparent, just splitting memory
    // references betwen the local and global spaces. The one exception is the
    // mapping onto the local mapper, which is 0-based since other components
    // like the dmac and hw_engines believe that local memory starts at 0.
    //
    // Shadows are implemented in the global map as loopback mappings. Global
    // shadows loop back to the global mapper. Local shadows loop back to the
    // local mapper.
    //

    assert (sess);
    assert (board);
    sess->add_child (this);

    // Bank 0 of the global mapper allows writing to read-only memory.
    // Bank 1 does not.
    assert (global_mapper);
    conn_pin (sess->sim_sched, "active", global_mapper, "bank");

    add_child (global_mapper);

    // use the mepcfgtool-edited custom memory regions
    // begin-global-memory-regions
    mems.push_back (new MepMemRegionCfg ("shared-mem0", 0x0, 0x200000, 10, 1, false, true));
    mems.push_back (new MepMemRegionCfg ("shared-mem1", 0x800000, 0x800000, 10, 1, true, false));
    mems.push_back (new MepMemRegionCfg ("shared-mem2", 0x80800000, 0x800000, 10, 1, false, false));
    // end-global-memory-regions

    // begin-shadow-regions
    // end-shadow-regions

    // begin-peripherals
    // end-peripherals

    for (vector <MepMemRegionCfg *>::const_iterator i = mems.begin ();
	 i != mems.end (); ++i)
      {
	assert (*i);
	add_child (*i);
      }
  }

  void map_global_memory ()
  {
    // Map global memory
    Mapping m = Mapping().bus("read-write-port");
    for (vector <MepMemRegionCfg *>::const_iterator i = mems.begin ();
	 i != mems.end (); ++i)
      {
	if (! (*i)->valid ())
	  continue;
	sid::host_int_4 start = (*i)->start ();
	sid::host_int_4 end = start + (*i)->size () - 1;
	if ((*i)->readonly ())
	  global_mapper->map_ro_mem (m.low(start).high(end).slave(*i));
	else
	  global_mapper->map (m.low(start).high(end).slave(*i));

	// Read latency of memory is 1 cycle, if we are modelling the busses.
	if (gbmif)
	  (*i)->set_read_latency (1);
      }

    // Map global shadow regions
    m.slave(global_mapper).bus("access-port");	
    for (vector <MepShadowRegion *>::const_iterator s = shadows.begin ();
	 s != shadows.end (); ++s)
      {
	if (! (*s)->is_global ())
	  continue;
	sid::host_int_4 s_start = (*s)->start ();
	sid::host_int_4 s_size  = (*s)->size ();
	sid::host_int_4 s_base  = (*s)->base ();
	sid::host_int_4 s_base_end = s_base + s_size - 1;
	// Only map the portions of the shadow which entirely
	// cover a real global region.
	for (vector <MepMemRegionCfg *>::const_iterator r = mems.begin ();
	     r != mems.end (); ++r)
	  {
	    if (! (*r)->valid ())
	      continue;
	    sid::host_int_4 r_start = (*r)->start ();
	    sid::host_int_4 r_size = (*r)->size ();
	    sid::host_int_4 r_end = r_start + r_size - 1;
	    if (r_start >= s_base && r_end <= s_base_end)
	      {
		sid::host_int_4 offset = r_start - s_base;
		sid::host_int_4 start = s_start + offset;
		sid::host_int_4 end = start + r_size - 1;
		global_mapper->map (m.low(start).high(end).base(r_start));
	      }
	  }
      }

    // Set the number of ports in the gbmif
    if (gbmif)
      set (gbmif, "ports", sidutil::make_attribute(MepBoardCfg::curr_core_id));
  }

  void map_boards ()
  {
    // Map the imem and dmem. This must be done for all boards before
    // setup_memory_map is done for any board (below).
    for (vector <MepBoardCfg *>::const_iterator i = boards.begin ();
	 i != boards.end (); ++i)
      (*i)->map_imem_dmem ();

    for (vector <MepBoardCfg *>::const_iterator i = boards.begin ();
	 i != boards.end (); ++i)
      {
	setup_memory_map (*i);
	if (gbmif && (*i)->gbif)
	  {
	    // The downstream-lock pin of the gbmif must connected to the
	    // global-bus-slave-lock pin of the gbif of each of the boards.
	    (gbmif)->conn_pin (gbmif, "global-bus-lock",
			       (*i)->gbif, "global-bus-slave-lock");
	  }
      }
  }
    
  void setup_memory_map (MepBoardCfg *board)
  {
    assert (board);
    assert (board->main_mapper);

    // Map global memory from the main mapper to the global mapper or to the
    // GBIF.
    AtomicCfg *probe = board->get_local_shadow_bit_insn_probe ();
    Mapping m;
    if (board->gbif)
      {
	m.bus("biu-interface").slave(board->gbif);
	if (probe)
	  probe->conn_bus (probe, "downstream", board->gbif, "biu-interface");
      }
    else
      {
	m.bus("access-port").slave(global_mapper);
	if (probe)
	  probe->conn_bus (probe, "downstream", global_mapper, "access-port");
      }

    for (vector <MepMemRegionCfg *>::const_iterator i = mems.begin ();
	 i != mems.end (); ++i)
      {
	if (! (*i)->valid ())
	  continue;
	sid::host_int_4 start = (*i)->start ();
	sid::host_int_4 end   = start + (*i)->size () - 1;
	board->main_mapper->map (m .low(start).high(end));
      }

    // Map all shadows from the main mapper to the global mapper or GBIF. The
    // mapper slave is already set correctly from above.
    Mapping mp;
    if (probe)
      mp.slave(probe).bus("upstream");

    for (vector <MepShadowRegion *>::const_iterator i = shadows.begin ();
	 i != shadows.end (); ++i)
      {
	// Don't map a local shadow for a module onto itself.
	if ((*i)->is_local () && board->get_module_type () == (*i)->mod_name ())
	  continue;
	sid::host_int_4 i_start = (*i)->start ();
	sid::host_int_4 i_size  = (*i)->size ();
	sid::host_int_4 i_end   = i_start + i_size - 1;

	// We need to examine the local memory of the shadowed module if we
	// need to detect access to that board's dmem by bit insns.
	if (probe && (*i)->is_local ())
	  {
	    // Find the board that this shadow maps onto.
	    MepBoardCfg* shadowed_board = 0;
	    for (vector <MepBoardCfg *>::const_iterator b = boards.begin ();
		 b != boards.end (); ++b)
	      {
		if ((*b)->get_module_type () == (*i)->mod_name ())
		  {
		    shadowed_board = *b;
		    break;
		  }
	      }

	    // If the shadowed board is not in the simulation, then no need
	    // to map anything.
	    if (! shadowed_board)
	      continue;
	    
	    // Only map the portions of the shadow which entirely
	    // cover a real local region.  This includes IMEM and DMEM
	    sid::host_int_4 i_base  = (*i)->base ();
	    sid::host_int_4 i_base_end = i_base + i_size - 1;
	    sid::host_int_4 offset;
	    sid::host_int_4 size;
	    bool is_dmem;
	    while (shadowed_board->shadow_covers_local_region (i_base, i_base_end, offset, size, is_dmem))
	      {
		sid::host_int_4 start = i_start + offset;
		sid::host_int_4 end = start + size - 1;

		// Insert the bit insn probe into the mapping if it exists and this is a local
		// shadow to the other module's dmem.
		if (is_dmem)
		  board->main_mapper->map (mp.low(start).high(end));
		else
		  board->main_mapper->map (m.low(start).high(end));

		i_start = end + 1;
		i_base += offset + size;
	      }
	  }
	else
	  board->main_mapper->map (m.low(i_start).high(i_end));
      }

    // Map local shadows from the global mapper to the local mapper or LBIF
    if (board->gbif)
      m.bus("global-bus-slave-interface");
    else
      m.slave(board->local_mapper).bus("access-port");
    for (vector <MepShadowRegion *>::const_iterator s = shadows.begin ();
	 s != shadows.end (); ++s)
      {
	if (! (*s)->is_local ())
	  continue;
	if (board->get_module_type () != (*s)->mod_name ())
	  continue;
	sid::host_int_4 s_start = (*s)->start ();
	sid::host_int_4 s_size  = (*s)->size ();
	sid::host_int_4 s_base  = (*s)->base ();
	sid::host_int_4 s_base_end = s_base + s_size - 1;

	// Only map the portions of the shadow which entirely
	// cover a real local region.  This includes IMEM and DMEM
	sid::host_int_4 offset;
	sid::host_int_4 size;
	bool is_dmem;
	while (board->shadow_covers_local_region (s_base, s_base_end, offset, size, is_dmem))
	  {
	    sid::host_int_4 start = s_start + offset;
	    sid::host_int_4 end = start + size - 1;
	    sid::host_int_4 base = s_base + offset;
	    if (board->lbif)
	      m.base(base);
	    else
	      m.base(base - MepBoardCfg::localmem_base);
	    global_mapper->map (m.low(start).high(end));
	    s_start = end + 1;
	    s_base += offset + size;
	  }
      }

    // begin-local-peripheral-mappings
    // end-local-peripheral-mappings

    // Connect this board's GBIF and LBIF
    if  (board->gbif)
      {
	assert (board->lbif);
	assert (global_mapper);
	board->conn_bus (board->gbif, "local-bus", board->lbif, "gbif-interface");
	board->conn_bus (board->lbif, "local-bus", board->local_mapper, "access-port");
      }
  }

  void set_dynamic_config (AtomicCfg *dynamic_configurator, Writer &w)
  {
    // The global mapper may be wrapped, so it may be reconfigured.
    assert (dynamic_configurator);
    assert (global_mapper);
    if (global_mapper->possibly_wrapped ())
      {
	Relation (dynamic_configurator, "client", global_mapper).write_to (w);
      }
    // The GBMIF uses ulog, so it may be reconfigured.
    if (gbmif)
      {
	Relation (dynamic_configurator, "client", gbmif).write_to (w);
      }
  }

  void set_model_busses (bool b = true);
  bool model_busses_p () const { return model_busses; }
  void set_opt_global_mem (MepMemRegionCfg* mem);
  void add_mm_int (MepMM_INTCfg *mm_int);
  void map_mm_int (MepBoardCfg *board, MepMM_INTCfg *mm_int);
  vector <MepMemRegionCfg *> mems;
  vector <MepShadowRegion *> shadows;
  MepBusArbitratorCfg *gbmif;
  string gbmif_type;

  void add_board (MepBoardCfg *b) { boards.push_back (b); }
  unsigned num_boards () const { return boards.size (); }

  bool insn_count_1_required () const { return insn_count_1; }

protected:
  MepGlobalMapperCfg *global_mapper;
  SessionCfg *sess;
  vector<MepBoardCfg *> boards;
  bool insn_count_1;
  bool model_busses;

  void add_peripheral (const string type, 
		       sid::host_int_4 mapped_addr,
		       sid::host_int_4 mapped_size);
  void add_toshapi_peripheral (const string type, 
			       const string instance,
			       sid::host_int_4 mapped_addr,
			       sid::host_int_4 mapped_size);
  void map_peripheral (MepBoardCfg *board,
		       sid::host_int_4 mapped_addr,
		       sid::host_int_4 mapped_size);

  void add_toshapi_global_bus_model (const string type, const string instance);

  virtual void write_config (Writer &w);
};

void
MepMemCfg::set_opt_global_mem (MepMemRegionCfg* mem)
{
  // If this is the first time called, then invalidate all the
  // memory regions in the mems vector.
  static bool called = false;
  if (! called)
    {
      called = true;
      for (vector <MepMemRegionCfg *>::const_iterator i = mems.begin();
	   i != mems.end (); ++i)
	(*i)->invalidate ();
    }

  // Now see if a memory region with this name already exists. If so,
  // modify it.
  for (vector <MepMemRegionCfg *>::const_iterator i = mems.begin();
       i != mems.end (); ++i)
    {
      if ((*i)->get_name () == mem->get_name ())
	{
	  **i = *mem;
	  return;
	}
    }

  // Not found, so just add the new region to the vector
  add_child (mem);
  mems.push_back (mem);
}

void
MepMemCfg::set_model_busses (bool b)
{
  if (! b || model_busses)
    return; //nothing to do

  model_busses = b;

  // Create a GBMIF component to arbitrate requests to the global bus.
  gbmif = new MepBusArbitratorCfg ("gbmif", gbmif_type);
  set (gbmif, "name", gbmif->get_name ());
  assert (sess);
  sess->init_seq->add_output (2, gbmif, "running");
  conn_pin (sess->sim_sched, "active", gbmif, "active");
  sess->sim_sched->add_subscription (gbmif, "step-event", "step-control");

  // Set up logging
  set (gbmif, "ulog-level", sidutil::make_attribute (sess->ulog_level));
  set (gbmif, "ulog-mode", sess->ulog_mode);
  conn_pin (gbmif, "ulog-out", sess->ulog_map[sess->ulog_file], "write");
  set (gbmif, "buffer-output", "false");
  conn_bus (gbmif, "global-bus", global_mapper, "access-port");

  add_child (gbmif);
}

void MepMemCfg::add_peripheral (const string type, 
				sid::host_int_4 mapped_addr,
				sid::host_int_4 mapped_size)
{
  static int i = 0;
  string name = type + sidutil::make_attribute (i++);
  AtomicCfg *p = new AtomicCfg (name, 
				"libmepfamily.la", 
				"mepfamily_component_library",
				"peripheral-" + type);
  assert (p);
  add_child (p);

  /* Map this peripheral into global memory at the address specified.  */
  assert (global_mapper);
  global_mapper->map (Mapping()
		      .low(mapped_addr).high(mapped_addr + mapped_size - 1)
		      .slave(p).bus("access-port"));

  /* Add a subscription to the scheduler so that this peripheral can be
     acctivated.  */
  assert (sess);
  assert (sess->sim_sched);
  sess->sim_sched->add_subscription (p, "burst-event", "burst-control");
  insn_count_1 = true;
}

static map<string, AtomicCfg*> mep_peripherals;

void MepMemCfg::add_toshapi_peripheral (const string type, 
					const string instance,
					sid::host_int_4 mapped_addr,
					sid::host_int_4 mapped_size)
{
  AtomicCfg *p = new AtomicCfg (instance, 
				"libmepfamily.la", 
				"mepfamily_component_library",
				"hw-toshapi-" + type + "-" + instance);
  assert (p);

  if (sess->verbose)
    set (p, "verbose?", "true");

  assert (sess);
  assert (sess->sim_sched);
  int n = sess->sim_sched->add_subscription (p, "step-insn");
  sess->sim_sched->set_regular (n, true);
  sess->sim_sched->set_time (n, 1);
  insn_count_1 = true;

  assert (sess->reset_net);
  sess->reset_net->add_output (0, p, "reset");

  conn_pin (p, "end-sim", sess->main_obj, "stop!");
  set (p, "ulog-level", sidutil::make_attribute (sess->ulog_level));
  set (p, "ulog-mode", sess->ulog_mode);
  conn_pin (p, "ulog-out", sess->ulog_map[sess->ulog_file], "write");
  set (p, "buffer-output", "false");

  add_child (p);
  // instance must match the instance name from MeP-Integrator
  mep_peripherals [instance] = p;

  /* Map this peripheral into global memory at the address specified.  */
  if (mapped_size > 0)
    {
      assert (global_mapper);
      global_mapper->map (Mapping()
			  .low(mapped_addr).high(mapped_addr + mapped_size - 1)
			  .slave(p).bus("control-bus"));

      MemCfg *mem = new MemCfg (instance + "-memory",  mapped_size, 10, 1);
      assert (mem);
      add_child (mem);
      relate (p, "__mapped_memory", mem);
    }
}

void MepMemCfg::map_peripheral (MepBoardCfg *board,
				sid::host_int_4 mapped_addr,
				sid::host_int_4 mapped_size)
{
  // Create a mapping from the main mapper to the global mapper, where
  // the peripheral is already mapped.
  assert (board->main_mapper);
  assert (global_mapper);

  Mapping m;
  if (board->gbif)
    m.bus("biu-interface").slave(board->gbif);
  else
    m.bus("access-port").slave(global_mapper);
  m.low(mapped_addr).high(mapped_addr + mapped_size - 1);
  board->main_mapper->map (m);
}

void
MepMemCfg::add_toshapi_global_bus_model (const string type, const string instance)
{
  gbmif_type = "hw-toshapi-" + type + "-" + instance;
}

void MepMemCfg::add_mm_int (MepMM_INTCfg *mm_int)
{
  // Map this mm_int into global memory at the address specified.
  // Allow 4 bytes per register per cpu.
  assert (mm_int);

  unsigned range = mm_int->get_range ();
  sid::big_int_4 mapped_addr = mm_int->get_mapped_addr ();

  assert (global_mapper);
  global_mapper->map (Mapping()
		      .low(mapped_addr).high(mapped_addr + range - 1)
		      .slave(mm_int).bus("access-port"));
}

void MepMemCfg::map_mm_int (MepBoardCfg *board, MepMM_INTCfg *mm_int)
{
  unsigned range = mm_int->get_range ();
  sid::big_int_4 mapped_addr = mm_int->get_mapped_addr ();

  // Map the mm_int into the board's main memory.
  assert (board->main_mapper);
  assert (global_mapper);
  Mapping m;
  if (board->gbif)
    m.bus("biu-interface").slave(board->gbif);
  else
    m.bus("access-port").slave(global_mapper);
  m.low(mapped_addr).high(mapped_addr + range - 1);
  board->main_mapper->map (m);
}

class MepCacheComponentCfg :
  virtual public BlockingCacheCfg
{
public:
  MepCacheComponentCfg (const string name, 
			const int cachesz = 16,
			const int linesz = 32,
			const int way = 1) :
    ComponentCfg (name),
    AtomicCfg (name, 
	       "libmepfamily.la", 
	       "mepfamily_component_library",
	       "hw-mep-cache-" +
	       sidutil::make_attribute(way) + "way/" + 
	       sidutil::make_attribute(cachesz) + "kb/" +
	       sidutil::make_attribute(linesz)),
    BlockingCacheCfg (name, cachesz, linesz)
  {}

protected:
  void compute_comptype ()
  {
    if (my_assoc == "")
      {
	my_assoc = "direct";
      }

    my_comptype = "hw-mep-cache-" + my_assoc + "/"
      + sidutil::make_attribute(my_size) + "kb/"
      + sidutil::make_attribute(my_line_size);
  } 
};

class MepCacheTagMemCfg : public MemCfg
{
public:
  MepCacheTagMemCfg (const string name, sid::host_int_4 size) :
    MemCfg (name, size * 1024),
    ComponentCfg (name),
    AtomicCfg (name, 
	       "libmepfamily.la", 
	       "mepfamily_component_library",
	       "hw-mep-cache-tag-memory")
  {}
};

class MepCacheCfg :
  virtual public AggregateCfg
{
public:
  MepCacheCfg (const string name, 
	       GlueSeqCfg *flusher, 
	       GlueSeqCfg *init_seq,
	       ComponentCfg *cpu,
	       MapperCfg *down,
	       const string downbus,
	       const int cachesz = 16,
	       const int linesz = 32,
	       const int way = 1,
	       const bool cwf = false,
	       const int hit_latency = 1,
	       const int miss_latency = 1,
	       const int refill_latency = 0):
    ComponentCfg (name),
    AggregateCfg (name),
    downstream (down),
    busname (downbus),
    my_cpu (cpu),
    main_mem_top (down),
    my_cwf (cwf),
    data_width (32),
    bit_insn_probe (0)
  {
    assert (downstream);
    assert (flusher);
    assert (init_seq);

    is_icache = (name == "icache");

    my_cache = new MepCacheComponentCfg ("cache", cachesz, linesz, way);
    set_way (way);
    assert (my_cache);
    add_child (my_cache);

    my_cache->set_hit_latency (hit_latency);
    my_cache->set_miss_latency (miss_latency);
    if (refill_latency)
      my_cache->set_refill_latency (refill_latency);

    my_mapper = new MapperCfg ("cache-map", true);
    assert (my_mapper);
    add_child (my_mapper);

    assert (flusher);
    flusher->add_output (0, my_cache, "flush-all");
    flusher->add_output (1, my_cache, "invalidate-all");

    map_name (my_mapper, bus, "access-port", "access-port");
    map_name (my_cache, attr, "report-heading", "report-heading");
    map_name (my_cache, attr, "write-allocate?", "write-allocate?");
    map_name (my_cache, attr, "name", "name");
    map_name (my_cache, attr, "blockable?", "blockable?");
    map_name (my_cache, attr, "ulog-level", "ulog-level");
    map_name (my_cache, attr, "ulog-mode", "ulog-mode");
    map_name (my_cache, out_pin, "ulog-out", "ulog-out");
    map_name (my_cache, attr, "buffer-output", "buffer-output");
    map_name (my_cache, out_pin, "downstream-lock", "downstream-lock");
    map_name (my_cache, attr, "total-latency?", "total-latency?");

    tag_test_mem = new MepCacheTagMemCfg ("tag-test-mem", cachesz);
    assert (tag_test_mem);
    set (tag_test_mem, "icache?", sidutil::make_attribute (is_icache));
    add_child (tag_test_mem);

    data_test_mem = new MemCfg ("data-test-mem", cachesz * 1024);
    assert (data_test_mem);
    add_child (data_test_mem);
  }      

  void set_main_mem_top (ComponentCfg *c, const string b)
  {
    main_mem_top = c;
    busname = b;
  }

  void configure ()
  {
    assert (downstream);
    if (my_cache->size () == 0)
      return; // nothing to do

    tag_test_mem->set_size (my_cache->size() * 1024);
    set (tag_test_mem, "line-size", sidutil::make_attribute (my_cache->line_size ()));
    set (tag_test_mem, "assoc", sidutil::make_attribute (my_way));
    data_test_mem->set_size (my_cache->size() * 1024);
    set (my_cache, "data-width", sidutil::make_attribute (data_width / 8));

    // Map tag and data test areas.
    assert (downstream);
    assert (my_cpu);
    Mapping test_map = Mapping().base(0).bus("read-write-port");
    if (is_icache)
      {
	downstream->map (test_map.low(0x300000).high(0x300000 + my_cache->size()*1024 - 1).slave(data_test_mem));
	downstream->map (test_map.low(0x310000).high(0x310000 + my_cache->size()*1024 - 1).slave(tag_test_mem));
	conn_pin (my_cpu, "insn-cache-enable", my_mapper, "bank");
	conn_pin (my_cpu, "insn-cache-invalidate-all", my_cache, "invalidate-all");
      }
    else
      {
	downstream->map (test_map.slave(data_test_mem).low(0x320000).high(0x320000 + my_cache->size()*1024 - 1));
	downstream->map (test_map.low(0x330000).slave(tag_test_mem).high(0x330000 + my_cache->size()*1024 - 1));
	conn_pin (my_cpu, "data-cache-enable", my_mapper, "bank");
	conn_pin (my_cpu, "cache-flush", my_cache, "flush");
	conn_pin (my_cpu, "cache-index-flush", my_cache, "flush-set");
	conn_pin (my_cpu, "cache-invalidate", my_cache, "clear-tag");
	conn_pin (my_cpu, "cache-index-invalidate", my_cache, "invalidate-set");
	conn_pin (my_cpu, "cache-flush-and-invalidate", my_cache, "flush-and-invalidate");
	conn_pin (my_cpu, "cache-index-flush-and-invalidate", my_cache, "flush-and-invalidate-set");
	conn_pin (my_cpu, "cache-prefetch", my_cache, "prefetch");
	conn_pin (my_cpu, "data-cache-invalidate-all", my_cache, "invalidate-all");

	if (bit_insn_probe)
	  bit_insn_probe->conn_bus (bit_insn_probe, "downstream", my_cache, "upstream");
      }
    conn_pin (my_cache, "operation-status", my_cpu, "cache-operation-status");
    my_cache->conn_bus (my_cache, "tag-test-mem", tag_test_mem, "read-write-port");
    my_cache->conn_bus (my_cache, "data-test-mem", data_test_mem, "read-write-port");

    assert (downstream);
    my_cache->set_downstream (main_mem_top, busname);
  }      

  void map_global_regions (MepMemCfg *shared_main_mem)
  {
    Mapping m;
    for (vector <MepMemRegionCfg *>::const_iterator i = shared_main_mem->mems.begin();
	 i != shared_main_mem->mems.end (); ++i)
      {
	if (! (*i)->valid ())
	  continue;
	sid::host_int_4 start = (*i)->start ();
	sid::host_int_4 end = start + (*i)->size () - 1;
	assert (*i);
	if ((*i)->cached ())
	  cache (m.low(start).high(end));
	else
	  pass (m.low(start).high(end));
      }
    for (vector <MepShadowRegion *>::const_iterator i = shared_main_mem->shadows.begin ();
	 i != shared_main_mem->shadows.end (); ++i)
      {
	sid::host_int_4 start = (*i)->start ();
	sid::host_int_4 end   = start + (*i)->size () - 1;
	if ((*i)->is_cached ())
	  cache (m.low(start).high(end));
	else
	  pass (m.low(start).high(end));
      }
  }

  void cache (const Mapping &m)
  {
    assert (my_mapper);
    assert (my_cache);
    assert (downstream);
    Mapping m1(m);
    // Insert the bit insn probe into the heirarchy for cached regions
    if (bit_insn_probe)
      my_mapper->map (m1.banks("{1}:cached").slave(bit_insn_probe).bus("upstream"));
    else
      my_mapper->map (m1.banks("{1}:cached").slave(my_cache).bus("upstream"));
    my_mapper->map (m1.banks("{0}:uncached").slave(main_mem_top).bus(busname));
  }

  void pass (const Mapping &m)
  {
    assert (my_mapper);
    assert (downstream);
    Mapping m1(m);
    my_mapper->map (m1.banks("{0,1}:uncacheable")
		    .slave(main_mem_top).bus(busname));
  }

  void need_bit_insn_probe ()
  {
    if (bit_insn_probe)
      return; // Already created

    // Create a bus probe
    bit_insn_probe = new AtomicCfg ("dcache-probe", "libglue.la", 
				    "glue_component_library", "hw-glue-probe-bus");
    add_child (bit_insn_probe);

    // Configure it to signal the cpu upon any activity.
    bit_insn_probe->set (bit_insn_probe, "sample-interval", "1");
    bit_insn_probe->conn_pin (bit_insn_probe, "address", my_cpu, "bit-insn-bad-address");
  }

  sid::host_int_4 size ()
  {
    assert (my_cache);
    return my_cache->size ();
  }

  void set_size (sid::host_int_4 sz)
  {
    assert (my_cache);
    my_cache->set_size (sz);
  }

  void set_way (sid::host_int_4 w)
  {
    assert (my_cache);
    my_cache->set_way (w);
    this->my_way = w;
  }

  void set_line_size (sid::host_int_4 sz)
  {
    assert (my_cache);
    my_cache->set_line_size (sz);
  }

  void set_cwf (bool c)
  {
    this->my_cwf = c;
  }

  void set_data_width (int w)
  {
    this->data_width = w;
  }
  sid::host_int_4 get_way ()
  {
    return this->my_way;
  }

  sid::host_int_4 get_line_size ()
  {
    assert (my_cache);
    return my_cache->get_line_size ();
  }

  bool get_cwf ()
  {
    return this->my_cwf;
  }

  void set_endianness (LoaderCfg *loader, const string endianness)
  {
    set (my_cache, "endian", endianness);
    if (loader)
      conn_pin (loader, "endian-set", my_cache, "endian-set!");
  }

  void set_dynamic_config (AtomicCfg *dynamic_configurator, Writer &w)
  {
    assert (dynamic_configurator);
    assert (my_cache);
    if (! my_cache->possibly_wrapped ())
      {
	Relation (dynamic_configurator, "client", my_cache).write_to (w);
      }
  }

protected:
  bool is_icache;
  string busname;
  bool my_cwf;
  sid::host_int_4 my_way;
  int data_width;
  MapperCfg *downstream;
  MepCacheComponentCfg *my_cache;
  MapperCfg *my_mapper;    
  ComponentCfg *my_cpu;
  MemCfg *tag_test_mem;
  MemCfg *data_test_mem;
  ComponentCfg *main_mem_top;
  AtomicCfg *bit_insn_probe;
};

class MepDSUCfg :
  virtual public AtomicCfg
{
public:
  MepDSUCfg (const string name,
	     MapperCfg *ctrlmap,
	     int core_type)  :
    ComponentCfg (name),
    AtomicCfg (name, "libmepfamily.la", 
	       "mepfamily_component_library", 
	       "hw-debug-mep")
  {  
    Mapping m = Mapping().wordsz(0x4).slave(this);
    if (core_type == MEP_CORE_H1)
      ctrlmap->map (m.low(0x800).high(0x805).bus("status-regs"));
    else
      ctrlmap->map (m.low(0x800).high(0x802).bus("status-regs"));
    ctrlmap->map (m.low(0x900).high(0x902).bus("insn-regs"));
    ctrlmap->map (m.low(0xA00).high(0xA05).bus("data-regs"));
  }
};

class MepINTCCfg :
  virtual public AtomicCfg
{
public:
  MepINTCCfg (const string name,
	      MapperCfg *ctrlmap,
	      ComponentCfg *cpu)  :
    ComponentCfg (name),
    AtomicCfg (name, "libmepfamily.la", 
	       "mepfamily_component_library", 
	       "hw-interrupt-mep-32"),
    channels (32)
  {
    conn_pin (this, "interrupt", cpu, "interrupt");
    Mapping m = Mapping().wordsz(0x4).slave(this);
    ctrlmap->map (m.low(0x0).high(0x7).bus("registers"));
  }

  void set_channels (sid::host_int_4 chan)
  {
    channels = chan;
    my_comptype = "hw-interrupt-mep-" + sidutil::make_attribute (chan);
  }

  sid::host_int_4 get_channels () const { return channels; }

  void set_level (sid::host_int_4 chan)
  {
    set (this, "cfg-interrupt-level", sidutil::make_attribute (chan));
  }

private:
  sid::host_int_4 channels;
};


class MepTimerCfg :
  virtual public AtomicCfg
{
public:
  MepTimerCfg (const string name, int channel_bitw) :
    ComponentCfg (name),
    AtomicCfg (name, "libmepfamily.la", 
	       "mepfamily_component_library", 
	       "hw-timer-mep"),
    channels (channel_bitw)
  {
  }

  void setup_interrupt_pins (MepINTCCfg * intc);
  int get_channels () const { return channels; }
  void set_channels (int channel_bitw) { channels = channel_bitw; }

private:
  int channels;
};

void
MepTimerCfg::setup_interrupt_pins (MepINTCCfg * intc)
{
  assert (intc);
  // The INTC only has limited channels
  sid::host_int_4 ch = intc->get_channels ();
  if (ch > channels)
    ch = channels;

  string timer_output = "interrupt-";
  for (sid::host_int_4 i = 0; i < ch; ++i)
    conn_pin (this, timer_output + sidutil::make_attribute (i),
	      intc, "interrupt-source-" + sidutil::make_attribute (i));
}


MepMemCfg *MepBoardCfg::shared_main_mem (NULL);
MepMM_INTCfg *MepBoardCfg::shared_mm_int (NULL);
sid::host_int_4 MepBoardCfg::curr_core_id (0);
vector<MepBoardCfg::MepIrq> MepBoardCfg::irq_specs;

MepBoardCfg::~MepBoardCfg () {}

MepBoardCfg::MepBoardCfg (const string name, 
			  const string type,
			  SessionCfg *sess) :
  ComponentCfg (name),
  AggregateCfg (name),
  BoardCfg (name, "mep", sess, false, true),
  core_rev (1),
  core_id (curr_core_id++),
  core_type (MEP_CORE_MEP),
  config_index (0),
  insn_buffer (NULL),
  biu_width (64),
  imem0 (NULL),
  imem1 (NULL),
  imem_size (0),
  dmem_bank_num (0),
  dmem_size (0),
  dmem_fixed_start_address (false),
  dmac_channel_bitw (0),
  dmac_data_width (0),
  dmac_rectangle (0),
  dcache (NULL),
  icache (NULL),
  removed_dcache (NULL),
  removed_icache (NULL),
  local_mapper (NULL),
  ctrlmap (NULL),
  dmac (NULL),
  dsu (NULL),
  intc (NULL),
  timer (NULL),
  gbif (NULL),
  gbif_type ("hw-gbif-mep"),
  lbif_type ("hw-lbif-mep"),
  lbif (NULL),
  hw_engines (0),
  main_mem_top (main_mapper),
  main_mem_bus ("access-port"),
  local_shadow_bit_insn_probe (0),
  warn_write_to_code (false),
  warn_write_to_rom (false),
  allow_write_to_rom (false),
  dsp_user_out (false),
  corrupt_caches (false),
  opt_bit_p (false),
  module_type (type),
  local_mems ()
{

  for (int i=0; i<dmem_max_banks; i++)
    {
      dmem[i] = NULL;
    }

  // the static, shared main memory

  if (! shared_main_mem)
    shared_main_mem = new MepMemCfg(sess, this);
  shared_main_mem->add_board (this);

  if (! shared_mm_int)
    allocate_mm_int ();

  // local memory bus

  local_mapper = new MapperCfg ("local");
  assert (local_mapper);
  local_mapper->set_transparent (false);

  // Bank 1 of the local mapper is connected to the readonly port
  // of any imem regions.
  assert (sess);
  sess->init_seq->add_output (2, local_mapper, "bank");

  // the connection between shared memory and BoardCfg::main_mapper

  assert (shared_main_mem);
  main_mapper->set_transparent (true);
        
  // divert the imem/dmem space directly into local memory. These accesses need not
  // use the GBIF
  //
  main_mapper->map (Mapping()
		    .low(imem_dmem_base).high(imem_dmem_base + imem_dmem_size - 1).base(0x0)
		    .slave(local_mapper).bus("access-port"));

  // use the mepcfgtool-edited custom local memory
  // begin-gmap-local-memory
  // end-gmap-local-memory

  // we build our own gloss here, since we want it to see local memory, and the base class
  // has no idea local memory exists.
  
  assert (cpu);
  assert (sess);
  gloss = new GlossCfg ("gloss", cpu, sess);  
  set (gloss, "syscall-numbering-scheme", "mep");
  assert (gloss);

  // control bus for peripheral items

  ctrlmap = new MapperCfg ("ctrl-map");
  assert (ctrlmap);
  conn_bus (cpu, "control-space", ctrlmap, "access-port");
    
  // insn buffer
  insn_buffer = new BlockingCacheCfg ("insn-buffer");
  assert (insn_buffer);
  insn_buffer->set (insn_buffer, "write-through?", "true");
  assert (cache_flush_net);
  cache_flush_net->add_output (0, insn_buffer, "flush-all");
  assert (sess);
  sess->init_seq->add_output (1, insn_buffer, "invalidate-all");
  assert (cpu);
  cpu->set_imem (insn_buffer, "upstream");
  cpu->set_disasm_mem (main_mapper, "access-port");
  relate (cpu, "insn-buffer", insn_buffer);
    
  add_child (gloss);
  add_child (insn_buffer);
  add_child (local_mapper);
  add_child (ctrlmap);
}

void MepBoardCfg::set_module_type (const string ty)
{
  module_type = ty;
}
string MepBoardCfg::get_module_type ()
{
  return module_type;
}

void MepBoardCfg::set_endian (const string endian)
{
  endianness = endian;
  BoardCfg::set_endian (endian);
}

void MepBoardCfg::set_loader (LoaderCfg *l)
{
  assert (l);

  // only want to do this once
  if (this->loader)
    return;

  BoardCfg::set_loader (l);
  assert (this->loader);
  main_mem_top = this->loader;
  main_mem_bus = "probe-upstream";
  if (icache)
    icache->set_main_mem_top (main_mem_top, main_mem_bus);
  if (dcache)
    dcache->set_main_mem_top (main_mem_top, main_mem_bus);
  if (dmac)
    dmac->conn_pin (dmac, "check-address", this->loader, "probe");
}

void MepBoardCfg::set_model_busses (bool b)
{
  shared_main_mem->set_model_busses (b);

  if (gbif || ! b)
    return;

  // --insn-count must be 1 for this board
  step_insn_count_1_required_p = true;

  // Create a GBIF component to arbitrate requests to the global and
  // local busses.
  gbif = new MepBusArbitratorCfg ("gbif", gbif_type);
  set (gbif, "name", this->get_name () + "/" + gbif->get_name ());
  assert (sess);
  sess->init_seq->add_output (2, gbif, "running");
  conn_pin (sess->sim_sched, "active", gbif, "active");
  sess->sim_sched->add_subscription (gbif, "step-event", "step-control");
  add_child (gbif);

  // Create a LBIF component to arbitrate requests to the global and
  // local busses.
  lbif = new MepBusArbitratorCfg ("lbif", lbif_type);
  set (lbif, "name", this->get_name () + "/" + lbif->get_name ());
  assert (sess);
  sess->init_seq->add_output (2, lbif, "running");
  conn_pin (sess->sim_sched, "active", lbif, "active");
  sess->sim_sched->add_subscription (lbif, "step-event", "step-control");
  add_child (lbif);
};

void MepBoardCfg::need_mm_int (sid::big_int_4 mapped_addr, unsigned reg_num,
			       unsigned corecount)
{
  assert (shared_main_mem);
  if (! shared_mm_int)
    {
      shared_mm_int = new MepMM_INTCfg (mapped_addr, reg_num, corecount);
      assert (shared_mm_int);

      shared_main_mem->add_child (shared_mm_int);
      shared_main_mem->add_mm_int (shared_mm_int);
    }
}

void MepBoardCfg::add_memory (const Mapping &m)
{
  if (main_mapper)
    {
      Mapping map (m);
      main_mapper->map (map.base(0));
    }
  // When someone adds a new --memory-region, we must pass that
  // region through the cache maps too.
  if (dcache)
    dcache->pass (m);
  if (icache)
    icache->pass (m);
}

MepMemRegionCfg *
MepBoardCfg::find_local_mem (const string name)
{
  for (vector <MepMemRegionCfg *>::iterator m = local_mems.begin ();
       m != local_mems.end (); ++m)
    {
      if (! (*m)->valid ())
	continue;
      if ((*m)->get_name () == get_name () + "/" + name)
	return *m;
    }
  return NULL;
}

MepMemRegionCfg *
MepBoardCfg::allocate_local_mem (sid::host_int_4 start,
				 sid::host_int_4 size,
				 const char *name)
{
  static int n = 0;
  MepMemRegionCfg *lmem;
  if (name != NULL)
    lmem = new MepMemRegionCfg (name, start, size);
  else
    lmem = new MepMemRegionCfg ("local-mem-" + sidutil::make_attribute (n++), start, size);
  return lmem;
}

void MepBoardCfg::add_local_mem (sid::host_int_4 start,
				 sid::host_int_4 size,
				 const char *name,
				 bool is_toshapi)
{
  MepMemRegionCfg *lmem = allocate_local_mem (start, size, name);
  assert (lmem);
  add_child (lmem);
  local_mems.push_back (lmem);

  // Create a toshapi Memory object and relate the local memory to it.
  if (is_toshapi)
    add_toshapi_local_mem (name, lmem);
}

void
MepBoardCfg::add_toshapi_local_mem (const string name, MepMemRegionCfg *lmem)
{
  AtomicCfg *tmem = new MepToshapiMemCfg (name, this);
  assert (tmem);
  add_child (tmem);
  relate (tmem, "__memory", lmem);
  lmem->set_toshapi (true);
}

MepMemRegionCfg *
MepBoardCfg::map_local_mem (sid::host_int_4 start, sid::host_int_4 size)
{
  MepMemRegionCfg *lmem = allocate_local_mem (start, size);
  assert (lmem);
  add_child (lmem);
  local_mems.push_back (lmem);
  return lmem;
}

void MepBoardCfg::map_local_mem (MepMemRegionCfg *lmem)
{
  // Make sure the memory is valid.
  if (! lmem->valid ())
    return;

  sid::host_int_4 start = lmem->start ();
  sid::host_int_4 size = lmem->size ();

  Mapping m;
  m.low(start).high(start + size - 1);

  if (dcache)
    dcache->pass (m);  
  if (icache)
    icache->pass (m);

  assert (main_mapper);
  assert (local_mapper);
  if (gbif)
    main_mapper->map (m.slave(gbif).bus("biu-interface"));
  else
    main_mapper->map (m.base(start - localmem_base)
		      .slave(local_mapper)
		      .bus("access-port"));

  local_mapper->map (m.low(start - localmem_base)
		      .high((start - localmem_base) + size - 1)
		      .base(0)
		      .slave(lmem)
		      .banks("{0,1}")
		      .bus("read-write-port"));
}

void MepBoardCfg::add_hw_engine (const string type, 
				 sid::host_int_4 cbus_addr,
				 int lbus_if,
				 sid::host_int_4 lbus_addr,
				 sid::host_int_4 lbus_size,
				 const char *local_mem_list)
{
  static int i = 0;
  int cbus_size = 0x1000; // toshiba-supplied constant
  string name = type + sidutil::make_attribute (i++);
  MepHWengineCfg *hw = new MepHWengineCfg (name, "hw-engine-" + type, this,
					   local_mem_list);
  assert (hw);
  add_child (hw);
  this->hwe [name] = hw;

  // Schedule this component at the same rate as the cpu
  assert (sess);
  assert (sess->sim_sched);
  assert (cpu);
  string ev = sidutil::make_attribute (cpu->get_subscription_number());
  ev += "-event";
  conn_pin (sess->sim_sched, ev, hw, "burst-event");
  step_insn_count_1_required_p = true;

  ++this->hw_engines;

  // Map this component into the control space.
  ctrlmap->map (Mapping()
		.low(cbus_addr).high(cbus_addr + cbus_size - 1)
		.wordsz(0x4).slave(hw).bus("control-bus"));

  // Connect this component's main memory to the main mapper.
  assert (main_mapper);
  assert (local_mapper);
  conn_bus (hw, "main-memory", main_mem_top, main_mem_bus);

  // Configure a mapper to handle the access to the local memory
  // region(s).
  hw->lbus_if_mapper = new MapperCfg (type + "-lbus-if-mapper");
  assert (hw->lbus_if_mapper);
  conn_bus (hw, "local-memory", hw->lbus_if_mapper, "access-port");
  add_child (hw->lbus_if_mapper);

  // Always provide access to the imem/dmem area.
  hw->lbus_if_mapper->map (Mapping()
			   .low(imem_dmem_base - localmem_base)
			   .high((imem_dmem_base - localmem_base) + imem_dmem_size - 1)
			   .slave(local_mapper).bus("access-port"));

  if (lbus_if)
    {
      // We need to configure a memory region on the local data bus and
      // make it also accessable from the lbus-if mapper.
      MemCfg *lmem = map_local_mem (lbus_addr, lbus_size);
      hw->lbus_if_mapper->map (Mapping()
			       .low(lbus_addr - localmem_base)
			       .high((lbus_addr - localmem_base) + lbus_size - 1)
			       .slave(lmem).bus("read-write-port"));
      hw->local_mem_list = NULL; // see configure_lmem
    }
}

void
MepHWengineCfg::configure_lmem ()
{
  // Configure the local memory interface, if specified.
  if (local_mem_list)
    {
      // A list of existing local memory regions has been specified. We
      // need to make them accessable from the lbus-if mapper.
      vector<string> local_mem_names = sidutil::tokenize (local_mem_list, ", ");
      while (local_mem_names.size() > 0)
	{
	  MepMemRegionCfg *lmem = board->find_local_mem (local_mem_names[0]);
	  if (lmem != NULL)
	    {
	      sid::host_int_4 address = lmem->start ();
	      if (address >= MepBoardCfg::localmem_base)
		lbus_if_mapper->map (Mapping()
				     .low(address - MepBoardCfg::localmem_base)
				     .high((address - MepBoardCfg::localmem_base) + lmem->size () - 1)
				     .slave(lmem).bus("read-write-port"));
	    }
	  local_mem_names.erase (local_mem_names.begin ());
	}
    }
}

MepToshapiHWengineCfg*
MepBoardCfg::add_toshapi_hw_engine (const string type, 
				    const string instance,
				    sid::host_int_4 cbus_addr,
				    int lbus_if,
				    sid::host_int_4 lbus_addr,
				    sid::host_int_4 lbus_size,
				    const char *local_mem_list)
{
  int cbus_size = 0x1000; // toshiba-supplied constant
  MepToshapiHWengineCfg *hw = new MepToshapiHWengineCfg (instance, "hw-toshapi-" + type + "-" + instance, this,
							 local_mem_list);
  assert (hw);

  if (sess->verbose)
    set (hw, "verbose?", "true");

  // Schedule this component at the same rate as the cpu
  assert (sess);
  assert (sess->sim_sched);
  assert (cpu);
  string ev = sidutil::make_attribute (cpu->get_subscription_number());
  ev += "-event";
  conn_pin (sess->sim_sched, ev, hw, "step-insn");
  step_insn_count_1_required_p = true;

  ++this->hw_engines;

  assert (sess->reset_net);
  sess->reset_net->add_output (0, hw, "reset");

  conn_pin (hw, "end-sim", sess->main_obj, "stop!");
  add_child (hw);
  if (this->intc)
    relate (hw, "intc", this->intc);
  if (this->dmac)
    relate (hw, "dmac", this->dmac);

  // instance must match the instance name from MeP-Integrator
  this->hwe [instance] = hw;

  if (cbus_addr >= 0 && cbus_addr <= 0xffff)
    ctrlmap->map (Mapping()
		  .low(cbus_addr).high(cbus_addr + cbus_size - 1)
		  .wordsz(0x4).slave(hw).bus("control-bus"));

  if (lbus_if)
    {
      assert (local_mem_list);
      // We need to configure a memory region on the local data bus and
      // make it also accessable from the lbus-if mapper.
      MemCfg *lmem = map_local_mem (lbus_addr, lbus_size);
      relate (hw, local_mem_list /* but really singular */, lmem);
      hw->local_mem_list = NULL; // See configure_lmem
    }

  return hw;
}

void
MepToshapiHWengineCfg::configure_lmem ()
{
  // Configure the local memory interface, if specified.
  if (local_mem_list)
    {
      // Relate each individual memory component.
      vector<string> local_mem_names = sidutil::tokenize (local_mem_list, ", ");
      while (local_mem_names.size() > 0)
	{
	  MemCfg *lmem = MemCfg::get_by_name (local_mem_names[0]);
	  if (lmem != NULL)
	    relate (this, local_mem_names[0], lmem);
	  local_mem_names.erase (local_mem_names.begin ());
	}
    }
}


void
MepToshapiHWengineCfg::add_dmac_hw_req (const string signal, unsigned ch)
{
  set (this, "signal-map", signal + "=" + sidutil::make_attribute (ch));
}


void
MepToshapiHWengineCfg::write_config(Writer &w)
{
  set (this, "ulog-level", sidutil::make_attribute (board->ulog_level));
  set (this, "ulog-mode", board->ulog_mode);
  conn_pin (this, "ulog-out", board->sess->ulog_map[board->ulog_file], "write");
  set (this, "buffer-output", "false");
  AtomicCfg::write_config (w);
}


void
MepToshapiMemCfg::write_config (Writer &w)
{
  set (this, "ulog-level", sidutil::make_attribute (board->ulog_level));
  set (this, "ulog-mode", board->ulog_mode);
  conn_pin (this, "ulog-out", board->sess->ulog_map[board->ulog_file], "write");
  set (this, "buffer-output", "false");
  AtomicCfg::write_config (w);
}


void MepBoardCfg::add_dsp (const string name,
			   int cbus_if,
			   int lbus_if,
			   sid::host_int_4 lbus_addr,
			   sid::host_int_4 lbus_size,
			   int dmem_if_width,
			   const char *local_mem_list)
{
  static int i = 0;
  int cbus_size = 0x1000; // toshiba-supplied constant
  int cbus_addr = 0x3000; // toshiba-supplied constant

  set_opt_dsp (true);

  // Add the control bus interface, if specified.
  MemCfg *mem;
  if (cbus_if)
    {
      // Add access via the control bus at address 0x3000 (Toshiba-supplied
      // constant).
      mem = new MemCfg ("dsp-" + name + "-ctrl-mem-" + sidutil::make_attribute (i++),
			cbus_size * 4);
      assert (mem);
      add_child (mem);

      assert (ctrlmap);
      Mapping m = Mapping().wordsz(4).slave(mem);
      ctrlmap->map (m.low(cbus_addr).high(cbus_addr + cbus_size - 1)
		     .bus("read-write-port"));
    }

  // Add the local memory interface, if specified.
  if (lbus_if && ! local_mem_list)
    map_local_mem (lbus_addr, lbus_size);

  set (cpu, "dsp-dmem-if-width", sidutil::make_attribute (dmem_if_width));
}


MepToshapiHWengineCfg *
MepBoardCfg::add_toshapi_dsp (const string type, 
			      const string instance,
			      int cbus_if,
			      int lbus_if,
			      sid::host_int_4 lbus_addr,
			      sid::host_int_4 lbus_size,
			      int dmem_if_width,
			      const char *local_mem_list)
{
  int cbus_addr = 0x3000; // toshiba-supplied constant

  set_opt_dsp (true);

  // It's much like a hw_engine
  MepToshapiHWengineCfg *dsp = this->add_toshapi_hw_engine (type, instance, cbus_addr, lbus_if, 
							    lbus_addr, lbus_size, local_mem_list);
  // but not a hw engine.
  --this->hw_engines;

  // Connect DSP pins
  conn_pin (cpu, "dsp-arg1", dsp, "ucidsp-arg1");
  conn_pin (cpu, "dsp-arg2", dsp, "ucidsp-arg2");
  conn_pin (cpu, "dsp-arg3", dsp, "ucidsp-arg3");
  conn_pin (cpu, "dsp-arg4", dsp, "ucidsp-arg4");
  conn_pin (cpu, "dsp-arg7", dsp, "ucidsp-arg7");
  conn_pin (dsp, "ucidsp-exception", cpu, "dsp-exception");
  conn_pin (dsp, "ucidsp-cycles", cpu, "dsp-cycles");
  conn_pin (dsp, "ucidsp-result", cpu, "dsp-result");

  // Save this dsp so that furth configuration can be done later.
  toshapi_dsps.push_back (dsp);

  conn_pin (dsp, "dsp-log-out", cpu, "trace");

  set (cpu, "dsp-dmem-if-width", sidutil::make_attribute (dmem_if_width));
  return dsp;
}


void MepBoardCfg::add_toshapi_uci (const string type, const string instance)
{
  // It's a little like a hw_engine
  AtomicCfg *dsp = this->add_toshapi_hw_engine (type, instance,
						0xffffffff /* no upstream cbus */,
						0, 0, 0, NULL);
  // but not a hw engine.
  --this->hw_engines;

  // Connect UCI pins
  this->conn_pin (cpu, "uci-arg1", dsp, "ucidsp-arg1");
  this->conn_pin (cpu, "uci-arg2", dsp, "ucidsp-arg2");
  this->conn_pin (cpu, "uci-arg3", dsp, "ucidsp-arg3");
  this->conn_pin (cpu, "uci-arg4", dsp, "ucidsp-arg4");
  this->conn_pin (dsp, "ucidsp-exception", cpu, "uci-exception");
  this->conn_pin (dsp, "ucidsp-cycles", cpu, "dsp-cycles");
  this->conn_pin (dsp, "ucidsp-result", cpu, "uci-result");
}


void
MepBoardCfg::add_toshapi_global_bus_if_model (const string type, const string instance)
{
  gbif_type = "hw-toshapi-" + type + "-" + instance;
}

void
MepBoardCfg::add_toshapi_local_bus_model (const string type, const string instance)
{
  lbif_type = "hw-toshapi-" + type + "-" + instance;
}

void MepBoardCfg::set_core_type (int t)
{
  core_type = t;
}


void MepBoardCfg::set_core_id (sid::host_int_4 i)
{
  core_id = i;
  if (curr_core_id <= core_id)
    curr_core_id = core_id + 1;
}


void MepBoardCfg::need_icache ()
{
  // Return if we already have an icache.
  if (icache)
    return;
  // Use a previously removed icache, if it exists.
  if (removed_icache)
    {
      icache = removed_icache;
      removed_icache = NULL;
      return;
    }
  // Allocate a new icache.
  assert (sess);
  assert (sess->init_seq);
  assert (cpu);
  assert (main_mapper);
  icache = new MepCacheCfg ("icache", cache_flush_net, sess->init_seq, cpu,
			    main_mapper, "access-port",
			    16, 32, 1, false, 0, 3, 10);
  assert (icache);
  add_child (icache);
}

void MepBoardCfg::configure_icache ()
{
  assert (icache);
  if (icache->size () == 0)
    return;

  LoaderCfg *the_loader = loader ? loader : sess->get_loader ();
  icache->set_endianness (the_loader, endianness);
  if (gbif)
    icache->set_data_width (biu_width);
  icache->configure ();

  // use the mepcfgtool-edited custom icache map
  Mapping m;

  // First pass the cache tag test areas.
  sid::host_int_4 icache_size = icache->size ();
  assert (icache_size);
  icache_size = icache_size * 1024;
  icache->pass (m.low(icache_lines_address).high(icache_lines_address + icache_size - 1));
  icache->pass (m.low(icache_tags_address).high(icache_tags_address + icache_size - 1));

  if (dcache)
    {
      sid::host_int_4 dcache_size = dcache->size ();
      assert (dcache_size);
      dcache_size = dcache_size * 1024;
      icache->pass (m.low(dcache_lines_address).high(dcache_lines_address + dcache_size - 1));
      icache->pass (m.low(dcache_tags_address).high(dcache_tags_address + dcache_size - 1));
    }

  // Now pass or cache the global memory and shadow areas
  icache->map_global_regions (shared_main_mem);

  // Pass the appropriate peripheral regions
  // begin-icache-settings
  // end-icache-settings

  // pass the imem/dmem space, which is always present.
  icache->pass (m.low(imem_dmem_base).high(imem_dmem_base + imem_dmem_size - 1));

  // Pass the mm_int region
  if (shared_mm_int)
    {
      unsigned range = shared_mm_int->get_range ();
      sid::big_int_4 mapped_addr = shared_mm_int->get_mapped_addr ();

      Mapping m = Mapping().low(mapped_addr).high(mapped_addr + range - 1);
      icache->pass (m);
    }

  icache->set (icache, "report-heading", "insn profile report");  
}

void MepBoardCfg::need_dcache ()
{
  // Return if we already have an dcache.
  if (dcache)
    return;
  // Use a previously removed dcache, if it exists.
  if (removed_dcache)
    {
      dcache = removed_dcache;
      removed_dcache = NULL;
      return;
    }
  // Allocate a new dcache.
  assert (cpu);
  assert (main_mapper);
  assert (sess);
  assert (sess->init_seq);
  dcache = new MepCacheCfg ("dcache", cache_flush_net, sess->init_seq, cpu,
			    main_mapper, "access-port",
			    16, 32, 1, false, 0, 3, 10);
  assert (dcache);
  add_child (dcache);
}

void MepBoardCfg::configure_dcache ()
{
  assert(dcache);
  if (dcache->size() == 0)
    return;

  LoaderCfg *the_loader = loader ? loader : sess->get_loader ();
  dcache->set_endianness (the_loader, endianness);
  if (gbif)
    dcache->set_data_width (biu_width);
  dcache->configure ();

  // use the mepcfgtool-edited custom dcache map
  Mapping m;

  // First pass the cache tag test areas.
  sid::host_int_4 dcache_size = dcache->size ();
  assert (dcache_size);
  dcache_size = dcache_size * 1024;
  dcache->pass (m.low(dcache_lines_address).high(dcache_lines_address + dcache_size - 1));
  dcache->pass (m.low(dcache_tags_address).high(dcache_tags_address + dcache_size - 1));

  if (icache)
    {
      sid::host_int_4 icache_size = icache->size ();
      assert (icache_size);
      icache_size = icache_size * 1024;
      dcache->pass (m.low(icache_lines_address).high(icache_lines_address + icache_size - 1));
      dcache->pass (m.low(icache_tags_address).high(icache_tags_address + icache_size - 1));
    }

  // Now pass or cache the global memory and shadow areas
  dcache->map_global_regions (shared_main_mem);

  // Pass the appropriate peripheral regions
  // begin-dcache-settings
  // end-dcache-settings

  // pass the imem/dmem space, which is always present.
  dcache->pass (m.low(imem_dmem_base).high(imem_dmem_base + imem_dmem_size - 1));

  // Pass the mm_int region
  if (shared_mm_int)
    {
      unsigned range = shared_mm_int->get_range ();
      sid::big_int_4 mapped_addr = shared_mm_int->get_mapped_addr ();

      Mapping m = Mapping().low(mapped_addr).high(mapped_addr + range - 1);
      dcache->pass (m);
    }

  dcache->set (dcache, "report-heading", "data profile report");
  dcache->set (dcache, "write-allocate?", "true");
}

void MepBoardCfg::allocate_mm_int ()
{
  // begin-mm_int
  // end-mm_int
}

void MepBoardCfg::set_icache_size (sid::host_int_4 v)
{
  // If setting the size to 0 (i.e. removing the icache), set aside the
  // current icache in case we need it later.
  if (v == 0)
    {
      if (icache)
	{
	  assert (! removed_icache);
	  removed_icache = icache;
	  icache = NULL;
	}
      return;
    }

  // Otherwise make sure we have an icache and set the size.
  need_icache ();
  assert (icache);
  icache->set_size (v);
}

void MepBoardCfg::set_icache_line_size (sid::host_int_4 v)
{
  MepCacheCfg *cache;
  // Make sure we have an icache
  if (removed_icache)
    cache = removed_icache;
  else
    {
      need_icache ();
      assert (icache);
      cache = icache;
    }
  cache->set_line_size (v);
}

void MepBoardCfg::set_icache_way (sid::host_int_4 v)
{
  MepCacheCfg *cache;
  // Otherwise make sure we have an icache
  if (removed_icache)
    cache = removed_icache;
  else
    {
      need_icache ();
      assert (icache);
      cache = icache;
    }
  cache->set_way (v);
}

void MepBoardCfg::set_icache_cwf (bool b)
{
  MepCacheCfg *cache;
  // Otherwise make sure we have an icache
  if (removed_icache)
    cache = removed_icache;
  else
    {
      need_icache ();
      assert (icache);
      cache = icache;
    }
  cache->set_cwf (b);
}

void MepBoardCfg::set_dcache_size (sid::host_int_4 v)
{
  // If setting the size to 0 (i.e. removing the dcache), set aside the
  // current dcache in case we need it later.
  if (v == 0)
    {
      if (dcache)
	{
	  assert (! removed_dcache);
	  removed_dcache = dcache;
	  dcache = NULL;
	}
      return;
    }

  // Otherwise make sure we have an dcache and set the size.
  need_dcache ();
  assert (dcache);
  dcache->set_size (v);
}

void MepBoardCfg::set_dcache_line_size (sid::host_int_4 v)
{
  MepCacheCfg *cache;
  // Make sure we have an dcache
  if (removed_dcache)
    cache = removed_dcache;
  else
    {
      need_dcache ();
      assert (dcache);
      cache = dcache;
    }
  cache->set_line_size (v);
}

void MepBoardCfg::set_dcache_way (sid::host_int_4 v)
{
  MepCacheCfg *cache;
  // Otherwise make sure we have an dcache
  if (removed_dcache)
    cache = removed_dcache;
  else
    {
      need_dcache ();
      assert (dcache);
      cache = dcache;
    }
  cache->set_way (v);
}

void MepBoardCfg::set_dcache_cwf (bool b)
{
  MepCacheCfg *cache;
  // Otherwise make sure we have an icache
  if (removed_dcache)
    cache = removed_dcache;
  else
    {
      need_dcache ();
      assert (dcache);
      cache = dcache;
    }
  cache->set_cwf (b);
}

void MepBoardCfg::set_imem_size (sid::host_int_4 v)
{
  imem_size = v;
  if (! imem0 && v != 0)
    {
      assert (! imem1);
      imem0 = new MemCfg ("imem0");
      imem1 = new MemCfg ("imem1");
      assert (imem0);
      assert (imem1);
      add_child (imem0);
      add_child (imem1);
    }
}

void MepBoardCfg::set_dmem_size (sid::host_int_4 v)
{
  dmem_size = v;
  if (! dmem[0] && v != 0)
    {
      for (int i = 0; i < dmem_max_banks; i++) {
	assert (! dmem[i]);
	dmem[i] = new MemCfg ("dmem" + sidutil::make_attribute (i));
	assert (dmem[i]);
	add_child (dmem[i]);
      }
    }
}

void MepBoardCfg::set_dmem_bank_num (sid::host_int_4 v)
{
  if (v != 0 && (v < 2 || v > dmem_max_banks)) {
    return;
  }
  dmem_bank_num = v;
}

void MepBoardCfg::set_dmem_fixed_start_address (bool b)
{
  dmem_fixed_start_address = b;
}


void MepBoardCfg::map_imem_dmem ()
{
  // Allocate the imem banks
  if (imem_size)
    {
      assert (imem0);
      assert (imem1);
      if (imem_size == 6 || imem_size == 12 || imem_size == 24)
	{
	  imem0->set_size (imem_size*1024 * 2 / 3);
	  imem1->set_size (imem_size*1024 - imem0->size ());
	}
      else
	{
	  int v = (imem_size * 1024) / 2; // imem is 2-bank style
	  imem0->set_size (v);
	  imem1->set_size (v);
	}
    }

  // Allocate the dmem banks
  if (dmem_bank_num && dmem_size)
    {
      int v = (dmem_size * 1024) / dmem_bank_num; // dmem may have 2, 3, or 4 banks
      for (int i = 0; i < dmem_bank_num; i++) {
	assert (dmem[i]);
	dmem[i]->set_size (v);
      }

      // Relate the dmem banks to the each toshapi DSP.
      for (vector <MepToshapiHWengineCfg *>::iterator d = toshapi_dsps.begin ();
	   d != toshapi_dsps.end (); ++d)
	{
	  for (int i = 0; i < dmem_bank_num; i++)
	    {
	      assert (dmem[i]);
	      relate (*d, "dmem" + sidutil::make_attribute (i), dmem[i]);
	    }
	}
    }

  dmem_base[0] = 0;
  if (imem_size)
    {
      assert (imem0);
      assert (imem1);
      // Wanted to use imem_dmem_base here, but the compiler couldn't resolve it for some reason.
      set (imem0, "base-address", "0x" + sidutil::make_numeric_attribute (0x200000, std::ios::hex));
      set (imem1, "base-address", "0x" + sidutil::make_numeric_attribute (0x200000 + imem0->size(), std::ios::hex));

      assert (local_mapper);
      Mapping m = Mapping().banks("{0,1}").bus("read-write-port");
      local_mapper->map (m.low(0).high(imem0->size () - 1).slave(imem0));
      local_mapper->map (m.low(imem0->size ()).high(imem0->size () + imem1->size () - 1).slave(imem1));

      if (dmem_fixed_start_address)
	dmem_base[0] = 0x80000;
      else
	{
#define IMEM_LIMITS	4
#define DMEM_LIMITS	6

	  /* 
	   * These limits are all just powers of two (today), but we'll use a table
	   * in case that changes in the future.  Duplicate entries (e.g., 1/2/4/6/8k)
	   * have been combined, where possible, to reduce table size and complexity.
	   *
	   * The limits are the values that mark the "top" of a range for search purposes.
	   *
	   */
	  sid::host_int_4
	    imem_limit[IMEM_LIMITS] = {0, 8, 16, 32};

	  sid::host_int_4
	    dmem_limit[DMEM_LIMITS] = {0, 8, 16, 32, 64, 128};

	  /* 
	   * This table represents the dmem base address values for the various
	   * dmem (rows) and imem (columns) combinations possible as per the 
	   * MeP Media User's Manual Rev. 5.0, section 4.6.2.
	   * 
	   */

	  sid::host_int_4
	    dmem_base_address[DMEM_LIMITS][IMEM_LIMITS] = {
/*             imem:	none,    1-8k,  12-16k,  24-32k */
/* dmem:    none */ {0x00000, 0x00000, 0x00000, 0x00000},
/* dmem:   1-8k  */ {0x00000, 0x02000, 0x04000, 0x08000},
/* dmem:  12-16k */ {0x00000, 0x04000, 0x04000, 0x08000},
/* dmem:  24-32k */ {0x00000, 0x08000, 0x08000, 0x08000},
/* dmem:  48-64k */ {0x00000, 0x10000, 0x10000, 0x10000},
/* dmem: 96-128k */ {0x00000, 0x20000, 0x20000, 0x20000},
	    };

	  // indices into the table; used for searching.
	  sid::signed_host_int_4 imem_index, dmem_index;

	  //  find the imem limit in the table
	  imem_index = -1;
	  for (int i=0; i<IMEM_LIMITS; i++) 
	    {
	      if (imem_size <= imem_limit[i]) 
		{
		  imem_index = i;
		  break;
		}
	    }

	  //  find the dmem limit in the table
	  dmem_index = -1;
	  for (int i=0; i<DMEM_LIMITS; i++) 
	    {
	      if (dmem_size <= dmem_limit[i]) 
		{
		  dmem_index = i;
		  break;
		}
	    }

	  if ((dmem_index >= 0) && (imem_index >= 0)) 	// found it
	    dmem_base[0] = dmem_base_address[dmem_index][imem_index];
	  else 
	    dmem_base[0] = 0xdeadbeef;		// can't happen
	}
    }

  if (dmem_bank_num && dmem_size)
    {
      assert (dmem[0]);
      for (int i=0; i<dmem_bank_num; i++) 
	{		// on the zeroth iteration, no increment to base
	  if (((dmem_size == 6) || (dmem_size == 12) || (dmem_size == 24)) &&
	      (dmem_bank_num == 2)) 
	    {	// adjust up to the next power of two 
	      dmem_base[i] = dmem_base[0] + (i * ((dmem_size * 1024) * 2 / 3));	
	    } 
	  else 
	    {
	      dmem_base[i] = dmem_base[0] + (i * (dmem[i]->size()));	
	    }
	}

      assert (local_mapper);
      if (opt_bit_p)
	{
	  // If bit insns are enabled, insert a bus probe for each dmem bank here.
	  Mapping m = Mapping().banks("{0,1}").bus("upstream");
	  for (int i=0; i<dmem_bank_num; i++) 
	    {
	      assert (dmem_probes[i]);
	      local_mapper->map (m.low(dmem_base[i]).high(dmem_base[i] + dmem[i]->size () - 1).slave(dmem_probes[i]));
	      dmem_probes[i]->set (dmem_probes[i], "base-address", "0x" + sidutil::make_numeric_attribute (dmem_base[i], std::ios::hex));
	      conn_bus (dmem_probes[i], "downstream", dmem[i], "read-write-port");
	    }
	}
      else
	{
	  // Otherwise, connect the dmem bank directly to the local mapper.
	  Mapping m = Mapping().banks("{0,1}").bus("read-write-port");
	  for (int i=0; i<dmem_bank_num; i++) 
	    local_mapper->map (m.low(dmem_base[i]).high(dmem_base[i] + dmem[i]->size () - 1).slave(dmem[i]));
	}
    }
}

bool MepBoardCfg::shadow_covers_local_region (sid::host_int_4 s_base, sid::host_int_4 s_base_end,
					      sid::host_int_4 &offset, sid::host_int_4 &size, bool & is_dmem)
{
  // Determine whether the given region entirely covers a real local region.
  // This includes IMEM and DMEM regions.
  is_dmem = false;
  if (imem_size && imem_dmem_base >= s_base && imem_dmem_base + imem_size*1024 - 1 <= s_base_end)
    {
      offset = imem_dmem_base - s_base;
      size = imem_size * 1024;
      return true;
    }

  if (dmem_size && dmem_bank_num)
    {
      size = dmem_base[dmem_bank_num - 1] + dmem[dmem_bank_num - 1]->size () - dmem_base[0];
      sid::host_int_4 base = imem_dmem_base + dmem_base[0];
      if (base >= s_base && base + size - 1 <= s_base_end)
	{
	  offset = base - s_base;
	  is_dmem = true;
	  return true;
	}
    }

  for (vector <MepMemRegionCfg *>::const_iterator r = local_mems.begin ();
       r != local_mems.end (); ++r)
    {
      if (! (*r)->valid ())
	continue;
      sid::host_int_4 r_start = (*r)->start ();
      sid::host_int_4 r_size = (*r)->size ();
      sid::host_int_4 r_end = r_start + r_size - 1;
      if (r_start >= s_base && r_end <= s_base_end)
	{
	  offset = r_start - s_base;
	  size = r_size;
	  return true;
	}
    }

  return false; // does not completely cover a local area
}

void
MepMemCfg::write_config(Writer &w)
{
  static bool global_memory_mapped = false;

  // Map the global memory and global/local shadows
  if (! global_memory_mapped)
    {
      global_memory_mapped = true;
      map_global_memory ();
    }
  map_boards ();

  AggregateCfg::write_config (w);
}

void MepBoardCfg::write_load (Writer &w)
{
  assert (sess);
  if (sess->maybe_model_busses)
    set_model_busses (true);

  if (opt_bit_p)
    {
      if (dmem_bank_num && dmem_size)
	{
	  // Create a bus probe for each dmem bank
	  for (int i=0; i<dmem_bank_num; i++) 
	    {
	      AtomicCfg *probe = new AtomicCfg ("dmem-probe" + sidutil::make_attribute (i), "libglue.la", 
						"glue_component_library", "hw-glue-probe-bus");
	      // Configure it to signal the cpu upon any activity.
	      probe->set (probe, "sample-interval", "1");
	      probe->conn_pin (probe, "address", cpu, "bit-insn-bad-address");

	      add_child (probe);
	      dmem_probes.push_back (probe);
	    }
	}

      // We may need a probe for local shadows onto another modules dmem.
      local_shadow_bit_insn_probe = new AtomicCfg ("local-shadow-bit-insn-probe", "libglue.la", 
						   "glue_component_library", "hw-glue-probe-bus");
      // Configure it to signal the cpu upon any activity.
      local_shadow_bit_insn_probe->set (local_shadow_bit_insn_probe, "sample-interval", "1");
      local_shadow_bit_insn_probe->conn_pin (local_shadow_bit_insn_probe, "address", cpu, "bit-insn-bad-address");
      add_child (local_shadow_bit_insn_probe);

      if (dcache)
	dcache->need_bit_insn_probe ();
    }

  BoardCfg::write_load (w);
}

void MepBoardCfg::write_config (Writer &w)
{
  assert (cpu);
  set (cpu, "config-index", sidutil::make_attribute (config_index));
  set (cpu, "corrupt-caches?", sidutil::make_attribute (corrupt_caches));

  // Create a mapping from the main mapper to the global mapper, where
  // the mm_int is already mapped.
  if (shared_mm_int)
    shared_main_mem->map_mm_int (this, shared_mm_int);

  // Setup the bus model, if requested
  if (gbif)
    {
      assert (sess);
      assert (insn_buffer);
      assert (lbif);
      assert (shared_main_mem->gbmif);

      // Configure the cpu to run in blockable mode with ulog enabled
      //
      set (cpu, "name", cpu->get_name ());
      set (cpu, "blockable?", "true");
      set (cpu, "ulog-level", sidutil::make_attribute (ulog_level));
      set (cpu, "ulog-mode", ulog_mode);
      conn_pin (cpu, "ulog-out", sess->ulog_map[ulog_file], "write");
      set (cpu, "buffer-output", "false");

      // Same for the GBIF
      set (gbif, "ulog-level", sidutil::make_attribute (ulog_level));
      set (gbif, "ulog-mode", ulog_mode);
      conn_pin (gbif, "ulog-out", sess->ulog_map[ulog_file], "write");
      set (gbif, "buffer-output", "false");
      conn_pin (cpu, "downstream-passthrough", gbif, "passthrough");

      // Finish connecting to the GBMIF
      conn_pin (cpu, "downstream-passthrough", shared_main_mem->gbmif,
		"passthrough-" + sidutil::make_attribute (core_id));
      conn_bus (gbif, "global-bus-master", shared_main_mem->gbmif,
		"gbif-interface-" + sidutil::make_attribute (core_id));
      conn_pin (gbif, "gbmif-lock", shared_main_mem->gbmif,
		"gbif-lock-" + sidutil::make_attribute (core_id));
      conn_pin (gbif, "local-memory-lock", lbif, "gbif-lock");

      // Set up the LBIF
      set (lbif, "ulog-level", sidutil::make_attribute (ulog_level));
      set (lbif, "ulog-mode", ulog_mode);
      conn_pin (lbif, "ulog-out", sess->ulog_map[ulog_file], "write");
      set (lbif, "buffer-output", "false");
      conn_pin (cpu, "downstream-passthrough", lbif, "passthrough");

      // The insn_buffer must be blockable
      set (insn_buffer, "name", insn_buffer->get_name ());
      set (insn_buffer, "blockable?", "true");
      set (insn_buffer, "ulog-level", sidutil::make_attribute (ulog_level));
      set (insn_buffer, "ulog-mode", ulog_mode);
      conn_pin (insn_buffer, "ulog-out", sess->ulog_map[ulog_file], "write");
      set (insn_buffer, "buffer-output", "false");
      set (insn_buffer, "total-latency?", "true");
      set (insn_buffer, "data-width", sidutil::make_attribute (biu_width / 8));
      conn_pin (insn_buffer, "downstream-lock", gbif, "biu-lock");

      // Same for the caches
      if (icache)
	{
	  set (icache, "name", icache->get_name ());
	  set (icache, "blockable?", "true");
	  set (icache, "ulog-level", sidutil::make_attribute (ulog_level));
	  set (icache, "ulog-mode", ulog_mode);
	  conn_pin (icache, "ulog-out", sess->ulog_map[ulog_file], "write");
	  set (icache, "buffer-output", "false");
	  set (icache, "total-latency?", "true");
	  conn_pin (icache, "downstream-lock", gbif, "biu-lock");
	}

      if (dcache)
	{
	  set (dcache, "name", dcache->get_name ());
	  set (dcache, "blockable?", "true");
	  set (dcache, "ulog-level", sidutil::make_attribute (ulog_level));
	  set (dcache, "ulog-mode", ulog_mode);
	  conn_pin (dcache, "ulog-out", sess->ulog_map[ulog_file], "write");
	  set (dcache, "buffer-output", "false");
	  set (dcache, "total-latency?", "true");
	  conn_pin (dcache, "downstream-lock", gbif, "biu-lock");
	}

      // Same for the dmac
      if (dmac)
	{
	  set (dmac, "name", dmac->get_name ());
	  set (dmac, "blockable?", "true");
	  set (dmac, "ulog-level", sidutil::make_attribute (ulog_level));
	  set (dmac, "ulog-mode", ulog_mode);
	  conn_pin (dmac, "ulog-out", sess->ulog_map[ulog_file], "write");
	  set (dmac, "buffer-output", "false");
	  conn_pin (dmac, "gbif-lock", gbif, "dmac-lock");
	  conn_pin (dmac, "lbif-lock", lbif, "dmac-lock");
	}
    }

  for (vector <string>::iterator s = insns.begin ();
       s != insns.end (); ++s)
    {
      if (*s == "abs")
	set_opt_abs (true);
      else if (*s ==  "ave")
	set_opt_ave (true);
      else if (*s ==  "bit")
	set_opt_bit (true);
      else if (*s ==  "clp")
	set_opt_clp (true);
      else if (*s ==  "div")
	set_opt_div (true);
      else if (*s ==  "ldz")
	set_opt_ldz (true);
      else if (*s ==  "min")
	set_opt_min (true);
      else if (*s ==  "mul")
	set_opt_mul (true);
      else if (*s ==  "sat")
	set_opt_sat (true);
      else if (*s == "!abs")
	set_opt_abs (false);
      else if (*s ==  "!ave")
	set_opt_ave (false);
      else if (*s ==  "!bit")
	set_opt_bit (false);
      else if (*s ==  "!clp")
	set_opt_clp (false);
      else if (*s ==  "!div")
	set_opt_div (false);
      else if (*s ==  "!ldz")
	set_opt_ldz (false);
      else if (*s ==  "!min")
	set_opt_min (false);
      else if (*s ==  "!mul")
	set_opt_mul (false);
      else if (*s ==  "!sat")
	set_opt_sat (false);
      else 
	cerr << "warning: unknown instruction sub-option to --insn: " << *s << endl;
    }

  // Set the hwe-option attribute of the cpu
  if (this->hw_engines)
    cpu->set (cpu, "hwe-option?", "true");

  // Process the --dsp-user-out or --no-dsp-user-out option
  assert (cpu);
  set (cpu, "dsp-user-out-option?", sidutil::make_attribute (dsp_user_out));
  for (vector <MepToshapiHWengineCfg *>::iterator d = toshapi_dsps.begin ();
       d != toshapi_dsps.end (); ++d)
    Setting (*d, "user-out?", sidutil::make_attribute (dsp_user_out)).write_to (w);

  // Complete the configuration of these components
  configure_timer ();
  configure_dmac ();
  if (dcache)
    configure_dcache ();
  if (icache)
    configure_icache ();

  // Force the cpu's insn-count to 1 if necessary.
  if (insn_count_1_required ())
    {
      cpu->set (cpu, "step-insn-count-1-required?", "true");
      if (step_insn_count != "1")
	set_step_insn_count ("1");
    }

  // Complete the lmem interface configuration of the hardware engines
  for (map<string, MepHWengineCfg*>::iterator h = hwe.begin();
       h != hwe.end (); ++h)
    h->second->configure_lmem ();

  // Map the local memory
  int i = 0;
  for (vector <MepMemRegionCfg *>::iterator m = local_mems.begin ();
       m != local_mems.end (); ++m, ++i)
    map_local_mem (*m);

  // Configure the warnings for writing to main memory regions
  for (vector <MepMemRegionCfg *>::const_iterator i = shared_main_mem->mems.begin ();
       i != shared_main_mem->mems.end (); ++i)
    {
      if (! (*i)->valid ())
	continue;
      if (warn_write_to_rom)
	set (*i, "warn-rom-write-option?", "true");
      else
	set (*i, "warn-rom-write-option?", "false");
      if (allow_write_to_rom)
	set (*i, "allow-rom-write-option?", "true");
      else
	set (*i, "allow-rom-write-option?", "false");
    }

  BoardCfg::write_config (w);

  // Configure irq settings, now that all boards are defined.
  // Must be done after the boards children have been written.
  configure_irqs (w);

  assert (main_mapper);
  if (dsu)
    {
      Setting (dsu, "core-type", sidutil::make_attribute (core_type)).write_to (w);

      // patch the memory hierarchy together, with the DSU in the middle
      if (icache)
	BusConnection (dsu, "insn-downstream", icache, "access-port").write_to (w);
      else
	BusConnection (dsu, "insn-downstream", main_mem_top, main_mem_bus).write_to (w);

      if (dcache)
	BusConnection (dsu, "data-downstream", dcache, "access-port").write_to (w);
      else
	BusConnection (dsu, "data-downstream", main_mem_top, main_mem_bus).write_to (w);
    }
  else
    {
      // if there is no DSU, we will need to wire up the CPU imem/dmem directly
      assert (cpu);
      if (icache)	
	BusConnection (insn_buffer, "downstream", icache, "access-port").write_to (w);
      else
	BusConnection (insn_buffer, "downstream", main_mem_top, main_mem_bus).write_to (w);

      if (dcache)
	BusConnection (cpu, "data-memory", dcache, "access-port").write_to (w);
      else
	BusConnection (cpu, "data-memory", main_mem_top, main_mem_bus).write_to (w);      
    }

  /* Connect the gloss target memory to the dcache, if present.  */
  assert (gloss);
  if (dcache)
    BusConnection (gloss, "target-memory", dcache, "access-port").write_to (w);
  else
    BusConnection (gloss, "target-memory", main_mem_top, main_mem_bus).write_to (w);

  // Connect the loader probe to main memory and connect the probe address pin
  if (main_mem_top != main_mapper)
    {
      BusConnection (main_mem_top, "probe-downstream", main_mapper, "access-port").write_to (w);
      PinConnection (main_mem_top, "write-to-code-address", cpu, "write-to-code-address").write_to (w);
    }

  sid::host_int_4 csr17 = ((core_id << 16) | (core_type << 8) | core_rev);

  sid::host_int_4 csr27 = ( 0x01000000 | // fixed bits
			   (imem_size << 16) | // IRSZ
			   (dmem_size << 0) | // DRSZ
			   (dmem_bank_num == 0 ?
			    (0x1 << 8) : // special case for DRBN
			    (((dmem_bank_num - 1) & 0x3) << 8))  | // DRBN
			   ((dmem_fixed_start_address ? 0xf :
			     (dmem_base[0] > 0x8000) ?  // if the base exceeds 16 bits, DRBA wraps
			       ((dmem_base[0] >> 16) & 0xf) :
			       ((dmem_base[0] >> 12) & 0xf)) << 12)) ; // DRBA

  sid::host_int_4 csr28 = 0;
  if (icache)
    {
      csr28 |= icache ? icache->size () << 16 : 0; // ICSZ
      if (core_type >= MEP_CORE_C3)
	{
	  csr28 |= (icache->get_way () - 1) << 28;
	  csr28 |= icache->get_cwf () << 27;
	  int line_size;
	  switch (icache->get_line_size ())
	    {
	    case 32:
	      line_size = 0x2;
	      break;
	    case 64:
	      line_size = 0x3;
	      break;
	    case 128:
	      line_size = 0x4;
	      break;
	    default:
	      line_size = 0;
	      break;
	    }
	  csr28 |= line_size << 24;
	}
    }
  if (dcache)
    {
      csr28 |= dcache ? dcache->size () << 0 : 0; // DCSZ
      if (core_type >= MEP_CORE_C3)
	{
	  csr28 |= (dcache->get_way () - 1) << 12;
	  csr28 |= dcache->get_cwf () << 11;
	  int line_size;
	  switch (dcache->get_line_size ())
	    {
	    case 32:
	      line_size = 0x2;
	      break;
	    case 64:
	      line_size = 0x3;
	      break;
	    case 128:
	      line_size = 0x4;
	      break;
	    default:
	      line_size = 0;
	      break;
	    }
	  csr28 |= line_size << 8;
	}
    }

  assert (cpu);
  Setting (cpu, "csr17", sidutil::make_attribute (csr17)).write_to (w);
  Setting (cpu, "csr27", sidutil::make_attribute (csr27)).write_to (w);
  Setting (cpu, "csr28", sidutil::make_attribute (csr28)).write_to (w);

  // If this board has an INTC, then setup the mm_int for this board
  // if it exists.
  if (intc && shared_mm_int)
    {
      // Connect the appropriate output pins of the MM_INT to the INTC for this
      // board.
      sid::host_int_4 channels = intc->get_channels ();
      string mm_int_output = "interrupt-" + sidutil::make_attribute (core_id) + "-";
      for (sid::host_int_4 i = 0; i < channels; ++i)
	PinConnection (shared_mm_int, mm_int_output + sidutil::make_attribute (i),
		       intc, "interrupt-source-" + sidutil::make_attribute (i)).write_to (w);
    }

  // Connect the config-result pin of the dynamic configurator to
  // the components of this board which need to know when the
  // configuration changes.
  if (dynamic_configurator)
    {
      shared_main_mem->set_dynamic_config (dynamic_configurator, w);

      // The instruction buffer is blockable, and thus, uses ulog.
      assert (insn_buffer);
      if (! insn_buffer->possibly_wrapped ())
	{
	  Relation (dynamic_configurator, "client", insn_buffer).write_to (w);
	}

      // The caches are blockable, and thus, uses ulog.
      if (icache)
	icache->set_dynamic_config (dynamic_configurator, w);
      if (dcache)
	dcache->set_dynamic_config (dynamic_configurator, w);

      // The DMAC is blockable, and thus, uses ulog.
      if (dmac && ! dmac->possibly_wrapped ())
	{
	  Relation (dynamic_configurator, "client", dmac).write_to (w);
	}

      // The GBIF uses ulog.
      if (gbif && ! gbif->possibly_wrapped ())
	{
	  Relation (dynamic_configurator, "client", gbif).write_to (w);
	}

      // The LBIF uses ulog.
      if (lbif && ! lbif->possibly_wrapped ())
	{
	  Relation (dynamic_configurator, "client", lbif).write_to (w);
	}

      // Toshapi hardware engines...
      for (map<string, MepHWengineCfg*>::iterator it = hwe.begin();
	   it != hwe.end (); ++it)
	{
	  MepToshapiHWengineCfg *h = dynamic_cast<MepToshapiHWengineCfg*>(it->second);
	  if (h && ! h->possibly_wrapped ())
	    {
	      Relation (dynamic_configurator, "client", h).write_to (w);
	    }
	}
      // Toshapi peripherals...done only once!!!
      static bool peripherals_done = false;
      if (! peripherals_done)
	{
	  for (map<string, AtomicCfg*>::iterator it = mep_peripherals.begin();
	       it != mep_peripherals.end();
	       it++)
	    {
	      AtomicCfg *p = it->second;
	      if (! p->possibly_wrapped ())
		{
		  Relation (dynamic_configurator, "client", p).write_to (w);
		}
	    }
	  peripherals_done = true;
	}
    }
}


void MepBoardCfg::need_intc ()
{
  if (intc)
    return;
  assert (ctrlmap);
  assert (cpu);
  intc = new MepINTCCfg ("intc", ctrlmap, cpu);
  assert (intc);
  add_child (intc);
}


void MepBoardCfg::intc_set (const string& name, const string& value)
{
  need_intc ();
  intc->set (intc, name, value);
}


void MepBoardCfg::add_timer (int channel_bitw)
{
  // Make sure the timer has been allocated
  if (channel_bitw && ! timer)
    allocate_timer (channel_bitw);

  if (! timer)
    return;

  timer->set_channels (channel_bitw);
}

void MepBoardCfg::allocate_timer (int channel_bitw)
{
  // Allocate the timer configuration.
  timer = new MepTimerCfg ("timer", channel_bitw);
  assert (timer);
  add_child (timer);

  // Add a subscription to the target scheduler.
  assert (sess);
  assert (sess->sim_sched);
  sess->sim_sched->add_subscription (timer, "burst-event", "burst-control");
}

void MepBoardCfg::configure_timer ()
{
  int timer_channel_bitw = timer ? timer->get_channels () : 0;

  // No timer?
  if (timer_channel_bitw == 0)
    return;
  assert (timer);

  // Set the number of configured channels.
  set (timer, "num-channels", sidutil::make_attribute (timer_channel_bitw));

  // Map the control registers
  Mapping m = Mapping().wordsz(0x4).slave(timer).bus("control-regs");
  for (int i = 0; i < timer_channel_bitw; ++i)
    {
      // Control regs for channel n are mapped from 0x04n0-0x04n5.
      int base = 0x0400 + (i << 4);
      ctrlmap->map (m.low(base).high(base + 0x5)
		     .bus("control-regs-" + sidutil::make_attribute (i)));
    }

  // Configure the cpu with the number of timer channels
  assert (cpu);
  cpu->set (cpu, "num-timer-channels", sidutil::make_attribute (timer_channel_bitw));

  // Connect the timer's nmi pin to the cpu
  conn_pin (timer, "nmi", cpu, "nmi");

  // If this board has an INTC, then setup the interrupt pins.
  if (intc)
    timer->setup_interrupt_pins (intc);
}

void MepBoardCfg::need_dsu ()
{
  if (dsu)
    return;
  assert (ctrlmap);
  dsu = new MepDSUCfg ("dsu", ctrlmap, core_type);
  assert (dsu);
  assert (cpu);
  assert (insn_buffer);
  cpu->set_dmem (dsu, "data-upstream");
  insn_buffer->set_downstream (dsu, "insn-upstream");
  add_child (dsu);  
}


void MepBoardCfg::allocate_dmac ()
{
  assert (! dmac);
  dmac = new AtomicCfg ("dmac", "libmepfamily.la",
			"mepfamily_component_library", "hw-dma-mep");
  assert (dmac);
  add_child (dmac);

  // Add a subscription to the target scheduler.
  assert (sess);
  assert (sess->sim_sched);
  sess->sim_sched->add_subscription (dmac, "burst-event", "burst-control");
}

void MepBoardCfg::add_dmac (int channel_bitw, int data_width, bool rectangle)
{
  allocate_dmac ();

  dmac_channel_bitw = channel_bitw;
  if (data_width == 64)
    dmac_data_width = 0x50;
  else
    dmac_data_width = 0;

  if (rectangle)
    dmac_rectangle = 0x4;
  else
    dmac_rectangle = 0;
}

void MepBoardCfg::configure_dmac ()
{
  // Check whether a dmac is to be configured
  if (! dmac_channel_bitw)
    return; // no dmac

  assert (dmac);

  // Width of the dmac must match that of the biu
  if (biu_width == 64)
    dmac_data_width = 0x50;
  else
    dmac_data_width = 0;

  // Set the dmac's DCR register to reflect this configuration.
  // See the Mep DMAC External Specification.
  sid::host_int_4 dcr = (dmac_channel_bitw << 8) & 0xf00;
  dcr = dcr | dmac_data_width;
  dcr = dcr | dmac_rectangle;
  set (dmac, "dcr", sidutil::make_attribute (dcr));

  // Connect main and local memory busses.
  if (gbif)
    {
      assert (lbif);
      conn_bus (dmac, "local-memory", lbif, "dmac-interface");
      conn_bus (dmac, "main-memory", gbif, "dmac-interface");
    }
  else
    {
      conn_bus (dmac, "local-memory", local_mapper, "access-port");
      conn_bus (dmac, "main-memory", main_mapper, "access-port");
    }

  // Map the control registers
  Mapping m = Mapping().wordsz(0x4).slave(dmac);
  ctrlmap->map (m.low(0x1100).high(0x1100).bus("main-control-regs"));
  for (int i = 0; i < dmac_channel_bitw; ++i)
    {
      // Control regs for channel n are mapped from 0x10n0-0x10na.
      int base = 0x1000 + (i << 4);
      ctrlmap->map (m.low(base).high(base + 0xa)
		     .bus("channel-control-regs-"
			  + sidutil::make_attribute (i)));
    }

  // If this board has an INTC, then setup the interrupt pins.
  if (intc)
    {
      // The DMAC interrupt pins are connected to the INTC in sequence
      // after any timer pins.
      // The INTC only has limited channels
      sid::host_int_4 intc_channels = intc->get_channels ();
      int timer_channel_bitw = timer ? timer->get_channels () : 0;
      if (timer_channel_bitw < intc_channels)
	{
	  conn_pin (dmac, "bus-error",
		    intc, "interrupt-source-" + sidutil::make_attribute (timer_channel_bitw));

	  string dmac_output = "interrupt-";
	  for (sid::host_int_4 i = 0; i < dmac_channel_bitw; ++i)
	    {
	      if (timer_channel_bitw + 1 + i >= intc_channels)
		break;
	      conn_pin (dmac, dmac_output + sidutil::make_attribute (i),
			intc, "interrupt-source-" + sidutil::make_attribute (timer_channel_bitw + 1 + i));
	    }
	}
    }

  // Allow the DMAC to terminate the simulation, if necessary
  conn_pin (dmac, "error", sess->main_obj, "stop!");
  conn_pin (dmac, "error", sess->yield_net, "input");
}

void MepBoardCfg::add_exit_location ()
{
  AtomicCfg *exit_watchdog = new AtomicCfg ("exit-watchdog", 
					    "libglue.la", 
					    "glue_component_library", 
					    "hw-glue-probe-bus");
  assert (exit_watchdog);
  add_child (exit_watchdog);
  const string pin_name ("address");

  if (gdb)
    exit_watchdog->conn_pin (exit_watchdog, pin_name, gdb, "gloss-process-signal");
  else
    {
      exit_watchdog->conn_pin (exit_watchdog, pin_name, sess->main_obj, "stop!");
      exit_watchdog->conn_pin (exit_watchdog, pin_name, sess->yield_net, "input");
    }

  Mapping exit_map = Mapping().wordsz(0x4).slave(exit_watchdog).bus("upstream");
  ctrlmap->map (exit_map.low(0xfd30).high(0xfd30));

  // Give the watchdog some memory, so that it doesn't return sid::status:unmapped
  // when accessed.
  MemCfg *mem = new MemCfg ("exit-watchdog-memory",  4);
  assert (mem);
  add_child (mem);
  exit_watchdog->conn_bus (exit_watchdog, "downstream", mem, "read-write-port");
}

void MepBoardCfg::set_intc_channel_bitw (sid::host_int_4 v)
{
  if (v != 0)
    {
      need_intc ();
      assert (intc);
    }
  if (intc)
    intc->set_channels (v);
}

void MepBoardCfg::set_intc_level (sid::host_int_4 v)
{
  if (v != 0)
    {
      need_intc ();
      assert (intc);
    }
  if (intc)
    intc->set_level (v);
}


void MepBoardCfg::set_opt_cp (bool b)
{
  assert (cpu);
  cpu->set (cpu, "cp-option?", b ? "true" : "false");
}


void MepBoardCfg::set_opt_dsu (bool b)
{
  assert (cpu);
  cpu->set (cpu, "debug-option?", b ? "true" : "false");
  if (b)
    need_dsu ();
}

void MepBoardCfg::set_opt_dsp (bool b)
{
  assert (cpu);
  cpu->set (cpu, "dsp-option?", b ? "true" : "false");
}

void MepBoardCfg::set_opt_uci (bool b)
{
  assert (cpu);
  cpu->set (cpu, "uci-option?", b ? "true" : "false");
}

void MepBoardCfg::set_opt_biu (unsigned data_width)
{
  assert (cpu);
  biu_width = data_width;
  cpu->set (cpu, "data-bus-width", sidutil::make_attribute (data_width));
}

void MepBoardCfg::add_cop (const string name, int cbus_if)
{
  static int i = 0;
  int cbus_size = 0x1000; // toshiba-supplied constant
  int cbus_addr = 0xe000; // toshiba-supplied constant

  set_opt_cp (true);

  // Add the control bus interface, if specified.
  if (cbus_if)
    {
      // Add access via the control bus at address 0xe000 (Toshiba-supplied
      // constant).
      MemCfg *mem = new MemCfg ("cop-" + name + "-ctrl-mem-" + sidutil::make_attribute (i++),
				cbus_size * 4);
      assert (mem);
      add_child (mem);

      assert (ctrlmap);
      Mapping m = Mapping().wordsz(4).slave(mem);
      ctrlmap->map (m.low(cbus_addr).high(cbus_addr + cbus_size - 1)
		     .bus("read-write-port"));
    }
}

void MepBoardCfg::set_cop_vliw_bitw (sid::host_int_4 v)
{
  assert ((v == 32) || (v == 64));
  assert (cpu);
  cpu->set (cpu, "vliw32-option?", v == 32 ? "true" : "false");
  cpu->set (cpu, "vliw64-option?", v == 64 ? "true" : "false");
}

void MepBoardCfg::set_cop_data_bus_width (sid::host_int_4 v)
{
  assert ((v == 32) || (v == 64));
  assert (cpu);
  cpu->set (cpu, "cop-data-bus-width", v == 32 ? "32" : "64");
}

void MepBoardCfg::set_cop_ccr (unsigned regno, sid::host_int_4 v)
{
  assert (cpu);
  cpu->set (cpu, "ccr" + sidutil::make_attribute (regno), sidutil::make_attribute (v));
}

void MepBoardCfg::set_opt_abs (bool b)
{
  assert (cpu);
  cpu->set (cpu, "abs-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_ave (bool b)
{
  assert (cpu);
  cpu->set (cpu, "ave-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_bit (bool b)
{
  assert (cpu);
  cpu->set (cpu, "bit-option?", b ? "true" : "false");  
  opt_bit_p = b;
}

void MepBoardCfg::set_opt_clp (bool b)
{
  assert (cpu);
  cpu->set (cpu, "clip-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_div (bool b)
{
  assert (cpu);
  cpu->set (cpu, "div-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_ldz (bool b)
{
  assert (cpu);
  cpu->set (cpu, "ldz-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_min (bool b)
{
  assert (cpu);
  cpu->set (cpu, "minmax-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_mul (bool b)
{
  assert (cpu);
  cpu->set (cpu, "mul-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_opt_sat (bool b)
{
  assert (cpu);
  cpu->set (cpu, "sat-option?", b ? "true" : "false");  
}

void MepBoardCfg::set_warn_write_to_code (bool b)
{
  assert (cpu);
  cpu->set (cpu, "warn-write-to-code-option?", b ? "true" : "false");  
  warn_write_to_code = b; 
}

void MepBoardCfg::set_opt_insn (string s)
{
  string *vs;
  vs = new string (s);
  insns.push_back (*vs);
}

void MepBoardCfg::set_opt_no_insn (string s)
{
  string *vs;
  string opt_no = "!";
  vs = new string (s);
  *vs = opt_no + s;
  insns.push_back (*vs);
}

void MepBoardCfg::set_opt_imem_size (string s)
{
  host_int_4 size;
  component::status stat = parse_attribute(s, size);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --imem-size: " << s << endl;
      return;
    }
  set_imem_size (size);
}

void MepBoardCfg::set_opt_local_mem (string s)
{
  vector<string> toks = sidutil::tokenize (s, ",");
  if (toks.size () < 3 || toks.size () > 4)
    {
      cerr << "Incorrect argument for --local-mem: " << s << endl;
      return;
    }
  host_int_4 start, len;
  component::status stat = parse_attribute(toks[0], start);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --local-mem: " << s << endl;
      return;
    }
  stat = parse_attribute(toks[1], len);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --local-mem: " << s << endl;
      return;
    }
  bool toshapi = false;
  if (toks.size () == 4)
    {
      if (toks[3] != "api")
	{
	  cerr << "Incorrect argument for --local-mem: " << s << endl;
	  return;
	}
      toshapi = true;
    }

  // Invalidate existing local memory when called for the first time.
  static bool called = false;
  if (! called)
    {
      called = true;
      for (vector <MepMemRegionCfg *>::const_iterator i = local_mems.begin();
	   i != local_mems.end (); ++i)
	(*i)->invalidate ();
    }

  // Now see if a memory region with this name already exists. If so,
  // modify it.
  MepMemRegionCfg *lmem = 0;
  for (vector <MepMemRegionCfg *>::const_iterator i = local_mems.begin();
       i != local_mems.end (); ++i)
    {
      if ((*i)->get_name () == get_name () + "/" + toks[2])
	{
	  (*i)->set_start (start);
	  (*i)->set_size (len);
	  (*i)->validate ();
	  lmem = *i;
	  break;
	}
    }

  // If no existing mem found, allocate a new one.
  if (! lmem)
    {
      add_local_mem (start, len, toks[2].c_str (), toshapi);
      return;
    }

  // Add toshapi component if specified and it does not already exist.
  if (toshapi && ! lmem->is_toshapi ())
    add_toshapi_local_mem (toks[2], lmem);
}

void MepBoardCfg::set_opt_global_mem (string s)
{
  static bool opt_global_mem_called = false;
  static int i = 0;

  vector<string> toks = sidutil::tokenize (s, ",");
  if (toks.size () < 2 || toks.size () > 4)
    {
      cerr << "Incorrect argument for --global-mem: " << s << endl;
      return;
    }
  host_int_4 start, len;
  component::status stat = parse_attribute(toks[0], start);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --global-mem: " << s << endl;
      return;
    }
  stat = parse_attribute(toks[1], len);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --global-mem: " << s << endl;
      return;
    }
  bool cached = false;
  bool rom = false;
  for (int ac = 2; ac < toks.size (); ++ac)
    {
      if (toks[ac] == "cached")
	cached = true;
      else if (toks[ac] == "rom")
	rom = true;
      else
	{
	  cerr << "Incorrect argument for --global-mem: " << s << endl;
	  return;
	}
    }

  // If this is the first time called, then invalidate all the
  // memory regions in the mems vector.
  static bool called = false;
  if (! called)
    {
      called = true;
      for (vector <MepMemRegionCfg *>::const_iterator i = shared_main_mem->mems.begin();
	   i != shared_main_mem->mems.end (); ++i)
	(*i)->invalidate ();
    }

  // Compute the name of the next global memory region
  string name = "shared-mem" + sidutil::make_attribute (i++);

  // Now see if a memory region with this name already exists. If so,
  // modify it.
  for (vector <MepMemRegionCfg *>::const_iterator i = shared_main_mem->mems.begin();
       i != shared_main_mem->mems.end (); ++i)
    {
      if ((*i)->get_name () == name)
	{
	  (*i)->set_start (start);
	  (*i)->set_size (len);
	  (*i)->set_cached (cached);
	  (*i)->set_readonly (rom);
	  (*i)->validate ();
	  return;
	}
    }

  // Not found, so allocate a new memory region.
  MepMemRegionCfg *m = new MepMemRegionCfg (name, start, len, 10, 1, cached, rom);
  assert (m);
  shared_main_mem->add_child (m);
  shared_main_mem->mems.push_back (m);
}

void MepBoardCfg::set_opt_shadow_mem (string s)
{
  static bool opt_shadow_mem_called = false;

  vector<string> toks = sidutil::tokenize (s, ",");
  if (toks.size () < 3 || toks.size () > 5)
    {
      cerr << "Incorrect argument for --shadow-mem: " << s << endl;
      return;
    }
  host_int_4 start, len, base;
  component::status stat = parse_attribute(toks[0], start);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --shadow-mem: " << s << endl;
      return;
    }
  stat = parse_attribute(toks[1], len);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --shadow-mem: " << s << endl;
      return;
    }
  stat = parse_attribute(toks[2], base);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --shadow-mem: " << s << endl;
      return;
    }
  int arg_ix = 3;
  bool cached = false;
  if (toks.size () > arg_ix && toks[arg_ix] == "cached")
    {
      cached = true;
      ++arg_ix;
    }
  const char *mod_name = NULL;
  if (toks.size () > arg_ix)
    {
      mod_name = toks[arg_ix].c_str ();
      ++arg_ix;
    }
  if (toks.size () > arg_ix)
    {
      cerr << "Incorrect argument for --shadow-mem: " << s << endl;
      return;
    }

  // Shadows specified on the command line completely replace
  // all shadows statically specified.
  if (! opt_shadow_mem_called)
    {
      opt_shadow_mem_called = true;
      shared_main_mem->shadows.erase (shared_main_mem->shadows.begin (), shared_main_mem->shadows.end ());
    }

  // Save this information for later mapping
  MepShadowRegion *r = new MepShadowRegion (start, len, base, cached, mod_name);
  assert (r);
  shared_main_mem->shadows.push_back (r);
}

void MepBoardCfg::set_opt_dmac_channel_bitw (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dmac-channel-bitw: " << s << endl;
      return;
    }
  dmac_channel_bitw = v;

  // Make sure the dmac has been allocated
  if (v && ! dmac)
    allocate_dmac ();
}

void MepBoardCfg::set_opt_timer_channel_bitw (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --timer-channel-bitw: " << s << endl;
      return;
    }
  add_timer (v);
}

void MepBoardCfg::set_opt_biu_width (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --biu-width: " << s << endl;
      return;
    }
  set_opt_biu (v);
}

void MepBoardCfg::set_opt_dmac_rectangle(bool b)
{
  if (b)
    dmac_rectangle = 0x4;
  else
    dmac_rectangle = 0x0;
}


void MepBoardCfg::set_opt_dmem_size (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dmem-size: " << s << endl;
      return;
    }
  set_dmem_size (v);
}

void MepBoardCfg::set_opt_dmem_bank_num (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dmem-bank-num: " << s << endl;
      return;
    }
  set_dmem_bank_num (v);
}

void MepBoardCfg::set_opt_dmem_fixed_start_address (bool b)
{
  set_dmem_fixed_start_address (b);
}

void MepBoardCfg::set_opt_icache_size (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --icache-size: " << s << endl;
      return;
    }
  set_icache_size (v);
}

void MepBoardCfg::set_opt_icache_line_size (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --icache-line-size: " << s << endl;
      return;
    }
  set_icache_line_size (v);
}

void MepBoardCfg::set_opt_icache_way (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --icache-way: " << s << endl;
      return;
    }
  set_icache_way (v);
}

void MepBoardCfg::set_opt_icache_cwf (string s)
{
  bool v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --icache-cwf: " << s << endl;
      return;
    }
  set_icache_cwf (v);
}

void MepBoardCfg::set_opt_dcache_size (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dcache-size: " << s << endl;
      return;
    }
  set_dcache_size (v);
}

void MepBoardCfg::set_opt_dcache_line_size (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dcache-line-size: " << s << endl;
      return;
    }
  set_dcache_line_size (v);
}

void MepBoardCfg::set_opt_dcache_way (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dcache-way: " << s << endl;
      return;
    }
  set_dcache_way (v);
}

void MepBoardCfg::set_opt_dcache_cwf (string s)
{
  bool v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --dcache-cwf: " << s << endl;
      return;
    }
  set_dcache_cwf (v);
}

void MepBoardCfg::set_opt_intc_channel_bitw (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --intc-channel-bitw: " << s << endl;
      return;
    }
  set_intc_channel_bitw (v);
}

void MepBoardCfg::set_opt_intc_level (string s)
{
  host_int_4 v;
  component::status stat = parse_attribute(s, v);
  if (stat != component::ok) 
    {
      cerr << "Incorrect argument for --intc-level: " << s << endl;
      return;
    }
  set_intc_level (v);
}

static map<string, MepBoardCfg*> mep_boards;

void MepBoardCfg::add_irq_board ()
{
  int found = 0;

  for (map<string, MepBoardCfg*>::iterator it = mep_boards.begin();
       it != mep_boards.end();
       it++)
    {
      if (this->get_name() == it->first)
	{
	  found = 1;
	  break;
	}
    }
  
  if (!found)
    mep_boards [this->get_name()] = this;
}

enum 
{irq_engine = 0, irq_dsp = 1, irq_peripheral = 2};

void MepBoardCfg::add_irq (int irq_type, 
			   const string src_mod, 
			   const string dest_mod,
			   const string instance,
			   const string signal, 
			   int engine_idx, 
			   int channel)
{
  MepIrq irq = { irq_type, src_mod, dest_mod, instance, signal, channel };
  irq_specs.push_back (irq);
}

void MepBoardCfg::configure_irqs (Writer &w)
{
  // Can only do this when the config for the last board is being
  // written.
  static unsigned times_called = 0;
  if (++times_called != shared_main_mem->num_boards ())
    return;

  for (vector<MepIrq>::const_iterator it = irq_specs.begin();
       it != irq_specs.end ();
       ++it)
    configure_irq (*it, w);
}

void MepBoardCfg::configure_irq (const MepIrq &irq, Writer &w)
{
  MepBoardCfg *src_mbc = NULL;
  MepBoardCfg *dest_mbc = NULL;
  MepHWengineCfg *this_hwe = NULL;
  static AtomicCfg *intc_for_periph = NULL;
  AtomicCfg *this_periph = NULL;
  int board_idx;
  int periph_idx;
  int found;

  for (board_idx = found = 0; !found && board_idx < 32; board_idx += 1)
    for (map<string, MepBoardCfg*>::iterator it = mep_boards.begin();
	 it != mep_boards.end();
	 it++)
      if (irq.src_mod + "-" + sidutil::make_attribute (board_idx) == it->first)
	{
	  found = 1;
	  src_mbc = it->second;
	  break;
	}

  if (! src_mbc)
    return; // nothing to configure

  for (board_idx = found = 0; !found && board_idx < 32; board_idx += 1)
    for (map<string, MepBoardCfg*>::iterator it = mep_boards.begin();
	 it != mep_boards.end();
	 it++)
      if (irq.dest_mod + "-" + sidutil::make_attribute (board_idx) == it->first)
	{
	  found = 1;
	  dest_mbc = it->second;
	  break;
	}

  switch (irq.irq_type)
    {
    case irq_engine:
    case irq_dsp:
      for (map<string, MepHWengineCfg*>::iterator it = src_mbc->hwe.begin();
	   it != src_mbc->hwe.end();
	   it++)
	if (irq.instance == it->first)
	  {
	    this_hwe = it->second;
	    break;
	  }
      assert (this_hwe);
      if (dest_mbc)
	{
	  PinConnection (this_hwe, "irq-" + irq.signal,
			 dest_mbc->intc, "interrupt-source-" + sidutil::make_attribute (irq.channel)).write_to (w);
	}
      Setting (this_hwe, "irq-name-" + sidutil::make_attribute (irq.channel), irq.signal).write_to (w);
      break;
    case irq_peripheral:
      for (map<string, AtomicCfg*>::iterator it = mep_peripherals.begin();
	   it != mep_peripherals.end();
	   it++)
	if (irq.instance == it->first)
	  {
	    this_periph = it->second;
	    break;
	  }
      assert (this_periph);

      if (intc_for_periph != this_periph)
	{
	  Relation (this_periph, "intc", this->intc).write_to (w);
	  intc_for_periph = this_periph;
	}

      if (dest_mbc)
	{
	  PinConnection (this_periph, "irq-" + irq.signal,
			 dest_mbc->intc, "interrupt-source-" + sidutil::make_attribute (irq.channel)).write_to (w);
	}
      Setting (this_periph, "irq-name-" + sidutil::make_attribute (irq.channel), irq.signal).write_to (w);
      break;
    }
}

bool MepBoardCfg::insn_count_1_required () const
{
  return step_insn_count_1_required_p
    || shared_main_mem->insn_count_1_required ()
    || timer && timer->get_channels () != 0
    || dmac && dmac_channel_bitw != 0;
}
