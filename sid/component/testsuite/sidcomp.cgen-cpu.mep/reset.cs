# configfile(): reset-1s.conf
# mach: all
# ld: -Tdata 0

	.include "testutils.inc"
.data
.org 0
	.global vector
vector:
	pass

	start
	bra 0
	fail
