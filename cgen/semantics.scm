; Routines for instruction semantic analysis (including rtx-simplify).
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; Semantic expression compilation.
; This is more involved than normal rtx compilation as we need to keep
; track of the inputs and outputs.  Various attributes that can be derived
; from the code are also computed.

; Subroutine of -simplify-expr-fn to compare two values for equality.
; If both are constants and they're equal return #f/#t.
; INVERT? = #f -> return #t if equal, #t -> return #f if equal.
; Returns 'unknown if either argument is not a constant.

(define (rtx-const-equal arg0 arg1 invert?)
  (if (and (rtx-constant? arg0)
	   (rtx-constant? arg1))
      (if invert?
	  (!= (rtx-constant-value arg0)
	      (rtx-constant-value arg1))
	  (= (rtx-constant-value arg0)
	     (rtx-constant-value arg1)))
      'unknown)
)

; Subroutine of -simplify-expr-fn to see if MAYBE-CONST is one of NUMBER-LIST.
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

(define (rtx-const-list-equal maybe-const number-list invert?)
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

; Subroutine of -simplify-expr-fn to simplify an eq-attr of (current-mach).
; CONTEXT is a <context> object or #f if there is none.

(define (rtx-simplify-eq-attr-mach rtx context)
  (let ((attr (rtx-eq-attr-attr rtx))
	(value (rtx-eq-attr-value rtx)))
    ; If all currently selected machs will yield the same value
    ; for the attribute, we can simplify.
    (let ((values (map (lambda (m)
			 (obj-attr-value m attr))
		       (current-mach-list))))
      ; Ensure at least one mach is selected.
      (if (null? values)
	  (context-error context "rtx simplification, no machs selected"
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

; Subroutine of -simplify-expr-fn to simplify an eq-attr of (current-insn).

(define (rtx-simplify-eq-attr-insn rtx insn context)
  (let ((attr (rtx-eq-attr-attr rtx))
	(value (rtx-eq-attr-value rtx)))
    (if (not (insn? insn))
	(context-error context
		       "No current insn for `(current-insn)'"
		       (rtx-strdump rtx)))
    (let ((attr-value (obj-attr-value insn attr)))
      (if (eq? value attr-value)
	  (rtx-true)
	  (rtx-false))))
)

; Subroutine of rtx-simplify.
; This is the EXPR-FN argument to rtx-traverse.

(define (-simplify-expr-fn rtx-obj expr mode parent-expr op-pos tstate appstuff)

  ;(display "Processing ") (display (rtx-dump expr)) (newline)

  (case (rtx-name expr)

    ((not)
     (let* ((arg (-rtx-traverse (rtx-alu-op-arg expr 0)
				'RTX
				(rtx-alu-op-mode expr)
				expr 1 tstate appstuff))
	    (no-side-effects? (not (rtx-side-effects? arg))))
       (cond ((and no-side-effects? (rtx-false? arg))
	      (rtx-true))
	     ((and no-side-effects? (rtx-true? arg))
	      (rtx-false))
	     (else (rtx-make 'not (rtx-alu-op-mode expr) arg)))))

    ((orif)
     (let ((arg0 (-rtx-traverse (rtx-boolif-op-arg expr 0)
				'RTX 'DFLT expr 0 tstate appstuff))
	   (arg1 (-rtx-traverse (rtx-boolif-op-arg expr 1)
				'RTX 'DFLT expr 1 tstate appstuff)))
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
     (let ((arg0 (-rtx-traverse (rtx-boolif-op-arg expr 0)
				'RTX 'DFLT expr 0 tstate appstuff))
	   (arg1 (-rtx-traverse (rtx-boolif-op-arg expr 1)
				'RTX 'DFLT expr 1 tstate appstuff)))
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
	    (-rtx-traverse (rtx-if-test expr) 'RTX 'DFLT expr 1 tstate appstuff)))
       (cond ((rtx-true? test)
	      (-rtx-traverse (rtx-if-then expr) 'RTX mode expr 2 tstate appstuff))
	     ((rtx-false? test)
	      (if (rtx-if-else expr)
		  (-rtx-traverse (rtx-if-else expr) 'RTX mode expr 3 tstate appstuff)
		  ; Sanity check, mode must be VOID.
		  (if (or (mode:eq? 'DFLT (rtx-mode expr))
			  (mode:eq? 'VOID (rtx-mode expr)))
		      (rtx-make 'nop)
		      (error "rtx-simplify: non-void-mode `if' missing `else' part" expr))))
	     ; Can't simplify.
	     ; We could traverse the then/else clauses here, but it's simpler
	     ; to have our caller do it.  The cost is retraversing `test'.
	     (else #f))))

    ((eq ne)
     (let ((name (rtx-name expr))
	   (cmp-mode (rtx-cmp-op-mode expr))
	   (arg0 (-rtx-traverse (rtx-cmp-op-arg expr 0) 'RTX
				(rtx-cmp-op-mode expr)
				expr 1 tstate appstuff))
	   (arg1 (-rtx-traverse (rtx-cmp-op-arg expr 1) 'RTX
				(rtx-cmp-op-mode expr)
				expr 2 tstate appstuff)))
       (if (or (rtx-side-effects? arg0) (rtx-side-effects? arg1))
	   (rtx-make name cmp-mode arg0 arg1)
	   (case (rtx-const-equal arg0 arg1 (rtx-kind? 'ne expr))
	     ((#f) (rtx-false))
	     ((#t) (rtx-true))
	     (else
	      ; That didn't work.  See if we have an ifield/operand with a
	      ; known range of values.
	      (case (rtx-name arg0)
		((ifield)
		 (let ((known-val (tstate-known-lookup tstate
						       (rtx-ifield-name arg0))))
		   (if (and known-val (rtx-kind? 'number-list known-val))
		       (case (rtx-const-list-equal arg1 known-val (rtx-kind? 'ne expr))
			 ((#f) (rtx-false))
			 ((#t) (rtx-true))
			 (else
			  (rtx-make name cmp-mode arg0 arg1)))
		       (rtx-make name cmp-mode arg0 arg1))))
		((operand)
		 (let ((known-val (tstate-known-lookup tstate
						       (rtx-operand-name arg0))))
		   (if (and known-val (rtx-kind? 'number-list known-val))
		       (case (rtx-const-list-equal arg1 known-val (rtx-kind? 'ne expr))
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
	    (rtx-simplify-eq-attr-mach expr (tstate-context tstate)))
	   ((rtx-kind? 'current-insn (rtx-eq-attr-owner expr))
	    (rtx-simplify-eq-attr-insn expr (tstate-owner tstate) (tstate-context tstate)))
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

    ; Leave EXPR unchanged and continue.
    (else #f))
)

; Simplify an rtl expresion.
; EXPR must be in source form.
; The result is a possibly simplified EXPR, still in source form.
;
; CONTEXT is a <context> object, used for error messages.
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
  (-rtx-traverse expr #f 'DFLT #f 0
		 (tstate-make context owner
			      (/fastcall-make -simplify-expr-fn)
			      (rtx-env-empty-stack)
			      #f #f known 0)
		 #f)
)

; Utilities for equation solving.
; ??? At the moment this is only focused on ifield assertions.
; ??? That there exist more sophisticated versions than this one can take
; as a given.  This works for the task at hand and will evolve or be replaced
; as necessary.
; ??? This makes the simplifying assumption that no expr has side-effects.

; Subroutine of rtx-solve.
; This is the EXPR-FN argument to rtx-traverse.

(define (-solve-expr-fn rtx-obj expr mode parent-expr op-pos tstate appstuff)
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
;	  (-rtx-traverse simplified-expr #f 'DFLT #f 0
;			 (tstate-make context owner
;				      (/fastcall-make -solve-expr-fn)
;				      (rtx-env-empty-stack)
;				      #f #f known 0)
;			 #f))
	 )
    (cond ((rtx-true? maybe-solved-expr) #t)
	  ((rtx-false? maybe-solved-expr) #f)
	  (else '?)))
)

; Subroutine of -rtx-find-op to determine if two modes are equivalent.
; Two modes are equivalent if they're equal, or if their sem-mode fields
; are equal.

(define (-rtx-mode-equiv? m1 m2)
  (or (eq? m1 m2)
      (let ((mode1 (mode:lookup m1))
	    (mode2 (mode:lookup m2)))
	(let ((s1 (mode:sem-mode mode1))
	      (s2 (mode:sem-mode mode2)))
	  (eq? (if s1 (obj:name s1) m1) (if s2 (obj:name s2) m2)))))
)

; Subroutine of semantic-compile to find OP in OP-LIST.
; OP-LIST is a list of operand expressions: (type expr mode name indx-sel).
; The result is the list element or #f if not found.
; TYPE is one of -op- reg mem.
; EXPR is the constructed `xop' rtx expression for the operand,
;   ignored in the search.
; MODE must match, as defined by -rtx-mode-equiv?.
; NAME is the hardware element name, ifield name, or '-op-'.
; INDX-SEL must match if present in either.
;
; ??? Does this need to take "conditionally-referenced" into account?

(define (-rtx-find-op op op-list)
  (let ((type (car op))
	(mode (caddr op))
	(name (cadddr op))
	(indx-sel (car (cddddr op))))
    ; The first cdr is to drop the dummy first arg.
    (let loop ((op-list (cdr op-list)))
      (cond ((null? op-list) #f)
	    ((eq? type (caar op-list))
	     (let ((try (car op-list)))
	       (if (and (eq? name (cadddr try))
			(-rtx-mode-equiv? mode (caddr try))
			(equal? indx-sel (car (cddddr try))))
		   try
		   (loop (cdr op-list)))))
	    (else (loop (cdr op-list))))))
)

; Subroutine of semantic-compile to determine how the operand in
; position OP-POS of EXPR is used.
; The result is one of 'use, 'set, 'set-quiet.
; "use" means "input operand".

(define (-rtx-ref-type expr op-pos)
  ; operand 0 is the option list, operand 1 is the mode
  ; (if you want to complain, fine, it's not like it would be unexpected)
  (if (= op-pos 2)
      (case (car expr)
	((set) 'set)
	((set-quiet clobber) 'set-quiet)
	(else 'use))
      'use)
)

; Subroutine of semantic-compile:process-expr!, to simplify it.
; Looks up the operand in the current set, returns it if found,
; otherwise adds it.
; REF-TYPE is one of 'use, 'set, 'set-quiet.
; Adds COND-CTI/UNCOND-CTI to SEM-ATTRS if the operand is a set of the pc.

(define (-build-operand! op-name op mode tstate ref-type op-list sem-attrs)
  ;(display (list op-name mode ref-type)) (newline) (force-output)
  (let* ((mode (mode-real-name (if (eq? mode 'DFLT)
				   (op:mode op)
				   mode)))
         ; The first #f is a placeholder for the object.
	 (try (list '-op- #f mode op-name #f))
	 (existing-op (-rtx-find-op try op-list)))

    (if (and (pc? op)
	     (memq ref-type '(set set-quiet)))
	(append! sem-attrs
		 (list (if (tstate-cond? tstate) 'COND-CTI 'UNCOND-CTI))))

    ; If already present, return the object, otherwise add it.
    (if existing-op

	(cadr existing-op)

	; We can't set the operand number yet 'cus we don't know it.
	; However, when it's computed we'll need to set all associated
	; operands.  This is done by creating shared rtx (a la gcc) - the
	; operand number then need only be updated in one place.

	(let ((xop (op:new-mode op mode)))
	  (op:set-cond?! xop (tstate-cond? tstate))
	  ; Set the object rtx in `try', now that we have it.
	  (set-car! (cdr try) (rtx-make 'xop xop))
	  ; Add the operand to in/out-ops.
	  (append! op-list (list try))
	  (cadr try))))
)

; Subroutine of semantic-compile:process-expr!, to simplify it.

(define (-build-reg-operand! expr tstate op-list)
  (let* ((hw-name (rtx-reg-name expr))
	 (hw (current-hw-sem-lookup-1 hw-name)))

    (if hw
	; If the mode is DFLT, use the object's natural mode.
	(let* ((mode (mode-real-name (if (eq? (rtx-mode expr) 'DFLT)
					 (obj:name (hw-mode hw))
					 (rtx-mode expr))))
	       (indx-sel (rtx-reg-index-sel expr))
	       ; #f is a place-holder for the object (filled in later)
	       (try (list 'reg #f mode hw-name indx-sel))
	       (existing-op (-rtx-find-op try op-list)))

	  ; If already present, return the object, otherwise add it.
	  (if existing-op

	      (cadr existing-op)

	      (let ((xop (apply reg (cons (tstate->estate tstate)
					  (cons mode
						(cons hw-name indx-sel))))))
		(op:set-cond?! xop (tstate-cond? tstate))
		; Set the object rtx in `try', now that we have it.
		(set-car! (cdr try) (rtx-make 'xop xop))
		; Add the operand to in/out-ops.
		(append! op-list (list try))
		(cadr try))))

	(parse-error "FIXME" "unknown reg" expr)))
)

; Subroutine of semantic-compile:process-expr!, to simplify it.

(define (-build-mem-operand! expr tstate op-list)
  (let ((mode (rtx-mode expr))
	(indx-sel (rtx-mem-index-sel expr)))

    (if (memq mode '(DFLT VOID))
	(parse-error "FIXME" "memory must have explicit mode" expr))

    (let* ((try (list 'mem #f mode 'h-memory indx-sel))
	   (existing-op (-rtx-find-op try op-list)))

      ; If already present, return the object, otherwise add it.
      (if existing-op

	  (cadr existing-op)

	  (let ((xop (apply mem (cons (tstate->estate tstate)
				      (cons mode indx-sel)))))
	    (op:set-cond?! xop (tstate-cond? tstate))
	    ; Set the object in `try', now that we have it.
	    (set-car! (cdr try) (rtx-make 'xop xop))
	    ; Add the operand to in/out-ops.
	    (append! op-list (list try))
	    (cadr try)))))
)

; Subroutine of semantic-compile:process-expr!, to simplify it.

(define (-build-ifield-operand! expr tstate op-list)
  (let* ((f-name (rtx-ifield-name expr))
	 (f (current-ifld-lookup f-name)))

    (if (not f)
	(parse-error "FIXME" "unknown ifield" f-name))

    (let* ((mode (obj:name (ifld-mode f)))
	   (try (list '-op- #f mode f-name #f))
	   (existing-op (-rtx-find-op try op-list)))

      ; If already present, return the object, otherwise add it.
      (if existing-op

	  (cadr existing-op)

	  (let ((xop (make <operand> f-name f-name
			   (atlist-cons (bool-attr-make 'SEM-ONLY #t)
					(obj-atlist f))
			   (obj:name (ifld-hw-type f))
			   mode
			   (make <hw-index> 'anonymous
				 'ifield (ifld-mode f) f)
			   nil #f #f)))
	    (set-car! (cdr try) (rtx-make 'xop xop))
	    (append! op-list (list try))
	    (cadr try)))))
)

; Subroutine of semantic-compile:process-expr!, to simplify it.
;
; ??? There are various optimizations (both space usage in ARGBUF and time
; spent in semantic code) that can be done on code that uses index-of
; (see i960's movq insn).  Later.

(define (-build-index-of-operand! expr tstate op-list)
  (if (not (and (rtx? (rtx-index-of-value expr))
		(rtx-kind? 'operand (rtx-index-of-value expr))))
      (parse-error "FIXME" "only `(index-of operand)' is currently supported"
		   expr))

  (let ((op (rtx-operand-obj (rtx-index-of-value expr))))
    (let ((indx (op:index op)))
      (if (not (eq? (hw-index:type indx) 'ifield))
	  (parse-error "FIXME" "only ifield indices are currently supported"
		       expr))
      (let* ((f (hw-index:value indx))
	     (f-name (obj:name f)))
	; The rest of this is identical to -build-ifield-operand!.
	(let* ((mode (obj:name (ifld-mode f)))
	       (try (list '-op- #f mode f-name #f))
	       (existing-op (-rtx-find-op try op-list)))

	  ; If already present, return the object, otherwise add it.
	  (if existing-op

	      (cadr existing-op)

	      (let ((xop (make <operand> f-name f-name
			       (atlist-cons (bool-attr-make 'SEM-ONLY #t)
					    (obj-atlist f))
			       (obj:name (ifld-hw-type f))
			       mode
			       (make <hw-index> 'anonymous
				     'ifield
				     (ifld-mode f)
				     ; (send (op:type op) 'get-index-mode)
				     f)
			       nil #f #f)))
		(set-car! (cdr try) (rtx-make 'xop xop))
		(append! op-list (list try))
		(cadr try)))))))
)

; Build the tstate known value list for INSN.
; This built from the ifield-assertion list.

(define (-build-known-values insn)
  (let ((expr (insn-ifield-assertion insn)))
    (if expr
	(case (rtx-name expr)
	  ((eq)
	   (if (and (rtx-kind? 'ifield (rtx-cmp-op-arg expr 0))
		    (rtx-constant? (rtx-cmp-op-arg expr 1)))
	       (list (cons (rtx-ifield-name (rtx-cmp-op-arg expr 0))
			   (rtx-cmp-op-arg expr 1)))
	       nil))
	  ((member)
	   (if (rtx-kind? 'ifield (rtx-member-value expr))
	       (list (cons (rtx-ifield-name (rtx-member-value expr))
			   (rtx-member-set expr)))
	       nil))
	  (else nil))
	nil))
)

; Structure to record the result of semantic-compile.

(define (csem-make compiled-code inputs outputs attributes)
  (vector compiled-code inputs outputs attributes)
)

; Accessors.

(define (csem-code csem) (vector-ref csem 0))
(define (csem-inputs csem) (vector-ref csem 1))
(define (csem-outputs csem) (vector-ref csem 2))
(define (csem-attrs csem) (vector-ref csem 3))

; Traverse each element in SEM-CODE-LIST, converting them to canonical form,
; and computing the input and output operands.
; The result is an object of four elements (built with csem-make).
; The first is a list of the canonical form of each element in SEM-CODE-LIST:
; operand and ifield elements specified without `operand' or `ifield' have it
; prepended, and operand numbers are computed for each operand.
; Operand numbers are needed when emitting "write" handlers for LIW cpus.
; Having the operand numbers available is also useful for efficient
; modeling: recording operand references can be done with a bitmask (one host
; insn), and the code to do the modeling can be kept out of the code that
; performs the insn.
; The second is the list of input <operand> objects.
; The third is the list of output <operand> objects.
; The fourth is an <attr-list> object of attributes that can be computed from
; the semantics.
; The possibilities are: UNCOND-CTI, COND-CTI, SKIP-CTI, DELAY-SLOT.
; ??? Combine *-CTI into an enum attribute.
;
; CONTEXT is a <context> object or #f if there is none.
; INSN is the <insn> object.
;
; ??? Specifying operand ordinals in the source would simplify this and speed
; it up.  On the other hand that makes the source form more complex.  Maybe the
; complexity will prove necessary, but following the goal of "incremental
; complication", we don't do this yet.
; Another way to simplify this and speed it up would be to add lists of
; input/output operands to the instruction description.
;
; ??? This calls rtx-simplify which calls rtx-traverse as it's simpler to
; simplify EXPR first, and then compile it.  On the other hand it's slower
; (two calls to rtx-traverse!).

(define (semantic-compile context insn sem-code-list)
  (for-each (lambda (rtx) (assert (rtx? rtx)))
	    sem-code-list)

  (let*
      ; String for error messages.
      ((errtxt "semantic compilation")

       ; These record the result of traversing SEM-CODE-LIST.
       ; They're lists of (type object mode name [args ...]).
       ; TYPE is one of: -op- reg mem.
       ; `-op-' is just something unique and is only used internally.
       ; OBJECT is the constructed <operand> object.
       ; The first element is just a dummy so that append! always works.
       (in-ops (list (list #f)))
       (out-ops (list (list #f)))

       ; List of attributes computed from SEM-CODE-LIST.
       ; The first element is just a dummy so that append! always works.
       (sem-attrs (list #f))

       ; Called for expressions encountered in SEM-CODE-LIST.
       ; Don't waste cpu here, this is part of the slowest piece in CGEN.
       (process-expr!
	(lambda (rtx-obj expr mode parent-expr op-pos tstate appstuff)
	  (case (car expr)

	    ; Registers.
	    ((reg) (let ((ref-type (-rtx-ref-type parent-expr op-pos))
			 ; ??? could verify reg is a scalar
			 (regno (or (rtx-reg-number expr) 0)))
		     ; The register number is either a number or an
		     ; expression.
		     ; ??? This is a departure from GCC RTL that might have
		     ; significant ramifications.  On the other hand in cases
		     ; where it matters the expression could always be
		     ; required to reduce to a constant (or some such).
		     (cond ((number? regno) #t)
			   ((form? regno)
			    (rtx-traverse-operands rtx-obj expr tstate appstuff))
			   (else (parse-error errtxt
					      "invalid register number"
					      regno)))
		     (-build-reg-operand! expr tstate
					  (if (eq? ref-type 'use)
					      in-ops
					      out-ops))))

	    ; Memory.
	    ((mem) (let ((ref-type (-rtx-ref-type parent-expr op-pos)))
		     (rtx-traverse-operands rtx-obj expr tstate appstuff)
		     (-build-mem-operand! expr tstate
					  (if (eq? ref-type 'use)
					      in-ops
					      out-ops))))

	    ; Operands.
	    ((operand) (let ((op (rtx-operand-obj expr))
			     (ref-type (-rtx-ref-type parent-expr op-pos)))
			 (-build-operand! (obj:name op) op mode tstate ref-type
					  (if (eq? ref-type 'use)
					      in-ops
					      out-ops)
					  sem-attrs)))

	    ; Give operand new name.
	    ((name) (let ((result (-rtx-traverse (caddr expr) 'RTX mode
						 parent-expr op-pos tstate appstuff)))
		      (if (not (operand? result))
			  (error "name: invalid argument:" expr result))
		      (op:set-sem-name! result (cadr expr))
		      ; (op:set-num! result (caddr expr))
		      result))

	    ; Specify a reference to a local variable
	    ((local) expr) ; nothing to do

	    ; Instruction fields.
	    ((ifield) (let ((ref-type (-rtx-ref-type parent-expr op-pos)))
			(if (not (eq? ref-type 'use))
			    (parse-error errtxt "can't set an `ifield'" expr))
			(-build-ifield-operand! expr tstate in-ops)))

	    ; Hardware indices.
	    ; For registers this is the register number.
	    ; For memory this is the address.
	    ; For constants, this is the constant.
	    ((index-of) (let ((ref-type (-rtx-ref-type parent-expr op-pos)))
			  (if (not (eq? ref-type 'use))
			      (parse-error errtxt "can't set an `index-of'" expr))
			  (-build-index-of-operand! expr tstate in-ops)))

	    ; Machine generate the SKIP-CTI attribute.
	    ((skip) (append! sem-attrs (list 'SKIP-CTI)) #f)

	    ; Machine generate the DELAY-SLOT attribute.
	    ((delay) (append! sem-attrs (list 'DELAY-SLOT)) #f)

	    ; If this is a syntax expression, the operands won't have been
	    ; processed, so tell our caller we want it to by returning #f.
	    ; We do the same for non-syntax expressions to keep things
	    ; simple.  This requires collaboration with the traversal
	    ; handlers which are defined to do what we want if we return #f.
	    (else #f))))

       ; Whew.  We're now ready to traverse the expression.
       ; Traverse the expression recording the operands and building objects
       ; for most elements in the source representation.
       ; This also performs various simplifications.
       ; In particular machine dependent code for non-selected machines
       ; is discarded.
       (compiled-exprs (map (lambda (expr)
			      (rtx-traverse
			       context
			       insn
			       (rtx-simplify context insn expr
					     (-build-known-values insn))
			       process-expr!
			       #f))
			    sem-code-list))
       )

    ;(display "in:  ") (display in-ops) (newline)
    ;(display "out: ") (display out-ops) (newline)
    ;(force-output)

    ; Now that we have the nub of all input and output operands,
    ; we can assign operand numbers.  Inputs and outputs are not defined
    ; separately, output operand numbers follow inputs.  This simplifies the
    ; code which keeps track of such things: it can use one variable.
    ; The assignment is defined to be arbitrary.  If there comes a day
    ; when we need to prespecify operand numbers, revisit.
    ; The operand lists are sorted to avoid spurious differences in generated
    ; code (for example unnecessary extra entries can be created in the
    ; ARGBUF struct).

    ; Drop dummy first arg and sort operand lists.
    (let ((sorted-ins
	   (sort (map (lambda (op)
			(rtx-xop-obj (cadr op)))
		      (cdr in-ops))
		 (lambda (a b) (string<? (obj:name a) (obj:name b)))))
	  (sorted-outs
	   (sort (map (lambda (op)
			(rtx-xop-obj (cadr op)))
		      (cdr out-ops))
		 (lambda (a b) (string<? (obj:name a) (obj:name b)))))
	  (sem-attrs (cdr sem-attrs)))

      (let ((in-op-nums (iota (length sorted-ins)))
	    (out-op-nums (iota (length sorted-ins) (length sorted-outs))))

	(for-each (lambda (op num) (op:set-num! op num))
		  sorted-ins in-op-nums)
	(for-each (lambda (op num) (op:set-num! op num))
		  sorted-outs out-op-nums)

	(let ((dump (lambda (op)
		      (string-append "  "
				     (obj:name op)
				     " "
				     (number->string (op:num op))
				     "\n"))))
	  (logit 4
		 "Input operands:\n"
		 (map dump sorted-ins)
		 "Output operands:\n"
		 (map dump sorted-outs)
		 "End of operands.\n"))

	(csem-make compiled-exprs sorted-ins sorted-outs
		   (atlist-parse sem-attrs "" "semantic attributes")))))
)

; Traverse SEM-CODE-LIST, computing attributes derivable from it.
; The result is an <attr-list> object of attributes that can be computed from
; the semantics.
; The possibilities are: UNCOND-CTI, COND-CTI, SKIP-CTI, DELAY-SLOT.
; This computes the same values as semantic-compile, but for speed is
; focused on attributes only.
; ??? Combine *-CTI into an enum attribute.
;
; CONTEXT is a <context> object or #f if there is none.
; INSN is the <insn> object.

(define (semantic-attrs context insn sem-code-list)
  (for-each (lambda (rtx) (assert (rtx? rtx)))
	    sem-code-list)

  (let*
      ; String for error messages.
      ((errtxt "semantic attribute computation")

       ; List of attributes computed from SEM-CODE-LIST.
       ; The first element is just a dummy so that append! always works.
       (sem-attrs (list #f))

       ; Called for expressions encountered in SEM-CODE-LIST.
       (process-expr!
	(lambda (rtx-obj expr mode parent-expr op-pos tstate appstuff)
	  (case (car expr)

	    ((operand) (if (and (eq? 'pc (obj:name (rtx-operand-obj expr)))
				(memq (-rtx-ref-type parent-expr op-pos)
				      '(set set-quiet)))
			   (append! sem-attrs
				    (if (tstate-cond? tstate)
					; Don't change these to '(FOO), since
					; we use append!.
					(list 'COND-CTI)
					(list 'UNCOND-CTI)))))
	    ((skip) (append! sem-attrs (list 'SKIP-CTI)) #f)
	    ((delay) (append! sem-attrs (list 'DELAY-SLOT)) #f)

	    ; If this is a syntax expression, the operands won't have been
	    ; processed, so tell our caller we want it to by returning #f.
	    ; We do the same for non-syntax expressions to keep things
	    ; simple.  This requires collaboration with the traversal
	    ; handlers which are defined to do what we want if we return #f.
	    (else #f))))

       ; Traverse the expression recording the attributes.
       (traversed-exprs (map (lambda (expr)
			       (rtx-traverse
				context
				insn
				(rtx-simplify context insn expr
					      (-build-known-values insn))
				process-expr!
				#f))
			     sem-code-list))
       )

    (let
	; Drop dummy first arg.
	((sem-attrs (cdr sem-attrs)))
      (atlist-parse sem-attrs "" "semantic attributes")))
)
