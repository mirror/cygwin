
/*
 * bltInit.c --
 *
 *	This module initials the BLT toolkit, registering its commands
 *	with the Tcl/Tk interpreter.
 *
 * Copyright 1991-1998 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies any of their entities not be used in
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
 */

#include <bltInt.h>

#ifdef __STDC__
static Tcl_MathProc MinMathProc, MaxMathProc;
#endif

#ifdef TCL_ONLY
#define NO_BELL		1
#define NO_BITMAP	1
#define NO_BUSY		1
#define NO_CONTAINER	1
#define NO_CUTBUFFER	1
#define NO_DND		1
#define NO_DRAGDROP	1
#define NO_GRAPH	1
#define NO_HIERBOX	1
#define NO_HTEXT	1
#define NO_MOUNTAIN	1
#define NO_PRINTER	1
#define NO_TABLE	1
#define NO_TABSET	1
#define NO_TABNOTEBOOK	1
#define NO_TED		1
#define NO_TILEBUTTON	1
#define NO_TILEFRAME	1
#define NO_TILESCROLLBAR 1
#define NO_WINOP	1
#define NO_TREEVIEW	1
#endif

static Tcl_AppInitProc *initProcArr[] =
{
#ifndef NO_GRAPH
    Blt_GraphInit,
#endif
#ifndef NO_TABLE
    Blt_TableInit,
#endif
#ifndef NO_HIERBOX
    Blt_HierboxInit,
#endif
#ifndef NO_TABSET
    Blt_TabsetInit,
#endif
#ifndef NO_TABNOTEBOOK
    Blt_TabnotebookInit,
#endif
#ifndef NO_HTEXT
    Blt_HtextInit,
#endif
#ifndef NO_BUSY
    Blt_BusyInit,
#endif
#ifndef NO_WINOP
    Blt_WinopInit,
#endif
#ifndef NO_BITMAP
    Blt_BitmapInit,
#endif
#ifndef NO_BGEXEC
    Blt_BgexecInit,
#endif
#ifndef NO_DRAGDROP
    Blt_DragDropInit,
#endif
#ifndef NO_DND
    Blt_DndInit,
#endif
#ifndef NO_DEBUG
    Blt_DebugInit,
#endif
#ifndef NO_WATCH
    Blt_WatchInit,
#endif
#ifndef NO_CONTAINER
    Blt_ContainerInit,
#endif
#ifndef NO_VECTOR
    Blt_VectorInit,
#endif
#ifndef NO_SPLINE
    Blt_SplineInit,
#endif
#ifndef NO_BELL
    Blt_BeepInit,
#endif
#ifndef NO_CUTBUFFER
    Blt_CutbufferInit,
#endif
#ifndef NO_PRINTER
    Blt_PrinterInit,
#endif
#ifndef NO_TILEFRAME
    Blt_FrameInit,
#endif
#ifndef NO_TILEBUTTON
    Blt_ButtonInit,
#endif
#ifndef NO_TILESCROLLBAR
    Blt_ScrollbarInit,
#endif
#ifndef NO_TREE
    Blt_TreeInit,
#endif
#ifndef NO_TREEVIEW
    Blt_TreeViewInit,
#endif
#if (BLT_MAJOR_VERSION == 3)
#ifndef NO_MOUNTAIN
    Blt_MountainInit,
#endif
#endif
#ifndef NO_TED
    Blt_TedInit,
#endif
#ifndef NO_DDE
    Blt_DdeInit,
#endif
    (Tcl_AppInitProc *) NULL
};

/* ARGSUSED */
static int
MinMathProc(clientData, interp, argsPtr, resultPtr)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;
    Tcl_Value *argsPtr;
    Tcl_Value *resultPtr;
{
    Tcl_Value *op1Ptr, *op2Ptr;

    op1Ptr = argsPtr, op2Ptr = argsPtr + 1;
    if ((op1Ptr->type == TCL_INT) && (op2Ptr->type == TCL_INT)) {
	resultPtr->intValue = MIN(op1Ptr->intValue, op2Ptr->intValue);
	resultPtr->type = TCL_INT;
    } else {
	double a, b;

	a = (op1Ptr->type == TCL_INT)
	    ? (double)op1Ptr->intValue : op1Ptr->doubleValue;
	b = (op2Ptr->type == TCL_INT)
	    ? (double)op2Ptr->intValue : op2Ptr->doubleValue;
	resultPtr->doubleValue = MIN(a, b);
	resultPtr->type = TCL_DOUBLE;
    }
    return TCL_OK;
}

/*ARGSUSED*/
static int
MaxMathProc(clientData, interp, argsPtr, resultPtr)
    ClientData clientData;	/* Not Used. */
    Tcl_Interp *interp;
    Tcl_Value *argsPtr;
    Tcl_Value *resultPtr;
{
    Tcl_Value *op1Ptr, *op2Ptr;

    op1Ptr = argsPtr, op2Ptr = argsPtr + 1;
    if ((op1Ptr->type == TCL_INT) && (op2Ptr->type == TCL_INT)) {
	resultPtr->intValue = MAX(op1Ptr->intValue, op2Ptr->intValue);
	resultPtr->type = TCL_INT;
    } else {
	double a, b;

	a = (op1Ptr->type == TCL_INT)
	    ? (double)op1Ptr->intValue : op1Ptr->doubleValue;
	b = (op2Ptr->type == TCL_INT)
	    ? (double)op2Ptr->intValue : op2Ptr->doubleValue;
	resultPtr->doubleValue = MAX(a, b);
	resultPtr->type = TCL_DOUBLE;
    }
    return TCL_OK;
}

#ifndef BLT_LIBRARY
#ifdef WIN32
#define BLT_LIBRARY  "c:/Program Files/Tcl/lib/blt"##BLT_VERSION
#else
#define BLT_LIBRARY "unknown"
#endif
#endif

static char libPath[1024] =
{
    BLT_LIBRARY
};

/*
 * Script to set the BLT library path in the variable global "blt_library"
 *
 * Checks the usual locations for a file (bltGraph.pro) from the BLT
 * library.  The places searched in order are
 *
 *	$BLT_LIBRARY
 *	$BLT_LIBRARY/blt2.4
 *      $BLT_LIBRARY/..
 *      $BLT_LIBRARY/../blt2.4
 *	$blt_libPath
 *	$blt_libPath/blt2.4
 *      $blt_libPath/..
 *      $blt_libPath/../blt2.4
 *	$tcl_library
 *	$tcl_library/blt2.4
 *      $tcl_library/..
 *      $tcl_library/../blt2.4
 *	$env(TCL_LIBRARY)
 *	$env(TCL_LIBRARY)/blt2.4
 *      $env(TCL_LIBRARY)/..
 *      $env(TCL_LIBRARY)/../blt2.4
 *
 *  The Tcl variable "blt_library" is set to the discovered path.
 *  If the file wasn't found, no error is returned.  The actual
 *  usage of $blt_library is purposely deferred so that it can be
 *  set from within a script.
 */

/* FIXME: Change this to a namespace procedure in 3.0 */

static char initScript[] =
{"\n\
global blt_library blt_libPath blt_version tcl_library env\n\
set blt_library {}\n\
set path {}\n\
foreach var { env(BLT_LIBRARY) blt_libPath tcl_library env(TCL_LIBRARY) } { \n\
    if { ![info exists $var] } { \n\
        continue \n\
    } \n\
    set path [set $var] \n\
    if { [file readable [file join $path bltGraph.pro]] } { \n\
        set blt_library $path\n\
        break \n\
    } \n\
    set path [file join $path blt$blt_version ] \n\
    if { [file readable [file join $path bltGraph.pro]] } { \n\
        set blt_library $path\n\
        break \n\
    } \n\
    set path [file dirname [set $var]] \n\
    if { [file readable [file join $path bltGraph.pro]] } { \n\
        set blt_library $path\n\
        break \n\
    } \n\
    set path [file join $path blt$blt_version ] \n\
    if { [file readable [file join $path bltGraph.pro]] } { \n\
        set blt_library $path\n\
        break \n\
    } \n\
} \n\
if { $blt_library != \"\" } { \n\
    global auto_path \n\
    lappend auto_path $blt_library \n\
}\n\
unset var path\n\
\n"
};

static int
GetVersionInfo(interp)
    Tcl_Interp *interp;
{
    Tcl_DString dString;
    char *value;
#define EXACT 1

    /*
     * Check that the versions of Tcl that have been loaded are the 
     * same ones that BLT was compiled against.
     */
#ifdef USE_TCL_STUBS
     if (Tcl_InitStubs(interp, TCL_VERSION, EXACT) == NULL) {
	 return TCL_ERROR;
     }
#else 
    if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, EXACT) == NULL) {
	return TCL_ERROR;
    }
#endif /* USE_TCL_STUBS */

#ifndef TCL_ONLY
#ifdef USE_TK_STUBS
     if (Tk_InitStubs(interp, TK_VERSION, EXACT) == NULL) {
	 return TCL_ERROR;
     }
#else
    if (Tcl_PkgRequire(interp, "Tk", TK_VERSION, EXACT) == NULL) {
	return TCL_ERROR;
    }
#endif /* USE_TK_STUBS */
#endif /* TCL_ONLY */

    /* Set the version variable. We'll use it in the following script. */
    value = Tcl_SetVar(interp, "blt_version", BLT_VERSION, TCL_GLOBAL_ONLY);
    if (value == NULL) {
	return TCL_ERROR;
    }
    value = Tcl_SetVar(interp, "blt_patchLevel", BLT_PATCH_LEVEL, 
	       TCL_GLOBAL_ONLY);
    if (value == NULL) {
	return TCL_ERROR;
    }
    Tcl_DStringInit(&dString);
    Tcl_DStringAppend(&dString, libPath, -1);
#ifdef WIN32
    {
	HKEY key;
	DWORD result;
#ifndef BLT_REGISTRY_KEY
#define BLT_REGISTRY_KEY "Software\\BLT\\" BLT_VERSION "\\" TCL_VERSION
#endif
	result = RegOpenKeyEx(
	      HKEY_LOCAL_MACHINE, /* Parent key. */
	      BLT_REGISTRY_KEY,	/* Path to sub-key. */
	      0,		/* Reserved. */
	      KEY_READ,		/* Security access mask. */
	      &key);		/* Resulting key.*/

	if (result == ERROR_SUCCESS) {
	    DWORD size;

	    /* Query once to get the size of the string needed */
	    result = RegQueryValueEx(key, "BLT_LIBRARY", NULL, NULL, NULL, 
		     &size);
	    if (result == ERROR_SUCCESS) {
		Tcl_DStringSetLength(&dString, size);
		/* And again to collect the string. */
		RegQueryValueEx(key, "BLT_LIBRARY", NULL, NULL,
				(LPBYTE)Tcl_DStringValue(&dString), &size);
		RegCloseKey(key);
	    }
	}
    }
#endif /* WIN32 */
    value = Tcl_SetVar(interp, "blt_libPath", Tcl_DStringValue(&dString),
	TCL_GLOBAL_ONLY | TCL_LEAVE_ERR_MSG);
    Tcl_DStringFree(&dString);
    if (value == NULL) {
	return TCL_ERROR;
    }
    if (Tcl_Eval(interp, initScript) != TCL_OK) {
	return TCL_ERROR;
    }
    return TCL_OK;
}

#if (TCL_MAJOR_VERSION > 7)

/*LINTLIBRARY*/

#ifdef WIN32
extern int bltPlatformId;

/*
 *----------------------------------------------------------------------
 *
 * DllMain --
 *
 *	This wrapper function is used by Windows to invoke the
 *	initialization code for the DLL.
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
DllMain(
    HINSTANCE hInst,		/* Library instance handle. */
    DWORD reason,		/* Reason this function is being called. */
    LPVOID reserved)		/* Not used. */
{
    return TRUE;
}

#endif

EXPORT int
Blt_Init(interp)
    Tcl_Interp *interp;		/* Interpreter to add extra commands */
{
    register Tcl_AppInitProc **p;
    Tcl_ValueType args[2];
    Tcl_Namespace *spacePtr;

    if (GetVersionInfo(interp) != TCL_OK) {
	return TCL_ERROR;
    }
    spacePtr = NULL;
#ifndef TCL_ONLY
    spacePtr = Tcl_CreateNamespace(interp, "blt::tile", NULL, 
	(Tcl_NamespaceDeleteProc *) NULL);
    if (spacePtr == NULL) {
	return TCL_ERROR;
    }
#endif
    for (p = initProcArr; *p != NULL; p++) {
	if ((**p) (interp) != TCL_OK) {
	    Tcl_DeleteNamespace(spacePtr);
	    return TCL_ERROR;
	}
    }
    if (Tcl_PkgProvide(interp, "BLT", BLT_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }
    args[0] = args[1] = TCL_EITHER;
    Tcl_CreateMathFunc(interp, "min", 2, args, MinMathProc, (ClientData)0);
    Tcl_CreateMathFunc(interp, "max", 2, args, MaxMathProc, (ClientData)0);
#ifndef TCL_ONLY
    Blt_InitEpsCanvasItem(interp);
#endif
    return TCL_OK;
}

#else

/*LINTLIBRARY*/
EXPORT int
Blt_Init(interp)
    Tcl_Interp *interp;		/* Interpreter to add extra commands */
{
    register Tcl_AppInitProc **p;
    Tcl_ValueType args[2];

#ifdef ITCL_NAMESPACES
    Itcl_Namespace dummy, spaceId;	/* Token for "blt" namespace
					 * created, used to delete the
					 * namespace on errors. */
    spaceId = NULL;
#endif
    if (GetVersionInfo(interp) != TCL_OK) {
	return TCL_ERROR;
    }
#ifdef ITCL_NAMESPACES
    if (Itcl_CreateNamesp(interp, "blt", (ClientData)0,
	    (Itcl_DeleteProc *) 0, &spaceId) != TCL_OK) {
	return TCL_ERROR;
    }
#ifndef TCL_ONLY
    if (Itcl_CreateNamesp(interp, "blt::tile", (ClientData)0,
	    (Itcl_DeleteProc *) 0, &dummy) != TCL_OK) {
	return TCL_ERROR;
    }
#endif /* TCL_ONLY */
#endif /* ITCL_NAMESPACES */
    if (Tcl_PkgProvide(interp, "BLT", BLT_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }
    for (p = initProcArr; *p != NULL; p++) {
	if ((**p) (interp) != TCL_OK) {
#ifdef ITCL_NAMESPACES
	    if (spaceId != NULL) {
		Itcl_DeleteNamesp(spaceId);
	    }
#endif
	    return TCL_ERROR;
	}
    }
    args[0] = args[1] = TCL_EITHER;
    Tcl_CreateMathFunc(interp, "min", 2, args, MinMathProc, (ClientData)0);
    Tcl_CreateMathFunc(interp, "max", 2, args, MaxMathProc, (ClientData)0);
#ifndef TCL_ONLY
    Blt_InitEpsCanvasItem(interp);
#endif
#if (TCL_MAJOR_VERSION > 7)
    Blt_RegisterArrayType(interp);
#endif
    return TCL_OK;
}

#endif /* TCL_MAJOR_VERION >= 8 */

/*LINTLIBRARY*/
EXPORT int
Blt_SafeInit(interp)
    Tcl_Interp *interp;		/* Interpreter to add extra commands */
{
    return Blt_Init(interp);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_InitCmd --
 *
 *      Given the name of a command, return a pointer to the
 *      clientData field of the command.
 *
 * Results:
 *      A standard TCL result. If the command is found, TCL_OK
 *	is returned and clientDataPtr points to the clientData
 *	field of the command (if the clientDataPtr in not NULL).
 *
 * Side effects:
 *      If the command is found, clientDataPtr is set to the address
 *	of the clientData of the command.  If not found, an error
 *	message is left in interp->result.
 *
 *----------------------------------------------------------------------
 */

/*ARGSUSED*/
Tcl_Command
Blt_InitCmd(interp, nsName, specPtr)
    Tcl_Interp *interp;
    char *nsName;
    Blt_CmdSpec *specPtr;
{
    char *cmdPath;
    Tcl_DString dString;
    Tcl_Command cmdToken;

    Tcl_DStringInit(&dString);
#if HAVE_NAMESPACES
    if (nsName != NULL) {
	Tcl_DStringAppend(&dString, nsName, -1);
    }
    Tcl_DStringAppend(&dString, "::", -1);
#endif /* HAVE_NAMESPACES */
    Tcl_DStringAppend(&dString, specPtr->name, -1);

    cmdPath = Tcl_DStringValue(&dString);
    cmdToken = Tcl_FindCommand(interp, cmdPath, (Tcl_Namespace *)NULL, 0);
    if (cmdToken != NULL) {
	Tcl_DStringFree(&dString);
	return cmdToken;	/* Assume command was already initialized */
    }
    cmdToken = Tcl_CreateCommand(interp, cmdPath, specPtr->cmdProc,
	specPtr->clientData, specPtr->cmdDeleteProc);
    Tcl_DStringFree(&dString);

#if (HAVE_NAMESPACES) && (TCL_MAJOR_VERSION > 7)
    {
	Tcl_Namespace *nsPtr;
	int dontResetList = 0;

	nsPtr = Tcl_FindNamespace(interp, nsName, (Tcl_Namespace *)NULL,
	    TCL_LEAVE_ERR_MSG);
	if (nsPtr == NULL) {
	    return NULL;
	}
	if (Tcl_Export(interp, nsPtr, specPtr->name, dontResetList) != TCL_OK) {
	    return NULL;
	}
    }
#endif /* TCL_MAJOR_VERSION > 7 */
    return cmdToken;
}

#if (TCL_MAJOR_VERSION > 7)
/*
 *----------------------------------------------------------------------
 *
 * Blt_InitObjCmd --
 *
 *      Given the name of a command, return a pointer to the
 *      clientData field of the command.
 *
 * Results:
 *      A standard TCL result. If the command is found, TCL_OK
 *	is returned and clientDataPtr points to the clientData
 *	field of the command (if the clientDataPtr in not NULL).
 *
 * Side effects:
 *      If the command is found, clientDataPtr is set to the address
 *	of the clientData of the command.  If not found, an error
 *	message is left in interp->result.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
Tcl_Command
Blt_InitObjCmd(interp, nsName, specPtr)
    Tcl_Interp *interp;
    char *nsName;
    Blt_ObjCmdSpec *specPtr;
{
    char *cmdPath;
    Tcl_DString dString;
    Tcl_Command cmdToken;
    Tcl_Namespace *nsPtr;

    Tcl_DStringInit(&dString);
    if (nsName != NULL) {
	Tcl_DStringAppend(&dString, nsName, -1);
    }
    Tcl_DStringAppend(&dString, "::", -1);
    Tcl_DStringAppend(&dString, specPtr->name, -1);

    cmdPath = Tcl_DStringValue(&dString);
    cmdToken = Tcl_FindCommand(interp, cmdPath, (Tcl_Namespace *)NULL, 0);
    if (cmdToken != NULL) {
	Tcl_DStringFree(&dString);
	return cmdToken;	/* Assume command was already initialized */
    }
    cmdToken = Tcl_CreateObjCommand(interp, cmdPath, 
		(Tcl_ObjCmdProc *)specPtr->cmdProc, 
		specPtr->clientData, 
		specPtr->cmdDeleteProc);
    Tcl_DStringFree(&dString);

    nsPtr = Tcl_FindNamespace(interp, nsName, (Tcl_Namespace *)NULL,
	      TCL_LEAVE_ERR_MSG);
    if (nsPtr == NULL) {
	return NULL;
    }
    if (Tcl_Export(interp, nsPtr, specPtr->name, FALSE) != TCL_OK) {
	return NULL;
    }
    return cmdToken;
}

#endif /* TCL_MAJOR_VERSION > 7 */

/*
 *----------------------------------------------------------------------
 *
 * Blt_InitCmds --
 *
 *      Given the name of a command, return a pointer to the
 *      clientData field of the command.
 *
 * Results:
 *      A standard TCL result. If the command is found, TCL_OK
 *	is returned and clientDataPtr points to the clientData
 *	field of the command (if the clientDataPtr in not NULL).
 *
 * Side effects:
 *      If the command is found, clientDataPtr is set to the address
 *	of the clientData of the command.  If not found, an error
 *	message is left in interp->result.
 *
 *----------------------------------------------------------------------
 */
int
Blt_InitCmds(interp, nsName, specPtr, nCmds)
    Tcl_Interp *interp;
    char *nsName;
    Blt_CmdSpec *specPtr;
    int nCmds;
{
    Blt_CmdSpec *endPtr;

    for (endPtr = specPtr + nCmds; specPtr < endPtr; specPtr++) {
	if (Blt_InitCmd(interp, nsName, specPtr) == NULL) {
	    return TCL_ERROR;
	}
    }
    return TCL_OK;
}
