#include<stdio.h>
#include<stdlib.h>

long long int gcd(long long int a,long long int b){
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

long long int power(long long int x,long long unsigned y,long long p){
    long long res = 1;
    x = x % p; 
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}

void main(){
   printf("Enter the value of P and Q: ");
   unsigned long P, Q, M, e=2, n, d=2, i, j;
   scanf("%lu %lu",&P,&Q);
   n=P*Q;

   unsigned phi=(P-1)*(Q-1);

   while(e<phi){
      if(gcd(e,phi)==1)
         break;
      else
         e++;
   }

   for(i=2;i<phi;i++){
      if((e*i)%phi==1)
         break;
      else
         d++;
   }

   printf("Enter the message to be encrypted: ");
   
   scanf("%lu",&M);

// 암호화 과정 추가
unsigned long C = power(M, e, n);

// 복호화 과정 추가
unsigned long decrypted_message = power(C, d, n);
printf("Decrypted message: %lu\n", decrypted_message);

printf("P(%d, %d), S(%d, %d), Cyphertext : %lu", e, n, d, n, C);

}
