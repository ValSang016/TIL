#include <stdio.h>

int maxage = -1, minage = 1000;
int maxscore = -1, minscore = 1000;
int maxagecnt, minagecnt, maxscorecnt, minscorecnt;
int age[100], maxagegrp[100], minagegrp[100];
int score[100], maxscoregrp[100], minscoregrp[100];

char score[100], age[100];

void findMaxAge(){
  for(int i = 0; i < 100; i++){
    if(age[i] > maxage){
      maxage = age[i];
      maxagecnt = 0;
      maxagegrp[maxagecnt] = i;
    } else if (age[i]==maxage){
      maxagecnt += 1;
      maxagegrp[maxagecnt] = i;
    }
  }
}

void findMinAge(){
    for(int i = 0; i < 100; i++){
    if(age[i] < minage){
      minage = age[i];
      minagecnt = 0;
      minagegrp[minagecnt] = i;
    } else if (age[i]==minage){
      minagecnt += 1;
      minagegrp[minagecnt] = i;
    }
  }
}

void findMaxScore(){
    for(int i = 0; i < 100; i++){
    if(age[i] > maxscore){
      maxscore = age[i];
      maxscorecnt = 0;
      maxscoregrp[maxscorecnt] = i;
    } else if (age[i]==maxscore){
      maxscorecnt += 1;
      maxscoregrp[maxscorecnt] = i;
    }
  }
}

void findMinScore(){
    for(int i = 0; i < 100; i++){
    if(age[i] > minscore){
      minscore = age[i];
      minscorecnt = 0;
      minscoregrp[minscorecnt] = i;
    } else if (age[i]==minscore){
      minscorecnt += 1;
      minscoregrp[minscorecnt] = i;
    }
  }
}

void main(){
  FILE *age_list, *score_list;
  age_list = fopen("age-list.txt", "r");
  score_list = fopen("score-list.txt", "r");
  while(!feof(age_list))  // 파일의 끝이 아니라면
   {
       fgets(age, 2, age_list);  // 최대 80칸짜리 한줄 읽기
       puts(age);  // 한줄 출력
       printf("%d%n", age);
   }
 
   fclose(age_list);
}
