/*
*
* File : Lab13-1.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Nov.28 2023
* Course : Problem solving
* Summary : This file contain code that practice in the class.
*
*/
#include <stdio.h>

// Function to convert a decimal number to binary
void decToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main(){
    int i;
    for(i = 1; i <= 1000; i++){
        printf("DEC %d: ", i);
        decToBinary(i);
        printf(" HEX %X\n", i);
    }
    return 0;
}
