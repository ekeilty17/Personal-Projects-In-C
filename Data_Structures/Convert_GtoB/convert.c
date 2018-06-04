#include "g_tree.c"
#include "b_tree.c"


bstNode* ConvertToBinaryTree_rec(TreeNode *g_tree, llnode *siblings)
{
    bstNode *b_tree = NULL;
    //got down to the bottom of the tree
    if (g_tree == NULL)
    {
        return NULL;
    }
    //init b_tree
    b_tree = (bstNode *)malloc(sizeof(bstNode));
    b_tree->val = g_tree->val;
    
    //if not successors, then nothing to add to the left
    if (g_tree->succs == NULL)
    {
        b_tree->left = NULL;
    }
    else
    {
        //else add the next sucessor to the left
        b_tree->left = ConvertToBinaryTree_rec(g_tree->succs->tree, g_tree->succs->next);
    }
    
    //if not siblings, then nothing to add to the right
    if (siblings == NULL)
    {
        b_tree->right = NULL;
    }
    else
    {
        //else add the next sibling to the right
        b_tree->right = ConvertToBinaryTree_rec(siblings->tree, siblings->next);
    }
    
    return b_tree;
}


bstNode* ConvertToBinaryTree(TreeNode *g_tree)
{
    if (g_tree == NULL)
    {
        return NULL;
    }
    return ConvertToBinaryTree_rec(g_tree, NULL);
}


int ConvertToGeneralTree_rec(bstNode *b_tree, TreeNode **g_tree)
{
    int r = 0;
    TreeNode *g_child = NULL;
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
    g_child = init(b_tree->val);
    r=g_add(g_tree, g_child);
    if (b_tree->left != NULL)
    {
        r=ConvertToGeneralTree_rec(b_tree->left, &g_child);
    }
    if (b_tree->right != NULL)
    {
        r=ConvertToGeneralTree_rec(b_tree->right, g_tree);
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
    r=ConvertToGeneralTree_rec(b_tree->left, &root);
    return root;
}
