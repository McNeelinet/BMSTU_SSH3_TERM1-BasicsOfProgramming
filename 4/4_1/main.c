#include <stdio.h>
#include <malloc.h>
#define ERR_VAL -1

void input_size(int* size);
void check_size(int* size);
void init_array(double** arr, int size);
void fill_array(double* arr, int size);
void find_average(double* arr, int size);
void free_memory(double* arr);

int main()
{
    double* arr;
    int size;

    input_size(&size);
    check_size(&size);

    init_array(&arr, size);

    if (arr != NULL) {
        fill_array(arr, size);

        find_average(arr, size);
        free_memory(arr);
    }

    return 0;
}

void input_size(int* size)
{
    printf("Please, enter array size: ");
    scanf("%d", size);
}

void check_size(int* size)
{
    while (*size <= 0) {
        printf("Invalid size.\n\n");
        input_size(size);
    }
}

void init_array(double** arr, int size)
{
    *arr = (double*) malloc(size * sizeof(double));
}

void fill_array(double* arr, int size)
{
    for (int i = 0; i <= size - 1; i++) {
        printf("Element #%d: ", i);
        scanf("%lf", (arr + i));
    }
}

int find_zero(double* arr, int size)
{
    int pos = ERR_VAL;

    for (int i = size - 1; i >= 0; i--)
        if (*(arr + i) == 0) {
            pos = i;
            break;
        }

    return pos;
}

int find_max_pos(double* arr, int size)
{
    int pos = 0;

    for (int i = 0; i <= size - 1; i++)
        if (*(arr + i) >= *(arr + pos))
            pos = i;

    return pos;
}

int c_is(int from_pos, int to_pos)
{
    int c = (to_pos - from_pos) + 1;

    return (c <= 0 ? 1 : c);
}

double calculate_average(double* arr, int from_pos, int to_pos)
{
    double sum = 0;
    int c = c_is(from_pos, to_pos);

    for (; from_pos <= to_pos; from_pos++)
        sum += *(arr + from_pos);

    return sum / c;
}

void find_average(double* arr, int size)
{
    int zero_pos, max_pos;

    zero_pos = find_zero(arr, size);
    max_pos = find_max_pos(arr, size);

    if (zero_pos == ERR_VAL)
        printf("There is no zero in the array. Can't calc.\n");
    else if (zero_pos >= max_pos)
        printf("Max element should be AFTER zero. Can't calc.\n");
    else if (max_pos - zero_pos == 1)
        printf("There is no numbers between zero and max element.\n");
    else
        printf("Average in (last zero; last max) is: %lf\n", calculate_average(arr, zero_pos + 1, max_pos - 1));
}

void free_memory(double* arr)
{
    free(arr);
}
