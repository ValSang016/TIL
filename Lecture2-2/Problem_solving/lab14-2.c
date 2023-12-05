#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int info;
    struct node* ptr;
};


struct node *front, *back, *current, *temp;

// Push() operation on a  stack
void push(int data) {
    if (front == NULL)
    {
        front = (struct node*)malloc(1 * sizeof(struct node));
        front->ptr = NULL;
        front->info = data;
        current = front;
    }
    else
    {
        temp = (struct node*)malloc(1 * sizeof(struct node));
        temp->ptr = current;
        temp->info = data;
        current = temp;
        back = temp;

    }
    printf("Node is Inserted\n\n");
}

int pop() {
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    return popped;
}

void display() {
    // Display the elements of the stack
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d--->", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n\n");

}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped element is :%d\n", pop());
    push(40);
    display();
}

