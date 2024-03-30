#include <stdio.h>

void fillMatrix(double** matrix, int rows, int columns)
{
    for (int row = 0; row <= rows - 1; row++)
        for (int column = 0; column <= columns - 1; column++) {
            printf("Element in row %d column %d: ", row, column);
            scanf("%lf", *(matrix + row) + column);
        }
}

void printMatrix(double** matrix, int rows, int columns, char* title)
{
    printf("%s\n", title);
    for (int row = 0; row <= rows - 1; row++) {
        for (int column = 0; column <= columns - 1; column++)
            printf("%-8.3lf\t", *(*(matrix + row) + column));
        printf("\n");
    }
    printf("Rows: %d\tColumns: %d\n\n", rows, columns);
}

void swapRows(double** row1, double** row2)
{
    double* temp = *row1;
    *row1 = *row2;
    *row2 = temp;
}

void swapElems(double* num1, double* num2)
{
    double temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void transposeSqureMatrix(double** matrix, int side)
{
    for (int i = 0; i < side - 1; i++)
        for (int j = 0; j < side - 1 - i; j++)
            swapElems(*(matrix + i) + j, *(matrix + side - 1 - j) + side - 1 - i);
}
