; Fix up the current interpreter-du-jour to conform to what we've
; been working with.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; check for newer guile

(if (symbol-bound? #f 'load-from-path)
    (begin
      (define (load file)
	(begin
	  ;(load-from-path file)
	  (primitive-load-path file)
	  ))
      )
)

; FIXME: to be deleted
(define =? =)
(define >=? >=)

(if (not (symbol-bound? #f '%stat))
    (begin
      (define %stat stat)
      )
)

(if (symbol-bound? #f 'debug-enable)
    (debug-enable 'backtrace)
)

; Guile 1.3 has reverse!, Guile 1.2 has list-reverse!.
; CGEN uses reverse!
(if (and (not (symbol-bound? #f 'reverse!))
	 (symbol-bound? #f 'list-reverse!))
    (define reverse! list-reverse!)
)
