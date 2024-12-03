#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <libintl.h>

#define _(STRING) gettext(STRING)

int main() {
    setlocale(LC_ALL, "");
	bindtextdomain("guess", ".");
	textdomain("guess");

    int min = 1, max = 100;
    char str[100];

    printf(_("imagine a number between 1 and 100\n"));
    printf(_("please always answer \"yes\" or \"no\"\n"));

    while (min < max) {
        int mid = (min+max)/2;
        printf(_("is your number greater than %d?\n"), mid);
        scanf("%9s", str);
        if (!strcmp(str, _("yes"))) {
            min = mid + 1;
        } else if (!strcmp(str, _("no"))) {
            max = mid;
        } else {
            printf(_("bad input. try again\n"));
        };
    }

    printf(_("I guess your number is %d\n"), min);
}
