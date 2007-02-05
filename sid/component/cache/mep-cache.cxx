// mep-cache.cxx - An implementation of the Cache for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidtypes.h>

#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include "mep-cache.h"

using namespace sid;
using namespace sidutil;
using std::setw;
using std::setfill;
using std::cerr;

mep_cache::mep_cache (unsigned assoc, unsigned cache_sz, unsigned line_sz,
		      cache_replacement_algorithm& replacer)
  : blocking_cache_component (this, assoc, cache_sz, line_sz, replacer, *(new mep_cache_line_factory (*this))),
    tag_test_mem (0),
    data_test_mem (0),
    clear_tag_pin (this, & mep_cache::clear_tag),
    endian_set_pin (this, & mep_cache::endian_set_pin_handler)
{
  add_accessor ("tag-test-mem", &tag_test_mem);
  add_accessor ("data-test-mem", &data_test_mem);
  add_pin ("clear-tag", &clear_tag_pin);
  add_pin ("endian-set!", & this->endian_set_pin);
  add_attribute ("endian", &endianness);
}

void
mep_cache::endian_set_pin_handler(sid::host_int_4 v)
{
  switch (v)
    {
    case 1:
      this->endianness = endian_big;
      break;
    case 2:
      this->endianness = endian_little;
      break;
    default:
      // XXX: warning message?
      break;
    }
}

void
mep_cache::write_tag (unsigned way, int index, cache_tag atag)
{
  if (! tag_test_mem)
    return;

  host_int_4 address = (way * cache_size / 2) + (index * line_size);
  if (endianness == endian_big)
    {
      big_int_4 data = atag;
      tag_test_mem->write (address, data);
    }
  else
    {
      little_int_4 data = atag;
      tag_test_mem->write (address, data);
    }
}

cache_tag
mep_cache::read_tag (unsigned way, int index)
{
  if (! tag_test_mem)
    return 0;

  host_int_4 address = (way * cache_size / 2) + (index * line_size);
  if (endianness == endian_big)
    {
      big_int_4 atag;
      tag_test_mem->read (address, atag);
      return atag;
    }
  little_int_4 atag;
  tag_test_mem->read (address, atag);
  return atag;
}

#define DEFN_METHOD(DataType) \
/* Insert a datum into the line at the given index, starting at byte offset.  */ \
void \
mep_cache::write_data (unsigned way, int index, unsigned offset, DataType new_data) \
{ \
  if (! data_test_mem) \
    return; \
  host_int_4 address = (way * cache_size / 2) + (index * line_size) + offset; \
  data_test_mem->write (address, new_data); \
}\
/* Extract a datum from the line at the given index, starting at byte offset.  */ \
void \
mep_cache::read_data (unsigned way, int index, unsigned offset, DataType& new_data) const \
{ \
  if (! data_test_mem) \
    return; \
  host_int_4 address = (way * cache_size / 2) + (index * line_size) + offset; \
  data_test_mem->read (address, new_data); \
}

DEFN_METHOD (sid::big_int_1)
DEFN_METHOD (sid::big_int_2)
DEFN_METHOD (sid::big_int_4)
DEFN_METHOD (sid::big_int_8)
DEFN_METHOD (sid::little_int_1)
DEFN_METHOD (sid::little_int_2)
DEFN_METHOD (sid::little_int_4)
DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

void
mep_cache::clear_tag (host_int_4 addr)
{
  cache_tag tag = acache.addr_to_tag (addr);
  cache_line* line = acache.find (tag);
  if (line && line->valid_p ())
    {
      mep_cache_line *mep_line = dynamic_cast<mep_cache_line*> (line);
      assert (mep_line);
      mep_line->clear_tag ();
    }
}

void
mep_cache::dump_data (unsigned way, int index) const
{
  for (unsigned i = 0; i < line_size; i++)
    {
      sid::little_int_1 data;
      read_data (way, index, i, data);
      cerr << setw (2) << setfill ('0') << static_cast<unsigned> (data);
    }
}

void
mep_cache::configure (const string &config)
{
  // Call up to the base class first
  blocking_cache_component::configure (config);

  // Now handle relevent configuration for us.
  if (config.size () <= 13)
    return;
  if (config.substr (0, 13) == "model-busses=")
    {
      set_attribute_value ("blockable?", config.substr (13));
      return;
    }
}

// ----------------------------------------

mep_cache_line::mep_cache_line (unsigned line_size, unsigned index, unsigned way, mep_cache &c) :
  my_size (line_size),
  my_way (way),
  my_index (index),
  my_cache (c)
{
  // Compute a shift amount for removing the index from an address.
  index_shift = log2 (my_size);

  // Compute a mask for extracting the tag index
  unsigned assoc = my_cache.assoc ();
  unsigned size = my_cache.size ();
  unsigned indices = size / assoc / line_size;
  index_mask = (1 << log2 (indices)) - 1;

  // Compute a mask for extracting the address tag.
  int non_address_bits = log2 (size) - log2 (assoc);
  address_mask = ~((1 << non_address_bits) - 1);
}

// Get the line's tag.
void
mep_cache_line::set_raw_tag (cache_tag atag)
{
  // Tag is already shifted to the index.
  assert (my_index == ((atag >> index_shift) & index_mask));
  my_cache.write_tag (my_way, my_index, atag);
}

void
mep_cache_line::set_tag (cache_tag atag)
{
  // Tag is already shifted to the index.
  assert (my_index == (atag & index_mask));
  atag <<= index_shift;

  cache_tag oldtag = raw_tag ();
  oldtag &= ~address_mask;
  oldtag |= atag & address_mask;
  my_cache.write_tag (my_way, my_index, oldtag);
}

void
mep_cache_line::clear_tag ()
{
  // Clear the tag bits as well as the dirty and valid bits.
  // Leave the R bit intact.
  cache_tag oldtag = raw_tag ();
  oldtag &= 0x4;
  my_cache.write_tag (my_way, my_index, oldtag);
}

cache_tag
mep_cache_line::raw_tag () const
{
  assert (my_index >= 0);
  cache_tag atag = my_cache.read_tag (my_way, my_index);
  // Add the index back into the tag
  atag |= my_index << index_shift;
  return atag;
}

cache_tag
mep_cache_line::tag () const
{
  return raw_tag () >> index_shift;
}

// Mark the line dirty or clean.
void
mep_cache_line::dirty ()
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  atag |= 0x2;
  set_raw_tag (atag);
}

void
mep_cache_line::clean ()
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  atag &= ~0x2;
  set_raw_tag (atag);
}

// Mark the line valid or invalid.
void
mep_cache_line::validate ()
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  atag |= 0x1;
  set_raw_tag (atag);
}

void
mep_cache_line::invalidate ()
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  atag &= ~0x1;
  set_raw_tag (atag);
}

// Maintain the R bit
int
mep_cache_line::get_R () const
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  return (atag >> 2) & 0x1;
}

void
mep_cache_line::set_R (int R)
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  atag &= ~0x4;
  atag |= (R & 0x1) << 2;
  set_raw_tag (atag);
}

// Lock or unlock the line.
void
mep_cache_line::lock ()
{
  // Nothing to do
}

void
mep_cache_line::unlock ()
{
  // Nothing to do
}

// Is the line dirty?
bool
mep_cache_line::dirty_p () const
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  return (atag & 0x2) != 0;
}

// Is the line valid?
bool
mep_cache_line::valid_p () const
{
  assert (my_index >= 0);
  cache_tag atag = raw_tag ();
  return (atag & 0x1) != 0;
}

// Is the line locked?
bool
mep_cache_line::locked_p () const
{
  return false; // Lines can't be locked
}

#define DEFN_METHOD(DataType) \
/* Insert a datum into the line, starting at byte offset.  */ \
void \
mep_cache_line::insert (unsigned offset, DataType new_data) \
{ \
  assert (offset + sizeof (new_data) <= my_size); \
  assert (my_index >= 0); \
  my_cache.write_data (my_way, my_index, offset, new_data); \
  dirty (); \
} \
/* Extract a datum from the line, starting at byte offset.  */ \
void \
mep_cache_line::extract (unsigned offset, DataType& new_data) const \
{ \
  assert (offset + sizeof (new_data) <= my_size); \
  assert (my_index >= 0); \
  my_cache.read_data (my_way, my_index, offset, new_data); \
}

DEFN_METHOD (sid::big_int_1)
DEFN_METHOD (sid::big_int_2)
DEFN_METHOD (sid::big_int_4)
DEFN_METHOD (sid::big_int_8)
DEFN_METHOD (sid::little_int_1)
DEFN_METHOD (sid::little_int_2)
DEFN_METHOD (sid::little_int_4)
DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

// Dump a line in human readable form to cout.
void
mep_cache_line::dump_data () const
{
  assert (my_index >= 0);
  my_cache.dump_data (my_way, my_index);
}

// ----------------------------------------

// Choose a line to replace in a cache set. Return it, if successful
cache_line *
mep_assoc_replacement_algorithm::expell (cache_set &set)
{
  // Check the R bit in way 0 for the index of the line to be replaced.
  cache_line *line = &set[0];
  mep_cache_line *mep_line = dynamic_cast<mep_cache_line*> (line);
  assert (mep_line);
  int R = mep_line->get_R ();
  assert (R == 0 || R == 1);

  // Reset the bit so the other line is replaced next time.
  mep_line->set_R (! R);

  return &set[R];
}
