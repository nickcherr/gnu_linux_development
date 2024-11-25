TESTS_ENVIRONMENT = CK_VERBOSITY=$(CK_VERBOSITY)

check_PROGRAMS = 1 2 3 4 5
TESTS = 1 2 3 4 5

AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@
