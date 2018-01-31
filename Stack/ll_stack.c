struct Stack { 
   int val;
   struct Stack *next;
};
typedef struct Stack Stack;

/* enq needs to be add to tail because otherwise it's annoying 
   to actually use the queue. If we added to head then we are removing
   from tail and with a linked list that's hard to get to */
int push(Stack **x, int val)
{
    Stack *old_head = NULL;
    if (x == NULL)
    {   
        return -1;
    }
    old_head = *x;
    
    *x = (Stack *) malloc(sizeof(Stack));
    (*x)->val = val;
    (*x)->next = old_head;
    return 0;
}    

/*this is the same as delete from head*/
int pop(Stack **x, int *pval)
{
    Stack *temp = NULL;

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

int isEmpty(Stack *x, int *r)
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

int size(Stack *x)
{   
    Stack *curr = x;
    int count = 0;
    while (curr != NULL)
    {
        count += 1;
        curr = curr->next;
    }
    return count;
}

int print_stack(Stack *x)
{
    int r = 0;
    if (x == NULL)
    {
        return -1;
    }
    printf("%d\n",x->val);
    r=print_stack(x->next);
    return 0;
}

int free_stack(Stack *x)
{
    if (x == NULL) 
    {
        return -1;
    }
    else
    {
        Stack *f = x->next;
        free(x);
        return free_stack(f);
    }
}
