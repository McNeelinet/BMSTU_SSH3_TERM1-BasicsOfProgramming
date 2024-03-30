#include <stdio.h>
#include <malloc.h>

void inputSize(int* size);
void checkSize(int* size);
double* initArray(int size);
void fillArray(double* arr_p, int size);
void reorganizeArray(double* arr, int size);
void printArray(double* arr, int size);
void freeMemory(double* arr);

int main()
{
    double* arr;
    int size;

    inputSize(&size);
    checkSize(&size);

    arr = initArray(size);
    if (arr != NULL) {
        fillArray(arr, size);
        reorganizeArray(arr, size);

        printArray(arr, size);
        freeMemory(arr);
    }

    return 0;
}

void inputSize(int* size)
{
    printf("Please, enter array size: ");
    scanf("%d", size);
}

void checkSize(int* size)
{
    while (*size <= 0) {
        printf("Invalid size.\n\n");
        inputSize(size);
    }
}

double* initArray(int size)
{
    double *arr = (double*) malloc(size * sizeof(double));

    return arr;
}

void fillArray(double* arr_p, int size)
{
    for (int i = 0; i <= size - 1; i++) {
        printf("Element #%d: ", i);
        scanf("%lf", (arr_p + i));
    }
}

void swap(double* num1, double* num2)
{
    double temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int group(double* arr, int size)
{
    int i = 0;
    for (int j = 0; j <= size - 1; j++)
        if (*(arr + j) >= 0) {
            swap(arr + i, arr + j);
            i++;
        }

    return i;
}

/*  1 - сортировка по возрастанию
 * -1 - сортировка по убыванию */
void bubbleSort(double *arr, int size, int mode)
{
    for (int i = 0; i <= size - 1; i++)
        for (int j = 0; j <= size - 1; j++)
            if (mode == 1 && *(arr + i) < *(arr + j))
                swap(arr + i, arr + j);
            else if (mode == -1 && *(arr + i) > *(arr + j))
                swap(arr + i, arr + j);
}

void reorganizeArray(double* arr, int size)
{
    int lenNonNegative = group(arr, size);

    bubbleSort(arr, lenNonNegative, -1);
    bubbleSort(arr + lenNonNegative, size - lenNonNegative, 1);
}

void printArray(double* arr, int size)
{
    printf("\nArray:\n");
    if (size)
        for (int i = 0; i <= size - 1; i++)
            printf("%.3lf\t", *(arr + i));
    else
        printf("Array is empty now.");

    printf("\n");
}

void freeMemory(double* arr)
{
    free(arr);
}
