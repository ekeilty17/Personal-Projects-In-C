/* 1d */
int* matrix_statement(int *inp);
int matrix_allocated(int *inp, int *out, int sizeInp, int sizeout);
int matrix_unallocated(int *inp, int **out, int size);

/* 2d */
int** matrix3d_statement(int **inp);
int matrix3d_allocated(int **inp, int **out, int dimI1, int dimI2, int dimO1, int dimO2);
int matrix3d_unallocated(int **inp, int ***out, int dim1, int dim2);

/* 3d */
int*** matrix3d_statement(int ***inp);
int matrix3d_allocated(int ***inp, int ***out, int dimI1, int dimI2, int dimI3, int dimO1, int dimO2, int dimO3);
int matrix3d_unallocated(int ***inp, int ****out, int dim1, int dim2, int dim3);

/* 1d */
int* matrix_statement(int *inp)
{
    return inp;
}

int matrix_allocated(int *inp, int *out, int sizeInp, int sizeOut)
{
    int i = 0;
    if (inp == NULL)
    {
        return -1;
    }
    if (out == NULL)
    {
        return -1;
    }
    if (sizeInp != sizeOut)
    {
        return -1;
    }
    
    for(i=0;i<sizeInp;i++)
    {
        out[i] = inp[i];
    }
    return 0;
}

int matrix_unallocated(int *inp, int **out, int size)
{
    int i = 0;
    if (inp == NULL)
    {
        return -1;
    }
    if (out == NULL)
    {
        return -1;
    }
    
    *out = (int *)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
    {
        (*out)[i] = inp[i];
    }
    return 0;
}

/* 2d */
int** matrix2d_statement(int **inp)
{
    return inp;
}

int matrix2d_allocated(int **inp, int **out, int dimI1, int dimI2, int dimO1, int dimO2)
{
    int i,j;
    
    if (inp == NULL)
    {
        return -1;
    }
    if (*inp == NULL)
    {
        return -1;
    }
    if (out == NULL)
    {
        return -1;
    }
    if (*out == NULL)
    {
        return -1;
    }
    if (dimI1 != dimO1)
    {
        return -1;
    }
    if (dimI2 != dimO2)
    {
        return -1;
    }
    
    for(i=0; i<dimI1; i++)
    {
        for(j=0; j<dimI2; j++)
        {
            out[i][j] = inp[i][j];
        }
    }
    
    return 0;
}
int matrix2d_unallocated(int **inp, int ***out, int dim1, int dim2)
{
    int i,j;
    
    if (inp == NULL)
    {
        return -1;
    }
    if (*inp == NULL)
    {
        return -1;
    }
    if (out == NULL)
    {
        return -1;
    }
    
    *out = (int ***)malloc(sizeof(int**)*dim1);
    for(i=0; i<dim1; i++)
    {
        (*out)[i] = (int**)malloc(sizeof(int*)*dim2);
    }
    
    for(i=0; i<dim1; i++)
    {
        for(j=0; j<dim2; j++)
        {
            (*out)[i][j] = inp[i][j];
        }
    }
    return 0;
}


/* 3d */
int*** matrix3d_statement(int ***inp)
{
    return inp;
}

int matrix3d_allocated(int ***inp, int ***out, int dimI1, int dimI2, int dimI3, int dimO1, int dimO2, int dimO3)
{
    int i,j,k;
    
    if (inp == NULL)
    {
        return -1;
    }
    if (*inp == NULL)
    {
        return -1;
    }
    if (**inp == NULL)
    {
        return -1;
    }
    if (out == NULL)
    {
        return -1;
    }
    if (*out == NULL)
    {
        return -1;
    }
    if (**out == NULL)
    {
        return -1;
    }
    if (dimI1 != dimO1)
    {
        return -1;
    }
    if (dimI2 != dimO2)
    {
        return -1;
    }
    if (dimI3 != dimO3)
    {
        return -1;
    }
    
    for(i=0; i<dimI1; i++)
    {
        for(j=0; j<dimI2; j++)
        {
            for(k=0; k<dimI3; k++)
            {
                out[i][j][k] = inp[i][j][k];
            }
        }
    }
    
    return 0;
}
int matrix3d_unallocated(int ***inp, int ****out, int dim1, int dim2, int dim3)
{
    int i,j,k;
    
    if (inp == NULL)
    {
        return -1;
    }
    if (*inp == NULL)
    {
        return -1;
    }
    if (**inp == NULL)
    {
        return -1;
    }
    if (out == NULL)
    {
        return -1;
    }
    
    *out = (int ***)malloc(sizeof(int**)*dim1);
    for(i=0; i<dim1; i++)
    {
        (*out)[i] = (int**)malloc(sizeof(int*)*dim2);
        for(j=0; j<dim2; j++)
        {
            (*out)[i][j] = (int *)malloc(sizeof(int)*dim3);
        }
    }
    
    for(i=0; i<dim1; i++)
    {
        for(j=0; j<dim2; j++)
        {
            for(k=0; k<dim3; k++)
            {
                (*out)[i][j][k] = inp[i][j][k];
            }
        }
    }
    return 0;
}
