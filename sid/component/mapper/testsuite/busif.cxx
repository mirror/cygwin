// busif.cxx - a component for testing word_bus<>.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <string>
#include <iostream>

#include <cstdio>

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidtypes.h>

#include <sidbusutil.h>

using namespace sid;
using namespace sidutil;
using namespace std;

template <typename DataType>
class Busif : public virtual component,
	    public no_accessor_component,
	    public no_attribute_component,
	    public no_relation_component,
	    public fixed_bus_map_component,
	    public no_pin_component
{
private:
  class BusInterface : public word_bus<DataType> {
  private:
    unsigned char mem[0x100];

    typedef typename DataType::value_type internal_type;

  public:
    BusInterface() {
      for( int i=0; i<0x100; i++ ) mem[i] = i + 1;
    }
    
    sid::bus::status word_write( host_int_4 addr, 
				 DataType mask,
				 DataType data ) {
      host_int_4 a = addr * sizeof( internal_type );
      internal_type m = mask;
      internal_type d = data;

      if( sizeof(internal_type) == 8 )
	printf( "write>>addr %d mask 0x%016llx data 0x%llx<<write\n", a, m, d );
      else
	printf( "write>>addr %d mask 0x%08x data 0x%x<<write\n", a, m, d );

      for( int i=0; i<sizeof(internal_type); i++ ) {
	if( mask.read_byte( i ) ) {
	  if( data.read_byte( i ) != mem[a + i] ) {
	    printf( "mismatch in byte %d: %02x != %02x\n", i, 
			data.read_byte(i), mem[a+i] );
	  }
	}
      }

      return sid::bus::ok;
    }

    sid::bus::status word_read( host_int_4 addr, 
				DataType mask,
				DataType& data ) {
      host_int_4 a = addr * sizeof( internal_type );

      for( int i=0; i<sizeof(internal_type); i++ ) {
	if( mask.read_byte( i ) )
	  data.write_byte( i, mem[a + i] );
      }

      internal_type m = mask;
      internal_type d = data;

      if( sizeof(internal_type) == 8 )
	printf( "read>>addr %d mask 0x%016llx data 0x%llx<<read\n", a, m, d );
      else
	printf( "read>>addr %d mask 0x%08x data 0x%x<<read\n", a, m, d );

      return sid::bus::ok;
    }
  };

  BusInterface bus;

public:

  Busif() {
    add_bus( "bus", &bus );
  }

  ~Busif() {}
};

static vector<string>
BusifListTypes() {
  vector<string> types;
  types.push_back(string("busif-big-1"));
  types.push_back(string("busif-big-2"));
  types.push_back(string("busif-big-4"));
  types.push_back(string("busif-big-8"));
  types.push_back(string("busif-little-1"));
  types.push_back(string("busif-little-2"));
  types.push_back(string("busif-little-4"));
  types.push_back(string("busif-little-8"));
  return types;
}

static component*
BusifCreate( const string& instance ) {
  if( instance == "busif-big-1" )
    return new Busif<big_int_1>();
  else if( instance == "busif-little-1" )
    return new Busif<little_int_1>();
  else if( instance == "busif-big-2" )
    return new Busif<big_int_2>();
  else if( instance == "busif-little-2" )
    return new Busif<little_int_2>();
  else if( instance == "busif-big-4" )
    return new Busif<big_int_4>();
  else if( instance == "busif-little-4" )
    return new Busif<little_int_4>();
  else if( instance == "busif-big-8" )
    return new Busif<big_int_8>();
  else if( instance == "busif-little-8" )
    return new Busif<little_int_8>();
  else
    return 0;
}

static void
BusifDelete( component* c ) {
}

// static object
extern const component_library busif_component_library;

const component_library busif_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & BusifListTypes, 
  & BusifCreate,
  & BusifDelete
};

