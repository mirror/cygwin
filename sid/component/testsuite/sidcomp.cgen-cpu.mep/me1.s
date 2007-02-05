# mep testcase for reading the me1 register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global me1
me1:
	ldc $0, $me1
	bnez $0, wrong
okay:
	pass
wrong:
	fail
