/* 
 * tkTableCell.c --
 *
 *	This module implements cell oriented functions for table
 *	widgets.
 *
 * Copyright (c) 1998 Jeffrey Hobbs
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 */

#include "tkTable.h"

static int	TableSortCompareProc _ANSI_ARGS_((CONST VOID *first,
						  CONST VOID *second));

/*
 *----------------------------------------------------------------------
 *
 * TableCellCoords --
 *	Takes a row,col pair in real coords and finds it position
 *	on the virtual screen.
 *
 * Results:
 *	The virtual x, y, width, and height of the cell
 *	are placed in the pointers.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
TableCellCoords(Table *tablePtr, int row, int col,
		int *x, int *y, int *width, int *height)
{
  if (tablePtr->rows <= 0 || tablePtr->cols <= 0) {
    *width = *height = *x = *y = 0;
    return;
  }
  /* real coords required, always should be passed acceptable values,
   * but this is a possible seg fault otherwise */
  row = MIN(tablePtr->rows-1, MAX(0, row));
  col = MIN(tablePtr->cols-1, MAX(0, col));
  *width = tablePtr->colPixels[col];
  *height = tablePtr->rowPixels[row];
  *x = tablePtr->highlightWidth + tablePtr->colStarts[col] - 
    ((col < tablePtr->titleCols) ? 0 : tablePtr->colStarts[tablePtr->leftCol]
     - tablePtr->colStarts[tablePtr->titleCols]);
  *y = tablePtr->highlightWidth + tablePtr->rowStarts[row] -
    ((row < tablePtr->titleRows) ? 0 : tablePtr->rowStarts[tablePtr->topRow]
     - tablePtr->rowStarts[tablePtr->titleRows]);
}

/*
 *----------------------------------------------------------------------
 *
 * TableCellVCoords --
 *	Takes a row,col pair in real coords and finds it position
 *	on the actual screen.  The full arg specifies whether
 *	only 100% visible cells should be considered visible.
 *
 * Results:
 *	The x, y, width, and height of the cell are placed in the pointers,
 *	depending upon visibility of the cell.
 *	Returns 0 for hidden and 1 for visible cells.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
int
TableCellVCoords(Table *tablePtr, int row, int col,
		 int *rx, int *ry, int *rw, int *rh, int full)
{
  if (tablePtr->tkwin == NULL) return 0;

  if ((row < tablePtr->topRow && row >= tablePtr->titleRows) ||
      (col < tablePtr->leftCol && col >= tablePtr->titleCols)) {
    /* hiding in "dead" space between title areas and visible cells */
    *rx = 0; *ry = 0; *rw = 0; *rh = 0;
    return 0;
  } else {
    int x, y, w, h, w0, h0, hl = tablePtr->highlightWidth;
    /* Necessary to use separate vars in case dummies are passed in */
    TableCellCoords(tablePtr, row, col, &x, &y, &w, &h);
    *rx = x; *ry = y;
    if (full) {
      w0 = w; h0 = h;
    } else {
      /* if we don't care about seeing the whole thing, then
       * make sure we at least see a pixel worth */
      w0 = h0 = 1;
    }
    /* Is the cell visible? */
    if (x<hl || y<hl || (x+w0)>(Tk_Width(tablePtr->tkwin)-hl)
	|| (y+h0)>(Tk_Height(tablePtr->tkwin)-hl)) {
      /* definitely off the screen */
      *rw = *rh = 0;
      return 0;
    } else {
      if (full) {
	*rw = w; *rh = h;
      } else {
	*rw = MIN(w, Tk_Width(tablePtr->tkwin)-hl-x);
	*rh = MIN(h, Tk_Height(tablePtr->tkwin)-hl-y);
      }
      return 1;
    }
  }
}

/*
 *----------------------------------------------------------------------
 *
 * TableWhatCell --
 *	Takes a x,y screen coordinate and determines what cell contains.
 *	that point.  This will return cells that are beyond the right/bottom
 *	edge of the viewable screen.
 *
 * Results:
 *	The row,col of the cell are placed in the pointers.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
TableWhatCell(register Table *tablePtr, int x, int y, int *row, int *col)
{
  int i;
  x = MAX(0, x); y = MAX(0, y);
  /* Adjust for table's global highlightthickness border */
  x -= tablePtr->highlightWidth;
  y -= tablePtr->highlightWidth;
  /* Adjust the x coord if not in the column titles to change display coords
   * into internal coords */
  x += (x < tablePtr->colStarts[tablePtr->titleCols]) ? 0 :
    tablePtr->colStarts[tablePtr->leftCol] -
    tablePtr->colStarts[tablePtr->titleCols];
  y += (y < tablePtr->rowStarts[tablePtr->titleRows]) ? 0 :
    tablePtr->rowStarts[tablePtr->topRow] -
    tablePtr->rowStarts[tablePtr->titleRows];
  x = MIN(x, tablePtr->maxWidth-1);
  y = MIN(y, tablePtr->maxHeight-1);
  for (i = 1; x >= tablePtr->colStarts[i]; i++);
  *col = i - 1;
  for (i = 1; y >= tablePtr->rowStarts[i]; i++);
  *row = i - 1;
}

/*
 *----------------------------------------------------------------------
 *
 * TableAtBorder --
 *	Takes a x,y screen coordinate and determines if that point is
 *	over a border.
 *
 * Results:
 *	The left/top row,col corresponding to that point are placed in
 *	the pointers.  The number of borders (+1 for row, +1 for col)
 *	hit is returned.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */
int
TableAtBorder(Table * tablePtr, int x, int y, int *row, int *col)
{
  int i, borders = 2, bd = tablePtr->borderWidth;
  int dbd = 2*bd;
  x = MAX(0, x); y = MAX(0, y);
  x -= tablePtr->highlightWidth; y -= tablePtr->highlightWidth;
  /* Adjust the x coord if not in the column titles to change display coords
   * into internal coords */
  x += (x < tablePtr->colStarts[tablePtr->titleCols]) ? 0 :
    tablePtr->colStarts[tablePtr->leftCol] -
    tablePtr->colStarts[tablePtr->titleCols];
  y += (y < tablePtr->rowStarts[tablePtr->titleRows]) ? 0 :
    tablePtr->rowStarts[tablePtr->topRow] -
    tablePtr->rowStarts[tablePtr->titleRows];
  x = MIN(x, tablePtr->maxWidth - 1);
  y = MIN(y, tablePtr->maxHeight - 1);
  for (i = 1; i <= tablePtr->cols && x+dbd >= tablePtr->colStarts[i]; i++);
  if (x > tablePtr->colStarts[--i]+bd) {
    borders--;
    *col = -1;
  } else {
    *col = (--i < tablePtr->leftCol && i >= tablePtr->titleCols) ?
      tablePtr->titleCols-1 : i;
  }
  for (i = 1; i <= tablePtr->rows && y+dbd >= tablePtr->rowStarts[i]; i++);
  if (y > tablePtr->rowStarts[--i]+bd) {
    borders--;
    *row = -1;
  } else {
    *row = (--i < tablePtr->topRow && i >= tablePtr->titleRows) ?
      tablePtr->titleRows-1 : i;
  }
  return borders;
}

/*
 *----------------------------------------------------------------------
 *
 * TableGetCellValue --
 *	Takes a row,col pair in user coords and returns the value for
 *	that cell.  This varies depending on what data source the
 *	user has selected.
 *
 * Results:
 *	The value of the cell is returned.  The return value is VOLATILE
 *	(do not free).
 *
 * Side effects:
 *	The value will be cached if caching is turned on.
 *
 *----------------------------------------------------------------------
 */
char *
TableGetCellValue(Table *tablePtr, int r, int c)
{
  register Tcl_Interp *interp = tablePtr->interp;
  char *result = NULL;
  char buf[INDEX_BUFSIZE];
  Tcl_HashEntry *entryPtr = NULL;
  int new = 1;

  TableMakeArrayIndex(r, c, buf);

  if (tablePtr->caching) {
    /* if we are caching, let's see if we have the value cached */
    entryPtr = Tcl_CreateHashEntry(tablePtr->cache, buf, &new);
    if (!new) {
      result = (char *) Tcl_GetHashValue(entryPtr);
      return result?result:"";
    }
  }
  if (tablePtr->command && tablePtr->useCmd) {
    Tcl_DString script;
    Tcl_DStringInit(&script);
    ExpandPercents(tablePtr, tablePtr->command, r, c, "", (char *)NULL,
		   0, &script, 0);
    if (Tcl_GlobalEval(interp, Tcl_DStringValue(&script)) == TCL_ERROR) {
      tablePtr->useCmd = 0;
      tablePtr->dataSource &= ~DATA_COMMAND;
      if (tablePtr->arrayVar)
	tablePtr->dataSource |= DATA_ARRAY;
      Tcl_AddErrorInfo(interp, "\n\t(in command executed by table)");
      Tcl_AddErrorInfo(interp, Tcl_DStringValue(&script));
      Tk_BackgroundError(interp);
      TableInvalidateAll(tablePtr, 0);
    } else {
      result = Tcl_GetStringResult(interp);
    }
    Tcl_FreeResult(interp);
    Tcl_DStringFree(&script);
  } else if (tablePtr->arrayVar) {
    result = Tcl_GetVar2(interp, tablePtr->arrayVar, buf, TCL_GLOBAL_ONLY);
  }
  if (result == NULL)
    result = "";
  if (tablePtr->caching && entryPtr != NULL) {
    /* if we are caching, make sure we cache the returned value */
    /* entryPtr will have been set from above, but check to make sure
     * someone didn't change caching during -command evaluation */
    char *val;
    val = (char *)ckalloc(strlen(result)+1);
    strcpy(val, result);
    Tcl_SetHashValue(entryPtr, val);
  }
  return result;
}

/*
 *----------------------------------------------------------------------
 *
 * TableSetCellValue --
 *	Takes a row,col pair in user coords and saves the given value for
 *	that cell.  This varies depending on what data source the
 *	user has selected.
 *
 * Results:
 *	Returns TCL_ERROR or TCL_OK, depending on whether an error
 *	occured during set (ie: during evaluation of -command).
 *
 * Side effects:
 *	If the value is NULL (empty string), it will be unset from
 *	an array rather than set to the empty string.
 *
 *----------------------------------------------------------------------
 */
int
TableSetCellValue(Table *tablePtr, int r, int c, char *value)
{
  register Tcl_Interp *interp = tablePtr->interp;
  char buf[INDEX_BUFSIZE];
  int code = TCL_OK;

  TableMakeArrayIndex(r, c, buf);

  if (tablePtr->state == STATE_DISABLED)
    return code;
  if (tablePtr->command && tablePtr->useCmd) {
    Tcl_DString script;

    Tcl_DStringInit(&script);
    ExpandPercents(tablePtr, tablePtr->command, r, c, value, (char *)NULL,
		   1, &script, 0);
    if (Tcl_GlobalEval(interp, Tcl_DStringValue(&script)) == TCL_ERROR) {
      /* An error resulted.  Prevent further triggering of the command
       * and set up the error message. */
      tablePtr->useCmd = 0;
      tablePtr->dataSource &= ~DATA_COMMAND;
      if (tablePtr->arrayVar)
	tablePtr->dataSource |= DATA_ARRAY;
      Tcl_AddErrorInfo(interp, "\n\t(in command executed by table)");
      Tk_BackgroundError(interp);
      code = TCL_ERROR;
    }
    Tcl_SetResult(interp, (char *) NULL, TCL_STATIC);
    Tcl_DStringFree(&script);
  } else if (tablePtr->arrayVar) {
    if (value == NULL || *value == '\0') {
      Tcl_UnsetVar2(interp, tablePtr->arrayVar, buf, TCL_GLOBAL_ONLY);
    } else if (Tcl_SetVar2(interp, tablePtr->arrayVar, buf, value,
			   TCL_GLOBAL_ONLY|TCL_LEAVE_ERR_MSG) == NULL) {
      code = TCL_ERROR;
    }
  }
  if (tablePtr->caching && code == TCL_OK) {
    Tcl_HashEntry *entryPtr;
    int new;
    char *val;

    val = (char *)ckalloc(strlen(value)+1);
    strcpy(val, value);
    entryPtr = Tcl_CreateHashEntry(tablePtr->cache, buf, &new);
    Tcl_SetHashValue(entryPtr, val);
  }
  return code;
}

/*
 *----------------------------------------------------------------------
 *
 * TableSortCompareProc --
 *	This procedure is invoked by qsort to determine the proper
 *	ordering between two elements.
 *
 * Results:
 *	< 0 means first is "smaller" than "second", > 0 means "first"
 *	is larger than "second", and 0 means they should be treated
 *	as equal.
 *
 * Side effects:
 *	None, unless a user-defined comparison command does something
 *	weird.
 *
 *----------------------------------------------------------------------
 */
static int
TableSortCompareProc(first, second)
    CONST VOID *first, *second;		/* Elements to be compared. */
{
    int r1, c1, r2, c2;
    char *firstString = *((char **) first);
    char *secondString = *((char **) second);

    /* This doesn't account for badly formed indices */
    sscanf(firstString, "%d,%d", &r1, &c1);
    sscanf(secondString, "%d,%d", &r2, &c2);
    if (r1 > r2)
      return 1;
    else if (r1 < r2)
      return -1;
    else if (c1 > c2)
      return 1;
    else if (c1 < c2)
      return -1;
    return 0;
}

/*
 *----------------------------------------------------------------------
 *
 * TableCellSort --
 *	Sort a list of table cell elements (of form row,col)
 *
 * Results:
 *	Returns the sorted list of elements.  Because Tcl_Merge allocs
 *	the space for result, it must later be ckfree'd by caller.
 *
 * Side effects:
 *	Behaviour undefined for ill-formed input list of elements.
 *
 *----------------------------------------------------------------------
 */
char *
TableCellSort(Table *tablePtr, char *str)
{
  int listArgc;
  char **listArgv;
  char *result;

  if (Tcl_SplitList(tablePtr->interp, str, &listArgc, &listArgv) != TCL_OK)
    return str;
  qsort((VOID *) listArgv, (size_t) listArgc, sizeof (char *),
	TableSortCompareProc);
  result = Tcl_Merge(listArgc, listArgv);
  ckfree((char *) listArgv);
  return result;
}

/*
 *----------------------------------------------------------------------
 *
 * TableGetIcursor --
 *	Parses the argument as an index into the active cell string.
 *	Recognises 'end', 'insert' or an integer.  Constrains it to the
 *	size of the buffer.  This acts like a "SetIcursor" when *posn is NULL.
 *
 * Results:
 *	If (posn != NULL), then it gets the cursor position.
 *
 * Side effects:
 *	Can move cursor position.
 *
 *----------------------------------------------------------------------
 */
int
TableGetIcursor(Table *tablePtr, char *arg, int *posn)
{
  int tmp, len;
#if (TK_MINOR_VERSION > 0)
  len = Tcl_NumUtfChars(tablePtr->activeBuf, strlen(tablePtr->activeBuf));
#else
  len = strlen(tablePtr->activeBuf);
#endif
  /* ensure icursor didn't get out of sync */
  if (tablePtr->icursor > len) tablePtr->icursor = len;
  /* is this end */
  if (strcmp(arg, "end") == 0) {
    tmp = len;
  } else if (strcmp(arg, "insert") == 0) {
    tmp = tablePtr->icursor;
  } else {
    if (Tcl_GetInt(tablePtr->interp, arg, &tmp) != TCL_OK) {
      return TCL_ERROR;
    }
    tmp = MIN(MAX(0, tmp), len);
  }
  if (posn)
    *posn = tmp;
  else
    tablePtr->icursor = tmp;
  return TCL_OK;
}

/*
 *--------------------------------------------------------------
 *
 * TableGetIndex --
 *	Parse an index into a table and return either its value
 *	or an error.
 *
 * Results:
 *	A standard Tcl result.  If all went well, then *row,*col is
 *	filled in with the index corresponding to string.  If an
 *	error occurs then an error message is left in interp result.
 *	The index returned is in user coords.
 *
 * Side effects:
 *	Sets row,col index to an appropriately constrained user index.
 *
 *--------------------------------------------------------------
 */
int
TableGetIndex(tablePtr, str, row_p, col_p)
     register Table *tablePtr;	/* Table for which the index is being
				 * specified. */
     char *str;			/* Symbolic specification of cell in table. */
     int *row_p;		/* Where to store converted row. */
     int *col_p;		/* Where to store converted col. */
{
  int r, c, len = strlen(str);

  /*
   * Note that all of these values will be adjusted by row/ColOffset
   */
  if (str[0] == '@') {				/* @x,y coordinate */ 
    int x, y;
    char *p, *end;

    p = str+1;
    x = strtol(p, &end, 0);
    if ((end == p) || (*end != ','))
      goto IndexError;
    p = end+1;
    y = strtol(p, &end, 0);
    if ((end == p) || (*end != '\0'))
      goto IndexError;
    TableWhatCell(tablePtr, x, y, &r, &c);
    r += tablePtr->rowOffset;
    c += tablePtr->colOffset;
  } else if (sscanf(str, "%d,%d", &r,&c) == 2) {
    char buf[INDEX_BUFSIZE];
    TableMakeArrayIndex(r, c, buf);
    /* Make sure it won't work for "2,3extrastuff" */
    if (strcmp(buf, str))
      goto IndexError;
    /* ensure appropriate user index */
    r = MIN(MAX(tablePtr->rowOffset,r),tablePtr->rows-1+tablePtr->rowOffset);
    c = MIN(MAX(tablePtr->colOffset,c),tablePtr->cols-1+tablePtr->colOffset);
  } else if (len > 1 && strncmp(str, "active", len) == 0 ) {	/* active */
    if (tablePtr->flags & HAS_ACTIVE) {
      r = tablePtr->activeRow+tablePtr->rowOffset;
      c = tablePtr->activeCol+tablePtr->colOffset;
    } else {
      Tcl_AppendResult(tablePtr->interp, "no \"active\" cell in table", NULL);
      return TCL_ERROR;
    }
  } else if (len > 1 && strncmp(str, "anchor", len) == 0) {	/* anchor */
    if (tablePtr->flags & HAS_ANCHOR) {
      r = tablePtr->anchorRow+tablePtr->rowOffset;
      c = tablePtr->anchorCol+tablePtr->colOffset;
    } else {
      Tcl_AppendResult(tablePtr->interp, "no \"anchor\" cell in table", NULL);
      return TCL_ERROR;
    }
  } else if (strncmp(str, "end", len) == 0) {		/* end */
    r = tablePtr->rows-1+tablePtr->rowOffset;
    c = tablePtr->cols-1+tablePtr->colOffset;
  } else if (strncmp(str, "origin", len) == 0) {	/* origin */
    r = tablePtr->titleRows+tablePtr->rowOffset;
    c = tablePtr->titleCols+tablePtr->colOffset;
  } else if (strncmp(str, "topleft", len) == 0) {	/* topleft */
    r = tablePtr->topRow+tablePtr->rowOffset;
    c = tablePtr->leftCol+tablePtr->colOffset;
  } else if (strncmp(str, "bottomright", len) == 0) {	/* bottomright */
    TableGetLastCell(tablePtr, &r, &c);
    r += tablePtr->rowOffset;
    c += tablePtr->colOffset;
  } else {
  IndexError:
    Tcl_AppendResult(tablePtr->interp, "bad table index \"",
		     str, "\"", (char *)NULL);
    return TCL_ERROR;
  }

  /* Note: values are expected to be properly constrained 
   * as a user index by this point */
  if (row_p) *row_p = r;
  if (col_p) *col_p = c;
  return TCL_OK;
}

