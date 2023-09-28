#include <stdio.h>


void calculate(int val1, int val2, int *re1, int *re2, int *re3, int *re4){
  *re1 = val1*val2;
  *re2 = val1/val2;
  *re3 = val1%val2;
  *re4 = val1+val2;
}

void main(){
  int val1, val2;
  int re1, re2, re3, re4;

  scanf("%d %d", &val1, &val2);
  calculate(val1, val2, &re1, &re2, &re3, &re4);

  printf("%d %d %d %d", re1, re2, re3, re4);
}