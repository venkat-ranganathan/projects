/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "header.h"
#define isCompatible(x, type) _Generic(x, type: true, default: false)

int main(void)
{
    // Compute the area and perimeter of a circle
    {
        #ifdef RADIUS
        #ifdef PI
        assert(isCompatible(RADIUS, int));
        assert(isCompatible(PI, double));
        double area, perimeter;
        area = PI * RADIUS * RADIUS;
        printf("Circle Area = %.2f inches\n", area);
        perimeter = 2 * PI * RADIUS;
        printf("Circle Perimeter = %.2f inches\n", perimeter);
        #else
        printf("Error: PI is not defined.\n");
        #endif
        #else
        printf("Error: RADIUS is not defined.\n");
        #endif
    }

    // Print favorite car brand
    {
        #ifdef CARBRAND
        assert(strlen(CARBRAND) > 0);
        printf("Your favorite car brand is %s\n", CARBRAND);
        #else
        printf("CARBRAND is not defined.\n");
        #endif
    }

    // Simple arithmetic operator
    {
        #ifdef ARITHMETIC
        float result = (float) 9 ARITHMETIC 3;
        printf("9 ARITHMETIC 3 = %.2f\n", result);
        #else
        printf("ARITHMETIC is not defined.\n");
        #endif
    }

    // Convert temperature from Fahrenheit to Celsius
    {
        #ifdef FAHRENHEIT
        assert(isCompatible(FAHRENHEIT, int));
        float celsius = (float) (FAHRENHEIT - 32) * 5 / 9;
        printf("Today's temperature in Celsius: %.2f\n", celsius);
        #else
        printf("FAHRENHEIT is not defined.\n");
        #endif
    }
}

