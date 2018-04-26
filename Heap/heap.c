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
    int min_index = p;  /*it was hard to come up with a good name for this var*/
                        /*basically, whatever compare function you define
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

int find_rec(Heap *H, int key, int i)
{
    int L = -1;
    int R = -1;
    /*if we blow the range*/
    if (i >= H->end)
    {
        return -1;
    }
    /*if we find it*/
    if (key == H->store[i])
    {
        return i;
    }
    /*so we don't have to do more searching than we have to
      (taking advantage of the data structure*/
    if (key < H->store[i])
    {
        L=find_rec(H, key, 2*i+1);
        /*back propogating if we found the index*/
        if (L != -1)
        {
            return L;
        }
        R=find_rec(H, key, 2*i+2);
        /*back propogating if we found the index*/
        if (R != -1)
        {
            return R;
        }
    }
    /*key is greater than all nodes below it*/
    return -1;
} 
int find(Heap *H, int key)
{
    if (H == NULL)
    {
        return -1;
    }
    return find_rec(H, key, 0);
}

int delete(Heap *H, int key, int *rval)
{
    int idx = 0;
    int r = 0;
    if (H == NULL)
    {
        return -1;
    }
    idx = find(H, key);
    if (idx != -1)
    {
        *rval = H->store[idx];
        H->store[idx] = H->store[ H->end-1 ];       /*swap root with last element*/
        H->end -= 1;                                /*reduce size of heap by 1*/
        r=bubble_down(H,idx);                       /*bubble down to re-heapify*/
    }
    return 0;
}

