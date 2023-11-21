/*
*
* File : LabTest.C
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

#define MAX_POINTS 30
#define INFINITY 10000.0

// Define a Point structure
typedef struct Point
{
  int x, y;
} Point;

// Array to store points
Point points[MAX_POINTS];

// Function to compare x-coordinates of two points
int compareX(const void *a, const void *b)
{
  Point *p1 = (Point *)a, *p2 = (Point *)b;
  return (p1->x - p2->x);
}

// Function to compare y-coordinates of two points
int compareY(const void *a, const void *b)
{
  Point *p1 = (Point *)a, *p2 = (Point *)b;
  return (p1->y - p2->y);
}

// Function to calculate the distance between two points
double dist(Point p1, Point p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the smallest distance using brute force for small arrays
double bruteForce(Point P[], int n)
{
  double min = INFINITY;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (dist(P[i], P[j]) < min)
        min = dist(P[i], P[j]);
  return min;
}

// Function to find the smallest distance in the strip of points close to the median line
double stripClosest(Point strip[], int size, double d)
{
  double min = d;
  qsort(strip, size, sizeof(Point), compareY);
  for (int i = 0; i < size; ++i)
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
      if (dist(strip[i], strip[j]) < min)
        min = dist(strip[i], strip[j]);
  return min;
}

// Recursive function to find the smallest distance
double closestUtil(Point P[], int n)
{
  if (n <= 3)
    return bruteForce(P, n);
  int mid = n / 2;
  Point midPoint = P[mid];
  double dl = closestUtil(P, mid);
  double dr = closestUtil(P + mid, n - mid);
  double d = (dl < dr) ? dl : dr;
  Point strip[n];
  int j = 0;
  for (int i = 0; i < n; i++)
    if (abs(P[i].x - midPoint.x) < d)
      strip[j] = P[i], j++;
  return (d < stripClosest(strip, j, d)) ? d : stripClosest(strip, j, d);
}

// Main function to find the smallest distance
double closest(Point P[], int n)
{
  qsort(P, n, sizeof(Point), compareX);
  return closestUtil(P, n);
}

// Main function to read points from a file and print the smallest distance
int main()
{
  int N;
  FILE *file;
  file = fopen("location.txt", "r"); // Opening the file
  if (file == NULL)
  {
    perror("Not found file");
    exit(1);
  }
  while (fscanf(file, "%d", &N) != EOF && N != 0)
  {
    for (int i = 0; i < N; ++i)
      fscanf(file, "%d %d", &points[i].x, &points[i].y);
    double result = closest(points, N);
    if (result >= INFINITY)
      printf("Infinity");
    else
      printf("%.2f", result);
  }
  return 0;
}
