#include <malloc.h>

void freeMemory(double** matrix, int rows)
{
    for (int row = 0; row <= rows - 1; row++)
        free(*(matrix + row));
    free(matrix);
}

double** initMatrix(int rows, int columns)
{
    double **matrix = (double**) malloc(rows * sizeof(double*));
    if (matrix != NULL) {
        for (int row = 0; row <= rows - 1; row++) {
            *(matrix + row) = (double*) malloc(columns * sizeof(double));
            if (*(matrix + row) == NULL) {
                freeMemory(matrix, row + 1);
                matrix = NULL;
                break;
            }
        }
    }
    return matrix;
}

void fillMatrix(double** matrix, int rows, int columns)
{
    for (int row = 0; row <= rows - 1; row++)
        for (int column = 0; column <= columns - 1; column++) {
            printf("Row %d rolumn %d: ", row, column);
            scanf("%lf", *(matrix + row) + column);
        }
}

void printMatrix(double** matrix, int rows, int columns, char* title)
{
    printf("%s\n", title);
    for (int row = 0; row <= rows - 1; row++) {
        for (int column = 0; column <= columns - 1; column++)
            printf("%4.2lf\t", *(*(matrix + row) + column));
        printf("\n");
    }
}
