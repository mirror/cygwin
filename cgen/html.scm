; CPU documentation generator, html output
; Copyright (C) 2003, Doug Evans
; This file is part of CGEN.  See file COPYING.CGEN for details.
;
; TODO:
; - assumes names, comments, etc. don't interfere with html.
;   Just like in generation of C there are routines to C-ize symbols,
;   we need to pass output through an html-izer.
; - make generated html more readable, e.g. more indentation
; - should really print the semantics in pseudo-C, a much better form for
;   the intended audience
; - registers that have multiple independent fields (like x86 eflags)
;   need to be printed like instruction formats are
; - uses some deprecated html, use css at very least
; - multi-ifields ok?
; - mapping from operands to h/w isn't as clear as it needs to be
; - for insn formats, if field is large consider printing "n ... m",
;   would want "n" left justified and "m" right justified though
; - for insn formats, consider printing them better,
;   e.g. maybe generate image and include that instead
; - need ability to specify more prose for each architecture
; - frv-doc.html is massive, default plan is to split it up by machine
;   but is that the way to go here?
;   --> split up output into several files anyway (for all archs)
; - assembler support
; - need to add docs to website that can be linked to here, rather than
;   including generic cgen documentation here
; - function units, timing, etc.
; - instruction framing
; - ARM docs mix arm/thumb, should be separate,
;   first try to split using keep-isa

; Global state variables.

; Specify which application.
(set! APPLICATION 'DOC)

; String containing copyright text.
(define CURRENT-COPYRIGHT #f)

; String containing text defining the package we're generating code for.
(define CURRENT-PACKAGE #f)

(define copyright-doc
  (cons "\
THIS FILE IS MACHINE GENERATED WITH CGEN.

See the input .cpu file(s) for copyright information.
"
	"\
"))

; Initialize the options.

(define (option-init!)
  (set! CURRENT-COPYRIGHT copyright-doc)
  (set! CURRENT-PACKAGE package-cgen)
  *UNSPECIFIED*
)

; Handle an option passed in from the command line.

(define (option-set! name value)
  (case name
    ((copyright) (cond ((equal?  value '("doc"))
			(set! CURRENT-COPYRIGHT copyright-doc))
		       (else (error "invalid copyright value" value))))
    ((package) (cond ((equal?  value '("cgen"))
		      (set! CURRENT-PACKAGE package-cgen))
		     (else (error "invalid package value" value))))
    (else (error "unknown option" name))
    )
  *UNSPECIFIED*
)

; Misc utilities.

; Return COPYRIGHT, with FILE-DESC as the first line
; and PACKAGE as the name of the package which the file belongs in.
; COPYRIGHT is a pair of (header . trailer).

(define (gen-html-copyright file-desc copyright package)
  (string-append "<! " file-desc "\n\n"
		 (car copyright)
		 "\n" package "\n"
		 (cdr copyright)
		 "\n>\n\n")
)

; TODO: Add author arg so all replies for this arch go to right person.

(define (gen-html-header)
  (let ((arch (current-arch-name))
	(ARCH (string-upcase (current-arch-name))))
    (string-list
     "<!doctype html public \"-//w3c//dtd html 4.0 transitional//en\">\n"
     "<html>\n"
     "<head>\n"
     "  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\n"
     "  <meta name=\"description\" content=\"" ARCH " Architecture Documentation\">\n"
     "  <meta name=\"language\" content=\"en-us\">\n"
     "  <meta name=\"owner\" content=\"dje@sebabeach.org (Doug Evans)\">\n"
     "  <meta name=\"reply-to\" content=\"dje@sebabeach.org (Doug Evans)\">\n"
     "  <title>" ARCH " Architecture Documentation</title>\n"
     "</head>\n"
     "<body bgcolor=\"#F0F0F0\" TEXT=\"#003333\" LINK=\"#FF0000\" VLINK=\"#444444\" alink=\"#000000\">\n"
     )
    )
)

(define (gen-html-trailer)
  (string-list
   "\n"
   "<p><hr><p>\n"
   "This documentation was machine generated from the cgen cpu description\n"
   "files for this architecture.\n"
   "<br>\n"
   "<a href=\"http://sources.redhat.com/cgen/\">http://sources.redhat.com/cgen/</a>\n"
   "</body>\n"
   "</html>\n"
   )
)

(define (gen-table-of-contents)
  (let ((ARCH (string-upcase (current-arch-name))))
    (string-list
     "<h1>\n"
     (string-append ARCH " Architecture Documentation")
     "</h1>\n"
     "\n"
     "<br>\n"
     "DISCLAIMER: This documentation is derived from the cgen cpu description\n"
     "of this architecture, and does not represent official documentation\n"
     "of the chip maker.\n"
     "<p><hr><p>\n"
     "\n"
     "<ul>\n"
     "<li><a href=\"#arch\">Architecture</a></li>\n"
     "<li><a href=\"#machines\">Machine variants</a></li>\n"
     "<li><a href=\"#models\">Model variants</a></li>\n"
     "<li><a href=\"#registers\">Registers</a></li>\n"
     "<li><a href=\"#insns\">Instructions</a></li>\n"
     "<li><a href=\"#macro-insns\">Macro instructions</a></li>\n"
     "<li><a href=\"#assembler\">Assembler supplemental</a></li>\n"
     "</ul>\n"
     "<br>\n"
     ; TODO: Move this to the cgen website, and include a link here.
     "In cgen-parlance, an architecture consists of machines and models.\n"
     "A `machine' is the specification of a variant of the architecture,\n"
     "and a `model' is the implementation of that specification.\n"
     "Typically there is a one-to-one correspondance between machine and model.\n"
     "The distinction allows for separation of what application programs see\n"
     "(the machine), and how to tune for the chip (what the compiler sees).\n"
     "<br>\n"
     "A \"cpu family\" is a cgen concoction to help organize the generated code.\n"
     "Chip variants that are quite dissimilar can be treated separately by the\n"
     "generated code even though they're both members of the same architecture.\n"
      ))
)

; Utility to print a list entry for object O of kind KIND
; which is a link to the description of O.
; KIND is one of "mach", "model", etc.

(define (gen-obj-list-entry o kind)
  (string-append "<li>"
		 "<a href=\"#" kind "-" (obj:name o) "\">"
		 (obj:name o)
		 " - "
		 (obj:comment o)
		 "</a>\n"
		 "</li>\n")
)

; Utility to print the header for the description of object O of kind KIND.
; KIND is one of "mach", "model", etc.

(define (gen-obj-doc-header o kind)
  (string-list
   "<a name=\"" kind "-" (obj:name o) "\"></a>\n"
   "<h3>" (obj:name o) " - " (obj:comment o) "</h3>\n"
   )
)

; Architecture page.

(define (-gen-cpu-intro cpu)
  (string-list
   "<li>\n"
   (obj:name cpu) " - " (obj:comment cpu) "\n"
   "<br>\n"
   "<br>\n"
   "Machines:\n"
   "<ul>\n"
   (string-list-map -gen-mach-intro
		    (alpha-sort-obj-list (machs-for-cpu cpu)))
   "</ul>\n"
   "</li>\n"
   "<br>\n"
   )
)

(define (-gen-mach-intro mach)
  (string-list
   "<li>\n"
   (obj:name mach) " - " (obj:comment mach) "\n"
   "<br>\n"
   "<br>\n"
   "Models:\n"
   "<ul>\n"
   (string-list-map -gen-model-intro
		    (alpha-sort-obj-list (models-for-mach mach)))
   "</ul>\n"
   "</li>\n"
   "<br>\n"
   )
)

(define (-gen-model-intro model)
  (string-list
   "<li>\n"
   (obj:name model) " - " (obj:comment model) "\n"
   "<br>\n"
   "</li>\n"
   )
)

(define (-gen-isa-intro isa)
  (string-list
   "<li>\n"
   (obj:name isa) " - " (obj:comment isa) "\n"
   "<br>\n"
   ; FIXME: wip
   ; I'd like to include the .cpu file tag here, but using English text
   ; feels more appropriate.  Having both is excessive.
   ; Pick one, and have a link to its description/tag.
   ; I'm leaning toward using the cgen tag here as we'll probably want
   ; access (via an html tag) to more than one-liner descriptions.
   "<ul>\n"
   "<li>default-insn-word-bitsize: "
   (number->string (isa-default-insn-word-bitsize isa))
   "</li>\n"
   "<br>\n"
   "<li>default-insn-bitsize: "
   (number->string (isa-default-insn-bitsize isa))
   "</li>\n"
   "<br>\n"
   "<li>base-insn-bitsize: "
   (number->string (isa-base-insn-bitsize isa))
   "</li>\n"
   "<br>\n"
   "<li>decode-assist: "
   (string-map (lambda (n) (string-append " " (number->string n)))
	       (isa-decode-assist isa))
   "</li>\n"
   "<br>\n"
   "<li>decode-splits: "
   (string-map (lambda (n) (string-append " " (number->string n)))
	       (isa-decode-splits isa))
   "</li>\n"
   "<br>\n"
   (if (> (isa-liw-insns isa) 1)
       (string-append "<li>liw-insns: "
		      (number->string (isa-liw-insns isa))
		      "</li>\n"
		      "<br>\n")
       "")
   (if (> (isa-parallel-insns isa) 1)
       (string-append "<li>parallel-insns: "
		      (number->string (isa-parallel-insns isa))
		      "</li>\n"
		      "<br>\n")
       "")
   (if (isa-condition isa)
       (string-append "<li>condition-field: "
		      (car (isa-condition isa))
		      "</li>\n"
		      "<br>\n"
		      "<li>condition:\n"
		      "<font size=+2>\n"
		      "<plaintext>" ; no trailing newline here on purpose
		      (with-output-to-string
			(lambda ()
			  (pretty-print (cadr (isa-condition isa)))))
		      "</plaintext></font>\n"
		      "</li>\n"
		      "<br>\n")
       "")
   (if (isa-setup-semantics isa)
       (string-append "<li>setup-semantics:\n"
		      "<font size=+2>\n"
		      "<plaintext>" ; no trailing newline here on purpose
		      (with-output-to-string
			(lambda ()
			  (pretty-print (cdr (isa-setup-semantics isa)))))
		      "</plaintext></font>\n"
		      "</li>\n"
		      "<br>\n")
       "")
   "</ul>\n"
   "</li>\n"
   )
)

(define (gen-arch-intro)
  ; NOTE: This includes cpu families.
  (let ((ARCH (string-upcase (current-arch-name)))
	(isas (current-isa-list))
	(cpus (current-cpu-list))
	)
    (string-list
     "\n"
     "<hr>\n"
     "<a name=\"arch\"></a>\n"
     "<h2>" ARCH " Architecture</h2>\n"
     "<p>\n"
     "This section describes various things about the cgen description of\n"
     "the " ARCH " architecture.  Familiarity with cgen cpu descriptions\n"
     "is assumed.\n"
     "<p>\n"
     "Bit number orientation (arch.lsb0?): "
     (if (current-arch-insn-lsb0?) "lsb = 0" "msb = 0")
     "\n"
     "<p>\n"
     "<h3>ISA description</h3>\n"
     ; NOTE: For the normal case there's only one isa, thus specifying it in
     ; a list is excessive.  Later.
     "<p>\n"
     "<ul>\n"
     (string-list-map -gen-isa-intro
		      (alpha-sort-obj-list isas))
     "</ul>\n"
     "<p>\n"
     "<h3>CPU Families</h3>\n"
     "<ul>\n"
     (string-list-map -gen-cpu-intro
		      (alpha-sort-obj-list cpus))
     "</ul>\n"
     ))
)

; Machine page.

(define (gen-machine-doc-1 mach)
  (string-list
   (gen-obj-doc-header mach "mach")
   "<ul>\n"
   "<li>\n"
   "bfd-name: "
   (mach-bfd-name mach)
   "\n"
   "</li>\n"
   "<li>\n"
   "isas: "
   (string-map (lambda (isa)
		 (string-append " " (obj:name isa)))
	       (mach-isas mach))
   "\n"
   "</li>\n"
   "</ul>\n"
   )
)

(define (gen-machine-docs)
  (let ((machs (alpha-sort-obj-list (current-mach-list))))
    (string-list
     "\n"
     "<hr>\n"
     "<a name=\"machines\"></a>\n"
     "<h2>Machine variants</h2>\n"
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "mach"))
		 machs)
     "</ul>\n"
     (string-list-map gen-machine-doc-1 machs)
     ))
)

; Model page.

(define (gen-model-doc-1 model)
  (string-list
   (gen-obj-doc-header model "model")
   "<ul>\n"
   "</ul>\n"
   )
)

(define (gen-model-docs)
  (let ((models (alpha-sort-obj-list (current-model-list))))
    (string-list
     "\n"
     "<hr>\n"
     "<a name=\"models\"></a>\n"
     "<h2>Model variants</h2>\n"
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "model"))
		 models)
     "</ul>\n"
     (string-list-map gen-model-doc-1 models)
     ))
)

; Register page.
;
; TODO: Provide tables of regs for each mach.

; Subroutine of gen-reg-doc-1 to simplify it.
; Generate a list of names of registers in register array REG.
; The catch is that we want to shrink r0,r1,r2,...,r15 to r0...r15.

(define (gen-pretty-reg-array-names reg)
  ; We currently only support arrays of rank 1 (vectors).
  (if (!= (hw-rank reg) 1)
      (error "gen-pretty-reg-array-names: unsupported rank" (hw-rank reg)))
  (let ((indices (hw-indices reg)))
    (if (class-instance? <keyword> indices)
	(let ((values (kw-values indices)))
	  (string-list
	   "<br>\n"
	   "names:\n"
	   "<br>\n"
	   "<table frame=border border=2>\n"
	   "<tr>\n"
	   (string-list-map (lambda (v)
			      (string-list "<tr>\n"
					   "<td>"
					   (car v)
					   "</td>\n"
					   "<td>"
					   (number->string (cadr v))
					   "</td>\n"
					   "</tr>\n"))
			    values)))
	""))
)

(define (gen-reg-doc-1 reg)
  (string-list
   (gen-obj-doc-header reg "reg")
   "<ul>\n"
   "<li>\n"
   "machines: "
   (string-map (lambda (mach)
		 (string-append " " mach))
	       (bitset-attr->list (obj-attr-value reg 'MACH)))
   "\n"
   "</li>\n"
   "<li>\n"
   "bitsize: "
   (number->string (hw-bits reg))
   "\n"
   "</li>\n"
   (if (not (hw-scalar? reg))
       (string-list "<li>\n"
		    "array: "
		    (string-map (lambda (dim)
				  (string-append "[" (number->string dim) "]"))
				(hw-shape reg))
		    "\n"
		    (gen-pretty-reg-array-names reg)
		    "</li>\n")
       "")
   "</ul>\n"
   )
)

(define (gen-register-docs)
  (let ((regs (alpha-sort-obj-list (find register? (current-hw-list)))))
    (string-list
     "\n"
     "<hr>\n"
     "<a name=\"registers\"></a>\n"
     "<h2>Registers</h2>\n"
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "reg"))
		 regs)
     "</ul>\n"
     (string-list-map gen-reg-doc-1 regs)
     ))
)

; Instruction page.

; Generate a diagram typically used to display instruction fields.
; OPERANDS is a list of numbers (for constant valued ifields)
; or operand names.

(define (gen-iformat-table-1 bitnums names operands)
  (string-list
   "<table frame=border border=2>\n"
   "<tr>\n"
   (string-list-map (lambda (b)
		      (string-list "<td>\n"
				   (string-map (lambda (n)
						 (string-append " "
								(number->string n)))
					       b)
				   "\n"
				   "</td>\n"))
		    bitnums)
   "</tr>\n"
   "<tr>\n"
   (string-list-map (lambda (n)
		      (string-list "<td>\n"
				   n
				   "\n"
				   "</td>\n"))
		    names)
   "</tr>\n"
   "<tr>\n"
   (string-list-map (lambda (o)
		      (string-list "<td>\n"
				   (if (number? o)
				       (string-append "0x"
						      (number->string o 16))
				       o)
				   "\n"
				   "</td>\n"))
		    operands)
   "</tr>\n"
   "</table>\n")
)

; Compute the list of field bit-numbers for each field.

(define (get-ifield-bitnums widths lsb0?)
  (let* ((total-width (apply + widths))
	 (bitnums (iota total-width
			(if lsb0? (1- total-width) 0)
			(if lsb0? -1 1))))
    (let loop ((result '()) (widths widths) (bitnums bitnums))
      (if (null? widths)
	  (reverse! result)
	  (loop (cons (list-take (car widths) bitnums)
		      result)
		(cdr widths)
		(list-drop (car widths) bitnums)))))
)

; Return ordered list of operands for each field in NAMES.
; The result is an acceptable arg to gen-iformat-table-1.

(define (get-operands insn)
  (let ((ifields (ifmt-ifields (insn-ifmt insn))))
    (map (lambda (f)
	   (if (ifld-constant? f)
	       (ifld-get-value f)
	       (obj:name (ifld-get-value f))))
	 ifields))
)

; Generate a diagram typically used to display instruction fields.
; NAMES is a list of field names,
; WIDTHS is a list of their widths.

(define (gen-iformat-table insn)
  (let* ((widths (map ifld-length
		      (ifmt-ifields (insn-ifmt insn))))
	 (names (map obj:name
		     (ifmt-ifields (insn-ifmt insn))))
	 (operands (get-operands insn))
	 (lsb0? (current-arch-insn-lsb0?)))
    (gen-iformat-table-1 (get-ifield-bitnums widths lsb0?) names operands))
)

(define (gen-insn-doc-1 insn)
  (string-list
   (gen-obj-doc-header insn "insn")
   "<ul>\n"
   "<li>\n"
   "machines: "
   (string-map (lambda (mach)
		 (string-append " " mach))
	       (bitset-attr->list (obj-attr-value insn 'MACH)))
   "\n"
   "</li>\n"
   "<br>\n"
   "<li>\n"
   "syntax: "
   "<tt><font size=+2>"
   (insn-syntax insn)
   "</font></tt>\n"
   "</li>\n"
   "<br>\n"
   "<li>\n"
   "format:\n"
   (gen-iformat-table insn)
   "</li>\n"
   "<br>\n"
   (if (insn-ifield-assertion insn)
       (string-append "<li>\n"
		      "instruction field constraint:\n"
		      "<font size=+2>\n"
		      "<plaintext>" ; no trailing newline here on purpose
		      (with-output-to-string
			(lambda ()
			  (pretty-print (insn-ifield-assertion insn))))
		      "</plaintext></font>\n"
		      "</li>\n"
		      "<br>\n")
       "")
   "<li>\n"
   "semantics:\n"
   "<font size=+2>\n"
   "<plaintext>" ; no trailing newline here on purpose
   (with-output-to-string
     (lambda ()
       (pretty-print (insn-semantics insn))))
   "</plaintext></font>\n"
   "</li>\n"
   ; "<br>\n" ; not present on purpose
   (if (not (null? (insn-timing insn)))
       (string-list "<li>\n"
		    "execution unit(s):\n"
		    "<br>\n"
		    "<br>\n"
		    "<ul>\n"
		    (string-list-map
		     (lambda (t)
		       (string-append "<li>\n"
				      (car t)
				      ": "
				      (string-map (lambda (u)
						    (string-append " "
								   (obj:name (iunit:unit u))))
						  (timing:units (cdr t)))
				      "\n"
				      "</li>\n"))
		     (insn-timing insn))
		    "</ul>\n"
		    "</li>\n"
		    "<br>\n")
       "")
   "</ul>\n"
   )
)

(define (gen-insn-doc-list mach)
  (let ((insns (find (lambda (insn)
		       (mach-supports? mach insn))
		     (current-insn-list))))
    (string-list
     (gen-obj-doc-header mach "mach-insns")
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "insn"))
		 insns)
     "</ul>\n"
     ))
)

(define (gen-insn-docs)
  (let ((machs (current-mach-list))
	(insns (alpha-sort-obj-list (current-insn-list))))
    (string-list
     "\n"
     "<hr>\n"
     "<a name=\"insns\"></a>\n"
     "<h2>Instructions</h2>\n"
     "Instructions for each machine:\n"
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "mach-insns"))
		 machs)
     "</ul>\n"
     (string-list-map gen-insn-doc-list machs)
     "<p>\n"
     "<h2>Individual instructions descriptions</h2>\n"
     "<br>\n"
     (string-list-map gen-insn-doc-1 insns)
     ))
)

; Macro-instruction page.

(define (gen-macro-insn-doc-1 minsn)
  (string-list
   (gen-obj-doc-header minsn "macro-insn")
   "<ul>\n"
   "<li>\n"
   "syntax: "
   "<tt><font size=+2>"
   (minsn-syntax minsn)
   "</font></tt>\n"
   "</li>\n"
   "<br>\n"
   "<li>\n"
   "transformation:\n"
   "<font size=+2>\n"
   "<plaintext>" ; no trailing newline here on purpose
   (with-output-to-string
     (lambda ()
       (pretty-print (minsn-expansions minsn))))
   "</plaintext></font>\n"
   "</li>\n"
   "</ul>\n"
   )
)

(define (gen-macro-insn-doc-list mach)
  (let ((minsns (find (lambda (minsn)
			(mach-supports? mach minsn))
		      (current-minsn-list))))
    (string-list
     (gen-obj-doc-header mach "mach-macro-insns")
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "macro-insn"))
		 minsns)
     "</ul>\n"
     ))
)

(define (gen-macro-insn-docs)
  (let ((machs (current-mach-list))
	(minsns (alpha-sort-obj-list (current-minsn-list))))
    (string-list
     "\n"
     "<hr>\n"
     "<a name=\"macro-insns\"></a>\n"
     "<h2>Macro Instructions</h2>\n"
     "Macro instructions for each machine:\n"
     "<ul>\n"
     (string-map (lambda (o)
		   (gen-obj-list-entry o "mach-macro-insns"))
		 machs)
     "</ul>\n"
     (string-list-map gen-macro-insn-doc-list machs)
     "<p>\n"
     "<h2>Individual macro-instructions descriptions</h2>\n"
     "<br>\n"
     (string-list-map gen-macro-insn-doc-1 minsns)
     ))
)

; Assembler page.

(define (gen-asm-docs)
  (string-list
   "\n"
   "<hr>\n"
   "<a name=\"assembler\"></a>\n"
   "<h2>Assembler supplemental</h2>\n"
   )
)

; Documentation init,finish,analyzer support.

; Initialize any opcodes specific things before loading the .cpu file.

(define (doc-init!)
  (desc-init!)
  (mode-set-biggest-word-bitsizes!)
  *UNSPECIFIED*
)

; Finish any opcodes specific things after loading the .cpu file.
; This is separate from analyze-data! as cpu-load performs some
; consistency checks in between.

(define (doc-finish!)
  (desc-finish!)
  *UNSPECIFIED*
)

; Compute various needed globals and assign any computed fields of
; the various objects.  This is the standard routine that is called after
; a .cpu file is loaded.

(define (doc-analyze!)
  (desc-analyze!)

  ; Initialize the rtl->c translator.
  (rtl-c-config!)

  ; Only include semantic operands when computing the format tables if we're
  ; generating operand instance tables.
  ; ??? Actually, may always be able to exclude the semantic operands.
  ; Still need to traverse the semantics to derive machine computed attributes.
  (arch-analyze-insns! CURRENT-ARCH
		       #t ; include aliases?
		       #f) ; analyze semantics?

  *UNSPECIFIED*
)

; Top level C code generators
;
; TODO: Will eventually want to split .html output into several files to
; speed up loading into browsers.

(define (cgen-doc.html)
  (logit 1 "Generating " (current-arch-name) "-doc.html ...\n")
  (string-write
   (gen-html-copyright (string-append "Architecture documentation for "
				      (current-arch-name)
				      ".")
		       CURRENT-COPYRIGHT CURRENT-PACKAGE)
   gen-html-header
   gen-table-of-contents
   gen-arch-intro
   gen-machine-docs
   gen-model-docs
   gen-register-docs
   gen-insn-docs
   gen-macro-insn-docs
   gen-asm-docs
   gen-html-trailer
   )
)

; For debugging.

(define (cgen-all)
  (string-write
   cgen-doc.html
   )
)
