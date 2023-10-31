/*
* File: lab6-1.C
*
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Oct.09 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>
#include <string.h>
#define iter 5


/*
*
* int string_len(char* string)
*
* Summary of this function : 
*   This function receives a string as pointer and calculate length of the string.
*
* Return count(int)
*
*/
int string_len(char* string){
  int count = 0;
  while(*string++){
    count++;
  }
  return count;
}


/*
*
* void string_divide(char* search_string, char* front, char* end)
*
* Summary of this function : 
*   This function receives a string as pointer and separate the string based on "*" into two 
*   strings. Or if there is no "*", return 0.
*
* Return : 0 : there is no wild card , or 1 : there is a wild card.
*
*/
int string_divide(char* search_string, char* front, char* end){
    while(*search_string != '*'){
      if(!*search_string){
        search_string++;
        *front = '\0';
        return 0;
      } 
      *front++ = *search_string++;
    }

    search_string++;
    *front = '\0'; // Add null terminator

    while (*search_string){
      *end++ = *search_string++;
    }
    *end = '\0'; // Add null terminator

    return 1;
}


/*
*
* int match_count(char input_string[], char search_string[])
*
* Summary of this function : 
*   This function receives two strings and count how many the search_string pattern in the input_string.
*
* Return : count(int)
*
*/
int match_count(char input_string[], char search_string[]){
  char front_string[256], end_string[256];

  // If there is a wild card, this separates the string based on "*" into two strings
  int have_wild_card = string_divide(search_string, front_string, end_string);


  int count = 0;
  int input_len = string_len(input_string);
  int front_len = string_len(front_string);
  int end_len = string_len(end_string);

  for (int cursor1 = 0; cursor1 < input_len; cursor1++)
  {
    if(input_string[cursor1] == ' ') // Skip space
      continue;

    if(input_string[cursor1] == front_string[0]){
      int tmp1 = 0; // Number of same characters
      for (int progress1 = 0; progress1 < front_len; progress1++){
        if(input_string[cursor1 + progress1] != front_string[progress1])
          break;
        else 
          tmp1++;

        if(tmp1 == front_len){  // tmp1 = front_len : This sub-string is same the pattern in search_string
          cursor1 += front_len;
          if(!have_wild_card){  // If the wild card don't exist, pass the cursor next
            count++;
            break;
          } else {  // If the wild card exists, repeat the function above
            for (int cursor2 = cursor1; cursor2 < input_len; cursor2++){
              if(input_string[cursor2] == end_string[0]){
                int tmp2 = 0;
                for (int progress2 = 0; progress2 < end_len; progress2++){
                  if(input_string[cursor2 + progress2] != end_string[progress2])
                    break;
                  else
                    tmp2++;
                  if(tmp2 == end_len){
                    count++;
                    break;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return count;
}


/*
*
* void main()
*
* Summary of this function : 
*   This function receives two stings and compare and print results.
* 
*/
void main(){
  char input_string[256], search_string[256];
  int count = 0;
  printf("Text matching program\n");

  for (int i = 0; i < iter; i++){
    printf("Enter the input string : ");
    fgets(input_string, sizeof(input_string), stdin);
    strtok(input_string, "\n"); // Remove newline character

    printf("Enter the search string : ");
    fgets(search_string, sizeof(search_string), stdin);
    strtok(search_string, "\n"); // Remove newline character  

    count = match_count(input_string, search_string);
    printf("Matched words : %d\n", count);
    (count>0) ? printf("Match found!\n\n") : printf("There is no matched pattern.\n\n"); 
  }
}