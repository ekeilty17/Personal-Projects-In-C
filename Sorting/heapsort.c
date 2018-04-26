/*O(n) = nlogn (very respectible and memory efficient sorting algorithm)*/
#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int *store;
    unsigned int size;
    unsigned int end;
    int (*compare)(int x, int y);
};
typedef struct Heap Heap;

int init(Heap *H, int size, int (*compare)(int x, int y))
{
    if (H == NULL)
    {
        return -1;
    }
    if (size < 1)
    {
        return -1;
    }
    H->store = (int *)malloc(sizeof(int)*size);
    H->size = size;
    H->end = 0;
    H->compare = compare;
    return 0;
}

int parent(int n)
{
    if (n < 1)
    {
        return -1;
    }
    if (n%2 == 0)
    {
        return (n-2)/2;
    }
    else
    {
        return (n-1)/2;
    }
}

int swap(int *a, int i, int j)
{   
    int temp = 0;
    if (a == NULL)
    {   
        return -1;
    }
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return 0;
}

int bubble_up(Heap *H, int c)
{   /*c stands for child*/
    int r = 0;
    if (H == NULL)
    {
        return -1;
    }
    /*if at root, break*/
    if (parent(c) == -1)
    {
        return 0;
    }
    if (H->compare(H->store[parent(c)], H->store[c])) 
    {
        r=swap(H->store, c, parent(c));
        r=bubble_up(H, parent(c));
    }
    return 0;
}

int insert(Heap *H, int x)
{
    int r = 0;
    if (H == NULL)
    {
        return -1;
    }
    /*blew the memory of the heap*/
    if (H->end >= H->size)
    {
        return -1;
    }
    H->store[ H->end ] = x;
    r=bubble_up(H, H->end);
    H->end += 1;
    return 0;
}

int bubble_down(Heap *H, int p)
{   /*p stands for parent*/
    int r = 0;
    int min_index = p;  /*it was hard to come up with a good name for this var*/                        /*basically, whatever compare function you define
                          this is the index that is minimized*/
    if (H == NULL)
    {
        return -1;
    }
    if (p < 0)
    {
        return -1;
    }
    /*pretty self explainitory, compare child and parent
      get the index of the child that is the "smallest"*/
    /*Left child*/
    if ((2*p+1) < H->end)
    {
        if (H->compare(H->store[min_index], H->store[2*p+1]))
        {
            min_index = 2*p+1;
        }
    }
    /*Right child*/
    if ((2*p+2) < H->end)
    {
        if (H->compare(H->store[min_index], H->store[2*p+2]))
        {
            min_index = 2*p+2;
        }
    }
    /*swap that index with that child and continue with the next child*/
    if (min_index != p)
    {
        r=swap(H->store,p,min_index);
        r=bubble_down(H,min_index);
    }
    return 0;
}


int extract(Heap *H, int *rval)
{
    int r = 0;
    if (H == NULL)
    {
        return -1;
    }
    /*empty heap*/
    if (H->end <= 0)
    {
        return -1;
    }
    *rval = H->store[0];
    H->store[0] = H->store[ H->end-1 ];     /*swap root with last element*/
    H->end -= 1;                            /*reduce size of heap by 1*/
    r=bubble_down(H,0);                     /*bubble down to re-heapify*/
    return 0;
}
/*______________________________^ HEAP CODE ^______________________________*/

int hs(int *x, int size, int (*compare)(int x, int y))
{
    int i = 0;
    int r = 0;
    int rval = 0;
    Heap H;
    
    r=init(&H,size,compare);
    for (i=0; i<size; i++)
    {
        r=insert(&H,x[i]);
    }
    for (i=0; i<size; i++)
    {
	r=extract(&H,&rval);
        x[i] = rval;
    }
    //we can of course make this more efficient by making the Heap sort array equal to x and then just manipulating that
    //then would be more memory efficient
    return 0;

}

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
    int n = 10;
    int x[10] = {0, -1, 100, 50, 12, -234, 43, 345, -2, 0};
    
    printf("Original List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }   
    printf("\n\n");
    
    r=hs(x,n,gt);
    printf("Heapsort Ascending\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");
    
    r=hs(x,n,lt);
    printf("Heapsort Descending\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");


    return 0;
} 
