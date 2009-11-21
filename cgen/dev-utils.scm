;; CGEN Debugging support.
;; Copyright (C) 2000, 2009 Red Hat, Inc.
;; This file is part of CGEN.
;; See file COPYING.CGEN for details.

;; This file contains a collection of utilities for use when
;; analyzing cpu files from Scheme.

(define srcdir ".")
(set! %load-path (cons srcdir %load-path))

(define (load-doc)
  (load "read")
  (load "desc")
  (load "desc-cpu")
  (load "html")
  ; ??? Necessary for the following case, dunno why.
  ; bash$ guile -l dev.scm
  ; guile> (load-doc)
  ; guile> (cload #:arch "./cpu/m32r.cpu")
  (set! APPLICATION 'DOC)
)

(define (load-opc)
  (load "read")
  (load "desc")
  (load "desc-cpu")
  (load "opcodes")
  (load "opc-asmdis")
  (load "opc-ibld")
  (load "opc-itab")
  (load "opc-opinst")
  (set! APPLICATION 'OPCODES)
)

(define (load-gtest)
  (load-opc)
  (load "gas-test")
  (set! APPLICATION 'GAS-TEST)
)

(define (load-sid)
  (load "read")
  (load "utils-sim")
  (load "sid")
  (load "sid-cpu")
  (load "sid-model")
  (load "sid-decode")
  (set! APPLICATION 'SID-SIMULATOR)
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
  (set! APPLICATION 'SIMULATOR)
)

(define (load-stest)
  (load-opc)
  (load "sim-test")
  (set! APPLICATION 'SIM-TEST)
)

(define (load-testsuite)
  (load "read")
  (load "desc")
  (load "desc-cpu")
  (load "testsuite.scm")
  (set! APPLICATION 'TESTSUITE)
)
