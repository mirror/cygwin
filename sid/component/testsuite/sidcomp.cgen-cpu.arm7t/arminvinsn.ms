# output(): Fault (invalid insn) pc=0x8044\n
# mach(): all

# Invoke an invalid instruction to test the angel component's handling of it.

	.include "armutils.inc"

	start

# This is the "undefined" special insn.
# ??? The expected output specifies the address of this insn as 0x8044.
# For one, we want to ensure a correct pc is set when the fault handler
# is called.  However, we could make this less fragile.
	.word 0xe7ffffff

	fail
