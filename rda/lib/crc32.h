/* crc32.h

   Copyright 2005 Red Hat, Inc.

   This file is part of RDA, the Red Hat Debug Agent (and library).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
   
   Alternative licenses for RDA may be arranged by contacting Red Hat,
   Inc.  */

/* crc32() computes a 32-bit CRC.

   In order to match GDB, the initial value for ``crc'' must be 0xffffffff.
   When using this function iteratively over a number of blocks, the
   previous block's crc32() value should be used for the ``crc'' parameter
   on the second and subsequent blocks.   The code might be structured
   as follows:

     char blk[1024];
     int size;
     unsigned long crc = 0xffffffff;

     do {
       size = read_a_block (blk, sizeof (blk));
       crc = crc32 (blk, size, crc);
     } while (size > 0);
*/

unsigned long crc32 (unsigned char *blk, int blk_len, unsigned long crc);
