#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 33
#define HASH_FUNCTION(KEY) KEY % TABLE_SIZE


typedef struct s_node
{
    int             key;
    char            *data;
    struct s_node   *next;
}                   t_node;

typedef struct s_table{
    t_node          *head;
    int             count;
}                   t_table;

int     h_key_maker(char *data);
t_node  *h_create_node(char *data);
void    h_add_hash(char *data);
void    h_remove_hash(int key);
bool    h_search_hash(int key, char *data);
void    print_table();
void    search_and_print(char *data);
void    delete_and_print(char *data);
void    insert_and_print(char *data);
t_table table[TABLE_SIZE];


t_node *h_create_node(char *data)
{
    t_node  *node;
    node = (t_node *)malloc(sizeof(t_node) * 1);

    if (!node)
        return (0);

    int key = h_key_maker(data);

    node->key = key;
   node->data = (char *)malloc(strlen(data) + 1);
    if (!node->data) {
        free(node);
        return NULL;
    }
    strcpy(node->data, data);
    node->next = NULL;
    return (node);
}

int h_key_maker(char *data)
{
    int key = 0;
    unsigned int i = 0;

    if (!data)
        return 0;
    while (data[i])
    {
        key += (int)data[i];
        i++;
    }
    return key;
}

void h_add_hash(char *data)
{
	int hashindex;
	t_node *newnode;
    if (!data)
    {
        printf("Empty data\n");
        return ;
    }

    if (h_search_hash(h_key_maker(data), data))
    {
        printf("Already exists\n");
        return ;
    }

    if (!(newnode = h_create_node(data)))
    {
        printf("Malloc Failed create node\n");
				exit(1);
    }

    hashindex = HASH_FUNCTION(newnode->key);
    if(!table[hashindex].count)
    {
    	table[hashindex].head = newnode;
        table[hashindex].count++;
    }
    else
    {
        newnode->next = table[hashindex].head;
        table[hashindex].head = newnode;
        table[hashindex].count++;
    }
    printf("Inserted\n");
}

bool h_search_hash(int key, char *data)
{
    int hashindex = HASH_FUNCTION(key);
    bool search_flag = false;
    t_node *finder = table[hashindex].head;

    while (finder)
    {
        if((finder->key == key)&&(strcmp(finder->data, data) == 0))
        {
            search_flag = true;
            break;
        }
        finder = finder->next;
    }
    if (search_flag == true)
    {
        printf("DATA: %s\n", finder->data);
        return (search_flag);
    }
    else
    {
        printf("NOT FOUND\n");
        return (search_flag);
    }
}

void    h_remove_hash(int key)
{
    int     hashindex = HASH_FUNCTION(key);
    bool    remove_flag = false;
    t_node  *finder;
    t_node  *before;

    finder = table[hashindex].head;
    while (finder)
    {
        if (finder->key == key)
        {
            if (finder == table[hashindex].head)
                table[hashindex].head = finder->next;
            else
                before->next = finder->next;
            table[hashindex].count--;
            free(finder);
            remove_flag = true;
        }
        before = finder;	
        finder = finder->next;	
    }
    if (remove_flag == true)		
        printf("DELETED: %d\n", key);
    else		
        printf("NOT FOUND\n");
}
void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:\n", i);
        t_node *current = table[i].head;
        if(!(current==NULL)){
            while (current) {
                printf("Key: %d, Data: %s\n", current->key, current->data);
                current = current->next;
            }
         }else {
            printf("NULL\n");
         }
    }
}
void search_and_print(char *data)
{
    printf("Search for %s: ", data);
    if(h_search_hash(h_key_maker(data), data)){
        printf("FOUND\n");
    }
}

void delete_and_print(char *data)
{
    printf("Delete %s: ", data);
    h_remove_hash(h_key_maker(data));
}

void insert_and_print(char *data)
{
    printf("Insert %s: ", data);
    h_search_hash(h_key_maker(data), data);
}

int main()
{
    t_table *table = (t_table *)malloc(sizeof(t_table) * TABLE_SIZE);
    if (!table) {
        printf("Malloc Failed create table\n");
        return 1;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].head = NULL;
        table[i].count = 0;
    }

    FILE *inputFile = fopen("keyinput.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening keyinput.txt\n");
        return 1;
    }

    char data[20];

    while (fscanf(inputFile, "%s", data) != EOF) {
        h_add_hash(data);
    }

    fclose(inputFile);

    print_table();

    search_and_print("Blue");
    search_and_print("black");
    search_and_print("Purple");
    delete_and_print("Purple");
    delete_and_print("Blue");
    delete_and_print("Green");
    insert_and_print("Green");
    insert_and_print("White");
    insert_and_print("Golden");
    insert_and_print("nedloG");
    search_and_print("Blue");
    search_and_print("nedloG");
    search_and_print("Yellow");
    search_and_print("Green");
    
    print_table();

    return 0;
}