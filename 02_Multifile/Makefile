CC = cc
CFLAGS = 
GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so 
TEST_RESULTS = test_*
OBJECT_FILES = const.o fun.o prog.o

%.o:	%.c
	$(CC) $(CFLAGS) $< -c -o $@

all:	prog prog-a prog-so

prog:	$(OBJECT_FILES)

prog-a:	prog.o liboutput_static.a
	$(CC) -L. $< -loutput_static -o prog-a

prog-so: clean_object_files prog.o
	make CFLAGS=-fPIC $(OBJECT_FILES)
	$(CC) -shared const.o fun.o -o liboutput.so
	$(CC) -L. prog.o -loutput -o $@

liboutput_static.a:	const.o fun.o
	ar -rcs $@ $^

fun.o:	outlib.h

test: all test_zero_args test_one_arg test_three_args clean_generates

test_zero_args:
	./prog   							> test_zero_1 2>&1
	./prog-a 							> test_zero_2 2>&1
	LD_LIBRARY_PATH=`pwd` 	./prog-so 	> test_zero_3 2>&1

	cmp test_zero_1 test_zero_2
	cmp test_zero_1 test_zero_3

test_one_arg:
	./prog   							1 > test_one_1 2>&1
	./prog-a 							1 > test_one_2 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so 	1 > test_one_3 2>&1

	cmp test_one_1 test_one_2
	cmp test_one_1 test_one_3

test_three_args:
	./prog   							1 2 3	> test_three_1 2>&1
	./prog-a 							1 2 3	> test_three_2 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so 	1 2 3 	> test_three_3 2>&1

	cmp test_three_1 test_three_2
	cmp test_three_1 test_three_3

clean_object_files:
	rm -f $(OBJECT_FILES)

clean_generates: clean_object_files
	rm -f $(GENERATES)

clean_test_results:
	rm -f $(TEST_RESULTS)

clean:	clean_generates clean_test_results
