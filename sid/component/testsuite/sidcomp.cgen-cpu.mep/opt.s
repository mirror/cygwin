# mep testcase for reading the opt register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global opt
opt:
	ldc $0, $opt
	mov $7, 0x0005
	sll $7, 12
	sub $0, $7
	bnez $0, wrong
okay:
	pass
wrong:
	fail
