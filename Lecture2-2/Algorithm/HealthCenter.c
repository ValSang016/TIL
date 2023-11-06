/*
*
* File : HealthCenter.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.06 2023
* Course : Algorithm
* Summary : This file contain solution code of the ploblem in the class.
*
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEALTH 100
#define MAX_INTER 500
#define MAX_ROAD 20
#define INFINITY 2000

void main()
{
  int num_intersection, num_healthCenter;
  int where_healthCenter[MAX_HEALTH];

  FILE *file;
  file = fopen("intersection3.txt", "r");

  //Managing error occured when the file is not found
  if (file == NULL){
    perror("Error opening file");
    exit(1);
  }

  //Roading contents of the number of health center and intersection in the file
  fscanf(file, "%d %d\n", &num_healthCenter, &num_intersection);

  //Managing the number of health center and intersection
  if(num_healthCenter>100 || num_intersection>500 || num_healthCenter>num_intersection){
    printf("The number of health center must be under 100 & the number of intersection.\n");
    printf("The number of intersection must be under 500.\n");
    exit(1);
  }

  //Get the information of locations in which there are health center
  for (int n = 0; n < num_healthCenter; n++){
    fscanf(file, "%d", &where_healthCenter[n]);
    where_healthCenter[n]--;
  }

  int adj[num_intersection][num_intersection];  //Adjacent & Cost matrix(If not neighbor, the cost is infinity)
  int D[num_intersection][num_intersection];  //Cheapest path from i to j for each all node
  int costToHC[num_intersection]; //Cost of path to health centers from each intersections
  int costToHC_newHC[num_intersection]; //When a new health center is established in each intersection, the cost of path to health centers from each intersections in each cases
  int i, j, c, k;

  //Reset the adjacent matrix to infinity
  for (i = 0; i < num_intersection; i++){
    for (j = 0; j < num_intersection; j++){
      adj[i][j] = INFINITY;
    }
  }

  //Save the cost of each edges
  while (fscanf(file, "%d %d %d\n", &i, &j, &c) != EOF){
    adj[i - 1][j - 1] = c;
    adj[j - 1][i - 1] = c;
  }
  fclose(file);

  //Create a new matrix to caculate cheapest cost
  int num_road;
  for (i = 0; i < num_intersection; i++){
    num_road = 0;
    for (j = 0; j < num_intersection; j++){
      if (i == j)
        D[i][j] = 0;
      else if (adj[i][j]){
        D[i][j] = adj[i][j];
        num_road++;
      }
      else
        D[i][j] = INFINITY;
    }
    if(num_road > MAX_ROAD){
    printf("The number of road of each intersection must be under 20.\n");
    exit(1);
    }
  }

  //Caculate the cheapest cost from all nodes to specific node
  for (k = 0; k < num_intersection; k++){
    for (i = 0; i < num_intersection; i++){
      for (j = 0; j < num_intersection; j++){
        if (D[i][j] > D[i][k] + D[k][j])
          D[i][j] = D[i][k] + D[k][j];
      }
    }
  }

  //Caculate the cost of path from each nodes to health center
  for (i = 0; i < num_intersection; i++){
    costToHC[i] = D[i][where_healthCenter[0]];
  }
  for (i = 0; i < num_intersection; i++){
    for (j = 1; j < num_healthCenter; j++){
      if (costToHC[i] > D[i][where_healthCenter[j]])
        costToHC[i] = D[i][where_healthCenter[j]];
    }
  }

  //Caculate the maximum cost of path from each nodes to health center when a new health center is established in each nodes
  int max_cost, max_idx;
  int temp[num_intersection];
  for (i = 0; i < num_intersection; i++){
    for (j = 0; j < num_intersection; j++){
      if (costToHC[j] > D[i][j])
        temp[j] = D[i][j];
      else
        temp[j] = costToHC[j];
    }

    max_cost = temp[0];
    costToHC_newHC[i] = temp[0];

    for (k = 1; k < num_intersection; k++)
    {
      if (max_cost < temp[k]){
        costToHC_newHC[i] = temp[k];
        max_cost = temp[k];
      }
    }
  }

  //Find the minimum cost and its index
  //So indicate what the case is efficient to establish the health center
  int min_cost = costToHC_newHC[0];
  int min_idx = 0;
  for (i = 1; i < num_intersection; i++)
  {
    if (costToHC_newHC[i]<min_cost){
      min_cost = costToHC_newHC[i];
      min_idx = i;
    }
  }
  
  //Print the number of intersection to establish health center
  printf("%d", min_idx+1);
}
