#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

//Linked list queue
struct Node {
    int data;
    struct Node* link;
};

 
struct Node* front = NULL; // front is empty initially
struct Node* rear = NULL; // rear is empty initially
int n_nodes = 0; // a variable to store number of nodes in queue

 

int queue_full() {
    if(n_nodes >= MAX_SIZE)
        return 1;
    return 0;
}

int queue_empty() {
    if(n_nodes == 0)
        return 1;
    return 0;
}

void enqueue(int x) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // test if memory allocation failed
    if(temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    } else {
        temp->data = x;
        temp->link = NULL;
    }
    if(queue_empty()){
        front = temp;
    } else {
        rear->link = temp;
    }
    rear = temp;
    n_nodes++;
}

 

int dequeue() {
int i = 0;
struct Node* del;
del = front;
i = front->data;
front = del->link;
free(del);                // free a deleted (disconnected) node
n_nodes--;
return i;
}


// helper function: traverse queue from front to rear and print elements
void print_queue() {
    struct Node* n;
    n = front;
    printf("queue =");
while (n != NULL) {
printf(" %d ", n->data);
n = n->link;
}
    printf("\n");
}

 
// helper function: run a series of enqueues
// input arguments: int arr[] <- an array from which input values are taken
// input arguments: int num <- total number of elements to push

void run_enqueues(int arr[], int num) {
    for(int i=0; i<num; i++) {
        printf("enqueue(%d) , ", arr[i]);
        if(!queue_full()) {
            enqueue(arr[i]);
        }
       else {
            printf("queue full! ");
       }
       print_queue();
    }

}

 

// helper function: run a series of pops
// input argument: int num <- total number of elements to pop

void run_dequeues(int num) {
    int value;
    for(int i=0; i<num; i++) {
        printf("dequeue() ");
        if(!queue_empty()) {
            value = dequeue();
            printf("-> %d , ", value);
        }
        else {
            printf("queue empty! ");
            front = rear = NULL;
        }
        print_queue();
    }
}

 

int main() {

    int numbers[] = {3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8};
    print_queue();
    run_enqueues(numbers, 5);
    run_dequeues(3);
    run_enqueues(numbers, 10);
    run_dequeues(11);
    run_enqueues(numbers, 11);
}