#include "ll_lib.c"

/*index and length are nice things to have access to sometimes*/
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

/*searching*/
llnode* ll_search(llnode *pList, int val)
{   
    if (pList == NULL)
    {
        return NULL;
    }
    if (pList->val == val)
    {
        return pList;
    }
    else
    {
        return ll_search(pList->next, val);
    }
} 
int ll_find_by_value(llnode *pList, int val)
{
    if(pList==NULL)
    {
        return -1;
    }
    if(pList->val == val)
    {
        return 0;
    }
    else
    {
        return ll_find_by_value(pList->next, val);
    }
}

/*delete*/
int ll_delete(llnode **ppList,int val)
{
    struct llnode *temp = NULL;
    
    if(ppList == NULL)
    {
        return -1;
    } 
   
    if ((*ppList)->val == val)
    {
        temp = *ppList;
        *ppList = temp->next;
        free(temp);
        return 0;
    }
    else
    {
        return ll_delete(&((*ppList)->next),val);
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

/*merge two lists*/
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

/*get parent node*/
llnode* ll_parent(llnode *head, llnode *curr)
{
    llnode *temp = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->next == curr)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

/*reverse the direction of a linked list*/
int ll_reverse(llnode **ppList)
{
    llnode *parent = NULL;
    llnode *curr = NULL;
    llnode *temp = NULL;
    if (ppList == NULL)
    {
        return -1;
    }
    if (*ppList == NULL)
    {
        return 0;
    }
    if ((*ppList)->next == NULL)
    {
        return 0;
    }
    parent = NULL;
    curr = *ppList;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = parent;
        parent = curr;
        curr = temp;
    }
    *ppList = parent;
    return 0;
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
