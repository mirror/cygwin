// rom-t6963.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

extern void init_rom( unsigned char rom[][8] );
extern void init_rom_japan( unsigned char rom[][8] );

static const int ROM_SIZE = 128 + 32;

void
init_rom_t6963c( bool use_japan_rom, unsigned char rom[][8] ) {
  int i, j;
  unsigned char *fm;
  
  for( i=0; i<ROM_SIZE; i++ )
    for( j=0; j<8; j++ ) rom[i][j] = 0;

 /* Note: the local ROM indices are offset by 32 (0x20) so that they
  *       correspond to ACSII indices.
  */
  init_rom( rom );

  if( use_japan_rom ) {
    unsigned char japanese[256][8];

    // We are over-writing stuff already in set by init_rom, so clear it out
    for( i=0x40; i<0x46; i++ )
      for( j=0; j<8; j++ ) rom[i+32][j] = 0;

    fm = &(rom[0x40 + 32][0]);
    fm[1] = 0x1;
    fm[2] = 0x1e;
    fm[3] = 0x4;
    fm[4] = 0x1f;
    fm[5] = 0x04;
    fm[6] = 0x04;

    fm = &(rom[0x41 + 32][0]);
    fm[2] = 0x1f;
    fm[3] = 0x08;
    fm[4] = 0x0f;
    fm[5] = 0x09;
    fm[6] = 0x11;

    fm = &(rom[0x42 + 32][0]);
    fm[2] = 0x1f;
    fm[3] = 0x15;
    fm[4] = 0x1f;
    fm[5] = 0x11;
    fm[6] = 0x11;
  
    fm = &(rom[0x43 + 32][0]);	// right arrow
    fm[1] = 0x4;
    fm[2] = 0x2;
    fm[3] = 0x1f;
    fm[4] = 0x2;
    fm[5] = 0x4;

    fm = &(rom[0x44 + 32][0]);	// left arrow
    fm[1] = 0x4;
    fm[2] = 0x8;
    fm[3] = 0x1f;
    fm[4] = 0x8;
    fm[5] = 0x4;

    fm = &(rom[0x45 + 32][0]);	// block
    for( i=0; i<7; i++ ) fm[i] = 0x1f;

    for( i=0; i<256; i++ )
      for( j=0; j<8; j++ ) japanese[i][j] = 0;

    init_rom_japan( japanese );

   /* This next part copies the Japanese chars from 0xa6-0xef of the 
    * HD44780U Japanese ROM to 0x46-0x7F of the local ROM.
    */
    int local;
    for( i=0xa6, local=0x46; local<0x080; i++, local++ )
      for( j=0; j<8; j++ )
	rom[local + 32][j] = japanese[i][j];
  }
  else {
    fm = &(rom[0x60 + 32][0]);
    fm[0] = 0x0f;
    fm[1] = 0x10;
    fm[2] = 0x10;
    fm[3] = 0x10;
    fm[4] = 0x0f;
    fm[5] = 0x2;
    fm[6] = 0x0e;

    fm = &(rom[0x61 + 32][0]);	// u umlaut
    fm[1] = 0x0a;
    fm[3] = 0x11;
    fm[4] = 0x11;
    fm[5] = 0x13;
    fm[6] = 0x0d;

    fm = &(rom[0x62 + 32][0]);	// e accent
    fm[0] = 2;
    fm[1] = 4;
    fm[2] = 0x0e;
    fm[3] = 0x11;
    fm[4] = 0x1f;
    fm[5] = 0x10;
    fm[6] = 0x0e;

    fm = &(rom[0x63 + 32][0]);	// a hat
    fm[0] = 0x04;
    fm[1] = 0x0a;
    fm[2] = 0x0e;
    fm[3] = 0x1;
    fm[4] = 0x0f;
    fm[5] = 0x11;
    fm[6] = 0x0f;

    fm = &(rom[0x64 + 32][0]);	// a umlaut
    fm[0] = 0x0a;
    fm[2] = 0x0e;
    fm[3] = 0x1;
    fm[4] = 0x0f;
    fm[5] = 0x11;
    fm[6] = 0x0f;

    fm = &(rom[0x65 + 32][0]);	// a grave
    fm[0] = 0x08;
    fm[1] = 4;
    fm[2] = 0x0e;
    fm[3] = 0x1;
    fm[4] = 0x0f;
    fm[5] = 0x11;
    fm[6] = 0x0f;

    fm = &(rom[0x66 + 32][0]);	// a dot
    fm[0] = 0x08;
    fm[2] = 0x0e;
    fm[3] = 0x1;
    fm[4] = 0x0f;
    fm[5] = 0x11;
    fm[6] = 0x0f;

    fm = &(rom[0x67 + 32][0]);
    fm[1] = 0x0f;
    fm[2] = 0x10;
    fm[3] = 0x10;
    fm[4] = 0x0f;
    fm[5] = 0x2;
    fm[6] = 0x0e;

    fm = &(rom[0x68 + 32][0]);	// e hat
    fm[0] = 4;
    fm[1] = 0x0a;
    fm[2] = 0x0e;
    fm[3] = 0x11;
    fm[4] = 0x1f;
    fm[5] = 0x10;
    fm[6] = 0x0e;

    fm = &(rom[0x69 + 32][0]);	// e umlaut
    fm[0] = 0x0a;
    fm[2] = 0x0e;
    fm[3] = 0x11;
    fm[4] = 0x1f;
    fm[5] = 0x10;
    fm[6] = 0x0e;

    fm = &(rom[0x6a + 32][0]);	// e grave
    fm[0] = 0x8;
    fm[1] = 4;
    fm[2] = 0x0e;
    fm[3] = 0x11;
    fm[4] = 0x1f;
    fm[5] = 0x10;
    fm[6] = 0x0e;

    fm = &(rom[0x6b + 32][0]);	// i umlaut
    for( i=3; i<6; i++ ) fm[i] = 0x4;
    fm[0] = 0x0a;
    fm[2] = 0x0c;
    fm[6] = 0x0e;

    fm = &(rom[0x6c + 32][0]);	// i hat
    for( i=0; i<6; i++ ) fm[i] = 0x4;
    fm[1] = 0x0a;
    fm[2] = 0;
    fm[3] = 0x0c;
    fm[6] = 0x0e;

    fm = &(rom[0x6d + 32][0]);	// i grave
    for( i=1; i<6; i++ ) fm[i] = 0x4;
    fm[0] = 0x08;
    fm[2] = 0;
    fm[3] = 0x0c;
    fm[6] = 0x0e;

    fm = &(rom[0x6e + 32][0]);	// A umlaut
    fm[0] = 0x0a;
    fm[2] = 0x04;
    fm[3] = 0x0a;
    fm[4] = 0x11;
    fm[5] = 0x1f;
    fm[6] = 0x11;

    fm = &(rom[0x6f + 32][0]);	// A diamond
    fm[0] = 0x04;
    fm[1] = 0x0a;
    fm[2] = 0x04;
    fm[3] = 0x0a;
    fm[4] = 0x11;
    fm[5] = 0x1f;
    fm[6] = 0x11;

    fm = &(rom[0x70 + 32][0]);	// E accent
    fm[0] = 0x02;
    fm[1] = 0x04;
    fm[2] = 0x1f;
    fm[3] = 0x10;
    fm[4] = 0x1f;
    fm[5] = 0x10;
    fm[6] = 0x1f;

    fm = &(rom[0x71 + 32][0]);
    fm[2] = 0x1a;
    fm[3] = 0x05;
    fm[4] = 0x0f;
    fm[5] = 0x14;
    fm[6] = 0x0f;

    fm = &(rom[0x72 + 32][0]);	// AE
    fm[0] = 0x0f;
    fm[1] = 0x11;
    fm[2] = 0x11;
    fm[3] = 0x1f;
    fm[4] = 0x11;
    fm[5] = 0x11;
    fm[6] = 0x17;

    fm = &(rom[0x73 + 32][0]);	// o hat
    fm[0] = 0x4;
    fm[1] = 0x0a;
    fm[3] = 0xe;
    fm[4] = 0x11;
    fm[5] = 0x11;
    fm[6] = 0xe;

    fm = &(rom[0x74 + 32][0]);	// o umlat
    fm[1] = 0x0a;
    fm[3] = 0xe;
    fm[4] = 0x11;
    fm[5] = 0x11;
    fm[6] = 0xe;

    fm = &(rom[0x75 + 32][0]);	// o grave
    fm[0] = 0x08;
    fm[1] = 0x04;
    fm[3] = 0xe;
    fm[4] = 0x11;
    fm[5] = 0x11;
    fm[6] = 0xe;

    fm = &(rom[0x76 + 32][0]);	// u hat
    fm[0] = 4;
    fm[1] = 0x0a;
    fm[3] = 0x11;
    fm[4] = 0x11;
    fm[5] = 0x13;
    fm[6] = 0x0d;

    fm = &(rom[0x77 + 32][0]);	// u grave
    fm[0] = 0x08;
    fm[1] = 0x04;
    fm[3] = 0x11;
    fm[4] = 0x11;
    fm[5] = 0x13;
    fm[6] = 0x0d;

    fm = &(rom[0x78 + 32][0]);	// y umlaut
    fm[0] = 0x0a;
    fm[2] = 0x11;
    fm[3] = 0x11;
    fm[4] = 0x0f;
    fm[5] = 0x01;
    fm[6] = 0x0e;

    fm = &(rom[0x79 + 32][0]);	// O umlaut
    for( i=0; i<6; i++ ) fm[i] = 0x11;
    fm[1] = 0x0e;
    fm[6] = 0x0e;

    fm = &(rom[0x7a + 32][0]);	// U umlaut
    for( i=2; i<6; i++ ) fm[i] = 0x11;
    fm[0] = 0x0a;
    fm[6] = 0x0e;

    fm = &(rom[0x7b + 32][0]);	// cent
    fm[0] = 0x04;
    fm[1] = 0x0f;
    fm[2] = 0x14;
    fm[3] = 0x14;
    fm[4] = 0x14;
    fm[5] = 0x0f;
    fm[6] = 0x04;

    fm = &(rom[0x7c + 32][0]);	// pound
    fm[0] = 0x06;
    fm[1] = 0x09;
    fm[2] = 0x08;
    fm[3] = 0x1e;
    fm[4] = 0x08;
    fm[5] = 0x08;
    fm[6] = 0x1f;

    fm = &(rom[0x7d + 32][0]);	// yen
    fm[0] = 0x11;
    fm[1] = 0x0a;
    fm[2] = 0x1f;
    fm[3] = 0x4;
    fm[4] = 0x1f;
    fm[5] = 0x4;
    fm[6] = 0x4;

    fm = &(rom[0x7e + 32][0]);	// Rx
    fm[0] = 0x1c;
    fm[1] = 0x12;
    fm[2] = 0x1c;
    fm[3] = 0x12;
    fm[4] = 0x17;
    fm[5] = 0x12;
    fm[6] = 0x13;

    fm = &(rom[0x7f + 32][0]);	// script f
    fm[0] = 0x2;
    fm[1] = 0x5;
    fm[2] = 0x4;
    fm[3] = 0x0e;
    fm[4] = 0x4;
    fm[5] = 0x14;
    fm[6] = 0x08;
  }
}

