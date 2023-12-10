#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int W;
  int L;
  int C;
} candidate;

void readData(const char* filename, candidate people[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    while (fscanf(file, "%s %s %s", ) == 3) {
        (*count)++;
    }

    fclose(file);
}

void counting() {

}

void main(){
  
}