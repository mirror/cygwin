; CPU family related simulator generator, excluding decoding and model support.
; Copyright (C) 2000 Red Hat, Inc.
; This file is part of CGEN.

; ***********
; cgen-desc.h

; Declare the attributes.

(define (-gen-attr-decls)
  (string-list
   "// Insn attribute indices.\n\n"
   (gen-attr-enum-decl "cgen_insn" (current-insn-attr-list))
   "// Attributes.\n\n"
   (string-list-map gen-decl (current-attr-list))
   )
)

; Generate class to hold an instruction's attributes.

(define (-gen-insn-attr-decls)
   (let ((attrs (current-insn-attr-list)))
     (string-append
      "// Insn attributes.\n\n"
      ; FIXME: maybe make class, but that'll require a constructor.  Later.
      "struct @arch@_insn_attr {\n"
      "  unsigned int bools;\n"
      (string-map (lambda (attr)
		    (if (bool-attr? attr)
			""
			(string-append "  "
				       (gen-attr-type attr)
				       " "
				       (string-downcase (gen-sym attr))
				       ";\n")))
		  attrs)
      ;"public:\n"
      (string-map (lambda (attr)
		    (string-append
		     "  inline "
		     (gen-attr-type attr)
		     " get_" (string-downcase (gen-sym attr)) "_attr"
		     " () { return "
		     (if (bool-attr? attr)
			 (string-append "(bools & "
					(gen-attr-mask "cgen_insn" (obj:name attr))
					") != 0")
			 (string-downcase (gen-sym attr)))
		     "; }\n"))
		  attrs)
				   
      "};\n\n"
      ))
)

; Generate <cpu>-desc.h.

(define (cgen-desc.h)
  (logit 1 "Generating " (gen-cpu-name) " desc.h ...\n")

  (string-write
   (gen-copyright "Misc. entries in the @arch@ description file."
		  copyright-cygnus package-cygnus-simulators)
   "\
#ifndef DESC_@ARCH@_H
#define DESC_@ARCH@_H

namespace @arch@ {
\n"

   "// Enums.\n\n"
   (lambda () (string-map gen-decl (current-enum-list)))

   -gen-attr-decls
   -gen-insn-attr-decls

   "
} // end @arch@ namespace

#endif /* DESC_@ARCH@_H */\n"
   )
)

; **********
; cgen-cpu.h

; Print out file containing elements to add to cpu class.

; Get/set fns for hardware element HW.

(define (-gen-reg-access-defns hw)
  (let ((scalar? (hw-scalar? hw))
	(name (obj:name hw))
	(getter (hw-getter hw))
	(setter (hw-setter hw))
	(isas (bitset-attr->list (obj-attr-value hw 'ISA)))
	(type (gen-type hw)))
    (let ((get-code (if getter
			(let ((mode (hw-mode hw))
			      (args (car getter))
			      (expr (cadr getter)))
			  (string-append
			   "return "
			   (rtl-c++ mode expr
				    (if scalar?
					nil
					(list (list (car args) 'UINT "regno")))
				    #:rtl-cover-fns? #t)
			   ";"))
			(string-append
			 "return this->hardware."
			 (gen-c-symbol name)
			 (if scalar? "" "[regno]")
			 ";")))
	  (set-code (if setter
			(let ((args (car setter))
			      (expr (cadr setter)))
			  (rtl-c++
			   VOID ; not `mode', sets have mode VOID
			   expr
			   (if scalar?
			       (list (list (car args) (hw-mode hw) "newval"))
			       (list (list (car args) 'UINT "regno")
				     (list (cadr args) (hw-mode hw) "newval")))
			   #:rtl-cover-fns? #t))
			(string-append
			 "this->hardware."
			 (gen-c-symbol name)
			 (if scalar? "" "[regno]")
			 " = newval;"))))
      (string-append
       "  inline " type " "
       (gen-reg-get-fun-name hw)
       " ("
       (if scalar? "" "UINT regno")
       ") const"
       " { " get-code " }"
       "\n"
       "  inline void "
       (gen-reg-set-fun-name hw)
       " ("
       (if scalar? "" "UINT regno, ")
       type " newval)"
       " { " set-code " }"
       "\n\n")))
)

; Return a boolean indicating if hardware element HW needs storage allocated
; for it in the SIM_CPU struct.

(define (hw-need-storage? hw)
  (and (register? hw)
       (not (obj-has-attr? hw 'VIRTUAL)))
)

; Subroutine of -gen-hardware-types to generate the struct containing
; hardware elements of one isa.

(define (-gen-hardware-struct prefix hw-list)
  (if (null? hw-list)
      ; If struct is empty, leave it out to simplify generated code.
      ""
      (string-list
       (if prefix
	   (string-append "  // Hardware elements for " prefix ".\n")
	   "  // Hardware elements.\n")
       "  struct {\n"
       (string-list-map gen-decl hw-list)
       "  } "
       (if prefix
	   (string-append prefix "_")
	   "")
       "hardware;\n\n"
       ))
)

; Return C type declarations of all of the hardware elements.
; The name of the type is prepended with the cpu family name.

(define (-gen-hardware-types)
  (string-list
   "// CPU state information.\n\n"
   (if (with-multiple-isa?)
       (let ((keep-isas (current-keep-isa-name-list))
	     (candidates (find hw-need-storage? (current-hw-list))))
	 (string-list
	  ; First emit a struct that contains all the common elements.
	  ; A common element is one supported by more than isa.
	  (-gen-hardware-struct #f
				(find (lambda (hw)
					(> (count-common
					    keep-isas
					    (bitset-attr->list
					     (obj-attr-value hw 'ISA)))
					   1))
				      candidates))
	  ; Now emit structs for each isa.  These contain entries for elements
	  ; supported by exactly one isa.
	  (string-list-map (lambda (isa)
			     (-gen-hardware-struct
			      isa
			      (find (lambda (hw)
				      (= (count-common
					  keep-isas
					  (bitset-attr->list
					   (obj-attr-value hw 'ISA)))
					 1))
				    candidates)))
			   keep-isas)
	  ))
       (-gen-hardware-struct #f (find hw-need-storage? (current-hw-list))))
   )
)

; Generate <cpu>-cpu.h

(define (cgen-cpu.h)
  (logit 1 "Generating " (gen-cpu-name) " cpu.h ...\n")
  (assert-keep-one)

  ; Turn parallel execution support on if cpu needs it.
  (set-with-parallel?! (state-parallel-exec?))

  ; Initialize rtl->c generation.
  (rtl-c-config! #:rtl-cover-fns? #t)

  (string-write
   (gen-copyright "CPU class elements for @cpu@."
		  copyright-cygnus package-cygnus-simulators)
   "\
// This file is included in the middle of the cpu class struct.

public:
\n"

   -gen-hardware-types

   "  // C++ register access function templates\n"
   "#define current_cpu this\n\n"
   (lambda ()
     (string-list-map -gen-reg-access-defns
		      (find register? (current-hw-list))))
   "#undef current_cpu\n\n"
   )
)

; **********
; cgen-defs.h

; Print various parameters of the cpu family.
; A "cpu family" here is a collection of variants of a particular architecture
; that share sufficient commonality that they can be handled together.

(define (-gen-cpu-defines)
  (string-append
   "\
/* Maximum number of instructions that are fetched at a time.
   This is for LIW type instructions sets (e.g. m32r).  */\n"
   "#define @CPU@_MAX_LIW_INSNS " (number->string (cpu-liw-insns (current-cpu))) "\n\n"
   "/* Maximum number of instructions that can be executed in parallel.  */\n"
   "#define @CPU@_MAX_PARALLEL_INSNS " (number->string (cpu-parallel-insns (current-cpu))) "\n"
   "\n"
;   (gen-enum-decl '@prefix@_virtual
;		  "@prefix@ virtual insns"
;		  "@ARCH@_INSN_" ; not @CPU@ to match CGEN_INSN_TYPE in opc.h
;		  '((x-invalid 0)
;		    (x-before -1) (x-after -2)
;		    (x-begin -3) (x-chain -4) (x-cti-chain -5)))
   )
)

; Generate type of struct holding model state while executing.

(define (-gen-model-decls)
  (logit 2 "Generating model decls ...\n")
  (string-list
   (string-list-map
    (lambda (model)
      (string-list
       "typedef struct {\n"
       (if (null? (model:state model))
	   "  int empty;\n"
	   (string-map (lambda (var)
			 (string-append "  "
					(mode:c-type (mode:lookup (cadr var)))
					" "
					(gen-c-symbol (car var))
					";\n"))
		       (model:state model)))
       "} " 
       (if (null? (model:state model)) "BLANK" "@CPU@") "_MODEL_DATA;\n\n"
       ))
    (current-model-list))
   "   
typedef int (@CPU@_MODEL_FN) (struct @cpu@_cpu*, void*);

typedef struct {
  /* This is an integer that identifies this insn.
     How this works is up to the target.  */
  int num;

  /* Function to handle insn-specific profiling.  */
  @CPU@_MODEL_FN *model_fn;

  /* Array of function units used by this insn.  */
  UNIT units[MAX_UNITS];
} @CPU@_INSN_TIMING;"
   )
)

; Utility of gen-parallel-exec-type to generate the definition of one
; structure in PAREXEC.
; SFMT is an <sformat> object.

(define (gen-parallel-exec-elm sfmt)
  (string-append
   "    struct { /* " (obj:comment sfmt) " */\n"
   (let ((sem-ops
	  ((if (with-parallel-write?) sfmt-out-ops sfmt-in-ops) sfmt)))
     (if (null? sem-ops)
	 "      int empty;\n"
	 (string-map
	  (lambda (op)
	    (logit 2 "Processing operand " (obj:name op) " of format "
		   (obj:name sfmt) " ...\n")
	      (if (with-parallel-write?)
		  (let ((index-type (and (op-save-index? op)
					 (gen-index-type op sfmt))))
		    (string-append "      " (gen-type op)
				   " " (gen-sym op) ";\n"
				   (if index-type
				       (string-append "      " index-type 
						      " " (gen-sym op) "_idx;\n")
				       "")))
		  (string-append "      "
				 (gen-type op)
				 " "
				 (gen-sym op)
				 ";\n")))
	  sem-ops)))
   "    } " (gen-sym sfmt) ";\n"
   )
)

; Generate the definition of the structure that holds register values, etc.
; for use during parallel execution.  When instructions are executed parallelly
; either
; - their inputs are read before their outputs are written.  Thus we have to
; fetch the input values of several instructions before executing any of them.
; - or their outputs are queued here first and then written out after all insns
; have executed.
; The fetched/queued values are stored in an array of PAREXEC structs, one
; element per instruction.

(define (gen-parallel-exec-type)
  (logit 2 "Generating PAREXEC type ...\n")
  (string-append
   (if (with-parallel-write?)
       "/* Queued output values of an instruction.  */\n"
       "/* Fetched input values of an instruction.  */\n")
   "\

struct @prefix@_parexec {
  union {\n"
   (string-map gen-parallel-exec-elm (current-sfmt-list))
   "\
  } operands;
  /* For conditionally written operands, bitmask of which ones were.  */
  unsigned long long written;
};\n\n"
   )
)

; Generate the TRACE_RECORD struct definition.

(define (-gen-trace-record-type)
  (string-list
   "\
/* Collection of various things for the trace handler to use.  */

typedef struct @prefix@_trace_record {
  PCADDR pc;
  /* FIXME:wip */
} @CPU@_TRACE_RECORD;
\n"
   )
)

; Generate <cpu>-defs.h

(define (cgen-defs.h)
  (logit 1 "Generating " (gen-cpu-name) " defs.h ...\n")
  (assert-keep-one)

  ; Turn parallel execution support on if cpu needs it.
  (set-with-parallel?! (state-parallel-exec?))

  ; Initialize rtl->c generation.
  (rtl-c-config! #:rtl-cover-fns? #t)

  (string-write
   (gen-copyright "CPU family header for @cpu@ / @prefix@."
		  copyright-cygnus package-cygnus-simulators)
   "\
#ifndef DEFS_@PREFIX@_H
#define DEFS_@PREFIX@_H

namespace @cpu@ {
\n"

   (if (with-parallel?)
       gen-parallel-exec-type
       "")

   "\
} // end @cpu@ namespace

#endif /* DEFS_@PREFIX@_H */\n"
   )
)

; **************
; cgen-write.cxx

; This is the other way of implementing parallel execution support.
; Instead of fetching all the input operands first, write all the output
; operands and their addresses to holding variables, and then run a
; post-processing pass to update the cpu state.

; Return C code to fetch and save all output operands to instructions with
; <sformat> SFMT.

(define (-gen-write-args sfmt)
  (string-map (lambda (op) (op:write op sfmt))
	      (sfmt-out-ops sfmt))
)

; Utility of gen-write-fns to generate a writer function for <sformat> SFMT.

(define (-gen-write-fn sfmt)
  (logit 2 "Processing write function for \"" (obj:name sfmt) "\" ...\n")
  (string-list
   "\nsem_status\n"
   (-gen-write-fn-name sfmt) " (@cpu@_cpu* current_cpu, @prefix@_scache* sem, @prefix@_parexec* par_exec)\n"
   "{\n"
   (if (with-scache?)
       (gen-define-field-macro sfmt)
       "")
   (gen-define-parallel-operand-macro sfmt)
   "  @prefix@_scache* abuf = sem;\n"
   "  unsigned long long written = abuf->written;\n"
   "  PCADDR pc = abuf->addr;\n"
   "  PCADDR npc = 0; // dummy value for branches\n"
   "  sem_status status = SEM_STATUS_NORMAL; // ditto\n"
   "\n"
   (-gen-write-args sfmt)
   "\n"
   "  return status;\n"
   (gen-undef-parallel-operand-macro sfmt)
   (if (with-scache?)
       (gen-undef-field-macro sfmt)
       "")
   "}\n\n")
)

(define (-gen-write-fns)
  (logit 2 "Processing writer functions ...\n")
  (string-write-map (lambda (sfmt) (-gen-write-fn sfmt))
		    (current-sfmt-list))
)


; Generate <cpu>-write.cxx.

(define (cgen-write.cxx)
  (logit 1 "Generating " (gen-cpu-name) " write.cxx ...\n")
  (assert-keep-one)

  (sim-analyze-insns!)

  ; Turn parallel execution support off.
  (set-with-parallel?! #f)

  ; Tell the rtx->c translator we are the simulator.
  (rtl-c-config! #:rtl-cover-fns? #t)

  (string-write
   (gen-copyright (string-append "Simulator instruction operand writer for "
				(current-arch-name) ".")
		 copyright-cygnus package-cygnus-simulators)
   "\

#include \"@cpu@.h\"
using namespace @cpu@;

"
   -gen-write-fns
   )
)

; ******************
; cgen-semantics.cxx

; Return C code to perform the semantics of INSN.

(define (gen-semantic-code insn)
  ; Indicate generating code for INSN.
  ; Use the compiled form if available.
  ; The case when they're not available is for virtual insns.
  (let ((sem-c-code
	 (if (insn-compiled-semantics insn)
	     (rtl-c++-parsed VOID (insn-compiled-semantics insn) nil
			     #:rtl-cover-fns? #t
			     #:owner insn)
	     (rtl-c++ VOID (insn-semantics insn) nil
		      #:rtl-cover-fns? #t
		      #:owner insn)))
	)
    sem-c-code)
)

; Return definition of C function to perform INSN.
; This version handles the with-scache case.

(define (-gen-scache-semantic-fn insn)
  (logit 2 "Processing semantics for " (obj:name insn) ": \"" (insn-syntax insn) "\" ...\n")
  (set! -with-profile? -with-profile-fn?)
  (let ((cti? (insn-cti? insn))
	(insn-len (insn-length-bytes insn)))
    (string-list
     "// ********** " (obj:name insn) ": " (insn-syntax insn) "\n\n"
     (if (with-parallel?)
	 "void\n"
	 "sem_status\n")
     "@prefix@_sem_" (gen-sym insn)
     (if (with-parallel?)
	 " (@cpu@_cpu* current_cpu, @prefix@_scache* sem, @prefix@_parexec* par_exec)\n"
	 " (@cpu@_cpu* current_cpu, @prefix@_scache* sem)\n")
     "{\n"
     (gen-define-field-macro (insn-sfmt insn))
     (if (with-parallel?)
	 (gen-define-parallel-operand-macro (insn-sfmt insn))
	 "")
     "  sem_status status = SEM_STATUS_NORMAL;\n"
     "  @prefix@_scache* abuf = sem;\n"
     ; Unconditionally written operands are not recorded here.
     (if (or (with-profile?) (with-parallel-write?))
	 "  unsigned long long written = 0;\n"
	 "")
     ; The address of this insn, needed by extraction and semantic code.
     ; Note that the address recorded in the cpu state struct is not used.
     ; For faster engines that copy will be out of date.
     "  PCADDR pc = abuf->addr;\n"
     "  PCADDR npc = pc + " (number->string insn-len) ";\n"
     "\n"
     (gen-semantic-code insn)
     "\n"
     ; Only update what's been written if some are conditionally written.
     ; Otherwise we know they're all written so there's no point in
     ; keeping track.
     (if (or (with-profile?) (with-parallel-write?))
	 (if (-any-cond-written? (insn-sfmt insn))
	     "  abuf->written = written;\n"
	     "")
	 "")
     (if cti?
	 "  current_cpu->done_cti_insn (npc, status);\n"
	 "  current_cpu->done_insn (npc, status);\n")
     (if (with-parallel?)
	 ""
	 "  return status;\n")
     (if (with-parallel?)
	 (gen-undef-parallel-operand-macro (insn-sfmt insn))
	 "")
     (gen-undef-field-macro (insn-sfmt insn))
     "}\n\n"
     ))
)

(define (-gen-all-semantic-fns)
  (logit 2 "Processing semantics ...\n")
  (let ((insns (scache-engine-insns)))
    (if (with-scache?)
	(string-write-map -gen-scache-semantic-fn insns)
	(error "must specify `with-scache'")))
)

; Generate <cpu>-sem.cxx.
; Each instruction is implemented in its own function.

(define (cgen-semantics.cxx)
  (logit 1 "Generating " (gen-cpu-name) " semantics.cxx ...\n")
  (assert-keep-one)

  (sim-analyze-insns!)

  ; Turn parallel execution support on if cpu needs it.
  (set-with-parallel?! (state-parallel-exec?))

  ; Tell the rtx->c translator we are the simulator.
  (rtl-c-config! #:rtl-cover-fns? #t)

  ; Indicate we're currently not generating a pbb engine.
  (set-current-pbb-engine?! #f)

  (string-write
   (gen-copyright "Simulator instruction semantics for @prefix@."
		  copyright-cygnus package-cygnus-simulators)
   "\

#include \"@cpu@.h\"

using namespace @cpu@; // FIXME: namespace organization still wip

#define GET_ATTR(name) GET_ATTR_##name ()

\n"

   -gen-all-semantic-fns
   )
)

; *******************
; cgen-sem-switch.cxx
;
; The semantic switch engine has two flavors: one case per insn, and one
; case per "frag" (where each insn is split into one or more fragments).

; Utility of -gen-sem-case to return the mask of operands always written
; to in <sformat> SFMT.
; ??? Not currently used.

(define (-uncond-written-mask sfmt)
  (apply + (map (lambda (op)
		  (if (op:cond? op)
		      0
		      (logsll 1 (op:num op))))
		(sfmt-out-ops sfmt)))
)

; Utility of -gen-sem-case to return #t if any operand in <sformat> SFMT is
; conditionally written to.

(define (-any-cond-written? sfmt)
  (any-true? (map op:cond? (sfmt-out-ops sfmt)))
)

; One case per insn version.

; Generate a switch case to perform INSN.

(define (-gen-sem-case insn parallel?)
  (logit 2 "Processing "
	 (if parallel? "parallel " "")
	 "semantic switch case for \"" (insn-syntax insn) "\" ...\n")
  (set! -with-profile? -with-profile-sw?)
  (let ((cti? (insn-cti? insn))
	(insn-len (insn-length-bytes insn)))
    (string-list
     ; INSN_ is prepended here and not elsewhere to avoid name collisions
     ; with symbols like AND, etc.
     "\
// ********** " (insn-syntax insn) "

  CASE (INSN_" (if parallel? "PAR_" "") (string-upcase (gen-sym insn)) "):
    {
      @prefix@_scache* abuf = vpc;\n"
     (if (with-scache?)
	 (gen-define-field-macro (insn-sfmt insn))
	 "")
     (if parallel?
	 (gen-define-parallel-operand-macro (insn-sfmt insn))
	 "")
     ; Unconditionally written operands are not recorded here.
     (if (or (with-profile?) (with-parallel-write?))
	 "      unsigned long long written = 0;\n"
	 "")
     ; The address of this insn, needed by extraction and semantic code.
     ; Note that the address recorded in the cpu state struct is not used.
     "      PCADDR pc = abuf->addr;\n"
     (if (and cti? (not parallel?))
	 (string-append "      PCADDR npc;\n"
			"      branch_status br_status = BRANCH_UNTAKEN;\n")
	 "")
     (string-list "      vpc = vpc + 1;\n")
     ; Emit setup-semantics code for real insns.
     (if (and (insn-real? insn)
	      (isa-setup-semantics (current-isa)))
	 (string-append
	  "      "
	  (rtl-c++ VOID (isa-setup-semantics (current-isa)) nil
		   #:rtl-cover-fns? #t
		   #:owner insn))
	 "")
     "\n"
     (gen-semantic-code insn)
     "\n"
     ; Only update what's been written if some are conditionally written.
     ; Otherwise we know they're all written so there's no point in
     ; keeping track.
     (if (or (with-profile?) (with-parallel-write?))
	 (if (-any-cond-written? (insn-sfmt insn))
	     "        abuf->written = written;\n"
	     "")
	 "")
     (if (and cti? (not parallel?))
	 (string-append "      pbb_br_npc = npc;\n"
			"      pbb_br_status = br_status;\n")
	 "")
     (if parallel?
	 (gen-undef-parallel-operand-macro (insn-sfmt insn))
	 "")
     (if (with-scache?)
	 (gen-undef-field-macro (insn-sfmt insn))
	 "")
     "    }\n"
     "    NEXT (vpc);\n\n"
     ))
)

(define (-gen-sem-switch)
  (logit 2 "Processing semantic switch ...\n")
  ; Turn parallel execution support off.
  (set-with-parallel?! #f)
  (string-write-map (lambda (insn) (-gen-sem-case insn #f))
		    (non-multi-insns (non-alias-insns (current-insn-list))))
)

; Generate the guts of a C switch statement to execute parallel instructions.
; This switch is included after the non-parallel instructions in the semantic
; switch.
;
; ??? We duplicate the writeback case for each insn, even though we only need
; one case per insn format.  The former keeps the code for each insn
; together and might improve cache usage.  On the other hand the latter
; reduces the amount of code, though it is believed that in this particular
; instance the win isn't big enough.

(define (-gen-parallel-sem-switch)
  (logit 2 "Processing parallel insn semantic switch ...\n")
  ; Turn parallel execution support on.
  (set-with-parallel?! #t)
  (string-write-map (lambda (insn)
		      (string-list (-gen-sem-case insn #t)
				   (-gen-write-case (insn-sfmt insn) insn)))
		    (parallel-insns (current-insn-list)))
)

; Return computed-goto engine.

(define (-gen-sem-switch-engine)
  (string-write
   "\
void
@cpu@_cpu::@prefix@_pbb_run ()
{
  @cpu@_cpu* current_cpu = this;
  @prefix@_scache* vpc;
  // These two are used to pass data from cti insns to the cti-chain insn.
  PCADDR pbb_br_npc;
  branch_status pbb_br_status;

#ifdef __GNUC__
{
  static const struct sem_labels
    {
      enum @prefix@_insn_type insn;
      void *label;
    }
  labels[] = 
    {\n"

   (lambda ()
     (string-write-map (lambda (insn)
			 (string-append "      { "
					"@PREFIX@_INSN_"
					(string-upcase (gen-sym insn))
					", && case_INSN_"
					(string-upcase (gen-sym insn))
					" },\n"))
		       (non-multi-insns (non-alias-insns (current-insn-list)))))

   (if (state-parallel-exec?)
       (lambda ()
	 (string-write-map (lambda (insn)
			     (string-append "      { "
					    "@PREFIX@_INSN_PAR_"
					    (string-upcase (gen-sym insn))
					    ", && case_INSN_PAR_"
					    (string-upcase (gen-sym insn))
					    " },\n"
					    "      { "
					    "@PREFIX@_INSN_WRITE_"
					    (string-upcase (gen-sym insn))
					    ", && case_INSN_WRITE_"
					    (string-upcase (gen-sym insn))
					    " },\n"))
			   (parallel-insns (current-insn-list))))
       "")

   "    { (@prefix@_insn_type) 0, 0 }
  };

  if (! @prefix@_idesc::idesc_table_initialized_p)
    {
      for (int i=0; labels[i].label != 0; i++)
	@prefix@_idesc::idesc_table[labels[i].insn].cgoto.label = labels[i].label; 

      // confirm that table is all filled up
      for (int i=0; i<@PREFIX@_INSN_MAX; i++)
        assert (@prefix@_idesc::idesc_table[i].cgoto.label != 0);

      // Initialize the compiler virtual insn.
      current_cpu->@prefix@_engine.compile_begin_insn (current_cpu);

      @prefix@_idesc::idesc_table_initialized_p = true;
    }
}
#endif

#ifdef __GNUC__
#define CASE(X) case_##X
// Branch to next handler without going around main loop.
#define NEXT(vpc) goto * vpc->execute.cgoto.label;
// Break out of threaded interpreter and return to \"main loop\".
#define BREAK(vpc) goto end_switch
#else
#define CASE(X) case @PREFIX@_##X
#define NEXT(vpc) goto restart
#define BREAK(vpc) break
#endif

  // Get next insn to execute.
  vpc = current_cpu->@prefix@_engine.get_next_vpc (current_cpu->h_pc_get ());

restart:
#ifdef __GNUC__
  goto * vpc->execute.cgoto.label;
#else
  switch (vpc->idesc->sem_index)
#endif

  {
"

  -gen-sem-switch

   (if (state-parallel-exec?)
       -gen-parallel-sem-switch
       "")

"
#ifdef __GNUC__
    end_switch: ;
#else
    default: abort();
#endif
  }

  // Save vpc for next time.
  current_cpu->@prefix@_engine.set_next_vpc (vpc);
}
\n"
   )
)

; Semantic frag version.

; Return declaration of frag enum.

(define (-gen-sfrag-enum-decl frag-list)
  (gen-enum-decl "@prefix@_frag_type"
		 "semantic fragments in cpu family @prefix@"
		 "@PREFIX@_FRAG_"
		 (append '((list-end))
			 (map (lambda (i)
				(cons (obj:name i)
				      (cons '-
					    (atlist-attrs (obj-atlist i)))))
			      frag-list)
			 '((max))))
)

; Return header file decls for semantic frag threaded engine.

(define (-gen-sfrag-engine-decls)
  (string-write
   "namespace @cpu@ {\n\n"

   ; FIXME: vector->list
   (-gen-sfrag-enum-decl (vector->list (sim-sfrag-frag-table)))

   "\
struct @prefix@_insn_frag {
  @PREFIX@_INSN_TYPE itype;
  // 4: header+middle+trailer+delimiter
  @PREFIX@_FRAG_TYPE ftype[4];
};

struct @prefix@_pbb_label {
  @PREFIX@_FRAG_TYPE frag;
  void *label;
};

} // end @cpu@ namespace
\n")
)

; Return C code to perform the semantics of FRAG.
; LOCALS is a list of sequence locals made global to all frags.
; Each element is (symbol <mode> "c-var-name").

(define (-gen-sfrag-code frag locals)
  ; Indicate generating code for FRAG.
  ; Use the compiled form if available.
  ; The case when they're not available is for virtual insns.
  (let ((sem (sfrag-compiled-semantics frag))
	; If the frag has one owner, use it.  Otherwise indicate the owner is
	; unknown.  In cases where the owner is needed by the semantics, the
	; frag should have only one owner.
	(owner (if (= (length (sfrag-users frag)) 1)
		   (car (sfrag-users frag))
		   #f))
	)
    (if sem
	(rtl-c++-parsed VOID sem locals
			#:rtl-cover-fns? #t
			#:owner owner)
	(rtl-c++ VOID (sfrag-semantics frag) locals
		 #:rtl-cover-fns? #t
		 #:owner owner)))
)

; Generate a switch case to perform FRAG.
; LOCALS is a list of sequence locals made global to all frags.
; Each element is (symbol <mode> "c-var-name").

(define (-gen-sfrag-case frag locals)
  (set! -with-profile? -with-profile-sw?)
  (let ((cti? (sfmt-cti? (sfrag-sfmt frag)))
	(parallel? (sfrag-parallel? frag)))
    (logit 2 "Processing "
	   (if parallel? "parallel " "")
	   "semantic switch case for \"" (obj:name frag) "\" ...\n")
    (string-list
     ; FRAG_ is prepended here and not elsewhere to avoid name collisions
     ; with symbols like AND, etc.
     "\
// ********** "
     (if (= (length (sfrag-users frag)) 1)
	 "used only by:"
	 "used by:")
     (string-drop1
      (string-map (lambda (user)
		    (string-append ", " (obj:name user)))
		  (sfrag-users frag)))
     "

  CASE (FRAG_" (string-upcase (gen-sym frag)) "):
    {\n"
     (if (sfrag-header? frag)
	 (string-append "      abuf = vpc;\n"
			"      vpc = vpc + 1;\n")
	 "")
     (gen-define-field-macro (sfrag-sfmt frag))
     (if parallel?
	 (gen-define-parallel-operand-macro (sfrag-sfmt frag))
	 "")
     ; Unconditionally written operands are not recorded here.
     (if (or (with-profile?) (with-parallel-write?))
	 "      unsigned long long written = 0;\n"
	 "")
     ; The address of this insn, needed by extraction and semantic code.
     ; Note that the address recorded in the cpu state struct is not used.
     "      PCADDR pc = abuf->addr;\n"
     (if (and cti?
	      (not parallel?)
	      (sfrag-header? frag))
	 (string-append ; "      npc = 0;\n" ??? needed?
	  "      br_status = BRANCH_UNTAKEN;\n")
	 "")
     ; Emit setup-semantics code for headers of real insns.
     (if (and (sfrag-header? frag)
	      (not (obj-has-attr? frag 'VIRTUAL))
	      (isa-setup-semantics (current-isa)))
	 (string-append
	  "      "
	  (rtl-c++ VOID (isa-setup-semantics (current-isa)) nil
		   #:rtl-cover-fns? #t
		   #:owner #f))
	 "")
     "\n"
     (-gen-sfrag-code frag locals)
     "\n"
     ; Only update what's been written if some are conditionally written.
     ; Otherwise we know they're all written so there's no point in
     ; keeping track.
     (if (or (with-profile?) (with-parallel-write?))
	 (if (-any-cond-written? (sfrag-sfmt frag))
	     "        abuf->written = written;\n"
	     "")
	 "")
     (if (and cti?
	      (not parallel?)
	      (sfrag-trailer? frag))
	 (string-append "      pbb_br_npc = npc;\n"
			"      pbb_br_status = br_status;\n")
	 "")
     (if parallel?
	 (gen-undef-parallel-operand-macro (sfrag-sfmt frag))
	 "")
     (gen-undef-field-macro (sfrag-sfmt frag))
     "    }\n"
     (if (sfrag-trailer? frag)
	 "    NEXT_INSN (vpc, fragpc);\n"
	 "    NEXT_FRAG (fragpc);\n")
     "\n"
     ))
)

; Convert locals from form computed by sem-find-common-frags to that needed by
; -gen-sfrag-engine-code (and ultimately rtl-c++).

(define (-frag-convert-c-locals locals)
  (map (lambda (local)
	 (list (car local) (mode:lookup (cadr local))
	       (gen-c-symbol (car local))))
       locals)
)

; Return definition of insn frag usage table.

(define (-gen-sfrag-engine-frag-table insn-list frag-table frag-usage)
  (string-write
   "\
// Table of frags used by each insn.

const @prefix@_insn_frag @prefix@_frag_usage[] = {\n"

   (lambda ()
     (for-each (lambda (insn frag-nums)
		 (string-write "  { "
			       "@PREFIX@_INSN_"
			       (string-upcase (gen-sym insn))
			       (string-map (lambda (frag-num)
					     (string-append ", @PREFIX@_FRAG_"
							    (string-upcase (gen-sym (vector-ref frag-table frag-num)))))
					   frag-nums)
			       ", @PREFIX@_FRAG_LIST_END },\n"))
	       insn-list frag-usage)
     "")

   "\
  { @PREFIX@_INSN_MAX }
};
\n"
   )
)

; Return sfrag computed-goto engine.
; LOCALS is a list of sequence locals made global to all frags.
; Each element is (symbol <mode> "c-var-name").

(define (-gen-sfrag-engine-fn frag-table locals)
  (string-write
   "\
void
@cpu@_cpu::@prefix@_pbb_run ()
{
  @cpu@_cpu* current_cpu = this;
  @prefix@_scache* vpc;
  @prefix@_scache* abuf;
#ifdef __GNUC__
  void** fragpc;
#else
  ARM_FRAG_TYPE* fragpc;
#endif

#ifdef __GNUC__
{
  static const @prefix@_pbb_label labels[] =
    {
      { @PREFIX@_FRAG_LIST_END, 0 },
"

   (lambda ()
     (string-write-map (lambda (frag)
			 (string-append "      { "
					"@PREFIX@_FRAG_"
					(string-upcase (gen-sym frag))
					", && case_FRAG_"
					(string-upcase (gen-sym frag))
					" },\n"))
		       ; FIXME: vector->list
		       (vector->list frag-table)))

   "\
      { @PREFIX@_FRAG_MAX, 0 }
    };

  if (! @prefix@_idesc::idesc_table_initialized_p)
    {
      // Several tables are in play here:
      // idesc table: const table of misc things for each insn
      // frag usage table: const set of frags used by each insn
      // frag label table: same as frag usage table, but contains labels
      // selected insn frag table: table of pointers to either the frag usage
      // table (if !gnuc) or frag label table (if gnuc) for the currently
      // selected ISA.  Insns not in the ISA are redirected to the `invalid'
      // insn handler.  FIXME: This one isn't implemented yet.

      // Allocate frag label table and point idesc table entries at it.
      // FIXME: Temporary hack, to be redone.
      static void** frag_label_table;
      frag_label_table = new (void*) [@PREFIX@_INSN_MAX * 4];
      memset (frag_label_table, 0, sizeof (void*) * @PREFIX@_INSN_MAX * 4);
      int i;
      void** v;
      for (i = 0, v = frag_label_table; i < @PREFIX@_INSN_MAX; ++i)
	{
	  @prefix@_idesc::idesc_table[@prefix@_frag_usage[i].itype].cgoto.frags = v;
	  for (int j = 0; @prefix@_frag_usage[i].ftype[j] != @PREFIX@_FRAG_LIST_END; ++j)
	    *v++ = labels[@prefix@_frag_usage[i].ftype[j]].label;
	}

      // Record frags used by each insn.
      //for (int i = 0; @prefix@_frag_usage[i].itype != @PREFIX@_INSN_MAX; ++i)
      //  @prefix@_idesc::idesc_table[@prefix@_frag_usage[i].itype].frags = & @prefix@_frag_usage[i];

      // Initialize the compiler virtual insn.
      // FIXME: Also needed if !gnuc.
      current_cpu->@prefix@_engine.compile_begin_insn (current_cpu);

      @prefix@_idesc::idesc_table_initialized_p = true;
    }
}
#endif

#ifdef __GNUC__
#define CASE(X) case_##X
// Branch to next handler without going around main loop.
#define NEXT_INSN(vpc, fragpc) fragpc = vpc->execute.cgoto.frags; goto * *fragpc
#define NEXT_FRAG(fragpc) ++fragpc; goto * *fragpc
// Break out of threaded interpreter and return to \"main loop\".
#define BREAK(vpc) goto end_switch
#else
#define CASE(X) case @PREFIX@_##X
#define NEXT_INSN(vpc, fragpc) fragpc = vpc->idesc->frags; goto restart
#define NEXT_FRAG(fragpc) ++fragpc; goto restart
#define BREAK(vpc) break
#endif

  // Get next insn to execute.
  vpc = current_cpu->@prefix@_engine.get_next_vpc (current_cpu->h_pc_get ());

  {
    // These two are used to pass data from cti insns to the cti-chain insn.
    PCADDR pbb_br_npc;
    branch_status pbb_br_status;
    // These two are used to build up values of the previous two.
    PCADDR npc;
    branch_status br_status;
    // Top level locals moved here so they're usable by multiple fragments.
"

   (lambda ()
     (string-write-map (lambda (local)
			 (string-append "    "
					(mode:c-type (cadr local))
					" "
					(caddr local)
					";\n"))
		       locals))

   "\

restart:
#ifdef __GNUC__
  fragpc = vpc->execute.cgoto.frags;
  goto * *fragpc;
#else
  fragpc = vpc->idesc->frags;
  switch (*fragpc)
#endif

    {

"

   (lambda ()
     ; Turn parallel execution support off.
     ; ??? Still needed?
     (set-with-parallel?! #f)
     (string-write-map (lambda (frag)
			 (-gen-sfrag-case frag locals))
		       ; FIXME: vector->list
		       (vector->list frag-table)))

   "
#ifdef __GNUC__
    end_switch: ;
#else
    default: abort ();
#endif
    }
  }

  // Save vpc for next time.
  current_cpu->@prefix@_engine.set_next_vpc (vpc);
}
\n")
)

(define (-gen-sfrag-engine)
  (string-write
   (lambda ()
     (-gen-sfrag-engine-frag-table (sim-sfrag-insn-list)
				   (sim-sfrag-frag-table)
				   (sim-sfrag-usage-table)))
   (lambda ()
     (-gen-sfrag-engine-fn (sim-sfrag-frag-table)
			   (-frag-convert-c-locals (sim-sfrag-locals-list))))
   )
)

; Generate sem-switch.cxx.

(define (cgen-sem-switch.cxx)
  (logit 1 "Generating " (gen-cpu-name) " sem-switch.cxx ...\n")

  (sim-analyze-insns!)
  (if (with-sem-frags?)
      (sim-sfrag-analyze-insns!))

  ; Turn parallel execution support off.
  ; It is later turned on/off when generating the actual semantic code.
  (set-with-parallel?! #f)

  ; Tell the rtx->c translator we are the simulator.
  (rtl-c-config! #:rtl-cover-fns? #t)

  ; Indicate we're currently generating a pbb engine.
  (set-current-pbb-engine?! #t)

  (string-write
   (gen-copyright "Simulator instruction semantics for @prefix@."
		  copyright-cygnus package-cygnus-simulators)
   "\

#include \"@cpu@.h\"

using namespace @cpu@; // FIXME: namespace organization still wip

#define GET_ATTR(name) GET_ATTR_##name ()

\n"

   (if (with-sem-frags?)
       -gen-sfrag-engine-decls
       "")

   (if (with-sem-frags?)
       -gen-sfrag-engine
       -gen-sem-switch-engine)
   )
)
