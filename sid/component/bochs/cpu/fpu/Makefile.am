## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(srcdir)/../.. -I$(srcdir) -I$(srcdir)/stubs -DUSE_WITH_CPU_SIM -DPARANOID -DNO_ASSEMBLER

noinst_LTLIBRARIES = libfpu.la

libfpu_la_SOURCES = fpu.cc wmFPUemu_glue.cc fpu_entry.c errors.c reg_ld_str.c load_store.c fpu_arith.c fpu_aux.c fpu_etc.c fpu_tags.c fpu_trig.c poly_atan.c poly_l2.c poly_2xm1.c poly_sin.c poly_tan.c reg_add_sub.c reg_compare.c reg_constant.c reg_convert.c reg_divide.c reg_mul.c reg_u_add.c reg_u_div.c reg_u_mul.c reg_u_sub.c div_small.c reg_norm.c reg_round.c wm_shrx.c wm_sqrt.c div_Xsig.c polynom_Xsig.c round_Xsig.c shr_Xsig.c mul_Xsig.c

libfpu_la_LDFLAGS = -no-undefined
