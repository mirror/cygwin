
/*
 * bltWinImage.c --
 *
 *	This module implements image processing procedures for the BLT
 *	toolkit.
 *
 * Copyright 1997-1998 Lucent Technologies, Inc.
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

#include "bltInt.h"
#include "bltImage.h"
#include "bltHash.h"
#include <X11/Xutil.h>

#define CLAMP(c)	((((c) < 0.0) ? 0.0 : ((c) > 255.0) ? 255.0 : (c)))

enum RightAngles { ROTATE_0, ROTATE_90, ROTATE_180, ROTATE_270 };

/*
 *----------------------------------------------------------------------
 *
 * Blt_ColorimageToPixmap --
 *
 *      Converts a color image into a pixmap.
 *
 *	Right now this only handles TrueColor visuals.
 *
 * Results:
 *      The new pixmap is returned.
 *
 *----------------------------------------------------------------------
 */
Pixmap
Blt_ColorimageToPixmap(
    Tcl_Interp *interp,
    Tk_Window tkwin,
    Blt_Colorimage image,
    ColorTable *colorTablePtr)	/* Points to array of colormap indices */
{
    HDC pixmapDC;
    TkWinDCState state;
    Display *display;
    int width, height, depth;
    Pixmap pixmap;
    register int x, y;
    register Pix32 *srcPtr;
    COLORREF rgb;

    *colorTablePtr = NULL;
    width = Blt_ColorimageWidth(image);
    height = Blt_ColorimageHeight(image);
    display = Tk_Display(tkwin);
    depth = Tk_Depth(tkwin);

    pixmap = Tk_GetPixmap(display, Tk_WindowId(tkwin), width, height, depth);
    pixmapDC = TkWinGetDrawableDC(display, pixmap, &state);

    srcPtr = Blt_ColorimageBits(image);
    for (y = 0; y < height; y++) {
	for (x = 0; x < width; x++) {
	    rgb = PALETTERGB(srcPtr->Red, srcPtr->Green, srcPtr->Blue);
	    SetPixelV(pixmapDC, x, y, rgb);
	    srcPtr++;
	}
    }
    TkWinReleaseDrawableDC(pixmap, pixmapDC, &state);
    return pixmap;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ColorimageToPixmap2 --
 *
 *      Converts a color image into a pixmap.
 *
 *	Right now this only handles TrueColor visuals.
 *
 * Results:
 *      The new pixmap is returned.
 *
 *----------------------------------------------------------------------
 */
Pixmap
Blt_ColorimageToPixmap2(
    Display *display,
    int depth,
    Blt_Colorimage image,
    ColorTable *colorTablePtr)	/* Points to array of colormap indices */
{
    BITMAP bm;
    HBITMAP hBitmap;
    TkWinBitmap *twdPtr;
    int width, height;
    register Pix32 *srcPtr;
    register int x, y;
    register unsigned char *destPtr;
    unsigned char *bits;

    *colorTablePtr = NULL;
    width = Blt_ColorimageWidth(image);
    height = Blt_ColorimageHeight(image);

    /* 
     * Copy the color image RGB data into the DIB. The DIB scanlines
     * are stored bottom-to-top and the order of the RGB color
     * components is BGR. Who says Win32 GDI programming isn't
     * backwards?  
     */
    bits = Blt_Malloc(width * height * sizeof(unsigned char));
    assert(bits);
    srcPtr = Blt_ColorimageBits(image);    
    for (y = height - 1; y >= 0; y--) {
	destPtr = bits + (y * width);
	for (x = 0; x < width; x++) {
	    *destPtr++ = srcPtr->Blue;
	    *destPtr++ = srcPtr->Green;
	    *destPtr++ = srcPtr->Red;
	    *destPtr++ = (unsigned char)-1;
	    srcPtr++;
	}
    }
    bm.bmType = 0;
    bm.bmWidth = width;
    bm.bmHeight = height;
    bm.bmWidthBytes = width;
    bm.bmPlanes = 1;
    bm.bmBitsPixel = 32;
    bm.bmBits = bits;
    hBitmap = CreateBitmapIndirect(&bm);

    /* Create a windows version of a drawable. */
    twdPtr = Blt_Malloc(sizeof(TkWinBitmap));
    assert(twdPtr);
    twdPtr->type = TWD_BITMAP;
    twdPtr->handle = hBitmap;
    twdPtr->depth = depth;
    twdPtr->colormap = DefaultColormap(display, DefaultScreen(display));
    return (Pixmap)twdPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_DrawableToColorimage --
 *
 *      Takes a snapshot of an X drawable (pixmap or window) and
 *	converts it to a color image.
 *
 * Results:
 *      Returns a color image of the drawable.  If an error occurred,
 *	NULL is returned.
 *
 *----------------------------------------------------------------------
 */
Blt_Colorimage
Blt_DrawableToColorimage(
    Tk_Window tkwin,
    Drawable drawable,
    int x, int y,
    int width, int height,	/* Dimension of the drawable. */
    double inputGamma)
{
    void *data;
    BITMAPINFO info;
    DIBSECTION ds;
    HBITMAP hBitmap, oldBitmap;
    HPALETTE hPalette;
    HDC memDC;
    unsigned char *srcArr;
    register unsigned char *srcPtr;
    HDC hDC;
    TkWinDCState state;
    register Pix32 *destPtr;
    Blt_Colorimage image;
    unsigned char lut[256];

    hDC = TkWinGetDrawableDC(Tk_Display(tkwin), drawable, &state);

    /* Create the intermediate drawing surface at window resolution. */
    ZeroMemory(&info, sizeof(info));
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    hBitmap = CreateDIBSection(hDC, &info, DIB_RGB_COLORS, &data, NULL, 0);
    memDC = CreateCompatibleDC(hDC);
    oldBitmap = SelectBitmap(memDC, hBitmap);

    hPalette = Blt_GetSystemPalette();
    if (hPalette != NULL) {
	SelectPalette(hDC, hPalette, FALSE);
	RealizePalette(hDC);
	SelectPalette(memDC, hPalette, FALSE);
	RealizePalette(memDC);
    }
    image = NULL;
    /* Copy the window contents to the memory surface. */
    if (!BitBlt(memDC, 0, 0, width, height, hDC, x, y, SRCCOPY)) {
#ifdef notdef
	PurifyPrintf("can't blit: %s\n", Blt_LastError());
#endif
	goto done;
    }
    if (GetObject(hBitmap, sizeof(DIBSECTION), &ds) == 0) {
#ifdef notdef
	PurifyPrintf("can't get object: %s\n", Blt_LastError());
#endif
	goto done;
    }
    srcArr = (unsigned char *)ds.dsBm.bmBits;
    image = Blt_CreateColorimage(width, height);
    destPtr = Blt_ColorimageBits(image);

    {
	register int i;
	double value;

	for (i = 0; i < 256; i++) {
	    value = pow(i / 255.0, inputGamma) * 255.0 + 0.5;
	    lut[i] = (unsigned char)CLAMP(value);
	}
    }

    /* 
     * Copy the DIB RGB data into the color image. The DIB scanlines
     * are stored bottom-to-top and the order of the RGB color
     * components is BGR. Who says Win32 GDI programming isn't
     * backwards?  
     */

    for (y = height - 1; y >= 0; y--) {
	srcPtr = srcArr + (y * ds.dsBm.bmWidthBytes);
	for (x = 0; x < width; x++) {
	    destPtr->Blue = lut[*srcPtr++];
	    destPtr->Green = lut[*srcPtr++];
	    destPtr->Red = lut[*srcPtr++];
	    destPtr->Alpha = (unsigned char)-1;
	    destPtr++;
	    srcPtr++;
	}
    }
  done:
    DeleteBitmap(SelectBitmap(memDC, oldBitmap));
    DeleteDC(memDC);
    TkWinReleaseDrawableDC(drawable, hDC, &state);
    if (hPalette != NULL) {
	DeletePalette(hPalette);
    }
    return image;
}


Pixmap
Blt_PhotoImageMask(
    Tk_Window tkwin,
    Tk_PhotoImageBlock src)
{
    TkWinBitmap *twdPtr;
    int bytesPerRow;
    int offset, count;
    register int x, y;
    unsigned char *bits;
    unsigned char *srcPtr;

    bytesPerRow = ((src.width + 31) & ~31) / 8;
    bits = Blt_Calloc(src.height, bytesPerRow);

#define SetBit(x, y) \
    bits[(bytesPerRow * y) + (x / 8)] |= (0x80 >> (x % 8))

    offset = count = 0;
    for (y = 0; y < src.height; y++) {
	srcPtr = src.pixelPtr + offset;
	for (x = 0; x < src.width; x++) {
	    if (srcPtr[src.offset[3]] == 0x00) {
		SetBit(x, y);
		count++;
	    }
	    srcPtr += src.pixelSize;
	}
	offset += src.pitch;
    }
    if (count > 0) {
	HBITMAP hBitmap;
	BITMAP bm;

	bm.bmType = 0;
	bm.bmWidth = src.width;
	bm.bmHeight = src.height;
	bm.bmWidthBytes = bytesPerRow;
	bm.bmPlanes = 1;
	bm.bmBitsPixel = 1;
	bm.bmBits = bits;
	hBitmap = CreateBitmapIndirect(&bm);

	twdPtr = Blt_Malloc(sizeof(TkWinBitmap));
	assert(twdPtr);
	twdPtr->type = TWD_BITMAP;
	twdPtr->handle = hBitmap;
	twdPtr->depth = 1;
	if (Tk_WindowId(tkwin) == None) {
	    twdPtr->colormap = DefaultColormap(Tk_Display(tkwin), 
			 DefaultScreen(Tk_Display(tkwin)));
	} else {
	    twdPtr->colormap = Tk_Colormap(tkwin);
	}
    } else {
	twdPtr = NULL;
    }
    if (bits != NULL) {
	Blt_Free(bits);
    }
    return (Pixmap)twdPtr;
}

Pixmap
Blt_ColorimageMask(
    Tk_Window tkwin,
    Blt_Colorimage image)
{
    TkWinBitmap *twdPtr;
    int bytesPerRow;
    int count;
    register int x, y;
    unsigned char *bits;
    Pix32 *srcPtr;
    int width, height;

    width = Blt_ColorimageWidth(image);
    height = Blt_ColorimageHeight(image);
    bytesPerRow = ((width + 31) & ~31) / 8;
    bits = Blt_Calloc(height, bytesPerRow);

    count = 0;
    srcPtr = Blt_ColorimageBits(image);
    for (y = height - 1; y >= 0; y--) {
	for (x = 0; x < width; x++) {
	    if (srcPtr->Alpha == 0x00) {
		SetBit(x, y);
		count++;
	    }
	    srcPtr++;
	}
    }
    if (count > 0) {
	HBITMAP hBitmap;
	BITMAP bm;

	bm.bmType = 0;
	bm.bmWidth = Blt_ColorimageWidth(image);
	bm.bmHeight = Blt_ColorimageHeight(image);
	bm.bmWidthBytes = bytesPerRow;
	bm.bmPlanes = 1;
	bm.bmBitsPixel = 1;
	bm.bmBits = bits;
	hBitmap = CreateBitmapIndirect(&bm);

	twdPtr = Blt_Malloc(sizeof(TkWinBitmap));
	assert(twdPtr);
	twdPtr->type = TWD_BITMAP;
	twdPtr->handle = hBitmap;
	twdPtr->depth = 1;
	if (Tk_WindowId(tkwin) == None) {
	    twdPtr->colormap = DefaultColormap(Tk_Display(tkwin), 
			 DefaultScreen(Tk_Display(tkwin)));
	} else {
	    twdPtr->colormap = Tk_Colormap(tkwin);
	}
    } else {
	twdPtr = NULL;
    }
    if (bits != NULL) {
	Blt_Free(bits);
    }
    return (Pixmap)twdPtr;
}

#ifdef notdef
/*
 *----------------------------------------------------------------------
 *
 * Blt_BlendColorimage --
 *
 *      Takes a snapshot of an X drawable (pixmap or window) and
 *	converts it to a color image.
 *
 * Results:
 *      Returns a color image of the drawable.  If an error occurred,
 *	NULL is returned.
 *
 *----------------------------------------------------------------------
 */
void
Blt_BlendColorimage(
    Tk_Window tkwin,
    Drawable drawable,
    int width, int height,	/* Dimension of the drawable. */
    Region2D *regionPtr)	/* Region to be snapped. */
{
    void *data;
    BITMAPINFO info;
    DIBSECTION ds;
    HBITMAP hBitmap, oldBitmap;
    HPALETTE hPalette;
    HDC memDC;
    unsigned char *srcArr;
    register unsigned char *srcPtr;
    HDC hDC;
    TkWinDCState state;
    register Pix32 *destPtr;
    Blt_Colorimage image;
    register int x, y;

    if (regionPtr == NULL) {
	regionPtr = Blt_SetRegion(0, 0, ColorimageWidth(image), 
		ColorimageHeight(image), &region);
    }
    if (regionPtr->left < 0) {
	regionPtr->left = 0;
    }
    if (regionPtr->right >= destWidth) {
	regionPtr->right = destWidth - 1;
    }
    if (regionPtr->top < 0) {
	regionPtr->top = 0;
    }
    if (regionPtr->bottom >= destHeight) {
	regionPtr->bottom = destHeight - 1;
    }
    width = RegionWidth(regionPtr);
    height = RegionHeight(regionPtr);

    hDC = TkWinGetDrawableDC(display, drawable, &state);

    /* Create the intermediate drawing surface at window resolution. */
    ZeroMemory(&info, sizeof(info));
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    hBitmap = CreateDIBSection(hDC, &info, DIB_RGB_COLORS, &data, NULL, 0);
    memDC = CreateCompatibleDC(hDC);
    oldBitmap = SelectBitmap(memDC, hBitmap);

    hPalette = Blt_GetSystemPalette();
    if (hPalette != NULL) {
	SelectPalette(hDC, hPalette, FALSE);
	RealizePalette(hDC);
	SelectPalette(memDC, hPalette, FALSE);
	RealizePalette(memDC);
    }
    image = NULL;
    /* Copy the window contents to the memory surface. */
    if (!BitBlt(memDC, 0, 0, width, height, hDC, regionPtr->left, 
	regionPtr->top, SRCCOPY)) {
#ifdef notdef
	PurifyPrintf("can't blit: %s\n", Blt_LastError());
#endif
	goto done;
    }
    if (GetObject(hBitmap, sizeof(DIBSECTION), &ds) == 0) {
#ifdef notdef
	PurifyPrintf("can't get object: %s\n", Blt_LastError());
#endif
	goto done;
    }
    srcArr = (unsigned char *)ds.dsBm.bmBits;
    image = Blt_CreateColorimage(width, height);
    destPtr = Blt_ColorimageBits(image);

    /* 
     * Copy the DIB RGB data into the color image. The DIB scanlines
     * are stored bottom-to-top and the order of the RGBA color
     * components is BGRA. Who says Win32 GDI programming isn't
     * backwards?  
     */
    for (y = height - 1; y >= 0; y--) {
	srcPtr = srcArr + (y * ds.dsBm.bmWidthBytes);
	for (x = 0; x < width; x++) {
	    if (destPtr->Alpha > 0) {
		/* Blend colorimage with background. */
		destPtr->Blue = *srcPtr++;
		destPtr->Green = *srcPtr++;
		destPtr->Red = *srcPtr++;
		destPtr->Alpha = (unsigned char)-1;
		srcPtr++;
	    }
	    destPtr++;
	}
    }
  done:
    DeleteBitmap(SelectBitmap(memDC, oldBitmap));
    DeleteDC(memDC);
    TkWinReleaseDrawableDC(drawable, hDC, &state);
    if (hPalette != NULL) {
	DeletePalette(hPalette);
    }
    return image;
}
#endif

#ifdef HAVE_IJL_H

#include <ijl.h>

Blt_Colorimage
Blt_JPEGToColorimage(interp, fileName)
    Tcl_Interp *interp;
    char *fileName;
{
    JPEG_CORE_PROPERTIES jpgProps;
    Blt_Colorimage image;

    ZeroMemory(&jpgProps, sizeof(JPEG_CORE_PROPERTIES));
    if(ijlInit(&jpgProps) != IJL_OK) {
	Tcl_AppendResult(interp, "can't initialize Intel JPEG library",
			 (char *)NULL);
	return NULL;
    }
    jpgProps.JPGFile = fileName;
    if (ijlRead(&jpgProps, IJL_JFILE_READPARAMS) != IJL_OK) {
	Tcl_AppendResult(interp, "can't read JPEG file header from \"",
			 fileName, "\" file.", (char *)NULL);
	goto error;
    }

    // !dudnik: to fix bug case 584680, [OT:287A305B]
    // Set the JPG color space ... this will always be
    // somewhat of an educated guess at best because JPEG
    // is "color blind" (i.e., nothing in the bit stream
    // tells you what color space the data was encoded from).
    // However, in this example we assume that we are
    // reading JFIF files which means that 3 channel images
    // are in the YCbCr color space and 1 channel images are
    // in the Y color space.
    switch(jpgProps.JPGChannels) {
    case 1:
	jpgProps.JPGColor = IJL_G;
	jpgProps.DIBChannels = 4;
	jpgProps.DIBColor = IJL_RGBA_FPX;
	break;
	
    case 3:
	jpgProps.JPGColor = IJL_YCBCR;
	jpgProps.DIBChannels = 4;
	jpgProps.DIBColor = IJL_RGBA_FPX;
	break;

    case 4:
	jpgProps.JPGColor = IJL_YCBCRA_FPX;
	jpgProps.DIBChannels = 4;
	jpgProps.DIBColor = IJL_RGBA_FPX;
	break;

    default:
	/* This catches everything else, but no color twist will be
           performed by the IJL. */
	jpgProps.DIBColor = (IJL_COLOR)IJL_OTHER;
 	jpgProps.JPGColor = (IJL_COLOR)IJL_OTHER;
	jpgProps.DIBChannels = jpgProps.JPGChannels;
	break;
    }

    jpgProps.DIBWidth    = jpgProps.JPGWidth;
    jpgProps.DIBHeight   = jpgProps.JPGHeight;
    jpgProps.DIBPadBytes = IJL_DIB_PAD_BYTES(jpgProps.DIBWidth, 
					     jpgProps.DIBChannels);

    image = Blt_CreateColorimage(jpgProps.JPGWidth, jpgProps.JPGHeight);

    jpgProps.DIBBytes = (BYTE *)Blt_ColorimageBits(image);
    if (ijlRead(&jpgProps, IJL_JFILE_READWHOLEIMAGE) != IJL_OK) {
	Tcl_AppendResult(interp, "can't read image data from \"", fileName,
		 "\"", (char *)NULL);
	goto error;
    }
    if (ijlFree(&jpgProps) != IJL_OK) {
	fprintf(stderr, "can't free Intel(R) JPEG library\n");
    }
    return image;

 error:
    ijlFree(&jpgProps);
    if (image != NULL) {
	Blt_FreeColorimage(image);
    }
    ijlFree(&jpgProps);
    return NULL;
} 

#else 

#ifdef HAVE_JPEGLIB_H

#undef HAVE_STDLIB_H
#undef EXTERN
#ifdef WIN32
#define XMD_H	1
#endif
#include "jpeglib.h"
#include <setjmp.h>

typedef struct {
    struct jpeg_error_mgr pub;	/* "public" fields */
    jmp_buf jmpBuf;
    Tcl_DString dString;
} ReaderHandler;

static void ErrorProc _ANSI_ARGS_((j_common_ptr jpegInfo));
static void MessageProc _ANSI_ARGS_((j_common_ptr jpegInfo));

/*
 * Here's the routine that will replace the standard error_exit method:
 */

static void
ErrorProc(jpgPtr)
    j_common_ptr jpgPtr;
{
    ReaderHandler *handlerPtr = (ReaderHandler *)jpgPtr->err;

    (*handlerPtr->pub.output_message) (jpgPtr);
    longjmp(handlerPtr->jmpBuf, 1);
}

static void
MessageProc(jpgPtr)
    j_common_ptr jpgPtr;
{
    ReaderHandler *handlerPtr = (ReaderHandler *)jpgPtr->err;
    char buffer[JMSG_LENGTH_MAX];

    /* Create the message and append it into the dynamic string. */
    (*handlerPtr->pub.format_message) (jpgPtr, buffer);
    Tcl_DStringAppend(&(handlerPtr->dString), " ", -1);
    Tcl_DStringAppend(&(handlerPtr->dString), buffer, -1);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_JPEGToColorimage --
 *
 *      Reads a JPEG file and converts it into a color image.
 *
 * Results:
 *      The color image is returned.  If an error occured, such
 *	as the designated file could not be opened, NULL is returned.
 *
 *----------------------------------------------------------------------
 */
Blt_Colorimage
Blt_JPEGToColorimage(interp, fileName)
    Tcl_Interp *interp;
    char *fileName;
{
    struct jpeg_decompress_struct jpg;
    Blt_Colorimage image;
    unsigned int imageWidth, imageHeight;
    register Pix32 *destPtr;
    ReaderHandler handler;
    FILE *f;
    JSAMPLE **readBuffer;
    int row_stride;
    register int i;
    register JSAMPLE *bufPtr;

    f = fopen(fileName, "rb");
    if (f == NULL) {
	Tcl_AppendResult(interp, "can't open \"", fileName, "\":",
	    Tcl_PosixError(interp), (char *)NULL);
	return NULL;
    }
    image = NULL;

    /* Step 1: allocate and initialize JPEG decompression object */

    /* We set up the normal JPEG error routines, then override error_exit. */
    jpg.dct_method = JDCT_IFAST;
    jpg.err = jpeg_std_error(&handler.pub);
    handler.pub.error_exit = ErrorProc;
    handler.pub.output_message = MessageProc;

    Tcl_DStringInit(&handler.dString);
    Tcl_DStringAppend(&handler.dString, "error reading \"", -1);
    Tcl_DStringAppend(&handler.dString, fileName, -1);
    Tcl_DStringAppend(&handler.dString, "\": ", -1);

    if (setjmp(handler.jmpBuf)) {
	jpeg_destroy_decompress(&jpg);
	fclose(f);
	Tcl_DStringResult(interp, &(handler.dString));
	return NULL;
    }
    jpeg_create_decompress(&jpg);
    jpeg_stdio_src(&jpg, f);

    jpeg_read_header(&jpg, TRUE);	/* Step 3: read file parameters */

    jpeg_start_decompress(&jpg);	/* Step 5: Start decompressor */
    imageWidth = jpg.output_width;
    imageHeight = jpg.output_height;
    if ((imageWidth < 1) || (imageHeight < 1)) {
	Tcl_AppendResult(interp, "bad JPEG image size", (char *)NULL);
	fclose(f);
	return NULL;
    }
    /* JSAMPLEs per row in output buffer */
    row_stride = imageWidth * jpg.output_components;

    /* Make a one-row-high sample array that will go away when done
     * with image */
    readBuffer = (*jpg.mem->alloc_sarray) ((j_common_ptr)&jpg, JPOOL_IMAGE, 
	row_stride, 1);
    image = Blt_CreateColorimage(imageWidth, imageHeight);
    destPtr = Blt_ColorimageBits(image);

    if (jpg.output_components == 1) {
	while (jpg.output_scanline < imageHeight) {
	    jpeg_read_scanlines(&jpg, readBuffer, 1);
	    bufPtr = readBuffer[0];
	    for (i = 0; i < (int)imageWidth; i++) {
		destPtr->Red = destPtr->Green = destPtr->Blue = *bufPtr++;
		destPtr->Alpha = (unsigned char)-1;
		destPtr++;
	    }
	}
    } else {
	while (jpg.output_scanline < imageHeight) {
	    jpeg_read_scanlines(&jpg, readBuffer, 1);
	    bufPtr = readBuffer[0];
	    for (i = 0; i < (int)imageWidth; i++) {
		destPtr->Red = *bufPtr++;
		destPtr->Green = *bufPtr++;
		destPtr->Blue = *bufPtr++;
		destPtr->Alpha = (unsigned char)-1;
		destPtr++;
	    }
	}
    }
    jpeg_finish_decompress(&jpg);	/* We can ignore the return value
					 * since suspension is not
					 * possible with the stdio data
					 * source.  */
    jpeg_destroy_decompress(&jpg);


    /*  
     * After finish_decompress, we can close the input file.  Here we
     * postpone it until after no more JPEG errors are possible, so as
     * to simplify the setjmp error logic above.  (Actually, I don't
     * think that jpeg_destroy can do an error exit, but why assume
     * anything...)  
     */
    fclose(f);

    /* 
     * At this point you may want to check to see whether any corrupt-data
     * warnings occurred (test whether jerr.pub.num_warnings is nonzero).
     */
    if (handler.pub.num_warnings > 0) {
	Tcl_SetErrorCode(interp, "IMAGE", "JPEG", 
		 Tcl_DStringValue(&(handler.dString)), (char *)NULL);
    } else {
	Tcl_SetErrorCode(interp, "NONE", (char *)NULL);
    }
    /*
     * We're ready to call the Tk_Photo routines. They'll take the RGB
     * array we've processed to build the Tk image of the JPEG.
     */
    Tcl_DStringFree(&(handler.dString));
    return image;
}

#endif /* HAVE_JPEGLIB_H */
#endif /* HAVE_IJL_H */

