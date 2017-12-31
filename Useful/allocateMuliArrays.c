int allocate_1d(int **x, int size);
int allocate_2d(int ***x, int rows, int cols);
int allocate_3d(int ****x, int dim1, int dim2, int dim3);
int allocate_4d(int *****x, int dim1, int dim2, int dim3, int dim4);
int allocate_5d(int ******x, int dim1, int dim2, int dim3, int dim4, int dim5);

int allocate_1d(int **x, int size)
{
    int i;
    if (x == NULL)
    {
        return -1;
    }
    if (size <= 0)
    {
        return -1;
    }
    *x = (int *)malloc(sizeof(int)*size);
    return 0;
}

int allocate_2d(int ***x, int rows, int cols)
{
    int i,j;
    if (x == NULL)
    {
        return -1;
    }
    if (rows <= 0)
    {
        return -1;
    }
    if (cols <= 0)
    {
        return -1;
    }
    *x = (int **)malloc(sizeof(int*)*rows);
    for (i=0;i<rows;i++)
    {
        (*x)[i] = (int *)malloc(sizeof(int)*cols);
    }
    return 0;
}

int allocate_3d(int ****x, int dim1, int dim2, int dim3)
{
    int i,j,k;
    if (x == NULL)
    {
        return -1;
    }
    if (dim1 <= 0)
    {
        return -1;
    }
    if (dim2 <= 0)
    {
        return -1;
    }
    if (dim3 <= 0)
    {
        return -1;
    }
    *x = (int ***)malloc(sizeof(int**)*dim1);
    for (i=0;i<dim1;i++)
    {
        (*x)[i] = (int **)malloc(sizeof(int*)*dim2);
        for (j=0;j<dim2;j++)
        {
            (*x)[i][j] = (int *)malloc(sizeof(int)*dim3);
        }
    }
    return 0;
}

int allocate_4d(int *****x, int dim1, int dim2, int dim3, int dim4)
{
    int i,j,k;
    if (x == NULL)
    {
        return -1;
    }
    if (dim1 <= 0)
    {
        return -1;
    }
    if (dim2 <= 0)
    {
        return -1;
    }
    if (dim3 <= 0)
    {
        return -1;
    }
    if (dim4 <= 0)
    {
        return -1;
    }
    *x = (int ****)malloc(sizeof(int***)*dim1);
    for (i=0;i<dim1;i++)
    {
        (*x)[i] = (int ***)malloc(sizeof(int**)*dim2);
        for (j=0;j<dim2;j++)
        {
            (*x)[i][j] = (int **)malloc(sizeof(int*)*dim3);
            for (k=0;k<dim3;k++)
            {
                (*x)[i][j][k] = (int *)malloc(sizeof(int)*dim4);
            }
        }
    }
    return 0;
}

int allocate_5d(int ******x, int dim1, int dim2, int dim3, int dim4, int dim5)
{
    int i,j,k,l;
    if (x == NULL)
    {
        return -1;
    }
    if (dim1 <= 0)
    {
        return -1;
    }
    if (dim2 <= 0)
    {
        return -1;
    }
    if (dim3 <= 0)
    {
        return -1;
    }
    if (dim4 <= 0)
    {
        return -1;
    }
    if (dim5 <= 0)
    {
        return -1;
    }
    *x = (int *****)malloc(sizeof(int****)*dim1);
    for (i=0;i<dim1;i++)
    {
        (*x)[i] = (int ****)malloc(sizeof(int***)*dim2);
        for (j=0;j<dim2;j++)
        {
            (*x)[i][j] = (int ***)malloc(sizeof(int**)*dim3);
            for (k=0;k<dim3;k++)
            {
                (*x)[i][j][k] = (int **)malloc(sizeof(int*)*dim4);
                for (l=0;l<dim4;l++)
                {
                    (*x)[i][j][k][l] = (int *)malloc(sizeof(int)*dim5);
                }
            }
        }
    }
    return 0;
}
