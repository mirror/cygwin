// sidcomputil.h - Useful mix-in classes for components.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDCOMPUTIL_H
#define SIDCOMPUTIL_H

#include <sidconfig.h>
#include <sidcomp.h>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace sidutil
{
  // The no_bus_component class is used by components that have no bus 
  // interface.  This class overrides the bus-related pure virtual
  // methods declared in sid::component.
  class no_bus_component: public virtual sid::component
  {
  public:
    std::vector<std::string> bus_names() throw()
      {
	return std::vector<std::string>();
      }

    sid::bus*
    find_bus(const std::string& name) throw()
      {
	return 0;
      }
  };


  // The no_accessor_component class is used by components that have
  // no accessors. This class overrides the accessor-related pure
  // virtual methods declared in sid::component.
  class no_accessor_component: public virtual sid::component
  {
  public:
    std::vector<std::string>
    accessor_names() throw()
      {
	return std::vector<std::string>();
      }	     

    sid::component::status
    connect_accessor(const std::string& name, sid::bus* bus) throw()
      {
	return sid::component::not_found;
      }

    sid::component::status
    disconnect_accessor(const std::string& nanme, sid::bus* bus) throw()
      {
	return sid::component::not_found;
      }

    sid::bus* connected_bus(const std::string& name) throw()
      {
	return 0;
      }
  };


  // The no_pin_component class is used by components that have no
  // pins. This class overrides the pin-related pure virtual methods
  // declared in sid::component.
  class no_pin_component: public virtual sid::component
  {
  public:
    std::vector<std::string> pin_names() throw()
      {
	return std::vector<std::string>();
      }

    sid::pin* find_pin(const std::string& name) throw()
      {
	return 0;
      }

    sid::component::status
    connect_pin(const std::string& name, sid::pin* pin) throw()
      {
	return sid::component::not_found;
      }

    sid::component::status
    disconnect_pin(const std::string& name, sid::pin* pin) throw()
      {
	return sid::component::not_found;
      }

    std::vector<sid::pin*>
    connected_pins(const std::string& name) throw()
      {
	return std::vector<sid::pin*>();
      }	    
  };


  // The no_attribute_component class is used by components that have
  // no attributes. This class overrides the attribute-related pure
  // virtual methods declared in sid::component.
  class no_attribute_component: public virtual sid::component
  {
  public:
    virtual std::vector<std::string> attribute_names() throw()
      {
	return std::vector<std::string>();
      }

    virtual std::vector<std::string>
    attribute_names(const std::string& category) throw()
      {
	return std::vector<std::string>();
      }

    std::string attribute_value(const std::string& name) throw()
      {
	return std::string();
      }

    sid::component::status
    set_attribute_value(const std::string& name,
			const std::string& value) throw()
      {
	return sid::component::not_found;
      }	
  };


  // The no_relation_component class is used by components that have
  // no relations. This class overrides the relation-related pure
  // virtual methods declared in sid::component.
  class no_relation_component: public virtual sid::component
  {
  public:
    std::vector<std::string> 
    relationship_names() throw()
      {
	return std::vector<std::string>();
      }

    sid::component::status
    relate (const std::string& rel, 
	    sid::component*) 
      throw()
      {
	return sid::component::not_found;
      }

    sid::component::status
    unrelate (const std::string& rel, 
	      sid::component*) 
      throw()
      {
	return sid::component::not_found;
      }

    std::vector<sid::component*>
    related_components (const std::string& rel)
      throw()
      {
	return std::vector<sid::component*>();
      }
  };


  // A fixed_relation_map_component maintains component relationships 
  // either as single pointers (as accessors) or a vector of pointers
  // (as output pins).
  class fixed_relation_map_component: public virtual sid::component
  {
  public:
    typedef std::vector<sid::component*> component_relation_t;

    std::vector<std::string> 
    relationship_names () throw()
      {
	std::vector<std::string> names;
	for (uni_relation_map_t::const_iterator it = 
				 this->uni_relation_map.begin();
	     it != this->uni_relation_map.end();
	     it++)
	   {
	     names.push_back(it->first);
	   }
	    
	 for (multi_relation_map_t::const_iterator it = 
				this->multi_relation_map.begin();
	      it != this->multi_relation_map.end();
	      it++)
	    {
	      names.push_back(it->first);
	    }
	 return names;
      }
    
    sid::component::status
    relate (const std::string& name, sid::component* comp) 
      throw()
      {
	if (this->uni_relation_map.find(name) != this->uni_relation_map.end())
	  {
	    sid::component** holder = (this->uni_relation_map[name]);	    
	    if (*holder == 0)
	      {
		*holder = comp;
		return sid::component::ok;
	      }
	    else
	      {
		// relationship already set
		return sid::component::bad_value;
	      }
	  }
	else if (this->multi_relation_map.find(name) != this->multi_relation_map.end())
	    {
	      component_relation_t* holder = this->multi_relation_map[name];
	      component_relation_t::iterator it =
		find (holder->begin(), holder->end(), comp);

	      if (it == holder->end())
		{
		  holder->push_back (comp);
		  return sid::component::ok;
		}
	      else
		{
		  // duplicate
		  return sid::component::bad_value;
		}
	    }
	    
	return sid::component::not_found;
      }


    sid::component::status
    unrelate (const std::string& name, sid::component* comp) 
      throw()
      {
	if (this->uni_relation_map.find(name) != this->uni_relation_map.end())
	  {
	    sid::component** holder = (this->uni_relation_map[name]);	    
	    if (*holder == comp)
	      {
		*holder = 0;
		return sid::component::ok;
	      }
	    else
	      {
		// relationship not already set
		return sid::component::bad_value;
	      }
	  }
	else if (this->multi_relation_map.find(name) != this->multi_relation_map.end())
	    {
	      component_relation_t* holder = this->multi_relation_map[name];
	      component_relation_t::iterator it =
		find (holder->begin(), holder->end(), comp);

	      if (it != holder->end())
		{
		  holder->erase (it);
		  return sid::component::ok;
		}
	      else
		{
		  // does not exist
		  return sid::component::bad_value;
		}
	    }
	    
	return sid::component::not_found;
      }


    std::vector<sid::component*>
    related_components (const std::string& name)
      throw()
      {
	component_relation_t list;

	if (this->uni_relation_map.find(name) != this->uni_relation_map.end())
	  {
	    sid::component** holder = this->uni_relation_map[name];
	    if (*holder != 0)
	      list.push_back (*holder);
	  }
	else if (this->multi_relation_map.find(name) != this->multi_relation_map.end())
	  {
	    component_relation_t* holder = this->multi_relation_map[name];
	    list = /* copy of */ *holder;
	  }
	
	return list;
      }

  protected:
    void
    add_uni_relation(const std::string& name, sid::component** ptr)
      {
	assert (uni_relation_map.find(name) == uni_relation_map.end());
	assert (multi_relation_map.find(name) == multi_relation_map.end());
	uni_relation_map[name] = ptr;
      } 
    
    void
    add_multi_relation(const std::string& name, component_relation_t* ptr)
      {
	assert (uni_relation_map.find(name) == uni_relation_map.end());
	assert (multi_relation_map.find(name) == multi_relation_map.end());
	multi_relation_map[name] = ptr;
      }
    
  private:
    typedef std::map<std::string, sid::component**> uni_relation_map_t;
    typedef std::map<std::string, component_relation_t*> multi_relation_map_t;
    mutable uni_relation_map_t uni_relation_map;
    mutable multi_relation_map_t multi_relation_map;
  };
}


#endif // SIDCOMPUTIL_H
