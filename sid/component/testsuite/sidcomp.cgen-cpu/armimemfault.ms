# output(): Fault (memory, 0xff000000) pc=0xff000000\n
# mach(): all

# Invoke a instruction fetch memory fault to test the angel component's handling of it.

	.include "armutils.inc"

	start

	bl . + 8
# Address of unmapped area
	.word 0xff000000
	ldr r15,[r14]

	fail
