// hash.h
#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 33
#define HASH_FUNCTION(KEY) KEY % TABLE_SIZE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool    h_search_hash(int key);

char	*dup(const char *s);
int     len(const char *str);

void    del_buf(void *str, char type);

extern t_table  *table;

#endif