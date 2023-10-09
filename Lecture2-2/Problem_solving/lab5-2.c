/*
* File: lab5-2.C
*
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Oct.08 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>

struct 
{
  int month;
  int day;
  int year;
}date;


/*
*
* void Days(int month, int day, int year)
*
* Summary of this function : 
*   This function calculates how many passed from the date 1/1/2000 to the date entered and 
*   return the value.
* 
*/
int Days(int month, int day ,int year){
  int tot_days = 0;
  tot_days += (year - 2000) * 360;
  tot_days += month * 30;
  tot_days += day;
  
  return tot_days;
}


/*
*
* void main()
*
* Summary of this function : 
*   This function receives a date and print the passed day using the Day() function.
* 
*/
void main(){
    printf("Type date (Month, Day, Year) : ");
    scanf("%d %d %d", &date.month, &date.day, &date.year);  
  
    printf("Days : %d", Days(date.month, date.day, date.year));
}