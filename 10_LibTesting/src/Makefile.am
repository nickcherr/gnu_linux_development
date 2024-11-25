CFLAGS = -std=c99 -Wall -Wextra
if COND_GCOV
CFLAGS += -O0 -g -fprofile-arcs -ftest-coverage
else
CFLAGS +=  -O3 -g3
endif

libbuf.c:	buf.h

lib_LTLIBRARIES = libbuf.la

gcov:
	gcov -o .libs libbuf -b -t | egrep -v '[[:digit:]]:[ /][*]'
