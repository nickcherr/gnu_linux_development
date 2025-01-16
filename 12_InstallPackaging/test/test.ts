#include <check.h>
#include "../src/adder.h"


#test t
    fail_unless(sum(1, 1) == 2);
#test f_t
    fail_unless(sum(37, 5) == 42);