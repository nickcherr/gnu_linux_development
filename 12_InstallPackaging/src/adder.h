#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include "config.h"

/** @file adder.c
 * Programm adds two numbers. With --help key it shows help message.
 */

#define _(STRING) gettext(STRING)

/** Adds @p a and @p b
 * 
 * @param a first additive
 * @param b second additive
 * @return sum of @p a and @p b
 */
int sum(int a, int b);