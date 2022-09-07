#include "lab2.h"

void introduction(void)
{
    printf("2021 Fall CS211: Programming I for Engineers\nLab-2 Project\n");
}

float castToFloat(int numi)
{
    float numd = (float)numi;
    return numd;
}

double circleArea(int radius)
{
    double area;
    area = PI * radius * radius;
    return area;
}

int circlePerimeter(int radius)
{
    int perimeter;
    perimeter = 2 * PI * radius;
    return perimeter;
}

int fahrenheit2Celsius(int fahrenheit)
{
    int celsius;
    celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

unsigned int factorial(unsigned int num)
{
    unsigned int factorial = 1;

    for (unsigned int i = 1; i <= num; i++)
    {
        factorial = factorial * i;
    }

    return factorial;
}
