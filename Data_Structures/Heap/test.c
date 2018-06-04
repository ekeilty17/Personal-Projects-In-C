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
    int *output = NULL;
    int size = 0;
    Heap H;
    r=init(&H,15,lt);

    r=insert(&H, 1);
    r=insert(&H, 20);
    r=insert(&H, 10);
    r=insert(&H, 30);
    r=insert(&H, 100);
    r=insert(&H, -5);
    r=insert(&H, 20);
    printf("Level Order:\n");
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=find(&H,40);
    printf("is 40 in Heap? %d\n",r);
    r=find(&H,30);
    printf("is 30 in Heap? %d\n",r);
    r=find(&H,60);
    printf("is 60 in Heap? %d\n",r);
    r=find(&H,50);
    printf("is 50 in Heap? %d\n",r);
    r=find(&H,100);
    printf("is 100 in Heap? %d\n",r);
    r=find(&H,0);
    printf("is 0 in Heap? %d\n",r);
    r=find(&H,10);
    printf("is 10 in Heap? %d\n",r);

    printf("\n\n");
    printf("Removing Specific Elements\n");
    r=delete(&H,1,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    printf("Extracting Top Element\n");
    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");

    r=extract(&H,&i);
    printf("removed %d\t",i);
    for(i=0;i<H.end;i++)
    {
        printf("%d ",H.store[i]);
    }
    printf("\n\n");
    return 0;
}
