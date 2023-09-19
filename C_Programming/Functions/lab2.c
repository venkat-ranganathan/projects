/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "lab2.h"
#include "lab2.h"

int main(void)
{
    printf("########## introduction() Function ##########\n");
    introduction();

    printf("########## Test-1: castToFloat() Function ##########\n");
    assert(castToFloat(15) == 15.0);
    printf(">>> Passed Test-1\n");

    printf("########## Test-2: circleArea() Function ##########\n");
    assert(circleArea(27) == 2289.06);
    printf(">>> Passed Test-2\n");

    printf("########## Test-3: circlePerimeter() Function ##########\n");
    assert(circlePerimeter(5) == 31);
    printf(">>> Passed Test-3\n");

    printf("########## Test-4: fahrenheit2Celsius() Function ##########\n");
    assert(fahrenheit2Celsius(81) == 27);
    printf(">>> Passed Test-4\n");

    printf("########## Test-5: factorial() Function ##########\n");
    assert(factorial(12) == 479001600);
    printf(">>> Passed Test-5\n");

    printf(">>> All Tests Passed Successfully!\n");
}
