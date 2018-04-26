/*O(n) = nlogn*/
#include <stdio.h>

int partition(int *A, int lo, int hi)
{
    int pivot = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    //picking the pivot is arbirary
    pivot = A[hi];

    i = lo - 1;
    for (j=lo; j<hi; j++)
    {
        /*change  V     for a descending list*/ 
        if (A[j] < pivot)
        {
            i += 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    /* ditto  V */
    if (A[hi] < A[i+1])
    {
        temp = A[i+1];
        A[i+1] = A[hi];
        A[hi] = temp;
    }
    return i+1;
}

int quicksort_rec(int *A, int lo, int hi)
{
    int p = 0;
    int r = 0;
    if (lo < hi)
    {
        p = partition(A, lo, hi);
        r=quicksort_rec(A, lo, p-1);
        r=quicksort_rec(A, p+1, hi);
    }
    return 0;
}

int quicksort(int *A, int sizeA)
{
    int r = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    r=quicksort_rec(A, 0, sizeA-1);
    return 0;
}

int main(void)
{
    int i = 0;
    int r = 0;
    int n = 10;
    int x[10] = {0, -1, 100, 50, 12, -234, 43, 345, -2, 0};

    printf("Original List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    r=quicksort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
