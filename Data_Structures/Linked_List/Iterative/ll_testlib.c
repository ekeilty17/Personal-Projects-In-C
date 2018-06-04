#include <stdio.h>
#include <stdlib.h>
#include "ll.c"

int main(void)
{
    llnode *A = NULL;
    llnode *B = NULL;
    llnode *seq = NULL;
    llnode *unordered = NULL;
    int r=0;
    int i=0;
    int l=0;

    printf("List A\n");
    r=ll_add_to_tail(&A,100);
    r=ll_add_to_tail(&A,200);
    r=ll_add_to_tail(&A,300);
    for(i=0;i<10;i=i+1)
    {
        r=ll_add_to_tail(&A,i*100);
    }
    r=ll_print_from_head(A);

    printf("\nList B\n");
    //r=ll_add_to_tail(&B,100);
    //r=ll_add_to_tail(&B,200);
    //r=ll_add_to_tail(&B,300);
    for(i=0;i<10;i=i+1)
    {
        r=ll_add_to_head(&B,i*100);
    }
    r=ll_print_from_head(B);
    r=ll_add_to_tail(&seq,100);
    r=ll_add_to_tail(&seq,200);
    r=ll_add_to_tail(&seq,300);
    r=ll_add_to_tail(&seq,400);
    r=ll_add_to_tail(&seq,500);
    r=ll_add_to_tail(&seq,600);
    r=ll_add_to_tail(&seq,700);
    r=ll_add_to_tail(&seq,800);
    r=ll_add_to_tail(&seq,900);
    r=ll_add_to_tail(&seq,1000);

    //printing seq list
    printf("\n\nSequenced List\n");
    r=ll_print_from_head(seq);
    
    return 0;
}
