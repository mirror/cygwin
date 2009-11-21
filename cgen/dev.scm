; CGEN Debugging support.
; Copyright (C) 2000, 2009 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; This file is loaded in during an interactive guile session to
; develop and debug CGEN.

; First load guile.scm to coerce guile into something we've been using.
; Guile is always in flux.
(load "guile.scm")

(load "dev-utils.scm")

; Also defined in read.scm, but we need it earlier.
(define APPLICATION 'UNKNOWN)

(define dev-verbose-level 2)

; Supply the path name and suffic for the .cpu file and delete the analyzer
; arg from cpu-load to lessen the typing.

(define (cload . args)
  (set! verbose-level dev-verbose-level)

  (let ((cpu-file #f)
	(keep-mach "all")
	(keep-isa "all")
	(options "")
	(trace-options "")
	(diagnostic-options ""))

    ; Doesn't check if (cadr args) exists or if #:arch was specified, but
    ; this is a debugging tool!
    (let loop ((args args))
      (if (null? args)
	  #f ; done
	  (begin
	    (case (car args)
	      ((#:arch) (set! cpu-file (cadr args)))
	      ((#:machs) (set! keep-mach (cadr args)))
	      ((#:isas) (set! keep-isa (cadr args)))
	      ((#:options) (set! options (cadr args)))
	      ((#:trace) (set! trace-options (cadr args)))
	      ((#:diag) (set! diagnostic-options (cadr args)))
	      (else (error "unknown option:" (car args))))
	    (loop (cddr args)))))

    (case APPLICATION
      ((UNKNOWN) (error "application not loaded"))
      ((DESC) (cpu-load cpu-file
			keep-mach keep-isa options
			trace-options diagnostic-options
			desc-init!
			desc-finish!
			desc-analyze!))
      ((DOC) (cpu-load cpu-file
			keep-mach keep-isa options
			trace-options diagnostic-options
			doc-init!
			doc-finish!
			doc-analyze!))
      ((OPCODES) (cpu-load cpu-file
			   keep-mach keep-isa options
			   trace-options diagnostic-options
			   opcodes-init!
			   opcodes-finish!
			   opcodes-analyze!))
      ((GAS-TEST) (cpu-load cpu-file
			    keep-mach keep-isa options
			    trace-options diagnostic-options
			    gas-test-init!
			    gas-test-finish!
			    gas-test-analyze!))
      ((SIMULATOR) (cpu-load cpu-file
			     keep-mach keep-isa options
			     trace-options diagnostic-options
			     sim-init!
			     sim-finish!
			     sim-analyze!))
      ((SID-SIMULATOR) (cpu-load cpu-file
			     keep-mach keep-isa options
			     trace-options diagnostic-options
			     sim-init!
			     sim-finish!
			     sim-analyze!))
      ((SIM-TEST) (cpu-load cpu-file
			    keep-mach keep-isa options
			    trace-options diagnostic-options
			    sim-test-init!
			    sim-test-finish!
			    sim-test-analyze!))
      ((TESTSUITE) (cpu-load cpu-file
			     keep-mach keep-isa options
			     trace-options diagnostic-options
			     testsuite-init!
			     testsuite-finish!
			     testsuite-analyze!))
      (else (error "unknown application:" APPLICATION))))
)

; Use the debugging evaluator.
(if (not (defined? 'DEBUG-EVAL))
    (define DEBUG-EVAL #t))

; Tell maybe-load to always load the file.
(if (not (defined? 'CHECK-LOADED?))
    (define CHECK-LOADED? #f))

(display "

First choose the application via one of:

(load-doc)
(load-opc)
(load-gtest)
(load-sim)
(load-stest)
(load-testsuite)
")

(display "(load-sid)\n")

(display "\

Then load the .cpu file with:

(cload #:arch \"path-to-cpu-file\" #:machs \"keep-mach\" #:isas \"keep-isa\"
       #:options \"options\" #:trace \"trace-options\" #:diag \"diagnostic-options\")

Only the #:arch parameter is mandatory, the rest are optional.

keep-mach:
comma separated list of machs to keep or `all'

keep-isa:
comma separated list of isas to keep or `all'

#:options specifies a list of application-specific options

doc options:
[none yet]

opcode options:
[none yet]
Remember to call (set-opc-file-path! \"/path/to/cpu.opc\").

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

(display "\
sid options:
[wip]
\n")

(display "\
trace-options: (comma-separated list of options)
commands - trace cgen command invocation
pmacros - trace pmacro expansion
all - trace everything
\n")

(display "\
diagnostic-options: (comma-separated list of options)
iformat - do more diagnostics on instruction formats
all - do all diagnostics
\n")

; If ~/.cgenrc exists, load it.

(let ((cgenrc (string-append (getenv "HOME") "/.cgenrc")))
  (if (file-exists? cgenrc)
      (load cgenrc))
)
