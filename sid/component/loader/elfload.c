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

unsigned char fileHeader [64];
unsigned char psymHdr[56];

#define PT_LOAD 1

struct LoadAreas
{
  host_int_8 loadAddr;
  host_int_8 filesize;
  host_int_8 offset;
  int flags;
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
  host_int_8 psymOffset;
  int psymSize;
  int psymNum;
  host_int_8 entryPoint = 0;
  int loadAreaCount = 0;
  int x;
  int littleEndian;
  int sixtyfourbit;

  /* This is relatively straightforward. We first read in the file header,
     find out how many sections there are, determine which ones are loadable
     (via the psym header), and load them.

     There is one major failing, tho--if the psym header isn't at the front
     of the file, and we're loading from a stream that we can't back
     up on, we will lose.  */
  if (func (NULL, fileHeader, 0, 64, 0) != 64)
    {
      return 0;
    }

  /* Check this is an ELF file.  */
  if (fileHeader[0] != 0x7f
    || fileHeader[1] != 'E'
    || fileHeader[2] != 'L'
    || fileHeader[3] != 'F')
      return 0;

  sixtyfourbit = (fileHeader[EI_CLASS] == ELFCLASS64);
  littleEndian = (fileHeader[EI_DATA] == ELFDATA2LSB);

  if (sixtyfourbit) 
    {
      entryPoint = fetchQuad (fileHeader+24, littleEndian);
      psymOffset = fetchQuad (fileHeader+32, littleEndian);
      psymSize = fetchShort (fileHeader+54, littleEndian);
      psymNum = fetchShort (fileHeader+56, littleEndian);
    }
  else
    {
      entryPoint = fetchWord (fileHeader+24, littleEndian);
      psymOffset = fetchWord (fileHeader+28, littleEndian);
      psymSize = fetchShort (fileHeader+42, littleEndian);
      psymNum = fetchShort (fileHeader+44, littleEndian);
    }
  for (x = 0; x < psymNum; x++)
    {
      if (sixtyfourbit)
        {
	  if (func (NULL, psymHdr, psymOffset, 56, 0) != 56)
	    {
	      return 0;
	    }
	  if (fetchWord (psymHdr, littleEndian) == PT_LOAD)
	    {
	      loadAreas[loadAreaCount].loadAddr = fetchQuad(psymHdr+24,
							    littleEndian);
	      loadAreas[loadAreaCount].offset = fetchQuad(psymHdr+8, littleEndian);
	      loadAreas[loadAreaCount].filesize = fetchQuad(psymHdr+32,
							    littleEndian);
	      loadAreas[loadAreaCount].flags = fetchWord(psymHdr+4, littleEndian);
	      loadAreas[loadAreaCount].loaded = 0;
	      loadAreaCount++;
	    }
        }
      else
        {
	  if (func (NULL, psymHdr, psymOffset, 32, 0) != 32)
	    {
	      return 0;
	    }
	  if (fetchWord (psymHdr, littleEndian) == PT_LOAD)
	    {
	      loadAreas[loadAreaCount].loadAddr = fetchWord(psymHdr+12,
								    littleEndian);
	      loadAreas[loadAreaCount].offset = fetchWord(psymHdr+4, littleEndian);
	      loadAreas[loadAreaCount].filesize = fetchWord(psymHdr+16,
							    littleEndian);
	      loadAreas[loadAreaCount].flags = fetchWord(psymHdr+24, littleEndian);
	      loadAreas[loadAreaCount].loaded = 0;
	      loadAreaCount++;
	    }
        }
      psymOffset += psymSize;
    }
  /* Yuck. N^2 behavior (where N is the # of loadable sections). */
  for (x = 0; x < loadAreaCount; x++)
    {
      int which, is_insn;
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
      is_insn = (((loadAreas[smallest].loadAddr) & PF_X|PF_R) == (PF_X|PF_R))
	      || ((loadAreas[smallest].loadAddr >> 32) & 1);
      if (func (loadAreas[smallest].loadAddr,
		NULL,
		loadAreas[smallest].offset,
		loadAreas[smallest].filesize,
		is_insn) != loadAreas[smallest].filesize)
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
