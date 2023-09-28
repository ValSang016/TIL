#include <stdio.h>

int main(void)
{
   int i;
   int b1,b2  = 1;
   int c1, c2;
   printf("삼각형의 크기를 입력하세요.\n");
   scanf("%d",&i);
    int start = i;
    c1 = i-1;
    c2 = c1;
    while(start > 0){
        while(c2 > 0){
            printf(" ");
            c2--;
        } 
        c2 = c1;
        c2--;
        c1--;
        for(int a = 1; a<=b2; a++){
        printf("*");
        }
        b2 = 2*b1 + 1;
        b1++;
        printf("\n");
        start--;
    }
   return 0;
}
// comment : while 대신 for로 결합할 수 있는 것들이 있음. 간결하게 표한하기. 또한 변수가 다 따로 놀고 있음. 변수 간 유기적 관계 떠올리기.
