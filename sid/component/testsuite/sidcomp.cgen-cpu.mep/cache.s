# mep testcase for the ri exception on the cache insn
# mach: all
# as:
# ld: -Tdata 0
# configfile(): mep-gloss.conf
# configline():	set cpu raise-ri-exception? true

	.include "testutils.inc"
.data
.org 0x30
vector:
	jmp test

	start
	ldc     $0,$ccfg
	# this will cause the ri exception to occur
	cache	0,($12)

wrong:
	fail

test:
	# assert exc.exc = 2
	ldc $0, $exc
	and3 $0, $0, 0xf
	assert $0, 2
	pass
