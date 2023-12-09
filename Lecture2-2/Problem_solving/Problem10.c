/*
*
* File : Problem10.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.06 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>
#include <stdlib.h>

/*
*
* void main()
*
* Summary of this function : 
*   This function first loads contents of a file. And this calculates averages of groups.
*
*/
void main()
{
  FILE *inFile;
  inFile = fopen("numbers.txt", "r");
  int num_entity, num_group = 1; //num_entity : The first number that indicate how many entities  
                                 //next there is.
  if (inFile == NULL) //Processing exception
  {
    printf("Input File Could Not Be Opened.");
    exit(1);
  }
  
  while (fscanf(inFile, "%d", &num_entity) == 1) //Caculate until empty
  {
    double sum = 0, k;
    int count = 0;
    for (int i = 0; i < num_entity; i++)
    {
      fscanf(inFile, "%lf", &k);
      sum += k;
      count++;
    }
    printf("Group %d average : %.2f\n", num_group, sum / count);
    num_group++;
  }
}