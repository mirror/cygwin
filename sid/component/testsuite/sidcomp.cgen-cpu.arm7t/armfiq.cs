# sim(): armeit.conf
# output(): pass\n
# mach(): all

# Set up, trigger, and verify an FIQ interrupt.

	.include "armutils.inc"

# Entry point.

	start

# Prepare to handle interrupts.

	mrs r4,cpsr
	bic r4,r4,#FBIT
	bic r4,r4,#MODE_BITS
	orr r4,r4,#SYSTEM_MODE
	msr cpsr,r4

# Build an instruction to branch to the interrupt handler.

	bl . + 8
	.word fiq_interrupt_handler
	ldr r4,[r14]
	sub r4,r4,#0x1c
	sub r4,r4,#8
	mov r4,r4,asr #2
	add r4,r4,#0xea000000
	mov r5,#FIQ_ADDR
	str r4,[r5]

# Write to memory location 0x80000000.  A tcl device at that address will wake
# up and then trigger an FIQ interrupt.

	mov r7,#1 @ set to zero by fiq handler

	mov r4,#0x80000000
	mov r5,#0
	strb r5,[r4]

# Wait for an FIQ, but don't wait forever.
# The FIQ handler will set r7 to zero.

	mov r4,#256
wait_fiq:
	cmp r7,#0
	beq fiq_happened
	subs r4,r4,#1
	bne wait_fiq
	fail

fiq_happened:

# Returned from interrupt.  Verify register contents.

# FIXME: unfinished

# All done, print "pass".

done:
	pass

# FIQ interrupt handler

fiq_interrupt_handler:

# Make sure we're in FIQ mode.

	mrs r4,cpsr
	and r4,r4,#MODE_BITS
	test_h_gr r4, FIQ_MODE

# Return from interrupt.

	mov r7,#0
	subs pc,r14,#4

# We should have returned from the interrupt, fail if not.

	fail
