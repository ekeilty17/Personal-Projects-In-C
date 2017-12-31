#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
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
    
    /*  need to find the last element in list
        but...we can't back track once we find that element,
        so we have to manually get the value at the next element
        if the value at the next element is equal to NULL, then its the last element
    */

    /*this is the second to last element in the list*/
    /*
    if (((*ppList)->next->next) == NULL)
    {
        temp = (*ppList)->next;
        (*ppList)->next = NULL;
        free(temp);
        return 0;
    }
    */
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
/* my insert in order
int ll_insert_in_order(llnode **ppList,int val)
{
    int r = 0;
    if(ppList == NULL)
    {
        return -1;
    }
    
    if( (((*ppList)->next)) == NULL )
    {
        return -1;
    }
    else if( (((*ppList)->val) <= val) && (val <= ((*ppList)->next->val)) )
    {
        r = ll_add_to_head(&((*ppList)->next), val);
        return 0;
    }
    else
    {
        return ll_insert_in_order(&((*ppList)->next),val);
    }
}
*/

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
    /*printf("\n\nstart: %d current: %d\n\n",address_start_list->val, (*ppList)->val);*/
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
                
                /*printf("\n\nstart: %d current: %d\n\n",address_start_list->val, (*ppList)->val);*/
                
                *ppList = address_start_list;
                swapped = 1;
            }
            else
            {
                *ppList = (*ppList)->next;
                /*temp = ll_print(*ppList);*/
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
