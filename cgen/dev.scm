; CGEN Debugging support.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; This file is loaded in during an interactive guile session to
; develop and debug CGEN.  The user visible procs are:
;
; (use-c)
; (load-opc)
; (load-sim)
; (cload #:arch arch #:machs "mach-list" #:isas "isa-list" #:options "options")

; First load fixup.scm to coerce guile into something we've been using.
; Guile is always in flux.
(load "fixup.scm")

(define srcdir ".")
(set! %load-path (cons srcdir %load-path))

; Utility to enable/disable compiled-in C code.

(define (use-c) (set! CHECK-LOADED? #t))
(define (no-c) (set! CHECK-LOADED? #f))

; Also defined in read.scm, but we need it earlier.
(define APPLICATION 'UNKNOWN)

; Supply the path name and suffic for the .cpu file and delete the analyzer
; arg from cpu-load to lessen the typing.
(define (cload . args)
  (let ((arch #f)
	(keep-mach "all")
	(keep-isa "all")
	(options ""))

    ; Doesn't check if (cadr args) exists or if #:arch was specified, but
    ; this is a debugging tool!
    (let loop ((args args))
      (if (null? args)
	  #f ; done
	  (begin
	    (case (car args)
	      ((#:arch) (set! arch (cadr args)))
	      ((#:machs) (set! keep-mach (cadr args)))
	      ((#:isas) (set! keep-isa (cadr args)))
	      ((#:options) (set! options (cadr args)))
	      (else (error "unknown option:" (car args))))
	    (loop (cddr args)))))

    (case APPLICATION
      ((UNKNOWN) (error "application not loaded"))
      ((DESC) (cpu-load (string-append arch ".cpu")
			keep-mach keep-isa options
			desc-init!
			desc-finish!
			desc-analyze!))
      ((OPCODES) (cpu-load (string-append arch ".cpu")
			   keep-mach keep-isa options
			   opcodes-init!
			   opcodes-finish!
			   opcodes-analyze!))
      ((GAS-TEST) (cpu-load (string-append arch ".cpu")
			    keep-mach keep-isa options
			    gas-test-init!
			    gas-test-finish!
			    gas-test-analyze!))
      ((SIMULATOR) (cpu-load (string-append arch ".cpu")
			     keep-mach keep-isa options
			     sim-init!
			     sim-finish!
			     sim-analyze!))
      ((SIM-TEST) (cpu-load (string-append arch ".cpu")
			    keep-mach keep-isa options
			    sim-test-init!
			    sim-test-finish!
			    sim-test-analyze!))
      (else (error "unknown application:" APPLICATION))))
)

; Use the debugging evaluator.
(if (not (defined? 'DEBUG-EVAL))
    (define DEBUG-EVAL #t))

; Tell maybe-load to always load the file.
(if (not (defined? 'CHECK-LOADED?))
    (define CHECK-LOADED? #f))

(define (load-opc)
  (load "read")
  (load "desc")
  (load "desc-cpu")
  (load "opcodes")
  (load "opc-asmdis")
  (load "opc-ibld")
  (load "opc-itab")
  (load "opc-opinst")
  (set! verbose-level 3)
  (set! APPLICATION 'OPCODES)
)

(define (load-gtest)
  (load-opc)
  (load "gas-test")
  (set! verbose-level 3)
  (set! APPLICATION 'GAS-TEST)
)


(define (load-sim)
  (load "read")
  (load "desc")
  (load "desc-cpu")
  (load "utils-sim")
  (load "sim")
  (load "sim-arch")
  (load "sim-cpu")
  (load "sim-model")
  (load "sim-decode")
  (set! verbose-level 3)
  (set! APPLICATION 'SIMULATOR)
)

(define (load-stest)
  (load-opc)
  (load "sim-test")
  (set! verbose-level 3)
  (set! APPLICATION 'SIM-TEST)
)

(display "
First enable compiled in C code if desired.

(use-c)

Then choose the application via one of:

(load-opc)
(load-gtest)
(load-sim)
(load-stest)
")

(display "(load-sid)\n")

(display "\

Then load the .cpu file with:

(cload #:arch \"arch\" #:machs \"keep-mach\" #:isas \"keep-isa\" #:options \"options\")

keep-mach:
comma separated list of machs to keep or `all'

keep-isa:
comma separated list of isas to keep or `all'

opcode options:
[none yet]

gas test options:
[none yet]
\n")

(display "\
sim options:
with-scache
with-profile=fn

sim test options:
[none yet]
\n")


; If ~/.cgenrc exists, load it.

(let ((cgenrc (string-append (getenv 'HOME) "/.cgenrc")))
  (if (file-exists? cgenrc)
      (load cgenrc))
)
