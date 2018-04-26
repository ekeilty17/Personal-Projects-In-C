#include <stdio.h>
//*************************** 8-bit Unsigned chars *************************

unsigned long convBin_char(unsigned char x)
{
    int n = (int)x;
    int remainder = 0;
    unsigned long binary = 0;
    int i = 1;
    while(n != 0)
    {
        remainder = n%2;
        n = n/2;
        binary += remainder*i;
        i = i*10;
    }
    return binary;
}

void add_zeros_4(unsigned long byte)
{
    if (byte <= 111)
    {
        printf("0");
    }
    if (byte <= 11)
    {
        printf("0");
    }
    if (byte <= 1)
    {
        printf("0");
    }
}

//0 to 255, which is 8 bits (or 2 bytes). That means max is 0xff
void print_char(unsigned char x)
{
    unsigned char x0_3 = (x >>  0) & 0x0F;
    unsigned char x4_7 = (x >>  4) & 0x0F;

    unsigned long byte1 = convBin_char(x0_3);
    unsigned long byte2 = convBin_char(x4_7);
    
    add_zeros_4(byte2);
    printf("%ld  ",byte2);
    add_zeros_4(byte1);
    printf("%ld\n",byte1);
}

void print_char_full(unsigned char x)
{
    printf("   Char: \t%c\n",x);
    printf("    Hex: \t%x\n",x);
    printf(" Binary: \t");
    print_char(x);
}

//*************************** 32-bit Unsigned Ints *************************

unsigned long convBin_int(unsigned int x)
{
    int n = x;
    int remainder = 0;
    unsigned long binary = 0;
    int i = 1;
    while(n != 0)
    {
        remainder = n%2;
        n = n/2;
        binary += remainder*i;
        i = i*10;
    }
    return binary;
}

void add_zeros_8(unsigned long nyb)
{
    if (nyb <= 1111111)
    {
        printf("0");
    }
    if (nyb <= 111111)
    {
        printf("0");
    }
    if (nyb <= 11111)
    {
        printf("0");
    }
    if (nyb <= 1111)
    {
        printf("0");
    }
    if (nyb <= 111)
    {
        printf("0");
    }
    if (nyb <= 11)
    {
        printf("0");
    }
    if (nyb <= 1)
    {
        printf("0");
    }
}


//0 to 4 billion, which is 32 bits (or 8 bytes). That means max is 0xffffffff
void print_int(unsigned int x)
{
    //ints are too long bc they are 32 bits, so I need to break up the integer
    //splitting x up into it's nybbles
    unsigned char x00_07 = (x >>  0) & 0x000000FF;
    unsigned char x08_15 = (x >>  8) & 0x000000FF; 
    unsigned char x16_23 = (x >> 16) & 0x000000FF;
    unsigned char x24_31 = (x >> 24) & 0x000000FF;
    
    unsigned long nyb1 = convBin_int(x00_07);
    unsigned long nyb2 = convBin_int(x08_15);
    unsigned long nyb3 = convBin_int(x16_23);
    unsigned long nyb4 = convBin_int(x24_31);
    
    //This is all to make the output look nice
    add_zeros_8(nyb4);
    printf("%ld  ",nyb4);
    add_zeros_8(nyb3);
    printf("%ld  ",nyb3);
    add_zeros_8(nyb2);
    printf("%ld  ",nyb2);
    add_zeros_8(nyb1);
    printf("%ld\n",nyb1);
}

void print_int_full(unsigned int x)
{
    printf("Decimal: \t%d\n",x);
    printf("    Hex: \t%x\n",x);
    printf(" Binary: \t");
    print_int(x);
}

int main(void)
{
    unsigned int x = 0x12abcdef;
    unsigned char c = 0x64;

    print_int_full(x);
    printf("\n");
    print_char_full(c);
    return 0;
}
