int rotate(int *arg0, int *arg1, int *arg2);

int rotate(int *arg0, int *arg1, int *arg2)
{
    int temp;
    if (arg0 == NULL)
    {
        return -1;
    }
    if (arg1 == NULL)
    {
        return -1;
    }
    if (arg2 == NULL)
    {
        return -1;
    }
    temp = *arg2;
    *arg2 = *arg1;
    *arg1 = *arg0;
    *arg0 = temp;
    
    return 0;
}
