
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  int key;
  struct NODE *next;
} NODE;

void scanList(struct NODE *node)
{
  while (node != NULL)
  {
    printf(" %d ", node->key);
    node = node->next;
  }
  printf("\n");
}

void insert(struct NODE *head, int value)
{
  struct NODE *p = head->next, *prev = head;
  struct NODE *new_node;
  while (p)
  {
    if (p->key > value)
      break;
    prev = p;
    p = p->next;
  }
  new_node = (struct NODE *)malloc(sizeof(struct NODE));
  new_node->key = value;
  prev->next = new_node;
  new_node->next = p;
}

int main()
{
  NODE node[7];
  NODE head;
  head.key = 0;
  head.next = NULL;

  insert(&head, 100);
  insert(&head, 250);
  insert(&head, 467);
  scanList(&head);

  insert(&head, 250);
  insert(&head, 300);
  insert(&head, 500);
  scanList(&head);
}
