#include "bfd.h"
#include "dis-asm.h"
#include "cgen/bitset.h"

// ansidecl.h interferes with this perfectly ordinary word
#undef AND

typedef int (*READMEM)(bfd_vma memaddr, bfd_byte *myaddr, unsigned int length, struct disassemble_info *info);
typedef void (*MEMERR)(int status, bfd_vma memaddr, struct disassemble_info *info);
typedef void (*PRINTADDR)(bfd_vma addr, struct disassemble_info *info);
typedef int (*SYMATADDR)(bfd_vma addr, struct disassemble_info * info);

void cgen_disassemble(bfd_vma, disassemble_info *, void *, READMEM, MEMERR, PRINTADDR, SYMATADDR, disassembler_ftype, enum bfd_flavour, enum bfd_architecture, int machine, enum bfd_endian, const char *, CGEN_BITSET *isas);
