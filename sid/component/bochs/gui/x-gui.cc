// x-gui.cc - SID gui front-end to the bochs vga, keyboard and mouse components.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "x-gui.h"
#include "icon_bochs.h"

#define LOG_THIS this->

/* These are used as arguments to nearly every Xlib routine, so it saves
 * routine arguments to declare them global.  If there were
 * additional source files, they would be declared extern there. */
Display *bx_x_display;
int bx_x_screen_num;
static Colormap default_cmap;
static unsigned long white_pixel=0, black_pixel=0;

static char *progname = "sid"; /* name this program was invoked by */

static int rows=25, columns=80;

static Window win;
static GC gc, gc_inv;
#if BX_SUPPORT_SID==0
static GC gc_headerbar, gc_headerbar_inv;
#endif
static XFontStruct *font_info;
static unsigned font_width, font_height;
static Bit8u blank_line[80];
static unsigned dimension_x=0, dimension_y=0;

static XImage *ximage = NULL;
static unsigned imDepth, imWide, imBPP;

// current cursor coordinates
#if BX_SUPPORT_SID==0
static int prev_x=-1, prev_y=-1;
static int current_x=-1, current_y=-1;
static unsigned mouse_button_state = 0;
#endif // BX_SUPPORT_SID
static unsigned prev_block_cursor_x=0;
static unsigned prev_block_cursor_y=0;
#if BX_SUPPORT_SID==0
static int warp_home_x = 200;
static int warp_home_y = 200;
static int mouse_enable_x = 0;
static int mouse_enable_y = 0;
static int warp_dx = 0;
static int warp_dy = 0;
static void warp_cursor(int dx, int dy);
static void disable_cursor();
static void enable_cursor();
#endif // BX_SUPPORT_SID

Bit32u ascii_to_key_event[0x5f] = {
  //  !"#$%&'
  BX_KEY_SPACE,
  BX_KEY_1,
  BX_KEY_SINGLE_QUOTE,
  BX_KEY_3,
  BX_KEY_4,
  BX_KEY_5,
  BX_KEY_7,
  BX_KEY_SINGLE_QUOTE,

  // ()*+,-./
  BX_KEY_9,
  BX_KEY_0,
  BX_KEY_8,
  BX_KEY_EQUALS,
  BX_KEY_COMMA,
  BX_KEY_MINUS,
  BX_KEY_PERIOD,
  BX_KEY_SLASH,

  // 01234567
  BX_KEY_0,
  BX_KEY_1,
  BX_KEY_2,
  BX_KEY_3,
  BX_KEY_4,
  BX_KEY_5,
  BX_KEY_6,
  BX_KEY_7,

  // 89:;<=>?
  BX_KEY_8,
  BX_KEY_9,
  BX_KEY_SEMICOLON,
  BX_KEY_SEMICOLON,
  BX_KEY_COMMA,
  BX_KEY_EQUALS,
  BX_KEY_PERIOD,
  BX_KEY_SLASH,

  // @ABCDEFG
  BX_KEY_2,
  BX_KEY_A,
  BX_KEY_B,
  BX_KEY_C,
  BX_KEY_D,
  BX_KEY_E,
  BX_KEY_F,
  BX_KEY_G,


  // HIJKLMNO
  BX_KEY_H,
  BX_KEY_I,
  BX_KEY_J,
  BX_KEY_K,
  BX_KEY_L,
  BX_KEY_M,
  BX_KEY_N,
  BX_KEY_O,


  // PQRSTUVW
  BX_KEY_P,
  BX_KEY_Q,
  BX_KEY_R,
  BX_KEY_S,
  BX_KEY_T,
  BX_KEY_U,
  BX_KEY_V,
  BX_KEY_W,

  // XYZ[\]^_
  BX_KEY_X,
  BX_KEY_Y,
  BX_KEY_Z,
  BX_KEY_LEFT_BRACKET,
  BX_KEY_BACKSLASH,
  BX_KEY_RIGHT_BRACKET,
  BX_KEY_6,
  BX_KEY_MINUS,

  // `abcdefg
  BX_KEY_GRAVE,
  BX_KEY_A,
  BX_KEY_B,
  BX_KEY_C,
  BX_KEY_D,
  BX_KEY_E,
  BX_KEY_F,
  BX_KEY_G,

  // hijklmno
  BX_KEY_H,
  BX_KEY_I,
  BX_KEY_J,
  BX_KEY_K,
  BX_KEY_L,
  BX_KEY_M,
  BX_KEY_N,
  BX_KEY_O,

  // pqrstuvw
  BX_KEY_P,
  BX_KEY_Q,
  BX_KEY_R,
  BX_KEY_S,
  BX_KEY_T,
  BX_KEY_U,
  BX_KEY_V,
  BX_KEY_W,

  // xyz{|}~
  BX_KEY_X,
  BX_KEY_Y,
  BX_KEY_Z,
  BX_KEY_LEFT_BRACKET,
  BX_KEY_BACKSLASH,
  BX_KEY_RIGHT_BRACKET,
  BX_KEY_GRAVE
};

unsigned long col_vals[256]; // 256 VGA colors
unsigned curr_foreground, curr_background;

x_gui::x_gui ()
    : init_pin(this, & x_gui::init),
      handle_events_pin(this, & x_gui::handle_events),
      update_display_pin(this, & x_gui::update_display),
      palette_change_index_pin(this, & x_gui::palette_change_index),
      x_tilesize(16), y_tilesize(16),
      font_name("-b&h-lucidux mono-medium-r-normal--15-140-75-75-m-90-iso8859-15"),
      private_colormap(false)
{
  add_pin("generate-scancode", & this->generate_scancode_pin);

  add_pin("init", & this->init_pin);
  add_pin("handle-events", & this->handle_events_pin);
  add_pin("update-display", & this->update_display_pin);
  
  add_pin("text-memory-updated", & this->text_memory_updated_pin);
  add_pin("text-start-address", & this->text_start_address_pin);
  add_pin("text-cursor-x", & this->text_cursor_x_pin);
  add_pin("text-cursor-y", & this->text_cursor_y_pin);

  add_pin("dimension-width", & this->dimension_width_pin);
  add_pin("dimension-height", & this->dimension_height_pin);
  add_pin("dimensions-updated", & this->dimensions_updated_pin);

  add_pin("palette-change-index", & this->palette_change_index_pin);

  add_attribute("font-name", & this->font_name, "setting");
  add_attribute("private-colormap?", & this->private_colormap, "setting");
}

void
x_gui::init(host_int_4)
{
  unsigned i;
  int x, y;   /* window position */
  unsigned int border_width = 4;  /* four pixels */
#if BX_CPU_LEVEL < 2
  char *window_name = "SID Import of the Bochs 8086 Emulator";
#elif BX_CPU_LEVEL == 2
  char *window_name = "SID Import of the Bochs 80286 Emulator";
#elif BX_CPU_LEVEL == 3
  char *window_name = "SID Import of the Bochs 80386 Emulator";
#elif BX_CPU_LEVEL == 4
  char *window_name = "SID Import of the Bochs 80486 Emulator";
#else
  char *window_name = "SID Import of the Bochs Pentium Emulator";
#endif
  char *icon_name = "SID Bochs";
  Pixmap icon_pixmap;
  XSizeHints size_hints;
  char *display_name = NULL;
  /* create GC for text and drawing */
  unsigned long valuemask = 0; /* ignore XGCvalues and use defaults */
  XGCValues values;
  Visual  *default_visual;
  int      default_depth;
  XEvent report;
  XSetWindowAttributes win_attr;
  unsigned long plane_masks_return[1];
  XColor color;
#if BX_SUPPORT_SID==0  
  th->setprefix("[XGUI]");
  UNUSED(th);
#endif

  if (bx_options.private_colormap) {
    BX_ERROR(( "private_colormap option not handled yet.\n" ));
  }
#if BX_SUPPORT_SID==0
  x_tilesize = tilewidth;
  y_tilesize = tileheight;
  bx_headerbar_y = headerbar_y;
#endif
  for (i=0; i<80; i++) {
    blank_line[i] = ' ';
    }
#if BX_SUPPORT_SID==0
  progname = argv[0];
#endif
  /* connect to X server */
  if ( (bx_x_display=XOpenDisplay(display_name)) == NULL )
  {
    BX_PANIC(("%s: cannot connect to X server %s\n",
        progname, XDisplayName(display_name)));
  }

  /* get screen size from display structure macro */
  bx_x_screen_num = DefaultScreen(bx_x_display);

  /* Note that in a real application, x and y would default to 0
   * but would be settable from the command line or resource database.
   */
  x = y = 0;


  load_font();

  font_width = font_info->max_bounds.width;
  font_height = (font_info->max_bounds.ascent +
                 font_info->max_bounds.descent);

  dimension_x = columns * font_width;
  dimension_y = rows * font_height;


  BX_INFO(("font %u wide x %u high\n", (unsigned) font_width, (unsigned) font_height));

  /* create opaque window */
  win = XCreateSimpleWindow(bx_x_display, RootWindow(bx_x_display,bx_x_screen_num),
    x, y,
    dimension_x,
    dimension_y,
    border_width,
    BlackPixel(bx_x_display, bx_x_screen_num),
    BlackPixel(bx_x_display, bx_x_screen_num));

  // (attempt to) enable backing store
  win_attr.save_under=1;
  win_attr.backing_store=Always;
  XChangeWindowAttributes(bx_x_display,win,CWSaveUnder|CWBackingStore,&win_attr);

  default_depth  = DefaultDepth(bx_x_display, bx_x_screen_num);
  default_visual = DefaultVisual(bx_x_display, bx_x_screen_num);

  if (bx_options.private_colormap) {
    default_cmap = XCreateColormap(bx_x_display, DefaultRootWindow(bx_x_display),
                                   default_visual, AllocNone);
    if (XAllocColorCells(bx_x_display, default_cmap, False,
                         plane_masks_return, 0, col_vals, 256) == 0) {
      BX_PANIC(("XAllocColorCells returns error.\n"));
    }
    
    win_attr.colormap = default_cmap;
    XChangeWindowAttributes(bx_x_display, win, CWColormap, &win_attr);
    
    color.flags = DoRed | DoGreen | DoBlue;
    
    for (i=0; i < 256; i++) {
      color.pixel = i;
      if (i==15) {
        color.red   = 0xffff;
        color.green = 0xffff;
        color.blue  = 0xffff;
        }
      else {
        color.red   = 0;
        color.green = 0;
        color.blue  = 0;
        }
      XStoreColor(bx_x_display, default_cmap, &color);
      }
    }
  else {
    default_cmap = DefaultColormap(bx_x_display, bx_x_screen_num);
    col_vals[0]  = BlackPixel(bx_x_display, bx_x_screen_num);
    col_vals[15] = WhitePixel(bx_x_display, bx_x_screen_num);
    for (i = 1; i < 256; i++) {
      if (i==15) continue;
      col_vals[i] = col_vals[0];
    }
  }
  
  // convenience variables which hold the black & white color indeces
  black_pixel = col_vals[0];
  white_pixel = col_vals[15];
  
  BX_INFO(("default_depth = %d\n", default_depth));

  //select_visual();


  /* Get available icon sizes from Window manager */

  /* Create pixmap of depth 1 (bitmap) for icon */
  icon_pixmap = XCreateBitmapFromData(bx_x_display, win,
                                      (char *) bochs_icon_bits, bochs_icon_width, bochs_icon_height);
  
  /* Set size hints for window manager.  The window manager may
   * override these settings.  Note that in a real
   * application if size or position were set by the user
   * the flags would be UPosition and USize, and these would
   * override the window manager's preferences for this window. */
  /* x, y, width, and height hints are now taken from
   * the actual settings of the window when mapped. Note
   * that PPosition and PSize must be specified anyway. */
  
  size_hints.flags = PPosition | PSize | PMinSize | PMaxSize;
  size_hints.max_width = size_hints.min_width = dimension_x;
  size_hints.max_height = size_hints.min_height = dimension_y;
  
  {
    XWMHints wm_hints;
    XClassHint class_hints;
    
    /* format of the window name and icon name
     * arguments has changed in R4 */
    XTextProperty windowName, iconName;
    
    /* These calls store window_name and icon_name into
     * XTextProperty structures and set their other
     * fields properly. */
    if (XStringListToTextProperty(&window_name, 1, &windowName) == 0) {
      BX_PANIC(("%s: structure allocation for windowName failed.\n",
                progname));
    }
    
    if (XStringListToTextProperty(&icon_name, 1, &iconName) == 0) {
      BX_PANIC(("%s: structure allocation for iconName failed.\n",
                progname));
    }
    
    wm_hints.initial_state = NormalState;
    wm_hints.input = True;
    wm_hints.icon_pixmap = icon_pixmap;
    wm_hints.flags = StateHint | IconPixmapHint | InputHint;
    
    class_hints.res_name = progname;
    class_hints.res_class = "Bochs";
#if BX_SUPPORT_SID
    XSetWMProperties(bx_x_display, win, &windowName, &iconName,
                     0, 0, &size_hints, &wm_hints,
                     &class_hints);
#else
    XSetWMProperties(bx_x_display, win, &windowName, &iconName,
                     argv, argc, &size_hints, &wm_hints,
                     &class_hints);
#endif
  }
    
  /* Select event types wanted */
  XSelectInput(bx_x_display, win, ExposureMask | KeyPressMask | KeyReleaseMask |
               ButtonPressMask | ButtonReleaseMask | StructureNotifyMask | PointerMotionMask |
               EnterWindowMask | LeaveWindowMask );
    
  
  /* Create default Graphics Context */
  gc               = XCreateGC(bx_x_display, win, valuemask, &values);
  gc_inv           = XCreateGC(bx_x_display, win, valuemask, &values);
#if BX_SUPPORT_SID==0
  gc_headerbar     = XCreateGC(bx_x_display, win, valuemask, &values);
  gc_headerbar_inv = XCreateGC(bx_x_display, win, valuemask, &values);
#endif
  
  /* specify font */
  XSetFont(bx_x_display, gc, font_info->fid);
  
  XSetState(bx_x_display, gc, white_pixel, black_pixel, GXcopy,AllPlanes);
  
  XSetState(bx_x_display, gc_inv, black_pixel, white_pixel, GXcopy,AllPlanes);
#if BX_SUPPORT_SID==0
  XSetState(bx_x_display, gc_headerbar, black_pixel, white_pixel, GXcopy,AllPlanes);
  
  XSetState(bx_x_display, gc_headerbar_inv, white_pixel, black_pixel, GXcopy,AllPlanes);
#endif
  
  /* Display window */
  XMapWindow(bx_x_display, win);
  XSync(bx_x_display, /* no discard */ 0);
  
  BX_INFO(("waiting for MapNotify\n"));
  while (1) {
    XNextEvent(bx_x_display, &report);
    if (report.type == MapNotify) break;
  }
  BX_INFO(("MapNotify found.\n"));
  
  {
    char *imagedata;
    
    ximage = XCreateImage(bx_x_display, default_visual,
                          default_depth,          // depth of image (bitplanes)
                          ZPixmap,
                          0,                      // offset
                          NULL,                   // malloc() space after
                          x_tilesize, y_tilesize, // x & y size of image
                          32,                     // # bits of padding
                          0 );                    // bytes_per_line, let X11 calculate
    if (!ximage)
      BX_PANIC(("vga: couldn't XCreateImage()\n"));
    
    imDepth = default_depth;
    imWide  = ximage->bytes_per_line;
    imBPP   = ximage->bits_per_pixel;
    
    imagedata = (char *) malloc( (size_t) (ximage->bytes_per_line * y_tilesize) );
    if (!imagedata) BX_PANIC(("imagedata: malloc returned error\n"));
    
    ximage->data = imagedata;
    
    if (imBPP < imDepth) {
      BX_PANIC(("vga_x: bits_per_pixel < depth ?\n"));
    }
    
  }
  
  curr_background = 0;
  XSetBackground(bx_x_display, gc, col_vals[curr_background]);
  curr_foreground = 1;
  XSetForeground(bx_x_display, gc, col_vals[curr_foreground]);
  //XGrabPointer( bx_x_display, win, True, 0, GrabModeAsync, GrabModeAsync,
  //  win, None, CurrentTime );
  
  
  XFlush(bx_x_display);

  vga_memory = this->buffer;
  palette_memory = (struct rgb_data *)(& vga_memory[0x20000]);
}

void
x_gui::handle_events(host_int_4)
{
  XEvent report;
  XKeyEvent *key_event;
  KeySym keysym;
  XComposeStatus compose;
  char buffer[MAX_MAPPED_STRING_LENGTH];
  int bufsize = MAX_MAPPED_STRING_LENGTH;
  int charcount;
  Boolean mouse_update;

  XPointerMovedEvent *pointer_event;
  XEnterWindowEvent *enter_event;
  XLeaveWindowEvent *leave_event;
  XButtonEvent *button_event;
  XExposeEvent *expose_event;

  //current_x = -1;
  //current_y = -1;
  mouse_update = 0;

  while (XPending(bx_x_display) > 0)
    {
      XNextEvent(bx_x_display, &report);
      switch(report.type)
        {
        case Expose:
          /* unless this is the last contiguous expose,
           * don't draw the window */
          expose_event = (XExposeEvent *) &report;
          
          redraw_area((unsigned) expose_event->x,
                      (unsigned) expose_event->y,
                      (unsigned) expose_event->width,
                      (unsigned) expose_event->height);
          break;

        case KeyPress:
          key_event = (XKeyEvent *) &report;
          charcount = XLookupString(key_event, buffer, bufsize, &keysym, &compose);
          xkeypress(keysym, 0);
          break;
          
        case KeyRelease:
          key_event = (XKeyEvent *) &report;
          charcount = XLookupString(key_event, buffer, bufsize, &keysym, &compose);
          xkeypress(keysym, 1);
          break;
        }
    }
}

void
x_gui::update_display(host_int_4)
{
  if (dimensions_updated_pin.sense())
    {
      host_int_4 x;
      host_int_4 y;
      // ASSUMING TEXT MODE!
      columns = dimension_width_pin.sense();
      rows = dimension_height_pin.sense();
      
      x = columns * font_width;
      y = rows * font_height;
      
      if ((x != dimension_x) || (y != (dimension_y)))
        {
          XSizeHints hints;
          long supplied_return;
          
          if ( XGetWMNormalHints(bx_x_display, win, &hints, &supplied_return) &&
               supplied_return & PMaxSize ) {
            hints.max_width = hints.min_width = x;
            hints.max_height = hints.min_height = y;
            XSetWMNormalHints(bx_x_display, win, &hints);
          }
          XResizeWindow(bx_x_display, win, x, y);
          dimension_x = x;
          dimension_y = y;
        }
      dimensions_updated_pin.driven(0);
    }

  if (text_memory_updated_pin.sense())
    {
      // Assume Text Mode for Now...
      int font_height;
      unsigned i, x, y, curs;
      unsigned new_foreground, new_background;
      Bit8u string[1];
      unsigned nchars;
      
      host_int_4 start_address = text_start_address_pin.sense();
      host_int_4 cursor_x = text_cursor_x_pin.sense();
      host_int_4 cursor_y = text_cursor_y_pin.sense();
      host_int_4 nrows = dimension_height_pin.sense();
      
      host_int_1 *old_text = text_snapshot;
      host_int_1 *new_text = & vga_memory[start_address];

      font_height = font_info->ascent + font_info->descent;
      
      // Number of characters on screen, variable number of rows
      nchars = 80*nrows;
      
      // first draw over character at original block cursor location
      if ( (prev_block_cursor_y*80 + prev_block_cursor_x) < nchars )
        {
          curs = (prev_block_cursor_y*80 + prev_block_cursor_x)*2;
          string[0] = new_text[curs];
          XSetBackground(bx_x_display, gc, col_vals[(new_text[curs+1] & 0xf0) >> 4]);
          
          XDrawImageString(bx_x_display, win,
                           gc,
                           prev_block_cursor_x * font_info->max_bounds.width,
                           prev_block_cursor_y * font_height + font_info->max_bounds.ascent,
                           (char *) string,
                           1);
        }
      
      for (i=0; i<nchars*2; i+=2)
        {
          if ((old_text[i]!=new_text[i]) || (old_text[i+1]!=new_text[i+1]))
            {
              string[0] = new_text[i];
              if (string[0] == 0) string[0] = ' '; // convert null to space
              new_foreground = new_text[i+1] & 0x0f;
              new_background = (new_text[i+1] & 0xf0) >> 4;
              
              XSetForeground(bx_x_display, gc, col_vals[new_foreground]);
              XSetBackground(bx_x_display, gc, col_vals[new_background]);
              
              //XSetForeground(bx_x_display, gc, white_pixel);
              //XSetBackground(bx_x_display, gc, black_pixel);
              
              x = (i/2) % 80;
              y = (i/2) / 80;
              
              XDrawImageString(bx_x_display, win,
                               gc,
                               x * font_info->max_bounds.width,
                               y * font_height + font_info->max_bounds.ascent,
                               (char *) string,
                               1);
              old_text[i] = new_text[i];
              old_text[i+1] = new_text[i+1];
            }
        }
      
      prev_block_cursor_x = cursor_x;
      prev_block_cursor_y = cursor_y;
      
      XSetForeground(bx_x_display, gc, white_pixel);
      XSetBackground(bx_x_display, gc, black_pixel);
      
      // now draw character at new block cursor location in reverse
      if ((cursor_y * 80 + cursor_x) < nchars)
        {
          string[0] = new_text[(cursor_y * 80 + cursor_x) * 2];
          
          XDrawImageString(bx_x_display, win,
                           gc_inv,
                           cursor_x * font_info->max_bounds.width,
                           cursor_y * font_height + font_info->max_bounds.ascent,
                           (char *) string,
                           1);
        }
      text_memory_updated_pin.driven(0);
    }
}

void
x_gui::palette_change_index(host_int_4 index)
{
  XColor color;

  host_int_1 red = palette_memory[index].red;
  host_int_1 green = palette_memory[index].green;
  host_int_1 blue = palette_memory[index].blue;

  color.flags = DoRed | DoGreen | DoBlue;
  color.red   = red << 10;
  color.green = green << 10;
  color.blue  = blue << 10;
  
  if (private_colormap)
    {
      color.pixel = index;
      XStoreColor(bx_x_display, default_cmap, &color);
      text_memory_updated_pin.driven(0); // no screen update needed
    }
  else
    {
      XAllocColor(bx_x_display, DefaultColormap(bx_x_display, bx_x_screen_num),
                  &color);
      col_vals[index] = color.pixel;
      text_memory_updated_pin.driven(1); // screen update needed
    }
}

void
x_gui::redraw_area(unsigned x0, unsigned y0, unsigned width, unsigned height)
{
  // Assume Text Mode For Now
  memset(text_snapshot, 0,
         sizeof(text_snapshot));
  text_memory_updated_pin.driven(1);
}

  void
x_gui::xkeypress(KeySym keysym, int press_release)
{
  Bit32u key_event;

  // this depends on the fact that the X11 keysyms which
  // correspond to the ascii characters space .. tilde
  // are in consequtive order.
  if ((keysym >= XK_space) && (keysym <= XK_asciitilde)) {
    key_event = ascii_to_key_event[keysym - XK_space];
    }
  else switch (keysym) {
    case XK_KP_1:
#ifdef XK_KP_End
    case XK_KP_End:
#endif
      key_event = BX_KEY_KP_END; break;

    case XK_KP_2:
#ifdef XK_KP_Down
    case XK_KP_Down:
#endif
      key_event = BX_KEY_KP_DOWN; break;

    case XK_KP_3:
#ifdef XK_KP_Page_Down
    case XK_KP_Page_Down:
#endif
      key_event = BX_KEY_KP_PAGE_DOWN; break;

    case XK_KP_4:
#ifdef XK_KP_Left
    case XK_KP_Left:
#endif
      key_event = BX_KEY_KP_LEFT; break;

    case XK_KP_5:
      key_event = BX_KEY_KP_5; break;

    case XK_KP_6:
#ifdef XK_KP_Right
    case XK_KP_Right:
#endif
      key_event = BX_KEY_KP_RIGHT; break;

    case XK_KP_7:
#ifdef XK_KP_Home
    case XK_KP_Home:
#endif
      key_event = BX_KEY_KP_HOME; break;

    case XK_KP_8:
#ifdef XK_KP_Up
    case XK_KP_Up:
#endif
      key_event = BX_KEY_KP_UP; break;

    case XK_KP_9:
#ifdef XK_KP_Page_Up
    case XK_KP_Page_Up:
#endif
      key_event = BX_KEY_KP_PAGE_UP; break;

    case XK_KP_0:
#ifdef XK_KP_Insert
    case XK_KP_Insert:
      key_event = BX_KEY_KP_INSERT; break;
#endif

    case XK_KP_Decimal:
#ifdef XK_KP_Delete
    case XK_KP_Delete:
      key_event = BX_KEY_KP_DELETE; break;
#endif

#ifdef XK_KP_Enter
    case XK_KP_Enter:
      key_event = BX_KEY_KP_ENTER; break;
#endif

    case XK_KP_Subtract: key_event = BX_KEY_KP_SUBTRACT; break;
    case XK_KP_Add:      key_event = BX_KEY_KP_ADD; break;

    case XK_KP_Multiply: key_event = BX_KEY_KP_MULTIPLY; break;
    case XK_KP_Divide:   key_event = BX_KEY_KP_DIVIDE; break;


    case XK_Up:          key_event = BX_KEY_UP; break;
    case XK_Down:        key_event = BX_KEY_DOWN; break;
    case XK_Left:        key_event = BX_KEY_LEFT; break;
    case XK_Right:       key_event = BX_KEY_RIGHT; break;


    case XK_Delete:      key_event = BX_KEY_DELETE; break;
    case XK_BackSpace:   key_event = BX_KEY_BACKSPACE; break;
    case XK_Tab:         key_event = BX_KEY_TAB; break;
    case XK_Return:      key_event = BX_KEY_ENTER; break;
    case XK_Escape:      key_event = BX_KEY_ESC; break;
    case XK_F1:          key_event = BX_KEY_F1; break;
    case XK_F2:          key_event = BX_KEY_F2; break;
    case XK_F3:          key_event = BX_KEY_F3; break;
    case XK_F4:          key_event = BX_KEY_F4; break;
    case XK_F5:          key_event = BX_KEY_F5; break;
    case XK_F6:          key_event = BX_KEY_F6; break;
    case XK_F7:          key_event = BX_KEY_F7; break;
    case XK_F8:          key_event = BX_KEY_F8; break;
    case XK_F9:          key_event = BX_KEY_F9; break;
    case XK_F10:         key_event = BX_KEY_F10; break;
    case XK_F11:         key_event = BX_KEY_F11; break;
    case XK_F12:         key_event = BX_KEY_F12; break;
    case XK_Control_L:   key_event = BX_KEY_CTRL_L; break;
    case XK_Shift_L:     key_event = BX_KEY_SHIFT_L; break;
    case XK_Shift_R:     key_event = BX_KEY_SHIFT_R; break;
    case XK_Caps_Lock:   key_event = BX_KEY_CAPS_LOCK; break;
    case XK_Num_Lock:    key_event = BX_KEY_NUM_LOCK; break;
    case XK_Alt_L:       key_event = BX_KEY_ALT_L; break;

    case XK_Insert:      key_event = BX_KEY_INSERT; break;
    case XK_Home:        key_event = BX_KEY_HOME; break;
    case XK_End:         key_event = BX_KEY_END; break;
    case XK_Page_Up:     key_event = BX_KEY_PAGE_UP; break;
    case XK_Page_Down:   key_event = BX_KEY_PAGE_DOWN; break;

    default:
      BX_ERROR(( "xkeypress(): keysym %x unhandled!\n", (unsigned) keysym ));
      return;
      break;
    }

  if (press_release)
    key_event |= BX_KEY_RELEASED;

  generate_scancode_pin.drive(key_event);
}

void
x_gui::load_font(void)
{
  /* Load font and get font information structure. */
  /* "-b&h-lucidux mono-medium-r-normal--15-140-75-75-m-90-iso8859-15" works well */
  if ((font_info = XLoadQueryFont(bx_x_display, font_name.c_str())) == NULL) {
    BX_PANIC(("Could not open vga font\n"));
  }
}
