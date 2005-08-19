
#ifndef __baseCfg_h__
#define __baseCfg_h__

#include <sidcomp.h>
#include <sidso.h>
#include <sidattrutil.h>
#include <sidcomputil.h>
#include <string>
#include <iosfwd>

using namespace std;

typedef enum { in_pin, out_pin, bus, accessor, relater, related, attr } role;
typedef enum { src_to_dst, dst_to_src, both } direction;
typedef enum {instruction_count, simulated_cycles} gprof_type;

// we do compiler-firewall on these base types to avoid hauling in <vector>
// and <map> to anyone who is including us. strings seem ubiquitous enough
// that it's not worth doing for string-only cases.

struct ComponentCfg_impl;
struct AggregateCfg_impl;

class sid::component;

struct Writer 
{
  Writer (sid::component *c, const string filename);
  ~Writer();
  void write_line(string s);
  void write_file(string s);
  sid::component *main_component;
  ostream *out;
  bool out_is_file;
};

struct Writable 
{  
  virtual void write_to(Writer &w) = 0;
};

struct ResolvedName
{
  ResolvedName ();
  ResolvedName (const string t, const string s);
  string target;
  string slot;
};

class ComponentCfg 
{
public:
  ComponentCfg (const string n);
  virtual ~ComponentCfg();
  const string get_name();
  virtual void add_prefix (const string prefix);
  virtual void write_all (Writer &w);
  virtual void write_load (Writer &w) = 0;
  virtual void write_construct (Writer &w) = 0;
  virtual void write_config (Writer &w);
  virtual const ResolvedName resolve(const role r, const string name);
  void map_name (ComponentCfg *c, role r, 
		 const string outer, const string inner);
  void add_pre (Writable *w);
  void add_post (Writable *w);
  void write_pre (Writer &w);
  void write_post (Writer &w);
  void conn_pin (ComponentCfg *src, const string srcport, 
		 ComponentCfg *dst, const string dstport, 
		 const direction dir = src_to_dst,
		 bool virt = true);
  void conn_bus (ComponentCfg *src, 
		 const string srcport,
		 ComponentCfg *dst, 
		 const string dstport,
		 bool virt = true);
  void set (ComponentCfg *targ, 
	    const string attr, 
	    const string val,
	    bool virt = true);
  void relate (ComponentCfg *relater, 
	       const string relationship, 
	       ComponentCfg *related,
	       bool virt = true);
protected:  
  string my_name;
  ComponentCfg_impl *c_impl;
};

class AtomicCfg :
virtual public ComponentCfg
{
 public:
  AtomicCfg (const string name, const string complib, 
	     const string compsym, const string comptype);
  virtual ~AtomicCfg(); 
  virtual void add_prefix (const string prefix);
  virtual void write_load (Writer &w);
  virtual void write_construct (Writer &w);
  static void reset_load_map ();
  static AtomicCfg *wrap_component (const string name);
  static AtomicCfg *possible_wrap_name (const string &comp_name);
  string comp_type () const { return my_comptype; }
  bool wrapped () const { return my_wrapped; }
  bool possibly_wrapped () const { return my_wrapped || my_possibly_wrapped; }
 protected:
  bool my_wrapped;
  bool my_possibly_wrapped;
  string my_complib;
  string my_compsym;
  string my_comptype;
};

class AggregateCfg :
virtual public ComponentCfg
{
 public:
  AggregateCfg (const string name);
  virtual ~AggregateCfg();
  virtual void add_prefix (const string prefix);
  virtual void write_load (Writer &w);
  virtual void write_construct (Writer &w);
  virtual void write_config (Writer &w);
  void add_child (ComponentCfg *c);
  virtual const ResolvedName resolve(const role r, const string name);
  void dynamic_config_for_wrapped_children (AtomicCfg *dynamic_configurator, Writer &w);
 protected:
  AggregateCfg_impl *a_impl;
};

class Connection : 
virtual public Writable 
{
 public:
  Connection (ComponentCfg *src, const string srcport, 
	      ComponentCfg *dst, const string dstport,
	      bool virt = true);
 protected:
  ComponentCfg *my_src;
  string my_srcport;
  ComponentCfg *my_dst;
  string my_dstport;
  bool my_virt;
};



class PinConnection : 
virtual public Connection 
{
 public:
  PinConnection (ComponentCfg *src, const string srcport, 
		 ComponentCfg *dst, const string dstport, 
		 const direction dir = src_to_dst,
		 bool virt = true);
  virtual void write_to (Writer &w);
 protected:
  direction my_dir;
};

class BusConnection : 
virtual public Connection 
{
 public:
  BusConnection (ComponentCfg *src, const string srcport,
		 ComponentCfg *dst, const string dstport,
		 bool virt = true);
  virtual void write_to (Writer &w);
};


class Relation : 
virtual public Writable
{
 public:
  Relation (ComponentCfg *relater, const string relationship, 
	    ComponentCfg *related, 
	    bool virt = true);
  virtual void write_to (Writer &w);
 protected:
  ComponentCfg *my_relater;
  string my_relationship;
  ComponentCfg *my_related;
  bool my_virt;
};

class Setting : 
virtual public Writable
{
 public:
  Setting (ComponentCfg *targ, 
	   const string attr, 
	   const string val,
	   bool virt = true);
  virtual void write_to (Writer &w);
 protected:
  ComponentCfg *my_targ;
  string my_attr;
  string my_val;
  bool my_virt;
};


#endif // __baseCfg_h__
