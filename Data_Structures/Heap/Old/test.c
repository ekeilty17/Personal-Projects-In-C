#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

int main(void)
{
    int i = 0;
    int r = 0;
    int *output = NULL;
    int size = 0;
    HeapType H;
    r=initHeap(&H,200);

    r=addHeap(&H, 1);
    r=addHeap(&H, 20);
    r=addHeap(&H, 10);
    r=addHeap(&H, 30);
    r=addHeap(&H, 100);
    r=addHeap(&H, -5);
    r=addHeap(&H, 20);

    printf("Level Order:\n");
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=findHeap(&H,40);
    printf("is 40 in Heap? %d\n",r);
    r=findHeap(&H,30);
    printf("is 30 in Heap? %d\n",r);
    r=findHeap(&H,60);
    printf("is 60 in Heap? %d\n",r);
    r=findHeap(&H,50);
    printf("is 50 in Heap? %d\n",r);
    r=findHeap(&H,100);
    printf("is 100 in Heap? %d\n",r);
    r=findHeap(&H,0);
    printf("is 0 in Heap? %d\n",r);
    r=findHeap(&H,10);
    printf("is 10 in Heap? %d\n",r);

    printf("\n\n");
    r=delete(&H,0);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=delete_root(&H,&i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    return 0;
}


