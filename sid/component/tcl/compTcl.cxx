// compTcl.cxx - Tcl bridge component.  -*- C++ -*-

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

#ifdef __CYGWIN__
#include <sys/cygwin.h>
#endif

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>


extern "C"
{
#ifdef HAVE_TCL_H
#include <tcl.h>
#else
#define DISABLE_THIS_COMPONENT
#endif

#ifdef HAVE_TK_H
#include <tk.h>
#endif

#ifdef HAVE_BLT_H
#include <blt.h>
extern int Blt_Init _ANSI_ARGS_ ( (Tcl_Interp *interp));
#endif
}


// Sometimes the header is available, but not the library.  We must disable
// blt in this case.
#if defined(HAVE_BLT_H) && defined(HAVE_LIBBLT)
#define USE_BLT
#else
#undef USE_BLT
#endif


#ifdef DISABLE_THIS_COMPONENT
#warning "This component library is empty."
#endif


namespace tcl_api_component
{
  using std::string;
  using std::vector;
  using std::map;
  using std::pair;
  using std::runtime_error;
  using std::cerr;
  using std::endl;

  using sid::bus;
  using sid::pin;
  using sid::component;
  using sid::host_int_1;
  using sid::host_int_2;
  using sid::host_int_4;
  using sid::host_int_8;
  using sid::little_int_1;
  using sid::little_int_2;
  using sid::little_int_4;
  using sid::little_int_8;
  using sid::big_int_1;
  using sid::big_int_2;
  using sid::big_int_4;
  using sid::big_int_8;

  using sidutil::callback_pin;
  using sidutil::output_pin;
  using sidutil::make_attribute;
  using sidutil::make_numeric_attribute;
  using sidutil::parse_attribute;
  using sidutil::bijection;
  using sidutil::std_error_string;
  using sidutil::tokenize;
  using sidutil::sid_file_search_path;


#ifndef DISABLE_THIS_COMPONENT


  // -----------------------------------------------------------------

  // forward decl
  string extract_string (Tcl_Obj* const obj);
  Tcl_Obj* make_object (const string& str);


  // Instances of this class generate unique IDs for objects on the
  // fly.  It's useful as a type-safe lookup table for pointers where
  // the precise id is not important (as long as it's unique).
  template <class Obj>
  class string_auto_lut: public bijection<string,Obj>
  {
    string id_prefix;
    unsigned last_index;

  public:
    string_auto_lut (const string& prefix): id_prefix (prefix), last_index (0) {}

    // Find Obj by id.  Return a blank Obj () instance if not found.
    Obj lookup (const string& id);

    // Find id by Obj.  Assign new unique ID if necessary.
    string lookup (const Obj& obj);
  };


  template <class Obj>
  string string_auto_lut<Obj>::lookup (const Obj& obj)
{
  string id;
  
  bool found = this->find (obj, id);
  if (found)
    return id;
  else
    {
      // new object to register!
      this->last_index ++;
      id = this->id_prefix + make_numeric_attribute (this->last_index);
      this->add (id, obj);
      return id;
    }
}


  template <class Obj>
  Obj string_auto_lut<Obj>::lookup (const string& id)
{
  Obj obj;
  
  bool found = this->find (id, obj);
  if (found)
    return obj;
  else
    return Obj ();
}




  // -------------------------------------------------------------------------

  // tcl component proxy object

  // NB: the constructor may throw an exception if the embedded tcl interpreter
  // fails to "boot".

  class tcl_component: public component
  {
  protected:
    // the interpreter itself 
    mutable Tcl_Interp* interp;

    // members exposed via component API
    callback_pin<tcl_component> event_pin;
    output_pin event_control_pin;
    host_int_4 poll_interval;

    // tables for mapping sid:: pointers <-> tcl id-strings
    mutable string_auto_lut<component*> component_lut;
    mutable string_auto_lut<bus*> bus_lut;
    mutable string_auto_lut<pin*> pin_lut;

    // tables for mapping enumerations
    bijection<string,sid::bus::status> bus_status_lut;
    bijection<string,sid::component::status> component_status_lut;

    // callback functions
    void event_pin_driven (host_int_4);
    void run_last_command ();

    void register_callbacks ();

  public:

    string encode_pin_handle (pin* p) const;
    pin* decode_pin_handle (const string& str) const;
    string encode_bus_handle (bus* p) const;
    bus* decode_bus_handle (const string& str) const;
    string encode_component_handle (component* p) const;
    string encode_component_handle (const component* p) const;
    component* decode_component_handle (const string& str) const;
    string encode_component_status (component::status p) const;
    component::status decode_component_status (const string& str) const;
    string encode_bus_status (bus::status p) const;
    bus::status decode_bus_status (const string& str) const;
    void tcl_component_ctor_0 ();

  public:
    tcl_component (): 
      event_pin (this, & tcl_component::event_pin_driven),
      component_lut ("sid-component#"),
      bus_lut ("sid-bus#"),
      pin_lut ("sid-pin#")
      {
	this->interp = Tcl_CreateInterp ();
	if (this->interp == 0)
	  throw runtime_error ("Cannot Tcl_CreateInterp");

	// Encourage tcl to find the rest of itself.  The "sid"
	// literal should really be the argv[0] of the enclosing
	// process, but we don't have that information here, so we
	// guess.
	char* sep = getenv ("SID_EXEC_PREFIX"); // install-time configuration
#ifdef HAVE_CYGWIN_CONV_TO_FULL_POSIX_PATH
	char conv_fn[PATH_MAX*2];
	if (sep)
	  {
	    int rc = cygwin_conv_to_full_posix_path (sep, conv_fn);
	    if (rc != 0)
	      cerr << "tcl-bridge: cygwin_conv_to_full_posix_path failed: " 
		   << std_error_string () << endl;
	    else
	      sep = conv_fn;
	  }
#endif
	if (!sep) sep = SID_EXEC_PREFIX; // build-time configuration
	string sepsid = string(sep) + "/bin/sid";
	(void) Tcl_FindExecutable (const_cast<char*>(sepsid.c_str ()));
	
	// XXX: deallocate this->interp upon following failures, before
	// throw (). It would be better to encapsulate the tcl interpreter
	// in its own C++ object.

	if (Tcl_Init (this->interp) == TCL_ERROR)
	  throw runtime_error (Tcl_GetStringResult (this->interp));

	if (Tcl_PkgRequire (this->interp, "Tcl", TCL_VERSION, 0) == NULL)
	  throw runtime_error (Tcl_GetStringResult (this->interp));

	tcl_component_ctor_0 ();
      }

    ~tcl_component ()
      {
	// XXX: kill buses?, pins?
	if (interp)
	  Tcl_DeleteInterp (interp);
      }

  protected:
    
    friend class tcl_bus;
    friend class tcl_pin;

    // out-of-line utility functions
    string call_scalar (const string& cmd) const throw ();
    bool call_void (const string& cmd) const throw ();
    vector<string> call_vector (const string& cmd) const throw ();
    string quote (const string& s) const throw ();


    // PART 3.2: attributes (SUPERVISORY)
  public:
    vector<string> attribute_names () throw ()
      {
	// NB: Don't list "load!" or "eval!" attributes here.
	vector<string> names = call_vector ("attribute_names");
	return names;
      }


    vector<string> attribute_names (const string& category) throw ()
      {
	// NB: Don't list "load!" for transparency.
	vector<string> names = call_vector ("attribute_names_in_category " +
					   quote (category));
	return names;
      }


    string attribute_value (const string& name) throw ()
      {
	return (call_scalar ("attribute_value " 
			    + quote (name)));
      }


    component::status
    set_attribute_value (const string& name, const string& value) throw ()
      {
	if (name == "load!")
	  {
	    // load a tcl component script
	    string filename = value.substr (value.find (':')+1);
	    
#ifdef SIDTCL_MAP_CYGWIN_NAMES
	    // Map name to Win32 form.
	    const char* fn = filename.c_str ();
	    char conv_fn[PATH_MAX*2];
	    int rc = -1;
#ifdef HAVE_CYGWIN_CONV_TO_FULL_WIN32_PATH
	    rc = cygwin_conv_to_full_win32_path (fn, conv_fn);
#else
#error "Cannot convert cygwin->win32 paths!"
#endif
	    if (rc != 0)
	      cerr << "tcl-bridge: cygwin_conv_to_full_win32_path failed: " 
		   << std_error_string () << endl;
	    else
	      filename = string (conv_fn);
#endif

	    // XXX: Could use Tcl_EvalFile() instead.
	    bool ok = call_void ("source " + quote (filename));
	    return ok ? component::ok : component::bad_value;
	  }
	else if (name == "eval!")
	  {
	    bool ok = call_void (value);
	    return ok ? component::ok : component::bad_value;
	  }
	else
	  {
	    string result = call_scalar ("set_attribute_value "
					+ quote (name) + " "
					+ quote (value));
	    return (decode_component_status (result));
	  }
      }


    // PART 3.3: pins (SUPERVISORY)
  public:
    vector<string> 
    pin_names () throw ()
      {
	// NB: don't include !event and !event-control for transparency.
	return call_vector ("pin_names"); 
      }


    pin* 
    find_pin (const string& name) throw ()
      {
	if (name == "!event")
	  return & this->event_pin;
	else
	  return (decode_pin_handle (call_scalar ("find_pin "
						+ quote (name))));
      }

    component::status
    connect_pin (const string& name, pin* pin) throw ()
      {
	if (name == "!event-control")
	  {
	    this->event_control_pin.connect (pin);
	    return component::ok;
	  }
	else
	  {
	    string res = call_scalar ("connect_pin "
				     + quote (name) + " " 
				     + encode_pin_handle (pin));
	    return decode_component_status (res);
	  }
      }


    component::status
    disconnect_pin (const string& name, pin* pin) throw ()
      {
	if (name == "!event-control")
	  {
	    return this->event_control_pin.disconnect (pin);
	  }
	else
	  {
	    string res = call_scalar ("disconnect_pin "
				     + quote (name) + " " 
				     + encode_pin_handle (pin));
	    return decode_component_status (res);
	  }
      }


    vector<pin*> 
    connected_pins (const string& name) throw ()
      {
	if (name == "!event-control")
	  return this->event_control_pin.connections ();
	else
	  {
	    vector<string> handles = call_vector ("connected_pins " 
						 + quote (name));
	    vector<pin*> pins;
	    for (vector<string>::const_iterator it = handles.begin ();
		it != handles.end ();
		it++)
	      {
		pin* p = decode_pin_handle (*it);
		if (p != 0)
		  pins.push_back (p);
	      }
	    return pins;
	  }
      }



    // PART 3.4: buses & accessors (SUPERVISORY)
  public:
    vector<string> 
    bus_names () throw ()
      {
	return (call_vector ("bus_names"));
      }


    bus*
    find_bus (const string& name) throw ()
      {
	return (decode_bus_handle (call_scalar ("find_bus "
					      + quote (name))));
      }


    vector<string> 
    accessor_names () throw ()
      {
	return (call_vector ("accessor_names"));
      }


    component::status
    connect_accessor (const string& name, bus* bus) throw ()
      {
	string result = call_scalar ("connect_accessor "
				    + quote (name) + " "
				    + encode_bus_handle (bus));
	return (decode_component_status (result));
      }

    component::status
    disconnect_accessor (const string& name, bus* bus) throw () 
      {
	string result = call_scalar ("disconnect_accessor "
				     + quote (name) + " "
				     + encode_bus_handle(bus));
	return (decode_component_status (result));
      }

    bus* connected_bus (const string& name) throw ()
      {
	return (decode_bus_handle (call_scalar ("connected_bus "
					      + quote (name))));
      }


    vector<string> 
    relationship_names () throw ()
      {
	vector<string> rels = call_vector ("relationship_names");
	return rels;
      }


    component::status
    relate (const string& rel, component* comp)
      throw ()
      {
	string cmd = "relate " + quote (rel) + " " + quote (encode_component_handle (comp));
	string result = call_scalar (cmd);
	return (decode_component_status (result));
      }


    component::status
    unrelate (const string& rel, component* comp)
      throw ()
      {
	string cmd = "unrelate " + quote (rel) + " " + quote (encode_component_handle (comp));
	string result = call_scalar (cmd);
	return (decode_component_status (result));
      }


    vector<component*>
    related_components (const string& rel) throw ()
      { 
	vector<component*> comps;
	vector<string> rels = call_vector ("related_components " 
					  + quote (rel));
	for (vector<string>::iterator it = rels.begin ();
	    it != rels.end ();
	    it++)
	  {
	    component* comp = decode_component_handle (*it);
	    if (comp != 0)
	      comps.push_back (comp);
	  }
	return comps;
      }
  };



// out-of-line functions

string
tcl_component::encode_pin_handle (pin* p) const
{ return this->pin_lut.lookup (p); }

pin* 
tcl_component::decode_pin_handle (const string& str) const
{ return this->pin_lut.lookup (str); }

string
tcl_component::encode_bus_handle (bus* p) const
{ return this->bus_lut.lookup (p); }

bus*
tcl_component::decode_bus_handle (const string& str) const
{ return this->bus_lut.lookup (str); }

string
tcl_component::encode_component_handle (component* p) const
{ return this->component_lut.lookup (p); }

string 
tcl_component::encode_component_handle (const component* p) const
{ return this->component_lut.lookup (const_cast<component*> (p)); }

component* 
tcl_component::decode_component_handle (const string& str) const
{ return this->component_lut.lookup (str); }

string 
tcl_component::encode_component_status (component::status p) const
{ 
  string id;
  bool found = this->component_status_lut.find (p, id);
  if (found)
    return id;
  else
    return "?";
}

component::status 
tcl_component::decode_component_status (const string& str) const
{ 
  component::status id;
  bool found = this->component_status_lut.find (str, id);
  if (found)
    return id;
  else
    return component::bad_value; // misc error
}

string
tcl_component::encode_bus_status (bus::status p) const
{ 
  string id;
  bool found = this->bus_status_lut.find (p, id);
  if (found)
    return id;
  else
    return "?";
}

bus::status 
tcl_component::decode_bus_status (const string& str) const
{ 
  bus::status id;
  bool found = this->bus_status_lut.find (str, id);
  if (found)
    return id;
  else
    return bus::unpermitted; // misc error
}


void
tcl_component::tcl_component_ctor_0 ()
{
  this->register_callbacks ();
  
  this->bus_status_lut.add (bus::ok, "ok");
  this->bus_status_lut.add (bus::misaligned, "misaligned");
  this->bus_status_lut.add (bus::unmapped, "unmapped");
  this->bus_status_lut.add (bus::unpermitted, "unpermitted");
  this->bus_status_lut.add (bus::delayed, "delayed");
  
  this->component_status_lut.add (component::ok, "ok");
  this->component_status_lut.add (component::not_found, "not_found");
  this->component_status_lut.add (component::bad_value, "bad_value");

  this->poll_interval = 100; // initial poll interval
}

string
tcl_component::call_scalar (const string& cmd) const throw ()
{
  assert (this->interp);

  Tcl_Obj* cmdobj = make_object (cmd);
  assert (cmdobj);
  int rc = Tcl_EvalObj (this->interp, cmdobj);
  Tcl_DecrRefCount (cmdobj);
  string result = extract_string (Tcl_GetObjResult (interp));
  if (rc != TCL_OK)
    {
      cerr << "TCL ERROR: " << result << endl;
      result = "";
    }

  return result;
}


bool
tcl_component::call_void (const string& cmd) const throw ()
{
  assert (this->interp);

  Tcl_Obj* cmdobj = make_object (cmd);
  assert (cmdobj);
  int rc = Tcl_EvalObj (this->interp, cmdobj);
  Tcl_DecrRefCount (cmdobj);
  if (rc != TCL_OK)
    {
      string result = extract_string (Tcl_GetObjResult (interp));
      cerr << "TCL ERROR: " << result << endl;
      return false;
    }
  return true;
}


vector<string> 
tcl_component::call_vector (const string& cmd) const throw ()
{
  assert (this->interp);

  Tcl_Obj* cmdobj = make_object (cmd);
  assert (cmdobj);
  int rc = Tcl_EvalObj (this->interp, cmdobj);
  Tcl_DecrRefCount (cmdobj);
  Tcl_Obj* result = Tcl_GetObjResult (interp);
  if (rc != TCL_OK)
    {
      string res2 = extract_string (result);
      cerr << "TCL ERROR: " << res2 << endl;
      return vector<string> ();
    }

  int result_length;
  vector<string> result_vector;
  Tcl_ListObjLength (interp, result, & result_length);
  for (int i=0; i<result_length; i++)
    {
      Tcl_Obj* element;
      Tcl_ListObjIndex (interp, result, i, & element);
      result_vector.push_back (extract_string (element));
      // [don't] Tcl_DecrRefCount (element); -- this is inappropriate for Tcl_ListObjIndex
    }

  return result_vector;
}


// quote the given string for safe passage through tcl parser
string
tcl_component::quote (const string& s) const throw ()
{
  if (s.size() == 0)
    return "{}";

  string escaped;
  for (unsigned i=0; i < s.size (); i++)
    {
      // convert characters to \xHH notation.
      char c = s[i];
      escaped += "\\x";
      escaped += "0123456789ABCDEF"[(c >> 4) & 15];
      escaped += "0123456789ABCDEF"[c & 15];
    }

  // cerr << "quote (``" << s << "'') => ``" << escaped << "''" << endl;
  return escaped;
}



  // ------------------------------------------------------------------------
  // utility conversion functions


  string
  extract_string (Tcl_Obj* const obj)
{
  int num_bytes;
  const char* bytes = Tcl_GetStringFromObj (obj, & num_bytes);
  assert (num_bytes >= 0);
  if (num_bytes == 0)
    return string ();
  else
    return string (bytes, num_bytes);
  // cerr << "extract_string ``" << s << "''" << endl;
}


  Tcl_Obj*
  make_object (const string& str)
{
  // cerr << "make_object ``" << str << "''" << endl;
  Tcl_Obj* o;
  if (str.length() == 0)
    o = Tcl_NewStringObj ("", 0);
  else
    o = Tcl_NewStringObj (const_cast<char*> (str.data ()), str.length ());
  Tcl_IncrRefCount (o);
  // must Tcl_DecrRefCount () after use!
  return o;
}




  // ------------------------------------------------------------------------
  // tcl component command callbacks

  // Sorry about the cut & paste job.  There should exist a nice little stub
  // generator.


int
sid_comp_this (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 1)
    {
      Tcl_SetResult (interp, "Need 0 args", TCL_STATIC);
      return TCL_ERROR;
    }

  string handle = comp->encode_component_handle (comp);

  Tcl_Obj* hobj = make_object (handle);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_list_attr_names (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 2)
    {
      Tcl_SetResult (interp, "Need 1 arg", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  vector<string> names = c->attribute_names ();

  Tcl_ResetResult (interp);
  for (unsigned i=0; i<names.size (); i++)
    Tcl_AppendElement (interp, const_cast<char*> (names[i].c_str ()));

  return TCL_OK;
}


int
sid_comp_list_attr_names_in_category (ClientData cdata, Tcl_Interp* interp,
				      int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 arg", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }
  string category = extract_string (objv[2]);
  
  vector<string> names = c->attribute_names (category);

  Tcl_ResetResult (interp);
  for (unsigned i=0; i<names.size (); i++)
    Tcl_AppendElement (interp, const_cast<char*> (names[i].c_str ()));

  return TCL_OK;
}


int
sid_comp_get_attr_value (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string value = c->attribute_value (extract_string (objv[2]));

  Tcl_Obj* hobj = make_object (value);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_set_attr_value (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status stat = c->set_attribute_value (extract_string (objv[2]), extract_string (objv[3]));
  string code = comp->encode_component_status (stat);
  
  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_list_pin_names (ClientData cdata, Tcl_Interp* interp, 
			int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 2)
    {
      Tcl_SetResult (interp, "Need 1 arg", TCL_STATIC);
      return TCL_ERROR;
    }
  
  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }
 
  vector<string> names = c->pin_names ();
  
  Tcl_ResetResult (interp);
  for (unsigned i=0; i<names.size (); i++)
    Tcl_AppendElement (interp, const_cast<char*> (names[i].c_str ()));
  
  return TCL_OK;
}


int
sid_comp_get_pin (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  pin* p = c->find_pin (extract_string (objv[2]));
  if (p == 0)
    {
      Tcl_SetResult (interp, "", TCL_STATIC);
      return TCL_OK;
    }

  string handle = comp->encode_pin_handle (p);

  Tcl_Obj* hobj = make_object (handle);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_connect_pin (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string pin_name = extract_string (objv[2]);

  pin* p = comp->decode_pin_handle (extract_string (objv[3]));
  if (p == 0)
    {
      Tcl_SetResult (interp, "Invalid pin handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status stat = c->connect_pin (pin_name, p);

  string code = comp->encode_component_status (stat);

  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_disconnect_pin (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string pin_name = extract_string (objv[2]);

  pin* p = comp->decode_pin_handle (extract_string (objv[3]));
  if (p == 0)
    {
      Tcl_SetResult (interp, "Invalid pin handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status stat = c->disconnect_pin (pin_name, p);

  string code = comp->encode_component_status (stat);

  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_list_connected_pins (ClientData cdata, Tcl_Interp* interp, 
			      int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  vector<pin*> neighbours = c->connected_pins (extract_string (objv[2]));

  Tcl_ResetResult (interp);
  for (unsigned i=0; i<neighbours.size (); i++)
    {
      string handle = comp->encode_pin_handle (neighbours[i]);
      Tcl_AppendElement (interp, const_cast<char*> (handle.c_str ()));
    }

  return TCL_OK;
}



int
sid_comp_list_bus_names (ClientData cdata, Tcl_Interp* interp,
			 int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 2)
    {
      Tcl_SetResult (interp, "Need 1 arg", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }
  
  vector<string> names = c->bus_names ();
  
  Tcl_ResetResult (interp);
  for (unsigned i=0; i<names.size (); i++)
    Tcl_AppendElement (interp, const_cast<char*> (names[i].c_str ()));
  
  return TCL_OK;
}


int
sid_comp_find_bus (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  bus* b = c->find_bus (extract_string (objv[2]));
  if (b == 0)
    {
      Tcl_SetResult (interp, "", TCL_STATIC);
      return TCL_OK;
    }

  string handle = comp->encode_bus_handle (b);

  Tcl_Obj* hobj = make_object (handle);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}



int
sid_comp_list_accessor_names (ClientData cdata, Tcl_Interp* interp,
			      int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 2)
    {
      Tcl_SetResult (interp, "Need 1 arg", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }
  
  vector<string> names = c->accessor_names ();
  
  Tcl_ResetResult (interp);
  for (unsigned i=0; i<names.size (); i++)
    Tcl_AppendElement (interp, const_cast<char*> (names[i].c_str ()));
  
  return TCL_OK;
}


int
sid_comp_get_accessor (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  bus* b = c->connected_bus (extract_string (objv[2]));
  if (b == 0)
    {
      Tcl_SetResult (interp, "", TCL_STATIC);
      return TCL_OK;
    }

  string handle = comp->encode_bus_handle (b);

  Tcl_Obj* hobj = make_object (handle);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_set_accessor (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string accessor_name = extract_string (objv[2]);
  bus* b = comp->decode_bus_handle (extract_string (objv[3]));
  if (b == 0)
    {
      Tcl_SetResult (interp, "Invalid bus handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status stat = c->connect_accessor (accessor_name, b);

  string code = comp->encode_component_status (stat);

  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}

int
sid_comp_unset_accessor (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult(interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle(extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }
  
  string accessor_name = extract_string (objv[2]);
  bus* b = comp->decode_bus_handle (extract_string (objv[3]));
  if (b == 0)
    {
      Tcl_SetResult (interp, "Invalid bus handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status stat = c->disconnect_accessor(accessor_name, b);

  string code = comp->encode_component_status(stat);

  Tcl_Obj* hobj = make_object(code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);
  
  return TCL_OK;
}

int
sid_comp_relationship_names (ClientData cdata, Tcl_Interp* interp,
			     int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 2)
    {
      Tcl_SetResult (interp, "Need 1 arg", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  vector<string> names = c->relationship_names ();

  Tcl_ResetResult (interp);
  for (unsigned i=0; i<names.size (); i++)
    Tcl_AppendElement (interp, const_cast<char*> (names[i].c_str ()));

  return TCL_OK;
}


int
sid_comp_relate (ClientData cdata, Tcl_Interp* interp,
		 int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string rel = extract_string (objv[2]);
  component* other = comp->decode_component_handle (extract_string (objv[3]));
  if (other == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status status = c->relate (rel, other);
  string code = comp->encode_component_status (status);
  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_comp_unrelate (ClientData cdata, Tcl_Interp* interp,
		   int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string rel = extract_string (objv[2]);
  component* other = comp->decode_component_handle (extract_string (objv[3]));
  if (other == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  component::status status = c->unrelate (rel, other);
  string code = comp->encode_component_status (status);
  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}



int
sid_comp_get_related_components (ClientData cdata, Tcl_Interp* interp, 
				 int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  component* c = comp->decode_component_handle (extract_string (objv[1]));
  if (c == 0)
    {
      Tcl_SetResult (interp, "Invalid component handle", TCL_STATIC);
      return TCL_ERROR;
    }

  string rel = extract_string (objv[2]);

  vector<component*> comps = c->related_components (rel);

  Tcl_ResetResult (interp);
  for (unsigned i=0; i<comps.size (); i++)
    {
      string handle = comp->encode_component_handle (comps[i]);
      Tcl_AppendElement (interp, const_cast<char*> (handle.c_str ()));
    }

  return TCL_OK;
}


// ------------------------------------------------------------------------
// tcl bus proxy object

class tcl_bus: public bus
{
  tcl_component* host;

public:
  tcl_bus (tcl_component* host): host (host) {}

  status write_any (const string& cmd, const string& args)
    {
      // cerr << cmd + " " + host->encode_bus_handle (this) + " " + args << endl;

      string res = host->call_scalar (cmd + " "
				     + host->encode_bus_handle (this) + " "
				     + args);
      // cerr << res << endl;

      return host->decode_bus_status (res);
    }

  pair<status,string> read_any (const string& cmd, const string& args)
    {
      vector<string> res = host->call_vector (cmd + " "
					     + host->encode_bus_handle (this) + " "
					     + args);
      if (res.size () != 2)
	return make_pair (bus::unpermitted, string ("0"));
      else
	return make_pair (host->decode_bus_status (res[0]), res[1]);
    }

// here is the dreaded Cartesian product.  

// Each bus::read is mapped to a call to the tcl procedure
// read_h4_[lb]Y BUS ADDRESS, for host_int_4/{little,big}_int_Y.  The tcl
// procedure should return a list "status value".

// Each bus::write is mapped to a call to the tcl procedure
// write_h4_[lb]Y BUS ADDRESS DATA, for host_int_4/{little,big}_int_Y.
// The tcl procedure should return "status".

status write (host_int_4 address, big_int_1 data) throw ()
{
  return this->write_any ("write_h4_b1", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, big_int_1& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_b1", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}


status write (host_int_4 address, big_int_2 data) throw ()
{
  return this->write_any ("write_h4_b2", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, big_int_2& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_b2", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}


status write (host_int_4 address, big_int_4 data) throw ()
{
  return this->write_any ("write_h4_b4", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, big_int_4& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_b4", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}

status write (host_int_4 address, big_int_8 data) throw ()
{
  return this->write_any ("write_h4_b8", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, big_int_8& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_b8", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}


status write (host_int_4 address, little_int_1 data) throw ()
{
  return this->write_any ("write_h4_l1", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, little_int_1& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_l1", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}



status write (host_int_4 address, little_int_2 data) throw ()
{
  return this->write_any ("write_h4_l2", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, little_int_2& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_l2", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}


status write (host_int_4 address, little_int_4 data) throw ()
{
  return this->write_any ("write_h4_l4", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}


status read (host_int_4 address, little_int_4& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_l4", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}


status write (host_int_4 address, little_int_8 data) throw ()
{
  return this->write_any ("write_h4_l8", 
			 make_attribute (address)
			 + " " + 
			 make_attribute (data));
}
  


status read (host_int_4 address, little_int_8& data) throw ()
{
  pair<status,string> res = 
    this->read_any ("read_h4_l8", 
		   make_attribute (address));
  if (res.first == bus::ok)
    parse_attribute (res.second, data);

  return res.first;
}

};


// ------------------------------------------------------------------------
// tcl bus command callbacks

int
sid_bus_new (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  tcl_bus* bus = new tcl_bus (comp);
  // XXX: hold on to bus pointer for later disposal
  string bus_handle = comp->encode_bus_handle (bus);

  Tcl_Obj* hobj = make_object (bus_handle);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}



template <class AddrType, class DataType>
int
sid_bus_write_any (ClientData cdata, Tcl_Interp* interp,
		   int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 4)
    {
      Tcl_SetResult (interp, "Need 3 args", TCL_STATIC);
      return TCL_ERROR;
    }

  bus* b = comp->decode_bus_handle (extract_string (objv[1]));
  if (b == 0)
    {
      Tcl_SetResult (interp, "Invalid bus handle", TCL_STATIC);
      return TCL_ERROR;
    }

  DataType data;
  string datastr = extract_string (objv[3]);
  AddrType addr;
  string addrstr = extract_string (objv[2]);
  component::status s1 = parse_attribute (addrstr, addr);
  component::status s2 = parse_attribute (datastr, data);

  if (s1 != component::ok || s2 != component::ok)
    {
      string errormsg = string("Invalid address ") + addrstr + string(" or data ") + datastr;
      Tcl_SetResult (interp, const_cast<char*>(errormsg.c_str()), TCL_STATIC);
      return TCL_ERROR;
    }

  bus::status stat = b->write (addr, data);
  string code = comp->encode_bus_status (stat);

  Tcl_Obj* hobj = make_object (code);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_bus_write_h4_l1 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,little_int_1> (cdata, interp, objc, objv);
}

int
sid_bus_write_h4_l2 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,little_int_2> (cdata, interp, objc, objv);
}

int
sid_bus_write_h4_l4 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,little_int_4> (cdata, interp, objc, objv);
}

int
sid_bus_write_h4_l8 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,little_int_8> (cdata, interp, objc, objv);
}


int
sid_bus_write_h4_b1 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,big_int_1> (cdata, interp, objc, objv);
}

int
sid_bus_write_h4_b2 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,big_int_2> (cdata, interp, objc, objv);
}

int
sid_bus_write_h4_b4 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,big_int_4> (cdata, interp, objc, objv);
}

int
sid_bus_write_h4_b8 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_write_any<host_int_4,big_int_8> (cdata, interp, objc, objv);
}




template <class AddrType, class DataType>
int
sid_bus_read_any (ClientData cdata, Tcl_Interp* interp,
		  int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  bus* b = comp->decode_bus_handle (extract_string (objv[1]));
  if (b == 0)
    {
      Tcl_SetResult (interp, "Invalid bus handle", TCL_STATIC);
      return TCL_ERROR;
    }

  AddrType addr;
  string valuestr = extract_string (objv[2]);
  component::status s = parse_attribute (valuestr, addr);
  DataType data;

  if (s != component::ok)
    {
      string errormsg = string("Invalid address ") + valuestr;
      Tcl_SetResult (interp, const_cast<char*>(errormsg.c_str()), TCL_STATIC);
      return TCL_ERROR;
    }

  bus::status stat = b->read (addr, data);
  string code = comp->encode_bus_status (stat);
  string data_string = make_attribute (data);
  string result = code + " " + data_string;

  Tcl_Obj* hobj = make_object (result);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}


int
sid_bus_read_h4_l1 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,little_int_1> (cdata, interp, objc, objv);
}

int
sid_bus_read_h4_l2 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,little_int_2> (cdata, interp, objc, objv);
}

int
sid_bus_read_h4_l4 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,little_int_4> (cdata, interp, objc, objv);
}

int
sid_bus_read_h4_l8 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,little_int_8> (cdata, interp, objc, objv);
}


int
sid_bus_read_h4_b1 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,big_int_1> (cdata, interp, objc, objv);
}

int
sid_bus_read_h4_b2 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,big_int_2> (cdata, interp, objc, objv);
}

int
sid_bus_read_h4_b4 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,big_int_4> (cdata, interp, objc, objv);
}

int
sid_bus_read_h4_b8 (ClientData cdata, Tcl_Interp* interp,
		     int objc, Tcl_Obj* const objv[])
{
  return sid_bus_read_any<host_int_4,big_int_8> (cdata, interp, objc, objv);
}



// ------------------------------------------------------------------------
// tcl pin proxy object

class tcl_pin: public pin
{
  tcl_component* host;

public:
  tcl_pin (tcl_component* host): host (host) {}

  void driven (host_int_4 value) throw ()
    {
      host->call_scalar ("driven_h4 " + 
			host->encode_pin_handle (this) + " "
			+ make_attribute (value));
    }
}; // End of class tcl_pin



// ------------------------------------------------------------------------
// tcl pin command callbacks

int
sid_pin_new (ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  tcl_pin* pin = new tcl_pin (comp);
  // XXX: hold on to bus pointer for later disposal
  string pin_handle = comp->encode_pin_handle (pin);

  Tcl_Obj* hobj = make_object (pin_handle);
  Tcl_SetObjResult (interp, hobj);
  Tcl_DecrRefCount (hobj);

  return TCL_OK;
}



int
sid_pin_driven_h4 (ClientData cdata, Tcl_Interp* interp,
		   int objc, Tcl_Obj* const objv[])
{
  tcl_component* comp = reinterpret_cast<tcl_component*> (cdata);
  if (objc != 3)
    {
      Tcl_SetResult (interp, "Need 2 args", TCL_STATIC);
      return TCL_ERROR;
    }

  pin* p = comp->decode_pin_handle (extract_string (objv[1]));
  if (p == 0)
    {
      Tcl_SetResult (interp, "Invalid pin handle", TCL_STATIC);
      return TCL_ERROR;
    }
  host_int_4 value;
  string valuestr = extract_string (objv[2]);
  component::status s = parse_attribute (valuestr, value);

  if (s != component::ok)
    {
      string errormsg = string("Invalid value ") + valuestr;
      Tcl_SetResult (interp, const_cast<char*>(errormsg.c_str()), TCL_STATIC);
      return TCL_ERROR;
    }

  p->driven (value);
  return TCL_OK;
}




// -------------------------------------------------------------------------------



// Register callback functions with interpreter
void
tcl_component::register_callbacks ()
{
  ClientData this_ptr = static_cast<ClientData> (this);


  // sid::component calls
  Tcl_CreateObjCommand (this->interp, "sid::component::this", 
		       (Tcl_ObjCmdProc*) sid_comp_this, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::attribute_names", 
		       (Tcl_ObjCmdProc*) sid_comp_list_attr_names, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::attribute_names_in_category", 
		       (Tcl_ObjCmdProc*) sid_comp_list_attr_names_in_category, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::attribute_value", 
		       (Tcl_ObjCmdProc*) sid_comp_get_attr_value, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::set_attribute_value", 
		       (Tcl_ObjCmdProc*) sid_comp_set_attr_value, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::pin_names", 
		       (Tcl_ObjCmdProc*) sid_comp_list_pin_names, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::find_pin", 
		       (Tcl_ObjCmdProc*) sid_comp_get_pin, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::connect_pin", 
		       (Tcl_ObjCmdProc*) sid_comp_connect_pin, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::disconnect_pin", 
		       (Tcl_ObjCmdProc*) sid_comp_disconnect_pin, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::connected_pins", 
		       (Tcl_ObjCmdProc*) sid_comp_list_connected_pins, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::bus_names", 
		       (Tcl_ObjCmdProc*) sid_comp_list_bus_names, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::find_bus", 
		       (Tcl_ObjCmdProc*) sid_comp_find_bus, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::accessor_names", 
		       (Tcl_ObjCmdProc*) sid_comp_list_accessor_names, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::connected_bus", 
		       (Tcl_ObjCmdProc*) sid_comp_get_accessor, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::connect_accessor", 
		       (Tcl_ObjCmdProc*) sid_comp_set_accessor, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::disconnect_accessor",
			(Tcl_ObjCmdProc*) sid_comp_unset_accessor, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::relationship_names", 
		       (Tcl_ObjCmdProc*) sid_comp_relationship_names, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::relate", 
		       (Tcl_ObjCmdProc*) sid_comp_relate, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::unrelate", 
		       (Tcl_ObjCmdProc*) sid_comp_unrelate, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::component::related_components", 
		       (Tcl_ObjCmdProc*) sid_comp_get_related_components, this_ptr, NULL);
  

  // sid::bus calls
  Tcl_CreateObjCommand (this->interp, "sid::bus::new", 
		       (Tcl_ObjCmdProc*) sid_bus_new, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_l1", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_l1, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_b1", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_b1, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_l2", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_l2, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_b2", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_b2, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_l4", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_l4, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_b4", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_b4, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_l8", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_l8, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::write_h4_b8", 
		       (Tcl_ObjCmdProc*) sid_bus_write_h4_b8, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_l1", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_l1, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_b1", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_b1, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_l2", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_l2, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_b2", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_b2, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_l4", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_l4, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_b4", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_b4, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_l8", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_l8, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::bus::read_h4_b8", 
		       (Tcl_ObjCmdProc*) sid_bus_read_h4_b8, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::pin::new",
		       (Tcl_ObjCmdProc*) sid_pin_new, this_ptr, NULL);
  Tcl_CreateObjCommand (this->interp, "sid::pin::driven_h4", 
		       (Tcl_ObjCmdProc*) sid_pin_driven_h4, this_ptr, NULL);
}




void
tcl_component::event_pin_driven (host_int_4)
{
  // global function!
  host_int_4 count = 0;
  while (Tcl_DoOneEvent (TCL_ALL_EVENTS | TCL_DONT_WAIT) != 0)
    count ++;

  // adjust poll interval aggressively
  if (count > 0)
    this->poll_interval /= 2; // pump down by 50%
  else
    this->poll_interval += 1 + (this->poll_interval / 10);  // pump up by 10%+1
  // clamp between 1ms and 1000ms
  if (this->poll_interval < 1) this->poll_interval = 1;
  if (this->poll_interval > 1000) this->poll_interval = 1000;

  // cout << "count=" << count << " poll=" << this->poll_interval << endl;

  // update scheduler
  host_int_4 value = this->poll_interval; // irregular event
  this->event_control_pin.drive (value);
}



#ifdef HAVE_TK_H
class tk_component: public tcl_component
{
public:
  tk_component ()
    {
      int rc = Tk_Init (interp);
      if (rc != TCL_OK)
	throw runtime_error (Tcl_GetStringResult (this->interp));

      Tcl_StaticPackage (interp, "Tk", Tk_Init, Tk_SafeInit);
    }
};
#endif

#ifdef USE_BLT
class blt_component: public tk_component
{
public:
  blt_component ()
    {
      int rc = Blt_Init (this->interp);
      if (rc != TCL_OK)
	throw runtime_error (Tcl_GetStringResult (this->interp));
    }
};
#endif
      
#endif /* DISABLE_THIS_COMPONENT */


// Maps from component-type-name -> file name
typedef map<string,string> file_map_t;

file_map_t
scan_files (const string& dotless_extension)
{
  file_map_t files;
  string extension = string(".") + dotless_extension;

  vector<string> basic_search_directories = sid_file_search_path ();
  vector<string> search_directories;

  // Add both a ".../sidcomp" and a non-.../sidcomp item to the
  // list, in case we're looking in the source/build trees.
  // An alternative would be to plop the .tk/.tcl/.blt component
  // sources into a new subdirectory component/tcl/sidcomp.
  for (unsigned i=0; i<basic_search_directories.size(); i++)
    {
      search_directories.push_back (basic_search_directories[i] + "/sidcomp");
      search_directories.push_back (basic_search_directories[i]);
    }

#ifndef HAVE_OPENDIR
#error "Need opendir!"
#endif

  for (unsigned i=0; i<search_directories.size(); i++)
    {
      string search_dir = search_directories[i];
      const char* dname = search_dir.c_str();
      // cout << "Searching directory `" << dname << "'" << endl;

      DIR* d = opendir (dname);
      if (d == NULL) continue;

      // scan through directory
      for (struct dirent* de = readdir (d);
	   de != NULL;
	   de = readdir (d))
	{
	  string entry (de->d_name);
	  // cout << "Found entry `" << entry << "'" << endl;
	  
	  // see if this file has desired extension
	  if ((entry.size() > extension.size()) &&
	      (entry.substr (entry.size() - extension.size()) == extension))
	    {
	      string tn = entry.substr (0, entry.size() - extension.size());
	      string fpn = string(dname) + "/" + entry;

	      // cout << "Recorded matching type " << tn << endl;
	      files[tn] = fpn;
	    }
	}

      closedir (d);
    }

  return files;
}


void
add_known_files (const string& extension, vector<string>& output)
{
  // Don't look for these types of files if support is not compiled in.
#ifndef HAVE_TCL_H
  if (extension == "tcl") return;
#endif
#ifndef HAVE_TK_H
  if (extension == "tk") return; 
#endif
#ifndef USE_BLT
  if (extension == "blt") return;
#endif

  file_map_t files = scan_files (extension);

  for (file_map_t::iterator it = files.begin();
       it != files.end();
       it ++)
    {
      output.push_back (it->first);
      // it->second is the file name
    }
}


component*
try_making_component (const string& extension, const string& type)
{
  file_map_t files = scan_files (extension);

  file_map_t::iterator it = files.find (type);
  bool found_p = (it != files.end());
  string fname = found_p ? it->second : "-none-";

  component* bridge = 0;

#ifdef HAVE_TCL_H
  if (extension == "tcl" && found_p)
    bridge = new tcl_component ();
#endif
#ifdef HAVE_TK_H
  if (extension == "tk" && found_p)
    bridge = new tk_component ();
#endif
#ifdef USE_BLT
  if (extension == "blt" && found_p)
    bridge = new blt_component ();
#endif

  if (found_p && bridge)
    {
      // Load source file into bridge component
      component::status s = bridge->set_attribute_value ("load!", fname);
      if (s != component::ok)
	cerr << "bridge-" << extension
	     << " warning: autoload `" << fname << "' failed!" << endl; 
    }

  return bridge;  
}



static
vector<string>
list_types ()
{
  vector<string> types;

  add_known_files ("tcl", types);
  add_known_files ("tk", types);
  add_known_files ("blt", types);

  return types;
}


static
component*
create (const string& typeName)
{
  component* comp = 0;

  try
    {
      if (comp == 0) comp = try_making_component ("tcl", typeName);
      if (comp == 0) comp = try_making_component ("tk", typeName);
      if (comp == 0) comp = try_making_component ("blt", typeName);
    }
  catch (runtime_error& e)
    {
      cerr << e.what () << endl;;
      comp = 0;
    }
  catch (...)
    {
      comp = 0;
    }

  return comp;
}


static
void
do_delete (component* c)
{
#ifndef DISABLE_THIS_COMPONENT
  delete dynamic_cast<tcl_component*>(c);
#endif
}


}


// static object
extern const sid::component_library tcl_bridge_library;

const sid::component_library tcl_bridge_library DLLEXPORT = 
{
  sid::COMPONENT_LIBRARY_MAGIC,
  & tcl_api_component::list_types, 
  & tcl_api_component::create,
  & tcl_api_component::do_delete
};
