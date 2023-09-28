#include <stdio.h>
#include <stdlib.h>

#define STRING 100
#define MAX_SIZE 100

void processing(char X[STRING], char Y[STRING], int S[MAX_SIZE][MAX_SIZE]){
  for (int i = 0; i < MAX_SIZE; i++)
  {
    if (Y[i] == '\0') {
            break;
        }
    for (int j = 0; j < MAX_SIZE; j++)
    {
      if(X[j] == '\0') {
            break;
      }else if(X[j] == Y[i]){
        S[i][j] = 2;
      }
      else{
        S[i][j] = 1;
      }
    }

  }
}

int search(int S[MAX_SIZE][MAX_SIZE], int i, int j){
  int counting = 0;
  if(S[i][j] == 0){
    return 1;
  }
  for (int k = j;; k++)
  {
    if(S[i][k]==0){
      break;
    } else if(S[i][k] == 2){
      counting += search(S, i+1, k+1);
    }
  }
  return counting;
}

void print_results(int result[], int num){
  for (int i = 0; i < num; i++)
  {
    printf("%d\n", result[i]);
  }
  
}

int main(){
  char X[STRING], Y[STRING];
  int num=1, counting = 0;
    int S[MAX_SIZE][MAX_SIZE];
  printf("Enter a number : ");
  scanf("%d", &num);

  int result[num];

  for (int i = 0; i < num; i++){
    for (int m = 0; m < STRING; m++) {
        for (int n = 0; n < STRING; n++){
          if (S[m][n] == 0) {
            break;
          }
          S[m][n] = 0;
          }
        }   
    scanf("%s", X);
    scanf("%s", Y);
    processing(X, Y, S);
    counting = search(S, 0, 0);
    result[i] = counting;
  }
  print_results(result, num);

  return 0;
}