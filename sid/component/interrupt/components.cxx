// components.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "tconfig.h"
#include "components.h"




  // XXX: this should be in components.cxx, but GCC does not seem to
  //      like these being outside of the class.
template<class bus_size>
ostream& operator<< (ostream& op, const IntController<bus_size>& copy_obj)
{
  op << "IRQEnable " << copy_obj.irq_enabled << " ";
  op << "IRQPend "   << copy_obj.irq_pending;
  op << " FIQEnable " << copy_obj.fiq_enabled;
  op << " FIQPend "   << copy_obj.fiq_pending;
  op << endl;
  
  op << "Pins ";
  op << copy_obj.reset_pin << " ";
  op << copy_obj.irq_pin;
  op << " " << copy_obj.fiq_pin;
  
  for (unsigned i = 0; i < copy_obj.irq_lines.size(); i++)
    op << " " << *static_cast<input_pin*>(copy_obj.irq_lines[i]);
  for (unsigned i = 0; i < copy_obj.fiq_lines.size(); i++)
    op << " " << *static_cast<input_pin*>(copy_obj.fiq_lines[i]);
  
  // NB: no whitespace at end!
  
  return op;
}

template <class bus_size>
istream& operator>> (istream& ip, IntController<bus_size>& ovwrite_obj)
{
  string coding;
  
  ip >> coding;
  if (coding != "IRQEnable")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.irq_enabled;
  
  ip >> coding;
  if (coding != "IRQPend")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.irq_pending;	    
  
  ip >> coding;
  if ( coding != "FIQEnable")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.fiq_enabled;
  
  ip >> coding;
  if ( coding != "FIQPend")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.fiq_pending;
  
  ip >> coding;
  if (coding != "Pins" )
    {
      ip.setstate (ios::badbit);
      return ip;
    }
  ip >> ovwrite_obj.reset_pin;
  ip >> ovwrite_obj.irq_pin;
  ip >> ovwrite_obj.fiq_pin;
  
  for (unsigned i = 0; i < ovwrite_obj.irq_lines.size(); i++)
    ip >> *static_cast<input_pin*>(ovwrite_obj.irq_lines[i]);
  for (unsigned i = 0; i < ovwrite_obj.fiq_lines.size(); i++)
    ip >> *static_cast<input_pin*>(ovwrite_obj.fiq_lines[i]);
  
  return ip;
}


// --- m a i n   d r i v e r ---

static vector<string>
compInterruptListTypes()
{
  vector<string> types;
#if SIDTARGET_ARM
  types.push_back(string("hw-interrupt-arm/ref"));
  types.push_back(string("hw-interrupt-cogent/cma222"));
//  types.push_back(string("hw-interrupt-sa"));
#endif
  return types;
}

#include "arm.h"
#include "cma222.h"
//#include "sa.h"

static component*
compInterruptCreate(const string& typeName)
{
#if SIDTARGET_ARM
  if (typeName == "hw-interrupt-arm/ref")
    return new armIntController();
  if (typeName == "hw-interrupt-cogent/cma222")
    return new cma222IntController();
//  if (typeName == "hw-interrupt-sa")
//    return new saIntController();
#endif
  return 0;
}

static void
compInterruptDelete(component* c)
{
#if SIDTARGET_ARM
  delete dynamic_cast<armIntController*>(c);
  delete dynamic_cast<cma222IntController*>(c);
//  delete dynamic_cast<saIntController*>(c);
#endif
}

extern const component_library interrupt_component_library;

const component_library interrupt_component_library DLLEXPORT =
{
  COMPONENT_LIBRARY_MAGIC,
  &compInterruptListTypes,
  &compInterruptCreate,
  &compInterruptDelete
};
