all: range.o

range.o:
	gcc -O0 -g -o range.o range.c

test: range.o
	gdb --quiet range.o < 1.gdb | grep "@@@" > result-1.txt
	if cmp expected-1.txt result-1.txt; then \
		echo "\e[32mTest 1 PASSED\e[0m"; \
	else \
		echo "\e[31mTest 1 FAILED\e[0m"; \
	fi
	
	gdb --quiet range.o < 2.gdb | grep "@@@" > result-2.txt
	if cmp expected-2.txt result-2.txt; then \
		echo "\e[32mTest 2 PASSED\e[0m"; \
	else \
		echo "\e[31mTest 2 FAILED\e[0m"; \
	fi

clean:
	rm range.o result-*.txt
