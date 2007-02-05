%{

#include <assert.h>
#include "mepcfgtool.h"
#include "stdio.h"

extern int gmaplineno;
extern Gmap *currentgmap;
extern char *gmapfilename;

static int shadow_specified = 0;
static int gmap_error = 0;

static void
bad (const char *rulename, char *value)
{
  fprintf (stderr, "%s:%d: bad %s value: '%s'\n", 
	   gmapfilename, gmaplineno, rulename, value);
}

int
ignore_gmap (Gmap *g)
{
  long end;
  int error = 0;

  /* Ignore entries in the ranges 0x200000-0x2fffff, 0x300000-0x3fffff,
     0x600000-0x6fffff and 0x700000-0x7fffff.  */
  end = g->start + g->size;
  if (g->start < 0x400000 && end > 0x200000 || g->start < 0x800000 && end > 0x600000)
    {
      const char *n = g->name ? g->name : "unnamed";
      fprintf (stderr, "Warning: %s:%d: ignoring %s region: Bad range 0x%08x-0x%08x\n", 
	       gmapfilename, gmaplineno, n, g->start, end - 1);
      error = 1;
    }
  /* Ignore global shadows in the ranges 0x300000-0x3fffff, 0x700000-0x7fffff  */
  if (g->shadow_specified && ! g->shadow_mod_name)
    {
      end = g->shadow + g->size;
      if (g->shadow < 0x400000 && end > 0x300000 || g->shadow < 0x800000 && end > 0x700000)
	{
	  const char *n = g->name ? g->name : "unnamed";
	  fprintf (stderr, "Warning: %s:%d: ignoring %s region: Bad shadow range 0x%08x-0x%08x\n", 
		   gmapfilename, gmaplineno, n, g->shadow, end - 1);
	  error = 1;
	}
    }
  return error;
}

Gmap *
new_gmap (unsigned long start, unsigned long size,
	  const char *name, cache_ty cache, name_and_num shadow_spec,
	  scope_ty scope, type_ty type, access_ty access)
{
  Gmap *g;
  g = (Gmap *) xcalloc (sizeof (Gmap), 1);
  assert (g);
  g->next = 0;
  g->start = start;
  g->size = size;
  g->name = name;
  g->cache = cache;
  g->shadow_specified = shadow_specified;
  g->shadow = shadow_spec.num;
  g->shadow_mod_name = shadow_spec.name;
  g->scope = scope;
  g->type = type;
  g->access = access;
  return g;
}

static void
check_local_shadow_range (Gmap *g, Gmap* gmaps)
{
  /* For any given module:
     1) All local shadows must lie in the range 0xa0000000-0xafffffff
     2) The range of starting address
        of the first local shadow and the ending address of the last local
        shadow must be 0x800000.  */
  Gmap *i;
  unsigned long range_start, range_end;
  int first;

  assert (g->shadow_mod_name);
  first = 1;
  range_start = ~0u;
  range_end = 0;
  for (i = gmaps; i; i = i->next)
    {
      if (i->shadow_mod_name &&
	  strcasecmp (i->shadow_mod_name, g->shadow_mod_name) == 0)
      {
	unsigned long end;
	/* Make sure this module has not already been checked.  Determine
	   this by checking that g is the first local shadow for its module.
	*/
	if (first)
	  {
	    if (i != g)
	      return; /* already checked */
	    first = 0;
	  }

	/* Update the range of all the shadows.  */
	if (i->start < range_start)
	  range_start = i->start;
	end = i->start + i->size;
	if (end > range_end)
	  range_end = end;

      }      
    }

  /* Check the range of all the shadows.  */
  if (range_end - range_start != 0x800000)
    {
      fprintf (stderr,
	       "Warning: gmap local shadow regions for module %s must span an address range of size 0x800000\n",
	       g->shadow_mod_name);
    }
}

static Gmap *
check_global_shadow_access_and_range (Gmap* gmaps)
{
  Gmap *g, *i, *prev;
  int overlap_found;
  prev = NULL;
  for (g = gmaps; g; g = g->next)
    {
      unsigned long g_start;
      unsigned long g_end;
      /* We're only looking at range of global shadows here.  */
      if (! g->shadow_specified || g->shadow_mod_name)
	{
	  if (g->access == defaccess)
	    g->access = readwrite;
	  prev = g;
	  continue;
	}
      /* Break up this shadow into sections which completely cover
	 an existing real region. Inherit the access attribute of the
	 shadowed region.  */
      if (! prev || prev->name != g->name)
	overlap_found = 0;
      g_start = g->shadow;
      g_end = g_start + g->size;
      for (i = gmaps; i; i = i->next)
	{
	  unsigned long i_start;
	  unsigned long i_end;
	  if (i->shadow_specified)
	    continue;
	  assert (i != g);
	  i_start = i->start;
	  i_end = i_start + i->size;

	  /* Make sure this region is completely covered by the shadow.
	     Generate a warning for partialy covered regions.  */
	  if (i_start < g_start)
	    {
	      if (i_end > g_start)
		{
		  overlap_found = 1;
		  fprintf (stderr, "Warning: gmap region 0x%08x-0x%08x is only partially covered "
			   "by shadow region 0x%08x-0x%08x. This shadow mapping will be ignored.\n",
			   i_start, i_end - 1, g_start, g_end - 1);
		  /* Discard the entire shadow if it is completely contained by the target region,
		     otherwise chop off the part that overlaps.  */
		  if (i_end >= g_end)
		    {
		      if (prev)
			prev->next = g->next;
		      else
			gmaps = gmaps->next;
		      break;
		    }
		  g->shadow += i_end - g_start;
		  g->start += i_end - g_start;
		  g->size -= i_end - g_start;
		  g_start = i_end;
		}
	      continue;
	    }
	  if (i_end > g_end)
	    {
	      if (i_start < g_end)
		{
		  overlap_found = 1;
		  fprintf (stderr, "Warning: gmap region 0x%08x-0x%08x is only partially covered "
			   "by shadow region 0x%08x-0x%08x. This shadow mapping will be ignored.\n",
			   i_start, i_end - 1, g_start, g_end - 1);
		  /* Chop off the part that overlaps.  */
		  g->size -= g_end - i_start;
		  g_end = i_start;
		}
	      continue;
	    }

	  /* Break the shadow up into pieces: The portion before this region,
	     the portion which covers this region and the portion after
	     this region.  */
	  overlap_found = 1;
	  if (i_end < g_end)
	    {
	      name_and_num s = {i_end, 0};
	      Gmap *x = new_gmap (g->start + (i_end - g_start), g_end - i_end, g->name, g->cache, s,
				  g->scope, g->type, g->access);
	      x->next = g->next;
	      g->next = x;
	      g->size -= x->size;
	    }
	  if (i_start > g_start)
	    {
	      name_and_num s = {g->shadow, 0};
	      Gmap *x = new_gmap (g->start, i_start - g_start, g->name, g->cache, s,
				  g->scope, g->type, g->access);
	      x->next = g->next;
	      g->next = x;
	      g->start += x->size;
	      g->size -= x->size;
	      g->shadow += x->size;
	    }
	  /* The piece left in g is the piece which covers the region. Check that
	     the region being covered is not also a shadow.  */
	  if (i->shadow_specified)
	    {
	      fprintf (stderr, "Error: gmap shadow region 0x%08x-0x%08x is also a shadow\n",
		       g->start, g->start + g->size - 1);
	      gmap_error = 1;
	    }
	  /* Inherit the region's access attribute.  */
	  if (i->access == defaccess)
	    i->access = readwrite;
	  if (g->access != i->access && g->access != defaccess)
	      fprintf (stderr, "Warning: Changing gmap region 0x%08x-0x%08x from %s to %s\n",
		       g->start, g->start + g->size - 1,
		       g->access == readonly ? "ro" : "rw",
		       i->access == readonly ? "ro" : "rw");
	  g->access = i->access;
	  prev = g;
	  break; /* back to outer loop */
	}
      if (! overlap_found)
	{
	  fprintf (stderr, "Warning: gmap shadow 0x%08x-0x%08x does not cover any real region. "
		   "This shadow mapping will be ignored.\n",
		   g_start, g_end - 1);
	  if (prev)
	    prev->next = g->next;
	  else
	    gmaps = gmaps->next;
	}
    }

  return gmaps;
}

/* Certain regions must be cached/uncached according to this table provided by
   Toshiba. See the MeP Architecture Document for details.  */
typedef struct
{
  unsigned long low;
  unsigned long high;
  cache_ty cache;
} CACHE_MAP_RECORD;

static CACHE_MAP_RECORD cache_map[] =
{
  {0x00000000, 0x001fffff, nocache},
  {0x00400000, 0x006fffff, nocache},
  {0x00800000, 0x00ffffff, cache},
  {0x01000000, 0x7fffffff, cache},
  {0x80000000, 0xbfffffff, nocache},
  {0xc0000000, 0xffffffff, cache}
};

static Gmap *
check_gmaps (Gmap *gmaps)
{
  int i;
  Gmap *g, *prev, *head;

  /* Check for conflicts between gmap records.  */
  head = gmaps;
  prev = NULL;
  for (g = gmaps; g != NULL; g = g->next)
    {
      unsigned long g_end;
      Gmap *r;

      /* See if this record is to be ignored.  */
      if (ignore_gmap (g))
      {
	if (prev)
	  prev->next = g->next;
	else
	  head = g->next;
	continue;
      }

      /* Check the cacheability of each region.  */
      g_end = g->start + g->size;
      for (i = 0; i < sizeof cache_map / sizeof (*cache_map); ++i)
	{
	  if (g->start <= cache_map[i].high && g_end > cache_map[i].low
	      && g->cache != cache_map[i].cache)
	    {
	      fprintf (stderr,
		       "Warning: Changing gmap region 0x%08x-0x%08x from %s to %s\n",
		       g->start, g_end - 1,
		       g->cache == cache ? "cached" : "uncached",
		       cache_map[i].cache == cache ? "cached" : "uncached");
	    }
	}

      /* Checks for local shadows.  */
      if (g->shadow_mod_name)
	{
	  /* Check the range of this shadow.  */
	  if (g->start < 0xa0000000 || g_end > 0xb0000000)
	    {
	      fprintf (stderr,
		       "Warning: gmap local shadow region 0x%08x-0x%08x is not in the range 0xa0000000-0xafffffff\n",
		       g->start, g_end - 1);
	    }
	  /* Check the range of local shadows to the same module.  */
	  check_local_shadow_range (g, head);
	}

      /* Check for conflicts with the remaining gmap records.  */
      for (r = g->next; r != NULL; r = r->next)
	{
	  /* Check for overlapping regions.  */
	  unsigned long i_end = r->start + r->size;
	  if (g->start < i_end && g_end > r->start)
	    {
	      fprintf (stderr,
		       "Warning: gmap region 0x%08x-0x%08x overlaps region 0x%08x-0x%08x\n",
		       r->start, i_end - 1,
		       g->start, g_end - 1);
	    }
	}
      prev = g;
    }

  /* Check the range and access of global shadows against their
     real memory.  */
  head = check_global_shadow_access_and_range (head);

  if (gmap_error)
    exit (EXIT_FAILURE);

  return head;
}

#define YYERROR_VERBOSE 1


%}

%union {
  scope_ty scope;
  access_ty access;
  type_ty type;
  cache_ty cache;  
  unsigned long num;
  name_and_num nn;
  char *str;
  Gmap *gmap;
}

%token <str> STR
%token <num> NUM

%type <gmap> gmaps
%type <gmap> gmap
%type <num> start
%type <num> size
%type <str> name
%type <cache> cache
%type <nn> shadow
%type <scope> scope
%type <type> type
%type <access> access
%%

file:
 gmaps { currentgmap = check_gmaps ($1); }
;

gmaps:
  gmap gmaps { if ($1) {$1->next = $2; $$ = $1;}
               else $$ = $2; }
|            { $$ = 0; }
;

gmap:
  start ':' size ':' name ':' cache ':' 
  shadow ':' scope ':' type ':' access ';'
{ $$ = new_gmap ($1, $3, $5, $7, $9, $11, $13, $15); }
;

start: 
  NUM           { $$ = $1; }
;

size:  
  NUM           { $$ = $1; }
;

name: 
  STR           { $$ = $1; }
|               { $$ = 0; }
;

cache:
STR             { char *s = $1;
                  if (strcmp (s, "Cache") == 0 || strcmp (s, "cache") == 0)
		    $$ = cache;
                  else { bad ("cache", s); $$ = nocache; } }
|               { $$ = nocache; }
;

shadow:  
  NUM              { $$.num = $1; $$.name = 0; shadow_specified = 1; } 
| NUM '(' STR ')'  { $$.num = $1; $$.name = $3; shadow_specified = 1; } 
|                  { $$.num = 0; $$.name = 0; shadow_specified = 0; }
;

scope:
  STR           { char *s = $1;
                  if (strcmp (s, "global") == 0) $$ = sc_global;
                  else if (strcmp (s, "local") == 0) $$ = sc_local;
                  else { bad ("scope", s); $$ = sc_global; } }
|               { $$ = sc_global; }
;

type:
  STR           { char *s = $1;
                  if (strcmp (s, "memory") == 0) $$ = memory;
                  else if (strcmp (s, "peripheral") == 0) $$ = peripheral;
                  else if (strcmp (s, "main_bus") == 0) $$ = mainbus;
                  else if (strcmp (s, "others") == 0) $$ = others;
                  else if (strcmp (s, "shadow") == 0) $$ = shadow;
                  else if (strcmp (s, "local") == 0) $$ = local;
                  else if (strcmp (s, "reserved") == 0) $$ = reserved;
                  else if (strcmp (s, "undefined") == 0) $$ = undefined;
                  else { bad ("type", s); $$ = undefined; } }
|               { $$ = undefined; }
;

access:
  STR           { char *s = $1;
                  if (strcmp (s, "ro") == 0) $$ = readonly;
                  else if (strcmp (s, "rw") == 0) $$ = readwrite;
                  else { bad ("access type", s); $$ = readwrite; } }
|               { $$ = defaccess; }
;

%%

int
gmaperror (char *s)
{
  fprintf (stderr, "%s:%d: %s\n", gmapfilename, gmaplineno, s);
}
