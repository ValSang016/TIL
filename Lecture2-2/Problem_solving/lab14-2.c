/*
*
* File : lab2.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Dec.05 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int info;
    struct node* ptr;
};


struct node *front, *back, *current, *temp;

// Check whether the queue is empty
int empty(){
    if (front == NULL)
    {
        return -1;
    }
    return 0;
}

// insert() is a function that insert data in the queue 
void insert(int data) {
    if (front == NULL)
    {
        front = (struct node*)malloc(1 * sizeof(struct node));
        front->ptr = NULL;
        front->info = data;
        back = front;
    }
    else
    {
        temp = (struct node*)malloc(1 * sizeof(struct node));
        temp->ptr = NULL;
        temp->info = data;
        back->ptr = temp;
        back = temp;
    }
    printf("\nNode is Inserted\n\n");
}

// delete() is a function that delete the front of queue
int delete() {
    temp = front;
    if(!empty()){
        front = front->ptr;
        int popped = temp->info;
        free(temp);
        return popped;
    }else
        printf("\nStack Underflow\n");
        return -1;
}
    
// Display the elements of the queue
void display() {
    temp = front;

    if (empty())
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The queue is \n");
    while (temp != NULL)
    {
        printf("%d--->", temp->info);
        temp = temp->ptr;
    }
    printf("NULL\n\n");

}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();

    printf("Deleted element is :%d\n", delete());
    printf("Deleted element is :%d\n", delete());

    display();

    insert(40);
    display();
}

