/*
 * bltInt.h --
 *
 * Copyright 1993-1998 Lucent Technologies, Inc.
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

#ifndef _BLT_INT_H
#define _BLT_INT_H

#ifdef WIN32
#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef STRICT
#undef WIN32_LEAN_AND_MEAN
#include <windowsx.h>
#endif /* WIN32 */

#include <tcl.h>
#include <tk.h>

#define _VERSION(a,b,c)	    (((a) << 16) + ((b) << 8) + (c))
#define TCL_VERSION_NUMBER _VERSION(TCL_MAJOR_VERSION, TCL_MINOR_VERSION, TCL_RELEASE_SERIAL)
#define TK_VERSION_NUMBER _VERSION(TK_MAJOR_VERSION, TK_MINOR_VERSION, TK_RELEASE_SERIAL)

#include "bltTkInt.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

#ifndef BLT_CONFIG_H
#ifdef WIN32
#include "bltWinConfig.h"
#else
#include "bltConfig.h"
#endif
#define BLT_CONFIG_H 1
#endif

#include "blt.h"
#include "bltNsUtil.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif /* HAVE_STDLIB_H */

#ifdef HAVE_STRING_H
#include <string.h>
#endif /* HAVE_STRING_H */

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif /* HAVE_ERRNO_H */

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif /* HAVE_CTYPE_H */

#ifdef HAVE_MEMORY_H
#include <memory.h>
#endif /* HAVE_MEMORY_H */

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_FLOAT_H
#include <float.h>
#endif

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifdef HAVE_IEEEFP_H
#include <ieeefp.h>
#endif /* HAVE_IEEEFP_H */

#ifndef M_PI
#define M_PI    	3.14159265358979323846
#endif /* M_PI */

#ifndef M_PI_2
#define M_PI_2		1.57079632679489661923
#endif

#ifndef M_SQRT2
#define M_SQRT2		1.41421356237309504880
#endif /* M_SQRT2 */

#ifndef M_SQRT1_2
#define M_SQRT1_2	0.70710678118654752440
#endif /* M_SQRT1_2 */

#ifndef SHRT_MAX
#define SHRT_MAX	0x7FFF
#endif /* SHRT_MAX */

#ifndef SHRT_MIN
#define SHRT_MIN	-(SHRT_MAX)
#endif /* SHRT_MAX */

#ifndef USHRT_MAX
#define	USHRT_MAX	0xFFFF
#endif /* USHRT_MAX */

#ifndef INT_MAX
#define INT_MAX		2147483647
#endif /* INT_MAX */

#ifndef HAVE_FLOAT_H
/*
 * ----------------------------------------------------------------------
 *
 * DBL_MIN, DBL_MAX --
 *
 * 	DBL_MAX and DBL_MIN are the largest and smaller double
 * 	precision numbers that can be represented by the floating
 * 	point hardware. If the compiler is ANSI, they can be found in
 * 	float.h.  Otherwise, we use HUGE_VAL or HUGE to determine
 * 	them.
 *
 * ----------------------------------------------------------------------
 */
/*
 * Don't want to include __infinity (definition of HUGE_VAL (SC1.x))
 */
#ifdef sun
#define DBL_MAX		1.7976931348623157E+308
#define DBL_MIN		2.2250738585072014E-308
#define DBL_EPSILON	2.2204460492503131e-16
#else
#ifndef DBL_EPSILON
#define DBL_EPSILON	BLT_DBL_EPSILON
#endif
#ifdef HUGE_VAL
#define DBL_MAX		HUGE_VAL
#define DBL_MIN		(1/HUGE_VAL)
#else
#ifdef HUGE
#define DBL_MAX		HUGE
#define DBL_MIN		(1/HUGE)
#else
/*
 * Punt: Assume values simple and relatively small
 */
#define DBL_MAX		3.40282347E+38
#define DBL_MIN		1.17549435E-38
#endif /*HUGE*/
#endif /*HUGE_VAL*/
#endif /*sun*/
#endif /*!HAVE_FLOAT_H*/

#undef INLINE
#ifdef __GNUC__
#define INLINE inline
#else
#define INLINE
#endif
#undef EXPORT
#define EXPORT

#undef VARARGS
#ifdef __cplusplus
#define ANYARGS (...)
#define VARARGS(first)  (first, ...)
#define VARARGS2(first, second)  (first, second, ...)
#else
#define ANYARGS ()
#define VARARGS(first) ()
#define VARARGS2(first, second) ()
#endif /* __cplusplus */

#undef MIN
#define MIN(a,b)	(((a)<(b))?(a):(b))

#undef MAX
#define MAX(a,b)	(((a)>(b))?(a):(b))

#undef MIN3
#define MIN3(a,b,c)	(((a)<(b))?(((a)<(c))?(a):(c)):(((b)<(c))?(b):(c)))

#undef MAX3
#define MAX3(a,b,c)	(((a)>(b))?(((a)>(c))?(a):(c)):(((b)>(c))?(b):(c)))

/*
 * ----------------------------------------------------------------------
 *
 *  	The following are macros replacing math library functions:
 *  	"fabs", "fmod", "abs", "rint", and "exp10".
 *
 *  	Although many of these routines may be in your math library,
 *  	they aren't used in libtcl.a or libtk.a.  This makes it
 *  	difficult to dynamically load the BLT library as a shared
 *  	object unless the math library is also shared (which isn't
 *  	true on several systems).  We can avoid the problem by
 *  	replacing the "exotic" math routines with macros.
 *
 * ----------------------------------------------------------------------
 */
#undef ABS
#define ABS(x)		(((x)<0)?(-(x)):(x))

#undef EXP10
#define EXP10(x)	(pow(10.0,(x)))

#undef FABS
#define FABS(x) 	(((x)<0.0)?(-(x)):(x))

#undef SIGN
#define SIGN(x)		(((x) < 0.0) ? -1 : 1)

/*
 * Be careful when using the next two macros.  They both assume the floating
 * point number is less than the size of an int.  That means, for example, you
 * can't use these macros with numbers bigger than than 2^31-1.
 */
#undef FMOD
#define FMOD(x,y) 	((x)-(((int)((x)/(y)))*y))

#undef ROUND
#define ROUND(x) 	((int)((x) + (((x)<0.0) ? -0.5 : 0.5)))

#define TRUE 	1
#define FALSE 	0
/*
 * The macro below is used to modify a "char" value (e.g. by casting
 * it to an unsigned character) so that it can be used safely with
 * macros such as isspace.
 */
#define UCHAR(c) ((unsigned char) (c))

#undef panic
#define panic(mesg)	Blt_Panic("%s:%d %s", __FILE__, __LINE__, (mesg))

#ifdef HAVE_FINITE
#else
#ifdef HAVE_ISFINITE
#define finite(x)		isfinite(x)
#endif /* HAVE_ISFINITE */
#endif /* HAVE_FINITE */

/*
 * Since the Tcl/Tk distribution doesn't perform any asserts, dynamic
 * loading can fail to find the __assert function.  As a workaround,
 * we'll include our own.
 */
#undef	assert
#ifdef	NDEBUG
#define	assert(EX) ((void)0)
#else
extern void Blt_Assert _ANSI_ARGS_((char *expr, char *file, int line));
#ifdef __STDC__
#define	assert(EX) (void)((EX) || (Blt_Assert(#EX, __FILE__, __LINE__), 0))
#else
#define	assert(EX) (void)((EX) || (Blt_Assert("EX", __FILE__, __LINE__), 0))
#endif /* __STDC__ */

#endif /* NDEBUG */

/*
 * ----------------------------------------------------------------------
 *
 * Blt_CmdSpec --
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    char *name;			/* Name of command */
    Tcl_CmdProc *cmdProc;
    Tcl_CmdDeleteProc *cmdDeleteProc;
    ClientData clientData;
} Blt_CmdSpec;

#if (TCL_MAJOR_VERSION >= 8)
/*
 * ----------------------------------------------------------------------
 *
 * Blt_CmdSpec --
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    char *name;			/* Name of command */
    Tcl_ObjCmdProc *cmdProc;
    Tcl_CmdDeleteProc *cmdDeleteProc;
    ClientData clientData;
} Blt_ObjCmdSpec;

#endif /* TCL_MAJOR_VERSION >= 8 */

/*
 * ----------------------------------------------------------------------
 *
 * Blt_Op --
 *
 * 	Generic function prototype of CmdOptions.
 *
 * ----------------------------------------------------------------------
 */
typedef int (*Blt_Op) _ANSI_ARGS_(ANYARGS);

/*
 * ----------------------------------------------------------------------
 *
 * Blt_OpSpec --
 *
 * 	Structure to specify a set of operations for a Tcl command.
 *      This is passed to the Blt_GetOp procedure to look
 *      for a function pointer associated with the operation name.
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    char *name;			/* Name of operation */
    int minChars;		/* Minimum # characters to disambiguate */
    Blt_Op proc;
    int minArgs;		/* Minimum # args required */
    int maxArgs;		/* Maximum # args required */
    char *usage;		/* Usage message */

} Blt_OpSpec;

typedef enum {
    BLT_OP_ARG0,		/* Op is the first argument. */
    BLT_OP_ARG1,		/* Op is the second argument. */
    BLT_OP_ARG2,		/* Op is the third argument. */
    BLT_OP_ARG3,		/* Op is the fourth argument. */
    BLT_OP_ARG4			/* Op is the fifth argument. */

} Blt_OpIndex;

#define BLT_OP_LINEAR_SEARCH	1
#define BLT_OP_BINARY_SEARCH	0

extern Blt_Op Blt_GetOp _ANSI_ARGS_((Tcl_Interp *interp, int nSpecs, 
	Blt_OpSpec *specArr, int operPos, int argc, char **argv, int flags));

#if (TCL_VERSION_NUMBER >= _VERSION(8,0,0)) 
extern Blt_Op Blt_GetOpFromObj _ANSI_ARGS_((Tcl_Interp *interp,
	int nSpecs, Blt_OpSpec *specArr, int operPos, int objc, 
	Tcl_Obj *CONST *objv, int flags));
#endif

/*
 * ----------------------------------------------------------------------
 *
 *	Assume we need to declare free if there's no stdlib.h or malloc.h
 *
 * ----------------------------------------------------------------------
 */
#if !defined(HAVE_STDLIB_H) && !defined(HAVE_MALLOC_H)
extern void free _ANSI_ARGS_((void *));
#endif

#define free(x)		abc123(x)

/*
 * ----------------------------------------------------------------------
 *
 *	On some systems "strdup" and "strcasecmp" are in the C library,
 *      but have no declarations in the C header files. Make sure we
 *      supply them here.
 *
 * ----------------------------------------------------------------------
 */
#ifdef NEED_DECL_STRDUP
extern char *strdup _ANSI_ARGS_((CONST char *s));
#endif /* NEED_DECL_STRDUP */

#ifndef HAVE_STRTOLOWER
extern void strtolower _ANSI_ARGS_((char *s));
#endif /* HAVE_STRTOLOWER */

#ifdef NEED_DECL_DRAND48
extern double drand48 _ANSI_ARGS_((void));
extern void srand48 _ANSI_ARGS_((long seed));
#endif /* NEED_DECL_DRAND48 */

#ifdef NEED_DECL_STRCASECMP
extern int strcasecmp _ANSI_ARGS_((CONST char *s1, CONST char *s2));
#endif /* NEED_DECL_STRCASECMP */

extern int Blt_DictionaryCompare _ANSI_ARGS_((char *s1, char *s2));

EXTERN void Blt_Panic _ANSI_ARGS_(TCL_VARARGS(char *, args));



/* ---------------------------------------------------------------- */

#define PIXELS_NONNEGATIVE	0
#define PIXELS_POSITIVE		1
#define PIXELS_ANY		2

#define COUNT_NONNEGATIVE	0
#define COUNT_POSITIVE		1
#define COUNT_ANY		2

#define BLT_SCROLL_MODE_CANVAS	(1<<0)
#define BLT_SCROLL_MODE_LISTBOX	(1<<1)
#define BLT_SCROLL_MODE_HIERBOX	(1<<2)

#define RGB_ANTIQUEWHITE1	"#ffefdb"
#define RGB_BISQUE1		"#ffe4c4"
#define RGB_BISQUE2		"#eed5b7"
#define RGB_BISQUE3		"#cdb79e"
#define RGB_BLACK		"#000000"
#define RGB_BLUE		"#0000ff"
#define RGB_GREEN		"#00ff00"
#define RGB_GREY		"#b0b0b0"
#define RGB_GREY15		"#262626"
#define RGB_GREY50		"#7f7f7f"
#define RGB_GREY64		"#a3a3a3"
#define RGB_GREY70		"#b3b3b3"
#define RGB_GREY75		"#bfbfbf"
#define RGB_GREY77		"#c3c3c3"
#define RGB_GREY82		"#d1d1d1"
#define RGB_GREY85		"#d9d9d9"
#define RGB_GREY90		"#e5e5e5"
#define RGB_GREY95		"#f2f2f2"
#define RGB_LIGHTBLUE0		"#e4f7ff"
#define RGB_LIGHTBLUE1		"#bfefff"
#define RGB_LIGHTBLUE2		"#b2dfee"
#define RGB_LIGHTSKYBLUE1	"#b0e2ff"
#define RGB_MAROON		"#b03060"
#define RGB_NAVYBLUE		"#000080"
#define RGB_PINK		"#ffc0cb"
#define RGB_BISQUE1		"#ffe4c4"
#define RGB_RED			"#ff0000"
#define RGB_WHITE		"#ffffff"
#define RGB_YELLOW		"#ffff00"

#ifdef OLD_TK_COLORS
#define STD_COLOR_NORMAL_BG	RGB_BISQUE1
#define STD_COLOR_ACTIVE_BG	RGB_BISQUE2
#define STD_COLOR_SELECT_BG	RGB_LIGHTBLUE2
#define STD_COLOR_DISABLE_FG	RGB_GREY64
#else
#define STD_COLOR_NORMAL_BG	RGB_GREY85
#define STD_COLOR_ACTIVE_BG	RGB_GREY64
#define STD_COLOR_SELECT_BG	RGB_GREY77
#define STD_COLOR_DISABLE_FG	RGB_GREY64
#endif /* OLD_TK_COLORS */

#define STD_COLOR_INDICATOR	RGB_MAROON

#define STD_COLOR_ACTIVE_FG	RGB_BLACK
#define STD_COLOR_NORMAL_FG	RGB_BLACK
#define STD_COLOR_SELECT_FG	RGB_BLACK
#define STD_COLOR_SHADOW	RGB_GREY64
#define STD_MONO_ACTIVE_BG	RGB_BLACK
#define STD_MONO_ACTIVE_FG	RGB_WHITE
#define STD_MONO_NORMAL_BG	RGB_WHITE
#define STD_MONO_NORMAL_FG	RGB_BLACK
#define STD_MONO_SELECT_BG	RGB_BLACK
#define STD_MONO_SELECT_FG	RGB_WHITE
#define STD_MONO_SHADOW		RGB_BLACK

#define STD_SELECT_BORDERWIDTH	"2"
#define STD_BORDERWIDTH 	"2"

#define STD_FONT_HUGE		"*-Helvetica-Medium-R-Normal-*-18-180-*"
#define STD_FONT_LARGE		"*-Helvetica-Medium-R-Normal-*-14-140-*"
#define STD_FONT		"*-Helvetica-Medium-R-Normal-*-12-120-*"
#define STD_FONT_SMALL		"*-Helvetica-Medium-R-Normal-*-10-100-*"

#ifdef WIN32
#undef STD_FONT
#undef STD_FONT_SMALL
#undef STD_FONT_LARGE
#undef STD_COLOR_NORMAL_BG
#undef STD_COLOR_NORMAL_FG
#undef STD_COLOR_TEXT_FG
#undef STD_COLOR_SELECT_BG

#define STD_FONT		"Arial 8"
#define STD_FONT_SMALL		"Arial 6"
#define STD_FONT_LARGE		"Arial 12"
#define STD_COLOR_NORMAL_BG	"SystemButtonFace"
#define STD_COLOR_NORMAL_FG	"SystemButtonText"
#define STD_COLOR_TEXT_FG	"SystemWindowText"
#define STD_COLOR_SELECT_BG	"SystemHighlight"
#endif /* WIN32 */

#ifdef HAVE_XEXTENDEDMAXREQUESTSIZE
#define Blt_MaxRequestSize(d)	\
	MAX(XExtendedMaxRequestSize(d), XMaxRequestSize(d))
#else
#define Blt_MaxRequestSize(d)	XMaxRequestSize(d)
#endif

#define LineWidth(w)	(((w) > 1) ? (w) : 0)

#ifdef TCL_UTF_MAX
#define HAVE_UTF	1
extern FILE *Blt_OpenUtfFile _ANSI_ARGS_((char *fileName, char *mode));
#define fopen(f,m)	Blt_OpenUtfFile((f),(m));
#else
#define HAVE_UTF	0
#endif /* TCL_UTF_MAX */

typedef char *DestroyData;


#ifndef TK_RELIEF_SOLID
#define TK_RELIEF_SOLID		TK_RELIEF_FLAT
#endif

/*
 * Tcl/Tk Backward compatibility section.
 */
#if (TCL_MAJOR_VERSION > 7)

#define NO_FLAGS			0
#define Blt_FindPhoto(interp, name)	Tk_FindPhoto(interp, name)

#else

#define Tcl_GetStringResult(interp)	((interp)->result)
#define Blt_FindPhoto(interp, name)	Tk_FindPhoto(name)

#define Tcl_DeleteCommandFromToken(interp, token) \
	Tcl_DeleteCommand(interp, Tcl_GetCommandName(interp, token))

/*
 *--------------------------------------------------------------
 *
 * The definitions below provide foreward compatibility for
 * functions and types related to event handling that used to
 * be in Tk but have moved to Tcl.
 *
 *--------------------------------------------------------------
 */

#define Tcl_IdleProc		Tk_IdleProc
#define Tcl_FileProc		Tk_FileProc
#define Tcl_TimerProc		Tk_TimerProc
#define Tcl_TimerToken		Tk_TimerToken

#define Tcl_BackgroundError	Tk_BackgroundError
#define Tcl_CancelIdleCall	Tk_CancelIdleCall

#define Tcl_CreateTimerHandler	Tk_CreateTimerHandler
#define Tcl_DeleteTimerHandler	Tk_DeleteTimerHandler
#define Tcl_DoOneEvent		Tk_DoOneEvent
#define Tcl_DoWhenIdle		Tk_DoWhenIdle
#define Tcl_Sleep		Tk_Sleep

/* Additional stuff that has moved to Tcl: */

#define Tcl_AfterCmd		Tk_AfterCmd
#define Tcl_EventuallyFree	Tk_EventuallyFree
#define Tcl_FreeProc		Tk_FreeProc
#define Tcl_Preserve		Tk_Preserve
#define Tcl_Release		Tk_Release

#endif /* TCL_MAJOR_VERSION > 7 */

typedef int (QSortCompareProc) _ANSI_ARGS_((const void *, const void *));


/*
 * ----------------------------------------------------------------------
 *
 * Blt_Pad --
 *
 * 	Specifies vertical and horizontal padding.
 *
 *	Padding can be specified on a per side basis.  The fields
 *	side1 and side2 refer to the opposite sides, either
 *	horizontally or vertically.
 *
 *		side1	side2
 *              -----   -----
 *          x | left    right
 *	    y | top     bottom
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    short int side1, side2;
} Blt_Pad;

#define padLeft  	padX.side1
#define padRight  	padX.side2
#define padTop		padY.side1
#define padBottom	padY.side2
#define PADDING(x)	((x).side1 + (x).side2)

/*
 * ----------------------------------------------------------------------
 *
 * The following enumerated values are used as bit flags.
 *	FILL_NONE		Neither coordinate plane is specified 
 *	FILL_X			Horizontal plane.
 *	FILL_Y			Vertical plane.
 *	FILL_BOTH		Both vertical and horizontal planes.
 *
 * ----------------------------------------------------------------------
 */
#define FILL_NONE	0
#define FILL_X		1
#define FILL_Y		2
#define FILL_BOTH	3

/*
 * ----------------------------------------------------------------------
 *
 * Blt_Dashes --
 *
 * 	List of dash values (maximum 11 based upon PostScript limit).
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    unsigned char values[12];
    int offset;
} Blt_Dashes;

#define LineIsDashed(d) ((d).values[0] != 0)

extern void Blt_SetDashes _ANSI_ARGS_((Display *display, GC gc,
	Blt_Dashes *dashesPtr));
extern Blt_Dashes *Blt_GetDashes _ANSI_ARGS_((GC gc));

/*
 * -------------------------------------------------------------------
 *
 * Point2D --
 *
 *	2-D coordinate.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    double x, y;
} Point2D;

/*
 * -------------------------------------------------------------------
 *
 * Point3D --
 *
 *	3-D coordinate.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    double x, y, z;
} Point3d;

/*
 * -------------------------------------------------------------------
 *
 * Segment2D --
 *
 *	2-D line segment.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    Point2D p, q;		/* The two end points of the segment. */
} Segment2D;

/*
 * -------------------------------------------------------------------
 *
 * Dim2D --
 *
 *	2-D dimension.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    short int width, height;
} Dim2D;

/*
 *----------------------------------------------------------------------
 *
 * Region2D --
 *
 *      2-D region.  Used to copy parts of images.
 *
 *----------------------------------------------------------------------
 */
typedef struct {
    int left, right, top, bottom;
} Region2D;

#define RegionWidth(r)		((r)->right - (r)->left + 1)
#define RegionHeight(r)		((r)->bottom - (r)->top + 1)

typedef struct {
    double left, right, top, bottom;
} Extents2D;

typedef struct {
    double left, right, top, bottom, front, back;
} Extents3D;

#define PointInRegion(e,x,y) \
	(((x) <= (e)->right) && ((x) >= (e)->left) && \
	 ((y) <= (e)->bottom) && ((y) >= (e)->top))

#define PointInRectangle(r,x0,y0) \
	(((x0) <= (int)((r)->x + (r)->width - 1)) && ((x0) >= (int)(r)->x) && \
	 ((y0) <= (int)((r)->y + (r)->height - 1)) && ((y0) >= (int)(r)->y))


/* -------------------------------------------------------------------
 *
 * ColorPair --
 *
 *	Holds a pair of foreground, background colors.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    XColor *fgColor, *bgColor;
} ColorPair;

#define COLOR_NONE		(XColor *)0
#define COLOR_DEFAULT		(XColor *)1
#define COLOR_ALLOW_DEFAULTS	1

extern int Blt_GetColorPair _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *fgColor, char *bgColor, ColorPair *pairPtr, int colorFlag));
extern void Blt_FreeColorPair _ANSI_ARGS_((ColorPair *pairPtr));

#define STATE_NORMAL	0
#define STATE_ACTIVE	(1<<0)
#define STATE_DISABLED	(1<<1)
#define STATE_EMPHASIS	(1<<2)


#include "bltText.h"

/*
 * ----------------------------------------------------------------------
 *
 * 	X11/Xosdefs.h requires XNOSTDHDRS be set for some systems.
 *	This is a guess.  If I can't find STDC headers or unistd.h,
 *	assume that this is non-POSIX and non-STDC environment.
 *	(needed for Encore Umax 3.4 ?)
 *
 * ----------------------------------------------------------------------
 */
#if !defined(STDC_HEADERS) && !defined(HAVE_UNISTD_H)
#define XNOSTDHDRS 	1
#endif

extern char *Blt_Itoa _ANSI_ARGS_((int value));
extern char *Blt_Utoa _ANSI_ARGS_((unsigned int value));
extern char *Blt_Dtoa _ANSI_ARGS_((Tcl_Interp *interp, double value));
extern Tcl_Command Blt_InitCmd _ANSI_ARGS_((Tcl_Interp *interp,
	char *namespace, Blt_CmdSpec *specPtr));

#if (TCL_VERSION_NUMBER >= _VERSION(8,0,0)) 
extern Tcl_Command Blt_InitObjCmd _ANSI_ARGS_((Tcl_Interp *interp,
	char *namespace, Blt_ObjCmdSpec *specPtr));
#if (TCL_VERSION_NUMBER < _VERSION(8,1,0))
extern char *Tcl_GetString _ANSI_ARGS_((Tcl_Obj *objPtr));
extern int Tcl_EvalObjv _ANSI_ARGS_((Tcl_Interp *interp, int objc, 
	Tcl_Obj **objv, int flags));
#endif /* TCL_VERSION_NUMBER < 8.2.0 */
#endif /* TCL_VERSION_NUMBER >= 8.0.0 */

#if ((TK_VERSION_NUMBER >= _VERSION(8,0,0)) && \
     (TK_VERSION_NUMBER < _VERSION(8,1,0)))
EXTERN int Tk_GetAnchorFromObj _ANSI_ARGS_((Tcl_Interp *interp, 
	Tcl_Obj *objPtr, Tk_Anchor *anchorPtr));
EXTERN int Tk_GetJustifyFromObj _ANSI_ARGS_((Tcl_Interp *interp,
	Tcl_Obj *objPtr, Tk_Justify *justifyPtr));
EXTERN int Tk_GetReliefFromObj _ANSI_ARGS_((Tcl_Interp *interp, 
	Tcl_Obj *objPtr, int *reliefPtr));
EXTERN int Tk_GetMMFromObj _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	Tcl_Obj *objPtr, double *doublePtr));
EXTERN int Tk_GetPixelsFromObj _ANSI_ARGS_((Tcl_Interp *interp, 
	Tk_Window tkwin, Tcl_Obj *objPtr, int *intPtr));
EXTERN Tk_3DBorder Tk_Alloc3DBorderFromObj _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, Tcl_Obj *objPtr));
EXTERN Pixmap Tk_AllocBitmapFromObj _ANSI_ARGS_((Tcl_Interp *interp, 
	Tk_Window tkwin, Tcl_Obj *objPtr));
EXTERN Tk_Font Tk_AllocFontFromObj _ANSI_ARGS_((Tcl_Interp *interp, 
	Tk_Window tkwin, Tcl_Obj *objPtr));
EXTERN Tk_Cursor Tk_AllocCursorFromObj _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, Tcl_Obj *objPtr));
EXTERN XColor *Tk_AllocColorFromObj _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, Tcl_Obj *objPtr));
#endif /* 8.0 */

extern int Blt_InitCmds _ANSI_ARGS_((Tcl_Interp *interp, char *namespace,
	Blt_CmdSpec *specPtr, int nCmds));

extern int Blt_NaturalSpline _ANSI_ARGS_((Point2D *origPts, int nOrigPts, 
	Point2D *intpPts, int nIntpPts));

extern int Blt_QuadraticSpline _ANSI_ARGS_((Point2D *origPts, int nOrigPts,
	Point2D *intpPts, int nIntpPts));

extern int Blt_SimplifyLine _ANSI_ARGS_((Point2D *origPts, int low, int high,
	 double tolerance, int indices[]));

extern int Blt_NaturalParametricSpline _ANSI_ARGS_((Point2D *origPts, 
	int nOrigPts, Extents2D *extsPtr, int isClosed, Point2D *intpPts, 
	int nIntpPts));

extern int Blt_CatromParametricSpline _ANSI_ARGS_((Point2D *origPts, 
	int nOrigPts, Point2D *intpPts, int nIntpPts));

extern int Blt_StringToFlag _ANSI_ARGS_((ClientData clientData,
	Tcl_Interp *interp, Tk_Window tkwin, char *string, char *widgRec,
	int flags));
extern char *Blt_FlagToString _ANSI_ARGS_((ClientData clientData,
	Tk_Window tkwin, char *string, int offset, Tcl_FreeProc **freeProc));

extern void Blt_InitHexTable _ANSI_ARGS_((char *table));

extern GC Blt_GetPrivateGC _ANSI_ARGS_((Tk_Window tkwin, unsigned long gcMask,
	XGCValues *valuePtr));

extern GC Blt_GetPrivateGCFromDrawable _ANSI_ARGS_((Display *display,
	Drawable drawable, unsigned long gcMask, XGCValues *valuePtr));

extern void Blt_FreePrivateGC _ANSI_ARGS_((Display *display, GC gc));

extern Tk_Window Blt_FindChild _ANSI_ARGS_((Tk_Window parent, char *name));

extern Tk_Window Blt_FirstChild _ANSI_ARGS_((Tk_Window parent));

extern Tk_Window Blt_NextChild _ANSI_ARGS_((Tk_Window tkwin));

extern void Blt_RelinkWindow _ANSI_ARGS_((Tk_Window tkwin, Tk_Window newParent,
	int x, int y));

extern Tk_Window Blt_Toplevel _ANSI_ARGS_((Tk_Window tkwin));

extern int Blt_GetPixels _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *string, int check, int *valuePtr));
extern int Blt_GetPosition _ANSI_ARGS_((Tcl_Interp *interp, char *string,
	int *indexPtr));
extern int Blt_GetCount _ANSI_ARGS_((Tcl_Interp *interp, char *string,
	int check, int *valuePtr));

extern char *Blt_NameOfFill _ANSI_ARGS_((int fill));

extern int Blt_GetXY _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *string, int *x, int *y));

extern Point2D Blt_GetProjection _ANSI_ARGS_((int x, int y, Point2D *p, 
	Point2D *q));

extern Tk_OptionParseProc Blt_StringToEnum;
extern Tk_OptionPrintProc Blt_EnumToString;

extern int Blt_ConfigModified _ANSI_ARGS_(TCL_VARARGS(Tk_ConfigSpec *, specs));

extern void Blt_DStringAppendElements _ANSI_ARGS_(TCL_VARARGS(Tcl_DString *, args));

extern void Blt_MakeTransparentWindowExist _ANSI_ARGS_((Tk_Window tkwin,
	Window parent, int isBusy));

extern Window Blt_GetParent _ANSI_ARGS_((Display *display, Window tkwin));

extern void Blt_GetBoundingBox _ANSI_ARGS_((int width, int height,
	double theta, int *widthPtr, int *heightPtr, Point2D *points));

extern void Blt_InitEpsCanvasItem _ANSI_ARGS_((Tcl_Interp *interp));

extern Pixmap Blt_RotateBitmap _ANSI_ARGS_((Tk_Window tkwin, Pixmap bitmap,
	int width, int height, double theta, int *widthPtr, int *heightPtr));

extern Pixmap Blt_ScaleBitmap _ANSI_ARGS_((Tk_Window tkwin, Pixmap srcBitmap,
	int srcWidth, int srcHeight, int scaledWidth, int scaledHeight));

extern Pixmap Blt_ScaleBitmapRegion _ANSI_ARGS_((Tk_Window tkwin,
	Pixmap srcBitmap, int srcWidth, int srcHeight,
	int scaledWidth, int scaledHeight, Region2D *regionPtr));

extern void Blt_TranslateAnchor _ANSI_ARGS_((int x, int y, int width,
	int height, Tk_Anchor anchor, int *transXPtr, int *transYPtr));

extern Point2D Blt_TranslatePoint _ANSI_ARGS_((Point2D *pointPtr, int width,
	int height, Tk_Anchor anchor));

extern int Blt_ConfigureWidgetComponent _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, char *name, char *class, Tk_ConfigSpec *specs,
	int argc, char **argv, char *widgRec, int flags));

extern void Blt_HSV _ANSI_ARGS_((XColor *colorPtr, double *huePtr,
	double *valPtr, double *satPtr));

extern void Blt_RGB _ANSI_ARGS_((double hue, double sat, double val,
	XColor *colorPtr));

extern int Blt_ParseFlag _ANSI_ARGS_((ClientData, Tcl_Interp *, Tk_Window,
	char *, char *, int));
extern char *Blt_FlagPrint _ANSI_ARGS_((ClientData, Tk_Window, char *, int,
	Tcl_FreeProc **));

extern Window Blt_GetRealWindowId _ANSI_ARGS_((Tk_Window tkwin));
extern int Blt_RootX _ANSI_ARGS_((Tk_Window tkwin));
extern int Blt_RootY _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_MapTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_UnmapTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_RaiseTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_ResizeTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin, 
	int width, int height));
extern ClientData Blt_GetWindowInstanceData _ANSI_ARGS_((Tk_Window tkwin));

extern void Blt_SetWindowInstanceData _ANSI_ARGS_((Tk_Window tkwin,
	ClientData instanceData));

extern void Blt_DeleteWindowInstanceData _ANSI_ARGS_((Tk_Window tkwin));

extern int Blt_AdjustViewport _ANSI_ARGS_((int offset, int worldSize,
	int windowSize, int scrollUnits, int scrollMode));

extern int Blt_GetScrollInfo _ANSI_ARGS_((Tcl_Interp *interp, int argc,
	char **argv, int *offsetPtr, int worldSize, int windowSize,
	int scrollUnits, int scrollMode));

#if (TK_MAJOR_VERSION >= 8) 
extern int Blt_GetScrollInfoFromObj _ANSI_ARGS_((Tcl_Interp *interp, int objc,
	Tcl_Obj *CONST *objv, int *offsetPtr, int worldSize, int windowSize,
	int scrollUnits, int scrollMode));
#endif

extern void Blt_UpdateScrollbar _ANSI_ARGS_((Tcl_Interp *interp,
	char *scrollCmd, double firstFract, double lastFract));

extern int Blt_ReparentWindow _ANSI_ARGS_((Display *display, Window window,
	Window newParent, int x, int y));

#if defined(HAVE_JPEGLIB_H) || defined(HAVE_IJL_H)
#define HAVE_JPEG 1
extern int Blt_JPEGToPhoto _ANSI_ARGS_((Tcl_Interp *interp, char *fileName,
	Tk_PhotoHandle photo));
#endif /* HAVE_JPEGLIB_H || HAVE_IJL_H */

#define Blt_SetBooleanResult(i, b) \
	Tcl_SetResult((i), (b) ? "1" : "0", TCL_STATIC)

/*
 * Define this if you want to be able to tile to the main window "."
 * This will cause a conflict with Tk if you try to compile and link
 * statically.
 */
#undef TILE_MAINWINDOW

#ifdef WIN32
#if (TCL_MAJOR_VERSION == 8)  && (TCL_MINOR_VERSION == 0)
#else
#define NO_DDE		1
#endif
#else 
#define NO_DDE		1
#define NO_PRINTER	1
#endif /* WIN32 */

#if (TCL_MAJOR_VERSION == 7) 
#define NO_TREE		1
#define NO_ARRAY	1
#define NO_TREEVIEW	1
#endif

/* #define NO_TED */

#ifndef NO_BEEP
extern Tcl_AppInitProc Blt_BeepInit;
#endif
#ifndef NO_BGEXEC
extern Tcl_AppInitProc Blt_BgexecInit;
#endif
#ifndef NO_BITMAP
extern Tcl_AppInitProc Blt_BitmapInit;
#endif
#ifndef NO_BUSY
extern Tcl_AppInitProc Blt_BusyInit;
#endif
#ifndef NO_CONTAINER
extern Tcl_AppInitProc Blt_ContainerInit;
#endif
#ifndef NO_CUTBUFFER
extern Tcl_AppInitProc Blt_CutbufferInit;
#endif
#ifndef NO_DEBUG
extern Tcl_AppInitProc Blt_DebugInit;
#endif
#ifndef NO_DRAGDROP
extern Tcl_AppInitProc Blt_DragDropInit;
#endif
#ifndef NO_DND
extern Tcl_AppInitProc Blt_DndInit;
#endif
#ifndef NO_GRAPH
extern Tcl_AppInitProc Blt_GraphInit;
#endif
#ifndef NO_HIERBOX
extern Tcl_AppInitProc Blt_HierboxInit;
#endif
#ifndef NO_HIERTABLE
extern Tcl_AppInitProc Blt_HiertableInit;
#endif
#ifndef NO_HTEXT
extern Tcl_AppInitProc Blt_HtextInit;
#endif
#ifdef WIN32
#ifndef NO_PRINTER
extern Tcl_AppInitProc Blt_PrinterInit;
#endif
#endif
#ifndef NO_TABLE
extern Tcl_AppInitProc Blt_TableInit;
#endif
#ifndef NO_VECTOR
extern Tcl_AppInitProc Blt_VectorInit;
#endif
#ifndef NO_WINOP
extern Tcl_AppInitProc Blt_WinopInit;
#endif
#ifndef NO_WATCH
extern Tcl_AppInitProc Blt_WatchInit;
#endif
#ifndef NO_SPLINE
extern Tcl_AppInitProc Blt_SplineInit;
#endif
#ifndef NO_TABSET
extern Tcl_AppInitProc Blt_TabsetInit;
#endif
#ifndef NO_TABNOTEBOOK
extern Tcl_AppInitProc Blt_TabnotebookInit;
#endif
#ifndef NO_TREE
extern Tcl_AppInitProc Blt_TreeInit;
#endif
#ifndef NO_TREEVIEW
extern Tcl_AppInitProc Blt_TreeViewInit;
#endif
#ifndef NO_TILEFRAME
extern Tcl_AppInitProc Blt_FrameInit;
#endif
#ifndef NO_TILEBUTTON
extern Tcl_AppInitProc Blt_ButtonInit;
#endif
#ifndef NO_TILESCROLLBAR
extern Tcl_AppInitProc Blt_ScrollbarInit;
#endif

#if (BLT_MAJOR_VERSION == 3)
#ifndef NO_MOUNTAIN
extern Tcl_AppInitProc Blt_MountainInit;
#endif
#endif
#ifndef NO_TED
extern Tcl_AppInitProc Blt_TedInit;
#endif

#ifndef NO_DDE
extern Tcl_AppInitProc Blt_DdeInit;
#endif

typedef void *(Blt_MallocProc) _ANSI_ARGS_((size_t size));
typedef void *(Blt_CallocProc) _ANSI_ARGS_((int nElem, size_t size));
typedef void *(Blt_ReallocProc) _ANSI_ARGS_((void *ptr, size_t size));
typedef void (Blt_FreeProc) _ANSI_ARGS_((void *ptr));

EXTERN Blt_MallocProc *Blt_MallocProcPtr;
EXTERN Blt_FreeProc *Blt_FreeProcPtr;

#define Blt_Malloc(size)	(*Blt_MallocProcPtr)(size)
#define Blt_Free		(*Blt_FreeProcPtr)

EXTERN char *Blt_Strdup _ANSI_ARGS_((CONST char *ptr));
EXTERN void *Blt_Calloc _ANSI_ARGS_((unsigned int nElem, size_t size));

#ifdef WIN32
#ifdef CHECK_UNICODE_CALLS

#define _UNICODE
#define UNICODE

#define __TCHAR_DEFINED
typedef float *_TCHAR;

#define _TCHAR_DEFINED
typedef float *TCHAR;

#endif /* CHECK_UNICODE_CALLS */

/* DOS Encapsulated PostScript File Header */
#pragma pack(2)
typedef struct {
    BYTE magic[4];		/* Magic number for a DOS EPS file
				 * C5,D0,D3,C6 */
    DWORD psStart;		/* Offset of PostScript section. */
    DWORD psLength;		/* Length of the PostScript section. */
    DWORD wmfStart;		/* Offset of Windows Meta File section. */
    DWORD wmfLength;		/* Length of Meta file section. */
    DWORD tiffStart;		/* Offset of TIFF section. */
    DWORD tiffLength;		/* Length of TIFF section. */
    WORD checksum;		/* Checksum of header. If FFFF, ignore. */
} DOSEPSHEADER;
#pragma pack()

/* Aldus Portable Metafile Header */
#pragma pack(2)
typedef struct {
    DWORD key;			/* Type of metafile */
    WORD hmf;			/* Unused. Must be NULL. */
    SMALL_RECT bbox;		/* Bounding rectangle */
    WORD inch;			/* Units per inch. */
    DWORD reserved;		/* Unused. */
    WORD checksum;		/* XOR of previous fields (10 32-bit words). */
} APMHEADER;
#pragma pack()

extern double hypot(double x, double y);
extern int Blt_AsyncRead(int fd, char *buffer, unsigned int size);
extern int Blt_AsyncWrite(int fd, char *buffer, unsigned int size);
extern void Blt_CreateFileHandler(int fd, int flags, Tcl_FileProc * proc,
    ClientData clientData);
extern void Blt_DeleteFileHandler(int fd);
extern int Blt_GetPlatformId(void);
extern char *Blt_LastError(void);
extern int Blt_GetOpenPrinter(Tcl_Interp *interp, const char *id,
    Drawable *drawablePtr);
extern int Blt_OpenPrinterDoc(Tcl_Interp *interp, const char *id);
extern int Blt_ClosePrinterDoc(Tcl_Interp *interp, const char *id);
extern void Blt_GetPrinterScale(HDC dc, double *xRatio, double *yRatio);

#undef EXPORT
#define EXPORT __declspec(dllexport)

#ifdef _MSC_VER
#define strncasecmp(s1,s2,n)	_strnicmp(s1,s2,n)
#define strcasecmp(s1,s2)	_stricmp(s1,s2)
#define finite(x)		_finite(x)

#else
/*
 * Add missing definitions from windgi.h, windowsx.h, and winspool.h
 */
#include <winspool.h>
#include <windowsx.h>
#include <wingdi.h>
#include <missing.h> 
#endif /* _MSC_VER */

#define XCopyArea		Blt_EmulateXCopyArea
#define XCopyPlane		Blt_EmulateXCopyPlane
#define XDrawArcs		Blt_EmulateXDrawArcs
#define XDrawLine		Blt_EmulateXDrawLine
#define XDrawLines		Blt_EmulateXDrawLines
#define XDrawPoints		Blt_EmulateXDrawPoints
#define XDrawRectangle		Blt_EmulateXDrawRectangle
#define XDrawRectangles		Blt_EmulateXDrawRectangles
#define XDrawSegments		Blt_EmulateXDrawSegments
#define XDrawString		Blt_EmulateXDrawString
#define XFillArcs		Blt_EmulateXFillArcs
#define XFillPolygon		Blt_EmulateXFillPolygon
#define XFillRectangle		Blt_EmulateXFillRectangle
#define XFillRectangles		Blt_EmulateXFillRectangles
#define XFree			Blt_EmulateXFree
#define XGetWindowAttributes	Blt_EmulateXGetWindowAttributes
#define XLowerWindow		Blt_EmulateXLowerWindow
#define XMaxRequestSize		Blt_EmulateXMaxRequestSize
#define XRaiseWindow		Blt_EmulateXRaiseWindow
#define XReparentWindow		Blt_EmulateXReparentWindow
#define XSetDashes		Blt_EmulateXSetDashes
#define XUnmapWindow		Blt_EmulateXUnmapWindow
#define XWarpPointer		Blt_EmulateXWarpPointer

EXTERN GC Blt_EmulateXCreateGC(Display *display, Drawable drawable,
    unsigned long mask, XGCValues *valuesPtr);
EXTERN void Blt_EmulateXCopyArea(Display *display, Drawable src, Drawable dest,
    GC gc, int src_x, int src_y, unsigned int width, unsigned int height,
    int dest_x, int dest_y);
EXTERN void Blt_EmulateXCopyPlane(Display *display, Drawable src,
    Drawable dest, GC gc, int src_x, int src_y, unsigned int width,
    unsigned int height, int dest_x, int dest_y, unsigned long plane);
EXTERN void Blt_EmulateXDrawArcs(Display *display, Drawable drawable, GC gc,
    XArc *arcArr, int nArcs);
EXTERN void Blt_EmulateXDrawLine(Display *display, Drawable drawable, GC gc,
    int x1, int y1, int x2, int y2);
EXTERN void Blt_EmulateXDrawLines(Display *display, Drawable drawable, GC gc,
    XPoint *pointArr, int nPoints, int mode);
EXTERN void Blt_EmulateXDrawPoints(Display *display, Drawable drawable, GC gc,
    XPoint *pointArr, int nPoints, int mode);
EXTERN void Blt_EmulateXDrawRectangle(Display *display, Drawable drawable,
    GC gc, int x, int y, unsigned int width, unsigned int height);
EXTERN void Blt_EmulateXDrawRectangles(Display *display, Drawable drawable,
    GC gc, XRectangle *rectArr, int nRects);
EXTERN void Blt_EmulateXDrawSegments(Display *display, Drawable drawable,
    GC gc, XSegment *segArr, int nSegments);
EXTERN void Blt_EmulateXDrawSegments(Display *display, Drawable drawable,
    GC gc, XSegment *segArr, int nSegments);
EXTERN void Blt_EmulateXDrawString(Display *display, Drawable drawable, GC gc,
    int x, int y, _Xconst char *string, int length);
EXTERN void Blt_EmulateXFillArcs(Display *display, Drawable drawable, GC gc,
    XArc *arcArr, int nArcs);
EXTERN void Blt_EmulateXFillPolygon(Display *display, Drawable drawable,
    GC gc, XPoint *points, int nPoints,  int shape, int mode);
EXTERN void Blt_EmulateXFillRectangle(Display *display, Drawable drawable,
    GC gc, int x, int y, unsigned int width, unsigned int height);
EXTERN void Blt_EmulateXFillRectangles(Display *display, Drawable drawable,
    GC gc, XRectangle *rectArr, int nRects);
EXTERN void Blt_EmulateXFree(void *ptr);
EXTERN Status Blt_EmulateXGetWindowAttributes(Display *display, Window window,
    XWindowAttributes * attrsPtr);
EXTERN void Blt_EmulateXLowerWindow(Display *display, Window window);
EXTERN void Blt_EmulateXMapWindow(Display *display, Window window);
EXTERN long Blt_EmulateXMaxRequestSize(Display *display);
EXTERN void Blt_EmulateXRaiseWindow(Display *display, Window window);
EXTERN void Blt_EmulateXReparentWindow(Display *display, Window window,
    Window parent, int x, int y);
EXTERN void Blt_EmulateXSetDashes(Display *display, GC gc, int dashOffset,
    _Xconst char *dashList, int n);
EXTERN void Blt_EmulateXUnmapWindow(Display *display, Window window);
EXTERN void Blt_EmulateXWarpPointer(Display *display, Window srcWindow,
    Window destWindow, int srcX, int srcY, unsigned int srcWidth,
    unsigned int srcHeight, int destX, int destY);

EXTERN void Blt_DrawPoint2DLine(Display *display, Drawable drawable, GC gc,
    Point2D *screenPts, int nScreenPts);

extern unsigned char *Blt_GetBitmapData _ANSI_ARGS_((Display *display,
	Pixmap bitmap, int width, int height, int *pitchPtr));

extern HFONT Blt_CreateRotatedFont _ANSI_ARGS_((Tk_Window tkwin,
	unsigned long font, double theta));

extern HPALETTE Blt_GetSystemPalette _ANSI_ARGS_((void));

extern HPEN Blt_GCToPen _ANSI_ARGS_((HDC dc, GC gc));

#endif /* WIN32 */

#endif /*_BLT_INT_H*/
