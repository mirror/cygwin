; Mode objects.
; Copyright (C) 2000, 2009, 2010 Red Hat, Inc.
; This file is part of CGEN.
; See file COPYING.CGEN for details.

; FIXME: Later allow target to add new modes.

(define <mode>
  (class-make '<mode>
	      '(<ident>)
	      '(
		; One of RANDOM, INT, UINT, FLOAT.
		class

		; size in bits
		bits

		; size in bytes
		bytes

		; The C type to use or #f if there is no such C type.
		; This is generally the name of the mode.
		c-type

		; PRINTF-TYPE is the %<letter> arg to printf-like functions,
		; however we define our own extensions for non-portable modes.
		; Values not understood by printf aren't intended to be used
		; with printf.
		;
		; Possible values:
		; %x - as always
		; %D - DI mode (8 bytes)
		; %T - TI mode (16 bytes)
		; %O - OI mode (32 bytes)
		; %f - SF,DF modes
		; %F - XF,TF modes
		printf-type

		; SEM-MODE is the mode to use for semantic operations.
		; Unsigned modes are not part of the semantic language proper,
		; but they can be used in hardware descriptions.  This maps
		; unusable -> usable modes.  It is #f if the mode is usable by
		; itself.  This prevents circular data structures and makes it
		; easy to define since the object doesn't exist before it's
		; defined.
		; ??? May wish to later remove SEM-MODE (e.g. mips signed add
		; is different than mips unsigned add).  However for now it keeps
		; things simpler, and prevents being wildly dissimilar from
		; GCC-RTL.  And the mips case needn't be handled with different
		; adds anyway.
		sem-mode

		; PTR-TO, if non-#f, is the mode being pointed to.
		ptr-to

		; HOST? is non-#f if the mode is a portable int for hosts,
		; or other host-related value.
		; This is used for things like register numbers and small
		; odd-sized immediates and registers.
		; ??? Not my favorite word choice here, but it's close.
		host?
		)
	      nil)
)

; Accessor fns

(define mode:class (elm-make-getter <mode> 'class))
(define mode:bits (elm-make-getter <mode> 'bits))
(define mode:bytes (elm-make-getter <mode> 'bytes))
(define mode:c-type (elm-make-getter <mode> 'c-type))
(define mode:printf-type (elm-make-getter <mode> 'printf-type))
(define mode:sem-mode (elm-make-getter <mode> 'sem-mode))
; ptr-to is currently private so there is no accessor.
(define mode:host? (elm-make-getter <mode> 'host?))

;; Utility to set the parameters of WI/UWI/AI/IAI modes.

(define (/mode-set-word-params! dst src)
  (assert (mode? dst))
  (assert (mode? src))
  (object-assign! dst src)
  *UNSPECIFIED*
)

; CM is short for "concat mode".  It is a list of modes of the elements
; of a `concat'.
; ??? Experiment.  Not currently used.

(define <concat-mode>
  (class-make '<concat-mode> '(<mode>)
	      '(
		; List of element modes
		elm-modes
		)
	      nil)
)

; Accessors.

(define cmode-elm-modes (elm-make-getter <concat-mode> 'elm-modes))

;; Table of all modes.
(define /mode-table nil)

;; This exists to simplify mode-find.
(define /mode-class-table nil)

; Return list of real mode objects (no aliases).

(define (mode-list-non-alias-values)
  (hash-fold (lambda (key value prior)
	       (if (eq? key (obj:name value))
		   (append value prior)
		   prior))
	     '()
	     /mode-table)
)

; Return a boolean indicating if X is a <mode> object.

(define (mode? x) (class-instance? <mode> x))

; Return enum cgen_mode_types value for M.

(define (mode:enum m)
  (gen-c-symbol (string-append "MODE_" (string-upcase (obj:str-name m))))
)

; Return a boolean indicating if MODE1 is equal to MODE2
; Either may be the name of a mode or a <mode> object.
; Aliases are handled by refering to their real name.
; ??? Might be useful to restrict this to <mode> objects only.

(define (mode:eq? mode1 mode2)
  (let ((mode1-name (mode-real-name (mode-maybe-lookup mode1)))
	(mode2-name (mode-real-name (mode-maybe-lookup mode2))))
    (eq? mode1-name mode2-name))
)

; Return a boolean indicating if CLASS is one of INT/UINT.

(define (mode-class-integral? class) (memq class '(INT UINT)))
(define (mode-class-signed? class) (eq? class 'INT))
(define (mode-class-unsigned? class) (eq? class 'UINT))

; Return a boolean indicating if CLASS is floating point.

(define (mode-class-float? class) (memq class '(FLOAT)))

; Return a boolean indicating if CLASS is numeric.

(define (mode-class-numeric? class) (memq class '(INT UINT FLOAT)))

; Return a boolean indicating if <mode> MODE has an integral mode class.
; Similarily for signed/unsigned.

(define (mode-integral? mode) (mode-class-integral? (mode:class mode)))
(define (mode-signed? mode) (mode-class-signed? (mode:class mode)))
(define (mode-unsigned? mode) (mode-class-unsigned? (mode:class mode)))

; Return a boolean indicating if <mode> MODE has a floating point mode class.

(define (mode-float? mode) (mode-class-float? (mode:class mode)))

; Return a boolean indicating if <mode> MODE has a numeric mode class.

(define (mode-numeric? mode) (mode-class-numeric? (mode:class mode))) 

;; Return a boolean indicating if <mode> MODE is VOID.

(define (mode-void? mode)
  (eq? mode VOID)
)

; Return a boolean indicating if MODE1 is compatible with MODE2.
; MODE[12] are either names or <mode> objects.
; HOW is a symbol indicating how the test is performed:
; strict: modes must have same name
; samesize: modes must be both float, or both integer (int or uint),
;           or both VOID and have same size
; sameclass: modes must be both float, or both integer (int or uint),
;            or both VOID
; numeric: modes must be both numeric

(define (mode-compatible? how mode1 mode2)
  (let ((m1 (mode-maybe-lookup mode1))
	(m2 (mode-maybe-lookup mode2)))
    (case how
      ((strict)
       (eq? (obj:name m1) (obj:name m2)))
      ((samesize)
       (cond ((mode-integral? m1)
	      (and (mode-integral? m2)
		   (= (mode:bits m1) (mode:bits m2))))
	     ((mode-float? m1)
	      (and (mode-float? m2)
		   (= (mode:bits m1) (mode:bits m2))))
	     ((mode-void? m1)
	      (mode-void? m2))
	     (else #f)))
      ((sameclass)
       (cond ((mode-integral? m1) (mode-integral? m2))
	     ((mode-float? m1) (mode-float? m2))
	     ((mode-void? m1) (mode-void? m2))
	     (else #f)))
      ((numeric)
       (and (mode-numeric? m1) (mode-numeric? m2)))
      (else (error "bad `how' arg to mode-compatible?" how))))
)

; Add MODE named NAME to the table of recognized modes.
; If NAME is already present, replace it with MODE.
; MODE is a mode object.
; NAME exists to allow aliases of modes [e.g. WI, UWI, AI, IAI].
;
; No attempt to preserve any particular order of entries is done here.
; That is up to the caller.

(define (mode:add! name mode)
  (hashq-set! /mode-table name mode)

  ;; Add the mode to its mode class.
  ;; There's no point in building this list in any particular order,
  ;; if the user adds some they could be of any size.
  ;; So build the list the simple way (in reverse).
  ;; The list is sorted in mode-finish!.
  (let ((class (mode:class mode)))
    (hashq-set! /mode-class-table class
		(cons mode (hashq-ref /mode-class-table class))))

  *UNSPECIFIED*
)

; Parse a mode.
; This is the main routine for building a mode object.
; All arguments are in raw (non-evaluated) form.

(define (/mode-parse context name comment attrs class bits bytes
		     c-type printf-type sem-mode ptr-to host?)
  (logit 2 "Processing mode " name " ...\n")

  ;; Pick out name first to augment the error context.
  (let* ((name (parse-name context name))
	 (context (context-append-name context name)))

    (make <mode>
      name
      (parse-comment context comment)
      (atlist-parse context attrs "mode")
      class bits bytes c-type printf-type
      sem-mode ptr-to host?))
)

; ??? At present there is no define-mode that takes an associative list
; of arguments.

; Define a mode object, all arguments specified.

(define (define-full-mode name comment attrs class bits bytes
	  c-type printf-type sem-mode ptr-to host?)
  (let ((m (/mode-parse (make-current-context "define-full-mode")
			name comment attrs
			class bits bytes
			c-type printf-type sem-mode ptr-to host?)))
    ; Add it to the list of insn modes.
    (mode:add! name m)
    m)
)

; Lookup the mode named X.
; Return the found object or #f.
; If X is already a mode object, return that.

(define (mode:lookup mode-name)
;  (if (mode? x)
;      x
;      (let ((result (assq x mode-list)))
;	(if result
;	    (cdr result)
;	    #f)))
  (hashq-ref /mode-table mode-name)
)

;; Same as mode:lookup except MODE is either the mode name or a <mode> object.

(define (mode-maybe-lookup mode)
  (if (symbol? mode)
      (hashq-ref /mode-table mode)
      mode)
)

; Return a boolean indicating if X is a valid mode name.

(define (mode-name? x)
  (and (symbol? x)
       (->bool (mode:lookup x)))
)

; Return the name of the real mode of MODE, a <mode> object.
; This is a no-op unless M is an alias in which case we return the
; real mode of the alias.

(define (mode-real-name mode)
  (obj:name mode)
)

; Return the real mode of MODE, a <mode> object.
; This is a no-op unless M is an alias in which case we return the
; real mode of the alias.

(define (mode-real-mode mode)
  ;; Lookups of aliases return its real mode, so this function is a no-op.
  ;; But that's an implementation detail, so I'm not ready to delete this
  ;; function.
  mode
)

; Return the version of MODE to use in semantic expressions.
; MODE is a <mode> object.
; This (essentially) converts aliases to their real value and then uses
; mode:sem-mode.  The implementation is the opposite but the effect is the
; same.
; ??? Less efficient than it should be.  One improvement would be to
; disallow unsigned modes from being aliased and set sem-mode for aliased
; modes.

(define (mode-sem-mode mode)
  (let ((sm (mode:sem-mode mode)))
    (if sm
	sm
	(mode-real-mode mode)))
)

; Return #t if mode M1 is bigger than mode M2.
; Both are <mode> objects.

(define (mode-bigger? m1 m2)
  (> (mode:bits m1)
     (mode:bits m2))
)

; Return a mode in mode class CLASS wide enough to hold BITS.
; This ignores "host" modes (e.g. INT,UINT).

(define (mode-find bits class)
  (let* ((class-modes (hashq-ref /mode-class-table class))
	 (modes (find (lambda (mode) (not (mode:host? mode)))
		      (or class-modes nil))))		     
    (if (null? modes)
	(error "invalid mode class" class))
    (let loop ((modes modes))
      (cond ((null? modes) (error "no modes for bits" bits))
	    ((<= bits (mode:bits (car modes))) (car modes))
	    (else (loop (cdr modes))))))
)

; Parse MODE-NAME and return the mode object.
; CONTEXT is a <context> object for error messages.
; An error is signalled if MODE isn't valid.

(define (parse-mode-name context mode-name)
  (let ((m (mode:lookup mode-name)))
    (if (not m)
	(parse-error context "not a valid mode" mode-name))
    m)
)

; Make a new INT/UINT mode.
; These have a variable number of bits (1-64).

(define (mode-make-int bits)
  (if (or (<= bits 0) (> bits 64))
      (error "unsupported number of bits" bits))
  (let ((result (object-copy-top INT)))
    (elm-xset! result 'bits bits)
    (elm-xset! result 'bytes (bits->bytes bits))
    result)
)

(define (mode-make-uint bits)
  (if (or (<= bits 0) (> bits 64))
      (error "unsupported number of bits" bits))
  (let ((result (object-copy-top UINT)))
    (elm-xset! result 'bits bits)
    (elm-xset! result 'bytes (bits->bytes bits))
    result)
)

; WI/UWI/AI/IAI modes
; These are aliases for other modes, e.g. SI,DI.
; Final values are defered until all cpu family definitions have been
; read in so that we know the word size, etc.
;
; NOTE: We currently assume WI/AI/IAI all have the same size: cpu:word-bitsize.
; If we ever add an architecture that needs different modes for WI/AI/IAI,
; we can add the support then.

; This is defined by the target in define-cpu:word-bitsize.
(define WI #f)
(define UWI #f)

; An "address int".  This is recorded in addition to a "word int" because it
; is believed that some target will need it.  It also stays consistent with
; what BFD does.  It also allows one to write rtl without having to care
; what the real mode actually is.
; ??? These are currently set from define-cpu:word-bitsize but that's just
; laziness.  If an architecture comes along that has different values,
; add the support then.
(define AI #f)
(define IAI #f)

; Kind of word size handling wanted.
; BIGGEST: pick the largest word size
; IDENTICAL: all word sizes must be identical
(define /mode-word-sizes-kind #f)

;; Set to true if mode-set-word-modes! has been called.
(define /mode-word-sizes-defined? #f)

; Called when a cpu-family is read in to set the word sizes.

(define (mode-set-word-modes! bitsize)
  (let ((current-word-bitsize (mode:bits WI))
	(word-mode (mode-find bitsize 'INT))
	(uword-mode (mode-find bitsize 'UINT))
	(ignore? #f))

    ; Ensure we found a precise match.
    (if (!= bitsize (mode:bits word-mode))
	(error "unable to find precise mode to match cpu word-bitsize" bitsize))

    ; Enforce word size kind.
    (if /mode-word-sizes-defined?
	(case /mode-word-sizes-kind
	  ((IDENTICAL)
	   (if (!= current-word-bitsize (mode:bits word-mode))
	       (error "app requires all selected cpu families to have same word size"))
	   (set! ignore? #t))
	  ((BIGGEST)
	   (if (>= current-word-bitsize (mode:bits word-mode))
	       (set! ignore? #t)))
	  ))

    (if (not ignore?)
	(begin
	  (/mode-set-word-params! WI word-mode)
	  (/mode-set-word-params! UWI uword-mode)
	  (/mode-set-word-params! AI uword-mode)
	  (/mode-set-word-params! IAI uword-mode)
	  ))
    )

  (set! /mode-word-sizes-defined? #t)
)

; Called by apps to indicate cpu:word-bitsize always has one value.
; It is an error to call this if the selected cpu families have
; different word sizes.
; Must be called before loading .cpu files.

(define (mode-set-identical-word-bitsizes!)
  (set! /mode-word-sizes-kind 'IDENTICAL)
)

; Called by apps to indicate using the biggest cpu:word-bitsize of all
; selected cpu families.
; Must be called before loading .cpu files.

(define (mode-set-biggest-word-bitsizes!)
  (set! /mode-word-sizes-kind 'BIGGEST)
)

; Ensure word sizes have been defined.
; This must be called after all cpu families have been defined
; and before any ifields, hardware, operand or insns have been read.
; FIXME: sparc.cpu breaks this

(define (mode-ensure-word-sizes-defined)
  (if (not /mode-word-sizes-defined?)
      (error "word sizes must be defined"))
)

; Initialization.

; Some modes are refered to by the Scheme code.
; These have global bindings, but we try not to make this the general rule.
; [Actually I don't think this is all that bad, but it seems reasonable to
; not create global bindings that we don't have to.]

(define VOID #f)
(define DFLT #f)

; Variable sized portable ints.
(define INT #f)
(define UINT #f)

;; Sort the modes for each class.

(define (/sort-mode-classes!)
  (for-each (lambda (class-name)
	      (hashq-set! /mode-class-table class-name
			  (sort (hashq-ref /mode-class-table class-name)
				(lambda (a b)
				  (< (mode:bits a)
				     (mode:bits b))))))
	    '(RANDOM INT UINT FLOAT))

  *UNSPECIFIED*
)

(define (mode-init!)
  (set! /mode-word-sizes-kind 'IDENTICAL)
  (set! /mode-word-sizes-defined? #f)

  (reader-add-command! 'define-full-mode
		       "\
Define a mode, all arguments specified.
"
		       nil '(name commment attrs class bits bytes
			     non-c-mode-type printf-type sem-mode ptr-to host?)
		       define-full-mode)

  *UNSPECIFIED*
)

; Called before a . cpu file is read in to install any builtins.

(define (mode-builtin!)
  ; FN-SUPPORT: In sem-ops.h file, include prototypes as well as macros.
  ;             Elsewhere, functions are defined to perform the operation.
  (define-attr '(for mode) '(type boolean) '(name FN-SUPPORT))

  (set! /mode-class-table (make-hash-table 7))
  (hashq-set! /mode-class-table 'RANDOM '())
  (hashq-set! /mode-class-table 'INT '())
  (hashq-set! /mode-class-table 'UINT '())
  (hashq-set! /mode-class-table 'FLOAT '())

  (set! /mode-table (make-hash-table 41))

  (let ((dfm define-full-mode))
    ; This list must be defined in order of increasing size among each type.
    ; FIXME: still true?

    (dfm 'VOID "void" '() 'RANDOM 0 0 "void" "" #f #f #f) ; VOIDmode

    ; Special marker to indicate "use the default mode".
    (dfm 'DFLT "default mode" '() 'RANDOM 0 0 #f "" #f #f #f)

    ; Mode used in `symbol' rtxs.
    (dfm 'SYM "symbol" '() 'RANDOM 0 0 #f "" #f #f #f)

    ; Mode used in `current-insn' rtxs.
    (dfm 'INSN "insn" '() 'RANDOM 0 0 #f "" #f #f #f)

    ; Mode used in `current-mach' rtxs.
    (dfm 'MACH "mach" '() 'RANDOM 0 0 #f "" #f #f #f)

    ; Not UINT on purpose.
    (dfm 'BI "one bit (0,1 not 0,-1)" '() 'INT 1 1 "BI" "'x'" #f #f #f)

    (dfm 'QI "8 bit byte" '() 'INT 8 1 "QI" "'x'" #f #f #f)
    (dfm 'HI "16 bit int" '() 'INT 16 2 "HI" "'x'" #f #f #f)
    (dfm 'SI "32 bit int" '() 'INT 32 4 "SI" "'x'" #f #f #f)
    (dfm 'DI "64 bit int" '(FN-SUPPORT) 'INT 64 8 "DI" "'D'" #f #f #f)

    ; No unsigned versions on purpose for now.
    (dfm 'TI "128 bit int" '(FN-SUPPORT) 'INT 128 16 "TI" "'T'" #f #f #f)
    (dfm 'OI "256 bit int" '(FN-SUPPORT) 'INT 256 32 "OI" "'O'" #f #f #f)

    (dfm 'UQI "8 bit unsigned byte" '() 'UINT
	 8 1 "UQI" "'x'" (mode:lookup 'QI) #f #f)
    (dfm 'UHI "16 bit unsigned int" '() 'UINT
	 16 2 "UHI" "'x'" (mode:lookup 'HI) #f #f)
    (dfm 'USI "32 bit unsigned int" '() 'UINT
	 32 4 "USI" "'x'" (mode:lookup 'SI) #f #f)
    (dfm 'UDI "64 bit unsigned int" '(FN-SUPPORT) 'UINT
	 64 8 "UDI" "'D'" (mode:lookup 'DI) #f #f)

    ; Floating point values.
    (dfm 'SF "32 bit float" '(FN-SUPPORT) 'FLOAT
	 32 4 "SF" "'f'" #f #f #f)
    (dfm 'DF "64 bit float" '(FN-SUPPORT) 'FLOAT
	 64 8 "DF" "'f'" #f #f #f)
    (dfm 'XF "80/96 bit float" '(FN-SUPPORT) 'FLOAT
	 96 12 "XF" "'F'" #f #f #f)
    (dfm 'TF "128 bit float" '(FN-SUPPORT) 'FLOAT
	 128 16 "TF" "'F'" #f #f #f)

    ; These are useful modes that represent host values.
    ; For INT/UINT the sizes indicate maximum portable values.
    ; These are also used for random width hardware elements (e.g. immediates
    ; and registers).
    ; FIXME: Can't be used to represent both host and target values.
    ; Either remove the distinction or add new modes with the distinction.
    ; FIXME: IWBN to specify #f for sem-mode, but that means we'd need
    ; TRUNCINTQI,etc.
    (dfm 'INT "portable int" '() 'INT 32 4 "INT" "'x'"
	 (mode:lookup 'SI) #f #t)
    (dfm 'UINT "portable unsigned int" '() 'UINT 32 4 "UINT" "'x'"
	 (mode:lookup 'SI) #f #t)

    ; ??? Experimental.
    (dfm 'PTR "host pointer" '() 'RANDOM 0 0 "void*" "'x'"
	 #f (mode:lookup 'VOID) #t)
    )

  (set! VOID (mode:lookup 'VOID))
  (set! DFLT (mode:lookup 'DFLT))

  (set! INT (mode:lookup 'INT))
  (set! UINT (mode:lookup 'UINT))

  ;; While setting the real values of WI/UWI/AI/IAI is defered to
  ;; mode-set-word-modes!, create usable entries in the table.
  ;; The entries must be usable as h/w elements may be defined that use them.
  (set! WI (object-copy-top (mode:lookup 'SI)))
  (set! UWI (object-copy-top (mode:lookup 'USI)))
  (set! AI (object-copy-top (mode:lookup 'USI)))
  (set! IAI (object-copy-top (mode:lookup 'USI)))
  (mode:add! 'WI WI)
  (mode:add! 'UWI UWI)
  (mode:add! 'AI AI)
  (mode:add! 'IAI IAI)

  ;; Need to have usable mode classes at this point as define-cpu
  ;; calls mode-set-word-modes!.
  (/sort-mode-classes!)

  *UNSPECIFIED*
)

(define (mode-finish!)
  ;; FIXME: mode:add! should keep the class sorted.
  ;; It's a cleaner way to handle modes from the .cpu file.
  (/sort-mode-classes!)

  *UNSPECIFIED*
)
