/*this file contains the necessary functions to make a linked list work*/

struct llnode {            /* since the llnode is a self-referential structure */
   int val;                /* we can not compile the struct and typedef decl into one */
   struct llnode *next;
};
typedef struct llnode llnode;

//adding
int ll_add_to_head(llnode **head, int val)
{   
    llnode *old_head = NULL;
    if (head == NULL)
    {   
        return -1;
    }

    old_head = *head;
    *head = (llnode *) malloc(sizeof(llnode));
    (*head)->val = val;
    (*head)->next = old_head;
    return 0;
}
int ll_add_to_tail(llnode **head, int val)
{
    llnode *temp = NULL;
    if (head == NULL)
    {
        return -1;
    }
    if (*head == NULL)
    {
        return ll_add_to_head(head, val);
    }

    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return ll_add_to_head(&(temp->next),val);
}

//deleting
int ll_del_from_head(llnode **ppList)
{
    llnode *temp = NULL;
    if (ppList == NULL)
    {
        return -1;
    }
    if (*ppList == NULL)
    {
        return 0;
    }
    
    temp = *ppList;
    *ppList = temp->next;
    free(temp);

    return 0;
}
int ll_del_from_tail(llnode **ppList)
{
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
         return ll_del_from_head(ppList);
    }
        
    temp = *ppList;
    while (temp->next->next != NULL)
    {
       temp = temp->next;
    } 
    return ll_del_from_head(&(temp->next));
}

//printing
int ll_print_from_head(llnode *p)
{
    while (p != NULL)
    {
        printf("val = %d\n",p->val);
        p = p->next;
    }
    return 0;
}
int ll_print_from_tail(llnode *p)
{
    //Unless I want to implement a stack, recurssion is THE way to write this function
    //So I'm just gonna leave it
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

//freeing
int ll_free(llnode *p)
{   
    llnode *temp = NULL;
    if (p == NULL)
    {
        return -1;
    }
    
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    return 0;
}
