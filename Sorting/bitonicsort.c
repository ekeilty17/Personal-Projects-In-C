#include <stdio.h>


int* bitonicsort_rec(int *x, int sizeX, int up)
{
    int *first = NULL;
    int *second = NULL;
    if (sizeX <= 1)
    {
        return x;
    }
    first = 

int bitonicsort(int *A, int sizeA, int up)
{
    //up is a boolean: True = ascending list, False = descending list
    int r = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    r=bitonicsort_rec(A,sizeA, 1)
