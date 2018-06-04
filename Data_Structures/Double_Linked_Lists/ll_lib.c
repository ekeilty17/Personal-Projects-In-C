struct llnode { 
    int val;
    struct llnode *next;
    struct llnode *prev;
};
typedef struct llnode llnode;

/*adding*/
int ll_add_to_head( llnode **head, int val)
{
    llnode *original_head = NULL;
    if (head == NULL)
    {
        return -1;
    }

    if (*head == NULL)
    {
        *head = ( llnode *) malloc(sizeof( llnode));
        (*head)->val = val;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return 0;
    }
    else
    {
        original_head = *head;

        *head = ( llnode *) malloc(sizeof( llnode));
        (*head)->val = val;
        (*head)->next = original_head;
        (*head)->next->prev = *head;
        (*head)->prev = NULL;

        return 0;
    }
}
int ll_add_to_tail( llnode **head, int val)
{
    if (head == NULL)
    {
        return -1;
    }
    if (*head == NULL)
    {
        *head = ( llnode *) malloc(sizeof( llnode));
        (*head) -> val = val;
        (*head) -> next = NULL;
        (*head) -> prev = NULL;

        return 0;
    }
    else if ((*head)->next == NULL)
    {
        (*head) -> next  = ( llnode *) malloc(sizeof( llnode));
        (*head) -> next -> val = val;
        (*head) -> next -> next = NULL;
        (*head) -> next -> prev = *head;

        return 0;
    }
    else
    { /* recursively call ll_add_to_tail until we get to the tail
         which is the point where the pointer is NULL */
        return ll_add_to_tail(&((*head)->next), val);
    }
}

/*deleting*/
int ll_del_from_head(llnode **ppList)
{
    struct llnode *temp = NULL;

    if (ppList == NULL)
    {
        return -1;
    }

    temp = *ppList;
    *ppList = temp->next;
    (*ppList)->prev = NULL;
    free(temp);

    return 0;

}
int ll_del_from_tail(llnode **ppList)
{
    struct llnode *temp = NULL;
    if (ppList == NULL)
    {
        return -1;
    }

    if ((*ppList)->next == NULL)
    {
        temp = *ppList;
        *ppList = NULL;
        free(temp);
        return 0;
    }
    else
    {
        return ll_del_from_tail(&((*ppList)->next));
    }
}

/*printing*/
int ll_print_from_head(llnode *p)
{   
    if (p==NULL)
    {   
        return 0;
    }
    else
    {   
        printf("val = %d\n",p->val);
        return ll_print_from_head(p->next);
    }
}
int ll_print_from_tail(llnode *p)
{
    if (p == NULL)
    {
        return -1;
    }
    if (p->next == NULL)
    {
        printf("%d\n",p->val);
        return 0;
    }
    else
    {
        ll_print_from_tail(p->next);
        printf("%d\n",p->val);
        return 0;
    }
}
/*shows where all the pointers are pointing to
  very useful to make sure fuctions are assinging poiners correctly*/
int ll_print_more( llnode *p)
{   
    if (p==NULL)
    {   
        return 0;
    }
    else if ((p->next == NULL) && (p->prev == NULL))
    {   
        printf("val = %d\n",p->val);
        printf("\t prev = NULL\t\tprev->val = NULL\n");
        printf("\t next = NULL\t\t next->val = NULL\n");
        return 0;
    }
    else if (p->next == NULL)
    {   
        printf("val = %d\n",p->val);
        printf("\t prev = %d\tprev->val = %d\n",p->prev,p->prev->val);
        printf("\t next = NULL\t\t next->val = NULL\n");
        return 0;
    }
    else if (p->prev == NULL)
    {    
         printf("val = %d\n",p->val);
         printf("\t prev = NULL\t\tprev->val = NULL\n");
         printf("\t next = %d\t next->val = %d\n",p->next,p->next->val);
         return ll_print_more(p->next);
    }
    else
    {   
        printf("val = %d\n",p->val);
        printf("\t prev = %d\tprev->val = %d\n",p->prev,p->prev->val);
        printf("\t next = %d\t next->val = %d\n",p->next,p->next->val);
        return ll_print_more(p->next);
    }
}

/*freeing*/
int ll_free( llnode *p)
{
    if (p == NULL) 
    {
        return -1;
    }
    else
    {
        llnode *f = p->next;
        free(p);
        return ll_free(f);
    }
}
