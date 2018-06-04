#include <stdio.h>
#include <stdlib.h>
#include "ll.c"

int main(void) 
{
    llnode *A = NULL;
    llnode *B = NULL;
    llnode *seq = NULL;
    llnode *unordered = NULL;
    llnode *temp = NULL;
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
    r=ll_add_to_tail(&B,100);
    r=ll_add_to_tail(&B,200);
    r=ll_add_to_tail(&B,300);
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
    
    //testing ll_find_by_value
    printf("\n");
    r=ll_find_by_value(seq,700);
    printf("is 700 in seq? %d\n",r);
    r=ll_find_by_value(seq,701);
    printf("is 701 in seq? %d\n",r);
    
    //testing ll_del_from_tail
    printf("\n\nseq with last 2 values deleted\n");
    r=ll_del_from_tail(&seq);
    r=ll_del_from_tail(&seq);
    r=ll_print_from_head(seq);
    
    
    //testing ll_del_from_head
    printf("\n\nseq with first value deleted\n");
    r=ll_del_from_head(&seq);
    r=ll_print_from_head(seq);
    

    //testing ll_del_by_value
    printf("\n\nseq with the value 400 deleted\n");
    r=ll_delete(&seq,400);
    r=ll_print_from_head(seq);
    
    
    //testing ll_insert_in_order
    printf("\n\nseq with a lot of things added in order\n");
    r=ll_insert_in_order(&seq,50);
    r=ll_insert_in_order(&seq,400);
    r=ll_insert_in_order(&seq,400);
    r=ll_insert_in_order(&seq,1000);
    r=ll_print_from_head(seq);
   
    
    //testing ll_concat
    printf("\n\nconcatinating A and B\n");
    r=ll_concat(&A,&B);
    r=ll_print_from_head(A);
    
    
    //testing ll_sort
    printf("\n\nsorting a small list\n");
    
    r=ll_add_to_tail(&unordered,600);
    r=ll_add_to_tail(&unordered,200);
    r=ll_add_to_tail(&unordered,500);
    r=ll_add_to_tail(&unordered,300);
    
    printf("Before\n");
    r=ll_print_from_head(unordered);
    printf("\n\nAfter\n");
    r=ll_sort(&unordered);
    r=ll_print_from_head(unordered);
    
    printf("\n\nsorting the concatinated list\n");
    r=ll_sort(&A);
    r=ll_print_from_head(A);
   
    //testing ll_index and ll_length
    printf("\n\nindexing seq from 0 to 14\n");
    r=ll_print_from_head(seq);
    printf("\n");
    l=ll_length(seq);
    printf("length of seq = %d\n",l);
    for(i=0; i<l; i++)
    {
        r=ll_index(seq,i);
        printf("seq at index %d = %d\n",i,r);
    }
    
    //testing ll_parent
    printf("\n\nfinding the parent nodes\n");
    temp = ll_parent(seq, seq);
    if (temp == NULL)
    {
        printf("parent of %d = NULL\n", seq->val);
    }
    else
    {
        printf("parent of %d = %d\n", seq->val, temp->val);
    }
    temp = ll_parent(seq, seq->next->next);
    if (temp == NULL)
    {
        printf("parent of %d = NULL\n", seq->val);
    }
    else
    {
        printf("parent of %d = %d\n", seq->next->next->val, temp->val);
    }
    
    //reversing the order of the linked list
    printf("\n\nreversing the order of seq\n");
    r=ll_reverse(&seq);
    r=ll_print_from_head(seq);

    //freeing shit
    r=ll_free(A);
    //since we concatinated A with B, B was already freed
    r=ll_free(seq);
    r=ll_free(unordered);
    return 0;
}
