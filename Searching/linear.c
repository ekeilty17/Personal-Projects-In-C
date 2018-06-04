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

int linear_search(int *A, int sizeA, int val)
{
    int r = 0;
    int i = 0;
    if (A == NULL)
    {
        return -1;
    }
    
    r = sorted(A,sizeA);
    if (r == 0)
    {
        i = 0;
        while (A[i] < val)
        {
            i += 1;
        }
        if (A[i] == val)
        {
            return 0;
        }
        return -1;
    }
    else
    {
        for (i=0; i<sizeA; i++)
        {
            if (A[i] == val)
            {
                return 0;
            }
        }
        return -1;
    }
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

    r=linear_search(x,n,10);
    printf("is 10 in the array?\t%d\n",r);

    r=linear_search(x,n,100);
    printf("is 100 in the array?\t%d\n",r);

    return 0;
}
