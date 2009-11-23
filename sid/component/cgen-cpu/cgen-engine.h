// cgen-engine.h - CGEN engine support.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_ENGINE_H
#define CGEN_ENGINE_H

namespace cgen {

// Result of semantic fns.

enum sem_status
{
  SEM_STATUS_NORMAL,
  SEM_STATUS_BRANCH_TAKEN,
  SEM_STATUS_DELAYED_BRANCH_TAKEN,
  SEM_STATUS_STALLED
};


// Virtual insn support.

// Canonical ids of virtual insns.
enum virtual_insn_type {
  VIRTUAL_INSN_INVALID,
  VIRTUAL_INSN_BEGIN,
  VIRTUAL_INSN_COND,
  VIRTUAL_INSN_CHAIN, VIRTUAL_INSN_CTI_CHAIN,
  VIRTUAL_INSN_BEFORE, VIRTUAL_INSN_AFTER,
};

// Exceptions used to exit the cpu's "main loop".

class cgen_trap
{
};

class cgen_yield_trap: public cgen_trap
{
public:
  PCADDR newpc;
  cgen_yield_trap(PCADDR p): newpc(p) {}
};

class cgen_memory_trap: public cgen_trap
{
public:
  ADDR address;
  PCADDR pc;
  ::sid::bus::status status;
  bool imem_p;
  const char* memory_name;
  const char* operation;

  cgen_memory_trap(PCADDR p, ADDR a, ::sid::bus::status s, const char* n, const char* o): 
    address(a), pc(p), status(s), imem_p(false), memory_name(n), operation(o) {}
  cgen_memory_trap(PCADDR p, ADDR a, ::sid::bus::status s, const char* n, const char* o, bool i): 
    address(a), pc(p), status(s), imem_p(i), memory_name(n), operation(o) {}
};

enum branch_status {
  BRANCH_UNTAKEN = 0,
  BRANCH_UNCACHEABLE = 1,
  BRANCH_CACHEABLE = 2
};

// Scache engine.

template <typename scache_content>
struct generic_scache_record
{
  PCADDR addr;
  scache_content content;
};


template <typename scache_record>
class scache_engine
{
private:

  scache_record* cache;
  size_t size; // XXX: must be power of two!
  unsigned mask;
  enum { UNUSED_ADDR = -1 }; // sentinel value

  inline size_t
  hash (PCADDR pc) const
    {
      // XXX: tune! [if all insns are 4 bytes, should at least do >> 2]
      return ((pc >> 1) & mask);
    }

public:

  scache_engine (size_t s):
    size(s)
    {
      mask = size - 1;
      cache = new scache_record[size];
      for (unsigned i = 0; i < size; ++i)
	cache[i].addr = (PCADDR) UNUSED_ADDR;
    }

  ~scache_engine ()
    {
      delete [] this->cache;
    }

  void
  zap (PCADDR pc)
    {
      assert (pc != (PCADDR) UNUSED_ADDR);
      scache_record* x = & cache[hash(pc)];
      if (x->addr == pc)
	x->addr = (PCADDR) UNUSED_ADDR;
    }

  void
  flush ()
    {
      for (unsigned i = 0; i < size; ++i)
	cache[i].addr = (PCADDR) UNUSED_ADDR;
    }

  
  inline scache_record*
  find (PCADDR pc, bool& reuse)
    {
      assert (pc != (PCADDR) UNUSED_ADDR);
      scache_record* x = & cache[hash(pc)];
      reuse = (x->addr == pc);
      return x;
    }
};

// PBB engine.
// This engine supports both the scache and pbb engines.  Either may be in
// use at various times during the execution of a program, and we don't want
// to keep separate copies of the cache [clumsy use of memory].
//
// ABUF is short for Argument BUFfer.

// Two kinds of computed goto (threaded) engines are supported: one entry per
// insn and one entry per insn fragment (where an insn can be made up of one
// or more fragments).

union cgoto_label {
  void* label;
  void** frags;
};

template <typename scache_record>
struct hash_table_entry
{
  PCADDR addr;
  scache_record* abuf;
};

// ??? This could be implemented by inheriting from `scache', but for the
// time being we don't.  Not sure it'll be warranted.

template <typename cpu_class, typename scache_record>
class pbb_engine
{
private:
  scache_record* cache;
  size_t cache_size; // XXX: must be power of two!
  size_t cache_size_mask;
  // ??? There is no perfect sentinel value to use, but this one should
  // work for the foreseeable future.
  enum { UNUSED_ADDR = -1 }; // sentinel value
  enum { MINIMUM_CACHE_SIZE = 8 };

  // true if using pbb engine, otherwise using scache engine
  bool pbb_p;

  typedef hash_table_entry<scache_record> hash_table_t;

  // Pointer to end of used part of pbb cache.
  scache_record* next_free;
  // Hash table into pbb cache.
  hash_table_t* hash_table;
  size_t hash_table_size;
  size_t hash_size_mask;

  // The pbb hash table is a linear collection of entries.  Lookup involves
  // scanning this many entries starting at the hash point.
  static const unsigned max_tries = 4;

  // Maximum number of real insns in a block (doesn't include virtual insns).
  // Most basic blocks are far shorter than this.
  // The actual maximum block size is min (step_insn_count, max_block_size).
  static const unsigned max_block_size = 32;

  // Indices of cpu's virtual insns.
  unsigned begin_index, cond_index, chain_index, cti_chain_index;
  unsigned before_index, after_index;
  bool index_init_p;

  PCADDR last_traced_pc_pbb;

public:

  pbb_engine (size_t s)
    {
      last_traced_pc_pbb = (PCADDR) UNUSED_ADDR;

      cache_size = s;
      if (cache_size < MINIMUM_CACHE_SIZE)
	cache_size = MINIMUM_CACHE_SIZE;
      cache_size_mask = cache_size - 1;
      cache = new scache_record[cache_size];

      hash_table_size = cache_size / 8;
      if (hash_table_size < 64)
	hash_table_size = 64;
      hash_size_mask = hash_table_size - 1;
      // We allocated max_tries-1 more entries to simplify lookup [we don't
      // have to handle wrapping around from the end to the beginning].
      hash_table_size += max_tries - 1;
      hash_table = new hash_table_t[hash_table_size];

      // Start out in scache mode, and empty the cache.
      pbb_p = false;
      index_init_p = false;
      flush ();

      begin_insn.addr = (PCADDR) UNUSED_ADDR;
      next_vpc = & begin_insn;
    }

  ~pbb_engine ()
    {
      delete [] this->cache;
      delete [] this->hash_table;
    }

  void
  set_pbb_engine ()
    {
      if (UNLIKELY(! index_init_p))
	{
	  // Look up virtual insns indices so we only do the lookup once.
	  // ??? Initialized here until pbb support finished.
	  begin_index = begin_insn.idesc->lookup_virtual (VIRTUAL_INSN_BEGIN);
	  cond_index = begin_insn.idesc->lookup_virtual (VIRTUAL_INSN_COND);
	  chain_index = begin_insn.idesc->lookup_virtual (VIRTUAL_INSN_CHAIN);
	  cti_chain_index = begin_insn.idesc->lookup_virtual (VIRTUAL_INSN_CTI_CHAIN);
	  before_index = begin_insn.idesc->lookup_virtual (VIRTUAL_INSN_BEFORE);
	  after_index = begin_insn.idesc->lookup_virtual (VIRTUAL_INSN_AFTER);
	  index_init_p = true;
	}
      pbb_p = true;
      flush ();
    }

  void
  set_scache_engine ()
    {
      pbb_p = false;
      flush ();
    }

  void
  flush ()
    {
      last_traced_pc_pbb = (PCADDR) UNUSED_ADDR;

      if (pbb_p)
	{
	  next_free = cache;
	  for (unsigned i = 0; i < hash_table_size; ++i)
	    hash_table[i].addr = (PCADDR) UNUSED_ADDR;
	}
      else
	{
	  for (unsigned i = 0; i < cache_size; ++i)
	    cache[i].addr = (PCADDR) UNUSED_ADDR;
	}
    }

  // Scache engine

private:

  inline size_t
  hash (PCADDR pc) const
    {
      // XXX: tune! [if all insns are 4 bytes, should at least do >> 2]
      return ((pc >> 1) & cache_size_mask);
    }

public:

  void
  zap (PCADDR pc)
    {
      assert (pc != (PCADDR) UNUSED_ADDR);
      scache_record* x = & cache[hash(pc)];
      if (x->addr == pc)
	x->addr = (PCADDR) UNUSED_ADDR;
    }
  
  inline scache_record*
  find (PCADDR pc, bool& reuse)
    {
      assert (pc != (PCADDR) UNUSED_ADDR);
      scache_record* x = & cache[hash(pc)];
      reuse = (x->addr == pc);
      return x;
    }

  // PBB engine.

private:

  inline size_t
  pbb_hash (PCADDR pc) const
    {
      // XXX: tune! [if all insns are 4 bytes, should at least do >> 2]
      return ((pc >> 1) & hash_size_mask);
    }

  // Virtual insn that starts the compiler.
  scache_record begin_insn;

  // Next insn to execute.  Only valid when engine is *not* running.
  scache_record *next_vpc;

  /*inline*/ scache_record*
  chain (cpu_class* cpu, scache_record*& next, PCADDR npc)
    {
      // Goto next block if we're already chained to it.
      if (LIKELY(next))
	return next;
      // Try to find next block.
      next = pbb_find (npc);
      if (LIKELY(next))
	return next;
      // Have to compile next block.
      return & this->begin_insn;
    }

public:

  // public begin_insn accessor
  inline scache_record* get_begin_insn () { return & this->begin_insn; }

  // public next_vpc accessor
  inline scache_record*
  get_next_vpc (PCADDR pc)
    {
      scache_record* vpc = this->next_vpc;
      if (LIKELY(vpc->addr == pc))
	return vpc;
      return & this->begin_insn;
    }

  // save vpc for next time
  inline void set_next_vpc (scache_record* vpc) { this->next_vpc = vpc; }

  // Return maximum number of real insns for a block.
  inline unsigned
  max_real_insns (cpu_class* cpu)
    {
      return max_block_size;
    }

  /*inline*/ scache_record*
  pbb_find (PCADDR pc) const
    {
      hash_table_t* hte = & hash_table[pbb_hash (pc)];

      for (unsigned i = 0; i < max_tries; ++i, ++hte)
	if (LIKELY(hte->addr == pc))
	  return hte->abuf;
      return 0;
    }

  /*inline*/ scache_record*
  pbb_find_or_alloc (PCADDR pc, unsigned n, bool& found)
    {
      assert (n <= cache_size);

      hash_table_t* hte = & hash_table[pbb_hash (pc)];

      unsigned i = 0;
      for (hash_table_t* p = hte; i < max_tries; ++i, ++p)
	{
	  if (LIKELY(p->addr == pc))
	    {
	      found = true;
	      return p->abuf;
	    }
	  if (p->addr == (PCADDR) UNUSED_ADDR)
	    break;
	}

      // Not found, so alloc N entries and return that.
      // If there's not enough room, flush the cache.
      // ??? garbage collect instead
      // If the hash table is full, throw out a pseudo-random entry.

      found = false;

      size_t remaining = cache_size - (next_free - cache);

      // Cache full?
      if (UNLIKELY(remaining < n))
	{
	  flush ();
	  hte->addr = pc;
	  hte->abuf = next_free;
	  next_free += n;
	  return hte->abuf;
	}
      // Hash table full?
      else if (UNLIKELY(i == max_tries))
	{
	  static unsigned last_tossed = 0;

	  if (++last_tossed == max_tries)
	    last_tossed = 0;
	  hte[last_tossed].addr = pc;
	  hte[last_tossed].abuf = next_free;
	  next_free += n;
	  return hte[last_tossed].abuf;
	}
      // Neither cache nor hash table is full.
      else
	{
	  hte[i].addr = pc;
	  hte[i].abuf = next_free;
	  next_free += n;
	  return hte[i].abuf;
	}
    }

  // Initialize the begin_insn member.  There's only one copy of this insn
  // [per engine], it is not emitted into the instruction stream.

  void
  compile_begin_insn (cpu_class* cpu)
    {
      this->begin_insn.idesc =
	& this->begin_insn.idesc->idesc_table[this->begin_index];
      this->begin_insn.execute.cgoto = this->begin_insn.idesc->cgoto;
    }

  void
  compile_cond_insn (cpu_class* cpu, scache_record* abuf, PCADDR pc, UINT cond)
    {
      abuf->idesc = & abuf->idesc->idesc_table[this->cond_index];
      abuf->addr = pc;
      abuf->cond = cond;
      abuf->execute.cgoto = abuf->idesc->cgoto;
    }

  void
  compile_chain_insn (cpu_class* cpu, scache_record* abuf, PCADDR pc, unsigned insn_count)
    {
      abuf->idesc = & abuf->idesc->idesc_table[this->chain_index];
      abuf->addr = pc;
      abuf->fields.chain.insn_count = insn_count;
      abuf->fields.chain.next = 0;
      abuf->execute.cgoto = abuf->idesc->cgoto;
      // Close off this block.
      this->next_free = abuf + 1;
    }

  void
  compile_cti_chain_insn (cpu_class* cpu, scache_record* abuf, PCADDR pc, unsigned insn_count)
    {
      abuf->idesc = & abuf->idesc->idesc_table[this->cti_chain_index];
      abuf->addr = pc;
      abuf->fields.chain.insn_count = insn_count;
      abuf->fields.chain.next = 0;
      abuf->fields.chain.branch_target = 0;
      abuf->execute.cgoto = abuf->idesc->cgoto;
      // Close off this block.
      this->next_free = abuf + 1;
    }

  void
  compile_before_insn (cpu_class* cpu, scache_record* abuf, PCADDR pc, scache_record* insn)
    {
      abuf->idesc = & abuf->idesc->idesc_table[this->before_index];
      abuf->addr = pc;
      abuf->fields.before.insn = insn;
      abuf->execute.cgoto = abuf->idesc->cgoto;
    }

  void
  compile_after_insn (cpu_class* cpu, scache_record* abuf, PCADDR pc, scache_record* insn)
    {
      abuf->idesc = & abuf->idesc->idesc_table[this->after_index];
      abuf->addr = pc;
      abuf->fields.before.insn = insn; // XXX: yeah, sharing field with "before" insn
      abuf->execute.cgoto = abuf->idesc->cgoto;
    }

  /*inline*/ scache_record*
  pbb_chain (cpu_class* cpu, scache_record* abuf)
    {
      cpu->h_pc_set (abuf->addr);
      return chain (cpu, abuf->fields.chain.next, abuf->addr);
    }

  // This handles all forms of cti insns (uncond/cond,
  // cacheable-address/noncacheable-address), at the expense of two
  // compare/conditional-branches.  We don't do any of this in the insn's
  // handler as there can be virtual insns executed between it and us
  // [e.g. after,writeback].

  /*inline*/ scache_record*
  pbb_cti_chain (cpu_class* cpu, scache_record* abuf, branch_status br_status, PCADDR npc)
    {
      // Is address runtime computed?
      if (br_status == BRANCH_UNCACHEABLE)
	{
	  cpu->h_pc_set (npc);
	  return & this->begin_insn;
	}

      scache_record** link;
      if (br_status == BRANCH_UNTAKEN)
	{
	  npc = abuf->addr;
	  cpu->h_pc_set (npc);
	  link = & abuf->fields.chain.next;
	}
      else
	{
	  cpu->h_pc_set (npc);
	  link = & abuf->fields.chain.branch_target;
	}

      return chain (cpu, *link, npc);
    }

  /*inline*/ void
  pbb_before (cpu_class* cpu, scache_record* abuf)
    {
      if (UNLIKELY(cpu->trace_result_p))
	{
	  last_traced_pc_pbb = abuf->addr;
	  cpu->trace_stream
	    << "0x" << std::ios::hex << abuf->addr << std::ios::dec
	    << ": " << abuf->fields.before.insn->idesc->insn_name << "\t";
	}
    }

  /*inline*/ void
  pbb_after (cpu_class* cpu, scache_record* abuf)
    {
      if (UNLIKELY(cpu->trace_result_p))
	{
	  cpu->trace_stream << std::endl;

	  // This after hook may be called for an instruction one or two past the
	  // one for which pbb_begin was called.  This can happen for delay slots,
	  // for example.  By emitting an "extra" trace entry here, the difference
	  // between scache and pbb traces should disappear.

	  if (UNLIKELY((last_traced_pc_pbb != UNUSED_ADDR) && 
		       (last_traced_pc_pbb != abuf->addr)))
	    {
	      cpu->trace_stream
		<< "0x" << std::ios::hex << abuf->addr << std::ios::dec
		<< ": " << abuf->fields.before.insn->idesc->insn_name << "\t"
		<< std::endl;
	    }
	}
    }
};

// Instruction field support macros.

/* Treating the TOTAL least significant bits of VAL as a field, and
   numbering its leftmost bit zero, return the LENGTH-bit subfield
   whose leftmost bit is START.
   The '*SINT' version sign-extends; the '*UINT' version doesn't.  */
#define EXTRACT_MSB0_SINT(val, total, start, length) \
(((INT) (val) << ((sizeof (INT) * 8) - (total) + (start))) \
 >> ((sizeof (INT) * 8) - (length)))
#define EXTRACT_MSB0_UINT(val, total, start, length) \
(((UINT) (val) << ((sizeof (UINT) * 8) - (total) + (start))) \
 >> ((sizeof (UINT) * 8) - (length)))

/* Treating the TOTAL least significant bits of VAL as a field, and
   numbering its rightmost bit zero, return the LENGTH-bit subfield
   whose leftmost bit is START.
   The '*SINT' version sign-extends; the '*UINT' version doesn't.  */
#define EXTRACT_LSB0_SINT(val, total, start, length) \
(((INT) (val) << ((sizeof (INT) * 8) - (start) - 1)) \
 >> ((sizeof (INT) * 8) - (length)))
#define EXTRACT_LSB0_UINT(val, total, start, length) \
(((UINT) (val) << ((sizeof (UINT) * 8) - (start) - 1)) \
 >> ((sizeof (UINT) * 8) - (length)))

#define EXTRACT_MSB0_LGSINT(val, total, start, length) \
(((CGEN_INSN_LGSINT) (val) << ((sizeof (CGEN_INSN_LGSINT) * 8) - (total) + (start))) \
 >> ((sizeof (CGEN_INSN_LGSINT) * 8) - (length)))
#define EXTRACT_MSB0_LGUINT(val, total, start, length) \
(((CGEN_INSN_UINT) (val) << ((sizeof (CGEN_INSN_LGUINT) * 8) - (total) + (start))) \
 >> ((sizeof (CGEN_INSN_LGUINT) * 8) - (length)))

#define EXTRACT_LSB0_LGSINT(val, total, start, length) \
(((CGEN_INSN_LGSINT) (val) << ((sizeof (CGEN_INSN_LGSINT) * 8) - (start) - 1)) \
 >> ((sizeof (CGEN_INSN_LGSINT) * 8) - (length)))
#define EXTRACT_LSB0_LGUINT(val, total, start, length) \
(((CGEN_INSN_LGUINT) (val) << ((sizeof (CGEN_INSN_LGUINT) * 8) - (start) - 1)) \
 >> ((sizeof (CGEN_INSN_LGUINT) * 8) - (length)))

} // namespace cgen

#endif /* CGEN_CPU_H */
