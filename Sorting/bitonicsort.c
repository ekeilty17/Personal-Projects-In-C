#include <stdio.h>


// A Bitonic Sequence is sequence such that the first half is ascending and the second half is descending
// If we have a bitonic sequence, then we can merge it similar to how we merge 2 lists in merge sort

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
