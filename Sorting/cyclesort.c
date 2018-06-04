/*O(n) = n^2*/
#include <stdio.h>
#include <stdlib.h>

int cyclesort(int *A, int sizeA)
{
    int i = 0;
    int *visited = (int *)malloc(sizeof(int)*sizeA);
    int all_visited = 0;
    int start = 0;
    int greater = 0;
    int temp = 0;
    
    //Error Checks
    if (A == NULL)
    {
        return -1;
    }
    if (sizeA <= 1)
    {
        return -1;
    }
    
    //initalize visited to all False
    visited[start] = 1;
    for (i=1; i<sizeA; i++)
    {
        visited[i] = 0;
    }
    
    while (!all_visited)
    {
        // We are always swapping with the start index, 
        //      the start index acts as our place-holder until eventually the correct elements gets placed there
        // Once the value in the start index is in the correct place, we have to find a new start
        //      Hence the visited array
        // If all nodes are visited then we are done
        
        // count the number of elements than A[start] is greater than 
        // and that will be the correct index of A[start]
        greater = 0;
        for (i=0; i<sizeA; i++)
        {
            //                  change    V        for a descending list
            if ((i != start) && (A[start] > A[i]))
            {
               greater += 1;
            }
        }
        
        if (greater != start)
        {
            // This is to deal with the case of repeated numbers in the list
            while (A[greater] == A[start])
            {
                greater += 1;
            }
            // swapping start with the element in the correct position
            temp = A[greater];
            A[greater] = A[start];
            A[start] = temp;
            // update visited array
            visited[greater] = 1;
        }
        else
        {
            // if greater == start 
            // then we've reached the end of a subcycle and we need to find a new one
            all_visited = 1;
            for (i=0; i<sizeA; i++)
            {
                if (visited[i] == 0)
                {
                    start = i;
                    visited[start] = 1;
                    all_visited = 0;
                    break;
                }
            }
            // if we get to the end of the for loop and a new start has not been found
            // then all_visited will be True and the while loop will break
        }
    }
    return 0;
}

int main(void)
{
    int i = 0;
    int r = 0;
    int n = 10;
    int x[10] = {0, -1, 100, 50, 12, -234, 43, 345, -2, 0};

    printf("Original List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    r=cyclesort(x,n);
    printf("Sorted List\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n\n");

    return 0;
}
