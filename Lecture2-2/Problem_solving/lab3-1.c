#include <stdio.h>


int word_count(char string[]){
  int counting = 0;
  for (int i = 0;; i++)
  {
    if (string[i]==NULL){
      break;
    }else if (string[i] != 32){
      counting++;
    }
  }
  return counting;
}

void main(){
  char string[100] = "";
  gets(string);
  printf("%s", string);
  int num = word_count(string);
  printf("%d", num);
}
