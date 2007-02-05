# mep testcase for reading the rcfg register
# mach: all
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	start
	.global rcfg
rcfg:
	ldc $0, $rcfg
	mov $7, 1
	sll $7, 24
	or3 $7, $7, 0x100
	sub $0, $7
	bnez $0, wrong
okay:
	pass
wrong:
	fail
