struct data {
    int key;
    char *val;
    struct data *next;  /*to deal with collisions*/
};
typedef struct data data;

struct HashTable {
    data **store;
    unsigned int max_size;
};
typedef struct HashTable HashTable;

int init(HashTable *H, int size)
{
    int i = 0;
    if (H == NULL)
    {
        return -1;
    }
    if (size <= 0)
    {
        return -1;
    }
    H->store = (data **)malloc(sizeof(data*)*size);
    for (i=0; i<size; i++)
    {
        H->store[i] = NULL;
    }
    H->max_size = size;
    return 0;
}

int string_to_num(char *s)
{
    int accum = 0;
    int i = 0;
    if (s == NULL)
    {
        return -1;
    }
    
    while(s[i] != '\0')
    {
        accum += strtol(s, NULL, 36) - 10;
        i += 1;
    }
    return accum;
}

int f(int x, int size)
{
    int out = x%size;
    if (out < 0)
    {
        return -out;
    }
    else
    {
        return out;
    }
}

int insert_into_array(data **head, int key, char *val)
{
    if (head == NULL)
    {
        return -1;
    }
    if (*head == NULL)
    {
        *head = (data *)malloc(sizeof(data));
        (*head)->key = key;
        (*head)->val = val;
        (*head)->next = NULL;
        return 0;
    }
    else
    {
        return insert_into_array(&((*head)->next),key,val);
    }
}
int add(HashTable *H, char *val)
{
    int r = 0;
    int key = 0;
    int index = 0;
    if (H == NULL)
    {
        return -1;
    }
    /*adding to Hash Table*/
    key = string_to_num(val);
    index = f(key, H->max_size);
    r=insert_into_array(&(H->store[index]),key,val);
    return 0;
}

int ll_print_from_head(data *p)
{   
    int i = 0;
    if (p==NULL)
    {   
        return 0;
    }
    while(p->val[i] != '\0')
    {
        printf("%c",p->val[i]);
        i += 1;
    }
    printf("\t\t");
    return ll_print_from_head(p->next);
}
int printTable(HashTable *H)
{
    int r = 0;
    int i = 0;
    if (H == NULL)
    {
        return -1;
    }
    for(i=0; i<H->max_size; i++)
    {
        if (H->store[i] == NULL)
        {
            printf("-\n");
        }
        else
        {
            r=ll_print_from_head(H->store[i]);
            printf("\n");
        }
    }
    return 0;
}
