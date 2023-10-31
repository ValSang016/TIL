#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Example4

void strcopy(char string1[], char string2[]){
  int i=0;
  while (string2[i] != '\0') {
    string1[i] = string2[i];
    i=i+1;
  }
  string1[i] = '\0';
/*  print string1  */
}