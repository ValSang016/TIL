#include <stdio.h>

struct CAR {
char name[20];
int year;
}car[2];


void main(){
  struct CAR car[0] = {"Avante", 2007};
  struct CAR car[1] = {"Sonata", 2008};
  
  FILE *outFile;
  outFile = fopen("myinFile.txt", "r");
}