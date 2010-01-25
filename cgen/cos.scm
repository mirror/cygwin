;; Cgen's Object System.
;; Copyright (C) 2000, 2009, 2010 Red Hat, Inc.
;; This file is part of CGEN.
;; See file COPYING.CGEN for details.
;;
;; Scheme implementations don't agree on a lot of things beyond the basics.
;; This is a simple object system for cgen's needs.
;; I thought at the start that when Guile had an official object system
;; we'd switch over, but the higher order bit now is to be usable on
;; multiple Scheme implementations: Guile isn't fast enough.
;;
;; NOTE: The original COS supported multiple inheritance.  This does not.
;;
;; Classes look like:
;;
;; #(class-tag
;;   class-name
;;   class-uid ;; unique id of class, index into /class-table
;;   parent-name
;;   elm-alist ;; not including parent classes
;;   method-alist ;; not including parent classes
;;   full-elm-initial-list ;; including parent classes
;;   method-cache ;; ??? not currently used
;;   class-descriptor)
;;
;; PARENT-NAME is the name of the parent class, if any.
;; If a subclasses b which subclasses c, then parent-name for a is b,
;; the parent-name for b is c, and the parent-name for c is #f.
;;
;; ELM-ALIST is an alist of (symbol vector-offset-with-class . initial-value)
;; for this class only.
;; Values can be looked up by name, via elm-make-[gs]etter routines.
;; Various Lisp (or Lisp-like) OOP systems (e.g. CLOS, Dylan) call these
;; "slots".  Maybe for consistency "slot" would be a better name.  Some might
;; confuse that with intentions at directions though.
;;
;; METHOD-ALIST is an alist of (symbol . procedure) for this class only.
;;
;; FULL-ELM-INITIAL-LIST is the elements of the flattened inheritance tree.
;; Initially it is #f meaning it hasn't been computed yet.
;; It is computed when the class is first instantiated.  During development,
;; it can be reset to #f after some module has been reloaded (as long as no
;; elements have been deleted/added/moved/etc., existing objects are ok).
;;
;; METHOD-CACHE is an alist of the methods of the flattened inheritance
;; tree.  Each element is (symbol . (parent-list-entry . method)).
;; Initially it is #f meaning it hasn't been computed yet.
;; It is computed when the class is first instantiated.  During development,
;; it can be reset to #f after some module has been reloaded (requires all
;; object instantiation to happen later of course).
;; FIXME: We don't yet implement the method cache.
;;
;; CLASS-DESCRIPTOR is the processed form of parent-name-list.
;; There is an entry for the class and one for each parent (recursively):
;; (class offset child-backpointer [parent-descriptor]).
;; offset is the offset in the element vector of the class's elements.
;; child-backpointer is #f in the top level object.
;; ??? child->subclass, parent->superclass?
;; Initially the class-descriptor is #f meaning it hasn't been computed yet.
;; It is computed when the class is first instantiated.  During development,
;; it can be reset to #f after some module has been reloaded (requires all
;; object instantiation to happen later of course).
;;
;; An object is a vector: #(object-tag class-name class-uid elm1 elm2 ...)
;; Vectors are nice in that they're self-evaluating.
;; Both class name and uid are stored here for a better developer experience.
;; It might be better to store the class-descriptor instead, but it's big and
;; vastly reduces the S/N ratio when displaying objects.
;;
;; -----------------------------------------------------------------------------
;;
;; User visible procs/macros:
;;
;; (define-class name prefix parents members)
;;
;; This is a macro that defines several things:
;; - the class object with the specified class members
;; - a predicate to identify instances of this class, named "class?"
;; - getters and setters for each member
;; NAME is the name of the class.
;; Convention requires class names to be decorated as <class-name>.
;; ??? This might change to require the actual class object, but not yet.
;; PREFIX is prepended to member getters/setters.
;; PARENTS is a list of parent class names.
;; It must contain at most one element, multiple inheritance isn't supported.
;; Each element of MEMBERS is either member-name (for uninitialized
;;  elements) or (member-name . initial-value).
;; MEMBER-NAME may begin with modifiers / and !:
;; / - member is private: getter/setter begins with /
;; ! - member is writable: readonly members do not get a setter
;; / and ! may not appear elsewhere in MEMBER-NAME.
;; / and ! may appear in either order.
;;
;; (class-make name parents members unused) -> class
;;
;; Create a class.  The result is then passed back by procedures requiring
;; a class argument.
;; NAME is the name of the class.
;; Convention requires class names to be decorated as <class-name>.
;; PARENTS is a list of parent class names.
;; It must contain at most one element, multiple inheritance isn't supported.
;; ??? This might change to require the actual class object, but not yet.
;; MEMBERS is a list of members, each list member is either a name (for
;; uninitialized elements) or (name . initial-value).
;; UNUSED must be the empty list, it will eventually be deleted.
;;
;; (class-list) -> list of all defined classes
;;
;; (class-name class) -> name of CLASS
;;
;; (class-lookup class-name) -> class
;;
;; (class-instance? class object) -> #t if OBJECT is an instance of CLASS
;;
;; (object-class object) -> class of OBJECT
;;
;; (object-class-name object) -> class name of OBJECT
;;
;; (send object method-name . args) -> result of invoking METHOD-NAME
;;
;; (send-next object class-name method-name . args) -> result of invoking next METHOD-NAME
;;
;; (new class) -> instantiate CLASS
;;
;; The object is initialized with values specified when CLASS
;; (and its parent classes) was defined.
;;
;; (vmake class . args) -> instantiate class and initialize it with 'vmake!
;;
;; This is shorthand for (send (new class) 'vmake! args).
;; ARGS is a list of option names and arguments (a la CLOS).
;; ??? Not implemented yet.
;;
;; (method-vmake! object . args) -> modify OBJECT from ARGS
;;
;; This is the standard 'vmake! method, available for use by user-written
;; 'vmake! methods.
;; ??? Not implemented yet.
;;
;; (make class . args) -> instantiate CLASS and initialize it with 'make!
;;
;; This is shorthand for (send (new class) 'make! arg1 ...).
;; This is a positional form of `new'.
;;
;; (method-make-make! class elm1-name elm2-name ...) -> unspecified
;;
;; Create a 'make! method that sets the specified elements.
;;
;; (object-copy object) -> copy of OBJECT
;;
;; Return a copy of OBJECT.
;; NOTE: This does a shallow copy.
;;
;; (object-assign! dstsrc) -> unspecified
;;
;; Assign the contents of SRC to DST.
;; Both must be objects of the same class.
;;
;; (class? foo) -> return #t if FOO is a class
;;
;; (object? foo) -> return #t if FOO is an object
;;
;; (method-make! class name lambda) -> unspecified
;;
;; Add method NAME to CLASS.
;;
;; (method-make-forward! class elm-name methods) -> unspecified
;;
;; Add METHODS to CLASS that pass the "message" onto the object in element
;; ELM-NAME.
;;
;; (elm-get object elm-name) -> value of element ELM-NAME in OBJ
;;
;; Can only be used in methods.
;;
;; (elm-set! object elm-name new-value) -> unspecified
;;
;; Set element ELM-NAME in OBJECT to NEW-VALUE.
;; Can only be used in methods.
;;
;; (elm-make-getter class elm-name) -> lambda
;;
;; Return efficient lambda to get the value of ELM-NAME in CLASS.
;;
;; (elm-make-setter class elm-name) -> lambda
;;
;; Return efficient lambda to set the value of ELM-NAME in CLASS.
;;
;; Conventions used in this file:
;; - procs/vars internal to this file are prefixed with "/"
;; - except for a few exceptions, public procs/macros begin with one of
;;   define-, class-, object-, elm-, method-.
;;   The exceptions are make, vmake, new, send, send-next.
;;
;; NOTES:
;; - "send" as a public interface is deprecated

(define /class-tag "class")
(define /object-tag "object")

;; Alist of all classes.
;; Each element is (class-name class?-object).
;; Note that classes are consed unto the front.

(define /class-list '())

;; Table of all classes, indexed by class-uid.
;; Note that classes are appended to the end.

(define /class-table '#())

;; Internal variables to mark their respective properties.
(define /object-unspecified #:unspecified)
(define /object-unbound #:unbound)

;; True if error messages are verbose and debugging messages are printed.

(define /object-verbose? #f)

;; Cover fn to set verbosity.

(define (object-set-verbose! verbose?)
  (set! /object-verbose? verbose?)
)

;; Signal error if not class/object.

(define (/class-check maybe-class proc-name . extra-text)
  (if (not (class? maybe-class))
      (apply /object-error
	     (append! (list proc-name maybe-class "not a class")
		      extra-text)))
  /object-unspecified
)

(define (/object-check-name maybe-name proc-name . extra-text)
  (if (not (symbol? maybe-name))
      (apply /object-error
	     (append! (list proc-name maybe-name) extra-text)))
  /object-unspecified
)

(define (/object-check maybe-object proc-name . extra-text)
  (if (not (object? maybe-object))
      (apply /object-error
	     (append! (list proc-name maybe-object "not an object")
		      extra-text)))
  /object-unspecified
)

;; Main routine to flag a cos error.
;; X is any arbitrary Scheme data.

(define (/object-error proc-name x . text)
  (error (string-append proc-name ": "
			(apply string-append (map /object->string text))
			(if (object? x)
			    (string-append
			     " (class: " (/object->string (/object-class-name x))
			     (if (method-present? x 'get-name)
				 (string-append ", name: "
						(/object->string (send x 'get-name)))
				 "")
			     ")")
			    "")
			"")
	 x)
)

;; Utility to count the number of non-#f elements in FLAGS.

(define (/object-count-true flags)
  (let loop ((result 0) (flags flags))
    (if (null? flags)
	result
	(loop (+ result (if (car flags) 1 0))
	      (cdr flags))))
)

;; If S is a symbol, convert it to a string.
;; Otherwise S must be a string, returned unchanged.

(define (/object->string s)
  (cond ((symbol? s) (symbol->string s))
	((string? s) s)
	(else (error "not a symbol or string" s)))
)

;; Low level class operations.

;; Return boolean indicating if X is a class.

(define (class? class)
  (and (vector? class) (eq? /class-tag (vector-ref class 0)))
)

;; Accessors.

(define (/class-name class) (vector-ref class 1))
(define (/class-uid class) (vector-ref class 2))
(define (/class-parent-name class) (vector-ref class 3))
(define (/class-elements class) (vector-ref class 4))
(define (/class-methods class) (vector-ref class 5))
(define (/class-all-initial-values class) (vector-ref class 6))
(define (/class-method-cache class) (vector-ref class 7))
(define (/class-class-desc class) (vector-ref class 8))

(define (/class-set-uid! class uid)
  (vector-set! class 2 uid)
)

(define (/class-set-methods! class method-alist)
  (vector-set! class 5 method-alist)
)

(define (/class-set-all-initial-values! class init-list)
  (vector-set! class 6 init-list)
)

(define (/class-set-method-cache! class all-meth-list)
  (vector-set! class 7 all-meth-list)
)

(define (/class-set-class-desc! class parent-list)
  (vector-set! class 8 parent-list)
)

;; Make a class.
;; The new definition overrides any existing definition.

(define (/class-make! name parent-name elements)
  (let ((class (vector /class-tag name
		       #f ;; uid filled in later
		       parent-name elements
		       '() ;; methods, none yet
		       #f #f #f))
	(list-entry (assq name /class-list)))
    (if list-entry
	(let ((uid (/class-uid (cdr list-entry))))
	  (/class-set-uid! class uid)
	  (set-cdr! list-entry class))
	(let ((uid (vector-length /class-table)))
	  (/class-set-uid! class uid)
	  (set! /class-table (list->vector
			      (append (vector->list /class-table)
				      (list class))))
	  (set! /class-list (acons name class /class-list))))
    class)
)

;; Lookup a class given its name.
;; The result is the class or #f if not found.

(define (class-lookup name) (assq-ref /class-list name))

;; Lookup a class given its uid.

(define (/class-lookup-uid uid) (vector-ref /class-table uid))

;; Return a list of all direct parent classes of CLASS.
;; The list can have at most one element.
;; this is for callers that prefer a list result.

(define (/class-parent-classes class)
  (if (/class-parent-name class)
      (let ((parent (class-lookup (/class-parent-name class))))
	(if parent
	    (list parent)
	    ;; The proc name we pass here is made up as we don't
	    ;; want it to be the name of an internal proc.
	    (/object-error "class" parent "not a class")))
      '())
)

;; Cover proc of /class-name for the outside world to use.
;; The result is the name of the class or #f if CLASS is not a class.
;; We could issue an error here, but to be consistent with object-class-name
;; we don't.

(define (class-name class)
  (if (class? class)
      (/class-name class)
      #f)
)

;; Class descriptor utilities.
;; A class-descriptor is:
;; (class offset child-backpointer [parent-descriptor])

(define (/class-desc? maybe-class-desc)
  (and (pair? maybe-class-desc)
       (class? (car maybe-class-desc)))
)
(define /class-desc-class car)
(define /class-desc-offset cadr)
(define /class-desc-child caddr)
(define /class-desc-parents cdddr) ;; nil or list of one element

;; Compute the class descriptor of CLASS.
;; OFFSET is the beginning offset in the element vector.
;; We can assume the parents of CLASS have already been initialized.
;;
;; A class-descriptor is:
;; (class offset child (parent-entry))
;; CLASS is the class? data structure of the class.
;; OFFSET is the offset into the object vector of the baseclass's elements.
;; CHILD is the backlink to the direct child class or #f if no subclass.
;; PARENT-ENTRY is the class descriptor of the parent class.

(define (/class-compute-class-desc class offset child)

  ;; OFFSET must be global to the calculation because it is continually
  ;; incremented as we recurse down through the hierarchy (actually, as we
  ;; traverse back up).  At any point in time it is the offset from the start
  ;; of the element vector of the next class's elements.
  ;; Object elements are laid out using a depth first traversal of the
  ;; inheritance tree.

  (define (compute1 class child)

    ;; Build the result first, then build our parents so that our parents have
    ;; the right value for the CHILD-BACKPOINTER field.
    ;; FIXME: Can't assume append! works that way.
    ;; Use a bogus value (999) for offset for the moment.
    ;; The correct value is set later.

    (let ((result (list class 999 child)))

      ;; Recurse on the parent.

      (if (/class-parent-name class)
	  (let ((parent (class-lookup (/class-parent-name class))))
	    (if (not parent)
		;; The proc name we pass here is made up as we don't
		;; want it to be the name of an internal proc.
		(/object-error "class" (car parents) "not a class"))

	    (let ((parent-desc (compute1 parent result)))

	      ;; We use `append!' here as the location of `result' is now fixed
	      ;; so that our parent's child-backpointer remains stable.
	      (append! result (list parent-desc)))))

      (list-set! result 1 offset)
      (set! offset (+ offset (length (/class-elements class))))
      result))

  (compute1 class child)
)

;; Return the top level class-descriptor of CLASS-DESC.

(define (/class-desc-top class-desc)
  (if (/class-desc-child class-desc)
      (/class-desc-top (/class-desc-child class-desc))
      class-desc)
)

;; Pretty print a class descriptor.

(define (class-desc-dump class-desc)
  (let* ((cep (current-error-port))
	 (top-desc (/class-desc-top class-desc))
	 (spaces (lambda (n port)
		   (display (make-string n #\space) port)))
	 (writeln (lambda (indent port . args)
		    (spaces indent port)
		    (for-each (lambda (arg) (display arg port))
			      args)
		    (newline port)))
	 )
    (letrec ((dump (lambda (cd indent)
		     (writeln indent cep "Class: "
			      (/class-name (/class-desc-class cd)))
		     (writeln indent cep "  offset: "
			      (/class-desc-offset cd))
		     (writeln indent cep "  child:       "
			      (if (/class-desc-child cd)
				  (/class-name (/class-desc-class
						(/class-desc-child cd)))
				  "-top-"))
		     (for-each (lambda (parent-cd) (dump parent-cd (+ indent 4)))
			       (/class-desc-parents cd))
		     )))
      (display "Top level class: " cep)
      (display (/class-name (/class-desc-class top-desc)) cep)
      (newline cep)
      (dump class-desc 0)
      ))
)

;; Low level object utilities.

;; Make an object.
;; All elements get initial (or unbound) values.

(define (/object-make! class)
  (/class-check-init! class)
  (apply vector (append! (list /object-tag
			       (/class-name class)
			       (/class-uid class))
			 (/class-all-initial-values class)))
)

;; Make an object using VALUES.
;; VALUES must specify all elements in the class (and parent classes).

(define (/object-make-with-values! class values)
  (/class-check-init! class)
  (apply vector (append! (list /object-tag
			       (/class-name class)
			       (/class-uid class))
			 values))
)

;; Copy an object.
;; WARNING: A shallow copy is currently done on the elements!

(define (/object-copy obj)
  (/object-vector-copy obj)
)

;; Accessors.

(define (/object-class-name obj) (vector-ref obj 1))
(define (/object-class-uid obj) (vector-ref obj 2))

(define (/object-class-desc obj)
  (/class-class-desc (/object-class obj))
)

(define (/object-class obj)
  (/class-lookup-uid (/object-class-uid obj))
)

(define (/object-elm-get obj elm-offset)
  (vector-ref obj elm-offset)
)

(define (/object-elm-set! obj elm-offset new-val)
  (vector-set! obj elm-offset new-val)
  /object-unspecified
)

;; Return boolean indicating if X is an object.

(define (object? obj)
  (and (vector? obj)
       (>= (vector-length obj) 3)
       (eq? /object-tag (vector-ref obj 0)))
)

;; Return the class of an object.

(define (object-class obj)
  (/object-check obj "object-class")
  (/object-class obj)
)

;; Cover proc of /object-class-name for the outside world to use.
;; The result is the name of the class or #f if OBJ is not an object.

(define (object-class-name obj)
  (if (object? obj)
      (/object-class-name obj)
      #f)
)

;; Class operations.

;; Return the list of initial values for CLASS.
;; The result does not include parent classes.

(define (/class-my-initial-values class)
  (map cadr (/class-elements class))
)

;; Initialize class if not already done.
;; FIXME: Need circularity check.  Later.

(define (/class-check-init! class)
  ;; This should be fast the second time through, so don't do any
  ;; computation until we know it's necessary.

  (if (/class-all-initial-values class)

      #t ;; nothing to do

      (begin

	;; First pass ensures all parents are initialized.
	(for-each /class-check-init!
		  (/class-parent-classes class))

	;; Next pass initializes the initial value list.
	(letrec ((get-inits
		  (lambda (class)
		    (let ((parents (/class-parent-classes class)))
		      (append (apply append (map get-inits parents))
			      (/class-my-initial-values class))))))

	  (let* ((parents (/class-parent-classes class))
		 (inits (append (apply append (map get-inits parents))
				(/class-my-initial-values class))))
	    (/class-set-all-initial-values! class inits)))

	;; Next pass initializes the class's class-descriptor.
	;; Object elements begin at offset 3 in the element vector.
	(/class-set-class-desc! class
				(/class-compute-class-desc class 3 #f))
	))

  /object-unspecified
)

;; Make a class.
;;
;; PARENTS is the name of parent class as a list, i.e. () or (<parent>).
;; It's a list just in case multiple-inheritance is added one day.
;; The parent need not exist yet, though it must exist when the class
;; is first instantiated.
;; ELMS is a either a list of either element names or name/value pairs.
;; Elements without initial values are marked as "unbound".
;; UNUSED must be the empty list, it will eventually be deleted.

(define (class-make name parents elms unused)
  (if (> (length parents) 1)
      (/object-error "class-make" parents "multiple-inheritance is not supported"))
  (if (not (null? unused))
      (/object-error "class-make" methods "unused parameter must be ()"))

  (let ((elm-list #f))

    ;; Mark elements without initial values as unbound, and
    ;; compute indices into the element vector (relative to the class's
    ;; offset).
    ;; Elements are recorded as (symbol initial-value . vector-index)
    (let loop ((elm-list-tmp '()) (index 0) (elms elms))
      (if (null? elms)
	  (set! elm-list (reverse! elm-list-tmp)) ;; done
	  (if (pair? (car elms))
	      (loop (acons (caar elms)
			   (cons (cdar elms) index)
			   elm-list-tmp)
		    (+ index 1)
		    (cdr elms))
	      (loop (acons (car elms)
			   (cons /object-unbound index)
			   elm-list-tmp)
		    (+ index 1)
		    (cdr elms)))))

    (let ((result (/class-make! name
				(if (null? parents) #f (car parents))
				elm-list)))

      ;; Create the standard `make!' method.
      ;; The caller can override afterwards if desired.
      ;; Note that if there are any parent classes then we don't know the names
      ;; of all of the elements yet, that is only known after the class has been
      ;; initialized which only happens when the class is first instantiated.
      ;; This method won't be called until that happens though so we're safe.
      ;; This is written without knowledge of the names, it just initializes
      ;; all elements.
      (method-make! result 'make!
		    (lambda args
		      (let ((self (car args)))
			;; Ensure exactly all of the elements are provided.
			(if (not (= (length args)
				    (- (vector-length self) 2)))
			    (/object-error "make!" "" "wrong number of arguments to method `make!'"))
			(/object-make-with-values! (/object-class self)
						   (cdr args)))))

      result))
)

;; Create an object of a class CLASS.

(define (new class)
  (/class-check class "new")

  (if /object-verbose?
      (display (string-append "Instantiating class " (/class-name class) ".\n")
	       (current-error-port)))

  (/object-make! class)
)

;; Make a copy of OBJ.
;; WARNING: A shallow copy is done on the elements!

(define (object-copy obj)
  (/object-check obj "object-copy")
  (/object-copy obj)
)

;; Assign object SRC to object DST.
;; They must have the same class.

(define (object-assign! dst src)
  (/object-check dst "object-assign!")
  (/object-check src "object-assign!")
  (if (not (eq? (/object-class-name dst) (/object-class-name src)))
      (/object-error "object-assign" (list dst src) "not same class"))

  (let ((n (vector-length dst)))
    (let loop ((i 0))
      (if (< i n)
	  (begin
	    (vector-set! dst i (vector-ref src i))
	    (loop (+ i 1))))))
  /object-unspecified
)

;; Utility to define a standard `make!' method.
;; A standard make! method is one in which all it does is initialize
;; fields from args.

(define (method-make-make! class args)
  (let ((lambda-expr
	 (append (list 'lambda (cons 'self args))
		 (map (lambda (elm) (list 'elm-set! 'self
					  (list 'quote elm) elm))
		      args)
		 '(self))))
    (method-make! class 'make! (eval1 lambda-expr)))
)

;; The "standard" way to invoke `make!' is (send (new class) 'make! ...).
;; This puts all that in a cover function.

(define (make class . operands)
  (apply send (append (cons (new class) '()) '(make!) operands))
)

;; Return #t if class X is a subclass of BASE-NAME.

(define (/class-subclass? base-name x)
  (if (eq? base-name (/class-name x))
      #t
      (let ((parent-name (/class-parent-name x)))
	(if parent-name
	    (/class-subclass? base-name (class-lookup parent-name))
	    #f)))
)

;; Return #t if OBJECT is an instance of CLASS.
;; This does not signal an error if OBJECT is not an object as this is
;; intended to be used in class predicates.

(define (class-instance? class object)
  (/class-check class "class-instance?")
  (if (object? object)
      (/class-subclass? (/class-name class) (/object-class object))
      #f)
)

;; Subroutine of define-class.
;; Parse a define-class member list and return a list of five elements:
;; - list of all members
;; - list of public readable members
;; - list of public writable members
;; - list of private readable members
;; - list of private writable members
;; MEMBER-SPEC is a list of members, with private members prefixed with '/',
;; and writable members prefixed with '!'.  / and ! may appear in any order.
;; Each element is either member-name or (member-name . initial-value).

(define (/parse-member-list member-spec)
  (let loop ((member-spec member-spec)
	     (members nil)
	     (public-readable nil)
	     (public-writable nil)
	     (private-readable nil)
	     (private-writable nil))
    (if (null? member-spec)
	(list (reverse! members)
	      (reverse! public-readable)
	      (reverse! public-writable)
	      (reverse! private-readable)
	      (reverse! private-writable))
	(let* ((spec (car member-spec))
	       (sym (if (pair? spec) (car spec) spec))
	       (str (symbol->string sym)))
	  (let ((private? (string-index str #\/))
		(writable? (string-index str #\!)))
	    ;; ??? Assumes /,! are first characters.
	    (let* ((stripped-str (substring str (/object-count-true (list private? writable?))))
		   (stripped-sym (string->symbol stripped-str)))
	      (loop (cdr member-spec)
		    ;; Combine initial value if present.
		    (cons (if (pair? spec)
			      (cons stripped-sym (cdr spec))
			      stripped-sym)
			  members)
		    (if (not private?)
			(cons stripped-sym public-readable)
			public-readable)
		    (if (and (not private?) writable?)
			(cons stripped-sym public-writable)
			public-writable)
		    (if private?
			(cons stripped-sym private-readable)
			private-readable)
		    (if (and private? writable?)
			(cons stripped-sym private-writable)
			private-writable)))))))
)

;; Subroutine of define-class.
;; Return a list of definitions of member getters.

(define (/build-getter-defs class prefix members private?)
  (let ((str-prefix (symbol->string prefix)))
    (cons 'begin
	  (map (lambda (m)
		 (let* ((elm-name (if (pair? m) (car m) m))
			(name (string-append (if private? "/" "")
					     str-prefix
					     (symbol->string elm-name)))
			(getter-name (string->symbol name)))
		   `(define ,getter-name
		      (elm-make-getter ,class (quote ,elm-name)))))
	       members)))
)

;; Subroutine of define-class.
;; Return a list of definitions of member getters.

(define (/build-setter-defs class prefix members private?)
  (let ((str-prefix (symbol->string prefix)))
    (cons 'begin
	  (map (lambda (m)
		 (let* ((elm-name (if (pair? m) (car m) m))
			(name (string-append (if private? "/" "")
					     str-prefix
					     "set-"
					     (symbol->string elm-name)
					     "!"))
			(getter-name (string->symbol name)))
		   `(define ,getter-name
		      (elm-make-setter ,class (quote ,elm-name)))))
	       members)))
)

;; Main routine to define a class.
;;
;; This defines several things:
;; - the class object with the specified class members
;; - a predicate to identify instances of this class, named "class?"
;; - getters and setters for each member
;;
;; Private members are specified as /member.
;; Writable members are specified as !member.
;; / and ! may be combined in any order.
;;
;; By convention name is formatted as <class-name>.

(defmacro define-class (name prefix parents members)
  (let* ((parsed-members (/parse-member-list members))
	 (str-name (symbol->string name))
	 (str-name-len (string-length str-name))
	 (name-sans-decorations (substring str-name 1 (- str-name-len 1))))
    ;; Enforce the <class> naming convention.
    (if (or (not (eq? (string-ref str-name 0) #\<))
	    (not (eq? (string-ref str-name (- str-name-len 1)) #\>)))
	(/object-error "define-class" name " not formatted as <class>: "))
    `(begin
       (define ,name (class-make (quote ,name) (quote ,parents) (quote ,(car parsed-members)) nil))
       ,(/build-getter-defs name prefix (list-ref parsed-members 1) #f)
       ,(/build-setter-defs name prefix (list-ref parsed-members 2) #f)
       ,(/build-getter-defs name prefix (list-ref parsed-members 3) #t)
       ,(/build-setter-defs name prefix (list-ref parsed-members 4) #t)
       (define ,(string->symbol (string-append name-sans-decorations "?"))
	 (lambda (obj) (class-instance? ,name obj)))))
)

;; Element operations.

;; Lookup an element in a class-desc.
;; The result is elm-index or #f if not found.

(define (/class-lookup-element class-desc elm-name)
  (let* ((class (/class-desc-class class-desc))
	 (elm (assq elm-name (/class-elements class))))
    (if elm
	(+ (cddr elm) ;; elm is (name init-value . index)
	   (/class-desc-offset class-desc))
	(let ((parents (/class-desc-parents class-desc)))
	  (if (null? parents)
	      #f
	      (/class-lookup-element (car parents) elm-name)))))
)

;; Return a boolean indicating if ELM-NAME is bound in OBJ.

(define (elm-bound? obj elm-name)
  (/object-check obj "elm-bound?")
  (let ((index (/class-lookup-element (/object-class-desc obj) elm-name)))
    (if index
	(not (eq? (/object-elm-get obj index) /object-unbound))
	(/object-error "elm-bound?" obj "element not present: " elm-name)))
)

;; Subroutine of elm-get.

(define (/elm-make-method-getter self elm-name)
  (/object-check self "elm-get")
  (let ((index (/class-lookup-element (/object-class-desc self) elm-name)))
    (if index
	(procedure->memoizing-macro
	 (lambda (exp env)
	   `(lambda (obj)
	      (/object-elm-get obj ,index))))
	(/object-error "elm-get" self "element not present: " elm-name)))
)

;; Get an element from an object.
;; If OBJ is `self' then the caller is required to be a method and we emit
;; memoized code.  Otherwise we do things the slow way.
;; ??? There must be a better way.
;; What this does is turn
;; (elm-get self 'foo)
;; into
;; ((/elm-make-method-get self 'foo) self)
;; Note the extra set of parens.  /elm-make-method-get then does the lookup of
;; foo and returns a memoizing macro that returns the code to perform the
;; operation with O(1).  Cute, but I'm hoping there's an easier/better way.

(defmacro elm-get (self elm-name)
  (if (eq? self 'self)
      `(((/elm-make-method-getter ,self ,elm-name)) ,self)
      `(elm-xget ,self ,elm-name))
)

;; Subroutine of elm-set!.

(define (/elm-make-method-setter self elm-name)
  (/object-check self "elm-set!")
  (let ((index (/class-lookup-element (/object-class-desc self) elm-name)))
    (if index
	(procedure->memoizing-macro
	 (lambda (exp env)
	   `(lambda (obj new-val)
	      (/object-elm-set! obj ,index new-val))))
	(/object-error "elm-set!" self "element not present: " elm-name)))
)

;; Set an element in an object.
;; This can only be used by methods.
;; See the comments for `elm-get'!

(defmacro elm-set! (self elm-name new-val)
  (if (eq? self 'self)
      `(((/elm-make-method-setter ,self ,elm-name)) ,self ,new-val)
      `(elm-xset! ,self ,elm-name ,new-val))
)

;; Get an element from an object.
;; This is for invoking from outside a method, and without having to
;; use elm-make-getter.  It should be used sparingly.

(define (elm-xget obj elm-name)
  (/object-check obj "elm-xget")
  (let ((index (/class-lookup-element (/object-class-desc obj) elm-name)))
    (if index
	(/object-elm-get obj index)
	(/object-error "elm-xget" obj "element not present: " elm-name)))
)

;; Set an element in an object.
;; This is for invoking from outside a method, and without having to
;; use elm-make-setter.  It should be used sparingly.

(define (elm-xset! obj elm-name new-val)
  (/object-check obj "elm-xset!")
  (let ((index (/class-lookup-element (/object-class-desc obj) elm-name)))
    (if index
	(/object-elm-set! obj index new-val)
	(/object-error "elm-xset!" obj "element not present: " elm-name)))
)

;; Return a boolean indicating if object OBJ has element ELM-NAME.

(define (elm-present? obj elm-name)
  (/object-check obj "elm-present?")
  (->bool (/class-lookup-element (/object-class-desc obj) elm-name))
)

;; Return lambda to get element ELM-NAME in CLASS.
;; FIXME: validate elm-name.

(define (elm-make-getter class elm-name)
  (/class-check class "elm-make-getter")
  ;; We use delay here as we can't assume parent classes have been
  ;; initialized yet.
  (let ((fast-index (delay (/class-lookup-element
			    (/class-class-desc class) elm-name))))
    (lambda (obj)
      (let ((index (force fast-index)))
	(/object-elm-get obj index))))
)

;; Return lambda to set element ELM-NAME in CLASS.
;; FIXME: validate elm-name.

(define (elm-make-setter class elm-name)
  (/class-check class "elm-make-setter")
  ;; We use delay here as we can't assume parent classes have been
  ;; initialized yet.
  (let ((fast-index (delay (/class-lookup-element
			    (/class-class-desc class) elm-name))))
    (lambda (obj newval)
      (let ((index (force fast-index)))
	(/object-elm-set! obj index newval))))
)

;; Method operations.

;; Lookup the next method in a class.
;; This means begin the search in the parent.

(define (/method-lookup-next class-desc method-name)
  (let ((parent-descs (/class-desc-parents class-desc)))
    (if (null? parent-descs)
	#f
	(let ((parent-desc (car parent-descs)))
	  (/method-lookup parent-desc method-name))))
)

;; Lookup a method in a class.
;; The result is (class-desc . method).  If the method is found in a parent
;; class, the associated parent class descriptor is returned.

(define (/method-lookup class-desc method-name)
  (if /object-verbose?
      (display (string-append "Looking up method " method-name " in "
			      (/class-name (/class-desc-class class-desc)) ".\n")
	       (current-error-port)))

  (let ((meth (assq method-name (/class-methods (/class-desc-class class-desc)))))
    (if meth
	;; Found.
	(cons class-desc (cdr meth))
	;; Method not found, search parents.
	(/method-lookup-next class-desc method-name)))
)

;; Return a boolean indicating if object OBJ has method NAME.

(define (method-present? obj name)
  (/object-check obj "method-present?")
  (->bool (/method-lookup (/object-class-desc obj) name))
)

;; Add a method to a class.

(define (method-make! class method-name method)
  (/class-check class "method-make!")
  (/object-check-name method-name "method-make!" "method-name must be a symbol")
  (if (not (procedure? method))
      (/object-error "method-make!" method "method must be a procedure"))
  (/class-set-methods! class (acons method-name method
				    (/class-methods class)))
  /object-unspecified
)

;; Utility to create "forwarding" methods.
;; METHODS are forwarded to class member ELM-NAME, assumed to be an object.
;; The created methods take a variable number of arguments.
;; Argument length checking will be done by the receiving method.
;; FIXME: ensure elm-name is a symbol

(define (method-make-forward! class elm-name methods)
  (for-each (lambda (method-name)
	      (method-make!
	       class method-name
	       (eval1 `(lambda args
			 (apply send
				(cons (elm-get (car args)
					       (quote ,elm-name))
				      (cons (quote ,method-name)
					    (cdr args))))))))
	    methods)
  /object-unspecified
)

;; Utility of send, send-next.

(define (/object-method-notify obj method-name maybe-next)
  (set! /object-verbose? #f)
  (display (string-append "Sending " maybe-next method-name " to"
			  (if (method-present? obj 'get-name)
			      (let ((name (send obj 'get-name)))
				(if (or (symbol? name) (string? name))
				    (string-append " object " name)
				    ""))
			      "")
			  " class " (object-class-name obj) ".\n")
	   (current-error-port))
  (set! /object-verbose? #t)
)

;; Invoke a method in an object.
;; When the method is invoked, the (possible parent class) object in which the
;; method is found is passed to the method.
;; ??? The word `send' comes from "sending messages".  Perhaps should pick
;; a better name for this operation, except this is deprecated as a public API.

(define (send obj method-name . args)
  (/object-check obj "send")
  (if /object-verbose? (/object-method-notify obj method-name ""))

  (let ((class-desc.meth (/method-lookup (/object-class-desc obj)
					 method-name)))
    (if class-desc.meth
	(apply (cdr class-desc.meth)
	       (cons obj args))
	(/object-error "send" obj "method not supported: " method-name)))
)

;; Invoke the next method named METHOD-NAME in the heirarchy of OBJ.
;; i.e. the method that would have been invoked if the calling method
;; didn't exist.
;; CLASS-NAME is the class of the invoking method.
;; It is present to simplify things: otherwise we have to either include in
;; objects the notion a current class or specialization, or include the class
;; as an argument to methods.
;; This may only be called by a method.
;; ??? Ideally we shouldn't need either CLASS-NAME or METHOD-NAME arguments.
;; They could be removed with a bit of effort, but is it worth it?
;; One possibility is if method-make! was a macro, then maybe send-next could
;; work with method-make! and get the values from it.
;;
;; While `send' is deprecated, this is not, yet anyway.

(define (send-next obj class-name method-name . args)
  (/object-check obj "send-next")
  (if /object-verbose? (/object-method-notify obj method-name "next "))

  (let* ((class (class-lookup class-name)) ;; FIXME: slow
	 (class-desc.meth (/method-lookup-next (/class-class-desc class)
					       method-name)))
    (if class-desc.meth
	(apply (cdr class-desc.meth)
	       (cons obj args))
	(/object-error "send-next" obj "method not supported: " method-name)))
)

;; Create an interface.
;; This defines a function named NAME that invokes METHOD-NAME.

(defmacro define-interface (name method-name . arg-list)
  `(define (,name object ,@arg-list)
     (send object (quote ,method-name) ,@arg-list))
)

;; Wrapper to define a method.
;; `self' must be the first argument.

(defmacro define-method (class name args . body)
  `(method-make! ,class (quote ,name) ,(cons 'lambda (cons args body)))
)

;; Miscellaneous publically accessible utilities.

;; Return list of all classes.

(define (class-list) (map cdr /class-list))

;; Utility to map over a class and all its parent classes, recursively.

(define (class-map-over-class proc class)
  (cons (proc class)
	(map (lambda (class) (class-map-over-class proc class))
	     (/class-parent-classes class)))
)

;; Return class tree of a class or object.

(define (class-tree class-or-object)
  (cond ((class? class-or-object)
	 (class-map-over-class class-name class-or-object))
	((object? class-or-object)
	 (class-map-over-class class-name (/object-class class-or-object)))
	(else (/object-error "class-tree" class-or-object
			     "not a class or object")))
)

;; Return names of each alist.

(define (/class-alist-names class)
  (list (/class-name class)
	(map car (/class-elements class))
	(map car (/class-methods class)))
)

;; Return complete layout of class-or-object.

(define (class-layout class-or-object)
  (cond ((class? class-or-object)
	 (class-map-over-class /class-alist-names class-or-object))
	((object? class-or-object)
	 (class-map-over-class /class-alist-names (/object-class class-or-object)))
	(else (/object-error "class-layout" class-or-object
			     "not a class or object")))
)

;; Define the getter for a list of elements of a class.

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

;; Define the setter for a list of elements of a class.

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

;; Make an object, specifying values for particular elements.

(define (vmake class . args)
  (let ((obj (new class)))
    (let ((unrecognized (send obj 'vmake! args)))
      (if (null? unrecognized)
	  obj
	  (error "vmake: unknown options:" unrecognized))))
)

;; Like assq but based on the `name' element.
;; WARNING: Slow.

(define (object-assq name obj-list)
  (find-first (lambda (o) (eq? (elm-xget o 'name) name))
	      obj-list)
)

;; Like memq but based on the `name' element.
;; WARNING: Slow.

(define (object-memq name obj-list)
  (let loop ((r obj-list))
    (cond ((null? r) #f)
	  ((eq? name (elm-xget (car r) 'name)) r)
	  (else (loop (cdr r)))))
)

;; Misc. internal utilities.

;; We need a fast vector copy operation.
;; If `vector-copy' doesn't exist (which is assumed to be the fast one),
;; provide a simple version.

(if (defined? 'vector-copy)
    (define /object-vector-copy vector-copy)
    (define (/object-vector-copy v) (list->vector (vector->list v)))
)
