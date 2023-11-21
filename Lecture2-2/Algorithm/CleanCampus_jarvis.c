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

// Creating a structure to store the points
typedef struct Point
{
  double x, y;
} Point;

// An array to hold the points
Point points[100];

// Function to compute the euclidean distance between two points
double computeDistance(Point a, Point b)
{
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to compute the angle between two points
double computeAngle(Point A, Point B)
{
  double Dx, Dy, Angle;
  Dx = B.x - A.x;
  Dy = B.y - A.y;
  if ((Dx >= 0) && (Dy == 0))
    Angle = 0;
  else
  {
    Angle = fabs(Dy) / (fabs(Dx) + fabs(Dy));
    if ((Dx < 0) && (Dy >= 0))
      Angle = 2 - Angle;
    else if ((Dx <= 0) && (Dy < 0))
      Angle = 2 + Angle;
    else if ((Dx > 0) && (Dy < 0))
      Angle = 4 - Angle;
  }
  return (Angle * 90.0);
}

// Function to compare two points, used for sorting
int compare(const void *a, const void *b)
{
  Point *p1 = (Point *)a;
  Point *p2 = (Point *)b;
  double angle1 = computeAngle(points[0], *p1);
  double angle2 = computeAngle(points[0], *p2);

  if (angle1 < angle2)
    return -1;
  if (angle1 > angle2)
    return 1;

  // When angle of two points, return 1 if the distance of point1 is lager than the point2, otherwise return -1
  double dist1 = computeDistance(points[0], *p1);
  double dist2 = computeDistance(points[0], *p2);
  return (dist1 > dist2) - (dist1 < dist2);
}

// Function to compute the convex hull
void convexHull(Point points[], int n)
{
  if (n < 3)
    return;
  qsort(points + 1, n - 1, sizeof(Point), compare);

  // Loop to keep the farthest point among the points with the same angle
  int m = 1;
  for (int i = 1; i < n; i++)
  {
    while (i < n - 1 && computeAngle(points[0], points[i]) == computeAngle(points[0], points[i + 1]))
    {
      i++;
    }
    points[m++] = points[i];
  }

  Point p = points[0], q;
  Point stack[m];
  int top = 0;
  int inStackIdx[m];
  int minIdx;

  stack[top] = p;

  // Main loop to find the convex hull
  // inStackIdx don't contain p(0, 0) because of condition that the loop finish
  do
  {
    double minAngle = 400, minDist = 1e9;
    for (int i = 0; i < m; i++)
    {
      int flag = 0;
      for (int j = 0; j < top; j++)
      {
        if (i == inStackIdx[j])
        {
          flag = 1;
          break;
        }
      }
      if (flag)
        continue;

      double angle;

      // Caculate the relative angle
      if (top < 2)
        angle = fmod((360 + computeAngle(p, points[i]) - computeAngle(p, stack[top])), 361);
      else
        angle = fmod((360 + computeAngle(p, points[i]) - computeAngle(p, stack[top - 1])), 361);
      if (angle < minAngle)
      {
        minAngle = angle;
        minIdx = i;
        q = points[i];
      }
    }
    inStackIdx[top++] = minIdx;
    stack[top] = q;
    p = q;
  } while (!(p.x == 0 && p.y == 0));

  // Computing the perimeter of the convex hull
  double perimeter = 0;
  double dx, dy, distance;
  for (int i = 0; i < top; i++)
  {
    dx = stack[i].x - stack[(i + 1) % (top + 1)].x;
    dy = stack[i].y - stack[(i + 1) % (top + 1)].y;
    distance = sqrt(dx * dx + dy * dy);
    perimeter += distance;
  }
  dx = stack[0].x - stack[top].x;
  dy = stack[0].y - stack[top].y;
  distance = sqrt(dx * dx + dy * dy);
  perimeter += distance;
  printf("%.2f", perimeter + 2);
}

// Main function to read the points and compute the convex hull
int main()
{
  FILE *file;
  file = fopen("frosh.txt", "r");
  if (file == NULL)
  {
    perror("Not found file");
    exit(1);
  }
  int T;
  fscanf(file, "%d", &T);
  for (int t = 0; t < T; t++)
  {
    int n;
    fscanf(file, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
      fscanf(file, "%lf %lf", &points[i].y, &points[i].x);
    }
    points[0].x = 0, points[0].y = 0;
    convexHull(points, n + 1);
    if (t != T - 1)
      printf("\n");
  }
  fclose(file);
  return 0;
}
