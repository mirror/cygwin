// toshapi.cxx - Wrappers for Toshiba's sim_api
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2002-2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "sidmiscutil.h"
#include "toshapi.h"

namespace toshapi {
#if 0
}
#endif

using namespace std;
using sidutil::tokenize;

// ------------------------------------------------------------------------


toshapi_component::toshapi_component (const char* n):
  upstream_control_bus (this, 
			& toshapi_component::upstream_cb_read, 
			& toshapi_component::upstream_cb_write),
  reset_pin (this, & toshapi_component::reset_pin_handler),
  stepinst_pin (this, & toshapi_component::stepinst_pin_handler),
  name (n)
{
  // Override the default setting of the buffer-output attribute so that
  // log messages issued from toshapi_component constructors will be output.
  buffer_output = true;

  this->add_bus ("control-bus", & this->upstream_control_bus);
  this->add_attribute_ro_value ("name", this->name, "setting");
  this->add_pin ("reset", & this->reset_pin);
  this->add_pin ("step-insn", & this->stepinst_pin);
  this->add_pin ("end-sim", & this->end_pin);
  this->add_attribute ("verbose?", & this->verbose_p, "setting");

  this->intc = 0;
  this->dmac = 0;
  this->memmap = new MemoryMap ();
  this->controller = new SimController (end_pin);
  this->verbose_p = false;
}


toshapi_component::~toshapi_component () /* throw () */
{
  // delete any downstream memory objects
  for (map<string,Memory*>::iterator it = this->downstream_memory.begin();
       it != this->downstream_memory.end();
       it++)
    {
      Memory* m = it->second;
      delete m;
    }

  if (this->intc)
    delete this->intc;

  if (this->dmac)
    delete this->dmac;

  assert (this->controller);
  delete this->controller;
}


vector<string>
toshapi_component::relationship_names () throw ()
{
  vector <string> names;

  names.push_back ("intc");
  names.push_back ("dmac");

  // add any downstream memory names
  for (map<string,Memory*>::iterator it = this->downstream_memory.begin();
       it != this->downstream_memory.end();
       it++)
    names.push_back (it->first);

  return names;
}


component::status
toshapi_component::relate (const string& nm, component* comp) throw ()
{
  if (nm == "intc" && this->intc == 0)
    {
      string have_irq = comp->attribute_value ("have_irq");
      if (this->verbose_p)
	cerr << "toshapi component connecting to intc" << endl;
      this->intc = new Intc (comp);
      for (int i = 0; i < 32; ++i)
	this->add_attribute_notify ("irq-name-" + make_numeric_attribute (i), & this->intc->irq_names[i],
				    this, & toshapi_component::setupIntcChannel, "irq to channel mapping");
      if (have_irq == "no")
	this->setupIntcChannel ();
      return component::ok;
    }

  if (nm == "dmac" && this->dmac == 0)
    {
      if (this->verbose_p)
	cerr << "toshapi component connecting to dmac" << endl;
      this->dmac = new PicardDmac (comp);
      return component::ok;
    }

  map<string,Memory*>::iterator it = this->downstream_memory.find (nm);
  if (it == this->downstream_memory.end ())
    {
      // assume the given component is a local memory
      Memory* m = new Memory (comp);
      bool ok = this->addMem (m, nm.c_str ());

      if (this->verbose_p)
	cerr << "toshapi component connecting to memory " << nm
	     << (ok ? " ok" : " error") << endl;
      if (ok)
	{
	  // accept & record it
	  memmap->memory_map.push_back (m);
	  this->downstream_memory [nm] = m;
	  return component::ok;
	}
      else
	delete m;
    }

  return component::not_found;
}


component::status
toshapi_component::unrelate (const string& nm, component* comp) throw ()
{
  if (nm == "intc" && this->intc && this->intc->intc_component == comp)
    {
      delete this->intc;
      this->intc = 0;
      return component::ok;
    }

  if (nm == "dmac" && this->dmac && this->dmac->dmac_component == comp)
    {
      delete this->dmac;
      this->dmac = 0;
      return component::ok;
    }

  // assume the given component is a local memory
  map<string,Memory*>::iterator it = this->downstream_memory.find (nm);
  if (it != this->downstream_memory.end ())
    {
      Memory* m = it->second;
      if (m->local_memory == comp)
	{
	  delete m;
	  this->downstream_memory.erase (nm);
	  return component::ok;
	}
    }

  return component::not_found;
}


vector<component*>
toshapi_component::related_components (const string& rel) throw ()
{
  vector <component*> comps;

  if (rel == "intc" && this->intc != NULL)
    comps.push_back (this->intc->intc_component);
  else if (rel == "dmac" && this->dmac != NULL)
    comps.push_back (this->dmac->dmac_component);
  else
    {
      map<string,Memory*>::iterator it = this->downstream_memory.find (rel);
      if (it != this->downstream_memory.end ())
	{
	  Memory* m = it->second;
	  comps.push_back (m->local_memory);
	}
    }

  return comps;
}


void
toshapi_component::reset_pin_handler (host_int_4 value)
{
  if (this->verbose_p)
    cerr << "toshapi component reset" << endl;
  this->reset (value ? true : false);
}


void
toshapi_component::stepinst_pin_handler (host_int_4)
{
  if (this->verbose_p)
    cerr << "toshapi component step-insn" << endl;
  this->stepInst (1);
}


bus::status
toshapi_component::upstream_cb_read (host_int_4 addr, big_int_4 /* mask */,
				     big_int_4& value)
{
  u32 data;
  bool ok = this->readCntlBus ((address) addr, & data);
  if (this->verbose_p)
    cerr << "toshapi component cb read addr=" << addr 
	 << (ok ? " ok" : " error") << endl;
  value = data;
  return ok ? bus::ok : bus::unmapped;
}


bus::status
toshapi_component::upstream_cb_write (host_int_4 addr, big_int_4 /* mask */, 
				      big_int_4 value)
{
  u32 data = value;
  bool ok = this->writeCntlBus ((address) addr, data);
  if (this->verbose_p)
    cerr << "toshapi component cb write addr=" << addr 
	 << (ok ? " ok" : " error") << endl;
  return ok ? bus::ok : bus::unmapped;
}

sid::component::status
toshapi_component::pin_factory (const string& name)
{
  sidutil::output_pin *plt_pin;
  plt_pin = new sidutil::output_pin ();
  add_pin (name, plt_pin);
  this->intc->plt [name] = plt_pin;
  this->setupIntcChannel ();
  return ok;
}

void
toshapi_component::configure (const string &config)
{
  // Call up to the base class first
  fixed_attribute_map_with_logging_component::configure (config);

  // Now handle relevent configuration for us.
  if (config.size () <= 8)
    return;
  if (config.substr (0, 8) == "verbose=")
    {
      verbose_p = (config.substr (8) == "true");
      return;
    }
}


// ------------------------------------------------------------------------


Intc::Intc (component *c)
{
  this->intc_component = c;
  assert (c != 0);
}



void
Intc::interrupt (bool flag, uint channel)
{
  string pin_name;
  string have_irq = this->intc_component->attribute_value ("have_irq");
  if (have_irq == "yes")
    {
      if (! irq_names [channel].empty ())
	{
	  pin_name = "irq-" + irq_names [channel];
	  for (map<string, output_pin*>::iterator it = this->plt.begin();
	       it != this->plt.end();
	       it++)
	    if (it->first == pin_name)
	      {
		sidutil::output_pin *p = it->second;
		p->drive (flag ? 1 : 0);
		return;
	      }
	}
    }

  pin_name = "interrupt-source-" + make_numeric_attribute (channel);
  pin* p = this->intc_component->find_pin (pin_name);
  if (! p)
    cerr << "Intc: no pin named " << pin_name << endl;
  else
    p->driven (flag ? 1 : 0);
}


bool
Intc::addChannel (const char *name, uint channel)
{
  string attr_name = "interrupt-name-" + make_numeric_attribute (channel);
  component::status s = this->intc_component->set_attribute_value (attr_name, 
								   name);
  return (s == component::ok);
}


bool
Intc::lookupChannel (const char *name, uint* channel)
{
  string pin_name = "irq-" + string (name);
  string have_irq = this->intc_component->attribute_value ("have_irq");
  sidutil::output_pin *p = NULL;
  const char *p1, *p2;

  if (have_irq == "yes")
    {
      // Lookup the name in irq_names to get the channel.
      for (int i = 0; i < 32; ++i)
	if (irq_names [i] == name)
	  {
	    *channel = i;
	    break;
	  }
      
      /* setupIntcChannel may call us for a channel
	 pin_factory has not yet setup.  */
      return true; 
    }

  for (unsigned i=0; i<32; i++)
    {
      string attr_name = "interrupt-name-" + make_numeric_attribute (i);
      string attr_value = this->intc_component->attribute_value (attr_name);
      if (attr_value == name)
	{
	  *channel = i;
	  return true;
	}
    }
  return false;
}



// ------------------------------------------------------------------------


Memory::Memory (const char* name) :
  toshapi_component (name),
  local_memory (NULL),
  local_memory_bus (NULL)
{
}

Memory::Memory (component *c) :
  toshapi_component (0)
{
  setMemory (c);
}

void
Memory::setMemory (component *c)
{
  this->local_memory = c;
  this->local_memory_bus = c->find_bus ("read-write-port");
}

component::status
Memory::relate (const string& nm, component* comp) throw ()
{
  if (nm == "__memory")
    {
      if (this->verbose_p)
	cerr << "toshapi Memory connecting to __memory" << endl;
      this->setMemory (comp);
      return component::ok;
    }

  return toshapi_component::relate (nm, comp);
}

address
Memory::base_address ()
{
  assert (this->local_memory);
  string v = this->local_memory->attribute_value ("base-address");
  address mem_base;
  component::status s = parse_attribute (v, mem_base);
  assert (s == component::ok);
  return mem_base;
}

address
Memory::size ()
{
  assert (this->local_memory);
  string v = this->local_memory->attribute_value ("size");
  sid::host_int_4 mem_size;
  component::status s = parse_attribute (v, mem_size);
  assert (s == component::ok);
  return mem_size;
}

// XXX: This is an inherently unsafe API function.
u32*
Memory::getStorage ()
{
  host_int_4 mem_unsafe_buffer;

  assert (this->local_memory);
  string v = this->local_memory->attribute_value ("buffer-base-UNSAFE");
  component::status s = parse_attribute (v, mem_unsafe_buffer);
  assert (s == component::ok);

  return (u32*) (host_int_1*) mem_unsafe_buffer;
}


bool
Memory::read8 (address a, u32* data)
{
  big_int_1 d;
  if (this->local_memory_bus &&
      this->local_memory_bus->read (a, d) == component::ok)
    {
      *data = d;
      return true;
    }
  else
    return false;
}

bool
Memory::read8s (address a, u32* data)
{
  big_int_1 d;
  if (this->local_memory_bus &&
      this->local_memory_bus->read (a, d) == component::ok)
    {
      *data = (signed) (signed char) d;
      return true;
    }
  else
    return false;
}

bool
Memory::read16 (address a, u32* data)
{
  big_int_2 d;
  if (this->local_memory_bus &&
      this->local_memory_bus->read (a, d) == component::ok)
    {
      *data = d;
      return true;
    }
  else
    return false;
}

bool
Memory::read16s (address a, u32* data)
{
  big_int_2 d;
  if (this->local_memory_bus &&
      this->local_memory_bus->read (a, d) == component::ok)
    {
      *data = (signed) (signed short) d;
      return true;
    }
  else
    return false;
}

bool
Memory::read32 (address a, u32* data)
{
  big_int_4 d;
  if (this->local_memory_bus &&
      this->local_memory_bus->read (a, d) == component::ok)
    {
      *data = d;
      return true;
    }
  else
    return false;
}

bool
Memory::write8 (address a, u32 data)
{
  big_int_1 d = (host_int_1) data;
  if (this->local_memory_bus &&
      this->local_memory_bus->write (a, d) == component::ok)
    return true;
  else
    return false;
}

bool
Memory::write16 (address a, u32 data)
{
  big_int_2 d = (host_int_2) data;
  if (this->local_memory_bus &&
      this->local_memory_bus->write (a, d) == component::ok)
    return true;
  else
    return false;
}

bool
Memory::write32 (address a, u32 data)
{
  big_int_4 d = (host_int_4) data;
  if (this->local_memory_bus &&
      this->local_memory_bus->write (a, d) == component::ok)
    return true;
  else
    return false;
}

// ------------------------------------------------------------------------


Memory* 
MemoryMap::getMem (address p_addr, address* p_offset, u32* p_size)
{
  for (int i = 0; i < memory_map.size(); i++)
    {
      Memory* it = memory_map[i];
      if (p_addr >= it->base_address ()
	  && p_addr <= it->base_address () + it->size ())
	{
	  if (p_offset)
	    it->read32 (p_addr, p_offset);
	  if (p_size)
	    *p_size = it->size ();
	  return it;
	}
    }
  return NULL;
}


// ------------------------------------------------------------------------

HWengine::HWengine (const char* foo)
  : toshapi_component (foo)
{
  add_attribute_notify ("signal-map", & signal_map, this, & HWengine::handle_signal_map, "output signal mapping");
}


void
HWengine::handle_signal_map ()
{
  vector<string> fields = tokenize (signal_map, "=");
  assert (fields.size() >= 2);

  string channel = fields[fields.size () - 1];
  string signal = signal_map.substr (0, signal_map.length () - channel.length() - 1);
  uint ch;
  component::status s = parse_attribute (channel, ch);
  assert (s == component::ok);
  if (this->setDmacCh (signal.c_str (), ch))
    return;

  cerr << "Configuration error: setDmacCh (" << signal << ", " << ch << ") failed" << endl;
}

// ------------------------------------------------------------------------


component::status
PeripheralModule::relate (const string& nm, component* comp) throw ()
{
  if (nm != "__mapped_memory")
    return toshapi_component::relate (nm, comp);

  // assume the given component is the mapped memory for this peripheral
  setMemory (comp);
  return component::ok;
}

// ------------------------------------------------------------------------


DSP::DSP (const char* name, Resource * /* ignored argument */): 
  HWengine (name),
  ucidsp_arg3 (this, & DSP::do_ucidsp_protocol),
  dmem0 (0),
  dmem1 (0),
  dmem2 (0),
  dmem3 (0),
  user_out_p (false)
{
  add_pin ("ucidsp-arg1", & this->ucidsp_arg1);
  add_pin ("ucidsp-arg2", & this->ucidsp_arg2);
  add_pin ("ucidsp-arg3", & this->ucidsp_arg3);
  add_pin ("ucidsp-arg4", & this->ucidsp_arg4);
  add_pin ("ucidsp-arg7", & this->ucidsp_arg7);
  add_pin ("ucidsp-exception", & this->ucidsp_exception);
  add_pin ("ucidsp-cycles", & this->ucidsp_cycles);
  add_pin ("ucidsp-result", & this->ucidsp_result);
  add_pin ("dsp-log-out", & dsp_out_pin);

  add_attribute ("user-out?", & user_out_p, "setting");

  dsp_logger = new logger (& dsp_out_pin, true, 0,"equal");
}


void 
DSP::do_ucidsp_protocol (host_int_4 /* == arg3 */)
{
  host_int_4 arg1 = this->ucidsp_arg1.sense ();
  host_int_4 arg2 = this->ucidsp_arg2.sense ();
  host_int_4 arg3 = this->ucidsp_arg3.sense ();
  host_int_4 arg4 = this->ucidsp_arg4.sense ();
  host_int_4 arg5 = 1;
  host_int_4 arg6 = 1;
  host_int_4 arg7 = this->ucidsp_arg7.sense ();

  bool is_dsp = (arg4 == 0);

  EXoperand the_op;
  the_op.arg1 = & arg1;
  the_op.arg2 = & arg2;
  the_op.arg3 = & arg3;
  the_op.arg4 = & arg4;
  the_op.arg5 = & arg5;
  the_op.arg6 = & arg6;
  the_op.arg7 = & arg7;

  if (this->verbose_p)
    cerr << "toshapi component uci/dsp"
	 << " arg1=" << arg1
	 << " arg2=" << arg2
	 << " arg3=" << arg3
	 << " arg4=" << arg4
	 << " arg7=" << arg7;

  /* ignore rc of */ this->doit (& the_op);

  dsp_logger->output_saved_messages ();

  if (this->verbose_p)
    cerr << " -> arg1=" << arg1
	 << " arg4=" << arg4
         << " arg5=" << arg5
	 << " arg6=" << arg6
	 << endl;

  if (arg5)
    this->ucidsp_cycles.drive (arg5);
  if (is_dsp && arg4)
    this->ucidsp_exception.drive (arg4);
  else if (arg6)
    this->ucidsp_result.drive (arg1);
  else
    ; // no arg1 writeback 
}


PIuci::PIuci (const char* name, Resource *res):
  DSP (name, res)
{
}


u32
PIuci::doit (EXoperand *opr)
{
  assert (this->eop);
  return this->eop->doit (opr);
}

// ------------------------------------------------------------------------

Dmac::Dmac (component *c)
{
  this->dmac_component = c;
  assert (c != 0);

  // Locate the main control registers
  this->main_control_bus = c->find_bus ("main-control-regs");

  for (int i = 0; i < max_channels; ++i)
    channel_control_bus[i] = 0;
}

void
Dmac::find_ctrl_regs (uint ch)
{
  // Find out how many channels this dmac has.
  component *c = this->dmac_component;
  string v = c->attribute_value ("dcr");
  host_int_4 dcr;
  component::status s = parse_attribute (v, dcr);
  assert (s == component::ok);
  uint num_channels = (dcr >> 8) & 0xf;

  // Locate the channel control registers and hw-req pin
  assert (ch < max_channels);
  string name = "channel-control-regs-" + make_numeric_attribute (ch);
  this->channel_control_bus[ch] = c->find_bus (name);

  name = "hw-req-" + make_numeric_attribute (ch);
  sid::pin* hw_req = c->find_pin (name);
  if (hw_req)
    this->hw_req_pin[ch].connect (hw_req);
}


// Request one DMAC burst on the given channel.
bool Dmac::hweReq (bool req, uint ch)
{
  // Make sure the channel is valid
  assert (ch < max_channels);
  find_ctrl_regs (ch);
  if (! this->channel_control_bus[ch])
    return false;

  // Read the current ccr
  big_int_4 ccr;
  if (this->channel_control_bus[ch]->read (ccr_addr, ccr) != component::ok)
    return false;

  // Check HTRQ bit
  uint htrq_mask = 1 << 12;
  if (! (ccr & htrq_mask))
    return false;

  // Read the current car
  big_int_4 car;
  if (this->channel_control_bus[ch]->read (car_addr, car) != component::ok)
    return false;
  if (! car)
    return false;

  // Drive the hw_req pin
  this->hw_req_pin[ch].drive (1);

  // Success!
  return true;
}

bool PicardDmac::hweReq (bool req, uint ch)
{
  // Make sure the channel is valid
  assert (ch < max_channels);
  find_ctrl_regs (ch);
  if (! this->channel_control_bus[ch])
    return false;

  // Read the current trc and save
  if (this->channel_control_bus[ch]->read (trc_addr, this->trc[ch]) != component::ok)
    return false;

  // Call the base class
  if (! Dmac::hweReq (req, ch))
    {
      this->trc[ch] = 0;
      return false;
    }

  return true; // success
}

// Determine the status of the given DMAC channel
PicardDmac::ChannelStat PicardDmac::getChStat (uint ch)
{
  // Make sure the channel is valid
  assert (ch < max_channels);
  if (! this->channel_control_bus[ch])
    return CHST_IDLE;

  // Read the current car
  big_int_4 car;
  if (this->channel_control_bus[ch]->read (car_addr, car) != component::ok)
    return CHST_IDLE;
  if (! car)
    return CHST_IDLE;

  if (this->trc[ch] == 0)
    return CHST_IDLE;
  // Read the current trc and compare
  big_int_4 current_trc;
  if (this->channel_control_bus[ch]->read (trc_addr, current_trc) != component::ok)
    return CHST_IDLE;
  if (this->trc[ch] != current_trc)
    {
      this->trc[ch] = 0;
      return CHST_IDLE; // burst has been processed
    }

  return CHST_BUSY;
}

#if 0
namespace toshapi {
#endif
}

