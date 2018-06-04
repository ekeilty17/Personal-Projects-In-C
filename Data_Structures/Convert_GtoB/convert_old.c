#include "g_tree.c"
#include "b_tree.c"

/*function prototypes*/
int B_Child(bstNode *b_tree, llnode *t_list);
int B_Sibling(bstNode *b_tree, llnode *t_list);
bstNode* ConvertToBinaryTree(TreeNode *g_tree);
int T_Sibling(TreeNode **g_tree, bstNode *b_tree);
TreeNode* ConvertToGeneralTree(bstNode *b_tree);

/*General Tree to Binary Tree*/
int B_Child(bstNode *b_tree, llnode *t_list)
{
    int r = 0;
    if (b_tree == NULL)
    {
        return -1;
    }
    if (t_list == NULL)
    {
        return -1;
    }
    
    b_tree->left = b_add(t_list->tree->val);
    if (t_list->tree->succs != NULL)
    {
        r=B_Child(b_tree->left, t_list->tree->succs);
    }
    if (t_list->next != NULL)
    {
        r=B_Sibling(b_tree->left, t_list->next);
    }
    return 0;
}

int B_Sibling(bstNode *b_tree, llnode *t_list)
{
    int r = 0;
    if (b_tree == NULL)
    {
        return -1;
    }
    if (t_list == NULL)
    {
        return -1;
    }
    
    b_tree->right = b_add(t_list->tree->val);
    if (t_list->tree->succs != NULL)
    {
        r=B_Child(b_tree->right, t_list->tree->succs);
    }
    if (t_list->next != NULL)
    {
        r=B_Sibling(b_tree->right, t_list->next);
    }
    return 0;
}

bstNode* ConvertToBinaryTree(TreeNode *g_tree)
{
    bstNode *root = NULL;
    int r = 0;
    if (g_tree == NULL)
    {
        return NULL;
    }
    
    root = b_add(g_tree->val);
    r=B_Child(root, g_tree->succs);
    return root;
}


/*Binary Tree to General Tree*/
int T_Sibling(TreeNode **g_tree, bstNode *b_tree)
{
    int r = 0;
    TreeNode *x = NULL;
    if (g_tree == NULL)
    {
        return -1;
    }
    if (*g_tree == NULL)
    {
        return -1;
    }
    if (b_tree == NULL)
    {
        return -1;
    }
    x = init(b_tree->val);
    r=g_add(g_tree, x);
    if (b_tree->left != NULL)
    {
        r=T_Sibling(&x, b_tree->left);
    }
    if (b_tree->right != NULL)
    {
        r=T_Sibling(g_tree, b_tree->right);
    }
    return 0;
}

TreeNode* ConvertToGeneralTree(bstNode *b_tree)
{
    TreeNode *root = NULL;
    int r = 0;
    if (b_tree == NULL)
    {
        return NULL;
    }
    if (b_tree->right != NULL)
    {
        return NULL;
    }
    root = init(b_tree->val);
    r=T_Sibling(&root, b_tree->left);
    return root;
}
