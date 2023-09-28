#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 1000


//Example3
void main(){
  void findmax(int [MAXNUM]);
  int numList[MAXNUM];
  srand(time(NULL));
  for(int i = 0; i < MAXNUM; i++){
    numList[i] = 1 + rand() % MAXNUM;
  }
  findmax(numList);
}

void findmax(int local_array[])
{
  int i, max = local_array[0];

  for(i=1; i<MAXNUM; i++){
    if(max < local_array[i])
      max = local_array[i];
  }
  printf("%d", max);
}