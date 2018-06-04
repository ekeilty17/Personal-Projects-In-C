#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(void)
{
    TreeNode *tree = NULL;
    TreeNode *temp = NULL;
    int r = 0;   
    
    r=add_in_order(&tree, 10);
    r=add_in_order(&tree, 100);
    r=add_in_order(&tree,1);
    r=add_in_order(&tree, 50);
    r=add_in_order(&tree, 10000);
    r=add_in_order(&tree, 3);
    r=add_in_order(&tree, 90);
    r=add_in_order(&tree, 500);
    r=add_in_order(&tree, 0);
    r=add_in_order(&tree, -10);
    r=add_in_order(&tree, -5);
    
    printf("\nPre Order\n");
    r=Pre_Order(tree);

    printf("\nIn Order\n");
    r=In_Order(tree);

    printf("\nPost Order\n");
    r=Post_Order(tree);

    printf("\nLevel Order\n");
    r=Level_Order(tree);
    
    printf("\nPrint Depth\n");
    r=printDepth(tree);

    printf("\n\n");
    temp=Min(tree);
    printf("%d\n",temp->val);
    temp=Max(tree);
    printf("%d\n",temp->val);
    
    printf("\n\n");
    temp=searchTree(tree, 100);
    printf("%d\n",temp->val);
    temp=searchTree(tree, 789);
    if (temp == NULL)
    {
        printf("NULL\n");
    }    
    
    r=delete(&tree,-5);
    printf("\nDeteling node with val: -5\n");
    r=printDepth(tree);
    
    r=free_tree(tree);

    return 0;
}
