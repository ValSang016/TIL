#include <stdio.h>
#include <stdlib.h>

struct NODE
{
  int key;
  struct NODE *next;
};



void main()
{
  struct NODE *node1, *node2, *node3;
  node1 = (struct NODE *)malloc(sizeof(struct NODE));
  node2 = (struct NODE *)malloc(sizeof(struct NODE));
  node3 = (struct NODE *)malloc(sizeof(struct NODE));

  if (node1 != (struct NODE *)NULL)
  {
    (*node1).key = 100;
    (*node1).next = NULL;
  }
  if (node2 != (struct NODE *)NULL)
  {
    (*node2).key = 300;
    (*node1).next = node2;
  }
  if (node3 != (struct NODE *)NULL)
  {
    (*node3).key = 400;
    (*node2).next = node3;
  }
  
    struct NODE *item;
    item = node1;
    while (item)
    {
      printf("%d\n", item->key);
      struct NODE *delete = item;
      item = item->next;
      free(delete);
    }
    


}