#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

//Linked list stack
struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL; // top is empty initially
int top_node = 0; // a variable to store number of nodes in stack


int stack_full() {
    if(top_node >= MAX_SIZE)
        return 1;
    return 0;
}

int stack_empty() {
    return top == NULL;
}

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // test if memory allocation failed
    if(temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    } else if(top_node == 0){     //The link of head Node should be none
        temp->data = x;
        temp->link = NULL;
    } else {
        temp->data = x;           
        temp->link = top;
    }
    top = temp;
    top_node++;
}

 

int pop() {
int i = 0;
struct Node* del;
if(stack_empty()){
    return 0;
}
del = top;
i = del->data;
top = del->link;
free(del);    //free a deleted (disconnected) node
top_node--;
return i;
}


// helper function: traverse stack from front to top and print elements
void print_stack() {
    struct Node* n;
    n = top;
    printf("stack\n");
while (n!= NULL) {
printf("%d\n", n->data);
n = n->link;
}
printf("top : %d\n", top_node);
}

 
// helper function: run a series of push
// input arguments: int arr[] <- an array from which input values are taken
// input arguments: int num <- total number of elements to push

void run_push(int arr[], int num) {
    for(int i=0; i<num; i++) {
        printf("push(%d) , ", arr[i]);
        if(!stack_full()) {
            push(arr[i]);
        } else {
            printf("stack full!\n");
       }
       print_stack();
    }
}

 

// helper function: run a series of pops
// input argument: int num <- total number of elements to pop
void run_pop(int num) {
    int value;
    for(int i=0; i<num; i++) {
        printf("pop() ");
        if(!stack_empty()) {
            value = pop();
            printf("-> %d \n", value);
        }
        else {
            printf("stack empty!\n");
            top = NULL;
        }
        print_stack();
    }
}

 

int main() {
    int numbers[] = {3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8};
    print_stack();
    run_push(numbers, 5);
    run_pop(3);
    run_push(numbers, 10);
    run_pop(11);
    run_push(numbers, 11);
}