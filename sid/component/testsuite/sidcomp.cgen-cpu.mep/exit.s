# mep testcase for terminating the simulation by writing to the ctrl bus.
# mach: all
# configfile():	mep-gloss.conf
# configline():	new hw-mapper-basic ctrl-map
# configline():	new hw-glue-probe-bus exit-watchdog
# configline():	new hw-memory-ram/rom-basic mem
# configline():	set mem size 4
# configline():	connect-bus exit-watchdog downstream mem read-write-port
# configline():	connect-bus ctrl-map \[4*64816-64816\] exit-watchdog upstream
# configline():	connect-bus cpu control-space ctrl-map access-port
# configline():	connect-pin exit-watchdog address -> main stop!
# configline():	connect-pin exit-watchdog address -> yield-net input

	.include "testutils.inc"

	.macro print arg
	.global print
print:	
	mov $1, 1				# fd 1 = stdout
	movu $7, %lo(\arg)			# put pointer to
	movh $2, %hi(\arg)			# string in $2.
	or $2, $7
	mov $3, 5				# strlen("pass\n")
	sys_write
	.endm

	start
	# (rc << 8) | newlib::sigAbrt.
	mov $0, 6
	print passmsg
	stcb $0, 0xfd30

wrong:
	# if we get here, add the word "fail" to the output, causing
	# the pass string to not match in the test harness (thus
	# failing).
	fail
