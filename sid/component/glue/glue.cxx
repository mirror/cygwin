// glue.cxx - miscellaneous glue components.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidtypes.h>
#include <sidmiscutil.h>
#include <sidpinattrutil.h>
#include <sidwatchutil.h>

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cassert>
#include <cstdlib>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif


namespace glue_components
{
  using sid::host_int_8;
  using sid::host_int_4;
  using sid::host_int_2;
  using sid::host_int_1;
  using sid::big_int_8;
  using sid::big_int_4;
  using sid::big_int_2;
  using sid::big_int_1;
  using sid::little_int_8;
  using sid::little_int_4;
  using sid::little_int_2;
  using sid::little_int_1;
  using sid::component;
  using sid::bus;

  using sidutil::fixed_pin_map_component;
  using sidutil::fixed_attribute_map_component;
  using sidutil::fixed_accessor_map_component;
  using sidutil::fixed_bus_map_component;
  using sidutil::no_accessor_component;
  using sidutil::no_relation_component;
  using sidutil::no_bus_component;
  using sidutil::no_pin_component;
  using sidutil::output_pin;
  using sidutil::input_pin;
  using sidutil::callback_pin;
  using sidutil::make_attribute;
  using sidutil::make_numeric_attribute;
  using sidutil::parse_attribute;
  using sidutil::recursion_limited;
  using sidutil::recursion_record;
  using sidutil::self_watcher;
  using sidutil::mux_passthrough_bus;

  using std::map;
  using std::deque;
  using std::vector;
  using std::string;
  using std::ostream;
  using std::istream;
  using std::ios;
  using std::endl;
  using std::cout;

// ----------------------------------------------------------------------------

  // The sequence component distributes an input pin event to a fixed
  // sequence of output pins.  Output-to-input recursion is disallowed
  // and enforced by assertion.
  class sequence_component: public virtual component,
			    protected fixed_pin_map_component,
			    protected no_accessor_component,
			    protected fixed_attribute_map_component,
			    protected no_relation_component,
			    protected no_bus_component,
			    protected recursion_limited
  {
    host_int_1 num_clients;
    callback_pin<sequence_component> input;
    vector<output_pin*> outputs;
    
    friend class self_watcher<sequence_component>;
    self_watcher<sequence_component> triggerpoint_manager;

    void dispatch_h4(host_int_4 value)
      {
	recursion_record block (this);
	if (! block.ok())
	  return;

	for (vector<output_pin*>::iterator it = outputs.begin ();
	     it != outputs.end ();
	     it++)
	  {
	    output_pin* o = *it;
	    o->drive (value);
	  }

	this->triggerpoint_manager.check_and_dispatch();
      }

    void num_clients_changed();

    friend ostream& operator << (ostream& o, const sequence_component& it);
    friend istream& operator >> (istream& i, sequence_component& it);
    string save_state() { return make_attribute(*this); }
    component::status restore_state(const string& state) { return parse_attribute(state, *this); }

    // Virtual pin interfaces between self_watcher and fixed_pin_map_component
    sid::component::status 
    pin_factory(const string& name)
      {
	return this->triggerpoint_manager.create_virtual_pin (name);
      }

    void
    pin_junkyard(const string& name)
      {
	this->triggerpoint_manager.destroy_virtual_pin (name);
      }


  public:
    sequence_component(unsigned nc = 0);
  };


sequence_component::sequence_component(unsigned nc):
  recursion_limited ("pin signal sequencing"), 
  num_clients (nc), 
  input (this, & sequence_component::dispatch_h4),
  triggerpoint_manager (this)
{
  if (nc == 0)
    {
      // configurable number of outputs
      this->add_attribute_notify ("num-outputs", & this->num_clients,
				  this, & sequence_component::num_clients_changed,
				  "setting");
    }
  else
    {
      // non-configurable number of outputs
      this->add_attribute_ro ("num-outputs", & this->num_clients, "setting");
    }
  this->triggerpoint_manager.add_watchable_attribute ("num-outputs");
  this->categorize ("num-outputs", "watchable");
  
  this->add_pin ("input", & this->input);
  this->add_attribute ("input", & this->input, "pin");
  this->triggerpoint_manager.add_watchable_attribute ("input");
  this->categorize ("input", "watchable");
  
  this->add_attribute_virtual ("state-snapshot", this,
			       & sequence_component::save_state,
			       & sequence_component::restore_state);
  
  this->num_clients_changed (); // grow any initial output pins
}
  
  
  ostream& 
  operator << (ostream& o, const sequence_component& it)
{
  o << "sequence ";
  o << host_int_2(it.num_clients) << " ";
  o << it.input;
  for (unsigned j=0; j<it.num_clients; j++)
    o << " " << *it.outputs[j];
  // NB: no whitespace at end!
  return o;
}

  
  istream&
  operator >> (istream& i, sequence_component& it)
{
  string key;
  i >> key;
  if (key != "sequence")
    {
      i.setstate (ios::badbit);
      return i;
    }

  host_int_2 nc;
  i >> nc;
  it.num_clients = nc;
  it.num_clients_changed();

  i >> it.input;
  for (unsigned j=0; j<it.num_clients; j++)
    i >> *it.outputs[j];

  return i;
}



  void
  sequence_component::num_clients_changed()
{
  recursion_record block (this);
  if (! block.ok())
    return;

  host_int_1 prev_num_clients = this->outputs.size();
  if (prev_num_clients == this->num_clients)
    return;
  
  // zap unneeded pins
  for (unsigned i=this->num_clients; i < prev_num_clients; i++)
    {
      output_pin* p = this->outputs[i];
      string oname = string("output-") + make_numeric_attribute(i);
      this->remove_pin (oname);
      this->remove_attribute (oname);
      // was not watchable
      delete p;
    }
  
  this->outputs.resize (this->num_clients);
  
  // And now: a quote from <mkostash> on 1999-06-08:
  // "Dear Mary-Lynn, you are my favorite co-worker.
  // Tomorrow I will buy you lunch." 
  
  // add needed pins
  for (unsigned i=prev_num_clients; i < this->num_clients; i++)
    {
      output_pin* p = new output_pin();
      this->outputs[i] = p;
      string oname = string("output-") + make_numeric_attribute(i);
      this->add_pin (oname, p);
      this->add_attribute (oname, p, "pin");
      // not watchable
    }
  
  this->triggerpoint_manager.check_and_dispatch();
}
  

// ----------------------------------------------------------------------------

  // The attribute storage component stores any set of values,
  // indefinitely.
  class attr_storage_component: public virtual component,
				protected no_pin_component,
				protected no_accessor_component,
				protected no_relation_component,
				protected no_bus_component
  {
    typedef map<string,string> attribute_map_t;
    attribute_map_t attribute_map;

  public:
    attr_storage_component() {}
    ~attr_storage_component() {}

    vector<string>
    attribute_names() throw()
      {
	vector<string> names;
	for (attribute_map_t::const_iterator it = this->attribute_map.begin();
	     it != this->attribute_map.end();
	     it++)
	   {
	     names.push_back ((*it).first);
	   }
        return names;
      }

    vector<string>
    attribute_names (const string& category) throw()
      {
	   return vector<string>();
      }

    string
    attribute_value (const string& name) throw()
      {
	attribute_map_t::iterator it = this->attribute_map.find(name);
	if (it == this->attribute_map.end())
	  return "";
	else
	  return (*it).second;
      }

    component::status
    set_attribute_value (const string& name, const string& value) throw()
      {
	    this->attribute_map[name] = value;
	    return component::ok;
      }
  };


// ----------------------------------------------------------------------------

class bus_prober;
class probing_bus: public bus
{
  friend class bus_prober;

  bus_prober* prober;
  host_int_4 counter;
  bool verbose_p;

  template <typename DataType>
  bus::status writeAny(host_int_4 addr, DataType data, host_int_4 code) throw ();
  template <typename DataType>
  bus::status readAny(host_int_4 addr, DataType& data, host_int_4 code) throw ();

  template <typename DataType>
  void traceAccess(host_int_4 addr, DataType data, host_int_4 code, bus::status s) throw ();

#define PROBE(DataType,Code) \
  status write(host_int_4 addr, DataType data) throw () \
    { \
      return this->writeAny(addr, data, Code); \
    } \
  status read(host_int_4 addr, DataType& data) throw () \
    { \
      return this->readAny(addr, data, (Code | 0x100)); \
    }

  PROBE(big_int_1,    0x00)
  PROBE(little_int_1, 0x10)
  PROBE(big_int_2,    0x01)
  PROBE(little_int_2, 0x11)
  PROBE(big_int_4,    0x02)
  PROBE(little_int_4, 0x12)
  PROBE(big_int_8,    0x03)
  PROBE(little_int_8, 0x13)

public:

  probing_bus (bus_prober* p):
    prober (p),
    counter (0),
    verbose_p (false)
    {
      assert (this->prober);
    }
  ~probing_bus () {}
};


class bus_prober: public virtual component,
		  protected fixed_pin_map_component,
		  protected fixed_accessor_map_component,
		  protected fixed_attribute_map_component,
		  protected no_relation_component,
		  protected fixed_bus_map_component
{
  friend class probing_bus;

  probing_bus upstream;
  bus* downstream;

  output_pin address_pin;
  output_pin data_high_pin;
  output_pin data_low_pin;
  output_pin result_pin;
  output_pin accesstype_pin;

  host_int_4 sample_interval; // 0: disabled

public:
  bus_prober::bus_prober ():
    upstream (this),
    downstream (0)
    {
      sample_interval = 1;

      add_bus ("upstream", & this->upstream);
      add_accessor ("downstream", & this->downstream);
      
      add_pin ("address", & this->address_pin);
      add_attribute ("address", & this->address_pin, "pin");
      add_pin ("data-high", & this->data_high_pin);
      add_attribute ("data-high", & this->data_high_pin, "pin");
      add_pin ("data-low", & this->data_low_pin);
      add_attribute ("data-low", & this->data_low_pin, "pin");
      add_pin ("status", & this->result_pin);
      add_attribute ("status", & this->result_pin, "pin");
      add_pin ("type", & this->accesstype_pin);
      add_attribute ("type", & this->accesstype_pin, "pin");
      
      add_attribute ("sample-interval", & this->sample_interval, "setting");
      add_attribute ("trace?", & this->upstream.verbose_p, "setting");
      add_attribute_ro ("interval-counter", & this->upstream.counter, "register");

      // XXX: make watchable
    }
};




template <typename DataType>
void
probing_bus::traceAccess(host_int_4 addr, DataType data, host_int_4 code, bus::status s) throw ()
{
  string access_type1 = (code & 0x100) ? "read" : "write";
  string access_type2 = (code & 0x100) ? "->" : "<-";
  string access_endian = (code & 0x10) ? "le" : "be";
  unsigned access_size = 1 << (code & 0xF);
  string access_status = 
    (s == bus::ok) ? "" : // print nothing for "ok"
    (s == bus::misaligned) ? " misaligned!" :
    (s == bus::unmapped) ? " unmapped!" :
    (s == bus::unpermitted) ? " unpermitted!" :
    (s == bus::delayed) ? " delayed!" : " (unknown)!";
  
  cout << access_type1 << '-' << access_endian << '-' << access_size << ':'
       << make_numeric_attribute (addr, ios::hex | ios::showbase) << ' '
       << access_type2 << ' '
       << make_numeric_attribute (data, ios::hex | ios::showbase) // no trailing space here
       << access_status
       << endl;
}


template <typename DataType>
bus::status
probing_bus::writeAny(host_int_4 addr, DataType data, host_int_4 code) throw ()
{
  assert (this->prober);

  bus::status s = bus::unmapped;
  if (this->prober->downstream != 0)
    s = this->prober->downstream->write (addr, data);

  if (this->prober->sample_interval > 0)
    {
      this->counter ++;
      if (this->counter >= this->prober->sample_interval)
	{
	  if (this->verbose_p)
	    this->traceAccess (addr, data, code, s);

	  this->counter = 0;
	  // drive informational pins
	  this->prober->address_pin.drive (addr);
	  typename DataType::host_int_type d_host = data; // natural endianness
	  host_int_8 d_wide(d_host); // widen
	  this->prober->data_high_pin.drive ((d_wide >> 32) & 0xFFFFFFFF);
	  this->prober->data_low_pin.drive (d_wide & 0xFFFFFFFF);
	  //	  host_int_4 result = static_cast<unsigned>(s);
	  this->prober->result_pin.drive (s);
	  // and finally
	  this->prober->accesstype_pin.drive (code);
	}
    }

  return s;
}


template <typename DataType>
bus::status 
probing_bus::readAny(host_int_4 addr, DataType& data, host_int_4 code) throw ()
{
  assert (this->prober);

  bus::status s = bus::unmapped;
  if (this->prober->downstream != 0)
    s = this->prober->downstream->read (addr, data);

  if (this->prober->sample_interval > 0)
    {
      this->counter ++;
      if (this->counter >= this->prober->sample_interval)
	{
	  if (this->verbose_p)
	    this->traceAccess (addr, data, code, s);

	  this->counter = 0;
	  // drive informational pins
	  this->prober->address_pin.drive (addr);
	  typename DataType::host_int_type d_host = data; // natural endianness
	  host_int_8 d_wide(d_host); // widen
	  this->prober->data_high_pin.drive ((d_wide >> 32) & 0xFFFFFFFF);
	  this->prober->data_low_pin.drive (d_wide & 0xFFFFFFFF);
	  //	  host_int_4 result = static_cast<unsigned>(s);
	  this->prober->result_pin.drive (s);
	  // and finally
	  this->prober->accesstype_pin.drive (code);
	}
    }

  return s;
}

class bus_mux: public virtual component,
               protected fixed_pin_map_component,
               protected fixed_accessor_map_component,
               protected fixed_attribute_map_component,
               protected no_relation_component,
               protected fixed_bus_map_component

{
  mux_passthrough_bus upstream;
  bus* downstream1;
  bus* downstream2;

  callback_pin<bus_mux> switch_pin;

public:
  bus_mux ():
    switch_pin (this, &bus_mux::handle_switch_pin),
    upstream (&this->downstream1, &this->downstream2),
    downstream1 (0), downstream2 (0)
    {
      add_bus ("upstream", &this->upstream);
      add_accessor ("downstream1", &this->downstream1); 
      add_accessor ("downstream2", &this->downstream2);
      add_pin ("switch", &switch_pin);
      add_attribute ("switch", &switch_pin, "pin");
    }
  ~bus_mux () {}

  void handle_switch_pin (host_int_4 value)
    {
      upstream.select_bus (value);
    }
};

// ----------------------------------------------------------------------------

  static
  vector<string>
  list_types()
{
  vector<string> types;
  types.push_back("hw-glue-sequence");
  types.push_back("hw-glue-sequence-1");
  types.push_back("hw-glue-sequence-2");
  types.push_back("hw-glue-sequence-8");
  types.push_back("sw-glue-attribbank");
  types.push_back("hw-glue-probe-bus");
  types.push_back("hw-glue-bus-mux");
  return types;
}
  
  
  static
  component*
  create(const string& typeName)
{
  if (typeName == "hw-glue-sequence")
    return new sequence_component ();
  if (typeName == "hw-glue-sequence-1")
    return new sequence_component (1);
  if (typeName == "hw-glue-sequence-2")
    return new sequence_component (2);
  if (typeName == "hw-glue-sequence-8")
    return new sequence_component (8);
  if (typeName == "sw-glue-attribbank")
    return new attr_storage_component ();
  if (typeName == "hw-glue-probe-bus")
    return new bus_prober ();
  if (typeName == "hw-glue-bus-mux")
    return new bus_mux ();
  else
    return 0;
}


  static
  void
  do_delete(component* c)
{
  // Three of these dynamic_cast<>s will return 0.  It is safe to delete 0.
  sequence_component* g1 = dynamic_cast<sequence_component*>(c);
  if (g1) { delete g1; return; }
  attr_storage_component* g2 = dynamic_cast<attr_storage_component*>(c);
  if (g2) { delete g2; return; }
  bus_prober* g3 = dynamic_cast<bus_prober*>(c);
  if (g3) { delete g3; return; }
  bus_mux* g4 = dynamic_cast<bus_mux*>(c);
  if (g4) { delete g4; return; }
}

  
} // end namespace



// static object in root namespace
extern const sid::component_library glue_component_library;

const sid::component_library glue_component_library DLLEXPORT = 
{
  sid::COMPONENT_LIBRARY_MAGIC,
  & glue_components::list_types, 
  & glue_components::create,
  & glue_components::do_delete
};
