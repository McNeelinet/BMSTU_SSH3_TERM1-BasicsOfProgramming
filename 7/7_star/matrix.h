#ifndef MATRIX_H
#define MATRIX_H

void printMatrix(double** matrix, int rows, int columns, char* title);
void freeMemory(double** matrix, int rows);
double** initMatrix(int rows, int columns);
void fillMatrix(double** matrix, int rows, int columns);

#endif // MATRIX_H
