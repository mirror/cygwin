# mep testcase for RI exception generation -*- Asm -*-
# mach: all
# as:
# ld: -Tdata 0
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	.macro reserved
	.word 0x100b
	.endm

.data
.org 0x30
	.global vector
vector:
	pass

	start
	.global ritest
ritest:
	nop
	nop
	nop
	reserved

wrong:
	fail
