/*
*
* File : Savingink_kruskal.C
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

// Define a struct to store coordinates
struct DOT
{
  double x;
  double y;
};

// Define a struct to store edge information
struct EDGE
{
  int src, dest;
  double weight;
};

// Comparison function for qsort. Sorts by edge weight.
int compare(const void* a, const void* b)
{
  return ((struct EDGE*)a)->weight > ((struct EDGE*)b)->weight;
}

// Find function used in Union-Find algorithm. Finds the root node of i.
int find(int parent[], int i)
{
  if (parent[i] == i)
    return i;
  return find(parent, parent[i]);
}

// Union function used in Union-Find algorithm. Unites x and y into the same set.
void Union(int parent[], int x, int y)
{
  int xroot = find(parent, x);
  int yroot = find(parent, y);
  parent[xroot] = yroot;
}

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
  if(number <= 0 || number >= 30){
    perror("The number of dots is under 30, above 0.");
    exit(1);
  }
  // Declare arrays to store points and edges
  struct DOT dots[number];
  struct EDGE edges[number*number];
  int parent[number];

  // Read point coordinates
  for (int i = 0; i < number; i++)
  {
    fscanf(file, "%lf %lf", &(dots[i].x), &(dots[i].y));
  }

  // Store distances between all points as edges
  int edge_count = 0;
  for (int i = 0; i < number; i++)
  {
    for (int j = i+1; j < number; j++)
    {
      edges[edge_count].src = i;
      edges[edge_count].dest = j;
      edges[edge_count].weight = sqrt(pow(dots[i].x-dots[j].x, 2) + pow(dots[i].y-dots[j].y, 2));
      edge_count++;
    }
  }

  // Sort edges by weight
  qsort(edges, edge_count, sizeof(edges[0]), compare);

  // Initialize parent array
  for (int i = 0; i < number; i++)
    parent[i] = i;

  // Run Kruskal's algorithm
  double total_weight = 0;
  for (int i = 0; i < edge_count; i++)
  {
    int x = find(parent, edges[i].src);
    int y = find(parent, edges[i].dest);

    // If a cycle does not form, add the edge
    if (x != y)
    {
      total_weight += edges[i].weight;
      Union(parent, x, y);
    }
  }

  // Print the minimum cost
  printf("Minimum cost: %.2lf", total_weight);
}
