/*
 * bltTile.c --
 *
 *	This module manages images for tiled backgrounds for the BLT toolkit.
 *
 * Copyright 1995-1998 Lucent Technologies, Inc.
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
#include "bltChain.h"
#include "bltHash.h"
#include "bltImage.h"
#include <X11/Xutil.h>

#include "bltTile.h"

#define TILE_THREAD_KEY	"BLT Tile Data"
#define TILE_MAGIC ((unsigned int) 0x46170277)

typedef struct {
    Blt_HashTable tileTable;	/* Hash table of tile structures keyed by 
				 * the name of the image. */
    Tcl_Interp *interp;
} TileInterpData;

typedef struct {
    char *name;			/* Name of image used to generate the pixmap.*/
    Display *display;		/* Display where pixmap was created. */
    int flags;			/* See definitions below. */
    Tcl_Interp *interp;
    Blt_HashEntry *hashPtr;	/* Pointer to hash table location */
    Blt_HashTable *tablePtr;

    Pixmap pixmap;		/* Pixmap generated from image. */
    Pixmap mask;		/* Monochrome pixmap used as
				 * transparency mask. */
    GC gc;			/* GC */
    Tk_Image tkImage;		/* Tk image token. */
    Blt_Chain *clients;		/* Chain of clients sharing this tile. */
    int width, height;		
} Server;

#define NOTIFY_PENDING	1	/* If set, indicates that the image
				 * associated with the tile has been
				 * updated or deleted.  The tile pixmap
				 * will be changed and the clients of the
				 * tile will be notified (if they supplied
				 * a TileChangedProc routine. */
typedef struct {
    unsigned int magic;
    Tk_Window tkwin;		/* Client window. */
    int xOrigin, yOrigin;	/* Tiling origin in relation to the
				 * client window. */
    Blt_TileChangedProc *notifyProc; /* If non-NULL, routine to
				 * call to when tile image changes. */
    ClientData clientData;	/* Data to pass to when calling the above
				 * routine. */
    Server *serverPtr;		/* Pointer to actual tile information */
    Blt_ChainLink *linkPtr;	/* Pointer to client entry in the server's
				 * client list.  Used to delete the client */
} Client;

typedef struct {
    Display *display;
    Tk_Uid nameId;
    int depth;
} TileKey;
    
static TileInterpData *GetTileInterpData _ANSI_ARGS_((Tcl_Interp *interp));

#ifdef __STDC__
static Tcl_IdleProc UpdateTile;
static Tk_ImageChangedProc ImageChangedProc;
static Tcl_InterpDeleteProc TileInterpDeleteProc;
#endif

static void DestroyClient _ANSI_ARGS_((Client *clientPtr));
static void DestroyServer _ANSI_ARGS_((Server *serverPtr));


/*
 *----------------------------------------------------------------------
 *
 * RedrawTile --
 *
 *	Generates a pixmap and draws the tile image into it.  Also
 *	a tranparency mask is possibly generated from the image.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
RedrawTile(tkwin, serverPtr)
    Tk_Window tkwin;
    Server *serverPtr;
{
    GC newGC;
    Tk_PhotoHandle photo;
    XGCValues gcValues;
    int width, height;
    unsigned int gcMask;
    
    Tk_SizeOfImage(serverPtr->tkImage, &width, &height);

    Tk_MakeWindowExist(tkwin);
    if ((width != serverPtr->width) || (height != serverPtr->height)) {
	Pixmap pixmap;

	/*
	 * Create the new pixmap *before* destroying the old one.  I don't
	 * why this happens, but if you delete the old pixmap first, the
	 * old pixmap sometimes gets used in the client's GCs.  I suspect
	 * it has something to do with the way Tk reallocates X resource
	 * identifiers.  
	 */
	pixmap = Tk_GetPixmap(Tk_Display(tkwin), Tk_WindowId(tkwin), width, 
			      height, Tk_Depth(tkwin));
	if (serverPtr->pixmap != None) {
	    Tk_FreePixmap(Tk_Display(tkwin), serverPtr->pixmap);
	}
	serverPtr->pixmap = pixmap;
    }
    Tk_RedrawImage(serverPtr->tkImage, 0, 0, width, height, serverPtr->pixmap, 
	0, 0);
    
    gcMask = (GCTile | GCFillStyle);
    gcValues.fill_style = FillTiled;
    gcValues.tile = serverPtr->pixmap;
    newGC = Tk_GetGC(tkwin, gcMask, &gcValues);
    if (serverPtr->gc != NULL) {
	Tk_FreeGC(Tk_Display(tkwin), serverPtr->gc);
    }
    serverPtr->gc = newGC;
    serverPtr->width = width;
    serverPtr->height = height;

    if (serverPtr->mask != None) {
#ifdef WIN32
	Tk_FreePixmap(Tk_Display(tkwin), serverPtr->mask);
#else 
	XFreePixmap(Tk_Display(tkwin), serverPtr->mask);
#endif /* WIN32 */
	serverPtr->mask = None;
    }
    photo = Blt_FindPhoto(serverPtr->interp, 
			  Blt_NameOfImage(serverPtr->tkImage));
    if (photo != NULL) {
	Tk_PhotoImageBlock src;

	Tk_PhotoGetImage(photo, &src);
	if ((src.offset[3] < src.pixelSize) && (src.offset[3] >= 0)) {
	    serverPtr->mask = Blt_PhotoImageMask(tkwin, src);
	}
    }
}

/*
 *----------------------------------------------------------------------
 *
 * UpdateTile --
 *
 *	It would be better if Tk checked for NULL proc pointers.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
UpdateTile(clientData)
    ClientData clientData;
{
    Server *serverPtr = (Server *) clientData;
    Client *clientPtr;
    Blt_ChainLink *linkPtr;

    serverPtr->flags &= ~NOTIFY_PENDING;
    if (Tk_ImageIsDeleted(serverPtr->tkImage)) {
	if (serverPtr->pixmap != None) {
	    Tk_FreePixmap(serverPtr->display, serverPtr->pixmap);
	}
	serverPtr->pixmap = None;
    } else {
	/* Pick any client window to generate the new pixmap. */
	linkPtr = Blt_ChainFirstLink(serverPtr->clients);
	clientPtr = Blt_ChainGetValue(linkPtr);
	RedrawTile(clientPtr->tkwin, serverPtr);
    }

    /* Notify each of the tile's clients that the pixmap has changed. */

    for (linkPtr = Blt_ChainFirstLink(serverPtr->clients); linkPtr != NULL;
	linkPtr = Blt_ChainNextLink(linkPtr)) {
	clientPtr = Blt_ChainGetValue(linkPtr);
	if (clientPtr->notifyProc != NULL) {
	    (*clientPtr->notifyProc) (clientPtr->clientData, 
		      (Blt_Tile)clientPtr);
	}
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ImageChangedProc
 *
 *	The Tk image has changed or been deleted, redraw the pixmap
 *	tile.
 *
 *	Note:	As of Tk 4.2 (rechecked in 8.3), if you redraw Tk 
 *		images from a Tk_ImageChangedProc you'll get a 
 *		coredump.  As a workaround, we have to simulate 
 *		how the Tk widgets use images and redraw within 
 *		an idle event.
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
    int imageWidth, imageHeight; /* Not used. */
{
    Server *serverPtr = (Server *) clientData;

    if (!(serverPtr->flags & NOTIFY_PENDING)) {
	Tcl_DoWhenIdle(UpdateTile, serverPtr);
	serverPtr->flags |= NOTIFY_PENDING;
    }
}

/*
 *----------------------------------------------------------------------
 *
 * DestroyServer --
 *
 *	Deletes the tile server structure, including the pixmap
 *	representing the tile.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
DestroyServer(serverPtr)
    Server *serverPtr;
{
    Blt_ChainLink *linkPtr;
    Client *clientPtr;

    if (serverPtr->flags & NOTIFY_PENDING) {
	Tcl_CancelIdleCall(UpdateTile, serverPtr);
    }
    for (linkPtr = Blt_ChainFirstLink(serverPtr->clients); linkPtr != NULL;
	linkPtr = Blt_ChainNextLink(linkPtr)) {
	clientPtr = Blt_ChainGetValue(linkPtr);
	Blt_Free(clientPtr);
    }
    Blt_ChainDestroy(serverPtr->clients);

    if (serverPtr->hashPtr != NULL) {
	Blt_DeleteHashEntry(serverPtr->tablePtr, serverPtr->hashPtr);
    }
    if (serverPtr->pixmap != None) {
	Tk_FreePixmap(serverPtr->display, serverPtr->pixmap);
    }
    Tk_FreeImage(serverPtr->tkImage);

    if (serverPtr->gc != NULL) {
	Tk_FreeGC(serverPtr->display, serverPtr->gc);
    }
    if (serverPtr->name != NULL) {
	Blt_Free(serverPtr->name);
    }
    Blt_Free(serverPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * CreateServer --
 *
 *	Creates a tile server.  A tile server manages a single image,
 *	possibly shared by several clients.  Clients will be updated
 *	(if requested) by the server if the image changes, so they
 *	know to redraw themselves.  For X11 the image is drawn into a
 *	pixmap that is used in a new GC as its tile.  For Windows we
 *	have to do the tiling ourselves by redrawing the image across
 *	the drawing area (see Blt_TileRectangle and Blt_TilePolygon).
 *
 * Results:
 *	Returns a pointer to the new tile server.  If the image name
 *	does not represent a Tk image, NULL is returned.
 *
 *---------------------------------------------------------------------- 
 */
static Server *
CreateServer(interp, tkwin, imageName)
    Tcl_Interp *interp;
    Tk_Window tkwin;
    char *imageName;
{
    Server *serverPtr;
    Tk_Image tkImage;

    serverPtr = Blt_Calloc(1, sizeof(Server));
    assert(serverPtr);
    /*
     * Get the image. Funnel all change notifications to a single routine.
     */
    tkImage = Tk_GetImage(interp, tkwin, imageName, ImageChangedProc,
	serverPtr);
    if (tkImage == NULL) {
	Blt_Free(serverPtr);
	return NULL;
    }

    /*
     * Initialize the tile server.
     */
    serverPtr->display = Tk_Display(tkwin);
    serverPtr->interp = interp;
    serverPtr->name = Blt_Strdup(imageName);
    serverPtr->clients = Blt_ChainCreate();
    serverPtr->tkImage = tkImage;
    RedrawTile(tkwin, serverPtr);
    return serverPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * DestroyClient --
 *
 *	Removes the client from the servers's list of clients and
 *	memory used by the client token is released.  When the last
 *	client is deleted, the server is also removed.
 *
 * Results:
 *	None.
 *
 *---------------------------------------------------------------------- 
 */
static void
DestroyClient(clientPtr)
    Client *clientPtr;
{
    Server *serverPtr;
    serverPtr = clientPtr->serverPtr;

    /* Remove the client from the server's list */
    if (clientPtr->linkPtr != NULL) {
	Blt_ChainDeleteLink(serverPtr->clients, clientPtr->linkPtr);
    }
    if (Blt_ChainGetLength(serverPtr->clients) == 0) {
	/*
	 * If there are no more clients of the tile, then remove the
	 * pixmap, image, and the server record.
	 */
	DestroyServer(serverPtr);
    }
    Blt_Free(clientPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * CreateClient --
 *
 *	Returns a token to a tile (possibly shared by many clients).
 *	A client uses the token to query or display the tile.  Clients
 *	request tiles by their image names.  Each tile is known by its
 *	display, screen depth, and image name.  The tile server tracks
 *	what clients are using the tile and notifies them (via a
 *	callback) whenever the tile changes. If no server exists
 *	already, one is created on-the-fly.
 *
 * Results:
 *	A pointer to the newly created client (i.e. tile).
 *
 *---------------------------------------------------------------------- 
 */
static Client *
CreateClient(interp, tkwin, name)
    Tcl_Interp *interp;
    Tk_Window tkwin;
    char *name;
{
    Client *clientPtr;
    Server *serverPtr;
    TileInterpData *dataPtr;
    Blt_HashEntry *hPtr;
    int isNew;
    TileKey key;

    dataPtr = GetTileInterpData(interp);

    key.nameId = Tk_GetUid(name);
    key.display = Tk_Display(tkwin);
    key.depth = Tk_Depth(tkwin);
    hPtr = Blt_CreateHashEntry(&(dataPtr->tileTable), (char *)&key, &isNew);
    if (isNew) {
	serverPtr = CreateServer(interp, tkwin, name);
	if (serverPtr == NULL) {
	    Blt_DeleteHashEntry(&(dataPtr->tileTable), hPtr);
	    return NULL;
	}
	serverPtr->hashPtr = hPtr;
	serverPtr->tablePtr = &(dataPtr->tileTable);
	Blt_SetHashValue(hPtr, serverPtr);
    } else {
	serverPtr = Blt_GetHashValue(hPtr);
    }
    clientPtr = Blt_Calloc(1, sizeof(Client));
    assert(clientPtr);

    /* Initialize client information. */
    clientPtr->magic = TILE_MAGIC;
    clientPtr->tkwin = tkwin;
    clientPtr->linkPtr = Blt_ChainAppend(serverPtr->clients, clientPtr);
    clientPtr->serverPtr = serverPtr;
    return clientPtr;
}

/*
 * -----------------------------------------------------------------------
 *
 * TileInterpDeleteProc --
 *
 *	This is called when the interpreter is deleted. All the tiles
 *	are specific to that interpreter are destroyed.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Destroys the tile table.
 *
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
static void
TileInterpDeleteProc(clientData, interp)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
{
    TileInterpData *dataPtr = clientData;
    Blt_HashEntry *hPtr;
    Blt_HashSearch cursor;
    Server *serverPtr;
    
    for (hPtr = Blt_FirstHashEntry(&(dataPtr->tileTable), &cursor);
	 hPtr != NULL; hPtr = Blt_NextHashEntry(&cursor)) {
	serverPtr = Blt_GetHashValue(hPtr);
	serverPtr->hashPtr = NULL;
	DestroyServer(serverPtr);
    }
    Blt_DeleteHashTable(&(dataPtr->tileTable));
    Tcl_DeleteAssocData(interp, TILE_THREAD_KEY);
    Blt_Free(dataPtr);
}

static TileInterpData *
GetTileInterpData(interp)
     Tcl_Interp *interp;
{
    TileInterpData *dataPtr;
    Tcl_InterpDeleteProc *proc;

    dataPtr = (TileInterpData *)
	Tcl_GetAssocData(interp, TILE_THREAD_KEY, &proc);
    if (dataPtr == NULL) {
	dataPtr = Blt_Malloc(sizeof(TileInterpData));
	assert(dataPtr);
	dataPtr->interp = interp;
	Tcl_SetAssocData(interp, TILE_THREAD_KEY, TileInterpDeleteProc, 
		dataPtr);
	Blt_InitHashTable(&(dataPtr->tileTable), sizeof(TileKey)/sizeof(int));
    }
    return dataPtr;
}


/* Public API for tiles. */

/*
 *----------------------------------------------------------------------
 *
 * Blt_GetTile
 *
 *	Convert the named image into a tile.
 *
 * Results:
 *	If the image is valid, a new tile is returned.  If the name
 *	does not represent a proper image, an error message is left in
 *	interp->result.
 *
 *----------------------------------------------------------------------
 */
/*LINTLIBRARY*/
int
Blt_GetTile(interp, tkwin, imageName, tilePtr)
    Tcl_Interp *interp;		/* Interpreter to report results back to */
    Tk_Window tkwin;		/* Window on the same display as tile */
    char *imageName;		/* Name of image */
    Blt_Tile *tilePtr;		/* (out) Returns the allocated tile. */
{
    Client *clientPtr;

    clientPtr = CreateClient(interp, tkwin, imageName);
    if (clientPtr == NULL) {
	return TCL_ERROR;
    } 
    *tilePtr = (Blt_Tile)clientPtr;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_FreeTile
 *
 *	Release the resources associated with the tile.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Memory and X resources are freed.  Bookkeeping information
 *	about the tile (i.e. width, height, and name) is discarded.
 *
 *----------------------------------------------------------------------
 */
/*LINTLIBRARY*/
void
Blt_FreeTile(tile)
    Blt_Tile tile;		/* Tile to be deleted */
{
    Client *clientPtr = (Client *)tile;

    if ((clientPtr == NULL) || (clientPtr->magic != TILE_MAGIC)) {
	return;			/* No tile */
    }
    DestroyClient(clientPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_NameOfTile
 *
 *	Returns the name of the image from which the tile was
 *	generated.
 *
 * Results:
 *	The name of the image is returned.  The name is not unique.
 *	Many tiles may use the same image.
 *
 *----------------------------------------------------------------------
 */
/*LINTLIBRARY*/
char *
Blt_NameOfTile(tile)
    Blt_Tile tile;		/* Tile to query */
{
    Client *clientPtr = (Client *)tile;

    if (clientPtr == NULL) {
	return "";
    }
    if (clientPtr->magic != TILE_MAGIC) {
	return "not a tile";
    }
    return clientPtr->serverPtr->name;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_PixmapOfTile
 *
 *	Returns the pixmap of the tile.
 *
 * Results:
 *	The X pixmap used as the tile is returned.
 *
 *----------------------------------------------------------------------
 */
/*LINTLIBRARY*/
Pixmap
Blt_PixmapOfTile(tile)
    Blt_Tile tile;		/* Tile to query */
{
    Client *clientPtr = (Client *)tile;

    if ((clientPtr == NULL) || (clientPtr->magic != TILE_MAGIC)) {
	return None;
    }
    return clientPtr->serverPtr->pixmap;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_SizeOfTile
 *
 *	Returns the width and height of the tile.
 *
 * Results:
 *	The width and height of the tile are returned.
 *
 *----------------------------------------------------------------------
 */
/*LINTLIBRARY*/
void
Blt_SizeOfTile(tile, widthPtr, heightPtr)
    Blt_Tile tile;		/* Tile to query */
    int *widthPtr, *heightPtr;	/* Returned dimensions of the tile (out) */
{
    Client *clientPtr = (Client *)tile;

    if ((clientPtr == NULL) || (clientPtr->magic != TILE_MAGIC)) {
	*widthPtr = *heightPtr = 0;
	return;			/* No tile given. */
    }
    *widthPtr = clientPtr->serverPtr->width;
    *heightPtr = clientPtr->serverPtr->height;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_SetTileChangedProc
 *
 *	Sets the routine to called when an image changes.  
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	The designated routine will be called the next time the
 *	image associated with the tile changes.
 *
 *----------------------------------------------------------------------
 */
/*LINTLIBRARY*/
void
Blt_SetTileChangedProc(tile, notifyProc, clientData)
    Blt_Tile tile;		/* Tile to query */
    Blt_TileChangedProc *notifyProc;
    ClientData clientData;
{
    Client *clientPtr = (Client *)tile;

    if ((clientPtr != NULL) && (clientPtr->magic == TILE_MAGIC)) {
	clientPtr->notifyProc = notifyProc;
	clientPtr->clientData = clientData;
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_SetTileOrigin --
 *
 *	Set the pattern origin of the tile to a common point (i.e. the
 *	origin (0,0) of the top level window) so that tiles from two
 *	different widgets will match up.  This done by setting the
 *	GCTileStipOrigin field is set to the translated origin of the
 *	toplevel window in the hierarchy.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	The GCTileStipOrigin is reset in the GC.  This will cause the
 *	tile origin to change when the GC is used for drawing.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
void
Blt_SetTileOrigin(tkwin, tile, x, y)
    Tk_Window tkwin;
    Blt_Tile tile;
    int x, y;
{
    Client *clientPtr = (Client *)tile;

    while (!Tk_IsTopLevel(tkwin)) {
	x += Tk_X(tkwin) + Tk_Changes(tkwin)->border_width;
	y += Tk_Y(tkwin) + Tk_Changes(tkwin)->border_width;
	tkwin = Tk_Parent(tkwin);
    }
    XSetTSOrigin(Tk_Display(tkwin), clientPtr->serverPtr->gc, -x, -y);
    clientPtr->xOrigin = -x;
    clientPtr->yOrigin = -y;
}

void
Blt_SetTSOrigin(tkwin, tile, x, y)
    Tk_Window tkwin;
    Blt_Tile tile;
    int x, y;
{
    Client *clientPtr = (Client *)tile;

    XSetTSOrigin(Tk_Display(tkwin), clientPtr->serverPtr->gc, x, y);
    clientPtr->xOrigin = x;
    clientPtr->yOrigin = y;
}

#ifdef WIN32
static int tkpWinRopModes[] =
{
    R2_BLACK,			/* GXclear */
    R2_MASKPEN,			/* GXand */
    R2_MASKPENNOT,		/* GXandReverse */
    R2_COPYPEN,			/* GXcopy */
    R2_MASKNOTPEN,		/* GXandInverted */
    R2_NOT,			/* GXnoop */
    R2_XORPEN,			/* GXxor */
    R2_MERGEPEN,		/* GXor */
    R2_NOTMERGEPEN,		/* GXnor */
    R2_NOTXORPEN,		/* GXequiv */
    R2_NOT,			/* GXinvert */
    R2_MERGEPENNOT,		/* GXorReverse */
    R2_NOTCOPYPEN,		/* GXcopyInverted */
    R2_MERGENOTPEN,		/* GXorInverted */
    R2_NOTMASKPEN,		/* GXnand */
    R2_WHITE			/* GXset */
};
#define MASKPAT		0x00E20746 /* dest = (src & pat) | (!src & dst) */
#define COPYFG		0x00CA0749 /* dest = (pat & src) | (!pat & dst) */
#define COPYBG		0x00AC0744 /* dest = (!pat & src) | (pat & dst) */

static void
TileRegion(
    HDC destDC, 
    HDC srcDC,
    Client *clientPtr,
    int x, int y, 
    int width, int height)
{
    Server *serverPtr = clientPtr->serverPtr;
    int destX, destY;
    int destWidth, destHeight;
    int srcX, srcY;
    int startX, startY;		/* Starting upper left corner of region. */
    int delta;
    int left, top, right, bottom;

    startX = x;
    if (x < clientPtr->xOrigin) {
	delta = (clientPtr->xOrigin - x) % serverPtr->width;
	if (delta > 0) {
	    startX -= (serverPtr->width - delta);
	}
    } else if (x > clientPtr->xOrigin) {
	delta = (x - clientPtr->xOrigin) % serverPtr->width;
	if (delta > 0) {
	    startX -= delta;
	}
    }
    startY = y;
    if (y < clientPtr->yOrigin) {
	delta = (clientPtr->yOrigin - y) % serverPtr->height;
	if (delta > 0) {
	    startY -= (serverPtr->height - delta);
	}
    } else if (y >= clientPtr->yOrigin) {
	delta = (y - clientPtr->yOrigin) % serverPtr->height;
	if (delta > 0) {
	    startY -= delta;
	}
    }
#ifdef notdef
    PurifyPrintf("tile is (%d,%d,%d,%d)\n", 
		 clientPtr->xOrigin, clientPtr->yOrigin, 
		 serverPtr->width, serverPtr->height);
    PurifyPrintf("region is (%d,%d,%d,%d)\n", x, y, width, height);
    PurifyPrintf("starting at %d,%d\n", startX, startY);
#endif
    left = x;
    right = x + width;
    top = y;
    bottom = y + height;
    for (y = startY; y < bottom; y += serverPtr->height) {
	srcY = 0;
	destY = y;
	destHeight = serverPtr->height;
	if (y < top) {
	    srcY = (top - y);
	    destHeight = serverPtr->height - srcY;
	    destY = top;
	} 
	if ((destY + destHeight) > bottom) {
	    destHeight = (bottom - destY);
	}
	for (x = startX; x < right; x += serverPtr->width) {
	    srcX = 0;
	    destX = x;
	    destWidth = serverPtr->width;
	    if (x < left) {
		srcX = (left - x);
		destWidth = serverPtr->width - srcX;
		destX = left;
	    } 
	    if ((destX + destWidth) > right) {
		destWidth = (right - destX);
	    }
#ifdef notdef
	    PurifyPrintf("drawing pattern (%d,%d,%d,%d) at %d,%d\n",
		 srcX , srcY, destWidth, destHeight, destX, destY);
#endif
	    if (serverPtr->mask != None) { /* With transparency. */
		HDC maskDC;
		TkWinDCState maskState;

		maskDC = TkWinGetDrawableDC(serverPtr->display, 
			serverPtr->mask, &maskState);
		SetBkColor(destDC, RGB(255, 255, 255));      
		SetTextColor(destDC, RGB(0, 0, 0));
		BitBlt(destDC, destX, destY, destWidth, destHeight, maskDC, 
		       0, 0, SRCAND);
		BitBlt(destDC, destX, destY, destWidth, destHeight, srcDC, 
		       srcX, srcY, SRCPAINT);
		TkWinReleaseDrawableDC(serverPtr->mask, maskDC, &maskState);
	    } else {		/* Opaque tile. */
	        BitBlt(destDC, destX, destY, destWidth, destHeight, 
		       srcDC, srcX, srcY, SRCCOPY);
	    }
	}
    }
}

void
Blt_TilePolygon(
    Tk_Window tkwin,
    Drawable drawable,
    Blt_Tile tile,
    XPoint pointArr[],
    int nPoints)
{
    Client *clientPtr = (Client *)tile;
    HBITMAP oldBitmap;
    HDC hDC;
    HDC memDC;
    HRGN hRgn;
    Region2D bbox;
    Display *display;
    Server *serverPtr;
    TkWinDCState state;
    TkWinDrawable *twdPtr;
    XPoint *endPtr, *pointPtr;
    int width, height;
    POINT *p, *winPts;
    int fillMode;

    if (drawable == None) {
	return;
    }
    display = Tk_Display(tkwin);
    serverPtr = clientPtr->serverPtr;

    /* Determine the bounding box of the polygon. */
    bbox.left = bbox.right = pointArr[0].x;
    bbox.top = bbox.bottom = pointArr[0].y;
    
    endPtr = pointArr + nPoints;
    for (pointPtr = pointArr; pointPtr < endPtr; pointPtr++) {
	if (pointPtr->x < bbox.left) {
	    bbox.left = pointPtr->x;
	} 
	if (pointPtr->x > bbox.right) {
	    bbox.right = pointPtr->x;
	}
	if (pointPtr->y < bbox.top) {
	    bbox.top = pointPtr->y;
	} 
	if (pointPtr->y > bbox.bottom) {
	    bbox.bottom = pointPtr->y;
	}
    }
    width = bbox.right - bbox.left + 1;
    height = bbox.bottom - bbox.top + 1;

    /* Allocate and fill an array of POINTS to create the polygon path. */
    p = winPts = Blt_Malloc(sizeof(POINT) * nPoints);
    for (pointPtr = pointArr; pointPtr < endPtr; pointPtr++) {
	p->x = pointPtr->x - bbox.left;
	p->y = pointPtr->y - bbox.top;
	p++;
    }

    hDC = TkWinGetDrawableDC(Tk_Display(tkwin), drawable, &state);
    SetROP2(hDC, tkpWinRopModes[serverPtr->gc->function]);
    fillMode = (serverPtr->gc->fill_rule == EvenOddRule) ? ALTERNATE : WINDING;
    /* Use the polygon as a clip path. */
    hRgn = CreatePolygonRgn(winPts, nPoints, fillMode);
    SelectClipRgn(hDC, hRgn);
    OffsetClipRgn(hDC, bbox.left, bbox.top);
    Blt_Free(winPts);

    twdPtr = (TkWinDrawable *)serverPtr->pixmap;
    memDC = CreateCompatibleDC(hDC);
    oldBitmap = SelectBitmap(memDC, twdPtr->bitmap.handle);
    
    /* Tile the bounding box. */
    TileRegion(hDC, memDC, clientPtr, bbox.left, bbox.top, width, height);
    
    SelectBitmap(memDC, oldBitmap);
    DeleteDC(memDC);
    SelectClipRgn(hDC, NULL);
    DeleteRgn(hRgn);
    TkWinReleaseDrawableDC(drawable, hDC, &state);
}

void
Blt_TileRectangle(tkwin, drawable, tile, x, y, width, height)
    Tk_Window tkwin;
    Drawable drawable;
    Blt_Tile tile;
    int x, y;
    unsigned int width, height;
{
    Client *clientPtr = (Client *)tile;
    HBITMAP oldBitmap;
    HDC hDC, memDC;
    Server *serverPtr;
    TkWinDCState state;
    TkWinDrawable *twdPtr;

    if (drawable == None) {
	return;
    }
    serverPtr = clientPtr->serverPtr;
    hDC = TkWinGetDrawableDC(Tk_Display(tkwin), drawable, &state);
    SetROP2(hDC, tkpWinRopModes[serverPtr->gc->function]);

    twdPtr = (TkWinDrawable *)serverPtr->pixmap;
    memDC = CreateCompatibleDC(hDC);
    oldBitmap = SelectBitmap(memDC, twdPtr->bitmap.handle);

    TileRegion(hDC, memDC, clientPtr, x, y, width, height);

    SelectBitmap(memDC, oldBitmap);
    DeleteDC(memDC);
    TkWinReleaseDrawableDC(drawable, hDC, &state);
}

void
Blt_TileRectangles(
    Tk_Window tkwin,
    Drawable drawable,
    Blt_Tile tile,
    XRectangle rectArr[],
    int nRectangles)
{
    Client *clientPtr = (Client *)tile;
    HBITMAP oldBitmap;
    HDC hDC, memDC;
    Server *serverPtr;
    TkWinDCState state;
    TkWinDrawable *twdPtr;
    XRectangle *rectPtr, *endPtr;

    if (drawable == None) {
	return;
    }
    serverPtr = clientPtr->serverPtr;
    hDC = TkWinGetDrawableDC(Tk_Display(tkwin), drawable, &state);
    SetROP2(hDC, tkpWinRopModes[serverPtr->gc->function]);

    twdPtr = (TkWinDrawable *)serverPtr->pixmap;
    memDC = CreateCompatibleDC(hDC);
    oldBitmap = SelectBitmap(memDC, twdPtr->bitmap.handle);

    endPtr = rectArr + nRectangles;
    for (rectPtr = rectArr; rectPtr < endPtr; rectPtr++) {
	TileRegion(hDC, memDC, clientPtr, (int)rectPtr->x, (int)rectPtr->y, 
	   (int)rectPtr->width, (int)rectPtr->height);
    }
    SelectBitmap(memDC, oldBitmap);
    DeleteDC(memDC);
    TkWinReleaseDrawableDC(drawable, hDC, &state);
}

#else 

/*
 *----------------------------------------------------------------------
 *
 * RectangleMask --
 *
 *	Creates a rectangular mask also stippled by the mask of the 
 *	tile.  This is used to draw the tiled polygon images with 
 *	transparent areas.
 *
 * Results:
 *	A bitmap mask is returned.
 *
 *----------------------------------------------------------------------
 */
static Pixmap
RectangleMask(display, drawable, x, y, width, height, mask, xOrigin, yOrigin)
    Display *display;
    Drawable drawable;
    int x, y;
    unsigned int width, height;
    Pixmap mask;
    int xOrigin, yOrigin;
{
    GC gc;
    Pixmap bitmap;
    XGCValues gcValues;
    unsigned long gcMask;

    bitmap = Tk_GetPixmap(display, drawable, width, height, 1);
    gcMask = (GCForeground | GCBackground | GCFillStyle | 
	      GCTileStipXOrigin | GCTileStipYOrigin | GCStipple);
    gcValues.foreground = 0x1;
    gcValues.background = 0x0;
    gcValues.fill_style = FillOpaqueStippled;
    gcValues.ts_x_origin = xOrigin - x;
    gcValues.ts_y_origin = yOrigin - y;
    gcValues.stipple = mask;
    gc = XCreateGC(display, bitmap, gcMask, &gcValues);
    XFillRectangle(display, bitmap, gc, 0, 0, width, height);
    Blt_FreePrivateGC(display, gc);
    return bitmap;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TileRectangle --
 *
 *	Draws a rectangle filled by a tiled image.  This differs from 
 *	the normal XFillRectangle call in that we also try to handle 
 *	a transparency mask. 
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Draws the rectangle.
 *
 *----------------------------------------------------------------------
 */
void
Blt_TileRectangle(tkwin, drawable, tile, x, y, width, height)
    Tk_Window tkwin;
    Drawable drawable;
    Blt_Tile tile;
    int x, y;
    unsigned int width, height;
{
    Client *clientPtr = (Client *)tile;
    Server *serverPtr;
    Display *display;

    display = Tk_Display(tkwin);
    serverPtr = clientPtr->serverPtr;
    if (clientPtr->serverPtr->mask != None) {
	Pixmap mask;

	mask = RectangleMask(display, drawable, x, y, width, height,
		serverPtr->mask, clientPtr->xOrigin, clientPtr->yOrigin);
	XSetClipMask(display, serverPtr->gc, mask);
	XSetClipOrigin(display, serverPtr->gc, x, y);
	XFillRectangle(display, drawable, serverPtr->gc, x, y, width, height);
	XSetClipMask(display, serverPtr->gc, None);
	XSetClipOrigin(display, serverPtr->gc, 0, 0);
	Tk_FreePixmap(display, mask);
    } else {
	XFillRectangle(display, drawable, serverPtr->gc, x, y, width, height);
    }
}


/*
 *----------------------------------------------------------------------
 *
 * Blt_TileRectangles --
 *
 *	Draws rectangles filled by a tiled image.  This differs from 
 *	the normal XFillRectangles call in that we also try to handle 
 *	a transparency mask. 
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Draws the given rectangles.
 *
 *----------------------------------------------------------------------
 */
void
Blt_TileRectangles(tkwin, drawable, tile, rectArr, nRectangles)
    Tk_Window tkwin;
    Drawable drawable;
    Blt_Tile tile;
    XRectangle rectArr[];
    int nRectangles;
{
    Client *clientPtr = (Client *)tile;
    Server *serverPtr;

    serverPtr = clientPtr->serverPtr;
    if (serverPtr->mask != None) {
	XRectangle *rectPtr, *endPtr;

	endPtr = rectArr + nRectangles;
	for (rectPtr = rectArr; rectPtr < endPtr; rectPtr++) {
	    Blt_TileRectangle(tkwin, drawable, tile, rectPtr->x, rectPtr->y,
		      rectPtr->width, rectPtr->height);
	}
    } else {
	XFillRectangles(Tk_Display(tkwin), drawable, serverPtr->gc, rectArr, 
		nRectangles);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * PolygonMask --
 *
 *	Creates a polygon shaped mask also stippled by the mask
 *	of the tile.  This is used to draw the tiled polygon images
 *	with transparent areas.
 *
 * Results:
 *	A bitmap mask is returned.
 *
 *----------------------------------------------------------------------
 */
static Pixmap
PolygonMask(display, pointArr, nPoints, regionPtr, mask, xOrigin, yOrigin)
    Display *display;
    XPoint *pointArr;
    int nPoints;
    Region2D *regionPtr;
    Pixmap mask;
    int xOrigin, yOrigin;
{
    unsigned int width, height;
    Pixmap bitmap;
    GC gc;
    XPoint *destArr;
    register XPoint *srcPtr, *destPtr, *endPtr;

    width = regionPtr->right - regionPtr->left + 1;
    height = regionPtr->bottom - regionPtr->top + 1;
    bitmap = 
	Tk_GetPixmap(display, DefaultRootWindow(display), width, height, 1);

    destArr = Blt_Malloc(sizeof(XPoint) * nPoints);
    endPtr = destArr + nPoints;
    srcPtr = pointArr;
    for (destPtr = destArr; destPtr < endPtr; destPtr++) {
	destPtr->x = srcPtr->x - regionPtr->left;
	destPtr->y = srcPtr->y - regionPtr->top;
	srcPtr++;
    }
    gc = XCreateGC(display, bitmap, 0, NULL);
    XFillRectangle(display, bitmap, gc, 0, 0, width, height);
    XSetForeground(display, gc, 0x01);
    XSetFillStyle(display, gc, FillStippled);
    XSetTSOrigin(display, gc, xOrigin - regionPtr->left, 
		 yOrigin - regionPtr->top);
    XSetStipple(display, gc, mask);
    XFillPolygon(display, bitmap, gc, destArr, nPoints, Complex, 
		 CoordModeOrigin);
    XFreeGC(display, gc);
    Blt_Free(destArr);
    return bitmap;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_TilePolygon --
 *
 *	Draws a polygon filled by a tiled image.  This differs from 
 *	the normal XFillPolygon call in that we also try to handle 
 *	a transparency mask. 
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Draws the polygon.
 *
 *----------------------------------------------------------------------
 */
void
Blt_TilePolygon(tkwin, drawable, tile, pointArr, nPoints)
    Tk_Window tkwin;
    Drawable drawable;
    Blt_Tile tile;
    XPoint pointArr[];
    int nPoints;
{
    Client *clientPtr = (Client *)tile;
    Server *serverPtr;
    Display *display;
    
    display = Tk_Display(tkwin);
    serverPtr = clientPtr->serverPtr;
    if (serverPtr->mask != None) {
	XPoint *pointPtr, *endPtr;
	Region2D region;
	Pixmap mask;

	/* Determine the bounding box of the polygon. */
	pointPtr = pointArr;
	region.left = region.right = pointPtr->x;
	region.top = region.bottom = pointPtr->y;
	
	endPtr = pointArr + nPoints;
	for (pointPtr = pointArr; pointPtr < endPtr; pointPtr++) {
	    if (region.left > pointPtr->x) {
		region.left = pointPtr->x;
	    } else if (region.right < pointPtr->x) {
		region.right = pointPtr->x;
	    }
	    if (region.top > pointPtr->y) {
		region.top = pointPtr->y;
	    } else if (region.bottom < pointPtr->y) {
		region.bottom = pointPtr->y;
	    }
	}
	mask = PolygonMask(display, pointArr, nPoints, &region, 
		   serverPtr->mask, clientPtr->xOrigin, clientPtr->yOrigin);
	XSetClipMask(display, serverPtr->gc, mask);
	XSetClipOrigin(display, serverPtr->gc, region.left, region.top);
	XFillPolygon(display, drawable, serverPtr->gc, pointArr, 
		     nPoints, Complex, CoordModeOrigin);
	XSetClipMask(display, serverPtr->gc, None);
	XSetClipOrigin(display, serverPtr->gc, 0, 0);
	Tk_FreePixmap(display, mask);
    } else {
	XFillPolygon(display, drawable, serverPtr->gc, pointArr, 
		     nPoints, Complex, CoordModeOrigin);
    }
}
#endif
