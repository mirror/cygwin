# mep testcase for break -*- Asm -*-
# mach: all
# as:
# ld: -Tdata 0
# configfile(): mep-gloss.conf

	.include "testutils.inc"
.data
.org 0x10
vector:
	pass

	start
	.global break
break:
	break

wrong:
	fail
	fail
	fail
	fail
