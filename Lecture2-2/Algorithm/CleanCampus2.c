#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_FROSH 100

// 스타팅 포인트 지정
// 테스트 케이스 변수
// 신입생 수 변수 
// 신입생 위치 array(100명) (2차원 / 행: 신입생 index / 열: x,y 좌표)
// 앵글이 작은 순서를 저장할 array(신입생의 index만 저장)

// 앵글 계산 + 최소 앵글 찾고 + 저장하는 함수
// 앵글이 작은 순서에 따라 array를 불러와서 줄의 길이를 계산하는 함수

int caculateAngle(){

}

void findMinAngle(int froshNum, int whereFrosh[MAX_FROSH+1][2], int sequence[MAX_FROSH+1]){
  //첫지점에서 각 지점에 대한 앵글을 모두 계산 후 최소 앵글을 찾는다.
  //최소 앵글의 인덱스를 sequence에 순서대로 넣는다.
  int minAngle = 360;
  int minIdx = 0;
  int A, x1, x2, y1, y2;
  sequence[0] = 0;

  for (int i = 0; i < froshNum; i++)
  { 
    for (int j = 1; j <= froshNum; j++)
    {
      x1 = whereFrosh[sequence[i]][0];
      y1 = whereFrosh[sequence[i]][1];
      x2 = whereFrosh[j][0];
      y2 = whereFrosh[j][1];
      A = caculateAngle(x1, x2, y1, y2);
      if (A < minAngle)
      {
        minAngle = A;
        minIdx = j;
      }
    }
    sequence[i+1] = minIdx;
  }
  
}

int caculateLength(){

}

void main()
{
  int testCaseNum, froshNum;
  int whereFrosh[MAX_FROSH+1][2];
  int sequence[MAX_FROSH+1];

  FILE *frosh;
  frosh = fopen("frosh.txt", "r");
  if (frosh == NULL)
  {
    perror("Not Found.");
    exit(1);
  }
  
  fscanf(frosh, "%d\n", testCaseNum);


  for (int i = 0; i < testCaseNum; i++)
  {
    fscanf(frosh, "%d\n", froshNum);

    if (froshNum > MAX_FROSH){
      printf("Too much frosh. So skip this case!");
      continue;
    }

    froshNum++;
    whereFrosh[0][0] = 0;
    whereFrosh[0][1] = 0;

    for (int j = 1; j <= froshNum; j++)
    {
      fscanf(frosh, "%d %d\n", &whereFrosh[j][0], &whereFrosh[j][1]); // &를 빼도 되나?
    }
    
    findMinAngle(froshNum, whereFrosh, sequence);

    
    
  }
}
