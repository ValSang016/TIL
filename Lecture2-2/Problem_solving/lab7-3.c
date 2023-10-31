#include <stdio.h>
#define MAX 5

//정한 인덱스까지의 함
int sum_of(int a[], int n){
  if(n < 1 || n > MAX){
    printf("array boundary error");
    return -1;
  } else {
    if (n == 1)
      return a[0];
    else 
      return (a[n-1] + sum_of(a, n-1));
  }
}

void main(){
  int result;
  int array[MAX] = {3, 4, 1, 2, 6};

  result = sum_of(array, 3);
  printf("%d", result);
}