#include <stdio.h>

struct Cal
{
  char name[20];
  float EPS;
  float PER;
};


void main(){
  char name[20];
  float EPS;
  float PER;

  for (int i = 0; i < 3; i++)
  {
    struct Cal cal;
    printf("Enter the name of stock, EPS, PER orderly.");
    scanf("%c %f %f", &cal.name, &cal.EPS, &cal.PER);
    printf("Price of %c stock : $%6.3f\n", name, cal.EPS*cal.PER);
  }
  

}