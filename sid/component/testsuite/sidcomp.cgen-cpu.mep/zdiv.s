# mep testcase for the zdiv exception
# mach: all
# as:
# ld: -Tdata 0
# configfile(): mep-gloss.conf
# configline():	set cpu div-option? true

	.include "testutils.inc"
.data
.org 0xc
vector:
	jmp test

	start
	mov $0, 2
	mov $1, 0
	# this will cause the zdiv exception to occur
	div $0, $1

wrong:
	fail

test:
	# assert exc.exc = 3
	ldc $0, $exc
	and3 $0, $0, 0xf
	assert $0, 3
	pass
