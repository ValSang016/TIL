#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DistinctSub(char strx[], char strz[]) {
    int m = strlen(strx);
    int n = strlen(strz);

    // dp[i][j]에 저장
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // 초기화
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    
    for (int j = 0; j <= m; j++) {
        dp[j][0] = 1;
    }

   // DP 테이블 채우기
   for (int j=1;j<=m;j++){
      for(int i=1;i<=n;i++){
         if(strx[j-1]==strz[i-1]){ // 같음, 옆 값과 위 값을 더한 값
            dp[j][i]=dp[j-1][i-1]+dp[j-1][i];
         }else{ // 다르면 바로 전 값
            dp[j][i]=dp[j-1][i];
         }
      }
   }

   int result=dp[m][n];

   // 동적 할당 해제
   for(int i=0;i<=m;i++){
      free(dp[i]);
   }
   free(dp);

   return result;
}

typedef struct TestCase{
   char strx[100];
   char strz[100];
   int result;
} TestCase;

TestCase getTestCase(){
   TestCase tc;

   printf("Enter string S: ");
   scanf("%s", tc.strx);

   printf("Enter string T: ");
   scanf("%s", tc.strz);

   tc.result=DistinctSub(tc.strx, tc.strz);
   
   return tc;
}

void printTestCase(TestCase* tcs,int num){
   for(int t=0;t<num;t++){
      printf("\nInput: S=\"%s\", T=\"%s\"",tcs[t].strx,tcs[t].strz);
      printf("\nOutput: %d",tcs[t].result);
   }
}

int main() {
   int num;

   printf("test cases: ");
   scanf("%d", &num);

   TestCase* testCases=(TestCase*)malloc(num*sizeof(TestCase));

   for(int t=0;t<num;t++){
      testCases[t]=getTestCase();
   }
   
   printTestCase(testCases,num);
   
   free(testCases);
   
   return(0);
}