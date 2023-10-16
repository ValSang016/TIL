#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
    findLeast function
    parameter : p_table(int**), table(int**), i(int), j(int), r(int), c(int)
    return : min (int)
    function : find least cost and add current table value -> return min value
 */
int findLeast(int** p_table, int** table, int i, int j, int r, int c)
{
    int min;

    if (j == 0)
    {
        min = table[j][i] + p_table[r - 1][i - 1];

        if (min > table[j][i] + p_table[j][i - 1])
            min = table[j][i] + p_table[j][i - 1];

        if (min > table[j][i] + p_table[(r + j + 1) % r][i - 1])
            min = table[j][i] + p_table[(r + j + 1) % r][i - 1];
    }

    else if (j == r - 1)
    {
        min = table[j][i] + p_table[(r + j - 1) % r][i - 1];

        if (min > table[j][i] + p_table[j][i - 1])
            min = table[j][i] + p_table[j][i - 1];

        if (min > table[j][i] + p_table[0][i - 1])
            min = table[j][i] + p_table[0][i - 1];
    }

    else
    {
        min = table[j][i] + p_table[(r + j - 1) % r][i - 1];

        if (min > table[j][i] + p_table[j][i - 1])
            min = table[j][i] + p_table[j][i - 1];

        if (min > table[j][i] + p_table[(r + j + 1) % r][i - 1])
            min = table[j][i] + p_table[(r + j + 1) % r][i - 1];
    }
    return min;
}

/*
    Calculate function
    parameter : p_table(int**), table(int**), row(int), column(int)
    function : Change p_table value by findLeast function
 */
void Calculate(int** p_table, int** table, int r, int c)
{
    int i, j;

    for (i = 1; i < c; i++)
    {
        for (j = 0; j < r; j++)
            p_table[j][i] = findLeast(p_table, table, i, j, r, c);
    }
}

/*
    SequenceList function
    parameter : p_table(int**), table(int**), tmpI(int), tmpJ(int), r(int), c(int), stack(int*)
    function : Find the minimum cost sequence and save in stack
*/
void SequenceList(int** p_table, int** table, int tmpI, int tmpJ, int r, int c, int* stack)
{
    int min, temp, result;

    //Find sequence
    for (int j = tmpJ; j >= 0; j--)
    {
        if (j != tmpJ)
            tmpI = temp;
        if (tmpI == 0)
        {
            min = p_table[r - 1][j - 1];
            temp = r - 1;
            if (p_table[tmpI][j - 1] < min)
            {
                min = p_table[tmpI][j - 1];
                temp = tmpI;
            }
            if (p_table[(tmpI + 1 + r) % r][j - 1] < min)
            {
                min = p_table[tmpI][j - 1];
                temp = (tmpI + 1 + r) % r;
            }
        }
        else if (tmpI == r - 1)
        {
            min = p_table[(tmpI - 1 + r) % r][j - 1];
            temp = (tmpI - 1 + r) % r;

            if (p_table[tmpI][j - 1] < min)
            {
                min = p_table[tmpI][j - 1];
                temp = tmpI;
            }
            if (p_table[0][j - 1] < min)
            {
                min = p_table[0][j - 1];
                temp = 0;
            }
        }
        else
        {
            min = p_table[(tmpI - 1 + r) % r][j - 1];
            temp = (tmpI - 1 + r) % r;
            if (p_table[tmpI][j - 1] < min)
            {
                min = p_table[tmpI][j - 1];
                temp = tmpI;
            }
            if (p_table[(tmpI + 1 + r) % r][j - 1] < min)
            {
                min = p_table[(tmpI + 1 + r) % r][j - 1];
                temp = (tmpI + 1 + r) % r;
            }
        }
        stack[j - 1] = table[temp][j - 1];
    }
}


/*
    Sequence function
    parameter : p_table(int**), table(int**), row(int), column(int)
    return : stack[](int)
    function : find min value of last column(p_table), save value in stack
 */
int* Sequence(int** p_table, int** table, int r, int c)
{
    int* stack, min, tmpI = 0, tmpJ = c - 1;

    stack = (int*)malloc(sizeof(int) * c);

    //Initialize min value, first row last column value in p_table
    min = p_table[0][c - 1];
    stack[c - 1] = table[0][c - 1];
    //find min value in last column, save original table value in stack
    for (int i = 1; i < r; i++)
    {
        if (p_table[i][c - 1] < min)
        {
            min = p_table[i][c - 1];
            stack[c - 1] = table[i][c - 1];
            tmpI = i;
            tmpJ = c - 1;
        }
    }
    SequenceList(p_table, table, tmpI, tmpJ, r, c, stack);
    return stack;
}

int main()
{
    char inFileName[7][20] = { "Input_1.txt", "Input_2.txt", "Input_3.txt", "Input_4.txt", "Input_5.txt", "Input_6.txt", "Input_7.txt" };
    char outFileName[7][20] = { "Output_1.txt", "Output_2.txt", "Output_3.txt", "Output_4.txt", "Output_5.txt", "Output_6.txt", "Output_7.txt" };

    for (int filenum = 0; filenum < 7; filenum++)
    {
        int row, column, result;
        int** table, ** p_table;  //p_table : parent table

        FILE* inFile;
        inFile = fopen(inFileName[filenum], "r");
        if (inFile == NULL)
            printf("\nInput File Could Not Be Opened\n");
        FILE* outFile;
        outFile = fopen(outFileName[filenum], "w");

        //Receive numbers & makes table
        while (fscanf(inFile, "%d %d", &row, &column) != EOF)
        {
            table = (int**)malloc(sizeof(int*) * row);
            p_table = (int**)malloc(sizeof(int*) * row);

            for (int i = 0; i < row; i++)
            {
                table[i] = (int*)malloc(sizeof(int) * column);
                p_table[i] = (int*)malloc(sizeof(int) * column);
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    fscanf(inFile, "%d", &table[i][j]);

                    if (j == 0)
                    {
                        p_table[i][0] = table[i][0];    //Duplicate to p_table
                    }
                }
            }

            Calculate(p_table, table, row, column);
            int* stack = Sequence(p_table, table, row, column);

            result = 0;

            //Prints out the results
            for (int i = 0; i < column; i++)
            {
                fprintf(outFile, "%d ", stack[i]);
                result = result + stack[i];
            }

            fprintf(outFile, "\n%d\n", result);
        }
        fclose(inFile);
        fclose(outFile);
    }
    return 0;
}