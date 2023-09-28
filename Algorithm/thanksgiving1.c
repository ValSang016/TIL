#include <stdio.h>


int processing(int average){
  return average - (average % 10);
}


int caculate(int array[], int num){
  int ex = 0, average = 0, sum = 0;
  for (int i = 0; i < num; i++)
  {
    sum += array[i];
  }
  average = sum / num;
  average = processing(average);
  for (int i = 0; i < num; i++)
  {
    if(array[i] < average){
      ex += (average-array[i]);
    }
  }
  return ex;
}

int input(int exchange[]){
  int num = 0, trips = 0;
  for (int k = 0; k < 100; k++){
    printf("Enter a number of student on the trip.\n");

    scanf("%d", &num);
    if(num == 0){
      break;
    }else{
      int array[100];
      int charge = 0;
      for (int i = 0; i < num; i++)
      {
        printf("Enter the money spent by each student separately.");
        scanf("%d", &charge);
        array[i] = charge;
      }
      exchange[k] = caculate(array, num);
      trips++;
    }
  }
  return trips;
}



void main(){
  int exchange[100];
  int trips = input(exchange);
  for (int i = 0; i < trips; i++)
  {
    printf("%d\n", exchange[i]);
  }
}