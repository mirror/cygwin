// rom.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

void 
init_rom( unsigned char rom[][8] ) {
  int i, j;
  unsigned char *fm;

  fm = &(rom['!'][0]);
  for( i=0; i<4; i++ ) fm[i] = 4;
  fm[6] = 4;

  fm = &(rom['"'][0]);
  for( i=0; i<4; i++ ) fm[i] = 0xa;

  fm = &(rom['#'][0]);
  for( i=0; i<7; i++ ) fm[i] = 0xa;
  fm[2] = 0x1f;
  fm[4] = 0x1f;

  fm = &(rom['$'][0]);
  fm[0] = 0x4;
  fm[1] = 0x0f;
  fm[2] = 0x14;
  fm[3] = 0xe;
  fm[4] = 0x5;
  fm[5] = 0x1e;
  fm[6] = 0x4;

  fm = &(rom['%'][0]);
  fm[0] = 0x18;
  fm[1] = 0x19;
  fm[2] = 0x2;
  fm[3] = 0x4;
  fm[4] = 0x8;
  fm[5] = 0x13;
  fm[6] = 0x3;

  fm = &(rom['&'][0]);
  fm[0] = 0xc;
  fm[1] = 0x12;
  fm[2] = 0x14;
  fm[3] = 0x8;
  fm[4] = 0x15;
  fm[5] = 0x12;
  fm[6] = 0xb;

  fm = &(rom[0x27][0]);	// The ' character
  fm[0] = 0xc;
  fm[1] = 0x4;
  fm[2] = 0x8;

  fm = &(rom['('][0]);
  fm[0] = 0x2;
  fm[1] = 0x4;
  fm[2] = 0x8;
  fm[3] = 0x8;
  fm[4] = 0x8;
  fm[5] = 0x4;
  fm[6] = 0x2;

  fm = &(rom[')'][0]);
  fm[0] = 0x8;
  fm[1] = 0x4;
  fm[2] = 0x2;
  fm[3] = 0x2;
  fm[4] = 0x2;
  fm[5] = 0x4;
  fm[6] = 0x8;

  fm = &(rom['*'][0]);
  fm[1] = 0x4;
  fm[2] = 0x15;
  fm[3] = 0xe;
  fm[4] = 0x15;
  fm[5] = 0x4;

  fm = &(rom['+'][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x4;
  fm[3] = 0x1f;

  fm = &(rom[','][0]);
  fm[4] = 0xc;
  fm[5] = 0x4;
  fm[6] = 0x8;

  fm = &(rom['-'][0]);
  fm[3] = 0x1f;

  fm = &(rom['.'][0]);
  fm[5] = 0xc;
  fm[6] = 0xc;

  fm = &(rom['/'][0]);
  fm[1] = 0x1;
  fm[2] = 0x2;
  fm[3] = 0x4;
  fm[4] = 0x8;
  fm[5] = 0x10;

  fm = &(rom['0'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x13;
  fm[3] = 0x15;
  fm[4] = 0x19;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['1'][0]);
  for( i=0; i<6; i++ ) fm[i] = 0x4;
  fm[1] = 0xc;
  fm[6] = 0xe;

  fm = &(rom['2'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x1;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[5] = 0x8;
  fm[6] = 0x1f;

  fm = &(rom['3'][0]);
  fm[0] = 0x1f;
  fm[1] = 0x2;
  fm[2] = 0x4;
  fm[3] = 0x2;
  fm[4] = 0x1;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['4'][0]);
  fm[0] = 0x2;
  fm[1] = 0x6;
  fm[2] = 0xa;
  fm[3] = 0x11;
  fm[4] = 0x1f;
  fm[5] = 0x2;
  fm[6] = 0x2;

  fm = &(rom['5'][0]);
  fm[0] = 0x1f;
  fm[1] = 0x10;
  fm[2] = 0x1e;
  fm[3] = 0x1;
  fm[4] = 0x1;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['6'][0]);
  fm[0] = 0x6;
  fm[1] = 0x8;
  fm[2] = 0x10;
  fm[3] = 0x1e;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['7'][0]);
  fm[0] = 0x1f;
  fm[1] = 0x11;
  fm[2] = 0x1;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[6] = 0x4;

  fm = &(rom['8'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0xe;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['9'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0xf;
  fm[4] = 0x1;
  fm[5] = 0x2;
  fm[6] = 0xc;

  fm = &(rom[':'][0]);
  for( i=1; i<6; i++ ) fm[i] = 0xc;
  fm[3] = 0;

  fm = &(rom[';'][0]);
  fm[1] = 0xc;
  fm[2] = 0xc;
  fm[4] = 0xc;
  fm[5] = 0x4;
  fm[6] = 0x8;

  fm = &(rom['<'][0]);
  fm[0] = 0x2;
  fm[1] = 0x4;
  fm[2] = 0x8;
  fm[3] = 0x10;
  fm[4] = 0x8;
  fm[5] = 0x4;
  fm[6] = 0x2;

  fm = &(rom['='][0]);
  fm[2] = 0x1f;
  fm[4] = 0x1f;

  fm = &(rom['>'][0]);
  fm[0] = 0x8;
  fm[1] = 0x4;
  fm[2] = 0x2;
  fm[3] = 0x1;
  fm[4] = 0x2;
  fm[5] = 0x4;
  fm[6] = 0x8;

  fm = &(rom['?'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x1;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[6] = 0x4;

  fm = &(rom['@'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x1;
  fm[3] = 0xb;
  fm[4] = 0x15;
  fm[5] = 0x15;
  fm[6] = 0xe;

  fm = &(rom['A'][0]);
  for( i=2; i<7; i++ ) fm[i] = 0x11;
  fm[0] = 0x4;
  fm[1] = 0x0a;
  fm[4] = 0x1f;

  fm = &(rom['B'][0]);
  fm[0] = 0x1e;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x1e;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x1e;

  fm = &(rom['C'][0]);
  fm[0] = 0x0e;
  fm[1] = 0x11;
  fm[2] = 0x10;
  fm[3] = 0x10;
  fm[4] = 0x10;
  fm[5] = 0x11;
  fm[6] = 0x0e;

  fm = &(rom['D'][0]);
  fm[0] = 0x1c;
  fm[1] = 0x12;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x12;
  fm[6] = 0x1c;

  fm = &(rom['E'][0]);
  fm[0] = 0x1f;
  fm[1] = 0x10;
  fm[2] = 0x10;
  fm[3] = 0x1e;
  fm[4] = 0x10;
  fm[5] = 0x10;
  fm[6] = 0x1f;

  fm = &(rom['F'][0]);
  for( i=1; i<7; i++ ) fm[i] = 0x10;
  fm[0] = 0x1f;
  fm[3] = 0x1e;

  fm = &(rom['G'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x10;
  fm[3] = 0x17;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x0f;

  fm = &(rom['H'][0]);
  for( i=0; i<7; i++ ) fm[i] = 0x11;
  fm[3] = 0x1f;

  fm = &(rom['I'][0]);
  for( i=1; i<6; i++ ) fm[i] = 4;
  fm[0] = 0xe;
  fm[6] = 0xe;

  fm = &(rom['J'][0]);
  for( i=1; i<5; i++ ) fm[i] = 2;
  fm[0] = 0x7;
  fm[5] = 0x12;
  fm[6] = 0xc;

  fm = &(rom['K'][0]);
  fm[0] = 0x11;
  fm[1] = 0x12;
  fm[2] = 0x14;
  fm[3] = 0x18;
  fm[4] = 0x14;
  fm[5] = 0x12;
  fm[6] = 0x11;

  fm = &(rom['L'][0]);
  for( i=0; i<6; i++ ) fm[i] = 0x10;
  fm[6] = 0x1f;

  fm = &(rom['M'][0]);
  for( i=0; i<7; i++ ) fm[i] = 0x11;
  fm[1] = 0x1b;
  fm[2] = 0x15;
  fm[3] = 0x15;

  fm = &(rom['N'][0]);
  fm[0] = 0x11;
  fm[1] = 0x11;
  fm[2] = 0x19;
  fm[3] = 0x15;
  fm[4] = 0x13;
  fm[5] = 0x11;
  fm[6] = 0x11;

  fm = &(rom['O'][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x11;
  fm[0] = 0xe;
  fm[6] = 0xe;

  fm = &(rom['P'][0]);
  fm[0] = 0x1e;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x1e;
  fm[4] = 0x10;
  fm[5] = 0x10;
  fm[6] = 0x10;

  fm = &(rom['Q'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x15;
  fm[5] = 0x12;
  fm[6] = 0xd;

  fm = &(rom['R'][0]);
  fm[0] = 0x1e;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x1e;
  fm[4] = 0x14;
  fm[5] = 0x12;
  fm[6] = 0x11;

  fm = &(rom['S'][0]);
  fm[0] = 0xe;
  fm[1] = 0x11;
  fm[2] = 0x10;
  fm[3] = 0xe;
  fm[4] = 0x1;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['T'][0]);
  for( i=1; i<7; i++ ) fm[i] = 4;
  fm[0] = 0x1f;

  fm = &(rom['U'][0]);
  for( i=0; i<6; i++ ) fm[i] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['V'][0]);
  for( i=0; i<5; i++ ) fm[i] = 0x11;
  fm[5] = 0xa;
  fm[6] = 0x4;

  fm = &(rom['W'][0]);
  fm[0] = 0x11;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0x15;
  fm[4] = 0x15;
  fm[5] = 0x15;
  fm[6] = 0xa;

  fm = &(rom['X'][0]);
  fm[0] = 0x11;
  fm[1] = 0x11;
  fm[2] = 0xa;
  fm[3] = 0x4;
  fm[4] = 0xa;
  fm[5] = 0x11;
  fm[6] = 0x11;

  fm = &(rom['Y'][0]);
  fm[0] = 0x11;
  fm[1] = 0x11;
  fm[2] = 0x11;
  fm[3] = 0xa;
  fm[4] = 0x4;
  fm[5] = 0x4;
  fm[6] = 0x4;

  fm = &(rom['Z'][0]);
  fm[0] = 0x1f;
  fm[1] = 0x1;
  fm[2] = 0x2;
  fm[3] = 0x4;
  fm[4] = 0x8;
  fm[5] = 0x10;
  fm[6] = 0x1f;

  fm = &(rom['['][0]);
  for( i=1; i<6; i++ ) fm[i] = 8;
  fm[0] = 0xe;
  fm[6] = 0xe;

  fm = &(rom[0x5c][0]);	// the \ character
  fm[1] = 0x10;
  fm[2] = 0x8;
  fm[3] = 0x4;
  fm[4] = 0x2;
  fm[5] = 0x1;

  fm = &(rom[']'][0]);
  for( i=1; i<6; i++ ) fm[i] = 2;
  fm[0] = 0xe;
  fm[6] = 0xe;

  fm = &(rom['^'][0]);
  fm[0] = 0x4;
  fm[1] = 0xa;
  fm[2] = 0x11;

  fm = &(rom['_'][0]);
  fm[6] = 0x1f;

  fm = &(rom['`'][0]);
  fm[0] = 0x8;
  fm[1] = 0x4;
  fm[2] = 0x2;

  fm = &(rom['a'][0]);
  fm[2] = 0x0e;
  fm[3] = 0x1;
  fm[4] = 0x0f;
  fm[5] = 0x11;
  fm[6] = 0x0f;

  fm = &(rom['b'][0]);
  fm[0] = 0x10;
  fm[1] = 0x10;
  fm[2] = 0x16;
  fm[3] = 0x19;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x1e;

  fm = &(rom['c'][0]);
  fm[2] = 0x0e;
  fm[3] = 0x10;
  fm[4] = 0x10;
  fm[5] = 0x11;
  fm[6] = 0x0e;

  fm = &(rom['d'][0]);
  fm[0] = 0x1;
  fm[1] = 0x1;
  fm[2] = 0xd;
  fm[3] = 0x13;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x0f;

  fm = &(rom['e'][0]);
  fm[2] = 0x0e;
  fm[3] = 0x11;
  fm[4] = 0x1f;
  fm[5] = 0x10;
  fm[6] = 0x0e;

  fm = &(rom['f'][0]);
  fm[0] = 0x6;
  fm[1] = 0x9;
  fm[2] = 0x8;
  fm[3] = 0x1c;
  fm[4] = 0x8;
  fm[5] = 0x8;
  fm[6] = 0x8;

  fm = &(rom['g'][0]);
  fm[2] = 0x0f;
  fm[3] = 0x11;
  fm[4] = 0x0f;
  fm[5] = 0x01;
  fm[6] = 0x0e;

  fm = &(rom['h'][0]);
  fm[0] = 0x10;
  fm[1] = 0x10;
  fm[2] = 0x16;
  fm[3] = 0x19;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;

  fm = &(rom['i'][0]);
  for( i=0; i<6; i++ ) fm[i] = 0x4;
  fm[1] = 0;
  fm[3] = 0x0c;
  fm[6] = 0x0e;

  fm = &(rom['j'][0]);
  for( i=0; i<6; i++ ) fm[i] = 0x2;
  fm[1] = 0;
  fm[2] = 0x06;
  fm[5] = 0x12;
  fm[6] = 0x0c;

  fm = &(rom['k'][0]);
  fm[0] = 0x10;
  fm[1] = 0x10;
  fm[2] = 0x12;
  fm[3] = 0x14;
  fm[4] = 0x18;
  fm[5] = 0x14;
  fm[6] = 0x12;

  fm = &(rom['l'][0]);
  for( i=1; i<6; i++ ) fm[i] = 0x4;
  fm[0] = 0x0c;
  fm[6] = 0x0e;

  fm = &(rom['m'][0]);
  for( i=3; i<7; i++ ) fm[i] = 0x15;
  fm[2] = 0x1a;

  fm = &(rom['n'][0]);
  fm[2] = 0x16;
  fm[3] = 0x19;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0x11;

  fm = &(rom['o'][0]);
  fm[2] = 0xe;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x11;
  fm[6] = 0xe;

  fm = &(rom['p'][0]);
  fm[2] = 0x1e;
  fm[3] = 0x11;
  fm[4] = 0x1e;
  fm[5] = 0x10;
  fm[6] = 0x10;

  fm = &(rom['q'][0]);
  fm[2] = 0x0d;
  fm[3] = 0x13;
  fm[4] = 0x0f;
  fm[5] = 0x1;
  fm[6] = 0x1;

  fm = &(rom['r'][0]);
  fm[2] = 0x16;
  fm[3] = 0x19;
  fm[4] = 0x10;
  fm[5] = 0x10;
  fm[6] = 0x10;

  fm = &(rom['s'][0]);
  fm[2] = 0x0e;
  fm[3] = 0x10;
  fm[4] = 0x0e;
  fm[5] = 0x01;
  fm[6] = 0x1e;

  fm = &(rom['t'][0]);
  for( i=0; i<5; i++ ) fm[i] = 0x8;
  fm[2] = 0x1c;
  fm[5] = 0x09;
  fm[6] = 0x06;

  fm = &(rom['u'][0]);
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0x13;
  fm[6] = 0x0d;

  fm = &(rom['v'][0]);
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x11;
  fm[5] = 0xa;
  fm[6] = 0x4;

  fm = &(rom['w'][0]);
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x15;
  fm[5] = 0x15;
  fm[6] = 0xa;

  fm = &(rom['x'][0]);
  fm[2] = 0x11;
  fm[3] = 0x0a;
  fm[4] = 0x04;
  fm[5] = 0x0a;
  fm[6] = 0x11;

  fm = &(rom['y'][0]);
  fm[2] = 0x11;
  fm[3] = 0x11;
  fm[4] = 0x0f;
  fm[5] = 0x01;
  fm[6] = 0x0e;

  fm = &(rom['z'][0]);
  fm[2] = 0x1f;
  fm[3] = 0x2;
  fm[4] = 0x4;
  fm[5] = 0x8;
  fm[6] = 0x1f;

  fm = &(rom['{'][0]);
  for( i=1; i<6; i++ ) fm[i] = 4;
  fm[0] = 0x2;
  fm[3] = 0x8;
  fm[6] = 0x2;

  fm = &(rom['|'][0]);
  for( i=0; i<7; i++ ) fm[i] = 4;

  fm = &(rom['}'][0]);
  for( i=1; i<6; i++ ) fm[i] = 4;
  fm[0] = 0x8;
  fm[3] = 0x2;
  fm[6] = 0x8;

  fm = &(rom['~'][0]);
  fm[0] = 0x08;
  fm[1] = 0x15;
  fm[2] = 0x2;
}

