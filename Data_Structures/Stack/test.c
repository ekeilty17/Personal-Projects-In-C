#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(void)
{
    int r = 0;
    int pval = 0;
    Stack s;
    
    r=init(&s);
    r=push(&s, 10);
    r=push(&s, 20);
    r=push(&s, 30);
    r=push(&s, 40);
    r=print_stack(s);
    
    printf("\n");
    r=pop(&s, &pval);
    r=print_stack(s);
    printf("\n");
    r=pop(&s, &pval);
    r=print_stack(s);
    printf("\n");
    r=pop(&s, &pval);
    r=print_stack(s);
    printf("\n");
    r=pop(&s, &pval);
    r=print_stack(s);
    printf("\n");
    r=pop(&s, &pval);
    r=print_stack(s);
    
    printf("\n");
    r=isEmpty(s, &pval);
    printf("isEmpty(s) = %d\n",pval);
    r=isFull(s, &pval);
    printf("isFull(s) = %d\n",pval);
    
    r=push(&s, 10);
    r=push(&s, 20);
    r=push(&s, 30);
    r=push(&s, 40);
    r=push(&s, 50);
    r=push(&s, 60);
    r=push(&s, 70);
    r=push(&s, 80);
    r=push(&s, 90);
    r=push(&s, 100);
    r=push(&s, 110); /*added one too many*/
    printf("\n");
    r=print_stack(s);

    printf("\n");
    r=isEmpty(s, &pval);
    printf("isEmpty(s) = %d\n",pval);
    r=isFull(s, &pval);
    printf("isFull(s) = %d\n",pval);
    
    r=free_stack(s);

    return 0;
}
