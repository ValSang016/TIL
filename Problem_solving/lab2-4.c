/*
*File: lab2-1.C
*
*Summary of file:
*This file is program that converts mile to km.
*This program gets five inputs as miles from user and returns five outputs by km.
*
*
*/


#include <stdio.h>
#define MAXNUM 5

void main(){
  void mile2km(float local_array[]);
  float miles[MAXNUM];
  float mile;
  for(int i=0; i<MAXNUM; i++){
    printf("\nEnter the miles : ");
    scanf("%f", &mile);
    miles[i] = mile;
  }
  mile2km(miles);
}

/*
*
*void mile2km(float local_array[])
*
*Summary of this function:
* This function changes mile array to km values.
*
* Parameters : array - containing float num
*
* Return value : none
*
*/
void mile2km(float local_array[]){
  for (int i = 0; i < MAXNUM; i++)
  {
    float km = local_array[i] * 1.6093;
    printf("%.4f mile is same with %.4f km.\n", local_array[i], km);
  }
}
