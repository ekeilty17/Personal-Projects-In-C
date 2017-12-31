int swap (int *a, int *b);

int swap (int *a, int *b)
{
    int c;
    if (a == NULL)
    {
        return -1;
    }
    if (b == NULL)
    {
        return -1;
    }
    c = *a;
    *a = *b;
    *b = c;
    
    return 0;
}
