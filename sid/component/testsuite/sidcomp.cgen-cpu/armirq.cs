# sim(): armeit.conf
# output(): pass\n
# mach(): all

# Set up, trigger, and verify an IRQ interrupt.

	.include "armutils.inc"

# Entry point.

	start

# Prepare to handle interrupts.

	mrs r4,cpsr
	bic r4,r4,#IBIT
	bic r4,r4,#MODE_BITS
	orr r4,r4,#SYSTEM_MODE
	msr cpsr,r4

# Build an instruction to branch to the interrupt handler.

	bl . + 8
	.word irq_interrupt_handler
	ldr r4,[r14]
	sub r4,r4,#0x1c
	sub r4,r4,#8
	mov r4,r4,asr #2
	add r4,r4,#0xea000000
	mov r5,#IRQ_ADDR
	str r4,[r5]

# Write to memory location 0x80000001.  A tcl device at that address will wake
# up and then trigger an IRQ interrupt.

	mov r7,#1 @ set to zero by irq handler

	mov r4,#0x80000001
	mov r5,#0
	strb r5,[r4]

# Wait for an IRQ, but don't wait forever.
# The IRQ handler will set r7 to zero.

	mov r4,#256
wait_irq:
	cmp r7,#0
	beq irq_happened
	subs r4,r4,#1
	bne wait_irq
	fail

irq_happened:

# Returned from interrupt.  Verify register contents.

# FIXME: unfinished

# All done, print "pass".

done:
	pass

# IRQ interrupt handler

irq_interrupt_handler:

# Make sure we're in IRQ mode.

	mrs r4,cpsr
	and r4,r4,#MODE_BITS
	test_h_gr r4, IRQ_MODE

# Return from interrupt.

	mov r7,#0
	subs pc,r14,#4

# We should have returned from the interrupt, fail if not.

	fail
