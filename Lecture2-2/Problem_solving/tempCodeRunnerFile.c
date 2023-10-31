#include <stdio.h>

void main()
{
  int i;
  char ch;
  FILE *myFile;
  myFile = fopen("myinFile.txt", "r");
  /* Read the input file one character at a time,
  and write the character to the screen.   */
  if (myFile == NULL)
    printf("\nFile Could Not Be Opened");
  else
  {
    // do
    // {
    //   putchar(ch);
    //   ch = fgetc(myFile);
    // } while (ch != EOF);

    while ((ch = fgetc(myFile)) != EOF)
    {
      putchar(ch);
    }
    

    // ch = fgetc(myFile);
    // while (ch != EOF)
    // {
    //   putchar(ch);
    //   ch = fgetc(myFile);
    // }
    printf("\nFinished printing the file \n");
    fclose(myFile);
  }
}
