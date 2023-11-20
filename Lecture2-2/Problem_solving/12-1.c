#include <stdio.h>
#include <stdlib.h>

struct NODE
{
  int key;
  struct NODE* next;
} node[4];

// seraching the schkey
int main(){
  node[0].key = 100;
  node[1].key = 250;
  node[2].key = 467;
  node[0].next = &node[1];
  node[1].next = &node[2];
  node[2].next = NULL;

  struct NODE *ptr;
  int srchkey = 467, found = 0;

  ptr = &node[0];

  while (ptr != NULL)
  {
    if(ptr->key == srchkey){
      found = 1;
      break;
    }
    ptr = ptr->next;
  }
  if (found)
    printf("Search key found");
  else
    printf("Search key not found");

}
