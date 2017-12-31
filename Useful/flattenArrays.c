int flattened_2d(int *a, int rows, int cols, int x, int y);
int flattened_3d(int *a, int dim1, int dim2, int dim3, int x, int y, int z);

int flattened_2d(int *a, int rows, int cols, int x, int y)
{
    if (a == NULL)
    {
        return -1;
    }
    if ((x < 0) || (x >= rows))
    {
        return -1;
    }
    if ((y < 0) || (y >= cols))
    {
        return -1;
    }
    return a[x + y*row]; /*a[x*cols + y] is also valid*/
}

int flattened_3d(int *a, int dim1, int dim2, int dim3, int x, int y, int z)
{
    if (a == NULL)
    {
        return -1;
    }
    if ((x < 0) || (x >= dim1))
    {
        return -1;
    }
    if ((y < 0) || (y >= dim2))
    {
        return -1;
    }
    if ((z < 0) || (z >= dim3))
    {
        return -1;
    }
    return a[x + y*dim1 + z*dim1*dim2]; /*there are many different valid ways to do this*/
}
