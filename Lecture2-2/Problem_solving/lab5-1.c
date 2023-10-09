/*
* File: Exercise12.2.3.C
*
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Oct.08 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>

#define number 6 // number of employees

/*
*
* struct ID(int), last_name[20](char), pay_rate(float), hours_worked(float)
*
* Summary of this function : 
*   This function calculates multipulation, division, remainder, plus of two values.
* 
*/
struct 
{
  int ID;
  char last_name[20];
  float pay_rate;
  float hours_worked;
}employees[number];


/*
*
* void main()
*
* Summary of this function : 
*   This function receives imformations of employees(ID, name, payrate, hours worked)
*   and caculate total pay of each employees and print a payroll report.
* 
*/
void main(){
  float total_pay[number]; // Total payroll of each employees
  float total_payroll = 0; // Total payroll of all employees

  //Receive informations of employees and save the total pay of each employees
  for (int i = 0; i < number; i++)
  {
    printf("Enter the ID, last_name, payrate, hours worked of %dth employee\n", i+1);
    scanf("%d %s %f %f", &employees[i].ID, employees[i].last_name, &employees[i].pay_rate, &employees[i].hours_worked);
    total_pay[i] = employees[i].pay_rate * employees[i].hours_worked; 
  }

  // Sum the total payroll of all employees
  for (int i = 0; i < number; i++)
  {
    total_payroll += total_pay[i];
  }
  
  // Print the payroll report
  printf("|   ID   |    NAME    |  Total pay  |\n");
  for (int i = 0; i < number; i++)
  {
    printf("|  %d  | %7s    |    %.2f   |\n", employees[i].ID, employees[i].last_name, total_pay[i]);
  }
  printf("Total payroll of all employees : %.2f", total_payroll);
  
  
}