#include <stdio.h>
#include "matrix_actions.h"
#include "matrix_memory.h"

void inputPositiveInt(int* value, char* prompt);
double** transposeMatrix(double** matrix, int* rows, int* columns);

int main()
{
    double** matrix;
    int rows, columns;

    inputPositiveInt(&rows, "Input rows: ");
    inputPositiveInt(&columns, "Input columns: ");

    matrix = initMatrix(rows, columns);
    if (matrix != NULL) {
        fillMatrix(matrix, rows, columns);
        printMatrix(matrix, rows, columns, "Initial matrix:");
        matrix = transposeMatrix(matrix, &rows, &columns);

        if (matrix != NULL) {
            printMatrix(matrix, rows, columns, "Transposed matrix:");
            freeMemory(matrix, rows);
        }
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

double** makeSquareMatrix(double** matrix, int* rows, int* columns)
{
    if (matrix != NULL)
        for (int i = *rows; i < *columns; i++) {
            matrix = addNRow(matrix, rows, columns, 0);
            if (matrix == NULL)
                break;
        }

    if (matrix != NULL)
        for (int i = *columns; i < *rows; i++) {
            matrix = addNCol(matrix, rows, columns, i);
            if (matrix == NULL)
                break;
        }

    return matrix;
}

double** deleteExcessColumns(double** matrix, int* rows, int* columns, int columnsToDelete)
{
    for (int i = columnsToDelete; i > 0; i--) {
        matrix = delNCol(matrix, rows, columns, *columns - 1);
        if (matrix == NULL)
            break;
    }

    return matrix;
}

double** deleteExcessRows(double** matrix, int* rows, int* columns, int rowsToDelete)
{
    double** newMatrix = matrix;

    for (int i = rowsToDelete; i > 0; i--) {
        newMatrix = delNRow(newMatrix, rows, columns, 0);
        if (newMatrix == NULL)
            break;
    }

    return newMatrix;
}

double** transposeMatrix(double** matrix, int* rows, int* columns)
{
    int addedRows = *columns - *rows;
    int addedCols = *rows - *columns;

    matrix = makeSquareMatrix(matrix, rows, columns);
    if (matrix != NULL) {
        transposeSqureMatrix(matrix, *rows);
        if (matrix != NULL && addedCols > 0)
            matrix = deleteExcessRows(matrix, rows, columns, addedCols);
        if (matrix != NULL && addedRows > 0)
            matrix = deleteExcessColumns(matrix, rows, columns, addedRows);
    }

    return matrix;
}
