/*this will be a max heap*/
/*this will also be a linked list implementation, 
  even though I realize the array implementation is better*/

struct Heap {
    int val;
    struct Heap *left;
    struct Heap *right;
};
typedef struct Heap Heap;

/*add nodes so that parent is always greater than the child*/
int add(Heap **root, int val)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }

    if (*root == NULL)
    {
        *root = (Heap *)malloc(sizeof(Heap));
        (*root)->left = NULL;
        (*root)->val = val;
        (*root)->right = NULL;
        return 0;
    }
    else
    {
        if (((*root)->left != NULL) && ((*root)->right) != NULL)
        {
            r=add(&((*root)->left));

    }
}
