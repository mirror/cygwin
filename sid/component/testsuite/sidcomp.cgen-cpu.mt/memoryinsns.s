# mach(): ms1

        .include "testutils.inc"
	start

	; Test ldw with 0 offset.
test1:
	loadval R7, value1
	ldw R8, R7, #0  
	assertv R8, 0x1234

test2:
	loadval R7, value2
        ldw R8, R7, #0
	assertv R8, 0x12345678

test3:
	loadval R7, value3
	ldw R8, R7, #0;
	assertv R8, 0xbeef0000

	; Test ldw with non-zero offsets.
test4:
	loadval R7, value1
	ldw R8, R7, #4
	assertv R8, 0x12345678

test5:	
	loadval R7, value3
	ldw R8, R7, #-4
	assertv R8, 0x12345678

	; test stw with 0 offset
test6:  
	loadval R7, value2      ; Where we want to store the new value.
	loadval R8, $87654321   ; The new value: 0x87654321
        stw R8, R7, #0          ; Use stw to fetch the word
	loadwl R9, value2       ; Load it into R9 as well.  
	assertr R8, R9          ; Make sure they're equal.

test7:  
	loadval R7, value1  
	loadval R8, $4321  
        stw R8, R7, #0      
	loadwl R9, value1     
	assertr R8, R9       

test8:  
	loadval R7, value3  
	loadval R8, $feed  
        stw R8, R7, #0      
	loadwl R9, value3     
	assertr R8, R9      
 
	; test stw with non-zero offset
test9:  
	loadval R7, value1  
	loadval R8, $deadbeef 
        stw R8, R7, #4      
	loadwl R9, value2     
	assertr R8, R9      

test10: 
	loadval R7, value2  
	loadval R8, $deadbeef 
        stw R8, R7, #-4      
	loadwl R9, value1     
	assertr R8, R9      

;; The ldb, ldbu and stb instructions are not really part of the 
;; mRISC-I architecture.  They're part of the mRISC-II, but since
;; the compiler has switches to generate/not generate them (in
;; support of the future mRISC-II chip), we'll implement and
;; test them so that the compiler developer can use them to
;; test his code generation.

test11:
        loadval R7, value5
        ldb R8, R7, #0          ; 0xffffffde (0xde sign extd) should be in R8.
        assertv R8, 0xffffffde  

test12:
        loadval R7, value6
        ldb R8, R7, #-1
        assertv R8, 0xffffffde

test13:
        loadval R7, value5
        ldbu R8, R7, #0          ; 0xffffffde (0xde sign extd) should be in R8.
	assertv R8, 0xde  

test14:
        loadval R7, value6
        ldbu R8, R7, #-1         ; 0xffffffde (0xde sign extd) should be in R8.
        assertv R8, 0xde  

test15:
        loadval R7, value5      ; Where we want to store the new value.
        loadval R8, $fa         ; The new value: 0xfa
        stb R8, R7, #0          ; Store the new byte at value5
	ldbu R9, R7,#0          ; Put the new byte into R9
        assertr R8, R9          ; Make sure they're equal.

test16:
        loadval R7, value7      ; Where we want to store the new value.
        loadval R8, $ce         ; The new value: 0xce
        stb R8, R7, #-1         ; Put the new byte at value6
	loadval R9, value6      ; Get value 6 into R9
	ldbu R10, R9,#0          ; Read the byte at value6 into R10
        assertr R8, R10          ; Make sure they're equal.

;; ldw and stw are for word access and ignore the two low-order bits so that they
;; will only read a word from word-aligned addresses.  Therefore, if addr1 is
;; word-alligned, reading from/writing to addr1+[0,1,2,3] should produce the
;; same results.  The follow two tests check this behaviour.

test17:
	; These should all load the same word.
        loadval R7, value0
        ldw R8, R7, #0          ; Load word at value0 into R8.
        assertv R8, 0xaceface   

	ldw R8, R7, #1          ; Load word at value0 + 1 into R8.
        assertv R8, 0xaceface  

        ldw R8, R7, #2          ; Load word at value0 + 2 into R8.
        assertv R8, 0xaceface

	ldw R8, R7, #3          ; Load word at value0 + 3 into R8.
        assertv R8, 0xaceface

test18:
	; These should all write to the same location.
	loadval R7, value0
	loadval R8, 0xfeedbeef
	stw R8, R7, #0
	loadwl R9, value0
	assertv R9, 0xfeedbeef

	loadval R8, 0xbadbed   ; Change the value to be written to location value0
	stw R8, R7, #1         ; Write to address value0 + 1.
	loadwl R9, value0      ; Load word at value0 into R9.
	assertv R9, 0xbadbed   ; Make sure it's the same as the new value.
	
	loadval R8, 0xfeedcab  ; Change the value to be written to location value0
	stw R8, R7, #2         ; Write to address value0 + 2.
	loadwl R9, value0      ; Load word at address value0 into R9.
	assertv R9, 0xfeedcab

	loadval R8, 0xabcdef1  ; Change the value to be written to location value0
	stw R8, R7, #2         ; Write to address value0 + 3.
	loadwl R9, value0      ; Load word at address value0 into R9.
	assertv R9, 0xabcdef1

pass:
	pass

	.data
	.align 4
value0: .word 0xaceface
value1: .word 0x1234 
value2:	.word 0x12345678
	.align 1
value3: .byte 0xbe
value4: .byte 0xef
	.org 0x100
	.align 1
value5: .byte 0xde
value6: .byte 0xed
value7: .byte 0xaa
