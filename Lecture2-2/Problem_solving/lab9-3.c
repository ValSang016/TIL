#include <stdio.h>
#include <stdlib.h>

//Input 파일의 문장의 줄 수와 줄을 출력

void main()
{
  FILE *infile, *outfile;
  char line[100];
  int lcount = 0;
  if ((infile = fopen("charstream.txt", "r")) == NULL){
    printf("File Could Not Be Opened.\n");
    exit(1);
  }
  if ((outfile = fopen("stream.txt", "w")) == NULL){
    printf("File Could Not Be Opened.\n");
    exit(1);
  }
  /* Get each line from the input file and write the line and
  line number to the screen */
  while (fgets(line, sizeof(line), infile) != NULL){
    lcount++;
    printf("Line %d: %s", lcount, line);
    fputs(line, outfile);
  }
  fclose(infile);
}