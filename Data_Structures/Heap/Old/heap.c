struct HeapType {
    int *store;
    unsigned int size;
    unsigned int end;
};
typedef struct HeapType HeapType;

int initHeap(HeapType *pHeap, int size)
{
    /*  not a linked list, dealing with an actual Heap
        not a pointer to a heap */
    if (pHeap == NULL)
    {
        return -1;
    }
    if (size < 1)
    {
        return -1;
    }
    /*pHeap is assumed to be allocated already*/
    pHeap->store = (int *)malloc(sizeof(int)*size);
    pHeap->size = size;
    pHeap->end = 0;
    return 0;
}

int getDepth(int index)
{
    int e = 0;
    int p = 1;
    if (index < 0)
    {
        return -1;
    }
    while(p < index+1)
    {
        e += 1;
        p *= 2;
    }
    return e;
}

int getParentIndex(int index)
{
    if (index < 0)
    {
        return -1;
    }
    if (index == 0)
    {
        return -1;
    }
    if (index%2 == 0)
    {
        return (index - 2)/2;
    }
    else
    {
        return (index - 1)/2;
    }
}

int getLeftChildIndex(int index)
{
    if (index < 0)
    {
        return -1;
    }
    return 2*index + 1;
}

int getRightChildIndex(int index)
{
    if (index < 0)
    {
        return -1;
    }
    return 2*index + 2;
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

int addHeap(HeapType *pHeap, int key)
{
    int r = 0;
    int key_index = 0;
    int parent_index = 0;
    if (pHeap == NULL)
    {
        return -1;
    }
    if (pHeap->end == pHeap->size)
    {
        return -1;
    }
    /*we add it to the end*/
    key_index = pHeap->end;
    pHeap->store[key_index] = key;
    pHeap->end += 1;
    /*then we have to bubble it up*/
    parent_index = getParentIndex(key_index);
    while ((pHeap->store[key_index] > pHeap->store[parent_index]) && (key_index != 0))
    {
        r=swap(pHeap->store, key_index, parent_index);
        key_index = parent_index;
        parent_index = getParentIndex(key_index);
    }
    return 0;
}

int findHeap_rec(HeapType *pHeap, int key, int index)
{
    int L = 0;
    int R = 0;
    if (index >= pHeap->end)
    {
        /*technically could work without this
          but this takes advantage of the structure*/
        return -1;
    }
    if (key == pHeap->store[index])
    {
        return 0;
    }
    if (key < pHeap->store[index])
    {
        L=findHeap_rec(pHeap, key, 2*index+1);
        R=findHeap_rec(pHeap, key, 2*index+2);
        if ((R == 0) || (L == 0))
        {
            return 0;
        }
        return -1;
    }
    /*key is greater than all nodes below it*/
    return -1;
}
int findHeap(HeapType *pHeap, int key)
{
    if (pHeap == NULL)
    {
        return -1;
    }
    return findHeap_rec(pHeap, key, 0);
}

int delete_rec(HeapType *pHeap, int key, int index)
{
    int L = 0;
    int R = 0;
    if (index >= pHeap->end)
    {
        /*technically could work without this
          but this takes advantage of the structure*/
        return -1;
    }
    if (key == pHeap->store[index])
    {
        /*swap with last element*/
        R=swap(pHeap->store, index, pHeap->end-1);
        /*remove last element*/
        pHeap->end -= 1;
        pHeap->store[pHeap->end] = 0;
        /*bubble the element down so it's a heap again*/
        while (1)
        {
            if (2*index+1 >= pHeap->end)
            {
                /*if 2*index+1 is out of range, so is 2*index+2*/
                break;
            }
            if ((2*index+2 >= pHeap->end) && (2*index+1 < pHeap->end))
            {
                /*this is an annoying case where the left is not out of
                  index of the array, but the right is*/
                if (pHeap->store[index] > pHeap->store[2*index+1])
                {
                    break;
                }
                R=swap(pHeap->store, index, 2*index+1);
                break;
            }
            /*the normal case*/
            if ((pHeap->store[index] > pHeap->store[2*index+1]) && (pHeap->store[index] > pHeap->store[2*index+2]))
            {
                /*if the index is greater than both its children...it's a heap*/
                break;
            }
            /*want to swap with the larger of the children so we only have
              to worry about the indexes below it*/
            if (pHeap->store[2*index+1] > pHeap->store[2*index+2])
            {
                R=swap(pHeap->store, index, 2*index+1);
                index = 2*index+1;
            }
            else
            {
                R=swap(pHeap->store, index, 2*index+2);
                index = 2*index+2;
            }
        }
        return 0;
    }
    if (key < pHeap->store[index])
    {
        L=delete_rec(pHeap, key, 2*index+1);
        R=delete_rec(pHeap, key, 2*index+2);
        if ((R == 0) || (L == 0))
        {
            return 0;
        }
        return -1;
    }
    /*key is greater than all nodes below it*/
    return -1;
}
int delete(HeapType *pHeap, int key)
{
    if (pHeap == NULL)
    {
        return -1;
    }
    return delete_rec(pHeap, key, 0);
}

int delete_root(HeapType *pHeap, int *key)
{
    int index = 0;
    int R = 0;
    if (pHeap == NULL)
    {
        return -1;
    }
    if (pHeap->end == 0)
    {
        return -1;
    }
    *key = pHeap->store[0];

    /*swap with last element*/
    R=swap(pHeap->store, index, pHeap->end-1);
    /*remove last element*/
    pHeap->end -= 1;
    pHeap->store[pHeap->end] = 0;
    /*bubble the element down so it's a heap again*/
    while (1)
    {
        if (2*index+1 >= pHeap->end)
        {
            /*if 2*index+1 is out of range, so is 2*index+2*/
            break;
        }
        if ((2*index+2 >= pHeap->end) && (2*index+1 < pHeap->end))
        {
            /*this is an annoying case where the left is not out of
              index of the array, but the right is*/
            if (pHeap->store[index] > pHeap->store[2*index+1])
            {
                break;
            }
            R=swap(pHeap->store, index, 2*index+1);
            break;
        }
        /*the normal case
          the index is greater than both its children*/
        if ((pHeap->store[index] > pHeap->store[2*index+1]) && (pHeap->store[index] > pHeap->store[2*index+2]))
        {
            /*if the index is greater than both its children...it's a heap*/
            break;
        }
/*want to swap with the larger of the children so we only have
          to worry about the indexes below it*/
        if (pHeap->store[2*index+1] > pHeap->store[2*index+2])
        {
            R=swap(pHeap->store, index, 2*index+1);
            index = 2*index+1;
        }
        else
        {
            R=swap(pHeap->store, index, 2*index+2);
            index = 2*index+2;
        }
    }
    return 0;
}
