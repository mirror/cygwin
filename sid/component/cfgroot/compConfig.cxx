// compConfig.cxx - The cfgroot component: configuration parsing, root
// of component creation and management.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidpinutil.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidmiscutil.h>
#include <sidpinattrutil.h>

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include <cctype>
#include <cstring>
#include <cassert>
#include <ltdl.h>

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#ifdef STDC_HEADERS
#include <stdlib.h>
#endif

#ifdef __CYGWIN__
#include <sys/cygwin.h>
#endif

using std::map;
using std::pair;
using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::cerr;
using std::endl;
using std::ios;
using std::ifstream;
using std::flush;

using sid::component;
using sid::pin;
using sid::bus;
using sid::host_int_1;
using sid::host_int_2;
using sid::host_int_4;
using sid::host_int_8;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_pin_map_component;
using sidutil::fixed_attribute_map_component;
using sidutil::fixed_relation_map_component;
using sidutil::no_bus_component;
using sidutil::no_accessor_component;
using sidutil::output_pin;
using sidutil::callback_pin;
using sidutil::stream2string;
using sidutil::string2stream;
using sidutil::make_attribute;
using sidutil::make_numeric_attribute;
using sidutil::parse_attribute;
using sidutil::std_error_string;
using sidutil::recursion_limited;
using sidutil::recursion_record;
using sidutil::find_sid_data_file;
using sidutil::tokenize;


// This component reads a flat config file, and acts as a root
// container for the simulation.
class cfgroot_component: public virtual component,
			 protected fixed_pin_map_component,
			 protected fixed_attribute_map_component,
			 protected no_bus_component,
			 protected no_accessor_component,
			 protected fixed_relation_map_component,
			 protected recursion_limited
{
public:
  cfgroot_component();
  virtual ~cfgroot_component() throw();

protected:
  host_int_8 activity_count;
  bool running;
  host_int_4 stop_code;
  void run (host_int_4); // run top-level simulation loop
  void stop (host_int_4); // stop top-level simulation loop

  // config-file! and config-line! virtual attribute handlers
  component::status configure_file(const std::string&);
  component::status configure_line(const std::string&);
  component::status dynamic_config(const std::string&);
  component::status lookup_dynamic_config(const std::string&);
  string nothing ();

  // parser
  string config_file;
  unsigned line_num;
  bool parse(istream&);
  string current_token;
  int num_invalid_chars;
  void consume_token(istream&);
  string next_token(istream&);
  bool parse_command(istream&);

  // commands
  bool register_dso(const string& dso_name, const string& _symbol_name);
  bool register_la(const string& la_name, const string& symbol_name);
  bool instantiate_component(const string& type, const string& name);
  bool connect_pin(const string& c1, const string& p1,
		   const string& c2, const string& p2);
  bool disconnect_pin(const string& c1, const string& p1,
		   const string& c2, const string& p2);
  bool connect_bus(const string& c1, const string& a1,
		      const string& c2, const string& b2);
  bool disconnect_bus(const string& c1, const string& a1,
		      const string& c2, const string& b2);
  bool set_attribute(const string& cname, const string& attr_name, 
		     const string& attr_value);
  bool set_relation(const string& cname, const string& rel_name,
		    const string& rel_value);
  bool unset_relation(const string& cname, const string& rel_name,
		      const string& rel_value);

  // state control
  friend ostream& operator << (ostream& o, const cfgroot_component& it);
  friend istream& operator >> (istream& i, cfgroot_component& it);
  string save_state() { return make_attribute(*this); }
  component::status restore_state(const string& state)
    { return parse_attribute(state, *this); }

  // relations
  vector<component*> component_catalog_informees;
  void inform_component_catalog_informees(component* focus = 0);

private:
  callback_pin<cfgroot_component> run_pin;
  output_pin starting_pin;
  output_pin activity_pin;
  callback_pin<cfgroot_component> stop_pin;
  output_pin stopping_pin;

  string config_file_history;
  bool verbose_p;
  bool autoprint_p;
  bool persistent_p;

  // max number of invalid chars which may be in a config file
  enum { max_invalid_chars = 12 };

  // a general purpose method for emitting error messages
  // FIXME: i18n
  void emit_error(const string& msg);

  // emit an error for invalid character codes found in the input
  void emit_invalid_char_error (const char ch);

  // track component name -> component object pointer
  typedef map<string,component*> component_map_t;
  component_map_t component_map;
  typedef map<string,string> component_type_map_t;
  component_type_map_t component_type_map;

  // track component type name -> component_library object pointer
  typedef map<string,component_library*> component_library_map_t;
  component_library_map_t component_library_map;

  // track component name -> component_library object pointer
  typedef map<string,component_library*> component_creator_map_t;
  component_creator_map_t component_creator_map;

  // Dynamic configurations
  map<string,string> dynamic_configs;
  string found_dynamic_config;
#ifndef NDEBUG
  void crash() { abort(); }
#endif
};



void
cfgroot_component::emit_error(const string& msg)
{
  cerr << config_file << ":" << line_num << ": " << msg << endl;
}

void
cfgroot_component::emit_invalid_char_error (const char ch)
{
  if (++num_invalid_chars < max_invalid_chars)
    emit_error(string("invalid character [") + 
	       make_numeric_attribute(host_int_2((unsigned char) ch),
				      ios::hex|ios::showbase) +
	       string("] ignored."));
}

void
cfgroot_component::consume_token(istream& input) // lexer
{
  string buf;
  while (true)
    {
      char ch = input.get();
      if (ch == '\n')
	{
	  line_num++;
	}
      if (! input.good())
	{
	  break; // end of token & stream
	}
      else if (ch == '#') // comment to end-of-line
	{
	  do { ch = input.get(); } while (ch != '\n' && input.good());
	  line_num++;
	}
      else if (isspace(ch)) 
	{
	  // skip leading whitespace
	}
      else if (ch == '"') // string literal
	{
	  while (true)
	    {
	      ch = input.get();
	      if (ch == '\n')
		{
		  line_num++;
		}
	      if (! input.good())
		{
		  emit_error("unterminated string literal");
		  buf = "";
		  break;
		}
	      else if (ch == '"') // closing quotes
		break;
	      else if (ch == '\\') // escape sequence
		{
		  ch = input.get();
		  if (ch == '\n') 
		    {
		      line_num++;
		    }
		  if (! input.good())
		    {
		      buf = "";
		      break;
		    }
		  switch (ch)
		    {
		    case 'n': buf += '\n'; break;
		      // XXX: other escape sequences?
		    default: buf += ch;
		    }
		}
	      else 
		buf += ch;
	    }
	  break; // end of token
	}
      else if (isascii(ch) && !isspace(ch)) // text
	{
	  do
	    {
	      if (!isprint(ch))
		emit_invalid_char_error (ch);
	      else
		buf += ch;

	      ch = input.get();
	      if (ch == '\n')
		{
		  input.unget();
		}
	    } while (!isspace(ch) && input.good());
	  break; // end of token
	}
      else // control code
	{
	  emit_invalid_char_error (ch);
	  continue;
	}
    }
  current_token = buf;
}


string
cfgroot_component::next_token(istream& input)
{
  consume_token(input);
  return current_token;
}


bool
cfgroot_component::parse_command(istream& input)
{
  string command = next_token(input);
  if(command == "") // EOF
    {
      return true;
    }
  else if (command == "load") // load dso-name symbol-name
    {
      bool ok = true;

      string dso_name = next_token(input);
      string symbol_name = next_token(input);

      if (! input.good())
	{
	  emit_error("unexpected end of file");
	  ok = false;
	}

      // Abort here in case of parse error
      if (! ok) return ok;

      return this->register_dso(dso_name, symbol_name);
    }
  else if(command == "new") // new component-type component-name
    {
      bool ok = true;

      string type = next_token(input);
      string name = next_token(input);

      if (! input.good())
	{
	  emit_error("unexpected end of file");
	  ok = false;
	}

      // Abort here in case of parse error
      if (! ok) return ok;

      return this->instantiate_component(type, name);
    }
  else if (command == "connect-pin" || command == "disconnect-pin") 
    {
      // connect-pin comp1 pin1 dir comp2 pin2    OR:
      // disconnect-pin comp1 pin1 dir comp2 pin2
      bool ok = true;
      string comp1 = next_token(input);
      string pin1 = next_token(input);
      string direction = next_token(input);
      string comp2 = next_token(input);
      string pin2 = next_token(input);

      if (! input.good())
	{
	  emit_error("unexpected end of file");
	  ok = false;
	}

      // (Don't warn again in case of eof)
      if (direction != "" && direction != "<-" && direction != "->" && direction != "<->")
	{
	  emit_error("directional arrow expected");
	  ok = false;
	}

      // Abort here in case of parse error
      if (! ok)	return ok;

      if ((direction == "->") || (direction == "<->"))
	{
	  if (command == "connect-pin")
	    ok = ok && this->connect_pin(comp1, pin1, comp2, pin2);
	  else
	    ok = ok && this->disconnect_pin(comp1, pin1, comp2, pin2);
	}
      if ((direction == "<-") || (direction == "<->"))
	{
	  if (command == "connect-pin")
	    ok = ok && this->connect_pin(comp2, pin2, comp1, pin1);
	  else
	    ok = ok && this->disconnect_pin(comp2, pin2, comp1, pin1);
	}
      return ok;
    }
  else if (command == "connect-bus" || command == "disconnect-bus")
    {
      // connect-bus c1 accessor c2 bus    OR:
      // disconnect-bus c1 accessor c2 bus

      bool ok = true;

      string comp1 = next_token(input);
      string acc1 = next_token(input);
      string comp2 = next_token(input);
      string bus2 = next_token(input);

      if (! input.good())
	{
	  emit_error("unexpected end of file");
	  ok = false;
	}

      // Abort here in case of parse error
      if (! ok)	return ok;

      if (command == "connect-bus")
	return this->connect_bus(comp1, acc1, comp2, bus2);
      else
	return this->disconnect_bus(comp1, acc1, comp2, bus2);
    }
  else if (command == "set") // set comp attr value
    {
      bool ok = true;

      string comp = next_token(input);
      string attr_name = next_token(input);
      string attr_value = next_token(input);

      if (! input.good())
	{
	  emit_error("unexpected end of file");
	  ok = false;
	}

      // Abort here in case of parse error
      if (! ok)	return ok;

      return this->set_attribute(comp, attr_name, attr_value);
    }
  else if (command == "relate" || command == "unrelate") // [un]relate comp rel comp2
    {
      bool ok = true;

      string comp = next_token(input);
      string rel_name = next_token(input);
      string comp2 = next_token(input);

      // Abort here in case of parse error
      if (! ok)	return ok;

      if (command == "relate")
	return this->set_relation(comp, rel_name, comp2);
      else
	return this->unset_relation(comp, rel_name, comp2);
    }
  // ... etc ...
  else 
    {
      emit_error(string("unknown command ") + command);
      return false;
    }

  // XXX: notreached
  return false;
}



bool
cfgroot_component::parse(istream& cfile)
{
  bool cumulative_ok = true;
  while (cfile.good())
    {
      bool this_ok = this->parse_command(cfile);
      cumulative_ok = cumulative_ok && this_ok;

      if (num_invalid_chars >= max_invalid_chars)
	{
	  emit_error ("too many invalid characters--possibly a binary file?");
	  cumulative_ok = false;
	  break;
	}
    }
  return cumulative_ok;
}


std::string
cfgroot_component::nothing()
{
  return "";
}


component::status
cfgroot_component::configure_file(const std::string& name)
{
  string last_config_file = this->config_file;
  this->config_file = name;
  if (this->config_file_history != "")
    this->config_file_history += ", ";
  this->config_file_history += this->config_file;
  unsigned last_line_num = this->line_num;
  this->line_num = 1;
  num_invalid_chars = 0;

  ifstream cfile(find_sid_data_file(this->config_file).c_str());
  if(! cfile.good())
    {
      cerr << config_file << ": " << std_error_string() << endl;
      this->config_file = last_config_file;
      this->line_num = last_line_num;
      return component::bad_value;
    }

  bool ok = this->parse(cfile);
  this->config_file = last_config_file;
  this->line_num = last_line_num;
  return ok ? component::ok : component::bad_value;
}



component::status
cfgroot_component::configure_line(const std::string& line)
{
  string last_config_file = this->config_file;
  this->config_file = "<literal>";
  if (this->config_file_history != "")
    this->config_file_history += ", ";
  this->config_file_history += this->config_file;
  unsigned last_line_num = this->line_num;
  this->line_num = 1;
  num_invalid_chars = 0;

  string line_with_eol = line + "\n";

#if HAVE_SSTREAM
    std::istringstream cfile (line_with_eol);
#elif HAVE_STRSTREAM_H
    istrstream cfile (line_with_eol.data (), line_with_eol.length ());
#else
#error "need <sstream> or <strstream.h>!"
#endif

  if(! cfile.good())
    {
      this->config_file = last_config_file;
      this->line_num = last_line_num;
      return component::bad_value;
    }

  bool ok = this->parse(cfile);
  this->config_file = last_config_file;
  this->line_num = last_line_num;
  return ok ? component::ok : component::bad_value;
}


component::status
cfgroot_component::dynamic_config(const std::string& spec)
{
  vector<string> parts = tokenize (spec, "|");
  if (parts.size () != 2)
    return component::bad_value;

  dynamic_configs[parts[0]] = parts[1];
  return component::ok;
}


component::status
cfgroot_component::lookup_dynamic_config(const std::string& name)
{
  if (dynamic_configs.find (name) == dynamic_configs.end())
    return component::not_found;

  found_dynamic_config = name + "|" + dynamic_configs [name];
  return component::ok;
}


cfgroot_component::cfgroot_component():
  recursion_limited ("running", 1),
  running (false),
  stop_code (0),
  config_file ("<none>"),
  line_num(1),
  run_pin(this, & cfgroot_component::run),
  stop_pin(this, & cfgroot_component::stop),
  verbose_p (false),
  autoprint_p (true),
  persistent_p (false),
  dynamic_configs (),
  found_dynamic_config ("")
{
  // suck in libtool preloaded symbols; must be called before lt_dlinit()
  LTDL_SET_PRELOADED_SYMBOLS ();

  int rc = lt_dlinit();
  assert(rc == 0);

  char* slp = getenv ("SID_LIBRARY_PATH"); // run-time configuration
  if (slp) lt_dlsetsearchpath (slp);

  char* sep = getenv ("SID_EXEC_PREFIX"); // install-time configuration
#ifdef HAVE_CYGWIN_CONV_TO_FULL_POSIX_PATH
  char conv_fn[PATH_MAX*2];
  if (sep)
    {
      int rc = cygwin_conv_to_full_posix_path (sep, conv_fn);
      if (rc != 0)
	cerr << "cfgroot: cygwin_conv_to_full_posix_path failed: " 
	     << std_error_string () << endl;
      else
	sep = conv_fn;
    }
#endif
  if (!sep) sep = SID_EXEC_PREFIX; // build-time configuration
  string pkglibdir = string(sep) + string("/lib/sidcomp");
  (void) lt_dladdsearchdir (pkglibdir.c_str ());

  add_pin("run!", & this->run_pin);

  add_pin("starting", & this->starting_pin);
  add_attribute("starting", & this->starting_pin, "pin");
  add_pin("perform-activity", & this->activity_pin);
  add_attribute("perform-activity", & this->activity_pin, "pin");

  add_attribute_ro ("running", & this->running, "register");
  add_attribute_ro ("activity-count", & this->activity_count, "register");
  add_attribute_ro ("stop-code", & this->stop_code, "register");

  add_pin("stop!", & this->stop_pin);
  add_attribute("stop!", & this->stop_pin, "pin");
  add_pin("stopping", & this->stopping_pin);
  add_attribute("stopping", & this->stopping_pin, "pin");

  add_attribute_virtual ("config-file!", this,
			 & cfgroot_component::configure_file,
			 & cfgroot_component::nothing);
  add_attribute_virtual ("config-line!", this,
			 & cfgroot_component::configure_line,
			 & cfgroot_component::nothing);
  add_attribute_virtual ("dynamic-config!", this,
			 & cfgroot_component::dynamic_config,
			 & cfgroot_component::nothing);
  add_attribute_virtual ("lookup-dynamic-config!", this,
			 & cfgroot_component::lookup_dynamic_config,
			 & cfgroot_component::nothing);
  add_attribute("found-dynamic-config", & this->found_dynamic_config, "result");
  add_attribute_ro ("config-file-history", & this->config_file_history,
                    "register");
  add_attribute("verbose?", & this->verbose_p, "setting");
  add_attribute("auto-print?", & this->autoprint_p, "setting");
  add_attribute("persistent?", & this->persistent_p, "setting");
  add_attribute_virtual ("state-snapshot", this,
			 & cfgroot_component::save_state,
			 & cfgroot_component::restore_state);

  add_multi_relation ("component-catalog-informees", & this->component_catalog_informees);

#ifndef NDEBUG
  add_attribute_notify ("**crash-sid-now**", & this->running, this, 
			 & cfgroot_component::crash, "setting");
#endif
  
  // register self as the "main" component.
  // NB: correlate with type in cfgroot_component_library
  this->component_map["main"] = this;
  this->component_type_map["main"] = "sid-control-cfgroot";
}


cfgroot_component::~cfgroot_component() throw()
{
    // Delete every item in the component_creator map.
    for (component_creator_map_t::iterator it = this->component_creator_map.begin ();
         it != this->component_creator_map.end ();
         it++)
      {
	string name = it->first;
	component_library* l = it->second;
	component* c = this->component_map[name];

	assert (c != 0);
	assert (l != 0);
	assert (l->delete_component != 0);

	if (this->verbose_p)
	  cout << "deleting component name " << name << endl;

	(* l->delete_component) (c);
      }

    int rc = lt_dlexit();
    assert(rc == 0);
}


void
cfgroot_component::stop (host_int_4 code)
{
  this->running = false;
  this->stop_code = code;
}


void
cfgroot_component::run(host_int_4)
{
  recursion_record running (this);
  if (! running.ok())
    return;

  if (this->component_map.size() == 1)
    {
      cout << "No components - aborting run." << endl;
      return;
    }

  if (this->verbose_p)
    cout << "informing component catalog informees." << endl;
  this->inform_component_catalog_informees();

  do
    {

      if (this->verbose_p)
	cout << "main loop starting." << endl;
      
      this->activity_count = 0;
      
      // Set this flag first, so that if someone during
      // starting_pin.drive() clears it, it has effect.
      this->running = true;
      this->stop_code = 0;
      this->starting_pin.drive (1);
      while (LIKELY(this->running))
	{
	  this->activity_pin.drive (1);
	  this->activity_count ++;
	}
      this->stopping_pin.drive (1);
      
      if (this->verbose_p)
	cout << "main loop ended after " << this->activity_count << " iterations." << endl;
    } while (this->persistent_p);

  if (this->verbose_p)
    cout << "simulator exiting" << endl;
}


bool
cfgroot_component::register_dso(const string& dso_name, const string& _symbol_name)
{
  lt_dlhandle dl_handle = 0;

  // Try ordinary dynamic linking
  dl_handle = lt_dlopen(dso_name.c_str());

  // Second, try ".la"->".a" kludge.
  if (! dl_handle &&
      (dso_name.length() > 3) &&
      (dso_name[dso_name.length()-3] == '.') &&
      (dso_name[dso_name.length()-2] == 'l') &&
      (dso_name[dso_name.length()-1] == 'a'))
    {
      string dso_name_dot_a = dso_name.substr (0, dso_name.length()-3);
      dso_name_dot_a += ".a";
      dl_handle = lt_dlopen(dso_name_dot_a.c_str());
    }

  // At last, try again looking within the executable
  if (dl_handle == 0)
    {
      dl_handle = lt_dlopen(NULL); // component library linked into executable
    }

  if (dl_handle == 0)
    {
      emit_error(string("dlopen of component library dso ") +
		 dso_name +
		 string(" failed: ") +
		 string(lt_dlerror()));
      return false;
    }
  
  const char* symbol_name = _symbol_name.c_str();
  void* symbol = lt_dlsym(dl_handle, symbol_name);
  if(symbol == 0)
    {
      emit_error(string("dlsym of ") + symbol_name +
		 string(" in component library dso ") + dso_name +
		 string(" failed: ") + string(lt_dlerror()));
     
      lt_dlclose (dl_handle);
      return false;
    }
  
  component_library* lib = (component_library*) symbol;
  
  // confirm magic
  if (lib->magic != COMPONENT_LIBRARY_MAGIC)
    {
      emit_error(string("component library ") + symbol_name +
		 string(" in ") + dso_name +
		 string(" has incompatible ABI magic value: ") +
		 make_numeric_attribute (lib->magic, ios::hex|ios::showbase) +
		 string(", expected ") +
		 make_numeric_attribute (COMPONENT_LIBRARY_MAGIC, ios::hex|ios::showbase) +
		 string("."));
      lt_dlclose (dl_handle);
      return false;
    }

  // confirm existence of all hook functions
  if ((lib->list_component_types == 0) ||
      (lib->delete_component == 0)     ||
      (lib->create_component == 0))
    {
      emit_error(string("component library ") + symbol_name +
		 string(" in ") + dso_name +
		 string(" has broken component_library pointers."));
      lt_dlclose (dl_handle);
      return false;
    }
  
  // enumerate component types; add 'em to the component_library map.
  if (this->verbose_p)
    cout << "component library " << dso_name << " contains type(s): " << flush;

  assert (lib->list_component_types != 0);
  vector<string> types = (* lib->list_component_types)();
  for(vector<string>::iterator it = types.begin();
      it != types.end();
      it++)
    {
      const string& type_name = (*it);

      if (this->verbose_p)
	cout << type_name << " ";
      
      this->component_library_map[type_name] = lib;
    }

  if (this->verbose_p)
    cout << endl;

  // XXX: should keep dl handle for ultimate lt_dlclose()
  return true;
}


bool
cfgroot_component::instantiate_component(const string& type, const string& name)
{
  component_map_t::iterator that = this->component_map.find(name);
  if(that != this->component_map.end())
    {
      emit_error(string("component ") + name + 
		 string(" already exists."));
      return false;
    }

  component_library_map_t::iterator it = this->component_library_map.find(type);
  if(it == this->component_library_map.end())
    {
      emit_error(string("component type ") + type + string(" unknown"));
      return false;
    }
  component_library* lib = it->second;
  
  assert (lib->create_component != 0);
  component* comp = (* lib->create_component)(type);
  if(comp == 0)
    {
      emit_error(string("component type ") + type + 
		 string(" instantiation failed."));
      return false;
    }

  // got it!
  if (this->verbose_p)
    cout << "component type " << type << " instantiated with name " << name << endl;

  this->component_map[name] = comp;
  this->component_type_map[name] = type;
  this->component_creator_map[name] = lib;

  // Handle autoprinting
  if (this->autoprint_p)
    {
      vector<string> autoprint_attrs = comp->attribute_names ("auto-print");
      for (unsigned i=0; i<autoprint_attrs.size(); i++)
	{
	  string s = comp->attribute_value (autoprint_attrs[i]);
	  if (s != "")
	    cout << s << endl;
	}
    }

  // Inform component catalog informees if we are already running
  if (this->running)
    {
      if (this->verbose_p)
	cout << "updating component catalog informees." << endl;
      this->inform_component_catalog_informees (comp);
    }
  
  return true;
}



// establish one unidirectional connection (c1,p1) -> (c2,p2)
bool
cfgroot_component::connect_pin(const string& c1, const string& p1,
			       const string& c2, const string& p2)
{
  component_map_t::iterator that = this->component_map.find(c1);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + c1 + string(" not found"));
      return false;
    }
  component* comp1 = that->second;

  that = this->component_map.find(c2);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + c2 + string(" not found"));
      return false;
    }
  component* comp2 = that->second;

  // Find the input pin
  pin* pin2 = comp2->find_pin(p2);
  if (!pin2)
    {
      emit_error(string("component ") + c2 +
		 string(" has no input pin ") + p2);
      return false;
    }

  // Connect it to the output pin
  component::status s = comp1->connect_pin(p1,pin2);
  if (s == component::not_found)
    emit_error(string("component ") + c1 +
	       string(" has no output pin ") + p1);
  else if (s == component::bad_value)
    emit_error(string("output pin ") + p1 + 
	       string(" is already connected to input pin ") + p2);
  else if (s == component::ok && this->verbose_p)
    cout << "connected component " << c1 << " pin " << p1
	 << " to component " << c2 << " pin " << p2 << endl;

  return (s == component::ok);
}


bool
cfgroot_component::disconnect_pin(const string& c1, const string& p1,
				  const string& c2, const string& p2)
{
  component_map_t::iterator that = this->component_map.find(c1);
  if (that == this->component_map.end())
    {
      emit_error(string("component ") + c1 + string(" not found"));
      return false;
    }
  component* comp1 = that->second;
  
  that = this->component_map.find(c2);
  if (that == component_map.end())
    {
      emit_error(string("component ") + c2 + string(" not found"));
      return false;
    }
  component *comp2 = that->second;

  // Find the input pin
  pin* pin2 = comp2->find_pin(p2);
  if (!pin2)
    {
      emit_error(string("component ") + c2 +
		 string(" has no inpuit pin ") + p2);
      return false;
    }

  component::status st = comp1->disconnect_pin(p1, pin2);
  if (st == component::not_found)
    emit_error(string("component ") + c1 +
	       string(" has no output pin ") + p1);
  else if (st == component::bad_value)
    emit_error(string("could not disconnect from ") + c2 + " " + p2);
  else if (st == component::ok && this->verbose_p)
    cout << "disconnected component " << c1 << " pin " << p1
	 << " from component " << c2 << " pin " << p2 << endl;
  
  return (st == component::ok);
}

bool
cfgroot_component::connect_bus(const string& c1, const string& a1,
			       const string& c2, const string& b2)
{
  component_map_t::iterator that = this->component_map.find(c1);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + c1 + string(" not found"));
      return false;
    }
  component* comp1 = that->second;
      
  that = this->component_map.find(c2);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + c2 + string(" not found"));
      return false;
    }
  component* comp2 = that->second;

  bus* bus2 = comp2->find_bus(b2);
  if(bus2 == 0)
    {
      emit_error(string("component ") + c2 +
		 string(" has no bus ") + b2);
      return false;
    }

  enum component::status status = comp1->connect_accessor( a1, bus2 );
  if (status == component::not_found)
    emit_error(string("component ") + c1 + string(" accessor ") +
	       a1 + string(" not found"));
  else if (status == component::bad_value)
    emit_error(string("could not set component ") + c1 +
	       string(" accessor ") + a1);
  else if (status == component::ok && this->verbose_p)
    cout << "connected component " << c1 << " accessor " << a1
	 << " to component " << c2 << " bus " << b2 << endl;

  return (status == component::ok);
}

bool
cfgroot_component::disconnect_bus(const string& c1, const string& a1,
				  const string& c2, const string& b2)
{
  component_map_t::iterator that = this->component_map.find(c1);
  if (that == this->component_map.end())
    {
      emit_error(string("component ") + c1 + string(" not found"));
      return false;
    }
  component* comp1 = that->second;

  that = this->component_map.find(c2);
  if (that == this->component_map.end())
    {
      emit_error(string("component ") + c2 + string(" not found"));
      return false;
    }
  component* comp2 = that->second;

  // This isn't strictly required, but it doesn't hurt to check.
  bus* bus2 = comp2->find_bus(b2);
  if (bus2 == 0)
    {
      emit_error(string("component ") + c2 +
		 string(" has no bus ") + b2);
      return false;
    }

  component::status s = comp1->disconnect_accessor(a1, bus2);
  if (s == component::not_found)
    emit_error(string("component ") + c1 + string(" accessor ") + a1 
	       + string(" not found "));
  else if (s == component::bad_value)
    emit_error(string("could not unset component ") + c1 + string(" accessor ") + a1);
  else if (s == component::ok && this->verbose_p)
    cout << "disconnected component " << c1 << " accessor " << a1
	 << " from component " << c2 << " bus " << b2 << endl;

  return s == component::ok;
}


bool
cfgroot_component::set_attribute(const string& cname, 
				 const string& attr_name, const string& attr_value)
{
  component_map_t::iterator that = this->component_map.find(cname);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + cname + string(" not found"));
      return false;
    }
  component* comp = that->second;

  component::status status = comp->set_attribute_value(attr_name, attr_value);
  if (status == component::not_found)
    emit_error(string("component ") + cname + string(" attribute ") +
	       attr_name + string(" not found"));
  else if (status == component::bad_value)
    emit_error(string("component ") + cname + string(" attribute ") +
	       attr_name + string(" bad value ") + attr_value);
  else if (status == component::ok && this->verbose_p)
    cout << "set component " << cname << " attribute " << attr_name
	 << " to value " << attr_value << endl;

  return status == component::ok;
}


bool
cfgroot_component::set_relation(const string& cname, const string& rel_name, 
				const string& rcname)
{
  component_map_t::iterator that = this->component_map.find(cname);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + cname + string(" not found"));
      return false;
    }
  component* comp = that->second;

  component_map_t::iterator other = this->component_map.find(rcname);
  if(other == this->component_map.end())
    {
      emit_error(string("component ") + rcname + string(" not found"));
      return false;
    }
  
  component::status status = comp->relate (rel_name, other->second);
  if (status != component::ok)
    emit_error(string("cannot set relation ") + rel_name +
	       string(" for component ") + cname);
  else if (status == component::ok && this->verbose_p)
    cout << "component " << cname
	 << " related as " << rel_name
	 << " to component " << rcname << endl;

  return (status == sid::component::ok);
}


bool
cfgroot_component::unset_relation(const string& cname, const string& rel_name, 
				  const string& rcname)
{
  component_map_t::iterator that = this->component_map.find(cname);
  if(that == this->component_map.end())
    {
      emit_error(string("component ") + cname + string(" not found"));
      return false;
    }
  component* comp = that->second;

  component_map_t::iterator other = this->component_map.find(rcname);
  if(other == this->component_map.end())
    {
      emit_error(string("component ") + rcname + string(" not found"));
      return false;
    }
  
  component::status status = comp->unrelate (rel_name, other->second);
  if (status != component::ok)
    emit_error(string("cannot unset relation ") + rel_name +
	       string(" for component ") + cname);
  else if (status == component::ok && this->verbose_p)
    cout << "component " << cname
	 << " unrelated as " << rel_name
	 << " from component " << rcname << endl;

  return (status == sid::component::ok);
}


void
cfgroot_component::inform_component_catalog_informees (component* focus)
{
  for (component_map_t::const_iterator it = this->component_map.begin();
       it != this->component_map.end();
       it++)
    {
      string component_name = it->first;
      component* other_component = it->second;

      // Skip this one if we were directed to focus on one component
      if ((focus != 0) && (focus != other_component))
	continue;

      string component_type = this->component_type_map[component_name];
      string relationship_name = component_type + " " + component_name;

      for (unsigned i=0; i < this->component_catalog_informees.size(); i++)
	{
	  sid::component* informee = this->component_catalog_informees[i];
	  assert (informee != 0);

	  sid::component::status s = informee->relate (relationship_name, other_component);
	  if (s != sid::component::ok)
	    {
	      ; // XXX: emit warning?
	    }
	}
    }
}

ostream& 
operator << (ostream& out, const cfgroot_component& it)
{
  out << "cfgroot-state "
      << string2stream(it.config_file) << " "
      << it.verbose_p << " " 
      << it.persistent_p;

  return out;
}

istream& 
operator >> (istream& in, cfgroot_component& it)
{
  string coding;
  in >> coding;
  if (coding == "cfgroot-state")
    {
      in >> stream2string(it.config_file)
	 >> it.verbose_p
	 >> it.persistent_p;
    }
  else
    {
      in.setstate(ios::badbit);
    }

  return in;
}

// -----------------------------------------------------------------------
// This component is used to dynamically configure the system.
//
class dynamic_configurator_component: public virtual component,
					protected fixed_pin_map_component,
					protected fixed_attribute_map_component,
					protected no_bus_component,
					protected no_accessor_component,
					protected fixed_relation_map_component
{
public:
  dynamic_configurator_component();
  virtual ~dynamic_configurator_component() throw() {}
protected:
  void reset_pin_handler(host_int_4 ignore);

  component::status add_warmup_functions (const std::string&);
  component::status add_profile_functions (const std::string&);
  component::status set_start_config (const std::string&);

  component::status configure (const std::string&);
  component::status do_configure (const std::string &name, const std::string& config, unsigned &handle);
  unsigned restore_config (unsigned handle);
  unsigned set_syscall_config (unsigned);
  void check_config_change (unsigned);

  callback_pin<dynamic_configurator_component> reset_pin;
  callback_pin<dynamic_configurator_component> step_pin;
  output_pin step_control_pin;
  callback_pin<dynamic_configurator_component> configure_pin;
  callback_pin<dynamic_configurator_component> function_caller_pin;
  callback_pin<dynamic_configurator_component> function_callee_pin;
  callback_pin<dynamic_configurator_component> function_jump_pin;
  callback_pin<dynamic_configurator_component> function_return_pin;
  void step_pin_handler (host_int_4);
  void configure_pin_handler (host_int_4 handle);
  void function_caller_pin_handler (host_int_4 addr);
  void function_callee_pin_handler (host_int_4 addr);
  void function_jump_pin_handler (host_int_4 addr);
  void function_return_pin_handler (host_int_4 addr);

  output_pin config_result_pin;
  output_pin config_error_pin;
  output_pin function_address_pin;

  unsigned current_config;
  unsigned prev_config;
  unsigned prev_user_config;
  bool in_function (const string &name);

  vector<string> config_names;
  vector<string> config_specs;
  map<string,string> function_configs;
  vector< pair<string,unsigned> > config_stack;

  component *loader;
  component *main;
  component_relation_t clients;

private:
  string get_nothing () { return ""; }
  component::status set_nothing (const string&) { return component::not_found; }
  void reset ();
};


dynamic_configurator_component::dynamic_configurator_component ()
  :
  reset_pin(this, &dynamic_configurator_component::reset_pin_handler),
  step_pin (this, &dynamic_configurator_component::step_pin_handler),
  configure_pin (this, &dynamic_configurator_component::configure_pin_handler),
  function_caller_pin (this, &dynamic_configurator_component::function_caller_pin_handler),
  function_callee_pin (this, &dynamic_configurator_component::function_callee_pin_handler),
  function_jump_pin (this, &dynamic_configurator_component::function_jump_pin_handler),
  function_return_pin (this, &dynamic_configurator_component::function_return_pin_handler),
  loader (0),
  main (0)
{
  add_attribute_virtual ("warmup-functions!", this,
			 & dynamic_configurator_component::add_warmup_functions,
			 & dynamic_configurator_component::get_nothing);
  add_attribute_virtual ("profile-functions!", this,
			 & dynamic_configurator_component::add_profile_functions,
			 & dynamic_configurator_component::get_nothing);
  add_attribute_virtual ("start-config", this,
			 & dynamic_configurator_component::set_start_config,
			 & dynamic_configurator_component::get_nothing);
  add_attribute_virtual ("configure!", this,
			 & dynamic_configurator_component::configure,
			 & dynamic_configurator_component::get_nothing);
  add_pin("reset", &this->reset_pin);
  add_pin ("step!", &step_pin);
  add_pin ("step-control", &step_control_pin);
  add_pin ("configure!", &configure_pin);
  add_pin ("config-result", &config_result_pin);
  add_pin ("config-error", &config_error_pin);
  add_pin ("function-caller!", &function_caller_pin);
  add_pin ("function-callee!", &function_callee_pin);
  add_pin ("function-jump!", &function_jump_pin);
  add_pin ("function-return!", &function_return_pin);
  add_pin ("function-address", &function_address_pin);

  add_uni_relation("loader", &this->loader);
  add_uni_relation("main", &this->main);
  add_multi_relation ("client", &this->clients);

  config_stack.push_back (pair<string,unsigned> ("<start>", 0));
  config_names.push_back ("<start>");
  config_specs.push_back ("");

  reset ();
}

void
dynamic_configurator_component::reset_pin_handler(host_int_4)
{
  reset();
}

void
dynamic_configurator_component::reset ()
{
  current_config = 0;
  prev_config = 0;
  prev_user_config = 0;

  while (config_stack.size () > 1)
    config_stack.pop_back ();

  assert (config_names.size () == config_specs.size ());
  while (config_names.size () > 1)
    {
      config_names.pop_back ();
      config_specs.pop_back ();
    }

  if (config_names[0] != "<start>")
    {
      component::status s = main->set_attribute_value ("lookup-dynamic-config!", config_names[0]);
      if (s == component::ok)
	{
	  string spec = main->attribute_value ("found-dynamic-config");
	  configure (spec);
	}
    }

  step_control_pin.drive (1); // reconfigure during next cycle
}

// Set the starting configuration
component::status
dynamic_configurator_component::set_start_config (const std::string& name)
{
  config_names[0] = name;
  return component::ok;
}

// Add the given list of function names as functions to be simulated in warmup
// mode. FUNCS will be a comma-separated list of function names.
//
component::status
dynamic_configurator_component::add_warmup_functions (const std::string& funcs)
{
  vector<string> parts = tokenize (funcs, ",");
  unsigned size = parts.size ();
  for (unsigned i = 0; i < size; ++i)
    function_configs[parts[i]] = "sid-internal-warmup";

  return component::ok;
}

// Process the given spec and assign the given profile name to
// the associated list of functions.
// SPEC will be a list of specs separatyed by '|'. Each spec
// will be a list of function names separated by commas followed
// by a colon and then the name of the profile to associated with
// thos functions.
//
component::status
dynamic_configurator_component::add_profile_functions (const std::string& specs)
{
  component::status s = component::ok;
  vector<string> parts = tokenize (specs, "|");
  unsigned size = parts.size ();
  for (unsigned i = 0; i < size; ++i)
    {
      vector<string> spec = tokenize (parts[i], ":");
      if (spec.size () != 2)
	{
	  s = component::bad_value;
	  continue;
	}

      const string &profile = spec[1];
      vector<string> funcs = tokenize (spec[0], ",");
      unsigned num_funcs = funcs.size ();
      for (unsigned f = 0; f < num_funcs; ++f)
	function_configs[funcs[f]] = profile;
    }
  return s;
}

// Drive the config-result pin if the configuration has changed
void
dynamic_configurator_component::step_pin_handler (host_int_4)
{
  prev_config = current_config;

  for (component_relation_t::const_iterator it = clients.begin ();
       it != clients.end();
       ++it)
    (*it)->set_attribute_value ("configure!", config_specs[current_config]);

  //  cout << "configured for " << config_names[current_config] + "|" + config_specs[current_config] << endl;
}

// Search for the named configuration in the list of previously used ones.
// If found, drive the config-result pin with the index of that config.
// Otherwise add the new config and drive the pin with the new index.
component::status
dynamic_configurator_component::configure (const std::string& spec)
{
  vector<string> parts = tokenize (spec, "|");
  if (parts.size () != 2)
    return component::bad_value;

  // Drive config-result pin with old config regardless of whether it changes.
  config_result_pin.drive (prev_user_config);

  unsigned new_handle;
  component::status s = do_configure (parts[0], parts[1], new_handle);
  if (s == component::ok)
    {
      new_handle = set_syscall_config (new_handle);
      check_config_change (new_handle);
      config_error_pin.drive (0);
    }
  else
    config_error_pin.drive (1);

  return s;
}

component::status
dynamic_configurator_component::do_configure (const std::string &name, const std::string& config, unsigned &new_handle)
{
  // Identify and/or save the new configuration
  unsigned size = config_names.size ();
  unsigned handle;
  for (handle = 0; handle < size; handle++)
    {
      if (config_names[handle] == name)
	break;
    }
  if (handle >= size)
    {
      config_names.push_back (name);
      config_specs.push_back (config);
    }

  // If this is the first configuration, then also set the
  // default "<start>" config to this value.
  if (handle == 0
      || size == 1 && config_names[0] == "<start>")
    {
      config_names[0] = name;
      config_specs[0] = config;
    }

  new_handle = handle;
  return component::ok;
}

void
dynamic_configurator_component::configure_pin_handler (host_int_4 handle)
{
  // Drive config-result pin with old config regardless of whether it changes.
  config_result_pin.drive (prev_user_config);

  host_int_4 orig_handle = handle;
  handle = restore_config (handle);
  config_error_pin.drive (handle != orig_handle);
  handle = set_syscall_config (handle);
  check_config_change (handle);
}

unsigned
dynamic_configurator_component::restore_config (host_int_4 handle)
{
  if (handle >= config_specs.size ())
    return current_config;

  return handle;
}

unsigned
dynamic_configurator_component::set_syscall_config (unsigned handle)
{
  // For a real syscall, there will be at least 2 entries on the stack.
  unsigned size = config_stack.size ();
  if (size <= 1)
    return handle;

  // If the current function is _Sid_config, then change the config
  // of the function which called _Sid_config, otherwise change the
  // config of the function on the top of the stack.
  string top_func = config_stack.back ().first;
  unsigned top_handle = config_stack.back ().second;
  config_stack.pop_back ();

  if (top_func == "_Sid_config")
    {
      assert (size > 2);
      string next_func = config_stack.back ().first;
      config_stack.pop_back ();
      config_stack.push_back (pair<string,unsigned> (next_func, handle));
      config_stack.push_back (pair<string,unsigned> (top_func, top_handle));
      return top_handle;
    }

  config_stack.push_back (pair<string,unsigned> (top_func, handle));
  return handle;
}

void
dynamic_configurator_component::check_config_change (unsigned handle)
{
  if (handle != prev_user_config)
    {
      if (! in_function ("_Sid_config"))
	prev_user_config = handle;
    }

  if (current_config != handle
      && config_specs[current_config] != config_specs[handle])
    {
      current_config = handle;
      step_control_pin.drive (1); // reconfigure during next cycle
    }
}

void
dynamic_configurator_component::function_caller_pin_handler (host_int_4 addr)
{
  if (! loader)
    return;

  // Drive the address on the function-address pin and read the
  // resulting attribute value from the loader.
  function_address_pin.drive (addr);
  string function = loader->attribute_value("current-function");

  // If there is no config on the stack, or it is for a different function,
  // we must have jumped into this function. Treat it as if it was called.
  if (config_stack.size() == 0 || config_stack.back ().first != function)
    function_callee_pin_handler (addr);
}

void
dynamic_configurator_component::function_jump_pin_handler (host_int_4 addr)
{
  if (! loader)
    return;

  // Drive the address on the function-address pin and read the
  // resulting attribute value from the loader.
  function_address_pin.drive (addr);
  string function = loader->attribute_value("current-function");

  // If the current function is on the stack, then assume we're
  // returning to it, otherwise assume we're calling it.
  for (vector < pair<string,unsigned> >::const_iterator it = config_stack.begin ();
       it != config_stack.end ();
       ++it)
    {
      if (it->first == function)
	{
	  function_return_pin_handler (addr);
	  return;
	}
    }
  function_callee_pin_handler (addr);
}

void
dynamic_configurator_component::function_callee_pin_handler (host_int_4 addr)
{
  if (! loader)
    return;

  // Drive the address on the function-address pin and read the
  // resulting attribute value from the loader.
  function_address_pin.drive (addr);
  string function = loader->attribute_value("current-function");
  if (function.empty ())
    return;

  unsigned new_config = current_config;
  // Make sure that the main component has been related to us.
  if (main)
    {
      component::status s = component::not_found;
      // If we are in a function called from _Sid_config, then
      // use the config for _Sid_config (which will be sid-internal-warmup).
      // Otherwise, look for the function name in function_configs. This mapping will provide
      // the name of the config spec to be used. We can then use that to obtain
      // the config handle. If there is no function associated with the given address
      // or if there has been no config associated with that function, then use the
      // current_config.
      if (in_function ("_Sid_config"))
	s = main->set_attribute_value ("lookup-dynamic-config!", "sid-internal-warmup");
      else
	{
	  map<string,string>::const_iterator it = function_configs.find (function);
	  if (it != function_configs.end())
	    {
	      // Set main's lookup-dynamic-config attribute with the name we're looking
	      // for. main will then write the configuration string into its
	      // found-config-profile attribute if it is found.
	      s = main->set_attribute_value ("lookup-dynamic-config!", it->second);
	    }
	}
      if (s == component::ok)
	{
	  // Get the config spec and configure using it. Don't use 'configure'
	  // because we want that to be used for the syscall only.
	  string spec = main->attribute_value ("found-dynamic-config");
	  vector<string> parts = tokenize (spec, "|");
	  assert (parts.size () == 2);
	  do_configure (parts[0], parts[1], new_config);
	}
    }

  // Push the function name and config name onto the stack
  config_stack.push_back (pair<string,unsigned> (function, new_config));
  check_config_change (new_config); // has been updated
  //  cout << "called function '" << function << "' has config " << config_names[current_config] << "|" << config_specs[current_config] << endl;
}

void
dynamic_configurator_component::function_return_pin_handler (host_int_4 addr)
{
  if (! loader)
    return;

  // Drive the address on the function-address pin and read the
  // resulting attribute value from the loader.
  function_address_pin.drive (addr);
  string function = loader->attribute_value("current-function");
  if (function.empty ())
    return;

  // Pop the function stack until the one we're returning to is on top
  // or until we've reached the entry for the start.
  assert (config_stack.size () >= 1);
  if (config_stack.size () > 1)
    {
      config_stack.pop_back ();
      while (config_stack.size () > 1)
	{
	  if (config_stack.back ().first == function)
	    break;
	  config_stack.pop_back ();
	}
    }

  unsigned new_config = config_stack.back ().second;
  function = config_stack.back ().first;

  // Reconfigure to the saved configuration
  new_config = restore_config (new_config);
  check_config_change (new_config);

  //  cout << "returned to '" << function << "' with config " << config_names[current_config] << "|" << config_specs[current_config] << endl;
}

bool
dynamic_configurator_component::in_function (const string &name)
{
  vector< pair<string,unsigned> >::const_iterator it;
  for (it = config_stack.begin (); it != config_stack.end (); ++it)
    {
      if (it->first == name)
	return true;
    }
  return false;
}

// -----------------------------------------------------------------------
static
vector<string>
compConfigListTypes()
{
  vector<string> types;
  // NB: correlate with type cfgroot_component ctor!
  types.push_back("sid-control-cfgroot");
  types.push_back("sid-control-dynamic-configurator");
  return types;
}


static
component*
compConfigCreate(const string& typeName)
{
  if(typeName == "sid-control-cfgroot")
    return new cfgroot_component();
  if(typeName == "sid-control-dynamic-configurator")
    return new dynamic_configurator_component();
  return 0;
}


static
void
compConfigDelete(component* c)
{
  cfgroot_component* c1 = dynamic_cast<cfgroot_component*>(c);
  if (c1) { delete c1; return; }
  dynamic_configurator_component* c2 = dynamic_cast<dynamic_configurator_component*>(c);
  if (c2) { delete c2; return; }
}


// static object
DLLEXPORT extern const component_library config_component_library;

const component_library config_component_library =
{
  COMPONENT_LIBRARY_MAGIC,
  & compConfigListTypes, 
  & compConfigCreate,
  & compConfigDelete
};
