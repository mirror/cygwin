/*
 * bltTreeViewStyle.c --
 *
 *	This module implements styles for treeview widget cells.
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
#include "bltList.h"
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#define STYLE_TEXT_ENTRY	0
#define STYLE_OPTION_MENU	1
#define STYLE_CHECK_BOX		2

#define DEF_TEXT_ENTRY_SIDE		"left"
#define DEF_TEXT_ENTRY_KEY		(char *)NULL
#define DEF_TEXT_ENTRY_ICON		(char *)NULL
#define DEF_TEXT_ENTRY_BACKGROUND	RGB_WHITE
#define DEF_TEXT_ENTRY_FG_COLOR		STD_COLOR_NORMAL_FG
#define DEF_TEXT_ENTRY_FG_MONO		STD_MONO_NORMAL_FG
#define DEF_TEXT_ENTRY_FONT		STD_FONT
#define DEF_TEXT_ENTRY_HIGHLIGHT_BG_COLOR STD_COLOR_NORMAL_BG
#define DEF_TEXT_ENTRY_HIGHLIGHT_FG_COLOR STD_COLOR_NORMAL_FG
#define DEF_TEXT_ENTRY_NORMAL_BG_COLOR 	STD_COLOR_NORMAL_BG
#define DEF_TEXT_ENTRY_NORMAL_FG_COLOR 	STD_COLOR_NORMAL_FG

extern Blt_CustomOption bltTreeViewImagesOption;

static StyleCreateProc CreateTextEntry, CreateCheckBox, CreateOptionMenu;
static StyleFreeProc FreeTextEntry, FreeCheckBox, FreeOptionMenu;
static StyleDrawProc DrawTextEntry, DrawCheckBox, DrawOptionMenu;
static StyleConfigProc ConfigTextEntry, ConfigCheckBox, ConfigOptionMenu;

typedef struct {
    int refCount;		/* Usage reference count. */
    unsigned int flags;
    char *name;			
    TreeViewStyleClass *classPtr; /* Class-specific routines to manage style. */
    Blt_HashEntry *hashPtr;

    XColor *fgColor;		/* Normal foreground color of cell. */
    XColor *bgColor;		/* Normal background color of cell. */
    XColor *highlightFgColor;	/* Foreground color of cell when
				 * highlighted. */
    XColor *highlightBgColor;	/* Background color of cell when
				 * highlighted. */
    Tk_Font font;	
    TreeViewImage icon;		/* If non-NULL, is a Tk_Image to be drawn
				 * in the cell. */
    int side;			/* Position of the text in relation to
				 * the icon.  */
    Blt_TreeKey key;		/* Actual data resides in this data value */
} TextEntry;

static Blt_ConfigSpec textEntrySpecs[] =
{
    {BLT_CONFIG_BORDER, "-background", "background", "Background",
	DEF_TEXT_ENTRY_NORMAL_BG_COLOR, Blt_Offset(TextEntry, bgColor), 0},
    {BLT_CONFIG_SYNONYM, "-bg", "background", (char *)NULL, (char *)NULL, 
	0, 0},
    {BLT_CONFIG_SYNONYM, "-fg", "foreground", (char *)NULL, (char *)NULL, 
	0, 0},
    {BLT_CONFIG_FONT, "-font", "font", "Font",
	DEF_TEXT_ENTRY_FONT, Blt_Offset(TextEntry, font), 0},
    {BLT_CONFIG_COLOR, "-foreground", "foreground", "Foreground",
	DEF_TEXT_ENTRY_NORMAL_FG_COLOR, Blt_Offset(TextEntry, fgColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-highlightbackground", "highlightBackground",
	"HighlightBackground", DEF_TEXT_ENTRY_HIGHLIGHT_BG_COLOR, 
        Blt_Offset(TextEntry, highlightBgColor), BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-highlightforeground", "highlightForeground", 
	"HighlightForeground", DEF_TEXT_ENTRY_HIGHLIGHT_FG_COLOR, 
	 Blt_Offset(TextEntry, highlightFgColor), 0},
    {BLT_CONFIG_CUSTOM, "-icon", "icon", "Icon",
	DEF_TEXT_ENTRY_ICON, Blt_Offset(TextEntry, icon), 
	BLT_CONFIG_NULL_OK, &bltTreeViewImagesOption},
    {BLT_CONFIG_STRING, "-key", "key", "key",
	DEF_TEXT_ENTRY_KEY, Blt_Offset(TextEntry, key), 
	BLT_CONFIG_NULL_OK, 0},
    {BLT_CONFIG_SIDE, "-side", "side", "side",
	DEF_TEXT_ENTRY_SIDE, Tk_Offset(TextEntry, side),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL,
	(char *)NULL, 0, 0}
};

typedef struct {
    int refCount;		/* Usage reference count. */
    unsigned int flags;
    char *name;			
    TreeViewStyleClass *classPtr; /* Class-specific routines to manage style. */
    Blt_HashEntry *hashPtr;

    XColor *fgColor;		/* Text color of the cell. */
    Tk_3DBorder border;		/* Background color of the cell. */
    TreeViewImage icon;		/* If non-NULL, is a Tk_Image to be drawn
				 * in the cell. */
    int anchor;			/* Position of the text in relation to
				 * the icon.  */
    Blt_TreeKey dataKey;	/* Actual data resides in this data value */

    char *choices;		/* Choices possible. */
    char *defChoice;		/* Default choice. */
    int useScrollbar;
    int scrollWidth;
    int button;
} OptionMenu;

static Blt_ConfigSpec optionMenuSpecs[] =
{
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL,
	(char *)NULL, 0, 0}
};

typedef struct {
    int refCount;		/* Usage reference count. */
    unsigned int flags;		/* Contains style type and update flags. */
    char *name;			/* Instance name. */
    TreeViewStyleClass *classPtr; /* Class-specific routines to manage style. */
    Blt_HashEntry *hashPtr;	/* If non-NULL, points to the hash
				 * table entry for the style.  A style
				 * that's been deleted, but still in
				 * use (non-zero reference count) will
				 * have no hash table entry.
				 */
    XColor *fgColor;		/* Text color of the cell. */
    Tk_3DBorder border;		/* Background color of the cell. */
    TreeViewImage icon;		/* If non-NULL, is a Tk_Image to be drawn
				 * in the cell. */
    int anchor;			/* Position of the text in relation to
				 * the icon.  */
    Blt_TreeKey dataKey;	/* Actual data resides in this data value */

    /* Checkbox specific fields. */
    char *onValue;
    char *offValue;
} CheckBox;

static Blt_ConfigSpec checkBoxSpecs[] =
{
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL,
	(char *)NULL, 0, 0}
};

static TreeViewStyleClass textEntryClass = {
    textEntrySpecs,
    ConfigTextEntry,
    DrawTextEntry,
    FreeTextEntry,
};

static TreeViewStyleClass checkBoxClass = {
    checkBoxSpecs,
    ConfigCheckBox,
    DrawCheckBox,
    FreeCheckBox,
};

static TreeViewStyleClass optionMenuClass = {
    optionMenuSpecs,
    ConfigOptionMenu,
    DrawOptionMenu,
    FreeOptionMenu,
};

static TreeViewStyle *
CreateTextEntry(tvPtr)
    TreeView *tvPtr;
{
    TextEntry *textEntryPtr;

    textEntryPtr = Blt_Calloc(1, sizeof(TextEntry));
    assert(textEntryPtr);
    textEntryPtr->classPtr = &textEntryClass;
    textEntryPtr->side = SIDE_LEFT;
    return (TreeViewStyle *)textEntryPtr;
}

static void
ConfigTextEntry(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
}

static void
DrawTextEntry(tvPtr, drawable, entryPtr, stylePtr, valuePtr, x, y)
    TreeView *tvPtr;
    Drawable drawable;
    TreeViewEntry *entryPtr;
    TreeViewStyle *stylePtr;
    TreeViewValue *valuePtr;
    int x, y;
{
    TreeViewColumn *columnPtr = valuePtr->columnPtr;

    if (valuePtr->image != NULL) {
	Tk_RedrawImage(TreeViewImageData(valuePtr->image), 0, 0, 
	       valuePtr->width, valuePtr->height, drawable, x, y);
    } else {
	TextStyle ts;
	XColor *color;

	if (entryPtr->color != NULL) {
	    XSetForeground(tvPtr->display, columnPtr->gc, 
			   entryPtr->color->pixel);
	    color = entryPtr->color;
	} else {
	    color = columnPtr->fgColor;
	}
	Blt_SetDrawTextStyle(&ts, columnPtr->font, columnPtr->gc, color, 
		tvPtr->selFgColor, entryPtr->shadow.color, 0.0, TK_ANCHOR_NW,
	    TK_JUSTIFY_LEFT, 0, entryPtr->shadow.offset);
	Blt_DrawTextLayout(tvPtr->tkwin, drawable, valuePtr->textPtr, 
		&ts, x, y);
	if (entryPtr->color != NULL) {
	    XSetForeground(tvPtr->display, valuePtr->columnPtr->gc, 
		  columnPtr->fgColor->pixel);
	}
    }
}

static void
FreeTextEntry(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
}

static void
MeasureTextEntry(tvPtr, stylePtr, valuePtr, widthPtr, heightPtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
    TreeViewValue *valuePtr;
    int *widthPtr, *heightPtr;
{
}

static TreeViewStyle *
CreateCheckBox(tvPtr)
     TreeView *tvPtr;
{
    CheckBox *checkBoxPtr;

    checkBoxPtr = Blt_Malloc(sizeof(CheckBox));
    checkBoxPtr->classPtr = &checkBoxClass;
    return (TreeViewStyle *)checkBoxPtr;
}

static void
ConfigCheckBox(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
}

static void
DrawCheckBox(tvPtr, drawable, entryPtr, stylePtr, valuePtr, x, y)
    TreeView *tvPtr;
    Drawable drawable;
    TreeViewEntry *entryPtr;
    TreeViewStyle *stylePtr;
    TreeViewValue *valuePtr;
    int x, y;
{
}

static void
FreeCheckBox(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
}

static void
MeasureCheckBox(tvPtr, stylePtr, valuePtr, widthPtr, heightPtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
    TreeViewValue *valuePtr;
    int *widthPtr, *heightPtr;
{
}

static TreeViewStyle *
CreateOptionMenu(tvPtr)
     TreeView *tvPtr;
{
    OptionMenu *optionMenuPtr;

    optionMenuPtr = Blt_Malloc(sizeof(OptionMenu));
    optionMenuPtr->classPtr = &optionMenuClass;
    return (TreeViewStyle *)optionMenuPtr;
}

static void
ConfigOptionMenu(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
}

static void
DrawOptionMenu(tvPtr, drawable, entryPtr, stylePtr, valuePtr, x, y)
    TreeView *tvPtr;
    Drawable drawable;
    TreeViewEntry *entryPtr;
    TreeViewStyle *stylePtr;
    TreeViewValue *valuePtr;
    int x, y;
{
}

static void
FreeOptionMenu(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
}

static void
MeasureOptionMenu(tvPtr, stylePtr, valuePtr, widthPtr, heightPtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
    TreeViewValue *valuePtr;
    int *widthPtr, *heightPtr;
{
}

TreeViewStyle *
Blt_TreeViewGetStyle(interp, tvPtr, objPtr, stylePtrPtr)
    Tcl_Interp *interp;
    TreeView *tvPtr;
    Tcl_Obj *objPtr;
    TreeViewStyle *stylePtrPtr;
{
    Blt_HashEntry *hPtr;
    char *string;
    
    string = Tcl_GetString(objPtr);
    hPtr = Blt_FindHashEntry(&tvPtr->styleTable, string);
    if (hPtr == NULL) {
	return NULL;
    }
    return Blt_GetHashValue(hPtr);
}

TreeViewStyle *
Blt_TreeViewCreateStyle(tvPtr, type, name)
     TreeView *tvPtr;		/* TreeView widget. */
     int type;			/* Type of style: either
				 * STYLE_TEXT_ENTRY,
				 * STYLE_OPTION_MENU, or
				 * STYLE_CHECK_BOX */
    char *name;			/* Name of the new style. */
{    
    TreeViewStyle *stylePtr;

    /* Create the new marker based upon the given type */
    switch (type) {
    case STYLE_TEXT_ENTRY:
	stylePtr = CreateTextEntry(tvPtr);
	break;
    case STYLE_OPTION_MENU:
	stylePtr = CreateOptionMenu(tvPtr);
	break;
    case STYLE_CHECK_BOX:
	stylePtr = CreateCheckBox(tvPtr);
	break;
    default:
	return NULL;
    }
    assert(stylePtr);
    stylePtr->name = Blt_Strdup(name);
    stylePtr->flags = type;
    stylePtr->refCount = 0;
    return stylePtr;
}

void
Blt_TreeViewFreeStyle(tvPtr, stylePtr)
    TreeView *tvPtr;
    TreeViewStyle *stylePtr;
{
    stylePtr->refCount--;
    /* Remove the style from the hash table so that it's name can be used.*/
    if (stylePtr->hashPtr != NULL) {
	Blt_DeleteHashEntry(&tvPtr->styleTable, stylePtr->hashPtr);
	stylePtr->hashPtr = NULL; 
    } 
    /* If no cell is using the style, remove it.*/
    if (stylePtr->refCount <= 0) {
	(*stylePtr->classPtr->freeProc)(tvPtr, stylePtr); 
    } 
}

#endif /* NO_TREEVIEW */
