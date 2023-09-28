#include <stdio.h>

int sum(int a, int b){
  int c = 0;
  c = a+b;
  return c;
}

int main(){
  int a = 10;
  int b = 20;
  int s = sum(a, b);
  printf("sum = %d\n", s);
}