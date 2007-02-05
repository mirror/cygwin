/* Configuration Tool for Toshiba Media Processor
   Copyright (C) 2001-2005 Free Software Foundation, Inc.
   Contributed by Red Hat Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with This program; see the file COPYING.  If not, write to the
Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__MSDOS__) || defined(_WIN32) || defined(__OS2__) || defined (__CYGWIN__)
#define IS_DRIVE_SEPARATOR(c) ((c) == ':')
#else
#define IS_DRIVE_SEPARATOR(c) 0
#endif

typedef enum { sc_local, sc_global } scope_ty;
typedef enum { cache, nocache } cache_ty;
typedef enum { memory, peripheral, mainbus, others, 
	       shadow, local, reserved, undefined } type_ty;
typedef enum { readonly, readwrite, defaccess } access_ty;

typedef enum { MEP_CORE_UNKNOWN,
	       MEP_CORE_C2 = 1, MEP_CORE_c2 = MEP_CORE_C2,
	       MEP_CORE_C3 = 2, MEP_CORE_c3 = MEP_CORE_C3,
	       MEP_CORE_C4 = 3, MEP_CORE_c4 = MEP_CORE_C4,
	       MEP_CORE_H1 = 4, MEP_CORE_h1 = MEP_CORE_H1
} mep_core_ty;

typedef enum { MEP_ENDIAN_BIG, MEP_ENDIAN_LITTLE } mep_endian_ty;

typedef struct { 
  unsigned long num; 
  const char *name; 
} 
name_and_num;

typedef struct Gmap
{
  struct Gmap *next;
  unsigned long start;
  unsigned long size;
  const char *name;
  cache_ty cache;
  int shadow_specified;
  unsigned long shadow;
  const char *shadow_mod_name;
  scope_ty scope;
  type_ty type;
  access_ty access;
} 
Gmap;

#define N_NONE	0
#define N_WORD	1 /* unquoted string */
#define N_QSTR	2 /* quoted string */
#define N_NUM	4
#define N_SUB	8

typedef struct Node
{
  const char *id;
  int type;
  const char *val;
  unsigned long ival;
  struct Node *sub;
  struct Node *next, *up;
  /* For error reporting.  */
  const char *filename;
  int lineno;
  int counted;
}
Node;


typedef enum {
  cmTypeUnknown, cmTypeHWengine, cmTypeUci, cmTypeDsp, cmTypePeripheral,
  cmTypeBusArbitrator
} CmodelType;

typedef struct CModel
{
  CmodelType type;
  const char *instance_name;
  char *class_name;
  unsigned argc;
  const char *cfg_args; /* XXX: fetch from outside the cmodel info file */
  char *base_dir;
  char *include_file;
  char *lib_file;
  char *cppflags;
  unsigned files_size;
  unsigned num_files;
  char **files;
  unsigned ints_size;
  unsigned num_ints;
  char **int_keys;
  unsigned *int_channels;
  char *mapped_region_name;
  char *rtl_model_type;
  char *rtl_module_name;
  unsigned num_rtl_files;
  char *rtl_base_dir;
  char *rtl_include_file;

  struct CModel *prev;
}
CModel;

extern Node *new_node (const char *name, Node *sub);
extern Node *find_sub (Node *parent, ...);
extern Node *find_typed_sub (Node *parent, int type, ...);
extern Node *find_next (Node *current, const char *id);

extern Gmap *new_gmap (unsigned long start, unsigned long size,
		       const char *name, cache_ty cache, name_and_num shadow_spec,
		       scope_ty scope, type_ty type, access_ty access);

extern void compare_configs (Node *, Node *);

extern void process_arcadia_files (Node *);
extern void verify_config (Node *);
extern void check_corecount_limit (void);
extern void check_biu (void);

extern void warn (const char *fmt, ...);
extern void warnn (Node *node, const char *fmt, ...);
extern void error (const char *fmt, ...);
extern void errorn (Node *node, const char *fmt, ...);
extern void fatal (const char *fmt, ...);

extern char *hex_pr (int val);

extern const char *resolve_local_filename (const char *filename);
extern const char *resolve_source_filename (const char *filename);

#define MAX_CORE_ID 255
