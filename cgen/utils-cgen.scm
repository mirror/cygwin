; CGEN Utilities.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.
;
; This file contains utilities specific to cgen.
; Generic utilities should go in utils.scm.

; True if text of sanitize markers are to be emitted.
; This is a debugging tool only, though it could have use in sanitized trees.
(define include-sanitize-marker? #t)

; Utility to display command line invocation for debugging purposes.

(define (display-argv argv)
  (let ((cep (current-error-port)))
    (display "cgen -s " cep)
    (for-each (lambda (arg)
		; Output double-quotes if string has a space for better
		; correspondence to how to specify string to shell.
		(if (string-index arg #\space)
		    (write arg cep)
		    (display arg cep))
		(display " " cep))
	      argv)
    (newline cep))
)

; COS utilities.
; Perhaps these should be provided with cos (cgen-object-system), but for
; now they live here.

; Define the getter for a list of elements of a class.

(defmacro define-getters (class class-prefix elm-names)
  (cons 'begin
	(map (lambda (elm-name)
	       (if (pair? elm-name)
		   `(define ,(symbol-append class-prefix '- (cdr elm-name))
		      (elm-make-getter ,class (quote ,(car elm-name))))
		   `(define ,(symbol-append class-prefix '- elm-name)
		      (elm-make-getter ,class (quote ,elm-name)))))
	     elm-names))
)

; Define the setter for a list of elements of a class.

(defmacro define-setters (class class-prefix elm-names)
  (cons 'begin
	(map (lambda (elm-name)
	       (if (pair? elm-name)
		   `(define ,(symbol-append class-prefix '-set- (cdr elm-name) '!)
		      (elm-make-setter ,class (quote ,(car elm-name))))
		   `(define ,(symbol-append class-prefix '-set- elm-name '!)
		      (elm-make-setter ,class (quote ,elm-name)))))
	     elm-names))
)

; Make an object, specifying values for particular elements.
; ??? Eventually move to cos.scm/cos.c.

(define (vmake class . args)
  (let ((obj (new class)))
    (let ((unrecognized (send obj 'vmake! args)))
      (if (null? unrecognized)
	  obj
	  (error "vmake: unknown options:" unrecognized))))
)

; Each named entry in the description file typically has these three members:
; name, comment attrs.

(define <ident> (class-make '<ident> () '(name comment attrs) ()))

(method-make! <ident> 'get-name (lambda (self) (elm-get self 'name)))
(method-make! <ident> 'get-comment (lambda (self) (elm-get self 'comment)))
(method-make! <ident> 'get-atlist (lambda (self) (elm-get self 'attrs)))

(method-make! <ident> 'set-name!
	      (lambda (self newval) (elm-set! self 'name newval)))
(method-make! <ident> 'set-comment!
	      (lambda (self newval) (elm-set! self 'comment newval)))
(method-make! <ident> 'set-atlist!
	      (lambda (self newval) (elm-set! self 'attrs newval)))

; All objects defined in the .cpu file have these elements.
; Where in the class hierarchy they're recorded depends on the object.
; Additionally most objects have `name', `comment' and `attrs' elements.

(define (obj:name obj) (send obj 'get-name))
(define (obj-set-name! obj name) (send obj 'set-name! name))
(define (obj:comment obj) (send obj 'get-comment))

; Utility to add standard access methods for name, comment, attrs.
; ??? Old.  Using <ident> baseclass now.

(define (add-ident-methods! class)
  (method-make! class 'get-name (lambda (self) (elm-get self 'name)))
  (method-make! class 'set-name! (lambda (self name) (elm-set! self 'name name)))

  (method-make! class 'get-comment (lambda (self) (elm-get self 'comment)))
  (method-make! class 'set-comment! (lambda (self comment) (elm-set! self 'comment comment)))

  (method-make! class 'get-atlist (lambda (self) (elm-get self 'attrs)))
  (method-make! class 'set-atlist! (lambda (self attrs) (elm-set! self 'attrs attrs)))

  *UNSPECIFIED*
)

; Parsing utilities

; Parsing context, used to give better error messages.

(define <context>
  (class-make '<context> nil
	      '(
		; Name of file containing object being processed.
		(file . #f)
		; Line number in the file.
		(lineno . #f)
		; Error message prefix
		(prefix . "")
		)
	      nil)
)

; Accessors.

(define-getters <context> context (file lineno prefix))

; Create a <context> object that is just a prefix.

(define (context-make-prefix prefix)
  (make <context> #f #f prefix)
)

; Create a <context> object for the reader.
; This sets file,lineno from (current-input-port).

(define (context-make-reader prefix)
  (make <context>
    (or (port-filename (current-input-port))
	"<input>")
    (port-line (current-input-port))
    prefix)
)

; Call this to issue an error message.
; CONTEXT is a <context> object or #f if there is none.
; ARG is the value that had the error if there is one.

(define (context-error context errmsg . arg)
  (cond ((and context (context-file context))
	 (let ((msg (string-append
		     (context-file context) ":"
		     (number->string (context-lineno context)) ": "
		     (context-prefix context) ": "
		     errmsg ": ")))
	   (apply error (cons msg arg))))
	(context (let ((msg (string-append (context-prefix context) ": "
					   errmsg ": ")))
		   (apply error (cons msg arg))))
	(else (apply error (cons (string-append errmsg ": ") arg))))
)

; Parse an object name.
; NAME is either a symbol or a list of symbols which are concatenated
; together.  Each element can in turn be a list of symbols, and so on.
; This supports symbol concatenation in the description file without having
; to using string-append or some such.
; FIXME: Isn't the plan to move ERRTXT to the 1st arg?

(define (parse-name name errtxt)
  (cond ((list? name)
	 (string->symbol (string-map (lambda (elm) (parse-name elm errtxt)) name)))
	((symbol? name) name)
	((string? name) (string->symbol name))
	(else (parse-error errtxt "improper name" name)))
)

; Parse an object comment.
; COMMENT is either a string or a list of strings, each element of which may
; in turn be a list of strings.
; FIXME: Isn't the plan to move ERRTXT to the 1st arg?

(define (parse-comment comment errtxt)
  (cond ((list? comment)
	 (string-map (lambda (elm) (parse-comment elm errtxt)) comment))
	((or (string? comment) (symbol? comment))
	 comment)
	(else (parse-error errtxt "improper comment" comment)))
)

; Parse a symbol.

(define (parse-symbol context value)
  (if (and (not (symbol? value)) (not (string? value)))
      (parse-error context "not a symbol" value))
  value
)

; Parse a string.

(define (parse-string context value)
  (if (and (not (symbol? value)) (not (string? value)))
      (parse-error context "not a string" value))
  value
)

; Parse a number.
; VALID-VALUES is a list of numbers and (min . max) pairs.

(define (parse-number errtxt value . valid-values)
  (if (not (number? value))
      (parse-error errtxt "not a number" value))
  (if (any-true? (map (lambda (test)
			(if (pair? test)
			    (and (>= value (car test))
				 (<= value (cdr test)))
			    (= value test)))
		      valid-values))
      value
      (parse-error errtxt "invalid number" value valid-values))
)

; Parse a boolean value

(define (parse-boolean context value)
  (if (boolean? value)
      value
      (parse-error context "not a boolean (#f/#t)" value))
)

; Parse a list of handlers.
; Each entry is (symbol "string").
; These map function to a handler for it.
; The meaning is up to the application but generally the handler is a
; C/C++ function name.
; ALLOWED is a list valid values for the symbol or #f if anything is allowed.
; The result is handlers unchanged.

(define (parse-handlers context allowed handlers)
  (if (not (list? handlers))
      (parse-error context "bad handler spec" handlers))
  (for-each (lambda (arg)
	      (if (not (list-elements-ok? arg (list symbol? string?)))
		  (parse-error context "bad handler spec" arg))
	      (if (and allowed (not (memq (car arg) allowed)))
		  (parse-error context "unknown handler type" (car arg))))
	    handlers)
  handlers
)

; Return a boolean indicating if X is a keyword.
; This also handles symbols named :foo because Guile doesn't stablely support
; :keywords (how does one enable :keywords? read-options doesn't appear to
; work).

(define (keyword-list? x)
  (and (list? x)
       (not (null? x))
       (or (keyword? (car x))
	   (and (symbol? (car x))
		(char=? (string-ref (car x) 0) #\:))))
)

; Convert a list like (#:key1 val1 #:key2 val2 ...) to
; ((#:key1 val1) (#:key2 val2) ...).
; Missing values are specified with an empty list.
; This also supports (:sym1 val1 ...) because Guile doesn't stablely support
; :keywords (#:keywords work, but #:foo shouldn't appear in the description
; language).

(define (keyword-list->arg-list kl)
  ; Scan KL backwards, building up each element as we go.
  (let loop ((result nil) (current nil) (rkl (reverse kl)))
    (cond ((null? rkl)
	   result)
	  ((keyword? (car rkl))
	   (loop (acons (keyword->symbol (car rkl)) current result)
		 nil
		 (cdr rkl)))
	  ((and (symbol? (car rkl))
		(char=? (string-ref (car rkl) 0) #\:))
	   (loop (acons (string->symbol
			 (substring (car rkl) 1 (string-length (car rkl))))
			current result)
		 nil
		 (cdr rkl)))
	  (else
	   (loop result
		 (cons (car rkl) current)
		 (cdr rkl)))))
)

; Signal an error if the argument name is not a symbol.
; This is done by each of the argument validation routines so the caller
; doesn't need to make two calls.

(define (arg-list-validate-name errtxt arg-spec)
  (if (null? arg-spec)
      (parse-error errtxt "empty argument spec"))
  (if (not (symbol? (car arg-spec)))
      (parse-error errtxt "argument name not a symbol" arg-spec))
  *UNSPECIFIED*
)

; Signal a parse error if an argument was specified with a value.
; ARG-SPEC is (name value).

(define (arg-list-check-no-args errtxt arg-spec)
  (arg-list-validate-name errtxt arg-spec)
  (if (not (null? (cdr arg-spec)))
      (parse-error errtxt (string-append (car arg-spec)
					 " takes zero arguments")))
  *UNSPECIFIED*
)

; Validate and return a symbol argument.
; ARG-SPEC is (name value).

(define (arg-list-symbol-arg errtxt arg-spec)
  (arg-list-validate-name errtxt arg-spec)
  (if (or (!= (length (cdr arg-spec)) 1)
	  (not (symbol? (cadr arg-spec))))
      (parse-error errtxt (string-append (car arg-spec)
					 ": argument not a symbol")))
  (cadr arg-spec)
)

; Sanitization

; Sanitization is handled via attributes.  Anything that must be sanitized
; has a `sanitize' attribute with the value being the keyword to sanitize on.
; Ideally most, if not all, of the guts of the generated sanitization is here.

; Utility to simplify expression in .cpu file.
; Usage: (sanitize keyword entry-type entry-name1 [entry-name2 ...])
; Enum attribute `(sanitize keyword)' is added to the entry.
; It's written this way so Hobbit can handle it.

(define (sanitize keyword entry-type . entry-names)
  (for-each (lambda (entry-name)
	      (let ((entry #f))
		(case entry-type
		  ((attr) (set! entry (current-attr-lookup entry-name)))
		  ((enum) (set! entry (current-enum-lookup entry-name)))
		  ((isa) (set! entry (current-isa-lookup entry-name)))
		  ((cpu) (set! entry (current-cpu-lookup entry-name)))
		  ((mach) (set! entry (current-mach-lookup entry-name)))
		  ((model) (set! entry (current-model-lookup entry-name)))
		  ((ifield) (set! entry (current-ifld-lookup entry-name)))
		  ((hardware) (set! entry (current-hw-lookup entry-name)))
		  ((operand) (set! entry (current-op-lookup entry-name)))
		  ((insn) (set! entry (current-insn-lookup entry-name)))
		  ((macro-insn) (set! entry (current-minsn-lookup entry-name)))
		  (else (parse-error "sanitize" "unknown entry type" entry-type)))

		; ENTRY is #f in the case where the element was discarded
		; because its mach wasn't selected.  But in the case where
		; we're keeping everything, ensure ENTRY is not #f to
		; catch spelling errors.

		(if entry

		    (begin
		      (obj-cons-attr! entry (enum-attr-make 'sanitize keyword))
		      ; Propagate the sanitize attribute to class members
		      ; as necessary.
		      (case entry-type
			((hardware)
			 (if (hw-indices entry)
			     (obj-cons-attr! (hw-indices entry)
					     (enum-attr-make 'sanitize
							     keyword)))
			 (if (hw-values entry)
			     (obj-cons-attr! (hw-values entry)
					     (enum-attr-make 'sanitize
							     keyword))))
			))

		    (if (and (eq? APPLICATION 'OPCODES) (keep-all?))
			(parse-error "sanitize"
				     (string-append "unknown " entry-type)
				     entry-name)))))
	    entry-names)

  #f ; caller eval's our result, so return a no-op
)

; Return TEXT sanitized with KEYWORD.
; TEXT must exist on a line (or lines) by itself.
; i.e. it is assumed that it begins at column 1 and ends with a newline.
; If KEYWORD is #f, no sanitization is generated.

(define (gen-sanitize keyword text)
  (cond ((null? text) "")
	((pair? text) ; pair? -> cheap list?
	 (if (and keyword include-sanitize-marker?)
	     (string-list
	      ; split string to avoid removal
	      "/* start-"
	      "sanitize-" keyword " */\n"
	      text
	      "/* end-"
	      "sanitize-" keyword " */\n")
	     text))
	(else
	 (if (= (string-length text) 0)
	     ""
	     (if (and keyword include-sanitize-marker?)
		 (string-append
		  ; split string to avoid removal
		  "/* start-"
		  "sanitize-" keyword " */\n"
		  text
		  "/* end-"
		  "sanitize-" keyword " */\n")
		 text))))
)

; Return TEXT sanitized with OBJ's sanitization, if it has any.
; OBJ may be #f.

(define (gen-obj-sanitize obj text)
  (if obj
      (let ((san (obj-attr-value obj 'sanitize)))
	(gen-sanitize (if (or (not san) (eq? san 'none)) #f san)
		      text))
      (gen-sanitize #f text))
)

; Cover procs to handle generation of object declarations and definitions.
; All object output should be routed through gen-decl and gen-defn.

; Send the gen-decl message to OBJ, and sanitize the output if necessary.

(define (gen-decl obj)
  (logit 3 "Generating decl for "
	 (cond ((method-present? obj 'get-name) (send obj 'get-name))
	       ((elm-present? obj 'name) (elm-get obj 'name))
	       (else "unknown"))
	 " ...\n")
  (cond ((and (method-present? obj 'gen-decl) (not (has-attr? obj 'META)))
	 (gen-obj-sanitize obj (send obj 'gen-decl)))
	(else ""))
)

; Send the gen-defn message to OBJ, and sanitize the output if necessary.

(define (gen-defn obj)
  (logit 3 "Generating defn for "
	 (cond ((method-present? obj 'get-name) (send obj 'get-name))
	       ((elm-present? obj 'name) (elm-xget obj 'name))
	       (else "unknown"))
	 " ...\n")
  (cond ((and (method-present? obj 'gen-defn) (not (has-attr? obj 'META)))
	 (gen-obj-sanitize obj (send obj 'gen-defn)))
	(else ""))
)

; Attributes

; Return C code to declare an enum of attributes ATTRS.
; PREFIX is one of "cgen_ifld", "cgen_hw", "cgen_operand", "cgen_insn".
; ATTRS is an alist of attribute values.  The value is unimportant except that
; it is used to determine bool/non-bool.
; Non-bools need to be separated from bools as they're each recorded
; differently.  Non-bools are recorded in an int for each.  All bools are
; combined into one int to save space.
; ??? We assume there is at least one bool.

(define (gen-attr-enum-decl prefix attrs)
  (string-append
   (gen-enum-decl (string-append prefix "_attr")
		  (string-append prefix " attrs")
		  (string-append prefix "_")
		  (attr-list-enum-list attrs))
   "/* Number of non-boolean elements in " prefix "_attr.  */\n"
   "#define " (string-upcase prefix) "_NBOOL_ATTRS "
   "(" (string-upcase prefix) "_END_NBOOLS - "
   (string-upcase prefix) "_START_NBOOLS - 1)\n"
   "\n")
)

; Return name of symbol ATTR-NAME.
; PREFIX is the prefix arg to gen-attr-enum-decl.

(define (gen-attr-name prefix attr-name)
  (string-upcase (gen-c-symbol (string-append prefix "_" attr-name)))
)

; Normal gen-mask argument to gen-bool-attrs.
; Returns "(1<< PREFIX_NAME)" where PREFIX is from atlist-prefix and
; NAME is the name of the attribute.
; ??? This used to return PREFIX_NAME-CGEN_ATTR_BOOL_OFFSET.
; The tradeoff is simplicity vs perceived maximum number of boolean attributes
; needed.  In the end the maximum number needn't be fixed, and the simplicity
; of the current way is good.

(define (gen-attr-mask prefix name)
  (string-append "(1<<" (gen-attr-name prefix name) ")")
)

; Return C expression of bitmasks of boolean attributes in ATTRS.
; ATTRS is an <attr-list> object, it need not be pre-sorted.
; GEN-MASK is a procedure that returns the C code of the mask.

(define (gen-bool-attrs attrs gen-mask)
  (let loop ((result "0")
	     (alist (attr-remove-meta-attrs-alist
		     (attr-nub (atlist-attrs attrs)))))
    (cond ((null? alist) result)
	  ((and (boolean? (cdar alist)) (cdar alist))
	   (loop (string-append result
				; `|' is used here instead of `+' so we don't
				; have to care about duplicates.
				"|" (gen-mask (atlist-prefix attrs)
					      (caar alist)))
		 (cdr alist)))
	  (else (loop result (cdr alist)))))
)

; Return the C definition of OBJ's attributes.
; TYPE is one of 'ifld, 'hw, 'operand, 'insn.
; [Other objects have attributes but these are the only ones we currently
; emit definitions for.]
; OBJ is any object that supports the 'get-atlist message.
; ALL-ATTRS is an ordered alist of all attributes.
; "ordered" means all the non-boolean attributes are at the front and
; duplicate entries have been removed.
; GEN-MASK is the gen-mask arg to gen-bool-attrs.

(define (gen-obj-attr-defn type obj all-attrs num-non-bools gen-mask)
  (let* ((attrs (obj-atlist obj))
	 (non-bools (attr-non-bool-attrs (atlist-attrs attrs)))
	 (all-non-bools (list-take num-non-bools all-attrs)))
  (string-append
   "{ "
   (gen-bool-attrs attrs gen-mask)
   ", {"
   ; For the boolean case, we can (currently) get away with only specifying
   ; the attributes that are used since they all fit in one int and the
   ; default is currently always #f (and won't be changed without good
   ; reason).  In the non-boolean case order is important since each value
   ; has a specific spot in an array, all of them must be specified.
   (if (null? all-non-bools)
       " 0"
       (string-drop1 ; drop the leading ","
	(string-map (lambda (attr)
		      (let ((val (or (assq-ref non-bools (obj:name attr))
				     (attr-default attr))))
			; FIXME: Are we missing attr-prefix here?
			(string-append ", "
				       (send attr 'gen-value-for-defn val))))
		    all-non-bools)))
   " } }"
   ))
)

; Return a boolean indicating if ATLIST indicates a CTI insn.

(define (atlist-cti? atlist)
  (or (atlist-has-attr? atlist 'UNCOND-CTI)
      (atlist-has-attr? atlist 'COND-CTI))
)

; Misc. gen-* procs

; Return name of obj as a C symbol.

(define (gen-sym obj) (gen-c-symbol (obj:name obj)))

; Return the name of the selected cpu family.
; An error is signalled if more than one has been selected.

(define (gen-cpu-name)
  ; FIXME: error checking
  (gen-sym (current-cpu))
)

; Return HAVE_CPU_<CPU>.

(define (gen-have-cpu cpu)
  (string-append "HAVE_CPU_"
		 (string-upcase (gen-sym cpu)))
)

; Return the bfd mach name for MACH.

(define (gen-mach-bfd-name mach)
  (string-append "bfd_mach_" (gen-c-symbol (mach-bfd-name mach)))
)

; Return definition of C macro to get the value of SYM.

(define (gen-get-macro sym index-args expr)
  (string-append
   "#define GET_" (string-upcase sym) "(" index-args ") " expr "\n")
)

; Return definition of C macro to set the value of SYM.

(define (gen-set-macro sym index-args lvalue)
  (string-append
   "#define SET_" (string-upcase sym)
   "(" index-args
   (if (equal? index-args "") "" ", ")
   "x) (" lvalue " = (x))\n")
)

; Return definition of C macro to set the value of SYM, version 2.
; EXPR is one or more C statements *without* proper \newline handling,
; we prepend \ to each line.

(define (gen-set-macro2 sym index-args newval-arg expr)
  (string-append
   "#define SET_" (string-upcase sym)
   "(" index-args
   (if (equal? index-args "") "" ", ")
   newval-arg ") \\\n"
   "do { \\\n"
   (backslash "\n" expr)
   ";} while (0)\n")
)


; Called before loading the .cpu file to initialize.

(define (utils-init!)
  (reader-add-command! 'sanitize
		       "\
Mark an entry as being sanitized.
"
		       nil '(keyword entry-type . entry-names) sanitize)

  *UNSPECIFIED*
)
