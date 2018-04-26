#include <stdio.h>
#include <stdlib.h>

int printc(char *c);
int length(char *c);
char* concat(char *a, char *b);
int concat2(char *a, char *b, char **out);
int find(char *string, char *part);

int printc(char *c)
{
    int i = 0;
    int size = 0;

    while(1)
    {
        if (c[i] == '\0')
        {
            break;
        }
        printf("%c",c[i]);
        i += 1;
        size += 1;
    }
    return size;
}

int length(char *c)
{
    int size = 0;
    while(1)
    {   
        if (c[size] == '\0')
        {   
            break;
        }
        size += 1;
    }
    return size;
}

char* concat(char *a, char *b)
{
    int i = 0;
    char *out = NULL;
    int sizeA = length(a);
    int sizeB = length(b);
    
    out = (char*)malloc(sizeof(char)*(sizeA + sizeB));
    for(i=0; i<sizeA; i++)
    {
        out[i] = a[i];
    }
    for(i=sizeA; i<sizeA+sizeB; i++)
    {
        out[i] = b[i-sizeA];
    }
    return out;
}

int concat2(char *a, char *b, char **out)
{
    int i = 0;
    int sizeA = length(a);
    int sizeB = length(b);
    char *c = NULL;

    if (out == NULL)
    {
        return -1;
    }
    
    c = (char*)malloc(sizeof(char)*(sizeA + sizeB));
    for(i=0; i<sizeA; i++)
    {
        c[i] = a[i];
    }
    for(i=sizeA; i<sizeA+sizeB; i++)
    {
        c[i] = b[i-sizeA];
    }
    
    *out = c;
    return 0;
}

int find(char *string, char *part)
{
    int lenS = length(string);
    int lenP = length(part);
    
    int i = 0;
    int counter = 0;
    for(i=0; i<lenS; i++)
    {
        if (string[i] == part[counter])
        {
            counter += 1;
        }
        else
        {
            counter = 0;
        }
        if (counter == lenP)
        {
            break;
        }
    }
    
    if (counter == lenP)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int i = 0;
    int r = 0;
    char a[12] = {'E','n','d','-','o','f','-','t','e','r','m','\0'};
    char b[5] = {'-','p','l','z','\0'};
    char *c = NULL;
    char d[5] = "hiii";

    r=printc(a);
    printf("\n");
    r=printc("this is fun, lol not really");
    printf("\n");
    r=printc(d);
    printf("\n%d\n",r);
    

    r=concat2("I am the this half", " I am the second half", &c);
    r=printc(c);
    printf("\n");
    
    return 0;
}
