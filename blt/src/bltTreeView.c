/*
 * bltTreeView.c --
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

/*
 * TODO:
 *
 * BUGS:
 *   1.  "open" operation should change scroll offset so that as many
 *	 new entries (up to half a screen) can be seen.
 *   2.  "open" needs to adjust the scrolloffset so that the same entry
 *	 is seen at the same place.
 */

#include "bltInt.h"

#ifndef NO_TREEVIEW

#include "bltTreeView.h"

#define BUTTON_IPAD		1
#define BUTTON_SIZE		7
#define COLUMN_PAD		2
#define FOCUS_WIDTH		1
#define ICON_PADX		2
#define ICON_PADY		1
#define INSET_PAD		0
#define LABEL_PADX		3
#define LABEL_PADY		0

#define ODD(x)			((x) | 0x01)

#include <X11/Xutil.h>
#include <X11/Xatom.h>

#define DEF_ICON_WIDTH		16
#define DEF_ICON_HEIGHT		16

static Tcl_FreeInternalRepProc FreeEntryInternalRep;
static Tcl_UpdateStringProc UpdateStringOfEntry;
static Tcl_SetFromAnyProc SetEntryObjFromAny;

static Tcl_ObjType entryObjType = {
    "BLT TreeView Entry",
    FreeEntryInternalRep,	/* Called when an object is freed. */
    NULL,			/* Copies an internal representation 
				 * from one object to another. */
    UpdateStringOfEntry,	/* Creates string representation from
				 * an object's internal representation. */
    SetEntryObjFromAny,		/* Creates valid internal representation 
				 * from an object's string representation. */
};

static Blt_TreeApplyProc DeleteApplyProc;
static Blt_TreeApplyProc CreateApplyProc;

extern Blt_CustomOption bltTreeViewDataOption;

static Blt_OptionParseProc ObjToTree;
static Blt_OptionPrintProc TreeToObj;
static Blt_OptionFreeProc FreeTree;
static Blt_CustomOption treeOption =
{
    ObjToTree, TreeToObj, FreeTree, NULL,
};

static Blt_OptionParseProc ObjToImages;
static Blt_OptionPrintProc ImagesToObj;
static Blt_OptionFreeProc FreeImages;
Blt_CustomOption bltTreeViewImagesOption =
{
    /* Contains a pointer to the widget that's currently being
     * configured.  This is used in the custom configuration parse
     * routine for images.  */
    ObjToImages, ImagesToObj, FreeImages, NULL,
};

static Blt_OptionParseProc ObjToButton;
static Blt_OptionPrintProc ButtonToObj;
static Blt_CustomOption buttonOption = {
    ObjToButton, ButtonToObj, NULL, NULL,
};

static Blt_OptionParseProc ObjToUid;
static Blt_OptionPrintProc UidToObj;
static Blt_OptionFreeProc FreeUid;
Blt_CustomOption bltTreeViewUidOption = {
    ObjToUid, UidToObj, FreeUid, NULL,
};

static Blt_OptionParseProc ObjToScrollmode;
static Blt_OptionPrintProc ScrollmodeToObj;
static Blt_CustomOption scrollmodeOption = {
    ObjToScrollmode, ScrollmodeToObj, NULL, NULL,
};

static Blt_OptionParseProc ObjToSelectmode;
static Blt_OptionPrintProc SelectmodeToObj;
static Blt_CustomOption selectmodeOption = {
    ObjToSelectmode, SelectmodeToObj, NULL, NULL,
};

static Blt_OptionParseProc ObjToSeparator;
static Blt_OptionPrintProc SeparatorToObj;
static Blt_OptionFreeProc FreeSeparator;
static Blt_CustomOption separatorOption = {
    ObjToSeparator, SeparatorToObj, FreeSeparator, NULL,
};

static Blt_OptionParseProc ObjToLabel;
static Blt_OptionPrintProc LabelToObj;
static Blt_OptionFreeProc FreeLabel;
static Blt_CustomOption labelOption =
{
    ObjToLabel, LabelToObj, FreeLabel, NULL,
};


#define DEF_BUTTON_ACTIVE_BG_COLOR	RGB_WHITE
#define DEF_BUTTON_ACTIVE_BG_MONO	STD_MONO_ACTIVE_BG
#define DEF_BUTTON_ACTIVE_FG_COLOR	STD_COLOR_ACTIVE_FG
#define DEF_BUTTON_ACTIVE_FG_MONO	STD_MONO_ACTIVE_FG
#define DEF_BUTTON_BORDER_WIDTH		"1"
#if (TK_MAJOR_VERSION == 4) 
#define DEF_BUTTON_CLOSE_RELIEF		"flat"
#define DEF_BUTTON_OPEN_RELIEF		"flat"
#else
#define DEF_BUTTON_CLOSE_RELIEF		"solid"
#define DEF_BUTTON_OPEN_RELIEF		"solid"
#endif
#define DEF_BUTTON_IMAGES		(char *)NULL
#define DEF_BUTTON_NORMAL_BG_COLOR	RGB_WHITE
#define DEF_BUTTON_NORMAL_BG_MONO	STD_MONO_NORMAL_BG
#define DEF_BUTTON_NORMAL_FG_COLOR	STD_COLOR_NORMAL_FG
#define DEF_BUTTON_NORMAL_FG_MONO	STD_MONO_NORMAL_FG
#define DEF_BUTTON_SIZE			"7"

#define DEF_ENTRY_BG_COLOR		(char *)NULL
#define DEF_ENTRY_BG_MONO		(char *)NULL
#define DEF_ENTRY_BIND_TAGS		"Entry all"
#define DEF_ENTRY_COMMAND		(char *)NULL
#define DEF_ENTRY_DATA			(char *)NULL
#define DEF_ENTRY_FG_COLOR		(char *)NULL
#define DEF_ENTRY_FG_MONO		(char *)NULL
#define DEF_ENTRY_FONT			(char *)NULL
#define DEF_ENTRY_HEIGHT		(char *)NULL
#define DEF_ENTRY_ICONS			(char *)NULL
#define DEF_ENTRY_ACTIVE_ICONS		(char *)NULL
#define DEF_ENTRY_IMAGES		(char *)NULL
#define DEF_ENTRY_LABEL			(char *)NULL
#define DEF_ENTRY_SHADOW_COLOR		(char *)NULL
#define DEF_ENTRY_SHADOW_MONO		(char *)NULL
#define DEF_ENTRY_TEXT			(char *)NULL


#define DEF_TV_ICONS \
	"blt::tv::normalOpenFolder blt::tv::normalCloseFolder"
#define DEF_TV_ACTIVE_ICONS \
	"blt::tv::activeOpenFolder blt::tv::activeCloseFolder"
#define DEF_TV_ACTIVE_BG_COLOR	RGB_LIGHTBLUE0
#define DEF_TV_ACTIVE_BG_MONO	STD_MONO_ACTIVE_BG
#define DEF_TV_ACTIVE_FG_COLOR	RGB_BLACK
#define DEF_TV_ACTIVE_RELIEF	"flat"
#define DEF_TV_ACTIVE_SELECT_BG_COLOR	"#ffffea"
#define DEF_TV_ACTIVE_STIPPLE	"gray25"
#define DEF_TV_ALLOW_DUPLICATES	"yes"
#define DEF_TV_BACKGROUND	RGB_WHITE
#define DEF_TV_BORDER_WIDTH	STD_BORDERWIDTH
#define DEF_TV_BUTTON		"auto"
#define DEF_TV_COMMAND		(char *)NULL
#define DEF_TV_CURSOR		(char *)NULL
#define DEF_TV_RESIZE_CURSOR	"arrow"
#define DEF_TV_DASHES		"dot"
#define DEF_TV_EXPORT_SELECTION	"no"
#define DEF_TV_FG_COLOR		STD_COLOR_NORMAL_FG
#define DEF_TV_FG_MONO		STD_MONO_NORMAL_FG
#define DEF_TV_FLAT		"no"
#define DEF_TV_FOCUS_DASHES	"dot"
#define DEF_TV_FOCUS_EDIT	"no"
#define DEF_TV_FOCUS_FG_COLOR	STD_COLOR_ACTIVE_FG
#define DEF_TV_FOCUS_FG_MONO	STD_MONO_ACTIVE_FG
#define DEF_TV_FONT		STD_FONT
#define DEF_TV_HEIGHT		"400"
#define DEF_TV_HIDE_LEAVES	"no"
#define DEF_TV_HIDE_ROOT	"yes"
#define DEF_TV_HIGHLIGHT_BG_COLOR STD_COLOR_NORMAL_BG
#define DEF_TV_HIGHLIGHT_BG_MONO STD_MONO_NORMAL_BG
#define DEF_TV_HIGHLIGHT_COLOR	RGB_BLACK
#define DEF_TV_HIGHLIGHT_WIDTH	"2"
#define DEF_TV_LINE_COLOR	RGB_GREY50
#define DEF_TV_LINE_MONO	STD_MONO_NORMAL_FG
#define DEF_TV_LINE_SPACING	"0"
#define DEF_TV_LINE_WIDTH	"1"
#define DEF_TV_MAKE_PATH	"no"
#define DEF_TV_NEW_TAGS		"no"
#define DEF_TV_NORMAL_BG_COLOR 	STD_COLOR_NORMAL_BG
#define DEF_TV_NORMAL_FG_MONO	STD_MONO_ACTIVE_FG
#define DEF_TV_RELIEF		"sunken"
#define DEF_TV_SCROLL_INCREMENT "20"
#define DEF_TV_SCROLL_MODE	"hierbox"
#define DEF_TV_SELECT_BG_COLOR 	RGB_LIGHTBLUE1
#define DEF_TV_SELECT_BG_MONO  	STD_MONO_SELECT_BG
#define DEF_TV_SELECT_BORDER_WIDTH "1"
#define DEF_TV_SELECT_CMD	(char *)NULL
#define DEF_TV_SELECT_FG_COLOR 	STD_COLOR_SELECT_FG
#define DEF_TV_SELECT_FG_MONO  	STD_MONO_SELECT_FG
#define DEF_TV_SELECT_MODE	"single"
#define DEF_TV_SELECT_RELIEF	"flat"
#define DEF_TV_SEPARATOR	(char *)NULL
#define DEF_TV_SHOW_ROOT	"yes"
#define DEF_TV_SHOW_TITLES	"yes"
#define DEF_TV_SORT_SELECTION	"no"
#define DEF_TV_TAKE_FOCUS	"1"
#define DEF_TV_TEXT_COLOR	STD_COLOR_NORMAL_FG
#define DEF_TV_TEXT_MONO	STD_MONO_NORMAL_FG
#define DEF_TV_TRIMLEFT		""
#define DEF_TV_WIDTH		"200"

Blt_ConfigSpec bltTreeViewButtonSpecs[] =
{
    {BLT_CONFIG_BORDER, "-activebackground", "activeBackground", "Background",
	DEF_BUTTON_ACTIVE_BG_MONO, Blt_Offset(TreeView, button.activeBorder),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_BORDER, "-activebackground", "activeBackground", "Background",
	DEF_BUTTON_ACTIVE_BG_COLOR, Blt_Offset(TreeView, button.activeBorder),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_SYNONYM, "-activebg", "activeBackground", (char *)NULL, 
	(char *)NULL, 0, 0},
    {BLT_CONFIG_SYNONYM, "-activefg", "activeForeground", (char *)NULL, 
	(char *)NULL, 0, 0},
    {BLT_CONFIG_COLOR, "-activeforeground", "activeForeground", "Foreground",
	DEF_BUTTON_ACTIVE_FG_COLOR, Blt_Offset(TreeView, button.activeFgColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-activeforeground", "activeForeground", "Foreground",
	DEF_BUTTON_ACTIVE_FG_MONO, Blt_Offset(TreeView, button.activeFgColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_BORDER, "-background", "background", "Background",
	DEF_BUTTON_NORMAL_BG_COLOR, Blt_Offset(TreeView, button.border),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_BORDER, "-background", "background", "Background",
	DEF_BUTTON_NORMAL_BG_MONO, Blt_Offset(TreeView, button.border),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_SYNONYM, "-bd", "borderWidth", (char *)NULL, (char *)NULL, 0, 
	0},
    {BLT_CONFIG_SYNONYM, "-bg", "background", (char *)NULL, (char *)NULL, 0, 0},
    {BLT_CONFIG_DISTANCE, "-borderwidth", "borderWidth", "BorderWidth",
	DEF_BUTTON_BORDER_WIDTH, Blt_Offset(TreeView, button.borderWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_RELIEF, "-closerelief", "closeRelief", "Relief",
	DEF_BUTTON_CLOSE_RELIEF, Blt_Offset(TreeView, button.closeRelief),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_SYNONYM, "-fg", "foreground", (char *)NULL, (char *)NULL, 0, 0},
    {BLT_CONFIG_COLOR, "-foreground", "foreground", "Foreground",
	DEF_BUTTON_NORMAL_FG_COLOR, Blt_Offset(TreeView, button.fgColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-foreground", "foreground", "Foreground",
	DEF_BUTTON_NORMAL_FG_MONO, Blt_Offset(TreeView, button.fgColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_CUSTOM, "-images", "images", "Images",
	DEF_BUTTON_IMAGES, Blt_Offset(TreeView, button.images),
	BLT_CONFIG_NULL_OK, &bltTreeViewImagesOption},
    {BLT_CONFIG_RELIEF, "-openrelief", "openRelief", "Relief",
	DEF_BUTTON_OPEN_RELIEF, Blt_Offset(TreeView, button.openRelief),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_DISTANCE, "-size", "size", "Size", DEF_BUTTON_SIZE, 
	Blt_Offset(TreeView, button.reqSize), 0},
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL,
	(char *)NULL, 0, 0}
};

Blt_ConfigSpec bltTreeViewEntrySpecs[] =
{
    {BLT_CONFIG_CUSTOM, "-activeicons", (char *)NULL, (char *)NULL,
	DEF_ENTRY_ICONS, Blt_Offset(TreeViewEntry, activeIcons),
	BLT_CONFIG_NULL_OK, &bltTreeViewImagesOption},
    {BLT_CONFIG_CUSTOM, "-bindtags", "bindTags", "BindTags",
	DEF_ENTRY_BIND_TAGS, Blt_Offset(TreeViewEntry, tagsUid),
	BLT_CONFIG_NULL_OK, &bltTreeViewUidOption},
    {BLT_CONFIG_CUSTOM, "-button", (char *)NULL, (char *)NULL,
	DEF_TV_BUTTON, Blt_Offset(TreeViewEntry, flags),
	BLT_CONFIG_DONT_SET_DEFAULT, &buttonOption},
    {BLT_CONFIG_CUSTOM, "-closecommand", (char *)NULL, (char *)NULL,
	DEF_ENTRY_COMMAND, Blt_Offset(TreeViewEntry, closeCmd),
	BLT_CONFIG_NULL_OK, &bltTreeViewUidOption},
    {BLT_CONFIG_CUSTOM, "-data", "data", "data",
	DEF_ENTRY_DATA, 0, BLT_CONFIG_NULL_OK, &bltTreeViewDataOption},
    {BLT_CONFIG_SYNONYM, "-fg", "foreground", (char *)NULL, (char *)NULL, 
	0, 0},
    {BLT_CONFIG_FONT, "-font", "font", "Font",
	DEF_ENTRY_FONT, Blt_Offset(TreeViewEntry, font), 0},
    {BLT_CONFIG_COLOR, "-foreground", (char *)NULL, (char *)NULL,
	DEF_ENTRY_FG_COLOR, Blt_Offset(TreeViewEntry, color), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_DISTANCE, "-height", "height", "Height",
	DEF_ENTRY_HEIGHT, Blt_Offset(TreeViewEntry, reqHeight),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_CUSTOM, "-icons", (char *)NULL, (char *)NULL,
	DEF_ENTRY_ICONS, Blt_Offset(TreeViewEntry, icons),
	BLT_CONFIG_NULL_OK, &bltTreeViewImagesOption},
    {BLT_CONFIG_CUSTOM, "-label", "label", "Label",
	DEF_ENTRY_LABEL, Blt_Offset(TreeViewEntry, labelUid), 0, 
	&labelOption},
    {BLT_CONFIG_CUSTOM, "-opencommand", (char *)NULL, (char *)NULL,
	DEF_ENTRY_COMMAND, Blt_Offset(TreeViewEntry, openCmd),
	BLT_CONFIG_NULL_OK, &bltTreeViewUidOption},
    {BLT_CONFIG_SHADOW, "-shadow", "shadow", "Shadow",
	DEF_ENTRY_SHADOW_COLOR, Blt_Offset(TreeViewEntry, shadow),
	BLT_CONFIG_NULL_OK | BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_SHADOW, "-shadow", "shadow", "Shadow",
	DEF_ENTRY_SHADOW_MONO, Blt_Offset(TreeViewEntry, shadow),
	BLT_CONFIG_NULL_OK | BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL,
	(char *)NULL, 0, 0}
};

Blt_ConfigSpec bltTreeViewSpecs[] =
{
    {BLT_CONFIG_BORDER, 
	"-activebackground", "activeBackground", "ActiveBackground",
	DEF_TV_ACTIVE_BG_COLOR, Blt_Offset(TreeView, activeBorder),
	BLT_CONFIG_COLOR_ONLY | BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_BORDER, 
	"-activebackground", "activeBackground", "ActiveBackground",
	DEF_TV_ACTIVE_BG_MONO, Blt_Offset(TreeView, activeBorder),
	BLT_CONFIG_MONO_ONLY | BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_SYNONYM, "-activebg", "activeBackground", (char *)NULL, 
	(char *)NULL, 0, 0},
    {BLT_CONFIG_SYNONYM, "-activefg", "activeForeground", (char *)NULL, 
	(char *)NULL, 0, 0},
    {BLT_CONFIG_COLOR, "-activeforeground", "activeForeground", "Foreground",
	DEF_TV_ACTIVE_FG_COLOR, Blt_Offset(TreeView, activeFgColor), 0},
    {BLT_CONFIG_CUSTOM, "-activeicons", "activeIcons", "Icons",
	DEF_TV_ACTIVE_ICONS, Blt_Offset(TreeView, activeIcons),
	BLT_CONFIG_NULL_OK, &bltTreeViewImagesOption},
    {BLT_CONFIG_BITFLAG, 
	"-allowduplicates", "allowDuplicates", "AllowDuplicates",
	DEF_TV_ALLOW_DUPLICATES, Blt_Offset(TreeView, flags),
	BLT_CONFIG_DONT_SET_DEFAULT, (Blt_CustomOption *)TV_ALLOW_DUPLICATES},
    {BLT_CONFIG_BITFLAG, "-autocreate", "autoCreate", "AutoCreate",
	DEF_TV_MAKE_PATH, Blt_Offset(TreeView, flags),
	BLT_CONFIG_DONT_SET_DEFAULT, (Blt_CustomOption *)TV_FILL_ANCESTORS},
    {BLT_CONFIG_BORDER, "-background", "background", "Background",
	DEF_TV_BACKGROUND, Blt_Offset(TreeView, border), 0},
    {BLT_CONFIG_SYNONYM, "-bd", "borderWidth", (char *)NULL, (char *)NULL, 
	0, 0},
    {BLT_CONFIG_SYNONYM, "-bg", "background", (char *)NULL, (char *)NULL, 
	0, 0},
    {BLT_CONFIG_DISTANCE, "-borderwidth", "borderWidth", "BorderWidth",
	DEF_TV_BORDER_WIDTH, Blt_Offset(TreeView, borderWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_CUSTOM, "-button", "button", "Button",
	DEF_TV_BUTTON, Blt_Offset(TreeView, buttonFlags),
	BLT_CONFIG_DONT_SET_DEFAULT, &buttonOption},
    {BLT_CONFIG_STRING, "-closecommand", "closeCommand", "CloseCommand",
	DEF_TV_COMMAND, Blt_Offset(TreeView, closeCmd), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_ACTIVE_CURSOR, "-cursor", "cursor", "Cursor",
	DEF_TV_CURSOR, Blt_Offset(TreeView, cursor), BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_DASHES, "-dashes", "dashes", "Dashes",
	DEF_TV_DASHES, Blt_Offset(TreeView, dashes),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_BITFLAG, "-exportselection", "exportSelection",
	"ExportSelection", DEF_TV_EXPORT_SELECTION, 
	Blt_Offset(TreeView, flags), BLT_CONFIG_DONT_SET_DEFAULT, 
	(Blt_CustomOption *)TV_SELECT_EXPORT},
    {BLT_CONFIG_SYNONYM, "-fg", "foreground", (char *)NULL, (char *)NULL, 
	0, 0},
    {BLT_CONFIG_BOOLEAN, "-flat", "flat", "Flat",
	DEF_TV_FLAT, Blt_Offset(TreeView, flatView),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_DASHES, "-focusdashes", "focusDashes", "FocusDashes",
	DEF_TV_FOCUS_DASHES, Blt_Offset(TreeView, focusDashes),
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_COLOR, 
	"-focusforeground", "focusForeground", "FocusForeground",
	DEF_TV_FOCUS_FG_COLOR, Blt_Offset(TreeView, focusColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, 
	"-focusforeground", "focusForeground", "FocusForeground",
	DEF_TV_FOCUS_FG_MONO, Blt_Offset(TreeView, focusColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_FONT, "-font", "font", "Font",
	DEF_TV_FONT, Blt_Offset(TreeView, treeColumn.font), 0},
    {BLT_CONFIG_COLOR, "-foreground", "foreground", "Foreground",
	DEF_TV_TEXT_COLOR, Blt_Offset(TreeView, treeColumn.fgColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-foreground", "foreground", "Foreground",
	DEF_TV_TEXT_MONO, Blt_Offset(TreeView, treeColumn.fgColor), 
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_DISTANCE, "-height", "height", "Height",
	DEF_TV_HEIGHT, Blt_Offset(TreeView, reqHeight),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_BITFLAG, "-hideleaves", "hideLeaves", "HideLeaves",
	DEF_TV_HIDE_LEAVES, Blt_Offset(TreeView, flags),
	BLT_CONFIG_DONT_SET_DEFAULT, (Blt_CustomOption *)TV_HIDE_LEAVES},
    {BLT_CONFIG_BITFLAG, "-hideroot", "hideRoot", "HideRoot",
	DEF_TV_HIDE_ROOT, Blt_Offset(TreeView, flags),
	BLT_CONFIG_DONT_SET_DEFAULT, (Blt_CustomOption *)TV_HIDE_ROOT},
    {BLT_CONFIG_COLOR, "-highlightbackground", "highlightBackground",
	"HighlightBackground", DEF_TV_HIGHLIGHT_BG_COLOR, 
        Blt_Offset(TreeView, highlightBgColor), BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-highlightbackground", "highlightBackground",
	"HighlightBackground",
	DEF_TV_HIGHLIGHT_BG_MONO, Blt_Offset(TreeView, highlightBgColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_COLOR, "-highlightcolor", "highlightColor", "HighlightColor",
	DEF_TV_HIGHLIGHT_COLOR, Blt_Offset(TreeView, highlightColor), 0},
    {BLT_CONFIG_PIXELS, "-highlightthickness", "highlightThickness",
	"HighlightThickness",
	DEF_TV_HIGHLIGHT_WIDTH, Blt_Offset(TreeView, highlightWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_CUSTOM, "-icons", "icons", "Icons",
	DEF_TV_ICONS, Blt_Offset(TreeView, icons), 
	BLT_CONFIG_NULL_OK, &bltTreeViewImagesOption},
    {BLT_CONFIG_COLOR, "-linecolor", "lineColor", "LineColor",
	DEF_TV_LINE_COLOR, Blt_Offset(TreeView, lineColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_COLOR, "-linecolor", "lineColor", "LineColor",
	DEF_TV_LINE_MONO, Blt_Offset(TreeView, lineColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_DISTANCE, "-linespacing", "lineSpacing", "LineSpacing",
	DEF_TV_LINE_SPACING, Blt_Offset(TreeView, leader),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_DISTANCE, "-linewidth", "lineWidth", "LineWidth",
	DEF_TV_LINE_WIDTH, Blt_Offset(TreeView, lineWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_BITFLAG, "-newtags", "newTags", "NewTags",
	DEF_TV_NEW_TAGS, Blt_Offset(TreeView, flags),
	BLT_CONFIG_DONT_SET_DEFAULT, (Blt_CustomOption *)TV_NEW_TAGS},
    {BLT_CONFIG_STRING, "-opencommand", "openCommand", "OpenCommand",
	DEF_TV_COMMAND, Blt_Offset(TreeView, openCmd), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_RELIEF, "-relief", "relief", "Relief",
	DEF_TV_RELIEF, Blt_Offset(TreeView, relief), 0},
    {BLT_CONFIG_CURSOR, "-resizecursor", "resizeCursor", "ResizeCursor",
	DEF_TV_RESIZE_CURSOR, Blt_Offset(TreeView, resizeCursor), 0},
    {BLT_CONFIG_CUSTOM, "-scrollmode", "scrollMode", "ScrollMode",
	DEF_TV_SCROLL_MODE, Blt_Offset(TreeView, scrollMode),
	BLT_CONFIG_DONT_SET_DEFAULT, &scrollmodeOption},
    {BLT_CONFIG_BORDER, "-selectbackground", "selectBackground", "Foreground",
	DEF_TV_SELECT_BG_MONO, Blt_Offset(TreeView, selBorder),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_BORDER, "-selectbackground", "selectBackground", "Foreground",
	DEF_TV_SELECT_BG_COLOR, Blt_Offset(TreeView, selBorder),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_DISTANCE, 
	"-selectborderwidth", "selectBorderWidth", "BorderWidth",
	DEF_TV_SELECT_BORDER_WIDTH, Blt_Offset(TreeView, selBorderWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_STRING, "-selectcommand", "selectCommand", "SelectCommand",
	DEF_TV_SELECT_CMD, Blt_Offset(TreeView, selectCmd),
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_COLOR, "-selectforeground", "selectForeground", "Background",
	DEF_TV_SELECT_FG_MONO, Blt_Offset(TreeView, selFgColor),
	BLT_CONFIG_MONO_ONLY},
    {BLT_CONFIG_COLOR, "-selectforeground", "selectForeground", "Background",
	DEF_TV_SELECT_FG_COLOR, Blt_Offset(TreeView, selFgColor),
	BLT_CONFIG_COLOR_ONLY},
    {BLT_CONFIG_CUSTOM, "-selectmode", "selectMode", "SelectMode",
	DEF_TV_SELECT_MODE, Blt_Offset(TreeView, selectMode),
	BLT_CONFIG_DONT_SET_DEFAULT, &selectmodeOption},
    {BLT_CONFIG_RELIEF, "-selectrelief", "selectRelief", "Relief",
	DEF_TV_SELECT_RELIEF, Blt_Offset(TreeView, selRelief),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_CUSTOM, "-separator", "separator", "Separator",
	DEF_TV_SEPARATOR, Blt_Offset(TreeView, pathSep), 
        BLT_CONFIG_NULL_OK, &separatorOption},
    {BLT_CONFIG_BITFLAG, "-showtitles", "showTitles", "ShowTitles",
	DEF_TV_SHOW_TITLES, Blt_Offset(TreeView, flags), 0,
        (Blt_CustomOption *)TV_SHOW_COLUMN_TITLES},
    {BLT_CONFIG_BITFLAG, "-sortselection", "sortSelection", "SortSelection",
	DEF_TV_SORT_SELECTION, Blt_Offset(TreeView, flags), 
        BLT_CONFIG_DONT_SET_DEFAULT, (Blt_CustomOption *)TV_SELECT_SORTED},
    {BLT_CONFIG_STRING, "-takefocus", "takeFocus", "TakeFocus",
	DEF_TV_TAKE_FOCUS, Blt_Offset(TreeView, takeFocus), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_CUSTOM, "-tree", "tree", "Tree",
	"", Blt_Offset(TreeView, tree), BLT_CONFIG_NULL_OK, &treeOption},
    {BLT_CONFIG_STRING, "-trim", "trim", "Trim",
	DEF_TV_TRIMLEFT, Blt_Offset(TreeView, trimLeft), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_DISTANCE, "-width", "width", "Width",
	DEF_TV_WIDTH, Blt_Offset(TreeView, reqWidth),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_STRING, 
	"-xscrollcommand", "xScrollCommand", "ScrollCommand",
	(char *)NULL, Blt_Offset(TreeView, xScrollCmdPrefix), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_DISTANCE, 
	"-xscrollincrement", "xScrollIncrement", "ScrollIncrement",
	DEF_TV_SCROLL_INCREMENT, Blt_Offset(TreeView, xScrollUnits),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_STRING, 
        "-yscrollcommand", "yScrollCommand", "ScrollCommand",
	(char *)NULL, Blt_Offset(TreeView, yScrollCmdPrefix), 
	BLT_CONFIG_NULL_OK},
    {BLT_CONFIG_DISTANCE, 
	"-yscrollincrement", "yScrollIncrement", "ScrollIncrement",
	DEF_TV_SCROLL_INCREMENT, Blt_Offset(TreeView, yScrollUnits),
	BLT_CONFIG_DONT_SET_DEFAULT},
    {BLT_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL,
	(char *)NULL, 0, 0}
};

/* Forward Declarations */
static Blt_TreeNotifyEventProc TreeEventProc;
static Blt_TreeTraceProc TreeTraceProc;
static Tcl_CmdDeleteProc WidgetInstCmdDeleteProc;
static Tcl_FreeProc DestroyTreeView;
static Tcl_IdleProc DisplayTreeView;
static Tk_EventProc TreeViewEventProc;

static int ComputeVisibleEntries _ANSI_ARGS_((TreeView *tvPtr));

EXTERN int Blt_TreeCmdGetToken _ANSI_ARGS_((Tcl_Interp *interp, char *treeName,
	Blt_Tree *treePtr));

EXTERN int Blt_TreeCmdGetTagTable _ANSI_ARGS_((Tcl_Interp *interp, 
	char *treeName, Blt_TreeTagTable **tablePtrPtr));

#ifdef __STDC__
extern Blt_TreeApplyProc Blt_TreeViewSortApplyProc;
static Blt_BindPickProc PickButton, PickEntry, PickColumn;
static Blt_BindTagProc GetTags, GetColumnTags;
static Tcl_FreeProc DestroyEntry;
static Tcl_ObjCmdProc TreeViewObjCmd;
static Tk_ImageChangedProc ImageChangedProc;
static Tk_SelectionProc SelectionProc;
#endif /* __STDC__ */

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewEventuallyRedraw --
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
void
Blt_TreeViewEventuallyRedraw(tvPtr)
    TreeView *tvPtr;
{
    if ((tvPtr->tkwin != NULL) && ((tvPtr->flags & TV_REDRAW) == 0)) {
	tvPtr->flags |= TV_REDRAW;
	Tcl_DoWhenIdle(DisplayTreeView, tvPtr);
    }
}

static void
TraceColumns(tvPtr)
    TreeView *tvPtr;
{
    Blt_ChainLink *linkPtr;
    TreeViewColumn *columnPtr;

    for(linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); linkPtr != NULL;
	linkPtr = Blt_ChainNextLink(linkPtr)) {
	columnPtr = Blt_ChainGetValue(linkPtr);
	Blt_TreeCreateTrace(tvPtr->tree, NULL /* Node */, columnPtr->key, 
	        TREE_TRACE_FOREIGN_ONLY | TREE_TRACE_WRITE | TREE_TRACE_UNSET, 
	        TreeTraceProc, tvPtr);
    }
}

void
Blt_TreeViewTraceColumn(tvPtr, columnPtr) 
    TreeView *tvPtr;
    TreeViewColumn *columnPtr;
{
    Blt_TreeCreateTrace(tvPtr->tree, NULL /* Node */, columnPtr->key, 
	TREE_TRACE_FOREIGN_ONLY | TREE_TRACE_WRITE | TREE_TRACE_UNSET, 
	TreeTraceProc, tvPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToTree --
 *
 *	Convert the string representing the name of a tree object 
 *	into a tree token.
 *
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left
 *	in interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToTree(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    Blt_Tree *treePtr = (Blt_Tree *)(widgRec + offset);
    Blt_Tree tree;
    char *string;

    tree = NULL;
    string = Tcl_GetString(objPtr);
    if ((string[0] != '\0') && 
	(Blt_TreeGetToken(interp, string, &tree) != TCL_OK)) {
	return TCL_ERROR;
    }
    *treePtr = tree;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * TreeToObj --
 *
 * Results:
 *	The string representation of the button boolean is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
TreeToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    Blt_Tree tree = *(Blt_Tree *)(widgRec + offset);

    if (tree == NULL) {
	return Tcl_NewStringObj("", -1);
    } else {
	return Tcl_NewStringObj(Blt_TreeName(tree), -1);
    }
}

/*ARGSUSED*/
static void
FreeTree(clientData, display, widgRec, offset)
    ClientData clientData;
    Display *display;		/* Not used. */
    char *widgRec;
    int offset;
{
    Blt_Tree *treePtr = (Blt_Tree *)(widgRec + offset);

    if (*treePtr != NULL) {
	Blt_TreeNode root;
	TreeView *tvPtr = clientData;

	/* 
	 * Release the current tree, removing any entry fields. 
	 */
	root = Blt_TreeRootNode(*treePtr);
	Blt_TreeApply(root, DeleteApplyProc, tvPtr);
	Blt_TreeViewClearSelection(tvPtr);
	Blt_TreeReleaseToken(*treePtr);
	if (tvPtr->tagTablePtr != NULL) {
	    Blt_TreeReleaseTagTable(tvPtr->tagTablePtr);
	    tvPtr->tagTablePtr = NULL;
	}
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToScrollmode --
 *
 *	Convert the string reprsenting a scroll mode, to its numeric
 *	form.
 *
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left
 *	in interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToScrollmode(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* New legend position string */
    char *widgRec;
    int offset;
{
    char *string;
    char c;
    int *modePtr = (int *)(widgRec + offset);

    string = Tcl_GetString(objPtr);
    c = string[0];
    if ((c == 'l') && (strcmp(string, "listbox") == 0)) {
	*modePtr = BLT_SCROLL_MODE_LISTBOX;
    } else if ((c == 't') && (strcmp(string, "treeview") == 0)) {
	*modePtr = BLT_SCROLL_MODE_HIERBOX;
    } else if ((c == 'h') && (strcmp(string, "hiertable") == 0)) {
	*modePtr = BLT_SCROLL_MODE_HIERBOX;
    } else if ((c == 'c') && (strcmp(string, "canvas") == 0)) {
	*modePtr = BLT_SCROLL_MODE_CANVAS;
    } else {
	Tcl_AppendResult(interp, "bad scroll mode \"", string,
	    "\": should be \"treeview\", \"listbox\", or \"canvas\"", 
		(char *)NULL);
	return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * ScrollmodeToObj --
 *
 * Results:
 *	The string representation of the button boolean is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
ScrollmodeToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    int mode = *(int *)(widgRec + offset);

    switch (mode) {
    case BLT_SCROLL_MODE_LISTBOX:
	return Tcl_NewStringObj("listbox", -1);
    case BLT_SCROLL_MODE_HIERBOX:
	return Tcl_NewStringObj("hierbox", -1);
    case BLT_SCROLL_MODE_CANVAS:
	return Tcl_NewStringObj("canvas", -1);
    default:
	return Tcl_NewStringObj("unknown scroll mode", -1);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToSelectmode --
 *
 *	Convert the string reprsenting a scroll mode, to its numeric
 *	form.
 *
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left
 *	in interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToSelectmode(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    char *string;
    char c;
    int *modePtr = (int *)(widgRec + offset);

    string = Tcl_GetString(objPtr);
    c = string[0];
    if ((c == 's') && (strcmp(string, "single") == 0)) {
	*modePtr = SELECT_MODE_SINGLE;
    } else if ((c == 'm') && (strcmp(string, "multiple") == 0)) {
	*modePtr = SELECT_MODE_MULTIPLE;
    } else if ((c == 'a') && (strcmp(string, "active") == 0)) {
	*modePtr = SELECT_MODE_SINGLE;
    } else {
	Tcl_AppendResult(interp, "bad select mode \"", string,
	    "\": should be \"single\" or \"multiple\"", (char *)NULL);
	return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * SelectmodeToObj --
 *
 * Results:
 *	The string representation of the button boolean is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
SelectmodeToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    int mode = *(int *)(widgRec + offset);

    switch (mode) {
    case SELECT_MODE_SINGLE:
	return Tcl_NewStringObj("single", -1);
    case SELECT_MODE_MULTIPLE:
	return Tcl_NewStringObj("multiple", -1);
    default:
	return Tcl_NewStringObj("unknown scroll mode", -1);
    }
}


/*
 *----------------------------------------------------------------------
 *
 * ObjToButton --
 *
 *	Convert a string to one of three values.
 *		0 - false, no, off
 *		1 - true, yes, on
 *		2 - auto
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left in
 *	interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToButton(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    char *string;
    int *flagsPtr = (int *)(widgRec + offset);

    string = Tcl_GetString(objPtr);
    if ((string[0] == 'a') && (strcmp(string, "auto") == 0)) {
	*flagsPtr &= ~BUTTON_MASK;
	*flagsPtr |= BUTTON_AUTO;
    } else {
	int bool;

	if (Tcl_GetBooleanFromObj(interp, objPtr, &bool) != TCL_OK) {
	    return TCL_ERROR;
	}
	*flagsPtr &= ~BUTTON_MASK;
	if (bool) {
	    *flagsPtr |= BUTTON_SHOW;
	}
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * ButtonToObj --
 *
 * Results:
 *	The string representation of the button boolean is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
ButtonToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    int bool;
    unsigned int flags = *(int *)(widgRec + offset);

    bool = (flags & BUTTON_MASK);
    if (bool == BUTTON_AUTO) {
	return Tcl_NewStringObj("auto", 4);
    } else {
	return Tcl_NewBooleanObj(bool);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToScrollmode --
 *
 *	Convert the string reprsenting a scroll mode, to its numeric
 *	form.
 *
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left
 *	in interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToSeparator(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    char **sepPtr = (char **)(widgRec + offset);
    char *string;

    string = Tcl_GetString(objPtr);
    if (*string == '\0') {
	*sepPtr = SEPARATOR_LIST;
    } else if (strcmp(string, "none") == 0) {
	*sepPtr = SEPARATOR_NONE;
    } else {
	*sepPtr = Blt_Strdup(string);
    } 
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * SeparatorToObj --
 *
 * Results:
 *	The string representation of the separator is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
SeparatorToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    char *separator = *(char **)(widgRec + offset);

    if (separator == SEPARATOR_NONE) {
	return Tcl_NewStringObj("", -1);
    } else if (separator == SEPARATOR_LIST) {
	return Tcl_NewStringObj("list", -1);
    }  else {
	return Tcl_NewStringObj(separator, -1);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * FreeSeparator --
 *
 *	Free the UID from the widget record, setting it to NULL.
 *
 * Results:
 *	The UID in the widget record is set to NULL.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static void
FreeSeparator(clientData, display, widgRec, offset)
    ClientData clientData;
    Display *display;		/* Not used. */
    char *widgRec;
    int offset;
{
    char *separator = *(char **)(widgRec + offset);

    if ((separator != SEPARATOR_LIST) && (separator != SEPARATOR_NONE)) {
	Blt_Free(separator);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToLabel --
 *
 *	Convert the string representing the label. 
 *
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left
 *	in interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToLabel(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    UID *labelPtr = (UID *)(widgRec + offset);
    char *string;

    string = Tcl_GetString(objPtr);
    if (string[0] != '\0') {
	TreeView *tvPtr = clientData;

	*labelPtr = Blt_TreeViewGetUid(tvPtr, string);
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * TreeToObj --
 *
 * Results:
 *	The string of the entry's label is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
LabelToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    UID labelUid = *(UID *)(widgRec + offset);
    char *string;

    if (labelUid == NULL) {
	TreeViewEntry *entryPtr  = (TreeViewEntry *)widgRec;

	string = Blt_TreeNodeLabel(entryPtr->node);
    } else {
	string = labelUid;
    }
    return Tcl_NewStringObj(string, -1);
}

/*ARGSUSED*/
static void
FreeLabel(clientData, display, widgRec, offset)
    ClientData clientData;
    Display *display;		/* Not used. */
    char *widgRec;
    int offset;
{
    UID *labelPtr = (UID *)(widgRec + offset);

    if (*labelPtr != NULL) {
	TreeView *tvPtr = clientData;

	Blt_TreeViewFreeUid(tvPtr, *labelPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewGetUid --
 *
 *	Gets or creates a unique string identifier.  Strings are
 *	reference counted.  The string is placed into a hashed table
 *	local to the treeview.
 *
 * Results:
 *	Returns the pointer to the hashed string.
 *
 *---------------------------------------------------------------------- 
 */
UID
Blt_TreeViewGetUid(tvPtr, string)
    TreeView *tvPtr;
    char *string;
{
    Blt_HashEntry *hPtr;
    int isNew;
    int refCount;

    hPtr = Blt_CreateHashEntry(&tvPtr->uidTable, string, &isNew);
    if (isNew) {
	refCount = 1;
    } else {
	refCount = (int)Blt_GetHashValue(hPtr);
	refCount++;
    }
    Blt_SetHashValue(hPtr, (ClientData)refCount);
    return Blt_GetHashKey(&tvPtr->uidTable, hPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewFreeUid --
 *
 *	Releases the uid.  Uids are reference counted, so only when
 *	the reference count is zero (i.e. no one else is using the
 *	string) is the entry removed from the hash table.
 *
 * Results:
 *	None.
 *
 *---------------------------------------------------------------------- 
 */
void
Blt_TreeViewFreeUid(tvPtr, uid)
    TreeView *tvPtr;
    UID uid;
{
    Blt_HashEntry *hPtr;
    int refCount;

    hPtr = Blt_FindHashEntry(&tvPtr->uidTable, uid);
    assert(hPtr != NULL);
    refCount = (int)Blt_GetHashValue(hPtr);
    refCount--;
    if (refCount > 0) {
	Blt_SetHashValue(hPtr, (ClientData)refCount);
    } else {
	Blt_DeleteHashEntry(&tvPtr->uidTable, hPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToUid --
 *
 *	Converts the string to a Uid. Uid's are hashed, reference
 *	counted strings.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToUid(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    TreeView *tvPtr = clientData;
    UID *uidPtr = (UID *)(widgRec + offset);
    UID newId;
    char *string;

    newId = NULL;
    string = Tcl_GetString(objPtr);
    if (*string != '\0') {
	newId = Blt_TreeViewGetUid(tvPtr, string);
    }
    *uidPtr = newId;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * UidToObj --
 *
 *	Returns the uid as a string.
 *
 * Results:
 *	The fill style string is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
UidToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    UID uid = *(UID *)(widgRec + offset);

    return Tcl_NewStringObj(((uid == NULL) ? "" : uid), -1);
}

/*
 *----------------------------------------------------------------------
 *
 * FreeUid --
 *
 *	Free the UID from the widget record, setting it to NULL.
 *
 * Results:
 *	The UID in the widget record is set to NULL.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static void
FreeUid(clientData, display, widgRec, offset)
    ClientData clientData;
    Display *display;		/* Not used. */
    char *widgRec;
    int offset;
{
    UID *uidPtr = (UID *)(widgRec + offset);

    if (*uidPtr != NULL) {
	TreeView *tvPtr = clientData;

	Blt_TreeViewFreeUid(tvPtr, *uidPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ImageChangedProc
 *
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
/* ARGSUSED */
static void
ImageChangedProc(clientData, x, y, width, height, imageWidth, imageHeight)
    ClientData clientData;
    int x, y, width, height;	/* Not used. */
    int imageWidth, imageHeight;/* Not used. */
{
    TreeView *tvPtr = clientData;

    tvPtr->flags |= (TV_DIRTY | TV_LAYOUT | TV_SCROLL);
    Blt_TreeViewEventuallyRedraw(tvPtr);
}

TreeViewImage
Blt_TreeViewGetImage(tvPtr, imageName)
    TreeView *tvPtr;
    char *imageName;
{
    Blt_HashEntry *hPtr;
    int isNew;
    struct TreeViewImageStruct *iPtr;

    hPtr = Blt_CreateHashEntry(&tvPtr->imageTable, imageName, &isNew);
    if (isNew) {
	Tk_Image tkImage;
	int width, height;

	tkImage = Tk_GetImage(tvPtr->interp, tvPtr->tkwin, imageName, 
		ImageChangedProc, tvPtr);
	if (tkImage == NULL) {
	    Blt_DeleteHashEntry(&tvPtr->imageTable, hPtr);
	    return NULL;
	}
	Tk_SizeOfImage(tkImage, &width, &height);
	iPtr = Blt_Malloc(sizeof(struct TreeViewImageStruct));
	iPtr->tkImage = tkImage;
	iPtr->hashPtr = hPtr;
	iPtr->refCount = 1;
	iPtr->width = width;
	iPtr->height = height;
	Blt_SetHashValue(hPtr, iPtr);
    } else {
	iPtr = Blt_GetHashValue(hPtr);
	iPtr->refCount++;
    }
    return iPtr;
}

void
Blt_TreeViewFreeImage(tvPtr, iPtr)
    TreeView *tvPtr;
    struct TreeViewImageStruct *iPtr;
{
    iPtr->refCount--;
    if (iPtr->refCount == 0) {
	Blt_DeleteHashEntry(&tvPtr->imageTable, iPtr->hashPtr);
	Tk_FreeImage(iPtr->tkImage);
	Blt_Free(iPtr);
    }
}

static void
DumpImageTable(tvPtr)
    TreeView *tvPtr;
{
    Blt_HashEntry *hPtr;
    Blt_HashSearch cursor;
    struct TreeViewImageStruct *iPtr;

    for (hPtr = Blt_FirstHashEntry(&tvPtr->imageTable, &cursor);
	 hPtr != NULL; hPtr = Blt_NextHashEntry(&cursor)) {
	iPtr = Blt_GetHashValue(hPtr);
	Tk_FreeImage(iPtr->tkImage);
	Blt_Free(iPtr);
    }
    Blt_DeleteHashTable(&tvPtr->imageTable);
}

/*
 *----------------------------------------------------------------------
 *
 * ObjToImages --
 *
 *	Convert a list of image names into Tk images.
 *
 * Results:
 *	If the string is successfully converted, TCL_OK is returned.
 *	Otherwise, TCL_ERROR is returned and an error message is left in
 *	interpreter's result field.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
ObjToImages(clientData, interp, tkwin, objPtr, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    Tcl_Obj *objPtr;		/* Tcl_Obj representing the new value. */
    char *widgRec;
    int offset;
{
    Tcl_Obj **objv;
    TreeView *tvPtr = clientData;
    TreeViewImage **iPtrPtr = (TreeViewImage **)(widgRec + offset);
    TreeViewImage *images;
    int objc;
    int result;

    result = TCL_OK;
    images = NULL;
    if (Tcl_ListObjGetElements(interp, objPtr, &objc, &objv) != TCL_OK) {
	return TCL_ERROR;
    }
    if (objc > 0) {
	register int i;
	
	images = Blt_Malloc(sizeof(TreeViewImage *) * (objc + 1));
	assert(images);
	for (i = 0; i < objc; i++) {
	    images[i] = Blt_TreeViewGetImage(tvPtr, Tcl_GetString(objv[i]));
	    if (images[i] == NULL) {
		result = TCL_ERROR;
		break;
	    }
	}
	images[i] = NULL;
    }
    *iPtrPtr = images;
    return result;
}

/*
 *----------------------------------------------------------------------
 *
 * ImagesToObj --
 *
 *	Converts the image into its string representation (its name).
 *
 * Results:
 *	The name of the image is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static Tcl_Obj *
ImagesToObj(clientData, interp, tkwin, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;
    int offset;
{
    TreeViewImage *images = *(TreeViewImage **)(widgRec + offset);
    Tcl_Obj *listObjPtr;
    
    listObjPtr = Tcl_NewListObj(0, (Tcl_Obj **)NULL);
    if (images != NULL) {
	register TreeViewImage *iPtr;
	Tcl_Obj *objPtr;

	for (iPtr = images; *iPtr != NULL; iPtr++) {
	    objPtr = Tcl_NewStringObj(Blt_NameOfImage((*iPtr)->tkImage), -1);
	    Tcl_ListObjAppendElement(interp, listObjPtr, objPtr);

	}
    }
    return listObjPtr;
}

/*ARGSUSED*/
static void
FreeImages(clientData, display, widgRec, offset)
    ClientData clientData;
    Display *display;		/* Not used. */
    char *widgRec;
    int offset;
{
    TreeViewImage *images = *(TreeViewImage **)(widgRec + offset);

    if (images != NULL) {
	register TreeViewImage *iPtr;
	TreeView *tvPtr = clientData;

	for (iPtr = images; *iPtr != NULL; iPtr++) {
	    Blt_TreeViewFreeImage(tvPtr, *iPtr);
	}
	Blt_Free(images);
    }
}

int
Blt_TreeViewApply(tvPtr, entryPtr, proc, flags)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;	/* Root entry of subtree. */
    TreeViewApplyProc *proc;	/* Procedure to call for each entry. */
    unsigned int flags;
{
    if ((flags & ENTRY_HIDDEN) && 
	(Blt_TreeViewEntryIsHidden(tvPtr, entryPtr))) {
	return TCL_OK;		/* Hidden node. */
    }
    if ((flags & ENTRY_HIDDEN) && (entryPtr->flags & ENTRY_HIDDEN)) {
	return TCL_OK;		/* Hidden node. */
    }
    if (((flags & ENTRY_CLOSED) == 0) || 
	((entryPtr->flags & ENTRY_CLOSED) == 0)) {
	TreeViewEntry *childPtr;
	Blt_TreeNode node, next;

	next = NULL;
	for (node = Blt_TreeFirstChild(entryPtr->node); node != NULL; 
	     node = next) {
	    next = Blt_TreeNextSibling(node);
	    /* 
	     * Get the next child before calling Blt_TreeViewApply
	     * recursively.  This is because the apply callback may
	     * delete the node and its link.
	     */
	    childPtr = NodeToEntry(tvPtr, node);
	    if (Blt_TreeViewApply(tvPtr, childPtr, proc, flags) != TCL_OK) {
		return TCL_ERROR;
	    }
	}
    }
    if ((*proc) (tvPtr, entryPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    return TCL_OK;
}

int
Blt_TreeViewEntryIsHidden(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    if ((tvPtr->flags & TV_HIDE_LEAVES) && (Blt_TreeIsLeaf(entryPtr->node))) {
	return TRUE;
    }
    return (entryPtr->flags & ENTRY_HIDDEN) ? TRUE : FALSE;
}

int
Blt_TreeViewEntryIsMapped(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    /* Don't check if the entry itself is open, only that its
     * ancestors are. */
    if (Blt_TreeViewEntryIsHidden(tvPtr, entryPtr)) {
	return FALSE;
    }
    if (entryPtr == tvPtr->rootPtr) {
	return TRUE;
    }
    entryPtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
    while (entryPtr != tvPtr->rootPtr) {
	if (entryPtr->flags & (ENTRY_CLOSED | ENTRY_HIDDEN)) {
	    return FALSE;
	}
	entryPtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
    }
    return TRUE;
}

TreeViewEntry *
Blt_TreeViewFirstChild(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_TreeNode node;

    for (node = Blt_TreeFirstChild(entryPtr->node); node != NULL; 
	 node = Blt_TreeNextSibling(node)) {
	entryPtr = NodeToEntry(tvPtr, node);
	if (!Blt_TreeViewEntryIsHidden(tvPtr, entryPtr)) {
	    return entryPtr;
	}
    }
    return NULL;
}

TreeViewEntry *
Blt_TreeViewLastChild(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_TreeNode node;

    for (node = Blt_TreeLastChild(entryPtr->node); node != NULL; 
	 node = Blt_TreePrevSibling(node)) {
	entryPtr = NodeToEntry(tvPtr, node);
	if (!Blt_TreeViewEntryIsHidden(tvPtr, entryPtr)) {
	    return entryPtr;
	}
    }
    return NULL;
}

TreeViewEntry *
Blt_TreeViewNextSibling(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_TreeNode node;

    for (node = Blt_TreeNextSibling(entryPtr->node); node != NULL; 
	 node = Blt_TreeNextSibling(node)) {
	entryPtr = NodeToEntry(tvPtr, node);
	if (!Blt_TreeViewEntryIsHidden(tvPtr, entryPtr)) {
	    return entryPtr;
	}
    }
    return NULL;
}

TreeViewEntry *
Blt_TreeViewPrevSibling(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_TreeNode node;

    for (node = Blt_TreePrevSibling(entryPtr->node); node != NULL; 
	 node = Blt_TreePrevSibling(node)) {
	entryPtr = NodeToEntry(tvPtr, node);
	if (!Blt_TreeViewEntryIsHidden(tvPtr, entryPtr)) {
	    return entryPtr;
	}
    }
    return NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewPrevEntry --
 *
 *	Returns the "previous" node in the tree.  This node (in 
 *	depth-first order) is its parent if the node has no siblings
 *	that are previous to it.  Otherwise it is the last descendant 
 *	of the last sibling.  In this case, descend the sibling's
 *	hierarchy, using the last child at any ancestor, until we
 *	we find a leaf.
 *
 *----------------------------------------------------------------------
 */
TreeViewEntry *
Blt_TreeViewPrevEntry(tvPtr, entryPtr, mask)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    unsigned int mask;
{
    TreeViewEntry *prevPtr;

    if (entryPtr->node == Blt_TreeRootNode(tvPtr->tree)) {
	return NULL;		/* The root is the first node. */
    }
    prevPtr = Blt_TreeViewPrevSibling(tvPtr, entryPtr);
    if (prevPtr == NULL) {
	/* There are no siblings previous to this one, so pick the parent. */
	prevPtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
    } else {
	/*
	 * Traverse down the right-most thread in order to select the
	 * last entry.  Stop if we find a "closed" entry or reach a leaf.
	 */
	entryPtr = prevPtr;
	while ((entryPtr->flags & mask) == 0) {
	    entryPtr = Blt_TreeViewLastChild(tvPtr, entryPtr);
	    if (entryPtr == NULL) {
		break;		/* Found a leaf. */
	    }
	    prevPtr = entryPtr;
	}
    }
    if (prevPtr == NULL) {
	return NULL;
    }
    return prevPtr;
}


/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewNextNode --
 *
 *	Returns the "next" node in relation to the given node.  
 *	The next node (in depth-first order) is either the first 
 *	child of the given node the next sibling if the node has
 *	no children (the node is a leaf).  If the given node is the 
 *	last sibling, then try it's parent next sibling.  Continue
 *	until we either find a next sibling for some ancestor or 
 *	we reach the root node.  In this case the current node is 
 *	the last node in the tree.
 *
 *----------------------------------------------------------------------
 */
TreeViewEntry *
Blt_TreeViewNextEntry(tvPtr, entryPtr, mask)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    unsigned int mask;
{
    TreeViewEntry *nextPtr;

    if ((((tvPtr->flags & TV_HIDE_LEAVES) == 0) ||
	 (!Blt_TreeIsLeaf(entryPtr->node))) && (entryPtr->flags & mask) == 0) {
	/* Pick the first sub-node. */
	nextPtr = Blt_TreeViewFirstChild(tvPtr, entryPtr); 
	if (nextPtr != NULL) {
	    return nextPtr;
	}
    }
    /* 
     * Back up until we can find a level where we can pick a 
     * "next sibling".  For the last entry we'll thread our 
     * way back to the root.  
     */
    while (entryPtr != tvPtr->rootPtr) {
	nextPtr = Blt_TreeViewNextSibling(tvPtr, entryPtr);
	if (nextPtr != NULL) {
	    return nextPtr;
	}
	entryPtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
    }
    return NULL;		/* At root, no next node. */
}

void
Blt_TreeViewConfigureButtons(tvPtr)
    TreeView *tvPtr;
{
    GC newGC;
    TreeViewButton *buttonPtr = &tvPtr->button;
    XGCValues gcValues;
    unsigned long gcMask;

    gcMask = GCForeground;
    gcValues.foreground = buttonPtr->fgColor->pixel;
    newGC = Tk_GetGC(tvPtr->tkwin, gcMask, &gcValues);
    if (buttonPtr->normalGC != NULL) {
	Tk_FreeGC(tvPtr->display, buttonPtr->normalGC);
    }
    buttonPtr->normalGC = newGC;

    gcMask = (GCForeground | GCLineWidth);
    gcValues.foreground = tvPtr->lineColor->pixel;
    gcValues.line_width = tvPtr->lineWidth;
    newGC = Tk_GetGC(tvPtr->tkwin, gcMask, &gcValues);
    if (buttonPtr->lineGC != NULL) {
	Tk_FreeGC(tvPtr->display, buttonPtr->lineGC);
    }
    buttonPtr->lineGC = newGC;

    gcMask = GCForeground;
    gcValues.foreground = buttonPtr->activeFgColor->pixel;
    newGC = Tk_GetGC(tvPtr->tkwin, gcMask, &gcValues);
    if (buttonPtr->activeGC != NULL) {
	Tk_FreeGC(tvPtr->display, buttonPtr->activeGC);
    }
    buttonPtr->activeGC = newGC;

    buttonPtr->width = buttonPtr->height = ODD(buttonPtr->reqSize);
    if (buttonPtr->images != NULL) {
	register int i;
	int width, height;

	for (i = 0; i < 2; i++) {
	    if (buttonPtr->images[i] == NULL) {
		break;
	    }
	    width = TreeViewImageWidth(buttonPtr->images[i]);
	    height = TreeViewImageWidth(buttonPtr->images[i]);
	    if (buttonPtr->width < width) {
		buttonPtr->width = width;
	    }
	    if (buttonPtr->height < height) {
		buttonPtr->height = height;
	    }
	}
    }
    buttonPtr->width += 2 * buttonPtr->borderWidth;
    buttonPtr->height += 2 * buttonPtr->borderWidth;
}

void
Blt_TreeViewConfigureEntry(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    GC newGC;

    newGC = NULL;
    if ((entryPtr->font != NULL) || (entryPtr->color != NULL)) {
	Tk_Font font;
	XColor *colorPtr;
	XGCValues gcValues;
	unsigned long gcMask;

	font = CHOOSE(tvPtr->treeColumn.font, entryPtr->font);
	colorPtr = CHOOSE(tvPtr->treeColumn.fgColor, entryPtr->color);
	gcMask = GCForeground | GCFont;
	gcValues.foreground = colorPtr->pixel;
	gcValues.font = Tk_FontId(font);
	newGC = Tk_GetGC(tvPtr->tkwin, gcMask, &gcValues);
    }
    if (entryPtr->gc != NULL) {
	Tk_FreeGC(tvPtr->display, entryPtr->gc);
    }
    /* Assume all changes require a new layout. */
    entryPtr->gc = newGC;
    entryPtr->flags |= ENTRY_DIRTY;
    tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
}

/*ARGSUSED*/
static int
SetEntryObjFromAny(interp, objPtr)
    Tcl_Interp *interp;
    Tcl_Obj *objPtr;
{
#ifdef notdef
    fprintf(stderr, "SetEntryObjFromAny\n");
#endif
    Tcl_AppendResult(interp, "can't reset entry object", (char *)NULL);
    return TCL_ERROR;
}

static void
UpdateStringOfEntry(objPtr)
    Tcl_Obj *objPtr;		/* Entry object whose string rep to update. */
{
    TreeViewEntry *entryPtr;
    char *label;

#ifdef notdef
    fprintf(stderr, "UpdateStringOfEntry\n");
#endif
    entryPtr = (TreeViewEntry *)objPtr->internalRep.otherValuePtr;
    label = GETLABEL(entryPtr);
    objPtr->bytes = label;
    objPtr->length = strlen(label);
}

void
Blt_TreeViewDestroyValue(tvPtr, valuePtr)
    TreeView *tvPtr;
    TreeViewValue *valuePtr;
{
    if (valuePtr->image != NULL) {
	Blt_TreeViewFreeImage(tvPtr, valuePtr->image);
    }
    if (valuePtr->stylePtr != NULL) {
	Blt_TreeViewFreeStyle(tvPtr, valuePtr->stylePtr);
    }
    if (valuePtr->textPtr != NULL) {
	Blt_Free(valuePtr->textPtr);
    }
}


static void
DestroyEntry(data)
    DestroyData data;
{
    TreeViewEntry *entryPtr = (TreeViewEntry *)data;
    TreeView *tvPtr = entryPtr->tvPtr;
    
    bltTreeViewImagesOption.clientData = tvPtr;
    bltTreeViewUidOption.clientData = tvPtr;
    labelOption.clientData = tvPtr;
    Blt_FreeObjOptions(bltTreeViewEntrySpecs, (char *)entryPtr, tvPtr->display,
	0);

    Blt_TreeClearTags(tvPtr->tagTablePtr, entryPtr->node);
    if (entryPtr->gc != NULL) {
	Tk_FreeGC(tvPtr->display, entryPtr->gc);
    }
    if (entryPtr->shadow.color != NULL) {
	Tk_FreeColor(entryPtr->shadow.color);
    }
    /* Delete the chain of data values from the entry. */
    if (entryPtr->values != NULL) {
	TreeViewValue *valuePtr, *nextPtr;
	
	for (valuePtr = entryPtr->values; valuePtr != NULL; 
	     valuePtr = nextPtr) {
	    nextPtr = valuePtr->nextPtr;
	    Blt_TreeViewDestroyValue(tvPtr, valuePtr);
	}
	entryPtr->values = NULL;
    }
    if (entryPtr->fullName != NULL) {
	Blt_Free(entryPtr->fullName);
    }
    if (entryPtr->textPtr != NULL) {
	Blt_Free(entryPtr->textPtr);
    }
    Blt_PoolFreeItem(tvPtr->entryPool, entryPtr);
}

TreeViewEntry *
Blt_TreeViewParentEntry(tvPtr, entryPtr) 
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_TreeNode node;

    if (entryPtr->node == Blt_TreeRootNode(tvPtr->tree)) {
	return NULL;
    }
    node = Blt_TreeNodeParent(entryPtr->node);
    if (node == NULL) {
	return NULL;
    }
    return NodeToEntry(tvPtr, node);
}

static void
FreeEntryInternalRep(objPtr)
    Tcl_Obj *objPtr;		/* Entry object whose string rep to update. */
{
    TreeViewEntry *entryPtr;
    TreeView *tvPtr;

#ifdef notdef
    fprintf(stderr, "FreeEntryInternalRep\n");
#endif
    entryPtr = (TreeViewEntry *)objPtr->internalRep.otherValuePtr;
    
    tvPtr = entryPtr->tvPtr;
    if (tvPtr->flags & TV_DESTROYED) {
	/* 
	 * If we know that the treeview is being destroyed, we don't
	 * need to reset the various focus/active/selection pointers
	 * or delete the individual bindings.
	 */
	DestroyEntry((DestroyData)entryPtr);
    } else {
	if (entryPtr == tvPtr->activePtr) {
	    tvPtr->activePtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
	}
	if (entryPtr == tvPtr->activeButtonPtr) {
	    tvPtr->activeButtonPtr = NULL;
	}
	if (entryPtr == tvPtr->focusPtr) {
	    tvPtr->focusPtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
	    Blt_SetFocusItem(tvPtr->bindTable, tvPtr->focusPtr);
	}
	if (entryPtr == tvPtr->selAnchorPtr) {
	    tvPtr->selMarkPtr = tvPtr->selAnchorPtr = NULL;
	}
	Blt_TreeViewDeselectEntry(tvPtr, entryPtr);
	Blt_TreeViewPruneSelection(tvPtr, entryPtr);
	Blt_DeleteBindings(tvPtr->bindTable, entryPtr);
	Blt_DeleteBindings(tvPtr->buttonBindTable, entryPtr);
	entryPtr->node = NULL;
	Tcl_EventuallyFree(entryPtr, DestroyEntry);
	/*
	 * Indicate that the screen layout of the hierarchy may have changed
	 * because this node was deleted.  The screen positions of the nodes
	 * in tvPtr->visibleArr are invalidated.
	 */
	tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
	Blt_TreeViewEventuallyRedraw(tvPtr);
    }
}

int
Blt_TreeViewEntryIsSelected(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_HashEntry *hPtr;

    hPtr = Blt_FindHashEntry(&tvPtr->selectTable, (char *)entryPtr);
    return (hPtr != NULL);
}

void
Blt_TreeViewSelectEntry(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    int isNew;
    Blt_HashEntry *hPtr;

    hPtr = Blt_CreateHashEntry(&tvPtr->selectTable, (char *)entryPtr, &isNew);
    if (isNew) {
	Blt_ChainLink *linkPtr;

	linkPtr = Blt_ChainAppend(tvPtr->selChainPtr, entryPtr);
	Blt_SetHashValue(hPtr, linkPtr);
    }
}

void
Blt_TreeViewDeselectEntry(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Blt_HashEntry *hPtr;

    hPtr = Blt_FindHashEntry(&tvPtr->selectTable, (char *)entryPtr);
    if (hPtr != NULL) {
	Blt_ChainLink *linkPtr;

	linkPtr = Blt_GetHashValue(hPtr);
	Blt_ChainDeleteLink(tvPtr->selChainPtr, linkPtr);
	Blt_DeleteHashEntry(&tvPtr->selectTable, hPtr);
    }
}

char *
Blt_TreeViewGetFullName(tvPtr, entryPtr, checkEntryLabel, resultPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    int checkEntryLabel;
    Tcl_DString *resultPtr;
{
    Blt_TreeNode node;
    char **names;		/* Used the stack the component names. */
    char *staticSpace[64];
    int level;
    register int i;

    level = Blt_TreeNodeDepth(tvPtr->tree, entryPtr->node);
    if (tvPtr->rootPtr->labelUid == NULL) {
	level--;
    }
    if (level > 64) {
	names = Blt_Malloc((level + 2) * sizeof(char *));
	assert(names);
    } else {
	names = staticSpace;
    }
    for (i = level; i >= 0; i--) {
	/* Save the name of each ancestor in the name array. */
	if (checkEntryLabel) {
	    names[i] = GETLABEL(entryPtr);
	} else {
	    names[i] = Blt_TreeNodeLabel(entryPtr->node);
	}
	node = Blt_TreeNodeParent(entryPtr->node);
	if (node != NULL) {
	    entryPtr = NodeToEntry(tvPtr, node);
	}
    }
    Tcl_DStringInit(resultPtr);
    if (level >= 0) {
	if ((tvPtr->pathSep == SEPARATOR_LIST) || 
	    (tvPtr->pathSep == SEPARATOR_NONE)) {
	    for (i = 0; i <= level; i++) {
		Tcl_DStringAppendElement(resultPtr, names[i]);
	    }
	} else {
	    Tcl_DStringAppend(resultPtr, names[0], -1);
	    for (i = 1; i <= level; i++) {
		Tcl_DStringAppend(resultPtr, tvPtr->pathSep, -1);
		Tcl_DStringAppend(resultPtr, names[i], -1);
	    }
	}
    } else {
	if ((tvPtr->pathSep != SEPARATOR_LIST) &&
	    (tvPtr->pathSep != SEPARATOR_NONE)) {
	    Tcl_DStringAppend(resultPtr, tvPtr->pathSep, -1);
	}
    }
    if (names != staticSpace) {
	Blt_Free(names);
    }
    return Tcl_DStringValue(resultPtr);
}


int
Blt_TreeViewCloseEntry(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    char *cmd;

    if (entryPtr->flags & ENTRY_CLOSED) {
	return TCL_OK;		/* Entry is already closed. */
    }
    entryPtr->flags |= ENTRY_CLOSED;

    /*
     * Invoke the entry's "close" command, if there is one. Otherwise
     * try the treeview's global "close" command.
     */
    cmd = CHOOSE(tvPtr->closeCmd, entryPtr->closeCmd);
    if (cmd != NULL) {
	Tcl_DString dString;
	int result;

	Blt_TreeViewPercentSubst(tvPtr, entryPtr, cmd, &dString);
	Tcl_Preserve(entryPtr);
	result = Tcl_GlobalEval(tvPtr->interp, Tcl_DStringValue(&dString));
	Tcl_Release(entryPtr);
	Tcl_DStringFree(&dString);
	if (result != TCL_OK) {
	    return TCL_ERROR;
	}
    }
    tvPtr->flags |= TV_LAYOUT;
    return TCL_OK;
}


int
Blt_TreeViewOpenEntry(tvPtr, entryPtr) 
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    char *cmd;

    if ((entryPtr->flags & ENTRY_CLOSED) == 0) {
	return TCL_OK;		/* Entry is already open. */
    }
    entryPtr->flags &= ~ENTRY_CLOSED;
    /*
     * If there's a "open" command proc specified for the entry, use
     * that instead of the more general "open" proc for the entire 
     * treeview.
     */
    cmd = CHOOSE(tvPtr->openCmd, entryPtr->openCmd);
    if (cmd != NULL) {
	Tcl_DString dString;
	int result;

	Blt_TreeViewPercentSubst(tvPtr, entryPtr, cmd, &dString);
	Tcl_Preserve(entryPtr);
	result = Tcl_GlobalEval(tvPtr->interp, Tcl_DStringValue(&dString));
	Tcl_Release(entryPtr);
	Tcl_DStringFree(&dString);
	if (result != TCL_OK) {
	    return TCL_ERROR;
	}
    }
    tvPtr->flags |= TV_LAYOUT;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewCreateEntry --
 *
 *	This procedure is called by the Tree object when a node is 
 *	created and inserted into the tree.  It adds a new treeview 
 *	entry field to the node.
 *
 * Results:
 *	Returns TCL_OK is the entry was added, TCL_ERROR otherwise.
 *
 *----------------------------------------------------------------------
 */
int
Blt_TreeViewCreateEntry(tvPtr, node, objc, objv)
    TreeView *tvPtr;
    Blt_TreeNode node;		/* Node that has just been created. */
    int objc;
    Tcl_Obj *CONST *objv;
{
    Blt_ChainLink *linkPtr;
    Tcl_Obj *objPtr;
    TreeViewColumn *columnPtr;
    TreeViewEntry *entryPtr;

    /* Create the entry structure */
    entryPtr = Blt_PoolAllocItem(tvPtr->entryPool, sizeof(TreeViewEntry));
    memset(entryPtr, 0, sizeof(TreeViewEntry));

    entryPtr->flags = tvPtr->buttonFlags | ENTRY_CLOSED;
    entryPtr->tvPtr = tvPtr;

    entryPtr->labelUid = NULL;
    entryPtr->node = node;

    bltTreeViewImagesOption.clientData = tvPtr;
    bltTreeViewUidOption.clientData = tvPtr;
    labelOption.clientData = tvPtr;
    if (Blt_ConfigureWidgetFromObj(tvPtr->interp, tvPtr->tkwin, 
	   bltTreeViewEntrySpecs, objc, objv, (char *)entryPtr, 0) != TCL_OK) {
	DestroyEntry((DestroyData)entryPtr);
	return TCL_ERROR;
    }
    Blt_TreeViewConfigureEntry(tvPtr, entryPtr);

    objPtr = Tcl_NewObj(); 
    /* 
     * Reference counts for entry objects are initialized to 0. They
     * are incremented as they are inserted into the tree via the 
     * Blt_TreeSetValue call. 
     */
    objPtr->refCount = 0;	
    objPtr->internalRep.otherValuePtr = (VOID *)entryPtr;
    objPtr->bytes = NULL;
    objPtr->length = 0; 
    objPtr->typePtr = &entryObjType;
    /* 
     * Check if there are values that need to be added 
     */
    for(linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); linkPtr != NULL;
	linkPtr = Blt_ChainNextLink(linkPtr)) {
	columnPtr = Blt_ChainGetValue(linkPtr);
	Blt_TreeViewAddValue(entryPtr, columnPtr);
    }
    if (Blt_TreeSetValueByKey(tvPtr->interp, tvPtr->tree, node, 
	      tvPtr->treeColumn.key, objPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    Blt_TreePrivateValue(tvPtr->interp, tvPtr->tree, node, 
	tvPtr->treeColumn.key);
    tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
    Blt_TreeViewEventuallyRedraw(tvPtr);
    return TCL_OK;
}

/*ARGSUSED*/
static int
CreateApplyProc(node, clientData, order)
    Blt_TreeNode node;		/* Node that has just been created. */
    ClientData clientData;
    int order;			/* Not used. */
{
    TreeView *tvPtr = clientData; 
    return Blt_TreeViewCreateEntry(tvPtr, node, 0, (Tcl_Obj **)NULL);
}

/*ARGSUSED*/
static int
DeleteApplyProc(node, clientData, order)
    Blt_TreeNode node;
    ClientData clientData;
    int order;			/* Not used. */
{
    TreeView *tvPtr = clientData;
    /* 
     * Unsetting the tree value triggers a call back to destroy the entry
     * and also releases the Tcl_Obj that contains it. 
     */
    return Blt_TreeUnsetValueByKey(tvPtr->interp, tvPtr->tree, node, 
	tvPtr->treeColumn.key);
}

static int
TreeEventProc(clientData, eventPtr) 
    ClientData clientData;
    Blt_TreeNotifyEvent *eventPtr;
{
    Blt_TreeNode node;
    TreeView *tvPtr = clientData; 
    TreeViewEntry *entryPtr;

    node = Blt_TreeGetNode(eventPtr->tree, eventPtr->inode);
    switch (eventPtr->type) {
    case TREE_NOTIFY_CREATE:
	return Blt_TreeViewCreateEntry(tvPtr, node, 0, (Tcl_Obj **)NULL);
    case TREE_NOTIFY_DELETE:
	/*  
	 * Unsetting the tree value triggers a call back to destroy
	 * the entry and also releases the Tcl_Obj that contains it.  
	 */
	if (node != NULL) {
	    if (Blt_TreeUnsetValueByKey(tvPtr->interp, eventPtr->tree, node, 
		   tvPtr->treeColumn.key) != TCL_OK) { 
		return TCL_ERROR;
	    }
	}
	break;
    case TREE_NOTIFY_RELABEL:
	if (node != NULL) {
	    entryPtr = NodeToEntry(tvPtr, node);
	    entryPtr->flags |= ENTRY_DIRTY;
	}
	/*FALLTHRU*/
    case TREE_NOTIFY_MOVE:
    case TREE_NOTIFY_SORT:
	Blt_TreeViewEventuallyRedraw(tvPtr);
	tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
	break;
    default:
	/* empty */
	break;
    }	
    return TCL_OK;
}

static TreeViewValue *
FindValue(entryPtr, columnPtr)
    TreeViewEntry *entryPtr;
    TreeViewColumn *columnPtr;
{
    register TreeViewValue *valuePtr;

    for (valuePtr = entryPtr->values; valuePtr != NULL; 
	 valuePtr = valuePtr->nextPtr) {
	if (valuePtr->columnPtr == columnPtr) {
	    return valuePtr;
	}
    }
    return NULL;
}

Tcl_Obj *
Blt_TreeViewGetData(entryPtr, key)
    TreeViewEntry *entryPtr;
    Blt_TreeKey key;
{
    Tcl_Obj *objPtr;

    if (Blt_TreeGetValueByKey((Tcl_Interp *)NULL, entryPtr->tvPtr->tree, 
	      entryPtr->node, key, &objPtr) != TCL_OK) {
	return NULL;
    }
    return objPtr;
}

void
Blt_TreeViewAddValue(entryPtr, columnPtr)
    TreeViewEntry *entryPtr;
    TreeViewColumn *columnPtr;
{
    if (FindValue(entryPtr, columnPtr) == NULL) {
	Tcl_Obj *objPtr;

	objPtr = Blt_TreeViewGetData(entryPtr, columnPtr->key);
	if (objPtr != NULL) {
	    TreeViewValue *valuePtr;

	    /* Add a new value only if a data entry exists. */
	    valuePtr = Blt_PoolAllocItem(entryPtr->tvPtr->valuePool, 
			 sizeof(TreeViewValue));
	    valuePtr->columnPtr = columnPtr;
	    valuePtr->image = NULL;
	    valuePtr->nextPtr = entryPtr->values;
	    valuePtr->textPtr = NULL;
	    valuePtr->width = valuePtr->height = 0;
	    valuePtr->stylePtr = NULL;
	    entryPtr->values = valuePtr;
	}
    }
    entryPtr->tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
    entryPtr->flags |= ENTRY_DIRTY;
}

/*
 *----------------------------------------------------------------------
 *
 * TreeTraceProc --
 *
 *	Mirrors the individual values of the tree object (they must
 *	also be listed in the widget's columns chain). This is because
 *	it must track and save the sizes of each individual data
 *	entry, rather than re-computing all the sizes each time the
 *	widget is redrawn.
 *
 *	This procedure is called by the Tree object when a node data
 *	value is set unset.
 *
 * Results:
 *	Returns TCL_OK.
 *
 *---------------------------------------------------------------------- 
 */
/*ARGSUSED*/
static int
TreeTraceProc(clientData, interp, node, key, flags)
    ClientData clientData;
    Tcl_Interp *interp;
    Blt_TreeNode node;		/* Node that has just been updated. */
    Blt_TreeKey key;		/* Key of value that's been updated. */
    unsigned int flags;
{
    Blt_HashEntry *hPtr;
    TreeView *tvPtr = clientData; 
    TreeViewColumn *columnPtr;
    TreeViewEntry *entryPtr;
    TreeViewValue *valuePtr, *nextPtr, *lastPtr;
    
    entryPtr = NodeToEntry(tvPtr, node);
    if (entryPtr == NULL) {
	return TCL_OK;
    }
    switch (flags & (TREE_TRACE_WRITE | TREE_TRACE_READ | TREE_TRACE_UNSET)) {
    case TREE_TRACE_WRITE:
	hPtr = Blt_FindHashEntry(&tvPtr->columnTable, key);
	if (hPtr == NULL) {
	    return TCL_OK;	/* Data value isn't used by widget. */
	}
	columnPtr = Blt_GetHashValue(hPtr);
	if (columnPtr != &tvPtr->treeColumn) {
	    Blt_TreeViewAddValue(entryPtr, columnPtr);
	}
	entryPtr->flags |= ENTRY_DIRTY;
	Blt_TreeViewEventuallyRedraw(tvPtr);
	tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
	break;

    case TREE_TRACE_UNSET:
	lastPtr = NULL;
	for(valuePtr = entryPtr->values; valuePtr != NULL; 
	    valuePtr = nextPtr) {
	    nextPtr = valuePtr->nextPtr;
	    if (valuePtr->columnPtr->key == key) { 
		Blt_TreeViewDestroyValue(tvPtr, valuePtr);
		if (lastPtr == NULL) {
		    entryPtr->values = nextPtr;
		} else {
		    lastPtr->nextPtr = nextPtr;
		}
		entryPtr->flags |= ENTRY_DIRTY;
		Blt_TreeViewEventuallyRedraw(tvPtr);
		tvPtr->flags |= (TV_LAYOUT | TV_DIRTY);
		break;
	    }
	    lastPtr = valuePtr;
	}		
	break;

    default:
	break;
    }
    return TCL_OK;
}


static void
GetValueSize(tvPtr, entryPtr, valuePtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    TreeViewValue *valuePtr;
{
    Tcl_Obj *objPtr;
    TextLayout *textPtr;
    TreeViewColumn *columnPtr;
    TreeViewImage image;
    char *string;
    int width, height;

    columnPtr = valuePtr->columnPtr;
    valuePtr->width = valuePtr->height = 0;
    objPtr = Blt_TreeViewGetData(entryPtr, columnPtr->key);
    if (objPtr == NULL) {
	return;			/* No data ??? */
    }
    string = Tcl_GetString(objPtr);
    if (string[0] == '@') {	/* Name of Tk image. */
	image = Blt_TreeViewGetImage(tvPtr, string + 1);
	if (image == NULL) {
	    goto handleString;
	}
	width = TreeViewImageWidth(image);
	height = TreeViewImageHeight(image);
	textPtr = NULL;
    } else {			/* Text string. */
	TextStyle ts;

    handleString:
	Blt_InitTextStyle(&ts);
	ts.font = columnPtr->font;
	ts.anchor = TK_ANCHOR_NW;
	ts.justify = TK_JUSTIFY_LEFT;
	textPtr = Blt_GetTextLayout(string, &ts);
	image = NULL;
	width = textPtr->width;
	height = textPtr->height;
    }
    valuePtr->width = width;
    valuePtr->height = height;
    if (valuePtr->image != NULL) {
	Blt_TreeViewFreeImage(tvPtr, valuePtr->image);
    }
    if (valuePtr->textPtr != NULL) {
	Blt_Free(valuePtr->textPtr);
    }
    valuePtr->image = image;
    valuePtr->textPtr = textPtr;
}

static void
GetRowExtents(tvPtr, entryPtr, widthPtr, heightPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    int *widthPtr, *heightPtr;
{
    TreeViewValue *valuePtr;
    int valueWidth;		/* Width of individual value.  */
    int width, height;		/* Compute dimensions of row. */

    width = height = 0;
    for (valuePtr = entryPtr->values; valuePtr != NULL; 
	valuePtr = valuePtr->nextPtr) {
	if ((entryPtr->flags & ENTRY_DIRTY) || 
	    (valuePtr->columnPtr->flags & COLUMN_DIRTY)) {
	    GetValueSize(tvPtr, entryPtr, valuePtr);
	}
	if (valuePtr->height > height) {
	    height = valuePtr->height;
	}
	if (valuePtr->columnPtr->maxWidth < valuePtr->width) {
	    valuePtr->columnPtr->maxWidth = valuePtr->width;
	}
	valueWidth = valuePtr->width;
	width += valueWidth;
    }	    
    *widthPtr = width;
    *heightPtr = height;
}


/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewNearestEntry --
 *
 *	Finds the entry closest to the given screen X-Y coordinates
 *	in the viewport.
 *
 * Results:
 *	Returns the pointer to the closest node.  If no node is
 *	visible (nodes may be hidden), NULL is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
TreeViewEntry *
Blt_TreeViewNearestEntry(tvPtr, x, y, selectOne)
    TreeView *tvPtr;
    int x, y;
    int selectOne;
{
    TreeViewEntry *lastPtr, *entryPtr;
    register TreeViewEntry **p;

    /*
     * We implicitly can pick only visible entries.  So make sure that
     * the tree exists.
     */
    if (tvPtr->nVisible == 0) {
	return NULL;
    }
    if (y < tvPtr->titleHeight) {
	return (selectOne) ? tvPtr->visibleArr[0] : NULL;
    }
    /*
     * Since the entry positions were previously computed in world
     * coordinates, convert Y-coordinate from screen to world
     * coordinates too.
     */
    y = WORLDY(tvPtr, y);
    lastPtr = tvPtr->visibleArr[0];
    for (p = tvPtr->visibleArr; *p != NULL; p++) {
	entryPtr = *p;
	/*
	 * If the start of the next entry starts beyond the point,
	 * use the last entry.
	 */
	if (entryPtr->worldY > y) {
	    return (selectOne) ? entryPtr : NULL;
	}
	if (y < (entryPtr->worldY + entryPtr->height)) {
	    return entryPtr;	/* Found it. */
	}
	lastPtr = entryPtr;
    }
    return (selectOne) ? lastPtr : NULL;
}

static void
GetColumnTags(table, object, list)
    Blt_BindTable table;
    ClientData object;
    Blt_List list;
{
    TreeView *tvPtr;
    TreeViewColumn *columnPtr;

    tvPtr = Blt_GetBindingData(table);
    columnPtr = object;
    if (columnPtr->type == TV_ITEM_RULE) {
	Blt_ListAppend(list, Blt_TreeViewGetUid(tvPtr, "Rule"), 0);
    } else {
	Blt_ListAppend(list, (char *)object, 0);
	if (columnPtr->tagsUid != NULL) {
	    int nNames;
	    char **names;
	    register char **p;
	    
	    if (Tcl_SplitList((Tcl_Interp *)NULL, columnPtr->tagsUid, &nNames,
			      &names) == TCL_OK) {
		for (p = names; *p != NULL; p++) {
		    Blt_ListAppend(list, Blt_TreeViewGetUid(tvPtr, *p), 0);
		}
		Blt_Free(names);
	    }
	}
    }
}

/*ARGSUSED*/
static ClientData
PickColumn(clientData, x, y)
    ClientData clientData;
    int x, y;			/* Screen coordinates of the test point. */
{
    TreeView *tvPtr = clientData;
    TreeViewColumn *columnPtr;

    if ((tvPtr->flags & TV_SHOW_COLUMN_TITLES) == 0) {
	return NULL;
    }
    if (tvPtr->flags & TV_DIRTY) {
	/* Can't trust selected entry, if entries have been added or
	 * deleted. */
	if (tvPtr->flags & TV_LAYOUT) {
	    Blt_TreeViewComputeLayout(tvPtr);
	}
	ComputeVisibleEntries(tvPtr);
    }
    columnPtr = Blt_TreeViewNearestColumn(tvPtr, x, y, SEARCH_Y);
    if ((columnPtr != NULL) && (columnPtr->flags & COLUMN_RULE_PICKED)) {
	columnPtr->flags &= ~COLUMN_RULE_PICKED;
	return &columnPtr->rule;
    }
    return columnPtr;
}

static void
GetTags(table, object, list)
    Blt_BindTable table;
    ClientData object;
    Blt_List list;
{
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;

    tvPtr = Blt_GetBindingData(table);
    Blt_ListAppend(list, (char *)object, 0);
    entryPtr = object;
    if (entryPtr->tagsUid != NULL) {
	int nNames;
	char **names;
	register char **p;

	if (Tcl_SplitList((Tcl_Interp *)NULL, entryPtr->tagsUid, &nNames,
		&names) == TCL_OK) {
	    for (p = names; *p != NULL; p++) {
		Blt_ListAppend(list, Blt_TreeViewGetUid(tvPtr, *p), 0);
	    }
	    Blt_Free(names);
	}
    }
    Blt_TreeViewGetTags(tvPtr->interp, tvPtr, entryPtr, list);
}

/*ARGSUSED*/
static ClientData
PickButton(clientData, x, y)
    ClientData clientData;
    int x, y;			/* Screen coordinates of the test point. */
{
    TreeView *tvPtr = clientData;
    register TreeViewEntry *entryPtr;

    if (tvPtr->flags & TV_DIRTY) {
	/* Can't trust selected entry, if entries have been added or
	 * deleted. */
	if (tvPtr->flags & TV_LAYOUT) {
	    Blt_TreeViewComputeLayout(tvPtr);
	}
	ComputeVisibleEntries(tvPtr);
    }
    if (tvPtr->nVisible == 0) {
	return (ClientData)0;
    }
    entryPtr = Blt_TreeViewNearestEntry(tvPtr, x, y, FALSE);
    if (entryPtr == NULL) {
	return (ClientData)0;
    }
    if (entryPtr->flags & ENTRY_HAS_BUTTON) {
	TreeViewButton *buttonPtr = &tvPtr->button;
	int left, right, top, bottom;
#define BUTTON_PAD 2
	left = entryPtr->worldX + entryPtr->buttonX - BUTTON_PAD;
	right = left + buttonPtr->width + 2 * BUTTON_PAD;
	top = entryPtr->worldY + entryPtr->buttonY - BUTTON_PAD;
	bottom = top + buttonPtr->height + 2 * BUTTON_PAD;
	x = WORLDX(tvPtr, x);
	y = WORLDY(tvPtr, y);
	if ((x >= left) && (x < right) && (y >= top) && (y < bottom)) {
	    return entryPtr;
	}
    }
    return NULL;
}

/*ARGSUSED*/
static ClientData
PickEntry(clientData, x, y)
    ClientData clientData;
    int x, y;			/* Screen coordinates of the test point. */
{
    TreeView *tvPtr = clientData;
    register TreeViewEntry *entryPtr;
    int labelX;

    if (tvPtr->flags & TV_DIRTY) {
	/* Can't trust the selected entry if nodes have been added or
	 * deleted. So recompute the layout. */
	if (tvPtr->flags & TV_LAYOUT) {
	    Blt_TreeViewComputeLayout(tvPtr);
	}
	ComputeVisibleEntries(tvPtr);
    }
    if (tvPtr->nVisible == 0) {
	return NULL;
    }
    entryPtr = Blt_TreeViewNearestEntry(tvPtr, x, y, FALSE);
    if (entryPtr == NULL) {
	return NULL;
    }
    x = WORLDX(tvPtr, x);
    y = WORLDY(tvPtr, y);
    labelX = entryPtr->worldX;
    if (!tvPtr->flatView) {
	labelX += ICONWIDTH(DEPTH(tvPtr, entryPtr->node));
    }
    if (entryPtr->flags & ENTRY_HAS_BUTTON) {
	TreeViewButton *buttonPtr = &tvPtr->button;
	int left, right, top, bottom;

	left = entryPtr->worldX + entryPtr->buttonX - BUTTON_PAD;
	right = left + buttonPtr->width + 2 * BUTTON_PAD;
	top = entryPtr->worldY + entryPtr->buttonY - BUTTON_PAD;
	bottom = top + buttonPtr->height + 2 * BUTTON_PAD;
	if ((x >= left) && (x < right) && (y >= top) && (y < bottom)) {
	    return NULL;
	}
    }
    return entryPtr;
}

static void
GetEntryExtents(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    Tk_Font font;
    TreeViewImage *icons;
    char *label;
    int entryWidth, entryHeight;
    int width, height;

    /*
     * FIXME: Use of DIRTY flag inconsistent.  When does it
     *	      mean "dirty entry"? When does it mean "dirty column"?
     *	      Does it matter? probably
     */
    if ((entryPtr->flags & ENTRY_DIRTY) || (tvPtr->flags & TV_UPDATE)) {
	entryPtr->iconWidth = entryPtr->iconHeight = 0;
	icons = CHOOSE(tvPtr->icons, entryPtr->icons);
	if (icons != NULL) {
	    register int i;
	    
	    for (i = 0; i < 2; i++) {
		if (icons[i] == NULL) {
		    break;
		}
		if (entryPtr->iconWidth < TreeViewImageWidth(icons[i])) {
		    entryPtr->iconWidth = TreeViewImageWidth(icons[i]);
		}
		if (entryPtr->iconHeight < TreeViewImageHeight(icons[i])) {
		    entryPtr->iconHeight = TreeViewImageHeight(icons[i]);
		}
	    }
	}
	if ((icons == NULL) || (icons[0] == NULL)) {
	    entryPtr->iconWidth = DEF_ICON_WIDTH;
	    entryPtr->iconHeight = DEF_ICON_HEIGHT;
	}
	entryPtr->iconWidth += 2 * ICON_PADX;
	entryPtr->iconHeight += 2 * ICON_PADY;
	entryHeight = MAX(entryPtr->iconHeight, tvPtr->button.height);
	entryWidth = 0;
	font = CHOOSE(tvPtr->treeColumn.font, entryPtr->font);
	if (entryPtr->fullName != NULL) {
	    Blt_Free(entryPtr->fullName);
	    entryPtr->fullName = NULL;
	}
	if (entryPtr->textPtr != NULL) {
	    Blt_Free(entryPtr->textPtr);
	    entryPtr->textPtr = NULL;
	}
	
	label = GETLABEL(entryPtr);
	if (label[0] == '\0') {
	    Tk_FontMetrics fontMetrics;
	    
	    Tk_GetFontMetrics(font, &fontMetrics);
	    width = height = fontMetrics.linespace;
	} else {
	    TextStyle ts;

	    Blt_InitTextStyle(&ts);
	    ts.shadow.offset = entryPtr->shadow.offset;
	    ts.font = font;
	    
	    if (tvPtr->flatView) {
		Tcl_DString dString;

		Blt_TreeViewGetFullName(tvPtr, entryPtr, TRUE, &dString);
		entryPtr->fullName = Blt_Strdup(Tcl_DStringValue(&dString));
		Tcl_DStringFree(&dString);
		entryPtr->textPtr = Blt_GetTextLayout(entryPtr->fullName, &ts);
	    } else {
		entryPtr->textPtr = Blt_GetTextLayout(label, &ts);
	    }
	    width = entryPtr->textPtr->width;
	    height = entryPtr->textPtr->height;
	}
	width += 2 * (FOCUS_WIDTH + LABEL_PADX + tvPtr->selBorderWidth);
	height += 2 * (FOCUS_WIDTH + LABEL_PADY + tvPtr->selBorderWidth);
	width = ODD(width);
	if (entryPtr->reqHeight > height) {
	    height = entryPtr->reqHeight;
	} 
	height = ODD(height);
	entryWidth = width;
	if (entryHeight < height) {
	    entryHeight = height;
	}
	entryPtr->labelWidth = width;
	entryPtr->labelHeight = height;
    } else {
	entryHeight = entryPtr->labelHeight;
	entryWidth = entryPtr->labelWidth;
    }
    /*  
     * Find the maximum height of the data value entries. This also has
     * the side effect of contributing the maximum width of the column. 
     */
    GetRowExtents(tvPtr, entryPtr, &width, &height);
    if (entryHeight < height) {
	entryHeight = height;
    }
    entryPtr->width = entryWidth + COLUMN_PAD;
    entryPtr->height = entryHeight + tvPtr->leader;
    /*
     * Force the height of the entry to an even number. This is to
     * make the dots or the vertical line segments coincide with the
     * start of the horizontal lines.
     */
    if (entryPtr->height & 0x01) {
	entryPtr->height++;
    }
    entryPtr->flags &= ~ENTRY_DIRTY;
}

/*
 * TreeView Procedures
 */

/*
 * ----------------------------------------------------------------------
 *
 * CreateTreeView --
 *
 * ----------------------------------------------------------------------
 */
static TreeView *
CreateTreeView(interp, objPtr, className)
    Tcl_Interp *interp;
    Tcl_Obj *objPtr;		/* Name of the new widget. */
    char *className;
{
    Tcl_DString dString;
    Tk_Window tkwin;
    TreeView *tvPtr;
    char *name;
    int result;

    name = Tcl_GetString(objPtr);
    tkwin = Tk_CreateWindowFromPath(interp, Tk_MainWindow(interp), name,
	(char *)NULL);
    if (tkwin == NULL) {
	return NULL;
    }
    Tk_SetClass(tkwin, className);

    tvPtr = Blt_Calloc(1, sizeof(TreeView));
    assert(tvPtr);
    tvPtr->tkwin = tkwin;
    tvPtr->display = Tk_Display(tkwin);
    tvPtr->interp = interp;
    tvPtr->flags = TV_HIDE_ROOT | TV_SHOW_COLUMN_TITLES | TV_DIRTY | TV_LAYOUT;
    tvPtr->leader = 0;
    tvPtr->dashes = 1;
    tvPtr->highlightWidth = 2;
    tvPtr->selBorderWidth = 1;
    tvPtr->borderWidth = 2;
    tvPtr->relief = TK_RELIEF_SUNKEN;
    tvPtr->selRelief = TK_RELIEF_FLAT;
    tvPtr->scrollMode = BLT_SCROLL_MODE_HIERBOX;
    tvPtr->selectMode = SELECT_MODE_SINGLE;
    tvPtr->button.closeRelief = tvPtr->button.openRelief = TK_RELIEF_SOLID;
    tvPtr->reqWidth = 200;
    tvPtr->reqHeight = 400;
    tvPtr->xScrollUnits = tvPtr->yScrollUnits = 20;
    tvPtr->lineWidth = 1;
    tvPtr->button.borderWidth = 1;
    tvPtr->colChainPtr = Blt_ChainCreate();
    tvPtr->buttonFlags = BUTTON_AUTO;
    tvPtr->selChainPtr = Blt_ChainCreate();
    tvPtr->tagTablePtr = Blt_TreeNewTagTable();
    Blt_InitHashTable(&tvPtr->columnTable, BLT_ONE_WORD_KEYS);
    Blt_InitHashTable(&tvPtr->imageTable, BLT_STRING_KEYS);
    Blt_InitHashTable(&tvPtr->selectTable, BLT_ONE_WORD_KEYS);
    Blt_InitHashTable(&tvPtr->uidTable, BLT_STRING_KEYS);
    Blt_InitHashTable(&tvPtr->styleTable, BLT_STRING_KEYS);
    tvPtr->bindTable = Blt_CreateBindingTable(interp, tkwin, tvPtr, 
	PickEntry, GetTags);
    tvPtr->buttonBindTable = Blt_CreateBindingTable(interp, tkwin, tvPtr, 
	PickButton, GetTags);
    tvPtr->columnBindTable = Blt_CreateBindingTable(interp, tkwin, tvPtr, 
	PickColumn, GetColumnTags);
    tvPtr->entryPool = Blt_PoolCreate(BLT_FIXED_SIZE_ITEMS);
    tvPtr->valuePool = Blt_PoolCreate(BLT_FIXED_SIZE_ITEMS);
#if (TK_MAJOR_VERSION > 4)
    Blt_SetWindowInstanceData(tkwin, tvPtr);
#endif
    /* Create a default column to display the view of the tree. */
    Tcl_DStringInit(&dString);
    Tcl_DStringAppend(&dString, "BLT TreeView ", -1);
    Tcl_DStringAppend(&dString, Tk_PathName(tkwin), -1);
    result = Blt_TreeViewInitColumn(tvPtr, &tvPtr->treeColumn, 
	Tcl_DStringValue(&dString), "", 0, (Tcl_Obj *CONST *)NULL);
    Tcl_DStringFree(&dString);
    if (result != TCL_OK) {
	Tk_DestroyWindow(tkwin);
	return NULL;
    }
    Blt_ChainAppend(tvPtr->colChainPtr, &tvPtr->treeColumn);
    tvPtr->editPtr = Blt_TreeViewCreateEditor(tvPtr, className);
    return tvPtr;
}

/*
 * ----------------------------------------------------------------------
 *
 * DestroyTreeView --
 *
 * 	This procedure is invoked by Tcl_EventuallyFree or Tcl_Release
 *	to clean up the internal structure of a TreeView at a safe time
 *	(when no-one is using it anymore).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Everything associated with the widget is freed up.
 *
 * ----------------------------------------------------------------------
 */
static void
DestroyTreeView(dataPtr)
    DestroyData dataPtr;	/* Pointer to the widget record. */
{
    TreeView *tvPtr = (TreeView *)dataPtr;
    TreeViewButton *buttonPtr = &tvPtr->button;
    
    tvPtr->flags |= TV_DESTROYED;

    treeOption.clientData = tvPtr;
    bltTreeViewImagesOption.clientData = tvPtr;
    Blt_FreeObjOptions(bltTreeViewSpecs, (char *)tvPtr, tvPtr->display, 0);

    if (tvPtr->tkwin != NULL) {
	Tk_DeleteSelHandler(tvPtr->tkwin, XA_PRIMARY, XA_STRING);
    }
    if (tvPtr->lineGC != NULL) {
	Tk_FreeGC(tvPtr->display, tvPtr->lineGC);
    }
    if (tvPtr->focusGC != NULL) {
	Blt_FreePrivateGC(tvPtr->display, tvPtr->focusGC);
    }
    if (tvPtr->visibleArr != NULL) {
	Blt_Free(tvPtr->visibleArr);
    }
    if (tvPtr->flatArr != NULL) {
	Blt_Free(tvPtr->flatArr);
    }
    if (tvPtr->levelInfo != NULL) {
	Blt_Free(tvPtr->levelInfo);
    }
    if (buttonPtr->activeGC != NULL) {
	Tk_FreeGC(tvPtr->display, buttonPtr->activeGC);
    }
    if (buttonPtr->normalGC != NULL) {
	Tk_FreeGC(tvPtr->display, buttonPtr->normalGC);
    }
    if (buttonPtr->lineGC != NULL) {
	Tk_FreeGC(tvPtr->display, buttonPtr->lineGC);
    }
    if (tvPtr->drawable != None) {
	Tk_FreePixmap(tvPtr->display, tvPtr->drawable);
    }

    Blt_TreeViewDestroyColumns(tvPtr);
    Blt_DestroyBindingTable(tvPtr->bindTable);
    Blt_DestroyBindingTable(tvPtr->buttonBindTable);
    Blt_DestroyBindingTable(tvPtr->columnBindTable);
    Blt_ChainDestroy(tvPtr->selChainPtr);
    Blt_DeleteHashTable(&tvPtr->selectTable);
    Blt_DeleteHashTable(&tvPtr->uidTable);
    if (tvPtr->tagTablePtr != NULL) {
	Blt_TreeReleaseTagTable(tvPtr->tagTablePtr);
    }
    Blt_PoolDestroy(tvPtr->entryPool);
    Blt_PoolDestroy(tvPtr->valuePool);
    DumpImageTable(tvPtr);
    Blt_Free(tvPtr);
}

/*
 * --------------------------------------------------------------
 *
 * TreeViewEventProc --
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
TreeViewEventProc(clientData, eventPtr)
    ClientData clientData;	/* Information about window. */
    XEvent *eventPtr;		/* Information about event. */
{
    TreeView *tvPtr = clientData;

    if (eventPtr->type == Expose) {
	if (eventPtr->xexpose.count == 0) {
	    Blt_TreeViewEventuallyRedraw(tvPtr);
	}
    } else if (eventPtr->type == ConfigureNotify) {
	tvPtr->flags |= (TV_LAYOUT | TV_SCROLL);
	Blt_TreeViewEventuallyRedraw(tvPtr);
    } else if ((eventPtr->type == FocusIn) || (eventPtr->type == FocusOut)) {
	if (eventPtr->xfocus.detail != NotifyInferior) {
	    if (eventPtr->type == FocusIn) {
		tvPtr->flags |= TV_FOCUS;
	    } else {
		tvPtr->flags &= ~TV_FOCUS;
	    }
	    Blt_TreeViewEventuallyRedraw(tvPtr);
	}
    } else if (eventPtr->type == DestroyNotify) {
	if (tvPtr->tkwin != NULL) {
	    tvPtr->tkwin = NULL;
	    Tcl_DeleteCommandFromToken(tvPtr->interp, tvPtr->cmdToken);
	}
	if (tvPtr->flags & TV_REDRAW) {
	    Tcl_CancelIdleCall(DisplayTreeView, tvPtr);
	}
	if (tvPtr->flags & TV_SELECT_PENDING) {
	    Tcl_CancelIdleCall(Blt_TreeViewSelectCmdProc, tvPtr);
	}
	Tcl_EventuallyFree(tvPtr, DestroyTreeView);
    }
}

/* Selection Procedures */
/*
 *----------------------------------------------------------------------
 *
 * SelectionProc --
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
SelectionProc(clientData, offset, buffer, maxBytes)
    ClientData clientData;	/* Information about the widget. */
    int offset;			/* Offset within selection of first
				 * character to be returned. */
    char *buffer;		/* Location in which to place
				 * selection. */
    int maxBytes;		/* Maximum number of bytes to place
				 * at buffer, not including terminating
				 * NULL character. */
{
    Tcl_DString dString;
    TreeView *tvPtr = clientData;
    TreeViewEntry *entryPtr;
    int size;

    if ((tvPtr->flags & TV_SELECT_EXPORT) == 0) {
	return -1;
    }
    /*
     * Retrieve the names of the selected entries.
     */
    Tcl_DStringInit(&dString);
    if (tvPtr->flags & TV_SELECT_SORTED) {
	Blt_ChainLink *linkPtr;

	for (linkPtr = Blt_ChainFirstLink(tvPtr->selChainPtr); 
	     linkPtr != NULL; linkPtr = Blt_ChainNextLink(linkPtr)) {
	    entryPtr = Blt_ChainGetValue(linkPtr);
	    Tcl_DStringAppend(&dString, GETLABEL(entryPtr), -1);
	    Tcl_DStringAppend(&dString, "\n", -1);
	}
    } else {
	for (entryPtr = tvPtr->rootPtr; entryPtr != NULL; 
	     entryPtr = Blt_TreeViewNextEntry(tvPtr, entryPtr, ENTRY_MASK)) {
	    if (Blt_TreeViewEntryIsSelected(tvPtr, entryPtr)) {
		Tcl_DStringAppend(&dString, GETLABEL(entryPtr), -1);
		Tcl_DStringAppend(&dString, "\n", -1);
	    }
	}
    }
    size = Tcl_DStringLength(&dString) - offset;
    strncpy(buffer, Tcl_DStringValue(&dString) + offset, maxBytes);
    Tcl_DStringFree(&dString);
    buffer[maxBytes] = '\0';
    return (size > maxBytes) ? maxBytes : size;
}

/*
 *----------------------------------------------------------------------
 *
 * WidgetInstCmdDeleteProc --
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
WidgetInstCmdDeleteProc(clientData)
    ClientData clientData;	/* Pointer to widget record for widget. */
{
    TreeView *tvPtr = clientData;

    /*
     * This procedure could be invoked either because the window was
     * destroyed and the command was then deleted (in which case tkwin
     * is NULL) or because the command was deleted, and then this
     * procedure destroys the widget.
     */
    if (tvPtr->tkwin != NULL) {
	Tk_Window tkwin;

	tkwin = tvPtr->tkwin;
	tvPtr->tkwin = NULL;
	Tk_DestroyWindow(tkwin);
#ifdef ITCL_NAMESPACES
	Itk_SetWidgetCommand(tkwin, (Tcl_Command) NULL);
#endif /* ITCL_NAMESPACES */
    }
}

/*
 * ----------------------------------------------------------------------
 *
 * Blt_TreeViewConfigureWidget --
 *
 * 	This procedure is called to process an objv/objc list, plus
 *	the Tk option database, in order to configure (or reconfigure)
 *	the widget.
 *
 * Results:
 *	The return value is a standard Tcl result.  If TCL_ERROR is
 * 	returned, then interp->result contains an error message.
 *
 * Side effects:
 *	Configuration information, such as text string, colors, font,
 *	etc. get set for tvPtr; old resources get freed, if there
 *	were any.  The widget is redisplayed.
 *
 * ----------------------------------------------------------------------
 */
int
Blt_TreeViewConfigureWidget(interp, tvPtr, objc, objv, flags)
    Tcl_Interp *interp;
    TreeView *tvPtr;		/* Information about widget; may or may not
			         * already have values for some values. */
    int objc;
    Tcl_Obj *CONST *objv;
    int flags;
{
    GC newGC;
    XGCValues gcValues;
    int oldView, setupTree;
    unsigned long gcMask;

    oldView = tvPtr->flatView;

    treeOption.clientData = tvPtr;
    bltTreeViewImagesOption.clientData = tvPtr;
    if (Blt_ConfigureWidgetFromObj(interp, tvPtr->tkwin, bltTreeViewSpecs, 
	objc, objv, (char *)tvPtr, flags) != TCL_OK) {
	return TCL_ERROR;
    }
    /*
     * GC for dotted vertical line.
     */
    gcMask = (GCForeground | GCLineWidth);
    gcValues.foreground = tvPtr->lineColor->pixel;
    gcValues.line_width = tvPtr->lineWidth;
    if (tvPtr->dashes > 0) {
	gcMask |= (GCLineStyle | GCDashList);
	gcValues.line_style = LineOnOffDash;
	gcValues.dashes = tvPtr->dashes;
    }
    newGC = Tk_GetGC(tvPtr->tkwin, gcMask, &gcValues);
    if (tvPtr->lineGC != NULL) {
	Tk_FreeGC(tvPtr->display, tvPtr->lineGC);
    }
    tvPtr->lineGC = newGC;

    /*
     * GC for active label. Dashed outline.
     */
    gcMask = GCForeground | GCLineStyle;
    gcValues.foreground = tvPtr->focusColor->pixel;
    gcValues.line_style = (LineIsDashed(tvPtr->focusDashes))
	? LineOnOffDash : LineSolid;
    newGC = Blt_GetPrivateGC(tvPtr->tkwin, gcMask, &gcValues);
    if (LineIsDashed(tvPtr->focusDashes)) {
	tvPtr->focusDashes.offset = 2;
	Blt_SetDashes(tvPtr->display, newGC, &tvPtr->focusDashes);
    }
    if (tvPtr->focusGC != NULL) {
	Blt_FreePrivateGC(tvPtr->display, tvPtr->focusGC);
    }
    tvPtr->focusGC = newGC;

    Blt_TreeViewConfigureButtons(tvPtr);
    tvPtr->inset = tvPtr->highlightWidth + tvPtr->borderWidth + INSET_PAD;

    setupTree = FALSE;

    /*
     * If no tree object was named, allocate a new one.  The name will
     * be the same as the widget pathname.
     */
    if (tvPtr->tree == NULL) {
	Blt_Tree token;
	char *string;

	string = Tk_PathName(tvPtr->tkwin);
	if (Blt_TreeCreate(interp, string, &token) != TCL_OK) {
	    return TCL_ERROR;
	}
	tvPtr->tree = token;
	setupTree = TRUE;
    } 

    /*
     * If the tree object was changed, we need to setup the new one.
     */
    if (Blt_ObjConfigModified(bltTreeViewSpecs, "-tree", (char *)NULL)) {
	setupTree = TRUE;
    }

    /*
     * These options change the layout of the box.  Mark the widget for update.
     */
    if (Blt_ObjConfigModified(bltTreeViewSpecs, "-font", 
	"-linespacing", "-width", "-height", "-hide*", "-tree", "-flat", 
	(char *)NULL)) {
	tvPtr->flags |= (TV_LAYOUT | TV_SCROLL);
    }
    if ((tvPtr->flatView != oldView) || 
	(Blt_ObjConfigModified(bltTreeViewSpecs, "-hideleaves", 
			       (char *)NULL))) {
	TreeViewEntry *entryPtr;
	
	tvPtr->flags |= TV_DIRTY;
	/* Mark all entries dirty. */
	for (entryPtr = tvPtr->rootPtr; entryPtr != NULL; 
	     entryPtr = Blt_TreeViewNextEntry(tvPtr, entryPtr, 0)) {
	    entryPtr->flags |= ENTRY_DIRTY;
	}
	if ((!tvPtr->flatView) && (tvPtr->flatArr != NULL)) {
	    Blt_Free(tvPtr->flatArr);
	    tvPtr->flatArr = NULL;
	}
    }
	
    /*
     * If the tree view was changed, mark all the nodes dirty (we'll
     * be switching back to either the full path name or the label)
     * and free the array representing the flattened view of the tree.
     */
    if (tvPtr->flatView != oldView) {
	TreeViewEntry *entryPtr;
	
	tvPtr->flags |= TV_DIRTY;
	/* Mark all entries dirty. */
	for (entryPtr = tvPtr->rootPtr; entryPtr != NULL; 
	     entryPtr = Blt_TreeViewNextEntry(tvPtr, entryPtr, 0)) {
	    entryPtr->flags |= ENTRY_DIRTY;
	}
	if ((!tvPtr->flatView) && (tvPtr->flatArr != NULL)) {
	    Blt_Free(tvPtr->flatArr);
	    tvPtr->flatArr = NULL;
	}
    }
    if ((tvPtr->reqHeight != Tk_ReqHeight(tvPtr->tkwin)) ||
	(tvPtr->reqWidth != Tk_ReqWidth(tvPtr->tkwin))) {
	Tk_GeometryRequest(tvPtr->tkwin, tvPtr->reqWidth, tvPtr->reqHeight);
    }

    if (setupTree) {
	Blt_TreeNode root;

	Blt_TreeCreateEventHandler(tvPtr->tree, 
				   TREE_NOTIFY_ALL | TREE_NOTIFY_FOREIGN_ONLY, 
				   TreeEventProc, 
				   tvPtr);
	TraceColumns(tvPtr);
	root = Blt_TreeRootNode(tvPtr->tree);

	/* Automatically add view-entry values to the new tree. */
	Blt_TreeApply(root, CreateApplyProc, tvPtr);
	tvPtr->focusPtr = tvPtr->rootPtr = NodeToEntry(tvPtr, root);
	tvPtr->selMarkPtr = tvPtr->selAnchorPtr = NULL;
	Blt_SetFocusItem(tvPtr->bindTable, tvPtr->rootPtr);

	/* Automatically open the root node. */
	if (Blt_TreeViewOpenEntry(tvPtr, tvPtr->rootPtr) != TCL_OK) {
	    return TCL_ERROR;
	}
	if ((tvPtr->flags & TV_NEW_TAGS) || 
	    (Blt_TreeCmdGetTagTable(interp, Blt_TreeName(tvPtr->tree), 
			    &tvPtr->tagTablePtr) != TCL_OK)) {
	    tvPtr->tagTablePtr = Blt_TreeNewTagTable();
	}
    }

    if (Blt_ObjConfigModified(bltTreeViewSpecs, "-font", "-color", 
	(char *)NULL)) {
	Blt_TreeViewConfigureColumn(tvPtr, &tvPtr->treeColumn);
    }
    Blt_TreeViewEventuallyRedraw(tvPtr);
    return TCL_OK;
}

/*
 * ----------------------------------------------------------------------
 *
 * ResetCoordinates --
 *
 *	Determines the maximum height of all visible entries.
 *
 *	1. Sets the worldY coordinate for all mapped/open entries.
 *	2. Determines if entry needs a button.
 *	3. Collects the minimum height of open/mapped entries. (Do for all
 *	   entries upon insert).
 *	4. Figures out horizontal extent of each entry (will be width of 
 *	   tree view column).
 *	5. Collects maximum icon size for each level.
 *	6. The height of its vertical line
 *
 * Results:
 *	Returns 1 if beyond the last visible entry, 0 otherwise.
 *
 * Side effects:
 *	The array of visible nodes is filled.
 *
 * ----------------------------------------------------------------------
 */
static void
ResetCoordinates(tvPtr, entryPtr, yPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
    int *yPtr;
{
    int depth;

    entryPtr->worldY = -1;
    entryPtr->lineHeight = -1;
    if ((entryPtr != tvPtr->rootPtr) && 
	(Blt_TreeViewEntryIsHidden(tvPtr, entryPtr))) {
	return;     /* If the entry is hidden, then do nothing. */
    }
    entryPtr->worldY = *yPtr;
    entryPtr->lineHeight = -(*yPtr);
    *yPtr += entryPtr->height;

    depth = DEPTH(tvPtr, entryPtr->node) + 1;
    if (tvPtr->levelInfo[depth].labelWidth < entryPtr->labelWidth) {
	tvPtr->levelInfo[depth].labelWidth = entryPtr->labelWidth;
    }
    if (tvPtr->levelInfo[depth].iconWidth < entryPtr->iconWidth) {
	tvPtr->levelInfo[depth].iconWidth = entryPtr->iconWidth;
    }
    tvPtr->levelInfo[depth].iconWidth |= 0x01;

    if ((entryPtr->flags & ENTRY_CLOSED) == 0) {
	TreeViewEntry *bottomPtr, *childPtr;

	bottomPtr = entryPtr;
	for (childPtr = Blt_TreeViewFirstChild(tvPtr, entryPtr); 
	     childPtr != NULL; 
	     childPtr = Blt_TreeViewNextSibling(tvPtr, childPtr)) {
	    ResetCoordinates(tvPtr, childPtr, yPtr);
	    bottomPtr = childPtr;
	}
	entryPtr->lineHeight += bottomPtr->worldY;
    }
}

static void
AdjustColumns(tvPtr)
    TreeView *tvPtr;
{
    Blt_ChainLink *linkPtr;
    TreeViewColumn *columnPtr;
    double weight;
    int nOpen;
    int size, avail, ration, growth;

    growth = VPORTWIDTH(tvPtr) - tvPtr->worldWidth;
    nOpen = 0;
    weight = 0.0;
    /* Find out how many columns still have space available */
    for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); linkPtr != NULL;
	 linkPtr = Blt_ChainNextLink(linkPtr)) {
	columnPtr = Blt_ChainGetValue(linkPtr);
	if ((columnPtr->hidden) || 
	    (columnPtr->weight == 0.0) || 
	    (columnPtr->width >= columnPtr->max) || 
	    (columnPtr->reqWidth > 0)) {
	    continue;
	}
	nOpen++;
	weight += columnPtr->weight;
    }

    while ((nOpen > 0) && (weight > 0.0) && (growth > 0)) {
	ration = (int)(growth / weight);
	if (ration == 0) {
	    ration = 1;
	}
	for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); 
	     linkPtr != NULL; linkPtr = Blt_ChainNextLink(linkPtr)) {
	    columnPtr = Blt_ChainGetValue(linkPtr);
	    if ((columnPtr->hidden) || 
		(columnPtr->weight == 0.0) ||
		(columnPtr->width >= columnPtr->max) || 
		(columnPtr->reqWidth > 0)) {
		continue;
	    }
	    size = (int)(ration * columnPtr->weight);
	    if (size > growth) {
		size = growth; 
	    }
	    avail = columnPtr->max - columnPtr->width;
	    if (size > avail) {
		size = avail;
		nOpen--;
		weight -= columnPtr->weight;
	    }
	    growth -= size;
	    columnPtr->width += size;
	}
    }
}

/*
 * ----------------------------------------------------------------------
 *
 * Blt_TreeViewComputeLayout --
 *
 *	Recompute the layout when entries are opened/closed,
 *	inserted/deleted, or when text attributes change (such as
 *	font, linespacing).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The world coordinates are set for all the opened entries.
 *
 * ----------------------------------------------------------------------
 */
static void
ComputeFlatLayout(tvPtr)
    TreeView *tvPtr;
{
    Blt_ChainLink *linkPtr;
    TreeViewColumn *columnPtr;
    TreeViewEntry **p;
    TreeViewEntry *entryPtr;
    int count;
    int maxX;
    int y;
    /* 
     * Pass 1:	Reinitialize column sizes and loop through all nodes. 
     *
     *		1. Recalculate the size of each entry as needed. 
     *		2. The maximum depth of the tree. 
     *		3. Minimum height of an entry.  Dividing this by the
     *		   height of the widget gives a rough estimate of the 
     *		   maximum number of visible entries.
     *		4. Build an array to hold level information to be filled
     *		   in on pass 2.
     */
    if (tvPtr->flags & (TV_DIRTY | TV_UPDATE)) {
	int position;

	position = 1;
	for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); 
	     linkPtr != NULL; linkPtr = Blt_ChainNextLink(linkPtr)) {
	    columnPtr = Blt_ChainGetValue(linkPtr);
	    columnPtr->maxWidth = 0;
	    columnPtr->max = SHRT_MAX;
	    if (columnPtr->reqMax > 0) {
		columnPtr->max = columnPtr->reqMax;
	    }
	    columnPtr->position = position;
	    position++;
	}
	tvPtr->minHeight = SHRT_MAX;
	tvPtr->depth = 0;
	tvPtr->nEntries = Blt_TreeSize(tvPtr->rootPtr->node);
	if (tvPtr->flatArr != NULL) {
	    Blt_Free(tvPtr->flatArr);
	}
	tvPtr->flatArr = 
	    Blt_Malloc(sizeof(TreeViewEntry *) * (tvPtr->nEntries + 1));
	assert(tvPtr->flatArr);
	tvPtr->depth = 0;
	count = 0;
	p = tvPtr->flatArr;
	for (entryPtr = tvPtr->rootPtr; entryPtr != NULL; 
	     entryPtr = Blt_TreeViewNextEntry(tvPtr, entryPtr, 0)) {
	    if ((tvPtr->flags & TV_HIDE_ROOT) && (entryPtr == tvPtr->rootPtr)) {
		continue;
	    }
	    entryPtr->lineHeight = 0;
	    if (Blt_TreeViewEntryIsMapped(tvPtr, entryPtr)) {
		GetEntryExtents(tvPtr, entryPtr);
		if (tvPtr->minHeight > entryPtr->height) {
		    tvPtr->minHeight = entryPtr->height;
		}
		entryPtr->flags &= ~ENTRY_HAS_BUTTON;
		*p++ = entryPtr;
		count++;
	    }
	}
	tvPtr->flatArr[count] = NULL;
	tvPtr->nEntries = count;

	if (tvPtr->levelInfo != NULL) {
	    Blt_Free(tvPtr->levelInfo);
	}
	tvPtr->levelInfo = Blt_Calloc(tvPtr->depth + 2, sizeof(LevelInfo));
	assert(tvPtr->levelInfo);
	tvPtr->flags &= ~(TV_DIRTY | TV_UPDATE);
	tvPtr->flags |= TV_SORT_PENDING;
    } 

    if (tvPtr->flags & TV_SORT_PENDING) {
	Blt_TreeViewSortFlatView(tvPtr);
	tvPtr->flags &= ~TV_SORT_PENDING;
    }

    tvPtr->levelInfo[0].labelWidth = tvPtr->levelInfo[0].x = 
	    tvPtr->levelInfo[0].iconWidth = 0;
    /* 
     * Pass 2:	Loop through all open/mapped nodes. 
     *
     *		1. Set world y-coordinates for entries. We must defer
     *		   setting the x-coordinates until we know the maximum 
     *		   icon sizes at each level.
     *		2. Compute the maximum depth of the tree. 
     *		3. Build an array to hold level information.
     */
    y = 0;			
    count = 0;
    for(p = tvPtr->flatArr; *p != NULL; p++) {
	entryPtr = *p;
	entryPtr->flatIndex = count++;
	entryPtr->worldY = y;
	entryPtr->lineHeight = 0;
	y += entryPtr->height;
	if (tvPtr->levelInfo[0].labelWidth < entryPtr->labelWidth) {
	    tvPtr->levelInfo[0].labelWidth = entryPtr->labelWidth;
	}
	if (tvPtr->levelInfo[0].iconWidth < entryPtr->iconWidth) {
	    tvPtr->levelInfo[0].iconWidth = entryPtr->iconWidth;
	}
    }
    tvPtr->levelInfo[0].iconWidth |= 0x01;
    tvPtr->worldHeight = y;	/* Set the scroll height of the hierarchy. */
    if (tvPtr->worldHeight < 1) {
	tvPtr->worldHeight = 1;
    }
    maxX = tvPtr->levelInfo[0].iconWidth + tvPtr->levelInfo[0].labelWidth;
    tvPtr->treeColumn.maxWidth = maxX;
    tvPtr->flags |= TV_VIEWPORT;
}

/*
 * ----------------------------------------------------------------------
 *
 * ComputeTreeLayout --
 *
 *	Recompute the layout when entries are opened/closed,
 *	inserted/deleted, or when text attributes change (such as
 *	font, linespacing).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The world coordinates are set for all the opened entries.
 *
 * ----------------------------------------------------------------------
 */
static void
ComputeTreeLayout(tvPtr)
    TreeView *tvPtr;
{
    Blt_ChainLink *linkPtr;
    TreeViewColumn *columnPtr;
    TreeViewEntry *entryPtr;
    int maxX, x, y;
    int sum;
    register int i;

    /* 
     * Pass 1:	Reinitialize column sizes and loop through all nodes. 
     *
     *		1. Recalculate the size of each entry as needed. 
     *		2. The maximum depth of the tree. 
     *		3. Minimum height of an entry.  Dividing this by the
     *		   height of the widget gives a rough estimate of the 
     *		   maximum number of visible entries.
     *		4. Build an array to hold level information to be filled
     *		   in on pass 2.
     */
    if (tvPtr->flags & TV_DIRTY) {
	int position;

	position = 1;
	for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); 
	     linkPtr != NULL; linkPtr = Blt_ChainNextLink(linkPtr)) {
	    columnPtr = Blt_ChainGetValue(linkPtr);
	    columnPtr->maxWidth = 0;
	    columnPtr->max = SHRT_MAX;
	    if (columnPtr->reqMax > 0) {
		columnPtr->max = columnPtr->reqMax;
	    }
	    columnPtr->position = position;
	    position++;
	}
	tvPtr->minHeight = SHRT_MAX;
	tvPtr->depth = 0;
	for (entryPtr = tvPtr->rootPtr; entryPtr != NULL; 
	     entryPtr = Blt_TreeViewNextEntry(tvPtr, entryPtr, 0)) {
	    GetEntryExtents(tvPtr, entryPtr);
	    if (tvPtr->minHeight > entryPtr->height) {
		tvPtr->minHeight = entryPtr->height;
	    }
	    /* 
	     * Determine if the entry should display a button
	     * (indicating that it has children) and mark the
	     * entry accordingly. 
	     */
	    entryPtr->flags &= ~ENTRY_HAS_BUTTON;
	    if (entryPtr->flags & BUTTON_SHOW) {
		entryPtr->flags |= ENTRY_HAS_BUTTON;
	    } else if (entryPtr->flags & BUTTON_AUTO) {
		if (tvPtr->flags & TV_HIDE_LEAVES) {
		    /* Check that a non-leaf child exists */
		    if (Blt_TreeViewFirstChild(tvPtr, entryPtr) != NULL) {
			entryPtr->flags |= ENTRY_HAS_BUTTON;
		    }
		} else if (!Blt_TreeIsLeaf(entryPtr->node)) {
		    entryPtr->flags |= ENTRY_HAS_BUTTON;
		}
	    }
	    /* Determine the depth of the tree. */
	    if (tvPtr->depth < DEPTH(tvPtr, entryPtr->node)) {
		tvPtr->depth = DEPTH(tvPtr, entryPtr->node);
	    }
	}
	Blt_TreeViewSortTreeView(tvPtr);

	if (tvPtr->levelInfo != NULL) {
	    Blt_Free(tvPtr->levelInfo);
	}
	tvPtr->levelInfo = Blt_Calloc(tvPtr->depth + 2, sizeof(LevelInfo));
	assert(tvPtr->levelInfo);
	tvPtr->flags &= ~TV_DIRTY;
    }
    for (i = 0; i <= (tvPtr->depth + 1); i++) {
	tvPtr->levelInfo[i].labelWidth = tvPtr->levelInfo[i].x = 
	    tvPtr->levelInfo[i].iconWidth = 0;
    }
    /* 
     * Pass 2:	Loop through all open/mapped nodes. 
     *
     *		1. Set world y-coordinates for entries. We must defer
     *		   setting the x-coordinates until we know the maximum 
     *		   icon sizes at each level.
     *		2. Compute the maximum depth of the tree. 
     *		3. Build an array to hold level information.
     */
    y = 0;
    if (tvPtr->flags & TV_HIDE_ROOT) {
	/* If the root entry is to be hidden, cheat by offsetting
	 * the y-coordinates by the height of the entry. */
	y = -(tvPtr->rootPtr->height);
    } 
    ResetCoordinates(tvPtr, tvPtr->rootPtr, &y);
    tvPtr->worldHeight = y;	/* Set the scroll height of the hierarchy. */
    if (tvPtr->worldHeight < 1) {
	tvPtr->worldHeight = 1;
    }
    sum = maxX = 0;
    for (i = 0; i <= (tvPtr->depth + 1); i++) {
	sum += tvPtr->levelInfo[i].iconWidth;
	if (i <= tvPtr->depth) {
	    tvPtr->levelInfo[i + 1].x = sum;
	}
	x = sum + tvPtr->levelInfo[i].labelWidth;
	if (x > maxX) {
	    maxX = x;
	}
    }
    tvPtr->treeColumn.maxWidth = maxX;
}

/*
 * ----------------------------------------------------------------------
 *
 * Blt_TreeViewComputeLayout --
 *
 *	Recompute the layout when entries are opened/closed,
 *	inserted/deleted, or when text attributes change (such as
 *	font, linespacing).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The world coordinates are set for all the opened entries.
 *
 * ----------------------------------------------------------------------
 */
void
Blt_TreeViewComputeLayout(tvPtr)
    TreeView *tvPtr;
{
    Blt_ChainLink *linkPtr;
    TreeViewColumn *columnPtr;
    int sum;

    if (tvPtr->flatView) {
	ComputeFlatLayout(tvPtr);
    } else {
	ComputeTreeLayout(tvPtr);
    }
    /* The width of the widget (in world coordinates) is the sum 
     * of the column widths. */

    tvPtr->worldWidth = tvPtr->titleHeight = 0;
    sum = 0;
    columnPtr = NULL;
    for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); linkPtr != NULL;
	 linkPtr = Blt_ChainNextLink(linkPtr)) {
	columnPtr = Blt_ChainGetValue(linkPtr);
	columnPtr->width = 0;
	if (!columnPtr->hidden) {
	    if ((tvPtr->flags & TV_SHOW_COLUMN_TITLES) &&
		(tvPtr->titleHeight < columnPtr->textPtr->height)) {
		tvPtr->titleHeight = columnPtr->textPtr->height;
	    }
	    if (columnPtr->reqWidth > 0) {
		columnPtr->width = columnPtr->reqWidth;
	    } else {
		/* The computed width of a column is the maximum of
		 * the title width and the widest entry. */
		columnPtr->width = MAX(columnPtr->titleWidth, 
				       columnPtr->maxWidth);
		/* Check that the width stays within any constraints that
		 * have been set. */
		if ((columnPtr->reqMin > 0) && 
		    (columnPtr->reqMin > columnPtr->width)) {
		    columnPtr->width = columnPtr->reqMin;
		}
		if ((columnPtr->reqMax > 0) && 
		    (columnPtr->reqMax < columnPtr->width)) {
		    columnPtr->width = columnPtr->reqMax;
		}
	    }
	    columnPtr->width += PADDING(columnPtr->pad) + 
		2 * columnPtr->borderWidth;
	}
	columnPtr->worldX = sum;
	sum += columnPtr->width;
    }
    tvPtr->worldWidth = sum;
    if (VPORTWIDTH(tvPtr) > sum) {
	AdjustColumns(tvPtr);
    }
    sum = 0;
    for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); linkPtr != NULL;
	 linkPtr = Blt_ChainNextLink(linkPtr)) {
	columnPtr = Blt_ChainGetValue(linkPtr);
	columnPtr->worldX = sum;
	sum += columnPtr->width;
    }
    if (tvPtr->titleHeight > 0) {
	/* If any headings are displayed, add some extra padding to
	 * the height. */
	tvPtr->titleHeight += 4;
    }
    /* tvPtr->worldWidth += 10; */
    if (tvPtr->yScrollUnits < 1) {
	tvPtr->yScrollUnits = 1;
    }
    if (tvPtr->xScrollUnits < 1) {
	tvPtr->xScrollUnits = 1;
    }
    if (tvPtr->worldWidth < 1) {
	tvPtr->worldWidth = 1;
    }
    tvPtr->flags &= ~TV_LAYOUT;
    tvPtr->flags |= TV_SCROLL;
}

/*
 * ----------------------------------------------------------------------
 *
 * ComputeVisibleEntries --
 *
 *	The entries visible in the viewport (the widget's window) are
 *	inserted into the array of visible nodes.
 *
 * Results:
 *	Returns 1 if beyond the last visible entry, 0 otherwise.
 *
 * Side effects:
 *	The array of visible nodes is filled.
 *
 * ----------------------------------------------------------------------
 */
static int
ComputeVisibleEntries(tvPtr)
    TreeView *tvPtr;
{
    int height;
    int level;
    int nSlots;
    int x, maxX;
    int xOffset, yOffset;

    xOffset = Blt_AdjustViewport(tvPtr->xOffset, tvPtr->worldWidth,
	VPORTWIDTH(tvPtr), tvPtr->xScrollUnits, tvPtr->scrollMode);
    yOffset = Blt_AdjustViewport(tvPtr->yOffset, 
	tvPtr->worldHeight, VPORTHEIGHT(tvPtr), tvPtr->yScrollUnits, 
	tvPtr->scrollMode);

    if ((xOffset != tvPtr->xOffset) || (yOffset != tvPtr->yOffset)) {
	tvPtr->yOffset = yOffset;
	tvPtr->xOffset = xOffset;
	tvPtr->flags |= TV_VIEWPORT;
    }
    height = VPORTHEIGHT(tvPtr);

    /* Allocate worst case number of slots for entry array. */
    nSlots = (height / tvPtr->minHeight) + 3;
    if (nSlots != tvPtr->nVisible) {
	if (tvPtr->visibleArr != NULL) {
	    Blt_Free(tvPtr->visibleArr);
	}
	tvPtr->visibleArr = Blt_Calloc(nSlots, sizeof(TreeViewEntry *));
	assert(tvPtr->visibleArr);
    }
    tvPtr->nVisible = 0;

    if (tvPtr->rootPtr->flags & ENTRY_HIDDEN) {
	return TCL_OK;		/* Root node is hidden. */
    }
    /* Find the node where the view port starts. */
    if (tvPtr->flatView) {
	register TreeViewEntry **p, *entryPtr;

	/* Find the starting entry visible in the viewport. It can't
	 * be hidden or any of it's ancestors closed. */
    again:
	for (p = tvPtr->flatArr; *p != NULL; p++) {
	    entryPtr = *p;
	    if ((entryPtr->worldY + entryPtr->height) > tvPtr->yOffset) {
		break;
	    }
	}	    
	/*
	 * If we can't find the starting node, then the view must be
	 * scrolled down, but some nodes were deleted.  Reset the view
	 * back to the top and try again.
	 */
	if (*p == NULL) {
	    if (tvPtr->yOffset == 0) {
		return TCL_OK;	/* All entries are hidden. */
	    }
	    tvPtr->yOffset = 0;
	    goto again;
	}

	
	maxX = 0;
	height += tvPtr->yOffset;
	for (/* empty */; *p != NULL; p++) {
	    entryPtr = *p;
	    entryPtr->worldX = LEVELX(0) + tvPtr->treeColumn.worldX;
	    x = entryPtr->worldX + ICONWIDTH(0) + entryPtr->width;
	    if (x > maxX) {
		maxX = x;
	    }
	    if (entryPtr->worldY >= height) {
		break;
	    }
	    tvPtr->visibleArr[tvPtr->nVisible] = *p;
	    tvPtr->nVisible++;
	}
	tvPtr->visibleArr[tvPtr->nVisible] = NULL;
    } else {
	TreeViewEntry *entryPtr;

	entryPtr = tvPtr->rootPtr;
	while ((entryPtr->worldY + entryPtr->height) <= tvPtr->yOffset) {
	    for (entryPtr = Blt_TreeViewLastChild(tvPtr, entryPtr); 
		 entryPtr != NULL; 
		 entryPtr = Blt_TreeViewPrevSibling(tvPtr, entryPtr)) {
		if (entryPtr->worldY <= tvPtr->yOffset) {
		    break;
		}
	    }
	    /*
	     * If we can't find the starting node, then the view must be
	     * scrolled down, but some nodes were deleted.  Reset the view
	     * back to the top and try again.
	     */
	    if (entryPtr == NULL) {
		if (tvPtr->yOffset == 0) {
		    return TCL_OK;	/* All entries are hidden. */
		}
		tvPtr->yOffset = 0;
		continue;
	    }
	}
	
	height += tvPtr->yOffset;
	maxX = 0;
	for (/* empty */; entryPtr != NULL; 
	    entryPtr = Blt_TreeViewNextEntry(tvPtr, entryPtr, ENTRY_MASK)) {
	    /*
	     * Compute and save the entry's X-coordinate now that we know
	     * what the maximum level offset for the entire TreeView is.
	     */
	    level = DEPTH(tvPtr, entryPtr->node);
	    entryPtr->worldX = LEVELX(level) + tvPtr->treeColumn.worldX;
	    
	    x = entryPtr->worldX + ICONWIDTH(level) + ICONWIDTH(level + 1) + 
		entryPtr->width;
	    if (x > maxX) {
		maxX = x;
	    }
	    if (entryPtr->worldY >= height) {
		break;
	    }
	    tvPtr->visibleArr[tvPtr->nVisible] = entryPtr;
	    tvPtr->nVisible++;
	}
	tvPtr->visibleArr[tvPtr->nVisible] = NULL;
    }
    /*
     * -------------------------------------------------------------------
     *
     * Note:	It's assumed that the view port always starts at or
     *		over an entry.  Check that a change in the hierarchy
     *		(e.g. closing a node) hasn't left the viewport beyond
     *		the last entry.  If so, adjust the viewport to start
     *		on the last entry.
     *
     * -------------------------------------------------------------------
     */
    if (tvPtr->xOffset > (tvPtr->worldWidth - tvPtr->xScrollUnits)) {
	tvPtr->xOffset = tvPtr->worldWidth - tvPtr->xScrollUnits;
    }
    if (tvPtr->yOffset > (tvPtr->worldHeight - tvPtr->yScrollUnits)) {
	tvPtr->yOffset = tvPtr->worldHeight - tvPtr->yScrollUnits;
    }
    tvPtr->xOffset = Blt_AdjustViewport(tvPtr->xOffset, 
	tvPtr->worldWidth, VPORTWIDTH(tvPtr), tvPtr->xScrollUnits, 
	tvPtr->scrollMode);
    tvPtr->yOffset = Blt_AdjustViewport(tvPtr->yOffset,
	tvPtr->worldHeight, VPORTHEIGHT(tvPtr), tvPtr->yScrollUnits,
	tvPtr->scrollMode);
    tvPtr->flags &= ~TV_DIRTY;
    return TCL_OK;
}


/*
 * ---------------------------------------------------------------------------
 *
 * DrawVerticals --
 *
 * 	Draws vertical lines for the ancestor nodes.  While the entry
 *	of the ancestor may not be visible, its vertical line segment
 *	does extent into the viewport.  So walk back up the hierarchy
 *	drawing lines until we get to the root.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Vertical lines are drawn for the ancestor nodes.
 *
 * ---------------------------------------------------------------------------
 */
static void
DrawVerticals(tvPtr, entryPtr, drawable)
    TreeView *tvPtr;		/* Widget record containing the attribute
				 * information for buttons. */
    TreeViewEntry *entryPtr;		/* Entry to be drawn. */
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    int height, level;
    int x, y;
    int x1, y1, x2, y2;

    while (entryPtr != tvPtr->rootPtr) {
	entryPtr = Blt_TreeViewParentEntry(tvPtr, entryPtr);
	if (entryPtr == NULL) {
	    break;
	}
	level = DEPTH(tvPtr, entryPtr->node);
	/*
	 * World X-coordinates aren't computed only for entries that are
	 * outside the view port.  So for each off-screen ancestor node
	 * compute it here too.
	 */
	entryPtr->worldX = LEVELX(level) + tvPtr->treeColumn.worldX;
	x = SCREENX(tvPtr, entryPtr->worldX);
	y = SCREENY(tvPtr, entryPtr->worldY);
	height = MAX(entryPtr->iconHeight, tvPtr->button.height);
	y += (height - tvPtr->button.height) / 2;
	x1 = x2 = x + ICONWIDTH(level) + ICONWIDTH(level + 1) / 2;
	y1 = y + tvPtr->button.height / 2;
	y2 = y1 + entryPtr->lineHeight;
	if ((entryPtr == tvPtr->rootPtr) && (tvPtr->flags & TV_HIDE_ROOT)) {
	    y1 += entryPtr->height;
	}
	/*
	 * Clip the line's Y-coordinates at the viewport borders.
	 */
	if (y1 < 0) {
	    y1 = (y1 & 0x1);	/* Make sure the dotted line starts on 
				 * the same even/odd pixel. */
	}
	if (y2 > Tk_Height(tvPtr->tkwin)) {
	    y2 = Tk_Height(tvPtr->tkwin);
	}
	if ((y1 < Tk_Height(tvPtr->tkwin)) && (y2 > 0)) {
	    XDrawLine(tvPtr->display, drawable, tvPtr->lineGC, 
	      x1, y1, x2, y2);
	}
    }
}

void
Blt_TreeViewDrawRule(tvPtr, columnPtr, drawable)
    TreeView *tvPtr;		/* Widget record containing the
				 * attribute information for rules. */
    TreeViewColumn *columnPtr;
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    int x, y1, y2;

    x = SCREENX(tvPtr, columnPtr->worldX) + 
	columnPtr->width + tvPtr->ruleMark - tvPtr->ruleAnchor - 1;

    y1 = tvPtr->titleHeight + tvPtr->inset;
    y2 = Tk_Height(tvPtr->tkwin) - tvPtr->inset;
    XDrawLine(tvPtr->display, drawable, columnPtr->rule.gc, x, y1, x, y2);
    tvPtr->flags = TOGGLE(tvPtr->flags, TV_RULE_ACTIVE);
}

/*
 * ---------------------------------------------------------------------------
 *
 * Blt_TreeViewDrawButton --
 *
 * 	Draws a button for the given entry. The button is drawn
 * 	centered in the region immediately to the left of the origin
 * 	of the entry (computed in the layout routines). The height
 * 	and width of the button were previously calculated from the
 * 	average row height.
 *
 *		button height = entry height - (2 * some arbitrary padding).
 *		button width = button height.
 *
 *	The button may have a border.  The symbol (either a plus or
 *	minus) is slight smaller than the width or height minus the
 *	border.
 *
 *	    x,y origin of entry
 *
 *              +---+
 *              | + | icon label
 *              +---+
 *             closed
 *
 *           |----|----| horizontal offset
 *
 *              +---+
 *              | - | icon label
 *              +---+
 *              open
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A button is drawn for the entry.
 *
 * ---------------------------------------------------------------------------
 */
void
Blt_TreeViewDrawButton(tvPtr, entryPtr, drawable)
    TreeView *tvPtr;		/* Widget record containing the
				 * attribute information for
				 * buttons. */
    TreeViewEntry *entryPtr;	/* Entry. */
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    Tk_3DBorder border;
    TreeViewButton *buttonPtr = &tvPtr->button;
    TreeViewImage image;
    int relief;
    int width, height;
    int x, y;
    int yBot, yTop;
    int y1, y2;

    width = ICONWIDTH(DEPTH(tvPtr, entryPtr->node));
    height = MAX(entryPtr->iconHeight, buttonPtr->height);
    entryPtr->buttonX = (width - buttonPtr->width) / 2;
    entryPtr->buttonY = (height - buttonPtr->height) / 2;

    x = SCREENX(tvPtr, entryPtr->worldX) + entryPtr->buttonX;
    y = SCREENY(tvPtr, entryPtr->worldY) + entryPtr->buttonY;

    if (entryPtr == tvPtr->activeButtonPtr) {
	border = buttonPtr->activeBorder;
    } else {
	border = buttonPtr->border;
    }
    if (entryPtr->flags & ENTRY_CLOSED) {
	relief = buttonPtr->closeRelief;
    } else {
	relief = buttonPtr->openRelief;
    }
    yBot = Tk_Height(tvPtr->tkwin) - (tvPtr->inset - INSET_PAD);
    yTop = tvPtr->titleHeight + tvPtr->inset;

    /*
     * FIXME:  1) button overlays column title.  
     *	       2) background rectangle drawn when image is available.
     *	       3) does "flat" relief always mean line border?
     */
    y1 = y;
    y2 = y + buttonPtr->height;
    if (y1 < yTop) {
	y1 = yTop;
    }
    if (y2 > yBot) {
	y2 = yBot;
    }
    if (y2 < y1) {
	return;
    }
    if (relief == TK_RELIEF_SOLID) {
	relief = TK_RELIEF_FLAT;
    }
    Tk_Fill3DRectangle(tvPtr->tkwin, drawable, border, x, y1,
	buttonPtr->width, y2 - y1, buttonPtr->borderWidth, relief);

    x += buttonPtr->borderWidth;
    y += buttonPtr->borderWidth;
    width = buttonPtr->width - (2 * buttonPtr->borderWidth);
    height = buttonPtr->height - (2 * buttonPtr->borderWidth);

    image = NULL;
    if (buttonPtr->images != NULL) {  /* Open or close button image? */
	image = buttonPtr->images[0];
	if (((entryPtr->flags & ENTRY_CLOSED) == 0) && 
	    (buttonPtr->images[1] != NULL)) {
	    image = buttonPtr->images[1];
	}
    }
    if (image != NULL) {	/* Image or rectangle? */
	Tk_RedrawImage(TreeViewImageData(image), 0, 0, width, height, drawable,
		       x, y);
    } else {
	int top, bottom, left, right;
	XSegment segments[6];
	XSegment *s;
	GC gc;

	gc = (entryPtr == tvPtr->activeButtonPtr)
	    ? buttonPtr->activeGC : buttonPtr->normalGC;
	s = segments;
	if (relief == TK_RELIEF_FLAT) {

	    /* Draw the box outline */

	    left = x - buttonPtr->borderWidth;
	    top = y - buttonPtr->borderWidth;
	    right = left + buttonPtr->width - 1;
	    bottom = top + buttonPtr->height - 1;
	    if (bottom >= yTop) {
		if (top < yTop) {
		    top = yTop;
		} else {
		    s->x1 = left;
		    s->x2 = right;
		    s->y2 = s->y1 = top;
		    s++;
		}
		s->x2 = s->x1 = right;
		s->y1 = top;
		s->y2 = bottom;
		s++;
		s->x2 = s->x1 = left;
		s->y1 = top;
#ifdef WIN32
		s->y2 = bottom + 1;
#else
		s->y2 = bottom;
#endif
		s++;
		s->x1 = left;
#ifdef WIN32
		s->x2 = right + 1;
#else
		s->x2 = right;
#endif
		s->y2 = s->y1 = bottom;
		s++;
	    }
	}
	top = y + height / 2;
	if (top >= yTop) {	/* Draw the horizontal line. */
	    left = x + BUTTON_IPAD;
	    right = x + width - BUTTON_IPAD;
	    s->y1 = s->y2 = top;
	    s->x1 = left;
#ifdef WIN32
	    s->x2 = right;
#else
	    s->x2 = right - 1;
#endif
	    s++;
	}
	if (entryPtr->flags & ENTRY_CLOSED) { /* Draw the vertical
					       * line for the plus. */
	    top = y + BUTTON_IPAD;
	    bottom = y + height - BUTTON_IPAD;
	    if (bottom > yTop) {
		if (top < yTop) {
		    top = yTop;
		}
		s->y1 = top;
#ifdef WIN32
		s->y2 = bottom;
#else
		s->y2 = bottom - 1;
#endif
		s->x1 = s->x2 = x + width / 2;
		s++;
	    }
	}
	XDrawSegments(tvPtr->display, drawable, gc, segments, s - segments);
    }
}


/*
 * ---------------------------------------------------------------------------
 *
 * Blt_TreeViewIconImage --
 *
 * 	Selects the correct image for the entry's icon depending upon
 *	the current state of the entry: active/inactive normal/selected.  
 *
 *		active - normal
 *		active - selected
 *		inactive - normal
 *		inactive - selected
 *
 * Results:
 *	Returns the image for the icon.
 *
 * ---------------------------------------------------------------------------
 */
TreeViewImage
Blt_TreeViewIconImage(tvPtr, entryPtr)
    TreeView *tvPtr;
    TreeViewEntry *entryPtr;
{
    TreeViewImage *icons;
    TreeViewImage image;

    int isActive, hasFocus;

    isActive = (entryPtr == tvPtr->activePtr);
    hasFocus = (entryPtr == tvPtr->focusPtr);
    icons = NULL;
    if (isActive) {
	icons = CHOOSE(tvPtr->activeIcons, entryPtr->activeIcons);
    }
    if (icons == NULL) {
	icons = CHOOSE(tvPtr->icons, entryPtr->icons);
    }
    image = NULL;
    if (icons != NULL) {	/* Selected or normal icon? */
	image = icons[0];
	if ((hasFocus) && (icons[1] != NULL)) {
	    image = icons[1];
	}
    }
    return image;
}


int
Blt_TreeViewDrawIcon(tvPtr, entryPtr, x, y, drawable)
    TreeView *tvPtr;		/* Widget record containing the attribute
				 * information for buttons. */
    TreeViewEntry *entryPtr;	/* Entry to display. */
    int x, y;
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    TreeViewImage image;

    image = Blt_TreeViewIconImage(tvPtr, entryPtr);

    if (image != NULL) {	/* Image or default icon bitmap? */
	int entryHeight;
	int level;
	int maxY;
	int top, bottom;
	int topInset, botInset;
	int width, height;

	level = DEPTH(tvPtr, entryPtr->node);
	entryHeight = MAX(entryPtr->iconHeight, tvPtr->button.height);
	height = TreeViewImageHeight(image);
	width = TreeViewImageWidth(image);
	if (tvPtr->flatView) {
	    x += (ICONWIDTH(0) - width) / 2;
	} else {
	    x += (ICONWIDTH(level + 1) - width) / 2;
	}	    
	y += (entryHeight - height) / 2;
	botInset = tvPtr->inset - INSET_PAD;
	topInset = tvPtr->titleHeight + tvPtr->inset;
	maxY = Tk_Height(tvPtr->tkwin) - botInset;
	top = 0;
	bottom = y + height;
	if (y < topInset) {
	    height += y - topInset;
	    top = -y + topInset;
	    y = topInset;
	} else if (bottom >= maxY) {
	    height = maxY - y;
	}
	Tk_RedrawImage(TreeViewImageData(image), 0, top, width, height, 
		drawable, x, y);
    } 
    return (image != NULL);
}

static int
DrawLabel(tvPtr, entryPtr, x, y, drawable)
    TreeView *tvPtr;		/* Widget record. */
    TreeViewEntry *entryPtr;	/* Entry attribute information. */
    int x, y;			
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    char *label;
    int entryHeight;
    int isFocused;
    int width, height;		/* Width and height of label. */

    entryHeight = MAX(entryPtr->iconHeight, tvPtr->button.height);
    isFocused = ((entryPtr == tvPtr->focusPtr) && 
		 (tvPtr->flags & TV_FOCUS));

    /* Includes padding, selection 3-D border, and focus outline. */
    width = entryPtr->labelWidth;
    height = entryPtr->labelHeight;

    /* Center the label, if necessary, vertically along the entry row. */
    if (height < entryHeight) {
	y += (entryHeight - height) / 2;
    }
    if (isFocused) {		/* Focus outline */
	XDrawRectangle(tvPtr->display, drawable, tvPtr->focusGC,
	    x, y, width - 1, height - 1);
    }
    x += FOCUS_WIDTH + LABEL_PADX + tvPtr->selBorderWidth;
    y += FOCUS_WIDTH + LABEL_PADY + tvPtr->selBorderWidth;

    label = GETLABEL(entryPtr);
    if (label[0] != '\0') {
	GC gc;
	TextStyle ts;
	Tk_Font font;
	XColor *normalColor, *activeColor;
	int selected;

	selected = Blt_TreeViewEntryIsSelected(tvPtr, entryPtr);
	font = CHOOSE(tvPtr->treeColumn.font, entryPtr->font);
	normalColor = CHOOSE(tvPtr->treeColumn.fgColor,entryPtr->color);
	activeColor = (selected) ? tvPtr->selFgColor : normalColor;
	gc = (entryPtr->gc == NULL) ? tvPtr->treeColumn.gc : entryPtr->gc;
	Blt_SetDrawTextStyle(&ts, font, gc, normalColor, activeColor, 
		entryPtr->shadow.color, 0.0, TK_ANCHOR_NW, TK_JUSTIFY_LEFT, 0, 
		entryPtr->shadow.offset);
	ts.state = (selected || (entryPtr->gc == NULL)) ? STATE_ACTIVE : 0;
	Blt_DrawTextLayout(tvPtr->tkwin, drawable, entryPtr->textPtr, 
		&ts, x, y);
    }
    return entryHeight;
}

/*
 * ---------------------------------------------------------------------------
 *
 * DrawFlatEntry --
 *
 * 	Draws a button for the given entry.  Note that buttons should only
 *	be drawn if the entry has sub-entries to be opened or closed.  It's
 *	the responsibility of the calling routine to ensure this.
 *
 *	The button is drawn centered in the region immediately to the left
 *	of the origin of the entry (computed in the layout routines). The
 *	height and width of the button were previously calculated from the
 *	average row height.
 *
 *		button height = entry height - (2 * some arbitrary padding).
 *		button width = button height.
 *
 *	The button has a border.  The symbol (either a plus or minus) is
 *	slight smaller than the width or height minus the border.
 *
 *	    x,y origin of entry
 *
 *              +---+
 *              | + | icon label
 *              +---+
 *             closed
 *
 *           |----|----| horizontal offset
 *
 *              +---+
 *              | - | icon label
 *              +---+
 *              open
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A button is drawn for the entry.
 *
 * ---------------------------------------------------------------------------
 */
static void
DrawFlatEntry(tvPtr, entryPtr, drawable)
    TreeView *tvPtr;		/* Widget record containing the attribute
				 * information for buttons. */
    TreeViewEntry *entryPtr;		/* Entry to be drawn. */
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    int level;
    int x, y;

    entryPtr->flags &= ~ENTRY_REDRAW;

    x = SCREENX(tvPtr, entryPtr->worldX);
    y = SCREENY(tvPtr, entryPtr->worldY);
    if (!Blt_TreeViewDrawIcon(tvPtr, entryPtr, x, y, drawable)) {
	x -= (DEF_ICON_WIDTH * 2) / 3;
    }
    level = 0;
    x += ICONWIDTH(level);
    /* Entry label. */
    DrawLabel(tvPtr, entryPtr, x, y, drawable);
}

/*
 * ---------------------------------------------------------------------------
 *
 * DrawTreeEntry --
 *
 * 	Draws a button for the given entry.  Note that buttons should only
 *	be drawn if the entry has sub-entries to be opened or closed.  It's
 *	the responsibility of the calling routine to ensure this.
 *
 *	The button is drawn centered in the region immediately to the left
 *	of the origin of the entry (computed in the layout routines). The
 *	height and width of the button were previously calculated from the
 *	average row height.
 *
 *		button height = entry height - (2 * some arbitrary padding).
 *		button width = button height.
 *
 *	The button has a border.  The symbol (either a plus or minus) is
 *	slight smaller than the width or height minus the border.
 *
 *	    x,y origin of entry
 *
 *              +---+
 *              | + | icon label
 *              +---+
 *             closed
 *
 *           |----|----| horizontal offset
 *
 *              +---+
 *              | - | icon label
 *              +---+
 *              open
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A button is drawn for the entry.
 *
 * ---------------------------------------------------------------------------
 */
static void
DrawTreeEntry(tvPtr, entryPtr, drawable)
    TreeView *tvPtr;		/* Widget record. */
    TreeViewEntry *entryPtr;	/* Entry to be drawn. */
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    TreeViewButton *buttonPtr = &tvPtr->button;
    int buttonY;
    int level;
    int width, height;
    int x, y;
    int x1, y1, x2, y2;

    entryPtr->flags &= ~ENTRY_REDRAW;

    x = SCREENX(tvPtr, entryPtr->worldX);
    y = SCREENY(tvPtr, entryPtr->worldY);

    level = DEPTH(tvPtr, entryPtr->node);
    width = ICONWIDTH(level);
    height = MAX(entryPtr->iconHeight, buttonPtr->height);

    entryPtr->buttonX = (width - buttonPtr->width) / 2;
    entryPtr->buttonY = (height - buttonPtr->height) / 2;

    buttonY = y + entryPtr->buttonY;

    x1 = x + (width / 2);
    y1 = y2 = buttonY + (buttonPtr->height / 2);
    x2 = x1 + (ICONWIDTH(level) + ICONWIDTH(level + 1)) / 2;

    if ((Blt_TreeNodeParent(entryPtr->node) != NULL) && 
	(tvPtr->lineWidth > 0)) {
	/*
	 * For every node except root, draw a horizontal line from
	 * the vertical bar to the middle of the icon.
	 */
	XDrawLine(tvPtr->display, drawable, tvPtr->lineGC, x1, y1, x2, y2);
    }
    if (((entryPtr->flags & ENTRY_CLOSED) == 0) && (tvPtr->lineWidth > 0)) {
	/*
	 * Entry is open, draw vertical line.
	 */
	y2 = y1 + entryPtr->lineHeight;
	if (y2 > Tk_Height(tvPtr->tkwin)) {
	    y2 = Tk_Height(tvPtr->tkwin); /* Clip line at window border. */
	}
	XDrawLine(tvPtr->display, drawable, tvPtr->lineGC, x2, y1, x2, y2);
    }
    if ((entryPtr->flags & ENTRY_HAS_BUTTON) && (entryPtr != tvPtr->rootPtr)) {
	/*
	 * Except for the root, draw a button for every entry that
	 * needs one.  The displayed button can be either a Tk image
	 * or a rectangle with plus or minus sign.
	 */
	Blt_TreeViewDrawButton(tvPtr, entryPtr, drawable);
    }
    x += ICONWIDTH(level);

    if (!Blt_TreeViewDrawIcon(tvPtr, entryPtr, x, y, drawable)) {
	x -= (DEF_ICON_WIDTH * 2) / 3;
    }
    x += ICONWIDTH(level + 1) + 4;

    /* Entry label. */
    DrawLabel(tvPtr, entryPtr, x, y, drawable);
}

/*
 * ---------------------------------------------------------------------------
 *
 * DrawValue --
 *
 * 	Draws a column value for the given entry.  
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A button is drawn for the entry.
 *
 * ---------------------------------------------------------------------------
 */
static void
DrawValue(tvPtr, columnPtr, entryPtr, drawable)
    TreeView *tvPtr;		/* Widget record. */
    TreeViewColumn *columnPtr;
    TreeViewEntry *entryPtr;	/* Node of entry to be drawn. */
    Drawable drawable;		/* Pixmap or window to draw into. */
{
    TreeViewValue *valuePtr;
    int width;
    int x, y;

    /* Draw the background of the value. */
    x = SCREENX(tvPtr, columnPtr->worldX);
    y = SCREENY(tvPtr, entryPtr->worldY);
    if (Blt_TreeViewEntryIsSelected(tvPtr, entryPtr)) {
	Tk_Fill3DRectangle(tvPtr->tkwin, drawable, tvPtr->selBorder,
	    x, y - 1, columnPtr->width, entryPtr->height + 1, 
	   tvPtr->selBorderWidth, tvPtr->selRelief);
    }
    /* Check if there's a corresponding value in the entry. */
    valuePtr = FindValue(entryPtr, columnPtr);
    if (valuePtr == NULL) {
	return;			/* No value. */
    }
    x += columnPtr->pad.side1 + columnPtr->borderWidth;
    width = columnPtr->width - (2 * columnPtr->borderWidth + 
	PADDING(columnPtr->pad));
    if (width > valuePtr->width) {
	switch(columnPtr->justify) {
	case TK_JUSTIFY_RIGHT:
	    x += (width - valuePtr->width);
	    break;
	case TK_JUSTIFY_CENTER:
	    x += (width - valuePtr->width) / 2;
	    break;
	case TK_JUSTIFY_LEFT:
	    break;
	}
    }
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
	    XSetForeground(tvPtr->display, columnPtr->gc, 
		  columnPtr->fgColor->pixel);
	}
    }
}

static void
DrawTitle(tvPtr, columnPtr, drawable, x)
    TreeView *tvPtr;
    TreeViewColumn *columnPtr;
    Drawable drawable;
    int x;
{
    GC gc;
    TextStyle ts;
    Tk_3DBorder border;
    XColor *fgColor;
    int columnWidth;
    int width;
    int x0, cx, xOffset;

    columnWidth = columnPtr->width;
    cx = x;
    if (columnPtr->position == Blt_ChainGetLength(tvPtr->colChainPtr)) {
	columnWidth = Tk_Width(tvPtr->tkwin) - x;
    } else if (columnPtr->position == 1) {
	columnWidth += x;
	cx = 0;
    }
    x0 = x + columnPtr->borderWidth;

    if (columnPtr == tvPtr->activeColumnPtr) {
	border = columnPtr->activeTitleBorder;
	gc = columnPtr->activeTitleGC;
	fgColor = columnPtr->activeTitleFgColor;
    } else {
	border = columnPtr->titleBorder;
	gc = columnPtr->titleGC;
	fgColor = columnPtr->titleFgColor;
    }
    Tk_Fill3DRectangle(tvPtr->tkwin, drawable, border, cx + 1, 
	tvPtr->inset + 1, columnWidth - 2, tvPtr->titleHeight - 2, 0, 
	TK_RELIEF_FLAT);
    width = columnPtr->width;
    xOffset = x0 + columnPtr->pad.side1 + 1;
    if (width > columnPtr->textPtr->width) {
	x += (width - columnPtr->textPtr->width) / 2;
    }
    if (columnPtr == tvPtr->sortColumnPtr) {
	/* Make sure there's room for the sorting-direction triangle. */
	if ((x - xOffset) <= (SORT_MARKER_WIDTH + 1)) {
	    x = xOffset + SORT_MARKER_WIDTH + 1;
	}
    }
    Blt_SetDrawTextStyle(&ts, columnPtr->titleFont, gc, fgColor,
	tvPtr->selFgColor, columnPtr->titleShadow.color, 0.0, TK_ANCHOR_NW,
	TK_JUSTIFY_LEFT, 0, columnPtr->titleShadow.offset);
    Blt_DrawTextLayout(tvPtr->tkwin, drawable, columnPtr->textPtr, &ts, x, 
	tvPtr->inset + 1);
    if ((columnPtr == tvPtr->sortColumnPtr) && (tvPtr->flatView)) {
	XPoint triangle[4];
	int y;

	y = tvPtr->inset + tvPtr->titleHeight / 2 - 2;
	if (tvPtr->flags & TV_DECREASING) {
	    triangle[0].x = x0 + SORT_MARKER_OFFSET + 1;
	    triangle[0].y = y - SORT_MARKER_OFFSET / 2;
	    triangle[1].x = triangle[0].x + SORT_MARKER_OFFSET;
	    triangle[1].y = triangle[0].y + SORT_MARKER_OFFSET;
	    triangle[2].x = triangle[0].x - SORT_MARKER_OFFSET;
	    triangle[2].y = triangle[0].y + SORT_MARKER_OFFSET;
	    triangle[3].x = triangle[0].x;
	    triangle[3].y = triangle[0].y;
	} else {
	    triangle[0].x = x0 + SORT_MARKER_OFFSET + 1;
	    triangle[0].y = y + SORT_MARKER_OFFSET / 2;
	    triangle[1].x = triangle[0].x - SORT_MARKER_OFFSET;
	    triangle[1].y = triangle[0].y - SORT_MARKER_OFFSET;
	    triangle[2].x = triangle[0].x + SORT_MARKER_OFFSET;
	    triangle[2].y = triangle[0].y - SORT_MARKER_OFFSET;
	    triangle[3].x = triangle[0].x;
	    triangle[3].y = triangle[0].y;
	}
	XFillPolygon(tvPtr->display, drawable, gc, triangle, 4, Convex, 
		CoordModeOrigin);
	XDrawLines(tvPtr->display, drawable, gc, triangle, 4, 
		CoordModeOrigin);
    }
    Tk_Draw3DRectangle(tvPtr->tkwin, drawable, border, cx, tvPtr->inset, 
	columnWidth, tvPtr->titleHeight, 1, TK_RELIEF_RAISED);
}

void
Blt_TreeViewDrawHeadings(tvPtr, drawable)
    TreeView *tvPtr;
    Drawable drawable;
{
    Blt_ChainLink *linkPtr;
    TreeViewColumn *columnPtr;
    int x;

    for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); linkPtr != NULL;
	 linkPtr = Blt_ChainNextLink(linkPtr)) {
	columnPtr = Blt_ChainGetValue(linkPtr);
	if (columnPtr->hidden) {
	    continue;
	}
	x = SCREENX(tvPtr, columnPtr->worldX);
	if ((x + columnPtr->width) < 0) {
	    continue;	/* Don't draw columns before the left edge. */
	}
	if (x > Tk_Width(tvPtr->tkwin)) {
	    break;		/* Discontinue when a column starts beyond
				 * the right edge. */
	}
	DrawTitle(tvPtr, columnPtr, drawable, x);
    }
}

static void
DrawTreeView(tvPtr, drawable, x)
    TreeView *tvPtr;
    Drawable drawable;
    int x;
{
    register TreeViewEntry **p;

    /* 
     * Draw the backgrounds of selected entries first.  The vertical
     * lines connecting child entries will be draw on top.
     */
    for (p = tvPtr->visibleArr; *p != NULL; p++) {
	if (Blt_TreeViewEntryIsSelected(tvPtr, *p)) {
	    int y;

	    y = SCREENY(tvPtr, (*p)->worldY) - 1;
	    Tk_Fill3DRectangle(tvPtr->tkwin, drawable, tvPtr->selBorder, 
		x, y, tvPtr->treeColumn.width, (*p)->height + 1, 
		tvPtr->selBorderWidth, tvPtr->selRelief);
	}
    }
    if (tvPtr->lineWidth > 0) { 
	/* Draw all the vertical lines from topmost node. */
	DrawVerticals(tvPtr, tvPtr->visibleArr[0], drawable);
    }

    for (p = tvPtr->visibleArr; *p != NULL; p++) {
	DrawTreeEntry(tvPtr, *p, drawable);
    }
}

static void
DrawFlatView(tvPtr, drawable, x)
    TreeView *tvPtr;
    Drawable drawable;
    int x;
{
    register TreeViewEntry **p;

    /* 
     * Draw the backgrounds of selected entries first.  The vertical
     * lines connecting child entries will be draw on top. 
     */
    for (p = tvPtr->visibleArr; *p != NULL; p++) {
	if (Blt_TreeViewEntryIsSelected(tvPtr, *p)) {
	    int y;

	    y = SCREENY(tvPtr, (*p)->worldY) - 1;
	    Tk_Fill3DRectangle(tvPtr->tkwin, drawable, tvPtr->selBorder, 
		x, y, tvPtr->treeColumn.width, (*p)->height + 1, 
		tvPtr->selBorderWidth, tvPtr->selRelief);
	}
    }
    for (p = tvPtr->visibleArr; *p != NULL; p++) {
	DrawFlatEntry(tvPtr, *p, drawable);
    }
}

void
Blt_TreeViewDrawOuterBorders(tvPtr, drawable)
    TreeView *tvPtr;
    Drawable drawable;
{
    /* Draw 3D border just inside of the focus highlight ring. */
    if ((tvPtr->borderWidth > 0) && (tvPtr->relief != TK_RELIEF_FLAT)) {
	Tk_Draw3DRectangle(tvPtr->tkwin, drawable, tvPtr->border,
	    tvPtr->highlightWidth, tvPtr->highlightWidth,
	    Tk_Width(tvPtr->tkwin) - 2 * tvPtr->highlightWidth,
	    Tk_Height(tvPtr->tkwin) - 2 * tvPtr->highlightWidth,
	    tvPtr->borderWidth, tvPtr->relief);
    }
    /* Draw focus highlight ring. */
    if (tvPtr->highlightWidth > 0) {
	XColor *color;
	GC gc;

	color = (tvPtr->flags & TV_FOCUS)
	    ? tvPtr->highlightColor : tvPtr->highlightBgColor;
	gc = Tk_GCForColor(color, drawable);
	Tk_DrawFocusHighlight(tvPtr->tkwin, gc, tvPtr->highlightWidth,
	    drawable);
    }
    tvPtr->flags &= ~TV_BORDERS;
}

/*
 * ----------------------------------------------------------------------
 *
 * DisplayTreeView --
 *
 * 	This procedure is invoked to display the widget.
 *
 *      Recompute the layout of the text if necessary. This is
 *	necessary if the world coordinate system has changed.
 *	Specifically, the following may have occurred:
 *
 *	  1.  a text attribute has changed (font, linespacing, etc.).
 *	  2.  an entry's option changed, possibly resizing the entry.
 *
 *      This is deferred to the display routine since potentially
 *      many of these may occur.
 *
 *	Set the vertical and horizontal scrollbars.  This is done
 *	here since the window width and height are needed for the
 *	scrollbar calculations.
 *
 * Results:
 *	None.
 *
 * Side effects:
 * 	The widget is redisplayed.
 *
 * ----------------------------------------------------------------------
 */
static void
DisplayTreeView(clientData)
    ClientData clientData;	/* Information about widget. */
{
    Blt_ChainLink *linkPtr;
    TreeView *tvPtr = clientData;
    TreeViewColumn *columnPtr;
    int width, height;
    int x;

    tvPtr->flags &= ~TV_REDRAW;
    if (tvPtr->tkwin == NULL) {
	return;			/* Window has been destroyed. */
    }
    if (tvPtr->flags & TV_LAYOUT) {
	/*
	 * Recompute the layout when entries are opened/closed,
	 * inserted/deleted, or when text attributes change (such as
	 * font, linespacing).
	 */
	Blt_TreeViewComputeLayout(tvPtr);
    }
    if (tvPtr->flags & TV_SCROLL) {
	/* 
	 * Scrolling means that the view port has changed and that the
	 * visible entries need to be recomputed.
	 */
	ComputeVisibleEntries(tvPtr);
	Blt_PickCurrentItem(tvPtr->bindTable);
	Blt_PickCurrentItem(tvPtr->buttonBindTable);

	width = VPORTWIDTH(tvPtr);
	height = VPORTHEIGHT(tvPtr);
	if (tvPtr->flags & TV_XSCROLL) {
	    if (tvPtr->xScrollCmdPrefix != NULL) {
		Blt_UpdateScrollbar(tvPtr->interp, tvPtr->xScrollCmdPrefix,
		    (double)tvPtr->xOffset / tvPtr->worldWidth,
		    (double)(tvPtr->xOffset + width) / tvPtr->worldWidth);
	    }
	}
	if (tvPtr->flags & TV_YSCROLL) {
	    if (tvPtr->yScrollCmdPrefix != NULL) {
		Blt_UpdateScrollbar(tvPtr->interp, tvPtr->yScrollCmdPrefix,
		    (double)tvPtr->yOffset / tvPtr->worldHeight,
		    (double)(tvPtr->yOffset + height) / tvPtr->worldHeight);
	    }
	}
	tvPtr->flags &= ~TV_SCROLL;
    }
    if (tvPtr->reqWidth == 0) {
	tvPtr->reqWidth = tvPtr->worldWidth + 2 * tvPtr->inset;
	Tk_GeometryRequest(tvPtr->tkwin, tvPtr->reqWidth,
	    tvPtr->reqHeight);
    }
    if (!Tk_IsMapped(tvPtr->tkwin)) {
	return;
    }
    if ((tvPtr->drawable == None) || 
	(tvPtr->drawWidth != Tk_Width(tvPtr->tkwin)) ||
	(tvPtr->drawHeight != Tk_Height(tvPtr->tkwin))) {
	if (tvPtr->drawable != None) {
	    Tk_FreePixmap(tvPtr->display, tvPtr->drawable);
	}
	tvPtr->drawWidth = Tk_Width(tvPtr->tkwin);
	tvPtr->drawHeight = Tk_Height(tvPtr->tkwin);
	tvPtr->drawable = Tk_GetPixmap(tvPtr->display, 
		Tk_WindowId(tvPtr->tkwin), 
		tvPtr->drawWidth, tvPtr->drawHeight, 
		Tk_Depth(tvPtr->tkwin));
	tvPtr->flags |= TV_VIEWPORT;
    }

    if ((tvPtr->flags & TV_RULE_ACTIVE) &&
	(tvPtr->resizeColumnPtr != NULL)) {
	Blt_TreeViewDrawRule(tvPtr, tvPtr->resizeColumnPtr, 
		tvPtr->drawable);
    }
    Tk_Fill3DRectangle(tvPtr->tkwin, tvPtr->drawable, tvPtr->border, 
       0, 0, Tk_Width(tvPtr->tkwin), Tk_Height(tvPtr->tkwin), 0,
       TK_RELIEF_FLAT);

    if (tvPtr->nVisible > 0) {
	register TreeViewEntry **p;
	Tk_3DBorder border;

	for (linkPtr = Blt_ChainFirstLink(tvPtr->colChainPtr); 
	     linkPtr != NULL; linkPtr = Blt_ChainNextLink(linkPtr)) {
	    columnPtr = Blt_ChainGetValue(linkPtr);
	    columnPtr->flags &= ~COLUMN_DIRTY;
	    if (columnPtr->hidden) {
		continue;
	    }
	    x = SCREENX(tvPtr, columnPtr->worldX);
	    if ((x + columnPtr->width) < 0) {
		continue;	/* Don't draw columns before the left edge. */
	    }
	    if (x > Tk_Width(tvPtr->tkwin)) {
		break;		/* Discontinue when a column starts beyond
				 * the right edge. */
	    }
	    /* Clear the column background. */
	    border = CHOOSE(tvPtr->border, columnPtr->border);
	    Tk_Fill3DRectangle(tvPtr->tkwin, tvPtr->drawable, border, x, 0,
	       columnPtr->width, Tk_Height(tvPtr->tkwin), 0, TK_RELIEF_FLAT);

	    if (columnPtr != &tvPtr->treeColumn) {
		for (p = tvPtr->visibleArr; *p != NULL; p++) {
		    DrawValue(tvPtr, columnPtr, *p, tvPtr->drawable);
		}
	    } else {
		if (tvPtr->flatView) {
		    DrawFlatView(tvPtr, tvPtr->drawable, x);
		} else {
		    DrawTreeView(tvPtr, tvPtr->drawable, x);
		}
	    }
	    if (columnPtr->relief != TK_RELIEF_FLAT) {
		Tk_Draw3DRectangle(tvPtr->tkwin, tvPtr->drawable, border,
			x, 0, columnPtr->width, Tk_Height(tvPtr->tkwin), 
			columnPtr->borderWidth, columnPtr->relief);
	    }
	}
    }

    if (tvPtr->flags & TV_SHOW_COLUMN_TITLES) {
	Blt_TreeViewDrawHeadings(tvPtr, tvPtr->drawable);
    }
    Blt_TreeViewDrawOuterBorders(tvPtr, tvPtr->drawable);
    if ((tvPtr->flags & TV_RULE_NEEDED) &&
	(tvPtr->resizeColumnPtr != NULL)) {
	Blt_TreeViewDrawRule(tvPtr, tvPtr->resizeColumnPtr, 
		tvPtr->drawable);
    }
    /* Now copy the new view to the window. */
    XCopyArea(tvPtr->display, tvPtr->drawable, Tk_WindowId(tvPtr->tkwin),
	tvPtr->lineGC, 0, 0, Tk_Width(tvPtr->tkwin), 
	Tk_Height(tvPtr->tkwin), 0, 0);
    tvPtr->flags &= ~TV_VIEWPORT;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TreeViewSelectCmdProc --
 *
 *      Invoked at the next idle point whenever the current
 *      selection changes.  Executes some application-specific code
 *      in the -selectcommand option.  This provides a way for
 *      applications to handle selection changes.
 *
 * Results:
 *      None.
 *
 * Side effects:
 *      Tcl code gets executed for some application-specific task.
 *
 *----------------------------------------------------------------------
 */
void
Blt_TreeViewSelectCmdProc(clientData)
    ClientData clientData;	/* Information about widget. */
{
    TreeView *tvPtr = clientData;

    Tcl_Preserve(tvPtr);
    if (tvPtr->selectCmd != NULL) {
	tvPtr->flags &= ~TV_SELECT_PENDING;
	if (Tcl_GlobalEval(tvPtr->interp, tvPtr->selectCmd) != TCL_OK) {
	    Tcl_BackgroundError(tvPtr->interp);
	}
    }
    Tcl_Release(tvPtr);
}

/*
 * --------------------------------------------------------------
 *
 * TreeViewObjCmd --
 *
 * 	This procedure is invoked to process the Tcl command that
 * 	corresponds to a widget managed by this module. See the user
 * 	documentation for details on what it does.
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side effects:
 *	See the user documentation.
 *
 * --------------------------------------------------------------
 */
/* ARGSUSED */
static int
TreeViewObjCmd(clientData, interp, objc, objv)
    ClientData clientData;	/* Main window associated with interpreter. */
    Tcl_Interp *interp;		/* Current interpreter. */
    int objc;			/* Number of arguments. */
    Tcl_Obj *CONST *objv;	/* Argument strings. */
{
    Tcl_CmdInfo cmdInfo;
    Tcl_Obj *initObjv[2];
    TreeView *tvPtr;
    char *className;
    char *string;

    string = Tcl_GetString(objv[0]);
    if (objc < 2) {
	Tcl_AppendResult(interp, "wrong # args: should be \"", string, 
		" pathName ?option value?...\"", (char *)NULL);
	return TCL_ERROR;
    }
    className = (string[0] == 'h') ? "Hiertable" : "TreeView";
    tvPtr = CreateTreeView(interp, objv[1], className);
    if (tvPtr == NULL) {
	return TCL_ERROR;
    }
    tvPtr->cmdToken = Tcl_CreateObjCommand(interp, Tk_PathName(tvPtr->tkwin), 
	Blt_TreeViewWidgetInstCmd, tvPtr, WidgetInstCmdDeleteProc);

#ifdef ITCL_NAMESPACES
    Itk_SetWidgetCommand(tvPtr->tkwin, tvPtr->cmdToken);
#endif
    Tk_CreateSelHandler(tvPtr->tkwin, XA_PRIMARY, XA_STRING, SelectionProc,
	tvPtr, XA_STRING);
    Tk_CreateEventHandler(tvPtr->tkwin, ExposureMask | StructureNotifyMask |
	FocusChangeMask, TreeViewEventProc, tvPtr);
    /*
     * Invoke a procedure to initialize various bindings on treeview
     * entries.  If the procedure doesn't already exist, source it
     * from "$blt_library/treeview.tcl".  We deferred sourcing the
     * file until now so that the variable $blt_library could be set
     * within a script.
     */
    if (!Tcl_GetCommandInfo(interp, "blt::tv::Initialize", &cmdInfo)) {
	char cmd[200];
	sprintf(cmd, "set className %s\n\
source [file join $blt_library treeview.tcl]\n\
unset className\n", className);
	if (Tcl_GlobalEval(interp, cmd) != TCL_OK) {
	    char info[200];

	    sprintf(info, "\n    (while loading bindings for %.50s)", 
		    Tcl_GetString(objv[0]));
	    Tcl_AddErrorInfo(interp, info);
	    goto error;
	}
    }
    
    initObjv[0] = Tcl_NewStringObj("blt::tv::Initialize", -1);
    initObjv[1] = objv[1];
    if (Tcl_EvalObjv(interp, 2, initObjv, TCL_EVAL_GLOBAL) != TCL_OK) {
	goto error;
    }
    Tcl_DecrRefCount(initObjv[0]);
    bltTreeViewImagesOption.clientData = tvPtr;
    if (Blt_ConfigureComponentFromObj(interp, tvPtr->tkwin, "button", "Button",
	 bltTreeViewButtonSpecs, 0, (Tcl_Obj **)NULL, (char *)tvPtr, 0) 
	!= TCL_OK) {
	goto error;
    }
    if (Blt_TreeViewConfigureWidget(interp, tvPtr, objc - 2, objv + 2, 0) 
	!= TCL_OK) {
	goto error;
    }

    /* 
     * Configure the default column after configuring the widget so
     * that we can use its global resources (font, color, border,
     * etc) in building the GCs.  
     */
    Blt_TreeViewConfigureColumn(tvPtr, &tvPtr->treeColumn);

    Tcl_SetObjResult(interp, Tcl_NewStringObj(Tk_PathName(tvPtr->tkwin), -1));
    return TCL_OK;
  error:
    Tk_DestroyWindow(tvPtr->tkwin);
    return TCL_ERROR;
}

int
Blt_TreeViewInit(interp)
    Tcl_Interp *interp;
{
    static Blt_ObjCmdSpec cmdSpec[] = { 
	{ "treeview", TreeViewObjCmd, },
	{ "hiertable", TreeViewObjCmd, }
    };

    if (Blt_InitObjCmd(interp, "blt", cmdSpec) == NULL) {
	return TCL_ERROR;
    }
    if (Blt_InitObjCmd(interp, "blt", cmdSpec + 1) == NULL) {
	return TCL_ERROR;
    }
    Tcl_RegisterObjType(&entryObjType);
    return TCL_OK;
}

#endif /* NO_TREEVIEW */
