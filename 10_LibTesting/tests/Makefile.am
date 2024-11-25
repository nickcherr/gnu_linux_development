TESTS_ENVIRONMENT = CK_VERBOSITY=$(CK_VERBOSITY)

check_PROGRAMS = 1.c 2.c 3.c 4.c 5.c
TESTS = 1.c 2.c 3.c 4.c 5.c

AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@
