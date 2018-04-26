/*O(n) = n^2        but there is a chance that it can have nlogn*/
#include <stdio.h>

int shellsort(int *A, int sizeA)
{
    int g = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    //Marcin Ciura's gap sequence
    int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 1};

    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    
    for (g=0; g<8; g++)
    {
        for (i=gaps[g]; i<sizeA; i++)
        {
            temp = A[i];
            for (j=i; j>=gaps[g]; j-=gaps[g])
            {
                //change           V        to make a descending list
                if (A[j - gaps[g]] < temp)
                {
                    break;
                }
                A[j] = A[j - gaps[g]];
            }
            A[j] = temp;
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

    r=shellsort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
