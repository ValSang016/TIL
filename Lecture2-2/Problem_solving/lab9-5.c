#include <stdio.h>
#include <stdlib.h>

//이것도 9-4와 같음

void main()
{
  FILE *myFile;
  char ch;
  myFile = fopen("myinFile.txt", "r");
  if (myFile == NULL){
    printf("Could not open data.txt!\n");
    exit(1);
  }
  /* Read the input file one character at a time, and write
  the character to the screen.   */
  while ((ch = fgetc(myFile)) != EOF)
    putchar(ch);
  fclose(myFile);
}