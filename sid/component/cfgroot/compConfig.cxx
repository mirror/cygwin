// compConfig.cxx - The cfgroot component: configuration parsing, root
// of component creation and management.  -*- C++ -*-

// Copyright (C) 1999-2001 Red Hat.
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
  virtual ~cfgroot_component();

protected:
  host_int_8 activity_count;
  bool running;
  void run (host_int_4); // run top-level simulation loop
  void stop (host_int_4); // stop top-level simulation loop

  // config-file! and config-line! virtual attribute handlers
  component::status configure(const std::string&);
  component::status configure_line(const std::string&);
  string nothing ();

  // parser
  string config_file;
  unsigned line_num;
  bool parse(istream&);
  string current_token;
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

  // a general purpose method for emitting error messages
  // FIXME: i18n
  void emit_error(const string& msg);

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
		{
		  emit_error(string("invalid character [") + 
			     make_numeric_attribute(host_int_2((unsigned char) ch),
						    ios::hex|ios::showbase) +
			     string("] ignored."));
		}
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
	  emit_error(string("invalid character [") + 
		     make_numeric_attribute(host_int_2((unsigned char) ch),
					    ios::hex|ios::showbase) +
		     string("] ignored."));
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
    }
  return cumulative_ok;
}


std::string
cfgroot_component::nothing()
{
  return "";
}


component::status
cfgroot_component::configure(const std::string& name)
{
  string last_config_file = this->config_file;
  this->config_file = name;
  if (this->config_file_history != "")
    this->config_file_history += ", ";
  this->config_file_history += this->config_file;
  unsigned last_line_num = this->line_num;
  this->line_num = 1;

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


cfgroot_component::cfgroot_component():
  recursion_limited ("running", 1),
  running (false),
  config_file ("<none>"),
  line_num(1),
  run_pin(this, & cfgroot_component::run),
  stop_pin(this, & cfgroot_component::stop),
  verbose_p (false),
  autoprint_p (true),
  persistent_p (false)
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

  add_pin("stop!", & this->stop_pin);
  add_attribute("stop!", & this->stop_pin, "pin");
  add_pin("stopping", & this->stopping_pin);
  add_attribute("stopping", & this->stopping_pin, "pin");

  add_attribute_virtual ("config-file!", this,
			 & cfgroot_component::configure,
			 & cfgroot_component::nothing);
  add_attribute_virtual ("config-line!", this,
			 & cfgroot_component::configure_line,
			 & cfgroot_component::nothing);
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


cfgroot_component::~cfgroot_component() 
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
cfgroot_component::stop(host_int_4)
{
  this->running = false;
}


void
cfgroot_component::run(host_int_4)
{
  recursion_record running (this);
  if (! running.ok())
    return;

  // check for time bomb expiration
  time_t timebomb = SID_TIMEBOMB;
  if (timebomb != 0)
    {
      time_t now = time (0);
#ifdef HAVE_CTIME
      const char* timebomb_formatted = ctime (& timebomb);
#else
#error "Need ctime!"
#endif

      if (now > timebomb)
	{
	  cerr << "SID license has expired at " << timebomb_formatted << flush;
	  return;
	}
      else if (this->verbose_p)
	{
	  cerr << "SID license will expire at " << timebomb_formatted << flush;
	}
    }

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
  if ((dso_name.length() > 3) &&
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
    dl_handle = lt_dlopen(NULL); // component library linked into executable

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

static
vector<string>
compConfigListTypes()
{
  vector<string> types;
  // NB: correlate with type cfgroot_component ctor!
  types.push_back("sid-control-cfgroot");
  return types;
}


static
component*
compConfigCreate(const string& typeName)
{
  if(typeName == "sid-control-cfgroot")
    return new cfgroot_component();
  else
    return 0;
}


static
void
compConfigDelete(component* c)
{
  delete dynamic_cast<cfgroot_component*>(c);
}


// static object
extern const component_library config_component_library;

const component_library config_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compConfigListTypes, 
  & compConfigCreate,
  & compConfigDelete
};
