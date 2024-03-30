#include <stdio.h>
#include <malloc.h>
#include "matrix.h"

void inputPositiveInt(int* value, char* prompt);
void replaceMax(double** matrix, int rows, int columns);

int main()
{
    int rows, columns;
    double** matrix;

    inputPositiveInt(&rows, "Input rows: ");
    inputPositiveInt(&columns, "Input columns: ");

    matrix = initMatrix(rows, columns);
    if (matrix != NULL) {
        fillMatrix(matrix, rows, columns);
        printMatrix(matrix, rows, columns, "Matrix:");

        replaceMax(matrix, rows, columns);
        printMatrix(matrix, rows, columns, "Matrix with replaced max:");
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

double calcSum(double** matrix, int rows, int columns)
{
    double sum = 0;

    for (int row = 0; row <= rows - 1; row++)
        for (int col = 0; col <= columns - row - 2; col++)
            sum += matrix[row][col];

    return sum;
}

double findMaxInMatrix(double** matrix, int rows, int columns)
{
    double max = **matrix;

    for (int row = 0; row <= rows - 1; row++)
        for (int col = 0; col <= columns - 1; col++)
            if (*(*(matrix + row) + col) > max)
                max = *(*(matrix + row) + col);

    return max;
}

void replaceMax(double** matrix, int rows, int columns)
{
    double sum = calcSum(matrix, rows, columns);
    double max = findMaxInMatrix(matrix, rows, columns);

    for (int row = 0; row <= rows - 1; row++)
        for (int col = 0; col <= columns - 1; col++)
            if (*(*(matrix + row) + col) == max)
                *(*(matrix + row) + col) = sum;
}
