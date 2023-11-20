/*
*
* File : Lab11-1.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.23 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
  int key;
  struct NODE* next;
} node[4];

int main(){
  node[0].key = 100;
  node[1].key = 250;
  node[2].key = 467;
  node[0].next = &node[1];
  node[1].next = &node[2];
  node[2].next = NULL;


  struct NODE *ptr, *old_ptr;
  int new_key, fail = -1;
  node[3].key = new_key = 100;
  node[3].next = NULL;

  // The ptr starts at a first node.
  ptr = &node[0];

  while (ptr)
  {
    if (ptr->key == new_key) // Compare the key of ptr and the new key.
    {                        // When they are same, we stop this process.
      printf("key already exists.");
      break;
    }
    
    if (ptr->key < new_key) // When the key of ptr is smaller than the new key
    {
      old_ptr = ptr;
      ptr = ptr->next;
    }
    else // Whene the key of ptr is larger than the new key
    {
      old_ptr->next = &node[3];
      node[3].next = ptr;
      printf("key inserted.");
      break;
    }
  }
}
