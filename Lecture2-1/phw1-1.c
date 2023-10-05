#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
//Circular array queue


void print(){                              //print this queue
    int front_p = front, rear_p = rear;
    if(front == -1){                         //when the queue is empty
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements : ");
    if(front_p <= rear_p){                         //devide cases 1.front <= rear
        while(front_p <= rear_p){
            printf("%d ", queue[front_p]);
            front_p++;
        }
    } else {                                        //case 2. front > rear
        while(front_p <= SIZE - 1){
            printf("%d ", queue[front_p]);
            front_p++;
        }
        front_p = 0;
        while(front_p <= rear_p){
            printf("%d ", queue[front_p]);
            front_p++;
        }
    }
printf("\n");
}

int queue_full(){
     if((rear == SIZE-1 && front == 0) || front == rear + 1){
        return 1;
    } else 
    return 0;
}

int queue_empty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(front == -1){                    //Initially, 'front' and 'rear' should start at 0
        front = 0;
        rear = 0;
    } else if(rear == SIZE-1){          //Because, this queue is a circular queue
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

int dequeue(){
    int data = queue[front];
    if(rear == front){                  //when the queue is empty, restart this queue
        rear = -1;
        front = -1;
    } else {
        if(front == SIZE-1){            //Because, this queue is a circular queue
            front = 0;
        }
        front++;
    }
    return data;
}


int main(){
    int i, p;
    for(;;){
        print();
        printf(" 1.enqueue 2.dequeue 3.finish\n");
        scanf("%d", &i);
            switch(i) {                            
            case 1:
                if(!queue_full()){                  
                    printf("Enter the number.\n");
                    scanf("%d", &p);
                    enqueue(p);
                } else printf("Queue is full.\n\n");
                break;
            case 2:
                if(!queue_empty()){                                 
                    for(;;){
                        int answer;
                        printf("Did you delete %d? 1.Y 2.N\n", queue[front]);
                        scanf("%d", &answer);
                        if(answer == 1) {
                            printf("%d is deleted.\n\n", dequeue());
                            break;
                            } else if (answer == 2) {
                            break;
                        } else printf("Retry.\n\n");
                    } 
                }else printf("Queue is emtpy.\n\n");
                break;
            case 3:
                return 0;
            default:
                printf("Retry.\n\n");
            }
            
        }
}