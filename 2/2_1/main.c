#include <stdio.h>
#include <math.h>

void read_interval(double* from_x, double* to_x);
void check_interval(double* from_x, double* to_x);
void set_n(double from_x, double to_x, int* n);

void run_cycles(double from_x, double to_x, int n);


int main()
{
    double from_x, to_x;
    int n;

    read_interval(&from_x, &to_x);
    check_interval(&from_x, &to_x);
    set_n(from_x, to_x, &n);

    run_cycles(from_x, to_x, n);

    return 0;
}


void read_interval(double* from_x, double* to_x)
{
    printf("Enter start point: ");
    scanf("%lf", from_x);

    printf("Enter end point: ");
    scanf("%lf", to_x);
}

void check_interval(double* from_x, double* to_x)
{
    double e = 0.0000001;

    while (*from_x - *to_x >= e) {
        printf("Incorrect interval. Try again.\n\n");
        read_interval(from_x, to_x);
    }
}

void read_n(int* n)
{
    printf("How many iterations?: ");
    scanf("%d", n);
}

void check_n(int* n)
{
    while (*n < 2) {
        printf("Should be at least 2 iterations for this interval.\n\n");
        read_n(n);
    }
}

void set_n(double from_x, double to_x, int* n)
{
    double diff = to_x - from_x;
    double e = 0.0000001;

    if (diff <= e && diff >= -e) {
        *n = 1;
        printf("Only 1 iteration will be completed.\n");
    }
    else {
        read_n(n);
        check_n(n);
    }

    printf("\n");
}


double step_is(double from_x, double to_x, int n)
{
    double step;

    if (n == 1)
        step = 1;
    else
        step = (to_x - from_x) / (n - 1);

    return step;
}

void gen_hat(double from_x, double step, double n)
{
    printf("x\t|");
    for (int i = 0; i <= n - 1; i++)
        printf("%-8.3lf\t|", from_x + step * i);

    printf("\n");
    printf("f(x)\t|");
}

void print_result(double x)
{
    double result = (sin(x) * sin(x)) / x;

    if (isnan(result))
        printf("%-8s\t|", "Zero");
    else
        printf("%-8.6lf\t|", result);
}

void for_cycle(double from_x, double step, int n)
{
    for (int i = 0; i <= n - 1; i++)
        print_result(from_x + step * i);

    printf("\n\n");
}

void while_cycle(double from_x, double to_x, double step)
{
    double e = 0.0000001;

    while (to_x - from_x >= -e) {
        print_result(from_x);
        from_x += step;
    }

    printf("\n\n");
}

void dowhile_cycle(double from_x, double to_x, double step)
{
    double e = 0.0000001;

    do {
        print_result(from_x);
        from_x += step;
    }
    while (to_x - from_x >= -e);

    printf("\n\n");
}

void run_cycles(double from_x, double to_x, int n)
{
    double step = step_is(from_x, to_x, n);

    printf("for\n");
    gen_hat(from_x, step, n);
    for_cycle(from_x, step, n);

    printf("while\n");
    gen_hat(from_x, step, n);
    while_cycle(from_x, to_x, step);

    printf("dowhile\n");
    gen_hat(from_x, step, n);
    dowhile_cycle(from_x, to_x, step);
}
