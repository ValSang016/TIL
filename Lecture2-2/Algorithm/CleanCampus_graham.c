#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining the structure for points
typedef struct Point {
    double x, y;
} Point;

Point p0; // Reference point

Point points[100]; // Array of points

// Function to swap the position of two points
void swap(Point *p1, Point *p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to calculate the square of the distance between two points
double distSq(Point p1, Point p2) {
    return pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
}

// Function to determine the direction of the angle formed by points p, q, r
int orientation(Point p, Point q, Point r) {
    // (x2-x1)(y3-y2)-(y2-y1)(x3-x2) = x1y2 + x2y3 + x3y1 - (x1y3 + x2y1 + x3y2)
    double val = (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x);
    if (val == 0) return 0; // Three points are collinear
    return (val > 0) ? 1 : 2; // 1 = counterclockwise, 2 = clockwise
}

// Function to compare two points with respect to p0
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    int o = orientation(p0, *p1, *p2);
    if (o == 0) {
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    }
    return (o == 2) ? 1 : -1;
}

// Function to execute the Graham scan algorithm
void grahamScan(Point points[], int n) {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        double y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    swap(&points[0], &points[min]);
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);
    
    if (n < 3) return; // If less than three points, no convex hull can be formed
    Point stack[n]; // Stack to store points of the convex hull
    int top = -1;
    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];
    for (int i = 3; i < n; i++) {
        while (orientation(stack[top - 1], stack[top], points[i]) != 2){
          if ((points[i].x == 0 && points[i].y == 0) || (stack[top-1].x == 0 && stack[top-1].y == 0) || (stack[top].x == 0 && stack[top].y == 0))
            break; // If the point is (0, 0), break
          top--;
        }
        stack[++top] = points[i];
    }
    double perimeter = 0;
    for (int i = 0; i <= top-1; i++) {
        perimeter += sqrt(distSq(stack[i], stack[i+1])); // Calculating the perimeter of the convex hull
    }
    perimeter += sqrt(distSq(stack[0], stack[top])); // Adding the distance between the last and first point
    printf("%.2f\n", perimeter+2);
}

int main()
{
  FILE *file;
  file = fopen("frosh.txt", "r"); // Opening the file
  if (file == NULL)
  {
    perror("Not found file");
    exit(1);
  }

  int T;
  fscanf(file, "%d", &T); // Reading the number of test cases

  for (int t = 0; t < T; t++)
  {
    int n;
    fscanf(file, "%d", &n); // Reading the number of points for each test case
    
    for (int i = 0; i < n; i++)
    {
      fscanf(file, "%lf %lf", &points[i].x, &points[i].y); // Reading the coordinates of the points
    }
    points[n+1].x = 0, points[n+1].y = 0;
    grahamScan(points, n+1); // Executing the Graham scan algorithm
    if (t != T - 1)
      printf(""); // Printing blank space between test cases
  }

  return 0;
}
