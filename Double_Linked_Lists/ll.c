struct llnode {            /* since the llnode is a self-referential structure */
    int val;                /* we can not compile the struct and typedef decl into one */
    struct llnode *next;
    struct llnode *prev;
};
typedef struct llnode llnode;

/*
list of all the functions
int ll_add_to_head( llnode **head, int val);
int ll_add_to_tail( llnode **head, int val);
int ll_print( llnode *p);
int ll_print_more( llnode *p);
int ll_free( llnode *p);

int ll_find_by_value(llnode *pList,int val);
int ll_del_from_tail(llnode **ppList);
int ll_del_from_head(llnode **ppList);
int ll_del_by_value(llnode **ppList,int val);
int ll_insert_in_order(llnode **ppList,int val);
int ll_concat(llnode **pSrcA,llnode **pSrcB);
int ll_sort(llnode **ppList);
*/

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

int ll_print( llnode *p)
{
    if (p==NULL)
    {   
        return 0;
    }
    else
    {
        printf("val = %d\n",p->val);
        return ll_print(p->next);
    }
}

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

int ll_free( llnode *p) 
{
    if (p==NULL) {
        return -1;
    } 
    else 
    {
        llnode *f=p->next;
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
    else
    {
        if((pList->val)==val)
        {
            return 0;
        }
        else
        {
            return ll_find_by_value(pList->next, val);   
        }
    }
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

int ll_del_by_value(llnode **ppList,int val)
{
    int r = 0;
    struct llnode *temp = NULL;
    
    if(ppList == NULL)
    {
        return -1;
    } 
   
    if ((*ppList)->val == val)
    {
        if((*ppList)->next == NULL)
        {
            r = ll_del_from_tail(ppList);
        }
        else
        {
            temp = *ppList;
            *ppList = temp->next;
            (*ppList)->prev = temp->prev;
            free(temp);
            return 0;
        }
    }
    else
    {
        return ll_del_by_value(&((*ppList)->next),val);
    }

}

int ll_insert_in_order(llnode **ppList,int val) 
{
    llnode *prev = NULL;
    llnode *curr = NULL;

    if (ppList == NULL) 
    { 
        return -1; 
    }
    if (*ppList == NULL) 
    {
        return ll_add_to_head(ppList,val);
    }
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
            if (curr->val >= val) 
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
        prev->next->val = val;
        prev->next->next = curr;
        prev->next->prev = prev;
        if (curr != NULL)
        {
            curr->prev = prev->next;
        }
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
        (*pSrcB)->prev = *pSrcA;
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
