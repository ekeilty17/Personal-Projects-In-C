struct dict {
    char *key;
    char *def;
    struct dict *prev;
    struct dict *next;
};
typedef struct dict dict;

int s_print(char *a)
{
    int i = 0;
    if (a == NULL)
    {
        return -1;
    }
    while (a[i] != '\0')
    {
        printf("%c",a[i]);
        i += 1;
    }
    return 0;
}

int length(char *a)
{
    int i = 0;
    if (a == NULL)
    {
        return -1;
    }
    while (a[i] != '\0')
    {
        i += 1;
    }
    return i;
}

int str_equ(char *a, char *b)
{
    int i = 0;
    int equal = 1;
    if (a == NULL)
    {
        return -1;
    }
    if (b == NULL)
    {
        return -1;
    }
    while (equal)
    {
        if (a[i] != b[i])
        {
            equal = 0;
        }
        if ((a[i] == '\0') || (b[i] == '\0'))
        {
            break;
        }
        i += 1;
    }
    return equal-1;
}

int add_to_head(dict **d, char *key, char *def)
{
    struct dict *old_d = NULL;
    if (d == NULL)
    {
        return -1;
    }
    old_d = *d;

    *d = (dict *) malloc(sizeof(dict));
    (*d)->key = key;
    (*d)->def = def;
    (*d)->next = old_d;
    return 0;
}

int add_to_tail(dict **d, char *key, char *def)
{
    if (d == NULL)
    {
        return -1;
    }
    if (*d == NULL)
    {
        *d = (dict *) malloc(sizeof(dict));
        (*d)->key = key;
        (*d)->def = def;
        (*d)->next = NULL;
        return 0;
    }
    else
    {
        return add_to_tail(&((*d)->next), key, def);
    }
}

int d_print(dict *d)
{
    if (d == NULL)
    {
        return 0;
    }
    s_print(d->key);
    printf(": ");
    s_print(d->def);
    printf("\n");
    return d_print(d->next);
}

int free_dict(dict *d)
{
    if ( d == NULL)
    {
        return -1;
    }
    else
    {
        dict *f = d->next;
        free(d);
        return free_dict(f);
    }
}

int search(dict *d, char *key)
{
    if (d == NULL)
    {
        return -1;
    }
    if (key == NULL)
    {
        return -1;
    }
    if (str_equ(d->key,key) == 0)
    {
        return 0;
    }
    else
    {
        return search(d->next,key);
    }
}

int delete(dict **d, char *key)
{
    struct dict *temp = NULL;
    if (d == NULL)
    {
        return -1;
    }
    if (key == NULL)
    {
        return -1;
    }
    if (str_equ((*d)->key,key) == 0)
    {
        temp = *d;
        *d = temp->next;
        free(temp);
        return 0;
    }
    else
    {
        return delete(&((*d)->next), key);
    }
}

int char_val(char c)
{
    if ((c == 'a') || (c == 'A')) {return 1;}
    else if ((c == 'b') || (c == 'B')) {return 2;}
    else if ((c == 'c') || (c == 'C')) {return 3;}
    else if ((c == 'd') || (c == 'D')) {return 4;}
    else if ((c == 'e') || (c == 'E')) {return 5;}
    else if ((c == 'f') || (c == 'F')) {return 6;}
    else if ((c == 'g') || (c == 'G')) {return 7;}
    else if ((c == 'h') || (c == 'H')) {return 8;}
    else if ((c == 'i') || (c == 'I')) {return 9;}
    else if ((c == 'j') || (c == 'J')) {return 10;}
    else if ((c == 'k') || (c == 'K')) {return 11;}
    else if ((c == 'l') || (c == 'L')) {return 12;}
    else if ((c == 'm') || (c == 'M')) {return 12;}
    else if ((c == 'n') || (c == 'N')) {return 14;}
    else if ((c == 'o') || (c == 'O')) {return 15;}
    else if ((c == 'p') || (c == 'P')) {return 16;}
    else if ((c == 'q') || (c == 'Q')) {return 17;}
    else if ((c == 'r') || (c == 'R')) {return 18;}
    else if ((c == 's') || (c == 'S')) {return 19;}
    else if ((c == 't') || (c == 'T')) {return 20;}
    else if ((c == 'u') || (c == 'U')) {return 21;}
    else if ((c == 'v') || (c == 'V')) {return 22;}
    else if ((c == 'w') || (c == 'W')) {return 23;}
    else if ((c == 'x') || (c == 'X')) {return 24;}
    else if ((c == 'y') || (c == 'Y')) {return 25;}
    else if ((c == 'z') || (c == 'Z')) {return 26;}
    else {return -1;}
}

int alphabetical(char *a, char *b)
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
    /*go through the list until we find a char that differs*/
    /*here's a nice subtlety
      putting && instead of || in the while loop accounts for cases such as
      car vs carpet
      */
    while ((a[i] != '\0') && (b[i] != '\0'))
    {
        if (char_val(a[i]) == char_val(b[i]))
        {
            i += 1;
        }
        else
        {
            break;
        }
    }
    /*this returns which char should go later*/
    if (char_val(a[i]) > char_val(b[i]))
    {
        return 1;
    }
    else if (char_val(a[i]) < char_val(b[i]))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int add_in_order(dict **d, char *key, char *def)
{
    dict *prev = NULL;
    dict *curr = NULL;
    
    if (d == NULL)
    {
        return -1;
    }
    if (key == NULL)
    {
        return -1;
    }
    if (def == NULL)
    {
        return -1;
    }
    if (*d == NULL)
    {
        return add_to_head(d,key,def);
    }
    if (alphabetical(((*d)->key), key) == 1)
    {
        return add_to_head(d,key,def);
    }
    else if (alphabetical(((*d)->key), key) == 0)
    {
        /*already have this entry*/
        return 0;
    }
    else
    {
        prev = *d;
        curr = (*d)->next;
        while(curr != NULL)
        {
            if (alphabetical((curr->key), key) == 1)
            {
                break;
            }
            else
            {
                prev = curr;
                curr = prev->next;
            }
        }
        prev->next = (dict *) malloc(sizeof(dict));
        prev->next->key = key;
        prev->next->def = def;
        prev->next->next = curr;
        return 0;
    }
}
