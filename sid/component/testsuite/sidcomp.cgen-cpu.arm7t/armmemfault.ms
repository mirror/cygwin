# output(): Fault (memory, 0xff000000) pc=0x8050\n
# mach(): all

# Invoke a memory fault to test the angel component's handling of it.

	.include "armutils.inc"

	start

	bl . + 8
# Address of unmapped area
	.word 0xff000000
	ldr r4,[r14]
# ??? The expected output specifies the address of this insn as 0x8050.
# For one, we want to ensure a correct pc is set when the fault handler
# is called.  However, we could make this less fragile.
	ldr r5,[r4]

	fail
