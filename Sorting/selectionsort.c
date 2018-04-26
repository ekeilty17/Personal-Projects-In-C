/*O(n) = n^2*/
#include <stdio.h>

int selectionsort(int *A, int sizeA)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int min_idx = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    
    for (i=0; i<sizeA; i++)
    {
        min_idx = i;
        for (j=i; j<sizeA; j++)
        {
            //change       V    to make a descending list
            if (A[min_idx] > A[j])
            {
                min_idx = j;
            }
        }
        temp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = temp;
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

    r=selectionsort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
