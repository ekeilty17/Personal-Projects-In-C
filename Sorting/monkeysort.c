/*O(n) = (n+1)!     yikes...it's tough to be worse than bubblesort*/
#include <stdio.h>
#include <stdlib.h>

int isSorted(int *A, int sizeA)
{
    int i = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 0)
    {
        return -1;
    }
    for (i=1; i<sizeA; i++)
    {
        //change   V    to make check if list is descending
        if (A[i-1] > A[i])
        {
            return 0;
        }
    }
    return 1;
}

int shuffle(int *A, int sizeA)
{
    int i = 0;
    int r = 0;
    int temp = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 0)
    {
        return -1;
    }   
    for (i=sizeA-1; i>0; i--)
    {
        r = rand() % (i+1);
        temp = A[r];
        A[r] = A[i];
        A[i] = temp;
    }
    return 0;
}

int monkeysort(int *A, int sizeA)
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
    while (!isSorted(A, sizeA))
    {
        r=shuffle(A, sizeA);
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

    r=monkeysort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
