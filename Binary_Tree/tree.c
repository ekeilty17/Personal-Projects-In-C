struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

#include "queue.c"

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

/*example of transversing (visiting every node in order)*/
int print_tree(TreeNode *root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        r=print_tree(root->left);
        printf("%d\n",root->val);
        r=print_tree(root->right);
        return 0;
    }
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

int printLevelOrder(TreeNode *root)
{
    int r = 0;
    int count = 0;
    TreeNode *temp = NULL;
    if (root == NULL)
    {
        return -1;
    }
    Queue q;
    r=init(&q);
    r=enq(&q, root);
    
    while (q.size != 0)
    {
        count = q.size;
        /*technically we can transverse the tree with only 1 while loop
          but in order to get the printf("\n") in the proper place
          we need the second while loop and the counter*/
        while (count > 0)
        {
            r=(q.store[0])->val;
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
            

/*make a delete from tree function*/
/*make a balance tree function so the length of it is always log(n)*/
