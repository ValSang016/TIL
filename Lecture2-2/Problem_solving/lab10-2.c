#include <stdio.h>

struct EMPLOYEE
{
  char name[20];
  char company[10];
  int ID;
  double payPerHour;
  char date[20];
} employee[5];

void main()
{
  FILE *inFile, *outFile;
  inFile = fopen("employee1.txt", "r");
  outFile = fopen("employee2.txt", "w");


  for (int i = 0; i < 4; i++)
  {
    fscanf(inFile, "%s %s %d %lf %s\n", &employee[i].name, &employee[i].company, &employee[i].ID, &employee[i].payPerHour, &employee[i].date);
    fprintf(outFile, "%s %s %d %lf %s\n", employee[i].name, employee[i].company, employee[i].ID, employee[i].payPerHour, employee[i].date);
  }
}