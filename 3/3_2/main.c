#include <stdio.h>
#include <math.h>

void read_interval(double* from_x, double* to_x);
void read_accuracy(double* accuracy);
double area_is(double from_x, double to_x, double accuracy);

int main()
{
    double from_x, to_x, accuracy;

    read_interval(&from_x, &to_x);
    read_accuracy(&accuracy);

    printf("\n%.20lf\n", area_is(from_x, to_x, accuracy));

    return 0;
}


void check_positivity(double* value)
{
    while (*value <= 0) {
        printf("This value should be positive. Try again: ");
        scanf("%lf", value);
    }
}

void read_interval(double* from_x, double* to_x)
{
    printf("Enter start point: ");
    scanf("%lf", from_x);
    check_positivity(from_x);

    printf("Enter end point: ");
    scanf("%lf", to_x);
    check_positivity(to_x);
    // проверки на положительность т.к. ln(x) опр на (0; +inf)
}

void read_accuracy(double* accuracy)
{
    printf("Enter accuracy: ");
    scanf("%lf", accuracy);
    check_positivity(accuracy);
}

double parabola_method(double from_x, double step, int n)
{
    double sum = log(from_x) + log(from_x + step * n);

    for (int i = 1; i <= (n - 1); i++)
        sum += log(from_x + step * i) * (i % 2 ? 4 : 2);

    return sum * (step * 1/3);
}

double area_is(double from_x, double to_x, double accuracy)
{
    float old_area = 0, new_area = 0, step;
    int n = 1;

    do {
        n *= 2;
        step = (to_x - from_x) / n;

        old_area = new_area;
        new_area = parabola_method(from_x, step, n);
    }
    while (fabs(new_area - old_area) >= accuracy);

    return new_area;
}
