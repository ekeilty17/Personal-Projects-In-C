#include <stdio.h>
#include <stdlib.h>
#include "dictionary.c"

int main(void)
{
    int r = 0;
    dict *d = NULL;
    r=add_in_order(&d, "Eric", "Keilty");
    r=add_in_order(&d, "Adam", "Gee");
    r=add_in_order(&d, "Priya", "Waaasomething");
    r=d_print(d);
    r=delete(&d, "Eric");
    r=d_print(d);

    return 0;
}
