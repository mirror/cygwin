; Basic RTL support.
; Copyright (C) 2000 Red Hat, Inc.
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
		name

		; argument list
		args

		; types of each argument, as symbols
		; This is #f for macros.
		; Possible values:
		; OPTIONS - optional list of :-prefixed options.
		; ANYMODE - any mode
		; INTMODE - any integer mode
		; FLOATMODE - any floating point mode
		; NUMMODE - any numeric mode
		; EXPLNUMMODE - explicit numeric mode, can't be DFLT or VOID
		; NONVOIDMODE - can't be `VOID'
		; VOIDMODE - must be `VOID'
		; DFLTMODE - must be `DFLT', used when any mode is inappropriate
		; RTX - any rtx
		; SETRTX - any rtx allowed to be `set'
		; TESTRTX - the test of an `if'
		; CONDRTX - a cond expression ((test) rtx ... rtx)
		; CASERTX - a case expression ((symbol .. symbol) rtx ... rtx)
		; LOCALS - the locals list of a sequence
		; ENV - environment stack
		; ATTRS - attribute list
		; SYMBOL - operand must be a symbol
		; STRING - operand must be a string
		; NUMBER - operand must be a number
		; SYMORNUM - operand must be a symbol or number
		; OBJECT - operand is an object
		arg-types

		; required mode of each argument
		; This is #f for macros.
		; Possible values include any mode name and:
		; ANY - any mode
		; NA - not applicable
		; OP0 - mode is specified in operand 0
		;       unless it is DFLT in which case use the default mode
		;       of the operand
		; MATCH1 - must match mode of operand 1
		;          which will have OP0 for its mode spec
		; MATCH2 - must match mode of operand 2
		;          which will have OP0 for its mode spec
		; <MODE-NAME> - must match specified mode
		arg-modes

		; The class of rtx.
		; This is #f for macros.
		; ARG - operand, local, const
		; SET - set
		; UNARY - not, inv, etc.
		; BINARY - add, sub, etc.
		; TRINARY - addc, subc, etc.
		; IF - if
		; COND - cond, case
		; SEQUENCE - sequence, parallel
		; UNSPEC - c-call
		; MISC - everything else
		class

		; A symbol indicating the flavour of rtx node this is.
		; function - normal function
		; syntax - don't pre-eval arguments
		; operand - result is an operand
		; macro - converts one rtx expression to another
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
  (name args arg-types arg-modes class style evaluator num)
)

(define (rtx-class-arg? rtx) (eq? (rtx-class rtx) 'ARG))
(define (rtx-class-set? rtx) (eq? (rtx-class rtx) 'SET)) 
(define (rtx-class-unary? rtx) (eq? (rtx-class rtx) 'UNARY))
(define (rtx-class-binary? rtx) (eq? (rtx-class rtx) 'BINARY))
(define (rtx-class-trinary? rtx) (eq? (rtx-class rtx) 'TRINARY))
(define (rtx-class-if? rtx) (eq? (rtx-class rtx) 'IF))
(define (rtx-class-cond? rtx) (eq? (rtx-class rtx) 'COND))
(define (rtx-class-sequence? rtx) (eq? (rtx-class rtx) 'SEQUENCE))
(define (rtx-class-unspec? rtx) (eq? (rtx-class rtx) 'UNSPEC))
(define (rtx-class-misc? rtx) (eq? (rtx-class rtx) 'MISC))

(define (rtx-style-function? rtx) (eq? (rtx-style rtx) 'function))
(define (rtx-style-syntax? rtx) (eq? (rtx-style rtx) 'syntax))
(define (rtx-style-operand? rtx) (eq? (rtx-style rtx) 'operand))
(define (rtx-style-macro? rtx) (eq? (rtx-style rtx) 'macro))

; Add standard `get-name' method since this isn't a subclass of <ident>.

(method-make! <rtx-func> 'get-name (lambda (self) (elm-get self 'name)))

; List of valid values for arg-types, not including mode names.

(define -rtx-valid-types
  '(OPTIONS
    ANYMODE INTMODE FLOATMODE NUMMODE EXPLNUMMODE NONVOIDMODE VOIDMODE DFLTMODE
    RTX TESTRTX CONDRTX CASERTX
    LOCALS ENV ATTRS SYMBOL STRING NUMBER SYMORNUM OBJECT)
)

; List of valid mode matchers, excluding mode names.

(define -rtx-valid-matches
  '(ANY NA OP0 MATCH1 MATCH2)
)

; List of all defined rtx names.  This can be map'd over without having
; to know the innards of -rtx-func-table (which is a hash table).

(define -rtx-name-list nil)
(define (rtx-name-list) -rtx-name-list)

; Table of rtx function objects.
; This is set in rtl-init!.

(define -rtx-func-table nil)

; Look up the <rtx-func> object for RTX-KIND.
; Returns the object or #f if not found.
; RTX-KIND may already be an <rtx-func> object.  FIXME: delete?

(define (rtx-lookup rtx-kind)
  (cond ((symbol? rtx-kind)
	 (hashq-ref -rtx-func-table rtx-kind))
	((rtx-func? rtx-kind)
	 rtx-kind)
	(else #f))
)

; Table of rtx macro objects.
; This is set in rtl-init!.

(define -rtx-macro-table nil)

; Table of operands, modes, and other non-functional aspects of RTL.
; This is defined in rtl-finish!, after all operands have been read in.

(define -rtx-operand-table nil)

; Number of next rtx to be defined.

(define -rtx-num-next #f)

; Return the number of rtx's.

(define (rtx-max-num)
  -rtx-num-next
)

; Define Rtx Node
;
; Add an entry to the rtx function table.
; NAME-ARGS is a list of the operation name and arguments.
; The mode of the result must be the first element in `args' (if there are
; any arguments).
; ARG-TYPES is a list of argument types (-rtx-valid-types).
; ARG-MODES is a list of mode matchers (-rtx-valid-matches).
; ACTION is a list of Scheme expressions to perform the operation.
;
; ??? Note that we can support variables.  Not sure it should be done.

(define (def-rtx-node name-args arg-types arg-modes class action)
  (let ((name (car name-args))
	(args (cdr name-args)))
    (let ((rtx (make <rtx-func> name args
		     arg-types arg-modes
		     class
		     'function
		     (if action
			 (eval (list 'lambda (cons '*estate* args) action))
			 #f)
		     -rtx-num-next)))
      ; Add it to the table of rtx handlers.
      (hashq-set! -rtx-func-table name rtx)
      (set! -rtx-num-next (+ -rtx-num-next 1))
      (set! -rtx-name-list (cons name -rtx-name-list))
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

(define (def-rtx-syntax-node name-args arg-types arg-modes class action)
  (let ((name (car name-args))
	(args (cdr name-args)))
    (let ((rtx (make <rtx-func> name args
		     arg-types arg-modes
		     class
		     'syntax
		     (if action
			 (eval (list 'lambda (cons '*estate* args) action))
			 #f)
		     -rtx-num-next)))
      ; Add it to the table of rtx handlers.
      (hashq-set! -rtx-func-table name rtx)
      (set! -rtx-num-next (+ -rtx-num-next 1))
      (set! -rtx-name-list (cons name -rtx-name-list))
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

(define (def-rtx-operand-node name-args arg-types arg-modes class action)
  ; Operand nodes must specify an action.
  (assert action)
  (let ((name (car name-args))
	(args (cdr name-args)))
    (let ((rtx (make <rtx-func> name args
		     arg-types arg-modes
		     class
		     'operand
		     (eval (list 'lambda (cons '*estate* args) action))
		     -rtx-num-next)))
      ; Add it to the table of rtx handlers.
      (hashq-set! -rtx-func-table name rtx)
      (set! -rtx-num-next (+ -rtx-num-next 1))
      (set! -rtx-name-list (cons name -rtx-name-list))
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
    (let ((rtx (make <rtx-func> name args #f #f
		     #f ; class
		     'macro
		     (eval (list 'lambda args action))
		     -rtx-num-next)))
      ; Add it to the table of rtx macros.
      (hashq-set! -rtx-macro-table name rtx)
      (set! -rtx-num-next (+ -rtx-num-next 1))
      (set! -rtx-name-list (cons name -rtx-name-list))
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

(define (-rtx-macro-lookup macro-name)
  (hashq-ref -rtx-macro-table macro-name)
)

; Lookup (car exp) and return the macro's lambda if it is one or #f.

(define (-rtx-macro-check exp fn-getter)
  (let ((macro (hashq-ref -rtx-macro-table (car exp))))
    (if macro
	(fn-getter macro)
	#f))
)

; Expand a list.

(define (-rtx-macro-expand-list exp fn-getter)
  (let ((macro (-rtx-macro-check exp fn-getter)))
    (if macro
	(apply macro (map (lambda (x) (-rtx-macro-expand x fn-getter))
			  (cdr exp)))
	(map (lambda (x) (-rtx-macro-expand x fn-getter))
	     exp)))
)

; Main entry point to expand a macro invocation.

(define (-rtx-macro-expand exp fn-getter)
  (if (pair? exp) ; pair? -> cheap (and (not (null? exp)) (list? exp))
      (let ((result (-rtx-macro-expand-list exp fn-getter)))
	; If the result is a new macro invocation, recurse.
	(if (pair? result)
	    (let ((macro (-rtx-macro-check result fn-getter)))
	      (if macro
		  (-rtx-macro-expand (apply macro (cdr result)) fn-getter)
		  result))
	    result))
      exp)
)

; Publically accessible version.

(define rtx-macro-expand -rtx-macro-expand)

; RTX canonicalization.
; ??? wip

; Subroutine of rtx-canonicalize.
; Return canonical form of rtx expression EXPR.
; CONTEXT is a <context> object or #f if there is none.
; It is used for error message.
; RTX-OBJ is the <rtx-func> object of (car expr).

(define (-rtx-canonicalize-expr context rtx-obj expr)
  #f
)

; Return canonical form of EXPR.
; CONTEXT is a <context> object or #f if there is none.
; It is used for error message.
;
; Does:
; - operand shortcuts expanded
;   - numbers -> (const number)
;   - operand-name -> (operand operand-name)
;   - ifield-name -> (ifield ifield-name)
; - no options -> null option list
; - absent result mode of those that require a mode -> DFLT
; - rtx macros are expanded
;
; EXPR is returned in source form.  We could speed up future processing by
; transforming it into a more compiled form, but that makes debugging more
; difficult, so for now we don't.

(define (rtx-canonicalize context expr)
  ; FIXME: wip
  (cond ((integer? expr)
	 (rtx-make-const 'INT expr))
	((symbol? expr)
	 (let ((op (current-op-lookup expr)))
	   (if op
	       (rtx-make-operand expr)
	       (context-error context "can't canonicalize" expr))))
	((pair? expr)
	 expr)
	(else
	 (context-error context "can't canonicalize" expr)))
)

; RTX mode support.

; Get implied mode of X, either an operand expression, sequence temp, or
; a hardware reference expression.
; The result is the name of the mode.

(define (rtx-lvalue-mode-name estate x)
  (assert (rtx? x))
  (case (car x)
;    ((operand) (obj:name (op:mode (current-op-lookup (cadr x)))))
    ((xop) (obj:name (send (rtx-xop-obj x) 'get-mode)))
;    ((opspec)
;     (if (eq? (rtx-opspec-mode x) 'VOID)
;	 (rtx-lvalue-mode-name estate (rtx-opspec-hw-ref x))
;	 (rtx-opspec-mode x)))
;    ((reg mem) (cadr x))
;    ((local) (obj:name (rtx-temp-mode (rtx-temp-lookup (estate-env estate)
;						       (cadr x)))))
    (else
     (error "rtx-lvalue-mode-name: not an operand or hardware reference:" x)))
)

; Lookup the mode to use for semantic operations (unsigned modes aren't
; allowed since we don't have ANDUSI, etc.).
; ??? I have actually implemented both ways (full use of unsigned modes
; and mostly hidden use of unsigned modes).  Neither makes me real
; comfortable, though I liked bringing unsigned modes out into the open
; even if it doubled the number of semantic operations.

(define (-rtx-sem-mode m) (or (mode:sem-mode m) m))

; MODE is a mode name or <mode> object.
(define (-rtx-lazy-sem-mode mode) (-rtx-sem-mode (mode:lookup mode)))

; Return the mode of object OBJ.

(define (-rtx-obj-mode obj) (send obj 'get-mode))

; Return a boolean indicating of modes M1,M2 are compatible.

(define (-rtx-mode-compatible? m1 m2)
  (let ((mode1 (-rtx-lazy-sem-mode m1))
	(mode2 (-rtx-lazy-sem-mode m2)))
    ;(eq? (obj:name mode1) (obj:name mode2)))
    ; ??? This is more permissive than is perhaps proper.
    (mode-compatible? 'sameclass mode1 mode2))
)

; Environments (sequences with local variables).

; Temporaries are created within a sequence.
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
(define (rtx-env-var-list env) env)
(define (rtx-env-empty-stack) nil)
(define (rtx-env-init-stack1 vars-alist)
  (if (null? vars-alist)
      nil
      (cons (rtx-env-make vars-alist) nil))
)
(define (rtx-env-empty? env) (null? env))

; Create an initial environment.
; VAR-LIST is a list of (name <mode> value) elements.

(define (rtx-env-make var-list)
  ; Convert VAR-LIST to an associative list of <rtx-temp> objects.
  (map (lambda (var-spec)
	 (cons (car var-spec)
	       (make <rtx-temp>
		 (car var-spec) (cadr var-spec) (caddr var-spec))))
       var-list)
)

; Create an initial environment with local variables.
; VAR-LIST is a list of (mode-name name) elements (the argument to `sequence').

(define (rtx-env-make-locals var-list)
  ; Convert VAR-LIST to an associative list of <rtx-temp> objects.
  (map (lambda (var-spec)
	 (cons (cadr var-spec)
	       (make <rtx-temp>
		 (cadr var-spec) (mode:lookup (car var-spec)) #f)))
       var-list)
)

; Push environment ENV onto the front of environment stack ENV-STACK,
; returning a new object.  ENV-STACK is not modified.

(define (rtx-env-push env-stack env)
  (cons env env-stack)
)

(define (rtx-temp-lookup env name)
  ;(display "looking up:") (display name) (newline)
  (let loop ((stack (rtx-env-var-list env)))
    (if (null? stack)
	#f
	(let ((temp (assq-ref (car stack) name)))
	  (if temp
	      temp
	      (loop (cdr stack))))))
)

; Create a "closure" of EXPR using the current temp stack.

(define (-rtx-closure-make estate expr)
  (rtx-make 'closure expr (estate-env estate))
)

(define (rtx-env-dump env)
  (let ((stack env))
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
  (cons kind (-rtx-munge-mode&options args))
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
    ((enum) (enum-lookup-val (rtx-enum-value rtx)))
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

(define (rtx-make-ifield ifield-name) (rtx-make 'ifield ifield-name))
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
	(current-ifield-lookup ifield)
	ifield))
)

(define (rtx-make-operand op-name) (rtx-make 'operand op-name))
(define (rtx-operand? rtx) (eq? 'operand (rtx-name rtx)))
(define (rtx-operand-name rtx)
  (let ((operand (rtx-arg1 rtx)))
    (if (symbol? operand)
	operand
	(obj:name operand)))
)
(define (rtx-operand-obj rtx)
  (let ((operand (rtx-arg1 rtx)))
    (if (symbol? operand)
	(current-op-lookup operand)
	operand))
)

(define (rtx-make-local local-name) (rtx-make 'local local-name))
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

(define rtx-xop-obj rtx-arg1)

;(define (rtx-opspec? rtx) (eq? 'opspec (rtx-name rtx)))
;(define (rtx-opspec-mode rtx) (rtx-mode rtx))
;(define (rtx-opspec-hw-ref rtx) (list-ref rtx 5))
;(define (rtx-opspec-set-op-num! rtx num) (set-car! (cddddr rtx) num))

(define rtx-index-of-value rtx-arg1)

(define (rtx-make-set dest src) (rtx-make 'set dest src))
(define rtx-set-dest rtx-arg1)
(define rtx-set-src rtx-arg2)
(define (rtx-single-set? rtx) (eq? (car rtx) 'set))

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

(define (rtx-sequence-assq-locals rtx)
  (let ((locals (rtx-sequence-locals rtx)))
    (map (lambda (local)
	   (list (cadr local) (car local)))
	 locals))
)

; Return a semi-pretty symbol describing RTX.
; This is used by hw to include the index in the element's name.

(define (rtx-pretty-name rtx)
  (if (pair? rtx)
      (case (car rtx)
	((const) (number->string (rtx-const-value rtx)))
	((operand) (obj:name (rtx-operand-obj rtx)))
	((local) (rtx-local-name rtx))
	((xop) (obj:name (rtx-xop-obj rtx)))
	(else
	 (if (null? (cdr rtx))
	     (car rtx)
	     (apply string-append
		    (cons (car rtx)
			  (map (lambda (elm)
				 (string-append "-" (rtx-pretty-name elm)))
			       (cdr rtx)))))))
      (stringize rtx "-"))
)

; RTL expression traversal support.
; Traversal (and compilation) involves validating the source form and
; converting it to internal form.
; ??? At present the internal form is also the source form (easier debugging).

; Set to #t to debug rtx traversal.

(define -rtx-traverse-debug? #f)

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
; (lambda (rtx-obj expr mode parent-expr op-pos tstate appstuff) ...).
; If the result of EXPR-FN is a lambda, it is applied to
; (cons TSTATE (cdr EXPR)).  TSTATE is prepended to the arguments.
; For syntax expressions if the result of EXPR-FN is #f, the operands are
; processed using the builtin traverser.
; So to repeat: EXPR-FN can process the expression, and if its result is a
; lambda then it also processes the expression.  The arguments to EXPR-FN
; are (rtx-obj expr mode parent-expr op-pos tstate appstuff).  The format
; of the result of EXPR-FN are (cons TSTATE (cdr EXPR)).
; The reason for the duality is that when trying to understand EXPR (e.g. when
; computing the insn format) EXPR-FN processes the expression itself, and
; when evaluating EXPR it's the result of EXPR-FN that computes the value.
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
; SET? is a boolean indicating if the current expression is an operand being
; set.
;
; OWNER is the owner of the expression or #f if there is none.
; Typically it is an <insn> object.
;
; KNOWN is an alist of known values.  This is used by rtx-simplify.
; Each element is (name . value) where
; NAME is either an ifield or operand name (in the future it might be a
; sequence local name), and
; VALUE is either (const mode value) or (numlist mode value1 value2 ...).
;
; DEPTH is the current traversal depth.

(define (tstate-make context owner expr-fn env cond? set? known depth)
  (vector context owner expr-fn env cond? set? known depth)
)

(define (tstate-context state)             (vector-ref state 0))
(define (tstate-set-context! state newval) (vector-set! state 0 newval))
(define (tstate-owner state)               (vector-ref state 1))
(define (tstate-set-owner! state newval)   (vector-set! state 1 newval))
(define (tstate-expr-fn state)             (vector-ref state 2))
(define (tstate-set-expr-fn! state newval) (vector-set! state 2 newval))
(define (tstate-env state)                 (vector-ref state 3))
(define (tstate-set-env! state newval)     (vector-set! state 3 newval))
(define (tstate-cond? state)               (vector-ref state 4))
(define (tstate-set-cond?! state newval)   (vector-set! state 4 newval))
(define (tstate-set? state)                (vector-ref state 5))
(define (tstate-set-set?! state newval)    (vector-set! state 5 newval))
(define (tstate-known state)               (vector-ref state 6))
(define (tstate-set-known! state newval)   (vector-set! state 6 newval))
(define (tstate-depth state)               (vector-ref state 7))
(define (tstate-set-depth! state newval)   (vector-set! state 7 newval))

; Create a copy of STATE.

(define (tstate-copy state)
  ; A fast vector-copy would be nice, but this is simple and portable.
  (list->vector (vector->list state))
)

; Create a copy of STATE with a new environment ENV.

(define (tstate-new-env state env)
  (let ((result (tstate-copy state)))
    (tstate-set-env! result env)
    result)
)

; Create a copy of STATE with environment ENV pushed onto the existing
; environment list.
; There's no routine to pop the environment list as there's no current
; need for it: we make a copy of the state when we push.

(define (tstate-push-env state env)
  (let ((result (tstate-copy state)))
    (tstate-set-env! result (cons env (tstate-env result)))
    result)
)

; Create a copy of STATE with a new COND? value.

(define (tstate-new-cond? state cond?)
  (let ((result (tstate-copy state)))
    (tstate-set-cond?! result cond?)
    result)
)

; Create a copy of STATE with a new SET? value.

(define (tstate-new-set? state set?)
  (let ((result (tstate-copy state)))
    (tstate-set-set?! result set?)
    result)
)

; Lookup NAME in the known value table.  Returns the value or #f if not found.

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

; Traversal/compilation support.

; Return a boolean indicating if X is a mode.

(define (-rtx-any-mode? x)
  (->bool (mode:lookup x))
)

; Return a boolean indicating if X is a symbol or rtx.

(define (-rtx-symornum? x)
  (or (symbol? x) (number? x))
)

; Traverse a list of rtx's.

(define (-rtx-traverse-rtx-list rtx-list mode expr op-num tstate appstuff)
  (map (lambda (rtx)
	 ; ??? Shouldn't OP-NUM change for each element?
	 (-rtx-traverse rtx 'RTX mode expr op-num tstate appstuff))
       rtx-list)
)

; Cover-fn to context-error for signalling an error during rtx traversal.

(define (-rtx-traverse-error tstate errmsg expr op-num)
;  (parse-error context (string-append errmsg ", operand number "
;				      (number->string op-num))
;	       (rtx-dump expr))
  (context-error (tstate-context tstate)
		 (string-append errmsg ", operand #" (number->string op-num))
		 (rtx-strdump expr))
)

; Rtx traversers.
; These are defined as individual functions that are then built into a table
; so that we can use Hobbit's "fastcall" support.
;
; The result is either a pair of the parsed VAL and new TSTATE,
; or #f meaning there is no change (saves lots of unnecessarying cons'ing).

(define (-rtx-traverse-options val mode expr op-num tstate appstuff)
  #f
)

(define (-rtx-traverse-anymode val mode expr op-num tstate appstuff)
  (let ((val-obj (mode:lookup val)))
    (if (not val-obj)
	(-rtx-traverse-error tstate "expecting a mode"
			     expr op-num))
    #f)
)

(define (-rtx-traverse-intmode val mode expr op-num tstate appstuff)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(INT UINT))
		 (eq? val 'DFLT)))
	#f
	(-rtx-traverse-error tstate "expecting an integer mode"
			     expr op-num)))
)

(define (-rtx-traverse-floatmode val mode expr op-num tstate appstuff)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(FLOAT))
		 (eq? val 'DFLT)))
	#f
	(-rtx-traverse-error tstate "expecting a float mode"
			     expr op-num)))
)

(define (-rtx-traverse-nummode val mode expr op-num tstate appstuff)
  (let ((val-obj (mode:lookup val)))
    (if (and val-obj
	     (or (memq (mode:class val-obj) '(INT UINT FLOAT))
		 (eq? val 'DFLT)))
	#f
	(-rtx-traverse-error tstate "expecting a numeric mode"
			     expr op-num)))
)

(define (-rtx-traverse-explnummode val mode expr op-num tstate appstuff)
  (let ((val-obj (mode:lookup val)))
    (if (not val-obj)
	(-rtx-traverse-error tstate "expecting a mode"
			     expr op-num))
    (if (memq val '(DFLT VOID))
	(-rtx-traverse-error tstate "DFLT and VOID not allowed here"
			     expr op-num))
    #f)
)

(define (-rtx-traverse-nonvoidmode val mode expr op-num tstate appstuff)
  (if (eq? val 'VOID)
      (-rtx-traverse-error tstate "mode can't be VOID"
			   expr op-num))
  #f
)

(define (-rtx-traverse-voidmode val mode expr op-num tstate appstuff)
  (if (memq val '(DFLT VOID))
      #f
      (-rtx-traverse-error tstate "expecting mode VOID"
			   expr op-num))
)

(define (-rtx-traverse-dfltmode val mode expr op-num tstate appstuff)
  (if (eq? val 'DFLT)
      #f
      (-rtx-traverse-error tstate "expecting mode DFLT"
			   expr op-num))
)

(define (-rtx-traverse-rtx val mode expr op-num tstate appstuff)
; Commented out 'cus it doesn't quite work yet.
; (if (not (rtx? val))
;     (-rtx-traverse-error tstate "expecting an rtx"
;			   expr op-num))
  (cons (-rtx-traverse val 'RTX mode expr op-num tstate appstuff)
	tstate)
)

(define (-rtx-traverse-setrtx val mode expr op-num tstate appstuff)
  ; FIXME: Still need to turn it off for sub-exprs.
  ; e.g. (mem (reg ...))
; Commented out 'cus it doesn't quite work yet.
; (if (not (rtx? val))
;     (-rtx-traverse-error tstate "expecting an rtx"
;				  expr op-num))
  (cons (-rtx-traverse val 'SETRTX mode expr op-num
		       (tstate-new-set? tstate #t)
		       appstuff)
	tstate)
)

; This is the test of an `if'.

(define (-rtx-traverse-testrtx val mode expr op-num tstate appstuff)
; Commented out 'cus it doesn't quite work yet.
; (if (not (rtx? val))
;     (-rtx-traverse-error tstate "expecting an rtx"
;				  expr op-num))
  (cons (-rtx-traverse val 'RTX mode expr op-num tstate appstuff)
	(tstate-new-cond?
	 tstate
	 (not (rtx-compile-time-constant? val))))
)

(define (-rtx-traverse-condrtx val mode expr op-num tstate appstuff)
  (if (not (pair? val))
      (-rtx-traverse-error tstate "expecting an expression"
			   expr op-num))
  (if (eq? (car val) 'else)
      (begin
	(if (!= (+ op-num 2) (length expr))
	    (-rtx-traverse-error tstate
				 "`else' clause not last"
				 expr op-num))
	(cons (cons 'else
		    (-rtx-traverse-rtx-list
		     (cdr val) mode expr op-num
		     (tstate-new-cond? tstate #t)
		     appstuff))
	      (tstate-new-cond? tstate #t)))
      (cons (cons
	     ; ??? Entries after the first are conditional.
	     (-rtx-traverse (car val) 'RTX 'ANY expr op-num tstate appstuff)
	     (-rtx-traverse-rtx-list
	      (cdr val) mode expr op-num
	      (tstate-new-cond? tstate #t)
	      appstuff))
	    (tstate-new-cond? tstate #t)))
)

(define (-rtx-traverse-casertx val mode expr op-num tstate appstuff)
  (if (or (not (list? val))
	  (< (length val) 2))
      (-rtx-traverse-error tstate
			   "invalid `case' expression"
			   expr op-num))
  ; car is either 'else or list of symbols/numbers
  (if (not (or (eq? (car val) 'else)
	       (and (list? (car val))
		    (not (null? (car val)))
		    (all-true? (map -rtx-symornum?
				    (car val))))))
      (-rtx-traverse-error tstate
			   "invalid `case' choice"
			   expr op-num))
  (if (and (eq? (car val) 'else)
	   (!= (+ op-num 2) (length expr)))
      (-rtx-traverse-error tstate "`else' clause not last"
			   expr op-num))
  (cons (cons (car val)
	      (-rtx-traverse-rtx-list
	       (cdr val) mode expr op-num
	       (tstate-new-cond? tstate #t)
	       appstuff))
	(tstate-new-cond? tstate #t))
)

(define (-rtx-traverse-locals val mode expr op-num tstate appstuff)
  (if (not (list? val))
      (-rtx-traverse-error tstate "bad locals list"
			   expr op-num))
  (for-each (lambda (var)
	      (if (or (not (list? var))
		      (!= (length var) 2)
		      (not (-rtx-any-mode? (car var)))
		      (not (symbol? (cadr var))))
		  (-rtx-traverse-error tstate
				       "bad locals list"
				       expr op-num)))
	    val)
  (let ((env (rtx-env-make-locals val)))
    (cons val (tstate-push-env tstate env)))
)

(define (-rtx-traverse-env val mode expr op-num tstate appstuff)
  ; VAL is an environment stack.
  (if (not (list? val))
      (-rtx-traverse-error tstate "environment not a list"
			   expr op-num))
  (cons val (tstate-new-env tstate val))
)

(define (-rtx-traverse-attrs val mode expr op-num tstate appstuff)
;  (cons val ; (atlist-source-form (atlist-parse val "" "with-attr"))
;	tstate)
  #f
)

(define (-rtx-traverse-symbol val mode expr op-num tstate appstuff)
  (if (not (symbol? val))
      (-rtx-traverse-error tstate "expecting a symbol"
			   expr op-num))
  #f
)

(define (-rtx-traverse-string val mode expr op-num tstate appstuff)
  (if (not (string? val))
      (-rtx-traverse-error tstate "expecting a string"
			   expr op-num))
  #f
)

(define (-rtx-traverse-number val mode expr op-num tstate appstuff)
  (if (not (number? val))
      (-rtx-traverse-error tstate "expecting a number"
			   expr op-num))
  #f
)

(define (-rtx-traverse-symornum val mode expr op-num tstate appstuff)
  (if (not (or (symbol? val) (number? val)))
      (-rtx-traverse-error tstate
			   "expecting a symbol or number"
			   expr op-num))
  #f
)

(define (-rtx-traverse-object val mode expr op-num tstate appstuff)
  #f
)

; Table of rtx traversers.
; This is a vector of size rtx-max-num.
; Each entry is a list of (arg-type-name . traverser) elements
; for rtx-arg-types.

(define -rtx-traverser-table #f)

; Return a hash table of standard operand traversers.
; The result of each traverser is a pair of the compiled form of `val' and
; a possibly new traversal state or #f if there is no change.

(define (-rtx-make-traverser-table)
  (let ((hash-tab (make-hash-table 31))
	(traversers
	 (list
	  ; /fastcall-make is recognized by Hobbit and handled specially.
	  ; When not using Hobbit it is a macro that returns its argument.
	  (cons 'OPTIONS (/fastcall-make -rtx-traverse-options))
	  (cons 'ANYMODE (/fastcall-make -rtx-traverse-anymode))
	  (cons 'INTMODE (/fastcall-make -rtx-traverse-intmode))
	  (cons 'FLOATMODE (/fastcall-make -rtx-traverse-floatmode))
	  (cons 'NUMMODE (/fastcall-make -rtx-traverse-nummode))
	  (cons 'EXPLNUMMODE (/fastcall-make -rtx-traverse-explnummode))
	  (cons 'NONVOIDFLTODE (/fastcall-make -rtx-traverse-nonvoidmode))
	  (cons 'VOIDFLTODE (/fastcall-make -rtx-traverse-voidmode))
	  (cons 'DFLTMODE (/fastcall-make -rtx-traverse-dfltmode))
	  (cons 'RTX (/fastcall-make -rtx-traverse-rtx))
	  (cons 'SETRTX (/fastcall-make -rtx-traverse-setrtx))
	  (cons 'TESTRTX (/fastcall-make -rtx-traverse-testrtx))
	  (cons 'CONDRTX (/fastcall-make -rtx-traverse-condrtx))
	  (cons 'CASERTX (/fastcall-make -rtx-traverse-casertx))
	  (cons 'LOCALS (/fastcall-make -rtx-traverse-locals))
	  (cons 'ENV (/fastcall-make -rtx-traverse-env))
	  (cons 'ATTRS (/fastcall-make -rtx-traverse-attrs))
	  (cons 'SYMBOL (/fastcall-make -rtx-traverse-symbol))
	  (cons 'STRING (/fastcall-make -rtx-traverse-string))
	  (cons 'NUMBER (/fastcall-make -rtx-traverse-number))
	  (cons 'SYMORNUM (/fastcall-make -rtx-traverse-symornum))
	  (cons 'OBJECT (/fastcall-make -rtx-traverse-object))
	  )))

    (for-each (lambda (traverser)
		(hashq-set! hash-tab (car traverser) (cdr traverser)))
	      traversers)

    hash-tab)
)

; Traverse the operands of EXPR, a canonicalized RTL expression.
; Here "canonicalized" means that -rtx-munge-mode&options has been called to
; insert an option list and mode if they were absent in the original
; expression.

(define (-rtx-traverse-operands rtx-obj expr tstate appstuff)
  (if -rtx-traverse-debug?
      (begin
	(display (spaces (* 4 (tstate-depth tstate))))
	(display "Traversing operands of: ")
	(display (rtx-dump expr))
	(newline)
	(rtx-env-dump (tstate-env tstate))
	(force-output)
	))

  (let loop ((operands (cdr expr))
	     (op-num 0)
	     (arg-types (vector-ref -rtx-traverser-table (rtx-num rtx-obj)))
	     (arg-modes (rtx-arg-modes rtx-obj))
	     (result nil)
	     )

    (let ((varargs? (and (pair? arg-types) (symbol? (car arg-types)))))

      (if -rtx-traverse-debug?
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
	    (force-output)
	    ))

      (cond ((null? operands)
	     ; Out of operands, check if we have the expected number.
	     (if (or (null? arg-types)
		     varargs?)
		 (reverse! result)
		 (context-error (tstate-context tstate)
				"missing operands" (rtx-strdump expr))))

	    ((null? arg-types)
	     (context-error (tstate-context tstate)
			    "too many operands" (rtx-strdump expr)))

	    (else
	     (let ((type (if varargs? arg-types (car arg-types)))
		   (mode (let ((mode-spec (if varargs?
					      arg-modes
					      (car arg-modes))))
			   ; This is small enough that this is fast enough,
			   ; and the number of entries should be stable.
			   ; FIXME: for now
			   (case mode-spec
			     ((ANY) 'DFLT)
			     ((NA) #f)
			     ((OP0) (rtx-mode expr))
			     ((MATCH1)
			      ; If there is an explicit mode, use it.
			      ; Otherwise we have to look at operand 1.
			      (if (eq? (rtx-mode expr) 'DFLT)
				  'DFLT
				  (rtx-mode expr)))
			     ((MATCH2)
			      ; If there is an explicit mode, use it.
			      ; Otherwise we have to look at operand 2.
			      (if (eq? (rtx-mode expr) 'DFLT)
				  'DFLT
				  (rtx-mode expr)))
			     (else mode-spec))))
		   (val (car operands))
		   )

	       ; Look up the traverser for this kind of operand and perform it.
	       (let ((traverser (cdr type)))
		 (let ((traversed-val (fastcall6 traverser val mode expr op-num tstate appstuff)))
		   (if traversed-val
		       (begin
			 (set! val (car traversed-val))
			 (set! tstate (cdr traversed-val))))))

	       ; Done with this operand, proceed to the next.
	       (loop (cdr operands)
		     (+ op-num 1)
		     (if varargs? arg-types (cdr arg-types))
		     (if varargs? arg-modes (cdr arg-modes))
		     (cons val result)))))))
)

; Publically accessible version of -rtx-traverse-operands as EXPR-FN may
; need to call it.

(define rtx-traverse-operands -rtx-traverse-operands)

; Subroutine of -rtx-munge-mode&options.
; Return boolean indicating if X is an rtx option.

(define (-rtx-option? x)
  (and (symbol? x)
       (char=? (string-ref x 0) #\:))
)

; Subroutine of -rtx-munge-mode&options.
; Return boolean indicating if X is an rtx option list.

(define (-rtx-option-list? x)
  (or (null? x)
      (and (pair? x)
	   (-rtx-option? (car x))))
)

; Subroutine of -rtx-traverse-expr to fill in the mode if absent and to
; collect the options into one list.
; ARGS is the list of arguments to the rtx function
; (e.g. (1 2) in (add 1 2)).
; ??? "munge" is an awkward name to use here, but I like it for now because
; it's easy to grep for.
; ??? An empty option list requires a mode to be present so that the empty
; list in `(sequence () foo bar)' is unambiguously recognized as the locals
; list.  Icky, sure, but less icky than the alternatives thus far.

(define (-rtx-munge-mode&options args)
  (let ((options nil)
	(mode-name 'DFLT))
    ; Pick off the option list if present.
    (if (and (pair? args)
	     (-rtx-option-list? (car args))
	     ; Handle `(sequence () foo bar)'.  If empty list isn't followed
	     ; by a mode, it is not an option list.
	     (or (not (null? (car args)))
		 (and (pair? (cdr args))
		      (mode-name? (cadr args)))))
	(begin
	  (set! options (car args))
	  (set! args (cdr args))))
    ; Pick off the mode if present.
    (if (and (pair? args)
	     (mode-name? (car args)))
	(begin
	  (set! mode-name (car args))
	  (set! args (cdr args))))
    ; Now put option list and mode back.
    (cons options (cons mode-name args)))
)

; Traverse an expression.
; For syntax expressions arguments are not pre-evaluated before calling the
; user's expression handler.  Otherwise they are.
; If EXPR-FN wants to just scan the operands, rather than evaluating them,
; one thing it can do is call back to rtx-traverse-operands.
; If EXPR-FN returns #f, traverse the operands normally and return
; (rtx's-name traversed-operand1 ...).
; This is for semantic-compile's sake and all traversal handlers are
; required to do this if EXPR-FN returns #f.

(define (-rtx-traverse-expr rtx-obj expr mode parent-expr op-pos tstate appstuff)
  (let* ((expr2 (cons (car expr)
		      (-rtx-munge-mode&options (cdr expr))))
	 (fn (fastcall7 (tstate-expr-fn tstate)
			rtx-obj expr2 mode parent-expr op-pos tstate appstuff)))
    (if fn
	(if (procedure? fn)
	    ; Don't traverse operands for syntax expressions.
	    (if (rtx-style-syntax? rtx-obj)
		(apply fn (cons tstate (cdr expr2)))
		(let ((operands (-rtx-traverse-operands rtx-obj expr2 tstate appstuff)))
		  (apply fn (cons tstate operands))))
	    fn)
	(let ((operands (-rtx-traverse-operands rtx-obj expr2 tstate appstuff)))
	  (cons (car expr2) operands))))
)

; Main entry point for expression traversal.
; (Actually rtx-traverse is, but it's just a cover function for this.)
;
; The result is the result of the lambda EXPR-FN looks up in the case of
; expressions or an operand object (usually <operand>) in the case of operands.
;
; EXPR is the expression to be traversed.
;
; MODE is the name of the mode of EXPR.
;
; PARENT-EXPR is the expression EXPR is contained in.  The top-level
; caller must pass #f for it.
;
; OP-POS is the position EXPR appears in PARENT-EXPR.  The
; top-level caller must pass 0 for it.
;
; EXPECTED is one of `-rtx-valid-types' and indicates the expected rtx type
; or #f if it doesn't matter.
;
; TSTATE is the current traversal state.
;
; APPSTUFF is for application specific use.
;
; All macros are expanded here.  User code never sees them.
; All operand shortcuts are also expand here.  User code never sees them.
; These are:
; - operands, ifields, and numbers appearing where an rtx is expected are
;   converted to use `operand', `ifield', or `const'.

(define (-rtx-traverse expr expected mode parent-expr op-pos tstate appstuff)
  (if -rtx-traverse-debug?
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
	(display "-mode:           ")
	(display mode)
	(newline)
	(force-output)
	))

  (if (pair? expr) ; pair? -> cheap non-null-list?

      (let ((rtx-obj (rtx-lookup (car expr))))
	(tstate-incr-depth! tstate)
	(let ((result
	       (if rtx-obj
		   (-rtx-traverse-expr rtx-obj expr mode parent-expr op-pos tstate appstuff)
		   (let ((rtx-obj (-rtx-macro-lookup (car expr))))
		     (if rtx-obj
			 (-rtx-traverse (-rtx-macro-expand expr rtx-evaluator)
					expected mode parent-expr op-pos tstate appstuff)
			 (context-error (tstate-context tstate) "unknown rtx function"
					expr))))))
	  (tstate-decr-depth! tstate)
	  result))

      ; EXPR is not a list.
      ; See if it's an operand shortcut.
      (if (memq expected '(RTX SETRTX))

	  (cond ((symbol? expr)
		 (cond ((current-op-lookup expr)
			(-rtx-traverse
			 (rtx-make-operand expr) ; (current-op-lookup expr))
			 expected mode parent-expr op-pos tstate appstuff))
		       ((rtx-temp-lookup (tstate-env tstate) expr)
			(-rtx-traverse
			 (rtx-make-local expr) ; (rtx-temp-lookup (tstate-env tstate) expr))
			 expected mode parent-expr op-pos tstate appstuff))
		       ((current-ifld-lookup expr)
			(-rtx-traverse
			 (rtx-make-ifield expr)
			 expected mode parent-expr op-pos tstate appstuff))
		       ((enum-lookup-val expr)
			(-rtx-traverse
			 (rtx-make-enum 'INT expr)
			 expected mode parent-expr op-pos tstate appstuff))
		       (else
			(context-error (tstate-context tstate)
				       "unknown operand" expr))))
		((integer? expr)
		 (-rtx-traverse (rtx-make-const 'INT expr)
				expected mode parent-expr op-pos tstate appstuff))
		(else
		 (context-error (tstate-context tstate)
				"unexpected operand"
				expr)))

	  ; Not expecting RTX or SETRTX.
	  (context-error (tstate-context tstate)
			 "unexpected operand"
			 expr)))
)

; User visible procedures to traverse an rtl expression.
; These calls -rtx-traverse to do most of the work.
; See tstate-make for an explanation of EXPR-FN.
; CONTEXT is a <context> object or #f if there is none.
; LOCALS is a list of (mode . name) elements (the locals arg to `sequence').
; APPSTUFF is for application specific use.

(define (rtx-traverse context owner expr expr-fn appstuff)
  (-rtx-traverse expr #f 'DFLT #f 0
		 (tstate-make context owner expr-fn (rtx-env-empty-stack)
			      #f #f nil 0)
		 appstuff)
)

(define (rtx-traverse-with-locals context owner expr expr-fn locals appstuff)
  (-rtx-traverse expr #f 'DFLT #f 0
		 (tstate-make context owner expr-fn
			      (rtx-env-push (rtx-env-empty-stack)
					    (rtx-env-make-locals locals))
			      #f #f nil 0)
		 appstuff)
)

; Traverser debugger.

(define (rtx-traverse-debug expr)
  (rtx-traverse
   #f #f expr
   (lambda (rtx-obj expr mode parent-expr op-pos tstate appstuff)
     (display "-expr:    ")
     (display (string-append "rtx=" (obj:name rtx-obj)))
     (display " expr=")
     (display expr)
     (display " mode=")
     (display mode)
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

; Convert rtl expression EXPR from source form to compiled form.
; The expression is validated and rtx macros are expanded as well.
; CONTEXT is a <context> object or #f if there is none.
; It is used in error messages.
; EXTRA-VARS-ALIST is an association list of extra (symbol <mode> value)
; elements to be used during value lookup.
;
; This does the same operation that rtx-traverse does, except that it provides
; a standard value for EXPR-FN.
;
; ??? In the future the compiled form may be the same as the source form
; except that all elements would be converted to their respective objects.

(define (-compile-expr-fn rtx-obj expr mode parent-expr op-pos tstate appstuff)
; (cond 
; The intent of this is to handle sequences/closures, but is it needed?
;  ((rtx-style-syntax? rtx-obj)
;   ((rtx-evaluator rtx-obj) rtx-obj expr mode
;			     parent-expr op-pos tstate))
;  (else
  (cons (car expr) ; rtx-obj
	(-rtx-traverse-operands rtx-obj expr tstate appstuff))
)

(define (rtx-compile context expr extra-vars-alist)
  (-rtx-traverse expr #f 'DFLT #f 0
		 (tstate-make context #f
			      (/fastcall-make -compile-expr-fn)
			      (rtx-env-init-stack1 extra-vars-alist)
			      #f #f nil 0)
		 #f)
)

; Various rtx utilities.

; Dump an rtx expression.

(define (rtx-dump rtx)
  (cond ((list? rtx) (map rtx-dump rtx))
	((object? rtx) (string-append "#<object "
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
      (display (rtx-dump rtx))))
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
	(or (hashq-ref -rtx-func-table (car x))
	    (hashq-ref -rtx-macro-table (car x)))))
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

		; Current environment.  This is a stack of sequence locals.
		(env . ())

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
	     ((#:expr-fn)
	      (elm-set! self 'expr-fn (cadr args)))
	     ((#:env)
	      (elm-set! self 'env (cadr args)))
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
  (context owner expr-fn env depth modifiers)
)
(define-setters <eval-state> estate
  (context owner expr-fn env depth modifiers)
)

; Build an estate for use in producing a value from rtl.
; CONTEXT is a <context> object or #f if there is none.
; OWNER is the owner of the expression or #f if there is none.

(define (estate-make-for-eval context owner)
  (vmake <eval-state>
	 #:context context
	 #:owner owner
	 #:expr-fn (lambda (rtx-obj expr mode estate)
		     (rtx-evaluator rtx-obj)))
)

; Create a copy of ESTATE.

(define (estate-copy estate)
  (object-copy-top estate)
)

; Create a copy of STATE with a new environment ENV.

(define (estate-new-env state env)
  (let ((result (estate-copy state)))
    (estate-set-env! result env)
    result)
)

; Create a copy of STATE with environment ENV pushed onto the existing
; environment list.
; There's no routine to pop the environment list as there's no current
; need for it: we make a copy of the state when we push.

(define (estate-push-env state env)
  (let ((result (estate-copy state)))
    (estate-set-env! result (cons env (estate-env result)))
    result)
)

; Create a copy of STATE with modifiers MODS.

(define (estate-with-modifiers state mods)
  (let ((result (estate-copy state)))
    (estate-set-modifiers! result (append mods (estate-modifiers result)))
    result)
)

; Convert a tstate to an estate.

(define (tstate->estate t)
  (vmake <eval-state>
	 #:context (tstate-context t)
	 #:env (tstate-env t))
)

; RTL expression evaluation.
;
; ??? These used eval2 at one point.  Not sure which is faster but I suspect
; eval2 is by far.  On the otherhand this has yet to be compiled.  And this way
; is more portable, more flexible, and works with guile 1.2 (which has
; problems with eval'ing self referential vectors, though that's one reason to
; use smobs).

; Set to #t to debug rtx evaluation.

(define -rtx-eval-debug? #f)

; RTX expression evaluator.
;
; EXPR is the expression to be eval'd.  It must be in compiled form.
; MODE is the mode of EXPR, a <mode> object or its name.
; ESTATE is the current evaluation state.

(define (rtx-eval-with-estate expr mode estate)
  (if -rtx-eval-debug?
      (begin
	(display "Traversing ")
	(display expr)
	(newline)
	(rtx-env-dump (estate-env estate))
	))

  (if (pair? expr) ; pair? -> cheap non-null-list?

      (let* ((rtx-obj (rtx-lookup (car expr)))
	     (fn ((estate-expr-fn estate) rtx-obj expr mode estate)))
	(if fn
	    (if (procedure? fn)
		(apply fn (cons estate (cdr expr)))
;		; Don't eval operands for syntax expressions.
;		(if (rtx-style-syntax? rtx-obj)
;		    (apply fn (cons estate (cdr expr)))
;		    (let ((operands
;			   (-rtx-eval-operands rtx-obj expr estate)))
;		      (apply fn (cons estate operands))))
		fn)
	    ; Leave expr unchanged.
	    expr))
;	    (let ((operands
;		   (-rtx-traverse-operands rtx-obj expr estate)))
;	      (cons rtx-obj operands))))

      ; EXPR is not a list
      (error "argument to rtx-eval-with-estate is not a list" expr))
)

; Evaluate rtx expression EXPR and return the computed value.
; EXPR must already be in compiled form (the result of rtx-compile).
; OWNER is the owner of the value, used for attribute computation,
; or #f if there isn't one.
; FIXME: context?

(define (rtx-value expr owner)
  (rtx-eval-with-estate expr 'DFLT (estate-make-for-eval #f owner))
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

(define (-rtx-hw-name hw hw-name index-arg)
  (cond ((hw-scalar? hw)
	 hw-name)
	((rtx? index-arg)
	 (symbol-append hw-name '- (rtx-pretty-name index-arg)))
	(else
	 (symbol-append hw-name ; (obj:name (op:type self))
			'-
			; (obj:name (op:index self)))))
			(stringize index-arg "-"))))
)

; Return the <operand> object described by
; HW-NAME/MODE-NAME/SELECTOR/INDEX-ARG.
;
; HW-NAME is the name of the hardware element.
; INDEX-ARG is an rtx or number of the index.
; In the case of scalar hardware elements, pass 0 for INDEX-ARG.
; MODE-NAME is the name of the mode.
; In the case of a vector of registers, INDEX-ARG is the vector index.
; In the case of a scalar register, the value is ignored, but pass 0 (??? #f?).
; SELECTOR is an rtx or number and is passed to HW-NAME to allow selection of a
; particular variant of the hardware.  It's kind of like an INDEX, but along
; an atypical axis.  An example is memory ASI's on Sparc.  Pass
; hw-selector-default if there is no selector.
; ESTATE is the current rtx evaluation state.
;
; e.g. (hw estate WI h-gr #f (const INT 14))
; selects register 14 of the h-gr set of registers.
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

(define (hw estate mode-name hw-name index-arg selector)
  ; Enforce some rules to keep things in line with the current design.
  (if (not (symbol? mode-name))
      (parse-error "hw" "invalid mode name" mode-name))
  (if (not (symbol? hw-name))
      (parse-error "hw" "invalid hw name" hw-name))
  (if (not (or (number? index-arg)
	       (rtx? index-arg)))
      (parse-error "hw" "invalid index" index-arg))
  (if (not (or (number? selector)
	       (rtx? selector)))
      (parse-error "hw" "invalid selector" selector))

  (let ((hw (current-hw-sem-lookup-1 hw-name)))
    (if (not hw)
	(parse-error "hw" "invalid hardware element" hw-name))

    (let ((mode (if (eq? mode-name 'DFLT) (hw-mode hw) (mode:lookup mode-name)))
	  (result (new <operand>))) ; ??? lookup-for-new?

      (if (not mode)
	  (parse-error "hw" "invalid mode" mode-name))

      ; Record the selector.
      (elm-xset! result 'selector selector)

      ; Create the index object.
      (elm-xset! result 'index
		 (cond ((number? index-arg)
			(make <hw-index> 'anonymous 'constant UINT index-arg))
		       ((rtx? index-arg)
			; For the simulator the following could be done which
			; would save having to create a closure.
			; ??? Old code, left in for now.
			; (rtx-get estate DFLT
			;          (rtx-eval (estate-context estate)
			;                    (estate-econfig estate)
			;                    index-arg rtx-evaluator))
			; Make sure constant indices are recorded as such.
			(if (rtx-constant? index-arg)
			    (make <hw-index> 'anonymous 'constant UINT
				  (rtx-constant-value index-arg))
			    (make <hw-index> 'anonymous 'rtx DFLT
				  (-rtx-closure-make estate index-arg))))
		       (else (parse-error "hw" "invalid index" index-arg))))

      (if (not (hw-mode-ok? hw (obj:name mode) (elm-xget result 'index)))
	  (parse-error "hw" "invalid mode for hardware" mode-name))

      (elm-xset! result 'type hw)
      (elm-xset! result 'mode mode)

      ; The name of the operand must include the index so that multiple copies
      ; of a hardware object (e.g. h-gr[0], h-gr[14]) can be distinguished.
      (let ((name (-rtx-hw-name hw hw-name index-arg)))
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
; unevaluated RTX expression.
; The selector, if present, is (cadr indx-sel) and must be a number or
; unevaluated RTX expression.
; ??? A register selector isn't supported yet.  It's just an idea that's
; been put down on paper for future reference.

(define (reg estate mode hw-name . indx-sel)
  (s-hw estate mode hw-name
	(if (pair? indx-sel) (car indx-sel) 0)
	(if (and (pair? indx-sel) (pair? (cdr indx-sel)))
	    (cadr indx-sel)
	    hw-selector-default))
)

; This is shorthand for (hw estate mode h-memory addr selector).
; ADDR must be an unevaluated RTX expression.
; If present (car sel) must be a number or unevaluated RTX expression.

(define (mem estate mode addr . sel)
  (s-hw estate mode 'h-memory addr
	(if (pair? sel) (car sel) hw-selector-default))
)

; For the rtx nodes to use.

(define s-hw hw)

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
      (error "if: too many elements in `else' part" else))
  (if (null? else)
      (if cond then)
      (if cond then (car else)))
)

; Subroutines.
; ??? Not sure this should live here.

(define (-subr-read errtxt . arg-list)
  #f
)

(define define-subr
  (lambda arg-list
    (let ((s (apply -subr-read (cons "define-subr" arg-list))))
      (if s
	  (current-subr-add! s))
      s))
)

; Misc. utilities.

; The argument to drn,drmn,drsn must be Scheme code (or a fixed subset
; thereof).  .str/.sym are used in pmacros so it makes sense to include them
; in the subset.
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
  (set! -rtx-func-table (make-hash-table 127))
  (set! -rtx-macro-table (make-hash-table 127))
  (set! -rtx-num-next 0)
  (def-rtx-funcs)
  (reader-add-command! 'define-subr
		       "\
Define an rtx subroutine, name/value pair list version.
"
		       nil 'arg-list define-subr)
  *UNSPECIFIED*
)

; Install builtins

(define (rtl-builtin!)
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

  ; Table of traversers for the various rtx elements.
  (let ((hash-table (-rtx-make-traverser-table)))
    (set! -rtx-traverser-table (make-vector (rtx-max-num) #f))
    (for-each (lambda (rtx-name)
		(let ((rtx (rtx-lookup rtx-name)))
		  (if rtx
		      (vector-set! -rtx-traverser-table (rtx-num rtx)
				   (map1-improper
				    (lambda (arg-type)
				      (cons arg-type
					    (hashq-ref hash-table arg-type)))
				    (rtx-arg-types rtx))))))
	      (rtx-name-list)))

  ; Initialize the operand hash table.
  (set! -rtx-operand-table (make-hash-table 127))

  ; Add the operands to the eval symbol table.
  (for-each (lambda (op)
	      (hashq-set! -rtx-operand-table (obj:name op) op)
	      )
	    (current-op-list))

  ; Add ifields to the eval symbol table.
  (for-each (lambda (f)
	      (hashq-set! -rtx-operand-table (obj:name f) f)
	      )
	    (non-derived-ifields (current-ifld-list)))

  *UNSPECIFIED*
)
