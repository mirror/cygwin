// toshapi.cxx - Wrappers for Toshiba's sim_api
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2002-2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef TOSHAPI_H
#define TOSHAPI_H

#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidbusutil.h>
#include <sidpinutil.h>
#include <sidattrutil.h>

#include <map>

#include "mep-gbif.h"
#include "mep-lbif.h"
#include "mep-gbmif.h"

namespace toshapi {
#if 0
}
#endif


using namespace sid;
using namespace sidutil;
using namespace std;


class Memory;
class MemoryMap;
class Intc;
class Dmac;
class PicardDmac;
class SimController;

// toshapi lightweight types
typedef unsigned char u8;
typedef unsigned short u16;
typedef host_int_4 u32;
typedef signed_host_int_4 s32;
typedef unsigned long long u64;
typedef unsigned int uint;
typedef host_int_4 address;


class toshapi_component: public virtual component,
			 protected virtual fixed_attribute_map_with_logging_component,
			 protected fixed_bus_map_component,
			 protected fixed_accessor_map_component,
			 protected virtual configurable_component
			 // NB: relationship API hand-coded
{
protected:
  toshapi_component (const char* name);
  ~toshapi_component () /* throw () */;

  // relationship api
  virtual vector<string> relationship_names () throw ();
  virtual component::status relate (const string& nm, component* comp) throw ();
  virtual component::status unrelate (const string& nm, component* comp) throw ();
  virtual vector<component*> related_components (const string& rel) throw ();

private:
  callback_word_bus<toshapi_component,big_int_4> upstream_control_bus;
  bus::status upstream_cb_read (host_int_4 addr, big_int_4 mask, big_int_4& value);
  bus::status upstream_cb_write (host_int_4 addr, big_int_4 mask, big_int_4 value);

  callback_pin<toshapi_component> reset_pin, stepinst_pin;
  void reset_pin_handler (host_int_4);
  void stepinst_pin_handler (host_int_4);
  output_pin end_pin;
  
protected:
  Intc *intc;
  PicardDmac *dmac;
  SimController *controller;
  MemoryMap *memmap;
  const char* const name;
  bool verbose_p;
  map<string, Memory*> downstream_memory;

  virtual void reset (bool sig) {}
  virtual void stepInst (unsigned n) {}
  virtual bool addMem (Memory *mem, const char* name) { return false; }
  virtual void setupIntcChannel () { }
  virtual bool setDmacCh (const char* id, uint ch) { return false; }

  virtual void configure (const string &config);

public:
  sid::component::status
  pin_factory (const string& name);
  virtual bool readCntlBus (address addr, u32* data) { return false; }
  virtual bool writeCntlBus (address addr, u32 data) { return false; }
};


class Resource
{
  // Help me, I'm empty!
};


class EXoperand
{
public:
  u32 *arg1; // dsp/uci rn input
  u32 *arg2; // dsp/uci rm input
  u32 *arg3; // dsp/uci subcode input
  u32 *arg4; // dsp-exception?/uci complete opcode
  u32 *arg5; // dsp-cycles?
  u32 *arg6; // writeback?
  u32 *arg7; // dsp complete opcode
};

class EXoperation
{
public:
  virtual u32 doit (EXoperand *opr) = 0;
};


class Memory: public toshapi_component
{
public:
  Memory (const char *name = 0);
protected:
  Memory (component*);
  void setMemory (component *);

  virtual component::status relate (const string& nm, component* comp) throw ();

private:
  friend class toshapi_component;

  component* local_memory;
  bus* local_memory_bus;

public:
  address base_address ();
  sid::host_int_4 size ();
  virtual bool read8(address addr, u32 *data);
  virtual bool read8s(address addr, u32 *data);
  virtual bool read16(address addr, u32 *data);
  virtual bool read16s(address addr, u32 *data);
  virtual bool read32(address addr, u32 *data);
  virtual bool write8(address addr, u32 data);
  virtual bool write16(address addr, u32 data);
  virtual bool write32(address addr, u32 data);
  u32* getStorage();
};


class MemoryMap
{
public:
  MemoryMap () {}
  Memory *getMem (address addr, address *offset = NULL, u32 * size = NULL);
  vector <Memory *> memory_map;
};

class Intc
{
  friend class toshapi_component;
  Intc (component *);
  component* intc_component;
  string irq_names[32];

public:
  void interrupt (bool flag, uint channel);
  bool addChannel (const char* name, uint channel);
  bool lookupChannel (const char* name, uint* channel);
  map<string, output_pin*> plt;
};


class SimController
{
  friend class toshapi_component;
  SimController (output_pin& ep) : end_pin (ep) {}

  output_pin& end_pin;

public:
  void simEnd () { end_pin.drive (1); }
};

// ------------------------------------------------------------------------


class Dmac
{
protected:
  friend class toshapi_component;
  Dmac (component *);

  void find_ctrl_regs (uint ch);

  static const uint max_channels = 6;

  static const uint car_addr = (0 * 4);
  static const uint ccr_addr = (1 * 4);
  static const uint trc_addr = (5 * 4);

  component* dmac_component;
  bus* main_control_bus;
  bus* channel_control_bus[max_channels];
  output_pin hw_req_pin[max_channels];

public:
  virtual bool hweReq (bool req, uint ch);
};


class PicardDmac : public Dmac
{
protected:
  friend class toshapi_component;
  PicardDmac (component *c) : Dmac (c)
    {
      for (int i = 0; i < max_channels; ++i)
	trc[i] = 0;
    }

  big_int_4 trc[max_channels];

public:
  enum ChannelStat { CHST_IDLE, CHST_BUSY };

  virtual bool hweReq (bool req, uint ch);
  ChannelStat getChStat (uint ch);
};


// ------------------------------------------------------------------------


class PeripheralModule: public Memory
{
protected:
  PeripheralModule (const char* foo, uint sw = 0) :
    Memory (foo)
  {}

  virtual component::status relate (const string& nm, component* comp) throw ();

public:
  virtual bool readCntlBus (address addr, u32* data) { return read32 (addr * 4, data); }
  virtual bool writeCntlBus (address addr, u32 data) { return write32 (addr * 4, data); }
};


// ------------------------------------------------------------------------


class HWengine: public toshapi_component
{
protected:
  HWengine (const char* foo);

  // virtual void reset (bool sig) {}
  // virtual void stepInst (unsigned n) {}
  // virtual bool addMem (Memory *mem, const char* name) { return false; }
  // virtual bool readCntlBus (address addr, u32* data) { return false; }
  // virtual bool writeCntlBus (address addr, u32 data) { return false; }
  // XXX: DMA functions omitted
  // XXX: INTC functions omitted
 private:
  void handle_signal_map ();
  string signal_map;
};


// ------------------------------------------------------------------------


class DSP: public HWengine
{
private:
  input_pin ucidsp_arg1;
  input_pin ucidsp_arg2;
  callback_pin<DSP> ucidsp_arg3; // signalled last
  input_pin ucidsp_arg4;
  input_pin ucidsp_arg7;
  output_pin ucidsp_exception;
  output_pin ucidsp_cycles;
  output_pin ucidsp_result;

  void do_ucidsp_protocol (host_int_4);

  sidutil::output_pin dsp_out_pin;
  sidutil::logger *dsp_logger;

  bool user_out_p;

protected:
  DSP (const char* name, Resource *res);
  virtual u32 doit (EXoperand *) {}

  Memory *dmem0;
  Memory *dmem1;
  Memory *dmem2;
  Memory *dmem3;
  void DSP_P (const char *fmt, ...)
    {
      if (! user_out_p)
	return;
      va_list ap;
      va_start (ap, fmt);
      dsp_logger->log (0, fmt, ap);
      va_end (ap);
    }
  void DSP_P_DIS ()  
    {
      dsp_logger->delete_saved_messages ();
    }
  void DSP_P_FLUSH ()
    {
      dsp_logger->output_saved_messages ();
    }
};


// ------------------------------------------------------------------------


class PIuci: public DSP
{
  u32 doit (EXoperand *opr);
protected:
  PIuci (const char* name, Resource *res);
  EXoperation* eop;
  map<u32,string> subName;
};



// ------------------------------------------------------------------------


#if 0
namespace toshapi {
#endif
}


#endif
