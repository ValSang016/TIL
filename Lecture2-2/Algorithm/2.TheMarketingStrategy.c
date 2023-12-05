#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 30
#define INFINITY 10000.0

typedef struct Point
{
  int x, y;
} Point;

Point points[MAX_POINTS];

int compareX(const void *a, const void *b)
{
  Point *p1 = (Point *)a, *p2 = (Point *)b;
  return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
  Point *p1 = (Point *)a, *p2 = (Point *)b;
  return (p1->y - p2->y);
}

double dist(Point p1, Point p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(Point P[], int l, int r)
{
  double min = INFINITY;
  for (int i = l; i <= r; ++i)
    for (int j = i + 1; j <= r; ++j)
      if (dist(P[i], P[j]) < min)
        min = dist(P[i], P[j]);
  return min;
}

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

double closestPair(Point P[], int l, int r)
{
  if (r - l < 3)
    return bruteForce(P, l, r);
  int q = (l + r) / 2;
  double dl = closestPair(P, l, q - 1);
  double dr = closestPair(P, q, r);
  double d = (dl < dr) ? dl : dr;
  Point strip[MAX_POINTS];
  int j = 0;
  for (int i = l; i <= r; i++)
    if (P[i].x >= P[q].x - d && P[i].x <= P[q].x + d)
      strip[j] = P[i], j++;
  d = (d < stripClosest(strip, j, d)) ? d : stripClosest(strip, j, d);
  return d;
}

double closest(Point P[], int n)
{
  qsort(P, n, sizeof(Point), compareX);
  return closestPair(P, 0, n - 1);
}

int main()
{
  int N;
  FILE *file;
  file = fopen("location.txt", "r");
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
