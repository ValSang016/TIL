#include <stdio.h>

struct
{
  int month, day, year;
} date;


void main(){
  int month, day, year;

  printf("Enter the month, day, year orderly.");
  scanf("%d %d %d", &day, &month, &year);

  date.month = month;
  date.day = day;
  date.year = year;

  printf("%d-%d-%d", date.year, date.month, date.day);
  
}