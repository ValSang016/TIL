#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int info;
    struct node* ptr;
};


struct node *top, *top1, *temp;

int empty(){
  if(top == NULL){
    printf("Stack is empty.");
  } else{
    printf("Stack is not empty.");
  }
}

// Push() operation on a  stack
void push(int data) {
    if (top == NULL)
    {
        top = (struct node*)malloc(1 * sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp = (struct node*)malloc(1 * sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
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
    pop();
    pop();
    pop();
    
    display();
    empty();
}

