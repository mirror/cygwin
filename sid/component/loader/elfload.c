/* Simple ELF loader
 *
 * Copyright (c) 1998 Red Hat
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */
#include <elfload.h>
#include <unistd.h>

unsigned char fileHeader [52];
unsigned char psymHdr[32];

#define PT_LOAD 1

struct LoadAreas
{
  char *loadAddr;
  int memsize;
  int filesize;
  int offset;
  int loaded;
} loadAreas[100]; // XXX: limit on number of loadable sections


/* Read in an ELF file, using FUNC to read data from the stream.
   The result is a boolean indicating success.
   The entry point as specified in the ELF header is stored in *ENTRY_POINT.
   The endianness as specified in the ELF header is stored in *LITTLE_ENDIAN.
*/

int
readElfFile (PFLOAD func, unsigned* entry_point, int* little_endian)
{
  int psymOffset;
  int psymSize;
  int psymNum;
  unsigned entryPoint = 0;
  int loadAreaCount = 0;
  int x;
  int littleEndian;

  /* This is relatively straightforward. We first read in the file header,
     find out how many sections there are, determine which ones are loadable
     (via the psym header), and load them.

     There is one major failing, tho--if the psym header isn't at the front
     of the file, and we're loading from a stream that we can't back
     up on, we will lose. */
  if (func (NULL, fileHeader, 0, 52) != 52)
    {
      return 0;
    }
  littleEndian = (fileHeader[EI_DATA] == ELFDATA2LSB);
  entryPoint = fetchWord (fileHeader+24, littleEndian);
  psymOffset = fetchWord (fileHeader+28, littleEndian);
  psymSize = fetchShort (fileHeader+42, littleEndian);
  psymNum = fetchShort (fileHeader+44, littleEndian);
  for (x = 0; x < psymNum; x++)
    {
      if (func (NULL, psymHdr, psymOffset, 32) != 32)
	{
	  return 0;
	}
      if (fetchWord (psymHdr, littleEndian) == PT_LOAD)
	{
	  loadAreas[loadAreaCount].loadAddr = (char *)fetchWord(psymHdr+8,
								littleEndian);
	  loadAreas[loadAreaCount].offset = fetchWord(psymHdr+4, littleEndian);
	  loadAreas[loadAreaCount].filesize = fetchWord(psymHdr+16,
							littleEndian);
	  loadAreas[loadAreaCount].loaded = 0;
	  loadAreaCount++;
	}
      psymOffset += psymSize;
    }
  /* Yuck. N^2 behavior (where N is the # of loadable sections). */
  for (x = 0; x < loadAreaCount; x++)
    {
      int which;
      int smallest = -1, smallestSz = -1;
      /* Find smallest not-loaded */
      for (which = 0; which < loadAreaCount; which++)
	{
	  if (! loadAreas[which].loaded)
	    {
	      if (smallest < 0 || loadAreas[which].offset < smallestSz)
		{
		  smallest = which;
		  smallestSz = loadAreas[which].offset;
		}
	    }
	}
      if (func (loadAreas[smallest].loadAddr,
		NULL,
		loadAreas[smallest].offset,
		loadAreas[smallest].filesize) != loadAreas[smallest].filesize)
	{
	  return 0;
	}
      loadAreas[smallest].loaded = 1;
    }

  /* FIXME: If no program segment header, loop over sections instead.  */
  /* FIXME: admin part of program segment is loaded.  */

  *entry_point = entryPoint;
  *little_endian = littleEndian;
  return 1;
}
