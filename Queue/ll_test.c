#include <stdio.h>
#include <stdlib.h>
#include "ll_queue.c"

int main(void)
{
    int r = 0;
    int pval = 0;
    Queue *q = NULL;
    
    r=enq(&q, 10);
    r=enq(&q, 20);
    r=enq(&q, 30);
    r=enq(&q, 40);
    r=print_queue(q);
    
    printf("\n");
    r=deq(&q, &pval);
    r=print_queue(q);
    printf("\n");
    r=deq(&q, &pval);
    r=print_queue(q);
    printf("\n");
    r=deq(&q, &pval);
    r=print_queue(q);
    printf("\n");
    r=deq(&q, &pval);
    r=print_queue(q);
    printf("\n");
    r=deq(&q, &pval);
    r=print_queue(q);
    
    printf("\n");
    r=isEmpty(q, &pval);
    printf("isEmpty(s) = %d\n",pval);
    
    r=enq(&q, 10);
    r=enq(&q, 20);
    r=enq(&q, 30);
    r=enq(&q, 40);
    r=enq(&q, 50);
    r=enq(&q, 60);
    r=enq(&q, 70);
    r=enq(&q, 80);
    r=enq(&q, 90);
    r=enq(&q, 100);
    r=enq(&q, 110);
    printf("\n");
    r=print_queue(q);

    printf("\n");
    r=isEmpty(q, &pval);
    printf("isEmpty(s) = %d\n",pval);
    
    r=free_queue(q);

    return 0;
}
