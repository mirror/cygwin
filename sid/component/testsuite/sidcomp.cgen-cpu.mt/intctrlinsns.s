# mach(): ms1

	.include "testutils.inc"
	start

        ; Interrupts should be disabled at startup.
	si R4; Should issue error message.  
	ei 
        addi R1, R0, #75        
	si R4; Should be ok.
	ei
	di
	si R4; Should issue error message.
	loadval R6,pass
	reti R6
	add R0, R0, R0
	fail

pass:
	pass

