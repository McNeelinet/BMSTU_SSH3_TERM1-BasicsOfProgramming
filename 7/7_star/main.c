#include <stdio.h>
#include "matrix.h"

void inputPositiveInt(int* value, char* prompt);
void sortMatrix(double** matirx, int rows, int columns);

int main()
{
    int rows, columns;
    double** matrix;

    inputPositiveInt(&rows, "Enter rows: ");
    inputPositiveInt(&columns, "Enter cols: ");

    matrix = initMatrix(rows, columns);
    if (matrix != NULL) {
        fillMatrix(matrix, rows, columns);
        printMatrix(matrix, rows, columns, "Matrix");

        sortMatrix(matrix, rows, columns);
        printMatrix(matrix, rows, columns, "Sorted matrix");

        freeMemory(matrix, rows);
    }

    return 0;
}

void inputPositiveInt(int* value, char* prompt)
{
    printf("%s", prompt);
    scanf("%d", value);
    while (*value <= 0) {
        printf("This value should be positive. Try again: ");
        scanf("%d", value);
    }
}

void changeCoordinate(int* curRow, int* curCol, int move)
{
    if (move % 4 == 0)
        (*curCol)++;
    else if (move % 4 == 1)
        (*curRow)--;
    else if (move % 4 == 2)
        (*curCol)--;
    else if (move % 4 == 3)
        (*curRow)++;
}

int isPosInMatrix(int rows, int columns, int curRow, int curCol)
{
    return (0 <= curRow && curRow <= rows - 1) && (0 <= curCol && curCol <= columns - 1);
}

void swap(double* num1, double* num2)
{
    double temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sortMatrix(double** matrix, int rows, int columns)
{
    int startRow = rows / 2;
    int startCol = (columns - 1) / 2;
    int moves = (rows > columns - 1 ? rows : columns - 1) + (columns > rows - 1 ? columns - 1 : rows - 1);
    int curRow;
    int curCol;
    double* prevElem;

    for (int i = 0; i <= rows * columns - 2; i++) {
        curRow = startRow;
        curCol = startCol;
        prevElem = *(matrix + curRow) + curCol;

        for (int move = 0; move <= moves - 1; move++)
            for (int step = 1 + move / 2; step > 0; step--) {
                if (isPosInMatrix(rows, columns, curRow, curCol)) {
                    if (*(*(matrix + curRow) + curCol) < *prevElem)
                        swap(*(matrix + curRow) + curCol, prevElem);
                    prevElem = *(matrix + curRow) + curCol;
                }
                changeCoordinate(&curRow, &curCol, move);
            }
    }
}




















