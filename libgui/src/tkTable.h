/* 
 * tkTable.h --
 *
 *	This is the header file for the module that implements
 *	table widgets for the Tk toolkit.
 *
 * Copyright (c) 1997,1998 Jeffrey Hobbs
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 */

#ifndef _TKTABLE_H_
#define _TKTABLE_H_

#include <string.h>
#include <stdlib.h>
#include <tk.h>
#include <X11/Xatom.h>

#include "tkTableCmd.h"

#ifdef _WIN32
#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>
#   undef WIN32_LEAN_AND_MEAN

/*
 * VC++ has an alternate entry point called DllMain, so we need to rename
 * our entry point.
 */

#   if defined(_MSC_VER)
#	define EXPORT(a,b) __declspec(dllexport) a b
#	define DllEntryPoint DllMain
#   else
#	if defined(__BORLANDC__)
#	    define EXPORT(a,b) a _export b
#	else
#	    define EXPORT(a,b) a b
#	endif
#   endif

/* Necessary to get XSync call defined */
#   include <tkInt.h>

#else	/* ! WIN32 */
#   define EXPORT(a,b) a b
#endif	/* WIN32 */

#ifdef INLINE
#undef INLINE
#endif
#ifdef __GNUC__
#    define INLINE inline
#else
#    if defined(_MSC_VER)
#	define INLINE __inline
#    else
#	define INLINE
#    endif
#endif

#ifndef NORMAL_BG
#	ifdef _WIN32
#		define NORMAL_BG	"SystemButtonFace"
#		define ACTIVE_BG	NORMAL_BG
#		define SELECT_BG	"SystemHighlight"
#		define DISABLED		"SystemDisabledText"
#		define HIGHLIGHT	"SystemWindowFrame"
#		define DEF_TABLE_FONT	"{MS Sans Serif} 8"
#	else
#		define NORMAL_BG	"#d9d9d9"
#		define ACTIVE_BG	"#fcfcfc"
#		define SELECT_BG	"#c3c3c3"
#		define DISABLED		"#a3a3a3"
#		define HIGHLIGHT	"Black"
#		define DEF_TABLE_FONT	"Helvetica -12"
#	endif
#endif

#define MAX(A,B)	(((A)>(B))?(A):(B))
#define MIN(A,B)	(((A)>(B))?(B):(A))
#define ARSIZE(A)	(sizeof(A)/sizeof(*A))
#define INDEX_BUFSIZE	64		/* max size of buffer for indices */
#define TEST_KEY	"#TEST KEY#"	/* index for testing array existence */

/*
 * Assigned bits of "flags" fields of Table structures, and what those
 * bits mean:
 *
 * REDRAW_PENDING:	Non-zero means a DoWhenIdle handler has
 *			already been queued to redisplay the table.
 * REDRAW_BORDER:	Non-zero means 3-D border must be redrawn
 *			around window during redisplay.	 Normally
 *			only text portion needs to be redrawn.
 * CURSOR_ON:		Non-zero means insert cursor is displayed at
 *			present.  0 means it isn't displayed.
 * TEXT_CHANGED:	Non-zero means the active cell text is being edited.
 * HAS_FOCUS:		Non-zero means this window has the input focus.
 * HAS_ACTIVE:		Non-zero means the active cell is set.
 * HAS_ANCHOR:		Non-zero means the anchor cell is set.
 * BROWSE_CMD:		Non-zero means we're evaluating the -browsecommand.
 * VALIDATING:		Non-zero means we are in a valCmd
 * SET_ACTIVE:		About to set the active array element internally
 * ACTIVE_DISABLED:	Non-zero means the active cell is -state disabled
 * OVER_BORDER:		Non-zero means we are over a table cell border
 * REDRAW_ON_MAP:	Forces a redraw on the unmap
 *
 * FIX - consider adding UPDATE_SCROLLBAR a la entry
 */
#define REDRAW_PENDING		(1L<<0)
#define CURSOR_ON		(1L<<1)
#define	HAS_FOCUS		(1L<<2)
#define TEXT_CHANGED		(1L<<3)
#define HAS_ACTIVE		(1L<<4)
#define HAS_ANCHOR		(1L<<5)
#define BROWSE_CMD		(1L<<6)
#define REDRAW_BORDER		(1L<<7)
#define VALIDATING		(1L<<8)
#define SET_ACTIVE		(1L<<9)
#define ACTIVE_DISABLED		(1L<<10)
#define OVER_BORDER		(1L<<11)
#define REDRAW_ON_MAP		(1L<<12)

/* Flags for TableInvalidate && TableRedraw */
#define ROW		(1L<<0)
#define COL		(1L<<1)
#define CELL		(ROW|COL)
#define INV_FILL	(1L<<3)	/* use for Redraw when the affected
				 * row/col will affect neighbors */
#define INV_FORCE	(1L<<4)
#define INV_HIGHLIGHT	(1L<<5)

/*
 * Definitions for tablePtr->dataSource, by bit
 */
#define DATA_NONE	0
#define DATA_CACHE	(1<<1)
#define	DATA_ARRAY	(1<<2)
#define DATA_COMMAND	(1<<3)

typedef enum {
  STATE_UNUSED, STATE_UNKNOWN, STATE_HIDDEN,
  STATE_NORMAL, STATE_DISABLED, STATE_ACTIVE,
  STATE_LAST
} TableState;

/* The tag structure */
typedef struct {
  Tk_3DBorder	bg;		/* background color */
  Tk_3DBorder	fg;		/* foreground color */
  int		relief;		/* relief type */
  Tk_Font	tkfont;		/* Information about text font, or NULL. */
  Tk_Anchor	anchor;		/* default anchor point */
  char *	imageStr;	/* name of image */
  Tk_Image	image;		/* actual pointer to image, if any */
  TableState	state;		/* state of the cell */
  Tk_Justify	justify;	/* justification of text in the cell */
  int		multiline;	/* wrapping style of multiline text */
  int		wrap;		/* wrapping style of multiline text */
  int		showtext;	/* whether to display text over image */
} TableTag;

/*  The widget structure for the table Widget */

typedef struct {
  /* basic information about the window and the interpreter */
  Tk_Window tkwin;
  Display *display;
  Tcl_Interp *interp;
  Tcl_Command widgetCmd;	/* Token for entry's widget command. */
  /* Configurable Options */
  int autoClear;
  char *selectMode;		/* single, browse, multiple, or extended */
  int selectType;		/* row, col, both, or cell */
  int selectTitles;		/* whether to do automatic title selection */
  int rows, cols;		/* number of rows and columns */
  int defRowHeight;		/* default row height in chars (positive)
				 * or pixels (negative) */
  int defColWidth;		/* default column width in chars (positive)
				 * or pixels (negative) */
  int maxReqCols;		/* the requested # cols to display */
  int maxReqRows;		/* the requested # rows to display */
  int maxReqWidth;		/* the maximum requested width in pixels */
  int maxReqHeight;		/* the maximum requested height in pixels */
  char *arrayVar;		/* name of traced array variable */
  char *rowSep;			/* separator string to place between
				 * rows when getting selection */
  char *colSep;			/* separator string to place between
				 * cols when getting selection */
  int borderWidth;		/* internal borderwidth */
  TableTag defaultTag;		/* the default tag colors/fonts etc */
  char *yScrollCmd;		/* the y-scroll command */
  char *xScrollCmd;		/* the x-scroll command */
  char *browseCmd;		/* the command that is called when the
				 * active cell changes */
  int caching;			/* whether to cache values of table */
  char *command;		/* A command to eval when get/set occurs
				 * for table values */
  int useCmd;			/* Signals whether to use command or the
				 * array variable, will be 0 if command errs */
  char *selCmd;			/* the command that is called to when a
				 * [selection get] call occurs for a table */
  char *valCmd;			/* Command prefix to use when invoking
				 * validate command.  NULL means don't
				 * invoke commands.  Malloc'ed. */
  int validate;			/* Non-zero means try to validate */
  Tk_3DBorder insertBg;		/* the cursor color */
  Tk_Cursor cursor;		/* the regular mouse pointer */
  Tk_Cursor bdcursor;		/* the mouse pointer when over borders */
  int exportSelection;		/* Non-zero means tie internal table
				 * to X selection. */
  TableState state;		/* Normal or disabled.  Table is read-only
				 * when disabled. */
  int insertWidth;		/* Total width of insert cursor. */
  int insertBorderWidth;	/* Width of 3-D border around insert cursor. */
  int insertOnTime;		/* Number of milliseconds cursor should spend
				 * in "on" state for each blink. */
  int insertOffTime;		/* Number of milliseconds cursor should spend
				 * in "off" state for each blink. */
  int invertSelected;           /* Whether to draw selected cells swapping
                                   foreground and background */
  int colStretch;		/* The way to stretch columns if the window
				   is too large */
  int rowStretch;		/* The way to stretch rows if the window is
				   too large */
  int colOffset;		/* X index of leftmost col in the display */
  int rowOffset;		/* Y index of topmost row in the display */
  int drawMode;			/* The mode to use when redrawing */
  int flashMode;		/* Specifies whether flashing is enabled */
  int flashTime;		/* The number of ms to flash a cell for */
  int resize;			/* -resizeborders option for interactive
				 * resizing of borders */
  char *rowTagCmd, *colTagCmd;	/* script to eval for getting row/tag cmd */
  int highlightWidth;		/* Width in pixels of highlight to draw
				 * around widget when it has the focus.
				 * <= 0 means don't draw a highlight. */
  XColor *highlightBgColorPtr;	/* Color for drawing traversal highlight
				 * area when highlight is off. */
  XColor *highlightColorPtr;	/* Color for drawing traversal highlight. */
  char *takeFocus;		/* Used only in Tcl to check if this
				 * widget will accept focus */
  int padX, padY;		/* Extra space around text (pixels to leave
				 * on each side).  Ignored for bitmaps and
				 * images. */

  /* Cached Information */
  int titleRows, titleCols;	/* the number of rows|cols to use as a title */
  /* these are kept in real coords */
  int topRow, leftCol;		/* The topleft cell to display excluding the
				 * fixed title rows.  This is just the
				 * config request.  The actual cell used may
				 * be different to keep the screen full */
  int anchorRow, anchorCol;	/* the row,col of the anchor cell */
  int activeRow, activeCol;	/* the row,col of the active cell */
  int oldTopRow, oldLeftCol;	/* cached by TableAdjustParams */
  int oldActRow, oldActCol;	/* cached by TableAdjustParams */
  int icursor;			/* The index of the insertion cursor in the
				   active cell */
  int flags;			/* An or'ed combination of flags concerning
				   redraw/cursor etc. */
  int dataSource;		/* where our data comes from:
				 * DATA_{NONE,CACHE,ARRAY,COMMAND} */
  int maxWidth, maxHeight;	/* max width|height required in pixels */
  int charWidth, charHeight;	/* size of a character in the default font */
  int *colPixels;		/* Array of the pixel width of each column */
  int *rowPixels;		/* Array of the pixel height of each row */
  int *colStarts, *rowStarts;	/* Array of start pixels for rows|columns */
  int scanMarkX, scanMarkY;	/* Used by "scan" and "border" to mark */
  int scanMarkRow, scanMarkCol;	/* necessary information for dragto */
  /* values in these are kept in user coords */
  Tcl_HashTable *cache;		/* value cache */
  /* colWidths and rowHeights are indexed from 0, so always adjust numbers
     by the appropriate *Offset factor */
  Tcl_HashTable *colWidths;	/* hash table of non default column widths */
  Tcl_HashTable *rowHeights;	/* hash table of non default row heights */
  Tcl_HashTable *tagTable;	/* table for style tags */
  Tcl_HashTable *winTable;	/* table for embedded windows */
  Tcl_HashTable *rowStyles;	/* table for row styles */
  Tcl_HashTable *colStyles;	/* table for col styles */
  Tcl_HashTable *cellStyles;	/* table for cell styles */
  Tcl_HashTable *flashCells;	/* table of flashing cells */
  Tcl_HashTable *selCells;	/* table of selected cells */
  Tcl_TimerToken cursorTimer;	/* timer token for the cursor blinking */
  Tcl_TimerToken flashTimer;	/* timer token for the cell flashing */
  char *activeBuf;		/* buffer where the selection is kept
				   for editing the active cell */
  Tk_TextLayout activeLayout;	/* cache of active layout */
  int activeX, activeY;		/* cache offset of active layout in cell */
  /* The invalid rectangle if there is an update pending */
  int invalidX, invalidY, invalidWidth, invalidHeight;
  int seen[4];			/* see TableUndisplay */
} Table;

/*
 * HEADERS FOR EMBEDDED WINDOWS
 */

/*
 * A structure of the following type holds information for each window
 * embedded in a table widget.
 */

typedef struct TableEmbWindow {
  Table *tablePtr;		/* Information about the overall table
				 * widget. */
  Tk_Window tkwin;		/* Window for this segment.  NULL
				 * means that the window hasn't
				 * been created yet. */
  Tcl_HashEntry *hPtr;		/* entry into winTable */
  Tk_3DBorder bg;		/* background color */
  char *create;			/* Script to create window on-demand.
				 * NULL means no such script.
				 * Malloc-ed. */
  int relief;			/* relief type */
  int sticky;			/* How to align window in space */
  int padX, padY;		/* Padding to leave around each side
				 * of window, in pixels. */
  int displayed;		/* Non-zero means that the window
				 * has been displayed on the screen
				 * recently. */
} TableEmbWindow;

extern void	EmbWinDisplay _ANSI_ARGS_((Table *tablePtr, Drawable window,
					   TableEmbWindow *ewPtr,
					   TableTag *tagPtr, int x, int y,
					   int width, int height));
extern void	EmbWinUnmap _ANSI_ARGS_((register Table *tablePtr,
					 int rlo, int rhi,
					 int clo, int chi));
extern void	EmbWinDelete _ANSI_ARGS_((register Table *tablePtr,
					   TableEmbWindow *ewPtr));
extern int	TableWindowCmd _ANSI_ARGS_((Table *tablePtr,
					    Tcl_Interp *interp,
					    int argc, char *argv[]));

/*
 * HEADERS IN TKTABLETAG
 */

extern TableTag *TableNewTag _ANSI_ARGS_((void));
extern void	TableMergeTag _ANSI_ARGS_((TableTag *baseTag,
					   TableTag *addTag));
extern void	TableInvertTag _ANSI_ARGS_((TableTag *baseTag));
extern void	TableInitTags _ANSI_ARGS_((Table *tablePtr));
extern TableTag *FindRowColTag _ANSI_ARGS_((Table *tablePtr,
					     int cell, int type));
extern void	TableCleanupTag _ANSI_ARGS_((Table *tablePtr,
					     TableTag *tagPtr));
extern int	TableTagCmd _ANSI_ARGS_((Table *tablePtr, Tcl_Interp *interp,
					 int argc, char *argv[]));

/*
 * HEADERS IN TKTABLECELL
 */

extern void	TableCellCoords _ANSI_ARGS_((Table *tablePtr, int row,
					     int col, int *rx, int *ry,
					     int *rw, int *rh));
extern int	TableCellVCoords _ANSI_ARGS_((Table *tablePtr, int row,
					      int col, int *rx, int *ry,
					      int *rw, int *rh, int full));
extern void	TableWhatCell _ANSI_ARGS_((register Table *tablePtr,
					   int x, int y, int *row, int *col));
extern int	TableAtBorder _ANSI_ARGS_((Table *tablePtr, int x, int y,
					   int *row, int *col));
extern char *	TableGetCellValue _ANSI_ARGS_((Table *tablePtr, int r, int c));
extern int	TableSetCellValue _ANSI_ARGS_((Table *tablePtr, int r, int c,
					       char *value));
extern char *	TableCellSort _ANSI_ARGS_((Table *tablePtr, char *str));
extern int	TableGetIcursor _ANSI_ARGS_((Table *tablePtr, char *arg,
					     int *posn));
extern int	TableGetIndex _ANSI_ARGS_((register Table *tablePtr, char *str,
					   int *row_p, int *col_p));

/*
 * HEADERS IN TKTABLE
 */

EXTERN EXPORT(int,Example_Init) _ANSI_ARGS_((Tcl_Interp *interp));

extern void	ExpandPercents _ANSI_ARGS_((Table *tablePtr, char *before,
			int r, int c, char *old, char *new, int index,
			Tcl_DString *dsPtr, int cmdType));
extern void	TableInvalidate _ANSI_ARGS_((Table *tablePtr, int x, int y,
					     int width, int height,
					     int force));
extern void	TableRefresh _ANSI_ARGS_((register Table *tablePtr,
					  int arg1, int arg2, int mode));

#define TableInvalidateAll(tablePtr, flags)	\
	TableInvalidate((tablePtr), 0, 0, Tk_Width((tablePtr)->tkwin),\
			Tk_Height((tablePtr)->tkwin), (flags))

     /*
      * Turn row/col into an index into the table
      */
#define TableMakeArrayIndex(r, c, i)	sprintf((i), "%d,%d", (r), (c))

     /*
      * Turn array index back into row/col
      * return the number of args parsed (should be two)
      */
#define TableParseArrayIndex(r, c, i)	sscanf((i), "%d,%d", (r), (c))

     /*
      * Macro for finding the last cell of the table
      */
#define TableGetLastCell(tablePtr, rowPtr, colPtr)	\
	TableWhatCell((tablePtr),\
		      Tk_Width((tablePtr)->tkwin)-(tablePtr)->highlightWidth,\
		      Tk_Height((tablePtr)->tkwin)-(tablePtr)->highlightWidth,\
		      (rowPtr), (colPtr))

#endif /* _TKTABLE_H_ */

