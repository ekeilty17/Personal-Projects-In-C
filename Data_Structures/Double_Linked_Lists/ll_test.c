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

    printf("List A\n");
    r=ll_add_to_tail(&A,100);
    r=ll_add_to_tail(&A,200);
    r=ll_add_to_tail(&A,300);
    for(i=0;i<10;i=i+1)
    {
        r=ll_add_to_tail(&A,i*100);
    }
    r=ll_print(A);

    printf("\nList B\n");
    r=ll_add_to_tail(&B,100);
    r=ll_add_to_tail(&B,200);
    r=ll_add_to_tail(&B,300);
    for(i=0;i<10;i=i+1)
    {
        r=ll_add_to_head(&B,i*100);
    }
    r=ll_print(B);
   

    /*making seq*/ 
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
    
    
    printf("\n\n\n\n\n\n\n\n\n");      

    /*printing seq list*/
    printf("\n\nSequenced List\n");
    r=ll_print(seq);
    
    /*testing ll_find_by_value*/
    printf("\n");
    r=ll_find_by_value(seq,700);
    printf("is 700 in seq? %d\n",r);
    r=ll_find_by_value(seq,701);
    printf("is 701 in seq? %d\n",r);
    
    /*testing ll_del_from_tail*/
    printf("\n\nseq with last 2 values deleted\n");
    r=ll_del_from_tail(&seq);
    r=ll_del_from_tail(&seq);
    r=ll_print(seq);
    
    
    /*testing ll_del_from_head*/
    printf("\n\nseq with first value deleted\n");
    r=ll_del_from_head(&seq);
    r=ll_print(seq);
    

    /*testing ll_del_by_value*/
    printf("\n\nseq with the value 400 deleted\n");
    r=ll_del_by_value(&seq,400);
    r=ll_print(seq);
    
    
    /*testing ll_insert_in_order*/
    printf("\n\nseq with a lot of things added in order\n");
    r=ll_insert_in_order(&seq,50);
    r=ll_insert_in_order(&seq,400);
    r=ll_insert_in_order(&seq,400);
    r=ll_insert_in_order(&seq,1000);
    r=ll_print(seq); 
   
    
    /*testing ll_concat*/
    printf("\n\nconcatinating A and B\n");
    r=ll_concat(&A,&B);
    r=ll_print(A);
    
    
    /*testing ll_sort*/
    printf("\n\nsorting a small list\n");
    
    r=ll_add_to_tail(&unordered,600);
    r=ll_add_to_tail(&unordered,200);
    r=ll_add_to_tail(&unordered,500);
    r=ll_add_to_tail(&unordered,300);
    
    printf("Before\n");
    r=ll_print(unordered);
    printf("\n\nAfter\n");
    r=ll_sort(&unordered);
    r=ll_print(unordered);
    
    printf("\n\nsorting the concatinated list\n");
    r=ll_sort(&A);
    r=ll_print(A);
    
    /*freeing shit*/
    r=ll_free(A);
    r=ll_free(B);
    r=ll_free(seq);
    r=ll_free(unordered);
    return 0;
}
