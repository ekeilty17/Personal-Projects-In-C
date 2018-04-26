/*O(n) = nlog(b)n 
  where b is the base you are operating with*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int radix_sort(int *A, int sizeA)
{
    int **buckets;
    int *bucket_idx;
    int iteration = 0;
    int digit = 0;
    int base = 10;
    int i = 0;
    int j = 0;
    int c = 0;

    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    
    //allocating memory to arrays
    buckets = (int**)malloc(sizeof(int*)*base);
    bucket_idx = (int*)malloc(sizeof(int)*base);
    for (i=0; i<base; i++)
    {
        buckets[i] = (int*)malloc(sizeof(int)*sizeA);
    }
    
    while ((iteration >= 0) && (iteration < 10))
    {
        //initializing arrays
        for (i=0; i<base; i++)
        {
            bucket_idx[i] = 0;
            for (j=0; j<sizeA; j++)
            {
                buckets[i][j] = 0;
            }
        }
        
        
        //getting the buckets
        for (i=0; i<sizeA; i++)
        {
            digit = (int)(A[i] / ((int)pow((double) base, iteration))) % base;
            buckets[digit][bucket_idx[digit]] = A[i];
            bucket_idx[digit] += 1;
        }

        /*
        //print buckets
        for (i=0; i<base; i++)
        {
            printf("%d: ",bucket_idx[i]);
            for (j=0; j<sizeA; j++)
            {
                printf("%d ",buckets[i][j]);
            }
            printf("\n");
        }
        */

        //base case
        for (i=0; i<base; i++)
        {
            if (bucket_idx[i] == base)
            {
                iteration = -2;
                break;
            }
        }
        
        //converting buckets to one list
        c = 0;
        for (i=0; i<base; i++)
        {
            for (j=0; j<bucket_idx[i]; j++)
            {
                A[c] = buckets[i][j];
                c += 1;
            }
        }
        iteration += 1;
    }
    
    //freeing malloced arrays
    for (i=0; i<base; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_idx);
    
    return 0;
}

int main(void)
{
    int i = 0;
    int r = 0;
    int n = 10;
    int x[10] = {0, 1, 100, 50, 12, 234, 43, 345, 2, 0};

    printf("Original List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");
    
    r=radix_sort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");
    
    return 0;
}
