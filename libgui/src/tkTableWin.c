/* 
 * tkTableWin.c --
 *
 *	This module implements embedded windows for table widgets.
 *	Much of this code is adapted from tkGrid.c and tkTextWind.c.
 *
 * Copyright (c) 1998 Jeffrey Hobbs
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 */

#include "tkTable.h"

static int	StickyParseProc _ANSI_ARGS_((ClientData clientData,
			    Tcl_Interp *interp, Tk_Window tkwin, char *value,
			    char *widgRec, int offset));
static char *	StickyPrintProc _ANSI_ARGS_((ClientData clientData,
			    Tk_Window tkwin, char *widgRec, int offset,
			    Tcl_FreeProc **freeProcPtr));

static void	EmbWinLostSlaveProc _ANSI_ARGS_((ClientData clientData,
						Tk_Window tkwin));
static void	EmbWinRequestProc _ANSI_ARGS_((ClientData clientData,
					       Tk_Window tkwin));

static void	EmbWinCleanup _ANSI_ARGS_((Table *tablePtr,
					   TableEmbWindow *ewPtr));
static int	EmbWinConfigure _ANSI_ARGS_((Table *tablePtr,
					     TableEmbWindow *ewPtr,
					     int argc, char **argv));
static void	EmbWinStructureProc _ANSI_ARGS_((ClientData clientData,
						 XEvent *eventPtr));
static void	EmbWinUnmapNow _ANSI_ARGS_((Tk_Window ewTkwin,
					    Tk_Window tkwin));

static Tk_GeomMgr tableGeomType = {
    "table",			/* name */
    EmbWinRequestProc,		/* requestProc */
    EmbWinLostSlaveProc,	/* lostSlaveProc */
};

/* windows subcommands */
#define WIN_CGET	1	/* get config item of embedded window */
#define WIN_CONFIGURE	2	/* configure an embedded window */
#define WIN_DELETE	3	/* delete an embedded window */
#define WIN_MOVE	4	/* moves a window index */
#define	WIN_NAMES	5	/* print the embedded window names */
static Cmd_Struct win_cmds[] = {
  {"configure",	WIN_CONFIGURE},
  {"cget",	WIN_CGET},
  {"delete",	WIN_DELETE},
  {"move",	WIN_MOVE},
  {"names",	WIN_NAMES},
  {"", 0}
};

/* Flag values for "sticky"ness  The 16 combinations subsume the packer's
 * notion of anchor and fill.
 *
 * STICK_NORTH  	This window sticks to the top of its cavity.
 * STICK_EAST		This window sticks to the right edge of its cavity.
 * STICK_SOUTH		This window sticks to the bottom of its cavity.
 * STICK_WEST		This window sticks to the left edge of its cavity.
 */

#define STICK_NORTH	(1<<0)
#define STICK_EAST	(1<<1)
#define STICK_SOUTH	(1<<2)
#define STICK_WEST	(1<<3)

/*
 * The default specification for configuring embedded windows
 * Done like this to make the command line parsing easy
 */

static Tk_CustomOption stickyOption = {StickyParseProc, StickyPrintProc,
				       (ClientData) NULL};

static Tk_ConfigSpec winConfigSpecs[] = {
  {TK_CONFIG_BORDER, "-background", "background", "Background", NULL,
   Tk_Offset(TableEmbWindow, bg),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_SYNONYM, "-bg", "background", (char *) NULL,
   (char *) NULL, 0, 0 },
  {TK_CONFIG_STRING, "-create", (char *) NULL, (char *) NULL, (char *) NULL,
   Tk_Offset(TableEmbWindow, create),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_PIXELS, "-padx", (char *) NULL, (char *) NULL, (char *) NULL,
   Tk_Offset(TableEmbWindow, padX), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_PIXELS, "-pady", (char *) NULL, (char *) NULL, (char *) NULL,
   Tk_Offset(TableEmbWindow, padY), TK_CONFIG_DONT_SET_DEFAULT },
  {TK_CONFIG_CUSTOM, "-sticky", (char *) NULL, (char *) NULL, (char *) NULL,
   Tk_Offset(TableEmbWindow, sticky), TK_CONFIG_DONT_SET_DEFAULT,
   &stickyOption},
  {TK_CONFIG_RELIEF, "-relief", "relief", "Relief", NULL,
   Tk_Offset(TableEmbWindow, relief), 0 },
  {TK_CONFIG_WINDOW, "-window", (char *) NULL, (char *) NULL, (char *) NULL,
   Tk_Offset(TableEmbWindow, tkwin),
   TK_CONFIG_DONT_SET_DEFAULT|TK_CONFIG_NULL_OK },
  {TK_CONFIG_END, (char *) NULL, (char *) NULL, (char *) NULL,
   (char *) NULL, 0, 0 }
};

/*
 *----------------------------------------------------------------------
 *
 * StickyPrintProc --
 *	Converts the internal boolean combination of "sticky" bits onto
 *	a TCL string element containing zero or more of n, s, e, or w.
 *
 * Results:
 *	A string is placed into the "result" pointer.
 *
 * Side effects:
 *	none.
 *
 *----------------------------------------------------------------------
 */
static char *
StickyPrintProc(clientData, tkwin, widgRec, offset, freeProcPtr)
    ClientData clientData;		/* Ignored. */
    Tk_Window tkwin;			/* Window for text widget. */
    char *widgRec;			/* Pointer to TkTextEmbWindow
					 * structure. */
    int offset;				/* Ignored. */
    Tcl_FreeProc **freeProcPtr;		/* Pointer to variable to fill in with
					 * information about how to reclaim
					 * storage for return string. */
{
  int flags = ((TableEmbWindow *) widgRec)->sticky;
  int count = 0;
  char *result = (char *) ckalloc(5*sizeof(char));

  if (flags&STICK_NORTH) result[count++] = 'n';
  if (flags&STICK_EAST)  result[count++] = 'e';
  if (flags&STICK_SOUTH) result[count++] = 's';
  if (flags&STICK_WEST)  result[count++] = 'w';

  *freeProcPtr = TCL_DYNAMIC;
  result[count] = '\0';
  return result;
}

/*
 *----------------------------------------------------------------------
 *
 * StringParseProc --
 *	Converts an ascii string representing a widgets stickyness
 *	into the boolean result.
 *
 * Results:
 *	The boolean combination of the "sticky" bits is retuned.  If an
 *	error occurs, such as an invalid character, -1 is returned instead.
 *
 * Side effects:
 *	none
 *
 *----------------------------------------------------------------------
 */
static int
StickyParseProc(clientData, interp, tkwin, value, widgRec, offset)
    ClientData clientData;		/* Not used.*/
    Tcl_Interp *interp;			/* Used for reporting errors. */
    Tk_Window tkwin;			/* Window for text widget. */
    char *value;			/* Value of option. */
    char *widgRec;			/* Pointer to TkTextEmbWindow
					 * structure. */
    int offset;				/* Offset into item (ignored). */
{
  register TableEmbWindow *ewPtr = (TableEmbWindow *) widgRec;
  int sticky = 0;
  char c;

  while ((c = *value++) != '\0') {
    switch (c) {
    case 'n': case 'N': sticky |= STICK_NORTH; break;
    case 'e': case 'E': sticky |= STICK_EAST;  break;
    case 's': case 'S': sticky |= STICK_SOUTH; break;
    case 'w': case 'W': sticky |= STICK_WEST;  break;
    case ' ': case ',': case '\t': case '\r': case '\n': break;
    default:
      Tcl_AppendResult(interp, "bad sticky value \"", --value,
		       "\": must contain n, s, e or w",
		       (char *) NULL);
      return TCL_ERROR;
    }
  }
  ewPtr->sticky = sticky;
  return TCL_OK;
}		

/*
 * ckallocs space for a new embedded window structure and clears the structure
 * returns the pointer to the new structure
 */
static TableEmbWindow *
TableNewEmbWindow(Table *tablePtr)
{
  TableEmbWindow *ewPtr = (TableEmbWindow *) ckalloc(sizeof(TableEmbWindow));
  ewPtr->tablePtr	= tablePtr;
  ewPtr->tkwin		= NULL;
  ewPtr->hPtr		= NULL;
  ewPtr->bg		= NULL;
  ewPtr->create		= NULL;
  ewPtr->relief		= -1;
  ewPtr->sticky		= 0;
  ewPtr->padX		= 0;
  ewPtr->padY		= 0;
  ewPtr->displayed	= 0;
  return ewPtr;
}

/* 
 *----------------------------------------------------------------------
 *
 * EmbWinCleanup --
 *	Releases resources used by an embedded window before it is freed up.
 *
 * Results:
 *	Window will no longer be valid.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
EmbWinCleanup(Table *tablePtr, TableEmbWindow *ewPtr)
{
  /* free the options in the widget */
  Tk_FreeOptions(winConfigSpecs, (char *) ewPtr, tablePtr->display, 0);
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinDisplay --
 *
 *	This procedure is invoked by TableDisplay for
 *	mapping windows into cells.
 *
 * Results:
 *	Displays or moves window on table screen.
 *
 * Side effects:
 *	None.
 *
 *--------------------------------------------------------------
 */
void
EmbWinDisplay(Table *tablePtr, Drawable window, TableEmbWindow *ewPtr,
	      TableTag *tagPtr, int x, int y, int width, int height)
{
  Tk_Window tkwin = tablePtr->tkwin;
  Tk_Window ewTkwin = ewPtr->tkwin;
  int diffx=0;	/* Cavity width - slave width. */
  int diffy=0;	/* Cavity hight - slave height. */
  int sticky = ewPtr->sticky;


  if (ewPtr->bg)
    tagPtr->bg = ewPtr->bg;
  if (ewPtr->relief != -1)
    tagPtr->relief = ewPtr->relief;

  x += ewPtr->padX/2;
  width -= ewPtr->padX;
  y += ewPtr->padY/2;
  height -= ewPtr->padY;

  if (width > Tk_ReqWidth(ewPtr->tkwin)) {
    diffx = width - Tk_ReqWidth(ewPtr->tkwin);
    width = Tk_ReqWidth(ewPtr->tkwin);
  }
  if (height > Tk_ReqHeight(ewPtr->tkwin)) {
    diffy = height - Tk_ReqHeight(ewPtr->tkwin);
    height = Tk_ReqHeight(ewPtr->tkwin);
  }
  if (sticky&STICK_EAST && sticky&STICK_WEST) {
    width += diffx;
  }
  if (sticky&STICK_NORTH && sticky&STICK_SOUTH) {
    height += diffy;
  }
  if (!(sticky&STICK_WEST)) {
    x += (sticky&STICK_EAST) ? diffx : diffx/2;
  }
  if (!(sticky&STICK_NORTH)) {
    y += (sticky&STICK_SOUTH) ? diffy : diffy/2;
  }

  /* If we fall below a specific minimum width/height requirement,
   * we just unmap the window */
  if (width < 4 || height < 4) {
    if (ewPtr->displayed) {
      EmbWinUnmapNow(ewTkwin, tkwin);
    }
    return;
  }

  if (tkwin == Tk_Parent(ewTkwin)) {
    if ((x != Tk_X(ewTkwin)) || (y != Tk_Y(ewTkwin))
	|| (width != Tk_Width(ewTkwin))	|| (height != Tk_Height(ewTkwin))) {
      Tk_MoveResizeWindow(ewTkwin, x, y, width, height);
    }
    Tk_MapWindow(ewTkwin);
  } else {
    Tk_MaintainGeometry(ewTkwin, tkwin, x, y, width, height);
  }
  ewPtr->displayed = 1;
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinUnmapNow --
 *	Handles unmapping the window depending on parent.
 *	tkwin should be tablePtr->tkwin.
 *	ewTkwin should be ewPtr->tkwin.
 *
 * Results:
 *	Removes the window.
 *
 * Side effects:
 *	None.
 *
 *--------------------------------------------------------------
 */
static void
EmbWinUnmapNow(Tk_Window ewTkwin, Tk_Window tkwin)
{
  if (tkwin != Tk_Parent(ewTkwin)) {
    Tk_UnmaintainGeometry(ewTkwin, tkwin);
  } else {
    Tk_UnmapWindow(ewTkwin);
  }
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinUnmap --
 *	This procedure is invoked by TableAdjustParams for
 *	unmapping windows managed moved offscreen.
 *	rlo, ... should be in real coords.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Unmaps embedded windows.
 *
 *--------------------------------------------------------------
 */
void
EmbWinUnmap(Table *tablePtr, int rlo, int rhi, int clo, int chi)
{
  register TableEmbWindow *ewPtr;
  Tcl_HashEntry *entryPtr;
  int row, col;
  char buf[INDEX_BUFSIZE];

  /* we need to deal with things user coords */
  rlo += tablePtr->rowOffset;
  rhi += tablePtr->rowOffset;
  clo += tablePtr->colOffset;
  chi += tablePtr->colOffset;
  for (row = rlo; row <= rhi; row++) {
    for (col = clo; col <= chi; col++) {
      TableMakeArrayIndex(row, col, buf);
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->winTable, buf)) != NULL) {
	ewPtr = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);
	if (ewPtr->displayed) {
	  ewPtr->displayed = 0;
	  if (ewPtr->tkwin != NULL && tablePtr->tkwin != NULL) {
	    EmbWinUnmapNow(ewPtr->tkwin, tablePtr->tkwin);
	  }
	}
      }
    }
  }
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinRequestProc --
 *	This procedure is invoked by Tk_GeometryRequest for
 *	windows managed by the Table.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Arranges for tkwin, and all its managed siblings, to
 *	be re-arranged at the next idle point.
 *
 *--------------------------------------------------------------
 */
static void
EmbWinRequestProc(clientData, tkwin)
    ClientData clientData;	/* Table's information about
				 * window that got new preferred
				 * geometry.  */
    Tk_Window tkwin;		/* Other Tk-related information
				 * about the window. */
{
  register TableEmbWindow *ewPtr = (TableEmbWindow *) clientData;

  /* resize depends on the sticky */
  if (ewPtr->displayed && ewPtr->hPtr != NULL) {
    Table *tablePtr = ewPtr->tablePtr;
    int row, col, x, y, width, height;

    TableParseArrayIndex(&row, &col,
			 Tcl_GetHashKey(tablePtr->winTable, ewPtr->hPtr));
    if (TableCellVCoords(tablePtr, row-tablePtr->rowOffset,
		     col-tablePtr->colOffset, &x, &y, &width, &height, 0)) {
      TableInvalidate(tablePtr, x, y, width, height, 0);
    }
  }
}

static void
EmbWinRemove(TableEmbWindow *ewPtr)
{
  Table *tablePtr = ewPtr->tablePtr;

  ewPtr->tkwin = NULL;
  ewPtr->displayed = 0;
  if (tablePtr->tkwin != NULL) {
    int row, col, x, y, width, height;

    TableParseArrayIndex(&row, &col,
			 Tcl_GetHashKey(tablePtr->winTable, ewPtr->hPtr));
    if (TableCellVCoords(tablePtr, row-tablePtr->rowOffset,
			 col-tablePtr->colOffset, &x, &y, &width, &height, 0))
      TableInvalidate(tablePtr, x, y, width, height, 1);
  }
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinLostSlaveProc --
 *	This procedure is invoked by Tk whenever some other geometry
 *	claims control over a slave that used to be managed by us.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Forgets all table-related information about the slave.
 *
 *--------------------------------------------------------------
 */

static void
EmbWinLostSlaveProc(clientData, tkwin)
    ClientData clientData;	/* Table structure for slave window that
				 * was stolen away. */
    Tk_Window tkwin;		/* Tk's handle for the slave window. */
{
    register TableEmbWindow *ewPtr = (TableEmbWindow *) clientData;

    Tk_DeleteEventHandler(ewPtr->tkwin, StructureNotifyMask,
			  EmbWinStructureProc, (ClientData) ewPtr);
#if 0
    Tcl_CancelIdleCall(EmbWinDelayedUnmap, (ClientData) ewPtr);
#endif
    EmbWinUnmapNow(tkwin, ewPtr->tablePtr->tkwin);
    EmbWinRemove(ewPtr);
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinStructureProc --
 *	This procedure is invoked by the Tk event loop whenever
 *	StructureNotify events occur for a window that's embedded
 *	in a table widget.  This procedure's only purpose is to
 *	clean up when windows are deleted.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The window is disassociated from the window segment, and
 *	the portion of the table is redisplayed.
 *
 *--------------------------------------------------------------
 */
static void
EmbWinStructureProc(clientData, eventPtr)
    ClientData clientData;	/* Pointer to record describing window item. */
    XEvent *eventPtr;		/* Describes what just happened. */
{
  register TableEmbWindow *ewPtr = (TableEmbWindow *) clientData;

  if (eventPtr->type != DestroyNotify) {
    return;
  }

  EmbWinRemove(ewPtr);
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinDelete --
 *	This procedure is invoked by ... whenever
 *	an embedded window is being deleted.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The embedded window is deleted, if it exists, and any resources
 *	associated with it are released.
 *
 *--------------------------------------------------------------
 */
void
EmbWinDelete(register Table *tablePtr, TableEmbWindow *ewPtr)
{
  Tcl_HashEntry *entryPtr;

  if (ewPtr->tkwin != NULL) {
    int row, col, x, y, width, height;
    entryPtr = ewPtr->hPtr;

    /*
     * Delete the event handler for the window before destroying
     * the window, so that EmbWinStructureProc doesn't get called
     * (we'll already do everything that it would have done, and
     * it will just get confused).
     */

    Tk_DeleteEventHandler(ewPtr->tkwin, StructureNotifyMask,
			  EmbWinStructureProc, (ClientData) ewPtr);
    Tk_DestroyWindow(ewPtr->tkwin);

    if (tablePtr->tkwin != NULL && entryPtr != NULL) {
      TableParseArrayIndex(&row, &col,
			   Tcl_GetHashKey(tablePtr->winTable, entryPtr));
      Tcl_DeleteHashEntry(entryPtr);

      if (TableCellVCoords(tablePtr, row-tablePtr->rowOffset,
			   col-tablePtr->colOffset,
			   &x, &y, &width, &height, 0))
	TableInvalidate(tablePtr, x, y, width, height, 0);
    }
  }
#if 0
  Tcl_CancelIdleCall(EmbWinDelayedUnmap, (ClientData) ewPtr);
#endif
  EmbWinCleanup(tablePtr, ewPtr);
  ckfree((char *) ewPtr);
}

/*
 *--------------------------------------------------------------
 *
 * EmbWinConfigure --
 *	This procedure is called to handle configuration options
 *	for an embedded window, using an argc/argv list.
 *
 * Results:
 *	The return value is a standard Tcl result.  If TCL_ERROR is
 *	returned, then the interp's result contains an error message..
 *
 * Side effects:
 *	Configuration information for the embedded window changes,
 *	such as alignment, stretching, or name of the embedded
 *	window.
 *
 *--------------------------------------------------------------
 */
static int
EmbWinConfigure(tablePtr, ewPtr, argc, argv)
     Table *tablePtr;		/* Information about table widget that
				 * contains embedded window. */
     TableEmbWindow *ewPtr;	/* Embedded window to be configured. */
     int argc;			/* Number of strings in argv. */
     char **argv;		/* Array of strings describing configuration
				 * options. */
{
  Tk_Window oldWindow;

  oldWindow = ewPtr->tkwin;
  if (Tk_ConfigureWidget(tablePtr->interp, tablePtr->tkwin, winConfigSpecs,
			 argc, argv, (char *) ewPtr, TK_CONFIG_ARGV_ONLY)
      != TCL_OK) {
    return TCL_ERROR;
  }
  if (oldWindow != ewPtr->tkwin) {
    ewPtr->displayed = 0;
    if (oldWindow != NULL) {
      Tk_DeleteEventHandler(oldWindow, StructureNotifyMask,
			    EmbWinStructureProc, (ClientData) ewPtr);
      Tk_ManageGeometry(oldWindow, (Tk_GeomMgr *) NULL,
			(ClientData) NULL);
      EmbWinUnmapNow(oldWindow, tablePtr->tkwin);
    }
    if (ewPtr->tkwin != NULL) {
      Tk_Window ancestor, parent;

      /*
       * Make sure that the table is either the parent of the
       * embedded window or a descendant of that parent.  Also,
       * don't allow a top-level window to be managed inside
       * a table.
       */

      parent = Tk_Parent(ewPtr->tkwin);
      for (ancestor = tablePtr->tkwin; ;
	   ancestor = Tk_Parent(ancestor)) {
	if (ancestor == parent) {
	  break;
	}
	if (Tk_IsTopLevel(ancestor)) {
	badMaster:
	  Tcl_AppendResult(tablePtr->interp, "can't embed ",
			   Tk_PathName(ewPtr->tkwin), " in ",
			   Tk_PathName(tablePtr->tkwin), (char *) NULL);
	  ewPtr->tkwin = NULL;
	  return TCL_ERROR;
	}
      }
      if (Tk_IsTopLevel(ewPtr->tkwin) || (ewPtr->tkwin == tablePtr->tkwin)) {
	goto badMaster;
      }

      /*
       * Take over geometry management for the window, plus create
       * an event handler to find out when it is deleted.
       */

      Tk_ManageGeometry(ewPtr->tkwin, &tableGeomType, (ClientData) ewPtr);
      Tk_CreateEventHandler(ewPtr->tkwin, StructureNotifyMask,
			    EmbWinStructureProc, (ClientData) ewPtr);
    }
  }
  return TCL_OK;
}

/*
 *--------------------------------------------------------------
 *
 * TableWindowCmd --
 *	This procedure is invoked to process the window method
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
TableWindowCmd(Table * tablePtr, register Tcl_Interp *interp,
	       int argc, char *argv[])
{
  int result = TCL_OK, retval;
  int row, col, x, y, width, height, i, new;
  TableEmbWindow *ewPtr;
  Tcl_HashEntry *entryPtr;
  Tcl_HashSearch search;
  char buf[INDEX_BUFSIZE], *keybuf;

  /* parse the next argument */
  retval = Cmd_Parse(interp, win_cmds, argv[2]);
  switch (retval) {
    /* failed to parse the argument, error */
  case 0:
    return TCL_ERROR;

  case WIN_CGET:
    if (argc != 5) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
                       argv[0], " window cget index option\"", (char *) NULL);
      return TCL_ERROR;
    }
    if ((entryPtr=Tcl_FindHashEntry(tablePtr->winTable, argv[3])) == NULL) {
      Tcl_AppendResult(interp, "no window at index \"", argv[3],
		       "\"", (char *) NULL);
      return TCL_ERROR;
    } else {
      ewPtr = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);
      result = Tk_ConfigureValue(interp, tablePtr->tkwin, winConfigSpecs,
				 (char *) ewPtr, argv[4], 0);
    }
    return result;	/* CGET */

  case WIN_CONFIGURE:
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
		       argv[0], " window configure index ?arg arg  ...?\"",
		       (char *) NULL);
      return TCL_ERROR;
    }
    if (TableGetIndex(tablePtr, argv[3], &row, &col) == TCL_ERROR) {
      return TCL_ERROR;
    }
    TableMakeArrayIndex(row, col, buf);
    entryPtr = Tcl_CreateHashEntry(tablePtr->winTable, buf, &new);
    if (new) {
      /* create the structure */
      ewPtr = TableNewEmbWindow(tablePtr);

      /* insert it into the table */
      Tcl_SetHashValue(entryPtr, (ClientData) ewPtr);
      ewPtr->hPtr = entryPtr;

      /* configure the window structure */
      result = EmbWinConfigure(tablePtr, ewPtr, argc-4, argv+4);
      if (result == TCL_ERROR) {
	/* release the structure */
	EmbWinCleanup(tablePtr, ewPtr);
	ckfree((char *) ewPtr);

	/* and free the hash table entry */
	Tcl_DeleteHashEntry(entryPtr);
	return TCL_ERROR;
      }

      /* if a window was specified, make sure it exists */
    } else {
      /* pointer wasn't null, do a reconfig if we have enough arguments */
      /* get the window pointer from the table */
      ewPtr = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);

      /* 5 args means that there are values to replace */
      if (argc > 5) {
	/* and do a reconfigure */
	result = EmbWinConfigure(tablePtr, ewPtr, argc-4, argv+4);
	if (result == TCL_ERROR)
	  return TCL_ERROR;
      }
    }

    /* 
     * If there were less than 6 args, we need
     * to do a printout of the config, even for new windows
     */
    if (argc < 6) {
      result = Tk_ConfigureInfo(interp, tablePtr->tkwin, winConfigSpecs,
				(char *) ewPtr, (argc == 5)?argv[4]:0, 0);
    } else {
      /* Otherwise we reconfigured so invalidate the table for a redraw */
      if (TableCellVCoords(tablePtr, row-tablePtr->rowOffset,
			   col-tablePtr->colOffset,
			   &x, &y, &width, &height, 0)) {
	TableInvalidate(tablePtr, x, y, width, height, 1);
      }
    }
    return result;	/* CONFIGURE */

  case WIN_DELETE:
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " window delete index ?index ...?\"", (char *) NULL);
      return TCL_ERROR;
    }
    for (i = 3; i < argc; i++) {
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->winTable, argv[i]))!=NULL) {
	/* get the window pointer */
	ewPtr = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);

	EmbWinDelete(tablePtr, ewPtr);
      }
    }
    /* clear up anything that might have been placed in the result string */
    Tcl_SetResult(interp, "", TCL_STATIC);
    return result;

  case WIN_MOVE:
    if (argc != 5) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " window move oldIndex newIndex\"", (char *) NULL);
      return TCL_ERROR;
    }
    if (TableGetIndex(tablePtr, argv[3], &x, &y) == TCL_ERROR ||
	TableGetIndex(tablePtr, argv[4], &row, &col) == TCL_ERROR) {
      return TCL_ERROR;
    }
    TableMakeArrayIndex(x, y, buf);
    if ((entryPtr = Tcl_FindHashEntry(tablePtr->winTable, buf)) == NULL) {
      Tcl_AppendResult(interp, "no window at index \"", argv[3],
		       "\"", (char *) NULL);
      return TCL_ERROR;
    }
    /* avoid moving it to the same location */
    if (x == row && y == col) {
      return TCL_OK;
    }
    /* get the window pointer */
    ewPtr = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);
    /* and free the old hash table entry */
    Tcl_DeleteHashEntry(entryPtr);

    TableMakeArrayIndex(row, col, buf);
    entryPtr = Tcl_CreateHashEntry(tablePtr->winTable, buf, &new);
    if (!new) {
      /* window already there - just delete it */
      TableEmbWindow *ewPtrDel;

      ewPtrDel = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);
      /* This prevents the deletion of it's own entry, since we need it */
      ewPtrDel->hPtr = NULL;
      EmbWinDelete(tablePtr, ewPtrDel);
    }
    /* set the new entry's value */
    Tcl_SetHashValue(entryPtr, (ClientData) ewPtr);
    ewPtr->hPtr = entryPtr;

    /* Invalidate old cell */
    if (TableCellVCoords(tablePtr, x-tablePtr->rowOffset,
			 y-tablePtr->colOffset,
			 &x, &y, &width, &height, 0)) {
      TableInvalidate(tablePtr, x, y, width, height, 0);
    }
    /* Invalidate new cell */
    if (TableCellVCoords(tablePtr, row-tablePtr->rowOffset,
			 col-tablePtr->colOffset,
			 &x, &y, &width, &height, 0)) {
      TableInvalidate(tablePtr, x, y, width, height, 0);
    }
    break;

  case WIN_NAMES:
    /* just print out the image names */
    if (argc != 3 && argc != 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " window names ?pattern?\"", (char *) NULL);
      return TCL_ERROR;
    }
    entryPtr = Tcl_FirstHashEntry(tablePtr->winTable, &search);
    while (entryPtr != NULL) {
      keybuf = Tcl_GetHashKey(tablePtr->winTable, entryPtr);
      if (argc == 3 || Tcl_StringMatch(keybuf, argv[3]))
	Tcl_AppendElement(interp, keybuf);
      entryPtr = Tcl_NextHashEntry(&search);
    }
    Tcl_SetResult(interp,
		  TableCellSort(tablePtr, Tcl_GetStringResult(interp)),
		  TCL_DYNAMIC);
    break;
  }
  return TCL_OK;
}
