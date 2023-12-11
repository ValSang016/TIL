#include <stdio.h>

typedef struct
{
  char name[20];
  char company[10];
  int ID;
  double payPerHour;
  char date[20];
} EMPLOYEE;

void main()
{
  FILE *inFile, *outFile;
  inFile = fopen("employee1.txt", "r");
  outFile = fopen("employee2.txt", "w");
  EMPLOYEE employee[5];

  for (int i = 0; i < 5; i++)
  {
    fscanf(inFile, "%s %s %d %lf %s\n", &employee[i].name, &employee[i].company, &employee[i].ID, &employee[i].payPerHour, &employee[i].date);
    fprintf(outFile, "%s %s %d %lf %s\n", employee[i].name, employee[i].company, employee[i].ID, employee[i].payPerHour, employee[i].date);
  }
}