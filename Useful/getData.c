#include <stdio.h>

int main(void)
{
    int n = 0;
    int value = 0;
    /* EOF = end of file, 
        If entering data manutally: control D is how to indicate EOF in unix*/
    /*  If reading from another textfile
                cat input.txt | ./a.out    or   echo input.txt | ./a.ouy
     
        You can print the results to an output file by doing this
                cat input.txt | ./a.out > output.txt
    */
    while (scanf("%d",&value) != EOF)
    {
        n=n+1;
    }
    printf("INFO: you entered %d items\n",n);
    return 0;
}
