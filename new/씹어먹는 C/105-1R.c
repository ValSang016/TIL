#include <stdio.h>

int main(void)
{
   int i, j, k, N;
   printf("삼각형의 크기를 입력하세요.\n");
   scanf("%d",&N);
    for(i = 0; i < N; i++){
        for(j = 0; j < N-i-1; j++){
            printf(" ");
        }
        for(k = 0; k <= i*2; k++){
            printf("*");
        }
        printf("\n");
    }
   return 0;
}
/*
***
*****/
