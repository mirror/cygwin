#include "default.h"
#include "tkInt.h"
#include "tkPort.h"
#include "tkCanvas.h"
#include "tkCanvLayout.h"

extern Tk_ItemType tkEdgeType;

static Tk_Uid allUid = NULL;

typedef struct Layout_Graph Layout_Graph;

static
char* layableitems[] = {
    "bitmap",
    "edge",
    "oval",
    "polygon",
    "rectangle",
    "text",
    "window",
    (char*)0
};

/* Define a config set for graph command */
static Tk_ConfigSpec graphspecs[] = {
  {TK_CONFIG_BOOLEAN, "-computenodesize", (char*)NULL, (char*)NULL, 
     "0", Tk_Offset(LayoutConfig,computenodesize), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_INT, "-gridlock", (char*)NULL, (char*)NULL, 
     "0", Tk_Offset(LayoutConfig,gridlock), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_INT, "-elementsperline", (char*)NULL, (char*)NULL, 
     "0", Tk_Offset(LayoutConfig,elementsperline), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_BOOLEAN, "-hideedges", (char*)NULL, (char*)NULL, 
     "0", Tk_Offset(LayoutConfig,hideedges), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_BOOLEAN, "-keeprandompositions", (char*)NULL, (char*)NULL, 
     "0", Tk_Offset(LayoutConfig,keeprandompositions), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_PIXELS, "-nodespaceh", (char*)NULL, (char*)NULL, 
     "5", Tk_Offset(LayoutConfig,nodespaceH), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_PIXELS, "-nodespacev", (char*)NULL, (char*)NULL, 
     "5", Tk_Offset(LayoutConfig,nodespaceV), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_PIXELS, "-maxx", (char*)NULL, (char*)NULL, 
     (char*)NULL, Tk_Offset(LayoutConfig,maxx),
     TK_CONFIG_DONT_SET_DEFAULT, (Tk_CustomOption*)NULL},
  {TK_CONFIG_PIXELS, "-maxy", (char*)NULL, (char*)NULL, 
     (char*)NULL, Tk_Offset(LayoutConfig,maxy),
     TK_CONFIG_DONT_SET_DEFAULT, (Tk_CustomOption*)NULL},
  {TK_CONFIG_INT, "-order", (char*)NULL, (char*)NULL, 
     "0", Tk_Offset(LayoutConfig,graphorder), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_PIXELS, "-xoffset", (char*)NULL, (char*)NULL, 
     "4", Tk_Offset(LayoutConfig,xoffset), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_PIXELS, "-yoffset", (char*)NULL, (char*)NULL, 
     "4", Tk_Offset(LayoutConfig,yoffset), 0, (Tk_CustomOption*)NULL},
  {TK_CONFIG_END, (char *) NULL, (char *) NULL, (char *) NULL,
     (char *) NULL, 0, 0}
};

/*
 * See tkCanvas.h for key data structures used to implement canvases.
 */

/*
 * The structure defined below is used to keep track of a tag search
 * in progress.  Only the "prevPtr" field should be accessed by anyone
 * other than StartTagSearch and NextItem.
 */

typedef struct TagSearch {
    TkCanvas *canvasPtr;        /* Canvas widget being searched. */
    Tk_Uid tag;                 /* Tag to search for.   0 means return
				 * all items. */
    Tk_Item *prevPtr;           /* Item just before last one found (or NULL
				 * if last one found was first in the item
				 * list of canvasPtr). */
    Tk_Item *currentPtr;        /* Pointer to last item returned. */
    int searchOver;             /* Non-zero means NextItem should always
				 * return NULL. */
} TagSearch;

static Tk_Item *        NextItem _ANSI_ARGS_((TagSearch *searchPtr));
static Tk_Item *        StartTagSearch _ANSI_ARGS_((TkCanvas *canvasPtr,
			    char *tag, TagSearch *searchPtr));
static Tcl_HashTable *  graph_table _ANSI_ARGS_((Tcl_Interp *interp));

int    MY_graphOrder   (struct Layout_Graph* This);
void * MY_EdgeParent   (struct Layout_Graph* This, int i, int num);
void * MY_EdgeFromNode (struct Layout_Graph* This, int i);


static
int
getnodebbox(interp,canvasPtr, iPtr, bbox)
    Tcl_Interp* interp;
    TkCanvas* canvasPtr;
    Tk_Item* iPtr;
    ItemGeom* bbox;
{
    bbox->x1 = iPtr->x1;
    bbox->y1 = iPtr->y1;
    bbox->x2 = iPtr->x2;
    bbox->y2 = iPtr->y2;
    return TCL_OK;
}

static
int
getedgedim(canvasPtr, e, dim)
    TkCanvas* canvasPtr;
    Tk_Item* e;
    ItemGeom* dim;
{
    int argc2; 
    char **argv2;

    /* Read the text height of this edge. */
    Tk_ConfigureInfo(canvasPtr->interp, canvasPtr->tkwin,
			 e->typePtr->configSpecs,
			 (char *) e, "-textheight", 0);
    if(Tcl_SplitList(canvasPtr->interp, canvasPtr->interp->result,
			  &argc2, &argv2) != TCL_OK) {
	return TCL_ERROR;
    }
    dim->height = atol(argv2[4]);
    ckfree((char *) argv2);
    /* Read the text width of this edge. */
    Tk_ConfigureInfo(canvasPtr->interp, canvasPtr->tkwin,
			 e->typePtr->configSpecs,
			 (char *) e, "-textwidth", 0);
    if(Tcl_SplitList(canvasPtr->interp, canvasPtr->interp->result,
			  &argc2, &argv2) != TCL_OK) {
	return TCL_ERROR;
    }
    dim->width = atol(argv2[4]);
    ckfree((char *) argv2);
    Tcl_ResetResult(canvasPtr->interp);
    return TCL_OK;
}

static
int
setnodegeom(interp,canvasPtr,iPtr,geom)
    Tcl_Interp* interp;
    TkCanvas* canvasPtr;
    Tk_Item* iPtr;
    ItemGeom geom;
{
    double deltax, deltay;

    if(iPtr->typePtr->translateProc == NULL) {
	Tcl_AppendResult(interp,"item has no translation proc",(char*)0);
	return TCL_ERROR;
    }

    /* get the delta x,y of the item */
    deltax = geom.x1 - iPtr->x1;
    deltay = geom.y1 - iPtr->y1;

    Tk_CanvasEventuallyRedraw((Tk_Canvas) canvasPtr, iPtr->x1, iPtr->y1, iPtr->x2, iPtr->y2);
    (void)(*iPtr->typePtr->translateProc)((Tk_Canvas) canvasPtr, iPtr, deltax, deltay);
    Tk_CanvasEventuallyRedraw((Tk_Canvas) canvasPtr, iPtr->x1, iPtr->y1, iPtr->x2, iPtr->y2);   
    return TCL_OK;
}

static Layout_Graph *
GetGraphLayoutII(TkCanvas *canvasPtr, Tcl_Interp *interp);
static
int
setedgegeom(interp,canvasPtr,iPtr,geom,i)
    Tcl_Interp* interp;
    TkCanvas* canvasPtr;
    Tk_Item* iPtr;
    ItemGeom geom;
    int i;
{
    /* register char* nm;
       register int c; */
    int argc = 4;
    char x1[TCL_DOUBLE_SPACE];
    char y1[TCL_DOUBLE_SPACE];
    char x2[TCL_DOUBLE_SPACE];
    char y2[TCL_DOUBLE_SPACE];
    char x3[TCL_DOUBLE_SPACE];
    char y3[TCL_DOUBLE_SPACE];
    char x4[TCL_DOUBLE_SPACE];
    char y4[TCL_DOUBLE_SPACE];
    char* argv[8];
    Layout_Graph *graph=GetGraphLayoutII(canvasPtr, interp);

    LayoutConfig cnf = GetLayoutConfig (/*canvasPtr->*/graph);
    double xd = geom.x1 - geom.x2 /*- 10.0*/ , xdiff;
    
    if (xd < 0.0) xd = geom.x2 - geom.x1 /*- 10.0*/;

    if(iPtr->typePtr->coordProc == NULL) {
	Tcl_AppendResult(interp,"could not set edge item coordinates",(char*)0);
	return TCL_ERROR; 
    }
    argv[0] = x1;
    argv[1] = y1;
    argv[2] = x2;
    argv[3] = y2;
    argv[4] = x3;
    argv[5] = y3;
    argv[6] = x4;
    argv[7] = y4;

    sprintf(x1,"%g",geom.x1);
    sprintf(y1,"%g",geom.y1);
    sprintf(x2,"%g",geom.x2);
    sprintf(y2,"%g",geom.y2);

	if (cnf.gridlock!=0)
	{
		/* changing lines, only when right to left */
		if (! MY_graphOrder (/*canvasPtr->*/graph))
		  {
	        xdiff = (double) cnf.nodespaceH - xd;
		    if (xdiff < 0.0) xdiff = xd - (double) cnf.nodespaceH;

			if (xdiff < 2.0 &&
		       MY_EdgeParent(/*canvasPtr->*/graph, i, 0) ==
		       MY_EdgeFromNode (/*canvasPtr->*/graph, i))
			{
				sprintf (x4, "%g", geom.x2);
				sprintf (y4, "%g", geom.y2);

				sprintf (x2, "%g", geom.x1 + (geom.x2 - geom.x1) / 2);
				sprintf (y2, "%g", geom.y1);
				sprintf (x3, "%g", geom.x1 + (geom.x2 - geom.x1) / 2);
				sprintf (y3, "%g", geom.y2);
				argc = 8;
			}
		  }
	}
    Tk_CanvasEventuallyRedraw((Tk_Canvas) canvasPtr, iPtr->x1, iPtr->y1, iPtr->x2, iPtr->y2);
    (void)(*iPtr->typePtr->coordProc)(interp, (Tk_Canvas) canvasPtr, iPtr,
				      /* argc-3, argv+3); 08nov95 wmt */
				      argc, argv);
    Tk_CanvasEventuallyRedraw((Tk_Canvas) canvasPtr, iPtr->x1, iPtr->y1, iPtr->x2, iPtr->y2);   
    return TCL_OK;
}
 
static
int
GetEdgeNodes(interp,canvasPtr,i,fp,tp)
	Tcl_Interp* interp;
	TkCanvas* canvasPtr;
	Tk_Item* i;
	char** fp;
	char** tp;
{
    int argc;
    char** argv;
    char * buf;

    /* Read the from node id of this edge. */
    Tk_ConfigureInfo(interp, canvasPtr->tkwin,
			 i->typePtr->configSpecs,
			 (char *) i, "-from", 0);
    if(Tcl_SplitList(interp, interp->result,
			  &argc, &argv) != TCL_OK) {
	return TCL_ERROR;
    }
    /* This should actuall be a call like Tcl_Strdup() */
    buf = (char*)ckalloc (strlen(argv[4])+1);
    strcpy (buf, argv[4]);
    *fp = buf;
    ckfree((char*)argv);
    /* Read the to node id of this edge. */
    Tk_ConfigureInfo(interp, canvasPtr->tkwin,
			 i->typePtr->configSpecs,
			 (char *) i, "-to", 0);
    if(Tcl_SplitList(interp, interp->result,
			  &argc, &argv) != TCL_OK) {
	return TCL_ERROR;
    }
    buf = (char*)ckalloc (strlen(argv[4])+1);
    strcpy (buf, argv[4]);
    *tp = buf;
    ckfree((char*)argv);
    Tcl_ResetResult(interp);
    return TCL_OK;
}


int
createcanvasgraph(interp,canvCmd,graph)
    Tcl_Interp* interp;
    Tcl_CmdInfo *canvCmd;
    Layout_Graph **graph;
{
    LayoutConfig cfg;
    int argc1; char* argv1[3];

    *graph = LayoutCreateGraph();
    if(!*graph) {
	Tcl_AppendResult(interp,"cannot create graph for canvas",(char*)0);
	return TCL_ERROR;
    }
    cfg = GetLayoutConfig(*graph);
    /* Establish max x and max y based on canvas height/width */
    argv1[0] = "<graph-canvas>";
    argv1[1] = "cget";
    argv1[2] = "-width";
    argc1 = 3;
    if ((canvCmd->proc)(canvCmd->clientData, interp, argc1, argv1) 
	!= TCL_OK) {
	return TCL_ERROR;
    }
    cfg.maxx = atol(Tcl_GetStringResult(interp));

    argv1[2] = "-height";
    if ((canvCmd->proc) (canvCmd->clientData, interp, argc1, argv1) 
	!= TCL_OK) {
	return TCL_ERROR;
    }
    cfg.maxy = atol(Tcl_GetStringResult(interp));
    Tcl_ResetResult(interp);
    SetLayoutConfig(*graph,cfg);
    return TCL_OK;
}

static Tcl_HashTable *
graph_table (Tcl_Interp *interp)
{
    return (Tcl_HashTable *) Tcl_GetAssocData (interp, "canvasgraph", NULL);
}

/* 
 *-------------------------------------------------------------
 *
 * GetGraphLayout --
 *      Gets graph info for canvas.  Adds a new entry if needed.
 * 
 * Results:
 *      Standard Tcl Error
 *-------------------------------------------------------------
 */

static Layout_Graph *
GetGraphLayout(canvCmd, interp)
     Tcl_CmdInfo *canvCmd;
     Tcl_Interp *interp;
{
    Tcl_HashEntry *entry;
    
    entry = Tcl_FindHashEntry(graph_table(interp), (char *)canvCmd->clientData);
    if (entry)
	return (Layout_Graph *)Tcl_GetHashValue(entry);
    
    return NULL;
}

static Layout_Graph *
GetGraphLayoutII(canvasPtr, interp)
     TkCanvas *canvasPtr;
     Tcl_Interp *interp;
{
    Tcl_HashEntry *entry;
    entry = Tcl_FindHashEntry(graph_table(interp), (char *)canvasPtr);
    if (entry)
	return (Layout_Graph *)Tcl_GetHashValue(entry);
    
    return NULL;
}

static int
GetCreatedGraphLayout(interp, canvCmd, graph)
     Tcl_Interp *interp; 
     Tcl_CmdInfo *canvCmd;
     Layout_Graph **graph;
{
    *graph = GetGraphLayout(canvCmd, interp);
    if (*graph == NULL) {
	Tcl_HashEntry *newitem;
	int new;

	/* No item, let's make one and add it to the table. */
	if (createcanvasgraph(interp, canvCmd, graph) != TCL_OK)
	    return TCL_ERROR;
	newitem = Tcl_CreateHashEntry(graph_table(interp), 
				      (char *)(canvCmd->clientData), &new);
	Tcl_SetHashValue(newitem, (ClientData) *graph);
    }
    return TCL_OK;
}

/*
 *--------------------------------------------------------------
 * 
 * GraphCanvasCmd -- 
 *      This procedure is invoked to process the new "graph"
 *      command.  This command takes a canvas and uses it to layout
 *      the canvas items with a pretty graph structure.
 *
 * Results:
 *      Standard Tcl result.
 * 
 *--------------------------------------------------------------
 */

int
GraphCanvasCmd(clientData, interp, argc, argv)
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
     char **argv;
{
    Tcl_CmdInfo canvCmd;
    size_t length;
    int c, i;
    Layout_Graph *graph;
    TkCanvas *canvasPtr;
    
    if (argc < 3) {
	Tcl_AppendResult(interp, "wrong # args: should be \"",
			 argv[0], " canvas option ?arg arg ...?\"",
			 (char *) NULL);
	return TCL_ERROR;
    }

    /* The second arg is the canvas widget */
    if (!Tcl_GetCommandInfo(interp, argv[1], &canvCmd)) {
	Tcl_AppendResult(interp, "couldn't get canvas information for \"",
			 argv[1], "\"", (char *) NULL);
	return TCL_ERROR;
    }
    canvasPtr = (TkCanvas *)(canvCmd.clientData);

    c = argv[2][0];
    length = strlen(argv[2]);
    if ((c == 'a') && (strncmp(argv[2], "add", length) == 0)) {
	char* newargv[4];
	if (argc < 4) {
	    Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0], 
			     " ", argv[1], " add tagOrId ?tagOrId ...?\"",
			     (char *) NULL);
	    goto error;
	}

	if (GetCreatedGraphLayout(interp, &canvCmd, &graph) != TCL_OK)
	    goto error;

	for (i = 3; i < argc; i++) {
	    Tk_Item *itemPtr;
	    TagSearch search;
	    /* Loop through all the items */
	    for (itemPtr = StartTagSearch(canvasPtr, argv[i], &search);
		 itemPtr != NULL; itemPtr = NextItem(&search)) {
		char* nm = itemPtr->typePtr->name;
		/* create a new edge or node */
		if(strcmp(nm,"edge") == 0) {
		    char* fname;
		    char* tname;
		    Tk_Item* f;
		    Tk_Item* t;
		    /* find the from and to node pItems */
		    if(GetEdgeNodes(interp,canvasPtr,itemPtr,&fname,&tname) != TCL_OK)
			goto error;
		    /* find the from and to node pItems */
		    f = StartTagSearch(canvasPtr, fname, &search);
		    t = StartTagSearch(canvasPtr, tname, &search);
		    ckfree(fname); ckfree(tname);
		    if(LayoutCreateEdge(graph,
					(pItem)itemPtr,
					(pItem)f, (pItem)t) != TCL_OK) {
			char* msg = LayoutGetError(graph);
			if(!msg)
			    msg = "could not record edge in graph";
			Tcl_AppendResult(interp,msg,(char*)0);
			goto error;
		    }
		} else { /* not an edge; assume a node */
		    /* verify that we can handle this */
		    char** p;
		    for(p=layableitems;*p;p++) {
			if(strcmp(*p,nm)==0) break;
		    }
		    if(!*p) {
			Tcl_AppendResult(interp,"cannot yet handle ",nm,(char*)0);
			goto error;
		    }
		    if(LayoutCreateNode(graph,
					(pItem)itemPtr,NULL,NULL) !=TCL_OK) {
			char* msg = LayoutGetError(graph);
			if(!msg)
			    msg = "could not record node in graph";
			Tcl_AppendResult(interp,msg,(char*)0);
			goto error;
		    }
		}
	    }
	}

    } else if ((c == 'c') && (strncmp(argv[2], "configure", length) == 0)) {
	    register int ok;
	    LayoutConfig cfg;
	    if (GetCreatedGraphLayout(interp, &canvCmd, &graph) != TCL_OK)
		goto error;
	    cfg = GetLayoutConfig(graph);

	    if(argc == 3) {
		/* get all options */
		ok = Tk_ConfigureInfo(interp, 
				      Tk_CanvasTkwin(*(Tk_Canvas *)canvasPtr), 
				      graphspecs,(char*)&cfg, (char*)NULL, 0);
	    } else if(argc == 4) {
		/* get one option */
		ok = Tk_ConfigureInfo(interp, 
				      Tk_CanvasTkwin(*(Tk_Canvas *)canvasPtr), 
				      graphspecs,(char*)&cfg, argv[3], 0);
	    } else { /* setting one or more options */
		ok = Tk_ConfigureWidget(interp, 
					Tk_CanvasTkwin(*(Tk_Canvas *)canvasPtr),
					graphspecs, argc-3, argv+3, 
					(char*)&cfg, TK_CONFIG_ARGV_ONLY);
		if(ok == TCL_OK) {
		    SetLayoutConfig(graph,cfg);
		}
	    }
	    if(ok != TCL_OK) goto error;
	} else if ((c == 'c') && (strncmp(argv[2], "clear", length) == 0)) {
	    /* clear graph; ignore if no graph */
	    Layout_Graph *graph = GetGraphLayout(&canvCmd, interp);
	    if (graph)
		LayoutClearGraph(graph);
	} else if ((c == 'd') && (strncmp(argv[2], "destroy", length) == 0)) {
	    /* destroy any graph info connected to the canvas,
	       but without destroying the canvas
	    */
	    Layout_Graph *graph = GetGraphLayout(&canvCmd, interp);
	    if (graph) {
		Tcl_HashEntry *entry;
		entry = Tcl_FindHashEntry(graph_table(interp),
					  (char *)(canvCmd.clientData));
		
		LayoutFreeGraph(graph);
		/* Remove hash table entry */
		Tcl_DeleteHashEntry(entry);
	    }
	} else if ((c == 'e') && (strncmp(argv[2], "edges", length) == 0)) {
	    Tk_Item* ip;
	    Layout_Graph *graph = GetGraphLayout(&canvCmd, interp);
	    /* return list of edges associated with graph, if any */
	    if(!graph) goto done;
	    for(i=0;LayoutGetIthEdge(graph,i,(pItem*)&ip)==TCL_OK;i++) {
		char convertbuffer[20];
		sprintf(convertbuffer, "%d", ip->id);
		Tcl_AppendElement(interp,convertbuffer);
	    }
	} else if ((c == 'l') && (strncmp(argv[2], "layout", length) == 0)) {
	    char* which;
	    Tk_Item* ip;
	    Layout_Graph *graph = GetGraphLayout(&canvCmd, interp);

	    if(!graph) goto done;

	    /* get the geometries of the items attached to the graph */
	    for(i=0;LayoutGetIthNode(graph,i,(pItem*)&ip)==TCL_OK;i++) {
		ItemGeom geom;
		if(getnodebbox(interp,canvasPtr,ip,&geom) != TCL_OK
		   || LayoutSetNodeBBox(graph,ip,geom) != TCL_OK) {
		    Tcl_AppendResult(interp, "could not get node location", (char *) NULL);
		    goto error;
		}
	    }
	    for(i=0;LayoutGetIthEdge(graph,i,(pItem*)&ip)==TCL_OK;i++) {
		ItemGeom geom;
		if(getedgedim(canvasPtr,ip,&geom) != TCL_OK
		   || LayoutSetEdgeDim(graph,ip,geom) != TCL_OK) {
		    Tcl_AppendResult(interp, "could not get edge location", (char *) NULL);
		    goto error;
		}
	    }

	    if(argc > 3) which = argv[3]; else which = "isi";
	    if(strcmp(which,"tree")==0) {
		if(LayoutTree(graph) == TCL_ERROR) {
		    Tcl_AppendResult(interp, "layout failed",(char *) NULL);
		    goto error;
		}
	    } else if(strcmp(which,"isi")==0) {
		if(LayoutISI(graph) == TCL_ERROR) {
		    Tcl_AppendResult(interp, "layout failed",(char *) NULL);
		    goto error;
		}
	    } else if(strcmp(which,"matrix")==0) {
		if(LayoutMatrix(graph) == TCL_ERROR) {
		    Tcl_AppendResult(interp, "layout failed",(char *) NULL);
		    goto error;
		}
	    } else if(strcmp(which,"random")==0) {
		if(LayoutRandom(graph) == TCL_ERROR) {
		    Tcl_AppendResult(interp, "layout failed",(char *) NULL);
		    goto error;
		}
	    } else {
		Tcl_AppendResult(interp, "unknown layout algorithm", which, (char *) NULL);
		goto error;
	    }
	    /* move the various items into place after layout */
	    for(i=0;LayoutGetIthNode(graph,i,(pItem*)&ip)==TCL_OK;i++) {
		ItemGeom geom;
		if(LayoutGetNodeBBox(graph,ip,&geom) != TCL_OK
		   || setnodegeom(interp,canvasPtr,ip,geom) != TCL_OK) {
		    Tcl_AppendResult(interp, "could not set node location", (char *) NULL);
		    goto error;
		}
	    }
	    for(i=0;LayoutGetIthEdge(graph,i,(pItem*)&ip)==TCL_OK;i++) {
		ItemGeom geom;
		if(LayoutGetEdgeEndPoints(graph,ip,&geom) != TCL_OK
		   || setedgegeom(interp,canvasPtr,ip,geom,i) != TCL_OK) {
		    Tcl_AppendResult(interp, "could not set edge location", (char *) NULL);
		    goto error;
		}
	    }
	} else if ((c == 'n') && (strncmp(argv[2], "nodes", length) == 0)) {
	    Tk_Item* ip;
	    Layout_Graph *graph = GetGraphLayout(&canvCmd, interp);

	    /* return list of nodes associated with graph */
	    if(!graph) goto done;
	    for(i=0;LayoutGetIthNode(graph,i,(pItem*)&ip)==TCL_OK;i++) {
		char convertbuffer[20];
		sprintf(convertbuffer, "%d", ip->id);
		Tcl_AppendElement(interp,convertbuffer);
	    }
	} else if ((c == 'r') && (strncmp(argv[2], "remove", length) == 0)) {
	    char* nm;
	    Tk_Item *itemPtr;
	    TagSearch search;
	    Layout_Graph *graph = GetGraphLayout(&canvCmd, interp);

	    if(!graph) goto done;
	    for (i = 3; i < argc; i++) {
		for (itemPtr = StartTagSearch(canvasPtr, argv[i], &search);
		     itemPtr != NULL; itemPtr = NextItem(&search)) {
		    nm = itemPtr->typePtr->name;
		    /* delete a new edge or node */
		    if(strcmp(nm,"edge") == 0) {
			(void)LayoutDeleteEdge(graph,itemPtr);
		    } else { /* not an edge; assume a node */
			(void)LayoutDeleteNode(graph,itemPtr);
		    }
		}
	    }
	} else {
	    Tcl_AppendResult(interp, "bad option \"", argv[2],
		"\":  must be add, configure, clear, ",
		"destroy, edges, layout, nodes, remove",
		(char *) NULL);  
	    goto error;
	}
 done:
    return TCL_OK;
 error:
    return TCL_ERROR;
}

/* If graph is deleted, make it go away */
static void 
delete_graph_command(ClientData clientData, Tcl_Interp *interp)
{
    Tcl_DeleteHashTable((Tcl_HashTable *) clientData);
    
    ckfree ((char*) clientData);
}

/*
 *-------------------------------------------------------------
 * GraphLayoutInit()
 *      Adds appropriate commands to Tcl interpreter, and 
 *      inits necessary tables.
 *-------------------------------------------------------------
 */
int
create_graph_command(Tcl_Interp *interp)
{
    Tcl_HashTable *graphTable= (Tcl_HashTable*)ckalloc (sizeof (Tcl_HashTable));

    Tcl_InitHashTable(graphTable, TCL_ONE_WORD_KEYS);
    
    /*
     * Create an associated data that stores the
     * hash table
     */
    Tcl_SetAssocData (interp, "canvasgraph",
                      delete_graph_command,
		      (void*) graphTable);
    
    allUid = Tk_GetUid("all");

    if (Tcl_CreateCommand(interp, "graph", GraphCanvasCmd, 
			  NULL, NULL /*delete_graph_command*/ ) == NULL)
	return TCL_ERROR;

    Tk_CreateItemType(&tkEdgeType);
   
    return TCL_OK;
}

/*
 *--------------------------------------------------------------
 *
 * StartTagSearch --
 *
 *      This procedure is called to initiate an enumeration of
 *      all items in a given canvas that contain a given tag.
 *
 * Results:
 *      The return value is a pointer to the first item in
 *      canvasPtr that matches tag, or NULL if there is no
 *      such item.  The information at *searchPtr is initialized
 *      such that successive calls to NextItem will return
 *      successive items that match tag.
 *
 * Side effects:
 *      SearchPtr is linked into a list of searches in progress
 *      on canvasPtr, so that elements can safely be deleted
 *      while the search is in progress.  EndTagSearch must be
 *      called at the end of the search to unlink searchPtr from
 *      this list.
 *
 *--------------------------------------------------------------
 */

static Tk_Item *
StartTagSearch(canvasPtr, tag, searchPtr)
     TkCanvas *canvasPtr;                /* Canvas whose items are to be
					  * searched. */
     char *tag;                          /* String giving tag value. */
     TagSearch *searchPtr;               /* Record describing tag search;
					  * will be initialized here. */
{
    int id;
    Tk_Item *itemPtr, *prevPtr;
    Tk_Uid *tagPtr;
    Tk_Uid uid;
    int count;
    
    /*
     * Initialize the search.
     */
    
    searchPtr->canvasPtr = canvasPtr;
    searchPtr->searchOver = 0;
    
    /*
     * Find the first matching item in one of several ways. If the tag
     * is a number then it selects the single item with the matching
     * identifier.  In this case see if the item being requested is the
     * hot item, in which case the search can be skipped.
     */
    
    if (isdigit(UCHAR(*tag))) {
	char *end;
	
	id = strtoul(tag, &end, 0);
	if (*end == 0) {
	    itemPtr = canvasPtr->hotPtr;
	    prevPtr = canvasPtr->hotPrevPtr;
	    if ((itemPtr == NULL) || (itemPtr->id != id) || (prevPtr == NULL)
		|| (prevPtr->nextPtr != itemPtr)) {
		for (prevPtr = NULL, itemPtr = canvasPtr->firstItemPtr;
		     itemPtr != NULL;
		     prevPtr = itemPtr, itemPtr = itemPtr->nextPtr) {
		    if (itemPtr->id == id) {
			break;
		    }
		}
	    }
	    searchPtr->prevPtr = prevPtr;
	    searchPtr->searchOver = 1;
	    canvasPtr->hotPtr = itemPtr;
	    canvasPtr->hotPrevPtr = prevPtr;
	    return itemPtr;
	}
    }
    
    searchPtr->tag = uid = Tk_GetUid(tag);
    if (uid == allUid) {
	
	/*
	 * All items match.
	 */
	
	searchPtr->tag = NULL;
	searchPtr->prevPtr = NULL;
	searchPtr->currentPtr = canvasPtr->firstItemPtr;
	return canvasPtr->firstItemPtr;
    }
    
    /*
     * None of the above.  Search for an item with a matching tag.
     */
    
    for (prevPtr = NULL, itemPtr = canvasPtr->firstItemPtr; itemPtr != NULL;
	 prevPtr = itemPtr, itemPtr = itemPtr->nextPtr) {
	for (tagPtr = itemPtr->tagPtr, count = itemPtr->numTags;
	     count > 0; tagPtr++, count--) {
	    if (*tagPtr == uid) {
		searchPtr->prevPtr = prevPtr;
		searchPtr->currentPtr = itemPtr;
		return itemPtr;
	    }
	}
    }
    searchPtr->prevPtr = prevPtr;
    searchPtr->searchOver = 1;
    return NULL;
}

/*
 *--------------------------------------------------------------
 *
 * NextItem --
 *
 *      This procedure returns successive items that match a given
 *      tag;  it should be called only after StartTagSearch has been
 *      used to begin a search.
 *
 * Results:
 *      The return value is a pointer to the next item that matches
 *      the tag specified to StartTagSearch, or NULL if no such
 *      item exists.  *SearchPtr is updated so that the next call
 *      to this procedure will return the next item.
 *
 * Side effects:
 *      None.
 *
 *--------------------------------------------------------------
 */

static Tk_Item *
NextItem(searchPtr)
     TagSearch *searchPtr;               /* Record describing search in
					  * progress. */
{
    Tk_Item *itemPtr, *prevPtr;
    int count;
    Tk_Uid uid;
    Tk_Uid *tagPtr;
    
    /*
     * Find next item in list (this may not actually be a suitable
     * one to return), and return if there are no items left.
     */
    
    prevPtr = searchPtr->prevPtr;
    if (prevPtr == NULL) {
	itemPtr = searchPtr->canvasPtr->firstItemPtr;
    } else {
	itemPtr = prevPtr->nextPtr;
    }
    if ((itemPtr == NULL) || (searchPtr->searchOver)) {
	searchPtr->searchOver = 1;
	return NULL;
    }
    if (itemPtr != searchPtr->currentPtr) {
	/*
	 * The structure of the list has changed.  Probably the
	 * previously-returned item was removed from the list.
	 * In this case, don't advance prevPtr;  just return
	 * its new successor (i.e. do nothing here).
	 */
    } else {
	prevPtr = itemPtr;
	itemPtr = prevPtr->nextPtr;
    }
    
    /*
     * Handle special case of "all" search by returning next item.
     */
    
    uid = searchPtr->tag;
    if (uid == NULL) {
	searchPtr->prevPtr = prevPtr;
	searchPtr->currentPtr = itemPtr;
	return itemPtr;
    }
    
    /*
     * Look for an item with a particular tag.
     */
    
    for ( ; itemPtr != NULL; prevPtr = itemPtr, itemPtr = itemPtr->nextPtr) {
	for (tagPtr = itemPtr->tagPtr, count = itemPtr->numTags;
	     count > 0; tagPtr++, count--) {
	    if (*tagPtr == uid) {
		searchPtr->prevPtr = prevPtr;
		searchPtr->currentPtr = itemPtr;
		return itemPtr;
	    }
	}
    }
    searchPtr->prevPtr = prevPtr;
    searchPtr->searchOver = 1;
    return NULL;
}
