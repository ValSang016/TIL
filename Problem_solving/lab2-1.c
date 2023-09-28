#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BAR 0
#define BELL 1
#define LEMON 2
#define CHERRY 3
#define RMAX 4

void slot(int *slot1, int *slot2, int *slot3){
  srand(time(NULL)); // 난수 초기화
	*slot1 = rand() % RMAX; // 0~3 중의 하나 생성
  *slot2 = rand() % RMAX;
  *slot3 = rand() % RMAX;
}

void main(){
  int slot1 = 0, slot2 = 0, slot3 = 0;
  char m[4][6] = {"BAR", "BELL", "LEMON", "CHERRY"};
  slot(&slot1, &slot2, &slot3);
  printf("%s %s %s\n", m[slot1], m[slot2], m[slot3]);

  
  if(slot1==slot2 && slot2==slot3 && slot1 == CHERRY)
    printf("Congratulations On A Jackpot!");
  else if(slot1 == CHERRY || slot2 == CHERRY || slot3 == CHERRY)
    printf("Dime!");
  else if(slot1==slot2 && slot2==slot3)
    printf("Nickel!");
  else
    printf("Sorry. Better luck next time");
}
