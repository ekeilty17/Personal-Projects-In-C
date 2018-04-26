/*O(n) = n^2 (really really bad)*/
#include <stdio.h>

int bubblesort_while(int *A, int sizeA)
{   
    int swapped = 1;
    int i = 0;
    int temp = 0;
    
    /*error checks*/
    if (sizeA <= 1)
    {
        return -1;
    }
    if (A == NULL)
    {
        return -1;
    }
    while (swapped)
    {
        swapped = 0;
        for(i=1;i<sizeA;i++)
        {
            //change   V    to make descending
            if (A[i-1] > A[i])
            {
                temp = A[i-1];
                A[i-1] = A[i];
                A[i] = temp;
                swapped = 1;
            }
        }
    }
    return 0;
}

int bubblesort_for(int *A, int sizeA)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    /*error*/
    if (sizeA <= 1)
    {
        return -1;
    }
    if (A == NULL)
    {
        return -1;
    } 
    for (i=0; i<sizeA; i++)
    {
        for (j=1; j<sizeA-i; j++)
        {
            //change   V    to make descending
            if (A[j-1] > A[j])
            {
                temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }
    }
    return 0;
}

int main(void)
{
    int i = 0;
    int r = 0;
    int n = 10;
    int x[10] = {0, -1, 100, 50, 12, -234, 43, 345, -2, 0};
    int y[10] = {0, -1, 100, 50, 12, -234, 43, 345, -2, 0};

    printf("Original List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    r=bubblesort_while(x,n);
    printf("Bubble Sort with a While Loop\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");
    
    r=bubblesort_for(y,n);
    printf("Bubble Sort with a For Loop\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",y[i]);
    }
    printf("\n\n");

    return 0;
}
