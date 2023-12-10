/*
*
* File : Lab11-3.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.22 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for player
typedef struct NODE
{
  int back_num; 
  char name[30]; 
  int age; 
  int A_match; 
  int goals;
  struct NODE *next; 
} NODE;

// Function to free the allocated memory
void freeStruct(struct NODE *node)
{
  node = node->next;
  while (node != NULL)
  {
    struct NODE *delete = node;
    node = node->next;
    free(delete);
  }
}

// Function to insert a new node to the linked list
void insert(NODE *head, int back, char *N, int A, int M, int G)
{
  NODE *p = head->next, *prev = head;
  NODE *new_node;
  while (p)
  {
    if (p->back_num > back)
      break;
    prev = p;
    p = p->next;
  }
  new_node = (NODE *)malloc(sizeof(NODE));
  new_node->back_num = back;
  new_node->age = A;
  new_node->A_match = M;
  new_node->goals = G;
  strcpy(new_node->name, N);
  prev->next = new_node;
  new_node->next = p;
}

// Function to find the player with minimum age
void find_min_age(NODE *head)
{
  NODE *p = head->next;
  NODE *min = NULL;
  int min_age = 100;
  
  do{
    if (p->age < min_age)
    {
      min_age = p->age;
      min = p;
    }
    p = p->next;
  }while (p->next != NULL);
    if(!(min==NULL)){
      printf("Min age : ");
      printf("%d %s %d %d %d\n", min->back_num, min->name, min->age, min->A_match, min->goals);
    }
    else
      printf("NULL");
}

// Function to find the player with maximum age
void find_max_age(NODE *head)
{
  NODE *p = head->next;
  NODE *max = NULL;
  int max_age = -1;
  
  do{
    if (p->age > max_age)
    {
      max_age = p->age;
      max = p;
    }
    p = p->next;
  }while (p->next != NULL);
  if(!(max==NULL)){
    printf("Max age : ");
    printf("%d %s %d %d %d\n", max->back_num, max->name, max->age, max->A_match, max->goals);
  }
  else
    printf("NULL");
}

// Function to find the player with minimum goals
void find_min_goal(NODE *head)
{
  NODE *p = head->next;
  NODE *min = NULL;
  int min_goal = 100;
  
  do{
    if (p->goals < min_goal)
    {
      min_goal = p->goals;
      min = p;
    }
    p = p->next;
  }while (p->next != NULL);
    if(!(min==NULL)){
      printf("Min goals : ");
      printf("%d %s %d %d %d\n", min->back_num, min->name, min->age, min->A_match, min->goals);
    }
    else
      printf("NULL");
}

// Function to find the player with maximum goals
void find_max_goal(NODE *head)
{
  NODE *p = head->next;
  NODE *max = NULL;
  int max_goal = -1;
  
  do{
    if (p->goals > max_goal)
    {
      max_goal = p->goals;
      max = p;
    }
    p = p->next;
  }while (p->next != NULL);
  if(!(max==NULL)){
    printf("Max goals : ");
    printf("%d %s %d %d %d\n", max->back_num, max->name, max->age, max->A_match, max->goals);
  }
  else
    printf("NULL");
}

// Function to find the player with minimum A matches
void find_min_match(NODE *head)
{
  NODE *p = head->next;
  NODE *min = NULL;
  int min_match = 500;
  
  do{
    if (p->A_match < min_match)
    {
      min_match = p->A_match;
      min = p;
    }
    p = p->next;
  }while (p->next != NULL);
    if(!(min==NULL)){
      printf("Min A-match : ");
      printf("%d %s %d %d %d\n", min->back_num, min->name, min->age, min->A_match, min->goals);
    }
    else
      printf("NULL");
}

// Function to find the player with maximum A matches
void find_max_match(NODE *head)
{
  NODE *p = head->next;
  NODE *max = NULL;
  int max_match = -1;
  
  do{
    if (p->A_match > max_match)
    {
      max_match = p->A_match;
      max = p;
    }
    p = p->next;
  }while (p->next != NULL);
  if(!(max==NULL)){
    printf("Max A-match : ");
    printf("%d %s %d %d %d\n", max->back_num, max->name, max->age, max->A_match, max->goals);
  }
  else
    printf("NULL");
}

// Main function
int main()
{
  int back_num, age, A_match, goals;
  char first_name[15], last_name[15], name[30];
  FILE *file;
  file = fopen("player.txt", "r");
  if (file == NULL)
  {
    printf("File not found");
    return 0;
  }

  NODE head;
  head.back_num = 0, head.age = 0, head.A_match = 0, head.goals = 0, head.next = NULL;

  // Read the file and insert the players to the linked list
  while (fscanf(file, "%d %s %s %d %d %d", &back_num, first_name, last_name, &age, &A_match, &goals) != EOF)
  {
    sprintf(name, "%s %s", first_name, last_name);
    insert(&head, back_num, name, age, A_match, goals);
  }
  fclose(file);

  // Find and print the players with minimum and maximum ages, goals, and A matches
  find_min_age(&head);
  find_max_age(&head);
  find_min_goal(&head);
  find_max_goal(&head);
  find_min_match(&head);
  find_max_match(&head);

  // Free the allocated memory
  freeStruct(&head);
}
