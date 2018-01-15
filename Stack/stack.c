/*global variable*/
const int SIZE = 10;

struct Stack {
	int *store; /*the array with the elements*/
	int max_size;
	int size;
};
typedef struct Stack Stack;

int init(Stack *x)
{
    if (x == NULL)
    {
        return -1;
    }
    x->store = (int *)malloc(SIZE*sizeof(int));
    if (x->store == NULL)
    {
        return -1;
    }
    x->max_size = SIZE;
    x->size = 0;
    return 0;
}

int push(Stack *x, int val)
{
    if (x == NULL)
    {
        return -1;
    }
    if (x->size == x->max_size)
    {
        /*blew the memory*/
        return -1;
    }
    x->store[x->size] = val;
    x->size += 1;
    return 0;
}

/*pval is a return value*/
int pop(Stack *x, int *pval)
{
    if (x == NULL)
    {
        return -1;
    }
    if (pval == NULL)
    {
        return -1;
    }
    if (x->size == 0)
    {
        return -1;
    }
    x->size -= 1;
    *pval = x->store[x->size];
    /*we don't actually need to remove the value, we just modify size
      that way if we add something else it will just overwrite it*/
    return 0;
}

int isEmpty(Stack x, int *r)
{
    if (r == NULL)
    {
        return -1;
    }
    if (x.size == 0)
    {
        *r = 1;
        return 0;
    }
    else
    {
        *r = 0;
        return 0;
    }
}

int isFull(Stack x, int *r)
{
    if (r == NULL)
    {
        return -1;
    }
    if (x.size == x.max_size)
    {   
        *r = 1;
        return 0;
    }
    else
    {   
        *r = 0;
        return 0;
    }
}

int print_stack(Stack x)
{
    int i = 0;
    for (i=(x.size-1); i>=0; i--)
    {
        printf("%d\n",x.store[i]);
    }
    return 0;
}

int free_stack(Stack x)
{
    free(x.store);
    return 0;
}
