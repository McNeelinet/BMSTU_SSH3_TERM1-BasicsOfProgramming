#ifndef MATRIX_MEMORY_H
#define MATRIX_MEMORY_H

double** initMatrix(int rows, int columns);
void freeMemory(double** matrix, int rows);
double** addNRow(double** matrix, int* rows, int* columns, int n);
double** addNCol(double** matrix, int* rows, int* columns, int n);
double** delNRow(double** matrix, int* rows, int* columns, int n);
double** delNCol(double** matrix, int* rows, int* columns, int n);

#endif // MATRIX_MEMORY_H
