// page-lcd.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "page-lcd.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

PagerUI :: PagerUI(lcd_driver& lcd)
  :lcd_drobj(lcd)
 {
   root = new Entry;
   root->next = root;
   root->prev = root;
   root->time_msg = "";
   root->id = 0;  // invalid id or only valid for root element. 

   total = 0;
   first_visible = 0;
   curr_line = 0;
   NROWS = lcd_drobj.get_numrows();
   NCOLS = lcd_drobj.get_numcols();
   // assuming lcd is already initialized by the program during its start.
   // MAKE SURE ASSUMPTION IS RIGHT
 }


// Displays message. Arrow is drawn only on the current line.
void
PagerUI :: draw_line( bool curr, int num, string msg ) 
{
  // write a text string
  lcd_drobj.send_cmd( lcd_driver::SET_AWRITE );

  if( curr )
    lcd_drobj.auto_write( 0x80 ); // prints arrow

  else
    lcd_drobj.auto_write( 0 );  // prints space

  if (num < 10)
    {
     lcd_drobj.auto_write(0); // putting a blank.
     lcd_drobj.auto_write( '0' + num - ' ' );  // prints number
    }

  else 
    { // num >= 10
     char s[3];
     sprintf (s, "%d", num);
     string string_rep(s);
     lcd_drobj.auto_write (string_rep[0] - ' ');	
     lcd_drobj.auto_write (string_rep[1] - ' ');	
    }
    lcd_drobj.auto_write( 0 ); // prints blank/space.

  for( unsigned int i=0; i < msg.size(); i++ ) 
    lcd_drobj.auto_write( msg[i] - ' ' );

  lcd_drobj.reset_auto( 8 );
}

void
PagerUI :: draw_screen() {
  int i, row;
  string msg;

  lcd_drobj.mem_set (0, 0, NROWS*NCOLS);  
  for( row=0; row<NROWS; row++ ) {
    lcd_drobj.set_word_reg( lcd_driver::SET_ADP, row*NCOLS, 0 );
				 // always points at start of line

    i = first_visible + row;

    if( row == (NROWS - 1) ) {
      if( i < (total - 1) ) { // more than 6 msgs.
	msg = "more...";

	lcd_drobj.send_cmd( lcd_driver::SET_AWRITE );

	for( unsigned c=0; c < (NCOLS - msg.size()); c++ ) 
	  lcd_drobj.auto_write( 0 );

	for( unsigned c=0; c<msg.size(); c++ ) 
	  lcd_drobj.auto_write( msg[c] - ' ' );

	lcd_drobj.reset_auto( 8 );
	break;
      }
    }

    msg = message( i );
    if( msg != "" )
      draw_line( i == curr_line, i + 1, msg );
    else {
      if( i < total ) 
	cerr << "gee - aren't there more lines to draw?" << endl;

      lcd_drobj.send_cmd( lcd_driver::SET_AWRITE );

      for( unsigned c=0; c<NCOLS; c++ ) 
	lcd_drobj.auto_write( 0 ); // printing blanks.

      lcd_drobj.reset_auto( 8 );
    }
  }
}

// Store new message.
void
PagerUI :: append( int id, string message ) {
  if( total > MAX_MSGS ) {
    cerr << " Cannot store more than 9 messages. Contact Rony or Fassi \n";
    return;
  }

  Entry *curr = new Entry;

  curr->next = root;
  curr->prev = root->prev;
  curr->id = id;
  curr->time_msg = message;

  root->prev->next = curr;
  root->prev = curr;

  ++total;
  select_line( total - 1 );
}

string
PagerUI :: remove( int index ) {
  int i;
  if ( root->next != root) {
    Entry* curr = root->next;
    string msg;

    if ( index >= total )
      return "";

    for ( i=0; i<index; i++ )
       curr = curr->next;

    msg = curr->time_msg;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;

    --total;
    if (total < 0) cerr << " total is less than zero ?? \n";
      return msg;
  }
  else {
    if (index > 0)
      cerr << " Root next is root and index > 0 \n";
    else
      cout << " Root next is root and index is  0 \n";
    return "";  
  }
}

string
PagerUI :: message( int index ) {
  int i;
  Entry* curr = root->next;

  if( index >= total )
    return "";

  for( i=0; i<index; i++ )
    curr = curr->next;

  return curr->time_msg;
}

void
PagerUI :: delete_selected() {
  string msg = remove( curr_line );

  if  (curr_line >= total) {
    if (total > 0)
      curr_line = total - 1;
    else 
      curr_line = 0;
  }
  // need to think about first visible.
  check_firstvisible();
}

void
PagerUI :: select_line( int line ) {
  curr_line = line;
  for (int i = first_visible; i < (total - 1); ++i) {
      if ( (i + (NROWS - 1)) >= (total - 1) )
        { // There is no "more" on current display
	   first_visible = i;
           break;
        }
    }
}

int
PagerUI :: current_id() {
  int i;
  Entry* curr = root->next;

  if( total == 0 )
    return 0; // changed it from -1

  for( i=0; i < curr_line; i++ )
    curr = curr->next;

  return curr->id;
}

PagerUI :: ~PagerUI() {
  while( root->next != root )
    remove( 0 );

  delete root;
}

void 
PagerUI :: up() {
  if( curr_line > 0 ) {
    --curr_line;
    check_firstvisible();
  }
}

void
PagerUI :: down() {
  if( curr_line < (total - 1) ) {
    ++curr_line;
    out_ofrange (curr_line);
  }
}


bool PagerUI :: out_ofrange (int curr_pos)
{
  if ( total > NROWS ) {
    // there are more msgs then lcd rows
    if ( (first_visible + (NROWS - 1)) < (total -1) ) { 
      // it means "more" is on display.      
      int temp = first_visible + (NROWS - 1);

      if (curr_line < temp) 
	return false;

      else {
        // Yup I am out of visible range
        first_visible += (NROWS -2); // or first_visible = temp -1
        return true;
      }
    }
    else
	return false;
  }      
  else 
    return false; // Total !> NROWS thus all msgs can be displayed.
}     

void PagerUI::check_firstvisible()
{
   if ( curr_line < first_visible)
     {
       first_visible = curr_line - (NROWS -1); 
		// Put first visible so that curr_line is last 
       if (first_visible < 0) first_visible = 0;
       else if ( (first_visible + (NROWS -1)) < (total -1) )
	 first_visible++; // because more is going to show up.
     }
}
