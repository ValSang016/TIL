#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS1 15
#define ROWS2 10
#define COLS_T 3


typedef struct {
    int data[COLS_T];
} TableRowTable;

void fillTable(TableRowTable table[], int Rows);
void printTable(TableRowTable table[], int Rows);
void updateTable(TableRowTable table[], int Rows, int Columns, int value);
void table_change(TableRowTable table[], int i, int k);
void duplex_selection_sort(TableRowTable table[], int len, int col);
void quick_sort(TableRowTable table[], int L, int R, int col);
void join(TableRowTable table1[], TableRowTable table2[], int t1c, int t2c, int val);
void print_join_table(TableRowTable table1[], TableRowTable table2[], int i, int j);



void fillTable(TableRowTable table[], int Rows) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < COLS_T; j++) {
            table[i].data[j] = rand() % 100 + 1;
        }
    }
}

void printTable(TableRowTable table[], int Rows) {
    printf(" --------------------------------\n");
    printf("| Column 1 | Column 2 | Column 3 |\n");
    printf(" --------------------------------\n");

    for (int i = 0; i < Rows; i++) {
        printf("| %-8d | %-8d | %-8d |\n", table[i].data[0], table[i].data[1], table[i].data[2]);
    }

    printf(" --------------------------------\n");
}

void print_join_table(TableRowTable table1[], TableRowTable table2[], int i, int j){

    printf(" ----------------------------------------------------------------\n");
    printf(" ----------------            Join Table           ---------------\n");
    printf(" ----------------------------------------------------------------\n");
    printf("| Column 1 | Column 2 | Column 3 || Column 1 | Column 2 | Column 3 |\n");
    printf(" ----------------------------------------------------------------\n");

        printf("| %-8d | %-8d | %-8d || %-8d | %-8d | %-8d |\n", table1[i].data[0], table1[i].data[1], table1[i].data[2], table2[j].data[0], table2[j].data[j], table2[j].data[2]);


    printf(" ----------------------------------------------------------------\n");
}


void updateTable(TableRowTable table[], int Rows, int Columns, int value){
  table[Rows-1].data[Columns-1] = value;
}

void table_change(TableRowTable table1[], int i, int k){
  TableRowTable bin = table1[i];
  table1[i] = table1[k];
  table1[k] = bin;
  }


void duplex_selection_sort(TableRowTable table[], int len, int col){
  int start = 0;
  int end = len-1;
  while(start < end){
    int min = start;
    int max = end;
    for(int i = start + 1; i <= end; i++)
    {
      if(table[i].data[col-1] < table[min].data[col-1])
        min = i;
      if(table[i].data[col-1] > table[max].data[col-1])
        max = i;
    }
      table_change(table, start, min);
      table_change(table, end, max);
      start++;
      end--;
  }
}

void quick_sort(TableRowTable table[], int L, int R, int col){
  int left = L, right = R;
  int k = col-1;
  int pivot = table[(L + R)/2].data[k];
  do{
    while(table[left].data[k] < pivot)
      left++;
    while(table[right].data[k] > pivot)
      right--;
    if(left<=right){
      table_change(table, left, right);
      left++;
      right--;
    }
  } while (left <= right);

  if(L < right)
    quick_sort(table, L, right, col);
  if(left < R)
    quick_sort(table, left, R, col);
}

void join(TableRowTable table1[], TableRowTable table2[], int t1c, int t2c, int val){
  bool t1 = false, t2 = false;
  int col1 = t1c-1, col2 = t2c-1;
  for (int i = 0; i < ROWS1-1; i++)
  {
    if(table1[i].data[col1] == val){
      t1 = true;
      for (int j = 0; j < ROWS2-1; j++)
      {
        if(table2[j].data[col2] == val){
            print_join_table(table1, table2, i, j);
          t2 = true;
        }
      }
    }
  }
  if (t2==false){
    if(t1==false){
    printf("%d is not found in all tables.", val);
    } else {
    printf("%d is not found in table2.", val);

    }
  }

  
}


int main() {
    srand(time(NULL));

    TableRowTable table1[ROWS1];
    TableRowTable table2[ROWS2];

//create tables and print
    fillTable(table1, ROWS1);
    fillTable(table2, ROWS2);
    printf("Table 1:\n");
    printTable(table1, ROWS1);
    printf("\nTable 2:\n");
    printTable(table2, ROWS2);

//update data to 55 and print
    updateTable(table1, 10, 3, 55);
    updateTable(table1, 14, 3, 55);
    updateTable(table2, 5, 1, 55);
    printf("Updated Table 1:\n");
    printTable(table1, ROWS1);
    printf("\nUpdated Table 2:\n");
    printTable(table2, ROWS2);

//duplex selction and print
    duplex_selection_sort(table1, ROWS1, 3);
    duplex_selection_sort(table2, ROWS2, 1);
    printf("\nSelection Sorted Table 1:\n");
    printTable(table1, ROWS1);
    printf("\nSelection Sorted Table 2:\n");
    printTable(table2, ROWS2);

    quick_sort(table1, 0, ROWS1-1, 3);
    quick_sort(table2, 0, ROWS2-1, 1);
    printf("\nQuick Sorted Table 1:\n");
    printTable(table1, ROWS1);
    printf("\nQuick Sorted Table 2:\n");
    printTable(table2, ROWS2);


    join(table1, table2, 3, 1, 55);

    return 0;
}