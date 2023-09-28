#include <stdio.h>

void minmax(int, int, int*, int*);

void minmax(int val1, int val2, int  *smallest, int *largest){
  if (val1 >= val2){
    *largest = val1;
    *smallest = val2;
  }else{
    *largest = val2;
    *smallest = val1;
  }
}

void main(){
  int val1=2, val2=3;
  int smallest, largest;
  minmax(val1, val2, &smallest, &largest);

  printf("Min : %d, Max :  %d", smallest, largest);
}