#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(void)
{
    TreeNode *tree = NULL;
    int r = 0;   
    
    r=add(&tree, 10);
    r=add(&tree, 100);
    r=add(&tree,1);
    r=add(&tree, 50);
    r=add(&tree, 10000);
    r=add(&tree, 3);
    r=add(&tree, 90);
    r=add(&tree, 500);
    r=add(&tree, 0);
    r=add(&tree, -10);
    r=add(&tree, -5);

    print(tree);
    
    r=TreeFree(tree);

    return 0;
}
