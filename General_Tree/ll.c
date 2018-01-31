int ll_add_to_head(llnode **head, TreeNode *tree) 
{
    llnode *old_head;
    if (head == NULL) 
    {
        return -1;
    }
    old_head = *head;

    *head = (llnode *) malloc(sizeof(llnode));
    (*head) -> tree = tree;
    (*head) -> next = old_head;
    return 0;
}

int ll_add_to_tail(llnode **head, TreeNode *tree) 
{
    if (head == NULL) 
    {
        return -1;
    }
    if (*head == NULL) 
    {
        *head = (llnode *) malloc(sizeof(llnode));
        (*head) -> tree = tree;
        (*head) -> next = NULL;
        return 0;
    } 
    else 
    { /* recursively call ll_add_to_tail until we get to the tail
         which is the point where the pointer is NULL */
        return ll_add_to_tail(&((*head)->next), tree);
    }
}

TreeNode* ll_find_by_value(llnode *pList, int val)
{
    if(pList == NULL)
    {
        return NULL;
    }
    if((pList->tree->val) == val)
    {
        return pList->tree;
    }
    else
    {
        return ll_find_by_value(pList->next, val);
    }
}

int ll_free(llnode *p) 
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

/*
int ll_print_from_head(llnode *p) 
{
    if (p==NULL) 
    {
        return 0;
    } 
    printf("val = %d\n",p->tree->val);
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
          printf("%d\n",p->tree->val);
          return 0;
      }
      else 
      {
          ll_print_from_tail(p->next);
          printf("%d\n",p->tree->val);
          return 0;
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
         free(temp->tree);
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
    free(temp->tree);
    free(temp);
    return 0;
}

int ll_del_by_value(llnode **ppList, int val)
{
    struct llnode *temp = NULL;
    
    if(ppList == NULL)
    {
        return -1;
    } 
   
    if (((*ppList)->tree->val) == val)
    {
        temp = *ppList;
        *ppList = temp->next;
        free(temp->tree);
        free(temp);
        return 0;
    }
    else
    {
        return ll_del_by_value(&((*ppList)->next),val);
    }

}

int ll_insert_in_order(llnode **ppList, TreeNode *tree) 
{
    llnode *prev = NULL;
    llnode *curr = NULL;

    if (ppList == NULL) 
    { 
        return -1; 
    }
    if (*ppList == NULL) 
    {
        return ll_add_to_head(ppList,tree);
    }
    if ((*ppList)->tree->val > tree->val) 
    {
        return ll_add_to_head(ppList,tree);
    } 
    else 
    {
        prev = *ppList;
        curr = (*ppList)->next;
        while(curr != NULL) 
        {
            if (curr->tree->val > tree->val)
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
        prev->next->tree  = tree;
        prev->next->next = curr;
        return 0;
    }
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
*/
