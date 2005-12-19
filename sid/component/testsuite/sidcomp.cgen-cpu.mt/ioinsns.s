# mach(): ms1

	.include "testutils.inc"
	start

	loadwl R1, value1    
	loadwl R2, value2
        loadwl R3, value3

	outb R1, #0, R2
	outh R2, #0, R2
	outw R3, #0, R2
        inb R1, R1, #0
        assertv R1, 0
        inh R2, R2, #0
        assertv R2, 0
        inw R3, R3, #0
        assertv R3, 0

pass:
	pass

	.data
	.align 4
value1: .word 0001
value2:	.word 0x1234
value3: .word 0x5678
