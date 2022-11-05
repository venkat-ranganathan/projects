// preprocessor directives
#include "lab5pointers.h"

// functions
int flipSign(int *x)
{
    // if "x" is pointing to a positive or negative value: switch the signs of the value and return '1'

    int temp = *x;

    // if "x" is pointing to a '0' value: return '0'
}

int compareAndSwap(int *x, int *y)
{
    // if "x" and "y" are both pointing to the same value: return '0'

    // if "x" is pointing to a value that is less than teh value "y" is pointing to: return '1'

    /* if "y" is pointing to a value that is less than the value "x" is pointing to: swap the values
    that are pointed to by the pointers "x" and "y", then return '-1' */
}

int searchArray(int array[], int size, int item)
{
    // if "item" is found in the "array": return the address of the "item" location in the "array" as an integer pointer

    // if "item" is not found in the "array": return "NULL"
}

int copyString(char str[], char str2[])
{
    // copy a given string "str1" (array of characters) to another "str2" (array of characters)
    // the function should return the size of the string copied into "str2" including the null termination character
}