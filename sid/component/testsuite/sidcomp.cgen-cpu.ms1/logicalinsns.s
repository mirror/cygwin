# mach(): ms1

        .include "testutils.inc"
	start
	
	loadval R6, value2 ; Use this throughout.  To get at value1 or value2,
	                   ; just use +/-1 offset.  No need to waste another reg.
	
	loadval R7, 0xffff     ; To be used as a mask value throughout.
	loadval R8, 0x0        ; To be used as a mask value throughout.
	ldw R9, R6, #0         ; R9 should contain 0xf0f0f0f0 for use throughout.

testand:
	and R10, R9, R7
        assertv R10, 0xf0f0 
	
testandi:
	andi R10, R9, #$ffff
        assertv R10, 0x0000f0f0    
	
testor:
        or R10, R9, R7
        assertv R10, 0xf0f0ffff   

testori:
        ori R10, R9, #$ffff
        assertv R10, 0xf0f0ffff   

testxor:
        xor R10, R9, R7
        assertv R10, 0xf0f00f0f    

testxori:
        xori R10, R9, #$ffff
        assertv R10, 0xf0f00f0f    

testnand:
        nand R10, R9, R7
        assertv R10, 0xffff0f0f

testnandi:
        nandi R10, R9, #$ffff
        assertv R10, 0xffff0f0f

testnor:
        nor R10, R9, R7
        ;assertv R10, 0x0f0f0000

testnori:
        nori R10, R9, #$ffff
        assertv R10, 0x0f0f0000

testxnor:
        xnor R10, R9, R7
        assertv R10, 0x0f0ff0f0

testxnori:
        xnori R10, R9, #$ffff
        assertv R10, 0x0f0ff0f0

testldui:
	ldui R10,#$beef
	assertv R10, 0xbeef0000

pass:
	pass
	

	.data
	.align 4
value1:	.word 0x1
value2: .word 0xf0f0f0f0
