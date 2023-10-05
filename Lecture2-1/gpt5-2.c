#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE1_ROWS 15
#define TABLE1_COLUMNS 3

#define TABLE2_ROWS 10
#define TABLE2_COLUMNS 3

typedef struct {
    int data[TABLE1_COLUMNS];
} Table1Row;

typedef struct {
    int data[TABLE2_COLUMNS];
} Table2Row;

void fillTable1(Table1Row table1[]) {
    for (int i = 0; i < TABLE1_ROWS; i++) {
        for (int j = 0; j < TABLE1_COLUMNS; j++) {
            table1[i].data[j] = rand() % 100 + 1;
        }
    }
}

void fillTable2(Table2Row table2[]) {
    for (int i = 0; i < TABLE2_ROWS; i++) {
        for (int j = 0; j < TABLE2_COLUMNS; j++) {
            table2[i].data[j] = rand() % 100 + 1;
        }
    }
}

void printTable1(const Table1Row table1[]) {
    printf("Table 1:\n");
    for (int i = 0; i < TABLE1_ROWS; i++) {
        for (int j = 0; j < TABLE1_COLUMNS; j++) {
            printf("%4d ", table1[i].data[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printTable2(const Table2Row table2[]) {
    printf("Table 2:\n");
    for (int i = 0; i < TABLE2_ROWS; i++) {
        for (int j = 0; j < TABLE2_COLUMNS; j++) {
            printf("%4d ", table2[i].data[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void updateTables(Table1Row table1[], Table2Row table2[]) {
    table1[9].data[2] = 55;
    table1[13].data[2] = 55;
    table2[4].data[0] = 55;
}

void duplexSelectionSort(Table1Row table1[], Table2Row table2[]) {
    // Sort Table 1 on column 3
    for (int i = 0; i < TABLE1_ROWS - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < TABLE1_ROWS; j++) {
            if (table1[j].data[2] < table1[min_index].data[2]) {
                min_index = j;
            }
        }
        Table1Row temp = table1[i];
        table1[i] = table1[min_index];
        table1[min_index] = temp;
    }

    // Sort Table 2 on column 1
    for (int i = 0; i < TABLE2_ROWS - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < TABLE2_ROWS; j++) {
            if (table2[j].data[0] < table2[min_index].data[0]) {
                min_index = j;
            }
        }
        Table2Row temp = table2[i];
        table2[i] = table2[min_index];
        table2[min_index] = temp;
    }
}

void quickSort(Table1Row table1[], Table2Row table2[], int low, int high) {
    if (low < high) {
        int pivot1 = table1[high].data[2];
        int pivot2 = table2[high].data[0];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (table1[j].data[2] <= pivot1) {
                i++;
                Table1Row temp1 = table1[i];
                table1[i] = table1[j];
                table1[j] = temp1;
            }
            if (table2[j].data[0] <= pivot2) {
                Table2Row temp2 = table2[i];
                table2[i] = table2[j];
                table2[j] = temp2;
            }
        }

        Table1Row temp1 = table1[i + 1];
        table1[i + 1] = table1[high];
        table1[high] = temp1;

        Table2Row temp2 = table2[i + 1];
        table2[i + 1] = table2[high];
        table2[high] = temp2;

        int partitionIndex = i + 1;
        quickSort(table1, table2, low, partitionIndex - 1);
        quickSort(table1, table2, partitionIndex + 1, high);
    }
}


void join(const Table1Row table1[], const Table2Row table2[], int t1c, int t2c, int val) {
    printf("Join:\n");
    for (int i = 0; i < TABLE1_ROWS; i++) {
        if (table1[i].data[t1c] == val) {
            for (int j = 0; j < TABLE2_ROWS; j++) {
                if (table2[j].data[t2c] == val) {
                    for (int k = 0; k < TABLE1_COLUMNS; k++) {
                        printf("%4d ", table1[i].data[k]);
                    }
                    for (int k = 0; k < TABLE2_COLUMNS; k++) {
                        printf("%4d ", table2[j].data[k]);
                    }
                    printf("\n");
                }
            }
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Table1Row table1[TABLE1_ROWS];
    Table2Row table2[TABLE2_ROWS];

    fillTable1(table1);
    fillTable2(table2);

    printf("Before update:\n");
    printTable1(table1);
    printTable2(table2);

    updateTables(table1, table2);

    printf("After update:\n");
    printTable1(table1);
    printTable2(table2);

    printf("Duplex Selection Sort:\n");
    duplexSelectionSort(table1, table2);
    printTable1(table1);
    printTable2(table2);

    printf("Quick Sort:\n");
    quickSort(table1, table2, 0, TABLE1_ROWS - 1);
    printTable1(table1);
    printTable2(table2);

    join(table1, table2, 2, 0, 55);

    return 0;
}
