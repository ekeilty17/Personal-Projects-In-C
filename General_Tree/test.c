#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

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
    
    r=add(&x, y);
    r=add(&x, f);
    r=add(&x, g);
    r=add(&y, d);
    r=add(&y, z);
    r=add(&y, e);
    r=add(&z, c);
    r=add(&g, h);
    
    printf("Depth Order\n");
    r=printDepth(x);

    printf("\nLevel Order\n");
    r=Level_Order(x);
    
    printf("\n\n");
    temp=searchTree(x, 1000);
    if (temp == NULL)
    {
        printf("does 1000 exist? NULL\n");
    }
    else
    {
        printf("does 1000 exist? %d\n",temp->val);
    } 
    printf("\n");
    temp=searchTree(x, 120);
    if (temp == NULL)
    {
        printf("does 120 exist? NULL\n");
    }
    else
    {
        printf("does 120 exist? %d\n",temp->val);
    }
    printf("\n");
    temp=searchTree(x, 789);
    if (temp == NULL)
    {
        printf("does 789 exist? NULL\n");
    }
    else
    {
        printf("does 789 exist? %d\n",temp->val);
    }

    r=free_tree(x);
    
    return 0;
}
