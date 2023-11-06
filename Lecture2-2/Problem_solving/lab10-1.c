#include <stdio.h>

struct CAR
{
  char name[20];
  int year;
  double price;
} car[4];

void main()
{
  car[0] = (struct CAR){"Avante", 2007, 13000.00};
  car[1] = (struct CAR){"Sonata", 2008, 18000.00};
  car[2] = (struct CAR){"SM7", 2009, 22000.00};
  car[3] = (struct CAR){"Sonata", 2008, 35000.00};

  FILE *outFile;
  outFile = fopen("cars.txt", "w");
  for (int i = 0; i < 4; i++)
  {
    fprintf(outFile, "%s %d %.2f\n", car[i].name, car[i].year, car[i].price);
  }
  fclose(outFile);

  char name[20];
  int year;
  double price;

  FILE *inFile;
  inFile = fopen("cars.txt", "r");
  printf("---------------------------\n");
  printf("|Name      |Year    |Price  |\n");
  printf("---------------------------\n");
  for (int i = 0; i < 4; i++)
  {
    fscanf(inFile, "%s %d %lf", name, &year, &price);
    printf("|  %s  |  %d  |  %lf  |\n", name, year, price);
  }
  printf("---------------------------\n");
}