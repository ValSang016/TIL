/*
*
* File : LabTest.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Oct.12 2023
* Course : Algorithm
* Summary : This file contain code that Lab test in the class.
*
*/

#include <stdio.h>
#include <stdlib.h>

int findLeastSum(int **dp, int **table, int i, int j, int r, int c)
{
  int min;

  if (j == 0)
  {
    min = table[j][i] + dp[r - 1][i - 1];

    if (min > table[j][i] + dp[j][i - 1])
      min = table[j][i] + dp[j][i - 1];

    if (min > table[j][i] + dp[(r + j + 1) % r][i - 1])
      min = table[j][i] + dp[(r + j + 1) % r][i - 1];
  }

  else if (j == r - 1)
  {
    min = table[j][i] + dp[(r + j - 1) % r][i - 1];

    if (min > table[j][i] + dp[j][i - 1])
      min = table[j][i] + dp[j][i - 1];

    if (min > table[j][i] + dp[0][i - 1])
      min = table[j][i] + dp[0][i - 1];
  }

  else
  {
    min = table[j][i] + dp[(r + j - 1) % r][i - 1];

    if (min > table[j][i] + dp[j][i - 1])
      min = table[j][i] + dp[j][i - 1];

    if (min > table[j][i] + dp[(r + j + 1) % r][i - 1])
      min = table[j][i] + dp[(r + j + 1) % r][i - 1];
  }
  return min;
}

void makeSumTable(int **dp, int **table, int r, int c)
{
  int i, j;

  for (i = 1; i < c; i++)
  {
    for (j = 0; j < r; j++)
      dp[j][i] = findLeastSum(dp, table, i, j, r, c);
  }
}

int findLeastestSequence(int **p_table, int **table, int r, int c)
{
   int tmpV, result;
  int *stack, min, tmpI = 0, tmpJ = c - 1;

  stack = (int *)malloc(sizeof(int) * c);

  // Initialize min value, value of first row and last column  in dp
  min = p_table[0][c - 1];
  stack[c - 1] = table[0][c - 1];
  // find min value in last the column, store the table value in stack
  for (int i = 1; i < r; i++)
  {
    if (p_table[i][c - 1] < min)
    {
      min = p_table[i][c - 1];
      stack[c - 1] = table[i][c - 1];
      tmpI = i;
      tmpJ = c - 1;
    }
  }
  printf("%d", min);

 

  // Find sequence
  for (int j = tmpJ; j >= 0; j--)
  {
    if (j != tmpJ)
      tmpI = tmpV;
    if (tmpI == 0)
    {
      min = p_table[r - 1][j - 1];
      tmpV = r - 1;
      if (p_table[tmpI][j - 1] < min)
      {
        min = p_table[tmpI][j - 1];
        tmpV = tmpI;
      }
      if (p_table[(tmpI + 1 + r) % r][j - 1] < min)
      {
        min = p_table[tmpI][j - 1];
        tmpV = (tmpI + 1 + r) % r;
      }
    }
    else if (tmpI == r - 1)
    {
      min = p_table[(tmpI - 1 + r) % r][j - 1];
      tmpV = (tmpI - 1 + r) % r;

      if (p_table[tmpI][j - 1] < min)
      {
        min = p_table[tmpI][j - 1];
        tmpV = tmpI;
      }
      if (p_table[0][j - 1] < min)
      {
        min = p_table[0][j - 1];
        tmpV = 0;
      }
    }
    else
    {
      min = p_table[(tmpI - 1 + r) % r][j - 1];
      tmpV = (tmpI - 1 + r) % r;
      if (p_table[tmpI][j - 1] < min)
      {
        min = p_table[tmpI][j - 1];
        tmpV = tmpI;
      }
      if (p_table[(tmpI + 1 + r) % r][j - 1] < min)
      {
        min = p_table[(tmpI + 1 + r) % r][j - 1];
        tmpV = (tmpI + 1 + r) % r;
      }
    }
    stack[j - 1] = table[tmpV][j - 1];
  }
  for (int t = 0; t < c; t++)
  {
    printf("%d ", stack[t]);
  }
  return stack;
}

int main()
{
  int repeat;
  printf("Enter the number of repeatations :");
  scanf("%d", &repeat);

  for (int i = 0; i < repeat; i++)
  {
    int row, column, result;
    int **table, **dp;
    printf("Enter the rows and columns : ");
    scanf("%d %d", &row, &column);
    table = (int **)malloc(sizeof(int *) * row);
    dp = (int **)malloc(sizeof(int *) * row);

    for (int i = 0; i < row; i++)
    {
      table[i] = (int *)malloc(sizeof(int) * column);
      dp[i] = (int *)malloc(sizeof(int) * column);
    }

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        scanf("%d", &table[i][j]);

        if (j == 0)
        {
          dp[i][0] = table[i][0]; // Duplicate to dp only a first column
        }
      }
      printf("\n");
    }

    makeSumTable(dp, table, row, column); // Sum table(smallest) = dp table

    int *stack = findLeastestSequence(dp, table, row, column);

    result = 0;
  }

  return 0;
}