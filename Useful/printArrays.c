int print1d(int *a, int size);
/* there are two ways to handle multidimensional arrays in C */
/* index a 1d array as if it is multidimensional */
int print1d_2d(int *a, int rows, int cols);
int print1d_3d(int *a, int dim1, int dim2, int dim3);
/* actually malloc a multidimensional array */
int print2d(int **a, int rows, int cols);
int print3d(int ***a, int dim1, int dim2, int dim3);

int print1d(int *a, int size)
{
    int i;
    if (a == NULL)
    {
        return -1;
    }
    if (size <= 0)
    {
        return -1;
    }
    for(i=0; i<size; i++)
    {
        printf("%3d\n",a[i]);
    }
    return 0;
}


int print1d_2d(int *a, int rows, int cols)
{
    int i;
    int j;
    if (a == NULL)
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
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("%3d ",a[i + j*rows]);
        }
        printf("\n");
    }
    return 0;
}

int print1d_3d(int *a, int dim1, int dim2, int dim3)
{
    int i;
    int j;
    int k;
    if (a == NULL)
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
    for(i=0; i<dim1; i++)
    {
        for(j=0; j<dim2; j++)
        {
            for(k=0; k<dim3; k++)
            {
                printf("%3d ",a[i + j*dim1 + k*dim1*dim3]);
            }
        }
        printf("\n");
    }
    return 0;
}

int print2d(int **a, int rows, int cols)
{
    int i;
    int j;
    int k;
    if (a == NULL)
    {
        return -1;
    }
    if (*a == NULL)
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
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int print3d(int ***a, int dim1, int dim2, int dim3)
{
    int i;
    int j;
    int k;
    if (a == NULL)
    {
        return -1;
    }
    if (*a == NULL)
    {
        return -1;
    }
    if (**a == NULL)
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
    for(i=0; i<dim1; i++)
    {
        for(j=0; j<dim2; j++)
        {
            for(k=0; k<dim3; k++)
            {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
