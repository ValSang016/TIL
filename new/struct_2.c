#include <stdio.h>
#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

//non-circular queue

/*void call(){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    } printf("\n");
}*/

int queue_full(){
     if (rear == SIZE){
        return 1;
    } else 
    return 0;
}

int queue_empty(){
    if(front > rear){    //front가 rear보다 커진다면 마지막 큐까지 모두 아웃시켰다는 얘기, 더 이상 삭제 불가능
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(front == -1){
        front++;
    }
    rear++;
    queue[rear] = data;
}

int dequeue(){
    front++;
    return 0;     
}


int main(){
    int i, p;
    for(;;){
        if(queue_full() && queue_empty()){           //rear가 size크기와 같고, front가 rear보다 클 때 더 이상 들어갈 자리가 없음. non-circular
            printf("더 이상 큐를 작동시킬 수 없습니다.");
            return 0;  
        }
        printf("현재 큐 : ");            //스택을 print하는 함수를 따로 만들 수 있지만, printf를 오직 main에서만 사용해야한다는 조건을 따름
        for(int s = front; s <= rear; s++){
            printf("%d ", queue[s]);
        }
        printf(" 1.enqueue 2.dequeue 3.finish\n");
        scanf("%d", &i);
            switch(i) {                            
            case 1:
                if(!queue_full()){                   //rear가 size크기만큼 커지지 않았을 때, 작동
                    printf("숫자를 입력하세요.\n");
                    scanf("%d", &p);
                    enqueue(p);
                } else printf("꽉 찼습니다. 더 이상 숫자를 삽입할 수 없습니다.\n\n");
                break;
            case 2:
                if(!queue_empty()){                                 //front가 rear와 같거나 작을 때, 작동
                    for(;;){
                        int answer;
                        printf("%d를 제거할까요? 1.Y 2.N\n", queue[front]);
                        scanf("%d", &answer);
                        if(answer == 1) {
                            dequeue();
                            printf("%d가 제거되었습니다.\n\n", queue[front-1]);
                            break;
                            } else if (answer == 2) {
                            break;
                        } else printf("다시 입력해주세요.\n\n");
                    } 
                }else printf("비어있습니다. 스택을 채워주세요.\n\n");
                break;
            case 3:
                return 0;
            default:
                printf("다시 입력해주세요.\n\n");
            }
            
        }
}