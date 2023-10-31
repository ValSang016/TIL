#include <stdio.h>

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long p)
{
  unsigned long res = 1;
  x = x % p;

  while (y > 0)
  {
    res = (res*res)%p;
    if (y & 1)
      res = (res * x) % p;

    y = y >> 1;
    
  }
  return res;
}

void main(){

  power(66, 77, 119);
  int m, n = 119;
  gets(m);
  printf("%d", m*m %119);
}