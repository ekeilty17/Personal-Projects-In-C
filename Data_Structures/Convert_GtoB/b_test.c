#include <stdio.h>
#include <stdlib.h>
#include "b_tree.c"

int main(void)
{
    bstNode *tree = NULL;
    bstNode *temp = NULL;
    int r = 0;   
    
    r=b_add_in_order(&tree, 10);
    r=b_add_in_order(&tree, 100);
    r=b_add_in_order(&tree,1);
    r=b_add_in_order(&tree, 50);
    r=b_add_in_order(&tree, 10000);
    r=b_add_in_order(&tree, 3);
    r=b_add_in_order(&tree, 90);
    r=b_add_in_order(&tree, 500);
    r=b_add_in_order(&tree, 0);
    r=b_add_in_order(&tree, -10);
    r=b_add_in_order(&tree, -5);
    
    printf("\nPrint Depth\n");
    r=b_printDepth(tree);

    r=free_b_tree(tree);

    return 0;
}
