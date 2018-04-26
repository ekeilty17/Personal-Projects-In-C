#include <stdio.h>
#include <stdlib.h>
#include "hash.c"

int equal(char *a, char *b)
{
    int i = 0;
    if (a == NULL)
    {
        return -1;
    }
    if (b == NULL)
    {
        return -1;
    }
    while (1)
    {
        if ((a[i] == '\0') && (b[i] == '\0'))
        {
            return 0;
        }
        if (a[i] != b[i])
        {
            return -1;
        }
        i += 1;
    }
}

int main(void)
{
    int r = 0;
    char username[64];
    char password[64];
    HashTable H;

    r=init(&H, 5);
    
    printf("Enter Account Names\n");
    while(1)
    {
        printf("Username: ");
        scanf("%s", username);
        r=equal(username, "done");
        if (r == 0)
        {
            break;
        }
        printf("password: ");
        scanf("%s", password);
        /*
        printf("Username: ");
        if (scanf("%s", username) == EOF)
        {
            break;
        }
        printf("password: ");
        if (scanf("%s", password) == EOF)
        {
            break;
        }
        */
        printf("\n");
        r=add(&H,username,password);
    }
    r=printTable(&H);
    
    printf("\n");
    printf("Login\n");
    while(1)
    { 
        printf("Username: ");
        scanf("%s", username);
        printf("password: ");
        scanf("%s", password);
        /*
        if (scanf("%s", username) == EOF)
        {
            break;
        }
        printf("password: ");
        if (scanf("%s", password) == EOF)
        {
            break;
        }
        printf("\n");
        */
        r=find(&H,username,password);
        if (r == 0)
        {
            printf("\nLogin Success\n\n");
            break;
        }
        else
        {
            printf("\nIncorrect Username or Password\n");
        }
        printf("\n");
    }
    return 0;
}
