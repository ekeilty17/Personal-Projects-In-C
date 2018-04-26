/*O(n) = n^2*/
#include <stdio.h>

int oddevensort(int *A, int sizeA)
{
    int i = 0;
    int sorted = 0;
    int temp = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    
    sorted = 0;
    while (!sorted)
    {
        //Can Parallelize the two functions below
        sorted = 1;
        //Odd
        for (i=1; i<sizeA-1; i+=2)
        {
            //change V      to make a decreasing list
            if (A[i] > A[i+1])
            {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                sorted = 0;
            }
        }
        //Even
        for (i=0; i<sizeA-1; i+=2)
        {
            //change V      to make a decreasing list
            if (A[i] > A[i+1])
            {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                sorted = 0;
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

    r=oddevensort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
