#include <stdio.h>
#include <stdlib.h>

//Input 파일의 문자를 하나하나 읽어서 Output 파일에 옮기기

void main()
{
  FILE *myInFile, *myOutFile;
  char ch;
  myInFile = fopen("myinFile.txt", "r");
  if (myInFile == NULL)
  {
    printf("Could not open data.txt!\n");
    exit(1);
  }
  myOutFile = fopen("samedata.txt", "w");
  if (myOutFile == NULL)
  {
    printf("Could not open samedata.txt!\n");
    exit(1);
  }
  /* Read the input file one character at a time, and write
  the character to the output file.   */
  while ((ch = fgetc(myInFile)) != EOF)
    fputc(ch, myOutFile);
  fclose(myInFile);
  fclose(myOutFile);
}