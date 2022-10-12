// call header file
#include "lab3binary.h"

unsigned int leftmostOnePos(int number)
{
    // I followed the hints from class

    // start by declaring position as integer with initial value 0
    int position = 0;

    // run a loop from 1 to 32 to check all 32 bits, since integer is 4 bytes, and 8 bits makes 1 byte
    for (int i = 1; i <= 32; i++)
    {
        // check if the current bit is one
        // bitwise '&' operator didn't work properly for me, but logical operator '&&' did
        if (number && 1)
        {
            // shift bit over and increment position
            number = number >> 1;
            position++;
        }
        else
        {
            // otherwise only shift bit over
            number = number >> 1;
        }
    }

    // returns current left-most bit position
    return position;
}

// use bitshift to convert from deciaml to binary
void convertAndOrder(int number, int binary[])
{
    // this was frustrating

    // i used a standard way of checking if a number is even by using a modulus operator
    if (number % 2 == 0)
    {
        // runs a loop in reverse to print binary values in *correct* order
        // don't know why but it works
        for (int i = 31; i >= 0; i--)
        {
            // prints 0 or 1 for the current bit value
            binary[i] = number % 2;

            // LSR
            number = number >> 1;

            // prints current binary value in array
            printf("%d ", binary[i]);
        }
    }

    else
    {
        // prints array in reverse order for non-even numbers
        for (int i = 0; i < 32; i++)
        {
            // prints 0 or 1 for the current bit value
            binary[i] = number % 2;

            // LSR
            number = number >> 1;

            // prints current binary value in array
            printf("%d ", binary[i]);
        }
    }
}