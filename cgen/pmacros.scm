; Preprocessor-like macro support.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; TODO:
; - Like C preprocessor macros, there is no scoping [one can argue
;   there should be].  Maybe in time (??? Hmmm... done?)
;   On the other hand these macros aren't intended for use outside
;   the cpu description file.
; - Support for multiple macro tables.
; - Comments for .pmacros.

; Required routines:
; make-hash-table, hashq-ref, hashq-set!
; string-append, symbol-append, map, apply, number?, number->string,
; eval, num-args-ok?, *UNSPECIFIED*.
; `num-args-ok?' and `*UNSPECIFIED*' are defined in cgen's utils.scm.

; The convention we use says `-' begins "local" objects.
; At some point this might also use the Guile module system.

; Exported routines:
;
; pmacro-init! - initialize the pmacro system
;
; define-pmacro - define a symbolic or procedural macro
;
;	(define-pmacro symbol "comment" expansion)
;	(define-pmacro (symbol [args]) "comment" (expansion))
;
; ARGS is a list of `symbol' or `(symbol default-value)' elements.
;
; pmacro-expand - expand all macros in an expression
;
;	(pmacro-expand expression)
;
; pmacro-trace - same as pmacro-expand, but print debugging messages
;
;	(pmacro-trace expression)

; Builtin macros:
;
; (.sym symbol1 symbol2 ...)          - symbol-append
; (.str string1 string2 ...)          - string-append
; (.hex number)                       - convert to hex string
; (.upcase string)                    - convert to uppercase
; (.downcase string)                  - convert to lowercase
; (.substring string start end)       - get part of a string
; (.splice a b (.unsplice c) d e ...) - quasi-quote/unquote-splicing
; (.iota count [start [increment]])   - number generator
; (.map macro-name arg1 ...)          - map
; (.apply macro-name arg)             - apply
; (.pmacro (arg-list) expansion)      - lambda (??? call it .lambda?)
; (.eval (expr))                      - eval (experimental)
;
; .sym and .str convert numbers to symbols/strings as necessary (base 10).
;
; .pmacro is for constructing pmacros on-the-fly, like lambda, and is currently
; only valid as arguments to other macros.
; ??? Nested pmacros don't bind their arguments the way nested lambda's do.
; Should they?
;
; .eval is an experiment.  Ports that consider themselves to be of beta
; quality or better don't use it.
;
; ??? Methinks .foo isn't a valid R5RS symbol.  May need to change 
; to something else.  Where's Quad when you need it?! :-)

(define -pmacro-trace? #f)

(define -pmacro-table #f)
(define (-pmacro-lookup name) (hashq-ref -pmacro-table name))
(define (-pmacro-set! name val) (hashq-set! -pmacro-table name val))

; Marker to indicate a value is a pmacro.
(define -pmacro-marker '<pmacro>)

; Utilities to create and access pmacros.
(define (-pmacro-make name arg-spec default-values transformer comment)
  (vector -pmacro-marker name arg-spec default-values transformer comment)
)
(define (-pmacro? x) (and (vector? x) (eq? (vector-ref x 0) -pmacro-marker)))
(define (-pmacro-name pmac) (vector-ref pmac 1))
(define (-pmacro-arg-spec pmac) (vector-ref pmac 2))
(define (-pmacro-default-values pmac) (vector-ref pmac 3))
(define (-pmacro-transformer pmac) (vector-ref pmac 4))
(define (-pmacro-comment pmac) (vector-ref pmac 5))

; Cover functions to manage an "environment" in case a need or desire for
; another method arises.

(define (-pmacro-env-make names values) (map cons names values))
(define (-pmacro-env-ref env name) (assq name env))

; Error message generator.

(define (-pmacro-error msg expr)
  (error (string-append
	  (or (port-filename (current-input-port)) "<input>")
	  ":"
	  (number->string (port-line (current-input-port)))
	  ":"
	  msg
	  ":")
	 expr)
)

; Process list of keyword/value specified arguments.

(define (-pmacro-process-keyworded-args arg-spec default-values args)
  ; Build a list of default values, then override ones specified in ARGS,
  (let ((result-alist (alist-copy default-values)))
    (let loop ((args args))
      (cond ((null? args)
	     #f) ; done
	    ((and (pair? args) (keyword? (car args)))
	     (let ((elm (assq (car args) result-alist)))
	       (if (not elm)
		   (-pmacro-error "not an argument name" (car args)))
	       (if (null? (cdr args))
		   (-pmacro-error "missing argument to #:keyword" (car args)))
	       (set-cdr! elm (cadr args))
	       (loop (cddr args))))
	    (else
	     (-pmacro-error "bad keyword/value argument list" args))))

    ; Ensure each element has a value.
    (let loop ((to-scan result-alist))
      (if (null? to-scan)
	  #f ; done
	  (begin
	    (if (not (cdar to-scan))
		(-pmacro-error "argument value not specified" (caar to-scan)))
	    (loop (cdr to-scan)))))

    ; If varargs pmacro, adjust result.
    (if (list? arg-spec)
	(map cdr result-alist) ; not varargs
	(let ((nr-args (length (result-alist))))
	  (append! (map cdr (list-head result-alist (- nr-args 1)))
		   (cdr (list-tail result-alist (- nr-args 1)))))))
)

; Process a pmacro argument list.
; ARGS is either a fully specified position dependent argument list,
; or is a list of keyword/value pairs with missing values coming from
; DEFAULT-VALUES.

(define (-pmacro-process-args arg-spec default-values args)
  (if (and (pair? args) (keyword? (car args)))
      (-pmacro-process-keyworded-args arg-spec default-values args)
      args)
)

; Invoke a procedural macro.
; ??? A better name might be -pmacro-apply but that is taken by the
; .apply handler.

(define (-pmacro-invoke macro args)
  (let ((arg-spec (-pmacro-arg-spec macro))
	(default-values (-pmacro-default-values macro)))
    (let ((processed-args (-pmacro-process-args arg-spec default-values args)))
      (if (not (num-args-ok? (length processed-args) arg-spec))
	  (-pmacro-error (string-append
			  "wrong number of arguments to pmacro "
			  (with-output-to-string
			    (lambda ()
			      (write (cons (-pmacro-name macro)
					   (-pmacro-arg-spec macro))))))
			 args))
      (apply (-pmacro-transformer macro) processed-args)))
)

; Expand expression EXP using ENV, an alist of variable assignments.

(define (-pmacro-expand exp env)

  (define cep (current-error-port))

  ; If the symbol is in `env', return its value.
  ; Otherwise see if symbol is a globally defined pmacro.
  ; Otherwise return the symbol unchanged.
  (define (scan-symbol sym)
    (let ((val (-pmacro-env-ref env sym)))
      (if val
	  (cdr val) ; cdr is value of (name . value) pair
	  (let ((val (-pmacro-lookup sym)))
	    (if val
		; Symbol is a macro.
		; If this is a procedural macro, let caller perform expansion.
		; Otherwise, return the macro's value.
		(if (procedure? (-pmacro-transformer val))
		    val
		    (-pmacro-transformer val))
		; Return symbol unchanged.
		sym)))))

  ; See if (car exp) is a macro.
  ; Return macro or #f.
  (define (check-macro exp)
    (if -pmacro-trace?
	(begin
	  (display "macro?   " cep)
	  (write exp cep)
	  (newline cep)))
    (and (-pmacro? (car exp)) (car exp)))

  ; Scan each element in EXP and see if the result is a macro invocation.
  (define (scan-list exp)
    ; Check for syntactic forms.
    (case (car exp)
      ((.pmacro)
       (if (not (= (length exp) 3))
	   (-pmacro-error "wrong number of arguments to .pmacro" exp))
       (-pmacro-pmacro (cadr exp) (caddr exp)))
      (else
       (let ((scanned-exp (map scan exp)))
	 (let ((macro (check-macro scanned-exp)))
	   (if macro
	       (if (procedure? (-pmacro-transformer macro))
		   (-pmacro-invoke macro (cdr scanned-exp))
		   (cons (-pmacro-transformer macro) (cdr scanned-exp)))
	       scanned-exp))))))

  ; Scan EXP, an arbitrary value.
  (define (scan exp)
    (let ((result (cond ((symbol? exp) (scan-symbol exp))
			((and (list? exp) (not (null? exp))) (scan-list exp))
			; Not a symbol or expression, return unchanged.
			(else exp))))
      ; ??? We use to re-examine `result' to see if it was another pmacro
      ; invocation.  This allowed doing things like ((.sym a b c) arg1 arg2)
      ; where `abc' is a pmacro.  Scheme doesn't work this way, so it was
      ; removed.  It can be put back should it ever be warranted.
      result))

  (if -pmacro-trace?
      (begin
	; We use `write' to display `exp' to see strings quoted.
	(display "expand: " cep) (write exp cep) (newline cep)
	(display "   env: " cep) (display env cep) (newline cep)))

  (let ((result (scan exp)))
    (if -pmacro-trace?
	(begin
	  (display "result:  " cep) (write result cep) (newline cep)))
    result)
)

; Return the argument spec from ARGS.
; ARGS is a [possibly improper] list of `symbol' or `(symbol default-value)'
; elements.  For varargs pmacros, ARGS must be an improper list
; (e.g. (a b . c)) with the last element being a symbol.

(define (-pmacro-get-arg-spec args)
  (let ((parse-arg
	 (lambda (arg)
	   (cond ((symbol? arg)
		  arg)
		 ((and (pair? arg) (symbol? (car arg)))
		  (car arg))
		 (else
		  (-pmacro-error "argument not `symbol' or `(symbol . default-value)'"
				 arg))))))
    (if (list? args)
	(map parse-arg args)
	(letrec ((parse-improper-list
		  (lambda (args)
		    (cond ((symbol? args)
			   args)
			  ((pair? args)
			   (cons (parse-arg (car args))
				 (parse-improper-list (cdr args))))
			  (else
			   (-pmacro-error "argument not `symbol' or `(symbol . default-value)'"
					  args))))))
	  (parse-improper-list args))))
)

; Return the default values specified in ARGS.
; The result is an alist of (#:arg-name . default-value) elements.
; ARGS is a [possibly improper] list of `symbol' or `(symbol . default-value)'
; elements.  For varargs pmacros, ARGS must be an improper list
; (e.g. (a b . c)) with the last element being a symbol.
; Unspecified default values are recorded as #f.

(define (-pmacro-get-default-values args)
  (let ((parse-arg
	 (lambda (arg)
	   (cond ((symbol? arg)
		  (cons (symbol->keyword arg) #f))
		 ((and (pair? arg) (symbol? (car arg)))
		  (cons (symbol->keyword (car arg)) (cdr arg)))
		 (else
		  (-pmacro-error "argument not `symbol' or `(symbol . default-value)'"
				 arg))))))
    (if (list? args)
	(map parse-arg args)
	(letrec ((parse-improper-list
		  (lambda (args)
		    (cond ((symbol? args)
			   (cons (parse-arg args) nil))
			  ((pair? args)
			   (cons (parse-arg (car args))
				 (parse-improper-list (cdr args))))
			  (else
			   (-pmacro-error "argument not `symbol' or `(symbol . default-value)'"
					  args))))))
	  (parse-improper-list args))))
)

; Build a procedure that performs a pmacro expansion.

(define (-pmacro-build-lambda params expansion)
  (eval `(lambda ,params
	   (-pmacro-expand ',expansion (-pmacro-env-make ',params (list ,@params)))))
)

; ??? I'd prefer to use `define-macro', but boot-9.scm uses it and
; I'd rather not risk a collision.  I could of course make the association
; during parsing, maybe later.
; ??? On the other hand, calling them pmacros removes all ambiguity.
;
; The syntax is one of:
; (define (name args ...) expansion)
; (define (name args ...) "documentation" expansion)
;
; If `expansion' is the name of a pmacro, its value is used (rather than its
; name).
; ??? The goal here is to follow Scheme's define/lambda, but not all variants
; are supported yet.  There's also the difference that we treat undefined
; symbols as being themselves.

(define (define-pmacro header arg1 . arg-rest)
  (let ((name (if (symbol? header) header (car header)))
	(arg-spec (if (symbol? header) #f (-pmacro-get-arg-spec (cdr header))))
	(default-values (if (symbol? header) #f (-pmacro-get-default-values (cdr header))))
	(comment (if (null? arg-rest) "" arg1))
	(expansion (if (null? arg-rest) arg1 (car arg-rest))))
    (if (symbol? header)
	(if (symbol? expansion)
	    (let ((maybe-pmacro (-pmacro-lookup expansion)))
	      (if maybe-pmacro
		  (-pmacro-set! name
				(-pmacro-make name
					      (-pmacro-arg-spec maybe-pmacro)
					      (-pmacro-default-values maybe-pmacro)
					      (-pmacro-transformer maybe-pmacro)
					      comment))
		  (-pmacro-set! name (-pmacro-make name #f #f expansion comment))))
	    (-pmacro-set! name (-pmacro-make name #f #f expansion comment)))
	(-pmacro-set! name
		      (-pmacro-make name arg-spec default-values
				    (-pmacro-build-lambda arg-spec expansion)
				    comment))))
    *UNSPECIFIED*
)

; Expand any pmacros in EXPR.

(define (pmacro-expand expr)
  (-pmacro-expand expr '())
)

; Debugging routine to trace macro expansion.

(define (pmacro-trace expr)
  ; ??? Need unwind protection.
  (let ((old -pmacro-trace?))
    (set! -pmacro-trace? #t)
    (let ((result (-pmacro-expand expr '())))
      (set! -pmacro-trace? old)
      result))
)

; Builtin macros.

; .sym - symbol-append, auto-convert numbers

(define -pmacro-sym
  (lambda args
    (apply symbol-append
	   (map (lambda (elm)
		  (if (number? elm)
		      (number->string elm)
		      elm))
		args)))
)

; .str - string-append, auto-convert numbers

(define -pmacro-str
  (lambda args
    (apply string-append
	   (map (lambda (elm)
		  (if (number? elm)
		      (number->string elm)
		      elm))
		args)))
)

; .hex - convert number to hex string
; WIDTH, if present, is the number of characters in the result, beginning
; from the least significant digit.

(define (-pmacro-hex num . width)
  (if (> (length width) 1)
      (-pmacro-error "wrong number of arguments to .hex"
		     (cons '.hex (cons num width))))
  (let ((str (number->string num 16)))
    (if (null? width)
	str
	(let ((len (string-length str)))
	  (substring (string-append (make-string (car width) #\0) str)
		     len (+ len (car width))))))
)

; .upcase - convert a string to uppercase

(define (-pmacro-upcase str)
  (string-upcase str)
)

; .downcase - convert a string to lowercase

(define (-pmacro-downcase str)
  (string-downcase str)
)

; .substring - get part of a string

(define (-pmacro-substring str start end)
  (substring str start end)
)

; .splice - splicing support
; Splice lists into the outer list.
;
; E.g. (define-pmacro '(splice-test a b c) '(.splice a (.unsplice b) c))
; (pmacro-expand '(splice-test (1 (2) 3))) --> (1 2 3)
;
; Similar to `(1 ,@'(2) 3) in Scheme, though the terminology is slightly
; different (??? may need to revisit).  In Scheme we have quasi-quote,
; unquote, unquote-splicing.  Here we have splice, unsplice.

(define -pmacro-splice
  (lambda arg-list
    ; ??? Not the most efficient implementation, but will the difference
    ; ever be measureable?
    (let loop ((arg-list arg-list) (result '()))
      (cond ((null? arg-list) result)
	    ((and (pair? (car arg-list)) (eq? '.unsplice (caar arg-list)))
	     (if (= (length (car arg-list)) 2)
		 (if (list? (cadar arg-list))
		     (loop (cdr arg-list) (append result (cadar arg-list)))
		     (-pmacro-error "argument to .unsplice must be a list"
				    (car arg-list)))
		 (-pmacro-error "wrong number of arguments to .unsplice"
				(car arg-list))))
	    (else
	     (loop (cdr arg-list) (append result (list (car arg-list))))))))
)

; .iota
; Usage:
; (.iota count)            ; start=0, incr=1
; (.iota count start)      ; incr=1
; (.iota count start incr)

(define (-pmacro-iota count . start-incr)
  (if (> (length start-incr) 2)
      (-pmacro-error "wrong number of arguments to .iota"
		     (cons '.iota (cons count start-incr))))
  (if (< count 0)
      (-pmacro-error "count must be non-negative"
		     (cons '.iota (cons count start-incr))))
  (let ((start (if (pair? start-incr) (car start-incr) 0))
	(incr (if (= (length start-incr) 2) (cadr start-incr) 1)))
    (let loop ((i start) (count count) (result '()))
      (if (= count 0)
	  (reverse! result)
	  (loop (+ i incr) (- count 1) (cons i result)))))
)

; .map

(define (-pmacro-map pmacro arg1 . arg-rest)
  (if (not (-pmacro? pmacro))
      (-pmacro-error "not a pmacro" pmacro))
  (let ((transformer (-pmacro-transformer pmacro)))
    (if (not (procedure? transformer))
	(-pmacro-error "not a procedural macro" pmacro))
    (apply map (cons transformer (cons arg1 arg-rest))))
)

; .apply

(define (-pmacro-apply pmacro arg-list)
  (if (not (-pmacro? pmacro))
      (-pmacro-error "not a pmacro" pmacro))
  (let ((transformer (-pmacro-transformer pmacro)))
    (if (not (procedure? transformer))
	(-pmacro-error "not a procedural macro" pmacro))
    (apply transformer arg-list))
)

; .pmacro

(define (-pmacro-pmacro params expansion)
  (if (not (list? params))
      (-pmacro-error "bad parameter list" params))
  (-pmacro-make '.anonymous params #f (-pmacro-build-lambda params expansion) "")
)

; Initialization.

(define (pmacros-init!)
  (set! -pmacro-table (make-hash-table 127))

  ; Some "predefined" macros.

  (-pmacro-set! '.sym
		(-pmacro-make '.sym 'symbols #f -pmacro-sym "symbol-append"))
  (-pmacro-set! '.str
		(-pmacro-make '.str 'strings #f -pmacro-str "string-append"))
  (-pmacro-set! '.hex
		(-pmacro-make '.hex '(number . width) #f -pmacro-hex
			      "convert to hex, with optional width"))
  (-pmacro-set! '.upcase
		(-pmacro-make '.upcase '(string) #f
			      -pmacro-upcase "string-upcase"))
  (-pmacro-set! '.downcase
		(-pmacro-make '.downcase '(string) #f
			      -pmacro-downcase "string-downcase"))
  (-pmacro-set! '.substring
		(-pmacro-make '.substring '(string start end) #f
			      -pmacro-substring "get part of a string"))
  (-pmacro-set! '.splice
		(-pmacro-make '.splice 'arg-list #f -pmacro-splice
			      "splice lists into the outer list"))
  (-pmacro-set! '.iota
		(-pmacro-make '.iota '(count . start-incr) #f -pmacro-iota
			      "iota number generator"))
  (-pmacro-set! '.map
		(-pmacro-make '.map '(macro-name arg1 . arg-rest) #f
			      -pmacro-map
			      "map a macro over a list of arguments"))
  (-pmacro-set! '.apply
		(-pmacro-make '.apply '(macro-name arg-list) #f -pmacro-apply
			      "apply a macro, taking arguments from a list"))
  (-pmacro-set! '.pmacro
		(-pmacro-make '.pmacro '(params expansion) #f -pmacro-pmacro
			      "create a pmacro on-the-fly"))

  ; doesn't work, Hobbit creates "eval" variable
  ;(-pmacro-set! '.eval (-pmacro-make '.eval '(expr) #f eval "eval"))
  (-pmacro-set! '.eval (-pmacro-make '.eval '(expr) #f (eval 'eval) "eval"))
)

; Initialize so we're ready to use after loading.
(pmacros-init!)
