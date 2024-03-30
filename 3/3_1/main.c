#include <stdio.h>

void read_accuracy(double* accuracy);
void check_accuracy(double* accuracy);
double sum_is(double accuracy);
void print_result(double sum);

int main()
{
    double accuracy;

    read_accuracy(&accuracy);
    check_accuracy(&accuracy);

    print_result(sum_is(accuracy));

    return 0;
}

void read_accuracy(double* accuracy)
{
    printf("Enter accuracy: ");
    scanf("%lf", accuracy);
}

void check_accuracy(double* accuracy)
{
    while (*accuracy < 0) {
        printf("Error. Accuracy should be positive. Try again.\n\n");
        read_accuracy(accuracy);
    }
}

double sum_is(double accuracy)
{
    double sum = 0, last_item = 1;
    int i = 0;

    do {
        i++;
        last_item /= i;
        sum += last_item;
        //printf("i=%d\titem=%lf\tsum=%.10lf\n", i, last_item, sum);
    }
    while (last_item > accuracy);

    return sum - last_item;
}

void print_result(double sum)
{
    printf("Sum is %.10lf\n\n", sum);
}
