# configfile(): nmi-1s.conf
# mach: all
# ld: -Tdata 0

	.include "testutils.inc"
.data
.org 0x4
	.global vector
vector:
	pass

	start
	# hardware interrupts are disabled at startup
	# the nmi should stomp right on through!

forever:
	bra 0
	fail
