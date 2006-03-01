// compLoader.cxx - object file loader component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2003, 2004, 2005 Red Hat.
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
using sid::host_int_8;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_bus_map_component;
using sidutil::fixed_attribute_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::fixed_accessor_map_component;
using sidutil::no_relation_component;
using sidutil::configurable_component;
using sidutil::output_pin;
using sidutil::callback_pin;
using sidutil::string2stream;
using sidutil::stream2string;
using sidutil::make_attribute;
using sidutil::make_numeric_attribute;
using sidutil::parse_attribute;
using sidutil::std_error_string;

// ----------------------------------------------------------------------------

// A bus for allowing the loader to perform random checks against reads and writes
// to memory. For example writing to a code area. Default implementation
class loader_probe_bus: public sidutil::passthrough_bus
  {
  public:
    loader_probe_bus (sid::bus **t, output_pin *p) :
      sidutil::passthrough_bus (t),
      write_to_code_address_pin (p),
      section_table (0)
    {
      assert (t);
    }
    ~loader_probe_bus() throw() {}
    
    void set_section_table (const struct TextSection *s) { section_table = s; }

    void probe_address (sid::host_int_4 addr)
      {
	if (write_to_code_address_pin && textSectionAddress (addr, section_table))
	  write_to_code_address_pin->drive (addr);
      }

    // Some macros to make manufacturing of the cartesian-product
    // calls simpler.
#define SID_GB_WRITE(dtype) \
      sid::bus::status write(sid::host_int_4 addr, dtype data) throw ()\
	  { if (LIKELY(*target)) \
              { \
                probe_address (addr); \
                return (*target)->write(addr, data); \
              } \
            else return sid::bus::unpermitted; \
          }

    SID_GB_WRITE(sid::little_int_1)
    SID_GB_WRITE(sid::big_int_1)
    SID_GB_WRITE(sid::little_int_2)
    SID_GB_WRITE(sid::big_int_2)
    SID_GB_WRITE(sid::little_int_4)
    SID_GB_WRITE(sid::big_int_4)
    SID_GB_WRITE(sid::little_int_8)
    SID_GB_WRITE(sid::big_int_8)

#undef SID_GB_WRITE

    output_pin *write_to_code_address_pin;
    const struct TextSection *section_table;
  };

class generic_loader: public virtual component,
		      protected fixed_bus_map_component,
		      protected virtual fixed_attribute_map_component,
		      protected virtual fixed_pin_map_component,
		      protected fixed_accessor_map_component,
		      protected no_relation_component,
		      protected virtual configurable_component
{
private:
  callback_pin<generic_loader> doit_pin;

protected:
  // entry point address
  output_pin start_pc_pin;
  // endianness as specified in ELF header.
  // The value is one of sidutil::endian_*.
  output_pin endian_pin;
  // eflags as specified in ELF header.
  output_pin eflags_pin;

  // Provide address of write attempt to code section
  output_pin write_to_code_address_pin;

  // Signal this if something went wrong.
  output_pin error_pin;

  // Attribute settings
  bool verbose_p;

  // loadable file names
  string load_file;

  // accessors
  bus* load_accessor_insn;
  bus* load_accessor_data;

  loader_probe_bus probe_upstream;
  bus           *probe_downstream;
  callback_pin<generic_loader> probe_pin;

  void handle_probe_pin (sid::host_int_4 v)
    {
      probe_upstream.probe_address (v);
    }

  // The load pin was triggered.
  virtual void load_it (host_int_4) = 0;

  // state control
  friend ostream& operator << (ostream& o, const generic_loader& it);
  friend istream& operator >> (istream& i, generic_loader& it);
  string save_state() { return make_attribute(*this); }
  sid::component::status restore_state(const string& state)
    { return parse_attribute(state, *this); }

  virtual void configure (const string &config);

public:
  generic_loader(): 
    doit_pin(this, & generic_loader::load_it), 
    verbose_p(false),
    load_file("/dev/null"),
    load_accessor_insn(0),
    load_accessor_data(0),
    probe_upstream (& probe_downstream, & this->write_to_code_address_pin),
    probe_downstream(0),
    probe_pin (this, & generic_loader::handle_probe_pin)
    {
      add_pin("load!", & this->doit_pin);
      add_pin("start-pc-set", & this->start_pc_pin);
      add_pin("endian-set", & this->endian_pin);
      add_pin("eflags-set", &this->eflags_pin);
      add_pin("error", & this->error_pin);
      add_pin("write-to-code-address", & this->write_to_code_address_pin);
      add_accessor("load-accessor-insn", & this->load_accessor_insn);
      add_accessor("load-accessor-data", & this->load_accessor_data);
      add_attribute("file", & this->load_file, "setting");
      add_bus ("probe-upstream", & this->probe_upstream);
      add_accessor ("probe-downstream", & this->probe_downstream);
      add_pin ("probe", & this->probe_pin);
      add_attribute("verbose?", & this->verbose_p, "setting");
      add_attribute_virtual ("state-snapshot", this,
			     & generic_loader::save_state,
			     & generic_loader::restore_state);
    }
  ~generic_loader() throw() { }
    
};

void
generic_loader::configure (const string &config)
{
  // Call up to the base class first
  configurable_component::configure (config);

  // Now handle relevent configuration for us.
  if (config.size () < 12)
    return;
  if (config.substr (0, 8) == "verbose=")
    {
      verbose_p = (config.substr (8) == "true");
      return;
    }
}

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
public:
  elf_loader ()
    : generic_loader (),
      symbol_table (0),
      current_function (""),
      check_function_pin (this, &elf_loader::check_function_pin_handler)
    {
      add_pin ("function?", &check_function_pin);
      add_attribute ("current-function", & current_function);
    }
  ~elf_loader () throw () {}

private:
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
      unsigned eflags;

      const struct TextSection *section_table;
      int success_p = readElfFile(& elf_loader::load_function,
				  & entry_point, & little_endian_p,
				  & eflags, & section_table, & symbol_table);
      probe_upstream.set_section_table (section_table);
      elf_loader::freeloader = 0;

      if (success_p)
	{
	  // Tell anyone who's listening things we learned about the elf file.
	  this->start_pc_pin.drive((host_int_4) entry_point);
	  if (little_endian_p)
	    this->endian_pin.drive(sidutil::endian_little);
	  else
	    this->endian_pin.drive(sidutil::endian_big);
	  this->eflags_pin.drive((host_int_4) eflags);

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

protected:
  callback_pin<elf_loader> check_function_pin;
  void check_function_pin_handler (host_int_4 addr);

  const struct Symbol *symbol_table;
  string current_function;
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
	     << make_numeric_attribute (dest_addr, ios::hex | ios::showbase)
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

	  bus::status s = b->write(addr, data);

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

void
elf_loader::check_function_pin_handler (host_int_4 addr)
{
  // Find the function corresponding to the given address in the symbol
  // table, if any, and set current_function to that name. If no function is
  // found, set current_function to a string representing the address.
  if (symbol_table)
    {
      unsigned closest = 0;
      host_int_8 min_difference = ~(host_int_8)0;
      unsigned ix;
      for (ix = 0; symbol_table[ix].name; ++ix)
	{
	  // Don't consider unnamed symbols.
	  if (! symbol_table[ix].name[0])
	    continue;
	  host_int_8 sym_addr = symbol_table[ix].addr;
	  host_int_8 sym_size = symbol_table[ix].size;
	  if (addr == sym_addr)
	    break;
	  if (addr > sym_addr && addr < (sym_addr + sym_size))
	    break;
	  if (addr - sym_addr < min_difference)
	    {
	      min_difference = addr - sym_addr;
	      closest = ix;
	    }
	}
      if (symbol_table[ix].name)
	{
	  current_function = symbol_table[ix].name;
	  return;
	}
      if (closest != 0)
	{
	  current_function = symbol_table[closest].name;
	  return;
	}
    }
  current_function = "";
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
DLLEXPORT extern const component_library loader_component_library;

const component_library loader_component_library =
{
  COMPONENT_LIBRARY_MAGIC,
  & compLoaderListTypes, 
  & compLoaderCreate,
  & compLoaderDelete
};
