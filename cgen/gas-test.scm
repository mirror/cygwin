; CPU description file generator for the GAS testsuite.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; This is invoked to build allinsn.exp and a script to run to
; generate allinsn.s and allinsn.d.

; Specify which application.
(set! APPLICATION 'GAS-TEST)

; Called before/after the .cpu file has been read.

(define (gas-test-init!) (opcodes-init!))
(define (gas-test-finish!) (opcodes-finish!))

; Called after .cpu file has been read and global error checks are done.
; We use the `tmp' member to record the syntax split up into its components.

(define (gas-test-analyze!)
  (opcodes-analyze!)
  (map (lambda (insn)
	 (elm-xset! insn 'tmp (syntax-break-out (insn-syntax insn))))
       (non-multi-insns (current-insn-list)))
  *UNSPECIFIED*
)

; Methods to compute test data.
; The result is a list of strings to be inserted in the assembler
; in the operand's position.

(method-make!
 <hw-asm> 'test-data
 (lambda (self n)
   ; FIXME: floating point support
   (let ((signed (list 0 1 -1 2 -2))
	 (unsigned (list 0 1 2 3 4))
	 (mode (elm-get self 'mode)))
     (map number->string
	  (list-take n
		     (if (eq? (mode:class mode) 'UINT)
			 unsigned
			 signed)))))
)

(method-make!
 <keyword> 'test-data
 (lambda (self n)
   (let* ((values (elm-get self 'values))
	  (n (min n (length values))))
     ; FIXME: Need to handle mach variants.
     (map car (list-take n values))))
)

(method-make!
 <hw-address> 'test-data
 (lambda (self n)
   (let ((test-data '("foodata" "4" "footext" "-4")))
     (list-take n test-data)))
)

(method-make!
 <hw-iaddress> 'test-data
 (lambda (self n)
   (let ((test-data '("footext" "4" "foodata" "-4")))
     (list-take n test-data)))
)

(method-make-forward! <hw-register> 'indices '(test-data))
(method-make-forward! <hw-immediate> 'values '(test-data))

; This can't use method-make-forward! as we need to call op:type to
; resolve the hardware reference.

(method-make!
 <operand> 'test-data
 (lambda (self n)
   (send (op:type self) 'test-data n))
)

; Given an operand, return a set of N test data.
; e.g. For a keyword operand, return a random subset.
; For a number, return N numbers.

(define (operand-test-data op n)
  (send op 'test-data n)
)

; Given the broken out assembler syntax string, return the list of operand
; objects.

(define (extract-operands syntax-list)
  (let loop ((result nil) (l syntax-list))
    (cond ((null? l) (reverse! result))
	  ((object? (car l)) (loop (cons (car l) result) (cdr l)))
	  (else (loop result (cdr l)))))
)

; Given a list of operands for an instruction, return the test set
; (all possible combinations).
; N is the number of testcases for each operand.
; The result has N to-the-power (length OP-LIST) elements.

(define (build-test-set op-list n)
  (let ((test-data (map (lambda (op) (operand-test-data op n)) op-list))
	(len (length op-list)))
    ; FIXME: Make slicker later.
    (cond ((=? len 0) (list (list)))
	  ((=? len 1) test-data)
	  (else (list (map car test-data)))))
)

; Given an assembler expression and a set of operands build a testcase.
; TEST-DATA is a list of strings, one element per operand.

(define (build-asm-testcase syntax-list test-data)
  (let loop ((result nil) (sl syntax-list) (td test-data))
    ;(display (list result sl td "\n"))
    (cond ((null? sl)
	   (string-append "\t"
			  (apply string-append (reverse result))
			  "\n"))
	  ((string? (car sl))
	   (loop (cons (car sl) result) (cdr sl) td))
	  (else (loop (cons (car td) result) (cdr sl) (cdr td)))))
)

; Generate the testsuite for INSN.
; FIXME: This needs to be expanded upon.

(define (gen-gas-test insn)
  (logit 2 "Generating gas test data for " (obj:name insn) " ...\n")
  (string-append
   "\t.text\n"
   "\t.global " (gen-sym insn) "\n"
   (gen-sym insn) ":\n"
   (let* ((syntax-list (insn-tmp insn))
	  (op-list (extract-operands syntax-list))
	  (test-set (build-test-set op-list 2)))
     ;(display test-set) (newline)
     (string-map (lambda (test-data)
		   (build-asm-testcase syntax-list test-data))
		 test-set))
   )
)

; Generate the shell script that builds the .d file.
; .d files contain the objdump result that is used to see whether the
; testcase passed.
; We do this by running gas and objdump.
; Obviously this isn't quite right - bugs in gas or
; objdump - the things we're testing - will cause an incorrect testsuite to
; be built and thus the bugs will be missed.  It is *not* intended that this
; be run immediately before running the testsuite!  Rather, this is run to
; generate the testsuite which is then inspected for accuracy and checked
; into CVS.  As bugs in the testsuite are found they are corrected by hand.
; Or if they're due to bugs in the generator the generator can be rerun and
; the output diff'd to ensure no errors have crept back in.
; The point of doing things this way is TO SAVE A HELL OF A LOT OF TYPING!
; Clearly some hand generated testcases will also be needed, but this
; provides a good test for each instruction.

(define (cgen-build.sh)
  (logit 1 "Generating gas-build.sh ...\n")
  (string-append
   "\
#/bin/sh
# Generate test result data for " (current-arch-name) " GAS testing.
# This script is machine generated.
# It is intended to be run in the testsuite source directory.
#
# Syntax: build.sh /path/to/build/gas

BUILD=$1

if [ ! -f $BUILD/as-new ] ; then
    echo \"$BUILD is not a GAS build directory.\"
    exit 1
fi

# Put results here, so we preserve the existing set for comparison.
rm -rf tmpdir
mkdir tmpdir
cd tmpdir

function gentest {
    rm -f a.out
    $BUILD/as-new ${1}.s -o a.out
    echo \"#as:\" >${1}.d
    echo \"#objdump: -dr\" >>${1}.d
    echo \"#name: $1\" >>${1}.d
    $BUILD/../binutils/objdump -dr a.out | \
	sed -e 's/(/\\\\(/g' -e 's/)/\\\\)/g' -e 's/[+]/\\\\+/g' -e 's/[*]/\\\*/g' | \
	sed -e 's/^.*file format.*$/.*: +file format .*/' \
	>>${1}.d
    rm -f a.out
}

# Now come all the testcases.
cat > allinsn.s <<EOF
 .data
foodata: .word 42
 .text
footext:\n"
    (string-map (lambda (insn)
		  (gen-gas-test insn))
		(non-multi-insns (current-insn-list)))
    "EOF\n"
    "\n"
    "# Finally, generate the .d file.\n"
    "gentest allinsn\n"
   )
)

; Generate the dejagnu allinsn.exp file that drives the tests.

(define (cgen-allinsn.exp)
  (logit 1 "Generating allinsn.exp ...\n")
  (string-append
   "\
# " (string-upcase (current-arch-name)) " assembler testsuite.

if [istarget " (current-arch-name) "*-*-*] {
    run_dump_test \"allinsn\"
}\n"
   )
)
