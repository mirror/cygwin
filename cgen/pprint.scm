;;;; pprint.scm --- pretty-printing objects for CGEN
;;;; Copyright (C) 2005 Red Hat, Inc.
;;;; This file is part of CGEN.
;;;; See file COPYING.CGEN for details.

;;; A list of elided objects, larger numbers first, and the number of
;;; the first element.
(define elide-table '())
(define elide-table-last -1)

;;; Add OBJ to the elided object list, and return its number.
(define (add-elided-object obj)
  (set! elide-table (cons obj elide-table))
  (set! elide-table-last (+ elide-table-last 1))
  elide-table-last)

;;; Referencing elided objects.
(define ($ n)
  (if (<= 0 n elide-table-last)
      (list-ref elide-table (- elide-table-last n))
      "no such object"))

;;; A default predicate for elision.
(define (elide? obj) #f)

;;; If (elide? OBJ) is true, return some sort of abbreviated list
;;; structure that might be helpful to the user in identifying the
;;; elided object.
;;; A default definition.
(define (elided-name obj) "")

;;; This is a pretty-printer that handles cyclic and shared structure.
(define (pprint original-obj)

  ;; Return true if OBJ should be elided in this call to pprint.
  ;; (We never elide the object we were passed itself.)
  (define (elide-this-call? obj)
    (and (not (eq? obj original-obj))
	 (elide? obj)))

  ;; First, traverse OBJ and build a hash table mapping objects
  ;; referenced more than once to #t, and everything else to #f.
  ;; (Only include entries for objects that might be interior nodes:
  ;; pairs and vectors.)
  (let ((shared
	 ;; Guile's stupid hash tables don't resize the table; the
	 ;; chains just get longer and longer.  So we need a big value here.
	 (let ((seen   (make-hash-table 65521))
	       (shared (make-hash-table 4093)))
	   (define (walk! obj)
	     (if (or (pair? obj) (vector? obj))
		 (if (hashq-ref seen obj)
		     (hashq-set! shared obj #t)
		     (begin
		       (hashq-set! seen obj #t)
		       (cond ((elide-this-call? obj))
			     ((pair? obj) (begin (walk! (car obj))
						 (walk! (cdr obj))))
			     ((vector? obj) (do ((i 0 (+ i 1)))
						 ((>= i (vector-length obj)))
					       (walk! (vector-ref obj i))))
			     (else (error "unhandled interior type")))))))
	   (walk! original-obj)
	   shared)))

    ;; A counter for shared structure labels.
    (define fresh-shared-label
      (let ((n 0))
	(lambda ()
	  (let ((l n))
	    (set! n (+ n 1))
	    l))))

    (define (print obj)
      (print-with-label obj (hashq-ref shared obj)))

    ;; Print an object OBJ, which SHARED maps to L.
    ;; L is always (hashq-ref shared obj), but we have that value handy
    ;; at times, so this entry point lets us avoid looking it up again.
    (define (print-with-label obj label)
      (if (number? label)
	  ;; If we've already visited this object, just print a
	  ;; reference to its label.
	  (map display `("#" ,label "#"))
	  (begin
	    ;; If it needs a label, attach one now.
	    (if (eqv? label #t) (let ((label (fresh-shared-label)))
				  (hashq-set! shared obj label)
				  (map display `("#" ,label "="))))
	    ;; Print the object.
	    (cond ((elide-this-call? obj)
		   (write (list '$ (add-elided-object obj) (elided-name obj))))
		  ((pair? obj) (begin (display "(")
				      (print-tail obj)))
		  ((vector? obj) (begin (display "#(")
					(do ((i 0 (+ i 1)))
					    ((>= i (vector-length obj)))
					  (print (vector-ref obj i))
					  (if (< (+ i 1) (vector-length obj))
					      (display " ")))
					(display ")")))
		  (else (write obj))))))

    ;; Print a pair P as if it were the tail of a list; assume the
    ;; opening paren and any previous elements have been printed.
    (define (print-tail obj)
      (print (car obj))
      (force-output)
      (let ((tail (cdr obj)))
	(if (null? tail)
	    (display ")")
	    ;; We use the dotted pair syntax if the cdr isn't a pair, but
	    ;; also if it needs to be labeled.
	    (let ((tail-label (hashq-ref shared tail)))
	      (if (or (not (pair? tail)) tail-label)
		  (begin (display " . ")
			 (print-with-label tail tail-label)
			 (display ")"))
		  (begin (display " ")
			 (print-tail tail)))))))

    (set! elide-table (make-hash-table 4093))
    (print original-obj)
    (newline)))

