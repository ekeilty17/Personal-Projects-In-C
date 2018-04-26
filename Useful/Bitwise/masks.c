#include <stdio.h>
#include "print_bits.c"

int range_error(int from, int to)
{
    if ((from < 0) || (from > 31))
    {
        return -1;
    }
    if ((to < 0) || (to > 31))
    {
        return -1;
    }
    if (from > to)
    {
        return -1;
    }
    return 0;
}

//will return 1's everywhere except for bits from --> to
unsigned int range_zeros(int from, int to)
{
    unsigned int out = 0x0;
    int i = 0;
    //error will be all 1's
    i = range_error(from, to);
    if (i == -1)
    {
        return ~0x0;
    }

    for (i=from; i<=to; i++)
    {
        out = out | (0x1 << i);
    }
    return ~out;
}

//will return 1's only in bits from --> to
unsigned int range_ones(int from, int to)
{
    unsigned int out = 0x0;
    int i = 0;
    //error will be all 0's
    i = range_error(from, to);
    if (i == -1)
    {
        return 0x0;
    }
    
    for (i=from; i<=to; i++)
    {
        out = out | (0x1 << i);
    }
    return out;
}

unsigned int clear(unsigned int x, int from, int to)
{
    unsigned int mask = 0x0;
    int r = 0;
    r = range_error(from, to);
    if (r == -1)
    {
        return x;
    }
    mask = range_zeros(from, to);
    return x & mask;
}

unsigned int extract(unsigned int x, int from, int to)
{
    unsigned int mask = 0x0;
    int r = 0;
    r = range_error(from, to);
    if (r == -1)
    {
        return x;
    }
    mask = range_ones(0, to-from);
    return (x >> from) & mask;
}

unsigned int flip(unsigned int x, int from, int to)
{
    unsigned int mask = 0x0;
    int r = 0;
    r = range_error(from, to);
    if (r == -1)
    {
        return x;
    }
    mask = range_ones(from, to);
    return x ^ mask;
}

unsigned int index(unsigned int x, int idx)
{
    if ((idx < 0) || (idx > 31))
    {
        return -1;
    }
    return (x >> idx) & 0x1;
}

unsigned int rot(unsigned int x, int n)
{
    unsigned int rot_bit = 0x0;
    int i = 0;
    if (n < 0)
    {
        for(i=0; i<-n; i++)
        {
            rot_bit = (x >> 31) & 0x1;
            x = x << 1;
            x = x | rot_bit;
        }
    }
    else if (n > 0)
    {
        for(i=0; i<n; i++)
        {
            rot_bit = (x & 0x1) << 31;
            x = x >> 1;
            x = x | rot_bit;
        }
    }
    return x;
}

int main(void)
{
    unsigned int out = 0xabcd;
    
    print_int(out);
    out = rot(out, 3);
    print_int(out);
    out = rot(out, -4);
    print_int(out);
    
    
    return 0;
}
