; Instruction definitions.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; Class to hold an insn.

(define <insn>
  (class-make '<insn>
	      '(<ident>)
	      '(
		; Used to explicitly specify mnemonic, now it's computed from
		; syntax string.  ??? Might be useful as an override someday.
		;mnemonic

		; Instruction syntax string.
		syntax

		; The insn fields as specified in the .cpu file.
		; Also contains values for constant fields.
		iflds
		(iflds-values . #f) ; Lazily computed cache

		; RTL source of assertions of ifield values or #f if none.
		; This is used, for example, by the decoder to help
		; distinguish what would otherwise be an ambiguity in the
		; specification.  It is also used by decode-split support.
		; ??? It could also be used the the assembler/disassembler
		; some day.
		(ifield-assertion . #f)

		; The <fmt-desc> of the insn.
		; This is used to help calculate the ifmt,sfmt members.
		fmt-desc

		; The <iformat> of the insn.
		ifmt

		; The <sformat> of the insn.
		sfmt

		; Temp slot for use by applications.
		; ??? Will go away in time.
		tmp

		; Instruction semantics.
		; This is the rtl in source form or #f if there is none.
		;
		; There are a few issues (ick, I hate that word) to consider
		; here:
		; - some apps don't need the trap checks (e.g. SIGSEGV)
		; - some apps treat the pieces in different ways
		; - the simulator tries to merge common fragments among insns
		;   to reduce code size in a pbb simulator
		;
		; Some insns don't have any semantics at all, they are defined
		; in another insn [akin to anonymous patterns in gcc].  wip.
		;
		; ??? GCC-like apps will need a new field to allow specifying
		; the semantics if a different value is needed.  wip.
		; ??? May wish to put this and the compiled forms in a
		; separate class.
		; ??? Contents of trap expressions is wip.  It will probably
		; be a sequence with an #:errchk modifier or some such.
		(semantics . #f)

		; The processed form of the above.
		; Each element of rtl is replaced with the associated object.
		(compiled-semantics . #f)

		; The mapping of the semantics onto the host.
		; FIXME: Not sure what its value will be.
		; Another thing that will be needed is [in some cases] a more
		; simplified version of the RTL for use by apps like compilers.
		; Perhaps that's what this will become.
		host-semantics

		; The function unit usage of the instruction.
		timing
		)
	      nil)
)

(method-make-make! <insn>
		   '(name comment attrs syntax iflds ifield-assertion
			  semantics timing)
)

; Accessor fns

(define-getters <insn> insn
  (syntax iflds ifield-assertion fmt-desc ifmt sfmt tmp
	  semantics compiled-semantics host-semantics timing)
)

(define-setters <insn> insn
  (fmt-desc ifmt sfmt ifield-assertion compiled-semantics)
)

; Return a boolean indicating if X is an <insn>.

(define (insn? x) (class-instance? <insn> x))

; Return a list of the machs that support INSN.

(define (insn-machs insn)
  nil ; ??? wip
)

; Return the length of INSN in bits.

(define (insn-length insn)
  (ifmt-length (insn-ifmt insn))
)

; Return the length of INSN in bytes.

(define (insn-length-bytes insn)
  (bits->bytes (insn-length insn))
)

; Return instruction mnemonic.
; This is computed from the syntax string.
; The mnemonic, as we define it, is everything up to, but not including, the
; first space or '$'.
; FIXME: Rename to syntax-mnemonic, and take a syntax string argument.

(define (insn-mnemonic insn)
  (letrec ((mnem-len (lambda (str len)
		       (cond ((= (string-length str) 0) len)
			     ((char=? #\space (string-ref str 0)) len)
			     ((char=? #\$ (string-ref str 0)) len)
			     (else (mnem-len (string-drop1 str) (+ len 1)))))))
    (string-take (mnem-len (insn-syntax insn) 0) (insn-syntax insn)))
)

; Return enum cgen_insn_types value for INSN.

(define (insn-enum insn)
  (string-upcase (string-append "@ARCH@_INSN_" (gen-sym insn)))
)

; Return enum for insn named INSN-NAME.
; This is needed for the `invalid' insn, there is no object for it.
; [Though obviously having such an object seems like a good idea.]

(define (gen-insn-enum insn-name)
  (string-upcase (string-append "@ARCH@_INSN_" (gen-c-symbol insn-name)))
)

; Insns with derived operands (see define-derived-operand).
; ??? These are [currently] recorded separately to minimize impact on existing
; code while the design is worked out.
;
; The class is called <multi-insn> because the insn has multiple variants,
; one for each combination of "anyof" alternatives.
; Internally we create one <insn> per alternative.  The theory is that this
; will remain an internal implementation issue.  When appropriate applications
; will collapse the number of insns in a way that is appropriate for them.
;
; ??? Another way to do this is with insn templates.  One problem the current
; way has is that it requires each operand's assembler syntax to be self
; contained (one way to fix this is to use "fake" operands like before).
; Insn templates needn't have this problem.  On the other hand insn templates
; [seem to] require more description file entries.
;
; ??? This doesn't use all of the members of <insn>.
; The <multi-insn> class is wip, but should eventually reorganize <insn>.
; This reorganization might also take into account real, virtual, etc. insns.

(define <multi-insn>
  (class-make '<multi-insn>
	      '(<insn>)
	      '(
		; An <insn> is created for each combination of "anyof"
		; alternatives.  They are recorded with other insns, but a
		; list of them is recorded here as well.
		; This is #f if the sub-insns haven't been instantiated yet.
		(sub-insns . #f)
		)
	      nil)
)

(method-make-make! <multi-insn>
		   '(name comment attrs syntax iflds ifield-assertion
			  semantics timing)
)

(define-getters <multi-insn> multi-insn (sub-insns))

; Return a boolean indicating if X is a <multi-insn>.

(define (multi-insn? x) (class-instance? <multi-insn> x))

; Subroutine of -sub-insn-make! to create the ifield list.
; Return encoding of {insn} with each element of {anyof-operands} replaced
; with {new-values}.
; {value-names} is a list of names of {anyof-operands}.

(define (-sub-insn-ifields insn anyof-operands value-names new-values)
  ; (debug-repl-env insn anyof-operands value-names new-values)

  ; Delete ifields of {anyof-operands} and add those for {new-values}.
  (let ((iflds
	 (append!
	  ; Delete ifields in {anyof-operands}.
	  (find (lambda (f)
		  (not (and (ifld-anyof-operand? f)
			    (memq (obj:name (ifld-get-value f))
				  value-names))))
		(insn-iflds insn))
	  ; Add ifields for {new-values}.
	  (map derived-encoding new-values)))

	; Return the last ifield of OWNER in IFLD-LIST.
	; OWNER is the object that owns the <ifield> we want.
	; For ifields, the owner is the ifield itself.
	; For operands, the owner is the operand.
	; For derived operands, the owner is the "anyof" parent.
	; IFLD-LIST is an unsorted list of <ifield> elements.
	(find-preceder
	 (lambda (ifld-list owner)
	   ;(debug-repl-env ifld-list owner)
	   (cond ((ifield? owner)
		  owner)
		 ((anyof-operand? owner)
		  ; This is the interesting case.  The instantiated choice of
		  ; {owner} is in {ifld-list}.  We have to find it.
		  (let* ((name (obj:name owner))
			 (result
			  (find-first (lambda (f)
					(and (derived-ifield? f)
					     (anyof-instance? (derived-ifield-owner f))
					     (eq? name (obj:name (anyof-instance-parent (derived-ifield-owner f))))))
				      ifld-list)))
		    ;(debug-repl-env ifld-list owner)
		    (assert result)
		    result))
		 ((operand? owner) ; derived operands are handled here too
		  (let ((result (op-ifield owner)))
		    (assert result)
		    result))
		 (else
		  (error "`owner' not <ifield>, <operand>, or <derived-operand>")))))
	)

    ; Resolve any `follows' specs.
    ; Bad worst case performance but ifield lists aren't usually that long.
    ; FIXME: Doesn't handle A following B following C.
    (map (lambda (f)
	   (let ((follows (ifld-follows f)))
	     (if follows
		 (let ((preceder (find-preceder iflds follows)))
		   (ifld-new-word-offset f (ifld-next-word preceder)))
		 f)))
	 iflds))
)


; Subroutine of multi-insn-instantiate! to instantiate one insn.
; INSN is the parent insn.
; ANYOF-OPERANDS is a list of the <anyof-operand>'s of INSN.
; NEW-VALUES is a list of the value to use for each corresponding element in
; ANYOF-OPERANDS.  Each element is a <derived-operand>.

(define (-sub-insn-make! insn anyof-operands new-values)
  ;(debug-repl-env insn anyof-operands new-values)
  (assert (= (length anyof-operands) (length new-values)))
  (assert (all-true? (map anyof-operand? anyof-operands)))
  (assert (all-true? (map derived-operand? new-values)))
  (logit 3 "Instantiating "
	 (obj:name insn)
	 ":"
	 (string-map (lambda (op newval)
		       (string-append " "
				      (obj:name op)
				      "="
				      (obj:name newval)))
		     anyof-operands new-values)
	 " ...\n")

;  (if (eq? '@sib+disp8-QI-disp32-8
;	   (obj:name (car new-values)))
;      (debug-repl-env insn anyof-operands new-values))

  (let* ((value-names (map obj:name anyof-operands))
	 (ifields (-sub-insn-ifields insn anyof-operands value-names new-values))
	 (known-values (ifld-known-values ifields)))

    ; Don't create insn if ifield assertions fail.
    (if (all-true? (map (lambda (op)
			  (anyof-satisfies-assertions? op known-values))
			new-values))

	(let ((sub-insn
	       (make <insn>
		     (apply symbol-append
			    (cons (obj:name insn)
				  (map (lambda (anyof)
					 (symbol-append '- (obj:name anyof)))
				       new-values)))
		     (obj:comment insn)
		     (obj-atlist insn)
		     (-anyof-merge-syntax (insn-syntax insn)
					  value-names new-values)
		     ifields
		     (insn-ifield-assertion insn) ; FIXME
		     (anyof-merge-semantics (insn-semantics insn)
					    value-names new-values)
		     (insn-timing insn)
		     )))
	  (logit 3 "   instantiated.\n")
	  (current-insn-add! sub-insn))

	(begin
	  logit 3 "    failed ifield assertions.\n")))

  *UNSPECIFIED*
)

; Instantiate all sub-insns of MULTI-INSN.
; ??? Might be better to return the list of insns, rather than add them to
; the global list, and leave it to the caller to add them.

(define (multi-insn-instantiate! multi-insn)
  (logit 2 "Instantiating " (obj:name multi-insn) " ...\n")

  ; We shouldn't get called more than once.
  ; ??? Though we could ignore second and subsequent calls.
  (assert (not (multi-insn-sub-insns multi-insn)))

  (let ((iflds (insn-iflds multi-insn)))

    ; What we want to create here is the set of all "anyof" alternatives.
    ; From that we create one <insn> per alternative.

    (let ((anyof-iflds (find ifld-anyof-operand? iflds)))

      (assert (all-true? (map anyof-operand? (map ifld-get-value anyof-iflds))))
      ;(display (obj:name multi-insn) (current-error-port))
      ;(display " anyof: " (current-error-port))
      ;(display (map obj:name (map ifld-get-value anyof-iflds)) (current-error-port))
      ;(newline (current-error-port))

      ; Iterate over all combinations.
      ; TODO is a list with one element for each <anyof-operand>.
      ; Each element is in turn a list of all choices (<derived-operands>'s)
      ; for the <anyof-operand>.  Note that some of these values may be
      ; derived from nested <anyof-operand>'s.
      ; ??? anyof-all-choices should cache the results.
      ; ??? Need to cache results of assertion processing in addition or
      ; instead of anyof-all-choices.

      (let* ((anyof-operands (map ifld-get-value anyof-iflds))
	     (todo (map anyof-all-choices anyof-operands))
	     (lengths (map length todo))
	     (total (apply * lengths)))
	; ??? One might prefer a `do' loop here, but every time I see one I
	; have to spend too long remembering its syntax.
	(let loop ((i 0))
	  (if (< i total)
	      (let* ((indices (split-value lengths i))
		     (anyof-instances (map list-ref todo indices)))
		;(display "derived: " (current-error-port))
		;(display (map obj:name anyof-instances) (current-error-port))
		;(newline (current-error-port))
		(-sub-insn-make! multi-insn anyof-operands anyof-instances)
		(loop (+ i 1))))))))

  *UNSPECIFIED*
)

; Parse an instruction description.
; This is the main routine for building an insn object from a
; description in the .cpu file.
; All arguments are in raw (non-evaluated) form.
; The result is the parsed object or #f if insn isn't for selected mach(s).

(define (-insn-parse errtxt name comment attrs syntax fmt ifield-assertion
		     semantics timing)
  (logit 2 "Processing insn " name " ...\n")

  (let ((name (parse-name name errtxt))
	(atlist-obj (atlist-parse attrs "cgen_insn" errtxt)))

    (if (keep-atlist? atlist-obj #f)

	(let ((ifield-assertion (if (not (null? ifield-assertion))
				    ifield-assertion
				    #f))
	      (semantics (if (not (null? semantics))
			     semantics
			     #f))
	      (format (-parse-insn-format (string-append errtxt " format")
					  fmt))
	      (comment (parse-comment comment errtxt))
	      ; If there are no semantics, mark this as an alias.
	      ; ??? Not sure this makes sense for multi-insns.
	      (atlist-obj (if semantics
			      atlist-obj
			      (atlist-cons (bool-attr-make 'ALIAS #t)
					   atlist-obj)))
	      (syntax (parse-syntax syntax errtxt))
	      (timing (parse-insn-timing errtxt timing))
	      )

	  (if (anyof-operand-format? format)

	      (make <multi-insn>
		name comment atlist-obj
		syntax
		format
		ifield-assertion
		semantics
		timing)

	      (make <insn>
		name comment atlist-obj
		syntax
		format
		ifield-assertion
		semantics
		timing)))

	(begin
	  (logit 2 "Ignoring " name ".\n")
	  #f)))
)

; Read an instruction description.
; This is the main routine for analyzing instructions in the .cpu file.
; ERRTXT is prepended to error messages to provide context.
; ARG-LIST is an associative list of field name and field value.
; -insn-parse is invoked to create the <insn> object.

(define (insn-read errtxt . arg-list)
  (let ((name nil)
	(comment "")
	(attrs nil)
	(syntax nil)
	(fmt nil)
	(ifield-assertion nil)
	(semantics nil)
	(timing nil)
	)
    ; Loop over each element in ARG-LIST, recording what's found.
    (let loop ((arg-list arg-list))
      (if (null? arg-list)
	  nil
	  (let ((arg (car arg-list))
		(elm-name (caar arg-list)))
	    (case elm-name
	      ((name) (set! name (cadr arg)))
	      ((comment) (set! comment (cadr arg)))
	      ((attrs) (set! attrs (cdr arg)))
	      ((syntax) (set! syntax (cadr arg)))
	      ((format) (set! fmt (cadr arg)))
	      ((ifield-assertion) (set! ifield-assertion (cadr arg)))
	      ((semantics) (set! semantics (cadr arg)))
	      ((timing) (set! timing (cdr arg)))
	      (else (parse-error errtxt "invalid insn arg" arg)))
	    (loop (cdr arg-list)))))
    ; Now that we've identified the elements, build the object.
    (-insn-parse errtxt name comment attrs syntax fmt ifield-assertion
		 semantics timing)
    )
)

; Define an instruction object, name/value pair list version.

(define define-insn
  (lambda arg-list
    (let ((i (apply insn-read (cons "define-insn" arg-list))))
      (if i
	  (current-insn-add! i))
      i))
)

; Define an instruction object, all arguments specified.

(define (define-full-insn name comment attrs syntax fmt ifield-assertion
	  semantics timing)
  (let ((i (-insn-parse "define-full-insn" name comment attrs
			syntax fmt ifield-assertion
			semantics timing)))
    (if i
	(current-insn-add! i))
    i)
)

; Parsing support.

; Parse an insn syntax field.
; SYNTAX is either a string or a list of strings, each element of which may
; in turn be a list of strings.
; ??? Not sure this extra flexibility is worth it yet.

(define (parse-syntax syntax errtxt)
  (cond ((list? syntax)
	 (string-map (lambda (elm) (parse-syntax elm errtxt)) syntax))
	((or (string? syntax) (symbol? syntax))
	 syntax)
	(else (parse-error errtxt "improper syntax" syntax)))
)

; Subroutine of -parse-insn-format to parse a symbol ifield spec.

(define (-parse-insn-format-symbol errtxt sym)
  ;(debug-repl-env sym)
  (let ((op (current-op-lookup sym)))
    (if op
	(cond ((derived-operand? op)
	       ; There is a one-to-one relationship b/w derived operands and
	       ; the associated derived ifield.
	       (let ((ifld (op-ifield op)))
		 (assert (derived-ifield? ifld))
		 ifld))
	      ((anyof-operand? op)
	       (ifld-new-value f-anyof op))
	      (else
	       (let ((ifld (op-ifield op)))
		 (ifld-new-value ifld op))))
	; An insn-enum?
	(let ((e (ienum-lookup-val sym)))
	  (if e
	      (ifld-new-value (ienum:fld (cdr e)) (car e))
	      (parse-error errtxt "bad format element" sym)))))
)

; Subroutine of -parse-insn-format to parse an (ifield-name value) ifield spec.
;
; The last element is the ifield's value.  It must be an integer.
; ??? Whether it can be negative is still unspecified.
; ??? While there might be a case where allowing floating point values is
; desirable, supporting them would require precise conversion routines.
; They should be rare enough that we instead punt.
;
; ??? May wish to support something like "(% startbit bitsize value)".
;
; ??? Error messages need improvement, but that's generally true of cgen.

(define (-parse-insn-format-ifield-spec errtxt ifld ifld-spec)
  (if (!= (length ifld-spec) 2)
      (parse-error errtxt "bad ifield format, should be (ifield-name value)" ifld-spec))

  (let ((value (cadr ifld-spec)))
    ; ??? This use to allow (ifield-name operand-name).  That's how
    ; `operand-name' elements are handled, but there's no current need
    ; to handle (ifield-name operand-name).
    (if (not (integer? value))
	(parse-error errtxt "ifield value not an integer" ifld-spec))
    (ifld-new-value ifld value))
)

; Subroutine of -parse-insn-format to parse an
; (ifield-name value) ifield spec.
; ??? There is room for growth in the specification syntax here.
; Possibilities are (ifield-name|operand-name [options] [value]).

(define (-parse-insn-format-list errtxt spec)
  (let ((ifld (current-ifld-lookup (car spec))))
    (if ifld
	(-parse-insn-format-ifield-spec errtxt ifld spec)
	(parse-error errtxt "unknown ifield" spec)))
)

; Given an insn format field from a .cpu file, replace it with a list of
; ifield objects with the values assigned.
;
; An insn format field is a list of ifields that make up the instruction.
; All bits must be specified, including reserved bits
; [at present no checking is made of this, but the rule still holds].
;
; A normal entry begins with `+' and then consist of the following:
; - operand name
; - (ifield-name [options] value)
; - (operand-name [options] [value])
; - insn ifield enum
;
; Example: (+ OP1_ADD (f-res2 0) dr src1 (f-src2 1) (f-res1 #xea))
;
; where OP1_ADD is an enum, dr and src1 are operands, and f-src2 and f-res1
; are ifield's.  The `+' allows for future extension.
;
; The other form of entry begins with `=' and is followed by an instruction
; name that has the same format.  The specified instruction must already be
; defined.  Instructions with this form typically also include an
; `ifield-assertion' spec to keep them separate.
;
; An empty field list is ok.  This means it's unspecified.
; VIRTUAL insns have this.
;
; This is one of the more important routines to be efficient.
; It's called for each instruction, and is one of the more expensive routines
; in insn parsing.

(define (-parse-insn-format errtxt fld-list)
  (if (null? fld-list)
      nil ; field list unspecified
      (case (car fld-list)
	((+) (map (lambda (fld)
		    (let ((f (if (string? fld)
				 (string->symbol fld)
				 fld)))
		      (cond ((symbol? f)
			     (-parse-insn-format-symbol errtxt f))
			    ((and (list? f)
				  ; ??? This use to allow <ifield> objects
				  ; in the `car' position.  Checked for below.
				  (symbol? (car f)))
			     (-parse-insn-format-list errtxt f))
			    (else
			     (if (and (list? f)
				      (ifield? (car f)))
				 (parse-error errtxt "FIXME: <ifield> object in format spec"))
			     (parse-error errtxt "bad format element" f)))))
		  (cdr fld-list)))
	((=) (begin
	       (if (or (!= (length fld-list) 2)
		       (not (symbol? (cadr fld-list))))
		   (parse-error errtxt
				"bad `=' format spec, should be `(= insn-name)'"
				fld-list))
	       (let ((insn (current-insn-lookup (cadr fld-list))))
		 (if (not insn)
		     (parse-error errtxt "unknown insn" (cadr fld-list)))
		 (insn-iflds insn))))
	(else
	 (parse-error errtxt "format must begin with `+' or `='" fld-list))
	))
)

; Return a boolean indicating if IFLD-LIST contains anyof operands.

(define (anyof-operand-format? ifld-list)
  (any-true? (map (lambda (f)
		    (or (ifld-anyof? f)
			(derived-ifield? f)))
		  ifld-list))
)

; Insn utilities.
; ??? multi-insn support wip, may require changes here.

; Return a boolean indicating if INSN is an alias insn.

(define (insn-alias? insn)
  (obj-has-attr? insn 'ALIAS)
)

; Return a list of instructions that are not aliases in INSN-LIST.

(define (non-alias-insns insn-list)
  (find (lambda (insn)
	  (not (insn-alias? insn)))
	insn-list)
)

; Return a boolean indicating if INSN is a "real" INSN
; (not ALIAS and not VIRTUAL and not a <multi-insn>).

(define (insn-real? insn)
  (let ((atlist (obj-atlist insn)))
    (and (not (atlist-has-attr? atlist 'ALIAS))
	 (not (atlist-has-attr? atlist 'VIRTUAL))
	 (not (multi-insn? insn))))
)

; Return a list of real instructions in INSN-LIST.

(define (real-insns insn-list)
  (find insn-real? insn-list)
)

; Return a boolean indicating if INSN is a virtual insn.

(define (insn-virtual? insn)
  (obj-has-attr? insn 'VIRTUAL)
)

; Return a list of virtual instructions in INSN-LIST.

(define (virtual-insns insn-list)
  (find insn-virtual? insn-list)
)

; Return a list of non-alias/non-pbb insns in INSN-LIST.

(define (non-alias-pbb-insns insn-list)
  (find (lambda (insn)
	  (let ((atlist (obj-atlist insn)))
	    (and (not (atlist-has-attr? atlist 'ALIAS))
		 (not (atlist-has-attr? atlist 'PBB)))))
	insn-list)
)

; Return a list of multi-insns in INSN-LIST.

(define (multi-insns insn-list)
  (find multi-insn? insn-list)
)

; And the opposite:

(define (non-multi-insns insn-list)
  (find (lambda (insn) (not (multi-insn? insn))) insn-list)
)


; Filter out instructions whose ifield patterns are strict subsets of
; another.  For decoding purpose, it is sufficient to consider the
; more general cousin.

(define (filter-harmlessly-ambiguous-insns insn-list)
  (logit 3 "Filtering " (length insn-list) " instructions.\n")
  (find (lambda (insn)
	  (let* ((i-mask (insn-base-mask insn))
		 (i-mask-len (insn-base-mask-length insn))
		 (i-value (insn-value insn))
		 (superset-insn (find-first 
				  (lambda (insn2) ; insn2: possible supermatch (fewer mask bits)
				    (let ((i2-mask (insn-base-mask insn2))
					  (i2-mask-len (insn-base-mask-length insn2))
					  (i2-value (insn-value insn2)))
				      (and (not (eq? insn insn2))
					   (= i-mask-len i2-mask-len)
					   (mask-superset? i2-mask i2-value i-mask i-value))))
				  insn-list))
		 (keep? (not superset-insn)))
	    (if (not keep?) 
		(logit 2
		       "Instruction " (obj:name insn) "ambiguity-filtered by "
		       (obj:name superset-insn) "\n"))
	    keep?))
	insn-list)
)


; Helper function for above: does (m1,v1) match a superset of (m2,v2) ?
;
; eg> mask-superset? #b1100 #b1000 #b1110 #b1010 -> #t
; eg> mask-superset? #b1100 #b1000 #b1010 #b1010 -> #f
; eg> mask-superset? #b1100 #b1000 #b1110 #b1100 -> #f
(define (mask-superset? m1 v1 m2 v2)
  (let ((result
	 (and (= (cg-logand m1 m2) m1)
	      (= (cg-logand m1 v1) (cg-logand m1 v2)))))
    (if result (logit 4
		      "(" (number->string m1 16) "," (number->string v1 16) ")"
		      " contains "
		      "(" (number->string m2 16) "," (number->string v2 16) ")"
		      "\n"))
    result)
)




; Return a boolean indicating if INSN is a cti [control transfer insn].
; This includes SKIP-CTI insns even though they don't terminate a basic block.
; ??? SKIP-CTI insns are wip, waiting for more examples of how they're used.

(define (insn-cti? insn)
  (atlist-cti? (obj-atlist insn))
)

; Return a boolean indicating if INSN can be executed in parallel.
; Such insns are required to have enum attribute PARALLEL != NO.
; This is worded specifically to allow the PARALLEL attribute to have more
; than just NO/YES values (should a target want to do so).
; This specification may not be sufficient, but the intent is explicit.

(define (insn-parallel? insn)
  (let ((atval (obj-attr-value insn 'PARALLEL)))
    (and atval (not (eq? atval 'NO))))
)

; Return a list of the insns that support parallel execution in INSN-LIST.

(define (parallel-insns insn-list)
  (find insn-parallel? insn-list)
)

; Instruction field utilities.

; Return a boolean indicating if INSN has ifield named F-NAME.

(define (insn-has-ifield? insn f-name)
  (->bool (object-assq f-name (insn-iflds insn)))
)

; Insn opcode value utilities.

; Given INSN, return the length in bits of the base mask (insn-base-mask).

(define (insn-base-mask-length insn)
  (ifmt-mask-length (insn-ifmt insn))
)

; Given INSN, return the bitmask of constant values (the opcode field)
; in the base part.

(define (insn-base-mask insn)
  (ifmt-mask (insn-ifmt insn))
)

; Given INSN, return the sum of the constant values in the insn
; (i.e. the opcode field).
;
; See also (compute-insn-base-mask).
;
(define (insn-value insn)
  (if (elm-get insn 'iflds-values)
      (elm-get insn 'iflds-values)
      (let* ((base-len (insn-base-mask-length insn))
	     (value (apply +
			   (map (lambda (fld) (ifld-value fld base-len (ifld-get-value fld)))
				(find ifld-constant?
				      (collect ifld-base-ifields (insn-iflds insn))))
			   )))
	(elm-set! insn 'iflds-values value)
	value)
      )
  )

; Insn operand utilities.

; Lookup operand SEM-NAME in INSN.

(define (insn-lookup-op insn sem-name)
  (or (op:lookup-sem-name (sfmt-in-ops (insn-sfmt insn)) sem-name)
      (op:lookup-sem-name (sfmt-out-ops (insn-sfmt insn)) sem-name))
)

; Insn syntax utilities.

; Create a list of syntax strings broken up into a list of characters and
; operand objects.

(define (syntax-break-out syntax)
  (let ((result nil))
    ; ??? The style of the following could be more Scheme-like.  Later.
    (let loop ()
      (if (> (string-length syntax) 0)
	  (begin
	    (cond 
	     ; Handle escaped syntax metacharacters 
	     ((char=? #\\ (string-ref syntax 0))
	      (set! result (cons (substring syntax 0 1) result))
	      (set! result (cons (substring syntax 1 1) result))
	      (set! syntax (string-drop 2 syntax)))
	     ; Handle operand reference
	     ((char=? #\$ (string-ref syntax 0))
	      ; Extract the symbol from the string, get the operand.
	      (if (char=? #\{ (string-ref syntax 1))
		  (let ((n (string-index syntax #\})))
		    (set! result (cons (current-op-lookup
					(string->symbol
					 (substring syntax 2 n)))
				       result))
		    (set! syntax (string-drop (+ 1 n) syntax)))
		  (let ((n (id-len (string-drop1 syntax))))
		    (set! result (cons (current-op-lookup
					(string->symbol
					 (substring syntax 1 (+ 1 n))))
				       result))
		    (set! syntax (string-drop (+ 1 n) syntax)))))
	     ; Handle everything else
	     (else (set! result (cons (substring syntax 0 1) result))
		   (set! syntax (string-drop1 syntax))))
	    (loop))))
    (reverse result))
  )

; Given a list of syntax elements (e.g. the result of syntax-break-out),
; create a syntax string.

(define (syntax-make elements)
  (apply string-append
	 (map (lambda (e)
		(cond ((char? e)
		       (string "\\" e))
		      ((string? e)
		       e)
		      (else
		       (assert (operand? e))
		       (string-append "${" (obj:name e) "}"))))
	      elements))
)

; Called before a .cpu file is read in.

(define (insn-init!)
  (reader-add-command! 'define-insn
		       "\
Define an instruction, name/value pair list version.
"
		       nil 'arg-list define-insn)
  (reader-add-command! 'define-full-insn
		       "\
Define an instruction, all arguments specified.
"
		       nil '(name comment attrs syntax fmt ifield-assertion semantics timing)
		       define-full-insn)

  *UNSPECIFIED*
)

; Called before a . cpu file is read in to install any builtins.

(define (insn-builtin!)
  ; Standard insn attributes.
  ; ??? Some of these can be combined into one.

  (define-attr '(for insn) '(type boolean) '(name UNCOND-CTI) '(comment "unconditional cti"))

  (define-attr '(for insn) '(type boolean) '(name COND-CTI) '(comment "conditional cti"))

  ; SKIP-CTI: one or more immediately following instructions are conditionally
  ; executed (or skipped)
  (define-attr '(for insn) '(type boolean) '(name SKIP-CTI) '(comment "skip cti"))

  ; DELAY-SLOT: insn has one or more delay slots (wip)
  (define-attr '(for insn) '(type boolean) '(name DELAY-SLOT) '(comment "insn has a delay slot"))

  ; RELAXABLE: Insn has one or more identical but larger variants.
  ; The assembler tries this one first and then the relaxation phase
  ; switches to the larger ones as necessary.
  ; All insns of identical behaviour have a RELAX_FOO attribute that groups
  ; them together.
  ; FIXME: This is a case where we need one attribute with several values.
  ; Presently each RELAX_FOO will use up a bit.
  (define-attr '(for insn) '(type boolean) '(name RELAXABLE) '(comment "insn is relaxable"))

  ; RELAX: Large relaxable variant.  Avoided by assembler in first pass.
  ; FIXME: Rename this to RELAXED.
  (define-attr '(for insn) '(type boolean) '(name RELAX) '(comment "relaxed form of insn"))

  ; NO-DIS: For macro insns, do not use during disassembly.
  (define-attr '(for insn) '(type boolean) '(name NO-DIS) '(comment "don't use for disassembly"))

  ; PBB: Virtual insn used for PBB support.
  (define-attr '(for insn) '(type boolean) '(name PBB) '(comment "virtual insn used for PBB support"))

  ; DECODE-SPLIT: insn resulted from decode-split processing
  (define-attr '(for insn) '(type boolean) '(name DECODE-SPLIT) '(comment "insn split from another insn for decoding purposes") '(attrs META))

  ; Also (defined elsewhere):
  ; VIRTUAL: Helper insn used by the simulator.

  *UNSPECIFIED*
)

; Called after the .cpu file has been read in.

(define (insn-finish!)
  *UNSPECIFIED*
)
