// lcd-driver.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "lcd-driver.h"
#include "mem-map.h"
#include <iostream.h>

lcd_driver::lcd_driver()
  :DATA_REG (LCD_BASE + 0), CMD_REG (LCD_BASE + 1), STATUS_REG (LCD_BASE + 1)
 { }

bool
lcd_driver::check_status( unsigned char what ) 
 {
  unsigned char byte;

  byte = *STATUS_REG; 

  if ((byte & what) != what)
    {
      std::cerr << "check_status: bad status - got "
		<< std::hex << (unsigned) byte << " != " << (unsigned) what
		<< std::dec << std::endl;
      return false;
    }
  return true;
 }

bool 
lcd_driver::send_cmd( unsigned char cmd ) 
 {
  if( !check_status( STA1 | STA0 ) )
    return false;

  *CMD_REG = cmd;

  return true;
 }
  
bool
lcd_driver::reset_auto( unsigned char mode ) 
 {
  if ( !check_status( mode ) )
    return false;

  *CMD_REG = (unsigned char) CLR_AUTO_RW;
    
  return true;
 }
  
bool 
lcd_driver::send_data( unsigned char data ) 
 {
  if ( !check_status( STA1 | STA0 ) )
    return false;

  *DATA_REG = data;
  return true;
 }
  
bool 
lcd_driver::get_data( unsigned char& data ) 
 {
   if ( !check_status( STA1 | STA0 ) )
     return false;

   data = *DATA_REG;
   return true;
 }

bool 
lcd_driver::write_mem( unsigned char cmd, unsigned char val ) 
 {
   if ( !send_data( val ) )
     return false;

   if ( !send_cmd( cmd ) )
     return false;

   return true;
 }

bool 
lcd_driver::read_mem( unsigned char cmd, unsigned char& val ) 
 {
   if ( !send_cmd( cmd ) )
     return false;

   return ( get_data( val ) );
 }

bool 
lcd_driver::auto_write( unsigned char data ) 
 {
   if ( !check_status( STA3 ) )
     return false;

   *DATA_REG = data;
   return true;
 }

bool 
lcd_driver::auto_read( unsigned char& data ) 
 {
   if ( !check_status( STA2 ) )
     return false;

   data = *DATA_REG;
   return true;
 }

bool
lcd_driver::set_word_reg( unsigned char cmd, unsigned char lo, unsigned char hi ) 
 {
   if ( !send_data( lo ) )
     return false;

   if ( !send_data( hi ) )
     return false;

   if ( !send_cmd( cmd ) )
     return false;

   return true;
 }

void
lcd_driver::mem_set( unsigned char val, unsigned addr, int len ) 
 {
   set_word_reg( SET_ADP, addr & 0xff, addr >> 8 );
   send_cmd( SET_AWRITE );
 
   for ( int i=0; i<len; i++ )
      auto_write( val );

   reset_auto( 8 );
 }

/*
void initialize_lcd() {

  //intialize the display
  set_word_reg( lcd_driver::SET_TXT_HOME, 0x00, 0x00 );
  set_word_reg( SET_TXT_AREA, NCOLS, 0 );
  set_word_reg( SET_GRX_HOME, 0x00, 0x02 );
  set_word_reg( SET_GRX_AREA, NCOLS, 0 );

  // mode set: OR mode, internal cgen
  send_cmd( 0x80 );			

  // display: text on, graphics off, no cursor
  send_cmd( 0x94 );

  mem_set( 0, 0, NCOLS*NROWS );		// clear display

  set_word_reg( SET_OFFSET, 2, 0 );
  set_word_reg( SET_ADP, 0, 0x14 );	// cgen area is 0x1400

  send_cmd( SET_AWRITE );

  auto_write( 0x8 );			// initialize the arrow
  auto_write( 0xc );
  auto_write( 0xe );
  auto_write( 0xf );
  auto_write( 0xe );
  auto_write( 0xc );
  auto_write( 0x8 );
  auto_write( 0x0 );

  reset_auto( 8 );
}
*/

