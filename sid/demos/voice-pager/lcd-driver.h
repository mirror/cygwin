// lcd-driver.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef LCD_DRIVER_DEFH
#define LCD_DRIVER_DEFH

class lcd_driver 
 {

 private:
    volatile unsigned char* const DATA_REG;
    volatile unsigned char* const CMD_REG;
    volatile unsigned char* const STATUS_REG;

   enum lcd_status
    {		// status byte
      STA0	= 0x1,	// set if ready to take next command
      STA1	= 0x2,	// set if memory ready
      STA2	= 0x4,	// set if auto read
      STA3	= 0x8,	// set if auto write
      STA6	= 0x40,	// set if peek/poke error
      STA7	= 0x80,	// set if display on
    };
    
    enum lcd_size 
     {
       NCOLS = 32,
       NROWS =  6
     };

 public: 
   enum lcd_cmds 
    {
      SET_CURSOR	= 0x21,
      SET_OFFSET	= 0x22,
      SET_ADP		= 0x24,
      SET_TXT_HOME	= 0x40,
      SET_TXT_AREA	= 0x41,
      SET_GRX_HOME	= 0x42,
      SET_GRX_AREA	= 0x43,
      SET_AWRITE	= 0xb0,
      SET_AREAD		= 0xb1,
      CLR_AUTO_RW	= 0xb2,
      DWRITE_INC	= 0xc0,
      DREAD_INC		= 0xc1,
      DWRITE_DEC	= 0xc2,
      DREAD_DEC		= 0xc3,
      DWRITE		= 0xc4,
      DREAD		= 0xc5
   };

   lcd_driver();
   bool send_cmd( unsigned char cmd );

   bool auto_write( unsigned char data );
   bool auto_read( unsigned char& data );
   bool reset_auto( unsigned char mode );

   bool write_mem( unsigned char cmd, unsigned char data );
   bool read_mem( unsigned char cmd, unsigned char& data );

   bool set_word_reg( unsigned char cmd, unsigned char lo, unsigned char hi );
   void mem_set( unsigned char val, unsigned addr, int len );
   unsigned get_numcols() { return NCOLS;}
   unsigned get_numrows() { return NROWS;}
   //   void initialize_lcd();


 private:
   bool check_status( unsigned char what );
   bool send_data( unsigned char data );
   bool get_data ( unsigned char& data );

 };

#endif // LCD_DRIVER_DEFH
