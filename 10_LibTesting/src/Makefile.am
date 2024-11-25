if COND_GCOV
CFLAGS = -std=c99 -Wall -Wextra -O0 -g -fprofile-arcs -ftest-coverage
else
CFLAGS = -std=c99 -Wall -Wextra -O3 -g3
endif

libbuf.c:	buf.h

lib_LTLIBRARIES = libbuf.la

gcov:
	gcov -o .libs libbuf -b -t | egrep -v '[[:digit:]]:[ /][*]'
