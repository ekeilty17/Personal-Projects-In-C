#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /*you can specify signed int, but things are signed by default*/
    printf("SIZE OF TYPES\n");
    printf("sizeof(void) = \t\t\t\t%d\n",sizeof(void));
    printf("sizeof(int) = \t\t\t\t%d\n",sizeof(int));
    printf("sizeof(unsigned int) = \t\t\t%d\n",sizeof(unsigned int));
    printf("sizeof(short int) = \t\t\t%d\n",sizeof(short int));
    printf("sizeof(unsigned short int) = \t\t%d\n",sizeof(unsigned short int));
    printf("sizeof(long int) = \t\t\t%d\n",sizeof(long int));
    printf("sizeof(unsigned long int) = \t\t%d\n",sizeof(unsigned long int));
    /*printf("sizeof(long long int) = \t\t%d\n",sizeof(long long int));*/
    /*printf("sizeof(unsigned long long int) = \t%d\n",sizeof(unsigned long long int));*/
    printf("sizeof(char) = \t\t\t\t%d\n",sizeof(char));
    printf("sizeof(unsigned char) = \t\t%d\n",sizeof(unsigned char));
    printf("sizeof(float) = \t\t\t%d\n",sizeof(float));
    printf("sizeof(double) = \t\t\t%d\n",sizeof(double));
    printf("sizeof(long double) = \t\t\t%d\n",sizeof(long double));

    printf("\n");

    /*the reason signed ints are commented out is becuase ints are signed by default*/
    /*so C didn't waste time defining that as a datatype*/
    /*I'm pretty sure the reason there is a signed char is because if you dont specify*/
    /*char can be set as unsignd, not really sure tho*/
    printf("RANGE OF TYPES\n");
    /*printf("Range of void=%d to %d\n",VOID_MIN,VOID_MAX);*/
    printf("Range of int = \t\t\t\t%d to %d\n",INT_MIN,INT_MAX);
    /*printf("Range of signed int = %d to %d\n",(signed int) SINT_MIN, (signed int) SINT_MAX);*/
    printf("Range of unsigned int = \t\t%d to %u\n",0,(unsigned int) UINT_MAX);
    
    printf("Range of short int = \t\t\t%d to %d\n",SHRT_MIN,SHRT_MAX);
    /*printf("Range of signed short int = %d to %d\n",(signed short) SSHRT_MIN, (signed short) SSHRT_MAX);*/
    printf("Range of unsigned short int = \t\t%d to %u\n",0,(unsigned short) USHRT_MAX);
    
    printf("Range of long int = \t\t\t%ld to %ld\n",(long) LONG_MIN,(long) LONG_MAX);
    /*printf("Range of signed long int = %ld to %ld\n",(signed long) SLONG_MIN, (signed long) SLONG_MAX);*/
    printf("Range of unsigned long int = \t\t%d to %lu\n",0,(unsigned long) ULONG_MAX);
    
    /*printf("Range of long long int = \t\t%lld to %lld\n",(long long) LLONG_MIN,(long long) LLONG_MAX);*/
    /*printf("Range of signed long long int = %ld to %ld\n",(signed long long) SLLONG_MIN,(signed long long) SLLONG_MAX);*/
    /*printf("Range of unsigned long long int = \t%d to %llu\n",0,(unsigned long long) ULLONG_MAX);*/
    
    printf("Range of char = \t\t\t%d to %d\n",CHAR_MIN,CHAR_MAX);
    printf("Range of signed char = \t\t\t%d to %d\n",SCHAR_MIN,SCHAR_MAX);
    printf("Range of unsigned char = \t\t%d to %d\n",0,UCHAR_MAX);
    
    printf("Range of float = \t\t\t%g to %g\tPrecise to 6 decimal places\n",(float) FLT_MIN,(float) FLT_MAX);
    printf("Range of double = \t\t\t%g to %g\tPrecise to 15 decimal places\n",(double) DBL_MIN, (double) DBL_MAX);
    printf("Range of long double = \t\t\t3.4e-4932 to 1.1e+4932\t\tPrecise to 19 decimal places\n");
    
    return 0;
}
