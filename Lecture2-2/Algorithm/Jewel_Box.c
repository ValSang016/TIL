/*
*
* File : Jewel_Box.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Oct.02 2023
* Course : Algorithm
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>


/*
*
* void main()
*
* Summary of this function : 
*   Receive the number of pearls she want to store in jewel box and costs, size of each box.
*   And then, find the best way to distribute her pearls among the boxes.
* 
*/
int main() {
  int n, c1, n1, c2, n2;

  while (1) {
    scanf("%d", &n);    //Enter the number of pearls she would store
    if (n == 0) break;

    scanf("%d %d", &c1, &n1);   // Enter a cost and size of box 1
    scanf("%d %d", &c2, &n2);   // Enter a cost and size of box 2

        int minCost = 20000000; 
        int m1 = 0, m2 = 0;   //m1, m2 are the number of boxes to buy
        int solution = 0;   //Check there is a solution to store pearls by the best way.

        for (int x1 = 0; x1 <= n / n1; x1++) {   //Find the best combination of number of boxes by checking all possible combinations

          for (int x2 = 0; x2 <= n / n2; x2++) {
            int totPearls = x1 * n1 + x2 * n2; 
            int totCost = x1 * c1 + x2 * c2;

            if (totPearls == n && totCost < minCost) {//Check that the total number of the size of box 1, 2 can store peals same with number of pearls to store and check the total cost of the current case is lower than the minimun cost
              minCost = totCost;
              m1 = x1;
              m2 = x2;
              solution = 1;
            }
          }
        }

        if (solution) {
            printf("%d %d\n", m1, m2);
        } else {
            printf("failed\n");
        }
    }

    return 0;
}
