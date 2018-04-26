#include <stdio.h>
#include <stdlib.h>
#include "g_tree.c"

int main(void)
{
    TreeNode *temp = NULL;
    llnode *ll_temp = NULL;
    TreeNode *x = init(1000);
    TreeNode *y = init(2000);
    TreeNode *z = init(3000);
    TreeNode *c = init(5);
    TreeNode *d = init(6);
    TreeNode *e = init(10);
    TreeNode *f = init(11);
    TreeNode *g = init(120);
    TreeNode *h = init(1234);
    int r = 0; 
    
    r=g_add(&x, y);
    r=g_add(&x, f);
    r=g_add(&x, g);
    r=g_add(&y, d);
    r=g_add(&y, z);
    r=g_add(&y, e);
    r=g_add(&z, c);
    r=g_add(&g, h);
    
    printf("Depth Order\n");
    r=g_printDepth(x);

    r=free_g_tree(x);
    
    return 0;
}
