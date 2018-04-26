/*O(n) = n^2*/
#include <stdio.h>

/*also called bidirectional bubble sort*/
int cocktailsort(int *A, int sizeA)
{
    int swapped = 1;
    int i = 0;
    int temp = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    while (swapped)
    {
        /*forwards bubblesort*/
        swapped = 0;
        for (i=1; i<sizeA; i++)
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
        if (!swapped)
        {
            break;
        }
        /*backwards bubblesort*/
        swapped = 0;
        for (i=sizeA-1; i>0; i--)
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

    r=cocktailsort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
