// rom-5X10.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

void 
init_rom_5X10( unsigned char rom[][11] ) {
  int i, j;
  unsigned char *fm;

  for( i=0; i<32; i++ )
    for( j=0; j<11; j++ )
      rom[i][j] = 0;

  // Base char code address is 0xe0
  fm = &(rom[0][0]);	// alpha
  fm[2] = 0x09;
  fm[3] = 0x15;
  fm[4] = 0x12;
  fm[5] = 0x12;
  fm[6] = 0x0d;
  
  fm = &(rom[1][0]);
  fm[0] = 0x0a;
  fm[2] = 0x0e;
  fm[3] = 0x1;
  fm[4] = 0x0f;
  fm[5] = 0x11;
  fm[6] = 0x0f;
  
  fm = &(rom[2][0]);	// beta
  fm[2] = 0x0e;
  fm[3] = 0x11;
  fm[4] = 0x1e;
  fm[5] = 0x11;
  fm[6] = 0x1e;
  fm[7] = 0x10;
  fm[8] = 0x10;
  fm[9] = 0x10;
  
  fm = &(rom[3][0]);	// epsilon
  fm[2] = 0x0e;
  fm[3] = 0x10;
  fm[4] = 0x0c;
  fm[5] = 0x11;
  fm[6] = 0x0e;
  
  fm = &(rom[4][0]);	// mu
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x13;
  fm[6] = 0x1d;
  fm[7] = 0x10;
  fm[8] = 0x10;
  fm[9] = 0x10;
  
  fm = &(rom[5][0]);	// sigma
  fm[2] = 0x0f;
  fm[3] = 0x14;
  fm[4] = 0x12;
  fm[5] = 0x11;
  fm[6] = 0x0e;
  
  fm = &(rom[6][0]);	// rho
  fm[2] = 0x6;
  fm[3] = 0x9;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x1e;
  fm[7] = 0x10;
  fm[8] = 0x10;
  fm[9] = 0x10;
  
  fm = &(rom[7][0]);	// g
  fm[2] = 0x0f;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x0f;
  fm[7] = 0x1;
  fm[8] = 0x1;
  fm[9] = 0x0e;
  
  fm = &(rom[8][0]);	// sqrt
  fm[2] = 0x07;
  fm[3] = 0x4;
  fm[4] = 0x4;
  fm[5] = 0x14;
  fm[6] = 0x08;
  
  fm = &(rom[9][0]);	// inverse
  fm[1] = 0x02;
  fm[2] = 0x1a;
  fm[3] = 0x2;
  
  fm = &(rom[10][0]);	// j
  for( i=0; i<8; i++ ) fm[i] = 2;
  fm[1] = 0x0;
  fm[2] = 0x6;
  fm[8] = 0x12;
  fm[9] = 0x0c;
  
  fm = &(rom[11][0]);	// power x
  fm[1] = 0x14;
  fm[2] = 0x08;
  fm[3] = 0x14;
  
  fm = &(rom[12][0]);	// cent
  fm[1] = 4;
  fm[2] = 0x0e;
  fm[3] = 0x14;
  fm[4] = 0x15;
  fm[5] = 0x0e;
  fm[6] = 0x04;
  
  fm = &(rom[13][0]);	// pound
  for( i=0; i<6; i++ ) fm[i] = 8;
  fm[2] = 0x1c;
  fm[4] = 0x1c;
  fm[6] = 0x0f;

  fm = &(rom[14][0]);	// n bar
  fm[0] = 0x0e;
  fm[2] = 0x16;
  fm[3] = 0x19;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;

  fm = &(rom[15][0]);	// o umlaut
  fm[0] = 0x0a;
  fm[2] = 0x0e;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x0e;
  
  fm = &(rom[16][0]);	// p
  fm[2] = 0x16;
  fm[3] = 0x19;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x1e;
  fm[7] = 0x10;
  fm[8] = 0x10;
  fm[9] = 0x10;
  
  fm = &(rom[17][0]);	// q
  fm[2] = 0x0d;
  fm[3] = 0x13;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x0f;
  fm[7] = 0x1;
  fm[8] = 0x1;
  fm[9] = 0x1;
  
  fm = &(rom[18][0]);	// theta
  fm[1] = 0x0e;
  fm[2] = 0x11;
  fm[3] = 0x1f;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x0e;
  
  fm = &(rom[19][0]);	// infinity?
  fm[3] = 0x0b;
  fm[4] = 0x15;
  fm[5] = 0x1a;
  
  fm = &(rom[20][0]);	// ohm
  fm[2] = 0x0e;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x0a;
  fm[6] = 0x1b;
  
  fm = &(rom[21][0]);	// U umlaut
  for( i=2; i<6; i++ ) fm[i] = 0x11;
  fm[0] = 0x0a;
  fm[6] = 0x13;
  fm[7] = 0x0d;
  
  fm = &(rom[22][0]);	// Sigma
  fm[0] = 0x1f;
  fm[1] = 0x10;
  fm[2] = 0x08;
  fm[3] = 0x04;
  fm[4] = 0x08;
  fm[5] = 0x10;
  fm[6] = 0x1f;

  fm = &(rom[23][0]);	// pi
  fm[2] = 0x1f;
  fm[3] = 0x0a;
  fm[4] = 0x0a;
  fm[5] = 0x0a;
  fm[6] = 0x13;
  
  fm = &(rom[24][0]);	// x bar
  fm[0] = 0x1f;
  fm[2] = 0x11;
  fm[3] = 0x0a;
  fm[4] = 0x04;
  fm[5] = 0x0a;
  fm[6] = 0x11;

  fm = &(rom[25][0]);	// y
  for( i=2; i<6; i++ ) fm[i] = 0x11;
  fm[6] = 0x0f;
  fm[7] = 0x1;
  fm[8] = 0x1;
  fm[9] = 0x0e;
  
  fm = &(rom[26][0]);
  fm[1] = 0x1;
  fm[2] = 0x1e;
  fm[3] = 0x4;
  fm[4] = 0x1f;
  fm[5] = 0x04;
  fm[6] = 0x04;

  fm = &(rom[27][0]);
  fm[2] = 0x1f;
  fm[3] = 0x08;
  fm[4] = 0x0f;
  fm[5] = 0x09;
  fm[6] = 0x11;

  fm = &(rom[28][0]);
  fm[2] = 0x1f;
  fm[3] = 0x15;
  fm[4] = 0x1f;
  fm[5] = 0x11;
  fm[6] = 0x11;
  
  fm = &(rom[29][0]);	// divide
  fm[2] = 0x4;
  fm[3] = 0x1f;
  fm[4] = 0x4;
  
  fm = &(rom[31][0]);
  for( i=0; i<10; i++ ) fm[i] = 0x1f;
}

