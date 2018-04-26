#include <stdio.h>
#include <stdlib.h>

struct Dynamic{
    int *store;
    int size;
    int end;
}

typedef struct Dynamic Dynamic;

int* grow(int *a, int size)
{
    int *out = NULL;
    int i = 0;
    if (a == NULL)
    {
        return NULL;
    }
    if (size <= 0)
    {
        return NULL;
    }
    out = (int *)malloc(sizeof(int)*2*size);
    for(i=0; i<size; i++)
    {
        out[i] = a[i];
    }
    return out;
}

int* shrink(int *a, int size)
{
    int *out = NULL;
    int i = 0;
    if (a == NULL)
    {
        return NULL;
    }
    if (size <= 1)
    {
       return NULL;
    }
    if (size % 2 == 1)
    {
        return -1;
    }
    out = (int *)malloc(sizeof(int)*(size/2));
    for (i=0; i<size/2; i++)
    {
        out[i] = a[i];
    }
    free(a);
    return out;
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

int init(Dynamic *a, int val)
{
    if (a == NULL)
    {
        return -1;
    }
    a->store = (int *)malloc(sizeof(int));
    a->store[i] = val;
    return 0;
}

int add(Dynamic *a, int val)
{
    if (a == NULL)
    {
        return -1;
    }
    if (end == size)
    {
        Dynamic->store = grow(Dynamic->store,Dynamic->size);
        Dynamic->size *= 2;
    }
    Dynamic->store[Dynamic->end] = val;
    Dynamic->end += 1;
    return 0;
}

int search(Dynamic *a, int val)
{
    int i = 0;
    if (a == NULL)
    {
        return -1;
    }
    for(i=0; i<a->end; i++)
    {
        if (a->store[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int delete(Dynamic *a, int val)
{
    if (a == NULL)
    {
        return -1;
    }
    int i = search(a,val);
    if (i != -1)
    {
        i=swap(a,i,a->end-1);
        a->end -= 1;
        if (a->end == a->size/2)
        {
            i=shrink
        
        return 0;
    }
    return -1;
}

int main(void)
{
    
