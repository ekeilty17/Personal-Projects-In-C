/*O(n) = n^2*/
#include <stdio.h>

int gnomesort(int *A, int sizeA)
{
    int pos = 0;
    int temp = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    while (pos < sizeA)
    {
        //change                    V       to make a descending list
        if ((pos == 0) || (A[pos-1] <= A[pos]))
        {
            pos += 1;
        }
        else
        {
            temp = A[pos-1];
            A[pos-1] = A[pos];
            A[pos] = temp;
            pos -= 1;
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

    r=gnomesort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
