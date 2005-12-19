# mach(): mt

	.include "testutils.inc"
	start

	loadwl R6, value1    
	loadwl R7, value2

	assertv R6,$1

test1:  ; test sub
	sub R8,R7,R6
	assertv R8, $1233

test2:  ; test subi 
        subi R8, R8, #1
        assertv R8, $1232
	

test3:  ; test subi for negative values
        addui R8, R0, #0      ; Clear R8: R8 contains 0.
        loadval R8, -4         ; Put expected result in R8.
        loadwl R6, value1     ; R6 contains 1.
        subi R6, R6, #5       ; R6 = R6 - 5 = -4.
        assertv R6, -4
	ei
	addi R8, R0, #1	      ; Put new expected value in R8.
	subi R6, R6, #-5      ; R6 = R6 - -5 = 1.
	ei
	assertv R6, 1

test4:  ;test subui
	loadwl R6 value2
	subui R8, R6, #1
	assertv R8, $1233

test5: ; test subu
	loadwl R6, value3 ; R6 should contain 0xfffffffe
	loadval R7,1 ; R7 should contain 0xfffffffe
	subu R8, R6, R7 
	assertv R8, 0xfffffffd 

test6: ; test subu
	loadval R6, 0xfffffffe ; R6 should contain 0xfffffffe
	loadval R7,1 ; R7 should contain 0xfffffffe
	subu R8, R6, R7 
	assertv R8, 0xfffffffd 

test7: ; test sub with same case as subu
	loadval R6, 0xfffffffe ; R6 should contain 0xfffffffe
	loadval R7,1 ; R7 should contain 0xfffffffe
	subu R8, R6, R7 
	assertv R8, -3

pass:
	pass

	.data
	.align 4
value1: .word 0x0001
value2:	.word 0x1234
value3: .word 0xfffffffe
