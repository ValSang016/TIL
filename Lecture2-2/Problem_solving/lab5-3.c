/*
* File: lab5-3.C
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
* int recent(int month1, int day1 ,int year1, int month2, int day2, int year2)
*
* Summary of this function : 
*   This function calculates which date is the later date. If date1 is later than date2, return 
*   date1.
* 
*/
int recent(int month1, int day1 ,int year1, int month2, int day2, int year2){
  int max = 0;
  if(year1 != year2){
    if (year1 > year2)
      return 1;
    else
      return 2;
  } else if (month1 != month2){
    if (month1 > month2)
      return 1;
    else
      return 2;
  } else if (day1 != day2) {
    if (day1 > day2)
      return 1;
    else
      return 2;
  } else {
    return 1;
  }
}


/*
*
* void main()
*
* Summary of this function : 
*   This function receives two dates and print the later date using the recent() function.
* 
*/
void main(){
  int month1, day1, year1, month2, day2, year2;
  int result;
  printf("Type date (Month, Day, Year) : ");
  scanf("%d %d %d", &month1, &day1, &year1);
  printf("Type date (Month, Day, Year) : ");
  scanf("%d %d %d", &month2, &day2, &year2); 
  
  result = recent(month1, day1, year1, month2, day2, year2);
  
  if (result == 1){
    date.month = month1;
    date.day = day1;
    date.year = year1;
  }else if (result == 2){
    date.month = month2;
    date.day = day2;
    date.year = year2;
  }
  
  printf("%d/%d/%d", date.month, date.day, date.year);

}