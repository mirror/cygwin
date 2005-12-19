# mach(): ms1

	.include "testutils.inc"
	start

test1:  ; mul: 
	loadval R6, 0xfff
	loadval R7, 0xfff
	mul R8,R7,R6
	assertv R8, 0xffe001

test2:
	; mul: -1*1 = +1
	loadval R6, 0x1
	loadval R7, -1
	mul R8,R7,R6
	assertv R8, -1

test3:  
	; mul: -1*-1 = 1
	loadval R6, -1
	loadval R7, -1
	mul R8,R7,R6
	assertv R8, 1

test4:
	; mul: 0x7fff * 0x7fff = 0x3fff0001
	loadval R6, 0x7fff
	loadval R7, 0x7fff
	mul R8,R7,R6
	assertv R8, 0x3fff0001


test5:  ; muli
	loadval R6, 0xfff
	muli R8,R6,#$fff
	assertv R8, 0xffe001

test6:
	; muli: -1*-1 = +1
	loadval R6, -1
	muli R8,R6, #-1
	assertv R8, 1

test7:  
	; muli: -1*1 = -1
	loadval R6, 1
	muli R8,R6,#-1
	assertv R8, -1

test8:
	; muli: 0x7fff * 0x7fff = 0x3fff0001
	loadval R6, 0x7fff
	muli R8,R7,#$7fff
	assertv R8, 0x3fff0001

	pass

	.data
	.align 4
value1: 
	.word 0xffff

