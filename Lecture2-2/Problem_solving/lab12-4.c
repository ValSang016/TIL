/*
*
* File : Lab11-2.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.21 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  int key;
  struct NODE *next;
} NODE;

// Print the all nodes. And delete node by "free" simultaneously.
void scanList(struct NODE *node)
{
  node = node->next;
  while (node != NULL)
  {
    printf(" %d ", node->key);
    struct NODE *delete = node;
    node = node->next;
    free(delete);
  }
  printf("\n");

}

// Insert the value in sturcture "node" by ascending order.
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
  int nums[10] = {17, 39, 11, 9, 42, 12, 15, 8, 13, 41};
  NODE head;
  head.key = 0, head.next = NULL;

  for (int i = 0; i < 10; i++)
  {
    insert(&head, nums[i]);
  }
  scanList(&head);
}
