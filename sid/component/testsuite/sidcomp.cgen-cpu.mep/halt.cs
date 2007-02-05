# configfile(): interrupt-1s.conf
# mach: all
# ld: -Tdata 0

	.include "testutils.inc"
	start
	halt
okay:
	pass
