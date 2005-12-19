# -*- asm -*-

# Make a system call with various numbers of arguments
	.macro syscall0 call
	   addi    r1,r0,\call
	   ;jal    r14,r0
	   SI  r14
	   ;add R0, R0, R0 ; Delay Slot.
	   nop
	.endm
	.macro syscall1 call arg1
	   addi   r2,r0,\arg1
	   syscall0 \call
	.endm
	.macro syscall2 call arg1 arg2
	   addi    r3,r0,\arg2
	   syscall1 \call,\arg1
	.endm
	.macro syscall3 call arg1 arg2 arg3
	   addi    r4,r0,\arg3
	   syscall2 \call,\arg1,\arg2
	.endm


# Exit with return code
	;.macro exit rc
	;   syscall1    #2,\rc
	;.endm

# Fill r3/r4 here rather than via syscall3()
	.macro write_stdout string,len
	loadval    r3,\string
	loadval   r4, \len
	syscall1  #5, #1
	.endm

# Exit with return code
        .macro exit rc
        syscall1    #1,#\rc
        .endm

# Pass the test case
        .macro pass
	   write_stdout passmsg,5
	   exit 0
        .endm

# Fail the testcase
        .macro fail
	   write_stdout failmsg,5
	   exit 1
        .endm

# NOP
	.macro nop
	   add R0, R0, R0
        .endm
	
# Assert that the contents of reg1 equals the contents of reg2.
	.macro assertr reg1 reg2
	   breq \reg1, \reg2, exit\@
           ;add R0, R0, R0 ; Delay slot.
	   nop
	   fail
exit\@:
        .endm

# Assert that a register contains 0.
	.macro assertz reg
	   breq \reg, R0, exit\@
	   ;add R0, R0, R0 ; Delay Slot.
           nop
	   fail
exit\@:
	.endm

# Assert that the contents of register reg match val.
	.macro assertv reg val
           addui R10,R0,#%hi16(\val)
	   lsli R10, R10, #16
	   addui R10, R10, #%lo16(\val)
	   breq \reg, R10, exit\@
	   ;dd R0, R0, R0 ; Delay Slot.
           nop
	   fail
exit\@:
	.endm

# Load the a word from memory into register reg.
# This is not for putting the address of a label into
	.macro loadwl reg label
           addui R10, R0, #%hi16(\label)
	   lsli R10, R10, #16
	   addui R10, R10, #%lo16(\label) ; Address of label is now in R8.
	   ldw \reg, R10, #0 ; Put the word at label in reg.
	   nop
	.endm	

# Load the a value into register reg.  Note that if you want to
# put the address of a label into a register, you use this.
# Maybe I should duplicate this as loadaddr to avoid confusion.
	.macro loadval reg val
           addui R10, R0, #%hi16(\val)
	   lsli R10, R10, #16
	   addui R10, R10, #%lo16(\val) ; Address of label is now in R8.
	   addui \reg, R10, #0 ; Put the word at label in reg.
	.endm	





# Canonical test case header
	.macro start
	
	.data
	.align 4
failmsg:
	.ascii "fail\n"
passmsg:
	.ascii "pass\n"

	.text
	.global _start
_start:
	.endm
	


