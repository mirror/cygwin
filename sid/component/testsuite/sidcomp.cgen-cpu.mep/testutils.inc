# Support macros for the assembly test cases.

	.macro start
	.data
	.align 4
failmsg:
	.ascii "fail\n"
passmsg:
	.ascii "pass\n"

	.global __sbss_start
__sbss_start:
	.global __sbss_end
__sbss_end:

	.text
	.global _start
_start:
	.endm

	# Assert that a register has a certain value.
	# Branch to a label "wrong" if the test fails.
	.macro assert reg value
	mov $7, \value
	sub $7, \reg
	bnez $7, wrong
	.endm

	.macro sys_write
	.2byte 0x7800 | (5 & 0xe) << 7 | (5 & 1) << 4
	.endm

	.macro sys_exit rc
	mov $1, \rc
	# sys call #1 (exit)
	.2byte 0x7800 | (1 << 4)
	.endm

	.macro pass
	# fd 1 is stdout.
	mov $1, 1
	# put pointer to string in $2.
	movu $7, %lo(passmsg)
	movh $2, %hi(passmsg)
	or $2, $7
	# put strlen("pass\n") in $3.
	mov $3, 5
	# make the sys calls.
	sys_write
	sys_exit 1
	.endm

	.macro fail
	# fd 1 is stdout.
	mov $1, 1
	# put pointer to string in $2.
	movu $7, %lo(failmsg)
	movh $2, %hi(failmsg)
	or $2, $7
	# put strlen("fail\n") in $3.
	mov $3, 5
	# make the sys calls.
	sys_write
	sys_exit 1
	.endm
