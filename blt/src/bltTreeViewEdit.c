/*
 * bltTreeViewEdit.c --
 *
 *	This module implements an hierarchy widget for the BLT toolkit.
 *
 * Copyright 1998-1999 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies or any of their entities not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * Lucent Technologies disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Lucent Technologies be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in
 * an action of contract, negligence or other tortuous action, arising
 * out of or in connection with the use or performance of this
 * software.
 *
 *	The "treeview" widget was created by George A. Howlett.
 */

#include "bltInt.h"

#ifndef NO_TREEVIEW

#include "bltTreeView.h"
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#define EDITOR_FOCUS	(1<<0)
#define EDITOR_REDRAW	(1<<1)

static Tcl_IdleProc DisplayTreeViewEditor;
static Tcl_FreeProc DestroyTreeViewEditor;
static Tcl_TimerProc BlinkCursorProc;

/*
 * TreeViewEditor --
 *
 *	This structure is shared by entries when their labels are
 *	edited via the keyboard.  It maintains the location of the
 *	insertion cursor and the text selection for the editted entry.
 *	The structure is shared since we need only one.  The "focus"
 *	entry should be the only entry receiving KeyPress/KeyRelease
 *	events at any time.  Information from the previously editted
 *	entry is overwritten.
 *
 *	Note that all the indices internally are in terms of bytes,
 *	not characters.  This is because UTF-8 strings may encode a
 *	single character into a multi-byte sequence.  To find the
 *	respective character position
 *
 *		n = Tcl_NumUtfChars(string, index);
 *
 *	where n is the resulting character number.
 */
struct TreeViewEditorStruct {
    unsigned int flags;
    Display *display;
    Tk_Window tkwin;		/* Window representing the editing frame. */
    int x, y;			/* Position of window. */
    int width, height;		/* Dimensions of editor window. */

    int active;			/* Indicates that the frame is active. */
    int exportSelection;

    int insertPos;		/* Position of the cursor within the
				 * array of bytes of the entry's label. */

    Tk_Cursor cursor;		/* X Cursor */
    int cursorX, cursorY;	/* Position of the insertion cursor in the
				 * editor window. */
    short int cursorWidth;	/* Size of the insertion cursor symbol. */
    short int cursorHeight;

    int selAnchor;		/* Fixed end of selection. Used to extend
				 * the selection while maintaining the
				 * other end of the selection. */
    int selFirst;		/* Position of the first character in the
				 * selection. */
    int selLast;		/* Position of the last character in the
				 * selection. */

    int cursorOn;		/* Indicates if the cursor is displayed. */
    int onTime, offTime;	/* Time in milliseconds to wait before
				 * changing the cursor from off-to-on
				 * and on-to-off. Setting offTime to 0 makes
				 * the cursor steady. */
    Tcl_TimerToken timerToken;	/* Handle for a timer event called periodically
				 * to blink the cursor. */
    /* Data-specific fields. */
    TreeViewEntry *entryPtr;	/* Selected entry */
    TreeViewColumn *columnPtr;	/* Column of entry to be edited */
    char *string;
    TextLayout *textPtr;
    Tk_Font font;
    GC gc;

    Tk_3DBorder selBorder;
    int selRelief;
    int selBorderWidth;
    Tk_3DBorder border;
    int relief;
    int borderWidth;
    XColor *selFgColor;		/* Text color of a selected entry. */


};

#define DEF_EDITOR_BACKGROUND		RGB_WHITE
#define DEF_EDITOR_BORDER_WIDTH		STD_BORDERWIDTH
#define DEF_EDITOR_CURSOR		(char *)NULL
#define DEF_EDITOR_EXPORT_SELECTION	"no"
#define DEF_EDITOR_NORMAL_BG_COLOR 	STD_COLOR_NORMAL_BG
#define DEF_EDITOR_NORMAL_FG_MONO	STD_MONO_ACTIVE_FG
#define DEF_EDITOR_RELIEF		"solid"
#define DEF_EDITOR_SELECT_BG_COLOR 	RGB_BISQUE1
#define DEF_EDITOR_SELECT_BG_MONO  	STD_MONO_SELECT_BG
#define DEF_EDITOR_SELECT_BORDER_WIDTH	"1"
#define DEF_EDITOR_SELECT_FG_COLOR 	STD_COLOR_SELECT_FG
#define DEF_EDITOR_SELECT_FG_MONO  	STD_MONO_SELECT_FG
#define DEF_EDITOR_SELECT_RELIEF	"raised"

/* Editor Procedures */
static Blt_ConfigSpec editorConfigSpecs[] =
{
    {BLT_CONFIG_BORDER, "-background", "background", "Background",
	DEF_EDITOR_BACKGROUND, Blt_Offset(TreeViewEditor, border), 0},
    {BLT_CONFIG_SYNONYM, "-bd", "borderWidth", (char *)NULL, (char *)NULL, 0,0},
    {BLT_CONFIG_SYNONYM, "-bg", "background", (char *)NULL, (char *)NULL, 0,0},
    {BLT_CONFIG_ACTIVE_CURSOR, "-cursor", "cursor", "Cursor",
	DEF_EDITOR_CURSOR, Blt_Offset(TreeViewEditor, cursor), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_DISTANCE, "-borderwidth", "borderWidth", "BorderWidth",
	DEF_EDITOR_BORDER_WIDTH, Blt_Offset(TreeViewEditor, borderWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_BOOLEAN, "-exportselection", "exportSelection",
	"ExportSelection", DEF_EDITOR_EXPORT_SELECTION, 
	Blt_Offset(TreeViewEditor, exportSelection), 
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_RELIEF, "-relief", "relief", "Relief",
	DEF_EDITOR_RELIEF, Blt_Offset(TreeViewEditor, relief), 0},
    {BLT_CONFIG_BORDER, "-selectbackground", "selectBackground", "Background",
	DEF_EDITOR_SELECT_BG_MONO, Blt_Offset(TreeViewEditor, selBorder),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_BORDER, "-selectbackground", "selectBackground", "Background",
	DEF_EDITOR_SELECT_BG_COLOR, Blt_Offset(TreeViewEditor, selBorder),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_DISTANCE, "-selectborderwidth", "selectBorderWidth", 
        "BorderWidth", DEF_EDITOR_SELECT_BORDER_WIDTH, 
	Blt_Offset(TreeViewEditor, selBorderWidth), 
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_COLOR, "-selectforeground", "selectForeground", "Foreground",

	DEF_EDITOR_SELECT_FG_MONO, Blt_Offset(TreeViewEditor, selFgColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_COLOR, "-selectforeground", "selectForeground", "Foreground",
	DEF_EDITOR_SELECT_FG_COLOR, Blt_Offset(TreeViewEditor, selFgColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_RELIEF, "-selectrelief", "selectRelief", "Relief",
	DEF_EDITOR_SELECT_RELIEF, Blt_Offset(TreeViewEditor, selRelief),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL, (char *)NULL, 
	0, 0}
};


#ifdef __STDC__
static Tk_LostSelProc TreeViewEditorLostSelectionProc;
static Tk_SelectionProc TreeViewEditorSelectionProc;
static Tk_EventProc TreeViewEditorEventProc;
#endif

/*
 *----------------------------------------------------------------------
 *
 * EventuallyRedrawEditor --
 *
 *	Queues a request to redraw the widget at the next idle point.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Information gets redisplayed.  Right now we don't do selective
 *	redisplays:  the whole window will be redrawn.
 *
 *----------------------------------------------------------------------
 */
static void
EventuallyRedrawEditor(tvPtr)
    TreeView *tvPtr;
{
    if ((tvPtr->editPtr->tkwin != NULL) && 
	((tvPtr->editPtr->flags & EDITOR_REDRAW) == 0)) {
	tvPtr->editPtr->flags |= EDITOR_REDRAW;
	Tcl_DoWhenIdle(DisplayTreeViewEditor, tvPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * BlinkCursorProc --
 *
 *	This procedure is called as a timer handler to blink the
 *	insertion cursor off and on.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The cursor gets turned on or off, redisplay gets invoked,
 *	and this procedure reschedules itself.
 *
 *----------------------------------------------------------------------
 */
static void
BlinkCursorProc(clientData)
    ClientData clientData;	/* Pointer to record describing entry. */
{
    TreeView *tvPtr = clientData;
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int interval;

    if (!(editPtr->flags & EDITOR_FOCUS) || (editPtr->offTime == 0)) {
	return;
    }
    if (editPtr->active) {
	editPtr->cursorOn ^= 1;
	interval = (editPtr->cursorOn) ? editPtr->onTime : editPtr->offTime;
	editPtr->timerToken = 
	    Tcl_CreateTimerHandler(interval, BlinkCursorProc, tvPtr);
	EventuallyRedrawEditor(tvPtr);
    }
}

/*
 * --------------------------------------------------------------
 *
 * TreeViewEditorEventProc --
 *
 * 	This procedure is invoked by the Tk dispatcher for various
 * 	events on hierarchy widgets.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	When the window gets deleted, internal structures get
 *	cleaned up.  When it gets exposed, it is redisplayed.
 *
 * --------------------------------------------------------------
 */
static void
TreeViewEditorEventProc(clientData, eventPtr)
    ClientData clientData;	/* Information about window. */
    XEvent *eventPtr;		/* Information about event. */
{
    TreeView *tvPtr = clientData;
    TreeViewEditor *editPtr = tvPtr->editPtr;

    if (eventPtr->type == Expose) {
	if (eventPtr->xexpose.count == 0) {
	    EventuallyRedrawEditor(tvPtr);
	}
    } else if (eventPtr->type == ConfigureNotify) {
	EventuallyRedrawEditor(tvPtr);
    } else if ((eventPtr->type == FocusIn) || (eventPtr->type == FocusOut)) {
	if (eventPtr->xfocus.detail == NotifyInferior) {
	    return;
	}
	if (eventPtr->type == FocusIn) {
	    editPtr->flags |= EDITOR_FOCUS;
	} else {
	    editPtr->flags &= ~EDITOR_FOCUS;
	}
	Tcl_DeleteTimerHandler(editPtr->timerToken);
	if ((editPtr->active) && (editPtr->flags & EDITOR_FOCUS)) {
	    editPtr->cursorOn = TRUE;
	    if (editPtr->offTime != 0) {
		editPtr->timerToken = Tcl_CreateTimerHandler(editPtr->onTime, 
		   BlinkCursorProc, clientData);
	    }
	} else {
	    editPtr->cursorOn = FALSE;
	    editPtr->timerToken = (Tcl_TimerToken) NULL;
	}
	EventuallyRedrawEditor(tvPtr);
    } else if (eventPtr->type == DestroyNotify) {
	if (editPtr->tkwin != NULL) {
	    editPtr->tkwin = NULL;
	}
	if (editPtr->flags & EDITOR_REDRAW) {
	    Tcl_CancelIdleCall(DisplayTreeViewEditor, tvPtr);
	}
	if (editPtr->timerToken != NULL) {
	    Tcl_DeleteTimerHandler(editPtr->timerToken);
	}
	Tcl_EventuallyFree(tvPtr, DestroyTreeViewEditor);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * TreeViewEditorLostSelectionProc --
 *
 *	This procedure is called back by Tk when the selection is
 *	grabbed away from a Text widget.
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
TreeViewEditorLostSelectionProc(clientData)
    ClientData clientData;	/* Information about Text widget. */
{
    TreeView *tvPtr = clientData;
    TreeViewEditor *editPtr = tvPtr->editPtr;

    if ((editPtr->selFirst >= 0) && (editPtr->exportSelection)) {
	editPtr->selFirst = editPtr->selLast = -1;
	EventuallyRedrawEditor(tvPtr);
    }
}

static int
PointerToIndex(tvPtr, x, y)
    TreeView *tvPtr;
    int x, y;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    TextLayout *textPtr;
    Tk_FontMetrics fontMetrics;
    TextFragment *fragPtr;
    int nBytes;
    register int i;
    int total;

    if ((editPtr->string == NULL) || (editPtr->string[0] == '\0')) {
	return 0;
    }
    x -= editPtr->selBorderWidth;
    y -= editPtr->selBorderWidth;

    textPtr = editPtr->textPtr;

    /* Bound the y-coordinate within the window. */
    if (y < 0) {
	y = 0;
    } else if (y >= textPtr->height) {
	y = textPtr->height - 1;
    }
    /* 
     * Compute the line that contains the y-coordinate. 
     *
     * FIXME: This assumes that segments are distributed 
     *	     line-by-line.  This may change in the future.
     */
    Tk_GetFontMetrics(editPtr->font, &fontMetrics);
    fragPtr = textPtr->fragArr;
    total = 0;
    for (i = (y / fontMetrics.linespace); i > 0; i--) {
	total += fragPtr->count;
	fragPtr++;
    }
    if (x < 0) {
	nBytes = 0;
    } else if (x >= textPtr->width) {
	nBytes = fragPtr->count;
    } else {
	int newX;

	/* Find the character underneath the pointer. */
	nBytes = Tk_MeasureChars(editPtr->font, fragPtr->text, fragPtr->count, 
		 x, 0, &newX);
	if ((newX < x) && (nBytes < fragPtr->count)) {
	    double fract;
	    int length, charSize;
	    char *next;

	    next = fragPtr->text + nBytes;
#if HAVE_UTF
	    {
		Tcl_UniChar dummy;

		length = Tcl_UtfToUniChar(next, &dummy);
	    }
#else
	    length = 1;
#endif
	    charSize = Tk_TextWidth(editPtr->font, next, length);
	    fract = ((double)(x - newX) / (double)charSize);
	    if (ROUND(fract)) {
		nBytes += length;
	    }
	}
    }
    return nBytes + total;
}

static int
IndexToPointer(tvPtr)
    TreeView *tvPtr;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int x, y;
    int maxLines;
    TextLayout *textPtr;
    Tk_FontMetrics fontMetrics;
    int nBytes;
    int sum;
    TextFragment *fragPtr;
    register int i;

    textPtr = editPtr->textPtr;
    Tk_GetFontMetrics(editPtr->font, &fontMetrics);
    maxLines = (textPtr->height / fontMetrics.linespace) - 1;

    nBytes = sum = 0;
    x = y = 0;
    fragPtr = textPtr->fragArr;
    for (i = 0; i <= maxLines; i++) {
	/* Total the number of bytes on each line.  Include newlines. */
	nBytes = fragPtr->count + 1;
	if ((sum + nBytes) > editPtr->insertPos) {
	    x += Tk_TextWidth(editPtr->font, fragPtr->text, 
		editPtr->insertPos - sum);
	    break;
	}
	y += fontMetrics.linespace;
	sum += nBytes;
	fragPtr++;
    }
    editPtr->cursorX = x;
    editPtr->cursorY = y;
    editPtr->cursorHeight = fontMetrics.linespace;
    editPtr->cursorWidth = 3;
    return TCL_OK;
}

static void
UpdateLayout(tvPtr)
    TreeView *tvPtr;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    TextStyle ts;
    int width, height;
    TextLayout *textPtr;

    /* The layout is based upon the current font. */
    Blt_InitTextStyle(&ts);
    ts.anchor = TK_ANCHOR_NW;
    ts.justify = TK_JUSTIFY_LEFT;
    ts.font = editPtr->font;
    textPtr = Blt_GetTextLayout(editPtr->string, &ts);
    if (editPtr->textPtr != NULL) {
	Blt_Free(editPtr->textPtr);
    }
    editPtr->textPtr = textPtr;

    width = editPtr->textPtr->width;
    if (width < editPtr->columnPtr->width) {
	width = editPtr->columnPtr->width;
    }
    height = editPtr->textPtr->height;
    if (height < 1) {
	Tk_FontMetrics fontMetrics;
	
	Tk_GetFontMetrics(editPtr->font, &fontMetrics);
	height = fontMetrics.linespace;
    }
    editPtr->width = width + 2 * editPtr->borderWidth;
    editPtr->height = height + 2 * editPtr->borderWidth;
    IndexToPointer(tvPtr);
    Tk_MoveResizeWindow(editPtr->tkwin, editPtr->x, editPtr->y, editPtr->width,
	editPtr->height);
}

static void
InsertText(tvPtr, insertText, insertPos, nBytes)
    TreeView *tvPtr;
    char *insertText;
    int insertPos;
    int nBytes;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int oldSize, newSize;
    char *oldText, *newText;

    oldText = editPtr->string;
    oldSize = strlen(oldText);
    newSize = oldSize + nBytes;
    newText = Blt_Malloc(sizeof(char) * (newSize + 1));
    if (insertPos == oldSize) {	/* Append */
	strcpy(newText, oldText);
	strcat(newText, insertText);
    } else if (insertPos == 0) {/* Prepend */
	strcpy(newText, insertText);
	strcat(newText, oldText);
    } else {			/* Insert into existing. */
	char *p;
	
	p = newText;
	strncpy(p, oldText, insertPos);
	p += insertPos;
	strcpy(p, insertText);
	p += nBytes;
	strcpy(p, oldText + insertPos);
    }

    /* 
     * All indices from the start of the insertion to the end of the
     * string need to be updated.  Simply move the indices down by the
     * number of characters added.  
     */
    if (editPtr->selFirst >= insertPos) {
	editPtr->selFirst += nBytes;
    }
    if (editPtr->selLast > insertPos) {
	editPtr->selLast += nBytes;
    }
    if ((editPtr->selAnchor > insertPos) || (editPtr->selFirst >= insertPos)) {
	editPtr->selAnchor += nBytes;
    }
    if (editPtr->string != NULL) {
	Blt_Free(editPtr->string);
    }
    editPtr->string = newText;
    editPtr->insertPos = insertPos + nBytes;
    UpdateLayout(tvPtr);
}

static int
DeleteText(tvPtr, firstPos, lastPos)
    TreeView *tvPtr;
    int firstPos, lastPos;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    char *oldText, *newText;
    int oldSize, newSize;
    int nBytes;
    char *p;

    oldText = editPtr->string;
    if (firstPos > lastPos) {
	return TCL_OK;
    }
    lastPos++;			/* Now is the position after the last
				 * character. */

    nBytes = lastPos - firstPos;

    oldSize = strlen(oldText) + 1;
    newSize = oldSize - nBytes + 1;
    newText = Blt_Malloc(sizeof(char) * newSize);
    p = newText;
    if (firstPos > 0) {
	strncpy(p, oldText, firstPos);
	p += firstPos;
    }
    *p = '\0';
    if (lastPos < oldSize) {
	strcpy(p, oldText + lastPos);
    }
    Blt_Free(oldText);

    /*
     * Since deleting characters compacts the character array, we need to
     * update the various character indices according.  It depends where
     * the index occurs in relation to range of deleted characters:
     *
     *	 before		Ignore.
     *   within		Move the index back to the start of the deletion.
     *	 after		Subtract off the deleted number of characters,
     *			since the array has been compressed by that
     *			many characters.
     *
     */
    if (editPtr->selFirst >= firstPos) {
	if (editPtr->selFirst >= lastPos) {
	    editPtr->selFirst -= nBytes;
	} else {
	    editPtr->selFirst = firstPos;
	}
    }
    if (editPtr->selLast >= firstPos) {
	if (editPtr->selLast >= lastPos) {
	    editPtr->selLast -= nBytes;
	} else {
	    editPtr->selLast = firstPos;
	}
    }
    if (editPtr->selLast <= editPtr->selFirst) {
	editPtr->selFirst = editPtr->selLast = -1; /* Cut away the entire
						    * selection. */ 
    }
    if (editPtr->selAnchor >= firstPos) {
	if (editPtr->selAnchor >= lastPos) {
	    editPtr->selAnchor -= nBytes;
	} else {
	    editPtr->selAnchor = firstPos;
	}
    }
    if (editPtr->insertPos >= firstPos) {
	if (editPtr->insertPos >= lastPos) {
	    editPtr->insertPos -= nBytes;
	} else {
	    editPtr->insertPos = firstPos;
	}
    }
    editPtr->string = newText;
    UpdateLayout(tvPtr);
    EventuallyRedrawEditor(tvPtr);
    return TCL_OK;
}

static int
AcquireText(tvPtr, entryPtr, columnPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    TreeViewColumn *columnPtr;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int x, y;
    char *string;

    string = NULL;
    if (columnPtr == &tvPtr->treeColumn) {
	int level;

	level = DEPTH(tvPtr, entryPtr->node);
	x = SCREENX(tvPtr, entryPtr->worldX);
	y = SCREENY(tvPtr, entryPtr->worldY);
	x += ICONWIDTH(level) + ICONWIDTH(level + 1) + 4;
	string = GETLABEL(entryPtr);
    } else {
	Tcl_Obj *objPtr;

	objPtr = Blt_TreeViewGetData(entryPtr, columnPtr->key);
	if (objPtr != NULL) {
	    string = Tcl_GetString(objPtr);
	}
	x = SCREENX(tvPtr, columnPtr->worldX);
	y = SCREENY(tvPtr, entryPtr->worldY);
    }
    if (editPtr->textPtr != NULL) {
	Blt_Free(editPtr->textPtr);
	editPtr->textPtr = NULL;
    }
    if (editPtr->string != NULL) {
	Blt_Free(editPtr->string);
    }
    if (string == NULL) {
	string = "";
    }
    editPtr->entryPtr = entryPtr;
    editPtr->columnPtr = columnPtr;
    editPtr->x = x - editPtr->borderWidth;
    editPtr->y = y - editPtr->borderWidth;
    editPtr->string = Blt_Strdup(string);
    editPtr->gc = columnPtr->gc;
    editPtr->font = CHOOSE(tvPtr->treeColumn.font, columnPtr->font);
    editPtr->selFirst = editPtr->selLast = -1;
    UpdateLayout(tvPtr);
    Tk_MapWindow(editPtr->tkwin);
    EventuallyRedrawEditor(tvPtr);
    return TCL_OK;
}


/*
 *---------------------------------------------------------------------------
 *
 * GetIndexFromObj --
 *
 *	Parse an index into an entry and return either its value
 *	or an error.
 *
 * Results:
 *	A standard Tcl result.  If all went well, then *indexPtr is
 *	filled in with the character index (into entryPtr) corresponding to
 *	string.  The index value is guaranteed to lie between 0 and
 *	the number of characters in the string, inclusive.  If an
 *	error occurs then an error message is left in the interp's result.
 *
 * Side effects:
 *	None.
 *
 *---------------------------------------------------------------------------
 */
static int
GetIndexFromObj(interp, tvPtr, objPtr, indexPtr)
    Tcl_Interp *interp;
    TreeView *tvPtr;
    Tcl_Obj *objPtr;
    int *indexPtr;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int textPos;
    char c;
    char *string;

    string = Tcl_GetString(objPtr);
    if ((editPtr->string == NULL) || (editPtr->string[0] == '\0')) {
	*indexPtr = 0;
	return TCL_OK;
    }
    c = string[0];
    if ((c == 'a') && (strcmp(string, "anchor") == 0)) {
	textPos = editPtr->selAnchor;
    } else if ((c == 'e') && (strcmp(string, "end") == 0)) {
	textPos = strlen(editPtr->string);
    } else if ((c == 'i') && (strcmp(string, "insert") == 0)) {
	textPos = editPtr->insertPos;
    } else if ((c == 'n') && (strcmp(string, "next") == 0)) {
	textPos = editPtr->insertPos;
	if (textPos < strlen(editPtr->string)) {
	    textPos++;
	}
    } else if ((c == 'l') && (strcmp(string, "last") == 0)) {
	textPos = editPtr->insertPos;
	if (textPos > 0) {
	    textPos--;
	}
    } else if ((c == 's') && (strcmp(string, "sel.first") == 0)) {
	if (editPtr->selFirst < 0) {
	    textPos = -1;
	} else {
	    textPos = editPtr->selFirst;
	}
    } else if ((c == 's') && (strcmp(string, "sel.last") == 0)) {
	if (editPtr->selLast < 0) {
	    textPos = -1;
	} else {
	    textPos = editPtr->selLast;
	}
    } else if (c == '@') {
	int x, y;

	if (Blt_GetXY(interp, editPtr->tkwin, string, &x, &y) != TCL_OK) {
	    return TCL_ERROR;
	}
	textPos = PointerToIndex(tvPtr, x, y);
    } else if (isdigit((int)c)) {
	int number;
	int maxChars;

	if (Tcl_GetIntFromObj(interp, objPtr, &number) != TCL_OK) {
	    return TCL_ERROR;
	}
	/* Don't allow the index to point outside the label. */
	maxChars = Tcl_NumUtfChars(editPtr->string, -1);
	if (number < 0) {
	    textPos = 0;
	} else if (number > maxChars) {
	    textPos = strlen(editPtr->string);
	} else {
	    textPos = Tcl_UtfAtIndex(editPtr->string, number) - 
		editPtr->string;
	}
    } else {
	if (interp != NULL) {
	    Tcl_AppendResult(interp, "bad label index \"", string, "\"",
			     (char *)NULL);
	}
	return TCL_ERROR;
    }
    *indexPtr = textPos;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * SelectText --
 *
 *	Modify the selection by moving its un-anchored end.  This
 *	could make the selection either larger or smaller.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The selection changes.
 *
 *----------------------------------------------------------------------
 */
static int
SelectText(tvPtr, textPos)
    TreeView *tvPtr;		/* Information about editor. */
    int textPos;		/* Index of element that is to
				 * become the "other" end of the
				 * selection. */
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int selFirst, selLast;

    /*
     * Grab the selection if we don't own it already.
     */
    if ((editPtr->exportSelection) && (editPtr->selFirst == -1)) {
	Tk_OwnSelection(editPtr->tkwin, XA_PRIMARY, 
			TreeViewEditorLostSelectionProc, tvPtr);
    }
    /*  If the anchor hasn't been set yet, assume the beginning of the text*/
    if (editPtr->selAnchor < 0) {
	editPtr->selAnchor = 0;
    }
    if (editPtr->selAnchor <= textPos) {
	selFirst = editPtr->selAnchor;
	selLast = textPos;
    } else {
	selFirst = textPos;
	selLast = editPtr->selAnchor;
    }
    if ((editPtr->selFirst != selFirst) || (editPtr->selLast != selLast)) {
	editPtr->selFirst = selFirst;
	editPtr->selLast = selLast;
	EventuallyRedrawEditor(tvPtr);
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * TreeViewEditorSelectionProc --
 *
 *	This procedure is called back by Tk when the selection is
 *	requested by someone.  It returns part or all of the selection
 *	in a buffer provided by the caller.
 *
 * Results:
 *	The return value is the number of non-NULL bytes stored at
 *	buffer.  Buffer is filled (or partially filled) with a
 *	NUL-terminated string containing part or all of the
 *	selection, as given by offset and maxBytes.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static int
TreeViewEditorSelectionProc(clientData, offset, buffer, maxBytes)
    ClientData clientData;	/* Information about the widget. */
    int offset;			/* Offset within selection of first
				 * character to be returned. */
    char *buffer;		/* Location in which to place
				 * selection. */
    int maxBytes;		/* Maximum number of bytes to place
				 * at buffer, not including terminating
				 * NULL character. */
{
    TreeView *tvPtr = clientData;
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int size;

    size = strlen(editPtr->string + offset);
    /*
     * Return the string currently in the editor.
     */
    strncpy(buffer, editPtr->string + offset, maxBytes);
    buffer[maxBytes] = '\0';
    return (size > maxBytes) ? maxBytes : size;
}


static void
DestroyTreeViewEditor(data)
    DestroyData data;
{
    TreeView *tvPtr = (TreeView *)data;
    TreeViewEditor *editPtr = tvPtr->editPtr;

    Blt_FreeObjOptions(editorConfigSpecs, (char *)editPtr, tvPtr->display, 0);

    if (editPtr->string != NULL) {
	Blt_Free(editPtr->string);
    }
    if (editPtr->textPtr != NULL) {
	Blt_Free(editPtr->textPtr);
    }
    if (editPtr->timerToken != NULL) {
	Tcl_DeleteTimerHandler(editPtr->timerToken);
    }
    if (editPtr->tkwin != NULL) {
	Tk_DeleteSelHandler(editPtr->tkwin, XA_PRIMARY, XA_STRING);
    }
    Blt_Free(editPtr);
}

static void
ConfigureTreeViewEditor(tvPtr)
    TreeView *tvPtr;
{
#ifdef notdef
    GC newGC;
    TreeViewEditor *editPtr = tvPtr->editPtr;
    XGCValues gcValues;
    unsigned long gcMask;

    /*
     * GC for edit window.
     */
    gcMask = 0;
    newGC = Tk_GetGC(editPtr->tkwin, gcMask, &gcValues);
    if (editPtr->gc != NULL) {
	Tk_FreeGC(tvPtr->display, editPtr->gc);
    }
    editPtr->gc = newGC;
    editPtr->width = editPtr->textPtr->width + 
	2 * (editPtr->borderWidth + editPtr->highlightWidth);
    editPtr->height = editPtr->textPtr->height + 
	2 * (editPtr->borderWidth + editPtr->highlightWidth);
    
    if (Tk_IsMapped(editPtr->tkwin)) {
	if ((editPtr->height != Tk_Height(editPtr->tkwin)) ||
	    (editPtr->width != Tk_Width(editPtr->tkwin))) {
	    Tk_ResizeWindow(editPtr->tkwin, editPtr->width, editPtr->height);
	}
    }
#endif
}

TreeViewEditor *
Blt_TreeViewCreateEditor(tvPtr, className)
    TreeView *tvPtr;
    char *className;		/* Class name of widget: either
				 * "Hiertable" or "TreeView". */
{
    TreeViewEditor *editPtr;
    Tk_Window tkwin;
    char editClass[20];

    tkwin = Tk_CreateWindow(tvPtr->interp, tvPtr->tkwin, "edit", (char *)NULL);
    if (tkwin == NULL) {
	return NULL;
    }
    sprintf(editClass, "%sEditor", className);
    Tk_SetClass(tkwin, editClass); 

    editPtr = Blt_Calloc(1, sizeof(TreeViewEditor));
    assert(editPtr);

    editPtr->tkwin = tkwin;
    editPtr->borderWidth = 1;
    editPtr->relief = TK_RELIEF_SOLID;
    editPtr->selRelief = TK_RELIEF_RAISED;
    editPtr->selBorderWidth = 1;
    editPtr->selAnchor = -1;
    editPtr->selFirst = editPtr->selLast = -1;
    editPtr->onTime = 600;
    editPtr->active = TRUE;
    editPtr->offTime = 300;
#if (TK_MAJOR_VERSION > 4)
    Blt_SetWindowInstanceData(tkwin, editPtr);
#endif
    Tk_CreateSelHandler(tkwin, XA_PRIMARY, XA_STRING, 
	TreeViewEditorSelectionProc, tvPtr, XA_STRING);
    Tk_CreateEventHandler(tkwin, ExposureMask | StructureNotifyMask |
	FocusChangeMask, TreeViewEditorEventProc, tvPtr);
    Tcl_CreateObjCommand(tvPtr->interp, Tk_PathName(tkwin), 
	Blt_TreeViewWidgetInstCmd, tvPtr, NULL);
    if (Blt_ConfigureWidgetFromObj(tvPtr->interp, tkwin, editorConfigSpecs, 0, 
	(Tcl_Obj **)NULL, (char *)editPtr, 0) != TCL_OK) {
	Tk_DestroyWindow(tkwin);
	return NULL;
    }
    return editPtr;
}

static void
DisplayTreeViewEditor(clientData)
    ClientData clientData;
{
    TreeView *tvPtr = clientData;
    TreeViewEditor *editPtr = tvPtr->editPtr;
    Pixmap drawable;
    register int i;
    int x1, x2;
    int count, nChars;
    int leftPos, rightPos;
    int selStart, selEnd, selLength;
    int x, y;
    TextFragment *fragPtr;
    Tk_FontMetrics fontMetrics;

    editPtr->flags &= ~EDITOR_REDRAW;
    if (!Tk_IsMapped(editPtr->tkwin)) {
	return;
    }
    drawable = Tk_GetPixmap(tvPtr->display, Tk_WindowId(editPtr->tkwin), 
	Tk_Width(editPtr->tkwin), Tk_Height(editPtr->tkwin), 
	Tk_Depth(editPtr->tkwin));

    Tk_Fill3DRectangle(editPtr->tkwin, drawable, editPtr->border, 0, 0,
	Tk_Width(editPtr->tkwin), Tk_Height(editPtr->tkwin), 
	editPtr->borderWidth, editPtr->relief);

    Tk_GetFontMetrics(editPtr->font, &fontMetrics);
    fragPtr = editPtr->textPtr->fragArr;
    count = 0;
    for (i = 0; i < editPtr->textPtr->nFrags; i++, fragPtr++) {
	leftPos = count;
	count += fragPtr->count;
	rightPos = count;
	y = fragPtr->y + editPtr->borderWidth;
	x = editPtr->borderWidth;
	if ((rightPos < editPtr->selFirst) || (leftPos > editPtr->selLast)) {
	    /* No selected text */
	    Tk_DrawChars(tvPtr->display, drawable, editPtr->gc, editPtr->font,
		fragPtr->text, fragPtr->count, x, y);
	    continue;
	}
	/*
	 *  A text segment (with selected text) may have up to 3 regions:
	 *
	 *	1. Text before the start the selection
	 *	2. Selected text itself (drawn in a raised border)
	 *	3. Text following the selection.
	 */

	selStart = leftPos;
	selEnd = rightPos;
	/* First adjust selected region for current line. */
	if (editPtr->selFirst > leftPos) {
	    selStart = editPtr->selFirst;
	}
	if (editPtr->selLast < rightPos) {
	    selEnd = editPtr->selLast;
	}
	selLength = (selEnd - selStart);
	x1 = x;

	if (selStart > leftPos) { /* Normal text preceding the selection */
	    nChars = (selStart - leftPos);
	    Tk_MeasureChars(editPtr->font, editPtr->string + leftPos,
		    nChars, 10000, DEF_TEXT_FLAGS, &x1);
	    x1 += x;
	}
	if (selLength > 0) {	/* The selection itself */
	    int width;

	    Tk_MeasureChars(editPtr->font, fragPtr->text + selStart, selLength,
		10000, DEF_TEXT_FLAGS, &x2);
	    x2 += x;
	    width = (x2 - x1) + 1;
	    Tk_Fill3DRectangle(editPtr->tkwin, drawable, editPtr->selBorder,
		x1, y - fontMetrics.ascent, width, fontMetrics.linespace, 
		editPtr->selBorderWidth, editPtr->selRelief);
	}
	Tk_DrawChars(Tk_Display(editPtr->tkwin), drawable, editPtr->gc, 
	     editPtr->font, fragPtr->text, fragPtr->count, x, y);
    }
    if ((editPtr->flags & EDITOR_FOCUS) && (editPtr->cursorOn)) {
	int left, top, right, bottom;

	IndexToPointer(tvPtr);
	left = editPtr->cursorX + editPtr->borderWidth + 1;
	right = left + 1;
	top = editPtr->cursorY + 2;
	bottom = editPtr->cursorY + editPtr->cursorHeight - 2;
	XDrawLine(tvPtr->display, drawable, editPtr->gc, left, top, left,
		bottom);
	XDrawLine(tvPtr->display, drawable, editPtr->gc, left - 1, top, right,
		top);
	XDrawLine(tvPtr->display, drawable, editPtr->gc, left - 1, bottom, 
		right, bottom);
    }
    Tk_Draw3DRectangle(editPtr->tkwin, drawable, editPtr->border, 0, 0,
	Tk_Width(editPtr->tkwin), Tk_Height(editPtr->tkwin), 
	editPtr->borderWidth, editPtr->relief);
    XCopyArea(tvPtr->display, drawable, Tk_WindowId(editPtr->tkwin),
	editPtr->gc, 0, 0, Tk_Width(editPtr->tkwin), 
	Tk_Height(editPtr->tkwin), 0, 0);
    Tk_FreePixmap(tvPtr->display, drawable);

}

/*ARGSUSED*/
static int
ApplyOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;	/* Not used. */
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    TreeViewEntry *entryPtr;

    entryPtr = editPtr->entryPtr;
    if (editPtr->columnPtr == &tvPtr->treeColumn) {

	if (entryPtr->labelUid != NULL) {
	    Blt_TreeViewFreeUid(tvPtr, entryPtr->labelUid);
	}
	if (editPtr->string == NULL) {
	    entryPtr->labelUid = Blt_TreeViewGetUid(tvPtr, "");
	} else {
	    entryPtr->labelUid = Blt_TreeViewGetUid(tvPtr, editPtr->string);
	}
    } else {
	TreeViewColumn *columnPtr;
	Tcl_Obj *objPtr;

	columnPtr = editPtr->columnPtr;
	objPtr = Tcl_NewStringObj(editPtr->string, -1);
	if (Blt_TreeSetValueByKey(interp, tvPtr->tree, entryPtr->node, 
		columnPtr->key, objPtr) != TCL_OK) {
	    return TCL_ERROR;
	}
	entryPtr->flags |= ENTRY_DIRTY;
    }	
    Blt_TreeViewConfigureEntry(tvPtr, entryPtr);
    tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
    Blt_TreeViewEventuallyRedraw(tvPtr);
    Tk_UnmapWindow(editPtr->tkwin);
    return TCL_OK;
}

/*ARGSUSED*/
static int
CancelOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;	/* Not used. */
{
    Tk_UnmapWindow(tvPtr->editPtr->tkwin);
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * CgetOp --
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
CgetOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;
{
    return Blt_ConfigureValueFromObj(interp, tvPtr->editPtr->tkwin, 
	editorConfigSpecs, (char *)tvPtr->editPtr, objv[3], 0);
}

/*
 *----------------------------------------------------------------------
 *
 * ConfigureOp --
 *
 * 	This procedure is called to process a list of configuration
 *	options database, in order to reconfigure the one of more
 *	entries in the widget.
 *
 *	  .h text configure option value
 *
 * Results:
 *	A standard Tcl result.  If TCL_ERROR is returned, then
 *	interp->result contains an error message.
 *
 * Side effects:
 *	Configuration information, such as text string, colors, font,
 *	etc. get set for tvPtr; old resources get freed, if there
 *	were any.  The hypertext is redisplayed.
 *
 *----------------------------------------------------------------------
 */
static int
ConfigureOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;
    int objc;
    Tcl_Obj *CONST *objv;
{
    if (objc == 3) {
	return Blt_ConfigureInfoFromObj(interp, tvPtr->editPtr->tkwin, 
		editorConfigSpecs, (char *)tvPtr->editPtr, (Tcl_Obj *)NULL, 0);
    } else if (objc == 4) {
	return Blt_ConfigureInfoFromObj(interp, tvPtr->editPtr->tkwin, 
		editorConfigSpecs, (char *)tvPtr->editPtr, objv[3], 0);
    }
    if (Blt_ConfigureWidgetFromObj(interp, tvPtr->editPtr->tkwin, 
	editorConfigSpecs, objc - 3, objv + 3, (char *)tvPtr->editPtr, 
	BLT_CONFIG_OBJV_ONLY) != TCL_OK) {
	return TCL_ERROR;
    }
    ConfigureTreeViewEditor(tvPtr);
    EventuallyRedrawEditor(tvPtr);
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * DeleteOp --
 *
 *	Remove one or more characters from the label of an entry.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Memory gets freed, the entry gets modified and (eventually)
 *	redisplayed.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
DeleteOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    int firstPos, lastPos;

    if (tvPtr->editPtr->entryPtr == NULL) {
	return TCL_OK;
    }
    if (GetIndexFromObj(interp, tvPtr, objv[3], &firstPos) != TCL_OK) {
	return TCL_ERROR;
    }
    lastPos = firstPos;
    if ((objc == 5) && 
	(GetIndexFromObj(interp, tvPtr, objv[4], &lastPos) != TCL_OK)) {
	return TCL_ERROR;
    }
    if (firstPos > lastPos) {
	return TCL_OK;
    }
    return DeleteText(tvPtr, firstPos, lastPos);
}

/*ARGSUSED*/
static int
GetOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    TreeViewEntry *entryPtr;
    char *string;
    int x, y;
    int isRoot;

    isRoot = FALSE;
    string = Tcl_GetString(objv[3]);
    if (strcmp("-root", string) == 0) {
	isRoot = TRUE;
	objv++, objc--;
    }
    if (objc != 5) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", 
		Tcl_GetString(objv[0]), " ", Tcl_GetString(objv[1]), 
		Tcl_GetString(objv[2]), " ?-root? x y\"", (char *)NULL);
	return TCL_ERROR;
			 
    }
    if ((Tcl_GetIntFromObj(interp, objv[3], &x) != TCL_OK) ||
	(Tcl_GetIntFromObj(interp, objv[4], &y) != TCL_OK)) {
	return TCL_ERROR;
    }
    if (isRoot) {
	int rootX, rootY;

	Tk_GetRootCoords(tvPtr->tkwin, &rootX, &rootY);
	x -= rootX;
	y -= rootY;
    }
    entryPtr = Blt_TreeViewNearestEntry(tvPtr, x, y, FALSE);
    if (entryPtr != NULL) {
	Blt_ChainLink *linkPtr;
	TreeViewColumn *columnPtr;
	int worldX;

	worldX = WORLDX(tvPtr, x);
	for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); 
	     linkPtr != NULL; linkPtr = Blt_ChainNextLink(linkPtr)) {
	    columnPtr = Blt_ChainGetValue(linkPtr);
	    if (!columnPtr->editable) {
		continue;
	    }
	    if ((worldX >= columnPtr->worldX) && 
		(worldX < (columnPtr->worldX + columnPtr->width))) {
		AcquireText(tvPtr, entryPtr, columnPtr);
		tvPtr->editPtr->insertPos = strlen(tvPtr->editPtr->string);
		Tk_MapWindow(tvPtr->editPtr->tkwin);
		EventuallyRedrawEditor(tvPtr);
		Tcl_SetObjResult(interp, 
			Tcl_NewIntObj(Blt_TreeNodeId(entryPtr->node)));
		return TCL_OK;
	    }
	}
    }
    Tcl_SetObjResult(interp, Tcl_NewIntObj(-1));
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * IcursorOp --
 *
 *	Returns the numeric index of the given string. Indices can be
 *	one of the following:
 *
 *	"anchor"	Selection anchor.
 *	"end"		End of the label.
 *	"insert"	Insertion cursor.
 *	"sel.first"	First character selected.
 *	"sel.last"	Last character selected.
 *	@x,y		Index at X-Y screen coordinate.
 *	number		Returns the same number.
 *
 * Results:
 *	A standard Tcl result.  If the argument does not represent a
 *	valid label index, then TCL_ERROR is returned and the interpreter
 *	result will contain an error message.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
IcursorOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int textPos;

    if (GetIndexFromObj(interp, tvPtr, objv[3], &textPos) != TCL_OK) {
	return TCL_ERROR;
    }
    if (editPtr->columnPtr != NULL) {
	editPtr->insertPos = textPos;
	IndexToPointer(tvPtr);
	EventuallyRedrawEditor(tvPtr);
    }
    return TCL_OK;
}


/*
 *----------------------------------------------------------------------
 *
 * IndexOp --
 *
 *	Returns the numeric index of the given string. Indices can be
 *	one of the following:
 *
 *	"anchor"	Selection anchor.
 *	"end"		End of the label.
 *	"insert"	Insertion cursor.
 *	"sel.first"	First character selected.
 *	"sel.last"	Last character selected.
 *	@x,y		Index at X-Y screen coordinate.
 *	number		Returns the same number.
 *
 * Results:
 *	A standard Tcl result.  If the argument does not represent a
 *	valid label index, then TCL_ERROR is returned and the interpreter
 *	result will contain an error message.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
IndexOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int textPos;

    if (GetIndexFromObj(interp, tvPtr, objv[3], &textPos) != TCL_OK) {
	return TCL_ERROR;
    }
    if ((editPtr->columnPtr != NULL) && (editPtr->string != NULL)) {
	int nChars;

	nChars = Tcl_NumUtfChars(editPtr->string, textPos);
	Tcl_SetObjResult(interp, Tcl_NewIntObj(nChars));
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * InsertOp --
 *
 *	Add new characters to the label of an entry.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	New information gets added to editPtr;  it will be redisplayed
 *	soon, but not necessarily immediately.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
InsertOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    TreeViewEditor *editPtr = tvPtr->editPtr;
    int extra;
    int insertPos;
    char *string;

    if (editPtr->entryPtr == NULL) {
	return TCL_ERROR;
    }
    if (GetIndexFromObj(interp, tvPtr, objv[3], &insertPos) != TCL_OK) {
	return TCL_ERROR;
    }
    string = Tcl_GetString(objv[4]);
    extra = strlen(string);
    if (extra == 0) {	/* Nothing to insert. Move the cursor anyways. */
	editPtr->insertPos = insertPos;
    } else {
	InsertText(tvPtr, string, insertPos, extra);
    }
    return TCL_OK;
}

/*ARGSUSED*/
static int
SelectionAdjustOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    int textPos;
    int half1, half2;

    if (GetIndexFromObj(interp, tvPtr, objv[4], &textPos) != TCL_OK) {
	return TCL_ERROR;
    }
    half1 = (tvPtr->editPtr->selFirst + tvPtr->editPtr->selLast) / 2;
    half2 = (tvPtr->editPtr->selFirst + tvPtr->editPtr->selLast + 1) / 2;
    if (textPos < half1) {
	tvPtr->editPtr->selAnchor = tvPtr->editPtr->selLast;
    } else if (textPos > half2) {
	tvPtr->editPtr->selAnchor = tvPtr->editPtr->selFirst;
    }
    return SelectText(tvPtr, textPos);
}

/*ARGSUSED*/
static int
SelectionClearOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;	/* Not used. */
{
    if (tvPtr->editPtr->selFirst != -1) {
	tvPtr->editPtr->selFirst = tvPtr->editPtr->selLast = -1;
	EventuallyRedrawEditor(tvPtr);
    }
    return TCL_OK;
}

/*ARGSUSED*/
static int
SelectionFromOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    int textPos;

    if (GetIndexFromObj(interp, tvPtr, objv[4], &textPos) != TCL_OK) {
	return TCL_ERROR;
    }
    tvPtr->editPtr->selAnchor = textPos;
    return TCL_OK;
}

/*ARGSUSED*/
static int
SelectionPresentOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		
    int objc;			/* Not used. */
    Tcl_Obj *CONST *objv;	/* Not used. */
{
    int bool;

    bool = (tvPtr->editPtr->selFirst != -1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj(bool));
    return TCL_OK;
}

/*ARGSUSED*/
static int
SelectionRangeOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    int selFirst, selLast;

    if (GetIndexFromObj(interp, tvPtr, objv[4], &selFirst) != TCL_OK) {
	return TCL_ERROR;
    }
    if (GetIndexFromObj(interp, tvPtr, objv[5], &selLast) != TCL_OK) {
	return TCL_ERROR;
    }
    tvPtr->editPtr->selAnchor = selFirst;
    return SelectText(tvPtr, selLast);
}

/*ARGSUSED*/
static int
SelectionToOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;		/* Not used. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    int textPos;

    if (GetIndexFromObj(interp, tvPtr, objv[4], &textPos) != TCL_OK) {
	return TCL_ERROR;
    }
    return SelectText(tvPtr, textPos);
}


static Blt_OpSpec textSelectionOps[] =
{
    {"adjust", 1, (Blt_Op)SelectionAdjustOp, 5, 5, "index",},
    {"clear", 1, (Blt_Op)SelectionClearOp, 4, 4, "",},
    {"from", 1, (Blt_Op)SelectionFromOp, 5, 5, "index"},
    {"present", 1, (Blt_Op)SelectionPresentOp, 4, 4, ""},
    {"range", 1, (Blt_Op)SelectionRangeOp, 6, 6, "start end",},
    {"to", 1, (Blt_Op)SelectionToOp, 5, 5, "index"},
};

static int nTextSelectionOps = sizeof(textSelectionOps) / sizeof(Blt_OpSpec);

/*
 *	This procedure handles the individual options for text
 *	selections.  The selected text is designated by start and end
 *	indices into the text pool.  The selected segment has both a
 *	anchored and unanchored ends.  The following selection
 *	operations are implemented:
 *
 *	  "adjust"	- resets either the first or last index
 *			  of the selection.
 *	  "clear"	- clears the selection. Sets first/last
 *			  indices to -1.
 *	  "from"	- sets the index of the selection anchor.
 *	  "present"	- return "1" if a selection is available,
 *			  "0" otherwise.
 *	  "range"	- sets the first and last indices.
 *	  "to"		- sets the index of the un-anchored end.
 */
static int
SelectionOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;
    int objc;
    Tcl_Obj *CONST *objv;
{
    Blt_Op proc;
    int result;

    proc = Blt_GetOpFromObj(interp, nTextSelectionOps, textSelectionOps, 
	BLT_OP_ARG3, objc, objv, 0);
    if (proc == NULL) {
	return TCL_ERROR;
    }
    result = (*proc) (tvPtr, interp, objc, objv);
    return result;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewTextOp --
 *
 *	This procedure handles entry operations.
 *
 * Results:
 *	A standard Tcl result.
 *
 *----------------------------------------------------------------------
 */

static Blt_OpSpec textOps[] =
{
    {"apply", 1, (Blt_Op)ApplyOp, 3, 3, "",},
    {"cancel", 2, (Blt_Op)CancelOp, 3, 3, "",},
    {"cget", 2, (Blt_Op)CgetOp, 4, 4, "value",},
    {"configure", 2, (Blt_Op)ConfigureOp, 3, 0, "?option value...?",},
    {"delete", 1, (Blt_Op)DeleteOp, 4, 5, "first ?last?"},
    {"get", 1, (Blt_Op)GetOp, 5, 6, "?-root? x y",},
    {"icursor", 2, (Blt_Op)IcursorOp, 4, 4, "index"},
    {"index", 3, (Blt_Op)IndexOp, 4, 4, "index"},
    {"insert", 3, (Blt_Op)InsertOp, 5, 5, "index string"},
    {"selection", 3, (Blt_Op)SelectionOp, 3, 0, "args"},
};
static int nTextOps = sizeof(textOps) / sizeof(Blt_OpSpec);

int
Blt_TreeViewTextOp(tvPtr, interp, objc, objv)
    TreeView *tvPtr;
    Tcl_Interp *interp;
    int objc;
    Tcl_Obj *CONST *objv;
{
    Blt_Op proc;
    int result;

    proc = Blt_GetOpFromObj(interp, nTextOps, textOps, BLT_OP_ARG2, objc, 
	objv, 0);
    if (proc == NULL) {
	return TCL_ERROR;
    }
    result = (*proc) (tvPtr, interp, objc, objv);
    return result;
}

#endif
