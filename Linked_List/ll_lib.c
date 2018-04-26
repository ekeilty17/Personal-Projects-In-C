/*this file contains the necessary functions to make a linked list work*/

struct llnode {            /* since the llnode is a self-referential structure */
   int val;                /* we can not compile the struct and typedef decl into one */
   struct llnode *next;
};
typedef struct llnode llnode;

/*adding*/
int ll_add_to_head( llnode **head, int val)
{   
    llnode *old_head;
    if (head == NULL)
    {   
        return -1;
    }
    old_head = *head;
    
    *head = ( llnode *) malloc(sizeof( llnode));
    (*head) -> val = val;
    (*head) -> next = old_head;
    return 0;
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
    free(temp);

    return 0;
}
int ll_del_from_tail(llnode **ppList)
{
    struct llnode *temp = NULL;
    /*  ppList is an int**
        therefore *ppList is the address of the pointer
        and ppList is the address of the address of the pointer
        *ppList is the address of the first element in the list
        **ppList is the value at the first element in the list
     */
    /*  checks if any memory was allovated to the  pointer...aka if it was initialized */
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
    printf("val = %d\n",p->val);
    return ll_print_from_head(p->next);
}
int ll_print_from_tail(llnode *p)
{
    if (p==NULL)
    {
        return -1;
    }
    else
    {
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
        llnode *f=p->next;
        free(p);
        return ll_free(f);
    }
}
