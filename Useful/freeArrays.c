int free2d(int **a, int dim1, int dim2);
int free3d(int ***a, int dim1, int dim2, int dim3);
int free4d(int ****a, int dim1, int dim2, int dim3, int dim4);
int free5d(int *****a, int dim1, int dim2, int dim3, int dim4, int dim5);

/*if you define a 1d array like this
 int a[10];
 then you don't need to free it
 if you defined it like this
 int *a = NULL;
 then you free it like this
 free(a)
 */

int free2d(int ***a, int dim1, int dim2)
{
    int i = 0;
    int j = 0;
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
    for(i=0; i<dim1; i++)
    {
        free(a[i]);
    }
    free(a);
    return 0;
}

int free3d(int ***a, int dim1, int dim2, int dim3)
{
    int i = 0;
    int j = 0;
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
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
    return 0;
}

int free4d(int ****a, int dim1, int dim2, int dim3, int dim4)
{
    int i,j,k,l;
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
    if (***a == NULL)
    {
        return -1;
    }
    if (****a == NULL)
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
    for (i=0;i<dim1;i++)
    {
        for (j=0;j<dim2;j++)
        {
            for (k=0;k<dim3;k++)
            {
                free(a[i][j][k]);
            }
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
}

int free5d(int *****a, int dim1, int dim2, int dim3, int dim4, int dim5)
{
    int i,j,k,l;
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
    if (***a == NULL)
    {
        return -1;
    }
    if (****a == NULL)
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
    for (i=0;i<dim1;i++)
    {
        for (j=0;j<dim2;j++)
        {
            for (k=0;k<dim3;k++)
            {
                for (l=0;l<dim4;l++)
                {
                    free(a[i][j][k][l]);
                }
                free(a[i][j][k]);
            }
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
}
/* I know I don't need the last dim in the arg list, but idk for some reason I feel like it should be there */
