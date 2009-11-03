;; Various RTL transformations.
;;
;; Copyright (C) 2000, 2009 Red Hat, Inc.
;; This file is part of CGEN.
;; See file COPYING.CGEN for details.
;;
;; In particular:
;; rtx-simplify
;; rtx-solve
;; rtx-trim-for-doc

;; Utility to verify there are no DFLT modes present in EXPR

;; Subroutine of rtx-verify-no-dflt-modes to simplify it.
;; This is the EXPR-FN argument to rtl-traverse.

(define (/rtx-verify-no-dflt-modes-expr-fn rtx-obj expr parent-expr op-pos
					   tstate appstuff)
  (if (eq? (rtx-mode expr) 'DFLT)
      (tstate-error tstate "DFLT mode present" expr))

  ;; Leave EXPR unchanged and continue.
  #f
)

;; Entry point.  Verify there are no DFLT modes in EXPR.

(define (rtx-verify-no-dflt-modes context expr)
  (rtx-traverse context #f expr /rtx-verify-no-dflt-modes-expr-fn #f)
)

;; rtx-simplify (and supporting cast)

; Subroutine of /rtx-simplify-expr-fn to compare two values for equality.
; If both are constants and they're equal return #f/#t.
; INVERT? = #f -> return #t if equal, #t -> return #f if equal.
; Returns 'unknown if either argument is not a constant.

(define (/rtx-const-equal arg0 arg1 invert?)
  (if (and (rtx-constant? arg0)
	   (rtx-constant? arg1))
      (if invert?
	  (!= (rtx-constant-value arg0)
	      (rtx-constant-value arg1))
	  (= (rtx-constant-value arg0)
	     (rtx-constant-value arg1)))
      'unknown)
)

; Subroutine of /rtx-simplify-expr-fn to see if MAYBE-CONST is
; an element of NUMBER-LIST.
; NUMBER-LIST is a `number-list' rtx.
; INVERT? is #t if looking for non-membership.
; #f/#t is only returned for definitive answers.
; If INVERT? is #f:
; - return #f if MAYBE-CONST is not in NUMBER-LIST
; - return #t if MAYBE-CONST is in NUMBER-LIST and it has only one member
; - return 'member if MAYBE-CONST is in NUMBER-LIST and it has many members
; - otherwise return 'unknown
; If INVERT? is #t:
; - return #t if MAYBE-CONST is not in NUMBER-LIST
; - return #f if MAYBE-CONST is in NUMBER-LIST and it has only one member
; - return 'member if MAYBE-CONST is in NUMBER-LIST and it has many members
; - otherwise return 'unknown

(define (/rtx-const-list-equal maybe-const number-list invert?)
  (assert (rtx-kind? 'number-list number-list))
  (if (rtx-constant? maybe-const)
      (let ((values (rtx-number-list-values number-list)))
	(if invert?
	    (if (memq (rtx-constant-value maybe-const) values)
		(if (= (length values) 1)
		    #f
		    'member)
		#t)
	    (if (memq (rtx-constant-value maybe-const) values)
		(if (= (length values) 1)
		    #t
		    'member)
		#f)))
      'unknown)
)

; Subroutine of /rtx-simplify-expr-fn to simplify an eq-attr of (current-mach).
; CONTEXT is a <context> object or #f if there is none.

(define (/rtx-simplify-eq-attr-mach rtx context)
  (let ((attr (rtx-eq-attr-attr rtx))
	(value (rtx-eq-attr-value rtx)))
    ; If all currently selected machs will yield the same value
    ; for the attribute, we can simplify.
    (let ((values (map (lambda (m)
			 (obj-attr-value m attr))
		       (current-mach-list))))
      ; Ensure at least one mach is selected.
      (if (null? values)
	  (context-error context
			 "While simplifying rtl"
			 "no machs selected"
			 (rtx-strdump rtx)))
      ; All values equal to the first one?
      (if (all-true? (map (lambda (val)
			    (equal? val (car values)))
			  values))
	  (if (equal? value
		      ; Convert internal boolean attribute value
		      ; #f/#t to external value FALSE/TRUE.
		      ; FIXME:revisit.
		      (case (car values)
			((#f) 'FALSE)
			((#t) 'TRUE)
			(else (car values))))
	      (rtx-true)
	      (rtx-false))
	  ; couldn't simplify
	  rtx)))
)

; Subroutine of /rtx-simplify-expr-fn to simplify an eq-attr of (current-insn).

(define (/rtx-simplify-eq-attr-insn rtx insn context)
  (let ((attr (rtx-eq-attr-attr rtx))
	(value (rtx-eq-attr-value rtx)))
    (if (not (insn? insn))
	(context-error context
		       "While simplifying rtl"
		       "No current insn for `(current-insn)'"
		       (rtx-strdump rtx)))
    (let ((attr-value (obj-attr-value insn attr)))
      (if (eq? value attr-value)
	  (rtx-true)
	  (rtx-false))))
)

; Subroutine of rtx-simplify.
; This is the EXPR-FN argument to rtx-traverse.

(define (/rtx-simplify-expr-fn rtx-obj expr parent-expr op-pos
			       tstate appstuff)

  ;(display "Processing ") (display (rtx-dump expr)) (newline)

  (case (rtx-name expr)

    ((not)
     (let* ((arg (/rtx-traverse (rtx-alu-op-arg expr 0)
				'RTX expr 1 tstate appstuff))
	    (no-side-effects? (not (rtx-side-effects? arg))))
       (cond ((and no-side-effects? (rtx-false? arg))
	      (rtx-true))
	     ((and no-side-effects? (rtx-true? arg))
	      (rtx-false))
	     (else (rtx-make 'not (rtx-alu-op-mode expr) arg)))))

    ((orif)
     (let ((arg0 (/rtx-traverse (rtx-boolif-op-arg expr 0)
				'RTX expr 0 tstate appstuff))
	   (arg1 (/rtx-traverse (rtx-boolif-op-arg expr 1)
				'RTX expr 1 tstate appstuff)))
       (let ((no-side-effects-0? (not (rtx-side-effects? arg0)))
	     (no-side-effects-1? (not (rtx-side-effects? arg1))))
	 (cond ((and no-side-effects-0? (rtx-true? arg0))
		(rtx-true))
	       ((and no-side-effects-0? (rtx-false? arg0))
		(rtx-canonical-bool arg1))
	       ; Value of arg0 is unknown or has side-effects.
	       ((and no-side-effects-1? (rtx-true? arg1))
		(if no-side-effects-0?
		    (rtx-true)
		    (rtx-make 'orif arg0 (rtx-true))))
	       ((and no-side-effects-1? (rtx-false? arg1))
		arg0)
	       (else
		(rtx-make 'orif arg0 arg1))))))

    ((andif)
     (let ((arg0 (/rtx-traverse (rtx-boolif-op-arg expr 0)
				'RTX expr 0 tstate appstuff))
	   (arg1 (/rtx-traverse (rtx-boolif-op-arg expr 1)
				'RTX expr 1 tstate appstuff)))
       (let ((no-side-effects-0? (not (rtx-side-effects? arg0)))
	     (no-side-effects-1? (not (rtx-side-effects? arg1))))
	 (cond ((and no-side-effects-0? (rtx-false? arg0))
		(rtx-false))
	       ((and no-side-effects-0? (rtx-true? arg0))
		(rtx-canonical-bool arg1))
	       ; Value of arg0 is unknown or has side-effects.
	       ((and no-side-effects-1? (rtx-false? arg1))
		(if no-side-effects-0?
		    (rtx-false)
		    (rtx-make 'andif arg0 (rtx-false))))
	       ((and no-side-effects-1? (rtx-true? arg1))
		arg0)
	       (else
		(rtx-make 'andif arg0 arg1))))))

    ; Fold if's to their then or else part if we can determine the
    ; result of the test.
    ((if)
     (let ((test
	    ; ??? Was this but that calls rtx-traverse again which
	    ; resets the temp stack!
	    ; (rtx-simplify context (caddr expr))))
	    (/rtx-traverse (rtx-if-test expr) 'RTX expr 1 tstate appstuff)))
       (cond ((rtx-true? test)
	      (/rtx-traverse (rtx-if-then expr) 'RTX expr 2 tstate appstuff))
	     ((rtx-false? test)
	      (if (rtx-if-else expr)
		  (/rtx-traverse (rtx-if-else expr) 'RTX expr 3 tstate appstuff)
		  ; Sanity check, mode must be VOID.
		  ; FIXME: DFLT can no longer appear
		  (if (or (mode:eq? 'DFLT (rtx-mode expr))
			  (mode:eq? 'VOID (rtx-mode expr)))
		      (rtx-make 'nop 'VOID)
		      (error "rtx-simplify: non-void-mode `if' missing `else' part" expr))))
	     ; Can't simplify.
	     ; We could traverse the then/else clauses here, but it's simpler
	     ; to have our caller do it (by returning #f).
	     ; The cost is retraversing `test'.
	     (else #f))))

    ((eq ne)
     (let ((name (rtx-name expr))
	   (cmp-mode (rtx-cmp-op-mode expr))
	   (arg0 (/rtx-traverse (rtx-cmp-op-arg expr 0) 'RTX
				expr 1 tstate appstuff))
	   (arg1 (/rtx-traverse (rtx-cmp-op-arg expr 1) 'RTX
				expr 2 tstate appstuff)))
       (if (or (rtx-side-effects? arg0) (rtx-side-effects? arg1))
	   (rtx-make name cmp-mode arg0 arg1)
	   (case (/rtx-const-equal arg0 arg1 (rtx-kind? 'ne expr))
	     ((#f) (rtx-false))
	     ((#t) (rtx-true))
	     (else
	      ; That didn't work.  See if we have an ifield/operand with a
	      ; known range of values.  We don't need to check for a known
	      ; single value, that is handled below.
	      (case (rtx-name arg0)
		((ifield)
		 (let ((known-val (tstate-known-lookup tstate
						       (rtx-ifield-name arg0))))
		   (if (and known-val (rtx-kind? 'number-list known-val))
		       (case (/rtx-const-list-equal arg1 known-val
						    (rtx-kind? 'ne expr))
			 ((#f) (rtx-false))
			 ((#t) (rtx-true))
			 (else
			  (rtx-make name cmp-mode arg0 arg1)))
		       (rtx-make name cmp-mode arg0 arg1))))
		((operand)
		 (let ((known-val (tstate-known-lookup tstate
						       (rtx-operand-name arg0))))
		   (if (and known-val (rtx-kind? 'number-list known-val))
		       (case (/rtx-const-list-equal arg1 known-val
						    (rtx-kind? 'ne expr))
			 ((#f) (rtx-false))
			 ((#t) (rtx-true))
			 (else
			  (rtx-make name cmp-mode arg0 arg1)))
		       (rtx-make name cmp-mode arg0 arg1))))
		(else
		 (rtx-make name cmp-mode arg0 arg1))))))))

    ; Recognize attribute requests of current-insn, current-mach.
    ((eq-attr)
     (cond ((rtx-kind? 'current-mach (rtx-eq-attr-owner expr))
	    (/rtx-simplify-eq-attr-mach expr (tstate-context tstate)))
	   ((rtx-kind? 'current-insn (rtx-eq-attr-owner expr))
	    (/rtx-simplify-eq-attr-insn expr (tstate-owner tstate) (tstate-context tstate)))
	   (else expr)))

    ((ifield)
     (let ((known-val (tstate-known-lookup tstate (rtx-ifield-name expr))))
       ; If the value is a single number, return that.
       ; It can be one of several, represented as a number list.
       (if (and known-val (rtx-constant? known-val))
	   known-val ; (rtx-make 'const 'INT known-val)
	   #f)))

    ((operand)
     (let ((known-val (tstate-known-lookup tstate (rtx-operand-name expr))))
       ; If the value is a single number, return that.
       ; It can be one of several, represented as a number list.
       (if (and known-val (rtx-constant? known-val))
	   known-val ; (rtx-make 'const 'INT known-val)
	   #f)))

    ((closure)
     (let ((simplified-expr (/rtx-traverse (rtx-closure-expr expr)
					   'RTX expr 2 tstate appstuff)))
       simplified-expr))

    ; Leave EXPR unchanged and continue.
    (else #f))
)

; Simplify an rtl expression.
;
; EXPR must be in canonical source form.
; The result is a possibly simplified EXPR, still in source form.
;
; CONTEXT is a <context> object or #f, used for error messages.
; OWNER is the owner of the expression (e.g. <insn>) or #f if there is none.
;
; KNOWN is an alist of known values.  Each element is (name . value) where
; NAME is an ifield/operand name and VALUE is a const/number-list rtx.
; FIXME: Need ranges, later.
;
; The following operations are performed:
; - unselected machine dependent code is removed (eq-attr of (current-mach))
; - if's are reduced to either then/else if we can determine that the test is
;   a compile-time constant
; - orif/andif
; - eq/ne
; - not
;
; ??? Will become more intelligent as needed.

(define (rtx-simplify context owner expr known)
  (/rtx-traverse expr #f #f 0
		 (tstate-make context owner
			      /rtx-simplify-expr-fn
			      #f ;; ok since EXPR is fully canonical
			      (rtx-env-empty-stack)
			      #f known 0)
		 #f)
)

;; Return an insn's semantics simplified.
;; CONTEXT is a <context> object or #f, used for error messages.

(define (rtx-simplify-insn context insn)
  (rtx-simplify context insn (insn-canonical-semantics insn)
		(insn-build-known-values insn))
)

;; rtx-solve (and supporting cast)

; Utilities for equation solving.
; ??? At the moment this is only focused on ifield assertions.
; ??? That there exist more sophisticated versions than this one can take
; as a given.  This works for the task at hand and will evolve or be replaced
; as necessary.
; ??? This makes the simplifying assumption that no expr has side-effects.

; Subroutine of rtx-solve.
; This is the EXPR-FN argument to rtx-traverse.

(define (/solve-expr-fn rtx-obj expr parent-expr op-pos tstate appstuff)
  #f ; wip
)

; Return a boolean indicating if {expr} equates to "true".
; If the expression can't be reduced to #f/#t, return '?.
; ??? Use rtx-eval instead of rtx-traverse?
;
; EXPR must be in source form.
; CONTEXT is a <context> object, used for error messages.
; OWNER is the owner of the expression (e.g. <insn>) or #f if there is none.
; KNOWN is an alist of known values.  Each element is (name . value) where
; NAME is an ifield/operand name and VALUE is a const/number-list rtx.
; FIXME: Need ranges, later.
;
; This is akin to rtx-simplify except it's geared towards solving ifield
; assertions.  It's not unreasonable to combine them.  The worry is the
; efficiency lost.
; ??? Will become more intelligent as needed.

(define (rtx-solve context owner expr known)
  ; First simplify, then solve.
  (let* ((simplified-expr (rtx-simplify context owner expr known))
	 (maybe-solved-expr
	  simplified-expr) ; FIXME: for now
;	  (/rtx-traverse simplified-expr #f #f 0
;			 (tstate-make context owner
;				      /solve-expr-fn
;				      #f (rtx-env-empty-stack)
;				      #f known 0)
;			 #f))
	 )
    (cond ((rtx-true? maybe-solved-expr) #t)
	  ((rtx-false? maybe-solved-expr) #f)
	  (else '?)))
)

;; rtx-trim-for-doc (and supporting cast)
;; RTX trimming (removing fluff not normally needed for the human viewer).

;; Subroutine of /rtx-trim-args to simplify it.
;; Trim a list of rtxes.

(define (/rtx-trim-rtx-list rtx-list)
  (map /rtx-rtim-for-doc rtx-list)
)

; Subroutine of /rtx-trim-for-doc to simplify it.
; Trim all the arguments of rtx NAME.

(define (/rtx-trim-args name args)
  (let* ((rtx-obj (rtx-lookup name))
	 (arg-types (rtx-arg-types rtx-obj)))

    (let loop ((args args)
	       (types (cddr arg-types)) ; skip options, mode
	       (result nil))

      (if (null? args)

	  (reverse! result)

	  (let ((arg (car args))
		; Remember, types may be an improper list.
		(type (if (pair? types) (car types) types))
		(new-arg (car args)))

	    ;(display arg (current-error-port)) (newline (current-error-port))
	    ;(display type (current-error-port)) (newline (current-error-port))

	    (case type
	      ((OPTIONS)
	       (assert #f)) ; shouldn't get here

	      ((ANYINTMODE ANYFLOATMODE ANYNUMMODE ANYEXPRMODE EXPLNUMMODE
		VOIDORNUMMODE VOIDMODE BIMODE INTMODE
		SYMMODE INSNMODE MACHMODE)
	       #f) ; leave arg untouched

	      ((RTX SETRTX TESTRTX)
	       (set! new-arg (/rtx-trim-for-doc arg)))

	      ((CONDRTX)
	       (assert (= (length arg) 2))
	       (if (eq? (car arg) 'else)
		   (set! new-arg (cons 'else (/rtx-trim-for-doc (cadr arg))))
		   (set! new-arg (list (/rtx-trim-for-doc (car arg))
				       (/rtx-trim-for-doc (cadr arg)))))
	       )

	      ((CASERTX)
	       (assert (= (length arg) 2))
	       (set! new-arg (list (car arg) (/rtx-trim-for-doc (cadr arg))))
	       )

	      ((LOCALS)
	       #f) ; leave arg untouched

	      ((ITERATION SYMBOLLIST ENVSTACK)
	       #f) ; leave arg untouched for now

	      ((ATTRS)
	       #f) ; leave arg untouched for now

	      ((SYMBOL STRING NUMBER SYMORNUM)
	       #f) ; leave arg untouched

	      ((OBJECT)
	       (assert #f)) ; hopefully(wip!) shouldn't get here

	      (else
	       (assert #f))) ; unknown arg type

	    (loop (cdr args)
		  (if (pair? types) (cdr types) types)
		  (cons new-arg result))))))
)

; Given a canonical rtl expression, usually the result of rtx-simplify,
; remove bits unnecessary for documentation purposes.
; Canonical rtl too verbose for docs.
; Examples of things to remove:
; - empty options list
; - ifield/operand/local/const wrappers
;
; NOTE: While having to trim the result of rtx-simplify may seem ironic,
; it isn't.  You need to keep separate the notions of simplifying "1+1" to "2"
; and trimming the clutter from "(const () BI 0)" yielding "0".

(define (/rtx-trim-for-doc rtx)
  (if (pair? rtx) ; ??? cheap rtx?

      (let ((name (car rtx))
	    (options (cadr rtx))
	    (mode (caddr rtx))
	    (rest (cdddr rtx)))

	(case name

	  ((const ifield operand local)
	   (if (null? options)
	       (car rest)
	       rtx))

	  ((set)
	   (let ((trimmed-args (/rtx-trim-args name rest)))
	     (if (null? options)
		 (cons name trimmed-args)
		 (cons name (cons options (cons mode trimmed-args))))))

	  ((if)
	   (let ((trimmed-args (/rtx-trim-args name rest)))
	     (if (null? options)
		 (if (eq? mode 'VOID)
		     (cons name trimmed-args)
		     (cons name (cons mode trimmed-args)))
		 (cons name (cons options (cons mode trimmed-args))))))

	  ((sequence parallel)
	   ; No special support is needed, except it's nice to remove nop
	   ; statements.  These can be created when an `if' get simplified.
	   (let ((trimmed-args (/rtx-trim-args name rest))
		 (result nil))
	     (for-each (lambda (rtx)
			 (if (equal? rtx '(nop))
			     #f ; ignore
			     (set! result (cons rtx result))))
		       trimmed-args)
	     (if (null? options)
		 (if (eq? mode 'VOID)
		     (cons name (reverse result))
		     (cons name (cons mode (reverse result))))
		 (cons name (cons options (cons mode (reverse result)))))))

	  ((closure)
	   ;; Remove outer closures, they are artificially added, and are
	   ;; basically noise to the human trying to understand the semantics.
	   ;; ??? Since we currently can't distinguish outer closures,
	   ;; just remove them all.
	   (let ((trimmed-expr (/rtx-trim-for-doc (rtx-closure-expr rtx))))
	     (if (and (null? options) (null? (rtx-closure-env-stack rtx)))
		 trimmed-expr
		 (rtx-make 'closure options mode
			   (rtx-closure-isas rtx)
			   (rtx-closure-env-stack rtx)
			   trimmed-expr))))

	  (else
	   (let ((trimmed-args (/rtx-trim-args name rest)))
	     (if (null? options)
		 (if (eq? mode 'DFLT) ;; FIXME: DFLT can no longer appear
		     (cons name trimmed-args)
		     (cons name (cons mode trimmed-args)))
		 (cons name (cons options (cons mode trimmed-args))))))))

      ; Not an rtx expression, must be number, symbol, string.
      rtx)
)

(define (rtx-trim-for-doc rtx)
  (/rtx-trim-for-doc rtx)
)
