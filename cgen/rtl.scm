; Basic RTL support.
; Copyright (C) 2000, 2001, 2009, 2010 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; The name for the description language has been changed a couple of times.
; RTL isn't my favorite because of perceived confusion with GCC
; (and perceived misinterpretation of intentions!).
; On the other hand my other choices were taken (and believed to be
; more confusing).
;
; RTL functions are described by class <rtx-func>.
; The complete list of rtl functions is defined in doc/rtl.texi.

; Conventions used in this file:
; - procs that perform the basic rtl or semantic expression manipulation that
;   is for public use shall be prefixed with "s-" or "rtl-" or "rtx-"
; - no other procs shall be so prefixed
; - rtl globals and other rtx-func object support shall be prefixed with
;   "-rtx[-:]"
; - no other procs shall be so prefixed

; Class for defining rtx nodes.

; FIXME: Add new members that are lambda's to perform the argument checking
; specified by `arg-types' and `arg-modes'.  This will save a lookup during
; traversing.  It will also allow custom versions for oddballs (e.g. for
; `member' we want to verify the 2nd arg is a `number-list' rtx).
; ??? Still useful?

(define <rtx-func>
  (class-make '<rtx-func> nil
	      '(
		; name as it appears in RTL
		; must be accessed via obj:name
		name

		; argument list
		; ??? Not used I think, but keep.
		args

		; result mode, or #f if from arg 2
		; (or the containing expression when canonicalizing)
		result-mode

		; types of each argument, as symbols
		; This is #f for macros.
		; Possible values:
		; OPTIONS - optional list of keyword-prefixed options
		; ANYINTMODE - any integer mode
		; ANYFLOATMODE - any floating point mode
		; ANYNUMMODE - any numeric mode
		; ANYEXPRMODE - VOID, PTR, SYM, or any numeric mode
		; ANYCEXPRMODE - VOID, PTR, or any numeric mode
		; EXPLNUMMODE - explicit numeric mode, can't be DFLT or VOID
		; VOIDORNUMMODE - VOID or any numeric mode
		; VOIDMODE - must be `VOID'
		; BIMODE - BI (boolean or bit int)
		; INTMODE - must be `INT'
		; SYMMODE - must be SYM
		; INSNMODE - must be INSN
		; MACHMODE - must be MACH
		; RTX - any rtx
		; SETRTX - any rtx allowed to be `set'
		; TESTRTX - the test of an `if'
		; CONDRTX - a cond expression ((test) rtx ... rtx)
		; CASERTX - a case expression ((symbol .. symbol) rtx ... rtx)
		; LOCALS - the locals list of a sequence
		; ITERATION - the iteration 
		; SYMBOLLIST - used for ISA name lists
		; ENVSTACK - environment stack
		; ATTRS - attribute list
		; SYMBOL - arg must be a symbol
		; STRING - arg must be a string
		; NUMBER - arg must be a number
		; SYMORNUM - arg must be a symbol or number
		; OBJECT - arg is an object (FIXME: restrict to <operand>?)
		arg-types

		; required mode of each argument
		; This is #f for macros.
		; Possible values include any mode name and:
		; ANY - any mode
		; ANYINT - any integer mode
		; NA - not applicable
		; MATCHEXPR - mode has to match the mode specified in the
		;             containing expression
		;             NOTE: This isn't necessarily the mode of the
		;             result of the expression.  E.g. in `set', the
		;             result always has mode VOID, but the mode
		;             specified in the expression is the mode of the
		;             set destination.
		; MATCHSEQ - for sequences
		;            last expression has to match mode of sequence,
		;            preceding expressions must be VOID
		; MATCH2 - must match mode of arg 2
		; MATCH3 - must match mode of arg 3
		; <MODE-NAME> - must match specified mode
		arg-modes

		; arg number of the MATCHEXPR arg,
		; or #f if there is none
		matchexpr-index

		; The class of rtx.
		; This is #f for macros.
		; ARG - operand, local, const
		; SET - set, set-quiet
		; UNARY - not, inv, etc.
		; BINARY - add, sub, etc.
		; TRINARY - addc, subc, etc.
		; COMPARE - eq, ne, etc.
		; IF - if
		; COND - cond, case
		; SEQUENCE - sequence, parallel
		; UNSPEC - c-call
		; MISC - everything else
		class

		; A symbol indicating the flavour of rtx node this is.
		; FUNCTION - normal function
		; SYNTAX - don't pre-eval arguments
		; OPERAND - result is an operand
		; MACRO - converts one rtx expression to another
		; The word "style" was chosen to be sufficiently different
		; from "type", "kind", and "class".
		style

		; A function to perform the rtx.
		evaluator

		; Ordinal number of rtx.  Used to index into tables.
		num
		)
	      nil)
)

; Predicate.

(define (rtx-func? x) (class-instance? <rtx-func> x))

; Accessor fns

(define-getters <rtx-func> rtx
  (result-mode arg-types arg-modes matchexpr-index class style evaluator num)
)

(define (rtx-style-syntax? rtx) (eq? (rtx-style rtx) 'syntax))

; Add standard `get-name' method since this isn't a subclass of <ident>.

(method-make! <rtx-func> 'get-name (lambda (self) (elm-get self 'name)))

; List of mode types for arg-types.

(define /rtx-valid-mode-types
  '(
    ANYINTMODE ANYFLOATMODE ANYNUMMODE ANYEXPRMODE ANYCEXPRMODE EXPLNUMMODE
    VOIDORNUMMODE VOIDMODE BIMODE INTMODE SYMMODE INSNMODE MACHMODE
   )
)

; List of valid values for arg-types, not including mode names.

(define /rtx-valid-types
  (append
   '(OPTIONS)
    /rtx-valid-mode-types
    '(RTX SETRTX TESTRTX CONDRTX CASERTX)
    '(LOCALS ITERATION SYMBOLLIST ENVSTACK ATTRS)
    '(SYMBOL STRING NUMBER SYMORNUM OBJECT)
    )
)

; List of valid mode matchers, excluding mode names.

(define /rtx-valid-matches
  '(ANY ANYINT NA MATCHEXPR MATCHSEQ MATCH2 MATCH3)
)

;; Return arg number of MATCHEXPR in ARG-MODES or #f if not present.

(define (/rtx-find-matchexpr-index arg-modes)
  ;; We can't use find-first-index here because arg-modes can be an
  ;; improper list (a b c . d).
  ;;(find-first-index 0 (lambda (t) (eq? t 'MATCHEXPR)) arg-modes)
  (define (improper-find-first-index i pred l)
    (cond ((null? l) #f)
	  ((pair? l)
	   (cond ((pred (car l)) i)
		 (else (improper-find-first-index (+ 1 i) pred (cdr l)))))
	  ((pred l) i)
	  (else #f)))
  (improper-find-first-index 0 (lambda (t) (eq? t 'MATCHEXPR)) arg-modes)
)

; List of all defined rtx names.  This can be map'd over without having
; to know the innards of /rtx-func-table (which is a hash table).

(define /rtx-name-list nil)
(define (rtx-name-list) /rtx-name-list)

; Table of rtx function objects.
; This is set in rtl-init!.

(define /rtx-func-table nil)

; Look up the <rtx-func> object for RTX-KIND.
; Returns the object or #f if not found.
; RTX-KIND is the name of the rtx function.

(define (rtx-lookup rtx-kind)
  (assert (symbol? rtx-kind))
  (hashq-ref /rtx-func-table rtx-kind)
)

; Table of rtx macro objects.
; This is set in rtl-init!.

(define /rtx-macro-table nil)

; Table of operands, modes, and other non-functional aspects of RTL.
; This is defined in rtl-finish!, after all operands have been read in.

(define /rtx-operand-table nil)

; Number of next rtx to be defined.

(define /rtx-num-next #f)

; Return the number of rtx's.

(define (rtx-max-num)
  /rtx-num-next
)

; Define Rtx Node
;
; Add an entry to the rtx function table.
; NAME-ARGS is a list of the operation name and arguments.
; The mode of the result must be the first element in `args' (if there are
; any arguments).
; ARG-TYPES is a list of argument types (/rtx-valid-types).
; ARG-MODES is a list of mode matchers (/rtx-valid-matches).
; CLASS is the class of the rtx to be created.
; ACTION is a list of Scheme expressions to perform the operation.
;
; ??? Note that we can support variables.  Not sure it should be done.

(define (def-rtx-node name-args result-mode arg-types arg-modes class action)
  (let* ((name (car name-args))
	 (args (cdr name-args))
	 (context (make-prefix-context (string-append "defining rtx "
						      (symbol->string name))))
	 (matchexpr-index (/rtx-find-matchexpr-index arg-modes)))

;    (map1-improper (lambda (arg-type)
;		     (if (not (memq arg-type /rtx-valid-types))
;			 (context-error context "While defining rtx functions"
;					"invalid arg type" arg-type)))
;		   arg-types)
;    (map1-improper (lambda (arg-mode)
;		     (if (and (not (memq arg-mode /rtx-valid-matches))
;			      (not (symbol? arg-mode))) ;; FIXME: mode-name?
;			 (context-error context "While defining rtx functions"
;					"invalid arg mode match" arg-mode)))
;		   arg-modes)

    (let ((rtx (make <rtx-func> name args
		     result-mode arg-types arg-modes matchexpr-index
		     class
		     'function
		     (if action
			 (eval1 (list 'lambda
				      (cons '*estate* args)
				      action))
			 #f)
		     /rtx-num-next)))
      ; Add it to the table of rtx handlers.
      (hashq-set! /rtx-func-table name rtx)
      (set! /rtx-num-next (+ /rtx-num-next 1))
      (set! /rtx-name-list (cons name /rtx-name-list))
      *UNSPECIFIED*))
)

(define define-rtx-node
  ; Written this way so Hobbit can handle it.
  (defmacro:syntax-transformer (lambda arg-list
				 (apply def-rtx-node arg-list)
				 nil))
)

; Same as define-rtx-node but don't pre-evaluate the arguments.
; Remember that `mode' must be the first argument.

(define (def-rtx-syntax-node name-args result-mode arg-types arg-modes class action)
  (let ((name (car name-args))
	(args (cdr name-args))
	(matchexpr-index (/rtx-find-matchexpr-index arg-modes)))
    (let ((rtx (make <rtx-func> name args
		     result-mode arg-types arg-modes matchexpr-index
		     class
		     'syntax
		     (if action
			 (eval1 (list 'lambda
				      (cons '*estate* args)
				      action))
			 #f)
		     /rtx-num-next)))
      ; Add it to the table of rtx handlers.
      (hashq-set! /rtx-func-table name rtx)
      (set! /rtx-num-next (+ /rtx-num-next 1))
      (set! /rtx-name-list (cons name /rtx-name-list))
      *UNSPECIFIED*))
)

(define define-rtx-syntax-node
  ; Written this way so Hobbit can handle it.
  (defmacro:syntax-transformer (lambda arg-list
				 (apply def-rtx-syntax-node arg-list)
				 nil))
)

; Same as define-rtx-node but return an operand (usually an <operand> object).
; ??? `mode' must be the first argument?

(define (def-rtx-operand-node name-args result-mode arg-types arg-modes class action)
  ; Operand nodes must specify an action.
  (assert action)
  (let ((name (car name-args))
	(args (cdr name-args))
	(matchexpr-index (/rtx-find-matchexpr-index arg-modes)))
    (let ((rtx (make <rtx-func> name args
		     result-mode arg-types arg-modes matchexpr-index
		     class
		     'operand
		     (eval1 (list 'lambda
				  (cons '*estate* args)
				  action))
		     /rtx-num-next)))
      ; Add it to the table of rtx handlers.
      (hashq-set! /rtx-func-table name rtx)
      (set! /rtx-num-next (+ /rtx-num-next 1))
      (set! /rtx-name-list (cons name /rtx-name-list))
      *UNSPECIFIED*))
)

(define define-rtx-operand-node
  ; Written this way so Hobbit can handle it.
  (defmacro:syntax-transformer (lambda arg-list
				 (apply def-rtx-operand-node arg-list)
				 nil))
)

; Convert one rtx expression into another.
; NAME-ARGS is a list of the operation name and arguments.
; ACTION is a list of Scheme expressions to perform the operation.
; The result of ACTION must be another rtx expression (a list).

(define (def-rtx-macro-node name-args action)
  ; macro nodes must specify an action
  (assert action)
  (let ((name (car name-args))
	(args (cdr name-args)))
    (let ((rtx (make <rtx-func> name args #f #f #f #f
		     #f ; class
		     'macro
		     (eval1 (list 'lambda args action))
		     /rtx-num-next)))
      ; Add it to the table of rtx macros.
      (hashq-set! /rtx-macro-table name rtx)
      (set! /rtx-num-next (+ /rtx-num-next 1))
      (set! /rtx-name-list (cons name /rtx-name-list))
      *UNSPECIFIED*))
)

(define define-rtx-macro-node
  ; Written this way so Hobbit can handle it.
  (defmacro:syntax-transformer (lambda arg-list
				 (apply def-rtx-macro-node arg-list)
				 nil))
)

; RTL macro expansion.
; RTL macros are different than pmacros.  The difference is that the expansion
; happens internally, RTL macros are part of the language.

; Lookup MACRO-NAME and return its <rtx-func> object or #f if not found.

(define (/rtx-macro-lookup macro-name)
  (hashq-ref /rtx-macro-table macro-name)
)

; Lookup (car exp) and return the macro's lambda if it is one or #f.

(define (/rtx-macro-check exp fn-getter)
  (let ((macro (hashq-ref /rtx-macro-table (car exp))))
    (if macro
	(fn-getter macro)
	#f))
)

; Expand a list.

(define (/rtx-macro-expand-list exp fn-getter)
  (let ((macro (/rtx-macro-check exp fn-getter)))
    (if macro
	(apply macro (map (lambda (x) (/rtx-macro-expand x fn-getter))
			  (cdr exp)))
	(map (lambda (x) (/rtx-macro-expand x fn-getter))
	     exp)))
)

; Main entry point to expand a macro invocation.

(define (/rtx-macro-expand exp fn-getter)
  (if (pair? exp) ; pair? -> cheap (and (not (null? exp)) (list? exp))
      (let ((result (/rtx-macro-expand-list exp fn-getter)))
	; If the result is a new macro invocation, recurse.
	(if (pair? result)
	    (let ((macro (/rtx-macro-check result fn-getter)))
	      (if macro
		  (/rtx-macro-expand (apply macro (cdr result)) fn-getter)
		  result))
	    result))
      exp)
)

; Publically accessible version.

(define rtx-macro-expand /rtx-macro-expand)

; RTX mode support.

; Get implied mode of X, either an operand expression, sequence temp, or
; a hardware reference expression.
; The result is the name of the mode.

(define (rtx-lvalue-mode-name estate x)
  (assert (rtx? x))
  (case (car x)
;    ((operand) (obj:name (op:mode (current-op-lookup (cadr x) (obj-isa-list (estate-owner estate))))))
    ((xop) (obj:name (send (rtx-xop-obj x) 'get-mode)))
;    ((opspec)
;     (if (eq? (rtx-opspec-mode x) 'VOID)
;	 (rtx-lvalue-mode-name estate (rtx-opspec-hw-ref x))
;	 (rtx-opspec-mode x)))
;    ((reg mem) (cadr x))
    ((local) ;; (local options mode name)
     (let* ((name (cadddr x))
	    (temp (rtx-temp-lookup (estate-env-stack estate) name)))
       (if (not temp)
	   (estate-error estate "unknown local" name))
       (obj:name (rtx-temp-mode temp))))
    (else
     (estate-error error
		   "rtx-lvalue-mode-name: not an operand or hardware reference:"
		   x)))
)

; Lookup the mode to use for semantic operations (unsigned modes aren't
; allowed since we don't have ANDUSI, etc.).
; MODE is a <mode> object.
; ??? I have actually implemented both ways (full use of unsigned modes
; and mostly hidden use of unsigned modes).  Neither makes me real
; comfortable, though I liked bringing unsigned modes out into the open
; even if it doubled the number of semantic operations.

(define (rtx-sem-mode mode) (or (mode:sem-mode mode) mode))

; Return the mode of object OBJ.

(define (rtx-obj-mode obj) (send obj 'get-mode))

; Return a boolean indicating of modes M1,M2 are compatible.
; M1,M2 are <mode> objects.

(define (rtx-mode-compatible? m1 m2)
  ;; ??? This is more permissive than is perhaps proper.
  (let ((mode1 (rtx-sem-mode m1))
	(mode2 (rtx-sem-mode m2)))
    ;;(eq? (obj:name mode1) (obj:name mode2)))
    (mode-compatible? 'sameclass mode1 mode2))
)

; Environments (sequences with local variables).

; Temporaries are created within a sequence.
; MODE is a <mode> object.
; VALUE is #f if not set yet.
; e.g. (sequence ((WI tmp)) (set tmp reg0) ...)
; ??? Perhaps what we want here is `let' but for now I prefer `sequence'.
; This isn't exactly `let' either as no initial value is specified.
; Environments are also used to specify incoming values from the top level.

(define <rtx-temp> (class-make '<rtx-temp> nil '(name mode value) nil))

;(define cx-temp:name (elm-make-getter <c-expr-temp> 'name))
;(define cx-temp:mode (elm-make-getter <c-expr-temp> 'mode))
;(define cx-temp:value (elm-make-getter <c-expr-temp> 'value))

(define-getters <rtx-temp> rtx-temp (name mode value))

(method-make!
 <rtx-temp> 'make!
 (lambda (self name mode value)
   (assert (mode? mode))
   (elm-set! self 'name name)
   (elm-set! self 'mode mode)
   (elm-set! self 'value (if value value (gen-temp name)))
   self)
)

(define (gen-temp name)
  ; ??? calls to gen-c-symbol don't belong here
  (string-append "tmp_" (gen-c-symbol name))
)

; Return a boolean indicating if X is an <rtx-temp>.

(define (rtx-temp? x) (class-instance? <rtx-temp> x))

; Respond to 'get-mode messages.

(method-make! <rtx-temp> 'get-mode (lambda (self) (elm-get self 'mode)))

; Respond to 'get-name messages.

(method-make! <rtx-temp> 'get-name (lambda (self) (elm-get self 'name)))

; An environment is a list of <rtx-temp> objects.
; An environment stack is a list of environments.

(define (rtx-env-stack-empty? env-stack) (null? env-stack))
(define (rtx-env-stack-head env-stack) (car env-stack))
(define (rtx-env-empty-stack) nil)
(define (rtx-env-init-stack1 vars-alist)
  (if (null? vars-alist)
      nil
      (cons (rtx-env-make vars-alist) nil))
)
(define (rtx-env-empty? env) (null? env))

;; Create an environment from VAR-ALIST,
;; an alist of (name <mode>-or-mode-name value) elements,
;; or, in the case of /rtx-closure-make, a list of (name . <rtx-temp>).

(define (rtx-env-make var-alist)
  ;; Check for an already-compiled environment, for /rtx-closure-make's sake.
  (if (and (pair? var-alist)
	   (rtx-temp? (cdar var-alist)))
      var-alist
      ;; Convert VAR-ALIST to an associative list of <rtx-temp> objects.
      (map (lambda (var-spec)
	     (cons (car var-spec)
		   (make <rtx-temp>
		     (car var-spec)
		     (mode-maybe-lookup (cadr var-spec))
		     (caddr var-spec))))
	   var-alist))
)

; Create an initial environment with local variables.
; VAR-LIST is a list of (mode-name name) elements, i.e. the locals argument to
; `sequence' or equivalent thereof.

(define (rtx-env-make-locals var-list)
  ; Convert VAR-LIST to an associative list of <rtx-temp> objects.
  (map (lambda (var-spec)
	 (cons (cadr var-spec)
	       (make <rtx-temp>
		 (cadr var-spec) (mode:lookup (car var-spec)) #f)))
       var-list)
)

; Return the symbol name of the limit variable of `do-count'
; given iteration-variable ITER-VAR.
; ??? We don't publish that this variable is available to use, but we could.

(define (rtx-make-iteration-limit-var iter-var)
  (symbol-append iter-var '-limit)
)

; Create an environment with the iteration local variables of `do-count'.

(define (rtx-env-make-iteration-locals iter-var)
  (rtx-env-make-locals (list (list 'INT iter-var)
			     (list 'INT (rtx-make-iteration-limit-var iter-var))))
)

;; Convert an alist of (name <mode>-object-or-name value) to
;; an environment.

(define (rtx-var-alist-to-env var-alist) var-alist)

;; Convert an alist of (name <mode>-object-or-name value) to
;; an environment stack.

(define (rtx-var-alist-to-closure-env-stack var-alist)
  ;; Preserve emptiness so (null? env-stack) works.
  (if (null? var-alist)
      nil
      (list var-alist))
)

;; Convert the source form of an env-stack, e.g. as used in a closure,
;; to the internal form, which is (name <rtx-temp>-object).

(define (rtx-make-env-stack closure-env-stack)
  (map rtx-env-make closure-env-stack)
)

; Push environment ENV onto the front of environment stack ENV-STACK,
; returning a new object.  ENV-STACK is not modified.

(define (rtx-env-push env-stack env)
  (cons env env-stack)
)

; Lookup variable NAME in environment stack ENV-STACK.
; The result is the <rtx-temp> object.

(define (rtx-temp-lookup env-stack name)
  (let loop ((stack env-stack))
    (if (null? stack)
	#f
	(let ((temp (assq-ref (car stack) name)))
	  (if temp
	      temp
	      (loop (cdr stack))))))
)

; Create a "closure" of EXPR using the current ISA list and temp stack.
; MODE is the mode name.

(define (/rtx-closure-make estate mode expr)
  ;; NOTE: This records the "compiled" environment stack in the closure.
  (rtx-make 'closure mode (estate-isas estate) (estate-env-stack estate)
	    expr)
)

(define (rtx-env-stack-dump env-stack)
  (let ((stack env-stack))
    (if (rtx-env-stack-empty? stack)
	(display "rtx-env stack (empty):\n")
	(let loop ((stack stack) (level 0))
	  (if (null? stack)
	      #f ; done
	      (begin
		(display "rtx-env stack, level ")
		(display level)
		(display ":\n")
		(for-each (lambda (var)
			    (display "  ")
			    ;(display (obj:name (rtx-temp-mode (cdr var))))
			    ;(display " ")
			    (display (rtx-temp-name (cdr var)))
			    (newline))
			  (car stack))
		(loop (cdr stack) (+ level 1)))))))
)

; Build, test, and analyze various kinds of rtx's.
; ??? A lot of this could be machine generated except that I don't yet need
; that much.

(define (rtx-make kind . args)
  (cons kind (rtx-munge-mode&options (rtx-lookup kind) 'DFLT kind args))
)

(define rtx-name car)
(define (rtx-kind? kind rtx) (eq? kind (rtx-name rtx)))

(define (rtx-make-const mode value) (rtx-make 'const mode value))
(define (rtx-make-enum mode value) (rtx-make 'enum mode value))

(define (rtx-constant? rtx) (memq (rtx-name rtx) '(const enum)))

; Return value of constant RTX (either const or enum).
(define (rtx-constant-value rtx)
  (case (rtx-name rtx)
    ((const) (rtx-const-value rtx))
    ((enum) (car (enum-lookup-val (rtx-enum-value rtx))))
    (else (error "rtx-constant-value: not const or enum" rtx)))
)

(define rtx-options cadr)
(define rtx-mode caddr)
(define rtx-args cdddr)
(define rtx-arg1 cadddr)
(define (rtx-arg2 rtx) (car (cddddr rtx)))

(define rtx-const-value rtx-arg1)
(define rtx-enum-value rtx-arg1)

(define rtx-reg-name rtx-arg1)

; Return register number or #f if absent.
; (reg options mode hw-name [regno [selector]])
(define (rtx-reg-number rtx) (list-maybe-ref rtx 4))

; Return register selector or #f if absent.
(define (rtx-reg-selector rtx) (list-maybe-ref rtx 5))

; Return both register number and selector.
(define rtx-reg-index-sel cddddr)

; Return memory address.
(define rtx-mem-addr rtx-arg1)

; Return memory selector or #f if absent.
(define (rtx-mem-sel mem) (list-maybe-ref mem 4))

; Return both memory address and selector.
(define rtx-mem-index-sel cdddr)

; Return MEM with new address NEW-ADDR.
; ??? Complicate as necessary.
(define (rtx-change-address mem new-addr)
  (rtx-make 'mem
	    (rtx-options mem)
	    (rtx-mode mem)
	    new-addr
	    (rtx-mem-sel mem))
)

; Return argument to `symbol' rtx.
(define rtx-symbol-name rtx-arg1)

(define (rtx-make-ifield mode-name ifield-name)
  (rtx-make 'ifield mode-name ifield-name)
)
(define (rtx-ifield? rtx) (eq? 'ifield (rtx-name rtx)))
(define (rtx-ifield-name rtx)
  (let ((ifield (rtx-arg1 rtx)))
    (if (symbol? ifield)
	ifield
	(obj:name ifield)))
)
(define (rtx-ifield-obj rtx)
  (let ((ifield (rtx-arg1 rtx)))
    (if (symbol? ifield)
	(current-ifld-lookup ifield)
	ifield))
)

(define (rtx-make-operand mode-name op-name)
  (rtx-make 'operand mode-name op-name)
)
(define (rtx-operand? rtx) (eq? 'operand (rtx-name rtx)))
;; FIXME: This should just fetch rtx-arg1,
;; operand rtxes shouldn't have objects, that's what xop is for.
(define (rtx-operand-name rtx)
  (let ((operand (rtx-arg1 rtx)))
    (if (symbol? operand)
	operand
	(obj:name operand)))
)

;; Given an operand rtx, return the <operand> object.
;; RTX must be canonical rtl.
;; ISA-NAME-LIST is the list of ISAs to look the operand up in.
;;
;; NOTE: op:mode-name can be DFLT, which means use the mode of the type.
;; It is up to the caller to deal with it.

(define (rtx-operand-obj rtx isa-name-list)
  (let ((op (current-op-lookup (rtx-arg1 rtx) isa-name-list))
	(mode-name (rtx-mode rtx)))
    (assert op)
    (assert (not (eq? mode-name 'DFLT)))
    ;; Ensure requested mode is supported by the hardware.
    ;; rtx-canonicalize should have verified this already (I think).
    (assert (hw-mode-ok? (op:type op) mode-name (op:index op)))
    op)
)

(define (rtx-make-local mode-name local-name)
  (rtx-make 'local mode-name local-name)
)
(define (rtx-local? rtx) (eq? 'local (rtx-name rtx)))
(define (rtx-local-name rtx)
  (let ((local (rtx-arg1 rtx)))
    (if (symbol? local)
	local
	(obj:name local)))
)
(define (rtx-local-obj rtx)
  (let ((local (rtx-arg1 rtx)))
    (if (symbol? local)
	(error "can't use rtx-local-obj on local name")
	local))
)

(define (rtx-make-xop op)
  (rtx-make 'xop (op:mode-name op) op)
)
(define rtx-xop-obj rtx-arg1)

;(define (rtx-opspec? rtx) (eq? 'opspec (rtx-name rtx)))
;(define (rtx-opspec-mode rtx) (rtx-mode rtx))
;(define (rtx-opspec-hw-ref rtx) (list-ref rtx 5))
;(define (rtx-opspec-set-op-num! rtx num) (set-car! (cddddr rtx) num))

(define rtx-index-of-value rtx-arg1)

(define (rtx-make-set dest src) (rtx-make 'set dest src))
(define rtx-set-dest rtx-arg1)
(define rtx-set-src rtx-arg2)
(define (rtx-single-set? rtx) (memq (car rtx) '(set set-quiet)))

(define rtx-alu-op-mode rtx-mode)
(define (rtx-alu-op-arg rtx n) (list-ref rtx (+ n 3)))

(define (rtx-boolif-op-arg rtx n) (list-ref rtx (+ n 3)))

(define rtx-cmp-op-mode rtx-mode)
(define (rtx-cmp-op-arg rtx n) (list-ref rtx (+ n 3)))

(define rtx-number-list-values cdddr)

(define rtx-member-value rtx-arg1)
(define (rtx-member-set rtx) (list-ref rtx 4))

(define rtx-if-mode rtx-mode)
(define (rtx-if-test rtx) (rtx-arg1 rtx))
(define (rtx-if-then rtx) (list-ref rtx 4))
; If `else' clause is missing the result is #f.
(define (rtx-if-else rtx) (list-maybe-ref rtx 5))

(define (rtx-eq-attr-owner rtx) (list-ref rtx 3))
(define (rtx-eq-attr-attr rtx) (list-ref rtx 4))
(define (rtx-eq-attr-value rtx) (list-ref rtx 5))

(define (rtx-sequence-locals rtx) (cadddr rtx))
(define (rtx-sequence-exprs rtx) (cddddr rtx))

; Same as rtx-sequence-locals except return in assq'able form.
; ??? Sometimes I think it should have been (sequence ((name MODE)) ...)
; instead of (sequence ((MODE name)) ...) from the beginning, sigh.

(define (rtx-sequence-assq-locals rtx)
  (let ((locals (rtx-sequence-locals rtx)))
    (map (lambda (local)
	   (list (cadr local) (car local)))
	 locals))
)

(define (rtx-closure-isas rtx) (list-ref rtx 3))
(define (rtx-closure-env-stack rtx) (list-ref rtx 4))
(define (rtx-closure-expr rtx) (list-ref rtx 5))

; Return a semi-pretty string describing RTX.
; This is used by hw to include the index in the element's name.

(define (rtx-pretty-name rtx)
  (if (pair? rtx)
      (case (car rtx)
	((const) (number->string (rtx-const-value rtx)))
	((operand) (symbol->string (rtx-operand-name rtx)))
	((local) (symbol->string (rtx-local-name rtx)))
	((xop) (symbol->string (obj:name (rtx-xop-obj rtx))))
	(else
	 (if (null? (cdr rtx))
	     (rtx-pretty-name (car rtx))
	     (apply stringsym-append
		    (cons (rtx-pretty-name (car rtx))
			  (map (lambda (elm)
				 (string-append "-" (rtx-pretty-name elm)))
			       (cdr rtx)))))))
      (stringize rtx "-"))
)

; Various rtx utilities.

; Dump an rtx expression.

(define (rtx-dump rtx)
  (cond ((list? rtx) (map rtx-dump rtx))
	((object? rtx) (string/symbol-append "#<object "
					     (object-class-name rtx)
					     " "
					     (obj:name rtx)
					     ">"))
	(else rtx))
)

; Dump an expression to a string.

(define (rtx-strdump rtx)
  (with-output-to-string
    (lambda ()
      ;; Use write instead of display, we want strings displayed with quotes.
      (write (rtx-dump rtx))))
)

;; Return the pretty-printed from of RTX.

(define (rtx-pretty-strdump rtx)
  (with-output-to-string
    (lambda ()
      (pretty-print (rtx-dump rtx))))
)

; Return a boolean indicating if EXPR is known to be a compile-time constant.

(define (rtx-compile-time-constant? expr)
  (cond ((pair? expr)
	 (case (car expr)
	   ((const enum) #t)
	   (else #f)))
	((memq expr '(FALSE TRUE)) #t)
	(else #f))
)

; Return boolean indicating if EXPR has side-effects.
; FIXME: for now punt.

(define (rtx-side-effects? expr)
  #f
)

; Return a boolean indicating if EXPR is a "true" boolean value.
;
; ??? In RTL, #t is a synonym for (const 1).  This is confusing for Schemers,
; so maybe RTL's #t should be renamed to TRUE.

(define (rtx-true? expr)
  (cond ((pair? expr)
	 (case (car expr)
	   ((const enum) (!= (rtx-constant-value expr) 0))
	   (else #f)))
	((eq? expr 'TRUE) #t)
	(else #f))
)

; Return a boolean indicating if EXPR is a "false" boolean value.
;
; ??? In RTL, #f is a synonym for (const 0).  This is confusing for Schemers,
; so maybe RTL's #f should be renamed to FALSE.

(define (rtx-false? expr)
  (cond ((pair? expr)
	 (case (car expr)
	   ((const enum) (= (rtx-constant-value expr) 0))
	   (else #f)))
	((eq? expr 'FALSE) #t)
	(else #f))
)

; Return canonical boolean values.

(define (rtx-false) (rtx-make-const 'BI 0))
(define (rtx-true) (rtx-make-const 'BI 1))

; Convert EXPR to a canonical boolean if possible.

(define (rtx-canonical-bool expr)
  (cond ((rtx-side-effects? expr) expr)
	((rtx-false? expr) (rtx-false))
	((rtx-true? expr) (rtx-true))
	(else expr))
)

; Return rtx values for #f/#t.

(define (rtx-make-bool value)
  (if value
      (rtx-true)
      (rtx-false))
)

; Return #t if X is an rtl expression.
; e.g. '(add WI dr simm8);

(define (rtx? x)
  (->bool
   (and (pair? x) ; pair? -> cheap non-null-list?
	(or (hashq-ref /rtx-func-table (car x))
	    (hashq-ref /rtx-macro-table (car x)))))
)

; Instruction field support.

; Return list of ifield names refered to in EXPR.
; Assumes EXPR is more than just (ifield x).

(define (rtl-find-ifields expr)
  (let ((ifields nil))
    (letrec ((scan! (lambda (arg-list)
		      (for-each (lambda (arg)
				  (if (pair? arg)
				      (if (eq? (car arg) 'ifield)
					  (set! ifields
						(cons (rtx-ifield-name arg)
						      ifields))
					  (scan! (cdr arg)))))
				arg-list))))
      (scan! (cdr expr))
      (nub ifields identity)))
)

; Hardware rtx handlers.

; Subroutine of hw to compute the object's name.
; The name of the operand must include the index so that multiple copies
; of a hardware object (e.g. h-gr[0], h-gr[14]) can be distinguished.
; We make some attempt to make the name pretty as it appears in generated
; files.

(define (/rtx-hw-name hw hw-name index-arg)
  (cond ((hw-scalar? hw)
	 hw-name)
	((rtx? index-arg)
	 (symbolstr-append hw-name '- (rtx-pretty-name index-arg)))
	(else
	 (symbolstr-append hw-name ; (obj:name (op:type self))
			   '-
			   ; (obj:name (op:index self)))))
			   (stringize index-arg "-"))))
)

; Return the <operand> object described by
; HW-NAME/MODE-NAME/SELECTOR/INDEX-ARG.
;
; HW-NAME is the name of the hardware element.
; MODE-NAME is the name of the mode.
; INDEX-ARG is an rtx or number of the index.
; In the case of scalar hardware elements, pass 0 for INDEX-ARG.
; In the case of a vector of registers, INDEX-ARG is the vector index.
; SELECTOR is an rtx or number and is passed to HW-NAME to allow selection of a
; particular variant of the hardware.  It's kind of like an INDEX, but along
; an atypical axis.  An example is memory ASI's on Sparc.  Pass
; hw-selector-default if there is no selector.
; ESTATE is the current rtx evaluation state.
;
; *** The index is passed unevaluated because for parallel execution support
; *** a variable is created with a name based on the hardware element and
; *** index, and we want a reasonably simple and stable name.  We get this by
; *** stringize-ing it.
; *** ??? Though this needs to be redone anyway.
;
; ??? The specified hardware element must be either a scalar or a vector.
; Maybe in the future allow arrays although there's significant utility in
; allowing only at most a scalar index.

(define (/hw estate mode-name hw-name index-arg selector)
  ; Enforce some rules to keep things in line with the current design.
  (if (not (symbol? mode-name))
      (parse-error (estate-context estate) "invalid mode name" mode-name))
  (if (not (symbol? hw-name))
      (parse-error (estate-context estate) "invalid hw name" hw-name))
  (if (not (or (number? index-arg)
	       (rtx? index-arg)))
      (parse-error (estate-context estate) "invalid index" index-arg))
  (if (not (or (number? selector)
	       (rtx? selector)))
      (parse-error (estate-context estate) "invalid selector" selector))

  (let ((hw (current-hw-sem-lookup-1 hw-name)))
    (if (not hw)
	(parse-error (estate-context estate) "invalid hardware element" hw-name))

    (let* ((mode (if (eq? mode-name 'DFLT) (hw-mode hw) (mode:lookup mode-name)))
	   (hw-name-with-mode (symbol-append hw-name '- (obj:name mode)))
	   (index-mode (if (eq? hw-name 'h-memory) 'AI 'INT))
	   (result (if (hw-pc? hw)
		       (new <pc>)
		       (new <operand>)))) ; ??? lookup-for-new?

      (if (not mode)
	  (parse-error (estate-context estate) "invalid mode" mode-name))

      ; Record the selector.
      (elm-xset! result 'selector selector)

      ; Create the index object.
      (elm-xset! result 'index
		 (cond ((number? index-arg)
			(make <hw-index> 'anonymous 'constant UINT index-arg))
		       ((rtx? index-arg)
			; Make sure constant indices are recorded as such.
			(case (rtx-name index-arg)
			  ((const)
			   (make <hw-index> 'anonymous 'constant UINT
				 (rtx-constant-value index-arg)))
			  ((enum)
			   (make-enum-hw-index 'anonymous (rtx-enum-value index-arg)))
			  (else
			   (make <hw-index> 'anonymous 'rtx (mode:lookup index-mode)
				 (/rtx-closure-make estate index-mode index-arg)))))
		       (else (parse-error (estate-context estate)
					  "invalid index" index-arg))))

      (if (not (hw-mode-ok? hw (obj:name mode) (elm-xget result 'index)))
	  (parse-error (estate-context estate)
		       "invalid mode for hardware" mode-name))

      (elm-xset! result 'hw-name hw-name)
      (elm-xset! result 'type hw)
      (elm-xset! result 'mode-name mode-name)
      (elm-xset! result 'mode mode)

      (op:set-pretty-sem-name! result hw-name)

      ; The name of the operand must include the index so that multiple copies
      ; of a hardware object (e.g. h-gr[0], h-gr[14]) can be distinguished.
      (let ((name (if (hw-pc? hw)
		      'pc
		      (/rtx-hw-name hw hw-name-with-mode index-arg))))
	(send result 'set-name! name)
	(op:set-sem-name! result name))

      ; Empty comment and attribute.
      ; ??? Stick the arguments in the comment for debugging purposes?
      (send result 'set-comment! "")
      (send result 'set-atlist! atlist-empty)

      result))
)

; This is shorthand for (hw estate mode hw-name regno selector).
; ESTATE is the current rtx evaluation state.
; INDX-SEL is an optional register number and possible selector.
; The register number, if present, is (car indx-sel) and must be a number or
; unevaluated canonical RTX expression.
; The selector, if present, is (cadr indx-sel) and must be a number or
; unevaluated canonical RTX expression.
; ??? A register selector isn't supported yet.  It's just an idea that's
; been put down on paper for future reference.

(define (reg estate mode-name hw-name . indx-sel)
  (s-hw estate mode-name hw-name
	(if (pair? indx-sel) (car indx-sel) 0)
	(if (and (pair? indx-sel) (pair? (cdr indx-sel)))
	    (cadr indx-sel)
	    hw-selector-default))
)

; This is shorthand for (hw estate mode-name h-memory addr selector).
; ADDR must be an unevaluated canonical RTX expression.
; If present (car sel) must be a number or unevaluated canonical
; RTX expression.

(define (mem estate mode-name addr . sel)
  (s-hw estate mode-name 'h-memory addr
	(if (pair? sel) (car sel) hw-selector-default))
)

; For the rtx nodes to use.

(define s-hw /hw)

; The program counter.
; When this code is loaded, global `pc' is nil, it hasn't been set to the
; pc operand yet (see operand-init!).  We can't use `pc' inside the drn as the
; value is itself.  So we use s-pc.  rtl-finish! must be called after
; operand-init!.

(define s-pc pc)

; Conditional execution.

; `if' in RTL has a result, like ?: in C.
; We support both: one with a result (non VOID mode), and one without (VOID mode).
; The non-VOID case must have an else part.
; MODE is the mode of the result, not the comparison.
; The comparison is expected to return a zero/non-zero value.
; ??? Perhaps this should be a syntax-expr.  Later.

(define (e-if estate mode cond then . else)
  (if (> (length else) 1)
      (estate-error estate "if: too many elements in `else' part" else))
  (if (null? else)
      (if cond then)
      (if cond then (car else)))
)

; Subroutines.
; ??? Not sure this should live here.

(define (/subr-read context . arg-list)
  #f
)

(define define-subr
  (lambda arg-list
    (let ((s (apply /subr-read (cons "define-subr" arg-list))))
      (if s
	  (current-subr-add! s))
      s))
)

; Misc. utilities.

; The argument to drn,drmn,drsn must be Scheme code (or a fixed subset
; thereof).  .str/.sym are used in pmacros so it makes sense to include them
; in the subset.
; FIXME: Huh?
(define .str string-append)
(define .sym symbol-append)

; Given (expr1 expr2 expr3 expr4), for example,
; return (fn (fn (fn expr1 expr2) expr3) expr4).

(define (rtx-combine fn exprs)
  (assert (not (null? exprs)))
  (letrec ((-rtx-combine (lambda (fn exprs result)
			   (if (null? exprs)
			       result
			       (-rtx-combine fn
					     (cdr exprs)
					     (rtx-make fn
						       result
						       (car exprs)))))))
    (-rtx-combine fn (cdr exprs) (car exprs)))
)

; Called before a .cpu file is read in.

(define (rtl-init!)
  (set! /rtx-func-table (make-hash-table 127))
  (set! /rtx-macro-table (make-hash-table 127))
  (set! /rtx-num-next 0)
  (def-rtx-funcs)

  ; Sanity checks.
  ; All rtx take options for the first arg and a mode for the second.
  (for-each (lambda (rtx-name)
	      (let ((rtx (rtx-lookup rtx-name)))
		(if rtx
		    (begin
		      (if (null? (rtx-arg-types rtx))
			  #f ; pc is the one exception, blech
			  (begin
			    (assert (eq? (car (rtx-arg-types rtx)) 'OPTIONS))
			    (assert (memq (cadr (rtx-arg-types rtx)) /rtx-valid-mode-types)))))
		    #f) ; else a macro
		))
	    /rtx-name-list)

  (reader-add-command! 'define-subr
		       "\
Define an rtx subroutine, name/value pair list version.
"
		       nil 'arg-list define-subr)

  *UNSPECIFIED*
)

;; Install builtins

(define (rtl-builtin!)
  (rtx-init-traversal-tables!)

  *UNSPECIFIED*
)

; Called after cpu files are loaded to add misc. remaining entries to the
; rtx handler table for use during evaluation.
; rtl-finish! must be done before ifmt-compute!, the latter will
; construct hardware objects which is done by rtx evaluation.

(define (rtl-finish!)
  (logit 2 "Building rtx operand table ...\n")

  ; Update s-pc, must be called after operand-init!.
  (set! s-pc pc)

  ; Initialize the operand hash table.
  (set! /rtx-operand-table (make-hash-table 127))

  ; Add the operands to the eval symbol table.
  (for-each (lambda (op)
	      (hashq-set! /rtx-operand-table (obj:name op) op))
	    (current-op-list))

  ; Add ifields to the eval symbol table.
  (for-each (lambda (f)
	      (hashq-set! /rtx-operand-table (obj:name f) f))
	    (non-derived-ifields (current-ifld-list)))

  *UNSPECIFIED*
)
