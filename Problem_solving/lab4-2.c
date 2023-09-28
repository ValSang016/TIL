/*
*
* File : Lab2-2.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Sep.25 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>


/*
*
* void calculate(int val1, int val2, int *re1, int *re2, int *re3, int *re4)
*
* Summary of this function : 
*   This function calculates multipulation, division, remainder, plus of two values.
*
* Parameter : int val1, int val2, int *re1, int *re2, int *re3, int *re4 / By pointer
* 
*/
void calculate(int val1, int val2, int *re1, int *re2, int *re3, int *re4){
  *re1 = val1*val2;
  *re2 = val1/val2;
  *re3 = val1%val2;
  *re4 = val1+val2;
}


/*
*
* void main()
*
* Summary of this function : 
*   Input 2 values and Pass 6 parameters to the calcaulate function.
*   And prints the result.
* 
*/
void main(){
  int val1, val2;
  int re1, re2, re3, re4;

  scanf("%d %d", &val1, &val2);
  calculate(val1, val2, &re1, &re2, &re3, &re4);

  printf("%d %d %d %d", re1, re2, re3, re4);
}