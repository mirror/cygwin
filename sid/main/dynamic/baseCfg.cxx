#include "baseCfg.h"
#include <fstream>
#include <vector>
#include <map>


ResolvedName::ResolvedName () : target (""), slot ("") {}
ResolvedName::ResolvedName (const string t, const string s) :
  target (t), slot (s)
{}


Writer::Writer (sid::component *c, const string filename) : 
  main_component (c),
  out (NULL),
  out_is_file (false)
{
  if (filename == "-")
    out = &cout;
  else if (filename != "")
    {
      out = new ofstream (filename.c_str());
      if (!(out && (*out)))
	{
	  cerr << "Cannot open output file '" << filename << "'.  Aborting." << endl;
	  exit (4);
	}
      out_is_file = true;
    }
}

Writer::~Writer() 
{
  if (out && out_is_file)
    {
      delete out;
    }
}


void Writer::write_line(string s)
{
  if (out)
    (*out) << s << endl;
  sid::component::status res = 
    main_component->set_attribute_value ("config-line!", s);
  if (res != sid::component::ok)
    {
      cerr << "Configuration error.  Aborting." << endl;
      exit (3);
    }
}
  
void Writer::write_file(string s)
{
  if (out)
    (*out) << "set main config-file! " << s << endl;
  sid::component::status res = 
    main_component->set_attribute_value ("config-file!", s);    
  if (res != sid::component::ok)
    {
      cerr << "Configuration error.  Aborting." << endl;
      exit (2);
    }
}


// ComponentCfg

struct ComponentCfg_impl 
{
  vector<Writable *> my_pre;
  vector<Writable *> my_post;
  map <role, map< string, pair<ComponentCfg *, string> > > my_name_map;
};

ComponentCfg::ComponentCfg (const string n) :
  my_name (n),
  c_impl (NULL)
{
  c_impl = new ComponentCfg_impl ();
}

ComponentCfg::~ComponentCfg() 
{
  if (c_impl)
    {
      for (vector<Writable *>::const_iterator i = c_impl->my_pre.begin();
	   i != c_impl->my_pre.end(); ++i)
	delete (*i);    
      for (vector<Writable *>::const_iterator i = c_impl->my_post.begin();
	   i != c_impl->my_post.end(); ++i)
	delete (*i);
      delete c_impl;
    }
}

const string ComponentCfg::get_name()
{
  return my_name;
}

void ComponentCfg::add_prefix (const string prefix)
{
  if (prefix != "")
    {
      my_name = prefix + "/" + my_name;
    }
}

void ComponentCfg::write_all (Writer &w)
{
  this->write_load (w);
  this->write_construct (w);
  this->write_config (w);
}

void ComponentCfg::write_config (Writer &w)
{
  this->write_pre(w);
  this->write_post(w);
}

void ComponentCfg::add_pre (Writable *w)
{
  assert (c_impl);
  assert (w);
  c_impl->my_pre.push_back(w);
}

void ComponentCfg::add_post (Writable *w)
{
  assert (c_impl);
  assert (w);
  c_impl->my_post.push_back(w);
}

void ComponentCfg::conn_pin (ComponentCfg *src, const string srcport, 
			     ComponentCfg *dst, const string dstport, 
			     const direction dir, 
			     bool virt)
{
  add_post (new PinConnection (src, srcport, dst, dstport, dir, virt));
}

void ComponentCfg::conn_bus (ComponentCfg *src, 
			     const string srcport,
			     ComponentCfg *dst, 
			     const string dstport,
			     bool virt)
{
  add_post (new BusConnection (src, srcport, dst, dstport, virt));
}

void ComponentCfg::set (ComponentCfg *targ, 
			const string attr, 
			const string val,
			bool virt)
{
  add_post (new Setting (targ, attr, val, virt));
}

void ComponentCfg::relate (ComponentCfg *relater, 
			   const string relationship, 
			   ComponentCfg *related,
			   bool virt)
{
  add_post (new Relation (relater, relationship, related, virt));
}


void ComponentCfg::write_pre (Writer &w)
{
  assert (c_impl);
  for (vector<Writable *>::const_iterator i = c_impl->my_pre.begin();
       i != c_impl->my_pre.end(); ++i)
    {
      assert (*i);
      (*i)->write_to (w);
    }
}
void ComponentCfg::write_post (Writer &w)
{
  assert (c_impl);
  for (vector<Writable *>::const_iterator i = c_impl->my_post.begin();
       i != c_impl->my_post.end(); ++i)
    {
      assert (*i);
      (*i)->write_to (w);
    }
}

void ComponentCfg::map_name (ComponentCfg *c, role r, 
			     const string outer, const string inner)
{
  string s(inner);
  assert (c);
  assert (c_impl);
  c_impl->my_name_map [r] [outer] = pair<ComponentCfg *, string>(c,s);
}

const ResolvedName ComponentCfg::resolve(const role r, const string name)
{
  assert (c_impl);
  if (c_impl->my_name_map [r].find (name) == 
      c_impl->my_name_map [r].end())
    return ResolvedName(my_name, name);
  
  // note: name binding is intentionally delayed here, to make sure
  // we resolve in the context of the component's "final destination"
  // rather than its location when the name mapping is setup.
  pair <ComponentCfg *, string> ref = c_impl->my_name_map [r] [name];
  assert (ref.first);
  return ref.first->resolve (r, ref.second);
}


// AtomicCfg

struct AtomicCfg_impl
{
  static map<string, AtomicCfg *> atomic_names;
  static map<string, bool> already_loaded;
};

map<string, bool> AtomicCfg_impl::already_loaded;
map<string, AtomicCfg *> AtomicCfg_impl::atomic_names;

AtomicCfg::AtomicCfg (const string name, const string complib, 
		      const string compsym, const string comptype) :
  ComponentCfg (name),
  my_wrapped (false),
  my_possibly_wrapped (false),
  my_complib (complib),
  my_compsym (compsym),
  my_comptype (comptype)
{
  AtomicCfg_impl::atomic_names [name] = this;
}

void AtomicCfg::add_prefix (const string prefix)
{
  ComponentCfg::add_prefix (prefix);
  AtomicCfg_impl::atomic_names [my_name] = this;
}

AtomicCfg::~AtomicCfg() {}

AtomicCfg *AtomicCfg::wrap_component (const string name)
{
  if (AtomicCfg_impl::atomic_names.find (name) == 
      AtomicCfg_impl::atomic_names.end ())
    return 0;
  AtomicCfg *comp = AtomicCfg_impl::atomic_names[name];
  comp->my_wrapped = true;
  comp->my_possibly_wrapped = false;
  return comp;
}

AtomicCfg *
AtomicCfg::possible_wrap_name (const string &name)
{
  if (AtomicCfg_impl::atomic_names.find (name) == 
      AtomicCfg_impl::atomic_names.end ())
    return 0;
  AtomicCfg *comp = AtomicCfg_impl::atomic_names[name];
  if (! comp->my_wrapped)
    comp->my_possibly_wrapped = true;
  return comp;
}

void AtomicCfg::reset_load_map () 
{
  AtomicCfg_impl::already_loaded.erase 
    (AtomicCfg_impl::already_loaded.begin (), 
     AtomicCfg_impl::already_loaded.end ());
}

void AtomicCfg::write_load (Writer &w) 
{
  if (my_complib == "" || my_compsym == "")
    return;
  if (AtomicCfg_impl::already_loaded.find (my_complib) != 
      AtomicCfg_impl::already_loaded.end ())
    return;
  w.write_line ("load " + my_complib + " " + my_compsym);      
  AtomicCfg_impl::already_loaded [my_complib] = true;
}

void AtomicCfg::write_construct (Writer &w)
{
  if (my_comptype == "")
    return;
  if (my_wrapped || my_possibly_wrapped)
    {
      w.write_line ("new sid-api-trace " + my_name);
      w.write_line ("new " + my_comptype + " " + my_name + "-traced");      
      w.write_line ("relate " + my_name + " victim " + my_name + "-traced");      
      w.write_line ("set " + my_name + " victim-name " + my_name + "-traced");      
      if (my_possibly_wrapped)
	w.write_line ("set " + my_name + " victim-trace? 0");      
    }
  else
    w.write_line ("new " + my_comptype + " " + my_name);
}


// AggregateCfg

struct AggregateCfg_impl
{
  vector<ComponentCfg *> my_children;
};

AggregateCfg::AggregateCfg (const string name) :
  ComponentCfg (name),
  a_impl (NULL)
{
  a_impl = new AggregateCfg_impl ();
  assert (a_impl);
}

AggregateCfg::~AggregateCfg() 
{
  if (a_impl)
    {
      for (vector<ComponentCfg *>::const_iterator i = a_impl->my_children.begin();
	   i != a_impl->my_children.end(); ++i)
	delete (*i);  
      if (a_impl)
	delete a_impl;
    }
}

void AggregateCfg::add_prefix (const string prefix)
{
  assert (a_impl);
  if (prefix.size() > 0 && prefix != string(""))
    {
      my_name = prefix + "-" + my_name;
      for (vector<ComponentCfg *>::const_iterator i = a_impl->my_children.begin();
	   i != a_impl->my_children.end(); ++i)
	(*i)->add_prefix (prefix);
    }
}

void AggregateCfg::write_load (Writer &w) 
{
  assert (a_impl);
  for (vector<ComponentCfg *>::const_iterator i = a_impl->my_children.begin();
       i != a_impl->my_children.end(); ++i)
    (*i)->write_load (w);
}

void AggregateCfg::write_construct (Writer &w) 
{
  assert (a_impl);
  for (vector<ComponentCfg *>::const_iterator i = a_impl->my_children.begin();
       i != a_impl->my_children.end(); ++i)
    (*i)->write_construct (w);
}

void AggregateCfg::write_config (Writer &w) 
{
  assert (a_impl);
  this->write_pre (w);
  for (vector<ComponentCfg *>::const_iterator i = a_impl->my_children.begin();
       i != a_impl->my_children.end(); ++i)
    (*i)->write_config (w);
  this->write_post (w);
}

void AggregateCfg::add_child (ComponentCfg *c)
{
  assert (c);
  assert (a_impl);
  c->add_prefix (this->my_name);
  a_impl->my_children.push_back (c);
}

const ResolvedName AggregateCfg::resolve(const role r, const string name)
{
  // note: name binding is intentionally delayed here, to make sure
  // we resolve in the context of the component's "final destination"
  // rather than its location when the name mapping is setup.
  //
  // also: aggregates will _not_ return their own name, since they
  // do not formally exist as instantiated components in sid
  assert (c_impl);
  pair <ComponentCfg *, string> ref = c_impl->my_name_map [r] [name];
  assert (ref.first);
  return ref.first->resolve (r, ref.second);
}


void AggregateCfg::dynamic_config_for_wrapped_children (AtomicCfg *dynamic_configurator, Writer &w)
{
  assert (dynamic_configurator);
  for (vector<ComponentCfg *>::const_iterator i = a_impl->my_children.begin();
       i != a_impl->my_children.end(); ++i)
    {
      if (*i == dynamic_configurator)
	continue;
      AtomicCfg *a = dynamic_cast<AtomicCfg *>(*i);
      if (a)
	{
	  if (a->possibly_wrapped ())
	    {
	      Relation (dynamic_configurator, "client", a).write_to (w);
	    }
	  continue;
	}
      AggregateCfg *ag = dynamic_cast<AggregateCfg *>(*i);
      if (ag)
	{
	  ag->dynamic_config_for_wrapped_children (dynamic_configurator, w);
	  continue;
	}
      assert (false);
    }
}


Connection::Connection (ComponentCfg *src, const string srcport, 
			ComponentCfg *dst, const string dstport,
			bool virt) :
  my_src (src), my_srcport (srcport), 
  my_dst (dst), my_dstport (dstport),
  my_virt (virt)
{
  assert (src);
  assert (dst);
}    


PinConnection::PinConnection (ComponentCfg *src, const string srcport, 
			      ComponentCfg *dst, const string dstport, 
			      const direction dir,
			      bool virt) :
  Connection (src, srcport, dst, dstport, virt),
  my_dir (dir)
{
  assert (src);
  assert (dst);
}    

void PinConnection::write_to (Writer &w)
{
  if (my_virt)
    {
      switch (my_dir)
	{
	case src_to_dst:
	  {
	    ResolvedName s = my_src->resolve (out_pin, my_srcport);
	    ResolvedName d = my_dst->resolve (in_pin, my_dstport);
	    w.write_line ("connect-pin " + s.target + " " + s.slot + " -> " + d.target + " " + d.slot);
	  }
	  break;
	case dst_to_src:
	  {
	    ResolvedName s = my_src->resolve (in_pin, my_srcport);
	    ResolvedName d = my_dst->resolve (out_pin, my_dstport);
	    w.write_line ("connect-pin " + s.target + " " + s.slot + " <- " + d.target + " " + d.slot);
	  }
	  break;
	case both:
	  {
	    // note: we might not use "<->" here since the port names on either
	    // end of the mapping, while the same from the user's perspective,
	    // may resolve to _different_ names depending on whether they are
	    // treated as in_pins or out_pins.
	    
	    ResolvedName s1 = my_src->resolve (out_pin, my_srcport);
	    ResolvedName d1 = my_dst->resolve (in_pin, my_dstport);
	    ResolvedName s2 = my_src->resolve (in_pin, my_srcport);
	    ResolvedName d2 = my_dst->resolve (out_pin, my_dstport);
	    if (s1.target == s2.target &&
		s1.slot == s2.slot &&
		d2.target == d1.target &&
		d2.slot == d1.slot)
	      {
		w.write_line ("connect-pin " + s1.target + " " + s1.slot + " <-> " + d1.target + " " + d1.slot);
	      }
	    else 
	      {
		w.write_line ("connect-pin " + s1.target + " " + s1.slot + " -> " + d1.target + " " + d1.slot);
		w.write_line ("connect-pin " + s2.target + " " + s2.slot + " <- " + d2.target + " " + d2.slot);
	      }
	  }
	  break;
	}
    }
  else
    {
      // non-virtual pin connection.
      string dir (my_dir == src_to_dst ? " -> " : (my_dir == dst_to_src ? " <- " : " <-> "));
      w.write_line ("connect-pin" + my_src->get_name() + " " + my_srcport + 
		    dir + my_dst->get_name() + " " + my_dstport);
    }
}

BusConnection::BusConnection (ComponentCfg *src, const string srcport,
			      ComponentCfg *dst, const string dstport,
			      bool virt) :
  Connection (src, srcport, dst, dstport, virt)
{
  assert (src);
  assert (dst);
}

void BusConnection::write_to (Writer &w)
{
  ResolvedName s;
  ResolvedName d;
  if (my_virt)
    {
      s = my_src->resolve (accessor, my_srcport);
      d = my_dst->resolve (bus, my_dstport);
    }
  else
    {
      s.target = my_src->get_name();
      s.slot = my_srcport;
      d.target = my_dst->get_name();
      d.slot = my_dstport;
    }
  w.write_line ("connect-bus " + s.target + " " + s.slot + " " + d.target + " " + d.slot);
}

Setting::Setting (ComponentCfg *targ, const string attr, 
		  const string val, bool virt) :
  my_targ (targ), 
  my_attr (attr),
  my_val (val),
  my_virt (virt)
{
  assert(targ);
}

void Setting::write_to (Writer &w)
{
  ResolvedName s;
  if (my_virt)
    s = my_targ->resolve (attr, my_attr);
  else
    {
      s.target = my_targ->get_name();
      s.slot = my_attr;
    }
  if (my_val.find (' ', 0) == -1)
    w.write_line ("set " + s.target + " " + s.slot + " " + my_val);
  else
    w.write_line ("set " + s.target + " " + s.slot + " \"" + my_val + "\"");
}

Relation::Relation (ComponentCfg *relater, const string relationship, 
		    ComponentCfg *related, bool virt) :
  my_relater (relater), 
  my_relationship (relationship),
  my_related (related),
  my_virt (true)
{
  assert (relater);
  assert (related);
}

void Relation::write_to (Writer &w)
{
  ResolvedName s; 
  ResolvedName d; 
  if (my_virt)
    {
      s = my_relater->resolve (relater, my_relationship);
      d = my_related->resolve (related, my_relationship);
    }
  else
    {
      s.target = my_relater->get_name();
      s.slot = my_relationship;
      d.target = my_related->get_name();
    }
  w.write_line ("relate " + s.target + " " + s.slot + " " + d.target);
}

