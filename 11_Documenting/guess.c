/** @mainpage
*   # Program that guesses user's number.
*/
/** @page Program that guesses user's number.
*   Think of a number between 1 and 100 and answer some questions.
*   Please answer only yes or no.
*   
*   Arguments (not necessary):
*   -r sets all numbers to roman system
*   --help, -h shows help message
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <libintl.h>
#include <stdbool.h>

#define _(STRING) gettext(STRING)

/**
 * @brief Array of roman numbers between 1 and 100.
 */
char *roman_values[100] = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
    "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
    "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
    "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
    "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
    "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
    "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
    "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"
};

/**
 * @brief Finds roman number for integer.
 *
 * @param num Integer between 1 and 100.
 * @return Pointer to string with roman number or empty string if number is out of [1, 100].
 */
char *int_to_roman(int num) {
    if (num < 1 || num > 100) {
        return "";
    }
    return roman_values[num - 1];
}

/**
 * @brief Main function.
 *
 * This function asks user questions and finds right number with binary search algorithm.
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return Code: 0 if successfully executed, 1 if error.
 */
int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
	bindtextdomain("guess", ".");
	textdomain("guess");

    if (argc > 2) {
        printf(_("Too many arguments\n"));
        return 1;
    }

    bool roman = false;
    if (argc == 2) {
        if (!strcmp(argv[1], _("-r"))) {
            roman = true;
        } else if (!strcmp(argv[1], _("--help")) || !strcmp(argv[1], _("-h"))) {
            printf(_("Usage:\n-h, --help shows this help message\n-r make program work with roman numbers\n"));
            return 0;
        } else {
            printf(_("ERROR: Invalid argument\n"));
            return 1;
        }
    }

    int min = 1, max = 100;
    char str[100];

    printf(_("imagine a number between 1 and 100\n"));
    printf(_("please always answer \"yes\" or \"no\"\n"));

    while (min < max) {
        int mid = (min+max)/2;
        if (roman) {
            printf(_("is your number greater than %s?\n"), int_to_roman(mid));
        } else {
            printf(_("is your number greater than %d?\n"), mid);
        }
        scanf("%9s", str);
        if (!strcmp(str, _("yes"))) {
            min = mid + 1;
        } else if (!strcmp(str, _("no"))) {
            max = mid;
        } else {
            printf(_("bad input. try again\n"));
        };
    }

    if (roman) {
        printf(_("I guess your number is %s\n"), int_to_roman(min));
    } else {
        printf(_("I guess your number is %d\n"), min);
    }
}
