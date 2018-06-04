#include <stdio.h>
#include <stdlib.h>
#include "convert.c"

int main(void)
{
    int r = 0;
    /*General Tree Definitions*/
    TreeNode *b_to_g = NULL;
    TreeNode *back_to_g = NULL;
    TreeNode *g_root = init(1000);
    TreeNode *y = init(2000);
    TreeNode *z = init(3000);
    TreeNode *c = init(5);
    TreeNode *d = init(6);
    TreeNode *e = init(10);
    TreeNode *f = init(11);
    TreeNode *g = init(120);
    TreeNode *h = init(1234);
    /*Binary Tree Node*/
    bstNode *b_root = NULL;
    bstNode *g_to_b = NULL;
    bstNode *back_to_b = NULL;
    
    /*making General Tree*/
    r=g_add(&g_root, y);
    r=g_add(&g_root, f);
    r=g_add(&g_root, g);
    r=g_add(&y, d);
    r=g_add(&y, z);
    r=g_add(&y, e);
    r=g_add(&z, c);
    r=g_add(&g, h);
    printf("\nOriginal a General Tree\n");
    r=g_printDepth(g_root);
    
    g_to_b = ConvertToBinaryTree(g_root); 
    printf("\nConverted Binary Tree\n");
    r=b_printDepth(g_to_b);
    
    /*Converting back to General Tree*/
    back_to_g = ConvertToGeneralTree(g_to_b);
    printf("\nConverted Back to General Tree\n");
    r=g_printDepth(back_to_g);
    
    printf("________________________________\n");
    
    /*making the Binary Tree*/
    r=b_add_in_order(&b_root, 10000);
    r=b_add_in_order(&b_root, 100);
    r=b_add_in_order(&b_root, 500);
    r=b_add_in_order(&b_root, -5);
    r=b_add_in_order(&b_root, 10);
    r=b_add_in_order(&b_root,1);
    r=b_add_in_order(&b_root, -10);
    r=b_add_in_order(&b_root, 50);
    r=b_add_in_order(&b_root, 3);
    r=b_add_in_order(&b_root, 90);
    r=b_add_in_order(&b_root, 0);

    printf("\nOriginal Binary Tree\n");
    r=b_printDepth(b_root);    
    
    b_to_g = ConvertToGeneralTree(b_root);
    printf("\nConverted to General Tree\n");
    r=g_printDepth(b_to_g);
    
    /*Converting back to Binary Tree*/
    back_to_b = ConvertToBinaryTree(b_to_g);
    printf("\nConverted Back to Binary Tree\n");
    r=b_printDepth(back_to_b);

    return 0;
}
