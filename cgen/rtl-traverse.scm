;; RTL traversing support.
;; Copyright (C) 2000, 2001, 2009 Red Hat, Inc.
;; This file is part of CGEN.
;; See file COPYING.CGEN for details.

;; Canonicalization support.
;; Canonicalizing an rtl expression involves adding possibly missing options
;; and mode, and converting occurrences of DFLT into usable modes.
;; Various error checks are done as well.
;; This is done differently than traversal support because it has a more
;; specific purpose, it doesn't need to support arbitrary "expr-fns".
;; ??? At present the internal form is also the source form (easier debugging).

(define /rtx-canon-debug? #f)

;; Canonicalization state.
;; This carries the immutable elements only!
;; OUTER-EXPR is the EXPR argument to rtx-canonicalize.

(define (/make-cstate context isa-name-list outer-expr)
  (vector context isa-name-list outer-expr)
)

(define (/cstate-context cstate) (vector-ref cstate 0))
(define (/cstate-isas cstate) (vector-ref cstate 1))
(define (/cstate-outer-expr cstate) (vector-ref cstate 2))

;; Flag an error while canonicalizing rtl.

(define (/rtx-canon-error cstate errmsg expr parent-expr op-num)
  (let* ((pretty-parent-expr (rtx-pretty-strdump (/cstate-outer-expr cstate)))
	 (intro (if parent-expr
		    (string-append "While canonicalizing "
				   (rtx-strdump parent-expr)
				   (if op-num
				       (string-append ", operand #"
						      (number->string op-num))
				       "")
				   " of:\n"
				   pretty-parent-expr)
		    (string-append "While canonicalizing:\n" pretty-parent-expr))))
    (context-error (/cstate-context cstate) intro errmsg (rtx-dump expr)))
)

;; Lookup h/w object HW-NAME and return it (as a <hardware-base> object).
;; If multiple h/w objects with the same name are defined, require
;; all to have the same mode.
;; CHECK-KIND is a function of one argument to verify the h/w objects
;; are valid and if not flag an error.

(define (/rtx-lookup-hw cstate hw-name parent-expr check-kind)
  (let ((hw-objs (current-hw-sem-lookup hw-name)))

    (if (null? hw-objs)
	(/rtx-canon-error cstate "unknown h/w object"
			  hw-name parent-expr #f))

    ;; Just check the first one with CHECK-KIND.
    (check-kind (car hw-objs))

    (let* ((hw1 (car hw-objs))
	   (hw1-mode (hw-mode hw1))
	   (hw1-mode-name (obj:name hw1-mode)))

      ;; Allow multiple h/w objects with the same name
      ;; as long has they have the same mode.
      (if (> (length hw-objs) 1)
	  (let ((other-hw-mode-names (map (lambda (hw)
					    (obj:name (hw-mode hw)))
					  (cdr hw-objs))))
	    (if (not (all-true? (map (lambda (mode-name)
				       (eq? mode-name hw1-mode-name))
				     other-hw-mode-names)))
		(/rtx-canon-error cstate "multiple h/w objects with different modes selected"
				  hw-name parent-expr #f))))

      hw1))
)

;; Return the mode name to use in an expression given the requested mode
;; and the mode used in the expression.
;; If both are DFLT, leave it alone and hope the expression provides
;; enough info to pick a usable mode.
;; If both are provided, prefer the mode used in the expression.
;; If the modes are incompatible, return #f.

(define (/rtx-pick-mode cstate requested-mode-name expr-mode-name)
  (cond ((eq? requested-mode-name 'DFLT)
	 expr-mode-name)
	((eq? expr-mode-name 'DFLT)
	 requested-mode-name)
	(else
	 (let ((requested-mode (mode:lookup requested-mode-name))
	       (expr-mode (mode:lookup expr-mode-name)))
	   (if (not requested-mode)
	       (/rtx-canon-error cstate "invalid mode" requested-mode-name #f #f))
	   (if (not expr-mode)
	       (/rtx-canon-error cstate "invalid mode" expr-mode-name #f #f))
	   ;; FIXME: 'would prefer samesize or "no precision lost", sigh
	   (if (mode-compatible? 'sameclass requested-mode expr-mode)
	       expr-mode-name
	       expr-mode-name)))) ;; FIXME: should be #f, disabled pending completion of rtl mode handling rewrite
)

;; Return the mode name (as a symbol) to use in an object's rtl given
;; the requested mode, the mode used in the expression, and the object's
;; real mode.
;; If both requested mode and expr mode are DFLT, use the real mode.
;; If requested mode is DFLT, prefer expr mode.
;; If expr mode is DFLT, prefer the real mode.
;; If both requested mode and expr mode are specified, prefer expr-mode.
;; If there's an error the result is the error message (as a string).
;;
;; E.g. in (set SI dest (ifield DFLT f-r1)), the mode of the ifield's
;; expression is DFLT, the requested mode is SI, and the real mode of f-r1
;; may be INT.
;;
;; REAL-MODE is a <mode> object.

(define (/rtx-pick-mode3 requested-mode-name expr-mode-name real-mode)
  ;; Leave checking for (symbol? requested-mode-name) to caller (or higher).
  (let ((expr-mode (mode:lookup expr-mode-name)))
    (cond ((not expr-mode)
	   "unknown mode")
	  ((eq? requested-mode-name 'DFLT)
	   (if (eq? expr-mode-name 'DFLT)
	       (obj:name real-mode)
	       (if (rtx-mode-compatible? expr-mode real-mode)
		   expr-mode-name
		   (string-append "expression mode "
				  (symbol->string expr-mode-name)
				  " is incompatible with real mode "
				  (obj:str-name real-mode)))))
	  ((eq? expr-mode-name 'DFLT)
	   (if (rtx-mode-compatible? (mode:lookup requested-mode-name)
				     real-mode)
	       (obj:name real-mode)
	       (string-append "mode of containing expression "
			      (symbol->string requested-mode-name)
			      " is incompatible with real mode "
			      (obj:str-name real-mode))))
	  (else
	   (let ((requested-mode (mode:lookup requested-mode-name)))
	     (cond ((not (rtx-mode-compatible? requested-mode expr-mode))
		    (string-append "mode of containing expression "
				   (symbol->string requested-mode-name)
				   " is incompatible with expression mode "
				   (symbol->string expr-mode-name)))
		   ((not (rtx-mode-compatible? expr-mode real-mode))
		    (string-append "expression mode "
				   (symbol->string expr-mode-name)
				   " is incompatible with real mode "
				   (obj:str-name real-mode)))
		   (else
		    expr-mode-name))))))
)

;; Return the mode name (as a symbol) to use in an operand's rtl given
;; the requested mode, the mode used in the expression, and the operand's
;; real mode.
;; If both requested mode and expr mode are DFLT, use the real mode.
;; If requested mode is DFLT, prefer expr mode.
;; If expr mode is DFLT, prefer the real mode.
;; If both requested mode and expr mode are specified, prefer expr-mode.
;; If the modes are incompatible an error is signalled.
;;
;; E.g. in (set QI (mem QI src2) src1), the mode to set is QI, but if src1
;; is a 32-bit (SI) register we want QI.
;; OTOH, in (set QI (mem QI src2) uimm8), the mode to set is QI, but we want
;; the real mode of uimm8.
;;
;; ??? This is different from /rtx-pick-mode3 for compatibility with
;; pre-full-canonicalization versions.
;  It's currently a toss-up on whether it improves things.
;;
;; OP is an <operand> object.
;;
;; Things are complicated because multiple versions of a h/w object can be
;; defined, and the operand refers to the h/w by name.
;; op:type, which op:mode calls, will flag an error if multiple versions of
;; a h/w object are defined - only one should have been kept during .cpu
;; file loading.  This is for semantic code generation, but for generating
;; files covering the entire architecture we need to keep all the versions.
;; Things are ok, as far as canonicalization is concerned, if all h/w versions
;; have the same mode (which could be WI for 32/64 arches).

(define (/rtx-pick-op-mode cstate requested-mode-name expr-mode-name op
			   parent-expr)
  ;; Leave checking for (symbol? requested-mode-name) to caller (or higher).
  (let* ((op-mode-name (op:mode-name op))
	 (hw (/rtx-lookup-hw cstate (op:hw-name op) parent-expr
			     (lambda (hw) *UNSPECIFIED*)))
	 (op-mode (if (eq? op-mode-name 'DFLT)
		      (hw-mode hw)
		      (mode:lookup op-mode-name)))
	 (expr-mode (mode:lookup expr-mode-name)))
    (cond ((not expr-mode)
	   (/rtx-canon-error cstate "unknown mode" expr-mode-name
			     parent-expr #f))
	  ((eq? requested-mode-name 'DFLT)
	   (if (eq? expr-mode-name 'DFLT)
	       (obj:name op-mode)
	       (if (rtx-mode-compatible? expr-mode op-mode)
		   expr-mode-name
		   (/rtx-canon-error cstate
				     (string-append
				      "expression mode "
				      (symbol->string expr-mode-name)
				      " is incompatible with operand mode "
				      (obj:str-name op-mode))
				     expr-mode-name parent-expr #f))))
	  ((eq? expr-mode-name 'DFLT)
	   (if (rtx-mode-compatible? (mode:lookup requested-mode-name)
				     op-mode)
; FIXME: Experiment.  It's currently a toss-up on whether it improves things.
;	       (cond ((pc? op)
;		      (obj:name op-mode))
;		     ((register? hw)
;		      requested-mode-name)
;		     (else
;		      (obj:name op-mode)))
	       (obj:name op-mode)
	       (/rtx-canon-error cstate
				 (string-append
				  "mode of containing expression "
				  (symbol->string requested-mode-name)
				  " is incompatible with operand mode "
				  (obj:str-name op-mode))
				 requested-mode-name parent-expr #f)))
	  (else
	   (let ((requested-mode (mode:lookup requested-mode-name)))
	     (cond ((not (rtx-mode-compatible? requested-mode expr-mode))
		    (/rtx-canon-error cstate
				      (string-append
				       "mode of containing expression "
				       (symbol->string requested-mode-name)
				       " is incompatible with expression mode "
				       (symbol->string expr-mode-name))
				      requested-mode-name parent-expr #f))
		   ((not (rtx-mode-compatible? expr-mode op-mode))
		    (/rtx-canon-error cstate
				      (string-append
				       "expression mode "
				       (symbol->string expr-mode-name)
				       " is incompatible with operand mode "
				       (obj:str-name op-mode))
				      expr-mode-name parent-expr #f))
		   (else
		    expr-mode-name))))))
)

;; Return the last rtx in cond or case expression EXPR.

(define (/rtx-get-last-cond-case-rtx expr)
  (let ((len (length expr)))
    (list-ref expr (- len 1)))
)

;; Canonicalize a list of rtx's.
;; The mode of rtxes prior to the last one must be VOID.

(define (/rtx-canon-rtx-list rtx-list mode parent-expr op-num cstate env depth)
  (let* ((nr-rtxes (length rtx-list))
	 (last-op-num (- nr-rtxes 1)))
    (map (lambda (rtx op-num)
	   (/rtx-canon rtx 'RTX
		       (if (= op-num last-op-num) mode 'VOID)
		       parent-expr op-num cstate env depth))
	 rtx-list (iota nr-rtxes)))
)

;; Rtx canonicalizers.
;; These are defined as individual functions that are then built into a table
;; mostly for simplicity.
;
;; The result is either a pair of the parsed VAL and new environment,
;; or #f meaning there is no change (saves lots of unnecessarying cons'ing).

(define (/rtx-canon-options val mode parent-expr op-num cstate env depth)
  #f
)

(define (/rtx-canon-anyintmode val mode parent-expr op-num cstate env depth)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(INT UINT))
		 (eq? val 'DFLT)))
	#f
	(/rtx-canon-error cstate "expecting an integer mode"
			  val parent-expr op-num)))
)

(define (/rtx-canon-anyfloatmode val mode parent-expr op-num cstate env depth)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(FLOAT))
		 (eq? val 'DFLT)))
	#f
	(/rtx-canon-error cstate "expecting a float mode"
			  val parent-expr op-num)))
)

(define (/rtx-canon-anynummode val mode parent-expr op-num cstate env depth)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(INT UINT FLOAT))
		 (eq? val 'DFLT)))
	#f
	(/rtx-canon-error cstate "expecting a numeric mode"
			  val parent-expr op-num)))
)

(define (/rtx-canon-anyexprmode val mode parent-expr op-num cstate env depth)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(INT UINT FLOAT))
		 (memq val '(DFLT PTR VOID))))
	#f
	(/rtx-canon-error cstate "expecting a numeric mode, PTR, or VOID"
			  val parent-expr op-num)))
)

(define (/rtx-canon-explnummode val mode parent-expr op-num cstate env depth)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (memq (mode:class val-obj) '(INT UINT FLOAT)))
	#f
	(/rtx-canon-error cstate "expecting an explicit numeric mode"
			  val parent-expr op-num)))
)

(define (/rtx-canon-voidornummode val mode parent-expr op-num cstate env depth)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(INT UINT FLOAT))
		 (memq val '(DFLT VOID))))
	#f
	(/rtx-canon-error cstate "expecting void or a numeric mode"
			  val parent-expr op-num)))
)

(define (/rtx-canon-voidmode val mode parent-expr op-num cstate env depth)
  (if (memq val '(DFLT VOID))
      (cons 'VOID env)
      (/rtx-canon-error cstate "expecting VOID mode"
			val parent-expr op-num))
)

(define (/rtx-canon-bimode val mode parent-expr op-num cstate env depth)
  (if (memq val '(DFLT BI))
      (cons 'BI env)
      (/rtx-canon-error cstate "expecting BI mode"
			val parent-expr op-num))
)

(define (/rtx-canon-intmode val mode parent-expr op-num cstate env depth)
  (if (memq val '(DFLT INT))
      (cons 'INT env)
      (/rtx-canon-error cstate "expecting INT mode"
			val parent-expr op-num))
)

(define (/rtx-canon-symmode val mode parent-expr op-num cstate env depth)
  (if (memq val '(DFLT SYM))
      (cons 'SYM env)
      (/rtx-canon-error cstate "expecting SYM mode"
			val parent-expr op-num))
)

(define (/rtx-canon-insnmode val mode parent-expr op-num cstate env depth)
  (if (memq val '(DFLT INSN))
      (cons 'INSN env)
      (/rtx-canon-error cstate "expecting INSN mode"
			val parent-expr op-num))
)

(define (/rtx-canon-machmode val mode parent-expr op-num cstate env depth)
  (if (memq val '(DFLT MACH))
      (cons 'MACH env)
      (/rtx-canon-error cstate "expecting MACH mode"
			val parent-expr op-num))
)

(define (/rtx-canon-rtx val mode parent-expr op-num cstate env depth)
; Commented out 'cus it doesn't quite work yet.
; (if (not (rtx? val))
;     (/rtx-canon-error cstate "expecting an rtx" val parent-expr op-num))
  (cons (/rtx-canon val 'RTX mode parent-expr op-num cstate env depth)
	env)
)

(define (/rtx-canon-setrtx val mode parent-expr op-num cstate env depth)
; Commented out 'cus it doesn't quite work yet.
; (if (not (rtx? val))
;     (/rtx-canon-error cstate "expecting an rtx" val parent-expr op-num))
  (let ((dest (/rtx-canon val 'SETRTX mode parent-expr op-num cstate env depth)))
    (cons dest env))
)

;; This is the test of an `if'.

(define (/rtx-canon-testrtx val mode parent-expr op-num cstate env depth)
; Commented out 'cus it doesn't quite work yet.
; (if (not (rtx? val))
;     (/rtx-canon-error cstate "expecting an rtx"
;			  val parent-expr op-num))
  (cons (/rtx-canon val 'RTX mode parent-expr op-num cstate env depth)
	env)
)

(define (/rtx-canon-condrtx val mode parent-expr op-num cstate env depth)
  (if (not (pair? val))
      (/rtx-canon-error cstate "expecting an expression"
			  val parent-expr op-num))
  (if (eq? (car val) 'else)
      (begin
	(if (!= (+ op-num 2) (length parent-expr))
	    (/rtx-canon-error cstate "`else' clause not last"
			      val parent-expr op-num))
	(cons (cons 'else
		    (/rtx-canon-rtx-list
		     (cdr val) mode parent-expr op-num cstate env depth))
	      env))
      (cons (cons
	     ;; ??? Entries after the first are conditional.
	     (/rtx-canon (car val) 'RTX 'INT parent-expr op-num cstate env depth)
	     (/rtx-canon-rtx-list
	      (cdr val) mode parent-expr op-num cstate env depth))
	    env))
)

(define (/rtx-canon-casertx val mode parent-expr op-num cstate env depth)
  (if (or (not (list? val))
	  (< (length val) 2))
      (/rtx-canon-error cstate "invalid `case' expression"
			val parent-expr op-num))
  ;; car is either 'else or list of symbols/numbers
  (if (not (or (eq? (car val) 'else)
	       (and (list? (car val))
		    (not (null? (car val)))
		    (all-true? (map /rtx-symornum?
				    (car val))))))
      (/rtx-canon-error cstate "invalid `case' choice"
			val parent-expr op-num))
  (if (and (eq? (car val) 'else)
	   (!= (+ op-num 2) (length parent-expr)))
      (/rtx-canon-error cstate "`else' clause not last"
			val parent-expr op-num))
  (cons (cons (car val)
	      (/rtx-canon-rtx-list
	       (cdr val) mode parent-expr op-num cstate env depth))
	env)
)

(define (/rtx-canon-locals val mode parent-expr op-num cstate env depth)
  (if (not (list? val))
      (/rtx-canon-error cstate "bad locals list"
			val parent-expr op-num))
  (for-each (lambda (var)
	      (if (or (not (list? var))
		      (!= (length var) 2)
		      (not (/rtx-any-mode? (car var)))
		      (not (symbol? (cadr var))))
		  (/rtx-canon-error cstate "bad locals list"
				    val parent-expr op-num)))
	    val)
  (let ((new-env (rtx-env-make-locals val)))
    (cons val (cons new-env env)))
)

(define (/rtx-canon-iteration val mode parent-expr op-num cstate env depth)
  (if (not (symbol? val))
      (/rtx-canon-error cstate "bad iteration variable name"
			val parent-expr op-num))
  (let ((new-env (rtx-env-make-iteration-locals val)))
    (cons val (cons new-env env)))
)

(define (/rtx-canon-symbol-list val mode parent-expr op-num cstate env depth)
  (if (or (not (list? val))
	  (not (all-true? (map symbol? val))))
      (/rtx-canon-error cstate "bad symbol list"
			val parent-expr op-num))
  #f
)

(define (/rtx-canon-env-stack val mode parent-expr op-num cstate env depth)
  ;; VAL is an environment stack.
  (if (not (list? val))
      (/rtx-canon-error cstate "environment not a list"
			val parent-expr op-num))
  ;; FIXME: Shouldn't this push VAL onto ENV?
  (cons val env)
)

(define (/rtx-canon-attrs val mode parent-expr op-num cstate env depth)
;  (cons val ; (atlist-source-form (atlist-parse (make-prefix-cstate "with-attr") val ""))
;	env)
  #f
)

(define (/rtx-canon-symbol val mode parent-expr op-num cstate env depth)
  (if (not (symbol? val))
      (/rtx-canon-error cstate "expecting a symbol"
			val parent-expr op-num))
  #f
)

(define (/rtx-canon-string val mode parent-expr op-num cstate env depth)
  (if (not (string? val))
      (/rtx-canon-error cstate "expecting a string"
			val parent-expr op-num))
  #f
)

(define (/rtx-canon-number val mode parent-expr op-num cstate env depth)
  (if (not (number? val))
      (/rtx-canon-error cstate "expecting a number"
			val parent-expr op-num))
  #f
)

(define (/rtx-canon-symornum val mode parent-expr op-num cstate env depth)
  (if (not (or (symbol? val) (number? val)))
      (/rtx-canon-error cstate "expecting a symbol or number"
			val parent-expr op-num))
  #f
)

(define (/rtx-canon-object val mode parent-expr op-num cstate env depth)
  #f
)

;; Table of rtx canonicalizers.
;; This is a vector of size rtx-max-num.
;; Each entry is a list of (arg-type-name . canonicalizer) elements
;; for rtx-arg-types.
;; FIXME: Initialized in rtl.scm (i.e. outside this file).

(define /rtx-canoner-table #f)

;; Return a hash table of standard operand canonicalizers.
;; The result of each canonicalizer is a pair of the canonical form
;; of `val' and a possibly new environment or #f if there is no change.

(define (/rtx-make-canon-table)
  (let ((hash-tab (make-hash-table 31))
	(canoners
	 (list
	  (cons 'OPTIONS /rtx-canon-options)
	  (cons 'ANYINTMODE /rtx-canon-anyintmode)
	  (cons 'ANYFLOATMODE /rtx-canon-anyfloatmode)
	  (cons 'ANYNUMMODE /rtx-canon-anynummode)
	  (cons 'ANYEXPRMODE /rtx-canon-anyexprmode)
	  (cons 'EXPLNUMMODE /rtx-canon-explnummode)
	  (cons 'VOIDORNUMMODE /rtx-canon-voidornummode)
	  (cons 'VOIDMODE /rtx-canon-voidmode)
	  (cons 'BIMODE /rtx-canon-bimode)
	  (cons 'INTMODE /rtx-canon-intmode)
	  (cons 'SYMMODE /rtx-canon-symmode)
	  (cons 'INSNMODE /rtx-canon-insnmode)
	  (cons 'MACHMODE /rtx-canon-machmode)
	  (cons 'RTX /rtx-canon-rtx)
	  (cons 'SETRTX /rtx-canon-setrtx)
	  (cons 'TESTRTX /rtx-canon-testrtx)
	  (cons 'CONDRTX /rtx-canon-condrtx)
	  (cons 'CASERTX /rtx-canon-casertx)
	  (cons 'LOCALS /rtx-canon-locals)
	  (cons 'ITERATION /rtx-canon-iteration)
	  (cons 'SYMBOLLIST /rtx-canon-symbol-list)
	  (cons 'ENVSTACK /rtx-canon-env-stack)
	  (cons 'ATTRS /rtx-canon-attrs)
	  (cons 'SYMBOL /rtx-canon-symbol)
	  (cons 'STRING /rtx-canon-string)
	  (cons 'NUMBER /rtx-canon-number)
	  (cons 'SYMORNUM /rtx-canon-symornum)
	  (cons 'OBJECT /rtx-canon-object)
	  )))

    (for-each (lambda (canoner)
		(hashq-set! hash-tab (car canoner) (cdr canoner)))
	      canoners)

    hash-tab)
)

;; Standard expression operand canonicalizer.
;; Loop over the operands, verifying them according to the argument type
;; and mode matcher, and replace DFLT with a usable mode.

(define (/rtx-canon-operands rtx-obj requested-mode-name
			     func args parent-expr parent-op-num
			     cstate env depth)
  ;; ??? Might want to just leave operands as a list.
  (let* ((operands (list->vector args))
	 (nr-operands (vector-length operands))
	 (this-expr (cons func args)) ;; For error messages.
	 (expr-mode 
	  ;; For sets, the requested mode is DFLT or VOID (the mode of the
	  ;; result), but the mode we want is the mode of the set destination.
	  (if (rtx-result-mode rtx-obj)
	      (cadr args) ;; mode of arg2 doesn't come from containing expr
	      (/rtx-pick-mode cstate requested-mode-name (cadr args))))
	 (all-arg-types (vector-ref /rtx-canoner-table (rtx-num rtx-obj))))

    (if (not expr-mode)
	(/rtx-canon-error cstate
			  (string-append "requested mode "
					 (symbol->string requested-mode-name)
					 " is incompatible with expression mode "
					 (symbol->string (cadr args)))
			  this-expr parent-expr #f))

    (let loop ((env env)
	       (op-num 0)
	       (arg-types all-arg-types)
	       (arg-modes (rtx-arg-modes rtx-obj)))

      (let ((varargs? (and (pair? arg-types) (symbol? (car arg-types)))))

	(if /rtx-canon-debug?
	    (begin
	      (display (spaces (* 4 depth)))
	      (if (= op-num nr-operands)
		  (display "end of operands")
		  (begin
		    (display "op-num ") (display op-num) (display ": ")
		    (display (rtx-dump (vector-ref operands op-num)))
		    (display ", ")
		    (display (if varargs? (car arg-types) (caar arg-types)))
		    (display ", ")
		    (display (if varargs? arg-modes (car arg-modes)))
		    ))
	      (newline)
	      (force-output)))

	(cond ((= op-num nr-operands)

	       ;; Out of operands, check if we have the expected number.
	       (if (or (null? arg-types)
		       varargs?)

		   ;; We're theoretically done.
		   (let ((set-mode-from-arg!
			  (lambda (arg-num)
			    (if /rtx-canon-debug?
				(begin
				  (display (spaces (* 4 depth)))
				  (display "Computing expr mode from arguments.")
				  (newline)))
			    (let* ((expr-to-match 
				    (case func
				      ((cond case)
				       (/rtx-get-last-cond-case-rtx (vector-ref operands arg-num)))
				      (else
				       (vector-ref operands arg-num))))
				   (expr-to-match-obj (rtx-lookup (rtx-name expr-to-match)))
				   (result-mode (or (rtx-result-mode expr-to-match-obj)
						    (let ((expr-mode (rtx-mode expr-to-match)))
						      (if (eq? expr-mode 'DFLT)
							  (if (eq? requested-mode-name 'DFLT)
							      (/rtx-canon-error cstate
										"unable to determine mode of expression from arguments, please specify a mode"
										this-expr parent-expr #f)
							      requested-mode-name)
							  expr-mode)))))
			      (vector-set! operands 1 result-mode)))))
		     ;; The expression's mode might still be DFLT.
		     ;; If it is, fetch the mode of the MATCHEXPR operand,
		     ;; or MATCHSEQ operand, or containing expression.
		     ;; If it's still DFLT, flag an error.
		     (if (eq? (vector-ref operands 1) 'DFLT)
			 (cond ((rtx-matchexpr-index rtx-obj)
				=> (lambda (matchexpr-index)
				     (set-mode-from-arg! matchexpr-index)))
			       ((eq? func 'sequence)
				(set-mode-from-arg! (- nr-operands 1)))
			       (else
				(if /rtx-canon-debug?
				    (begin
				      (display (spaces (* 4 depth)))
				      (display "Computing expr mode from containing expression.")
				      (newline)))
				(if (or (eq? requested-mode-name 'DFLT)
					(rtx-result-mode rtx-obj))
				    (/rtx-canon-error cstate
						      "unable to determine mode of expression, please specify a mode"
						      this-expr parent-expr #f)
				    (vector-set! operands 1 requested-mode-name)))))
		     (vector->list operands))

		   (/rtx-canon-error cstate "missing operands"
				     this-expr parent-expr #f)))

	      ((null? arg-types)
	       (/rtx-canon-error cstate "too many operands"
				 this-expr parent-expr #f))

	      (else
	       (let ((type (if varargs? arg-types (car arg-types)))
		     (mode (let ((mode-spec (if varargs?
						arg-modes
						(car arg-modes))))
			     ;; We don't necessarily have enough information
			     ;; at this point.  Just propagate what we do know,
			     ;; and leave it for final processing to fix up what
			     ;; we missed.
			     ;; This is small enough that case is fast enough,
			     ;; and the number of entries should be stable.
			     (case mode-spec
			       ((ANY) 'DFLT)
			       ((ANYINT) 'DFLT) ;; FIXME
			       ((NA) #f)
			       ((MATCHEXPR) expr-mode)
			       ((MATCHSEQ)
				(if (= (+ op-num 1) nr-operands) ;; last one?
				    expr-mode
				    'VOID))
			       ((MATCH2)
				;; This is complicated by the fact that some
				;; rtx have a different result mode than what
				;; is specified in the rtl (e.g. set, eq).
				;; ??? Make these rtx specify both modes?
				(let* ((op2 (vector-ref operands 2))
				       (op2-obj (rtx-lookup (rtx-name op2))))
				  (or (rtx-result-mode op2-obj)
				      (rtx-mode op2))))
			       ((MATCH3)
				;; This is complicated by the fact that some
				;; rtx have a different result mode than what
				;; is specified in the rtl (e.g. set, eq).
				;; ??? Make these rtx specify both modes?
				(let* ((op2 (vector-ref operands 3))
				       (op2-obj (rtx-lookup (rtx-name op2))))
				  (or (rtx-result-mode op2-obj)
				      (rtx-mode op2))))
			       ;; Otherwise mode-spec is the mode to use.
			       (else mode-spec))))
		     (val (vector-ref operands op-num))
		     )

		 ;; Look up the canoner for this operand and perform it.
		 ;; FIXME: This would benefit from returning multiple values.
		 (let ((canoner (cdr type)))
		   (let ((canon-val (canoner val mode this-expr op-num
					     cstate env depth)))
		     (if canon-val
			 (begin
			   (set! val (car canon-val))
			   (set! env (cdr canon-val))))))

		 (vector-set! operands op-num val)

		 ;; Done with this operand, proceed to the next.
		 (loop env
		       (+ op-num 1)
		       (if varargs? arg-types (cdr arg-types))
		       (if varargs? arg-modes (cdr arg-modes)))))))))
)

(define (/rtx-canon-rtx-enum rtx-obj requested-mode-name
			     func args parent-expr parent-op-num
			     cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to enum, expecting 3"
			(cons func args) parent-expr #f))

  (let ((mode-name (cadr args))
	(enum-name (caddr args)))
    (let ((mode-obj (mode:lookup mode-name))
	  (enum-val-and-obj (enum-lookup-val enum-name)))

      (if (not enum-val-and-obj)
	  (/rtx-canon-error cstate "unknown enum value"
			    enum-name parent-expr #f))

      (let ((expr-mode-or-errmsg (/rtx-pick-mode3 requested-mode-name mode-name INT)))
	(if (symbol? expr-mode-or-errmsg)
	    (list (car args) expr-mode-or-errmsg enum-name)
	    (/rtx-canon-error cstate expr-mode-or-errmsg
			      enum-name parent-expr #f)))))
)

(define (/rtx-canon-rtx-ifield rtx-obj requested-mode-name
			       func args parent-expr parent-op-num
			       cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to ifield, expecting 3"
			(cons func args) parent-expr #f))

  (let ((expr-mode-name (cadr args))
	(ifld-name (caddr args)))
    (let ((ifld-obj (current-ifld-lookup ifld-name)))

      (if ifld-obj

	  (let ((mode-or-errmsg (/rtx-pick-mode3 requested-mode-name
						 expr-mode-name
						 (ifld-mode ifld-obj))))
	    (if (symbol? mode-or-errmsg)
		(list (car args) mode-or-errmsg ifld-name)
		(/rtx-canon-error cstate mode-or-errmsg expr-mode-name
				  parent-expr parent-op-num)))

	  (/rtx-canon-error cstate "unknown ifield"
			    ifld-name parent-expr #f))))
)

(define (/rtx-canon-rtx-operand rtx-obj requested-mode-name
				func args parent-expr parent-op-num
				cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to operand, expecting 3"
			(cons func args) parent-expr #f))

  (let ((expr-mode-name (cadr args))
	(op-name (caddr args)))
    (let ((op-obj (current-op-lookup op-name (/cstate-isas cstate))))

      (if op-obj

	  (let ((mode (/rtx-pick-op-mode cstate requested-mode-name
					 expr-mode-name op-obj parent-expr)))
	    (list (car args) mode op-name))

	  (/rtx-canon-error cstate "unknown operand"
			    op-name parent-expr #f))))
)

(define (/rtx-canon-rtx-xop rtx-obj requested-mode-name
			    func args parent-expr parent-op-num
			    cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to xop, expecting 3"
			(cons func args) parent-expr #f))

  (let ((expr-mode-name (cadr args))
	(xop-obj (caddr args)))

    (if (operand? xop-obj)

	(let ((mode-or-errmsg (/rtx-pick-mode3 requested-mode-name
					       expr-mode-name
					       (op:mode xop-obj))))
	  (if (symbol? mode-or-errmsg)
	      (list (car args) mode-or-errmsg xop-obj)
	      (/rtx-canon-error cstate mode-or-errmsg expr-mode-name
				parent-expr parent-op-num)))

	(/rtx-canon-error cstate "xop operand #2 not an operand"
			  (obj:name xop-obj) parent-expr #f)))
)

(define (/rtx-canon-rtx-local rtx-obj requested-mode-name
			      func args parent-expr parent-op-num
			      cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to local, expecting 3"
			(cons func args) parent-expr #f))

  (let ((expr-mode-name (cadr args))
	(local-name (caddr args)))
    (let ((local-obj (rtx-temp-lookup env local-name)))

      (if local-obj

	  (let ((mode-or-errmsg (/rtx-pick-mode3 requested-mode-name
						 expr-mode-name
						 (rtx-temp-mode local-obj))))
	    (if (symbol? mode-or-errmsg)
		(list (car args) mode-or-errmsg local-name)
		(/rtx-canon-error cstate mode-or-errmsg expr-mode-name
				  parent-expr parent-op-num)))

	  (/rtx-canon-error cstate "unknown local"
			    local-name parent-expr #f))))
)

(define (/rtx-canon-rtx-ref rtx-obj requested-mode-name
			    func args parent-expr parent-op-num
			    cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to ref, expecting 3"
			(cons func args) parent-expr #f))

  (let ((expr-mode-name (cadr args))
	(ref-name (caddr args)))
    ;; FIXME: Will current-op-lookup find named operands?
    (let ((op-obj (current-op-lookup ref-name (/cstate-isas cstate))))

      (if op-obj

	  ;; The result of "ref" is canonically an INT.
	  (let ((mode-or-errmsg (/rtx-pick-mode3 requested-mode-name
						 expr-mode-name
						 INT)))
	    (if (symbol? mode-or-errmsg)
		(list (car args) mode-or-errmsg ref-name)
		(/rtx-canon-error cstate mode-or-errmsg expr-mode-name
				  parent-expr parent-op-num)))

	  (/rtx-canon-error cstate "unknown operand"
			    ref-name parent-expr #f))))
)

(define (/rtx-canon-rtx-reg rtx-obj requested-mode-name
			    func args parent-expr parent-op-num
			    cstate env depth)
  (let ((len (length args)))
    (if (or (< len 3) (> len 5))
	(/rtx-canon-error cstate
			  ;; TODO: be more firm on expected number of args
			  (string-append
			   "wrong number of operands to "
			   (symbol->string func)
			   ", expecting 3 (or possibly 4,5)")
			  (cons func args) parent-expr #f))

    (let ((expr-mode-name (cadr args))
	  (hw-name (caddr args))
	  (this-expr (cons func args)))
      (let* ((hw (/rtx-lookup-hw cstate hw-name parent-expr
				 (lambda (hw)
				   (if (not (register? hw))
				       (/rtx-canon-error cstate "not a register" hw-name
							 parent-expr parent-op-num))
				   *UNSPECIFIED*)))
	     (hw-mode-obj (hw-mode hw)))

	(let ((mode-or-errmsg (/rtx-pick-mode3 requested-mode-name
					       expr-mode-name
					       hw-mode-obj)))

	  (if (symbol? mode-or-errmsg)

	      ;; Canonicalizing optional index/selector.
	      (let ((index (if (>= len 4)
			       (let ((canon (/rtx-canon-rtx
					     (list-ref args 3) 'INT
					     this-expr 3 cstate env depth)))
				 (car canon)) ;; discard env
			       #f))
		    (sel (if (= len 5)
			     (let ((canon (/rtx-canon-rtx
					   (list-ref args 4) 'INT
					   this-expr 4 cstate env depth)))
			       (car canon)) ;; discard env
			     #f)))
		(if sel
		    (begin
		      (assert index)
		      (list (car args) mode-or-errmsg hw-name index sel))
		    (if index
			(list (car args) mode-or-errmsg hw-name index)
			(list (car args) mode-or-errmsg hw-name))))

	      (/rtx-canon-error cstate mode-or-errmsg expr-mode-name
				parent-expr parent-op-num))))))
)

(define (/rtx-canon-rtx-mem rtx-obj requested-mode-name
			    func args parent-expr parent-op-num
			    cstate env depth)
  (let ((len (length args)))
    (if (or (< len 3) (> len 4))
	(/rtx-canon-error cstate
			  "wrong number of operands to mem, expecting 3 (or possibly 4)"
			  (cons func args) parent-expr #f))

    (let ((expr-mode-name (cadr args))
	  (addr-expr (caddr args))
	  (this-expr (cons func args)))

      ;; Call /rtx-canon-explnummode just for the error checking.
      (/rtx-canon-explnummode expr-mode-name #f this-expr 1 cstate env depth)

      (if (and (not (eq? requested-mode-name 'DFLT))
	       ;; FIXME: 'would prefer samesize or "no precision lost", sigh
	       (not (mode-compatible? 'sameclass
				      requested-mode-name expr-mode-name)))
	  (/rtx-canon-error cstate
			    (string-append "requested mode "
					   (symbol->string requested-mode-name)
					   " is incompatible with expression mode "
					   (symbol->string expr-mode-name))
			    this-expr parent-expr #f))

      (let ((addr (car ;; discard env
		   (/rtx-canon-rtx (list-ref args 2) 'AI
				   this-expr 2 cstate env depth)))
	    (sel (if (= len 4)
		     (let ((canon (/rtx-canon-rtx (list-ref args 3) 'INT
						  this-expr 3 cstate env depth)))
		       (car canon)) ;; discard env
		     #f)))
	(if sel
	    (list (car args) expr-mode-name addr sel)
	    (list (car args) expr-mode-name addr)))))
)

(define (/rtx-canon-rtx-const rtx-obj requested-mode-name
			      func args parent-expr parent-op-num
			      cstate env depth)
  (if (!= (length args) 3)
      (/rtx-canon-error cstate "wrong number of operands to const, expecting 3"
			(cons func args) parent-expr #f))

  ;; ??? floating point support is wip
  ;; NOTE: (integer? 1.0) == #t, but (inexact? 1.0) ==> #t too.

  (let ((expr-mode-name1 (if (and (eq? requested-mode-name 'DFLT)
				  (eq? (cadr args) 'DFLT))
			     'INT
			     (cadr args)))
	(value (caddr args))
	(this-expr (cons func args)))

    (let ((expr-mode-name (/rtx-pick-mode cstate requested-mode-name
					  expr-mode-name1)))

      (if (not expr-mode-name)
	  (/rtx-canon-error cstate
			    (string-append "requested mode "
					   (symbol->string requested-mode-name)
					   " is incompatible with expression mode "
					   (symbol->string expr-mode-name1))
			    this-expr parent-expr #f))

      (let ((expr-mode (mode:lookup expr-mode-name)))

	(cond ((integer? value)
	       (if (not (memq (mode:class expr-mode) '(INT UINT FLOAT)))
		   (/rtx-canon-error cstate "integer value incompatible with mode"
				     value this-expr 2)))
	      ((inexact? value)
	       (if (not (memq (mode:class expr-mode) '(FLOAT)))
		   (/rtx-canon-error cstate "floating point value incompatible with mode"
				     value this-expr 2)))
	      (else
	       (/rtx-canon-error cstate
				 (string-append "expecting a"
						(if (eq? (mode:class expr-mode) 'FLOAT)
						    " floating point"
						    "n integer")
						" constant")
				 value this-expr 2)))

	(list (car args) expr-mode-name value))))
)

;; Table of operand canonicalizers.
;; The main one is /rtx-traverse-operands, but a few rtx functions are simple
;; and special-purpose enough that it's simpler to have specific traversers.

(define /rtx-operand-canoners #f)

;; Return list of rtx functions that have special purpose canoners.

(define (/rtx-special-expr-canoners)
  (list
   (cons 'enum /rtx-canon-rtx-enum)
   (cons 'ifield /rtx-canon-rtx-ifield)
   (cons 'operand /rtx-canon-rtx-operand)
   ;;(cons 'name /rtx-canon-rtx-name) ;; ??? needed?
   (cons 'xop /rtx-canon-rtx-xop) ;; yes, it can appear
   (cons 'local /rtx-canon-rtx-local)
   (cons 'ref /rtx-canon-rtx-ref)
   ;;(cons 'index-of /rtx-canon-rtx-index-of) ;; ??? needed?
   (cons 'reg /rtx-canon-rtx-reg)
   (cons 'raw-reg /rtx-canon-rtx-reg)
   (cons 'mem /rtx-canon-rtx-mem)
   (cons 'const /rtx-canon-rtx-const)
   )
)

;; Subroutine of rtx-munge-mode&options.
;; Return boolean indicating if X is an rtx option.

(define (/rtx-option? x)
  (keyword? x)
)

;; Subroutine of rtx-munge-mode&options.
;; Return boolean indicating if X is an rtx option list.

(define (/rtx-option-list? x)
  (or (null? x)
      (and (pair? x)
	   (/rtx-option? (car x))))
)

;; Subroutine of /rtx-canon-expr to fill in the options and mode if absent.
;; The result is the canonical form of ARGS.
;;
;; "munge" is an awkward name to use here, but I like it for now because
;; it's easy to grep for.
;; An empty option list requires a mode to be present so that the empty
;; list in `(sequence () foo bar)' is unambiguously recognized as the locals
;; list.  Icky, sure, but less icky than the alternatives thus far.

(define (rtx-munge-mode&options rtx-obj requested-mode-name func args)
  (let ((orig-args args)
	(options #f)
	(mode-name #f)
	;; The mode in a `set' is the mode of the destination,
	;; whereas the mode of the result is VOID.
	;; The mode in a compare (e.g. `eq') is the mode of the operands,
	;; but the mode of the result is BI.
	(requested-mode-name (if (rtx-result-mode rtx-obj)
				 'DFLT ;; mode of args doesn't come from containing expr
				 'DFLT))) ;; FIXME: requested-mode-name)))

    ;; Pick off the option list if present.
    (if (and (pair? args)
	     (/rtx-option-list? (car args))
	     ;; Handle `(sequence () foo bar)'.  If empty list isn't followed
	     ;; by a mode, it is not an option list.
	     (or (not (null? (car args)))
		 (and (pair? (cdr args))
		      (mode-name? (cadr args)))))
	(begin
	  (set! options (car args))
	  (set! args (cdr args))))

    ;; Pick off the mode if present.
    (if (and (pair? args)
	     (mode-name? (car args)))
	(begin
	  (set! mode-name (car args))
	  (set! args (cdr args))))

    ;; Now put option list and mode back.
    ;; But don't do unnecessary consing.
    (if options
	(if (and mode-name (not (eq? mode-name 'DFLT)))
	    orig-args ;; can return ARGS unchanged
	    (cons options (cons requested-mode-name args)))
	(if (and mode-name (not (eq? mode-name 'DFLT)))
	    (cons nil orig-args) ;; just need to insert options
	    (cons nil (cons requested-mode-name args)))))
)

;; Subroutine of /rtx-canon to simplify it.

(define (/rtx-canon-expr rtx-obj requested-mode-name
			 func args parent-expr op-num cstate env depth)
  (let ((args2 (rtx-munge-mode&options rtx-obj requested-mode-name func args)))

    (if /rtx-canon-debug?
	(begin
	  (display (spaces (* 4 depth)))
	  (display "Traversing operands of: ")
	  (display (rtx-dump (cons func args)))
	  (newline)
	  (display (spaces (* 4 depth)))
	  (display "Requested mode: ")
	  (display requested-mode-name)
	  (newline)
	  (display (spaces (* 4 depth)))
	  (rtx-env-stack-dump env)
	  (force-output)))

    (let* ((canoner (vector-ref /rtx-operand-canoners (rtx-num rtx-obj)))
	   (operands (canoner rtx-obj requested-mode-name
			      func args2 parent-expr op-num
			      cstate env (+ depth 1))))
      (cons func operands)))
)

;; Convert rtl expression EXPR from source form to canonical form.
;; The expression is validated and rtx macros are expanded as well.
;; Plus DFLT mode is converted to a useful mode.
;; The result is EXPR in canonical form.
;;
;; CSTATE is a <cstate> object or #f if there is none.
;; It is used in error messages.

(define (/rtx-canon expr expected mode parent-expr op-num cstate env depth)
  (if /rtx-canon-debug?
      (begin
	(display (spaces (* 4 depth)))
	(display "Canonicalizing (")
	(display mode)
	(display "): ")
	(display (rtx-dump expr))
	(newline)
	(display (spaces (* 4 depth)))
	(rtx-env-stack-dump env)
	(force-output)
	))

  (let ((result
	 (if (pair? expr) ;; pair? -> cheap non-null-list?

	     (let ((rtx-name (car expr)))
	       (if (not (symbol? rtx-name))
		   (/rtx-canon-error cstate "invalid rtx function name"
				     expr parent-expr op-num))
	       (let ((rtx-obj (rtx-lookup rtx-name)))
		 (if rtx-obj
		     (/rtx-canon-expr rtx-obj mode rtx-name (cdr expr)
				      parent-expr op-num cstate env depth)
		     (let ((rtx-obj (/rtx-macro-lookup rtx-name)))
		       (if rtx-obj
			   (/rtx-canon (/rtx-macro-expand expr rtx-evaluator)
				       expected mode parent-expr op-num cstate env (+ depth 1))
			   (/rtx-canon-error cstate "unknown rtx function"
					     expr parent-expr op-num))))))

	     ;; EXPR is not a list.
	     ;; See if it's an operand shortcut.
	     (if (memq expected '(RTX SETRTX))

		 (cond ((symbol? expr)
			(cond ((current-op-lookup expr (/cstate-isas cstate))
			       => (lambda (op)
				    ;; NOTE: We can't simply call
				    ;; op:mode-name here, we need the real
				    ;; mode, not (potentially) DFLT.
				    ;; See /rtx-pick-op-mode.
				    (rtx-make-operand (/rtx-pick-op-mode cstate mode 'DFLT op parent-expr)
						      expr)))
			      ((rtx-temp-lookup env expr)
			       => (lambda (tmp)
				    (rtx-make-local (obj:name (rtx-temp-mode tmp)) expr)))
			      ((current-ifld-lookup expr)
			       => (lambda (f)
				    (rtx-make-ifield (obj:name (ifld-mode f)) expr)))
			      ((enum-lookup-val expr)
			       ;; ??? If enums could have modes other than INT,
			       ;; we'd want to propagate that mode here.
			       (rtx-make-enum 'INT expr))
			      (else
			       (/rtx-canon-error cstate "unknown operand"
						 expr parent-expr op-num))))
		       ((integer? expr)
			(rtx-make-const 'INT expr))
		       (else
			(/rtx-canon-error cstate "unexpected operand"
					  expr parent-expr op-num)))

		 ;; Not expecting RTX or SETRTX.
		 (/rtx-canon-error cstate "unexpected operand"
				   expr parent-expr op-num)))))

    (if /rtx-canon-debug?
	(begin
	  (display (spaces (* 4 depth)))
	  (display "Result: ")
	  (display (rtx-dump result))
	  (newline)
	  (force-output)
	  ))

    result)
)

;; Public entry point.
;; Convert rtl expression EXPR from source form to canonical form.
;; The expression is validated and rtx macros are expanded as well.
;; Plus operand shortcuts are expanded:
;;   - numbers -> (const number)
;;   - operand-name -> (operand operand-name)
;;   - ifield-name -> (ifield ifield-name)
;; Plus an absent option list is replaced with ().
;; Plus DFLT mode is converted to a useful mode.
;; Plus the specified isa-name-list is recorded in the RTL.
;;
;; The result is EXPR in canonical form.
;;
;; CONTEXT is a <context> object or #f if there is none.
;; It is used in error messages.
;;
;; ISA-NAME-LIST is a list of ISAs in which to evaluate the expression,
;; e.g. to do operand lookups.
;; The ISAs must be compatible, e.g. operand lookups must be unambiguous.
;;
;; MODE-NAME is the requested mode of the result, or DFLT.
;;
;; EXTRA-VARS-ALIST is an association list of extra (symbol <mode> value)
;; elements to be used during value lookup.
;; VALUE can be #f which means the value is assumed to be known, but is
;; currently unrepresentable.  This is used, for example, when representing
;; ifield setters: we don't know the new value, but it will be known when the
;; rtx is evaluated (??? Sigh, this is a bit of a cheat, closures have no
;; such thing, but it's useful here because we don't necessarily know what
;; the value will be in the application side of things).

(define (rtx-canonicalize context mode-name isa-name-list extra-vars-alist expr)
  (let ((result
	 (/rtx-canon expr 'RTX mode-name #f 0
		     (/make-cstate context isa-name-list expr)
		     (rtx-env-init-stack1 extra-vars-alist) 0)))
    (rtx-verify-no-dflt-modes context result)
    (rtx-make 'closure mode-name isa-name-list
	      (rtx-var-alist-to-closure-env-stack extra-vars-alist)
	      result))
)

;; RTL expression traversal support.
;; This is for analyzing the semantics in some way.
;; The rtl must already be in canonical form.

;; Set to #t to debug rtx traversal.

(define /rtx-traverse-debug? #f)

; Container to record the current state of traversal.
; This is initialized before traversal, and modified (in a copy) as the
; traversal state changes.
; This doesn't record all traversal state, just the more static elements.
; There's no point in recording things like the parent expression and operand
; position as they change for every sub-traversal.
; The main raison d'etre for this class is so we can add more state without
; having to modify all the traversal handlers.
; ??? At present it's not a proper "class" as there's no real need.
;
; CONTEXT is a <context> object or #f if there is none.
; It is used for error messages.
;
; EXPR-FN is a dual-purpose beast.  The first purpose is to just process
; the current expression and return the result.  The second purpose is to
; lookup the function which will then process the expression.
; It is applied recursively to the expression and each sub-expression.
; It must be defined as
; (lambda (rtx-obj expr parent-expr op-pos tstate appstuff) ...).
; If the result of EXPR-FN is a lambda, it is applied to
; (cons TSTATE EXPR), TSTATE is prepended to the arguments.
; For syntax expressions if the result of EXPR-FN is #f, the operands are
; processed using the builtin traverser.
; So to repeat: EXPR-FN can process the expression, and if its result is a
; lambda then it also processes the expression.  The arguments to EXPR-FN
; are (rtx-obj expr parent-expr op-pos tstate appstuff).  The format
; of the result of EXPR-FN are (cons TSTATE EXPR).
; The reason for the duality is that when trying to understand EXPR (e.g. when
; computing the insn format) EXPR-FN processes the expression itself, and
; when evaluating EXPR it's the result of EXPR-FN that computes the value.
;
; ISAS is a list of ISA name(s) in which to evaluate the expression.
;
; ENV is the current environment.  This is a stack of sequence locals.
;
; COND? is a boolean indicating if the current expression is on a conditional
; execution path.  This is for optimization purposes only and it is always ok
; to pass #t, except for the top-level caller which must pass #f (since the top
; level expression obviously isn't subject to any condition).
; It is used, for example, to speed up the simulator: there's no need to keep
; track of whether an operand has been assigned to (or potentially read from)
; if it's known it's always assigned to.
;
; OWNER is the owner of the expression or #f if there is none.
; Typically it is an <insn> object.
;
; KNOWN is an alist of known values.  This is used by rtx-simplify.
; Each element is (name . value) where
; NAME is a scalar ifield name (in the future it might be an operand name or
; sequence local name), and
; VALUE is a const rtx, (const () mode value),
; or a number-list rtx, (number-list () mode value1 [value2 ...]).
; A "scalar ifield" is a simple ifield (not a multi or derived ifield),
; or a multi-ifield consisting of only simple ifields.
;
; DEPTH is the current traversal depth.

(define (tstate-make context owner expr-fn isas env cond? known depth)
  (vector context owner expr-fn isas env cond? known depth)
)

(define (tstate-context state)               (vector-ref state 0))
(define (tstate-set-context! state newval)   (vector-set! state 0 newval))
(define (tstate-owner state)                 (vector-ref state 1))
(define (tstate-set-owner! state newval)     (vector-set! state 1 newval))
(define (tstate-expr-fn state)               (vector-ref state 2))
(define (tstate-set-expr-fn! state newval)   (vector-set! state 2 newval))
(define (tstate-isas state)                  (vector-ref state 3))
(define (tstate-set-isas! state newval)      (vector-set! state 3 newval))
(define (tstate-env-stack state)             (vector-ref state 4))
(define (tstate-set-env-stack! state newval) (vector-set! state 4 newval))
(define (tstate-cond? state)                 (vector-ref state 5))
(define (tstate-set-cond?! state newval)     (vector-set! state 5 newval))
(define (tstate-known state)                 (vector-ref state 6))
(define (tstate-set-known! state newval)     (vector-set! state 6 newval))
(define (tstate-depth state)                 (vector-ref state 7))
(define (tstate-set-depth! state newval)     (vector-set! state 7 newval))

; Create a copy of STATE.

(define (tstate-copy state)
  ; A fast vector-copy would be nice, but this is simple and portable.
  (list->vector (vector->list state))
)

;; Create a copy of STATE with environment stack ENV-STACK added,
;; and the ISA(s) set to ISA-NAME-LIST.

(define (tstate-make-closure state isa-name-list env-stack)
  (let ((result (tstate-copy state)))
    (tstate-set-isas! result isa-name-list)
    (tstate-set-env-stack! result (append env-stack (tstate-env-stack result)))
    result)
)

; Create a copy of STATE with environment ENV pushed onto the existing
; environment list.
; There's no routine to pop the environment list as there's no current
; need for it: we make a copy of the state when we push.

(define (tstate-push-env state env)
  (let ((result (tstate-copy state)))
    (tstate-set-env-stack! result (cons env (tstate-env-stack result)))
    result)
)

; Create a copy of STATE with a new COND? value.

(define (tstate-new-cond? state cond?)
  (let ((result (tstate-copy state)))
    (tstate-set-cond?! result cond?)
    result)
)

; Lookup NAME in the known value table.
; Returns the value or #f if not found.
; The value is either a const rtx or a number-list rtx.

(define (tstate-known-lookup tstate name)
  (let ((known (tstate-known tstate)))
    (assq-ref known name))
)

; Increment the recorded traversal depth of TSTATE.

(define (tstate-incr-depth! tstate)
  (tstate-set-depth! tstate (1+ (tstate-depth tstate)))
)

; Decrement the recorded traversal depth of TSTATE.

(define (tstate-decr-depth! tstate)
  (tstate-set-depth! tstate (1- (tstate-depth tstate)))
)

; Issue an error given a tstate.

(define (tstate-error tstate errmsg . expr)
  (apply context-owner-error
	 (cons (tstate-context tstate)
	       (cons (tstate-owner tstate)
		     (cons "During rtx traversal"
			   (cons errmsg expr)))))
)

; Traversal support.

; Return a boolean indicating if X is a mode.

(define (/rtx-any-mode? x)
  (->bool (mode:lookup x))
)

; Return a boolean indicating if X is a symbol or rtx.

(define (/rtx-symornum? x)
  (or (symbol? x) (number? x))
)

; Traverse a list of rtx's.

(define (/rtx-traverse-rtx-list rtx-list expr op-num tstate appstuff)
  (map (lambda (rtx)
	 ; ??? Shouldn't OP-NUM change for each element?
	 (/rtx-traverse rtx 'RTX expr op-num tstate appstuff))
       rtx-list)
)

; Cover-fn to tstate-error for signalling an error during rtx traversal
; of operand OP-NUM.
; RTL-EXPR must be an rtl expression.

(define (/rtx-traverse-error tstate errmsg rtl-expr op-num)
  (tstate-error tstate
		(string-append errmsg ", operand #" (number->string op-num))
		(rtx-dump rtl-expr))
)

; Rtx traversers.
;
; The result is either a pair of the parsed VAL and new TSTATE,
; or #f meaning there is no change (saves lots of unnecessarying cons'ing).

(define (/rtx-traverse-normal-operand val expr op-num tstate appstuff)
  #f
)

(define (/rtx-traverse-rtx val expr op-num tstate appstuff)
  (cons (/rtx-traverse val 'RTX expr op-num tstate appstuff)
	tstate)
)

(define (/rtx-traverse-setrtx val expr op-num tstate appstuff)
  (cons (/rtx-traverse val 'SETRTX expr op-num tstate appstuff)
	tstate)
)

; This is the test of an `if'.

(define (/rtx-traverse-testrtx val expr op-num tstate appstuff)
  (cons (/rtx-traverse val 'RTX expr op-num tstate appstuff)
	(tstate-new-cond?
	 tstate
	 (not (rtx-compile-time-constant? val))))
)

(define (/rtx-traverse-condrtx val expr op-num tstate appstuff)
  (if (eq? (car val) 'else)
      (cons (cons 'else
		  (/rtx-traverse-rtx-list
		   (cdr val) expr op-num
		   (tstate-new-cond? tstate #t)
		   appstuff))
	    (tstate-new-cond? tstate #t))
      (cons (cons
	     ; ??? Entries after the first are conditional.
	     (/rtx-traverse (car val) 'RTX expr op-num tstate appstuff)
	     (/rtx-traverse-rtx-list
	      (cdr val) expr op-num
	      (tstate-new-cond? tstate #t)
	      appstuff))
	    (tstate-new-cond? tstate #t)))
)

(define (/rtx-traverse-casertx val expr op-num tstate appstuff)
  (cons (cons (car val)
	      (/rtx-traverse-rtx-list
	       (cdr val) expr op-num
	       (tstate-new-cond? tstate #t)
	       appstuff))
	(tstate-new-cond? tstate #t))
)

(define (/rtx-traverse-locals val expr op-num tstate appstuff)
  (let ((env (rtx-env-make-locals val)))
    (cons val (tstate-push-env tstate env)))
)

(define (/rtx-traverse-iteration val expr op-num tstate appstuff)
  (let ((env (rtx-env-make-iteration-locals val)))
    (cons val (tstate-push-env tstate env)))
)

(define (/rtx-traverse-attrs val expr op-num tstate appstuff)
;  (cons val ; (atlist-source-form (atlist-parse (make-prefix-context "with-attr") val ""))
;	tstate)
  #f
)

; Table of rtx traversers.
; This is a vector of size rtx-max-num.
; Each entry is a list of (arg-type-name . traverser) elements
; for rtx-arg-types.
; FIXME: Initialized in rtl.scm (i.e. outside this file).

(define /rtx-traverser-table #f)

; Return a hash table of standard operand traversers.
; The result of each traverser is a pair of the compiled form of `val' and
; a possibly new traversal state or #f if there is no change.

(define (/rtx-make-traverser-table)
  (let ((hash-tab (make-hash-table 31))
	(traversers
	 (list
	  (cons 'OPTIONS /rtx-traverse-normal-operand)
	  (cons 'ANYINTMODE /rtx-traverse-normal-operand)
	  (cons 'ANYFLOATMODE /rtx-traverse-normal-operand)
	  (cons 'ANYNUMMODE /rtx-traverse-normal-operand)
	  (cons 'ANYEXPRMODE /rtx-traverse-normal-operand)
	  (cons 'EXPLNUMMODE /rtx-traverse-normal-operand)
	  (cons 'VOIDORNUMMODE /rtx-traverse-normal-operand)
	  (cons 'VOIDMODE /rtx-traverse-normal-operand)
	  (cons 'BIMODE /rtx-traverse-normal-operand)
	  (cons 'INTMODE /rtx-traverse-normal-operand)
	  (cons 'SYMMODE /rtx-traverse-normal-operand)
	  (cons 'INSNMODE /rtx-traverse-normal-operand)
	  (cons 'MACHMODE /rtx-traverse-normal-operand)
	  (cons 'RTX /rtx-traverse-rtx)
	  (cons 'SETRTX /rtx-traverse-setrtx)
	  (cons 'TESTRTX /rtx-traverse-testrtx)
	  (cons 'CONDRTX /rtx-traverse-condrtx)
	  (cons 'CASERTX /rtx-traverse-casertx)
	  (cons 'LOCALS /rtx-traverse-locals)
	  (cons 'ITERATION /rtx-traverse-iteration)
	  ;; NOTE: Closure isas and env are handled in /rtx-traverse.
	  (cons 'SYMBOLLIST /rtx-traverse-normal-operand)
	  (cons 'ENVSTACK /rtx-traverse-normal-operand)
	  (cons 'ATTRS /rtx-traverse-attrs)
	  (cons 'SYMBOL /rtx-traverse-normal-operand)
	  (cons 'STRING /rtx-traverse-normal-operand)
	  (cons 'NUMBER /rtx-traverse-normal-operand)
	  (cons 'SYMORNUM /rtx-traverse-normal-operand)
	  (cons 'OBJECT /rtx-traverse-normal-operand)
	  )))

    (for-each (lambda (traverser)
		(hashq-set! hash-tab (car traverser) (cdr traverser)))
	      traversers)

    hash-tab)
)

; Traverse the operands of EXPR, a canonicalized RTL expression.
; Here "canonicalized" means that EXPR has been run through rtx-canonicalize.
; Note that this means that, yes, the options and mode are "traversed" too.

(define (/rtx-traverse-operands rtx-obj expr tstate appstuff)
  (if /rtx-traverse-debug?
      (begin
	(display (spaces (* 4 (tstate-depth tstate))))
	(display "Traversing operands of: ")
	(display (rtx-dump expr))
	(newline)
	(rtx-env-stack-dump (tstate-env-stack tstate))
	(force-output)))

  (let loop ((operands (cdr expr))
	     (op-num 0)
	     (arg-types (vector-ref /rtx-traverser-table (rtx-num rtx-obj)))
	     (arg-modes (rtx-arg-modes rtx-obj))
	     (result nil))

    (let ((varargs? (and (pair? arg-types) (symbol? (car arg-types)))))

      (if /rtx-traverse-debug?
	  (begin
	    (display (spaces (* 4 (tstate-depth tstate))))
	    (if (null? operands)
		(display "end of operands")
		(begin
		  (display "op-num ") (display op-num) (display ": ")
		  (display (rtx-dump (car operands)))
		  (display ", ")
		  (display (if varargs? (car arg-types) (caar arg-types)))
		  (display ", ")
		  (display (if varargs? arg-modes (car arg-modes)))
		  ))
	    (newline)
	    (force-output)))

      (cond ((null? operands)
	     ;; Out of operands, check if we have the expected number.
	     (if (or (null? arg-types)
		     varargs?)
		 (reverse! result)
		 (tstate-error tstate "missing operands" (rtx-dump expr))))

	    ((null? arg-types)
	     (tstate-error tstate "too many operands" (rtx-dump expr)))

	    (else
	     (let* ((val (car operands))
		    (type (if varargs? arg-types (car arg-types))))

	       ;; Look up the traverser for this kind of operand and perform it.
	       ;; FIXME: This would benefit from returning multiple values.
	       (let ((traverser (cdr type)))
		 (let ((traversed-val (traverser val expr op-num tstate appstuff)))
		   (if traversed-val
		       (begin
			 (set! val (car traversed-val))
			 (set! tstate (cdr traversed-val))))))

	       ;; Done with this operand, proceed to the next.
	       (loop (cdr operands)
		     (+ op-num 1)
		     (if varargs? arg-types (cdr arg-types))
		     (if varargs? arg-modes (cdr arg-modes))
		     (cons val result)))))))
)

; Publically accessible version of /rtx-traverse-operands as EXPR-FN may
; need to call it.

(define rtx-traverse-operands /rtx-traverse-operands)

; Subroutine of /rtx-traverse to traverse an expression.
;
; RTX-OBJ is the <rtx-func> object of the (outer) expression being traversed.
;
; EXPR is the expression to be traversed.
; It must be fully canonical.
;
; PARENT-EXPR is the expression EXPR is contained in.  The top-level
; caller must pass #f for it.
;
; OP-POS is the position EXPR appears in PARENT-EXPR.  The
; top-level caller must pass 0 for it.
;
; TSTATE is the current traversal state.
;
; APPSTUFF is for application specific use.
;
; For syntax expressions arguments are not pre-evaluated before calling the
; user's expression handler.  Otherwise they are.
;
; If (tstate-expr-fn TSTATE) wants to just scan the operands, rather than
; evaluating them, one thing it can do is call back to rtx-traverse-operands.
; If (tstate-expr-fn TSTATE) returns #f, traverse the operands normally and
; return (rtx's-name ([options]) mode traversed-operand1 ...),
; i.e., the canonicalized form.
; This is for semantic-compile's sake and all traversal handlers are
; required to do this if the expr-fn returns #f.

(define (/rtx-traverse-expr rtx-obj expr parent-expr op-pos tstate appstuff)
  (let ((fn ((tstate-expr-fn tstate)
	     rtx-obj expr parent-expr op-pos tstate appstuff)))
    (if fn
	(if (procedure? fn)
	    ; Don't traverse operands for syntax expressions.
	    (if (eq? (rtx-style rtx-obj) 'SYNTAX)
		(apply fn (cons tstate cdr expr))
		(let ((operands (/rtx-traverse-operands rtx-obj expr tstate appstuff)))
		  (apply fn (cons tstate operands))))
	    fn)
	(let ((operands (/rtx-traverse-operands rtx-obj expr tstate appstuff)))
	  (cons (car expr) operands))))
)

; Main entry point for expression traversal.
; (Actually rtx-traverse is, but it's just a cover function for this.)
;
; The result is the result of the lambda (tstate-expr-fn TSTATE) looks up
; in the case of expressions, or an operand object (usually <operand>)
; in the case of operands.
;
; EXPR is the expression to be traversed.
; It must be fully canonical.
;
; EXPECTED is one of `-rtx-valid-types' and indicates the expected rtx type
; or #f if it doesn't matter.
;
; PARENT-EXPR is the expression EXPR is contained in.  The top-level
; caller must pass #f for it.
;
; OP-POS is the position EXPR appears in PARENT-EXPR.  The
; top-level caller must pass 0 for it.
;
; TSTATE is the current traversal state.
;
; APPSTUFF is for application specific use.

(define (/rtx-traverse expr expected parent-expr op-pos tstate appstuff)
  (if /rtx-traverse-debug?
      (begin
	(display (spaces (* 4 (tstate-depth tstate))))
	(display "Traversing expr: ")
	(display expr)
	(newline)
	(display (spaces (* 4 (tstate-depth tstate))))
	(display "-expected:       ")
	(display expected)
	(newline)
	(display (spaces (* 4 (tstate-depth tstate))))
	(display "-conditional:    ")
	(display (tstate-cond? tstate))
	(newline)
	(force-output)
	))

  ;; FIXME: error checking here should be deleteable.

  (if (pair? expr) ; pair? -> cheap non-null-list?

      (let* ((rtx-name (car expr))
	     (rtx-obj (rtx-lookup rtx-name))
	     ;; If this is a closure, update tstate.
	     ;; ??? This is a bit of a wart.  All other rtxes handle their
	     ;; special args/needs via rtx-arg-types.  Left as is to simmer.
	     (tstate (if (eq? rtx-name 'closure)
			 (tstate-make-closure tstate
					      (rtx-closure-isas expr)
					      (rtx-make-env-stack (rtx-closure-env-stack expr)))
			 tstate)))
	(tstate-incr-depth! tstate)
	(let ((result
	       (if rtx-obj
		   (/rtx-traverse-expr rtx-obj expr parent-expr op-pos tstate appstuff)
		   (let ((rtx-obj (/rtx-macro-lookup rtx-name)))
		     (if rtx-obj
			 (/rtx-traverse (/rtx-macro-expand expr rtx-evaluator)
					expected parent-expr op-pos tstate appstuff)
			 (tstate-error tstate "unknown rtx function" expr))))))
	  (tstate-decr-depth! tstate)
	  result))

      ; EXPR is not a list.
      ; See if it's an operand shortcut.
      ; FIXME: Can we get here any more? [now that EXPR is already canonical]
      (if (memq expected '(RTX SETRTX))

	  (cond ((symbol? expr)
		 (cond ((current-op-lookup expr (tstate-isas tstate))
			=> (lambda (op)
			     (/rtx-traverse
			      ;; NOTE: Can't call op:mode-name here, we need
			      ;; the real mode, not (potentially) DFLT.
			      (rtx-make-operand (obj:name (op:mode op)) expr)
			      expected parent-expr op-pos tstate appstuff)))
		       ((rtx-temp-lookup (tstate-env-stack tstate) expr)
			=> (lambda (tmp)
			     (/rtx-traverse
			      (rtx-make-local (rtx-temp-mode tmp) expr)
			      expected parent-expr op-pos tstate appstuff)))
		       ((current-ifld-lookup expr)
			=> (lambda (f)
			     (/rtx-traverse
			      (rtx-make-ifield (obj:name (ifld-mode f)) expr)
			      expected parent-expr op-pos tstate appstuff)))
		       ((enum-lookup-val expr)
			;; ??? If enums could have modes other than INT,
			;; we'd want to propagate that mode here.
			(/rtx-traverse
			 (rtx-make-enum 'INT expr)
			 expected parent-expr op-pos tstate appstuff))
		       (else
			(tstate-error tstate "unknown operand" expr))))
		((integer? expr)
		 (/rtx-traverse (rtx-make-const 'INT expr)
				expected parent-expr op-pos tstate appstuff))
		(else
		 (tstate-error tstate "unexpected operand" expr)))

	  ; Not expecting RTX or SETRTX.
	  (tstate-error tstate "unexpected operand" expr)))
)

; User visible procedures to traverse an rtl expression.
; EXPR must be fully canonical.
; These calls /rtx-traverse to do most of the work.
; See tstate-make for explanations of OWNER, EXPR-FN.
; CONTEXT is a <context> object or #f if there is none.
; LOCALS is a list of (mode . name) elements (the locals arg to `sequence').
; APPSTUFF is for application specific use.

(define (rtx-traverse context owner expr expr-fn appstuff)
  (/rtx-traverse expr #f #f 0
		 (tstate-make context owner expr-fn
			      #f ;; ok since EXPR is fully canonical
			      (rtx-env-empty-stack)
			      #f nil 0)
		 appstuff)
)

(define (rtx-traverse-with-locals context owner expr expr-fn locals appstuff)
  (/rtx-traverse expr #f #f 0
		 (tstate-make context owner expr-fn
			      #f ;; ok since EXPR is fully canonical
			      (rtx-env-push (rtx-env-empty-stack)
					    (rtx-env-make-locals locals))
			      #f nil 0)
		 appstuff)
)

; Traverser debugger.
; This just traverses EXPR printing everything it sees.

(define (rtx-traverse-debug expr)
  (rtx-traverse
   #f #f expr
   (lambda (rtx-obj expr parent-expr op-pos tstate appstuff)
     (display "-expr:    ")
     (display (string-append "rtx=" (obj:str-name rtx-obj)))
     (display " expr=")
     (display expr)
     (display " parent=")
     (display parent-expr)
     (display " op-pos=")
     (display op-pos)
     (display " cond?=")
     (display (tstate-cond? tstate))
     (newline)
     #f)
   #f
   )
)

; RTL evaluation state.
; Applications may subclass <eval-state> if they need to add things.
;
; This is initialized before evaluation, and modified (in a copy) as the
; evaluation state changes.
; This doesn't record all evaluation state, just the less dynamic elements.
; There's no point in recording things like the parent expression and operand
; position as they change for every sub-eval.
; The main raison d'etre for this class is so we can add more state without
; having to modify all the eval handlers.

(define <eval-state>
  (class-make '<eval-state> nil
	      '(
		; <context> object or #f if there is none
		(context . #f)

		; Current object rtl is being evaluated for.
		; We need to be able to access the current instruction while
		; generating semantic code.  However, the semantic description
		; doesn't specify it as an argument to anything (and we don't
		; want it to).  So we record the value here.
		(owner . #f)

		;; The outer expr being evaluated, for error messages.
		;; #f if there is none.
		(outer-expr . #f)

		; EXPR-FN is a dual-purpose beast.  The first purpose is to
		; just process the current expression and return the result.
		; The second purpose is to lookup the function which will then
		; process the expression.  It is applied recursively to the
		; expression and each sub-expression.  It must be defined as
		; (lambda (rtx-obj expr mode estate) ...).
		; If the result of EXPR-FN is a lambda, it is applied to
		; (cons ESTATE (cdr EXPR)).  ESTATE is prepended to the
		; arguments.
		; For syntax expressions if the result of EXPR-FN is #f,
		; the operands are processed using the builtin evaluator.
		; FIXME: This special handling of syntax expressions is
		; not currently done.
		; So to repeat: EXPR-FN can process the expression, and if its
		; result is a lambda then it also processes the expression.
		; The arguments to EXPR-FN are
		; (rtx-obj expr mode estate).
		; The arguments to the result of EXPR-FN are
		; (cons ESTATE (cdr EXPR)).
		; The reason for the duality is mostly history.
		; In time things should be simplified.
		(expr-fn . #f)

		; List of ISA name(s) in which to evaluate the expression.
		; This is used for example during operand lookups.
		; All specified ISAs must be compatible,
		; e.g. operand lookups must be unambiguous.
		; A value of #f means "all ISAs".
		(isas . #f)

		; Current environment.  This is a stack of sequence locals,
		; e.g. made with rtx-env-init-stack1.
		(env-stack . ())

		; Current evaluation depth.  This is used, for example, to
		; control indentation in generated output.
		(depth . 0)

		; Associative list of modifiers.
		; This is here to support things like `delay'.
		(modifiers . ())
		)
	      nil)
)

; Create an <eval-state> object using a list of keyword/value elements.
; ARGS is a list of #:keyword/value elements.
; The result is a list of the unrecognized elements.
; Subclasses should override this method and send-next it first, then
; see if they recognize anything in the result, returning what isn't
; recognized.

(method-make!
 <eval-state> 'vmake!
 (lambda (self args)
   (let loop ((args args) (unrecognized nil))
     (if (null? args)
	 (reverse! unrecognized) ; ??? Could invoke method to initialize here.
	 (begin
	   (case (car args)
	     ((#:context)
	      (elm-set! self 'context (cadr args)))
	     ((#:owner)
	      (elm-set! self 'owner (cadr args)))
	     ((#:outer-expr)
	      (elm-set! self 'outer-expr (cadr args)))
	     ((#:expr-fn)
	      (elm-set! self 'expr-fn (cadr args)))
	     ((#:env-stack)
	      (elm-set! self 'env-stack (cadr args)))
	     ((#:isas)
	      (elm-set! self 'isas (cadr args)))
	     ((#:depth)
	      (elm-set! self 'depth (cadr args)))
	     ((#:modifiers)
	      (elm-set! self 'modifiers (cadr args)))
	     (else
	      ; Build in reverse order, as we reverse it back when we're done.
	      (set! unrecognized
		    (cons (cadr args) (cons (car args) unrecognized)))))
	   (loop (cddr args) unrecognized)))))
)

; Accessors.

(define-getters <eval-state> estate
  (context owner outer-expr expr-fn isas env-stack depth modifiers)
)
(define-setters <eval-state> estate
  (isas env-stack depth modifiers)
)

; Build an estate for use in producing a value from rtl.
; CONTEXT is a <context> object or #f if there is none.
; OWNER is the owner of the expression or #f if there is none.

(define (estate-make-for-eval context owner)
  (vmake <eval-state>
	 #:context context
	 #:owner owner
	 #:expr-fn (lambda (rtx-obj expr mode estate)
		     (rtx-evaluator rtx-obj))
	 #:isas (and owner (obj-isa-list owner)))
)

; Create a copy of ESTATE.

(define (estate-copy estate)
  (object-copy-top estate)
)

;; Create a copy of ESTATE with environment stack ENV-STACK added,
;; and the ISA(s) set to ISA-NAME-LIST.

(define (estate-make-closure estate isa-name-list env-stack)
  (let ((result (estate-copy estate)))
    (estate-set-isas! result isa-name-list)
    (estate-set-env-stack! result (append env-stack (estate-env-stack result)))
    result)
)

; Create a copy of ESTATE with environment ENV pushed onto the existing
; environment list.
; There's no routine to pop the environment list as there's no current
; need for it: we make a copy of the state when we push.

(define (estate-push-env estate env)
  (let ((result (estate-copy estate)))
    (estate-set-env-stack! result (cons env (estate-env-stack result)))
    result)
)

; Create a copy of ESTATE with the depth incremented by one.

(define (estate-deepen estate)
  (let ((result (estate-copy estate)))
    (estate-set-depth! result (1+ (estate-depth estate)))
    result)
)

; Create a copy of ESTATE with modifiers MODS.

(define (estate-with-modifiers estate mods)
  (let ((result (estate-copy estate)))
    (estate-set-modifiers! result (append mods (estate-modifiers result)))
    result)
)

; Convert a tstate to an estate.

(define (tstate->estate t)
  (vmake <eval-state>
	 #:context (tstate-context t)
	 #:env-stack (tstate-env-stack t))
)

; Issue an error given an estate.

(define (estate-error estate errmsg . expr)
  (apply context-owner-error
	 (cons (estate-context estate)
	       (cons (estate-owner estate)
		     (cons (string-append "During rtx evalution"
					  (if (estate-outer-expr estate)
					      (string-append " of\n"
							     (rtx-pretty-strdump (estate-outer-expr estate))
							     "\n")
					      ""))
			   (cons errmsg expr)))))
)

; RTL expression evaluation.
;
; ??? These used eval2 at one point.  Not sure which is faster but I suspect
; eval2 is by far.  On the otherhand this has yet to be compiled.  And this way
; is more portable, more flexible, and works with guile 1.2 (which has
; problems with eval'ing self referential vectors, though that's one reason to
; use smobs).

; Set to #t to debug rtx evaluation.

(define /rtx-eval-debug? #f)

; RTX expression evaluator.
;
; EXPR is the expression to be eval'd.  It must be in compiled(canonical) form.
; MODE is the desired mode of EXPR, a <mode> object.
; ESTATE is the current evaluation state.

(define (rtx-eval-with-estate expr mode estate)
  (if /rtx-eval-debug?
      (begin
	(display "Evaluating expr with mode ")
	(display (if (symbol? mode) mode (obj:name mode)))
	(newline)
	(display (rtx-dump expr))
	(newline)
	(rtx-env-stack-dump (estate-env-stack estate))
	))

  (if (pair? expr) ; pair? -> cheap non-null-list?

      (let* ((rtx-obj (rtx-lookup (car expr)))
	     (fn ((estate-expr-fn estate) rtx-obj expr mode estate)))
	(if fn
	    (if (procedure? fn)
		(apply fn (cons estate (cdr expr)))
;		; Don't eval operands for syntax expressions.
;		(if (eq? (rtx-style rtx-obj) 'SYNTAX)
;		    (apply fn (cons estate (cdr expr)))
;		    (let ((operands
;			   (/rtx-eval-operands rtx-obj expr estate)))
;		      (apply fn (cons estate operands))))
		fn)
	    ; Leave expr unchanged.
	    expr))
;	    (let ((operands
;		   (/rtx-traverse-operands rtx-obj expr estate)))
;	      (cons rtx-obj operands))))

      ; EXPR is not a list
      (error "argument to rtx-eval-with-estate is not a list" expr))
)

; Evaluate rtx expression EXPR and return the computed value.
; EXPR must already be in canonical form (the result of rtx-canonicalize).
; OWNER is the owner of the value, used for attribute computation
; and to get the ISA name list.
; OWNER is #f if there isn't one.
; FIXME: context?

(define (rtx-value expr owner)
  (rtx-eval-with-estate expr DFLT (estate-make-for-eval #f owner))
)

;; Initialize the tables.

(define (rtx-init-traversal-tables!)
  (let ((compiler-hash-table (/rtx-make-canon-table))
	(traverser-hash-table (/rtx-make-traverser-table)))

    (set! /rtx-canoner-table (make-vector (rtx-max-num) #f))
    (set! /rtx-traverser-table (make-vector (rtx-max-num) #f))

    (for-each (lambda (rtx-name)
		(let ((rtx (rtx-lookup rtx-name)))
		  (if rtx
		      (let ((num (rtx-num rtx))
			    (arg-types (rtx-arg-types rtx)))
			(vector-set! /rtx-canoner-table num
				     (map1-improper
				      (lambda (arg-type)
					(cons arg-type
					      (hashq-ref compiler-hash-table arg-type)))
				      arg-types))
			(vector-set! /rtx-traverser-table num
				     (map1-improper
				      (lambda (arg-type)
					(cons arg-type
					      (hashq-ref traverser-hash-table arg-type)))
				      arg-types))))))
	      (rtx-name-list)))

  (set! /rtx-operand-canoners (make-vector (rtx-max-num) /rtx-canon-operands))
  (for-each (lambda (rtx-canoner)
	      (let ((rtx-obj (rtx-lookup (car rtx-canoner))))
		(vector-set! /rtx-operand-canoners (rtx-num rtx-obj) (cdr rtx-canoner))))
	    (/rtx-special-expr-canoners))
)
