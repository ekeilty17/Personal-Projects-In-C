struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

int add(TreeNode **root, int val);
int print(TreeNode *root);
int TreeFree(TreeNode *root);

int add(TreeNode **root, int val)
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
        return 0;
    }
    else
    {
        if ((*root)->val > val)
        {
            r=add(&((*root)->left),val);
        }
        else if((*root)->val < val)
        {   
            r=add(&((*root)->right),val);
        }
        else
        {
            return 0;
        }
    }
}

int print(TreeNode *root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        r=print(root->left);
        printf("%d\n",root->val);
        r=print(root->right);
        return 0;
    }
}

int TreeFree(TreeNode *root)
{
    int temp = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        TreeNode *r = root->left;
        TreeNode *l = root->right;
        free(root);
        temp=TreeFree(r);
        temp=TreeFree(l);
    }
    return 0;
}
