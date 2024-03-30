#include <stdio.h>

void read_values(double* x, double* y);
int position_is(float l_part, float r_part);
int region_is(int rel_to_f1, int rel_to_f2, int rel_to_f3);
void print_region(int);
void print_lines(int pos_rel_to_f1, int pos_rel_to_f2, int pos_rel_to_f3);

// f1(x) = 2x + 2
// f2(x) = 0.5x - 1
// f3(x) = -x + 2

int main()
{
    double x, y;
    int pos_rel_to_f1, pos_rel_to_f2, pos_rel_to_f3, region;

    read_values(&x, &y);

    pos_rel_to_f1 = position_is(y, 2 * x + 2);
    pos_rel_to_f2 = position_is(y, 0.5 * x - 1);
    pos_rel_to_f3 = position_is(y, -x + 2);

    region = region_is(pos_rel_to_f1, pos_rel_to_f2, pos_rel_to_f3);

    if (region)
        print_region(region);
    else
        print_lines(pos_rel_to_f1, pos_rel_to_f2, pos_rel_to_f3);

    return 0;
}

void read_values(double* x, double* y)
{
    printf("Please insert coordinates of the point:\n");
    scanf("%lf%lf", x, y);
}

int position_is(float l_part, float r_part)
{
    int result;

    if (l_part == r_part)
        result = 3;
    else if (l_part < r_part)
        result = 2;
    else
        result = 1;

    return result;
}

int region_is(int pos_rel_to_f1, int pos_rel_to_f2, int pos_rel_to_f3)
{
    int region = 0;

    switch (pos_rel_to_f1 * 100 + pos_rel_to_f2 * 10 + pos_rel_to_f3) {
        case 211:
            region = 1;
            break;
        case 221:
            region = 2;
            break;
        case 222:
            region = 3;
            break;
        case 122:
            region = 4;
            break;
        case 112:
            region = 5;
            break;
        case 111:
            region = 6;
            break;
        case 212:
            region = 7;
            break;
    }
    return region;
}

void print_region(int region)
{
    printf("Point placed in region %d.\n", region);
}

void print_lines(int pos_rel_to_f1, int pos_rel_to_f2, int pos_rel_to_f3)
{
    printf("Point lies on function graphs: ");
    if (pos_rel_to_f1 == 3)
        printf("1 ");
    if (pos_rel_to_f2 == 3)
        printf("2 ");
    if (pos_rel_to_f3 == 3)
        printf("3 ");
    printf("\n");
}
