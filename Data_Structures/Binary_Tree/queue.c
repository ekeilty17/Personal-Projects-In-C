/*this is slight modified from my original to complement the binary tree code*/

/*global variable*/
const int SIZE = 100;

struct Queue {
	TreeNode **store; /*the array with the elements*/
	int max_size;
	int size;
};
typedef struct Queue Queue;

int init(Queue *x)
{
    if (x == NULL)
    {
        return -1;
    }
    x->store = (TreeNode **)malloc(SIZE*sizeof(TreeNode *));
    if (x->store == NULL)
    {
        return -1;
    }
    x->max_size = SIZE;
    x->size = 0;
    return 0;
}

int enq(Queue *x, TreeNode* val)
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
int deq(Queue *x, TreeNode **pval)
{
    int i=0;
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
    *pval = x->store[0];
    for (i=0; i<(x->size-1); i++)
    {
        x->store[i] = x->store[i+1];
    }
    x->size -= 1;
    return 0;
}

int isEmpty(Queue x, int *r)
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

int isFull(Queue x, int *r)
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

int free_queue(Queue x)
{
    free(x.store);
    return 0;
}
