struct bstNode {
    int val;
    struct bstNode *left;
    struct bstNode *right;
};
typedef struct bstNode bstNode;

/*add nodes so that they are in numerical order*/
bstNode* b_add(int val)
{
    bstNode *temp = (bstNode *)malloc(sizeof(bstNode));
    temp->left = NULL;
    temp->val = val;
    temp->right = NULL;
    return temp;
}

int b_add_in_order(bstNode **root, int val)
{
    if (root == NULL)
    {
        return -1;
    }

    if (*root == NULL)
    {
        *root = (bstNode *)malloc(sizeof(bstNode));
        (*root)->left = NULL;
        (*root)->val = val;
        (*root)->right = NULL;
        return 0;
    }
    else
    {
        if ((*root)->val > val)
        {
            return b_add_in_order(&((*root)->left),val);
        }
        else if((*root)->val < val)
        {   
            return b_add_in_order(&((*root)->right),val);
        }
        else
        {
            return 0;
        }
    }
}

int b_printDepth_rec(bstNode *root, int tab)
{
    int i = 0;
    for(i=0; i<tab; i++)
    {
        printf("\t");
    }
    tab += 1;
    printf("%d\n",root->val);
    if (root->right != NULL)
    {
        b_printDepth_rec(root->right, tab);
    }
    if (root->left != NULL)
    {
        b_printDepth_rec(root->left, tab);
    }
    return 0;
}
int b_printDepth(bstNode *root)
{
    return b_printDepth_rec(root, 0);
}

bstNode* searchTree(bstNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        return root;
    }
    if (val < root->val)
    {
        return searchTree(root->left, val);
    }
    else
    {
        return searchTree(root->right, val);
    }
}

int free_b_tree(bstNode *root)
{
    int temp = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        bstNode *r = root->left;
        bstNode *l = root->right;
        free(root);
        temp=free_b_tree(r);
        temp=free_b_tree(l);
    }
    return 0;
}
