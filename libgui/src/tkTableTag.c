/* 
 * tkTableTag.c --
 *
 *	This module implements tags for table widgets.
 *
 * Copyright (c) 1998 Jeffrey Hobbs
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 */

#include "tkTable.h"

static void	CreateTagEntry _ANSI_ARGS_((Table *tablePtr, char *name,
					    int argc, char **argv));
static void	TableImageProc _ANSI_ARGS_((ClientData clientData, int x,
					    int y, int width, int height,
					    int imageWidth, int imageHeight));

/* tag subcommands */
#define TAG_CELLTAG	1	/* tag a cell */
#define TAG_CGET	2	/* get a config value */
#define TAG_COLTAG	3	/* tag a column */
#define	TAG_CONFIGURE	4	/* config/create a new tag */
#define	TAG_DELETE	5	/* delete a tag */
#define TAG_EXISTS	6	/* does a tag exist? */
#define	TAG_NAMES	7	/* print the tag names */
#define TAG_ROWTAG	8	/* tag a row */
#define TAG_INCLUDES	9	/* does an index have a particular tag */

static Cmd_Struct tag_cmds[] = {
  {"celltag",	TAG_CELLTAG},
  {"coltag",	TAG_COLTAG},
  {"configure",	TAG_CONFIGURE},
  {"cget",	TAG_CGET},
  {"delete",	TAG_DELETE},
  {"exists",	TAG_EXISTS},
  {"names",	TAG_NAMES},
  {"rowtag",	TAG_ROWTAG},
  {"includes",	TAG_INCLUDES},
  {"", 0}
};

static Cmd_Struct tagState_vals[]= {
  {"unknown",	 STATE_UNKNOWN},
  {"normal",	 STATE_NORMAL},
  {"disabled",	 STATE_DISABLED},
  {"",		 0 }
};

static Tk_CustomOption tagStateOpt = { Cmd_OptionSet, Cmd_OptionGet,
				       (ClientData)(&tagState_vals) };

/*
 * The default specification for configuring tags
 * Done like this to make the command line parsing easy
 */

static Tk_ConfigSpec tagConfig[] = {
  {TK_CONFIG_ANCHOR, "-anchor", "anchor", "Anchor", "center",
   Tk_Offset(TableTag, anchor), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_BORDER, "-background", "background", "Background", NULL,
   Tk_Offset(TableTag, bg),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_SYNONYM, "-bg", "background", (char *) NULL,
   (char *) NULL, 0, 0 },
  {TK_CONFIG_BORDER, "-foreground", "foreground", "Foreground", NULL,
   Tk_Offset(TableTag, fg),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_SYNONYM, "-fg", "foreground", (char *) NULL,
   (char *) NULL, 0, 0 },
  {TK_CONFIG_FONT, "-font", "font", "Font", NULL,
   Tk_Offset(TableTag, tkfont),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_STRING, "-image", "image", "Image", NULL,
   Tk_Offset(TableTag, imageStr),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_JUSTIFY, "-justify", "justify", "Justify", "left",
   Tk_Offset(TableTag, justify), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_INT, "-multiline", "multiline", "Multiline", "1",
   Tk_Offset(TableTag, multiline), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_RELIEF, "-relief", "relief", "Relief", "flat",
   Tk_Offset(TableTag, relief),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_INT, "-showtext", "showText", "ShowText", "0",
   Tk_Offset(TableTag, showtext), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_CUSTOM, "-state", "state", "State", "unknown",
   Tk_Offset(TableTag, state), TK_CONFIG_DONT_SET_DEFAULT, &tagStateOpt },
  {TK_CONFIG_INT, "-wrap", "wrap", "Wrap", "0",
   Tk_Offset(TableTag, wrap), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_END, (char *) NULL, (char *) NULL, (char *) NULL,
   (char *) NULL, 0, 0 }
};

/* 
 *----------------------------------------------------------------------
 *
 * TableImageProc --
 *	Called when an image associated with a tag is changed.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Invalidates the whole table.
 *	FIX - should only invalidate affected cells.
 *
 *----------------------------------------------------------------------
 */
static void
TableImageProc(ClientData clientData, int x, int y, int width, int height,
	       int imageWidth, int imageHeight)
{
  TableInvalidateAll((Table *)clientData, 0);
}

/*
 *----------------------------------------------------------------------
 *
 * TableNewTag --
 *	ckallocs space for a new tag structure and inits the structure.
 *
 * Results:
 *	Returns a pointer to the new structure.  Must be freed later.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
TableTag *
TableNewTag(void)
{
  TableTag *tagPtr = (TableTag *) ckalloc(sizeof(TableTag));
  tagPtr->anchor	= (Tk_Anchor)-1;
  tagPtr->bg		= NULL;
  tagPtr->fg		= NULL;
  tagPtr->tkfont	= NULL;
  tagPtr->image		= NULL;
  tagPtr->imageStr	= NULL;
  tagPtr->justify	= (Tk_Justify)-1;
  tagPtr->multiline	= -1;
  tagPtr->relief	= -1;
  tagPtr->showtext	= -1;
  tagPtr->state		= STATE_UNKNOWN;
  tagPtr->wrap		= -1;
  return tagPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * TableMergeTag --
 *	This routine merges two tags by adding any fields from the addTag
 *	that are set to the baseTag.
 *
 * Results:
 *	baseTag will inherit all set characteristics of addTag
 *	(addTag thus has the priority).
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
TableMergeTag(TableTag *baseTag, TableTag *addTag)
{
  if (addTag->anchor != (Tk_Anchor)-1)	baseTag->anchor = addTag->anchor;
  if (addTag->bg != NULL)		baseTag->bg = addTag->bg;
  if (addTag->fg != NULL)		baseTag->fg = addTag->fg;
  if (addTag->tkfont != NULL)		baseTag->tkfont = addTag->tkfont;
  if (addTag->imageStr != NULL) {
    baseTag->imageStr = addTag->imageStr;
    baseTag->image = addTag->image;
  }
  if (addTag->multiline >= 0)		baseTag->multiline = addTag->multiline;
  if (addTag->relief != -1)		baseTag->relief = addTag->relief;
  if (addTag->showtext >= 0)		baseTag->showtext = addTag->showtext;
  if (addTag->state != STATE_UNKNOWN)	baseTag->state = addTag->state;
  if (addTag->justify != (Tk_Justify)-1) baseTag->justify = addTag->justify;
  if (addTag->wrap >= 0)		baseTag->wrap = addTag->wrap;
}

/*
 *----------------------------------------------------------------------
 *
 * TableInvertTag --
 *	This routine swaps background and foreground for the selected tag.
 *
 * Results:
 *	Inverts fg and bg of tag.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
TableInvertTag(TableTag *baseTag)
{
  Tk_3DBorder tmpBg;

  tmpBg = baseTag->fg;
  baseTag->fg = baseTag->bg;
  baseTag->bg = tmpBg;
}

/*
 *----------------------------------------------------------------------
 *
 * CreateTagEntry --
 *	Takes a name and optional args and create a tag entry in the
 *	table's tag table.
 *
 * Results:
 *	A new tag entry will be created.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
CreateTagEntry(Table *tablePtr, char *name, int argc, char **argv)
{
  Tcl_HashEntry *entryPtr;
  TableTag *tagPtr = TableNewTag();
  int dummy;
  Tk_ConfigureWidget(tablePtr->interp, tablePtr->tkwin, tagConfig,
		     argc, argv, (char *)tagPtr, TK_CONFIG_ARGV_ONLY);
  entryPtr = Tcl_CreateHashEntry(tablePtr->tagTable, name, &dummy);
  Tcl_SetHashValue(entryPtr, (ClientData) tagPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * TableInitTags --
 *	Creates the static table tags.
 *
 * Results:
 *	active, sel, title and flash are created as tags.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
TableInitTags(Table *tablePtr)
{
  static char *activeArgs[]	= {"-bg", ACTIVE_BG, "-relief", "flat" };
  static char *selArgs[]	= {"-bg", SELECT_BG, "-relief", "sunken" };
  static char *titleArgs[]	= {"-bg", DISABLED,  "-relief", "flat",
				   "-fg", "white", "-state", "disabled" };
  static char *flashArgs[]	= {"-bg", "red" };
  CreateTagEntry(tablePtr, "active", ARSIZE(activeArgs), activeArgs);
  CreateTagEntry(tablePtr, "sel", ARSIZE(selArgs), selArgs);
  CreateTagEntry(tablePtr, "title", ARSIZE(titleArgs), titleArgs);
  CreateTagEntry(tablePtr, "flash", ARSIZE(flashArgs), flashArgs);
}

/*
 *----------------------------------------------------------------------
 *
 * FindRowColTag --
 *	Finds a row/col tag based on the row/col styles and tagCommand.
 *
 * Results:
 *	Returns tag associated with row/col cell, if any.
 *
 * Side effects:
 *	Possible side effects from eval of tagCommand.
 *
 *----------------------------------------------------------------------
 */
TableTag *
FindRowColTag(Table *tablePtr, int cell, int mode)
{
  Tcl_HashTable *hash;
  Tcl_HashEntry *entryPtr;

  hash = (mode == ROW) ? tablePtr->rowStyles : tablePtr->colStyles;
  if ((entryPtr = Tcl_FindHashEntry(hash, (char *)cell)) == NULL) {
    char *cmd = (mode == ROW) ? tablePtr->rowTagCmd : tablePtr->colTagCmd;
    if (cmd) {
      register Tcl_Interp *interp = tablePtr->interp;
      char buf[INDEX_BUFSIZE];
      /* Since it does not exist, eval command with row/col appended */
      sprintf(buf, " %d", cell);
      Tcl_Preserve((ClientData) interp);
      if (Tcl_VarEval(interp, cmd, buf, (char *)NULL) == TCL_OK) {
	char *name = Tcl_GetStringResult(interp);
	if (name && *name) {
	  /* If a result was returned, check to see if it is a known tag */
	  entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, name);
	}
      }
      Tcl_Release((ClientData) interp);
      Tcl_ResetResult(interp);
    }
  }
  return (TableTag *) (entryPtr ? Tcl_GetHashValue(entryPtr) : NULL);
}

/* 
 *----------------------------------------------------------------------
 *
 * TableCleanupTag --
 *	Releases the resources used by a tag before it is freed up.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The tag is no longer valid.
 *
 *----------------------------------------------------------------------
 */
void
TableCleanupTag(Table *tablePtr, TableTag *tagPtr)
{
  if (tagPtr->image)
    Tk_FreeImage(tagPtr->image);
  /* free the options in the widget */
  Tk_FreeOptions(tagConfig, (char *) tagPtr, tablePtr->display, 0);
}

/*
 *--------------------------------------------------------------
 *
 * TableTagCmd --
 *	This procedure is invoked to process the tag method
 *	that corresponds to a widget managed by this module.
 *	See the user documentation for details on what it does.
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side effects:
 *	See the user documentation.
 *
 *--------------------------------------------------------------
 */
int
TableTagCmd(Table * tablePtr, register Tcl_Interp *interp,
	    int argc, char *argv[])
{
  int result = TCL_OK, retval, i, newEntry, value;
  int row, col;
  TableTag *tagPtr;
  Tcl_HashEntry *entryPtr, *scanPtr, *newEntryPtr, *oldEntryPtr;
  Tcl_HashTable *hashTblPtr;
  Tcl_HashSearch search;
  Tk_Image image;
  char buf[INDEX_BUFSIZE], *keybuf, *yes = "1", *no = "0";

  /* parse the next argument */
  retval = Cmd_Parse(interp, tag_cmds, argv[2]);
  switch (retval) {
    /* failed to parse the argument, error */
  case 0:
    return TCL_ERROR;

  case TAG_CELLTAG:
    /* tag a (group of) cell(s) */
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " tag cell tag ?arg arg ...?\"", (char *) NULL);
      return TCL_ERROR;
    }
    /* are we deleting */
    if (!(*argv[3]))
      tagPtr = NULL;
    else {
      /* check to see if the tag actually exists */
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, argv[3]))==NULL) {
	/* Unknown tag, just return empty string */
	Tcl_SetResult(interp, (char *) NULL, TCL_STATIC);
	return TCL_OK;
      }
      /* get the pointer to the tag structure */
      tagPtr = (TableTag *) Tcl_GetHashValue (entryPtr);
    }

    /* No more args -> display only */
    if (argc == 4) {
      /* Added special handling for tags: active, flash, sel, title */

      if ((tablePtr->flags & HAS_ACTIVE) && strcmp(argv[3], "active") == 0) {
	TableMakeArrayIndex(tablePtr->activeRow+tablePtr->rowOffset,
			    tablePtr->activeCol+tablePtr->colOffset, buf);
	Tcl_AppendElement(interp, buf);
      } else if (tablePtr->flashMode && strcmp(argv[3], "flash") == 0) {
	for (scanPtr = Tcl_FirstHashEntry(tablePtr->flashCells, &search);
	     scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search)) {
	  Tcl_AppendElement(interp,
			    Tcl_GetHashKey(tablePtr->flashCells, scanPtr));
	}
      } else if (strcmp(argv[3], "sel") == 0) {
	for (scanPtr = Tcl_FirstHashEntry(tablePtr->selCells, &search);
	     scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search)) {
	  Tcl_AppendElement(interp,
			    Tcl_GetHashKey(tablePtr->selCells, scanPtr));
	}
      } else if (strcmp(argv[3], "title") == 0 &&
		 (tablePtr->titleRows || tablePtr->titleCols)) {
	for (row = tablePtr->rowOffset;
	     row < tablePtr->rowOffset+tablePtr->rows; row++) {
	  for (col = tablePtr->colOffset;
	       col < tablePtr->colOffset+tablePtr->titleCols; col++) {
	    TableMakeArrayIndex(row, col, buf);
	    Tcl_AppendElement(interp, buf);
	  }
	}
	for (row = tablePtr->rowOffset;
	     row < tablePtr->rowOffset+tablePtr->titleRows; row++) {
	  for (col = tablePtr->colOffset+tablePtr->titleCols;
	       col < tablePtr->colOffset+tablePtr->cols; col++) {
	    TableMakeArrayIndex(row, col, buf);
	    Tcl_AppendElement(interp, buf);
	  }
	}
      } else {
	for (scanPtr = Tcl_FirstHashEntry(tablePtr->cellStyles, &search);
	     scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search)) {
	  /* is this the tag pointer for this cell */
	  if ((TableTag *) Tcl_GetHashValue(scanPtr) == tagPtr) {
	    Tcl_AppendElement(interp,
			      Tcl_GetHashKey(tablePtr->cellStyles, scanPtr));
	  }
	}
      }
      return TCL_OK;
    }
    /* Now loop through the arguments and fill in the hash table */
    for (i = 4; i < argc; i++) {
      /* can I parse this argument */
      if (TableGetIndex(tablePtr, argv[i], &row, &col) != TCL_OK) {
	return TCL_ERROR;
      }
      /* get the hash key ready */
      TableMakeArrayIndex(row, col, buf);

      /* is this a deletion */
      if (tagPtr == NULL) {
	oldEntryPtr = Tcl_FindHashEntry(tablePtr->cellStyles, buf);
	if (oldEntryPtr != NULL)
	  Tcl_DeleteHashEntry(oldEntryPtr);
      } else {
	/* add a key to the hash table */
	newEntryPtr = Tcl_CreateHashEntry(tablePtr->cellStyles, buf,
					   &newEntry);

	/* and set it to point to the Tag structure */
	Tcl_SetHashValue (newEntryPtr, (ClientData) tagPtr);
      }
      /* now invalidate the area */
      TableRefresh(tablePtr, row-tablePtr->rowOffset,
		   col-tablePtr->colOffset, CELL);
    }
    return TCL_OK;

  case TAG_COLTAG:
  case TAG_ROWTAG:
    /* tag a row or a column */
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
			argv[0], " tag ", (retval == TAG_ROWTAG) ? "row" :
			"col", " tag ?arg arg ..?\"", (char *) NULL);
      return TCL_ERROR;
    }
    /* if the tag is null, we are deleting */
    if (!(*argv[3]))
      tagPtr = NULL;
    else {			/* check to see if the tag actually exists */
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, argv[3]))==NULL) {
	/* Unknown tag, just return empty string */
	Tcl_SetResult(interp, (char *) NULL, TCL_STATIC);
	return TCL_OK;
      }
      /* get the pointer to the tag structure */
      tagPtr = (TableTag *) Tcl_GetHashValue (entryPtr);
    }

    /* and choose the correct hash table */
    hashTblPtr = (retval == TAG_ROWTAG) ?
      tablePtr->rowStyles : tablePtr->colStyles;

    /* No more args -> display only */
    if (argc == 4) {
      for (scanPtr = Tcl_FirstHashEntry(hashTblPtr, &search);
	   scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search)) {
	/* is this the tag pointer on this row */
	if ((TableTag *) Tcl_GetHashValue (scanPtr) == tagPtr) {
	  sprintf(buf, "%d", (int) Tcl_GetHashKey (hashTblPtr, scanPtr));
	  Tcl_AppendElement(interp, buf);
	}
      }
      return TCL_OK;
    }
    /* Now loop through the arguments and fill in the hash table */
    for (i = 4; i < argc; i++) {
      /* can I parse this argument */
      if (Tcl_GetInt(interp, argv[i], &value) != TCL_OK) {
	return TCL_ERROR;
      }
      /* deleting or adding */
      if (tagPtr == NULL) {
	oldEntryPtr = Tcl_FindHashEntry(hashTblPtr, (char *) value);
	if (oldEntryPtr != NULL)
	  Tcl_DeleteHashEntry(oldEntryPtr);
      } else {
	/* add a key to the hash table */
	newEntryPtr = Tcl_CreateHashEntry(hashTblPtr, (char *) value,
					  &newEntry);

	/* and set it to point to the Tag structure */
	Tcl_SetHashValue (newEntryPtr, (ClientData) tagPtr);
      }
      /* and invalidate the row or column affected */
      if (retval == TAG_ROWTAG) {
	TableRefresh(tablePtr, value-tablePtr->rowOffset, 0, ROW);
      } else {
	TableRefresh(tablePtr, 0, value-tablePtr->colOffset, COL);
      }
    }
    return TCL_OK;	/* COLTAG && ROWTAG */

  case TAG_CGET:
    if (argc != 5) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
                       argv[0], " tag cget tagName option\"", (char *) NULL);
      return TCL_ERROR;
    }
    if ((entryPtr=Tcl_FindHashEntry(tablePtr->tagTable, argv[3])) == NULL) {
      Tcl_AppendResult(interp, "invalid tag name \"", argv[3],
		       "\"", (char *) NULL);
      return TCL_ERROR;
    } else {
      tagPtr = (TableTag *) Tcl_GetHashValue (entryPtr);
      result = Tk_ConfigureValue(interp, tablePtr->tkwin, tagConfig,
				 (char *) tagPtr, argv[4], 0);
    }
    return result;	/* CGET */

  case TAG_CONFIGURE:
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
		       argv[0], " tag configure tagName ?arg arg  ...?\"",
		       (char *) NULL);
      return TCL_ERROR;
    }
    /* first see if this is a reconfiguration */
    entryPtr = Tcl_CreateHashEntry(tablePtr->tagTable, argv[3], &newEntry);
    if (newEntry) {
      /* create the structure */
      tagPtr = TableNewTag();

      /* insert it into the table */
      Tcl_SetHashValue(entryPtr, (ClientData) tagPtr);

      /* configure the tag structure */
      result = Tk_ConfigureWidget(interp, tablePtr->tkwin, tagConfig,
				  argc - 4, argv + 4, (char *) tagPtr, 0);
      if (result == TCL_ERROR)
	return TCL_ERROR;
    } else {
      /* pointer wasn't null, do a reconfig if we have enough arguments */
      /* get the tag pointer from the table */
      tagPtr = (TableTag *) Tcl_GetHashValue(entryPtr);

      /* 5 args means that there are values to replace */
      if (argc > 5) {
	/* and do a reconfigure */
	result = Tk_ConfigureWidget(interp, tablePtr->tkwin,
				    tagConfig, argc - 4, argv + 4,
				    (char *) tagPtr, TK_CONFIG_ARGV_ONLY);
	if (result == TCL_ERROR)
	  return TCL_ERROR;
      }
    }

    /* handle change of image name */
    if (tagPtr->imageStr) {
      image = Tk_GetImage(interp, tablePtr->tkwin, tagPtr->imageStr,
			  TableImageProc, (ClientData)tablePtr);
      if (image == NULL)
	result = TCL_ERROR;
    } else {
      image = NULL;
    }
    if (tagPtr->image) {
      Tk_FreeImage(tagPtr->image);
    }
    tagPtr->image = image;

    /* 
     * If there were less than 6 args, we need
     * to do a printout of the config, even for new tags
     */
    if (argc < 6) {
      result = Tk_ConfigureInfo(interp, tablePtr->tkwin, tagConfig,
				(char *) tagPtr, (argc == 5)?argv[4]:0, 0);
    } else {
      /* Otherwise we reconfigured so invalidate the table for a redraw */
      TableInvalidateAll(tablePtr, 0);
    }
    return result;

  case TAG_DELETE:
    /* delete a tag */
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
	       argv[0], " tag delete tagName ?tagName ...?\"", (char *) NULL);
      return TCL_ERROR;
    }
    /* run through the remaining arguments */
    for (i = 3; i < argc; i++) {
      /* cannot delete the title tag */
      if (strcmp(argv[i], "title") == 0 || strcmp (argv[i], "sel") == 0 ||
	  strcmp(argv[i], "flash") == 0 || strcmp (argv[i], "active") == 0) {
	Tcl_AppendResult(interp, "cannot delete ", argv[i],
			  " tag", (char *) NULL);
	return TCL_ERROR;
      }
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, argv[i]))!=NULL) {
	/* get the tag pointer */
	tagPtr = (TableTag *) Tcl_GetHashValue(entryPtr);

	/* delete all references to this tag in rows */
	scanPtr = Tcl_FirstHashEntry(tablePtr->rowStyles, &search);
	for (; scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search))
	  if ((TableTag *)Tcl_GetHashValue(scanPtr) == tagPtr)
	    Tcl_DeleteHashEntry(scanPtr);

	/* delete all references to this tag in cols */
	scanPtr = Tcl_FirstHashEntry(tablePtr->colStyles, &search);
	for (; scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search))
	  if ((TableTag *)Tcl_GetHashValue(scanPtr) == tagPtr)
	    Tcl_DeleteHashEntry(scanPtr);

	/* delete all references to this tag in cells */
	scanPtr = Tcl_FirstHashEntry(tablePtr->cellStyles, &search);
	for (; scanPtr != NULL; scanPtr = Tcl_NextHashEntry(&search))
	  if ((TableTag *)Tcl_GetHashValue(scanPtr) == tagPtr)
	    Tcl_DeleteHashEntry(scanPtr);

	/* release the structure */
	TableCleanupTag(tablePtr, tagPtr);
	ckfree((char *) tagPtr);

	/* and free the hash table entry */
	Tcl_DeleteHashEntry(entryPtr);
      }
    }
    /* since we deleted a tag, redraw the screen */
    TableInvalidateAll(tablePtr, 0);
    return result;

  case TAG_EXISTS:
    if (argc != 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
			argv[0], " tag exists tagName\"", (char *) NULL);
      return TCL_ERROR;
    }
    if (Tcl_FindHashEntry(tablePtr->tagTable, argv[3]) != NULL) {
      Tcl_SetResult(interp, yes, TCL_VOLATILE);
    } else {
      Tcl_SetResult(interp, no, TCL_VOLATILE);
    }
    return TCL_OK;

  case TAG_INCLUDES:
    /* does a tag contain a index ? */
    if (argc != 5) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			" tag includes tag index\"", (char *) NULL);
      return TCL_ERROR;
    }
    /* check to see if the tag actually exists */
    if ((entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, argv[3])) == NULL) {
      /* Unknown tag, just return no */
      Tcl_SetResult(interp, no, TCL_VOLATILE);
      return TCL_OK;
    }
    /* parse index */
    if (TableGetIndex (tablePtr, argv[4], &row, &col) != TCL_OK) {
      return TCL_ERROR;
    }
    /* create hash key */
    TableMakeArrayIndex(row, col, buf);
    
    if (strcmp(argv[3], "active") == 0) {
      if (tablePtr->activeRow+tablePtr->rowOffset == row &&
	  tablePtr->activeCol+tablePtr->colOffset == col)
	Tcl_SetResult(interp, yes, TCL_VOLATILE);
      else
	Tcl_SetResult(interp, no, TCL_VOLATILE);
      return TCL_OK;
    } else if (strcmp(argv[3], "flash") == 0) {
      if (tablePtr->flashMode && Tcl_FindHashEntry(tablePtr->flashCells, buf))
	Tcl_SetResult(interp, yes, TCL_VOLATILE);
      else
	Tcl_SetResult(interp, no, TCL_VOLATILE);
      return TCL_OK;
    } else if (strcmp(argv[3], "sel") == 0) {
      if (Tcl_FindHashEntry(tablePtr->selCells, buf))
	Tcl_SetResult(interp, yes, TCL_VOLATILE);
      else
	Tcl_SetResult(interp, no, TCL_VOLATILE);
      return TCL_OK;
    } else if (strcmp(argv[3], "title") == 0) {
      if (row < tablePtr->titleRows+tablePtr->rowOffset ||
	  col < tablePtr->titleCols+tablePtr->colOffset)
	Tcl_SetResult(interp, yes, TCL_VOLATILE);
      else
	Tcl_SetResult(interp, no, TCL_VOLATILE);
      return TCL_OK;
    }

    /* get the pointer to the tag structure */
    tagPtr = (TableTag *) Tcl_GetHashValue(entryPtr);
    scanPtr = Tcl_FindHashEntry(tablePtr->cellStyles, buf);
    /* look to see if there is a cell, row, or col tag for this cell */
    if ((scanPtr && ((TableTag *) Tcl_GetHashValue(scanPtr) == tagPtr)) ||
        (tagPtr == FindRowColTag(tablePtr, row, ROW)) ||
        (tagPtr == FindRowColTag(tablePtr, col, COL))) {
      /* yes there is - return true */
      Tcl_SetResult(interp, yes, TCL_VOLATILE);
      return TCL_OK;
    }
    Tcl_SetResult(interp, no, TCL_VOLATILE);
    return TCL_OK;

  case TAG_NAMES:
    /* just print out the tag names */
    if (argc != 3 && argc != 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " tag names ?pattern?\"", (char *) NULL);
      return TCL_ERROR;
    }
    entryPtr = Tcl_FirstHashEntry(tablePtr->tagTable, &search);
    while (entryPtr != NULL) {
      keybuf = Tcl_GetHashKey(tablePtr->tagTable, entryPtr);
      if (argc == 3 || Tcl_StringMatch(keybuf, argv[3]))
	Tcl_AppendElement(interp, keybuf);
      entryPtr = Tcl_NextHashEntry(&search);
    }
    return TCL_OK;
  }
  return TCL_OK;
}

