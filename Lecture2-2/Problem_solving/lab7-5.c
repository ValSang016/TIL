#include <stdio.h>
#define MAX 5

int puzzle(int n){
  if(n==1)
    return 1;
  if(n % 2 == 0)
    return (puzzle(n/2) + n);
  else
    return (puzzle(3*n+1));
}

void main(){
  int result;

  result = puzzle(5);
  printf("%d", result);
}