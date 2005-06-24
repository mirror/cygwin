# mach(): ms1

        .INCLUDE "testutils.inc"
	start

	loadwl R7 value2    ; Load 0x0f0f0f0f into R7
	addui R8, R0, #4    ; Load the value we want to shift by (4) into R8.

test1:
	; Test lsl - basic test.
	lsl R7, R7, R8 ; Shift left by 4 bits: R7 should be 0xf0f0f0f0.

	; Put the expected result into R9.
	loadwl R9, value3

	; Check to see if it's correct.
	assertr R9,R7

test2:
	; Test lsr - basic test.
	lsr R7, R7, R8 ; Shift right by 4 bits: R7 should be 0x0f0f0f0f.

	; Put the expected value in R9
	loadwl R9, value2

	; Check to see if it's correct.
	assertr R9,R7

test3:
	; Test lsli - basic test.
	lsli R7, R7, #4 ; Shift left by 4 bits: R7 should be 0xf0f0f0f0.

	; Put the expected result into R9.
	loadwl R9, value3

	; Check to see if it's correct.
	assertr R9,R7

test4:
	; Test lsri - basic test.
	lsri R7, R7, #4 ; Shift right by 4 bits: R7 should be 0x0f0f0f0f.

	; Put the expected value in R9
	loadwl R9, value2

	; Check to see if it's correct.
	assertr R9,R7

	; Test asr.
test5:
	loadwl R7, value3
	addui R8, R0, #16
	asr R9, R7,R8
	assertv R9, $fffff0f0

test6:
	loadwl R7, value2
	addui R8, R0, #16
	asr R9, R7,R8
	assertv R9, $f0f

	; Test asri.
test7:
	loadwl R7, value3
	asri R9, R7,#16
	assertv R9, $fffff0f0

test8:
	loadwl R7, value2
	asri R9, R7,#16
	assertv R9, $f0f

	; Test shifts of 32 bits and make sure it results in 0.
	
pass:
	pass
	

	.data
	.align 4
value1:	.word 0x1
value2:	.word 0x0f0f0f0f
value3: .word 0xf0f0f0f0
