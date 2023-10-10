#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 100
#define INF 1e9

int matrix[MAX_ROWS][MAX_COLS];
int dp[MAX_ROWS][MAX_COLS];
int next_step[MAX_ROWS][MAX_COLS];

void solve(int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (j == 0) 
              dp[i][j] = matrix[i][j];
            else {
                int up = (i - 1 + m) % m;
                int down = (i + 1) % m;
                int min_path_row = dp[up][j+1] <= dp[i][j+1] ? 
                                    (dp[up][j+1] <= dp[down][j+1] ? up : down)
                                    : 
                                    (dp[i][j+1] <= dp[down][j+1] ? i : down);
                dp[i][j] +=  matrix[min_path_row][j+1];
                next_step[i][j] = min_path_row;
            }
        }
    }
}

void print_solution(int m, int n) {
    solve(m, n);
    
    // Find the starting point of the minimum path.
    int start_row = INF;
    for(int i=0; i<m; ++i){
        if(start_row == INF || dp[start_row ][n-2]>dp[i ][n-2]){
            start_row=i;
        }
    }

     printf("%d", start_row+2); // Print the first row number
     int next_col=0;

     while(next_col<n-2){
         printf(" %d",next_step[start_row ][next_col]+m+2);
         start_row=next_step[start_row][next_col++];
     }

     printf(" %d\n",dp[start_row ][n-2]);
}

int main() {

   FILE *filePtr;

   filePtr=fopen("input.txt","r");
   
   if(filePtr==NULL){
       printf("File not found\n");
       return EXIT_FAILURE ;
   }

   int m, n;

  while(fscanf(filePtr,"%d%d",&m,&n)!=EOF){
    for(int i=0;i<m;++i){
      for(int j=0;j<n;++j){
        fscanf(filePtr,"%d", &matrix [i][j]);
      }
    }
    print_solution(m, n);
   }
}

