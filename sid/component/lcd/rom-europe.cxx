// rom-europe.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

void 
init_rom_europe( unsigned char rom[][8] ) {
  int i, j;
  unsigned char *fm;

  fm = &(rom[0x10][0]);
  fm[1] = 0x08;
  fm[2] = 0x0c;
  fm[3] = 0x0e;
  fm[4] = 0x0f;
  fm[5] = 0x0e;
  fm[6] = 0x0c;
  fm[7] = 0x08;

  fm = &(rom[0x11][0]);
  fm[1] = 0x02;
  fm[2] = 0x06;
  fm[3] = 0x0e;
  fm[4] = 0x1e;
  fm[5] = 0x0e;
  fm[6] = 0x06;
  fm[7] = 0x02;

  fm = &(rom[0x12][0]);
  fm[1] = 0x09;
  fm[2] = 0x12;
  fm[3] = 0x1b;

  fm = &(rom[0x13][0]);
  fm[1] = 0x1b;
  fm[2] = 0x09;
  fm[3] = 0x12;

  fm = &(rom[0x14][0]);
  fm[1] = 0x04;
  fm[2] = 0x0e;
  fm[3] = 0x1f;
  fm[5] = 0x04;
  fm[6] = 0x0e;
  fm[7] = 0x1f;

  fm = &(rom[0x15][0]);
  fm[1] = 0x1f;
  fm[2] = 0x0e;
  fm[3] = 0x04;
  fm[5] = 0x1f;
  fm[6] = 0x0e;
  fm[7] = 0x04;

  fm = &(rom[0x16][0]);
  fm[2] = 0x0e;
  fm[3] = 0x1f;
  fm[4] = 0x1f;
  fm[5] = 0x1f;
  fm[6] = 0x0e;

  fm = &(rom[0x17][0]);
  fm[1] = 0x01;
  fm[2] = 0x01;
  fm[3] = 0x05;
  fm[4] = 0x09;
  fm[5] = 0x1f;
  fm[6] = 0x08;
  fm[7] = 0x04;

  fm = &(rom[0x18][0]);
  fm[1] = 0x04;
  fm[2] = 0x0e;
  fm[3] = 0x15;
  for( i=4; i<8; i++ ) fm[i] = 4;

  fm = &(rom[0x19][0]);
  for( i=1; i<5; i++ ) fm[i] = 4;
  fm[5] = 0x15;
  fm[6] = 0x0e;
  fm[7] = 0x4;

  fm = &(rom[0x1a][0]);
  fm[2] = 0x04;
  fm[3] = 0x02;
  fm[4] = 0x1f;
  fm[5] = 0x02;
  fm[6] = 0x04;

  fm = &(rom[0x1b][0]);
  fm[2] = 0x04;
  fm[3] = 0x08;
  fm[4] = 0x1f;
  fm[5] = 0x08;
  fm[6] = 0x04;

  fm = &(rom[0x1c][0]);
  fm[1] = 0x02;
  fm[2] = 0x04;
  fm[3] = 0x08;
  fm[4] = 0x04;
  fm[5] = 0x02;
  fm[7] = 0x1f;

  fm = &(rom[0x1d][0]);
  fm[1] = 0x08;
  fm[2] = 0x04;
  fm[3] = 0x02;
  fm[4] = 0x04;
  fm[5] = 0x08;
  fm[7] = 0x1f;

  fm = &(rom[0x1e][0]);
  fm[2] = 0x04;
  fm[3] = 0x04;
  fm[4] = 0x0e;
  fm[5] = 0x0e;
  fm[6] = 0x1f;

  fm = &(rom[0x1f][0]);
  fm[2] = 0x1f;
  fm[3] = 0x0e;
  fm[4] = 0x0e;
  fm[5] = 0x04;
  fm[6] = 0x04;

  fm = &(rom['!'][0]);
  for( i=1; i<5; i++ ) fm[i] = 4;
  fm[7] = 4;

  fm = &(rom['"'][0]);
  for( i=1; i<4; i++ ) fm[i] = 0xa;

  fm = &(rom['#'][0]);
  for( i=1; i<8; i++ ) fm[i] = 0xa;
  fm[3] = 0x1f;
  fm[5] = 0x1f;

  fm = &(rom['$'][0]);
  fm[1] = 0x4;
  fm[2] = 0x0f;
  fm[3] = 0x14;
  fm[4] = 0xe;
  fm[5] = 0x5;
  fm[6] = 0x1e;
  fm[7] = 0x4;

  fm = &(rom['%'][0]);
  fm[1] = 0x18;
  fm[2] = 0x19;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[5] = 0x8;
  fm[6] = 0x13;
  fm[7] = 0x3;

  fm = &(rom['&'][0]);
  fm[1] = 0xc;
  fm[2] = 0x12;
  fm[3] = 0x14;
  fm[4] = 0x8;
  fm[5] = 0x15;
  fm[6] = 0x12;
  fm[7] = 0xb;

  fm = &(rom[0x27][0]);	// The ' character
  fm[1] = 0xc;
  fm[2] = 0x4;
  fm[3] = 0x8;

  fm = &(rom['('][0]);
  fm[1] = 0x2;
  fm[2] = 0x4;
  fm[3] = 0x8;
  fm[4] = 0x8;
  fm[5] = 0x8;
  fm[6] = 0x4;
  fm[7] = 0x2;

  fm = &(rom[')'][0]);
  fm[1] = 0x8;
  fm[2] = 0x4;
  fm[3] = 0x2;
  fm[4] = 0x2;
  fm[5] = 0x2;
  fm[6] = 0x4;
  fm[7] = 0x8;

  fm = &(rom['*'][0]);
  fm[2] = 0x4;
  fm[3] = 0x15;
  fm[4] = 0xe;
  fm[5] = 0x15;
  fm[6] = 0x4;

  fm = &(rom['+'][0]);
  for( i=2; i<7; i++ ) fm[i] = 0x4;
  fm[4] = 0x1f;

  fm = &(rom[','][0]);
  fm[5] = 0xc;
  fm[6] = 0x4;
  fm[7] = 0x8;

  fm = &(rom['-'][0]);
  fm[4] = 0x1f;

  fm = &(rom['.'][0]);
  fm[6] = 0xc;
  fm[7] = 0xc;

  fm = &(rom['/'][0]);
  fm[2] = 0x1;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[5] = 0x8;
  fm[6] = 0x10;

  fm = &(rom['0'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x13;
  fm[4] = 0x15;
  fm[5] = 0x19;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['1'][0]);
  for( i=1; i<7; i++ ) fm[i] = 0x4;
  fm[2] = 0xc;
  fm[7] = 0xe;

  fm = &(rom['2'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x1;
  fm[4] = 0x2;
  fm[5] = 0x4;
  fm[6] = 0x8;
  fm[7] = 0x1f;

  fm = &(rom['3'][0]);
  fm[1] = 0x1f;
  fm[2] = 0x2;
  fm[3] = 0x4;
  fm[4] = 0x2;
  fm[5] = 0x1;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['4'][0]);
  fm[1] = 0x2;
  fm[2] = 0x6;
  fm[3] = 0xa;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x2;
  fm[7] = 0x2;

  fm = &(rom['5'][0]);
  fm[1] = 0x1f;
  fm[2] = 0x10;
  fm[3] = 0x1e;
  fm[4] = 0x1;
  fm[5] = 0x1;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['6'][0]);
  fm[1] = 0x6;
  fm[2] = 0x8;
  fm[3] = 0x10;
  fm[4] = 0x1e;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['7'][0]);
  fm[1] = 0x1f;
  fm[2] = 0x11;
  fm[3] = 0x1;
  fm[4] = 0x2;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x4;

  fm = &(rom['8'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0xe;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['9'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0xf;
  fm[5] = 0x1;
  fm[6] = 0x2;
  fm[7] = 0xc;

  fm = &(rom[':'][0]);
  for( i=2; i<7; i++ ) fm[i] = 0xc;
  fm[4] = 0;

  fm = &(rom[';'][0]);
  fm[2] = 0xc;
  fm[3] = 0xc;
  fm[5] = 0xc;
  fm[6] = 0x4;
  fm[7] = 0x8;

  fm = &(rom['<'][0]);
  fm[1] = 0x2;
  fm[2] = 0x4;
  fm[3] = 0x8;
  fm[4] = 0x10;
  fm[5] = 0x8;
  fm[6] = 0x4;
  fm[7] = 0x2;

  fm = &(rom['='][0]);
  fm[3] = 0x1f;
  fm[5] = 0x1f;

  fm = &(rom['>'][0]);
  fm[1] = 0x8;
  fm[2] = 0x4;
  fm[3] = 0x2;
  fm[4] = 0x1;
  fm[5] = 0x2;
  fm[6] = 0x4;
  fm[7] = 0x8;

  fm = &(rom['?'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x1;
  fm[4] = 0x2;
  fm[5] = 0x4;
  fm[7] = 0x4;

  fm = &(rom['@'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x1;
  fm[4] = 0xb;
  fm[5] = 0x15;
  fm[6] = 0x15;
  fm[7] = 0xe;

  fm = &(rom['A'][0]);
  for( i=3; i<8; i++ ) fm[i] = 0x11;
  fm[1] = 0x4;
  fm[2] = 0x0a;
  fm[5] = 0x1f;

  fm = &(rom['B'][0]);
  fm[1] = 0x1e;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x1e;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x1e;

  fm = &(rom['C'][0]);
  fm[1] = 0x0e;
  fm[2] = 0x11;
  fm[3] = 0x10;
  fm[4] = 0x10;
  fm[5] = 0x10;
  fm[6] = 0x11;
  fm[7] = 0x0e;

  fm = &(rom['D'][0]);
  fm[1] = 0x1c;
  fm[2] = 0x12;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x12;
  fm[7] = 0x1c;

  fm = &(rom['E'][0]);
  fm[1] = 0x1f;
  fm[2] = 0x10;
  fm[3] = 0x10;
  fm[4] = 0x1e;
  fm[5] = 0x10;
  fm[6] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom['F'][0]);
  for( i=2; i<8; i++ ) fm[i] = 0x10;
  fm[1] = 0x1f;
  fm[4] = 0x1e;

  fm = &(rom['G'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x10;
  fm[4] = 0x17;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom['H'][0]);
  for( i=1; i<8; i++ ) fm[i] = 0x11;
  fm[4] = 0x1f;

  fm = &(rom['I'][0]);
  for( i=2; i<7; i++ ) fm[i] = 4;
  fm[1] = 0xe;
  fm[7] = 0xe;

  fm = &(rom['J'][0]);
  for( i=2; i<6; i++ ) fm[i] = 2;
  fm[1] = 0x7;
  fm[6] = 0x12;
  fm[7] = 0xc;

  fm = &(rom['K'][0]);
  fm[1] = 0x11;
  fm[2] = 0x12;
  fm[3] = 0x14;
  fm[4] = 0x18;
  fm[5] = 0x14;
  fm[6] = 0x12;
  fm[7] = 0x11;

  fm = &(rom['L'][0]);
  for( i=1; i<7; i++ ) fm[i] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom['M'][0]);
  for( i=1; i<8; i++ ) fm[i] = 0x11;
  fm[2] = 0x1b;
  fm[3] = 0x15;
  fm[4] = 0x15;

  fm = &(rom['N'][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x19;
  fm[4] = 0x15;
  fm[5] = 0x13;
  fm[6] = 0x11;
  fm[7] = 0x11;

  fm = &(rom['O'][0]);
  for( i=2; i<7; i++ ) fm[i] = 0x11;
  fm[1] = 0xe;
  fm[7] = 0xe;

  fm = &(rom['P'][0]);
  fm[1] = 0x1e;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x1e;
  fm[5] = 0x10;
  fm[6] = 0x10;
  fm[7] = 0x10;

  fm = &(rom['Q'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x15;
  fm[6] = 0x12;
  fm[7] = 0xd;

  fm = &(rom['R'][0]);
  fm[1] = 0x1e;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x1e;
  fm[5] = 0x14;
  fm[6] = 0x12;
  fm[7] = 0x11;

  fm = &(rom['S'][0]);
  fm[1] = 0xe;
  fm[2] = 0x11;
  fm[3] = 0x10;
  fm[4] = 0xe;
  fm[5] = 0x1;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['T'][0]);
  for( i=2; i<8; i++ ) fm[i] = 4;
  fm[1] = 0x1f;

  fm = &(rom['U'][0]);
  for( i=1; i<7; i++ ) fm[i] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['V'][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x11;
  fm[6] = 0xa;
  fm[7] = 0x4;

  fm = &(rom['W'][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x15;
  fm[5] = 0x15;
  fm[6] = 0x15;
  fm[7] = 0xa;

  fm = &(rom['X'][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0xa;
  fm[4] = 0x4;
  fm[5] = 0xa;
  fm[6] = 0x11;
  fm[7] = 0x11;

  fm = &(rom['Y'][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0xa;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x4;

  fm = &(rom['Z'][0]);
  fm[1] = 0x1f;
  fm[2] = 0x1;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[5] = 0x8;
  fm[6] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom['['][0]);
  for( i=2; i<7; i++ ) fm[i] = 8;
  fm[1] = 0xe;
  fm[7] = 0xe;

  fm = &(rom[0x5c][0]);	// the \ character
  fm[2] = 0x10;
  fm[3] = 0x8;
  fm[4] = 0x4;
  fm[5] = 0x2;
  fm[6] = 0x1;

  fm = &(rom[']'][0]);
  for( i=2; i<7; i++ ) fm[i] = 2;
  fm[1] = 0xe;
  fm[7] = 0xe;

  fm = &(rom['^'][0]);
  fm[1] = 0x4;
  fm[2] = 0xa;
  fm[3] = 0x11;

  fm = &(rom['_'][0]);
  fm[7] = 0x1f;

  fm = &(rom['`'][0]);
  fm[1] = 0x8;
  fm[2] = 0x4;
  fm[3] = 0x2;

  fm = &(rom['a'][0]);
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom['b'][0]);
  fm[1] = 0x10;
  fm[2] = 0x10;
  fm[3] = 0x16;
  fm[4] = 0x19;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x1e;

  fm = &(rom['c'][0]);
  fm[3] = 0x0e;
  fm[4] = 0x10;
  fm[5] = 0x10;
  fm[6] = 0x11;
  fm[7] = 0x0e;

  fm = &(rom['d'][0]);
  fm[1] = 0x1;
  fm[2] = 0x1;
  fm[3] = 0xd;
  fm[4] = 0x13;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom['e'][0]);
  fm[3] = 0x0e;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x10;
  fm[7] = 0x0e;

  fm = &(rom['f'][0]);
  fm[1] = 0x6;
  fm[2] = 0x9;
  fm[3] = 0x8;
  fm[4] = 0x1c;
  fm[5] = 0x8;
  fm[6] = 0x8;
  fm[7] = 0x8;

  fm = &(rom['g'][0]);
  fm[3] = 0x0f;
  fm[4] = 0x11;
  fm[5] = 0x0f;
  fm[6] = 0x01;
  fm[7] = 0x0e;

  fm = &(rom['h'][0]);
  fm[1] = 0x10;
  fm[2] = 0x10;
  fm[3] = 0x16;
  fm[4] = 0x19;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x11;

  fm = &(rom['i'][0]);
  for( i=1; i<7; i++ ) fm[i] = 0x4;
  fm[2] = 0;
  fm[4] = 0x0c;
  fm[7] = 0x0e;

  fm = &(rom['j'][0]);
  for( i=1; i<7; i++ ) fm[i] = 0x2;
  fm[2] = 0;
  fm[3] = 0x06;
  fm[6] = 0x12;
  fm[7] = 0x0c;

  fm = &(rom['k'][0]);
  fm[1] = 0x10;
  fm[2] = 0x10;
  fm[3] = 0x12;
  fm[4] = 0x14;
  fm[5] = 0x18;
  fm[6] = 0x14;
  fm[7] = 0x12;

  fm = &(rom['l'][0]);
  for( i=2; i<7; i++ ) fm[i] = 0x4;
  fm[1] = 0x0c;
  fm[7] = 0x0e;

  fm = &(rom['m'][0]);
  for( i=4; i<8; i++ ) fm[i] = 0x15;
  fm[3] = 0x1a;

  fm = &(rom['n'][0]);
  fm[3] = 0x16;
  fm[4] = 0x19;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x11;

  fm = &(rom['o'][0]);
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom['p'][0]);
  fm[3] = 0x1e;
  fm[4] = 0x11;
  fm[5] = 0x1e;
  fm[6] = 0x10;
  fm[7] = 0x10;

  fm = &(rom['q'][0]);
  fm[3] = 0x0d;
  fm[4] = 0x13;
  fm[5] = 0x0f;
  fm[6] = 0x1;
  fm[7] = 0x1;

  fm = &(rom['r'][0]);
  fm[3] = 0x16;
  fm[4] = 0x19;
  fm[5] = 0x10;
  fm[6] = 0x10;
  fm[7] = 0x10;

  fm = &(rom['s'][0]);
  fm[3] = 0x0e;
  fm[4] = 0x10;
  fm[5] = 0x0e;
  fm[6] = 0x01;
  fm[7] = 0x1e;

  fm = &(rom['t'][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x8;
  fm[3] = 0x1c;
  fm[6] = 0x09;
  fm[7] = 0x06;

  fm = &(rom['u'][0]);
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x13;
  fm[7] = 0x0d;

  fm = &(rom['v'][0]);
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0xa;
  fm[7] = 0x4;

  fm = &(rom['w'][0]);
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x15;
  fm[6] = 0x15;
  fm[7] = 0xa;

  fm = &(rom['x'][0]);
  fm[3] = 0x11;
  fm[4] = 0x0a;
  fm[5] = 0x04;
  fm[6] = 0x0a;
  fm[7] = 0x11;

  fm = &(rom['y'][0]);
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x0f;
  fm[6] = 0x01;
  fm[7] = 0x0e;

  fm = &(rom['z'][0]);
  fm[3] = 0x1f;
  fm[4] = 0x2;
  fm[5] = 0x4;
  fm[6] = 0x8;
  fm[7] = 0x1f;

  fm = &(rom['{'][0]);
  for( i=2; i<7; i++ ) fm[i] = 4;
  fm[1] = 0x2;
  fm[4] = 0x8;
  fm[7] = 0x2;

  fm = &(rom['|'][0]);
  for( i=1; i<8; i++ ) fm[i] = 4;

  fm = &(rom['}'][0]);
  for( i=2; i<7; i++ ) fm[i] = 4;
  fm[1] = 0x8;
  fm[4] = 0x2;
  fm[7] = 0x8;

  fm = &(rom['~'][0]);
  fm[4] = 0xd;
  fm[5] = 0x12;

  fm = &(rom[0x7f][0]);	
  fm[1] = 0x04;
  fm[2] = 0x0a;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x1f;
  
  fm = &(rom[0x80][0]);	
  fm[1] = 0x1f;
  fm[2] = 0x11;
  fm[3] = 0x10;
  fm[4] = 0x1e;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x1e;
  
  fm = &(rom[0x81][0]);	
  fm[0] = 0x0f;
  fm[1] = 0x5;
  fm[2] = 0x5;
  fm[3] = 0x09;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x11;
  fm[7] = 0x11;
  
  fm = &(rom[0x82][0]);
  for( i=1; i<8; i++ ) fm[i] = 0x15;
  fm[4] = 0x0e;

  fm = &(rom[0x83][0]);	
  fm[1] = 0x1e;
  fm[2] = 0x1;
  fm[3] = 0x1;
  fm[4] = 0x6;
  fm[5] = 0x1;
  fm[6] = 0x1;
  fm[7] = 0x1e;
  
  fm = &(rom[0x84][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x13;
  fm[4] = 0x15;
  fm[5] = 0x19;
  fm[6] = 0x11;
  fm[7] = 0x11;

  fm = &(rom[0x85][0]);
  fm[0] = 0x0a;
  fm[1] = 0x4;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x13;
  fm[5] = 0x15;
  fm[6] = 0x19;
  fm[7] = 0x11;

  fm = &(rom[0x86][0]);
  for( i=2; i<6; i++ ) fm[i] = 0x5;
  fm[1] = 0x0f;
  fm[6] = 0x15;
  fm[6] = 0x09;

  fm = &(rom[0x87][0]);	// Pi
  for( i=2; i<8; i++ ) fm[i] = 0x11;
  fm[1] = 0x1f;

  fm = &(rom[0x88][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x0a;
  fm[5] = 0x4;
  fm[6] = 0x08;
  fm[7] = 0x10;

  fm = &(rom[0x89][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x11;
  fm[6] = 0x1f;
  fm[7] = 0x1;

  fm = &(rom[0x8a][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x0f;
  fm[5] = 0x1;
  fm[6] = 0x1;
  fm[7] = 0x1;
  
  fm = &(rom[0x8b][0]);
  for( i=2; i<7; i++ ) fm[i] = 0x15;
  fm[7] = 0x1f;

  fm = &(rom[0x8c][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x15;
  fm[6] = 0x1f;
  fm[7] = 0x1;

  fm = &(rom[0x8d][0]);
  fm[1] = 0x18;
  fm[2] = 0x08;
  fm[3] = 0x08;
  fm[4] = 0x0e;
  fm[5] = 0x09;
  fm[6] = 0x09;
  fm[7] = 0x0e;
  
  fm = &(rom[0x8e][0]);
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x19;
  fm[5] = 0x15;
  fm[6] = 0x15;
  fm[7] = 0x19;
  
  fm = &(rom[0x8f][0]);
  fm[1] = 0x0e;
  fm[2] = 0x11;
  fm[3] = 0x05;
  fm[4] = 0x0b;
  fm[5] = 0x01;
  fm[6] = 0x11;
  fm[7] = 0x0e;
  
  fm = &(rom[0x90][0]);	// alpha
  fm[3] = 0x09;
  fm[4] = 0x15;
  fm[5] = 0x12;
  fm[6] = 0x12;
  fm[7] = 0x0d;
  
  fm = &(rom[0x91][0]);	// half note
  fm[1] = 0x4;
  fm[2] = 0x6;
  fm[3] = 0x5;
  fm[4] = 0x5;
  fm[5] = 0x4;
  fm[6] = 0x1c;
  fm[7] = 0x1c;
  
  fm = &(rom[0x92][0]);	// Gamma
  for( i=3; i<8; i++ ) fm[i] = 0x10;
  fm[1] = 0x1f;
  fm[2] = 0x11;

  fm = &(rom[0x93][0]);	// pi
  fm[3] = 0x1f;
  fm[4] = 0x0a;
  fm[5] = 0x0a;
  fm[6] = 0x0a;
  fm[7] = 0x13;
  
  fm = &(rom[0x94][0]);	// Sigma
  fm[1] = 0x1f;
  fm[2] = 0x10;
  fm[3] = 0x08;
  fm[4] = 0x4;
  fm[5] = 0x08;
  fm[6] = 0x10;
  fm[7] = 0x1f;
  
  fm = &(rom[0x95][0]);	// sigma
  fm[3] = 0x0f;
  fm[4] = 0x12;
  fm[5] = 0x12;
  fm[6] = 0x12;
  fm[7] = 0x0c;
  
  fm = &(rom[0x96][0]);	// joined note
  fm[0] = 0x6;
  fm[1] = 0x5;
  fm[2] = 0x7;
  fm[3] = 0x5;
  fm[4] = 0x5;
  fm[5] = 0x1d;
  fm[6] = 0x1b;
  fm[7] = 0x3;
  
  fm = &(rom[0x97][0]);	// tau
  fm[2] = 0x01;
  fm[3] = 0x0e;
  fm[4] = 0x14;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x2;
  
  fm = &(rom[0x98][0]);	// bell
  fm[1] = 0x4;
  fm[2] = 0x0e;
  fm[3] = 0x0e;
  fm[4] = 0x0e;
  fm[5] = 0x1f;
  fm[6] = 0x4;
  
  fm = &(rom[0x99][0]);	// Theta
  for( i=2; i<7; i++ ) fm[i] = 0x11;
  fm[1] = 0x0e;
  fm[4] = 0x1f;
  fm[7] = 0x0e;

  fm = &(rom[0x9a][0]);	// omega
  fm[2] = 0x0e;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x0a;
  fm[6] = 0x0a;
  fm[7] = 0x11;
  
  fm = &(rom[0x9b][0]);	// delta
  fm[1] = 0x6;
  fm[2] = 0x09;
  fm[3] = 0x4;
  fm[4] = 0x0a;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x0e;

  fm = &(rom[0x9c][0]);	// infinity?
  fm[3] = 0x0b;
  fm[4] = 0x15;
  fm[5] = 0x1a;
  
  fm = &(rom[0x9d][0]);	// heart
  fm[2] = 0x0a;
  fm[3] = 0x1f;
  fm[4] = 0x1f;
  fm[5] = 0x1f;
  fm[6] = 0x0e;
  fm[7] = 0x4;
  
  fm = &(rom[0x9e][0]);	// epsilon
  fm[3] = 0x0e;
  fm[4] = 0x10;
  fm[5] = 0x0c;
  fm[6] = 0x11;
  fm[7] = 0x0e;
  
  fm = &(rom[0x9f][0]);	// intersection
  for( i=2; i<8; i++ ) fm[i] = 0x11;
  fm[1] = 0x0e;

  fm = &(rom[0xa0][0]);
  for( i=1; i<8; i++ ) fm[i] = 0x1b;

  fm = &(rom[0xa1][0]);	// i
  for( i=1; i<8; i++ ) fm[i] = 0x4;
  fm[2] = 0;
  fm[3] = 0;

  fm = &(rom[0xa2][0]);	// cent
  fm[1] = 0x4;
  fm[2] = 0x0e;
  fm[3] = 0x14;
  fm[4] = 0x14;
  fm[5] = 0x14;
  fm[6] = 0x0e;
  fm[7] = 0x4;

  fm = &(rom[0xa3][0]);	// pound
  fm[1] = 0x6;
  fm[2] = 0x8;
  fm[3] = 0x8;
  fm[4] = 0x1c;
  fm[5] = 0x8;
  fm[6] = 0x9;
  fm[7] = 0x16;

  fm = &(rom[0xa4][0]);
  fm[2] = 0x11;
  fm[3] = 0x0e;
  fm[4] = 0x0a;
  fm[5] = 0x0e;
  fm[6] = 0x11;

  fm = &(rom[0xa5][0]);	// yen
  fm[1] = 0x11;
  fm[2] = 0x0a;
  fm[3] = 0x1f;
  fm[4] = 0x4;
  fm[5] = 0x1f;
  fm[6] = 0x4;
  fm[7] = 0x4;

  fm = &(rom[0xa6][0]);	// |
  for( i=1; i<8; i++ ) fm[i] = 0x4;
  fm[4] = 0;

  fm = &(rom[0xa7][0]);	// script s?
  fm[1] = 0x6;
  fm[2] = 0x09;
  fm[3] = 0x4;
  fm[4] = 0x0a;
  fm[5] = 0x4;
  fm[6] = 0x12;
  fm[7] = 0x0c;

  fm = &(rom[0xa8][0]);	// script f?
  fm[1] = 0x2;
  fm[2] = 0x5;
  fm[3] = 0x4;
  fm[4] = 0x1f;
  fm[5] = 0x4;
  fm[6] = 0x14;
  fm[7] = 0x08;

  fm = &(rom[0xa9][0]);
  fm[1] = 0x1f;
  fm[2] = 0x11;
  fm[3] = 0x15;
  fm[4] = 0x17;
  fm[5] = 0x15;
  fm[6] = 0x11;
  fm[7] = 0x1f;

  fm = &(rom[0xaa][0]);	// a underscore
  fm[1] = 0x0e;
  fm[2] = 0x1;
  fm[3] = 0x0f;
  fm[4] = 0x11;
  fm[5] = 0x0f;
  fm[7] = 0x1f;

  fm = &(rom[0xab][0]);	// <<
  fm[2] = 0x05;
  fm[3] = 0x0a;
  fm[4] = 0x14;
  fm[5] = 0x0a;
  fm[6] = 0x05;

  fm = &(rom[0xac][0]);
  fm[1] = 0x12;
  fm[2] = 0x15;
  fm[3] = 0x15;
  fm[4] = 0x1d;
  fm[5] = 0x15;
  fm[6] = 0x15;
  fm[7] = 0x12;

  fm = &(rom[0xad][0]);	// reverse R
  fm[1] = 0x0f;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x0f;
  fm[5] = 0x5;
  fm[6] = 0x09;
  fm[7] = 0x11;

  fm = &(rom[0xae][0]);	// inverse block R
  fm[1] = 0x1f;
  fm[2] = 0x11;
  fm[3] = 0x15;
  fm[4] = 0x11;
  fm[5] = 0x13;
  fm[6] = 0x15;
  fm[7] = 0x1f;

  fm = &(rom[0xaf][0]);	// `
  fm[1] = 0x4;
  fm[2] = 0x08;
  fm[3] = 0x0c;

  fm = &(rom[0xb0][0]);	// degree
  fm[0] = 0x0c;
  fm[1] = 0x12;
  fm[2] = 0x12;
  fm[3] = 0x0c;

  fm = &(rom[0xb1][0]);	// +-
  fm[1] = 0x4;
  fm[2] = 0x4;
  fm[3] = 0x1f;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[7] = 0x1f;

  fm = &(rom[0xb2][0]);	// power 2
  fm[0] = 0x0c;
  fm[1] = 0x12;
  fm[2] = 0x4;
  fm[3] = 0x08;
  fm[4] = 0x1e;

  fm = &(rom[0xb3][0]);	// power 3
  fm[0] = 0x1c;
  fm[1] = 0x2;
  fm[2] = 0x0c;
  fm[3] = 0x02;
  fm[4] = 0x1c;

  fm = &(rom[0xb4][0]);
  fm[0] = 0x1c;
  fm[1] = 0x12;
  fm[2] = 0x1c;
  fm[3] = 0x10;
  fm[4] = 0x12;
  fm[5] = 0x17;
  fm[6] = 0x12;
  fm[7] = 0x3;

  fm = &(rom[0xb5][0]);	// mu
  for( i=1; i<4; i++ ) fm[i] = 0x11;
  fm[4] = 0x13;
  fm[5] = 0x1d;
  fm[6] = 0x10;
  fm[7] = 0x10;

  fm = &(rom[0xb6][0]);
  for( i=5; i<8; i++ ) fm[i] = 0x3;
  fm[1] = 0x0f;
  fm[2] = 0x13;
  fm[3] = 0x13;
  fm[4] = 0x0f;

  fm = &(rom[0xb7][0]);	// dot
  fm[4] = 0x06;
  fm[5] = 0x06;

  fm = &(rom[0xb8][0]);
  fm[3] = 0x0a;
  fm[4] = 0x11;
  fm[5] = 0x15;
  fm[6] = 0x15;
  fm[7] = 0x0a;

  fm = &(rom[0xb9][0]);	// power 1
  fm[0] = 0x08;
  fm[1] = 0x18;
  fm[2] = 0x08;
  fm[3] = 0x08;
  fm[4] = 0x1c;

  fm = &(rom[0xba][0]);	// o underscore
  fm[1] = 0x0e;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x0e;
  fm[7] = 0x1f;

  fm = &(rom[0xbb][0]);	// >>
  fm[2] = 0x14;
  fm[3] = 0x0a;
  fm[4] = 0x5;
  fm[5] = 0x0a;
  fm[6] = 0x14;

  fm = &(rom[0xbc][0]);	// 1/4
  fm[0] = 0x11;
  fm[1] = 0x12;
  fm[2] = 0x14;
  fm[3] = 0x0a;
  fm[4] = 0x16;
  fm[5] = 0x0a;
  fm[6] = 0x0f;
  fm[7] = 0x2;

  fm = &(rom[0xbd][0]);	// 1/2
  fm[0] = 0x11;
  fm[1] = 0x12;
  fm[2] = 0x14;
  fm[3] = 0x0a;
  fm[4] = 0x15;
  fm[5] = 0x1;
  fm[6] = 0x2;
  fm[7] = 0x07;

  fm = &(rom[0xbe][0]);	// 3/4?
  fm[0] = 0x18;
  fm[1] = 0x08;
  fm[2] = 0x18;
  fm[3] = 0x09;
  fm[4] = 0x1b;
  fm[5] = 0x5;
  fm[6] = 0x7;
  fm[7] = 0x1;

  fm = &(rom[0xbf][0]);	// inverted ?
  fm[1] = 0x4;
  fm[3] = 0x4;
  fm[4] = 0x08;
  fm[5] = 0x10;
  fm[6] = 0x11;
  fm[7] = 0x0e;

  fm = &(rom[0xc0][0]);	// A grave
  for( i=3; i<8; i++ ) fm[i] = 0x11;
  fm[0] = 0x08;
  fm[1] = 0x4;
  fm[2] = 0x0a;
  fm[5] = 0x1f;

  fm = &(rom[0xc1][0]);	// A accent
  for( i=3; i<8; i++ ) fm[i] = 0x11;
  fm[0] = 0x02;
  fm[1] = 0x4;
  fm[2] = 0x0a;
  fm[5] = 0x1f;

  fm = &(rom[0xc2][0]);	// A hat
  for( i=4; i<8; i++ ) fm[i] = 0x11;
  fm[0] = 0x04;
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[5] = 0x1f;

  fm = &(rom[0xc3][0]);	// A tilde
  for( i=4; i<8; i++ ) fm[i] = 0x11;
  fm[0] = 0x0d;
  fm[1] = 0x12;
  fm[3] = 0x0e;
  fm[5] = 0x1f;

  fm = &(rom[0xc4][0]);	// A umlaut
  for( i=4; i<8; i++ ) fm[i] = 0x11;
  fm[0] = 0x0a;
  fm[2] = 0x04;
  fm[3] = 0x0a;
  fm[5] = 0x1f;

  fm = &(rom[0xc5][0]);	// A diamond
  for( i=3; i<8; i++ ) fm[i] = 0x11;
  fm[0] = 0x04;
  fm[1] = 0x0a;
  fm[2] = 0x04;
  fm[3] = 0x0e;
  fm[5] = 0x1f;

  fm = &(rom[0xc6][0]);	// AE
  fm[1] = 0x07;
  fm[2] = 0x0c;
  fm[3] = 0x14;
  fm[4] = 0x17;
  fm[5] = 0x1c;
  fm[6] = 0x14;
  fm[7] = 0x17;

  fm = &(rom[0xc7][0]);
  fm[0] = 0x0e;
  fm[1] = 0x11;
  fm[2] = 0x10;
  fm[3] = 0x10;
  fm[4] = 0x11;
  fm[5] = 0x0e;
  fm[6] = 0x2;
  fm[7] = 0x0e;

  fm = &(rom[0xc8][0]);	// E grave
  fm[0] = 8;
  fm[1] = 4;
  fm[3] = 0x1f;
  fm[4] = 0x10;
  fm[5] = 0x1e;
  fm[6] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom[0xc9][0]);	// E accent
  fm[0] = 2;
  fm[1] = 4;
  fm[3] = 0x1f;
  fm[4] = 0x10;
  fm[5] = 0x1e;
  fm[6] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom[0xca][0]);	// E hat
  fm[0] = 4;
  fm[1] = 0x0a;
  fm[3] = 0x1f;
  fm[4] = 0x10;
  fm[5] = 0x1e;
  fm[6] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom[0xcb][0]);	// E umlaut
  fm[1] = 0x0a;
  fm[3] = 0x1f;
  fm[4] = 0x10;
  fm[5] = 0x1e;
  fm[6] = 0x10;
  fm[7] = 0x1f;

  fm = &(rom[0xcc][0]);	// I grave
  fm[0] = 8;
  fm[1] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x0e;

  fm = &(rom[0xcd][0]);	// I accent
  fm[0] = 2;
  fm[1] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x0e;

  fm = &(rom[0xce][0]);	// I hat
  fm[0] = 4;
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x0e;

  fm = &(rom[0xcf][0]);	// I umlaut
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[6] = 0x4;
  fm[7] = 0x0e;

  fm = &(rom[0xd0][0]);
  for( i=2; i<7; i++ ) fm[i] = 0x09;
  fm[1] = 0x0e;
  fm[4] = 0x1d;
  fm[7] = 0x0e;

  fm = &(rom[0xd1][0]);	// N tilde
  fm[0] = 0x0d;
  fm[1] = 0x12;
  fm[3] = 0x11;
  fm[4] = 0x19;
  fm[5] = 0x15;
  fm[6] = 0x13;
  fm[7] = 0x11;

  fm = &(rom[0xd2][0]);	// O grave
  fm[0] = 0x08;
  fm[1] = 0x04;
  fm[2] = 0xe;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xd3][0]);	// O accent
  fm[0] = 0x02;
  fm[1] = 0x04;
  fm[2] = 0xe;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xd4][0]);	// O hat
  fm[0] = 0x04;
  fm[1] = 0x0a;
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xd5][0]);	// O tilde
  fm[0] = 0x0d;
  fm[1] = 0x12;
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xd6][0]);	// O umlaut
  fm[0] = 0x0a;
  fm[2] = 0xe;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xd7][0]);	// times
  fm[2] = 0x11;
  fm[3] = 0x0a;
  fm[4] = 0x04;
  fm[5] = 0x0a;
  fm[6] = 0x11;

  fm = &(rom[0xd8][0]);	// Psi
  fm[1] = 0x0e;
  fm[2] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x15;
  fm[5] = 0x0e;
  fm[6] = 0x4;
  fm[7] = 0x0e;

  fm = &(rom[0xd9][0]);	// U grave
  for( i=2; i<7; i++ ) fm[i] = 0x11;
  fm[0] = 8;
  fm[1] = 4;
  fm[7] = 0xe;

  fm = &(rom[0xda][0]);	// U accent
  for( i=2; i<7; i++ ) fm[i] = 0x11;
  fm[0] = 2;
  fm[1] = 4;
  fm[7] = 0xe;

  fm = &(rom[0xdb][0]);	// U hat
  for( i=3; i<7; i++ ) fm[i] = 0x11;
  fm[0] = 4;
  fm[1] = 0x0a;
  fm[7] = 0xe;

  fm = &(rom[0xdc][0]);	// U umlaut
  for( i=2; i<7; i++ ) fm[i] = 0x11;
  fm[0] = 0x0a;
  fm[7] = 0xe;

  fm = &(rom[0xdd][0]);
  for( i=4; i<8; i++ ) fm[i] = 0x4;
  fm[0] = 0x02;
  fm[1] = 0x04;
  fm[2] = 0x11;
  fm[3] = 0x0a;

  fm = &(rom[0xde][0]);	// Y accent
  fm[0] = 0x18;
  fm[1] = 8;
  fm[2] = 0x0e;
  fm[3] = 0x09;
  fm[4] = 0x09;
  fm[5] = 0x0e;
  fm[6] = 0x08;
  fm[7] = 0x1c;

  fm = &(rom[0xdf][0]);	// Beta
  for( i=2; i<7; i++ ) fm[i] = 0x09;
  fm[1] = 6;
  fm[4] = 0x0e;
  fm[7] = 0x16;

  fm = &(rom[0xe0][0]);	// a grave
  fm[0] = 0x08;
  fm[1] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom[0xe1][0]);	// a accent
  fm[0] = 0x2;
  fm[1] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom[0xe2][0]);	// a hat
  fm[0] = 0x04;
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom[0xe3][0]);	// a tilde
  fm[0] = 0x0d;
  fm[1] = 0x12;
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom[0xe4][0]);	// a umlaut
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom[0xe5][0]);	// a diamond
  fm[0] = 0x04;
  fm[1] = 0x0a;
  fm[2] = 0x4;
  fm[3] = 0x0e;
  fm[4] = 0x1;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0f;

  fm = &(rom[0xe6][0]);
  fm[2] = 0x1a;
  fm[3] = 0x05;
  fm[4] = 0x0f;
  fm[5] = 0x14;
  fm[6] = 0x15;
  fm[7] = 0x0a;

  fm = &(rom[0xe7][0]);	
  fm[2] = 0x0e;
  fm[3] = 0x10;
  fm[4] = 0x11;
  fm[5] = 0x0e;
  fm[6] = 0x4;
  fm[7] = 0x0c;

  fm = &(rom[0xe8][0]);	// e grave
  fm[0] = 0x8;
  fm[1] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x10;
  fm[7] = 0x0e;

  fm = &(rom[0xe9][0]);	// e accent
  fm[0] = 2;
  fm[1] = 4;
  fm[3] = 0x0e;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x10;
  fm[7] = 0x0e;

  fm = &(rom[0xea][0]);	// e hat
  fm[0] = 4;
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x10;
  fm[7] = 0x0e;

  fm = &(rom[0xeb][0]);	// e umlaut
  fm[1] = 0x0a;
  fm[3] = 0x0e;
  fm[4] = 0x11;
  fm[5] = 0x1f;
  fm[6] = 0x10;
  fm[7] = 0x0e;

  fm = &(rom[0xec][0]);	// i grave
  for( i=1; i<7; i++ ) fm[i] = 0x4;
  fm[0] = 0x08;
  fm[2] = 0;
  fm[4] = 0x0c;
  fm[7] = 0x0e;

  fm = &(rom[0xed][0]);	// i accent
  for( i=1; i<7; i++ ) fm[i] = 0x4;
  fm[0] = 2;
  fm[2] = 0;
  fm[4] = 0x0c;
  fm[7] = 0x0e;

  fm = &(rom[0xee][0]);	// i hat
  for( i=0; i<7; i++ ) fm[i] = 0x4;
  fm[1] = 0x0a;
  fm[2] = 0;
  fm[4] = 0x0c;
  fm[7] = 0x0e;

  fm = &(rom[0xef][0]);	// i umlaut
  for( i=3; i<7; i++ ) fm[i] = 0x4;
  fm[1] = 0x0a;
  fm[4] = 0x0c;
  fm[7] = 0x0e;

  fm = &(rom[0xf0][0]);	
  fm[1] = 0x14;
  fm[2] = 0x08;
  fm[3] = 0x14;
  fm[4] = 0x2;
  fm[5] = 0x0f;
  fm[6] = 0x11;
  fm[7] = 0x0e;

  fm = &(rom[0xf1][0]);	// n tilde
  fm[0] = 0x0d;
  fm[1] = 0x12;
  fm[3] = 0x16;
  fm[4] = 0x19;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0x11;

  fm = &(rom[0xf2][0]);	// o grave
  fm[0] = 0x08;
  fm[1] = 0x04;
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xf3][0]);	// o accent
  fm[0] = 0x2;
  fm[1] = 0x4;
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xf4][0]);	// o hat
  fm[1] = 0x4;
  fm[2] = 0x0a;
  fm[4] = 0xe;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xf5][0]);	// o tilde
  fm[1] = 0x0d;
  fm[2] = 0x12;
  fm[4] = 0xe;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xf6][0]);	// o umlat
  fm[1] = 0x0a;
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;
  fm[7] = 0xe;

  fm = &(rom[0xf7][0]);	// divide
  fm[2] = 0x4;
  fm[4] = 0x1f;
  fm[6] = 0x4;

  fm = &(rom[0xf8][0]);	// psi?
  fm[1] = 0x02;
  fm[2] = 0x04;
  fm[3] = 0x0e;
  fm[4] = 0x11;
  fm[5] = 0x0e;
  fm[6] = 0x4;
  fm[7] = 0x8;

  fm = &(rom[0xf9][0]);	// u grave
  fm[0] = 8;
  fm[1] = 4;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x13;
  fm[7] = 0x0d;

  fm = &(rom[0xfa][0]);	// u accent
  fm[0] = 2;
  fm[1] = 4;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x13;
  fm[7] = 0x0d;

  fm = &(rom[0xfb][0]);	// u hat
  fm[0] = 4;
  fm[1] = 0x0a;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x13;
  fm[7] = 0x0d;

  fm = &(rom[0xfc][0]);	// u umlaut
  fm[1] = 0x0a;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x13;
  fm[7] = 0x0d;

  fm = &(rom[0xfd][0]); // y accent
  fm[0] = 2;
  fm[1] = 4;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x0f;
  fm[6] = 0x01;
  fm[7] = 0x0e;

  fm = &(rom[0xfe][0]);
  fm[1] = 0x0c;
  fm[2] = 4;
  fm[3] = 0x6;
  fm[4] = 0x5;
  fm[5] = 0x6;
  fm[6] = 0x4;
  fm[7] = 0x0e;

  fm = &(rom[0xff][0]);	// y umlaut
  fm[1] = 0x0a;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x0f;
  fm[6] = 0x01;
  fm[7] = 0x0e;
}
