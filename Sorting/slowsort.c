/*O(n) >> n^n ... worse than bubble sort even in best case*/
#include <stdio.h>

int slowsort_rec(int *A, int i, int j)
{
    int m = 0;
    int r = 0;
    int temp = 0;
    //base case
    if (i >= j)
    {
        return 0;
    }

    m = (int)(i+j)/2;
    r=slowsort_rec(A,i,m);
    r=slowsort_rec(A,m+1,j);
    //change V      to make a descreasing list
    if (A[j] < A[m])
    {
        temp = A[j];
        A[j] = A[m];
        A[m] = temp;
    }
    r=slowsort_rec(A,i,j-1);
    return 0;
}

int slowsort(int *A, int sizeA)
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
    r=slowsort_rec(A,0,sizeA-1);
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

    r=slowsort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
