#include <stdio.h>
#include <stdlib.h>

void main()
{
  int *nums;
  nums = (int *)malloc(10 * sizeof(int));

  if (nums == (int *)NULL)
  {
    printf("malloc failed");
    exit(1);
  }
  
  for (int i = 0; i < 10; i++)
  {
    nums[i] = i+10;
  }
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", *nums++);
  }
}