#include <stdio.h>
#include <stdlib.h>

long long extended_gcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    else {
        long long x1, y1;
        long long gcd = extended_gcd(b, a % b, &x1, &y1);

        // Update x and y using the results of recursive call
        *x = y1;
        *y = x1 - (a / b) * y1;

        return gcd;
    }
}

int main() {

	int A = 21, B = 30; 
	// scanf("%d %d",&A,&B);
	
	double k, x,y;


  long long x_prime=0, y_prime=0; // 변수 초기화
  long long x_tmp=0, y_tmp=0; // 변수 초기화
  int min = 0;

	x_prime=(double)A; y_prime=(double)B;

	double gcd=extended_gcd(A, B, &x_prime, &y_prime);


	// k = my_round(temp_x/(double)B);


  min = abs(x_prime) + abs(y_prime);

  for (int i = 1 ;; i++)
  {
    x_tmp = x_prime-(i*(double)B/gcd);
    y_tmp = y_prime+(i*(double)A/gcd);

    if(abs(x_tmp)+abs(y_tmp) < min){
      min = abs(x_tmp)+abs(y_tmp);
    }else{
      x_tmp = x_prime-((i-1)*(double)B/gcd);
      y_tmp = y_prime+((i-1)*(double)A/gcd);
      break;
    }
  }

  for (int i = -1 ;; i--){
    x_tmp = x_prime-(i*(double)B/gcd);
    y_tmp = y_prime+(i*(double)A/gcd);

    if(abs(x_tmp)+abs(y_tmp) < min){
      min = abs(x_tmp)+abs(y_tmp);
    }else{
      x_tmp = x_prime-((i+1)*(double)B/gcd);
      y_tmp = y_prime+((i+1)*(double)A/gcd);
      break;
    }
  }
  x = x_tmp, y=y_tmp;

	printf("X: %.2lf , Y: %.2lf , D(GCD): %.2lf\n",x,y,gcd);
	
	return 0;
}
