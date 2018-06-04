struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

#include "ll_queue.c"

/*allows user to put the tree in any order they wish*/
TreeNode* add(int val)
{
    TreeNode *temp = NULL;
    temp->left = NULL;
    temp->val = val;
    temp->right = NULL;
    return temp;
}

/*add nodes so that they are in numerical order*/
int add_in_order(TreeNode **root, int val)
{
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
            return add_in_order(&((*root)->left),val);
        }
        else if((*root)->val < val)
        {   
            return add_in_order(&((*root)->right),val);
        }
        else
        {
            return 0;
        }
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

int delete(TreeNode **root, int val)
{
    int r = 0;
    TreeNode *temp = NULL;
    if (root == NULL)
    {
        return -1;
    }
    /*base case*/
    if (*root == NULL)
    {
        return -1;
    }
    /*navigating to get to the node*/
    if (val < (*root)->val)
    {
        r=delete(&((*root)->left), val);
    }
    else if (val > (*root)->val)
    {
        r=delete(&((*root)->right), val);
    }
    /*we found the node to delete*/
    else
    {
        /*easy case where the node only has 1 child*/
        if ((*root)->left == NULL)
        {
            temp = (*root)->right;
            /*Heapfree(*root);*/
            return 0;
        }
        /*easy case where the node has 1 child*/
        else if ((*root)->right == NULL)
        {
            temp = (*root)->left;
            /*free(*root);*/
            return 0;
        }
        /*node has 2 children*/
        temp = Min((*root)->right);             /*take the min node down the right branch*/
        (*root)->val = temp->val;               /*assign the min value to the root*/
        r=delete(&((*root)->right), temp->val); /*then put everthing else on the right*/
    }
    return 0;
}

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

int Level_Order(TreeNode *root)
{
    int r = 0;
    int count = 0;
    TreeNode *temp = NULL;
    Queue *q = NULL;
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

int printDepth_rec(TreeNode *root, int tab)
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
