# mep testcase for reading the mb0 register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global mb0
mb0:
	ldc $0, $mb0
	bnez $0, wrong
okay:
	pass
wrong:
	fail
