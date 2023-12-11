#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  int key;
  struct NODE *next;
}NODE;



void main()
{
  struct NODE *node1, *node2, *node3;
  node1 = (NODE *)malloc(sizeof(NODE));
  node2 = (NODE *)malloc(sizeof(NODE));
  node3 = (NODE *)malloc(sizeof(NODE));

  if (node1 != NULL)
  {
    (*node1).key = 100;
    (*node1).next = NULL;
  }
  if (node2 != NULL)
  {
    (*node2).key = 300;
    (*node1).next = node2;
  }
  if (node3 != NULL)
  {
    (*node3).key = 400;
    (*node2).next = node3;
  }
  
    NODE *item;
    item = node1;
    while (item)
    {
      printf("%d\n", item->key);
      NODE *delete = item;
      item = item->next;
      free(delete);
    }
}