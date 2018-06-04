#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

int lt(int x, int y)
{   
    if (x < y)
    {   
        return 1;
    }
    else
    {   
        return 0;
    }
}

int gt(int x, int y)
{   
    if (x > y)
    {   
        return 1;
    }
    else
    {   
        return 0;
    }
}

int main(void)
{
    int i = 0;
    int r = 0;
    int rval = 0;
    Heap heap_max;
    Heap heap_min;
    
    /*Max Heap*/
    printf("Max Heap\n");
    r=init(&heap_max,20,lt);

    r=insert(&heap_max, 10);
    r=insert(&heap_max, 30);
    r=insert(&heap_max, -12);
    r=insert(&heap_max, 23);
    r=insert(&heap_max, 100);
    r=insert(&heap_max, -4);
    r=insert(&heap_max, 0);
    
    for (i=0; i<heap_max.end; i++)
    {
        printf("%d ",heap_max.store[i]);
    }
    printf("\n\n");
    
    r=extract(&heap_max,&rval);
    printf("removed %d:\t",rval);
    for (i=0; i<heap_max.end; i++)
    {
        printf("%d ",heap_max.store[i]);
    }
    printf("\n");
    r=extract(&heap_max,&rval);
    printf("removed %d:\t",rval);
    for (i=0; i<heap_max.end; i++)
    {
        printf("%d ",heap_max.store[i]);
    }
    printf("\n");
    r=extract(&heap_max,&rval);
    printf("removed %d:\t",rval);
    for (i=0; i<heap_max.end; i++)
    {
        printf("%d ",heap_max.store[i]);
    }
    printf("\n\n\n");
    
    /*Min Heap*/
    printf("Min Heap\n");
    r=init(&heap_min,20,gt);

    r=insert(&heap_min, 10);
    r=insert(&heap_min, 30);
    r=insert(&heap_min, -12);
    r=insert(&heap_min, 23);
    r=insert(&heap_min, 100);
    r=insert(&heap_min, -4);
    r=insert(&heap_min, 0);
    
    for (i=0; i<heap_min.end; i++)
    {
        printf("%d ",heap_min.store[i]);
    }
    printf("\n\n");
    
    r=extract(&heap_min,&rval);
    printf("removed %d:\t",rval);
    for (i=0; i<heap_min.end; i++)
    {
        printf("%d ",heap_min.store[i]);
    }
    printf("\n");

    r=extract(&heap_min,&rval);
    printf("removed %d:\t",rval);
    for (i=0; i<heap_min.end; i++)
    {
        printf("%d ",heap_min.store[i]);
    }
    printf("\n");

    r=extract(&heap_min,&rval);
    printf("removed %d:\t",rval);
    for (i=0; i<heap_min.end; i++)
    {
        printf("%d ",heap_min.store[i]);
    }
    printf("\n");
    
    return 0;
}
