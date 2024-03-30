#ifndef MATRIX_H
#define MATRIX_H

void fillMatrix(double** matrix, int rows, int columns);
void printMatrix(double** matrix, int rows, int columns, char* title);
void swapElems(double* num1, double* num2);
void swapRows(double** row1, double** row2);
void transposeSqureMatrix(double** matrix, int side);

#endif // MATRIX_H
