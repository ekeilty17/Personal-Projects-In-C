struct Queue { 
   TreeNode *val;
   struct Queue *next;
};
typedef struct Queue Queue;

/* enq needs to be add to tail because otherwise it's annoying 
   to actually use the queue. If we added to head then we are removing
   from tail and with a linked list that's hard to get to */
int enq(Queue **x, TreeNode *val)
{
    if (x == NULL)
    {
        return -1;
    }
    if (*x == NULL)
    {
        *x = (Queue *) malloc(sizeof(Queue));
        (*x)->val = val;
        (*x)->next = NULL;
        return 0;
    }
    else
    {
        return enq(&((*x)->next), val);
    }
}

/*this is the same as delete from head*/
int deq(Queue **x, TreeNode **pval)
{
    Queue *temp = NULL;

    if (x == NULL)
    {
        return -1;
    }
    if (*x == NULL)
    {
        return -1;
    }

    temp = *x;
    *pval = (*x)->val;
    *x = temp->next;
    free(temp);
    return 0;
}

int isEmpty(Queue *x, int *r)
{
    if (r == NULL)
    {
        return -1;
    }
    if (x == NULL)
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

int size(Queue *x)
{   
    Queue *curr = x;
    int count = 0;
    while (curr != NULL)
    {
        count += 1;
        curr = curr->next;
    }
    return count;
}

int print_queue(Queue *x)
{
    int r = 0;
    if (x == NULL)
    {
        return -1;
    }
    r=print_queue(x->next);
    printf("%d\n",x->val->val);
    return 0;
}

int free_queue(Queue *x)
{
    if (x == NULL) 
    {
        return -1;
    }
    else
    {
        Queue *f = x->next;
        free(x);
        return free_queue(f);
    }
}
