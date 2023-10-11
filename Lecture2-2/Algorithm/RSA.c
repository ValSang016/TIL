#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int gcd(long long int a, long long int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long p)
{
  unsigned long res = 1;
  x = x % p;

  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % p;

    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

long long int mod_exp(long long int a, long long int b, long long int n)
{
  long long int d = 1;
  while (b > 0)
  {
    if (b % 2 == 1)
    {
      d = (d * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return d;
}

void main()
{
  printf("Enter the value of P and Q: ");
  unsigned long P, Q, M, e = 2, n, d = 2, i, j;
  scanf("%lu %lu", &P, &Q);
  n = P * Q;

  unsigned pie_n = (P - 1) * (Q - 1);

  // e 구하기
  while (e < pie_n)
  {
    if (gcd(e, pie_n) == 1)
      break;
    else
      e++;
  }

  // d 구하기
  for (i = 2; i < pie_n; i++)
  {
    if ((e * i) % pie_n == 1)
      break;
    else
      d++;
  }

  printf("Enter the message to be encrypted: ");

  scanf("%lu", &M);

  // 암호화 과정 추가
  unsigned long C = (unsigned long long)pow(M, e) % n;
  // unsigned long C = power(M,e,n);

  unsigned long d_before = d;
  d = mod_exp(C, d, n);
  // 복호화 과정 추가
  unsigned long decrypted_message = (unsigned long long)pow(C, d) % n;
  // unsigned long decrypted_message = power(C, d, n);
  printf("Decrypted message: %lu\n", decrypted_message);

  printf("P(%lu, %lu, S(%lu, %lu), Cyphertext : %lu", e, n, d_before, n, C);
}
