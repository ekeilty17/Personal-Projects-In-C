struct llnode {            /* since the llnode is a self-referential structure */
   int val;                /* we can not compile the struct and typedef decl into one */
   struct llnode *next;
};
typedef struct llnode llnode;

/*
list of the functions
int ll_add_to_head( llnode **head, int val);
int ll_add_to_tail( llnode **head, int val);
int ll_print_from_head( llnode *p);
int ll_print_from_tail( llnode *p);
int ll_free( llnode *p);

int ll_find_by_value(llnode *pList,int val);
int ll_del_from_tail(llnode **ppList);
int ll_del_from_head(llnode **ppList);
int ll_del_by_value(llnode **ppList,int val);
int ll_insert_in_order(llnode **ppList,int val);
int ll_concat(llnode **pSrcA,llnode **pSrcB);
int ll_sort(llnode **ppList);
int ll_index(llnode *pList, int index);
int ll_length(llnode *pList);
*/

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
        return 0; 
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

int ll_find_by_value(llnode *pList,int val)
{
    if(pList==NULL)
    {
        return -1;
    }
    if((pList->val)==val)
    {
        return 0;
    }
    else
    {
        return ll_find_by_value(pList->next, val);
    }
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
    if (*ppList == NULL)
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

int ll_del_from_head(llnode **ppList)
{
    struct llnode *temp = NULL;
    
    if (ppList == NULL)
    {
        return -1;
    }   
    if (*ppList == NULL)
    {
        return -1;
    }

    temp = *ppList;
    *ppList = temp->next;
    free(temp);
    
    return 0;   

}

int ll_del_by_value(llnode **ppList,int val)
{
    struct llnode *temp = NULL;
    
    if(ppList == NULL)
    {
        return -1;
    } 
   
    if (((*ppList)->val) == val)
    {
        temp = *ppList;
        *ppList = temp->next;
        free(temp);
        return 0;
    }
    else
    {
        return ll_del_by_value(&((*ppList)->next),val);
    }

}

/*this function assumes the list is in numerical order*/
int ll_insert_in_order(llnode **ppList,int val) 
{
       /* we are going to iterate through the linked list to find the
          insertion point; we will need to track the prior node so we
          can stitch in the new node properly
          -> thus we will create two pointers to track the nodes
          "curr" and "prev"
       */
    llnode *prev = NULL;
    llnode *curr = NULL;

    if (ppList == NULL) 
    { 
        return -1; 
    }
    if (*ppList == NULL) 
    {
        /* if we're dealing with an empty linked list, just call
           add to head */
        return ll_add_to_head(ppList,val);
    }
    /* otherwise: we iterate through the list until will find the
       insert location */
    /* first we handle the degenerate case of the first node */
    if ((*ppList) -> val > val) 
    {
        return ll_add_to_head(ppList,val);
    } 
    else 
    {
        prev = *ppList;
        curr = (*ppList)->next;
        while(curr != NULL) 
        {
            if (curr->val > val) 
            {
                break;
            } 
            else 
            {
                prev = curr;
                curr = prev->next;
            }
        }
        prev->next = (llnode *) malloc(sizeof(llnode));
        prev->next->val  = val;
        prev->next->next = curr;
        return 0;
    }
}

int ll_concat(llnode **pSrcA,llnode **pSrcB)
{
    if(pSrcA == NULL)
    {
        return -1;
    }
    if(pSrcB == NULL)
    {
        return -1;
    }
    
    if ((*pSrcA)->next == NULL)
    {
        (*pSrcA)->next = *pSrcB;
        return 0;
    }
    else
    {
        return ll_concat(&((*pSrcA)->next),pSrcB);
    }
}

int ll_sort(llnode **ppList)
{
    int swapped = 1;
    struct llnode *address_start_list = NULL;
    int temp = 0;
    
    address_start_list = *ppList;

    if(ppList == NULL)
    {
        return -1;
    }
    if(*ppList == NULL)
    {
        return -1;
    }
    while (swapped)
    {
        swapped = 0;
        while((*ppList)->next != NULL)
        {
            if ((*ppList)->val > (*ppList)->next->val)
            {
                temp = (*ppList)->val;
                (*ppList)->val = (*ppList)->next->val;
                (*ppList)->next->val = temp;
                
                *ppList = address_start_list;
                swapped = 1;
            }
            else
            {
                *ppList = (*ppList)->next;
            }
        }
    }
    *ppList = address_start_list;
    return 0;
}

int ll_index(llnode *pList, int index)
{
    int i = 0;
    for(i=0; i<index; i++)
    {
        if (pList->next == NULL)
        {
            return -1;
        }
        else
        {
            pList = pList->next;
        }
    }
    return pList->val;
}

int ll_length(llnode *pList)
{
    llnode *curr = pList;
    int n = 0;
    while(curr != NULL)
    {
        n += 1;
        curr = curr->next;
    }
    return n;
}
