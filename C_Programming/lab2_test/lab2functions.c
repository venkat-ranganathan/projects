#include "lab2.h"

void introduction(void)
{
    printf("2022 Fall CS211: Programming I for Engineers\nLab-2 Project\n");
}
float castToFloat(int numi)
{
    float numif = (float)numi;

    return numif;
}
double circleArea(int radius)
{
    double area = PI * radius * radius;

    return area;
}
int circlePerimeter(int radius)
{
    int perimeter = 2 * PI * radius;

    return perimeter;
}
int fahrenheit2Celsius(int fahrenheit)
{
    int celsius = (fahrenheit - 32) * 5 / 9;

    return celsius;
}
unsigned int factorial(unsigned int num)
{
    unsigned int factorial = 1;

    // factorial works backwards from n!, so you can reverse the order and use a loop
    // to go from 1 to n, i.e. instead of n! = n * (n-1) * (n-2) * etc.., you can use a for loop
    // to start from 1 and keep going until you reach the value of num, then you set
    // factorial equal to factorial * i (or whatever variable name in the for loop),
    // so the value of the factorial is constantly updated
    // until you reach the specified end of the loop, then you just return the value of factorial

    for (unsigned int i = 1; i <= num; i++)
    {
        factorial = factorial * i;
    }

    return factorial;
}