int bubblesort(int *A, int sizeA)
{   
    int swapped = 1;
    int i = 0;
    int temp = 0;
    
    /*if size is 1 or 0 then nothing will sort*/
    if ((sizeA == 0) || (sizeA == 1))
    {
        return -1;
    }
    /*checking if all values are defined for the size stated*/
    /*
    for(i=0;i<sizeA;i++)
    {
        if ((A[i] == NULL) && (A[i] != 0))
        {
            return -1;
        }
    }
    */
    while (swapped)
    {
        swapped = 0;
        for(i=1;i<sizeA;i++)
        {
            if (A[i-1] > A[i])
            {
                temp = A[i-1];
                A[i-1] = A[i];
                A[i] = temp;
                swapped = 1;
            }
        }
    }
    return 0;
}
