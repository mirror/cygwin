# mep testcase for reading the id register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global id
id:
	ldc $0, $id
	mov $7, 0x100
	sub $0, $7
	bnez $0, wrong
okay:
	pass
wrong:
	fail
