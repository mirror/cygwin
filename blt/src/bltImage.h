/*
 * bltImage.h --
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

#include <X11/Xutil.h>
#ifndef WIN32
#include <X11/Xproto.h>
#endif

#ifndef _BLT_IMAGE_H
#define _BLT_IMAGE_H

#define DIV255(i) ((((i) + 1) + (((i) + 1) >> 8) ) >> 8)

#define GAMMA	(1.0)

/*
 *----------------------------------------------------------------------
 *
 * Pix32 --
 *
 *      A union representing either a pixel as a RGB triplet or a
 *	single word value.
 *
 *----------------------------------------------------------------------
 */
typedef union {
    unsigned int value;		/* Lookup table address */
    struct RGBA {
	unsigned char red;	/* Red intensity 0..255 */
	unsigned char green;	/* Green intensity 0.255 */
	unsigned char blue;	/* Blue intensity 0..255 */
	unsigned char alpha;	/* Alpha-channel for compositing. 0..255 */
    } rgba;
    unsigned char channel[4];
} Pix32;

#define Red	rgba.red
#define Blue	rgba.blue
#define Green	rgba.green
#define Alpha	rgba.alpha


typedef struct {
    XColor exact, best;
    double error;
    unsigned int freq;
    int allocated;
    int index;
} ColorInfo;


/*
 *----------------------------------------------------------------------
 *
 * ColorTable --
 *
 *	For colormap-ed visuals, this structure contains color lookup
 *	information needed to translate RGB triplets to pixel indices.
 *
 *	This structure isn't needed for TrueColor or Monochrome visuals.
 *
 *	DirectColor:
 *		Pixel values for each color channel
 *	StaticColor, PsuedoColor, StaticGray, and GrayScale:
 *		Red represents the 8-bit color. Green and Blue pixel
 *		values are unused.
 *
 *----------------------------------------------------------------------
 */
typedef struct ColorTableStruct {
    double outputGamma;		/* Gamma correction value */
    Display *display;		/* Display of colortable. Used to free
				 * colors allocated. */
    XVisualInfo visualInfo;	/* Visual information for window displaying
				 * the image. */
    Colormap colorMap;		/* Colormap used.  This may be the default
				 * colormap, or an allocated private map. */
    int flags;
    unsigned int red[256], green[256], blue[256];

    /* Array of allocated pixels in colormap */
    ColorInfo colorInfo[256];
    ColorInfo *sortedColors[256];

    int nUsedColors, nFreeColors;
    int nPixels;		/* Number of colors in the quantized image */
    unsigned long int pixelValues[256];

    unsigned int *lut;		/* Color lookup table. Used to collect
				 * frequencies of colors and later
				 * colormap indices */
} *ColorTable;

#define PRIVATE_COLORMAP	1
#define RGBIndex(r,g,b) (((r)<<10) + ((r)<<6) + (r) + ((g) << 5) + (g) + (b))

/*
 *----------------------------------------------------------------------
 *
 * Blt_Colorimage --
 *
 *      The structure below represents a color image.  Each pixel
 *	occupies a 32-bit word of memory: one byte for each of the
 *	red, green, and blue color intensities, and another for
 *	alpha-channel image compositing (e.g. transparency).
 *
 *----------------------------------------------------------------------
 */
typedef struct Colorimage {
    int width, height;		/* Dimensions of the image */
    Pix32 *bits;		/* Array of pixels representing the image. */
} *Blt_Colorimage;

/*
 * Blt_Colorimage is supposed to be an opaque type.
 * Use the macros below to access its members.
 */
#define Blt_ColorimageHeight(c)	((c)->height)
#define Blt_ColorimageWidth(c)	((c)->width)
#define Blt_ColorimageBits(c)	((c)->bits)
#define Blt_ColorimagePixel(c, x, y) ((c)->bits + ((c)->width * (y)) + (x))

/*
 *----------------------------------------------------------------------
 *
 * ResampleFilterProc --
 *
 *      A function implementing a 1-D filter.
 *
 *----------------------------------------------------------------------
 */
typedef double (ResampleFilterProc) _ANSI_ARGS_((double value));

/*
 *----------------------------------------------------------------------
 *
 * ResampleFilter --
 *
 *      Contains information about a 1-D filter (its support and
 *	the procedure implementing the filter).
 *
 *----------------------------------------------------------------------
 */
typedef struct {
    char *name;			/* Name of the filter */
    ResampleFilterProc *proc;	/* 1-D filter procedure. */
    double support;		/* Width of 1-D filter */
} ResampleFilter;

extern ResampleFilter *bltBoxFilterPtr; /* The ubiquitous box filter */


/*
 *----------------------------------------------------------------------
 *
 * Filter2D --
 *
 *      Defines a convolution mask for a 2-D filter.  Used to smooth or
 *	enhance images.
 *
 *----------------------------------------------------------------------
 */
typedef struct {
    double support;		/* Radius of filter */
    double sum, scale;		/* Sum of kernel */
    double *kernel;		/* Array of values (malloc-ed) representing
				 * the discrete 2-D filter. */
} Filter2D;

/* Prototypes of image routines */

extern void Blt_ColorimageToGreyscale _ANSI_ARGS_((Blt_Colorimage image));

extern void Blt_ColorimageToPhoto _ANSI_ARGS_((Blt_Colorimage image,
	Tk_PhotoHandle photo));

extern Pixmap Blt_ColorimageToPixmap _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, Blt_Colorimage image, ColorTable *colorTablePtr));

extern Blt_Colorimage Blt_ConvolveColorimage _ANSI_ARGS_((
	Blt_Colorimage srcImage, Filter2D *filter));

extern Blt_Colorimage Blt_CreateColorimage _ANSI_ARGS_((int width,int height));

extern Blt_Colorimage Blt_DrawableToColorimage _ANSI_ARGS_((Tk_Window tkwin, 
	Drawable drawable, int x, int y, int width, int height, 
	double inputGamma));

extern int Blt_GetResampleFilter _ANSI_ARGS_((Tcl_Interp *interp,
	char *filterName, ResampleFilter **filterPtrPtr));

extern void Blt_FreeColorimage _ANSI_ARGS_((Blt_Colorimage image));

#if HAVE_JPEG
extern Blt_Colorimage Blt_JPEGToColorimage _ANSI_ARGS_((Tcl_Interp *interp,
	char *fileName));
#endif

extern Blt_Colorimage Blt_PhotoToColorimage _ANSI_ARGS_((
	Tk_PhotoHandle photo));

extern Blt_Colorimage Blt_PhotoRegionToColorimage _ANSI_ARGS_((
	Tk_PhotoHandle photo, int x, int y, int width, int height));

extern int Blt_QuantizeColorimage _ANSI_ARGS_((Blt_Colorimage src, 
        Blt_Colorimage dest, int nColors));

extern Blt_Colorimage Blt_ResampleColorimage _ANSI_ARGS_((Blt_Colorimage image,
	int destWidth, int destHeight, ResampleFilter *horzFilterPtr, 
	ResampleFilter *vertFilterPtr));

extern void Blt_ResamplePhoto _ANSI_ARGS_((Tk_PhotoHandle srcPhoto,
	int x, int y, int width, int height, Tk_PhotoHandle destPhoto,
	ResampleFilter *horzFilterPtr, ResampleFilter *vertFilterPtr));

extern Blt_Colorimage Blt_ResizeColorimage _ANSI_ARGS_((Blt_Colorimage image,
	int x, int y, int width, int height, int destWidth, int destHeight));

extern Blt_Colorimage Blt_RotateColorimage _ANSI_ARGS_((Blt_Colorimage image,
	double theta));

extern void Blt_ResizePhoto _ANSI_ARGS_((Tk_PhotoHandle srcPhoto, int x, int y,
	int width, int height, Tk_PhotoHandle destPhoto));

extern int Blt_SnapPhoto _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	Drawable drawable, int x, int y, int width, int height, int destWidth,
	int destHeight, char *photoName, double inputGamma));

extern void Blt_ImageRegion _ANSI_ARGS_((Blt_Colorimage image, 
	Region2D *regionPtr));

extern Region2D *Blt_ColorimageRegion _ANSI_ARGS_((Blt_Colorimage image, 
	Region2D *regionPtr));

extern Region2D *Blt_SetRegion _ANSI_ARGS_((int x, int y, int width, 
	int height, Region2D *regionPtr));

extern ColorTable Blt_CreateColorTable _ANSI_ARGS_((Tk_Window tkwin));

extern ColorTable Blt_DirectColorTable _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, Blt_Colorimage image));

extern ColorTable Blt_PseudoColorTable _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, Blt_Colorimage image));

extern void Blt_FreeColorTable _ANSI_ARGS_((ColorTable colorTable));

/* Missing routines from the Tk photo C API */

extern int Tk_ImageIsDeleted _ANSI_ARGS_((Tk_Image tkImage));
extern Tk_ImageMaster Tk_ImageGetMaster _ANSI_ARGS_((Tk_Image tkImage));
extern Tk_ImageType *Tk_ImageGetType _ANSI_ARGS_((Tk_Image tkImage));
extern Pixmap Tk_ImageGetPhotoPixmap _ANSI_ARGS_((Tk_Image photoImage));
extern GC Tk_ImageGetPhotoGC _ANSI_ARGS_((Tk_Image photoImage));

extern char *Blt_NameOfImage _ANSI_ARGS_((Tk_Image tkImage));
extern Tk_Image Blt_CreateTemporaryImage _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, ClientData clientData));
extern int Blt_DestroyTemporaryImage _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Image tkImage));

extern GC Blt_GetBitmapGC _ANSI_ARGS_((Tk_Window tkwin));
extern Pixmap Blt_PhotoImageMask _ANSI_ARGS_((Tk_Window tkwin, 
	Tk_PhotoImageBlock src));

#endif /*_BLT_IMAGE_H*/
