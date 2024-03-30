#include <malloc.h>

void freeMemory(double** matrix, int rows)
{
    for (int row = 0; row <= rows - 1; row++)
        free(matrix[row]);
    free(matrix);
}

double** initMatrix(int rows, int columns)
{
    double** matrix = (double**) malloc(rows * sizeof(double*));
    if (matrix != NULL)
        for (int i = 0; i <= rows - 1; i++) {
            matrix[i] = (double*) malloc(columns * sizeof(double));
            if (matrix[i] == NULL) {
                freeMemory(matrix, i + 1);
                matrix = NULL;
                break;
            }
        }
    return matrix;
}

void fillMatrix(double** matrix, int rows, int columns)
{
    for (int row = 0; row <= rows - 1; row++)
        for (int column = 0; column <= columns - 1; column++) {
            printf("Element in row %d column %d: ", row, column);
            scanf("%lf", matrix[row] + column);
        }
}

void printMatrix(double** matrix, int rows, int columns, char* title)
{
    printf("%s\n", title);
    for (int row = 0; row <= rows - 1; row++) {
        for (int column = 0; column <= columns - 1; column++)
            printf("%4.2lf\t", matrix[row][column]);
        printf("\n");
    }
}
