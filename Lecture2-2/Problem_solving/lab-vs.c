/*
*
* File : lab-vs.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.13 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SALARY1
{
  char name[10];
  int age;
  float sal;
}salary1[20];

struct SALARY2
{
  float sal;
}salary2[20];

struct SALARY3
{
  float sal;
}salary3[20];


/*
*
* void update1()
*
* Summary of this function : 
*   Update the data of which salaries of aged from 40 to 49 are raised 10%.
* 
*/
void update1(){
  FILE *file2;
  file2 = fopen("salary_v2.txt", "w");
  for (int i = 0; i < 20; i++)
  {
    if(salary1[i].age >= 40 && salary1[i].age <=49)
      salary2[i].sal = salary1[i].sal * 1.1;
    else
      salary2[i].sal = salary1[i].sal;
    fprintf(file2, "%s %d %f\n", salary1[i].name, salary1[i].age, salary2[i].sal);
  }
  fclose(file2);
}


/*
*
* void update2()
*
* Summary of this function : 
*   Update the data of which salaries of aged from 30 to 39 are raised 20%.
*
*/
void update2(){
  FILE *file3;
  file3 = fopen("salary_v3.txt", "w");
  for (int i = 0; i < 20; i++)
  {
    if(salary1[i].age >= 30 && salary1[i].age <=39)
      salary3[i].sal = salary2[i].sal * 1.2;
    else
      salary3[i].sal = salary2[i].sal;
    fprintf(file3, "%s %d %f\n", salary1[i].name, salary1[i].age, salary3[i].sal);
  }
  fclose(file3);
}


void main(){
  FILE *file1;
  file1 = fopen("salary_v1.txt", "r");

  if (salary1 == NULL)
  {
    perror("Not found the file.");
    exit(1);
  }

  for (int i = 0; i < 20; i++)
  {
    fscanf(file1, "%s %d %f\n", salary1[i].name, &salary1[i].age, &salary1[i].sal);
  }
  fclose(file1);
  
  update1();
  update2();

  for (int i = 0; i < 20; i++)
  {
    printf("%-5s %5d %10.2f -> %6.2f\n", salary1[i].name, salary1[i].age, salary1[i].sal, salary3[i].sal);
  }
  }
  
  
