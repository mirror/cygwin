// page-lcd.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef PAGER_UI_DEFH
#define PAGER_UI_DEFH

#define MAX_MSGS 20

#include "lcd-driver.h"
#include <string>

using std::string;

class PagerUI {

private:
  typedef struct entry { // Doubly link list with file id & msg (rtc time)
    struct entry *next;
    struct entry *prev;
    int id;
    string time_msg;
  } Entry;

  Entry *root;

  int total; // total number of current messages. Max is 20
  int first_visible; // first visible line number on screen
  int curr_line; // line with arrow on GUI
  lcd_driver& lcd_drobj; // Object of type lcd_driver.
  unsigned NROWS;
  unsigned NCOLS;

public:
  PagerUI(lcd_driver& lcd); // constructor
  void append( int id, string message ); //Stores new message
  void delete_selected(); // Delete selected message
  string message( int index ); // Show message (rtc time)
  void up();  
  void down();
  int current_id();
  void draw_screen();
  ~PagerUI();

 private:
  // Helper methods
  void draw_line( bool curr, int num, string msg );
  string remove( int index );
  void select_line( int line );
  bool out_ofrange (int curr_pos);
  void check_firstvisible();
};

#endif // PAGER_UI_DEFH
