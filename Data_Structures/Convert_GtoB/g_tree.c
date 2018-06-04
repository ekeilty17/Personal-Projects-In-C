struct llnode {
   struct TreeNode *tree; /*linked list of tree nodes*/
   struct llnode *next;
};
typedef struct llnode llnode;

struct TreeNode {
    int val;
    struct llnode *succs;
};
typedef struct TreeNode TreeNode;

/*add to tail function to linked list*/
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
    { 
        return ll_add_to_tail(&((*head)->next), tree);
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

/*Only the General Tree code that makes it functional*/
TreeNode* init(int val)
{
    int r=0;
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->succs = NULL;
    return temp;
}

/*there's no way of organizing a general tree that isn't arbitrary
so the user will have to put the tree in the order they wish*/
/*this means instead of adding a value, they have to add a node*/
int g_add(TreeNode **root, TreeNode *node)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        /*the root was not initialized as a node*/
        return -1;
    }
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        r=ll_add_to_tail(&((*root)->succs), node);
        return 0;
    }
}

int g_printDepth_rec(TreeNode *root, int tab)
{
    int i = 0;
    llnode *curr = root->succs;
    for(i=0; i<tab; i++)
    {
        printf("\t");
    }
    tab += 1;
    printf("%d\n",root->val);
    
    while (curr != NULL)
    {
        g_printDepth_rec(curr->tree, tab);
        curr = curr->next;
    }
    return 0;
}
int g_printDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return g_printDepth_rec(root, 0);
}

int free_g_tree(TreeNode *root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        llnode *head = root->succs;
        llnode *curr = head;
        free(root);
        while (curr != NULL)
        {
            r=free_g_tree(curr->tree);
            curr = curr->next;
        }
        r=ll_free(head);
        return 0;
    }
}
