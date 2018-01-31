int max_int(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
/*assigns heights to each node*/
int assignHeights(TreeNode **root)
{
    int r = 0;
    int R = 0;
    int L = 0;
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        return -1; /*in this case -1 isn't because it's an error
                     it's to get the index of the heights right
                     it really doesnt matter technically
                     but like convention*/
    }
    else
    {
        L=assignHeights(&((*root)->left));
        R=assignHeights(&((*root)->right));
        r = max_int(L,R);
        (*root)->height = r+1;
        return r+1;
    }
}

int balance_factor(TreeNode *root)
{
    int bf = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL)
    {
        bf -= root->left->height+1;
    }
    if (root->right != NULL)
    {
        bf += root->right->height+1;
    }
    return bf;
}

int rotate_right(TreeNode **root)
{
    int r = 0;
    /*this needs to be done so we can change the root to t1 after the rotoation*/
    struct TreeNode **t1 = (TreeNode **)malloc(sizeof(TreeNode*));
    struct TreeNode **t2 = (TreeNode **)malloc(sizeof(TreeNode*));
    struct TreeNode **temp = (TreeNode **)malloc(sizeof(TreeNode*));
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        return -1;
    }
    /*rotate right*/
    *t1 = (*root)->left;
    *t2 = (*t1)->right;
    (*t1)->right = *root;
    (*root)->left = *t2;
    /*reasigning the root*/
    *temp = *root;
    *root = *t1;
    *t1 = *temp;
    r=assignHeights(root);
    return 0;
}

int rotate_left(TreeNode **root)
{
    int r = 0;
    /*this needs to be done so we can change the root to t1 after the rotoation*/
    struct TreeNode **t1 = (TreeNode **)malloc(sizeof(TreeNode*));
    struct TreeNode **t2 = (TreeNode **)malloc(sizeof(TreeNode*));
    struct TreeNode **temp = (TreeNode **)malloc(sizeof(TreeNode*));
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        return -1;
    }
    /*rotate left*/
    *t1 = (*root)->right;
    *t2 = (*t1)->left;
    (*t1)->left = *root;
    (*root)->right = *t2;
    /*reasigning the root*/
    *temp = *root;
    *root = *t1;
    *t1 = *temp;
    r=assignHeights(root);
    return 0;
}

/*rotate right child right then root left*/
int double_rotate_left(TreeNode **root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        return -1;
    }
    if ((*root)->right != NULL)
    {
        r=rotate_right(&((*root)->right));
        r=rotate_left(root);
        return 0;
    }
    else
    {
        /*the right child doesnt exist*/
        return -1;
    }
}

/*rotate left child left then root right*/
int double_rotate_right(TreeNode **root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        return -1;
    }
    if ((*root)->left != NULL)
    {
        r=rotate_left(&((*root)->left));
        r=rotate_right(root);
        return 0;
    }
    else
    {
        /*the left child doesnt exist*/
        return -1;
    }
}

/*the function that makes this an AVL Tree*/
int balance(TreeNode **root)
{
    int r = 0;
    int bf = balance_factor(*root);

    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        return 0;
    }
    /*  we want to call the these first so that we start at the bottom
        of the bottom of the tree and work our way up
        otherwise it wont stay an AVL tree 
    */
    r=balance(&((*root)->left));
    r=balance(&((*root)->right));
    if (bf < -1) /*root is left heavy*/
    {
        if (balance_factor((*root)->left) > 0) /*left child is right heavy*/
        {
            r=rotate_left(&((*root)->left));
        }
        r=rotate_right(root);
        return 0;
    }
    else if (bf > 1) /*root is right heavy*/
    {
        if (balance_factor((*root)->right) < 0) /*right child is left heavy*/
        {
            r=rotate_right(&((*root)->right));
        }
        r=rotate_left(root);
        return 0;
    }
    return 0;
}

/*add nodes so that they are in numerical order and balances the tree*/
int add_rec(TreeNode **head, TreeNode **root, int val)
{
    int r = 0;
    if (root == NULL)
    {   
        return -1; 
    }   

    if (*root == NULL)
    {   
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        (*root)->left = NULL;
        (*root)->val = val;
        (*root)->right = NULL;
        (*root)->height = 0;  
        /*every time it adds a node
          it re-assigns the heights and balances it*/
        r=assignHeights(head);
        r=balance(head);
        return 0;
    }   
    else
    {   
        if ((*root)->val > val)
        {   
            return add_rec(head,&((*root)->left),val);
        }   
        else if((*root)->val < val)
        {   
            return add_rec(head,&((*root)->right),val);
        }   
        return 0;
    }   
}
int add(TreeNode **root, int val)
{
    return add_rec(root, root, val);
}
