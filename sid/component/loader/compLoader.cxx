// compLoader.cxx - object file loader component.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidcpuutil.h>
#include <sidtypes.h>
#include <sidmiscutil.h>

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cerrno>
#include <unistd.h>
#include <fstream>

extern "C" {
#include "elfload.h"
}

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::endl;
using std::cout;
using std::ifstream;
using std::cerr;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::little_int_1;
using sid::host_int_4;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::no_bus_component;
using sidutil::fixed_attribute_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_accessor_map_component;
using sidutil::no_relation_component;
using sidutil::output_pin;
using sidutil::callback_pin;
using sidutil::string2stream;
using sidutil::stream2string;
using sidutil::make_attribute;
using sidutil::make_numeric_attribute;
using sidutil::parse_attribute;
using sidutil::std_error_string;

// ----------------------------------------------------------------------------

class generic_loader: public virtual component,
		      protected no_bus_component,
		      protected fixed_attribute_map_component,
		      protected fixed_pin_map_component,
		      protected fixed_accessor_map_component,
		      protected no_relation_component
{
private:
  callback_pin<generic_loader> doit_pin;

protected:
  // entry point address
  output_pin start_pc_pin;
  // endianness as specified in ELF header.
  // The value is one of sidutil::endian_*.
  output_pin endian_pin;

  // Signal this if something went wrong.
  output_pin error_pin;

  // loadable file names
  bool verbose_p;
  string load_file;

  // accessors
  bus* load_accessor_insn;
  bus* load_accessor_data;

  // The load pin was triggered.
  virtual void load_it (host_int_4) = 0;

  // state control
  friend ostream& operator << (ostream& o, const generic_loader& it);
  friend istream& operator >> (istream& i, generic_loader& it);
  string save_state() { return make_attribute(*this); }
  sid::component::status restore_state(const string& state)
    { return parse_attribute(state, *this); }

public:
  generic_loader(): 
    doit_pin(this, & generic_loader::load_it), 
    verbose_p(false),
    load_file("/dev/null"),
    load_accessor_insn(0),
    load_accessor_data(0)
    {
      add_pin("load!", & this->doit_pin);
      add_pin("start-pc-set", & this->start_pc_pin);
      add_pin("endian-set", & this->endian_pin);
      add_pin("error", & this->error_pin);
      add_accessor("load-accessor-insn", & this->load_accessor_insn);
      add_accessor("load-accessor-data", & this->load_accessor_data);
      add_attribute("file", & this->load_file, "setting");
      add_attribute("verbose?", & this->verbose_p, "setting");
      add_attribute_virtual ("state-snapshot", this,
			     & generic_loader::save_state,
			     & generic_loader::restore_state);
    }
    
};

ostream& 
operator << (ostream& out, const generic_loader& it)
{
  out << "loader-state "
      << string2stream(it.load_file) << " "
      << it.verbose_p;

  return out;
}


istream& 
operator >> (istream& in, generic_loader& it)
{
  string coding;
  in >> coding;
  if (coding == "loader-state")
    {
      in >> stream2string(it.load_file)
	 >> it.verbose_p;
    }
  else
    {
      in.setstate(ios::badbit);
    }

  return in;
}

// ----------------------------------------------------------------------------

class elf_loader: public generic_loader
{
  // static pointer to active instance (XXX: concurrency?)
  static elf_loader* freeloader;

  // callback function from C code in elfload.c
  static int load_function(host_int_8 dest_addr, char* host_addr, host_int_8 file_offset, host_int_8 bytes, int insn_space);
  static int verbose_function(char* s);

  // stream for current file  
  ifstream* file;

  void load_it (host_int_4)
    {
      if (this->load_accessor_insn == 0 || this->load_accessor_data == 0)
	{
	  cerr << "loader: error - target accessors not configured!" << endl;
	  this->error_pin.drive (0);
	  return;
	}

      if (this->verbose_p)
	{
	  cout << "loader: reading program " << this->load_file << endl;
	}

      assert(elf_loader::freeloader == 0);
      this->file = new ifstream(this->load_file.c_str(), ios::binary | ios::in);
      if (! this->file->good())
	{
	  cerr << "loader: error opening " << load_file << ": "
	       << std_error_string() << endl;
	  return;
	}

      elf_loader::freeloader = this;
      unsigned entry_point;
      int little_endian_p;
      int success_p = readElfFile(& elf_loader::load_function,
				  & entry_point, & little_endian_p);
      elf_loader::freeloader = 0;

      if (success_p)
	{
	  // Tell anyone who's listening things we learned about the elf file.
	  this->start_pc_pin.drive((host_int_4) entry_point);
	  if (little_endian_p)
	    this->endian_pin.drive(sidutil::endian_little);
	  else
	    this->endian_pin.drive(sidutil::endian_big);

	  if (this->verbose_p)
	    cout << "loader: starting "
		 << (little_endian_p ? "little-" : "big-") << "endian"
		 << " program at pc=" 
		 << make_numeric_attribute (entry_point, ios::hex | ios::showbase)
		 << endl;
	}
      else
	{
	  cerr << "loader: error loading " << load_file << endl;
	  this->error_pin.drive (0);
	}

      delete this->file;
      this->file = 0;
    }
};

// static variable
elf_loader* elf_loader::freeloader = 0;

// static function
int
elf_loader::load_function(host_int_8 dest_addr, char *host_addr, host_int_8 file_offset, host_int_8 bytes, int insn_space)
{
  elf_loader& l = * elf_loader::freeloader;
  string who = insn_space ? "instruction" : "data";

  if (l.verbose_p)
    {
      if (host_addr == 0)
	cout << "loader: reading "
	     << make_numeric_attribute (bytes, ios::hex | ios::showbase)
	     << " bytes from file offset "
	     << make_numeric_attribute (file_offset, ios::hex | ios::showbase)
	     << " into target " << who << " memory at "
	     << make_numeric_attribute ((void *)dest_addr, ios::hex | ios::showbase)
	     << endl;
    }

  ifstream& f = * l.file;
  bus* b;

  if (insn_space)
    b = l.load_accessor_insn;
  else
    b = l.load_accessor_data;
  assert (b);

  // go to proper offset in file
  f.seekg(file_offset);

  // fetch lots of characters
  for (int n = 0; n < bytes; n++)
    {
      char c;
      f.get(c);
      if (!f.good())
	{
	  cerr << "loader: error reading byte " << file_offset+n
	       << " from file " << l.load_file << endl;
	  return -1; // oops
	}

      if (host_addr) // read into host buffer
	{
	  // cerr << "H:" << (void*)host_addr << ":" << hex << (int)c << dec << endl;
	  *host_addr++ = c;
	}
      else // read into target memory
	{
	  host_int_8 a = dest_addr++;
	  little_int_1 data = c;
	  host_int_4 addr = a;

	  bus::status s;

	  do // loop while memory getting ready
	    {
	      s = b->write(addr, data);
	    } while (s == bus::delayed);

	  if (s != bus::ok) // abort on error
	    {
	      cerr << "loader: write to " << who << " accessor failed at address "
		   << make_numeric_attribute (addr, ios::hex | ios::showbase)
		   << ", status "
		   << (int) s << endl;
	      return -1;
	    }
	  // else
	  //  cerr << "T:" << addr << ":" << data << endl;
	}
    }
  return bytes;
}

// ----------------------------------------------------------------------------

static
vector<string>
compLoaderListTypes()
{
  vector<string> types;
  types.push_back("sw-load-elf");
  return types;
}

static
component*
compLoaderCreate(const string& typeName)
{
  if (typeName == "sw-load-elf")
    return new elf_loader();
  else
    return 0;
}

static
void
compLoaderDelete(component* c)
{
  delete dynamic_cast<elf_loader*>(c);
}

// static object
extern const component_library loader_component_library;

const component_library loader_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compLoaderListTypes, 
  & compLoaderCreate,
  & compLoaderDelete
};
