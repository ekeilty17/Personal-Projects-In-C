/*O(n) = nlogn (quickest sorting algorithm in C)*/
#include <stdio.h>
#include <stdlib.h>

/*this function will be passed into qsort*/
/*it can be called anything*/
int comparator(const void *p, const void *q)
{
    /*the reason p and q are void* is so 
      in the function they can be any datatype (even structs)
      */
    int l = *(int *)p;
    int r = *(int *)q;
    /*want to return a negetive value if p before q
              return 0 is p is equivalent to q
              return a positive value if p after q */
    return l-r;
}

int main(void)
{
    int i = 0;
    int n = 8;
    int x[8] = {1, 6, 5, 2, 3, 9, 7, 8};

    printf("Original List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");   
    
    qsort((void*)x, 8, sizeof(int), comparator);
    printf("Sorted List\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");
    return 0;
}
