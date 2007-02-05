/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NEWLINE = 258,
     STR = 259,
     QSTR = 260,
     NUM = 261,
     KWD_CLASS_NAME = 262,
     KWD_ARGC = 263,
     KWD_BASE_DIR = 264,
     KWD_INCLUDE_FILE = 265,
     KWD_LIB_FILE = 266,
     KWD_FILES = 267,
     KWD_CPPFLAGS = 268,
     KWD_END = 269,
     KWD_INT_CHANNEL = 270,
     KWD_MAPPED_REGION_NAME = 271,
     KWD_MAPSTO = 272,
     KWD_RTL_MODEL_TYPE = 273,
     KWD_RTL_MODULE_NAME = 274,
     KWD_RTL_FILES = 275,
     KWD_RTL_BASE_DIR = 276,
     KWD_RTL_INCLUDE_FILE = 277
   };
#endif
#define NEWLINE 258
#define STR 259
#define QSTR 260
#define NUM 261
#define KWD_CLASS_NAME 262
#define KWD_ARGC 263
#define KWD_BASE_DIR 264
#define KWD_INCLUDE_FILE 265
#define KWD_LIB_FILE 266
#define KWD_FILES 267
#define KWD_CPPFLAGS 268
#define KWD_END 269
#define KWD_INT_CHANNEL 270
#define KWD_MAPPED_REGION_NAME 271
#define KWD_MAPSTO 272
#define KWD_RTL_MODEL_TYPE 273
#define KWD_RTL_MODULE_NAME 274
#define KWD_RTL_FILES 275
#define KWD_RTL_BASE_DIR 276
#define KWD_RTL_INCLUDE_FILE 277




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 93 "/home/brolley/sources/src/utils/mep/cmodel.y"
typedef union YYSTYPE {
  unsigned long num;
  char *str;
  CModel *cmodel;
} YYSTYPE;
/* Line 1318 of yacc.c.  */
#line 87 "/home/brolley/sources/src/utils/mep/parse.cmodel.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE cmodellval;



