/*O(n) = nlogn*/
#include <stdio.h>
#include <stdlib.h>

int merge(int *A, int left, int middle, int right)
{
    int i = 0;
    int l = 0; //L index counter
    int r = 0; //R index counter
    int a = 0; //A index counter
    int sizeL = middle - left + 1;
    int sizeR = right - middle;
    int *L = (int*)malloc(sizeof(int)*sizeL);
    int *R = (int*)malloc(sizeof(int)*sizeR);
    
    //printf("left: %d, middle: %d, right: %d\n",left,middle,right);
    
    //adding left half of A to L
    for (i=0; i<sizeL; i++)
    {
        L[i] = A[left + i];
    }
    //adding right half of A to R
    for (i=0; i<sizeR; i++)
    {
        R[i] = A[middle + 1 + i];
    }
    
    l = 0;  //L index counter
    r = 0;  //R index counter
    a = left;  //A index counter
    while ((l < sizeL) && (r < sizeR))
    {
        //iterate through L and R and add the smaller index to A
        //If we added from L, up l by 1
        if (L[l] <= R[r])
        {
            A[a] = L[l];
            l++;
        }
        //if we added from R, up r by 1
        else
        {
            A[a] = R[r];
            r++;
        }
        a++;
    }
    
    //whatever is left over after ^ we add to A
    //only one of these while loops will run
    while (l < sizeL)
    {
        A[a] = L[l];
        l++;
        a++;
    }
    while (r < sizeR)
    {
        A[a] = R[r];
        r++;
        a++;
    }

    free(L);
    free(R);
    return 0;
}

int mergesort_rec(int *A, int left, int right)
{
    int r = 0;
    int middle = 0;
    if (left >= right)
    {
        return -1;
    }
    middle = left + (right - left)/2;
    //printf("left: %d, middle: %d, right: %d\n",left,middle,right);
    r=mergesort_rec(A, left, middle);
    r=mergesort_rec(A, middle+1, right);
    
    r=merge(A, left, middle, right);
    return 0;
}

int merge_sort(int *A, int sizeA)
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
    return mergesort_rec(A, 0, sizeA-1);
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

    r=merge_sort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
