/* 
 * tkTable.c --
 *
 *	This module implements table widgets for the Tk
 *	toolkit.  An table displays a 2D array of strings
 *	and allows the strings to be edited.
 *
 * Based on Tk3 table widget written by Roland King
 *
 * Updates 1996 by:
 * Jeffrey Hobbs	jeff.hobbs@acm.org
 * John Ellson		ellson@lucent.com
 * Peter Bruecker	peter@bj-ig.de
 * Tom Moore		tmoore@spatial.ca
 * Sebastian Wangnick	wangnick@orthogon.de
 *
 * Copyright (c) 1997-1998 Jeffrey Hobbs
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 */

#include "tkTable.h"
#ifdef DEBUG
#include "../../dprint.h"
#endif

INLINE static void	TableFlushCache _ANSI_ARGS_((Table *tablePtr));
static int	TableClear _ANSI_ARGS_((register Table *tablePtr, int mode,
					char *first, char *last));
INLINE static void	TableGetGc _ANSI_ARGS_((Display *display, Drawable d,
					TableTag *tagPtr, GC *tagGc));
static void	TableRedrawHighlight _ANSI_ARGS_((Table *tablePtr));
static void	TableDisplay _ANSI_ARGS_((ClientData clientdata));
static void	TableFlashEvent _ANSI_ARGS_((ClientData clientdata));
static void	TableAddFlash _ANSI_ARGS_((Table *tablePtr, int row, int col));
static void	TableSetActiveIndex _ANSI_ARGS_((register Table *tablePtr));
static void	TableGetActiveBuf _ANSI_ARGS_((register Table *tablePtr));
static char *	TableVarProc _ANSI_ARGS_((ClientData clientData,
			Tcl_Interp *interp, char *name, char *index,
			int flags));
static void	TableGeometryRequest _ANSI_ARGS_((Table *tablePtr));
static void	TableAdjustActive _ANSI_ARGS_((register Table *tablePtr));
static void	TableAdjustParams _ANSI_ARGS_((register Table *tablePtr));
static void	TableCursorEvent _ANSI_ARGS_((ClientData clientData));
static void	TableConfigCursor _ANSI_ARGS_((register Table *tablePtr));
static int	TableFetchSelection _ANSI_ARGS_((ClientData clientData,
			int offset, char *buffer, int maxBytes));
static void	TableLostSelection _ANSI_ARGS_((ClientData clientData));
static Tk_RestrictAction TableRestrictProc _ANSI_ARGS_((ClientData arg,
			XEvent *eventPtr));
static int	TableValidateChange _ANSI_ARGS_((Table *tablePtr, int r,
			int c, char *old, char *new, int index));
static void	TableDeleteChars _ANSI_ARGS_((register Table *tablePtr,
					      int index, int count));
static void	TableInsertChars _ANSI_ARGS_((register Table *tablePtr,
					      int index, char *string));
static int	TableWidgetCmd _ANSI_ARGS_((ClientData clientData,
			Tcl_Interp *interp, int argc, char **argv));
static void	TableDestroy _ANSI_ARGS_((ClientData clientdata));
static void	TableEventProc _ANSI_ARGS_((ClientData clientData,
			XEvent *eventPtr));
static int	TableConfigure _ANSI_ARGS_((Tcl_Interp *interp,
			Table *tablePtr, int argc, char **argv,
			int flags, int forceUpdate));
static void	TableCmdDeletedProc _ANSI_ARGS_((ClientData clientData));
static int	TableCmd _ANSI_ARGS_((ClientData clientData,
			Tcl_Interp *interp, int argc, char **argv));

/*
 * The list of command values for all the widget commands
 * We could use enum for many of these #defines, but it adds
 * just that much more code size...
 */
#define CMD_ACTIVATE	1	/* activate command a la listbox */
#define CMD_BBOX	3	/* bounding box of cell <index> */
#define CMD_BORDER	5	/* border movement function */
#define CMD_CGET	7	/* basic cget widget command */
#define CMD_CLEAR	8	/* clear state command */
#define	CMD_CONFIGURE	9	/* general configure command */
#define CMD_CURSELECTION 11	/* get current selected cell(s) */
#define CMD_CURVALUE	13	/* get current selection buffer */
#define	CMD_DELETE	15	/* delete text in the selection */
#define CMD_FLUSH	17	/* flush the table cache */
#define CMD_GET		19	/* get mode a la listbox */
#define	CMD_HEIGHT	21	/* (re)set row heights */
#define CMD_ICURSOR	23	/* set the insertion cursor */
#define CMD_INDEX	25	/* get an index */
#define CMD_INSERT	27	/* insert text at any position */
#define	CMD_REREAD	31	/* reread the current selection */
#define CMD_SCAN	33	/* scan command a la listbox */
#define CMD_SEE		35	/* see command a la listbox */
#define CMD_SELECTION	37	/* selection command a la listbox */
#define CMD_SET		39	/* set command, to set multiple items */
#define	CMD_TAG		41	/* tag command menu */
#define CMD_VALIDATE	43	/* validate contents of active cell */
#define CMD_VERSION	45	/* hidden command to return version */
#define	CMD_WIDTH	47	/* (re)set column widths */
#define	CMD_WINDOW	49	/* manage embedded windows */
#define CMD_XVIEW	51	/* change x view of widget (for scrollbars) */
#define CMD_YVIEW	53	/* change y view of widget (for scrollbars) */

/* The list of commands for the command parser */

static Cmd_Struct main_cmds[] = {
  {"activate",		CMD_ACTIVATE},
  {"bbox",		CMD_BBOX},
  {"border",		CMD_BORDER},
  {"cget",		CMD_CGET},
  {"clear",		CMD_CLEAR},
  {"configure",		CMD_CONFIGURE},
  {"curselection",	CMD_CURSELECTION},
  {"curvalue",		CMD_CURVALUE},
  {"delete",		CMD_DELETE},
  {"flush",		CMD_FLUSH},
  {"get",		CMD_GET},
  {"height",		CMD_HEIGHT},
  {"icursor",		CMD_ICURSOR},
  {"index",		CMD_INDEX},
  {"insert",		CMD_INSERT},
  {"reread",		CMD_REREAD},
  {"scan",		CMD_SCAN},
  {"see",		CMD_SEE},
  {"selection",		CMD_SELECTION},
  {"set",		CMD_SET},
  {"tag",		CMD_TAG},
  {"validate",		CMD_VALIDATE},
  {"version",		CMD_VERSION},
  {"window",		CMD_WINDOW},
  {"width",		CMD_WIDTH},
  {"xview",		CMD_XVIEW},
  {"yview",		CMD_YVIEW},
  {"", 0}
};

/* selection subcommands */
#define SEL_ANCHOR	1	/* set selection anchor */
#define SEL_CLEAR	2	/* clear list from selection */
#define SEL_INCLUDES	3	/* query items inclusion in selection */
#define SEL_SET		4	/* include items in selection */

static Cmd_Struct sel_cmds[]= {
  {"anchor",	 SEL_ANCHOR},
  {"clear",	 SEL_CLEAR},
  {"includes",	 SEL_INCLUDES},
  {"set",	 SEL_SET},
  {"",		 0 }
};

/* -selecttype selection type options */
/* These alter how the selection set/clear commands behave */
#define SEL_ROW		(1<<0)
#define SEL_COL		(1<<1)
#define SEL_BOTH	(1<<2)
#define SEL_CELL	(1<<3)
#define SEL_NONE	(1<<4)

static Cmd_Struct sel_vals[]= {
  {"row",	 SEL_ROW},
  {"col",	 SEL_COL},
  {"both",	 SEL_BOTH},
  {"cell",	 SEL_CELL},
  {"",		 0 }
};

/* clear subcommands */
#define CLEAR_TAGS	(1<<0)
#define CLEAR_SIZES	(1<<1)
#define CLEAR_CACHE	(1<<2)
static Cmd_Struct clear_cmds[] = {
  {"tags",	CLEAR_TAGS},
  {"sizes",	CLEAR_SIZES},
  {"cache",	CLEAR_CACHE},
  {"all",	CLEAR_TAGS | CLEAR_SIZES | CLEAR_CACHE},
  {"",		0}
};

/* -resizeborders options */
static Cmd_Struct resize_vals[]= {
  {"row",	 SEL_ROW},		/* allow rows to be dragged */
  {"col",	 SEL_COL},		/* allow cols to be dragged */
  {"both",	 SEL_ROW|SEL_COL},	/* allow either to be dragged */
  {"none",	 SEL_NONE},		/* allow nothing to be dragged */
  {"",		 0 }
};

/* insert/delete subcommands */
#define MOD_ACTIVE	1
#define MOD_COLS	2
#define MOD_ROWS	3
static Cmd_Struct mod_cmds[] = {
  {"active",	MOD_ACTIVE},
  {"cols",	MOD_COLS},
  {"rows",	MOD_ROWS},
  {"", 0}
};

/* border subcommands */
#define BD_MARK		1
#define BD_DRAGTO	2
static Cmd_Struct bd_cmds[] = {
  {"mark",	BD_MARK},
  {"dragto",	BD_DRAGTO},
  {"", 0}
};

/* drawmode values */
/* The display redraws with a pixmap using TK function calls */
#define	DRAW_MODE_SLOW		(1<<0)
/* The redisplay is direct to the screen, but TK function calls are still
 * used to give correct 3-d border appearance and thus remain compatible
 * with other TK apps */
#define	DRAW_MODE_TK_COMPAT	(1<<1)
/* the redisplay goes straight to the screen and the 3d borders are rendered
 * with a single pixel wide line only. It cheats and uses the internal
 * border structure to do the borders */
#define DRAW_MODE_FAST		(1<<2)
#define DRAW_MODE_SINGLE	(1<<3)

static Cmd_Struct drawmode_vals[] = {
  {"fast",		DRAW_MODE_FAST},
  {"compatible",	DRAW_MODE_TK_COMPAT},
  {"slow",		DRAW_MODE_SLOW},
  {"single",		DRAW_MODE_SINGLE},
  {"", 0}
};

/* stretchmode values */
#define	STRETCH_MODE_NONE	(1<<0)	/* No additional pixels will be
					   added to rows or cols */
#define	STRETCH_MODE_UNSET	(1<<1)	/* All default rows or columns will
					   be stretched to fill the screen */
#define STRETCH_MODE_ALL	(1<<2)	/* All rows/columns will be padded
					   to fill the window */
#define STRETCH_MODE_LAST	(1<<3)	/* Stretch last elememt to fill
					   window */
#define STRETCH_MODE_FILL       (1<<4)	/* More ROWS in Window */

static Cmd_Struct stretch_vals[] = {
  {"none",	STRETCH_MODE_NONE},
  {"unset",	STRETCH_MODE_UNSET},
  {"all",	STRETCH_MODE_ALL},
  {"last",	STRETCH_MODE_LAST},
  {"fill",	STRETCH_MODE_FILL},
  {"", 0}
};

static Cmd_Struct state_vals[]= {
  {"normal",	 STATE_NORMAL},
  {"disabled",	 STATE_DISABLED},
  {"",		 0 }
};

/* The widget configuration table */
static Tk_CustomOption drawOpt = { Cmd_OptionSet, Cmd_OptionGet,
				   (ClientData)(&drawmode_vals) };
static Tk_CustomOption resizeTypeOpt = { Cmd_OptionSet, Cmd_OptionGet,
					 (ClientData)(&resize_vals) };
static Tk_CustomOption stretchOpt = { Cmd_OptionSet, Cmd_OptionGet,
				      (ClientData)(&stretch_vals) };
static Tk_CustomOption selTypeOpt = { Cmd_OptionSet, Cmd_OptionGet,
				      (ClientData)(&sel_vals) };
static Tk_CustomOption stateTypeOpt = { Cmd_OptionSet, Cmd_OptionGet,
					(ClientData)(&state_vals) };

static Tk_ConfigSpec TableConfig[] = {
  {TK_CONFIG_ANCHOR, "-anchor", "anchor", "Anchor", "center",
   Tk_Offset(Table, defaultTag.anchor), 0 },
  {TK_CONFIG_BOOLEAN, "-autoclear", "autoClear", "AutoClear", "0",
   Tk_Offset(Table, autoClear), 0 },
  {TK_CONFIG_BORDER, "-background", "background", "Background", NORMAL_BG,
   Tk_Offset(Table, defaultTag.bg), 0 },
  {TK_CONFIG_SYNONYM, "-bg", "background", (char *) NULL, (char *) NULL, 0, 0},
  {TK_CONFIG_SYNONYM, "-bd", "borderWidth", (char *)NULL, (char *) NULL, 0, 0},
  {TK_CONFIG_CURSOR, "-bordercursor", "borderCursor", "Cursor", "crosshair",
   Tk_Offset(Table, bdcursor), TK_CONFIG_NULL_OK },
  {TK_CONFIG_PIXELS, "-borderwidth", "borderWidth", "BorderWidth", "1",
   Tk_Offset(Table, borderWidth), 0 },
  {TK_CONFIG_STRING, "-browsecommand", "browseCommand", "BrowseCommand", "",
   Tk_Offset(Table, browseCmd), TK_CONFIG_NULL_OK},
  {TK_CONFIG_SYNONYM, "-browsecmd", "browseCommand", (char *) NULL,
   (char *) NULL, 0, TK_CONFIG_NULL_OK},
  {TK_CONFIG_BOOLEAN, "-cache", "cache", "Cache", "0",
   Tk_Offset(Table, caching), 0},
  {TK_CONFIG_INT, "-colorigin", "colOrigin", "Origin", "0",
   Tk_Offset(Table, colOffset), 0 },
  {TK_CONFIG_INT, "-cols", "cols", "Cols", "10",
   Tk_Offset(Table, cols), 0 },
  {TK_CONFIG_STRING, "-colseparator", "colSeparator", "Separator", NULL,
   Tk_Offset(Table, colSep), TK_CONFIG_NULL_OK },
  {TK_CONFIG_CUSTOM, "-colstretchmode", "colStretch", "StretchMode", "none",
   Tk_Offset (Table, colStretch), 0 , &stretchOpt },
  {TK_CONFIG_STRING, "-coltagcommand", "colTagCommand", "TagCommand", NULL,
   Tk_Offset(Table, colTagCmd), TK_CONFIG_NULL_OK },
  {TK_CONFIG_INT, "-colwidth", "colWidth", "ColWidth", "10",
   Tk_Offset(Table, defColWidth), 0 },
  {TK_CONFIG_STRING, "-command", "command", "Command", "",
   Tk_Offset(Table, command), TK_CONFIG_NULL_OK},
  {TK_CONFIG_ACTIVE_CURSOR, "-cursor", "cursor", "Cursor", "xterm",
   Tk_Offset(Table, cursor), TK_CONFIG_NULL_OK },
  {TK_CONFIG_CUSTOM, "-drawmode", "drawMode", "DrawMode", "compatible",
   Tk_Offset(Table, drawMode), 0, &drawOpt },
  {TK_CONFIG_BOOLEAN, "-exportselection", "exportSelection",
   "ExportSelection", "1", Tk_Offset(Table, exportSelection), 0},
  {TK_CONFIG_SYNONYM, "-fg", "foreground", (char *) NULL, (char *) NULL, 0, 0},
  {TK_CONFIG_BOOLEAN, "-flashmode", "flashMode", "FlashMode", "0",
   Tk_Offset(Table, flashMode), 0 },
  {TK_CONFIG_INT, "-flashtime", "flashTime", "FlashTime", "2",
   Tk_Offset(Table, flashTime), 0 },
  {TK_CONFIG_FONT, "-font", "font", "Font",  DEF_TABLE_FONT,
   Tk_Offset(Table, defaultTag.tkfont), 0 },
  {TK_CONFIG_BORDER, "-foreground", "foreground", "Foreground", "black",
   Tk_Offset(Table, defaultTag.fg), 0 },
  {TK_CONFIG_INT, "-height", "height", "Height", "0",
   Tk_Offset(Table, maxReqRows), 0 },
  {TK_CONFIG_COLOR, "-highlightbackground", "highlightBackground",
   "HighlightBackground", NORMAL_BG, Tk_Offset(Table, highlightBgColorPtr), 0},
  {TK_CONFIG_COLOR, "-highlightcolor", "highlightColor", "HighlightColor",
   HIGHLIGHT, Tk_Offset(Table, highlightColorPtr), 0 },
  {TK_CONFIG_PIXELS, "-highlightthickness", "highlightThickness",
   "HighlightThickness", "2", Tk_Offset(Table, highlightWidth), 0 },
  {TK_CONFIG_BORDER, "-insertbackground", "insertBackground", "Foreground",
   "Black", Tk_Offset(Table, insertBg), 0 },
  {TK_CONFIG_PIXELS, "-insertborderwidth", "insertBorderWidth", "BorderWidth",
   "0", Tk_Offset(Table, insertBorderWidth), TK_CONFIG_COLOR_ONLY},
  {TK_CONFIG_PIXELS, "-insertborderwidth", "insertBorderWidth", "BorderWidth",
   "0", Tk_Offset(Table, insertBorderWidth), TK_CONFIG_MONO_ONLY},
  {TK_CONFIG_INT, "-insertofftime", "insertOffTime", "OffTime", "300",
   Tk_Offset(Table, insertOffTime), 0},
  {TK_CONFIG_INT, "-insertontime", "insertOnTime", "OnTime", "600",
   Tk_Offset(Table, insertOnTime), 0},
  {TK_CONFIG_PIXELS, "-insertwidth", "insertWidth", "InsertWidth", "2",
   Tk_Offset(Table, insertWidth), 0},
   {TK_CONFIG_BOOLEAN, "-invertselected", "invertSelected", "InvertSelected",
    "0", Tk_Offset(Table, invertSelected), 0},
  {TK_CONFIG_PIXELS, "-maxheight", "maxHeight", "MaxHeight", "600",
   Tk_Offset(Table, maxReqHeight), 0 },
  {TK_CONFIG_PIXELS, "-maxwidth", "maxWidth", "MaxWidth", "800",
   Tk_Offset(Table, maxReqWidth), 0 },
  {TK_CONFIG_BOOLEAN, "-multiline", "multiline", "Multiline", "1",
   Tk_Offset(Table, defaultTag.multiline), 0 },
  {TK_CONFIG_PIXELS, "-padx", "padX", "Pad", "2", Tk_Offset(Table, padX), 0},
  {TK_CONFIG_PIXELS, "-pady", "padY", "Pad", "1", Tk_Offset(Table, padY), 0},
  {TK_CONFIG_RELIEF, "-relief", "relief", "Relief", "sunken",
   Tk_Offset(Table, defaultTag.relief), 0 },
  {TK_CONFIG_CUSTOM, "-resizeborders", "resizeBorders", "ResizeBorders",
   "both", Tk_Offset(Table, resize), 0, &resizeTypeOpt },
  {TK_CONFIG_PIXELS, "-rowheight", "rowHeight", "RowHeight", "1",
   Tk_Offset(Table, defRowHeight), 0 },
  {TK_CONFIG_INT, "-roworigin", "rowOrigin", "Origin", "0",
   Tk_Offset(Table, rowOffset), 0 },
  {TK_CONFIG_INT, "-rows", "rows", "Rows", "10", Tk_Offset(Table, rows), 0 },
  {TK_CONFIG_STRING, "-rowseparator", "rowSeparator", "Separator", NULL,
   Tk_Offset(Table, rowSep), TK_CONFIG_NULL_OK },
  {TK_CONFIG_CUSTOM, "-rowstretchmode", "rowStretch", "StretchMode", "none",
   Tk_Offset(Table, rowStretch), 0 , &stretchOpt },
  {TK_CONFIG_STRING, "-rowtagcommand", "rowTagCommand", "TagCommand", NULL,
   Tk_Offset(Table, rowTagCmd), TK_CONFIG_NULL_OK },
  {TK_CONFIG_SYNONYM, "-selcmd", "selectionCommand", (char *) NULL,
   (char *) NULL, 0, TK_CONFIG_NULL_OK},
  {TK_CONFIG_STRING, "-selectioncommand", "selectionCommand",
   "SelectionCommand", NULL, Tk_Offset(Table, selCmd), TK_CONFIG_NULL_OK },
  {TK_CONFIG_STRING, "-selectmode", "selectMode", "SelectMode", "browse",
   Tk_Offset(Table, selectMode), TK_CONFIG_NULL_OK },
  {TK_CONFIG_BOOLEAN, "-selecttitles", "selectTitles", "SelectTitles", "0",
   Tk_Offset(Table, selectTitles), 0 },
  {TK_CONFIG_CUSTOM, "-selecttype", "selectType", "SelectType", "cell",
   Tk_Offset(Table, selectType), 0, &selTypeOpt },
  {TK_CONFIG_CUSTOM, "-state", "state", "State", "normal",
   Tk_Offset(Table, state), 0, &stateTypeOpt},
  {TK_CONFIG_STRING, "-takefocus", "takeFocus", "TakeFocus", (char *) NULL,
   Tk_Offset(Table, takeFocus), TK_CONFIG_NULL_OK },
  {TK_CONFIG_INT, "-titlecols", "titleCols", "TitleCols", "0",
   Tk_Offset(Table, titleCols), TK_CONFIG_NULL_OK },
  {TK_CONFIG_INT, "-titlerows", "titleRows", "TitleRows", "0",
   Tk_Offset(Table, titleRows), TK_CONFIG_NULL_OK },
  {TK_CONFIG_BOOLEAN, "-usecommand", "useCommand", "UseCommand", "1",
   Tk_Offset(Table, useCmd), 0},
  {TK_CONFIG_STRING, "-variable", "variable", "Variable", (char *) NULL,
   Tk_Offset(Table, arrayVar), TK_CONFIG_NULL_OK },
  {TK_CONFIG_BOOLEAN, "-validate", "validate", "Validate", "0",
   Tk_Offset(Table, validate), 0 },
  {TK_CONFIG_STRING, "-validatecommand", "validateCommand", "ValidateCommand",
   "", Tk_Offset(Table, valCmd), TK_CONFIG_NULL_OK},
  {TK_CONFIG_SYNONYM, "-vcmd", "validateCommand", (char *) NULL,
   (char *) NULL, 0, TK_CONFIG_NULL_OK},
  {TK_CONFIG_INT, "-width", "width", "Width", "0",
   Tk_Offset(Table, maxReqCols), 0 },
  {TK_CONFIG_BOOLEAN, "-wrap", "wrap", "Wrap", "0",
   Tk_Offset(Table, defaultTag.wrap), 0 },
  {TK_CONFIG_STRING, "-xscrollcommand", "xScrollCommand", "ScrollCommand",
   NULL, Tk_Offset(Table, xScrollCmd), TK_CONFIG_NULL_OK },
  {TK_CONFIG_STRING, "-yscrollcommand", "yScrollCommand", "ScrollCommand",
   NULL, Tk_Offset(Table, yScrollCmd), TK_CONFIG_NULL_OK },
  {TK_CONFIG_END, (char *) NULL, (char *) NULL, (char *) NULL,
   (char *) NULL, 0, 0 }
};

/*
 * This specifies the configure options that will cause an update to
 * occur, so we should have a quick lookup table for them.
 * Keep this in sync with the above values.
 */
static Cmd_Struct update_config[] = {
  {"-anchor",		1},  {"-background",	1},
  {"-bg",		1},  {"-bd",		1},
  {"-borderwidth",	1},  {"-cache",		1},
  {"-command",		1},  {"-colorigin",	1},
  {"-cols",		1},  {"-colstretchmode",	1},
  {"-coltagcommand",	1},  {"-drawmode",	1},
  {"-fg",		1},  {"-font",		1},
  {"-foreground",	1},
  {"-height",		1},  {"-highlightbackground",	1},
  {"-highlightcolor",	1},  {"-highlightthickness",	1},
  {"-insertbackground",	1},  {"-insertborderwidth",	1},
  {"-insertwidth",	1},  {"-invertselected",	1},
  {"-maxheight",	1},  {"-maxwidth",		1},
  {"-multiline",	1},
  {"-padx",		1},  {"-pady",		1},
  {"-relief",		1},  {"-roworigin",	1},
  {"-rows",		1},  {"-rowstretchmode",	1},
  {"-rowtagcommand",	1},  {"-state",		1},
  {"-titlecols",	1},  {"-titlerows",	1},
  {"-usecommand",	1},  {"-variable",		1},
  {"-width",		1},  {"-wrap",		1},
  {"-xscrollcommand",	1},  {"-yscrollcommand",	1},
  {"", 0},
};

/*
 * END HEADER INFORMATION
 */

/*
 *----------------------------------------------------------------------
 *
 * TableFlushCache --
 *	Flushes the internal cache of the table.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
INLINE static void
TableFlushCache(register Table *tablePtr)
{
  /* Just get rid of it and reinit it */
  Tcl_DeleteHashTable(tablePtr->cache);
  ckfree((char *) (tablePtr->cache));
  tablePtr->cache = (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->cache, TCL_STRING_KEYS);
}



/*
 *----------------------------------------------------------------------
 *
 * TableRefresh --
 *	Refreshes an area of the table based on the mode.
 *	row,col in real coords (0-based)
 *
 * Results:
 *	Will cause redraw for visible cells
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
TableRefresh(register Table *tablePtr, int row, int col, int mode)
{
  int x, y, w, h;

  if (mode & CELL) {
    if (TableCellVCoords(tablePtr, row, col, &x, &y, &w, &h, 0)) {
      TableInvalidate(tablePtr, x, y, w, h, mode);
    }
  } else if (mode & ROW) {
    /* get the position of the leftmost cell in the row */
    if ((mode & INV_FILL) && row < tablePtr->topRow) {
      /* Invalidate whole table */
      TableInvalidateAll(tablePtr, mode);
    } else if (TableCellVCoords(tablePtr, row, tablePtr->leftCol,
			 &x, &y, &w, &h, 0)) {
      /* Invalidate from this row, maybe to end */
      TableInvalidate(tablePtr, 0, y, Tk_Width(tablePtr->tkwin),
		      (mode&INV_FILL)?Tk_Height(tablePtr->tkwin):h, mode);
    }
  } else if (mode & COL) {
    /* get the position of the topmost cell on the column */
    if ((mode & INV_FILL) && col < tablePtr->leftCol) {
      /* Invalidate whole table */
      TableInvalidateAll(tablePtr, mode);
    } else if (TableCellVCoords(tablePtr, tablePtr->topRow, col,
			 &x, &y, &w, &h, 0)) {
      /* Invalidate from this column, maybe to end */
      TableInvalidate(tablePtr, x, 0,
		      (mode&INV_FILL)?Tk_Width(tablePtr->tkwin):w,
		      Tk_Height(tablePtr->tkwin), mode);
    }
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableClear --
 *	Clears state information about the table.
 *
 * Results:
 *	Cached info can be lost.  Returns valid Tcl result.
 *
 * Side effects:
 *	Can cause redraw.
 *
 *----------------------------------------------------------------------
 */
static int
TableClear(register Table *tablePtr, int mode, char *first, char *last)
{
  int redraw = 0;

  if (mode == 0) return TCL_ERROR;

  if (first == NULL) {
    if (mode & CLEAR_TAGS) {
      Tcl_DeleteHashTable(tablePtr->rowStyles);
      Tcl_DeleteHashTable(tablePtr->colStyles);
      Tcl_DeleteHashTable(tablePtr->cellStyles);
      Tcl_DeleteHashTable(tablePtr->flashCells);
      Tcl_DeleteHashTable(tablePtr->selCells);

      /* style hash tables */
      Tcl_InitHashTable(tablePtr->rowStyles, TCL_ONE_WORD_KEYS);
      Tcl_InitHashTable(tablePtr->colStyles, TCL_ONE_WORD_KEYS);
      Tcl_InitHashTable(tablePtr->cellStyles, TCL_STRING_KEYS);

      /* special style hash tables */
      Tcl_InitHashTable(tablePtr->flashCells, TCL_STRING_KEYS);
      Tcl_InitHashTable(tablePtr->selCells, TCL_STRING_KEYS);
    }

    if (mode & CLEAR_SIZES) {
      Tcl_DeleteHashTable(tablePtr->colWidths);
      Tcl_DeleteHashTable(tablePtr->rowHeights);

      /* style hash tables */
      Tcl_InitHashTable(tablePtr->colWidths, TCL_ONE_WORD_KEYS);
      Tcl_InitHashTable(tablePtr->rowHeights, TCL_ONE_WORD_KEYS);
    }

    if (mode & CLEAR_CACHE) {
      TableFlushCache(tablePtr);
      /* If we were caching and we have no other data source,
       * invalidate all the cells */
      if (tablePtr->dataSource == DATA_CACHE) {
	TableGetActiveBuf(tablePtr);
      }
    }
    redraw = 1;
  } else {
    int row, col, r1, r2, c1, c2;
    Tcl_HashEntry *entryPtr;
    char buf[INDEX_BUFSIZE];

    if (TableGetIndex(tablePtr, first, &row, &col) == TCL_ERROR ||
	(last != NULL && TableGetIndex(tablePtr, last, &r2, &c2)==TCL_ERROR)) {
      return TCL_ERROR;
    }
    if (last == NULL) {
      r1 = r2 = row;
      c1 = c2 = col;
    } else {
      r1 = MIN(row,r2); r2 = MAX(row,r2);
      c1 = MIN(col,c2); c2 = MAX(col,c2);
    }
    for (row = r1; row <= r2; row++) {
      /* Note that *Styles entries are user based (no offset)
       * while size entries are 0-based (real) */
      if ((mode & CLEAR_TAGS) &&
	  (entryPtr = Tcl_FindHashEntry(tablePtr->rowStyles, (char *) row))) {
	Tcl_DeleteHashEntry(entryPtr);
	redraw = 1;
      }

      if ((mode & CLEAR_SIZES) &&
	  (entryPtr = Tcl_FindHashEntry(tablePtr->rowHeights,
					(char *) row-tablePtr->rowOffset))) {
	Tcl_DeleteHashEntry(entryPtr);
	redraw = 1;
      }

      for (col = c1; col <= c2; col++) {
	TableMakeArrayIndex(row, col, buf);

	if (mode & CLEAR_TAGS) {
	  if ((row == r1) && (entryPtr = Tcl_FindHashEntry(tablePtr->colStyles,
							   (char *) col))) {
	    Tcl_DeleteHashEntry(entryPtr);
	    redraw = 1;
	  }
	  if ((entryPtr = Tcl_FindHashEntry(tablePtr->cellStyles, buf))) {
	    Tcl_DeleteHashEntry(entryPtr);
	    redraw = 1;
	  }
	  if ((entryPtr = Tcl_FindHashEntry(tablePtr->flashCells, buf))) {
	    Tcl_DeleteHashEntry(entryPtr);
	    redraw = 1;
	  }
	  if ((entryPtr = Tcl_FindHashEntry(tablePtr->selCells, buf))) {
	    Tcl_DeleteHashEntry(entryPtr);
	    redraw = 1;
	  }
	}

	if ((mode & CLEAR_SIZES) && row == r1 &&
	    (entryPtr = Tcl_FindHashEntry(tablePtr->colWidths, (char *)
					  col-tablePtr->colOffset))) {
	  Tcl_DeleteHashEntry(entryPtr);
	  redraw = 1;
	}

	if ((mode & CLEAR_CACHE) &&
	    (entryPtr = Tcl_FindHashEntry(tablePtr->cache, buf))) {
	  Tcl_DeleteHashEntry(entryPtr);
	  /* if the cache is our data source,
	   * we need to invalidate the cells changed */
	  if ((tablePtr->dataSource == DATA_CACHE) &&
	      (row-tablePtr->rowOffset == tablePtr->activeRow &&
	       col-tablePtr->colOffset == tablePtr->activeCol))
	    TableGetActiveBuf(tablePtr);
	  redraw = 1;
	}
      }
    }
  }
  /* This could be more sensitive about what it updates,
   * but that can actually be a lot more costly in some cases */
  if (redraw) {
    if (mode & CLEAR_SIZES) {
      TableAdjustParams(tablePtr);
      /* rerequest geometry */
      TableGeometryRequest(tablePtr);
    }
    TableInvalidateAll(tablePtr, 0);
  }
  return TCL_OK;
}

/* 
 *----------------------------------------------------------------------
 *
 * TableGetGc --
 *	Gets a GC corresponding to the tag structure passed.
 *
 * Results:
 *	Returns usable GC.
 *
 * Side effects:
 *	None
 *
 *----------------------------------------------------------------------
 */
INLINE static void
TableGetGc(Display *display, Drawable d, TableTag *tagPtr, GC *tagGc)
{
  XGCValues gcValues;
  gcValues.foreground = Tk_3DBorderColor(tagPtr->fg)->pixel;
  gcValues.background = Tk_3DBorderColor(tagPtr->bg)->pixel;
  gcValues.font = Tk_FontId(tagPtr->tkfont);
  if (*tagGc == NULL) {
    gcValues.graphics_exposures = False;
    *tagGc = XCreateGC(display, d,
		       GCForeground|GCBackground|GCFont|GCGraphicsExposures,
		       &gcValues);
  } else {
    XChangeGC(display, *tagGc, GCForeground|GCBackground|GCFont, &gcValues);
  }
}

#define TableFreeGc	XFreeGC

/* 
 *----------------------------------------------------------------------
 *
 * TableRedrawHighlight --
 *	Redraws just the highlight for the window
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	None
 *
 *----------------------------------------------------------------------
 */
INLINE static void
TableRedrawHighlight(Table *tablePtr)
{
  if ((tablePtr->flags & REDRAW_BORDER) && tablePtr->highlightWidth > 0) {
    GC gc = Tk_GCForColor((tablePtr->flags & HAS_FOCUS)
			  ?(tablePtr->highlightColorPtr)
			  :(tablePtr->highlightBgColorPtr),
			  Tk_WindowId(tablePtr->tkwin));
    Tk_DrawFocusHighlight(tablePtr->tkwin, gc, tablePtr->highlightWidth,
			  Tk_WindowId(tablePtr->tkwin));
  }
  tablePtr->flags &= ~REDRAW_BORDER;
}

/*
 *--------------------------------------------------------------
 *
 * TableUndisplay --
 *	This procedure removes the contents of a table window
 *	that have been moved offscreen.
 *
 * Results:
 *	Embedded windows can be unmapped.
 *
 * Side effects:
 *	Information disappears from the screen.
 *
 *--------------------------------------------------------------
 */
static void
TableUndisplay(register Table *tablePtr)
{
  register int *seen = tablePtr->seen;
  int row, col;

  TableGetLastCell(tablePtr, &row, &col);
  if (seen[0] != -1) {
    if (seen[0] < tablePtr->topRow) {
      /* Remove now hidden rows */
      EmbWinUnmap(tablePtr, seen[0], tablePtr->topRow-1, 0, seen[3]);
    }
    if (seen[1] < tablePtr->leftCol) {
      /* Remove now hidden cols */
      EmbWinUnmap(tablePtr, 0, seen[2], seen[1], tablePtr->leftCol-1);
    }
    if (seen[2] > row) {
      /* Remove now off-screen rows */
      EmbWinUnmap(tablePtr, row+1, seen[2], 0, seen[3]);
    }
    if (seen[3] > col) {
      /* Remove now off-screen cols */
      EmbWinUnmap(tablePtr, 0, seen[2], col+1, seen[3]);
    }
  }
  seen[0] = tablePtr->topRow;
  seen[1] = tablePtr->leftCol;
  seen[2] = row;
  seen[3] = col;
}

/*
 *--------------------------------------------------------------
 *
 * TableDisplay --
 *	This procedure redraws the contents of a table window.
 *	The conditional code in this function is due to these factors:
 *		o Lack of XSetClipRectangles on Windows
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Information appears on the screen.
 *
 *--------------------------------------------------------------
 */
static void
TableDisplay(ClientData clientdata)
{
  register Table *tablePtr = (Table *) clientdata;
  Tk_Window tkwin = tablePtr->tkwin;
  Display *display = tablePtr->display;
  Drawable window;
#ifdef _WIN32
  Drawable clipWind;
#else
  XRectangle clipRect;
#endif
  int rowFrom, rowTo, colFrom, colTo,
    invalidX, invalidY, invalidWidth, invalidHeight,
    x, y, width, height, itemX, itemY, itemW, itemH,
    row, col, urow, ucol, cx, cy, cw, ch, bd,
    numBytes, new, boundW, boundH, maxW, maxH,
    originX, originY, activeCell, clipRectSet, shouldInvert;
  GC tagGc = NULL, topGc, bottomGc;
  char *string = NULL;
  char buf[INDEX_BUFSIZE];
  TableTag *tagPtr = NULL, *titlePtr, *selPtr, *activePtr, *flashPtr,
    *rowPtr, *colPtr;
  Tcl_HashEntry *entryPtr;
  static XPoint rect[3] = { {0, 0}, {0, 0}, {0, 0} };
  Tcl_HashTable *colTagsCache = NULL;
  Tk_TextLayout textLayout = NULL;
  TableEmbWindow *ewPtr;

  if ((tablePtr->tkwin == NULL) || !Tk_IsMapped(tkwin)) {
    return;
  }
  tablePtr->flags &= ~REDRAW_PENDING;

  bd = tablePtr->borderWidth;
  boundW = Tk_Width(tkwin)-tablePtr->highlightWidth;
  boundH = Tk_Height(tkwin)-tablePtr->highlightWidth;

  /* Constrain drawable to not include highlight borders */
  invalidX = MAX(tablePtr->highlightWidth, tablePtr->invalidX);
  invalidY = MAX(tablePtr->highlightWidth, tablePtr->invalidY);
  invalidWidth = MIN(tablePtr->invalidWidth, MAX(1, boundW-invalidX));
  invalidHeight = MIN(tablePtr->invalidHeight, MAX(1, boundH-invalidY));

  /* 
   * if we are using the slow drawing mode with a pixmap 
   * create the pixmap and adjust x && y for offset in pixmap
   */
  if (tablePtr->drawMode == DRAW_MODE_SLOW) {
    window = Tk_GetPixmap(display, Tk_WindowId(tkwin),
			  invalidWidth, invalidHeight, Tk_Depth(tkwin));
  } else {
    window = Tk_WindowId(tkwin);
  }
#ifdef _WIN32
  clipWind = Tk_GetPixmap(display, window,
			  invalidWidth, invalidHeight, Tk_Depth(tkwin));
#endif

  /* set up the permanent tag styles */
  entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, "title");
  titlePtr = (TableTag *) Tcl_GetHashValue(entryPtr);
  entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, "sel");
  selPtr   = (TableTag *) Tcl_GetHashValue(entryPtr);
  entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, "active");
  activePtr= (TableTag *) Tcl_GetHashValue(entryPtr);
  entryPtr = Tcl_FindHashEntry(tablePtr->tagTable, "flash");
  flashPtr = (TableTag *) Tcl_GetHashValue(entryPtr);

  /* find out the cells represented by the invalid region */
  TableWhatCell(tablePtr, invalidX, invalidY, &rowFrom, &colFrom);
  TableWhatCell(tablePtr, invalidX+invalidWidth-1,
		invalidY+invalidHeight-1, &rowTo, &colTo);

#ifdef DEBUG
  tcl_dprintf(tablePtr->interp, "display %d,%d => %d,%d",
	      rowFrom+tablePtr->rowOffset, colFrom+tablePtr->colOffset,
	      rowTo+tablePtr->rowOffset, colTo+tablePtr->colOffset);
#endif

  /* 
   * Initialize colTagsCache hash table to cache column tag names.
   */
  colTagsCache = (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(colTagsCache, TCL_ONE_WORD_KEYS);

  /* Cycle through the cells and display them */
  for (row = rowFrom; row <= rowTo; row++) {
    /* 
     * are we in the 'dead zone' between the
     * title rows and the first displayed row 
     */
    if (row < tablePtr->topRow && row >= tablePtr->titleRows) {
      row = tablePtr->topRow;
    }

    /* Cache the row in user terms */
    urow = row+tablePtr->rowOffset;

    /* Get the row tag once for all iterations of col */
    rowPtr = FindRowColTag(tablePtr, urow, ROW);

    for (col = colFrom; col <= colTo; col++) {
      activeCell = 0;
      /* 
       * are we in the 'dead zone' between the
       * title cols and the first displayed col
       */
      if (col < tablePtr->leftCol && col >= tablePtr->titleCols) {
	col = tablePtr->leftCol;
      }

      /* Cache the col in user terms */
      ucol = col+tablePtr->colOffset;

      /* put the use cell ref into a buffer for the hash lookups */
      TableMakeArrayIndex(urow, ucol, buf);

      /* get the coordinates for the cell */
      TableCellCoords(tablePtr, row, col, &x, &y, &width, &height);

      /* Constrain drawn size to the visual boundaries */
      if (width > boundW-x) {
	width = boundW-x;
      }
      if (height > boundH-y) {
	height = boundH-y;
      }

      /* Create the tag here */
      tagPtr = TableNewTag();
      /* First, merge in the default tag */
      TableMergeTag(tagPtr, &(tablePtr->defaultTag));

      if ((entryPtr = Tcl_FindHashEntry(tablePtr->winTable, buf)) != NULL) {
	ewPtr = (TableEmbWindow *) Tcl_GetHashValue(entryPtr);

	if (ewPtr->tkwin != NULL) {
	  /* Display embedded window instead of text */

	  /* if active, make it disabled to avoid unnecessary editing */
	  if ((tablePtr->flags & HAS_ACTIVE)
	      && row == tablePtr->activeRow && col == tablePtr->activeCol) {
	    tablePtr->flags |= ACTIVE_DISABLED;
	  }

	  EmbWinDisplay(tablePtr, window, ewPtr, tagPtr,
			x, y, width, height);

	  if (tablePtr->drawMode == DRAW_MODE_SLOW) {
	    /* Correctly adjust x && y with the offset */
	    x -= invalidX;
	    y -= invalidY;
	  }
	  Tk_Fill3DRectangle(tkwin, window, tagPtr->bg,
			     x, y, width, height, bd, TK_RELIEF_FLAT);

	  goto ImageUsed;
	}
      }

      if (tablePtr->drawMode == DRAW_MODE_SLOW) {
	/* Correctly adjust x && y with the offset */
	x -= invalidX;
	y -= invalidY;
      }

      shouldInvert = 0;
      /*
       * get the combined tag structure for the cell
       * first clear out a new tag structure that we will build in
       * then add tags as we realize they belong.
       * Tags with the highest priority are added first
       */

      /*
       * Merge colPtr if it exists
       * let's see if we have the value cached already
       * if not, run the findColTag routine and cache the value
       */
      entryPtr = Tcl_CreateHashEntry(colTagsCache, (char *)ucol, &new);
      if (new) {
	colPtr = FindRowColTag(tablePtr, ucol, COL);
	Tcl_SetHashValue(entryPtr, colPtr);
      } else {
	colPtr = (TableTag *) Tcl_GetHashValue(entryPtr);
      }
      if (colPtr != (TableTag *) NULL)
	TableMergeTag(tagPtr, colPtr);
      /* Merge rowPtr if it exists */
      if (rowPtr != (TableTag *) NULL)
	TableMergeTag(tagPtr, rowPtr);
      /* Am I in the titles */
      if (row < tablePtr->topRow || col < tablePtr->leftCol)
	TableMergeTag(tagPtr, titlePtr);
      /* Does this have a cell tag */
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->cellStyles, buf)) != NULL)
	TableMergeTag(tagPtr, (TableTag *) Tcl_GetHashValue(entryPtr));
      /* is this cell selected? */
      if (Tcl_FindHashEntry(tablePtr->selCells, buf) != NULL) {
        if (tablePtr->invertSelected && !activeCell) {
          shouldInvert = 1;
        } else {
	  TableMergeTag(tagPtr, selPtr);
	}
      }
      /* is this cell active? */
      if ((tablePtr->flags & HAS_ACTIVE) && tablePtr->state == STATE_NORMAL
	  && row == tablePtr->activeRow && col == tablePtr->activeCol) {
	if (tagPtr->state == STATE_DISABLED) {
	  tablePtr->flags |= ACTIVE_DISABLED;
	} else {
	  TableMergeTag(tagPtr, activePtr);
	  activeCell = 1;
	  tablePtr->flags &= ~ACTIVE_DISABLED;
	}
      }
      /* if flash mode is on, is this cell flashing */
      if (tablePtr->flashMode &&
	  Tcl_FindHashEntry(tablePtr->flashCells, buf) != NULL)
	TableMergeTag(tagPtr, flashPtr);

      if (shouldInvert) TableInvertTag(tagPtr);

      /*
       * first fill in a blank rectangle. This is left as a Tk call instead
       * of a direct X call for Tk compatibilty. The TK_RELIEF_FLAT ensures
       * that only XFillRectangle is called anyway so the speed is the same
       */
      Tk_Fill3DRectangle(tkwin, window, tagPtr->bg,
			 x, y, width, height, bd, TK_RELIEF_FLAT);

      /*
       * If an image is in the tag, draw it
       */
      if (tagPtr->image != NULL) {
	Tk_SizeOfImage(tagPtr->image, &itemW, &itemH);
	/* Handle anchoring of image in cell space */
	switch (tagPtr->anchor) {
	case TK_ANCHOR_NW:
	case TK_ANCHOR_W:
	case TK_ANCHOR_SW:	/* western position */
	  originX = itemX = 0;
	  break;
	case TK_ANCHOR_N:
	case TK_ANCHOR_S:
	case TK_ANCHOR_CENTER:	/* centered position */
	  itemX = MAX(0, (itemW-width)/2-bd);
	  originX = MAX(0, (width-itemW)/2);
	  break;
	default:	/* eastern position */
	  itemX = MAX(0, itemW-width-2*bd);
	  originX = MAX(0, width-itemW);
	}
	switch (tagPtr->anchor) {
	case TK_ANCHOR_N:
	case TK_ANCHOR_NE:
	case TK_ANCHOR_NW:	/* northern position */
	  originY = itemY = 0;
	  break;
	case TK_ANCHOR_W:
	case TK_ANCHOR_E:
	case TK_ANCHOR_CENTER:	/* centered position */
	  itemY = MAX(0, (itemH-height)/2-bd);
	  originY = MAX(0, (height-itemH)/2);
	  break;
	default:	/* southern position */
	  itemY = MAX(0, itemH-height-2*bd);
	  originY = MAX(0, height-itemH);
	}
	Tk_RedrawImage(tagPtr->image, itemX, itemY,
		       MIN(itemW, width-originX-2*bd),
		       MIN(itemH, height-originY-2*bd), window,
		       x+originX+bd, y+originY+bd);
	/* Jump to avoid display of the text value */
	if (tagPtr->showtext == 0)
	  goto ImageUsed;
      }

      /* get the GC for this particular blend of tags
       * this creates the GC if it never existed, otherwise it
       * modifies the one we have */
      TableGetGc(display, window, tagPtr, &tagGc);

      /* if this is the active cell, use the buffer */
      if (activeCell) {
	string = tablePtr->activeBuf;
      } else {
	/* Is there a value in the cell? If so, draw it  */
	string = TableGetCellValue(tablePtr, urow, ucol);
      }

      numBytes = strlen(string);
      /* If there is a string, show it */
      if (activeCell || numBytes) {
	/* get the dimensions of the string */
	textLayout = Tk_ComputeTextLayout(tagPtr->tkfont, string, numBytes,
					  (tagPtr->wrap>0) ? width : 0,
					  tagPtr->justify,
					  (tagPtr->multiline>0) ? 0 :
					  TK_IGNORE_NEWLINES,
					  &itemW, &itemH);

	/* 
	 * Set the origin coordinates of the string to draw using the anchor.
	 * origin represents the (x,y) coordinate of the lower left corner of
	 * the text box, relative to the internal (inside the border) window
	 */

	/* set the X origin first */
	switch (tagPtr->anchor) {
	case TK_ANCHOR_NW:
	case TK_ANCHOR_W:
	case TK_ANCHOR_SW:	/* western position */
	  originX = tablePtr->padX;
	  break;
	case TK_ANCHOR_N:
	case TK_ANCHOR_S:
	case TK_ANCHOR_CENTER:	/* centered position */
	  originX = (width-itemW)/2 - bd;
	  break;
	default:	/* eastern position */
	  originX = width-itemW-2*bd-tablePtr->padX;
	}

	/* then set the Y origin */
	switch (tagPtr->anchor) {
	case TK_ANCHOR_N:
	case TK_ANCHOR_NE:
	case TK_ANCHOR_NW:	/* northern position */
	  originY = tablePtr->padY;
	  break;
	case TK_ANCHOR_W:
	case TK_ANCHOR_E:
	case TK_ANCHOR_CENTER:	/* centered position */
	  originY = (height-itemH)/2 - bd;
	  break;
	default:	/* southern position */
	  originY = height-itemH-2*bd-tablePtr->padY;
	}

	/*
	 * if this is the selected cell and we are editing
	 * ensure that the cursor will be displayed
	 */
	if (activeCell) {
#if (TK_MINOR_VERSION > 0)
	  int insertByte;

	  insertByte = Tcl_UtfAtIndex(string, tablePtr->icursor) - string;
	  Tk_CharBbox(textLayout, MIN(numBytes, insertByte),
		      &cx, &cy, &cw, &ch);
#else
	  Tk_CharBbox(textLayout, MIN(numBytes, tablePtr->icursor),
		      &cx, &cy, &cw, &ch);
#endif
	  /* we have to fudge with maxW because of odd width
	   * determination for newlines at the end of a line */
	  maxW = width-bd-tablePtr->padX-tablePtr->insertWidth
	    -(cx+MIN(tablePtr->charWidth, cw));
	  maxH = height-bd-tablePtr->padY-(cy+ch);
	  if (originX < tablePtr->padX+bd-cx) {
	    /* cursor off cell to the left */
	    /* use western positioning to cet cursor at left edge
	     * with slight variation to show some text */
	    originX = tablePtr->padX+bd-cx
	      +MIN(cx, width-2*bd-tablePtr->padX-tablePtr->insertWidth);
	  } else if (originX > maxW) {
	    /* cursor off cell to the right */
	    /* use eastern positioning to cet cursor at right edge */
	    originX = maxW;
	  }
	  if (originY < tablePtr->padY+bd-cy) {
	    /* cursor before top of cell */
	    /* use northern positioning to cet cursor at top edge */
	    originY = tablePtr->padY+bd-cy;
	  } else if (originY > maxH) {
	    /* cursor beyond bottom of cell */
	    /* use southern positioning to cet cursor at bottom edge */
	    originY = maxH;
	  }
	  tablePtr->activeLayout = textLayout;
	  tablePtr->activeX = originX;
	  tablePtr->activeY = originY;
	}
	/*
	 * use a clip rectangle only if necessary as it means
	 * updating the GC in the server which slows everything down.
	 * The bd offsets allow us to fudge a little more since the
	 * borders are drawn after drawing the string.
	 */
	if ((clipRectSet = ((originX < bd) || (originY < bd)
			    || (originX+itemW > width-bd)
			    || (originY+itemH > height-bd)))) {
#ifdef _WIN32
	  /* We always draw in the upper-left corner of the clipWind */
	  Tk_Fill3DRectangle(tkwin, clipWind, tagPtr->bg, 0, 0,
			     width, height, bd, TK_RELIEF_FLAT);
	  Tk_DrawTextLayout(display, clipWind, tagGc, textLayout,
			    originX+bd, originY+bd, 0, -1);
	  XCopyArea(display, clipWind, window, tagGc, 0, 0,
		    width, height, x, y);
#else
	  /* set the clipping rectangle */
	  clipRect.x = x;
	  clipRect.y = y;
	  clipRect.width = width;
	  clipRect.height = height;
	  XSetClipRectangles(display, tagGc, 0, 0, &clipRect, 1, Unsorted);
#endif
	}

#ifdef _WIN32	/* no cliprect on windows */
	if (!clipRectSet)
#endif
	  Tk_DrawTextLayout(display, window, tagGc, textLayout,
			    x+originX+bd, y+originY+bd, 0, -1);

#ifndef _WIN32	/* no cliprect on windows */
	/* reset the clip mask */
	if (clipRectSet) {
	  XSetClipMask(display, tagGc, None);
        }
#endif

	/* if this is the active cell draw the cursor if it's on.
	 * this ignores clip rectangles. */
	if (activeCell && (tablePtr->flags & CURSOR_ON) &&
	    (originY+bd+cy < height) &&
	    (originX+cx+bd-(tablePtr->insertWidth/2) >= 0)) {
	  /* make sure it will fit in the box */
	  maxW = MAX(0, originY+bd+cy);
	  maxH = MIN(ch, height-maxW);
	  Tk_Fill3DRectangle(tkwin, window, tablePtr->insertBg,
			     x+originX+cx+bd-(tablePtr->insertWidth/2),
			     y+maxW, tablePtr->insertWidth,
			     maxH, 0, TK_RELIEF_FLAT);
	}
      }

    ImageUsed:
      /* Draw the 3d border on the pixmap correctly offset */
      if (tablePtr->borderWidth) {
	switch (tablePtr->drawMode) {
	case DRAW_MODE_SLOW:
	case DRAW_MODE_TK_COMPAT:
	  Tk_Draw3DRectangle(tkwin, window, tagPtr->bg,
			     x, y, width, height, bd, tagPtr->relief);
	  break;
	case DRAW_MODE_FAST:
	  /*
	  ** choose the GCs to get the best approximation
	  ** to the desired drawing style
	  */
	  switch(tagPtr->relief) {
	  case TK_RELIEF_FLAT:
	    topGc = bottomGc = Tk_3DBorderGC(tkwin, tagPtr->bg, TK_3D_FLAT_GC);
	    break;
	  case TK_RELIEF_RAISED:
	  case TK_RELIEF_RIDGE:
	    topGc    = Tk_3DBorderGC(tkwin, tagPtr->bg, TK_3D_LIGHT_GC);
	    bottomGc = Tk_3DBorderGC(tkwin, tagPtr->bg, TK_3D_DARK_GC);
	    break;
	  default: /* TK_RELIEF_SUNKEN TK_RELIEF_GROOVE */
	    bottomGc = Tk_3DBorderGC(tkwin, tagPtr->bg, TK_3D_LIGHT_GC);
	    topGc    = Tk_3DBorderGC(tkwin, tagPtr->bg, TK_3D_DARK_GC);
	    break;
	  }
	
	  /* draw a line with single pixel width */
	  rect[0].x = x + width - 1;
	  rect[0].y = y;
	  rect[1].y = height - 1;
	  rect[2].x = -width + 1;
	  XDrawLines(display, window, bottomGc, rect, 3, CoordModePrevious);
	  rect[0].x = x;
	  rect[0].y = y + height - 1;
	  rect[1].y = -height + 1;
	  rect[2].x = width - 1;
	  XDrawLines(display, window, topGc, rect, 3, CoordModePrevious);
	  break;
	case DRAW_MODE_SINGLE:
	  topGc = Tk_3DBorderGC(tkwin, tagPtr->bg, TK_3D_DARK_GC);
	  /* draw a line with single pixel width */
	  rect[0].x = x;
	  rect[0].y = y + height - 1;
	  rect[1].y = -height + 1;
	  rect[2].x = width - 1;
	  XDrawLines(display, window, topGc, rect, 3, CoordModePrevious);
	  break;
	}
      }

      /* delete the tag structure */
      ckfree((char *) (tagPtr));
      if (textLayout && !activeCell) {
	Tk_FreeTextLayout(textLayout);
	textLayout = NULL;
      }
    }
  }
#ifdef _WIN32
  Tk_FreePixmap(display, clipWind);
#endif

  /* Take care of removing embedded windows that are no longer in view */
  TableUndisplay(tablePtr);

  /* copy over and delete the pixmap if we are in slow mode */
  if (tablePtr->drawMode == DRAW_MODE_SLOW) {
    /* Get a default valued GC */
    TableGetGc(display, window, &(tablePtr->defaultTag), &tagGc);
    XCopyArea(display, window, Tk_WindowId(tkwin), tagGc, 0, 0,
	      invalidWidth, invalidHeight, invalidX, invalidY);
    Tk_FreePixmap(display, window);
    window = Tk_WindowId(tkwin);
  }

  /* 
   * if we have got to the end of the table, 
   * clear the area after the last row/col
   */
  TableCellCoords(tablePtr, tablePtr->rows-1, tablePtr->cols-1,
		  &x, &y, &width, &height);

  /* This should occur before moving pixmap, but this simplifies things
   *
   * Could use Tk_Fill3DRectangle instead of XFillRectangle
   * for best compatibility, and XClearArea could be used on Unix
   * for best speed, so this is the compromise w/o #ifdef's
   */
  if (x+width < invalidX+invalidWidth) {
    XFillRectangle(display, window,
		   Tk_3DBorderGC(tkwin, tablePtr->defaultTag.bg,
				 TK_3D_FLAT_GC), x+width, invalidY,
		   invalidX+invalidWidth-x-width, invalidHeight);
  }

  if (y+height < invalidY+invalidHeight) {
    XFillRectangle(display, window,
		   Tk_3DBorderGC(tkwin, tablePtr->defaultTag.bg,
				 TK_3D_FLAT_GC), invalidX, y+height,
		   invalidWidth, invalidY+invalidHeight-y-height);
  }

  if (tagGc != NULL) {
    TableFreeGc(display, tagGc);
  }
  TableRedrawHighlight(tablePtr);
  /* 
   * Free the hash table used to cache evaluations.
   */
  Tcl_DeleteHashTable(colTagsCache);
  ckfree((char *) (colTagsCache));
}

/* 
 *----------------------------------------------------------------------
 *
 * TableInvalidate --
 *	Invalidates a rectangle and adds it to the total invalid rectangle
 *	waiting to be redrawn.  If the INV_FORCE flag bit is set,
 *	it does an update instantly else waits until Tk is idle.
 *
 * Results:
 *	Will schedule table (re)display.
 *
 * Side effects:
 *	None
 *
 *----------------------------------------------------------------------
 */
void
TableInvalidate(Table * tablePtr, int x, int y,
		int width, int height, int flags)
{
  register int hl = tablePtr->highlightWidth;
  register Tk_Window tkwin = tablePtr->tkwin;

  /* make sure that the window hasn't been destroyed already */
  /* avoid allocating 0 sized pixmaps which would be fatal */
  /* and check if rectangle is even on the screen */
  if ((tkwin == NULL) || (width <= 0) || (height <= 0)
      || (x > Tk_Width(tkwin)) || (y > Tk_Height(tkwin))) return;

  /* If not even mapped, wait for the remap to redraw all */
  if (!Tk_IsMapped(tkwin)) {
    tablePtr->flags |= REDRAW_ON_MAP;
    return;
  }

  /* if no pending updates then replace the rectangle,
   * otherwise find the bounding rectangle */
  if ((flags & INV_HIGHLIGHT) &&
      (x < hl || y < hl || x+width >= Tk_Width(tkwin)-hl ||
      y+height >= Tk_Height(tkwin)-hl)) {
    tablePtr->flags |= REDRAW_BORDER;
  }

  if (tablePtr->flags & REDRAW_PENDING) {
    tablePtr->invalidWidth  = MAX(tablePtr->invalidX+tablePtr->invalidWidth,
				  x + width);
    tablePtr->invalidHeight = MAX(tablePtr->invalidY+tablePtr->invalidHeight,
				  y + height);
    if (tablePtr->invalidX > x) tablePtr->invalidX = x;
    if (tablePtr->invalidY > y) tablePtr->invalidY = y;
    tablePtr->invalidWidth  -= tablePtr->invalidX;
    tablePtr->invalidHeight -= tablePtr->invalidY;
    /* are we forcing this update out */
    if (flags & INV_FORCE) {
      Tcl_CancelIdleCall(TableDisplay, (ClientData) tablePtr);
      TableDisplay((ClientData) tablePtr);
    }
  } else {
    tablePtr->invalidX = x;
    tablePtr->invalidY = y;
    tablePtr->invalidWidth = width;
    tablePtr->invalidHeight = height;
    if (flags & INV_FORCE) {
      TableDisplay((ClientData) tablePtr);
    } else {
      tablePtr->flags |= REDRAW_PENDING;
      Tcl_DoWhenIdle(TableDisplay, (ClientData) tablePtr);
    }
  }
}

/* 
 *----------------------------------------------------------------------
 *
 * TableFlashEvent --
 *	Called when the flash timer goes off.
 *
 * Results:
 *	Decrements all the entries in the hash table and invalidates
 *	any cells that expire, deleting them from the table.  If the
 *	table is now empty, stops the timer, else reenables it.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
TableFlashEvent(ClientData clientdata)
{
  Table *tablePtr = (Table *) clientdata;
  Tcl_HashEntry *entryPtr;
  Tcl_HashSearch search;
  int entries, count, row, col;

  entries = 0;
  for (entryPtr = Tcl_FirstHashEntry(tablePtr->flashCells, &search);
       entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
    count = (int) Tcl_GetHashValue(entryPtr);
    if (--count <= 0) {
      /* get the cell address and invalidate that region only */
      TableParseArrayIndex(&row, &col,
			   Tcl_GetHashKey(tablePtr->flashCells, entryPtr));

      /* delete the entry from the table */
      Tcl_DeleteHashEntry(entryPtr);

      TableRefresh(tablePtr, row-tablePtr->rowOffset,
		   col-tablePtr->colOffset, CELL|INV_FORCE);
    } else {
      Tcl_SetHashValue(entryPtr, (ClientData) count);
      entries++;
    }
  }

  /* do I need to restart the timer */
  if (entries && tablePtr->flashMode)
    tablePtr->flashTimer = Tcl_CreateTimerHandler(250, TableFlashEvent,
						  (ClientData) tablePtr);
  else
    tablePtr->flashTimer = 0;
}

/* 
 *----------------------------------------------------------------------
 *
 * TableAddFlash --
 *	Adds a flash on cell row,col (real coords) with the default timeout
 *	if flashing is enabled and flashtime > 0.
 *
 * Results:
 *	Cell will flash.
 *
 * Side effects:
 *	Will start flash timer if it didn't exist.
 *
 *----------------------------------------------------------------------
 */
static void
TableAddFlash(Table *tablePtr, int row, int col)
{
  char buf[INDEX_BUFSIZE];
  int dummy;
  Tcl_HashEntry *entryPtr;

  if (!tablePtr->flashMode || tablePtr->flashTime < 1)
    return;

  /* create the array index in user coords */
  TableMakeArrayIndex(row+tablePtr->rowOffset, col+tablePtr->colOffset, buf);

  /* add the flash to the hash table */
  entryPtr = Tcl_CreateHashEntry(tablePtr->flashCells, buf, &dummy);
  Tcl_SetHashValue(entryPtr, tablePtr->flashTime);

  /* now set the timer if it's not already going and invalidate the area */
  if (tablePtr->flashTimer == NULL)
    tablePtr->flashTimer = Tcl_CreateTimerHandler(250, TableFlashEvent,
						  (ClientData) tablePtr);
}

/*
 *----------------------------------------------------------------------
 *
 * TableSetActiveIndex --
 *	Sets the "active" index of the associated array to the current
 *	value of the active buffer.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Traces on the array can cause side effects.
 *
 *----------------------------------------------------------------------
 */
static void
TableSetActiveIndex(register Table *tablePtr)
{
  if (tablePtr->arrayVar) {
    tablePtr->flags |= SET_ACTIVE;
    Tcl_SetVar2(tablePtr->interp, tablePtr->arrayVar, "active",
		tablePtr->activeBuf, TCL_GLOBAL_ONLY);
    tablePtr->flags &= ~SET_ACTIVE;
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableGetActiveBuf --
 *	Get the current selection into the buffer and mark it as unedited.
 *	Set the position to the end of the string.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	tablePtr->activeBuf will change.
 *
 *----------------------------------------------------------------------
 */
static void
TableGetActiveBuf(register Table *tablePtr)
{
  char *data = "";

  if (tablePtr->flags & HAS_ACTIVE)
    data = TableGetCellValue(tablePtr, tablePtr->activeRow+tablePtr->rowOffset,
			     tablePtr->activeCol+tablePtr->colOffset);

  if (strcmp(tablePtr->activeBuf, data) == 0) {
    /* this forced SetActiveIndex is necessary if we change array vars and
     * they happen to have these cells equal, we won't properly set the
     * active index for the new array var unless we do this here */
    TableSetActiveIndex(tablePtr);
    return;
  }
  /* is the buffer long enough */
  tablePtr->activeBuf = (char *)ckrealloc(tablePtr->activeBuf, strlen(data)+1);
  strcpy(tablePtr->activeBuf, data);
  TableGetIcursor(tablePtr, "end", (int *)0);
  tablePtr->flags &= ~TEXT_CHANGED;
  TableSetActiveIndex(tablePtr);
}

/* 
 *----------------------------------------------------------------------
 *
 * TableVarProc --
 *	This is the trace procedure associated with the Tcl array.  No
 *	validation will occur here because this only triggers when the
 *	array value is directly set, and we can't maintain the old value.
 *
 * Results:
 *	Invalidates changed cell.
 *
 * Side effects:
 *	Creates/Updates entry in the cache if we are caching.
 *
 *----------------------------------------------------------------------
 */
static char *
TableVarProc(clientData, interp, name, index, flags)
    ClientData clientData;	/* Information about table. */
    Tcl_Interp *interp;		/* Interpreter containing variable. */
    char *name;			/* Not used. */
    char *index;		/* Not used. */
    int flags;			/* Information about what happened. */
{
  Table *tablePtr = (Table *) clientData;
  int dummy, row, col, update = 1;

  /* This is redundant, as the name should always == arrayVar */
  name = tablePtr->arrayVar;

  /* is this the whole var being destroyed or just one cell being deleted */
  if ((flags & TCL_TRACE_UNSETS) && index == NULL) {
    /* if this isn't the interpreter being destroyed reinstate the trace */
    if ((flags & TCL_TRACE_DESTROYED) && !(flags & TCL_INTERP_DESTROYED)) {
      Tcl_SetVar2(interp, name, TEST_KEY, "", TCL_GLOBAL_ONLY);
      Tcl_UnsetVar2(interp, name, TEST_KEY, TCL_GLOBAL_ONLY);
      Tcl_ResetResult(interp);

      /* set a trace on the variable */
      Tcl_TraceVar(interp, name,
		   TCL_TRACE_WRITES | TCL_TRACE_UNSETS | TCL_GLOBAL_ONLY,
		   (Tcl_VarTraceProc *)TableVarProc, (ClientData) tablePtr);

      /* only do the following if arrayVar is our data source */
      if (tablePtr->dataSource & DATA_ARRAY) {
	/* clear the selection buffer */
	TableGetActiveBuf(tablePtr);
	/* flush any cache */
	TableFlushCache(tablePtr);
	/* and invalidate the table */
	TableInvalidateAll(tablePtr, 0);
      }
    }
    return (char *) NULL;
  }
  /* only continue if arrayVar is our data source */
  if (!(tablePtr->dataSource & DATA_ARRAY)) {
    return (char *) NULL;
  }
  /* get the cell address and invalidate that region only.
   * Make sure that it is a valid cell address. */
  if (strcmp("active", index) == 0) {
    if (tablePtr->flags & SET_ACTIVE) {
      /* If we are already setting the active cell, the update
       * will occur in other code */
      update = 0;
    } else {
      /* modified TableGetActiveBuf */
      char *data = "";

      row = tablePtr->activeRow;
      col = tablePtr->activeCol;
      if (tablePtr->flags & HAS_ACTIVE)
	data = Tcl_GetVar2(interp, name, index, TCL_GLOBAL_ONLY);
      if (!data) data = "";

      if (strcmp(tablePtr->activeBuf, data) == 0) {
	return (char *) NULL;
      }
      tablePtr->activeBuf = (char *)ckrealloc(tablePtr->activeBuf,
					      strlen(data)+1);
      strcpy(tablePtr->activeBuf, data);
      /* set cursor to the last char */
      TableGetIcursor(tablePtr, "end", (int *)0);
      tablePtr->flags |= TEXT_CHANGED;
    }
  } else if (TableParseArrayIndex(&row, &col, index) == 2) {
    char buf[INDEX_BUFSIZE];
    /* Make sure it won't trigger on array(2,3extrastuff) */
    TableMakeArrayIndex(row, col, buf);
    if (strcmp(buf, index)) {
      return (char *) NULL;
    }
    if (tablePtr->caching) {
      Tcl_HashEntry *entryPtr;
      char *val, *data = NULL;

      data = Tcl_GetVar2(interp, name, index, TCL_GLOBAL_ONLY);
      if (!data) data = "";
      val = (char *)ckalloc(strlen(data)+1);
      strcpy(val, data);
      entryPtr = Tcl_CreateHashEntry(tablePtr->cache, buf, &dummy);
      Tcl_SetHashValue(entryPtr, val);
    }
    /* convert index to real coords */
    row -= tablePtr->rowOffset;
    col -= tablePtr->colOffset;
    /* did the active cell just update */
    if (row == tablePtr->activeRow && col == tablePtr->activeCol)
      TableGetActiveBuf(tablePtr);
    /* Flash the cell */
    TableAddFlash(tablePtr, row, col);
  } else {
    return (char *) NULL;
  }

  if (update) TableRefresh(tablePtr, row, col, CELL);

  return (char *) NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * TableGeometryRequest --
 *	This procedure is invoked to request a new geometry from Tk.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Geometry information is updated and a new requested size is
 *	registered for the widget.  Internal border info is also set.
 *
 *----------------------------------------------------------------------
 */
static void
TableGeometryRequest(tablePtr)
     register Table *tablePtr;
{
  int x, y;

  /* Do the geometry request
   * If -width #cols was not specified or it is greater than the real
   * number of cols, use maxWidth as a lower bound, with the other lower
   * bound being the upper bound of the window's user-set width and the
   * value of -maxwidth set by the programmer
   * Vice versa for rows/height
   */
  x = MIN((tablePtr->maxReqCols==0 || tablePtr->maxReqCols > tablePtr->cols) ?
	   tablePtr->maxWidth : tablePtr->colStarts[tablePtr->maxReqCols],
	  tablePtr->maxReqWidth) + 2*tablePtr->highlightWidth;
  y = MIN((tablePtr->maxReqRows==0 || tablePtr->maxReqRows > tablePtr->rows) ?
	   tablePtr->maxHeight : tablePtr->rowStarts[tablePtr->maxReqRows],
	  tablePtr->maxReqHeight) + 2*tablePtr->highlightWidth;
  Tk_GeometryRequest(tablePtr->tkwin, x, y);
}

/*
 *----------------------------------------------------------------------
 *
 * TableAdjustActive --
 *	This procedure is called by AdjustParams and CMD_ACTIVATE to
 *	move the active cell.
 *
 * Results:
 *	Old and new active cell indices will be invalidated.
 *
 * Side effects:
 *	If the old active cell index was edited, it will be saved.
 *	The active buffer will be updated.
 *
 *----------------------------------------------------------------------
 */
static void
TableAdjustActive(tablePtr)
     register Table *tablePtr;		/* Widget record for table */
{
  if (tablePtr->flags & HAS_ACTIVE) {
    /* make sure the active cell has a reasonable real index */
    tablePtr->activeRow = MAX(0, MIN(tablePtr->activeRow, tablePtr->rows-1));
    tablePtr->activeCol = MAX(0, MIN(tablePtr->activeCol, tablePtr->cols-1));
  }

  /*
   * now check the new value of active cell against the original,
   * If it changed, invalidate the area, else leave it alone
   */
  if (tablePtr->oldActRow != tablePtr->activeRow ||
      tablePtr->oldActCol != tablePtr->activeCol) {
    int x, y, width, height;
    /* put the value back in the cell */
    if (tablePtr->oldActRow >= 0 && tablePtr->oldActCol >= 0) {
      /* 
       * Set the value of the old active cell to the active buffer
       * SetCellValue will check if the value actually changed
       */
      if (tablePtr->flags & TEXT_CHANGED) {
	/* WARNING an outside trace will be triggered here and if it
	 * calls something that causes TableAdjustParams to be called
	 * again, we are in data consistency trouble */
	/* HACK - turn TEXT_CHANGED off now to possibly avoid the
	 * above data inconsistency problem.  */
	tablePtr->flags &= ~TEXT_CHANGED;
	TableSetCellValue(tablePtr, tablePtr->oldActRow+tablePtr->rowOffset,
			  tablePtr->oldActCol+tablePtr->colOffset,
			  tablePtr->activeBuf);
      }
      /* invalidate the old active cell */
      TableCellCoords(tablePtr, tablePtr->oldActRow, tablePtr->oldActCol,
		       &x, &y, &width, &height);
      TableInvalidate(tablePtr, x, y, width, height, 0);
    }

    /* get the new value of the active cell into buffer */
    TableGetActiveBuf(tablePtr);

    /* invalidate the new active cell */
    TableCellCoords(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
		    &x, &y, &width, &height);
    TableInvalidate(tablePtr, x, y, width, height, 0);
    /* set the old active row/col for the next time this function is called */
    tablePtr->oldActRow = tablePtr->activeRow;
    tablePtr->oldActCol = tablePtr->activeCol;
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableAdjustParams --
 *	Calculate the row and column starts.  Adjusts the topleft corner
 *	variable to keep it within the screen range, out of the titles
 *	and keep the screen full make sure the selected cell is in the
 *	visible area checks to see if the top left cell has changed at
 *	all and invalidates the table if it has.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Number of rows can change if -rowstretchmode == fill.
 *	topRow && leftCol can change to fit display.
 *	activeRow/Col can change to ensure it is a valid cell.
 *
 *----------------------------------------------------------------------
 */
static void
TableAdjustParams(register Table *tablePtr)
{
  int topRow, leftCol, row, col, total, i, value, x, y, width, height;
  int w, h, bd, hl, recalc = 0;
  int diff, unpreset, lastUnpreset, pad, lastPad, numPixels;
  int defColWidth, defRowHeight;
  Tcl_HashEntry *entryPtr;

  /* cache the borderwidth (doubled) for many upcoming calculations */
  bd = 2*tablePtr->borderWidth;
  hl = tablePtr->highlightWidth;
  w = Tk_Width(tablePtr->tkwin)-2*hl;
  h = Tk_Height(tablePtr->tkwin)-2*hl;

  /* account for whether defColWidth is in chars (>=0) or pixels (<0) */
  /* bd is added in here for convenience */
  if (tablePtr->defColWidth > 0)
    defColWidth = tablePtr->charWidth * tablePtr->defColWidth + bd;
  else
    defColWidth = -(tablePtr->defColWidth) + bd;
  if (tablePtr->defRowHeight > 0)
    defRowHeight = tablePtr->charHeight * tablePtr->defRowHeight + bd;
  else
    defRowHeight = -(tablePtr->defRowHeight) + bd;

  /* Set up the arrays to hold the col pixels and starts */
  if (tablePtr->colPixels) ckfree((char *) tablePtr->colPixels);
  tablePtr->colPixels = (int *) ckalloc(tablePtr->cols * sizeof(int));
  if (tablePtr->colStarts) ckfree((char *) tablePtr->colStarts);
  tablePtr->colStarts = (int *) ckalloc((tablePtr->cols+1) * sizeof(int));

  /* get all the preset columns and set their widths */
  lastUnpreset = 0;
  numPixels = 0;
  unpreset = 0;
  for (i = 0; i < tablePtr->cols; i++) {
    if ((entryPtr = Tcl_FindHashEntry(tablePtr->colWidths,
				      (char *) i)) == NULL) {
      tablePtr->colPixels[i] = -1;
      unpreset++;
      lastUnpreset = i;
    } else {
      value = (int) Tcl_GetHashValue(entryPtr);
      if (value <= 0) {
	tablePtr->colPixels[i] = -value + bd;
      } else {
	tablePtr->colPixels[i] = value * tablePtr->charWidth + bd;
      }
      numPixels += tablePtr->colPixels[i];
    }
  }

  /* work out how much to pad each col depending on the mode */
  diff = w-numPixels-(unpreset*defColWidth);
  total = 0;
  /* now do the padding and calculate the column starts */
  /* diff lower than 0 means we can't see the entire set of columns,
   * thus no special stretching will occur & we optimize the calculation */
  if (diff <= 0) {
    for (i = 0; i < tablePtr->cols; i++) {
      if (tablePtr->colPixels[i] == -1)
	tablePtr->colPixels[i] = defColWidth;
      tablePtr->colStarts[i] = total;
      total += tablePtr->colPixels[i];
    }
  } else {
    switch(tablePtr->colStretch) {
    case STRETCH_MODE_NONE:
      pad = 0;
      lastPad = 0;
      break;
    case STRETCH_MODE_UNSET:
      if (unpreset == 0) {
	pad = 0;
	lastPad = 0;
      } else {
	pad = diff / unpreset;
	lastPad = diff - pad * (unpreset - 1);
      }
      break;
    case STRETCH_MODE_LAST:
      pad = 0;
      lastPad = diff;
      lastUnpreset = tablePtr->cols - 1;
      break;
    default:	/* STRETCH_MODE_ALL, but also FILL for cols */
      pad = diff / tablePtr->cols;
      /* force it to be applied to the last column too */
      lastUnpreset = tablePtr->cols - 1;
      lastPad = diff - pad * lastUnpreset;
    }

    for (i = 0; i < tablePtr->cols; i++) {
      if (tablePtr->colPixels[i] == -1) {
	tablePtr->colPixels[i] = defColWidth
	  + ((i==lastUnpreset)?lastPad:pad);
      } else if (tablePtr->colStretch == STRETCH_MODE_ALL) {
	tablePtr->colPixels[i] += (i==lastUnpreset)?lastPad:pad;
      }
      tablePtr->colStarts[i] = total;
      total += tablePtr->colPixels[i];
    }
  }
  tablePtr->colStarts[i] = tablePtr->maxWidth = total;

  /*
   * The 'do' loop is only necessary for rows because of FILL mode
   */
  do {
    /* Set up the arrays to hold the row pixels and starts */
    /* FIX - this can be moved outside 'do' if you check >row size */
    if (tablePtr->rowPixels) ckfree((char *) tablePtr->rowPixels);
    tablePtr->rowPixels = (int *) ckalloc(tablePtr->rows * sizeof(int));

    /* get all the preset rows and set their heights */
    lastUnpreset = 0;
    numPixels = 0;
    unpreset = 0;
    for (i = 0; i < tablePtr->rows; i++) {
      if ((entryPtr = Tcl_FindHashEntry(tablePtr->rowHeights,
					(char *) i)) == NULL) {
	tablePtr->rowPixels[i] = -1;
	unpreset++;
	lastUnpreset = i;
      } else {
	value = (int) Tcl_GetHashValue(entryPtr);
	if (value <= 0) {
	  tablePtr->rowPixels[i] = -value + bd;
	} else {
	  tablePtr->rowPixels[i] = value * tablePtr->charHeight + bd;
	}
	numPixels += tablePtr->rowPixels[i];
      }
    }

    /* work out how much to pad each row depending on the mode */
    diff = h-numPixels-(unpreset*defRowHeight);
    switch(tablePtr->rowStretch) {
    case STRETCH_MODE_NONE:
      pad = 0;
      lastPad = 0;
      break;
    case STRETCH_MODE_UNSET:
      if (unpreset == 0)  {
	pad = 0;
	lastPad = 0;
      } else {
	pad = MAX(0,diff) / unpreset;
	lastPad = MAX(0,diff) - pad * (unpreset - 1);
      }
      break;
    case STRETCH_MODE_LAST:
      pad = 0;
      lastPad = MAX(0,diff);
      /* force it to be applied to the last column too */
      lastUnpreset = tablePtr->rows - 1;
      break;
    case STRETCH_MODE_FILL:
      pad = 0;
      lastPad = diff;
      if (diff && !recalc) {
	tablePtr->rows += (diff/defRowHeight);
	if (diff < 0 && tablePtr->rows < 0)
	  tablePtr->rows = 0;
	lastUnpreset = tablePtr->rows - 1;
	recalc = 1;
	continue;
      } else {
	lastUnpreset = tablePtr->rows - 1;
	recalc = 0;
      }
      break;
    default:	/* STRETCH_MODE_ALL */
      pad = MAX(0,diff) / tablePtr->rows;
      /* force it to be applied to the last column too */
      lastUnpreset = tablePtr->rows - 1;
      lastPad = MAX(0,diff) - pad * lastUnpreset;
    }
  } while (recalc);

  if (tablePtr->rowStarts) ckfree((char *) tablePtr->rowStarts);
  tablePtr->rowStarts = (int *) ckalloc((tablePtr->rows+1)*sizeof(int));
  /* now do the padding and calculate the row starts */
  total = 0;
  for (i = 0; i < tablePtr->rows; i++) {
    if (tablePtr->rowPixels[i] == -1) {
      tablePtr->rowPixels[i] = defRowHeight
	+ ((i==lastUnpreset)?lastPad:pad);
    } else if (tablePtr->rowStretch == STRETCH_MODE_ALL) {
      tablePtr->rowPixels[i] += (i==lastUnpreset)?lastPad:pad;
    }
    /* calculate the start of each row */
    tablePtr->rowStarts[i] = total;
    total += tablePtr->rowPixels[i];
  }
  tablePtr->rowStarts[i] = tablePtr->maxHeight = total;

  /* make sure the top row and col have reasonable real indices */
  tablePtr->topRow = topRow =
    MAX(tablePtr->titleRows, MIN(tablePtr->topRow, tablePtr->rows-1));
  tablePtr->leftCol = leftCol =
    MAX(tablePtr->titleCols, MIN(tablePtr->leftCol, tablePtr->cols-1));

  /* If we dont have the info, dont bother to fix up the other parameters */
  if (Tk_WindowId(tablePtr->tkwin) == None) {
    tablePtr->oldTopRow = tablePtr->oldLeftCol = -1;
    return;
  }

  w += hl;
  h += hl;
  /* 
   * If we use this value of topRow, will we fill the window?
   * if not, decrease it until we will, or until it gets to titleRows 
   * make sure we don't cut off the bottom row
   */
  for (; topRow > tablePtr->titleRows; topRow--)
    if ((tablePtr->maxHeight-(tablePtr->rowStarts[topRow-1] -
			      tablePtr->rowStarts[tablePtr->titleRows])) > h)
      break;
  /* 
   * If we use this value of topCol, will we fill the window?
   * if not, decrease it until we will, or until it gets to titleCols 
   * make sure we don't cut off the left column
   */
  for (; leftCol > tablePtr->titleCols; leftCol--)
    if ((tablePtr->maxWidth-(tablePtr->colStarts[leftCol-1] -
			     tablePtr->colStarts[tablePtr->titleCols])) > w)
      break;

  tablePtr->topRow = topRow;
  tablePtr->leftCol = leftCol;

  /* Now work out where the bottom right for scrollbar update
   * and testing for one last stretch */
  TableGetLastCell(tablePtr, &row, &col);
  TableCellVCoords(tablePtr, row, col, &x, &y, &width, &height, 0);

  /*
   * Do we have scrollbars, if so, calculate and call the TCL functions In
   * order to get the scrollbar to be completely full when the whole screen
   * is shown and there are titles, we have to arrange for the scrollbar
   * range to be 0 -> rows-titleRows etc.  This leads to the position
   * setting methods, toprow and leftcol, being relative to the titles, not
   * absolute row and column numbers.
   */
  if (tablePtr->yScrollCmd != NULL || tablePtr->xScrollCmd != NULL) {
    Tcl_Interp *interp = tablePtr->interp;
    char buf[INDEX_BUFSIZE];
    double first, last;

    /*
     * We must hold onto the interpreter because the data referred to at
     * tablePtr might be freed as a result of the call to Tcl_VarEval.
     */
    Tcl_Preserve((ClientData) interp);

    /* Do we have a Y-scrollbar and rows to scroll? */
    if (tablePtr->yScrollCmd != NULL) {
      if (row < tablePtr->titleRows) {
	first = 0;
	last  = 1;
      } else {
	diff = tablePtr->rowStarts[tablePtr->titleRows];
	last = (double) (tablePtr->rowStarts[tablePtr->rows]-diff);
	first = (tablePtr->rowStarts[topRow]-diff) / last;
	last  = (height+tablePtr->rowStarts[row]-diff) / last;
      }
      sprintf(buf, " %g %g", first, last);
      if (Tcl_VarEval(interp, tablePtr->yScrollCmd,
		      buf, (char *) NULL) != TCL_OK) {
	Tcl_AddErrorInfo(interp,
		"\n    (vertical scrolling command executed by table)");
	Tcl_BackgroundError(interp);
      }
    }
    /* Do we have a X-scrollbar and cols to scroll? */
    if (tablePtr->xScrollCmd != NULL) {
      if (col < tablePtr->titleCols) {
	first = 0;
	last  = 1;
      } else {
	diff = tablePtr->colStarts[tablePtr->titleCols];
	last = (double) (tablePtr->colStarts[tablePtr->cols]-diff);
	first = (tablePtr->colStarts[leftCol]-diff) / last;
	last  = (width+tablePtr->colStarts[col]-diff) / last;
      }
      sprintf(buf, " %g %g", first, last);
      if (Tcl_VarEval(interp, tablePtr->xScrollCmd,
		      buf, (char *) NULL) != TCL_OK) {
	Tcl_AddErrorInfo(interp,
		"\n    (horizontal scrolling command executed by table)");
	Tcl_BackgroundError(interp);
      }
    }

    Tcl_Release((ClientData) interp);
  }

  /* Adjust the last row/col to fill empty space if it is visible */
  /* do this after setting the scrollbars to not upset its calculations */
  if (row == tablePtr->rows-1 && tablePtr->rowStretch != STRETCH_MODE_NONE) {
    diff = h-(y+height);
    if (diff > 0) {
      tablePtr->rowPixels[tablePtr->rows-1] += diff;
      tablePtr->rowStarts[tablePtr->rows] += diff;
    }
  }
  if (col == tablePtr->cols-1 && tablePtr->colStretch != STRETCH_MODE_NONE) {
    diff = w-(x+width);
    if (diff > 0) {
      tablePtr->colPixels[tablePtr->cols-1] += diff;
      tablePtr->colStarts[tablePtr->cols] += diff;
    }
  }

  TableAdjustActive(tablePtr);

  /*
   * now check the new value of topleft cell against the originals,
   * If they changed, invalidate the area, else leave it alone
   */
  if (tablePtr->topRow != tablePtr->oldTopRow ||
      tablePtr->leftCol != tablePtr->oldLeftCol) {
    /* set the old top row/col for the next time this function is called */
    tablePtr->oldTopRow = tablePtr->topRow;
    tablePtr->oldLeftCol = tablePtr->leftCol;
    /* only the upper corner title cells wouldn't change */
    TableInvalidateAll(tablePtr, 0);
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableCursorEvent --
 *	Toggle the cursor status.  Equivalent to EntryBlinkProc.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The cursor will be switched off/on.
 *
 *----------------------------------------------------------------------
 */
static void
TableCursorEvent(ClientData clientData)
{
  register Table *tablePtr = (Table *) clientData;

  if (!(tablePtr->flags & HAS_FOCUS) || (tablePtr->insertOffTime == 0)) {
    return;
  }

  if (tablePtr->cursorTimer != NULL)
    Tcl_DeleteTimerHandler(tablePtr->cursorTimer);

  tablePtr->cursorTimer =
    Tcl_CreateTimerHandler((tablePtr->flags & CURSOR_ON) ?
			   tablePtr->insertOffTime : tablePtr->insertOnTime,
			   TableCursorEvent, (ClientData) tablePtr);
  /* Toggle the cursor */
  tablePtr->flags ^= CURSOR_ON;

  /* invalidate the cell */
  TableRefresh(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
	       CELL|INV_FORCE);
}

/*
 *----------------------------------------------------------------------
 *
 * TableConfigCursor --
 *	Configures the timer depending on the state of the table.
 *	Equivalent to EntryFocusProc.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The cursor will be switched off/on.
 *
 *----------------------------------------------------------------------
 */
static void
TableConfigCursor(register Table *tablePtr)
{
  /* to get a cursor, we have to have focus and allow edits */
  if ((tablePtr->flags & HAS_FOCUS) && !(tablePtr->flags & ACTIVE_DISABLED) &&
      (tablePtr->state == STATE_NORMAL)) {
    /* turn the cursor on */
    if (!(tablePtr->flags & CURSOR_ON)) {
      tablePtr->flags |= CURSOR_ON;
    }

    /* set up the first timer */
    if (tablePtr->insertOffTime != 0) {
      /* make sure nothing existed */
      Tcl_DeleteTimerHandler(tablePtr->cursorTimer);
      tablePtr->cursorTimer = Tcl_CreateTimerHandler(tablePtr->insertOnTime,
						     TableCursorEvent,
						     (ClientData) tablePtr);
    }

  } else {
    /* turn the cursor off */
    if ((tablePtr->flags & CURSOR_ON)) {
      tablePtr->flags &= ~CURSOR_ON;
    }

    /* and disable the timer */
    if (tablePtr->cursorTimer != NULL)
      Tcl_DeleteTimerHandler(tablePtr->cursorTimer);
    tablePtr->cursorTimer = NULL;
  }

  /* Invalidate the selection window to show or hide the cursor */
  TableRefresh(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
	       CELL|INV_FORCE);
}

/*
 *----------------------------------------------------------------------
 *
 * TableFetchSelection --
 *	This procedure is called back by Tk when the selection is
 *	requested by someone.  It returns part or all of the selection
 *	in a buffer provided by the caller.
 *
 * Results:
 *	The return value is the number of non-NULL bytes stored
 *	at buffer.  Buffer is filled (or partially filled) with a
 *	NULL-terminated string containing part or all of the selection,
 *	as given by offset and maxBytes.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static int
TableFetchSelection(clientData, offset, buffer, maxBytes)
    ClientData clientData;		/* Information about table widget. */
    int offset;				/* Offset within selection of first
					 * character to be returned. */
    char *buffer;			/* Location in which to place
					 * selection. */
    int maxBytes;			/* Maximum number of bytes to place
					 * at buffer, not including terminating
					 * NULL character. */
{
  register Table *tablePtr = (Table *) clientData;
  Tcl_Interp *interp = tablePtr->interp;
  char *value, *data, *rowsep = tablePtr->rowSep, *colsep = tablePtr->colSep;
  Tcl_DString selection;
  Tcl_HashEntry *entryPtr;
  Tcl_HashSearch search;
  int length, count, lastrow=0, needcs=0, r, c, listArgc, rslen=0, cslen=0;
  int numcols, numrows;
  char **listArgv;

  /* if we are not exporting the selection || we have no data source, return */
  if (!tablePtr->exportSelection ||
      (tablePtr->dataSource == DATA_NONE)) {
    return -1;
  }

  /* First get a sorted list of the selected elements */
  Tcl_DStringInit(&selection);
  for (entryPtr = Tcl_FirstHashEntry(tablePtr->selCells, &search);
       entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
    Tcl_DStringAppendElement(&selection,
			     Tcl_GetHashKey(tablePtr->selCells, entryPtr));
  }
  value = TableCellSort(tablePtr, Tcl_DStringValue(&selection));
  Tcl_DStringFree(&selection);

  if (value == NULL ||
      Tcl_SplitList(interp, value, &listArgc, &listArgv) != TCL_OK) {
    return -1;
  }
  ckfree(value);

  Tcl_DStringInit(&selection);
  rslen = (rowsep?(strlen(rowsep)):0);
  cslen = (colsep?(strlen(colsep)):0);
  numrows = numcols = 0;
  for (count = 0; count < listArgc; count++) {
    TableParseArrayIndex(&r, &c, listArgv[count]);
    if (count) {
      if (lastrow != r) {
	lastrow = r;
	needcs = 0;
	if (rslen) {
	  Tcl_DStringAppend(&selection, rowsep, rslen);
	} else {
	  Tcl_DStringEndSublist(&selection);
	  Tcl_DStringStartSublist(&selection);
	}
	++numrows;
      } else {
	if (++needcs > numcols)
	  numcols = needcs;
      }
    } else {
      lastrow = r;
      needcs = 0;
      if (!rslen)
	Tcl_DStringStartSublist(&selection);
    }
    data = TableGetCellValue(tablePtr, r, c);
    if (cslen) {
      if (needcs)
	Tcl_DStringAppend(&selection, colsep, cslen);
      Tcl_DStringAppend(&selection, data, -1);
    } else {
      Tcl_DStringAppendElement(&selection, data);
    }
  }
  if (!rslen && count)
    Tcl_DStringEndSublist(&selection);
  ckfree((char *) listArgv);

  if (tablePtr->selCmd != NULL) {
    Tcl_DString script;
    Tcl_DStringInit(&script);
    ExpandPercents(tablePtr, tablePtr->selCmd, numrows+1, numcols+1,
		   Tcl_DStringValue(&selection), (char *) NULL,
		   listArgc, &script, CMD_ACTIVATE);
    if (Tcl_GlobalEval(interp, Tcl_DStringValue(&script)) == TCL_ERROR) {
      Tcl_AddErrorInfo(interp,
		       "\n    (error in table selection command)");
      Tcl_BackgroundError(interp);
      Tcl_DStringFree(&script);
      Tcl_DStringFree(&selection);
      return -1;
    } else {
      Tcl_DStringGetResult(interp, &selection);
    }
    Tcl_DStringFree(&script);
  }

  length = Tcl_DStringLength(&selection);

  if (length == 0)
    return -1;

  /* Copy the requested portion of the selection to the buffer. */
  count = length - offset;
  if (count <= 0) {
    count = 0;
  } else {
    if (count > maxBytes) {
      count = maxBytes;
    }
    memcpy((VOID *) buffer, (VOID *) (Tcl_DStringValue(&selection) + offset),
	   (size_t) count);
  }
  buffer[count] = '\0';
  Tcl_DStringFree(&selection);
  return count;
}

/*
 *----------------------------------------------------------------------
 *
 * TableLostSelection --
 *	This procedure is called back by Tk when the selection is
 *	grabbed away from a table widget.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The existing selection is unhighlighted, and the window is
 *	marked as not containing a selection.
 *
 *----------------------------------------------------------------------
 */
static void
TableLostSelection(clientData)
    ClientData clientData;	/* Information about table widget. */
{
  register Table *tablePtr = (Table *) clientData;

  if (tablePtr->exportSelection) {
    Tcl_HashEntry *entryPtr;
    Tcl_HashSearch search;
    int row, col;

    /* Same as SEL CLEAR ALL */
    for (entryPtr = Tcl_FirstHashEntry(tablePtr->selCells, &search);
	 entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
      TableParseArrayIndex(&row, &col,
			   Tcl_GetHashKey(tablePtr->selCells,entryPtr));
      Tcl_DeleteHashEntry(entryPtr);
      TableRefresh(tablePtr, row-tablePtr->rowOffset,
		   col-tablePtr->colOffset, CELL);
    }
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableRestrictProc --
 *	A Tk_RestrictProc used by TableValidateChange to eliminate any
 *	extra key input events in the event queue that
 *	have a serial number no less than a given value.
 *
 * Results:
 *	Returns either TK_DISCARD_EVENT or TK_DEFER_EVENT.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static Tk_RestrictAction
TableRestrictProc(serial, eventPtr)
    ClientData serial;
    XEvent *eventPtr;
{
  if ((eventPtr->type == KeyRelease || eventPtr->type == KeyPress) &&
      ((eventPtr->xany.serial-(unsigned int)serial) > 0)) {
    return TK_DEFER_EVENT;
  } else {
    return TK_PROCESS_EVENT;
  }
}

/*
 *--------------------------------------------------------------
 *
 * TableValidateChange --
 *	This procedure is invoked when any character is added or
 *	removed from the table widget, or a set has triggered validation.
 *
 * Results:
 *	TCL_OK    if the validatecommand accepts the new string,
 *	TCL_BREAK if the validatecommand rejects the new string,
 *      TCL_ERROR if any problems occured with validatecommand.
 *
 * Side effects:
 *      The insertion/deletion may be aborted, and the
 *      validatecommand might turn itself off (if an error
 *      or loop condition arises).
 *
 *--------------------------------------------------------------
 */
static int
TableValidateChange(tablePtr, r, c, old, new, index)
     register Table *tablePtr;	/* Table that needs validation. */
     int r, c;			/* row,col index of cell in user coords */
     char *old;			/* current value of cell */
     char *new;			/* potential new value of cell */
     int index;			/* index of insert/delete, -1 otherwise */
{
  register Tcl_Interp *interp = tablePtr->interp;
  int code, bool;
  Tk_RestrictProc *restrict;
  ClientData cdata;
  Tcl_DString script;
    
  if (tablePtr->valCmd == NULL || tablePtr->validate == 0) {
    return TCL_OK;
  }

  /* Magic code to make this bit of code synchronous in the face of
   * possible new key events */
  XSync(tablePtr->display, False);
  restrict = Tk_RestrictEvents(TableRestrictProc, (ClientData)
			       NextRequest(tablePtr->display), &cdata);

  /*
   * If we're already validating, then we're hitting a loop condition
   * Return and set validate to 0 to disallow further validations
   * and prevent current validation from finishing
   */
  if (tablePtr->flags & VALIDATING) {
    tablePtr->validate = 0;
    return TCL_OK;
  }
  tablePtr->flags |= VALIDATING;

  /* Now form command string and run through the -validatecommand */
  Tcl_DStringInit(&script);
  ExpandPercents(tablePtr, tablePtr->valCmd, r, c, old, new, index, &script,
		 CMD_VALIDATE);
  code = Tcl_GlobalEval(tablePtr->interp, Tcl_DStringValue(&script));
  Tcl_DStringFree(&script);

  if (code != TCL_OK && code != TCL_RETURN) {
    Tcl_AddErrorInfo(interp, "\n\t(in validation command executed by table)");
    Tk_BackgroundError(interp);
    code = TCL_ERROR;
  } else if (Tcl_GetBoolean(interp, Tcl_GetStringResult(interp),
			    &bool) != TCL_OK) {
    Tcl_AddErrorInfo(interp, "\n\tboolean not returned by validation command");
    Tk_BackgroundError(interp);
    code = TCL_ERROR;
  } else {
    if (bool)
      code = TCL_OK;
    else
      code = TCL_BREAK;
  }
  Tcl_SetResult(interp, (char *) NULL, TCL_STATIC);

  /*
   * If ->validate has become VALIDATE_NONE during the validation,
   * it means that a loop condition almost occured.  Do not allow
   * this validation result to finish.
   */
  if (tablePtr->validate == 0) {
    code = TCL_ERROR;
  }

  /* If validate will return ERROR, then disallow further validations */
  if (code == TCL_ERROR) {
    tablePtr->validate = 0;
  }

  Tk_RestrictEvents(restrict, cdata, &cdata);
  tablePtr->flags &= ~VALIDATING;

  return code;
}

/*
 *--------------------------------------------------------------
 *
 * ExpandPercents --
 *	Given a command and an event, produce a new command
 *	by replacing % constructs in the original command
 *	with information from the X event.
 *
 * Results:
 *	The new expanded command is appended to the dynamic string
 *	given by dsPtr.
 *
 * Side effects:
 *	None.
 *
 *--------------------------------------------------------------
 */
void
ExpandPercents(tablePtr, before, r, c, old, new, index, dsPtr, cmdType)
     Table *tablePtr;		/* Table that needs validation. */
     char *before;		/* Command containing percent
				 * expressions to be replaced. */
     int r, c;			/* row,col index of cell */
     char *old;                 /* current value of cell */
     char *new;                 /* potential new value of cell */
     int index;                 /* index of insert/delete */
     Tcl_DString *dsPtr;        /* Dynamic string in which to append
				 * new command. */
     int cmdType;		/* type of command to make %-subs for */
{
  int spaceNeeded, cvtFlags;	/* Used to substitute string as proper Tcl
				 * list element. */
  int number, length;
  char *string;
  char buf[INDEX_BUFSIZE];

  /* This returns the static value of the string as set in the array */
  if (old == NULL && cmdType == CMD_VALIDATE) {
    old = TableGetCellValue(tablePtr, r, c);
  }

  while (1) {
    /*
     * Find everything up to the next % character and append it
     * to the result string.
     */
    for (string = before; (*string != 0) && (*string != '%'); string++) {
      /* Empty loop body. */
    }
    if (string != before) {
      Tcl_DStringAppend(dsPtr, before, string-before);
      before = string;
    }
    if (*before == 0) break;

    /* There's a percent sequence here.  Process it. */
    number = 0;
    string = "??";
    /* cmdType independent substitutions */
    switch (before[1]) {
    case 'c':
      number = c;
      goto doNumber;
    case 'C': /* index of cell */
      TableMakeArrayIndex(r, c, buf);
      string = buf;
      goto doString;
    case 'r':
      number = r;
      goto doNumber;
    case 'i': /* index of cursor OR |number| of cells selected */
      number = index;
      goto doNumber;
    case 's': /* Current cell value */
      string = old;
      goto doString;
    case 'S': /* Potential new value of cell */
      string = (new?new:old);
      goto doString;
    case 'W': /* widget name */
      string = Tk_PathName(tablePtr->tkwin);
      goto doString;
    default:
      buf[0] = before[1];
      buf[1] = '\0';
      string = buf;
      goto doString;
    }
	
  doNumber:
    sprintf(buf, "%d", number);
    string = buf;

  doString:
    spaceNeeded = Tcl_ScanElement(string, &cvtFlags);
    length = Tcl_DStringLength(dsPtr);
    Tcl_DStringSetLength(dsPtr, length + spaceNeeded);
    spaceNeeded = Tcl_ConvertElement(string, Tcl_DStringValue(dsPtr) + length,
				     cvtFlags | TCL_DONT_USE_BRACES);
    Tcl_DStringSetLength(dsPtr, length + spaceNeeded);
    before += 2;
  }
  Tcl_DStringAppend(dsPtr, "", 1);
}

/*
 *----------------------------------------------------------------------
 *
 * TableDeleteChars --
 *	Remove one or more characters from an table widget.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Memory gets freed, the table gets modified and (eventually)
 *	redisplayed.
 *
 *----------------------------------------------------------------------
 */
static void
TableDeleteChars(tablePtr, index, count)
    register Table *tablePtr;	/* Table widget to modify. */
    int index;			/* Index of first character to delete. */
    int count;			/* How many characters to delete. */
{
  int x, y, width, height;
#if (TK_MINOR_VERSION > 0)
  int byteIndex, byteCount, newByteCount, numBytes, numChars;
  char *new, *string;

  string = tablePtr->activeBuf;
  numBytes = strlen(string);
  numChars = Tcl_NumUtfChars(string, numBytes);
  if ((index + count) > numChars) {
    count = numChars - index;
  }
  if (count <= 0) {
    return;
  }

  byteIndex = Tcl_UtfAtIndex(string, index) - string;
  byteCount = Tcl_UtfAtIndex(string + byteIndex, count) - (string + byteIndex);

  newByteCount = numBytes + 1 - byteCount;
  new = (char *) ckalloc((unsigned) newByteCount);
  memcpy(new, string, (size_t) byteIndex);
  strcpy(new + byteIndex, string + byteIndex + byteCount);
#else
  int oldlen;
  char *new;

  /* this gets the length of the string, as well as ensuring that
   * the cursor isn't beyond the end char */
  TableGetIcursor(tablePtr, "end", &oldlen);

  if ((index+count) > oldlen)
    count = oldlen-index;
  if (count <= 0)
    return;

  new = (char *) ckalloc((unsigned)(oldlen-count+1));
  strncpy(new, tablePtr->activeBuf, (size_t) index);
  strcpy(new+index, tablePtr->activeBuf+index+count);
  /* make sure this string is null terminated */
  new[oldlen-count] = '\0';
#endif
  /* This prevents deletes on BREAK or validation error. */
  if (tablePtr->validate &&
      TableValidateChange(tablePtr, tablePtr->activeRow+tablePtr->rowOffset,
			  tablePtr->activeCol+tablePtr->colOffset,
			  tablePtr->activeBuf, new, index) != TCL_OK) {
    ckfree(new);
    return;
  }

  ckfree(tablePtr->activeBuf);
  tablePtr->activeBuf = new;

  /* mark the text as changed */
  tablePtr->flags |= TEXT_CHANGED;

  if (tablePtr->icursor >= index) {
    if (tablePtr->icursor >= (index+count)) {
      tablePtr->icursor -= count;
    } else {
      tablePtr->icursor = index;
    }
  }

  TableSetActiveIndex(tablePtr);

  TableCellCoords(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
		   &x, &y, &width, &height);
  TableInvalidate(tablePtr, x, y, width, height, INV_FORCE);
}

/*
 *----------------------------------------------------------------------
 *
 * TableInsertChars --
 *	Add new characters to the active cell of a table widget.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	New information gets added to tablePtr; it will be redisplayed
 *	soon, but not necessarily immediately.
 *
 *----------------------------------------------------------------------
 */
static void
TableInsertChars(tablePtr, index, value)
    register Table *tablePtr;	/* Table that is to get the new elements. */
    int index;			/* Add the new elements before this element. */
    char *value;		/* New characters to add (NULL-terminated
				 * string). */
{
#if (TK_MINOR_VERSION > 0)
  int x, y, width, height, oldlen;
  int byteIndex, byteCount;
  char *new, *string;

  string = tablePtr->activeBuf;
  byteIndex = Tcl_UtfAtIndex(string, index) - string;
  byteCount = strlen(value);
  if (byteCount == 0) {
    return;
  }

  /* Is this an autoclear and this is the first update */
  /* Note that this clears without validating */
  if (tablePtr->autoClear && !(tablePtr->flags & TEXT_CHANGED)) {
    /* set the buffer to be empty */
    tablePtr->activeBuf = (char *)ckrealloc(tablePtr->activeBuf, 1);
    tablePtr->activeBuf[0] = '\0';
    /* the insert position now has to be 0 */
    index = 0;
  }

  oldlen = strlen(string);
  new = (char *) ckalloc((unsigned)(oldlen + byteCount + 1));
  memcpy(new, string, (size_t) byteIndex);
  strcpy(new + byteIndex, value);
  strcpy(new + byteIndex + byteCount, string + byteIndex);

  /* validate potential new active buffer */
  /* This prevents inserts on either BREAK or validation error. */
  if (tablePtr->validate &&
      TableValidateChange(tablePtr, tablePtr->activeRow+tablePtr->rowOffset,
			  tablePtr->activeCol+tablePtr->colOffset,
			  tablePtr->activeBuf, new, byteIndex) != TCL_OK) {
    ckfree(new);
    return;
  }

  /*
   * The following construction is used because inserting improperly
   * formed UTF-8 sequences between other improperly formed UTF-8
   * sequences could result in actually forming valid UTF-8 sequences;
   * the number of characters added may not be Tcl_NumUtfChars(string, -1),
   * because of context.  The actual number of characters added is how
   * many characters were are in the string now minus the number that
   * used to be there.
   */

  if (tablePtr->icursor >= index) {
    tablePtr->icursor += Tcl_NumUtfChars(new, oldlen+byteCount)
      - Tcl_NumUtfChars(tablePtr->activeBuf, oldlen);
  }

  ckfree(string);
  tablePtr->activeBuf = new;

#else
  int x, y, width, height, oldlen, newlen;
  char *new;

  newlen = strlen(value);
  if (newlen == 0) return;

  /* Is this an autoclear and this is the first update */
  /* Note that this clears without validating */
  if (tablePtr->autoClear && !(tablePtr->flags & TEXT_CHANGED)) {
    /* set the buffer to be empty */
    tablePtr->activeBuf = (char *)ckrealloc(tablePtr->activeBuf, 1);
    tablePtr->activeBuf[0] = '\0';
    /* the insert position now has to be 0 */
    index = 0;
  }
  oldlen = strlen(tablePtr->activeBuf);
  /* get the buffer to at least the right length */
  new = (char *) ckalloc((unsigned)(oldlen+newlen+1));
  strncpy(new, tablePtr->activeBuf, (size_t) index);
  strcpy(new+index, value);
  strcpy(new+index+newlen, (tablePtr->activeBuf)+index);
  /* make sure this string is null terminated */
  new[oldlen+newlen] = '\0';

  /* validate potential new active buffer */
  /* This prevents inserts on either BREAK or validation error. */
  if (tablePtr->validate &&
      TableValidateChange(tablePtr, tablePtr->activeRow+tablePtr->rowOffset,
			  tablePtr->activeCol+tablePtr->colOffset,
			  tablePtr->activeBuf, new, index) != TCL_OK) {
    ckfree(new);
    return;
  }
  ckfree(tablePtr->activeBuf);
  tablePtr->activeBuf = new;

  if (tablePtr->icursor >= index) {
    tablePtr->icursor += newlen;
  }
#endif

  /* mark the text as changed */
  tablePtr->flags |= TEXT_CHANGED;

  TableSetActiveIndex(tablePtr);

  TableCellCoords(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
		   &x, &y, &width, &height);
  TableInvalidate(tablePtr, x, y, width, height, INV_FORCE);
}

/*
 *----------------------------------------------------------------------
 *
 * TableModifyRCaux --
 *	Helper function that does the core work of moving rows/cols
 *	and associated tags.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Moves cell data and possibly tag data
 *
 *----------------------------------------------------------------------
 */
static void
TableModifyRCaux(tablePtr, type, which, movetag, tagTblPtr, dimTblPtr,
		 offset, from, to, lo, hi, check)
    Table *tablePtr;	/* Information about text widget. */
    int type;		/* insert (CMD_INSERT) | delete (CMD_DELETE) */
    int which;		/* rows (MOD_ROWS) or cols (MOD_COLS) */
    int movetag;	/* whether tags are supposed to be moved */
    Tcl_HashTable *tagTblPtr, *dimTblPtr; /* Pointers to the row/col tags
					   * and width/height tags */
    int offset;		/* appropriate offset */
    int from, to;	/* the from and to row/col */
    int lo, hi;		/* the lo and hi col/row */
    int check;		/* the boundary check for shifting items */
{
  int j, dummy;
  char buf[INDEX_BUFSIZE], buf1[INDEX_BUFSIZE];
  Tcl_HashEntry *entryPtr, *newPtr;

  /* move row/col style && width/height here */
  if (movetag) {
    if ((entryPtr=Tcl_FindHashEntry(tagTblPtr, (char *)from)) != NULL) {
      Tcl_DeleteHashEntry(entryPtr);
    }
    if ((entryPtr=Tcl_FindHashEntry(dimTblPtr, (char *)from-offset)) != NULL) {
      Tcl_DeleteHashEntry(entryPtr);
    }
    if (!check) {
      if ((entryPtr=Tcl_FindHashEntry(tagTblPtr, (char *)to)) != NULL) {
	newPtr = Tcl_CreateHashEntry(tagTblPtr, (char *)from, &dummy);
	Tcl_SetHashValue(newPtr, Tcl_GetHashValue(entryPtr));
	Tcl_DeleteHashEntry(entryPtr);
      }
      if ((entryPtr=Tcl_FindHashEntry(dimTblPtr, (char *)to-offset)) != NULL) {
	newPtr = Tcl_CreateHashEntry(dimTblPtr, (char *)from-offset, &dummy);
	Tcl_SetHashValue(newPtr, Tcl_GetHashValue(entryPtr));
	Tcl_DeleteHashEntry(entryPtr);
      }
    }
  }
  for (j = lo; j <= hi; j++) {
    if (which == MOD_COLS) {
      TableMakeArrayIndex(j, from, buf);
      TableMakeArrayIndex(j, to, buf1);
      TableSetCellValue(tablePtr, j, from, check ? "" :
			TableGetCellValue(tablePtr, j, to));
    } else {
      TableMakeArrayIndex(from, j, buf);
      TableMakeArrayIndex(to, j, buf1);
      TableSetCellValue(tablePtr, from, j, check ? "" :
			TableGetCellValue(tablePtr, to, j));
    }
    /* move cell style here */
    if (movetag) {
      if ((entryPtr=Tcl_FindHashEntry(tablePtr->cellStyles,buf)) != NULL) {
	Tcl_DeleteHashEntry(entryPtr);
      }
      if (!check &&
	  (entryPtr=Tcl_FindHashEntry(tablePtr->cellStyles,buf1))!=NULL) {
	newPtr = Tcl_CreateHashEntry(tablePtr->cellStyles, buf, &dummy);
	Tcl_SetHashValue(newPtr, Tcl_GetHashValue(entryPtr));
	Tcl_DeleteHashEntry(entryPtr);
      }
    }
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableModifyRC --
 *	Modify rows/cols of the table (insert or delete)
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Modifies associated row/col data
 *
 *----------------------------------------------------------------------
 */
static int
TableModifyRC(tablePtr, interp, type, which, argc, argv)
    Table *tablePtr;		/* Information about text widget. */
    Tcl_Interp *interp;		/* Current interpreter. */
    int type;			/* insert (CMD_INSERT) | delete (CMD_DELETE) */
    int which;			/* rows (MOD_ROWS) or cols (MOD_COLS) */
    int argc;			/* Number of arguments. */
    char **argv;		/* Argument strings. */
{
  int i, first, lo, hi, idx, c, argsLeft, x, y, offset;
  int maxrow, maxcol, maxkey, minkey, movetitle, movetag, movedim;
  size_t length;
  char *arg;
  Tcl_HashTable *tagTblPtr, *dimTblPtr;
  Tcl_HashSearch search;
  int *dimPtr;

  movetitle	= 1;
  movetag	= 1;
  movedim	= 1;
  maxcol	= tablePtr->cols-1+tablePtr->colOffset;
  maxrow	= tablePtr->rows-1+tablePtr->rowOffset;
  for (i = 3; i < argc; i++) {
    arg = argv[i];
    if (arg[0] != '-') {
      break;
    }
    length = strlen(arg);
    if (length < 2) {
    badSwitch:
      Tcl_AppendResult(interp, "bad switch \"", arg,
		       "\": must be -cols, -keeptitles, -holddimensions, ",
		       "-holdtags, -rows, or --",
		       (char *) NULL);
      return TCL_ERROR;
    }
    c = arg[1];
    if ((c == 'h') && (length > 5) &&
	(strncmp(argv[i], "-holddimensions", length) == 0)) {
      movedim = 0;
    } else if ((c == 'h') && (length > 5) &&
	       (strncmp(argv[i], "-holdtags", length) == 0)) {
      movetag = 0;
    } else if ((c == 'k') && (strncmp(argv[i], "-keeptitles", length) == 0)) {
      movetitle = 0;
    } else if ((c == 'c') && (strncmp(argv[i], "-cols", length) == 0)) {
      if (i >= (argc-1)) {
	Tcl_SetResult(interp, "no value given for \"-cols\" option",
		      TCL_STATIC);
	return TCL_ERROR;
      }
      if (Tcl_GetInt(interp, argv[++i], &maxcol) != TCL_OK) {
	return TCL_ERROR;
      }
      maxcol = MAX(maxcol, tablePtr->titleCols+tablePtr->colOffset);
    } else if ((c == 'r') && (strncmp(argv[i], "-rows", length) == 0)) {
      if (i >= (argc-1)) {
	Tcl_SetResult(interp, "no value given for \"-rows\" option",
		      TCL_STATIC);
	return TCL_ERROR;
      }
      if (Tcl_GetInt(interp, argv[++i], &maxrow) != TCL_OK) {
	return TCL_ERROR;
      }
      maxrow = MAX(maxrow, tablePtr->titleRows+tablePtr->rowOffset);
    } else if ((c == '-') && (strncmp(argv[i], "--", length) == 0)) {
      i++;
      break;
    } else {
      goto badSwitch;
    }
  }
  argsLeft = argc - i;
  if (argsLeft != 1 && argsLeft != 2) {
    Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		     (type == CMD_DELETE) ? " delete" : " insert",
		     (which == MOD_COLS) ? " cols" : " rows",
		     " ?switches? index ?count?\"", (char *) NULL);
    return TCL_ERROR;
  }

  c = 1;
  if (strcmp(argv[i], "end") == 0) {
    /* allow "end" to be specified as an index */
    idx = (which == MOD_COLS) ? maxcol : maxrow;
  } else if (Tcl_GetInt(interp, argv[i], &idx) != TCL_OK) {
    return TCL_ERROR;
  }
  if (argsLeft == 2 && Tcl_GetInt(interp, argv[++i], &c) != TCL_OK) {
    return TCL_ERROR;
  }
  if (tablePtr->state == STATE_DISABLED || c == 0)
    return TCL_OK;

  if (which == MOD_COLS) {
    maxkey	= maxcol;
    minkey	= tablePtr->colOffset+tablePtr->titleCols;
    lo		= tablePtr->rowOffset+(movetitle?0:tablePtr->titleRows);
    hi		= maxrow;
    offset	= tablePtr->colOffset;
    tagTblPtr	= tablePtr->colStyles;
    dimTblPtr	= tablePtr->colWidths;
    dimPtr	= &(tablePtr->cols);
  } else {
    maxkey	= maxrow;
    minkey	= tablePtr->rowOffset+tablePtr->titleRows;
    lo		= tablePtr->colOffset+(movetitle?0:tablePtr->titleCols);
    hi		= maxcol;
    offset	= tablePtr->rowOffset;
    tagTblPtr	= tablePtr->rowStyles;
    dimTblPtr	= tablePtr->rowHeights;
    dimPtr	= &(tablePtr->rows);
  }

  if (type == CMD_DELETE) {
    /* Handle row/col deletion */
    first = MAX(MIN(idx,idx+c), minkey);
    /* (index = i && count = 1) == (index = i && count = -1) */
    if (c < 0) {
      /* if the count is negative, make sure that the col count will delete
       * no greater than the original index */
      c = idx-first;
      first++;
    }
    if (movedim) {
      *dimPtr -= c;
    }
    for (i = first; i <= maxkey; i++) {
      TableModifyRCaux(tablePtr, type, which, movetag, tagTblPtr,
		       dimTblPtr, offset, i, i+c, lo, hi, ((i+c)>maxkey));
    }
  } else {
    /* Handle row/col insertion */
    first = MAX(MIN(idx, maxkey), minkey);
    /* +count means insert after index, -count means insert before index */
    if (c < 0) {
      c = -c;
    } else {
      first++;
    }
    if (movedim) {
      maxkey += c;
      *dimPtr += c;
    }
    for (i = maxkey; i >= first; i--) {
      /* move row/col style && width/height here */
      TableModifyRCaux(tablePtr, type, which, movetag, tagTblPtr,
		       dimTblPtr, offset, i, i-c, lo, hi, ((i-c)<first));
    }
  }
  if (Tcl_FirstHashEntry(tablePtr->selCells, &search) != NULL) {
    /* clear selection - forceful, but effective */
    Tcl_DeleteHashTable(tablePtr->selCells);
    ckfree((char *) (tablePtr->selCells));
    tablePtr->selCells = (Tcl_HashTable *)ckalloc(sizeof(Tcl_HashTable));
    Tcl_InitHashTable(tablePtr->selCells, TCL_STRING_KEYS);
  }

  TableAdjustParams(tablePtr);
  if (which == MOD_COLS) {
    TableCellCoords(tablePtr, 0, first, &x, &y, &offset, &offset);
    TableInvalidate(tablePtr, x, y,
		    Tk_Width(tablePtr->tkwin)-x,
		    Tk_Height(tablePtr->tkwin), 0);
  } else {
    TableCellCoords(tablePtr, first, 0, &x, &y, &offset, &offset);
    TableInvalidate(tablePtr, x, y,
		    Tk_Width(tablePtr->tkwin),
		    Tk_Height(tablePtr->tkwin)-y, 0);
  }
  return TCL_OK;
}

/*
 *--------------------------------------------------------------
 *
 * TableWidgetCmd --
 *	This procedure is invoked to process the Tcl command
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
static int
TableWidgetCmd(clientData, interp, argc, argv)
     ClientData clientData;		/* Information about listbox widget. */
     Tcl_Interp *interp;		/* Current interpreter. */
     int argc;				/* Number of arguments. */
     char **argv;			/* Argument strings. */
{
  Tcl_HashEntry *entryPtr;
  Tcl_HashSearch search;
  Tcl_HashTable *hashTablePtr;
  int result, retval, sub_retval, row, col, x, y;
  int i, width, height, dummy, key, value, posn, offset;
  char buf1[INDEX_BUFSIZE], buf2[INDEX_BUFSIZE];

  Table *tablePtr = (Table *) clientData;

  if (argc < 2) {
    Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		     " option ?arg arg ...?\"", (char *) NULL);
    return TCL_ERROR;
  }
  Tcl_Preserve(clientData);

  result = TCL_OK;
  /* parse the first parameter */
  retval = Cmd_Parse(interp, main_cmds, argv[1]);

  /* Switch on the parameter value */
  switch (retval) {
  case 0:
    /* error, the return string is already set up */
    result = TCL_ERROR;
    break;

  case CMD_ACTIVATE:
    if (argc != 3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " activate index\"", (char *)NULL);
      result = TCL_ERROR;
    } else if (TableGetIndex(tablePtr, argv[2], &row, &col) == TCL_ERROR) {
      result = TCL_ERROR;
    } else {
      /* convert to valid active index in real coords */
      row -= tablePtr->rowOffset;
      col -= tablePtr->colOffset;
      /* we do this regardless, to avoid cell commit problems */
      if ((tablePtr->flags & HAS_ACTIVE) &&
	  (tablePtr->flags & TEXT_CHANGED)) {
	tablePtr->flags &= ~TEXT_CHANGED;
	TableSetCellValue(tablePtr, tablePtr->activeRow+tablePtr->rowOffset,
			  tablePtr->activeCol+tablePtr->colOffset,
			  tablePtr->activeBuf);
      }
      if (row != tablePtr->activeRow || col != tablePtr->activeCol) {
	if (tablePtr->flags & HAS_ACTIVE) {
	  TableMakeArrayIndex(tablePtr->activeRow+tablePtr->rowOffset,
			      tablePtr->activeCol+tablePtr->colOffset, buf1);
	} else {
	  buf1[0] = '\0';
	}
	tablePtr->flags |= HAS_ACTIVE;
	tablePtr->flags &= ~ACTIVE_DISABLED;
	tablePtr->activeRow = row;
	tablePtr->activeCol = col;
	if (tablePtr->activeLayout) {
	  Tk_FreeTextLayout(tablePtr->activeLayout);
	  tablePtr->activeLayout = NULL;
	}
	TableAdjustActive(tablePtr);
	TableConfigCursor(tablePtr);
	if (!(tablePtr->flags & BROWSE_CMD) && tablePtr->browseCmd != NULL) {
	  Tcl_DString script;
	  tablePtr->flags |= BROWSE_CMD;
	  row = tablePtr->activeRow+tablePtr->rowOffset;
	  col = tablePtr->activeCol+tablePtr->colOffset;
	  TableMakeArrayIndex(row, col, buf2);
	  Tcl_DStringInit(&script);
	  ExpandPercents(tablePtr, tablePtr->browseCmd, row, col, buf1, buf2,
			 tablePtr->icursor, &script, CMD_ACTIVATE);
	  result = Tcl_GlobalEval(interp, Tcl_DStringValue(&script));
	  if (result == TCL_OK || result == TCL_RETURN)
	    Tcl_ResetResult(interp);
	  Tcl_DStringFree(&script);
	  tablePtr->flags &= ~BROWSE_CMD;
	}
      } else if ((tablePtr->activeLayout != NULL) &&
		 !(tablePtr->flags & ACTIVE_DISABLED) && argv[2][0] == '@' &&
		 TableCellVCoords(tablePtr, row, col, &x, &y,
				  &dummy, &dummy, 0)) {
	/* we are clicking into the same cell */
	/* If it was activated with @x,y indexing, find the closest char */
	char *p;

	/* no error checking because GetIndex did it for us */
	p = argv[2]+1;
	x = strtol(p, &p, 0) - x - tablePtr->activeX;
	y = strtol(++p, &p, 0) - y - tablePtr->activeY;

	tablePtr->icursor = Tk_PointToChar(tablePtr->activeLayout, x, y);
	TableConfigCursor(tablePtr);
      }
      tablePtr->flags |= HAS_ACTIVE;
    }
    break;	/* ACTIVATE */

  case CMD_BBOX: {
    /* bounding box of cell(s) */
    if (argc < 3 || argc > 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			" bbox first ?last?\"", (char *) NULL);
      result = TCL_ERROR;
    } else if (TableGetIndex(tablePtr, argv[2], &row, &col) == TCL_ERROR) {
      result = TCL_ERROR;
    } else if (argc == 3) {
      row -= tablePtr->rowOffset; col -= tablePtr->colOffset;
      if (TableCellVCoords(tablePtr, row, col, &x, &y, &width, &height, 0)) {
	sprintf(buf1, "%d %d %d %d", x, y, width, height);
	Tcl_SetResult(interp, buf1, TCL_VOLATILE);
      }
    } else if (TableGetIndex(tablePtr, argv[3], &x, &y) == TCL_ERROR) {
      result = TCL_ERROR;
    } else {
      int r1, c1, r2, c2, minX = 99999, minY = 99999, maxX = 0, maxY = 0;
      row -= tablePtr->rowOffset; col -= tablePtr->colOffset;
      x -= tablePtr->rowOffset; y -= tablePtr->colOffset;
      r1 = MIN(row,x); r2 = MAX(row,x);
      c1 = MIN(col,y); c2 = MAX(col,y);
      key = 0;
      for (row = r1; row <= r2; row++) {
	for (col = c1; col <= c2; col++) {
	  if (TableCellVCoords(tablePtr, row, col, &x, &y,
			       &width, &height, 0)) {
	    /* Get max bounding box */
	    if (x < minX) minX = x;
	    if (y < minY) minY = y;
	    if (x+width > maxX) maxX = x+width;
	    if (y+height > maxY) maxY = y+height;
	    key++;
	  }
	  /* FIX - This could break on else for speed */
	}
      }
      if (key) {
	sprintf(buf1, "%d %d %d %d", minX, minY, maxX-minX, maxY-minY);
	Tcl_SetResult(interp, buf1, TCL_VOLATILE);
      }
    }
  }
  break;	/* BBOX */

  case CMD_BORDER:
    if (argc > 6) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " border mark|dragto x y ?r|c?\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    sub_retval = Cmd_Parse(interp, bd_cmds, argv[2]);
    if (sub_retval == 0 || Tcl_GetInt(interp, argv[3], &x) != TCL_OK ||
	Tcl_GetInt(interp, argv[4], &y) != TCL_OK) {
      result = TCL_ERROR;
      break;
    }
    switch (sub_retval) {
    case BD_MARK:
      /* Use x && y to determine if we are over a border */
      value = TableAtBorder(tablePtr, x, y, &row, &col);
      /* Cache the row && col for use in DRAGTO */
      tablePtr->scanMarkRow = row;
      tablePtr->scanMarkCol = col;
      if (!value) break;
      TableCellCoords(tablePtr, row, col, &x, &y, &dummy, &dummy);
      tablePtr->scanMarkX = x;
      tablePtr->scanMarkY = y;
      if (argc == 5 || argv[5][0] == 'r') {
	if (row < 0)
	  buf1[0] = '\0';
	else
	  sprintf(buf1, "%d", row+tablePtr->rowOffset);
	Tcl_AppendElement(interp, buf1);
      }
      if (argc == 5 || argv[5][0] == 'c') {
	if (col < 0)
	  buf1[0] = '\0';
	else
	  sprintf(buf1, "%d", col+tablePtr->colOffset);
	Tcl_AppendElement(interp, buf1);
      }
      break;	/* BORDER MARK */
    case BD_DRAGTO:
      /* check to see if we want to resize any borders */
      if (tablePtr->resize == SEL_NONE) break;
      row = tablePtr->scanMarkRow;
      col = tablePtr->scanMarkCol;
      TableCellCoords(tablePtr, row, col, &width, &height, &dummy, &dummy);
      key = 0;
      if (row >= 0 && (tablePtr->resize & SEL_ROW)) {
	/* row border was active, move it */
	/* FIX should this be 1 or 2 bds off? */
	value = y-height-tablePtr->borderWidth;
	if (value < -1) value = -1;
	if (value != tablePtr->scanMarkY) {
	  entryPtr = Tcl_CreateHashEntry(tablePtr->rowHeights,
					 (char *) row, &dummy);
	  /* -value means rowHeight will be interp'd as pixels, not lines */
	  Tcl_SetHashValue(entryPtr, (ClientData) MIN(0,-value));
	  tablePtr->scanMarkY = value;
	  key++;
	}
      }
      if (col >= 0 && (tablePtr->resize & SEL_COL)) {
	/* col border was active, move it */
	value = x-width-tablePtr->borderWidth;
	if (value < -1) value = -1;
	if (value != tablePtr->scanMarkX) {
	  entryPtr = Tcl_CreateHashEntry(tablePtr->colWidths,
					 (char *) col, &dummy);
	  /* -value means colWidth will be interp'd as pixels, not chars */
	  Tcl_SetHashValue(entryPtr, (ClientData) MIN(0,-value));
	  tablePtr->scanMarkX = value;
	  key++;
	}
      }
      /* Only if something changed do we want to update */
      if (key) {
	TableAdjustParams(tablePtr);
	/* Only rerequest geometry if the basis is the #rows &| #cols */
	if (tablePtr->maxReqCols || tablePtr->maxReqRows)
	  TableGeometryRequest(tablePtr);
	TableInvalidateAll(tablePtr, 0);
      }
      break;	/* BORDER DRAGTO */
    }
    break;	/* BORDER */

  case CMD_CGET:
    if (argc != 3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " cget option\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    result = Tk_ConfigureValue(interp, tablePtr->tkwin, TableConfig,
			       (char *) tablePtr, argv[2], 0);
    break;	/* CGET */

  case CMD_CLEAR:
    if (argc < 3 || argc > 5) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " clear option ?first? ?last?\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    }

    sub_retval = Cmd_Parse(interp, clear_cmds, argv[2]);
    result = TableClear(tablePtr, sub_retval,
			(argc>3)?argv[3]:NULL, (argc>4)?argv[4]:NULL);
    break;	/* CLEAR */

  case CMD_CONFIGURE:
    switch (argc) {
    case 2:
      result = Tk_ConfigureInfo(interp, tablePtr->tkwin, TableConfig,
				(char *) tablePtr, (char *) NULL, 0);
      break;
    case 3:
      result = Tk_ConfigureInfo(interp, tablePtr->tkwin, TableConfig,
				(char *) tablePtr, argv[2], 0);
      break;
    default:
      result = TableConfigure(interp, tablePtr, argc - 2, argv + 2,
			      TK_CONFIG_ARGV_ONLY, 0);
    }
    break;	/* CONFIGURE */

  case CMD_CURVALUE:
    /* Get current active cell buffer */
    if (argc > 3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
                       argv[0], " curvalue ?<value>?\"", (char *)NULL);
      result = TCL_ERROR;
    } else if (tablePtr->flags & HAS_ACTIVE) {
      if (argc == 3 && strcmp(argv[2], tablePtr->activeBuf)) {
	key = TCL_OK;
	/* validate potential new active buffer contents
	 * only accept if validation returns acceptance. */
	if (tablePtr->validate &&
	    TableValidateChange(tablePtr,
				tablePtr->activeRow+tablePtr->rowOffset,
				tablePtr->activeCol+tablePtr->colOffset,
				tablePtr->activeBuf,
				argv[2], tablePtr->icursor) != TCL_OK) {
	  break;
	}
	tablePtr->activeBuf = (char *)ckrealloc(tablePtr->activeBuf,
						strlen(argv[2])+1);
	strcpy(tablePtr->activeBuf, argv[2]);
	/* mark the text as changed */
	tablePtr->flags |= TEXT_CHANGED;
	TableSetActiveIndex(tablePtr);
	/* check for possible adjustment of icursor */
	TableGetIcursor(tablePtr, "insert", (int *)0);
	TableRefresh(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
		     CELL|INV_FORCE);
	if (key == TCL_ERROR) {
	  result = TCL_ERROR;
	  break;
	}
      }
      Tcl_AppendResult(interp, tablePtr->activeBuf, (char *)NULL);
    }
    break;	/* CURVALUE */

  case CMD_CURSELECTION:
    if ((argc != 2 && argc != 4) ||
	(argc == 4 && (argv[2][0] == '\0' ||
		       strncmp(argv[2], "set", strlen(argv[2]))))) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " curselection ?set <value>?\"", (char *)NULL);
      result = TCL_ERROR;
      break;
    }
    /* make sure there is a data source to accept set */
    if (argc == 4 && (tablePtr->state == STATE_DISABLED ||
		      (tablePtr->dataSource == DATA_NONE)))
      break;
    for (entryPtr = Tcl_FirstHashEntry(tablePtr->selCells, &search);
	 entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
      if (argc == 2) {
	Tcl_AppendElement(interp,
			  Tcl_GetHashKey(tablePtr->selCells, entryPtr));
      } else {
	TableParseArrayIndex(&row, &col,
			     Tcl_GetHashKey(tablePtr->selCells, entryPtr));
	TableSetCellValue(tablePtr, row, col, argv[3]);
	row -= tablePtr->rowOffset;
	col -= tablePtr->colOffset;
	if (row == tablePtr->activeRow && col == tablePtr->activeCol) {
	  TableGetActiveBuf(tablePtr);
	}
	TableCellCoords(tablePtr, row, col, &x, &y, &width, &height);
	TableInvalidate(tablePtr, x, y, width, height, 0);
      }
    }
    if (argc == 2) {
      Tcl_SetResult(interp,
		    TableCellSort(tablePtr, Tcl_GetStringResult(interp)),
		    TCL_DYNAMIC);
    }
    break;	/* CURSELECTION */

  case CMD_DELETE:
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			" delete option ?switches? arg ?arg?\"",
			(char *) NULL);
      result = TCL_ERROR;
      break;
    }
    sub_retval = Cmd_Parse (interp, mod_cmds, argv[2]);
    switch (sub_retval) {
    case 0:
      result = TCL_ERROR;
      break;
    case MOD_ACTIVE:
      if (argc > 5) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " delete active first ?last?\"", (char *) NULL);
	result = TCL_ERROR;
	break;
      }
      if (TableGetIcursor(tablePtr, argv[3], &posn) == TCL_ERROR) {
	result = TCL_ERROR;
	break;
      }
      if (argc == 4) {
	value = posn+1;
      } else if (TableGetIcursor(tablePtr, argv[4], &value) == TCL_ERROR) {
	result = TCL_ERROR;
	break;
      }
      if (value >= posn && (tablePtr->flags & HAS_ACTIVE) &&
	  !(tablePtr->flags & ACTIVE_DISABLED) &&
	  tablePtr->state == STATE_NORMAL)
	TableDeleteChars(tablePtr, posn, value-posn);
      break;	/* DELETE ACTIVE */
    case MOD_COLS:
    case MOD_ROWS:
      result = TableModifyRC(tablePtr, interp, CMD_DELETE, sub_retval,
			     argc, argv);
      break;	/* DELETE ROWS */
    }
    break;	/* DELETE */

  case CMD_GET: {
    int r1, c1, r2, c2;

    if (argc < 3 || argc > 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " get first ?last?\"", (char *)NULL);
      result = TCL_ERROR;
    } else if (TableGetIndex(tablePtr, argv[2], &row, &col) == TCL_ERROR) {
      result = TCL_ERROR;
    } else if (argc == 3) {
      Tcl_SetResult(interp, TableGetCellValue(tablePtr, row, col), TCL_STATIC);
    } else if (TableGetIndex(tablePtr, argv[3], &r2, &c2) == TCL_ERROR) {
      result = TCL_ERROR;
    } else {
      r1 = MIN(row,r2); r2 = MAX(row,r2);
      c1 = MIN(col,c2); c2 = MAX(col,c2);
      for ( row = r1; row <= r2; row++ ) {
	for ( col = c1; col <= c2; col++ ) {
	  Tcl_AppendElement(interp, TableGetCellValue(tablePtr, row, col));
	}
      }
    }
  }
  break;	/* GET */

  case CMD_FLUSH: /* FIX - DEPRECATED */
    if (argc > 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " flush ?first? ?last?\"", (char *) NULL);
      result = TCL_ERROR;
    } else {
      result = TableClear(tablePtr, CLEAR_CACHE,
			  (argc>2)?argv[2]:NULL, (argc>3)?argv[3]:NULL);
    }
    break;	/* FLUSH */

  case CMD_HEIGHT:
  case CMD_WIDTH:
    /* changes the width/height of certain selected columns */
    if (argc != 3 && (argc & 1)) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       (retval == CMD_WIDTH) ?
		       " width ?col? ?width col width ...?\"" :
		       " height ?row? ?height row height ...?\"",
		       (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    if (retval == CMD_WIDTH) {
      hashTablePtr = tablePtr->colWidths;
      offset = tablePtr->colOffset;
    } else { 
      hashTablePtr = tablePtr->rowHeights;
      offset = tablePtr->rowOffset;
    }

    if (argc == 2) {
      /* print out all the preset column widths or row heights */
      entryPtr = Tcl_FirstHashEntry(hashTablePtr, &search);
      while (entryPtr != NULL) {
	posn = ((int) Tcl_GetHashKey(hashTablePtr, entryPtr)) + offset;
	value = (int) Tcl_GetHashValue(entryPtr);
	sprintf(buf1, "%d %d", posn, value);
	Tcl_AppendElement(interp, buf1);
	entryPtr = Tcl_NextHashEntry(&search);
      }
    } else if (argc == 3) {
      /* get the width/height of a particular row/col */
      if (Tcl_GetInt(interp, argv[2], &posn) != TCL_OK) {
	result = TCL_ERROR;
	break;
      }
      /* no range check is done, why bother? */
      posn -= offset;
      entryPtr = Tcl_FindHashEntry(hashTablePtr, (char *) posn);
      if (entryPtr != NULL) {
	sprintf(buf1, "%d", (int) Tcl_GetHashValue(entryPtr));
	Tcl_SetResult(interp, buf1, TCL_VOLATILE);
      } else {
	sprintf(buf1, "%d", (retval == CMD_WIDTH) ?
		tablePtr->defColWidth : tablePtr->defRowHeight);
	Tcl_SetResult(interp, buf1, TCL_VOLATILE);
      }
    } else {
      for (i=2; i<argc; i++) {
	/* set new width|height here */
	value = -999999;
	if (Tcl_GetInt(interp, argv[i++], &posn) != TCL_OK ||
	    (strncmp(argv[i], "default", strlen(argv[i])) &&
	     Tcl_GetInt(interp, argv[i], &value) != TCL_OK)) {
	  result = TCL_ERROR;
	  break;
	}
	posn -= offset;
	if (value == -999999) {
	  /* reset that field */
	  if ((entryPtr = Tcl_FindHashEntry(hashTablePtr, (char *) posn)))
	    Tcl_DeleteHashEntry(entryPtr);
	} else {
	  entryPtr = Tcl_CreateHashEntry(hashTablePtr, (char *) posn, &dummy);
	  Tcl_SetHashValue(entryPtr, (ClientData) value);
	}
      }
      TableAdjustParams(tablePtr);
      /* rerequest geometry */
      TableGeometryRequest(tablePtr);
      /*
       * Invalidate the whole window as TableAdjustParams
       * will only check to see if the top left cell has moved
       * FIX: should just move from lowest order visible cell to edge of window
       */
      TableInvalidateAll(tablePtr, 0);
    }
    break;	/* HEIGHT && WIDTH */

  case CMD_ICURSOR:
    /* set the insertion cursor */
    if (!(tablePtr->flags & HAS_ACTIVE) ||
	(tablePtr->flags & ACTIVE_DISABLED) ||
	 tablePtr->state == STATE_DISABLED)
      break;
    switch (argc) {
    case 2:
      sprintf(buf1, "%d", tablePtr->icursor);
      Tcl_SetResult(interp, buf1, TCL_VOLATILE);
      break;
    case 3:
      if (TableGetIcursor(tablePtr, argv[2], (int *)0) != TCL_OK) {
	result = TCL_ERROR;
	break;
      }
      TableRefresh(tablePtr, tablePtr->activeRow, tablePtr->activeCol, CELL);
      break;
    default:
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " icursor arg\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    break;	/* ICURSOR */

  case CMD_INDEX:
    if (argc < 3 || argc > 4 ||
	TableGetIndex(tablePtr, argv[2], &row, &col) == TCL_ERROR ||
	(argc == 4 && (strcmp(argv[3], "row") && strcmp(argv[3], "col")))) {
      if (!strlen(Tcl_GetStringResult(interp))) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " index index ?row|col?\"", (char *)NULL);
      }
      result = TCL_ERROR;
      break;
    }
    if (argc == 3) {
      TableMakeArrayIndex(row, col, buf1);
    } else if (argv[3][0] == 'r') { /* INDEX row */
      sprintf(buf1, "%d", row);
    } else {	/* INDEX col */
      sprintf(buf1, "%d", col);
    }
    Tcl_SetResult(interp, buf1, TCL_VOLATILE);
    break;	/* INDEX */

  case CMD_INSERT:
    /* are edits enabled */
    if (argc < 4) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " insert option ?switches? arg ?arg?\"", (char *)NULL);
      result = TCL_ERROR;
      break;
    }
    sub_retval = Cmd_Parse(interp, mod_cmds, argv[2]);
    switch (sub_retval) {
    case 0:
      result = TCL_ERROR;
      break;
    case MOD_ACTIVE:
      if (argc != 5) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " insert active index string\"", (char *)NULL);
	result = TCL_ERROR;
      } else if (TableGetIcursor(tablePtr, argv[3], &posn) != TCL_OK) {
	result = TCL_ERROR;
      } else if ((tablePtr->flags & HAS_ACTIVE) &&
		 !(tablePtr->flags & ACTIVE_DISABLED) &&
		 tablePtr->state == STATE_NORMAL) {
	TableInsertChars(tablePtr, posn, argv[4]);
      }
      break;	/* INSERT ACTIVE */
    case MOD_COLS:
    case MOD_ROWS:
      result = TableModifyRC(tablePtr, interp, CMD_INSERT, sub_retval,
			     argc, argv);
      break;
    }
    break;	/* INSERT */

  case CMD_REREAD:
    /* this rereads the selection from the array */
    if (!(tablePtr->flags & HAS_ACTIVE) ||
	(tablePtr->flags & ACTIVE_DISABLED) ||
	tablePtr->state == STATE_DISABLED)
      break;
    TableGetActiveBuf(tablePtr);
    TableRefresh(tablePtr, tablePtr->activeRow, tablePtr->activeCol,
		 CELL|INV_FORCE);
    break;	/* REREAD */

  case CMD_SCAN:
    if (argc != 5) {
      Tcl_AppendResult(interp, "wrong # args: should be \"",
		       argv[0], " scan mark|dragto x y\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    } else if (Tcl_GetInt(interp, argv[3], &x) == TCL_ERROR ||
	       Tcl_GetInt(interp, argv[4], &y) == TCL_ERROR) {
      result = TCL_ERROR;
      break;
    }
    if ((argv[2][0] == 'm')
	&& (strncmp(argv[2], "mark", strlen(argv[2])) == 0)) {
      TableWhatCell(tablePtr, x, y, &row, &col);
      tablePtr->scanMarkRow = row-tablePtr->topRow;
      tablePtr->scanMarkCol = col-tablePtr->leftCol;
      tablePtr->scanMarkX = x;
      tablePtr->scanMarkY = y;
    } else if ((argv[2][0] == 'd')
	       && (strncmp(argv[2], "dragto", strlen(argv[2])) == 0)) {
      int oldTop = tablePtr->topRow, oldLeft = tablePtr->leftCol;
      y += (5*(y-tablePtr->scanMarkY));
      x += (5*(x-tablePtr->scanMarkX));

      TableWhatCell(tablePtr, x, y, &row, &col);

      /* maintain appropriate real index */
      tablePtr->topRow  = MAX(MIN(row-tablePtr->scanMarkRow,
				  tablePtr->rows-1), tablePtr->titleRows);
      tablePtr->leftCol = MAX(MIN(col-tablePtr->scanMarkCol,
				  tablePtr->cols-1), tablePtr->titleCols);

      /* Adjust the table if new top left */
      if (oldTop != tablePtr->topRow || oldLeft != tablePtr->leftCol)
	TableAdjustParams(tablePtr);
    } else {
      Tcl_AppendResult(interp, "bad scan option \"", argv[2],
		       "\": must be mark or dragto", (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    break;	/* SCAN */

  case CMD_SEE:
    if (argc!=3 || TableGetIndex(tablePtr,argv[2],&row,&col)==TCL_ERROR) {
      if (!strlen(Tcl_GetStringResult(interp))) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " see index\"", (char *)NULL);
      }
      result = TCL_ERROR;
      break;
    }
    /* Adjust from user to master coords */
    row -= tablePtr->rowOffset;
    col -= tablePtr->colOffset;
    if (!TableCellVCoords(tablePtr, row, col, &x, &x, &x, &x, 1)) {
      tablePtr->topRow  = row-1;
      tablePtr->leftCol = col-1;
      TableAdjustParams(tablePtr);
    }
    break;	/* SEE */

  case CMD_SELECTION:
    if (argc<3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " selection option args\"", (char *)NULL);
      result=TCL_ERROR;
      break;
    }
    retval = Cmd_Parse(interp, sel_cmds, argv[2]);
    switch(retval) {
    case 0: 		/* failed to parse the argument, error */
      return TCL_ERROR;
    case SEL_ANCHOR:
      if (argc != 4 || TableGetIndex(tablePtr,argv[3],&row,&col) != TCL_OK) {
	if (!strlen(Tcl_GetStringResult(interp)))
	  Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			   " selection anchor index\"", (char *)NULL);
	result=TCL_ERROR;
	break;
      }
      tablePtr->flags |= HAS_ANCHOR;
      /* maintain appropriate real index */
      if (tablePtr->selectTitles) {
	tablePtr->anchorRow = MIN(MAX(0,row-tablePtr->rowOffset),
				  tablePtr->rows-1);
	tablePtr->anchorCol = MIN(MAX(0,col-tablePtr->colOffset),
				  tablePtr->cols-1);
      } else {
	tablePtr->anchorRow = MIN(MAX(tablePtr->titleRows,
				      row-tablePtr->rowOffset),
				  tablePtr->rows-1);
	tablePtr->anchorCol = MIN(MAX(tablePtr->titleCols,
				      col-tablePtr->colOffset),
				  tablePtr->cols-1);
      }
      break;
    case SEL_CLEAR:
      if ( argc != 4 && argc != 5 ) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " selection clear all|<first> ?<last>?\"",
			 (char *)NULL);
	result=TCL_ERROR;
	break;
      }
      if (strcmp(argv[3],"all") == 0) {
	for(entryPtr = Tcl_FirstHashEntry(tablePtr->selCells, &search);
	    entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
	  TableParseArrayIndex(&row, &col,
			       Tcl_GetHashKey(tablePtr->selCells,entryPtr));
	  Tcl_DeleteHashEntry(entryPtr);
	  TableCellCoords(tablePtr, row-tablePtr->rowOffset,
			  col-tablePtr->colOffset, &x, &y, &width, &height);
	  TableInvalidate(tablePtr, x, y, width, height, 0);
	}
      } else {
	int clo=0,chi=0,r1,c1,r2,c2;
	if (TableGetIndex(tablePtr,argv[3],&row,&col) == TCL_ERROR ||
	    (argc==5 && TableGetIndex(tablePtr,argv[4],&r2,&c2)==TCL_ERROR)) {
	  result = TCL_ERROR;
	  break;
	}
	key = 0;
	if (argc == 4) {
	  r1 = r2 = row;
	  c1 = c2 = col;
	} else {
	  r1 = MIN(row,r2); r2 = MAX(row,r2);
	  c1 = MIN(col,c2); c2 = MAX(col,c2);
	}
	switch (tablePtr->selectType) {
	case SEL_BOTH:
	  clo = c1; chi = c2;
	  c1 = tablePtr->colOffset;
	  c2 = tablePtr->cols-1+c1;
	  key = 1;
	  goto CLEAR_CELLS;
	CLEAR_BOTH:
	  key = 0;
	  c1 = clo; c2 = chi;
	case SEL_COL:
	  r1 = tablePtr->rowOffset;
	  r2 = tablePtr->rows-1+r1;
	  break;
	case SEL_ROW:
	  c1 = tablePtr->colOffset;
	  c2 = tablePtr->cols-1+c1;
	  break;
	}
	/* row/col are in user index coords */
      CLEAR_CELLS:
	for ( row = r1; row <= r2; row++ ) {
	  for ( col = c1; col <= c2; col++ ) {
	    TableMakeArrayIndex(row, col, buf1);
	    if ((entryPtr=Tcl_FindHashEntry(tablePtr->selCells, buf1))!=NULL) {
	      Tcl_DeleteHashEntry(entryPtr);
	      TableCellCoords(tablePtr, row-tablePtr->rowOffset,
			      col-tablePtr->colOffset,&x,&y,&width,&height);
	      TableInvalidate(tablePtr, x, y, width, height, 0);
	    }
	  }
	}
	if (key) goto CLEAR_BOTH;
      }
      break;	/* SELECTION CLEAR */
    case SEL_INCLUDES:
      if (argc != 4) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " selection includes index\"", (char *)NULL);
	result = TCL_ERROR;
      } else if (TableGetIndex(tablePtr, argv[3], &row, &col) == TCL_ERROR) {
	result = TCL_ERROR;
      } else {
	TableMakeArrayIndex(row, col, buf1);
	if (Tcl_FindHashEntry(tablePtr->selCells, buf1)) {
	  Tcl_SetResult(interp, "1", TCL_STATIC);
	} else {
	  Tcl_SetResult(interp, "0", TCL_STATIC);
	}
      }
      break;	/* SELECTION INCLUDES */
    case SEL_SET: {
      int clo=0, chi=0, r1, c1, r2, c2, titleRows, titleCols;
      if (argc < 4 || argc > 5) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
			 " selection set first ?last?\"", (char *)NULL);
	result = TCL_ERROR;
	break;
      }
      if (TableGetIndex(tablePtr,argv[3],&row,&col) == TCL_ERROR ||
	  (argc==5 && TableGetIndex(tablePtr,argv[4],&r2,&c2)==TCL_ERROR)) {
	result = TCL_ERROR;
	break;
      }
      key = 0;
      if (tablePtr->selectTitles) {
	titleRows = 0;
	titleCols = 0;
      } else {
	titleRows = tablePtr->titleRows;
	titleCols = tablePtr->titleCols;
      }
      /* maintain appropriate user index */
      row = MIN(MAX(titleRows+tablePtr->rowOffset, row),
		tablePtr->rows-1+tablePtr->rowOffset);
      col = MIN(MAX(titleCols+tablePtr->colOffset, col),
		tablePtr->cols-1+tablePtr->colOffset);
      if (argc == 4) {
	r1 = r2 = row;
	c1 = c2 = col;
      } else {
	r2 = MIN(MAX(titleRows+tablePtr->rowOffset, r2),
		 tablePtr->rows-1+tablePtr->rowOffset);
	c2 = MIN(MAX(titleCols+tablePtr->colOffset, c2),
		 tablePtr->cols-1+tablePtr->colOffset);
	r1 = MIN(row,r2); r2 = MAX(row,r2);
	c1 = MIN(col,c2); c2 = MAX(col,c2);
      }
      switch (tablePtr->selectType) {
      case SEL_BOTH:
	clo = c1; chi = c2;
	c1 = titleCols+tablePtr->colOffset;
	c2 = tablePtr->cols-1+tablePtr->colOffset;
	key = 1;
	goto SET_CELLS;
      SET_BOTH:
	key = 0;
	c1 = clo; c2 = chi;
      case SEL_COL:
	r1 = titleRows+tablePtr->rowOffset;
	r2 = tablePtr->rows-1+tablePtr->rowOffset;
	break;
      case SEL_ROW:
	c1 = titleCols+tablePtr->colOffset;
	c2 = tablePtr->cols-1+tablePtr->colOffset;
	break;
      }
    SET_CELLS:
      entryPtr = Tcl_FirstHashEntry(tablePtr->selCells, &search);
      for ( row = r1; row <= r2; row++ ) {
	for ( col = c1; col <= c2; col++ ) {
	  TableMakeArrayIndex(row, col, buf1);
	  if (Tcl_FindHashEntry(tablePtr->selCells, buf1) == NULL) {
	    Tcl_CreateHashEntry(tablePtr->selCells, buf1, &dummy);
	    TableCellCoords(tablePtr, row-tablePtr->rowOffset,
			    col-tablePtr->colOffset, &x, &y, &width, &height);
	    TableInvalidate(tablePtr, x, y, width, height, 0);
	  }
	}
      }
      if (key) goto SET_BOTH;

      /* Adjust the table for top left, selection on screen etc */
      TableAdjustParams(tablePtr);

      /* If the table was previously empty and we want to export the
       * selection, we should grab it now */
      if (entryPtr==NULL && tablePtr->exportSelection) {
	Tk_OwnSelection(tablePtr->tkwin, XA_PRIMARY, TableLostSelection,
			(ClientData) tablePtr);
      }
    }
    break;	/* SELECTION SET */
    }
    break;	/* SELECTION */

  case CMD_SET:
    /* sets any number of tags/indices to a given value */
    if (argc < 3 || (argc > 3 && (argc & 1))) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " set index ?value? ?index value ...?\"",
		       (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    /* make sure there is a data source to accept set */
    if (tablePtr->dataSource == DATA_NONE)
      break;
    if (argc == 3) {
      if (TableGetIndex(tablePtr, argv[2], &row, &col) != TCL_OK) {
	result = TCL_ERROR;
	break;
      }
      Tcl_SetResult(interp, TableGetCellValue(tablePtr, row, col),
		    TCL_STATIC);
    } else if (tablePtr->state == STATE_NORMAL) {
      for (i=2; i<argc; i++) {
	if (TableGetIndex(tablePtr, argv[i], &row, &col) != TCL_OK) {
	  result = TCL_ERROR;
	  break;
	}
	if (TableSetCellValue(tablePtr, row, col, argv[++i]) == TCL_ERROR) {
	  result = TCL_ERROR;
	  break;
	}
	row -= tablePtr->rowOffset;
	col -= tablePtr->colOffset;
	if (row == tablePtr->activeRow && col == tablePtr->activeCol) {
	  TableGetActiveBuf(tablePtr);
	}
	TableCellCoords(tablePtr, row, col, &x, &y, &width, &height);
	TableInvalidate(tablePtr, x, y, width, height, 0);
      }
    }
    break;

  case CMD_TAG:
    /* a veritable plethora of tag commands */
    /* do we have another argument */
    if (argc < 3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " tag option ?arg arg ...?\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    /* all the rest is now done in a separate function */
    result = TableTagCmd(tablePtr, interp, argc, argv);
    break;	/* TAG */

  case CMD_VALIDATE:
    if (argc != 3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " validate index\"", (char *) NULL);
      result = TCL_ERROR;
    } else if (TableGetIndex(tablePtr, argv[2], &row, &col) == TCL_ERROR) {
      result = TCL_ERROR;
    } else {
      value = tablePtr->validate;
      tablePtr->validate = 1;
      key = TableValidateChange(tablePtr, row, col, (char *) NULL,
				(char *) NULL, -1);
      tablePtr->validate = value;
      sprintf(buf1, "%d", (key == TCL_OK) ? 1 : 0);
      Tcl_SetResult(interp, buf1, TCL_VOLATILE);
    }
    break;

  case CMD_VERSION:
    if (argc != 2) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " version\"", (char *) NULL);
      result = TCL_ERROR;
    } else {
      Tcl_SetResult(interp, TBL_VERSION, TCL_VOLATILE);
    }
    break;

  case CMD_WINDOW:
    /* a veritable plethora of window commands */
    /* do we have another argument */
    if (argc < 3) {
      Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
		       " window option ?arg arg ...?\"", (char *) NULL);
      result = TCL_ERROR;
      break;
    }
    /* all the rest is now done in a separate function */
    result = TableWindowCmd(tablePtr, interp, argc, argv);
    break;

  case CMD_XVIEW:
  case CMD_YVIEW:
    if (argc == 2) {
      int diff;
      double first, last;
      TableGetLastCell(tablePtr, &row, &col);
      TableCellVCoords(tablePtr, row, col, &x, &y, &width, &height, 0);
      if (retval == CMD_YVIEW) {
	if (row < tablePtr->titleRows) {
	  first = 0;
	  last  = 1;
	} else {
	  diff = tablePtr->rowStarts[tablePtr->titleRows];
	  last = (double) (tablePtr->rowStarts[tablePtr->rows]-diff);
	  first = (tablePtr->rowStarts[tablePtr->topRow]-diff) / last;
	  last  = (height+tablePtr->rowStarts[row]-diff) / last;
	}
      } else {
	if (col < tablePtr->titleCols) {
	  first = 0;
	  last  = 1;
	} else {
	  diff = tablePtr->colStarts[tablePtr->titleCols];
	  last = (double) (tablePtr->colStarts[tablePtr->cols]-diff);
	  first = (tablePtr->colStarts[tablePtr->leftCol]-diff) / last;
	  last  = (width+tablePtr->colStarts[col]-diff) / last;
	}
      }
      sprintf(buf1, "%g %g", first, last);
      Tcl_SetResult(interp, buf1, TCL_VOLATILE);
    } else {
      /* cache old topleft to see if it changes */
      int oldTop = tablePtr->topRow, oldLeft = tablePtr->leftCol;
      if (argc == 3) {
	if (Tcl_GetInt(interp, argv[2], &value) != TCL_OK) {
	  result = TCL_ERROR;
	  break;
	}
	if (retval == CMD_YVIEW) {
	  tablePtr->topRow  = value + tablePtr->titleRows;
	} else {
	  tablePtr->leftCol = value + tablePtr->titleCols;
	}
      } else {
	double frac;
	sub_retval = Tk_GetScrollInfo(interp, argc, argv, &frac, &value);
	switch (sub_retval) {
	case TK_SCROLL_ERROR:
	  result = TCL_ERROR;
	  break;
	case TK_SCROLL_MOVETO:
	  if (frac < 0) frac = 0;
	  if (retval == CMD_YVIEW) {
	    tablePtr->topRow = (int)(frac*tablePtr->rows)+tablePtr->titleRows;
	  } else {
	    tablePtr->leftCol = (int)(frac*tablePtr->cols)+tablePtr->titleCols;
	  }
	  break;
	case TK_SCROLL_PAGES:
	  TableGetLastCell(tablePtr, &row, &col);
	  if (retval == CMD_YVIEW) {
	    tablePtr->topRow  += value * (row-tablePtr->topRow+1);
	  } else {
	    tablePtr->leftCol += value * (col-tablePtr->leftCol+1);
	  }
	  break;
	case TK_SCROLL_UNITS:
	  if (retval == CMD_YVIEW) {
	    tablePtr->topRow  += value;
	  } else {
	    tablePtr->leftCol += value;
	  }
	  break;
	}
      }
      /* maintain appropriate real index */
      tablePtr->topRow  = MAX(tablePtr->titleRows,
			      MIN(tablePtr->topRow, tablePtr->rows-1));
      tablePtr->leftCol = MAX(tablePtr->titleCols,
			      MIN(tablePtr->leftCol, tablePtr->cols-1));
      /* Do the table adjustment if topRow || leftCol changed */	
      if (oldTop != tablePtr->topRow || oldLeft != tablePtr->leftCol)
	TableAdjustParams(tablePtr);
    }
    break; /* XVIEW/YVIEW */
  }
  Tcl_Release(clientData);
  return result;
}

/*
 *----------------------------------------------------------------------
 *
 * TableDestroy --
 *	This procedure is invoked by Tcl_EventuallyFree
 *	to clean up the internal structure of a table at a safe time
 *	(when no-one is using it anymore).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Everything associated with the table is freed up (hopefully).
 *
 *----------------------------------------------------------------------
 */
static void
TableDestroy(ClientData clientdata)
{
  register Table *tablePtr = (Table *) clientdata;
  Tcl_HashEntry *entryPtr;
  Tcl_HashSearch search;

  /* These may be repetitive from DestroyNotify, but it doesn't hurt */
  /* cancel any pending update or timer */
  if (tablePtr->flags & REDRAW_PENDING) {
    Tcl_CancelIdleCall(TableDisplay, (ClientData) tablePtr);
    tablePtr->flags &= ~REDRAW_PENDING;
  }
  Tcl_DeleteTimerHandler(tablePtr->cursorTimer);
  Tcl_DeleteTimerHandler(tablePtr->flashTimer);

  /* delete the variable trace */
  if (tablePtr->arrayVar != NULL) {
    Tcl_UntraceVar(tablePtr->interp, tablePtr->arrayVar,
		   TCL_TRACE_WRITES | TCL_TRACE_UNSETS | TCL_GLOBAL_ONLY,
		   (Tcl_VarTraceProc *)TableVarProc, (ClientData) tablePtr);
  }

  /* delete cached activeLayout */
  if (tablePtr->activeLayout != NULL) {
    Tk_FreeTextLayout(tablePtr->activeLayout);
    tablePtr->activeLayout = NULL;
  }
  /* free the arrays with row/column pixel sizes */
  if (tablePtr->colPixels) ckfree((char *) tablePtr->colPixels);
  if (tablePtr->rowPixels) ckfree((char *) tablePtr->rowPixels);
  if (tablePtr->colStarts) ckfree((char *) tablePtr->colStarts);
  if (tablePtr->rowStarts) ckfree((char *) tablePtr->rowStarts);

  /* free the selection buffer */
  if (tablePtr->activeBuf != NULL) ckfree(tablePtr->activeBuf);

  /* delete the cache, row, column and cell style hash tables */
  Tcl_DeleteHashTable(tablePtr->cache);
  ckfree((char *) (tablePtr->cache));
  Tcl_DeleteHashTable(tablePtr->rowStyles);
  ckfree((char *) (tablePtr->rowStyles));
  Tcl_DeleteHashTable(tablePtr->colStyles);
  ckfree((char *) (tablePtr->colStyles));
  Tcl_DeleteHashTable(tablePtr->cellStyles);
  ckfree((char *) (tablePtr->cellStyles));
  Tcl_DeleteHashTable(tablePtr->flashCells);
  ckfree((char *) (tablePtr->flashCells));
  Tcl_DeleteHashTable(tablePtr->selCells);
  ckfree((char *) (tablePtr->selCells));
  Tcl_DeleteHashTable(tablePtr->colWidths);
  ckfree((char *) (tablePtr->colWidths));
  Tcl_DeleteHashTable(tablePtr->rowHeights);
  ckfree((char *) (tablePtr->rowHeights));

  /* Now free up all the tag information */
  for (entryPtr = Tcl_FirstHashEntry(tablePtr->tagTable, &search);
       entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
    TableCleanupTag(tablePtr, (TableTag *) Tcl_GetHashValue(entryPtr));
    ckfree((char *) Tcl_GetHashValue(entryPtr));
  }
  /* free up the stuff in the default tag */
  TableCleanupTag(tablePtr, &(tablePtr->defaultTag));
  /* And delete the actual hash table */
  Tcl_DeleteHashTable(tablePtr->tagTable);
  ckfree((char *) (tablePtr->tagTable));

  /* Now free up all the embedded window info */
  for (entryPtr = Tcl_FirstHashEntry(tablePtr->winTable, &search);
       entryPtr != NULL; entryPtr = Tcl_NextHashEntry(&search)) {
    EmbWinDelete(tablePtr, (TableEmbWindow *) Tcl_GetHashValue(entryPtr));
  }
  /* And delete the actual hash table */
  Tcl_DeleteHashTable(tablePtr->winTable);
  ckfree((char *) (tablePtr->winTable));

  /* free the configuration options in the widget */
  Tk_FreeOptions(TableConfig, (char *) tablePtr, tablePtr->display, 0);

  /* and free the widget memory at last! */
  ckfree((char *) (tablePtr));
}

/*
 *--------------------------------------------------------------
 *
 * TableEventProc --
 *	This procedure is invoked by the Tk dispatcher for various
 *	events on tables.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	When the window gets deleted, internal structures get
 *	cleaned up.  When it gets exposed, it is redisplayed.
 *
 *--------------------------------------------------------------
 */
static void
TableEventProc(clientData, eventPtr)
     ClientData clientData;	/* Information about window. */
     XEvent *eventPtr;		/* Information about event. */
{
  Table *tablePtr = (Table *) clientData;
  int row, col;

  switch (eventPtr->type) {

  case MotionNotify:
    if (!(tablePtr->resize & SEL_NONE) && (tablePtr->bdcursor != None) &&
	TableAtBorder(tablePtr, eventPtr->xmotion.x, eventPtr->xmotion.y,
		      &row, &col) &&
	((row>=0 && (tablePtr->resize & SEL_ROW)) ||
	 (col>=0 && (tablePtr->resize & SEL_COL)))) {
      /* The bordercursor is defined and we meet the criteria for being
       * over a border.  Set the cursor to border if not already so */
      if (!(tablePtr->flags & OVER_BORDER)) {
	tablePtr->flags |= OVER_BORDER;
	Tk_DefineCursor(tablePtr->tkwin, tablePtr->bdcursor);
      }
    } else if (tablePtr->flags & OVER_BORDER) {
      tablePtr->flags &= ~OVER_BORDER;
      if (tablePtr->cursor != None) {
	Tk_DefineCursor(tablePtr->tkwin, tablePtr->cursor);
      } else {
	Tk_UndefineCursor(tablePtr->tkwin);
      }
    }
    break;

  case Expose:
    TableInvalidate(tablePtr, eventPtr->xexpose.x, eventPtr->xexpose.y,
		    eventPtr->xexpose.width, eventPtr->xexpose.height,
		    INV_HIGHLIGHT);
    break;

  case DestroyNotify:
    /* remove the command from the interpreter */
    if (tablePtr->tkwin != NULL) {
      tablePtr->tkwin = NULL;
      Tcl_DeleteCommandFromToken(tablePtr->interp, tablePtr->widgetCmd);
    }

    /* cancel any pending update or timer */
    if (tablePtr->flags & REDRAW_PENDING) {
      Tcl_CancelIdleCall(TableDisplay, (ClientData) tablePtr);
      tablePtr->flags &= ~REDRAW_PENDING;
    }
    Tcl_DeleteTimerHandler(tablePtr->cursorTimer);
    Tcl_DeleteTimerHandler(tablePtr->flashTimer);

    Tcl_EventuallyFree((ClientData) tablePtr, (Tcl_FreeProc *) TableDestroy);
    break;

  case MapNotify: /* redraw table when remapped if it changed */
    if (tablePtr->flags & REDRAW_ON_MAP) {
      tablePtr->flags &= ~REDRAW_ON_MAP;
      Tcl_Preserve((ClientData) tablePtr);
      TableAdjustParams(tablePtr);
      TableInvalidateAll(tablePtr, INV_FORCE|INV_HIGHLIGHT);
      Tcl_Release((ClientData) tablePtr);
    }
    break;

  case ConfigureNotify:
    Tcl_Preserve((ClientData) tablePtr);
    TableAdjustParams(tablePtr);
    TableInvalidateAll(tablePtr, INV_FORCE|INV_HIGHLIGHT);
    Tcl_Release((ClientData) tablePtr);
    break;

  case FocusIn:
  case FocusOut:
    if (eventPtr->xfocus.detail != NotifyInferior) {
      tablePtr->flags |= REDRAW_BORDER;
      if (eventPtr->type == FocusOut) {
	tablePtr->flags &= ~HAS_FOCUS;
      } else {
	tablePtr->flags |= HAS_FOCUS;
      }
      TableRedrawHighlight(tablePtr);
      /* cancel the timer */
      TableConfigCursor(tablePtr);
    }
    break;
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableConfigure --
 *	This procedure is called to process an argv/argc list, plus
 *	the Tk option database, in order to configure (or reconfigure)
 *	a table widget.
 *
 * Results:
 *	The return value is a standard Tcl result.  If TCL_ERROR is
 *	returned, then interp result contains an error message.
 *
 * Side effects:
 *	Configuration information, such as colors, border width, etc.
 *	get set for tablePtr; old resources get freed, if there were any.
 *	Certain values might be constrained.
 *
 *----------------------------------------------------------------------
 */
static int
TableConfigure(interp, tablePtr, argc, argv, flags, forceUpdate)
    Tcl_Interp *interp;		/* Used for error reporting. */
    register Table *tablePtr;	/* Information about widget;  may or may
				 * not already have values for some fields. */
    int argc;			/* Number of valid entries in argv. */
    char **argv;		/* Arguments. */
    int flags;			/* Flags to pass to Tk_ConfigureWidget. */
    int forceUpdate;		/* Whether to force an update - required
				 * for initial configuration */
{
  Tcl_HashSearch search;
  int oldUse, oldCaching, oldExport, result = TCL_OK;
  char *oldVar;
  Tcl_DString error;
  Tk_FontMetrics fm;

  oldExport	= tablePtr->exportSelection;
  oldCaching	= tablePtr->caching;
  oldUse	= tablePtr->useCmd;
  oldVar	= tablePtr->arrayVar;

  /* Do the configuration */
  if (Tk_ConfigureWidget(interp, tablePtr->tkwin, TableConfig, argc, argv,
			 (char *) tablePtr, flags) != TCL_OK)
    return TCL_ERROR;

  Tcl_DStringInit(&error);

  /* Any time we configure, reevaluate what our data source is */
  tablePtr->dataSource = DATA_NONE;
  if (tablePtr->caching) {
    tablePtr->dataSource |= DATA_CACHE;
  }
  if (tablePtr->command && tablePtr->useCmd) {
    tablePtr->dataSource |= DATA_COMMAND;
  } else if (tablePtr->arrayVar) {
    tablePtr->dataSource |= DATA_ARRAY;
  }

  /* Check to see if the array variable was changed */
  if (strcmp((tablePtr->arrayVar?tablePtr->arrayVar:""),(oldVar?oldVar:""))) {
    /* only do the following if arrayVar is our data source */
    if (tablePtr->dataSource & DATA_ARRAY) {
      /* ensure that the cache will flush later so it gets the new values */
      oldCaching = !(tablePtr->caching);
    }
    /* remove the trace on the old array variable if there was one */
    if (oldVar != NULL)
      Tcl_UntraceVar(interp, oldVar,
		     TCL_TRACE_WRITES | TCL_TRACE_UNSETS | TCL_GLOBAL_ONLY,
		     (Tcl_VarTraceProc *)TableVarProc, (ClientData)tablePtr);
    /* Check whether variable is an array and trace it if it is */
    if (tablePtr->arrayVar != NULL) {
      /* does the variable exist as an array? */
      if (Tcl_SetVar2(interp, tablePtr->arrayVar, TEST_KEY, "",
		      TCL_GLOBAL_ONLY) == NULL) {
	Tcl_DStringAppend(&error, "invalid variable value \"", -1);
	Tcl_DStringAppend(&error, tablePtr->arrayVar, -1);
	Tcl_DStringAppend(&error, "\": could not be made an array", -1);
	ckfree(tablePtr->arrayVar);
	tablePtr->arrayVar = NULL;
	tablePtr->dataSource &= ~DATA_ARRAY;
	result = TCL_ERROR;
      } else {
	Tcl_UnsetVar2(interp, tablePtr->arrayVar, TEST_KEY, TCL_GLOBAL_ONLY);
	/* remove the effect of the evaluation */
	/* set a trace on the variable */
	Tcl_TraceVar(interp, tablePtr->arrayVar,
		     TCL_TRACE_WRITES | TCL_TRACE_UNSETS | TCL_GLOBAL_ONLY,
		     (Tcl_VarTraceProc *)TableVarProc, (ClientData) tablePtr);

	/* only do the following if arrayVar is our data source */
	if (tablePtr->dataSource & DATA_ARRAY) {
	  /* get the current value of the selection */
	  TableGetActiveBuf(tablePtr);
	}
      }
    }
  }
  if ((tablePtr->command && tablePtr->useCmd && !oldUse) ||
      (tablePtr->arrayVar && !(tablePtr->useCmd) && oldUse)) {
    /* our effective data source changed, so flush and
     * retrieve new active buffer */
    TableFlushCache(tablePtr);
    TableGetActiveBuf(tablePtr);
    forceUpdate = 1;
  } else if (oldCaching != tablePtr->caching) {
    /* caching changed, so just clear the cache for safety */
    TableFlushCache(tablePtr);
    forceUpdate = 1;
  }

  /* set up the default column width and row height */
  Tk_GetFontMetrics(tablePtr->defaultTag.tkfont, &fm);
  tablePtr->charWidth = Tk_TextWidth(tablePtr->defaultTag.tkfont, "0", 1);
  tablePtr->charHeight = fm.linespace + 2;

  if (tablePtr->insertWidth <= 0) {
    tablePtr->insertWidth = 2;
  }
  if (tablePtr->insertBorderWidth > tablePtr->insertWidth/2) {
    tablePtr->insertBorderWidth = tablePtr->insertWidth/2;
  }
  tablePtr->highlightWidth = MAX(0,tablePtr->highlightWidth);
  /* the border must be >= 0 */
  tablePtr->borderWidth = MAX(0,tablePtr->borderWidth);
  /* when drawing fast or single, the border must be <= 1 */
  if (tablePtr->drawMode & (DRAW_MODE_SINGLE|DRAW_MODE_FAST)) {
    tablePtr->borderWidth = MIN(1,tablePtr->borderWidth);
  }

  /* Ensure that certain values are within proper constraints */
  tablePtr->rows = MAX(1,tablePtr->rows);
  tablePtr->cols = MAX(1,tablePtr->cols);
  tablePtr->titleRows = MIN(MAX(0,tablePtr->titleRows),tablePtr->rows);
  tablePtr->titleCols = MIN(MAX(0,tablePtr->titleCols),tablePtr->cols);
  tablePtr->padX = MAX(0,tablePtr->padX);
  tablePtr->padY = MAX(0,tablePtr->padY);
  tablePtr->maxReqCols = MAX(0,tablePtr->maxReqCols);
  tablePtr->maxReqRows = MAX(0,tablePtr->maxReqRows);

  /*
   * Claim the selection if we've suddenly started exporting it and
   * there is a selection to export.
   */
  if (tablePtr->exportSelection && !oldExport &&
      (Tcl_FirstHashEntry(tablePtr->selCells, &search) != NULL)) {
    Tk_OwnSelection(tablePtr->tkwin, XA_PRIMARY, TableLostSelection,
		    (ClientData) tablePtr);
  }

  /* only do the full reconfigure if absolutely necessary */
  if (!forceUpdate) {
    int i;
    for (i = 0; i < argc-1; i += 2) {
      if (Cmd_GetValue(update_config, argv[i])) {
	forceUpdate = 1;
	break;
      }
    }
  }
  if (forceUpdate) {
    /* 
     * Calculate the row and column starts 
     * Adjust the top left corner of the internal display 
     */
    TableAdjustParams(tablePtr);
    /* reset the cursor */
    TableConfigCursor(tablePtr);
    /* set up the background colour in the window */
    Tk_SetBackgroundFromBorder(tablePtr->tkwin, tablePtr->defaultTag.bg);
    /* set the geometry and border */
    TableGeometryRequest(tablePtr);
    Tk_SetInternalBorder(tablePtr->tkwin, tablePtr->highlightWidth);
    /* invalidate the whole table */
    TableInvalidateAll(tablePtr, INV_HIGHLIGHT);
  }
  /* FIX this is goofy because the result could be munged by other
   * functions.  Needs to be improved */
  Tcl_ResetResult(interp);
  if (result == TCL_ERROR) {
    Tcl_AddErrorInfo(interp, "\t(configuring table widget)");
    Tcl_DStringResult(interp, &error);
  }
  Tcl_DStringFree(&error);
  return result;
}

#ifndef CLASSPATCH
/*
 * As long as we wait for the Function in general
 *
 * This parses the "-class" option for the table.
 */
static void
Tk_ClassOption(Tk_Window tkwin, char *defaultclass, int *argcp, char ***argvp)
{
  char *classname = (((*argcp)<3) || (strcmp((*argvp)[2],"-class"))) ?
    defaultclass : ((*argcp)-=2,(*argcp)+=2,(*argvp)[1]);
  Tk_SetClass(tkwin,classname);
}
#endif

/*
 *----------------------------------------------------------------------
 *
 * TableCmdDeletedProc --
 *
 *	This procedure is invoked when a widget command is deleted.  If
 *	the widget isn't already in the process of being destroyed,
 *	this command destroys it.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The widget is destroyed.
 *
 *----------------------------------------------------------------------
 */
static void
TableCmdDeletedProc(ClientData clientData)
{
  Table *tablePtr = (Table *) clientData;
  Tk_Window tkwin;

  /*
   * This procedure could be invoked either because the window was
   * destroyed and the command was then deleted (in which case tkwin
   * is NULL) or because the command was deleted, and then this procedure
   * destroys the widget.
   */

  /* This is needed to avoid bug where the DLL is unloaded before
   * the table is properly destroyed */
  Tcl_DeleteExitHandler((Tcl_ExitProc *) TableCmdDeletedProc,
			(ClientData) tablePtr);
  if (tablePtr->tkwin != NULL) {
    tkwin = tablePtr->tkwin;
    tablePtr->tkwin = NULL;
    Tk_DestroyWindow(tkwin);
  }
}

/*
 *--------------------------------------------------------------
 *
 * TableCmd --
 *	This procedure is invoked to process the "table" Tcl
 *	command.  See the user documentation for details on what
 *	it does.
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side effects:
 *	See the user documentation.
 *
 *--------------------------------------------------------------
 */
static int
TableCmd(clientData, interp, argc, argv)
     ClientData clientData;	/* Main window associated with
				 * interpreter. */
     Tcl_Interp *interp;	/* Current interpreter. */
     int argc;			/* Number of arguments. */
     char **argv;		/* Argument strings. */
{
  register Table *tablePtr;
  Tk_Window tkwin = (Tk_Window) clientData;
  Tk_Window new;

  if (argc < 2) {
    Tcl_AppendResult(interp, "wrong # args: should be \"",
		     argv[0], " pathname ?options?\"", (char *) NULL);
    return TCL_ERROR;
  }

  new = Tk_CreateWindowFromPath(interp, tkwin, argv[1], (char *) NULL);
  if (new == NULL) {
    return TCL_ERROR;
  }

  tablePtr			= (Table *) ckalloc(sizeof(Table));
  tablePtr->tkwin		= new;
  tablePtr->display		= Tk_Display(new);
  tablePtr->interp		= interp;

  tablePtr->topRow		= 0;
  tablePtr->leftCol		= 0;
  tablePtr->anchorRow		= -1;
  tablePtr->anchorCol		= -1;
  tablePtr->activeRow		= -1;
  tablePtr->activeCol		= -1;
  tablePtr->oldTopRow		= -1;
  tablePtr->oldLeftCol		= -1;
  tablePtr->oldActRow		= -1;
  tablePtr->oldActCol		= -1;
  tablePtr->seen[0]		= -1;
  tablePtr->icursor		= 0;
  tablePtr->flags		= 0;

  tablePtr->colPixels		= (int *) 0;
  tablePtr->rowPixels		= (int *) 0;
  tablePtr->colStarts		= (int *) 0;
  tablePtr->rowStarts		= (int *) 0;
  tablePtr->cursorTimer		= (Tcl_TimerToken)0;
  tablePtr->flashTimer		= (Tcl_TimerToken)0;
  tablePtr->dataSource		= DATA_NONE;
  tablePtr->activeBuf		= ckalloc(1);
  *(tablePtr->activeBuf)	= '\0';
  tablePtr->activeLayout	= NULL;

  /* misc tables */
  tablePtr->tagTable	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->tagTable, TCL_STRING_KEYS);
  tablePtr->winTable	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->winTable, TCL_STRING_KEYS);

  /* internal value cache */
  tablePtr->cache	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->cache, TCL_STRING_KEYS);

  /* style hash tables */
  tablePtr->colWidths	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->colWidths, TCL_ONE_WORD_KEYS);
  tablePtr->rowHeights	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->rowHeights, TCL_ONE_WORD_KEYS);

  /* style hash tables */
  tablePtr->rowStyles	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->rowStyles, TCL_ONE_WORD_KEYS);
  tablePtr->colStyles	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->colStyles, TCL_ONE_WORD_KEYS);
  tablePtr->cellStyles	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->cellStyles, TCL_STRING_KEYS);

  /* special style hash tables */
  tablePtr->flashCells	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->flashCells, TCL_STRING_KEYS);
  tablePtr->selCells	= (Tcl_HashTable *) ckalloc(sizeof(Tcl_HashTable));
  Tcl_InitHashTable(tablePtr->selCells, TCL_STRING_KEYS);

  tablePtr->rows		= 0;
  tablePtr->cols		= 0;
  tablePtr->selectMode		= NULL;
  tablePtr->selectTitles	= 0;
  tablePtr->defRowHeight	= 0;
  tablePtr->defColWidth		= 0;
  tablePtr->arrayVar		= NULL;
  tablePtr->borderWidth		= 0;
  tablePtr->defaultTag.anchor	= TK_ANCHOR_CENTER;
  tablePtr->defaultTag.bg	= NULL;
  tablePtr->defaultTag.fg	= NULL;
  tablePtr->defaultTag.tkfont	= NULL;
  tablePtr->defaultTag.image	= NULL;
  tablePtr->defaultTag.imageStr	= NULL;
  tablePtr->defaultTag.justify	= TK_JUSTIFY_LEFT;
  tablePtr->defaultTag.multiline	= 1;
  tablePtr->defaultTag.relief	= TK_RELIEF_FLAT;
  tablePtr->defaultTag.showtext	= 0;
  tablePtr->defaultTag.state	= STATE_UNKNOWN;
  tablePtr->defaultTag.wrap	= 0;
  tablePtr->yScrollCmd		= NULL;
  tablePtr->xScrollCmd		= NULL;
  tablePtr->insertBg		= NULL;
  tablePtr->cursor		= None;
  tablePtr->bdcursor		= None;
  tablePtr->titleRows		= 0;
  tablePtr->titleCols		= 0;
  tablePtr->drawMode		= DRAW_MODE_TK_COMPAT;
  tablePtr->colStretch		= STRETCH_MODE_NONE;
  tablePtr->rowStretch		= STRETCH_MODE_NONE;
  tablePtr->maxWidth		= 0;
  tablePtr->maxHeight		= 0;
  tablePtr->charWidth		= 0;
  tablePtr->charHeight		= 0;
  tablePtr->colOffset		= 0;
  tablePtr->rowOffset		= 0;
  tablePtr->flashTime		= 2;
  tablePtr->rowTagCmd		= NULL;
  tablePtr->colTagCmd		= NULL;
  tablePtr->highlightWidth	= 0;
  tablePtr->highlightBgColorPtr	= NULL;
  tablePtr->highlightColorPtr	= NULL;
  tablePtr->takeFocus		= NULL;
  tablePtr->state		= STATE_NORMAL;
  tablePtr->insertWidth		= 0;
  tablePtr->insertBorderWidth	= 0;
  tablePtr->insertOnTime	= 0;
  tablePtr->insertOffTime	= 0;
  tablePtr->invertSelected	= 0;
  tablePtr->autoClear		= 0;
  tablePtr->flashMode		= 0;
  tablePtr->exportSelection	= 1;
  tablePtr->rowSep		= NULL;
  tablePtr->colSep		= NULL;
  tablePtr->browseCmd		= NULL;
  tablePtr->command		= NULL;
  tablePtr->selCmd		= NULL;
  tablePtr->valCmd		= NULL;
  tablePtr->validate		= 0;
  tablePtr->useCmd		= 1;
  tablePtr->caching		= 0;
  tablePtr->padX		= 0;
  tablePtr->padY		= 0;
  tablePtr->maxReqCols		= 0;
  tablePtr->maxReqRows		= 0;
  tablePtr->maxReqWidth		= 800;
  tablePtr->maxReqHeight	= 600;

  /* selection handlers needed here */

  Tk_ClassOption(new, "Table", &argc, &argv);
  Tk_CreateEventHandler(tablePtr->tkwin,
			PointerMotionMask|ExposureMask|StructureNotifyMask|FocusChangeMask|VisibilityChangeMask,
			TableEventProc, (ClientData) tablePtr);
  Tk_CreateSelHandler(tablePtr->tkwin, XA_PRIMARY, XA_STRING,
		      TableFetchSelection, (ClientData) tablePtr, XA_STRING);

  tablePtr->widgetCmd = Tcl_CreateCommand(interp, Tk_PathName(tablePtr->tkwin),
			TableWidgetCmd, (ClientData) tablePtr,
			(Tcl_CmdDeleteProc *) TableCmdDeletedProc);
  if (TableConfigure(interp, tablePtr, argc - 2, argv + 2, 0, 1) != TCL_OK) {
    Tk_DestroyWindow(new);
    return TCL_ERROR;
  }
  TableInitTags(tablePtr);
  /* This is needed to avoid bug where the DLL is unloaded before
   * the table is properly destroyed */
  Tcl_CreateExitHandler((Tcl_ExitProc *) TableCmdDeletedProc,
			(ClientData) tablePtr);
  Tcl_SetResult(interp, Tk_PathName(tablePtr->tkwin), TCL_STATIC);
  return TCL_OK;
}

/* Function to call on loading the Table module */

EXPORT(int,Tktable_Init)(interp)
    Tcl_Interp *interp;
{
  static char init_script[] =
    "if {[catch {source \"" TCL_RUNTIME "\"}]} {\n"
#include "tkTabletcl.h"
    "}\n";
  if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, 0) == NULL ||
      Tcl_PkgRequire(interp, "Tk", TK_VERSION, 0) == NULL ||
      Tcl_PkgProvide(interp, "Tktable", TBL_VERSION) != TCL_OK) {
    return TCL_ERROR;
  }
  Tcl_CreateCommand(interp, TBL_COMMAND, TableCmd,
		    (ClientData) Tk_MainWindow(interp),
		    (Tcl_CmdDeleteProc *) NULL);

  return Tcl_Eval(interp, init_script);
}

EXPORT(int,Tktable_SafeInit)(interp)
    Tcl_Interp *interp;
{
  return Tktable_Init(interp);
}

#ifdef _WIN32
/*
 *----------------------------------------------------------------------
 *
 * DllEntryPoint --
 *
 *	This wrapper function is used by Windows to invoke the
 *	initialization code for the DLL.  If we are compiling
 *	with Visual C++, this routine will be renamed to DllMain.
 *	routine.
 *
 * Results:
 *	Returns TRUE;
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

BOOL APIENTRY
DllEntryPoint(hInst, reason, reserved)
    HINSTANCE hInst;		/* Library instance handle. */
    DWORD reason;		/* Reason this function is being called. */
    LPVOID reserved;		/* Not used. */
{
  return TRUE;
}
#endif
