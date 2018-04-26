#include <stdio.h>

int sorted(int *A, int sizeA)
{
    int i = 0;
    for (i=1; i<sizeA; i++)
    {
        if (A[i-1] > A[i])
        {
            return -1;
        }
    }
    return 0;
}

int binary_search_rec(int *A, int key, int lo, int hi)
{
    int middle = 0;
    int r = 0;
    if (lo > hi)
    {
        return -1;
    }
    middle = lo + (hi - lo)/2;
    if (A[middle] == key)
    {
        return middle;
    }
    if (A[middle] > key)
    {
        return binary_search_rec(A, key, lo, middle-1);
    }
    else
    {
        return binary_search_rec(A, key, middle+1, hi);
    }
}

int binary_search(int *A, int sizeA, int key)
{
    int r = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 0)
    {
        return -1;
    }
    r=sorted(A, sizeA);
    if (r == -1)
    {
        return -1;
    }
    return binary_search_rec(A, key, 0, sizeA-1);
}

int main(void)
{
    int x[10] = {-345, -234, -21, -5, 0, 2, 10, 34, 431, 2304};
    int n = 10;
    int i = 0;
    int r = 0;

    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    r=binary_search(x,n,10);
    printf("is 10 in the array?\t%d\n",r);
    
    r=binary_search(x,n,100);
    printf("is 100 in the array?\t%d\n",r);

    return 0;
}
