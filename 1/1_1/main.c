#include <stdio.h>

void readValue(double* x, double* y);

int main()
{
    double x, y;
    double rPart;

    readValue(&x, &y);
    rPart = 0.5 * x + 1;

    if (y == rPart)
        printf("Point is on the line.\n");
    else if (y < rPart)
        printf("Point is belove the line.\n");
    else
        printf("Point is above the line.\n");
    printf("\n");

    return 0;
}

void readValue(double* x, double* y)
{
    printf("Please insert coordinates of the point:\n");
    scanf("%lf%lf", x, y);
}
