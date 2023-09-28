#include <stdio.h>

#define SIZE 10
int stack[SIZE];
int top = -1;

//non-circular stack

/*void call(){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    } printf("\n");
}*/

int stack_full(){
    if (top == SIZE - 1){
        return 1;
    } else 
    return 0;
}

int stack_empty(){
    if (top == -1){
        return 1;
    } else
    return 0;
}

void push(int data){
    top++;
    stack[top] = data;
}

int pop(){
    int k = stack[top];
    top--;
    return k;
}


int main(){
for(;;){
    int i, p;
    printf("현재 스택 : ");
    for(int i = 0; i <= top; i++){           //스택을 print하는 함수를 따로 만들 수 있지만, printf를 오직 main에서만 사용해야한다는 조건을 따름
    printf("%d ", stack[i]);
    }
    printf(" 1.push 2.pop 3.finish\n");
    scanf("%d", &i);
        switch(i) {                             //push, pop 선택에 따라 기능실행
        case 1:
            if(!stack_full()){                     //top이 size와 같지 않은 비포화상태일 때, 작동
                printf("숫자를 입력하세요.\n");  
                scanf("%d", &p);
                push(p);
            } else printf("꽉 찼습니다. 스택을 비워주세요.\n\n");
            break;
        case 2:
            if(!stack_empty()){                                  //top이 -1 이상일 때, 작동
                for(;;){
                    int answer;
                    printf("%d를 제거할까요? 1.Y 2.N\n", stack[top]);
                    scanf("%d", &answer);
                    if(answer == 1) {
                        printf("%d가 제거되었습니다.\n\n", pop());
                        break;
                        } else if (answer == 2) {
                        break;
                    } else printf("다시 입력해주세요.\n\n");
                } 
            }else printf("비어있습니다. 스택을 채워주세요.\n\n");
            break;
        case 3:
            printf("\n시스템을 종료합니다.");
            return 0;
        default:
            printf("다시 입력해주세요.\n\n");
        }
        
    }
}