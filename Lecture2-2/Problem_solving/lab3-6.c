#include <stdio.h>

void main(){
  void newVal(float *);
  float testval;

  printf("\nEnter a number : ");
  scanf("%f", &testval);

  newVal(&testval);

}

void newVal(float *num){
  *num += 20.2;
}