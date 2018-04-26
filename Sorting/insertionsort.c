/*O(n) = n^2*/
#include <stdio.h>

int insertionsort(int *A, int sizeA)
{
    int i = 0;
    int j= 0;
    int temp = 0;
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
        j = i;
        /*switch this         V         if you want a descending list*/
        while ((j>0) && (A[j] < A[j-1]))
        {
            temp = A[j-1];
            A[j-1] = A[j];
            A[j] = temp;
            j -= 1;
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

    r=insertionsort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
