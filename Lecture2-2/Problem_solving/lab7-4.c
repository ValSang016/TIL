#include <stdio.h>
#define MAX 5

//제곱
double pow(float a, int n){
  if(n < 0 || n > MAX){
    printf("array boundary error");
    return -1;
  } else {
    if (n == 0)
      return 1;
    else 
      return (a * pow(a, n-1));
  }
}

void main(){
  float result;

  result = pow(2.1, 3);
  printf("%.2f", result);
}