#include <stdio.h>

int maxage = -1, minage = 1000;
int maxscore = -1, minscore = 1000;
int maxagecnt, minagecnt, maxscorecnt, minscorecnt;
int age[100], maxagegrp[100], minagegrp[100];
int score[100], maxscoregrp[100], minscoregrp[100];

int score[100], age[100];

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
    if(score[i] > maxscore){
      maxscore = score[i];
      maxscorecnt = 0;
      maxscoregrp[maxscorecnt] = i;
    } else if (score[i]==maxscore){
      maxscorecnt += 1;
      maxscoregrp[maxscorecnt] = i;
    }
  }
}

void findMinScore(){
    for(int i = 0; i < 100; i++){
    if(score[i] < minscore){
      minscore = score[i];
      minscorecnt = 0;
      minscoregrp[minscorecnt] = i;
    } else if (score[i]==minscore){
      minscorecnt += 1;
      minscoregrp[minscorecnt] = i;
    }
  }
}

void read_file(){
  FILE *age_list, *score_list;
  age_list = fopen("age-list.txt", "r");
  score_list = fopen("score-list.txt", "r");
  for (int i = 0; i < 100 && !feof(age_list); i++) {
        fscanf(age_list, "%d", &age[i]);
    }
  for (int i = 0; i < 100 && !feof(score_list); i++) {
        fscanf(score_list, "%d", &score[i]);
    }
}
void print_board(int cnt, int grp[]){
  printf("idx   Age  Score\n");
  for (int i = 0; i <= cnt; i++)
  {
    if(!grp)
      break;
    printf(" %d   %d   %d \n", grp[i], age[grp[i]], score[grp[i]]);
  }
}

void main(){
  read_file();
  findMaxAge();
  findMinAge();
  findMaxScore();
  findMinScore();
  printf("Score of oldest student\n");
  print_board(maxagecnt, maxagegrp);
  printf("\nScore of youngest student\n");
  print_board(minagecnt, minagegrp);
  printf("\nAge of highest score student\n");
  print_board(maxscorecnt, maxscoregrp);
  printf("\nAge of lowest score student\n");
  print_board(minscorecnt, minscoregrp);
}
