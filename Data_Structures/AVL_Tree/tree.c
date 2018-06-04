struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
};
typedef struct TreeNode TreeNode;

#include "ll_queue.c"
#include "avl.c"

/*Transversals (visiting every node in order)*/
int Pre_Order(TreeNode *root)
{   
    int r = 0;
    if (root == NULL)
    {   
        return -1;
    }
    else
    {   
        printf("%d\n",root->val);
        r=Pre_Order(root->left);
        r=Pre_Order(root->right);
        return 0;
    }
}

/*gives you an in order list (given the data was added correctly)*/
int In_Order(TreeNode *root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        r=In_Order(root->left);
        printf("%d\n",root->val);
        r=In_Order(root->right);
        return 0;
    }
}

int Post_Order(TreeNode *root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        r=Post_Order(root->left);
        r=Post_Order(root->right);
        printf("%d\n",root->val);
        return 0;
    }
}

/*shows each level of the tree*/
int Level_Order(TreeNode *root)
{
    int r = 0;
    int count = 0;
    Queue *q = NULL;
    TreeNode *temp = NULL;
    if (root == NULL)
    {
        return -1;
    }
    r=enq(&q, root);

    while (q != NULL)
    {
        count = size(q);
        /*technically we can transverse the tree with only 1 while loop
          but in order to get the printf("\n") in the proper place
          we need the second while loop and the counter*/
        while (count > 0)
        {
            r=q->val->val;
            printf("%d ",r);
            r=deq(&q, &temp);
            if (temp->left != NULL)
            {
                r=enq(&q, temp->left);
            }
            if (temp->right != NULL)
            {
                r=enq(&q, temp->right);
            }
            count -= 1;
        }
        printf("\n");
    }
    return 0;
}

/*a way to show the heirarchical structure of the tree*/
int printDepth_rec(TreeNode *root, int tab)
{
    int i = 0;
    int bf = 0;
    for(i=0; i<tab; i++)
    {
        printf("\t");
    }
    tab += 1;
    bf = balance_factor(root);
    printf("%d,%d,%d\n",root->val,root->height,bf);
    /*printf("%d\n",root->val);*/
    if (root->right != NULL)
    {
        printDepth_rec(root->right, tab);
    }
    if (root->left != NULL)
    {
        printDepth_rec(root->left, tab);
    }
    return 0;
}
int printDepth(TreeNode *root)
{
    return printDepth_rec(root, 0);
}

/*searching*/
TreeNode* searchTree(TreeNode *root, int val)
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

TreeNode* Min(TreeNode *root)
{
    TreeNode *min;
    if (root == NULL)
    {
        return NULL;
    }
    min = root;
    while (min->left != NULL)
    {
        min = min->left;
    }
    return min;
}

TreeNode* Max(TreeNode *root)
{   
    TreeNode *max;
    if (root == NULL)
    {
        return NULL;
    }
    max = root;
    while (max->right != NULL)
    {
        max = max->right;
    }
    return max;
}

int free_tree(TreeNode *root)
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
        temp=free_tree(r);
        temp=free_tree(l);
    }
    return 0;
}

/*make a delete from tree function*/
