#include "adder.h"

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
int sum(int a, int b)
{
    return a + b;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printf(_("This programm adds two numbers. Very useful.\n"));
        return 0;
    }
    int a, b;
    printf(_("Write first number:\n"));
    scanf("%d", &a);
    printf(_("Write second number:\n"));
    scanf("%d", &b);
    printf(_("Summ of your numbers: %d\n"), sum(a, b));
    return 0;
}