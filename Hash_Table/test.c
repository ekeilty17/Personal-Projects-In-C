#include <stdio.h>
#include <stdlib.h>
#include "hash.c"

int main(void)
{
    int r = 0;
    
    HashTable H;
    r=init(&H, 15);
    r=printTable(&H);
    printf("\n");
    
    r=add(&H, "Eric");
    r=add(&H, "Cleo");
    r=add(&H, "Keilty");
    r=add(&H, "Hello, World!");
    r=add(&H, "Netflix");
    r=add(&H, "Nicole");
    r=add(&H, "words");
    r=add(&H, "AHHHH");
    r=add(&H, "The Office");
    r=add(&H, "#hashtables");
    r=add(&H, "Praxis!");
    r=add(&H, "Nebu");
    r=add(&H, "Baum");
    r=add(&H, "Micheal Scott");
    printf("\n");
    r=printTable(&H);
    return 0;
}
