# r0-r3 are used as tmps, consider them call clobbered by these macros.
# This uses the angel rom monitor calls.
# ??? How do we use the \@ facility of .macros ???
# @ is the comment char!

# Various useful constants.

	.equ NBIT, 0x80000000
	.equ ZBIT, 0x40000000
	.equ CBIT, 0x20000000
	.equ VBIT, 0x10000000

	.equ IBIT, 0x80
	.equ FBIT, 0x40
	.equ TBIT, 0x20

	.equ MODE_BITS, 0x1f
	.equ USER_MODE, 0x10
	.equ FIQ_MODE, 0x11
	.equ IRQ_MODE, 0x12
	.equ SUPERVISOR_MODE, 0x13
	.equ ABORT_MODE, 0x17
	.equ UNDEFINED_MODE, 0x1b
	.equ SYSTEM_MODE, 0x1f

	.equ RESET_ADDR, 0
	.equ UNDEFINED_INSN_ADDR, 4
	.equ SWI_ADDR, 8
	.equ PREFETCH_ABORT_ADDR, 12
	.equ DATA_ABORT_ADDR, 16
	.equ IRQ_ADDR, 0x18
	.equ FIQ_ADDR, 0x1c

# Move an arbitrary constant into REG.

	.macro mvi_h_gr reg, val
	ldr \reg,[pc]
	b . + 8
	.word \val
	.endm

# Move an address into REG.

	.macro mvaddr_h_gr reg, addr
	ldr \reg,[pc]
	b . + 8
	.word \addr
	.endm

# Use this macro as the entry point of your testcase.

	.macro start
	.data
failmsg:
	.asciz "fail\n"
passmsg:
	.asciz "pass\n"
	.text

do_pass:
	mov r0, #4 @ write0 angel call
	ldr r1, passmsg_addr
	swi 0x123456
	b do_exit
passmsg_addr:
	.word passmsg

do_fail:
	mov r0, #4 @ write0 angel call
	ldr r1, failmsg_addr
	swi 0x123456
	b do_exit
failmsg_addr:
	.word failmsg

do_exit:
	bl . + 8
	.word 0x20026
	mov r0,#0x18
	ldr r1,[r14]
	swi #0x123456
	# If that returns, punt with a sigill.
# This is "undefined" but it's not properly decoded yet.
	.word 0x07ffffff
# This is stc which isn't recognized yet.
	stc 0,cr0,[r0]

	.global _start
_start:
	.endm

# *** Other macros know pass/fail are 4 bytes in size!  Yuck.

	.macro pass
	b do_pass
	.endm

	.macro fail
	b do_fail
	.endm

# Verify REG has a certain value.
# Other macros know this only clobbers r0.

	.macro test_h_gr reg, val
	mvaddr_h_gr r0, \val
	cmp \reg, r0
	beq . + 8
	fail
	.endm

# Set the condition codes.  unfinished

	.macro mvi_h_cc c, n, v, z
	ldi8 r0, 0
	ldi8 r1, 1
	.if xxx
	cmp r0, r1
	.else
	cmp r1, r0
	.endif
	.endm

# Verify the condition codes have a certain value.

	.macro test_h_cc c, n, v, z
	.if xxx
	bc . + 8
	fail
	.else
	bnc . + 8
	fail
	.endif
	.endm
