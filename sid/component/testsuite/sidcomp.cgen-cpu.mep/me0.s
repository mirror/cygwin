# mep testcase for reading the me0 register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global me0
me0:
	ldc $0, $me0
	bnez $0, wrong
okay:
	pass
wrong:
	fail
