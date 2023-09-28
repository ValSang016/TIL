/*
*
* File : pancake.C
* 
* Author : Sangheon Lee(tkdgjs1315@gachon.ac.kr)
* Date : Sep.12 2023
* Course : Algorithm
* Summary : This file contain code that practice in the class.
*
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DSIZE 20  //Generate 20 pieces of data


/*
*
* void create_dataset(int dataset[])
*
* Summary of this function : 
*   Create the dataset(20) used in pancake flip.
*
* Parameter : array(containing nothing) / get by pointer address
* 
*/
void create_dataset(int dataset[]){
	for (int i = 0; i < DSIZE; i++) 
	{
		int random = 1 + rand() % 10; 
		dataset[i] = random;
	}
}


/*
*
* int testOrder(int dataset[])
*
* Summary of this function : 
*   Test the dataset to see if this is sorted in order for each flip.
*   This is for efficiency of code(No need to keep sorting already sorted data).
*
* Parameter : array(containing nothing) / get by pointer address
* Return value : trueOrder(int) 0 : Not in order, 1 : In order
*
*/
int testOrder(int dataset[]){
  int trueOrder = 1;
  for (int i = 0; i < DSIZE-1; i++)
  {
    if(dataset[i] > dataset[i+1])
      trueOrder = 0;
  }
  return trueOrder;
}


/*
*
* int findMax(int flipnum, int dataset[])
*
* Summary of this function : 
*   Find a max value and index of this for using in flipping.
*
* Parameter : (int)flipnum / decide where to compare from the beginning
*             array(containing nothing) / get by pointer address
* Return value : (int)maxidx(max index) 
*
*/
int findMax(int flipnum, int dataset[]){
  int maxidx;
  int maxnum = -1;
  for (int i = 0; i <= flipnum; i++)
  {
    if(dataset[i] >= maxnum){
      maxidx = i;
      maxnum = dataset[i];
    }
  }
  return maxidx;
}


/*
*
* int flip(int maxidx, int dataset[])
*
* Summary of this function : 
*   Flip the pancake from the top to a specific point.
*   The point is a max index point is discovered in function 'findMax'.
*   Make a new array and insert the data in the dataset backwards from maxidx to the 
*   beginning into a new array in order from the beginning.
*   And then insert the data values ​​of the array into the data of the dataset in order.
*
* Parameter : (int)maxidx
*             array(containing nothing) / get by pointer address
*
*/
void flip(int maxidx, int dataset[]){
  int temmax = maxidx;
  int flipdic[DSIZE];

  for (int i = 0; i <= maxidx; i++) // insert the data in the dataset to the new array
  {                                 
    flipdic[i] = dataset[temmax];
    temmax--;
  }
  for (int i = 0; i <= maxidx; i++) // insert the data in the new array to the dataset
  {
    dataset[i] = flipdic[i];
  }
}


/*
*
* void printData(int dataset[])
*
* Summary of this function : 
*   This is the function printing data in the dataset.
*
* Parameter : array(containing nothing) / get by pointer address
*
*/
void printData(int dataset[], int size){
  for (int i = 0; i < size; i++)
  {
    printf("%d ", dataset[i]);
  }
  printf("\n");
}


/*
*
* void process_pancake()
*
* Summary of this function : 
*   This is the main processing function.
*
*/
void process_pancake(){
  int maxidx = 0, flipn = DSIZE-1; //This two decide where to flip from the beginning
  int dataset[DSIZE];

  int flip_where[DSIZE*2];  // multiplied by 2 to give room for spaces or multiple digits
  int where_idx = 0;
  create_dataset(dataset);

  printf("Dataset before processing : ");
  printData(dataset, DSIZE);

  for (int i = 0; i < DSIZE; i++)
  {
    if(testOrder(dataset)) //Test the dataset to see if this is sorted in order for each flip
      break;  // If the result is 1, this means the dataset is already in order. 
              //So break out process.

    maxidx = findMax(flipn, dataset);

    if(maxidx == flipn){ //If the biggest pancake is in the bottom in scope of flipping process
      flipn--;           //there is no need to flip.
      continue;
    }

    if(maxidx == 0){ //If biggest pancake is in the top, just flip it over once.
      flip(flipn, dataset);
      flip_where[where_idx] = DSIZE-flipn;
      where_idx++;
    }else{  //But if not,
      flip(maxidx, dataset);  //Just place the largest pancake on top,
      flip_where[where_idx] = DSIZE-maxidx;
      where_idx++;
      flip(flipn, dataset); //flip the whole thing over, and let it go to the bottom.
      flip_where[where_idx] = DSIZE-flipn;
      where_idx++;
    }
    flipn--;  //Excluding the pancake already at the bottom
  }
  printf("Dataset after processing  : ");
  printData(dataset, DSIZE);

  flip_where[where_idx] = 0;
  where_idx++;
  printf("Flipped at positions : ");
  printData(flip_where, where_idx);
}


/*
*
* void main()
*
* Summary of this function : 
*   This is the main function.
*   This is for testing three datasets.
*
*
*/
int main(){
  srand(time(NULL));
  for (int i = 0; i < 3; i++)
  {
    printf("%dth Pancake Flip : \n", i+1);
    process_pancake();
  }
  return 0;
}