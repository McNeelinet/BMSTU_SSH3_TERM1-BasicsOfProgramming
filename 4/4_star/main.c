#include <stdio.h>
#include <malloc.h>
#include <math.h>

void inputSize(int* size);
void checkSize(int* size);
double* initArray(int size);
void fillArray(double* arr, int size);
int filterArray(double** arr, int size);
void printArray(double* arr, int size);
void memoryError();
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
        size = filterArray(&arr, size);

        if (arr != NULL)
            printArray(arr, size);
    }
    if (arr == NULL)
        memoryError();

    freeMemory(arr);
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
    double* arr = (double*) malloc(size * sizeof(double));

    return arr;
}

void fillArray(double* arr, int size)
{
    for (int i = 0; i <= size - 1; i++) {
        printf("Element #%d: ", i);
        scanf("%lf", (arr + i));
    }
}

double findMax(double* arr, int size)
{
    double max = *arr;

    for (int i = 0; i <= size - 1; i++)
        if (*(arr + i) > max)
            max = *(arr + i);

    return max;
}

double findMin(double* arr, int size)
{
    double min = *arr;

    for (int i = 0; i <= size - 1; i++)
        if (*(arr + i) < min)
            min = *(arr + i);

    return min;
}

double calcAverage(double *arr, int size, double max, double min)
{
    double sum = 0;
    int c = 0;

    for (int i = 0; i <= size - 1; i++)
        if (*(arr + i) > min && *(arr + i) < max) {
            sum += *(arr + i);
            c += 1;
        }

    if (c == 0)
        return NAN;
    else
        return (sum / c);
}

int deleteElement(double** arr, int deletePos, int size)
{
    for (int i = deletePos; i <= size - 2; i++)
        *(*arr + i) = *(*arr + i + 1);
    if (size - 1)
        *arr = (double*) realloc(*arr, (size - 1) * sizeof(double));

    return size - 1;
}

int filterArray(double** arr, int size)
{
    double max = findMax(*arr, size);
    double min = findMin(*arr, size);
    double average = calcAverage(*arr, size, max, min);

    if (isnan(average) == 0) {
        for (int i = 0; i <= size - 1; i++)
            if (*(*arr + i) <= min * 2 || *(*arr + i) >= average) {
                size = deleteElement(arr, i, size);
                if (*arr == NULL)
                    break;
                i--;
            }
    }
    else {
        printf("Can't calc average. Array left without changes.\n");
    }

    return size;
}

void printArray(double* arr, int size)
{
    if (size) {
        printf("\nArray:\n");
        for (int i = 0; i <= size - 1; i++)
            printf("%.3lf\t", *(arr + i));
    }
    else {
        printf("\nArray is empty now.");
    }

    printf("\n");
}

void memoryError()
{
    printf("Something went wrong during memory allocation. Restart program.\n");
}

void freeMemory(double* arr)
{
    free(arr);
}
