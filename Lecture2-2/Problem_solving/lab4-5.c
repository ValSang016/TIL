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

  for (int i = 0; i < 1; i++)
  {
    struct Cal cal;
    printf("Enter the name of stock, EPS, PER orderly.");
    scanf("%s %f %f", cal.name, &cal.EPS, &cal.PER);
    printf("Price of %s stock : $%6.3f\n", cal.name, cal.EPS*cal.PER);
  }
  

}