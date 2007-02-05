# mep testcase for reading the cfg register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global cfg
cfg:
	ldc $0, $cfg
	mov $7, 0x28
	sub $0, $7
	bnez $0, wrong
okay:
	pass
wrong:
	fail
