#include <stdio.h>

void main(){

  char *ptr, string[20] = "programming";
  ptr = string;
  ptr += 3;
  *ptr = 'k';  // ""큰 따옴표 안됨
  printf("%s", string);

}