// lcd-ex.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <stdio.h>

enum {
  LCD_IR = 0,
  LCD_AC = 0,
  LCD_DR = 4
};

#define LCD_BASE	0x800040	// base address for LCD

char logo[] = { 0x3, 0x4, 0x9, 0xa, 0xa, 
		0xa, 0xa, 0x9, 0x4, 0x3, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x18, 0x4, 0x13, 0x0b, 0x0, 
		0x0, 0xa, 0x13, 0x4, 0x18 };

int
main( int argc, char* argv[] ) {
  int i;
  volatile char *lcd = (volatile char*) LCD_BASE;
  char *str = "cygnus";
  char *p = str;

  lcd[LCD_IR] = 0x38;		// 2-lines, 5X8 font
  lcd[LCD_IR] = 1;		// clear display
  lcd[LCD_IR] = 0x0c;		// enable display
  lcd[LCD_IR] = 0x43;		// set AC to CGRAM char 0 line 3

  for( i=0; i<26; i++ )		// create logo	       
    lcd[LCD_DR] = logo[i];

  lcd[LCD_IR] = 0x80;		// select DDRAM address 0

  lcd[LCD_DR] = 0;		// write first line
  lcd[LCD_DR] = 2;

  while( *p )
    lcd[LCD_DR] = *p++;

  lcd[LCD_IR] = 0xc0;		// select start of second line

  lcd[LCD_DR] = 1;		// write second line
  lcd[LCD_DR] = 3;

  str = "rules!";
  p = str;

  while( *p )
    lcd[LCD_DR] = *p++;

  printf( "should see \"cygnus rules!\"\n" );
  while( 1 );
}
