#include <stdio.h>

void main(){
  float* fptr;
  int* iptr;
  float fvalue;
  int ivalue;

  ivalue = 200;
  fvalue = 314.72;
  iptr = &ivalue;
  fptr = &fvalue;

  *fptr -= 300;
  *iptr += 300;

  printf("%f %d", fvalue, ivalue);
}