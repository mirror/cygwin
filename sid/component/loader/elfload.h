/* Header for simple ELF loader
 *
 * Copyright (c) 1998, 2004 Red Hat
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
#ifndef ELF_LOAD_H
#define ELF_LOAD_H

#define BYTE(X,offset) (((X)[offset]) & 255)
#define fetchShortLittle(addr) (BYTE((addr),1)*256+BYTE((addr),0))
#define fetchWordLittle(addr) (fetchShortLittle (addr) + fetchShortLittle((addr) + 2) * 65536)
#define fetchQuadLittle(addr) (fetchWordLittle ((addr)) + ((unsigned long long)fetchWordLittle((addr) + 4) << 32))
#define fetchShortBig(addr) (BYTE((addr),0)*256+BYTE((addr),1))
#define fetchWordBig(addr) (fetchShortBig (addr) * 65536 + fetchShortBig((addr) + 2))
#define fetchQuadBig(addr) (((unsigned long long)fetchWordBig ((addr)) << 32) + fetchWordBig((addr) + 4))
#define fetchShort(ADDR,LITTLE) ((LITTLE) ? fetchShortLittle((ADDR)) : fetchShortBig((ADDR)))
#define fetchWord(ADDR,LITTLE) ((LITTLE) ? fetchWordLittle((ADDR)) : fetchWordBig((ADDR)))
#define fetchQuad(ADDR,LITTLE) ((LITTLE) ? fetchQuadLittle((ADDR)) : fetchQuadBig((ADDR)))

struct TextSection
{
  unsigned long long lbound;
  unsigned long long hbound;
};

/* 
   PFLOAD represents a function that will read file data. 
   DEST or DEST2 is used as the destination address to be written with the
   raw file data. If DEST is NULL, then DEST2 should be used.
   OFFSET is the byte offset into the file to be read.
   AMOUNT is the number of bytes to read.
   INSN_SPACE is true if this data should be loaded into instruction space.

   If OFFSET and AMOUNT are both negative, then the file should be
   closed (any remaining bytes are to be ignored). */

typedef int (*PFLOAD)(unsigned long long dest, char *dest2, unsigned long long offset, unsigned long long amount, int insn_space);
/* Is address in the text segment? */
extern int textSectionAddress(unsigned long long, const struct TextSection *);
/* Load an ELF executable into memory. FUNC is used to actually read the
   file. */
extern int readElfFile(PFLOAD func, unsigned*, int*, const struct TextSection **);

#define EI_CLASS 4
#define ELFCLASS64  2 /* 64 bit */
#define EI_DATA 5
#define ELFDATA2LSB 1 /* little endian */
#define ELFDATA2MSB 2 /* big endian */

/* Elf program header flags */
#define PF_X	0x01	/* executable */
#define PF_R	0x04	/* readable */

/* ELF section header flags */
#define SHF_EXECINSTR	(1 << 2)	/* Executable machine instructions */

#endif
