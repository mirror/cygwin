# mach(): ms1

        .include "testutils.inc"
	start

	loadwl R1, value1
	loadwl R2, value2

testbrlt:
	assertv R14, 0
	brlt R1, R2, testbrle
	addi R14, R0, #1

testbrle:
	assertv R14, 1
	brle R1,R2, testbrle2
	addi R14, R14, #1

testbrle2:
	assertv R14, 2
	brle R1, R1, testbreq
        addi R14, R14, #1

testbreq:
	assertv R14, 3
	breq R1, R1, testjmp
	addi R14, R14, #1

testjmp:
	assertv R14, 4
	jmp testjal
	addi R14, R14, #1

testjal:
  	assertv R14, 5
	loadval R2, nobranchbrle
	nop

jallbl:	jal R3, R2
	addi R14, R14, #1

nobranchbrle:
	assertv R14, 6
	assertv R3, (jallbl + 8) ; Did jal store the right return address?
	brle R2, R1, fail
        nop

nobranchbrlt:
	brlt R2, R1, fail
        nop

nobranchbreq:
	breq R2, R1, fail
        nop

brne:
	brne R0,R3,pass
	nop
	fail

pass:
	pass

fail:
	fail

	.data
	.align 4
value1: .word 0001
value2:	.word 0x1234
