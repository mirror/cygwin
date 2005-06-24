# mach(): ms1

	.include "testutils.inc"
	start

	loadwl R7, value1    
	loadwl R8, value2

testadd:
	add R9, R7, R8
	assertv R9, $1235

testaddi:
	addi R9, R8, #1     ; Positive immediate value
	assertv R9, $1235

testaddiagain:
	addi R9, R9, #-1
	assertv R9, $1234

testaddionemoretime:
	loadwl R7, value1     ; R7 contains 1.
	addui R9, R0, #0      ; Clear R9: R9 contains 0.
	addi R9, R0, #-3      ; Put expected result in R9.
	addi R7, R7, #-4      ; R7 = R7 + -4 = -3
	assertv R7,-3

testaddui:
	addui R9, R8, #1
	assertv R9, $1235

testadduiagain:
	loadval R7, -6
	addui R9, R7, #1
	assertv R9, -5

pass:
	pass

	.data
	.align 4
value1: .word 0x1
value2:	.word 0x1234
