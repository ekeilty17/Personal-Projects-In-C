struct Data {
    int key;
    char *username;
    struct Data *next;  /*to deal with collisions*/
};
typedef struct Data Data;

struct HashTable {
    Data **store;
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
    H->store = (Data **)malloc(sizeof(Data*)*size);
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

int insert_into_array(Data **head, int key, char *username)
{
    int i = 0;
    if (head == NULL)
    {
        return -1;
    }
    if (*head == NULL)
    {
        *head = (Data *)malloc(sizeof(Data));
        (*head)->key = key;
        (*head)->next = NULL;
        /*need to uncouple the pointer from the username variable in the main*/
        (*head)->username = (char *)malloc(sizeof(char)*64);
        while(username[i] != '\0')
        {
            (*head)->username[i] = username[i];
            i += 1;
        }
        return 0;
    }
    else
    {
        return insert_into_array(&((*head)->next),key,username);
    }
}
int add(HashTable *H, char *username, char *password)
{
    int r = 0;
    int key = 0;
    int index = 0;
    if (H == NULL)
    {
        return -1;
    }
    /*Generating index using Hash function*/
    key = string_to_num(password);
    index = f(key, H->max_size);
    /*adding to Hash Table*/
    r=insert_into_array(&(H->store[index]),key,username);
    return 0;
}

Data* ll_search(Data *pList, int key)
{
    if (pList == NULL)
    {   
        return NULL;
    }
    if (pList->key == key)
    {   
        return pList;
    }
    else
    {   
        return ll_search(pList->next, key);
    }
}
int find(HashTable *H, char *username, char *password)
{
    int r = 0;
    int i = 0;
    int key = 0;
    int index = 0;
    Data *data = NULL;
    if (H == NULL)
    {
        return -1;
    }
    /*Generating index using Hash function*/
    key = string_to_num(password);
    index = f(key, H->max_size);
    data = ll_search(H->store[index],key);
    if (data == NULL)
    {
        return -1;
    }
    while(data->username[i] != '\0')
    {
        if (data->username[i] != username[i])
        {
            return -1;
        }
        i += 1;
    }
    return 0;
}

int ll_print_from_head(Data *p)
{   
    int i = 0;
    if (p==NULL)
    {   
        return 0;
    }
    while(p->username[i] != '\0')
    {
        printf("%c",p->username[i]);
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
