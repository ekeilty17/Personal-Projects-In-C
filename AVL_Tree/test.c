#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(void)
{
    TreeNode *tree = NULL;
    TreeNode *temp = NULL;
    int r = 0;   
    /*
    r=add(&tree, -10);
    r=add(&tree, 10);
    r=add(&tree,100);
    r=add(&tree, 50);
    r=add(&tree, 3);
    r=add(&tree, 90);
    r=add(&tree, 0);
    r=add(&tree, 500);
    r=add(&tree, 700);
    */
    
    r=add(&tree, -1);
    r=add(&tree, 0);
    r=add(&tree, 1);
    r=add(&tree, 3);
    r=add(&tree, 4);
    r=add(&tree, 5);
    r=add(&tree, 6);
    r=add(&tree, 7);
    r=add(&tree, 8);
    
    printf("\nPrint Depth\n");
    r=printDepth(tree);
    printf("\n\n");
    r=Level_Order(tree);
    printf("\n\n");
    r=In_Order(tree);
    /*
    r=add(&tree, 50);
    r=add(&tree, 3);
    r=add(&tree, 90);
    r=add(&tree, 0);
    r=add(&tree, 500);
    r=add(&tree, 700);
    r=add(&tree, 1000);
    r=add(&tree, -5);
    */
    
    r=free_tree(tree);

    return 0;
}
