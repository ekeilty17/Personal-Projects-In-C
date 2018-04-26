/*O(n) = n^2*/
#include <stdio.h>

int cyclesort(int *A, int sizeA)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int element = 0;
    int temp = 0;
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    element = A[0];
    for (i=0; i<sizeA-1; i++)
    {
        cnt = 0;
        for (j=0; j<sizeA; j++)
        {
            if ((j != element) && (A[j] < element))
            {
                cnt += 1;
            }
        }
        printf("element: %d\tcnt: %d\n",element, cnt);
        temp = element;
        element = A[cnt];
        A[cnt] = temp;
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

    r=cyclesort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
