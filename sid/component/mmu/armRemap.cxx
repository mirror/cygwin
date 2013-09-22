// armRemap.cxx - An implementation of the "remap and pause"
// controller from the ARM PID7T development board.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found at
// <http://www.arm.com/Documentation/UserMans/rps/#rp>.

#include "config.h"
#include "tconfig.h"
 
#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidmiscutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidtypes.h>
#include <sidwatchutil.h>

using std::map;
using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::pair;
using std::ios;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_4;
using sid::little_int_1;
using sid::little_int_2;
using sid::little_int_4;
using sid::little_int_8;
using sid::big_int_1;
using sid::big_int_2;
using sid::big_int_4;
using sid::big_int_8;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::attribute_coder_base;
using sidutil::attribute_coder_virtual_parameterized;
using sidutil::fixed_attribute_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_accessor_map_component;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::no_relation_component;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::word_bus;
using sidutil::self_watcher;
using sidutil::tokenize;

#include <map>
#include <vector>
#include <string>

#if SIDTARGET_ARM

class armRemapPause: public virtual component, 
		     protected fixed_attribute_map_component,
		     protected fixed_bus_map_component,
		     protected fixed_pin_map_component,
		     protected fixed_accessor_map_component,
		     protected no_relation_component
{
public:
  armRemapPause();
  ~armRemapPause () throw () {}

private:
  class map_bus: public bus
  {
  public:
    map_bus(armRemapPause* target) :target(target) {}

#define BUS_WRITE(type1, type2) \
    virtual bus::status write(type1 address, type2 data) throw () = 0;
#define BUS_READ(type1, type2) \
    virtual bus::status read(type1 address, type2& data) throw () = 0;
    
    BUS_WRITE(host_int_4, little_int_1);
    BUS_WRITE(host_int_4, little_int_2);
    BUS_WRITE(host_int_4, little_int_4);
    BUS_WRITE(host_int_4, little_int_8);
    BUS_WRITE(host_int_4, big_int_1);
    BUS_WRITE(host_int_4, big_int_2);
    BUS_WRITE(host_int_4, big_int_4);
    BUS_WRITE(host_int_4, big_int_8);

    BUS_READ(host_int_4, little_int_1);
    BUS_READ(host_int_4, little_int_2);
    BUS_READ(host_int_4, little_int_4);
    BUS_READ(host_int_4, little_int_8);
    BUS_READ(host_int_4, big_int_1);
    BUS_READ(host_int_4, big_int_2);
    BUS_READ(host_int_4, big_int_4);
    BUS_READ(host_int_4, big_int_8);

#undef BUS_WRITE
#undef BUS_READ

  protected:
    armRemapPause* target;
  };
    
  class reset_map_bus: public map_bus
  {
  public:
    reset_map_bus(armRemapPause* target): map_bus(target) {}

#define BUS_WRITE(type1, type2) \
    bus::status write(type1 address, type2 data) throw () { \
        if (! target->downstream_bus) return bus::unmapped; \
        type1 newAddress = translate(address); \
	return target->downstream_bus->write(newAddress, data);\
    }

#define BUS_READ(type1, type2) \
    bus::status read(type1 address, type2& data) throw () { \
        if (! target->downstream_bus) return bus::unmapped; \
        type1 newAddress = translate(address); \
        return target->downstream_bus->read(newAddress, data); \
    }
      
    BUS_WRITE(host_int_4, little_int_1);
    BUS_WRITE(host_int_4, little_int_2);
    BUS_WRITE(host_int_4, little_int_4);
    BUS_WRITE(host_int_4, little_int_8);
    BUS_WRITE(host_int_4, big_int_1);
    BUS_WRITE(host_int_4, big_int_2);
    BUS_WRITE(host_int_4, big_int_4);
    BUS_WRITE(host_int_4, big_int_8);

    BUS_READ(host_int_4, little_int_1);
    BUS_READ(host_int_4, little_int_2);
    BUS_READ(host_int_4, little_int_4);
    BUS_READ(host_int_4, little_int_8);
    BUS_READ(host_int_4, big_int_1);
    BUS_READ(host_int_4, big_int_2);
    BUS_READ(host_int_4, big_int_4);
    BUS_READ(host_int_4, big_int_8);

#undef BUS_WRITE
#undef BUS_READ
    
  private:
    host_int_4 translate(host_int_4 address)
      {
	if (target->translations.empty())
	  return address;

	armRemapPause::translation_t::iterator it =
	  target->translations.upper_bound(address);
	
	if (it == target->translations.begin())
	  return address;

	it--;
	assert(address >= it->first);
	return (address - it->first) + it->second;
      }
  }; 
  
  class normal_map_bus: public map_bus
  {
  public:
    normal_map_bus(armRemapPause* target): map_bus(target) {}

#define BUS_WRITE(type1,type2) \
    bus::status write(type1 address, type2 data) throw ( ) { \
        if (! target->downstream_bus) return bus::unmapped; \
	  return target->downstream_bus->write(address, data); }
  
#define BUS_READ(type1,type2) \
    bus::status read(type1 address, type2& data) throw ( ) { \
        if (! target->downstream_bus) return bus::unmapped; \
          return target->downstream_bus->read(address, data); }

    BUS_WRITE(host_int_4, little_int_1);
    BUS_WRITE(host_int_4, little_int_2);
    BUS_WRITE(host_int_4, little_int_4);
    BUS_WRITE(host_int_4, little_int_8);
    BUS_WRITE(host_int_4, big_int_1);
    BUS_WRITE(host_int_4, big_int_2);
    BUS_WRITE(host_int_4, big_int_4);
    BUS_WRITE(host_int_4, big_int_8);

    BUS_READ(host_int_4, little_int_1);
    BUS_READ(host_int_4, little_int_2);
    BUS_READ(host_int_4, little_int_4);
    BUS_READ(host_int_4, little_int_8);
    BUS_READ(host_int_4, big_int_1);
    BUS_READ(host_int_4, big_int_2);
    BUS_READ(host_int_4, big_int_4);
    BUS_READ(host_int_4, big_int_8);

#undef BUS_WRITE
#undef BUS_READ
  };


  class remap_bus: public bus
  {
  public:
    remap_bus(armRemapPause *target)
      :target(target), reset_map(target), normal_map(target),
       bus(&reset_map) {}

    // Based on the setting of the remapping_p variable, switch the
    // bus object used to do downstream memory transactions.
    void bus_update();

    // Unconditional switch to the normal map.
    void use_normal_map();

#define BUS_WRITE(type1, type2) \
    bus::status write(type1 address, type2 data) throw () \
      { return bus->write(address, data); }
    
#define BUS_READ(type1, type2) \
    bus::status read(type1 address, type2& data) throw () \
      { return bus->read(address, data); }

    BUS_WRITE(host_int_4, little_int_1);
    BUS_WRITE(host_int_4, little_int_2);
    BUS_WRITE(host_int_4, little_int_4);
    BUS_WRITE(host_int_4, little_int_8);
    BUS_WRITE(host_int_4, big_int_1);
    BUS_WRITE(host_int_4, big_int_2);
    BUS_WRITE(host_int_4, big_int_4);
    BUS_WRITE(host_int_4, big_int_8);

    BUS_READ(host_int_4, little_int_1);
    BUS_READ(host_int_4, little_int_2);
    BUS_READ(host_int_4, little_int_4);
    BUS_READ(host_int_4, little_int_8);
    BUS_READ(host_int_4, big_int_1);
    BUS_READ(host_int_4, big_int_2);
    BUS_READ(host_int_4, big_int_4);
    BUS_READ(host_int_4, big_int_8);

#undef BUS_WRITE
#undef BUS_READ

  protected:
    armRemapPause* target;

  private:
    reset_map_bus reset_map;
    normal_map_bus normal_map;
    map_bus* bus;
  };
  

  class bus_interface: public word_bus<little_int_4>
  {
  public:
    bus_interface(armRemapPause* target): target(target) {}

    bus::status word_write(host_int_4 addr,
			   little_int_4 mask,
			   little_int_4 data);

    bus::status word_read(host_int_4 addr,
			  little_int_4 mask,
			  little_int_4& data);

  private:
    armRemapPause* target;
  };

  friend class bus_interface;
  friend class remap_bus;
  friend class reset_map_bus;
  friend class normal_map_bus;

  bus* downstream_bus;
  remap_bus upstream_bus;

  void reset(host_int_4 value);
  host_int_4 resetStatus;

  // The controller's programmable registers.
  bus_interface registers;

  // Are we currently applying the translation map?
  bool remapping_p;

  typedef map<host_int_4, host_int_4> translation_t;
  typedef pair<host_int_4, host_int_4> addr_pair_t;
  typedef map<host_int_4, addr_pair_t> entry_t;

  // The translation map, containing entries of address ranges and
  // their corresponding relocations.
  translation_t translations;

  // An orthogonal map to keep necessary state about known
  // relocations.
  entry_t entries;

  host_int_1 num_relocations;
  string get_num_relocations();
  component::status set_num_relocations(const string& s);

  string get_start(host_int_4 entryNum);
  component::status set_start(host_int_4 entryNum, const string& s);
  
  string get_end(host_int_4 entryNum);
  component::status set_end(host_int_4 entryNum, const string& s);

  string get_reloc(host_int_4 entryNum);
  component::status set_reloc(host_int_4 entryNum, const string& s);

  callback_pin<armRemapPause> resetPin;
  friend class callback_pin<armRemapPause>;

  output_pin halt;

  // State save/restore support.
  string save_state();
  sid::component::status restore_state(const string& state);
  friend ostream& operator<< (ostream& op, const armRemapPause& obj);
  friend istream& operator>> (istream& ip, armRemapPause& obj);

  // Triggerpoint support.
  friend class self_watcher<armRemapPause>;
  self_watcher<armRemapPause> triggerpoint_manager;

  sid::component::status
  pin_factory(const string& name)
    {
      return this->triggerpoint_manager.create_virtual_pin(name);
    }

  void
  pin_junkyard(const string& name)
    {
      return this->triggerpoint_manager.destroy_virtual_pin(name);
    }
};


armRemapPause::armRemapPause()
  :upstream_bus(this), downstream_bus(0),
   resetStatus(0), registers(this), remapping_p(true), num_relocations(0),
   resetPin(this, & armRemapPause::reset),
   triggerpoint_manager(this)
{
  add_accessor("all", &downstream_bus);
  add_attribute_notify("remapping?", &remapping_p, &upstream_bus,
		       &armRemapPause::remap_bus::bus_update, 
		       "setting");
  add_attribute_virtual("num-relocations", this,
			&armRemapPause::set_num_relocations,
			&armRemapPause::get_num_relocations);
  add_attribute_virtual("state-snapshot", this,
			&armRemapPause::restore_state,
			&armRemapPause::save_state);
  add_bus("access-port", &upstream_bus);
  add_bus("registers", &registers);
  add_pin("reset", &resetPin);
  add_pin("halt!", &halt);

  triggerpoint_manager.add_watchable_attribute("remapping?");
  categorize("remapping?", "watchable");
}

string
armRemapPause::save_state()
{
  return make_attribute(*this);
}

sid::component::status
armRemapPause::restore_state(const string& state)
{
  return parse_attribute(state, *this);
}

ostream& operator<< (ostream& op, const armRemapPause& obj)
{
  op << "remapping " << obj.remapping_p
     << " num-relocs " << static_cast<unsigned int> (obj.num_relocations)
     << " relocs ";

  for (armRemapPause::entry_t::const_iterator ie = obj.entries.begin();
       ie != obj.entries.end();
       ie++)
    {
      op << make_attribute(ie->second.first) << ",";    // start address
      op << make_attribute(ie->second.second) << ",";   // end address
      
      host_int_4 start_addr = ie->second.first;
      armRemapPause::translation_t::const_iterator it = obj.translations.find(start_addr);
      assert(it != obj.translations.end());
      op << it->second << " ";                          // relocated address
    }
  return op;
}
  
istream& operator>> (istream& ip, armRemapPause& obj)
{
  string word;

  // Temporary versions of all state variables.
  // None of these are commited unless the entire state is known to be
  // good.
  bool temp_remapping_p;
  unsigned temp_num_relocs = 0;

  ip >> word;

  if (word != "remapping")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> temp_remapping_p;
  if (!ip.good())
    return ip;

  ip >> word;
  if (word != "num-relocs")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> temp_num_relocs;
  if (!ip.good())
    return ip;

  ip >> word;
  if (word != "relocs")
    {
      ip.setstate(ios::badbit);
      return ip;
    }

  armRemapPause::entry_t temp_entries;
  armRemapPause::translation_t temp_translations;

  unsigned i = 0;
  while (ip >> word)
    {
      vector<string> v = tokenize(word, ",");
      if (v.size() != 3) {
	ip.setstate(ios::badbit);
	return ip;
      }
      host_int_4 start_addr, end_addr, reloc_addr;
      if ((parse_attribute(v[0], start_addr) != component::ok) ||
	  (parse_attribute(v[1], end_addr) != component::ok) ||
	  (parse_attribute(v[2], reloc_addr) != component::ok))
	{
	  ip.setstate(ios::badbit);
	  return ip;
	}

      temp_entries[i].first = start_addr;
      temp_entries[i].second = end_addr;
      temp_translations[start_addr] = reloc_addr;

      i++;
    }

  if (i != temp_num_relocs)
    {
      ip.setstate(ios::badbit);
      return ip;
    }

  // If we got here, commit the new state--the data looks okay.
  obj.remapping_p = temp_remapping_p;
  obj.translations = temp_translations;
  obj.entries = temp_entries;
  obj.num_relocations = temp_num_relocs;

  return ip;
}

string
armRemapPause::get_start(host_int_4 entryNum)
{
  return make_attribute(entries[entryNum].first);
}


component::status
armRemapPause::set_start(host_int_4 entryNum, const string& s)
{
  host_int_4 newBase;

  component::status st = parse_attribute(s, newBase);
  if (st != component::ok)
    return st;

  entries[entryNum].first = newBase;

  // Translate from x => x in anticipation that the user never
  // provides the relocation address via the N-reloc-to attribute.
  // This allows us to safely make an necessary entry now, and we can
  // update it once the relocation address is provided.
  translations[newBase] = newBase;

  return component::ok;
}


string
armRemapPause::get_end(host_int_4 entryNum)
{
  return make_attribute(entries[entryNum].second);
}


component::status
armRemapPause::set_end(host_int_4 entryNum, const string& s)
{
  host_int_4 address;

  component::status st = parse_attribute(s, address);
  if (st != component::ok)
    return st;

  entries[entryNum].second = address;

  // Having an address for the end of a region allows us to make a new
  // entry in the translation map that will return to mapping x => x.
  // This mapping must take effect from end+1.
  address++;
  translations[address] = address;

  return component::ok;
}


string
armRemapPause::get_reloc(host_int_4 entryNum)
{
  return make_attribute(translations[entries[entryNum].first]);
}


component::status
armRemapPause::set_reloc(host_int_4 entryNum, const string& s)
{
  host_int_4 newReloc;

  component::status st = parse_attribute(s, newReloc);
  if (st != component::ok)
    return st;

  translations[entries[entryNum].first] = newReloc;
  return component::ok;
}


string
armRemapPause::get_num_relocations()
{
  return make_attribute(num_relocations);
}


component::status
armRemapPause::set_num_relocations(const string& s)
{
  if (num_relocations > 0)
    return component::bad_value;

  // NB: type should match that of armRemapPause::num_relocations
  host_int_1 new_num; 

  component::status st = parse_attribute(s, new_num);
  if (st == component::ok)
    {
      for (unsigned i = num_relocations; i < new_num; i++)
	{
	  // Create new attributes as necessary.
	  string prefix = make_attribute(i);
	  
	  attribute_coder_base* coder =
	    new attribute_coder_virtual_parameterized
	    <armRemapPause,host_int_4> (this,
					&armRemapPause::get_start,
					&armRemapPause::set_start,
					i);
	  add_attribute_coder(string(prefix + "-start"),
			      coder, "setting");
	  
	  coder =
	    new attribute_coder_virtual_parameterized
	    <armRemapPause,host_int_4> (this,
					&armRemapPause::get_reloc,
					&armRemapPause::set_reloc,
					i);
	  add_attribute_coder(prefix + "-reloc-to", coder, "setting");
	  
	  coder =
	    new attribute_coder_virtual_parameterized
	    <armRemapPause,host_int_4> (this,
					&armRemapPause::get_end,
					&armRemapPause::set_end,
					i);
	  add_attribute_coder(prefix + "-end", coder, "setting");
	}
      num_relocations = new_num;
    }
  return st;
}


void
armRemapPause::reset(host_int_4 value)
{
  if (value > 0)
    resetStatus |= 1;
}


void
armRemapPause::remap_bus::bus_update()
{
  bus = (target->remapping_p) ? 
    static_cast<map_bus*>(& reset_map) : 
    & normal_map;

  // Trigger checkpoint.
  target->triggerpoint_manager.check_and_dispatch();
}


void
armRemapPause::remap_bus::use_normal_map()
{
  target->remapping_p = false;
  bus = &normal_map;

  // Trigger checkpoint.
  target->triggerpoint_manager.check_and_dispatch();
}

bus::status
armRemapPause::bus_interface::word_write(host_int_4 addr,
					 little_int_4 mask,
					 little_int_4 le_data) 
{
  host_int_4 data = le_data;
  switch (addr)
    {
    case 0:
      // Pause.
      target->halt.drive(1);
      break;
    case 4:
      // Reserved.
      break;
    case 8:
      // Switch from reset map to normal map.
      target->upstream_bus.use_normal_map();
      break;
    case 12:
      // Reset status set.
      // Ignore for a minimal implementation.
      break;
    case 13:
      // Reset status clear.
      target->resetStatus &= ~data;
      break;
    }
  return bus::ok;
}

bus::status
armRemapPause::bus_interface::word_read(host_int_4 addr,
					little_int_4 mask,
					little_int_4& data)
{
  switch (addr) {
  case 0:
    // Reserved.
    break;
  case 4:
    // Identification; just ensure bit 0 is cleared to say that we
    // don't have any further identification to offer.
    data = 0;
    break;
  case 8:
    // Reserved.
    break;
  case 12:
    // Reset status.
    data = target->resetStatus;
    break;
  case 13:
    // Reserved.
    break;
  }
  return bus::ok;
}

#endif // SIDTARGET_ARM


static vector<string>
compMmuListTypes()
{
  vector<string> types;
#if SIDTARGET_ARM
  types.push_back("hw-remap/pause-arm/ref");
#endif
  return types;
}

static component*
compMmuCreate(const string& typeName)
{
#if SIDTARGET_ARM
  if (typeName == "hw-remap/pause-arm/ref")
    return new armRemapPause();
#endif
  return 0;
}

static void
compMmuDelete(component* c)
{
#if SIDTARGET_ARM
  delete dynamic_cast<armRemapPause*>(c);
#endif
}


DLLEXPORT extern const component_library mmu_component_library;

const component_library mmu_component_library =
{
  COMPONENT_LIBRARY_MAGIC,
  &compMmuListTypes,
  &compMmuCreate,
  &compMmuDelete
};
