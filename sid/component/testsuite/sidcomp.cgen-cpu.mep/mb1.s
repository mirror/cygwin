# mep testcase for reading the mb1 register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global mb1
mb1:
	ldc $0, $mb1
	bnez $0, wrong
okay:
	pass
wrong:
	fail
