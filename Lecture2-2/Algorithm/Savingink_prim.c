/*
*
* File : Savingink_prim.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.23 2023
* Course : Algorithm
* Summary : This file contain code that Lab test in the class.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

// Define a struct to store coordinates
struct DOT
{
  double x;
  double y;
};


void main(){
  FILE* file;
  // Open file
  file = fopen("dataset.txt", "r");
  if (file == NULL)
  {
    perror("Not found the file");
    exit(1);
  }
  
  int number; 
  // Read the number of points
  fscanf(file, "%d", &number);
  // If the number of points is 0 or greater than or equal to 30, print an error message and exit
  if(number <= 0 || number >= 30){
    perror("The number of dots is under 30, above 0.");
    exit(1);
  }
  // Declare arrays to store points and distances
  struct DOT dots[number];
  double adjacent[number][number];
  int parent[number]; 
  double key[number];   
  bool mstSet[number];  

  // Read the coordinates of points
  for (int i = 0; i < number; i++)
  {
    fscanf(file, "%lf %lf", &(dots[i].x), &(dots[i].y));
  }

  // Calculate the distance between all points
  for (int i = 0; i < number; i++)
  {
    for (int j = 0; j < number; j++)
    {
      adjacent[i][j] = sqrt(pow(dots[i].x-dots[j].x, 2) + pow(dots[i].y-dots[j].y, 2));
    }
  }

  // Initialize the key and Stack set arrays
  for (int i = 0; i < number; i++)
  {
    key[i] = INT_MAX, mstSet[i] = false;
  }

  // Select the first point
  key[0] = 0;     
  parent[0] = -1; 

  // Run Prim's algorithm
  for (int count = 0; count < number-1; count++)
  {
    int min = INT_MAX, min_index;
    
    // Find the point not yet included in MST that has the smallest key value
    for (int v = 0; v < number; v++)
      if (mstSet[v] == false && key[v] < min)
          min = key[v], min_index = v;

    int u = min_index;

    // Include the found point in MST
    mstSet[u] = true;

    // Update key values of points adjacent to the found point
    for (int v = 0; v < number; v++)
      if (adjacent[u][v] && mstSet[v] == false && adjacent[u][v] < key[v])
        parent[v] = u, key[v] = adjacent[u][v];
  }

  // Calculate the length of MST
  double total_distance = 0;
  for (int i = 1; i < number; i++)
    total_distance += adjacent[i][parent[i]];

  // Print the length of MST
  printf("Minimum cost: %.2lf", total_distance);
}
