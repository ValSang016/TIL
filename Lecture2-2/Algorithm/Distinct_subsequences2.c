/*
*
* File : Distinct_subsequences.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Sep.25 2023
* Course : Algorithm
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*
* void processing(char X[], char Z[])
*
* Summary of this function : 
*   Make the array S for counting the number of occurrences of Z in X as a subsequence such 
*   that each has a distinct index sequence.
*
* Parameter : char array X, Z / get by pointer address
* Return value : result(the number of occurences of Z in X)
* 
*/
int processing(char X[], char Z[]){
  int x_len = strlen(X);
  int z_len = strlen(Z);

  long long *S = (long long*)malloc((z_len + 1) * sizeof(long long));

  for(int i=0; i <= z_len; i++) { // Set all elements of S to 0
    S[i] = 0;
  }
  S[0] = 1; // Set the first element of S to 1

  for (int i = 0; i < x_len; i++) // If X[i]=Z[j], then S[j+1] = S[j+1] + S[j]
  {                               // Z[j] corresponds to S[j+1]
    for (int j = z_len-1; j >= 0; j--)
    {
      if (X[i] != Z[j])
        continue;
      S[j+1] += S[j];
    }
  }
  int result = S[z_len]; //The last element of S is the number of occurences of Z in X

  free(S);

  return result;
}


/*
*
* void print_results(char result[], int num)
*
* Summary of this function : 
*   Print the result for all input value
*
* Parameter : int array result / get by pointer address
*             int num(the number of calculations)
* 
*/
void print_results(int result[], int num){
  for (int i = 0; i < num; i++)
  {
    printf("%dst result : %d\n", i+1, result[i]);
  }
}


/*
*
* void main()
*
* Summary of this function : 
*   This is the main function.
*   After entering the number of desired calculations, 
*   input X and Z as many times as that number and pass them to the processing function.
*
*/
void main(){
  char X[10000], Z[100];
  int num;

  printf("Enter a number of repeatation : ");
  scanf("%d", &num);

  int result[num];

  for (int i = 0; i < num; i++){
    printf("Enter the %dth X : ", i+1);
    scanf("%s", X);
    printf("Enter the %dth Z : ", i+1);
    scanf("%s", Z);
    result[i] = processing(X, Z);
  }
  print_results(result, num);
}

