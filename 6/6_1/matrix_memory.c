#include <malloc.h>
#include "matrix_actions.h"

void freeMemory(double** matrix, int rows)
{
    for (int row = 0; row <= rows - 1; row++)
        if (*(matrix + row) != NULL)
            free(*(matrix + row));
    free(matrix);
}

double** initMatrix(int rows, int columns)
{
    double** matrix = (double**) malloc(rows * sizeof(double*));
    if (matrix != NULL)
        for (int i = 0; i <= rows - 1; i++) {
            *(matrix + i) = (double*) malloc(columns * sizeof(double));
            if (*(matrix + i) == NULL) {
                freeMemory(matrix, i);
                matrix = NULL;
                break;
            }
        }
    return matrix;
}

double** addNRow(double** matrix, int* rows, int* columns, int n)
{
    double** tmp = matrix;

    matrix = (double**) realloc(matrix, (*rows + 1) * sizeof(double*));
    if (matrix != NULL) {
        *(matrix + *rows) = (double*) malloc(*columns * sizeof(double));
        if (*(matrix + *rows) != NULL) {
            for (int i = *rows; i >= n + 1; i--)
                swapRows(matrix + i, matrix + i - 1);
            (*rows) += 1;
        }
        else {
            freeMemory(matrix, *rows);
            matrix = NULL;
        }
    }
    else
        freeMemory(tmp, *rows);

    return matrix;
}

double** addNCol(double** matrix, int* rows, int* columns, int n)
{
    for (int row = 0; row <= *rows - 1; row++) {
        *(matrix + row) = (double*) realloc(*(matrix + row), (*columns + 1) * sizeof(double));
        if (*(matrix + row) != NULL)
            for (int column = *columns; column >= n + 1; column--)
                swapElems(*(matrix + row) + column, *(matrix + row) + column - 1);
        else {
            freeMemory(matrix, *rows);
            matrix = NULL;
            break;
        }
    }
    if (matrix !=  NULL)
        (*columns) += 1;

    return matrix;
}

double** delNRow(double** matrix, int* rows, int* columns, int n)
{
    double** tmp = matrix;

    for (int row = n; row <= *rows - 2; row++)
        swapRows(matrix + row, matrix + row + 1);

    matrix = (double**) realloc(matrix, (*columns - 1) * sizeof(double*));
    if (matrix == NULL)
        freeMemory(matrix, *rows);
    else
        (*rows) -= 1;

    return matrix;
}

double** delNCol(double** matrix, int* rows, int* columns, int n)
{
    for (int row = 0; row <= *rows - 1; row++) {
        for (int column = n; column <= *columns - 2; column++)
            swapElems(*(matrix + row) + column, *(matrix + row) + column + 1);
        *(matrix + row) = (double*) realloc(*(matrix + row), (*columns - 1) * sizeof(double));
        if (*(matrix + row) == NULL) {
            freeMemory(matrix, *rows);
            matrix = NULL;
            break;
        }
    }
    if (matrix != NULL)
        (*columns) -= 1;

    return matrix;
}
